
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

#ifndef IPCLIB_CONFIG_H
#define IPCLIB_CONFIG_H 1

#include "auto_eas/gen4_dpe.h"

/** How big is the largest message */
#define CONFIG_IPC_MESSAGE_MAX_SIZE             512

/** Configure Queue Headers (the central read/write pointers)
 * to be located in firmware memory
 */
#define CONFIG_IPC_QUEUE_HEADERS_IN_FW_MEMORY

/** Byte-alignment requirement of each message
 * (MUST BE a power of two AT LEAST 4)
 */
#define CONFIG_IPC_MESSAGE_SIZE_ALIGN           8

/* Max supported streams by FW. In DPE Fw->host and Host->Fw will be same number
   of streams.*/
#define VPP_FW_SUPPORTED_STREAMS               16

/* AVDL_TSD_NUM_STREAMS to FW */
#define CONFIG_IPC_FW_MAX_RX_QUEUES             VPP_FW_SUPPORTED_STREAMS
#define CONFIG_IPC_FW_QUEUE_SIZE                1024 

/* Is there a PeekMessage function? */
#define CONFIG_IPC_FW_MESSAGE_PEEK

/* One return Queue to host (usually larger) */
#define CONFIG_IPC_HOST_MAX_RX_QUEUES           VPP_FW_SUPPORTED_STREAMS
#define CONFIG_IPC_HOST_QUEUE_SIZE              1024 

/* Does the firmware "share" a single message for processing among
 * all the ports, or does each input path have it's own message
 */
#define CONFIG_FW_IPC_USES_ONE_MESSAGE_PER_RECEIVE_PORT

#define DPE_LOCAL_SRAM_BASE     0x10000000
#define DPE_HOST_SRAM_ROFF      0x0000
#define FW_PTR_TO_REGISTER_OFFSET( fw_ptr ) ((int)((char *)(fw_ptr) - DPE_LOCAL_SRAM_BASE) + DPE_HOST_SRAM_ROFF)
#define REGISTER_OFFSET_TO_FW_PTR( roff ) ((int)((char *)(roff) + DPE_LOCAL_SRAM_BASE - DPE_HOST_SRAM_ROFF))

/* ---- queued messages ---- */

/* Synchronous (one at a time) message block (no queueing) */
#define CONFIG_IPC_SYNC_MESSAGE_OFFSET          0x8000/*0x8000*/

/* size of tsd_fw_dmem_map_t.tsd_fw_registers_t.data_payload */
#define CONFIG_IPC_SYNC_MESSAGE_BUF_SIZE        4096

/* What is the PAL device name we open */
#define CONFIG_IPC_PAL_UNIT_NAME               "DPE"

/* How many overflow messages can we hold */
#define CONFIG_IPC_HOST_NUM_OVERFLOW_MESSAGES   0


#define CONFIG_IPC_ROFF_RISC_RX_DOORBELL        ROFF_DPE_CP_DOORBELL
#define CONFIG_IPC_ROFF_HOST_RX_DOORBELL        ROFF_DPE_HOST_DOORBELL

#define CONFIG_IPC_ROFF_HOST_DOORBELL_STATUS    ROFF_DPE_HOST_IPC_STATUS
#define CONFIG_IPC_DOORBELL_STAT_HOST_READY  BMSK_DPE_HOST_IPC_STATUS_READY
#define CONFIG_IPC_DOORBELL_STAT_HOST_DONE   BMSK_DPE_HOST_IPC_STATUS_DONE

#define CONFIG_IPC_ROFF_RISC_DOORBELL_STATUS    ROFF_DPE_CP_IPC_STATUS
#define CONFIG_IPC_DOORBELL_STAT_RISC_READY  BMSK_DPE_CP_IPC_STATUS_READY
#define CONFIG_IPC_DOORBELL_STAT_RISC_DONE   BMSK_DPE_CP_IPC_STATUS_DONE

/** register offset which puts unit into reset */
#define CONFIG_IPC_ROFF_FW_RESET                ROFF_DPE_CP_CONTROL_REGISTER
#define CONFIG_IPC_ROFF_FW_PROG_COUNTER         ROFF_DPE_CP_ICACHE_BASE_ADDRESS

#endif /* IPCLIB_CONFIG_H */
