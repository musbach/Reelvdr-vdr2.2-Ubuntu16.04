/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2012. Intel Corporation. All rights reserved.

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

    Copyright (c) 2012. Intel Corporation. All rights reserved.

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

#ifndef __ISMD_GST_AUDIO_DEC_H__
#define __ISMD_GST_AUDIO_DEC_H__

#include <gst/gst.h>
#include "ismd_gst_element.h"
#include "ismd_audio_defs.h"

/**
 * ISmdAudioDecoder:
 *
 * The opaque #ISmdAudioDecoder data structure.
 */
#ifndef AAC_ADTS_HEADER_SIZE
#define AAC_ADTS_HEADER_SIZE  7
#endif
typedef struct _ISmdGstAudioDecoder
{
  ISmdGstElement element;
//for input
  gint width;
  gint rate;
  gint channels;
  gint bitrate;
//for output
  gint                   out_sample_size;
  gint                   out_sample_rate;
  ismd_audio_channel_config_t ch_config;
  gint out_mode;
  ismd_dev_t output_handle;
  gint out_delay;

  gboolean use_global_proc;

  guint8 aac_header_data[AAC_ADTS_HEADER_SIZE];
  gboolean sync;
  gboolean first_aac_packet;

  ismd_audio_format_t codec;
  ismd_audio_wma_format_t wma_fmt;
  ismd_audio_processor_t processor;
  /* Monitoring task on EOS event */
} ISmdGstAudioDecoder;

typedef struct _ISmdGstAudioDecoderClass
{
  ISmdGstElementClass parent_class;

  /* signals */
  //void (*handoff) (GstElement *element, GstBuffer *buf, GstPad *pad);
  //void (*preroll_handoff) (GstElement *element, GstBuffer *buf, GstPad *pad);
} ISmdGstAudioDecoderClass;

GType ismd_gst_audio_decoder_get_type (void);

#define ISMD_GST_TYPE_AUDIO_DECODER 	(ismd_gst_audio_decoder_get_type())
#define ISMD_GST_AUDIO_DECODER(obj) 	(G_TYPE_CHECK_INSTANCE_CAST\
					((obj),ISMD_GST_TYPE_AUDIO_DECODER,ISmdGstAudioDecoder))
#define ISMD_GST_AUDIO_DECODER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST\
					((klass),ISMD_GST_TYPE_AUDIO_DECODER,ISmdGstAudioDecoderClass))
#define ISMD_GST_IS_AUDIO_DECODER(obj) 	(G_TYPE_CHECK_INSTANCE_TYPE\
					((obj),ISMD_GST_TYPE_AUDIO_DECODER))
#define ISMD_GST_IS_AUDIO_DECODER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
					((klass),ISMD_GST_TYPE_AUDIO_DECODER))
#define ISMD_GST_AUDIO_DECODER_CAST(obj) ((ISmdGstAudioDecoder *)obj)

#endif /* __ISMD_GST_audio_dec_H__ */
