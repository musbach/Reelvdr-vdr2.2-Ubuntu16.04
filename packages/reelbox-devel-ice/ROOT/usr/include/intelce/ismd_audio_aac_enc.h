/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2009 Intel Corporation. All rights reserved.
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

/** 

This file defines the parameters for the AAC encoder.  The 
defines and enums are intended to be used when calling the functions
ismd_audio_input_set_decoder_param() and ismd_audio_input_get_decoder_param().

Example usage: 

   void set_codec_parameters( ismd_audio_processor_t proc_handle,
                              ismd_dev_t             input_handle )
   {
      ismd_result_t                                  	  result;
      ismd_audio_codec_param_t                   param;
      ismd_audio_aac_enc_data_rate_t 		*data_rate;
      ismd_audio_aac_enc_quality_level_t     *quality_level;

      karaoke_mode = (ismd_audio_aac_enc_data_rate_t *)&param;
      *data_rate = 320000;
      result = ismd_audio_decoder_param_set( proc_handle, 
                                           input_handle, 
                                           ISMD_AUDIO_AAC_ENC_DATA_RATE, 
                                           &param );

      quality_level = (ismd_audio_aac_enc_quality_level_t *)&param;
      *quality_level = 2;
      result = ismd_audio_decoder_param_set( proc_handle, 
                                           input_handle, 
                                           ISMD_AUDIO_AAC_ENC_QUALITY_LEVEL, 
                                           &param );
      
      return;
   }

*/


#ifndef _ISMD_AUDIO_AAC_ENC_PARAMS_H_
#define _ISMD_AUDIO_AAC_ENC_PARAMS_H_

/** 
The output datarates supported by AAC Encoder are exposed by this SMD API parameter. 
The application has to provide the datarate for two channel. 
The suppported values range from 16-320 kbps for 2 channel. Default 128 Kbps. 
*/
#define ISMD_AUDIO_AAC_ENC_DATA_RATE  		0x2950
/** 
The output quality levels supported by AAC Encoder are exposed by this SMD API parameter. 
The supported values are 0, 1 and 2. Default value is 2. 
*/
#define ISMD_AUDIO_AAC_ENC_QUALITY_LEVEL  	0x2951
/** 
The Number of input channels supported by AAC Encoder are exposed by this SMD API parameter. 
The only supported value at this point is 2. 
*/
#define ISMD_AUDIO_AAC_ENC_NUM_INPUT_CH    	0x2952
/** 
The encode mode supported by AAC Encoder is exposed by this SMD API parameter. 
The only supported value at this point is 0 which means AAC LC Encoding is performed.
*/
#define ISMD_AUDIO_AAC_ENC_ENCODE_MODE		0x2953

/** 
The Hifi 2 Audio Engine AAC Encoder supports a given set of bit rates per input audio sample rate. 
The normal usage of the Audio Encoder is within these ranges. 
The bit rate supported is from 8 to 320 kbps. 
Sample Rate (kHz)	   Bit Rate(kbps)
	32000				      28 to 320
	44100				      28 to 320
	48000				      28 to 320
	88200				      48 to 320
	96000				      48 to 320
*/
typedef int ismd_audio_aac_enc_data_rate_t;


/** 
The Hifi 2 Audio Engine AAC Encoder supports three different quality levels.
0 for least quality encoding (fastest)
1 is intermediate quality
2 for best quality encoding (slowest)
*/
typedef int ismd_audio_aac_enc_quality_level_t;


/** 
   Only 2 channel input is supported for the time being.
*/
typedef int ismd_audio_aac_enc_num_input_ch_t;

/** 
The Hifi 2 Audio Engine AAC Encoder has two encode modes.
 0 means aacPlus(v1) Encoding is performed. Not supporting.
 1 means AAC LC Encoding is performed
*/
typedef int ismd_audio_aac_enc_encode_mode_t;


#endif /* _ISMD_AUDIO_AAC_ENC_PARAMS_H_ */

