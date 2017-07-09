/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

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

#include "ismd_global_defs.h"
#include "ismd_vidpproc.h"
#include "ismd_gst_refiller.h"
#include "ismd_gst_vidrend_bin.h"
#include "ismd_gst_enum.h"
#include "ismd_gst_rectangle.h"

GST_DEBUG_CATEGORY_EXTERN (ismd_gst_vidrend_bin_debug);
#define GST_CAT_DEFAULT ismd_gst_vidrend_bin_debug

/* video rendering related */
#define DEFAULT_ISMD_VIDEO_BIN_TVMODE      -1
#define DEFAULT_ISMD_VIDEO_BIN_BG_COLOR    0
#define DEFAULT_ISMD_VIDEO_BIN_GDL_PLANE   GDL_PLANE_ID_UPP_A
#define DEFAULT_ISMD_VIDEO_PAN_AND_SCAN    FALSE
#define DEFAULT_ISMD_VIDEO_QOS             TRUE
#define DEFAULT_ISMD_VIDEO_BIN_FLUSH_REPEAT_FRAME TRUE

/* video postprocessor related */
#define DEFAULT_ISMD_VIDEO_BIN_SCALE_MODE  ZOOM_TO_FIT

/* common properties */
#define DEFAULT_ISMD_VIDEO_RECTANGLE   "0,0,0,0"
#define DEFAULT_STREAM_TIME_OFFSET  0

enum
{
  PROP_VIDEO_UNKNOWN,
  PROP_VIDEO_RECTANGLE,
  PROP_VIDEO_STREAM_TIME_OFFSET,
  PROP_VIDEO_TVMODE,
  PROP_VIDEO_BG_COLOR,
  PROP_VIDEO_GDL_PLANE,
  PROP_VIDEO_SCALE_MODE,
  PROP_VIDEO_PAN_AND_SCAN,
  PROP_VIDEO_QOS,
  PROP_VIDEO_FLUSH_REPEAT_FRAME
};

static GstElementDetails ismd_gst_vidrend_bin_details = {
  "Intel Streaming Media Driver (ISMD) Hardware Video Renderer Bin",
  "Sink/Video",
  "GStreamer Video Render Bin for Intel's Media Processors",
  "http://www.intelconsumerelectronics.com/"
};

#define ISMD_GST_VIDEO_CAPS \
           "video/x-decoded-ismd; " \
           "video/x-raw-yuv, " \
           "  format = (fourcc) {NV12, YV12, I420}, "\
           "  width = (int) [16,1920], " \
           "  height = (int) [16,1088] "

static GstStaticPadTemplate ismd_gst_video_sink_factory =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VIDEO_CAPS));


GST_BOILERPLATE (ISmdGstVidrendBin, ismd_gst_vidrend_bin, GstBin, GST_TYPE_BIN);

static void
ismd_gst_vidrend_bin_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstVidrendBin *bin = ISMD_GST_VIDREND_BIN (object);
  gint tvmode;
  guint32 bgcolor;
  gdl_plane_id_t gdlplane;
  ismd_vidpproc_scaling_policy_t scalemode;
  gboolean pan_and_scan, qos, flush_repeat_frame;

  switch (prop_id) {
    case PROP_VIDEO_RECTANGLE:
      g_value_transform (&bin->rectangle, value);
      break;
    case PROP_VIDEO_STREAM_TIME_OFFSET:
      g_value_set_uint64 (value, bin->stream_time_offset);
      break;
    case PROP_VIDEO_TVMODE:
      g_object_get (G_OBJECT (bin->vidrendsink), "tvmode", &tvmode, NULL);
      g_value_set_enum (value, tvmode);
      break;
    case PROP_VIDEO_BG_COLOR:
      g_object_get (G_OBJECT (bin->vidrendsink), "bgcolor", &bgcolor, NULL);
      g_value_set_uint (value, bgcolor);
      break;
    case PROP_VIDEO_GDL_PLANE:
      g_object_get (G_OBJECT (bin->vidrendsink), "gdl-plane", &gdlplane, NULL);
      g_value_set_enum (value, gdlplane);
      break;
    case PROP_VIDEO_SCALE_MODE:
      g_object_get (G_OBJECT (bin->vidpproc), "scale-mode", &scalemode, NULL);
      g_value_set_enum (value, scalemode);
      break;
    case PROP_VIDEO_PAN_AND_SCAN:
      g_object_get (G_OBJECT (bin->vidpproc), "pan-and-scan", &pan_and_scan,
          NULL);
      g_value_set_boolean (value, pan_and_scan);
      break;
    case PROP_VIDEO_QOS:
      g_object_get (G_OBJECT (bin->vidrendsink), "qos", &qos, NULL);
      g_value_set_boolean (value, qos);
      break;
    case PROP_VIDEO_FLUSH_REPEAT_FRAME:
      g_object_get (G_OBJECT (bin->vidrendsink), "flush-repeat-frame", &flush_repeat_frame, NULL);
      g_value_set_boolean (value, flush_repeat_frame);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_vidrend_bin_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstVidrendBin *bin = ISMD_GST_VIDREND_BIN (object);
  gint tvmode;
  guint32 bgcolor;
  gdl_plane_id_t gdlplane;
  ismd_vidpproc_scaling_policy_t scalemode;
  gboolean pan_and_scan, qos, flush_repeat_frame;

  switch (prop_id) {
    case PROP_VIDEO_RECTANGLE:

      if (!g_value_transform (value, &bin->rectangle)) {
        g_warning ("Could not transform string to rectangle");
        gst_value_set_rectangle (&bin->rectangle, 0, 0, 0, 0);
      }
      GST_DEBUG_OBJECT (bin, "set destination rectangle to %d,%d,%d,%d",
          gst_value_get_rectangle_x (&bin->rectangle),
          gst_value_get_rectangle_y (&bin->rectangle),
          gst_value_get_rectangle_width (&bin->rectangle),
          gst_value_get_rectangle_height (&bin->rectangle));

      g_object_set (G_OBJECT (bin->refiller), "rectangle",
          g_value_get_string (value), NULL);

      g_object_set (G_OBJECT (bin->vidpproc), "rectangle",
          g_value_get_string (value), NULL);

      g_object_set (G_OBJECT (bin->vidrendsink), "rectangle",
          g_value_get_string (value), NULL);

      break;
    case PROP_VIDEO_STREAM_TIME_OFFSET:
      bin->stream_time_offset = g_value_get_uint64 (value);
      g_object_set (G_OBJECT (bin->vidpproc), "stream-time-offset",
          bin->stream_time_offset, NULL);
      g_object_set (G_OBJECT (bin->vidrendsink), "stream-time-offset",
          bin->stream_time_offset, NULL);
      break;
    case PROP_VIDEO_TVMODE:
      tvmode = g_value_get_enum (value);
      g_object_set (G_OBJECT (bin->vidrendsink), "tvmode", tvmode, NULL);
      break;
    case PROP_VIDEO_BG_COLOR:
      bgcolor = g_value_get_uint (value);
      g_object_set (G_OBJECT (bin->vidrendsink), "bgcolor", bgcolor, NULL);
      break;
    case PROP_VIDEO_GDL_PLANE:
      gdlplane = g_value_get_enum (value);
      g_object_set (G_OBJECT (bin->vidrendsink), "gdl-plane", gdlplane, NULL);
      break;
    case PROP_VIDEO_SCALE_MODE:
      scalemode = g_value_get_enum (value);
      g_object_set (G_OBJECT (bin->vidpproc), "scale-mode", scalemode, NULL);
      break;
    case PROP_VIDEO_PAN_AND_SCAN:
      pan_and_scan = g_value_get_boolean (value);
      g_object_set (G_OBJECT (bin->vidpproc), "pan-and-scan", pan_and_scan,
          NULL);
      break;
    case PROP_VIDEO_QOS:
      qos = g_value_get_boolean (value);
      g_object_set (G_OBJECT (bin->vidrendsink), "qos", qos, NULL);
      break;
    case PROP_VIDEO_FLUSH_REPEAT_FRAME:
      flush_repeat_frame = g_value_get_boolean (value);
      g_object_set (G_OBJECT (bin->vidrendsink), "flush-repeat-frame", flush_repeat_frame, NULL);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_vidrend_bin_dispose (GObject * object)
{
  ISmdGstVidrendBin *bin = ISMD_GST_VIDREND_BIN (object);

  if (bin->refiller) {
    gst_object_unref (bin->refiller);
    bin->refiller = NULL;
  }

  if (bin->vidpproc) {
    gst_object_unref (bin->vidpproc);
    bin->vidpproc = NULL;
  }

  if (bin->vidrendsink) {
    gst_object_unref (bin->vidrendsink);
    bin->vidrendsink = NULL;
  }
  GST_CALL_PARENT (G_OBJECT_CLASS, dispose, (object));
}

static void
ismd_gst_vidrend_bin_finalize (GObject * object)
{
  ISmdGstVidrendBin *bin = ISMD_GST_VIDREND_BIN (object);

  GST_DEBUG_OBJECT (bin, "Destroying");
  g_value_unset (&bin->rectangle);
  GST_CALL_PARENT (G_OBJECT_CLASS, finalize, (object));
}

static void
ismd_gst_vidrend_bin_base_init (gpointer g_class)
{
  GstElementClass * element_class = GST_ELEMENT_CLASS (g_class);

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&ismd_gst_video_sink_factory));

  gst_element_class_set_details (element_class, &ismd_gst_vidrend_bin_details);
}

static void
ismd_gst_vidrend_bin_class_init (ISmdGstVidrendBinClass * klass)
{
  GObjectClass * oclass = G_OBJECT_CLASS (klass);

  oclass->get_property = ismd_gst_vidrend_bin_get_property;
  oclass->set_property = ismd_gst_vidrend_bin_set_property;
  oclass->dispose = ismd_gst_vidrend_bin_dispose;
  oclass->finalize = ismd_gst_vidrend_bin_finalize;

  g_object_class_install_property (oclass, PROP_VIDEO_STREAM_TIME_OFFSET,
      g_param_spec_uint64 ("stream-time-offset", "Stream Time Offset",
          "Specifies an offset in ns to apply on clock synchronization.",
          0, G_MAXUINT64, DEFAULT_STREAM_TIME_OFFSET, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_TVMODE,
      g_param_spec_enum ("tvmode",
          "Television mode",
          "Define the television mode",
          GST_TYPE_ISMD_VIDEO_SINK_TVMODE,
          DEFAULT_ISMD_VIDEO_BIN_TVMODE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_BG_COLOR,
      g_param_spec_uint ("bgcolor",
          "Background color",
          "Defines the canvas color used by the gdl plane",
          0, 0xffffffff, DEFAULT_ISMD_VIDEO_BIN_BG_COLOR, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_GDL_PLANE,
      g_param_spec_enum ("gdl-plane",
          "UPP used for rendering",
          "Define the Universal Pixel Plane used in the GDL layer",
          GST_TYPE_ISMD_VIDEO_SINK_GDL_PLANE,
          DEFAULT_ISMD_VIDEO_BIN_GDL_PLANE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_VIDEO_SCALE_MODE,
      g_param_spec_enum ("scale-mode",
          "Scale mode",
          "Define the mode used by the video scaler",
          GST_TYPE_ISMD_VIDPPROC_SCALE_MODE,
          DEFAULT_ISMD_VIDEO_BIN_SCALE_MODE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_VIDEO_PAN_AND_SCAN,
      g_param_spec_boolean ("pan-and-scan",
          "Pan and Scan",
          "Enable usage of Pan and Scan information if present in the stream",
          DEFAULT_ISMD_VIDEO_PAN_AND_SCAN, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_RECTANGLE,
      g_param_spec_string ("rectangle", "Destination rectangle",
          "The destination rectangle, (0,0,0,0) full screen",
          DEFAULT_ISMD_VIDEO_RECTANGLE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass,
      PROP_VIDEO_QOS,
      g_param_spec_boolean ("qos",
          "Qos",
          "Generate Quality-of-Service events upstream",
          DEFAULT_ISMD_VIDEO_QOS, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDEO_FLUSH_REPEAT_FRAME,
      g_param_spec_boolean ("flush-repeat-frame", "Flushing Repeat Frame",
          "Keep displaying the last frame rather than a black one whilst flushing",
          DEFAULT_ISMD_VIDEO_BIN_FLUSH_REPEAT_FRAME,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
}

static void
ismd_gst_vidrend_bin_init (ISmdGstVidrendBin * bin,
    ISmdGstVidrendBinClass * g_class)
{
  GstElement *refiller, *vidpproc, *vidrendsink;

  g_value_init (&bin->rectangle, GST_TYPE_RECTANGLE);
  gst_value_set_rectangle (&bin->rectangle, 0, 0, 0, 0);

  bin->stream_time_offset = DEFAULT_STREAM_TIME_OFFSET;

  refiller = g_object_new (ISMD_GST_TYPE_REFILLER, NULL);
  if (refiller) {
    GstPad * pad, * gpad;

    if (!gst_bin_add (GST_BIN (bin), refiller)) {
      GST_ERROR_OBJECT (bin, "Could not add refiller element");
      gst_object_unref (refiller);
      return;
    }

    /* get the sinkpad */
    pad = gst_element_get_static_pad (refiller, "sink");
    /* ghost the sink pad to ourself */
    gpad = gst_ghost_pad_new ("sink", pad);
    gst_pad_set_active (gpad, TRUE);
    gst_element_add_pad (GST_ELEMENT (bin), gpad);
    gst_object_unref (pad);
  }
  else {
    GST_ERROR_OBJECT (bin, "refiller creation failed");
    return;
  }

  vidpproc = gst_element_factory_make ("ismd_vidpproc", NULL);
  if (vidpproc) {
    if (!gst_bin_add (GST_BIN (bin), vidpproc)) {
      GST_ERROR_OBJECT (bin, "Could not add vidpproc element");
      gst_object_unref (vidpproc);
      return;
    }
    g_object_set (G_OBJECT (vidpproc),
        "scale-mode", DEFAULT_ISMD_VIDEO_BIN_SCALE_MODE,
        "pan-and-scan", DEFAULT_ISMD_VIDEO_PAN_AND_SCAN,
        "rectangle", DEFAULT_ISMD_VIDEO_RECTANGLE, NULL);
  }
  else {
    GST_ERROR_OBJECT (bin, "vidpproc creation failed");
    return;
  }

  vidrendsink = gst_element_factory_make ("ismd_vidrend_sink", NULL);
  if (vidrendsink) {
    if (!gst_bin_add (GST_BIN (bin), vidrendsink)) {
      GST_ERROR_OBJECT (bin, "Could not add vidrendsink element");
      gst_object_unref (vidrendsink);
      return;
    }

    g_object_set (G_OBJECT (vidrendsink),
        "tvmode", DEFAULT_ISMD_VIDEO_BIN_TVMODE,
        "bgcolor", DEFAULT_ISMD_VIDEO_BIN_BG_COLOR,
        "gdl-plane", DEFAULT_ISMD_VIDEO_BIN_GDL_PLANE,
        "rectangle", DEFAULT_ISMD_VIDEO_RECTANGLE,
        "flush-repeat-frame", DEFAULT_ISMD_VIDEO_BIN_FLUSH_REPEAT_FRAME, NULL);
  }
  else {
    GST_ERROR_OBJECT (bin, "vidrend creation failed");
    return;
  }
  gst_element_link_many (refiller, vidpproc, vidrendsink, NULL);
  bin->refiller = gst_object_ref (refiller);
  bin->vidpproc = gst_object_ref (vidpproc);
  bin->vidrendsink = gst_object_ref (vidrendsink);
  GST_OBJECT_FLAG_SET (GST_OBJECT (bin), GST_ELEMENT_IS_SINK);
}



