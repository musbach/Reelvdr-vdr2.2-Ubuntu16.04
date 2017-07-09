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
 * File Name:       idl_smartcard_core.c
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 *
 */

//#include "pal.h"
#include "osal.h"
#include "osal_memmap.h"
#include "osal_memory.h"
#include "osal_io.h"
#include "pal_interrupt.h"
#include "osal_interrupt.h"
#include "pal.h"
#include "idl.h"
#include "idl_smartcard.h"
#include "idl_smartcard_core.h"
#include "_smartcard.h"
#include <idl_gpio.h>

#define slot_is_valid(slot) \
        (((slot == SC_SLOT1) || (slot == SC_SLOT2)) ? true : false)

#define protocol_is_valid(protocol) \
        (((protocol == SC_T0) || (protocol == SC_T1)) ? true : false)

#define  GEN3_SCARD_IRQ   20
static   pal_dev_id_t m_devkey[] = {SCARD_0, SCARD_1};
static   os_interrupt_t *m_interrupt_handler[] = {NULL, NULL};
extern uint32_t scard_irq;

/*------------------------------------------------------------------------------
 *                                LOCAL FUNCTIONS
 *------------------------------------------------------------------------------
 */

/*------------------------------------------------------------------------------
 *                                GLOBAL FUNCTIONS
 *------------------------------------------------------------------------------
 */

int sc_infc_init(uint8_t slot)
{
        int ret;

        ret = _scard_infc_init(slot);

        return (ret);
}

int sc_infc_deinit(uint8_t slot)
{
        int ret;

        if ( (ret =_scard_infc_deinit(slot)) < 0) {
                return (ret);
        }
        
        if (m_interrupt_handler[slot] != NULL) {
                os_release_interrupt(m_interrupt_handler[slot]);
                m_interrupt_handler[slot] = NULL;
        }

        return (0);
}

int sc_infc_reset(uint8_t slot, sc_reset_t type, sc_vcc_t vcc)
{
        return (_scard_infc_reset(slot, type, vcc));
}

int sc_infc_warm_reset(uint8_t slot)
{
        if ( !slot_is_valid(slot) ) {
                return -1;
        }
	
		return sc_infc_reset(slot, SC_RESET_TYPE_WARM, 0 );
}


int sc_infc_get_slot_info(uint8_t slot, sc_slot_info_t *info)
{
        return (_scard_infc_get_slot_info(slot, info));
}
                
int sc_infc_start_section(uint8_t slot, sc_section_t *section)
{
	 sc_slot_info_t info;
//	 uint32_t rx_length = 0;
	 int status = -1;
 
	 _scard_infc_get_slot_info(slot, &info);

//	 if(info.protocol!=section->protocol){
//		  return (-1);
//	 }

	status = _scard_infc_reset_rx_fifo(slot);

    if (status < 0)
		goto ende;
     status = _scard_infc_reset_tx_fifo(slot);
	 if(status < 0)
		 goto ende;
	 status = _scard_infc_set_protocol(slot, section->protocol);
	 if (status < 0)
		 goto ende;
	 status = _scard_infc_reset(slot, section->reset_type, section->vcc);
	 if (status < 0)
		 goto ende;
	 status = sc_infc_read(slot, section->atr, sizeof(section->atr), &(section->atr_len));
ende:
     return status;
}

int sc_infc_get_rx_length(uint8_t slot, uint32_t *rx_length)
{
        int ret = 0;

        if (slot_is_valid(slot)) {
                *rx_length= _scard_infc_get_rx_length(slot);
        }
        else {
                ret = -1;
        }

        return (ret);
}

int sc_infc_get_tx_length(uint8_t slot, uint32_t *tx_length)
{
        int ret = 0;

        if (slot_is_valid(slot)) {
                *tx_length= _scard_infc_get_rx_length(slot);
        }
        else {
                ret = -1;
        }

        return (ret);
}

int sc_infc_reset_rx_fifo(uint8_t slot)
{
        if ( !slot_is_valid(slot) ) {
                return -1;
        }
        return (_scard_infc_reset_rx_fifo(slot));
}

int sc_infc_reset_tx_fifo(uint8_t slot)
{
        if ( !slot_is_valid(slot) ) {
                return -1;
        }
        return (_scard_infc_reset_tx_fifo(slot));
}

int sc_infc_set_rx_trigger_level(uint8_t slot, uint16_t rx_tl)
{
        if ( !slot_is_valid(slot) ) {
                return -1;
        }
        return (_scard_infc_set_rx_trigger_level(slot, rx_tl));
}

int sc_infc_set_tx_trigger_level(uint8_t slot, uint16_t tx_tl)
{
        if ( !slot_is_valid(slot) ) {
                return -1;
        }
        return (_scard_infc_set_tx_trigger_level(slot, tx_tl));
}

int sc_infc_set_protocol(uint8_t slot, uint32_t protocol)
{
        if ( !slot_is_valid(slot) ) {
                return -1;
        }
        return (_scard_infc_set_protocol(slot, protocol));
}

int sc_infc_read(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_read) 
{

		return  _scard_infc_read(slot, s, nbytes, actual_bytes_read);

}

int sc_infc_write(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_written)
{    
        return _scard_infc_write(slot, s, nbytes, actual_bytes_written);
}

int sc_infc_card_deactivate(uint8_t slot)
{
        return (_scard_infc_card_deactivate(slot));
}

int sc_infc_register_event_handler(uint8_t slot, os_interrupt_handler_t *handler, void *data) 
{
        int ret = 0;

        /* clear all pending interrupts */
        if ( (ret = _scard_infc_clear_interrupt(slot, SC_EVENT_MASK)) < 0) {
                return (ret);
        }

		/* initialize the interrupt handlers (1 per SmartCard interrupt) */
		m_interrupt_handler[slot] = (os_interrupt_t *)OS_ALLOC(sizeof(os_interrupt_t));
        
		if (m_interrupt_handler[slot] == NULL) {
			ret = (-1);
		}

        m_interrupt_handler[slot] = os_acquire_interrupt(scard_irq,
                                                         m_devkey[slot], 
                                                         "scard", 
                                                         (os_interrupt_handler_t *)handler, 
                                                         data );

        if (m_interrupt_handler[slot] == NULL) {
                ret = (-1);
        }

        if ( (ret = _scard_infc_enable_interrupt(slot, (SC_EVENT_CARD_DET))) < 0) {
                return (ret);
        }

        return (ret);
}  

int sc_infc_release_event_handler(uint8_t slot)
{
        int ret;

        /* clear all pending interrupts */
        if ( (ret =_scard_infc_clear_interrupt(slot, SC_EVENT_MASK)) < 0 ) {
                return (ret);
        }

        /* disable all enabled interrupts */
        if ( (ret = _scard_infc_disable_interrupt(slot, SC_EVENT_MASK)) < 0 ) {
                return (ret);
        }

        if (m_interrupt_handler[slot] != NULL) {
                os_release_interrupt(m_interrupt_handler[slot]);
                m_interrupt_handler[slot] = NULL;
        }
        
        return (ret);
}

int sc_infc_clear_event(uint8_t slot, uint32_t event)
{ 
        /* clear the interrupt event */
        return (_scard_infc_clear_interrupt(slot, event));
}

int sc_infc_get_event_status(uint8_t slot, uint32_t *event_status)
{
        /* get the interrupt event status */
        return (_scard_get_interrupt_status(slot, event_status));
}

int sc_infc_card_removal(uint8_t slot)
{
        return (_scard_infc_card_removal(slot));
}

int sc_infc_set_flr(uint8_t slot, uint32_t factor)
{
        return (_scard_infc_set_flr(slot, factor));
}

int sc_infc_set_dlr(uint8_t slot, uint32_t divisor)
{
        return (_scard_infc_set_dlr(slot, divisor));
}

int sc_infc_set_cwt(uint8_t slot, uint32_t cwt)
{
        return (_scard_infc_set_cwt(slot, cwt));
}

int sc_infc_set_bwt(uint8_t slot, uint32_t bwt)
{   
        return (_scard_infc_set_bwt(slot, bwt));
}

int sc_infc_set_tor(uint8_t slot, uint32_t tor)
{   
        return (_scard_infc_set_tor(slot, tor));
}

int sc_infc_set_clk_divisor(uint8_t slot, uint32_t c_div)
{
		return (_scard_infc_set_clk_divisor(slot, c_div));
}

int sc_infc_set_iomode(uint8_t slot, uint32_t iomode)
{
		return (_scard_infc_set_iomode(slot, iomode));
}
/*
 * This routine configure the etu for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param c_div - 0-0xFF 
 * @param divisor - 0-0xFFFF
 * @param factor - 0-0xFF
 * @retval true if etu values are set correctly
 */
int sc_infc_set_etu(uint8_t slot, uint32_t c_div, uint32_t divisor, uint32_t factor)
{
		return (_scard_infc_set_etu(slot, c_div, divisor, factor));
}

int sc_infc_set_egtr(uint8_t slot, uint32_t egtm)
{
		return (_scard_infc_set_egtr(slot, egtm));
}

int sc_infc_set_bgtr(uint8_t slot, uint32_t bgtm)
{
		return (_scard_infc_set_bgtr(slot, bgtm));
}

int sc_infc_adjust_reset_delay(uint8_t slot, uint32_t delay)
{ 
        /* adjust the delay time in reset */
        return (_scard_infc_adjust_reset_delay(slot, delay));
}

int sc_infc_suspend(uint8_t slot)
{
	return (_scard_infc_suspend(slot));
} 

int sc_infc_resume(uint8_t slot)
{
	return (_scard_infc_resume(slot));
}  

int set_scard_alt_fun_pin(uint8_t gpio_num, int val)
{
	pal_soc_name_t soc;
	pal_soc_info_t pal_info;
	
	if(0 != val && 1 != val)
		return -1;
	
	if( PAL_SUCCESS != pal_get_soc_info(&pal_info)) {
		return -1;
	}

	soc	= pal_info.name;

	/* open the gpio device to configure some GPIO pins to function as Smart Card pins. */
	idl_gpio_init();
		
	switch(soc)
  	{
		case SOC_NAME_CE3100:
		case SOC_NAME_CE4100:
			/* set gpio function 19 to 1, then GPIO[7:5] function as Smart Card 0 pins */
			idl_gpio_set_alt_function(19, val);
			/* set gpio function 11 to 1, then GPIO_AUX[11:8] function as Smart Card 1 pins */
			idl_gpio_set_alt_function(11, val);
			break;
		case SOC_NAME_CE4200:
			/* set gpio function GPIO 1 function as Smart Card 0 pins */
			idl_gpio_set_alt_function(1, val);

			/* set gpio function GPIO 2 function as Smart Card 1 pins */
			idl_gpio_set_alt_function(2, val);
			break;
		case SOC_NAME_CE5300:
			/* set gpio function GPIO 33, GPIO_AUX[33, 34, 99, 100, 101, 102] 
		       function as Smart Card 0 pins */
            idl_gpio_set_alt_function(33, val);
           /* set gpio function GPIO 58, GPIO_AUX[58, 59, 60, 61, 62, 63]
               function as Smart Card 1 pins */
           idl_gpio_set_alt_function(58, val);
           break;
		default:
		  return -1;
	
	}


	/* close the gpio devie after configuration*/
	idl_gpio_release();	

	return 0;
}
