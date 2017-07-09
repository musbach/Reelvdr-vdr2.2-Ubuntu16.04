/*------------------------------------------------------------------------------
 * File Name: vpp_host.h
 *------------------------------------------------------------------------------
 */
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

#ifndef _DPE_HOST_H_
#define _DPE_HOST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dpe_common.h"

/* Please use definitions of registers and bit fields provided in the following
file. */
#include "auto_eas/gen4_dpe.h"


/* Note that this file exists only on the host side so should not use
dpe_reg_xxx() from dpe_reg.h and DPE_MESSAGE_XXX() from dpe_message.h. Instead,
the host-side equivalent functions (e.g., devh_ReadReg32(), devh_WriteReg32(),
and DEVH_XXX() from sven_devh.h) should be used. */
#include "sven_devh.h"

/** @weakgroup vpp_host_defs DPE Host Definitions */
/** @ingroup vpp_host_defs */
/*@{*/

/** This defines the number of 32-bit firmware cache masks. */

#define DPE_FW_CACHE_MASK_SIZE  3

/*@}*/

/** @weakgroup vpp_host DPE Host Functions */
/** @ingroup vpp_host */
/*@{*/

/**
This function set the system memory region accessible from CP.
@param[in] *devh - Device handle.
@param[in] atr - To select accessible system memory region.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_set_atr(os_devhandle_t *devh, const uint8_t atr);

/**
This function resets or "un-resets" the DPE control plane.
@param[in] *devh - Device handle.
@param[in] to_reset - To reset CP?
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_reset_cp(os_devhandle_t *devh, const bool to_reset);

/**
This function resets or "un-resets" the DPE pipe
@param[in] *devh - Device handle.
@param[in] to_reset - To reset CP?
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_reset_vpp_pipe(os_devhandle_t *devh, const bool to_reset);

/**
This function loads firmware for DPE control plane.
@param[in] *devh - Device handle.
@param[in] fw_address - Location to store firmware in system memory.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_load_fw(os_devhandle_t *devh, const uint32_t fw_address);
    
/**
This function gets the last command posted to the host doorbell.
@param[in] *devh - Device handle.
@param[out] *command - 32-bit command associated with the host doorbell.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_get_host_doorbell(os_devhandle_t *devh, uint32_t *command);

/**
This function clears the host doorbell after the command is processed.
@param[in] *devh - Device handle.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_clear_host_doorbell(os_devhandle_t *devh);

/**
This function posts a command to the CP doorbell.
@param[in] *devh - Device handle.
@param[in] command - 32-bit command associated with the CP doorbell.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_set_cp_doorbell(os_devhandle_t *devh, const uint32_t command);

/**
This function posts check if CP doorbell is cleared.
@param[in] *devh - Device handle.
@param[in] *is_cleared - Whether door bell is cleared.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_is_cp_doorbell_cleared(os_devhandle_t *devh, bool *is_cleared);

/**
This function checks if CP doorbell is cleared.
@param[in] *devh - Device handle.
@param[out] *is_cleared - Is CP doorbell cleared?
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_is_cp_doorbell_cleared(os_devhandle_t *devh, bool *is_cleared);

/**
This function enables selected interrupts.
@param[in] *devh - Device handle.
@param[in] vpp_interrupts - Selected interrupts.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_enable_interrupts(os_devhandle_t *devh, const uint32_t vpp_interrupts);

/**
This function gets the current interrupt status.
@param[in] *devh - Device handle.
@param[out] *vpp_interrupts - Current interrupt status.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_get_interrupt_status(os_devhandle_t *devh, uint32_t *vpp_interrupts);

/**
This function clears the selected interrupt status.
@param[in] *devh - Device handle.
@param[in] vpp_interrupts - Selected interrupt status.
@retval DPE_RESULT_SUCCESS if function succeeds.
@retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t
vpp_host_clear_interrupt_status(os_devhandle_t *devh,
   const uint32_t vpp_interrupts);


/*@}*/

#ifdef __cplusplus
}
#endif

#endif
