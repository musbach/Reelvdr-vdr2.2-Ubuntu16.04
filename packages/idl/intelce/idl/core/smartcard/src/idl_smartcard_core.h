/*
#
#  This file is provided under a dual BSD/GPLv2 license.  When using or
#  redistributing this file, you may do so under either license.
#
#  GPL LICENSE SUMMARY
#
#  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of version 2 of the GNU General Public License as
#  published by the Free Software Foundation.
#
#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
#  The full GNU General Public License is included in this distribution
#  in the file called LICENSE.GPL.
#
#  Contact Information:
#  intel.com
#  Intel Corporation
#  2200 Mission College Blvd.
#  Santa Clara, CA  95052
#  USA
#  (408) 765-8080
#
#
#  BSD LICENSE
#
#  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the name of Intel Corporation nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*/

/*----------------------------------------------------------------------
 * File Name:       idl_smartcard_core.h
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 *
 */


/* @weakgroup Smartcard Interface IDL SMARTCARD INTERFACE Functions
 * IDL Interface for General Smartcard Interface (scard_infc). 
 *
 * @section IDL Smartcard Interface Overview
 * This library provides a set of functions to access Smartcard Interface on Intel Media
 * Processors. This Library support following in smart card interface
 * - T=0 character, T=1 block communication protocol
 * Supports any combination of the following clock-rate conversion factor F, and bit-rate 
 * adjustment factor D to support variety of smart card types
 * F={372, 512, 558}
 * D={1,2,4,8,16, 32, 12, 20}
 * Supports Smart Card reset pin control (using reset pin control and power supply control, 
 * warm/cold reset of the 14 card can be initiated by software).
 * Supports card insertion and removal detection with automatic card power-down on removal
 * The interface does not require a DMA to communicate to smart card.
 * @section Intended Audience
 * This library is intended to be used by system designers, device driver 
 * developers, and application developers.
 * 
 * @section Organization
 * The library is subdivided into the general categories:
 * - Initialization/Cleanup
 * - Configuration
 * - Get/Set routines
 * .
 * <B> Initialization/Cleanup </B> <br><br>
 * These routines are responsible for allocating the resources needed to 
 * access the Smartcard Interface and to free up these resources when they are no longer
 * needed. This API defines two functions in this category:
 * -# idl_scard_infc_set_config() - Initialize system resources needed to access 
 * Smartcard Interface.
 * -# idl_sc_clear_config() - Release the resourced allocated by idl_sc_set_config().
 * .
 * <B> Configuration </B><br><br>
 * These routines configure the different capabilities of the Smartcard Interface.
 * -# idl_sc_enable_interrupt() - Configure the smartcard interface to 
 *  act as an interrupt line.
 * -# idl_sc_disable_interrupt() - Disable the specified interrupt bit.
 * -# idl_sc_interrupt_handler() - Specifies the function to be
 * called when a some smartcard interface interrupt occurs.This is secondary interrupt
 * routine.
 * -#idl_sc_card_cold_reset() - Perform cold reset of smartcard
 * -#idl_sc_card_warm_reset() - Perform warm reset of smartcard
 * . 
 * <B> Get/Set routines </B><br><br>
 * These routines get/set the various functionality of smart card interface.
 * -# idl_sc_write_byte() - write a character to TX FIFO.
 * -# idl_sc_read_byte() - Get acharacter from RX FIFO.
 * -# idl_sc_interrupt_occurred() - Get the reason for an interrupt.
 * -# idl_sc_get_rx_length() - get the current data length status of RX FIFO
 * -# idl_sc_get_tx_length() - get the current data length status of TX FIFO 
 * -# idl_sc_card_deactivate() - Deactivate the card from smart card interface
 * -# idl_sc_card_removal() - Handle the unexpected removal of card from interface
 * 
 */

#ifndef _IDL_SMARTCARD_CORE_H_
#define _IDL_SMARTCARD_CORE_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "idl.h"
#include "osal_thread.h"
#include "osal_event.h"
#include "osal_interrupt.h"

/*
 * This routine will set minimum configuration for smart card interface
 * as defined by ISO7816-3. so that Driver can atleast access card
 */
int sc_infc_init(uint8_t slot);

/*
 * This function frees any memory associated with the smartcard interface. This functions should be
 * called last
 */
int sc_infc_deinit(uint8_t slot);

int sc_infc_reset(uint8_t slot, sc_reset_t type, sc_vcc_t vcc);

int sc_infc_get_slot_info(uint8_t slot, sc_slot_info_t *info);
                
int sc_infc_start_section(uint8_t slot, sc_section_t *section);

/*
 * This routine will get the current number of bytes in receive buffer 
 */
int sc_infc_get_rx_length(uint8_t slot, uint32_t *rx_length);

/*
 * This routine will get the current number of bytes in transmit buffer 
 */
int sc_infc_get_tx_length(uint8_t slot, uint32_t *tx_length);

/*
 * This routine will reset the receive fifo 
 */
int sc_infc_reset_rx_fifo(uint8_t slot);

/*
 * This routine will reset the transmit fifo 
 */
int sc_infc_reset_tx_fifo(uint8_t slot);

int sc_infc_set_rx_trigger_level(uint8_t slot, uint16_t rx_tl);

int sc_infc_set_tx_trigger_level(uint8_t slot, uint16_t tx_tl);

int sc_infc_set_protocol(uint8_t slot, uint32_t protocol);

int sc_infc_read(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_read);

int sc_infc_write(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_write);

int sc_infc_get_event_status(uint8_t slot, uint32_t *event_status);

/*
 * This function specifies the user function that should be called when the smartcard interface 
 * generates an event. For example, the receive FIFO level is above a previously defined 
 * threshold.
 */
int sc_infc_register_event_handler(uint8_t slot, os_interrupt_handler_t *handler, void *data);

int sc_infc_release_event_handler(uint8_t slot);

/*
 * This routine will enable the interrupts for smart card interface
 */
int sc_infc_enable_event(uint8_t slot, uint32_t event);

/*
 * This routine will disable the interrupts for smart card interface
 */
int sc_infc_disable_event(uint8_t slot, uint32_t event);

/*
 * This routine will clear the smart card interface supported interrupt status 
 * bit based on interrupt type and thn will re-enable the same interrupt
 * @param smartcard_id - intel_gen3 support 0, 1 ( smartcard id)
 * @param event - Interrupt value in hex supported by smart card interface, following
 * types are currently supported
 * - Parity error interrupt 
 * - T=0 error interrupt 
 * - Framing error interrupt 
 * - Receive timeout interrupt 
 * - Character waiting time interrupt
 * - Block waiting time interrupt
 * - Receive Data Ready interrupt
 * - Transmit data refill interrupt
 * - smart card detection interrupt
 * - RXFIFO Receive request in event of a timeout situation interrupt
 * - RXFIFO Receive request interrupt
 * @retval IDL_SUCCESS if smartcard interface interrupt bit is cleared and re-enabled
 * @retval IDL_NOT_INITIALIZED if system is unable to map smartcard interface register space 
 * @retval IDL_INVALID_PARAM if smartcard interface id or interrupt type is invalid.
 */
int sc_infc_clear_event(uint8_t slot, uint32_t event);

/*
 * This routine will determine the cause of interrupt, when interrupt from the smart card interface 
 * is processed by driver, the SW should read this register bits to determine the cause of interrupt request
 * @param smartcard_id - intel_gen3 support 0, 1 ( smartcard id)
 * @param event - Interrupt value in hex supported by smart card interface, following
 * types are currently supported
 * - Parity error interrupt 
 * - T=0 error interrupt 
 * - Framing error interrupt 
 * - Receive timeout interrupt 
 * - Character waiting time interrupt
 * - Block waiting time interrupt
 * - Receive Data Ready interrupt
 * - Transmit data refill interrupt
 * - smart card detection interrupt
 * @retval IDL_SUCCESS if smartcard interface interrupt bit is cleared
 * @retval IDL_NOT_INITIALIZED if system is unable to map smartcard interface register space 
 * @retval IDL_INVALID_PARAM if smartcard interface id or interrupt type is invalid.
 */

int sc_infc_event_cause(uint8_t slot, uint32_t event);

int sc_infc_card_deactivate(uint8_t slot);

int sc_infc_set_power_on(uint8_t slot, sc_vcc_t vcc);

/*
 * This routine will should be called after any unexpected card removal at interface 
 * unexpected removal destroy the smartcard content and this routine should be called
 * to prevent electrical damage to smartcard.
 * @param smartcard_id - intel_gen3 support 0, 1 ( smartcard id)
 * @retval IDL_SUCCESS if smartcard interface successfully handled the unexpeced
 * card removal process.
 * @retval IDL_INVALID_PARAM if smartcard interface id is invalid.
 */
int sc_infc_card_removal(uint8_t slot);


int sc_infc_set_cwt(uint8_t slot, uint32_t cwt);

int sc_infc_set_bwt(uint8_t slot, uint32_t bwt);
int sc_infc_set_dds(uint8_t slot, uint32_t dds);

int sc_infc_set_tor(uint8_t slot, uint32_t tor);

int sc_infc_set_clk_divisor(uint8_t slot, uint32_t c_div);

int sc_infc_set_iomode(uint8_t slot, uint32_t iomode);
/*
 * This routine configure the etu for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param c_div - 0-0xFF 
 * @param D - 0-0xFFFF
 * @param F - 0-0xFF
 * @retval true if etu values are set correctly
 */
int sc_infc_set_etu(uint8_t slot, uint32_t c_div, uint32_t divisor, uint32_t factor);

int sc_infc_set_egtr(uint8_t slot, uint32_t egtm);

int sc_infc_set_bgtr(uint8_t slot, uint32_t bgtm);

int sc_infc_warm_reset(uint8_t slot);

int sc_infc_adjust_reset_delay(uint8_t slot, uint32_t delay);

int sc_infc_suspend(uint8_t slot);
 
int sc_infc_resume(uint8_t slot);

int set_scard_alt_fun_pin(uint8_t slot, int flag);

#ifdef __cplusplus
}
#endif

#endif


