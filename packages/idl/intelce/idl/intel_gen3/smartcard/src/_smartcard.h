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
 * File Name:       _smartcard.h
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 *
 */


#ifndef __SMARTCARD_H__
#define __SMARTCARD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "idl.h"
#include "idl_smartcard.h"

//define HARDCODE_BAR, will use the hardcode base address, otherwise, will get base address from pal
//#define HARDCODE_BAR

#define _BASE_REG_PA_USIM_0        0xDFFE0800
#define _BASE_REG_PA_USIM_1        0xDFFE0900

#define _SCARD_INFC_CCR_SCARD_INSERTED (1 << 3)

/* SMARTCARD INTERFACE Bit definitions for Transmit Holding Register */
#define _SCARD_INFC_THR_TX_ENABLE      (1 << 31)

/* SMARTCARD INTERFACE Bit definitions for Line Control Register */
#define _SCARD_INFC_LCR_TX_T1          (1 << 4)	/* Transmission Protocol */
#define _SCARD_INFC_LCR_RX_T1          (1 << 3)	/* Receiver Protocol */

/* SMARTCARD INTERFACE bit definitions for Line Status Register */
#define _SCARD_INFC_LSR_TX_WORKING     (1 << 13) /* Transmission Working */
#define _SCARD_INFC_LSR_RX_EMPTY_N     (1 << 12) /* Receive FIFO Empty */

/* SMARTCARD INTERFACE Bit definitions for FIFO Control Register */
#define _SCARD_INFC_FCR_TX_HOLD        (1 << 30)  /* TX_HOLD */

/*  
 * Smartcard Interface Register definitions
 */
typedef struct
{ 
        uint32_t volatile    rbr;       /* Receive Buffer register */
        uint32_t volatile    thr;       /* Transmit Holding register */
        uint32_t volatile    ier;       /* Interrupt Enable register */
        uint32_t volatile    iir;       /* Interrupt Indetification register */
        uint32_t volatile    fcr;       /* FIFO Control register */
        uint32_t volatile    fsr;       /* FIFO Status register */
        uint32_t volatile    ecr;       /* Error Control register */
        uint32_t volatile    lcr;       /* Line Control register */
        uint32_t volatile    ccr;       /* Card Control register */
        uint32_t volatile    lsr;       /* Line Status register */
        uint32_t volatile    egtr;      /* Extra Guard Time register */
        uint32_t volatile    bgtr;      /* Baurd Guard Time register */
        uint32_t volatile    tor;       /* Time Out register */
        uint32_t volatile    clkr;      /* Clock Control Register */
        uint32_t volatile    dlr;       /* Divisor Latch register */
        uint32_t volatile    flr;       /* Factor Latch register */
        uint32_t volatile    cwtr;      /* Character waiting Time register */
        uint32_t volatile    bwtr;      /* Block Waiting Time register */
        uint32_t volatile    dds_rate;  /* Block Waiting Time register */
} _scard_infc_reg_t, *_pscard_infc_reg_t;



/*
 * This function initializes the smartcard interface. This is the first function 
 * that should be called, it reset all the smartcard interface register to HW 
 * reset values.
 */
int _scard_infc_init(uint8_t slot);
 
 /*
 * This function frees any memory associated with the smartcard interface. 
 * This functions should be called last
  */
int _scard_infc_deinit(uint8_t slot);
 
/*
 * This routine will get the current number of bytes in receive buffer 
 */
int _scard_infc_get_rx_length(uint8_t slot);
 
/*
 * This routine will get the current number of bytes in transmit buffer 
 */
int _scard_infc_get_tx_length(uint8_t slot);
 
int _scard_infc_reset_rx_fifo(uint8_t slot);

int _scard_infc_reset_tx_fifo(uint8_t slot);

int _scard_infc_set_rx_trigger_level(uint8_t slot, uint16_t rx_tl);

int _scard_infc_set_tx_trigger_level(uint8_t slot, uint16_t tx_tl);

/*
 * This routine will set the protocols for the transmitter/receiver
 * transmitter and receiver are programmed with same protocol type
 */
int _scard_infc_set_protocol(uint8_t slot, uint8_t protocol);

/*
 * This routine will detect the card at smart card interface.
 */
int _scard_infc_get_slot_info(uint8_t slot, sc_slot_info_t *info);

/*
 * This routine will warm reset the card
 */
int _scard_infc_reset(uint8_t slot, sc_reset_t type, sc_vcc_t vcc);

/*
 * This routine will deactivate the card
 */
int _scard_infc_card_deactivate(uint8_t slot);

/*
 * This routine will enable the interrupts for smart card interface
*/
int _scard_infc_enable_interrupt(uint8_t slot, uint32_t mask);

/*
 * This routine will disable the interrupts for smart card interface
 */
int _scard_infc_disable_interrupt(uint8_t slot, uint32_t mask);

/*
 * This routine will clear the interrupt for smart card interface by clearing
 * the status bits
 */
int _scard_infc_clear_interrupt(uint8_t slot, uint32_t mask);

int _scard_get_interrupt_status(uint8_t slot, uint32_t *status);

int _scard_infc_set_card_vcc(uint8_t slot, sc_vcc_t vcc);

/*
 * This routine will read a byte from smartcard interface RX FIFO
 * and activate it
 */
int _scard_infc_read(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_read);
/*
 * This routine will read a byte from smartcard interface RX FIFO
 * and activate it
 */
/* int _scard_infc_write(uint8_t slot, uint8_t byte); */
int _scard_infc_write(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_written);

int _scard_infc_set_clk_divisor(uint8_t slot, uint32_t c_div);

/*
 * This routine configure the etu for smartcard interface
 * @param smartcard_id - 0,1 ( smartcard id)
 * @param c_div - 0-0xFF 
 * @param D - 0-0xFFFF
 * @param F - 0-0xFF
 * @retval true if etu values are set correctly
 */
int _scard_infc_set_etu(uint8_t slot, uint32_t c_div, uint32_t divisor, uint32_t factor);

/*
 * This routine configure the baud factor for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param F - 0-0xFF
 * @retval true if baud factor values are set correctly
 */
int _scard_infc_set_flr(uint8_t slot, uint32_t factor);

/*
 * This routine configure the baud divisor for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param F - 0-0xFFFF
 * @retval true if baud divisor values are set correctly
 */
int _scard_infc_set_dlr(uint8_t slot, uint32_t divisor);

/*
* This routine configure the character waiting time for smartcard interface
* @param id - 0,1 ( smartcard id)
* @param D - 0-0xFFFF
* @retval true if character waiting time values are set correctly
*/
int _scard_infc_set_cwt(uint8_t slot, uint32_t cwt);

/*
 * This routine configure the block waiting time for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param D - 0-0xFFFF
 * @retval true if block waiting time values are set correctly
 */
int _scard_infc_set_bwt(uint8_t slot, uint32_t bwt);

/*
 * This routine will reset and flush the TX FIFO entries
 * @param smartcard_id - 0,1 ( smartcard id)
 * @retval true if TX FIFO reset correctly
 */
int _scard_infc_reset_tx_fifo(uint8_t slot);

/*
 * This routine will reset and flush the RX FIFO entries
 * @param smartcard_id - 0,1 ( smartcard id)
 * @retval true if RX FIFO reset correctly
 */
int _scard_infc_reset_rx_fifo(uint8_t slot);

/*
 * This routine will perform cold reset to the card connected to smartcard interface
 * and activate it
 * @param smartcard_id - 0,1 ( smartcard id)
 * @retval true if RX FIFO reset correctly
 */
int _scard_infc_card_removal(uint8_t slot);

/*
 * This routine configure the character waiting time for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param D - 0-0xFFFF
 * @retval IDL_SUCCESS if character waiting time values are set correctly
 */
int _scard_infc_set_cwt(uint8_t slot, uint32_t cwt);


/*
 * This routine configure the block waiting time for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param data - 0-0xFFFF
 * @retval IDL_SUCCESS if block waiting time values are set correctly
 */
int _scard_infc_set_bwt(uint8_t slot, uint32_t bwt);

/*
 * This routine configure the time out register for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param data - 0-0xFFFF
 * @retval IDL_SUCCESS if block waiting time values are set correctly
 */
int _scard_infc_set_tor(uint8_t slot, uint32_t tor);

/*
 * This routine configure the io mode for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param data - 0-0x1
 * @retval IDL_SUCCESS if block waiting time values are set correctly
 */
int _scard_infc_set_iomode(uint8_t slot, uint32_t iomode);

int _scard_infc_set_egtr(uint8_t slot, uint32_t egtm);


int _scard_infc_set_bgtr(uint8_t slot, uint32_t bgt);

/*
 * This routine configure the GPIO for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @retval true if gpio are programmed corretly
 */
int _scard_infc_set_gpio(uint8_t scard_id);


/*
 * This routine configure the etu for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param c_div - 0-0xFF 
 * @param D - 0-0xFFFF
 * @param F - 0-0xFF
 * @retval true if etu values are set correctly
 */
int _scard_infc_set_etu(uint8_t slot, uint32_t c_div, uint32_t divisor, uint32_t factor);

int _scard_infc_adjust_reset_delay(uint8_t slot, uint32_t delay);

void _scard_dump_registers(uint8_t slot);

/* smartcard suspend function */
int _scard_infc_suspend(uint8_t slot);
 
/* smartcard resume function */
int _scard_infc_resume(uint8_t slot);


#ifdef __cplusplus
}
#endif

#endif /* __SMARTCARD_H__ */
