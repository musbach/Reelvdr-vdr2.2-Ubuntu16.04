#ifndef AUD_IO_REGOFFS_H
#define AUD_IO_REGOFFS_H 1
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


/* Module AUD_IO CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_AUD_IO_CSR	0x0 /* CSR - Configuration and Status Register. This register controls clock and reset of the block, various configurations of the block and reflects general status of the block. */ 
	#define BITFIELD_AUD_IO_CSR	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_CSR */
	#define BLSB_AUD_IO_CSR_UNDEFINED_31_20	20
	#define BLSB_AUD_IO_CSR_DTS_ENABLE	19
	#define BLSB_AUD_IO_CSR_RESERVED_18_8	8
	#define BLSB_AUD_IO_CSR_UNDEFINED_7_4	4
	#define BLSB_AUD_IO_CSR_UNDEFINED_3	3
	#define BLSB_AUD_IO_CSR_UNDEFINED_2	2
	#define BLSB_AUD_IO_CSR_SWRST	1
	#define BLSB_AUD_IO_CSR_CLKEN	0
	/* Register Bit Widths for AUD_IO_CSR */
	#define BWID_AUD_IO_CSR_UNDEFINED_31_20	12
	#define BWID_AUD_IO_CSR_DTS_ENABLE	1
	#define BWID_AUD_IO_CSR_RESERVED_18_8	11
	#define BWID_AUD_IO_CSR_UNDEFINED_7_4	4
	#define BWID_AUD_IO_CSR_UNDEFINED_3	1
	#define BWID_AUD_IO_CSR_UNDEFINED_2	1
	#define BWID_AUD_IO_CSR_SWRST	1
	#define BWID_AUD_IO_CSR_CLKEN	1
	/* Register Bit MASKS for AUD_IO_CSR */
	#define BMSK_AUD_IO_CSR_UNDEFINED_31_20	0xfff00000 /* , bit(s):31:20, default(), access() */
	#define BMSK_AUD_IO_CSR_DTS_ENABLE	(1<<19) /* == 0x00080000: DTS_ENABLE Fuse value, bit(s):19, default(0b), access(R0) */
	#define BMSK_AUD_IO_CSR_RESERVED_18_8	0x0007ff00 /* Reserved, bit(s):18:8, default(0h), access(RV) */
	#define BMSK_AUD_IO_CSR_UNDEFINED_7_4	0x000000f0 /* , bit(s):7:4, default(), access() */
	#define BMSK_AUD_IO_CSR_UNDEFINED_3	(1<<3) /* == 0x00000008: , bit(s):3, default(), access() */
	#define BMSK_AUD_IO_CSR_UNDEFINED_2	(1<<2) /* == 0x00000004: , bit(s):2, default(), access() */
	#define BMSK_AUD_IO_CSR_SWRST	(1<<1) /* == 0x00000002: Software Reset. When asserted, active low, drives reset to all dependent blocks, except DSP processor., bit(s):1, default(0b), access(RW) */
	#define BMSK_AUD_IO_CSR_CLKEN	(1<<0) /* == 0x00000001: Clock Enable. When asserted, active high, enables the clock to dependent blocks., bit(s):0, default(1b), access(RW) */
	/* Register BITFIELD for AUD_IO_CSR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_CSR_UNDEFINED_31_20	 0x0000, 20, 12, 0xfff00000
	#define BITFIELD_AUD_IO_CSR_DTS_ENABLE	 0x0000, 19, 1, 0x00080000
	#define BITFIELD_AUD_IO_CSR_RESERVED_18_8	 0x0000, 8, 11, 0x0007ff00
	#define BITFIELD_AUD_IO_CSR_UNDEFINED_7_4	 0x0000, 4, 4, 0x000000f0
	#define BITFIELD_AUD_IO_CSR_UNDEFINED_3	 0x0000, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_CSR_UNDEFINED_2	 0x0000, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_CSR_SWRST	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_CSR_CLKEN	 0x0000, 0, 1, 0x00000001
#define ROFF_AUD_IO_ISRX	0x4 /* ISRX - IA32 Interrupt Status Register. This register reflects status of an interrupted mapped event.  */ 
	#define BITFIELD_AUD_IO_ISRX	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_ISRX */
	#define BLSB_AUD_IO_ISRX_UNDEFINED_31	31
	#define BLSB_AUD_IO_ISRX_UNDEFINED_30	30
	#define BLSB_AUD_IO_ISRX_UNDEFINED_29	29
	#define BLSB_AUD_IO_ISRX_UNDEFINED_28	28
	#define BLSB_AUD_IO_ISRX_UNDEFINED_27	27
	#define BLSB_AUD_IO_ISRX_UNDEFINED_26	26
	#define BLSB_AUD_IO_ISRX_UNDEFINED_25	25
	#define BLSB_AUD_IO_ISRX_UNDEFINED_24	24
	#define BLSB_AUD_IO_ISRX_TX2_INT_PEND_CPU	23
	#define BLSB_AUD_IO_ISRX_TX1_INT_PEND_CPU	22
	#define BLSB_AUD_IO_ISRX_TX0_INT_PEND_CPU	21
	#define BLSB_AUD_IO_ISRX_UNDEFINED_20	20
	#define BLSB_AUD_IO_ISRX_RX0_INT_PEND_CPU	19
	#define BLSB_AUD_IO_ISRX_UNDEFINED_18	18
	#define BLSB_AUD_IO_ISRX_UNDEFINED_17	17
	#define BLSB_AUD_IO_ISRX_UNDEFINED_16	16
	#define BLSB_AUD_IO_ISRX_UNDEFINED_15	15
	#define BLSB_AUD_IO_ISRX_UNDEFINED_14	14
	#define BLSB_AUD_IO_ISRX_UNDEFINED_13	13
	#define BLSB_AUD_IO_ISRX_UNDEFINED_12	12
	#define BLSB_AUD_IO_ISRX_UNDEFINED_11	11
	#define BLSB_AUD_IO_ISRX_DMA3_DES	10
	#define BLSB_AUD_IO_ISRX_DMA3_SRC	9
	#define BLSB_AUD_IO_ISRX_DMA2_DES	8
	#define BLSB_AUD_IO_ISRX_DMA2_SRC	7
	#define BLSB_AUD_IO_ISRX_DMA1_DES	6
	#define BLSB_AUD_IO_ISRX_DMA1_SRC	5
	#define BLSB_AUD_IO_ISRX_DMA0_DES	4
	#define BLSB_AUD_IO_ISRX_DMA0_SRC	3
	#define BLSB_AUD_IO_ISRX_UNDEFINED_2	2
	#define BLSB_AUD_IO_ISRX_UNDEFINED_1	1
	#define BLSB_AUD_IO_ISRX_UNDEFINED_0	0
	/* Register Bit Widths for AUD_IO_ISRX */
	#define BWID_AUD_IO_ISRX_UNDEFINED_31	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_30	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_29	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_28	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_27	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_26	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_25	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_24	1
	#define BWID_AUD_IO_ISRX_TX2_INT_PEND_CPU	1
	#define BWID_AUD_IO_ISRX_TX1_INT_PEND_CPU	1
	#define BWID_AUD_IO_ISRX_TX0_INT_PEND_CPU	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_20	1
	#define BWID_AUD_IO_ISRX_RX0_INT_PEND_CPU	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_18	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_17	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_16	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_15	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_14	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_13	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_12	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_11	1
	#define BWID_AUD_IO_ISRX_DMA3_DES	1
	#define BWID_AUD_IO_ISRX_DMA3_SRC	1
	#define BWID_AUD_IO_ISRX_DMA2_DES	1
	#define BWID_AUD_IO_ISRX_DMA2_SRC	1
	#define BWID_AUD_IO_ISRX_DMA1_DES	1
	#define BWID_AUD_IO_ISRX_DMA1_SRC	1
	#define BWID_AUD_IO_ISRX_DMA0_DES	1
	#define BWID_AUD_IO_ISRX_DMA0_SRC	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_2	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_1	1
	#define BWID_AUD_IO_ISRX_UNDEFINED_0	1
	/* Register Bit MASKS for AUD_IO_ISRX */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_31	(1<<31) /* == 0x80000000: , bit(s):31, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_30	(1<<30) /* == 0x40000000: , bit(s):30, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_29	(1<<29) /* == 0x20000000: , bit(s):29, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_28	(1<<28) /* == 0x10000000: , bit(s):28, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_27	(1<<27) /* == 0x08000000: , bit(s):27, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_26	(1<<26) /* == 0x04000000: , bit(s):26, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_25	(1<<25) /* == 0x02000000: , bit(s):25, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_24	(1<<24) /* == 0x01000000: , bit(s):24, default(), access() */
	#define BMSK_AUD_IO_ISRX_TX2_INT_PEND_CPU	(1<<23) /* == 0x00800000: TX2 interrupt pending to CPU, bit(s):23, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_TX1_INT_PEND_CPU	(1<<22) /* == 0x00400000: TX1 Interrupt pending to CPU, bit(s):22, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_TX0_INT_PEND_CPU	(1<<21) /* == 0x00200000: TX0 Interrupt pending to CPU, bit(s):21, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_20	(1<<20) /* == 0x00100000: , bit(s):20, default(), access() */
	#define BMSK_AUD_IO_ISRX_RX0_INT_PEND_CPU	(1<<19) /* == 0x00080000: RX0 interrupt pending to CPU, bit(s):19, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_18	(1<<18) /* == 0x00040000: , bit(s):18, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_17	(1<<17) /* == 0x00020000: , bit(s):17, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_16	(1<<16) /* == 0x00010000: , bit(s):16, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_15	(1<<15) /* == 0x00008000: , bit(s):15, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_14	(1<<14) /* == 0x00004000: , bit(s):14, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_13	(1<<13) /* == 0x00002000: , bit(s):13, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_12	(1<<12) /* == 0x00001000: , bit(s):12, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_11	(1<<11) /* == 0x00000800: , bit(s):11, default(), access() */
	#define BMSK_AUD_IO_ISRX_DMA3_DES	(1<<10) /* == 0x00000400: DMA3 Destination  Interrupt pending to CPU, bit(s):10, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA3_SRC	(1<<9) /* == 0x00000200: DMA3 Source Interrupt pending to CPU, bit(s):9, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA2_DES	(1<<8) /* == 0x00000100: DMA2 Destination  Interrupt pending to CPU, bit(s):8, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA2_SRC	(1<<7) /* == 0x00000080: DMA2 Source Interrupt pending to CPU, bit(s):7, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA1_DES	(1<<6) /* == 0x00000040: DMA1 Destination  Interrupt pending to CPU, bit(s):6, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA1_SRC	(1<<5) /* == 0x00000020: DMA1 Source Interrupt pending to CPU, bit(s):5, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA0_DES	(1<<4) /* == 0x00000010: DMA0 Destination  Interrupt pending to CPU, bit(s):4, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_DMA0_SRC	(1<<3) /* == 0x00000008: DMA0 Source Interrupt pending to CPU, bit(s):3, default(0b), access(RWC) */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_2	(1<<2) /* == 0x00000004: , bit(s):2, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_1	(1<<1) /* == 0x00000002: , bit(s):1, default(), access() */
	#define BMSK_AUD_IO_ISRX_UNDEFINED_0	(1<<0) /* == 0x00000001: , bit(s):0, default(), access() */
	/* Register BITFIELD for AUD_IO_ISRX - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_31	 0x0004, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_30	 0x0004, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_29	 0x0004, 29, 1, 0x20000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_28	 0x0004, 28, 1, 0x10000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_27	 0x0004, 27, 1, 0x08000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_26	 0x0004, 26, 1, 0x04000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_25	 0x0004, 25, 1, 0x02000000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_24	 0x0004, 24, 1, 0x01000000
	#define BITFIELD_AUD_IO_ISRX_TX2_INT_PEND_CPU	 0x0004, 23, 1, 0x00800000
	#define BITFIELD_AUD_IO_ISRX_TX1_INT_PEND_CPU	 0x0004, 22, 1, 0x00400000
	#define BITFIELD_AUD_IO_ISRX_TX0_INT_PEND_CPU	 0x0004, 21, 1, 0x00200000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_20	 0x0004, 20, 1, 0x00100000
	#define BITFIELD_AUD_IO_ISRX_RX0_INT_PEND_CPU	 0x0004, 19, 1, 0x00080000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_18	 0x0004, 18, 1, 0x00040000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_17	 0x0004, 17, 1, 0x00020000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_16	 0x0004, 16, 1, 0x00010000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_15	 0x0004, 15, 1, 0x00008000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_14	 0x0004, 14, 1, 0x00004000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_13	 0x0004, 13, 1, 0x00002000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_12	 0x0004, 12, 1, 0x00001000
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_11	 0x0004, 11, 1, 0x00000800
	#define BITFIELD_AUD_IO_ISRX_DMA3_DES	 0x0004, 10, 1, 0x00000400
	#define BITFIELD_AUD_IO_ISRX_DMA3_SRC	 0x0004, 9, 1, 0x00000200
	#define BITFIELD_AUD_IO_ISRX_DMA2_DES	 0x0004, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_ISRX_DMA2_SRC	 0x0004, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_ISRX_DMA1_DES	 0x0004, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_ISRX_DMA1_SRC	 0x0004, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_ISRX_DMA0_DES	 0x0004, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_ISRX_DMA0_SRC	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_2	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_1	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_ISRX_UNDEFINED_0	 0x0004, 0, 1, 0x00000001
#define ROFF_AUD_IO_IMRX	0xc /* IMRX - IA32 Interrupt Mask Register. This register enables/disables interrupts.  */ 
	#define BITFIELD_AUD_IO_IMRX	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_IMRX */
	#define BLSB_AUD_IO_IMRX_RESERVED_31	31
	#define BLSB_AUD_IO_IMRX_UNDEFINED_30	30
	#define BLSB_AUD_IO_IMRX_UNDEFINED_29	29
	#define BLSB_AUD_IO_IMRX_UNDEFINED_28	28
	#define BLSB_AUD_IO_IMRX_UNDEFINED_27	27
	#define BLSB_AUD_IO_IMRX_UNDEFINED_26	26
	#define BLSB_AUD_IO_IMRX_UNDEFINED_25	25
	#define BLSB_AUD_IO_IMRX_UNDEFINED_24	24
	#define BLSB_AUD_IO_IMRX_TX2_INT_EN_IA	23
	#define BLSB_AUD_IO_IMRX_TX1_INT_EN_IA	22
	#define BLSB_AUD_IO_IMRX_TX0_INT_EN_IA	21
	#define BLSB_AUD_IO_IMRX_UNDEFINED_20	20
	#define BLSB_AUD_IO_IMRX_RX0_INT_EN_IA	19
	#define BLSB_AUD_IO_IMRX_UNDEFINED_18	18
	#define BLSB_AUD_IO_IMRX_UNDEFINED_17	17
	#define BLSB_AUD_IO_IMRX_UNDEFINED_16	16
	#define BLSB_AUD_IO_IMRX_UNDEFINED_15	15
	#define BLSB_AUD_IO_IMRX_UNDEFINED_14	14
	#define BLSB_AUD_IO_IMRX_UNDEFINED_13	13
	#define BLSB_AUD_IO_IMRX_UNDEFINED_12	12
	#define BLSB_AUD_IO_IMRX_UNDEFINED_11	11
	#define BLSB_AUD_IO_IMRX_DMA3_DES	10
	#define BLSB_AUD_IO_IMRX_DMA3_SRC	9
	#define BLSB_AUD_IO_IMRX_DMA2_DES	8
	#define BLSB_AUD_IO_IMRX_DMA2_SRC	7
	#define BLSB_AUD_IO_IMRX_DMA1_DES	6
	#define BLSB_AUD_IO_IMRX_DMA1_SRC	5
	#define BLSB_AUD_IO_IMRX_DMA0_DES	4
	#define BLSB_AUD_IO_IMRX_DMA0_SRC	3
	#define BLSB_AUD_IO_IMRX_UNDEFINED_2	2
	#define BLSB_AUD_IO_IMRX_UNDEFINED_1	1
	#define BLSB_AUD_IO_IMRX_UNDEFINED_0	0
	/* Register Bit Widths for AUD_IO_IMRX */
	#define BWID_AUD_IO_IMRX_RESERVED_31	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_30	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_29	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_28	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_27	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_26	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_25	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_24	1
	#define BWID_AUD_IO_IMRX_TX2_INT_EN_IA	1
	#define BWID_AUD_IO_IMRX_TX1_INT_EN_IA	1
	#define BWID_AUD_IO_IMRX_TX0_INT_EN_IA	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_20	1
	#define BWID_AUD_IO_IMRX_RX0_INT_EN_IA	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_18	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_17	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_16	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_15	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_14	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_13	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_12	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_11	1
	#define BWID_AUD_IO_IMRX_DMA3_DES	1
	#define BWID_AUD_IO_IMRX_DMA3_SRC	1
	#define BWID_AUD_IO_IMRX_DMA2_DES	1
	#define BWID_AUD_IO_IMRX_DMA2_SRC	1
	#define BWID_AUD_IO_IMRX_DMA1_DES	1
	#define BWID_AUD_IO_IMRX_DMA1_SRC	1
	#define BWID_AUD_IO_IMRX_DMA0_DES	1
	#define BWID_AUD_IO_IMRX_DMA0_SRC	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_2	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_1	1
	#define BWID_AUD_IO_IMRX_UNDEFINED_0	1
	/* Register Bit MASKS for AUD_IO_IMRX */
	#define BMSK_AUD_IO_IMRX_RESERVED_31	(1<<31) /* == 0x80000000: Reserved, bit(s):31, default(0h), access(RV) */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_30	(1<<30) /* == 0x40000000: , bit(s):30, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_29	(1<<29) /* == 0x20000000: , bit(s):29, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_28	(1<<28) /* == 0x10000000: , bit(s):28, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_27	(1<<27) /* == 0x08000000: , bit(s):27, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_26	(1<<26) /* == 0x04000000: , bit(s):26, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_25	(1<<25) /* == 0x02000000: , bit(s):25, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_24	(1<<24) /* == 0x01000000: , bit(s):24, default(), access() */
	#define BMSK_AUD_IO_IMRX_TX2_INT_EN_IA	(1<<23) /* == 0x00800000: TX2 interrupt enable to IA, bit(s):23, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_TX1_INT_EN_IA	(1<<22) /* == 0x00400000: TX1 Interrupt enable to IA, bit(s):22, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_TX0_INT_EN_IA	(1<<21) /* == 0x00200000: TX0 Interrupt Enable to IA, bit(s):21, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_20	(1<<20) /* == 0x00100000: , bit(s):20, default(), access() */
	#define BMSK_AUD_IO_IMRX_RX0_INT_EN_IA	(1<<19) /* == 0x00080000: RX0 Interrupt Enable to IA, 1: Enables interrupt from the RX channel 0, '0' - Disables., bit(s):19, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_18	(1<<18) /* == 0x00040000: , bit(s):18, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_17	(1<<17) /* == 0x00020000: , bit(s):17, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_16	(1<<16) /* == 0x00010000: , bit(s):16, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_15	(1<<15) /* == 0x00008000: , bit(s):15, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_14	(1<<14) /* == 0x00004000: , bit(s):14, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_13	(1<<13) /* == 0x00002000: , bit(s):13, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_12	(1<<12) /* == 0x00001000: , bit(s):12, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_11	(1<<11) /* == 0x00000800: , bit(s):11, default(), access() */
	#define BMSK_AUD_IO_IMRX_DMA3_DES	(1<<10) /* == 0x00000400: DMA3 destination  Interrupt Enable to IA, bit(s):10, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA3_SRC	(1<<9) /* == 0x00000200: DMA 3 source interrupt Enable to IA, bit(s):9, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA2_DES	(1<<8) /* == 0x00000100: DMA2 destination  Interrupt Enable to IA CPU, bit(s):8, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA2_SRC	(1<<7) /* == 0x00000080: DMA2 source interrupt enable to IA CPU, bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA1_DES	(1<<6) /* == 0x00000040: DMA1 destination  Interrupt Enable to IA CPU, bit(s):6, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA1_SRC	(1<<5) /* == 0x00000020: DMA 1 source interrupt enable to IA CPU, bit(s):5, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA0_DES	(1<<4) /* == 0x00000010: DMA0  destination  Interrupt Enable to IA CPU, 1:  Enables interrupt from the DMA channel 0, '0' - Disables., bit(s):4, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_DMA0_SRC	(1<<3) /* == 0x00000008: DMA0 source interrupt enable to IA CPU, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_2	(1<<2) /* == 0x00000004: , bit(s):2, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_1	(1<<1) /* == 0x00000002: , bit(s):1, default(), access() */
	#define BMSK_AUD_IO_IMRX_UNDEFINED_0	(1<<0) /* == 0x00000001: , bit(s):0, default(), access() */
	/* Register BITFIELD for AUD_IO_IMRX - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_IMRX_RESERVED_31	 0x000c, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_30	 0x000c, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_29	 0x000c, 29, 1, 0x20000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_28	 0x000c, 28, 1, 0x10000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_27	 0x000c, 27, 1, 0x08000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_26	 0x000c, 26, 1, 0x04000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_25	 0x000c, 25, 1, 0x02000000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_24	 0x000c, 24, 1, 0x01000000
	#define BITFIELD_AUD_IO_IMRX_TX2_INT_EN_IA	 0x000c, 23, 1, 0x00800000
	#define BITFIELD_AUD_IO_IMRX_TX1_INT_EN_IA	 0x000c, 22, 1, 0x00400000
	#define BITFIELD_AUD_IO_IMRX_TX0_INT_EN_IA	 0x000c, 21, 1, 0x00200000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_20	 0x000c, 20, 1, 0x00100000
	#define BITFIELD_AUD_IO_IMRX_RX0_INT_EN_IA	 0x000c, 19, 1, 0x00080000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_18	 0x000c, 18, 1, 0x00040000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_17	 0x000c, 17, 1, 0x00020000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_16	 0x000c, 16, 1, 0x00010000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_15	 0x000c, 15, 1, 0x00008000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_14	 0x000c, 14, 1, 0x00004000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_13	 0x000c, 13, 1, 0x00002000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_12	 0x000c, 12, 1, 0x00001000
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_11	 0x000c, 11, 1, 0x00000800
	#define BITFIELD_AUD_IO_IMRX_DMA3_DES	 0x000c, 10, 1, 0x00000400
	#define BITFIELD_AUD_IO_IMRX_DMA3_SRC	 0x000c, 9, 1, 0x00000200
	#define BITFIELD_AUD_IO_IMRX_DMA2_DES	 0x000c, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_IMRX_DMA2_SRC	 0x000c, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_IMRX_DMA1_DES	 0x000c, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_IMRX_DMA1_SRC	 0x000c, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_IMRX_DMA0_DES	 0x000c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_IMRX_DMA0_SRC	 0x000c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_2	 0x000c, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_1	 0x000c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_IMRX_UNDEFINED_0	 0x000c, 0, 1, 0x00000001
#define ROFF_AUD_IO_CGR	0x2c /* CGR - Clock Gating config register */ 
	#define BITFIELD_AUD_IO_CGR	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_CGR */
	#define BLSB_AUD_IO_CGR_RESERVED_31_13	13
	#define BLSB_AUD_IO_CGR_SPDIF_CLK_RATE	12
	#define BLSB_AUD_IO_CGR_I2SC0_WS_SELECT	11
	#define BLSB_AUD_IO_CGR_I2SC1_WS_SELECT	10
	#define BLSB_AUD_IO_CGR_I2S2_CLK_INV	9
	#define BLSB_AUD_IO_CGR_I2S1_CLK_INV	8
	#define BLSB_AUD_IO_CGR_I2S0_CLK_INV	7
	#define BLSB_AUD_IO_CGR_UNDEFINED_6	6
	#define BLSB_AUD_IO_CGR_UNDEFINED_5	5
	#define BLSB_AUD_IO_CGR_TX2_CLK_EN	4
	#define BLSB_AUD_IO_CGR_TX1_CLK_EN	3
	#define BLSB_AUD_IO_CGR_TX0_CLK_EN	2
	#define BLSB_AUD_IO_CGR_UNDEFINED_1	1
	#define BLSB_AUD_IO_CGR_RX0_CLK_EN	0
	/* Register Bit Widths for AUD_IO_CGR */
	#define BWID_AUD_IO_CGR_RESERVED_31_13	19
	#define BWID_AUD_IO_CGR_SPDIF_CLK_RATE	1
	#define BWID_AUD_IO_CGR_I2SC0_WS_SELECT	1
	#define BWID_AUD_IO_CGR_I2SC1_WS_SELECT	1
	#define BWID_AUD_IO_CGR_I2S2_CLK_INV	1
	#define BWID_AUD_IO_CGR_I2S1_CLK_INV	1
	#define BWID_AUD_IO_CGR_I2S0_CLK_INV	1
	#define BWID_AUD_IO_CGR_UNDEFINED_6	1
	#define BWID_AUD_IO_CGR_UNDEFINED_5	1
	#define BWID_AUD_IO_CGR_TX2_CLK_EN	1
	#define BWID_AUD_IO_CGR_TX1_CLK_EN	1
	#define BWID_AUD_IO_CGR_TX0_CLK_EN	1
	#define BWID_AUD_IO_CGR_UNDEFINED_1	1
	#define BWID_AUD_IO_CGR_RX0_CLK_EN	1
	/* Register Bit MASKS for AUD_IO_CGR */
	#define BMSK_AUD_IO_CGR_RESERVED_31_13	0xffffe000 /* Reserved, bit(s):31:13, default(00000000h), access(RO) */
	#define BMSK_AUD_IO_CGR_SPDIF_CLK_RATE	(1<<12) /* == 0x00001000: SPDIF Clock update rate.  0: SPDIF measured clock is updated every 192 stereo samples. This is the default mode of operation, '1' : SPDIF measured clock is updated every stereo sample., bit(s):12, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_I2SC0_WS_SELECT	(1<<11) /* == 0x00000800: Select WS output coming off falling edge of bitclock for I2Sc1 interface. Used only when using internally generated bitclock, bit(s):11, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_I2SC1_WS_SELECT	(1<<10) /* == 0x00000400: Select WS_output coming off falling edge of bitclock for I2Sc0 interface. Used only when using internally generated bitclock., bit(s):10, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_I2S2_CLK_INV	(1<<9) /* == 0x00000200: Invert I2S2 bitclock output( 1: invert bitclock going out of chip; 0: no inversion on bitclock), bit(s):9, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_I2S1_CLK_INV	(1<<8) /* == 0x00000100: Invert I2S1 bitclock output( 1: invert bitclock going out of chip; 0: no inversion on bitclock), bit(s):8, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_I2S0_CLK_INV	(1<<7) /* == 0x00000080: Invert I2S0 bitclock output ( 1: invert bitclock going out of chip; 0: no inversion on bitclock), bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_UNDEFINED_6	(1<<6) /* == 0x00000040: , bit(s):6, default(), access() */
	#define BMSK_AUD_IO_CGR_UNDEFINED_5	(1<<5) /* == 0x00000020: , bit(s):5, default(), access() */
	#define BMSK_AUD_IO_CGR_TX2_CLK_EN	(1<<4) /* == 0x00000010: Enable Clock gating for TX 2 channel( 1: Enable; 0: Disable), bit(s):4, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_TX1_CLK_EN	(1<<3) /* == 0x00000008: Enable Clock gating for TX1 Channel( 1: Enable; 0: Disable), bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_TX0_CLK_EN	(1<<2) /* == 0x00000004: Enable Clock gating for TX0  channel  ( 1: Enable; 0: Disable), bit(s):2, default(0b), access(RW) */
	#define BMSK_AUD_IO_CGR_UNDEFINED_1	(1<<1) /* == 0x00000002: , bit(s):1, default(), access() */
	#define BMSK_AUD_IO_CGR_RX0_CLK_EN	(1<<0) /* == 0x00000001: Enable Clock gating for RX0 channel (1: Enable; 0: Disable), bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_CGR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_CGR_RESERVED_31_13	 0x002c, 13, 19, 0xffffe000
	#define BITFIELD_AUD_IO_CGR_SPDIF_CLK_RATE	 0x002c, 12, 1, 0x00001000
	#define BITFIELD_AUD_IO_CGR_I2SC0_WS_SELECT	 0x002c, 11, 1, 0x00000800
	#define BITFIELD_AUD_IO_CGR_I2SC1_WS_SELECT	 0x002c, 10, 1, 0x00000400
	#define BITFIELD_AUD_IO_CGR_I2S2_CLK_INV	 0x002c, 9, 1, 0x00000200
	#define BITFIELD_AUD_IO_CGR_I2S1_CLK_INV	 0x002c, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_CGR_I2S0_CLK_INV	 0x002c, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_CGR_UNDEFINED_6	 0x002c, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_CGR_UNDEFINED_5	 0x002c, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_CGR_TX2_CLK_EN	 0x002c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_CGR_TX1_CLK_EN	 0x002c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_CGR_TX0_CLK_EN	 0x002c, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_CGR_UNDEFINED_1	 0x002c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_CGR_RX0_CLK_EN	 0x002c, 0, 1, 0x00000001
#define ROFF_AUD_IO_SPRSCS	0x50 /* SPRSCS - SPDIF Re-sampler Counter Sample Register */ 
	#define BITFIELD_AUD_IO_SPRSCS	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_SPRSCS */
	#define BLSB_AUD_IO_SPRSCS_RESERVED_31_20	20
	#define BLSB_AUD_IO_SPRSCS_SPDIF_SAMPLED_COUNTER_VALUE	0
	/* Register Bit Widths for AUD_IO_SPRSCS */
	#define BWID_AUD_IO_SPRSCS_RESERVED_31_20	12
	#define BWID_AUD_IO_SPRSCS_SPDIF_SAMPLED_COUNTER_VALUE	20
	/* Register Bit MASKS for AUD_IO_SPRSCS */
	#define BMSK_AUD_IO_SPRSCS_RESERVED_31_20	0xfff00000 /* Reserved, bit(s):31:20, default(00000000h), access(RW) */
	#define BMSK_AUD_IO_SPRSCS_SPDIF_SAMPLED_COUNTER_VALUE	0x000fffff /* This is the sample of a free-running counter 36.864Mhz. The sampling point is based on a count of a number of SPDIF Frames., bit(s):19:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_SPRSCS - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_SPRSCS_RESERVED_31_20	 0x0050, 20, 12, 0xfff00000
	#define BITFIELD_AUD_IO_SPRSCS_SPDIF_SAMPLED_COUNTER_VALUE	 0x0050, 0, 20, 0x000fffff
#define ROFF_AUD_IO_SPRSFC	0x54 /* SPRSFC - SPDIF Re-sampler Frame Count Register */ 
	#define BITFIELD_AUD_IO_SPRSFC	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_SPRSFC */
	#define BLSB_AUD_IO_SPRSFC_RESERVED_31_4	4
	#define BLSB_AUD_IO_SPRSFC_SPDIF_RESAMPLER_FRAME_COUNT	0
	/* Register Bit Widths for AUD_IO_SPRSFC */
	#define BWID_AUD_IO_SPRSFC_RESERVED_31_4	28
	#define BWID_AUD_IO_SPRSFC_SPDIF_RESAMPLER_FRAME_COUNT	4
	/* Register Bit MASKS for AUD_IO_SPRSFC */
	#define BMSK_AUD_IO_SPRSFC_RESERVED_31_4	0xfffffff0 /* Reserved, bit(s):31:4, default(00000000h), access(RW) */
	#define BMSK_AUD_IO_SPRSFC_SPDIF_RESAMPLER_FRAME_COUNT	0x0000000f /* Number of Frames to be counted before sampling the free-counter., bit(s):3:0, default(0), access(RW) */
	/* Register BITFIELD for AUD_IO_SPRSFC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_SPRSFC_RESERVED_31_4	 0x0054, 4, 28, 0xfffffff0
	#define BITFIELD_AUD_IO_SPRSFC_SPDIF_RESAMPLER_FRAME_COUNT	 0x0054, 0, 4, 0x0000000f
#define ROFF_AUD_IO_DMA0_CURR_DESCR	0x1008 /* DMA0_CURR_DESCR - Current Descriptor Address, [31:2]. 32-bit aligned BI address pointing to the current DMA descriptor (linked-list mode only). default(0000_0000), access(RO) */ 
	#define BITFIELD_AUD_IO_DMA0_CURR_DESCR	 0x1008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_NEXT_DESCR	0x100c /* DMA0_NEXT_DESCR - Next Descriptor Address [31:2]. 32-bit aligned BI address pointing to the next DMA descriptor (linked-list mode only). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_NEXT_DESCR	 0x100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA0_NEXT_DESCR */
	#define BLSB_AUD_IO_DMA0_NEXT_DESCR_WRITEABLE	31
	#define BLSB_AUD_IO_DMA0_NEXT_DESCR_RESERVED_1	1
	#define BLSB_AUD_IO_DMA0_NEXT_DESCR_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA0_NEXT_DESCR */
	#define BWID_AUD_IO_DMA0_NEXT_DESCR_WRITEABLE	30
	#define BWID_AUD_IO_DMA0_NEXT_DESCR_RESERVED_1	1
	#define BWID_AUD_IO_DMA0_NEXT_DESCR_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA0_NEXT_DESCR */
	#define BMSK_AUD_IO_DMA0_NEXT_DESCR_WRITEABLE	0x80000000 /* 1: NEXT_DESCR register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_NEXT_DESCR_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA0_NEXT_DESCR_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA0_NEXT_DESCR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA0_NEXT_DESCR_WRITEABLE	 0x100c, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA0_NEXT_DESCR_RESERVED_1	 0x100c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA0_NEXT_DESCR_RESERVED_0	 0x100c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA0_SRCDMA_START	0x1010 /* DMA0_SRCDMA_START - Start address of the Source DMA buffer in the BI address space. This is also the current pointer into the source buffer. Bits [31:0] set the physical start address. When local address is defined as SRCDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_START	 0x1010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_DSTDMA_START	0x1014 /* DMA0_DSTDMA_START - Start address of the Destination DMA buffer in the BI address space. This is also the current pointer into the destination buffer. Bits [31:0] set the physical start address. When local address is defined as DSTDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_START	 0x1014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_SRCDMA_SIZE	0x1018 /* DMA0_SRCDMA_SIZE - Size of the block of data (in bytes) to fetched from the source location. When Store-and-Forward Mode is used, the register has to hold the total number (sum) of bytes in source and destination buffers associated with current descriptor. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs.  default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_SIZE	 0x1018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_FLAGS_MODE	0x101c /* DMA0_FLAGS_MODE - Miscellaneous Control/Status: Flags, Modes, Quality of Service, and Addresses (see description below for details). This register is used to start a DMA context. A context is started when a valid configuration is written into this register (the other registers of this context must be properly configured as well - FLAGS_MODE is written to last). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE	 0x101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA0_FLAGS_MODE */
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_ACTIVE_DMA	31
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_SRC_INT	30
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_DST_INT	29
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_TERM	28
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_SUBUNIT_ID	20
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_XDMA_GAP	16
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_XBURST_SZ	12
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_BURST_SZ	8
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_READ_EN	7
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUD_IO_DMA0_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUD_IO_DMA0_FLAGS_MODE */
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_ACTIVE_DMA	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_SRC_INT	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_DST_INT	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_TERM	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_SUBUNIT_ID	4
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_XDMA_GAP	4
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_XBURST_SZ	4
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_BURST_SZ	4
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_READ_EN	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUD_IO_DMA0_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUD_IO_DMA0_FLAGS_MODE */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_ACTIVE_DMA	(1<<31) /* == 0x80000000: 1: DMA context is active (has been started but has not finished). 0: DMA context is not active., bit(s):31, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_SRC_INT	(1<<30) /* == 0x40000000: Interrupt when the current (active context) transfer has finished (source byte counter reaches zero) or when in circular-buffer addressing mode the circular buffer is empty.  1: enable interrupt 0: do not interrupt, bit(s):30, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_DST_INT	(1<<29) /* == 0x20000000: Interrupt when the current (active context) transfer has finished (destination byte counter reaches zero) or when in circular-buffer addressing mode and the circular buffer is full. 1: enable interrupt 0: do not interrupt, bit(s):29, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_TERM	(1<<28) /* == 0x10000000: Do not fetch the next descriptor when the current (active context) transfer has finished (byte counter reaches zero). 1: terminate 0: go read next descriptor , bit(s):28, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000: Read Swap Endianism: This bit control whether the data on a DMA "read" (a transfer from global address space to local address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):27, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000: Write Swap Endianism: This bit controls whether the data on a DMA "write" (a transfer from local address space to global address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):26, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000: Source Endianism: Indicates what the source endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):25, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000: Destination Endianism: Indicates what the destination endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):24, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_SUBUNIT_ID	0x00f00000 /* This field is not required to be programmed for Audio. , bit(s):23:20, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_XDMA_GAP	0x000f0000 /* Between bursts (meaning the larger of the 2 burst sizes) the context is "locked" XDMA_GAP value XSI bus clocks., bit(s):19:16, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_XBURST_SZ	0x0000f000 /* The DMA will transfer data to the Global Agent in bursts of this value., bit(s):15:12, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_BURST_SZ	0x00000f00 /* The DMA will transfer data to the Local Agent in bursts of this value., bit(s):11:8, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080: The DMA will read data from the global address space and write it into the local address space., bit(s):7, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /* Source Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010: Source Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008: The DMA will read data from the local address space and write it into the global address space., bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /* Destination Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):2:1, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001: Destination Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):0, default(0), access(RW) */
	/* Register BITFIELD for AUD_IO_DMA0_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_ACTIVE_DMA	 0x101c, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_SRC_INT	 0x101c, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_DST_INT	 0x101c, 29, 1, 0x20000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_TERM	 0x101c, 28, 1, 0x10000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	 0x101c, 27, 1, 0x08000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	 0x101c, 26, 1, 0x04000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_SRC_ENDIANISM	 0x101c, 25, 1, 0x02000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_DST_ENDIANISM	 0x101c, 24, 1, 0x01000000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_SUBUNIT_ID	 0x101c, 20, 4, 0x00f00000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_XDMA_GAP	 0x101c, 16, 4, 0x000f0000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_XBURST_SZ	 0x101c, 12, 4, 0x0000f000
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_BURST_SZ	 0x101c, 8, 4, 0x00000f00
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_READ_EN	 0x101c, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	 0x101c, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_SRC_LINK_LIST	 0x101c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_WRITE_EN	 0x101c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_DST_ADDR_MODE	 0x101c, 1, 2, 0x00000006
	#define BITFIELD_AUD_IO_DMA0_FLAGS_MODE_DST_LINK_LIST	 0x101c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA0_SRCDMA_STARTA	0x1020 /* DMA0_SRCDMA_STARTA - This is the alias of Source DMA Start Register SRCDMA_START default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_STARTA	 0x1020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_SRCDMA_BOT	0x1024 /* DMA0_SRCDMA_BOT - Address of the bottom of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_BOT	 0x1024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA0_SRCDMA_BOT */
	#define BLSB_AUD_IO_DMA0_SRCDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA0_SRCDMA_BOT */
	#define BWID_AUD_IO_DMA0_SRCDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA0_SRCDMA_BOT */
	#define BMSK_AUD_IO_DMA0_SRCDMA_BOT_WRITEABLE	0x80000000 /* 1: SRCDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA0_SRCDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_BOT_WRITEABLE	 0x1024, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_1	 0x1024, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_BOT_RESERVED_0	 0x1024, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA0_SRCDMA_TOP	0x1028 /* DMA0_SRCDMA_TOP - Address of the top of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_TOP	 0x1028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA0_SRCDMA_TOP */
	#define BLSB_AUD_IO_DMA0_SRCDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA0_SRCDMA_TOP */
	#define BWID_AUD_IO_DMA0_SRCDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA0_SRCDMA_TOP */
	#define BMSK_AUD_IO_DMA0_SRCDMA_TOP_WRITEABLE	0x80000000 /* 1: SRCDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA0_SRCDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_TOP_WRITEABLE	 0x1028, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_1	 0x1028, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_TOP_RESERVED_0	 0x1028, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA0_DSTDMA_BOT	0x102c /* DMA0_DSTDMA_BOT - Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_BOT	 0x102c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA0_DSTDMA_BOT */
	#define BLSB_AUD_IO_DMA0_DSTDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA0_DSTDMA_BOT */
	#define BWID_AUD_IO_DMA0_DSTDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA0_DSTDMA_BOT */
	#define BMSK_AUD_IO_DMA0_DSTDMA_BOT_WRITEABLE	0x80000000 /* 1: DSTDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA0_DSTDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_BOT_WRITEABLE	 0x102c, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_1	 0x102c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_BOT_RESERVED_0	 0x102c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA0_DSTDMA_TOP	0x1030 /* DMA0_DSTDMA_TOP - Address of the top of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_TOP	 0x1030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA0_DSTDMA_TOP */
	#define BLSB_AUD_IO_DMA0_DSTDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA0_DSTDMA_TOP */
	#define BWID_AUD_IO_DMA0_DSTDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA0_DSTDMA_TOP */
	#define BMSK_AUD_IO_DMA0_DSTDMA_TOP_WRITEABLE	0x80000000 /* 1: DSTDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA0_DSTDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_TOP_WRITEABLE	 0x1030, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_1	 0x1030, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_TOP_RESERVED_0	 0x1030, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA0_DSTDMA_SIZE	0x1034 /* DMA0_DSTDMA_SIZE - Size of the block of data (in bytes) to be sent to the destination location. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_SIZE	 0x1034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_SRCDMA_STOP	0x1038 /* DMA0_SRCDMA_STOP - Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_SRCDMA_STOP	 0x1038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA0_DSTDMA_STOP	0x103c /* DMA0_DSTDMA_STOP - Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA0_DSTDMA_STOP	 0x103c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_CURR_DESCR	0x1048 /* DMA1_CURR_DESCR - Current Descriptor Address, [31:2]. 32-bit aligned BI address pointing to the current DMA descriptor (linked-list mode only). default(0000_0000), access(RO) */ 
	#define BITFIELD_AUD_IO_DMA1_CURR_DESCR	 0x1048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_NEXT_DESCR	0x104c /* DMA1_NEXT_DESCR - Next Descriptor Address [31:2]. 32-bit aligned BI address pointing to the next DMA descriptor (linked-list mode only). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_NEXT_DESCR	 0x104c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA1_NEXT_DESCR */
	#define BLSB_AUD_IO_DMA1_NEXT_DESCR_WRITEABLE	31
	#define BLSB_AUD_IO_DMA1_NEXT_DESCR_RESERVED_1	1
	#define BLSB_AUD_IO_DMA1_NEXT_DESCR_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA1_NEXT_DESCR */
	#define BWID_AUD_IO_DMA1_NEXT_DESCR_WRITEABLE	30
	#define BWID_AUD_IO_DMA1_NEXT_DESCR_RESERVED_1	1
	#define BWID_AUD_IO_DMA1_NEXT_DESCR_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA1_NEXT_DESCR */
	#define BMSK_AUD_IO_DMA1_NEXT_DESCR_WRITEABLE	0x80000000 /* 1: NEXT_DESCR register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_NEXT_DESCR_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA1_NEXT_DESCR_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA1_NEXT_DESCR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA1_NEXT_DESCR_WRITEABLE	 0x104c, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA1_NEXT_DESCR_RESERVED_1	 0x104c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA1_NEXT_DESCR_RESERVED_0	 0x104c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA1_SRCDMA_START	0x1050 /* DMA1_SRCDMA_START - Start address of the Source DMA buffer in the BI address space. This is also the current pointer into the source buffer. Bits [31:0] set the physical start address. When local address is defined as SRCDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_START	 0x1050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_DSTDMA_START	0x1054 /* DMA1_DSTDMA_START - Start address of the Destination DMA buffer in the BI address space. This is also the current pointer into the destination buffer. Bits [31:0] set the physical start address. When local address is defined as DSTDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_START	 0x1054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_SRCDMA_SIZE	0x1058 /* DMA1_SRCDMA_SIZE - Size of the block of data (in bytes) to fetched from the source location. When Store-and-Forward Mode is used, the register has to hold the total number (sum) of bytes in source and destination buffers associated with current descriptor. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs.  default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_SIZE	 0x1058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_FLAGS_MODE	0x105c /* DMA1_FLAGS_MODE - Miscellaneous Control/Status: Flags, Modes, Quality of Service, and Addresses (see description below for details). This register is used to start a DMA context. A context is started when a valid configuration is written into this register (the other registers of this context must be properly configured as well - FLAGS_MODE is written to last). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE	 0x105c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA1_FLAGS_MODE */
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_ACTIVE_DMA	31
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_SRC_INT	30
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_DST_INT	29
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_TERM	28
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_SUBUNIT_ID	20
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_XDMA_GAP	16
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_XBURST_SZ	12
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_BURST_SZ	8
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_READ_EN	7
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUD_IO_DMA1_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUD_IO_DMA1_FLAGS_MODE */
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_ACTIVE_DMA	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_SRC_INT	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_DST_INT	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_TERM	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_SUBUNIT_ID	4
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_XDMA_GAP	4
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_XBURST_SZ	4
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_BURST_SZ	4
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_READ_EN	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUD_IO_DMA1_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUD_IO_DMA1_FLAGS_MODE */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_ACTIVE_DMA	(1<<31) /* == 0x80000000: 1: DMA context is active (has been started but has not finished). 0: DMA context is not active., bit(s):31, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_SRC_INT	(1<<30) /* == 0x40000000: Interrupt when the current (active context) transfer has finished (source byte counter reaches zero) or when in circular-buffer addressing mode the circular buffer is empty.  1: enable interrupt 0: do not interrupt, bit(s):30, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_DST_INT	(1<<29) /* == 0x20000000: Interrupt when the current (active context) transfer has finished (destination byte counter reaches zero) or when in circular-buffer addressing mode and the circular buffer is full. 1: enable interrupt 0: do not interrupt, bit(s):29, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_TERM	(1<<28) /* == 0x10000000: Do not fetch the next descriptor when the current (active context) transfer has finished (byte counter reaches zero). 1: terminate 0: go read next descriptor , bit(s):28, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000: Read Swap Endianism: This bit control whether the data on a DMA "read" (a transfer from global address space to local address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):27, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000: Write Swap Endianism: This bit controls whether the data on a DMA "write" (a transfer from local address space to global address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):26, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000: Source Endianism: Indicates what the source endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):25, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000: Destination Endianism: Indicates what the destination endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):24, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_SUBUNIT_ID	0x00f00000 /* This field is not required to be programmed for Audio. , bit(s):23:20, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_XDMA_GAP	0x000f0000 /* Between bursts (meaning the larger of the 2 burst sizes) the context is "locked" XDMA_GAP value XSI bus clocks., bit(s):19:16, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_XBURST_SZ	0x0000f000 /* The DMA will transfer data to the Global Agent in bursts of this value., bit(s):15:12, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_BURST_SZ	0x00000f00 /* The DMA will transfer data to the Local Agent in bursts of this value., bit(s):11:8, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080: The DMA will read data from the global address space and write it into the local address space., bit(s):7, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /* Source Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010: Source Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008: The DMA will read data from the local address space and write it into the global address space., bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /* Destination Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):2:1, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001: Destination Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):0, default(0), access(RW) */
	/* Register BITFIELD for AUD_IO_DMA1_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_ACTIVE_DMA	 0x105c, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_SRC_INT	 0x105c, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_DST_INT	 0x105c, 29, 1, 0x20000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_TERM	 0x105c, 28, 1, 0x10000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	 0x105c, 27, 1, 0x08000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	 0x105c, 26, 1, 0x04000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_SRC_ENDIANISM	 0x105c, 25, 1, 0x02000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_DST_ENDIANISM	 0x105c, 24, 1, 0x01000000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_SUBUNIT_ID	 0x105c, 20, 4, 0x00f00000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_XDMA_GAP	 0x105c, 16, 4, 0x000f0000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_XBURST_SZ	 0x105c, 12, 4, 0x0000f000
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_BURST_SZ	 0x105c, 8, 4, 0x00000f00
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_READ_EN	 0x105c, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	 0x105c, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_SRC_LINK_LIST	 0x105c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_WRITE_EN	 0x105c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_DST_ADDR_MODE	 0x105c, 1, 2, 0x00000006
	#define BITFIELD_AUD_IO_DMA1_FLAGS_MODE_DST_LINK_LIST	 0x105c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA1_SRCDMA_STARTA	0x1060 /* DMA1_SRCDMA_STARTA - This is the alias of Source DMA Start Register SRCDMA_START default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_STARTA	 0x1060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_SRCDMA_BOT	0x1064 /* DMA1_SRCDMA_BOT - Address of the bottom of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_BOT	 0x1064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA1_SRCDMA_BOT */
	#define BLSB_AUD_IO_DMA1_SRCDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA1_SRCDMA_BOT */
	#define BWID_AUD_IO_DMA1_SRCDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA1_SRCDMA_BOT */
	#define BMSK_AUD_IO_DMA1_SRCDMA_BOT_WRITEABLE	0x80000000 /* 1: SRCDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA1_SRCDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_BOT_WRITEABLE	 0x1064, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_1	 0x1064, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_BOT_RESERVED_0	 0x1064, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA1_SRCDMA_TOP	0x1068 /* DMA1_SRCDMA_TOP - Address of the top of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_TOP	 0x1068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA1_SRCDMA_TOP */
	#define BLSB_AUD_IO_DMA1_SRCDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA1_SRCDMA_TOP */
	#define BWID_AUD_IO_DMA1_SRCDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA1_SRCDMA_TOP */
	#define BMSK_AUD_IO_DMA1_SRCDMA_TOP_WRITEABLE	0x80000000 /* 1: SRCDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA1_SRCDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_TOP_WRITEABLE	 0x1068, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_1	 0x1068, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_TOP_RESERVED_0	 0x1068, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA1_DSTDMA_BOT	0x106c /* DMA1_DSTDMA_BOT - Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_BOT	 0x106c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA1_DSTDMA_BOT */
	#define BLSB_AUD_IO_DMA1_DSTDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA1_DSTDMA_BOT */
	#define BWID_AUD_IO_DMA1_DSTDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA1_DSTDMA_BOT */
	#define BMSK_AUD_IO_DMA1_DSTDMA_BOT_WRITEABLE	0x80000000 /* 1: DSTDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA1_DSTDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_BOT_WRITEABLE	 0x106c, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_1	 0x106c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_BOT_RESERVED_0	 0x106c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA1_DSTDMA_TOP	0x1070 /* DMA1_DSTDMA_TOP - Address of the top of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_TOP	 0x1070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA1_DSTDMA_TOP */
	#define BLSB_AUD_IO_DMA1_DSTDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA1_DSTDMA_TOP */
	#define BWID_AUD_IO_DMA1_DSTDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA1_DSTDMA_TOP */
	#define BMSK_AUD_IO_DMA1_DSTDMA_TOP_WRITEABLE	0x80000000 /* 1: DSTDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA1_DSTDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_TOP_WRITEABLE	 0x1070, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_1	 0x1070, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_TOP_RESERVED_0	 0x1070, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA1_DSTDMA_SIZE	0x1074 /* DMA1_DSTDMA_SIZE - Size of the block of data (in bytes) to be sent to the destination location. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_SIZE	 0x1074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_SRCDMA_STOP	0x1078 /* DMA1_SRCDMA_STOP - Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_SRCDMA_STOP	 0x1078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA1_DSTDMA_STOP	0x107c /* DMA1_DSTDMA_STOP - Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA1_DSTDMA_STOP	 0x107c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_CURR_DESCR	0x1088 /* DMA2_CURR_DESCR - Current Descriptor Address, [31:2]. 32-bit aligned BI address pointing to the current DMA descriptor (linked-list mode only). default(0000_0000), access(RO) */ 
	#define BITFIELD_AUD_IO_DMA2_CURR_DESCR	 0x1088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_NEXT_DESCR	0x108c /* DMA2_NEXT_DESCR - Next Descriptor Address [31:2]. 32-bit aligned BI address pointing to the next DMA descriptor (linked-list mode only). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_NEXT_DESCR	 0x108c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA2_NEXT_DESCR */
	#define BLSB_AUD_IO_DMA2_NEXT_DESCR_WRITEABLE	31
	#define BLSB_AUD_IO_DMA2_NEXT_DESCR_RESERVED_1	1
	#define BLSB_AUD_IO_DMA2_NEXT_DESCR_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA2_NEXT_DESCR */
	#define BWID_AUD_IO_DMA2_NEXT_DESCR_WRITEABLE	30
	#define BWID_AUD_IO_DMA2_NEXT_DESCR_RESERVED_1	1
	#define BWID_AUD_IO_DMA2_NEXT_DESCR_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA2_NEXT_DESCR */
	#define BMSK_AUD_IO_DMA2_NEXT_DESCR_WRITEABLE	0x80000000 /* 1: NEXT_DESCR register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_NEXT_DESCR_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA2_NEXT_DESCR_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA2_NEXT_DESCR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA2_NEXT_DESCR_WRITEABLE	 0x108c, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA2_NEXT_DESCR_RESERVED_1	 0x108c, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA2_NEXT_DESCR_RESERVED_0	 0x108c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA2_SRCDMA_START	0x1090 /* DMA2_SRCDMA_START - Start address of the Source DMA buffer in the BI address space. This is also the current pointer into the source buffer. Bits [31:0] set the physical start address. When local address is defined as SRCDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_START	 0x1090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_DSTDMA_START	0x1094 /* DMA2_DSTDMA_START - Start address of the Destination DMA buffer in the BI address space. This is also the current pointer into the destination buffer. Bits [31:0] set the physical start address. When local address is defined as DSTDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_START	 0x1094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_SRCDMA_SIZE	0x1098 /* DMA2_SRCDMA_SIZE - Size of the block of data (in bytes) to fetched from the source location. When Store-and-Forward Mode is used, the register has to hold the total number (sum) of bytes in source and destination buffers associated with current descriptor. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs.  default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_SIZE	 0x1098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_FLAGS_MODE	0x109c /* DMA2_FLAGS_MODE - Miscellaneous Control/Status: Flags, Modes, Quality of Service, and Addresses (see description below for details). This register is used to start a DMA context. A context is started when a valid configuration is written into this register (the other registers of this context must be properly configured as well - FLAGS_MODE is written to last). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE	 0x109c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA2_FLAGS_MODE */
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_ACTIVE_DMA	31
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_SRC_INT	30
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_DST_INT	29
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_TERM	28
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_SUBUNIT_ID	20
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_XDMA_GAP	16
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_XBURST_SZ	12
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_BURST_SZ	8
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_READ_EN	7
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUD_IO_DMA2_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUD_IO_DMA2_FLAGS_MODE */
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_ACTIVE_DMA	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_SRC_INT	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_DST_INT	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_TERM	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_SUBUNIT_ID	4
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_XDMA_GAP	4
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_XBURST_SZ	4
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_BURST_SZ	4
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_READ_EN	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUD_IO_DMA2_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUD_IO_DMA2_FLAGS_MODE */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_ACTIVE_DMA	(1<<31) /* == 0x80000000: 1: DMA context is active (has been started but has not finished). 0: DMA context is not active., bit(s):31, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_SRC_INT	(1<<30) /* == 0x40000000: Interrupt when the current (active context) transfer has finished (source byte counter reaches zero) or when in circular-buffer addressing mode the circular buffer is empty.  1: enable interrupt 0: do not interrupt, bit(s):30, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_DST_INT	(1<<29) /* == 0x20000000: Interrupt when the current (active context) transfer has finished (destination byte counter reaches zero) or when in circular-buffer addressing mode and the circular buffer is full. 1: enable interrupt 0: do not interrupt, bit(s):29, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_TERM	(1<<28) /* == 0x10000000: Do not fetch the next descriptor when the current (active context) transfer has finished (byte counter reaches zero). 1: terminate 0: go read next descriptor , bit(s):28, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000: Read Swap Endianism: This bit control whether the data on a DMA "read" (a transfer from global address space to local address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):27, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000: Write Swap Endianism: This bit controls whether the data on a DMA "write" (a transfer from local address space to global address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):26, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000: Source Endianism: Indicates what the source endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):25, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000: Destination Endianism: Indicates what the destination endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):24, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_SUBUNIT_ID	0x00f00000 /* This field is not required to be programmed for Audio. , bit(s):23:20, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_XDMA_GAP	0x000f0000 /* Between bursts (meaning the larger of the 2 burst sizes) the context is "locked" XDMA_GAP value XSI bus clocks., bit(s):19:16, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_XBURST_SZ	0x0000f000 /* The DMA will transfer data to the Global Agent in bursts of this value., bit(s):15:12, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_BURST_SZ	0x00000f00 /* The DMA will transfer data to the Local Agent in bursts of this value., bit(s):11:8, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080: The DMA will read data from the global address space and write it into the local address space., bit(s):7, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /* Source Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010: Source Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008: The DMA will read data from the local address space and write it into the global address space., bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /* Destination Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):2:1, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001: Destination Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):0, default(0), access(RW) */
	/* Register BITFIELD for AUD_IO_DMA2_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_ACTIVE_DMA	 0x109c, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_SRC_INT	 0x109c, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_DST_INT	 0x109c, 29, 1, 0x20000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_TERM	 0x109c, 28, 1, 0x10000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	 0x109c, 27, 1, 0x08000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	 0x109c, 26, 1, 0x04000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_SRC_ENDIANISM	 0x109c, 25, 1, 0x02000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_DST_ENDIANISM	 0x109c, 24, 1, 0x01000000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_SUBUNIT_ID	 0x109c, 20, 4, 0x00f00000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_XDMA_GAP	 0x109c, 16, 4, 0x000f0000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_XBURST_SZ	 0x109c, 12, 4, 0x0000f000
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_BURST_SZ	 0x109c, 8, 4, 0x00000f00
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_READ_EN	 0x109c, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	 0x109c, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_SRC_LINK_LIST	 0x109c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_WRITE_EN	 0x109c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_DST_ADDR_MODE	 0x109c, 1, 2, 0x00000006
	#define BITFIELD_AUD_IO_DMA2_FLAGS_MODE_DST_LINK_LIST	 0x109c, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA2_SRCDMA_STARTA	0x10a0 /* DMA2_SRCDMA_STARTA - This is the alias of Source DMA Start Register SRCDMA_START default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_STARTA	 0x10a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_SRCDMA_BOT	0x10a4 /* DMA2_SRCDMA_BOT - Address of the bottom of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_BOT	 0x10a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA2_SRCDMA_BOT */
	#define BLSB_AUD_IO_DMA2_SRCDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA2_SRCDMA_BOT */
	#define BWID_AUD_IO_DMA2_SRCDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA2_SRCDMA_BOT */
	#define BMSK_AUD_IO_DMA2_SRCDMA_BOT_WRITEABLE	0x80000000 /* 1: SRCDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA2_SRCDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_BOT_WRITEABLE	 0x10a4, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_1	 0x10a4, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_BOT_RESERVED_0	 0x10a4, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA2_SRCDMA_TOP	0x10a8 /* DMA2_SRCDMA_TOP - Address of the top of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_TOP	 0x10a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA2_SRCDMA_TOP */
	#define BLSB_AUD_IO_DMA2_SRCDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA2_SRCDMA_TOP */
	#define BWID_AUD_IO_DMA2_SRCDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA2_SRCDMA_TOP */
	#define BMSK_AUD_IO_DMA2_SRCDMA_TOP_WRITEABLE	0x80000000 /* 1: SRCDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA2_SRCDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_TOP_WRITEABLE	 0x10a8, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_1	 0x10a8, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_TOP_RESERVED_0	 0x10a8, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA2_DSTDMA_BOT	0x10ac /* DMA2_DSTDMA_BOT - Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_BOT	 0x10ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA2_DSTDMA_BOT */
	#define BLSB_AUD_IO_DMA2_DSTDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA2_DSTDMA_BOT */
	#define BWID_AUD_IO_DMA2_DSTDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA2_DSTDMA_BOT */
	#define BMSK_AUD_IO_DMA2_DSTDMA_BOT_WRITEABLE	0x80000000 /* 1: DSTDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA2_DSTDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_BOT_WRITEABLE	 0x10ac, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_1	 0x10ac, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_BOT_RESERVED_0	 0x10ac, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA2_DSTDMA_TOP	0x10b0 /* DMA2_DSTDMA_TOP - Address of the top of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_TOP	 0x10b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA2_DSTDMA_TOP */
	#define BLSB_AUD_IO_DMA2_DSTDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA2_DSTDMA_TOP */
	#define BWID_AUD_IO_DMA2_DSTDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA2_DSTDMA_TOP */
	#define BMSK_AUD_IO_DMA2_DSTDMA_TOP_WRITEABLE	0x80000000 /* 1: DSTDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA2_DSTDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_TOP_WRITEABLE	 0x10b0, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_1	 0x10b0, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_TOP_RESERVED_0	 0x10b0, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA2_DSTDMA_SIZE	0x10b4 /* DMA2_DSTDMA_SIZE - Size of the block of data (in bytes) to be sent to the destination location. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_SIZE	 0x10b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_SRCDMA_STOP	0x10b8 /* DMA2_SRCDMA_STOP - Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_SRCDMA_STOP	 0x10b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA2_DSTDMA_STOP	0x10bc /* DMA2_DSTDMA_STOP - Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA2_DSTDMA_STOP	 0x10bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_CURR_DESCR	0x10c8 /* DMA3_CURR_DESCR - Current Descriptor Address, [31:2]. 32-bit aligned BI address pointing to the current DMA descriptor (linked-list mode only). default(0000_0000), access(RO) */ 
	#define BITFIELD_AUD_IO_DMA3_CURR_DESCR	 0x10c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_NEXT_DESCR	0x10cc /* DMA3_NEXT_DESCR - Next Descriptor Address [31:2]. 32-bit aligned BI address pointing to the next DMA descriptor (linked-list mode only). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_NEXT_DESCR	 0x10cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA3_NEXT_DESCR */
	#define BLSB_AUD_IO_DMA3_NEXT_DESCR_WRITEABLE	31
	#define BLSB_AUD_IO_DMA3_NEXT_DESCR_RESERVED_1	1
	#define BLSB_AUD_IO_DMA3_NEXT_DESCR_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA3_NEXT_DESCR */
	#define BWID_AUD_IO_DMA3_NEXT_DESCR_WRITEABLE	30
	#define BWID_AUD_IO_DMA3_NEXT_DESCR_RESERVED_1	1
	#define BWID_AUD_IO_DMA3_NEXT_DESCR_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA3_NEXT_DESCR */
	#define BMSK_AUD_IO_DMA3_NEXT_DESCR_WRITEABLE	0x80000000 /* 1: NEXT_DESCR register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_NEXT_DESCR_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA3_NEXT_DESCR_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA3_NEXT_DESCR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA3_NEXT_DESCR_WRITEABLE	 0x10cc, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA3_NEXT_DESCR_RESERVED_1	 0x10cc, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA3_NEXT_DESCR_RESERVED_0	 0x10cc, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA3_SRCDMA_START	0x10d0 /* DMA3_SRCDMA_START - Start address of the Source DMA buffer in the BI address space. This is also the current pointer into the source buffer. Bits [31:0] set the physical start address. When local address is defined as SRCDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_START	 0x10d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_DSTDMA_START	0x10d4 /* DMA3_DSTDMA_START - Start address of the Destination DMA buffer in the BI address space. This is also the current pointer into the destination buffer. Bits [31:0] set the physical start address. When local address is defined as DSTDMA_START, only bits 14:2 are meaningful and point to the register in local address space. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_START	 0x10d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_SRCDMA_SIZE	0x10d8 /* DMA3_SRCDMA_SIZE - Size of the block of data (in bytes) to fetched from the source location. When Store-and-Forward Mode is used, the register has to hold the total number (sum) of bytes in source and destination buffers associated with current descriptor. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs.  default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_SIZE	 0x10d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_FLAGS_MODE	0x10dc /* DMA3_FLAGS_MODE - Miscellaneous Control/Status: Flags, Modes, Quality of Service, and Addresses (see description below for details). This register is used to start a DMA context. A context is started when a valid configuration is written into this register (the other registers of this context must be properly configured as well - FLAGS_MODE is written to last). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE	 0x10dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA3_FLAGS_MODE */
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_ACTIVE_DMA	31
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_SRC_INT	30
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_DST_INT	29
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_TERM	28
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_SUBUNIT_ID	20
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_XDMA_GAP	16
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_XBURST_SZ	12
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_BURST_SZ	8
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_READ_EN	7
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUD_IO_DMA3_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUD_IO_DMA3_FLAGS_MODE */
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_ACTIVE_DMA	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_SRC_INT	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_DST_INT	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_TERM	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_SUBUNIT_ID	4
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_XDMA_GAP	4
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_XBURST_SZ	4
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_BURST_SZ	4
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_READ_EN	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUD_IO_DMA3_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUD_IO_DMA3_FLAGS_MODE */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_ACTIVE_DMA	(1<<31) /* == 0x80000000: 1: DMA context is active (has been started but has not finished). 0: DMA context is not active., bit(s):31, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_SRC_INT	(1<<30) /* == 0x40000000: Interrupt when the current (active context) transfer has finished (source byte counter reaches zero) or when in circular-buffer addressing mode the circular buffer is empty.  1: enable interrupt 0: do not interrupt, bit(s):30, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_DST_INT	(1<<29) /* == 0x20000000: Interrupt when the current (active context) transfer has finished (destination byte counter reaches zero) or when in circular-buffer addressing mode and the circular buffer is full. 1: enable interrupt 0: do not interrupt, bit(s):29, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_TERM	(1<<28) /* == 0x10000000: Do not fetch the next descriptor when the current (active context) transfer has finished (byte counter reaches zero). 1: terminate 0: go read next descriptor , bit(s):28, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000: Read Swap Endianism: This bit control whether the data on a DMA "read" (a transfer from global address space to local address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):27, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000: Write Swap Endianism: This bit controls whether the data on a DMA "write" (a transfer from local address space to global address space) is endian swapped.   1: Swap Endianism,  0: Don't Swap Endianism., bit(s):26, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000: Source Endianism: Indicates what the source endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):25, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000: Destination Endianism: Indicates what the destination endianism is and is used by hardware to generate the appropriate byte enables for non-32bit aligned accesses. 1: Big Endianism,  0: Little Endianism., bit(s):24, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_SUBUNIT_ID	0x00f00000 /* This field is not required to be programmed for Audio. , bit(s):23:20, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_XDMA_GAP	0x000f0000 /* Between bursts (meaning the larger of the 2 burst sizes) the context is "locked" XDMA_GAP value XSI bus clocks., bit(s):19:16, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_XBURST_SZ	0x0000f000 /* The DMA will transfer data to the Global Agent in bursts of this value., bit(s):15:12, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_BURST_SZ	0x00000f00 /* The DMA will transfer data to the Local Agent in bursts of this value., bit(s):11:8, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080: The DMA will read data from the global address space and write it into the local address space., bit(s):7, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /* Source Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010: Source Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008: The DMA will read data from the local address space and write it into the global address space., bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /* Destination Addressing Mode: 00 Linear, 01 Circular, 10 Fixed, 11 Reserved., bit(s):2:1, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001: Destination Link List Enable: 0: Linked-list mode disabled. 1: Linked-list mode enabled., bit(s):0, default(0), access(RW) */
	/* Register BITFIELD for AUD_IO_DMA3_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_ACTIVE_DMA	 0x10dc, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_SRC_INT	 0x10dc, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_DST_INT	 0x10dc, 29, 1, 0x20000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_TERM	 0x10dc, 28, 1, 0x10000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	 0x10dc, 27, 1, 0x08000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	 0x10dc, 26, 1, 0x04000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_SRC_ENDIANISM	 0x10dc, 25, 1, 0x02000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_DST_ENDIANISM	 0x10dc, 24, 1, 0x01000000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_SUBUNIT_ID	 0x10dc, 20, 4, 0x00f00000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_XDMA_GAP	 0x10dc, 16, 4, 0x000f0000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_XBURST_SZ	 0x10dc, 12, 4, 0x0000f000
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_BURST_SZ	 0x10dc, 8, 4, 0x00000f00
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_READ_EN	 0x10dc, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	 0x10dc, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_SRC_LINK_LIST	 0x10dc, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_WRITE_EN	 0x10dc, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_DST_ADDR_MODE	 0x10dc, 1, 2, 0x00000006
	#define BITFIELD_AUD_IO_DMA3_FLAGS_MODE_DST_LINK_LIST	 0x10dc, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA3_SRCDMA_STARTA	0x10e0 /* DMA3_SRCDMA_STARTA - This is the alias of Source DMA Start Register SRCDMA_START default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_STARTA	 0x10e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_SRCDMA_BOT	0x10e4 /* DMA3_SRCDMA_BOT - Address of the bottom of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_BOT	 0x10e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA3_SRCDMA_BOT */
	#define BLSB_AUD_IO_DMA3_SRCDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA3_SRCDMA_BOT */
	#define BWID_AUD_IO_DMA3_SRCDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA3_SRCDMA_BOT */
	#define BMSK_AUD_IO_DMA3_SRCDMA_BOT_WRITEABLE	0x80000000 /* 1: SRCDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA3_SRCDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_BOT_WRITEABLE	 0x10e4, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_1	 0x10e4, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_BOT_RESERVED_0	 0x10e4, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA3_SRCDMA_TOP	0x10e8 /* DMA3_SRCDMA_TOP - Address of the top of the DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_TOP	 0x10e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA3_SRCDMA_TOP */
	#define BLSB_AUD_IO_DMA3_SRCDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA3_SRCDMA_TOP */
	#define BWID_AUD_IO_DMA3_SRCDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA3_SRCDMA_TOP */
	#define BMSK_AUD_IO_DMA3_SRCDMA_TOP_WRITEABLE	0x80000000 /* 1: SRCDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA3_SRCDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_TOP_WRITEABLE	 0x10e8, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_1	 0x10e8, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_TOP_RESERVED_0	 0x10e8, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA3_DSTDMA_BOT	0x10ec /* DMA3_DSTDMA_BOT - Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer bottom (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_BOT	 0x10ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA3_DSTDMA_BOT */
	#define BLSB_AUD_IO_DMA3_DSTDMA_BOT_WRITEABLE	31
	#define BLSB_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_1	1
	#define BLSB_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA3_DSTDMA_BOT */
	#define BWID_AUD_IO_DMA3_DSTDMA_BOT_WRITEABLE	30
	#define BWID_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_1	1
	#define BWID_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA3_DSTDMA_BOT */
	#define BMSK_AUD_IO_DMA3_DSTDMA_BOT_WRITEABLE	0x80000000 /* 1: DSTDMA_BOT register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA3_DSTDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_BOT_WRITEABLE	 0x10ec, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_1	 0x10ec, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_BOT_RESERVED_0	 0x10ec, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA3_DSTDMA_TOP	0x10f0 /* DMA3_DSTDMA_TOP - Address of the top of the Destination DMA buffer (used for circular buffer modes only). Bits 31:2 set the physical address of buffer top (must be 32-bit aligned). default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_TOP	 0x10f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_DMA3_DSTDMA_TOP */
	#define BLSB_AUD_IO_DMA3_DSTDMA_TOP_WRITEABLE	31
	#define BLSB_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_1	1
	#define BLSB_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_DMA3_DSTDMA_TOP */
	#define BWID_AUD_IO_DMA3_DSTDMA_TOP_WRITEABLE	30
	#define BWID_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_1	1
	#define BWID_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_DMA3_DSTDMA_TOP */
	#define BMSK_AUD_IO_DMA3_DSTDMA_TOP_WRITEABLE	0x80000000 /* 1: DSTDMA_TOP register is 4 byte aligned., bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_1	(1<<1) /* == 0x00000002: , always 0, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_0	(1<<0) /* == 0x00000001: , always 0, bit(s):0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_DMA3_DSTDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_TOP_WRITEABLE	 0x10f0, 31, 30, 0x80000000
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_1	 0x10f0, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_TOP_RESERVED_0	 0x10f0, 0, 1, 0x00000001
#define ROFF_AUD_IO_DMA3_DSTDMA_SIZE	0x10f4 /* DMA3_DSTDMA_SIZE - Size of the block of data (in bytes) to be sent to the destination location. NOTE: Once the transfer starts, the SIZE value gets decremented by the number of data transferred and this field will reflect the current value. This field gets updated continuously when the transfer of data occurs. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_SIZE	 0x10f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_SRCDMA_STOP	0x10f8 /* DMA3_SRCDMA_STOP - Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_SRCDMA_STOP	 0x10f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_DMA3_DSTDMA_STOP	0x10fc /* DMA3_DSTDMA_STOP - Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. Bits [31:0] set the physical stop address. default(0000_0000), access(RW) */ 
	#define BITFIELD_AUD_IO_DMA3_DSTDMA_STOP	 0x10fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SACR0	0x3000 /* RX0SACR0 - Global Control Register */ 
	#define BITFIELD_AUD_IO_RX0SACR0	 0x3000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SACR0 */
	#define BLSB_AUD_IO_RX0SACR0_RESERVED_31_9	9
	#define BLSB_AUD_IO_RX0SACR0_I2S_INPUT_TYPE_SELECT	7
	#define BLSB_AUD_IO_RX0SACR0_INPUT_INTERFACE_SELECT	5
	#define BLSB_AUD_IO_RX0SACR0_RESERVED_4	4
	#define BLSB_AUD_IO_RX0SACR0_RST_FIFO	3
	#define BLSB_AUD_IO_RX0SACR0_BIT_CLK_SRC	2
	#define BLSB_AUD_IO_RX0SACR0_RESERVED_1	1
	#define BLSB_AUD_IO_RX0SACR0_RX_ENABLE	0
	/* Register Bit Widths for AUD_IO_RX0SACR0 */
	#define BWID_AUD_IO_RX0SACR0_RESERVED_31_9	23
	#define BWID_AUD_IO_RX0SACR0_I2S_INPUT_TYPE_SELECT	2
	#define BWID_AUD_IO_RX0SACR0_INPUT_INTERFACE_SELECT	2
	#define BWID_AUD_IO_RX0SACR0_RESERVED_4	1
	#define BWID_AUD_IO_RX0SACR0_RST_FIFO	1
	#define BWID_AUD_IO_RX0SACR0_BIT_CLK_SRC	1
	#define BWID_AUD_IO_RX0SACR0_RESERVED_1	1
	#define BWID_AUD_IO_RX0SACR0_RX_ENABLE	1
	/* Register Bit MASKS for AUD_IO_RX0SACR0 */
	#define BMSK_AUD_IO_RX0SACR0_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SACR0_I2S_INPUT_TYPE_SELECT	0x00000180 /* Select I2S input type, bit(s):8:7, default(0h), access(RW) */
	#define BMSK_AUD_IO_RX0SACR0_INPUT_INTERFACE_SELECT	0x00000060 /* Selects which input interface will be using this RX channel, bit(s):6:5, default(0h), access(RW) */
	#define BMSK_AUD_IO_RX0SACR0_RESERVED_4	(1<<4) /* == 0x00000010: , bit(s):4, default(), access() */
	#define BMSK_AUD_IO_RX0SACR0_RST_FIFO	(1<<3) /* == 0x00000008: Resets FIFOs logic and all registers, except this register (SACR0):0: Not reset 1: Reset is Active Other Registers, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SACR0_BIT_CLK_SRC	(1<<2) /* == 0x00000004: This bit specifies input/output direction of BITCLK: 0: Input. BITCLK is driven by an external source1: Output. BITCLK generated internally and driven out to the DAC, bit(s):2, default(0H), access(RW) */
	#define BMSK_AUD_IO_RX0SACR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved , bit(s):1, default(0b), access(RV) */
	#define BMSK_AUD_IO_RX0SACR0_RX_ENABLE	(1<<0) /* == 0x00000001: Enable RX function: 0: RX channel is disabled 1: RX channel is enabled, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_RX0SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SACR0_RESERVED_31_9	 0x3000, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_RX0SACR0_I2S_INPUT_TYPE_SELECT	 0x3000, 7, 2, 0x00000180
	#define BITFIELD_AUD_IO_RX0SACR0_INPUT_INTERFACE_SELECT	 0x3000, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_RX0SACR0_RESERVED_4	 0x3000, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_RX0SACR0_RST_FIFO	 0x3000, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_RX0SACR0_BIT_CLK_SRC	 0x3000, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_RX0SACR0_RESERVED_1	 0x3000, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_RX0SACR0_RX_ENABLE	 0x3000, 0, 1, 0x00000001
#define ROFF_AUD_IO_RX0SACR1	0x3004 /* RX0SACR1 - Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUD_IO_RX0SACR1	 0x3004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SACR1 */
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_31_21	21
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_20	20
	#define BLSB_AUD_IO_RX0SACR1_DMA_CONTEXT	17
	#define BLSB_AUD_IO_RX0SACR1_TIMESTAMP_FIFO_THRSH	15
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_14_10	10
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_9_8	8
	#define BLSB_AUD_IO_RX0SACR1_SAMPLE_SIZE	7
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_6_5	5
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_4	4
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_3	3
	#define BLSB_AUD_IO_RX0SACR1_RESERVED_2	2
	#define BLSB_AUD_IO_RX0SACR1_UNDEFINED_1	1
	#define BLSB_AUD_IO_RX0SACR1_ALT_MODE	0
	/* Register Bit Widths for AUD_IO_RX0SACR1 */
	#define BWID_AUD_IO_RX0SACR1_RESERVED_31_21	11
	#define BWID_AUD_IO_RX0SACR1_RESERVED_20	1
	#define BWID_AUD_IO_RX0SACR1_DMA_CONTEXT	3
	#define BWID_AUD_IO_RX0SACR1_TIMESTAMP_FIFO_THRSH	2
	#define BWID_AUD_IO_RX0SACR1_RESERVED_14_10	5
	#define BWID_AUD_IO_RX0SACR1_RESERVED_9_8	2
	#define BWID_AUD_IO_RX0SACR1_SAMPLE_SIZE	1
	#define BWID_AUD_IO_RX0SACR1_RESERVED_6_5	2
	#define BWID_AUD_IO_RX0SACR1_RESERVED_4	1
	#define BWID_AUD_IO_RX0SACR1_RESERVED_3	1
	#define BWID_AUD_IO_RX0SACR1_RESERVED_2	1
	#define BWID_AUD_IO_RX0SACR1_UNDEFINED_1	1
	#define BWID_AUD_IO_RX0SACR1_ALT_MODE	1
	/* Register Bit MASKS for AUD_IO_RX0SACR1 */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_31_21	0xffe00000 /* Reserved, bit(s):31:21, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_20	(1<<20) /* == 0x00100000: Note: By default Timestamp Filter is enabled., bit(s):20, default(1), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_DMA_CONTEXT	0x000e0000 /* DMA Context Number. Specifies the DMA context number allocated to this I2S channel. The software must set up this field differently for each I2S channel to avoid unpredictable behavior. 000: Context 0 001: Context 1 010:  Context 2 011: Context 3., bit(s):19:17, default(00h), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_TIMESTAMP_FIFO_THRSH	0x00018000 /* Timestamp FIFO Threshold, bit(s):16:15, default(0h), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_14_10	0x00007c00 /* Reserved, bit(s):14:10, default(0h), access(RV) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_9_8	0x00000300 /* Reserved, bit(s):9:8, default(0h), access(RV) */
	#define BMSK_AUD_IO_RX0SACR1_SAMPLE_SIZE	(1<<7) /* == 0x00000080: Data Sample Size 0: 16-bit data sample in I2S mode or 20 bit data sample in SPDIF mode 1: 24-bit data sample, bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_6_5	0x00000060 /* Reserved , bit(s):6:5, default(00b), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_3	(1<<3) /* == 0x00000008: Reserved, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SACR1_RESERVED_2	(1<<2) /* == 0x00000004: Reserved, bit(s):2, default(0b), access(RV) */
	#define BMSK_AUD_IO_RX0SACR1_UNDEFINED_1	(1<<1) /* == 0x00000002: , bit(s):1, default(0), access() */
	#define BMSK_AUD_IO_RX0SACR1_ALT_MODE	(1<<0) /* == 0x00000001: Specify Alternate Mode (I2S or MSB-Justified) Operation_ 0: Select I2S Operation Mode 1: Select MSB-Justified Operation Mode, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_RX0SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_31_21	 0x3004, 21, 11, 0xffe00000
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_20	 0x3004, 20, 1, 0x00100000
	#define BITFIELD_AUD_IO_RX0SACR1_DMA_CONTEXT	 0x3004, 17, 3, 0x000e0000
	#define BITFIELD_AUD_IO_RX0SACR1_TIMESTAMP_FIFO_THRSH	 0x3004, 15, 2, 0x00018000
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_14_10	 0x3004, 10, 5, 0x00007c00
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_9_8	 0x3004, 8, 2, 0x00000300
	#define BITFIELD_AUD_IO_RX0SACR1_SAMPLE_SIZE	 0x3004, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_6_5	 0x3004, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_4	 0x3004, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_3	 0x3004, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_RX0SACR1_RESERVED_2	 0x3004, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_RX0SACR1_UNDEFINED_1	 0x3004, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_RX0SACR1_ALT_MODE	 0x3004, 0, 1, 0x00000001
#define ROFF_AUD_IO_RX0SASR0	0x3008 /* RX0SASR0 - Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUD_IO_RX0SASR0	 0x3008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SASR0 */
	#define BLSB_AUD_IO_RX0SASR0_RESERVED_31_13	13
	#define BLSB_AUD_IO_RX0SASR0_RESERVED_12	12
	#define BLSB_AUD_IO_RX0SASR0_RESERVED_11	11
	#define BLSB_AUD_IO_RX0SASR0_TIMESTAMP_FIFO_LEVEL	8
	#define BLSB_AUD_IO_RX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	7
	#define BLSB_AUD_IO_RX0SASR0_RX_FIFO_OVERRUN	6
	#define BLSB_AUD_IO_RX0SASR0_RESERVED_5	5
	#define BLSB_AUD_IO_RX0SASR0_RX_FIFO_SVC_REQ	4
	#define BLSB_AUD_IO_RX0SASR0_RESERVED_3	3
	#define BLSB_AUD_IO_RX0SASR0_RX_BUSY	2
	#define BLSB_AUD_IO_RX0SASR0_RX_FIFO_NOT_EMPTY	1
	#define BLSB_AUD_IO_RX0SASR0_RESERVED_0	0
	/* Register Bit Widths for AUD_IO_RX0SASR0 */
	#define BWID_AUD_IO_RX0SASR0_RESERVED_31_13	19
	#define BWID_AUD_IO_RX0SASR0_RESERVED_12	1
	#define BWID_AUD_IO_RX0SASR0_RESERVED_11	1
	#define BWID_AUD_IO_RX0SASR0_TIMESTAMP_FIFO_LEVEL	3
	#define BWID_AUD_IO_RX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	1
	#define BWID_AUD_IO_RX0SASR0_RX_FIFO_OVERRUN	1
	#define BWID_AUD_IO_RX0SASR0_RESERVED_5	1
	#define BWID_AUD_IO_RX0SASR0_RX_FIFO_SVC_REQ	1
	#define BWID_AUD_IO_RX0SASR0_RESERVED_3	1
	#define BWID_AUD_IO_RX0SASR0_RX_BUSY	1
	#define BWID_AUD_IO_RX0SASR0_RX_FIFO_NOT_EMPTY	1
	#define BWID_AUD_IO_RX0SASR0_RESERVED_0	1
	/* Register Bit MASKS for AUD_IO_RX0SASR0 */
	#define BMSK_AUD_IO_RX0SASR0_RESERVED_31_13	0xffffe000 /* Reserved, bit(s):31:13, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RESERVED_12	(1<<12) /* == 0x00001000: Reserved, bit(s):12, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RESERVED_11	(1<<11) /* == 0x00000800: Reserved, bit(s):11, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_TIMESTAMP_FIFO_LEVEL	0x00000700 /* Timestamp FIFO level. The number of entries currently stored in the Timestamp and Buffer Address Pointer FIFOs (SATS and SABAP), bit(s):10:8, default(00b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	(1<<7) /* == 0x00000080: I2S Controller Clean Shutdown. When this value is '1', the I2SC is in the process of clean shutdown. When this value is '1', no writes ot the I2SC registers are allowed. When this bit is '0' and SACR0.ENB bit value is '0', then the unit is shutdown. When this bit is '0' and SACR0.ENB bit value is '1', then the I2SC is in enabled mode.When '0' is written to SACR0.ENB, I2SOFF will be '1' until all the data in the transmit FIFO is transmitted to CODEC and all the data in receive FIFO is read by the DMA., bit(s):7, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RX_FIFO_OVERRUN	(1<<6) /* == 0x00000040: Receive FIFO Overrun:0: Receive FIFO has not experienced an overrun. 1: I2S attempted data write to full Receive FIFO (Interruptible) - Can interrupt processor if bit6 of Serial Audio Interrupt Mask Register is set. - Cleared by writing a '1' to bit6 of Serial Audio Interrupt Clear Register., bit(s):6, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RESERVED_5	(1<<5) /* == 0x00000020: Reserved, bit(s):5, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RX_FIFO_SVC_REQ	(1<<4) /* == 0x00000010: Receive FIFO Service Request: 0: Receive FIFO level below RFL threshold, or I2S disabled 1: Receive FIFO level is at or above RFL threshold. - Can interrupt processor if bit4 of Serial Audio Interrupt Mask Register is set. - Cleared automatically when # of Receive FIFO entries < (RFTH + 1), bit(s):4, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RESERVED_3	(1<<3) /* == 0x00000008: Reserved, bit(s):3, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RX_BUSY	(1<<2) /* == 0x00000004: RX Busy:0: RX channel is idle or disabled 1: RX channel currently receiving a frame , bit(s):2, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RX_FIFO_NOT_EMPTY	(1<<1) /* == 0x00000002: Receive FIFO not empty: 0: Receive FIFO is empty 1: Receive FIFO is not empty, bit(s):1, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SASR0_RESERVED_0	(1<<0) /* == 0x00000001: Reserved, bit(s):0, default(0b), access(RO) */
	/* Register BITFIELD for AUD_IO_RX0SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SASR0_RESERVED_31_13	 0x3008, 13, 19, 0xffffe000
	#define BITFIELD_AUD_IO_RX0SASR0_RESERVED_12	 0x3008, 12, 1, 0x00001000
	#define BITFIELD_AUD_IO_RX0SASR0_RESERVED_11	 0x3008, 11, 1, 0x00000800
	#define BITFIELD_AUD_IO_RX0SASR0_TIMESTAMP_FIFO_LEVEL	 0x3008, 8, 3, 0x00000700
	#define BITFIELD_AUD_IO_RX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	 0x3008, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_RX0SASR0_RX_FIFO_OVERRUN	 0x3008, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_RX0SASR0_RESERVED_5	 0x3008, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_RX0SASR0_RX_FIFO_SVC_REQ	 0x3008, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_RX0SASR0_RESERVED_3	 0x3008, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_RX0SASR0_RX_BUSY	 0x3008, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_RX0SASR0_RX_FIFO_NOT_EMPTY	 0x3008, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_RX0SASR0_RESERVED_0	 0x3008, 0, 1, 0x00000001
#define ROFF_AUD_IO_RX0SAIMR	0x300c /* RX0SAIMR - Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUD_IO_RX0SAIMR	 0x300c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SAIMR */
	#define BLSB_AUD_IO_RX0SAIMR_RESERVED_31_18	18
	#define BLSB_AUD_IO_RX0SAIMR_SPDIF_RESAMPLER_INT_EN	17
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_16	16
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_15	15
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_14	14
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_13	13
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_12	12
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_11	11
	#define BLSB_AUD_IO_RX0SAIMR_I2S_FRAME_INT_EN	10
	#define BLSB_AUD_IO_RX0SAIMR_SPDIF_SYNCH_ERROR_INT_EN	9
	#define BLSB_AUD_IO_RX0SAIMR_UNDEFINED_8	8
	#define BLSB_AUD_IO_RX0SAIMR_TIMESTAMP_FIFO_SVC_REQ_INT_EN	7
	#define BLSB_AUD_IO_RX0SAIMR_RX_FIFO_OVERRUN_INT_EN	6
	#define BLSB_AUD_IO_RX0SAIMR_RESERVED_5	5
	#define BLSB_AUD_IO_RX0SAIMR_RX_FIFO_SVC_REQ_INT_EN	4
	#define BLSB_AUD_IO_RX0SAIMR_SPDIF_VALIDITY_BIT_INT_EN	3
	#define BLSB_AUD_IO_RX0SAIMR_SPDIF_PARITY_ERROR_INT_EN	2
	#define BLSB_AUD_IO_RX0SAIMR_RESERVED_1_0	0
	/* Register Bit Widths for AUD_IO_RX0SAIMR */
	#define BWID_AUD_IO_RX0SAIMR_RESERVED_31_18	14
	#define BWID_AUD_IO_RX0SAIMR_SPDIF_RESAMPLER_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_16	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_15	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_14	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_13	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_12	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_11	1
	#define BWID_AUD_IO_RX0SAIMR_I2S_FRAME_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_SPDIF_SYNCH_ERROR_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_UNDEFINED_8	1
	#define BWID_AUD_IO_RX0SAIMR_TIMESTAMP_FIFO_SVC_REQ_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_RX_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_RESERVED_5	1
	#define BWID_AUD_IO_RX0SAIMR_RX_FIFO_SVC_REQ_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_SPDIF_VALIDITY_BIT_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_SPDIF_PARITY_ERROR_INT_EN	1
	#define BWID_AUD_IO_RX0SAIMR_RESERVED_1_0	2
	/* Register Bit MASKS for AUD_IO_RX0SAIMR */
	#define BMSK_AUD_IO_RX0SAIMR_RESERVED_31_18	0xfffc0000 /* Reserved, bit(s):31:18, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SAIMR_SPDIF_RESAMPLER_INT_EN	(1<<17) /* == 0x00020000: Enable SPDIF Resampler interrupt, bit(s):17, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_16	(1<<16) /* == 0x00010000: , bit(s):16, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_15	(1<<15) /* == 0x00008000: , bit(s):15, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_14	(1<<14) /* == 0x00004000: , bit(s):14, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_13	(1<<13) /* == 0x00002000: , bit(s):13, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_12	(1<<12) /* == 0x00001000: , bit(s):12, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_11	(1<<11) /* == 0x00000800: , bit(s):11, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_I2S_FRAME_INT_EN	(1<<10) /* == 0x00000400: Enable I2S Frame interrupt (valid for I2S and S/PDIF), bit(s):10, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_SPDIF_SYNCH_ERROR_INT_EN	(1<<9) /* == 0x00000200: Enable SPDIF synch error interrupt, bit(s):9, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_UNDEFINED_8	(1<<8) /* == 0x00000100: , bit(s):8, default(), access() */
	#define BMSK_AUD_IO_RX0SAIMR_TIMESTAMP_FIFO_SVC_REQ_INT_EN	(1<<7) /* == 0x00000080: Enable Timestamp FIFO Service Request Interrupt, bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_RX_FIFO_OVERRUN_INT_EN	(1<<6) /* == 0x00000040: Enable Receive FIFO Overrun condition based interrupt (valid only in input mode), bit(s):6, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_RESERVED_5	(1<<5) /* == 0x00000020: Reserved, bit(s):5, default(0), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_RX_FIFO_SVC_REQ_INT_EN	(1<<4) /* == 0x00000010: Enable Receive FIFO Service Request based interrupt  (valid only in input mode) , bit(s):4, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_SPDIF_VALIDITY_BIT_INT_EN	(1<<3) /* == 0x00000008: Enable SPDIF validity bit interrupt, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_SPDIF_PARITY_ERROR_INT_EN	(1<<2) /* == 0x00000004: Enable SPDIF parity error interrupt, bit(s):2, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAIMR_RESERVED_1_0	0x00000003 /* Reserved, bit(s):1:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_RX0SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SAIMR_RESERVED_31_18	 0x300c, 18, 14, 0xfffc0000
	#define BITFIELD_AUD_IO_RX0SAIMR_SPDIF_RESAMPLER_INT_EN	 0x300c, 17, 1, 0x00020000
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_16	 0x300c, 16, 1, 0x00010000
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_15	 0x300c, 15, 1, 0x00008000
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_14	 0x300c, 14, 1, 0x00004000
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_13	 0x300c, 13, 1, 0x00002000
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_12	 0x300c, 12, 1, 0x00001000
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_11	 0x300c, 11, 1, 0x00000800
	#define BITFIELD_AUD_IO_RX0SAIMR_I2S_FRAME_INT_EN	 0x300c, 10, 1, 0x00000400
	#define BITFIELD_AUD_IO_RX0SAIMR_SPDIF_SYNCH_ERROR_INT_EN	 0x300c, 9, 1, 0x00000200
	#define BITFIELD_AUD_IO_RX0SAIMR_UNDEFINED_8	 0x300c, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_RX0SAIMR_TIMESTAMP_FIFO_SVC_REQ_INT_EN	 0x300c, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_RX0SAIMR_RX_FIFO_OVERRUN_INT_EN	 0x300c, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_RX0SAIMR_RESERVED_5	 0x300c, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_RX0SAIMR_RX_FIFO_SVC_REQ_INT_EN	 0x300c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_RX0SAIMR_SPDIF_VALIDITY_BIT_INT_EN	 0x300c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_RX0SAIMR_SPDIF_PARITY_ERROR_INT_EN	 0x300c, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_RX0SAIMR_RESERVED_1_0	 0x300c, 0, 2, 0x00000003
#define ROFF_AUD_IO_RX0SAISR	0x3010 /* RX0SAISR - Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUD_IO_RX0SAISR	 0x3010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SAISR */
	#define BLSB_AUD_IO_RX0SAISR_RESERVED_31_14	14
	#define BLSB_AUD_IO_RX0SAISR_SPDIF_RESAMPLER_CNT_INT	13
	#define BLSB_AUD_IO_RX0SAISR_UNDEFINED_12	12
	#define BLSB_AUD_IO_RX0SAISR_UNDEFINED_11	11
	#define BLSB_AUD_IO_RX0SAISR_UNDEFINED_10	10
	#define BLSB_AUD_IO_RX0SAISR_TIMESTAMP_FIFO_SVC_REQ_INT	9
	#define BLSB_AUD_IO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	8
	#define BLSB_AUD_IO_RX0SAISR_UNDEFINED_7	7
	#define BLSB_AUD_IO_RX0SAISR_UNDEFINED_6	6
	#define BLSB_AUD_IO_RX0SAISR_UNDEFINED_5	5
	#define BLSB_AUD_IO_RX0SAISR_I2S_SPDIF_FRAME_INT	4
	#define BLSB_AUD_IO_RX0SAISR_SPDIF_VALIDITY_BIT_INT	3
	#define BLSB_AUD_IO_RX0SAISR_SPDIF_PARITY_ERROR_INT	2
	#define BLSB_AUD_IO_RX0SAISR_RESERVED_1	1
	#define BLSB_AUD_IO_RX0SAISR_SPDIF_SYNCH_ERROR_INT	0
	/* Register Bit Widths for AUD_IO_RX0SAISR */
	#define BWID_AUD_IO_RX0SAISR_RESERVED_31_14	18
	#define BWID_AUD_IO_RX0SAISR_SPDIF_RESAMPLER_CNT_INT	1
	#define BWID_AUD_IO_RX0SAISR_UNDEFINED_12	1
	#define BWID_AUD_IO_RX0SAISR_UNDEFINED_11	1
	#define BWID_AUD_IO_RX0SAISR_UNDEFINED_10	1
	#define BWID_AUD_IO_RX0SAISR_TIMESTAMP_FIFO_SVC_REQ_INT	1
	#define BWID_AUD_IO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	1
	#define BWID_AUD_IO_RX0SAISR_UNDEFINED_7	1
	#define BWID_AUD_IO_RX0SAISR_UNDEFINED_6	1
	#define BWID_AUD_IO_RX0SAISR_UNDEFINED_5	1
	#define BWID_AUD_IO_RX0SAISR_I2S_SPDIF_FRAME_INT	1
	#define BWID_AUD_IO_RX0SAISR_SPDIF_VALIDITY_BIT_INT	1
	#define BWID_AUD_IO_RX0SAISR_SPDIF_PARITY_ERROR_INT	1
	#define BWID_AUD_IO_RX0SAISR_RESERVED_1	1
	#define BWID_AUD_IO_RX0SAISR_SPDIF_SYNCH_ERROR_INT	1
	/* Register Bit MASKS for AUD_IO_RX0SAISR */
	#define BMSK_AUD_IO_RX0SAISR_RESERVED_31_14	0xffffc000 /* Reserved, bit(s):31:14, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SAISR_SPDIF_RESAMPLER_CNT_INT	(1<<13) /* == 0x00002000: SPDIF resampler counter interrupt, bit(s):13, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAISR_UNDEFINED_12	(1<<12) /* == 0x00001000: , bit(s):12, default(), access() */
	#define BMSK_AUD_IO_RX0SAISR_UNDEFINED_11	(1<<11) /* == 0x00000800: , bit(s):11, default(), access() */
	#define BMSK_AUD_IO_RX0SAISR_UNDEFINED_10	(1<<10) /* == 0x00000400: , bit(s):10, default(), access() */
	#define BMSK_AUD_IO_RX0SAISR_TIMESTAMP_FIFO_SVC_REQ_INT	(1<<9) /* == 0x00000200: Timestamp FIFO Service Request Interrupt. 0: FIFO level below TSFL threshold from SACR1, or I2S disabled 1: FIFO level is at or above the TSFL threshold in SACR1. Cleared automatically when # of FIFO entries < (TSTH + 1), bit(s):9, default(0b), access(RO) */
	#define BMSK_AUD_IO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	(1<<8) /* == 0x00000100: Clear Receive FIFO overrun Interrupt and ROR status bit in SASR0. Writing a '1' to this location clears the interrupt and SASR0 bit 6, bit(s):8, default(0b), access(RWC) */
	#define BMSK_AUD_IO_RX0SAISR_UNDEFINED_7	(1<<7) /* == 0x00000080: , bit(s):7, default(), access() */
	#define BMSK_AUD_IO_RX0SAISR_UNDEFINED_6	(1<<6) /* == 0x00000040: , bit(s):6, default(), access() */
	#define BMSK_AUD_IO_RX0SAISR_UNDEFINED_5	(1<<5) /* == 0x00000020: , bit(s):5, default(), access() */
	#define BMSK_AUD_IO_RX0SAISR_I2S_SPDIF_FRAME_INT	(1<<4) /* == 0x00000010: I2S/SPDIF Frame interrupt (valid for I2S and S/PDIF) -This interrupt is asserted when a programmable (N) number of samples have been  received by the RX logic. This is asserted when RXFRAME_SIZE -1 stereo samples have been received by the RX logic in the case of I2S or when RXFRAME_SIZE -1 samples have been received by the RX logic  Writing a '1' clears this bit., bit(s):4, default(0b), access(RWC) */
	#define BMSK_AUD_IO_RX0SAISR_SPDIF_VALIDITY_BIT_INT	(1<<3) /* == 0x00000008: SPDIF validity bit interrupt, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAISR_SPDIF_PARITY_ERROR_INT	(1<<2) /* == 0x00000004: SPDIF parity error interrupt, bit(s):2, default(0b), access(RW) */
	#define BMSK_AUD_IO_RX0SAISR_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RW) */
	#define BMSK_AUD_IO_RX0SAISR_SPDIF_SYNCH_ERROR_INT	(1<<0) /* == 0x00000001: SPDIF input synch error interrupt, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_RX0SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SAISR_RESERVED_31_14	 0x3010, 14, 18, 0xffffc000
	#define BITFIELD_AUD_IO_RX0SAISR_SPDIF_RESAMPLER_CNT_INT	 0x3010, 13, 1, 0x00002000
	#define BITFIELD_AUD_IO_RX0SAISR_UNDEFINED_12	 0x3010, 12, 1, 0x00001000
	#define BITFIELD_AUD_IO_RX0SAISR_UNDEFINED_11	 0x3010, 11, 1, 0x00000800
	#define BITFIELD_AUD_IO_RX0SAISR_UNDEFINED_10	 0x3010, 10, 1, 0x00000400
	#define BITFIELD_AUD_IO_RX0SAISR_TIMESTAMP_FIFO_SVC_REQ_INT	 0x3010, 9, 1, 0x00000200
	#define BITFIELD_AUD_IO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	 0x3010, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_RX0SAISR_UNDEFINED_7	 0x3010, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_RX0SAISR_UNDEFINED_6	 0x3010, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_RX0SAISR_UNDEFINED_5	 0x3010, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_RX0SAISR_I2S_SPDIF_FRAME_INT	 0x3010, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_RX0SAISR_SPDIF_VALIDITY_BIT_INT	 0x3010, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_RX0SAISR_SPDIF_PARITY_ERROR_INT	 0x3010, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_RX0SAISR_RESERVED_1	 0x3010, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_RX0SAISR_SPDIF_SYNCH_ERROR_INT	 0x3010, 0, 1, 0x00000001
#define ROFF_AUD_IO_RX0SADIV	0x3014 /* RX0SADIV - Audio Clock Divider Register */ 
	#define BITFIELD_AUD_IO_RX0SADIV	 0x3014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SADIV */
	#define BLSB_AUD_IO_RX0SADIV_RESERVED_31_7	7
	#define BLSB_AUD_IO_RX0SADIV_AUD_CLK_DIV	0
	/* Register Bit Widths for AUD_IO_RX0SADIV */
	#define BWID_AUD_IO_RX0SADIV_RESERVED_31_7	25
	#define BWID_AUD_IO_RX0SADIV_AUD_CLK_DIV	7
	/* Register Bit MASKS for AUD_IO_RX0SADIV */
	#define BMSK_AUD_IO_RX0SADIV_RESERVED_31_7	0xffffff80 /* Reserved, bit(s):31:7, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SADIV_AUD_CLK_DIV	0x0000007f /* Audio Clock Divider, bit(s):6:0, default(00h), access(RW) */
	/* Register BITFIELD for AUD_IO_RX0SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SADIV_RESERVED_31_7	 0x3014, 7, 25, 0xffffff80
	#define BITFIELD_AUD_IO_RX0SADIV_AUD_CLK_DIV	 0x3014, 0, 7, 0x0000007f
#define ROFF_AUD_IO_RX0SARR	0x3018 /* RX0SARR - Serial Audio Receive Register */ 
	#define BITFIELD_AUD_IO_RX0SARR	 0x3018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SAFTH	0x301c /* RX0SAFTH - Serial Audio FIFO Threshold Register */ 
	#define BITFIELD_AUD_IO_RX0SAFTH	 0x301c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SAFTH */
	#define BLSB_AUD_IO_RX0SAFTH_RESERVED_31_16	16
	#define BLSB_AUD_IO_RX0SAFTH_RX_UPPER_FIFO_THRSH	0
	/* Register Bit Widths for AUD_IO_RX0SAFTH */
	#define BWID_AUD_IO_RX0SAFTH_RESERVED_31_16	16
	#define BWID_AUD_IO_RX0SAFTH_RX_UPPER_FIFO_THRSH	16
	/* Register Bit MASKS for AUD_IO_RX0SAFTH */
	#define BMSK_AUD_IO_RX0SAFTH_RESERVED_31_16	0xffff0000 /* Reserved, bit(s):31:16, default(0h), access(RW) */
	#define BMSK_AUD_IO_RX0SAFTH_RX_UPPER_FIFO_THRSH	0x0000ffff /* Upper FIFO Threshold of Receive Channel in words, bit(s):15:0, default(0000h), access(RW) */
	/* Register BITFIELD for AUD_IO_RX0SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SAFTH_RESERVED_31_16	 0x301c, 16, 16, 0xffff0000
	#define BITFIELD_AUD_IO_RX0SAFTH_RX_UPPER_FIFO_THRSH	 0x301c, 0, 16, 0x0000ffff
#define ROFF_AUD_IO_RX0SAFL	0x3020 /* RX0SAFL - Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUD_IO_RX0SAFL	 0x3020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SAFL */
	#define BLSB_AUD_IO_RX0SAFL_RESERVED_31_8	8
	#define BLSB_AUD_IO_RX0SAFL_RX_FIFO_LEVEL	0
	/* Register Bit Widths for AUD_IO_RX0SAFL */
	#define BWID_AUD_IO_RX0SAFL_RESERVED_31_8	24
	#define BWID_AUD_IO_RX0SAFL_RX_FIFO_LEVEL	8
	/* Register Bit MASKS for AUD_IO_RX0SAFL */
	#define BMSK_AUD_IO_RX0SAFL_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_RX0SAFL_RX_FIFO_LEVEL	0x000000ff /* FIFO Level of Receive Channel. The number of words that are currently stored in the FIFO. , bit(s):7:0, default(00h), access(RO) */
	/* Register BITFIELD for AUD_IO_RX0SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SAFL_RESERVED_31_8	 0x3020, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_RX0SAFL_RX_FIFO_LEVEL	 0x3020, 0, 8, 0x000000ff
#define ROFF_AUD_IO_RX0SADESC	0x3024 /* RX0SADESC - Audio capture Block size Register */ 
	#define BITFIELD_AUD_IO_RX0SADESC	 0x3024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_RX0SADESC */
	#define BLSB_AUD_IO_RX0SADESC_RX_FRAME_DESCRIPTOR	16
	#define BLSB_AUD_IO_RX0SADESC_RX_FRAME_SIZE	0
	/* Register Bit Widths for AUD_IO_RX0SADESC */
	#define BWID_AUD_IO_RX0SADESC_RX_FRAME_DESCRIPTOR	16
	#define BWID_AUD_IO_RX0SADESC_RX_FRAME_SIZE	16
	/* Register Bit MASKS for AUD_IO_RX0SADESC */
	#define BMSK_AUD_IO_RX0SADESC_RX_FRAME_DESCRIPTOR	0xffff0000 /* 16-bit Frame Descriptor. , bit(s):31:16, default(0000h), access(RW) */
	#define BMSK_AUD_IO_RX0SADESC_RX_FRAME_SIZE	0x0000ffff /* RXFRAME_SIZE: This value will be used to determine the size of the audio frame and how often the header info is inserted into the data stream. Normally, the audio encoding algorithm will define how many audio samples will comprise one audio block. For example, when MPEG-1 layer 2 or layer 3 is encoded, the software will set this field to 1152(decimal). Note: For I2S this refers to the number of Stereo Samples while for SPDIF this refers to just the number of Samples. , bit(s):15:0, default(0000h), access(RW) */
	/* Register BITFIELD for AUD_IO_RX0SADESC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_RX0SADESC_RX_FRAME_DESCRIPTOR	 0x3024, 16, 16, 0xffff0000
	#define BITFIELD_AUD_IO_RX0SADESC_RX_FRAME_SIZE	 0x3024, 0, 16, 0x0000ffff
#define ROFF_AUD_IO_RX0SATS	0x3028 /* RX0SATS - Audio Capture block timestamp  */ 
	#define BITFIELD_AUD_IO_RX0SATS	 0x3028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SABAP	0x302c /* RX0SABAP - Audio Sample block buffer pointer */ 
	#define BITFIELD_AUD_IO_RX0SABAP	 0x302c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SACUDR	0x3030 /* RX0SACUDR - Audio Capture User Data bit FIFO  */ 
	#define BITFIELD_AUD_IO_RX0SACUDR	 0x3030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SACSR	0x3034 /* RX0SACSR - Audio Capture Channel Status bit FIFO */ 
	#define BITFIELD_AUD_IO_RX0SACSR	 0x3034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SAVR	0x3038 /* RX0SAVR - Audio Capture Validity bit FIFO */ 
	#define BITFIELD_AUD_IO_RX0SAVR	 0x3038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_RX0SPDBP	0x303c /* RX0SPDBP - Audio Capture SPDIF Block address Pointer FIFO */ 
	#define BITFIELD_AUD_IO_RX0SPDBP	 0x303c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SACR0	0x2000 /* TX0SACR0 - Global Control Register */ 
	#define BITFIELD_AUD_IO_TX0SACR0	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SACR0 */
	#define BLSB_AUD_IO_TX0SACR0_RESERVED_31	31
	#define BLSB_AUD_IO_TX0SACR0_RESERVED_30	30
	#define BLSB_AUD_IO_TX0SACR0_RESERVED_29_6	6
	#define BLSB_AUD_IO_TX0SACR0_TX0_OUTPUT_SEL	5
	#define BLSB_AUD_IO_TX0SACR0_UNDEFINED_4	4
	#define BLSB_AUD_IO_TX0SACR0_TX0_FIFO_RESET	3
	#define BLSB_AUD_IO_TX0SACR0_RESERVED_2	2
	#define BLSB_AUD_IO_TX0SACR0_RESERVED_1	1
	#define BLSB_AUD_IO_TX0SACR0_TX0_ENABLE	0
	/* Register Bit Widths for AUD_IO_TX0SACR0 */
	#define BWID_AUD_IO_TX0SACR0_RESERVED_31	1
	#define BWID_AUD_IO_TX0SACR0_RESERVED_30	1
	#define BWID_AUD_IO_TX0SACR0_RESERVED_29_6	24
	#define BWID_AUD_IO_TX0SACR0_TX0_OUTPUT_SEL	2
	#define BWID_AUD_IO_TX0SACR0_UNDEFINED_4	1
	#define BWID_AUD_IO_TX0SACR0_TX0_FIFO_RESET	1
	#define BWID_AUD_IO_TX0SACR0_RESERVED_2	1
	#define BWID_AUD_IO_TX0SACR0_RESERVED_1	1
	#define BWID_AUD_IO_TX0SACR0_TX0_ENABLE	1
	/* Register Bit MASKS for AUD_IO_TX0SACR0 */
	#define BMSK_AUD_IO_TX0SACR0_RESERVED_31	(1<<31) /* == 0x80000000: Reserved, bit(s):31, default(0H), access(RW) */
	#define BMSK_AUD_IO_TX0SACR0_RESERVED_30	(1<<30) /* == 0x40000000: Reserved, bit(s):30, default(0H), access(RO) */
	#define BMSK_AUD_IO_TX0SACR0_RESERVED_29_6	0x3fffffc0 /* Reserved, bit(s):29:6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SACR0_TX0_OUTPUT_SEL	0x00000060 /* Select outputs 00: 7.1 I2S output 01: stereo I2S output 0 10: not used  11: S/PDIF output, bit(s):6:5, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR0_UNDEFINED_4	(1<<4) /* == 0x00000010: , bit(s):4, default(), access() */
	#define BMSK_AUD_IO_TX0SACR0_TX0_FIFO_RESET	(1<<3) /* == 0x00000008: Resets FIFOs logic and all registers, except this register (SACR0): 0: Not reset 1: Reset is Active Other Registers , bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR0_RESERVED_2	(1<<2) /* == 0x00000004: Reserved , bit(s):2, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SACR0_TX0_ENABLE	(1<<0) /* == 0x00000001: EnableTX function: 0: TX channel is disabled 1: TX channel is enabled, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SACR0_RESERVED_31	 0x2000, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_TX0SACR0_RESERVED_30	 0x2000, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_TX0SACR0_RESERVED_29_6	 0x2000, 6, 24, 0x3fffffc0
	#define BITFIELD_AUD_IO_TX0SACR0_TX0_OUTPUT_SEL	 0x2000, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_TX0SACR0_UNDEFINED_4	 0x2000, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX0SACR0_TX0_FIFO_RESET	 0x2000, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX0SACR0_RESERVED_2	 0x2000, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX0SACR0_RESERVED_1	 0x2000, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX0SACR0_TX0_ENABLE	 0x2000, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX0SACR1	0x2004 /* TX0SACR1 - Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUD_IO_TX0SACR1	 0x2004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SACR1 */
	#define BLSB_AUD_IO_TX0SACR1_TX0_SPDIF_VALIDITY	31
	#define BLSB_AUD_IO_TX0SACR1_RESERVED_30_20	20
	#define BLSB_AUD_IO_TX0SACR1_TX0_DMA_CONTEXT	17
	#define BLSB_AUD_IO_TX0SACR1_RESERVED_16	16
	#define BLSB_AUD_IO_TX0SACR1_TX0_I2S_PIN2	14
	#define BLSB_AUD_IO_TX0SACR1_TX0_I2S_PIN1	12
	#define BLSB_AUD_IO_TX0SACR1_TX0_I2S_PIN0	10
	#define BLSB_AUD_IO_TX0SACR1_TX0_MODE	8
	#define BLSB_AUD_IO_TX0SACR1_TX0_SAMPLE_SIZE	7
	#define BLSB_AUD_IO_TX0SACR1_TX0_I2S_PIN3	5
	#define BLSB_AUD_IO_TX0SACR1_RESERVED_4	4
	#define BLSB_AUD_IO_TX0SACR1_RESERVED_3	3
	#define BLSB_AUD_IO_TX0SACR1_RESERVED_2	2
	#define BLSB_AUD_IO_TX0SACR1_RESERVED_1	1
	#define BLSB_AUD_IO_TX0SACR1_TX0_ALT_MODE	0
	/* Register Bit Widths for AUD_IO_TX0SACR1 */
	#define BWID_AUD_IO_TX0SACR1_TX0_SPDIF_VALIDITY	1
	#define BWID_AUD_IO_TX0SACR1_RESERVED_30_20	11
	#define BWID_AUD_IO_TX0SACR1_TX0_DMA_CONTEXT	3
	#define BWID_AUD_IO_TX0SACR1_RESERVED_16	1
	#define BWID_AUD_IO_TX0SACR1_TX0_I2S_PIN2	2
	#define BWID_AUD_IO_TX0SACR1_TX0_I2S_PIN1	2
	#define BWID_AUD_IO_TX0SACR1_TX0_I2S_PIN0	2
	#define BWID_AUD_IO_TX0SACR1_TX0_MODE	2
	#define BWID_AUD_IO_TX0SACR1_TX0_SAMPLE_SIZE	1
	#define BWID_AUD_IO_TX0SACR1_TX0_I2S_PIN3	2
	#define BWID_AUD_IO_TX0SACR1_RESERVED_4	1
	#define BWID_AUD_IO_TX0SACR1_RESERVED_3	1
	#define BWID_AUD_IO_TX0SACR1_RESERVED_2	1
	#define BWID_AUD_IO_TX0SACR1_RESERVED_1	1
	#define BWID_AUD_IO_TX0SACR1_TX0_ALT_MODE	1
	/* Register Bit MASKS for AUD_IO_TX0SACR1 */
	#define BMSK_AUD_IO_TX0SACR1_TX0_SPDIF_VALIDITY	(1<<31) /* == 0x80000000: SPDIF validity bit, bit(s):31, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_RESERVED_30_20	0x7ff00000 /* Reserved, bit(s):30:20, default(000h), access(RO) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_DMA_CONTEXT	0x000e0000 /* DMA Context Number. Specifies the DMA context number allocated to this I2S channel. The software must set up this field differently for each I2S interface to avoid unpredictable behavior. 000: Context 0 001: Context 1 010: Context 2 011: Context 3., bit(s):19:17, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_RESERVED_16	(1<<16) /* == 0x00010000: Reserved , bit(s):16, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_I2S_PIN2	0x0000c000 /* Disable I2S Transmit Data Pin 2: 00: Transmit Data Pin 2, Both Channels are Enabled 01: Transmit Data Pin 2, Left Channel is Enabled; Right  channel output will be 0-filled 10: Transmit Data Pin 2, Right channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 2 is Disabled, bit(s):15:14, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_I2S_PIN1	0x00003000 /* Disable I2S Transmit Data Pin 1: 00: Transmit Data Pin 1, Both Channels are Enabled 01: Transmit Data Pin 1, Left  Channel is Enabled; Right channel output will be 0-filled 10: Transmit Data Pin 1, Right  Channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 1 is Disabled, bit(s):13:12, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_I2S_PIN0	0x00000c00 /* Disable I2S Transmit Data Pin 0: 00: Transmit Data Pin 0, Both Channels are Enabled 01: Transmit Data Pin 0, Left  Channel is Enabled; Right channel output will be 0-filled 10: Transmit Data Pin 0, Right  Channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 0 is Disabled, bit(s):11:10, default(0H), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_MODE	0x00000300 /* Data storage Mode: 00: 7.1 Data 01: Stereo Mode 10: Left-Channel Mono 11: Right-Channel Mono, bit(s):9:8, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_SAMPLE_SIZE	(1<<7) /* == 0x00000080: Data Sample Size 0: 16-bit data sample 1: 24-bit data sample, bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_I2S_PIN3	0x00000060 /* Disable I2S Transmit Data Pin 3: 00: Transmit Data Pin 3, Both Channels are Enabled 01: Transmit Data Pin 3, Left Channel is Enabled; Right  channel output will be 0-filled 10: Transmit Data Pin 3, Right channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 3 is Disabled, bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_RESERVED_3	(1<<3) /* == 0x00000008: Reserved, bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_TX0SACR1_RESERVED_2	(1<<2) /* == 0x00000004: Reserved, bit(s):2, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SACR1_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SACR1_TX0_ALT_MODE	(1<<0) /* == 0x00000001: Specify Alternate Mode (I2S or MSB-Justified) Operation: 0: Select I2S Operation Mode 1: Select MSB-Justified Operation Mode, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_SPDIF_VALIDITY	 0x2004, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_TX0SACR1_RESERVED_30_20	 0x2004, 20, 11, 0x7ff00000
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_DMA_CONTEXT	 0x2004, 17, 3, 0x000e0000
	#define BITFIELD_AUD_IO_TX0SACR1_RESERVED_16	 0x2004, 16, 1, 0x00010000
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_I2S_PIN2	 0x2004, 14, 2, 0x0000c000
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_I2S_PIN1	 0x2004, 12, 2, 0x00003000
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_I2S_PIN0	 0x2004, 10, 2, 0x00000c00
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_MODE	 0x2004, 8, 2, 0x00000300
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_SAMPLE_SIZE	 0x2004, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_I2S_PIN3	 0x2004, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_TX0SACR1_RESERVED_4	 0x2004, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX0SACR1_RESERVED_3	 0x2004, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX0SACR1_RESERVED_2	 0x2004, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX0SACR1_RESERVED_1	 0x2004, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX0SACR1_TX0_ALT_MODE	 0x2004, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX0SASR0	0x2008 /* TX0SASR0 - Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUD_IO_TX0SASR0	 0x2008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SASR0 */
	#define BLSB_AUD_IO_TX0SASR0_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX0SASR0_RESERVED_10_8	8
	#define BLSB_AUD_IO_TX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	7
	#define BLSB_AUD_IO_TX0SASR0_RESERVED_6	6
	#define BLSB_AUD_IO_TX0SASR0_TX0_FIFO_UNDERRUN	5
	#define BLSB_AUD_IO_TX0SASR0_RESERVED_4	4
	#define BLSB_AUD_IO_TX0SASR0_TX0_FIFO_SVC_REQ	3
	#define BLSB_AUD_IO_TX0SASR0_TX0_BUSY	2
	#define BLSB_AUD_IO_TX0SASR0_RESERVED_1	1
	#define BLSB_AUD_IO_TX0SASR0_TX0_FIFO_NOT_EMPTY	0
	/* Register Bit Widths for AUD_IO_TX0SASR0 */
	#define BWID_AUD_IO_TX0SASR0_RESERVED_31_8	24
	#define BWID_AUD_IO_TX0SASR0_RESERVED_10_8	3
	#define BWID_AUD_IO_TX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	1
	#define BWID_AUD_IO_TX0SASR0_RESERVED_6	1
	#define BWID_AUD_IO_TX0SASR0_TX0_FIFO_UNDERRUN	1
	#define BWID_AUD_IO_TX0SASR0_RESERVED_4	1
	#define BWID_AUD_IO_TX0SASR0_TX0_FIFO_SVC_REQ	1
	#define BWID_AUD_IO_TX0SASR0_TX0_BUSY	1
	#define BWID_AUD_IO_TX0SASR0_RESERVED_1	1
	#define BWID_AUD_IO_TX0SASR0_TX0_FIFO_NOT_EMPTY	1
	/* Register Bit MASKS for AUD_IO_TX0SASR0 */
	#define BMSK_AUD_IO_TX0SASR0_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_RESERVED_10_8	0x00000700 /* Reserved, bit(s):10:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	(1<<7) /* == 0x00000080: I2S Controller Clean Shutdown. When this value is '1', the I2SC is in the process of clean shutdown. When this value is '1', no writes ot the I2SC registers are allowed. When this bit is '0' and SACR0.ENB bit value is '0', then the unit is shutdown. When this bit is '0' and SACR0.ENB bit value is '1', then the I2SC is in enabled mode. When '0' is written to SACR0.ENB, I2SOFF will be '1' until all the data in the transmit FIFO is transmitted to CODEC and all the data in receive FIFO is read by the DMA., bit(s):7, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_RESERVED_6	(1<<6) /* == 0x00000040: Reserved, bit(s):6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_TX0_FIFO_UNDERRUN	(1<<5) /* == 0x00000020: Transmit FIFO Underrun: 0: Transmit FIFO has not experienced an underrun.1: I2S attempted data read from an empty Transmit FIFO - Can interrupt processor if bit5 of Serial Audio Interrupt Mask Register is set. - Cleared by writing a '1' to bit5 of Serial Audio Interrupt Clear Register., bit(s):5, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_TX0_FIFO_SVC_REQ	(1<<3) /* == 0x00000008: Transmit FIFO Service Request: 0: Transmit FIFO level exceeds TFL threshold, or I2S disabled 1: Transmit FIFO level is at or below TFL threshold - Can interrupt processor if bit3 of Serial Audio Interrupt Mask Register is set. - Cleared automatically when # of Transmit FIFO entries >= (TFTH + 1), bit(s):3, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_TX0_BUSY	(1<<2) /* == 0x00000004: TX Busy: 0: TX is idle or disabled 1:TX currently transmitting a frame , bit(s):2, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SASR0_TX0_FIFO_NOT_EMPTY	(1<<0) /* == 0x00000001: Transmit FIFO not full 0: Transmit FIFO is full 1: Transmit FIFO is not full, bit(s):0, default(1b), access(RO) */
	/* Register BITFIELD for AUD_IO_TX0SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SASR0_RESERVED_31_8	 0x2008, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX0SASR0_RESERVED_10_8	 0x2008, 8, 3, 0x00000700
	#define BITFIELD_AUD_IO_TX0SASR0_I2S_CNTL_CLEAN_SHUTDOWN	 0x2008, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_TX0SASR0_RESERVED_6	 0x2008, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_TX0SASR0_TX0_FIFO_UNDERRUN	 0x2008, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX0SASR0_RESERVED_4	 0x2008, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX0SASR0_TX0_FIFO_SVC_REQ	 0x2008, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX0SASR0_TX0_BUSY	 0x2008, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX0SASR0_RESERVED_1	 0x2008, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX0SASR0_TX0_FIFO_NOT_EMPTY	 0x2008, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX0SAIMR	0x200c /* TX0SAIMR - Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUD_IO_TX0SAIMR	 0x200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SAIMR */
	#define BLSB_AUD_IO_TX0SAIMR_RESERVED_31_9	9
	#define BLSB_AUD_IO_TX0SAIMR_TX0_SPDIF_BCLK_COMPLETE_INT_EN	8
	#define BLSB_AUD_IO_TX0SAIMR_TX0_FIFO_UNDERRUN_INT_EN	5
	#define BLSB_AUD_IO_TX0SAIMR_RESERVED_4	4
	#define BLSB_AUD_IO_TX0SAIMR_TX0_FIFO_SVC_REQ_INT_EN	3
	#define BLSB_AUD_IO_TX0SAIMR_RESERVED_2_0	0
	/* Register Bit Widths for AUD_IO_TX0SAIMR */
	#define BWID_AUD_IO_TX0SAIMR_RESERVED_31_9	23
	#define BWID_AUD_IO_TX0SAIMR_TX0_SPDIF_BCLK_COMPLETE_INT_EN	1
	#define BWID_AUD_IO_TX0SAIMR_TX0_FIFO_UNDERRUN_INT_EN	1
	#define BWID_AUD_IO_TX0SAIMR_RESERVED_4	1
	#define BWID_AUD_IO_TX0SAIMR_TX0_FIFO_SVC_REQ_INT_EN	1
	#define BWID_AUD_IO_TX0SAIMR_RESERVED_2_0	3
	/* Register Bit MASKS for AUD_IO_TX0SAIMR */
	#define BMSK_AUD_IO_TX0SAIMR_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAIMR_TX0_SPDIF_BCLK_COMPLETE_INT_EN	(1<<8) /* == 0x00000100: Enable S/PDIF Block complete interrupt, bit(s):8, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX0SAIMR_TX0_FIFO_UNDERRUN_INT_EN	(1<<5) /* == 0x00000020: Enable Transmit FIFO under-run condition based interrupt, bit(s):5, default(0), access(RW) */
	#define BMSK_AUD_IO_TX0SAIMR_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAIMR_TX0_FIFO_SVC_REQ_INT_EN	(1<<3) /* == 0x00000008: Enable Transmit FIFO service request based interrupt, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX0SAIMR_RESERVED_2_0	0x00000007 /* Reserved, bit(s):2:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_TX0SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SAIMR_RESERVED_31_9	 0x200c, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_TX0SAIMR_TX0_SPDIF_BCLK_COMPLETE_INT_EN	 0x200c, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_TX0SAIMR_TX0_FIFO_UNDERRUN_INT_EN	 0x200c, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX0SAIMR_RESERVED_4	 0x200c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX0SAIMR_TX0_FIFO_SVC_REQ_INT_EN	 0x200c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX0SAIMR_RESERVED_2_0	 0x200c, 0, 3, 0x00000007
#define ROFF_AUD_IO_TX0SAISR	0x2010 /* TX0SAISR - Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUD_IO_TX0SAISR	 0x2010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SAISR */
	#define BLSB_AUD_IO_TX0SAISR_RESERVED_31_9	9
	#define BLSB_AUD_IO_TX0SAISR_TX0_SPDIF_BLK_COMPLETE_INT	8
	#define BLSB_AUD_IO_TX0SAISR_RESERVED_7_6	6
	#define BLSB_AUD_IO_TX0SAISR_TX0_CLEAR_FIFO_UNDERRUN_INT	5
	#define BLSB_AUD_IO_TX0SAISR_RESERVED_4	4
	#define BLSB_AUD_IO_TX0SAISR_RESERVED_3	3
	#define BLSB_AUD_IO_TX0SAISR_RESERVED_2_0	0
	/* Register Bit Widths for AUD_IO_TX0SAISR */
	#define BWID_AUD_IO_TX0SAISR_RESERVED_31_9	23
	#define BWID_AUD_IO_TX0SAISR_TX0_SPDIF_BLK_COMPLETE_INT	1
	#define BWID_AUD_IO_TX0SAISR_RESERVED_7_6	2
	#define BWID_AUD_IO_TX0SAISR_TX0_CLEAR_FIFO_UNDERRUN_INT	1
	#define BWID_AUD_IO_TX0SAISR_RESERVED_4	1
	#define BWID_AUD_IO_TX0SAISR_RESERVED_3	1
	#define BWID_AUD_IO_TX0SAISR_RESERVED_2_0	3
	/* Register Bit MASKS for AUD_IO_TX0SAISR */
	#define BMSK_AUD_IO_TX0SAISR_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAISR_TX0_SPDIF_BLK_COMPLETE_INT	(1<<8) /* == 0x00000100:  SPDIF Block Transmit Complete Interrupt. Writing a '1' to this location clears the interrupt., bit(s):8, default(0), access(RW) */
	#define BMSK_AUD_IO_TX0SAISR_RESERVED_7_6	0x000000c0 /* Reserved, bit(s):7:6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAISR_TX0_CLEAR_FIFO_UNDERRUN_INT	(1<<5) /* == 0x00000020: Clear Transmit FIFO underrun interrupt and TUR status bit SASR0. Writing a '1' to this location clears the interrupt and SASR0 bit 5, bit(s):5, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX0SAISR_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAISR_RESERVED_3	(1<<3) /* == 0x00000008: Reserved , bit(s):3, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAISR_RESERVED_2_0	0x00000007 /* Reserved, bit(s):2:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_TX0SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SAISR_RESERVED_31_9	 0x2010, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_TX0SAISR_TX0_SPDIF_BLK_COMPLETE_INT	 0x2010, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_TX0SAISR_RESERVED_7_6	 0x2010, 6, 2, 0x000000c0
	#define BITFIELD_AUD_IO_TX0SAISR_TX0_CLEAR_FIFO_UNDERRUN_INT	 0x2010, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX0SAISR_RESERVED_4	 0x2010, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX0SAISR_RESERVED_3	 0x2010, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX0SAISR_RESERVED_2_0	 0x2010, 0, 3, 0x00000007
#define ROFF_AUD_IO_TX0SADIV	0x2014 /* TX0SADIV - Audio Clock Divider Register */ 
	#define BITFIELD_AUD_IO_TX0SADIV	 0x2014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SADIV */
	#define BLSB_AUD_IO_TX0SADIV_UNDEFINED_31_7	7
	#define BLSB_AUD_IO_TX0SADIV_TX0_AUD_CLK_DIV	0
	/* Register Bit Widths for AUD_IO_TX0SADIV */
	#define BWID_AUD_IO_TX0SADIV_UNDEFINED_31_7	25
	#define BWID_AUD_IO_TX0SADIV_TX0_AUD_CLK_DIV	7
	/* Register Bit MASKS for AUD_IO_TX0SADIV */
	#define BMSK_AUD_IO_TX0SADIV_UNDEFINED_31_7	0xffffff80 /* Reserved, bit(s):31:7, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SADIV_TX0_AUD_CLK_DIV	0x0000007f /* Audio Clock Divider, bit(s):6:0, default(06h), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SADIV_UNDEFINED_31_7	 0x2014, 7, 25, 0xffffff80
	#define BITFIELD_AUD_IO_TX0SADIV_TX0_AUD_CLK_DIV	 0x2014, 0, 7, 0x0000007f
#define ROFF_AUD_IO_TX0SATR	0x2018 /* TX0SATR - Serial Audio Transmit Register */ 
	#define BITFIELD_AUD_IO_TX0SATR	 0x2018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SAFTH	0x201c /* TX0SAFTH - Serial Audio FIFO Threshold Register */ 
	#define BITFIELD_AUD_IO_TX0SAFTH	 0x201c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SAFTH */
	#define BLSB_AUD_IO_TX0SAFTH_RESERVED_31_16	16
	#define BLSB_AUD_IO_TX0SAFTH_TX0_LOWER_FIFO_THRSH	0
	/* Register Bit Widths for AUD_IO_TX0SAFTH */
	#define BWID_AUD_IO_TX0SAFTH_RESERVED_31_16	16
	#define BWID_AUD_IO_TX0SAFTH_TX0_LOWER_FIFO_THRSH	16
	/* Register Bit MASKS for AUD_IO_TX0SAFTH */
	#define BMSK_AUD_IO_TX0SAFTH_RESERVED_31_16	0xffff0000 /* Reserved, bit(s):31:16, default(0), access(RW) */
	#define BMSK_AUD_IO_TX0SAFTH_TX0_LOWER_FIFO_THRSH	0x0000ffff /* Lower FIFO Threshold of Transmit Channel in words, bit(s):15:0, default(0000h), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SAFTH_RESERVED_31_16	 0x201c, 16, 16, 0xffff0000
	#define BITFIELD_AUD_IO_TX0SAFTH_TX0_LOWER_FIFO_THRSH	 0x201c, 0, 16, 0x0000ffff
#define ROFF_AUD_IO_TX0SAFL	0x2020 /* TX0SAFL - Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUD_IO_TX0SAFL	 0x2020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SAFL */
	#define BLSB_AUD_IO_TX0SAFL_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX0SAFL_TX0_FIFO_LEVEL	0
	/* Register Bit Widths for AUD_IO_TX0SAFL */
	#define BWID_AUD_IO_TX0SAFL_RESERVED_31_8	24
	#define BWID_AUD_IO_TX0SAFL_TX0_FIFO_LEVEL	8
	/* Register Bit MASKS for AUD_IO_TX0SAFL */
	#define BMSK_AUD_IO_TX0SAFL_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX0SAFL_TX0_FIFO_LEVEL	0x000000ff /* FIFO Level of Transmit Channel. The number of words that are currently stored in the FIFO. , bit(s):7:0, default(000h), access(RO) */
	/* Register BITFIELD for AUD_IO_TX0SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SAFL_RESERVED_31_8	 0x2020, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX0SAFL_TX0_FIFO_LEVEL	 0x2020, 0, 8, 0x000000ff
#define ROFF_AUD_IO_TX0SASUD0	0x2040 /* TX0SASUD0 -  S/PDIF transmit user data bits 31:0 (for SASUD0) - bytes 0-3 (transmitted first)  */ 
	#define BITFIELD_AUD_IO_TX0SASUD0	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD1	0x2044 /* TX0SASUD1 -  S/PDIF transmit user data bits 63:32 (for SASUD1) */ 
	#define BITFIELD_AUD_IO_TX0SASUD1	 0x2044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD2	0x2048 /* TX0SASUD2 -  S/PDIF transmit user data bits 96:64 (for SASUD2) */ 
	#define BITFIELD_AUD_IO_TX0SASUD2	 0x2048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD3	0x204c /* TX0SASUD3 -  S/PDIF transmit user data bits 127:97 (for SASUD3) */ 
	#define BITFIELD_AUD_IO_TX0SASUD3	 0x204c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD4	0x2050 /* TX0SASUD4 -  S/PDIF transmit user data bits 159 :128 (for SASUD4) */ 
	#define BITFIELD_AUD_IO_TX0SASUD4	 0x2050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD5	0x2054 /* TX0SASUD5 -  S/PDIF transmit user data bits 191:160 (for SASUD5) */ 
	#define BITFIELD_AUD_IO_TX0SASUD5	 0x2054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD6	0x2058 /* TX0SASUD6 -  S/PDIF transmit user data bits 223:191 (for SASUD6) */ 
	#define BITFIELD_AUD_IO_TX0SASUD6	 0x2058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD7	0x205c /* TX0SASUD7 -  S/PDIF transmit user data bits 255:224 (for SASUD7) */ 
	#define BITFIELD_AUD_IO_TX0SASUD7	 0x205c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD8	0x2060 /* TX0SASUD8 -  S/PDIF transmit user data bits 287:256 (for SASUD8) */ 
	#define BITFIELD_AUD_IO_TX0SASUD8	 0x2060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD9	0x2064 /* TX0SASUD9 -  S/PDIF transmit user data bits 319:288 (for SASUD9) */ 
	#define BITFIELD_AUD_IO_TX0SASUD9	 0x2064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD10	0x2068 /* TX0SASUD10 - S/PDIF transmit user data bits 351:320 (for SASUD10) */ 
	#define BITFIELD_AUD_IO_TX0SASUD10	 0x2068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUD11	0x206c /* TX0SASUD11 - S/PDIF transmit user data bits 383:352 (for SASUD11) - transmitted last           */ 
	#define BITFIELD_AUD_IO_TX0SASUD11	 0x206c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASUDC	0x2070 /* TX0SASUDC - S/PDIF transmit user data control Register */ 
	#define BITFIELD_AUD_IO_TX0SASUDC	 0x2070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SASUDC */
	#define BLSB_AUD_IO_TX0SASUDC_RESERVED_31_1	1
	#define BLSB_AUD_IO_TX0SASUDC_TX0_LOAD_SASUD_TO_SPDIF	0
	/* Register Bit Widths for AUD_IO_TX0SASUDC */
	#define BWID_AUD_IO_TX0SASUDC_RESERVED_31_1	31
	#define BWID_AUD_IO_TX0SASUDC_TX0_LOAD_SASUD_TO_SPDIF	1
	/* Register Bit MASKS for AUD_IO_TX0SASUDC */
	#define BMSK_AUD_IO_TX0SASUDC_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0), access(RV) */
	#define BMSK_AUD_IO_TX0SASUDC_TX0_LOAD_SASUD_TO_SPDIF	(1<<0) /* == 0x00000001: Load the User Data registers (SASUD0 - SASUD11)into buffer for insertion into S/PDIF data stream. This bit will be automatically reset to \'0\'., bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SASUDC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SASUDC_RESERVED_31_1	 0x2070, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_IO_TX0SASUDC_TX0_LOAD_SASUD_TO_SPDIF	 0x2070, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX0SASCS0	0x2080 /* TX0SASCS0 - S/PDIF transmit channel status Register. Channel Status bits 31:0 (for SASCS0) - bytes 0-3 (Transmitted first) */ 
	#define BITFIELD_AUD_IO_TX0SASCS0	 0x2080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX0SASCS1	0x2084 /* TX0SASCS1 - S/PDIF transmit channel status Register. Channel Status bits 63:32 (for SASCS1) */ 
	#define BITFIELD_AUD_IO_TX0SASCS1	 0x2084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SASCS1 */
	#define BLSB_AUD_IO_TX0SASCS1_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX0SASCS1_WRITABLE	0
	/* Register Bit Widths for AUD_IO_TX0SASCS1 */
	#define BWID_AUD_IO_TX0SASCS1_RESERVED_31_8	24
	#define BWID_AUD_IO_TX0SASCS1_WRITABLE	8
	/* Register Bit MASKS for AUD_IO_TX0SASCS1 */
	#define BMSK_AUD_IO_TX0SASCS1_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(R0) */
	#define BMSK_AUD_IO_TX0SASCS1_WRITABLE	0x000000ff /* TX0SASCS1 - S/PDIF transmit channel status Register. Channel Status bits 40:32 (40 bits only), bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SASCS1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SASCS1_RESERVED_31_8	 0x2084, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX0SASCS1_WRITABLE	 0x2084, 0, 8, 0x000000ff
#define ROFF_AUD_IO_TX0SASCSC	0x208c /* TX0SASCSC - S/PDIF transmit Channel status ctrl Register */ 
	#define BITFIELD_AUD_IO_TX0SASCSC	 0x208c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX0SASCSC */
	#define BLSB_AUD_IO_TX0SASCSC_RESERVED_31_1	1
	#define BLSB_AUD_IO_TX0SASCSC_TX0_LOAD_CNTL_STAT_REG	0
	/* Register Bit Widths for AUD_IO_TX0SASCSC */
	#define BWID_AUD_IO_TX0SASCSC_RESERVED_31_1	31
	#define BWID_AUD_IO_TX0SASCSC_TX0_LOAD_CNTL_STAT_REG	1
	/* Register Bit MASKS for AUD_IO_TX0SASCSC */
	#define BMSK_AUD_IO_TX0SASCSC_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0), access(RV) */
	#define BMSK_AUD_IO_TX0SASCSC_TX0_LOAD_CNTL_STAT_REG	(1<<0) /* == 0x00000001: Load the Control Status registers (TX0SASCS0 - TX0SASCS5)into buffer for insertion into S/PDIF data stream. This bit will be automatically reset to '0'. , bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX0SASCSC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX0SASCSC_RESERVED_31_1	 0x208c, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_IO_TX0SASCSC_TX0_LOAD_CNTL_STAT_REG	 0x208c, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX1SACR0	0x2100 /* TX1SACR0 - Global Control Register */ 
	#define BITFIELD_AUD_IO_TX1SACR0	 0x2100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SACR0 */
	#define BLSB_AUD_IO_TX1SACR0_RESERVED_31	31
	#define BLSB_AUD_IO_TX1SACR0_RESERVED_30	30
	#define BLSB_AUD_IO_TX1SACR0_RESERVED_29_6	6
	#define BLSB_AUD_IO_TX1SACR0_TX1_OUTPUT_SEL	5
	#define BLSB_AUD_IO_TX1SACR0_UNDEFINED_4	4
	#define BLSB_AUD_IO_TX1SACR0_TX1_FIFO_RESET	3
	#define BLSB_AUD_IO_TX1SACR0_RESERVED_2	2
	#define BLSB_AUD_IO_TX1SACR0_RESERVED_1	1
	#define BLSB_AUD_IO_TX1SACR0_TX1_ENABLE	0
	/* Register Bit Widths for AUD_IO_TX1SACR0 */
	#define BWID_AUD_IO_TX1SACR0_RESERVED_31	1
	#define BWID_AUD_IO_TX1SACR0_RESERVED_30	1
	#define BWID_AUD_IO_TX1SACR0_RESERVED_29_6	24
	#define BWID_AUD_IO_TX1SACR0_TX1_OUTPUT_SEL	2
	#define BWID_AUD_IO_TX1SACR0_UNDEFINED_4	1
	#define BWID_AUD_IO_TX1SACR0_TX1_FIFO_RESET	1
	#define BWID_AUD_IO_TX1SACR0_RESERVED_2	1
	#define BWID_AUD_IO_TX1SACR0_RESERVED_1	1
	#define BWID_AUD_IO_TX1SACR0_TX1_ENABLE	1
	/* Register Bit MASKS for AUD_IO_TX1SACR0 */
	#define BMSK_AUD_IO_TX1SACR0_RESERVED_31	(1<<31) /* == 0x80000000: Reserved, bit(s):31, default(0H), access(RW) */
	#define BMSK_AUD_IO_TX1SACR0_RESERVED_30	(1<<30) /* == 0x40000000: Reserved, bit(s):30, default(0H), access(RO) */
	#define BMSK_AUD_IO_TX1SACR0_RESERVED_29_6	0x3fffffc0 /* Reserved, bit(s):29:6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SACR0_TX1_OUTPUT_SEL	0x00000060 /* Select outputs 00: 7.1 I2S output 01: stereo I2S output 0 10: not used  11: S/PDIF output, bit(s):6:5, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR0_UNDEFINED_4	(1<<4) /* == 0x00000010: , bit(s):4, default(), access() */
	#define BMSK_AUD_IO_TX1SACR0_TX1_FIFO_RESET	(1<<3) /* == 0x00000008: Resets FIFOs logic and all registers, except this register (SACR0): 0: Not reset 1: Reset is Active Other Registers , bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR0_RESERVED_2	(1<<2) /* == 0x00000004: Reserved , bit(s):2, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SACR0_TX1_ENABLE	(1<<0) /* == 0x00000001: EnableTX function: 0: TX channel is disabled 1: TX channel is enabled, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SACR0_RESERVED_31	 0x2100, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_TX1SACR0_RESERVED_30	 0x2100, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_TX1SACR0_RESERVED_29_6	 0x2100, 6, 24, 0x3fffffc0
	#define BITFIELD_AUD_IO_TX1SACR0_TX1_OUTPUT_SEL	 0x2100, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_TX1SACR0_UNDEFINED_4	 0x2100, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX1SACR0_TX1_FIFO_RESET	 0x2100, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX1SACR0_RESERVED_2	 0x2100, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX1SACR0_RESERVED_1	 0x2100, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX1SACR0_TX1_ENABLE	 0x2100, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX1SACR1	0x2104 /* TX1SACR1 - Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUD_IO_TX1SACR1	 0x2104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SACR1 */
	#define BLSB_AUD_IO_TX1SACR1_TX1_SPDIF_VALIDITY	31
	#define BLSB_AUD_IO_TX1SACR1_RESERVED_30_20	20
	#define BLSB_AUD_IO_TX1SACR1_TX1_DMA_CONTEXT	17
	#define BLSB_AUD_IO_TX1SACR1_RESERVED_16	16
	#define BLSB_AUD_IO_TX1SACR1_TX1_I2S_PIN2	14
	#define BLSB_AUD_IO_TX1SACR1_TX1_I2S_PIN1	12
	#define BLSB_AUD_IO_TX1SACR1_TX1_I2S_PIN0	10
	#define BLSB_AUD_IO_TX1SACR1_TX1_MODE	8
	#define BLSB_AUD_IO_TX1SACR1_TX1_SAMPLE_SIZE	7
	#define BLSB_AUD_IO_TX1SACR1_TX1_I2S_PIN3	5
	#define BLSB_AUD_IO_TX1SACR1_RESERVED_4	4
	#define BLSB_AUD_IO_TX1SACR1_RESERVED_3	3
	#define BLSB_AUD_IO_TX1SACR1_RESERVED_2	2
	#define BLSB_AUD_IO_TX1SACR1_RESERVED_1	1
	#define BLSB_AUD_IO_TX1SACR1_TX1_ALT_MODE	0
	/* Register Bit Widths for AUD_IO_TX1SACR1 */
	#define BWID_AUD_IO_TX1SACR1_TX1_SPDIF_VALIDITY	1
	#define BWID_AUD_IO_TX1SACR1_RESERVED_30_20	11
	#define BWID_AUD_IO_TX1SACR1_TX1_DMA_CONTEXT	3
	#define BWID_AUD_IO_TX1SACR1_RESERVED_16	1
	#define BWID_AUD_IO_TX1SACR1_TX1_I2S_PIN2	2
	#define BWID_AUD_IO_TX1SACR1_TX1_I2S_PIN1	2
	#define BWID_AUD_IO_TX1SACR1_TX1_I2S_PIN0	2
	#define BWID_AUD_IO_TX1SACR1_TX1_MODE	2
	#define BWID_AUD_IO_TX1SACR1_TX1_SAMPLE_SIZE	1
	#define BWID_AUD_IO_TX1SACR1_TX1_I2S_PIN3	2
	#define BWID_AUD_IO_TX1SACR1_RESERVED_4	1
	#define BWID_AUD_IO_TX1SACR1_RESERVED_3	1
	#define BWID_AUD_IO_TX1SACR1_RESERVED_2	1
	#define BWID_AUD_IO_TX1SACR1_RESERVED_1	1
	#define BWID_AUD_IO_TX1SACR1_TX1_ALT_MODE	1
	/* Register Bit MASKS for AUD_IO_TX1SACR1 */
	#define BMSK_AUD_IO_TX1SACR1_TX1_SPDIF_VALIDITY	(1<<31) /* == 0x80000000: SPDIF validity bit, bit(s):31, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_RESERVED_30_20	0x7ff00000 /* Reserved, bit(s):30:20, default(000h), access(RO) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_DMA_CONTEXT	0x000e0000 /* DMA Context Number. Specifies the DMA context number allocated to this I2S channel. The software must set up this field differently for each I2S interface to avoid unpredictable behavior. 000: Context 0 001: Context 1 010: Context 2 011: Context 3., bit(s):19:17, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_RESERVED_16	(1<<16) /* == 0x00010000: Reserved , bit(s):16, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_I2S_PIN2	0x0000c000 /* Disable I2S Transmit Data Pin 2: 00: Transmit Data Pin 2, Both Channels are Enabled 01: Transmit Data Pin 2, Left Channel is Enabled; Right  channel output will be 0-filled 10: Transmit Data Pin 2, Right channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 2 is Disabled, bit(s):15:14, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_I2S_PIN1	0x00003000 /* Disable I2S Transmit Data Pin 1: 00: Transmit Data Pin 1, Both Channels are Enabled 01: Transmit Data Pin 1, Left  Channel is Enabled; Right channel output will be 0-filled 10: Transmit Data Pin 1, Right  Channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 1 is Disabled, bit(s):13:12, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_I2S_PIN0	0x00000c00 /* Disable I2S Transmit Data Pin 0: 00: Transmit Data Pin 0, Both Channels are Enabled 01: Transmit Data Pin 0, Left  Channel is Enabled; Right channel output will be 0-filled 10: Transmit Data Pin 0, Right  Channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 0 is Disabled, bit(s):11:10, default(0H), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_MODE	0x00000300 /* Data storage Mode: 00: 7.1 Data 01: Stereo Mode 10: Left-Channel Mono 11: Right-Channel Mono, bit(s):9:8, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_SAMPLE_SIZE	(1<<7) /* == 0x00000080: Data Sample Size 0: 16-bit data sample 1: 24-bit data sample, bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_I2S_PIN3	0x00000060 /* Disable I2S Transmit Data Pin 3: 00: Transmit Data Pin 3, Both Channels are Enabled 01: Transmit Data Pin 3, Left Channel is Enabled; Right  channel output will be 0-filled 10: Transmit Data Pin 3, Right channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 3 is Disabled, bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_RESERVED_3	(1<<3) /* == 0x00000008: Reserved, bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_TX1SACR1_RESERVED_2	(1<<2) /* == 0x00000004: Reserved, bit(s):2, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SACR1_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SACR1_TX1_ALT_MODE	(1<<0) /* == 0x00000001: Specify Alternate Mode (I2S or MSB-Justified) Operation: 0: Select I2S Operation Mode 1: Select MSB-Justified Operation Mode, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_SPDIF_VALIDITY	 0x2104, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_TX1SACR1_RESERVED_30_20	 0x2104, 20, 11, 0x7ff00000
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_DMA_CONTEXT	 0x2104, 17, 3, 0x000e0000
	#define BITFIELD_AUD_IO_TX1SACR1_RESERVED_16	 0x2104, 16, 1, 0x00010000
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_I2S_PIN2	 0x2104, 14, 2, 0x0000c000
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_I2S_PIN1	 0x2104, 12, 2, 0x00003000
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_I2S_PIN0	 0x2104, 10, 2, 0x00000c00
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_MODE	 0x2104, 8, 2, 0x00000300
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_SAMPLE_SIZE	 0x2104, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_I2S_PIN3	 0x2104, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_TX1SACR1_RESERVED_4	 0x2104, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX1SACR1_RESERVED_3	 0x2104, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX1SACR1_RESERVED_2	 0x2104, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX1SACR1_RESERVED_1	 0x2104, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX1SACR1_TX1_ALT_MODE	 0x2104, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX1SASR0	0x2108 /* TX1SASR0 - Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUD_IO_TX1SASR0	 0x2108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SASR0 */
	#define BLSB_AUD_IO_TX1SASR0_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX1SASR0_RESERVED_10_8	8
	#define BLSB_AUD_IO_TX1SASR0_I2S_CNTL_CLEAN_SHUTDOWN	7
	#define BLSB_AUD_IO_TX1SASR0_RESERVED_6	6
	#define BLSB_AUD_IO_TX1SASR0_TX1_FIFO_UNDERRUN	5
	#define BLSB_AUD_IO_TX1SASR0_RESERVED_4	4
	#define BLSB_AUD_IO_TX1SASR0_TX1_FIFO_SVC_REQ	3
	#define BLSB_AUD_IO_TX1SASR0_TX1_BUSY	2
	#define BLSB_AUD_IO_TX1SASR0_RESERVED_1	1
	#define BLSB_AUD_IO_TX1SASR0_TX1_FIFO_NOT_EMPTY	0
	/* Register Bit Widths for AUD_IO_TX1SASR0 */
	#define BWID_AUD_IO_TX1SASR0_RESERVED_31_8	24
	#define BWID_AUD_IO_TX1SASR0_RESERVED_10_8	3
	#define BWID_AUD_IO_TX1SASR0_I2S_CNTL_CLEAN_SHUTDOWN	1
	#define BWID_AUD_IO_TX1SASR0_RESERVED_6	1
	#define BWID_AUD_IO_TX1SASR0_TX1_FIFO_UNDERRUN	1
	#define BWID_AUD_IO_TX1SASR0_RESERVED_4	1
	#define BWID_AUD_IO_TX1SASR0_TX1_FIFO_SVC_REQ	1
	#define BWID_AUD_IO_TX1SASR0_TX1_BUSY	1
	#define BWID_AUD_IO_TX1SASR0_RESERVED_1	1
	#define BWID_AUD_IO_TX1SASR0_TX1_FIFO_NOT_EMPTY	1
	/* Register Bit MASKS for AUD_IO_TX1SASR0 */
	#define BMSK_AUD_IO_TX1SASR0_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_RESERVED_10_8	0x00000700 /* Reserved, bit(s):10:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_I2S_CNTL_CLEAN_SHUTDOWN	(1<<7) /* == 0x00000080: I2S Controller Clean Shutdown. When this value is '1', the I2SC is in the process of clean shutdown. When this value is '1', no writes ot the I2SC registers are allowed. When this bit is '0' and SACR0.ENB bit value is '0', then the unit is shutdown. When this bit is '0' and SACR0.ENB bit value is '1', then the I2SC is in enabled mode. When '0' is written to SACR0.ENB, I2SOFF will be '1' until all the data in the transmit FIFO is transmitted to CODEC and all the data in receive FIFO is read by the DMA., bit(s):7, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_RESERVED_6	(1<<6) /* == 0x00000040: Reserved, bit(s):6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_TX1_FIFO_UNDERRUN	(1<<5) /* == 0x00000020: Transmit FIFO Underrun: 0: Transmit FIFO has not experienced an underrun.1: I2S attempted data read from an empty Transmit FIFO - Can interrupt processor if bit5 of Serial Audio Interrupt Mask Register is set. - Cleared by writing a '1' to bit5 of Serial Audio Interrupt Clear Register., bit(s):5, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_TX1_FIFO_SVC_REQ	(1<<3) /* == 0x00000008: Transmit FIFO Service Request: 0: Transmit FIFO level exceeds TFL threshold, or I2S disabled 1: Transmit FIFO level is at or below TFL threshold - Can interrupt processor if bit3 of Serial Audio Interrupt Mask Register is set. - Cleared automatically when # of Transmit FIFO entries >= (TFTH + 1), bit(s):3, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_TX1_BUSY	(1<<2) /* == 0x00000004: TX Busy: 0: TX is idle or disabled 1:TX currently transmitting a frame , bit(s):2, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SASR0_TX1_FIFO_NOT_EMPTY	(1<<0) /* == 0x00000001: Transmit FIFO not full 0: Transmit FIFO is full 1: Transmit FIFO is not full, bit(s):0, default(1b), access(RO) */
	/* Register BITFIELD for AUD_IO_TX1SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SASR0_RESERVED_31_8	 0x2108, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX1SASR0_RESERVED_10_8	 0x2108, 8, 3, 0x00000700
	#define BITFIELD_AUD_IO_TX1SASR0_I2S_CNTL_CLEAN_SHUTDOWN	 0x2108, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_TX1SASR0_RESERVED_6	 0x2108, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_TX1SASR0_TX1_FIFO_UNDERRUN	 0x2108, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX1SASR0_RESERVED_4	 0x2108, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX1SASR0_TX1_FIFO_SVC_REQ	 0x2108, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX1SASR0_TX1_BUSY	 0x2108, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX1SASR0_RESERVED_1	 0x2108, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX1SASR0_TX1_FIFO_NOT_EMPTY	 0x2108, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX1SAIMR	0x210c /* TX1SAIMR - Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUD_IO_TX1SAIMR	 0x210c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SAIMR */
	#define BLSB_AUD_IO_TX1SAIMR_RESERVED_31_9	9
	#define BLSB_AUD_IO_TX1SAIMR_TX1_SPDIF_BCLK_COMPLETE_INT_EN	8
	#define BLSB_AUD_IO_TX1SAIMR_TX1_FIFO_UNDERRUN_INT_EN	5
	#define BLSB_AUD_IO_TX1SAIMR_RESERVED_4	4
	#define BLSB_AUD_IO_TX1SAIMR_TX1_FIFO_SVC_REQ_INT_EN	3
	#define BLSB_AUD_IO_TX1SAIMR_RESERVED_2_0	0
	/* Register Bit Widths for AUD_IO_TX1SAIMR */
	#define BWID_AUD_IO_TX1SAIMR_RESERVED_31_9	23
	#define BWID_AUD_IO_TX1SAIMR_TX1_SPDIF_BCLK_COMPLETE_INT_EN	1
	#define BWID_AUD_IO_TX1SAIMR_TX1_FIFO_UNDERRUN_INT_EN	1
	#define BWID_AUD_IO_TX1SAIMR_RESERVED_4	1
	#define BWID_AUD_IO_TX1SAIMR_TX1_FIFO_SVC_REQ_INT_EN	1
	#define BWID_AUD_IO_TX1SAIMR_RESERVED_2_0	3
	/* Register Bit MASKS for AUD_IO_TX1SAIMR */
	#define BMSK_AUD_IO_TX1SAIMR_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAIMR_TX1_SPDIF_BCLK_COMPLETE_INT_EN	(1<<8) /* == 0x00000100: Enable S/PDIF Block complete interrupt, bit(s):8, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX1SAIMR_TX1_FIFO_UNDERRUN_INT_EN	(1<<5) /* == 0x00000020: Enable Transmit FIFO under-run condition based interrupt, bit(s):5, default(0), access(RW) */
	#define BMSK_AUD_IO_TX1SAIMR_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAIMR_TX1_FIFO_SVC_REQ_INT_EN	(1<<3) /* == 0x00000008: Enable Transmit FIFO service request based interrupt, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX1SAIMR_RESERVED_2_0	0x00000007 /* Reserved, bit(s):2:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_TX1SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SAIMR_RESERVED_31_9	 0x210c, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_TX1SAIMR_TX1_SPDIF_BCLK_COMPLETE_INT_EN	 0x210c, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_TX1SAIMR_TX1_FIFO_UNDERRUN_INT_EN	 0x210c, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX1SAIMR_RESERVED_4	 0x210c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX1SAIMR_TX1_FIFO_SVC_REQ_INT_EN	 0x210c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX1SAIMR_RESERVED_2_0	 0x210c, 0, 3, 0x00000007
#define ROFF_AUD_IO_TX1SAISR	0x2110 /* TX1SAISR - Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUD_IO_TX1SAISR	 0x2110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SAISR */
	#define BLSB_AUD_IO_TX1SAISR_RESERVED_31_9	9
	#define BLSB_AUD_IO_TX1SAISR_TX1_SPDIF_BLK_COMPLETE_INT	8
	#define BLSB_AUD_IO_TX1SAISR_RESERVED_7_6	6
	#define BLSB_AUD_IO_TX1SAISR_TX1_CLEAR_FIFO_UNDERRUN_INT	5
	#define BLSB_AUD_IO_TX1SAISR_RESERVED_4	4
	#define BLSB_AUD_IO_TX1SAISR_RESERVED_3	3
	#define BLSB_AUD_IO_TX1SAISR_RESERVED_2_0	0
	/* Register Bit Widths for AUD_IO_TX1SAISR */
	#define BWID_AUD_IO_TX1SAISR_RESERVED_31_9	23
	#define BWID_AUD_IO_TX1SAISR_TX1_SPDIF_BLK_COMPLETE_INT	1
	#define BWID_AUD_IO_TX1SAISR_RESERVED_7_6	2
	#define BWID_AUD_IO_TX1SAISR_TX1_CLEAR_FIFO_UNDERRUN_INT	1
	#define BWID_AUD_IO_TX1SAISR_RESERVED_4	1
	#define BWID_AUD_IO_TX1SAISR_RESERVED_3	1
	#define BWID_AUD_IO_TX1SAISR_RESERVED_2_0	3
	/* Register Bit MASKS for AUD_IO_TX1SAISR */
	#define BMSK_AUD_IO_TX1SAISR_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAISR_TX1_SPDIF_BLK_COMPLETE_INT	(1<<8) /* == 0x00000100:  SPDIF Block Transmit Complete Interrupt. Writing a '1' to this location clears the interrupt., bit(s):8, default(0), access(RW) */
	#define BMSK_AUD_IO_TX1SAISR_RESERVED_7_6	0x000000c0 /* Reserved, bit(s):7:6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAISR_TX1_CLEAR_FIFO_UNDERRUN_INT	(1<<5) /* == 0x00000020: Clear Transmit FIFO underrun interrupt and TUR status bit SASR0. Writing a '1' to this location clears the interrupt and SASR0 bit 5, bit(s):5, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX1SAISR_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAISR_RESERVED_3	(1<<3) /* == 0x00000008: Reserved , bit(s):3, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAISR_RESERVED_2_0	0x00000007 /* Reserved, bit(s):2:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_TX1SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SAISR_RESERVED_31_9	 0x2110, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_TX1SAISR_TX1_SPDIF_BLK_COMPLETE_INT	 0x2110, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_TX1SAISR_RESERVED_7_6	 0x2110, 6, 2, 0x000000c0
	#define BITFIELD_AUD_IO_TX1SAISR_TX1_CLEAR_FIFO_UNDERRUN_INT	 0x2110, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX1SAISR_RESERVED_4	 0x2110, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX1SAISR_RESERVED_3	 0x2110, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX1SAISR_RESERVED_2_0	 0x2110, 0, 3, 0x00000007
#define ROFF_AUD_IO_TX1SADIV	0x2114 /* TX1SADIV - Audio Clock Divider Register */ 
	#define BITFIELD_AUD_IO_TX1SADIV	 0x2114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SADIV */
	#define BLSB_AUD_IO_TX1SADIV_UNDEFINED_31_7	7
	#define BLSB_AUD_IO_TX1SADIV_TX1_AUD_CLK_DIV	0
	/* Register Bit Widths for AUD_IO_TX1SADIV */
	#define BWID_AUD_IO_TX1SADIV_UNDEFINED_31_7	25
	#define BWID_AUD_IO_TX1SADIV_TX1_AUD_CLK_DIV	7
	/* Register Bit MASKS for AUD_IO_TX1SADIV */
	#define BMSK_AUD_IO_TX1SADIV_UNDEFINED_31_7	0xffffff80 /* Reserved, bit(s):31:7, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SADIV_TX1_AUD_CLK_DIV	0x0000007f /* Audio Clock Divider, bit(s):6:0, default(06h), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SADIV_UNDEFINED_31_7	 0x2114, 7, 25, 0xffffff80
	#define BITFIELD_AUD_IO_TX1SADIV_TX1_AUD_CLK_DIV	 0x2114, 0, 7, 0x0000007f
#define ROFF_AUD_IO_TX1SATR	0x2118 /* TX1SATR - Serial Audio Transmit Register */ 
	#define BITFIELD_AUD_IO_TX1SATR	 0x2118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SAFTH	0x211c /* TX1SAFTH - Serial Audio FIFO Threshold Register */ 
	#define BITFIELD_AUD_IO_TX1SAFTH	 0x211c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SAFTH */
	#define BLSB_AUD_IO_TX1SAFTH_RESERVED_31_16	16
	#define BLSB_AUD_IO_TX1SAFTH_TX1_LOWER_FIFO_THRSH	0
	/* Register Bit Widths for AUD_IO_TX1SAFTH */
	#define BWID_AUD_IO_TX1SAFTH_RESERVED_31_16	16
	#define BWID_AUD_IO_TX1SAFTH_TX1_LOWER_FIFO_THRSH	16
	/* Register Bit MASKS for AUD_IO_TX1SAFTH */
	#define BMSK_AUD_IO_TX1SAFTH_RESERVED_31_16	0xffff0000 /* Reserved, bit(s):31:16, default(0), access(RW) */
	#define BMSK_AUD_IO_TX1SAFTH_TX1_LOWER_FIFO_THRSH	0x0000ffff /* Lower FIFO Threshold of Transmit Channel in words, bit(s):15:0, default(0000h), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SAFTH_RESERVED_31_16	 0x211c, 16, 16, 0xffff0000
	#define BITFIELD_AUD_IO_TX1SAFTH_TX1_LOWER_FIFO_THRSH	 0x211c, 0, 16, 0x0000ffff
#define ROFF_AUD_IO_TX1SAFL	0x2120 /* TX1SAFL - Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUD_IO_TX1SAFL	 0x2120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SAFL */
	#define BLSB_AUD_IO_TX1SAFL_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX1SAFL_TX1_FIFO_LEVEL	0
	/* Register Bit Widths for AUD_IO_TX1SAFL */
	#define BWID_AUD_IO_TX1SAFL_RESERVED_31_8	24
	#define BWID_AUD_IO_TX1SAFL_TX1_FIFO_LEVEL	8
	/* Register Bit MASKS for AUD_IO_TX1SAFL */
	#define BMSK_AUD_IO_TX1SAFL_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX1SAFL_TX1_FIFO_LEVEL	0x000000ff /* FIFO Level of Transmit Channel. The number of words that are currently stored in the FIFO. , bit(s):7:0, default(000h), access(RO) */
	/* Register BITFIELD for AUD_IO_TX1SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SAFL_RESERVED_31_8	 0x2120, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX1SAFL_TX1_FIFO_LEVEL	 0x2120, 0, 8, 0x000000ff
#define ROFF_AUD_IO_TX1SASUD0	0x2040 /* TX1SASUD0 -  S/PDIF transmit user data bits 31:0 (for SASUD0) - bytes 0-3 (transmitted first)  */ 
	#define BITFIELD_AUD_IO_TX1SASUD0	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD1	0x2044 /* TX1SASUD1 -  S/PDIF transmit user data bits 63:32 (for SASUD1) */ 
	#define BITFIELD_AUD_IO_TX1SASUD1	 0x2044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD2	0x2048 /* TX1SASUD2 -  S/PDIF transmit user data bits 96:64 (for SASUD2) */ 
	#define BITFIELD_AUD_IO_TX1SASUD2	 0x2048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD3	0x204c /* TX1SASUD3 -  S/PDIF transmit user data bits 127:97 (for SASUD3) */ 
	#define BITFIELD_AUD_IO_TX1SASUD3	 0x204c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD4	0x2050 /* TX1SASUD4 -  S/PDIF transmit user data bits 159 :128 (for SASUD4) */ 
	#define BITFIELD_AUD_IO_TX1SASUD4	 0x2050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD5	0x2054 /* TX1SASUD5 -  S/PDIF transmit user data bits 191:160 (for SASUD5) */ 
	#define BITFIELD_AUD_IO_TX1SASUD5	 0x2054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD6	0x2058 /* TX1SASUD6 -  S/PDIF transmit user data bits 223:191 (for SASUD6) */ 
	#define BITFIELD_AUD_IO_TX1SASUD6	 0x2058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD7	0x205c /* TX1SASUD7 -  S/PDIF transmit user data bits 255:224 (for SASUD7) */ 
	#define BITFIELD_AUD_IO_TX1SASUD7	 0x205c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD8	0x2060 /* TX1SASUD8 -  S/PDIF transmit user data bits 287:256 (for SASUD8) */ 
	#define BITFIELD_AUD_IO_TX1SASUD8	 0x2060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD9	0x2064 /* TX1SASUD9 -  S/PDIF transmit user data bits 319:288 (for SASUD9) */ 
	#define BITFIELD_AUD_IO_TX1SASUD9	 0x2064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD10	0x2068 /* TX1SASUD10 - S/PDIF transmit user data bits 351:320 (for SASUD10) */ 
	#define BITFIELD_AUD_IO_TX1SASUD10	 0x2068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUD11	0x206c /* TX1SASUD11 - S/PDIF transmit user data bits 383:352 (for SASUD11) - transmitted last           */ 
	#define BITFIELD_AUD_IO_TX1SASUD11	 0x206c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASUDC	0x2170 /* TX1SASUDC - S/PDIF transmit user data control Register */ 
	#define BITFIELD_AUD_IO_TX1SASUDC	 0x2170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SASUDC */
	#define BLSB_AUD_IO_TX1SASUDC_RESERVED_31_1	1
	#define BLSB_AUD_IO_TX1SASUDC_TX1_LOAD_SASUD_TO_SPDIF	0
	/* Register Bit Widths for AUD_IO_TX1SASUDC */
	#define BWID_AUD_IO_TX1SASUDC_RESERVED_31_1	31
	#define BWID_AUD_IO_TX1SASUDC_TX1_LOAD_SASUD_TO_SPDIF	1
	/* Register Bit MASKS for AUD_IO_TX1SASUDC */
	#define BMSK_AUD_IO_TX1SASUDC_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0), access(RV) */
	#define BMSK_AUD_IO_TX1SASUDC_TX1_LOAD_SASUD_TO_SPDIF	(1<<0) /* == 0x00000001: Load the User Data registers (SASUD0 - SASUD11)into buffer for insertion into S/PDIF data stream. This bit will be automatically reset to \'0\'., bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SASUDC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SASUDC_RESERVED_31_1	 0x2170, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_IO_TX1SASUDC_TX1_LOAD_SASUD_TO_SPDIF	 0x2170, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX1SASCS0	0x2180 /* TX1SASCS0 - S/PDIF transmit channel status Register. Channel Status bits 31:0 (for SASCS0) - bytes 0-3 (Transmitted first) */ 
	#define BITFIELD_AUD_IO_TX1SASCS0	 0x2180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX1SASCS1	0x2184 /* TX1SASCS1 - S/PDIF transmit channel status Register. Channel Status bits 63:32 (for SASCS1) */ 
	#define BITFIELD_AUD_IO_TX1SASCS1	 0x2184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SASCS1 */
	#define BLSB_AUD_IO_TX1SASCS1_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX1SASCS1_WRITABLE	0
	/* Register Bit Widths for AUD_IO_TX1SASCS1 */
	#define BWID_AUD_IO_TX1SASCS1_RESERVED_31_8	24
	#define BWID_AUD_IO_TX1SASCS1_WRITABLE	8
	/* Register Bit MASKS for AUD_IO_TX1SASCS1 */
	#define BMSK_AUD_IO_TX1SASCS1_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(R0) */
	#define BMSK_AUD_IO_TX1SASCS1_WRITABLE	0x000000ff /* TX0SASCS1 - S/PDIF transmit channel status Register. Channel Status bits 40:32 (40 bits only), bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SASCS1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SASCS1_RESERVED_31_8	 0x2184, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX1SASCS1_WRITABLE	 0x2184, 0, 8, 0x000000ff
#define ROFF_AUD_IO_TX1SASCSC	0x218c /* TX1SASCSC - S/PDIF transmit Channel status ctrl Register */ 
	#define BITFIELD_AUD_IO_TX1SASCSC	 0x218c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX1SASCSC */
	#define BLSB_AUD_IO_TX1SASCSC_RESERVED_31_1	1
	#define BLSB_AUD_IO_TX1SASCSC_TX1_LOAD_CNTL_STAT_REG	0
	/* Register Bit Widths for AUD_IO_TX1SASCSC */
	#define BWID_AUD_IO_TX1SASCSC_RESERVED_31_1	31
	#define BWID_AUD_IO_TX1SASCSC_TX1_LOAD_CNTL_STAT_REG	1
	/* Register Bit MASKS for AUD_IO_TX1SASCSC */
	#define BMSK_AUD_IO_TX1SASCSC_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0), access(RV) */
	#define BMSK_AUD_IO_TX1SASCSC_TX1_LOAD_CNTL_STAT_REG	(1<<0) /* == 0x00000001: Load the Control Status registers (TX1SASCS0 - TX1SASCS5)into buffer for insertion into S/PDIF data stream. This bit will be automatically reset to '0'. , bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX1SASCSC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX1SASCSC_RESERVED_31_1	 0x218c, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_IO_TX1SASCSC_TX1_LOAD_CNTL_STAT_REG	 0x218c, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX2SACR0	0x2200 /* TX2SACR0 - Global Control Register */ 
	#define BITFIELD_AUD_IO_TX2SACR0	 0x2200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SACR0 */
	#define BLSB_AUD_IO_TX2SACR0_RESERVED_31	31
	#define BLSB_AUD_IO_TX2SACR0_RESERVED_30	30
	#define BLSB_AUD_IO_TX2SACR0_RESERVED_29_6	6
	#define BLSB_AUD_IO_TX2SACR0_TX2_OUTPUT_SEL	5
	#define BLSB_AUD_IO_TX2SACR0_UNDEFINED_4	4
	#define BLSB_AUD_IO_TX2SACR0_TX2_FIFO_RESET	3
	#define BLSB_AUD_IO_TX2SACR0_RESERVED_2	2
	#define BLSB_AUD_IO_TX2SACR0_RESERVED_1	1
	#define BLSB_AUD_IO_TX2SACR0_TX2_ENABLE	0
	/* Register Bit Widths for AUD_IO_TX2SACR0 */
	#define BWID_AUD_IO_TX2SACR0_RESERVED_31	1
	#define BWID_AUD_IO_TX2SACR0_RESERVED_30	1
	#define BWID_AUD_IO_TX2SACR0_RESERVED_29_6	24
	#define BWID_AUD_IO_TX2SACR0_TX2_OUTPUT_SEL	2
	#define BWID_AUD_IO_TX2SACR0_UNDEFINED_4	1
	#define BWID_AUD_IO_TX2SACR0_TX2_FIFO_RESET	1
	#define BWID_AUD_IO_TX2SACR0_RESERVED_2	1
	#define BWID_AUD_IO_TX2SACR0_RESERVED_1	1
	#define BWID_AUD_IO_TX2SACR0_TX2_ENABLE	1
	/* Register Bit MASKS for AUD_IO_TX2SACR0 */
	#define BMSK_AUD_IO_TX2SACR0_RESERVED_31	(1<<31) /* == 0x80000000: Reserved, bit(s):31, default(0H), access(RW) */
	#define BMSK_AUD_IO_TX2SACR0_RESERVED_30	(1<<30) /* == 0x40000000: Reserved, bit(s):30, default(0H), access(RO) */
	#define BMSK_AUD_IO_TX2SACR0_RESERVED_29_6	0x3fffffc0 /* Reserved, bit(s):29:6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SACR0_TX2_OUTPUT_SEL	0x00000060 /* Select outputs 00: 7.1 I2S output 01: stereo I2S output 0 10: not used  11: S/PDIF output, bit(s):6:5, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR0_UNDEFINED_4	(1<<4) /* == 0x00000010: , bit(s):4, default(), access() */
	#define BMSK_AUD_IO_TX2SACR0_TX2_FIFO_RESET	(1<<3) /* == 0x00000008: Resets FIFOs logic and all registers, except this register (SACR0): 0: Not reset 1: Reset is Active Other Registers , bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR0_RESERVED_2	(1<<2) /* == 0x00000004: Reserved , bit(s):2, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SACR0_TX2_ENABLE	(1<<0) /* == 0x00000001: EnableTX function: 0: TX channel is disabled 1: TX channel is enabled, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SACR0_RESERVED_31	 0x2200, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_TX2SACR0_RESERVED_30	 0x2200, 30, 1, 0x40000000
	#define BITFIELD_AUD_IO_TX2SACR0_RESERVED_29_6	 0x2200, 6, 24, 0x3fffffc0
	#define BITFIELD_AUD_IO_TX2SACR0_TX2_OUTPUT_SEL	 0x2200, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_TX2SACR0_UNDEFINED_4	 0x2200, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX2SACR0_TX2_FIFO_RESET	 0x2200, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX2SACR0_RESERVED_2	 0x2200, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX2SACR0_RESERVED_1	 0x2200, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX2SACR0_TX2_ENABLE	 0x2200, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX2SACR1	0x2204 /* TX2SACR1 - Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUD_IO_TX2SACR1	 0x2204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SACR1 */
	#define BLSB_AUD_IO_TX2SACR1_TX2_SPDIF_VALIDITY	31
	#define BLSB_AUD_IO_TX2SACR1_RESERVED_30_20	20
	#define BLSB_AUD_IO_TX2SACR1_TX2_DMA_CONTEXT	17
	#define BLSB_AUD_IO_TX2SACR1_RESERVED_16	16
	#define BLSB_AUD_IO_TX2SACR1_TX2_I2S_PIN2	14
	#define BLSB_AUD_IO_TX2SACR1_TX2_I2S_PIN1	12
	#define BLSB_AUD_IO_TX2SACR1_TX2_I2S_PIN0	10
	#define BLSB_AUD_IO_TX2SACR1_TX2_MODE	8
	#define BLSB_AUD_IO_TX2SACR1_TX2_SAMPLE_SIZE	7
	#define BLSB_AUD_IO_TX2SACR1_TX2_I2S_PIN3	5
	#define BLSB_AUD_IO_TX2SACR1_RESERVED_4	4
	#define BLSB_AUD_IO_TX2SACR1_RESERVED_3	3
	#define BLSB_AUD_IO_TX2SACR1_RESERVED_2	2
	#define BLSB_AUD_IO_TX2SACR1_RESERVED_1	1
	#define BLSB_AUD_IO_TX2SACR1_TX2_ALT_MODE	0
	/* Register Bit Widths for AUD_IO_TX2SACR1 */
	#define BWID_AUD_IO_TX2SACR1_TX2_SPDIF_VALIDITY	1
	#define BWID_AUD_IO_TX2SACR1_RESERVED_30_20	11
	#define BWID_AUD_IO_TX2SACR1_TX2_DMA_CONTEXT	3
	#define BWID_AUD_IO_TX2SACR1_RESERVED_16	1
	#define BWID_AUD_IO_TX2SACR1_TX2_I2S_PIN2	2
	#define BWID_AUD_IO_TX2SACR1_TX2_I2S_PIN1	2
	#define BWID_AUD_IO_TX2SACR1_TX2_I2S_PIN0	2
	#define BWID_AUD_IO_TX2SACR1_TX2_MODE	2
	#define BWID_AUD_IO_TX2SACR1_TX2_SAMPLE_SIZE	1
	#define BWID_AUD_IO_TX2SACR1_TX2_I2S_PIN3	2
	#define BWID_AUD_IO_TX2SACR1_RESERVED_4	1
	#define BWID_AUD_IO_TX2SACR1_RESERVED_3	1
	#define BWID_AUD_IO_TX2SACR1_RESERVED_2	1
	#define BWID_AUD_IO_TX2SACR1_RESERVED_1	1
	#define BWID_AUD_IO_TX2SACR1_TX2_ALT_MODE	1
	/* Register Bit MASKS for AUD_IO_TX2SACR1 */
	#define BMSK_AUD_IO_TX2SACR1_TX2_SPDIF_VALIDITY	(1<<31) /* == 0x80000000: SPDIF validity bit, bit(s):31, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_RESERVED_30_20	0x7ff00000 /* Reserved, bit(s):30:20, default(000h), access(RO) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_DMA_CONTEXT	0x000e0000 /* DMA Context Number. Specifies the DMA context number allocated to this I2S channel. The software must set up this field differently for each I2S interface to avoid unpredictable behavior. 000: Context 0 001: Context 1 010: Context 2 011: Context 3., bit(s):19:17, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_RESERVED_16	(1<<16) /* == 0x00010000: Reserved , bit(s):16, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_I2S_PIN2	0x0000c000 /* Disable I2S Transmit Data Pin 2: 00: Transmit Data Pin 2, Both Channels are Enabled 01: Transmit Data Pin 2, Left Channel is Enabled; Right  channel output will be 0-filled 10: Transmit Data Pin 2, Right channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 2 is Disabled, bit(s):15:14, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_I2S_PIN1	0x00003000 /* Disable I2S Transmit Data Pin 1: 00: Transmit Data Pin 1, Both Channels are Enabled 01: Transmit Data Pin 1, Left  Channel is Enabled; Right channel output will be 0-filled 10: Transmit Data Pin 1, Right  Channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 1 is Disabled, bit(s):13:12, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_I2S_PIN0	0x00000c00 /* Disable I2S Transmit Data Pin 0: 00: Transmit Data Pin 0, Both Channels are Enabled 01: Transmit Data Pin 0, Left  Channel is Enabled; Right channel output will be 0-filled 10: Transmit Data Pin 0, Right  Channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 0 is Disabled, bit(s):11:10, default(0H), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_MODE	0x00000300 /* Data storage Mode: 00: 7.1 Data 01: Stereo Mode 10: Left-Channel Mono 11: Right-Channel Mono, bit(s):9:8, default(00b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_SAMPLE_SIZE	(1<<7) /* == 0x00000080: Data Sample Size 0: 16-bit data sample 1: 24-bit data sample, bit(s):7, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_I2S_PIN3	0x00000060 /* Disable I2S Transmit Data Pin 3: 00: Transmit Data Pin 3, Both Channels are Enabled 01: Transmit Data Pin 3, Left Channel is Enabled; Right  channel output will be 0-filled 10: Transmit Data Pin 3, Right channel is Enabled; Left  channel output will be 0-filled 11: Transmit Data Pin 3 is Disabled, bit(s):6:5, default(0), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_RESERVED_3	(1<<3) /* == 0x00000008: Reserved, bit(s):3, default(0), access(RW) */
	#define BMSK_AUD_IO_TX2SACR1_RESERVED_2	(1<<2) /* == 0x00000004: Reserved, bit(s):2, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SACR1_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SACR1_TX2_ALT_MODE	(1<<0) /* == 0x00000001: Specify Alternate Mode (I2S or MSB-Justified) Operation: 0: Select I2S Operation Mode 1: Select MSB-Justified Operation Mode, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_SPDIF_VALIDITY	 0x2204, 31, 1, 0x80000000
	#define BITFIELD_AUD_IO_TX2SACR1_RESERVED_30_20	 0x2204, 20, 11, 0x7ff00000
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_DMA_CONTEXT	 0x2204, 17, 3, 0x000e0000
	#define BITFIELD_AUD_IO_TX2SACR1_RESERVED_16	 0x2204, 16, 1, 0x00010000
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_I2S_PIN2	 0x2204, 14, 2, 0x0000c000
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_I2S_PIN1	 0x2204, 12, 2, 0x00003000
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_I2S_PIN0	 0x2204, 10, 2, 0x00000c00
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_MODE	 0x2204, 8, 2, 0x00000300
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_SAMPLE_SIZE	 0x2204, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_I2S_PIN3	 0x2204, 5, 2, 0x00000060
	#define BITFIELD_AUD_IO_TX2SACR1_RESERVED_4	 0x2204, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX2SACR1_RESERVED_3	 0x2204, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX2SACR1_RESERVED_2	 0x2204, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX2SACR1_RESERVED_1	 0x2204, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX2SACR1_TX2_ALT_MODE	 0x2204, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX2SASR0	0x2208 /* TX2SASR0 - Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUD_IO_TX2SASR0	 0x2208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SASR0 */
	#define BLSB_AUD_IO_TX2SASR0_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX2SASR0_RESERVED_10_8	8
	#define BLSB_AUD_IO_TX2SASR0_I2S_CNTL_CLEAN_SHUTDOWN	7
	#define BLSB_AUD_IO_TX2SASR0_RESERVED_6	6
	#define BLSB_AUD_IO_TX2SASR0_TX2_FIFO_UNDERRUN	5
	#define BLSB_AUD_IO_TX2SASR0_RESERVED_4	4
	#define BLSB_AUD_IO_TX2SASR0_TX2_FIFO_SVC_REQ	3
	#define BLSB_AUD_IO_TX2SASR0_TX2_BUSY	2
	#define BLSB_AUD_IO_TX2SASR0_RESERVED_1	1
	#define BLSB_AUD_IO_TX2SASR0_TX2_FIFO_NOT_EMPTY	0
	/* Register Bit Widths for AUD_IO_TX2SASR0 */
	#define BWID_AUD_IO_TX2SASR0_RESERVED_31_8	24
	#define BWID_AUD_IO_TX2SASR0_RESERVED_10_8	3
	#define BWID_AUD_IO_TX2SASR0_I2S_CNTL_CLEAN_SHUTDOWN	1
	#define BWID_AUD_IO_TX2SASR0_RESERVED_6	1
	#define BWID_AUD_IO_TX2SASR0_TX2_FIFO_UNDERRUN	1
	#define BWID_AUD_IO_TX2SASR0_RESERVED_4	1
	#define BWID_AUD_IO_TX2SASR0_TX2_FIFO_SVC_REQ	1
	#define BWID_AUD_IO_TX2SASR0_TX2_BUSY	1
	#define BWID_AUD_IO_TX2SASR0_RESERVED_1	1
	#define BWID_AUD_IO_TX2SASR0_TX2_FIFO_NOT_EMPTY	1
	/* Register Bit MASKS for AUD_IO_TX2SASR0 */
	#define BMSK_AUD_IO_TX2SASR0_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_RESERVED_10_8	0x00000700 /* Reserved, bit(s):10:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_I2S_CNTL_CLEAN_SHUTDOWN	(1<<7) /* == 0x00000080: I2S Controller Clean Shutdown. When this value is '1', the I2SC is in the process of clean shutdown. When this value is '1', no writes ot the I2SC registers are allowed. When this bit is '0' and SACR0.ENB bit value is '0', then the unit is shutdown. When this bit is '0' and SACR0.ENB bit value is '1', then the I2SC is in enabled mode. When '0' is written to SACR0.ENB, I2SOFF will be '1' until all the data in the transmit FIFO is transmitted to CODEC and all the data in receive FIFO is read by the DMA., bit(s):7, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_RESERVED_6	(1<<6) /* == 0x00000040: Reserved, bit(s):6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_TX2_FIFO_UNDERRUN	(1<<5) /* == 0x00000020: Transmit FIFO Underrun: 0: Transmit FIFO has not experienced an underrun.1: I2S attempted data read from an empty Transmit FIFO - Can interrupt processor if bit5 of Serial Audio Interrupt Mask Register is set. - Cleared by writing a '1' to bit5 of Serial Audio Interrupt Clear Register., bit(s):5, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_TX2_FIFO_SVC_REQ	(1<<3) /* == 0x00000008: Transmit FIFO Service Request: 0: Transmit FIFO level exceeds TFL threshold, or I2S disabled 1: Transmit FIFO level is at or below TFL threshold - Can interrupt processor if bit3 of Serial Audio Interrupt Mask Register is set. - Cleared automatically when # of Transmit FIFO entries >= (TFTH + 1), bit(s):3, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_TX2_BUSY	(1<<2) /* == 0x00000004: TX Busy: 0: TX is idle or disabled 1:TX currently transmitting a frame , bit(s):2, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_RESERVED_1	(1<<1) /* == 0x00000002: Reserved, bit(s):1, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SASR0_TX2_FIFO_NOT_EMPTY	(1<<0) /* == 0x00000001: Transmit FIFO not full 0: Transmit FIFO is full 1: Transmit FIFO is not full, bit(s):0, default(1b), access(RO) */
	/* Register BITFIELD for AUD_IO_TX2SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SASR0_RESERVED_31_8	 0x2208, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX2SASR0_RESERVED_10_8	 0x2208, 8, 3, 0x00000700
	#define BITFIELD_AUD_IO_TX2SASR0_I2S_CNTL_CLEAN_SHUTDOWN	 0x2208, 7, 1, 0x00000080
	#define BITFIELD_AUD_IO_TX2SASR0_RESERVED_6	 0x2208, 6, 1, 0x00000040
	#define BITFIELD_AUD_IO_TX2SASR0_TX2_FIFO_UNDERRUN	 0x2208, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX2SASR0_RESERVED_4	 0x2208, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX2SASR0_TX2_FIFO_SVC_REQ	 0x2208, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX2SASR0_TX2_BUSY	 0x2208, 2, 1, 0x00000004
	#define BITFIELD_AUD_IO_TX2SASR0_RESERVED_1	 0x2208, 1, 1, 0x00000002
	#define BITFIELD_AUD_IO_TX2SASR0_TX2_FIFO_NOT_EMPTY	 0x2208, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX2SAIMR	0x220c /* TX2SAIMR - Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUD_IO_TX2SAIMR	 0x220c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SAIMR */
	#define BLSB_AUD_IO_TX2SAIMR_RESERVED_31_9	9
	#define BLSB_AUD_IO_TX2SAIMR_TX2_SPDIF_BCLK_COMPLETE_INT_EN	8
	#define BLSB_AUD_IO_TX2SAIMR_TX2_FIFO_UNDERRUN_INT_EN	5
	#define BLSB_AUD_IO_TX2SAIMR_RESERVED_4	4
	#define BLSB_AUD_IO_TX2SAIMR_TX2_FIFO_SVC_REQ_INT_EN	3
	#define BLSB_AUD_IO_TX2SAIMR_RESERVED_2_0	0
	/* Register Bit Widths for AUD_IO_TX2SAIMR */
	#define BWID_AUD_IO_TX2SAIMR_RESERVED_31_9	23
	#define BWID_AUD_IO_TX2SAIMR_TX2_SPDIF_BCLK_COMPLETE_INT_EN	1
	#define BWID_AUD_IO_TX2SAIMR_TX2_FIFO_UNDERRUN_INT_EN	1
	#define BWID_AUD_IO_TX2SAIMR_RESERVED_4	1
	#define BWID_AUD_IO_TX2SAIMR_TX2_FIFO_SVC_REQ_INT_EN	1
	#define BWID_AUD_IO_TX2SAIMR_RESERVED_2_0	3
	/* Register Bit MASKS for AUD_IO_TX2SAIMR */
	#define BMSK_AUD_IO_TX2SAIMR_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAIMR_TX2_SPDIF_BCLK_COMPLETE_INT_EN	(1<<8) /* == 0x00000100: Enable S/PDIF Block complete interrupt, bit(s):8, default(0b), access(RO) */
	#define BMSK_AUD_IO_TX2SAIMR_TX2_FIFO_UNDERRUN_INT_EN	(1<<5) /* == 0x00000020: Enable Transmit FIFO under-run condition based interrupt, bit(s):5, default(0), access(RW) */
	#define BMSK_AUD_IO_TX2SAIMR_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAIMR_TX2_FIFO_SVC_REQ_INT_EN	(1<<3) /* == 0x00000008: Enable Transmit FIFO service request based interrupt, bit(s):3, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX2SAIMR_RESERVED_2_0	0x00000007 /* Reserved, bit(s):2:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_TX2SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SAIMR_RESERVED_31_9	 0x220c, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_TX2SAIMR_TX2_SPDIF_BCLK_COMPLETE_INT_EN	 0x220c, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_TX2SAIMR_TX2_FIFO_UNDERRUN_INT_EN	 0x220c, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX2SAIMR_RESERVED_4	 0x220c, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX2SAIMR_TX2_FIFO_SVC_REQ_INT_EN	 0x220c, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX2SAIMR_RESERVED_2_0	 0x220c, 0, 3, 0x00000007
#define ROFF_AUD_IO_TX2SAISR	0x2210 /* TX2SAISR - Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUD_IO_TX2SAISR	 0x2210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SAISR */
	#define BLSB_AUD_IO_TX2SAISR_RESERVED_31_9	9
	#define BLSB_AUD_IO_TX2SAISR_TX2_SPDIF_BLK_COMPLETE_INT	8
	#define BLSB_AUD_IO_TX2SAISR_RESERVED_7_6	6
	#define BLSB_AUD_IO_TX2SAISR_TX2_CLEAR_FIFO_UNDERRUN_INT	5
	#define BLSB_AUD_IO_TX2SAISR_RESERVED_4	4
	#define BLSB_AUD_IO_TX2SAISR_RESERVED_3	3
	#define BLSB_AUD_IO_TX2SAISR_RESERVED_2_0	0
	/* Register Bit Widths for AUD_IO_TX2SAISR */
	#define BWID_AUD_IO_TX2SAISR_RESERVED_31_9	23
	#define BWID_AUD_IO_TX2SAISR_TX2_SPDIF_BLK_COMPLETE_INT	1
	#define BWID_AUD_IO_TX2SAISR_RESERVED_7_6	2
	#define BWID_AUD_IO_TX2SAISR_TX2_CLEAR_FIFO_UNDERRUN_INT	1
	#define BWID_AUD_IO_TX2SAISR_RESERVED_4	1
	#define BWID_AUD_IO_TX2SAISR_RESERVED_3	1
	#define BWID_AUD_IO_TX2SAISR_RESERVED_2_0	3
	/* Register Bit MASKS for AUD_IO_TX2SAISR */
	#define BMSK_AUD_IO_TX2SAISR_RESERVED_31_9	0xfffffe00 /* Reserved, bit(s):31:9, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAISR_TX2_SPDIF_BLK_COMPLETE_INT	(1<<8) /* == 0x00000100:  SPDIF Block Transmit Complete Interrupt. Writing a '1' to this location clears the interrupt., bit(s):8, default(0), access(RW) */
	#define BMSK_AUD_IO_TX2SAISR_RESERVED_7_6	0x000000c0 /* Reserved, bit(s):7:6, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAISR_TX2_CLEAR_FIFO_UNDERRUN_INT	(1<<5) /* == 0x00000020: Clear Transmit FIFO underrun interrupt and TUR status bit SASR0. Writing a '1' to this location clears the interrupt and SASR0 bit 5, bit(s):5, default(0b), access(RW) */
	#define BMSK_AUD_IO_TX2SAISR_RESERVED_4	(1<<4) /* == 0x00000010: Reserved, bit(s):4, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAISR_RESERVED_3	(1<<3) /* == 0x00000008: Reserved , bit(s):3, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAISR_RESERVED_2_0	0x00000007 /* Reserved, bit(s):2:0, default(0), access(RO) */
	/* Register BITFIELD for AUD_IO_TX2SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SAISR_RESERVED_31_9	 0x2210, 9, 23, 0xfffffe00
	#define BITFIELD_AUD_IO_TX2SAISR_TX2_SPDIF_BLK_COMPLETE_INT	 0x2210, 8, 1, 0x00000100
	#define BITFIELD_AUD_IO_TX2SAISR_RESERVED_7_6	 0x2210, 6, 2, 0x000000c0
	#define BITFIELD_AUD_IO_TX2SAISR_TX2_CLEAR_FIFO_UNDERRUN_INT	 0x2210, 5, 1, 0x00000020
	#define BITFIELD_AUD_IO_TX2SAISR_RESERVED_4	 0x2210, 4, 1, 0x00000010
	#define BITFIELD_AUD_IO_TX2SAISR_RESERVED_3	 0x2210, 3, 1, 0x00000008
	#define BITFIELD_AUD_IO_TX2SAISR_RESERVED_2_0	 0x2210, 0, 3, 0x00000007
#define ROFF_AUD_IO_TX2SADIV	0x2214 /* TX2SADIV - Audio Clock Divider Register */ 
	#define BITFIELD_AUD_IO_TX2SADIV	 0x2214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SADIV */
	#define BLSB_AUD_IO_TX2SADIV_UNDEFINED_31_7	7
	#define BLSB_AUD_IO_TX2SADIV_TX2_AUD_CLK_DIV	0
	/* Register Bit Widths for AUD_IO_TX2SADIV */
	#define BWID_AUD_IO_TX2SADIV_UNDEFINED_31_7	25
	#define BWID_AUD_IO_TX2SADIV_TX2_AUD_CLK_DIV	7
	/* Register Bit MASKS for AUD_IO_TX2SADIV */
	#define BMSK_AUD_IO_TX2SADIV_UNDEFINED_31_7	0xffffff80 /* Reserved, bit(s):31:7, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SADIV_TX2_AUD_CLK_DIV	0x0000007f /* Audio Clock Divider, bit(s):6:0, default(06h), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SADIV_UNDEFINED_31_7	 0x2214, 7, 25, 0xffffff80
	#define BITFIELD_AUD_IO_TX2SADIV_TX2_AUD_CLK_DIV	 0x2214, 0, 7, 0x0000007f
#define ROFF_AUD_IO_TX2SATR	0x2218 /* TX2SATR - Serial Audio Transmit Register */ 
	#define BITFIELD_AUD_IO_TX2SATR	 0x2218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SAFTH	0x221c /* TX2SAFTH - Serial Audio FIFO Threshold Register */ 
	#define BITFIELD_AUD_IO_TX2SAFTH	 0x221c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SAFTH */
	#define BLSB_AUD_IO_TX2SAFTH_RESERVED_31_16	16
	#define BLSB_AUD_IO_TX2SAFTH_TX2_LOWER_FIFO_THRSH	0
	/* Register Bit Widths for AUD_IO_TX2SAFTH */
	#define BWID_AUD_IO_TX2SAFTH_RESERVED_31_16	16
	#define BWID_AUD_IO_TX2SAFTH_TX2_LOWER_FIFO_THRSH	16
	/* Register Bit MASKS for AUD_IO_TX2SAFTH */
	#define BMSK_AUD_IO_TX2SAFTH_RESERVED_31_16	0xffff0000 /* Reserved, bit(s):31:16, default(0), access(RW) */
	#define BMSK_AUD_IO_TX2SAFTH_TX2_LOWER_FIFO_THRSH	0x0000ffff /* Lower FIFO Threshold of Transmit Channel in words, bit(s):15:0, default(0000h), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SAFTH_RESERVED_31_16	 0x221c, 16, 16, 0xffff0000
	#define BITFIELD_AUD_IO_TX2SAFTH_TX2_LOWER_FIFO_THRSH	 0x221c, 0, 16, 0x0000ffff
#define ROFF_AUD_IO_TX2SAFL	0x2220 /* TX2SAFL - Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUD_IO_TX2SAFL	 0x2220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SAFL */
	#define BLSB_AUD_IO_TX2SAFL_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX2SAFL_TX2_FIFO_LEVEL	0
	/* Register Bit Widths for AUD_IO_TX2SAFL */
	#define BWID_AUD_IO_TX2SAFL_RESERVED_31_8	24
	#define BWID_AUD_IO_TX2SAFL_TX2_FIFO_LEVEL	8
	/* Register Bit MASKS for AUD_IO_TX2SAFL */
	#define BMSK_AUD_IO_TX2SAFL_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(RO) */
	#define BMSK_AUD_IO_TX2SAFL_TX2_FIFO_LEVEL	0x000000ff /* FIFO Level of Transmit Channel. The number of words that are currently stored in the FIFO. , bit(s):7:0, default(000h), access(RO) */
	/* Register BITFIELD for AUD_IO_TX2SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SAFL_RESERVED_31_8	 0x2220, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX2SAFL_TX2_FIFO_LEVEL	 0x2220, 0, 8, 0x000000ff
#define ROFF_AUD_IO_TX2SASUD0	0x2040 /* TX2SASUD0 -  S/PDIF transmit user data bits 31:0 (for SASUD0) - bytes 0-3 (transmitted first)  */ 
	#define BITFIELD_AUD_IO_TX2SASUD0	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD1	0x2044 /* TX2SASUD1 -  S/PDIF transmit user data bits 63:32 (for SASUD1) */ 
	#define BITFIELD_AUD_IO_TX2SASUD1	 0x2044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD2	0x2048 /* TX2SASUD2 -  S/PDIF transmit user data bits 96:64 (for SASUD2) */ 
	#define BITFIELD_AUD_IO_TX2SASUD2	 0x2048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD3	0x204c /* TX2SASUD3 -  S/PDIF transmit user data bits 127:97 (for SASUD3) */ 
	#define BITFIELD_AUD_IO_TX2SASUD3	 0x204c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD4	0x2050 /* TX2SASUD4 -  S/PDIF transmit user data bits 159 :128 (for SASUD4) */ 
	#define BITFIELD_AUD_IO_TX2SASUD4	 0x2050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD5	0x2054 /* TX2SASUD5 -  S/PDIF transmit user data bits 191:160 (for SASUD5) */ 
	#define BITFIELD_AUD_IO_TX2SASUD5	 0x2054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD6	0x2058 /* TX2SASUD6 -  S/PDIF transmit user data bits 223:191 (for SASUD6) */ 
	#define BITFIELD_AUD_IO_TX2SASUD6	 0x2058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD7	0x205c /* TX2SASUD7 -  S/PDIF transmit user data bits 255:224 (for SASUD7) */ 
	#define BITFIELD_AUD_IO_TX2SASUD7	 0x205c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD8	0x2060 /* TX2SASUD8 -  S/PDIF transmit user data bits 287:256 (for SASUD8) */ 
	#define BITFIELD_AUD_IO_TX2SASUD8	 0x2060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD9	0x2064 /* TX2SASUD9 -  S/PDIF transmit user data bits 319:288 (for SASUD9) */ 
	#define BITFIELD_AUD_IO_TX2SASUD9	 0x2064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD10	0x2068 /* TX2SASUD10 - S/PDIF transmit user data bits 351:320 (for SASUD10) */ 
	#define BITFIELD_AUD_IO_TX2SASUD10	 0x2068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUD11	0x206c /* TX2SASUD11 - S/PDIF transmit user data bits 383:352 (for SASUD11) - transmitted last           */ 
	#define BITFIELD_AUD_IO_TX2SASUD11	 0x206c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASUDC	0x2270 /* TX2SASUDC - S/PDIF transmit user data control Register */ 
	#define BITFIELD_AUD_IO_TX2SASUDC	 0x2270, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SASUDC */
	#define BLSB_AUD_IO_TX2SASUDC_RESERVED_31_1	1
	#define BLSB_AUD_IO_TX2SASUDC_TX2_LOAD_SASUD_TO_SPDIF	0
	/* Register Bit Widths for AUD_IO_TX2SASUDC */
	#define BWID_AUD_IO_TX2SASUDC_RESERVED_31_1	31
	#define BWID_AUD_IO_TX2SASUDC_TX2_LOAD_SASUD_TO_SPDIF	1
	/* Register Bit MASKS for AUD_IO_TX2SASUDC */
	#define BMSK_AUD_IO_TX2SASUDC_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0), access(RV) */
	#define BMSK_AUD_IO_TX2SASUDC_TX2_LOAD_SASUD_TO_SPDIF	(1<<0) /* == 0x00000001: Load the User Data registers (SASUD0 - SASUD11)into buffer for insertion into S/PDIF data stream. This bit will be automatically reset to \'0\'., bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SASUDC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SASUDC_RESERVED_31_1	 0x2270, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_IO_TX2SASUDC_TX2_LOAD_SASUD_TO_SPDIF	 0x2270, 0, 1, 0x00000001
#define ROFF_AUD_IO_TX2SASCS0	0x2280 /* TX2SASCS0 - S/PDIF transmit channel status Register. Channel Status bits 31:0 (for SASCS0) - bytes 0-3 (Transmitted first) */ 
	#define BITFIELD_AUD_IO_TX2SASCS0	 0x2280, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUD_IO_TX2SASCS1	0x2284 /* TX2SASCS1 - S/PDIF transmit channel status Register. Channel Status bits 63:32 (for SASCS1) */ 
	#define BITFIELD_AUD_IO_TX2SASCS1	 0x2284, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SASCS1 */
	#define BLSB_AUD_IO_TX2SASCS1_RESERVED_31_8	8
	#define BLSB_AUD_IO_TX2SASCS1_WRITABLE	0
	/* Register Bit Widths for AUD_IO_TX2SASCS1 */
	#define BWID_AUD_IO_TX2SASCS1_RESERVED_31_8	24
	#define BWID_AUD_IO_TX2SASCS1_WRITABLE	8
	/* Register Bit MASKS for AUD_IO_TX2SASCS1 */
	#define BMSK_AUD_IO_TX2SASCS1_RESERVED_31_8	0xffffff00 /* Reserved, bit(s):31:8, default(0), access(R0) */
	#define BMSK_AUD_IO_TX2SASCS1_WRITABLE	0x000000ff /* TX0SASCS1 - S/PDIF transmit channel status Register. Channel Status bits 40:32 (40 bits only), bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SASCS1 - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SASCS1_RESERVED_31_8	 0x2284, 8, 24, 0xffffff00
	#define BITFIELD_AUD_IO_TX2SASCS1_WRITABLE	 0x2284, 0, 8, 0x000000ff
#define ROFF_AUD_IO_TX2SASCSC	0x228c /* TX2SASCSC - S/PDIF transmit Channel status ctrl Register */ 
	#define BITFIELD_AUD_IO_TX2SASCSC	 0x228c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_IO_TX2SASCSC */
	#define BLSB_AUD_IO_TX2SASCSC_RESERVED_31_1	1
	#define BLSB_AUD_IO_TX2SASCSC_TX2_LOAD_CNTL_STAT_REG	0
	/* Register Bit Widths for AUD_IO_TX2SASCSC */
	#define BWID_AUD_IO_TX2SASCSC_RESERVED_31_1	31
	#define BWID_AUD_IO_TX2SASCSC_TX2_LOAD_CNTL_STAT_REG	1
	/* Register Bit MASKS for AUD_IO_TX2SASCSC */
	#define BMSK_AUD_IO_TX2SASCSC_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0), access(RV) */
	#define BMSK_AUD_IO_TX2SASCSC_TX2_LOAD_CNTL_STAT_REG	(1<<0) /* == 0x00000001: Load the Control Status registers (TX2SASCS0 - TX2SASCS5)into buffer for insertion into S/PDIF data stream. This bit will be automatically reset to '0'. , bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_IO_TX2SASCSC - roff, lsb, width, mask */
	#define BITFIELD_AUD_IO_TX2SASCSC_RESERVED_31_1	 0x228c, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_IO_TX2SASCSC_TX2_LOAD_CNTL_STAT_REG	 0x228c, 0, 1, 0x00000001


/* Module AUD_IO SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_AUD_IO_APM_INPUT_PORT_ADD	0x1
#define SVEN_MODULE_EVENT_AUD_IO_APM_OUTPUT_PORT_ADD	0x2
#define SVEN_MODULE_EVENT_AUD_IO_APM_DECODER_CODEC_CHANGED	0x3
#define SVEN_MODULE_EVENT_AUD_IO_APM_DECODER_SETUP	0x4
#define SVEN_MODULE_EVENT_AUD_IO_APM_INPUT_RECONFIG	0x5
#define SVEN_MODULE_EVENT_AUD_IO_APM_SET_PCM_FORMAT	0x6
#define SVEN_MODULE_EVENT_AUD_IO_APM_SET_OOB_BUF_ATTR	0x7
#define SVEN_MODULE_EVENT_AUD_IO_APM_RENDER_SETUP	0x8
#define SVEN_MODULE_EVENT_AUD_IO_APM_SET_STATE	0x9
#define SVEN_MODULE_EVENT_AUD_IO_APM_NEWSEGMENT	0xa
#define SVEN_MODULE_EVENT_AUD_IO_APM_ADVANCE_TO_PTS	0xb
#define SVEN_MODULE_EVENT_AUD_IO_APM_INPUT_SET_PLAY_RATE	0xc
#define SVEN_MODULE_EVENT_AUD_IO_APM_INPUT_DEQUEUE	0xd
#define SVEN_MODULE_EVENT_AUD_IO_APM_POST_ATC_PIPE_RECONFIG	0xe
#define SVEN_MODULE_EVENT_AUD_IO_APM_FLUSH	0xf
#define SVEN_MODULE_EVENT_AUD_IO_APM_INPUT_DEQUEUE_FAILED	0x10
#define SVEN_MODULE_EVENT_AUD_IO_APM_OUTPUT_PORT_WRITE_FAILED	0x11
#define SVEN_MODULE_EVENT_AUD_IO_APM_OUTPUT_PORT_IN_DEQUEUE_FAILED	0x12
#define SVEN_MODULE_EVENT_AUD_IO_APM_HANDLE_PTS	0x13
#define SVEN_MODULE_EVENT_AUD_IO_APM_INPUT_AD	0x14
#define SVEN_MODULE_EVENT_AUD_IO_APM_PTS_LATE	0x15
#define SVEN_MODULE_EVENT_AUD_IO_APM_SCALE_PTS	0x16
#define SVEN_MODULE_EVENT_AUD_IO_APM_CAPTURE_PTS_ASSOCIATION	0x17
#define SVEN_MODULE_EVENT_AUD_IO_APM_OUTPUT_PORT_TIMING_INFO	0x18
#define SVEN_MODULE_EVENT_AUD_IO_CORE_NORMALIZE_SAMPLES	0x19
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_TIME_PERIOD	0x21
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_BASE_TIME	0x22
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_CLOCK	0x23
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PTS_CLOCK_COMPARE	0x24
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SEND_SILENCE_BUFFER	0x25
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PRE_BUFFER_CHOP	0x26
#define SVEN_MODULE_EVENT_AUD_IO_ATC_POST_BUFFER_CHOP	0x27
#define SVEN_MODULE_EVENT_AUD_IO_ATC_CLOCK_ALARM	0x28
#define SVEN_MODULE_EVENT_AUD_IO_ATC_FILL_SILENCE	0x29
#define SVEN_MODULE_EVENT_AUD_IO_ATC_INPUT_DEQUEUE	0x2a
#define SVEN_MODULE_EVENT_AUD_IO_ATC_TIME_STAMP	0x2b
#define SVEN_MODULE_EVENT_AUD_IO_ATC_GET_BASE_NUMBERS	0x2c
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PTS_LATE	0x2d
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PTS_EARLY	0x2e
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PAD_SILENCE	0x2f
#define SVEN_MODULE_EVENT_AUD_IO_ATC_FIRST_PTS_NOT_FOUND	0x30
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_STATE	0x31
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PTS_LATE_FFWD	0x32
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PTS_EARLY_FFWD	0x33
#define SVEN_MODULE_EVENT_AUD_IO_ATC_DROPPED_SAMPLES	0x34
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_NEW_ALARM_CLOCK	0x35
#define SVEN_MODULE_EVENT_AUD_IO_ATC_AFTER_EVENT_WAIT	0x36
#define SVEN_MODULE_EVENT_AUD_IO_ATC_CALC_FIRST_FRAME	0x37
#define SVEN_MODULE_EVENT_AUD_IO_ATC_INVALID_METADATA	0x38
#define SVEN_MODULE_EVENT_AUD_IO_ATC_INPUT_METADATA	0x39
#define SVEN_MODULE_EVENT_AUD_IO_ATC_RESET_STREAM	0x3a
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SILENCE_TOP_OFF_ERROR	0x3b
#define SVEN_MODULE_EVENT_AUD_IO_ATC_CLOCK_DRIFT_DETECT	0x3c
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_TIMING_ACCURACY	0x3d
#define SVEN_MODULE_EVENT_AUD_IO_ATC_UNDERRUN_DETECTED	0x3e
#define SVEN_MODULE_EVENT_AUD_IO_ATC_DISCARDED_BUFFER	0x3f
#define SVEN_MODULE_EVENT_AUD_IO_ATC_NEWSEGMENT	0x40
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SCALE_PTS	0x41
#define SVEN_MODULE_EVENT_AUD_IO_ATC_INPUT_DEQUEUE_FAILED	0x42
#define SVEN_MODULE_EVENT_AUD_IO_ATC_OUTPUT_ENQUEUE_FAILED	0x43
#define SVEN_MODULE_EVENT_AUD_IO_ATC_OUTPUT_ATEMPT_LATE	0x44
#define SVEN_MODULE_EVENT_AUD_IO_ATC_PTS_EARLY_DISCONTINUITY_DISCARD	0x45
#define SVEN_MODULE_EVENT_AUD_IO_ATC_RENDER_DRIFT_DETECTED	0x46
#define SVEN_MODULE_EVENT_AUD_IO_ATC_STOP_TIME_CHECK	0x47
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_SLAVE_CLOCK	0x48
#define SVEN_MODULE_EVENT_AUD_IO_ATC_ADJUST_SLAVE_CLOCK	0x49
#define SVEN_MODULE_EVENT_AUD_IO_ATC_SET_PTS_MODE	0x4a
#define SVEN_MODULE_EVENT_AUD_IO_ATC_OUT_OF_SEGMENT_DROP	0x4b
#define SVEN_MODULE_EVENT_AUD_IO_ATC_START_OF_SEGMENT_FOUND	0x4c
#define SVEN_MODULE_EVENT_AUD_IO_ATC_INPUT_CLOCK_DRIFT_DETECT	0x4d
#define SVEN_MODULE_EVENT_AUD_IO_ATC_DISCONTINUITY_UPDATE	0x4e
#define SVEN_MODULE_EVENT_AUD_IO_ATC_DISCONTINUITY_SILENCE_FILL	0x4f
#define SVEN_MODULE_EVENT_AUD_IO_ATC_OUTPUT_ENQUEUE	0x50
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_STARTED	0x61
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_PUSH_BUFFER	0x62
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_PULL_BUFFER	0x63
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_BUFFER_EMPTY_CALLBACK	0x64
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_BUFFER_DONE	0x65
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_SAFE_TO_CLOSE_CALLBACK	0x66
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_ADDED_SILENCE	0x67
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_DEQUEUE	0x68
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_BUFFER_DONE_TIMING_INFO	0x69
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_CLOCK_ACCURACY	0x6a
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_TIME_STAMP_LATE	0x6b
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_TRY_TO_PLAY	0x6c
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_DEQUEUE_FAILED	0x6d
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_BEHIND_NOTIFY_ATC	0x6e
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_SAMPLE_COUNT_RESYNC	0x6f
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_CHUNK_SIZE_MISMATCH	0x70
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_TIME_STAMP_EARLY	0x71
#define SVEN_MODULE_EVENT_AUD_IO_RENDER_CLOCK_RECOVERY	0x72
#define SVEN_MODULE_EVENT_AUD_IO_HAL_RENDER_NODE_CLEAN_UP	0x81
#define SVEN_MODULE_EVENT_AUD_IO_HAL_RENDER_LL_INTERUPT	0x82
#define SVEN_MODULE_EVENT_AUD_IO_HAL_RENDER_BUFFER_ADD	0x83
#define SVEN_MODULE_EVENT_AUD_IO_HAL_RENDER_BUFFER_ADD_FAILED	0x84
#define SVEN_MODULE_EVENT_AUD_IO_PSM_WAITING_FOR_IO_EVENT	0xa1
#define SVEN_MODULE_EVENT_AUD_IO_PSM_INPUT_JOB_SENT	0xa2
#define SVEN_MODULE_EVENT_AUD_IO_PSM_INPUT_JOB_SEND_ERROR	0xa3
#define SVEN_MODULE_EVENT_AUD_IO_PSM_INPUT_JOB_QUEUE_FULL	0xa4
#define SVEN_MODULE_EVENT_AUD_IO_PSM_INPUT_JOB_NONE	0xa5
#define SVEN_MODULE_EVENT_AUD_IO_PSM_INPUT_JOB_DEQUEUED	0xa6
#define SVEN_MODULE_EVENT_AUD_IO_PSM_OUTPUT_JOB_RECEIVED	0xa7
#define SVEN_MODULE_EVENT_AUD_IO_PSM_OUTPUT_JOB_RECEIVE_ERROR	0xa8
#define SVEN_MODULE_EVENT_AUD_IO_PSM_OUTPUT_QUEUE_FULL	0xa9
#define SVEN_MODULE_EVENT_AUD_IO_PSM_OUTPUT_JOB_NONE	0xaa
#define SVEN_MODULE_EVENT_AUD_IO_PSM_OUTPUT_BUFFER_ENQUEUED	0xab
#define SVEN_MODULE_EVENT_AUD_IO_PSM_INPUT_JOB_ALLIGN_TS	0xac
#define SVEN_MODULE_EVENT_AUD_IO_DSP_IPCD_INTR	0xc1
#define SVEN_MODULE_EVENT_AUD_IO_DSP_IPCX_INTR	0xc2
#define SVEN_MODULE_EVENT_AUD_IO_DSP_WRITE_INPUT_JOB	0xc3
#define SVEN_MODULE_EVENT_AUD_IO_DSP_READ_OUTPUT_JOB	0xc4
#define SVEN_MODULE_EVENT_AUD_IO_DSP_JOB_DESC	0xc5
#define SVEN_MODULE_EVENT_AUD_IO_DSP_HTOD_MESSAGE	0xc6
#define SVEN_MODULE_EVENT_AUD_IO_DSP_HTOD_MESSAGE_DSP_BUSY	0xc7
#define SVEN_MODULE_EVENT_AUD_IO_DSP_HTOD_MESSAGE_DSP_NO_RESPONSE	0xc8
#define SVEN_MODULE_EVENT_AUD_IO_DSP_HTOD_MESSAGE_DSP_RETURNED_ERROR	0xc9
#define SVEN_MODULE_EVENT_AUD_IO_DSP_HTOD_MESSAGE_DSP_SENT_ERROR	0xc9
#define SVEN_MODULE_EVENT_AUD_IO_ALSA_SHIM_PREPARE	0xd7
#define SVEN_MODULE_EVENT_AUD_IO_ALSA_SHIM_TRIGGER	0xd8
#define SVEN_MODULE_EVENT_AUD_IO_ALSA_SHIM_POINTER	0xd9
#define SVEN_MODULE_EVENT_AUD_IO_ALSA_SHIM_ACK	0xda
#define SVEN_MODULE_EVENT_AUD_IO_ALSA_SHIM_COPY	0xdb
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_STARTED	0xe2
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_ADD_BUFFER	0xe3
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_LATENCY	0xe4
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_BUFFER_DISCARD	0xe5
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_BUFFER_EMPTY	0xe6
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_BUFFER_DONE	0xe7
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_SAFE_TO_CLOSE	0xe8
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_DEV_STATE	0xe9
#define SVEN_MODULE_EVENT_AUD_IO_CAPTURE_CLOCK_RECOVERY	0xea
#define SVEN_MODULE_EVENT_AUD_IO_HAL_CAPTURE_NODE_CLEAN_UP	0xf1
#define SVEN_MODULE_EVENT_AUD_IO_HAL_CAPTURE_LL_INTERUPT	0xf2
#define SVEN_MODULE_EVENT_AUD_IO_HAL_CAPTURE_BUFFER_ADD	0xf3
#define SVEN_MODULE_EVENT_AUD_IO_HAL_CAPTURE_BUFFER_ADD_FAILED	0xf4


#endif /* AUD_IO_REGOFFS_H */
