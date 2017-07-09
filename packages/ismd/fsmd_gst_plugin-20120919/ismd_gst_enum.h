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

#ifndef __ISMD_GST_ENUM_H__
#define __ISMD_GST_ENUM_H__

#include <gst/gst.h>
#include "libgdl.h"

G_BEGIN_DECLS

typedef struct _TVMode
{
  char *alias;
  gdl_uint32 width;
  gdl_uint32 height;
  gdl_refresh_t refresh;
  gdl_boolean_t interlaced;
} TVMode;

static const TVMode tvmodes[] = {
  {"480i", 720, 480, GDL_REFRESH_59_94, GDL_TRUE},
  {"480p", 720, 480, GDL_REFRESH_59_94, GDL_FALSE},
  {"576i", 720, 576, GDL_REFRESH_50, GDL_TRUE},
  {"576p", 720, 576, GDL_REFRESH_50, GDL_FALSE},
  {"720p", 1280, 720, GDL_REFRESH_59_94, GDL_FALSE},
  {"720p50", 1280, 720, GDL_REFRESH_50, GDL_FALSE},
  {"1080i", 1920, 1080, GDL_REFRESH_59_94, GDL_TRUE},
  {"1080i50", 1920, 1080, GDL_REFRESH_50, GDL_TRUE},
  {"1080p", 1920, 1080, GDL_REFRESH_59_94, GDL_FALSE},
  {"1080p50", 1920, 1080, GDL_REFRESH_50, GDL_FALSE},
  {NULL, 0, 0, (gdl_refresh_t) 0, GDL_FALSE}    // EOL
};

typedef enum _PidCategory {
    PID_CAT_UNKNOWN = 0,
    PID_CAT_PAT = 1,
    PID_CAT_PMT = 2,
    PID_CAT_PCR = 4,
    PID_CAT_PSI = PID_CAT_PAT | PID_CAT_PMT | PID_CAT_PCR,
    PID_CAT_VIDEO = 8,
    PID_CAT_AUDIO = 16,
    PID_CAT_OTHER = 32,
    PID_CAT_ALL = PID_CAT_PSI | PID_CAT_VIDEO | PID_CAT_AUDIO | PID_CAT_OTHER
} PidCategory;

typedef enum _PmtStreamType{
    VIDEO_MPEG1 = 0x01,
    VIDEO_MPEG2 = 0x02,
    AUDIO_MP2 = 0x03,
    AUDIO_MP3 = 0x04,
    PRIVATE = 0x06,           /* Not audio nor video */
    AUDIO_MPEG2_AAC = 0xf,
    AUDIO_MPEG4_AAC = 0x11,
    VIDEO_H264 = 0x1b,
    AUDIO_PCM = 0x80,         /* BD PCM                 */
    AUDIO_AC3_DDP = 0x81,     /* BD AC3                 */
    AUDIO_DTS = 0x82,         /* BD DTS                 */
    AUDIO_TRUE_HD = 0x83,     /* BD "Dolby Lossless"    */
    AUDIO_AC3_DDP2 = 0x84,    /* BD DD+                 */
    AUDIO_DTS_HD = 0x85,      /* BD DTS HD (except XLL) */
    AUDIO_DTS_HD_XLL = 0x86,  /* BD DTS HD XLL          */
    AUDIO_AC3_DDP3 = 0x87,    /* Defined in atsc spec:  */
                              /* www.atsc.org/standards/a_53-Part-3-2007.pdf */
    VIDEO_VC1 = 0xEA
} PmtStreamType;

#define GST_TYPE_ISMD_VIDEO_SINK_TVMODE \
  (ismd_gst_video_sink_tvmode_get_type())

#define GST_TYPE_ISMD_VIDEO_SINK_GDL_PLANE \
  (ismd_gst_video_sink_gdl_plane_get_type())

#define GST_TYPE_ISMD_VIDPPROC_SCALE_MODE \
  (ismd_gst_vidpproc_scale_mode_get_type())

#define GST_TYPE_ISMD_VIDDEC_OUTPUT_POLICY \
  (ismd_gst_viddec_output_policy_get_type())

#define GST_TYPE_ISMD_VIDDEC_ERROR_POLICY \
  (ismd_gst_viddec_error_policy_get_type())

#define GST_TYPE_ISMD_AUDIO_SINK_LATENCY \
  (ismd_gst_audio_sink_latency_get_type())

#define GST_TYPE_FLAGS_PID_CATEGORY \
  (ismd_gst_pid_category_get_type())


GType ismd_gst_video_sink_tvmode_get_type (void);
GType ismd_gst_video_sink_gdl_plane_get_type (void);
GType ismd_gst_vidpproc_scale_mode_get_type (void);
GType ismd_gst_viddec_output_policy_get_type (void);
GType ismd_gst_viddec_error_policy_get_type (void);
GType ismd_gst_audio_sink_latency_get_type (void);
GType ismd_gst_pid_category_get_type(void);
PidCategory ismd_gst_get_category_from_stream_type (guint8 type);
const gchar *ismd_gst_stream_type_name (guint8 type);

G_END_DECLS

#endif /* __ISMD_GST_ENUM_H__ */

