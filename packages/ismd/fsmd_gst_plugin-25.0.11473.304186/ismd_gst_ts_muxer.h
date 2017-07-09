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

#ifndef __ISMD_GST_TS_MUXER_H__
#define __ISMD_GST_TS_MUXER_H__

#include <gst/gst.h>
#include "ismd_gst_element.h"
#include "ismd_mux.h"


typedef struct _ISmdGstTSMuxerPad{
    ISmdGstPad *pad;
    ismd_mux_pid_t pid;
    ismd_port_handle_t port;
    ismd_mux_input_stream_type_t stream_type;
    ismd_mux_input_stream_mode_t        stream_mode;
    ismd_time_t                         ts_offset; 
}ISmdGstTSMuxerPad;

typedef struct _ISmdGstTSMuxer
{
  ISmdGstElement element;
  
   /*  sinkpads, video first */
  GList *sinkpads;
  guint audio_pads;
  guint video_pads;
  guint sink_count;

  /* property */
  ismd_mux_output_stream_type_t output_stream_type;
  ismd_mux_input_stream_mode_t input_stream_mode;
  ismd_mux_scheduling_mode_t scheduling_mode;

  guint transport_stream_id;
  guint program_num;
  guint pmt_pid;
  guint bitrate;

  guint64 pat_interval;
  guint64 pmt_interval;
  guint64 pcr_interval;
} ISmdGstTSMuxer;

typedef struct _ISmdGstTSMuxerClass
{
  ISmdGstElementClass parent_class;

} ISmdGstTSMuxerClass;

GType ismd_gst_ts_muxer_get_type (void);

#define ISMD_GST_TYPE_TS_MUXER 	(ismd_gst_ts_muxer_get_type())
#define ISMD_GST_TS_MUXER(obj) 	(G_TYPE_CHECK_INSTANCE_CAST\
					((obj),ISMD_GST_TYPE_TS_MUXER,ISmdGstTSMuxer))
#define ISMD_GST_TS_MUXER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST\
					((klass),ISMD_GST_TYPE_TS_MUXER,ISmdGstTSMuxerClass))
#define ISMD_GST_IS_TS_MUXER(obj) 	(G_TYPE_CHECK_INSTANCE_TYPE\
					((obj),ISMD_GST_TYPE_TS_MUXER))
#define ISMD_GST_IS_TS_MUXER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
					((klass),ISMD_GST_TYPE_TS_MUXER))
#define ISMD_GST_TS_MUXER_CAST(obj) ((ISmdGstTSMuxer *)obj)

#endif 
