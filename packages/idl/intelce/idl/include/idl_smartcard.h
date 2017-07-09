/*
#
# This file is provided under a dual BSD/LGPLv2.1 license.  When using 
# or redistributing this file, you may do so under either license.
#
# LGPL LICENSE SUMMARY
#
# Copyright(c) 2007-2011. Intel Corporation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify 
# it under the terms of version 2.1 of the GNU Lesser General Public 
# License as published by the Free Software Foundation.
#
# This library is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public 
# License along with this library; if not, write to the Free Software 
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
# USA. The full GNU Lesser General Public License is included in this 
# distribution in the file called LICENSE.LGPL.
#
# Contact Information:
#     Intel Corporation
#     2200 Mission College Blvd.
#     Santa Clara, CA  97052
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
 * File Name:       idl_smartcard.h
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 *
 */


/**
 * @weakgroup idl_smartcard SIDL SMARTCARD INTERFACE Functions
 * IDL Interface for General Smartcard Interface. 
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
 * - Open/Close
 * - Configuration
 * - Get/Set routines
 * .
 * <B> Open/Close </B> <br><br>
 * These routines are responsible for opening the device for accessing  the Smartcard Interface and 
 * to free up these resources when they are no longer needed. This API defines two functions 
 * in this category:
 * -# sc_open() - Open the device resources needed to access Smartcard Interface.
 * -# sc_close() - Release the resource opened by sc_open().
 * .
 * <B> Configuration </B><br><br>
 * These routines configure the different capabilities of the Smartcard Interface.
 * -# sc_register_event_handler() - Specifies the function to be called when a some smartcard 
 * interface interrupt occurs.This is secondary interrupt routine.
 * -# sc_release_event_handler()  - Releases the event handler
 *
 * <B> Get/Set routines </B><br><br>
 * These routines get/set the various functionality of smart card interface.
 * -# sc_write() - write a buffer of data to TX FIFO.
 * -# sc_read()  - Read a buffer of data from RX FIFO.
 * -# sc_get_slot_info() - Retrieve information of the in-use smartcard slot
 * -# sc_start_section() - Set protocol for transacions, reset the card and retrieve Answer-To-Reset data sent
 * by the card.
 * -# sc_get_tx_length() - get the current data length status of TX FIFO
 * -# sc_get_rx_length() - get the current data length status of RX FIFO
 * -# sc_reset_rx_fifo() - reset the receive FIFO
 * -# sc_reset_tx_fifo() - reset the transmit FIFO
 * -# sc_wait_for_event() - wait for interrupt event to occurs
 * -# sc_notify_event_done() - notify the smartcard driver that the generated event has been proccessed.
 * -# sc_get_event()     - get the event
 * -# sc_clear_event()   - clear the event
 * -# sc_deactivate()    - deactivate the card from smart card interface
 * -# sc_card_removal()  - handle unexpected card removal
 * 
 */
#ifndef _IDL_SMARTCARD_H_
#define _IDL_SMARTCARD_H_
#ifdef __cplusplus
extern "C" {
#endif


#include <linux/ioctl.h>
#include "idl.h"
#include "osal_thread.h"
#include "osal_event.h"
#include "osal_interrupt.h"
#include "osal_sched.h"


/** @defgroup idl_smartcard_defs IDL SMARTCARD Definitions */
/** @ingroup idl_smartcard_defs */

/*@{*/

/* maximun slots number supported */
#define SC_MAX_SLOTS_SUPPORTED   2

/* slot information */
#define SC_SLOT1                 0
#define SC_SLOT2                 1

/* reader supported protocol type */
#define SC_T0                    0x00000001
#define SC_T1                    0x00000002

/* slot info status */
#define SC_CARD_NO_CARD_INSERTED        0
#define SC_CARD_INSERTED_NOT_POWERED_UP 1
#define SC_CARD_POWERED_UP              2


/*error code for smartcard*/  
#define EOVRN             	155
#define EPARITY           	156
#define ET0					157
#define EFRAME            	158

/* 
 * This enumeration defines the different Smartcard Interface interrupt types. 
 */
#define SC_EVENT_OVRN      0x0001    /* Receive data overrun interrupt */
#define SC_EVENT_PERR      0x0002    /* Parity error interrupt */
#define SC_EVENT_T0ERR     0x0004    /* T=0 error interrupt */
#define SC_EVENT_FRAMERR   0x0008    /* Framing error interrupt */
#define SC_EVENT_TIMEO     0x0010    /* Receive timeout interrupt */
#define SC_EVENT_CWT	   0x0020    /* Character waiting time interrupt */
#define SC_EVENT_BWT       0x0040    /* Block waiting time interrupt */
#define SC_EVENT_RDR       0x0100    /* Receive Data Ready interrupt */
#define SC_EVENT_TDR       0x0200    /* Transmit data refill interrupt */
#define SC_EVENT_CARD_DET  0x0400    /* SmartCard detection interrupt */
#define SC_EVENT_FIFO_TIME 0x2000    /* FIFO_RX interrupt */
#define SC_EVENT_FIFO_RX   0x4000    /* FIFO_TIME interrupt */

/* Smartcard interface valid interrupt mask */
#define SC_EVENT_MASK  (SC_EVENT_CARD_DET|SC_EVENT_TIMEO|SC_EVENT_TDR|SC_EVENT_CWT|SC_EVENT_BWT)
/* Maximum trigger level for rx fifo */
#define MAX_RX_TRIGGER_LEVEL 260
/* Maximum trigger level for tx fifo */
#define MAX_TX_TRIGGER_LEVEL 260
/*! Fifo size for rx fifo */
#define RX_FIFO_SIZE 260
/*! Fifo size for rx fifo */
#define TX_FIFO_SIZE 260
	
/* event type */
typedef uint32_t sc_event_t;

#define SC_LSR_OVRN      0x0001    /* Receive data overrun interrupt */
#define SC_LSR_PERR      0x0002    /* Parity error interrupt */
#define SC_LSR_T0ERR     0x0004    /* T=0 error interrupt */
#define SC_LSR_FRAMERR   0x0008    /* Framing error interrupt */
#define SC_LSR_TIMEO     0x0010    /* Receive timeout interrupt */
#define SC_LSR_CWT	     0x0020    /* Character waiting time interrupt */
#define SC_LSR_BWT       0x0040    /* Block waiting time interrupt */


/* card voltage level supported */
typedef enum
{
        SC_VCC_SEL_0 = 0,
        SC_VCC_SEL_3_3 = 2,
        SC_VCC_SEL_5,
} sc_vcc_t;

/* reset types supported */
typedef enum
{
        SC_RESET_TYPE_WARM = 1,
        SC_RESET_TYPE_COLD,
} sc_reset_t;

/* data structure used to get slot info */
typedef struct
{
        uint8_t protocol;
        uint8_t status;
} sc_slot_info_t;

/* data structure used for sc_start_section */
typedef struct
{
        uint8_t  protocol;         /* card type selected for operation: SC_T0 or SC_T1 */ 
        uint8_t  vcc;              /* card voltage */
        uint32_t atr_len;          /* length of the ATR */
        uint32_t reset_type;       /* reset type */
        uint8_t  atr[128];         /* ATR string */
} sc_section_t;

/*@}*/

#define MAX_PARAMS 6
typedef struct
{
        uint32_t p_params[MAX_PARAMS]; /* used for both input/output */
} sc_ioctl_args_t;


/* IOCTL defintions */
/* See /usr/src/linux/Documentation/ioctl-number.txt */
#define SC_IOCTL_MAGIC                   0xD2

#define SC_IOCTL_START_SECTION           _IO(SC_IOCTL_MAGIC,  1)
#define SC_IOCTL_GET_SLOT_INFO	         _IO(SC_IOCTL_MAGIC,  2)
#define SC_IOCTL_READ                    _IO(SC_IOCTL_MAGIC,  3)
#define SC_IOCTL_WRITE                   _IO(SC_IOCTL_MAGIC,  4)
#define SC_IOCTL_DEACTIVATE              _IO(SC_IOCTL_MAGIC,  5)
#define SC_IOCTL_GET_RX_LENGTH           _IO(SC_IOCTL_MAGIC,  6)
#define SC_IOCTL_GET_TX_LENGTH           _IO(SC_IOCTL_MAGIC,  7)
#define SC_IOCTL_RESET_RXFIFO            _IO(SC_IOCTL_MAGIC,  8)
#define SC_IOCTL_RESET_TXFIFO            _IO(SC_IOCTL_MAGIC,  9)
#define SC_IOCTL_REGISTER_EVENT_HANDLER  _IO(SC_IOCTL_MAGIC, 10)
#define SC_IOCTL_RELEASE_EVENT_HANDLER   _IO(SC_IOCTL_MAGIC, 11)
#define SC_IOCTL_WAIT_FOR_EVENT          _IO(SC_IOCTL_MAGIC, 12)
#define SC_IOCTL_NOTIFY_EVENT_DONE       _IO(SC_IOCTL_MAGIC, 13)
#define SC_IOCTL_GET_EVENT_STATUS        _IO(SC_IOCTL_MAGIC, 14)
#define SC_IOCTL_CLEAR_EVENT             _IO(SC_IOCTL_MAGIC, 15)
#define SC_IOCTL_RELEASE_EVENT           _IO(SC_IOCTL_MAGIC, 16)
#define SC_IOCTL_CARD_REMOVAL            _IO(SC_IOCTL_MAGIC, 17)

#define SC_IOCTL_WARM_RESET              _IO(SC_IOCTL_MAGIC, 18)
#define SC_IOCTL_SET_IO_MODE             _IO(SC_IOCTL_MAGIC, 19)
#define SC_IOCTL_SET_CWTR            	 _IO(SC_IOCTL_MAGIC, 20)
#define SC_IOCTL_SET_BWTR            	 _IO(SC_IOCTL_MAGIC, 21)
#define SC_IOCTL_SET_TOR            	 _IO(SC_IOCTL_MAGIC, 22)
#define SC_IOCTL_SET_ETU            	 _IO(SC_IOCTL_MAGIC, 23)
#define SC_IOCTL_SET_CLOCK            	 _IO(SC_IOCTL_MAGIC, 24)
#define SC_IOCTL_SET_BGTR            	 _IO(SC_IOCTL_MAGIC, 25)
#define SC_IOCTL_SET_EGTR            	 _IO(SC_IOCTL_MAGIC, 26)
#define SC_IOCTL_BLOCK_READ            	 _IO(SC_IOCTL_MAGIC, 27)
#define SC_IOCTL_BLOCK_WRITE             _IO(SC_IOCTL_MAGIC, 28)
#define SC_IOCTL_ADJUST_RESET_DELAY      _IO(SC_IOCTL_MAGIC, 29)
#define SC_IOCTL_SET_PROTOCOL      _IO(SC_IOCTL_MAGIC, 30)

typedef enum {
	DIRECT_CONVENTION,
	INVERSE_CONVENTION
} io_mode_t;


/** @weakgroup idl_smartcard IDL SMARTCARD Functions */
/** ingroup idl_smartcard */
/*@{*/

/** 
 * This function opens a SMARTCARD device. This function must be called before any other
 * SmartCard's API. If successful, this function will return a file descriptor of the
 * opened device. Otherwise, it will return -1.
 * @param [in] slot - SMARTCARD slot number (SC_SLOT1 or SC_SLOT2)
 * @retval fd - if successful, sc_open() will return the file descriptor of 
 * the opened device.
 * @retval -1 if failed
 */
int sc_open(uint8_t slot);

/** 
 * This function closes the opened SMARTCARD device . This function must be the last 
 * function to be called to end using the SMARTCARD device on a particular SMARTCARD slot.
 * @param [in] fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_close(int fd);

/** 
 * This function first notify the smartcard device the protocol (SC_T0 or SC_T1) it want to use
 * for upcoming transactions, reset the card and retrieve Answer-To-Reset data sent from the card.
 * This function shall be call before any transaction is made. 
 * @param [in]  fd - file descriptor returned from sc_open() function call
 * @param [in]  section->protocol - protocol (SC_T0 or SC_T1) selected for transactions
 * @param [out] section->atr_len  - length of the data buffer returned from Answer-To-Reset operation
 * @param [out] section->atr      - buffer containing data returned from Answer-To-Reset operation
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_start_section(int fd, sc_section_t *section);

/**
 * This function will get information/status of of the current in-used smartcard slot.
 * @param [in] fd - file descriptor returned from sc_open() function call
 * @param [out] info->protocol - protocol (SC_T0 or SC_T1) used for transactions
 * @param [out] info->status   - SC_CARD_NO_CARD_INSERTED if no card is inserted,
 *                               SC_CARD_INSERTED_NOT_POWERED_UP if card's inserted but not powered up,
 *                               SC_CARD_POWERED_UP if card is inserted and powered up
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_get_slot_info(int fd, sc_slot_info_t *info);

/** 
 * This function deactivate the smartcard.
 * @param [in] fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_deactivate(int fd);

/** 
 * This function handles the unexpected card removal.
 * @param [in] fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_card_removal(int fd);

/**
 * This function reads data from receive FIFO.
 * @param [in]  fd     - file descriptor returned from sc_open call
 * @param [out] *s     - buffer containing read data
 * @param [in]  nbytes - number of bytes to be read
 * @retval non-negative-value indicating number of bytes read.
 * @retval -1 if failed
 */
int sc_read(int fd, uint8_t *s, uint32_t nbytes);

/**
 * This function write commands and posibly data to the transmit FIFO.
 * @param [in] fd     - file descriptor returned from sc_open call
 * @param [in] *s     - buffer that contains data to be written
 * @param [in] nbytes - number of bytes to be written
 * @retval non-negative-value indicating number of bytes written.
 * @retval -1 if failed
 */
int sc_write(int fd, uint8_t *s, uint32_t nbytes);

/** 
 * This function is used to find out the number of bytes in the RX buffer.
 * @param [in]  fd - file descriptor returned from sc_open call
 * @param [out] *rx_length - number of bytes in the RX buffer
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_get_rx_length(int fd, uint32_t *rx_length);

/** 
 * This function is used to find out the number of bytes in the TX buffer currently available for transmission.
 * @param [in]  fd - file descriptor returned from sc_open call
 * @param [out] *tx_length - number of bytes in the TX buffer currently available for transmission
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_get_tx_length(int fd, uint32_t *tx_length);

/** 
 * This function is used to reset the receive FIFO.
 * @param [in]  fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_reset_rx_fifo(int fd);

/** 
 * This function is used to reset the transmit FIFO.
 * @param [in]  fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_reset_tx_fifo(int fd);

/**
 * This function registers interrupt handler for the specific smartcard slot.
 * @param [in] fd       - file descriptor returned from sc_open call
 * @param [in] *handler - the function to be called when the interrupt is triggered. A NULL 
 *                        pointer is acceptable if the user does not want the sc_register_event_handler
 *                        to process the event when the interrupt is triggered.
 * @param [in] *data    - a void pointer to be passed to the interrupt handler when the interrupt is 
                          triggered. A NULL pointer is acceptable if the callback handler equals to NULL.
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_register_event_handler(int fd, void *handler, void *data);

/**
 * This function releases interrupt handler for the specific smartcard slot.
 * @param [in] fd       - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_release_event_handler(int fd);

/**
 * This function waits and notifies the application when a new interrupt event occurs.
 * @param [in]  fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_wait_for_event(int fd);

/**
 * This function notifies the kernel driver the interrupt event has been processed. The kernel driver 
 * then will clear out the resources and interrupt event.
 * @param [in] fd    - file descriptor returned from sc_open call
 * @param [in] event - interrupt event status bits mask 
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_notify_event_done(int fd, sc_event_t event);

/**
 * This function returns the value of the interrupt event status bits for the specified smartcard slot. 
 * @param [in]  fd     - file descriptor returned from sc_open call
 * @param [out] *event - value of the interrupt event status for the specified smartcard slot
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_get_event(int fd, sc_event_t *event);

/**
 * This function clears the interrupt event status bits for the specified smartcard slot.
 * This function is optional. sc_notify_event_done can also take care of clearing the interrupt 
 * event.
 * @param [in] fd    - file descriptor returned from sc_open call
 * @param [in] event - interrupt event status bits mask 
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_clear_event(int fd, sc_event_t event);

/** 
 * This function is used to do warm reset for the smartcard interface.
 * @param [in]  fd - file descriptor returned from sc_open call
 * @retval 0 if successful
 * @retval -1 if failed
 */
int sc_warm_reset(int fd);

/**
 * This function reads data from receive FIFO in blocking mode.
 * @param [in]  fd     - file descriptor returned from sc_open call
 * @param [out] *s     - buffer containing read data
 * @param [in]  nbytes - number of bytes to be read
 * @retval non-negative-value indicating number of bytes read.
 * @retval -1 if failed
 */
int sc_block_read(int fd, uint8_t *s, uint32_t nbytes);

/**
 * This function write commands and posibly data to the transmit FIFO in blocking mode.
 * @param [in] fd     - file descriptor returned from sc_open call
 * @param [in] *s     - buffer that contains data to be written
 * @param [in] nbytes - number of bytes to be written
 * @retval non-negative-value indicating number of bytes written.
 * @retval -1 if failed
 */
int sc_block_write(int fd, uint8_t *s, uint32_t nbytes);

/**
 * This function sets the I/O mode to direct or inverted byte format;
 * @param [in] fd     - file descriptor returned from sc_open call
 * @param [in] iomode - I/O mode to be set 
 * @retval negative-value indicating I/O mode setting failed.
 * @retval 0 if successful
 */
int sc_set_io_mode(int fd, uint32_t iomode);

/**
 * This function sets the timeout values that end up in the character waiting time registers;
 * @param [in] fd     - file descriptor returned from sc_open call
 * @param [in] cwtr - character waiting time to be set 
 * @retval negative-value indicating character waiting time setting failed.
 * @retval 0 if successful
 */

int sc_set_cwtr (int fd, uint32_t cwtr);

/**
 * This function sets the timeout values that end up in the block waiting time registers; 
 * @param [in] fd     - file descriptor returned from sc_open call
 * @param [in] cwtr - block waiting time to be set 
 * @retval negative-value indicating block waiting time setting failed.
 * @retval 0 if successful
 */
int sc_set_bwtr (int fd, uint32_t bwtr);


/**
 * This function sets the timeout values that end up in the time out registers;
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] tor - time out value to be set 
 * @retval negative-value indicating time out setting failed.
 * @retval 0 if successful
 */
int sc_set_tor (int fd, uint32_t time);


/**
 * This API sets the baud rate/ETU;
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] c_div - time out value to be set 
 * @param [in] divisor - divisor value to be set 
 * @param [in] factor - factor value to be set 
 * @retval negative-value indicating time out setting failed.
 * @retval 0 if successful
 */
int sc_set_etu (int fd, uint32_t c_div, uint32_t divisor, uint32_t factor);

/**
 * This fucntion sets the clock frequency;
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] clock - clock frequency to be set 
 * @retval negative-value indicating clock frequency setting failed.
 * @retval 0 if successful
 */
int sc_set_clock (int fd, uint32_t clock);


/** 
 * This API sets the block guard time;
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] bgtime - block guard time value to be set 
 * @retval negative-value indicating block guard time setting failed.
 * @retval 0 if successful
 */
int sc_set_bgtime (int fd, uint32_t bgtime);


/** 
 * This function sets the extra guard time
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] egtime - extra guard timebe set 
 * @retval negative-value indicating  extra guard time setting failed.
 * @retval 0 if successful
 */
int sc_set_egtime (int fd, uint32_t egtime);


/**
 * This function sets the reset delay time
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] delay - reset delay time to be set 
 * @retval negative-value indicating reset delay time setting failed.
 * @retval 0 if successful
 */
int sc_adjust_reset_delay(int fd, uint32_t delay);

/**
 * This function sets the smart card protocol
 * @param [in] fd  - file descriptor returned from sc_open call
 * @param [in] protocol - smart card protocol 
 * @retval negative-value indicating reset delay time setting failed.
 * @retval 0 if successful
 */
int sc_set_protocol(int fd, uint32_t protocol);




#ifdef __cplusplus
}
#endif

#endif


