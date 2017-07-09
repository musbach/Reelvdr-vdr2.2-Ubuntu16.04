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

#ifndef __VIDENC_HAL_PVT_H__
#define __VIDENC_HAL_PVT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_videnc.h"
#include "osal.h"
#include "pal.h"
#include "pal_interrupt.h"
#include "auto_eas/sw_encoder.h"
#include "ismd_core.h"
#include "ismd_core_protected.h"
#include "ismd_global_defs.h"
#include "thread_utils.h"
#include "videnc_hal.h"
#include "ces_host_videnc.h"
   
/* This file defines private data structures used by the hal. 
 */
#define  VIDENC_HAL_MAX_FW_FRAME_BUFFERS 11
#define  VIDENC_HAL_TIMEOUT 2000
#define  VIDENC_HAL_ES_BUF_ALLOC_FAILURE_LIMIT 10

// This flag enables processing of partial workloads in
// case there isn't enough room on the output queue for the
// full workload.
#define  VIDENC_HAL_PROCESS_PARTIAL_WKLD    1

/*
 * The driver always uses at least this many workloads.
 * On CE 5300, where there are B Frames and also possibly
 * lookahead buffers for scene change detection, there can
 * be more, but this is computed dynamically, to avoid using
 * too many buffers and too much memory for raw YUV data frames.
 */

#define  VIDENC_HAL_NUM_WKLDS_FOR_DRIVER 2

/* wkld ids that are sent to the FW are 4 bytes long where the least significant byte
   is the wkld array index, and the other 3 are a semi-unique identifier (for the sake
   of FW debuging */
#define  VIDENC_HAL_WKLD_ID_MASK 0xFF
#define  VIDENC_HAL_GET_WKLD_INDEX(a) (a&VIDENC_HAL_WKLD_ID_MASK)
#define  VIDENC_HAL_GET_WKLD_ID(a) ((a)>>8)
#define  VIDENC_HAL_CALC_WKLD_ID(index, id) (((id)<<8)|(index))

#define MFPS_CLOCK 90000000

/* Buffer size to allocate for output ES buffers.
   Any size less than the SMD core page size (default 512kB) will work */
#define VIDENC_OUTPUT_BUFFER_SIZE (32*1024)

/* bottom half handler can be interrupt driven or polled driven */
typedef enum
{
   VIDENC_ISR_POLLED_DRIVEN  = 0,
   VIDENC_ISR_INTR_DRIVEN    = 1
} videnc_hal_isr_mode_t;

/* HAL queue size */
#define VIDENC_HAL_Q_SIZE 64
#define VIDENC_HAL_MAX_FB_MD_Q_SIZE 64
#define VIDENC_HAL_MAX_OUTPUT_Q_SIZE 64

/** Macros to simplify hal locking */
#define HAL_LOCK_CONTEXT()    os_sema_get(&context->context_lock)
#define HAL_UNLOCK_CONTEXT()  os_sema_put(&context->context_lock)

/** Mask for any kind of SEI or user data */
#define VIDENC_WORKLOAD_ANY_SEI_DATA \
       ( VIDENC_WORKLOAD_FRAME_LEVEL_USER_DATA | VIDENC_WORKLOAD_TOP_FIELD_LEVEL_USER_DATA | \
         VIDENC_WORKLOAD_BOTTOM_FIELD_LEVEL_USER_DATA | VIDENC_WORKLOAD_REGISTERED_USER_DATA | \
         VIDENC_WORKLOAD_UNREGISTERED_USER_DATA | VIDENC_WORKLOAD_SEI_FRAME_PACKING_MESSAGE )

/* This struct pairs a workload pointer with its physical address */
typedef struct
{
    /* pointer to wkld */
    videnc_frm_wkld_t *wl;
    /* phy address of wkld */
    int phy_add;

   /* Flags passed on input for this workload. */
   uint32_t wkld_input_flags;
} videnc_hal_wkld_t;

/* HAL buffer queue */
typedef struct
{
   int head;
   int tail;
   int num_elements; /* number of elements in the q*/
   int max_elements;
   int elem[VIDENC_HAL_Q_SIZE]; /*buf handle for wkld*/
   ismd_event_t q_event; /* event that is triggered when the q goes from full to unfull */
   os_sema_t q_lock;
   bool q_lock_created;
} videnc_hal_q_t;

/* This struct stores frame buffer metadata that needs to be propagated in display order. */
typedef struct
{
    /* true - if the source of the tag data is a zero sized buffer, 
       or a frame_buffer that was dropped. In this case data should be copied
       to subsequent frame. */
    bool tags_only;
    /* a zero sized buffer storing the tag info, or -1 if there is no tag data */
    ismd_buffer_handle_t tag_info;
} videnc_hal_fb_metadata_t;

/* Driver tag types */
enum videnc_driver_tag_type
{
    VIDENC_DRIVER_TIMING = (1<<0)
};

typedef struct
{
    uint32_t field_counter; /* # fields already entered to fw including this frame  */
    uint32_t frame_rate; /* current frame rate */
} videnc_timing_tag_t;

/* 12-byte tag */
typedef struct
{
    enum videnc_driver_tag_type tag_type;
    union
    {
        videnc_timing_tag_t timing;
    };
} videnc_driver_tag_t;

/* frame buffer metadata queue - stores videnc_hal_fb_metadata_t in display order */
typedef struct
{
   int head;
   int tail;
   int num_elements; /* number of elements in the q*/
   videnc_hal_fb_metadata_t elem[VIDENC_HAL_MAX_FB_MD_Q_SIZE]; /*buf handle for wkld*/
   os_sema_t q_lock;
   bool q_lock_created;
} videnc_hal_fb_metadata_q_t;

typedef enum
{
    WKLD_THREAD_STALL_NONE,
    WKLD_THREAD_STALL_OUTPUT_FULL,
    WKLD_THREAD_OUT_OF_RESOURCES
} wkld_thread_stall_state_t;

/* wkld manager */
typedef struct
{
   /* array of wklds used by this context */
   videnc_hal_wkld_t wklds[VIDENC_HAL_Q_SIZE];
   /* queue to store empty workloads */
   videnc_hal_q_t empty_wkld_queue;
   /* pointer to smd bufer - must be cached memory */
   ismd_buffer_handle_t wkld_mem;
   /* pointer to the cached memory */
   void* virt_memory_pointer;
   /* stores the size of the cached memory */
   int virt_memory_size;
   /* running counter of the wklds used - used to create unique wkld id for FW */
   uint32_t wkld_counter;
} videnc_hal_wkld_manager_t;

/* wkld thread */
typedef struct
{
   /*this thread reads workloads from the encoder and processes them*/
   os_thread_t wkld_handler_thread;
   bool wkld_handler_thread_created;
   bool wkld_handler_thread_running;

   /*this event will be strobed at close*/
   ismd_event_t terminate_wkld_handler_thread;

   /*this event wakes up workload handler thread*/
   ismd_event_t wkld_handler_event;
   
   /* current frame rate */
   unsigned int input_cont_rate;

   /* Number of es buffers currently in the system - this is used for internal debugging. It is not currently protected by locks*/
   unsigned long num_es;

   /* stall state */
   wkld_thread_stall_state_t stall_state;

   /* stores the size of the current AU. This is 0 if it is not set.*/
   uint32_t au_size;

   /* these are used to store the place in the current wkld being processed */
   int section_num;
   int item_num;

   /* store timing information about the current wkld being processed */
   videnc_timing_tag_t current_frame_timing;

   /* count number of fields that were encoded (include repetition) */
   uint32_t output_fields_counter;

   /* debug flag that indicates whether the pts and dts values on the output
      are in synch. In CE4200 they should always be equal */
   bool synch;
} videnc_hal_wkld_handler_t;


/* handle to fw 
 */
typedef unsigned int videnc_fw_handle_t; 

/* stores list of driver callbacks and the data that should 
 * be passed to the driver when calling the callbacks 
 */
typedef struct
{
   videnc_hal_events_t event_handlers;
   void *data;
} videnc_hal_driver_callbacks_t;

/* This is the HAL context structure for a stream */
typedef struct videnc_hal_context_t
{
   /* This is used to protect operations on shared structures by different
   apis or threads
   */
   os_sema_t context_lock;
   bool context_lock_created;

   /* list of driver callbacks for this context and the data that should 
    * be passed to the driver when calling the callbacks 
    */
   videnc_hal_driver_callbacks_t callbacks;

   /* this denotes if context is in use. Initialize to false at 
    * init time and when stream is closed. 
    */
   bool context_in_use;

   /* this denotes if interrupts are enabled on this stream.
    */
   bool interrupts_enabled;

   /* this denotes if device is in play state.
    */
   bool running;

   /* determines whether the output is in monochrome mode */
   bool monochrome;

   /* handle to encoder module instance for this stream */
   videnc_fw_handle_t str_handle;

   /* handle to memory allocated for encoder for this stream*/
   ismd_buffer_handle_t str_fw_mem_handle;

   /* fw frame buffer handles */
   ismd_buffer_handle_t str_fw_fb_handles[VIDENC_HAL_MAX_FW_FRAME_BUFFERS];

   /* counts the number of times that es buffer allocation failed */
   int es_buffer_alloc_failure_counter;

   /* This field tracks the codec format of the stream */
   ismd_codec_type_t codec;
   


   /* All the resources needed by the FW - frame buffers and encoding parameters */
   codec_specific_setting_t  resources;
   codec_specific_setting_t* resources_copy;	/* this is for the FW */

   /* Bookkeeping for the copy which is in physical memory */
   ismd_buffer_handle_t resources_buf_handle;
   ismd_buffer_descriptor_t resources_desc;
   bool resources_copy_is_mapped;

   /*
    * Set bits here when a change occurs, copy this to the relevant frame
    * and then clear it back.
    */
   videnc_wkld_flags_t workload_flags;

   codec_specific_setting_desc_t  codec_settings;
   // in init: codec_settings.driver_buffer_id = index<<24;
   // codec_settings.phys_addr = virt2phys(& this->enc_params);

   /* workload handler thread */
   videnc_hal_wkld_handler_t wkld_thread;

   /* workload manager */
   videnc_hal_wkld_manager_t wkld_manager;

   /* queue to store workloads read from the encoder fw */
   videnc_hal_q_t wkld_queue;

   /* queue to store es buffers generated by the encoder */
   videnc_hal_q_t output_queue;
   
   /* queue for storing the frame buffer metadata in display order
   for propagating dtses and tag data to the output */
   videnc_hal_fb_metadata_q_t fb_md_q;

   /* statistics associated with this instance */
   videnc_hal_stream_statistics_t statistics;

   // This is a template for each frame to be sent to the FW.
   // The driver initializes each workload from this and then sets
   // up the per-workload info such as the handles for the frames.
   //
   // The template includes
   // - frame width/height
   // - bitrate settings
   videnc_frm_wkld_t workload_template;

   /* stores whether low ip state was reached */
   bool low_ip;

   /* if true, reuse the end of sequence from the input stream */
   bool reuse_input_end_sequence;

   /* if true, a real end of sequence */
   bool saw_input_end_sequence;

   /*
    * Encoder settings from the user:
    * - aspect ratio mechanism as chosen by user
    * - qp mode
    */
   ismd_videnc_h264_aspect_ratio_t aspect_ratio;
   ismd_videnc_h264_qp_mode_t qp_mode;

   /* input encoding policies */
   ismd_videnc_per_input_encoding_policies_t policies;

   /* EPU settings */
   videnc_stream_epu_settings_t epu_settings;

   /* max num of wklds to allow for this instance */
   int max_wklds;
   
   /* true if workload queues have been setup */
   bool workload_queues_inited;

   /* for debugging prints */
   bool print;

   /*
    * keep the mfps that came with the last video frame - this value will be used when
    * EOS arrive
    */
   uint32_t last_mfps;

   /* keep track of how many consecutive times we drop frames */
   uint32_t consecutive_problems;

   /* true if initialized all the various and sundry queues */
   bool queues_inited;

   /* count the number of fields that were sent to the fw */
   uint32_t input_fields_counter;

} videnc_hal_context_t;

/* these are global state variables that the HAL maintains */

/* Global hal data structure */
typedef struct 
{
   /* devh for all SVEN events */
   os_devhandle_t          *devh;
 
   /* indicates whether fw was loaded */
   bool fw_loaded;

   /* polled or interrupt based isr, this maintains a copy 
    * from driver's global data structure.
    */
   int isr_mode;
  
   /* event used to monitor interrupts */
   ismd_event_t fw_interrupt_event;

   /* interrupt thread */
   os_thread_t   isr_thread;
   bool          isr_thread_created;
   bool          terminate_isr_thread;
   ismd_event_t  terminate_isr_thread_event;

   /* to protect access to this structure */
   os_sema_t     lock;
   bool          lock_created;

   /* per stream contexts */
   videnc_hal_context_t hal_context_array[VIDENC_HAL_MAX_NUM_STREAMS_SUPPORTED];

   /* SOC info */
   pal_soc_info_t  soc_info;

   /* size of ES buffers */
   uint32_t es_buffer_size;
} videnc_hal_global_data_t;

extern videnc_hal_global_data_t videnc_hal_global_data;

/* end global state variables */

/* function prototypes */

/* initialization utilities */
ismd_result_t videnc_initialize_global_hal_data (void);
void videnc_free_global_hal_data(void);
void videnc_hal_init_all_stream_contexts(void);
void videnc_hal_deinit_all_stream_contexts(void);
void videnc_hal_init_stream_context (videnc_hal_context_t *stream);
void videnc_hal_deinit_stream_context(videnc_hal_context_t *context);
void videnc_hal_reset_stream_context_on_flush (videnc_hal_context_t *stream);
ismd_result_t videnc_hal_fw_open_stream (videnc_hal_context_t *stream_context);
ismd_result_t videnc_hal_fw_close_stream (videnc_hal_context_t *stream_context);
ismd_result_t videnc_hal_alloc_stream_resources(videnc_hal_context_t *stream);
void videnc_hal_dealloc_stream_resources(videnc_hal_context_t* context);
ismd_result_t videnc_hal_init_fw(void);
void videnc_hal_deinit_fw(void);
void videnc_hal_free_isr(void);
ismd_result_t videnc_hal_fw_flush_stream(videnc_hal_context_t *context);
ismd_result_t videnc_hal_setup_workload_queues(videnc_hal_context_t *context);

/*------------ wkld management utilities ------------*/
/* Initialize the context wkld pool. Allocates a block of
   cached memory and breaks it up into wklds */
ismd_result_t videnc_hal_init_wkld_pool(videnc_hal_context_t *context);
/* Pulls an available wkld and populates its field based on the input data.
   The wkld descriptor is populated according to the wkld used.  */
ismd_result_t videnc_hal_init_wkld(videnc_hal_context_t *context, 
    videnc_hal_input_data_t frm_buffer, videnc_frm_wkld_desc_t *data);
/* Pulls an available empty wkld and populate wkld descriptor. */
ismd_result_t videnc_hal_init_empty_wkld(videnc_hal_context_t *context, 
    videnc_frm_wkld_desc_t *data);
/* Releases to wkld and returns it to the wkld pool. */
ismd_result_t videnc_hal_release_wkld_descriptor(videnc_hal_context_t *context, 
    int wkld_id);
/* Destroys the context wkld pool and deallocates the associated memory. */
ismd_result_t videnc_hal_destroy_wkld_pool(videnc_hal_context_t *context);
/* get the wkld associated with the given handle */
videnc_frm_wkld_t *get_wkld(videnc_hal_context_t *context, int wkld_id);

ismd_result_t videnc_hal_convert_smd_buf_handle_to_wkld_desc(
                                              ismd_buffer_handle_t buf, 
                                              videnc_frm_wkld_desc_t *wkld);
ismd_result_t videnc_hal_send_frm_buf_to_fw(videnc_hal_context_t *context,
                                            videnc_hal_input_data_t buf);
ismd_result_t videnc_hal_push_to_tag_q(videnc_hal_context_t *context,
                                            videnc_hal_input_data_t buf);
ismd_result_t videnc_hal_read_wkld (videnc_fw_handle_t str_fw_handle,
                                    videnc_frm_wkld_desc_t *wkld);
ismd_result_t videnc_hal_handle_fw_wkld_received(videnc_hal_context_t *context,
                                             ismd_buffer_handle_t wkld_handle);
ismd_result_t videnc_hal_set_metadata(videnc_hal_context_t *context,
                                      ismd_buffer_handle_t fb_handle,
                                      uint32_t removal_delay,
                                      uint32_t bit_rate,
                                      ismd_buffer_handle_t es_handle,
                                      ismd_buffer_descriptor_t* es_desc);
ismd_result_t videnc_hal_set_es_discontinuity (ismd_buffer_handle_t handle);
ismd_result_t videnc_hal_create_wkld_handler_thread (videnc_hal_context_t *context);
void videnc_hal_destroy_wkld_handler_thread(videnc_hal_context_t *context);
void videnc_hal_wkld_handler_thread(void *args);
ismd_result_t hal_send_es_buffers_to_fw(videnc_hal_context_t *context);
void hal_deallocate_wkld_resources(videnc_hal_context_t *context, ismd_buffer_handle_t wkld_id);
ismd_result_t videnc_hal_get_fw_q_status(videnc_hal_context_t *context, videnc_fw_q_status_t* q_status);


/* q utilities */
void videnc_hal_q_init(videnc_hal_q_t *q, int max_size);
void videnc_hal_fb_metadata_q_init(videnc_hal_fb_metadata_q_t *q);

ismd_result_t videnc_hal_q_enqueue(videnc_hal_q_t *q, unsigned int elem);
ismd_result_t videnc_hal_enqueue_metadata(videnc_hal_fb_metadata_q_t *q, bool tags_only, int buf);
unsigned int videnc_hal_q_peek(videnc_hal_q_t *q);
unsigned int videnc_hal_q_dequeue(videnc_hal_q_t *q, bool strobe);
ismd_result_t videnc_hal_dequeue_metadata(videnc_hal_fb_metadata_q_t *q, bool* tags_only, int* buf);

bool videnc_hal_is_q_full(videnc_hal_q_t *q);
void videnc_empty_wkld_q (videnc_hal_context_t *context);
ismd_result_t videnc_process_wkld_q (videnc_hal_context_t *context);
void videnc_empty_output_q (videnc_hal_context_t *context);
void videnc_empty_fb_md_q(videnc_hal_context_t *context);

/* interupt utilities */
void videnc_hal_service_interrupt(videnc_hal_context_t *stream, 
                                  int *interrupts_pending);
void videnc_hal_interrupt_handler(void*);
void videnc_hal_isr_thread(void);
void hal_mask_stream_interrupt(videnc_hal_context_t *context);
void hal_enable_stream_interrupt(videnc_hal_context_t *context);

/* hal utilities */
void videnc_hal_initialize_stats(videnc_hal_context_t *c);
void videnc_hal_initialize_frame_settings(videnc_hal_context_t *c);
ismd_result_t hal_alloc_ismd_buffer(ismd_codec_type_t codec, 
                                          unsigned int size, 
                                          ismd_buffer_handle_t *es);
videnc_hal_context_t *hal_validate_and_lock_context(videnc_hal_stream_t h);
videnc_hal_context_t *hal_validate_and_get_context(videnc_hal_stream_t h);
void videnc_hal_initialize_encoding_params_and_wkld_template(videnc_hal_context_t *c);
ismd_result_t videnc_hal_get_stream_handle (videnc_hal_stream_t *hal_stream_handle);
void videnc_hal_release_frame(videnc_hal_context_t *c, ismd_buffer_handle_t fb,  bool encoded);
ismd_result_t videnc_hal_get_fb_attrs(ismd_buffer_handle_t handle,
    ismd_pts_t *local_pts, ismd_pts_t *orig_pts, bool* discont);
ismd_result_t validate_H264_params(videnc_hal_context_t *context , ismd_videnc_h264_encoder_params_t *params);
ismd_result_t validate_H264_bitrate(videnc_hal_context_t *context , ismd_videnc_h264_bitrate_settings_t *bitrate_settings);
ismd_result_t validate_profile_and_level(ismd_videnc_h264_profile_t profile, ismd_videnc_h264_level_t level);
void videnc_hal_common_init(profile_mode_t profile, videnc_h264_encoder_params_t *p);
ismd_result_t videnc_hal_alloc_frame_buffer (unsigned int height, unsigned int width,
                                    ismd_buffer_handle_t *handle, unsigned int *phys_address);


#ifdef __cplusplus
}
#endif
#endif /* __VIDENC_HAL_PVT_H__*/
