/*
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

/*------------------------------------------------------------------------------
 * File Name: idl_smartcard.c
 *------------------------------------------------------------------------------
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef IDL_DRIVER
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>

#include <osal_event.h>
#include <osal_thread.h>

#include <idl.h>
#include <idl_smartcard.h>


#define slot_is_valid(slot) \
        (((slot == SC_SLOT1) || (slot == SC_SLOT2)) ? true : false)

#define protocol_is_valid(protocol) \
        (((protocol == SC_T0) || (protocol == SC_T1)) ? true : false)

typedef struct 
{
        int fd;
        int slot;
} sc_fd_table_t;

typedef void (sc_handler_t)(void *data);

typedef struct
{
	int          fd;
	bool         exit;
	sc_handler_t *handler;
	void         *data;
} thread_data_t;

static sc_fd_table_t m_fd_table[] = { {-1, 0}, {-1, 0} };
static pthread_t     m_thread_handle[SC_MAX_SLOTS_SUPPORTED];
static bool          m_thread_created[] = {false, false};  
static thread_data_t m_td[SC_MAX_SLOTS_SUPPORTED];


static int get_slot_number(int fd)
{
        int i;
        int slot = -1;

        for (i = 0; i < SC_MAX_SLOTS_SUPPORTED; i++) {
                if (m_fd_table[i].fd == fd) {
                        slot = m_fd_table[i].slot;
                }
        }

        return (slot);
}

static void *irq_handler(void *arg)
{
	thread_data_t *td = (thread_data_t *)arg;
        sc_event_t event;
		
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	
	while (1) {
		/* this blocks until an interrupt is detected */
		sc_wait_for_event(td->fd);
	
                /* get events */
                sc_get_event(td->fd, &event);

		/*
		 * we'll need to check to see if we are exiting the 
		 * thread - we don't want to trigger a false interrupt. 
		 */
		if (td->exit) {
			/* interrupt handling complete */	
			sc_notify_event_done(td->fd, event);
			break;	/* exit while loop */
		}

		/* 
		 * ok, an interrupt is detected...
		 * call user-specified callback
		 */
		if (td->handler != NULL) {
			td->handler(td->data);
		}
	
		/* interrupt handling complete */
		sc_notify_event_done(td->fd, event);
	}

	return arg;
}

/*------------------------------------------------------------------------------
 * sc_open
 *------------------------------------------------------------------------------
 */

int 
sc_open(uint8_t slot)
{
        char devname[20];
        int  fd = -1;
        
		if ( !slot_is_valid(slot) ) {
                return (fd);
        }

        sprintf(devname, "/dev/scard%d", slot);
        fd = open(devname, O_RDWR);
       
        /* save slot and descriptor info interally for later use */
        if (fd > 0) {
                m_fd_table[slot].fd   = fd;
                m_fd_table[slot].slot = slot;
        }
        
        return (fd);
}

/*------------------------------------------------------------------------------
 * sc_close
 *------------------------------------------------------------------------------
 */

int
sc_close(int fd)
{        
        int slot = -1;

        if (fd < 0) {
                return (-1);
        }

        slot = get_slot_number(fd);        

        sc_reset_tx_fifo(fd);
        sc_reset_rx_fifo(fd);

        close(fd);
        

        return (0);
}

/*------------------------------------------------------------------------------
 * sc_start_section
 *------------------------------------------------------------------------------
 */

int 
sc_start_section(int fd, sc_section_t *section)
{
        sc_ioctl_args_t ioctl_args;
        int             slot; 
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* start section */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) section;
                
                ret = ioctl(fd, SC_IOCTL_START_SECTION, &ioctl_args);
				if(ret == -1)
					ret = -errno;

        }

        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_get_slot_info
 *------------------------------------------------------------------------------
 */

int
sc_get_slot_info(int fd, sc_slot_info_t *info)
{
        sc_ioctl_args_t ioctl_args;
        int             slot; 
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* get slot info */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) info;
                
                ret = ioctl(fd, SC_IOCTL_GET_SLOT_INFO, &ioctl_args);
        }
        
        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_get_rx_length
 *------------------------------------------------------------------------------
 */

int
sc_get_rx_length(int fd, uint32_t *rx_length)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        *rx_length = 0;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* get rx_length */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) rx_length;
                
                ret = ioctl(fd, SC_IOCTL_GET_RX_LENGTH, &ioctl_args);
        }
        
        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_get_tx_length
 *------------------------------------------------------------------------------
 */

int
sc_get_tx_length(int fd, uint32_t *tx_length)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        *tx_length = 0;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* get tx_length */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) tx_length;
                
                ret = ioctl(fd, SC_IOCTL_GET_RX_LENGTH, &ioctl_args);
        }

        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_reset_rx_fifo
 *------------------------------------------------------------------------------
 */

int
sc_reset_rx_fifo(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* reset rx fifo */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                
                ret = ioctl(fd, SC_IOCTL_RESET_RXFIFO, &ioctl_args);
        }

        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_reset_tx_fifo
 *------------------------------------------------------------------------------
 */

int
sc_reset_tx_fifo(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* reset tx fifo */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                
                ret = ioctl(fd, SC_IOCTL_RESET_TXFIFO, &ioctl_args);
        }

        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_deactivate
 *------------------------------------------------------------------------------
 */
int
sc_deactivate(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* set protocol */
                ioctl_args.p_params[0] = (uint32_t) &slot;

                ret = ioctl(fd, SC_IOCTL_DEACTIVATE, &ioctl_args);
        }
        
        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_card_removal
 *------------------------------------------------------------------------------
 */
int
sc_card_removal(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* set protocol */
                ioctl_args.p_params[0] = (uint32_t) &slot;

                ret = ioctl(fd, SC_IOCTL_CARD_REMOVAL, &ioctl_args);
        }
        
        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_register_event_handler
 *------------------------------------------------------------------------------
 */
int
sc_register_event_handler(int fd, void *handler, void *data)
{
        pthread_attr_t         attr;
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {                
                ioctl_args.p_params[0] = (uint32_t) &slot;
	
                if ( (ret = ioctl(fd, SC_IOCTL_REGISTER_EVENT_HANDLER, &ioctl_args)) < 0) {
                        return (ret);
                }

                m_td[slot].fd      = fd;
                m_td[slot].exit    = true; 
                m_td[slot].handler = handler;
                m_td[slot].data    = data;
	
                if (handler != NULL) {
                        pthread_attr_init(&attr);
                        m_td[slot].exit = false; 
                        if (pthread_create(&m_thread_handle[slot], 
                                           &attr, 
                                           &irq_handler, 
                                           &m_td[slot]) != 0)
                        {
                                m_thread_created[slot] = false;
                                ret = (-1);
                        }
                        else {
                                m_thread_created[slot] = true;
                                ret = 0;
                        } 
                }
        }

        return (0);
}

/*------------------------------------------------------------------------------
 * sc_release_event_handler
 *------------------------------------------------------------------------------
 */
int
sc_release_event_handler(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {                  
                ioctl_args.p_params[0] = (uint32_t) &slot;
	
                ret = ioctl(fd, SC_IOCTL_RELEASE_EVENT_HANDLER, &ioctl_args);

		if (m_td[slot].handler != NULL) {
			m_td[slot].handler = NULL;
			m_td[slot].exit = true;						
		}	
		
		if(m_thread_created[slot] == true && m_thread_handle[slot] != 0) {
			pthread_cancel(m_thread_handle[slot]);
			pthread_join(m_thread_handle[slot], NULL);
			m_thread_created[slot] = false;
		}
        }
	
        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_wait_for_event
 *------------------------------------------------------------------------------
 */

int
sc_wait_for_event(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
	
                ret = ioctl(fd, SC_IOCTL_WAIT_FOR_EVENT, &ioctl_args);
        }

        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_notify_event_done
 *------------------------------------------------------------------------------
 */

int
sc_notify_event_done(int fd, sc_event_t event_mask)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &event_mask;

                ret = ioctl(fd, SC_IOCTL_NOTIFY_EVENT_DONE, &ioctl_args);
        }

        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_get_event_status
 *------------------------------------------------------------------------------
 */

int
sc_get_event(int fd, sc_event_t *event)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) event;
        
                ret = ioctl(fd, SC_IOCTL_GET_EVENT_STATUS, &ioctl_args);
        }
        
        return (ret);
}
 
/*------------------------------------------------------------------------------
 * sc_clear_event
 *------------------------------------------------------------------------------
 */

int
sc_clear_event(int fd, sc_event_t event)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                errno = EBADF;
				return ret;
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &event;
        
                ret = ioctl(fd, SC_IOCTL_CLEAR_EVENT, &ioctl_args);
	}
        
	return (ret);
}

/*------------------------------------------------------------------------------
 * sc_read
 *------------------------------------------------------------------------------
 */

int
sc_read(int fd, uint8_t *s, uint32_t nbytes)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;
        int             bytes_read = 0;

        if (fd < 0) {
		  		errno = EBADF;
                return ret;
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) s;
                ioctl_args.p_params[2] = (uint32_t) &nbytes;
                ioctl_args.p_params[3] = (uint32_t) &bytes_read;
                
                ret = ioctl(fd, SC_IOCTL_READ, &ioctl_args);
        }
		if (ret < 0) return -errno;

        return (bytes_read);
}

/*------------------------------------------------------------------------------
 * sc_write
 *------------------------------------------------------------------------------
 */

int
sc_write(int fd, uint8_t *s, uint32_t nbytes)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;
        int             bytes_written = 0;

        if (fd < 0) {
                errno = EBADF;
				return ret;
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) s;
                ioctl_args.p_params[2] = (uint32_t) &nbytes;
                ioctl_args.p_params[3] = (uint32_t) &bytes_written;

                ret = ioctl(fd, SC_IOCTL_WRITE, &ioctl_args);
        }
		if (ret < 0) return ret;

        return (bytes_written);
}

/*This API does warm reset to the smartcard.*/
int sc_warm_reset(int fd)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                errno = EBADF;
				return ret;
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                /* reset tx fifo */
                ioctl_args.p_params[0] = (uint32_t) &slot;
                
                ret = ioctl(fd, SC_IOCTL_WARM_RESET, &ioctl_args);
        }

        return (ret);
}

/*This API sets the I/O mode to direct or inverted byte format;*/
int sc_set_io_mode(int fd, uint32_t iomode)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &iomode;
        
                ret = ioctl(fd, SC_IOCTL_SET_IO_MODE, &ioctl_args);
        }
        
        return (ret);


}
/*An API to set the timeout values that end up in the character waiting time registers;*/
int sc_set_cwtr (int fd, uint32_t cwtr)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &cwtr;
        
                ret = ioctl(fd, SC_IOCTL_SET_CWTR, &ioctl_args);
        }
        
        return (ret);
}

/*An API to set the timeout values that end up in the block waiting time registers; */
int sc_set_bwtr (int fd, uint32_t bwtr)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &bwtr;
        
                ret = ioctl(fd, SC_IOCTL_SET_BWTR, &ioctl_args);
        }
        
        return (ret);
}


/*An API to set the timeout values that end up in the time out registers; */
int sc_set_tor (int fd, uint32_t time)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &time;
        
                ret = ioctl(fd, SC_IOCTL_SET_TOR, &ioctl_args);
        }
        
        return (ret);
}



/*This API sets the baud rate/ETU;*/
int sc_set_etu (int fd, uint32_t c_div, uint32_t divisor, uint32_t factor)
{
     sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &c_div;
                ioctl_args.p_params[2] = (uint32_t) &divisor;
                ioctl_args.p_params[3] = (uint32_t) &factor;

                ret = ioctl(fd, SC_IOCTL_SET_ETU, &ioctl_args);
        }

        return (ret);
}

/*This API sets the clock frequency;*/
int sc_set_clock (int fd, uint32_t clock)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &clock;
        
                ret = ioctl(fd, SC_IOCTL_SET_CLOCK, &ioctl_args);
        }
        
        return (ret);
}



/*This API sets the block guard time;*/
int sc_set_bgtime (int fd, uint32_t bgtime)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &bgtime ;
        
                ret = ioctl(fd, SC_IOCTL_SET_BGTR, &ioctl_args);
        }
        
        return (ret);
}



/*This API sets the extra guard time;*/
int sc_set_egtime (int fd, uint32_t egtime)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &egtime;
        
                ret = ioctl(fd, SC_IOCTL_SET_EGTR, &ioctl_args);
        }
        
        return (ret);
}

/*------------------------------------------------------------------------------
 * sc_adjust_reset_delay
 *------------------------------------------------------------------------------
 */

int
sc_adjust_reset_delay(int fd, uint32_t delay)
{
        sc_ioctl_args_t ioctl_args;
        int             slot;
        int             ret = -1;

        if (fd < 0) {
                return (ret);
        }
        
        slot = get_slot_number(fd);        

        if (slot_is_valid(slot)) {
                ioctl_args.p_params[0] = (uint32_t) &slot;
                ioctl_args.p_params[1] = (uint32_t) &delay;
        
                ret = ioctl(fd, SC_IOCTL_ADJUST_RESET_DELAY, &ioctl_args);
	}
        
	return (ret);
}

int sc_set_protocol(int fd, uint32_t protocol)
{
	sc_ioctl_args_t ioctl_args;
	int             slot;
	int             ret = -1;
	
	if (fd < 0) {
	        return (ret);
	}
	
	slot = get_slot_number(fd);        
	
	if (slot_is_valid(slot)) {
	        ioctl_args.p_params[0] = (uint32_t) &slot;
	        ioctl_args.p_params[1] = (uint32_t) &protocol;
	        ret = ioctl(fd, SC_IOCTL_SET_PROTOCOL, &ioctl_args);
	}
	return (ret);
}

#ifdef __cplusplus
}
#endif
