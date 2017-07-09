/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

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

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.
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


#ifndef _EDL_AUDIO_DAC_H_
#define _EDL_AUDIO_DAC_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup edl_audio_dac 
 */
/** @{ 
 */

#include "osal.h"
#include "edl.h"

/**
* Data structure  for configuring DAC
*/  

#define EDL_AUDIO_DAC_MAX_CHANNELS 8

typedef enum {
   EDL_AUDIO_DAC_DATA_FORMAT_24_STD_RJ  = 1,
   EDL_AUDIO_DAC_DATA_FORMAT_20_STD_RJ  = 2,
   EDL_AUDIO_DAC_DATA_FORMAT_18_STD_RJ  = 3,
   EDL_AUDIO_DAC_DATA_FORMAT_16_STD_RJ  = 4,
   EDL_AUDIO_DAC_DATA_FORMAT_16_24_I2S  = 5,
   EDL_AUDIO_DAC_DATA_FORMAT_16_24_LJ   = 6
} edl_audio_dac_data_format_t;


typedef enum {
   EDL_AUDIO_DAC_OVERSAMPLING_RATE_32X  = 3,
   EDL_AUDIO_DAC_OVERSAMPLING_RATE_64X  = 4,
   EDL_AUDIO_DAC_OVERSAMPLING_RATE_128X = 5
} edl_audio_dac_oversampling_rate_t;

typedef enum {
   EDL_AUDIO_DAC_DEEMPHASIS_RATE_44_1KHZ = 1,
   EDL_AUDIO_DAC_DEEMPHASIS_RATE_48KHZ   = 2,
   EDL_AUDIO_DAC_DEEMPHASIS_RATE_32KHZ   = 3
} edl_audio_dac_deemphasis_rate_t ;

typedef enum {
   EDL_AUDIO_DAC_ROLLOFF_CONTROL_SHARP  = 1,
   EDL_AUDIO_DAC_ROLLOFF_CONTROL_SLOW   = 2,
} edl_audio_dac_rolloff_control_t;


typedef enum {
   EDL_AUDIO_DAC_OUTPUT_PHASE_NORMAL    = 1,
   EDL_AUDIO_DAC_OUTPUT_PHASE_INVERTED  = 2
} edl_audio_dac_output_phase_t;


#define EDL_AUDIO_DAC_VOLUME_MAX 100

typedef struct {
   unsigned int volume; /**< - Volume Level (0 to 100)        */
   bool         mute;   /**< - Mute channel (true or false)   */
   bool         enable; /**< - Enable channel (true or false) */
} dac_channel_config_t;


typedef struct {
   dac_channel_config_t              channel[EDL_AUDIO_DAC_MAX_CHANNELS];
   edl_audio_dac_oversampling_rate_t oversampling_rate; /**< - Oversampling rate            */
   bool                              deemphasis;        /**< - De-emphasis enable/disable   */
   edl_audio_dac_deemphasis_rate_t   deemphasis_rate;   /**< - De-emphasis rate             */
   edl_audio_dac_data_format_t       data_format;       /**< - Audio data format            */
   edl_audio_dac_rolloff_control_t   rolloff_control;   /**< - Digital filter rolloff ctrl  */
   edl_audio_dac_output_phase_t      output_phase;      /**< - Output phase                 */
   
   /* May need to add more stuff here to support other DACs. */

} edl_audio_dac_config_t;


/*! @name API for audio DAC units. */

/**
* Reset an audio DAC.  This sets the DAC to it's default state.
*
* @param dac_id : platform_specific identifier for the DAC.
*
* @retval EDL_SUCCESS : The DAC was successfully reset
* @retval EDL_FAILURE : on failure to reset
*/
edl_result_t edl_audio_dac_reset( int dac_id );


/**
* Configure an audio DAC (volume, format, phase, etc.).
*
* @param dac_id : platform_specific identifier for the DAC.
* @param config : pointer to a structure that contains all of the
* information required to configure the DAC.
*
* @retval EDL_SUCCESS : The DAC was configured successfully.
* @retval EDL_FAILURE : on failure to configure.
*/
edl_result_t edl_audio_dac_config_set( int                     dac_id, 
                                       edl_audio_dac_config_t *config );


/**
* Retrieve the configuration of an audio DAC (volume, format, phase, 
* etc.).
*
* @param dac_id : platform_specific identifier for the DAC.
* @param config_data : pointer to a structure to store all of the 
* dac configuration information.
*
* @retval EDL_SUCCESS : The configuration was retrieved successfully
* @retval EDL_FAILURE : The configuration could not be retrieved.
*/
edl_result_t edl_audio_dac_config_get( int                     dac_id, 
                                       edl_audio_dac_config_t *config );



#ifdef __cplusplus
}
#endif

#endif /* _EDL_AUDIO_DAC_H_ */
/*@}*/
