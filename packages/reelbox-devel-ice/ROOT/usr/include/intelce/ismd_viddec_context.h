/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

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

#ifndef __ISMD_VIDDEC_CONTEXT_H__
#define __ISMD_VIDDEC_CONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* This header file contains the definition of the video decoder context and
 * related structures. */
#include "ismd_viddec.h"
#include "viddec_hal.h"

#include "ismd_global_defs.h"
#include "ismd_core_protected.h"

#include "osal.h"
#include "sven_devh.h"

/* Number of application specific events supported by the viddec driver */
#define VIDDEC_NUM_OF_EVENTS ISMD_VIDDEC_NUM_OF_EVENTS

/*Number of events associated with the viddec driver i/o threads*/
#define VIDDEC_NUM_OF_THREAD_EVENTS 6 

/* all queues use generic data structure of size 64.entries
 * The size of the queue actually used may be less than 64.
 * This is stored in q_size fied.
 */
#define VIDDEC_MAX_Q_SIZE 64

/* size of display queue */
#define VIDDEC_MAX_DISP_Q_SIZE VIDDEC_MAX_Q_SIZE

/* This queue is for display reordering logic */
#define VIDDEC_MAX_DISP_REORDER_Q_SIZE 2

/* Size of user data buffer in work load is 10k
 * It is copied into 1k user data buffers and
 * sent out through user data. Maximum number 
 * of 1k user data buffers that can be sent out */
#define VIDDEC_MAX_USER_DATA_Q_SIZE VIDDEC_MAX_Q_SIZE

/* generic data structure used by viddec queues */
typedef struct viddec_q
{
   int head;
   int tail;
   int num_elements;
   int peek_ptr;
   void *initializer;
   void *q[VIDDEC_MAX_Q_SIZE];
   int q_size;
} viddec_q_t;

/* initializer value for queues */
#define INVALID_Q_ENTRY  NULL

/* initializer value for display reorder q */
#define INVALID_DISP_REORDER_Q_ENTRY  INVALID_Q_ENTRY

/* initializer value for display q */
#define INVALID_DISP_Q_ENTRY  INVALID_Q_ENTRY

/* Display stack - stores the indices of frames during smooth rewind. This
 * stack is used as an intermediate storage for reversing frames before they
 * are transferred to display queue. The requirement for smooth rewind feature
 * is to decode only N frames in each new video segment. The process of
 * enqueing N frames into the stack and then copying them into the display
 * queue is equivalent to reversing these N frames
 */
#define VIDDEC_MAX_STACK_SIZE  18
#define VIDDEC_MAX_DISP_STACK_SIZE VIDDEC_MAX_STACK_SIZE
typedef struct
{
   int ptr;   /*Location of latest entry in stack */
   int num_elements; /*Number of elements in the stack */
   void *initializer;
   void *fb[VIDDEC_MAX_STACK_SIZE]; /*this stores the frame pushed in stack*/
   int size;
} viddec_stack_t;

/* initializer value for display stack */
#define INVALID_DISP_STACK_ENTRY  INVALID_Q_ENTRY

/* Rectangle id indicating uninitialized value in h264 pan-scan tags */
#define VIDDEC_INVALID_RECT_ID -1

/* Enumeration for current decoder state */
typedef enum{
    VIDDEC_STATE_INVALID,  /*Initial state of decoder*/
    VIDDEC_STATE_OPEN,     /*When instance is opened*/
    VIDDEC_STATE_CLOSE,    /*When instance is ready to be closed*/
    VIDDEC_STATE_STOPPED,    /*When instance is stopped */
    VIDDEC_STATE_STARTED   /*When instance is in play or pause state */ /*note: decoder_started from gen3 is replaced by this*/
} viddec_state_t;

/* thread events */
typedef enum {
   VIDDEC_BUFFER_RECEIVED,     /* event triggered on port writes or port reads*/
   VIDDEC_DATA_AVAILABLE,      /* event triggered when producing thread
                                * has data ready for port thread to process
                                * (e.g., ready to display message) */
   VIDDEC_INPUT_LOW_WATERMARK, /* event triggered when queue is at low watermark*/
   VIDDEC_THREAD_TERMINATE,    /* event to notify thread to exit*/
   VIDDEC_STARTUP,             /* event triggered when viddec instance is set to play state */
   VIDDEC_CLOCK_ALARM          /* event triggered when a periodic clock alarm is triggered */
} viddec_thread_events_t;

/* Port structure */
typedef struct {
   ismd_port_handle_t port;         /*port handle*/

   /*The following flag is used to track resources during shutdown*/
   bool port_created;         /*flag indicates if port creation succeeded*/
} viddec_port_t;

/* structure to contain thread related info*/
typedef struct {
   os_thread_t thread;        /*thread that handles port operations*/
   bool thread_created;       /*flag indicates if thread creation succeeded*/
   bool thread_running;       /*Indicates whether the thread should continue running*/

   /*various events associated with the thread */
   ismd_event_t events[VIDDEC_NUM_OF_THREAD_EVENTS];

   /*alarm used to wake up thread in polling mode*/
   ismd_clock_alarm_t         alarm;

   /* this is a lock to synchronize the thread with other asynchronous 
    * operations like flush
    */
   os_mutex_t lock; 
   bool lock_created;
} viddec_thread_t;

/* Stores information required to handle pts interpolation for 3:2 pulldown */
typedef struct
{
   ismd_frame_polarity_t polarity;
   bool repeated;
   codec_repeat_frame_t repeat_frame_cnt; /* used only for VC-1 and H264 codecs */
   unsigned int tff; /* used only for VC-1 and MPEG2 codecs */
} viddec_pulldown_info_t;

/* For all codecs, this keeps track of previous pan-scan details */
typedef struct
{
   ismd_pan_scan_offset_t pan_scan;

   /*h264 specific parameters*/
   unsigned int   repetition_period;
   int            rect_id;
} viddec_prev_pan_scan_info_t;

/* This structure maintains the PTS interpolation state information */
typedef struct {
   /* PTS interpolation state tracking */
   ismd_viddec_pts_interpolation_policy_t pts_interpolation_mode;

   /* Initial PTS value to start from */
   ismd_pts_t initial_pts;

   /* Previous PTS value (used by interpolation to calculate current PTS) */
   ismd_pts_t prev_pts;

   /* The repeat flag/frame information of the current frame determines the
   interpolated pts value of the next frame. */
   viddec_pulldown_info_t prev_frame_3_2_info;

} viddec_pts_interpolation_info_t;

struct viddec_stream_context_t;

/* This is the view context structure for a multiview stream */
typedef struct viddec_view_context
{
   /* Output port for this view */
   viddec_port_t output_port;

   /* This is the queue of frames ready for display but pending 
    * writing to the port . We have one display q per view.
    */
   viddec_q_t disp_queue;

   /* this is a lock for the display q, which is accessed by o/p 
    * port thread and display reordering logic 
    */
   os_mutex_t disp_q_lock; 
   bool disp_q_lock_created;

   /* This structure maintains all the state information required for
    * performing PTS interpolation for frames in this view
    */
   viddec_pts_interpolation_info_t pts_info;

   /* This is the frame number of the last frame that was displayed in this view*/
   unsigned long last_frame_decode_num;

   int index; /* index of the current view. This field is 
               * the view number e.g. in a MVC stream with 
               * 3 views the view_index can be 0, 1, 2 for 
               * base and dependent streams respectively */

   /*view context stores a pointer to the top level stream context*/
   struct viddec_stream_context_t* stream_context;
} viddec_view_context_t;

/* For DVD/GOP CC handling, Max Display Fields in GOP is 6 bits 
 * Max Display Fields = 2^6 = 64. This will be the size of Array 
 * to store the CC data 
 */
/* MAX_FIELDS_IN_GOP is doubled, to store an additional gop cc_data, if it
 * arrives while still the active gop line21 buffer is still being consumed */
#define VIDDEC_MAX_FIELDS_IN_GOP 128 

typedef struct viddec_gop_cc_data
{
   /* Number of Disp fields the CC data will be applied to
    */
   unsigned int number_of_displayed_fields_in_gop;

   /* Flag to determine the first disp field of first pic in the GOP
    */
   bool first_field_is_top_field;

   /* 608_cc Data for the all (top, bottom & repeat) fields 
    * Max frames we are assuming here is 25  
    */
   ismd_608_cc_t cc_data[VIDDEC_MAX_FIELDS_IN_GOP];

   /* Field Counter Starting from the first field in GOP
    */
   unsigned int current_field;

} viddec_gop_cc_data_t;

/* Stream context */
typedef struct viddec_stream_context_t
{
   /***********************************************************************
   IMPORTANT: PLEASE DO NOT CHANGE THE ORDER OF VARIABLES BELOW. HAS TO
   BE SAME AS VERSION 1 FOR TESTS TO WORK RELIABLY
   ***********************************************************************/
   /**** START OF VARIABLES WHOSE ORDER SHOULD NOT BE CHANGED ****/
   /*
    This handle is tracked by SMD_core, This is a unique handle
    that must be used when calling all viddec function exposed
    directly to application and indirect viddec functions
    (close, flush) exposed through ismd_dev_close, ismd_dev_flush
   */
   ismd_dev_t    ismd_dev_handle;

   /* This field tracks the initial codec format of the stream */
   ismd_codec_type_t    initial_codec;

   /* This attribute is used for global management */
   bool in_use;  /* true -> stream context is currently active */

   /* This is the index into the context array. Will be used to name
      resources for this instance
    */
   int stream_id;

   /* Current state of this instance */
   viddec_state_t state;

   /* This is the rate of playback. For normal mode, this value is 10000 */
   int play_rate;

   /* store the client id seen in the decoder */
   int client_id_last_seen;

    /*
     Used for internal testing only, keep tracks of number of times
     Bottom half handler is getting called by OS
    */
   unsigned long os_intr_cnt;

   /**** END OF VARIABLES WHOSE ORDER SHOULD NOT BE CHANGED ****/
   /***********************************************************************
   IMPORTANT: PLEASE DO NOT CHANGE THE ORDER OF VARIABLES ABOVE. HAS TO
   BE SAME AS VERSION 1 FOR TESTS TO WORK RELIABLY
   ***********************************************************************/
   /* This is the handle to the HAL. This allows us to communicate with
      the underlying hardware platform.
    */
   viddec_hal_stream_t hal_stream_handle;

   /* Output policy - determines the order in which frames are sent out of the decoder */
   ismd_viddec_frame_output_policy_t output_policy;

   /* statistics associated with this instance */
   ismd_viddec_stream_statistics_t statistics;

   /* video decoder dropped frame or not */
   bool viddec_last_frame_dropped;

   /*counter for contiguous frame drop */
   unsigned int contiguous_frame_drop;

   /* Flag to indicate if gop boundary needs to be found */
   bool find_gop_boundary;

   /*number of frame buffers allocated so far for this stream*/
   int num_allocated_fbs;

   /* For all codecs, need to keep track of previous pan-scan details */
   viddec_prev_pan_scan_info_t prev_pan_scan_info;

   /* For H264, need to keep track of the rect_id and the repetition period
   of the last frame written out of the output port along with the pan-scan rectangle information
   */
   int prev_rect_id;
   int prev_repetition_period;
   unsigned long last_valid_frame_dsn;

   /* All structures that use OSAL types go here
    * The reason we do this is to help facilitate white box testing.
    * OSAL data types are different sizes in user/kernel space.
    * This causes problems when trying to gain visibility into the
    * context data structure (as the only way to get the data from
    * kernel to userspace is via a memcpy()). When the copied data
    * is cast in userspace, this causes problems as these data structures
    * will have different sizes.
    */

   /* This structure keep track of input port related states*/
   viddec_port_t input_port;

   /* User_data output port for this instance */
   viddec_port_t user_data_out_port;

   /* Internal queue to store user data.
    *
    * Handling user data in the decoder is accomplished via a state machine
    * with four states:
    *
    * 1) Init state, waiting for user data
    * 2) Processing user data, when user data is generated by the decoder
    * 3) Associating user data, when it's related to a frame
    * 4) Assigning timing information to user data, when it's related to a
    * frame.
    *
    * In state (2), a 1K ismd_buffer is allocated. If the user data is not
    * frame specific, it will immediately be written to the user data out
    * port via this queue. If it is associated with a picture, the
    * user data buffer is stored in the tag array for association.
    *
    * Once the next frame is decoded, the user data buffer will be associated
    * with the frame. This takes the buffer out of the tag array, and puts
    * it on the frame buffer.
    *
    * When a ready to display event occurs, the user data is pulled from the
    * frame after the PTS association is done. The user data is sent out of
    * the user data port via this queue.
    *
    * In the normal case, it is the responsiblity of the application to free
    * the user data buffer. If we flush the decoder, or in the case of
    * asynchronous close, we must free any 1K SMD buffers that are in the
    * system. Thus, on close, we must:
    *
    * 1) Free all buffers allocated in our tag array
    * 2) Free all buffers allocated on pending frame buffers
    * 3) Free all buffers in this queue
    *
    * */
   viddec_q_t user_data_queue;

   /* this queue is used for display reordering in case of MPEG2, VC-1
    * and MPEG4 codecs.
    */
   viddec_q_t disp_reorder_q;

   /* Intermediate storage stack - to store frames during smooth reverse */
   viddec_stack_t disp_stack;

   /* This is used to protect operations on shared structures by different
   apis or threads
   */
   os_mutex_t context_lock;
   bool context_lock_created;

   /* This lock is used to synchronize access to driver critical sections.
    * It is intended to be a general purpose synchronization method that
    * can be used to protect any sequence of events in the driver that must
    * be synchronized between different driver threads.  */
   os_mutex_t critical_section_lock;
   bool critical_section_lock_created;

   /* Used to store the events registered by application for each condition
      The condition acts as the index into this array. */
   ismd_event_t event_array[VIDDEC_NUM_OF_EVENTS];

   /* Context sven handle used for debugging multistream events... also see global viddec_sven_handle */
   os_devhandle_t *  sven_handle;

   /* Message context id */
   ismd_message_context_t message_context;

   /* flag to enable/disable host pts reordering mode,
     this is used for handling some error streams that
     have wrong PTS */
   bool host_pts_reordering;

   /* flag to indicate startup case - used to send first I frame to display */
   /* immediately after decode, without waiting for another I/P frame to come in. */
   /* this helps first frame on display with slide show clips. */
   bool stream_startup;

   /*The view context stores view specific information in an MVC stream.*/
   viddec_view_context_t view[VIDDEC_HAL_MAX_NUM_VIEWS_SUPPORTED];

   /* Last valid original pts processed by viddec */
   ismd_pts_t last_orig_pts;

   /* Last valid original pts processed by viddec */
   ismd_pts_t last_local_pts;

   /* slave clock to drive */
   ismd_clock_t slave_clock;

   /* This is the requested rate of playback at output port. For normal mode, this value is 10000 */
   int requested_play_rate;

   /* flag to indicate the input data underflow */
   bool input_underflow;

   /* Added to store the start and stop times from the last seen newsegment
    * to check frames for out_of_segment 
    */
   ismd_pts_t newseg_start;
   ismd_pts_t newseg_stop;

   /* Policy to decide how to treat outofsegment frames
    */
   ismd_viddec_out_of_segment_drop_policy_t outofsegment_policy;

   /* this is a lock for the user data q, which is accessed by user data
    * port thread and handle user data call back function.
    */
   os_mutex_t user_data_q_lock;
   bool user_data_q_lock_created;
   
    /* This field stores the CC data at the GOP Level 
     *
     * We use a ping-pong buffer to avoid race conditions
     * between reading and writing the CC data as we have pending frames
     * that may not have had their CC data associated with them
     * in the display queue. 
     */
    viddec_gop_cc_data_t gop_cc_data[2];

    /* This will take values 0 & 1 Indicates the buffer
     * which to copy cc_data onto frame attributes cc_data */
    unsigned int gop_cc_data_active_buffer;

   /* A bool value used for determining the FIRST GOP
    * for DVD/GOP CC handling */
   bool is_first_gop;

   /* In case of 3D AVC Frame sequential format, this Boolean field determines 
    * if the Dependent view frame PTS value should be overriden with the 
    * corresponding Base view frame PTS value.
    * This is required to handle 3D AVC Frame sequential streams that doesnt 
    * have identical PTS values on the Left and right frame.
    * 
    * The ismd_viddec_override_dependent_view_frame_pts() API will update this Value 
    */
   bool override_dependent_view_frame_pts;

   /* for reverse trick mode: If we have decoded N frames, where N is the max 
    * number of frames to decode in a segment as specified by the user, 
    * we drop all frames after the Nth frame. The following variable is 
    * used to check for this condition. 
    */
   bool drop_remaining_frames_in_segment;

   /** This field is required to support I frame trick modes with 3DBD and 3D 
    *  AVC (frame sequential) content.
    *   
    * 1. last_I_frame_pts : PTS value of the last I/IDR frame output by the 
    *                       decoder. I frame trick modes with 3D AVC FS and
    *                       3DBD content needs few extra frames to be decoded.
    *                       After the I frame is sent out, the driver will only
    *                       output the frame having the same PTS value. The
    *                       driver will drop any extra frames without sending
    *                       them to the output port.*/ 
   ismd_pts_t last_I_frame_pts;

   /** This field is used by the evict frame logic. This will be set on the 
    *  ismd_viddec_evict_frame() api call. 
    *  The Input port thread will check for this flag before inserting every 
    *  new es buffer. If set, the input thread will first insert a Zero size 
    *  buffer with the FORCE_FRAME flag set into the Parser F/W queue. */
   bool evict_frame;

} viddec_stream_context_t;

/* This prototype is provided as a convenience to the user. */
ismd_result_t ismd_viddec_get_stream_context(ismd_dev_t    viddec,
                                             ismd_buffer_handle_t h);

#ifdef __cplusplus
}
#endif
#endif //__ISMD_VIDDEC_CONTEXT_H_
