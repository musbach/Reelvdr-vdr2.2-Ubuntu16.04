/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2012. Intel Corporation. All rights reserved.
    Copyright(c) 2009, 2010. Fluendo S.A. All rights reserved.

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation; either version 2.1 of the
    License.

    This library is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
    USA. The full GNU Lesser General Public License is included in this
    distribution in the file called LICENSE.LGPL.

    Contat Information for Fluendo:
        FLUENDO S.A.
        World Trade Center Ed Norte 4 pl.
        Moll de Barcelona
        08039 BARCELONA - SPAIN

    BSD LICENSE

    Copyright(c) 2012. Intel Corporation. All rights reserved.
    Copyright(c) 2009, 2010. Fluendo S.A. All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

      - Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      - Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in
        the documentation and/or other materials provided with the
        distribution.
      - Neither the name of FLUENDO S.A. nor the names of its
        contributors may be used to endorse or promote products derived
        from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "ismd_gst_dvb_src.h"

GST_DEBUG_CATEGORY_EXTERN (ismd_gst_dvb_stream_debug);
#define GST_CAT_DEFAULT ismd_gst_dvb_stream_debug

#define ADAPTER_GET_LOCK(stream)    (ISMD_GST_DVB_STREAM_CAST(stream)->adapter_lock)
#define ADAPTER_LOCK(stream)        (g_static_rec_mutex_lock(ADAPTER_GET_LOCK(stream)))
#define ADAPTER_LOCK_FULL(stream,t) (g_static_rec_mutex_lock_full(ADAPTER_GET_LOCK(stream), t))
#define ADAPTER_TRYLOCK(stream)     (g_static_rec_mutex_trylock(ADAPTER_GET_LOCK(stream)))
#define ADAPTER_UNLOCK(stream)      (g_static_rec_mutex_unlock(ADAPTER_GET_LOCK(stream)))

static GstPadClass *parent_class = NULL;

static void ismd_gst_dvb_stream_loop (ISmdGstDVBStream * stream);

ISmdGstDVBStream *
ismd_gst_dvb_stream_create (GstPadTemplate * template, const gchar * name)
{
  ismd_result_t result;
  ISmdGstDVBStream * stream;

  stream = g_object_new (ISMD_GST_TYPE_DVB_STREAM, "name", name,
      "direction", GST_PAD_SRC, "template", template, NULL);
  if (stream) {
    GstCaps *caps;
    caps = gst_caps_new_simple ("video/mpegts", "packetsize", G_TYPE_INT, 188,
        NULL);
    gst_pad_set_caps (GST_PAD (stream), caps);
    GST_DEBUG_OBJECT (stream, "create pad %s, caps %" GST_PTR_FORMAT, name,
        caps);
    gst_caps_unref (caps);

    /* Create the for monitoring the data output */
    if ((result = ismd_event_alloc (&stream->port_event)) != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (stream, "ismd_event_alloc failed(%d)", result);
    }

    /* Create an adapter and a lock to protect access to it */
    stream->queued_data = gst_adapter_new ();
    ADAPTER_GET_LOCK(stream) = g_new0 (GStaticRecMutex, 1);
    g_static_rec_mutex_init (ADAPTER_GET_LOCK(stream));

  } else {
    GST_WARNING_OBJECT (stream, "failed creating a stream object");
  }

  return stream;
}

gboolean
ismd_gst_dvb_stream_open (ISmdGstDVBStream * stream, ismd_dev_t dev_handle)
{
  ismd_result_t result;

  g_return_val_if_fail (stream != NULL, FALSE);

  if (dev_handle == ISMD_PORT_HANDLE_INVALID)
    return FALSE;

  if (stream->setup)
    return TRUE;

  /* Configure a filter on the device */
  result = ismd_demux_filter_open (dev_handle,
     ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, 32*1024, &stream->filter_handle,
     &stream->port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "ismd_demux_filter_open failed(%d)", result);
    return FALSE;
  }

  result = ismd_port_attach (stream->port, stream->port_event,
      ISMD_QUEUE_EVENT_ALWAYS, ISMD_QUEUE_WATERMARK_NONE);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "ismd_port_attach failed (%d) to output port %d",
        result, stream->port);
    return FALSE;
  }
  stream->setup = TRUE;

  GST_DEBUG_OBJECT (stream, "Successfully opened the filter and got port %d",
      stream->port);
  return TRUE;
}

gboolean
ismd_gst_dvb_stream_close (ISmdGstDVBStream * stream, ismd_dev_t dev_handle)
{
  ismd_result_t result;

  g_return_val_if_fail (stream != NULL, FALSE);

  /* Take the stream lock on the pushing task */
  GST_PAD_STREAM_LOCK (GST_PAD (stream));
  if (!stream->setup) {
    GST_PAD_STREAM_UNLOCK (GST_PAD (stream));
    return TRUE;
  }

  result = ismd_demux_filter_stop (dev_handle, stream->filter_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "ismd_demux_filter_stop failed(%d)", result);
  }
  GST_DEBUG_OBJECT (stream, "filter stopped");

  result = ismd_port_detach (stream->port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "ismd_port_detach failed(%d)", result);
  }

  result = ismd_demux_filter_close (dev_handle, stream->filter_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "ismd_demux_filter_close failed(%d)", result);
  }
  GST_DEBUG_OBJECT (stream, "filter closed");

  stream->setup = FALSE;
  GST_PAD_STREAM_UNLOCK (GST_PAD (stream));
  GST_DEBUG_OBJECT (stream, "stream closed");
  return TRUE;
}

gboolean
ismd_gst_dvb_stream_start (ISmdGstDVBStream * stream)
{
  gboolean ret;

  ret = gst_pad_start_task (GST_PAD(stream),
      (GstTaskFunction) ismd_gst_dvb_stream_loop, stream);
  if (ret) {
    GST_DEBUG_OBJECT (stream, "Started program # %d PMT PID %04x",
        stream->program, stream->pmt_pid);
  }
  return ret;
}

gboolean
ismd_gst_dvb_stream_stop (ISmdGstDVBStream * stream)
{
  gboolean ret;
  ismd_result_t result;

  if (stream->port_event != ISMD_EVENT_HANDLE_INVALID) {
    result = ismd_event_strobe (stream->port_event);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (stream, "ismd_event_strobe failed(%d)", result);
    }
  }

  ret = gst_pad_stop_task (GST_PAD(stream));

  if (ret && stream->configured) {
    GST_DEBUG_OBJECT (stream, "Send EOS");
    gst_pad_push_event (GST_PAD (stream), gst_event_new_eos ());
    GST_DEBUG_OBJECT (stream, "Stopped");
  }
  return ret;
}

gboolean
ismd_gst_dvb_stream_map_pid (ISmdGstDVBStream * stream,
    guint16 pid, ismd_demux_pid_type_t pid_type)
{
  gboolean ret = FALSE;
  ismd_result_t result;

  ISmdGstDVBSrc * dvbsrc =
      ISMD_GST_DVB_SRC (gst_pad_get_parent (GST_PAD(stream)));

  if (!stream->setup) {
    GST_DEBUG_OBJECT (stream, "Setup not done on this stream");
    goto beach;
  }
  GST_OBJECT_LOCK (dvbsrc);
  result = ismd_demux_filter_map_to_pid (dvbsrc->dev_handle,
      stream->filter_handle, pid, pid_type);
  GST_OBJECT_UNLOCK (dvbsrc);
  if (result != ISMD_SUCCESS) {
     GST_ERROR_OBJECT (stream, "ismd_demux_filter_map_to_pids failed(%d)",
        result);
     goto beach;
  }
  ret = TRUE;
beach:
  gst_object_unref (dvbsrc);
  return ret;
}

gboolean
ismd_gst_dvb_stream_unmap_pid (ISmdGstDVBStream * stream, guint16 pid)
{
  gboolean ret = FALSE;
  ismd_result_t result;

  ISmdGstDVBSrc * dvbsrc =
      ISMD_GST_DVB_SRC (gst_pad_get_parent (GST_PAD(stream)));

  if (!stream->setup) {
    GST_DEBUG_OBJECT (stream, "Setup not done on this stream");
    goto beach;
  }
  GST_OBJECT_LOCK (dvbsrc);
  result = ismd_demux_filter_unmap_from_pid (dvbsrc->dev_handle,
      stream->filter_handle, pid);
  GST_OBJECT_UNLOCK (dvbsrc);
  if (result != ISMD_SUCCESS) {
     GST_ERROR_OBJECT (stream, "ismd_demux_filter_unmap_from_pid failed(%d)",
        result);
     goto beach;
  }
  ret = TRUE;
beach:
  gst_object_unref (dvbsrc);
  return ret;

}

void
ismd_gst_dvb_stream_queue_data (ISmdGstDVBStream * stream, GstBuffer *buf)
{
  GST_LOG_OBJECT (stream, "queued buffer %p", buf);
  GST_MEMDUMP_OBJECT (stream, "Received ISMD buffer:",
      GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));

  ADAPTER_LOCK (stream);
  if (stream->queued_data) {
    gst_adapter_push (stream->queued_data, gst_buffer_ref (buf));
  }
  ADAPTER_UNLOCK (stream);
#if 0
  ismd_result_t result;
  result = ismd_event_strobe (stream->port_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_event_strobe failed(%d)", result);
  }
#endif
}


static gboolean
ismd_gst_dvb_stream_create_buffer (ISmdGstDVBStream * stream,
    GstBuffer ** buf)
{
  ismd_result_t result;
  ismd_buffer_handle_t buf_handle;
  ismd_buffer_descriptor_t buf_desc;
  ismd_newsegment_tag_t newsegment;

  *buf = NULL;

  result = ismd_port_read (stream->port, &buf_handle);
  if (result != ISMD_SUCCESS) {
    GST_LOG_OBJECT (stream, "ismd_port_read failed(%d)", result);
    goto no_data;
  }

  /* If some data is available read the description of it */
  memset (&buf_desc, 0, sizeof (buf_desc));
  result = ismd_buffer_read_desc (buf_handle, &buf_desc);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "ismd_buffer_read_desc failed(%d)", result);
    goto drop;
  }

  /* Check for newsegment */
  result = ismd_tag_get_newsegment (buf_handle, &newsegment);
  if (result == ISMD_SUCCESS) {
    GST_INFO_OBJECT (stream,
        "SMD NEWSEGMENT received start %" GST_TIME_FORMAT
        " stop %" GST_TIME_FORMAT " linear_start %" GST_TIME_FORMAT
        " requested_rate %f applied_rate %f",
        GST_TIME_ARGS (SMD_TO_GST_TIME (newsegment.start)),
        GST_TIME_ARGS (SMD_TO_GST_TIME (newsegment.stop)),
        GST_TIME_ARGS (SMD_TO_GST_TIME (newsegment.linear_start)),
        SMD_TO_GST_RATE (newsegment.requested_rate),
        SMD_TO_GST_RATE (newsegment.applied_rate));
  }

  if (buf_desc.phys.level) {
    /* When isn't video just generate an standard GstBuffer and copy
     * the data on it */
    guint8 *dataptr;
    *buf = gst_buffer_new_and_alloc (buf_desc.phys.level);

    /* Map and copy the data into a gstreamer buffer */
    dataptr = ISMD_BUFFER_MAP_BY_TYPE(buf_desc.buffer_type, buf_desc.phys.base,
        buf_desc.phys.level);

    memcpy (GST_BUFFER_DATA (*buf), dataptr, buf_desc.phys.level);
    OS_UNMAP_IO_FROM_MEM (dataptr, buf_desc.phys.level);

    /* Since data copied, free ismd_buffer */
    result = ismd_buffer_dereference (buf_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (stream, "freeing ismd_buffer %d failed", buf_handle);
    }
  }
  else {
    goto drop;
  }

  return TRUE;

no_data:
  GST_LOG_OBJECT (stream, "probably no data available");
  return FALSE;

drop:
  GST_LOG_OBJECT (stream, "dropping ismd buffer %d", buf_handle);
  result = ismd_buffer_dereference (buf_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (stream, "freeing ismd_buffer failed(%d)", result);
  }
  return FALSE;
}

static inline gint
search_ts_boundary (GstBuffer * buffer) {
  guint8 * data = GST_BUFFER_DATA (buffer);
  gint size = GST_BUFFER_SIZE (buffer);
  gint offset = size - 1;

  while (offset) {
    if (G_UNLIKELY (data [offset] == 0x47)) {
      if (G_LIKELY((offset - 564) >=0 &&
          data [offset - 188] == 0x47 && data [offset - 376] == 0x47 &&
          data [offset - 564] == 0x47)) {
        goto found;
      }
    }
    offset--;
  }
  return -1;
found:
  return offset;
}

gboolean
ismd_gst_dvb_stream_configure_es_pids (ISmdGstDVBStream * stream,
    pmt_data * pmt)
{
  GArray *oldpids = stream->ES_pids;
  GArray *newpids;
  guint16 oldpid, newpid;
  gint i, j;

  ISmdGstDVBSrc * dvbsrc =
      ISMD_GST_DVB_SRC (gst_pad_get_parent (GST_PAD(stream)));

  /* Recover the list of the ES pids from the pmt */
  newpids = g_array_new(FALSE, FALSE, sizeof (guint16));
  for (i = 0; i < pmt->entries->len; i++) {
    pmt_stream_data *ES = &g_array_index (pmt->entries, pmt_stream_data, i);
    PidCategory cat = ismd_gst_get_category_from_stream_type (ES->type);
    if (dvbsrc->allowed_pid_categories & cat) {
      GST_DEBUG_OBJECT (stream, "New ES stream pid 0x%04x with type %d (%s) ",
          ES->pid, ES->type, ismd_gst_stream_type_name (ES->type));
      g_array_append_val (newpids, ES->pid);
    }
	}
  
  /* Remove Elementary Stream PIDs */
  if (oldpids) {
    for (i = 0; i < oldpids->len; i++) {
      oldpid = g_array_index (oldpids, guint16, i);
      gboolean found = FALSE;
      for (j = 0; j < newpids->len; j++) {
        newpid = g_array_index (newpids, guint16, j);
        if (newpid == oldpid) {
          found = TRUE;
          break;
        }    
      }
      if (!found) {
        GST_DEBUG_OBJECT (stream, "Removed ES stream with pid 0x%04x", oldpid);
        ismd_gst_dvb_stream_unmap_pid (stream, oldpid);
      }
    }
  }

  /* Add Elementary Stream PIDs */
  for (i = 0; i < newpids->len; i++) {
    newpid = g_array_index (newpids, guint16, i);
    /* HACK:
     * These are in fact Elementary Streams (ES), but the ISMD filters can
     * only handle 8 of them and we have found programs with more.
     * Since we are asking for whole TS packets with no further processing,
     * it doesn't seem to matter what we specify as the pid_type, and
     * therefore, we say PSI instead of ES, because there can be filters
     * can handle 32 PSI pids.
     */      
    if (ismd_gst_dvb_stream_map_pid (stream, newpid, ISMD_DEMUX_PID_TYPE_PSI)) {
      GST_DEBUG_OBJECT (stream, "Added ES stream with pid 0x%04x", newpid);
    }
    else {
      goto failed;
    }
  }
  stream->ES_pids = newpids;
  gst_object_unref (dvbsrc);  
  return TRUE;

failed:
  GST_ERROR_OBJECT (stream, "Failed configuring ES pids in filter");
  g_array_free (newpids, TRUE);
  gst_object_unref (dvbsrc);  
  return FALSE;
}

static void
ismd_gst_dvb_stream_loop (ISmdGstDVBStream * stream)
{
  GstFlowReturn ret = GST_FLOW_OK;
  GstBuffer *buf = NULL;
  gboolean flushing = FALSE, stopped = FALSE;
  GstCaps *caps = gst_pad_get_negotiated_caps (GST_PAD (stream));
  gint ts_boundary = -1;
  guint avail = 0;

  ISmdGstDVBSrc * dvbsrc =
      ISMD_GST_DVB_SRC (gst_pad_get_parent (GST_PAD(stream)));

  GST_OBJECT_LOCK (dvbsrc);
  flushing = dvbsrc->flushing;
  GST_OBJECT_UNLOCK (dvbsrc);

  if (!stream->configured) {
    gboolean status;
    pmt_data pmt;
    ret = GST_FLOW_UNEXPECTED;

    GST_DEBUG_OBJECT (stream, "Collect PMT info (program %d)", stream->program);
    /* Add the PMT for the selected program to the PSI filter */
    if (!psi_filter_add_pmt_for_service (dvbsrc->psif, stream->program)) {
      GST_WARNING_OBJECT (stream,
          "Program number %d not found in current PAT", stream->program);
      goto beach;
    }
    /* Wait for the PMT being found */
    status = psi_filter_wait_for_pmt (dvbsrc->psif, stream->program,
        dvbsrc->psi_timeout);
    if (!status) {
       GST_ERROR_OBJECT (stream, "psi_filter_wait_for_pmt failed");
       goto beach;
    }
    status = psi_filter_get_pmt (dvbsrc->psif, stream->program, &pmt);
    if (!status) {
       GST_ERROR_OBJECT (stream, "psi_filter_get_pmt failed");
       goto beach;
    }
    GST_DEBUG_OBJECT (stream, "Added PCR with pid 0x%04x", pmt.pcr_pid);
    if (!ismd_gst_dvb_stream_map_pid (stream, pmt.pcr_pid,
          ISMD_DEMUX_PID_TYPE_PSI)) {
      goto beach;
    }

    /* Elementary Stream PIDs */
    if (!ismd_gst_dvb_stream_configure_es_pids (stream, &pmt)) {
      goto beach;
    }

    stream->configured = TRUE;
    ret = GST_FLOW_OK;
  }

  if (G_UNLIKELY (!GST_IS_CAPS (caps))) {
    GST_ERROR_OBJECT (stream, "src pad has not negotiated caps");
    ret = GST_FLOW_NOT_NEGOTIATED;
    goto beach;
  }

  if (G_UNLIKELY (stream->need_new_segment)) {
    /* Push a new segment event */
    gst_pad_push_event (GST_PAD (stream),
        gst_event_new_new_segment (FALSE, 1.0, GST_FORMAT_BYTES, 0, -1, 0));
    stream->need_new_segment = FALSE;
  }

  /* Now take data from the stream filter */
  if (!ismd_gst_dvb_stream_create_buffer (stream, &buf)) {
    ret = GST_FLOW_OK;
    goto beach;
  }

  ADAPTER_LOCK (stream);

  /* Now we can concatenate the data buffer at TS packet boundaries */
  if (buf) {
    /* First add last previous fragment into the current buffer */
    GST_LOG_OBJECT (stream, "got buffer of %d bytes", GST_BUFFER_SIZE (buf));

    if (stream->prev_ts_fragment) {
      GST_LOG_OBJECT (stream, "prefix current buffer with previous fragment "
          "of %d bytes", GST_BUFFER_SIZE (stream->prev_ts_fragment));
      buf = gst_buffer_join (stream->prev_ts_fragment, buf);
      stream->prev_ts_fragment = NULL;
    }

    /* We need at least 5 x 188 = 940 bytes to scan */
    if (G_LIKELY (GST_BUFFER_SIZE (buf) > 940)) {
      ts_boundary = search_ts_boundary (buf);
      GST_LOG_OBJECT (stream, "Found sync point at %d of %d", ts_boundary,
          GST_BUFFER_SIZE (buf));
      if (ts_boundary != -1) {
        GstBuffer * sub;
        stream->prev_ts_fragment =
            gst_buffer_create_sub (buf, ts_boundary,
                GST_BUFFER_SIZE (buf) - ts_boundary);
        GST_LOG_OBJECT (stream, "saved %d bytes of PES data for later %p",
            GST_BUFFER_SIZE (stream->prev_ts_fragment), stream->prev_ts_fragment);

        GST_MEMDUMP_OBJECT (stream, "TS packet fragment:",
            GST_BUFFER_DATA (stream->prev_ts_fragment),
            GST_BUFFER_SIZE (stream->prev_ts_fragment));

        sub = gst_buffer_create_sub (buf, 0, ts_boundary);
        gst_buffer_unref (buf);
        buf = NULL;
        GST_LOG_OBJECT (stream, "Concatenate %d bytes of PES data",
            GST_BUFFER_SIZE (sub));
        gst_adapter_push (stream->queued_data, sub);
      }
      else {
        GST_WARNING_OBJECT (stream, "Sync point not found, produced bitstream "
            "could be corrupted");
        stream->prev_ts_fragment = buf;
        buf = NULL;
      }
    } else {
      GST_WARNING_OBJECT (stream, "Buffer of %d bytes is too small, keep it for"
          " later processing", GST_BUFFER_SIZE (buf));
      stream->prev_ts_fragment = buf;
      buf = NULL;
    }
  }

  /* Now push all the queued data */
  if ((avail = gst_adapter_available (stream->queued_data))) {
    buf = gst_adapter_take_buffer (stream->queued_data, avail);
  }
  ADAPTER_UNLOCK (stream);

  if (G_UNLIKELY (flushing)) {
    GST_DEBUG_OBJECT (stream, "in flushing state");
    ret = GST_FLOW_WRONG_STATE;
    if (buf) {
      gst_buffer_unref (buf);
      buf = NULL;
    }
  }

  if (G_LIKELY (buf)) {
    gst_buffer_set_caps (buf, caps);
    GST_LOG_OBJECT (stream, "pushing buffer %p of %d bytes",
        buf, GST_BUFFER_SIZE (buf));
    ret = gst_pad_push (GST_PAD (stream), buf);
  }

beach:
  if (caps)
    gst_caps_unref (caps);

  /* If we are a source handle the flow return value here*/
  if (GST_FLOW_IS_FATAL (ret) || ret == GST_FLOW_NOT_LINKED || flushing) {
    const gchar *reason = gst_flow_get_name (ret);

    GST_LOG_OBJECT (stream, "pausing task, reason %s", reason);
    gst_pad_pause_task (GST_PAD(stream));

    ismd_gst_dvb_stream_close (stream, dvbsrc->dev_handle);

    GST_DEBUG_OBJECT (stream, "Send EOS");
    gst_pad_push_event (GST_PAD (stream), gst_event_new_eos ());

    stopped = TRUE; /* We don't want to stay waiting for more data */
  }

  if (!stopped && !buf) {
    GST_LOG_OBJECT (stream, "wait for more data");
    ismd_event_wait (stream->port_event, ISMD_TIMEOUT_NONE);
    ismd_event_acknowledge (stream->port_event);
    GST_LOG_OBJECT (stream, "SMD port just got some data");
  }

  gst_object_unref (dvbsrc);
}

static void
ismd_gst_dvb_stream_finalize (GObject * object)
{
  ISmdGstDVBStream *stream = ISMD_GST_DVB_STREAM (object);

  GST_DEBUG_OBJECT (stream, "Finalize");

  if (stream->ES_pids) {
    g_array_free (stream->ES_pids, TRUE);
    stream->ES_pids = NULL;
  }

  if (stream->port_event != ISMD_EVENT_HANDLE_INVALID) {
    ismd_event_free (stream->port_event);
    stream->port_event = ISMD_EVENT_HANDLE_INVALID;
  }

  if (stream->prev_ts_fragment) {
    gst_buffer_unref (stream->prev_ts_fragment);
  }

  ADAPTER_LOCK (stream);
  if (stream->queued_data) {
    gst_adapter_clear (stream->queued_data);
    g_object_unref (stream->queued_data);
    stream->queued_data = NULL;

  }
  ADAPTER_UNLOCK (stream);

  if (ADAPTER_GET_LOCK(stream)) {
    g_static_rec_mutex_free (ADAPTER_GET_LOCK(stream));
    g_free (ADAPTER_GET_LOCK(stream));
    ADAPTER_GET_LOCK(stream) = NULL;
  }

  /* Chaining up */
  if (G_OBJECT_CLASS (parent_class)->finalize != NULL) {
    G_OBJECT_CLASS (parent_class)->finalize (object);
  }
}

static void
ismd_gst_dvb_stream_class_init (ISmdGstDVBStream * klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  parent_class = g_type_class_ref (GST_TYPE_PAD);

  gobject_class->finalize = ismd_gst_dvb_stream_finalize;
}

static gboolean
ismd_gst_dvb_stream_event (GstPad * pad, GstEvent * event) {
  ISmdGstDVBStream *stream = ISMD_GST_DVB_STREAM_CAST (pad);
  gboolean ret = FALSE;

  GST_DEBUG_OBJECT (stream, "handling event type %s",
      GST_EVENT_TYPE_NAME (event));

  switch (GST_EVENT_TYPE (event)) {
    case GST_EVENT_LATENCY:
    {
      gst_event_unref (event);
      ret = TRUE;
      break;
    }
    default:
      ret = gst_pad_event_default (pad, event);
      break;
  }

  return ret;
}

static const GstQueryType *
ismd_gst_dvb_stream_get_query_types (GstPad * pad)
{
  static const GstQueryType query_types[] = {
    GST_QUERY_LATENCY,
    0
  };

  return query_types;
}

static gboolean
ismd_gst_dvb_stream_query (GstPad * pad, GstQuery * query)
{
  gboolean res;
  ISmdGstDVBStream *stream = ISMD_GST_DVB_STREAM_CAST (pad);

  switch (GST_QUERY_TYPE (query)) {
    case GST_QUERY_LATENCY:
    {
      GstClockTime min = 0, max = -1;
      gboolean live = FALSE;

      GST_LOG_OBJECT (stream, "report latency: live %d, min %" GST_TIME_FORMAT
          ", max %" GST_TIME_FORMAT, live, GST_TIME_ARGS (min),
          GST_TIME_ARGS (max));

      gst_query_set_latency (query, live, min, max);
      res = TRUE;
      break;
    }

    default:
      res = FALSE;
      break;
  }
  GST_DEBUG_OBJECT (stream, "query %s returns %d", GST_QUERY_TYPE_NAME (query),
      res);

  return res;
}

static void
ismd_gst_dvb_stream_init (ISmdGstDVBStream * stream,
    ISmdGstDVBStreamClass * g_class)
{
  gst_pad_set_event_function (GST_PAD (stream),
      GST_DEBUG_FUNCPTR (ismd_gst_dvb_stream_event));
  gst_pad_set_query_type_function (GST_PAD (stream),
      GST_DEBUG_FUNCPTR (ismd_gst_dvb_stream_get_query_types));
  gst_pad_set_query_function (GST_PAD (stream),
      GST_DEBUG_FUNCPTR (ismd_gst_dvb_stream_query));

  gst_pad_use_fixed_caps (GST_PAD (stream));

  stream->filter_handle = ISMD_PORT_HANDLE_INVALID;
  stream->port = ISMD_PORT_HANDLE_INVALID;
  stream->setup = FALSE;
  stream->configured = FALSE;
  stream->need_new_segment = TRUE;
  stream->port_event = ISMD_EVENT_HANDLE_INVALID;
  ADAPTER_GET_LOCK(stream) = NULL;
  stream->queued_data = NULL;
  stream->pmt_pid = 0xffff;
  stream->ES_pids = NULL;
  stream->prev_ts_fragment = NULL;
  stream->program = -1;
}

GType
ismd_gst_dvb_stream_get_type (void)
{
  static GType stream_type = 0;

  if (!stream_type) {
    static const GTypeInfo stream_info = {
      sizeof (ISmdGstDVBStreamClass),
      NULL,
      NULL,
      (GClassInitFunc) ismd_gst_dvb_stream_class_init,
      NULL,
      NULL,
      sizeof (ISmdGstDVBStream),
      0,
      (GInstanceInitFunc) ismd_gst_dvb_stream_init,
    };

    stream_type = g_type_register_static (GST_TYPE_PAD, "ISmdGstDVBStream",
        &stream_info, 0);
  }
  return stream_type;
}
