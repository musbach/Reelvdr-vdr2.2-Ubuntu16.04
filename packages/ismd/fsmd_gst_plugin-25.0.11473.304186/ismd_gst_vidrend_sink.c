/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2008. Intel Corporation. All rights reserved.
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

    Copyright (c) 2008. Intel Corporation. All rights reserved.
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
 * SECTION:element-vidrendsink
 * @short_description: generic sink for video renderer at NV16/I420
 * @see_also: #GstFakeSrc
 *
 * This sink element provides generic NV16/I420 video rendering
 */

#include <gst/interfaces/navigation.h>

#include <string.h>
#include <gst/gstmarshal.h>
#include <ismd_core.h>
#include <ismd_vidrend.h>
#include "ismd_gst_vidrend_sink.h"
#include "ismd_gst_element.h"
#include "ismd_gst_enum.h"
#include "ismd_gst_rectangle.h"

#define VIDREND_SINK_CAPS  "video/x-raw-ismd"

/* Structure definitions */
static GstStaticPadTemplate sink_template = GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (VIDREND_SINK_CAPS));

GST_DEBUG_CATEGORY_STATIC (ismd_gst_vidrend_sink_debug);
#define GST_CAT_DEFAULT ismd_gst_vidrend_sink_debug

enum
{
  PROP_VIDEO_UNKNOWN,
  PROP_VIDEO_TVMODE,
  PROP_VIDEO_BG_COLOR,
  PROP_VIDEO_GDL_PLANE,
  PROP_VIDEO_RECTANGLE,
  PROP_VIDEO_QOS,
  PROP_VIDEO_FLUSH_REPEAT_FRAME,
};

#define DEFAULT_ISMD_VIDEO_SINK_TVMODE      -1
#define DEFAULT_ISMD_VIDEO_SINK_BG_COLOR    0
#define DEFAULT_ISMD_VIDEO_SINK_GDL_PLANE   GDL_PLANE_ID_UPP_A
#define DEFAULT_ISMD_VIDEO_SINK_RECTANGLE   "0,0,0,0"
#define DEFAULT_ISMD_VIDEO_SINK_QOS         TRUE
#define DEFAULT_ISMD_VIDEO_SINK_FLUSH_REPEAT_FRAME TRUE

#define DO_RUNNING_AVG(avg,val,size) (((val) + ((size)-1) * (avg)) / (size))

/* generic running average, this has a neutral window size */
#define UPDATE_RUNNING_AVG(avg,val)   DO_RUNNING_AVG(avg,val,8)
/* the windows for these running averages are experimentally obtained.
 * possitive values get averaged more while negative values use a small
 * window so we can react faster to badness. */
#define UPDATE_RUNNING_AVG_P(avg,val) DO_RUNNING_AVG(avg,val,16)
#define UPDATE_RUNNING_AVG_N(avg,val) DO_RUNNING_AVG(avg,val,4)

static void
ismd_gst_vidrend_sink_init_interfaces (GType type);

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_vidrend_sink_debug, "ISMD_VIDREND_SINK",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstvidrendsink element");
  
  ismd_gst_vidrend_sink_init_interfaces (ismd_gst_debug_type);
}

/* Call Boilerplate to declare the base_init, class_init and init functions
 * and to define the get_type function */
GST_BOILERPLATE_FULL (ISmdGstVidrendSink, ismd_gst_vidrend_sink, ISmdGstElement,
    ISMD_GST_TYPE_ELEMENT, _do_init);


static void 
ismd_gst_vidrend_sink_navigation_send_event (GstNavigation * navigation,
                                             GstStructure * structure)
{
    ISmdGstElement *smd_element = ISMD_GST_ELEMENT (navigation);

    GstPad *peer = gst_pad_get_peer (GST_PAD (smd_element->sink_pad));
    
    if (peer) {
      GstEvent *event = gst_event_new_navigation (structure);
      
      if (GST_IS_PAD(peer) && GST_IS_EVENT(event))
        gst_pad_send_event (peer, event);
      gst_object_unref (peer);
    }
}

static void
ismd_gst_vidrend_sink_navigation_init (GstNavigationInterface * iface)
{
  iface->send_event = ismd_gst_vidrend_sink_navigation_send_event;
}

static void
ismd_gst_vidrend_sink_reset_qos (ISmdGstVidrendSink * sink)
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
ismd_gst_vidrend_sink_track_qos (ISmdGstElement * smd_element,
    gint client_id, gint t)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (smd_element);
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
ismd_gst_vidrend_sink_send_qos (ISmdGstVidrendSink * sink, gint client_id,
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
ismd_gst_vidrend_sink_convert (ISmdGstElement * smd_element, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  /* TODO: check if the buffer is late here. If is it late emit the QoS event
   * and drop the buffer */
  return buf;
}

static void
ismd_gst_vidrend_sink_prerolled (ISmdGstElement * smd_element)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (smd_element);
      
  if (!sink->first_advance_to_pts) {
    ismd_vidrend_advance_to_pts (smd_element->dev_handle, 1);
  }
  sink->first_advance_to_pts = FALSE;
}

static void
ismd_gst_vidrend_sink_drain (ISmdGstElement * smd_element)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (smd_element);
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
ismd_gst_vidrend_sink_event (ISmdGstElement * smd_element, GstEvent * event)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (smd_element);
  ismd_result_t result;

  switch (event->type) {
    case GST_EVENT_FLUSH_START:
      result = ismd_dev_get_stream_base_time (smd_element->dev_handle,
          &sink->ismd_basetime);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (sink, "ismd_dev_get_stream_base_time failed(%d)",
            result);
      }          
      break;  
    case GST_EVENT_FLUSH_STOP:
      sink->eos_posted = FALSE;
      ismd_gst_vidrend_sink_reset_qos (sink);
      result = ismd_dev_set_stream_base_time (smd_element->dev_handle,
          sink->ismd_basetime);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (sink, "ismd_dev_set_stream_base_time failed(%d)",
            result);
      }          
      break;
#ifndef NOT_REEL_PATCHED
    case GST_EVENT_NEWSEGMENT:
      if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
          gboolean update;
          double rate;
          double applied_rate;
          GstFormat format;
          gint64 start, stop, position;

          gst_event_parse_new_segment_full (event, &update, &rate, &applied_rate, &format, &start, &stop, &position);
          unsigned int old_frame_inc = 0;
          if(ISMD_SUCCESS != ismd_vidrend_get_fixed_frame_rate(smd_element->dev_handle, &old_frame_inc)) old_frame_inc = 0;
//          printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>new_segment %d %g %g %d %" G_GINT64_FORMAT " %" G_GINT64_FORMAT " %" G_GINT64_FORMAT " fixed frame rate %d\n", update, rate, applied_rate, format, start, stop, position, old_frame_inc);

          if((1 == rate) && (-1 != stop) && sink->fps_n && sink->fps_d) {
              unsigned int new_frame_inc = 90000LL * sink->fps_d / sink->fps_n;
              if(old_frame_inc != new_frame_inc) {
                  printf("GST_EVENT_NEWSEGMENT set %d                                        \n", new_frame_inc);
                  result = ismd_vidrend_enable_fixed_frame_rate(smd_element->dev_handle, new_frame_inc);
                  if (result != ISMD_SUCCESS)  GST_ERROR_OBJECT (sink, "ismd_vidrend_enable_fixed_frame_rate failed(%d)", result);
              }
          } else {
              if(old_frame_inc) {
                  printf("GST_EVENT_NEWSEGMENT -> disable                                    \n");
                  result = ismd_vidrend_disable_fixed_frame_rate(smd_element->dev_handle);
                  if (result != ISMD_SUCCESS) GST_ERROR_OBJECT (sink, "ismd_vidrend_disable_fixed_frame_rate failed(%d)", result);
              }
          }
      }
      break;
#endif
    default:
      break;
  }
  return TRUE;
}

static void
ismd_gst_vidrend_sink_handle_buffer (ISmdGstVidrendSink * sink,
    ismd_buffer_handle_t buf_handle)
{
  ismd_result_t result;
  gint client_id;
  ismd_buffer_descriptor_t buf_desc;
  ismd_time_t pts = ISMD_NO_PTS;

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
    if (sink->qos_enabled) {
      ismd_gst_vidrend_sink_send_qos (sink, client_id, pts);
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
ismd_gst_vidrend_sink_loop (ISmdGstVidrendSink * sink)
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
    ismd_gst_vidrend_sink_handle_buffer (sink, buf_handle);
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
ismd_gst_vidrend_sink_provide_clock (GstElement * element)
{
  ISmdGstVidrendSink *sink;
  GstClock *clock;

  sink = ISMD_GST_VIDREND_SINK (element);
  if (G_UNLIKELY (sink->provided_clock == NULL)) {
    sink->provided_clock = g_object_new (ISMD_GST_TYPE_CLOCK, NULL);
  }
  clock = GST_CLOCK_CAST (gst_object_ref (sink->provided_clock));

  GST_INFO_OBJECT (sink, "provide %p (ID:%d)",
      clock, sink->provided_clock->dev_handle);

  return clock;
}

static inline gdl_ret_t
set_gdl_port_attribute (ISmdGstVidrendSink * sink, gdl_pd_id_t pd_id)
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
config_tvmode (ISmdGstVidrendSink * sink)
{
  gdl_ret_t ret = GDL_SUCCESS;
  gdl_display_info_t di;

  GST_DEBUG_OBJECT (sink, "configure TV mode");
  memset (&di, 0, sizeof (di));

  if (sink->tvmode == -1) {
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

static inline gdl_ret_t
config_plane (ISmdGstVidrendSink * sink, gdl_plane_id_t video_plane)
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
setup_gdl (ISmdGstVidrendSink * sink)
{
  gboolean ret = FALSE;
  gdl_ret_t st;

  if (gdl_init (0) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_init failed");
    goto beach;
  }


  if (sink->tvmode != -1) {
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
ismd_gst_vidrend_sinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (gst_pad_get_parent (pad));
  GstStructure *structure;
  gboolean ret = FALSE;
  const GValue *fps;

  GST_DEBUG_OBJECT (sink, "setcaps called with %" GST_PTR_FORMAT, caps);

  structure = gst_caps_get_structure (caps, 0);

  ret = gst_structure_has_name (structure, "video/x-raw-ismd");
  fps = gst_structure_get_value (structure, "framerate");
  if (fps) {
    sink->fps_n = gst_value_get_fraction_numerator (fps);
    sink->fps_d = gst_value_get_fraction_denominator (fps);
#if 0 //ndef NOT_REEL_PATCHED
    // Use fixed frame rate if set via setcaps or dvd menus may not be shown
    if(sink->fps_n && sink->fps_d) {
      ismd_result_t result;
      ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
      if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
        result = ismd_vidrend_enable_fixed_frame_rate(smd_element->dev_handle, 90000LL * sink->fps_d / sink->fps_n);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (sink, "ismd_vidrend_enable_fixed_frame_rate failed(%d)", result);
        }
      }
    }
#endif
  }
  else {
#if 0 //ndef NOT_REEL_PATCHED
    // Don't use fixed frame rate if no valid fps is set via setcaps (or should we take a default value?)
    sink->fps_n = 25;
    sink->fps_d = 1;
    ismd_result_t result;
    ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
    if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
      result = ismd_vidrend_disable_fixed_frame_rate(smd_element->dev_handle);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_vidrend_disable_fixed_frame_rate failed(%d)", result);
      }
    }
#else
    sink->fps_n = 30;
    sink->fps_d = 1;
#endif
  }

  /* initial statistics about duration */
  sink->avg_duration =
      gst_util_uint64_scale_int (sink->fps_d, GST_SECOND, sink->fps_n);

  gst_object_unref (sink);
  return ret;
}

static GstFlowReturn
ismd_gst_vidrend_sink_alloc (GstPad * pad, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf)
{
  GstFlowReturn ret = GST_FLOW_OK;
  ISmdGstBuffer *ismd_gst_buf;

  GST_LOG_OBJECT (pad, "try to allocate %u bytes with caps %" GST_PTR_FORMAT,
      size, caps);

  ismd_gst_buf = ismd_gst_buffer_new ();
  if (G_UNLIKELY (!ismd_gst_buf)) {
    GST_ERROR_OBJECT (pad, "buffer allocation failure");
    ret = GST_FLOW_ERROR;
  } else {
    /* init the buffer's data properties */
    GST_BUFFER_SIZE (ismd_gst_buf) = size;
    *buf = (GstBuffer *) ismd_gst_buf;
  }

  if (ret == GST_FLOW_OK) {
    if (caps)
      gst_buffer_set_caps (*buf, caps);
  } else {
    *buf = NULL;
  }

  return ret;
}

static void
ismd_gst_vidrend_sink_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (object);

  switch (prop_id) {
    case PROP_VIDEO_TVMODE:
      g_value_set_enum (value, sink->tvmode);
      break;
    case PROP_VIDEO_BG_COLOR:
      g_value_set_uint (value, sink->bg_color);
      break;
    case PROP_VIDEO_GDL_PLANE:
      g_value_set_enum (value, sink->video_plane);
      break;
    case PROP_VIDEO_RECTANGLE:
      g_value_transform (&sink->rectangle, value);
      break;
    case PROP_VIDEO_QOS:
      g_value_set_boolean (value, sink->qos_enabled);
      break;
    case PROP_VIDEO_FLUSH_REPEAT_FRAME:
      g_value_set_boolean (value, sink->flush_repeat_frame);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_vidrend_sink_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (object);

  GST_OBJECT_LOCK (sink);
  switch (prop_id) {
    case PROP_VIDEO_TVMODE:
      sink->tvmode = g_value_get_enum (value);
      break;
    case PROP_VIDEO_BG_COLOR:
      sink->bg_color = g_value_get_uint (value);
      break;
    case PROP_VIDEO_GDL_PLANE:
      sink->video_plane = g_value_get_enum (value);
      break;
    case PROP_VIDEO_RECTANGLE:
      if (!g_value_transform (value, &sink->rectangle)) {
        g_warning ("Could not transform string to rectangle");
        gst_value_set_rectangle (&sink->rectangle, 0, 0, 0, 0);
      }
      GST_DEBUG_OBJECT (sink, "set destination rectangle to %d,%d,%d,%d",
          gst_value_get_rectangle_x (&sink->rectangle),
          gst_value_get_rectangle_y (&sink->rectangle),
          gst_value_get_rectangle_width (&sink->rectangle),
          gst_value_get_rectangle_height (&sink->rectangle));
      break;
    case PROP_VIDEO_QOS:
      sink->qos_enabled = g_value_get_boolean (value);
      break;
    case PROP_VIDEO_FLUSH_REPEAT_FRAME:
      {
        gboolean flush_repeat_frame = g_value_get_boolean (value);
        ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
        ismd_result_t result;
        sink->flush_repeat_frame = flush_repeat_frame;
        if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
          result = ismd_vidrend_set_flush_policy (smd_element->dev_handle,
              flush_repeat_frame ? ISMD_VIDREND_FLUSH_POLICY_REPEAT_FRAME :
              ISMD_VIDREND_FLUSH_POLICY_DISPLAY_BLACK);
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (sink, "ismd_vidrend_set_flush_policy failed(%d)",
              result);
          }
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
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (smd_element);

  if (sink->out_event != ISMD_EVENT_HANDLE_INVALID) {
    ismd_event_free (sink->out_event);
  }

  if (sink->out_port != ISMD_PORT_HANDLE_INVALID) {
    result = ismd_port_detach (sink->out_port);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_port_detach failed(%d)", result);
    }
    result =  ismd_vidrend_disable_port_output (smd_element->dev_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_vidrend_disable_port_output failed(%d)",
          result);
    }
    sink->out_port = ISMD_PORT_HANDLE_INVALID;
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
  ismd_port_handle_t port = -1;
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (smd_element);

  GST_DEBUG_OBJECT (sink, "ismd_open()");
  if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
    GST_DEBUG_OBJECT (sink,
        "video renderer: video renderer is already open. Cannot open again.");
    if (-1 == (smd_element->sink_pad)->ismd_port) {
      result = ismd_vidrend_get_input_port (smd_element->dev_handle, &port);
      if (result != ISMD_SUCCESS) {
        return FALSE;
      }
      (smd_element->sink_pad)->ismd_port = port;
    }
    return TRUE;
  }
  /* Open and Grab a handle */
  result = ismd_vidrend_open (&smd_element->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink,
        "video renderer: Unable to open video renderer. ERROR = %d", result);
    return FALSE;
  }
  GST_DEBUG_OBJECT (sink, "ismd_gst_vidrend_open(%d) OK", smd_element->dev_handle);

  /* Get the video renderer input port and set it in the pad */
  result = ismd_vidrend_get_input_port (smd_element->dev_handle, &port);
  if (result != ISMD_SUCCESS) {
    return FALSE;
  }
  (smd_element->sink_pad)->ismd_port = port;

  GST_DEBUG_OBJECT (sink, "vidrend device(%d) has input port %d",
      smd_element->dev_handle, (smd_element->sink_pad)->ismd_port);

  result = ismd_vidrend_enable_port_output (smd_element->dev_handle, 0, 1,
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

  result = ismd_vidrend_get_eos_event (smd_element->dev_handle,
      &sink->eos_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_vidrend_get_eos_event failed(%d)",
        result);
  }

  return TRUE;
}

static gboolean
ismd_gst_vidrend_sink_peer_query (ISmdGstElement * smd_element,
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
ismd_gst_vidrend_sink_query (GstElement * element, GstQuery * query)
{
  gboolean ret;
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (element);
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
        ret = ismd_gst_vidrend_sink_peer_query (smd_element, query);
        break;
      }

      /* get position */
      result = ismd_vidrend_get_stream_position (smd_element->dev_handle,
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
      ret = ismd_gst_vidrend_sink_peer_query (smd_element, query);
      break;
    }
  }

  return ret;
}

static void
ismd_gst_vidrend_sink_prepare_gdl_plane (ISmdGstVidrendSink *sink)
{
  GstStructure *s;
  GstMessage *msg;

  GST_LOG_OBJECT (sink, "prepare gdl plane");
  s = gst_structure_new ("prepare-gdl-plane", NULL);
  msg = gst_message_new_element (GST_OBJECT (sink), s);
  gst_element_post_message (GST_ELEMENT (sink), msg);
}

static GstStateChangeReturn
ismd_gst_vidrend_sink_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstVidrendSink *sink = ISMD_GST_VIDREND_SINK (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;

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
      break;
    }
    case GST_STATE_CHANGE_READY_TO_PAUSED:
    {
      ismd_result_t result;
      sink->eos_posted = FALSE;
      ismd_vidrend_flush_policy_t policy;

      if (sink->flush_repeat_frame) {
        policy = ISMD_VIDREND_FLUSH_POLICY_REPEAT_FRAME;
        GST_DEBUG_OBJECT (sink, "configuring flush policy to repeat frame");
      }
      else {
        policy = ISMD_VIDREND_FLUSH_POLICY_DISPLAY_BLACK;
        GST_DEBUG_OBJECT (sink, "configuring flush policy to display black");
      }
      result = ismd_vidrend_set_flush_policy (smd_element->dev_handle, policy);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_vidrend_set_flush_policy failed(%d)",
            result);
      }
      GST_DEBUG_OBJECT (sink, "configuring stop policy to display black");
      result = ismd_vidrend_set_stop_policy (smd_element->dev_handle,
          ISMD_VIDREND_STOP_POLICY_DISPLAY_BLACK);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_vidrend_set_stop_policy failed(%d)",
            result);
      }
      /* Post a message to let the application configure the GDL plane */
      ismd_gst_vidrend_sink_prepare_gdl_plane (sink);
      /* Setup GDL and connect the plane with the ismd_vidrend */
      if ((sink->setup = setup_gdl (sink))) {
        GST_DEBUG_OBJECT (sink, "try ismd_vidrend_set_video_plane");
        if (ISMD_SUCCESS != ismd_vidrend_set_video_plane (smd_element->dev_handle,
                sink->video_plane)) {
          GST_ERROR_OBJECT (sink, "ismd_vidrend_set_video_plane failed");
          goto failure;
        }
      } else {
        GST_ERROR_OBJECT (sink, "setup_gdl failed");
        goto failure;
      }
      sink->first_advance_to_pts = TRUE;
      ismd_gst_vidrend_sink_reset_qos (sink);
      break;
    }

    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
    {
      if (sink->monitor_loop == NULL) {
        sink->monitor_stop = FALSE;
        sink->monitor_loop = gst_task_create (
            (GstTaskFunction) ismd_gst_vidrend_sink_loop, sink);
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
        GST_DEBUG_OBJECT (sink, "monitoring task stopped");
        sink->setup = FALSE;
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
ismd_gst_vidrend_sink_dispose (GObject * object)
{
  ISmdGstVidrendSink *sink;

  sink = ISMD_GST_VIDREND_SINK (object);
  if (sink->provided_clock)
    gst_object_unref (sink->provided_clock);
  sink->provided_clock = NULL;
  G_OBJECT_CLASS (parent_class)->dispose (object);
}

#ifndef NOT_REEL_PATCHED
static ISmdGstVidrendSink * old_sink = NULL;
#endif

static void
ismd_gst_vidrend_sink_finalize (GObject * object)
{
  ISmdGstVidrendSink *sink;

  sink = ISMD_GST_VIDREND_SINK (object);
#ifndef NOT_REEL_PATCHED
  if(old_sink==sink) old_sink = NULL;
#endif
  g_value_unset (&sink->rectangle);
  g_static_rec_mutex_free (sink->monitor_mutex);
  g_free (sink->monitor_mutex);
  sink->monitor_mutex = NULL;
  sink->monitor_loop = NULL;

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
ismd_gst_vidrend_sink_init_interfaces (GType type)
{
  static const GInterfaceInfo navigation_info = {
    (GInterfaceInitFunc) ismd_gst_vidrend_sink_navigation_init,
    NULL,
    NULL,
  };
  g_type_add_interface_static (type, GST_TYPE_NAVIGATION, &navigation_info);

  /* register type and create class in a more safe place instead of at
   * runtime since the type registration and class creation is not
   * threadsafe. */
  g_type_class_ref (ISMD_GST_TYPE_ELEMENT);
}


static void
ismd_gst_vidrend_sink_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_vidrend_sink_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Hardware Video Renderer Sink",
      "Sink/Video",
      "GStreamer VideoSink Element for Intel's Media Processors",
      "http://www.intelconsumerelectronics.com/");

  GstElementClass *gstelement_class = GST_ELEMENT_CLASS (g_class);

  GstPadTemplate *curr_tmplt = NULL;

  curr_tmplt = gst_static_pad_template_get (&sink_template);
  gst_element_class_add_pad_template (gstelement_class, curr_tmplt);
  gst_object_unref (curr_tmplt);
  gst_element_class_set_details (gstelement_class,
      &ismd_gst_vidrend_sink_details);
}

static void
ismd_gst_vidrend_sink_class_init (ISmdGstVidrendSinkClass * klass)
{
  ISmdGstElementClass *iclass = ISMD_GST_ELEMENT_CLASS (klass);
  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GObjectClass *oclass = G_OBJECT_CLASS (klass);

  oclass->get_property = ismd_gst_vidrend_sink_get_property;
  oclass->set_property = ismd_gst_vidrend_sink_set_property;

  g_object_class_install_property (oclass, PROP_VIDEO_TVMODE,
      g_param_spec_enum ("tvmode",
          "Television mode",
          "Define the television mode",
          GST_TYPE_ISMD_VIDEO_SINK_TVMODE,
          DEFAULT_ISMD_VIDEO_SINK_TVMODE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_BG_COLOR,
      g_param_spec_uint ("bgcolor",
          "Background color",
          "Defines the canvas color used by the gdl plane",
          0, 0xffffffff, DEFAULT_ISMD_VIDEO_SINK_BG_COLOR, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_GDL_PLANE,
      g_param_spec_enum ("gdl-plane",
          "UPP used for rendering",
          "Define the Universal Pixel Plane used in the GDL layer",
          GST_TYPE_ISMD_VIDEO_SINK_GDL_PLANE,
          DEFAULT_ISMD_VIDEO_SINK_GDL_PLANE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_RECTANGLE,
      g_param_spec_string ("rectangle", "Destination rectangle",
          "The destination rectangle, (0,0,0,0) full screen",
          DEFAULT_ISMD_VIDEO_SINK_RECTANGLE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_VIDEO_QOS,
      g_param_spec_boolean ("qos", "Qos",
          "Generate Quality-of-Service events upstream",
          DEFAULT_ISMD_VIDEO_SINK_QOS,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_VIDEO_FLUSH_REPEAT_FRAME,
      g_param_spec_boolean ("flush-repeat-frame", "Flushing Repeat Frame",
          "Keep displaying the last frame rather than a black one whilst flushing",
          DEFAULT_ISMD_VIDEO_SINK_FLUSH_REPEAT_FRAME,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_change_state);
  eclass->query = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_query);
  eclass->provide_clock =
      GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_provide_clock);
  iclass->prerolled = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_prerolled);
  iclass->convert = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_convert);
  iclass->drain = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_drain);
  iclass->track_qos = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_track_qos);
  iclass->event = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_event);
  iclass->is_sink = TRUE;
  oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_dispose);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_finalize);

  ismd_gst_element_requires_clock (eclass);
}

static void
ismd_gst_vidrend_sink_init (ISmdGstVidrendSink * sink,
    ISmdGstVidrendSinkClass * g_class)
{
  /* Create Sink Pad */
  GstPad *pad;
  ISmdGstElement *element = ISMD_GST_ELEMENT (sink);

  GstPadTemplate *curr_tmplt = NULL;

  GST_DEBUG_OBJECT (sink, "ismd_gst_vidrend_sink_init()");
  curr_tmplt = gst_static_pad_template_get (&sink_template);
  element->sink_pad = ismd_gst_pad_new_from_template (curr_tmplt, "sink");
  gst_object_unref (curr_tmplt);

  pad = GST_PAD (element->sink_pad);
  gst_element_add_pad (GST_ELEMENT (element), pad);
  /* Register sinkpad to allow the element to receive and process buffers */
  ismd_gst_element_register_sinkpad (element, element->sink_pad);
  gst_pad_set_bufferalloc_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sink_alloc));

  /* Set up the pad capabilities */
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vidrend_sinkpad_setcaps));

  /* Initialize to invalid port id - to prevent buffer passing */
  (element->sink_pad)->ismd_port = -1;

  sink->tvmode = DEFAULT_ISMD_VIDEO_SINK_TVMODE;
  sink->bg_color = DEFAULT_ISMD_VIDEO_SINK_BG_COLOR;
  sink->gamma = GDL_GAMMA_LINEAR;        /* GDL_GAMMA_2_2 GDL_GAMMA_2_8 */
  sink->video_plane = DEFAULT_ISMD_VIDEO_SINK_GDL_PLANE;
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
  sink->qos_enabled = DEFAULT_ISMD_VIDEO_SINK_QOS;
  sink->flush_repeat_frame = DEFAULT_ISMD_VIDEO_SINK_FLUSH_REPEAT_FRAME;
#ifndef NOT_REEL_PATCHED
  sink->provided_clock = NULL;
  //UGLY PATCH: Reuse the clock since we expect that the old instance will not be finalized
  if(old_sink) sink->provided_clock = ismd_gst_clock_reuse(old_sink->provided_clock);
  old_sink=sink;
#endif
  ismd_gst_vidrend_sink_reset_qos (sink);
  g_value_init (&sink->rectangle, GST_TYPE_RECTANGLE);
  gst_value_set_rectangle (&sink->rectangle, 0, 0, 0, 0);
  GST_OBJECT_FLAG_SET (GST_OBJECT (sink), GST_ELEMENT_IS_SINK);
}

