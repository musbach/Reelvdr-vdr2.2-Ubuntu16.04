

/** 

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
  Santa Clara, CA  97052

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

/**
   File Name: ismd_ces_context.h
*/

#ifndef _ISMD_CES_CONTEXT_H_
#define _ISMD_CES_CONTEXT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_global_defs.h"
#include "osal.h"
#include "sven_devh.h"
#include "ismd_ces_driver_interface.h"
#include "ismd_ces_fw_interface.h"

/**
   This will define the F/W service specific context for CES
 */
typedef struct ces_fw_service_context
{
   /* F/W service callbacks */
   ismd_ces_service_callbacks_t fw_callbacks;

   /* Boolean to indicate if service is registered */
   bool is_service_registered;

   /* Interrupt event for this F/W service */
   ismd_event_t interrupt_event;
} ces_service_context_t;


/**
   This will define the CES driver context. It will be used for maintaining 
   internal State information.
 */
typedef struct ces_context 
{
   /* Semaphore to access this context*/
   os_sema_t context_lock;
   bool context_lock_created;

   /* Context Sven Handle for debugging*/
   os_devhandle_t * sven_handle;

  /* F/W service context array.
   * Enum ces_fw_supported_types_t values will be used as index to the 
   * corresponding F/W Service context */
  ces_service_context_t services[ISMD_CES_FW_MAX]; 
} ces_context_t;

#ifdef __cplusplus
}
#endif

#endif /*_ISMD_CES_CONTEXT_H_*/
