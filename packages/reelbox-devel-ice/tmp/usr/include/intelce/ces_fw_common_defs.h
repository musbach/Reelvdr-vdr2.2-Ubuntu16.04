/*  
   This file is provided under a dual BSD/GPLv2 license.  When using or 
   redistributing this file, you may do so under either license.

   GPL LICENSE SUMMARY

   Copyright(c) 2010-2011 Intel Corporation. All rights reserved.

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

   Copyright(c) 2010-2011 Intel Corporation. All rights reserved.
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
#ifndef CES_FW_COMMON_DEFS_H
#define CES_FW_COMMON_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/** @group CES Common Embedded Services */
/** @weakgroup FW_COMMON_DEFS CES common shared defines */

/** @{ */

#include <stdint.h>

/**
@brief <H3></H3>
   Max number of services that are supported by CES service drivers(Ex: parse_encode).
*/
#define MAX_NUM_SERVICES_SUPPORTED 2

/**
@brief <H3></H3>
   Invalid Que Id value.
*/
#define INVALID_Q_ID    (uint32_t)-1


/**
@brief <H3></H3>
   Firmware return types.
*/
typedef enum
{
   CES_FW_SUCCESS,
   CES_FW_FAILURE,          
   CES_FW_INVALID_PARAM,
   CES_FW_NO_RESOURCES,
   CES_FW_NO_BUFFERS,
   CES_FW_UNSUPPORTED,
   CES_FW_Q_FULL,
   CES_FW_Q_EMPTY,
}ces_fw_return_types_t;

/**
@brief <H3></H3>
   Firmware stream states.
*/
typedef enum
{
   CES_FW_STREAM_FREE,       /**< Stream in inactive state */
   CES_FW_STREAM_STOP,       /**< Stream in Stop state */
   CES_FW_STREAM_PLAYING,    /**< Stream in playing state */
}ces_fw_stream_states_t;

/**
@brief <H3></H3>
   Firmware Interrupt types that are supported by CES.
*/
typedef enum
{
   CES_FW_INT_HIGH_MIPS = 0x1,           /**< Interrupt from High MIPS FW */
   CES_FW_INT_LOW_LATENCY= 0x2,          /**< Interrupt from LowLatency FW */
   CES_FW_INT_SYNC_MESSAGE= 0x4,         /**< Interrupt from Synchronous Queue */
}ces_fw_intr_type_t;

/**
@brief <H3></H3>
   Firmware types that are supported by CES.
*/
typedef enum
{
   ISMD_CES_FW_PARSER,                     /**< Parser Firmware */
   ISMD_CES_FW_DECODER,                    /**< Decoder Firmware */
   ISMD_CES_FW_ENCODER,                    /**< Encoder Firmware */
   ISMD_CES_FW_MUX,                        /**< Mux Firmware */
   ISMD_CES_FW_IPC,
   ISMD_CES_FW_MAX,
   ISMD_CES_FW_UNDEFINED = 0xFFFFFFFF,     /**< Undefined error value */
}ces_fw_supported_fw_types_t;

/**
@brief <H3></H3>
   Queue type.
*/
typedef enum
{
   CES_FW_QUEUE_TYPE_FREE=0,    /**< Free unused Q */
   CES_FW_QUEUE_TYPE_INPUT,     /**< Input Q to Firmware */
   CES_FW_QUEUE_TYPE_OUTPUT,    /**< Output Q from Firmware */
}ces_fw_queue_type_t;


/**
@brief <H3></H3>
   Queue descriptors that are shared between Host and firmware.
*/
typedef struct
{
   uint32_t phys;    /**<  DDR addr of where the actual message data is*/
   uint32_t len;     /**<  Size of the message pointed by phys*/
   uint32_t flags;   /**<  Inband message types*/
   uint32_t id;      /**<  id for the current buffer used by host only*/
}ces_fw_que_desc_t;

typedef ces_fw_que_desc_t ces_fw_ipc_msg_t;

/**
@brief <H3></H3>
   Data associated with current interrupt.
*/
typedef struct
{
   uint32_t     data; /* TBD */
}ces_fw_intrpt_data_t;

/**
@brief <H3></H3>
   Indicates the interrupt event which needs to be enabled.
*/
typedef enum {
   /** Enable interrupt from MP2VDP */
   CES_FW_EVENT_MP2VDP_ENABLE,

   /** Enable interrupt from H264VDP */
   CES_FW_EVENT_H264VDP_ENABLE,

   /** Enable interrupt from VC1VDP */
   CES_FW_EVENT_VC1VDP_ENABLE,
   
   /** Enable interrupt from MFVDP */
   CES_FW_EVENT_MFVDP_ENABLE,

   /**< Enable interrupt from H264VE */
   CES_FW_EVENT_H264VE_ENABLE
} ces_fw_int_event_enable_t;

/*@}*/

#ifdef __cplusplus
}
#endif

#endif
