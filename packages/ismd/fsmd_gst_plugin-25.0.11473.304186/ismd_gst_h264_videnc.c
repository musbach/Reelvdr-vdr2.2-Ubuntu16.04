/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright (c) 2011. Intel Corporation. All rights reserved.


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

    Copyright (c) 2011. Intel Corporation. All rights reserved.


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
#include "ismd_gst_element.h"
#include "ismd_gst_h264_videnc.h"

#define ISMD_GST_H264_VIDENC_VIDEO_SINK_CAPS \
           "video/x-decoded-ismd; " \
           "video/x-raw-ismd; " \
           "video/x-raw-yuv, " \
           "  format = (fourcc) {NV12, NV16}, " \
           "  width = (int) [48,1920], " \
           "  height = (int) [48,1088]; " 

#define ISMD_GST_H264_VIDENC_SRC_CAPS \
           "video/x-h264"

static GstStaticPadTemplate ismd_gst_h264_videnc_video_sinkpad_template =
GST_STATIC_PAD_TEMPLATE ("sink_1",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_H264_VIDENC_VIDEO_SINK_CAPS)
    );

static GstStaticPadTemplate ismd_gst_h264_videnc_userdata_sinkpad_template =
GST_STATIC_PAD_TEMPLATE ("sink_2",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);


static GstStaticPadTemplate ismd_gst_h264_videnc_srcpad_template =
GST_STATIC_PAD_TEMPLATE ("src_1",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_H264_VIDENC_SRC_CAPS)
    );

static GstStaticCaps srccap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_H264_VIDENC_SRC_CAPS };
static GstStaticCaps sinkcap_1 =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_H264_VIDENC_VIDEO_SINK_CAPS };
static GstStaticCaps sinkcap_2 =
    { {0, 0, (GstCapsFlags) 0}, "ANY" };


#define H264_VIDENC_MAX_BITRATE 50000000

/* ISmdGstH264Videnc properties */
#define DEFAULT_H264_VIDENC_CODEC_PROFILE           		ISMD_VIDENC_H264_PROFILE_HIGH
#define DEFAULT_H264_VIDENC_CODEC_LEVEL                   	ISMD_VIDENC_H264_LEVEL_4_1
#define DEFAULT_H264_VIDENC_ENTROPY_MODE                 	ISMD_VIDENC_H264_ENTROPY_MODE_CABAC
#define DEFAULT_H264_VIDENC_CHROMA_FORMAT               	ISMD_VIDENC_H264_CHROMA_FORMAT_4_2_0
#define DEFAULT_H264_VIDENC_ASPECT_RATIO                        ISMD_VIDENC_H264_ASPECT_RATIO_AUTO
#define DEFAULT_H264_VIDENC_RATE_CONTROL_MODE                   ISMD_VIDENC_H264_RATE_CONTROL_VBR
#define DEFAULT_H264_VIDENC_MAX_BITRATE                     	15000000
#define DEFAULT_H264_VIDENC_TARGET_BITRATE                 	10000000
#define DEFAULT_H264_VIDENC_GOP_LENGTH                  	24
#define DEFAULT_H264_VIDENC_GOP_NUM_OF_B_FRAME           	0
#define DEFAULT_H264_VIDENC_IDR_FREQUENCE               	0
#define DEFAULT_H264_VIDENC_SCALING_LIST                 	ISMD_VIDENC_H264_SCALING_LIST_FLAT
#define DEFAULT_H264_VIDENC_QP_MODE				ISMD_VIDENC_H264_QP_UNIFORM		

enum
{
  PROP_H264_VIDENC_UNKNOWN,
  PROP_H264_VIDENC_CODEC_PROFILE,
  PROP_H264_VIDENC_CODEC_LEVEL,
  PROP_H264_VIDENC_ENTROPY_MODE,
  PROP_H264_VIDENC_CHROMA_FORMAT,
  PROP_H264_VIDENC_ASPECT_RATIO,
  PROP_H264_VIDENC_RATE_CONTROL_MODE,
  PROP_H264_VIDENC_MAX_BITRATE,
  PROP_H264_VIDENC_TARGET_BITRATE,
  PROP_H264_VIDENC_GOP_LENGTH,
  PROP_H264_VIDENC_GOP_NUM_0F_B_FRAME,
  PROP_H264_VIDENC_IDR_FREQUENCE,
  PROP_H264_VIDENC_SCALING_LIST,
  PROP_H264_VIDENC_QP_MODE,
  PROP_H264_VIDENC_LAST,
};

#define GST_TYPE_ISMD_H264_VIDENC_CODEC_PROFILE \
  (ismd_gst_h264_videnc_codec_profile_get_type())
#define GST_TYPE_ISMD_H264_VIDENC_CODEC_LEVEL \
  (ismd_gst_h264_videnc_codec_level_get_type())
#define GST_TYPE_ISMD_H264_VIDENC_ASPECT_RATIO \
  (ismd_gst_h264_videnc_aspect_ratio_get_type())
#define GST_TYPE_ISMD_H264_VIDENC_SCALING_LIST \
  (ismd_gst_h264_videnc_scaling_list_get_type())

GST_DEBUG_CATEGORY_STATIC (ismd_gst_h264_videnc_debug);
#define GST_CAT_DEFAULT ismd_gst_h264_videnc_debug

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_h264_videnc_debug, "ISMD_H264_VIDENC",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgsth264videnc element");
}

GST_BOILERPLATE_FULL (ISmdGstH264Videnc, ismd_gst_h264_videnc,
    ISmdGstElement, ISMD_GST_TYPE_ELEMENT, _do_init);

GType
ismd_gst_h264_videnc_codec_profile_get_type (void)
{
  static GType ismd_gst_h264_videnc_codec_profile_type = 0;
  static const GEnumValue codec_profile_types[] = {
    {ISMD_VIDENC_H264_PROFILE_BASELINE, "H264 base profile", "Base"},
    {ISMD_VIDENC_H264_PROFILE_MAIN, "H264 main profile", "Main"},
    {ISMD_VIDENC_H264_PROFILE_HIGH, "H264 high profile", "High"},
    {10, NULL, NULL}
  };
  if (!ismd_gst_h264_videnc_codec_profile_type) {
    ismd_gst_h264_videnc_codec_profile_type =
        g_enum_register_static ("GstIsmdH264VidencCodecProfile", codec_profile_types);
  }
  return ismd_gst_h264_videnc_codec_profile_type;
}

GType
ismd_gst_h264_videnc_codec_level_get_type (void)
{
  static GType ismd_gst_h264_videnc_codec_level_type = 0;
  static const GEnumValue codec_level_types[] = {
    {ISMD_VIDENC_H264_LEVEL_1_0B, "H264 Level 1.0B", "L 1.0B"},
    {ISMD_VIDENC_H264_LEVEL_1_0, "H264 Level 1.0", "L 1.0"},
    {ISMD_VIDENC_H264_LEVEL_1_1, "H264 Level 1.1", "L 1.1"},
    {ISMD_VIDENC_H264_LEVEL_1_2, "H264 Level 1.2", "L 1.2"},
    {ISMD_VIDENC_H264_LEVEL_1_3, "H264 Level 1.3", "L 1.3"},
    {ISMD_VIDENC_H264_LEVEL_2_0, "H264 Level 2.0", "L 2.0"},
    {ISMD_VIDENC_H264_LEVEL_2_1, "H264 Level 2.1", "L 2.1"},
    {ISMD_VIDENC_H264_LEVEL_2_2, "H264 Level 2.2", "L 2.2"},
    {ISMD_VIDENC_H264_LEVEL_3_0, "H264 Level 3.0", "L 3.0"},
    {ISMD_VIDENC_H264_LEVEL_3_1, "H264 Level 3.1", "L 3.1"},
    {ISMD_VIDENC_H264_LEVEL_3_2, "H264 Level 3.2", "L 3.2"},
    {ISMD_VIDENC_H264_LEVEL_4_0, "H264 Level 4.0", "L 4.0"},
    {ISMD_VIDENC_H264_LEVEL_4_1, "H264 Level 4.1", "L 4.1"},
    {10, NULL, NULL}
  };
  if (!ismd_gst_h264_videnc_codec_level_type) {
    ismd_gst_h264_videnc_codec_level_type =
        g_enum_register_static ("GstIsmdH264VidencCodecLevel", codec_level_types);
  }
  return ismd_gst_h264_videnc_codec_level_type;
}

GType
ismd_gst_h264_videnc_aspect_ratio_get_type (void)
{
  static GType ismd_gst_h264_videnc_aspect_ratio_type = 0;
  static const GEnumValue aspect_ratio_types[] = {
    {ISMD_VIDENC_H264_ASPECT_RATIO_AUTO, "Encoding aspect ratio auto", "AUTO"},
    {ISMD_VIDENC_H264_ASPECT_RATIO_4_3, "Encoding aspect ratio 4:3", "4_3"},
    {ISMD_VIDENC_H264_ASPECT_RATIO_16_9, "Encoding aspect ratio 16:9", "16_9"},
    {ISMD_VIDENC_H264_ASPECT_RATIO_NONE, "Encoding aspect ratio not be present in the stream", "NONE"},
    {ISMD_VIDENC_H264_ASPECT_RATIO_SAME_AS_INPUT, "Encoding aspect ratio as in the input if supported, otherwise will use NONE", "SAME_AS_INPUT"},
    {10, NULL, NULL}
  };

  if (!ismd_gst_h264_videnc_aspect_ratio_type) {
    ismd_gst_h264_videnc_aspect_ratio_type =
        g_enum_register_static ("GstIsmdH264VidencAspectRatio", aspect_ratio_types);
  }
  return ismd_gst_h264_videnc_aspect_ratio_type;
}

GType
ismd_gst_h264_videnc_scaling_list_get_type (void)
{
  static GType ismd_gst_h264_videnc_scaling_list_type = 0;
  static const GEnumValue scaling_list_types[] = {
    {ISMD_VIDENC_H264_SCALING_LIST_FLAT, "Use flat scaling list", "flat"},
    {ISMD_VIDENC_H264_SCALING_LIST_DEFAULT, "Use default scaling list. High profile only", "default"},
    {ISMD_VIDENC_H264_SCALING_LIST_INTEL_CUSTOM, "Use custom scaling list. High profile only", "custom"},
    {10, NULL, NULL}
  };

  if (!ismd_gst_h264_videnc_scaling_list_type) {
    ismd_gst_h264_videnc_scaling_list_type =
        g_enum_register_static ("GstIsmdH264VidencScalingList", scaling_list_types);
  }
  return ismd_gst_h264_videnc_scaling_list_type;
}

static GstPadLinkReturn
ismd_gst_h264_videnc_sinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  GstStructure *structure;
  ISmdGstH264Videnc *videnc;
  GstPad *srcpad;
  GstCaps *srccaps;
  gboolean ret = FALSE;
  const GValue * par;
  gint aspect_x = 1, aspect_y = 1;

  videnc = ISMD_GST_H264_VIDENC (gst_pad_get_parent (pad));

  GST_DEBUG_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  if (!(structure = gst_caps_get_structure (caps, 0))) {
    GST_ERROR_OBJECT (pad, "no caps found");
    goto beach;
  }
  
  if (gst_structure_has_name (structure, "video/x-raw-yuv") || 
		gst_structure_has_name (structure, "video/x-decoded-ismd") ||
		gst_structure_has_name (structure, "video/x-raw-ismd")) {

    videnc->vCodec = ISMD_CODEC_TYPE_H264;

    par = gst_structure_get_value (structure, "pixel-aspect-ratio");
    if (par) {
      aspect_x = gst_value_get_fraction_numerator (par);
      aspect_y = gst_value_get_fraction_denominator (par);
    }
  
    srcpad = gst_element_get_static_pad (GST_ELEMENT (videnc), "src_1");
    srccaps = gst_caps_new_simple ("video/x-h264",
      "pixel-aspect-ratio", GST_TYPE_FRACTION, aspect_x, aspect_y, NULL);
    if (gst_pad_peer_accept_caps (srcpad, srccaps)) {
      GST_DEBUG_OBJECT (videnc, "setting caps downstream to %" GST_PTR_FORMAT,
        srccaps);
      ret = gst_pad_set_caps (srcpad, srccaps);
      if (G_UNLIKELY (!ret)) {
        GST_ERROR_OBJECT (videnc, "failed setting downstream caps to %"
          GST_PTR_FORMAT, srccaps);
      }
      else {
        GstTagList * taglist = gst_tag_list_new ();

        /* Post a tag with the codec name */
        gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_VIDEO_CODEC,
          "H.264/AVC video", NULL);

        gst_element_found_tags_for_pad (GST_ELEMENT (videnc), srcpad, taglist);
      }
    }
    gst_caps_unref (srccaps);
    gst_object_unref (srcpad);
  }

beach:
  gst_object_unref (videnc);
  return ret;
}

static void
ismd_gst_h264_videnc_drain (ISmdGstElement * smd_element)
{
  ISmdGstH264Videnc *videnc = ISMD_GST_H264_VIDENC (smd_element);
  ismd_result_t result;
  ismd_event_t event_handle;
  gint counter = 0;

  result = ismd_videnc_get_event (smd_element->dev_handle,
      ISMD_VIDENC_CLIENT_ID_SEEN, &event_handle );
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (videnc, "ismd_videnc_get_event failed(%d)", result);
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
      GST_LOG_OBJECT (videnc, "timeout %d", counter);
      if (counter < ISMD_POLL_TIMEOUT) {
        result = ISMD_SUCCESS;
      }
    }
    else {
      GST_WARNING_OBJECT (videnc, "ismd_event_wait failed(%d)", result);
    }
  }

beach:
  return;
}


static GstStateChangeReturn
ismd_gst_h264_videnc_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstH264Videnc *videnc;
  videnc = ISMD_GST_H264_VIDENC (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ismd_result_t result;
  ISmdGstPad *gstpad;
  ISmdGstElementSinkPad *pad_node_data; 
  GList *padlist_sink;
  GList *padlist_src;

  GST_DEBUG_OBJECT (videnc,
      "devh:%d smd element default handler change state from %s to %s (%04x)",
      smd_element->dev_handle, gst_element_state_get_name ((GstState)
          GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)),
      transition);

  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
      	{
        // initialize the device but don't consume data
        ismd_videnc_stream_init_params_t stream_params;
        stream_params.max_frame_height = 0;
        stream_params.max_frame_width = 0;
        stream_params.scene_change_control.scene_change_detect_enabled= FALSE;
        stream_params.scene_change_control.lookahead_count= 0;

         /* Setting H264 codec parameters */
        ismd_videnc_codec_init_params_t codec_params;
        codec_params.h264_init_params.profile = videnc->codec_profile;
        codec_params.h264_init_params.level = videnc->codec_level;

        result = ismd_videnc_open (videnc->vCodec, &stream_params, &codec_params, &(smd_element->dev_handle));
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (videnc, "ismd_videnc_open failed(%d)", result);
          goto failure;
        }

	  /* Video sink pad */
	  padlist_sink = smd_element->sink_pads;
	  pad_node_data =  padlist_sink->data;
        result = ismd_videnc_get_input_port (smd_element->dev_handle, &(pad_node_data->sink_pad->ismd_port));
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (videnc, "videnc get input port failed(%d)", result);
          goto failure;
        }

        /* User data sink pad */
        if ((padlist_sink = g_list_next (padlist_sink)) != NULL) {
	    pad_node_data =  padlist_sink->data;
	    result = ismd_videnc_get_user_data_port (smd_element->dev_handle, &(pad_node_data->sink_pad->ismd_port));
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (videnc, "videnc get user data port failed(%d)", result);
            goto failure;
          }
        }

	  /* Src pad */
        padlist_src = smd_element->src_pads;
        gstpad = ISMD_GST_PAD (padlist_src->data);
        ismd_videnc_get_output_port (smd_element->dev_handle, &(gstpad->ismd_port));
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (videnc, "videnc get output port failed(%d)", result);
          goto failure;
        }

        /* Setting encoder parameters */
	  ismd_videnc_h264_encoder_params_t h264_enc_params;
        h264_enc_params.chroma_format = videnc->chroma_format;
        h264_enc_params.aspect_ratio = videnc->aspect_ratio;
        h264_enc_params.entropy = videnc->entropy_mode;
        h264_enc_params.bitrate_settings.bitrate_mode = videnc->rate_control_mode;
        h264_enc_params.bitrate_settings.max_bitrate = videnc->max_bitrate;
        h264_enc_params.bitrate_settings.bitrate = videnc->target_bitrate;
        h264_enc_params.gop_settings.GOP_length = videnc->gop_length;
        h264_enc_params.gop_settings.num_of_B_frames = videnc->gop_num_of_B_frame;
        h264_enc_params.gop_settings.IDR_Frequency = videnc->idr_frequence;
        h264_enc_params.scaling_list = videnc->scaling_list;
        h264_enc_params.qp_mode = videnc->qp_mode;
        result = ismd_videnc_h264_set_encoding_params(smd_element->dev_handle, &h264_enc_params);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (videnc, "ismd_videnc_h264_set_encoding_params(%d)", result);
          goto failure;
        }

        videnc->reuse_input_end_sequence = TRUE;
        result = ismd_videnc_set_reuse_input_end_sequence(smd_element->dev_handle, videnc->reuse_input_end_sequence);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (videnc, "ismd_videnc_set_reuse_input_end_sequence(%d)", result);
          goto failure;
        }

	  /* Setting encoding policies*/
        ismd_videnc_per_input_encoding_policies_t encoding_policies;
        encoding_policies.interlaced_input_encoding_scan_mode = ISMD_VIDENC_SCAN_MODE_ENCODE_INTERLACED_FIELD;
        encoding_policies.interlaced_input_flags = ISMD_VIDENC_INPUT_INTERLACED_FLAGS_DO_PULLDOWN;
        encoding_policies.progressive_input_encoding_scan_mode = ISMD_VIDENC_SCAN_MODE_ENCODE_PROGRESSIVE;
        encoding_policies.progressive_input_flags = ISMD_VIDENC_INPUT_PROGRESSIVE_FLAGS_HALVE_FRAME_RATE;
        encoding_policies.deinterlaced_input_encoding_scan_mode = ISMD_VIDENC_SCAN_MODE_ENCODE_PROGRESSIVE;
        encoding_policies.deinterlaced_input_flags = ISMD_VIDENC_INPUT_DEINTERLACED_FLAGS_DOUBLE_FRAME_RATE_PROGRESSIVE;
        result = ismd_videnc_set_per_input_encoding_policies(smd_element->dev_handle, &encoding_policies);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (videnc, "ismd_videnc_set_per_input_encoding_policies(%d)", result);
          goto failure;
        }
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
      //ismd_gst_mpeg4_viddec_drop_badframes (smd_element, TRUE);
      break;
    default:
      break;
  }

  return ret;

failure:
  return GST_STATE_CHANGE_FAILURE;
}

static GstFlowReturn
ismd_gst_h264_videnc_push_buffer (ISmdGstElement * smd_element, GstPad * pad,
    GstBuffer * buf)
{
  GstFlowReturn ret = GST_FLOW_OK; 
  ISmdGstH264Videnc *videnc = ISMD_GST_H264_VIDENC (smd_element);

  GST_DEBUG_OBJECT (videnc, "pushing buffer %p pts %" GST_TIME_FORMAT,
      buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)));
  ret = gst_pad_push (pad, buf);

  return ret;
}

static void
ismd_gst_h264_videnc_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstH264Videnc *videnc = ISMD_GST_H264_VIDENC (object);

  switch (prop_id) {
    case PROP_H264_VIDENC_CODEC_PROFILE:
      videnc->codec_profile = g_value_get_enum(value);
      break;
    case PROP_H264_VIDENC_CODEC_LEVEL:
      videnc->codec_level = g_value_get_enum(value);
      break;
    case PROP_H264_VIDENC_ASPECT_RATIO:
	videnc->aspect_ratio = g_value_get_enum(value);
	break;
    case PROP_H264_VIDENC_SCALING_LIST:
      videnc->scaling_list = g_value_get_enum(value);
      break; 
    case PROP_H264_VIDENC_ENTROPY_MODE:
      videnc->entropy_mode = g_value_get_boolean(value);
      break;
    case PROP_H264_VIDENC_CHROMA_FORMAT:
      videnc->chroma_format = g_value_get_boolean(value);
      break;
    case PROP_H264_VIDENC_RATE_CONTROL_MODE:
      videnc->rate_control_mode = g_value_get_boolean(value);
      break;
    case PROP_H264_VIDENC_QP_MODE:
      videnc->qp_mode = g_value_get_boolean(value);
      break;
    case PROP_H264_VIDENC_MAX_BITRATE:
	videnc->max_bitrate= g_value_get_uint(value);
	break;
    case PROP_H264_VIDENC_TARGET_BITRATE:
      videnc->target_bitrate = g_value_get_uint(value);
      break;
    case PROP_H264_VIDENC_GOP_LENGTH:
      videnc->gop_length = g_value_get_uint(value);
      break;
    case PROP_H264_VIDENC_GOP_NUM_0F_B_FRAME:
      videnc->gop_num_of_B_frame= g_value_get_uint(value);
      break;
    case PROP_H264_VIDENC_IDR_FREQUENCE:
      videnc->idr_frequence= g_value_get_uint(value);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_h264_videnc_get_property (GObject * object, guint prop_id, 
    GValue * value, GParamSpec * pspec)
{
  ISmdGstH264Videnc *videnc = ISMD_GST_H264_VIDENC (object);

  switch (prop_id) {
    case PROP_H264_VIDENC_CODEC_PROFILE:
      g_value_set_enum (value, videnc->codec_profile);
      break;
    case PROP_H264_VIDENC_CODEC_LEVEL:
      g_value_set_enum (value, videnc->codec_level);
      break;
    case PROP_H264_VIDENC_ASPECT_RATIO:
	g_value_set_enum (value, videnc->aspect_ratio);
	break;
    case PROP_H264_VIDENC_SCALING_LIST:
      g_value_set_enum (value, videnc->scaling_list);
      break;
    case PROP_H264_VIDENC_ENTROPY_MODE:
      g_value_set_boolean (value, videnc->entropy_mode);
      break;
    case PROP_H264_VIDENC_CHROMA_FORMAT:
      g_value_set_boolean (value, videnc->chroma_format);
      break;
    case PROP_H264_VIDENC_RATE_CONTROL_MODE:
      g_value_set_boolean (value, videnc->rate_control_mode);
      break;
    case PROP_H264_VIDENC_QP_MODE:
      g_value_set_boolean (value, videnc->qp_mode);
      break;
    case PROP_H264_VIDENC_MAX_BITRATE:
			g_value_set_uint (value, videnc->max_bitrate);
			break;
    case PROP_H264_VIDENC_TARGET_BITRATE:
      g_value_set_uint (value, videnc->target_bitrate);
      break;
    case PROP_H264_VIDENC_GOP_LENGTH:
      g_value_set_uint (value, videnc->gop_length);
      break;
    case PROP_H264_VIDENC_GOP_NUM_0F_B_FRAME:
      g_value_set_uint (value, videnc->gop_num_of_B_frame);
      break;
    case PROP_H264_VIDENC_IDR_FREQUENCE:
      g_value_set_uint (value, videnc->idr_frequence);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_h264_videnc_base_init (gpointer klass)
{
  static GstElementDetails details = {
    "Intel Streaming Media Driver (ISMD) Hardware H.264 Video Encoder",
    "Codec/Encoder/Video",
    "GStreamer Video Encoder Element for Intel Media Processors",
    "http://www.intelconsumerelectronics.com/"
  };

  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GstPadTemplate *curr_tmplt = NULL;
  gst_element_class_set_details (eclass, &details);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_h264_videnc_video_sinkpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);

    curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_h264_videnc_userdata_sinkpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_h264_videnc_srcpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);
}

static void
ismd_gst_h264_videnc_class_init (ISmdGstH264VidencClass * klass)
{
  GObjectClass *oclass;
  oclass = G_OBJECT_CLASS (klass);
  GstElementClass *eclass;
  eclass = GST_ELEMENT_CLASS (klass);
  ISmdGstElementClass *iclass;
  iclass = ISMD_GST_ELEMENT_CLASS (klass);
  
  oclass->set_property = GST_DEBUG_FUNCPTR(ismd_gst_h264_videnc_set_property);
  oclass->get_property = GST_DEBUG_FUNCPTR(ismd_gst_h264_videnc_get_property);

  /* Add property for enum */
  g_object_class_install_property (oclass, PROP_H264_VIDENC_CODEC_PROFILE,
      g_param_spec_enum ("codec-profile", "Codec Profile", 
          "H.264 Encoding profiles", GST_TYPE_ISMD_H264_VIDENC_CODEC_PROFILE, 
          DEFAULT_H264_VIDENC_CODEC_PROFILE, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_CODEC_LEVEL,
      g_param_spec_enum ("codec-level", "Codec Level", 
          "H.264 Encoding level", GST_TYPE_ISMD_H264_VIDENC_CODEC_LEVEL,
          DEFAULT_H264_VIDENC_CODEC_LEVEL, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_ASPECT_RATIO,
      g_param_spec_enum ("aspect-ratio", "Aspect Ratio", 
          "Encoding aspect ratio", GST_TYPE_ISMD_H264_VIDENC_ASPECT_RATIO,
          DEFAULT_H264_VIDENC_ASPECT_RATIO, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_SCALING_LIST,
      g_param_spec_enum ("scaling-list", "Scaling List", 
          "Encoding scaling list", GST_TYPE_ISMD_H264_VIDENC_SCALING_LIST,
          DEFAULT_H264_VIDENC_SCALING_LIST, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  /* Add property for bool */
  g_object_class_install_property (oclass, PROP_H264_VIDENC_ENTROPY_MODE,
      g_param_spec_boolean ("entropy-mode", "Entropy Mode",
          "Encoding rate entropy mode. 0: cavlc entropy mode, 1: cabac entropy mode - this is only for main and high profiles",
          DEFAULT_H264_VIDENC_ENTROPY_MODE, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_CHROMA_FORMAT,
      g_param_spec_boolean ("chroma-mode", "Chroma Mode",
          "Encoding rate chroma format. 0: Output stream will be monochrome. This is only allowed for HIGH profile, 1: Chroma format of output stream will be 4:2:0", DEFAULT_H264_VIDENC_CHROMA_FORMAT, 
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_RATE_CONTROL_MODE,
      g_param_spec_boolean ("rate-control-mode", "Rate Control Mode",
          "Encoding rate control mode. 0: Constant bit rate, 1: Variable bit rate",
          DEFAULT_H264_VIDENC_RATE_CONTROL_MODE, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));


  g_object_class_install_property (oclass, PROP_H264_VIDENC_QP_MODE,
      g_param_spec_boolean ("qp-mode", "QP Mode",
          "Lambda parameters. 0: Use the same QP for the entire picture, 1: Autoselect QP for each macro block",
          DEFAULT_H264_VIDENC_QP_MODE, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  /* Add property for uint */
  g_object_class_install_property (oclass, PROP_H264_VIDENC_MAX_BITRATE,
      g_param_spec_uint ("max-bitrate", "Max Bitrate", 
          "Maximum bit rate allowed in bits/sec", 0, H264_VIDENC_MAX_BITRATE, DEFAULT_H264_VIDENC_MAX_BITRATE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  
  g_object_class_install_property (oclass, PROP_H264_VIDENC_TARGET_BITRATE,
      g_param_spec_uint ("target-bitrate", "Target Bitrate", 
          "Target bit rate in bits/sec", 0, H264_VIDENC_MAX_BITRATE, DEFAULT_H264_VIDENC_TARGET_BITRATE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_GOP_LENGTH,
      g_param_spec_uint ("gop-length", "GOP Length", 
          "GOP length in Frame including the I picture", 0, 1000, DEFAULT_H264_VIDENC_GOP_LENGTH,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_GOP_NUM_0F_B_FRAME,
      g_param_spec_uint ("num-of-B-frame", "Num Of B Frame", 
          "Maximum number of consecutive B Frame in a GOP", 0, 2, DEFAULT_H264_VIDENC_GOP_NUM_OF_B_FRAME,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_H264_VIDENC_IDR_FREQUENCE,
      g_param_spec_uint ("IDR-frequence", "IDR Frequence", 
          "Number of frame between 2 IDR pictures", 0, 0xffffffff, DEFAULT_H264_VIDENC_IDR_FREQUENCE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
 
  
  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_h264_videnc_change_state);
  iclass->drain = GST_DEBUG_FUNCPTR (ismd_gst_h264_videnc_drain);
  iclass->push_buffer = GST_DEBUG_FUNCPTR (ismd_gst_h264_videnc_push_buffer);
  iclass->is_decoder = FALSE;
  iclass->is_vidio_enc = TRUE;
}

static void
ismd_gst_h264_videnc_init (ISmdGstH264Videnc * videnc,
    ISmdGstH264VidencClass * klass)
{
  ISmdGstElement *smd_element;
  GstPadTemplate *template;
  ISmdGstPad *pad;
  gchar *name;
  GstPad *gst_pad;
  
  smd_element = ISMD_GST_ELEMENT (videnc);
 
  // Create the sink_1 pad.
  name = g_strdup_printf ("sink_1");
  template =
      gst_pad_template_new ("sink", GST_PAD_SINK, GST_PAD_ALWAYS,
      gst_static_caps_get (&sinkcap_1));
  pad = ismd_gst_pad_new_from_template (template, name);
  gst_object_unref (template);
  g_free (name);
  ismd_gst_element_register_sinkpad (smd_element, pad);
  gst_element_add_pad (GST_ELEMENT (smd_element), GST_PAD (pad));

  // Create the sink_2 pad.
  name = g_strdup_printf ("sink_2");
  template =
      gst_pad_template_new ("sink", GST_PAD_SINK, GST_PAD_ALWAYS,
      gst_static_caps_get (&sinkcap_2));
  pad = ismd_gst_pad_new_from_template (template, name);
  gst_object_unref (template);
  g_free (name);
  ismd_gst_element_register_sinkpad (smd_element, pad);
  gst_element_add_pad (GST_ELEMENT (smd_element), GST_PAD (pad));

  // Create the src pad.
  name = g_strdup_printf ("src_1");
  template =
      gst_pad_template_new ("src", GST_PAD_SRC, GST_PAD_ALWAYS,
      gst_static_caps_get (&srccap));
  pad = ismd_gst_pad_new_from_template (template, name);
  gst_object_unref (template);
  g_free (name);
  ismd_gst_element_register_srcpad (smd_element, pad);
  gst_element_add_pad (GST_ELEMENT (smd_element), GST_PAD (pad));
  
  gst_pad = gst_element_get_static_pad (GST_ELEMENT (videnc), "sink_1");
  gst_pad_set_setcaps_function (gst_pad,
      GST_DEBUG_FUNCPTR (ismd_gst_h264_videnc_sinkpad_setcaps));
  gst_object_unref (gst_pad);

  videnc->vCodec = ISMD_CODEC_TYPE_H264;
  videnc->reuse_input_end_sequence = TRUE;
  videnc->codec_profile = DEFAULT_H264_VIDENC_CODEC_PROFILE;
  videnc->codec_level = DEFAULT_H264_VIDENC_CODEC_LEVEL;
  videnc->aspect_ratio = DEFAULT_H264_VIDENC_ASPECT_RATIO;
  videnc->scaling_list = DEFAULT_H264_VIDENC_SCALING_LIST;
  videnc->entropy_mode = DEFAULT_H264_VIDENC_ENTROPY_MODE;
  videnc->chroma_format = DEFAULT_H264_VIDENC_CHROMA_FORMAT;
  videnc->rate_control_mode = DEFAULT_H264_VIDENC_RATE_CONTROL_MODE;
  videnc->qp_mode = DEFAULT_H264_VIDENC_QP_MODE;
  videnc->max_bitrate = DEFAULT_H264_VIDENC_MAX_BITRATE;
  videnc->target_bitrate = DEFAULT_H264_VIDENC_TARGET_BITRATE;
  videnc->gop_length = DEFAULT_H264_VIDENC_GOP_LENGTH;
  videnc->gop_num_of_B_frame = DEFAULT_H264_VIDENC_GOP_NUM_OF_B_FRAME;
  videnc->idr_frequence = DEFAULT_H264_VIDENC_IDR_FREQUENCE;
}


