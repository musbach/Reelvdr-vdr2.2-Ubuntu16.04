/*==========================================================================
  This file is provided under BSD license.  When using or 
  redistributing this file, you may do so under this license.

  BSD LICENSE 

  Copyright(c) 2005-2011 Intel Corporation. All rights reserved.
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

 =========================================================================*/
#ifndef _PAL_INTERRUPT_H
#define _PAL_INTERRUPT_H
#include "pal.h"

//! \file
//! This file contains definitions that are common to all the platform abstraction functions. 
/** @addtogroup PAL_ */
/* @{ */

/**
 * @brief Get device's BAR and IRQ#
 *  
 * Determine and return a device's base addresses and interrupt number
 *
 * This function is added for backwards compatability with
 * older versions of PAL, should only be used with gen2 devices.
 * 
 * @param[in] dev           PAL specific ID for the device
 * @param[out] pal_info     Structure for the device's BARs and interrupt number
 *
 * @retval PAL_SUCCESS Device found successfully
 * @retval PAL_FAILURE Device not found or invalid device ID
 */
pal_result_t pal_get_base_and_irq(pal_dev_id_t dev, pal_info_t **pal_info);

/**
 * @brief Get device's IRQ#
 * 
 * Determine and return a device's interrupt number
 * 
 * @param[in] dev_id       PAL specific ID for the device
 * @param[out] p_irq    Device's interrupt number
 *
 * @retval PAL_SUCCESS  Device found successfully
 * @retval PAL_FAILURE  Device not found or invalid device ID
 */
pal_result_t pal_get_irq(pal_dev_id_t dev_id, unsigned long *p_irq);

/**
 * @brief Register to receiver interrrupts
 *
 * This function does the operating system specific calls for registering the 
 * bottom half interrupt handler for the driver calling this function
 *
 * @param[in] irq           Indicates the device signaling the interrupt.
 * @param[in] devicekey     Key to indicate which device on a shared interrupt is
 *                      interrupting. 
 * @param[in] driver_name   ASCII string indicating the driver that the interrupt
 *                      is intended for.
 *
 * @param[in] handler       Pointer to the interrupt handler.
 * @param[in] data          Pointer to the data needed by operating system for
 *                      registering the interrupt
 *
 * @retval handle       Handle to interrupt.
 */
os_interrupt_t pal_acquire_interrupt(   int irq,
                                        int devicekey,
                                        char *driver_name,
                                        os_interrupt_handler_t *handler,
                                        void *data);

/**
 * @brief  Releases the interrupt
 *
 * @param interrupt_handle   Handle to interrupt
 */
void pal_release_interrupt(os_interrupt_t interrupt_handle);

/* put os_acquire_interrupt, os_release_interrupt here to avoid circular dependency */
/** Register a interrupt */ 
#define os_acquire_interrupt(a,b,c,d,e) pal_acquire_interrupt(a,b,c,d,e)
/** Release the interrupt */
#define os_release_interrupt(x) pal_release_interrupt(x)
/* @} */
#endif
