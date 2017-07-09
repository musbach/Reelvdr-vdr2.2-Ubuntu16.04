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


// ********************************
// file: mfd api.h
// Author: bpthevar ( balakesan.p.thevar@intel.com)
// Desc:    See MFD Programming Interface spec for the details.
//    
//************************************************************

#ifndef _MFD_API_H_
#define _MFD_API_H_

typedef enum _h264_Profile
{
    h264_ProfileBaseline           = 66,       /**< Baseline profile */
    h264_ProfileMain               = 77,       /**< Main profile */
    h264_ProfileExtended           = 88,       /**< Extended profile */
    h264_ProfileHigh               = 100 ,     /**< High profile */
    h264_ProfileHigh10             = 110,      /**< High 10 profile */
    h264_ProfileHighMVC            = 118,      /**< MVC High profile */ 
    h264_ProfileStereoHigh         = 128,      /**< MVC High profile for BR3D */
    h264_ProfileHigh422            = 122,      /**< High profile 4:2:2 */
    h264_ProfileHigh444            = 244,      /**< High profile 4:4:4 */
} h264_Profile;

typedef enum {
        HOST_SYS_CTRL_Q = 0x10,    // System Q for exchanging system ctrl msgs
        MFD_SYS_CTRL_Q,
        HOST_INTR_Q,        //chennal interrupt queues.
        MFD_INTR_Q,
        HOST_LOG_Q,        //used for vsparc logging
        SYS_LAST_Q,
        
        HOST_STR_CTRL_Q = 0x20,    // per channel msg Q for exchanging channel ctrl msgs
        MFD_STR_CTRL_Q,
        HOST_DATA_Q,        // per channel Data Q for decoded info
        MFD_INPUT_Q,         // Elementary stream input_q
        HOST_INPUT_Q,
        MFD_INDEX_Q,        //Elementry stream Q: Handles frame index 
        HOST_INDEX_Q,
        STR_LAST_Q,

        // Shadow Queues
        // Reserved for future use. DONOT use these values. 
        SHADOW_Q_START    = 0x30,
        HOST_SYS_CTRL_SQ = SHADOW_Q_START,
        MFD_SYS_CTRL_SQ,
        HOST_INTR_SQ,            
        MFD_INTR_SQ,
        
        HOST_STR_CTRL_SQ =  0x40,
        MFD_STR_CTRL_SQ,
        HOST_DATA_SQ,    
        MFD_DATA_SQ,   

} Q_NAME;

typedef enum {
            Q_CTRL_SET_HI_WMARK,
            Q_CTRL_SET_LO_WMARK,
            Q_CTRL_CHECK_WMARK,
            Q_CTRL_FORCE_WMARK,
            Q_CTRL_CHECK_AVAIL_Q_SIZE,
            Q_CTRL_RESET_STREAM,
            Q_CTRL_RESET_INBOUND_Q,
            Q_CTRL_GET_NUM_OF_MSGS
} Q_CTRL;

typedef struct {
    unsigned long         phy_base_address;
    unsigned long         virt_base_address;
    unsigned long         size;
    unsigned long         rd_ptr;
    unsigned long         wr_ptr;
    unsigned long         rd_count; // num of msges haven been written
    unsigned long         wr_count; //num of msges have been read
    unsigned long         hi_wmark;
    unsigned long         lo_wmark;
    unsigned long         q_name;
    unsigned long         wmark_intr_sent;
    unsigned long         q_full_intr_sent;
} Q_HDR;


#define MAX_NUM_CH_Q                7               // number of stream control Qs
#define MAX_NUM_SYSTEM_Q        5                // number of system control Qs 

#define MAX_NUM_Q        MAX_NUM_CH_Q    // max of these two 

typedef struct {

		unsigned long 		stream_id;
		unsigned long   	video_format;
} STREAM_INFO;


typedef struct {
    void                      *mfd_handle;
    Q_HDR                 *v_q_hdr [MAX_NUM_Q];
    Q_HDR                 *p_q_hdr [MAX_NUM_Q];
    unsigned long           stream_id;
    unsigned long           video_format;
    unsigned long           cp_process;
    unsigned long           host_process;
    unsigned long           this_addr_phy;
    unsigned long           this_addr_virt;
    unsigned long           this_size;
    unsigned long           fw_ctx_addr_phy;
    unsigned long           fw_ctx_addr_virt;
    unsigned long           fw_ctx_size_in_bytes;
    unsigned long           host_ctx_addr_virt;
    unsigned long           host_ctx_size_in_bytes;
    unsigned long           ext_rsb0_phy_addr;
    unsigned long           ext_rsb1_phy_addr;
    unsigned long           custom_buffer_phy_addr;
    unsigned long           custom_buffer_size;
    void *                      parser;
    unsigned long           fw_state_phy_addr;
    unsigned long           fw_state_virt_addr;
}STREAM_HANDLE;

// I really wanted define MFD_HANDLE as base_class
//    and derive STREAM_HANDLE from it.
//    so that i can pass either pointer to all MFD API calls. 
//    Sicne I have to achieve this in 'C', here is my 
//    implementation - Bala    
//defined MFD_HANDLE is same as stream handle.
// However MFD_HANDLE will not use anything other than Q hdrs.

typedef STREAM_HANDLE MFD_HANDLE;
typedef STREAM_HANDLE stream_handle_t;
typedef MFD_HANDLE    mfd_handle_t;

#define MFD_API_NULL_HANDLE      ( (STREAM_HANDLE *) 0x0 )


typedef struct {
            unsigned  long    virt_address; // FW image addresses.
            unsigned  long    phy_address;
            unsigned  long    size;       // Size of the FW
} DDR_MEM_INFO;



typedef enum {

    MFD_API_SUCCESS,
    MFD_API_ERROR_INVALID_MSG_SIZE,
    MFD_API_ERROR_INVALID_QCTRL_CMD,
    MFD_API_ERROR_Q_FULL,
    MFD_API_ERROR_Q_EMPTY,
    MFD_API_ERROR_PREV_PENDING_REQ,
    MFD_API_ERROR_NO_RESPONSE,
    MFD_API_ERROR_INVALID_FW_IMAGE,
    MFD_API_ERROR_FW_DOWNLOAD_FAILURE,
    MFD_API_ERROR_INSUFFICIENT_MEM,
    MFD_API_ERROR_MAX_PROCESS_REACHED,
    MFD_API_ERROR_INVALID_VIDEO_FORMAT_REQ,
    MFD_API_ERROR_HOST_SYSTEM_ERROR

} MFD_API_RETURN_CODE;

MFD_HANDLE*  mfd_init( DDR_MEM_INFO *ddr, int *err_code);
STREAM_HANDLE*  mfd_open( MFD_HANDLE * mfd_handle, DDR_MEM_INFO *ddr, STREAM_INFO *str_info, int *err_code);
int  mfd_recv( STREAM_HANDLE* str_ch_handle, Q_NAME recv_q, unsigned char* msg, unsigned long msg_size);
int mfd_send(STREAM_HANDLE *str_ch_handle, Q_NAME send_q, unsigned char* msg, unsigned long msg_size);
int mfd_qctrl(STREAM_HANDLE *str_handle, Q_NAME q,  Q_CTRL q_ctrl, unsigned long data_in, unsigned long *data_out );
int mfd_close( STREAM_HANDLE * str_handle);
int mfd_reset( STREAM_HANDLE * str_handle);
int mfd_exit(MFD_HANDLE * mfd_handle);
int mfd_parser( STREAM_HANDLE * str_handle);

#endif // _MFD_API_H_
