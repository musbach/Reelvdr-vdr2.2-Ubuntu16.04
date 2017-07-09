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

#ifndef _CES_HOST_MUX_H_
#define _CES_HOST_MUX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ces_fw_common_defs.h"
#include "ismd_core.h"
#include "ces_fw_mux_workload.h"

/** @weakgroup  */
/** @ingroup  */
/*@{*/


/**
This function initializes the mux host library memory and returns the 
the ismd event handle used for the mux fw interrupts. It is the driver's responsibility 
to sync calls to this function with calls to any other mux fw libraty function.
@param[out] interrupt_event    : The mux fw interrupt event handle.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the its version.
@retval CES_FW_FAILURE         : Failed to allocate resources needed fot the library.   
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*/
uint32_t ces_host_mux_init(ismd_event_t *interrupt_event);

/**
This function unloads mux FW and free's the resources allocated in the previous call 
to mux_fw_init.
@retval CES_FW_SUCCESS         : Successfuly deinitalized the FW.
@retval CES_FW_FAILURE         : The library is not initialized.
*/
uint32_t ces_host_mux_deinit(void);

/**
This function returns the ddr size required opening a stream for multiplexing. This a synchronous message to the FW.
@param[in] container_format    : Type of container format to be multiplexed
@param[out] size               : Size of memory required for opening a stream.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the required resources info.
@retval CES_FW_INVALID_PARAM   : Invalid parametrs.
@retval CES_FW_FAILURE         : The library is not initialized.   
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*
*/
uint32_t ces_host_mux_query_streamsize(mux_stream_container_format_t container_format, 
   uint32_t *size);

/**
This function opens a stream for multiplexing. This a synchronous message to FW.
@param[out] strm_handle            : Handle of the opened stream.
@param[in] container_type          : Container example: MPEG-TS.
@param[in] phys                    : Physical address of allocated memory for this stream.
@param[in] priority                : Priority of the stream. Realtime or background.
@retval CES_FW_SUCCESS              : Successfully Opened the stream.
@retval CES_FW_NO_RESOURCES         : Failed to open stream due to lack of resources.
@retval CES_FW_INVALID_PARAM        : Failed to open a stream due to invalid parametrs.
@retval CES_FW_FAILURE              : The library is not initialized.  
@retval CES_FW_UNSUPPORTED          : The FW service is not registered with CES.
*/
uint32_t ces_host_mux_openstream(uint32_t* strm_handle, 
    mux_stream_container_format_t container_type,
    uint32_t phys,
    mux_stream_priority_t priority);

/**
This function closes stream. For the close stream to be effective, 
host has to do flush with discard first and then close the stream. This a synchronous message to the FW.
@param[in] strm_handle        : Handle of the stream to close.
@retval CES_FW_SUCCESS            : Successfully closed the stream.
@retval CES_FW_INVALID_PARAM      : Failed to close a stream due to invalid parametrs.
@retval CES_FW_FAILURE            : The library is not initialized.   
@retval CES_FW_UNSUPPORTED        : The FW service is not registered with CES.
*/
uint32_t ces_host_mux_closestream(uint32_t strm_handle);

/**
This function flushes the current stream. The FW should stop multiplexing after current ES being multiplexed. 
Then it should should empty the input queues without any multiplexing operations. This a synchronous message to the FW.
@param[in]  strm_handle        : Handle of the stream we want to flush.
@retval CES_FW_SUCCESS      : Successfully flushed the stream.
@retval CES_FW_INVALID_PARAM: The input parameters are not valid.
@retval CES_FW_FAILURE  : Failed to flush. No room in output pipe.
*/
uint32_t ces_host_mux_flushstream(uint32_t strm_handle);

/**
This function sends an empty buffer descriptor to be filled with muxed data (such as TS packets). 
This an asynchronous message to the FW.
@param[in] strm_handle         : The handle of stream to send es buffer to.
@param[in] buffer               : The buffer to send.
@retval CES_FW_SUCCESS          : Successfully Sent the message.
@retval CES_FW_INVALID_PARAM    : The input parameters are not valid.
@retval CES_FW_FAILURE          : Unsuccesful in sending the buffer. The port might be full or the library is not initialized. 
@retval CES_FW_UNSUPPORTED      : The FW service is not registered with CES.
*/
uint32_t ces_host_mux_send_empty_outbuff(uint32_t strm_handle, ces_fw_ipc_msg_t *buffer);

/**
This function sends an input workload buffer descriptor. This an asynchronous message to the FW.
@param[in] strm_handle         : The handle of stream that to send the workload buffer to.
@param[in] message             : The workload buffer to send.
@retval CES_FW_SUCCESS          : Successfully Sent the message.
@retval CES_FW_INVALID_PARAM    : The input parameters are not valid.
@retval CES_FW_FAILURE          : Unsuccesful in sending the buffer. The port might be full or the library is not initialized. 
@retval CES_FW_UNSUPPORTED      : The FW service is not registered with CES.
*/
uint32_t ces_host_mux_send_wkld(uint32_t strm_handle, ces_fw_ipc_msg_t* wkld);

/**
This function gets the next processed buffer. This an asynchronous message to the FW.
@param[in] strm_handle         : The handle of stream that we want to get the buffer from.
@param[in] message             : The buffer descriptor.
@retval CES_FW_SUCCESS       : Successfully Sent the message.
@retval CES_FW_INVALID_PARAM : The input parameters are not valid.
@retval CES_FW_FAILURE       : Unsuccesful in reading wkld. The port might be empty or the library is not initialized.
@retval CES_FW_UNSUPPORTED   : The FW service is not registered with CES.
*/
uint32_t ces_host_mux_recv(uint32_t strm_handle, ces_fw_ipc_msg_t* buffer);

/**
This function gets the major and minor revision numbers of the loaded firmware.
@param[out] major              : The major revision numner.
@param[out] minor              : The minor revision number.
@param[out] build              : The internal build number.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the its version.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.

*/
uint32_t ces_host_mux_get_version_number(unsigned int *major, unsigned int *minor, unsigned int *build);
 

/**
   This function enables/disables interrupt for the stream specified.
@param[in] strm_handle         : The handle of the stream set the mask for.
@param[in] mask              : Interrupt mask for the given stream.
@retval CES_FW_SUCCESS         : Successfully set mask.
@retval CES_FW_INVALID_PARAM   : The input parameters are not valid.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
@retval CES_FW_FAILURE         : The library is not initialized.   
*/
uint32_t ces_host_mux_set_stream_interrupt_mask(uint32_t stream_handle, uint32_t mask);


/**
This function returns current status of all the FW MUX queues. If the current stream is active we return
number of input messages that can be written to input TS queue, number of messages in output queue and number of
free slots available in available workload descriptor queue.
@param[in] strm_handle         : The handle of stream that we want to get status of queues.
@param[out] status             : The status of each queue gets updated in here.
@retval CES_FW_SUCCESS         : Successfully got the status information.
@retval CES_FW_INVALID_PARAM   : Invalid parameter.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
@retval CES_FW_FAILURE         : The library is not initialized.   
*/
uint32_t ces_host_mux_get_queue_status(uint32_t strm_handle, mux_fw_q_status_t *status); 

/**
   This function allows to set stream attributes that are supported.
   @param[in] strm_handle         : The handle of stream to set theattribute on.
   @param[in] type                : The type of attribute to set, this should be one of items in mux_fw_stream_attributes_t.
   @param[in] value               : The value of the type to set.
   @retval CES_FW_SUCCESS         : Successfully Set the attribute.
   @retval CES_FW_INVALID_PARAM   : The input parameters are not valid.
   @retval CES_FW_FAILURE         : The library is not initialized.  
*/
uint32_t ces_host_mux_set_stream_attributes(uint32_t strm_handle, uint32_t type, uint32_t value);

/**
   This function suspends the encoder FW. (power management).
   @retval CES_FW_SUCCESS      : The FW successfully suspended.  
   @retval CES_FW_UNSUPPORTED  : The FW service is not registered with CES.
   @retval CES_FW_FAILURE      : The library is not initialized or not all the stream are closed.
*/
uint32_t ces_host_mux_suspend(void);

/**
   This function resumes the encoder FW. (power management).
   @retval CES_FW_SUCCESS      : The FW successfully resumed.  
   @retval CES_FW_UNSUPPORTED  : The FW service is not registered with CES.
   @retval CES_FW_FAILURE      : The library is not initialized.  
*/
uint32_t ces_host_mux_resume(void);

/**
   This function sets sven debug level for mux firmware.

   @param[in] level              : Level we want to set, 0 for No messages.
   @retval CES_FW_SUCCESS        : Successfull in Setting Level.
   @retval CES_FW_UNSUPPORTED    : Failed as this api is not supported.
*/
uint32_t ces_host_mux_set_debug(uint32_t level);



/*@}*/
#ifdef __cplusplus
}
#endif

#endif //_CES_HOST_MUX_H_


