/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2011. Fluendo S.A. All rights reserved.

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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "ismd_gst_refiller.h"
#include "ismd_gst_rectangle.h"

GST_DEBUG_CATEGORY_EXTERN (ismd_gst_refiller_debug);
#define GST_CAT_DEFAULT ismd_gst_refiller_debug

#define DEFAULT_ISMD_VIDEO_RECTANGLE   "0,0,0,0"

#define MAX_RECENT 12

enum
{
  PROP_VIDEO_UNKNOWN,
  PROP_VIDEO_RECTANGLE
};

#define ISMD_GST_VIDEO_CAPS \
           "video/x-decoded-ismd; " \
           "video/x-raw-yuv, " \
           "  format = (fourcc) {NV12, YV12, I420}, "\
           "  width = (int) [16,1920], " \
           "  height = (int) [16,1088] "

static GstStaticPadTemplate video_sink_factory =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VIDEO_CAPS));

static GstStaticPadTemplate video_src_factory =
GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VIDEO_CAPS));

GST_BOILERPLATE (ISmdGstRefiller, ismd_gst_refiller, GstElement, GST_TYPE_ELEMENT);

static gboolean
ismd_gst_refiller_setcaps (GstPad * pad, GstCaps * caps)
{
  gboolean ret = TRUE;
  ISmdGstRefiller * refiller;

  refiller = ISMD_GST_REFILLER (gst_pad_get_parent (pad));

  GST_DEBUG_OBJECT (refiller, "setcaps called with %" GST_PTR_FORMAT, caps);
  if (!gst_pad_set_caps (refiller->srcpad, caps)) {
    GST_WARNING_OBJECT (refiller, "failed setting downstream caps");
    ret = FALSE;
    goto beach;
  }

beach:
  gst_object_unref (refiller);
  return ret;
}

/* Use with the object lock taken */
static void
ismd_gst_refiller_flush (ISmdGstRefiller * refiller, GstClockTime age)
{
  GstClockTime time = 0;
  GstBuffer * buffer;

  GST_LOG_OBJECT (refiller, "flushing age: %" GST_TIME_FORMAT,
      GST_TIME_ARGS (age));

  /* Flush all data in the recent memory list */
  while (refiller->buffers) {
    buffer = GST_BUFFER (refiller->buffers->data);
    if (GST_CLOCK_TIME_IS_VALID (age)) {
      time = gst_segment_to_running_time (refiller->segment, GST_FORMAT_TIME,
          GST_BUFFER_TIMESTAMP (buffer));
      GST_LOG_OBJECT (refiller, "checking buf: %p with time: %" GST_TIME_FORMAT,
          buffer, GST_TIME_ARGS (time));

      if (time >= age) {
        break;
      }
    }
    GST_LOG_OBJECT (refiller, "releasing buf: %p with pts: %" GST_TIME_FORMAT,
        buffer, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP(buffer)));
    gst_buffer_unref (buffer);
    refiller->buffers = g_slist_delete_link (refiller->buffers,
        refiller->buffers);
  }
}

static GstFlowReturn
ismd_gst_refiller_chain (GstPad * pad, GstBuffer * buffer)
{
  GstFlowReturn ret = GST_FLOW_OK;
  ISmdGstRefiller * refiller;
  gboolean need_refill;
  GSList * to_push = NULL;
  GstClockTime pts, duration;
  gint64 clip_start, clip_stop;
  gboolean in_segment;

  refiller = ISMD_GST_REFILLER (gst_pad_get_parent (pad));

  pts = GST_BUFFER_TIMESTAMP (buffer);
  duration = GST_BUFFER_DURATION (buffer);

  to_push = g_slist_append (to_push, buffer);

  if (GST_CLOCK_TIME_IS_VALID (pts)) {
    GST_LOG_OBJECT (refiller, "check for clipping on buffer %p with pts %" \
        GST_TIME_FORMAT " and duration %" GST_TIME_FORMAT,
        buffer, GST_TIME_ARGS (pts), GST_TIME_ARGS (duration));

    clip_start = clip_stop = pts;
    if (GST_CLOCK_TIME_IS_VALID (duration))
      clip_stop += duration;

    /* Check if this buffer's timestamp/duration is in our segment */
    in_segment = gst_segment_clip (refiller->segment, GST_FORMAT_TIME,
        clip_start, clip_stop, &clip_start, &clip_stop);
  }
  else {
    in_segment = TRUE;
  }

  if (in_segment) {
    guint count;
    GST_OBJECT_LOCK (refiller);
    /* Add a ref for this buffer in the recent memory list */
    refiller->buffers =
        g_slist_append (refiller->buffers, gst_buffer_ref (buffer));
    count = g_slist_length (refiller->buffers);
    if (count > MAX_RECENT) {
      buffer = GST_BUFFER (refiller->buffers->data);
      gst_buffer_unref (buffer);
      refiller->buffers = g_slist_delete_link (refiller->buffers,
          refiller->buffers);
      count--;
    }
    GST_DEBUG_OBJECT (refiller, "%u buffers in recent list", count);
    GST_OBJECT_UNLOCK (refiller);
  }


push_buffers:
  while (to_push) {
    buffer = GST_BUFFER (to_push->data);
    if (ret == GST_FLOW_OK) {
      GST_LOG_OBJECT (refiller, "pushing buf: %p pts: %" GST_TIME_FORMAT,
          buffer, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buffer)));
      ret = gst_pad_push (refiller->srcpad, buffer);
    } else {
      GST_LOG_OBJECT (refiller, "dropping buf: %p pts: %" GST_TIME_FORMAT,
          buffer, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buffer)));
      gst_buffer_unref (buffer);
    }
    to_push = g_slist_delete_link (to_push, to_push);
  }
  GST_DEBUG_OBJECT (refiller, "ret is %s", gst_flow_get_name (ret));

  /* Here check if we need to refill the pipeline for a rectangle animation */
  GST_OBJECT_LOCK (refiller);
  need_refill = refiller->need_refill;
  if (refiller->buffers && need_refill) {
    GSList * walk = refiller->buffers;
    /* Finish flushing */
    GST_DEBUG_OBJECT (refiller, "pushing flush stop");
    gst_pad_push_event (refiller->srcpad, gst_event_new_flush_stop ());
#if 0    
    if (walk && !refiller->last_new_segment) {
      gint64 stop, start = 0, pos = 0;
      buffer = GST_BUFFER (walk->data);

      start = refiller->segment->start;
      stop = refiller->segment->stop;
      pos = GST_BUFFER_TIMESTAMP (buffer);

      GST_DEBUG_OBJECT (refiller, "new segment from %" GST_TIME_FORMAT \
            ", to %" GST_TIME_FORMAT ", pos %" GST_TIME_FORMAT, \
            GST_TIME_ARGS (pos), GST_TIME_ARGS (stop),
            GST_TIME_ARGS (start));
      refiller->last_new_segment = gst_event_new_new_segment (FALSE,
              refiller->segment->rate, GST_FORMAT_TIME, pos, stop, start);
    }
#endif
    /* Collect the buffers that have to be pushed */
    while (walk) {
      buffer = GST_BUFFER (walk->data);
      to_push = g_slist_append(to_push, gst_buffer_ref (buffer));
      walk = g_slist_next (walk);
    }
    GST_DEBUG_OBJECT (refiller, "reloaded %u buffers", g_slist_length (to_push));
    /* Recover the new segment */
    GST_DEBUG_OBJECT (refiller, "pushing new segment");
    gst_pad_push_event (refiller->srcpad,
        gst_event_ref (refiller->last_new_segment));
  }
  refiller->need_refill = FALSE;
  GST_OBJECT_UNLOCK (refiller);

  if (need_refill) {
    ret = GST_FLOW_OK;
    goto push_buffers;
  }

  gst_object_unref (refiller);
  return ret;
}

static gboolean
ismd_gst_refiller_sink_event (GstPad * pad, GstEvent * event)
{
  ISmdGstRefiller * refiller;
  gboolean ret = FALSE;

  refiller = ISMD_GST_REFILLER (gst_pad_get_parent (pad));

  GST_DEBUG_OBJECT (refiller, "handling event type %s",
      GST_EVENT_TYPE_NAME (event));

  switch (GST_EVENT_TYPE (event)) {
    case GST_EVENT_EOS:
      GST_DEBUG_OBJECT (refiller, "we are EOS, flushing...");
      GST_OBJECT_LOCK (refiller);
      ismd_gst_refiller_flush (refiller, GST_CLOCK_TIME_NONE);
      GST_OBJECT_UNLOCK (refiller);
      ret = gst_pad_push_event (refiller->srcpad, event);
      break;
    case GST_EVENT_NEWSEGMENT:
    {
      GstFormat format;
      gdouble rate;
      gint64 start, stop, time;
      gboolean update;

      gst_event_parse_new_segment (event, &update, &rate, &format, &start,
          &stop, &time);

      GST_OBJECT_LOCK (refiller);
      ismd_gst_refiller_flush (refiller, GST_CLOCK_TIME_NONE);
      GST_OBJECT_UNLOCK (refiller);

      if (refiller->last_new_segment) {
        gst_event_unref (refiller->last_new_segment);
        refiller->last_new_segment = NULL;
      }
      refiller->last_new_segment = gst_event_ref (event);

      /* now copy over the values */
      gst_segment_set_newsegment (refiller->segment, update, rate, format,
          start, stop, time);

      GST_DEBUG_OBJECT (refiller, "received new segment %" GST_SEGMENT_FORMAT,
          refiller->segment);

      ret = gst_pad_push_event (refiller->srcpad, event);
      break;
    }
    case GST_EVENT_FLUSH_STOP:
      GST_DEBUG_OBJECT (refiller, "flushing");
      GST_OBJECT_LOCK (refiller);
      ismd_gst_refiller_flush (refiller, GST_CLOCK_TIME_NONE);
      GST_OBJECT_UNLOCK (refiller);

      /* Need to init our segment again after a flush */
      gst_segment_init (refiller->segment, GST_FORMAT_TIME);
      if (refiller->last_new_segment) {
        gst_event_unref (refiller->last_new_segment);
        refiller->last_new_segment = NULL;
      }

      ret = gst_pad_push_event (refiller->srcpad, event);
      break;
    default:
      ret = gst_pad_push_event (refiller->srcpad, event);
      break;
  }

  gst_object_unref (refiller);

  return ret;
}

static gboolean
ismd_gst_refiller_src_event (GstPad * pad, GstEvent * event)
{
  ISmdGstRefiller * refiller;
  gboolean ret = FALSE;

  refiller = ISMD_GST_REFILLER (gst_pad_get_parent (pad));

  GST_DEBUG_OBJECT (refiller, "handling event type %s",
      GST_EVENT_TYPE_NAME (event));

  switch (GST_EVENT_TYPE (event)) {
    case GST_EVENT_QOS:
    {
      gdouble proportion;
      GstClockTimeDiff diff;
      GstClockTime timestamp;

      gst_event_parse_qos (event, &proportion, &diff, &timestamp);

      GST_LOG_OBJECT (refiller, "got QOS %" GST_TIME_FORMAT ", %"
          G_GINT64_FORMAT ", proportion %f",
          GST_TIME_ARGS (timestamp), diff, proportion);

      /* update our QoS values with buffer reception time */
      GST_OBJECT_LOCK (refiller);
      ismd_gst_refiller_flush (refiller, timestamp);
      GST_OBJECT_UNLOCK (refiller);

      ret = gst_pad_push_event (refiller->sinkpad, event);
      break;
    }
    default:
      ret = gst_pad_event_default (pad, event);
      break;
  }

  gst_object_unref (refiller);

  return ret;
}

static void
ismd_gst_refiller_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstRefiller *refiller = ISMD_GST_REFILLER (object);

  switch (prop_id) {
    case PROP_VIDEO_RECTANGLE:
    {
      GST_OBJECT_LOCK (refiller);
      if (!g_value_transform (value, &refiller->rectangle)) {
        g_warning ("Could not transform string to rectangle");
        gst_value_set_rectangle (&refiller->rectangle, 0, 0, 0, 0);
      }
      if (GST_STATE (refiller) == GST_STATE_PAUSED && refiller->buffers) {
        GST_DEBUG_OBJECT (refiller, "pushing flush start");
        gst_pad_push_event (refiller->srcpad, gst_event_new_flush_start ());
        refiller->need_refill = TRUE;
      }
      GST_OBJECT_UNLOCK (refiller);
      break;
    }
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_refiller_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstRefiller *refiller = ISMD_GST_REFILLER (object);

  switch (prop_id) {
    case PROP_VIDEO_RECTANGLE:
      GST_OBJECT_LOCK (refiller);
      g_value_transform (&refiller->rectangle, value);
      GST_OBJECT_UNLOCK (refiller);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_refiller_finalize (GObject * object)
{
  ISmdGstRefiller *refiller = ISMD_GST_REFILLER (object);

  g_value_unset (&refiller->rectangle);

  ismd_gst_refiller_flush (refiller, GST_CLOCK_TIME_NONE);

  if (refiller->segment) {
    gst_segment_free (refiller->segment);
    refiller->segment = NULL;
  }

  if (refiller->last_new_segment) {
    gst_event_unref (refiller->last_new_segment);
    refiller->last_new_segment = NULL;
  }

  GST_CALL_PARENT (G_OBJECT_CLASS, finalize, (object));
}

static void
ismd_gst_refiller_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_refiller_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Refiller Element",
      "Controller/Video",
      "GStreamer Refiller element for rectangle animation in paused state",
      "http://www.intelconsumerelectronics.com/");

  GstElementClass *element_class = GST_ELEMENT_CLASS (g_class);

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&video_sink_factory));

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&video_src_factory));

  gst_element_class_set_details (element_class, &ismd_gst_refiller_details);
}

static void
ismd_gst_refiller_class_init (ISmdGstRefillerClass * klass)
{
  //GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GObjectClass *oclass = G_OBJECT_CLASS (klass);

  oclass->set_property = ismd_gst_refiller_set_property;
  oclass->get_property = ismd_gst_refiller_get_property;

  //oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_refiller_dispose);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_refiller_finalize);

  g_object_class_install_property (oclass, PROP_VIDEO_RECTANGLE,
      g_param_spec_string ("rectangle", "Destination rectangle",
          "The destination rectangle, (0,0,0,0) full screen",
          DEFAULT_ISMD_VIDEO_RECTANGLE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
}

static void
ismd_gst_refiller_init (ISmdGstRefiller * refiller,
    ISmdGstRefillerClass * g_class)
{
  refiller->sinkpad = gst_pad_new_from_static_template (&video_sink_factory,
      "sink");

  gst_pad_set_event_function (refiller->sinkpad, ismd_gst_refiller_sink_event);
  gst_pad_set_chain_function (refiller->sinkpad, ismd_gst_refiller_chain);
  gst_pad_set_setcaps_function (refiller->sinkpad, ismd_gst_refiller_setcaps);
  gst_element_add_pad (GST_ELEMENT (refiller), refiller->sinkpad);

  refiller->srcpad = gst_pad_new_from_static_template (&video_src_factory,
      "src");

  gst_pad_set_event_function (refiller->srcpad, ismd_gst_refiller_src_event);
  gst_pad_use_fixed_caps (refiller->srcpad);
  gst_element_add_pad (GST_ELEMENT (refiller), refiller->srcpad);

  g_value_init (&refiller->rectangle, GST_TYPE_RECTANGLE);
  gst_value_set_rectangle (&refiller->rectangle, 0, 0, 0, 0);

  refiller->segment = gst_segment_new ();
  refiller->need_refill = FALSE;
  refiller->buffers = NULL;
  refiller->last_new_segment = NULL;
}

