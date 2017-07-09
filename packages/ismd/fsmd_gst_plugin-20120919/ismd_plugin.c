/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright (c) 2011-2012. Intel Corporation. All rights reserved.
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

    Copyright (c) 2011-2012. Intel Corporation. All rights reserved.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
//#include "system_utils_soc_info.h"
#include "pal_soc_info.h"

#include "ismd_gst_element.h"
#include "ismd_gst_demux.h"
#include "ismd_gst_mpeg2_viddec.h"
#include "ismd_gst_mpeg4_viddec.h"
#include "ismd_gst_h264_videnc.h"
#include "ismd_gst_h264_viddec.h"
#include "ismd_gst_vc1_viddec.h"
#include "ismd_gst_vidpproc.h"
#include "ismd_gst_vidrend_sink.h"
#include "ismd_gst_audio_sink.h"
#include "ismd_gst_audio_dec.h"
#include "ismd_gst_vidrend_bin.h"
#include "ismd_gst_dvb_src.h"
#include "ismd_gst_ts_muxer.h"
#include "ismd_gst_vidsink.h"


#include "ismd_gst_rectangle.h"
#include "ismd_gst_clock_recovery_provider.h"

/* Name of package */
#define PACKAGE "gst-fluendo-ismd"

/* Version number of package */
#define VERSION "0.10.22.1"

/* Define to the full name of this package. */
#define PACKAGE_NAME "GStreamer Fluendo ISMD Elements"

GST_DEBUG_CATEGORY (ismd_gst_refiller_debug);
GST_DEBUG_CATEGORY (ismd_gst_vidrend_bin_debug);
GST_DEBUG_CATEGORY (ismd_gst_vidsink_debug);
GST_DEBUG_CATEGORY (ismd_gst_dvb_stream_debug);
GST_DEBUG_CATEGORY (ismd_gst_psi_filter_debug);
GST_DEBUG_CATEGORY (ismd_gst_section_filter_debug);
GST_DEBUG_CATEGORY (ismd_gst_mpeg_ts_desc_debug);

struct _elements_entry
{
  const gchar *name;
  guint rank;
    GType (*type) (void);
};

static struct _elements_entry _elements[] = {
/*  {"ismd_demux", GST_RANK_NONE, ismd_gst_demux_get_type}, */
  {"ismd_mpeg2_viddec", GST_RANK_PRIMARY + 2, ismd_gst_mpeg2_viddec_get_type},
  {"ismd_h264_videnc", GST_RANK_PRIMARY + 2, ismd_gst_h264_videnc_get_type},
  {"ismd_h264_viddec", GST_RANK_PRIMARY + 2, ismd_gst_h264_viddec_get_type},
  {"ismd_vc1_viddec", GST_RANK_PRIMARY + 2, ismd_gst_vc1_viddec_get_type},
  {"ismd_audio_sink", GST_RANK_PRIMARY - 1, ismd_gst_audio_sink_get_type},
  {"ismd_audio_decoder", GST_RANK_PRIMARY + 2, ismd_gst_audio_decoder_get_type},
  {"ismd_ts_muxer", GST_RANK_PRIMARY + 2, ismd_gst_ts_muxer_get_type},
  {"ismd_vidpproc", GST_RANK_PRIMARY + 2, ismd_gst_vidpproc_get_type},
  {"ismd_vidrend_sink", GST_RANK_PRIMARY + 2, ismd_gst_vidrend_sink_get_type},
  {"ismd_vidrend_bin", GST_RANK_PRIMARY + 2, ismd_gst_vidrend_bin_get_type},
  {"ismd_vidsink", GST_RANK_PRIMARY + 1, ismd_gst_vidsink_get_type},
  {"ismd_dvb_src", GST_RANK_PRIMARY + 2, ismd_gst_dvb_src_get_type},
  {"ismd_clock_recovery_provider", GST_RANK_PRIMARY + 2, ismd_gst_clock_recovery_provider_get_type},
  {NULL, 0},
};

static gboolean
plugin_init (GstPlugin * plugin)
{
  struct _elements_entry *my_elements = _elements;
  ismd_result_t result = ISMD_ERROR_OPERATION_FAILED;
  soc_user_info_t info;  

  GST_DEBUG_CATEGORY_INIT (ismd_gst_refiller_debug, "ISMD_REFILLER",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstrefiller element");
  
  GST_DEBUG_CATEGORY_INIT (ismd_gst_vidrend_bin_debug, "ISMD_VIDREND_BIN",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstvidrendbin element");

  GST_DEBUG_CATEGORY_INIT (ismd_gst_vidsink_debug, "ISMD_VIDSINK",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstvidsink element");

  GST_DEBUG_CATEGORY_INIT (ismd_gst_dvb_stream_debug, "ISMD_DVB_STREAM",
      (GST_DEBUG_FG_GREEN), "DVB stream");

  GST_DEBUG_CATEGORY_INIT (ismd_gst_psi_filter_debug, "ISMD_PSI_FILTER",
      (GST_DEBUG_FG_GREEN), "psi filter helper lib");

  GST_DEBUG_CATEGORY_INIT (ismd_gst_section_filter_debug, "ISMD_SECTION_FILTER",
      (GST_DEBUG_FG_CYAN), "MPEG-TS Section filter output");

  GST_DEBUG_CATEGORY_INIT (ismd_gst_mpeg_ts_desc_debug, "ISMD_MPEG_TS_DESC",
      (GST_DEBUG_FG_CYAN), "MPEG TS parser (descriptor)");

  if ((result = system_utils_get_soc_info (&info)) == 0) {
    if (info.name_enum == SOC_NAME_CE4100 || info.name_enum == SOC_NAME_CE4200 || 
        info.name_enum == SOC_NAME_CE5300) {
      if (!gst_element_register (plugin, "ismd_mpeg4_viddec",
            GST_RANK_PRIMARY + 2, ismd_gst_mpeg4_viddec_get_type())) {
        return FALSE;
      }
    } else {      
      GST_WARNING ("system_utils_get_soc_info returned unrecognized chip info");
    }
  }

  while ((*my_elements).name) {
    if (!gst_element_register (plugin, (*my_elements).name, (*my_elements).rank,
            ((*my_elements).type) ())) {
      return FALSE;
    }
    my_elements++;
  }

  gst_value_rectangle_register ();
  
  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    "fluismd",
    "GStreamer elements to use Intel Streaming Media Drivers (ISMD).",
    plugin_init,
    VERSION, "BSD", PACKAGE_NAME, "http://www.intelconsumerelectronics.com/");
