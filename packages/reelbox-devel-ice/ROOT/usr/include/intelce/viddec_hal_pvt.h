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

#ifndef __VIDDEC_HAL_PVT_H__
#define __VIDDEC_HAL_PVT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_viddec.h"
#include "osal.h"
#include "pal.h"
#include "pal_interrupt.h"
#include "auto_eas/gen4_mfd.h"
#include "sven_devh.h"
#include "ismd_core.h"
#include "ismd_core_protected.h"
#include "ismd_global_defs.h"
#include "thread_utils.h"
#include "viddec_hal.h"
#include "viddec_hal_workload_manager.h"
#include "viddec_hal_sven.h"

#ifdef VIDDEC_HAL_CE4200  /* VIDDEC_HAL_CE4200 */
#include "ces_host_decoder.h"
#include "ces_host_parser.h"

#define  WKLD_BUF_SIZE                 0x08000 /* 32k */
/* Size of one-third of work load userdata buffer 
 *  * each one-third is assigned to one work load 
 *   * as userdata
 *    */
#define WKLD_USER_DATA_BUF_SIZE 0x2800
#define HAL_INTERRUPT_THREAD_TOTAL_EVENTS 2

#else   /* VIDDEC_HAL_CE4100 */
#include "viddec_fw_parser_host.h"
#include "viddec_fw_common_defs.h"
#include "viddec_fw_decoder_host.h"
#endif


   
/* This file defines private data structures used by the hal. 
 */

/* todo: fw team shall provide these macros, remove later. */
#define  VIDDEC_MAX_INITIAL_WKLDS_PER_STREAM   8 

#define  VIDDEC_HAL_MAX_FRAME_BUFFERS  32

#define  VIDDEC_HAL_INVALID_INDEX      -1

#define  VIDDEC_HAL_INVALID_VIEW_ID    -1

#define INVALID_TAG_PTR (unsigned int) (-1)

#define HAL_ENABLE_INTERRUPT  true
#define HAL_DISABLE_INTERRUPT false

/* bottom half handler can be interrupt driven or polled driven */
typedef enum
{
   VIDDEC_ISR_POLLED_DRIVEN  = 0,
   VIDDEC_ISR_INTR_DRIVEN    = 1
} viddec_hal_isr_mode_t;

/*wkld handler thread will wait on four events - 1.parser wkld output 2. decoder wkld output
 * 3. driver fb release 4. eos handled 5. wkld handler thread terminate */
#define WKLD_THREAD_TOTAL_EVENTS 5 

/* HAL queue to store workloads read from the parser */
#define VIDDEC_HAL_WKLD_Q_SIZE 32

#define INVALID_WKLD_Q_ENTRY ISMD_BUFFER_HANDLE_INVALID

/* These are flags used to indicate specific stream property 
 * changes. Used by comparison function to indicate which 
 * property changed. */
#define VIDDEC_STR_PROP_FRN_NUM  0x0001<<0   /*Frame rate numerator*/ 
#define VIDDEC_STR_PROP_FRN_DEN  0x0001<<1   /*Frame rate denominator*/
#define VIDDEC_STR_PROP_CD_H     0x0001<<2   /*Coded Height*/
#define VIDDEC_STR_PROP_CD_W     0x0001<<3   /*Coded width*/
#define VIDDEC_STR_PROP_DI_H     0x0001<<4   /*Display height*/
#define VIDDEC_STR_PROP_DI_W     0x0001<<5   /*Display width*/
#define VIDDEC_STR_PROP_AR_NUM   0x0001<<6   /*Sample Aspect Ratio Num*/
#define VIDDEC_STR_PROP_AR_DEN   0x0001<<7   /*Sample Aspect Ratio Den*/
#define VIDDEC_STR_FORMAT        0x0001<<8   /*Stream Format (2D/3D)*/
#define VIDDEC_STR_PROP_DISPLAY_INFO   0x0001<<9   /*Display related info*/
 
/** 3D MPEG2 video/stream format signal identifier */
#define VIDDEC_MPEG2_3D_FORMAT_SGNL_IDNTFR 0x4433504A

/** Mask bits used to identify 3D MPEG2 video/stream format type */
#define VIDDEC_MPEG2_3D_STRM_FRMT_BIT_MASK 0x00007F00

/** 3D MPEG2 video/stream format type indicators */
#define VIDDEC_MPEG2_STRM_FRMT_3D_SIDE_BY_SIDE 0x00000300 /** 3D side by side */
#define VIDDEC_MPEG2_STRM_FRMT_3D_OVER_UNDER   0x00000400 /** 3D over under/top bottom */
#define VIDDEC_MPEG2_STRM_FRMT_2D              0x00000800 /** 2D */

/* In 3D Frame Sequential Content, Only base frames are reversed. Hence, max number 
of frames to reverse will be 5 per segment, hence 10(5base + 5dep) in all. */
#define VIDDEC_DEFAULT_MAX_FRAMES_TO_REVERSE_IN_3DFS 10

#define VIDDEC_MAX_PAL_HEIGHT 625
#define VIDDEC_MAX_NTSC_HEIGHT 525

/* deafult values for MPEG2 sequence diplay extension parameters
 * See section 6.3.5 in the MPEG2 standard iso-13818-2 */
#define VIDDEC_MPEG2_DEFAULT_COLOR_PRIM   1
#define VIDDEC_MPEG2_DEFAULT_TRANSF_CHAR  1
#define VIDDEC_MPEG2_DEFAULT_MATRIX_COEFF 1

/* H.264 support */

/* these are used internally in conjunction to H.264 stream properties to 
 * set bits for use in bit rate calculations 
 */
enum HRD_PARAMS_PRESENT 
{
   VIDDEC_HAL_NO_NAL_VCL_HRD_PARAMS  = 0,
   VIDDEC_HAL_VCL_HRD_PARAMS = 1,
   VIDDEC_HAL_NAL_HRD_PARAMS = 2
};

/* H.264 profile level  Annex A.3 used for frame buffer and bit rate calc */
#define VIDDEC_H264_LEVEL1_b    9
#define VIDDEC_H264_LEVEL1_0    10
#define VIDDEC_H264_LEVEL1_1    11
#define VIDDEC_H264_LEVEL1_2    12
#define VIDDEC_H264_LEVEL1_3    13
#define VIDDEC_H264_LEVEL2_0    20
#define VIDDEC_H264_LEVEL2_1    21
#define VIDDEC_H264_LEVEL2_2    22
#define VIDDEC_H264_LEVEL3_0    30
#define VIDDEC_H264_LEVEL3_1    31
#define VIDDEC_H264_LEVEL3_2    32
#define VIDDEC_H264_LEVEL4_0    40
#define VIDDEC_H264_LEVEL4_1    41
#define VIDDEC_H264_LEVEL4_2    42
#define VIDDEC_H264_LEVEL5_0    50
#define VIDDEC_H264_LEVEL5_1    51

/** Macros to simplify hal locking */
#define HAL_LOCK_CONTEXT()    os_mutex_lock(&viddec_hal_context_array_lock)
#define HAL_UNLOCK_CONTEXT()  os_mutex_unlock(&viddec_hal_context_array_lock)

/** Macros to simplify parser wkld q locking */
#define HAL_LOCK_PARSER_WKLD_Q(c)    os_mutex_lock(&c->parser_wkld_q_lock)
#define HAL_UNLOCK_PARSER_WKLD_Q(c)  os_mutex_unlock(&c->parser_wkld_q_lock)

/** Macros to simplify decoder wkld q locking */
#define HAL_LOCK_DECODER_WKLD_Q(c)    os_mutex_lock(&c->decoder_wkld_q_lock)
#define HAL_UNLOCK_DECODER_WKLD_Q(c)  os_mutex_unlock(&c->decoder_wkld_q_lock)

#define HAL_LOCK_WKLD_THREAD()   os_mutex_lock(&viddec_hal_global_data.wkld_handler_thread_lock)
#define HAL_UNLOCK_WKLD_THREAD() os_mutex_unlock(&viddec_hal_global_data.wkld_handler_thread_lock)

/**. Macros to simplify decoder interrupt thread locking */
#define HAL_LOCK_DEOCDER_INTERRUPT_THREAD()   os_mutex_lock(&viddec_hal_global_data.decoder_interrupt_handler_thread_lock)
#define HAL_UNLOCK_DEOCDER_INTERRUPT_THREAD() os_mutex_unlock(&viddec_hal_global_data.decoder_interrupt_handler_thread_lock)

/** Macros to check for 3DBD and 3D AVC Frame sequential content */
#define HAL_IS_3DBD(cxt)   ((cxt)->stream_prop.ismd_prop.stream_format == \
                            VIDDEC_STREAM_FORMAT_3D_MVC)

#define HAL_IS_3D_AVC_FS(cxt) ((cxt)->stream_prop.ismd_prop.stream_format == \
                               VIDDEC_STREAM_FORMAT_3D_FRAME_SEQUENTIAL)

#define HAL_IS_STREAM_FORMAT_3D(cxt) ((HAL_IS_3DBD(cxt)) || \
                                      (HAL_IS_3D_AVC_FS(cxt)))

/** Macros to check for smooth rewind trick mode (Hal only)*/
#define HAL_IS_SMOOTH_REWIND(cxt) (((cxt)->play_rate < 0) && \
                  ((cxt)->frame_mask_info.frame_mask == ISMD_VIDDEC_SKIP_NONE))

/* macros used to synchronize frame buffer release */
#define HAL_FRAME_IS_WRITTEN  0 /*frame was written out of the decoder*/
#define HAL_FRAME_IS_RELEASED 1 /*frame has gone out of scope of the decoder*/

#define HAL_NUM_ISR_EVENTS 2

/* How many times per second the polling thread and wkld thread should run.
 * Higher numbers give lower latency on stream startup and require smaller
 * queue depths to hit maximum FW performance but also take more IA CPU.
 * If lowering this number, check that the viddec performance is not negatively
 * impacted. If raising this number make sure the CPU utilization is 
 * acceptable. Used only in polled mode.
 * For now, threads will wake up every 4 ms */
#define HAL_POLL_THREAD_WAKEUP_RATE_PER_SEC 250
#define HAL_WKLD_THREAD_WAKEUP_RATE_PER_SEC 250

/*This queue stores workloads generated by parser module*/
typedef struct
{
   int head;
   int tail;
   int num_elements; /*number of workloads in the q*/
   ismd_buffer_handle_t wkld[VIDDEC_HAL_WKLD_Q_SIZE]; /*buf handle for wkld*/
} viddec_hal_wkld_q_t;

/* todo: request FW team to provide mfd_fw_handle_t, use that and remove 
 * this typedef 
 */
typedef unsigned int viddec_mfd_fw_handle_t; 

/* stores list of driver callbacks and the data that should 
 * be passed to the driver when calling the callbacks 
 */
typedef struct
{
   viddec_hal_dec_events_t event_handlers;
   void *data;
} viddec_hal_driver_callbacks_t;

/* Stores the Frame mask info
 */
typedef struct 
{
  ismd_viddec_frame_skip_policy_t frame_mask;
  bool skip_b_frames;
  bool skip_p_frames;
} viddec_frame_mask_info_t;

/* each entry in the tag array is a struct of this type */
typedef struct viddec_hal_buffer_tag_data
{
   /* frame decode number of the frame to which the tags should be attached */
   unsigned long frame_decode_number;

   bool fdn_valid;

   /* zero sized buffer to store all tags associated with this frame */
   ismd_buffer_handle_t zero_size_buffer_id;

} viddec_hal_buffer_tag_data_t;

/* size of the tag array in the HAL */
#define VIDDEC_HAL_MAX_BUFFER_TAG_ARRAY_SIZE 64

typedef struct viddec_hal_tag_struct
{
   /*tag array is an array of structures*/
   viddec_hal_buffer_tag_data_t buffer_tag_array[VIDDEC_HAL_MAX_BUFFER_TAG_ARRAY_SIZE];
   
   /*read and write pointers that will be used to access the array*/
   unsigned int wr_ptr;
   unsigned int rd_ptr;

   /* read pointers used in tag association */
   unsigned int prev_rd_ptr;
   unsigned int curr_rd_ptr;

   /* read pointers used in tag peek */
   unsigned int peek_ptr;
   
   /*this lock will synchornize access to the tag array*/
   os_mutex_t tag_array_lock;
   bool tag_array_lock_created;

} viddec_hal_tag_struct_t;

/** This structure holds all of the attributes related to managing the 
 * ismd viddec frame buffer pool. 
 */
typedef struct viddec_hal_frame_buffer_pool
{
   /*array of frame buffer structures used by this stream*/
   viddec_hal_frame_buffer_t frame_buffers[VIDDEC_HAL_MAX_FRAME_BUFFERS];

   /* this variable is used to keep track of index of last allocated 
    * frame in the frame_buffers array
    */
   unsigned int last_fb_index;

   /* this variable is used to keep track of index of last reference 
    * frame allocated in the frame_buffers array. Used for VC-1
    * skipped frames.
    */
   unsigned int last_ref_frame_index;

   /*last actual reference (non skipped) frame's buffer ids  
    *These are used to create alias buffers for the not coded or
    *skipped frames in MPEG4 and VC1 respectively */ 
   ismd_buffer_handle_t last_ref_reg_fb;
   ismd_buffer_handle_t last_ref_vc1_ra_fb;
   ismd_buffer_handle_t last_ref_pip_fb;

   /* to protect access to this frame buffer array */
   os_mutex_t     fb_lock;
   bool          fb_lock_created;

   /*to process redundant_skip_frame*/
   ismd_pts_t    mp4_redundant_local_pts;
   ismd_pts_t    mp4_redundant_ori_pts;

} viddec_hal_frame_buffer_pool_t;

#define VIDDEC_HAL_MAX_WKLDS 4
#define INVALID_WKLD_ENTRY (-1)

typedef struct viddec_wkld_entry
{
   ismd_buffer_descriptor_t *wkld;
   ismd_buffer_descriptor_t *ud;
   ismd_buffer_descriptor_t *resvd_nal;
   bool sent_to_fw;
} viddec_wkld_entry_t;

typedef struct viddec_hal_wkld_pool
{
   viddec_wkld_entry_t wkld_entry[VIDDEC_HAL_MAX_WKLDS];
   int index;
   unsigned int size;
} viddec_hal_wkld_pool_t;

/* This is the view context structure for a multiview stream */
typedef struct viddec_hal_view_context
{
   int index; /* index of the current view. This field is 
               * the view number e.g. in a MVC stream with 
               * 3 views the view_index can be 0, 1, 2 for 
               * base and dependent streams respectively */
   int id;    /* id of the current view. This information 
               * is extracted from the bitstream by the FW.
               * for example, in a MVC stream with 2 views, 
               * the views for Base view and Dependent view
               * may be 1000 and 1001.*/
   bool is_active; /* indicates whether current view is 
                    * active or not */
   unsigned long frames_decoded; /* number of frames decoded
                                  * in the current view */

   /*This stores all the information related to buffer tags*/
   viddec_hal_tag_struct_t tags;
   
   /*This defines the View Angle (Left/Right/Default-2D) for this View */
   ismd_video_angle_t view_angle; 
   
   /* This flag indicates that there is a pending EOS that needs to be
    * sent out for this stream */
   bool eos_pending;
} viddec_hal_view_context_t;


/* This is the HAL context structure for a stream */
typedef struct viddec_hal_context_t
{
   /* handle to decoder module instance for this stream */
   viddec_mfd_fw_handle_t str_decoder_handle;

   /* handle to parser module instance for this stream */
   viddec_mfd_fw_handle_t str_parser_handle;

   /* handle to memory allocated for decoder(stream memory and queue memory) 
      for this stream */
   ismd_buffer_handle_t str_decoder_mem_handle;

#ifdef VIDDEC_HAL_CE4200
   /* handle to memory allocated for decoder(mbinfo memory) for this stream */
   ismd_buffer_handle_t str_decoder_mbinfo_mem_handle;
   unsigned int         mbinfo_phys_addr; /* Physical address of allocated memory for mb info */
#endif

   /*handle to memory allocated for parser for this stream*/
   ismd_buffer_handle_t str_parser_mem_handle;

   /* workload mgr instance, used by wkload mgr library for this stream */
   struct viddec_workload_manager wkld_mngr;
   
   /* to synchronize workload manager code */
   os_mutex_t     wkld_mgr_lock;
   bool          wkld_mgr_lock_created;

   /* for certain trick modes, we may only decode the first N frames in a 
    * sequence. this is where we store the value of N 
    */
   uint64_t max_frames_to_decode;

   /* for smooth reverse trick modes, we may only decode the first 
    * N frames in a segment. this is where we store the value of N. 
    * Note this value is different from max_frames_to_decoder,which 
    * may be larger than the max_frames_to_reverse due to buffering
    * requirement in reverse playback
    */
   unsigned int max_frames_to_reverse;

   /* for certain trick modes, we may only decode the first N frames in a 
    * data segment. This keeps track of how many frames have been decoded
    * in the current data segment. A data segment start is indicated by a 
    * discontinuity flag.
    */
   uint64_t num_frames_decoded_in_segment;

   /* this is the current setting of the output scaler in the decoder */
   ismd_viddec_output_scale_factor_t scale_factor;

   /* list of driver callbacks for this context and the data that should 
    * be passed to the driver when calling the callbacks 
    */
   viddec_hal_driver_callbacks_t callbacks;

   /* this denotes if context is in use. Initialize to false at 
    * init time and when stream is closed. 
    */
   bool context_in_use;

   /* queue to store workloads read from the parser */
   viddec_hal_wkld_q_t parser_wkld_queue;

   /* queue to store workloads output from the decoder */
   viddec_hal_wkld_q_t decoder_wkld_queue;
   
   /* This is used to synchronise access to parser wkld queue by different threads */
   os_mutex_t parser_wkld_q_lock;
   bool parser_wkld_q_lock_created;

   /* This is used to synchronise access to parser wkld queue by different threads */
   os_mutex_t decoder_wkld_q_lock;
   bool decoder_wkld_q_lock_created;

   /* This data structure defines the frame buffer pool. This is an 
    * array of frame buffers with certain attributes that is maintained
    * by the HAL. 
    */
   viddec_hal_frame_buffer_pool_t fb_pool;

   /* frame mask info*/
   viddec_frame_mask_info_t frame_mask_info; 

   /* statistics associated with this instance 
    * NOTE: The statistics reported to the user are tracked by the driver.
    * This is only used for internal bookeeping by the HAL, for things
    * like the frame decode number or the number of frames 
    * dropped by the HAL. */
   ismd_viddec_stream_statistics_t statistics;

   /* Output policy - determines the order in which frames 
    * are sent out of the decoder. This is a copy of the 
    * policy stored in the driver context.
    */
   ismd_viddec_frame_output_policy_t output_policy;

   /* Fixed frame rate flag - if set to true, the encoded frame rate 
    * parameters are ignored. */
   bool override_frame_rate;

   /* Frame polarity override mode - in this mode decoder will mark all frames as
    * interlaced if 
    * 1) the sequence is interlaced
    * 2) the frame rate is <=30 fps
    * By default this mode is disabled.
    */
   bool override_frame_polarity;

   /* This structure keep track of stream properties applicable to the stream*/
   viddec_hal_stream_properties_t stream_prop;

   /* prev_stream_prop caches the last known stream properties. This is
    * used to detect changes in the stream properties for things such
    * as frame rate changes.
    */
   viddec_hal_stream_properties_t prev_stream_prop;

   /* decoder error policy - by default, it's to drop all error frames
    * except those with marcroblock errors that can be concealed. 
    * this attribute should be preserved after flush */
   ismd_viddec_frame_error_policy_t error_frame_output_policy;

   /* This error mask is generated by HAL to simplify the error 
    * policy handling */
   unsigned int error_mask;

   /* Last H.264 header seen */
   viddec_workload_item_t sps;
   bool sps_is_valid;

   viddec_workload_item_t cropping;
   bool cropping_is_valid;

   viddec_workload_item_t sei_pic_timing;
   bool pic_timing_is_valid;

   codec_repeat_frame_t repeat_frame_cnt;

   unsigned int tff;

   h264_pan_scan_data_t h264_ps_data;

   /* This flag will determine if the panscan information from the bitstream will
    * be propagated downstream. By default, panscan information will be propagated.
    * If flag is disabled, panscan information will be dropped in the decoder and
    * SAR calculation for mpeg2 will be based off of content resolution always.
    */
   bool propagate_panscan_info;

   /* This field defines the default sequence display extension
      values to be used if not explicitly found in the bitstream
   */
   ismd_viddec_seq_disp_ext_default_policy_t display_extension_policy;

   /*The view context stores view specific information in an MVC stream.*/
   viddec_hal_view_context_t view[VIDDEC_HAL_MAX_NUM_VIEWS_SUPPORTED];

   /* current_frame_index
    * This value is used for Frame sequential 3D AVC format only to 
    * determine the current frame (frame0 or frame1)
    * 0 : Current frame is Frame0 (Base view Index) 
    * 1 : Current frame is Frame1 (Dependent view Index)
    *
    * This value gets updated in two cases
    * 1. When a SEI Frame packing info is recieved with the Wkld
    *    This will be interpreted from current_frame_is_frame0 flag
    * 2. On every wkld received from Parser, this value will toggle
    *    to create alternate frame0 and frame1
    * */ 
    unsigned int current_frame_index;

   /*eos handling policy */
   ismd_viddec_eos_policy_t eos_policy;

   /* video_preproc_id_buffer and video_preproc_pipeline_buffer which are used in video preproc */
   viddec_fw_video_preproc_mem_context_t video_preproc_buffers;

   /* video preproc flags*/
   unsigned int video_preproc_flags;
   
#ifdef VIDDEC_HAL_CE4200
   /* region of interest info for jpeg*/
   viddec_jpeg_roi_t roi_info;

   /* this is the current setting of the output scaler for jpeg decoder */
   ismd_viddec_output_scale_factor_t jpeg_scale_factor;
#endif

   /* 
    * MPEG2 Spec states that forward propagation of pan scan vectors 
    * should stop after a new sequence header is found.
    * Pan scan values are updated in display order, so in case a wkld 
    * is dropped at the parser (due to errors), the new_seq_hdr info 
    * will never be propogated for pan scan update.
    *
    * Fix is to retain the seq_hdr_found in the hal_context. In case 
    * of wkld drop, this field will indicate the sequence header on 
    * the dropped workload and will be used for the next workload.
    * */
   bool seq_hdr_found;

   /* In case of forced 2D-3D conversion, this variable determines the output 
    * video format. This variable can have only these six values
    *
    * VIDDEC_OUTPUT_VIDEO_FORMAT_BITSTREAM_DEFAULT
    * VIDDEC_OUTPUT_VIDEO_FORMAT_2D
    * VIDDEC_OUTPUT_VIDEO_FORMAT_2D_BOTH_VIEW
    * VIDDEC_OUTPUT_VIDEO_FORMAT_3D_SIDEBYSIDE
    * VIDDEC_OUTPUT_VIDEO_FORMAT_3D_OVER_UNDER
    * VIDDEC_OUTPUT_VIDEO_FORMAT_3D_ROW_INTERLEAVING
    *
    */
   ismd_viddec_output_video_format_t output_video_format;

   /** This field maintains the previous output_video_format. It is required
       to determine the changes to sample aspect ratio when 
       output_video_format changes. */
   ismd_viddec_output_video_format_t prev_output_video_format;

   viddec_hal_wkld_pool_t wkld_pool;

   int max_active_ref_frames;
   int max_num_fb_for_codec;
   int play_rate;
   bool is_first_frame_decoded;
   int disp_stack_size;

   /** These two fields are required for supporting I frame trick modes (frame
    *  masking) with 3D AVC (frame sequential) content.  
    *  Every I frame will pair with either the first P frame or first B frame
    *  to form a Base-Dependent view pair in this content. When an I frame is
    *  detected (from parser workload), the driver will allow only the first P
    *  and first B frame and drop all other frames.
    *
    *    1. check_for_first_P_frame : This will be set when a workload from
    *                 Parser F/W corresponds to an I frame. When the first P
    *                 frame workload is detected the driver will allow the
    *                 frame to decode and reset this variable.
    *
    *    2. check_for_first_B_frame : This will be set when a workload from
    *                 Parser F/W corresponds to an I frame. When the first B
    *                 frame workload is detected, the driver will allow the
    *                 frame to decode and reset this variable.  
    */
   bool check_for_first_P_frame;
   bool check_for_first_B_frame;

   /** This field is for supporting I frame trick modes with 3DBD content. 
    *
    *  1. is_prev_I_frame : The last workload recieved from Parser correspondes
    *                        to an I frame in a new sequence.
    */
   bool is_prev_I_frame;

} viddec_hal_context_t;

/* these are global state variables that the HAL maintains */

typedef struct viddec_hal_buf_sizes_info
{
   /*size of the work load populated from memory layout */
   unsigned int wkld_buf_size;

   /*size of the user data buffer populated from memory layout */
   unsigned int user_data_buf_size;

   /* Size of Reserved NAL buffer populated from memory layout */
   unsigned int resvd_nal_buf_size;

   /*system stride */
   int system_stride;

} viddec_hal_buf_sizes_info_t;




/* Global hal data structure */
typedef struct 
{
   /* devh for all SVEN_TX events */
   os_devhandle_t          *devh;
 
   /*used to connect to global vsparc*/
    os_devhandle_t          *gv_devh;

   /*used to connect to mfd vsparc*/
   os_devhandle_t          *mfd_devh;

   /* handle to decoder fw scratch memory */
   ismd_buffer_handle_t scratch_mem_handle;

   /* handle to video_preproc_id_buffer */
   ismd_buffer_handle_t video_preproc_id_buffer_handle;

   /*this thread reads workloads from parser and sends them to the decoder*/
   os_thread_t   wkld_handler_thread;
   bool          wkld_handler_thread_created;

   /* to synchronize wkld handler thread with operations like flush */
   os_mutex_t    wkld_handler_thread_lock;
   bool          wkld_handler_thread_lock_created;

   /* to synchronize decoder interrupt handler thread with operations like flush */
   os_mutex_t    decoder_interrupt_handler_thread_lock;
   bool          decoder_interrupt_handler_thread_lock_created;


   /* this event will be set at close */
   ismd_event_t  terminate_wkld_handler_thread; 

   /* This event is set when the parser outputs a workload into the
    * parser workload queue . This event wakes up wkld handler thread*/
   ismd_event_t  parser_wkld_event;

   /* This event is set when the decoder outputs a workload into the
    * decoder workload queue . This event wakes up wkld handler thread*/
   ismd_event_t  decoder_wkld_event;

   /* This event is set when a frame buffer is released by the driver */
   ismd_event_t  fb_avail_event;

   /* This event is set when a pending eos is handled by the driver */
   ismd_event_t  eos_handled_event;

   /* to protect access to this structure */
   os_mutex_t    lock;
   bool          lock_created;

   /*structure holding the sizes of workload, wkld user data buf */
   viddec_hal_buf_sizes_info_t size_info;

   /* polled or interrupt based isr, this maintains a copy 
    * from driver's global data structure.
    */
   int isr_mode;

   /* this union stores all variables needed for interrupts mode and 
    * polling mode */
   union 
   {
      /*any polling mode related variables go here*/
      struct  
      {
         /* this thread works as ISR if in polling mode */
         os_thread_t   polling_thread;
         bool          polling_thread_created;
         ismd_event_t  terminate_polling_thread_event;
         /* this event is set in polling mode to wake up the isr thread */
         ismd_event_t  polling_alarm_event;

         /* this event is set in polling mode to wake up the wkld thread */
         ismd_event_t  wkld_alarm_event;

         /* clock handle used for generating alarms. The alarm will wake up 
          * interrupt handler thread and wkld handler thread when viddec
          * is configured in polling mode. Note this just stores a copy of 
          * the clock handle allocated in the driver.*/
         ismd_clock_t    alarm_clock;

         /*alarm used to wake up ISR thread in polling mode*/
         ismd_clock_alarm_t polling_alarm;

         /*alarm used to wake up wkld thread in polling mode*/
         ismd_clock_alarm_t wkld_alarm;
      } polling_info;

      /*any interrupt mode related variables go here*/
      struct 
      {
         #ifdef VIDDEC_HAL_CE4200   /* VIDDEC_HAL_CE4200 */
            /* used when in interrupt mode*/
            ismd_event_t parser_intr_event; 
            ismd_event_t decoder_intr_event; 

            os_thread_t   parser_isr_thread;
            bool          parser_isr_thread_created;
            ismd_event_t  terminate_parser_isr_thread_event;

            os_thread_t   decoder_isr_thread;
            bool          decoder_isr_thread_created;
            ismd_event_t  terminate_decoder_isr_thread_event;

         #else   /* VIDDEC_HAL_CE4100 */
            /* used when in interrupt mode*/
            os_interrupt_t parser_interrupt;
            os_interrupt_t decoder_interrupt;
         #endif
      } intr_info;
   };
   
} viddec_hal_global_data_t;

extern viddec_hal_global_data_t viddec_hal_global_data;

/* We use static allocation of the hal context array structure as opposed to 
   dynamic, on demand allocation to simplify memory management and increase the
   deterministic nature of the system. 
 */
extern viddec_hal_context_t hal_context_array[VIDDEC_HAL_MAX_NUM_STREAMS_SUPPORTED];

/* This lock is used to synchronize access to the hal_context arrray. This 
   will prevent race conditions in open/close.
 */
extern os_mutex_t viddec_hal_context_array_lock;

/* end global state variables */

/* function prototypes */
void viddec_hal_reset_stream_context_on_close (viddec_hal_context_t *stream);
void viddec_hal_reset_stream_context_on_flush (viddec_hal_context_t *stream);
void viddec_hal_init_frame_buffers (viddec_hal_context_t *c, bool checkvalid);
void viddec_hal_convert_smd_buf_handle_to_wkld(
                                                ismd_buffer_handle_t buf, 
                                                viddec_workload_t **wkld
                                               );

void viddec_hal_wkld_q_init(viddec_hal_wkld_q_t *q);

ismd_result_t viddec_hal_wkld_q_enqueue(
                                          viddec_hal_wkld_q_t *q, 
                                          unsigned int wkld_id
                                       );
unsigned int viddec_hal_wkld_q_dequeue(viddec_hal_wkld_q_t *q);

unsigned int viddec_hal_wkld_q_peek(viddec_hal_wkld_q_t *q);

void viddec_empty_parser_wkld_q (viddec_hal_context_t *context);

void viddec_empty_decoder_wkld_q (viddec_hal_context_t *context);

ismd_result_t viddec_hal_handle_decoder_wkld_received(
                                              viddec_hal_context_t *context,
                                              ismd_buffer_handle_t wkld_handle,
                                              viddec_workload_t *wl);

ismd_result_t viddec_hal_copy_pts_tags_to_frame(viddec_workload_t *wl,
                                                ismd_buffer_handle_t fb_handle);
                                                
ismd_result_t viddec_hal_send_wkld_to_decoder(viddec_mfd_fw_handle_t decoder_handle,
                                              ismd_buffer_handle_t wkld_handle,
                                              viddec_workload_t *wl);
                                             

bool viddec_hal_get_discontinuity(ismd_buffer_handle_t handle);

ismd_result_t viddec_hal_create_wkld_handler_thread (void);
void viddec_hal_destroy_wkld_handler_thread(void);

void viddec_hal_initialize_tags_struct (viddec_hal_view_context_t *c);

void viddec_hal_release_zero_sized_bufs_in_tags_struct (viddec_hal_view_context_t *c);

viddec_hal_context_t *hal_validate_and_lock_context(viddec_hal_stream_t h);

void hal_get_frame_attributes(viddec_hal_context_t *context, 
                              viddec_workload_t *wkld, 
                              ismd_frame_attributes_t *frame_attrs);

void hal_get_stream_properties(viddec_hal_context_t *context, 
                              viddec_workload_t *wkld);

ismd_result_t hal_init_skipped_frame(viddec_hal_context_t *context, 
                                     viddec_hal_frame_buffer_t *curr_frame);

int hal_get_fb_array_index (int frame_buf_id);

void print_hal_array(viddec_hal_context_t *context);

void hal_update_sar_on_pip_transition(ismd_viddec_output_scale_factor_t old_scale,
                                      ismd_viddec_output_scale_factor_t new_scale,
                                      viddec_hal_context_t *context);

void hal_release_frame_buffer(viddec_hal_context_t *context,
                              viddec_hal_frame_buffer_t *frame,
                              bool release_smdfb);

/*Helper function to get end of stream, end of sequence
 * evict frame flags from work load */
void hal_get_eos_eoseq_evict_from_wkld(viddec_workload_t *wl,
                                                  bool * eos,
                                                 bool *eoseq,
                                                 bool *evict);

ismd_result_t hal_send_frame_to_driver (viddec_hal_context_t *context,
                                        int fb_index);

void hal_deref_tag_list_buffers (viddec_workload_t *wl);

void hal_process_h264_release_frame (viddec_hal_context_t *context, int fb_index,
                                     int written_or_release );

ismd_result_t 
viddec_hal_get_stream_handle (viddec_hal_stream_t *hal_stream_handle);

ismd_result_t viddec_hal_alloc_stream_resources(viddec_hal_context_t *stream);

ismd_result_t viddec_hal_global_alloc (unsigned int size, 
                                       ismd_buffer_handle_t *handle, 
                                       ismd_buffer_descriptor_t *desc);

void hal_init_wkld_frame (viddec_frame_reference_t *frame);
void viddec_hal_dealloc_stream_resources(viddec_hal_context_t* context);
unsigned long hal_compute_pts_step_size(unsigned long n, unsigned long d);
void hal_compute_error_mask (viddec_hal_context_t *context, 
                             ismd_viddec_frame_error_policy_t policy);
ismd_result_t hal_init_wklds_for_parser(viddec_hal_context_t *context);
bool viddec_hal_is_frame_buffer_in_use(viddec_hal_frame_buffer_t frame_buffer);
void 
viddec_hal_mark_frame_buffer_in_use(viddec_hal_frame_buffer_t *frame_buffer);
void viddec_hal_init_frame_buffer(viddec_hal_frame_buffer_t *fb, int i);

void hal_dump_fb_array(viddec_hal_context_t *context );
int get_buf_size_from_memory_layout(char *buf_name);
void viddec_hal_free_isr(void);

void hal_get_default_frame_rate(unsigned long *num, unsigned long *den);
void hal_initialize_frame_attributes(ismd_frame_attributes_t *attr);
int hal_get_pip_fb_id (int index);
int hal_get_vc1_ra_fb_id (int index);
int hal_get_reg_fb_id (int index);
bool hal_is_skipped_frame(viddec_workload_t *wkld);
bool hal_is_vc1_range_adjustment(viddec_workload_t *wkld);
void hal_copy_attributes_to_frame(viddec_hal_frame_buffer_t *fb, 
                                  ismd_frame_attributes_t attrs, 
                                  viddec_hal_context_t *context);
void hal_update_pulldown_information(viddec_hal_context_t *context, 
                                     viddec_hal_frame_buffer_t *fb);
void hal_copy_h264_panscan_info(viddec_hal_context_t *context, 
                                viddec_hal_frame_buffer_t *fb);

void hal_process_user_data(viddec_workload_t *wkld, viddec_hal_context_t *context);

bool hal_get_discont_from_wkld(viddec_workload_t *wl);
bool hal_frame_has_discontinuity_tags(viddec_hal_context_t *hal_context,
                                      viddec_hal_frame_buffer_t *fb);
bool hal_is_wkld_to_be_masked(viddec_hal_context_t *context, 
                              viddec_workload_t *wkld);
ismd_result_t viddec_hal_store_tags(viddec_hal_context_t *context, 
                                    viddec_workload_t *wl,
                                    bool is_wkld_dropped);
void viddec_hal_release_esbuffers_in_wkld(viddec_workload_t *wl);
void viddec_hal_release_frame_buffer_resources (viddec_hal_context_t *context);
void hal_copy_view_index_to_frame(viddec_hal_frame_buffer_t *fb, 
                                  viddec_workload_t *wkld,
                                  viddec_hal_context_t *context);
int hal_get_view_index (viddec_hal_context_t *context, viddec_workload_t *wkld);
bool hal_is_wkld_from_active_view(viddec_hal_context_t *context, 
                                  viddec_workload_t *wkld);
void hal_init_view_contexts(viddec_hal_context_t *stream);
bool hal_is_multiview_case(viddec_hal_context_t *context);
void hal_update_statistics (viddec_hal_context_t *context, 
                            viddec_workload_t *wkld);
void hal_alloc_view_resources(viddec_hal_view_context_t *context);
void hal_dealloc_view_resources(viddec_hal_view_context_t *context);
bool hal_is_aspect_ratio_info_valid(unsigned int aspect_ratio);
void hal_mpeg2_get_display_aspect_ratio(int asp_ratio, unsigned int *numerator,
                                        unsigned int *denominator);
void hal_calculate_sample_aspect_ratio(viddec_hal_context_t *context,
                                       unsigned int w,
                                       unsigned int h,
                                       unsigned int *num,
                                       unsigned int *den);

void hal_set_ud_buf_dflt_attrs(ismd_ud_buf_attr_t *ud_buf_attr);

/* Helper function to set the eos policy for 3dbd streams */
ismd_result_t hal_set_eos_policy(viddec_hal_context_t *cxt, ismd_viddec_eos_policy_t policy);

/* Helper function to set the vpp buffer for video watermark */
ismd_result_t hal_set_video_preproc_buffer(viddec_hal_context_t *cxt);

/* Helper function to set the vpp disable flag for video watermark */
ismd_result_t hal_set_video_preproc_flag(viddec_hal_context_t *cxt);

/* Helper function to support H264 Monochrome Content */
ismd_result_t hal_update_fb_for_h264_monochrome_content(viddec_hal_frame_buffer_t *fb);

/* Converts FW user data item type to ISMD user data item type */
ismd_userdata_type_t hal_convert_to_ismd_ud_type(viddec_fw_userdata_type_t ud_item_type);

int hal_compare_stream_properties(ismd_viddec_stream_properties_t *prop1,
                                  ismd_viddec_stream_properties_t *prop2);

int hal_get_wkld_pool_index(viddec_hal_context_t *context, ismd_buffer_handle_t h);
void hal_init_wkld_pool_entry(viddec_wkld_entry_t *entry, viddec_ipc_msg_data *data);
ismd_result_t hal_init_replacement_wkld(viddec_hal_context_t *context, ismd_buffer_handle_t h);
void viddec_hal_convert_smd_buf_desc_to_wkld(ismd_buffer_descriptor_t *desc, viddec_workload_t **wkld);
void hal_deallocate_and_init_parser_wkld_resources(viddec_hal_context_t *context, unsigned int wkld_id);
void viddec_hal_get_wl(viddec_hal_context_t *context, unsigned int wkld_id, viddec_workload_t *wl);
ismd_result_t hal_find_and_send_wkld_to_parser(viddec_hal_context_t *context);
ismd_result_t hal_deinit_wklds_for_parser(viddec_hal_context_t *context);

void viddec_hal_compute_num_frame_buffers(viddec_hal_context_t *context);

bool hal_is_any_eos_pending(viddec_hal_context_t *context);
bool hal_is_eos_pending_for_view(viddec_hal_view_context_t *context);

ismd_result_t viddec_hal_allocate_mbinfo_memory(
                                       uint32_t size,
                                       uint32_t width,
                                       ismd_buffer_handle_t *handle,
                                       uint32_t *mbinfo_phys_addr);

#ifdef VIDDEC_HAL_CE4200   /* VIDDEC_HAL_CE4200 */
void viddec_hal_convert_smd_buf_handle_to_wkld_desc(
                                                      ismd_buffer_handle_t buf, 
                                                      viddec_ipc_msg_data *wkld
                                                   );
ismd_result_t viddec_hal_convert_es_buffer_to_ipc_desc(
                                             ismd_buffer_handle_t buffer,
                                             viddec_ipc_msg_data *data,
                                             bool set_discontinuity,
                                             bool set_evict_frame_flag);
ismd_result_t viddec_hal_read_wkld_from_parser (
                                                 viddec_mfd_fw_handle_t str_parser_handle,
                                                 viddec_ipc_msg_data *wkld
                                               );

/*only for preliminary testing, to be removed later*/
void print_workload(viddec_ipc_msg_data *data);

bool hal_is_jpeg_not_supported(viddec_hal_context_t *context, viddec_workload_t *wl);
unsigned int hal_compute_fb_stride_for_jpeg(unsigned int width);
ismd_result_t viddec_hal_init_fw_and_configure_isr(void);

#else   /* VIDDEC_HAL_CE4100 */
/* function prototypes */
ismd_result_t viddec_hal_load_mfd_fw (void);
ismd_result_t viddec_hal_load_parser_fw (void);
ismd_result_t viddec_hal_load_decoder_fw (void);
void viddec_free_global_hal_data(void);

void viddec_hal_convert_smd_buf_handle_to_wkld_desc(
                                                      ismd_buffer_handle_t buf,
                                                      ipc_msg_data *wkld
                                                   );

ismd_result_t viddec_hal_convert_es_buffer_to_ipc_desc(
                                             ismd_buffer_handle_t buffer,
                                             ipc_msg_data *data,
                                             bool set_discontinuity,
                                             bool set_evict_frame_flag);

ismd_result_t viddec_hal_read_wkld_from_parser (
                                                 viddec_mfd_fw_handle_t str_parser_handle,
                                                 ipc_msg_data *wkld
                                               );


void  hal_check_eos_tag_and_copy_to_frame(viddec_hal_context_t *context,
                                          viddec_workload_t *wl,
                                          viddec_hal_frame_buffer_t *curr_frame);

/*only for preliminary testing, to be removed later*/
void print_workload(ipc_msg_data *data);

/* For allocating an replacement wkld whenever the wkld is dropped fr some reason(ex: frame mask)*/
ismd_result_t viddec_hal_alloc_replacement_wkld (viddec_hal_context_t *context);


void hal_mask_stream_interrupt(viddec_hal_context_t *context);
void hal_enable_stream_interrupt(viddec_hal_context_t *context);


/* Helper function to release allocated nal buffer */
void hal_free_nal_from_wkld(ismd_buffer_handle_t wkld_handle);

#endif




#ifdef __cplusplus
}
#endif
#endif /* __VIDDEC_HAL_PVT_H__*/
