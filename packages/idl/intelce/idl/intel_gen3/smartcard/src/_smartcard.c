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
 * File Name:       _smartcard.c
 * $Revision: 0.1 $
 *----------------------------------------------------------------------
 *
 */

#include "osal_memmap.h"
#include "osal_io.h"
#include "osal_memory.h"
#include "_smartcard.h"
#include <pal_interrupt.h>
#include <linux/math64.h>

 /**
 * Forward references
 */
//static uint32_t gscard_infc_addr[] = {0x0, 0x0};
#ifdef HARDCODE_BAR
static uint32_t gscard_phys_base_addr[] = {_BASE_REG_PA_USIM_0, _BASE_REG_PA_USIM_1};
#endif
//static _scard_infc_reg_t *gpscard_infc_port[] = {NULL, NULL};


enum TimerState_e { ts_BWTR_Running=0, ts_CWTR_Running, ts_Idle};
typedef enum TimerState_e TimerState_t;

struct slot_record_s {
		_scard_infc_reg_t *	registers;
		TimerState_t		TimerState;
		volatile int					m_Signal;
		int					m_CWTRPending;
		int					m_BWTRPending;
		uint32_t			programmed_CWTR;
		uint32_t			programmed_BWTR;
		u64					jiffies_CWTR;
		u64					jiffies_BWTR;
		uint32_t			m_Waiting;
		wait_queue_head_t	m_WaitQueue;
		_scard_infc_reg_t   m_SavedRegs;
		uint32_t			m_ResetDelay;
};

#define SW_TIMER_LIMIT 1
typedef struct slot_record_s slot_record_t;

static slot_record_t slot_info[SC_MAX_SLOTS_SUPPORTED];

/*
 * This routine will return the physical base address of Smart card
 * interface 
 * @retval Base address if smartcard interface is supported other wise 0x0 is 
 * returned.
 */
static _scard_infc_reg_t * _scard_infc_get_base_addr(uint8_t slot)
{
        uint32_t phyad;
 
#ifdef HARDCODE_BAR
		phyad =  OS_MAP_IO_TO_MEM_NOCACHE(gscard_phys_base_addr[slot], 0xff);
#else
        //get the base address from pal
        pal_dev_id_t scard_dev_id;
		pal_info_t *pal_info = (pal_info_t *)OS_ALLOC(sizeof(pal_info_t));
        if (pal_info == NULL)
        {
             // OS_PRINT("OS_ALLOC FAILURE : could not alloc memory to pal_info \n");
              return 0;
        }

        scard_dev_id = (slot == 0) ? SCARD_0 : SCARD_1;
        if ( pal_get_base_and_irq(scard_dev_id, &pal_info) != PAL_SUCCESS ) {
               OS_FREE(pal_info);
               return 0;
        }
        phyad = pal_info->base_addr0;
        OS_FREE(pal_info);
#endif
        return (_scard_infc_reg_t * )(OS_MAP_IO_TO_MEM_NOCACHE(phyad,0xff));
}

/*
 * This function initializes the smartcard interface. This is the first function that should
 * be called, it reset all the smartcard interface register to HW reset values.
 */
int _scard_infc_init(uint8_t slot)
{
	slot_record_t *slot_p;
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
		_OS_DEBUG("SLOT value is incorrect=%d", slot);
		return (-1);
	}
	slot_p = &slot_info[slot];
	if(!slot_p->registers)
		slot_p->registers  = _scard_infc_get_base_addr(slot);
	if(!slot_p->registers)
		return -1;
	slot_p->registers->egtr = 0x00000005;
	slot_p->registers->bgtr = 0x00000005;// is it ISO conform? 

	_scard_infc_set_etu(slot, 7, 13, 372);
	_scard_infc_set_tx_trigger_level(slot, 0);
	_scard_infc_set_rx_trigger_level(slot, 0);
	slot_p->TimerState = ts_BWTR_Running;
	init_waitqueue_head(&slot_p->m_WaitQueue);
	slot_p->programmed_CWTR = slot_p->registers->cwtr;
	slot_p->programmed_BWTR = slot_p->registers->bwtr;
	slot_p->m_CWTRPending=0;
	slot_p->m_BWTRPending=0;
	slot_p->m_ResetDelay = 40;
	return (0);
}

/*
 * This function frees any memory associated with the smartcard interface. This 
 * functions should be called last
 */
int _scard_infc_deinit(uint8_t slot)
{
	slot_record_t *slot_p;
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) { 
		_OS_DEBUG("SLOT value is incorrect=%d", slot); 
		return (-1); 
	}
	slot_p = &slot_info[slot];
	/* clear all pending interrupts */
	if (_scard_infc_clear_interrupt(slot, SC_EVENT_MASK) < 0) {
		return IDL_FAILURE;
	}
	slot_p->TimerState = ts_BWTR_Running;
	if(slot_p->registers)
	{
			slot_p->m_Signal = 1;
			wake_up_interruptible_all(&slot_p->m_WaitQueue);
			mdelay(10);
			OS_UNMAP_IO_FROM_MEM(slot_p->registers, 0xFF);
			slot_p->registers = NULL;
	}
	return (0);
}

/*
 * This routine will perform cold/warm reset to the card connected to 
 * smartcard interface and activate it
 */
int _scard_infc_reset(uint8_t slot, sc_reset_t type, sc_vcc_t vcc)
{
        int ret = 0;
		uint32_t dummy;

		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) { 
			_OS_DEBUG("SLOT value is incorrect=%d", slot); 
			return (-1); 
		}
		slot_p = &slot_info[slot];
        switch (type) {
                case SC_RESET_TYPE_COLD:
			ret = _scard_infc_card_deactivate(slot);
			if(ret)
				break;
                        os_sleep(1);
			_scard_infc_set_etu(slot, 7, 372, 13);
                        os_sleep(1);

                        /* set CCR.RST_CARD_N to logic 0 */
                        slot_p->registers->ccr &= 0xfffffffe;
						_scard_infc_set_cwt(slot,9600-12);
						_scard_infc_set_bwt(slot,9600-12);
						slot_p->TimerState = ts_BWTR_Running;
						slot_p->m_CWTRPending=0;
						slot_p->m_BWTRPending=0;

                        os_sleep(1);
#ifndef NOT_REEL_PATCHED
                        /* enable the i/o line to return to Vhigh by setting the CCR.TXD_FORCE bit to 0 */
                        slot_p->registers->ccr &= 0xffffffef;
                        os_sleep(1); // GA
#endif
                        /* 
                         * turn on the VCC voltage by writing to the CCR.VCC bits.on first 
                         * activation, set the lowest voltage level.(set the CCR.VCC bits 
                         * to "10").
                         */
                        ret = _scard_infc_set_card_vcc(slot, vcc);
						if ( ret < 0) 
								return ret; 
 
#ifdef NOT_REEL_PATCHED
                        /* enable the i/o line to return to Vhigh by setting the CCR.TXD_FORCE bit to 0 */
                        slot_p->registers->ccr &= 0xffffffef;
#endif

                        /* activate the card clock by setting the stop bit, CLKR.STOP_UCLK to 0 */
                        slot_p->registers->clkr &= 0xffffdfff;

                        /*
                         * verify that CCR.RST_CARD_N was asserted for at least 400 UCLK cycles. note that
                         * when Fcard is set to th lowest frequency allowed by the standard, 400 cycles
                         * take 0.4ms
                         */
                        os_sleep(1);
                        /*
                         * deassert CCR.RST_CARD_N by setting it to 1. the card will Answer To Reset(ATR)
                         * within 400-40000 card clock cycles 
                         */
                        slot_p->registers->ccr |= 0x00000001;


                        os_sleep(slot_p->m_ResetDelay);

                        break;
                case SC_RESET_TYPE_WARM:
                        /* set CCR.RST_CARD_N to logic 0 */
                        slot_p->registers->ccr &= 0xfffffffe;
						_scard_infc_set_cwt(slot,9600-12);
						_scard_infc_set_bwt(slot,9600-12);
						slot_p->TimerState = ts_BWTR_Running;
						slot_p->m_CWTRPending=0;
						slot_p->m_BWTRPending=0;
                        
                        /*
                         * verify that CCR.RST_CARD_N was asserted for at least 400 UCLK cycles. note that
                         * when Fcard is set to th lowest frequency allowed by the standard, 400 cycles
                         * take 0.4ms
                         */
                        os_sleep(1);

                        /*
                         * deassert CCR.RST_CARD_N by setting it to 1. the card will Answer To Reset(ATR)
                         * within 400-40000 card clock cycles 
                         */
                        slot_p->registers->ccr |= 0x00000001;

                        os_sleep(slot_p->m_ResetDelay);
                        /* Card Deactivation.Perform the following in sequence to deactivate the USIM card */
                        
                        break;
                default: 
                        ret = (-1);
                        break;
        }
		dummy = slot_p->registers->lsr;
        return (ret);
}

/*
 * This routine will deactivate the card
 * @param id - 0,1 ( smartcard id)
 * @retval IDL_SUCCESS if card is deactivated 
 * is returned
 */
int _scard_infc_card_deactivate(uint8_t slot)
{
        slot_record_t *slot_p;
		if ( slot >= sizeof(slot_info)/sizeof(slot_info[0]) ) {	
                _OS_DEBUG("SLOT value is incorrect=%d", slot);
                return (-1);
        }
		slot_p = &slot_info[slot];

        /* set CCR.RST_CARD_N to logic 0 */
        slot_p->registers->ccr &= 0xfffffffe;
                          
        /*
         * stop the clock on Vlow by setting CLKR.STOP_LEVEL bit to 0, and setting the
         * CLKR.STOP_UCLK bit to 1
         */
		slot_p->registers->clkr &= 0xffff7fff;
		slot_p->registers->clkr |= 0x00002000;
        
        /* force the i/o line to ground level by setting 1 to the CCR.TXT_FORCE bit */
        slot_p->registers->ccr |= 0x00000010;
        
        /*
         * turn on the VCC voltage to ground level by setting CCR.VCC bits to "00" at least 
         * after the i/o line is forced low. the i/o line can be checked in the Line Status
         * Register(LSR).
         */
        slot_p->registers->ccr &= 0xfffffff9;
        
        return (0);
}

/*
 * This routine will get the current number of bytes in receive buffer 
 */
int _scard_infc_get_rx_length(uint8_t slot)
{
	slot_record_t *slot_p;
	if ( slot >= sizeof(slot_info)/sizeof(slot_info[0]) ) {	
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
	}
	slot_p = &slot_info[slot];
	return (slot_p->registers->fsr & 0x01ff);
}

/*
 * This routine will get the current number of bytes in transmit buffer 
 */
int _scard_infc_get_tx_length(uint8_t slot)
{
	slot_record_t *slot_p;
	if ( slot >= sizeof(slot_info)/sizeof(slot_info[0]) ) {	
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
	}
	slot_p = &slot_info[slot];
	return ( (slot_p->registers->fsr & 0x01ff0000) >> 16);
}

/*
 * This routine will reset and flush the TX FIFO entries
 */
int _scard_infc_reset_tx_fifo(uint8_t slot)
{
	slot_record_t *slot_p;	
	if ( slot >= sizeof(slot_info)/sizeof(slot_info[0]) ) {	
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
	}
	slot_p = &slot_info[slot];

    slot_p->registers->fcr |= 0x20000000;

	if(slot_p->TimerState == ts_BWTR_Running)
		slot_p->jiffies_BWTR = get_jiffies_64();
	return (0);
}

/*
 * This routine will reset and flush the RX FIFO entries
 */
int _scard_infc_reset_rx_fifo(uint8_t slot)
{
	slot_record_t *slot_p;
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
		_OS_DEBUG("SLOT value is incorrect=%d", slot);
		return (-1);
	}	    
	slot_p = &slot_info[slot];
	slot_p->registers->fcr |= 0x10000000;
 
	if(slot_p->TimerState == ts_CWTR_Running)
		slot_p->jiffies_CWTR = get_jiffies_64();
	return (0);
}


/*
 * This routine will set the RX trigger level
 */
int _scard_infc_set_rx_trigger_level(uint8_t slot, uint16_t rx_tl)
{
	slot_record_t *slot_p;
	if (rx_tl > MAX_RX_TRIGGER_LEVEL) {
			return (-1);
	}
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
		_OS_DEBUG("SLOT value is incorrect=%d", slot);
		return (-1);
	}	    
	slot_p = &slot_info[slot];
	slot_p->registers->fcr &= 0xffffff00;
	slot_p->registers->fcr |= rx_tl;
	return (0);
}

/*
 * This routine will set the TX trigger level
 */
int _scard_infc_set_tx_trigger_level(uint8_t slot, uint16_t tx_tl)
{
	slot_record_t *slot_p;
	if (tx_tl > MAX_TX_TRIGGER_LEVEL) {
			return (-1);
	}
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
		_OS_DEBUG("SLOT value is incorrect=%d", slot);
		return (-1);
	}	    
	slot_p = &slot_info[slot];
	slot_p->registers->fcr &= 0xff00ffff;
	slot_p->registers->fcr |= (tx_tl << 16);
	return (0);
}

/*
 * This routine will detect the card at smart card interface.
 */
int _scard_infc_get_slot_info(uint8_t slot, sc_slot_info_t *info)
{
	slot_record_t *slot_p;
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
		_OS_DEBUG("SLOT value is incorrect=%d", slot);
		return (-1);
	}	    
	slot_p = &slot_info[slot];
        /* get protocol */
	info->protocol = (slot_p->registers->lcr & 0x00000018) ? SC_T1 : SC_T0;
        /* get status */
	if (slot_p->registers->ccr & _SCARD_INFC_CCR_SCARD_INSERTED) {
        /* card is inserted, we now have to check if it is powered up */
        if ( ((slot_p->registers->ccr & 0x00000007) >> 1) > 0) {
                        info->status = SC_CARD_POWERED_UP;
        }
        else {
						info->status = SC_CARD_INSERTED_NOT_POWERED_UP;
        }             
   }
   else {
         info->status = SC_CARD_NO_CARD_INSERTED;
   }

   return (0);
}

/*
 * This routine will set the protocols for the transmitter/receiver
 * transmitter and receiver are programmed with same protocol type
 */
int _scard_infc_set_protocol(uint8_t slot, uint8_t protocol)
{

	int ret = 0;
	slot_record_t *slot_p;
	if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
		_OS_DEBUG("SLOT value is incorrect=%d", slot);
		return (-1);
	}	    
	slot_p = &slot_info[slot];


	switch (protocol) 
	{
			case SC_T0:
					slot_p->registers->lcr &= 0xffffffe7;
					break;
			case SC_T1:
					slot_p->registers->lcr |= 0x00000018;
					break;
			default:
					ret = (-1);
					break;
	}
    return (ret);
}

/*
 * This routine will enable the interrupts for smart card interface
 */
int _scard_infc_enable_interrupt(uint8_t slot, uint32_t mask)
{
		slot_record_t *slot_p;
        if ( mask & (~SC_EVENT_MASK) ) {
                return (-1);
        }
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
		slot_p->registers->ier |= mask|(SC_EVENT_MASK & (~(SC_EVENT_CARD_DET|SC_EVENT_TDR|SC_EVENT_RDR)));
        return (0);
}

/*
 * This routine will disable the interrupts for smart card interface
 */
int _scard_infc_disable_interrupt(uint8_t slot, uint32_t mask)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if ( mask & (~SC_EVENT_MASK) ) {	
                return (-1);
        }
		slot_p->registers->ier &= ~mask;        
        return (0);
}

static void arm_cwtr(slot_record_t *slot_p, uint32_t offset);
/*
 * This routine will clear the interrupt for smart card interface by clearing
 * the status bits
 */
int _scard_infc_clear_interrupt(uint8_t slot, uint32_t mask)
{
		unsigned iir;
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if ( (mask & (~SC_EVENT_MASK)) ) {
                return (-1);
        }
		iir = slot_p->registers->iir;
		slot_p->registers->iir |= mask;
		if(iir & (SC_EVENT_RDR|SC_EVENT_TDR|SC_EVENT_TIMEO|SC_EVENT_CWT|SC_EVENT_BWT))
		{

			if(iir & SC_EVENT_CWT)
				slot_p->m_CWTRPending  = 1;
			if(iir & SC_EVENT_BWT)
				slot_p->m_BWTRPending  = 1;
			if((iir & SC_EVENT_TIMEO) && !slot_p->m_Signal)
			{
				
				if(slot_p->registers->fsr & 0x1FF)
				{
					struct sched_param s = { .sched_priority = 1 };
					arm_cwtr(slot_p,slot_p->registers->tor);
					slot_p->m_Signal = 1;
					wake_up_interruptible(&slot_p->m_WaitQueue);
					sched_setscheduler(current, SCHED_RR, &s);
				}
			}
			mask &= (SC_EVENT_RDR|SC_EVENT_TDR|SC_EVENT_TIMEO);//|SC_EVENT_CWT|SC_EVENT_BWT
			slot_p->registers->ier &= ~mask;
		}
        return (0);
}

int _scard_get_interrupt_status(uint8_t slot, uint32_t *status)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        *status = (slot_p->registers->iir & SC_EVENT_MASK);
        return (0);
}
static inline uint32_t etus_to_us(slot_record_t *slot_p, unsigned n_etu)
{
	u64 usec;
	unsigned freq = slot_p->registers->dds_rate;
	unsigned clks;
	freq = (freq * 79)/10 + (freq*3)/100; // to avoid overflow
	usec = clks = n_etu * (slot_p->registers->dlr  & 0xFFFF) * (1+(slot_p->registers->flr  & 0xFF));
	usec *= 1000000;
	usec += freq/2;
	usec = div_u64(usec,freq);
	//printk("%s: Waiting time for %u etu's is %u us (freq=%u,clks=%u)\n",__FUNCTION__,n_etu,(uint32_t)usec,freq,clks);
	return (uint32_t)usec;
}
static inline uint32_t etus_to_jiffies(slot_record_t *slot_p, unsigned n_etu)
{
	return usecs_to_jiffies(etus_to_us(slot_p,n_etu));
}
static inline uint32_t get_bytes_etus(slot_record_t *slot_p, unsigned n_bytes, int tx)
{
	unsigned protocol_mask = tx ? _SCARD_INFC_LCR_TX_T1 : _SCARD_INFC_LCR_RX_T1;
	unsigned bits_per_byte = (slot_p->registers->lcr & protocol_mask) ?  11 : 12;
	return bits_per_byte * n_bytes;
}
static inline uint32_t get_bytes_us(slot_record_t *slot_p, unsigned n_bytes, int tx)
{
	return etus_to_us(slot_p,get_bytes_etus(slot_p,n_bytes,tx));
}
static inline uint32_t get_bytes_jiffies(slot_record_t *slot_p, unsigned n_bytes, int tx)
{
	return (uint32_t)usecs_to_jiffies(get_bytes_us(slot_p,n_bytes,tx));
}

static int has_cwt_flag(slot_record_t *slot_p,uint32_t lsr)
{
	u64 now;
	if (ts_CWTR_Running != slot_p->TimerState)
		return 0;
	if(slot_p->programmed_CWTR <= SW_TIMER_LIMIT)
	{
		if(slot_p->m_CWTRPending)
		{
			slot_p->m_CWTRPending = 0;
			lsr |=  SC_EVENT_CWT;
		}
		return ((lsr & SC_EVENT_CWT) != 0);
	}
	/*printk("%s: using sw timer %08x\n",__FUNCTION__,lsr); */
	now = get_jiffies_64();
	now -= slot_p->jiffies_CWTR;
	if((long long)now >= 0)
	{
		slot_p->TimerState = ts_Idle;
		return 1;
	}
	return 0;

}
static int has_bwt_flag(slot_record_t *slot_p,uint32_t lsr)
{
	u64 now;
	if (ts_BWTR_Running != slot_p->TimerState)
		return 0;
	if(slot_p->programmed_BWTR <= SW_TIMER_LIMIT)
	{

		if(slot_p->m_BWTRPending)
		{
			slot_p->m_BWTRPending = 0;
			lsr |=  SC_EVENT_BWT;
		}
		/* printk("%s: using silicon timer %08x\n",__FUNCTION__,lsr); */
		return ((lsr &SC_EVENT_BWT) != 0);
	}

	/* printk("%s: using sw timer %08x\n",__FUNCTION__,lsr); */
	now = get_jiffies_64();
	now -= slot_p->jiffies_BWTR;
	if((long long)now >= 0)
	{
		slot_p->TimerState = ts_Idle;
		return 1;
	}
	return 0;
}
static void arm_cwtr(slot_record_t *slot_p, uint32_t offset)
{
	slot_p->TimerState = ts_CWTR_Running;
	if(slot_p->programmed_CWTR <= SW_TIMER_LIMIT)
		return;
	slot_p->jiffies_CWTR = get_jiffies_64() + etus_to_jiffies(slot_p,slot_p->programmed_CWTR-offset);
}
static u64 get_read_waiting_time(slot_record_t *slot_p)
{
	u64 to = 0;
	u64 now = get_jiffies_64();
	switch(slot_p->TimerState)
	{
	case ts_BWTR_Running:
		if(slot_p->programmed_BWTR <= SW_TIMER_LIMIT)
		{
			to = get_bytes_us(slot_p,2,0);
			break;
		}
		to = slot_p->jiffies_BWTR - now;
		break;
	case ts_CWTR_Running:
		if(slot_p->programmed_CWTR <= SW_TIMER_LIMIT)
		{
			to = get_bytes_us(slot_p,2,0);
			break;
		}
		to = slot_p->jiffies_CWTR - now;
		break;
	default:
		break;
	}
	if(!to )
		to = HZ/100;
	return to;
}
static int using_to_hw(slot_record_t *slot_p)
{
	switch(slot_p->TimerState)
	{
	case ts_BWTR_Running:
		return (slot_p->programmed_BWTR <= SW_TIMER_LIMIT);
	case ts_CWTR_Running:
		return (slot_p->programmed_CWTR <= SW_TIMER_LIMIT);
	default:
		break;
	}
	return 1;
}

/*
 * This routine will read a byte from smartcard interface RX FIFO and activate it
 */
int _scard_infc_read(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_read) 
{
        uint32_t i = 0;
        uint32_t lsr = 0;
        uint32_t fsr = 0;
		uint32_t vcc=0;
		int ret = 0;
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}
		slot_p = &slot_info[slot];
        *actual_bytes_read = 0;
		if(!nbytes)
			return 0;
		for(;;)
		{
			fsr = slot_p->registers->fsr;
			if(fsr & 0xFF)
			{
				s[i++] = slot_p->registers->rbr;
				//slot_p->registers->lcr = slot_p->registers->lcr ^ 4;
				arm_cwtr(slot_p,0);				
				if(nbytes == i)
					break;
				if(SC_EVENT_FIFO_RX & slot_p->registers->lsr)
					schedule_timeout(get_bytes_jiffies(slot_p,10,1));
				continue;
			}
			lsr = slot_p->registers->lsr;
			
			vcc = slot_p->registers->ccr;
			if (!(vcc & _SCARD_INFC_CCR_SCARD_INSERTED))
			{
				ret = -ENODEV; /*card is pluged out*/
				break;
			}
			if (has_cwt_flag(slot_p,lsr))
			{
				//slot_p->registers->thr = (_SCARD_INFC_THR_TX_ENABLE | 0x41);
				if(!i)
					ret = -ETIMEDOUT;  /*CWTR timeout*/
				printk("%s: CWTR len=%d\n",__FUNCTION__,i);
				break;
			}
			if (has_bwt_flag(slot_p,lsr))
			{
				ret = -ETIMEDOUT;  /*BWTR timeout*/
				printk("%s: BWTR\n",__FUNCTION__);
				//slot_p->registers->thr = (_SCARD_INFC_THR_TX_ENABLE |  0x42);
				break;
			}
			if (lsr & SC_EVENT_FRAMERR)
			{
				ret = -EFRAME; /*Frame error*/
				break;
			}  
			if (lsr & SC_EVENT_PERR)
			{
				//printk("%s: parity error: %u\n",__FUNCTION__,i);
				ret = -EPARITY; /*parity error*/
				break;
			}  
			if (lsr & SC_EVENT_OVRN)
			{
				ret = -EOVRN; /*over run error*/
				break;
			} 
			if (lsr & SC_EVENT_TIMEO)
				break;
/*
			if (!( (lsr & 0x4000) || !(fsr & 0x1FF) || !(lsr & 0x0010) ))
			{
				break;
			}
*/
			if(using_to_hw(slot_p))
			{
				udelay(get_read_waiting_time(slot_p));
			}
			else
			{
				struct sched_param s = { .sched_priority = 1 };
				int old_prio = current->rt_priority;
			        int old_policy = current->policy;
				slot_p->m_Signal = 0;
				_scard_infc_enable_interrupt(slot,SC_EVENT_TIMEO);
				wait_event_interruptible_timeout(slot_p->m_WaitQueue,(slot_p->m_Signal != 0), get_read_waiting_time(slot_p) );
				s.sched_priority = old_prio;
				sched_setscheduler(current, old_policy, &s);
			}
		}
		if(!i)
			ret = -ETIMEDOUT;
		if (ret < 0) 
		{	
	//	  _scard_dump_registers(slot);
		}
        *actual_bytes_read = i;

		//slot_p->registers->thr = (_SCARD_INFC_THR_TX_ENABLE |  0x43);
	_scard_infc_enable_interrupt(slot,SC_EVENT_TIMEO);
        return ret;
}

/*
 * This routine will read a byte from smartcard interface RX FIFO
 * and activate it
 */
int _scard_infc_write(uint8_t slot, uint8_t *s, uint32_t nbytes, uint32_t *actual_bytes_written) 
{ 
        uint32_t i = 0;
        uint32_t val;
        uint32_t lsr = 0;
        uint32_t fsr = 0;
		int ret = 0;
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        
        while (i < nbytes) {
                /* 
                 * if it is the last byte to be writen, then mark bit TX_ENABLE in the bit 31
                 */
#if 1
                if (i == nbytes - 1) { /* last byte */
                        val = (_SCARD_INFC_THR_TX_ENABLE | s[i]);

                }
                else {
                        val = s[i];
                }
#else
                val = (_SCARD_INFC_THR_TX_ENABLE | s[i]);
#endif  
                /* Write a character byte to the FIFO. */
                slot_p->registers->thr = val;
                i++;
        }

        *actual_bytes_written = i;
		val = ((fsr = slot_p->registers->fsr >> 16) & 0x1FF) + 1;
		while(val != i)
		{
			unsigned us = get_bytes_us(slot_p,i,1);
			if(us < 5000)
				udelay(us);
			else
			{
				set_current_state(TASK_UNINTERRUPTIBLE);
				schedule_timeout(usecs_to_jiffies(us));
			}

			lsr = slot_p->registers->lsr;
			fsr = slot_p->registers->fsr;
			if (lsr & (1<<2))
			{
				slot_p->registers->fsr = (fsr | (1 << 6));
				udelay(10);
				ret = -ET0;
				break;
			
			}  
			if (!( (lsr & 0x2000) && (fsr & 0x1FF0000) ))
			{
				break;
			}
			val = i;
			i = (fsr >> 16) & 0x1FF;
		}

		slot_p->TimerState = ts_BWTR_Running;
		slot_p->jiffies_BWTR = get_jiffies_64()+etus_to_jiffies(slot_p,slot_p->programmed_BWTR);

		return ret;
}

/*
 * This routine is called after the card is removed from the interface
 * This routine will complete smooth shut down at interface
 * @param id - 0,1 ( smartcard id)
 * @retval IDL_SUCCESS if card is deactivated 
 * is returned
 */
int _scard_infc_card_removal(uint8_t slot)
{
#if 1
        /* clear the FIFOs */
        _scard_infc_reset_tx_fifo(slot);
        _scard_infc_reset_rx_fifo(slot);

        /* shut down the power supply */
        if (_scard_infc_set_card_vcc(slot, SC_VCC_SEL_0) < 0) {
                return (-1);
        }
#else                
        /* stop the clocks */
        _scard_infc_stop_sclk(slot);

        /* set the clock rate to default value */
        _scard_infc_set_clk_divisor(slot, IDL_SCARD_INFC_CLK_DIV_DEF);
#endif
        return (0);
}

/*
 * This routine configure the clock frequency for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param c_div - 0-0xFF 
 * @retval true if etu values are set correctly
 */
int _scard_infc_set_clk_divisor(uint8_t slot, uint32_t c_div)
{
		int i=0;
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];

        if ( c_div > 0xff ) {
                _OS_DEBUG("Clock divisior value is incorrect=0x%X[0-0x00FF]",c_div);
                return (-1);
        }
        else if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
                _OS_DEBUG("SLOT value is incorrect=%d", slot);
                return (-1);
        } 
	//Any write to the CLKR when CLKR.RQST = '1' will be ignored
		while((i++<10) && (slot_p->registers->clkr &0x100));

		if(10 <= i)
		{
			_OS_DEBUG("Request occurring, do not update CLKR\n");
			return (-1);
		} 
		slot_p->registers->clkr = (slot_p->registers->clkr & 0xffffff00) | (uint8_t) c_div;
        os_sleep(1);
        return (0);
}

int _scard_infc_stop_sclk(uint8_t slot)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        slot_p->registers->clkr |= 0x00002000;        
        return (0);
}

int _scard_infc_start_sclk(uint8_t slot)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        slot_p->registers->clkr &= 0xffffdfff;        
        return (0);
}

int _scard_infc_set_card_vcc(uint8_t slot, sc_vcc_t vcc)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        slot_p->registers->ccr &= 0xfffffff9;
        slot_p->registers->ccr |= (vcc << 1);
		if( ((slot_p->registers->ccr & (~0xfffffff9)) >> 1) != vcc) 
				return -1;
        return (0);
}

int _scard_infc_set_egtr(uint8_t slot, uint32_t egtm)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if ( egtm > 0xff ) {
                _OS_DEBUG("EGTR value is incorrect=0x%X[0-0xFF]", egtm);
                return (-1);
        }    
        slot_p->registers->egtr = (uint8_t) egtm;
        return (0);
}

int _scard_infc_set_bgtr(uint8_t slot, uint32_t bgt)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if ( bgt > 0xff ) {
                _OS_DEBUG("BGTR value is incorrect=0x%X[0-0xFF]", bgt);
                return (-1);
        }    
        slot_p->registers->bgtr = (uint8_t) bgt;
        return IDL_SUCCESS;
}

/*
 * This routine configure the GPIO for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @retval true if gpio are programmed corretly
 */
int _scard_infc_set_gpio(uint8_t scard_id)
{
        /* need to add code to configure GPIO if they are not configured by default */
        return (0);
}

/*
 * This routine configure the etu for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param c_div - 0-0xFF 
 * @param D - 0-0xFFFF
 * @param F - 0-0xFF
 * @retval true if etu values are set correctly
 */
int _scard_infc_set_etu(uint8_t slot, uint32_t c_div, uint32_t divisor, uint32_t factor)
{
        int ret = -1;


        /* configure factor latch reg */
        if (_scard_infc_set_flr(slot, factor) < 0) {
                return (ret);
        }
        if (_scard_infc_set_dlr(slot, divisor) < 0) {
                return (ret);
        }

        if (_scard_infc_set_clk_divisor(slot, c_div) < 0) {
                return (ret);
        }

        return (0);    
}

/*
 * This routine configure the baud factor for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param F - 0-0xFF
 * @retval IDL_SUCCESS if baud factor values are set correctly
 */
int _scard_infc_set_flr(uint8_t slot, uint32_t factor)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if (factor > 0xff || factor < 5) {
                _OS_DEBUG("Baud factor value is incorrect=0x%X[5-0x00FF]", factor);
                return (-1);
        }
        slot_p->registers->flr = (uint8_t) factor ;
        return (0);
}
/*
 * This routine configure the baud divisor for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param F - 0-0xFFFF
 * @retval IDL_SUCCESS if baud divisor values are set correctly
 */
int _scard_infc_set_dlr(uint8_t slot, uint32_t divisor)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if (divisor > 0xffff) {
                _OS_DEBUG("Baud divisor value is incorrect=0x%X[0-0xFFFF]", divisor);
                return (-1);
        }
		slot_p->registers->dlr = (uint16_t) divisor;
        return (0);
}

/*
 * This routine configure the character waiting time for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param D - 0-0xFFFF
 * @retval IDL_SUCCESS if character waiting time values are set correctly
 */
int _scard_infc_set_cwt(uint8_t slot, uint32_t cwt)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}
		slot_p = &slot_info[slot];
		slot_p->programmed_CWTR = cwt;
        if (cwt > SW_TIMER_LIMIT)
			cwt = 0xFFFF;
        slot_p->registers->cwtr = (uint16_t) cwt;
        return (0);
}

/*
 * This routine configure the block waiting time for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param data - 0-0xFFFF
 * @retval IDL_SUCCESS if block waiting time values are set correctly
 */
int _scard_infc_set_bwt(uint8_t slot, uint32_t bwt)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
		slot_p->programmed_BWTR = bwt;
        if (bwt > SW_TIMER_LIMIT)
			bwt = 0xFFFF;
        slot_p->registers->bwtr = (uint16_t) bwt;
        return (0);
}

/*
 * This routine configure the time out register for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param data - 0-0xFFFF
 * @retval IDL_SUCCESS if block waiting time values are set correctly
 */
int _scard_infc_set_tor(uint8_t slot, uint32_t tor)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if (tor > 0xffff) {
                _OS_DEBUG("Tor value is incorrect=0x%X[0-0xFFFF]", tor);
                return (-1);
        }
        slot_p->registers->tor = (uint16_t) tor;
        return (0);
}

/*
 * This routine configure the io mode for smartcard interface
 * @param id - 0,1 ( smartcard id)
 * @param data - 0-0x1
 * @retval IDL_SUCCESS if block waiting time values are set correctly
 */
int _scard_infc_set_iomode(uint8_t slot, uint32_t iomode)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		slot_p = &slot_info[slot];
        if (iomode > 0x1) {
                _OS_DEBUG("BWT value is incorrect=0x%X[0-0x1]", iomode);
                return (-1);
        }    
		
		if (iomode == DIRECT_CONVENTION)
		{
			slot_p->registers->lcr &= ((uint16_t)(0xFFFC));
			slot_p->registers->lcr |= ((uint16_t)(1<<0x2));
		}
		else
		{
			slot_p->registers->lcr &= ((uint16_t)(~(1<<0x2)));
			slot_p->registers->lcr |= ((uint16_t)(0x0003));
		}

        return (0);
}

/*
 * This routine will clear the interrupt for smart card interface by clearing
 * the status bits
 */
int _scard_infc_adjust_reset_delay(uint8_t slot, uint32_t delay)
{
	slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return (-1);
		}	    
		if ( delay > 500) {
				return (-1);
		}
		slot_p = &slot_info[slot];
        slot_p->m_ResetDelay = delay;
        return (0);
}

void _scard_dump_registers(uint8_t slot)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return;
		}	    
		slot_p = &slot_info[slot];
        OS_PRINT( "---------------BEGIN(SCARD_%d)-----------------\n", slot);
        OS_PRINT( "ier  = 0x%08x\n", slot_p->registers->ier);
        OS_PRINT( "iir  = 0x%08x\n", slot_p->registers->iir);
        OS_PRINT( "fcr  = 0x%08x\n", slot_p->registers->fcr);
        OS_PRINT( "fsr  = 0x%08x\n", slot_p->registers->fsr);
        OS_PRINT( "ecr  = 0x%08x\n", slot_p->registers->ecr);
        OS_PRINT( "lcr  = 0x%08x\n", slot_p->registers->lcr);
        OS_PRINT( "ccr  = 0x%08x\n", slot_p->registers->ccr);
        OS_PRINT( "lsr  = 0x%08x\n", slot_p->registers->lsr);
        OS_PRINT( "egtr = 0x%08x\n", slot_p->registers->egtr);
        OS_PRINT( "bgtr = 0x%08x\n", slot_p->registers->bgtr);
        OS_PRINT( "tor  = 0x%08x\n", slot_p->registers->tor);
        OS_PRINT( "clkr = 0x%08x\n", slot_p->registers->clkr);
        OS_PRINT( "dlr  = 0x%08x\n", slot_p->registers->dlr);
        OS_PRINT( "flr  = 0x%08x\n", slot_p->registers->flr);
        OS_PRINT( "cwtr = 0x%08x\n", slot_p->registers->cwtr);
        OS_PRINT( "bwtr = 0x%08x\n", slot_p->registers->bwtr);
        OS_PRINT( "-----------------END(SCARD_%d)-----------------\n", slot);
}

/*suspend one smartcard register into scard_reg[slot] structure*/
int _scard_infc_suspend(uint8_t slot)
{
		slot_record_t *slot_p;
		uint32_t *src,*dst;
		int i;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return -EINVAL;
		}	    
		slot_p = &slot_info[slot];
		dst = (uint32_t *)&slot_p->m_SavedRegs;
		src = (uint32_t *)slot_p->registers;
		for(i=0;i<(sizeof(slot_p->m_SavedRegs)/sizeof(uint32_t));i++)
			dst[i] = src[i];
		return 0;
 }
 
 /*resume one smartcard register from scard_reg[slot] structure*/
int _scard_infc_resume(uint8_t slot)
{
		slot_record_t *slot_p;
		if (slot >= sizeof(slot_info)/sizeof(slot_info[0])) {
			_OS_DEBUG("SLOT value is incorrect=%d", slot);
			return -EINVAL;
		}	    
		slot_p = &slot_info[slot];
		slot_p->registers->fcr = (slot_p->m_SavedRegs.fcr & ((1 << 31) | 0x1FF | (0x1FF << 16) ));
		slot_p->registers->ecr = (slot_p->m_SavedRegs.ecr & (0x3 | (0x3 << 3) | (1 << 7)));
		slot_p->registers->lcr = (slot_p->m_SavedRegs.lcr & 0x1f);
		//    slot_p->registers->ccr = slot_p->m_SavedRegs.ccr;
		slot_p->registers->egtr = (slot_p->m_SavedRegs.egtr & 0xFF); 
		slot_p->registers->bgtr = (slot_p->m_SavedRegs.bgtr & 0xFF);
		slot_p->registers->tor = (slot_p->m_SavedRegs.tor & 0xFF);
		slot_p->registers->clkr = (slot_p->m_SavedRegs.clkr & 0x60FF);
		slot_p->registers->flr = (slot_p->m_SavedRegs.flr & 0xFF);
		slot_p->registers->dlr = (slot_p->m_SavedRegs.dlr & 0xFFFF); 
		slot_p->registers->cwtr = (slot_p->m_SavedRegs.cwtr & 0xFFFF); 
		slot_p->registers->bwtr = (slot_p->m_SavedRegs.bwtr & 0xFFFF);
		_scard_infc_reset_tx_fifo(slot);
		_scard_infc_reset_rx_fifo(slot);
		slot_p->registers->ier = (slot_p->m_SavedRegs.ier & 0x707F);
		return 0;
}

