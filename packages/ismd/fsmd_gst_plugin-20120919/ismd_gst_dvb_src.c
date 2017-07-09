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

    Contact Information for Intel:
        Intel Corporation
        2200 Mission College Blvd.
        Santa Clara, CA  97052

    Contat Information for Fluendo:
        FLUENDO S.A.
        World Trade Center Ed Norte 4 pl.
        Moll de Barcelona
        08039 BARCELONA - SPAIN

    BSD LICENSE

    Copyright (c) 2012. Intel Corporation. All rights reserved.
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
      - Neither the name of Intel Corporation nor the names of its
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

#include <gst/gstmarshal.h>
#include "ismd_gst_dvb_src.h"
#include "psi_helper.h"

GST_DEBUG_CATEGORY_STATIC (ismd_gst_dvb_src_debug);
#define GST_CAT_DEFAULT ismd_gst_dvb_src_debug

enum
{
  PROP_0,
  PROP_TUNER,
  PROP_PROGRAM,
  PROP_PSI_TIMEOUT,
  PROP_EXTRA_PIDS,
  PROP_PID_FILTER,
  PROP_CHECK_CRC,
  PROP_CLOCK_RECOVERY,
  PROP_DISCOVERY
};

#define DEFAULT_TUNER             0
#define DEFAULT_PROGRAM           ((guint)-1)
#define DEFAULT_PSI_TIMEOUT       5000000 /* microseconds */
#define DEFAULT_ES_PIDS           ""
#define DEFAULT_PID_FILTER        PID_CAT_ALL
#define DEFAULT_CHECK_CRC         TRUE
#define DEFAULT_CLOCK_RECOVERY    TRUE
#define DEFAULT_DISCOVERY         FALSE

#define BUFFERING_EVENT_TIMEOUT   1000
#define MINIMUM_BUFFERING         40000

#define TEST_RESOURCES 0


static GstStaticPadTemplate src_factory =
GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("video/mpegts, packetsize = (int) 188"));

static GstStaticPadTemplate prog_factory =
GST_STATIC_PAD_TEMPLATE ("program_%d",
    GST_PAD_SRC,
    GST_PAD_REQUEST,
    GST_STATIC_CAPS ("video/mpegts, packetsize = (int) 188"));

static guint
ismd_gst_dvb_src_uri_get_type (void)
{
  return GST_URI_SRC;
}

static gchar **
ismd_gst_dvb_src_uri_get_protocols (void)
{
  static gchar *protocols[] = { "ismdtuner", NULL };

  return protocols;
}

static const gchar *
ismd_gst_dvb_src_uri_get_uri (GstURIHandler * handler)
{
  return "ismdtuner://";
}

static gboolean
ismd_gst_dvb_src_uri_set_uri (GstURIHandler * handler, const gchar * uri)
{
  gboolean ret;
  gchar *protocol;
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (handler);

  protocol = gst_uri_get_protocol (uri);

  if (strcmp (protocol, "ismdtuner") != 0) {
    ret = FALSE;
  } else {
    gchar *location = gst_uri_get_location (uri);

    if (location != NULL) {
      sscanf (location, "%d,%d", &dvbsrc->tuner, &dvbsrc->program);
      g_free (location);
      ret = TRUE;
    } else
      ret = FALSE;
  }

  g_free (protocol);

  return ret;
}

static void
ismd_gst_dvb_src_uri_handler_init (gpointer g_iface, gpointer iface_data)
{
  GstURIHandlerInterface *iface = (GstURIHandlerInterface *) g_iface;

  iface->get_type = ismd_gst_dvb_src_uri_get_type;
  iface->get_protocols = ismd_gst_dvb_src_uri_get_protocols;
  iface->get_uri = ismd_gst_dvb_src_uri_get_uri;
  iface->set_uri = ismd_gst_dvb_src_uri_set_uri;
}

static gboolean
ismd_gst_dvb_src_enable_clock_recovery (ISmdGstDVBSrc * dvbsrc)
{
  ismd_result_t result;
  pmt_data pmt;
  gboolean running;

  GST_OBJECT_LOCK (dvbsrc);
  running = dvbsrc->running;
  GST_OBJECT_UNLOCK (dvbsrc);

  if (!dvbsrc->clock_recovery) {
    return TRUE;
  }

  /* We can't confgure the clock recovery when not running and clock
   * distributed */
  if (!running) {
    GST_DEBUG_OBJECT (dvbsrc, "clock recovery can't be configured yet");
    return TRUE;
  }

  if (!dvbsrc->clock_is_ismd) {
    GST_DEBUG_OBJECT (dvbsrc, "clock recovery can't be configured with a "
        "non ISMD clock");
    return TRUE;
  }

  if (!psi_filter_get_pmt (dvbsrc->psif, dvbsrc->program, &pmt)) {
    GST_ERROR_OBJECT (dvbsrc, "psi_filter_get_pmt failed");
    goto failure;
  }

  if (pmt.pcr_pid == dvbsrc->current_pcr_pid) {
    GST_DEBUG_OBJECT (dvbsrc, "clock recovery is already configured for "
        "pid 0x%04x", pmt.pcr_pid);
    return TRUE;
  }

  result = ismd_demux_ts_set_pcr_pid (dvbsrc->dev_handle, pmt.pcr_pid);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_ts_set_pcr_pid failed(%d)",
        result);
    goto failure;
  }

  result = ismd_demux_tsin_enable_clock_recovery (dvbsrc->dev_handle,
      pmt.pcr_pid);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_tsin_enable_clock_recovery "
        "failed(%d)", result);
    goto failure;
  }

#if 0
  /* The following doesn't seem to be needed */
  result = ismd_demux_stream_use_arrival_time (dvbsrc->dev_handle, TRUE);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_stream_use_arrival_time failed"
        " (%d)", result);
    goto failure;
  }
#endif

  dvbsrc->current_pcr_pid = pmt.pcr_pid;
  GST_INFO_OBJECT (dvbsrc, "Clock recovery enabled for PCR pid 0x%04x",
      pmt.pcr_pid);
  return TRUE;

failure:
  return FALSE;
}

static gboolean
ismd_gst_dvb_src_disable_clock_recovery (ISmdGstDVBSrc * dvbsrc)
{
  ismd_result_t result;
  gboolean running;

  GST_DEBUG_OBJECT (dvbsrc, "Disable clock recovery");

  GST_OBJECT_LOCK (dvbsrc);
  running = dvbsrc->running;
  GST_OBJECT_UNLOCK (dvbsrc);

  if (!running)
    return TRUE;

  result = ismd_demux_tsin_disable_clock_recovery (dvbsrc->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_tsin_enable_clock_recovery "
        "failed(%d)", result);
    goto failure;
  }
  dvbsrc->current_pcr_pid = -1;

  return TRUE;
failure:
  return FALSE;
}

static ISmdGstDVBStream *
ismd_gst_dvb_src_add_stream (ISmdGstDVBSrc * dvbsrc, gboolean main,
    gint program, guint16 pmt_pid)
{
  ISmdGstDVBStream *stream;
  GstPadTemplate *template;
  gchar *pad_name;


  if (main) {
    template = gst_static_pad_template_get (&src_factory);
    pad_name = g_strdup_printf ("src");
  }
  else {
    template = gst_static_pad_template_get (&prog_factory);
    pad_name = g_strdup_printf ("program_%d", program);
  }
  stream = ismd_gst_dvb_stream_create (template, pad_name);
  gst_object_unref (template);
  g_free (pad_name);

  stream->program = program;
  stream->pmt_pid = pmt_pid;

  g_hash_table_insert (dvbsrc->streams,
      GINT_TO_POINTER (program), gst_object_ref(stream));

  gst_pad_set_active (GST_PAD (stream), TRUE);
  gst_element_add_pad (GST_ELEMENT (dvbsrc), GST_PAD (stream));

  return stream;
}

static ISmdGstDVBStream *
ismd_gst_dvb_src_get_stream (ISmdGstDVBSrc * dvbsrc, gint program)
{
  ISmdGstDVBStream *stream;

  stream = (ISmdGstDVBStream *) g_hash_table_lookup (dvbsrc->streams,
      GINT_TO_POINTER ((gint) program));

  return stream;
}

static void
ismd_gst_dvb_src_remove_stream (ISmdGstDVBSrc * dvbsrc, gint program)
{
  g_hash_table_remove (dvbsrc->streams, GINT_TO_POINTER (program));
}

static void
foreach_stream_start (gpointer key, gpointer value, gpointer data)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (data);
  ISmdGstDVBStream *stream = ISMD_GST_DVB_STREAM_CAST (value);

  GST_DEBUG_OBJECT (dvbsrc, "going to start %" GST_PTR_FORMAT, stream);
  if (!stream->setup) {
    ismd_gst_dvb_stream_open (stream, dvbsrc->dev_handle);
  }
  ismd_gst_dvb_stream_start (stream);
}

static void
foreach_stream_stop (gpointer key, gpointer value, gpointer data)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (data);
  ISmdGstDVBStream *stream = ISMD_GST_DVB_STREAM_CAST (value);

  GST_DEBUG_OBJECT (dvbsrc, "going to stop %" GST_PTR_FORMAT, stream);
  ismd_gst_dvb_stream_stop (stream);
  ismd_gst_dvb_stream_close (stream, dvbsrc->dev_handle);
}

static void
_do_init (GType type)
{
  static const GInterfaceInfo urihandler_info = {
    ismd_gst_dvb_src_uri_handler_init,
    NULL,
    NULL,
  };

  GST_DEBUG_CATEGORY_INIT (ismd_gst_dvb_src_debug, "ISMD_DVB_SRC",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstdvbsrc element");

  g_type_add_interface_static (type, GST_TYPE_URI_HANDLER, &urihandler_info);
}

/* Call Boilerplate to declare the base_init, class_init and init functions
 * and to define the get_type function */
GST_BOILERPLATE_FULL (ISmdGstDVBSrc, ismd_gst_dvb_src, GstElement,
    GST_TYPE_ELEMENT, _do_init);

static void
ismd_gst_dvb_src_dispose (GObject * object)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (object);

  GST_DEBUG_OBJECT (dvbsrc, "Dispose");

  G_OBJECT_CLASS (parent_class)->dispose (object);
}

static void
ismd_gst_dvb_src_finalize (GObject * object)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (object);

  GST_DEBUG_OBJECT (dvbsrc, "Finalizing");

  if (dvbsrc->extra_pids != NULL)
    g_free (dvbsrc->extra_pids);

  g_hash_table_destroy (dvbsrc->streams);

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
ismd_gst_dvb_src_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (object);
  gchar **pids;
  guint num_pids;
  gint i;

  switch (prop_id) {
    case PROP_TUNER:
      dvbsrc->tuner = g_value_get_uint (value);
      GST_DEBUG_OBJECT (dvbsrc, "setting tuner number %u", dvbsrc->tuner);
      break;
    case PROP_PROGRAM:
      dvbsrc->program = g_value_get_uint (value);
      GST_DEBUG_OBJECT (dvbsrc, "setting program number %u", dvbsrc->program);
      break;
    case PROP_PSI_TIMEOUT:
      dvbsrc->psi_timeout = g_value_get_uint64 (value);
      GST_DEBUG_OBJECT (dvbsrc, "setting PSI timeout value to %llu",
          dvbsrc->psi_timeout);
      break;
    case PROP_EXTRA_PIDS:
      GST_DEBUG_OBJECT (dvbsrc, "setting extra-pids to %s",
          g_value_get_string (value));
      pids = g_strsplit (g_value_get_string (value), ":", -1);
      num_pids = g_strv_length (pids);

      /* If there were already some extra-pids being filtered, unmap them */
      for (i = 0; i < dvbsrc->nb_extra_pids; i++) {
        GST_LOG_OBJECT (dvbsrc, "  Removing PID 0x%04x",
            dvbsrc->extra_pids[i]);
        ismd_gst_dvb_stream_unmap_pid (dvbsrc->main_stream,
            dvbsrc->extra_pids[i]);
      }

      if (num_pids > 0) {
        if (dvbsrc->extra_pids != NULL) g_free (dvbsrc->extra_pids);
        dvbsrc->extra_pids = g_new0 (guint16, num_pids);
        dvbsrc->nb_extra_pids = num_pids;
        for (i = 0; i < num_pids; i++) {
          dvbsrc->extra_pids[i] = strtol (pids[i], NULL, 0);
          GST_LOG_OBJECT (dvbsrc, "  Adding PID 0x%04x",
              dvbsrc->extra_pids[i]);
          ismd_gst_dvb_stream_map_pid (dvbsrc->main_stream,
              dvbsrc->extra_pids[i], ISMD_DEMUX_PID_TYPE_PES);
        }
      }
      g_strfreev (pids);
      break;
    case PROP_PID_FILTER:
      dvbsrc->allowed_pid_categories = g_value_get_flags (value);
      GST_DEBUG_OBJECT (dvbsrc, "setting allowed PID categories to %x",
          dvbsrc->allowed_pid_categories);
      break;
    case PROP_CHECK_CRC:
      dvbsrc->check_crc = g_value_get_boolean (value);
      if (dvbsrc->psif != NULL) {
        dvbsrc->psif->check_crc = dvbsrc->check_crc;
      }
      GST_DEBUG_OBJECT (dvbsrc, "setting check-crc flag to %d",
          dvbsrc->check_crc);
      break;
    case PROP_CLOCK_RECOVERY:
      {
        dvbsrc->clock_recovery = g_value_get_boolean (value);;
        if (dvbsrc->clock_recovery) {
          ismd_gst_dvb_src_enable_clock_recovery (dvbsrc);
        } else {
          ismd_gst_dvb_src_disable_clock_recovery (dvbsrc);
        }
        GST_DEBUG_OBJECT (dvbsrc, "setting clock recovery flag to %d",
            dvbsrc->clock_recovery);
        break;
      }
    case PROP_DISCOVERY:
      {
        dvbsrc->discovery = g_value_get_boolean (value);
        break;
      }
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_dvb_src_get_property (GObject * object, guint prop_id, GValue * value,
    GParamSpec * pspec)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (object);
  int i;

  switch (prop_id) {
    case PROP_TUNER:
      g_value_set_uint (value, dvbsrc->tuner);
      break;
    case PROP_PROGRAM:
      g_value_set_uint (value, dvbsrc->program);
      break;
    case PROP_PSI_TIMEOUT:
      g_value_set_uint64 (value, dvbsrc->psi_timeout);
      break;
    case PROP_EXTRA_PIDS:
      if (dvbsrc->nb_extra_pids == 0) {
        g_value_set_static_string (value, "");
      } else {
        gchar **ts_pids;

        ts_pids = g_new0 (gchar *, dvbsrc->nb_extra_pids + 1);
        for (i = 0; i < dvbsrc->nb_extra_pids; i++) {
          ts_pids[i] = g_strdup_printf ("%d", dvbsrc->extra_pids[i]);
        }

        g_value_set_string (value, g_strjoinv (":", ts_pids));
        g_strfreev (ts_pids);
      }
      break;
    case PROP_PID_FILTER:
      g_value_set_flags (value, dvbsrc->allowed_pid_categories);
      break;
    case PROP_CHECK_CRC:
      g_value_set_boolean (value, dvbsrc->check_crc);
      break;
    case PROP_CLOCK_RECOVERY:
      g_value_set_boolean (value, dvbsrc->clock_recovery);
      break;
    case PROP_DISCOVERY:
      g_value_set_boolean (value, dvbsrc->discovery);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static inline gboolean
ismd_tune (ISmdGstDVBSrc * dvbsrc)
{

  if (dvbsrc->tuner != -1) {
    GST_DEBUG_OBJECT (dvbsrc, "Using pretuned tuner number %u", dvbsrc->tuner);
    goto beach;
  }
#if 0
  GST_DEBUG_OBJECT (dvbsrc, "get_free_tuner");
  dvbsrc->tuner = get_free_tuner();
  if (dvbsrc->tuner == -1) {
    GST_ERROR_OBJECT (dvbsrc, "Could not get free tuner");
    return FALSE;
  }

  GST_DEBUG_OBJECT (dvbsrc, "ce9530_do_tune");
  if(ce9530_do_tune(dvbsrc->tuner, &dvbsrc->tune_info) != 0) {
    GST_ERROR_OBJECT (dvbsrc, "Could not tune");
  }
#endif

beach:
  return TRUE;
}

#if TEST_RESOURCES
#define MAX_TEST_FILTERS 100
static void
ismd_check_resources (ismd_dev_t dev_handle) {
  ismd_demux_filter_handle_t filters[MAX_TEST_FILTERS];
  ismd_port_handle_t dummy_port;
  int m, i;

  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "Checking max filters...");
  for (m=0; m<MAX_TEST_FILTERS &&
      ismd_demux_filter_open (dev_handle, ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, 32*1024, &filters[m], &dummy_port)==ISMD_SUCCESS; m++) {};
  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "   ... Max filters is %d", m);
  for (i=0; i<m; i++) ismd_demux_filter_close (dev_handle, filters[i]);

  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "Checking max different PSI pids per filter...");
  ismd_demux_filter_open (dev_handle, ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, 32*1024, &filters[0], &dummy_port);
  for (m=0; ismd_demux_filter_map_to_pid (dev_handle, filters[0], m, ISMD_DEMUX_PID_TYPE_PSI)==ISMD_SUCCESS; m++) {};
  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "   ... Max different PSI pids per filter is %d", m);
  ismd_demux_filter_close (dev_handle, filters[0]);

  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "Checking max different PES pids per filter...");
  ismd_demux_filter_open (dev_handle, ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, 32*1024, &filters[0], &dummy_port);
  for (m=0; ismd_demux_filter_map_to_pid (dev_handle, filters[0], m, ISMD_DEMUX_PID_TYPE_PES)==ISMD_SUCCESS; m++) {};
  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "   ... Max different PES pids per filter is %d", m);
  ismd_demux_filter_close (dev_handle, filters[0]);

  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "Checking max filters per PSI pid...");
  for (m=0; m<MAX_TEST_FILTERS &&
      ismd_demux_filter_open (dev_handle, ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, 32*1024, &filters[m], &dummy_port)==ISMD_SUCCESS &&
      ismd_demux_filter_map_to_pid (dev_handle, filters[m], 0x0000, ISMD_DEMUX_PID_TYPE_PSI)==ISMD_SUCCESS; m++) {};
  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "   ... Max filters per PSI pid is %d", m);
  for (i=0; i<m; i++) ismd_demux_filter_close (dev_handle, filters[i]);

  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "Checking max filters per PES pid...");
  for (m=0; m<MAX_TEST_FILTERS &&
      ismd_demux_filter_open (dev_handle, ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, 32*1024, &filters[m], &dummy_port)==ISMD_SUCCESS &&
      ismd_demux_filter_map_to_pid (dev_handle, filters[m], 0x0000, ISMD_DEMUX_PID_TYPE_PES)==ISMD_SUCCESS; m++) {};
  GST_CAT_DEBUG (ismd_gst_dvb_src_debug, "   ... Max filters per PSI pid is %d", m);
  for (i=0; i<m; i++) ismd_demux_filter_close (dev_handle, filters[i]);
}
#endif

static inline gboolean
ismd_open (ISmdGstDVBSrc * dvbsrc)
{
  ismd_result_t result;

  /* Open a TSIN device which is a SMD demuxer with the sink port connected to
   * the tuner */
  result = ismd_tsin_open (dvbsrc->tuner, &dvbsrc->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_tsin_open failed(%d)", result);
    return FALSE;
  }

  GST_DEBUG_OBJECT (dvbsrc, "Successfully opened the device %d", dvbsrc->tuner);

  /* Uncomment to find out some filtering-related hardware resources */
#if TEST_RESOURCES
  ismd_check_resources (dvbsrc->dev_handle);
#endif
  return TRUE;
}

static inline gboolean
ismd_reset (ISmdGstDVBSrc * dvbsrc)
{
  ismd_result_t result;

  GST_DEBUG_OBJECT (dvbsrc, "Reset DVB");

  GST_OBJECT_LOCK (dvbsrc);
  dvbsrc->running = FALSE;
  dvbsrc->flushing = TRUE;
  GST_OBJECT_UNLOCK (dvbsrc);

  result = ismd_demux_enable_leaky_filters (dvbsrc->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_enable_leaky_filters failed(%d)",
        result);
  }

  result = ismd_dev_set_state (dvbsrc->dev_handle, ISMD_DEV_STATE_PAUSE);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_dev_set_state failed(%d)", result);
  }

  g_hash_table_foreach (dvbsrc->streams, foreach_stream_stop, dvbsrc);

  if (dvbsrc->psif) {
    psi_filter_destroy (dvbsrc->psif);
    dvbsrc->psif = NULL;
  }

  result = ismd_dev_set_state (dvbsrc->dev_handle, ISMD_DEV_STATE_STOP);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_dev_set_state failed(%d)", result);
  }

  result = ismd_demux_disable_leaky_filters (dvbsrc->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_disable_leaky_filters failed(%d)",
        result);
  }

  GST_OBJECT_LOCK (dvbsrc);
  dvbsrc->flushing = FALSE;
  GST_OBJECT_UNLOCK (dvbsrc);

  GST_DEBUG_OBJECT (dvbsrc, "Succeded in reset DVB");
  return TRUE;
}

static inline gboolean
ismd_close (ISmdGstDVBSrc * dvbsrc)
{
  ismd_result_t result;

  GST_DEBUG_OBJECT (dvbsrc, "Closing DVB");
  result = ismd_dev_set_state (dvbsrc->dev_handle, ISMD_DEV_STATE_STOP);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_dev_set_state failed(%d)", result);
  }

  result = ismd_dev_flush (dvbsrc->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_dev_flush failed(%d)", result);
  }

  result = ismd_dev_close (dvbsrc->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_demux_stream_close failed(%d)", result);
  }
  dvbsrc->dev_handle = ISMD_DEV_HANDLE_INVALID;
  GST_DEBUG_OBJECT (dvbsrc, "device closed");
  return TRUE;
}

#if 0
static
ismd_result_t wait_for_buffering (ismd_dev_t demux_handle,
    unsigned int minimum_buffering)
{
  ismd_result_t result = ISMD_SUCCESS;
  ismd_event_t buffering_event;

  result = ismd_event_alloc (&buffering_event);
  if (ISMD_SUCCESS != result)
  {
    GST_ERROR ("ismd_event_alloc failed(%d)", result);
    return result;
  }

  result = ismd_demux_set_buffering_event (demux_handle, buffering_event,
      minimum_buffering);

  if (result != ISMD_SUCCESS)
  {
     GST_ERROR("ismd_demux_set_buffering_event failed(%d)",
         result);
     goto beach;
  }
  result = ismd_event_wait (buffering_event, BUFFERING_EVENT_TIMEOUT);

beach:
  ismd_event_free (buffering_event);
  return result;
}
#endif

static void
ismd_pat_changed_cb (gpointer user_data) {
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (user_data);

  GST_DEBUG_OBJECT (dvbsrc, "Received 'PAT changed' callback");

  gst_element_post_message (GST_ELEMENT_CAST (dvbsrc),
      gst_message_new_element (GST_OBJECT (dvbsrc),
          psi_filter_build_pat_structure (dvbsrc->psif)));
}

static void
ismd_pmt_changed_cb (gpointer user_data, guint16 service_id) {
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (user_data);

  GST_DEBUG_OBJECT (dvbsrc, "Received 'PMT changed' callback for program %d",
      service_id);
  /* On PMT changes try to enable clock recovery to reconfigure it with the
   * right PCR in the case that it had changed */
  if (service_id == dvbsrc->program) {
    pmt_data pmt;
    if (psi_filter_get_pmt (dvbsrc->psif, dvbsrc->program, &pmt)) {
      ismd_gst_dvb_stream_configure_es_pids (dvbsrc->main_stream, &pmt);
    }
        
    ismd_gst_dvb_src_enable_clock_recovery (dvbsrc);
  }

  if (dvbsrc->discovery || dvbsrc->program == service_id) {
    gst_element_post_message (GST_ELEMENT_CAST (dvbsrc),
        gst_message_new_element (GST_OBJECT (dvbsrc),
            psi_filter_build_pmt_structure (dvbsrc->psif, service_id)));
  }
}

static void
ismd_eit_changed_cb (gpointer user_data, GstStructure * eit) {
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (user_data);

  GST_LOG_OBJECT (dvbsrc, "Received 'EIT changed' callback");

  gst_element_post_message (GST_ELEMENT_CAST (dvbsrc),
      gst_message_new_element (GST_OBJECT (dvbsrc), eit));
}

static void
ismd_tdt_changed_cb (gpointer user_data, GstStructure * tdt) {
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (user_data);

  GST_LOG_OBJECT (dvbsrc, "Received 'TDT changed' callback");

  gst_element_post_message (GST_ELEMENT_CAST (dvbsrc),
      gst_message_new_element (GST_OBJECT (dvbsrc), tdt));
}

static void
foreach_stream_inject_pat (gpointer key, gpointer value, gpointer data)
{
  GstBuffer *buf = GST_BUFFER (data);
  ISmdGstDVBStream *stream = ISMD_GST_DVB_STREAM_CAST (value);
  ismd_gst_dvb_stream_queue_data (stream, buf);
}

static void
ismd_data_inject_cb (gpointer user_data, GstBuffer * buf, gint program) {
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (user_data);

  if (program == -1 && dvbsrc->allowed_pid_categories & PID_CAT_PAT) {
    GST_LOG_OBJECT (dvbsrc, "Injecting PAT");
    g_hash_table_foreach (dvbsrc->streams, foreach_stream_inject_pat, buf);
  }
  else if (dvbsrc->allowed_pid_categories & PID_CAT_PMT) {
    if (dvbsrc->main_stream->program == program) {
      GST_LOG_OBJECT (dvbsrc, "Injecting PMT");
      ismd_gst_dvb_stream_queue_data (dvbsrc->main_stream, buf);
    }
  }
  else {
    ISmdGstDVBStream * stream = ismd_gst_dvb_src_get_stream (dvbsrc, program);
    if (stream) {
      GST_LOG_OBJECT (dvbsrc, "Injecting PMT");
      ismd_gst_dvb_stream_queue_data (stream, buf);
    }
  }
}

static inline gboolean
ismd_play (ISmdGstDVBSrc * dvbsrc)
{
  ismd_result_t result;
  gint i;
  gboolean gresult;
  pat_data pat;
  pmt_data pmt;

  if (!ismd_gst_dvb_stream_open (dvbsrc->main_stream, dvbsrc->dev_handle)) {
    goto beach;
  }

  /* Create a PSI parser */
  gresult = psi_filter_create (dvbsrc->dev_handle, &dvbsrc->psif);
  if (gresult == FALSE) {
    GST_ERROR_OBJECT (dvbsrc, "psi_filter_create failed");
    goto beach;
  }

  psi_filter_set_callbacks (dvbsrc->psif, ismd_pat_changed_cb,
      ismd_pmt_changed_cb, ismd_eit_changed_cb, ismd_tdt_changed_cb,
      ismd_data_inject_cb, (gpointer)dvbsrc);

  /* Start TSI data flow */
  result = ismd_dev_set_state (dvbsrc->dev_handle, ISMD_DEV_STATE_PLAY);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (dvbsrc, "ismd_dev_set_state to PLAY failed(%d)",
        result);
    goto beach;
  }

  /* Collect PAT info */
  GST_DEBUG_OBJECT (dvbsrc, "Collect PAT info");
  gresult = psi_filter_wait_for_pat (dvbsrc->psif, dvbsrc->psi_timeout);
  if (gresult == FALSE) {
     GST_ERROR_OBJECT (dvbsrc, "psi_filter_wait_for_pat failed");
     GST_ELEMENT_ERROR (GST_ELEMENT (dvbsrc), RESOURCE, READ,
         ("Program Association Table not received. Probably there is no "
         "signal."),
         ("PAT not received after timeout period of %llu microseconds",
         dvbsrc->psi_timeout));
     goto beach;
  }

  gresult = psi_filter_get_pat (dvbsrc->psif, &pat);
  if (gresult == FALSE) {
     GST_ERROR_OBJECT (dvbsrc, "psi_filter_get_pat failed");
     goto beach;
  }

  GST_DEBUG_OBJECT (dvbsrc, "Got PAT that describes %d programs",
      pat.entries->len);
  for (i = 0; i < pat.entries->len; i++) {
    pmt_descriptor *pmt = &g_array_index( pat.entries, pmt_descriptor, i);
    GST_DEBUG_OBJECT (dvbsrc, "program # %d PMT PID %04x",
        pmt->program_number, pmt->pmt_pid);
  }

  /* TODO: Take program 0 for now but we would like to push
   * all programs plus PSI when no program filtering is set */
  if (dvbsrc->program == -1) {
    dvbsrc->program =
        g_array_index(pat.entries, pmt_descriptor, 0).program_number;
    GST_DEBUG_OBJECT (dvbsrc, "Auto selected program %d", dvbsrc->program);
  }
  else {
    GST_DEBUG_OBJECT (dvbsrc, "Manually selected program %d", dvbsrc->program);
  }

  dvbsrc->main_stream->program = dvbsrc->program;

  if (dvbsrc->discovery) {
    /* Add the PMT for the selected program to the PSI filter */
    if (!psi_filter_add_all_pmts (dvbsrc->psif)) {
      GST_ERROR_OBJECT (dvbsrc, "Addition of PMTs failed");
      goto beach;
    }
  }
  else {
    /* Add the PMT for the selected program to the PSI filter */
    if (!psi_filter_add_pmt_for_service (dvbsrc->psif, dvbsrc->program)) {
      GST_WARNING_OBJECT (dvbsrc,
          "Program number %d not found in current PAT", dvbsrc->program);
      goto beach;
    }
  }
  /* Remember PMT pid in the stream for PMT injection */
  if (dvbsrc->allowed_pid_categories & PID_CAT_PMT) {
    pmt_descriptor *pmt_desc =
        psi_filter_find_prognum_in_pat (&pat, dvbsrc->program);
    if (pmt_desc == NULL) {
      GST_WARNING_OBJECT (dvbsrc,
          "Program number %d not found in current PAT", dvbsrc->program);
      GST_ELEMENT_ERROR (GST_ELEMENT (dvbsrc), RESOURCE, READ,
          ("Service ID not found. Probably the requested Service ID "
          "#%d does not exist", dvbsrc->program),
          ("Service ID not found in received PATs"));
      goto beach;
    }
    dvbsrc->main_stream->pmt_pid = pmt_desc->pmt_pid;
  }

  /* Collect PMT info */
  GST_DEBUG_OBJECT (dvbsrc, "Collect PMT info (program %d)", dvbsrc->program);
  gresult = psi_filter_wait_for_pmt (dvbsrc->psif, dvbsrc->program,
      dvbsrc->psi_timeout);
  if (gresult == FALSE) {
     GST_ERROR_OBJECT (dvbsrc, "psi_filter_wait_for_pmt failed");
     GST_ELEMENT_ERROR (GST_ELEMENT (dvbsrc), RESOURCE, READ,
         ("Program Map Table not received. Probably the requested Service ID "
         "#%d does not exist", dvbsrc->program),
         ("PMT not received after timeout period of %llu microseconds",
         dvbsrc->psi_timeout));
     goto beach;
  }

  gresult = psi_filter_get_pmt (dvbsrc->psif, dvbsrc->program, &pmt);
  if (gresult == FALSE) {
     GST_ERROR_OBJECT (dvbsrc, "psi_filter_get_pmt failed");
     goto beach;
  }

  /* Enable these PIDs */
  /* PCR */
  if (dvbsrc->allowed_pid_categories & PID_CAT_PCR) {
    GST_DEBUG_OBJECT (dvbsrc, "Added PCR with pid 0x%04x",
        pmt.pcr_pid);

    if (!ismd_gst_dvb_stream_map_pid (dvbsrc->main_stream, pmt.pcr_pid,
          ISMD_DEMUX_PID_TYPE_PSI)) {
      goto beach;
    }
  }
  /* Elementary Stream PIDs */
  if (!ismd_gst_dvb_stream_configure_es_pids (dvbsrc->main_stream, &pmt)) {
    goto beach;
  }
  
  /* Requested extra PIDs (regardless of possible PID filtering) */
  for (i = 0; i < dvbsrc->nb_extra_pids; i++) {
    GST_DEBUG_OBJECT (dvbsrc, "Added Extra pid 0x%04x",
        dvbsrc->extra_pids[i]);
    if (!ismd_gst_dvb_stream_map_pid (dvbsrc->main_stream,
          dvbsrc->extra_pids[i], ISMD_DEMUX_PID_TYPE_PES)) {
      goto beach;
    }
  }
  dvbsrc->main_stream->configured = TRUE;
#if 0
  GST_DEBUG_OBJECT (dvbsrc, "Start buffering...");
  result = wait_for_buffering(dvbsrc->dev_handle, MINIMUM_BUFFERING);
  if (result != ISMD_SUCCESS) {
     GST_ERROR_OBJECT (dvbsrc, "wait_for_buffering");
     return FALSE;
  }
  GST_DEBUG_OBJECT (dvbsrc, "Buffering done.");
#endif

  /* Here we can start the task to push buffers in the src pad */
  g_hash_table_foreach (dvbsrc->streams,
      foreach_stream_start, dvbsrc);

  return TRUE;

beach:
  ismd_reset (dvbsrc);
  return FALSE;
}

static GstStateChangeReturn
ismd_gst_dvb_src_change_state (GstElement * element, GstStateChange transition)
{
  ISmdGstDVBSrc *dvbsrc = ISMD_GST_DVB_SRC (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  GstClock *base_clock = NULL;

  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
    {
      GST_OBJECT_LOCK (dvbsrc);
      dvbsrc->running = FALSE;
      GST_OBJECT_UNLOCK (dvbsrc);
      if (!ismd_open (dvbsrc)) {
        goto failure;
      }
      break;
    }
    case GST_STATE_CHANGE_READY_TO_PAUSED:
    {
      if (!ismd_play (dvbsrc)) {
        goto failure;
      }
      break;
    }
    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
    {
      ismd_result_t result;
      dvbsrc->clock_is_ismd = FALSE;
      base_clock = gst_element_get_clock (element);
      GST_OBJECT_LOCK (dvbsrc);
      dvbsrc->running = TRUE;
      GST_OBJECT_UNLOCK (dvbsrc);
      if (ISMD_GST_IS_CLOCK (base_clock)) {
        /* Enable clock recovery, to sync with the clock embedded in the TS */
        ISmdGstClock *ismd_clock = ISMD_GST_CLOCK (base_clock);
        ismd_demux_stats_t demux_stats;
        demux_stats.clock_sync_handle = ISMD_DEV_HANDLE_INVALID;

        GST_INFO_OBJECT (dvbsrc, "An ISMD clock (ID:%d) has been provided: ",
            ismd_clock->dev_handle);
        dvbsrc->clock_is_ismd = TRUE;
        /* ismd_element does not call dev_set_clock for src elements */
        result = ismd_dev_set_clock (dvbsrc->dev_handle,
            ismd_clock->dev_handle);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (dvbsrc, "ismd_dev_set_clock failed(%d)",
              result);
          goto failure;
        }
        if (!ismd_gst_dvb_src_enable_clock_recovery (dvbsrc)) {
          goto failure;
        }

        result = ismd_demux_get_stats (dvbsrc->dev_handle, 0, &demux_stats);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (dvbsrc, "ismd_demux_get_stats failed(%d)",
              result);

        }
        else if (demux_stats.clock_sync_handle != ISMD_DEV_HANDLE_INVALID) {
          ismd_gst_clock_bufmon_add_source (ismd_clock,
              demux_stats.clock_sync_handle);
        }
      }
      break;
    }
    case GST_STATE_CHANGE_PAUSED_TO_READY:
    {
      if (!ismd_reset (dvbsrc)) {
        goto failure;
      }
      break;
    }
    case GST_STATE_CHANGE_READY_TO_NULL:
    {
      if (!ismd_close (dvbsrc)) {
        goto failure;
      }
      break;
    }
    default:
      break;
  }

  /* Chain up to the parent class's state change function */
  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    goto failure;
  }

  /* Loose the ref to the clock */
  if (base_clock)
    gst_object_unref (base_clock);

  return ret;

failure:
  GST_DEBUG_OBJECT (dvbsrc, "state change failed");

  /* Loose the ref to the clock */
  if (base_clock)
    gst_object_unref (base_clock);

  ret = GST_STATE_CHANGE_FAILURE;
  return ret;
}

static GstPad *
ismd_gst_dvb_src_request_new_pad (GstElement * element,
    GstPadTemplate * template, const gchar * name)
{
  ISmdGstDVBSrc *dvbsrc;
  ISmdGstDVBStream *stream;
  gint program = -1;

  g_return_val_if_fail (template != NULL, NULL);
  g_return_val_if_fail (ISMD_GST_IS_DVB_SRC (element), NULL);

  dvbsrc = ISMD_GST_DVB_SRC (element);
  sscanf (name, "program_%d", &program);
  GST_DEBUG_OBJECT (dvbsrc, "Requested pad %s for program %d", name, program);
  stream = ismd_gst_dvb_src_add_stream (dvbsrc, FALSE, program, G_MAXUINT16);

  if (dvbsrc->dev_handle != ISMD_DEV_HANDLE_INVALID) {
    if (!stream->setup) {
      ismd_gst_dvb_stream_open (stream, dvbsrc->dev_handle);
    }
    ismd_gst_dvb_stream_start (stream);
  }
  return GST_PAD (stream);
}

static void
ismd_gst_dvb_src_release_pad (GstElement * element, GstPad * pad)
{
  ISmdGstDVBSrc *dvbsrc;
  ISmdGstDVBStream *stream;
  ismd_result_t result;

  g_return_if_fail (ISMD_GST_IS_DVB_SRC (element));

  dvbsrc = ISMD_GST_DVB_SRC (element);
  stream = ISMD_GST_DVB_STREAM_CAST (pad);

  GST_DEBUG_OBJECT (stream, "release pad for program %d", stream->program);

  ismd_gst_dvb_src_remove_stream (dvbsrc, stream->program);
  result = ismd_event_strobe (stream->port_event);
  gst_pad_set_active (pad, FALSE);

  ismd_gst_dvb_stream_close (stream, dvbsrc->dev_handle);
  /* we do the cleanup in GstElement::pad-removed */
  gst_element_remove_pad (element, pad);
}

/**
 * ismd_gst_dvb_src_base_init
 *      Define element details and add pad templates if any
 *      @g_class - Pointer to the GStreamer object
 */
static void
ismd_gst_dvb_src_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_dvb_src_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) DVB Source Element",
      "Source/Video",
      "GStreamer Digital Video Broadcast Source for Intel's Media Processors",
      "http://www.intelconsumerelectronics.com/");

  GstElementClass *element_class = GST_ELEMENT_CLASS (g_class);

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&src_factory));

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&prog_factory));

  gst_element_class_set_details (element_class, &ismd_gst_dvb_src_details);
}

static void
ismd_gst_dvb_src_class_init (ISmdGstDVBSrcClass * klass)
{

  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GObjectClass *oclass = G_OBJECT_CLASS (klass);

  oclass->get_property = ismd_gst_dvb_src_get_property;
  oclass->set_property = ismd_gst_dvb_src_set_property;

  oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_dvb_src_dispose);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_dvb_src_finalize);

  g_object_class_install_property (oclass, PROP_TUNER,
      g_param_spec_uint ("tuner", "tuner",
          "Specifies the tuner id to use.",
          0, 0xffffffff, DEFAULT_TUNER, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_PROGRAM,
      g_param_spec_uint ("program", "program",
          "Specifies the program number to use. Default -1 select first in PAT.",
          0, 0xffffffff, DEFAULT_PROGRAM, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_PSI_TIMEOUT,
      g_param_spec_uint64 ("psi-timeout", "psi-timeout",
          "Specifies the maximum number of microseconds to wait for a PAT"
          " or PMT to arrive.",
          0, G_MAXUINT64, DEFAULT_PSI_TIMEOUT, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_EXTRA_PIDS,
      g_param_spec_string ("extra-pids",
          "Colon separated list of extra PIDs to allow through the filter",
          "Extra PIDs to allow through the filter, eg 0x10:0x11:0x20",
          DEFAULT_ES_PIDS, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_PID_FILTER,
      g_param_spec_flags ("pid-filter", "pid-filter",
          "Bitfield specifying the PID categories allowed through the filter",
          GST_TYPE_FLAGS_PID_CATEGORY, DEFAULT_PID_FILTER, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_CHECK_CRC,
      g_param_spec_boolean ("check-crc", "check-crc",
          "Discard incomming PSI packets with wrong CRC",
          DEFAULT_CHECK_CRC, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_CLOCK_RECOVERY,
      g_param_spec_boolean ("clock-recovery", "clock-recovery",
          "Enable or disable clock recovery based on the PCR",
          DEFAULT_CLOCK_RECOVERY, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_DISCOVERY,
      g_param_spec_boolean ("discovery", "discovery",
          "Enables discovery mode",
          DEFAULT_DISCOVERY, G_PARAM_READWRITE));

  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_dvb_src_change_state);
  eclass->request_new_pad =
      GST_DEBUG_FUNCPTR (ismd_gst_dvb_src_request_new_pad);
  eclass->release_pad =
      GST_DEBUG_FUNCPTR (ismd_gst_dvb_src_release_pad);
  /*
   * In order to support demux's 'usr arrive time' API,
   * assign clock to demux.
   */
  ismd_gst_element_requires_clock (eclass);
}

static void
ismd_gst_dvb_src_init (ISmdGstDVBSrc * dvbsrc, ISmdGstDVBSrcClass * g_class)
{
  dvbsrc->tuner = DEFAULT_TUNER;
  dvbsrc->program = DEFAULT_PROGRAM;
  dvbsrc->psi_timeout = DEFAULT_PSI_TIMEOUT;
  dvbsrc->allowed_pid_categories = DEFAULT_PID_FILTER;
  dvbsrc->dev_handle = ISMD_DEV_HANDLE_INVALID;
  dvbsrc->extra_pids = NULL;
  dvbsrc->nb_extra_pids = 0;
  dvbsrc->check_crc = DEFAULT_CHECK_CRC;
  dvbsrc->clock_recovery = DEFAULT_CLOCK_RECOVERY;
  dvbsrc->discovery = DEFAULT_DISCOVERY;
  dvbsrc->running = FALSE;
  dvbsrc->flushing = FALSE;
  dvbsrc->clock_is_ismd = FALSE;
  dvbsrc->current_pcr_pid = -1;
  dvbsrc->psif = NULL;

  dvbsrc->streams = g_hash_table_new_full (g_direct_hash, g_direct_equal,
      NULL, (GDestroyNotify) gst_object_unref);

  /* Create the main stream pad. */
  dvbsrc->main_stream =
      ismd_gst_dvb_src_add_stream (dvbsrc, TRUE, -1, G_MAXUINT16);
}

