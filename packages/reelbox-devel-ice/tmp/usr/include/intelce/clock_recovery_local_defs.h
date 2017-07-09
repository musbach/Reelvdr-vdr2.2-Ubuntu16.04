/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
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
#ifndef __CLOCK_RECOVERY_LOCAL_DEFS_H__
#define __CLOCK_RECOVERY_LOCAL_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sven.h"
#include "osal.h"
#include "sven_event_type.h"
#include "sven_devh.h"
#include "ismd_clock_recovery.h"
#include "algo_adaptive_pid.h"

#define INVALID_VALUE -1
/* Print a message only if the severity level of the message is less than the current debug verbosity level */
#define ISMD_LOG_MSG(level, format...)  if( (level) <= ismd_debug_level ) OS_INFO(format)
#define ISMD_CLOCK_SYNC_MAX 6

typedef enum {
   CLOCK_SYNC_STATE_CLOSED= 1,
   CLOCK_SYNC_STATE_OPEN  = 2
} clock_sync_status_t;


typedef enum {
    FreeRun,
    Setup,
    Acquiring,
    Tracking,
} algo_state;

typedef union {
   SoftPLL spll;
   AdaptivePID apid;
} clock_sync_algo_data_t;

typedef struct
{
   ismd_clock_t                clock;             //Clock handle associated to this clock synchronizer / recoverer.
   bool                        clock_associated;  //If a clock is already associated to this clock synchronizer/recoverer or not
   ismd_clock_sync_algo_t      algorithm_type;    //Algorithm to be used by the clock recoverer.
   clock_sync_status_t         state;             //Status of clock synchronizer / recoverer i.e Open / Closed (allocated/free)
   clock_sync_algo_data_t      clock_sync_algos; 
   void *                      algo_struct;       //Algorithm specific data structure to be used by the specified algorithm
   os_sema_t                   lock;              //Semaphore Lock
   ismd_event_t                user_event[ISMD_CLOCK_SYNC_EVENT_MAX]; //ISMD events registered by the client
   ismd_clock_source_t         master_clock_source;
   ismd_result_t               result;
   algo_state                  algorithm_state;   //Current operational state of the clock recovery algorithm
   int                         tracking_counter;  
   int                         last_adjustment;   //Last adjustment (in PPM) requested to the clocking unit, by the clock recovery 
                                                  //algorithm.  Adjustment is relative to nominal (~27Mhz) freq. 
} clock_sync_context_t;

extern os_devhandle_t *dbg_devh;

void smd_core_send_sven_event(
    os_devhandle_t          *devh,
    enum SVEN_EV_SMDCore_t   subtype,
    int                      payload0,
    int                      payload1,
    int                      payload2,
    int                      payload3,
    int                      payload4,
    int                      payload5 );
   

/* Print a message only if the severity level of the message is less than the current debug verbosity level */
#define ISMD_LOG_MSG(level, format...)  if( (level) <= ismd_debug_level ) OS_INFO(format)

/** Sven function enter / exit events */
#define CLOCK_SYNC_SVEN_ENTER(devh) if(NULL != devh) DEVH_FUNC_ENTER(devh);
#define CLOCK_SYNC_SVEN_EXIT(devh) if(NULL != devh) DEVH_FUNC_EXIT(devh);

/**
Allows the autoapi system to track calls to open clock sync devices from applications. Registers 
with autoapi in case the app terminates without closing the clock sync. In such a case,  
ismd_clock_sync_close_autoapi_callback will get invoked to handle the close operation.
Typically called from the ioctl and direct servers for clock recovery.

@param[in] connection : a handle that represents a client. 
@param[in] sync       : a handle to the clock sync resource that is being opened.

@retval ISMD_SUCCESS : the clock recoverer was successfully opened and the transaction registered with autoapi.
@retval ISMD_ERROR_NO_RESOURCES :  not enough resources existed to open the
clock recoverer.
*/
ismd_result_t ismd_clock_sync_open_track(unsigned long connection, ismd_clock_sync_t *sync);

/**
Allows the autoapi system to track calls to close clock sync devices from applications. Unregisters 
with autoapi the ismd_clock_sync_close_autoapi_callback. 
Typically called from the ioctl and direct servers for clock recovery.

@param[in] connection : a handle that represents a client. 
@param[in] sync       : a handle to the clock sync resource that is being closed.

@retval ISMD_SUCCESS : the clock recoverer was successfully opened and the transaction registered with autoapi.
*/
ismd_result_t ismd_clock_sync_close_track( unsigned long connection, ismd_clock_sync_t handle );

#ifdef __cplusplus
}
#endif
   
#endif

