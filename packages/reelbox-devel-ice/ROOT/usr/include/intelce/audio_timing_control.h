/*  
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2007-2009 Intel Corporation. All rights reserved.
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

 /* AUDIO TIMING CONTROL (ATC) */
 
#ifndef _AUDIO_ATC_H_
#define _AUDIO_ATC_H_

#include "osal.h"
#include "ismd_audio_defs.h"
#include "ismd_core_protected.h"
#include "ismd_core.h"

/** Handle to a ATC instance. 
  audio_atc_t */
typedef int audio_atc_t;

/** Handle to an ATC stream. 
  audio_atc_stream_t */
typedef int audio_atc_stream_t;

typedef enum {
   ATC_OUTPUT_DISCARD_POLICY_INVALID,
   ATC_OUTPUT_DISCARD_ON_RENDER_NOT_PRESENT,
   ATC_OUTPUT_DISCARD_NEVER
}atc_output_discard_policy_t;

typedef struct {
   ismd_newsegment_tag_t  curr_seg_info; //Copy of the last new segment info
   int curr_rate; //Possibly changed out of band.
   ismd_pts_t last_linear_rate_change_time;
   ismd_pts_t last_scaled_rate_change_time;
}audio_time_rebase_info_t;

ismd_result_t
audio_timing_control_initialize(void);

ismd_result_t
audio_timing_control_deinitialize(void);

ismd_result_t
audio_timing_control_open(audio_atc_t *atc_h, int association_id);

ismd_result_t
audio_timing_control_close(audio_atc_t atc_h);

ismd_result_t
audio_timing_control_change_chunk_period(audio_atc_t atc_h, int chunk_period);

ismd_result_t
audio_timing_control_get_clock_alarm_period(audio_atc_t atc_h, int *chunk_period);

ismd_result_t
audio_timing_control_set_output_queue_lock( audio_atc_t atc_h, os_mutex_t *output_queue_lock);

ismd_result_t
audio_timing_control_add_stream
(
   audio_atc_t atc_h,
   bool is_timed_stream,
   bool is_encoded_data,
   ismd_queue_handle_t input_queue,
   ismd_queue_handle_t output_queue,
   const ismd_event_t event_list[],
   int input_smd_h,
   audio_atc_stream_t *atc_stream_h
);

ismd_result_t
audio_timing_control_get_message_context
(
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h,
   uint32_t *message_context
);

ismd_result_t
audio_timing_control_remove_stream
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h
);

ismd_result_t
audio_timing_control_set_base_time
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_time_t base_time
);

ismd_result_t
audio_timing_control_set_as_primary( audio_atc_t atc_h, audio_atc_stream_t atc_stream_h);

ismd_result_t
audio_timing_control_set_silence_insert
(
   audio_atc_t atc_h, 
   bool insert_silence
);

ismd_result_t
audio_timing_control_set_fast_output
(
   audio_atc_t atc_h, 
   bool fast_output
);

ismd_result_t
audio_timing_control_set_discont_metadata_policy
(
   audio_atc_t atc_h, 
   bool insert_discontinuity_metadata
);

ismd_result_t
audio_timing_control_stream_set_fast_output
(
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   bool fast_output
);

ismd_result_t
audio_timing_control_set_output_discard_policy
(
   audio_atc_t atc_h, 
   atc_output_discard_policy_t discard_policy
);

ismd_result_t
audio_timing_control_set_stream_pos_mem_locaton
(
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_audio_stream_position_info_t *stream_pos_ptr
);

ismd_result_t
audio_timing_control_set_clock
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_clock_t clock_h
);

ismd_result_t
audio_timing_control_set_slave_clock
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_clock_t clock_h
);

ismd_result_t
audio_timing_control_set_timing_mode
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_timing_mode_t timing_mode 
);

ismd_result_t
audio_timing_control_set_newsegment_policy
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_newsegment_policy_t policy
);

ismd_result_t
audio_timing_control_get_stream_info
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   audio_buffer_attr_t *stream_info
); 

ismd_result_t
audio_timing_control_set_state
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_dev_state_t state
); 

ismd_result_t
audio_timing_control_get_state
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_dev_state_t *state
); 

ismd_result_t
audio_timing_control_flush
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h 
); 

ismd_result_t
audio_timing_control_set_playback_rate
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_pts_t current_linear_time,
   int rate 
); 

ismd_result_t
audio_timing_control_set_start_pts
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_pts_t start_pts 
);

ismd_result_t
audio_timing_control_disable_stream
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h
);

ismd_result_t
audio_timing_control_enable_stream
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h
); 

ismd_result_t
audio_timing_control_set_timing_accuracy
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h,
   int allowed_ms_drift_ahead,
   int allowed_ms_drift_behind
);

ismd_result_t
audio_timing_control_get_underrun_amount
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_time_t *underrun_amount
); 

ismd_result_t
audio_timing_control_set_underrun_event
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   ismd_event_t underrun_event
);

ismd_result_t
audio_timing_control_set_fixed_delay
(
   audio_atc_t atc_h,
   unsigned int fixed_back_end_delay_ms
);

ismd_result_t
audio_timing_control_set_segment_info
( 
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h, 
   audio_time_rebase_info_t seg_info
);

ismd_result_t
audio_timing_control_suspend(void);

ismd_result_t
audio_timing_control_resume(void);

ismd_result_t
audio_timing_control_set_clock_mode
(
   ismd_audio_clk_mode_t clk_mode
);

ismd_clock_t *
audio_timing_control_get_timer_clock(void);

ismd_result_t
audio_timing_control_enable_vsrc_support
(
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h
);

ismd_result_t
audio_timing_control_disable_vsrc_support
(
   audio_atc_t atc_h, 
   audio_atc_stream_t atc_stream_h
);

ismd_result_t
audio_timing_control_asrc_set_target_sample_rate
(
   audio_atc_t atc_h, 
   unsigned int mixer_sample_rate
);

#endif

