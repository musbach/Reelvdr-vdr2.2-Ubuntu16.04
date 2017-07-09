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
  Intel Corporation
  2200 Mission College Blvd.
  Santa Clara, CA 97052

  BSD LICENSE

  Copyright(c) 2010-2011 Intel Corporation. All rights reserved.

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

#ifndef __CES_SERVICES_PVT_H__
#define __CES_SERVICES_PVT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "osal.h"
#include "sven_devh.h"
#include "pal.h"
#include "ismd_global_defs.h"
#include "ismd_ces_fw_interface.h"
#include "auto_eas/gen4_gv.h"
#include "ismd_core.h"
#include "ismd_core_protected.h"
#include "ces_fw_common_defs.h"
#include "ces_host_common_callbacks.h"

#define CES_SERVICES_MAX_NUM_SERVICES_SUPPORTED MAX_NUM_SERVICES_SUPPORTED

/*list of all supported services by this vsparc driver*/
typedef enum {
   CES_SERVICES_HIGHMIPS_INDEX        = 0,
   CES_SERVICES_LOWLATENCY_INDEX      = 1,
   CES_SERVICES_INVALID_INDEX         = 2
} ces_service_service_index_t;

/*services data structure */
typedef struct ces_service_service_context
{
   ces_fw_supported_fw_types_t service_type;
   
   /*is the service supported on this SoC*/
   bool is_supported;

   /* This flag indicates if the service is active right now. 
    * Service may be disabled by making a 'suspend' call by
    * the CES driver. By default service is active if it is 
    * supported on this SoC */
   bool is_active;

   /* pointer to ismd event for interrupt */
   ismd_event_t *interrupt_event;

} ces_service_service_context_t;

/*global context defined here*/
typedef struct ces_service_global_context
{
   /* to protect accesses to this structure */
   os_sema_t      global_driver_lock;
   bool           global_driver_lock_created;

   pal_soc_info_t soc_info;
   ces_service_service_context_t service[CES_SERVICES_MAX_NUM_SERVICES_SUPPORTED];

   /*callbacks to the host IPC library*/
   ces_host_common_callbacks_t host_callbacks;

   /*handle to underlying FW loaded by the driver*/
   os_devhandle_t   *fw_devh;

   /*flag to denote if fw is loaded, reqd for power management*/
   bool fw_loaded;

} ces_service_global_context_t;

/* This is the declaration of global data structure */
extern ces_service_global_context_t ces_service_global_data;

/* ces_service_debug_level_t defines the debug levels to enable/disable
 * the logging of debug messages.
 * DEBUG_LEVEL_OFF    : no logging
 * DEBUG_LEVEL_ON     : the debug information will be printed by VIDDEC_LOG.
 * DEBUG_LEVEL_ERRORS : error message will be printed by VIDDEC_LOG
 *                      defined below.
 *
 * DEBUG_LEVEL_ON should be used to enable printing of any debug information.
 * DEBUG_LEVEL_ERRORS should be used to print any error messages.
 */
typedef enum
{
   DEBUG_LEVEL_OFF     = 0,
   DEBUG_LEVEL_ON      = 1,
   DEBUG_LEVEL_ERRORS  = 2
} ces_service_debug_level_t;

/* This macro is used for printing debug messages */
#define CES_SERVICES_LOG(level, format...) if(level > DEBUG_LEVEL_OFF) OS_PRINT(format)


/* Macros required for autoapi scripts */
#define ISMD_MODULE_INIT ismd_ces_service_init
#define ISMD_MODULE_EXIT ismd_ces_service_deinit

/** Macros to simplify vsparc locking */
#define CES_SERVICE_GET_LOCK() os_sema_get(&ces_service_global_data.global_driver_lock)
#define CES_SERVICE_PUT_LOCK() os_sema_put(&ces_service_global_data.global_driver_lock)

/*These are the callbacks registered with CES driver */

/* Function to open an queue for sending/recieving asynchronous 
 * messages to the FW.
 */ 
uint32_t ces_service_queue_open(uint32_t queue_phys_addr,
                           uint32_t queue_size,
                           ces_fw_queue_type_t queue_type,
                           uint32_t *queue_id);

/* Function to close an asynchronous message queue. */
uint32_t ces_service_queue_close(uint32_t queue_id);

/* Function to send a synchronous message to the FW */
uint32_t ces_service_sync_send(uint32_t group_id, 
                      uint32_t func_id, 
                      void *params,
                      uint32_t size); 

/* Function to send an asynchronous message to the FW.*/
uint32_t ces_service_async_send(uint32_t queue_id, void *message);

/* This is used to read an asynchronous message */
uint32_t ces_service_async_recv(uint32_t queue_id, void *message);

/* Function to get available queue space in case of send queue
 * and num of available messages in case of receive queue. */
uint32_t ces_service_get_q_status(uint32_t queue_id, 
                             uint32_t *data_avail,
                             uint32_t *space_avail);

/* This is used to perform power management suspend call to the vsparc*/
uint32_t ces_service_suspend(ces_fw_supported_fw_types_t service);

/* This is used to perform power management resume call to the vsparc*/
uint32_t ces_service_resume(ces_fw_supported_fw_types_t service);

/* This is used to get the fw supported capabilities.
 * This is exposed only for testing purpose */
uint32_t ces_service_fw_get_supported_capabilities(ces_fw_supported_fw_types_t *highMips,
                                              ces_fw_supported_fw_types_t *lowLatency);

/* Other function prototypes */
ismd_result_t ces_service_get_buf_info_from_memory_layout(char *buf_name, 
                                                          uint32_t *buf_size, 
                                                          uint32_t *buf_addr);

ismd_result_t ces_service_unload_fw(void);

ismd_result_t ces_service_load_fw(void);

uint32_t ces_service_get_service_index(ces_fw_supported_fw_types_t service);

bool ces_service_is_service_valid(ces_fw_supported_fw_types_t service);

bool ces_service_is_service_active(ces_fw_supported_fw_types_t service);

ces_fw_return_types_t ces_service_mark_service_suspended(ces_fw_supported_fw_types_t service);

bool ces_service_are_all_services_suspended(void);

ces_fw_return_types_t ces_service_mark_service_resumed(ces_fw_supported_fw_types_t service);

void ces_service_mark_all_services_resumed(void);

uint32_t ces_service_deinit_fw(os_devhandle_t **fw_devh);

void ces_service_update_service_info(ismd_event_t *hm_intr_event,
                                     ismd_event_t *ll_intr_event);

ismd_result_t ces_service_global_alloc (unsigned int size,
                                   ismd_buffer_handle_t *handle,
                                   ismd_buffer_descriptor_t *desc);

ismd_result_t ismd_ces_service_init(void);

ismd_result_t ismd_ces_service_deinit(void);

void 
ces_service_validate_capabilities(ces_fw_supported_fw_types_t high_mips_service,
                                  ces_fw_supported_fw_types_t low_latency_service);

#ifdef __cplusplus
}
#endif
#endif /*__CES_SERVICES_PVT_H__*/
