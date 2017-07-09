/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2011 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution
  in the file called LICENSE.GPL.

  Contact Information:

  Intel Corporation
  2200 Mission College Blvd.
  Santa Clara, CA  97052

  BSD LICENSE

  Copyright(c) 2011 Intel Corporation. All rights reserved.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
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

#ifndef _ISMD_AUDIO_DTS_NEURAL_H_
#define _ISMD_AUDIO_DTS_NEURAL_H_

#include "ismd_audio_type_defs.h"

/** The amount of memory required for each instance
    of the DTS Neural processing block.*/
#define ISMD_AUDIO_DTS_NEURAL_REQ_MEM_SIZE (112 * 1024)

/** Min value for front_width parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_FRONT_WIDTH_MIN -20
/** Maxium value for front_width parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_FRONT_WIDTH_MAX 20

/** Min value for surround_width parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_SURROUND_WIDTH_MIN 0
/** Maxium value for surround_width parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_SURROUND_WIDTH_MAX 20

/** Min value for limiter_ceiling parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_LIMITER_CEILING_MIN -12
/** Maxium value for limiter_ceiling parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_LIMITER_CEILING_MAX 0

/** Min value for depth parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_DEPTH_MIN -20
/** Maxium value for depth parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_DEPTH_MAX 20

/** Min value for dice_level parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_DICE_LEVEL_MIN 0
/** Maxium value for dice_level parameter in \ref ismd_audio_dts_neural_params_t.*/
#define ISMD_AUDIO_DTS_NEURAL_DICE_LEVEL_MAX 20

/** Min value for the input_level  parameter in \ref ismd_audio_dts_neural_params_t*/
#define ISMD_AUDIO_DTS_NEURAL_INPUT_LEVEL_MIN -12
/** Max value for the input_level parameter in \ref ismd_audio_dts_neural_params_t*/
#define ISMD_AUDIO_DTS_NEURAL_INPUT_LEVEL_MAX 12

/** Min value for the output_level  parameter in \ref ismd_audio_dts_neural_params_t*/
#define ISMD_AUDIO_DTS_NEURAL_OUTPUT_LEVEL_MIN -12
/** Max value for the output_level parameter in \ref ismd_audio_dts_neural_params_t*/
#define ISMD_AUDIO_DTS_NEURAL_OUTPUT_LEVEL_MAX 12

/** Specify unused channels to be silenced or removed.*/
typedef enum {
   /** DTS Neural will only ouput active channels. (Default)*/
   ISMD_AUDIO_DTS_NEURAL_UNUSED_CHANNELS_REMOVED = 0, 
   
   /** DTS Neural will always output \ref AUDIO_MAX_OUTPUT_CHANNELS, 
       and will silence the channels that do not contain active
       audio output from the library. This mode is used
       for special certification tests or debugging, it is 
       not recommended to use this mode as the default mode
       since it will added uneeded processing on silence channels.*/
   ISMD_AUDIO_DTS_NEURAL_UNUSED_CHANNELS_ADD_SILENCE      
}ismd_audio_dts_neural_unused_channels_mode_t;

/** Specify the input channels for the library to use.*/
typedef enum {
   /** DTS Neural will process 2 input channels at its input. This
       puts the library in 227 or 225 mode depending on the 
       \ref ismd_audio_dts_neural_output_config_t setting. The
       channels it will use as input are the Left and Right channels. (Default)*/
   ISMD_AUDIO_DTS_NEURAL_2CH_INPUT_MODE = 0,
   
   /** DTS Neural will process 6 input channels at its input. This 
       puts the library in the 527 mode. The channels it will use
       as input are the Left, Right, Center, LFE, Left Sur, Right Sur*/
   ISMD_AUDIO_DTS_NEURAL_6CH_INPUT_MODE   
}ismd_audio_dts_neural_input_channel_mode_t;

/** Use to enable or disable the internal limiter.*/
typedef enum {
   ISMD_AUDIO_DTS_NEURAL_LIMITER_DISABLED = 0,  /** DTS Neural disable the limiter.*/
   ISMD_AUDIO_DTS_NEURAL_LIMITER_ENABLED        /** DTS Neural enable the limiter.*/
}ismd_audio_dts_neural_limiter_mode_t;

/** Use to enable or disable DICE mode.*/
typedef enum {
   ISMD_AUDIO_DTS_NEURAL_DICE_DISABLED = 0,  /** DTS Neural disable DICE mode */
   ISMD_AUDIO_DTS_NEURAL_DICE_ENABLED        /** DTS Neural enable DICE mode*/
}ismd_audio_dts_neural_dice_mode_t;

/** The low pass cutoff frequency of the LFE channel.*/
typedef enum {
   ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_0HZ,     /** 0Hz cutoff*/
   ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_60HZ,    /** 60Hz cutoff*/
   ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_80HZ,    /** 80Hz cutoff (default)*/
   ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_100HZ,   /** 100Hz cutoff*/
   ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_120HZ,   /** 120Hz cutoff*/
   ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_140HZ    /** 140Hz cutoff*/
}ismd_audio_dts_neural_lfe_cutoff_t;

/** The latency setting for DTS nueral latency parameter.*/
typedef enum {
   ISMD_AUDIO_DTS_NEURAL_LATENCY_LOW = 0, /** Low latency. (default)*/
   ISMD_AUDIO_DTS_NEURAL_LATENCY_HIGH     /** High latency.*/
}ismd_audio_dts_neural_latency_t;

/** DTS Neural output configuration settings. */
typedef enum {
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_INVALID,         /** Invalid output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_STEREO,          /** 2 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_3_1,             /** 3.1 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_4_1,             /** 4.1 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_5_1,             /** 5.1 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_6_1,             /** 6.1 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_PHANTOM_6_1,     /** Phantom 6.1 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_7_1,             /** 7.1 channel output configuration.*/
   ISMD_AUDIO_DTS_NEURAL_OUT_CONFIG_PHANTOM_7_1,     /** Phantom 7.1 channel output configuration.*/
}ismd_audio_dts_neural_output_config_t;

/** Parameters that can be applied to the DTS Neural processing module.*/
typedef struct {

   /** Set the amount of narrowing or widening to perform on 
       the front channels. This is performed via combining of the 
       Left and Right channels into the Center channel, or via 
       Center channel spread into the Left and Right channels. A 
       setting of 0 performs no special narrowing or widening, 
       e.g. no Center channel collapse or spread. A setting of -20 
       performs full narrowing, e.g. full collapse of the Left and 
       Right channels into the Center channel, while a setting of +20 
       performs full widening, e.g. full spread of the Center channel 
       into the Left and Right channels. Valid range: -20 to 20. 
       Default setting is 0.*/
   int front_width;

   /** Set the wideness of the surround channels. A setting of 0 
       generates surround channels which are narrower, yet which may 
       achieve greater rejection of Center channel material. A setting 
       of +20 generates surround channels which are wider and more enveloping. 
       Valid range: 0 to 20. Default setting is 20. */
   int surround_width;

   /** Turn the limiter on or off using this parameter.*/
   ismd_audio_dts_neural_limiter_mode_t limiter_mode;

   /** Set the maximum level of output samples in dBFS when the final 
       limiters are applied. Valid range: 0 to -12 (db). Default setting is 0.*/ 
   int limiter_ceiling;

   /** Set the amount of front-to-back bias to apply to the standard soundstage. 
       A setting of +20 shifts the image to the front speakers, a setting of 
       -20 shifts the image to the surround and rear speakers, while a setting 
       of 0 applies no front or back bias. Valid range: -20 to 20. Default setting is 0.*/
   int depth;

   /** Turn DICE mode on or off using this parameter.*/
   ismd_audio_dts_neural_dice_mode_t dice_mode;
   
   /** Set the amount of DICE processing to apply. A setting of 0 applies the minimum 
       amount of Dynamic Image Control Enhancement (DICE) processing, while a setting 
       of 20 applies the maximum amount. This parameter is only applicable when the 
       set to Digital Music mode. Valid range: 0 to 20. Default setting is 10. */
   int dice_level;

   /** Defines the latency setting of the 227 decoder. Two latency settings 
       are supported: \ref ISMD_AUDIO_DTS_NEURAL_LATENCY_LOW for 
       live applications or other situations where latency is of concern, 
       and \ref ISMD_AUDIO_DTS_NEURAL_LATENCY_HIGH setting for situations 
       where some latency is acceptable. The \ref ISMD_AUDIO_DTS_NEURAL_LATENCY_HIGH 
       setting may exhibit some performance improvements on certain content types. */
   ismd_audio_dts_neural_latency_t latency;
   
   /** Controls the low pass cutoff frequency of the LFE channel. The
       default setting is \ref ISMD_AUDIO_DTS_NEURAL_LFE_CUTOFF_80HZ */
   ismd_audio_dts_neural_lfe_cutoff_t lfe_cutoff;

   /** Set the output configuration of the DTS Neural processing block.*/
   ismd_audio_dts_neural_output_config_t output_config;

   /** Set the way the library handles the unused output channels.*/
   ismd_audio_dts_neural_unused_channels_mode_t unused_channels_mode;

   /** Set how many input channels the library should operate on.*/
   ismd_audio_dts_neural_input_channel_mode_t input_channel_mode;

   /** Set the input gain prior to the upmix. Valid range: -12 to 12 (db). Default is 0.*/
   int input_level;

   /** Set the output gain after the upmix. Valid range: -12 to 12 (db). Default is 0.*/
   int output_level;
}ismd_audio_dts_neural_params_t;

/**************************************************************************/

#endif /* _ISMD_AUDIO_DTS_NEURAL_H_ */

