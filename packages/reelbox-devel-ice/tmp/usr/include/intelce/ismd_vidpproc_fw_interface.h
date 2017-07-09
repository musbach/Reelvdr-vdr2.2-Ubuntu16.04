/*
* File Name: ismd_vidpproc_fw_interface.h
*/

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
  Santa Clara, CA  97052

  BSD LICENSE

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
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
#ifndef __ISMD_VIDPPROC_FW_INTERFACE_H__
#define __ISMD_VIDPPROC_FW_INTERFACE_H__

#include "ismd_vidpproc_pvt.h"
#include "dpe_common.h"
#include "vpp_fw_core.h"
#include "vpp_host_ipc.h"
#include "vpp_host.h"
#include "vpp_fw_ipc.h"

#ifdef VPP_USE_GEN5
#include "vpp_jlcce_default.h"
#endif
#include "vpp_scaler_default.h"

//IPC
dpe_result_t vpp_ipc_wrapper_reset_cp(os_devhandle_t *devh, const bool to_reset);

dpe_result_t vpp_ipc_wrapper_clear_host_doorbell(os_devhandle_t *devh);

dpe_result_t vpp_ipc_wrapper_load_fw(os_devhandle_t *devh, const uint32_t fw_address);

dpe_result_t vpp_ipc_wrapper_initialize(os_devhandle_t **devh);

dpe_result_t vpp_ipc_wrapper_deinitialize(void);

dpe_result_t vpp_ipc_wrapper_recv_message(os_devhandle_t *devh, uint32_t stream_id, void *message, uint32_t *message_size);


//DPE
dpe_result_t vpp_fw_wrapper_open_stream(vpp_fw_ipc_open_param_t *open_params);

dpe_result_t vpp_fw_wrapper_close_stream(const uint32_t stream_id);

dpe_result_t vpp_fw_wrapper_set_stream_states(const uint32_t stream_ids, const vpp_fw_ipc_stream_state_t stream_state);

dpe_result_t vpp_fw_wrapper_get_stream_priority(const uint32_t stream_id, vpp_fw_ipc_stream_priority *priority);

dpe_result_t vpp_fw_wrapper_set_stream_priority(uint32_t stream_id, vpp_fw_ipc_stream_priority priority);

dpe_result_t vpp_fw_wrapper_set_rnr_level(const uint32_t stream_ids, uint32_t rnr_level);

dpe_result_t vpp_fw_wrapper_flush_stream(uint32_t stream_id);

dpe_result_t vpp_fw_wrapper_set_watermarks(uint32_t stream_id, vpp_fw_ipc_stream_watermark_t watermark);

dpe_result_t vpp_fw_wrapper_set_nrf_level(const uint32_t stream_ids, uint32_t nrf_level);

dpe_result_t vpp_fw_wrapper_init_scalers(const vpp_fw_ipc_init_scalers_t scalers_params);

dpe_result_t vpp_fw_wrapper_initialize(dpe_si_version_t si_version);

dpe_result_t vpp_fw_wrapper_query_fw(vpp_fw_ipc_query_info_t *fw_info);

dpe_result_t vpp_fw_wrapper_set_black_frame(vpp_fw_core_process_picture_t *pict);

dpe_result_t vpp_fw_wrapper_get_status_addr(vpp_fw_ipc_stream_int_state_t **addr);

dpe_result_t vpp_fw_wrapper_process_picture(vpp_fw_core_process_picture_t *picture_params);

dpe_result_t vpp_fw_wrapper_ping_fw(uint32_t time_out);

dpe_result_t vpp_fw_wrapper_set_mode(const uint32_t stream_id, uint32_t is_adp_mode);

dpe_result_t vpp_ipc_wrapper_set_mem_path(bool fast_path);

#ifdef VPP_USE_GEN5
dpe_result_t vpp_fw_wrapper_init_jlcce_table(const vpp_fw_ipc_init_jlcce_table_t jlcce_tables);
#endif

#endif


