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

#ifndef __ISMD_GST_AUDIO_SINK_H__
#define __ISMD_GST_AUDIO_SINK_H__

#include <gst/gst.h>
#include "ismd_gst_element.h"
#include "ismd_audio_defs.h"
#include "libgdl.h"
#include "ismd_gst_clock.h"

#define AAC_ADTS_HEADER_SIZE    7
#define AAC_FREQUENCY_INDEX     12
#define AAC_CHANNEL_INDEX       7
#define AAC_LC_CODEC_DATA       "1190"
#define SMD_TO_GST(x) (x*100000/9)
#define PIPE_LATENCY  100000000/9

typedef enum
{
  AUDIO_PLL_FREQ_FAMILY_INVALID,
  AUDIO_PLL_FREQ_FAMILY_44100,
  AUDIO_PLL_FREQ_FAMILY_48000
} AUDIO_PLL_FREQ_FAMILY;

typedef struct
{
  unsigned int data;
  unsigned char index;
} aac_audio_index;

typedef struct
{
  gint ismd_port;
  gint out_mode;
  ismd_dev_t output_handle;
  gboolean configured;
  gboolean shared_physical_out;
} output_device;

/**
 * ISmdAudioSink:
 *
 * The opaque #ISmdAudioSink data structure.
 */
typedef struct _ISmdGstAudioSink
{
  ISmdGstElement element;

  gint width;
  gint rate;
  gint channels;
  gint bitrate;

  gboolean use_global_proc;

  guint8 aac_header_data[AAC_ADTS_HEADER_SIZE];
  gboolean sync;
  ismd_audio_latency_mode_t latency;
  GstFormat format;  
  GstClockTime first_pts;
  GstClockTime last_pts;
  gboolean first_aac_packet;
  GstCaps *caps_available;

  gfloat input_gain;
  gfloat volume;
  gboolean mute;

  gfloat current_input_gain;
  gfloat current_volume;
  gboolean current_mute;
 
  gint hdmi_pcm_max_channels;
  gint hdmi_pcm_max_samplerate;
  gint hdmi_pcm_max_samplesize;

  gint hdmi_pcm_samplerates[8];

  ismd_audio_format_t codec;
  ismd_audio_wma_format_t wma_fmt;
  ismd_audio_processor_t processor;

  AUDIO_PLL_FREQ_FAMILY clock_family;
  output_device hdmi;
  output_device spdif;
  output_device i2s0;
  output_device i2s1;
  gint out_delay;

  ISmdGstClock *provided_clock;

  /* Monitoring task on EOS event */
  GstTask *monitor_loop;
  GStaticRecMutex *monitor_mutex;
  ismd_event_t bos_event;
  ismd_event_t eos_event;
  ismd_event_t clientid_event;
  gboolean monitor_stop;
  gboolean bos_posted;
  gboolean eos_posted;
} ISmdGstAudioSink;

typedef struct _ISmdGstAudioSinkClass
{
  ISmdGstElementClass parent_class;

  /* signals */
  //void (*handoff) (GstElement *element, GstBuffer *buf, GstPad *pad);
  //void (*preroll_handoff) (GstElement *element, GstBuffer *buf, GstPad *pad);
} ISmdGstAudioSinkClass;

GType ismd_gst_audio_sink_get_type (void);

#define ISMD_GST_TYPE_AUDIO_SINK 	(ismd_gst_audio_sink_get_type())
#define ISMD_GST_AUDIO_SINK(obj) 	(G_TYPE_CHECK_INSTANCE_CAST\
					((obj),ISMD_GST_TYPE_AUDIO_SINK,ISmdGstAudioSink))
#define ISMD_GST_AUDIO_SINK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST\
					((klass),ISMD_GST_TYPE_AUDIO_SINK,ISmdGstAudioSinkClass))
#define ISMD_GST_IS_AUDIO_SINK(obj) 	(G_TYPE_CHECK_INSTANCE_TYPE\
					((obj),ISMD_GST_TYPE_AUDIO_SINK))
#define ISMD_GST_IS_AUDIO_SINK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
					((klass),ISMD_GST_TYPE_AUDIO_SINK))
#define ISMD_GST_AUDIO_SINK_CAST(obj) ((ISmdGstAudioSink *)obj)

#endif /* __ISMD_GST_AUDIO_SINK_H__ */
