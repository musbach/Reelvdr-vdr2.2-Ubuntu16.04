
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
#ifndef _DPE_MESSAGE_H_
#define _DPE_MESSAGE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dpe_common.h"

/** @weakgroup dpe_message_defs DPE Message Definitions */
/** @ingroup dpe_message_defs */
/*@{*/

/** This defines the maximum size (in bytes) of the message content. */
#define DPE_MESSAGE_SIZE_MAX        (80)

/** During development, DPE_DEBUG should be defined in order to get debug 
messages. */

#ifdef DPE_DEBUG
/** This defines a debug message macro for function entry.  unit is of type
dpe_unit_t, and function is a text string of the function name. */
#define DPE_MESSAGE_FUNC_ENTER(a_unit, a_id) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_FUNC_ENTER; \
   message.data.id = (dpe_id_t) a_id; \
   dpe_message(message); \
}
/** This defines a debug message macro for function exit.  unit is of type
dpe_unit_t, and function is a text string of the function name. */
#define DPE_MESSAGE_FUNC_EXIT(a_unit, a_id) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_FUNC_EXIT; \
   message.data.id = (dpe_id_t) a_id; \
   dpe_message(message); \
}
/** This defines a debug message macro for debug message.  unit is of type
dpe_unit_t, and debug is a text string. */
#define DPE_MESSAGE_DEBUG(a_unit, a_id) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_DEBUG; \
   message.data.id = (dpe_id_t) a_id; \
   dpe_message(message); \
}
/** This defines a debug message macro for assertion if condition is met.  It
is assumed that the function would then return DPE_RESULT_FAILURE.  unit is of 
type dpe_unit_t, and comparison is the condition. */
#define DPE_MESSAGE_ASSERT(a_unit, comparison, a_id) { \
   if ((comparison)) { \
      dpe_message_t message; \
      message.unit = a_unit; \
      message.type = DPE_MESSAGE_TYPE_ASSERT; \
      message.data.id = (dpe_id_t) a_id; \
      dpe_message(message); \
      return DPE_RESULT_FAILURE; \
   } \
}
/** This defines a debug message macro for warning.  unit is of type 
dpe_unit_t, and warning is a text string. */
#define DPE_MESSAGE_WARN(a_unit, a_id) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_WARN; \
   message.data.id = (dpe_id_t) a_id; \
   dpe_message(message); \
}
/** This defines a debug message macro for fatal error.  unit is of type 
dpe_unit_t, and error is a text string. */
#define DPE_MESSAGE_FATAL_ERROR(a_unit, a_id) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_FATAL_ERROR; \
   message.data.id = (dpe_id_t) a_id; \
   dpe_message(message); \
}
/** This defines a debug message macro for result of reading register.  unit is 
of type dpe_unit_t, a_offset is of type uint32_t, and a_value is of type 
uint32_t. */
#define DPE_MESSAGE_REG_READ(a_unit, a_offset, a_value) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_REG_READ; \
   message.data.reg.offset = a_offset; \
   message.data.reg.value = a_value; \
   dpe_message(message); \
}
/** This defines a debug message macro for result of writing register.  unit is 
of type dpe_unit_t, a_offset is of type uint32_t, and a_value is of type 
uint32_t. */
#define DPE_MESSAGE_REG_WRITE(a_unit, a_offset, a_value) { \
   dpe_message_t message; \
   message.unit = a_unit; \
   message.type = DPE_MESSAGE_TYPE_REG_WRITE; \
   message.data.reg.offset = a_offset; \
   message.data.reg.value = a_value; \
   dpe_message(message); \
}
#else
#define DPE_MESSAGE_FUNC_ENTER(a_unit, a_id)
#define DPE_MESSAGE_FUNC_EXIT(a_unit, a_id)
#define DPE_MESSAGE_DEBUG(a_unit, a_id)
#define DPE_MESSAGE_ASSERT(a_unit, comparison, a_id)
#define DPE_MESSAGE_WARN(a_unit, a_id)
#define DPE_MESSAGE_FATAL_ERROR(a_unit, a_id)
#define DPE_MESSAGE_REG_READ(a_unit, address, value)
#define DPE_MESSAGE_REG_WRITE(a_unit, address, value)
#endif

/** This enumeration defines the types of messages available. */
typedef enum {
   DPE_MESSAGE_TYPE_FUNC_ENTER,
   DPE_MESSAGE_TYPE_FUNC_EXIT,
   DPE_MESSAGE_TYPE_DEBUG,
   DPE_MESSAGE_TYPE_ASSERT,
   DPE_MESSAGE_TYPE_WARN,
   DPE_MESSAGE_TYPE_FATAL_ERROR,
   DPE_MESSAGE_TYPE_REG_READ,
   DPE_MESSAGE_TYPE_REG_WRITE,
   DPE_MESSAGE_TYPE_MAX
} dpe_message_type_t;

/** This enumeration defines the types of messages available. */
typedef enum {
   DPE_ID_unknown,
   
   /* List of generic debug points. */
   DPE_ID_debug_point_0,
   DPE_ID_debug_point_1,
   DPE_ID_debug_point_2,
   DPE_ID_debug_point_3,
   DPE_ID_debug_point_4,
   DPE_ID_debug_point_5,
   DPE_ID_debug_point_6,
   DPE_ID_debug_point_7,
   DPE_ID_debug_point_8,
   DPE_ID_debug_point_9,
   DPE_ID_debug_point_a,
   DPE_ID_debug_point_b,
   DPE_ID_debug_point_c,
   DPE_ID_debug_point_d,
   DPE_ID_debug_point_e,
   DPE_ID_debug_point_f,

   /* List of functions. */
   DPE_ID_dpe_fw_core_initialize,
   DPE_ID_dpe_fw_core_set_stream_states,
   DPE_ID_dpe_fw_core_get_stream_state,
   DPE_ID_dpe_fw_core_init_scalers,
   DPE_ID_dpe_fw_core_set_strides,
   DPE_ID_dpe_fw_core_process_picture,
   DPE_ID_dpe_c422_config_picture,
   DPE_ID_dpe_c422_config_stride,
   DPE_ID_dpe_calc_strides,
   DPE_ID_dpe_cp_set_atr,
   DPE_ID_dpe_cp_dma_data,
   DPE_ID_dpe_cp_get_cp_doorbell,
   DPE_ID_dpe_cp_clear_cp_doorbell,
   DPE_ID_dpe_cp_set_host_doorbell,
   DPE_ID_dpe_cp_is_host_doorbell_cleared,
   DPE_ID_dpe_cp_enable_stc,
   DPE_ID_dpe_cp_set_stc_source,
   DPE_ID_dpe_cp_set_stc_counter,
   DPE_ID_dpe_cp_get_stc_counter,
   DPE_ID_dpe_cp_enable_watchdog,
   DPE_ID_dpe_cp_set_watchdog_counter,
   DPE_ID_dpe_cp_get_watchdog_counter,
   DPE_ID_dpe_cp_enable_interrupts,
   DPE_ID_dpe_cp_get_interrupt_status,
   DPE_ID_dpe_cp_clear_interrupt_status,
   DPE_ID_dpe_cp_enable_events,
   DPE_ID_dpe_cp_get_event_status,
   DPE_ID_dpe_cp_clear_event_status,
   DPE_ID_dpe_cp_enable_ext_events,
   DPE_ID_dpe_cp_get_ext_event_status,
   DPE_ID_dpe_cp_clear_ext_event_status,
   DPE_ID_dpe_di_config_picture,
   DPE_ID_dpe_di_config_stride,
   DPE_ID_dpe_di_set_next_block_fifo,
   DPE_ID_dpe_di_set_software_frame_start,
   DPE_ID_dpe_di_read_software_frame_start,
   DPE_ID_dpe_dma_set_state,
   DPE_ID_dpe_dma_set_master_state,
   DPE_ID_dpe_dma_set_all_states,
   DPE_ID_dpe_dma_get_state,
   DPE_ID_dpe_dma_config_picture,
   DPE_ID_dpe_dma_config_fgr_picture,
   DPE_ID_dpe_dma_config_indv_stride,
   DPE_ID_dpe_dma_config_stride,
   DPE_ID_dpe_dma_config_fgr_stride,
   DPE_ID_dpe_drta_dwta_set_state,
   DPE_ID_dpe_drta_dwta_get_state,
   DPE_ID_dpe_drta_dwta_config_picture,
   DPE_ID_dpe_drta_config_stride,
   DPE_ID_dpe_dwta_config_stride,
   DPE_ID_dpe_fgt_config_picture,
   DPE_ID_dpe_fgt_config_stride,
   DPE_ID_dpe_fgt_config_np,
   DPE_ID_dpe_hsc_config_picture,
   DPE_ID_dpe_hsc_config_stride,
   DPE_ID_dpe_hsc_config_coeff,
   DPE_ID_dpe_rnr_config_picture,
   DPE_ID_dpe_rnr_config_stride,
   DPE_ID_dpe_vsc_config_picture,
   DPE_ID_dpe_vsc_config_stride,
   DPE_ID_dpe_vsc_config_coeff,
   
   /* List of debug messages. */
   DPE_ID_stream_id_greater_than_or_equal_to_DPE_MAX_STREAMS,
   DPE_ID_table_count_equal_to_0,
   DPE_ID_table_count_greater_than_DPE_SCALER_TABLES_MAX,
   DPE_ID_stride_resolution_equal_to_0,
   DPE_ID_bank_sel_greater_than_or_equal_to_DPE_xSC_COEFF_BANK_MAX,
   
   DPE_ID_MAX
} dpe_id_t;

/** This structure defines the message content. */
typedef struct {
   dpe_message_type_t type;   /** Identification of message. */
   uint32_t order_id;         /** Order of the processed message. */
   dpe_unit_t unit;           /** Unit generated this message. */
   union {
      dpe_id_t id;
      struct {
         uint32_t offset;
         uint32_t value;
      } reg;
   } data;                    /** Payload of the message. */
} dpe_message_t;

/** This variable tracks the order of the current message getting processed. */
//extern uint32_t _dpe_fw_order_id;

/*@}*/
#ifdef DEBUG_HAL_DPE
/** @weakgroup dpe_message DPE Message Functions */
/** @ingroup dpe_message */
/*@{*/


/**
This function sends out a message for instrumentation or debugging purpose.
@param[in] message - Message associated with instrumentation or debugging.
*/

void
dpe_message(dpe_message_t message);

/*@}*/
#endif
    
#ifdef __cplusplus
}
#endif

#endif
