/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2010-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2010-2011 Intel Corporation. All rights reserved.
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

/* 


Example usage: 

   void set_codec_parameters( ismd_audio_processor_t proc_handle,
                                             ismd_dev_t             input_handle )
   {
      ismd_result_t                                  result;
      ismd_audio_codec_param_t             param;
      ismd_audio_mpeg_mono_to_stereo_t *mpeg_mono_to_stereo;
      ismd_audio_mpeg_mono_to_stereo_surround_t *mpeg_mono_to_stereo_surround;
      
      mpeg_mono_to_stereo = (ismd_audio_mpeg_mono_to_stereo_t *)&param;
      *mpeg_mono_to_stereo = ISMD_AUDIO_MPEG_MONO_TO_STEREO_ENABLED;
      result = ismd_audio_decoder_param_set( proc_handle, 
                                           input_handle, 
                                           *mpeg_mono_to_stereo, 
                                           &param );

      mpeg_mono_to_stereo_surround = 
         (ismd_audio_mpeg_mono_to_stereo_surround_t *)&param;
      *mpeg_mono_to_stereo_surround = 
         ISMD_AUDIO_MPEG_MONO_TO_STEREO_SURROUND_DISABLED;
      result = ismd_audio_decoder_param_set( proc_handle, 
                             input_handle, 
                             *mpeg_mono_to_stereo_surround, 
                             &param );
      
      return;
   }

*/


#ifndef _ISMD_AUDIO_MPEG_PARAMS_H_
#define _ISMD_AUDIO_MPEG_PARAMS_H_

/** @ingroup ismd_audio */
/** @{ */

/** Use these defines to change the MPEG decoder parameters */

/** Flag to specify duplication and/or scaling of mono signals to stereo. See \ref ismd_audio_mpeg_mono_to_stereo_t */
#define ISMD_AUDIO_MPEG_MONO_TO_STEREO                      0x300001  

/** Flag to specify duplication and/or scaling of S into Ls and Rs. See \ref ismd_audio_mpeg_mono_to_stereo_surround_t*/
#define ISMD_AUDIO_MPEG_MONO_TO_STEREO_SURROUND             0x300002

/** Flag to specify which channel the mono channel gets routed to. Valid valued for this are picked from \ref ismd_audio_channel_t*/
#define ISMD_AUDIO_MPEG_ROUTE_MONO_TO_CHANNEL_LOCATION      0x300003

/** Flag to dynamically enable/disbale downmixing. See \ref ismd_audio_mpeg_downmixer_t */
#define	ISMD_AUDIO_MPEG_DOWNMIXER_ON_OFF		            0x300004

/** Flag to specify Dual Mono mode. Valid valued for this are picked from \ref ismd_audio_mpeg_dual_mono_reproduction_mode_t*/
#define ISMD_AUDIO_MPEG_DUAL_MONO_REPRODUCTION_MODE         0x300005

/** Valid values to specify for decode param \ref ISMD_AUDIO_MPEG_MONO_TO_STEREO */
typedef enum {
   ISMD_AUDIO_MPEG_MONO_TO_STEREO_DISABLED = 0,   /** Mono streams are presented as a single channel routed to C (center) */
   ISMD_AUDIO_MPEG_MONO_TO_STEREO_ENABLED     /** Mono streams are presented as 2 identical channels (default) L = R = 0.707xC */
} ismd_audio_mpeg_mono_to_stereo_t;

/** Valid values to specify for decode param \ref ISMD_AUDIO_MPEG_MONO_TO_STEREO_SURROUND */
typedef enum {
   ISMD_AUDIO_MPEG_MONO_TO_STEREO_SURROUND_DISABLED = 0,   /** Mono surround streams are presented as a single channel routed to S (left surround) */
   ISMD_AUDIO_MPEG_MONO_TO_STEREO_SURROUND_ENABLED     /** Mono streams are presented as 2 identical channels (default) Ls = Rs = 0.707xS */
}  ismd_audio_mpeg_mono_to_stereo_surround_t;


/** Valid values to specify for decode param \ref ISMD_AUDIO_MPEG_DOWNMIXER_ON_OFF */
typedef enum {
   ISMD_AUDIO_MPEG_DOWNMIXER_DISABLE = 0,   /** Updown mixer produces multi channel output */
   ISMD_AUDIO_MPEG_DOWNMIXER_ENABLE     /** Updown mixer produces stereo output */
}  ismd_audio_mpeg_downmixer_t;

/** Valid values to specify for decode param \ref ISMD_AUDIO_MPEG_DUAL_MONO_REPRODUCTION_MODE */
typedef enum {
   ISMD_AUDIO_MPEG_DUAL_MONO_REPRODUCTION_MODE_STEREO = 0, //default
   ISMD_AUDIO_MPEG_DUAL_MONO_REPRODUCTION_MODE_LEFT_MONO, 
   ISMD_AUDIO_MPEG_DUAL_MONO_REPRODUCTION_MODE_RIGHT_MONO,
   ISMD_AUDIO_MPEG_DUAL_MONO_REPRODUCTION_MODE_MIXED_MONO
} ismd_audio_mpeg_dual_mono_reproduction_mode_t;

/**@}*/

#endif /* _ISMD_AUDIO_MPEG_PARAMS_H_ */
