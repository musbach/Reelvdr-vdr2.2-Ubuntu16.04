#ifndef TVE_REGOFFS_H
#define TVE_REGOFFS_H 1
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


/* Module TVE CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_TVE_TVE0_TVCTRL	0x58000 /*  */ 
	#define BITFIELD_TVE_TVE0_TVCTRL	 0x58000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TVE_TVE0_TVCTRL */
	#define BLSB_TVE_TVE0_TVCTRL_ENC_ENABLE	31
	#define BLSB_TVE_TVE0_TVCTRL_ENC_PIPESEL	30
	#define BLSB_TVE_TVE0_TVCTRL_reserved_29_27	27
	#define BLSB_TVE_TVE0_TVCTRL_reserved_26_24	24
	#define BLSB_TVE_TVE0_TVCTRL_RGB	23
	#define BLSB_TVE_TVE0_TVCTRL_3CH_SYNC	22
	#define BLSB_TVE_TVE0_TVCTRL_TRILEVEL_SYNC	21
	#define BLSB_TVE_TVE0_TVCTRL_SLOW_SYNC	20
	#define BLSB_TVE_TVE0_TVCTRL_OVERSAMPLE	18
	#define BLSB_TVE_TVE0_TVCTRL_reserved_17	17
	#define BLSB_TVE_TVE0_TVCTRL_reserved_16	16
	#define BLSB_TVE_TVE0_TVCTRL_FIELD_SWAP	15
	#define BLSB_TVE_TVE0_TVCTRL_YC_SKEW	12
	#define BLSB_TVE_TVE0_TVCTRL_Intel_Reserved	11
	#define BLSB_TVE_TVE0_TVCTRL_TP_SIZE	9
	#define BLSB_TVE_TVE0_TVCTRL_TP_INTERLACED	8
	#define BLSB_TVE_TVE0_TVCTRL_reserved_7_4	4
	#define BLSB_TVE_TVE0_TVCTRL_ENC_TEST_MODE	0
	/* Register Bit Widths for TVE_TVE0_TVCTRL */
	#define BWID_TVE_TVE0_TVCTRL_ENC_ENABLE	1
	#define BWID_TVE_TVE0_TVCTRL_ENC_PIPESEL	1
	#define BWID_TVE_TVE0_TVCTRL_reserved_29_27	3
	#define BWID_TVE_TVE0_TVCTRL_reserved_26_24	3
	#define BWID_TVE_TVE0_TVCTRL_RGB	1
	#define BWID_TVE_TVE0_TVCTRL_3CH_SYNC	1
	#define BWID_TVE_TVE0_TVCTRL_TRILEVEL_SYNC	1
	#define BWID_TVE_TVE0_TVCTRL_SLOW_SYNC	1
	#define BWID_TVE_TVE0_TVCTRL_OVERSAMPLE	2
	#define BWID_TVE_TVE0_TVCTRL_reserved_17	1
	#define BWID_TVE_TVE0_TVCTRL_reserved_16	1
	#define BWID_TVE_TVE0_TVCTRL_FIELD_SWAP	1
	#define BWID_TVE_TVE0_TVCTRL_YC_SKEW	3
	#define BWID_TVE_TVE0_TVCTRL_Intel_Reserved	1
	#define BWID_TVE_TVE0_TVCTRL_TP_SIZE	2
	#define BWID_TVE_TVE0_TVCTRL_TP_INTERLACED	1
	#define BWID_TVE_TVE0_TVCTRL_reserved_7_4	4
	#define BWID_TVE_TVE0_TVCTRL_ENC_TEST_MODE	4
	/* Register Bit MASKS for TVE_TVE0_TVCTRL */
	#define BMSK_TVE_TVE0_TVCTRL_ENC_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TVE_TVE0_TVCTRL_ENC_PIPESEL	(1<<30) /* == 0x40000000: 0:PipeA(HDMI); 1:PipeB(Blender) */
	#define BMSK_TVE_TVE0_TVCTRL_reserved_29_27	0x38000000 /*  */
	#define BMSK_TVE_TVE0_TVCTRL_reserved_26_24	0x07000000 /*  */
	#define BMSK_TVE_TVE0_TVCTRL_RGB	(1<<23) /* == 0x00800000:  */
	#define BMSK_TVE_TVE0_TVCTRL_3CH_SYNC	(1<<22) /* == 0x00400000:  */
	#define BMSK_TVE_TVE0_TVCTRL_TRILEVEL_SYNC	(1<<21) /* == 0x00200000:  */
	#define BMSK_TVE_TVE0_TVCTRL_SLOW_SYNC	(1<<20) /* == 0x00100000:  */
	#define BMSK_TVE_TVE0_TVCTRL_OVERSAMPLE	0x000c0000 /* 0:4x(480/576p);1:2x(720p/1080i);2:None;3:8x */
	#define BMSK_TVE_TVE0_TVCTRL_reserved_17	(1<<17) /* == 0x00020000:  */
	#define BMSK_TVE_TVE0_TVCTRL_reserved_16	(1<<16) /* == 0x00010000:  */
	#define BMSK_TVE_TVE0_TVCTRL_FIELD_SWAP	(1<<15) /* == 0x00008000:  */
	#define BMSK_TVE_TVE0_TVCTRL_YC_SKEW	0x00007000 /*  */
	#define BMSK_TVE_TVE0_TVCTRL_Intel_Reserved	(1<<11) /* == 0x00000800: scratch (preserve this bit) */
	#define BMSK_TVE_TVE0_TVCTRL_TP_SIZE	0x00000600 /* 0:640x480;1:720;2:1080 */
	#define BMSK_TVE_TVE0_TVCTRL_TP_INTERLACED	(1<<8) /* == 0x00000100: Enable Test Pattern Interlaced */
	#define BMSK_TVE_TVE0_TVCTRL_reserved_7_4	0x000000f0 /*  */
	#define BMSK_TVE_TVE0_TVCTRL_ENC_TEST_MODE	0x0000000f /* 0:Norm;1:Combo;2:Vert75%Color;3:Horz75%Color;etc... */
	/* Register BITFIELD for TVE_TVE0_TVCTRL - roff, lsb, width, mask */
	#define BITFIELD_TVE_TVE0_TVCTRL_ENC_ENABLE	 0x58000, 31, 1, 0x80000000
	#define BITFIELD_TVE_TVE0_TVCTRL_ENC_PIPESEL	 0x58000, 30, 1, 0x40000000
	#define BITFIELD_TVE_TVE0_TVCTRL_reserved_29_27	 0x58000, 27, 3, 0x38000000
	#define BITFIELD_TVE_TVE0_TVCTRL_reserved_26_24	 0x58000, 24, 3, 0x07000000
	#define BITFIELD_TVE_TVE0_TVCTRL_RGB	 0x58000, 23, 1, 0x00800000
	#define BITFIELD_TVE_TVE0_TVCTRL_3CH_SYNC	 0x58000, 22, 1, 0x00400000
	#define BITFIELD_TVE_TVE0_TVCTRL_TRILEVEL_SYNC	 0x58000, 21, 1, 0x00200000
	#define BITFIELD_TVE_TVE0_TVCTRL_SLOW_SYNC	 0x58000, 20, 1, 0x00100000
	#define BITFIELD_TVE_TVE0_TVCTRL_OVERSAMPLE	 0x58000, 18, 2, 0x000c0000
	#define BITFIELD_TVE_TVE0_TVCTRL_reserved_17	 0x58000, 17, 1, 0x00020000
	#define BITFIELD_TVE_TVE0_TVCTRL_reserved_16	 0x58000, 16, 1, 0x00010000
	#define BITFIELD_TVE_TVE0_TVCTRL_FIELD_SWAP	 0x58000, 15, 1, 0x00008000
	#define BITFIELD_TVE_TVE0_TVCTRL_YC_SKEW	 0x58000, 12, 3, 0x00007000
	#define BITFIELD_TVE_TVE0_TVCTRL_Intel_Reserved	 0x58000, 11, 1, 0x00000800
	#define BITFIELD_TVE_TVE0_TVCTRL_TP_SIZE	 0x58000, 9, 2, 0x00000600
	#define BITFIELD_TVE_TVE0_TVCTRL_TP_INTERLACED	 0x58000, 8, 1, 0x00000100
	#define BITFIELD_TVE_TVE0_TVCTRL_reserved_7_4	 0x58000, 4, 4, 0x000000f0
	#define BITFIELD_TVE_TVE0_TVCTRL_ENC_TEST_MODE	 0x58000, 0, 4, 0x0000000f
#define ROFF_TVE_TVE0_TVDACCTRL	0x58004 /*  */ 
	#define BITFIELD_TVE_TVE0_TVDACCTRL	 0x58004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCSCY1	0x58010 /*  */ 
	#define BITFIELD_TVE_TVE0_TVCSCY1	 0x58010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCSCY2	0x58014 /*  */ 
	#define BITFIELD_TVE_TVE0_TVCSCY2	 0x58014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCSCU1	0x58018 /*  */ 
	#define BITFIELD_TVE_TVE0_TVCSCU1	 0x58018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCSCU2	0x5801c /*  */ 
	#define BITFIELD_TVE_TVE0_TVCSCU2	 0x5801c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCSCV1	0x58020 /*  */ 
	#define BITFIELD_TVE_TVE0_TVCSCV1	 0x58020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCSCV2	0x58024 /*  */ 
	#define BITFIELD_TVE_TVE0_TVCSCV2	 0x58024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVVBIYLEVEL	0x58008 /*  */ 
	#define BITFIELD_TVE_TVE0_TVVBIYLEVEL	 0x58008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVUVOFF	0x5800c /*  */ 
	#define BITFIELD_TVE_TVE0_TVUVOFF	 0x5800c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVBCSH	0x58028 /*  */ 
	#define BITFIELD_TVE_TVE0_TVBCSH	 0x58028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVBLEVEL	0x5802c /*  */ 
	#define BITFIELD_TVE_TVE0_TVBLEVEL	 0x5802c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHCTRL1	0x58030 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHCTRL1	 0x58030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHCTRL3	0x58038 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHCTRL3	 0x58038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVVCTRL1	0x5803c /*  */ 
	#define BITFIELD_TVE_TVE0_TVVCTRL1	 0x5803c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVVCTRL2	0x58040 /*  */ 
	#define BITFIELD_TVE_TVE0_TVVCTRL2	 0x58040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVVCTRL3	0x58044 /*  */ 
	#define BITFIELD_TVE_TVE0_TVVCTRL3	 0x58044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVWINPOS	0x58070 /*  */ 
	#define BITFIELD_TVE_TVE0_TVWINPOS	 0x58070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVWINSZ	0x58074 /*  */ 
	#define BITFIELD_TVE_TVE0_TVWINSZ	 0x58074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVFILTCTRL1	0x58080 /*  */ 
	#define BITFIELD_TVE_TVE0_TVFILTCTRL1	 0x58080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVCCCTRL	0x58090 /* TV Closed Caption Control */ 
	#define BITFIELD_TVE_TVE0_TVCCCTRL	 0x58090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TVE_TVE0_TVCCCTRL */
	#define BLSB_TVE_TVE0_TVCCCTRL_CC_ENA	31
	#define BLSB_TVE_TVE0_TVCCCTRL_reserved_30_28	28
	#define BLSB_TVE_TVE0_TVCCCTRL_CC_FID	27
	#define BLSB_TVE_TVE0_TVCCCTRL_reserved_26	26
	#define BLSB_TVE_TVE0_TVCCCTRL_CC_HOFF	16
	#define BLSB_TVE_TVE0_TVCCCTRL_reserved_15_6	6
	#define BLSB_TVE_TVE0_TVCCCTRL_CC_LINE	0
	/* Register Bit Widths for TVE_TVE0_TVCCCTRL */
	#define BWID_TVE_TVE0_TVCCCTRL_CC_ENA	1
	#define BWID_TVE_TVE0_TVCCCTRL_reserved_30_28	3
	#define BWID_TVE_TVE0_TVCCCTRL_CC_FID	1
	#define BWID_TVE_TVE0_TVCCCTRL_reserved_26	1
	#define BWID_TVE_TVE0_TVCCCTRL_CC_HOFF	10
	#define BWID_TVE_TVE0_TVCCCTRL_reserved_15_6	10
	#define BWID_TVE_TVE0_TVCCCTRL_CC_LINE	6
	/* Register Bit MASKS for TVE_TVE0_TVCCCTRL */
	#define BMSK_TVE_TVE0_TVCCCTRL_CC_ENA	(1<<31) /* == 0x80000000:  */
	#define BMSK_TVE_TVE0_TVCCCTRL_reserved_30_28	0x70000000 /*  */
	#define BMSK_TVE_TVE0_TVCCCTRL_CC_FID	(1<<27) /* == 0x08000000: 0 reserved */
	#define BMSK_TVE_TVE0_TVCCCTRL_reserved_26	(1<<26) /* == 0x04000000:  */
	#define BMSK_TVE_TVE0_TVCCCTRL_CC_HOFF	0x03ff0000 /* (usually 135) */
	#define BMSK_TVE_TVE0_TVCCCTRL_reserved_15_6	0x0000ffc0 /*  */
	#define BMSK_TVE_TVE0_TVCCCTRL_CC_LINE	0x0000003f /* (usually 21) */
	/* Register BITFIELD for TVE_TVE0_TVCCCTRL - roff, lsb, width, mask */
	#define BITFIELD_TVE_TVE0_TVCCCTRL_CC_ENA	 0x58090, 31, 1, 0x80000000
	#define BITFIELD_TVE_TVE0_TVCCCTRL_reserved_30_28	 0x58090, 28, 3, 0x70000000
	#define BITFIELD_TVE_TVE0_TVCCCTRL_CC_FID	 0x58090, 27, 1, 0x08000000
	#define BITFIELD_TVE_TVE0_TVCCCTRL_reserved_26	 0x58090, 26, 1, 0x04000000
	#define BITFIELD_TVE_TVE0_TVCCCTRL_CC_HOFF	 0x58090, 16, 10, 0x03ff0000
	#define BITFIELD_TVE_TVE0_TVCCCTRL_reserved_15_6	 0x58090, 6, 10, 0x0000ffc0
	#define BITFIELD_TVE_TVE0_TVCCCTRL_CC_LINE	 0x58090, 0, 6, 0x0000003f
#define ROFF_TVE_TVE0_TVCCDATA1	0x58094 /* TV CC Data Field 1 */ 
	#define BITFIELD_TVE_TVE0_TVCCDATA1	 0x58094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TVE_TVE0_TVCCDATA1 */
	#define BLSB_TVE_TVE0_TVCCDATA1_CC_RDY	31
	#define BLSB_TVE_TVE0_TVCCDATA1_reserved_30_15	15
	#define BLSB_TVE_TVE0_TVCCDATA1_CC_D2	8
	#define BLSB_TVE_TVE0_TVCCDATA1_reserved_7	7
	#define BLSB_TVE_TVE0_TVCCDATA1_CC_D1	0
	/* Register Bit Widths for TVE_TVE0_TVCCDATA1 */
	#define BWID_TVE_TVE0_TVCCDATA1_CC_RDY	1
	#define BWID_TVE_TVE0_TVCCDATA1_reserved_30_15	16
	#define BWID_TVE_TVE0_TVCCDATA1_CC_D2	7
	#define BWID_TVE_TVE0_TVCCDATA1_reserved_7	1
	#define BWID_TVE_TVE0_TVCCDATA1_CC_D1	7
	/* Register Bit MASKS for TVE_TVE0_TVCCDATA1 */
	#define BMSK_TVE_TVE0_TVCCDATA1_CC_RDY	(1<<31) /* == 0x80000000: (read only) 0:CC engine ready; 1: data fifo full */
	#define BMSK_TVE_TVE0_TVCCDATA1_reserved_30_15	0x7fff8000 /*  */
	#define BMSK_TVE_TVE0_TVCCDATA1_CC_D2	0x00007f00 /* cc_data2 */
	#define BMSK_TVE_TVE0_TVCCDATA1_reserved_7	(1<<7) /* == 0x00000080:  */
	#define BMSK_TVE_TVE0_TVCCDATA1_CC_D1	0x0000007f /* cc_data1 */
	/* Register BITFIELD for TVE_TVE0_TVCCDATA1 - roff, lsb, width, mask */
	#define BITFIELD_TVE_TVE0_TVCCDATA1_CC_RDY	 0x58094, 31, 1, 0x80000000
	#define BITFIELD_TVE_TVE0_TVCCDATA1_reserved_30_15	 0x58094, 15, 16, 0x7fff8000
	#define BITFIELD_TVE_TVE0_TVCCDATA1_CC_D2	 0x58094, 8, 7, 0x00007f00
	#define BITFIELD_TVE_TVE0_TVCCDATA1_reserved_7	 0x58094, 7, 1, 0x00000080
	#define BITFIELD_TVE_TVE0_TVCCDATA1_CC_D1	 0x58094, 0, 7, 0x0000007f
#define ROFF_TVE_TVE0_TVCCDATA2	0x58098 /* TV CC Data Field 2 */ 
	#define BITFIELD_TVE_TVE0_TVCCDATA2	 0x58098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TVE_TVE0_TVCCDATA2 */
	#define BLSB_TVE_TVE0_TVCCDATA2_CC_RDY	31
	#define BLSB_TVE_TVE0_TVCCDATA2_reserved_30_15	15
	#define BLSB_TVE_TVE0_TVCCDATA2_CC_D2	8
	#define BLSB_TVE_TVE0_TVCCDATA2_reserved_7	7
	#define BLSB_TVE_TVE0_TVCCDATA2_CC_D1	0
	/* Register Bit Widths for TVE_TVE0_TVCCDATA2 */
	#define BWID_TVE_TVE0_TVCCDATA2_CC_RDY	1
	#define BWID_TVE_TVE0_TVCCDATA2_reserved_30_15	16
	#define BWID_TVE_TVE0_TVCCDATA2_CC_D2	7
	#define BWID_TVE_TVE0_TVCCDATA2_reserved_7	1
	#define BWID_TVE_TVE0_TVCCDATA2_CC_D1	7
	/* Register Bit MASKS for TVE_TVE0_TVCCDATA2 */
	#define BMSK_TVE_TVE0_TVCCDATA2_CC_RDY	(1<<31) /* == 0x80000000: (read only) 0:CC engine ready; 1: data fifo full */
	#define BMSK_TVE_TVE0_TVCCDATA2_reserved_30_15	0x7fff8000 /*  */
	#define BMSK_TVE_TVE0_TVCCDATA2_CC_D2	0x00007f00 /* cc_data2 */
	#define BMSK_TVE_TVE0_TVCCDATA2_reserved_7	(1<<7) /* == 0x00000080:  */
	#define BMSK_TVE_TVE0_TVCCDATA2_CC_D1	0x0000007f /* cc_data1 */
	/* Register BITFIELD for TVE_TVE0_TVCCDATA2 - roff, lsb, width, mask */
	#define BITFIELD_TVE_TVE0_TVCCDATA2_CC_RDY	 0x58098, 31, 1, 0x80000000
	#define BITFIELD_TVE_TVE0_TVCCDATA2_reserved_30_15	 0x58098, 15, 16, 0x7fff8000
	#define BITFIELD_TVE_TVE0_TVCCDATA2_CC_D2	 0x58098, 8, 7, 0x00007f00
	#define BITFIELD_TVE_TVE0_TVCCDATA2_reserved_7	 0x58098, 7, 1, 0x00000080
	#define BITFIELD_TVE_TVE0_TVCCDATA2_CC_D1	 0x58098, 0, 7, 0x0000007f
#define ROFF_TVE_TVE0_TVHYCOEFF_0	0x58100 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_0	 0x58100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_1	0x58104 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_1	 0x58104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_2	0x58108 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_2	 0x58108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_3	0x5810c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_3	 0x5810c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_4	0x58110 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_4	 0x58110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_5	0x58114 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_5	 0x58114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_6	0x58118 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_6	 0x58118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_7	0x5811c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_7	 0x5811c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_8	0x58120 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_8	 0x58120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_9	0x58124 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_9	 0x58124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_10	0x58128 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_10	 0x58128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_11	0x5812c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_11	 0x5812c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_12	0x58130 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_12	 0x58130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_13	0x58134 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_13	 0x58134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_14	0x58138 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_14	 0x58138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_15	0x5813c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_15	 0x5813c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_16	0x58140 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_16	 0x58140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_17	0x58144 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_17	 0x58144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_18	0x58148 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_18	 0x58148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_19	0x5814c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_19	 0x5814c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_20	0x58150 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_20	 0x58150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_21	0x58154 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_21	 0x58154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_22	0x58158 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_22	 0x58158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_23	0x5815c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_23	 0x5815c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_24	0x58160 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_24	 0x58160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_25	0x58164 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_25	 0x58164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_26	0x58168 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_26	 0x58168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_27	0x5816c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_27	 0x5816c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_28	0x58170 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_28	 0x58170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_29	0x58174 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_29	 0x58174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_30	0x58178 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_30	 0x58178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_31	0x5817c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_31	 0x5817c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_32	0x58180 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_32	 0x58180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_33	0x58184 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_33	 0x58184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_34	0x58188 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_34	 0x58188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_35	0x5818c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_35	 0x5818c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_36	0x58190 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_36	 0x58190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_37	0x58194 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_37	 0x58194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_38	0x58198 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_38	 0x58198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_39	0x5819c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_39	 0x5819c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_40	0x581a0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_40	 0x581a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_41	0x581a4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_41	 0x581a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_42	0x581a8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_42	 0x581a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_43	0x581ac /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_43	 0x581ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_44	0x581b0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_44	 0x581b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_45	0x581b4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_45	 0x581b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_46	0x581b8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_46	 0x581b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_47	0x581bc /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_47	 0x581bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_48	0x581c0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_48	 0x581c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_49	0x581c4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_49	 0x581c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_50	0x581c8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_50	 0x581c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_51	0x581cc /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_51	 0x581cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_52	0x581d0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_52	 0x581d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_53	0x581d4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_53	 0x581d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_54	0x581d8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_54	 0x581d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_55	0x581dc /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_55	 0x581dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_56	0x581e0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_56	 0x581e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_57	0x581e4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_57	 0x581e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_58	0x581e8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_58	 0x581e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHYCOEFF_59	0x581ec /*  */ 
	#define BITFIELD_TVE_TVE0_TVHYCOEFF_59	 0x581ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_0	0x58200 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_0	 0x58200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_1	0x58204 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_1	 0x58204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_2	0x58208 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_2	 0x58208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_3	0x5820c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_3	 0x5820c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_4	0x58210 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_4	 0x58210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_5	0x58214 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_5	 0x58214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_6	0x58218 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_6	 0x58218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_7	0x5821c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_7	 0x5821c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_8	0x58220 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_8	 0x58220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_9	0x58224 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_9	 0x58224, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_10	0x58228 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_10	 0x58228, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_11	0x5822c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_11	 0x5822c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_12	0x58230 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_12	 0x58230, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_13	0x58234 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_13	 0x58234, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_14	0x58238 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_14	 0x58238, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_15	0x5823c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_15	 0x5823c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_16	0x58240 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_16	 0x58240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_17	0x58244 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_17	 0x58244, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_18	0x58248 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_18	 0x58248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_19	0x5824c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_19	 0x5824c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_20	0x58250 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_20	 0x58250, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_21	0x58254 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_21	 0x58254, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_22	0x58258 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_22	 0x58258, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_23	0x5825c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_23	 0x5825c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_24	0x58260 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_24	 0x58260, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_25	0x58264 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_25	 0x58264, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_26	0x58268 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_26	 0x58268, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_27	0x5826c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_27	 0x5826c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_28	0x58270 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_28	 0x58270, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_29	0x58274 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_29	 0x58274, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_30	0x58278 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_30	 0x58278, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_31	0x5827c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_31	 0x5827c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_32	0x58280 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_32	 0x58280, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_33	0x58284 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_33	 0x58284, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_34	0x58288 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_34	 0x58288, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_35	0x5828c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_35	 0x5828c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_36	0x58290 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_36	 0x58290, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_37	0x58294 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_37	 0x58294, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_38	0x58298 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_38	 0x58298, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_39	0x5829c /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_39	 0x5829c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_40	0x582a0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_40	 0x582a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_41	0x582a4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_41	 0x582a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_42	0x582a8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_42	 0x582a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_43	0x582ac /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_43	 0x582ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_44	0x582b0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_44	 0x582b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_45	0x582b4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_45	 0x582b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_46	0x582b8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_46	 0x582b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_47	0x582bc /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_47	 0x582bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_48	0x582c0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_48	 0x582c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_49	0x582c4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_49	 0x582c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_50	0x582c8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_50	 0x582c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_51	0x582cc /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_51	 0x582cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_52	0x582d0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_52	 0x582d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_53	0x582d4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_53	 0x582d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_54	0x582d8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_54	 0x582d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_55	0x582dc /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_55	 0x582dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_56	0x582e0 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_56	 0x582e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_57	0x582e4 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_57	 0x582e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_58	0x582e8 /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_58	 0x582e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE0_TVHUVCOEFF_59	0x582ec /*  */ 
	#define BITFIELD_TVE_TVE0_TVHUVCOEFF_59	 0x582ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_HTOTALB	0x68500 /*  */ 
	#define BITFIELD_TVE_TVE1_HTOTALB	 0x68500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_HBLANKB	0x68504 /*  */ 
	#define BITFIELD_TVE_TVE1_HBLANKB	 0x68504, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_HSYNCB	0x68508 /*  */ 
	#define BITFIELD_TVE_TVE1_HSYNCB	 0x68508, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_VTOTALB	0x6850c /*  */ 
	#define BITFIELD_TVE_TVE1_VTOTALB	 0x6850c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_VBLANKB	0x68510 /*  */ 
	#define BITFIELD_TVE_TVE1_VBLANKB	 0x68510, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_VSYNCB	0x68514 /*  */ 
	#define BITFIELD_TVE_TVE1_VSYNCB	 0x68514, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_PIPEBCONF	0x68550 /* Pipe B Config */ 
	#define BITFIELD_TVE_PIPEBCONF	 0x68550, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TVE_PIPEBCONF */
	#define BLSB_TVE_PIPEBCONF_PipeB_Enable	31
	#define BLSB_TVE_PIPEBCONF_PipeB_Destination	29
	#define BLSB_TVE_PIPEBCONF_Frmstart_Delay	27
	#define BLSB_TVE_PIPEBCONF_reserved_26_21	21
	#define BLSB_TVE_PIPEBCONF_Interlaced_Mode	20
	#define BLSB_TVE_PIPEBCONF_Force_Planes_Off	19
	#define BLSB_TVE_PIPEBCONF_reserved_18_0	0
	/* Register Bit Widths for TVE_PIPEBCONF */
	#define BWID_TVE_PIPEBCONF_PipeB_Enable	1
	#define BWID_TVE_PIPEBCONF_PipeB_Destination	2
	#define BWID_TVE_PIPEBCONF_Frmstart_Delay	2
	#define BWID_TVE_PIPEBCONF_reserved_26_21	6
	#define BWID_TVE_PIPEBCONF_Interlaced_Mode	1
	#define BWID_TVE_PIPEBCONF_Force_Planes_Off	1
	#define BWID_TVE_PIPEBCONF_reserved_18_0	18
	/* Register Bit MASKS for TVE_PIPEBCONF */
	#define BMSK_TVE_PIPEBCONF_PipeB_Enable	(1<<31) /* == 0x80000000:  */
	#define BMSK_TVE_PIPEBCONF_PipeB_Destination	0x60000000 /* 00:Enc1;01:Enc0;10:Res;11:Both */
	#define BMSK_TVE_PIPEBCONF_Frmstart_Delay	0x18000000 /*  */
	#define BMSK_TVE_PIPEBCONF_reserved_26_21	0x07e00000 /*  */
	#define BMSK_TVE_PIPEBCONF_Interlaced_Mode	(1<<20) /* == 0x00100000: 0:Progressive; 1:Interlaced */
	#define BMSK_TVE_PIPEBCONF_Force_Planes_Off	(1<<19) /* == 0x00080000: 0:Norm; 1:Disabled */
	#define BMSK_TVE_PIPEBCONF_reserved_18_0	0x0003ffff /*  */
	/* Register BITFIELD for TVE_PIPEBCONF - roff, lsb, width, mask */
	#define BITFIELD_TVE_PIPEBCONF_PipeB_Enable	 0x68550, 31, 1, 0x80000000
	#define BITFIELD_TVE_PIPEBCONF_PipeB_Destination	 0x68550, 29, 2, 0x60000000
	#define BITFIELD_TVE_PIPEBCONF_Frmstart_Delay	 0x68550, 27, 2, 0x18000000
	#define BITFIELD_TVE_PIPEBCONF_reserved_26_21	 0x68550, 21, 6, 0x07e00000
	#define BITFIELD_TVE_PIPEBCONF_Interlaced_Mode	 0x68550, 20, 1, 0x00100000
	#define BITFIELD_TVE_PIPEBCONF_Force_Planes_Off	 0x68550, 19, 1, 0x00080000
	#define BITFIELD_TVE_PIPEBCONF_reserved_18_0	 0x68550, 0, 18, 0x0003ffff
#define ROFF_TVE_PIPEBSTAT	0x68554 /*  */ 
	#define BITFIELD_TVE_PIPEBSTAT	 0x68554, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCTRL	0x68000 /*  */ 
	#define BITFIELD_TVE_TVE1_TVCTRL	 0x68000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVDACCTRL	0x68004 /*  */ 
	#define BITFIELD_TVE_TVE1_TVDACCTRL	 0x68004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCSCY1	0x68010 /*  */ 
	#define BITFIELD_TVE_TVE1_TVCSCY1	 0x68010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCSCY2	0x68014 /*  */ 
	#define BITFIELD_TVE_TVE1_TVCSCY2	 0x68014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCSCU1	0x68018 /*  */ 
	#define BITFIELD_TVE_TVE1_TVCSCU1	 0x68018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCSCU2	0x6801c /*  */ 
	#define BITFIELD_TVE_TVE1_TVCSCU2	 0x6801c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCSCV1	0x68020 /*  */ 
	#define BITFIELD_TVE_TVE1_TVCSCV1	 0x68020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVCSCV2	0x68024 /*  */ 
	#define BITFIELD_TVE_TVE1_TVCSCV2	 0x68024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVBIYLEVEL	0x68008 /*  */ 
	#define BITFIELD_TVE_TVE1_TVVBIYLEVEL	 0x68008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVUVOFF	0x6800c /*  */ 
	#define BITFIELD_TVE_TVE1_TVUVOFF	 0x6800c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVBCSH	0x68028 /*  */ 
	#define BITFIELD_TVE_TVE1_TVBCSH	 0x68028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVBLEVEL	0x6802c /*  */ 
	#define BITFIELD_TVE_TVE1_TVBLEVEL	 0x6802c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHCTRL1	0x68030 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHCTRL1	 0x68030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHCTRL2	0x68034 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHCTRL2	 0x68034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHCTRL3	0x68038 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHCTRL3	 0x68038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL1	0x6803c /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL1	 0x6803c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL2	0x68040 /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL2	 0x68040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL3	0x68044 /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL3	 0x68044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL4	0x68048 /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL4	 0x68048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL5	0x6804c /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL5	 0x6804c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL6	0x68050 /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL6	 0x68050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVVCTRL7	0x68054 /*  */ 
	#define BITFIELD_TVE_TVE1_TVVCTRL7	 0x68054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVSCCTRL1	0x68060 /*  */ 
	#define BITFIELD_TVE_TVE1_TVSCCTRL1	 0x68060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVSCCTRL2	0x68064 /*  */ 
	#define BITFIELD_TVE_TVE1_TVSCCTRL2	 0x68064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVSCCTRL3	0x68068 /*  */ 
	#define BITFIELD_TVE_TVE1_TVSCCTRL3	 0x68068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVWINPOS	0x68070 /*  */ 
	#define BITFIELD_TVE_TVE1_TVWINPOS	 0x68070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVWINSZ	0x68074 /*  */ 
	#define BITFIELD_TVE_TVE1_TVWINSZ	 0x68074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVFILTCTRL1	0x68080 /*  */ 
	#define BITFIELD_TVE_TVE1_TVFILTCTRL1	 0x68080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVSINROM	0x6808c /*  */ 
	#define BITFIELD_TVE_TVE1_TVSINROM	 0x6808c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF	0x68100 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF	 0x68100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF	0x68200 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF	 0x68200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_0	0x68100 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_0	 0x68100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_1	0x68104 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_1	 0x68104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_2	0x68108 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_2	 0x68108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_3	0x6810c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_3	 0x6810c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_4	0x68110 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_4	 0x68110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_5	0x68114 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_5	 0x68114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_6	0x68118 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_6	 0x68118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_7	0x6811c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_7	 0x6811c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_8	0x68120 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_8	 0x68120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_9	0x68124 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_9	 0x68124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_10	0x68128 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_10	 0x68128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_11	0x6812c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_11	 0x6812c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_12	0x68130 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_12	 0x68130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_13	0x68134 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_13	 0x68134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_14	0x68138 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_14	 0x68138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_15	0x6813c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_15	 0x6813c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_16	0x68140 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_16	 0x68140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_17	0x68144 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_17	 0x68144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_18	0x68148 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_18	 0x68148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_19	0x6814c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_19	 0x6814c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_20	0x68150 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_20	 0x68150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_21	0x68154 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_21	 0x68154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_22	0x68158 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_22	 0x68158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_23	0x6815c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_23	 0x6815c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_24	0x68160 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_24	 0x68160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_25	0x68164 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_25	 0x68164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_26	0x68168 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_26	 0x68168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_27	0x6816c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_27	 0x6816c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_28	0x68170 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_28	 0x68170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_29	0x68174 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_29	 0x68174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_30	0x68178 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_30	 0x68178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_31	0x6817c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_31	 0x6817c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_32	0x68180 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_32	 0x68180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_33	0x68184 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_33	 0x68184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_34	0x68188 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_34	 0x68188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_35	0x6818c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_35	 0x6818c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_36	0x68190 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_36	 0x68190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_37	0x68194 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_37	 0x68194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_38	0x68198 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_38	 0x68198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_39	0x6819c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_39	 0x6819c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_40	0x681a0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_40	 0x681a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_41	0x681a4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_41	 0x681a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_42	0x681a8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_42	 0x681a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_43	0x681ac /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_43	 0x681ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_44	0x681b0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_44	 0x681b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_45	0x681b4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_45	 0x681b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_46	0x681b8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_46	 0x681b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_47	0x681bc /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_47	 0x681bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_48	0x681c0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_48	 0x681c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_49	0x681c4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_49	 0x681c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_50	0x681c8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_50	 0x681c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_51	0x681cc /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_51	 0x681cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_52	0x681d0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_52	 0x681d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_53	0x681d4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_53	 0x681d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_54	0x681d8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_54	 0x681d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_55	0x681dc /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_55	 0x681dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_56	0x681e0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_56	 0x681e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_57	0x681e4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_57	 0x681e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_58	0x681e8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_58	 0x681e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHYCOEFF_59	0x681ec /*  */ 
	#define BITFIELD_TVE_TVE1_TVHYCOEFF_59	 0x681ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_0	0x68200 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_0	 0x68200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_1	0x68204 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_1	 0x68204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_2	0x68208 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_2	 0x68208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_3	0x6820c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_3	 0x6820c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_4	0x68210 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_4	 0x68210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_5	0x68214 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_5	 0x68214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_6	0x68218 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_6	 0x68218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_7	0x6821c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_7	 0x6821c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_8	0x68220 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_8	 0x68220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_9	0x68224 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_9	 0x68224, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_10	0x68228 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_10	 0x68228, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_11	0x6822c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_11	 0x6822c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_12	0x68230 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_12	 0x68230, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_13	0x68234 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_13	 0x68234, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_14	0x68238 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_14	 0x68238, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_15	0x6823c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_15	 0x6823c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_16	0x68240 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_16	 0x68240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_17	0x68244 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_17	 0x68244, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_18	0x68248 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_18	 0x68248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_19	0x6824c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_19	 0x6824c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_20	0x68250 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_20	 0x68250, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_21	0x68254 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_21	 0x68254, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_22	0x68258 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_22	 0x68258, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_23	0x6825c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_23	 0x6825c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_24	0x68260 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_24	 0x68260, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_25	0x68264 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_25	 0x68264, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_26	0x68268 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_26	 0x68268, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_27	0x6826c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_27	 0x6826c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_28	0x68270 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_28	 0x68270, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_29	0x68274 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_29	 0x68274, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_30	0x68278 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_30	 0x68278, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_31	0x6827c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_31	 0x6827c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_32	0x68280 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_32	 0x68280, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_33	0x68284 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_33	 0x68284, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_34	0x68288 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_34	 0x68288, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_35	0x6828c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_35	 0x6828c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_36	0x68290 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_36	 0x68290, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_37	0x68294 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_37	 0x68294, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_38	0x68298 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_38	 0x68298, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_39	0x6829c /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_39	 0x6829c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_40	0x682a0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_40	 0x682a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_41	0x682a4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_41	 0x682a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_42	0x682a8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_42	 0x682a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_43	0x682ac /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_43	 0x682ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_44	0x682b0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_44	 0x682b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_45	0x682b4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_45	 0x682b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_46	0x682b8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_46	 0x682b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_47	0x682bc /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_47	 0x682bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_48	0x682c0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_48	 0x682c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_49	0x682c4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_49	 0x682c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_50	0x682c8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_50	 0x682c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_51	0x682cc /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_51	 0x682cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_52	0x682d0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_52	 0x682d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_53	0x682d4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_53	 0x682d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_54	0x682d8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_54	 0x682d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_55	0x682dc /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_55	 0x682dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_56	0x682e0 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_56	 0x682e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_57	0x682e4 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_57	 0x682e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_58	0x682e8 /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_58	 0x682e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TVE_TVE1_TVHUVCOEFF_59	0x682ec /*  */ 
	#define BITFIELD_TVE_TVE1_TVHUVCOEFF_59	 0x682ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module TVE SPECIFIC SVEN Events */




#endif /* TVE_REGOFFS_H */
