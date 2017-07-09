/*------------------------------------------------------------------------------
 * File Name: vpp_host_ipc.h
 *------------------------------------------------------------------------------
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
 *
 */

#ifndef _VPP_HOST_IPC_H_
#define _VPP_HOST_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dpe_common.h"
#include "vpp_fw_ipc.h"
#include "host_ipc.h"

/* Global handle for host to perform IPC calls. */
extern struct HostIPC_Handler _vpp_host_ipc_handle;

/**
This function initializes the IPC message queues.
@param[out] **devh - Handle for OSAL/SVEN calls.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_host_ipc_initialize(os_devhandle_t **devh);

/**
This function deinitializes the IPC message queues.
@param[out] **devh - Handle for OSAL/SVEN calls.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/
dpe_result_t vpp_host_ipc_deinitialize(void);
/**
This function connects the stream to fw and setsup input and output queues to and from Fw. 
@param[in] *devh     - Device handle.
@param[in] addr      - Physical addr on where the input and ouput queues for this stream should be.
@param[in] size      - Total size of memory for these queues.
@param[in] stream_id - stream_id of the stream thats being opened. The input and output queues will
                       bet set to stream_id too.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_host_ipc_connect_to_fw(os_devhandle_t *devh, uint32_t addr, uint32_t size, uint32_t stream_id);

/**
Disconnect the stream by closing input and output queues.
@param[in] *devh - Device handle.
@param[in] stream_id - stream_id thats being closed.
*/
void vpp_host_ipc_disconnect(os_devhandle_t *devh, uint32_t stream_id);    

/**
This function performs a blocking synchronous message with firmware and with a
time-out.
@param[in] *devh - Device handle.
@param[in] *vpp_sync_msg - Synchronous message.
@param[in] time_out - Time-out period in microseconds.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_host_ipc_execute_synchronous_message(os_devhandle_t *devh, 
                                                      vpp_fw_ipc_sync_msg_t *vpp_sync_msg, uint32_t time_out);

/**
Send a asynchronous message to Fw. The message being sent will be copied to input queue of the fw.
The input queue number will be same as stream_id.
@param[in] *devh                     - Device handle.
@param[in] stream_id                 - stream_id thats sending message.
@param[in] message                   - Actual message that needs to go to FW(ex:process a frame).
@param[in] message_size              - size of message being sent in bytes.
@retval DPE_RESULT_SUCCESS           if function succeeds.
@retval DPE_RESULT_FULL              if input queue is full and message was not written.
@retval DPE_RESULT_INVALID_PARAM     if invalid stream  is sent.
*/
    
dpe_result_t vpp_host_ipc_send_message(os_devhandle_t *devh, uint32_t stream_id, void *message, uint32_t message_size);

/**
Get a asynchronous message from Fw based on stream_id.
@param[in] *devh                     - Device handle.
@param[in] stream_id                 - stream_id tells which queue to read the message from.
@param[out] message                  - Actual message that we received.
@param[out] message_size             - size of message that was received
@retval DPE_RESULT_SUCCESS           if function succeeds.
@retval DPE_RESULT_EMPTY             if output queue is empty and message was not written.
@retval DPE_RESULT_INVALID_PARAM     if invalid stream  is sent.
*/
    
dpe_result_t vpp_host_ipc_recv_message(os_devhandle_t *devh, uint32_t stream_id, void *message, uint32_t *message_size);

dpe_result_t vpp_host_ipc_is_free(os_devhandle_t *devh, uint32_t stream_id,uint32_t message_size);

/**
 * Set the current IA memory path (COHERENT, NON_COHERENT)
@param[in] *mem_path                 - IA memory path.
@retval DPE_RESULT_SUCCESS           if function succeeds.
*/

dpe_result_t vpp_host_ipc_set_memory_path(ipc_mem_path_t mem_path);


#ifdef __cplusplus
}
#endif

#endif
