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

#include "ismd_global_defs.h"
#include "ismd_audio_defs.h"
#include "ismd_vidpproc.h"
#include "ismd_viddec.h"

#include "ismd_gst_enum.h"

GType
ismd_gst_video_sink_tvmode_get_type (void)
{
  static GType ismd_gst_video_sink_tvmode_type = 0;
  static const GEnumValue tvmode_types[] = {
    {-1, "None to be configured", "none"},
    {0, "480 interlaced at 60 Hz", "480i"},
    {1, "480 progressive at 60 Hz", "480p"},
    {2, "576 interlaced at 50 Hz", "576i"},
    {3, "576 progressive at 50 Hz", "576p"},
    {4, "720 progressive at 60 Hz", "720p"},
    {5, "720 progressive at 50 Hz", "720p50"},
    {6, "1080 interlaced at 60 Hz", "1080i"},
    {7, "1080 interlaced at 50 Hz", "1080i50"},
    {8, "1080 progressive at 60 Hz", "1080p"},
    {9, "1080 progressive at 50 Hz", "1080p50"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_video_sink_tvmode_type) {
    ismd_gst_video_sink_tvmode_type =
        g_enum_register_static ("GstIsmdVideoSinkTVMode", tvmode_types);
  }
  return ismd_gst_video_sink_tvmode_type;
}

GType
ismd_gst_video_sink_gdl_plane_get_type (void)
{
  static GType ismd_gst_video_sink_gdl_plane_type = 0;
  static const GEnumValue gdl_plane_types[] = {
    {GDL_PLANE_ID_UPP_A, "Universal Pixel Plane A", "UPPA"},
    {GDL_PLANE_ID_UPP_B, "Universal Pixel Plane B", "UPPB"},
    {GDL_PLANE_ID_UPP_C, "Universal Pixel Plane C", "UPPC"},
    {GDL_PLANE_ID_UPP_D, "Universal Pixel Plane D", "UPPD"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_video_sink_gdl_plane_type) {
    ismd_gst_video_sink_gdl_plane_type =
        g_enum_register_static ("GstIsmdVideoSinkGDLPlane", gdl_plane_types);
  }
  return ismd_gst_video_sink_gdl_plane_type;
}

GType
ismd_gst_vidpproc_scale_mode_get_type (void)
{
  static GType ismd_gst_vidpproc_scale_mode_type = 0;
  static const GEnumValue scale_mode_types[] = {
    {VPP_NO_SCALING,
          "this will force the output to be same size as the input ignores pixel aspect ratio",
        "none"},
    {SCALE_TO_FIT,
          "basic independent x and y scaling, ignores pixel aspect ratio",
        "scale2fit"},
    {ZOOM_TO_FIT,
          "fit at least one side of the destination rectangle, letterbox/pillarbox the remainder",
        "zoom2fit"},
    {ZOOM_TO_FILL,
          "fill entire screen. use both the source and destination pixel aspect ratios",
        "zoom2fill"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_vidpproc_scale_mode_type) {
    ismd_gst_vidpproc_scale_mode_type =
        g_enum_register_static ("GstIsmdVidpprocScaleMode", scale_mode_types);
  }
  return ismd_gst_vidpproc_scale_mode_type;
}

GType
ismd_gst_viddec_output_policy_get_type (void)
{
  static GType ismd_gst_viddec_output_policy_type = 0;
  static const GEnumValue output_policy_types[] = {
    {ISMD_VIDDEC_DISPLAY_ORDER,
          "Default - Frames will be emitted in display order",
        "display"},
    {ISMD_VIDDEC_DECODE_ORDER,
          "Frames will be emitted in decode order",
        "decode"},
    {ISMD_VIDDEC_FIRST_IN_GROUP,
          "First frame from the group will be emitted",
        "first-in-group"},
    {ISMD_VIDDEC_LAST_IN_GROUP,
          "Last frame from the group will be emitted",
        "last-in-group"},
    {ISMD_VIDDEC_REVERSE_IN_GROUP_ORDER,
          "Frames from group will be emitted in reverse order",
        "reverse-in-group"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_viddec_output_policy_type) {
    ismd_gst_viddec_output_policy_type =
        g_enum_register_static ("GstIsmdViddecOutpuPolicy", output_policy_types);
  }
  return ismd_gst_viddec_output_policy_type;
}

GType
ismd_gst_viddec_error_policy_get_type (void)
{
  static GType ismd_gst_viddec_error_policy_type = 0;
  static const GEnumValue error_policy_types[] = {
    {ISMD_VIDDEC_EMIT_NO_ERROR_FRAMES,
          "Drop all frames with missing references, dangling fields, and macroblock errors",
        "no-error-frames"},
    {ISMD_VIDDEC_EMIT_ALL,
          "Output all frames, including those with errors",
        "all"},
    {ISMD_VIDDEC_EMIT_FRAMES_MISSING_REF,
          "Output frames with missing references",
        "missing-ref"},
    {ISMD_VIDDEC_EMIT_DANGLING_FIELDS,
          "Output frames with dangling fields",
        "dangling-fields"},
    {ISMD_VIDDEC_EMIT_ERROR_CONCEAL_FRAMES,
          "Default - Output frames where macroblock errors were concealed",
        "error-conceal-frames"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_viddec_error_policy_type) {
    ismd_gst_viddec_error_policy_type =
        g_enum_register_static ("GstIsmdViddecErrorPolicy", error_policy_types);
  }
  return ismd_gst_viddec_error_policy_type;
}

GType
ismd_gst_audio_sink_latency_get_type (void)
{
  static GType ismd_gst_audio_sink_latency_type = 0;
  static const GEnumValue audio_latency_types[] = {
    {ISMD_AUDIO_LATENCY_MODE_LOW_WITH_POST_PROCESSING,
          "Low latency mode with post processing enabled, no encode or HDMI output support",
        "low"},
    {ISMD_AUDIO_LATENCY_MODE_DEFAULT,
          "Default audio latency policy",
        "default"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_audio_sink_latency_type) {
    ismd_gst_audio_sink_latency_type =
        g_enum_register_static ("GstIsmdAudioSinkLatency", audio_latency_types);
  }
  return ismd_gst_audio_sink_latency_type;
}

GType
ismd_gst_pid_category_get_type (void)
{
  static GType ismd_gst_pid_category_type = 0;
  static const GFlagsValue pid_category[] = {
    { PID_CAT_PAT, "Program Association Table", "pat" },
    { PID_CAT_PMT, "Program Map Table", "pmt" },
    { PID_CAT_PCR, "Program Clock Reference", "pcr" },
    { PID_CAT_PSI, "Program Specific Information = pat + pmt + pcr", "psi" },
    { PID_CAT_VIDEO, "Elementary streams containing video", "video" },
    { PID_CAT_AUDIO, "Elementary streams containing audio", "audio" },
    { PID_CAT_OTHER, "Elementary streams containing other information", "other" },
    { PID_CAT_ALL, "All previous categories", "all" },
    {0, NULL, NULL}
  };

  if (!ismd_gst_pid_category_type) {
    ismd_gst_pid_category_type =
        g_flags_register_static ("GstIsmdPidCategory",
            pid_category);
  }
  return ismd_gst_pid_category_type;
}

PidCategory
ismd_gst_get_category_from_stream_type (guint8 type)
{
  switch (type) {
    case VIDEO_MPEG1:
    case VIDEO_MPEG2:
    case VIDEO_H264:
    case VIDEO_VC1:
      return PID_CAT_VIDEO;
    case AUDIO_MP2:
    case AUDIO_MP3:
    case AUDIO_MPEG2_AAC:
    case AUDIO_MPEG4_AAC:
    case AUDIO_PCM:
    case AUDIO_AC3_DDP:
    case AUDIO_DTS:
    case AUDIO_TRUE_HD:
    case AUDIO_AC3_DDP2:
    case AUDIO_DTS_HD:
    case AUDIO_DTS_HD_XLL:
    case AUDIO_AC3_DDP3:
      return PID_CAT_AUDIO;
    case PRIVATE:
    default:
      return PID_CAT_OTHER;
  }
}

const gchar *
ismd_gst_stream_type_name (guint8 type) {
  switch (type) {
    case VIDEO_MPEG1:
      return "VIDEO_MPEG_1";
    case VIDEO_MPEG2:
      return "VIDEO_MPEG_2";
    case VIDEO_H264:
      return "VIDEO_H264";
    case VIDEO_VC1:
      return "VIDEO_VC1";
    case AUDIO_MP2:
      return "AUDIO_MP2";
    case AUDIO_MP3:
      return "AUDIO_MP3";
    case AUDIO_MPEG2_AAC:
      return "AUDIO_MPEG2_AAC";
    case AUDIO_MPEG4_AAC:
      return "AUDIO_MPEG4_AAC";
    case AUDIO_PCM:
      return "AUDIO_PCM";
    case AUDIO_AC3_DDP:
      return "AUDIO_AC3_DDP";
    case AUDIO_DTS:
      return "AUDIO_DTS";
    case AUDIO_TRUE_HD:
      return "AUDIO_TRUE_HD";
    case AUDIO_AC3_DDP2:
      return "AUDIO_AC3_DDP2";
    case AUDIO_DTS_HD:
      return "AUDIO_DTS_HD";
    case AUDIO_DTS_HD_XLL:
      return "AUDIO_DTS_HD_XLL";
    case AUDIO_AC3_DDP3:
      return "AUDIO_AC3_DDP3";
    case PRIVATE:
      return "PRIVATE";
    default:
      return "UNKNOWN TYPE";
  }
}

