/*  
    This file is provided under a dual BSD/GPLv2 license.  When using or
    redistributing this file, you may do so under either license.
    
    GPL LICENSE SUMMARY
    
    Copyright(c) 2010-2011 Intel Corporation. All rights reserved.
    
    This program is free software; you can redistribute it and/or modify it
    under the terms of version 2 of the GNU General Public License as published
    by the Free Software Foundation.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc., 51
    Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  The full GNU General
    Public License is included in this distribution in the file called
    LICENSE.GPL.

    Contact Information:

    BSD LICENSE 

    Copyright(c) 2010-2011 Intel Corporation. All rights reserved.  All rights
    reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright 
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright 
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its 
    contributors may be used to endorse or promote products derived from this
    software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

*/
                             
#ifndef _CES_HOST_PARSER_H_ 
#define _CES_HOST_PARSER_H_ 
                             
#ifdef __cplusplus 
extern "C" {
#endif 

#include <ismd_core.h>
#include "ces_fw_common_defs.h"
#include "ces_fw_viddec_shared_defs.h"

/** @weakgroup Viddec FW Parser host library interface Functions */
/** @ingroup  ces_host_parser */
/*@{*/

/**
   This function will initialize necessary state information for the host
   library and will return the ismd event handle (interrupt event) that the 
   driver is supposed to wait on for handling interrupts.  
   @param[in] polled_mode : If true then Polled otherwise interrupt driven. 
   @param[out] event           : Double pointer to Interrupt event handle
   @retval CES_FW_SUCCESS      : Successfully initialized the host library. 
   @retval CES_FW_FAILURE      : Failed to initialize the host library.  
   @retval CES_FW_INVALID_PARAM: The input parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_init(ismd_event_t *event, bool polled_mode); 

/**
   This function returns the memory size required for opening a stream. This a 
   synchronous message to FW.  
   @param[in] codec_type       : Type of codec that we want information 
                                 about.  
   @param[out] num_wklds       : Number of wklds required for initialization.
   @param[out] size            : Size of memory required for opening a 
                                 stream.
   @retval CES_FW_SUCCESS      : Successfully queried the streamsize. 
   @retval CES_FW_FAILURE      : Failed to get the size and num_wklds.  
   @retval CES_FW_INVALID_PARAM: The parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES driver.
*/
uint32_t ces_host_parser_query_streamsize(uint32_t codec_type, uint32_t *num_wklds, uint32_t *size);

/**
   This function opens a parser instance for the requested codec type. Before 
   calling this function, the host must query for the memory size required 
   for this codec_type using viddec_fw_quey_streamsize() api and allocate the 
   memory of that size. The host should pass the physical address of that 
   allocated memory in this function. After this call, the host must set the 
   stream state to CES_FW_STREAM_PLAYING using viddec_fw_set_stream_state() 
   api before sending any data(es buffer or empty workloads) to the F/W. 
   @param[in] codec_type       : Type of codec that we want to open.
   @param[in] phys             : Physical address of allocated memory for
                                 this codec.  
   @param[in] prority          : Priority of stream. Valid values are 
                                 viddec_stream_priority_REALTIME for realtime and 
                                 viddec_stream_priority_BACKGROUND for background.  
   @param[out] strm_handle     : Handle of the opened stream.  
   @retval CES_FW_SUCCESS      : Successfully Opened the stream.  
   @retval CES_FW_FAILURE      : Failed to Open a stream.
   @retval CES_FW_NORESOURCES  : Failed to Open a stream as we are out of
                                 resources.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/    
uint32_t ces_host_parser_openstream(uint32_t codec_type, uint32_t *strm_handle, uint32_t phys, uint32_t priority);

/**
   This function closes the parser instance.This a synchronous message to FW.  For the close
   stream to be effective, host has to do flush with discard first and then
   close the stream.  
   @param[in] strm_handle       : Handle of the stream to close.
   @retval CES_FW_SUCCESS       : Successfully closed the stream.  
   @retval CES_FW_FAILURE       : Failed to close a stream.
   @retval CES_FW_INVALID_PARAM : The stream handle is not valid.
   @retval CES_FW_UNSUPPORTED   : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_closestream(uint32_t strm_handle);

/**
   This function flushes the current stream. This is a synchronous message to
   FW.  Before calling this function the host has to make sure the output queue
   of the firmware is empty. After this function is executed the FW will read
   all entries in input es buffer queue into a free or partial workload and
   push it into output queue.  After this operation the host has to read all
   entries in output queue again to finish the flush operation.
   @param[in] flush_type        : Type of flush we want to perform. Valid 
                                  values are VIDDEC_STREAM_FLUSH_DISCARD and
                                  VIDDEC_STREAM_FLUSH_PRESERVE.  
   @param[in]  strm_handle      : Handle of the stream we want to flush.  
   @retval CES_FW_SUCCESS       : Successfully flushed the stream.
   @retval CES_FW_INVALID_PARAM : The input parameters are not valid.
   @retval CES_FW_NORESOURCES   : Failed to flush the stream. Out of workloads.
   @retval CES_FW_FAILURE       : Failed to flush the stream. Workload queue 
                                  from fw is not empty.
   @retval CES_FW_UNSUPPORTED   : The Parser fw service is not registered with 
                                  CES.
*/
uint32_t ces_host_parser_flushstream(uint32_t strm_handle, uint32_t flush_type);
    
/**
   This function sends an input es buffer.  
   @param[in] strm_handle      : The handle of stream that we want to send 
                                 es buffer to.
   @param[in] message          : The es buffer we want to send.  
   @retval CES_FW_SUCCESS      : Successfully Sent the message.  
   @retval CES_FW_FAILURE      : Es buffer queue to fw is full. Unsuccesful 
                                 in sending message.
   @retval CES_FW_INVALID_PARAM: The input parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_send(uint32_t strm_handle, ces_fw_ipc_msg_t *message);

/**
   This function gets the next processed workload. The host is required to add
   free workloads to keep the parser busy. The FW will stall when it doesn't
   have enough workloads(2) to continue.  
   @param[in] strm_handle      : The handle of stream that we want to read 
                                 workload from.  
   @param[out] message         : The workload descriptor.  
   @retval CES_FW_SUCCESS      : Successfully Sent the message.  
   @retval CES_FW_FAILURE      : Workload queue from fw is empty. Unsuccesful 
                                 in reading wkld. 
   @retval CES_FW_INVALID_PARAM: The input parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_recv(uint32_t strm_handle, ces_fw_ipc_msg_t *message);

/**
   This function adds a free workload to current stream.  
   @param[in] strm_handle      : The handle of stream that we want to write 
                                 workload to.
   @param[in] message          : The workload descriptor.  
   @retval CES_FW_SUCCESS      : Successfully Sent the message.  
   @retval CES_FW_FAILURE      : Workload queue from fw is full. Unsuccesful 
                                 in sending workload message.
   @retval CES_FW_INVALID_PARAM: The input parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_addwkld(uint32_t strm_handle, ces_fw_ipc_msg_t *message);
 
/**
   This function allows to set stream attributes that are supported.
   @param[in] strm_handle      : The handle of stream that we want to set
                                 attribute on.  
   @param[in] type             : The type of attribute we want to set, this 
                                 should be one of items in 
                                 viddec_fw_stream_attributes_t.
   @param[in] value            : The value of the type that we want to set.
   @retval CES_FW_SUCCESS      : Successfully Set the attribute.  
   @retval CES_FW_INVALID_PARAM: The input parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_set_stream_attributes(uint32_t strm_handle, 
                                                uint32_t type, uint32_t value);

/**
   This function allows to set codec attributes that are supported.
   @param[in] strm_handle      : The handle of stream that we want to set
                                 attribute on.  
   @param[in] type             : The type of attribute we want to set, this 
                                 should be one of items in 
                                 viddec_fw_stream_attributes_t.
   @param[in] value            : The value of the type that we want to set.
   @retval CES_FW_SUCCESS      : Successfully Set the attribute.  
   @retval CES_FW_INVALID_PARAM: The input parameters are not valid.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/

uint32_t ces_host_parser_set_codecs_attributes(uint32_t strm_handle, 
                                                uint32_t type, 
                                                viddec_fw_codec_attributes_t *value);

/**
   This function gets the F/W state of the current stream.
   @param[in] strm_handle      : The handle of stream that we want to get 
                                 state.  
   @param[out] state           : The state value returned 
                                 (ces_fw_stream_states_t).
   @retval CES_FW_SUCCESS      : Successfully got the state information.  
   @retval CES_FW_FAILURE      : Unable to get due to invalid parameters.
*/
uint32_t ces_host_parser_get_stream_state( uint32_t strm_handle, 
                                            ces_fw_stream_states_t *state);

/**
   This function sets the F/W state of the current stream.
   @param[in] strm_handle      : The handle of stream that we want to set 
                                 state.  
   @param[in] state           : The state value that needs to be set 
                                 (ces_fw_stream_states_t).
   @retval CES_FW_SUCCESS      : Successfully in setting state information.  
   @retval CES_FW_FAILURE      : Unable to set due to invalid parameters.
*/
uint32_t ces_host_parser_set_stream_state(uint32_t strm_handle, 
                                    ces_fw_stream_states_t state);

/**
   This function allows to get current status of all the parser queues. If the
   current stream is active we return number of input messages that can be
   written to input ES buffer queue, no of messages in output queue and number 
   of free slots available in workload descriptor queue. 
   @param[in] strm_handle      : The handle of stream that we want to get 
                                 status of queues.  
   @param[out] status          : The status of each queue gets updated in 
                                 here.  
   @retval CES_FW_SUCCESS      : Successfully Got the status information.  
   @retval CES_FW_INVALID_PARAM: Invalid parameter in this case an inactive 
                                 stream.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_get_queue_status(  uint32_t strm_handle, 
                                             viddec_fw_q_status_t *status);

/**
   This function free's the resources allocated in fw initialize call. If this 
   function is called before load fw it will crash with a
   segmentation fault.  
   @retval CES_FW_SUCCESS      : Successfully deinitialized firmware.
   @retval CES_FW_FAILURE      : Encountered active streams during deinit.
                                 Deinit aborted.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/    
uint32_t ces_host_parser_deinit(void);

/**
   This function gets the major and minor revison numbers of the loaded
   firmware.  
   @param[out] major           : The major revision numner.
   @param[out] minor           : The minor revision number.  
   @param[out] build           : The Internal Build number.
   @retval CES_FW_SUCCESS      : Successfuly got the fw version number.
   @retval CES_FW_UNSUPPORTED  : The Parser fw service is not registered with 
                                 CES.
*/
uint32_t ces_host_parser_get_version_number(uint32_t *major, 
                                             uint32_t *minor, uint32_t *build);

/**
   This function sets sven debug level for parser firmware.

   @param[in] level              : Level we want to set, 0 for No messages.
   @retval CES_FW_SUCCESS        : Successfull in Setting Level.
   @retval CES_FW_UNSUPPORTED    : Failed as this api is not supported.
*/
uint32_t ces_host_parser_set_debug(uint32_t level);

/**
   This function sets the parser asyn event mode 

   @param[in] polled_mode            : If true then polled mode else interrupt driven.
   @retval CES_FW_SUCCESS        : Successfull in Setting Level.
   @retval CES_FW_UNSUPPORTED    : Failed as this api is not supported.
*/
uint32_t ces_host_parser_set_async_event_mode(bool polled_mode);

/*@}*/
#ifdef __cplusplus
}
#endif

#endif /**_CES_HOST_PARSER_H_*/
