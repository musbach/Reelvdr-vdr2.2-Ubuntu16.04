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
#ifndef __VIDDEC_HAL_SVEN_H__
#define  __VIDDEC_HAL_SVEN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "auto_eas/gen4_mfd.h"
#include "auto_eas/gen4_gv.h"
#include "sven_devh.h"

#define DEFAULT_SVEN_DEBUG_LEVEL_OVERRIDE 2
#define DEFAULT_SVEN_DEBUG_LEVEL          12

extern bool sven_level_log_critical , sven_level_log_data_flow , sven_level_log_generic, sven_level_log_fn;

#define VIDDEC_SVEN_ENTER(devh) if((NULL != devh) && (sven_level_log_fn)) \
   { DEVH_FUNC_ENTER(devh); }

#define VIDDEC_SVEN_EXIT(devh) if((NULL != devh) && (sven_level_log_fn)) \
   { DEVH_FUNC_EXIT(devh); }

#define VIDDEC_SEND_SVEN_EVENT(enabled, devh, event, a, b, c, d, e, f)                \
            if(enabled) { \
                devh_SVEN_WriteModuleEvent(devh ,event, a, b, c, d, e, f); \
            }

#define VIDDEC_LOG_SVEN_EVENT_HAL_FB_IS_RELEASED(devh, handle, index, type, output_fb, is_written, is_displayed) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_FB_IS_RELEASED, handle, index, type, output_fb, is_written, is_displayed);

#define VIDDEC_LOG_SVEN_EVENT_HAL_FBA_RELEASE(devh, context, index, reg_fb, fb_hal_lock_count, type, release_smdfb) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_FBA_RELEASE, context, index, reg_fb, fb_hal_lock_count, type, release_smdfb);

#define VIDDEC_LOG_SVEN_EVENT_HAL_FB_IS_WRITTEN(devh, handle, index, type, output_fb, is_released, is_displayed) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_FB_IS_WRITTEN, handle, index, type, output_fb, is_released, is_displayed);

#define VIDDEC_LOG_SVEN_EVENT_HAL_FB_IS_DISPLAYED(devh, handle, index, type, output_fb, is_written, is_released) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_FB_IS_DISPLAYED, handle, index, type, output_fb, is_written, is_released);

#define VIDDEC_LOG_SVEN_EVENT_HAL_FBA_ALLOC(devh, context, index, fb, fb_hal_lock_count, type, result) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_FBA_ALLOC, context, index, fb, fb_hal_lock_count, type, result);

#define VIDDEC_LOG_SVEN_EVENT_HAL_GET_FW_VER(devh, fw_major_num, fw_minor_num, parser_major_num, parser_minor_num, build_num, parser_build_num) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_GET_FW_VER, fw_major_num, fw_minor_num, parser_major_num, parser_minor_num, build_num, parser_build_num);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WKLD_TX_P(devh, str_parser_handle, wkld_id, wkld_phys, wkld_len, wkld_flags) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_WKLD_TX_P, str_parser_handle, wkld_id, wkld_phys, wkld_len, wkld_flags, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WKLD_RX_P(devh, str_parser_handle, wkld_id, wkld_phys, wkld_len, wkld_flags) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_WKLD_RX_P, str_parser_handle, wkld_id, wkld_phys, wkld_len, wkld_flags, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WKLD_RX_D(devh, str_parser_handle, wkld_id, wkld_phys, wkld_len, wkld_flags) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_WKLD_RX_D, str_parser_handle, wkld_id, wkld_phys, wkld_len, wkld_flags, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_UNSUPPORTED_3D_AVC_STREAM_FORMAT_DETECTED(devh, context, sei_frame_pack_arrangement_quincunx_flag, sei_frame_pack_arragement_type) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_HAL_UNSUPPORTED_3D_AVC_STREAM_FORMAT_DETECTED, context, sei_frame_pack_arrangement_quincunx_flag, sei_frame_pack_arragement_type, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_GET_DESCR_ERR(devh, handle, result) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_GET_DESCR_ERR, handle, result, 0, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_FB_ARRAY(devh, context, index, error_flags, fb_id_flags, reg_fb, fb_hal_lock_count) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_FB_ARRAY, context, index, error_flags, fb_id_flags, reg_fb, fb_hal_lock_count);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WKLD_FOUT(devh, str_decoder_handle, driver_frame_id, luma_phys_addr, chroma_phys_addr, internal_id) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_WKLD_FOUT, str_decoder_handle, 0, driver_frame_id, luma_phys_addr, chroma_phys_addr, internal_id);

#define VIDDEC_LOG_SVEN_EVENT_HAL_DISCONT_ON_WKLD(devh, str_parser_handle, wkld_handle, driver_frame_id) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_DISCONT_ON_WKLD, str_parser_handle, wkld_handle, driver_frame_id, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WKLD_TX_D(devh, decoder_handle, wkld_desc_id, wkld_desc_phys, wkld_desc_len, wkld_desc_flags, wkld_handle) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_WKLD_TX_D, decoder_handle, wkld_desc_id, wkld_desc_phys, wkld_desc_len, wkld_desc_flags, wkld_handle);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WM_FR_INC(devh, context, fb_id, fb) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_WM_FR_INC, context, fb_id, fb, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WM_FR_DEC(devh, context, fb_id, fb) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_WM_FR_DEC, context, fb_id, fb, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WM_ES_INC(devh, context, es_buf_id) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_WM_ES_INC, context, es_buf_id, es_buf_id, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_WM_ES_DEC(devh, context, es_buf_id) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_HAL_WM_ES_DEC, context, es_buf_id, es_buf_id, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_OPEN(devh, codec) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_HAL_OPEN, codec, 0, 0, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_CLOSE_STAGE1(devh, handle, str_parser_handle, str_decoder_handle) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_HAL_CLOSE_STAGE1, handle, str_parser_handle, str_decoder_handle, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_CLOSE_STAGE2(devh, handle, str_parser_handle, str_decoder_handle) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_HAL_CLOSE_STAGE2, handle, str_parser_handle, str_decoder_handle, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_HAL_TX_ES_TO_FW(devh, parser_handle, data_id, data_phys, data_len, data_flags, buffer) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_HAL_TX_ES_TO_FW, parser_handle, data_id, data_phys, data_len, data_flags, buffer);

#define VIDDEC_LOG_SVEN_EVENT_DROP_ERR_FRAME(devh, stream_id, error_flags, output_fb, fb_type, orig_pts, local_pts) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_DROP_ERR_FRAME, stream_id, error_flags, output_fb, fb_type, orig_pts, local_pts);

#define VIDDEC_LOG_SVEN_EVENT_DECODE_ORDER_FRAME(devh, stream_id, fb_index, output_fb, view_index, fb_type) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_DECODE_ORDER_FRAME, stream_id, fb_index, output_fb, view_index, fb_type, 0);

#define VIDDEC_LOG_SVEN_EVENT_DISPLAY_ORDER_FRAME(devh, stream_id, output_port, output_fb, fb_type, orig_pts, local_pts) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_DISPLAY_ORDER_FRAME, stream_id, output_port, output_fb, fb_type, orig_pts, local_pts);

#define VIDDEC_LOG_SVEN_EVENT_WAITING_FOR_FREE_FRAME(devh, stream_id, num_allocated_fbs, max_fbs, reorder_q_num_elements, disp_stack_num_elements, base_view_display_q_num_elements) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_WAITING_FOR_FREE_FRAME, stream_id, num_allocated_fbs, max_fbs, reorder_q_num_elements, disp_stack_num_elements, base_view_display_q_num_elements);

#define VIDDEC_LOG_SVEN_EVENT_EOS_TRIGGERED(devh, stream_id, output_port) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_EOS_TRIGGERED, stream_id, output_port, 0, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_CLOSE(devh, stream_id, input_port, output_port) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_CLOSE, stream_id, input_port, output_port, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_NEW_SEG_IN(devh, stream_id, input_port, newseg_start, newseg_stop, linear_start, requested_rate) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_NEW_SEG_IN, stream_id, input_port, newseg_start, newseg_stop, linear_start, requested_rate);

#define VIDDEC_LOG_SVEN_EVENT_DISCONT_ON_INPUT(devh, stream_id, es_buf_handle) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_DISCONT_ON_INPUT, stream_id, es_buf_handle, 0, 0, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_IN_DEQUEUE(devh, stream_id, input_port, es_buf_handle, port_cur_depth, orig_pts, port_max_depth) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_IN_DEQUEUE, stream_id, input_port, es_buf_handle, port_cur_depth, orig_pts, port_max_depth);

#define VIDDEC_LOG_SVEN_EVENT_NEW_SEG_OUT(devh, stream_id, output_port, newseg_start, newseg_stop, linear_start, requested_rate) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_NEW_SEG_OUT, stream_id, output_port, newseg_start, newseg_stop, linear_start, requested_rate);

#define VIDDEC_LOG_SVEN_EVENT_CLIENT_ID_PROCESSED(devh, stream_id, output_port, output_fb, client_id) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_generic, devh, SVEN_MODULE_EVENT_MFD_CLIENT_ID_PROCESSED, stream_id, output_port, output_fb, client_id, 0, 0);

#define VIDDEC_LOG_SVEN_EVENT_OUT_ENQUEUE(devh, stream_id, output_port, output_fb, port_cur_depth, local_pts, port_max_depth) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_data_flow, devh, SVEN_MODULE_EVENT_MFD_OUT_ENQUEUE, stream_id, output_port, output_fb, port_cur_depth, local_pts, port_max_depth);

#define VIDDEC_LOG_SVEN_EVENT_OPEN(devh, stream_id, input_port, output_port, ismd_dev_handle, initial_codec) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_OPEN, stream_id, input_port, output_port, ismd_dev_handle, initial_codec,0);

#define VIDDEC_LOG_SVEN_EVENT_FLUSH_START(devh, stream_id, input_port, input_port_curr_depth, output_port, output_port_curr_depth) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_FLUSH_START, stream_id, input_port, input_port_curr_depth, output_port, output_port_curr_depth, 0);

#define VIDDEC_LOG_SVEN_EVENT_FLUSH_COMPLETE(devh, stream_id, input_port, input_port_curr_depth, output_port, output_port_curr_depth) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_FLUSH_COMPLETE, stream_id, input_port, input_port_curr_depth, output_port, output_port_curr_depth, 0);

#define VIDDEC_LOG_SVEN_EVENT_SET_STATE(devh, stream_id, prev_state, state_requested) \
         VIDDEC_SEND_SVEN_EVENT(sven_level_log_critical, devh, SVEN_MODULE_EVENT_MFD_SET_STATE, stream_id, prev_state, state_requested, 0, 0, 0);

#ifdef __cplusplus
}
#endif
#endif /* __VIDDEC_HAL_SVEN_H__*/
