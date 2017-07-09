/*
   This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2010 Intel Corporation. All rights reserved.
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
#ifndef ISMD_AUDIO_MS10_H
#define ISMD_AUDIO_MS10_H

/* These are the available user configurable options on the MS10 DDC/DDT decoder.*/

/*DDT testmode on/off flag*/
#define ISMD_AUDIO_DDT_DDCE_TESTMODEON    		0xaac000

/*set aac format, whether ADTS or LOAS*/
#define ISMD_AUDIO_DDT_AAC_BSFORMAT       		0xaac001

/*set RF mode, valid value is 0(Lineout) or 1(Rf)*/
#define ISMD_AUDIO_DDT_PP_RFMODE          		0xaac002

/*set post proc downmix mode, valid data is 0(LtRt) or 1 (LoRo)*/
#define ISMD_AUDIO_DDT_PP_DWNMIX          		0xaac003

/*set Boost Factor, valid value 0~100(step 1) represents real value of 0~1(step 0.01)*/
#define ISMD_AUDIO_DDT_PP_DRCCUTFAC       		0xaac004

/*set Boost Factor, valid value 0~100(step 1) represents real value of 0~1(step 0.01)*/
#define ISMD_AUDIO_DDT_PP_DRCBOOSTFAC     		0xaac005

/*set Dual Mode. valid data:
  *0: Stereo (default) \n
  *1: Left mono signal at both output channels, attenuated by 3 dB
  *2: Right mono signal at both output channels, attenuated by 3 dB  */
#define ISMD_AUDIO_DDT_PP_DRCDUALMODE     		0xaac006

/*flag to determine if packetize encoded AC3 frame with IEC61937 or not*/
#define ISMD_AUDIO_DDT_ENC_PACKETIZE      		0xaac007

#define ISMD_AUDIO_DDC_DCV_PACKETIZE 			0xddc000
#define ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_MODE 	0xddc001

/*Flag to determine if user input channel mixer coeff apply into main audio or assoc audio or both. */
/*This flag is only avaible under ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_MODE case. */
#define ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_MODE       0xddc002

#define ISMD_AUDIO_MS10_DOLBY_PULSE_BSFORMAT_ADTS 2
#define ISMD_AUDIO_MS10_DOLBY_PULSE_BSFORMAT_LOAS 5

/* This command sets the MS10 DDT DDCE to testmode. Enable testmode (1) or Disable testmode (0). Diable as default */
typedef int ismd_audio_ms10_ddt_ddce_testmode_t;

/* This command sets the RF mode. valid values are 0(Lineout) or 1(RF). 0 by default */
typedef int ismd_audio_ms10_ddt_pp_rfmode_t;

/* This command sets the post proc downmix mode. valid values are 0(LtRt) or 1 (LoRo). 0 by default */
typedef int ismd_audio_ms10_ddt_pp_dwnmix_t;

/* This command sets the Cut Factor. Valid values are 0~100(step 1) representing real values of 0~1(step 0.01). 0 by default */
/* Valid scale factors use 1.14 fixed point intergers. */
/* range is from 0 through 0x4000 */
/* where 0=0, and MAX(1.0) = 0x4000,  */
/* 50% = (int)(0x4000*0.50), 25% = (int)(0x4000*0.25), ..etc */
typedef int ismd_audio_ms10_ddt_pp_drccutfac_t;

/* This command sets the Boost Factor. Valid values are 0~100(step 1) representing real values of 0~1(step 0.01). 0 by default . */
/* Valid scale factors use 1.14 fixed point intergers. */
/* range is from 0 through 0x4000 */
/* where 0=0, and MAX(1.0) = 0x4000,  */
/* 50% = (int)(0x4000*0.50), 25% = (int)(0x4000*0.25), ..etc */
typedef int ismd_audio_ms10_ddt_pp_drcboostfac_t;

/* This command sets the channel mode. Valid values are 0: Stereo, 1: Left mono signal at both output channels, 2: Right mono signal at both output channels, . 0 by default */
typedef int ismd_audio_ms10_ddt_pp_drcdualmode_t;

/* This command sets the MS10 DDT BSFORMAT. Valid value: ISMD_AUDIO_MEDIA_FMT_AAC, ISMD_AUDIO_MEDIA_FMT_AAC_LOAS. AAC as default */
typedef int ismd_audio_ms10_dolby_pulse_bsformat_t;

/* This command sets the MS10 DDC packetizer mode: Enable (1) or disable (0). Enable as default */
typedef int ismd_audio_ms10_ddc_packetizer_enable_t;

/* This command sets the MS10 DDC single input with dual decoding mode: Enable (1) or disable (0). Disable as default */
typedef int ismd_audio_ms10_ddc_single_input_dual_mode_t;

/* This command determines whether the MS10 DDC associated audio accept user input channel mixer coeff settings
* ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_DUP: user mixer coeff apply into both main and assoc audio
* ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_MAIN:user mixer coeff apply into main audio
* ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_ASSOC:user mixer coeff apply into associated audio
* Only avaible under ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_MODE case */
typedef enum {
      ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_DUP,
      ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_MAIN,
      ISMD_AUDIO_DDC_SINGLE_INPUT_DUAL_CH_MIX_ASSOC,
   } ismd_audio_ms10_ddc_single_input_dual_ch_mix_mode_t; 


#endif
