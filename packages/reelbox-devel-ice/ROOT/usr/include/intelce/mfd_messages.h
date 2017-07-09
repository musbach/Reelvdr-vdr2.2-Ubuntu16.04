/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2005-2009 Intel Corporation. All rights reserved.

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


//
// IPC message implementation
//

#ifndef MFD_MESSAGES_H
#define MFD_MESSAGES_H

#include "mfd_basic_types.h"

//
// If the value of a field is not known to the decoder it may set the value to
// MFD_UNDEFINED_VALUE in a message
//
#define MFD_UNDEFINED_VALUE             0x0

//
// Max message size from host to MFD == sizeof( mfd_str_ctrl_add_frame_buffers_t )
//

#define MAX_MFD_MSG_SIZE_IN_32_BITS_WORDS  (134)
#define MAX_MFD_MSG_SIZE_IN_BYTES                   (MAX_MFD_MSG_SIZE_IN_32_BITS_WORDS <<2)


//
// Max message size from MFD to host == sizeof( host_outdf_new_user_data_t )
//
#define MAX_HOST_MSG_SIZE_IN_32_BITS_WORDS  (264)
#define MAX_HOST_MSG_SIZE_IN_BYTES          (MAX_HOST_MSG_SIZE_IN_32_BITS_WORDS <<2)

//
// Defines related to host managed mode
//
#define MFD_MAX_FRAME_BUFFERS               26
#define MFD_VC1_MAX_FRAME_BUFFERS           26
#define MFD_H264_MAX_FRAME_BUFFERS          26
#define MFD_MPEG2_MAX_FRAME_BUFFERS      MFD_MAX_FRAME_BUFFERS

//
// fb_id now contains the type of the frame buffer referred to. It is defined as
// follows:
// Bits 4:0 : frame buffer index
// Bit  5   : fb_id referes to normal decode buffer
// Bit  6   : fb_id referes to pip buffer
//
#define MFD_FB_ID_TYPE_NORMAL_BIT_POS       5
#define MFD_FB_ID_TYPE_PIP_BIT_POS          6


//
// MFD_INVALID_FBID to be used for masked frame or when fbid field is not used
//

#define MFD_INVALID_FBID  0xFFFFFFFF

// ---------------------------------------------------------------------------
// Messages enum (message type/id)
//
typedef enum
{
  //
  //  Cmd Q 		: system CTRL Q
  //    Value range	: 0x100 to 0x1FF
  //
  MFD_SYS_CTRL_GET_SYSTEM_VERSION,

  //
  //  Cmd Q 		:  INTR Q
  //    Value range	: 0x200 to 0x2FF
  //
  HOST_INTR_HI_WMARK_REACHED = 0x200,
  HOST_INTR_LO_WMARK_REACHED,
  HOST_INTR_STREAM_ERROR,
  HOST_INTR_DECODER_ERROR,

  //
  //   Cmd Q 		:  log Q for vsparc
  //    Value range	: 0x300 to 0x37F for MFD to Host
  //
  HOST_LOG_VSPARC_PRINTF = 0x300,


  //
  //   Cmd Q 		:  stream control Q
  //    Value range	: 0x400 to 0x4FF for Host to MFD
  //
  MFD_STR_CTRL_SET_FRAME_MASK = 0x400,
  MFD_STR_CTRL_GET_DECODER_STATE,
  MFD_STR_CTRL_ADD_FRAME_BUFFERS,
  MFD_STR_CTRL_SET_PIP_SCALER,
  MFD_STR_CTRL_RESOLUTION_CHANGE_ACK,

  //
  //   Cmd Q 		:   INPUT_Q
  //    Value range	: 0x500 to 0x5FF for Host to MFD
  //
  MFD_INDF_ADD_ES_BUFFER = 0x500,
  MFD_INDF_ADD_ES_MARKER,
  MFD_INDF_END_OF_ES_INPUT,
  MFD_INDF_AU_INDEX_CTRL,


  //From MFD to Host
  HOST_INDF_RELEASE_ES_BUFFER,
  HOST_INDF_AU_INDEX_INFO,


  //
  //   Cmd Q 		:   DATA Q
  //    Value range	: 0x600 to 0x6FF for Host to MFD
  //
  HOST_OUTDF_NEW_DECODED_FRAME = 0x600,
  HOST_OUTDF_NEW_DISPLAY_FRAME,
  HOST_OUTDF_NEW_USER_DATA,
  HOST_OUTDF_NEW_VIDEO_SEQUENCE,
  HOST_OUTDF_ES_MARKER_FOUND,
  HOST_OUTDF_END_OF_SEQUENCE,
  HOST_OUTDF_END_OF_STREAM,
  HOST_OUTDF_RELEASE_FRAME_BUFFERS,
  HOST_OUTDF_INCORRECT_FB_ID,
  HOST_OUTDF_RESOLUTION_CHANGE,
  HOST_OUTDF_STREAM_PROPERTIES,
  HOST_OUTDF_H264_SPS,
  HOST_OUTDF_MPEG2_SPS,
  HOST_OUTDF_MPEG2_DPS,
  HOST_OUTDF_VC1_SPS,
  HOST_OUTDF_MPEG2_PAN_SCAN_PARAMS,
  HOST_OUTDF_VC1_PAN_SCAN_PARAMS,
  HOST_OUTDF_RESOLUTION_CHANGE_DONE,

  //
  //   Cmd Q 		:   All Q
  //    Value range	: 0x700 to 0x7FF for Host to MFD
  //
  TEST_MESSAGE                  = 0x700,
  MFD_STR_CTRL_NO_BIT_STREAM_BUFFER_TEST,
  MFD_OUTDF_NEW_START_CODE_TEST,
  MFD_STR_CTRL_STREAM_DUMP,

} mfd_msg_id_t;

typedef enum {

	DMA_MODE_INVALID_MODE,
	DMA_MODE_LINEAR_MODE,
	DMA_MODE_CIRCULAR_QUEUE,
	DMA_MODE_LINKED_LIST

} dma_mode_t;

typedef enum {

        VIDEO_FORMAT_INVALID,
        VIDEO_FORMAT_MPEG2,
        VIDEO_FORMAT_H264,
        VIDEO_FORMAT_VC1,
        VIDEO_FORMAT_TEST,
} VIDEO_FORMAT;

#define STREAM_ID_DEFAULT       (0xFFFFFFFF)

//
// All messages sizes below MUST be multiples of 8 bytes
//

// ---------------------------------------------------------------------------
// Message header
//
typedef struct
{
  uint32_t                  name;             //Specific message name
  uint32_t                  size;             // size of the msg (including this hdr)

}  mfd_msg_hdr_t ;


//********************************************************************
//
// System control commands to MFD
//
//********************************************************************

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  firmware_version;
  uint32_t                  hardware_version;

} DOUBLE_ALIGN mfd_sys_get_system_version_t ;

//********************************************************************
//
// INTR messages  from MFD
//
//********************************************************************

typedef enum
{
    STREAM_ERROR_UNSUPPORTED_PROFILE = 0x01,
    STREAM_ERROR_UNSUPPORTED_LEVEL,
    STREAM_ERROR_UNSUPPORTED_FEATURE,
    STREAM_ERROR_UNSUPPORTED_RESOLUTION,
    STREAM_ERROR_INVALID_BS_SYNTAX

} stream_error_msg_id_t;

typedef enum
{
    DECODER_ERROR_Q_FULL = 0x01,
    DECODER_ERROR_INVALID_HOST_MSG

} decoder_error_msg_id_t;
// Interrupt message
typedef struct
{
  mfd_msg_hdr_t         header;

  uint32_t                    stream_id;
  uint32_t                    error_code;  //indicate sublevel of interrupt message

  uint32_t                    error_data;   //any other data accompanying
  uint32_t                    pad;

} DOUBLE_ALIGN           host_intr_stream_error_t ;

typedef  host_intr_stream_error_t  host_intr_decoder_error_t ;


typedef struct
{
  mfd_msg_hdr_t         header;
  uint32_t                    stream_id;
  uint32_t                    q_name;       // indicates which the Q is in danger


} DOUBLE_ALIGN      host_intr_wmark_t ;

typedef  host_intr_wmark_t   host_intr_hi_wmark_t;
typedef  host_intr_wmark_t   host_intr_lo_wmark_t;

//********************************************************************
//
// Stream control commands
//
//********************************************************************
typedef enum
{
  SKIP_B_TYPE_FRAMES                 = (0x01<<0),
  SKIP_P_AND_B_TYPE_FRAMES     = (0x01<<1)

} skip_picture_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  frame_mask;
  uint32_t                  pad;

} DOUBLE_ALIGN mfd_str_ctrl_set_frame_mask_t ;

// This message can be in-band and out-band. Create an alias here.
typedef mfd_str_ctrl_set_frame_mask_t mfd_indf_set_frame_mask_t;


typedef struct
{
  uint32_t                  fb_id;
  uint32_t                  y_addr;
  uint32_t                  uv_addr;
  uint32_t                  mb_info_addr;

} frame_buffer_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  num_entries;
  uint32_t                  pad;

  frame_buffer_t            fb[MFD_MAX_FRAME_BUFFERS ];

} DOUBLE_ALIGN mfd_str_ctrl_add_frame_buffers_t;


typedef enum
{
  PIP_SCALER_DISABLED,
  PIP_SCALE_FACTOR_1_BY_4,
  PIP_SCALE_FACTOR_1_BY_2,
  PIP_SCALER_INVALID,

} pip_setting_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  pip_setting;
  uint32_t                  pad;

} DOUBLE_ALIGN mfd_str_ctrl_set_pip_scaler_t;


typedef struct
{
  mfd_msg_hdr_t             header;

} DOUBLE_ALIGN mfd_str_ctrl_resolution_change_ack_t;


typedef enum
{
  DECODE_STATE_WAIT_FOR_RESYNC_IN_STREAM = 0x01,
  DECODE_STATE_WAIT_FOR_RESOLUTION_CHANGE_ACK,
  DECODE_STATE_WAIT_FOR_NEW_START_CODE,
  DECODE_STATE_HEADER_DECODING,
  DECODE_STATE_SLICE_DECODING,
  DECODE_STATE_STALLED_NO_FRAME_BUFFER,


} decoder_state_t;

typedef struct
{
  mfd_msg_hdr_t             header;
  uint32_t                  stream_fmt;
  uint32_t                  stream_id;
  uint32_t                  decoder_state;
  uint32_t                  pad;

} DOUBLE_ALIGN mfd_str_ctrl_get_decoder_state_t ;

typedef mfd_str_ctrl_get_decoder_state_t host_str_ctrl_get_decoder_state_t;


#define	VSPARC_LOG_BUFFER_SIZE_IN_BYTES		112 //in bytes  128 - sizeof(mfd_msg_hdr_t)
typedef struct
{

  mfd_msg_hdr_t         header;
  uint32_t              data[ VSPARC_LOG_BUFFER_SIZE_IN_BYTES>>2];

} DOUBLE_ALIGN host_log_vsparc_printf_t ;


//********************************************************************
//
// Input Data Flow descriptors from host to MFD
//
//********************************************************************

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  head_node_descriptor; //physical add of head of ll desc
  uint32_t                  size; //like buffer_length in enqueue_buffer_t, when non - zero
  //when 0 head_node_descriptor is physical  address of link list

} DOUBLE_ALIGN mfd_indf_add_es_buffer_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  head_node_descriptor; //physical add of head of ll desc
  uint32_t                  es_marker1;
  uint32_t                  es_marker2;
  uint32_t                  size; //like buffer_length in enqueue_buffer_t, when non - zero
  //when 0 head_node_descriptor is physical  address of link list

} DOUBLE_ALIGN mfd_indf_add_es_marker_t;

typedef enum {
                END_CONDITION_STREAM_ENDED            = (0x01<<0),
                END_CONDITION_FRAME_ENDED             = (0x01<<1)
} INPUT_END_CONDITION;

typedef struct
{
  mfd_msg_hdr_t             header;
  uint32_t                        end_condition;
  uint32_t                        pad;

} DOUBLE_ALIGN mfd_indf_end_of_es_input_t;

//********************************************************************
//
// Output data flow descriptors to host
//
//********************************************************************


typedef enum
{
  FRAME_FLAG_TOP_FIELD_FIRST            = ( 0x1 << 0  ),
  FRAME_FLAG_BIT_01_RESERVED            = ( 0x1 << 1  ),
  FRAME_FLAG_REPEAT_FIRST_FIELD         = ( 0x1 << 2  ),

  FRAME_FLAG_DANGLING_TOP_FIELD         = ( 0x1 << 3  ),
  FRAME_FLAG_DANGLING_BOTTOM_FIELD      = ( 0x1 << 4  ),

  // Bits 5 and 6 defines the  FRAME_CODING_MODE
  // 00 ==> RESERVED
  // 01 ==> INTERLACED_FIELD_MODE
  // 10 ==> INTERLACED_FRAME_MODE
  // 11 ==> PROGRESSIVE_FRAME_MODE
  FRAME_FLAG_INTERLACED_FIELD_MODE      = ( 0x1 << 5  ),
  FRAME_FLAG_INTERLACED_FRAME_MODE     = ( 0x2 << 5  ),
  FRAME_FLAG_PROGRESSIVE_FRAME              =  ( 0x3 << 5  ),

  FRAME_FLAG_ERROR_IN_FRAME             = ( 0x1 << 8  ),
  FRAME_FLAG_SKIPPED                    = ( 0x1 << 9  ),
  FRAME_FLAG_BIT_11_RESERVED            = ( 0x1 << 11 ),
  FRAME_FLAG_FB_ID_IN_USE               = ( 0x1 << 14 ),

  FRAME_FLAG_FIRST_FRAME_IN_GOP         = ( 0x1 << 15 ),
  FRAME_FLAG_CLOSED_GOP                 = ( 0x1 << 16 ),
  FRAME_FLAG_BROKEN_LINK                = ( 0x1 << 17 ),
  FRAME_FLAG_REFERENCES_UNAVAILABLE     = ( 0x1 << 18 ),
  FRAME_FLAG_DO_NOT_DISLAY_PREV_PICS      = ( 0x01 << 19), //no_output_of_prior_pics_flag from H264. Only valid if FRAME_TYPE is IDR.
  FRAME_FLAG_REFERENCE_FRAME      = ( 0x01 << 20)
} mfd_frame_flags_t;

typedef enum
{
  FRAME_TYPE_NOT_USED = 0x0,
  FRAME_TYPE_I     = 1,
  FRAME_TYPE_P     = 2,
  FRAME_TYPE_B     = 3,
  FRAME_TYPE_D     = 4, //MPEG-1 I frame but not used for reference
  FRAME_TYPE_IDR   = 5 // H264 only.

} mfd_frame_type_t;


typedef struct
{
  uint32_t          pan_scan_hoffset;
  uint32_t          pan_scan_voffset;

  uint32_t          pan_scan_hsize;
  uint32_t          pan_scan_vsize;

} pan_scan_window_t;

typedef  pan_scan_window_t vc1_pan_scan_window_t;

typedef struct
{
  mfd_msg_hdr_t     header;

  uint32_t          fb_id;
  uint32_t          num_free_fb_id;

  uint32_t          first_dsn;      //Contains the DSN of a frame if it is progressive. Otherwise it contains the DSN of the first field picture.
  uint32_t          second_dsn; //This field should be ignored and must contain ZERO, if it is a progressive video. Otherwise it contains the DSN of a 2nd field

  uint32_t          previous_frame_dsn;
  uint32_t          frame_number;

  uint32_t          frame_type;           // Of mfd_frame_type_t
  uint32_t          frame_flags;          // Of mfd_frame_flags_t

  uint32_t          pip_setting;          // Of pip_setting_t
  uint32_t          number_mb_concealed;

  uint32_t          temporal_reference;
  uint32_t          frame_cycle_count;

  uint32_t          es_input_wait_count;
  uint32_t          ib_wait_count;

  uint32_t          rbsp_count;
  uint32_t          mpr_wait_count;

  uint32_t          yield_count;
  uint32_t          frame_pack_type;
  uint32_t          pad;

} DOUBLE_ALIGN host_outdf_new_decoded_frame_t ;

typedef struct
{
  mfd_msg_hdr_t     header;

  uint32_t          fb_id;
  uint32_t          ignore_frame;

} DOUBLE_ALIGN host_outdf_new_display_frame_t ;


#define             MAX_USER_DATA_SIZE              1024
typedef struct
{
  mfd_msg_hdr_t                   header;

  uint32_t                        user_data_type;
  uint32_t                        user_data_id;

  uint32_t                        dsn;
  uint32_t                        user_data_size;

  uint32_t                        user_data[MAX_USER_DATA_SIZE>>2];

} DOUBLE_ALIGN host_outdf_new_user_data_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  hsize;
  uint32_t                  vsize;

  uint32_t                  index_profile_level;
  uint32_t                  pad;

} DOUBLE_ALIGN host_outdf_new_video_sequence_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  aspect_ratio;
  uint32_t                  frame_rate;

  uint32_t                  bit_rate;
  uint32_t                  progressive;

  uint32_t                  chroma_fmt;
  uint32_t                  vbv_buf_size;

} DOUBLE_ALIGN host_outdf_mpeg2_sps_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  display_hsize;
  uint32_t                  display_vsize;

  uint32_t                  video_fmt;
  uint32_t                  color_desc;

  uint32_t                  color_prim;
  uint32_t                  transfer_char;

  uint32_t                  matrix_coeff;
  uint32_t                  pad;

} DOUBLE_ALIGN host_outdf_mpeg2_dps_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  aspect_ratio;
  uint32_t                  frame_rate;

  uint32_t                  bit_rate;
  uint32_t                  progressive;

  uint32_t                  display_hsize;
  uint32_t                  display_vsize;

  uint32_t                  color_desc;
  uint32_t                  color_prim;

  uint32_t                  chroma_fmt;
  uint32_t                  transfer_char;

  uint32_t                  tfcntr_flag;
  uint32_t                  pad;

} DOUBLE_ALIGN host_outdf_vc1_sps_t;


typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  num_pan_scan_windows;
  uint32_t                  dsn;

  pan_scan_window_t     pan_scan_window[ 4 ];

} DOUBLE_ALIGN host_outdf_pan_scan_params_t;

typedef host_outdf_pan_scan_params_t host_outdf_mpeg2_pan_scan_params_t;
typedef host_outdf_pan_scan_params_t host_outdf_vc1_pan_scan_params_t;
 
typedef host_outdf_new_video_sequence_t host_outdf_stream_properties_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  es_marker1;
  uint32_t                  es_marker2;

  uint32_t                  dsn;
  uint32_t                  pad;

} DOUBLE_ALIGN host_outdf_es_marker_found_t ;

typedef struct
{
  mfd_msg_hdr_t             header;

}DOUBLE_ALIGN  host_outdf_end_of_sequence_t;

typedef struct
{
  mfd_msg_hdr_t             header;

}DOUBLE_ALIGN  host_outdf_end_of_stream_t ;


typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  num_entries;
  uint32_t                  pad;

  uint32_t                  fb_id[MFD_MAX_FRAME_BUFFERS ];

}  DOUBLE_ALIGN host_outdf_release_frame_buffers_t;


typedef enum
{
  ADD_FB            = 0x1,
  MISSING_PIP_FB    = 0x2

} incorrect_fb_id_msg_id_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  id;           // of incorrect_fb_id_msg_id_t
  uint32_t                  num_entries;

  uint32_t                  fb_id[ MFD_MAX_FRAME_BUFFERS ];

} DOUBLE_ALIGN host_outdf_incorrect_fb_id_t ;

typedef struct
{
  mfd_msg_hdr_t   header;

  uint32_t        width;
  uint32_t        height;

  uint32_t        required_fb_num;
  uint32_t        num_ref_frames;

} DOUBLE_ALIGN host_outdf_resolution_change_t;

typedef struct
{
  mfd_msg_hdr_t   header;
  uint32_t        head_node_descriptor;
  uint32_t        pad;

} DOUBLE_ALIGN host_indf_release_es_buffer_t;

typedef enum
{
  AU_INDEX_CMD_SET_MAX_AU_SIZE=0x1,
  AU_INDEX_CMD_RESET_AU_START_OFFSET=0x2,
  AU_INDEX_CMD_GET_CURRENT_AU_START_OFFSET=0x4

} mfd_au_index_cmd_t;

typedef struct
{

  mfd_msg_hdr_t   header;

  uint32_t        au_max_size;
  uint32_t        index_cmd;

} DOUBLE_ALIGN mfd_indf_au_index_ctrl_t;

typedef enum
{
  AU_INDEX_STATUS_FOUND_AU_BOUNDARY = 0x01,
  AU_INDEX_STATUS_CURRENT_INDEX = 0x02,
  AU_INDEX_ERROR_MAX_AU_SIZE_REACHED = 0x03,
  AU_INDEX_ERROR_UNSUPPORTED_SC_FOUND  = 0x04,
  AU_INDEX_STATUS_END_OF_ES  = 0x05

} mfd_au_index_status_t;

typedef struct
{

  mfd_msg_hdr_t   header;

  uint32_t        au_start_offset;
  uint32_t        status;

  uint32_t        au_index_cycle_count;
  uint32_t        ddr_wait_cycle_count;
  
  uint32_t        picture_type;
  uint32_t        picture_flags;

  uint32_t        temporal_ref;
  uint32_t        pad;
    

} DOUBLE_ALIGN host_indf_au_index_info_t;

//********************************************************************
//
// Test message for sample api app
//
//********************************************************************

typedef struct
{
    mfd_msg_hdr_t           header;
    struct
    {
        uint32_t            test;
        uint32_t            pad;

    } cmd_data;

} DOUBLE_ALIGN mfd_test_msg_t ;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  stream_format;
  uint32_t                  pad;

} DOUBLE_ALIGN  mfd_str_ctrl_no_bit_stream_buffer_test_t;

typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t                  sc_count;
  uint32_t                  pad;


} DOUBLE_ALIGN  mfd_outdf_new_start_code_test_t;

typedef struct
{
  mfd_msg_hdr_t             header;

} DOUBLE_ALIGN mfd_str_ctrl_stream_dump_t ;


//********************************************************************
//
// Decoder specific message.
//
//***************************************************

#define MAX_VALUE_OF_CPB_CNT 32

typedef struct
{

  uint32_t   cpb_cnt_minus1;                                   // ue(v), 0 to 31
  uint32_t   bit_rate_scale;                                   // u(4)

  uint32_t   cpb_size_scale;                                   // u(4)

  uint32_t   bit_rate_value_minus1[MAX_VALUE_OF_CPB_CNT];      // ue(v), 0 to (2^32)-2
  uint32_t   cpb_size_value_minus1[MAX_VALUE_OF_CPB_CNT];      // ue(v), 0 to (2^32)-2
  uint32_t   cbr_flag[MAX_VALUE_OF_CPB_CNT];               // u(1)

  uint32_t   initial_cpb_removal_delay_length_minus1;          // u(5)

  uint32_t   cpb_removal_delay_length_minus1;                  // u(5)
  uint32_t   dpb_output_delay_length_minus1;                   // u(5)

  uint32_t   time_offset_length;                               // u(5)

} h264_hrd_params_t; // Refer Annex E - Sec E1.2

typedef struct
{

  uint32_t   aspect_ratio_info_present_flag;                  // u(1)
  uint32_t   aspect_ratio_idc;                                // u(8)

  uint32_t   sar_width;                                       // u(16)
  uint32_t   sar_height;                                      // u(16)

  uint32_t   overscan_info_present_flag;                      // u(1)
  uint32_t   overscan_appropriate_flag;                       // u(1)

  uint32_t   video_signal_type_present_flag;                  // u(1)
  uint32_t   video_format;                                    // u(3)

  uint32_t   video_full_range_flag;                           // u(1)
  uint32_t   colour_description_present_flag;                 // u(1)

  uint32_t   colour_primaries;                                // u(8)
  uint32_t   transfer_characteristics;                        // u(8)

  uint32_t   matrix_coefficients;                             // u(8)
  uint32_t   chroma_loc_info_present_flag;               // u(1)

  uint32_t   chroma_sample_loc_type_top_field;                // ue(v)
  uint32_t   chroma_sample_loc_type_bottom_field;             // ue(v)

  uint32_t   timing_info_present_flag;                        // u(1)
  uint32_t    num_units_in_tick;                             // u(32)

  uint32_t    time_scale;                                    // u(32)
  uint32_t   fixed_frame_rate_flag;                           // u(1)

  uint32_t   low_delay_hrd_flag;                               // u(1)
  uint32_t   bitstream_restriction_flag;                       // u(1)

  uint32_t  motion_vectors_over_pic_boundaries_flag;          // u(1)
  uint32_t  max_bytes_per_pic_denom;                          // ue(v), 0 to 16

  uint32_t  max_bits_per_mb_denom;                            // ue(v), 0 to 16
  uint32_t  log2_max_mv_length_vertical;                      // ue(v), 0 to 16, default to 16

  uint32_t  log2_max_mv_length_horizontal;                    // ue(v), 0 to 16, default to 16
  uint32_t  num_reorder_frames;                               // ue(v), 0 to max_dec_frame_buffering

  uint32_t  max_dec_frame_buffering;                          // ue(v), 0 to MaxDpbSize, specified in subclause A.3
  uint32_t  nal_hrd_parameters_present_flag;                 // u(1)

  h264_hrd_params_t nal_hrd_parameters;
  uint32_t  vcl_hrd_parameters_present_flag;                 // u(1)

  h264_hrd_params_t vcl_hrd_parameters;
  uint32_t  pic_struct_present_flag;

}h264_vui_params_t; //Refer Annex E, Section E.1.1


typedef struct
{
  mfd_msg_hdr_t             header;

  uint32_t   reserved;

  uint32_t   pic_width_in_mbs_minus1;
  uint32_t   pic_height_in_map_units_minus1;

  uint32_t  frame_mbs_only_flag;
  uint32_t  mb_adaptive_frame_field_flag;

  uint32_t  direct_8x8_inference_flag;
  uint32_t  frame_cropping_flag;

  uint32_t  frame_crop_left_offset;
  uint32_t  frame_crop_right_offset;

  uint32_t  frame_crop_top_offset;
  uint32_t  frame_crop_bottom_offset;

  uint32_t  vui_parameters_present_flag;

  h264_vui_params_t vui_seq_parameters;

  uint32_t  chroma_format_idc;
  uint32_t  pad;


} DOUBLE_ALIGN host_outdf_h264_sps_t ;


#endif // MFD_MESSAGES_H
