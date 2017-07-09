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

#ifndef _ISMD_AUDIO_SRS_H_
#define _ISMD_AUDIO_SRS_H_

#include "ismd_audio_type_defs.h"

/**************************************************************************/
/*! @SRS Audio Post Processing Pipeline Defines */
/**************************************************************************/
/** Please note that most of  the SRS parameters have the ranges documented in terms of floating point numbers. The audio driver requires the application to pass
these values to the API converted to fixed point values. Depending on the parameter, the precision is either 16 bit (audio_int16_t) or 32 bit (audio_int32_t) fixed point values.
The user should implement floating point to fixed point conversion functions in the application and pass the fixed point value to the audio driver. An example of such a
function for this conversion is given below. These examples accept the float as the desired value to be set. The second parameter is the scaling factor which is n-1 where
n is specified in the documentation as I16.n or I32.n. Please reference SMD sample applications for actual implementation of the conversion code.


   audio_int16_t convert_float_to_fxp16(float float_input, int scaling_factor){
		audio_int16_t max_16_bit_fixed_point_number = 0x7FFF;
		audio_int16_t min_16_bit_fixed_point_number = 0x8000;
		audio_int16_t max_fixed_point_for_this_scaling = ((audio_int64_t)1<<((16)-(scaling_factor)));
	    audio_int_16_t fixed_point_rep_of_floating_point_value = (val) *(max_fixed_point_for_this_scaling);
		if(float_input >= 0)
			float rounding_factor = 0.5;
		else
			float rounding_factor = -0.5;
		audio_int16_t converted number = (fixed_point_rep_of_floating_point_value + rounding_factor);
		if(converted_number > max_16_bit_fixed_point_number)
			converted_number = max_16_bit_fixed_point_number;
		else if(converted_number < min_16_bit_fixed_point_number)
			converted_number = min_16_bit_fixed_point_number;
   }

   A similar function can be written for 32 bit fixed point-

   audio_int32_t convert_float_to_fxp16(float float_input, int scaling_factor){
		audio_int32_t max_32_bit_fixed_point_number = 0x7FFFFFFF;
		audio_int32_t min_32_bit_fixed_point_number = 0x80000000;
		audio_int32_t max_fixed_point_for_this_scaling = ((audio_int64_t)1<<((32)-(scaling_factor)));
	    audio_int_32_t fixed_point_rep_of_floating_point_value = (val) *(max_fixed_point_for_this_scaling);
		if(float_input >= 0)
			float rounding_factor = 0.5;
		else
			float rounding_factor = -0.5;
		audio_int16_t converted number = (fixed_point_rep_of_floating_point_value + rounding_factor);
		if(converted_number > max_16_bit_fixed_point_number)
			converted_number = max_16_bit_fixed_point_number;
		else if(converted_number < min_16_bit_fixed_point_number)
			converted_number = min_16_bit_fixed_point_number;
   }

*/

/** Number of bands available in the SRS Parametric EQ. */
#define ISMD_AUDIO_SRS_PEQ_BANDS 8
/** Number of bands available in the SRS Graphic EQ. */
#define ISMD_AUDIO_SRS_GEQ_BANDS 5


/**See \ref ismd_audio_srs_truvolume_params_t*/
typedef enum {
   ISMD_AUDIO_SRS_TRUVOL_LIGHT = 0,
   ISMD_AUDIO_SRS_TRUVOL_NORM,
   ISMD_AUDIO_SRS_TRUVOL_HEAVY,
}ismd_audio_srs_tru_volume_mode_t;

/**See \ref ismd_audio_srs_cs_decoder_params_t*/
typedef enum {
   ISMD_AUDIO_SRS_CSD_MODE_CINEMA         = 1 << 0,
   ISMD_AUDIO_SRS_CSD_MODE_PRO            = 1 << 1,
   ISMD_AUDIO_SRS_CSD_MODE_MUSIC          = 1 << 2,
   ISMD_AUDIO_SRS_CSD_MODE_MONO           = 1 << 3,
   ISMD_AUDIO_SRS_CSD_MODE_LCRS           = 1 << 4
}ismd_audio_srs_cs_decoder_mode_t;

/**See \ref ismd_audio_srs_cs_decoder_params_t*/
typedef enum {
   ISMD_AUDIO_SRS_CSD_OUTMODE_STEREO,
   ISMD_AUDIO_SRS_CSD_OUTMODE_MULTICHS
}ismd_audio_srs_cs_decoder_output_mode_t;

/**See \ref ismd_audio_srs_tru_sur_hd_params_t*/
typedef enum {
   ISMD_AUDIO_SRS_TSHD_CXOVER_80Hz,   /** default */
   ISMD_AUDIO_SRS_TSHD_CXOVER_120Hz,
   ISMD_AUDIO_SRS_TSHD_CXOVER_160Hz,
   ISMD_AUDIO_SRS_TSHD_CXOVER_200Hz,
} ismd_audio_srs_tru_sur_hd_crossover_freq_t;

/** SRS input/output modes, used in some of the processing blocks.*/
typedef enum {
   ISMD_AUDIO_SRS_IO_1_0_0,
   ISMD_AUDIO_SRS_IO_2_0_0,
   ISMD_AUDIO_SRS_IO_3_0_0,
   ISMD_AUDIO_SRS_IO_2_0_1,
   ISMD_AUDIO_SRS_IO_3_0_1,
   ISMD_AUDIO_SRS_IO_2_2_0,
   ISMD_AUDIO_SRS_IO_3_2_0,
   ISMD_AUDIO_SRS_IO_2_2_1,
   ISMD_AUDIO_SRS_IO_3_2_1,
   ISMD_AUDIO_SRS_IO_2_1_0,
   ISMD_AUDIO_SRS_IO_3_1_0,
   ISMD_AUDIO_SRS_IO_2_1_1,
   ISMD_AUDIO_SRS_IO_3_1_1,
   ISMD_AUDIO_SRS_IO_2_3_0,
   ISMD_AUDIO_SRS_IO_3_3_0,
   ISMD_AUDIO_SRS_IO_2_3_1,
   ISMD_AUDIO_SRS_IO_3_3_1,
   ISMD_AUDIO_SRS_IO_LtRt,
   ISMD_AUDIO_SRS_IO_Headphone,
   ISMD_AUDIO_SRS_IO_BSDigital,
   ISMD_AUDIO_SRS_IO_PL2Music
} ismd_audio_srs_io_mode_t;

typedef enum
{
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_40Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_60Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_100Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_150Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_200Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_250Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_300Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_400Hz,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_Custom,
   ISMD_AUDIO_SRS_TB_SPEAKER_LF_RESPONSE_SIZES
} ismd_audio_srs_trubass_speaker_size_t;

/** Parameters used to configure the Tru Volume block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                 /** Set to true/false to enable/disable this block */
   audio_int16_t                    input_gain;             /** I16.6 0.0-32.0 converted to fixed point, 2^5 scaling */
   audio_int16_t                    output_gain;            /** I16.6 0.0-32.0 converted to fixed point, 2^5 scaling */
   audio_int16_t                    bypass_gain;            /** I16.1 0.0-1.0 converted to fixed point,  2^0 scaling */
   ismd_audio_srs_tru_volume_mode_t volume_mode;            /** 0,1 or 2 to set it to light, normal or heavy*/
}ismd_audio_srs_tru_volume_params_t;

/** Parameters used to configure the Circle Surround block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    center_full_band_enable;/** Enable or disable center full band option.*/
   audio_int16_t                    input_gain;             /** I16.1 0.0-1.0, converted to fixed point, 2^0 scaling */
   audio_int16_t                    lr_gain;                /** I16.3 0.0-1.0, converted to fixed point, 2^2 scaling */
   audio_int16_t                    lsrs_gain;              /** I16.3 0.0-1.0, converted to fixed point, 2^2 scaling */
   audio_int16_t                    center_gain;            /** I16.3 0.0-1.0, converted to fixed point, 2^2 scaling */
   ismd_audio_srs_cs_decoder_mode_t mode;                   /** Sets the CS decoder mode 0 for Cinema and 2 for Music*/
}ismd_audio_srs_cs_decoder_params_t;

/** Parameters used to configure the Tru Dialog block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                 /** Set to true/false to enable/disable this block */
   audio_int16_t                    input_gain;             /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    output_gain;            /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    bypass_gain;            /** I16.3 0.0-4.0 converted to fixed point, 2^2 scaling */
   audio_int16_t                    clarity_gain;           /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int32_t                          process_gain;           /** I32.3 0.5-3.0 converted to fixed point, 2^2 scaling */
}ismd_audio_srs_tru_dialog_params_t;

/** Parameters used to configure the Tru Surround HD block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                     /** Set to true/false to enable/disable this block */
   bool_shared_t                    dialog_clarity_enable;      /** Set to true/false to enable/disable dialog clarity. */
   bool_shared_t                    front_def_enable;           /** Set to true/false to enable/disable front definition*/
   bool_shared_t                    front_tru_bass_enable;      /** Set to true/false to enable/disable front definition*/
   bool_shared_t                    center_def_enable;          /** Set to true/false to enable/disable center definition */
   bool_shared_t                    wowhd_srs3d_enable;         /** Set to true/false to enable/disable center definition */
   bool_shared_t                    wowhd_focus_enable;         /** Set to true/false to enable/disable center definition */
   audio_int16_t                    input_gain;                 /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    output_gain;                /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    bypass_gain;                /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    surround_level;             /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    dialog_clarity_factor;      /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    front_def_factor;           /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    front_tru_bass_factor;      /** I16.1 converted to fixed point, 2^0 scaling */
   ismd_audio_srs_trubass_speaker_size_t front_tru_bass_speaker_size;/** 0-9 enum to set various values */
   audio_int16_t                    front_tru_bass_mode;        /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    center_def_factor;          /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    wowhd_srs3d_space_control;  /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    wowhd_srs3d_center_control; /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    wowhd_srs3d_is_high_bitrate;/** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    wowhd_srs3d_mode;           /** I16.1 converted to fixed point, 2^0 scaling */
   audio_int16_t                    wowhd_focus_control;        /** I16.1 converted to fixed point, 2^0 scaling */
   ismd_audio_srs_tru_sur_hd_crossover_freq_t freq;             /** Crossover frequency for Tru Sur HD*/
   ismd_audio_srs_io_mode_t         input_mode;                 /** ISMD_AUDIO_SRS_IO_LtRt or ISMD_AUDIO_SRS_IO_2_0_0 */
}ismd_audio_srs_tru_sur_hd_params_t;

/** Parameters used to configure the Graphic EQ block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                 /** Set to true/false to enable/disable this block */
   bool_shared_t                    limiter_enable;         /** Set to true/false to enable/disable limiter. */
   audio_int16_t                    input_gain;             /** I16.1 0.0-10.0, converted to fixed point, 2^0 scaling */
   audio_int16_t                    output_gain;            /** I16.1 0.0-10.0, converted to fixed point, 2^0 scaling */
   audio_int16_t                    bypass_gain;            /** I16.1 0.0-10.0, converted to fixed point, 2^0 scaling */
   audio_int16_t                    band_gain[ISMD_AUDIO_SRS_GEQ_BANDS]; /** I16.3 0.316- 3.16, converted to fixed point, 2^2 scaling.*/
}ismd_audio_srs_geq_params_t;

/** Parameters used to configure the Parametric EQ block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                 /** Set to true/false to enable/disable this block */
   audio_int16_t                    input_gain;             /** I16.4 0.0-10.0, converted to fixed point, 2^3 scaling */
   audio_int16_t                    output_gain;            /** I16.4 0.0-10.0, converted to fixed point, 2^3 scaling */
   audio_int16_t                    bypass_gain;            /** I16.4 0.0-10.0, converted to fixed point, 2^3 scaling */
}ismd_audio_srs_peq_params_t;

/** Parameters used to configure the hard limiter block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                 /** Set to true/false to enable/disable this block */
   audio_int16_t                    input_gain;             /** I16.3 0.0-4.0 converted to fixed point, 2^2 scaling */
   audio_int16_t                    output_gain;            /** I16.3 0.0-4.0 converted to fixed point, 2^2 scaling */
   audio_int16_t                    bypass_gain;            /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int16_t                    limit;                  /** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   audio_int32_t                    boost;                  /** I32.9 0.001-256.0 converted to fixed point, 2^8 scaling */
   audio_int32_t                    delay_length;           /** 6-240, Set the delay length*/
}ismd_audio_srs_hard_limiter_params_t;

/** Parameters used to configure the hard limiter block in the SRS pipeline.*/
typedef struct {
   bool_shared_t                    enable;                 /** Set to true/false to enable/disable this block */
}ismd_audio_srs_filter_params_t;




/** The SRS audio processing pipeline is setup in fixed blocks or stages
    as specified by SRS. Use these parameters to configure the SRS audio
    processing pipeline. Use the enable flag in each block params specfied
    to enable or disable the processing block. All blocks are disabled by default.*/
typedef struct {
   ismd_audio_srs_filter_params_t         filter1;          /** SRS pipe location: 0, filter before TruVolume */
   ismd_audio_srs_tru_volume_params_t     tru_volume;       /** SRS pipe location: 1 */
   ismd_audio_srs_cs_decoder_params_t     cs_decoder;       /** SRS pipe location: 3 */
   ismd_audio_srs_tru_dialog_params_t     tru_dialog;       /** SRS pipe location: 4 */
   ismd_audio_srs_tru_sur_hd_params_t     tru_sur_hd;       /** SRS pipe location: 5 */
   ismd_audio_srs_geq_params_t            graphic_eq;       /** SRS pipe location: 6 */
   ismd_audio_srs_peq_params_t            parametric_eq;    /** SRS pipe location: 7 */
   ismd_audio_srs_filter_params_t         filter2;          /** SRS pipe location: 8, filter before hard limiter.*/
   ismd_audio_srs_hard_limiter_params_t   hard_limiter;     /** SRS pipe location: 9 */
   audio_int16_t                          headroom_gain;	/** I16.1 0.0-1.0 converted to fixed point, 2^0 scaling */
   bool_shared_t                          master_bypass;    /** Bypass all SRS processing, but keeps stage in post procesing pipe.*/
}ismd_audio_srs_pipe_params_t;

/**************************************************************************/

#endif /* _ISMD_AUDIO_SRS_H_ */

