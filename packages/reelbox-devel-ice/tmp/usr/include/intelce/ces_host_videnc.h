/*  
This file is provided under a dual BSD/GPLv2 license.  When using or 
redistributing this file, you may do so under either license.

GPL LICENSE SUMMARY

Copyright(c) 2007-2010 Intel Corporation. All rights reserved.

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

Copyright(c) 2007-2010 Intel Corporation. All rights reserved.
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

#ifndef CES_HOST_VIDENC_H
#define CES_HOST_VIDENC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ces_fw_videnc_common_defs.h"
#include "ces_fw_common_defs.h"
#include "ismd_core.h"

/** @weakgroup videnc Fw Encoder interface Functions */
/** @ingroup videnc_fw_encoder */
/*@{*/

/* Encoder Q data.*/
typedef struct
{
    uint32_t wkld_in_q_space; /* Number of messages that can be written to the wkld input queue */
    uint32_t wkld_out_q_data; /* Number of messages available in output queue */
    uint32_t es_in_q_space;   /* Number of messages that can be written to the es input queue */
}videnc_fw_q_status_t;


/**
This function initializes the videnc host library memory and returns the 
the ismd enent handle used for the videnc fw interrupts. It is the driver's responsibility 
to sunc calls to this function with calls to any other videnc fw libraty function.
@param[out] interrupt_event    : The videnc fw interrupt event handle.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the its version.
@retval CES_FW_FAILURE         : Failed to allocate resources needed fot the library or the FW is not loaded.   
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*/
ces_fw_return_types_t videnc_fw_init(ismd_event_t *interrupt_event);

/**
This function deinitializes the videnc host library memory. It is the driver's responsibility 
to sunc calls to this function with calls to any other videnc fw libraty function. 
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the its version.
@retval CES_FW_FAILURE         : The library is not initialized or not all the streams are closed.
*/
ces_fw_return_types_t videnc_fw_deinit(void);

/**
This function returns the ddr resources required to open a stream. This a synchronous message to FW.
@param[in] codec_type          : Type of codec that we want information about.
@param[out] stream_buffer_size : Size of memory required for opening a stream.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the required resources info.
@retval CES_FW_INVALID_PARAM   : Invalid parametrs.
@retval CES_FW_FAILURE         : The library is not initialized.   
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*/

ces_fw_return_types_t videnc_fw_query_stream_resources(uint32_t codec_type,
                                                       uint32_t *stream_buffer_size);



/**
This function returns the ddr resources required to use B frames This a synchronous message to FW.
@param[in] codec_type          : Type of codec that we want information about.
@param[in] max_height          : The input frames maximal height in pixels. 
@param[in] max_width           : The input frames maximal width in pixels. 
@param[in] codec_specific_params_buffer           : Contains parametrs for specific used codec. 
@param[out] required_resources : Contains resources for specific used codec. This resources buffers might be large and therefor need to be dynamiclly allocated.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the required resources info.
@retval CES_FW_INVALID_PARAM   : Invalid parametrs.
@retval CES_FW_FAILURE         : The library is not initialized.   
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*/

ces_fw_return_types_t videnc_fw_query_codec_specific_stream_resources(uint32_t codec_type,
                                                       uint32_t pixel_max_height,
                                                       uint32_t pixel_max_width,
                                                       uint32_t codec_specific_params, // phys addr to a videnc_encoder_params_t struct,
    							      				   videnc_codec_specific_query_resources_t *required_resources);

/**
This function opens requested codec. This a synchronous message to FW.
@param[in] strm_settings            : Setting to use when opening the stream.   
@param[in] strm_ddr                 : Information about the allocated ddr resources for the stream use.
@param[out] strm_handle             : Handle of the opened stream.
@retval CES_FW_SUCCESS              : Successfully Opened the stream.
@retval CES_FW_NO_RESOURCES         : Failed to open stream due to lack of resources.
@retval CES_FW_INVALID_PARAM        : Failed to open a stream due to invalid parametrs.
@retval CES_FW_FAILURE              : The library is not initialized.  
@retval CES_FW_UNSUPPORTED          : The FW service is not registered with CES.
*/

ces_fw_return_types_t videnc_fw_open_stream(uint32_t *strm_handle, 
                                           videnc_stream_settings_t *strm_settings,
                                           videnc_stream_allocated_ddr_t *strm_ddr);
/**
This function closes stream. This a synchronous message to FW. For the close stream to be effective, 
host has to do flush with discard first and then close the stream.
@param[in] strm_handle            : Handle of the stream to close.
@retval CES_FW_SUCCESS            : Successfully closed the stream.
@retval CES_FW_INVALID_PARAM      : Failed to close a stream due to invalid parametrs.
@retval CES_FW_FAILURE            : The library is not initialized.   
@retval CES_FW_UNSUPPORTED        : The FW service is not registered with CES.
*/
ces_fw_return_types_t videnc_fw_close_stream(uint32_t strm_handle);

/**
This function flushes the current stream. The FW should stop encoding after current frame is finished and insert a sequence   
endcode.Then it should should empty the input queues without encoding.
@param[in]  strm_handle        : Handle of the stream we want to flush.
@retval CES_FW_SUCCESS         : Successfully flushed the stream.
@retval CES_FW_INVALID_PARAM   : The input parameters are not valid.
@retval CES_FW_NO_RESOURCES    : Failed to flush. Out of workloads to push empty ES buffers to.
@retval CES_FW_FAILURE         : Failed to flush. Output port is full or the library is not initialized.
*/
ces_fw_return_types_t videnc_fw_flush_stream(uint32_t strm_handle);

/**
This function sends an input es buffer descriptor.
@param[in] strm_handle          : The handle of stream that we want to send es buffer to.
@param[in] message              : The es buffer we want to send.
@retval CES_FW_SUCCESS          : Successfully Sent the message.
@retval CES_FW_INVALID_PARAM    : The input parameters are not valid.
@retval CES_FW_FAILURE          : Unsuccesful in sending the buffer. The port might be full or the library is not initialized. 
@retval CES_FW_UNSUPPORTED      : The FW service is not registered with CES.
*/
ces_fw_return_types_t videnc_fw_send_empty_es(uint32_t strm_handle, videnc_es_desc_t *buffer);

/**
This function sends a frame buffer workload to firmware.
@param[in] strm_handle         : The handle of stream that we want to write workload to.
@param[out] message            : The frame buffer descriptor.
@retval CES_FW_SUCCESS         : Successfully Sent the message.
@retval CES_FW_INVALID_PARAM   : The input parameters are not valid.
@retval CES_FW_FAILURE         : Unsuccesful in sending the buffer. The port might be full or the library is not initialized.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*/
ces_fw_return_types_t videnc_fw_send_frm_wkld(uint32_t strm_handle, videnc_frm_wkld_desc_t *message);

/**
This function gets the next processed workload. 
@param[in] strm_handle       : The handle of stream that we want to read workload from.
@param[out] message          : The workload descriptor.
@retval CES_FW_SUCCESS       : Successfully Sent the message.
@retval CES_FW_INVALID_PARAM : The input parameters are not valid.
@retval CES_FW_FAILURE       : Unsuccesful in reading wkld. The port might be empty or the library is not initialized.
@retval CES_FW_UNSUPPORTED   : The FW service is not registered with CES.
*/
ces_fw_return_types_t videnc_fw_recv(uint32_t strm_handle, videnc_frm_wkld_desc_t *message);

/**
This function gets the major and minor revision numbers of the loaded firmware.
@param[out] major              : The major revision numner.
@param[out] minor              : The minor revision number.
@param[out] build              : The Internal Build number.
@retval CES_FW_SUCCESS         : Successfuly talked to FW and got the its version.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
*/
ces_fw_return_types_t videnc_fw_get_version_number(uint32_t *major, uint32_t *minor, uint32_t *build);

/**
This function enables or disables Interrupts for a stream. By default the FW will always enable interrupts.
The driver can disable/enable Interrupts if it needs for this particular stream.
@param[in] strm_handle         : The handle of stream that we want to get mask from
@param[in] mask                : Mask value.
@retval CES_FW_SUCCESS         : Successfully set mask.
@retval CES_FW_INVALID_PARAM   : The input parameters are not valid.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
@retval CES_FW_FAILURE         : The library is not initialized.   
*/
ces_fw_return_types_t videnc_fw_set_stream_interrupt_mask(uint32_t strm_handle, uint32_t mask);

/**
This function returns current status of all the encoder queues. If the current stream is active we return
Number of input messages that can be written to input ES queue, number of messages in output queue and number of
Free slots available in available workload descriptor queue.
@param[in] strm_handle         : The handle of stream that we want to get status of queues.
@param[out] status             : The status of each queue gets updated in here.
@retval CES_FW_SUCCESS         : Successfully got the status information.
@retval CES_FW_INVALID_PARAM   : Invalid parameter.
@retval CES_FW_UNSUPPORTED     : The FW service is not registered with CES.
@retval CES_FW_FAILURE         : The library is not initialized.   
*/
ces_fw_return_types_t videnc_fw_get_queue_status(uint32_t strm_handle, videnc_fw_q_status_t *status); 

/**
   This function allows to set stream attributes that are supported.
   @param[in] strm_handle         : The handle of stream that we want to set attribute on.
   @param[in] type                : The type of attribute we want to set, this should be one of items in videnc_fw_stream_attributes_t.
   @param[in] value               : The value of the type that we want to set.
   @retval CES_FW_SUCCESS         : Successfully Set the attribute.
   @retval CES_FW_INVALID_PARAM   : The input parameters are not valid.
   @retval CES_FW_FAILURE         : The library is not initialized.  
*/
ces_fw_return_types_t videnc_fw_set_stream_attributes(uint32_t strm_handle, uint32_t type, uint32_t value);

/**
   This function suspends the encoder FW. (power management).
   It is the driver's responsibility to sunc calls to this function with calls to any 
   other videnc fw libraty function.   
   @retval CES_FW_SUCCESS      : The FW successfully suspended.  
   @retval CES_FW_UNSUPPORTED  : The FW service is not registered with CES.
   @retval CES_FW_FAILURE      : The FW is not loaded or it is initialized.
*/
ces_fw_return_types_t videnc_fw_suspend(void);

/**
   This function resumes the encoder FW. (power management).
   It is the driver's responsibility to sunc calls to this function with calls to any 
   other videnc fw libraty function.
   @retval CES_FW_SUCCESS      : The FW successfully resumed.  
   @retval CES_FW_UNSUPPORTED  : The FW service is not registered with CES.
   @retval CES_FW_FAILURE      : The library is not initialized.  
*/
ces_fw_return_types_t videnc_fw_resume(void);

/*@}*/
#ifdef __cplusplus
}
#endif

#endif//#ifndef VIDENC_FW_ENCODER_HOST_H
