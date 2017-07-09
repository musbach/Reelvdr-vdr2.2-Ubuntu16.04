#ifndef AUDIO_REGOFFS_H
#define AUDIO_REGOFFS_H 1
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


/* Module AUDIO CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_AUDIO_CSR	0x80000 /* Configuration and Status Register. */ 
	#define BITFIELD_AUDIO_CSR	 0x80000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_CSR */
	#define BLSB_AUDIO_CSR_XREMAP	16
	#define BLSB_AUDIO_CSR_RSVD_15_8	8
	#define BLSB_AUDIO_CSR_REMAP	4
	#define BLSB_AUDIO_CSR_DSP_INIT	3
	#define BLSB_AUDIO_CSR_DSP_RST	2
	#define BLSB_AUDIO_CSR_SWRST	1
	#define BLSB_AUDIO_CSR_CLKEN	0
	/* Register Bit Widths for AUDIO_CSR */
	#define BWID_AUDIO_CSR_XREMAP	16
	#define BWID_AUDIO_CSR_RSVD_15_8	8
	#define BWID_AUDIO_CSR_REMAP	4
	#define BWID_AUDIO_CSR_DSP_INIT	1
	#define BWID_AUDIO_CSR_DSP_RST	1
	#define BWID_AUDIO_CSR_SWRST	1
	#define BWID_AUDIO_CSR_CLKEN	1
	/* Register Bit MASKS for AUDIO_CSR */
	#define BMSK_AUDIO_CSR_XREMAP	0xffff0000 /* The address of the window into the Intel MSA address space for Intel XScale core accesses */
	#define BMSK_AUDIO_CSR_RSVD_15_8	0x0000ff00 /*  */
	#define BMSK_AUDIO_CSR_REMAP	0x000000f0 /*  */
	#define BMSK_AUDIO_CSR_DSP_INIT	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_CSR_DSP_RST	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_CSR_SWRST	(1<<1) /* == 0x00000002: Software Reset. When asserted, active low, drives reset to all dependent blocks, except DSP processor. */
	#define BMSK_AUDIO_CSR_CLKEN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_CSR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_CSR_XREMAP	 0x80000, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_CSR_RSVD_15_8	 0x80000, 8, 8, 0x0000ff00
	#define BITFIELD_AUDIO_CSR_REMAP	 0x80000, 4, 4, 0x000000f0
	#define BITFIELD_AUDIO_CSR_DSP_INIT	 0x80000, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_CSR_DSP_RST	 0x80000, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_CSR_SWRST	 0x80000, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_CSR_CLKEN	 0x80000, 0, 1, 0x00000001
#define ROFF_AUDIO_ISRX	0x80004 /* XScale Interrupt Status Register. */ 
	#define BITFIELD_AUDIO_ISRX	 0x80004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_ISRX */
	#define BLSB_AUDIO_ISRX_RSVD_31_24	30
	#define BLSB_AUDIO_ISRX_DMA3_DES	23
	#define BLSB_AUDIO_ISRX_DMA3_SRC	22
	#define BLSB_AUDIO_ISRX_DMA2_DES	21
	#define BLSB_AUDIO_ISRX_DMA2_SRC	20
	#define BLSB_AUDIO_ISRX_DMA1_DES	19
	#define BLSB_AUDIO_ISRX_DMA1_SRC	18
	#define BLSB_AUDIO_ISRX_DMA0_DES	17
	#define BLSB_AUDIO_ISRX_DMA0_SRC	16
	#define BLSB_AUDIO_ISRX_RSVD_15_11	15
	#define BLSB_AUDIO_ISRX_IPCD	10
	#define BLSB_AUDIO_ISRX_IPCX	9
	#define BLSB_AUDIO_ISRX_I2S3_TO_CPU	8
	#define BLSB_AUDIO_ISRX_I2S2_TO_CPU	7
	#define BLSB_AUDIO_ISRX_I2S1_TO_CPU	6
	#define BLSB_AUDIO_ISRX_RSVD_5_2	2
	#define BLSB_AUDIO_ISRX_ETS1	1
	#define BLSB_AUDIO_ISRX_ETS0	0
	/* Register Bit Widths for AUDIO_ISRX */
	#define BWID_AUDIO_ISRX_RSVD_31_24	8
	#define BWID_AUDIO_ISRX_DMA3_DES	1
	#define BWID_AUDIO_ISRX_DMA3_SRC	1
	#define BWID_AUDIO_ISRX_DMA2_DES	1
	#define BWID_AUDIO_ISRX_DMA2_SRC	1
	#define BWID_AUDIO_ISRX_DMA1_DES	1
	#define BWID_AUDIO_ISRX_DMA1_SRC	1
	#define BWID_AUDIO_ISRX_DMA0_DES	1
	#define BWID_AUDIO_ISRX_DMA0_SRC	1
	#define BWID_AUDIO_ISRX_RSVD_15_11	5
	#define BWID_AUDIO_ISRX_IPCD	1
	#define BWID_AUDIO_ISRX_IPCX	1
	#define BWID_AUDIO_ISRX_I2S3_TO_CPU	1
	#define BWID_AUDIO_ISRX_I2S2_TO_CPU	1
	#define BWID_AUDIO_ISRX_I2S1_TO_CPU	1
	#define BWID_AUDIO_ISRX_RSVD_5_2	4
	#define BWID_AUDIO_ISRX_ETS1	1
	#define BWID_AUDIO_ISRX_ETS0	1
	/* Register Bit MASKS for AUDIO_ISRX */
	#define BMSK_AUDIO_ISRX_RSVD_31_24	0xc0000000 /*  */
	#define BMSK_AUDIO_ISRX_DMA3_DES	(1<<23) /* == 0x00800000:  */
	#define BMSK_AUDIO_ISRX_DMA3_SRC	(1<<22) /* == 0x00400000:  */
	#define BMSK_AUDIO_ISRX_DMA2_DES	(1<<21) /* == 0x00200000:  */
	#define BMSK_AUDIO_ISRX_DMA2_SRC	(1<<20) /* == 0x00100000:  */
	#define BMSK_AUDIO_ISRX_DMA1_DES	(1<<19) /* == 0x00080000:  */
	#define BMSK_AUDIO_ISRX_DMA1_SRC	(1<<18) /* == 0x00040000:  */
	#define BMSK_AUDIO_ISRX_DMA0_DES	(1<<17) /* == 0x00020000:  */
	#define BMSK_AUDIO_ISRX_DMA0_SRC	(1<<16) /* == 0x00010000:  */
	#define BMSK_AUDIO_ISRX_RSVD_15_11	0x000f8000 /*  */
	#define BMSK_AUDIO_ISRX_IPCD	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_ISRX_IPCX	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_ISRX_I2S3_TO_CPU	(1<<8) /* == 0x00000100: 1  Pending interrupt; 0  Not pending */
	#define BMSK_AUDIO_ISRX_I2S2_TO_CPU	(1<<7) /* == 0x00000080: 1  Pending interrupt; 0  Not pending */
	#define BMSK_AUDIO_ISRX_I2S1_TO_CPU	(1<<6) /* == 0x00000040: 1  Pending interrupt; 0  Not pending */
	#define BMSK_AUDIO_ISRX_RSVD_5_2	0x0000003c /*  */
	#define BMSK_AUDIO_ISRX_ETS1	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_ISRX_ETS0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_ISRX - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_ISRX_RSVD_31_24	 0x80004, 30, 8, 0xc0000000
	#define BITFIELD_AUDIO_ISRX_DMA3_DES	 0x80004, 23, 1, 0x00800000
	#define BITFIELD_AUDIO_ISRX_DMA3_SRC	 0x80004, 22, 1, 0x00400000
	#define BITFIELD_AUDIO_ISRX_DMA2_DES	 0x80004, 21, 1, 0x00200000
	#define BITFIELD_AUDIO_ISRX_DMA2_SRC	 0x80004, 20, 1, 0x00100000
	#define BITFIELD_AUDIO_ISRX_DMA1_DES	 0x80004, 19, 1, 0x00080000
	#define BITFIELD_AUDIO_ISRX_DMA1_SRC	 0x80004, 18, 1, 0x00040000
	#define BITFIELD_AUDIO_ISRX_DMA0_DES	 0x80004, 17, 1, 0x00020000
	#define BITFIELD_AUDIO_ISRX_DMA0_SRC	 0x80004, 16, 1, 0x00010000
	#define BITFIELD_AUDIO_ISRX_RSVD_15_11	 0x80004, 15, 5, 0x000f8000
	#define BITFIELD_AUDIO_ISRX_IPCD	 0x80004, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_ISRX_IPCX	 0x80004, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_ISRX_I2S3_TO_CPU	 0x80004, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_ISRX_I2S2_TO_CPU	 0x80004, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_ISRX_I2S1_TO_CPU	 0x80004, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_ISRX_RSVD_5_2	 0x80004, 2, 4, 0x0000003c
	#define BITFIELD_AUDIO_ISRX_ETS1	 0x80004, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_ISRX_ETS0	 0x80004, 0, 1, 0x00000001
#define ROFF_AUDIO_ISRD	0x80008 /* Intel MSA Interrupt Status Register. */ 
	#define BITFIELD_AUDIO_ISRD	 0x80008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_ISRD */
	#define BLSB_AUDIO_ISRD_DEBUG_BRK	31
	#define BLSB_AUDIO_ISRD_RSVD_30_24	24
	#define BLSB_AUDIO_ISRD_DMA3_DES	23
	#define BLSB_AUDIO_ISRD_DMA3_SRC	22
	#define BLSB_AUDIO_ISRD_DMA2_DES	21
	#define BLSB_AUDIO_ISRD_DMA2_SRC	20
	#define BLSB_AUDIO_ISRD_DMA1_DES	19
	#define BLSB_AUDIO_ISRD_DMA1_SRC	18
	#define BLSB_AUDIO_ISRD_DMA0_DES	17
	#define BLSB_AUDIO_ISRD_DMA0_SRC	16
	#define BLSB_AUDIO_ISRD_RSVD_15_11	15
	#define BLSB_AUDIO_ISRD_IPCD	10
	#define BLSB_AUDIO_ISRD_IPCX	9
	#define BLSB_AUDIO_ISRD_I2S3_TO_DSP	8
	#define BLSB_AUDIO_ISRD_I2S2_TO_DSP	7
	#define BLSB_AUDIO_ISRD_I2S1_TO_DSP	6
	#define BLSB_AUDIO_ISRD_RSVD_5_2	2
	#define BLSB_AUDIO_ISRD_ETS1	1
	#define BLSB_AUDIO_ISRD_ETS0	0
	/* Register Bit Widths for AUDIO_ISRD */
	#define BWID_AUDIO_ISRD_DEBUG_BRK	1
	#define BWID_AUDIO_ISRD_RSVD_30_24	7
	#define BWID_AUDIO_ISRD_DMA3_DES	1
	#define BWID_AUDIO_ISRD_DMA3_SRC	1
	#define BWID_AUDIO_ISRD_DMA2_DES	1
	#define BWID_AUDIO_ISRD_DMA2_SRC	1
	#define BWID_AUDIO_ISRD_DMA1_DES	1
	#define BWID_AUDIO_ISRD_DMA1_SRC	1
	#define BWID_AUDIO_ISRD_DMA0_DES	1
	#define BWID_AUDIO_ISRD_DMA0_SRC	1
	#define BWID_AUDIO_ISRD_RSVD_15_11	5
	#define BWID_AUDIO_ISRD_IPCD	1
	#define BWID_AUDIO_ISRD_IPCX	1
	#define BWID_AUDIO_ISRD_I2S3_TO_DSP	1
	#define BWID_AUDIO_ISRD_I2S2_TO_DSP	1
	#define BWID_AUDIO_ISRD_I2S1_TO_DSP	1
	#define BWID_AUDIO_ISRD_RSVD_5_2	4
	#define BWID_AUDIO_ISRD_ETS1	1
	#define BWID_AUDIO_ISRD_ETS0	1
	/* Register Bit MASKS for AUDIO_ISRD */
	#define BMSK_AUDIO_ISRD_DEBUG_BRK	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_ISRD_RSVD_30_24	0x7f000000 /*  */
	#define BMSK_AUDIO_ISRD_DMA3_DES	(1<<23) /* == 0x00800000:  */
	#define BMSK_AUDIO_ISRD_DMA3_SRC	(1<<22) /* == 0x00400000:  */
	#define BMSK_AUDIO_ISRD_DMA2_DES	(1<<21) /* == 0x00200000:  */
	#define BMSK_AUDIO_ISRD_DMA2_SRC	(1<<20) /* == 0x00100000:  */
	#define BMSK_AUDIO_ISRD_DMA1_DES	(1<<19) /* == 0x00080000:  */
	#define BMSK_AUDIO_ISRD_DMA1_SRC	(1<<18) /* == 0x00040000:  */
	#define BMSK_AUDIO_ISRD_DMA0_DES	(1<<17) /* == 0x00020000:  */
	#define BMSK_AUDIO_ISRD_DMA0_SRC	(1<<16) /* == 0x00010000:  */
	#define BMSK_AUDIO_ISRD_RSVD_15_11	0x000f8000 /*  */
	#define BMSK_AUDIO_ISRD_IPCD	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_ISRD_IPCX	(1<<9) /* == 0x00000200: Interrupt Request to MSA */
	#define BMSK_AUDIO_ISRD_I2S3_TO_DSP	(1<<8) /* == 0x00000100: Interrupt pending to DSP */
	#define BMSK_AUDIO_ISRD_I2S2_TO_DSP	(1<<7) /* == 0x00000080: Interrupt pending to DSP */
	#define BMSK_AUDIO_ISRD_I2S1_TO_DSP	(1<<6) /* == 0x00000040: Interrupt pending to DSP */
	#define BMSK_AUDIO_ISRD_RSVD_5_2	0x0000003c /*  */
	#define BMSK_AUDIO_ISRD_ETS1	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_ISRD_ETS0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_ISRD - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_ISRD_DEBUG_BRK	 0x80008, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_ISRD_RSVD_30_24	 0x80008, 24, 7, 0x7f000000
	#define BITFIELD_AUDIO_ISRD_DMA3_DES	 0x80008, 23, 1, 0x00800000
	#define BITFIELD_AUDIO_ISRD_DMA3_SRC	 0x80008, 22, 1, 0x00400000
	#define BITFIELD_AUDIO_ISRD_DMA2_DES	 0x80008, 21, 1, 0x00200000
	#define BITFIELD_AUDIO_ISRD_DMA2_SRC	 0x80008, 20, 1, 0x00100000
	#define BITFIELD_AUDIO_ISRD_DMA1_DES	 0x80008, 19, 1, 0x00080000
	#define BITFIELD_AUDIO_ISRD_DMA1_SRC	 0x80008, 18, 1, 0x00040000
	#define BITFIELD_AUDIO_ISRD_DMA0_DES	 0x80008, 17, 1, 0x00020000
	#define BITFIELD_AUDIO_ISRD_DMA0_SRC	 0x80008, 16, 1, 0x00010000
	#define BITFIELD_AUDIO_ISRD_RSVD_15_11	 0x80008, 15, 5, 0x000f8000
	#define BITFIELD_AUDIO_ISRD_IPCD	 0x80008, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_ISRD_IPCX	 0x80008, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_ISRD_I2S3_TO_DSP	 0x80008, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_ISRD_I2S2_TO_DSP	 0x80008, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_ISRD_I2S1_TO_DSP	 0x80008, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_ISRD_RSVD_5_2	 0x80008, 2, 4, 0x0000003c
	#define BITFIELD_AUDIO_ISRD_ETS1	 0x80008, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_ISRD_ETS0	 0x80008, 0, 1, 0x00000001
#define ROFF_AUDIO_IMRX	0x8000c /* XScale Interrupt Mask Register. */ 
	#define BITFIELD_AUDIO_IMRX	 0x8000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_IMRX */
	#define BLSB_AUDIO_IMRX_RSVD_31_24	24
	#define BLSB_AUDIO_IMRX_DMA3_DES	23
	#define BLSB_AUDIO_IMRX_DMA3_SRC	22
	#define BLSB_AUDIO_IMRX_DMA2_DES	21
	#define BLSB_AUDIO_IMRX_DMA2_SRC	20
	#define BLSB_AUDIO_IMRX_DMA1_DES	19
	#define BLSB_AUDIO_IMRX_DMA1_SRC	18
	#define BLSB_AUDIO_IMRX_DMA0_DES	17
	#define BLSB_AUDIO_IMRX_DMA0_SRC	16
	#define BLSB_AUDIO_IMRX_RSVD_15_11	15
	#define BLSB_AUDIO_IMRX_IPCD	10
	#define BLSB_AUDIO_IMRX_IPCX	9
	#define BLSB_AUDIO_IMRX_I2S3_TO_DSP	8
	#define BLSB_AUDIO_IMRX_I2S2_TO_DSP	7
	#define BLSB_AUDIO_IMRX_I2S1_TO_DSP	6
	#define BLSB_AUDIO_IMRX_RSVD_5_2	2
	#define BLSB_AUDIO_IMRX_ETS1	1
	#define BLSB_AUDIO_IMRX_ETS0	0
	/* Register Bit Widths for AUDIO_IMRX */
	#define BWID_AUDIO_IMRX_RSVD_31_24	8
	#define BWID_AUDIO_IMRX_DMA3_DES	1
	#define BWID_AUDIO_IMRX_DMA3_SRC	1
	#define BWID_AUDIO_IMRX_DMA2_DES	1
	#define BWID_AUDIO_IMRX_DMA2_SRC	1
	#define BWID_AUDIO_IMRX_DMA1_DES	1
	#define BWID_AUDIO_IMRX_DMA1_SRC	1
	#define BWID_AUDIO_IMRX_DMA0_DES	1
	#define BWID_AUDIO_IMRX_DMA0_SRC	1
	#define BWID_AUDIO_IMRX_RSVD_15_11	5
	#define BWID_AUDIO_IMRX_IPCD	1
	#define BWID_AUDIO_IMRX_IPCX	1
	#define BWID_AUDIO_IMRX_I2S3_TO_DSP	1
	#define BWID_AUDIO_IMRX_I2S2_TO_DSP	1
	#define BWID_AUDIO_IMRX_I2S1_TO_DSP	1
	#define BWID_AUDIO_IMRX_RSVD_5_2	4
	#define BWID_AUDIO_IMRX_ETS1	1
	#define BWID_AUDIO_IMRX_ETS0	1
	/* Register Bit MASKS for AUDIO_IMRX */
	#define BMSK_AUDIO_IMRX_RSVD_31_24	0xff000000 /*  */
	#define BMSK_AUDIO_IMRX_DMA3_DES	(1<<23) /* == 0x00800000:  */
	#define BMSK_AUDIO_IMRX_DMA3_SRC	(1<<22) /* == 0x00400000:  */
	#define BMSK_AUDIO_IMRX_DMA2_DES	(1<<21) /* == 0x00200000:  */
	#define BMSK_AUDIO_IMRX_DMA2_SRC	(1<<20) /* == 0x00100000:  */
	#define BMSK_AUDIO_IMRX_DMA1_DES	(1<<19) /* == 0x00080000:  */
	#define BMSK_AUDIO_IMRX_DMA1_SRC	(1<<18) /* == 0x00040000:  */
	#define BMSK_AUDIO_IMRX_DMA0_DES	(1<<17) /* == 0x00020000:  */
	#define BMSK_AUDIO_IMRX_DMA0_SRC	(1<<16) /* == 0x00010000:  */
	#define BMSK_AUDIO_IMRX_RSVD_15_11	0x000f8000 /*  */
	#define BMSK_AUDIO_IMRX_IPCD	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_IMRX_IPCX	(1<<9) /* == 0x00000200: Interrupt Enable to XScale */
	#define BMSK_AUDIO_IMRX_I2S3_TO_DSP	(1<<8) /* == 0x00000100: (audio capture) Interrupt Enable to XScale */
	#define BMSK_AUDIO_IMRX_I2S2_TO_DSP	(1<<7) /* == 0x00000080: (stereo) interrupt Enable to XScale */
	#define BMSK_AUDIO_IMRX_I2S1_TO_DSP	(1<<6) /* == 0x00000040: (6-channel) interrupt Enable to XScale */
	#define BMSK_AUDIO_IMRX_RSVD_5_2	0x0000003c /*  */
	#define BMSK_AUDIO_IMRX_ETS1	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_IMRX_ETS0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_IMRX - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_IMRX_RSVD_31_24	 0x8000c, 24, 8, 0xff000000
	#define BITFIELD_AUDIO_IMRX_DMA3_DES	 0x8000c, 23, 1, 0x00800000
	#define BITFIELD_AUDIO_IMRX_DMA3_SRC	 0x8000c, 22, 1, 0x00400000
	#define BITFIELD_AUDIO_IMRX_DMA2_DES	 0x8000c, 21, 1, 0x00200000
	#define BITFIELD_AUDIO_IMRX_DMA2_SRC	 0x8000c, 20, 1, 0x00100000
	#define BITFIELD_AUDIO_IMRX_DMA1_DES	 0x8000c, 19, 1, 0x00080000
	#define BITFIELD_AUDIO_IMRX_DMA1_SRC	 0x8000c, 18, 1, 0x00040000
	#define BITFIELD_AUDIO_IMRX_DMA0_DES	 0x8000c, 17, 1, 0x00020000
	#define BITFIELD_AUDIO_IMRX_DMA0_SRC	 0x8000c, 16, 1, 0x00010000
	#define BITFIELD_AUDIO_IMRX_RSVD_15_11	 0x8000c, 15, 5, 0x000f8000
	#define BITFIELD_AUDIO_IMRX_IPCD	 0x8000c, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_IMRX_IPCX	 0x8000c, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_IMRX_I2S3_TO_DSP	 0x8000c, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_IMRX_I2S2_TO_DSP	 0x8000c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_IMRX_I2S1_TO_DSP	 0x8000c, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_IMRX_RSVD_5_2	 0x8000c, 2, 4, 0x0000003c
	#define BITFIELD_AUDIO_IMRX_ETS1	 0x8000c, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_IMRX_ETS0	 0x8000c, 0, 1, 0x00000001
#define ROFF_AUDIO_IMRD	0x80010 /* Intel MSA Interrupt Mask Register. */ 
	#define BITFIELD_AUDIO_IMRD	 0x80010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_IMRD */
	#define BLSB_AUDIO_IMRD_DEBUG_BRK	31
	#define BLSB_AUDIO_IMRD_RSVD_30_24	24
	#define BLSB_AUDIO_IMRD_DMA3_DES	23
	#define BLSB_AUDIO_IMRD_DMA3_SRC	22
	#define BLSB_AUDIO_IMRD_DMA2_DES	21
	#define BLSB_AUDIO_IMRD_DMA2_SRC	20
	#define BLSB_AUDIO_IMRD_DMA1_DES	19
	#define BLSB_AUDIO_IMRD_DMA1_SRC	18
	#define BLSB_AUDIO_IMRD_DMA0_DES	17
	#define BLSB_AUDIO_IMRD_DMA0_SRC	16
	#define BLSB_AUDIO_IMRD_RSVD_15_11	15
	#define BLSB_AUDIO_IMRD_IPCD	10
	#define BLSB_AUDIO_IMRD_IPCX	9
	#define BLSB_AUDIO_IMRD_I2S3_TO_DSP	8
	#define BLSB_AUDIO_IMRD_I2S2_TO_DSP	7
	#define BLSB_AUDIO_IMRD_I2S1_TO_DSP	6
	#define BLSB_AUDIO_IMRD_RSVD_5_2	2
	#define BLSB_AUDIO_IMRD_ETS1	1
	#define BLSB_AUDIO_IMRD_ETS0	0
	/* Register Bit Widths for AUDIO_IMRD */
	#define BWID_AUDIO_IMRD_DEBUG_BRK	1
	#define BWID_AUDIO_IMRD_RSVD_30_24	7
	#define BWID_AUDIO_IMRD_DMA3_DES	1
	#define BWID_AUDIO_IMRD_DMA3_SRC	1
	#define BWID_AUDIO_IMRD_DMA2_DES	1
	#define BWID_AUDIO_IMRD_DMA2_SRC	1
	#define BWID_AUDIO_IMRD_DMA1_DES	1
	#define BWID_AUDIO_IMRD_DMA1_SRC	1
	#define BWID_AUDIO_IMRD_DMA0_DES	1
	#define BWID_AUDIO_IMRD_DMA0_SRC	1
	#define BWID_AUDIO_IMRD_RSVD_15_11	5
	#define BWID_AUDIO_IMRD_IPCD	1
	#define BWID_AUDIO_IMRD_IPCX	1
	#define BWID_AUDIO_IMRD_I2S3_TO_DSP	1
	#define BWID_AUDIO_IMRD_I2S2_TO_DSP	1
	#define BWID_AUDIO_IMRD_I2S1_TO_DSP	1
	#define BWID_AUDIO_IMRD_RSVD_5_2	4
	#define BWID_AUDIO_IMRD_ETS1	1
	#define BWID_AUDIO_IMRD_ETS0	1
	/* Register Bit MASKS for AUDIO_IMRD */
	#define BMSK_AUDIO_IMRD_DEBUG_BRK	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_IMRD_RSVD_30_24	0x7f000000 /*  */
	#define BMSK_AUDIO_IMRD_DMA3_DES	(1<<23) /* == 0x00800000:  */
	#define BMSK_AUDIO_IMRD_DMA3_SRC	(1<<22) /* == 0x00400000:  */
	#define BMSK_AUDIO_IMRD_DMA2_DES	(1<<21) /* == 0x00200000:  */
	#define BMSK_AUDIO_IMRD_DMA2_SRC	(1<<20) /* == 0x00100000:  */
	#define BMSK_AUDIO_IMRD_DMA1_DES	(1<<19) /* == 0x00080000:  */
	#define BMSK_AUDIO_IMRD_DMA1_SRC	(1<<18) /* == 0x00040000:  */
	#define BMSK_AUDIO_IMRD_DMA0_DES	(1<<17) /* == 0x00020000:  */
	#define BMSK_AUDIO_IMRD_DMA0_SRC	(1<<16) /* == 0x00010000:  */
	#define BMSK_AUDIO_IMRD_RSVD_15_11	0x000f8000 /*  */
	#define BMSK_AUDIO_IMRD_IPCD	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_IMRD_IPCX	(1<<9) /* == 0x00000200: Interrupt Request to MSA */
	#define BMSK_AUDIO_IMRD_I2S3_TO_DSP	(1<<8) /* == 0x00000100: Interrupt Enable to MSA */
	#define BMSK_AUDIO_IMRD_I2S2_TO_DSP	(1<<7) /* == 0x00000080: Interrupt Enable to MSA */
	#define BMSK_AUDIO_IMRD_I2S1_TO_DSP	(1<<6) /* == 0x00000040: Interrupt Enable to MSA */
	#define BMSK_AUDIO_IMRD_RSVD_5_2	0x0000003c /*  */
	#define BMSK_AUDIO_IMRD_ETS1	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_IMRD_ETS0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_IMRD - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_IMRD_DEBUG_BRK	 0x80010, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_IMRD_RSVD_30_24	 0x80010, 24, 7, 0x7f000000
	#define BITFIELD_AUDIO_IMRD_DMA3_DES	 0x80010, 23, 1, 0x00800000
	#define BITFIELD_AUDIO_IMRD_DMA3_SRC	 0x80010, 22, 1, 0x00400000
	#define BITFIELD_AUDIO_IMRD_DMA2_DES	 0x80010, 21, 1, 0x00200000
	#define BITFIELD_AUDIO_IMRD_DMA2_SRC	 0x80010, 20, 1, 0x00100000
	#define BITFIELD_AUDIO_IMRD_DMA1_DES	 0x80010, 19, 1, 0x00080000
	#define BITFIELD_AUDIO_IMRD_DMA1_SRC	 0x80010, 18, 1, 0x00040000
	#define BITFIELD_AUDIO_IMRD_DMA0_DES	 0x80010, 17, 1, 0x00020000
	#define BITFIELD_AUDIO_IMRD_DMA0_SRC	 0x80010, 16, 1, 0x00010000
	#define BITFIELD_AUDIO_IMRD_RSVD_15_11	 0x80010, 15, 5, 0x000f8000
	#define BITFIELD_AUDIO_IMRD_IPCD	 0x80010, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_IMRD_IPCX	 0x80010, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_IMRD_I2S3_TO_DSP	 0x80010, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_IMRD_I2S2_TO_DSP	 0x80010, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_IMRD_I2S1_TO_DSP	 0x80010, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_IMRD_RSVD_5_2	 0x80010, 2, 4, 0x0000003c
	#define BITFIELD_AUDIO_IMRD_ETS1	 0x80010, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_IMRD_ETS0	 0x80010, 0, 1, 0x00000001
#define ROFF_AUDIO_IPCX	0x80014 /* Inter-process Communication register for XScale. */ 
	#define BITFIELD_AUDIO_IPCX	 0x80014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_IPCX */
	#define BLSB_AUDIO_IPCX_BUSY	31
	#define BLSB_AUDIO_IPCX_DONE	30
	#define BLSB_AUDIO_IPCX_RSVD_29_16	16
	#define BLSB_AUDIO_IPCX_CPU_MSA_MSG	0
	/* Register Bit Widths for AUDIO_IPCX */
	#define BWID_AUDIO_IPCX_BUSY	1
	#define BWID_AUDIO_IPCX_DONE	1
	#define BWID_AUDIO_IPCX_RSVD_29_16	14
	#define BWID_AUDIO_IPCX_CPU_MSA_MSG	16
	/* Register Bit MASKS for AUDIO_IPCX */
	#define BMSK_AUDIO_IPCX_BUSY	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_IPCX_DONE	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_IPCX_RSVD_29_16	0x3fff0000 /*  */
	#define BMSK_AUDIO_IPCX_CPU_MSA_MSG	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_IPCX - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_IPCX_BUSY	 0x80014, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_IPCX_DONE	 0x80014, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_IPCX_RSVD_29_16	 0x80014, 16, 14, 0x3fff0000
	#define BITFIELD_AUDIO_IPCX_CPU_MSA_MSG	 0x80014, 0, 16, 0x0000ffff
#define ROFF_AUDIO_IPCD	0x80018 /* Inter-process Communication Intel MSA. */ 
	#define BITFIELD_AUDIO_IPCD	 0x80018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_IPCD */
	#define BLSB_AUDIO_IPCD_BUSY	31
	#define BLSB_AUDIO_IPCD_DONE	30
	#define BLSB_AUDIO_IPCD_RSVD_29_16	16
	#define BLSB_AUDIO_IPCD_MSA_CPU_MSG	0
	/* Register Bit Widths for AUDIO_IPCD */
	#define BWID_AUDIO_IPCD_BUSY	1
	#define BWID_AUDIO_IPCD_DONE	1
	#define BWID_AUDIO_IPCD_RSVD_29_16	14
	#define BWID_AUDIO_IPCD_MSA_CPU_MSG	16
	/* Register Bit MASKS for AUDIO_IPCD */
	#define BMSK_AUDIO_IPCD_BUSY	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_IPCD_DONE	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_IPCD_RSVD_29_16	0x3fff0000 /*  */
	#define BMSK_AUDIO_IPCD_MSA_CPU_MSG	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_IPCD - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_IPCD_BUSY	 0x80018, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_IPCD_DONE	 0x80018, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_IPCD_RSVD_29_16	 0x80018, 16, 14, 0x3fff0000
	#define BITFIELD_AUDIO_IPCD_MSA_CPU_MSG	 0x80018, 0, 16, 0x0000ffff
#define ROFF_AUDIO_MSARVEC	0x8001c /* Intel MSA Reset Vector. */ 
	#define BITFIELD_AUDIO_MSARVEC	 0x8001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ETS0L	0x80020 /* Interrupt Event Time Stamp register 0 LSB */ 
	#define BITFIELD_AUDIO_ETS0L	 0x80020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ETS0M	0x80024 /* Interrupt Event Time Stamp register 0 MSB */ 
	#define BITFIELD_AUDIO_ETS0M	 0x80024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ETS1L	0x80028 /* Interrupt Event Time Stamp register 1 LSB */ 
	#define BITFIELD_AUDIO_ETS1L	 0x80028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ETS1M	0x8002c /* Interrupt Event Time Stamp register 1 MSB */ 
	#define BITFIELD_AUDIO_ETS1M	 0x8002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_AUDDEC_RESERVED1	0x80030 /* Reserved */ 
	#define BITFIELD_AUDIO_AUDDEC_RESERVED1	 0x80030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_AUDDEC_RESERVED2	0x80034 /* Reserved */ 
	#define BITFIELD_AUDIO_AUDDEC_RESERVED2	 0x80034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_AUDDEC_RESERVED3	0x80038 /* Reserved */ 
	#define BITFIELD_AUDIO_AUDDEC_RESERVED3	 0x80038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_AUDDEC_RESERVED4	0x8003c /* Reserved */ 
	#define BITFIELD_AUDIO_AUDDEC_RESERVED4	 0x8003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SPL0	0x80040 /* Presentation Time Counter STC 0 LSB Preload Register */ 
	#define BITFIELD_AUDIO_SPL0	 0x80040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SPM0	0x80044 /* Presentation Time Counter STC 0 MSB Preload Register */ 
	#define BITFIELD_AUDIO_SPM0	 0x80044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SVL0	0x80048 /* Presentation Time Counter STC 0 LSB Current Value Register */ 
	#define BITFIELD_AUDIO_SVL0	 0x80048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SVM0	0x8004c /* Presentation Time Counter STC 0 MSB Current Value Register */ 
	#define BITFIELD_AUDIO_SVM0	 0x8004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SPL1	0x80050 /* Presentation Time Counter STC 1 LSB Preload Register */ 
	#define BITFIELD_AUDIO_SPL1	 0x80050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SPM1	0x80054 /* Presentation Time Counter STC 1 MSB Preload Register */ 
	#define BITFIELD_AUDIO_SPM1	 0x80054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SVL1	0x80058 /* Presentation Time Counter STC 1 LSB Current Value Register */ 
	#define BITFIELD_AUDIO_SVL1	 0x80058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SVM1	0x8005c /* Presentation Time Counter STC 1 MSB Current Value Register */ 
	#define BITFIELD_AUDIO_SVM1	 0x8005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_SCR0	0x80080 /* Presentation Time Counter STC 0 Control Register */ 
	#define BITFIELD_AUDIO_SCR0	 0x80080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_SCR0 */
	#define BLSB_AUDIO_SCR0_RSVD_31_6	3
	#define BLSB_AUDIO_SCR0_STC_Counter_90_kHz_Prescaler_SEL	5
	#define BLSB_AUDIO_SCR0_PREFILTER_CLOCK_SEL	3
	#define BLSB_AUDIO_SCR0_PCR_SEL	1
	#define BLSB_AUDIO_SCR0_Counter_Select	0
	/* Register Bit Widths for AUDIO_SCR0 */
	#define BWID_AUDIO_SCR0_RSVD_31_6	25
	#define BWID_AUDIO_SCR0_STC_Counter_90_kHz_Prescaler_SEL	1
	#define BWID_AUDIO_SCR0_PREFILTER_CLOCK_SEL	2
	#define BWID_AUDIO_SCR0_PCR_SEL	2
	#define BWID_AUDIO_SCR0_Counter_Select	1
	/* Register Bit MASKS for AUDIO_SCR0 */
	#define BMSK_AUDIO_SCR0_RSVD_31_6	0x0ffffff8 /*  */
	#define BMSK_AUDIO_SCR0_STC_Counter_90_kHz_Prescaler_SEL	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_SCR0_PREFILTER_CLOCK_SEL	0x00000018 /*  */
	#define BMSK_AUDIO_SCR0_PCR_SEL	0x00000006 /*  */
	#define BMSK_AUDIO_SCR0_Counter_Select	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_SCR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_SCR0_RSVD_31_6	 0x80080, 3, 25, 0x0ffffff8
	#define BITFIELD_AUDIO_SCR0_STC_Counter_90_kHz_Prescaler_SEL	 0x80080, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_SCR0_PREFILTER_CLOCK_SEL	 0x80080, 3, 2, 0x00000018
	#define BITFIELD_AUDIO_SCR0_PCR_SEL	 0x80080, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_SCR0_Counter_Select	 0x80080, 0, 1, 0x00000001
#define ROFF_AUDIO_SCR1	0x80084 /* Presentation Time Counter STC 1 Control Register */ 
	#define BITFIELD_AUDIO_SCR1	 0x80084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_SCR1 */
	#define BLSB_AUDIO_SCR1_RSVD_31_6	3
	#define BLSB_AUDIO_SCR1_STC_Counter_90_kHz_Prescaler_SEL	5
	#define BLSB_AUDIO_SCR1_PREFILTER_CLOCK_SEL	3
	#define BLSB_AUDIO_SCR1_PCR_SEL	1
	#define BLSB_AUDIO_SCR1_Counter_Select	0
	/* Register Bit Widths for AUDIO_SCR1 */
	#define BWID_AUDIO_SCR1_RSVD_31_6	25
	#define BWID_AUDIO_SCR1_STC_Counter_90_kHz_Prescaler_SEL	1
	#define BWID_AUDIO_SCR1_PREFILTER_CLOCK_SEL	2
	#define BWID_AUDIO_SCR1_PCR_SEL	2
	#define BWID_AUDIO_SCR1_Counter_Select	1
	/* Register Bit MASKS for AUDIO_SCR1 */
	#define BMSK_AUDIO_SCR1_RSVD_31_6	0x0ffffff8 /*  */
	#define BMSK_AUDIO_SCR1_STC_Counter_90_kHz_Prescaler_SEL	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_SCR1_PREFILTER_CLOCK_SEL	0x00000018 /*  */
	#define BMSK_AUDIO_SCR1_PCR_SEL	0x00000006 /*  */
	#define BMSK_AUDIO_SCR1_Counter_Select	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_SCR1 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_SCR1_RSVD_31_6	 0x80084, 3, 25, 0x0ffffff8
	#define BITFIELD_AUDIO_SCR1_STC_Counter_90_kHz_Prescaler_SEL	 0x80084, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_SCR1_PREFILTER_CLOCK_SEL	 0x80084, 3, 2, 0x00000018
	#define BITFIELD_AUDIO_SCR1_PCR_SEL	 0x80084, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_SCR1_Counter_Select	 0x80084, 0, 1, 0x00000001
#define ROFF_AUDIO_ACPL	0x800a0 /* Audio Capture Timestamp LSB Preload Register */ 
	#define BITFIELD_AUDIO_ACPL	 0x800a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ACPM	0x800a4 /* Audio Capture Timestamp MSB Preload Register */ 
	#define BITFIELD_AUDIO_ACPM	 0x800a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ACVL	0x800a8 /* Audio Capture Timestamp LSB Current Value Register */ 
	#define BITFIELD_AUDIO_ACVL	 0x800a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_ACVM	0x800ac /* Audio Capture Timestamp MSB Current Value Register */ 
	#define BITFIELD_AUDIO_ACVM	 0x800ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_CURR_DESCR	0x81008 /* Current descriptor address pointer */ 
	#define BITFIELD_AUDIO_DMA0_CURR_DESCR	 0x81008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_NEXT_DESCR	0x8100c /* Next descriptor address pointer. */ 
	#define BITFIELD_AUDIO_DMA0_NEXT_DESCR	 0x8100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_SRCDMA_START	0x81010 /* Start address of the Source DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA0_SRCDMA_START	 0x81010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_DSTDMA_START	0x81014 /* Start address of the Destination DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA0_DSTDMA_START	 0x81014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_SRCDMA_SIZE	0x81018 /* Total size of the block of data (in bytes) to be read from the source location. */ 
	#define BITFIELD_AUDIO_DMA0_SRCDMA_SIZE	 0x81018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_FLAGS_MODE	0x8101c /* Miscellaneous Control/Status: flags, modes, quality of service, addresses, etc. */ 
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE	 0x8101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_DMA0_FLAGS_MODE */
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_DMA_CONTEXT_ACTIVE	31
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_SRC_INT_EN	30
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_DST_INT_EN	29
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_LINK_LIST_TERM	28
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_SUB_UNIT_SEL	20
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_GAP	61
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_BURST_SZ	12
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_DMA_BURST_SZ	8
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_READ_EN	7
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUDIO_DMA0_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUDIO_DMA0_FLAGS_MODE */
	#define BWID_AUDIO_DMA0_FLAGS_MODE_DMA_CONTEXT_ACTIVE	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_SRC_INT_EN	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_DST_INT_EN	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_LINK_LIST_TERM	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_SUB_UNIT_SEL	4
	#define BWID_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_GAP	4
	#define BWID_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_BURST_SZ	5
	#define BWID_AUDIO_DMA0_FLAGS_MODE_DMA_BURST_SZ	4
	#define BWID_AUDIO_DMA0_FLAGS_MODE_READ_EN	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUDIO_DMA0_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUDIO_DMA0_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUDIO_DMA0_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUDIO_DMA0_FLAGS_MODE */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_DMA_CONTEXT_ACTIVE	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_SRC_INT_EN	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_DST_INT_EN	(1<<29) /* == 0x20000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_LINK_LIST_TERM	(1<<28) /* == 0x10000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_SUB_UNIT_SEL	0x00f00000 /*  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_GAP	0xe0000000 /*  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_BURST_SZ	0x0001f000 /*  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_DMA_BURST_SZ	0x00000f00 /*  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /*  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /*  */
	#define BMSK_AUDIO_DMA0_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_DMA0_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_DMA_CONTEXT_ACTIVE	 0x8101c, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_SRC_INT_EN	 0x8101c, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_DST_INT_EN	 0x8101c, 29, 1, 0x20000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_LINK_LIST_TERM	 0x8101c, 28, 1, 0x10000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_RD_SWAP_ENDIAN	 0x8101c, 27, 1, 0x08000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_WR_SWAP_ENDIAN	 0x8101c, 26, 1, 0x04000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_SRC_ENDIANISM	 0x8101c, 25, 1, 0x02000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_DST_ENDIANISM	 0x8101c, 24, 1, 0x01000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_SUB_UNIT_SEL	 0x8101c, 20, 4, 0x00f00000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_GAP	 0x8101c, 61, 4, 0xe0000000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_XSI_DMA_BURST_SZ	 0x8101c, 12, 5, 0x0001f000
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_DMA_BURST_SZ	 0x8101c, 8, 4, 0x00000f00
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_READ_EN	 0x8101c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_SRC_ADDR_MODE	 0x8101c, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_SRC_LINK_LIST	 0x8101c, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_WRITE_EN	 0x8101c, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_DST_ADDR_MODE	 0x8101c, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_DMA0_FLAGS_MODE_DST_LINK_LIST	 0x8101c, 0, 1, 0x00000001
#define ROFF_AUDIO_DMA0_SRCDMA_START_ALIAS	0x81020 /* This is the alias of Source DMA Start Register SRCDMA_START */ 
	#define BITFIELD_AUDIO_DMA0_SRCDMA_START_ALIAS	 0x81020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_SRCDMA_BOT	0x81024 /* Address of the bottom of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA0_SRCDMA_BOT	 0x81024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_SRCDMA_TOP	0x81028 /* Address of the top of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA0_SRCDMA_TOP	 0x81028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_DSTDMA_BOT	0x8102c /* Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA0_DSTDMA_BOT	 0x8102c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_DSTDMA_TOP	0x81030 /* Address of the top of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA0_DSTDMA_TOP	 0x81030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_DSTDMA_SIZE	0x81034 /* Size of the block of data (in bytes) to be sent to the destination location. */ 
	#define BITFIELD_AUDIO_DMA0_DSTDMA_SIZE	 0x81034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_SRCDMA_STOP	0x81038 /* Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA0_SRCDMA_STOP	 0x81038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA0_DSTDMA_STOP	0x8103c /* Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA0_DSTDMA_STOP	 0x8103c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_CURR_DESCR	0x81048 /*  Current descriptor address pointer */ 
	#define BITFIELD_AUDIO_DMA1_CURR_DESCR	 0x81048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_NEXT_DESCR	0x8104c /*  Next descriptor address pointer. */ 
	#define BITFIELD_AUDIO_DMA1_NEXT_DESCR	 0x8104c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_SRCDMA_START	0x81050 /*  Start address of the Source DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA1_SRCDMA_START	 0x81050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_DSTDMA_START	0x81054 /*  Start address of the Destination DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA1_DSTDMA_START	 0x81054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_SRCDMA_SIZE	0x81058 /*  Total size of the block of data (in bytes) to be read from the source location. */ 
	#define BITFIELD_AUDIO_DMA1_SRCDMA_SIZE	 0x81058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_FLAGS_MODE	0x8105c /* Miscellaneous Control/Status: flags, modes, quality of service, addresses, etc. */ 
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE	 0x8105c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_DMA1_FLAGS_MODE */
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_DMA_CONTEXT_ACTIVE	31
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_SRC_INT_EN	30
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_DST_INT_EN	29
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_LINK_LIST_TERM	28
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_SUB_UNIT_SEL	20
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_GAP	61
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_BURST_SZ	12
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_DMA_BURST_SZ	8
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_READ_EN	7
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUDIO_DMA1_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUDIO_DMA1_FLAGS_MODE */
	#define BWID_AUDIO_DMA1_FLAGS_MODE_DMA_CONTEXT_ACTIVE	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_SRC_INT_EN	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_DST_INT_EN	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_LINK_LIST_TERM	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_SUB_UNIT_SEL	4
	#define BWID_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_GAP	4
	#define BWID_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_BURST_SZ	5
	#define BWID_AUDIO_DMA1_FLAGS_MODE_DMA_BURST_SZ	4
	#define BWID_AUDIO_DMA1_FLAGS_MODE_READ_EN	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUDIO_DMA1_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUDIO_DMA1_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUDIO_DMA1_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUDIO_DMA1_FLAGS_MODE */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_DMA_CONTEXT_ACTIVE	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_SRC_INT_EN	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_DST_INT_EN	(1<<29) /* == 0x20000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_LINK_LIST_TERM	(1<<28) /* == 0x10000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_SUB_UNIT_SEL	0x00f00000 /*  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_GAP	0xe0000000 /*  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_BURST_SZ	0x0001f000 /*  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_DMA_BURST_SZ	0x00000f00 /*  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /*  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /*  */
	#define BMSK_AUDIO_DMA1_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_DMA1_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_DMA_CONTEXT_ACTIVE	 0x8105c, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_SRC_INT_EN	 0x8105c, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_DST_INT_EN	 0x8105c, 29, 1, 0x20000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_LINK_LIST_TERM	 0x8105c, 28, 1, 0x10000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_RD_SWAP_ENDIAN	 0x8105c, 27, 1, 0x08000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_WR_SWAP_ENDIAN	 0x8105c, 26, 1, 0x04000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_SRC_ENDIANISM	 0x8105c, 25, 1, 0x02000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_DST_ENDIANISM	 0x8105c, 24, 1, 0x01000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_SUB_UNIT_SEL	 0x8105c, 20, 4, 0x00f00000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_GAP	 0x8105c, 61, 4, 0xe0000000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_XSI_DMA_BURST_SZ	 0x8105c, 12, 5, 0x0001f000
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_DMA_BURST_SZ	 0x8105c, 8, 4, 0x00000f00
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_READ_EN	 0x8105c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_SRC_ADDR_MODE	 0x8105c, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_SRC_LINK_LIST	 0x8105c, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_WRITE_EN	 0x8105c, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_DST_ADDR_MODE	 0x8105c, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_DMA1_FLAGS_MODE_DST_LINK_LIST	 0x8105c, 0, 1, 0x00000001
#define ROFF_AUDIO_DMA1_SRCDMA_START_ALIAS	0x81060 /*  This is the alias of Source DMA Start Register SRCDMA_START */ 
	#define BITFIELD_AUDIO_DMA1_SRCDMA_START_ALIAS	 0x81060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_SRCDMA_BOT	0x81064 /*  Address of the bottom of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA1_SRCDMA_BOT	 0x81064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_SRCDMA_TOP	0x81068 /*  Address of the top of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA1_SRCDMA_TOP	 0x81068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_DSTDMA_BOT	0x8106c /*  Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA1_DSTDMA_BOT	 0x8106c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_DSTDMA_TOP	0x81070 /*  Address of the top of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA1_DSTDMA_TOP	 0x81070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_DSTDMA_SIZE	0x81074 /*  Size of the block of data (in bytes) to be sent to the destination location. */ 
	#define BITFIELD_AUDIO_DMA1_DSTDMA_SIZE	 0x81074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_SRCDMA_STOP	0x81078 /*  Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA1_SRCDMA_STOP	 0x81078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA1_DSTDMA_STOP	0x8107c /*  Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA1_DSTDMA_STOP	 0x8107c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_CURR_DESCR	0x81088 /*  Current descriptor address pointer */ 
	#define BITFIELD_AUDIO_DMA2_CURR_DESCR	 0x81088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_NEXT_DESCR	0x8108c /*  Next descriptor address pointer. */ 
	#define BITFIELD_AUDIO_DMA2_NEXT_DESCR	 0x8108c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_SRCDMA_START	0x81090 /*  Start address of the Source DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA2_SRCDMA_START	 0x81090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_DSTDMA_START	0x81094 /*  Start address of the Destination DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA2_DSTDMA_START	 0x81094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_SRCDMA_SIZE	0x81098 /*  Total size of the block of data (in bytes) to be read from the source location. */ 
	#define BITFIELD_AUDIO_DMA2_SRCDMA_SIZE	 0x81098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_FLAGS_MODE	0x8109c /* Miscellaneous Control/Status: flags, modes, quality of service, addresses, etc. */ 
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE	 0x8109c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_DMA2_FLAGS_MODE */
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_DMA_CONTEXT_ACTIVE	31
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_SRC_INT_EN	30
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_DST_INT_EN	29
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_LINK_LIST_TERM	28
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_SUB_UNIT_SEL	20
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_GAP	61
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_BURST_SZ	12
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_DMA_BURST_SZ	8
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_READ_EN	7
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUDIO_DMA2_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUDIO_DMA2_FLAGS_MODE */
	#define BWID_AUDIO_DMA2_FLAGS_MODE_DMA_CONTEXT_ACTIVE	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_SRC_INT_EN	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_DST_INT_EN	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_LINK_LIST_TERM	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_SUB_UNIT_SEL	4
	#define BWID_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_GAP	4
	#define BWID_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_BURST_SZ	5
	#define BWID_AUDIO_DMA2_FLAGS_MODE_DMA_BURST_SZ	4
	#define BWID_AUDIO_DMA2_FLAGS_MODE_READ_EN	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUDIO_DMA2_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUDIO_DMA2_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUDIO_DMA2_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUDIO_DMA2_FLAGS_MODE */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_DMA_CONTEXT_ACTIVE	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_SRC_INT_EN	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_DST_INT_EN	(1<<29) /* == 0x20000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_LINK_LIST_TERM	(1<<28) /* == 0x10000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_SUB_UNIT_SEL	0x00f00000 /*  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_GAP	0xe0000000 /*  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_BURST_SZ	0x0001f000 /*  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_DMA_BURST_SZ	0x00000f00 /*  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /*  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /*  */
	#define BMSK_AUDIO_DMA2_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_DMA2_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_DMA_CONTEXT_ACTIVE	 0x8109c, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_SRC_INT_EN	 0x8109c, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_DST_INT_EN	 0x8109c, 29, 1, 0x20000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_LINK_LIST_TERM	 0x8109c, 28, 1, 0x10000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_RD_SWAP_ENDIAN	 0x8109c, 27, 1, 0x08000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_WR_SWAP_ENDIAN	 0x8109c, 26, 1, 0x04000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_SRC_ENDIANISM	 0x8109c, 25, 1, 0x02000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_DST_ENDIANISM	 0x8109c, 24, 1, 0x01000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_SUB_UNIT_SEL	 0x8109c, 20, 4, 0x00f00000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_GAP	 0x8109c, 61, 4, 0xe0000000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_XSI_DMA_BURST_SZ	 0x8109c, 12, 5, 0x0001f000
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_DMA_BURST_SZ	 0x8109c, 8, 4, 0x00000f00
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_READ_EN	 0x8109c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_SRC_ADDR_MODE	 0x8109c, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_SRC_LINK_LIST	 0x8109c, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_WRITE_EN	 0x8109c, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_DST_ADDR_MODE	 0x8109c, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_DMA2_FLAGS_MODE_DST_LINK_LIST	 0x8109c, 0, 1, 0x00000001
#define ROFF_AUDIO_DMA2_SRCDMA_START_ALIAS	0x810a0 /*  This is the alias of Source DMA Start Register SRCDMA_START */ 
	#define BITFIELD_AUDIO_DMA2_SRCDMA_START_ALIAS	 0x810a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_SRCDMA_BOT	0x810a4 /*  Address of the bottom of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA2_SRCDMA_BOT	 0x810a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_SRCDMA_TOP	0x810a8 /*  Address of the top of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA2_SRCDMA_TOP	 0x810a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_DSTDMA_BOT	0x810ac /*  Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA2_DSTDMA_BOT	 0x810ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_DSTDMA_TOP	0x810b0 /*  Address of the top of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA2_DSTDMA_TOP	 0x810b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_DSTDMA_SIZE	0x810b4 /*  Size of the block of data (in bytes) to be sent to the destination location. */ 
	#define BITFIELD_AUDIO_DMA2_DSTDMA_SIZE	 0x810b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_SRCDMA_STOP	0x810b8 /*  Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA2_SRCDMA_STOP	 0x810b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA2_DSTDMA_STOP	0x810bc /*  Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA2_DSTDMA_STOP	 0x810bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_CURR_DESCR	0x810c8 /*  Current descriptor address pointer */ 
	#define BITFIELD_AUDIO_DMA3_CURR_DESCR	 0x810c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_NEXT_DESCR	0x810cc /*  Next descriptor address pointer. */ 
	#define BITFIELD_AUDIO_DMA3_NEXT_DESCR	 0x810cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_SRCDMA_START	0x810d0 /*  Start address of the Source DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA3_SRCDMA_START	 0x810d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_DSTDMA_START	0x810d4 /*  Start address of the Destination DMA buffer in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA3_DSTDMA_START	 0x810d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_SRCDMA_SIZE	0x810d8 /*  Total size of the block of data (in bytes) to be read from the source location. */ 
	#define BITFIELD_AUDIO_DMA3_SRCDMA_SIZE	 0x810d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_FLAGS_MODE	0x810dc /* Miscellaneous Control/Status: flags, modes, quality of service, addresses, etc. */ 
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE	 0x810dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_DMA3_FLAGS_MODE */
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_DMA_CONTEXT_ACTIVE	31
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_SRC_INT_EN	30
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_DST_INT_EN	29
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_LINK_LIST_TERM	28
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_SUB_UNIT_SEL	20
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_GAP	61
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_BURST_SZ	12
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_DMA_BURST_SZ	8
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_READ_EN	7
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_WRITE_EN	3
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_AUDIO_DMA3_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for AUDIO_DMA3_FLAGS_MODE */
	#define BWID_AUDIO_DMA3_FLAGS_MODE_DMA_CONTEXT_ACTIVE	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_SRC_INT_EN	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_DST_INT_EN	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_LINK_LIST_TERM	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_SUB_UNIT_SEL	4
	#define BWID_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_GAP	4
	#define BWID_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_BURST_SZ	5
	#define BWID_AUDIO_DMA3_FLAGS_MODE_DMA_BURST_SZ	4
	#define BWID_AUDIO_DMA3_FLAGS_MODE_READ_EN	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_AUDIO_DMA3_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_WRITE_EN	1
	#define BWID_AUDIO_DMA3_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_AUDIO_DMA3_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for AUDIO_DMA3_FLAGS_MODE */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_DMA_CONTEXT_ACTIVE	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_SRC_INT_EN	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_DST_INT_EN	(1<<29) /* == 0x20000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_LINK_LIST_TERM	(1<<28) /* == 0x10000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_SUB_UNIT_SEL	0x00f00000 /*  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_GAP	0xe0000000 /*  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_BURST_SZ	0x0001f000 /*  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_DMA_BURST_SZ	0x00000f00 /*  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /*  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /*  */
	#define BMSK_AUDIO_DMA3_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_DMA3_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_DMA_CONTEXT_ACTIVE	 0x810dc, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_SRC_INT_EN	 0x810dc, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_DST_INT_EN	 0x810dc, 29, 1, 0x20000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_LINK_LIST_TERM	 0x810dc, 28, 1, 0x10000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_RD_SWAP_ENDIAN	 0x810dc, 27, 1, 0x08000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_WR_SWAP_ENDIAN	 0x810dc, 26, 1, 0x04000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_SRC_ENDIANISM	 0x810dc, 25, 1, 0x02000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_DST_ENDIANISM	 0x810dc, 24, 1, 0x01000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_SUB_UNIT_SEL	 0x810dc, 20, 4, 0x00f00000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_GAP	 0x810dc, 61, 4, 0xe0000000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_XSI_DMA_BURST_SZ	 0x810dc, 12, 5, 0x0001f000
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_DMA_BURST_SZ	 0x810dc, 8, 4, 0x00000f00
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_READ_EN	 0x810dc, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_SRC_ADDR_MODE	 0x810dc, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_SRC_LINK_LIST	 0x810dc, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_WRITE_EN	 0x810dc, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_DST_ADDR_MODE	 0x810dc, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_DMA3_FLAGS_MODE_DST_LINK_LIST	 0x810dc, 0, 1, 0x00000001
#define ROFF_AUDIO_DMA3_SRCDMA_START_ALIAS	0x810e0 /*  This is the alias of Source DMA Start Register SRCDMA_START */ 
	#define BITFIELD_AUDIO_DMA3_SRCDMA_START_ALIAS	 0x810e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_SRCDMA_BOT	0x810e4 /*  Address of the bottom of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA3_SRCDMA_BOT	 0x810e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_SRCDMA_TOP	0x810e8 /*  Address of the top of the Source DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA3_SRCDMA_TOP	 0x810e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_DSTDMA_BOT	0x810ec /*  Address of the bottom of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA3_DSTDMA_BOT	 0x810ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_DSTDMA_TOP	0x810f0 /*  Address of the top of the Destination DMA buffer (used for circular buffer modes only). */ 
	#define BITFIELD_AUDIO_DMA3_DSTDMA_TOP	 0x810f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_DSTDMA_SIZE	0x810f4 /*  Size of the block of data (in bytes) to be sent to the destination location. */ 
	#define BITFIELD_AUDIO_DMA3_DSTDMA_SIZE	 0x810f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_SRCDMA_STOP	0x810f8 /*  Stop address of the Source DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA3_SRCDMA_STOP	 0x810f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_DMA3_DSTDMA_STOP	0x810fc /*  Stop address of the Destination DMA buffer (used for circular buffer modes only) in the BI address space. */ 
	#define BITFIELD_AUDIO_DMA3_DSTDMA_STOP	 0x810fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SACR0	0x82000 /* Global Control Register */ 
	#define BITFIELD_AUDIO_TX0SACR0	 0x82000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SACR0 */
	#define BLSB_AUDIO_TX0SACR0_SAMS	31
	#define BLSB_AUDIO_TX0SACR0_SPORT	30
	#define BLSB_AUDIO_TX0SACR0_RSVD_29_6	6
	#define BLSB_AUDIO_TX0SACR0_RX_STRF	5
	#define BLSB_AUDIO_TX0SACR0_SP_RW_FN_EN	4
	#define BLSB_AUDIO_TX0SACR0_RST_FIFO_REGS	3
	#define BLSB_AUDIO_TX0SACR0_BITCLK_OUT	2
	#define BLSB_AUDIO_TX0SACR0_BITCLK_INV	1
	#define BLSB_AUDIO_TX0SACR0_EN_TX	0
	/* Register Bit Widths for AUDIO_TX0SACR0 */
	#define BWID_AUDIO_TX0SACR0_SAMS	1
	#define BWID_AUDIO_TX0SACR0_SPORT	1
	#define BWID_AUDIO_TX0SACR0_RSVD_29_6	24
	#define BWID_AUDIO_TX0SACR0_RX_STRF	1
	#define BWID_AUDIO_TX0SACR0_SP_RW_FN_EN	1
	#define BWID_AUDIO_TX0SACR0_RST_FIFO_REGS	1
	#define BWID_AUDIO_TX0SACR0_BITCLK_OUT	1
	#define BWID_AUDIO_TX0SACR0_BITCLK_INV	1
	#define BWID_AUDIO_TX0SACR0_EN_TX	1
	/* Register Bit MASKS for AUDIO_TX0SACR0 */
	#define BMSK_AUDIO_TX0SACR0_SAMS	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_TX0SACR0_SPORT	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_TX0SACR0_RSVD_29_6	0x3fffffc0 /*  */
	#define BMSK_AUDIO_TX0SACR0_RX_STRF	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX0SACR0_SP_RW_FN_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX0SACR0_RST_FIFO_REGS	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX0SACR0_BITCLK_OUT	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX0SACR0_BITCLK_INV	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_TX0SACR0_EN_TX	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX0SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SACR0_SAMS	 0x82000, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_TX0SACR0_SPORT	 0x82000, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_TX0SACR0_RSVD_29_6	 0x82000, 6, 24, 0x3fffffc0
	#define BITFIELD_AUDIO_TX0SACR0_RX_STRF	 0x82000, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX0SACR0_SP_RW_FN_EN	 0x82000, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX0SACR0_RST_FIFO_REGS	 0x82000, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX0SACR0_BITCLK_OUT	 0x82000, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX0SACR0_BITCLK_INV	 0x82000, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_TX0SACR0_EN_TX	 0x82000, 0, 1, 0x00000001
#define ROFF_AUDIO_TX0SACR1	0x82004 /* Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUDIO_TX0SACR1	 0x82004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SACR1 */
	#define BLSB_AUDIO_TX0SACR1_SPDIF_VALIDITY	31
	#define BLSB_AUDIO_TX0SACR1_RSVD_30_20	20
	#define BLSB_AUDIO_TX0SACR1_DMA_CONTEXT	18
	#define BLSB_AUDIO_TX0SACR1_TS_FIFO_THLD	16
	#define BLSB_AUDIO_TX0SACR1_PIN2_DIS	14
	#define BLSB_AUDIO_TX0SACR1_PIN1_DIS	12
	#define BLSB_AUDIO_TX0SACR1_PIN0_DIS	10
	#define BLSB_AUDIO_TX0SACR1_DATA_FMT	8
	#define BLSB_AUDIO_TX0SACR1_DATA_SAMP_SZ	7
	#define BLSB_AUDIO_TX0SACR1_LOOPBACK	5
	#define BLSB_AUDIO_TX0SACR1_SLIP_DIS	4
	#define BLSB_AUDIO_TX0SACR1_REC_DIS	3
	#define BLSB_AUDIO_TX0SACR1_RSVD_2_1	1
	#define BLSB_AUDIO_TX0SACR1_ALT_MODE	0
	/* Register Bit Widths for AUDIO_TX0SACR1 */
	#define BWID_AUDIO_TX0SACR1_SPDIF_VALIDITY	1
	#define BWID_AUDIO_TX0SACR1_RSVD_30_20	11
	#define BWID_AUDIO_TX0SACR1_DMA_CONTEXT	2
	#define BWID_AUDIO_TX0SACR1_TS_FIFO_THLD	2
	#define BWID_AUDIO_TX0SACR1_PIN2_DIS	2
	#define BWID_AUDIO_TX0SACR1_PIN1_DIS	2
	#define BWID_AUDIO_TX0SACR1_PIN0_DIS	2
	#define BWID_AUDIO_TX0SACR1_DATA_FMT	2
	#define BWID_AUDIO_TX0SACR1_DATA_SAMP_SZ	1
	#define BWID_AUDIO_TX0SACR1_LOOPBACK	2
	#define BWID_AUDIO_TX0SACR1_SLIP_DIS	1
	#define BWID_AUDIO_TX0SACR1_REC_DIS	1
	#define BWID_AUDIO_TX0SACR1_RSVD_2_1	2
	#define BWID_AUDIO_TX0SACR1_ALT_MODE	1
	/* Register Bit MASKS for AUDIO_TX0SACR1 */
	#define BMSK_AUDIO_TX0SACR1_SPDIF_VALIDITY	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_TX0SACR1_RSVD_30_20	0x7ff00000 /*  */
	#define BMSK_AUDIO_TX0SACR1_DMA_CONTEXT	0x000c0000 /*  */
	#define BMSK_AUDIO_TX0SACR1_TS_FIFO_THLD	0x00030000 /*  */
	#define BMSK_AUDIO_TX0SACR1_PIN2_DIS	0x0000c000 /*  */
	#define BMSK_AUDIO_TX0SACR1_PIN1_DIS	0x00003000 /*  */
	#define BMSK_AUDIO_TX0SACR1_PIN0_DIS	0x00000c00 /*  */
	#define BMSK_AUDIO_TX0SACR1_DATA_FMT	0x00000300 /*  */
	#define BMSK_AUDIO_TX0SACR1_DATA_SAMP_SZ	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX0SACR1_LOOPBACK	0x00000060 /*  */
	#define BMSK_AUDIO_TX0SACR1_SLIP_DIS	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX0SACR1_REC_DIS	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX0SACR1_RSVD_2_1	0x00000006 /*  */
	#define BMSK_AUDIO_TX0SACR1_ALT_MODE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX0SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SACR1_SPDIF_VALIDITY	 0x82004, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_TX0SACR1_RSVD_30_20	 0x82004, 20, 11, 0x7ff00000
	#define BITFIELD_AUDIO_TX0SACR1_DMA_CONTEXT	 0x82004, 18, 2, 0x000c0000
	#define BITFIELD_AUDIO_TX0SACR1_TS_FIFO_THLD	 0x82004, 16, 2, 0x00030000
	#define BITFIELD_AUDIO_TX0SACR1_PIN2_DIS	 0x82004, 14, 2, 0x0000c000
	#define BITFIELD_AUDIO_TX0SACR1_PIN1_DIS	 0x82004, 12, 2, 0x00003000
	#define BITFIELD_AUDIO_TX0SACR1_PIN0_DIS	 0x82004, 10, 2, 0x00000c00
	#define BITFIELD_AUDIO_TX0SACR1_DATA_FMT	 0x82004, 8, 2, 0x00000300
	#define BITFIELD_AUDIO_TX0SACR1_DATA_SAMP_SZ	 0x82004, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX0SACR1_LOOPBACK	 0x82004, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_TX0SACR1_SLIP_DIS	 0x82004, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX0SACR1_REC_DIS	 0x82004, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX0SACR1_RSVD_2_1	 0x82004, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_TX0SACR1_ALT_MODE	 0x82004, 0, 1, 0x00000001
#define ROFF_AUDIO_TX0SASR0	0x82008 /* Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUDIO_TX0SASR0	 0x82008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SASR0 */
	#define BLSB_AUDIO_TX0SASR0_RSVD_31_11	11
	#define BLSB_AUDIO_TX0SASR0_TS_FIFO_LVL	8
	#define BLSB_AUDIO_TX0SASR0_I2S_SHUTDN	7
	#define BLSB_AUDIO_TX0SASR0_RX_FIFO_OVERRUN	6
	#define BLSB_AUDIO_TX0SASR0_TX_FIFO_UNDERRUN	5
	#define BLSB_AUDIO_TX0SASR0_RX_FIFO_SERVICE_REQ	4
	#define BLSB_AUDIO_TX0SASR0_TX_FIFO_SERVICE_REQ	3
	#define BLSB_AUDIO_TX0SASR0_BUSY	2
	#define BLSB_AUDIO_TX0SASR0_RX_FIFO_NEMPTY	1
	#define BLSB_AUDIO_TX0SASR0_TX_FIFO_NFULL	0
	/* Register Bit Widths for AUDIO_TX0SASR0 */
	#define BWID_AUDIO_TX0SASR0_RSVD_31_11	21
	#define BWID_AUDIO_TX0SASR0_TS_FIFO_LVL	3
	#define BWID_AUDIO_TX0SASR0_I2S_SHUTDN	1
	#define BWID_AUDIO_TX0SASR0_RX_FIFO_OVERRUN	1
	#define BWID_AUDIO_TX0SASR0_TX_FIFO_UNDERRUN	1
	#define BWID_AUDIO_TX0SASR0_RX_FIFO_SERVICE_REQ	1
	#define BWID_AUDIO_TX0SASR0_TX_FIFO_SERVICE_REQ	1
	#define BWID_AUDIO_TX0SASR0_BUSY	1
	#define BWID_AUDIO_TX0SASR0_RX_FIFO_NEMPTY	1
	#define BWID_AUDIO_TX0SASR0_TX_FIFO_NFULL	1
	/* Register Bit MASKS for AUDIO_TX0SASR0 */
	#define BMSK_AUDIO_TX0SASR0_RSVD_31_11	0xfffff800 /*  */
	#define BMSK_AUDIO_TX0SASR0_TS_FIFO_LVL	0x00000700 /*  */
	#define BMSK_AUDIO_TX0SASR0_I2S_SHUTDN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX0SASR0_RX_FIFO_OVERRUN	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_TX0SASR0_TX_FIFO_UNDERRUN	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX0SASR0_RX_FIFO_SERVICE_REQ	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX0SASR0_TX_FIFO_SERVICE_REQ	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX0SASR0_BUSY	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX0SASR0_RX_FIFO_NEMPTY	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_TX0SASR0_TX_FIFO_NFULL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX0SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SASR0_RSVD_31_11	 0x82008, 11, 21, 0xfffff800
	#define BITFIELD_AUDIO_TX0SASR0_TS_FIFO_LVL	 0x82008, 8, 3, 0x00000700
	#define BITFIELD_AUDIO_TX0SASR0_I2S_SHUTDN	 0x82008, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX0SASR0_RX_FIFO_OVERRUN	 0x82008, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_TX0SASR0_TX_FIFO_UNDERRUN	 0x82008, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX0SASR0_RX_FIFO_SERVICE_REQ	 0x82008, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX0SASR0_TX_FIFO_SERVICE_REQ	 0x82008, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX0SASR0_BUSY	 0x82008, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX0SASR0_RX_FIFO_NEMPTY	 0x82008, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_TX0SASR0_TX_FIFO_NFULL	 0x82008, 0, 1, 0x00000001
#define ROFF_AUDIO_TX0SAIMR	0x8200c /* Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUDIO_TX0SAIMR	 0x8200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SAIMR */
	#define BLSB_AUDIO_TX0SAIMR_RSVD_31_16	16
	#define BLSB_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	15
	#define BLSB_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	14
	#define BLSB_AUDIO_TX0SAIMR_HDMI_SYNC_ERR_INT_EN	13
	#define BLSB_AUDIO_TX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	12
	#define BLSB_AUDIO_TX0SAIMR_HDMI_SET_AVMUTE_INT_EN	11
	#define BLSB_AUDIO_TX0SAIMR_I2S_FRAME_INT_EN	10
	#define BLSB_AUDIO_TX0SAIMR_SPDIF_SYNC_ERR_INT_EN	9
	#define BLSB_AUDIO_TX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	8
	#define BLSB_AUDIO_TX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	7
	#define BLSB_AUDIO_TX0SAIMR_FIFO_OVERRUN_INT_EN	6
	#define BLSB_AUDIO_TX0SAIMR_RSVD_5_5	5
	#define BLSB_AUDIO_TX0SAIMR_FIFO_SER_REQ_EN	4
	#define BLSB_AUDIO_TX0SAIMR_SPDIF_VAL_BIT_INT_EN	3
	#define BLSB_AUDIO_TX0SAIMR_SPDIF_PAR_ERR_INT_EN	2
	#define BLSB_AUDIO_TX0SAIMR_RSVD_1_0	0
	/* Register Bit Widths for AUDIO_TX0SAIMR */
	#define BWID_AUDIO_TX0SAIMR_RSVD_31_16	16
	#define BWID_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_HDMI_SYNC_ERR_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_HDMI_SET_AVMUTE_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_I2S_FRAME_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_SPDIF_SYNC_ERR_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_RSVD_5_5	1
	#define BWID_AUDIO_TX0SAIMR_FIFO_SER_REQ_EN	1
	#define BWID_AUDIO_TX0SAIMR_SPDIF_VAL_BIT_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_SPDIF_PAR_ERR_INT_EN	1
	#define BWID_AUDIO_TX0SAIMR_RSVD_1_0	2
	/* Register Bit MASKS for AUDIO_TX0SAIMR */
	#define BMSK_AUDIO_TX0SAIMR_RSVD_31_16	0xffff0000 /*  */
	#define BMSK_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	(1<<15) /* == 0x00008000:  */
	#define BMSK_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	(1<<14) /* == 0x00004000:  */
	#define BMSK_AUDIO_TX0SAIMR_HDMI_SYNC_ERR_INT_EN	(1<<13) /* == 0x00002000:  */
	#define BMSK_AUDIO_TX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	(1<<12) /* == 0x00001000:  */
	#define BMSK_AUDIO_TX0SAIMR_HDMI_SET_AVMUTE_INT_EN	(1<<11) /* == 0x00000800:  */
	#define BMSK_AUDIO_TX0SAIMR_I2S_FRAME_INT_EN	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_TX0SAIMR_SPDIF_SYNC_ERR_INT_EN	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_TX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_AUDIO_TX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX0SAIMR_FIFO_OVERRUN_INT_EN	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_TX0SAIMR_RSVD_5_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX0SAIMR_FIFO_SER_REQ_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX0SAIMR_SPDIF_VAL_BIT_INT_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX0SAIMR_SPDIF_PAR_ERR_INT_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX0SAIMR_RSVD_1_0	0x00000003 /*  */
	/* Register BITFIELD for AUDIO_TX0SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SAIMR_RSVD_31_16	 0x8200c, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	 0x8200c, 15, 1, 0x00008000
	#define BITFIELD_AUDIO_TX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	 0x8200c, 14, 1, 0x00004000
	#define BITFIELD_AUDIO_TX0SAIMR_HDMI_SYNC_ERR_INT_EN	 0x8200c, 13, 1, 0x00002000
	#define BITFIELD_AUDIO_TX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	 0x8200c, 12, 1, 0x00001000
	#define BITFIELD_AUDIO_TX0SAIMR_HDMI_SET_AVMUTE_INT_EN	 0x8200c, 11, 1, 0x00000800
	#define BITFIELD_AUDIO_TX0SAIMR_I2S_FRAME_INT_EN	 0x8200c, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_TX0SAIMR_SPDIF_SYNC_ERR_INT_EN	 0x8200c, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_TX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	 0x8200c, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_TX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	 0x8200c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX0SAIMR_FIFO_OVERRUN_INT_EN	 0x8200c, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_TX0SAIMR_RSVD_5_5	 0x8200c, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX0SAIMR_FIFO_SER_REQ_EN	 0x8200c, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX0SAIMR_SPDIF_VAL_BIT_INT_EN	 0x8200c, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX0SAIMR_SPDIF_PAR_ERR_INT_EN	 0x8200c, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX0SAIMR_RSVD_1_0	 0x8200c, 0, 2, 0x00000003
#define ROFF_AUDIO_TX0SAISR	0x82010 /* Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUDIO_TX0SAISR	 0x82010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SAISR */
	#define BLSB_AUDIO_TX0SAISR_RSVD_31_12	12
	#define BLSB_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	11
	#define BLSB_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	10
	#define BLSB_AUDIO_TX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	9
	#define BLSB_AUDIO_TX0SAISR_CLEAR_FIFO_OVERRUN_INT	8
	#define BLSB_AUDIO_TX0SAISR_HDMI_SYNC_ERR_INT	7
	#define BLSB_AUDIO_TX0SAISR_HDMI_CLEAR_AVMUTE_INT	6
	#define BLSB_AUDIO_TX0SAISR_HDMI_SET_AVMUTE_INT	5
	#define BLSB_AUDIO_TX0SAISR_I2S_FRAME_INT	4
	#define BLSB_AUDIO_TX0SAISR_SPDIF_VAL_BIT_INT	3
	#define BLSB_AUDIO_TX0SAISR_SPDIF_PAR_ERR_INT	2
	#define BLSB_AUDIO_TX0SAISR_SPDIF_BLOCK_CMP_INT	1
	#define BLSB_AUDIO_TX0SAISR_SPDIF_SYNC_ERR_INT	0
	/* Register Bit Widths for AUDIO_TX0SAISR */
	#define BWID_AUDIO_TX0SAISR_RSVD_31_12	20
	#define BWID_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	1
	#define BWID_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	1
	#define BWID_AUDIO_TX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	1
	#define BWID_AUDIO_TX0SAISR_CLEAR_FIFO_OVERRUN_INT	1
	#define BWID_AUDIO_TX0SAISR_HDMI_SYNC_ERR_INT	1
	#define BWID_AUDIO_TX0SAISR_HDMI_CLEAR_AVMUTE_INT	1
	#define BWID_AUDIO_TX0SAISR_HDMI_SET_AVMUTE_INT	1
	#define BWID_AUDIO_TX0SAISR_I2S_FRAME_INT	1
	#define BWID_AUDIO_TX0SAISR_SPDIF_VAL_BIT_INT	1
	#define BWID_AUDIO_TX0SAISR_SPDIF_PAR_ERR_INT	1
	#define BWID_AUDIO_TX0SAISR_SPDIF_BLOCK_CMP_INT	1
	#define BWID_AUDIO_TX0SAISR_SPDIF_SYNC_ERR_INT	1
	/* Register Bit MASKS for AUDIO_TX0SAISR */
	#define BMSK_AUDIO_TX0SAISR_RSVD_31_12	0xfffff000 /*  */
	#define BMSK_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	(1<<11) /* == 0x00000800:  */
	#define BMSK_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_TX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_TX0SAISR_CLEAR_FIFO_OVERRUN_INT	(1<<8) /* == 0x00000100:  */
	#define BMSK_AUDIO_TX0SAISR_HDMI_SYNC_ERR_INT	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX0SAISR_HDMI_CLEAR_AVMUTE_INT	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_TX0SAISR_HDMI_SET_AVMUTE_INT	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX0SAISR_I2S_FRAME_INT	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX0SAISR_SPDIF_VAL_BIT_INT	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX0SAISR_SPDIF_PAR_ERR_INT	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX0SAISR_SPDIF_BLOCK_CMP_INT	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_TX0SAISR_SPDIF_SYNC_ERR_INT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX0SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SAISR_RSVD_31_12	 0x82010, 12, 20, 0xfffff000
	#define BITFIELD_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	 0x82010, 11, 1, 0x00000800
	#define BITFIELD_AUDIO_TX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	 0x82010, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_TX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	 0x82010, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_TX0SAISR_CLEAR_FIFO_OVERRUN_INT	 0x82010, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_TX0SAISR_HDMI_SYNC_ERR_INT	 0x82010, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX0SAISR_HDMI_CLEAR_AVMUTE_INT	 0x82010, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_TX0SAISR_HDMI_SET_AVMUTE_INT	 0x82010, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX0SAISR_I2S_FRAME_INT	 0x82010, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX0SAISR_SPDIF_VAL_BIT_INT	 0x82010, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX0SAISR_SPDIF_PAR_ERR_INT	 0x82010, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX0SAISR_SPDIF_BLOCK_CMP_INT	 0x82010, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_TX0SAISR_SPDIF_SYNC_ERR_INT	 0x82010, 0, 1, 0x00000001
#define ROFF_AUDIO_TX0SADIV	0x82014 /* Audio Clock Divider Register */ 
	#define BITFIELD_AUDIO_TX0SADIV	 0x82014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SADIV */
	#define BLSB_AUDIO_TX0SADIV_RSVD_31_7	7
	#define BLSB_AUDIO_TX0SADIV_AUDIO_CLK_DIV	0
	/* Register Bit Widths for AUDIO_TX0SADIV */
	#define BWID_AUDIO_TX0SADIV_RSVD_31_7	25
	#define BWID_AUDIO_TX0SADIV_AUDIO_CLK_DIV	7
	/* Register Bit MASKS for AUDIO_TX0SADIV */
	#define BMSK_AUDIO_TX0SADIV_RSVD_31_7	0xffffff80 /*  */
	#define BMSK_AUDIO_TX0SADIV_AUDIO_CLK_DIV	0x0000007f /*  */
	/* Register BITFIELD for AUDIO_TX0SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SADIV_RSVD_31_7	 0x82014, 7, 25, 0xffffff80
	#define BITFIELD_AUDIO_TX0SADIV_AUDIO_CLK_DIV	 0x82014, 0, 7, 0x0000007f
#define ROFF_AUDIO_TX0SATR	0x82018 /* Serial Audio Transmit Register */ 
	#define BITFIELD_AUDIO_TX0SATR	 0x82018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SARR	0x8201c /* Serial Audio Rx Register */ 
	#define BITFIELD_AUDIO_TX0SARR	 0x8201c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SAFTH	0x82020 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_TX0SAFTH	 0x82020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SAFTH */
	#define BLSB_AUDIO_TX0SAFTH_RX_THLD	16
	#define BLSB_AUDIO_TX0SAFTH_TX_THLD	0
	/* Register Bit Widths for AUDIO_TX0SAFTH */
	#define BWID_AUDIO_TX0SAFTH_RX_THLD	16
	#define BWID_AUDIO_TX0SAFTH_TX_THLD	16
	/* Register Bit MASKS for AUDIO_TX0SAFTH */
	#define BMSK_AUDIO_TX0SAFTH_RX_THLD	0xffff0000 /*  */
	#define BMSK_AUDIO_TX0SAFTH_TX_THLD	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_TX0SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SAFTH_RX_THLD	 0x82020, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX0SAFTH_TX_THLD	 0x82020, 0, 16, 0x0000ffff
#define ROFF_AUDIO_TX0SAFTHL	0x82024 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_TX0SAFTHL	 0x82024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SAFTHL */
	#define BLSB_AUDIO_TX0SAFTHL_RX_THLD	16
	#define BLSB_AUDIO_TX0SAFTHL_TX_THLD	0
	/* Register Bit Widths for AUDIO_TX0SAFTHL */
	#define BWID_AUDIO_TX0SAFTHL_RX_THLD	16
	#define BWID_AUDIO_TX0SAFTHL_TX_THLD	16
	/* Register Bit MASKS for AUDIO_TX0SAFTHL */
	#define BMSK_AUDIO_TX0SAFTHL_RX_THLD	0xffff0000 /*  */
	#define BMSK_AUDIO_TX0SAFTHL_TX_THLD	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_TX0SAFTHL - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SAFTHL_RX_THLD	 0x82024, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX0SAFTHL_TX_THLD	 0x82024, 0, 16, 0x0000ffff
#define ROFF_AUDIO_TX0SAFL	0x82028 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_TX0SAFL	 0x82028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SAFL */
	#define BLSB_AUDIO_TX0SAFL_RX_LEVEL	16
	#define BLSB_AUDIO_TX0SAFL_TX_LEVEL	0
	/* Register Bit Widths for AUDIO_TX0SAFL */
	#define BWID_AUDIO_TX0SAFL_RX_LEVEL	16
	#define BWID_AUDIO_TX0SAFL_TX_LEVEL	16
	/* Register Bit MASKS for AUDIO_TX0SAFL */
	#define BMSK_AUDIO_TX0SAFL_RX_LEVEL	0xffff0000 /*  */
	#define BMSK_AUDIO_TX0SAFL_TX_LEVEL	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_TX0SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SAFL_RX_LEVEL	 0x82028, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX0SAFL_TX_LEVEL	 0x82028, 0, 16, 0x0000ffff
#define ROFF_AUDIO_TX0SADESC	0x82030 /* Audio Capture Descriptor Register */ 
	#define BITFIELD_AUDIO_TX0SADESC	 0x82030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SABAP	0x82034 /* Audio Capture Buffer Address Pointer Register */ 
	#define BITFIELD_AUDIO_TX0SABAP	 0x82034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SATSL	0x82038 /* Audio Capture Timestamp LSB */ 
	#define BITFIELD_AUDIO_TX0SATSL	 0x82038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SATSM	0x8203c /* Audio Capture Timestamp MSB */ 
	#define BITFIELD_AUDIO_TX0SATSM	 0x8203c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SASUDX	0x82040 /* S/PDIF transmit user data bits registers */ 
	#define BITFIELD_AUDIO_TX0SASUDX	 0x82040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SASUDC	0x82070 /* S/PDIF transmit user data control Register */ 
	#define BITFIELD_AUDIO_TX0SASUDC	 0x82070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX0SASUDC */
	#define BLSB_AUDIO_TX0SASUDC_RSVD_31_1	1
	#define BLSB_AUDIO_TX0SASUDC_LD_UD_REGISTERS	0
	/* Register Bit Widths for AUDIO_TX0SASUDC */
	#define BWID_AUDIO_TX0SASUDC_RSVD_31_1	31
	#define BWID_AUDIO_TX0SASUDC_LD_UD_REGISTERS	1
	/* Register Bit MASKS for AUDIO_TX0SASUDC */
	#define BMSK_AUDIO_TX0SASUDC_RSVD_31_1	0xfffffffe /*  */
	#define BMSK_AUDIO_TX0SASUDC_LD_UD_REGISTERS	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX0SASUDC - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX0SASUDC_RSVD_31_1	 0x82070, 1, 31, 0xfffffffe
	#define BITFIELD_AUDIO_TX0SASUDC_LD_UD_REGISTERS	 0x82070, 0, 1, 0x00000001
#define ROFF_AUDIO_TX0SASCSC	0x8207c /* S/PDIF transmit Channel status ctrl Register */ 
	#define BITFIELD_AUDIO_TX0SASCSC	 0x8207c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX0SASCSX	0x82080 /* S/PDIF transmit channel status Registers */ 
	#define BITFIELD_AUDIO_TX0SASCSX	 0x82080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SACR0	0x82100 /* Global Control Register */ 
	#define BITFIELD_AUDIO_TX1SACR0	 0x82100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SACR0 */
	#define BLSB_AUDIO_TX1SACR0_SAMS	31
	#define BLSB_AUDIO_TX1SACR0_SPORT	30
	#define BLSB_AUDIO_TX1SACR0_RSVD_29_6	6
	#define BLSB_AUDIO_TX1SACR0_RX_STRF	5
	#define BLSB_AUDIO_TX1SACR0_SP_RW_FN_EN	4
	#define BLSB_AUDIO_TX1SACR0_RST_FIFO_REGS	3
	#define BLSB_AUDIO_TX1SACR0_BITCLK_OUT	2
	#define BLSB_AUDIO_TX1SACR0_BITCLK_INV	1
	#define BLSB_AUDIO_TX1SACR0_EN_TX	0
	/* Register Bit Widths for AUDIO_TX1SACR0 */
	#define BWID_AUDIO_TX1SACR0_SAMS	1
	#define BWID_AUDIO_TX1SACR0_SPORT	1
	#define BWID_AUDIO_TX1SACR0_RSVD_29_6	24
	#define BWID_AUDIO_TX1SACR0_RX_STRF	1
	#define BWID_AUDIO_TX1SACR0_SP_RW_FN_EN	1
	#define BWID_AUDIO_TX1SACR0_RST_FIFO_REGS	1
	#define BWID_AUDIO_TX1SACR0_BITCLK_OUT	1
	#define BWID_AUDIO_TX1SACR0_BITCLK_INV	1
	#define BWID_AUDIO_TX1SACR0_EN_TX	1
	/* Register Bit MASKS for AUDIO_TX1SACR0 */
	#define BMSK_AUDIO_TX1SACR0_SAMS	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_TX1SACR0_SPORT	(1<<30) /* == 0x40000000:  */
	#define BMSK_AUDIO_TX1SACR0_RSVD_29_6	0x3fffffc0 /*  */
	#define BMSK_AUDIO_TX1SACR0_RX_STRF	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX1SACR0_SP_RW_FN_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX1SACR0_RST_FIFO_REGS	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX1SACR0_BITCLK_OUT	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX1SACR0_BITCLK_INV	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_TX1SACR0_EN_TX	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX1SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SACR0_SAMS	 0x82100, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_TX1SACR0_SPORT	 0x82100, 30, 1, 0x40000000
	#define BITFIELD_AUDIO_TX1SACR0_RSVD_29_6	 0x82100, 6, 24, 0x3fffffc0
	#define BITFIELD_AUDIO_TX1SACR0_RX_STRF	 0x82100, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX1SACR0_SP_RW_FN_EN	 0x82100, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX1SACR0_RST_FIFO_REGS	 0x82100, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX1SACR0_BITCLK_OUT	 0x82100, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX1SACR0_BITCLK_INV	 0x82100, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_TX1SACR0_EN_TX	 0x82100, 0, 1, 0x00000001
#define ROFF_AUDIO_TX1SACR1	0x82104 /* Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUDIO_TX1SACR1	 0x82104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SACR1 */
	#define BLSB_AUDIO_TX1SACR1_SPDIF_VALIDITY	31
	#define BLSB_AUDIO_TX1SACR1_RSVD_30_20	20
	#define BLSB_AUDIO_TX1SACR1_DMA_CONTEXT	18
	#define BLSB_AUDIO_TX1SACR1_TS_FIFO_THLD	16
	#define BLSB_AUDIO_TX1SACR1_PIN2_DIS	14
	#define BLSB_AUDIO_TX1SACR1_PIN1_DIS	12
	#define BLSB_AUDIO_TX1SACR1_PIN0_DIS	10
	#define BLSB_AUDIO_TX1SACR1_DATA_FMT	8
	#define BLSB_AUDIO_TX1SACR1_DATA_SAMP_SZ	7
	#define BLSB_AUDIO_TX1SACR1_LOOPBACK	5
	#define BLSB_AUDIO_TX1SACR1_SLIP_DIS	4
	#define BLSB_AUDIO_TX1SACR1_REC_DIS	3
	#define BLSB_AUDIO_TX1SACR1_RSVD_2_1	1
	#define BLSB_AUDIO_TX1SACR1_ALT_MODE	0
	/* Register Bit Widths for AUDIO_TX1SACR1 */
	#define BWID_AUDIO_TX1SACR1_SPDIF_VALIDITY	1
	#define BWID_AUDIO_TX1SACR1_RSVD_30_20	11
	#define BWID_AUDIO_TX1SACR1_DMA_CONTEXT	2
	#define BWID_AUDIO_TX1SACR1_TS_FIFO_THLD	2
	#define BWID_AUDIO_TX1SACR1_PIN2_DIS	2
	#define BWID_AUDIO_TX1SACR1_PIN1_DIS	2
	#define BWID_AUDIO_TX1SACR1_PIN0_DIS	2
	#define BWID_AUDIO_TX1SACR1_DATA_FMT	2
	#define BWID_AUDIO_TX1SACR1_DATA_SAMP_SZ	1
	#define BWID_AUDIO_TX1SACR1_LOOPBACK	2
	#define BWID_AUDIO_TX1SACR1_SLIP_DIS	1
	#define BWID_AUDIO_TX1SACR1_REC_DIS	1
	#define BWID_AUDIO_TX1SACR1_RSVD_2_1	2
	#define BWID_AUDIO_TX1SACR1_ALT_MODE	1
	/* Register Bit MASKS for AUDIO_TX1SACR1 */
	#define BMSK_AUDIO_TX1SACR1_SPDIF_VALIDITY	(1<<31) /* == 0x80000000:  */
	#define BMSK_AUDIO_TX1SACR1_RSVD_30_20	0x7ff00000 /*  */
	#define BMSK_AUDIO_TX1SACR1_DMA_CONTEXT	0x000c0000 /*  */
	#define BMSK_AUDIO_TX1SACR1_TS_FIFO_THLD	0x00030000 /*  */
	#define BMSK_AUDIO_TX1SACR1_PIN2_DIS	0x0000c000 /*  */
	#define BMSK_AUDIO_TX1SACR1_PIN1_DIS	0x00003000 /*  */
	#define BMSK_AUDIO_TX1SACR1_PIN0_DIS	0x00000c00 /*  */
	#define BMSK_AUDIO_TX1SACR1_DATA_FMT	0x00000300 /*  */
	#define BMSK_AUDIO_TX1SACR1_DATA_SAMP_SZ	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX1SACR1_LOOPBACK	0x00000060 /*  */
	#define BMSK_AUDIO_TX1SACR1_SLIP_DIS	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX1SACR1_REC_DIS	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX1SACR1_RSVD_2_1	0x00000006 /*  */
	#define BMSK_AUDIO_TX1SACR1_ALT_MODE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX1SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SACR1_SPDIF_VALIDITY	 0x82104, 31, 1, 0x80000000
	#define BITFIELD_AUDIO_TX1SACR1_RSVD_30_20	 0x82104, 20, 11, 0x7ff00000
	#define BITFIELD_AUDIO_TX1SACR1_DMA_CONTEXT	 0x82104, 18, 2, 0x000c0000
	#define BITFIELD_AUDIO_TX1SACR1_TS_FIFO_THLD	 0x82104, 16, 2, 0x00030000
	#define BITFIELD_AUDIO_TX1SACR1_PIN2_DIS	 0x82104, 14, 2, 0x0000c000
	#define BITFIELD_AUDIO_TX1SACR1_PIN1_DIS	 0x82104, 12, 2, 0x00003000
	#define BITFIELD_AUDIO_TX1SACR1_PIN0_DIS	 0x82104, 10, 2, 0x00000c00
	#define BITFIELD_AUDIO_TX1SACR1_DATA_FMT	 0x82104, 8, 2, 0x00000300
	#define BITFIELD_AUDIO_TX1SACR1_DATA_SAMP_SZ	 0x82104, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX1SACR1_LOOPBACK	 0x82104, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_TX1SACR1_SLIP_DIS	 0x82104, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX1SACR1_REC_DIS	 0x82104, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX1SACR1_RSVD_2_1	 0x82104, 1, 2, 0x00000006
	#define BITFIELD_AUDIO_TX1SACR1_ALT_MODE	 0x82104, 0, 1, 0x00000001
#define ROFF_AUDIO_TX1SASR0	0x82108 /* Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUDIO_TX1SASR0	 0x82108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SASR0 */
	#define BLSB_AUDIO_TX1SASR0_RSVD_31_11	11
	#define BLSB_AUDIO_TX1SASR0_TS_FIFO_LVL	8
	#define BLSB_AUDIO_TX1SASR0_I2S_SHUTDN	7
	#define BLSB_AUDIO_TX1SASR0_RX_FIFO_OVERRUN	6
	#define BLSB_AUDIO_TX1SASR0_TX_FIFO_UNDERRUN	5
	#define BLSB_AUDIO_TX1SASR0_RX_FIFO_SERVICE_REQ	4
	#define BLSB_AUDIO_TX1SASR0_TX_FIFO_SERVICE_REQ	3
	#define BLSB_AUDIO_TX1SASR0_BUSY	2
	#define BLSB_AUDIO_TX1SASR0_RX_FIFO_NEMPTY	1
	#define BLSB_AUDIO_TX1SASR0_TX_FIFO_NFULL	0
	/* Register Bit Widths for AUDIO_TX1SASR0 */
	#define BWID_AUDIO_TX1SASR0_RSVD_31_11	21
	#define BWID_AUDIO_TX1SASR0_TS_FIFO_LVL	3
	#define BWID_AUDIO_TX1SASR0_I2S_SHUTDN	1
	#define BWID_AUDIO_TX1SASR0_RX_FIFO_OVERRUN	1
	#define BWID_AUDIO_TX1SASR0_TX_FIFO_UNDERRUN	1
	#define BWID_AUDIO_TX1SASR0_RX_FIFO_SERVICE_REQ	1
	#define BWID_AUDIO_TX1SASR0_TX_FIFO_SERVICE_REQ	1
	#define BWID_AUDIO_TX1SASR0_BUSY	1
	#define BWID_AUDIO_TX1SASR0_RX_FIFO_NEMPTY	1
	#define BWID_AUDIO_TX1SASR0_TX_FIFO_NFULL	1
	/* Register Bit MASKS for AUDIO_TX1SASR0 */
	#define BMSK_AUDIO_TX1SASR0_RSVD_31_11	0xfffff800 /*  */
	#define BMSK_AUDIO_TX1SASR0_TS_FIFO_LVL	0x00000700 /*  */
	#define BMSK_AUDIO_TX1SASR0_I2S_SHUTDN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX1SASR0_RX_FIFO_OVERRUN	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_TX1SASR0_TX_FIFO_UNDERRUN	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX1SASR0_RX_FIFO_SERVICE_REQ	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX1SASR0_TX_FIFO_SERVICE_REQ	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX1SASR0_BUSY	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX1SASR0_RX_FIFO_NEMPTY	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_TX1SASR0_TX_FIFO_NFULL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX1SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SASR0_RSVD_31_11	 0x82108, 11, 21, 0xfffff800
	#define BITFIELD_AUDIO_TX1SASR0_TS_FIFO_LVL	 0x82108, 8, 3, 0x00000700
	#define BITFIELD_AUDIO_TX1SASR0_I2S_SHUTDN	 0x82108, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX1SASR0_RX_FIFO_OVERRUN	 0x82108, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_TX1SASR0_TX_FIFO_UNDERRUN	 0x82108, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX1SASR0_RX_FIFO_SERVICE_REQ	 0x82108, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX1SASR0_TX_FIFO_SERVICE_REQ	 0x82108, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX1SASR0_BUSY	 0x82108, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX1SASR0_RX_FIFO_NEMPTY	 0x82108, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_TX1SASR0_TX_FIFO_NFULL	 0x82108, 0, 1, 0x00000001
#define ROFF_AUDIO_TX1SAIMR	0x8210c /* Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUDIO_TX1SAIMR	 0x8210c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SAIMR */
	#define BLSB_AUDIO_TX1SAIMR_RSVD_31_16	16
	#define BLSB_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	15
	#define BLSB_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	14
	#define BLSB_AUDIO_TX1SAIMR_HDMI_SYNC_ERR_INT_EN	13
	#define BLSB_AUDIO_TX1SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	12
	#define BLSB_AUDIO_TX1SAIMR_HDMI_SET_AVMUTE_INT_EN	11
	#define BLSB_AUDIO_TX1SAIMR_I2S_FRAME_INT_EN	10
	#define BLSB_AUDIO_TX1SAIMR_SPDIF_SYNC_ERR_INT_EN	9
	#define BLSB_AUDIO_TX1SAIMR_SPDIF_BLOCK_CMP_INT_EN	8
	#define BLSB_AUDIO_TX1SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	7
	#define BLSB_AUDIO_TX1SAIMR_FIFO_OVERRUN_INT_EN	6
	#define BLSB_AUDIO_TX1SAIMR_RSVD_5_5	5
	#define BLSB_AUDIO_TX1SAIMR_FIFO_SER_REQ_EN	4
	#define BLSB_AUDIO_TX1SAIMR_SPDIF_VAL_BIT_INT_EN	3
	#define BLSB_AUDIO_TX1SAIMR_SPDIF_PAR_ERR_INT_EN	2
	#define BLSB_AUDIO_TX1SAIMR_RSVD_1_0	0
	/* Register Bit Widths for AUDIO_TX1SAIMR */
	#define BWID_AUDIO_TX1SAIMR_RSVD_31_16	16
	#define BWID_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_HDMI_SYNC_ERR_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_HDMI_SET_AVMUTE_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_I2S_FRAME_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_SPDIF_SYNC_ERR_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_SPDIF_BLOCK_CMP_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_RSVD_5_5	1
	#define BWID_AUDIO_TX1SAIMR_FIFO_SER_REQ_EN	1
	#define BWID_AUDIO_TX1SAIMR_SPDIF_VAL_BIT_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_SPDIF_PAR_ERR_INT_EN	1
	#define BWID_AUDIO_TX1SAIMR_RSVD_1_0	2
	/* Register Bit MASKS for AUDIO_TX1SAIMR */
	#define BMSK_AUDIO_TX1SAIMR_RSVD_31_16	0xffff0000 /*  */
	#define BMSK_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	(1<<15) /* == 0x00008000:  */
	#define BMSK_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	(1<<14) /* == 0x00004000:  */
	#define BMSK_AUDIO_TX1SAIMR_HDMI_SYNC_ERR_INT_EN	(1<<13) /* == 0x00002000:  */
	#define BMSK_AUDIO_TX1SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	(1<<12) /* == 0x00001000:  */
	#define BMSK_AUDIO_TX1SAIMR_HDMI_SET_AVMUTE_INT_EN	(1<<11) /* == 0x00000800:  */
	#define BMSK_AUDIO_TX1SAIMR_I2S_FRAME_INT_EN	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_TX1SAIMR_SPDIF_SYNC_ERR_INT_EN	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_TX1SAIMR_SPDIF_BLOCK_CMP_INT_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_AUDIO_TX1SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX1SAIMR_FIFO_OVERRUN_INT_EN	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_TX1SAIMR_RSVD_5_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX1SAIMR_FIFO_SER_REQ_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX1SAIMR_SPDIF_VAL_BIT_INT_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX1SAIMR_SPDIF_PAR_ERR_INT_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX1SAIMR_RSVD_1_0	0x00000003 /*  */
	/* Register BITFIELD for AUDIO_TX1SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SAIMR_RSVD_31_16	 0x8210c, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	 0x8210c, 15, 1, 0x00008000
	#define BITFIELD_AUDIO_TX1SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	 0x8210c, 14, 1, 0x00004000
	#define BITFIELD_AUDIO_TX1SAIMR_HDMI_SYNC_ERR_INT_EN	 0x8210c, 13, 1, 0x00002000
	#define BITFIELD_AUDIO_TX1SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	 0x8210c, 12, 1, 0x00001000
	#define BITFIELD_AUDIO_TX1SAIMR_HDMI_SET_AVMUTE_INT_EN	 0x8210c, 11, 1, 0x00000800
	#define BITFIELD_AUDIO_TX1SAIMR_I2S_FRAME_INT_EN	 0x8210c, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_TX1SAIMR_SPDIF_SYNC_ERR_INT_EN	 0x8210c, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_TX1SAIMR_SPDIF_BLOCK_CMP_INT_EN	 0x8210c, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_TX1SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	 0x8210c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX1SAIMR_FIFO_OVERRUN_INT_EN	 0x8210c, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_TX1SAIMR_RSVD_5_5	 0x8210c, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX1SAIMR_FIFO_SER_REQ_EN	 0x8210c, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX1SAIMR_SPDIF_VAL_BIT_INT_EN	 0x8210c, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX1SAIMR_SPDIF_PAR_ERR_INT_EN	 0x8210c, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX1SAIMR_RSVD_1_0	 0x8210c, 0, 2, 0x00000003
#define ROFF_AUDIO_TX1SAISR	0x82110 /* Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUDIO_TX1SAISR	 0x82110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SAISR */
	#define BLSB_AUDIO_TX1SAISR_RSVD_31_12	12
	#define BLSB_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	11
	#define BLSB_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	10
	#define BLSB_AUDIO_TX1SAISR_TIME_STAMP_FIFO_SER_REQ_INT	9
	#define BLSB_AUDIO_TX1SAISR_CLEAR_FIFO_OVERRUN_INT	8
	#define BLSB_AUDIO_TX1SAISR_HDMI_SYNC_ERR_INT	7
	#define BLSB_AUDIO_TX1SAISR_HDMI_CLEAR_AVMUTE_INT	6
	#define BLSB_AUDIO_TX1SAISR_HDMI_SET_AVMUTE_INT	5
	#define BLSB_AUDIO_TX1SAISR_I2S_FRAME_INT	4
	#define BLSB_AUDIO_TX1SAISR_SPDIF_VAL_BIT_INT	3
	#define BLSB_AUDIO_TX1SAISR_SPDIF_PAR_ERR_INT	2
	#define BLSB_AUDIO_TX1SAISR_SPDIF_BLOCK_CMP_INT	1
	#define BLSB_AUDIO_TX1SAISR_SPDIF_SYNC_ERR_INT	0
	/* Register Bit Widths for AUDIO_TX1SAISR */
	#define BWID_AUDIO_TX1SAISR_RSVD_31_12	20
	#define BWID_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	1
	#define BWID_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	1
	#define BWID_AUDIO_TX1SAISR_TIME_STAMP_FIFO_SER_REQ_INT	1
	#define BWID_AUDIO_TX1SAISR_CLEAR_FIFO_OVERRUN_INT	1
	#define BWID_AUDIO_TX1SAISR_HDMI_SYNC_ERR_INT	1
	#define BWID_AUDIO_TX1SAISR_HDMI_CLEAR_AVMUTE_INT	1
	#define BWID_AUDIO_TX1SAISR_HDMI_SET_AVMUTE_INT	1
	#define BWID_AUDIO_TX1SAISR_I2S_FRAME_INT	1
	#define BWID_AUDIO_TX1SAISR_SPDIF_VAL_BIT_INT	1
	#define BWID_AUDIO_TX1SAISR_SPDIF_PAR_ERR_INT	1
	#define BWID_AUDIO_TX1SAISR_SPDIF_BLOCK_CMP_INT	1
	#define BWID_AUDIO_TX1SAISR_SPDIF_SYNC_ERR_INT	1
	/* Register Bit MASKS for AUDIO_TX1SAISR */
	#define BMSK_AUDIO_TX1SAISR_RSVD_31_12	0xfffff000 /*  */
	#define BMSK_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	(1<<11) /* == 0x00000800:  */
	#define BMSK_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_TX1SAISR_TIME_STAMP_FIFO_SER_REQ_INT	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_TX1SAISR_CLEAR_FIFO_OVERRUN_INT	(1<<8) /* == 0x00000100:  */
	#define BMSK_AUDIO_TX1SAISR_HDMI_SYNC_ERR_INT	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_TX1SAISR_HDMI_CLEAR_AVMUTE_INT	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_TX1SAISR_HDMI_SET_AVMUTE_INT	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_TX1SAISR_I2S_FRAME_INT	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_TX1SAISR_SPDIF_VAL_BIT_INT	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_TX1SAISR_SPDIF_PAR_ERR_INT	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_TX1SAISR_SPDIF_BLOCK_CMP_INT	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_TX1SAISR_SPDIF_SYNC_ERR_INT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX1SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SAISR_RSVD_31_12	 0x82110, 12, 20, 0xfffff000
	#define BITFIELD_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	 0x82110, 11, 1, 0x00000800
	#define BITFIELD_AUDIO_TX1SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	 0x82110, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_TX1SAISR_TIME_STAMP_FIFO_SER_REQ_INT	 0x82110, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_TX1SAISR_CLEAR_FIFO_OVERRUN_INT	 0x82110, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_TX1SAISR_HDMI_SYNC_ERR_INT	 0x82110, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_TX1SAISR_HDMI_CLEAR_AVMUTE_INT	 0x82110, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_TX1SAISR_HDMI_SET_AVMUTE_INT	 0x82110, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_TX1SAISR_I2S_FRAME_INT	 0x82110, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_TX1SAISR_SPDIF_VAL_BIT_INT	 0x82110, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_TX1SAISR_SPDIF_PAR_ERR_INT	 0x82110, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_TX1SAISR_SPDIF_BLOCK_CMP_INT	 0x82110, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_TX1SAISR_SPDIF_SYNC_ERR_INT	 0x82110, 0, 1, 0x00000001
#define ROFF_AUDIO_TX1SADIV	0x82114 /* Audio Clock Divider Register */ 
	#define BITFIELD_AUDIO_TX1SADIV	 0x82114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SADIV */
	#define BLSB_AUDIO_TX1SADIV_RSVD_31_7	7
	#define BLSB_AUDIO_TX1SADIV_AUDIO_CLK_DIV	0
	/* Register Bit Widths for AUDIO_TX1SADIV */
	#define BWID_AUDIO_TX1SADIV_RSVD_31_7	25
	#define BWID_AUDIO_TX1SADIV_AUDIO_CLK_DIV	7
	/* Register Bit MASKS for AUDIO_TX1SADIV */
	#define BMSK_AUDIO_TX1SADIV_RSVD_31_7	0xffffff80 /*  */
	#define BMSK_AUDIO_TX1SADIV_AUDIO_CLK_DIV	0x0000007f /*  */
	/* Register BITFIELD for AUDIO_TX1SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SADIV_RSVD_31_7	 0x82114, 7, 25, 0xffffff80
	#define BITFIELD_AUDIO_TX1SADIV_AUDIO_CLK_DIV	 0x82114, 0, 7, 0x0000007f
#define ROFF_AUDIO_TX1SATR	0x82118 /* Serial Audio Transmit Register */ 
	#define BITFIELD_AUDIO_TX1SATR	 0x82118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SARR	0x8211c /* Serial Audio Rx Register */ 
	#define BITFIELD_AUDIO_TX1SARR	 0x8211c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SAFTH	0x82120 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_TX1SAFTH	 0x82120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SAFTH */
	#define BLSB_AUDIO_TX1SAFTH_RX_THLD	16
	#define BLSB_AUDIO_TX1SAFTH_TX_THLD	0
	/* Register Bit Widths for AUDIO_TX1SAFTH */
	#define BWID_AUDIO_TX1SAFTH_RX_THLD	16
	#define BWID_AUDIO_TX1SAFTH_TX_THLD	16
	/* Register Bit MASKS for AUDIO_TX1SAFTH */
	#define BMSK_AUDIO_TX1SAFTH_RX_THLD	0xffff0000 /*  */
	#define BMSK_AUDIO_TX1SAFTH_TX_THLD	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_TX1SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SAFTH_RX_THLD	 0x82120, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX1SAFTH_TX_THLD	 0x82120, 0, 16, 0x0000ffff
#define ROFF_AUDIO_TX1SAFTHL	0x82124 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_TX1SAFTHL	 0x82124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SAFTHL */
	#define BLSB_AUDIO_TX1SAFTHL_RX_THLD	16
	#define BLSB_AUDIO_TX1SAFTHL_TX_THLD	0
	/* Register Bit Widths for AUDIO_TX1SAFTHL */
	#define BWID_AUDIO_TX1SAFTHL_RX_THLD	16
	#define BWID_AUDIO_TX1SAFTHL_TX_THLD	16
	/* Register Bit MASKS for AUDIO_TX1SAFTHL */
	#define BMSK_AUDIO_TX1SAFTHL_RX_THLD	0xffff0000 /*  */
	#define BMSK_AUDIO_TX1SAFTHL_TX_THLD	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_TX1SAFTHL - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SAFTHL_RX_THLD	 0x82124, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX1SAFTHL_TX_THLD	 0x82124, 0, 16, 0x0000ffff
#define ROFF_AUDIO_TX1SAFL	0x82128 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_TX1SAFL	 0x82128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SAFL */
	#define BLSB_AUDIO_TX1SAFL_RX_LEVEL	16
	#define BLSB_AUDIO_TX1SAFL_TX_LEVEL	0
	/* Register Bit Widths for AUDIO_TX1SAFL */
	#define BWID_AUDIO_TX1SAFL_RX_LEVEL	16
	#define BWID_AUDIO_TX1SAFL_TX_LEVEL	16
	/* Register Bit MASKS for AUDIO_TX1SAFL */
	#define BMSK_AUDIO_TX1SAFL_RX_LEVEL	0xffff0000 /*  */
	#define BMSK_AUDIO_TX1SAFL_TX_LEVEL	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_TX1SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SAFL_RX_LEVEL	 0x82128, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_TX1SAFL_TX_LEVEL	 0x82128, 0, 16, 0x0000ffff
#define ROFF_AUDIO_TX1SADESC	0x82130 /* Audio Capture Descriptor Register */ 
	#define BITFIELD_AUDIO_TX1SADESC	 0x82130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SABAP	0x82134 /* Audio Capture Buffer Address Pointer Register */ 
	#define BITFIELD_AUDIO_TX1SABAP	 0x82134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SATSL	0x82138 /* Audio Capture Timestamp LSB */ 
	#define BITFIELD_AUDIO_TX1SATSL	 0x82138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SATSM	0x8213c /* Audio Capture Timestamp MSB */ 
	#define BITFIELD_AUDIO_TX1SATSM	 0x8213c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SASUDX	0x82140 /* S/PDIF transmit user data bits registers */ 
	#define BITFIELD_AUDIO_TX1SASUDX	 0x82140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SASUDC	0x82170 /* S/PDIF transmit user data control Register */ 
	#define BITFIELD_AUDIO_TX1SASUDC	 0x82170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_TX1SASUDC */
	#define BLSB_AUDIO_TX1SASUDC_RSVD_31_1	1
	#define BLSB_AUDIO_TX1SASUDC_LD_UD_REGISTERS	0
	/* Register Bit Widths for AUDIO_TX1SASUDC */
	#define BWID_AUDIO_TX1SASUDC_RSVD_31_1	31
	#define BWID_AUDIO_TX1SASUDC_LD_UD_REGISTERS	1
	/* Register Bit MASKS for AUDIO_TX1SASUDC */
	#define BMSK_AUDIO_TX1SASUDC_RSVD_31_1	0xfffffffe /*  */
	#define BMSK_AUDIO_TX1SASUDC_LD_UD_REGISTERS	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_TX1SASUDC - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_TX1SASUDC_RSVD_31_1	 0x82170, 1, 31, 0xfffffffe
	#define BITFIELD_AUDIO_TX1SASUDC_LD_UD_REGISTERS	 0x82170, 0, 1, 0x00000001
#define ROFF_AUDIO_TX1SASCSC	0x8217c /* S/PDIF transmit Channel status ctrl Register */ 
	#define BITFIELD_AUDIO_TX1SASCSC	 0x8217c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_TX1SASCSX	0x82180 /* S/PDIF transmit channel status Registers */ 
	#define BITFIELD_AUDIO_TX1SASCSX	 0x82180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SACR0	0x83000 /* Global Control Register */ 
	#define BITFIELD_AUDIO_RX0SACR0	 0x83000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SACR0 */
	#define BLSB_AUDIO_RX0SACR0_RSVD_31_7	7
	#define BLSB_AUDIO_RX0SACR0_SEL_INPUTS	5
	#define BLSB_AUDIO_RX0SACR0_SP_RW_FN_EN	4
	#define BLSB_AUDIO_RX0SACR0_RST_FIFO_REGS	3
	#define BLSB_AUDIO_RX0SACR0_BITCLK_DIR	2
	#define BLSB_AUDIO_RX0SACR0_RSVD_1_1	1
	#define BLSB_AUDIO_RX0SACR0_EN_RX	0
	/* Register Bit Widths for AUDIO_RX0SACR0 */
	#define BWID_AUDIO_RX0SACR0_RSVD_31_7	25
	#define BWID_AUDIO_RX0SACR0_SEL_INPUTS	2
	#define BWID_AUDIO_RX0SACR0_SP_RW_FN_EN	1
	#define BWID_AUDIO_RX0SACR0_RST_FIFO_REGS	1
	#define BWID_AUDIO_RX0SACR0_BITCLK_DIR	1
	#define BWID_AUDIO_RX0SACR0_RSVD_1_1	1
	#define BWID_AUDIO_RX0SACR0_EN_RX	1
	/* Register Bit MASKS for AUDIO_RX0SACR0 */
	#define BMSK_AUDIO_RX0SACR0_RSVD_31_7	0xffffff80 /*  */
	#define BMSK_AUDIO_RX0SACR0_SEL_INPUTS	0x00000060 /*  */
	#define BMSK_AUDIO_RX0SACR0_SP_RW_FN_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_RX0SACR0_RST_FIFO_REGS	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_RX0SACR0_BITCLK_DIR	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_RX0SACR0_RSVD_1_1	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_RX0SACR0_EN_RX	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_RX0SACR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SACR0_RSVD_31_7	 0x83000, 7, 25, 0xffffff80
	#define BITFIELD_AUDIO_RX0SACR0_SEL_INPUTS	 0x83000, 5, 2, 0x00000060
	#define BITFIELD_AUDIO_RX0SACR0_SP_RW_FN_EN	 0x83000, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_RX0SACR0_RST_FIFO_REGS	 0x83000, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_RX0SACR0_BITCLK_DIR	 0x83000, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_RX0SACR0_RSVD_1_1	 0x83000, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_RX0SACR0_EN_RX	 0x83000, 0, 1, 0x00000001
#define ROFF_AUDIO_RX0SACR1	0x83004 /* Serial Audio I2S/MSB-Justified Control Register */ 
	#define BITFIELD_AUDIO_RX0SACR1	 0x83004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SACR1 */
	#define BLSB_AUDIO_RX0SACR1_RSVD_31_21	21
	#define BLSB_AUDIO_RX0SACR1_TS_FILTER_EN	20
	#define BLSB_AUDIO_RX0SACR1_DMA_CONTEXT	17
	#define BLSB_AUDIO_RX0SACR1_TS_FIFO_THLD	15
	#define BLSB_AUDIO_RX0SACR1_RSVD_14_10	10
	#define BLSB_AUDIO_RX0SACR1_DATA_STORE_MODE	8
	#define BLSB_AUDIO_RX0SACR1_DATA_SAMP_SZ	7
	#define BLSB_AUDIO_RX0SACR1_RSVD_6_0	0
	/* Register Bit Widths for AUDIO_RX0SACR1 */
	#define BWID_AUDIO_RX0SACR1_RSVD_31_21	11
	#define BWID_AUDIO_RX0SACR1_TS_FILTER_EN	1
	#define BWID_AUDIO_RX0SACR1_DMA_CONTEXT	3
	#define BWID_AUDIO_RX0SACR1_TS_FIFO_THLD	2
	#define BWID_AUDIO_RX0SACR1_RSVD_14_10	5
	#define BWID_AUDIO_RX0SACR1_DATA_STORE_MODE	2
	#define BWID_AUDIO_RX0SACR1_DATA_SAMP_SZ	1
	#define BWID_AUDIO_RX0SACR1_RSVD_6_0	7
	/* Register Bit MASKS for AUDIO_RX0SACR1 */
	#define BMSK_AUDIO_RX0SACR1_RSVD_31_21	0xffe00000 /*  */
	#define BMSK_AUDIO_RX0SACR1_TS_FILTER_EN	(1<<20) /* == 0x00100000:  */
	#define BMSK_AUDIO_RX0SACR1_DMA_CONTEXT	0x000e0000 /*  */
	#define BMSK_AUDIO_RX0SACR1_TS_FIFO_THLD	0x00018000 /*  */
	#define BMSK_AUDIO_RX0SACR1_RSVD_14_10	0x00007c00 /*  */
	#define BMSK_AUDIO_RX0SACR1_DATA_STORE_MODE	0x00000300 /*  */
	#define BMSK_AUDIO_RX0SACR1_DATA_SAMP_SZ	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_RX0SACR1_RSVD_6_0	0x0000007f /*  */
	/* Register BITFIELD for AUDIO_RX0SACR1 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SACR1_RSVD_31_21	 0x83004, 21, 11, 0xffe00000
	#define BITFIELD_AUDIO_RX0SACR1_TS_FILTER_EN	 0x83004, 20, 1, 0x00100000
	#define BITFIELD_AUDIO_RX0SACR1_DMA_CONTEXT	 0x83004, 17, 3, 0x000e0000
	#define BITFIELD_AUDIO_RX0SACR1_TS_FIFO_THLD	 0x83004, 15, 2, 0x00018000
	#define BITFIELD_AUDIO_RX0SACR1_RSVD_14_10	 0x83004, 10, 5, 0x00007c00
	#define BITFIELD_AUDIO_RX0SACR1_DATA_STORE_MODE	 0x83004, 8, 2, 0x00000300
	#define BITFIELD_AUDIO_RX0SACR1_DATA_SAMP_SZ	 0x83004, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_RX0SACR1_RSVD_6_0	 0x83004, 0, 7, 0x0000007f
#define ROFF_AUDIO_RX0SASR0	0x83008 /* Serial Audio I2S/MSB-Justified Interface and FIFO Status Register */ 
	#define BITFIELD_AUDIO_RX0SASR0	 0x83008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SASR0 */
	#define BLSB_AUDIO_RX0SASR0_RSVD_31_11	11
	#define BLSB_AUDIO_RX0SASR0_TS_FIFO_LVL	8
	#define BLSB_AUDIO_RX0SASR0_I2S_SHUTDN	7
	#define BLSB_AUDIO_RX0SASR0_FIFO_OEVRRUN_INT	6
	#define BLSB_AUDIO_RX0SASR0_RSVD_5_5	5
	#define BLSB_AUDIO_RX0SASR0_FIFO_SERVICE_REQ	4
	#define BLSB_AUDIO_RX0SASR0_RSVD_3_3	3
	#define BLSB_AUDIO_RX0SASR0_BUSY	2
	#define BLSB_AUDIO_RX0SASR0_FIFO_EMPTY	1
	#define BLSB_AUDIO_RX0SASR0_RSVD_0_0	0
	/* Register Bit Widths for AUDIO_RX0SASR0 */
	#define BWID_AUDIO_RX0SASR0_RSVD_31_11	21
	#define BWID_AUDIO_RX0SASR0_TS_FIFO_LVL	3
	#define BWID_AUDIO_RX0SASR0_I2S_SHUTDN	1
	#define BWID_AUDIO_RX0SASR0_FIFO_OEVRRUN_INT	1
	#define BWID_AUDIO_RX0SASR0_RSVD_5_5	1
	#define BWID_AUDIO_RX0SASR0_FIFO_SERVICE_REQ	1
	#define BWID_AUDIO_RX0SASR0_RSVD_3_3	1
	#define BWID_AUDIO_RX0SASR0_BUSY	1
	#define BWID_AUDIO_RX0SASR0_FIFO_EMPTY	1
	#define BWID_AUDIO_RX0SASR0_RSVD_0_0	1
	/* Register Bit MASKS for AUDIO_RX0SASR0 */
	#define BMSK_AUDIO_RX0SASR0_RSVD_31_11	0xfffff800 /*  */
	#define BMSK_AUDIO_RX0SASR0_TS_FIFO_LVL	0x00000700 /*  */
	#define BMSK_AUDIO_RX0SASR0_I2S_SHUTDN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_RX0SASR0_FIFO_OEVRRUN_INT	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_RX0SASR0_RSVD_5_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_RX0SASR0_FIFO_SERVICE_REQ	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_RX0SASR0_RSVD_3_3	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_RX0SASR0_BUSY	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_RX0SASR0_FIFO_EMPTY	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_RX0SASR0_RSVD_0_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_RX0SASR0 - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SASR0_RSVD_31_11	 0x83008, 11, 21, 0xfffff800
	#define BITFIELD_AUDIO_RX0SASR0_TS_FIFO_LVL	 0x83008, 8, 3, 0x00000700
	#define BITFIELD_AUDIO_RX0SASR0_I2S_SHUTDN	 0x83008, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_RX0SASR0_FIFO_OEVRRUN_INT	 0x83008, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_RX0SASR0_RSVD_5_5	 0x83008, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_RX0SASR0_FIFO_SERVICE_REQ	 0x83008, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_RX0SASR0_RSVD_3_3	 0x83008, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_RX0SASR0_BUSY	 0x83008, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_RX0SASR0_FIFO_EMPTY	 0x83008, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_RX0SASR0_RSVD_0_0	 0x83008, 0, 1, 0x00000001
#define ROFF_AUDIO_RX0SAIMR	0x8300c /* Serial Audio Interrupt Mask Register */ 
	#define BITFIELD_AUDIO_RX0SAIMR	 0x8300c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SAIMR */
	#define BLSB_AUDIO_RX0SAIMR_RSVD_31_16	16
	#define BLSB_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	15
	#define BLSB_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	14
	#define BLSB_AUDIO_RX0SAIMR_HDMI_SYNC_ERR_INT_EN	13
	#define BLSB_AUDIO_RX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	12
	#define BLSB_AUDIO_RX0SAIMR_HDMI_SET_AVMUTE_INT_EN	11
	#define BLSB_AUDIO_RX0SAIMR_I2S_FRAME_INT_EN	10
	#define BLSB_AUDIO_RX0SAIMR_SPDIF_SYNC_ERR_INT_EN	9
	#define BLSB_AUDIO_RX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	8
	#define BLSB_AUDIO_RX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	7
	#define BLSB_AUDIO_RX0SAIMR_FIFO_OVERRUN_INT_EN	6
	#define BLSB_AUDIO_RX0SAIMR_RSVD_5_5	5
	#define BLSB_AUDIO_RX0SAIMR_FIFO_SER_REQ_EN	4
	#define BLSB_AUDIO_RX0SAIMR_SPDIF_VAL_BIT_INT_EN	3
	#define BLSB_AUDIO_RX0SAIMR_SPDIF_PAR_ERR_INT_EN	2
	#define BLSB_AUDIO_RX0SAIMR_RSVD_1_0	0
	/* Register Bit Widths for AUDIO_RX0SAIMR */
	#define BWID_AUDIO_RX0SAIMR_RSVD_31_16	16
	#define BWID_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_HDMI_SYNC_ERR_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_HDMI_SET_AVMUTE_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_I2S_FRAME_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_SPDIF_SYNC_ERR_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_FIFO_OVERRUN_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_RSVD_5_5	1
	#define BWID_AUDIO_RX0SAIMR_FIFO_SER_REQ_EN	1
	#define BWID_AUDIO_RX0SAIMR_SPDIF_VAL_BIT_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_SPDIF_PAR_ERR_INT_EN	1
	#define BWID_AUDIO_RX0SAIMR_RSVD_1_0	2
	/* Register Bit MASKS for AUDIO_RX0SAIMR */
	#define BMSK_AUDIO_RX0SAIMR_RSVD_31_16	0xffff0000 /*  */
	#define BMSK_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	(1<<15) /* == 0x00008000:  */
	#define BMSK_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	(1<<14) /* == 0x00004000:  */
	#define BMSK_AUDIO_RX0SAIMR_HDMI_SYNC_ERR_INT_EN	(1<<13) /* == 0x00002000:  */
	#define BMSK_AUDIO_RX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	(1<<12) /* == 0x00001000:  */
	#define BMSK_AUDIO_RX0SAIMR_HDMI_SET_AVMUTE_INT_EN	(1<<11) /* == 0x00000800:  */
	#define BMSK_AUDIO_RX0SAIMR_I2S_FRAME_INT_EN	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_RX0SAIMR_SPDIF_SYNC_ERR_INT_EN	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_RX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_AUDIO_RX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_RX0SAIMR_FIFO_OVERRUN_INT_EN	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_RX0SAIMR_RSVD_5_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_RX0SAIMR_FIFO_SER_REQ_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_RX0SAIMR_SPDIF_VAL_BIT_INT_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_RX0SAIMR_SPDIF_PAR_ERR_INT_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_RX0SAIMR_RSVD_1_0	0x00000003 /*  */
	/* Register BITFIELD for AUDIO_RX0SAIMR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SAIMR_RSVD_31_16	 0x8300c, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_OVERRUN_INT_EN	 0x8300c, 15, 1, 0x00008000
	#define BITFIELD_AUDIO_RX0SAIMR_HDMI_CNTRL_FIFO_SERVICE_INT_EN	 0x8300c, 14, 1, 0x00004000
	#define BITFIELD_AUDIO_RX0SAIMR_HDMI_SYNC_ERR_INT_EN	 0x8300c, 13, 1, 0x00002000
	#define BITFIELD_AUDIO_RX0SAIMR_HDMI_CLEAR_AVMUTE_INT_EN	 0x8300c, 12, 1, 0x00001000
	#define BITFIELD_AUDIO_RX0SAIMR_HDMI_SET_AVMUTE_INT_EN	 0x8300c, 11, 1, 0x00000800
	#define BITFIELD_AUDIO_RX0SAIMR_I2S_FRAME_INT_EN	 0x8300c, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_RX0SAIMR_SPDIF_SYNC_ERR_INT_EN	 0x8300c, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_RX0SAIMR_SPDIF_BLOCK_CMP_INT_EN	 0x8300c, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_RX0SAIMR_TIME_STAMP_FIFO_SER_REQ_INT_EN	 0x8300c, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_RX0SAIMR_FIFO_OVERRUN_INT_EN	 0x8300c, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_RX0SAIMR_RSVD_5_5	 0x8300c, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_RX0SAIMR_FIFO_SER_REQ_EN	 0x8300c, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_RX0SAIMR_SPDIF_VAL_BIT_INT_EN	 0x8300c, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_RX0SAIMR_SPDIF_PAR_ERR_INT_EN	 0x8300c, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_RX0SAIMR_RSVD_1_0	 0x8300c, 0, 2, 0x00000003
#define ROFF_AUDIO_RX0SAISR	0x83010 /* Serial Audio Interrupt Status Register */ 
	#define BITFIELD_AUDIO_RX0SAISR	 0x83010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SAISR */
	#define BLSB_AUDIO_RX0SAISR_RSVD_31_12	12
	#define BLSB_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	11
	#define BLSB_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	10
	#define BLSB_AUDIO_RX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	9
	#define BLSB_AUDIO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	8
	#define BLSB_AUDIO_RX0SAISR_HDMI_SYNC_ERR_INT	7
	#define BLSB_AUDIO_RX0SAISR_HDMI_CLEAR_AVMUTE_INT	6
	#define BLSB_AUDIO_RX0SAISR_HDMI_SET_AVMUTE_INT	5
	#define BLSB_AUDIO_RX0SAISR_I2S_FRAME_INT	4
	#define BLSB_AUDIO_RX0SAISR_SPDIF_VAL_BIT_INT	3
	#define BLSB_AUDIO_RX0SAISR_SPDIF_PAR_ERR_INT	2
	#define BLSB_AUDIO_RX0SAISR_SPDIF_BLOCK_CMP_INT	1
	#define BLSB_AUDIO_RX0SAISR_SPDIF_SYNC_ERR_INT	0
	/* Register Bit Widths for AUDIO_RX0SAISR */
	#define BWID_AUDIO_RX0SAISR_RSVD_31_12	20
	#define BWID_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	1
	#define BWID_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	1
	#define BWID_AUDIO_RX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	1
	#define BWID_AUDIO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	1
	#define BWID_AUDIO_RX0SAISR_HDMI_SYNC_ERR_INT	1
	#define BWID_AUDIO_RX0SAISR_HDMI_CLEAR_AVMUTE_INT	1
	#define BWID_AUDIO_RX0SAISR_HDMI_SET_AVMUTE_INT	1
	#define BWID_AUDIO_RX0SAISR_I2S_FRAME_INT	1
	#define BWID_AUDIO_RX0SAISR_SPDIF_VAL_BIT_INT	1
	#define BWID_AUDIO_RX0SAISR_SPDIF_PAR_ERR_INT	1
	#define BWID_AUDIO_RX0SAISR_SPDIF_BLOCK_CMP_INT	1
	#define BWID_AUDIO_RX0SAISR_SPDIF_SYNC_ERR_INT	1
	/* Register Bit MASKS for AUDIO_RX0SAISR */
	#define BMSK_AUDIO_RX0SAISR_RSVD_31_12	0xfffff000 /*  */
	#define BMSK_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	(1<<11) /* == 0x00000800:  */
	#define BMSK_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	(1<<10) /* == 0x00000400:  */
	#define BMSK_AUDIO_RX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	(1<<9) /* == 0x00000200:  */
	#define BMSK_AUDIO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	(1<<8) /* == 0x00000100:  */
	#define BMSK_AUDIO_RX0SAISR_HDMI_SYNC_ERR_INT	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_RX0SAISR_HDMI_CLEAR_AVMUTE_INT	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_RX0SAISR_HDMI_SET_AVMUTE_INT	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_RX0SAISR_I2S_FRAME_INT	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_RX0SAISR_SPDIF_VAL_BIT_INT	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_RX0SAISR_SPDIF_PAR_ERR_INT	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_RX0SAISR_SPDIF_BLOCK_CMP_INT	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_RX0SAISR_SPDIF_SYNC_ERR_INT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_RX0SAISR - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SAISR_RSVD_31_12	 0x83010, 12, 20, 0xfffff000
	#define BITFIELD_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_OVERRUN_INT	 0x83010, 11, 1, 0x00000800
	#define BITFIELD_AUDIO_RX0SAISR_HDMI_CNTRL_FIFO_SERVICE_INT	 0x83010, 10, 1, 0x00000400
	#define BITFIELD_AUDIO_RX0SAISR_TIME_STAMP_FIFO_SER_REQ_INT	 0x83010, 9, 1, 0x00000200
	#define BITFIELD_AUDIO_RX0SAISR_CLEAR_FIFO_OVERRUN_INT	 0x83010, 8, 1, 0x00000100
	#define BITFIELD_AUDIO_RX0SAISR_HDMI_SYNC_ERR_INT	 0x83010, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_RX0SAISR_HDMI_CLEAR_AVMUTE_INT	 0x83010, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_RX0SAISR_HDMI_SET_AVMUTE_INT	 0x83010, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_RX0SAISR_I2S_FRAME_INT	 0x83010, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_RX0SAISR_SPDIF_VAL_BIT_INT	 0x83010, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_RX0SAISR_SPDIF_PAR_ERR_INT	 0x83010, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_RX0SAISR_SPDIF_BLOCK_CMP_INT	 0x83010, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_RX0SAISR_SPDIF_SYNC_ERR_INT	 0x83010, 0, 1, 0x00000001
#define ROFF_AUDIO_RX0SADIV	0x83014 /* Audio Clock Divider Register */ 
	#define BITFIELD_AUDIO_RX0SADIV	 0x83014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SADIV */
	#define BLSB_AUDIO_RX0SADIV_RSVD_31_7	7
	#define BLSB_AUDIO_RX0SADIV_AUDIO_CLK_DIV	0
	/* Register Bit Widths for AUDIO_RX0SADIV */
	#define BWID_AUDIO_RX0SADIV_RSVD_31_7	25
	#define BWID_AUDIO_RX0SADIV_AUDIO_CLK_DIV	7
	/* Register Bit MASKS for AUDIO_RX0SADIV */
	#define BMSK_AUDIO_RX0SADIV_RSVD_31_7	0xffffff80 /*  */
	#define BMSK_AUDIO_RX0SADIV_AUDIO_CLK_DIV	0x0000007f /*  */
	/* Register BITFIELD for AUDIO_RX0SADIV - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SADIV_RSVD_31_7	 0x83014, 7, 25, 0xffffff80
	#define BITFIELD_AUDIO_RX0SADIV_AUDIO_CLK_DIV	 0x83014, 0, 7, 0x0000007f
#define ROFF_AUDIO_RX0SARR	0x83018 /* Serial Audio Receive Register */ 
	#define BITFIELD_AUDIO_RX0SARR	 0x83018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SAFTH	0x8301c /* Serial Audio FIFO Threshold Register */ 
	#define BITFIELD_AUDIO_RX0SAFTH	 0x8301c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SAFTH */
	#define BLSB_AUDIO_RX0SAFTH_RSVD_31_16	16
	#define BLSB_AUDIO_RX0SAFTH_FIFO_THLD	0
	/* Register Bit Widths for AUDIO_RX0SAFTH */
	#define BWID_AUDIO_RX0SAFTH_RSVD_31_16	16
	#define BWID_AUDIO_RX0SAFTH_FIFO_THLD	16
	/* Register Bit MASKS for AUDIO_RX0SAFTH */
	#define BMSK_AUDIO_RX0SAFTH_RSVD_31_16	0xffff0000 /*  */
	#define BMSK_AUDIO_RX0SAFTH_FIFO_THLD	0x0000ffff /*  */
	/* Register BITFIELD for AUDIO_RX0SAFTH - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SAFTH_RSVD_31_16	 0x8301c, 16, 16, 0xffff0000
	#define BITFIELD_AUDIO_RX0SAFTH_FIFO_THLD	 0x8301c, 0, 16, 0x0000ffff
#define ROFF_AUDIO_RX0SAFL	0x83020 /* Serial Audio FIFO Level Register */ 
	#define BITFIELD_AUDIO_RX0SAFL	 0x83020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SAFL */
	#define BLSB_AUDIO_RX0SAFL_RSVD_31_8	8
	#define BLSB_AUDIO_RX0SAFL_RX_FIFO_LEVEL	0
	/* Register Bit Widths for AUDIO_RX0SAFL */
	#define BWID_AUDIO_RX0SAFL_RSVD_31_8	24
	#define BWID_AUDIO_RX0SAFL_RX_FIFO_LEVEL	8
	/* Register Bit MASKS for AUDIO_RX0SAFL */
	#define BMSK_AUDIO_RX0SAFL_RSVD_31_8	0xffffff00 /*  */
	#define BMSK_AUDIO_RX0SAFL_RX_FIFO_LEVEL	0x000000ff /*  */
	/* Register BITFIELD for AUDIO_RX0SAFL - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SAFL_RSVD_31_8	 0x83020, 8, 24, 0xffffff00
	#define BITFIELD_AUDIO_RX0SAFL_RX_FIFO_LEVEL	 0x83020, 0, 8, 0x000000ff
#define ROFF_AUDIO_RX0SADESC	0x83024 /* Audio capture Block size Register */ 
	#define BITFIELD_AUDIO_RX0SADESC	 0x83024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUDIO_RX0SADESC */
	#define BLSB_AUDIO_RX0SADESC_RSVD_31_11	11
	#define BLSB_AUDIO_RX0SADESC_TS_FIFO_LVL	8
	#define BLSB_AUDIO_RX0SADESC_I2S_SHUTDN	7
	#define BLSB_AUDIO_RX0SADESC_FIFO_OEVRRUN_INT	6
	#define BLSB_AUDIO_RX0SADESC_RSVD_5_5	5
	#define BLSB_AUDIO_RX0SADESC_FIFO_SERVICE_REQ	4
	#define BLSB_AUDIO_RX0SADESC_RSVD_3_3	3
	#define BLSB_AUDIO_RX0SADESC_BUSY	2
	#define BLSB_AUDIO_RX0SADESC_FIFO_EMPTY	1
	#define BLSB_AUDIO_RX0SADESC_RSVD_0_0	0
	/* Register Bit Widths for AUDIO_RX0SADESC */
	#define BWID_AUDIO_RX0SADESC_RSVD_31_11	21
	#define BWID_AUDIO_RX0SADESC_TS_FIFO_LVL	3
	#define BWID_AUDIO_RX0SADESC_I2S_SHUTDN	1
	#define BWID_AUDIO_RX0SADESC_FIFO_OEVRRUN_INT	1
	#define BWID_AUDIO_RX0SADESC_RSVD_5_5	1
	#define BWID_AUDIO_RX0SADESC_FIFO_SERVICE_REQ	1
	#define BWID_AUDIO_RX0SADESC_RSVD_3_3	1
	#define BWID_AUDIO_RX0SADESC_BUSY	1
	#define BWID_AUDIO_RX0SADESC_FIFO_EMPTY	1
	#define BWID_AUDIO_RX0SADESC_RSVD_0_0	1
	/* Register Bit MASKS for AUDIO_RX0SADESC */
	#define BMSK_AUDIO_RX0SADESC_RSVD_31_11	0xfffff800 /*  */
	#define BMSK_AUDIO_RX0SADESC_TS_FIFO_LVL	0x00000700 /*  */
	#define BMSK_AUDIO_RX0SADESC_I2S_SHUTDN	(1<<7) /* == 0x00000080:  */
	#define BMSK_AUDIO_RX0SADESC_FIFO_OEVRRUN_INT	(1<<6) /* == 0x00000040:  */
	#define BMSK_AUDIO_RX0SADESC_RSVD_5_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_AUDIO_RX0SADESC_FIFO_SERVICE_REQ	(1<<4) /* == 0x00000010:  */
	#define BMSK_AUDIO_RX0SADESC_RSVD_3_3	(1<<3) /* == 0x00000008:  */
	#define BMSK_AUDIO_RX0SADESC_BUSY	(1<<2) /* == 0x00000004:  */
	#define BMSK_AUDIO_RX0SADESC_FIFO_EMPTY	(1<<1) /* == 0x00000002:  */
	#define BMSK_AUDIO_RX0SADESC_RSVD_0_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AUDIO_RX0SADESC - roff, lsb, width, mask */
	#define BITFIELD_AUDIO_RX0SADESC_RSVD_31_11	 0x83024, 11, 21, 0xfffff800
	#define BITFIELD_AUDIO_RX0SADESC_TS_FIFO_LVL	 0x83024, 8, 3, 0x00000700
	#define BITFIELD_AUDIO_RX0SADESC_I2S_SHUTDN	 0x83024, 7, 1, 0x00000080
	#define BITFIELD_AUDIO_RX0SADESC_FIFO_OEVRRUN_INT	 0x83024, 6, 1, 0x00000040
	#define BITFIELD_AUDIO_RX0SADESC_RSVD_5_5	 0x83024, 5, 1, 0x00000020
	#define BITFIELD_AUDIO_RX0SADESC_FIFO_SERVICE_REQ	 0x83024, 4, 1, 0x00000010
	#define BITFIELD_AUDIO_RX0SADESC_RSVD_3_3	 0x83024, 3, 1, 0x00000008
	#define BITFIELD_AUDIO_RX0SADESC_BUSY	 0x83024, 2, 1, 0x00000004
	#define BITFIELD_AUDIO_RX0SADESC_FIFO_EMPTY	 0x83024, 1, 1, 0x00000002
	#define BITFIELD_AUDIO_RX0SADESC_RSVD_0_0	 0x83024, 0, 1, 0x00000001
#define ROFF_AUDIO_RX0SATS	0x83028 /* Audio Capture block timestamp */ 
	#define BITFIELD_AUDIO_RX0SATS	 0x83028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SABAP	0x8302c /* Audio Sample block buffer pointer */ 
	#define BITFIELD_AUDIO_RX0SABAP	 0x8302c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SACUDR	0x83030 /* Audio Capture User Data bit FIFO */ 
	#define BITFIELD_AUDIO_RX0SACUDR	 0x83030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SACSR	0x83034 /* Audio Capture Channel Status bit FIFO */ 
	#define BITFIELD_AUDIO_RX0SACSR	 0x83034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SAVR	0x83038 /* Audio Capture Validity bit FIFO */ 
	#define BITFIELD_AUDIO_RX0SAVR	 0x83038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AUDIO_RX0SPDBP	0x8303c /* Audio Capture SPDIF Block address Pointer FIFO */ 
	#define BITFIELD_AUDIO_RX0SPDBP	 0x8303c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module AUDIO SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_AUDIO_DEC_FRAME_PUSH	0x1
#define SVEN_MODULE_EVENT_AUDIO_ES_SCRUB_FRAME_PUSH	0x2
#define SVEN_MODULE_EVENT_AUDIO_RESAM_FRAME_PUSH	0x3
#define SVEN_MODULE_EVENT_AUDIO_SET_TIMEBASE	0x4
#define SVEN_MODULE_EVENT_AUDIO_I2S_ENABLED	0x5
#define SVEN_MODULE_EVENT_AUDIO_ATC_WRITE	0x6
#define SVEN_MODULE_EVENT_AUDIO_ALSA_WRITE	0x7


#endif /* AUDIO_REGOFFS_H */
