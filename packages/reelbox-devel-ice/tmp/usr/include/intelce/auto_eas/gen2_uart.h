#ifndef UART_REGOFFS_H
#define UART_REGOFFS_H 1
#warning including deprecated file UART_REGOFFS_H please use sanitized filename
/*

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2007-2009 Intel Corporation. All rights reserved.
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


/* Module UART CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_UART_RBR	0x0 /*  Receive Data Buffer  */ 
	#define BITFIELD_UART_RBR	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_THR	0x4 /*  Transmit Holding Register  */ 
	#define BITFIELD_UART_THR	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_IER	0x8 /*  Interrupt Enable  */ 
	#define BITFIELD_UART_IER	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_IIR	0xc /*  Interrupt Identification  */ 
	#define BITFIELD_UART_IIR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_FCR	0x10 /*  FIFO Control  */ 
	#define BITFIELD_UART_FCR	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_FSR	0x14 /*  FIFO Status  */ 
	#define BITFIELD_UART_FSR	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_ECR	0x18 /*  Error Control  */ 
	#define BITFIELD_UART_ECR	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_LCR	0x1c /*  Line Control  */ 
	#define BITFIELD_UART_LCR	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_CCR	0x20 /*  Card Control  */ 
	#define BITFIELD_UART_CCR	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_LSR	0x24 /*  Line Status  */ 
	#define BITFIELD_UART_LSR	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_EGTR	0x28 /*  Extra Guard Time  */ 
	#define BITFIELD_UART_EGTR	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_BGTR	0x2c /*  Block Guard Time  */ 
	#define BITFIELD_UART_BGTR	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_TOR	0x30 /*  Time Out  */ 
	#define BITFIELD_UART_TOR	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_CLKR	0x34 /*  Clock  */ 
	#define BITFIELD_UART_CLKR	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_DLR	0x38 /*  Divisor Latch  */ 
	#define BITFIELD_UART_DLR	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_FLR	0x3c /*  Factor Latch  */ 
	#define BITFIELD_UART_FLR	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_CWTR	0x40 /*  Character Waiting Time  */ 
	#define BITFIELD_UART_CWTR	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_BWTR	0x44 /*  Block Waiting Time  */ 
	#define BITFIELD_UART_BWTR	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_UART_Reserved	0x48 /*  Reserved			 */ 
	#define BITFIELD_UART_Reserved	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module UART SPECIFIC SVEN Events */




#endif /* UART_REGOFFS_H */
