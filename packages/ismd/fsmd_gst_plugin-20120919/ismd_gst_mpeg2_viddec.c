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

#include <stdlib.h>
#include <string.h>

#include "ismd_gst_enum.h"
#include "ismd_gst_element.h"
#include "ismd_gst_mpeg2_viddec.h"
#include "ismd_viddec.h"

/* Forward declarations of prviate API functions in viddec driver to enable
 * special PTS re-ordering mode for Netflix content (ECR #200091).  This
 * only affects VC-1 content (see ismd_viddec_pvt.h) */
ismd_result_t ismd_viddec_enable_host_pts_reordering (ismd_dev_t viddec);
ismd_result_t ismd_viddec_disable_host_pts_reordering (ismd_dev_t viddec);

#define ISMD_GST_MPEG2_VIDDEC_SINK_CAPS \
           "video/mpeg, " \
           "  format = (fourcc) {MPEG, MP2V}, " \
           "  width = (int) [16,1920], " \
           "  height = (int) [16,1088], " \
           "  mpegversion = (int) [1, 2], " \
           "  systemstream = (boolean) false, " \
           "  ispacketized = (boolean) false; "

#define ISMD_GST_MPEG2_VIDDEC_SRC_CAPS \
           "video/x-decoded-ismd"

static GstStaticPadTemplate ismd_gst_mpeg2_viddec_sinkpad_template =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_MPEG2_VIDDEC_SINK_CAPS)
    );

static GstStaticPadTemplate ismd_gst_mpeg2_viddec_srcpad_template =
GST_STATIC_PAD_TEMPLATE ("src_1",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_MPEG2_VIDDEC_SRC_CAPS)
    );

static GstStaticCaps srccap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_MPEG2_VIDDEC_SRC_CAPS };
static GstStaticCaps sinkcap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_MPEG2_VIDDEC_SINK_CAPS };

GST_DEBUG_CATEGORY_STATIC (ismd_gst_mpeg2_viddec_debug);
#define GST_CAT_DEFAULT ismd_gst_mpeg2_viddec_debug

enum
{
  PROP_VIDDEC_UNKNOWN,
  PROP_VIDDEC_OUTPUT_POLICY,
  PROP_VIDDEC_ERROR_POLICY,
  PROP_VIDDEC_INTERLACED,
  PROP_VIDDEC_GOPSIZE,
  PROP_VIDDEC_TRICK_RATE
};

#define DEFAULT_ISMD_VIDDEC_OUTPUT_POLICY ISMD_VIDDEC_DISPLAY_ORDER
#define DEFAULT_ISMD_VIDDEC_ERROR_POLICY  ISMD_VIDDEC_EMIT_ERROR_CONCEAL_FRAMES
#define DEFAULT_ISMD_VIDDEC_INTERLACED    FALSE
#define DEFAULT_GOPSIZE                   0

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_mpeg2_viddec_debug, "ISMD_MPEG2_VIDDEC",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstmpeg2viddec element");
}

GST_BOILERPLATE_FULL (ISmdGstMpeg2Viddec, ismd_gst_mpeg2_viddec,
    ISmdGstElement, ISMD_GST_TYPE_ELEMENT, _do_init);

static void
ismd_gst_mpeg2_viddec_drop_badframes (ISmdGstElement * smd_element,
    gboolean enable)
{
  ISmdGstMpeg2Viddec *viddec = ISMD_GST_MPEG2_VIDDEC (smd_element);
  ismd_viddec_frame_error_policy_t policy =
      ISMD_VIDDEC_EMIT_ERROR_CONCEAL_FRAMES;
  ismd_result_t result;
      
  GST_DEBUG_OBJECT (viddec, "drop on decoding errors set to: %d", enable);

  if (!enable) {
    policy = ISMD_VIDDEC_EMIT_ALL;
  }

  result = ismd_viddec_set_frame_error_policy (smd_element->dev_handle,
      policy);
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (viddec,
        "ismd_viddec_set_frame_error_policy failed(%d)", result);
  }

  viddec->drop_badframes = enable;
}

static GstPadLinkReturn
ismd_gst_mpeg2_viddec_sinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  GstStructure *structure;
  ISmdGstMpeg2Viddec *viddec;
  ISmdGstElement *parent;
  ismd_result_t result;
  gint mpegversion;
  GstPad *srcpad;
  GstCaps *srccaps;
  gboolean ret = FALSE;

  viddec = ISMD_GST_MPEG2_VIDDEC (gst_pad_get_parent (pad));
  parent = ISMD_GST_ELEMENT (viddec);

  GST_DEBUG_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  if (!(structure = gst_caps_get_structure (caps, 0))) {
    GST_ERROR_OBJECT (pad, "no caps found");
    goto beach;
  }

  if (gst_structure_has_name (structure, "video/mpeg") &&
      gst_structure_get_int (structure, "mpegversion", &mpegversion) &&
      (mpegversion == 2 || mpegversion == 1)) {
    viddec->vCodec = ISMD_CODEC_TYPE_MPEG2;
    // This is a failsafe call to insure that we are NOT in the Netflix PTS
    // re-ordering mode when dealing with non-VC1 content.  See ECR #200091
    result = ismd_viddec_disable_host_pts_reordering (parent->dev_handle);
    if (result != ISMD_SUCCESS)
      GST_WARNING_OBJECT (viddec,
          "Could not disable VC1 PTS re-ordering mode!");
  } else {
    goto beach;
  }

  ret = TRUE;
  srcpad = gst_element_get_static_pad (GST_ELEMENT (viddec), "src_1");
  srccaps = gst_caps_new_simple ("video/x-decoded-ismd", NULL);
  if (gst_pad_peer_accept_caps (srcpad, srccaps)) {
    GST_DEBUG_OBJECT (viddec, "setting caps downstream to %" GST_PTR_FORMAT,
        srccaps);
    ret = gst_pad_set_caps (srcpad, srccaps);
    if (G_UNLIKELY (!ret)) {
      GST_ERROR_OBJECT (viddec, "failed setting downstream caps to %"
          GST_PTR_FORMAT, srccaps);
    }
    else {
      GstTagList * taglist = gst_tag_list_new ();

      /* Post a tag with the codec name */
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_VIDEO_CODEC,
          "MPEG2 video", NULL);

      gst_element_found_tags_for_pad (GST_ELEMENT (viddec), srcpad, taglist);
    }
  }
  gst_caps_unref (srccaps);
  gst_object_unref (srcpad);

beach:
  gst_object_unref (viddec);
  return ret;
}

static void
ismd_gst_mpeg2_viddec_drain (ISmdGstElement * smd_element)
{
  ISmdGstMpeg2Viddec *viddec = ISMD_GST_MPEG2_VIDDEC (smd_element);
  ismd_result_t result;
  ismd_event_t event_handle;
  gint counter = 0;

  result = ismd_viddec_get_event (smd_element->dev_handle,
      ISMD_VIDDEC_CLIENT_ID_SEEN, &event_handle );
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (viddec, "ismd_viddec_get_event failed(%d)", result);
    goto beach;
  }

  while (result == ISMD_SUCCESS) {
    result = ismd_event_wait (event_handle, 50);
    if (result == ISMD_SUCCESS) {
      ismd_event_acknowledge (event_handle);
      counter = 0;
    }
    else if (result == ISMD_ERROR_TIMEOUT) {
      counter += 50;
      GST_LOG_OBJECT (viddec, "timeout %d", counter);
      if (counter < ISMD_POLL_TIMEOUT) {
        result = ISMD_SUCCESS;
      }
    }
    else {
      GST_WARNING_OBJECT (viddec, "ismd_event_wait failed(%d)", result);
    }
  }

beach:
  return;
}

static void
ismd_gst_viddec_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (object);
  ISmdGstMpeg2Viddec *viddec = ISMD_GST_MPEG2_VIDDEC(object);

  switch (prop_id) {
    case PROP_VIDDEC_OUTPUT_POLICY:
      g_value_set_enum (value, viddec->output_policy);
      break;
    case PROP_VIDDEC_ERROR_POLICY:
      g_value_set_enum (value, viddec->error_policy);
      break;
    case PROP_VIDDEC_INTERLACED:
      {
        ismd_result_t result;
        ismd_viddec_stream_properties_t smd_prop;
        result = ismd_viddec_get_stream_properties(smd_element->dev_handle, &smd_prop);
        if (ISMD_SUCCESS != result)
        {
          GST_ERROR_OBJECT(smd_element, "ismd_viddec_get_stream_properties failed :: dev_handle = %d\n", smd_element->dev_handle);
        }
        else
        {
          viddec->interlaced = smd_prop.is_stream_interlaced;
        }
      }
      g_value_set_boolean(value, viddec->interlaced);
      break;
    case PROP_VIDDEC_GOPSIZE:
      g_value_set_ulong(value, viddec->gopSize);
      break;
    case PROP_VIDDEC_TRICK_RATE:
      g_value_set_float(value, viddec->trick_rate);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_viddec_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstElement *smde = ISMD_GST_ELEMENT (object);
  ISmdGstMpeg2Viddec *viddec = ISMD_GST_MPEG2_VIDDEC(object);

  switch (prop_id) {
    case PROP_VIDDEC_OUTPUT_POLICY:
    {
      viddec->output_policy = g_value_get_enum (value);
      if (smde->dev_handle != ISMD_DEV_HANDLE_INVALID) {
        ismd_result_t res;
        res = ismd_viddec_set_frame_output_policy (smde->dev_handle, viddec->output_policy);
        if (G_UNLIKELY (res != ISMD_SUCCESS)) {
          GST_WARNING_OBJECT (viddec, "set_frame_output_policy failed");
        }
      }
      break;
    }
    case PROP_VIDDEC_ERROR_POLICY:
      viddec->error_policy = g_value_get_enum (value);
      if (smde->dev_handle != ISMD_DEV_HANDLE_INVALID) {
        ismd_result_t res;
        res = ismd_viddec_set_frame_error_policy (smde->dev_handle, viddec->error_policy);
        if (G_UNLIKELY (res != ISMD_SUCCESS)) {
          GST_WARNING_OBJECT (viddec, "set_frame_error_policy failed");
        }
      }
      break;
    case PROP_VIDDEC_INTERLACED:
      viddec->interlaced = g_value_get_boolean (value);
      break;
    case PROP_VIDDEC_GOPSIZE:
      viddec->gopSize = g_value_get_ulong(value);
      break;
    case PROP_VIDDEC_TRICK_RATE:
      {
        viddec->trick_rate = g_value_get_float(value);
        smde->segment.rate = (gdouble)viddec->trick_rate;
      }
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static gboolean
ismd_gst_mpeg2_viddec_event (ISmdGstElement * smd_element, GstEvent * event)
{
  ISmdGstMpeg2Viddec *viddec = ISMD_GST_MPEG2_VIDDEC (smd_element);

  switch (event->type) {
    case GST_EVENT_NEWSEGMENT:
      {
        ismd_viddec_frame_skip_policy_t mask;
        gdouble rate;
        gst_event_parse_new_segment (event, NULL, &rate, NULL, NULL,
            NULL, NULL);
        if (rate > 2.0 || rate < 0.0) {
          mask = ISMD_VIDDEC_SKIP_FRAME_TYPE_P | ISMD_VIDDEC_SKIP_FRAME_TYPE_B;
          GST_DEBUG_OBJECT (smd_element, "switch to only keyframe decoding mode");
        } else {
          mask = ISMD_VIDDEC_SKIP_NONE;
          GST_DEBUG_OBJECT (smd_element, "switch to normal decoding mode");
        }
        ismd_viddec_set_frame_mask (smd_element->dev_handle, mask);

        if(viddec->trick_rate < 0 )
        {
          ismd_viddec_frame_skip_policy_t mask;
          ismd_result_t result;
          ismd_viddec_frame_error_policy_t policy = ISMD_VIDDEC_EMIT_ERROR_CONCEAL_FRAMES;

          mask = ISMD_VIDDEC_SKIP_NONE;
          result = ismd_viddec_set_frame_mask(smd_element->dev_handle, mask);
          if (result != ISMD_SUCCESS)
          {
            GST_ERROR_OBJECT(smd_element, "could not set viddec frame_mask :: (%d)\n", result);
          }

          result = ismd_viddec_set_max_frames_to_decode (smd_element->dev_handle, ISMD_VIDDEC_ALL_FRAMES);
          if (result != ISMD_SUCCESS)
          {
            GST_ERROR_OBJECT(smd_element,"could not set viddec max_frames_to_decode :: (%d)\n", result);
          }

          result = ismd_viddec_set_frame_error_policy (smd_element->dev_handle, policy);
          if (result != ISMD_SUCCESS)
          {
            GST_ERROR_OBJECT(smd_element,"ismd_viddec_set_frame_error_policy failed :: (%d)\n", result);
          }
        }
      }
      break;
    case GST_EVENT_CUSTOM_DOWNSTREAM:
      {
        ismd_result_t result;
        const GstStructure *s = gst_event_get_structure (event);

        if (gst_structure_has_name (s, "GstGOPInfo")) {
          gint present_frames = 0;
          gst_structure_get_int (s, "present-frames", &present_frames);
          GST_DEBUG_OBJECT (smd_element, "going to present %d frames out"
              " of next GOP", present_frames);
          result =
              ismd_viddec_set_max_frames_to_decode (smd_element->dev_handle,
              present_frames == 0 ? ISMD_VIDDEC_ALL_FRAMES : present_frames);
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (smd_element,
                "could not set viddec max_frames_to_decode: %d", present_frames);
          }
        }              
      }
      break;
    case GST_EVENT_FLUSH_START:
      ismd_gst_mpeg2_viddec_drop_badframes (smd_element, TRUE);
      break;
    default:
      break;
  }
  return TRUE;
}

static GstStateChangeReturn
ismd_gst_mpeg2_viddec_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstMpeg2Viddec *viddec;
  viddec = ISMD_GST_MPEG2_VIDDEC (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ismd_result_t result;
  ISmdGstPad *gstpad;
  GList *padlist;

  GST_DEBUG_OBJECT (viddec,
      "devh:%d smd element default handler change state from %s to %s (%04x)",
      smd_element->dev_handle, gst_element_state_get_name ((GstState)
          GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)),
      transition);

  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
      // initialize the device but don't consume data
      result = ismd_viddec_open (viddec->vCodec, &(smd_element->dev_handle));
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "ismd_viddec_open failed(%d)", result);
        goto failure;
      }

      result =
          ismd_viddec_set_pts_interpolation_policy (smd_element->dev_handle,
          ISMD_VIDDEC_INTERPOLATE_MISSING_PTS, ISMD_NO_PTS);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec,
            "ismd_viddec_set_pts_interpolation_policy failed(%d)", result);
        goto failure;
      }

      result = ismd_viddec_set_frame_output_policy (smd_element->dev_handle, viddec->output_policy);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "viddec set output policy failed(%d)", result);
        goto failure;
      }

      result = ismd_viddec_get_input_port (smd_element->dev_handle,
          &(smd_element->sink_pad->ismd_port));
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "viddec get input port failed(%d)", result);
        goto failure;
      }

      padlist = smd_element->src_pads;
      gstpad = ISMD_GST_PAD (padlist->data);

      ismd_viddec_get_output_port (smd_element->dev_handle, &gstpad->ismd_port);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "viddec get output port failed(%d)", result);
        goto failure;
      }
      ismd_gst_mpeg2_viddec_drop_badframes (smd_element, TRUE);
      break;
    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
      if(viddec->trick_rate < 0.0)
      {
        ismd_viddec_set_pts_interpolation_policy (smd_element->dev_handle,ISMD_VIDDEC_INTERPOLATE_MISSING_PTS, ISMD_NO_PTS);

        if(viddec->trick_rate >= -2.0 && viddec->gopSize > 18)
        {
          GST_DEBUG_OBJECT(smd_element,"Smooth Reverse case with gopSize greater than 18. Skip b frames\n");
          ismd_viddec_frame_skip_policy_t mask;
          mask = ISMD_VIDDEC_SKIP_FRAME_TYPE_B;
          ismd_viddec_set_frame_mask(smd_element->dev_handle, mask);
        }
      }
      if(viddec->trick_rate > 2.0 || viddec->trick_rate < -2.0 )
      {
        GST_DEBUG_OBJECT(smd_element, "ISMD GST ELEMENT :: ismd_viddec_set_frame_mask :: xxxxxxxx :: dev_handle :: %d\n", smd_element->dev_handle);
        ismd_viddec_frame_skip_policy_t mask;
        mask = ISMD_VIDDEC_SKIP_FRAME_TYPE_P | ISMD_VIDDEC_SKIP_FRAME_TYPE_B;
        ismd_viddec_set_frame_mask (smd_element->dev_handle, mask);
      }
      break;
    default:
      break;
  }

  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
      ismd_gst_mpeg2_viddec_drop_badframes (smd_element, TRUE);
      break;
    case GST_STATE_CHANGE_READY_TO_NULL:
      ismd_dev_close(smd_element->dev_handle);
      smd_element->dev_handle = ISMD_DEV_HANDLE_INVALID;
      break;
    default:
      break;
  }

  return ret;

failure:
  return GST_STATE_CHANGE_FAILURE;
}

static GstFlowReturn
ismd_gst_mpeg2_viddec_push_buffer (ISmdGstElement * smd_element, GstPad * pad,
    GstBuffer * buf)
{
  GstFlowReturn ret = GST_FLOW_OK; 
  ISmdGstMpeg2Viddec *viddec = ISMD_GST_MPEG2_VIDDEC (smd_element);
  ismd_result_t result;

  /* don't reset the frame_error_policy if the trick rate is <0 */
  if (G_UNLIKELY (viddec->drop_badframes) && viddec->trick_rate >= 0) {
    result = ismd_viddec_set_frame_error_policy (smd_element->dev_handle, viddec->error_policy);
    if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (viddec, "set_frame_error_policy failed");
    }
    viddec->drop_badframes = false;
  }
  
  GST_DEBUG_OBJECT (viddec, "pushing buffer %p pts %" GST_TIME_FORMAT,
      buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)));
  ret = gst_pad_push (pad, buf);

  return ret;
}

static void
ismd_gst_mpeg2_viddec_base_init (gpointer klass)
{
  static GstElementDetails details = {
    "Intel Streaming Media Driver (ISMD) Hardware MPEG-2 Video Decoder",
    "Codec/Decoder/Video",
    "GStreamer Video Decoder Element for Intel Media Processors",
    "http://www.intelconsumerelectronics.com/"
  };

  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GstPadTemplate *curr_tmplt = NULL;
  gst_element_class_set_details (eclass, &details);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_mpeg2_viddec_sinkpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_mpeg2_viddec_srcpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);
}

static void
ismd_gst_mpeg2_viddec_class_init (ISmdGstMpeg2ViddecClass * klass)
{
  GObjectClass *oclass;
  oclass = G_OBJECT_CLASS (klass);
  GstElementClass *eclass;
  eclass = GST_ELEMENT_CLASS (klass);
  ISmdGstElementClass *iclass;
  iclass = ISMD_GST_ELEMENT_CLASS (klass);

  oclass->get_property = ismd_gst_viddec_get_property;
  oclass->set_property = ismd_gst_viddec_set_property;

  g_object_class_install_property (oclass, PROP_VIDDEC_OUTPUT_POLICY,
      g_param_spec_enum ("output-policy",
          "Output Policy",
          "Define the output policy used by the video decoder",
          GST_TYPE_ISMD_VIDDEC_OUTPUT_POLICY,
          DEFAULT_ISMD_VIDDEC_OUTPUT_POLICY, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDDEC_ERROR_POLICY,
      g_param_spec_enum ("error-policy",
          "Error Policy",
          "Define the error policy used by the video decoder",
          GST_TYPE_ISMD_VIDDEC_ERROR_POLICY,
          DEFAULT_ISMD_VIDDEC_ERROR_POLICY, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDDEC_INTERLACED,
      g_param_spec_boolean ("interlaced",
          "interlaced",
          "sets the flag for interlaced streams",
          DEFAULT_ISMD_VIDDEC_INTERLACED, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDDEC_GOPSIZE,
      g_param_spec_ulong("gopsize", "gopsize as long",
          "Allows setting the GOP size if it is known by the calling application. \
           The GOP size is used during smooth reverse trick play to determine \
           whether or not to skip B-frames", 0, 50, DEFAULT_GOPSIZE,G_PARAM_WRITABLE));

  g_object_class_install_property (oclass, PROP_VIDDEC_TRICK_RATE,
      g_param_spec_float ("trick rate", "rewind rate in normalised form( > -20000)",
      "rewind rate in normalised form( > -20000)", -20000.0,20000.0,0.0, G_PARAM_READWRITE));

  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_mpeg2_viddec_change_state);
  iclass->event = GST_DEBUG_FUNCPTR (ismd_gst_mpeg2_viddec_event);
  iclass->drain = ismd_gst_mpeg2_viddec_drain;
  iclass->push_buffer = GST_DEBUG_FUNCPTR (ismd_gst_mpeg2_viddec_push_buffer);
  iclass->is_decoder = TRUE;
}

static void
ismd_gst_mpeg2_viddec_init (ISmdGstMpeg2Viddec * viddec,
    ISmdGstMpeg2ViddecClass * klass)
{
  GstPad *pad;

  ismd_gst_element_create_pads (ISMD_GST_ELEMENT (viddec), &sinkcap,
      &srccap, 1);

  pad = gst_element_get_static_pad (GST_ELEMENT (viddec), "sink");
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_mpeg2_viddec_sinkpad_setcaps));
  gst_object_unref (pad);

  viddec->output_policy = DEFAULT_ISMD_VIDDEC_OUTPUT_POLICY;
  viddec->error_policy = DEFAULT_ISMD_VIDDEC_ERROR_POLICY;
  viddec->vCodec = ISMD_CODEC_TYPE_MPEG2;
  viddec->interlaced = DEFAULT_ISMD_VIDDEC_INTERLACED;
  viddec->trick_rate = 0.0;
}


