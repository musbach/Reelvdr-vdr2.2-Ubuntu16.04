/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2008-2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2006-2009 Intel Corporation. All rights reserved.
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

This file defines the parameters for the Dolby Digital TRUE-HD decoder.  The 
defines and enums are intended to be used when calling the functions
ismd_audio_input_set_decoder_param() and ismd_audio_input_get_decoder_param().

Example usage: 

   void set_codec_parameters( ismd_audio_processor_t proc_handle,
                              ismd_dev_t             input_handle )
   {
      ismd_result_t                          result;
      ismd_audio_codec_param_t               param;
      ismd_audio_truehd_drc_enable_t        *drc_enable;

      drc_enable = (ismd_audio_truehd_drc_enable_t *)&param;
      *drc_enable = 1;  // AUTO mode
      result = ismd_audio_decoder_param_set( proc_handle, 
                                           input_handle, 
                                           ISMD_AUDIO_TRUEHD_DRC_ENABLE, 
                                           &param );
      
      return;
   }

*/

#ifndef _ISMD_AUDIO_TRUEHD_PARAMS_H_
#define _ISMD_AUDIO_TRUEHD_PARAMS_H_

#define ISMD_AUDIO_TRUEHD_DECODE_MODE        0x700  /* see ismd_audio_truehd_decode_mode_t */
#define ISMD_AUDIO_TRUEHD_ZERO_UNUSED_CHANS  0x701  /* see ismd_audio_truehd_zero_unused_chans_t */
#define ISMD_AUDIO_TRUEHD_BLOCK_CRC          0x702  /* see ismd_audio_truehd_block_crc_t */
#define ISMD_AUDIO_TRUEHD_LOSSLESS           0x703  /* see ismd_audio_truehd_lossless_t */
#define ISMD_AUDIO_TRUEHD_DRC_ENABLE         0x704  /* see ismd_audio_truehd_drc_enable_t */
#define ISMD_AUDIO_TRUEHD_DRC_CUT            0x705  /* see ismd_audio_truehd_drc_cut_t */
#define ISMD_AUDIO_TRUEHD_DRC_BOOST          0x706  /* see ismd_audio_truehd_drc_boost_t */
#define ISMD_AUDIO_TRUEHD_DIALOG_REF         0x707  /* see ismd_audio_truehd_dialog_ref_t */
#define ISMD_AUDIO_TRUEHD_FBA_CH_REORDER     0x708  /* see ismd_audio_truehd_fba_chan_reorder_t */
#define ISMD_AUDIO_TRUEHD_METADATA           0x709  /* see ismd_audio_truehd_metadata_t */

/** 
\deprecated 
This feature is no longer supported by TrueHD Decoder v2.2. 
 */
#define ISMD_AUDIO_TRUEHD_DIALOG_REF_DEFAULT   -100   /* Flag to reset the dialog reference in the codec, used as param for ISMD_AUDIO_TRUEHD_DIALOG_REF API*/

/* This command sets the decode_mode and configures the decoder as a two-, six- or eight-channel decoder. Valid values are 2, 6, and 8 (default)*/
typedef int ismd_audio_truehd_decode_mode_t;

/* Enable (1 default) or disable (0) zeroing of unused output channels. */
typedef int ismd_audio_truehd_zero_unused_chans_t;

/* This command enables (1 default) or disables (0) the CRC check on the block headers. */
typedef int ismd_audio_truehd_block_crc_t;

/* This command enables (0 default) and disables (1) the post-processing modules (dialogue normalization and dynamic range compression). */
typedef int ismd_audio_truehd_lossless_t;

/* This command sets the DRC mode: 0 – off, 1 – auto (default), 2 – forced. */
typedef int ismd_audio_truehd_drc_enable_t;

/* This command sets the DRC cut percentage value. Valid values: 0 to 100 (default).*/
typedef int ismd_audio_truehd_drc_cut_t;

/* This command sets the DRC percentage boost value. Valid values: 0 to 100 (default).*/
typedef int ismd_audio_truehd_drc_boost_t;

/**
\deprecated 
This feature is no longer supported by TrueHD Decoder v2.2. 
 */
typedef int ismd_audio_truehd_dialog_ref_t;

/* This command reroutes the FBB stream channels to match the FBA channel order. Default is 0 (no rerouting). Valid values: 0 (default), 1*/
typedef int ismd_audio_truehd_fba_chan_reorder_t;

/* This command enables metadata extraction from the TrueHD stream. Default is 1 (metadata information extracted). Valid values: 0 , 1 (default)*/
typedef int ismd_audio_truehd_metadata_t;

#endif /* _ISMD_AUDIO_TRUEHD_PARAMS_H_ */
