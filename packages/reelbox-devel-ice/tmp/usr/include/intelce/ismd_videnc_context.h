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
  Santa Clara, CA 97052

  BSD LICENSE

  Copyright(c) 2011 Intel Corporation. All rights reserved.

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

#ifndef __ISMD_VIDENC_CONTEXT_H__
#define __ISMD_VIDENC_CONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* This header file contains the definition of the video encoder context and
 * related structures. */
#include "ismd_videnc.h"
#include "videnc_hal.h"
#include "ismd_core.h"
#include "ismd_core_protected.h"
#include "osal.h"

/* Number of application specific events supported by the videnc driver */
#define VIDENC_NUM_OF_EVENTS 6

/* Enumeration for current encoder state */
typedef enum{
    VIDENC_STATE_INVALID,  /*Initial state of encoder*/
    VIDENC_STATE_OPEN,     /*When instance is opened*/
    VIDENC_STATE_CLOSE,    /*When instance is ready to be closed*/
    VIDENC_STATE_STOPPED,  /*When instance is stopped */
    VIDENC_STATE_STARTED   /*When instance is in play or pause state */
} videnc_state_t;

/* port events */
typedef enum {
   VIDENC_INPUT_LOW_WATERMARK,      /* event triggered when queue is at low watermark*/
   VIDENC_EOS_REACHED,              /* event triggered from eos message*/
} videnc_events_t;

typedef enum {
    VIDENC_INPUT_STALL_NONE,
    VIDENC_INPUT_STALL_FULL,
    VIDENC_INPUT_STALL_NO_DATA,
} videnc_input_stall_states;

/* Port structure */
typedef struct {
   ismd_port_handle_t port;         /*port handle*/
   os_thread_t thread;              /*thread that handles port operations*/

   ismd_event_t terminate_event;
   ismd_event_t startup_event;
   ismd_event_t buffer_received_event;
   ismd_event_t space_available;

   /*The following flags are used to track resources during shutdown*/
   bool port_created;         /*flag indicates if port creation succeeded*/
   bool thread_created;       /*flag indicates if thread creation succeeded*/
   bool thread_running;       /*Indicates whether the thread should continue running*/

   videnc_input_stall_states stall_state;
} videnc_input_t;

typedef enum {
    VIDENC_OUTPUT_STALL_NONE,
    VIDENC_OUTPUT_STALL_PORT_FULL,
    VIDENC_OUTPUT_STALL_NO_DATA,
} videnc_output_stall_states;

/* Port structure */
typedef struct {
   ismd_port_handle_t port;         /*port handle*/
   os_thread_t thread;              /*thread that handles port operations*/

   ismd_event_t terminate_event;
   ismd_event_t output_port_not_full_event;
   ismd_event_t output_data_available;

   /*The following flags are used to track resources during shutdown*/
   bool port_created;         /*flag indicates if port creation succeeded*/
   bool thread_created;       /*flag indicates if thread creation succeeded*/
   bool thread_running;       /*Indicates whether the thread should continue running*/

   videnc_output_stall_states stall_state;
} videnc_output_t;

/* Port structure */
typedef struct {
   ismd_port_handle_t port;         /*port handle*/

   ismd_event_t port_event;

   bool port_created;         /*flag indicates if port creation succeeded*/
} videnc_user_data_t;

/* Stream context */
typedef struct videnc_stream_context_t
{
   /*
    This handle is tracked by SMD_core, This is a unique handle
    that must be used when calling all videnc function exposed
    directly to application and indirect videnc functions
    (close, flush) exposed through ismd_dev_close, ismd_dev_flush
   */
   ismd_dev_t    ismd_dev_handle;

   /* This field tracks the codec format of the stream */
   ismd_codec_type_t    codec;

   /* This attribute is used for global management */
   bool in_use;  /* true -> stream context is currently active */

   /* This is the index into the context array. Will be used to name
      resources for this instance
    */
   int stream_id;
   
   /* Current state of this instance */
   videnc_state_t state;

   /* indicates whether the encoding params were set */
   bool enc_params_set;

   /* This is the handle to the HAL. This allows us to communicate with
      the underlying hardware platform.
    */
   videnc_hal_stream_t hal_stream_handle;

   /* statistics associated with this instance */
   ismd_videnc_stream_statistics_t statistics;

   /* Input port */
   videnc_input_t input;

   /* user data input port */
   videnc_user_data_t user_data_port;

    /* Output port */
   videnc_output_t output;

    /* this is a lock for the output q, which is accessed by o/p 
    * port thread and HAL 
    */
   os_sema_t output_q_lock; 
   bool output_q_lock_created;

   /* This is used to protect operations on shared structures by different
   apis or threads
   */
   os_sema_t context_lock;
   bool context_lock_created;

   /* Used to store the events registered by application for each condition
      The condition acts as the index into this array. */
   ismd_event_t event_array[VIDENC_NUM_OF_EVENTS];

   /* Context sven handle used for debugging multistream events... also see global videnc_sven_handle */
   os_devhandle_t *  sven_handle;

   /* stores the pts of the last frame buffer that was received */
   ismd_pts_t last_pts;

   /* stores the pts of user data that needs to be copied to next frame (if frame was dropped) */
   ismd_pts_t user_data_pts;

   /* stores the number of input frames that were rejected by the hal */
   uint32_t frames_dropped;

   /* if true, encoder driver will drop every other frame */
   bool reduce_frame_rate;

   /* counts the total number of frames received */
   uint32_t total_frames;

   /* indicates whether to drop the next frame (if requested policy is to reduce the frame rate) */
   bool drop_next_frame;

   /* indicates whether a discontinuity was detected on the input stream.
   this is used in case a frame with a discontinuity flag was dropped. 
   discontinuity data will be sent in with the next frame. */
   bool discontinuity;

   /* per input encoding policies */
   ismd_videnc_per_input_encoding_policies_t policies;

   /* input frame types */
   videnc_input_frame_type_t input_type;

   /* true if handling user data */
   bool handling_user_data;

   /* true if there is ISMD_VIDENC_H264_UD_RULE_TYPE_608_CC rule */
   bool have_cc608_rule;

   /* true if there is ISMD_VIDENC_H264_UD_RULE_TYPE_UD rule with dest_type of ISMD_VIDENC_H264_SEI_TYPE_UD_REGISTERED
      and orig_ud_type is ISMD_VIDENC_UD_INPUT_FRAME or ISMD_VIDENC_UD_INPUT_FIELD*/
   bool have_frame_field_to_registered_ud_rule;

   /* how many user data rules we have */
   uint32_t  num_ud_rules;

   ismd_videnc_h264_ud_rule ud_rules[MAX_UD_RULES];


   /* used only in reinterlacing case, when needed to wait for the "second" buffer */
   videnc_hal_input_data_t   reinterlacing_buf;

   /* indicate if we need to use reinterlacing_buf */
   bool have_reinterlacing_buf;

   /* helper index for parsing the reinterlacing_buf for the FW */
   uint8_t reinterlacing_buf_frame_index;

} videnc_stream_context_t;

#ifdef __cplusplus
}
#endif
#endif //__ISMD_VIDENC_CONTEXT_H_
