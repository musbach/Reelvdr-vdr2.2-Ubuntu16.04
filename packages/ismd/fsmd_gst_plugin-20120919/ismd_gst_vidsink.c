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

/**
 * SECTION:element-vidsink
 * @short_description: generic sink for vidsink at NV12/YV12/I420
 * @see_also: #GstVidsink
 *
 * This sink element provides generic NV12/YV12/I420 video post-processing
 * and rendering
 */

#include <string.h>
#include <gst/gstmarshal.h>
#include <ismd_core.h>
#include <ismd_vidpproc.h>
#include <ismd_vidrend.h>
#include <ismd_vidsink.h>
#include "platform_config_paths.h"
#include "platform_config.h"
#include "ismd_gst_vidsink.h"
#include "ismd_gst_element.h"
#include "ismd_gst_enum.h"
#include "ismd_gst_rectangle.h"

//#undef GST_DEBUG_OBJECT
//#define GST_DEBUG_OBJECT GST_ERROR_OBJECT

////////////////////////////////////////////////////////////////////////////////
// Shortcut macros for accessing core platform configuration properties
////////////////////////////////////////////////////////////////////////////////

#ifndef ISMD_CORE_INT_PROPERTY
#define ISMD_CORE_INT_PROPERTY(name) ({                                         \
   config_result_t icipret = CONFIG_SUCCESS;                                    \
   int icipint = 0;                                                             \
   config_ref_t icip_attr_id = ROOT_NODE;                                       \
                                                                                \
   icipret = config_node_find(ROOT_NODE,                                        \
                              CONFIG_PATH_SMD_CORE,                             \
                              &icip_attr_id);                                   \
   if (icipret == CONFIG_SUCCESS) {                                             \
      icipret = config_get_int(icip_attr_id, name, &icipint);                   \
   }                                                                            \
                                                                                \
   if (icipret != CONFIG_SUCCESS) {                                             \
      OS_INFO("Error! %s undefined!", name);                                    \
   }                                                                            \
   icipint;                                                                     \
})
#endif

#define SYSTEM_STRIDE ISMD_CORE_INT_PROPERTY("frame_buffer_properties.stride")
#define CACHE_LINE_SIZE (64)
#define ROUND_UP(num, amt) ((num%amt) ? (num+amt) - (num%amt) : num)

#define ISMD_GST_VIDSINK_CAPS \
           "video/x-decoded-ismd; " \
           "video/x-raw-yuv, " \
           "  format = (fourcc) {NV12, YV12, I420}, "\
           "  width = (int) [16,1920], " \
           "  height = (int) [16,1088]; " \
           "video/x-raw-yuv, " \
           "  format = (fourcc) {YV12, I420}, "\
           "  width = (int) [16,1920], " \
           "  height = (int) [16,1088] "


/* Structure definitions */
static GstStaticPadTemplate ismd_gst_vidsink_sinkpad_template =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VIDSINK_CAPS)
    );

GST_DEBUG_CATEGORY_STATIC (ismd_gst_vidsink_debug);
#define GST_CAT_DEFAULT ismd_gst_vidsink_debug

enum
{
  PROP_VIDSINK_UNKNOWN,
  PROP_VIDSINK_SCALE_MODE,
  PROP_VIDSINK_PAN_AND_SCAN,
  PROP_VIDSINK_RECTANGLE,
  PROP_VIDSINK_TVMODE,
  PROP_VIDSINK_BG_COLOR,
  PROP_VIDSINK_GDL_PLANE,
  PROP_VIDSINK_QOS,
  PROP_VIDSINK_FLUSH_REPEAT_FRAME,
};

#define DEFAULT_ISMD_VIDSINK_SCALE_MODE      ZOOM_TO_FIT
#define DEFAULT_ISMD_VIDSINK_RECTANGLE       "0,0,0,0"
#define DEFAULT_ISMD_VIDSINK_PAN_AND_SCAN    FALSE
#define DEFAULT_ISMD_VIDSINK_TVMODE          -1
#define DEFAULT_ISMD_VIDSINK_BG_COLOR        0
#define DEFAULT_ISMD_VIDSINK_GDL_PLANE       GDL_PLANE_ID_UPP_A
#define DEFAULT_ISMD_VIDSINK_QOS             TRUE
#define DEFAULT_ISMD_VIDSINK_FLUSH_REPEAT_FRAME FALSE

#define DO_RUNNING_AVG(avg,val,size) (((val) + ((size)-1) * (avg)) / (size))

/* generic running average, this has a neutral window size */
#define UPDATE_RUNNING_AVG(avg,val)   DO_RUNNING_AVG(avg,val,8)
/* the windows for these running averages are experimentally obtained.
 * possitive values get averaged more while negative values use a small
 * window so we can react faster to badness. */
#define UPDATE_RUNNING_AVG_P(avg,val) DO_RUNNING_AVG(avg,val,16)
#define UPDATE_RUNNING_AVG_N(avg,val) DO_RUNNING_AVG(avg,val,4)

enum
{
  FORMAT_UNDEFINED,
  FORMAT_ISMD,
  FORMAT_RAW,
  FORMAT_LAST
};

static GstBuffer *
vidsink_yv12_to_nv12 (ISmdGstVidsink * vidsink, GstBuffer * in_buffer);

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_vidsink_debug, "ISMD_VIDSINK",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstvidsink element");
}

/* Call Boilerplate to declare the base_init, class_init and init functions
 * and to define the get_type function */
GST_BOILERPLATE_FULL (ISmdGstVidsink, ismd_gst_vidsink, ISmdGstElement,
    ISMD_GST_TYPE_ELEMENT, _do_init);

static void
ismd_gst_vidsink_reset_qos (ISmdGstVidsink * sink)
{
  gint i;
  for (i = 0; i < QOS_MAX_TRACK; i++) {
      sink->qos_entries [i].arrival = ISMD_NO_PTS;
      sink->qos_entries [i].queued = ISMD_NO_PTS;
  }
  sink->avg_pt = 0;  
  sink->avg_rate = 0;
  sink->avg_duration = GST_CLOCK_TIME_NONE;
}

static void
ismd_gst_vidsink_track_qos (ISmdGstElement * smd_element,
    gint client_id, gint t)
{
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (smd_element);
  ismd_time_t time = 0;
  if (sink->provided_clock) {
    ismd_clock_get_time (sink->provided_clock->dev_handle, &time);
  }
  if (time == ISMD_NO_PTS) {
    time = 0;
  }
  if (t) {
    GST_DEBUG_OBJECT (smd_element, "store queued time %llu for client_id %d",
      time, client_id);
    sink->qos_entries[client_id%QOS_MAX_TRACK].queued = time;
  }
  else {
    GST_DEBUG_OBJECT (smd_element, "store arrival time %llu for client_id %d",
      time, client_id);
    sink->qos_entries[client_id%QOS_MAX_TRACK].arrival = time;
  }
}

static gboolean
ismd_gst_vidsink_send_qos (ISmdGstVidsink * sink, gint client_id,
    ismd_time_t pts)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  gboolean res;
  gdouble rate = 0.0;
  GstClockTime time = 0;
  ismd_time_t ctime = -1;
  qos_entry *cqos, *pqos;
  GstClockTime pt, last_duration = 0;
  GstClockTimeDiff jitter;

  /* current time of this buffer */
  if (sink->provided_clock) {
    ismd_clock_get_time (sink->provided_clock->dev_handle, &ctime);
  }

  /* arrival time and queued time of current and previous buffer */
  cqos = &sink->qos_entries[client_id%QOS_MAX_TRACK];
  if (client_id > 0) {
    pqos = &sink->qos_entries[(client_id-1)%QOS_MAX_TRACK];
  } else {
    pqos = cqos;
  }
  GST_DEBUG_OBJECT (sink, "current qos: arrival time: %" G_GUINT64_FORMAT
      " queued time: %" G_GUINT64_FORMAT " d: %" G_GUINT64_FORMAT,
      cqos->arrival, cqos->queued, cqos->queued - cqos->arrival);
  GST_DEBUG_OBJECT (sink, "previous qos: arrival time: %" G_GUINT64_FORMAT
      " queued time: %" G_GUINT64_FORMAT " d: %" G_GUINT64_FORMAT,
      pqos->arrival, pqos->queued, pqos->queued - pqos->arrival);

  /* calculate the running time of the buffer */
  time = gst_segment_to_running_time (&smd_element->segment, GST_FORMAT_TIME,
      SMD_TO_GST_TIME (pts));

  if (cqos->arrival != ISMD_NO_PTS) {
      /* jitter time of this buffer */
      jitter = SMD_TO_GST_TIME (cqos->arrival) - time;

      /* processing time with the previous buffer */
      if (cqos->arrival > pqos->queued) {
          pt = SMD_TO_GST_TIME (cqos->arrival - pqos->queued);
      }
      else {
          pt = 0;
      }
  } else {
      jitter = 0;
      pt = 0;
  }
  
  GST_DEBUG_OBJECT (sink, "qos: current time: %" G_GINT64_FORMAT
      " jitter time: %" G_GINT64_FORMAT
      " processing time: %" G_GUINT64_FORMAT " (%" G_GUINT64_FORMAT ")",
      ctime, jitter, pt, GST_TO_SMD_TIME (pt));

  sink->avg_pt = UPDATE_RUNNING_AVG (sink->avg_pt, pt);

  /* calculate last duration and update the average */
  if (sink->qos_last_pts != ISMD_NO_PTS) {
    if (pts > sink->qos_last_pts) {
      last_duration = SMD_TO_GST_TIME (pts - sink->qos_last_pts);
    }
  }
  /* collect running averages. for first observations, we copy the
   * values */
  if (!GST_CLOCK_TIME_IS_VALID (sink->avg_duration))
    sink->avg_duration = last_duration;
  else 
    sink->avg_duration = UPDATE_RUNNING_AVG (sink->avg_duration, last_duration);

  if (sink->avg_duration != 0)
    rate =
        gst_guint64_to_gdouble (sink->avg_pt) /
        gst_guint64_to_gdouble (sink->avg_duration);
  else
    rate = 1.0;

  if (sink->avg_rate < 0.0) {
    sink->avg_rate = rate;
  } else {
    if (rate > 1.0)
      sink->avg_rate = UPDATE_RUNNING_AVG_N (sink->avg_rate, rate);
    else
      sink->avg_rate = UPDATE_RUNNING_AVG_P (sink->avg_rate, rate);
  }

  GST_DEBUG_OBJECT (sink,
      "updated: avg_duration: %" GST_TIME_FORMAT ", avg_pt: %" GST_TIME_FORMAT
      ", avg_rate: %g", GST_TIME_ARGS (sink->avg_duration),
      GST_TIME_ARGS (sink->avg_pt), sink->avg_rate);

  if (sink->avg_rate >= 0.0) {
    GstEvent *event;  

    /* generate Quality-of-Service event */
    GST_DEBUG_OBJECT (sink, "qos: proportion: %g, diff %" G_GINT64_FORMAT
        ", timestamp %" GST_TIME_FORMAT,
        sink->avg_rate, jitter, GST_TIME_ARGS (time));

    event = gst_event_new_qos (sink->avg_rate, jitter, time);

    /* send upstream */
    res = gst_pad_push_event (GST_PAD (smd_element->sink_pad), event);
  }  

  /* update stats */
  sink->qos_last_pts = pts;

  return res;
}

static GstBuffer *
ismd_gst_vidsink_convert (ISmdGstElement * smd_element, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  ISmdGstVidsink *vidsink = ISMD_GST_VIDSINK (smd_element);
  GstBuffer *outbuf = buf;
  GstClockTime pts, duration;
  gint64 clip_start, clip_stop;
  gboolean in_seg;

  if (G_UNLIKELY(!vidsink->has_newsegment)) {
    GST_LOG_OBJECT (vidsink, "dropping buffer due missing new segment");
    gst_buffer_unref (buf);
    outbuf = NULL;
    goto beach;
  }

  pts = GST_BUFFER_TIMESTAMP (buf);
  duration = GST_BUFFER_DURATION (buf);
  if (GST_CLOCK_TIME_IS_VALID (pts)) {
    GST_LOG_OBJECT (vidsink, "check for clipping on buffer %p with pts %" \
        GST_TIME_FORMAT " and duration %" GST_TIME_FORMAT,
        buf, GST_TIME_ARGS (pts), GST_TIME_ARGS (duration));

    clip_start = clip_stop = pts;
    if (GST_CLOCK_TIME_IS_VALID (duration))
      clip_stop += duration;

    /* Check if this buffer's timestamp/duration is in our segment */
    in_seg = gst_segment_clip (&smd_element->segment, GST_FORMAT_TIME,
        clip_start, clip_stop, &clip_start, &clip_stop);

    if (G_UNLIKELY (!in_seg)) {
      GST_LOG_OBJECT (vidsink, "dropping buffer due to temporal clipping");
      gst_buffer_unref (buf);
      outbuf = NULL;
    }
  }

  if (outbuf && (vidsink->is_yv12 || vidsink->is_i420)) {
    outbuf = vidsink_yv12_to_nv12 (vidsink, outbuf);
  }

beach:
  return outbuf;
}

static void
ismd_gst_vidsink_prerolled (ISmdGstElement * smd_element)
{
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (smd_element);

  if (!sink->first_advance_to_pts) {
    ismd_vidsink_advance_to_pts (smd_element->dev_handle, 1);
  }
  sink->first_advance_to_pts = FALSE;
}

static void
ismd_gst_vidsink_drain (ISmdGstElement * smd_element)
{
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (smd_element);
  ismd_result_t result;
  ismd_event_t event_handle;
  ismd_vidrend_status_t status;
  gint counter = 0;

  result = ismd_vidrend_get_client_id_seen_event (smd_element->dev_handle,
      &event_handle );
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (sink, "ismd_vidrend_get_client_id_seen_event "
        "failed(%d)", result);
    goto beach;
  }

  while (result == ISMD_SUCCESS) {
    result = ismd_event_wait (event_handle, 50);
    if (result == ISMD_SUCCESS) {
      ismd_event_acknowledge (event_handle);
      result = ismd_vidrend_get_status (smd_element->dev_handle, &status);
      if (result == ISMD_SUCCESS) {
        GST_DEBUG_OBJECT (sink, "got client_id %d", status.client_id_last_seen);
      }
      counter = 0;
    }
    else if (result == ISMD_ERROR_TIMEOUT) {
      counter += 50;
      GST_LOG_OBJECT (sink, "timeout %d", counter);
      if (counter < ISMD_POLL_TIMEOUT) {
        result = ISMD_SUCCESS;
      }
    }
  }

beach:
  return;
}

static gboolean
ismd_gst_vidsink_event (ISmdGstElement * smd_element, GstEvent * event)
{
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (smd_element);

  switch (event->type) {
    case GST_EVENT_NEWSEGMENT:
      {
        gboolean update;
        gst_event_parse_new_segment (event, &update, NULL, NULL, NULL,
            NULL, NULL);
        if (!update) {
          sink->has_newsegment = TRUE;
        }
      }
      break;
    case GST_EVENT_FLUSH_STOP:
      sink->has_newsegment = FALSE;
      ismd_gst_vidsink_reset_qos (sink);
      ismd_vidsink_set_base_time(smd_element->dev_handle,
                       sink->ismd_basetime);
      break; 
   case GST_EVENT_FLUSH_START:
       ismd_dev_get_stream_base_time(sink->vidrend_handle,
                         &sink->ismd_basetime);
      break;
    default:
      break;
  }
  return TRUE;
}

static void
ismd_gst_vidsink_handle_buffer (ISmdGstVidsink * sink,
    ismd_buffer_handle_t buf_handle)
{
  ismd_result_t result;
  gint client_id;
  ismd_buffer_descriptor_t buf_desc;
  ismd_time_t pts = ISMD_NO_PTS;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  GstElement *gst_element = GST_ELEMENT(smd_element);

  /* Read the buffer description to recover the pts */
  memset (&buf_desc, 0, sizeof (buf_desc));
  result = ismd_buffer_read_desc (buf_handle, &buf_desc);
  if (result == ISMD_SUCCESS) {
    ismd_frame_attributes_t *attr =
        (ismd_frame_attributes_t *) & (buf_desc.attributes);
    pts = attr->original_pts;
  }

  /* Check client id (buffer's serial number) */
  result = ismd_tag_get_client_id (buf_handle, &client_id);
  if (result != ISMD_SUCCESS) {
    GST_DEBUG_OBJECT (sink, "Got buffer with no client-id (error %d)",
        result);
  } else {
    GST_DEBUG_OBJECT (sink, "Got buffer with client-id %d", client_id);
    /* Perform QoS */
    if (sink->qos_enabled && (pts != ISMD_NO_PTS) && (gst_element->current_state == GST_STATE_PLAYING)) {
      ismd_gst_vidsink_send_qos (sink, client_id, pts);
    }
  }

  /* Check for EOS mark */
  result = ismd_tag_get_eos (buf_handle);
  if (result == ISMD_SUCCESS && !sink->eos_posted) {
    GST_DEBUG_OBJECT (sink, "Posting EOS message");
    if (!gst_element_post_message (GST_ELEMENT (sink),
            gst_message_new_eos (GST_OBJECT (sink)))) {
      GST_ERROR_OBJECT (sink, "Couldn't post sink EOS message");
    }
    sink->eos_posted = TRUE;
  }

  GST_LOG_OBJECT (sink, "dropping ismd buffer %d", buf_handle);
  result = ismd_buffer_dereference (buf_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "freeing ismd_buffer failed(%d)", result);
  }
}

static void
ismd_gst_vidsink_loop (ISmdGstVidsink * sink)
{
  ismd_result_t result;
  ismd_buffer_handle_t buf_handle;
  ismd_event_list_t event_list = { sink->eos_event, sink->out_event };
  ismd_event_t event;

  result = ismd_port_read (sink->out_port, &buf_handle);
  if (result != ISMD_SUCCESS) {
    if (result != ISMD_ERROR_NO_DATA_AVAILABLE) {
      GST_LOG_OBJECT (sink, "ismd_port_read failed(%d) on port %d",
          result, sink->out_port);
    }
  }
  else {
    ismd_gst_vidsink_handle_buffer (sink, buf_handle);
  }

  if (!sink->monitor_stop) {
    GST_LOG_OBJECT (sink, "wait for event");
    result = ismd_event_wait_multiple (event_list, 2, ISMD_TIMEOUT_NONE,
        &event);
    if (result == ISMD_SUCCESS) {
      if (event == sink->eos_event) {
        if (!sink->eos_posted) {
          GST_DEBUG_OBJECT (sink, "Posting EOS message");
          if (!gst_element_post_message (GST_ELEMENT (sink),
                  gst_message_new_eos (GST_OBJECT (sink)))) {
            GST_ERROR_OBJECT (sink, "Couldn't post sink EOS message");
          }
          sink->eos_posted = TRUE;
        }
        result = ismd_event_reset (event);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (sink, "ismd_event_reset failed(%d)", result);
        }
      }
      else if (event == sink->out_event) {
        GST_LOG_OBJECT (sink, "SMD port just got some data");
      }
      ismd_event_acknowledge (event);
    }
    else {
      GST_ERROR_OBJECT (sink, "ismd_event_wait_multiple failed(%d)", result);
    }
  }
}

GstClock *
ismd_gst_vidsink_provide_clock (GstElement * element)
{
  ISmdGstVidsink *sink;
  GstClock *clock;

  sink = ISMD_GST_VIDSINK (element);
  if (G_UNLIKELY (sink->provided_clock == NULL)) {
    sink->provided_clock = ismd_gst_clock_get_default_clock();
  }
  clock = GST_CLOCK_CAST (gst_object_ref (sink->provided_clock));

  GST_INFO_OBJECT (sink, "provide %p (ID:%d)",
      clock, sink->provided_clock->dev_handle);

  return clock;
}

static inline gdl_ret_t
set_gdl_port_attribute (ISmdGstVidsink * sink, gdl_pd_id_t pd_id)
{
  gdl_display_id_t display_id = GDL_DISPLAY_ID_0;
  gdl_uint32 port_brightness = sink->brightness;
  gdl_uint32 port_contrast = sink->contrast;
  gdl_uint32 port_hue = sink->hue;
  gdl_uint32 port_pic_aspect_ratio = sink->aspect_ratio;
  gdl_ret_t ret = GDL_SUCCESS;
  gdl_boolean_t enable_port = GDL_TRUE;

  ret = gdl_port_set_attr (pd_id, GDL_PD_ATTR_ID_POWER, &enable_port);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "gdl_port_set_attr (GDL_PD_ATTR_ID_POWER) failed ret: %d", ret);
    return ret;
  }
  switch (pd_id) {
    case GDL_PD_ID_HDMI:
    {
      /* set hdmi port attribute */
      if (port_pic_aspect_ratio != 0) {
        ret =
            gdl_port_set_attr (pd_id, GDL_PD_ATTR_ID_PAR,
            &port_pic_aspect_ratio);
        if (ret != GDL_SUCCESS) {
          GST_ERROR_OBJECT (sink,
              "gdl_port_set_attr (PIXEL_FORMAT_OUTPUT) failed! ret: %d", ret);
          return ret;
        }
      }
      break;
    }
    case GDL_PD_ID_INTTVENC:
    case GDL_PD_ID_INTTVENC_COMPONENT:
    {
      /* set analog port attribute */
      if (port_brightness != 0) {
        ret =
            gdl_port_set_attr (pd_id, GDL_PD_ATTR_ID_BRIGHTNESS,
            &port_brightness);
        if (ret != GDL_SUCCESS) {
          GST_ERROR_OBJECT (sink,
              "gdl_port_set_attr (BRIGHTNESS) failed! ret: %d", ret);
          return ret;
        }
      }
      if (port_contrast != 0) {
        ret =
            gdl_port_set_attr (pd_id, GDL_PD_ATTR_ID_CONTRAST, &port_contrast);
        if (ret != GDL_SUCCESS) {

          GST_ERROR_OBJECT (sink,
              "gdl_port_set_attr (CONTRAST) failed! ret: %d", ret);
          return ret;
        }
      }
      if (pd_id == GDL_PD_ID_INTTVENC) {
        if (port_hue != 0) {
          ret = gdl_port_set_attr (pd_id, GDL_PD_ATTR_ID_HUE, &port_hue);
          if (ret != GDL_SUCCESS) {
            GST_ERROR_OBJECT (sink, "gdl_port_set_attr (HUE) failed! ret: %d",
                ret);
            return ret;
          }
        }
      }
      if (pd_id == GDL_PD_ID_INTTVENC_COMPONENT) {
        ret =
            gdl_port_set_attr (pd_id, GDL_PD_ATTR_ID_DISPLAY_PIPE, &display_id);
        if (ret != GDL_SUCCESS) {
          GST_ERROR_OBJECT (sink,
              "gdl_port_set_attr (DISPLAY_PIPE) failed! ret: %d", ret);
          return ret;
        }
      }
      break;
    }
    default:
      GST_ERROR_OBJECT (sink, "invalid pd_id");
      return GDL_ERR_FAILED;
  }
  return ret;
}

static inline gdl_ret_t
config_tvmode (ISmdGstVidsink * sink)
{
  gdl_ret_t ret = GDL_SUCCESS;
  gdl_display_info_t di;

  GST_DEBUG_OBJECT (sink, "configure TV mode");
  memset (&di, 0, sizeof (di));

  if (sink->tvmode == DEFAULT_ISMD_VIDSINK_TVMODE) {
    /* Read current hardware state */
    ret = gdl_get_display_info (GDL_DISPLAY_ID_0, &di);
    if (ret != GDL_SUCCESS) {
      GST_ERROR_OBJECT (sink, "gdl_get_display_info failed! ret: %d", ret);
      goto beach;
    }
    GST_DEBUG_OBJECT (sink, "Current Disp_id: %d  %dx%d %d %d",
        di.id, di.tvmode.width, di.tvmode.height, di.tvmode.refresh,
        di.tvmode.interlaced);
  } else {
    di.tvmode.width = tvmodes[sink->tvmode].width;
    di.tvmode.height = tvmodes[sink->tvmode].height;
    di.tvmode.refresh = tvmodes[sink->tvmode].refresh;
    di.tvmode.interlaced = tvmodes[sink->tvmode].interlaced;
    GST_DEBUG_OBJECT (sink, "%s Disp_id: %d  %dx%d %d %d",
        tvmodes[sink->tvmode].alias, GDL_DISPLAY_ID_0, di.tvmode.width,
        di.tvmode.height, di.tvmode.refresh, di.tvmode.interlaced);
  }

  /* HSD Defect 2753995. Improper background selection */
  if (di.tvmode.height > 576) {
    di.color_space = GDL_COLOR_SPACE_BT709;
  } else {
    di.color_space = GDL_COLOR_SPACE_BT601;
  }

  di.bg_color = sink->bg_color;
  di.gamma = sink->gamma;
  di.flags = 0;
  di.id = GDL_DISPLAY_ID_0;

  ret = gdl_set_display_info (&di);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_set_display_info failed! ret: %d", ret);
    goto beach;
  }
  /* Read back and print the new hardware state */
  ret = gdl_get_display_info (di.id, &di);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_get_display_info failed! ret: %d", ret);
    goto beach;
  }

  GST_DEBUG_OBJECT (sink, "Configured Disp_id: %d  %dx%d %d %d",
      di.id, di.tvmode.width, di.tvmode.height, di.tvmode.refresh,
      di.tvmode.interlaced);

  sink->tv_width = di.tvmode.width;
  sink->tv_height = di.tvmode.height;

beach:
  return ret;
}

static inline gboolean
update_dest_rect (ISmdGstVidsink * sink, gboolean sync)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  guint x = 0, y = 0, w = 0, h = 0;
  ismd_result_t result = ISMD_SUCCESS;

  x = gst_value_get_rectangle_x (&sink->rectangle);
  y = gst_value_get_rectangle_y (&sink->rectangle);
  w = gst_value_get_rectangle_width (&sink->rectangle);
  h = gst_value_get_rectangle_height (&sink->rectangle);

  /* 0,0,0,0 value means full screen */
  if (!w || w > sink->tv_width || !h || h > sink->tv_height) {
    w = sink->tv_width;
    h = sink->tv_height;
  }

  if (x + w > sink->tv_width)
    x = sink->tv_width - w;

  if (y + h > sink->tv_height)
    y = sink->tv_height - h;

  sink->dest_rect.x = x;
  sink->dest_rect.y = y;
  sink->dest_rect.width = w;
  sink->dest_rect.height = h;

  if (sync) {
    ismd_event_t vsync_event;
    result = ismd_vidrend_get_vsync_event (smd_element->dev_handle,
        ISMD_VIDREND_VSYNC_TYPE_FRAME, &vsync_event);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (sink, "ismd_vidrend_get_vsync_event(%d)",
          result);
    }

    do {
      result = ismd_event_wait(vsync_event,ISMD_TIMEOUT_NONE);
    } while ( result == ISMD_ERROR_NOT_DONE );
    ismd_event_acknowledge(vsync_event);
  }

  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (sink, "ismd_vidrend_get_vsync_event(%d)",
        result);
  }
  else {
    ismd_cropping_window_t portion_to_display = {0,0,0,0};

    GST_DEBUG_OBJECT (sink, "Setting destination rectangle %d,%d,%d,%d",
        x, y, w, h);

    /* The pixel aspect ratio is carried in the ismd buffer */
    memset (&sink->scale_params, 0, sizeof (ismd_vidsink_scale_params_t));
    sink->scale_params.crop_window = portion_to_display;
    sink->scale_params.crop_enable = false;
    sink->scale_params.dest_window = sink->dest_rect;
    sink->scale_params.aspect_ratio.numerator = sink->aspect_x;
    sink->scale_params.aspect_ratio.denominator = sink->aspect_y;
    sink->scale_params.scaling_policy = sink->scale_mode;
    result = ismd_vidsink_set_global_scaling_params (smd_element->dev_handle,
            sink->scale_params);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_vidsink_set_global_scaling_params failed");
    }
  }

  return (result == ISMD_SUCCESS);
}


static inline gdl_ret_t
config_plane (ISmdGstVidsink * sink, gdl_plane_id_t video_plane)
{
  gdl_ret_t ret;
  gdl_rectangle_t dest_rect;
  gdl_display_info_t di;

  guint x = 0, y = 0, w = 0, h = 0;

  ret = GDL_SUCCESS;

  GST_DEBUG_OBJECT (sink, "doing config_plane");
  memset (&dest_rect, 0, sizeof (dest_rect));
  memset (&di, 0, sizeof (di));

  /* Reset GDL video plane */
  ret = gdl_plane_reset (video_plane);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_plane_reset failed! ret: %d", ret);
    goto exit;
  }

  /* Begin GDL plane config */
  ret = gdl_plane_config_begin (video_plane);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_plane_config_begin failed! ret: %d", ret);
    goto exit;
  }

  /* Set GDL video plane dest rectangle attributes */
  ret = gdl_plane_get_attr (video_plane, GDL_PLANE_DST_RECT, &dest_rect);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "gdl_plane_get_attr (GDL_PLANE_DST_RECT) failed! ret: %d", ret);
    goto exit;
  }

  GST_OBJECT_LOCK (sink);
  x = gst_value_get_rectangle_x (&sink->rectangle);
  y = gst_value_get_rectangle_y (&sink->rectangle);
  w = gst_value_get_rectangle_width (&sink->rectangle);
  h = gst_value_get_rectangle_height (&sink->rectangle);
  GST_OBJECT_UNLOCK (sink);

  /* 0,0,0,0 value means full screen */
  if (!w || w > sink->tv_width || !h || h > sink->tv_height) {
    w = sink->tv_width;
    h = sink->tv_height;
  }

  if (x + w > sink->tv_width)
    x = sink->tv_width - w;

  if (y + h > sink->tv_height)
    y = sink->tv_height - h;

  dest_rect.origin.x = x;
  dest_rect.origin.y = y;
  dest_rect.width = w;
  dest_rect.height = h;

  GST_DEBUG_OBJECT (sink, "Setting destination rectangle %d,%d,%d,%d",
      dest_rect.origin.x, dest_rect.origin.y,
      dest_rect.width, dest_rect.height);

  ret = gdl_plane_set_attr (GDL_PLANE_DST_RECT, &dest_rect);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "gdl_plane_set_attr (GDL_PLANE_DST_RECT) failed! ret: %d", ret);
    goto exit;
  }

  ret = gdl_plane_set_uint (GDL_PLANE_VID_MISMATCH_POLICY,
          GDL_VID_POLICY_RESIZE);
  if (ret != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "gdl_plane_set_uint, (GDL_PLANE_VID_MISMATCH_POLICY) failed(%d)", ret);
    goto exit;
  }

  /* TODO: Closed Captioning */
  if (GDL_PLANE_ID_UNDEFINED != sink->cc_plane) {
    /***********************************************************************
     * Yes, now set the CC attribute on both port A(0) and port B(1)
     * ignore ret error (for when and port driver is not loaded).
     ***********************************************************************/
    gdl_boolean_t attr_value = GDL_TRUE;
    gdl_port_set_attr (GDL_PD_ID_INTTVENC_COMPONENT, GDL_PD_ATTR_ID_CC,
        &attr_value);
    attr_value = GDL_TRUE;
    gdl_port_set_attr (GDL_PD_ID_INTTVENC, GDL_PD_ATTR_ID_CC, &attr_value);
    /* TODO: Is there a display destructor where we can turn the CC attribute
     * off when cl_app closes? */

    /* Now configure the source of the closed captioning */
    ret = gdl_closed_caption_source (sink->cc_plane);
    if (ret != GDL_SUCCESS) {
      GST_ERROR_OBJECT (sink, "gdl_closed_caption_source(%d) failed! ret=%d",
          sink->cc_plane, ret);
      goto exit;
    }
  }

exit:
  /* End GDL plane config */
  ret = gdl_plane_config_end (GDL_FALSE);
  if (ret != GDL_SUCCESS) {
    ret = gdl_plane_config_end (GDL_TRUE);
    GST_ERROR_OBJECT (sink, "gdl_plane_config_end failed! ret: %d", ret);
  }

  return ret;
}

static gboolean
setup_gdl (ISmdGstVidsink * sink)
{
  gboolean ret = FALSE;
  gdl_ret_t st;

  if (gdl_init (0) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_init failed");
    goto beach;
  }


  if (sink->tvmode != DEFAULT_ISMD_VIDSINK_TVMODE) {
    /* try to activate output to all ports */
    st = set_gdl_port_attribute (sink, GDL_PD_ID_INTTVENC_COMPONENT);
    if (st != GDL_SUCCESS) {
      GST_WARNING_OBJECT (sink, "set_gdl_port_attribute failed! ret: %d", ret);
    }

    st = set_gdl_port_attribute (sink, GDL_PD_ID_HDMI);
    if (st != GDL_SUCCESS) {
      GST_ERROR_OBJECT (sink, "set_gdl_port_attribute failed! ret: %d", ret);
      goto error;
    }
  }

  st = config_tvmode (sink);
  if (st != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "configure tvmode failed!");
    goto error;
  }

  st = config_plane (sink, sink->video_plane);
  if (st != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "configure plane failed!");
    goto error;
  }

  gdl_close ();
  ret = TRUE;
beach:
  return ret;

error:
  gdl_close ();
  return FALSE;
}

static GstPadLinkReturn
ismd_gst_vidsinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  GstStructure *structure;
  const gchar *name = NULL;
  gboolean ret = FALSE;
  ISmdGstVidsink *vidsink = ISMD_GST_VIDSINK (gst_pad_get_parent (pad));
  const GValue *par, *fps;
  guint32 fourcc;
  GST_DEBUG_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  structure = gst_caps_get_structure (caps, 0);
  name = gst_structure_get_name (structure);

  if (!strcmp (name, "video/x-raw-yuv") || !strcmp (name, "video/x-decoded-ismd")) {
    if (!gst_structure_get_int (structure, "width", &vidsink->width) ||
          !gst_structure_get_int (structure, "height", &vidsink->height)) {
      vidsink->width = vidsink->height = 0;      
    }
    if (gst_structure_get_fourcc (structure, "format", &fourcc)) {
      if (fourcc == GST_MAKE_FOURCC ('Y', 'V', '1', '2')) {
        vidsink->is_yv12 = TRUE;
      }
      if (fourcc == GST_MAKE_FOURCC ('I', '4', '2', '0')) {
        vidsink->is_i420 = TRUE;
      }
      if (vidsink->is_yv12 || vidsink->is_i420) {
        if (!vidsink->width || !vidsink->height) {
          GST_WARNING_OBJECT (vidsink, "missing parameters from the caps " \
              "(required width, height)");
          goto beach;
        }
      }
    }

    par = gst_structure_get_value (structure, "pixel-aspect-ratio");
    if (par) {
      vidsink->aspect_x = gst_value_get_fraction_numerator (par);
      vidsink->aspect_y = gst_value_get_fraction_denominator (par);
    }
    else {
      vidsink->aspect_x = vidsink->aspect_y = 1;
    }

    fps = gst_structure_get_value (structure, "framerate");
    if (fps) {
      vidsink->fps_n = gst_value_get_fraction_numerator (fps);
      vidsink->fps_d = gst_value_get_fraction_denominator (fps);
    }
    else {
      vidsink->fps_n = 30;
      vidsink->fps_d = 1;
    }

    GST_OBJECT_LOCK (vidsink);
    update_dest_rect (vidsink, FALSE);
    GST_OBJECT_UNLOCK (vidsink);

    ret = TRUE;
  }

beach:
  gst_object_unref (vidsink);
  return ret;
}

static GstFlowReturn
vidsink_alloc_nv12 (ISmdGstVidsink * vidsink, ISmdGstBuffer **ismd_gst_buf,
    gint width, gint height, gint par_x, gint par_y)
{
  GstFlowReturn ret = GST_FLOW_OK;
  ismd_buffer_handle_t hbuf;
  ismd_buffer_descriptor_t desc;
  ismd_frame_attributes_t *attr;
  ismd_result_t result;
  void *data_ptr;
  gint height_to_alloc;

  /* Allocate a physically-contiguous frame buffer.
   * After reserving the physical memory through the SMD core, we need to init
   * the descriptor to contain the image attributes. */
  height_to_alloc = (height * 3) / 2;

  result = ismd_frame_buffer_alloc (ROUND_UP (width, CACHE_LINE_SIZE),
      height_to_alloc, &hbuf);
  if (result != ISMD_SUCCESS)
    goto allocation_failed;

  ismd_buffer_read_desc (hbuf, &desc);
  // Now fill in the zillion of frame attribute fields
  attr = (ismd_frame_attributes_t *) desc.attributes;
  attr->discontinuity = FALSE;
  attr->cont_rate = 0;
  if (par_y) {
    attr->cont_ratio.numerator = par_x;
    attr->cont_ratio.denominator = par_y;
  } else {
    attr->cont_ratio.numerator = 0;
    attr->cont_ratio.denominator = 0;
  }
  attr->cont_size.width = width;
  attr->cont_size.height = height;
  attr->dest_size.width = width;
  attr->dest_size.height = height;
  attr->pixel_format = ISMD_PF_NV12;
  attr->color_space = ISMD_SRC_COLOR_SPACE_BT709;       // used
  attr->polarity = ISMD_POLARITY_FRAME; // FIXME: can we tell if it's interlaced?
  attr->gamma_type = ISMD_GAMMA_HDTV;   // default as per as per ISO/IEC 13818-2
  attr->repeated = 0;
  attr->y = 0;
  attr->u = attr->y + (vidsink->system_stride * height);
  // commit the changes to the descriptor
  result = ismd_buffer_update_desc (hbuf, &desc);
  if (result != ISMD_SUCCESS) {
    ismd_buffer_dereference (hbuf);
    goto description_failed;
  }
  // map buffer physical address to a virtual address
  data_ptr = OS_MAP_IO_TO_MEM_NOCACHE (desc.phys.base,
      height_to_alloc * vidsink->system_stride);
  if (data_ptr == NULL) {
    GST_ERROR_OBJECT (vidsink, "virtual mapping failure");
    ismd_buffer_dereference (hbuf);
    goto mapping_failed;
  }
  // init the buffer's data properties
  (*ismd_gst_buf)->ismd_buffer_id = hbuf;
  GST_BUFFER_SIZE (*ismd_gst_buf) = height_to_alloc * vidsink->system_stride;
  GST_BUFFER_DATA (*ismd_gst_buf) = (guint8 *) data_ptr;

beach:
  return ret;

allocation_failed:
  {
    GST_ERROR_OBJECT (vidsink, "frame buffer allocation failed");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
description_failed:
  {
    GST_ERROR_OBJECT (vidsink, "ismd update description failed");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
mapping_failed:
  {
    GST_ERROR_OBJECT (vidsink, "virtual mapping failure");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
}

static GstFlowReturn
vidsink_alloc (ISmdGstVidsink * vidsink, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf)
{
  GstFlowReturn ret = GST_FLOW_OK;
  GstCaps *intersection = NULL;
  GstStructure *structure = NULL;
  gint width = 0, height = 0, format = FORMAT_UNDEFINED;
  ISmdGstBuffer *ismd_gst_buf = NULL;
  guint32 fourcc;
  const GValue * par;
  gint par_x = 1, par_y = 1;

  if (G_LIKELY (vidsink->last_caps &&
          gst_caps_is_equal (caps, vidsink->last_caps))) {
    GST_LOG_OBJECT (vidsink,
        "buffer alloc for same last_caps, reusing caps");
    intersection = gst_caps_ref (caps);
    format = vidsink->last_format;
    width = vidsink->last_width;
    height = vidsink->last_height;
    par_x = vidsink->last_par_x;
    par_y = vidsink->last_par_x;
    goto reuse_last_caps;
  }

  GST_DEBUG_OBJECT (vidsink, "buffer alloc requested size %d with caps %"
      GST_PTR_FORMAT ", intersecting with our caps %" GST_PTR_FORMAT, size,
      caps, vidsink->caps);

  /* Check the caps against our xcontext */
  intersection = gst_caps_intersect (vidsink->caps, caps);

  /* Ensure the returned caps are fixed */
  gst_caps_truncate (intersection);

  GST_DEBUG_OBJECT (vidsink, "intersection in buffer alloc returned %"
      GST_PTR_FORMAT, intersection);

  if (gst_caps_is_empty (intersection)) {
    goto invalid_caps;
  } else if (gst_caps_is_equal (intersection, caps)) {
    /* Things work better if we return a buffer with the same caps ptr
     * as was asked for when we can */
    gst_caps_replace (&intersection, caps);
  }

  /* Get caps details*/
  structure = gst_caps_get_structure (intersection, 0);

  /* Get format from caps */
  if (gst_structure_has_name (structure, "video/x-decoded-ismd"))
    format = FORMAT_ISMD;
  else if (gst_structure_has_name (structure, "video/x-raw-yuv")) {
    format = FORMAT_RAW;

    par = gst_structure_get_value (structure, "pixel-aspect-ratio");
    if (par) {
      par_x = gst_value_get_fraction_numerator (par);
      par_y = gst_value_get_fraction_denominator (par);
    }
    else {
      par_x = par_y = 1;
    }

    if (!gst_structure_get_int (structure, "width", &width) ||
        !gst_structure_get_int (structure, "height", &height) ||
        !gst_structure_get_fourcc (structure, "format", &fourcc))
      goto invalid_caps;
  }
  /* Store our caps and format as the last_caps to avoid expensive
   * caps intersection next time */
  gst_caps_replace (&vidsink->last_caps, intersection);
  vidsink->last_format = format;
  vidsink->last_width = width;
  vidsink->last_height = height;
  vidsink->last_par_x = par_x;
  vidsink->last_par_y = par_y;

reuse_last_caps:


  if (format == FORMAT_RAW) {
    if (fourcc == GST_MAKE_FOURCC ('N', 'V', '1', '2')) {
      ismd_gst_buf = ismd_gst_buffer_new ();
      if (G_UNLIKELY (!ismd_gst_buf))
        goto allocation_failed;

      ret = vidsink_alloc_nv12 (vidsink, &ismd_gst_buf, width, height,
          par_x, par_y);
    }
  }
  else {
    ismd_gst_buf = ismd_gst_buffer_new ();
    if (G_UNLIKELY (!ismd_gst_buf))
      goto allocation_failed;
    /* For empty ISMD buffers just set the buffer size */
    GST_BUFFER_SIZE (ismd_gst_buf) = size;
  }

  if (ismd_gst_buf) {
    gst_buffer_set_caps (GST_BUFFER_CAST (ismd_gst_buf), intersection);
    *buf = GST_BUFFER_CAST (ismd_gst_buf);
  }
  else {
    *buf = gst_buffer_new_and_alloc (size);
    gst_buffer_set_caps (*buf, intersection);
  }

beach:
  if (intersection) {
    gst_caps_unref (intersection);
  }

  return ret;

  /* ERRORS */
allocation_failed:
  {
    GST_ERROR_OBJECT (vidsink, "buffer allocation failed");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
invalid_caps:
  {
    GST_WARNING_OBJECT (vidsink, "invalid caps for buffer allocation %"
        GST_PTR_FORMAT, intersection);
    ret = GST_FLOW_NOT_NEGOTIATED;
    goto beach;
  }
}

#define GST_VIDEO_YV12_Y_ROWSTRIDE(width) (GST_ROUND_UP_4(width))
#define GST_VIDEO_YV12_UV_ROWSTRIDE(width) (GST_ROUND_UP_4 (GST_ROUND_UP_2 (width) / 2))

#define GST_VIDEO_YV12_Y_OFFSET(w,h) (0)
#define GST_VIDEO_YV12_U_OFFSET(w,h) (GST_VIDEO_YV12_Y_OFFSET(w,h)+(GST_VIDEO_YV12_Y_ROWSTRIDE(w)*GST_ROUND_UP_2(h)))
#define GST_VIDEO_YV12_V_OFFSET(w,h) (GST_VIDEO_YV12_U_OFFSET(w,h)+(GST_VIDEO_YV12_UV_ROWSTRIDE(w)*GST_ROUND_UP_2(h)/2))

#define GST_VIDEO_YV12_SIZE(w,h)     (GST_VIDEO_YV12_V_OFFSET(w,h)+(GST_VIDEO_YV12_V_ROWSTRIDE(w)*GST_ROUND_UP_2(h)/2))

#define CACHE_LINE_SIZE (64)
#define ROUND_UP(num, amt) ((num%amt) ? (num+amt) - (num%amt) : num)

static __inline void *
memcpy_nt (void *dest, void *src, size_t n)
{
  size_t bytes_to_move_with_prefetch;

  assert((uintptr_t)dest % CACHE_LINE_SIZE == 0);
  assert(n % CACHE_LINE_SIZE == 0);

  /* We can't prefetch the "next" cacheline when processing
   * the last cacheline, because the "next" would exceed
   * the bounds of the buffer. So, we move the first N-1
   * cache lines first, prefetching the next cache line of the
   * source for those */
  bytes_to_move_with_prefetch = n - CACHE_LINE_SIZE;
  /* *INDENT-OFF* */
#ifndef __i386__
#error This code is only for x86-32
#else
  asm(
    "movl %0, %%edi # dest base\n\t"
    "movl %1, %%esi # src base\n\t"
    "movl %2, %%ecx # bytes to move with prefetch\n\t"

    "subl $64, %%esp\n\t"
    "movdqu %%xmm0, 0(%%esp)\n\t"
    "movdqu %%xmm1, 16(%%esp)\n\t"
    "movdqu %%xmm2, 32(%%esp)\n\t"
    "movdqu %%xmm3, 48(%%esp)\n\t"

  "next:\n\t"
    "# start prefetching the next source cache line\n\t"
    "prefetchnta -64(%%esi, %%ecx, 1)\n\t"

    "# read the current cache line of the src\n\t"
    "movdqu 0(%%esi, %%ecx, 1), %%xmm0\n\t"
    "movdqu 16(%%esi, %%ecx, 1), %%xmm1\n\t"
    "movdqu 32(%%esi, %%ecx, 1), %%xmm2\n\t"
    "movdqu 48(%%esi, %%ecx, 1), %%xmm3\n\t"

    "# write it\n\t"
    "movntdq %%xmm0, 0(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm1, 16(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm2, 32(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm3, 48(%%edi, %%ecx, 1)\n\t"

    "subl $64, %%ecx\n\t"
    "jz done\n\t"

    "jmp next\n\t"

  "done:\n\t"
    "# read the last cache line of the src\n\t"
    "movdqu 0(%%esi, %%ecx, 1), %%xmm0\n\t"
    "movdqu 16(%%esi, %%ecx, 1), %%xmm1\n\t"
    "movdqu 32(%%esi, %%ecx, 1), %%xmm2\n\t"
    "movdqu 48(%%esi, %%ecx, 1), %%xmm3\n\t"

    "# write it\n\t"
    "movntdq %%xmm0, 0(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm1, 16(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm2, 32(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm3, 48(%%edi, %%ecx, 1)\n\t"

    "sfence\n\t"

    "movdqu 0(%%esp), %%xmm0\n\t"
    "movdqu 16(%%esp), %%xmm1\n\t"
    "movdqu 32(%%esp), %%xmm2\n\t"
    "movdqu 48(%%esp), %%xmm3\n\t"
    "addl $64, %%esp\n\t"

    :
    : "g"(dest),
      "g"(src),
      "g"(bytes_to_move_with_prefetch)
    : "edi", "esi", "ecx"
  );
#endif
  /* *INDENT-ON* */

  return dest;
}

static void
uv_to_nv12 (void *dest_uv,  int dest_uv_stride, void *src_u, void *src_v,
  int src_uv_stride,
  int width, /* number of u bytes per row */
  int height)
{
  int row;
  int round_bytes_to_copy;
  uintptr_t dest_row;
  uintptr_t src_u_row;
  uintptr_t src_v_row;

  assert((uintptr_t)dest_uv % 32 == 0);
  assert(dest_uv_stride % 32 == 0);
  assert(width >= 16);

  round_bytes_to_copy = (width / 16) * 16;

  dest_row = (uintptr_t)dest_uv;
  src_u_row = (uintptr_t)src_u;
  src_v_row = (uintptr_t)src_v;

  for (row = 0; row < height; row++) {
    /* *INDENT-OFF* */
#ifndef __i386__
#error This code is only for x86-32
#else
    /* process the row */
    asm (
       "movl %0, %%edi # dest_row\n\t"
       "movl %1, %%eax # src_u_row\n\t"
       "movl %2, %%esi # src_v_row\n\t"
       "movl %3, %%ecx # round bytes to copy\n\t"
       "movl %4, %%edx # total bytes to copy\n\t"
       "pushl %%ebx\n\t"
       "movl %%esi, %%ebx\n\t"
       "movl %%ecx, %%esi\n\t"

    "next_chunk:\n\t"
       /* read the next 16 U/V bytes */
       "movdqu -16(%%eax, %%ecx, 1), %%xmm1\n\t"
       "movdqu -16(%%ebx, %%ecx, 1), %%xmm2\n\t"

       /* generate the next 16 UV pairs */
       "movdqa %%xmm1, %%xmm3\n\t"
       "movdqa %%xmm2, %%xmm4\n\t"

       "punpckhbw %%xmm2, %%xmm1\n\t"
       "punpcklbw %%xmm4, %%xmm3\n\t"

       /* store the results */
       "movntdq %%xmm1, -16(%%edi, %%ecx, 2)\n\t"
       "movntdq %%xmm3, -32(%%edi, %%ecx, 2)\n\t"

       "subl $16, %%ecx\n\t"
       "jz done_with_chunks\n\t"

       "jmp next_chunk\n\t"
    "done_with_chunks:\n\t"

       "sfence\n\t"

       /* if width == chunked_bytes, we're done */
       "cmpl %%edx, %%esi\n\t"
       "je done_uv\n\t"
       /* else, we need to handle the remaining few bytes */

       /* read the last 16 U/V bytes */
       "movdqu -16(%%eax, %%edx, 1), %%xmm1\n\t"
       "movdqu -16(%%ebx, %%edx, 1), %%xmm2\n\t"

       /* generate the last 16 UV pairs */
       "movdqa %%xmm1, %%xmm3\n\t"
       "movdqa %%xmm2, %%xmm4\n\t"

       "punpckhbw %%xmm2, %%xmm1\n\t"
       "punpcklbw %%xmm4, %%xmm3\n\t"

       /* store the results */
       "movdqu %%xmm1, -16(%%edi, %%edx, 2)\n\t"
       "movdqu %%xmm3, -32(%%edi, %%edx, 2)\n\t"
       "clflush -1(%%edi, %%edx, 2)\n\t"
       "clflush -32(%%edi, %%edx, 2)\n\t"

    "done_uv:\n\t"
       "popl %%ebx\n\t"
       :
       : "g"(dest_row),
         "g"(src_u_row),
         "g"(src_v_row),
         "g"(round_bytes_to_copy),
         "g"(width)
       : "eax", "ecx", "edx", "edi", "esi"
    );
#endif
    /* *INDENT-ON* */

    dest_row += dest_uv_stride;
    src_u_row += src_uv_stride;
    src_v_row += src_uv_stride;
  }
}

static GstBuffer *
vidsink_yv12_to_nv12 (ISmdGstVidsink * vidsink, GstBuffer * in_buffer)
{
  ISmdGstBuffer *ismd_gst_buf;
  GstBuffer * out_buffer = NULL;
  GstFlowReturn ret = GST_FLOW_OK;
  guint8 *data = GST_BUFFER_DATA(in_buffer);
  gint width = vidsink->width;
  gint height = vidsink->height;
  gint system_stride = vidsink->system_stride;
  gint y_stride = GST_VIDEO_YV12_Y_ROWSTRIDE (width);
  gint uv_stride = GST_VIDEO_YV12_UV_ROWSTRIDE (width);
  guint8 *out_data_y, *out_data_uv;
  gint line;

  ismd_gst_buf = ismd_gst_buffer_new ();
  if (G_UNLIKELY (!ismd_gst_buf))
    goto beach;

  ret = vidsink_alloc_nv12 (vidsink, &ismd_gst_buf, width, height,
      vidsink->aspect_x, vidsink->aspect_y);
  if (ret != GST_FLOW_OK)
    goto beach;

  out_buffer = GST_BUFFER_CAST (ismd_gst_buf);

  GST_BUFFER_TIMESTAMP (out_buffer) = GST_BUFFER_TIMESTAMP (in_buffer);
  GST_BUFFER_DURATION (out_buffer) = GST_BUFFER_DURATION (in_buffer);
  GST_BUFFER_FLAGS (out_buffer) = GST_BUFFER_FLAGS (in_buffer);
  out_data_y = GST_BUFFER_DATA(out_buffer);
  out_data_uv = out_data_y + (height * system_stride);

  /* copy Y data */
  for (line = 0; line < height; line++) {
    /* Potentially copying some extra bytes (up to 63), this is OK because
     * SRC buffer has U and V  after Y, so we won't overrun it
     * DEST buffer locally allocated to have a width of system stride */
    memcpy_nt (out_data_y + (line*system_stride), data + (line*y_stride),
        ROUND_UP (y_stride, CACHE_LINE_SIZE));
  }

  /* This assumes data in buffer is packed YV12 (stride == width) */
  if (vidsink->is_i420) {
    uv_to_nv12 (out_data_uv, system_stride,
        data + GST_VIDEO_YV12_U_OFFSET(width, height),
        data + GST_VIDEO_YV12_V_OFFSET(width, height),
        uv_stride, uv_stride, height/2);
  } else {
    uv_to_nv12 (out_data_uv, system_stride,
        data + GST_VIDEO_YV12_V_OFFSET(width, height),
        data + GST_VIDEO_YV12_U_OFFSET(width, height),
        uv_stride, uv_stride, height/2);
  }


beach:
  gst_buffer_unref (in_buffer);
  return out_buffer;
}

static GstFlowReturn
ismd_gst_vidsink_alloc (GstPad * pad, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf)
{
  GstFlowReturn ret = GST_FLOW_OK;
  ISmdGstVidsink *vidsink;

  vidsink = ISMD_GST_VIDSINK (gst_pad_get_parent_element (pad));

  ret = vidsink_alloc (vidsink, offset, size, caps, buf);

  gst_object_unref (vidsink);

  return ret;
}

static void
ismd_gst_vidsink_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (object);

  switch (prop_id) {
    case PROP_VIDSINK_SCALE_MODE:
      g_value_set_enum (value, sink->scale_mode);
      break;
    case PROP_VIDSINK_RECTANGLE:
      g_value_transform (&sink->rectangle, value);
      break;
    case PROP_VIDSINK_PAN_AND_SCAN:
      g_value_set_boolean (value, sink->pan_and_scan_enabled);
      break;
    case PROP_VIDSINK_TVMODE:
      g_value_set_enum (value, sink->tvmode);
      break;
    case PROP_VIDSINK_BG_COLOR:
      g_value_set_uint (value, sink->bg_color);
      break;
    case PROP_VIDSINK_GDL_PLANE:
      g_value_set_enum (value, sink->video_plane);
      break;
    case PROP_VIDSINK_QOS:
      g_value_set_boolean (value, sink->qos_enabled);
      break;
    case PROP_VIDSINK_FLUSH_REPEAT_FRAME:
      g_value_set_boolean (value, sink->flush_repeat_frame);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_vidsink_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstElement *smde = ISMD_GST_ELEMENT (object);
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (object);

  GST_OBJECT_LOCK (sink);
  switch (prop_id) {
    case PROP_VIDSINK_SCALE_MODE:
    {
      sink->scale_mode = g_value_get_enum (value);
      if (sink->setup) {
        ismd_result_t res;
        ismd_cropping_window_t portion_to_display = {0,0,0,0};
        memset (&sink->scale_params, 0, sizeof (ismd_vidsink_scale_params_t));
        sink->scale_params.crop_window = portion_to_display;
        sink->scale_params.crop_enable = false;
        sink->scale_params.dest_window = sink->dest_rect;
        sink->scale_params.aspect_ratio.numerator = sink->aspect_x;
        sink->scale_params.aspect_ratio.denominator = sink->aspect_y;
        sink->scale_params.scaling_policy = sink->scale_mode;
        res = ismd_vidsink_set_global_scaling_params (smde->dev_handle,
                sink->scale_params);
        if (G_UNLIKELY (res != ISMD_SUCCESS)) {
          GST_WARNING_OBJECT (sink, "set_scaling_policy failed");
        }
      }
      break;
    }
    case PROP_VIDSINK_RECTANGLE:
    {
      if (!g_value_transform (value, &sink->rectangle)) {
        g_warning ("Could not transform string to rectangle");
        gst_value_set_rectangle (&sink->rectangle, 0, 0, 0, 0);
      }
      GST_DEBUG_OBJECT (sink, "set destination rectangle to %d,%d,%d,%d",
          gst_value_get_rectangle_x (&sink->rectangle),
          gst_value_get_rectangle_y (&sink->rectangle),
          gst_value_get_rectangle_width (&sink->rectangle),
          gst_value_get_rectangle_height (&sink->rectangle));
      if (sink->setup)
        update_dest_rect (sink, FALSE);
      break;
    }
    case PROP_VIDSINK_PAN_AND_SCAN:
    {
      sink->pan_and_scan_enabled = g_value_get_boolean (value);
      if (sink->setup) {
        ismd_result_t res;
        res = sink->pan_and_scan_enabled ?
            ismd_vidpproc_pan_scan_enable (sink->vidpproc_handle) :
            ismd_vidpproc_pan_scan_disable (sink->vidpproc_handle);
        if (G_UNLIKELY (res != ISMD_SUCCESS)) {
          GST_WARNING_OBJECT (sink, "pan_scan_enable/disable failed");
        }
      }
      break;
    }
    case PROP_VIDSINK_TVMODE:
      sink->tvmode = g_value_get_enum (value);
      break;
    case PROP_VIDSINK_BG_COLOR:
      sink->bg_color = g_value_get_uint (value);
      break;
    case PROP_VIDSINK_GDL_PLANE:
      sink->video_plane = g_value_get_enum (value);
      break;
    case PROP_VIDSINK_QOS:
      sink->qos_enabled = g_value_get_boolean (value);
      break;
    case PROP_VIDSINK_FLUSH_REPEAT_FRAME:
      {
        gboolean flush_repeat_frame = g_value_get_boolean (value);
        //ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
        ismd_result_t result;
        sink->flush_repeat_frame = flush_repeat_frame;
        result = ismd_vidsink_set_flush_policy (smde->dev_handle,
            flush_repeat_frame ? ISMD_VIDREND_FLUSH_POLICY_REPEAT_FRAME :
            ISMD_VIDREND_FLUSH_POLICY_DISPLAY_BLACK);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (sink, "ismd_vidsink_set_flush_policy failed(%d)",
            result);
        }
      }
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
  GST_OBJECT_UNLOCK (sink);
}


static inline gboolean
ismd_close (ISmdGstElement *smd_element)
{
  ismd_result_t result = ISMD_SUCCESS;
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (smd_element);

  if (sink->out_event != ISMD_EVENT_HANDLE_INVALID) {
    ismd_event_free (sink->out_event);
  }

  if (sink->out_port != ISMD_PORT_HANDLE_INVALID) {
    result = ismd_port_detach (sink->out_port);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_port_detach failed(%d)", result);
    }
    result =  ismd_vidrend_disable_port_output (sink->vidrend_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_vidrend_disable_port_output failed(%d)",
          result);
    }
    sink->out_port = ISMD_PORT_HANDLE_INVALID;
  }

  if (sink->vidpproc_handle != ISMD_DEV_HANDLE_INVALID) {
     result = ismd_dev_close (sink->vidpproc_handle);
     if (result != ISMD_SUCCESS) {
       GST_ERROR_OBJECT (sink, "vidpproc close failed(%d)", result);
     }
     sink->vidpproc_handle = ISMD_DEV_HANDLE_INVALID;
  }

  if (sink->vidrend_handle != ISMD_DEV_HANDLE_INVALID) {
     result = ismd_dev_close (sink->vidrend_handle);
     if (result != ISMD_SUCCESS) {
       GST_ERROR_OBJECT (sink, "vidrend close failed(%d)", result);
     }
     sink->vidrend_handle = ISMD_DEV_HANDLE_INVALID;
  }

  return TRUE;
}

/**
 * ismd_open
 * Open the video renderer and get the port
 * @element - element containing videosink
 * returns TRUE if setup is successful
 */
static inline gboolean
ismd_open (ISmdGstElement *smd_element)
{
  ismd_result_t result = ISMD_SUCCESS;
  ismd_port_handle_t port = ISMD_PORT_HANDLE_INVALID;
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (smd_element);

  GST_DEBUG_OBJECT (sink, "ismd_open()");
  if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
    GST_DEBUG_OBJECT (sink,
        "vidsink: vidsink is already open. Cannot open again.");
    if (ISMD_DEV_HANDLE_INVALID == (smd_element->sink_pad)->ismd_port) {
      result = ismd_vidsink_get_input_port (smd_element->dev_handle, &port);
      if (result != ISMD_SUCCESS) {
        return FALSE;
      }
      (smd_element->sink_pad)->ismd_port = port;
    }
    return TRUE;
  }

  /* Open and Grab a vidrend handle */
  result = ismd_vidrend_open (&sink->vidrend_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "vidsink: Unable to open video renderer. ERROR = %d", result);
    goto error;
  }
  GST_DEBUG_OBJECT (sink, "ismd_gst_vidrend_open(%d) OK", smd_element->dev_handle);

  /* Open and Grab a vidpproc handle */
  result = ismd_vidpproc_open (&sink->vidpproc_handle);
  if (result != ISMD_SUCCESS) {
     GST_ERROR_OBJECT (sink,
         "vidsink: Unable to open video postprocessor. ERROR = %d", result);
    goto error;
  }

  /* Open and Grab a vidsink handle */
  result = ismd_vidsink_open (&smd_element->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "vidsink: Unable to open vidsink. ERROR = %d", result);
    goto error;
  }

  GST_DEBUG_OBJECT (sink, "ismd_gst_vidsink_open(%d) OK", smd_element->dev_handle);

  /* Get smd handles */
  result = ismd_vidsink_set_smd_handles(smd_element->dev_handle, 
        sink->vidpproc_handle, sink->vidrend_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_vidsink_set_smd_handles failed(%d)",
        result);
    goto error;
  }
  GST_DEBUG_OBJECT (sink, "vidsink device(%d) got smd handles: vidpproc(%d) vidrend(%d)",
      smd_element->dev_handle, sink->vidpproc_handle, sink->vidrend_handle);

  /* Get the vidsink input port and set it in the pad */
  result = ismd_vidsink_get_input_port (smd_element->dev_handle, &port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_vidsink_get_input_port failed(%d)",
        result);
    goto error;
  }
  (smd_element->sink_pad)->ismd_port = port;

  GST_DEBUG_OBJECT (sink, "vidrend device(%d) has input port %d",
      smd_element->dev_handle, (smd_element->sink_pad)->ismd_port);

  /* Set up EOS handling */
  result = ismd_vidrend_enable_port_output (sink->vidrend_handle, 0, 1,
      &sink->out_port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_vidrend_enable_port_output failed(%d)",
        result);
  }
  else {
    result = ismd_event_alloc (&sink->out_event);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "ismd_event_alloc failed(%d)", result);
    }

    result = ismd_port_attach (sink->out_port, sink->out_event,
        ISMD_QUEUE_EVENT_ALWAYS, ISMD_QUEUE_WATERMARK_NONE);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "ismd_port_attach failed(%d)", result);
    }
  }

  result = ismd_vidrend_get_eos_event (sink->vidrend_handle,
      &sink->eos_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_vidrend_get_eos_event failed(%d)",
        result);
  }

  return TRUE;
error:
  ismd_close(smd_element);
  return FALSE;
}

static inline gboolean
ismd_get_tvmode_size (ISmdGstVidsink * vidsink)
{
  gboolean ret = FALSE;
  gdl_display_info_t di;
  memset (&di, 0, sizeof (di));

  if (gdl_init (0) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (vidsink, "gdl_init failed");
    goto beach;
  }

  /* Read current hardware state */
  if (gdl_get_display_info (GDL_DISPLAY_ID_0, &di) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (vidsink, "gdl_get_display_info failed");
    goto error;
  }

  GST_DEBUG_OBJECT (vidsink, "got width %d and height %d from display",
    di.tvmode.width, di.tvmode.height);
  vidsink->tv_width = di.tvmode.width;
  vidsink->tv_height = di.tvmode.height;
  vidsink->interlaced = (di.tvmode.interlaced == GDL_TRUE);

  ret = TRUE;
  gdl_close ();

beach:
  return ret;
error:
  gdl_close ();
  return FALSE;
}

static gboolean
ismd_gst_vidsink_peer_query (ISmdGstElement * smd_element,
    GstQuery * query)
{
  GstPad *peer;
  gboolean res = FALSE;

  GST_DEBUG_OBJECT (smd_element, "forward upstream query type %s",
      GST_QUERY_TYPE_NAME (query));

  if ((peer = gst_pad_get_peer (GST_PAD (smd_element->sink_pad)))) {
    GST_DEBUG_OBJECT (peer, "forward upstream query type %s",
        GST_QUERY_TYPE_NAME (query));

    res = gst_pad_query (peer, query);
    gst_object_unref (peer);
  }
  return res;
}

static gboolean
ismd_gst_vidsink_query (GstElement * element, GstQuery * query)
{
  gboolean ret;
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (element);
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);

  GST_DEBUG_OBJECT (sink, "handling query type %s",
      GST_QUERY_TYPE_NAME (query));

  switch (GST_QUERY_TYPE (query)) {
    case GST_QUERY_POSITION:
    {
      gint64 position;
      GstFormat format;
      ismd_vidrend_stream_position_info_t smd_position;
      ismd_result_t result;
      gst_query_parse_position (query, &format, &position);

      if (format != GST_FORMAT_TIME) {
        ret = ismd_gst_vidsink_peer_query (smd_element, query);
        break;
      }

      /* get position */
      result = ismd_vidrend_get_stream_position (sink->vidrend_handle,
          &smd_position);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (sink, "ismd_vidrend_get_stream_position failed(%d)",
            result);
        smd_position.last_segment_pts = ISMD_NO_PTS;
      }

      if (smd_position.linear_time == ISMD_NO_PTS) {
        position = gst_segment_to_stream_time (&smd_element->segment, format,
            smd_element->segment.last_stop);
      } else {
        /* The position query is used primarily to set the new stream time (i.e.
         * gst_pipeline_set_new_stream_time()) and needs to be compatible with
         * Gstreamer's concept of stream time.  The SMD segment_time is the absolute
         * PTS value of the current frame being displayed and will not work.  GST
         * stream time is always from 0 - duration of clip.  The SMD linear_time
         * fits the bill.  Linear_time is different from scaled_time in that it
         * accounts for the playback rate (e.g. 2x rate will accumulate a larger
         * value than scaled_time as "more" content is played in the same amount
         * of time. */
        position = SMD_TO_GST_TIME (smd_position.linear_time);
        position += smd_element->segment.time;
        GST_DEBUG_OBJECT (sink, "vidrend.base_time: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.base_time)));
        GST_DEBUG_OBJECT (sink, "vidrend.current_time: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.current_time)));
        GST_DEBUG_OBJECT (sink, "vidrend.segment_time: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.segment_time)));
        GST_DEBUG_OBJECT (sink, "vidrend.linear_time: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.linear_time)));
        GST_DEBUG_OBJECT (sink, "vidrend.scaled_time: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.scaled_time)));
        GST_DEBUG_OBJECT (sink, "vidrend.last_seg_pts: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.last_segment_pts)));
        GST_DEBUG_OBJECT (sink, "vidrend.last_lnr_pts: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.last_linear_pts)));
        GST_DEBUG_OBJECT (sink, "element.segment.time: %" GST_TIME_FORMAT,
            GST_TIME_ARGS (smd_element->segment.time));
      }

      GST_DEBUG_OBJECT (sink, "position = %" GST_TIME_FORMAT,
          GST_TIME_ARGS(position));

      /* return stream position */
      gst_query_set_position (query, format, position);
      ret = TRUE;
      break;
    }
    default:
    {
      ret = ismd_gst_vidsink_peer_query (smd_element, query);
      break;
    }
  }

  return ret;
}

static void
ismd_gst_vidsink_prepare_gdl_plane (ISmdGstVidsink *sink)
{
  GstStructure *s;
  GstMessage *msg;

  GST_LOG_OBJECT (sink, "prepare gdl plane");
  s = gst_structure_new ("prepare-gdl-plane", NULL);
  msg = gst_message_new_element (GST_OBJECT (sink), s);
  gst_element_post_message (GST_ELEMENT (sink), msg);
}

static GstStateChangeReturn
ismd_gst_vidsink_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstVidsink *sink = ISMD_GST_VIDSINK (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ismd_vidpproc_deinterlace_policy_t deinterlacing_policy = NONE;

  GST_DEBUG_OBJECT (sink, "change state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));

  ret = GST_STATE_CHANGE_SUCCESS;
  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
    {
      /* This should try to open the HW device connection, and allocate
       * the hw resources. */
      if (ismd_open (smd_element) != TRUE) {
        GST_ERROR_OBJECT (sink, "video renderer(%d): ismd_open failed",
            smd_element->dev_handle);
        goto failure;
      }

      /* Try to get tvmode size */
      if (!ismd_get_tvmode_size (sink)) {
        GST_ERROR_OBJECT (sink, "couldn't get the screen size");
        goto failure;
      }

      /* Setup the sink settings */
      if (sink->interlaced) {
        deinterlacing_policy = NONE;
      } else {
        deinterlacing_policy = AUTO;
      }
      if (ISMD_SUCCESS !=
          ismd_vidpproc_set_deinterlace_policy (sink->vidpproc_handle, deinterlacing_policy)) {
        GST_ERROR_OBJECT (sink, "ismd_vidsink_set_deinterlace_policy");
        goto failure;
      }
      GST_OBJECT_LOCK (sink);
      if (update_dest_rect (sink, FALSE) == FALSE) {
        goto failure;
      }
      GST_OBJECT_UNLOCK (sink);

      if (ISMD_SUCCESS != (sink->pan_and_scan_enabled ?
          ismd_vidpproc_pan_scan_enable (sink->vidpproc_handle) :
          ismd_vidpproc_pan_scan_disable (sink->vidpproc_handle))) {
        GST_ERROR_OBJECT (sink, "ismd_vidsink_pan_scan_enable/disable failed");
        goto failure;
      }

      {
         ismd_cropping_window_t portion_to_display = {0,0,0,0};
         memset (&sink->scale_params, 0, sizeof (ismd_vidsink_scale_params_t));
         sink->scale_params.crop_window = portion_to_display;
         sink->scale_params.crop_enable = false;
         sink->scale_params.dest_window = sink->dest_rect;
         sink->scale_params.aspect_ratio.numerator = sink->aspect_x;
         sink->scale_params.aspect_ratio.denominator = sink->aspect_y;
         sink->scale_params.scaling_policy = sink->scale_mode;
         if (ISMD_SUCCESS != ismd_vidsink_set_global_scaling_params (smd_element->dev_handle,
                 sink->scale_params)) {
           GST_ERROR_OBJECT (sink, "ismd_vidsink_set_global_scaling_params failed");
           goto failure;
         }
      }
      sink->caps = gst_caps_copy (
          gst_pad_get_pad_template_caps (ISMD_ELEMENT_SINK_PAD(smd_element)));

      sink->system_stride = SYSTEM_STRIDE;
      break;
    }
    case GST_STATE_CHANGE_READY_TO_PAUSED:
    {
      ismd_result_t result;
      sink->eos_posted = FALSE;
      ismd_vidsink_flush_policy_t policy;

      if (sink->flush_repeat_frame) {
        policy = ISMD_VIDSINK_FLUSH_POLICY_REPEAT_FRAME;
        GST_DEBUG_OBJECT (sink, "configuring flush policy to repeat frame");
      }
      else {
        policy = ISMD_VIDSINK_FLUSH_POLICY_DISPLAY_BLACK;
        GST_DEBUG_OBJECT (sink, "configuring flush policy to display black");
      }
      result = ismd_vidsink_set_flush_policy (smd_element->dev_handle, policy);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_vidsink_set_flush_policy failed(%d)",
            result);
      }
      GST_DEBUG_OBJECT (sink, "configuring stop policy to display black");
      result = ismd_vidrend_set_stop_policy (sink->vidrend_handle,
          ISMD_VIDREND_STOP_POLICY_DISPLAY_BLACK);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_vidrend_set_stop_policy failed(%d)",
            result);
      }
      /* Post a message to let the application configure the GDL plane */
      ismd_gst_vidsink_prepare_gdl_plane (sink);
      /* Setup GDL and connect the plane with the ismd_vidrend */
      if ((sink->setup = setup_gdl (sink))) {
          GST_DEBUG_OBJECT (sink, "try ismd_vidrend_set_video_plane");
          if (ISMD_SUCCESS != ismd_vidrend_set_video_plane (sink->vidrend_handle,
                      sink->video_plane)) {
              GST_ERROR_OBJECT (sink, "ismd_vidrend_set_video_plane failed");
              goto failure;
          }
          GST_OBJECT_LOCK (sink);
          update_dest_rect (sink, FALSE);
          GST_OBJECT_UNLOCK (sink);
      } else {
        GST_ERROR_OBJECT (sink, "setup_gdl failed");
        goto failure;
      }
      sink->has_newsegment = FALSE;
      sink->first_advance_to_pts = TRUE;
      sink->need_flush = FALSE;
      ismd_gst_vidsink_reset_qos (sink);
      break;
    }

    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
    {
      if (sink->monitor_loop == NULL) {
        sink->monitor_stop = FALSE;
        sink->monitor_loop = gst_task_create (
            (GstTaskFunction) ismd_gst_vidsink_loop, sink);
        gst_task_set_lock (sink->monitor_loop, sink->monitor_mutex);
        gst_task_start (sink->monitor_loop);
        GST_DEBUG_OBJECT (sink, "monitoring task started");
      }
      break;
    }
    case GST_STATE_CHANGE_PAUSED_TO_READY:
    {
      ismd_result_t result;
      if (sink->monitor_loop != NULL) {
        sink->monitor_stop = TRUE;
        /* Do not post the EOS message when we just close the element */
        sink->eos_posted = TRUE;
        gst_task_stop (sink->monitor_loop);
        result = ismd_event_strobe (sink->eos_event);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (sink, "ismd_event_strobe failed(%d)", result);
        }
        gst_task_join (sink->monitor_loop);
        gst_object_unref (sink->monitor_loop);
        sink->monitor_loop = NULL;
        sink->eos_posted = TRUE;
        sink->setup = FALSE;
        GST_DEBUG_OBJECT (sink, "monitoring task stopped");
      }
      break;
    }
    case GST_STATE_CHANGE_READY_TO_NULL:
    {
      ismd_close (smd_element);
      break;
    }
    default:
      break;
  }

  /* Chain up to the parent class's state change function
   * Must do this before downward transitions are handled to safely handle
   * concurrent access by multiple threads */
  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    GST_ERROR_OBJECT (sink, "video renderer: change state failure");
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PAUSED_TO_READY:
      sink->width = sink->height = 0;
      sink->is_yv12 = FALSE;
      sink->is_i420 = FALSE;
      break;

    case GST_STATE_CHANGE_READY_TO_NULL:
      if (sink->last_caps)
        gst_caps_replace (&sink->last_caps, NULL);
      if (sink->caps)
        gst_caps_unref (sink->caps);
      break;

    default:
      break;
  }

  GST_DEBUG_OBJECT (sink, "changed state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));

  return ret;

failure:
  GST_DEBUG_OBJECT (sink, "failed change state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));
  ret = GST_STATE_CHANGE_FAILURE;
  return ret;
}

static void
ismd_gst_vidsink_dispose (GObject * object)
{
  ISmdGstVidsink *sink;

  sink = ISMD_GST_VIDSINK (object);
  if (sink->provided_clock)
    gst_object_unref (sink->provided_clock);
  sink->provided_clock = NULL;
  G_OBJECT_CLASS (parent_class)->dispose (object);
}

static void
ismd_gst_vidsink_finalize (GObject * object)
{
  ISmdGstVidsink *sink;

  sink = ISMD_GST_VIDSINK (object);
  g_value_unset (&sink->rectangle);
  g_static_rec_mutex_free (sink->monitor_mutex);
  g_free (sink->monitor_mutex);
  sink->monitor_mutex = NULL;
  sink->monitor_loop = NULL;

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
ismd_gst_vidsink_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_vidsink_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Hardware Video Sink",
      "Sink/Video",
      "GStreamer VideoSink Element for Intel's Media Processors",
      "http://www.intelconsumerelectronics.com/");

  GstElementClass *gstelement_class = GST_ELEMENT_CLASS (g_class);

  GstPadTemplate *curr_tmplt = NULL;

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_vidsink_sinkpad_template);
  gst_element_class_add_pad_template (gstelement_class, curr_tmplt);
  gst_object_unref (curr_tmplt);

  gst_element_class_set_details (gstelement_class,
      &ismd_gst_vidsink_details);
}

static void
ismd_gst_vidsink_class_init (ISmdGstVidsinkClass * klass)
{
  ISmdGstElementClass *iclass = ISMD_GST_ELEMENT_CLASS (klass);
  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GObjectClass *oclass = G_OBJECT_CLASS (klass);

  oclass->get_property = ismd_gst_vidsink_get_property;
  oclass->set_property = ismd_gst_vidsink_set_property;

  g_object_class_install_property (oclass, PROP_VIDSINK_SCALE_MODE,
      g_param_spec_enum ("scale-mode",
          "Scale mode",
          "Define the mode used by the video scaler",
          GST_TYPE_ISMD_VIDPPROC_SCALE_MODE,
          DEFAULT_ISMD_VIDSINK_SCALE_MODE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDSINK_RECTANGLE,
      g_param_spec_string ("rectangle", "Destination rectangle",
          "The destination rectangle, (0,0,0,0) full screen",
          DEFAULT_ISMD_VIDSINK_RECTANGLE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_VIDSINK_PAN_AND_SCAN,
      g_param_spec_boolean ("pan-and-scan",
          "Pan and Scan",
          "Enable usage of Pan and Scan information if present in the stream",
          DEFAULT_ISMD_VIDSINK_PAN_AND_SCAN, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDSINK_TVMODE,
      g_param_spec_enum ("tvmode",
          "Television mode",
          "Define the television mode",
          GST_TYPE_ISMD_VIDEO_SINK_TVMODE,
          DEFAULT_ISMD_VIDSINK_TVMODE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDSINK_BG_COLOR,
      g_param_spec_uint ("bgcolor",
          "Background color",
          "Defines the canvas color used by the gdl plane",
          0, 0xffffffff, DEFAULT_ISMD_VIDSINK_BG_COLOR, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDSINK_GDL_PLANE,
      g_param_spec_enum ("gdl-plane",
          "UPP used for rendering",
          "Define the Universal Pixel Plane used in the GDL layer",
          GST_TYPE_ISMD_VIDEO_SINK_GDL_PLANE,
          DEFAULT_ISMD_VIDSINK_GDL_PLANE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDSINK_QOS,
      g_param_spec_boolean ("qos", "Qos",
          "Generate Quality-of-Service events upstream",
          DEFAULT_ISMD_VIDSINK_QOS,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_VIDSINK_FLUSH_REPEAT_FRAME,
      g_param_spec_boolean ("flush-repeat-frame", "Flushing Repeat Frame",
          "Keep displaying the last frame rather than a black one whilst flushing",
          DEFAULT_ISMD_VIDSINK_FLUSH_REPEAT_FRAME,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_change_state);
  eclass->query = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_query);
  eclass->provide_clock =
      GST_DEBUG_FUNCPTR (ismd_gst_vidsink_provide_clock);
  iclass->prerolled = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_prerolled);
  iclass->convert = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_convert);
  iclass->drain = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_drain);
  iclass->track_qos = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_track_qos);
  iclass->event = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_event);
  iclass->is_sink = TRUE;

  oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_dispose);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_vidsink_finalize);

  iclass->dev_ops.close = ismd_vidsink_close;
  iclass->dev_ops.flush = ismd_vidsink_flush;
  iclass->dev_ops.set_state = ismd_vidsink_set_state;
  iclass->dev_ops.set_clock = ismd_vidsink_set_clock;
  iclass->dev_ops.set_base_time = ismd_vidsink_set_base_time;
  iclass->dev_ops.set_play_rate = ismd_vidsink_set_play_rate;
  iclass->dev_ops.set_underrun_event = NULL;
  iclass->dev_ops.get_underrun_amount = NULL;
  iclass->dev_ops.get_state = NULL;
  iclass->dev_ops.get_base_time = NULL;
  iclass->dev_ops.get_play_rate = NULL;
  iclass->dev_ops.set_slave_clock = NULL;


  ismd_gst_element_requires_clock (eclass);
}

static void
ismd_gst_vidsink_init (ISmdGstVidsink * sink,
    ISmdGstVidsinkClass * g_class)
{
  /* Create Sink Pad */
  GstPad *pad;
  ISmdGstElement *element = ISMD_GST_ELEMENT (sink);

  GstPadTemplate *curr_tmplt = NULL;

  GST_DEBUG_OBJECT (sink, "ismd_gst_vidsink_init()");
  curr_tmplt = gst_static_pad_template_get (&ismd_gst_vidsink_sinkpad_template);
  element->sink_pad = ismd_gst_pad_new_from_template (curr_tmplt, "sink");
  gst_object_unref (curr_tmplt);

  pad = GST_PAD (element->sink_pad);
  gst_element_add_pad (GST_ELEMENT (element), pad);

  /* Register sinkpad to allow the element to receive and process buffers */
  ismd_gst_element_register_sinkpad (element, element->sink_pad);
  gst_pad_set_bufferalloc_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vidsink_alloc));

  /* Set up the pad capabilities */
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vidsinkpad_setcaps));

  /* Initialize to invalid port id - to prevent buffer passing */
  (element->sink_pad)->ismd_port = ISMD_DEV_HANDLE_INVALID;

  sink->vidpproc_handle = ISMD_DEV_HANDLE_INVALID;
  sink->vidrend_handle = ISMD_DEV_HANDLE_INVALID;

  memset (&sink->scale_params, 0, sizeof (ismd_vidsink_scale_params_t));
  sink->scale_mode = DEFAULT_ISMD_VIDSINK_SCALE_MODE;
  sink->pan_and_scan_enabled = DEFAULT_ISMD_VIDSINK_PAN_AND_SCAN;
  sink->aspect_x = sink->aspect_y = 1;
  sink->setup = FALSE;
  sink->width = sink->height = 0;
  sink->interlaced = FALSE;
  sink->is_yv12 = FALSE;
  sink->is_i420 = FALSE;

  sink->tvmode = DEFAULT_ISMD_VIDSINK_TVMODE;
  sink->bg_color = DEFAULT_ISMD_VIDSINK_BG_COLOR;
  sink->gamma = GDL_GAMMA_LINEAR;        /* GDL_GAMMA_2_2 GDL_GAMMA_2_8 */
  sink->video_plane = DEFAULT_ISMD_VIDSINK_GDL_PLANE;
  sink->cc_plane = GDL_PLANE_ID_UNDEFINED;
  sink->brightness = 0;
  sink->contrast = 0;
  sink->hue = 0;
  sink->aspect_ratio = 0;
  sink->setup = FALSE;
  sink->monitor_loop = NULL;
  sink->monitor_mutex = g_new0 (GStaticRecMutex, 1);
  g_static_rec_mutex_init (sink->monitor_mutex);
  sink->eos_event = ISMD_EVENT_HANDLE_INVALID;
  sink->out_event = ISMD_EVENT_HANDLE_INVALID;
  sink->out_port = ISMD_PORT_HANDLE_INVALID;
  sink->qos_enabled = DEFAULT_ISMD_VIDSINK_QOS;
  sink->flush_repeat_frame = DEFAULT_ISMD_VIDSINK_FLUSH_REPEAT_FRAME;
  ismd_gst_vidsink_reset_qos (sink);
  g_value_init (&sink->rectangle, GST_TYPE_RECTANGLE);
  gst_value_set_rectangle (&sink->rectangle, 0, 0, 0, 0);
  memset (&sink->dest_rect, 0, sizeof (dest_rect_t));
  GST_OBJECT_FLAG_SET (GST_OBJECT (sink), GST_ELEMENT_IS_SINK);
}

