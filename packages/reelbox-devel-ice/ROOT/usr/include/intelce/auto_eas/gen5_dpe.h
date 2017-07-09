#ifndef DPE_REGOFFS_H
#define DPE_REGOFFS_H 1
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


/* Module DPE CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_DPE_DPE_420_422_STRIDE_HEIGHT	0x180 /* Stride height and no of strides - fixed for all strides in one picture */ 
	#define BITFIELD_DPE_DPE_420_422_STRIDE_HEIGHT	 0x0180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_420_422_STRIDE_HEIGHT */
	#define BLSB_DPE_DPE_420_422_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_DPE_420_422_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_DPE_420_422_STRIDE_HEIGHT */
	#define BWID_DPE_DPE_420_422_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_DPE_420_422_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_DPE_420_422_STRIDE_HEIGHT */
	#define BMSK_DPE_DPE_420_422_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_420_422_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_420_422_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_420_422_STRIDE_HEIGHT_num_strides	 0x0180, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_420_422_STRIDE_HEIGHT_stride_h	 0x0180, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_420_422_Y_STRIDE_WIDTH	0x184 /* N Component Y stride width */ 
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH	 0x0184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_420_422_Y_STRIDE_WIDTH */
	#define BLSB_DPE_DPE_420_422_Y_STRIDE_WIDTH_next_rd_offset_x	27
	#define BLSB_DPE_DPE_420_422_Y_STRIDE_WIDTH_pix_coord_x	16
	#define BLSB_DPE_DPE_420_422_Y_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_DPE_420_422_Y_STRIDE_WIDTH_RM	6
	#define BLSB_DPE_DPE_420_422_Y_STRIDE_WIDTH_LM	5
	#define BLSB_DPE_DPE_420_422_Y_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_420_422_Y_STRIDE_WIDTH */
	#define BWID_DPE_DPE_420_422_Y_STRIDE_WIDTH_next_rd_offset_x	5
	#define BWID_DPE_DPE_420_422_Y_STRIDE_WIDTH_pix_coord_x	11
	#define BWID_DPE_DPE_420_422_Y_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_DPE_420_422_Y_STRIDE_WIDTH_RM	1
	#define BWID_DPE_DPE_420_422_Y_STRIDE_WIDTH_LM	1
	#define BWID_DPE_DPE_420_422_Y_STRIDE_WIDTH_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_420_422_Y_STRIDE_WIDTH */
	#define BMSK_DPE_DPE_420_422_Y_STRIDE_WIDTH_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_420_422_Y_STRIDE_WIDTH_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DPE_420_422_Y_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_420_422_Y_STRIDE_WIDTH_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_420_422_Y_STRIDE_WIDTH_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_420_422_Y_STRIDE_WIDTH_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_420_422_Y_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH_next_rd_offset_x	 0x0184, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH_pix_coord_x	 0x0184, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH_out_stride_w	 0x0184, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH_RM	 0x0184, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH_LM	 0x0184, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_420_422_Y_STRIDE_WIDTH_in_stride_off	 0x0184, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_420_422_cbcr_STRIDE_WIDTH	0x188 /* N Component cbcr stride width */ 
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH	 0x0188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_420_422_cbcr_STRIDE_WIDTH */
	#define BLSB_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_next_rd_offset_x	27
	#define BLSB_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_pix_coord_x	16
	#define BLSB_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_RM	6
	#define BLSB_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_LM	5
	#define BLSB_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_420_422_cbcr_STRIDE_WIDTH */
	#define BWID_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_next_rd_offset_x	5
	#define BWID_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_pix_coord_x	11
	#define BWID_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_RM	1
	#define BWID_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_LM	1
	#define BWID_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_420_422_cbcr_STRIDE_WIDTH */
	#define BMSK_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_420_422_cbcr_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_next_rd_offset_x	 0x0188, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_pix_coord_x	 0x0188, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_out_stride_w	 0x0188, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_RM	 0x0188, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_LM	 0x0188, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_420_422_cbcr_STRIDE_WIDTH_in_stride_off	 0x0188, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_420_422_Converter_Control	0x1e0 /* control register */ 
	#define BITFIELD_DPE_DPE_420_422_Converter_Control	 0x01e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_420_422_Converter_Control */
	#define BLSB_DPE_DPE_420_422_Converter_Control_Pxl_Repeat	4
	#define BLSB_DPE_DPE_420_422_Converter_Control_PI	3
	#define BLSB_DPE_DPE_420_422_Converter_Control_TOP	2
	#define BLSB_DPE_DPE_420_422_Converter_Control_BYP	1
	#define BLSB_DPE_DPE_420_422_Converter_Control_UNIT_EN	0
	/* Register Bit Widths for DPE_DPE_420_422_Converter_Control */
	#define BWID_DPE_DPE_420_422_Converter_Control_Pxl_Repeat	1
	#define BWID_DPE_DPE_420_422_Converter_Control_PI	1
	#define BWID_DPE_DPE_420_422_Converter_Control_TOP	1
	#define BWID_DPE_DPE_420_422_Converter_Control_BYP	1
	#define BWID_DPE_DPE_420_422_Converter_Control_UNIT_EN	1
	/* Register Bit MASKS for DPE_DPE_420_422_Converter_Control */
	#define BMSK_DPE_DPE_420_422_Converter_Control_Pxl_Repeat	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_PI	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_TOP	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_BYP	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_UNIT_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_420_422_Converter_Control - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_Pxl_Repeat	 0x01e0, 4, 1, 0x00000010
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_PI	 0x01e0, 3, 1, 0x00000008
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_TOP	 0x01e0, 2, 1, 0x00000004
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_BYP	 0x01e0, 1, 1, 0x00000002
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_UNIT_EN	 0x01e0, 0, 1, 0x00000001
#define ROFF_DPE_HIST_Y_BIN	0x6500 /* The Histogram for Y */ 
	#define BITFIELD_DPE_HIST_Y_BIN	 0x6500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_HIST_Cb_BIN	0x6700 /* The Histogram for Cb */ 
	#define BITFIELD_DPE_HIST_Cb_BIN	 0x6700, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_HIST_Cr_BIN	0x6900 /* The Histogram for Cr */ 
	#define BITFIELD_DPE_HIST_Cr_BIN	 0x6900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_HIST_CbCr_BIN	0x3d0 /* The Histogram for CbCr */ 
	#define BITFIELD_DPE_HIST_CbCr_BIN	 0x03d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_CP_CONTROL_REGISTER	0x7000 /* Controls the reset and configuration of Control Plane */ 
	#define BITFIELD_DPE_CP_CONTROL_REGISTER	 0x7000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_CONTROL_REGISTER */
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC3_Enable	19
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC3_Clk_Sel	17
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC2_Enable	16
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC2_Clk_Sel	14
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC1_Enable	13
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC1_Clk_Sel	11
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC0_Enable	10
	#define BLSB_DPE_CP_CONTROL_REGISTER_STC0_Clk_Sel	8
	#define BLSB_DPE_CP_CONTROL_REGISTER_Watchdog_Timer_enable	7
	#define BLSB_DPE_CP_CONTROL_REGISTER_ATR	5
	#define BLSB_DPE_CP_CONTROL_REGISTER_PIP	2
	#define BLSB_DPE_CP_CONTROL_REGISTER_DPE_Reset_l	1
	#define BLSB_DPE_CP_CONTROL_REGISTER_CP_Reset_l	0
	/* Register Bit Widths for DPE_CP_CONTROL_REGISTER */
	#define BWID_DPE_CP_CONTROL_REGISTER_STC3_Enable	1
	#define BWID_DPE_CP_CONTROL_REGISTER_STC3_Clk_Sel	2
	#define BWID_DPE_CP_CONTROL_REGISTER_STC2_Enable	1
	#define BWID_DPE_CP_CONTROL_REGISTER_STC2_Clk_Sel	2
	#define BWID_DPE_CP_CONTROL_REGISTER_STC1_Enable	1
	#define BWID_DPE_CP_CONTROL_REGISTER_STC1_Clk_Sel	2
	#define BWID_DPE_CP_CONTROL_REGISTER_STC0_Enable	1
	#define BWID_DPE_CP_CONTROL_REGISTER_STC0_Clk_Sel	2
	#define BWID_DPE_CP_CONTROL_REGISTER_Watchdog_Timer_enable	1
	#define BWID_DPE_CP_CONTROL_REGISTER_ATR	2
	#define BWID_DPE_CP_CONTROL_REGISTER_PIP	1
	#define BWID_DPE_CP_CONTROL_REGISTER_DPE_Reset_l	1
	#define BWID_DPE_CP_CONTROL_REGISTER_CP_Reset_l	1
	/* Register Bit MASKS for DPE_CP_CONTROL_REGISTER */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC3_Enable	(1<<19) /* == 0x00080000:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC3_Clk_Sel	0x00060000 /*  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC2_Enable	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC2_Clk_Sel	0x0000c000 /*  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC1_Enable	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC1_Clk_Sel	0x00001800 /*  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC0_Enable	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_STC0_Clk_Sel	0x00000300 /*  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_Watchdog_Timer_enable	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_ATR	0x00000060 /*  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_PIP	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_DPE_Reset_l	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_CP_CONTROL_REGISTER_CP_Reset_l	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_CP_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC3_Enable	 0x7000, 19, 1, 0x00080000
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC3_Clk_Sel	 0x7000, 17, 2, 0x00060000
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC2_Enable	 0x7000, 16, 1, 0x00010000
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC2_Clk_Sel	 0x7000, 14, 2, 0x0000c000
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC1_Enable	 0x7000, 13, 1, 0x00002000
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC1_Clk_Sel	 0x7000, 11, 2, 0x00001800
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC0_Enable	 0x7000, 10, 1, 0x00000400
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_STC0_Clk_Sel	 0x7000, 8, 2, 0x00000300
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_Watchdog_Timer_enable	 0x7000, 7, 1, 0x00000080
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_ATR	 0x7000, 5, 2, 0x00000060
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_PIP	 0x7000, 2, 1, 0x00000004
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_DPE_Reset_l	 0x7000, 1, 1, 0x00000002
	#define BITFIELD_DPE_CP_CONTROL_REGISTER_CP_Reset_l	 0x7000, 0, 1, 0x00000001
#define ROFF_DPE_CP_ICACHE_BASE_ADDRESS	0x7004 /* Instruction Code base system address */ 
	#define BITFIELD_DPE_CP_ICACHE_BASE_ADDRESS	 0x7004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_ICACHE_BASE_ADDRESS */
	#define BLSB_DPE_CP_ICACHE_BASE_ADDRESS_Base_address	14
	/* Register Bit Widths for DPE_CP_ICACHE_BASE_ADDRESS */
	#define BWID_DPE_CP_ICACHE_BASE_ADDRESS_Base_address	18
	/* Register Bit MASKS for DPE_CP_ICACHE_BASE_ADDRESS */
	#define BMSK_DPE_CP_ICACHE_BASE_ADDRESS_Base_address	0xffffc000 /*  */
	/* Register BITFIELD for DPE_CP_ICACHE_BASE_ADDRESS - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_ICACHE_BASE_ADDRESS_Base_address	 0x7004, 14, 18, 0xffffc000
#define ROFF_DPE_CP_WATCHDOG_TIMER	0x7008 /* A free running watchdog timer */ 
	#define BITFIELD_DPE_CP_WATCHDOG_TIMER	 0x7008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_WATCHDOG_TIMER */
	#define BLSB_DPE_CP_WATCHDOG_TIMER_Timer	0
	/* Register Bit Widths for DPE_CP_WATCHDOG_TIMER */
	#define BWID_DPE_CP_WATCHDOG_TIMER_Timer	20
	/* Register Bit MASKS for DPE_CP_WATCHDOG_TIMER */
	#define BMSK_DPE_CP_WATCHDOG_TIMER_Timer	0x000fffff /*  */
	/* Register BITFIELD for DPE_CP_WATCHDOG_TIMER - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_WATCHDOG_TIMER_Timer	 0x7008, 0, 20, 0x000fffff
#define ROFF_DPE_CACHELINE_INVALIDATE0	0x7010 /* 32-bit lower Icache line invalidate mask */ 
	#define BITFIELD_DPE_CACHELINE_INVALIDATE0	 0x7010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CACHELINE_INVALIDATE0 */
	#define BLSB_DPE_CACHELINE_INVALIDATE0_Cacheline_Invalidate_mask	0
	/* Register Bit Widths for DPE_CACHELINE_INVALIDATE0 */
	#define BWID_DPE_CACHELINE_INVALIDATE0_Cacheline_Invalidate_mask	32
	/* Register Bit MASKS for DPE_CACHELINE_INVALIDATE0 */
	#define BMSK_DPE_CACHELINE_INVALIDATE0_Cacheline_Invalidate_mask	0x00000000 /*  */
	/* Register BITFIELD for DPE_CACHELINE_INVALIDATE0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CACHELINE_INVALIDATE0_Cacheline_Invalidate_mask	 0x7010, 0, 32, 0x00000000
#define ROFF_DPE_CACHELINE_INVALIDATE1	0x7014 /* 32-bit lower Icache line invalidate mask */ 
	#define BITFIELD_DPE_CACHELINE_INVALIDATE1	 0x7014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CACHELINE_INVALIDATE1 */
	#define BLSB_DPE_CACHELINE_INVALIDATE1_Cacheline_Invalidate_mask	0
	/* Register Bit Widths for DPE_CACHELINE_INVALIDATE1 */
	#define BWID_DPE_CACHELINE_INVALIDATE1_Cacheline_Invalidate_mask	32
	/* Register Bit MASKS for DPE_CACHELINE_INVALIDATE1 */
	#define BMSK_DPE_CACHELINE_INVALIDATE1_Cacheline_Invalidate_mask	0x00000000 /*  */
	/* Register BITFIELD for DPE_CACHELINE_INVALIDATE1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CACHELINE_INVALIDATE1_Cacheline_Invalidate_mask	 0x7014, 0, 32, 0x00000000
#define ROFF_DPE_CACHELINE_INVALIDATE2	0x7018 /* 32-bit lower Icache line invalidate mask */ 
	#define BITFIELD_DPE_CACHELINE_INVALIDATE2	 0x7018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CACHELINE_INVALIDATE2 */
	#define BLSB_DPE_CACHELINE_INVALIDATE2_Cacheline_Invalidate_mask	0
	/* Register Bit Widths for DPE_CACHELINE_INVALIDATE2 */
	#define BWID_DPE_CACHELINE_INVALIDATE2_Cacheline_Invalidate_mask	32
	/* Register Bit MASKS for DPE_CACHELINE_INVALIDATE2 */
	#define BMSK_DPE_CACHELINE_INVALIDATE2_Cacheline_Invalidate_mask	0x00000000 /*  */
	/* Register BITFIELD for DPE_CACHELINE_INVALIDATE2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CACHELINE_INVALIDATE2_Cacheline_Invalidate_mask	 0x7018, 0, 32, 0x00000000
#define ROFF_DPE_CP_DMA_SYSTEM_ADDRESS	0x7020 /* 32-bit system address for DMA */ 
	#define BITFIELD_DPE_CP_DMA_SYSTEM_ADDRESS	 0x7020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_DMA_SYSTEM_ADDRESS */
	#define BLSB_DPE_CP_DMA_SYSTEM_ADDRESS_System_address	0
	/* Register Bit Widths for DPE_CP_DMA_SYSTEM_ADDRESS */
	#define BWID_DPE_CP_DMA_SYSTEM_ADDRESS_System_address	32
	/* Register Bit MASKS for DPE_CP_DMA_SYSTEM_ADDRESS */
	#define BMSK_DPE_CP_DMA_SYSTEM_ADDRESS_System_address	0x00000000 /*  */
	/* Register BITFIELD for DPE_CP_DMA_SYSTEM_ADDRESS - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_DMA_SYSTEM_ADDRESS_System_address	 0x7020, 0, 32, 0x00000000
#define ROFF_DPE_CP_DMA_LOCAL_ADDRESS	0x7024 /* 16-bit local address for DMA */ 
	#define BITFIELD_DPE_CP_DMA_LOCAL_ADDRESS	 0x7024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_DMA_LOCAL_ADDRESS */
	#define BLSB_DPE_CP_DMA_LOCAL_ADDRESS_Local_address	0
	/* Register Bit Widths for DPE_CP_DMA_LOCAL_ADDRESS */
	#define BWID_DPE_CP_DMA_LOCAL_ADDRESS_Local_address	16
	/* Register Bit MASKS for DPE_CP_DMA_LOCAL_ADDRESS */
	#define BMSK_DPE_CP_DMA_LOCAL_ADDRESS_Local_address	0x0000ffff /*  */
	/* Register BITFIELD for DPE_CP_DMA_LOCAL_ADDRESS - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_DMA_LOCAL_ADDRESS_Local_address	 0x7024, 0, 16, 0x0000ffff
#define ROFF_DPE_CP_DMA_CONTROL_STATUS	0x7028 /* DMA control and status register */ 
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS	 0x7028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_DMA_CONTROL_STATUS */
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_DMA_START	22
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_DMA_DONE	21
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_DMA_BUSY	20
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_DMA_BURST	18
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_BYTE_SWAP	17
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_DMA_Direction	16
	#define BLSB_DPE_CP_DMA_CONTROL_STATUS_DMA_Size	0
	/* Register Bit Widths for DPE_CP_DMA_CONTROL_STATUS */
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_DMA_START	1
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_DMA_DONE	1
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_DMA_BUSY	1
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_DMA_BURST	2
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_BYTE_SWAP	1
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_DMA_Direction	1
	#define BWID_DPE_CP_DMA_CONTROL_STATUS_DMA_Size	16
	/* Register Bit MASKS for DPE_CP_DMA_CONTROL_STATUS */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_DMA_START	(1<<22) /* == 0x00400000:  */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_DMA_DONE	(1<<21) /* == 0x00200000:  */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_DMA_BUSY	(1<<20) /* == 0x00100000:  */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_DMA_BURST	0x000c0000 /*  */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_BYTE_SWAP	(1<<17) /* == 0x00020000:  */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_DMA_Direction	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_CP_DMA_CONTROL_STATUS_DMA_Size	0x0000ffff /*  */
	/* Register BITFIELD for DPE_CP_DMA_CONTROL_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_DMA_START	 0x7028, 22, 1, 0x00400000
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_DMA_DONE	 0x7028, 21, 1, 0x00200000
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_DMA_BUSY	 0x7028, 20, 1, 0x00100000
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_DMA_BURST	 0x7028, 18, 2, 0x000c0000
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_BYTE_SWAP	 0x7028, 17, 1, 0x00020000
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_DMA_Direction	 0x7028, 16, 1, 0x00010000
	#define BITFIELD_DPE_CP_DMA_CONTROL_STATUS_DMA_Size	 0x7028, 0, 16, 0x0000ffff
#define ROFF_DPE_HOST_DOORBELL	0x7030 /* Host Processor doorbell register */ 
	#define BITFIELD_DPE_HOST_DOORBELL	 0x7030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HOST_DOORBELL */
	#define BLSB_DPE_HOST_DOORBELL_Doorbell_command	0
	/* Register Bit Widths for DPE_HOST_DOORBELL */
	#define BWID_DPE_HOST_DOORBELL_Doorbell_command	32
	/* Register Bit MASKS for DPE_HOST_DOORBELL */
	#define BMSK_DPE_HOST_DOORBELL_Doorbell_command	0x00000000 /*  */
	/* Register BITFIELD for DPE_HOST_DOORBELL - roff, lsb, width, mask */
	#define BITFIELD_DPE_HOST_DOORBELL_Doorbell_command	 0x7030, 0, 32, 0x00000000
#define ROFF_DPE_HOST_IPC_STATUS	0x7034 /* Host Processor doorbell and mailbox status register */ 
	#define BITFIELD_DPE_HOST_IPC_STATUS	 0x7034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HOST_IPC_STATUS */
	#define BLSB_DPE_HOST_IPC_STATUS_DONE	1
	#define BLSB_DPE_HOST_IPC_STATUS_READY	0
	/* Register Bit Widths for DPE_HOST_IPC_STATUS */
	#define BWID_DPE_HOST_IPC_STATUS_DONE	1
	#define BWID_DPE_HOST_IPC_STATUS_READY	1
	/* Register Bit MASKS for DPE_HOST_IPC_STATUS */
	#define BMSK_DPE_HOST_IPC_STATUS_DONE	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_HOST_IPC_STATUS_READY	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_HOST_IPC_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DPE_HOST_IPC_STATUS_DONE	 0x7034, 1, 1, 0x00000002
	#define BITFIELD_DPE_HOST_IPC_STATUS_READY	 0x7034, 0, 1, 0x00000001
#define ROFF_DPE_CP_DOORBELL	0x7038 /* Control Processor doorbell register */ 
	#define BITFIELD_DPE_CP_DOORBELL	 0x7038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_DOORBELL */
	#define BLSB_DPE_CP_DOORBELL_Doorbell_command	0
	/* Register Bit Widths for DPE_CP_DOORBELL */
	#define BWID_DPE_CP_DOORBELL_Doorbell_command	32
	/* Register Bit MASKS for DPE_CP_DOORBELL */
	#define BMSK_DPE_CP_DOORBELL_Doorbell_command	0x00000000 /*  */
	/* Register BITFIELD for DPE_CP_DOORBELL - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_DOORBELL_Doorbell_command	 0x7038, 0, 32, 0x00000000
#define ROFF_DPE_CP_IPC_STATUS	0x703c /* Control Processor doorbell and mailbox status register */ 
	#define BITFIELD_DPE_CP_IPC_STATUS	 0x703c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_IPC_STATUS */
	#define BLSB_DPE_CP_IPC_STATUS_DONE	1
	#define BLSB_DPE_CP_IPC_STATUS_READY	0
	/* Register Bit Widths for DPE_CP_IPC_STATUS */
	#define BWID_DPE_CP_IPC_STATUS_DONE	1
	#define BWID_DPE_CP_IPC_STATUS_READY	1
	/* Register Bit MASKS for DPE_CP_IPC_STATUS */
	#define BMSK_DPE_CP_IPC_STATUS_DONE	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_CP_IPC_STATUS_READY	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_CP_IPC_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_IPC_STATUS_DONE	 0x703c, 1, 1, 0x00000002
	#define BITFIELD_DPE_CP_IPC_STATUS_READY	 0x703c, 0, 1, 0x00000001
#define ROFF_DPE_CP_SYSTEM_TIME_COUNTER0	0x7040 /* System time stamp counter0 for video stream */ 
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER0	 0x7040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_SYSTEM_TIME_COUNTER0 */
	#define BLSB_DPE_CP_SYSTEM_TIME_COUNTER0_STC	0
	/* Register Bit Widths for DPE_CP_SYSTEM_TIME_COUNTER0 */
	#define BWID_DPE_CP_SYSTEM_TIME_COUNTER0_STC	32
	/* Register Bit MASKS for DPE_CP_SYSTEM_TIME_COUNTER0 */
	#define BMSK_DPE_CP_SYSTEM_TIME_COUNTER0_STC	0x00000000 /*  */
	/* Register BITFIELD for DPE_CP_SYSTEM_TIME_COUNTER0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER0_STC	 0x7040, 0, 32, 0x00000000
#define ROFF_DPE_CP_SYSTEM_TIME_COUNTER1	0x7044 /* System time stamp counter1 for video stream */ 
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER1	 0x7044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_SYSTEM_TIME_COUNTER1 */
	#define BLSB_DPE_CP_SYSTEM_TIME_COUNTER1_STC	0
	/* Register Bit Widths for DPE_CP_SYSTEM_TIME_COUNTER1 */
	#define BWID_DPE_CP_SYSTEM_TIME_COUNTER1_STC	32
	/* Register Bit MASKS for DPE_CP_SYSTEM_TIME_COUNTER1 */
	#define BMSK_DPE_CP_SYSTEM_TIME_COUNTER1_STC	0x00000000 /*  */
	/* Register BITFIELD for DPE_CP_SYSTEM_TIME_COUNTER1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER1_STC	 0x7044, 0, 32, 0x00000000
#define ROFF_DPE_CP_SYSTEM_TIME_COUNTER2	0x7048 /* System time stamp counter2 for video stream */ 
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER2	 0x7048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_SYSTEM_TIME_COUNTER2 */
	#define BLSB_DPE_CP_SYSTEM_TIME_COUNTER2_STC	0
	/* Register Bit Widths for DPE_CP_SYSTEM_TIME_COUNTER2 */
	#define BWID_DPE_CP_SYSTEM_TIME_COUNTER2_STC	32
	/* Register Bit MASKS for DPE_CP_SYSTEM_TIME_COUNTER2 */
	#define BMSK_DPE_CP_SYSTEM_TIME_COUNTER2_STC	0x00000000 /*  */
	/* Register BITFIELD for DPE_CP_SYSTEM_TIME_COUNTER2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER2_STC	 0x7048, 0, 32, 0x00000000
#define ROFF_DPE_CP_SYSTEM_TIME_COUNTER3	0x704c /* System time stamp counter3 for video stream */ 
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER3	 0x704c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_SYSTEM_TIME_COUNTER3 */
	#define BLSB_DPE_CP_SYSTEM_TIME_COUNTER3_STC	0
	/* Register Bit Widths for DPE_CP_SYSTEM_TIME_COUNTER3 */
	#define BWID_DPE_CP_SYSTEM_TIME_COUNTER3_STC	32
	/* Register Bit MASKS for DPE_CP_SYSTEM_TIME_COUNTER3 */
	#define BMSK_DPE_CP_SYSTEM_TIME_COUNTER3_STC	0x00000000 /*  */
	/* Register BITFIELD for DPE_CP_SYSTEM_TIME_COUNTER3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_SYSTEM_TIME_COUNTER3_STC	 0x704c, 0, 32, 0x00000000
#define ROFF_DPE_HOST_INTERRUPT_ENABLE	0x7050 /* Interrupt enable register for Host Processor */ 
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE	 0x7050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HOST_INTERRUPT_ENABLE */
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_Vsparc_illegal_event	6
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_Watchdog_timer	5
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_Ext_Event	4
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_DPE_Event	3
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_CP_DMA_done	2
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_HOST_Doorbell_Event	1
	#define BLSB_DPE_HOST_INTERRUPT_ENABLE_CP_Doorbell_Event	0
	/* Register Bit Widths for DPE_HOST_INTERRUPT_ENABLE */
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_Vsparc_illegal_event	1
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_Watchdog_timer	1
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_Ext_Event	1
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_DPE_Event	2
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_CP_DMA_done	1
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_HOST_Doorbell_Event	1
	#define BWID_DPE_HOST_INTERRUPT_ENABLE_CP_Doorbell_Event	1
	/* Register Bit MASKS for DPE_HOST_INTERRUPT_ENABLE */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_Vsparc_illegal_event	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_Watchdog_timer	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_Ext_Event	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_DPE_Event	0x00000018 /*  */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_CP_DMA_done	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_HOST_Doorbell_Event	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_HOST_INTERRUPT_ENABLE_CP_Doorbell_Event	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_HOST_INTERRUPT_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_Vsparc_illegal_event	 0x7050, 6, 1, 0x00000040
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_Watchdog_timer	 0x7050, 5, 1, 0x00000020
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_Ext_Event	 0x7050, 4, 1, 0x00000010
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_DPE_Event	 0x7050, 3, 2, 0x00000018
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_CP_DMA_done	 0x7050, 2, 1, 0x00000004
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_HOST_Doorbell_Event	 0x7050, 1, 1, 0x00000002
	#define BITFIELD_DPE_HOST_INTERRUPT_ENABLE_CP_Doorbell_Event	 0x7050, 0, 1, 0x00000001
#define ROFF_DPE_CP_INTERRUPT_ENABLE	0x7054 /* Interrupt enable register for Control Processor */ 
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE	 0x7054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_INTERRUPT_ENABLE */
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_Vsparc_illegal_event	6
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_Watchdog_timer	5
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_Ext_Event	4
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_DPE_Event	3
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_CP_DMA_done	2
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_HOST_Doorbell_Event	1
	#define BLSB_DPE_CP_INTERRUPT_ENABLE_CP_Doorbell_Event	0
	/* Register Bit Widths for DPE_CP_INTERRUPT_ENABLE */
	#define BWID_DPE_CP_INTERRUPT_ENABLE_Vsparc_illegal_event	1
	#define BWID_DPE_CP_INTERRUPT_ENABLE_Watchdog_timer	1
	#define BWID_DPE_CP_INTERRUPT_ENABLE_Ext_Event	1
	#define BWID_DPE_CP_INTERRUPT_ENABLE_DPE_Event	2
	#define BWID_DPE_CP_INTERRUPT_ENABLE_CP_DMA_done	1
	#define BWID_DPE_CP_INTERRUPT_ENABLE_HOST_Doorbell_Event	1
	#define BWID_DPE_CP_INTERRUPT_ENABLE_CP_Doorbell_Event	1
	/* Register Bit MASKS for DPE_CP_INTERRUPT_ENABLE */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_Vsparc_illegal_event	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_Watchdog_timer	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_Ext_Event	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_DPE_Event	0x00000018 /*  */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_CP_DMA_done	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_HOST_Doorbell_Event	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_CP_INTERRUPT_ENABLE_CP_Doorbell_Event	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_CP_INTERRUPT_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_Vsparc_illegal_event	 0x7054, 6, 1, 0x00000040
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_Watchdog_timer	 0x7054, 5, 1, 0x00000020
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_Ext_Event	 0x7054, 4, 1, 0x00000010
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_DPE_Event	 0x7054, 3, 2, 0x00000018
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_CP_DMA_done	 0x7054, 2, 1, 0x00000004
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_HOST_Doorbell_Event	 0x7054, 1, 1, 0x00000002
	#define BITFIELD_DPE_CP_INTERRUPT_ENABLE_CP_Doorbell_Event	 0x7054, 0, 1, 0x00000001
#define ROFF_DPE_CP_INTERRUPT_STATUS_REGISTER	0x7058 /* Current Interrupt Status  */ 
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER	 0x7058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_CP_INTERRUPT_STATUS_REGISTER */
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_Vsparc_illegal_event	6
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_Watchdog_timer	5
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_Ext_Event	4
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_DPE_Event	3
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_DMA_done	2
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_HOST_Doorbell_Event	1
	#define BLSB_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_Doorbell_Event	0
	/* Register Bit Widths for DPE_CP_INTERRUPT_STATUS_REGISTER */
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_Vsparc_illegal_event	1
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_Watchdog_timer	1
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_Ext_Event	1
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_DPE_Event	2
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_DMA_done	1
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_HOST_Doorbell_Event	1
	#define BWID_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_Doorbell_Event	1
	/* Register Bit MASKS for DPE_CP_INTERRUPT_STATUS_REGISTER */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_Vsparc_illegal_event	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_Watchdog_timer	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_Ext_Event	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_DPE_Event	0x00000018 /*  */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_DMA_done	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_HOST_Doorbell_Event	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_Doorbell_Event	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_CP_INTERRUPT_STATUS_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_Vsparc_illegal_event	 0x7058, 6, 1, 0x00000040
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_Watchdog_timer	 0x7058, 5, 1, 0x00000020
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_Ext_Event	 0x7058, 4, 1, 0x00000010
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_DPE_Event	 0x7058, 3, 2, 0x00000018
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_DMA_done	 0x7058, 2, 1, 0x00000004
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_HOST_Doorbell_Event	 0x7058, 1, 1, 0x00000002
	#define BITFIELD_DPE_CP_INTERRUPT_STATUS_REGISTER_CP_Doorbell_Event	 0x7058, 0, 1, 0x00000001
#define ROFF_DPE_DPE_EVENT_ENABLE_REGISTER	0x7060 /* DPE event interrupt enable register */ 
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER	 0x7060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_EVENT_ENABLE_REGISTER */
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DMA_DONE	23
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DMA_DONE	22
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DMA_DONE	21
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DMA_DONE	20
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DMA_DONE	19
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DMA_DONE	18
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_Y_W_DMA_DONE	17
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_UV_W_DMA_DONE	16
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DMA_DONE	15
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DRTA_DONE	14
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DRTA_DONE	13
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DRTA_DONE	12
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DRTA_DONE	11
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DRTA_DONE	10
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DWTA_DONE	9
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_W_DWTA_DONE	8
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DWTA_DONE	7
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_VS_DONE	6
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_HS_DONE	5
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_DI_DONE	4
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_UV_DONE	3
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_Y_DONE	2
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_422_DONE	1
	#define BLSB_DPE_DPE_EVENT_ENABLE_REGISTER_RNR_DONE	0
	/* Register Bit Widths for DPE_DPE_EVENT_ENABLE_REGISTER */
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_Y_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_UV_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DWTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_W_DWTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DWTA_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_VS_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_HS_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_DI_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_UV_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_Y_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_422_DONE	1
	#define BWID_DPE_DPE_EVENT_ENABLE_REGISTER_RNR_DONE	1
	/* Register Bit MASKS for DPE_DPE_EVENT_ENABLE_REGISTER */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DMA_DONE	(1<<23) /* == 0x00800000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DMA_DONE	(1<<22) /* == 0x00400000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DMA_DONE	(1<<21) /* == 0x00200000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DMA_DONE	(1<<20) /* == 0x00100000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DMA_DONE	(1<<19) /* == 0x00080000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DMA_DONE	(1<<18) /* == 0x00040000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_Y_W_DMA_DONE	(1<<17) /* == 0x00020000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_UV_W_DMA_DONE	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DMA_DONE	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DRTA_DONE	(1<<14) /* == 0x00004000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DRTA_DONE	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DRTA_DONE	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DRTA_DONE	(1<<11) /* == 0x00000800:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DRTA_DONE	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DWTA_DONE	(1<<9) /* == 0x00000200:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_W_DWTA_DONE	(1<<8) /* == 0x00000100:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DWTA_DONE	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_VS_DONE	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_HS_DONE	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_DI_DONE	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_UV_DONE	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_Y_DONE	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_422_DONE	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DPE_EVENT_ENABLE_REGISTER_RNR_DONE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_EVENT_ENABLE_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DMA_DONE	 0x7060, 23, 1, 0x00800000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DMA_DONE	 0x7060, 22, 1, 0x00400000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DMA_DONE	 0x7060, 21, 1, 0x00200000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DMA_DONE	 0x7060, 20, 1, 0x00100000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DMA_DONE	 0x7060, 19, 1, 0x00080000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DMA_DONE	 0x7060, 18, 1, 0x00040000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_Y_W_DMA_DONE	 0x7060, 17, 1, 0x00020000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_UV_W_DMA_DONE	 0x7060, 16, 1, 0x00010000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DMA_DONE	 0x7060, 15, 1, 0x00008000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_Y_R_DRTA_DONE	 0x7060, 14, 1, 0x00004000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_UV_R_DRTA_DONE	 0x7060, 13, 1, 0x00002000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_YUV_R_DRTA_DONE	 0x7060, 12, 1, 0x00001000
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NM1_MH_R_DRTA_DONE	 0x7060, 11, 1, 0x00000800
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_R_DRTA_DONE	 0x7060, 10, 1, 0x00000400
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_NP1_YUV_W_DWTA_DONE	 0x7060, 9, 1, 0x00000200
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_YUV_W_DWTA_DONE	 0x7060, 8, 1, 0x00000100
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_N_MH_W_DWTA_DONE	 0x7060, 7, 1, 0x00000080
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_VS_DONE	 0x7060, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_HS_DONE	 0x7060, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_DI_DONE	 0x7060, 4, 1, 0x00000010
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_UV_DONE	 0x7060, 3, 1, 0x00000008
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_FGT_Y_DONE	 0x7060, 2, 1, 0x00000004
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_422_DONE	 0x7060, 1, 1, 0x00000002
	#define BITFIELD_DPE_DPE_EVENT_ENABLE_REGISTER_RNR_DONE	 0x7060, 0, 1, 0x00000001
#define ROFF_DPE_DPE_EVENT_STATUS_REGISTER	0x7064 /* DPE event status register */ 
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER	 0x7064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_EVENT_STATUS_REGISTER */
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DMA_DONE	23
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DMA_DONE	22
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DMA_DONE	21
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DMA_DONE	20
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DMA_DONE	19
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DMA_DONE	18
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_Y_W_DMA_DONE	17
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_UV_W_DMA_DONE	16
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DMA_DONE	15
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DRTA_DONE	14
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DRTA_DONE	13
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DRTA_DONE	12
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DRTA_DONE	11
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DRTA_DONE	10
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DWTA_DONE	9
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_W_DWTA_DONE	8
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DWTA_DONE	7
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_VS_DONE	6
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_HS_DONE	5
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_DI_DONE	4
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_FGT_UV_DONE	3
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_FGT_Y_DONE	2
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_422_DONE	1
	#define BLSB_DPE_DPE_EVENT_STATUS_REGISTER_RNR_DONE	0
	/* Register Bit Widths for DPE_DPE_EVENT_STATUS_REGISTER */
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_Y_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_UV_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DMA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DRTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DWTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_W_DWTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DWTA_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_VS_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_HS_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_DI_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_FGT_UV_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_FGT_Y_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_422_DONE	1
	#define BWID_DPE_DPE_EVENT_STATUS_REGISTER_RNR_DONE	1
	/* Register Bit MASKS for DPE_DPE_EVENT_STATUS_REGISTER */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DMA_DONE	(1<<23) /* == 0x00800000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DMA_DONE	(1<<22) /* == 0x00400000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DMA_DONE	(1<<21) /* == 0x00200000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DMA_DONE	(1<<20) /* == 0x00100000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DMA_DONE	(1<<19) /* == 0x00080000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DMA_DONE	(1<<18) /* == 0x00040000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_Y_W_DMA_DONE	(1<<17) /* == 0x00020000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_UV_W_DMA_DONE	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DMA_DONE	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DRTA_DONE	(1<<14) /* == 0x00004000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DRTA_DONE	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DRTA_DONE	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DRTA_DONE	(1<<11) /* == 0x00000800:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DRTA_DONE	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DWTA_DONE	(1<<9) /* == 0x00000200:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_W_DWTA_DONE	(1<<8) /* == 0x00000100:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DWTA_DONE	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_VS_DONE	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_HS_DONE	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_DI_DONE	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_FGT_UV_DONE	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_FGT_Y_DONE	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_422_DONE	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DPE_EVENT_STATUS_REGISTER_RNR_DONE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_EVENT_STATUS_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DMA_DONE	 0x7064, 23, 1, 0x00800000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DMA_DONE	 0x7064, 22, 1, 0x00400000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DMA_DONE	 0x7064, 21, 1, 0x00200000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DMA_DONE	 0x7064, 20, 1, 0x00100000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DMA_DONE	 0x7064, 19, 1, 0x00080000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DMA_DONE	 0x7064, 18, 1, 0x00040000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_Y_W_DMA_DONE	 0x7064, 17, 1, 0x00020000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_UV_W_DMA_DONE	 0x7064, 16, 1, 0x00010000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DMA_DONE	 0x7064, 15, 1, 0x00008000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NP1_Y_R_DRTA_DONE	 0x7064, 14, 1, 0x00004000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NP1_UV_R_DRTA_DONE	 0x7064, 13, 1, 0x00002000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NM1_YUV_R_DRTA_DONE	 0x7064, 12, 1, 0x00001000
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NM1_MH_R_DRTA_DONE	 0x7064, 11, 1, 0x00000800
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_R_DRTA_DONE	 0x7064, 10, 1, 0x00000400
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_NP1_YUV_W_DWTA_DONE	 0x7064, 9, 1, 0x00000200
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_YUV_W_DWTA_DONE	 0x7064, 8, 1, 0x00000100
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_N_MH_W_DWTA_DONE	 0x7064, 7, 1, 0x00000080
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_VS_DONE	 0x7064, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_HS_DONE	 0x7064, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_DI_DONE	 0x7064, 4, 1, 0x00000010
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_FGT_UV_DONE	 0x7064, 3, 1, 0x00000008
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_FGT_Y_DONE	 0x7064, 2, 1, 0x00000004
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_422_DONE	 0x7064, 1, 1, 0x00000002
	#define BITFIELD_DPE_DPE_EVENT_STATUS_REGISTER_RNR_DONE	 0x7064, 0, 1, 0x00000001
#define ROFF_DPE_EXT_EVENT_ENABLE_REGISTER	0x7070 /* External event interrupt enable register */ 
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER	 0x7070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_EXT_EVENT_ENABLE_REGISTER */
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_VSparc_Illegal_Access	31
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_Mfd_int	17
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_Gfx_int	16
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_Demux_int	15
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_Prefilter_int	14
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_Comp_int	13
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_Audio_int	12
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Video1_OVRkeepout_p0_5	6
	#define BLSB_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Flip_p0_5	0
	/* Register Bit Widths for DPE_EXT_EVENT_ENABLE_REGISTER */
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_VSparc_Illegal_Access	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_Mfd_int	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_Gfx_int	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_Demux_int	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_Prefilter_int	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_Comp_int	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_Audio_int	1
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Video1_OVRkeepout_p0_5	6
	#define BWID_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Flip_p0_5	6
	/* Register Bit MASKS for DPE_EXT_EVENT_ENABLE_REGISTER */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_VSparc_Illegal_Access	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_Mfd_int	(1<<17) /* == 0x00020000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_Gfx_int	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_Demux_int	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_Prefilter_int	(1<<14) /* == 0x00004000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_Comp_int	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_Audio_int	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Video1_OVRkeepout_p0_5	0x00000fc0 /*  */
	#define BMSK_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Flip_p0_5	0x0000003f /*  */
	/* Register BITFIELD for DPE_EXT_EVENT_ENABLE_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_VSparc_Illegal_Access	 0x7070, 31, 1, 0x80000000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_Mfd_int	 0x7070, 17, 1, 0x00020000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_Gfx_int	 0x7070, 16, 1, 0x00010000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_Demux_int	 0x7070, 15, 1, 0x00008000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_Prefilter_int	 0x7070, 14, 1, 0x00004000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_Comp_int	 0x7070, 13, 1, 0x00002000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_Audio_int	 0x7070, 12, 1, 0x00001000
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Video1_OVRkeepout_p0_5	 0x7070, 6, 6, 0x00000fc0
	#define BITFIELD_DPE_EXT_EVENT_ENABLE_REGISTER_VDC_Flip_p0_5	 0x7070, 0, 6, 0x0000003f
#define ROFF_DPE_EXT_EVENT_STATUS_REGISTER	0x7074 /* External event status register */ 
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER	 0x7074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_EXT_EVENT_STATUS_REGISTER */
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_VSparc_Illegal_Access	31
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_Mfd_int	17
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_Gfx_int	16
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_Demux_int	15
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_Prefilter_int	14
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_Comp_int	13
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_Audio_int	12
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Video1_OVRkeepout_p0_5	6
	#define BLSB_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Flip_p0_5	0
	/* Register Bit Widths for DPE_EXT_EVENT_STATUS_REGISTER */
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_VSparc_Illegal_Access	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_Mfd_int	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_Gfx_int	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_Demux_int	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_Prefilter_int	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_Comp_int	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_Audio_int	1
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Video1_OVRkeepout_p0_5	6
	#define BWID_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Flip_p0_5	6
	/* Register Bit MASKS for DPE_EXT_EVENT_STATUS_REGISTER */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_VSparc_Illegal_Access	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_Mfd_int	(1<<17) /* == 0x00020000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_Gfx_int	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_Demux_int	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_Prefilter_int	(1<<14) /* == 0x00004000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_Comp_int	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_Audio_int	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Video1_OVRkeepout_p0_5	0x00000fc0 /*  */
	#define BMSK_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Flip_p0_5	0x0000003f /*  */
	/* Register BITFIELD for DPE_EXT_EVENT_STATUS_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_VSparc_Illegal_Access	 0x7074, 31, 1, 0x80000000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_Mfd_int	 0x7074, 17, 1, 0x00020000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_Gfx_int	 0x7074, 16, 1, 0x00010000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_Demux_int	 0x7074, 15, 1, 0x00008000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_Prefilter_int	 0x7074, 14, 1, 0x00004000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_Comp_int	 0x7074, 13, 1, 0x00002000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_Audio_int	 0x7074, 12, 1, 0x00001000
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Video1_OVRkeepout_p0_5	 0x7074, 6, 6, 0x00000fc0
	#define BITFIELD_DPE_EXT_EVENT_STATUS_REGISTER_VDC_Flip_p0_5	 0x7074, 0, 6, 0x0000003f
#define ROFF_DPE_DI_Stride_Height_Register	0x1400 /* is used to set up the stride height and number of strides per frame */ 
	#define BITFIELD_DPE_DI_Stride_Height_Register	 0x1400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Stride_Height_Register */
	#define BLSB_DPE_DI_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_DI_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_DI_Stride_Height_Register */
	#define BWID_DPE_DI_Stride_Height_Register_num_strides	4
	#define BWID_DPE_DI_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_DI_Stride_Height_Register */
	#define BMSK_DPE_DI_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DI_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DI_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Stride_Height_Register_num_strides	 0x1400, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DI_Stride_Height_Register_stride_h	 0x1400, 0, 11, 0x000007ff
#define ROFF_DPE_DI_Field_Nplus1_Stride_Width_Register	0x1404 /* set up the per stride input stride width, stride offset and output stride width for Field N+1 */ 
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register	 0x1404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Field_Nplus1_Stride_Width_Register */
	#define BLSB_DPE_DI_Field_Nplus1_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_DI_Field_Nplus1_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_DI_Field_Nplus1_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_DI_Field_Nplus1_Stride_Width_Register_RM	6
	#define BLSB_DPE_DI_Field_Nplus1_Stride_Width_Register_LM	5
	#define BLSB_DPE_DI_Field_Nplus1_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_DI_Field_Nplus1_Stride_Width_Register */
	#define BWID_DPE_DI_Field_Nplus1_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_DI_Field_Nplus1_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_DI_Field_Nplus1_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_DI_Field_Nplus1_Stride_Width_Register_RM	1
	#define BWID_DPE_DI_Field_Nplus1_Stride_Width_Register_LM	1
	#define BWID_DPE_DI_Field_Nplus1_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_DI_Field_Nplus1_Stride_Width_Register */
	#define BMSK_DPE_DI_Field_Nplus1_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DI_Field_Nplus1_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DI_Field_Nplus1_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DI_Field_Nplus1_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Field_Nplus1_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_Field_Nplus1_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_Nplus1_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register_next_rd_offset_x	 0x1404, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register_pix_coord_x	 0x1404, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register_out_stride_w	 0x1404, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register_RM	 0x1404, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register_LM	 0x1404, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Field_Nplus1_Stride_Width_Register_in_stride_off	 0x1404, 0, 5, 0x0000001f
#define ROFF_DPE_DI_Field_N_Stride_Width_Register	0x1408 /* set up the per stride input stride width, stride offset and output stride width for Field N */ 
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register	 0x1408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Field_N_Stride_Width_Register */
	#define BLSB_DPE_DI_Field_N_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_DI_Field_N_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_DI_Field_N_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_DI_Field_N_Stride_Width_Register_RM	6
	#define BLSB_DPE_DI_Field_N_Stride_Width_Register_LM	5
	#define BLSB_DPE_DI_Field_N_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_DI_Field_N_Stride_Width_Register */
	#define BWID_DPE_DI_Field_N_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_DI_Field_N_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_DI_Field_N_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_DI_Field_N_Stride_Width_Register_RM	1
	#define BWID_DPE_DI_Field_N_Stride_Width_Register_LM	1
	#define BWID_DPE_DI_Field_N_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_DI_Field_N_Stride_Width_Register */
	#define BMSK_DPE_DI_Field_N_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DI_Field_N_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DI_Field_N_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DI_Field_N_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Field_N_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_Field_N_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_N_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register_next_rd_offset_x	 0x1408, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register_pix_coord_x	 0x1408, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register_out_stride_w	 0x1408, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register_RM	 0x1408, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register_LM	 0x1408, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Field_N_Stride_Width_Register_in_stride_off	 0x1408, 0, 5, 0x0000001f
#define ROFF_DPE_DI_Field_Nless1_Stride_Width_Register	0x140c /* set up the per stride input stride width, stride offset and output stride width for Field 1 */ 
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register	 0x140c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Field_Nless1_Stride_Width_Register */
	#define BLSB_DPE_DI_Field_Nless1_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_DI_Field_Nless1_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_DI_Field_Nless1_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_DI_Field_Nless1_Stride_Width_Register_RM	6
	#define BLSB_DPE_DI_Field_Nless1_Stride_Width_Register_LM	5
	#define BLSB_DPE_DI_Field_Nless1_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_DI_Field_Nless1_Stride_Width_Register */
	#define BWID_DPE_DI_Field_Nless1_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_DI_Field_Nless1_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_DI_Field_Nless1_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_DI_Field_Nless1_Stride_Width_Register_RM	1
	#define BWID_DPE_DI_Field_Nless1_Stride_Width_Register_LM	1
	#define BWID_DPE_DI_Field_Nless1_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_DI_Field_Nless1_Stride_Width_Register */
	#define BMSK_DPE_DI_Field_Nless1_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DI_Field_Nless1_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DI_Field_Nless1_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DI_Field_Nless1_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Field_Nless1_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_Field_Nless1_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_Nless1_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register_next_rd_offset_x	 0x140c, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register_pix_coord_x	 0x140c, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register_out_stride_w	 0x140c, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register_RM	 0x140c, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register_LM	 0x140c, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Field_Nless1_Stride_Width_Register_in_stride_off	 0x140c, 0, 5, 0x0000001f
#define ROFF_DPE_DI_Field_MH_Stride_Width_Register	0x1410 /* sset up the per stride input stride width, stride offset and output stride width for motion history */ 
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register	 0x1410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Field_MH_Stride_Width_Register */
	#define BLSB_DPE_DI_Field_MH_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_DI_Field_MH_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_DI_Field_MH_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_DI_Field_MH_Stride_Width_Register_RM	6
	#define BLSB_DPE_DI_Field_MH_Stride_Width_Register_LM	5
	#define BLSB_DPE_DI_Field_MH_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_DI_Field_MH_Stride_Width_Register */
	#define BWID_DPE_DI_Field_MH_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_DI_Field_MH_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_DI_Field_MH_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_DI_Field_MH_Stride_Width_Register_RM	1
	#define BWID_DPE_DI_Field_MH_Stride_Width_Register_LM	1
	#define BWID_DPE_DI_Field_MH_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_DI_Field_MH_Stride_Width_Register */
	#define BMSK_DPE_DI_Field_MH_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DI_Field_MH_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DI_Field_MH_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DI_Field_MH_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Field_MH_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_Field_MH_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_MH_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register_next_rd_offset_x	 0x1410, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register_pix_coord_x	 0x1410, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register_out_stride_w	 0x1410, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register_RM	 0x1410, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register_LM	 0x1410, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Field_MH_Stride_Width_Register_in_stride_off	 0x1410, 0, 5, 0x0000001f
#define ROFF_DPE_DI_Field_FMD_Stride_Width_Register	0x1414 /* set up the per stride input stride width, stride offset and output stride width for film mode detection */ 
	#define BITFIELD_DPE_DI_Field_FMD_Stride_Width_Register	 0x1414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Field_FMD_Stride_Width_Register */
	#define BLSB_DPE_DI_Field_FMD_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_DI_Field_FMD_Stride_Width_Register_RM	6
	#define BLSB_DPE_DI_Field_FMD_Stride_Width_Register_LM	5
	#define BLSB_DPE_DI_Field_FMD_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_DI_Field_FMD_Stride_Width_Register */
	#define BWID_DPE_DI_Field_FMD_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_DI_Field_FMD_Stride_Width_Register_RM	1
	#define BWID_DPE_DI_Field_FMD_Stride_Width_Register_LM	1
	#define BWID_DPE_DI_Field_FMD_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_DI_Field_FMD_Stride_Width_Register */
	#define BMSK_DPE_DI_Field_FMD_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DI_Field_FMD_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Field_FMD_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_Field_FMD_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_FMD_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_FMD_Stride_Width_Register_out_stride_w	 0x1414, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DI_Field_FMD_Stride_Width_Register_RM	 0x1414, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Field_FMD_Stride_Width_Register_LM	 0x1414, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Field_FMD_Stride_Width_Register_in_stride_off	 0x1414, 0, 5, 0x0000001f
#define ROFF_DPE_DI_Field_N_Next_Block_Parameters_Register	0x1418 /* used to set up the next block parameters */ 
	#define BITFIELD_DPE_DI_Field_N_Next_Block_Parameters_Register	 0x1418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Field_N_Next_Block_Parameters_Register */
	#define BLSB_DPE_DI_Field_N_Next_Block_Parameters_Register_next_rd_offset_y	8
	#define BLSB_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	0
	/* Register Bit Widths for DPE_DI_Field_N_Next_Block_Parameters_Register */
	#define BWID_DPE_DI_Field_N_Next_Block_Parameters_Register_next_rd_offset_y	5
	#define BWID_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	5
	/* Register Bit MASKS for DPE_DI_Field_N_Next_Block_Parameters_Register */
	#define BMSK_DPE_DI_Field_N_Next_Block_Parameters_Register_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_N_Next_Block_Parameters_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_N_Next_Block_Parameters_Register_next_rd_offset_y	 0x1418, 8, 5, 0x00001f00
	#define BITFIELD_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	 0x1418, 0, 5, 0x0000001f
#define ROFF_DPE_DI_Control_Register	0x1420 /* control register */ 
	#define BITFIELD_DPE_DI_Control_Register	 0x1420, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Control_Register */
	#define BLSB_DPE_DI_Control_Register_Black_spatial	31
	#define BLSB_DPE_DI_Control_Register_SDI_stride_mode	30
	#define BLSB_DPE_DI_Control_Register_Mh_disable	29
	#define BLSB_DPE_DI_Control_Register_Const_md	28
	#define BLSB_DPE_DI_Control_Register_Const_md_value	27
	#define BLSB_DPE_DI_Control_Register_Chkn_mdaf	26
	#define BLSB_DPE_DI_Control_Register_Chkn_mdaf_conservative_chk	25
	#define BLSB_DPE_DI_Control_Register_Chkn_weight_fix	24
	#define BLSB_DPE_DI_Control_Register_Chkn_mdaf_check_md	23
	#define BLSB_DPE_DI_Control_Register_enable_1x2_MH_write	14
	#define BLSB_DPE_DI_Control_Register_MADI_select	13
	#define BLSB_DPE_DI_Control_Register_Motion_histogram_win_en	12
	#define BLSB_DPE_DI_Control_Register_Swap23_mode	10
	#define BLSB_DPE_DI_Control_Register_FilmMode_1_0	8
	#define BLSB_DPE_DI_Control_Register_CONST_HISTORY	7
	#define BLSB_DPE_DI_Control_Register_Software_Frame_Start	6
	#define BLSB_DPE_DI_Control_Register_BYPASS_motion_decision_TNRF	5
	#define BLSB_DPE_DI_Control_Register_BYPASSNRF	4
	#define BLSB_DPE_DI_Control_Register_TOP_FIELD	3
	#define BLSB_DPE_DI_Control_Register_SPATIAL	2
	#define BLSB_DPE_DI_Control_Register_Progressive	1
	#define BLSB_DPE_DI_Control_Register_Bypass	0
	/* Register Bit Widths for DPE_DI_Control_Register */
	#define BWID_DPE_DI_Control_Register_Black_spatial	1
	#define BWID_DPE_DI_Control_Register_SDI_stride_mode	1
	#define BWID_DPE_DI_Control_Register_Mh_disable	1
	#define BWID_DPE_DI_Control_Register_Const_md	1
	#define BWID_DPE_DI_Control_Register_Const_md_value	1
	#define BWID_DPE_DI_Control_Register_Chkn_mdaf	1
	#define BWID_DPE_DI_Control_Register_Chkn_mdaf_conservative_chk	1
	#define BWID_DPE_DI_Control_Register_Chkn_weight_fix	1
	#define BWID_DPE_DI_Control_Register_Chkn_mdaf_check_md	1
	#define BWID_DPE_DI_Control_Register_enable_1x2_MH_write	1
	#define BWID_DPE_DI_Control_Register_MADI_select	1
	#define BWID_DPE_DI_Control_Register_Motion_histogram_win_en	1
	#define BWID_DPE_DI_Control_Register_Swap23_mode	1
	#define BWID_DPE_DI_Control_Register_FilmMode_1_0	2
	#define BWID_DPE_DI_Control_Register_CONST_HISTORY	1
	#define BWID_DPE_DI_Control_Register_Software_Frame_Start	1
	#define BWID_DPE_DI_Control_Register_BYPASS_motion_decision_TNRF	1
	#define BWID_DPE_DI_Control_Register_BYPASSNRF	1
	#define BWID_DPE_DI_Control_Register_TOP_FIELD	1
	#define BWID_DPE_DI_Control_Register_SPATIAL	1
	#define BWID_DPE_DI_Control_Register_Progressive	1
	#define BWID_DPE_DI_Control_Register_Bypass	1
	/* Register Bit MASKS for DPE_DI_Control_Register */
	#define BMSK_DPE_DI_Control_Register_Black_spatial	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_DI_Control_Register_SDI_stride_mode	(1<<30) /* == 0x40000000:  */
	#define BMSK_DPE_DI_Control_Register_Mh_disable	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DI_Control_Register_Const_md	(1<<28) /* == 0x10000000:  */
	#define BMSK_DPE_DI_Control_Register_Const_md_value	(1<<27) /* == 0x08000000:  */
	#define BMSK_DPE_DI_Control_Register_Chkn_mdaf	(1<<26) /* == 0x04000000:  */
	#define BMSK_DPE_DI_Control_Register_Chkn_mdaf_conservative_chk	(1<<25) /* == 0x02000000:  */
	#define BMSK_DPE_DI_Control_Register_Chkn_weight_fix	(1<<24) /* == 0x01000000:  */
	#define BMSK_DPE_DI_Control_Register_Chkn_mdaf_check_md	(1<<23) /* == 0x00800000:  */
	#define BMSK_DPE_DI_Control_Register_enable_1x2_MH_write	(1<<14) /* == 0x00004000:  */
	#define BMSK_DPE_DI_Control_Register_MADI_select	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_DI_Control_Register_Motion_histogram_win_en	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_DI_Control_Register_Swap23_mode	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_DI_Control_Register_FilmMode_1_0	0x00000300 /*  */
	#define BMSK_DPE_DI_Control_Register_CONST_HISTORY	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_DI_Control_Register_Software_Frame_Start	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Control_Register_BYPASS_motion_decision_TNRF	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_Control_Register_BYPASSNRF	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DI_Control_Register_TOP_FIELD	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DI_Control_Register_SPATIAL	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DI_Control_Register_Progressive	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DI_Control_Register_Bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DI_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Control_Register_Black_spatial	 0x1420, 31, 1, 0x80000000
	#define BITFIELD_DPE_DI_Control_Register_SDI_stride_mode	 0x1420, 30, 1, 0x40000000
	#define BITFIELD_DPE_DI_Control_Register_Mh_disable	 0x1420, 29, 1, 0x20000000
	#define BITFIELD_DPE_DI_Control_Register_Const_md	 0x1420, 28, 1, 0x10000000
	#define BITFIELD_DPE_DI_Control_Register_Const_md_value	 0x1420, 27, 1, 0x08000000
	#define BITFIELD_DPE_DI_Control_Register_Chkn_mdaf	 0x1420, 26, 1, 0x04000000
	#define BITFIELD_DPE_DI_Control_Register_Chkn_mdaf_conservative_chk	 0x1420, 25, 1, 0x02000000
	#define BITFIELD_DPE_DI_Control_Register_Chkn_weight_fix	 0x1420, 24, 1, 0x01000000
	#define BITFIELD_DPE_DI_Control_Register_Chkn_mdaf_check_md	 0x1420, 23, 1, 0x00800000
	#define BITFIELD_DPE_DI_Control_Register_enable_1x2_MH_write	 0x1420, 14, 1, 0x00004000
	#define BITFIELD_DPE_DI_Control_Register_MADI_select	 0x1420, 13, 1, 0x00002000
	#define BITFIELD_DPE_DI_Control_Register_Motion_histogram_win_en	 0x1420, 12, 1, 0x00001000
	#define BITFIELD_DPE_DI_Control_Register_Swap23_mode	 0x1420, 10, 1, 0x00000400
	#define BITFIELD_DPE_DI_Control_Register_FilmMode_1_0	 0x1420, 8, 2, 0x00000300
	#define BITFIELD_DPE_DI_Control_Register_CONST_HISTORY	 0x1420, 7, 1, 0x00000080
	#define BITFIELD_DPE_DI_Control_Register_Software_Frame_Start	 0x1420, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Control_Register_BYPASS_motion_decision_TNRF	 0x1420, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Control_Register_BYPASSNRF	 0x1420, 4, 1, 0x00000010
	#define BITFIELD_DPE_DI_Control_Register_TOP_FIELD	 0x1420, 3, 1, 0x00000008
	#define BITFIELD_DPE_DI_Control_Register_SPATIAL	 0x1420, 2, 1, 0x00000004
	#define BITFIELD_DPE_DI_Control_Register_Progressive	 0x1420, 1, 1, 0x00000002
	#define BITFIELD_DPE_DI_Control_Register_Bypass	 0x1420, 0, 1, 0x00000001
#define ROFF_DPE_DI_Status_Register	0x1424 /* status register */ 
	#define BITFIELD_DPE_DI_Status_Register	 0x1424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_DI_SDI_SAD_Wt_0_3_Register	0x1428 /* DI_SDI_SAD_Wt_0_3_Register */ 
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_0_3_Register	 0x1428, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_SDI_SAD_Wt_0_3_Register */
	#define BLSB_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_3	24
	#define BLSB_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_2	16
	#define BLSB_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_1	8
	#define BLSB_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_0	0
	/* Register Bit Widths for DPE_DI_SDI_SAD_Wt_0_3_Register */
	#define BWID_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_3	8
	#define BWID_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_2	8
	#define BWID_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_1	8
	#define BWID_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_0	8
	/* Register Bit MASKS for DPE_DI_SDI_SAD_Wt_0_3_Register */
	#define BMSK_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_3	0xff000000 /*  */
	#define BMSK_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_SDI_SAD_Wt_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_3	 0x1428, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_2	 0x1428, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_1	 0x1428, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_0_3_Register_SDI_SAD_Wt_0	 0x1428, 0, 8, 0x000000ff
#define ROFF_DPE_DI_SDI_SAD_Wt_4_5_Register	0x142c /* DI_SDI_SAD_Wt_4_5_Register */ 
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_4_5_Register	 0x142c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_SDI_SAD_Wt_4_5_Register */
	#define BLSB_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_directional_mean_flag	16
	#define BLSB_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_5	8
	#define BLSB_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_4	0
	/* Register Bit Widths for DPE_DI_SDI_SAD_Wt_4_5_Register */
	#define BWID_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_directional_mean_flag	1
	#define BWID_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_5	8
	#define BWID_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_4	8
	/* Register Bit MASKS for DPE_DI_SDI_SAD_Wt_4_5_Register */
	#define BMSK_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_directional_mean_flag	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_SDI_SAD_Wt_4_5_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_directional_mean_flag	 0x142c, 16, 1, 0x00010000
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_5	 0x142c, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_SDI_SAD_Wt_4_5_Register_SDI_SAD_Wt_4	 0x142c, 0, 8, 0x000000ff
#define ROFF_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register	0x1430 /* DI_Motion_Detect_SAD_Threshold_Parameter_Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register	 0x1430, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register */
	#define BLSB_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE2	28
	#define BLSB_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE1	24
	#define BLSB_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_MAX_NOISE_LEVEL	16
	#define BLSB_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_POST	12
	#define BLSB_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_START_VALUE	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register */
	#define BWID_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE2	3
	#define BWID_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE1	3
	#define BWID_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_MAX_NOISE_LEVEL	8
	#define BWID_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_POST	3
	#define BWID_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_START_VALUE	10
	/* Register Bit MASKS for DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register */
	#define BMSK_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE2	0x70000000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE1	0x07000000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_MAX_NOISE_LEVEL	0x00ff0000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_POST	0x00007000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_START_VALUE	0x000003ff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE2	 0x1430, 28, 3, 0x70000000
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_PRE1	 0x1430, 24, 3, 0x07000000
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_MAX_NOISE_LEVEL	 0x1430, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_WEIGHT_POST	 0x1430, 12, 3, 0x00007000
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_Threshold_Parameter_Register_SAD_START_VALUE	 0x1430, 0, 10, 0x000003ff
#define ROFF_DPE_DI_Motion_Detect_MAD_History_Parameter_Register	0x1434 /* DI_Motion_Detect_MAD_Hsitory_Parameter_Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_MAD_History_Parameter_Register	 0x1434, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_MAD_History_Parameter_Register */
	#define BLSB_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_HISTORY_VALUE	16
	#define BLSB_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_CAP	8
	#define BLSB_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_MIN	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_MAD_History_Parameter_Register */
	#define BWID_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_HISTORY_VALUE	6
	#define BWID_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_CAP	8
	#define BWID_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_MIN	8
	/* Register Bit MASKS for DPE_DI_Motion_Detect_MAD_History_Parameter_Register */
	#define BMSK_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_HISTORY_VALUE	0x003f0000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_CAP	0x0000ff00 /*  */
	#define BMSK_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_MIN	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_MAD_History_Parameter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_HISTORY_VALUE	 0x1434, 16, 6, 0x003f0000
	#define BITFIELD_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_CAP	 0x1434, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_Motion_Detect_MAD_History_Parameter_Register_MAD_MIN	 0x1434, 0, 8, 0x000000ff
#define ROFF_DPE_DI_Motion_Detect_SAD_History_Parameter_Register	0x1438 /* DI_Motion_Detect_SAD_Hsitory_Parameter_Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_History_Parameter_Register	 0x1438, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_SAD_History_Parameter_Register */
	#define BLSB_DPE_DI_Motion_Detect_SAD_History_Parameter_Register_SAD_HISTORY_VALUE	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_SAD_History_Parameter_Register */
	#define BWID_DPE_DI_Motion_Detect_SAD_History_Parameter_Register_SAD_HISTORY_VALUE	10
	/* Register Bit MASKS for DPE_DI_Motion_Detect_SAD_History_Parameter_Register */
	#define BMSK_DPE_DI_Motion_Detect_SAD_History_Parameter_Register_SAD_HISTORY_VALUE	0x000003ff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_SAD_History_Parameter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_SAD_History_Parameter_Register_SAD_HISTORY_VALUE	 0x1438, 0, 10, 0x000003ff
#define ROFF_DPE_DI_Motion_Detect_Noise_Range_Register	0x143c /* DI_Motion_Detect Noise Range Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Range_Register	 0x143c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Noise_Range_Register */
	#define BLSB_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MAX	24
	#define BLSB_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MIN	16
	#define BLSB_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MAX	8
	#define BLSB_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MIN	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Noise_Range_Register */
	#define BWID_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MAX	8
	#define BWID_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MIN	8
	#define BWID_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MAX	8
	#define BWID_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MIN	8
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Noise_Range_Register */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MAX	0xff000000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MIN	0x00ff0000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MAX	0x0000ff00 /*  */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MIN	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Noise_Range_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MAX	 0x143c, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG2_MIN	 0x143c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MAX	 0x143c, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Range_Register_NOISE_RNG1_MIN	 0x143c, 0, 8, 0x000000ff
#define ROFF_DPE_DI_Motion_Detect_Noise_Level_Register	0x1440 /* DI_Motion_Detect Noise level Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Level_Register	 0x1440, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Noise_Level_Register */
	#define BLSB_DPE_DI_Motion_Detect_Noise_Level_Register_Noiselvl	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Noise_Level_Register */
	#define BWID_DPE_DI_Motion_Detect_Noise_Level_Register_Noiselvl	30
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Noise_Level_Register */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Level_Register_Noiselvl	0x3fffffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Noise_Level_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Level_Register_Noiselvl	 0x1440, 0, 30, 0x3fffffff
#define ROFF_DPE_DI_Motion_Detect_Noise_Pixel_Count_Register	0x1444 /* DI_Motion_Detect Noise pixel count Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Pixel_Count_Register	 0x1444, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Noise_Pixel_Count_Register */
	#define BLSB_DPE_DI_Motion_Detect_Noise_Pixel_Count_Register_Noisepixcnt	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Noise_Pixel_Count_Register */
	#define BWID_DPE_DI_Motion_Detect_Noise_Pixel_Count_Register_Noisepixcnt	22
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Noise_Pixel_Count_Register */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Pixel_Count_Register_Noisepixcnt	0x003fffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Noise_Pixel_Count_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Pixel_Count_Register_Noisepixcnt	 0x1444, 0, 22, 0x003fffff
#define ROFF_DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register	0x1448 /* DI_Motion_Detect Noise pixel count2 Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register	 0x1448, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register */
	#define BLSB_DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register_Noisepixcnt2	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register */
	#define BWID_DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register_Noisepixcnt2	22
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register */
	#define BMSK_DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register_Noisepixcnt2	0x003fffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Noise_Pixel_Count2_Register_Noisepixcnt2	 0x1448, 0, 22, 0x003fffff
#define ROFF_DPE_DI_Motion_Detect_Threshold_Register	0x144c /* DI_Motion_Detect threshold Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Threshold_Register	 0x144c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Threshold_Register */
	#define BLSB_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_PRE	28
	#define BLSB_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_POST	24
	#define BLSB_DPE_DI_Motion_Detect_Threshold_Register_thdm	16
	#define BLSB_DPE_DI_Motion_Detect_Threshold_Register_Ln	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Threshold_Register */
	#define BWID_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_PRE	3
	#define BWID_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_POST	3
	#define BWID_DPE_DI_Motion_Detect_Threshold_Register_thdm	6
	#define BWID_DPE_DI_Motion_Detect_Threshold_Register_Ln	12
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Threshold_Register */
	#define BMSK_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_PRE	0x70000000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_POST	0x07000000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_Threshold_Register_thdm	0x003f0000 /*  */
	#define BMSK_DPE_DI_Motion_Detect_Threshold_Register_Ln	0x00000fff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Threshold_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_PRE	 0x144c, 28, 3, 0x70000000
	#define BITFIELD_DPE_DI_Motion_Detect_Threshold_Register_MAD_WEIGHT_POST	 0x144c, 24, 3, 0x07000000
	#define BITFIELD_DPE_DI_Motion_Detect_Threshold_Register_thdm	 0x144c, 16, 6, 0x003f0000
	#define BITFIELD_DPE_DI_Motion_Detect_Threshold_Register_Ln	 0x144c, 0, 12, 0x00000fff
#define ROFF_DPE_DI_NRF_Index_Shift_Registers	0x1450 /* DI_NRF_Index_Shift_Registers */ 
	#define BITFIELD_DPE_DI_NRF_Index_Shift_Registers	 0x1450, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_NRF_Index_Shift_Registers */
	#define BLSB_DPE_DI_NRF_Index_Shift_Registers_SWSHIFT	2
	#define BLSB_DPE_DI_NRF_Index_Shift_Registers_TWSHIFT	0
	/* Register Bit Widths for DPE_DI_NRF_Index_Shift_Registers */
	#define BWID_DPE_DI_NRF_Index_Shift_Registers_SWSHIFT	2
	#define BWID_DPE_DI_NRF_Index_Shift_Registers_TWSHIFT	2
	/* Register Bit MASKS for DPE_DI_NRF_Index_Shift_Registers */
	#define BMSK_DPE_DI_NRF_Index_Shift_Registers_SWSHIFT	0x0000000c /*  */
	#define BMSK_DPE_DI_NRF_Index_Shift_Registers_TWSHIFT	0x00000003 /*  */
	/* Register BITFIELD for DPE_DI_NRF_Index_Shift_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_NRF_Index_Shift_Registers_SWSHIFT	 0x1450, 2, 2, 0x0000000c
	#define BITFIELD_DPE_DI_NRF_Index_Shift_Registers_TWSHIFT	 0x1450, 0, 2, 0x00000003
#define ROFF_DPE_DI_Motion_Detect_Static_Noise_Level_Register	0x145c /* DI_Motion_Detect Static Noise level Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Static_Noise_Level_Register	 0x145c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Static_Noise_Level_Register */
	#define BLSB_DPE_DI_Motion_Detect_Static_Noise_Level_Register_Noiselvl	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Static_Noise_Level_Register */
	#define BWID_DPE_DI_Motion_Detect_Static_Noise_Level_Register_Noiselvl	30
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Static_Noise_Level_Register */
	#define BMSK_DPE_DI_Motion_Detect_Static_Noise_Level_Register_Noiselvl	0x3fffffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Static_Noise_Level_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Static_Noise_Level_Register_Noiselvl	 0x145c, 0, 30, 0x3fffffff
#define ROFF_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register	0x1460 /* DI_Motion_Detect Static Noise pixel count Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register	 0x1460, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register */
	#define BLSB_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register_Noisepixcnt	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register */
	#define BWID_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register_Noisepixcnt	22
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register */
	#define BMSK_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register_Noisepixcnt	0x003fffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count_Register_Noisepixcnt	 0x1460, 0, 22, 0x003fffff
#define ROFF_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register	0x1464 /* DI_Motion_Detect Static Noise pixel count2 Register */ 
	#define BITFIELD_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register	 0x1464, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register */
	#define BLSB_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register_Noisepixcnt2	0
	/* Register Bit Widths for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register */
	#define BWID_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register_Noisepixcnt2	22
	/* Register Bit MASKS for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register */
	#define BMSK_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register_Noisepixcnt2	0x003fffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Detect_Static_Noise_Pixel_Count2_Register_Noisepixcnt2	 0x1464, 0, 22, 0x003fffff
#define ROFF_DPE_DI_FMD_TC_prev_count_Registers	0x146c /* DI_FMD_TC_prev_count_Registers */ 
	#define BITFIELD_DPE_DI_FMD_TC_prev_count_Registers	 0x146c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_FMD_TC_prev_count_Registers */
	#define BLSB_DPE_DI_FMD_TC_prev_count_Registers_TCP_COUNTER	0
	/* Register Bit Widths for DPE_DI_FMD_TC_prev_count_Registers */
	#define BWID_DPE_DI_FMD_TC_prev_count_Registers_TCP_COUNTER	20
	/* Register Bit MASKS for DPE_DI_FMD_TC_prev_count_Registers */
	#define BMSK_DPE_DI_FMD_TC_prev_count_Registers_TCP_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_FMD_TC_prev_count_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_FMD_TC_prev_count_Registers_TCP_COUNTER	 0x146c, 0, 20, 0x000fffff
#define ROFF_DPE_DI_FMD_TC_next_count_Registers	0x1470 /* DI_FMD_TC_next_count_Registers */ 
	#define BITFIELD_DPE_DI_FMD_TC_next_count_Registers	 0x1470, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_FMD_TC_next_count_Registers */
	#define BLSB_DPE_DI_FMD_TC_next_count_Registers_TCN_COUNTER	0
	/* Register Bit Widths for DPE_DI_FMD_TC_next_count_Registers */
	#define BWID_DPE_DI_FMD_TC_next_count_Registers_TCN_COUNTER	20
	/* Register Bit MASKS for DPE_DI_FMD_TC_next_count_Registers */
	#define BMSK_DPE_DI_FMD_TC_next_count_Registers_TCN_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_FMD_TC_next_count_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_FMD_TC_next_count_Registers_TCN_COUNTER	 0x1470, 0, 20, 0x000fffff
#define ROFF_DPE_DI_FMD_FDC_Registers	0x1474 /* DI_FMD_FDC_Registers */ 
	#define BITFIELD_DPE_DI_FMD_FDC_Registers	 0x1474, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_FMD_FDC_Registers */
	#define BLSB_DPE_DI_FMD_FDC_Registers_FD_COUNTER	0
	/* Register Bit Widths for DPE_DI_FMD_FDC_Registers */
	#define BWID_DPE_DI_FMD_FDC_Registers_FD_COUNTER	20
	/* Register Bit MASKS for DPE_DI_FMD_FDC_Registers */
	#define BMSK_DPE_DI_FMD_FDC_Registers_FD_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_FMD_FDC_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_FMD_FDC_Registers_FD_COUNTER	 0x1474, 0, 20, 0x000fffff
#define ROFF_DPE_DI_FMD_Th_Registers	0x1478 /* DI_FMD_Th_Registers */ 
	#define BITFIELD_DPE_DI_FMD_Th_Registers	 0x1478, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_FMD_Th_Registers */
	#define BLSB_DPE_DI_FMD_Th_Registers_DIFF_TH	16
	#define BLSB_DPE_DI_FMD_Th_Registers_DIFF_TC_TH	8
	#define BLSB_DPE_DI_FMD_Th_Registers_TC_TH	0
	/* Register Bit Widths for DPE_DI_FMD_Th_Registers */
	#define BWID_DPE_DI_FMD_Th_Registers_DIFF_TH	8
	#define BWID_DPE_DI_FMD_Th_Registers_DIFF_TC_TH	8
	#define BWID_DPE_DI_FMD_Th_Registers_TC_TH	8
	/* Register Bit MASKS for DPE_DI_FMD_Th_Registers */
	#define BMSK_DPE_DI_FMD_Th_Registers_DIFF_TH	0x00ff0000 /*  */
	#define BMSK_DPE_DI_FMD_Th_Registers_DIFF_TC_TH	0x0000ff00 /*  */
	#define BMSK_DPE_DI_FMD_Th_Registers_TC_TH	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_FMD_Th_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_FMD_Th_Registers_DIFF_TH	 0x1478, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_FMD_Th_Registers_DIFF_TC_TH	 0x1478, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_FMD_Th_Registers_TC_TH	 0x1478, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TC_prev_Hist_0_Registers	0x147c /* DI_TC_prev_Hist_0_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_0_Registers	 0x147c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_0_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_0_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_0_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_0_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_0_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_0_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_0_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_0_Registers_TCP_HIST_CNTR	 0x147c, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_1_Registers	0x1480 /* DI_TC_prev_Hist_1_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_1_Registers	 0x1480, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_1_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_1_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_1_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_1_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_1_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_1_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_1_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_1_Registers_TCP_HIST_CNTR	 0x1480, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_2_Registers	0x1484 /* DI_TC_prev_Hist_2_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_2_Registers	 0x1484, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_2_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_2_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_2_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_2_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_2_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_2_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_2_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_2_Registers_TCP_HIST_CNTR	 0x1484, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_3_Registers	0x1488 /* DI_TC_prev_Hist_3_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_3_Registers	 0x1488, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_3_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_3_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_3_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_3_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_3_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_3_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_3_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_3_Registers_TCP_HIST_CNTR	 0x1488, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_4_Registers	0x148c /* DI_TC_prev_Hist_4_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_4_Registers	 0x148c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_4_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_4_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_4_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_4_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_4_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_4_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_4_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_4_Registers_TCP_HIST_CNTR	 0x148c, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_5_Registers	0x1490 /* DI_TC_prev_Hist_5_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_5_Registers	 0x1490, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_5_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_5_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_5_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_5_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_5_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_5_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_5_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_5_Registers_TCP_HIST_CNTR	 0x1490, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_6_Registers	0x1494 /* DI_TC_prev_Hist_6_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_6_Registers	 0x1494, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_6_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_6_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_6_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_6_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_6_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_6_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_6_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_6_Registers_TCP_HIST_CNTR	 0x1494, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_prev_Hist_7_Registers	0x1498 /* DI_TC_prev_Hist_7_Registers */ 
	#define BITFIELD_DPE_DI_TC_prev_Hist_7_Registers	 0x1498, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_prev_Hist_7_Registers */
	#define BLSB_DPE_DI_TC_prev_Hist_7_Registers_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_prev_Hist_7_Registers */
	#define BWID_DPE_DI_TC_prev_Hist_7_Registers_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_prev_Hist_7_Registers */
	#define BMSK_DPE_DI_TC_prev_Hist_7_Registers_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_prev_Hist_7_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_prev_Hist_7_Registers_TCP_HIST_CNTR	 0x1498, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_0_Registers	0x149c /* DI_TC_next_Hist_0_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_0_Registers	 0x149c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_0_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_0_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_0_Registers */
	#define BWID_DPE_DI_TC_next_Hist_0_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_0_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_0_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_0_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_0_Registers_TCN_HIST_CNTR	 0x149c, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_1_Registers	0x14a0 /* DI_TC_next_Hist_1_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_1_Registers	 0x14a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_1_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_1_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_1_Registers */
	#define BWID_DPE_DI_TC_next_Hist_1_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_1_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_1_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_1_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_1_Registers_TCN_HIST_CNTR	 0x14a0, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_2_Registers	0x14a4 /* DI_TC_next_Hist_2_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_2_Registers	 0x14a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_2_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_2_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_2_Registers */
	#define BWID_DPE_DI_TC_next_Hist_2_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_2_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_2_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_2_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_2_Registers_TCN_HIST_CNTR	 0x14a4, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_3_Registers	0x14a8 /* DI_TC_next_Hist_3_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_3_Registers	 0x14a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_3_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_3_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_3_Registers */
	#define BWID_DPE_DI_TC_next_Hist_3_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_3_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_3_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_3_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_3_Registers_TCN_HIST_CNTR	 0x14a8, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_4_Registers	0x14ac /* DI_TC_next_Hist_4_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_4_Registers	 0x14ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_4_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_4_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_4_Registers */
	#define BWID_DPE_DI_TC_next_Hist_4_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_4_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_4_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_4_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_4_Registers_TCN_HIST_CNTR	 0x14ac, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_5_Registers	0x14b0 /* DI_TC_next_Hist_5_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_5_Registers	 0x14b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_5_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_5_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_5_Registers */
	#define BWID_DPE_DI_TC_next_Hist_5_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_5_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_5_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_5_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_5_Registers_TCN_HIST_CNTR	 0x14b0, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_6_Registers	0x14b4 /* DI_TC_next_Hist_6_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_6_Registers	 0x14b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_6_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_6_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_6_Registers */
	#define BWID_DPE_DI_TC_next_Hist_6_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_6_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_6_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_6_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_6_Registers_TCN_HIST_CNTR	 0x14b4, 0, 32, 0x00000000
#define ROFF_DPE_DI_TC_next_Hist_7_Registers	0x14b8 /* DI_TC_next_Hist_7_Registers */ 
	#define BITFIELD_DPE_DI_TC_next_Hist_7_Registers	 0x14b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TC_next_Hist_7_Registers */
	#define BLSB_DPE_DI_TC_next_Hist_7_Registers_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_TC_next_Hist_7_Registers */
	#define BWID_DPE_DI_TC_next_Hist_7_Registers_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_TC_next_Hist_7_Registers */
	#define BMSK_DPE_DI_TC_next_Hist_7_Registers_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_TC_next_Hist_7_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TC_next_Hist_7_Registers_TCN_HIST_CNTR	 0x14b8, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_Hist_Th_Registers	0x14c0 /* DI_Motion_Hist_Th_Registers */ 
	#define BITFIELD_DPE_DI_Motion_Hist_Th_Registers	 0x14c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Hist_Th_Registers */
	#define BLSB_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH4	24
	#define BLSB_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH3	16
	#define BLSB_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH2	8
	#define BLSB_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH1	0
	/* Register Bit Widths for DPE_DI_Motion_Hist_Th_Registers */
	#define BWID_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH4	8
	#define BWID_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH3	8
	#define BWID_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH2	8
	#define BWID_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH1	8
	/* Register Bit MASKS for DPE_DI_Motion_Hist_Th_Registers */
	#define BMSK_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH4	0xff000000 /*  */
	#define BMSK_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH3	0x00ff0000 /*  */
	#define BMSK_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH2	0x0000ff00 /*  */
	#define BMSK_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH1	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Hist_Th_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH4	 0x14c0, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH3	 0x14c0, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH2	 0x14c0, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_Motion_Hist_Th_Registers_MOTION_AB_TH1	 0x14c0, 0, 8, 0x000000ff
#define ROFF_DPE_DI_Motion_A_Hist_Counter_0_Registers	0x14c4 /* DI_Motion_A_Hist_Counter_0_Registers */ 
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_0_Registers	 0x14c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_A_Hist_Counter_0_Registers */
	#define BLSB_DPE_DI_Motion_A_Hist_Counter_0_Registers_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_A_Hist_Counter_0_Registers */
	#define BWID_DPE_DI_Motion_A_Hist_Counter_0_Registers_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_A_Hist_Counter_0_Registers */
	#define BMSK_DPE_DI_Motion_A_Hist_Counter_0_Registers_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_A_Hist_Counter_0_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_0_Registers_MOTION_A_HIST_CNTR	 0x14c4, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_A_Hist_Counter_1_Registers	0x14c8 /* DI_Motion_A_Hist_Counter_1_Registers */ 
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_1_Registers	 0x14c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_A_Hist_Counter_1_Registers */
	#define BLSB_DPE_DI_Motion_A_Hist_Counter_1_Registers_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_A_Hist_Counter_1_Registers */
	#define BWID_DPE_DI_Motion_A_Hist_Counter_1_Registers_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_A_Hist_Counter_1_Registers */
	#define BMSK_DPE_DI_Motion_A_Hist_Counter_1_Registers_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_A_Hist_Counter_1_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_1_Registers_MOTION_A_HIST_CNTR	 0x14c8, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_A_Hist_Counter_2_Registers	0x14cc /* DI_Motion_A_Hist_Counter_2_Registers */ 
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_2_Registers	 0x14cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_A_Hist_Counter_2_Registers */
	#define BLSB_DPE_DI_Motion_A_Hist_Counter_2_Registers_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_A_Hist_Counter_2_Registers */
	#define BWID_DPE_DI_Motion_A_Hist_Counter_2_Registers_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_A_Hist_Counter_2_Registers */
	#define BMSK_DPE_DI_Motion_A_Hist_Counter_2_Registers_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_A_Hist_Counter_2_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_2_Registers_MOTION_A_HIST_CNTR	 0x14cc, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_A_Hist_Counter_3_Registers	0x14d0 /* DI_Motion_A_Hist_Counter_3_Registers */ 
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_3_Registers	 0x14d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_A_Hist_Counter_3_Registers */
	#define BLSB_DPE_DI_Motion_A_Hist_Counter_3_Registers_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_A_Hist_Counter_3_Registers */
	#define BWID_DPE_DI_Motion_A_Hist_Counter_3_Registers_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_A_Hist_Counter_3_Registers */
	#define BMSK_DPE_DI_Motion_A_Hist_Counter_3_Registers_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_A_Hist_Counter_3_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_A_Hist_Counter_3_Registers_MOTION_A_HIST_CNTR	 0x14d0, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_B_Hist_Counter_0_Registers	0x14d4 /* DI_Motion_B_Hist_Counter_0_Registers */ 
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_0_Registers	 0x14d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_B_Hist_Counter_0_Registers */
	#define BLSB_DPE_DI_Motion_B_Hist_Counter_0_Registers_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_B_Hist_Counter_0_Registers */
	#define BWID_DPE_DI_Motion_B_Hist_Counter_0_Registers_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_B_Hist_Counter_0_Registers */
	#define BMSK_DPE_DI_Motion_B_Hist_Counter_0_Registers_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_B_Hist_Counter_0_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_0_Registers_MOTION_B_HIST_CNTR	 0x14d4, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_B_Hist_Counter_1_Registers	0x14d8 /* DI_Motion_B_Hist_Counter_1_Registers */ 
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_1_Registers	 0x14d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_B_Hist_Counter_1_Registers */
	#define BLSB_DPE_DI_Motion_B_Hist_Counter_1_Registers_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_B_Hist_Counter_1_Registers */
	#define BWID_DPE_DI_Motion_B_Hist_Counter_1_Registers_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_B_Hist_Counter_1_Registers */
	#define BMSK_DPE_DI_Motion_B_Hist_Counter_1_Registers_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_B_Hist_Counter_1_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_1_Registers_MOTION_B_HIST_CNTR	 0x14d8, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_B_Hist_Counter_2_Registers	0x14dc /* DI_Motion_B_Hist_Counter_2_Registers */ 
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_2_Registers	 0x14dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_B_Hist_Counter_2_Registers */
	#define BLSB_DPE_DI_Motion_B_Hist_Counter_2_Registers_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_B_Hist_Counter_2_Registers */
	#define BWID_DPE_DI_Motion_B_Hist_Counter_2_Registers_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_B_Hist_Counter_2_Registers */
	#define BMSK_DPE_DI_Motion_B_Hist_Counter_2_Registers_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_B_Hist_Counter_2_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_2_Registers_MOTION_B_HIST_CNTR	 0x14dc, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_B_Hist_Counter_3_Registers	0x14e0 /* DI_Motion_B_Hist_Counter_3_Registers */ 
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_3_Registers	 0x14e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_B_Hist_Counter_3_Registers */
	#define BLSB_DPE_DI_Motion_B_Hist_Counter_3_Registers_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_Motion_B_Hist_Counter_3_Registers */
	#define BWID_DPE_DI_Motion_B_Hist_Counter_3_Registers_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_Motion_B_Hist_Counter_3_Registers */
	#define BMSK_DPE_DI_Motion_B_Hist_Counter_3_Registers_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Motion_B_Hist_Counter_3_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_B_Hist_Counter_3_Registers_MOTION_B_HIST_CNTR	 0x14e0, 0, 32, 0x00000000
#define ROFF_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers	0x14e4 /* DI_Motion_Hist_Start_Pix_Coord_Registers */ 
	#define BITFIELD_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers	 0x14e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Hist_Start_Pix_Coord_Registers */
	#define BLSB_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_Y_COORD	16
	#define BLSB_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_X_COORD	0
	/* Register Bit Widths for DPE_DI_Motion_Hist_Start_Pix_Coord_Registers */
	#define BWID_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_Y_COORD	16
	#define BWID_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_X_COORD	16
	/* Register Bit MASKS for DPE_DI_Motion_Hist_Start_Pix_Coord_Registers */
	#define BMSK_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_Y_COORD	0xffff0000 /*  */
	#define BMSK_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_X_COORD	0x0000ffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Hist_Start_Pix_Coord_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_Y_COORD	 0x14e4, 16, 16, 0xffff0000
	#define BITFIELD_DPE_DI_Motion_Hist_Start_Pix_Coord_Registers_START_PIX_X_COORD	 0x14e4, 0, 16, 0x0000ffff
#define ROFF_DPE_DI_Motion_Hist_End_Pix_Coord_Registers	0x14e8 /* DI_Motion_Hist_End_Pix_Coord_Registers */ 
	#define BITFIELD_DPE_DI_Motion_Hist_End_Pix_Coord_Registers	 0x14e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Motion_Hist_End_Pix_Coord_Registers */
	#define BLSB_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_Y_COORD	16
	#define BLSB_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_X_COORD	0
	/* Register Bit Widths for DPE_DI_Motion_Hist_End_Pix_Coord_Registers */
	#define BWID_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_Y_COORD	16
	#define BWID_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_X_COORD	16
	/* Register Bit MASKS for DPE_DI_Motion_Hist_End_Pix_Coord_Registers */
	#define BMSK_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_Y_COORD	0xffff0000 /*  */
	#define BMSK_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_X_COORD	0x0000ffff /*  */
	/* Register BITFIELD for DPE_DI_Motion_Hist_End_Pix_Coord_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_Y_COORD	 0x14e8, 16, 16, 0xffff0000
	#define BITFIELD_DPE_DI_Motion_Hist_End_Pix_Coord_Registers_END_PIX_X_COORD	 0x14e8, 0, 16, 0x0000ffff
#define ROFF_DPE_DI_New_MD_Th_Register	0x14ec /* DI_New_MD_Th_Register */ 
	#define BITFIELD_DPE_DI_New_MD_Th_Register	 0x14ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_New_MD_Th_Register */
	#define BLSB_DPE_DI_New_MD_Th_Register_NMD_MAD_TH	20
	#define BLSB_DPE_DI_New_MD_Th_Register_NMD_SAD_TH2	10
	#define BLSB_DPE_DI_New_MD_Th_Register_NMD_SAD_TH1	0
	/* Register Bit Widths for DPE_DI_New_MD_Th_Register */
	#define BWID_DPE_DI_New_MD_Th_Register_NMD_MAD_TH	6
	#define BWID_DPE_DI_New_MD_Th_Register_NMD_SAD_TH2	10
	#define BWID_DPE_DI_New_MD_Th_Register_NMD_SAD_TH1	10
	/* Register Bit MASKS for DPE_DI_New_MD_Th_Register */
	#define BMSK_DPE_DI_New_MD_Th_Register_NMD_MAD_TH	0x03f00000 /*  */
	#define BMSK_DPE_DI_New_MD_Th_Register_NMD_SAD_TH2	0x000ffc00 /*  */
	#define BMSK_DPE_DI_New_MD_Th_Register_NMD_SAD_TH1	0x000003ff /*  */
	/* Register BITFIELD for DPE_DI_New_MD_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_New_MD_Th_Register_NMD_MAD_TH	 0x14ec, 20, 6, 0x03f00000
	#define BITFIELD_DPE_DI_New_MD_Th_Register_NMD_SAD_TH2	 0x14ec, 10, 10, 0x000ffc00
	#define BITFIELD_DPE_DI_New_MD_Th_Register_NMD_SAD_TH1	 0x14ec, 0, 10, 0x000003ff
#define ROFF_DPE_DI_MD_SAD_WT_0_7_Register	0x14f0 /* DI_MD_SAD_WT_0_7_Register */ 
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register	 0x14f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MD_SAD_WT_0_7_Register */
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_7	28
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_6	24
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_5	20
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_4	16
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_3	12
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_2	8
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_1	4
	#define BLSB_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_0	0
	/* Register Bit Widths for DPE_DI_MD_SAD_WT_0_7_Register */
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_7	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_6	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_5	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_4	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_3	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_2	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_1	4
	#define BWID_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_0	4
	/* Register Bit MASKS for DPE_DI_MD_SAD_WT_0_7_Register */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_7	0xf0000000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_6	0x0f000000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_5	0x00f00000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_4	0x000f0000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_3	0x0000f000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_2	0x00000f00 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_1	0x000000f0 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_0	0x0000000f /*  */
	/* Register BITFIELD for DPE_DI_MD_SAD_WT_0_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_7	 0x14f0, 28, 4, 0xf0000000
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_6	 0x14f0, 24, 4, 0x0f000000
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_5	 0x14f0, 20, 4, 0x00f00000
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_4	 0x14f0, 16, 4, 0x000f0000
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_3	 0x14f0, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_2	 0x14f0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_1	 0x14f0, 4, 4, 0x000000f0
	#define BITFIELD_DPE_DI_MD_SAD_WT_0_7_Register_MH_SAD_Wt_0	 0x14f0, 0, 4, 0x0000000f
#define ROFF_DPE_DI_MD_SAD_WT_8_14_Register	0x14f4 /* DI_MD_SAD_WT_8_14_Register */ 
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register	 0x14f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MD_SAD_WT_8_14_Register */
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_MAD_Wt_8	28
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_14	24
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_13	20
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_12	16
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_11	12
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_10	8
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_9	4
	#define BLSB_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_8	0
	/* Register Bit Widths for DPE_DI_MD_SAD_WT_8_14_Register */
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_MAD_Wt_8	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_14	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_13	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_12	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_11	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_10	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_9	4
	#define BWID_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_8	4
	/* Register Bit MASKS for DPE_DI_MD_SAD_WT_8_14_Register */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_MAD_Wt_8	0xf0000000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_14	0x0f000000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_13	0x00f00000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_12	0x000f0000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_11	0x0000f000 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_10	0x00000f00 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_9	0x000000f0 /*  */
	#define BMSK_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_8	0x0000000f /*  */
	/* Register BITFIELD for DPE_DI_MD_SAD_WT_8_14_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_MAD_Wt_8	 0x14f4, 28, 4, 0xf0000000
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_14	 0x14f4, 24, 4, 0x0f000000
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_13	 0x14f4, 20, 4, 0x00f00000
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_12	 0x14f4, 16, 4, 0x000f0000
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_11	 0x14f4, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_10	 0x14f4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_9	 0x14f4, 4, 4, 0x000000f0
	#define BITFIELD_DPE_DI_MD_SAD_WT_8_14_Register_MH_SAD_Wt_8	 0x14f4, 0, 4, 0x0000000f
#define ROFF_DPE_DI_MD_MAD_WT_0_7_Register	0x14f8 /* DI_MD_MAD_WT_0_7_Register */ 
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register	 0x14f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MD_MAD_WT_0_7_Register */
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_7	28
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_6	24
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_5	20
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_4	16
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_3	12
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_2	8
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_1	4
	#define BLSB_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_0	0
	/* Register Bit Widths for DPE_DI_MD_MAD_WT_0_7_Register */
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_7	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_6	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_5	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_4	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_3	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_2	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_1	4
	#define BWID_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_0	4
	/* Register Bit MASKS for DPE_DI_MD_MAD_WT_0_7_Register */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_7	0xf0000000 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_6	0x0f000000 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_5	0x00f00000 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_4	0x000f0000 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_3	0x0000f000 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_2	0x00000f00 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_1	0x000000f0 /*  */
	#define BMSK_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_0	0x0000000f /*  */
	/* Register BITFIELD for DPE_DI_MD_MAD_WT_0_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_7	 0x14f8, 28, 4, 0xf0000000
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_6	 0x14f8, 24, 4, 0x0f000000
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_5	 0x14f8, 20, 4, 0x00f00000
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_4	 0x14f8, 16, 4, 0x000f0000
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_3	 0x14f8, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_2	 0x14f8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_1	 0x14f8, 4, 4, 0x000000f0
	#define BITFIELD_DPE_DI_MD_MAD_WT_0_7_Register_MH_MAD_Wt_0	 0x14f8, 0, 4, 0x0000000f
#define ROFF_DPE_DI_TNRF_SHIFT_Blend_Weight_Register	0x0 /* DI_TNRF_SHIFT_Blend_Weight_Register */ 
	#define BITFIELD_DPE_DI_TNRF_SHIFT_Blend_Weight_Register	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_SHIFT_Blend_Weight_Register */
	#define BLSB_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YU_YV_BLEND	8
	#define BLSB_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_UVSHIFT	2
	#define BLSB_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YSHIFT	0
	/* Register Bit Widths for DPE_DI_TNRF_SHIFT_Blend_Weight_Register */
	#define BWID_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YU_YV_BLEND	8
	#define BWID_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_UVSHIFT	2
	#define BWID_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YSHIFT	2
	/* Register Bit MASKS for DPE_DI_TNRF_SHIFT_Blend_Weight_Register */
	#define BMSK_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YU_YV_BLEND	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_UVSHIFT	0x0000000c /*  */
	#define BMSK_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YSHIFT	0x00000003 /*  */
	/* Register BITFIELD for DPE_DI_TNRF_SHIFT_Blend_Weight_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YU_YV_BLEND	 0x0000, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_UVSHIFT	 0x0000, 2, 2, 0x0000000c
	#define BITFIELD_DPE_DI_TNRF_SHIFT_Blend_Weight_Register_YSHIFT	 0x0000, 0, 2, 0x00000003
#define ROFF_DPE_DI_TNRF_Y_LUT_0_3_Register	0x4 /* DI_TNRF_Y_LUT_0_3_Register */ 
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_0_3_Register	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_Y_LUT_0_3_Register */
	#define BLSB_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_3	24
	#define BLSB_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_2	16
	#define BLSB_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_1	8
	#define BLSB_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_0	0
	/* Register Bit Widths for DPE_DI_TNRF_Y_LUT_0_3_Register */
	#define BWID_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_3	8
	#define BWID_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_2	8
	#define BWID_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_1	8
	#define BWID_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_0	8
	/* Register Bit MASKS for DPE_DI_TNRF_Y_LUT_0_3_Register */
	#define BMSK_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_3	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_Y_LUT_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_3	 0x0004, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_2	 0x0004, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_1	 0x0004, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_0_3_Register_TNRF_Y_LUT_0	 0x0004, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_Y_LUT_4_7_Register	0x8 /* DI_TNRF_Y_LUT_4_7_Register */ 
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_4_7_Register	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_Y_LUT_4_7_Register */
	#define BLSB_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_7	24
	#define BLSB_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_6	16
	#define BLSB_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_5	8
	#define BLSB_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_4	0
	/* Register Bit Widths for DPE_DI_TNRF_Y_LUT_4_7_Register */
	#define BWID_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_7	8
	#define BWID_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_6	8
	#define BWID_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_5	8
	#define BWID_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_4	8
	/* Register Bit MASKS for DPE_DI_TNRF_Y_LUT_4_7_Register */
	#define BMSK_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_7	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_6	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_Y_LUT_4_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_7	 0x0008, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_6	 0x0008, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_5	 0x0008, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_4_7_Register_TNRF_Y_LUT_4	 0x0008, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_Y_LUT_8_11_Register	0xc /* DI_TNRF_Y_LUT_8_11_Register */ 
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_8_11_Register	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_Y_LUT_8_11_Register */
	#define BLSB_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_11	24
	#define BLSB_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_10	16
	#define BLSB_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_9	8
	#define BLSB_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_8	0
	/* Register Bit Widths for DPE_DI_TNRF_Y_LUT_8_11_Register */
	#define BWID_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_11	8
	#define BWID_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_10	8
	#define BWID_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_9	8
	#define BWID_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_8	8
	/* Register Bit MASKS for DPE_DI_TNRF_Y_LUT_8_11_Register */
	#define BMSK_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_11	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_10	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_9	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_8	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_Y_LUT_8_11_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_11	 0x000c, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_10	 0x000c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_9	 0x000c, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_8_11_Register_TNRF_Y_LUT_8	 0x000c, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_Y_LUT_12_15_Register	0x10 /* DI_TNRF_Y_LUT_12_15_Register */ 
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_12_15_Register	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_Y_LUT_12_15_Register */
	#define BLSB_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_15	24
	#define BLSB_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_14	16
	#define BLSB_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_13	8
	#define BLSB_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_12	0
	/* Register Bit Widths for DPE_DI_TNRF_Y_LUT_12_15_Register */
	#define BWID_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_15	8
	#define BWID_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_14	8
	#define BWID_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_13	8
	#define BWID_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_12	8
	/* Register Bit MASKS for DPE_DI_TNRF_Y_LUT_12_15_Register */
	#define BMSK_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_15	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_14	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_13	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_12	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_Y_LUT_12_15_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_15	 0x0010, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_14	 0x0010, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_13	 0x0010, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_Y_LUT_12_15_Register_TNRF_Y_LUT_12	 0x0010, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_UV_LUT_0_3_Register	0x14 /* DI_TNRF_UV_LUT_0_3_Register */ 
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_0_3_Register	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_UV_LUT_0_3_Register */
	#define BLSB_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_3	24
	#define BLSB_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_2	16
	#define BLSB_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_1	8
	#define BLSB_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_0	0
	/* Register Bit Widths for DPE_DI_TNRF_UV_LUT_0_3_Register */
	#define BWID_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_3	8
	#define BWID_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_2	8
	#define BWID_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_1	8
	#define BWID_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_0	8
	/* Register Bit MASKS for DPE_DI_TNRF_UV_LUT_0_3_Register */
	#define BMSK_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_3	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_UV_LUT_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_3	 0x0014, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_2	 0x0014, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_1	 0x0014, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_0_3_Register_TNRF_UV_LUT_0	 0x0014, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_UV_LUT_4_7_Register	0x18 /* DI_TNRF_UV_LUT_4_7_Register */ 
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_4_7_Register	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_UV_LUT_4_7_Register */
	#define BLSB_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_7	24
	#define BLSB_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_6	16
	#define BLSB_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_5	8
	#define BLSB_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_4	0
	/* Register Bit Widths for DPE_DI_TNRF_UV_LUT_4_7_Register */
	#define BWID_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_7	8
	#define BWID_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_6	8
	#define BWID_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_5	8
	#define BWID_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_4	8
	/* Register Bit MASKS for DPE_DI_TNRF_UV_LUT_4_7_Register */
	#define BMSK_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_7	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_6	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_UV_LUT_4_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_7	 0x0018, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_6	 0x0018, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_5	 0x0018, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_4_7_Register_TNRF_UV_LUT_4	 0x0018, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_UV_LUT_8_11_Register	0x1c /* DI_TNRF_UV_LUT_8_11_Register */ 
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_8_11_Register	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_UV_LUT_8_11_Register */
	#define BLSB_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_11	24
	#define BLSB_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_10	16
	#define BLSB_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_9	8
	#define BLSB_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_8	0
	/* Register Bit Widths for DPE_DI_TNRF_UV_LUT_8_11_Register */
	#define BWID_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_11	8
	#define BWID_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_10	8
	#define BWID_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_9	8
	#define BWID_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_8	8
	/* Register Bit MASKS for DPE_DI_TNRF_UV_LUT_8_11_Register */
	#define BMSK_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_11	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_10	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_9	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_8	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_UV_LUT_8_11_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_11	 0x001c, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_10	 0x001c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_9	 0x001c, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_8_11_Register_TNRF_UV_LUT_8	 0x001c, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_UV_LUT_12_15_Register	0x20 /* DI_TNRF_UV_LUT_12_15_Register */ 
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_12_15_Register	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_UV_LUT_12_15_Register */
	#define BLSB_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_15	24
	#define BLSB_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_14	16
	#define BLSB_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_13	8
	#define BLSB_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_12	0
	/* Register Bit Widths for DPE_DI_TNRF_UV_LUT_12_15_Register */
	#define BWID_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_15	8
	#define BWID_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_14	8
	#define BWID_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_13	8
	#define BWID_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_12	8
	/* Register Bit MASKS for DPE_DI_TNRF_UV_LUT_12_15_Register */
	#define BMSK_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_15	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_14	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_13	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_12	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_UV_LUT_12_15_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_15	 0x0020, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_14	 0x0020, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_13	 0x0020, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_UV_LUT_12_15_Register_TNRF_UV_LUT_12	 0x0020, 0, 8, 0x000000ff
#define ROFF_DPE_DI_TNRF_Var_Sc_Factor_Register	0x24 /* DI_TNRF_Var_Sc_Factor_Register */ 
	#define BITFIELD_DPE_DI_TNRF_Var_Sc_Factor_Register	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_TNRF_Var_Sc_Factor_Register */
	#define BLSB_DPE_DI_TNRF_Var_Sc_Factor_Register_Coring_TH	24
	#define BLSB_DPE_DI_TNRF_Var_Sc_Factor_Register_FirstSec_Diff_Scale_Factor	16
	#define BLSB_DPE_DI_TNRF_Var_Sc_Factor_Register_Sec_Diff_Scale_Factor	8
	#define BLSB_DPE_DI_TNRF_Var_Sc_Factor_Register_First_Diff_Scale_Factor	0
	/* Register Bit Widths for DPE_DI_TNRF_Var_Sc_Factor_Register */
	#define BWID_DPE_DI_TNRF_Var_Sc_Factor_Register_Coring_TH	8
	#define BWID_DPE_DI_TNRF_Var_Sc_Factor_Register_FirstSec_Diff_Scale_Factor	8
	#define BWID_DPE_DI_TNRF_Var_Sc_Factor_Register_Sec_Diff_Scale_Factor	8
	#define BWID_DPE_DI_TNRF_Var_Sc_Factor_Register_First_Diff_Scale_Factor	8
	/* Register Bit MASKS for DPE_DI_TNRF_Var_Sc_Factor_Register */
	#define BMSK_DPE_DI_TNRF_Var_Sc_Factor_Register_Coring_TH	0xff000000 /*  */
	#define BMSK_DPE_DI_TNRF_Var_Sc_Factor_Register_FirstSec_Diff_Scale_Factor	0x00ff0000 /*  */
	#define BMSK_DPE_DI_TNRF_Var_Sc_Factor_Register_Sec_Diff_Scale_Factor	0x0000ff00 /*  */
	#define BMSK_DPE_DI_TNRF_Var_Sc_Factor_Register_First_Diff_Scale_Factor	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_TNRF_Var_Sc_Factor_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_TNRF_Var_Sc_Factor_Register_Coring_TH	 0x0024, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_TNRF_Var_Sc_Factor_Register_FirstSec_Diff_Scale_Factor	 0x0024, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_TNRF_Var_Sc_Factor_Register_Sec_Diff_Scale_Factor	 0x0024, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_TNRF_Var_Sc_Factor_Register_First_Diff_Scale_Factor	 0x0024, 0, 8, 0x000000ff
#define ROFF_DPE_DI_Noise_Estimation_Th_Register	0x30 /* DI_Noise_Estimation_Th_Register */ 
	#define BITFIELD_DPE_DI_Noise_Estimation_Th_Register	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Noise_Estimation_Th_Register */
	#define BLSB_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Th	10
	#define BLSB_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Const	0
	/* Register Bit Widths for DPE_DI_Noise_Estimation_Th_Register */
	#define BWID_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Th	12
	#define BWID_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Const	10
	/* Register Bit MASKS for DPE_DI_Noise_Estimation_Th_Register */
	#define BMSK_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Th	0x003ffc00 /*  */
	#define BMSK_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Const	0x000003ff /*  */
	/* Register BITFIELD for DPE_DI_Noise_Estimation_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Th	 0x0030, 10, 12, 0x003ffc00
	#define BITFIELD_DPE_DI_Noise_Estimation_Th_Register_VarNoise_Const	 0x0030, 0, 10, 0x000003ff
#define ROFF_DPE_DI_Noise_Estimation_Var_Noise_Count_Register	0x34 /* DI_Noise_Estimation_Var_Noise_Count_Register */ 
	#define BITFIELD_DPE_DI_Noise_Estimation_Var_Noise_Count_Register	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Noise_Estimation_Var_Noise_Count_Register */
	#define BLSB_DPE_DI_Noise_Estimation_Var_Noise_Count_Register_VarNoise_Count	0
	/* Register Bit Widths for DPE_DI_Noise_Estimation_Var_Noise_Count_Register */
	#define BWID_DPE_DI_Noise_Estimation_Var_Noise_Count_Register_VarNoise_Count	32
	/* Register Bit MASKS for DPE_DI_Noise_Estimation_Var_Noise_Count_Register */
	#define BMSK_DPE_DI_Noise_Estimation_Var_Noise_Count_Register_VarNoise_Count	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Noise_Estimation_Var_Noise_Count_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Noise_Estimation_Var_Noise_Count_Register_VarNoise_Count	 0x0034, 0, 32, 0x00000000
#define ROFF_DPE_DI_Noise_Estimation_Var_Noise_Level_Register	0x38 /* DI_Noise_Estimation_Var_Noise_Level_Register */ 
	#define BITFIELD_DPE_DI_Noise_Estimation_Var_Noise_Level_Register	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_Noise_Estimation_Var_Noise_Level_Register */
	#define BLSB_DPE_DI_Noise_Estimation_Var_Noise_Level_Register_VarNoise_Level	0
	/* Register Bit Widths for DPE_DI_Noise_Estimation_Var_Noise_Level_Register */
	#define BWID_DPE_DI_Noise_Estimation_Var_Noise_Level_Register_VarNoise_Level	32
	/* Register Bit MASKS for DPE_DI_Noise_Estimation_Var_Noise_Level_Register */
	#define BMSK_DPE_DI_Noise_Estimation_Var_Noise_Level_Register_VarNoise_Level	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_Noise_Estimation_Var_Noise_Level_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Noise_Estimation_Var_Noise_Level_Register_VarNoise_Level	 0x0038, 0, 32, 0x00000000
#define ROFF_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register	0x50 /* DI_MADI_LumaGain_Blend_LUT_0_3_Register */ 
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register */
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT3	24
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT2	16
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT1	8
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT0	0
	/* Register Bit Widths for DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register */
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT3	8
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT2	8
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT1	8
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT0	8
	/* Register Bit MASKS for DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT3	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT3	 0x0050, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT2	 0x0050, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT1	 0x0050, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_0_3_Register_LumaGain_Blend_LUT0	 0x0050, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register	0x54 /* DI_MADI_LumaGain_Blend_LUT_4_7_Register */ 
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register */
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT7	24
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT6	16
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT5	8
	#define BLSB_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT4	0
	/* Register Bit Widths for DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register */
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT7	8
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT6	8
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT5	8
	#define BWID_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT4	8
	/* Register Bit MASKS for DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT7	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT6	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT7	 0x0054, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT6	 0x0054, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT5	 0x0054, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_LumaGain_Blend_LUT_4_7_Register_LumaGain_Blend_LUT4	 0x0054, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register	0x58 /* DI_MADI_LumaGain_LPF_LUT_0_3_Register */ 
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register */
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT3	24
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT2	16
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT1	8
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT0	0
	/* Register Bit Widths for DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register */
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT3	8
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT2	8
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT1	8
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT0	8
	/* Register Bit MASKS for DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT3	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT3	 0x0058, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT2	 0x0058, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT1	 0x0058, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_0_3_Register_LumaGain_LPF_LUT0	 0x0058, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register	0x5c /* DI_MADI_LumaGain_LPF_LUT_4_7_Register */ 
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register */
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT7	24
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT6	16
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT5	8
	#define BLSB_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT4	0
	/* Register Bit Widths for DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register */
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT7	8
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT6	8
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT5	8
	#define BWID_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT4	8
	/* Register Bit MASKS for DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT7	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT6	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT7	 0x005c, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT6	 0x005c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT5	 0x005c, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_LumaGain_LPF_LUT_4_7_Register_LumaGain_LPF_LUT4	 0x005c, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_Coring_Th_Register	0x60 /* DI_MADI_Coring_Th_Register */ 
	#define BITFIELD_DPE_DI_MADI_Coring_Th_Register	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Coring_Th_Register */
	#define BLSB_DPE_DI_MADI_Coring_Th_Register_MAD_Coring_TH	8
	#define BLSB_DPE_DI_MADI_Coring_Th_Register_SAD_Coring_TH	0
	/* Register Bit Widths for DPE_DI_MADI_Coring_Th_Register */
	#define BWID_DPE_DI_MADI_Coring_Th_Register_MAD_Coring_TH	6
	#define BWID_DPE_DI_MADI_Coring_Th_Register_SAD_Coring_TH	8
	/* Register Bit MASKS for DPE_DI_MADI_Coring_Th_Register */
	#define BMSK_DPE_DI_MADI_Coring_Th_Register_MAD_Coring_TH	0x00003f00 /*  */
	#define BMSK_DPE_DI_MADI_Coring_Th_Register_SAD_Coring_TH	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_Coring_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Coring_Th_Register_MAD_Coring_TH	 0x0060, 8, 6, 0x00003f00
	#define BITFIELD_DPE_DI_MADI_Coring_Th_Register_SAD_Coring_TH	 0x0060, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_Freq_Ana_SAD_Th_Register	0x64 /* DI_MADI_Freq_Ana_SAD_Th_Register */ 
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_SAD_Th_Register	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Freq_Ana_SAD_Th_Register */
	#define BLSB_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_Max_Gain	16
	#define BLSB_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th2	8
	#define BLSB_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th1	0
	/* Register Bit Widths for DPE_DI_MADI_Freq_Ana_SAD_Th_Register */
	#define BWID_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_Max_Gain	8
	#define BWID_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th2	8
	#define BWID_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th1	8
	/* Register Bit MASKS for DPE_DI_MADI_Freq_Ana_SAD_Th_Register */
	#define BMSK_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_Max_Gain	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th2	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th1	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_Freq_Ana_SAD_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_Max_Gain	 0x0064, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th2	 0x0064, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_SAD_Th_Register_Freq_SAD_Th1	 0x0064, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register	0x68 /* DI_MADI_Freq_Ana_Filter1_Th_Register */ 
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Freq_Ana_Filter1_Th_Register */
	#define BLSB_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_InvDiff_Th1Th2	20
	#define BLSB_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th2	10
	#define BLSB_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th1	0
	/* Register Bit Widths for DPE_DI_MADI_Freq_Ana_Filter1_Th_Register */
	#define BWID_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_InvDiff_Th1Th2	10
	#define BWID_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th2	10
	#define BWID_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th1	10
	/* Register Bit MASKS for DPE_DI_MADI_Freq_Ana_Filter1_Th_Register */
	#define BMSK_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_InvDiff_Th1Th2	0x3ff00000 /*  */
	#define BMSK_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th2	0x000ffc00 /*  */
	#define BMSK_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th1	0x000003ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_Freq_Ana_Filter1_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_InvDiff_Th1Th2	 0x0068, 20, 10, 0x3ff00000
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th2	 0x0068, 10, 10, 0x000ffc00
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter1_Th_Register_Freq_Filt1_Th1	 0x0068, 0, 10, 0x000003ff
#define ROFF_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register	0x6c /* DI_MADI_Freq_Ana_Filter3_Th_Register */ 
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Freq_Ana_Filter3_Th_Register */
	#define BLSB_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_InvDiff_Th1Th2	20
	#define BLSB_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th2	10
	#define BLSB_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th1	0
	/* Register Bit Widths for DPE_DI_MADI_Freq_Ana_Filter3_Th_Register */
	#define BWID_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_InvDiff_Th1Th2	10
	#define BWID_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th2	10
	#define BWID_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th1	10
	/* Register Bit MASKS for DPE_DI_MADI_Freq_Ana_Filter3_Th_Register */
	#define BMSK_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_InvDiff_Th1Th2	0x3ff00000 /*  */
	#define BMSK_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th2	0x000ffc00 /*  */
	#define BMSK_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th1	0x000003ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_Freq_Ana_Filter3_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_InvDiff_Th1Th2	 0x006c, 20, 10, 0x3ff00000
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th2	 0x006c, 10, 10, 0x000ffc00
	#define BITFIELD_DPE_DI_MADI_Freq_Ana_Filter3_Th_Register_Freq_Filt3_Th1	 0x006c, 0, 10, 0x000003ff
#define ROFF_DPE_DI_MADI_SAD_MAD_TM_WTS_Register	0x70 /* DI_MADI_SAD_MAD_TM_WTS_Register */ 
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_SAD_MAD_TM_WTS_Register */
	#define BLSB_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_LPF	20
	#define BLSB_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_BLEND	16
	#define BLSB_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_LPF	12
	#define BLSB_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_BLEND	8
	#define BLSB_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_LPF	4
	#define BLSB_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_BLEND	0
	/* Register Bit Widths for DPE_DI_MADI_SAD_MAD_TM_WTS_Register */
	#define BWID_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_LPF	4
	#define BWID_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_BLEND	4
	#define BWID_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_LPF	4
	#define BWID_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_BLEND	4
	#define BWID_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_LPF	4
	#define BWID_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_BLEND	4
	/* Register Bit MASKS for DPE_DI_MADI_SAD_MAD_TM_WTS_Register */
	#define BMSK_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_LPF	0x00f00000 /*  */
	#define BMSK_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_BLEND	0x000f0000 /*  */
	#define BMSK_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_LPF	0x0000f000 /*  */
	#define BMSK_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_BLEND	0x00000f00 /*  */
	#define BMSK_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_LPF	0x000000f0 /*  */
	#define BMSK_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_BLEND	0x0000000f /*  */
	/* Register BITFIELD for DPE_DI_MADI_SAD_MAD_TM_WTS_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_LPF	 0x0070, 20, 4, 0x00f00000
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_TM_WT_BLEND	 0x0070, 16, 4, 0x000f0000
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_LPF	 0x0070, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_MAD_WT_BLEND	 0x0070, 8, 4, 0x00000f00
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_LPF	 0x0070, 4, 4, 0x000000f0
	#define BITFIELD_DPE_DI_MADI_SAD_MAD_TM_WTS_Register_SAD_WT_BLEND	 0x0070, 0, 4, 0x0000000f
#define ROFF_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register	0x74 /* DI_MADI_FWT_Blend_LUT_0_3_Register */ 
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_FWT_Blend_LUT_0_3_Register */
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT3	24
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT2	16
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT1	8
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT0	0
	/* Register Bit Widths for DPE_DI_MADI_FWT_Blend_LUT_0_3_Register */
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT3	8
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT2	8
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT1	8
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT0	8
	/* Register Bit MASKS for DPE_DI_MADI_FWT_Blend_LUT_0_3_Register */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT3	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_FWT_Blend_LUT_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT3	 0x0074, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT2	 0x0074, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT1	 0x0074, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_0_3_Register_FWT_Blend_LUT0	 0x0074, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register	0x78 /* DI_MADI_FWT_Blend_LUT_4_7_Register */ 
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register	 0x0078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_FWT_Blend_LUT_4_7_Register */
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT7	24
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT6	16
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT5	8
	#define BLSB_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT4	0
	/* Register Bit Widths for DPE_DI_MADI_FWT_Blend_LUT_4_7_Register */
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT7	8
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT6	8
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT5	8
	#define BWID_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT4	8
	/* Register Bit MASKS for DPE_DI_MADI_FWT_Blend_LUT_4_7_Register */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT7	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT6	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_FWT_Blend_LUT_4_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT7	 0x0078, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT6	 0x0078, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT5	 0x0078, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_FWT_Blend_LUT_4_7_Register_FWT_Blend_LUT4	 0x0078, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register	0x7c /* DI_MADI_FWT_LPF_LUT_0_3_Register */ 
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register	 0x007c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_FWT_LPF_LUT_0_3_Register */
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT3	24
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT2	16
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT1	8
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT0	0
	/* Register Bit Widths for DPE_DI_MADI_FWT_LPF_LUT_0_3_Register */
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT3	8
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT2	8
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT1	8
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT0	8
	/* Register Bit MASKS for DPE_DI_MADI_FWT_LPF_LUT_0_3_Register */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT3	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT2	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT1	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT0	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_FWT_LPF_LUT_0_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT3	 0x007c, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT2	 0x007c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT1	 0x007c, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_0_3_Register_FWT_LPF_LUT0	 0x007c, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register	0x80 /* DI_MADI_FWT_LPF_LUT_4_7_Register */ 
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_FWT_LPF_LUT_4_7_Register */
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT7	24
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT6	16
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT5	8
	#define BLSB_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT4	0
	/* Register Bit Widths for DPE_DI_MADI_FWT_LPF_LUT_4_7_Register */
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT7	8
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT6	8
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT5	8
	#define BWID_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT4	8
	/* Register Bit MASKS for DPE_DI_MADI_FWT_LPF_LUT_4_7_Register */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT7	0xff000000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT6	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT5	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT4	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_FWT_LPF_LUT_4_7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT7	 0x0080, 24, 8, 0xff000000
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT6	 0x0080, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT5	 0x0080, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_FWT_LPF_LUT_4_7_Register_FWT_LPF_LUT4	 0x0080, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_Post_TM_Th_Register	0x84 /* DI_MADI_Post_TM_Th_Register */ 
	#define BITFIELD_DPE_DI_MADI_Post_TM_Th_Register	 0x0084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Post_TM_Th_Register */
	#define BLSB_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_WT	24
	#define BLSB_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Max_Th	16
	#define BLSB_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_InvDiff_Th1Th2	8
	#define BLSB_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Th1	0
	/* Register Bit Widths for DPE_DI_MADI_Post_TM_Th_Register */
	#define BWID_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_WT	4
	#define BWID_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Max_Th	8
	#define BWID_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_InvDiff_Th1Th2	8
	#define BWID_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Th1	8
	/* Register Bit MASKS for DPE_DI_MADI_Post_TM_Th_Register */
	#define BMSK_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_WT	0x0f000000 /*  */
	#define BMSK_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Max_Th	0x00ff0000 /*  */
	#define BMSK_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_InvDiff_Th1Th2	0x0000ff00 /*  */
	#define BMSK_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Th1	0x000000ff /*  */
	/* Register BITFIELD for DPE_DI_MADI_Post_TM_Th_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_WT	 0x0084, 24, 4, 0x0f000000
	#define BITFIELD_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Max_Th	 0x0084, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_InvDiff_Th1Th2	 0x0084, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_DI_MADI_Post_TM_Th_Register_Post_TM_Th1	 0x0084, 0, 8, 0x000000ff
#define ROFF_DPE_DI_MADI_Control_Register	0x88 /* DI_MADI_Control_Register */ 
	#define BITFIELD_DPE_DI_MADI_Control_Register	 0x0088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Control_Register */
	#define BLSB_DPE_DI_MADI_Control_Register_Bypass_fWT_LPFLUT	8
	#define BLSB_DPE_DI_MADI_Control_Register_Bypass_fWT_BlendLUT	7
	#define BLSB_DPE_DI_MADI_Control_Register_Bypass_MDCheck_LPFWt	6
	#define BLSB_DPE_DI_MADI_Control_Register_Bypass_MDCheck_BlendWt	5
	#define BLSB_DPE_DI_MADI_Control_Register_Post_TM_Method	4
	#define BLSB_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_LPF	3
	#define BLSB_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_Blend	2
	#define BLSB_DPE_DI_MADI_Control_Register_TM_Max_Avg_Flag	1
	#define BLSB_DPE_DI_MADI_Control_Register_TM_Method_Flag	0
	/* Register Bit Widths for DPE_DI_MADI_Control_Register */
	#define BWID_DPE_DI_MADI_Control_Register_Bypass_fWT_LPFLUT	1
	#define BWID_DPE_DI_MADI_Control_Register_Bypass_fWT_BlendLUT	1
	#define BWID_DPE_DI_MADI_Control_Register_Bypass_MDCheck_LPFWt	1
	#define BWID_DPE_DI_MADI_Control_Register_Bypass_MDCheck_BlendWt	1
	#define BWID_DPE_DI_MADI_Control_Register_Post_TM_Method	1
	#define BWID_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_LPF	1
	#define BWID_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_Blend	1
	#define BWID_DPE_DI_MADI_Control_Register_TM_Max_Avg_Flag	1
	#define BWID_DPE_DI_MADI_Control_Register_TM_Method_Flag	1
	/* Register Bit MASKS for DPE_DI_MADI_Control_Register */
	#define BMSK_DPE_DI_MADI_Control_Register_Bypass_fWT_LPFLUT	(1<<8) /* == 0x00000100:  */
	#define BMSK_DPE_DI_MADI_Control_Register_Bypass_fWT_BlendLUT	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_DI_MADI_Control_Register_Bypass_MDCheck_LPFWt	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_MADI_Control_Register_Bypass_MDCheck_BlendWt	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DI_MADI_Control_Register_Post_TM_Method	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_LPF	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_Blend	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DI_MADI_Control_Register_TM_Max_Avg_Flag	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DI_MADI_Control_Register_TM_Method_Flag	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DI_MADI_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Control_Register_Bypass_fWT_LPFLUT	 0x0088, 8, 1, 0x00000100
	#define BITFIELD_DPE_DI_MADI_Control_Register_Bypass_fWT_BlendLUT	 0x0088, 7, 1, 0x00000080
	#define BITFIELD_DPE_DI_MADI_Control_Register_Bypass_MDCheck_LPFWt	 0x0088, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_MADI_Control_Register_Bypass_MDCheck_BlendWt	 0x0088, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_MADI_Control_Register_Post_TM_Method	 0x0088, 4, 1, 0x00000010
	#define BITFIELD_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_LPF	 0x0088, 3, 1, 0x00000008
	#define BITFIELD_DPE_DI_MADI_Control_Register_Bypass_Ratio_Check_Blend	 0x0088, 2, 1, 0x00000004
	#define BITFIELD_DPE_DI_MADI_Control_Register_TM_Max_Avg_Flag	 0x0088, 1, 1, 0x00000002
	#define BITFIELD_DPE_DI_MADI_Control_Register_TM_Method_Flag	 0x0088, 0, 1, 0x00000001
#define ROFF_DPE_DI_MADI_Chicken_Bit_Register	0x100 /* DI_MADI_Chicken_Bit_Register */ 
	#define BITFIELD_DPE_DI_MADI_Chicken_Bit_Register	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_MADI_Chicken_Bit_Register */
	#define BLSB_DPE_DI_MADI_Chicken_Bit_Register_Last_Indicator_fix_en	0
	/* Register Bit Widths for DPE_DI_MADI_Chicken_Bit_Register */
	#define BWID_DPE_DI_MADI_Chicken_Bit_Register_Last_Indicator_fix_en	1
	/* Register Bit MASKS for DPE_DI_MADI_Chicken_Bit_Register */
	#define BMSK_DPE_DI_MADI_Chicken_Bit_Register_Last_Indicator_fix_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DI_MADI_Chicken_Bit_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_MADI_Chicken_Bit_Register_Last_Indicator_fix_en	 0x0100, 0, 1, 0x00000001
#define ROFF_DPE_SNRF_Y_Stride_Height_Register	0x6400 /* DPE_SNRF_Y_stride_height */ 
	#define BITFIELD_DPE_SNRF_Y_Stride_Height_Register	 0x6400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Y_Stride_Height_Register */
	#define BLSB_DPE_SNRF_Y_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_SNRF_Y_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_SNRF_Y_Stride_Height_Register */
	#define BWID_DPE_SNRF_Y_Stride_Height_Register_num_strides	4
	#define BWID_DPE_SNRF_Y_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_SNRF_Y_Stride_Height_Register */
	#define BMSK_DPE_SNRF_Y_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_SNRF_Y_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_SNRF_Y_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Y_Stride_Height_Register_num_strides	 0x6400, 12, 4, 0x0000f000
	#define BITFIELD_DPE_SNRF_Y_Stride_Height_Register_stride_h	 0x6400, 0, 11, 0x000007ff
#define ROFF_DPE_SNRF_Y_Stride_Width_Register	0x6404 /* DPE_SNRF_Y_stride_width */ 
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register	 0x6404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Y_Stride_Width_Register */
	#define BLSB_DPE_SNRF_Y_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_SNRF_Y_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_SNRF_Y_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_SNRF_Y_Stride_Width_Register_RM	6
	#define BLSB_DPE_SNRF_Y_Stride_Width_Register_LM	5
	#define BLSB_DPE_SNRF_Y_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_SNRF_Y_Stride_Width_Register */
	#define BWID_DPE_SNRF_Y_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_SNRF_Y_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_SNRF_Y_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_SNRF_Y_Stride_Width_Register_RM	1
	#define BWID_DPE_SNRF_Y_Stride_Width_Register_LM	1
	#define BWID_DPE_SNRF_Y_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_SNRF_Y_Stride_Width_Register */
	#define BMSK_DPE_SNRF_Y_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_SNRF_Y_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_SNRF_Y_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_SNRF_Y_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_SNRF_Y_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_SNRF_Y_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_SNRF_Y_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register_next_rd_offset_x	 0x6404, 27, 5, 0xf8000000
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register_pix_coord_x	 0x6404, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register_out_stride_w	 0x6404, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register_RM	 0x6404, 6, 1, 0x00000040
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register_LM	 0x6404, 5, 1, 0x00000020
	#define BITFIELD_DPE_SNRF_Y_Stride_Width_Register_in_stride_off	 0x6404, 0, 5, 0x0000001f
#define ROFF_DPE_SNRF_UV_Stride_Height_Register	0x6408 /* DPE_SNRF_UV_stride_height */ 
	#define BITFIELD_DPE_SNRF_UV_Stride_Height_Register	 0x6408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_UV_Stride_Height_Register */
	#define BLSB_DPE_SNRF_UV_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_SNRF_UV_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_SNRF_UV_Stride_Height_Register */
	#define BWID_DPE_SNRF_UV_Stride_Height_Register_num_strides	4
	#define BWID_DPE_SNRF_UV_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_SNRF_UV_Stride_Height_Register */
	#define BMSK_DPE_SNRF_UV_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_SNRF_UV_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_SNRF_UV_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_UV_Stride_Height_Register_num_strides	 0x6408, 12, 4, 0x0000f000
	#define BITFIELD_DPE_SNRF_UV_Stride_Height_Register_stride_h	 0x6408, 0, 11, 0x000007ff
#define ROFF_DPE_SNRF_UV_Stride_Width_Register	0x640c /* DPE_SNRF_UV_stride_width */ 
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register	 0x640c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_UV_Stride_Width_Register */
	#define BLSB_DPE_SNRF_UV_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_SNRF_UV_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_SNRF_UV_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_SNRF_UV_Stride_Width_Register_RM	6
	#define BLSB_DPE_SNRF_UV_Stride_Width_Register_LM	5
	#define BLSB_DPE_SNRF_UV_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_SNRF_UV_Stride_Width_Register */
	#define BWID_DPE_SNRF_UV_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_SNRF_UV_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_SNRF_UV_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_SNRF_UV_Stride_Width_Register_RM	1
	#define BWID_DPE_SNRF_UV_Stride_Width_Register_LM	1
	#define BWID_DPE_SNRF_UV_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_SNRF_UV_Stride_Width_Register */
	#define BMSK_DPE_SNRF_UV_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_SNRF_UV_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_SNRF_UV_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_SNRF_UV_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_SNRF_UV_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_SNRF_UV_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_SNRF_UV_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register_next_rd_offset_x	 0x640c, 27, 5, 0xf8000000
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register_pix_coord_x	 0x640c, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register_out_stride_w	 0x640c, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register_RM	 0x640c, 6, 1, 0x00000040
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register_LM	 0x640c, 5, 1, 0x00000020
	#define BITFIELD_DPE_SNRF_UV_Stride_Width_Register_in_stride_off	 0x640c, 0, 5, 0x0000001f
#define ROFF_DPE_SNRF_Y_NEXT_BLOCK_PARAMS	0x6410 /* SNRF_Luma_Next_Field_Register */ 
	#define BITFIELD_DPE_SNRF_Y_NEXT_BLOCK_PARAMS	 0x6410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Y_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_rd_offset_y	8
	#define BLSB_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_wr_y	0
	/* Register Bit Widths for DPE_SNRF_Y_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_rd_offset_y	5
	#define BWID_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_wr_y	5
	/* Register Bit MASKS for DPE_SNRF_Y_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_SNRF_Y_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_rd_offset_y	 0x6410, 8, 5, 0x00001f00
	#define BITFIELD_DPE_SNRF_Y_NEXT_BLOCK_PARAMS_Y_next_wr_y	 0x6410, 0, 5, 0x0000001f
#define ROFF_DPE_SNRF_UV_NEXT_BLOCK_PARAMS	0x6414 /* SNRF_Chroma_Next_Field_Register */ 
	#define BITFIELD_DPE_SNRF_UV_NEXT_BLOCK_PARAMS	 0x6414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_UV_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_rd_offset_y	8
	#define BLSB_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_wr_y	0
	/* Register Bit Widths for DPE_SNRF_UV_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_rd_offset_y	5
	#define BWID_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_wr_y	5
	/* Register Bit MASKS for DPE_SNRF_UV_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_SNRF_UV_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_rd_offset_y	 0x6414, 8, 5, 0x00001f00
	#define BITFIELD_DPE_SNRF_UV_NEXT_BLOCK_PARAMS_UV_next_wr_y	 0x6414, 0, 5, 0x0000001f
#define ROFF_DPE_SNRF_Control_Register	0x6418 /* SNRF_Control_Register */ 
	#define BITFIELD_DPE_SNRF_Control_Register	 0x6418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Control_Register */
	#define BLSB_DPE_SNRF_Control_Register_Disable_impluse_noise_check	3
	#define BLSB_DPE_SNRF_Control_Register_En_3x3_Y_filter	2
	#define BLSB_DPE_SNRF_Control_Register_Chroma_Bypass	1
	#define BLSB_DPE_SNRF_Control_Register_Luma_bypass	0
	/* Register Bit Widths for DPE_SNRF_Control_Register */
	#define BWID_DPE_SNRF_Control_Register_Disable_impluse_noise_check	1
	#define BWID_DPE_SNRF_Control_Register_En_3x3_Y_filter	1
	#define BWID_DPE_SNRF_Control_Register_Chroma_Bypass	1
	#define BWID_DPE_SNRF_Control_Register_Luma_bypass	1
	/* Register Bit MASKS for DPE_SNRF_Control_Register */
	#define BMSK_DPE_SNRF_Control_Register_Disable_impluse_noise_check	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_SNRF_Control_Register_En_3x3_Y_filter	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_SNRF_Control_Register_Chroma_Bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_SNRF_Control_Register_Luma_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_SNRF_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Control_Register_Disable_impluse_noise_check	 0x6418, 3, 1, 0x00000008
	#define BITFIELD_DPE_SNRF_Control_Register_En_3x3_Y_filter	 0x6418, 2, 1, 0x00000004
	#define BITFIELD_DPE_SNRF_Control_Register_Chroma_Bypass	 0x6418, 1, 1, 0x00000002
	#define BITFIELD_DPE_SNRF_Control_Register_Luma_bypass	 0x6418, 0, 1, 0x00000001
#define ROFF_DPE_SNRF_In_filter_y0_Register	0x6420 /* SNRF_In_filter_y0_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y0_Register	 0x6420, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y0_Register */
	#define BLSB_DPE_SNRF_In_filter_y0_Register_In_filter_y0_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y0_Register */
	#define BWID_DPE_SNRF_In_filter_y0_Register_In_filter_y0_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y0_Register */
	#define BMSK_DPE_SNRF_In_filter_y0_Register_In_filter_y0_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y0_Register_In_filter_y0_coeff	 0x6420, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y1_Register	0x6424 /* SNRF_In_filter_y1_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y1_Register	 0x6424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y1_Register */
	#define BLSB_DPE_SNRF_In_filter_y1_Register_In_filter_y1_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y1_Register */
	#define BWID_DPE_SNRF_In_filter_y1_Register_In_filter_y1_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y1_Register */
	#define BMSK_DPE_SNRF_In_filter_y1_Register_In_filter_y1_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y1_Register_In_filter_y1_coeff	 0x6424, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y2_Register	0x6428 /* SNRF_In_filter_y2_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y2_Register	 0x6428, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y2_Register */
	#define BLSB_DPE_SNRF_In_filter_y2_Register_In_filter_y2_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y2_Register */
	#define BWID_DPE_SNRF_In_filter_y2_Register_In_filter_y2_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y2_Register */
	#define BMSK_DPE_SNRF_In_filter_y2_Register_In_filter_y2_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y2_Register_In_filter_y2_coeff	 0x6428, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y3_Register	0x642c /* SNRF_In_filter_y3_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y3_Register	 0x642c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y3_Register */
	#define BLSB_DPE_SNRF_In_filter_y3_Register_In_filter_y3_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y3_Register */
	#define BWID_DPE_SNRF_In_filter_y3_Register_In_filter_y3_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y3_Register */
	#define BMSK_DPE_SNRF_In_filter_y3_Register_In_filter_y3_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y3_Register_In_filter_y3_coeff	 0x642c, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y4_Register	0x6430 /* SNRF_In_filter_y4_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y4_Register	 0x6430, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y4_Register */
	#define BLSB_DPE_SNRF_In_filter_y4_Register_In_filter_y4_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y4_Register */
	#define BWID_DPE_SNRF_In_filter_y4_Register_In_filter_y4_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y4_Register */
	#define BMSK_DPE_SNRF_In_filter_y4_Register_In_filter_y4_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y4_Register_In_filter_y4_coeff	 0x6430, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y5_Register	0x6434 /* SNRF_In_filter_y5_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y5_Register	 0x6434, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y5_Register */
	#define BLSB_DPE_SNRF_In_filter_y5_Register_In_filter_y5_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y5_Register */
	#define BWID_DPE_SNRF_In_filter_y5_Register_In_filter_y5_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y5_Register */
	#define BMSK_DPE_SNRF_In_filter_y5_Register_In_filter_y5_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y5_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y5_Register_In_filter_y5_coeff	 0x6434, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y6_Register	0x6438 /* SNRF_In_filter_y6_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y6_Register	 0x6438, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y6_Register */
	#define BLSB_DPE_SNRF_In_filter_y6_Register_In_filter_y6_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y6_Register */
	#define BWID_DPE_SNRF_In_filter_y6_Register_In_filter_y6_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y6_Register */
	#define BMSK_DPE_SNRF_In_filter_y6_Register_In_filter_y6_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y6_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y6_Register_In_filter_y6_coeff	 0x6438, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y7_Register	0x643c /* SNRF_In_filter_y7_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y7_Register	 0x643c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y7_Register */
	#define BLSB_DPE_SNRF_In_filter_y7_Register_In_filter_y7_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y7_Register */
	#define BWID_DPE_SNRF_In_filter_y7_Register_In_filter_y7_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y7_Register */
	#define BMSK_DPE_SNRF_In_filter_y7_Register_In_filter_y7_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y7_Register_In_filter_y7_coeff	 0x643c, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_In_filter_y8_Register	0x6440 /* SNRF_In_filter_y8_Register */ 
	#define BITFIELD_DPE_SNRF_In_filter_y8_Register	 0x6440, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_In_filter_y8_Register */
	#define BLSB_DPE_SNRF_In_filter_y8_Register_In_filter_y8_coeff	0
	/* Register Bit Widths for DPE_SNRF_In_filter_y8_Register */
	#define BWID_DPE_SNRF_In_filter_y8_Register_In_filter_y8_coeff	12
	/* Register Bit MASKS for DPE_SNRF_In_filter_y8_Register */
	#define BMSK_DPE_SNRF_In_filter_y8_Register_In_filter_y8_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_In_filter_y8_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_In_filter_y8_Register_In_filter_y8_coeff	 0x6440, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y0_Register	0x6444 /* SNRF_Out_filter_y0_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y0_Register	 0x6444, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y0_Register */
	#define BLSB_DPE_SNRF_Out_filter_y0_Register_Out_filter_y0_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y0_Register */
	#define BWID_DPE_SNRF_Out_filter_y0_Register_Out_filter_y0_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y0_Register */
	#define BMSK_DPE_SNRF_Out_filter_y0_Register_Out_filter_y0_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y0_Register_Out_filter_y0_coeff	 0x6444, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y1_Register	0x6448 /* SNRF_Out_filter_y1_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y1_Register	 0x6448, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y1_Register */
	#define BLSB_DPE_SNRF_Out_filter_y1_Register_Out_filter_y1_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y1_Register */
	#define BWID_DPE_SNRF_Out_filter_y1_Register_Out_filter_y1_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y1_Register */
	#define BMSK_DPE_SNRF_Out_filter_y1_Register_Out_filter_y1_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y1_Register_Out_filter_y1_coeff	 0x6448, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y2_Register	0x644c /* SNRF_Out_filter_y2_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y2_Register	 0x644c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y2_Register */
	#define BLSB_DPE_SNRF_Out_filter_y2_Register_Out_filter_y2_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y2_Register */
	#define BWID_DPE_SNRF_Out_filter_y2_Register_Out_filter_y2_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y2_Register */
	#define BMSK_DPE_SNRF_Out_filter_y2_Register_Out_filter_y2_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y2_Register_Out_filter_y2_coeff	 0x644c, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y3_Register	0x6450 /* SNRF_Out_filter_y3_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y3_Register	 0x6450, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y3_Register */
	#define BLSB_DPE_SNRF_Out_filter_y3_Register_Out_filter_y3_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y3_Register */
	#define BWID_DPE_SNRF_Out_filter_y3_Register_Out_filter_y3_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y3_Register */
	#define BMSK_DPE_SNRF_Out_filter_y3_Register_Out_filter_y3_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y3_Register_Out_filter_y3_coeff	 0x6450, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y4_Register	0x6454 /* SNRF_Out_filter_y4_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y4_Register	 0x6454, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y4_Register */
	#define BLSB_DPE_SNRF_Out_filter_y4_Register_Out_filter_y4_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y4_Register */
	#define BWID_DPE_SNRF_Out_filter_y4_Register_Out_filter_y4_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y4_Register */
	#define BMSK_DPE_SNRF_Out_filter_y4_Register_Out_filter_y4_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y4_Register_Out_filter_y4_coeff	 0x6454, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y5_Register	0x6458 /* SNRF_Out_filter_y5_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y5_Register	 0x6458, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y5_Register */
	#define BLSB_DPE_SNRF_Out_filter_y5_Register_Out_filter_y5_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y5_Register */
	#define BWID_DPE_SNRF_Out_filter_y5_Register_Out_filter_y5_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y5_Register */
	#define BMSK_DPE_SNRF_Out_filter_y5_Register_Out_filter_y5_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y5_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y5_Register_Out_filter_y5_coeff	 0x6458, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y6_Register	0x645c /* SNRF_Out_filter_y6_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y6_Register	 0x645c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y6_Register */
	#define BLSB_DPE_SNRF_Out_filter_y6_Register_Out_filter_y6_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y6_Register */
	#define BWID_DPE_SNRF_Out_filter_y6_Register_Out_filter_y6_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y6_Register */
	#define BMSK_DPE_SNRF_Out_filter_y6_Register_Out_filter_y6_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y6_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y6_Register_Out_filter_y6_coeff	 0x645c, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y7_Register	0x6460 /* SNRF_Out_filter_y7_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y7_Register	 0x6460, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y7_Register */
	#define BLSB_DPE_SNRF_Out_filter_y7_Register_Out_filter_y7_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y7_Register */
	#define BWID_DPE_SNRF_Out_filter_y7_Register_Out_filter_y7_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y7_Register */
	#define BMSK_DPE_SNRF_Out_filter_y7_Register_Out_filter_y7_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y7_Register_Out_filter_y7_coeff	 0x6460, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_y8_Register	0x6464 /* SNRF_Out_filter_y8_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_y8_Register	 0x6464, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_y8_Register */
	#define BLSB_DPE_SNRF_Out_filter_y8_Register_Out_filter_y8_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_y8_Register */
	#define BWID_DPE_SNRF_Out_filter_y8_Register_Out_filter_y8_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_y8_Register */
	#define BMSK_DPE_SNRF_Out_filter_y8_Register_Out_filter_y8_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_y8_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_y8_Register_Out_filter_y8_coeff	 0x6464, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv0_Register	0x6468 /* SNRF_Out_filter_UV0_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv0_Register	 0x6468, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv0_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv0_Register_Out_filter_uv0_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv0_Register */
	#define BWID_DPE_SNRF_Out_filter_uv0_Register_Out_filter_uv0_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv0_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv0_Register_Out_filter_uv0_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv0_Register_Out_filter_uv0_coeff	 0x6468, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv1_Register	0x646c /* SNRF_Out_filter_UV1_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv1_Register	 0x646c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv1_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv1_Register_Out_filter_uv1_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv1_Register */
	#define BWID_DPE_SNRF_Out_filter_uv1_Register_Out_filter_uv1_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv1_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv1_Register_Out_filter_uv1_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv1_Register_Out_filter_uv1_coeff	 0x646c, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv2_Register	0x6470 /* SNRF_Out_filter_UV2_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv2_Register	 0x6470, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv2_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv2_Register_Out_filter_uv2_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv2_Register */
	#define BWID_DPE_SNRF_Out_filter_uv2_Register_Out_filter_uv2_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv2_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv2_Register_Out_filter_uv2_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv2_Register_Out_filter_uv2_coeff	 0x6470, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv3_Register	0x6474 /* SNRF_Out_filter_UV3_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv3_Register	 0x6474, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv3_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv3_Register_Out_filter_uv3_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv3_Register */
	#define BWID_DPE_SNRF_Out_filter_uv3_Register_Out_filter_uv3_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv3_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv3_Register_Out_filter_uv3_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv3_Register_Out_filter_uv3_coeff	 0x6474, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv4_Register	0x6478 /* SNRF_Out_filter_UV4_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv4_Register	 0x6478, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv4_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv4_Register_Out_filter_uv4_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv4_Register */
	#define BWID_DPE_SNRF_Out_filter_uv4_Register_Out_filter_uv4_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv4_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv4_Register_Out_filter_uv4_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv4_Register_Out_filter_uv4_coeff	 0x6478, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv5_Register	0x647c /* SNRF_Out_filter_UV5_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv5_Register	 0x647c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv5_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv5_Register_Out_filter_uv5_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv5_Register */
	#define BWID_DPE_SNRF_Out_filter_uv5_Register_Out_filter_uv5_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv5_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv5_Register_Out_filter_uv5_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv5_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv5_Register_Out_filter_uv5_coeff	 0x647c, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv6_Register	0x6480 /* SNRF_Out_filter_UV6_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv6_Register	 0x6480, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv6_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv6_Register_Out_filter_uv6_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv6_Register */
	#define BWID_DPE_SNRF_Out_filter_uv6_Register_Out_filter_uv6_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv6_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv6_Register_Out_filter_uv6_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv6_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv6_Register_Out_filter_uv6_coeff	 0x6480, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv7_Register	0x6484 /* SNRF_Out_filter_UV7_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv7_Register	 0x6484, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv7_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv7_Register_Out_filter_uv7_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv7_Register */
	#define BWID_DPE_SNRF_Out_filter_uv7_Register_Out_filter_uv7_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv7_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv7_Register_Out_filter_uv7_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv7_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv7_Register_Out_filter_uv7_coeff	 0x6484, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Out_filter_uv8_Register	0x6488 /* SNRF_Out_filter_UV8_Register */ 
	#define BITFIELD_DPE_SNRF_Out_filter_uv8_Register	 0x6488, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Out_filter_uv8_Register */
	#define BLSB_DPE_SNRF_Out_filter_uv8_Register_Out_filter_uv8_coeff	0
	/* Register Bit Widths for DPE_SNRF_Out_filter_uv8_Register */
	#define BWID_DPE_SNRF_Out_filter_uv8_Register_Out_filter_uv8_coeff	12
	/* Register Bit MASKS for DPE_SNRF_Out_filter_uv8_Register */
	#define BMSK_DPE_SNRF_Out_filter_uv8_Register_Out_filter_uv8_coeff	0x00000fff /*  */
	/* Register BITFIELD for DPE_SNRF_Out_filter_uv8_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Out_filter_uv8_Register_Out_filter_uv8_coeff	 0x6488, 0, 12, 0x00000fff
#define ROFF_DPE_SNRF_Max_distance_threshold_register	0x648c /* SNRF_Max_distance_threshold_register */ 
	#define BITFIELD_DPE_SNRF_Max_distance_threshold_register	 0x648c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Max_distance_threshold_register */
	#define BLSB_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_UV	16
	#define BLSB_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_Y	0
	/* Register Bit Widths for DPE_SNRF_Max_distance_threshold_register */
	#define BWID_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_UV	8
	#define BWID_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_Y	8
	/* Register Bit MASKS for DPE_SNRF_Max_distance_threshold_register */
	#define BMSK_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_UV	0x00ff0000 /*  */
	#define BMSK_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_Y	0x000000ff /*  */
	/* Register BITFIELD for DPE_SNRF_Max_distance_threshold_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_UV	 0x648c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SNRF_Max_distance_threshold_register_Max_distance_threshold_Y	 0x648c, 0, 8, 0x000000ff
#define ROFF_DPE_SNRF_Min_distance_threshold_register	0x6490 /* SNRF_Min_distance_threshold_register */ 
	#define BITFIELD_DPE_SNRF_Min_distance_threshold_register	 0x6490, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Min_distance_threshold_register */
	#define BLSB_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_UV	16
	#define BLSB_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_Y	0
	/* Register Bit Widths for DPE_SNRF_Min_distance_threshold_register */
	#define BWID_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_UV	8
	#define BWID_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_Y	8
	/* Register Bit MASKS for DPE_SNRF_Min_distance_threshold_register */
	#define BMSK_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_UV	0x00ff0000 /*  */
	#define BMSK_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_Y	0x000000ff /*  */
	/* Register BITFIELD for DPE_SNRF_Min_distance_threshold_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_UV	 0x6490, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SNRF_Min_distance_threshold_register_Min_distance_threshold_Y	 0x6490, 0, 8, 0x000000ff
#define ROFF_DPE_SNRF_Impulse_noise_threshold_register	0x6494 /* SNRF_Impulse_noise_threshold_register */ 
	#define BITFIELD_DPE_SNRF_Impulse_noise_threshold_register	 0x6494, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Impulse_noise_threshold_register */
	#define BLSB_DPE_SNRF_Impulse_noise_threshold_register_Impulse_noise_threshold_UV	16
	#define BLSB_DPE_SNRF_Impulse_noise_threshold_register_Impulse_Noise_Threshold_Y	0
	/* Register Bit Widths for DPE_SNRF_Impulse_noise_threshold_register */
	#define BWID_DPE_SNRF_Impulse_noise_threshold_register_Impulse_noise_threshold_UV	8
	#define BWID_DPE_SNRF_Impulse_noise_threshold_register_Impulse_Noise_Threshold_Y	8
	/* Register Bit MASKS for DPE_SNRF_Impulse_noise_threshold_register */
	#define BMSK_DPE_SNRF_Impulse_noise_threshold_register_Impulse_noise_threshold_UV	0x00ff0000 /*  */
	#define BMSK_DPE_SNRF_Impulse_noise_threshold_register_Impulse_Noise_Threshold_Y	0x000000ff /*  */
	/* Register BITFIELD for DPE_SNRF_Impulse_noise_threshold_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Impulse_noise_threshold_register_Impulse_noise_threshold_UV	 0x6494, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SNRF_Impulse_noise_threshold_register_Impulse_Noise_Threshold_Y	 0x6494, 0, 8, 0x000000ff
#define ROFF_DPE_SNRF_Output_avg_threshold_register	0x6498 /* SNRF_Output_avg_threshold_register */ 
	#define BITFIELD_DPE_SNRF_Output_avg_threshold_register	 0x6498, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_Output_avg_threshold_register */
	#define BLSB_DPE_SNRF_Output_avg_threshold_register_Output_average_threshold_UV	16
	#define BLSB_DPE_SNRF_Output_avg_threshold_register_Output_average_Threshold_Y	0
	/* Register Bit Widths for DPE_SNRF_Output_avg_threshold_register */
	#define BWID_DPE_SNRF_Output_avg_threshold_register_Output_average_threshold_UV	10
	#define BWID_DPE_SNRF_Output_avg_threshold_register_Output_average_Threshold_Y	10
	/* Register Bit MASKS for DPE_SNRF_Output_avg_threshold_register */
	#define BMSK_DPE_SNRF_Output_avg_threshold_register_Output_average_threshold_UV	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_Output_avg_threshold_register_Output_average_Threshold_Y	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_Output_avg_threshold_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_Output_avg_threshold_register_Output_average_threshold_UV	 0x6498, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_Output_avg_threshold_register_Output_average_Threshold_Y	 0x6498, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_hist_cntrl_register	0x300 /* SNRF_fft_hist_cntrl_register */ 
	#define BITFIELD_DPE_SNRF_fft_hist_cntrl_register	 0x0300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_hist_cntrl_register */
	#define BLSB_DPE_SNRF_fft_hist_cntrl_register_max_enable	3
	#define BLSB_DPE_SNRF_fft_hist_cntrl_register_enable_hist_win	2
	#define BLSB_DPE_SNRF_fft_hist_cntrl_register_enable_fft_win	1
	#define BLSB_DPE_SNRF_fft_hist_cntrl_register_enable_apl_win	0
	/* Register Bit Widths for DPE_SNRF_fft_hist_cntrl_register */
	#define BWID_DPE_SNRF_fft_hist_cntrl_register_max_enable	1
	#define BWID_DPE_SNRF_fft_hist_cntrl_register_enable_hist_win	1
	#define BWID_DPE_SNRF_fft_hist_cntrl_register_enable_fft_win	1
	#define BWID_DPE_SNRF_fft_hist_cntrl_register_enable_apl_win	1
	/* Register Bit MASKS for DPE_SNRF_fft_hist_cntrl_register */
	#define BMSK_DPE_SNRF_fft_hist_cntrl_register_max_enable	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_SNRF_fft_hist_cntrl_register_enable_hist_win	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_SNRF_fft_hist_cntrl_register_enable_fft_win	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_SNRF_fft_hist_cntrl_register_enable_apl_win	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_SNRF_fft_hist_cntrl_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_hist_cntrl_register_max_enable	 0x0300, 3, 1, 0x00000008
	#define BITFIELD_DPE_SNRF_fft_hist_cntrl_register_enable_hist_win	 0x0300, 2, 1, 0x00000004
	#define BITFIELD_DPE_SNRF_fft_hist_cntrl_register_enable_fft_win	 0x0300, 1, 1, 0x00000002
	#define BITFIELD_DPE_SNRF_fft_hist_cntrl_register_enable_apl_win	 0x0300, 0, 1, 0x00000001
#define ROFF_DPE_SNRF_fft_hist_y_start_register	0x304 /* SNRF_fft_hist_y_start_register */ 
	#define BITFIELD_DPE_SNRF_fft_hist_y_start_register	 0x0304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_hist_y_start_register */
	#define BLSB_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_y	16
	#define BLSB_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_x	0
	/* Register Bit Widths for DPE_SNRF_fft_hist_y_start_register */
	#define BWID_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_y	16
	#define BWID_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_x	16
	/* Register Bit MASKS for DPE_SNRF_fft_hist_y_start_register */
	#define BMSK_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_hist_y_start_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_y	 0x0304, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_fft_hist_y_start_register_Fft_hist_win_start_x	 0x0304, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_fft_hist_y_end_register	0x308 /* SNRF_fft_hist_y_end_register */ 
	#define BITFIELD_DPE_SNRF_fft_hist_y_end_register	 0x0308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_hist_y_end_register */
	#define BLSB_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_y	16
	#define BLSB_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_x	0
	/* Register Bit Widths for DPE_SNRF_fft_hist_y_end_register */
	#define BWID_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_y	16
	#define BWID_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_x	16
	/* Register Bit MASKS for DPE_SNRF_fft_hist_y_end_register */
	#define BMSK_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_hist_y_end_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_y	 0x0308, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_fft_hist_y_end_register_Fft_hist_win_end_x	 0x0308, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_fft_hist_CbCr_start_register	0x30c /* SNRF_fft_hist_CbCr_start_register */ 
	#define BITFIELD_DPE_SNRF_fft_hist_CbCr_start_register	 0x030c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_hist_CbCr_start_register */
	#define BLSB_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_y	16
	#define BLSB_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_x	0
	/* Register Bit Widths for DPE_SNRF_fft_hist_CbCr_start_register */
	#define BWID_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_y	16
	#define BWID_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_x	16
	/* Register Bit MASKS for DPE_SNRF_fft_hist_CbCr_start_register */
	#define BMSK_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_hist_CbCr_start_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_y	 0x030c, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_fft_hist_CbCr_start_register_Fft_hist_win_start_x	 0x030c, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_fft_hist_CbCr_end_register	0x310 /* SNRF_fft_hist_CbCr_end_register */ 
	#define BITFIELD_DPE_SNRF_fft_hist_CbCr_end_register	 0x0310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_hist_CbCr_end_register */
	#define BLSB_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_y	16
	#define BLSB_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_x	0
	/* Register Bit Widths for DPE_SNRF_fft_hist_CbCr_end_register */
	#define BWID_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_y	16
	#define BWID_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_x	16
	/* Register Bit MASKS for DPE_SNRF_fft_hist_CbCr_end_register */
	#define BMSK_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_hist_CbCr_end_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_y	 0x0310, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_fft_hist_CbCr_end_register_Fft_hist_win_start_x	 0x0310, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_apl_y_start_register	0x314 /* SNRF_apl_y_start_register */ 
	#define BITFIELD_DPE_SNRF_apl_y_start_register	 0x0314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_apl_y_start_register */
	#define BLSB_DPE_SNRF_apl_y_start_register_apl_win_start_y	16
	#define BLSB_DPE_SNRF_apl_y_start_register_apl_win_start_x	0
	/* Register Bit Widths for DPE_SNRF_apl_y_start_register */
	#define BWID_DPE_SNRF_apl_y_start_register_apl_win_start_y	16
	#define BWID_DPE_SNRF_apl_y_start_register_apl_win_start_x	16
	/* Register Bit MASKS for DPE_SNRF_apl_y_start_register */
	#define BMSK_DPE_SNRF_apl_y_start_register_apl_win_start_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_apl_y_start_register_apl_win_start_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_apl_y_start_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_apl_y_start_register_apl_win_start_y	 0x0314, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_apl_y_start_register_apl_win_start_x	 0x0314, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_apl_y_end_register	0x318 /* SNRF_apl_y_end_register */ 
	#define BITFIELD_DPE_SNRF_apl_y_end_register	 0x0318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_apl_y_end_register */
	#define BLSB_DPE_SNRF_apl_y_end_register_apl_win_end_y	16
	#define BLSB_DPE_SNRF_apl_y_end_register_apl_win_end_x	0
	/* Register Bit Widths for DPE_SNRF_apl_y_end_register */
	#define BWID_DPE_SNRF_apl_y_end_register_apl_win_end_y	16
	#define BWID_DPE_SNRF_apl_y_end_register_apl_win_end_x	16
	/* Register Bit MASKS for DPE_SNRF_apl_y_end_register */
	#define BMSK_DPE_SNRF_apl_y_end_register_apl_win_end_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_apl_y_end_register_apl_win_end_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_apl_y_end_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_apl_y_end_register_apl_win_end_y	 0x0318, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_apl_y_end_register_apl_win_end_x	 0x0318, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_apl_CbCr_start_register	0x31c /* SNRF_apl_CbCr_start_register */ 
	#define BITFIELD_DPE_SNRF_apl_CbCr_start_register	 0x031c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_apl_CbCr_start_register */
	#define BLSB_DPE_SNRF_apl_CbCr_start_register_apl_win_start_y	16
	#define BLSB_DPE_SNRF_apl_CbCr_start_register_apl_win_start_x	0
	/* Register Bit Widths for DPE_SNRF_apl_CbCr_start_register */
	#define BWID_DPE_SNRF_apl_CbCr_start_register_apl_win_start_y	16
	#define BWID_DPE_SNRF_apl_CbCr_start_register_apl_win_start_x	16
	/* Register Bit MASKS for DPE_SNRF_apl_CbCr_start_register */
	#define BMSK_DPE_SNRF_apl_CbCr_start_register_apl_win_start_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_apl_CbCr_start_register_apl_win_start_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_apl_CbCr_start_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_apl_CbCr_start_register_apl_win_start_y	 0x031c, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_apl_CbCr_start_register_apl_win_start_x	 0x031c, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_apl_CbCr_end_register	0x320 /* SNRF_apl_CbCr_end_register */ 
	#define BITFIELD_DPE_SNRF_apl_CbCr_end_register	 0x0320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_apl_CbCr_end_register */
	#define BLSB_DPE_SNRF_apl_CbCr_end_register_apl_win_start_y	16
	#define BLSB_DPE_SNRF_apl_CbCr_end_register_apl_win_start_x	0
	/* Register Bit Widths for DPE_SNRF_apl_CbCr_end_register */
	#define BWID_DPE_SNRF_apl_CbCr_end_register_apl_win_start_y	16
	#define BWID_DPE_SNRF_apl_CbCr_end_register_apl_win_start_x	16
	/* Register Bit MASKS for DPE_SNRF_apl_CbCr_end_register */
	#define BMSK_DPE_SNRF_apl_CbCr_end_register_apl_win_start_y	0xffff0000 /*  */
	#define BMSK_DPE_SNRF_apl_CbCr_end_register_apl_win_start_x	0x0000ffff /*  */
	/* Register BITFIELD for DPE_SNRF_apl_CbCr_end_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_apl_CbCr_end_register_apl_win_start_y	 0x0320, 16, 16, 0xffff0000
	#define BITFIELD_DPE_SNRF_apl_CbCr_end_register_apl_win_start_x	 0x0320, 0, 16, 0x0000ffff
#define ROFF_DPE_SNRF_stride_width_y	0x324 /* SNRF_stride_width_y */ 
	#define BITFIELD_DPE_SNRF_stride_width_y	 0x0324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_stride_width_y */
	#define BLSB_DPE_SNRF_stride_width_y_next_rd_offset_x	27
	#define BLSB_DPE_SNRF_stride_width_y_Pix_coord_x	16
	#define BLSB_DPE_SNRF_stride_width_y_In_stride_w	7
	#define BLSB_DPE_SNRF_stride_width_y_RM	6
	#define BLSB_DPE_SNRF_stride_width_y_LM	5
	#define BLSB_DPE_SNRF_stride_width_y_IN_stride_off	0
	/* Register Bit Widths for DPE_SNRF_stride_width_y */
	#define BWID_DPE_SNRF_stride_width_y_next_rd_offset_x	5
	#define BWID_DPE_SNRF_stride_width_y_Pix_coord_x	11
	#define BWID_DPE_SNRF_stride_width_y_In_stride_w	9
	#define BWID_DPE_SNRF_stride_width_y_RM	1
	#define BWID_DPE_SNRF_stride_width_y_LM	1
	#define BWID_DPE_SNRF_stride_width_y_IN_stride_off	5
	/* Register Bit MASKS for DPE_SNRF_stride_width_y */
	#define BMSK_DPE_SNRF_stride_width_y_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_SNRF_stride_width_y_Pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_SNRF_stride_width_y_In_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_SNRF_stride_width_y_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_SNRF_stride_width_y_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_SNRF_stride_width_y_IN_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_SNRF_stride_width_y - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_stride_width_y_next_rd_offset_x	 0x0324, 27, 5, 0xf8000000
	#define BITFIELD_DPE_SNRF_stride_width_y_Pix_coord_x	 0x0324, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_SNRF_stride_width_y_In_stride_w	 0x0324, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_SNRF_stride_width_y_RM	 0x0324, 6, 1, 0x00000040
	#define BITFIELD_DPE_SNRF_stride_width_y_LM	 0x0324, 5, 1, 0x00000020
	#define BITFIELD_DPE_SNRF_stride_width_y_IN_stride_off	 0x0324, 0, 5, 0x0000001f
#define ROFF_DPE_SNRF_stride_width_CbCr	0x328 /* SNRF_stride_width_CbCr */ 
	#define BITFIELD_DPE_SNRF_stride_width_CbCr	 0x0328, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_stride_width_CbCr */
	#define BLSB_DPE_SNRF_stride_width_CbCr_next_rd_offset_x	27
	#define BLSB_DPE_SNRF_stride_width_CbCr_Pix_coord_x	16
	#define BLSB_DPE_SNRF_stride_width_CbCr_In_stride_w	7
	#define BLSB_DPE_SNRF_stride_width_CbCr_RM	6
	#define BLSB_DPE_SNRF_stride_width_CbCr_LM	5
	#define BLSB_DPE_SNRF_stride_width_CbCr_IN_stride_off	0
	/* Register Bit Widths for DPE_SNRF_stride_width_CbCr */
	#define BWID_DPE_SNRF_stride_width_CbCr_next_rd_offset_x	5
	#define BWID_DPE_SNRF_stride_width_CbCr_Pix_coord_x	11
	#define BWID_DPE_SNRF_stride_width_CbCr_In_stride_w	9
	#define BWID_DPE_SNRF_stride_width_CbCr_RM	1
	#define BWID_DPE_SNRF_stride_width_CbCr_LM	1
	#define BWID_DPE_SNRF_stride_width_CbCr_IN_stride_off	5
	/* Register Bit MASKS for DPE_SNRF_stride_width_CbCr */
	#define BMSK_DPE_SNRF_stride_width_CbCr_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_SNRF_stride_width_CbCr_Pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_SNRF_stride_width_CbCr_In_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_SNRF_stride_width_CbCr_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_SNRF_stride_width_CbCr_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_SNRF_stride_width_CbCr_IN_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_SNRF_stride_width_CbCr - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_stride_width_CbCr_next_rd_offset_x	 0x0328, 27, 5, 0xf8000000
	#define BITFIELD_DPE_SNRF_stride_width_CbCr_Pix_coord_x	 0x0328, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_SNRF_stride_width_CbCr_In_stride_w	 0x0328, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_SNRF_stride_width_CbCr_RM	 0x0328, 6, 1, 0x00000040
	#define BITFIELD_DPE_SNRF_stride_width_CbCr_LM	 0x0328, 5, 1, 0x00000020
	#define BITFIELD_DPE_SNRF_stride_width_CbCr_IN_stride_off	 0x0328, 0, 5, 0x0000001f
#define ROFF_DPE_SNRF_fft_coeff_0_A	0x32c /* SNRF_fft_coeff_0_A */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_0_A	 0x032c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_0_A */
	#define BLSB_DPE_SNRF_fft_coeff_0_A_Coef_01	16
	#define BLSB_DPE_SNRF_fft_coeff_0_A_Coef_00	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_0_A */
	#define BWID_DPE_SNRF_fft_coeff_0_A_Coef_01	10
	#define BWID_DPE_SNRF_fft_coeff_0_A_Coef_00	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_0_A */
	#define BMSK_DPE_SNRF_fft_coeff_0_A_Coef_01	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_0_A_Coef_00	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_0_A - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_0_A_Coef_01	 0x032c, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_0_A_Coef_00	 0x032c, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_0_B	0x330 /* SNRF_fft_coeff_0_B */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_0_B	 0x0330, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_0_B */
	#define BLSB_DPE_SNRF_fft_coeff_0_B_Coef_03	16
	#define BLSB_DPE_SNRF_fft_coeff_0_B_Coef_02	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_0_B */
	#define BWID_DPE_SNRF_fft_coeff_0_B_Coef_03	10
	#define BWID_DPE_SNRF_fft_coeff_0_B_Coef_02	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_0_B */
	#define BMSK_DPE_SNRF_fft_coeff_0_B_Coef_03	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_0_B_Coef_02	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_0_B - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_0_B_Coef_03	 0x0330, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_0_B_Coef_02	 0x0330, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_1_A	0x334 /* SNRF_fft_coeff_1_A */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_1_A	 0x0334, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_1_A */
	#define BLSB_DPE_SNRF_fft_coeff_1_A_Coef_11	16
	#define BLSB_DPE_SNRF_fft_coeff_1_A_Coef_10	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_1_A */
	#define BWID_DPE_SNRF_fft_coeff_1_A_Coef_11	10
	#define BWID_DPE_SNRF_fft_coeff_1_A_Coef_10	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_1_A */
	#define BMSK_DPE_SNRF_fft_coeff_1_A_Coef_11	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_1_A_Coef_10	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_1_A - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_1_A_Coef_11	 0x0334, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_1_A_Coef_10	 0x0334, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_1_B	0x338 /* SNRF_fft_coeff_1_B */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_1_B	 0x0338, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_1_B */
	#define BLSB_DPE_SNRF_fft_coeff_1_B_Coef_13	16
	#define BLSB_DPE_SNRF_fft_coeff_1_B_Coef_12	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_1_B */
	#define BWID_DPE_SNRF_fft_coeff_1_B_Coef_13	10
	#define BWID_DPE_SNRF_fft_coeff_1_B_Coef_12	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_1_B */
	#define BMSK_DPE_SNRF_fft_coeff_1_B_Coef_13	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_1_B_Coef_12	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_1_B - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_1_B_Coef_13	 0x0338, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_1_B_Coef_12	 0x0338, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_2_A	0x33c /* SNRF_fft_coeff_2_A */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_2_A	 0x033c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_2_A */
	#define BLSB_DPE_SNRF_fft_coeff_2_A_Coef_21	16
	#define BLSB_DPE_SNRF_fft_coeff_2_A_Coef_20	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_2_A */
	#define BWID_DPE_SNRF_fft_coeff_2_A_Coef_21	10
	#define BWID_DPE_SNRF_fft_coeff_2_A_Coef_20	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_2_A */
	#define BMSK_DPE_SNRF_fft_coeff_2_A_Coef_21	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_2_A_Coef_20	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_2_A - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_2_A_Coef_21	 0x033c, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_2_A_Coef_20	 0x033c, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_2_B	0x340 /* SNRF_fft_coeff_2_B */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_2_B	 0x0340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_2_B */
	#define BLSB_DPE_SNRF_fft_coeff_2_B_Coef_23	16
	#define BLSB_DPE_SNRF_fft_coeff_2_B_Coef_22	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_2_B */
	#define BWID_DPE_SNRF_fft_coeff_2_B_Coef_23	10
	#define BWID_DPE_SNRF_fft_coeff_2_B_Coef_22	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_2_B */
	#define BMSK_DPE_SNRF_fft_coeff_2_B_Coef_23	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_2_B_Coef_22	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_2_B - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_2_B_Coef_23	 0x0340, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_2_B_Coef_22	 0x0340, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_3_A	0x344 /* SNRF_fft_coeff_3_A */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_3_A	 0x0344, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_3_A */
	#define BLSB_DPE_SNRF_fft_coeff_3_A_Coef_31	16
	#define BLSB_DPE_SNRF_fft_coeff_3_A_Coef_30	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_3_A */
	#define BWID_DPE_SNRF_fft_coeff_3_A_Coef_31	10
	#define BWID_DPE_SNRF_fft_coeff_3_A_Coef_30	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_3_A */
	#define BMSK_DPE_SNRF_fft_coeff_3_A_Coef_31	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_3_A_Coef_30	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_3_A - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_3_A_Coef_31	 0x0344, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_3_A_Coef_30	 0x0344, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_3_B	0x348 /* SNRF_fft_coeff_3_B */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_3_B	 0x0348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_3_B */
	#define BLSB_DPE_SNRF_fft_coeff_3_B_Coef_33	16
	#define BLSB_DPE_SNRF_fft_coeff_3_B_Coef_32	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_3_B */
	#define BWID_DPE_SNRF_fft_coeff_3_B_Coef_33	10
	#define BWID_DPE_SNRF_fft_coeff_3_B_Coef_32	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_3_B */
	#define BMSK_DPE_SNRF_fft_coeff_3_B_Coef_33	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_3_B_Coef_32	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_3_B - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_3_B_Coef_33	 0x0348, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_3_B_Coef_32	 0x0348, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_4_A	0x34c /* SNRF_fft_coeff_4_A */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_4_A	 0x034c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_4_A */
	#define BLSB_DPE_SNRF_fft_coeff_4_A_Coef_41	16
	#define BLSB_DPE_SNRF_fft_coeff_4_A_Coef_40	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_4_A */
	#define BWID_DPE_SNRF_fft_coeff_4_A_Coef_41	10
	#define BWID_DPE_SNRF_fft_coeff_4_A_Coef_40	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_4_A */
	#define BMSK_DPE_SNRF_fft_coeff_4_A_Coef_41	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_4_A_Coef_40	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_4_A - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_4_A_Coef_41	 0x034c, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_4_A_Coef_40	 0x034c, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_coeff_4_B	0x350 /* SNRF_fft_coeff_4_B */ 
	#define BITFIELD_DPE_SNRF_fft_coeff_4_B	 0x0350, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_coeff_4_B */
	#define BLSB_DPE_SNRF_fft_coeff_4_B_Coef_43	16
	#define BLSB_DPE_SNRF_fft_coeff_4_B_Coef_42	0
	/* Register Bit Widths for DPE_SNRF_fft_coeff_4_B */
	#define BWID_DPE_SNRF_fft_coeff_4_B_Coef_43	10
	#define BWID_DPE_SNRF_fft_coeff_4_B_Coef_42	10
	/* Register Bit MASKS for DPE_SNRF_fft_coeff_4_B */
	#define BMSK_DPE_SNRF_fft_coeff_4_B_Coef_43	0x03ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_coeff_4_B_Coef_42	0x000003ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_coeff_4_B - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_coeff_4_B_Coef_43	 0x0350, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_SNRF_fft_coeff_4_B_Coef_42	 0x0350, 0, 10, 0x000003ff
#define ROFF_DPE_SNRF_fft_th	0x354 /* SNRF_fft_th */ 
	#define BITFIELD_DPE_SNRF_fft_th	 0x0354, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_fft_th */
	#define BLSB_DPE_SNRF_fft_th_TH_3	24
	#define BLSB_DPE_SNRF_fft_th_TH_2	16
	#define BLSB_DPE_SNRF_fft_th_TH_1	8
	#define BLSB_DPE_SNRF_fft_th_TH_0	0
	/* Register Bit Widths for DPE_SNRF_fft_th */
	#define BWID_DPE_SNRF_fft_th_TH_3	8
	#define BWID_DPE_SNRF_fft_th_TH_2	8
	#define BWID_DPE_SNRF_fft_th_TH_1	8
	#define BWID_DPE_SNRF_fft_th_TH_0	8
	/* Register Bit MASKS for DPE_SNRF_fft_th */
	#define BMSK_DPE_SNRF_fft_th_TH_3	0xff000000 /*  */
	#define BMSK_DPE_SNRF_fft_th_TH_2	0x00ff0000 /*  */
	#define BMSK_DPE_SNRF_fft_th_TH_1	0x0000ff00 /*  */
	#define BMSK_DPE_SNRF_fft_th_TH_0	0x000000ff /*  */
	/* Register BITFIELD for DPE_SNRF_fft_th - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_fft_th_TH_3	 0x0354, 24, 8, 0xff000000
	#define BITFIELD_DPE_SNRF_fft_th_TH_2	 0x0354, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SNRF_fft_th_TH_1	 0x0354, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_SNRF_fft_th_TH_0	 0x0354, 0, 8, 0x000000ff
#define ROFF_DPE_SNRF_pix_cum_value_y	0x358 /* SNRF_pix_cum_value_y */ 
	#define BITFIELD_DPE_SNRF_pix_cum_value_y	 0x0358, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_pix_cum_value_y */
	#define BLSB_DPE_SNRF_pix_cum_value_y_pix_cum_value	0
	/* Register Bit Widths for DPE_SNRF_pix_cum_value_y */
	#define BWID_DPE_SNRF_pix_cum_value_y_pix_cum_value	32
	/* Register Bit MASKS for DPE_SNRF_pix_cum_value_y */
	#define BMSK_DPE_SNRF_pix_cum_value_y_pix_cum_value	0x00000000 /*  */
	/* Register BITFIELD for DPE_SNRF_pix_cum_value_y - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_pix_cum_value_y_pix_cum_value	 0x0358, 0, 32, 0x00000000
#define ROFF_DPE_SNRF_pix_cum_value_Cb	0x35c /* SNRF_pix_cum_value_Cb */ 
	#define BITFIELD_DPE_SNRF_pix_cum_value_Cb	 0x035c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_pix_cum_value_Cb */
	#define BLSB_DPE_SNRF_pix_cum_value_Cb_pix_cum_value	0
	/* Register Bit Widths for DPE_SNRF_pix_cum_value_Cb */
	#define BWID_DPE_SNRF_pix_cum_value_Cb_pix_cum_value	32
	/* Register Bit MASKS for DPE_SNRF_pix_cum_value_Cb */
	#define BMSK_DPE_SNRF_pix_cum_value_Cb_pix_cum_value	0x00000000 /*  */
	/* Register BITFIELD for DPE_SNRF_pix_cum_value_Cb - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_pix_cum_value_Cb_pix_cum_value	 0x035c, 0, 32, 0x00000000
#define ROFF_DPE_SNRF_pix_cum_value_Cr	0x360 /* SNRF_pix_cum_value_Cr */ 
	#define BITFIELD_DPE_SNRF_pix_cum_value_Cr	 0x0360, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SNRF_pix_cum_value_Cr */
	#define BLSB_DPE_SNRF_pix_cum_value_Cr_pix_cum_value	0
	/* Register Bit Widths for DPE_SNRF_pix_cum_value_Cr */
	#define BWID_DPE_SNRF_pix_cum_value_Cr_pix_cum_value	32
	/* Register Bit MASKS for DPE_SNRF_pix_cum_value_Cr */
	#define BMSK_DPE_SNRF_pix_cum_value_Cr_pix_cum_value	0x00000000 /*  */
	/* Register BITFIELD for DPE_SNRF_pix_cum_value_Cr - roff, lsb, width, mask */
	#define BITFIELD_DPE_SNRF_pix_cum_value_Cr_pix_cum_value	 0x0360, 0, 32, 0x00000000
#define ROFF_DPE_FGT_Y_STRIDE_HEIGHT	0x500 /* DPE FGT Y stride height */ 
	#define BITFIELD_DPE_FGT_Y_STRIDE_HEIGHT	 0x0500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_Y_STRIDE_HEIGHT */
	#define BLSB_DPE_FGT_Y_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_FGT_Y_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_FGT_Y_STRIDE_HEIGHT */
	#define BWID_DPE_FGT_Y_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_FGT_Y_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_FGT_Y_STRIDE_HEIGHT */
	#define BMSK_DPE_FGT_Y_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_FGT_Y_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_FGT_Y_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_Y_STRIDE_HEIGHT_num_strides	 0x0500, 12, 4, 0x0000f000
	#define BITFIELD_DPE_FGT_Y_STRIDE_HEIGHT_stride_h	 0x0500, 0, 11, 0x000007ff
#define ROFF_DPE_FGT_Y_STRIDE_WIDTH	0x504 /* DPE FGT Y stride width */ 
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH	 0x0504, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_Y_STRIDE_WIDTH */
	#define BLSB_DPE_FGT_Y_STRIDE_WIDTH_next_rd_offset_x	27
	#define BLSB_DPE_FGT_Y_STRIDE_WIDTH_pix_coord_x	16
	#define BLSB_DPE_FGT_Y_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_FGT_Y_STRIDE_WIDTH_RM	6
	#define BLSB_DPE_FGT_Y_STRIDE_WIDTH_LM	5
	#define BLSB_DPE_FGT_Y_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_FGT_Y_STRIDE_WIDTH */
	#define BWID_DPE_FGT_Y_STRIDE_WIDTH_next_rd_offset_x	5
	#define BWID_DPE_FGT_Y_STRIDE_WIDTH_pix_coord_x	11
	#define BWID_DPE_FGT_Y_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_FGT_Y_STRIDE_WIDTH_RM	1
	#define BWID_DPE_FGT_Y_STRIDE_WIDTH_LM	1
	#define BWID_DPE_FGT_Y_STRIDE_WIDTH_in_stride_off	5
	/* Register Bit MASKS for DPE_FGT_Y_STRIDE_WIDTH */
	#define BMSK_DPE_FGT_Y_STRIDE_WIDTH_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_FGT_Y_STRIDE_WIDTH_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_FGT_Y_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_FGT_Y_STRIDE_WIDTH_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_FGT_Y_STRIDE_WIDTH_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_FGT_Y_STRIDE_WIDTH_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_FGT_Y_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH_next_rd_offset_x	 0x0504, 27, 5, 0xf8000000
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH_pix_coord_x	 0x0504, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH_out_stride_w	 0x0504, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH_RM	 0x0504, 6, 1, 0x00000040
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH_LM	 0x0504, 5, 1, 0x00000020
	#define BITFIELD_DPE_FGT_Y_STRIDE_WIDTH_in_stride_off	 0x0504, 0, 5, 0x0000001f
#define ROFF_DPE_FGT_UV_STRIDE_HEIGHT	0x508 /* DPE FGT UV stride height */ 
	#define BITFIELD_DPE_FGT_UV_STRIDE_HEIGHT	 0x0508, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_UV_STRIDE_HEIGHT */
	#define BLSB_DPE_FGT_UV_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_FGT_UV_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_FGT_UV_STRIDE_HEIGHT */
	#define BWID_DPE_FGT_UV_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_FGT_UV_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_FGT_UV_STRIDE_HEIGHT */
	#define BMSK_DPE_FGT_UV_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_FGT_UV_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_FGT_UV_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_UV_STRIDE_HEIGHT_num_strides	 0x0508, 12, 4, 0x0000f000
	#define BITFIELD_DPE_FGT_UV_STRIDE_HEIGHT_stride_h	 0x0508, 0, 11, 0x000007ff
#define ROFF_DPE_FGT_UV_STRIDE_WIDTH	0x50c /* DPE FGT UV stride width */ 
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH	 0x050c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_UV_STRIDE_WIDTH */
	#define BLSB_DPE_FGT_UV_STRIDE_WIDTH_next_rd_offset_x	27
	#define BLSB_DPE_FGT_UV_STRIDE_WIDTH_pix_coord_x	16
	#define BLSB_DPE_FGT_UV_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_FGT_UV_STRIDE_WIDTH_RM	6
	#define BLSB_DPE_FGT_UV_STRIDE_WIDTH_LM	5
	#define BLSB_DPE_FGT_UV_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_FGT_UV_STRIDE_WIDTH */
	#define BWID_DPE_FGT_UV_STRIDE_WIDTH_next_rd_offset_x	5
	#define BWID_DPE_FGT_UV_STRIDE_WIDTH_pix_coord_x	11
	#define BWID_DPE_FGT_UV_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_FGT_UV_STRIDE_WIDTH_RM	1
	#define BWID_DPE_FGT_UV_STRIDE_WIDTH_LM	1
	#define BWID_DPE_FGT_UV_STRIDE_WIDTH_in_stride_off	5
	/* Register Bit MASKS for DPE_FGT_UV_STRIDE_WIDTH */
	#define BMSK_DPE_FGT_UV_STRIDE_WIDTH_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_FGT_UV_STRIDE_WIDTH_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_FGT_UV_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_FGT_UV_STRIDE_WIDTH_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_FGT_UV_STRIDE_WIDTH_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_FGT_UV_STRIDE_WIDTH_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_FGT_UV_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH_next_rd_offset_x	 0x050c, 27, 5, 0xf8000000
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH_pix_coord_x	 0x050c, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH_out_stride_w	 0x050c, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH_RM	 0x050c, 6, 1, 0x00000040
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH_LM	 0x050c, 5, 1, 0x00000020
	#define BITFIELD_DPE_FGT_UV_STRIDE_WIDTH_in_stride_off	 0x050c, 0, 5, 0x0000001f
#define ROFF_DPE_FGT_Y_NEXT_BLOCK_PARAMS	0x510 /* Pixel Data Block Size and Offset parameters for next block in pipeline */ 
	#define BITFIELD_DPE_FGT_Y_NEXT_BLOCK_PARAMS	 0x0510, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_Y_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_FGT_Y_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_FGT_Y_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_FGT_Y_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x0510, 8, 5, 0x00001f00
	#define BITFIELD_DPE_FGT_Y_NEXT_BLOCK_PARAMS_next_wr_y	 0x0510, 0, 5, 0x0000001f
#define ROFF_DPE_FGT_UV_NEXT_BLOCK_PARAMS	0x514 /* Pixel Data Block Size and Offset parameters for next block in pipeline */ 
	#define BITFIELD_DPE_FGT_UV_NEXT_BLOCK_PARAMS	 0x0514, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_UV_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_FGT_UV_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_FGT_UV_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_FGT_UV_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x0514, 8, 5, 0x00001f00
	#define BITFIELD_DPE_FGT_UV_NEXT_BLOCK_PARAMS_next_wr_y	 0x0514, 0, 5, 0x0000001f
#define ROFF_DPE_FGT_CONTROL	0x520 /* General configuration that affects the entire FGT like bypass */ 
	#define BITFIELD_DPE_FGT_CONTROL	 0x0520, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_CONTROL */
	#define BLSB_DPE_FGT_CONTROL_fgt_bypass	7
	#define BLSB_DPE_FGT_CONTROL_fgt_y_bypass	6
	#define BLSB_DPE_FGT_CONTROL_fgt_U_bypass	5
	#define BLSB_DPE_FGT_CONTROL_fgt_V_bypass	4
	#define BLSB_DPE_FGT_CONTROL_sw_pic_cfg_done	3
	#define BLSB_DPE_FGT_CONTROL_log2_scale_factor	0
	/* Register Bit Widths for DPE_FGT_CONTROL */
	#define BWID_DPE_FGT_CONTROL_fgt_bypass	1
	#define BWID_DPE_FGT_CONTROL_fgt_y_bypass	1
	#define BWID_DPE_FGT_CONTROL_fgt_U_bypass	1
	#define BWID_DPE_FGT_CONTROL_fgt_V_bypass	1
	#define BWID_DPE_FGT_CONTROL_sw_pic_cfg_done	1
	#define BWID_DPE_FGT_CONTROL_log2_scale_factor	3
	/* Register Bit MASKS for DPE_FGT_CONTROL */
	#define BMSK_DPE_FGT_CONTROL_fgt_bypass	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_FGT_CONTROL_fgt_y_bypass	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_FGT_CONTROL_fgt_U_bypass	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_FGT_CONTROL_fgt_V_bypass	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_FGT_CONTROL_sw_pic_cfg_done	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_FGT_CONTROL_log2_scale_factor	0x00000007 /*  */
	/* Register BITFIELD for DPE_FGT_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_CONTROL_fgt_bypass	 0x0520, 7, 1, 0x00000080
	#define BITFIELD_DPE_FGT_CONTROL_fgt_y_bypass	 0x0520, 6, 1, 0x00000040
	#define BITFIELD_DPE_FGT_CONTROL_fgt_U_bypass	 0x0520, 5, 1, 0x00000020
	#define BITFIELD_DPE_FGT_CONTROL_fgt_V_bypass	 0x0520, 4, 1, 0x00000010
	#define BITFIELD_DPE_FGT_CONTROL_sw_pic_cfg_done	 0x0520, 3, 1, 0x00000008
	#define BITFIELD_DPE_FGT_CONTROL_log2_scale_factor	 0x0520, 0, 3, 0x00000007
#define ROFF_DPE_FGT_PRNG_Y_STRIDE_PARAMS	0x534 /* FGT Y configuration parameters for configuring PRNG to handle stride-based processing */ 
	#define BITFIELD_DPE_FGT_PRNG_Y_STRIDE_PARAMS	 0x0534, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_PRNG_Y_STRIDE_PARAMS */
	#define BLSB_DPE_FGT_PRNG_Y_STRIDE_PARAMS_nnext_stride_strt_off	12
	#define BLSB_DPE_FGT_PRNG_Y_STRIDE_PARAMS_next_row_strt_off	0
	/* Register Bit Widths for DPE_FGT_PRNG_Y_STRIDE_PARAMS */
	#define BWID_DPE_FGT_PRNG_Y_STRIDE_PARAMS_nnext_stride_strt_off	9
	#define BWID_DPE_FGT_PRNG_Y_STRIDE_PARAMS_next_row_strt_off	12
	/* Register Bit MASKS for DPE_FGT_PRNG_Y_STRIDE_PARAMS */
	#define BMSK_DPE_FGT_PRNG_Y_STRIDE_PARAMS_nnext_stride_strt_off	0x001ff000 /*  */
	#define BMSK_DPE_FGT_PRNG_Y_STRIDE_PARAMS_next_row_strt_off	0x00000fff /*  */
	/* Register BITFIELD for DPE_FGT_PRNG_Y_STRIDE_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_PRNG_Y_STRIDE_PARAMS_nnext_stride_strt_off	 0x0534, 12, 9, 0x001ff000
	#define BITFIELD_DPE_FGT_PRNG_Y_STRIDE_PARAMS_next_row_strt_off	 0x0534, 0, 12, 0x00000fff
#define ROFF_DPE_FGT_PRNG_UV_STRIDE_PARAMS	0x538 /* FGT UV configuration parameters for configuring PRNG to handle stride-based processing */ 
	#define BITFIELD_DPE_FGT_PRNG_UV_STRIDE_PARAMS	 0x0538, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_PRNG_UV_STRIDE_PARAMS */
	#define BLSB_DPE_FGT_PRNG_UV_STRIDE_PARAMS_nnext_stride_strt_off	12
	#define BLSB_DPE_FGT_PRNG_UV_STRIDE_PARAMS_next_row_strt_off	0
	/* Register Bit Widths for DPE_FGT_PRNG_UV_STRIDE_PARAMS */
	#define BWID_DPE_FGT_PRNG_UV_STRIDE_PARAMS_nnext_stride_strt_off	9
	#define BWID_DPE_FGT_PRNG_UV_STRIDE_PARAMS_next_row_strt_off	12
	/* Register Bit MASKS for DPE_FGT_PRNG_UV_STRIDE_PARAMS */
	#define BMSK_DPE_FGT_PRNG_UV_STRIDE_PARAMS_nnext_stride_strt_off	0x001ff000 /*  */
	#define BMSK_DPE_FGT_PRNG_UV_STRIDE_PARAMS_next_row_strt_off	0x00000fff /*  */
	/* Register BITFIELD for DPE_FGT_PRNG_UV_STRIDE_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_PRNG_UV_STRIDE_PARAMS_nnext_stride_strt_off	 0x0538, 12, 9, 0x001ff000
	#define BITFIELD_DPE_FGT_PRNG_UV_STRIDE_PARAMS_next_row_strt_off	 0x0538, 0, 12, 0x00000fff
#define ROFF_DPE_FGT_Y_PRNG_SEED	0x528 /* FGT PRNG seed value of the current stride for Y component */ 
	#define BITFIELD_DPE_FGT_Y_PRNG_SEED	 0x0528, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_Y_PRNG_SEED */
	#define BLSB_DPE_FGT_Y_PRNG_SEED_PRNG_Y_Seed	0
	/* Register Bit Widths for DPE_FGT_Y_PRNG_SEED */
	#define BWID_DPE_FGT_Y_PRNG_SEED_PRNG_Y_Seed	32
	/* Register Bit MASKS for DPE_FGT_Y_PRNG_SEED */
	#define BMSK_DPE_FGT_Y_PRNG_SEED_PRNG_Y_Seed	0x00000000 /*  */
	/* Register BITFIELD for DPE_FGT_Y_PRNG_SEED - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_Y_PRNG_SEED_PRNG_Y_Seed	 0x0528, 0, 32, 0x00000000
#define ROFF_DPE_FGT_U_PRNG_SEED	0x52c /* FGT PRNG seed value of the current stride for U component */ 
	#define BITFIELD_DPE_FGT_U_PRNG_SEED	 0x052c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_U_PRNG_SEED */
	#define BLSB_DPE_FGT_U_PRNG_SEED_PRNG_U_Seed	0
	/* Register Bit Widths for DPE_FGT_U_PRNG_SEED */
	#define BWID_DPE_FGT_U_PRNG_SEED_PRNG_U_Seed	32
	/* Register Bit MASKS for DPE_FGT_U_PRNG_SEED */
	#define BMSK_DPE_FGT_U_PRNG_SEED_PRNG_U_Seed	0x00000000 /*  */
	/* Register BITFIELD for DPE_FGT_U_PRNG_SEED - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_U_PRNG_SEED_PRNG_U_Seed	 0x052c, 0, 32, 0x00000000
#define ROFF_DPE_FGT_V_PRNG_SEED	0x530 /* FGT PRNG seed value of the current stride for V component */ 
	#define BITFIELD_DPE_FGT_V_PRNG_SEED	 0x0530, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_V_PRNG_SEED */
	#define BLSB_DPE_FGT_V_PRNG_SEED_PRNG_V_Seed	0
	/* Register Bit Widths for DPE_FGT_V_PRNG_SEED */
	#define BWID_DPE_FGT_V_PRNG_SEED_PRNG_V_Seed	32
	/* Register Bit MASKS for DPE_FGT_V_PRNG_SEED */
	#define BMSK_DPE_FGT_V_PRNG_SEED_PRNG_V_Seed	0x00000000 /*  */
	/* Register BITFIELD for DPE_FGT_V_PRNG_SEED - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_V_PRNG_SEED_PRNG_V_Seed	 0x0530, 0, 32, 0x00000000
#define ROFF_DPE_FGT_Y_NP_Parameter_Table	0x600 /* There are 256 registers that stores the noise-pattern parameters like the offset in NP cache and scaling factor for each possible value of 8X8 block */ 
	#define BITFIELD_DPE_FGT_Y_NP_Parameter_Table	 0x0600, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_Y_NP_Parameter_Table */
	#define BLSB_DPE_FGT_Y_NP_Parameter_Table_bypass_fgt	12
	#define BLSB_DPE_FGT_Y_NP_Parameter_Table_comp_model_value	4
	#define BLSB_DPE_FGT_Y_NP_Parameter_Table_np_cache_offset	0
	/* Register Bit Widths for DPE_FGT_Y_NP_Parameter_Table */
	#define BWID_DPE_FGT_Y_NP_Parameter_Table_bypass_fgt	1
	#define BWID_DPE_FGT_Y_NP_Parameter_Table_comp_model_value	8
	#define BWID_DPE_FGT_Y_NP_Parameter_Table_np_cache_offset	4
	/* Register Bit MASKS for DPE_FGT_Y_NP_Parameter_Table */
	#define BMSK_DPE_FGT_Y_NP_Parameter_Table_bypass_fgt	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_FGT_Y_NP_Parameter_Table_comp_model_value	0x00000ff0 /*  */
	#define BMSK_DPE_FGT_Y_NP_Parameter_Table_np_cache_offset	0x0000000f /*  */
	/* Register BITFIELD for DPE_FGT_Y_NP_Parameter_Table - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_Y_NP_Parameter_Table_bypass_fgt	 0x0600, 12, 1, 0x00001000
	#define BITFIELD_DPE_FGT_Y_NP_Parameter_Table_comp_model_value	 0x0600, 4, 8, 0x00000ff0
	#define BITFIELD_DPE_FGT_Y_NP_Parameter_Table_np_cache_offset	 0x0600, 0, 4, 0x0000000f
#define ROFF_DPE_FGT_U_NP_Parameter_Table	0xa00 /* There are 256 registers that stores the noise-pattern parameters like the offset in NP cache and scaling factor for each possible value of 8X8 block */ 
	#define BITFIELD_DPE_FGT_U_NP_Parameter_Table	 0x0a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_U_NP_Parameter_Table */
	#define BLSB_DPE_FGT_U_NP_Parameter_Table_bypass_fgt	12
	#define BLSB_DPE_FGT_U_NP_Parameter_Table_comp_model_value	4
	#define BLSB_DPE_FGT_U_NP_Parameter_Table_np_cache_offset	0
	/* Register Bit Widths for DPE_FGT_U_NP_Parameter_Table */
	#define BWID_DPE_FGT_U_NP_Parameter_Table_bypass_fgt	1
	#define BWID_DPE_FGT_U_NP_Parameter_Table_comp_model_value	8
	#define BWID_DPE_FGT_U_NP_Parameter_Table_np_cache_offset	4
	/* Register Bit MASKS for DPE_FGT_U_NP_Parameter_Table */
	#define BMSK_DPE_FGT_U_NP_Parameter_Table_bypass_fgt	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_FGT_U_NP_Parameter_Table_comp_model_value	0x00000ff0 /*  */
	#define BMSK_DPE_FGT_U_NP_Parameter_Table_np_cache_offset	0x0000000f /*  */
	/* Register BITFIELD for DPE_FGT_U_NP_Parameter_Table - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_U_NP_Parameter_Table_bypass_fgt	 0x0a00, 12, 1, 0x00001000
	#define BITFIELD_DPE_FGT_U_NP_Parameter_Table_comp_model_value	 0x0a00, 4, 8, 0x00000ff0
	#define BITFIELD_DPE_FGT_U_NP_Parameter_Table_np_cache_offset	 0x0a00, 0, 4, 0x0000000f
#define ROFF_DPE_FGT_V_NP_Parameter_Table	0xe00 /* There are 256 registers that stores the noise-pattern parameters like the offset in NP cache and scaling factor for each possible value of 8X8 block */ 
	#define BITFIELD_DPE_FGT_V_NP_Parameter_Table	 0x0e00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_FGT_V_NP_Parameter_Table */
	#define BLSB_DPE_FGT_V_NP_Parameter_Table_bypass_fgt	12
	#define BLSB_DPE_FGT_V_NP_Parameter_Table_comp_model_value	4
	#define BLSB_DPE_FGT_V_NP_Parameter_Table_np_cache_offset	0
	/* Register Bit Widths for DPE_FGT_V_NP_Parameter_Table */
	#define BWID_DPE_FGT_V_NP_Parameter_Table_bypass_fgt	1
	#define BWID_DPE_FGT_V_NP_Parameter_Table_comp_model_value	8
	#define BWID_DPE_FGT_V_NP_Parameter_Table_np_cache_offset	4
	/* Register Bit MASKS for DPE_FGT_V_NP_Parameter_Table */
	#define BMSK_DPE_FGT_V_NP_Parameter_Table_bypass_fgt	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_FGT_V_NP_Parameter_Table_comp_model_value	0x00000ff0 /*  */
	#define BMSK_DPE_FGT_V_NP_Parameter_Table_np_cache_offset	0x0000000f /*  */
	/* Register BITFIELD for DPE_FGT_V_NP_Parameter_Table - roff, lsb, width, mask */
	#define BITFIELD_DPE_FGT_V_NP_Parameter_Table_bypass_fgt	 0x0e00, 12, 1, 0x00001000
	#define BITFIELD_DPE_FGT_V_NP_Parameter_Table_comp_model_value	 0x0e00, 4, 8, 0x00000ff0
	#define BITFIELD_DPE_FGT_V_NP_Parameter_Table_np_cache_offset	 0x0e00, 0, 4, 0x0000000f
#define ROFF_DPE_HSC_STRIDE_HEIGHT	0x2000 /* Stride height configuration */ 
	#define BITFIELD_DPE_HSC_STRIDE_HEIGHT	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_STRIDE_HEIGHT */
	#define BLSB_DPE_HSC_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_HSC_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_HSC_STRIDE_HEIGHT */
	#define BWID_DPE_HSC_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_HSC_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_HSC_STRIDE_HEIGHT */
	#define BMSK_DPE_HSC_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_HSC_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_HSC_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_STRIDE_HEIGHT_num_strides	 0x2000, 12, 4, 0x0000f000
	#define BITFIELD_DPE_HSC_STRIDE_HEIGHT_stride_h	 0x2000, 0, 11, 0x000007ff
#define ROFF_DPE_HSC_STRIDE_WIDTH	0x2004 /* Stride width configuration */ 
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH	 0x2004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_STRIDE_WIDTH */
	#define BLSB_DPE_HSC_STRIDE_WIDTH_next_rd_offset_x	27
	#define BLSB_DPE_HSC_STRIDE_WIDTH_pix_coord_x	16
	#define BLSB_DPE_HSC_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_HSC_STRIDE_WIDTH_RM	6
	#define BLSB_DPE_HSC_STRIDE_WIDTH_LM	5
	#define BLSB_DPE_HSC_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_HSC_STRIDE_WIDTH */
	#define BWID_DPE_HSC_STRIDE_WIDTH_next_rd_offset_x	5
	#define BWID_DPE_HSC_STRIDE_WIDTH_pix_coord_x	11
	#define BWID_DPE_HSC_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_HSC_STRIDE_WIDTH_RM	1
	#define BWID_DPE_HSC_STRIDE_WIDTH_LM	1
	#define BWID_DPE_HSC_STRIDE_WIDTH_in_stride_off	5
	/* Register Bit MASKS for DPE_HSC_STRIDE_WIDTH */
	#define BMSK_DPE_HSC_STRIDE_WIDTH_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_HSC_STRIDE_WIDTH_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_HSC_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_HSC_STRIDE_WIDTH_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_HSC_STRIDE_WIDTH_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_HSC_STRIDE_WIDTH_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_HSC_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH_next_rd_offset_x	 0x2004, 27, 5, 0xf8000000
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH_pix_coord_x	 0x2004, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH_out_stride_w	 0x2004, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH_RM	 0x2004, 6, 1, 0x00000040
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH_LM	 0x2004, 5, 1, 0x00000020
	#define BITFIELD_DPE_HSC_STRIDE_WIDTH_in_stride_off	 0x2004, 0, 5, 0x0000001f
#define ROFF_DPE_HSC_STRIDE_SCALING_PARAMS1	0x2008 /* Stride scaling params1 for the current stride */ 
	#define BITFIELD_DPE_HSC_STRIDE_SCALING_PARAMS1	 0x2008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_STRIDE_SCALING_PARAMS1 */
	#define BLSB_DPE_HSC_STRIDE_SCALING_PARAMS1_In_stride_w	20
	#define BLSB_DPE_HSC_STRIDE_SCALING_PARAMS1_SIP	0
	/* Register Bit Widths for DPE_HSC_STRIDE_SCALING_PARAMS1 */
	#define BWID_DPE_HSC_STRIDE_SCALING_PARAMS1_In_stride_w	9
	#define BWID_DPE_HSC_STRIDE_SCALING_PARAMS1_SIP	17
	/* Register Bit MASKS for DPE_HSC_STRIDE_SCALING_PARAMS1 */
	#define BMSK_DPE_HSC_STRIDE_SCALING_PARAMS1_In_stride_w	0x1ff00000 /*  */
	#define BMSK_DPE_HSC_STRIDE_SCALING_PARAMS1_SIP	0x0001ffff /*  */
	/* Register BITFIELD for DPE_HSC_STRIDE_SCALING_PARAMS1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_STRIDE_SCALING_PARAMS1_In_stride_w	 0x2008, 20, 9, 0x1ff00000
	#define BITFIELD_DPE_HSC_STRIDE_SCALING_PARAMS1_SIP	 0x2008, 0, 17, 0x0001ffff
#define ROFF_DPE_HSC_STRIDE_SCALING_PARAMS2	0x200c /* Stride scaling params2 for the current stride */ 
	#define BITFIELD_DPE_HSC_STRIDE_SCALING_PARAMS2	 0x200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_STRIDE_SCALING_PARAMS2 */
	#define BLSB_DPE_HSC_STRIDE_SCALING_PARAMS2_SISF	0
	/* Register Bit Widths for DPE_HSC_STRIDE_SCALING_PARAMS2 */
	#define BWID_DPE_HSC_STRIDE_SCALING_PARAMS2_SISF	21
	/* Register Bit MASKS for DPE_HSC_STRIDE_SCALING_PARAMS2 */
	#define BMSK_DPE_HSC_STRIDE_SCALING_PARAMS2_SISF	0x001fffff /*  */
	/* Register BITFIELD for DPE_HSC_STRIDE_SCALING_PARAMS2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_STRIDE_SCALING_PARAMS2_SISF	 0x200c, 0, 21, 0x001fffff
#define ROFF_DPE_HSC_PREV_BLOCK_PARAMS	0x2020 /* Pixel Data Block Size and Offset parameters for previous block in pipeline */ 
	#define BITFIELD_DPE_HSC_PREV_BLOCK_PARAMS	 0x2020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_PREV_BLOCK_PARAMS */
	#define BLSB_DPE_HSC_PREV_BLOCK_PARAMS_prev_wr_y	0
	/* Register Bit Widths for DPE_HSC_PREV_BLOCK_PARAMS */
	#define BWID_DPE_HSC_PREV_BLOCK_PARAMS_prev_wr_y	5
	/* Register Bit MASKS for DPE_HSC_PREV_BLOCK_PARAMS */
	#define BMSK_DPE_HSC_PREV_BLOCK_PARAMS_prev_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_HSC_PREV_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_PREV_BLOCK_PARAMS_prev_wr_y	 0x2020, 0, 5, 0x0000001f
#define ROFF_DPE_HSC_NEXT_BLOCK_PARAMS	0x2024 /* Pixel Data Block Size and Offset parameters for next block in pipeline */ 
	#define BITFIELD_DPE_HSC_NEXT_BLOCK_PARAMS	 0x2024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_HSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	/* Register Bit Widths for DPE_HSC_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_HSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	/* Register Bit MASKS for DPE_HSC_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_HSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	/* Register BITFIELD for DPE_HSC_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x2024, 8, 5, 0x00001f00
#define ROFF_DPE_HSC_CONTROL	0x2040 /* Control/Configuration register for the unit */ 
	#define BITFIELD_DPE_HSC_CONTROL	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_CONTROL */
	#define BLSB_DPE_HSC_CONTROL_adp_en	31
	#define BLSB_DPE_HSC_CONTROL_dering_en	4
	#define BLSB_DPE_HSC_CONTROL_bank_sel	2
	#define BLSB_DPE_HSC_CONTROL_en	0
	/* Register Bit Widths for DPE_HSC_CONTROL */
	#define BWID_DPE_HSC_CONTROL_adp_en	1
	#define BWID_DPE_HSC_CONTROL_dering_en	1
	#define BWID_DPE_HSC_CONTROL_bank_sel	1
	#define BWID_DPE_HSC_CONTROL_en	1
	/* Register Bit MASKS for DPE_HSC_CONTROL */
	#define BMSK_DPE_HSC_CONTROL_adp_en	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_HSC_CONTROL_dering_en	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_HSC_CONTROL_bank_sel	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_HSC_CONTROL_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_HSC_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_CONTROL_adp_en	 0x2040, 31, 1, 0x80000000
	#define BITFIELD_DPE_HSC_CONTROL_dering_en	 0x2040, 4, 1, 0x00000010
	#define BITFIELD_DPE_HSC_CONTROL_bank_sel	 0x2040, 2, 1, 0x00000004
	#define BITFIELD_DPE_HSC_CONTROL_en	 0x2040, 0, 1, 0x00000001
#define ROFF_DPE_HSC_PHASE_CONFIG	0x2044 /* Total number of phases */ 
	#define BITFIELD_DPE_HSC_PHASE_CONFIG	 0x2044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_PHASE_CONFIG */
	#define BLSB_DPE_HSC_PHASE_CONFIG_SIP	8
	#define BLSB_DPE_HSC_PHASE_CONFIG_TNP	0
	/* Register Bit Widths for DPE_HSC_PHASE_CONFIG */
	#define BWID_DPE_HSC_PHASE_CONFIG_SIP	16
	#define BWID_DPE_HSC_PHASE_CONFIG_TNP	8
	/* Register Bit MASKS for DPE_HSC_PHASE_CONFIG */
	#define BMSK_DPE_HSC_PHASE_CONFIG_SIP	0x00ffff00 /*  */
	#define BMSK_DPE_HSC_PHASE_CONFIG_TNP	0x000000ff /*  */
	/* Register BITFIELD for DPE_HSC_PHASE_CONFIG - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_PHASE_CONFIG_SIP	 0x2044, 8, 16, 0x00ffff00
	#define BITFIELD_DPE_HSC_PHASE_CONFIG_TNP	 0x2044, 0, 8, 0x000000ff
#define ROFF_DPE_HSC_REGION1_START_VALUE	0x2048 /* Start parameter for region 1 */ 
	#define BITFIELD_DPE_HSC_REGION1_START_VALUE	 0x2048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_REGION1_START_VALUE */
	#define BLSB_DPE_HSC_REGION1_START_VALUE_SISF	0
	/* Register Bit Widths for DPE_HSC_REGION1_START_VALUE */
	#define BWID_DPE_HSC_REGION1_START_VALUE_SISF	21
	/* Register Bit MASKS for DPE_HSC_REGION1_START_VALUE */
	#define BMSK_DPE_HSC_REGION1_START_VALUE_SISF	0x001fffff /*  */
	/* Register BITFIELD for DPE_HSC_REGION1_START_VALUE - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_REGION1_START_VALUE_SISF	 0x2048, 0, 21, 0x001fffff
#define ROFF_DPE_HSC_REGION1_SCALE_INCR	0x204c /* Inverse scale factor increment for region 1 */ 
	#define BITFIELD_DPE_HSC_REGION1_SCALE_INCR	 0x204c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_REGION1_SCALE_INCR */
	#define BLSB_DPE_HSC_REGION1_SCALE_INCR_PC	20
	#define BLSB_DPE_HSC_REGION1_SCALE_INCR_ISF_INCR	0
	/* Register Bit Widths for DPE_HSC_REGION1_SCALE_INCR */
	#define BWID_DPE_HSC_REGION1_SCALE_INCR_PC	11
	#define BWID_DPE_HSC_REGION1_SCALE_INCR_ISF_INCR	17
	/* Register Bit MASKS for DPE_HSC_REGION1_SCALE_INCR */
	#define BMSK_DPE_HSC_REGION1_SCALE_INCR_PC	0x7ff00000 /*  */
	#define BMSK_DPE_HSC_REGION1_SCALE_INCR_ISF_INCR	0x0001ffff /*  */
	/* Register BITFIELD for DPE_HSC_REGION1_SCALE_INCR - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_REGION1_SCALE_INCR_PC	 0x204c, 20, 11, 0x7ff00000
	#define BITFIELD_DPE_HSC_REGION1_SCALE_INCR_ISF_INCR	 0x204c, 0, 17, 0x0001ffff
#define ROFF_DPE_HSC_REGION2_START_VALUE	0x2050 /* Start parameter for region 2 */ 
	#define BITFIELD_DPE_HSC_REGION2_START_VALUE	 0x2050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_REGION2_START_VALUE */
	#define BLSB_DPE_HSC_REGION2_START_VALUE_SISF	0
	/* Register Bit Widths for DPE_HSC_REGION2_START_VALUE */
	#define BWID_DPE_HSC_REGION2_START_VALUE_SISF	21
	/* Register Bit MASKS for DPE_HSC_REGION2_START_VALUE */
	#define BMSK_DPE_HSC_REGION2_START_VALUE_SISF	0x001fffff /*  */
	/* Register BITFIELD for DPE_HSC_REGION2_START_VALUE - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_REGION2_START_VALUE_SISF	 0x2050, 0, 21, 0x001fffff
#define ROFF_DPE_HSC_REGION2_SCALE_INCR	0x2054 /* Inverse scale factor increment for region 2 */ 
	#define BITFIELD_DPE_HSC_REGION2_SCALE_INCR	 0x2054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_REGION2_SCALE_INCR */
	#define BLSB_DPE_HSC_REGION2_SCALE_INCR_PC	20
	#define BLSB_DPE_HSC_REGION2_SCALE_INCR_ISF_INCR	0
	/* Register Bit Widths for DPE_HSC_REGION2_SCALE_INCR */
	#define BWID_DPE_HSC_REGION2_SCALE_INCR_PC	11
	#define BWID_DPE_HSC_REGION2_SCALE_INCR_ISF_INCR	17
	/* Register Bit MASKS for DPE_HSC_REGION2_SCALE_INCR */
	#define BMSK_DPE_HSC_REGION2_SCALE_INCR_PC	0x7ff00000 /*  */
	#define BMSK_DPE_HSC_REGION2_SCALE_INCR_ISF_INCR	0x0001ffff /*  */
	/* Register BITFIELD for DPE_HSC_REGION2_SCALE_INCR - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_REGION2_SCALE_INCR_PC	 0x2054, 20, 11, 0x7ff00000
	#define BITFIELD_DPE_HSC_REGION2_SCALE_INCR_ISF_INCR	 0x2054, 0, 17, 0x0001ffff
#define ROFF_DPE_HSC_REGION3_START_VALUE	0x2058 /* Start parameter for region 3 */ 
	#define BITFIELD_DPE_HSC_REGION3_START_VALUE	 0x2058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_REGION3_START_VALUE */
	#define BLSB_DPE_HSC_REGION3_START_VALUE_SISF	0
	/* Register Bit Widths for DPE_HSC_REGION3_START_VALUE */
	#define BWID_DPE_HSC_REGION3_START_VALUE_SISF	21
	/* Register Bit MASKS for DPE_HSC_REGION3_START_VALUE */
	#define BMSK_DPE_HSC_REGION3_START_VALUE_SISF	0x001fffff /*  */
	/* Register BITFIELD for DPE_HSC_REGION3_START_VALUE - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_REGION3_START_VALUE_SISF	 0x2058, 0, 21, 0x001fffff
#define ROFF_DPE_HSC_REGION3_SCALE_INCR	0x205c /* Inverse scale factor increment for region 3 */ 
	#define BITFIELD_DPE_HSC_REGION3_SCALE_INCR	 0x205c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_HSC_REGION3_SCALE_INCR */
	#define BLSB_DPE_HSC_REGION3_SCALE_INCR_PC	20
	#define BLSB_DPE_HSC_REGION3_SCALE_INCR_ISF_INCR	0
	/* Register Bit Widths for DPE_HSC_REGION3_SCALE_INCR */
	#define BWID_DPE_HSC_REGION3_SCALE_INCR_PC	11
	#define BWID_DPE_HSC_REGION3_SCALE_INCR_ISF_INCR	17
	/* Register Bit MASKS for DPE_HSC_REGION3_SCALE_INCR */
	#define BMSK_DPE_HSC_REGION3_SCALE_INCR_PC	0x7ff00000 /*  */
	#define BMSK_DPE_HSC_REGION3_SCALE_INCR_ISF_INCR	0x0001ffff /*  */
	/* Register BITFIELD for DPE_HSC_REGION3_SCALE_INCR - roff, lsb, width, mask */
	#define BITFIELD_DPE_HSC_REGION3_SCALE_INCR_PC	 0x205c, 20, 11, 0x7ff00000
	#define BITFIELD_DPE_HSC_REGION3_SCALE_INCR_ISF_INCR	 0x205c, 0, 17, 0x0001ffff
#define ROFF_DPE_HSC_Y_POLY_COEFF_BANK0	0x2400 /* Y polyphase coefficient memory Bank 0 */ 
	#define BITFIELD_DPE_HSC_Y_POLY_COEFF_BANK0	 0x2400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_HSC_Y_POLY_COEFF_BANK1	0x2800 /* Y polyphase coefficient memory Bank 1 */ 
	#define BITFIELD_DPE_HSC_Y_POLY_COEFF_BANK1	 0x2800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_HSC_UV_POLY_COEFF_BANK0	0x2c00 /* UV polyphase coefficient memory Bank 0 */ 
	#define BITFIELD_DPE_HSC_UV_POLY_COEFF_BANK0	 0x2c00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_HSC_UV_POLY_COEFF_BANK1	0x2e00 /* UV polyphase coefficient memory Bank 1 */ 
	#define BITFIELD_DPE_HSC_UV_POLY_COEFF_BANK1	 0x2e00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_VSC_STRIDE_HEIGHT	0x3000 /* Stride height configuration */ 
	#define BITFIELD_DPE_VSC_STRIDE_HEIGHT	 0x3000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_STRIDE_HEIGHT */
	#define BLSB_DPE_VSC_STRIDE_HEIGHT_out_stride_h	16
	#define BLSB_DPE_VSC_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_VSC_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_VSC_STRIDE_HEIGHT */
	#define BWID_DPE_VSC_STRIDE_HEIGHT_out_stride_h	11
	#define BWID_DPE_VSC_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_VSC_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_VSC_STRIDE_HEIGHT */
	#define BMSK_DPE_VSC_STRIDE_HEIGHT_out_stride_h	0x07ff0000 /*  */
	#define BMSK_DPE_VSC_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_VSC_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_VSC_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_STRIDE_HEIGHT_out_stride_h	 0x3000, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_VSC_STRIDE_HEIGHT_num_strides	 0x3000, 12, 4, 0x0000f000
	#define BITFIELD_DPE_VSC_STRIDE_HEIGHT_stride_h	 0x3000, 0, 11, 0x000007ff
#define ROFF_DPE_VSC_STRIDE_WIDTH	0x3004 /* Stride width configuration */ 
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH	 0x3004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_STRIDE_WIDTH */
	#define BLSB_DPE_VSC_STRIDE_WIDTH_next_rd_offset_x	27
	#define BLSB_DPE_VSC_STRIDE_WIDTH_pix_coord_x	16
	#define BLSB_DPE_VSC_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_VSC_STRIDE_WIDTH_RM	6
	#define BLSB_DPE_VSC_STRIDE_WIDTH_LM	5
	#define BLSB_DPE_VSC_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_VSC_STRIDE_WIDTH */
	#define BWID_DPE_VSC_STRIDE_WIDTH_next_rd_offset_x	5
	#define BWID_DPE_VSC_STRIDE_WIDTH_pix_coord_x	11
	#define BWID_DPE_VSC_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_VSC_STRIDE_WIDTH_RM	1
	#define BWID_DPE_VSC_STRIDE_WIDTH_LM	1
	#define BWID_DPE_VSC_STRIDE_WIDTH_in_stride_off	5
	/* Register Bit MASKS for DPE_VSC_STRIDE_WIDTH */
	#define BMSK_DPE_VSC_STRIDE_WIDTH_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_VSC_STRIDE_WIDTH_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_VSC_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_VSC_STRIDE_WIDTH_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_VSC_STRIDE_WIDTH_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_VSC_STRIDE_WIDTH_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_VSC_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH_next_rd_offset_x	 0x3004, 27, 5, 0xf8000000
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH_pix_coord_x	 0x3004, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH_out_stride_w	 0x3004, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH_RM	 0x3004, 6, 1, 0x00000040
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH_LM	 0x3004, 5, 1, 0x00000020
	#define BITFIELD_DPE_VSC_STRIDE_WIDTH_in_stride_off	 0x3004, 0, 5, 0x0000001f
#define ROFF_DPE_VSC_PREV_BLOCK_PARAMS	0x3020 /* Pixel Data Block Size and Offset parameters for previous block in pipeline */ 
	#define BITFIELD_DPE_VSC_PREV_BLOCK_PARAMS	 0x3020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_PREV_BLOCK_PARAMS */
	#define BLSB_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_offset_y	8
	#define BLSB_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_VSC_PREV_BLOCK_PARAMS */
	#define BWID_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_offset_y	5
	#define BWID_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_VSC_PREV_BLOCK_PARAMS */
	#define BMSK_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_VSC_PREV_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_offset_y	 0x3020, 8, 5, 0x00001f00
	#define BITFIELD_DPE_VSC_PREV_BLOCK_PARAMS_next_wr_y	 0x3020, 0, 5, 0x0000001f
#define ROFF_DPE_VSC_NEXT_BLOCK_PARAMS	0x3024 /* Pixel Data Block Size and Offset parameters for next block in pipeline */ 
	#define BITFIELD_DPE_VSC_NEXT_BLOCK_PARAMS	 0x3024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_VSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_VSC_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_VSC_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_VSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_VSC_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_VSC_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_VSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_VSC_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_VSC_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x3024, 8, 5, 0x00001f00
	#define BITFIELD_DPE_VSC_NEXT_BLOCK_PARAMS_next_wr_y	 0x3024, 0, 5, 0x0000001f
#define ROFF_DPE_VSC_IN_FIFO_PARAMS1	0x3028 /* Shared Memory Input FIFO parameters */ 
	#define BITFIELD_DPE_VSC_IN_FIFO_PARAMS1	 0x3028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_IN_FIFO_PARAMS1 */
	#define BLSB_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_startaddr	12
	#define BLSB_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_width	0
	/* Register Bit Widths for DPE_VSC_IN_FIFO_PARAMS1 */
	#define BWID_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_startaddr	18
	#define BWID_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_width	9
	/* Register Bit MASKS for DPE_VSC_IN_FIFO_PARAMS1 */
	#define BMSK_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_startaddr	0x3ffff000 /*  */
	#define BMSK_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_width	0x000001ff /*  */
	/* Register BITFIELD for DPE_VSC_IN_FIFO_PARAMS1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_startaddr	 0x3028, 12, 18, 0x3ffff000
	#define BITFIELD_DPE_VSC_IN_FIFO_PARAMS1_In_fifo_width	 0x3028, 0, 9, 0x000001ff
#define ROFF_DPE_VSC_IN_FIFO_PARAMS2	0x302c /* Shared Memory Input FIFO parameters */ 
	#define BITFIELD_DPE_VSC_IN_FIFO_PARAMS2	 0x302c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_IN_FIFO_PARAMS2 */
	#define BLSB_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_size	8
	#define BLSB_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_height	0
	/* Register Bit Widths for DPE_VSC_IN_FIFO_PARAMS2 */
	#define BWID_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_size	15
	#define BWID_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_height	6
	/* Register Bit MASKS for DPE_VSC_IN_FIFO_PARAMS2 */
	#define BMSK_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_size	0x007fff00 /*  */
	#define BMSK_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_height	0x0000003f /*  */
	/* Register BITFIELD for DPE_VSC_IN_FIFO_PARAMS2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_size	 0x302c, 8, 15, 0x007fff00
	#define BITFIELD_DPE_VSC_IN_FIFO_PARAMS2_In_fifo_height	 0x302c, 0, 6, 0x0000003f
#define ROFF_DPE_VSC_OUT_FIFO_PARAMS1	0x3030 /* Shared Memory Output FIFO parameters */ 
	#define BITFIELD_DPE_VSC_OUT_FIFO_PARAMS1	 0x3030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_OUT_FIFO_PARAMS1 */
	#define BLSB_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_startaddr	12
	#define BLSB_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_width	0
	/* Register Bit Widths for DPE_VSC_OUT_FIFO_PARAMS1 */
	#define BWID_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_startaddr	18
	#define BWID_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_width	9
	/* Register Bit MASKS for DPE_VSC_OUT_FIFO_PARAMS1 */
	#define BMSK_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_startaddr	0x3ffff000 /*  */
	#define BMSK_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_width	0x000001ff /*  */
	/* Register BITFIELD for DPE_VSC_OUT_FIFO_PARAMS1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_startaddr	 0x3030, 12, 18, 0x3ffff000
	#define BITFIELD_DPE_VSC_OUT_FIFO_PARAMS1_Out_fifo_width	 0x3030, 0, 9, 0x000001ff
#define ROFF_DPE_VSC_OUT_FIFO_PARAMS2	0x3034 /* Shared Memory Output FIFO parameters */ 
	#define BITFIELD_DPE_VSC_OUT_FIFO_PARAMS2	 0x3034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_OUT_FIFO_PARAMS2 */
	#define BLSB_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_size	8
	#define BLSB_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_height	0
	/* Register Bit Widths for DPE_VSC_OUT_FIFO_PARAMS2 */
	#define BWID_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_size	15
	#define BWID_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_height	6
	/* Register Bit MASKS for DPE_VSC_OUT_FIFO_PARAMS2 */
	#define BMSK_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_size	0x007fff00 /*  */
	#define BMSK_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_height	0x0000003f /*  */
	/* Register BITFIELD for DPE_VSC_OUT_FIFO_PARAMS2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_size	 0x3034, 8, 15, 0x007fff00
	#define BITFIELD_DPE_VSC_OUT_FIFO_PARAMS2_Out_fifo_height	 0x3034, 0, 6, 0x0000003f
#define ROFF_DPE_VSC_CONTROL	0x3040 /* Control/Configuration register for the unit */ 
	#define BITFIELD_DPE_VSC_CONTROL	 0x3040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_CONTROL */
	#define BLSB_DPE_VSC_CONTROL_adp_en	31
	#define BLSB_DPE_VSC_CONTROL_DI_LPF_assist	7
	#define BLSB_DPE_VSC_CONTROL_UV_420_422_en	5
	#define BLSB_DPE_VSC_CONTROL_dering_en	4
	#define BLSB_DPE_VSC_CONTROL_pic_done	3
	#define BLSB_DPE_VSC_CONTROL_bank_sel	2
	#define BLSB_DPE_VSC_CONTROL_bypass	1
	#define BLSB_DPE_VSC_CONTROL_en	0
	/* Register Bit Widths for DPE_VSC_CONTROL */
	#define BWID_DPE_VSC_CONTROL_adp_en	1
	#define BWID_DPE_VSC_CONTROL_DI_LPF_assist	1
	#define BWID_DPE_VSC_CONTROL_UV_420_422_en	1
	#define BWID_DPE_VSC_CONTROL_dering_en	1
	#define BWID_DPE_VSC_CONTROL_pic_done	1
	#define BWID_DPE_VSC_CONTROL_bank_sel	1
	#define BWID_DPE_VSC_CONTROL_bypass	1
	#define BWID_DPE_VSC_CONTROL_en	1
	/* Register Bit MASKS for DPE_VSC_CONTROL */
	#define BMSK_DPE_VSC_CONTROL_adp_en	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_VSC_CONTROL_DI_LPF_assist	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_VSC_CONTROL_UV_420_422_en	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_VSC_CONTROL_dering_en	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_VSC_CONTROL_pic_done	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_VSC_CONTROL_bank_sel	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_VSC_CONTROL_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_VSC_CONTROL_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_VSC_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_CONTROL_adp_en	 0x3040, 31, 1, 0x80000000
	#define BITFIELD_DPE_VSC_CONTROL_DI_LPF_assist	 0x3040, 7, 1, 0x00000080
	#define BITFIELD_DPE_VSC_CONTROL_UV_420_422_en	 0x3040, 5, 1, 0x00000020
	#define BITFIELD_DPE_VSC_CONTROL_dering_en	 0x3040, 4, 1, 0x00000010
	#define BITFIELD_DPE_VSC_CONTROL_pic_done	 0x3040, 3, 1, 0x00000008
	#define BITFIELD_DPE_VSC_CONTROL_bank_sel	 0x3040, 2, 1, 0x00000004
	#define BITFIELD_DPE_VSC_CONTROL_bypass	 0x3040, 1, 1, 0x00000002
	#define BITFIELD_DPE_VSC_CONTROL_en	 0x3040, 0, 1, 0x00000001
#define ROFF_DPE_VSC_SCALE_FACTOR	0x3044 /* Inverse scale factor value */ 
	#define BITFIELD_DPE_VSC_SCALE_FACTOR	 0x3044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_SCALE_FACTOR */
	#define BLSB_DPE_VSC_SCALE_FACTOR_ISF	0
	/* Register Bit Widths for DPE_VSC_SCALE_FACTOR */
	#define BWID_DPE_VSC_SCALE_FACTOR_ISF	21
	/* Register Bit MASKS for DPE_VSC_SCALE_FACTOR */
	#define BMSK_DPE_VSC_SCALE_FACTOR_ISF	0x001fffff /*  */
	/* Register BITFIELD for DPE_VSC_SCALE_FACTOR - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_SCALE_FACTOR_ISF	 0x3044, 0, 21, 0x001fffff
#define ROFF_DPE_VSC_PHASE_CONFIG	0x3048 /* Phase configuration parameters including number of phases and initial phase */ 
	#define BITFIELD_DPE_VSC_PHASE_CONFIG	 0x3048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_VSC_PHASE_CONFIG */
	#define BLSB_DPE_VSC_PHASE_CONFIG_SIP	8
	#define BLSB_DPE_VSC_PHASE_CONFIG_TNP	0
	/* Register Bit Widths for DPE_VSC_PHASE_CONFIG */
	#define BWID_DPE_VSC_PHASE_CONFIG_SIP	20
	#define BWID_DPE_VSC_PHASE_CONFIG_TNP	8
	/* Register Bit MASKS for DPE_VSC_PHASE_CONFIG */
	#define BMSK_DPE_VSC_PHASE_CONFIG_SIP	0x0fffff00 /*  */
	#define BMSK_DPE_VSC_PHASE_CONFIG_TNP	0x000000ff /*  */
	/* Register BITFIELD for DPE_VSC_PHASE_CONFIG - roff, lsb, width, mask */
	#define BITFIELD_DPE_VSC_PHASE_CONFIG_SIP	 0x3048, 8, 20, 0x0fffff00
	#define BITFIELD_DPE_VSC_PHASE_CONFIG_TNP	 0x3048, 0, 8, 0x000000ff
#define ROFF_DPE_VSC_Y_POLY_COEFF_BANK0	0x3400 /* Y polyphase coefficient memory Bank 0 */ 
	#define BITFIELD_DPE_VSC_Y_POLY_COEFF_BANK0	 0x3400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_VSC_Y_POLY_COEFF_BANK1	0x3800 /* Y polyphase coefficient memory Bank 1 */ 
	#define BITFIELD_DPE_VSC_Y_POLY_COEFF_BANK1	 0x3800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_VSC_UV_POLY_COEFF_BANK0	0x3c00 /* UV polyphase coefficient memory Bank 0 */ 
	#define BITFIELD_DPE_VSC_UV_POLY_COEFF_BANK0	 0x3c00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_VSC_UV_POLY_COEFF_BANK1	0x3e00 /* UV polyphase coefficient memory Bank 1 */ 
	#define BITFIELD_DPE_VSC_UV_POLY_COEFF_BANK1	 0x3e00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT	0x1680 /* This register is used to set up the stride height and number of strides per frame */ 
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT	 0x1680, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT */
	#define BLSB_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT */
	#define BWID_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT */
	#define BMSK_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	 0x1680, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	 0x1680, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH	0x1684 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH	 0x1684, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH */
	#define BLSB_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH */
	#define BWID_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	6
	/* Register Bit MASKS for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH */
	#define BMSK_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	0x0000003f /*  */
	/* Register BITFIELD for DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	 0x1684, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	 0x1684, 0, 6, 0x0000003f
#define ROFF_DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER	0x1688 /* This register is used to enable/disable DWTA */ 
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER	 0x1688, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER_dwta_en	0
	/* Register Bit Widths for DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER_dwta_en	1
	/* Register Bit MASKS for DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER_dwta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_NP1_YUV_DMA_CONTROL_REGISTER_dwta_en	 0x1688, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT	0x1700 /* This register is used to set up the stride height and number of strides per frame */ 
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT	 0x1700, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT */
	#define BLSB_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT */
	#define BWID_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT */
	#define BMSK_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_num_strides	 0x1700, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_HEIGHT_stride_h	 0x1700, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH	0x1704 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH	 0x1704, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH */
	#define BLSB_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH */
	#define BWID_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_in_stride_off	6
	/* Register Bit MASKS for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH */
	#define BMSK_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_in_stride_off	0x0000003f /*  */
	/* Register BITFIELD for DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_out_stride_w	 0x1704, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_WRITE_STRIDE_WIDTH_in_stride_off	 0x1704, 0, 6, 0x0000003f
#define ROFF_DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER	0x1708 /* This register is used to enable/disable DWTA */ 
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER	 0x1708, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER_dwta_en	0
	/* Register Bit Widths for DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER_dwta_en	1
	/* Register Bit MASKS for DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER_dwta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_N_MH_DMA_CONTROL_REGISTER_dwta_en	 0x1708, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT	0x4100 /* This register is used to set up the stride height and number of strides per frame */ 
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT	 0x4100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT */
	#define BLSB_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	12
	#define BLSB_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	0
	/* Register Bit Widths for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT */
	#define BWID_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	4
	#define BWID_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT */
	#define BMSK_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_num_strides	 0x4100, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_HEIGHT_stride_h	 0x4100, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH	0x4104 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH	 0x4104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH */
	#define BLSB_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	7
	#define BLSB_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH */
	#define BWID_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	9
	#define BWID_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	6
	/* Register Bit MASKS for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH */
	#define BMSK_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	0x0000003f /*  */
	/* Register BITFIELD for DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_out_stride_w	 0x4104, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_WRITE_STRIDE_WIDTH_in_stride_off	 0x4104, 0, 6, 0x0000003f
#define ROFF_DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER	0x4108 /* This register is used to enable/disable DWTA */ 
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER	 0x4108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER_dwta_en	0
	/* Register Bit Widths for DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER_dwta_en	1
	/* Register Bit MASKS for DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER_dwta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DWTA_N_YUV_DMA_CONTROL_REGISTER_dwta_en	 0x4108, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER	0x200 /* This register is used to set up the stride height and number of strides per frame.  */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER	 0x0200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	12
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	4
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	 0x0200, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	 0x0200, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER	0x204 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER	 0x0204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	27
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	7
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_RM	6
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_LM	5
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	5
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	9
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_RM	1
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_LM	1
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	 0x0204, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	 0x0204, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_RM	 0x0204, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_LM	 0x0204, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	 0x0204, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER	0x20c /* This register is used to enable/disable DRTA */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER	 0x020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER_drta_en	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER_drta_en	1
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER_drta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_CONTROL_REGISTER_drta_en	 0x020c, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS	0x208 /* used to setup dma read data param */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS	 0x0208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x0208, 8, 5, 0x00001f00
	#define BITFIELD_DPE_DPE_DRTA_NP1_Y_DMA_NEXT_BLOCK_PARAMS_next_wr_y	 0x0208, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER	0x280 /* This register is used to set up the stride height and number of strides per frame.  */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER	 0x0280, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	12
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	4
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	 0x0280, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	 0x0280, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER	0x284 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER	 0x0284, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	27
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	7
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	6
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	5
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	5
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	9
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	1
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	1
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	 0x0284, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	 0x0284, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	 0x0284, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	 0x0284, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	 0x0284, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER	0x28c /* This register is used to enable/disable DRTA */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER	 0x028c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER_drta_en	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER_drta_en	1
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER_drta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_CONTROL_REGISTER_drta_en	 0x028c, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS	0x288 /* used to setup dma read data param */ 
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS	 0x0288, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x0288, 8, 5, 0x00001f00
	#define BITFIELD_DPE_DPE_DRTA_NP1_UV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	 0x0288, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER	0x1580 /* This register is used to set up the stride height and number of strides per frame.  */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER	 0x1580, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	12
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	4
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	 0x1580, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	 0x1580, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER	0x1584 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER	 0x1584, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	27
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	7
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	6
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	5
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	5
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	9
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	1
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	1
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	 0x1584, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	 0x1584, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	 0x1584, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	 0x1584, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	 0x1584, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER	0x158c /* This register is used to enable/disable DRTA */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER	 0x158c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER_drta_en	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER_drta_en	1
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER_drta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_CONTROL_REGISTER_drta_en	 0x158c, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS	0x1588 /* used to setup dma read data param */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS	 0x1588, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x1588, 8, 5, 0x00001f00
	#define BITFIELD_DPE_DPE_DRTA_NM1_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	 0x1588, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER	0x1500 /* This register is used to set up the stride height and number of strides per frame.  */ 
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER	 0x1500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	12
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0
	/* Register Bit Widths for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	4
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	 0x1500, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	 0x1500, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER	0x1504 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER	 0x1504, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	27
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	7
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	6
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	5
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	5
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	9
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	1
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	1
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	 0x1504, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	 0x1504, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_RM	 0x1504, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_LM	 0x1504, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	 0x1504, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER	0x150c /* This register is used to enable/disable DRTA */ 
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER	 0x150c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER_drta_en	0
	/* Register Bit Widths for DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER_drta_en	1
	/* Register Bit MASKS for DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER_drta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_CONTROL_REGISTER_drta_en	 0x150c, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS	0x1508 /* used to setup dma read data param */ 
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS	 0x1508, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x1508, 8, 5, 0x00001f00
	#define BITFIELD_DPE_DPE_DRTA_N_YUV_DMA_NEXT_BLOCK_PARAMS_next_wr_y	 0x1508, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER	0x1600 /* This register is used to set up the stride height and number of strides per frame.  */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER	 0x1600, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	12
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	4
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	11
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_num_strides	 0x1600, 12, 4, 0x0000f000
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_HEIGHT_REGISTER_stride_h	 0x1600, 0, 11, 0x000007ff
#define ROFF_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER	0x1604 /* This register is used to set up the input stride width, stride offset and output stride width */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER	 0x1604, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	27
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	7
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_RM	6
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_LM	5
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	5
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	9
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_RM	1
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_LM	1
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_next_rd_offset_x	 0x1604, 27, 5, 0xf8000000
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_out_stride_w	 0x1604, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_RM	 0x1604, 6, 1, 0x00000040
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_LM	 0x1604, 5, 1, 0x00000020
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_READ_STRIDE_WIDTH_REGISTER_in_stride_off	 0x1604, 0, 5, 0x0000001f
#define ROFF_DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER	0x160c /* This register is used to enable/disable DRTA */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER	 0x160c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER */
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER_drta_en	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER */
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER_drta_en	1
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER_drta_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_CONTROL_REGISTER_drta_en	 0x160c, 0, 1, 0x00000001
#define ROFF_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS	0x1608 /* used to setup dma read data param */ 
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS	 0x1608, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS */
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	8
	#define BLSB_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0
	/* Register Bit Widths for DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS */
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	5
	#define BWID_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_wr_y	5
	/* Register Bit MASKS for DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_rd_offset_y	 0x1608, 8, 5, 0x00001f00
	#define BITFIELD_DPE_DPE_DRTA_NM1_MH_DMA_NEXT_BLOCK_PARAMS_next_wr_y	 0x1608, 0, 5, 0x0000001f
#define ROFF_DPE_DMA_Mode_Register	0x6074 /* DMA_Mode_Register */ 
	#define BITFIELD_DPE_DMA_Mode_Register	 0x6074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_Mode_Register */
	#define BLSB_DPE_DMA_Mode_Register_N_ARGB_W_enable	15
	#define BLSB_DPE_DMA_Mode_Register_N_444_W_enable	14
	#define BLSB_DPE_DMA_Mode_Register_Dpe_dma_en	11
	#define BLSB_DPE_DMA_Mode_Register_N_YUV_W_en	10
	#define BLSB_DPE_DMA_Mode_Register_FG_R_enable	9
	#define BLSB_DPE_DMA_Mode_Register_N_MH_W_enable	8
	#define BLSB_DPE_DMA_Mode_Register_N_UV_W_enable	7
	#define BLSB_DPE_DMA_Mode_Register_N_Y_W_enable	6
	#define BLSB_DPE_DMA_Mode_Register_NP1_YUV_W_enable	5
	#define BLSB_DPE_DMA_Mode_Register_N_YUV_R_enable	4
	#define BLSB_DPE_DMA_Mode_Register_NM1_MH_R_enable	3
	#define BLSB_DPE_DMA_Mode_Register_NM1_YUV_R_enable	2
	#define BLSB_DPE_DMA_Mode_Register_NP1_UV_R_enable	1
	#define BLSB_DPE_DMA_Mode_Register_NP1_Y_R_enable	0
	/* Register Bit Widths for DPE_DMA_Mode_Register */
	#define BWID_DPE_DMA_Mode_Register_N_ARGB_W_enable	1
	#define BWID_DPE_DMA_Mode_Register_N_444_W_enable	1
	#define BWID_DPE_DMA_Mode_Register_Dpe_dma_en	1
	#define BWID_DPE_DMA_Mode_Register_N_YUV_W_en	1
	#define BWID_DPE_DMA_Mode_Register_FG_R_enable	1
	#define BWID_DPE_DMA_Mode_Register_N_MH_W_enable	1
	#define BWID_DPE_DMA_Mode_Register_N_UV_W_enable	1
	#define BWID_DPE_DMA_Mode_Register_N_Y_W_enable	1
	#define BWID_DPE_DMA_Mode_Register_NP1_YUV_W_enable	1
	#define BWID_DPE_DMA_Mode_Register_N_YUV_R_enable	1
	#define BWID_DPE_DMA_Mode_Register_NM1_MH_R_enable	1
	#define BWID_DPE_DMA_Mode_Register_NM1_YUV_R_enable	1
	#define BWID_DPE_DMA_Mode_Register_NP1_UV_R_enable	1
	#define BWID_DPE_DMA_Mode_Register_NP1_Y_R_enable	1
	/* Register Bit MASKS for DPE_DMA_Mode_Register */
	#define BMSK_DPE_DMA_Mode_Register_N_ARGB_W_enable	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_DMA_Mode_Register_N_444_W_enable	(1<<14) /* == 0x00004000:  */
	#define BMSK_DPE_DMA_Mode_Register_Dpe_dma_en	(1<<11) /* == 0x00000800:  */
	#define BMSK_DPE_DMA_Mode_Register_N_YUV_W_en	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_DMA_Mode_Register_FG_R_enable	(1<<9) /* == 0x00000200:  */
	#define BMSK_DPE_DMA_Mode_Register_N_MH_W_enable	(1<<8) /* == 0x00000100:  */
	#define BMSK_DPE_DMA_Mode_Register_N_UV_W_enable	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_DMA_Mode_Register_N_Y_W_enable	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DMA_Mode_Register_NP1_YUV_W_enable	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_DMA_Mode_Register_N_YUV_R_enable	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DMA_Mode_Register_NM1_MH_R_enable	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DMA_Mode_Register_NM1_YUV_R_enable	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DMA_Mode_Register_NP1_UV_R_enable	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DMA_Mode_Register_NP1_Y_R_enable	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DMA_Mode_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_Mode_Register_N_ARGB_W_enable	 0x6074, 15, 1, 0x00008000
	#define BITFIELD_DPE_DMA_Mode_Register_N_444_W_enable	 0x6074, 14, 1, 0x00004000
	#define BITFIELD_DPE_DMA_Mode_Register_Dpe_dma_en	 0x6074, 11, 1, 0x00000800
	#define BITFIELD_DPE_DMA_Mode_Register_N_YUV_W_en	 0x6074, 10, 1, 0x00000400
	#define BITFIELD_DPE_DMA_Mode_Register_FG_R_enable	 0x6074, 9, 1, 0x00000200
	#define BITFIELD_DPE_DMA_Mode_Register_N_MH_W_enable	 0x6074, 8, 1, 0x00000100
	#define BITFIELD_DPE_DMA_Mode_Register_N_UV_W_enable	 0x6074, 7, 1, 0x00000080
	#define BITFIELD_DPE_DMA_Mode_Register_N_Y_W_enable	 0x6074, 6, 1, 0x00000040
	#define BITFIELD_DPE_DMA_Mode_Register_NP1_YUV_W_enable	 0x6074, 5, 1, 0x00000020
	#define BITFIELD_DPE_DMA_Mode_Register_N_YUV_R_enable	 0x6074, 4, 1, 0x00000010
	#define BITFIELD_DPE_DMA_Mode_Register_NM1_MH_R_enable	 0x6074, 3, 1, 0x00000008
	#define BITFIELD_DPE_DMA_Mode_Register_NM1_YUV_R_enable	 0x6074, 2, 1, 0x00000004
	#define BITFIELD_DPE_DMA_Mode_Register_NP1_UV_R_enable	 0x6074, 1, 1, 0x00000002
	#define BITFIELD_DPE_DMA_Mode_Register_NP1_Y_R_enable	 0x6074, 0, 1, 0x00000001
#define ROFF_DPE_DMA_SAP_MEM_Parameters_Register	0x6078 /* SAP_MEM_Parameters_Register */ 
	#define BITFIELD_DPE_DMA_SAP_MEM_Parameters_Register	 0x6078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_SAP_MEM_Parameters_Register */
	#define BLSB_DPE_DMA_SAP_MEM_Parameters_Register_lsb_pad	31
	/* Register Bit Widths for DPE_DMA_SAP_MEM_Parameters_Register */
	#define BWID_DPE_DMA_SAP_MEM_Parameters_Register_lsb_pad	1
	/* Register Bit MASKS for DPE_DMA_SAP_MEM_Parameters_Register */
	#define BMSK_DPE_DMA_SAP_MEM_Parameters_Register_lsb_pad	(1<<31) /* == 0x80000000:  */
	/* Register BITFIELD for DPE_DMA_SAP_MEM_Parameters_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_SAP_MEM_Parameters_Register_lsb_pad	 0x6078, 31, 1, 0x80000000
#define ROFF_DPE_DMA_NP1_Y_Picture_Parameter_Register	0x6000 /* NP1_Y_Picture_Parameter_Register */ 
	#define BITFIELD_DPE_DMA_NP1_Y_Picture_Parameter_Register	 0x6000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_Y_Picture_Parameter_Register */
	#define BLSB_DPE_DMA_NP1_Y_Picture_Parameter_Register_top_disable	31
	#define BLSB_DPE_DMA_NP1_Y_Picture_Parameter_Register_bottom_disable	30
	#define BLSB_DPE_DMA_NP1_Y_Picture_Parameter_Register_pix_wsel	29
	#define BLSB_DPE_DMA_NP1_Y_Picture_Parameter_Register_pic_line_w	12
	#define BLSB_DPE_DMA_NP1_Y_Picture_Parameter_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_NP1_Y_Picture_Parameter_Register */
	#define BWID_DPE_DMA_NP1_Y_Picture_Parameter_Register_top_disable	1
	#define BWID_DPE_DMA_NP1_Y_Picture_Parameter_Register_bottom_disable	1
	#define BWID_DPE_DMA_NP1_Y_Picture_Parameter_Register_pix_wsel	1
	#define BWID_DPE_DMA_NP1_Y_Picture_Parameter_Register_pic_line_w	15
	#define BWID_DPE_DMA_NP1_Y_Picture_Parameter_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_NP1_Y_Picture_Parameter_Register */
	#define BMSK_DPE_DMA_NP1_Y_Picture_Parameter_Register_top_disable	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_DMA_NP1_Y_Picture_Parameter_Register_bottom_disable	(1<<30) /* == 0x40000000:  */
	#define BMSK_DPE_DMA_NP1_Y_Picture_Parameter_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_NP1_Y_Picture_Parameter_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_NP1_Y_Picture_Parameter_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_NP1_Y_Picture_Parameter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_Y_Picture_Parameter_Register_top_disable	 0x6000, 31, 1, 0x80000000
	#define BITFIELD_DPE_DMA_NP1_Y_Picture_Parameter_Register_bottom_disable	 0x6000, 30, 1, 0x40000000
	#define BITFIELD_DPE_DMA_NP1_Y_Picture_Parameter_Register_pix_wsel	 0x6000, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_NP1_Y_Picture_Parameter_Register_pic_line_w	 0x6000, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_NP1_Y_Picture_Parameter_Register_stride_h	 0x6000, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_NP1_UV_Picture_Parameter_Register	0x600c /* DMA_NP1_UV_Picture_Parameter_Register */ 
	#define BITFIELD_DPE_DMA_NP1_UV_Picture_Parameter_Register	 0x600c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_UV_Picture_Parameter_Register */
	#define BLSB_DPE_DMA_NP1_UV_Picture_Parameter_Register_top_disable	31
	#define BLSB_DPE_DMA_NP1_UV_Picture_Parameter_Register_bottom_disable	30
	#define BLSB_DPE_DMA_NP1_UV_Picture_Parameter_Register_pix_wsel	29
	#define BLSB_DPE_DMA_NP1_UV_Picture_Parameter_Register_pic_line_w	12
	#define BLSB_DPE_DMA_NP1_UV_Picture_Parameter_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_NP1_UV_Picture_Parameter_Register */
	#define BWID_DPE_DMA_NP1_UV_Picture_Parameter_Register_top_disable	1
	#define BWID_DPE_DMA_NP1_UV_Picture_Parameter_Register_bottom_disable	1
	#define BWID_DPE_DMA_NP1_UV_Picture_Parameter_Register_pix_wsel	1
	#define BWID_DPE_DMA_NP1_UV_Picture_Parameter_Register_pic_line_w	15
	#define BWID_DPE_DMA_NP1_UV_Picture_Parameter_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_NP1_UV_Picture_Parameter_Register */
	#define BMSK_DPE_DMA_NP1_UV_Picture_Parameter_Register_top_disable	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_DMA_NP1_UV_Picture_Parameter_Register_bottom_disable	(1<<30) /* == 0x40000000:  */
	#define BMSK_DPE_DMA_NP1_UV_Picture_Parameter_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_NP1_UV_Picture_Parameter_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_NP1_UV_Picture_Parameter_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_NP1_UV_Picture_Parameter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_UV_Picture_Parameter_Register_top_disable	 0x600c, 31, 1, 0x80000000
	#define BITFIELD_DPE_DMA_NP1_UV_Picture_Parameter_Register_bottom_disable	 0x600c, 30, 1, 0x40000000
	#define BITFIELD_DPE_DMA_NP1_UV_Picture_Parameter_Register_pix_wsel	 0x600c, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_NP1_UV_Picture_Parameter_Register_pic_line_w	 0x600c, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_NP1_UV_Picture_Parameter_Register_stride_h	 0x600c, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register	0x6004 /* DMA_NP1_Y_Top_Field_Starting_Address_Register */ 
	#define BITFIELD_DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register	 0x6004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register */
	#define BLSB_DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register_top_start_addr	0
	/* Register Bit Widths for DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register */
	#define BWID_DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register_top_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register */
	#define BMSK_DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register_top_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_Y_Top_Field_Starting_Address_Register_top_start_addr	 0x6004, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register	0x6010 /* DMA_NP1_UV_Top_Field_Starting_Address_Register */ 
	#define BITFIELD_DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register	 0x6010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register */
	#define BLSB_DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register_top_start_addr	0
	/* Register Bit Widths for DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register */
	#define BWID_DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register_top_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register */
	#define BMSK_DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register_top_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_UV_Top_Field_Starting_Address_Register_top_start_addr	 0x6010, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register	0x6008 /* DMA_NP1_Y_Bottom_Field_Starting_Address_Register */ 
	#define BITFIELD_DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register	 0x6008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register */
	#define BLSB_DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register_Bottom_start_addr	0
	/* Register Bit Widths for DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register */
	#define BWID_DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register_Bottom_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register */
	#define BMSK_DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register_Bottom_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_Y_Bottom_Field_Starting_Address_Register_Bottom_start_addr	 0x6008, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register	0x6014 /* DMA_NP1_UV_Bottom_Field_Starting_Address_Register */ 
	#define BITFIELD_DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register	 0x6014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register */
	#define BLSB_DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register_Bottom_start_addr	0
	/* Register Bit Widths for DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register */
	#define BWID_DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register_Bottom_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register */
	#define BMSK_DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register_Bottom_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_UV_Bottom_Field_Starting_Address_Register_Bottom_start_addr	 0x6014, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NM1_YUV_R_Param_Register	0x6018 /* DMA_NM1_YUV_R_Param_Register */ 
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Param_Register	 0x6018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NM1_YUV_R_Param_Register */
	#define BLSB_DPE_DMA_NM1_YUV_R_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_NM1_YUV_R_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_NM1_YUV_R_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_NM1_YUV_R_Param_Register */
	#define BWID_DPE_DMA_NM1_YUV_R_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_NM1_YUV_R_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_NM1_YUV_R_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_NM1_YUV_R_Param_Register */
	#define BMSK_DPE_DMA_NM1_YUV_R_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_NM1_YUV_R_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_NM1_YUV_R_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_NM1_YUV_R_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Param_Register_pix_wsel	 0x6018, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Param_Register_pic_line_w	 0x6018, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Param_Register_stride_h	 0x6018, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_NM1_MH_R_Param_Register	0x6020 /* DMA_NM1_MH_R_Param_Register */ 
	#define BITFIELD_DPE_DMA_NM1_MH_R_Param_Register	 0x6020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NM1_MH_R_Param_Register */
	#define BLSB_DPE_DMA_NM1_MH_R_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_NM1_MH_R_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_NM1_MH_R_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_NM1_MH_R_Param_Register */
	#define BWID_DPE_DMA_NM1_MH_R_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_NM1_MH_R_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_NM1_MH_R_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_NM1_MH_R_Param_Register */
	#define BMSK_DPE_DMA_NM1_MH_R_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_NM1_MH_R_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_NM1_MH_R_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_NM1_MH_R_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NM1_MH_R_Param_Register_pix_wsel	 0x6020, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_NM1_MH_R_Param_Register_pic_line_w	 0x6020, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_NM1_MH_R_Param_Register_stride_h	 0x6020, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_N_YUV_R_Param_Register	0x6028 /* DMA_N_YUV_R_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_YUV_R_Param_Register	 0x6028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_YUV_R_Param_Register */
	#define BLSB_DPE_DMA_N_YUV_R_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_N_YUV_R_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_N_YUV_R_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_N_YUV_R_Param_Register */
	#define BWID_DPE_DMA_N_YUV_R_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_N_YUV_R_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_N_YUV_R_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_N_YUV_R_Param_Register */
	#define BMSK_DPE_DMA_N_YUV_R_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_N_YUV_R_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_N_YUV_R_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_N_YUV_R_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_YUV_R_Param_Register_pix_wsel	 0x6028, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_N_YUV_R_Param_Register_pic_line_w	 0x6028, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_N_YUV_R_Param_Register_stride_h	 0x6028, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_NP1_YUV_W_Param_Register	0x6030 /* DMA_NP1_YUV_W_Param_Register */ 
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Param_Register	 0x6030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_YUV_W_Param_Register */
	#define BLSB_DPE_DMA_NP1_YUV_W_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_NP1_YUV_W_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_NP1_YUV_W_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_NP1_YUV_W_Param_Register */
	#define BWID_DPE_DMA_NP1_YUV_W_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_NP1_YUV_W_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_NP1_YUV_W_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_NP1_YUV_W_Param_Register */
	#define BMSK_DPE_DMA_NP1_YUV_W_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_NP1_YUV_W_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_NP1_YUV_W_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_NP1_YUV_W_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Param_Register_pix_wsel	 0x6030, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Param_Register_pic_line_w	 0x6030, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Param_Register_stride_h	 0x6030, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_N_Y_W_Param_Register	0x6038 /* DMA_N_Y_W_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_Y_W_Param_Register	 0x6038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_Y_W_Param_Register */
	#define BLSB_DPE_DMA_N_Y_W_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_N_Y_W_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_N_Y_W_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_N_Y_W_Param_Register */
	#define BWID_DPE_DMA_N_Y_W_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_N_Y_W_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_N_Y_W_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_N_Y_W_Param_Register */
	#define BMSK_DPE_DMA_N_Y_W_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_N_Y_W_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_N_Y_W_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_N_Y_W_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_Y_W_Param_Register_pix_wsel	 0x6038, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_N_Y_W_Param_Register_pic_line_w	 0x6038, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_N_Y_W_Param_Register_stride_h	 0x6038, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_N_UV_W_Param_Register	0x6040 /* DMA_N_UV_W_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_UV_W_Param_Register	 0x6040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_UV_W_Param_Register */
	#define BLSB_DPE_DMA_N_UV_W_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_N_UV_W_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_N_UV_W_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_N_UV_W_Param_Register */
	#define BWID_DPE_DMA_N_UV_W_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_N_UV_W_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_N_UV_W_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_N_UV_W_Param_Register */
	#define BMSK_DPE_DMA_N_UV_W_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_N_UV_W_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_N_UV_W_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_N_UV_W_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_UV_W_Param_Register_pix_wsel	 0x6040, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_N_UV_W_Param_Register_pic_line_w	 0x6040, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_N_UV_W_Param_Register_stride_h	 0x6040, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_N_MH_W_Param_Register	0x6048 /* DMA_N_MH_W_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_MH_W_Param_Register	 0x6048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_MH_W_Param_Register */
	#define BLSB_DPE_DMA_N_MH_W_Param_Register_pix_wsel	29
	#define BLSB_DPE_DMA_N_MH_W_Param_Register_pic_line_w	12
	#define BLSB_DPE_DMA_N_MH_W_Param_Register_stride_h	0
	/* Register Bit Widths for DPE_DMA_N_MH_W_Param_Register */
	#define BWID_DPE_DMA_N_MH_W_Param_Register_pix_wsel	1
	#define BWID_DPE_DMA_N_MH_W_Param_Register_pic_line_w	15
	#define BWID_DPE_DMA_N_MH_W_Param_Register_stride_h	11
	/* Register Bit MASKS for DPE_DMA_N_MH_W_Param_Register */
	#define BMSK_DPE_DMA_N_MH_W_Param_Register_pix_wsel	(1<<29) /* == 0x20000000:  */
	#define BMSK_DPE_DMA_N_MH_W_Param_Register_pic_line_w	0x07fff000 /*  */
	#define BMSK_DPE_DMA_N_MH_W_Param_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_DMA_N_MH_W_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_MH_W_Param_Register_pix_wsel	 0x6048, 29, 1, 0x20000000
	#define BITFIELD_DPE_DMA_N_MH_W_Param_Register_pic_line_w	 0x6048, 12, 15, 0x07fff000
	#define BITFIELD_DPE_DMA_N_MH_W_Param_Register_stride_h	 0x6048, 0, 11, 0x000007ff
#define ROFF_DPE_DMA_NM1_YUV_R_Start_Addr_Register	0x601c /* DMA_NM1_YUV_R_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Start_Addr_Register	 0x601c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NM1_YUV_R_Start_Addr_Register */
	#define BLSB_DPE_DMA_NM1_YUV_R_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_NM1_YUV_R_Start_Addr_Register */
	#define BWID_DPE_DMA_NM1_YUV_R_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NM1_YUV_R_Start_Addr_Register */
	#define BMSK_DPE_DMA_NM1_YUV_R_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NM1_YUV_R_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Start_Addr_Register_pic_start_addr	 0x601c, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NM1_MH_R_Start_Addr_Register	0x6024 /* DMA_NM1_MH_R_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_NM1_MH_R_Start_Addr_Register	 0x6024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NM1_MH_R_Start_Addr_Register */
	#define BLSB_DPE_DMA_NM1_MH_R_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_NM1_MH_R_Start_Addr_Register */
	#define BWID_DPE_DMA_NM1_MH_R_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NM1_MH_R_Start_Addr_Register */
	#define BMSK_DPE_DMA_NM1_MH_R_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NM1_MH_R_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NM1_MH_R_Start_Addr_Register_pic_start_addr	 0x6024, 0, 32, 0x00000000
#define ROFF_DPE_DMA_N_YUV_R_Start_Addr_Register	0x602c /* DMA_N_YUV_R_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_N_YUV_R_Start_Addr_Register	 0x602c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_YUV_R_Start_Addr_Register */
	#define BLSB_DPE_DMA_N_YUV_R_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_N_YUV_R_Start_Addr_Register */
	#define BWID_DPE_DMA_N_YUV_R_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_N_YUV_R_Start_Addr_Register */
	#define BMSK_DPE_DMA_N_YUV_R_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_N_YUV_R_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_YUV_R_Start_Addr_Register_pic_start_addr	 0x602c, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NP1_YUV_W_Start_Addr_Register	0x6034 /* DMA_NP1_YUV_W_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Start_Addr_Register	 0x6034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_YUV_W_Start_Addr_Register */
	#define BLSB_DPE_DMA_NP1_YUV_W_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_NP1_YUV_W_Start_Addr_Register */
	#define BWID_DPE_DMA_NP1_YUV_W_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_NP1_YUV_W_Start_Addr_Register */
	#define BMSK_DPE_DMA_NP1_YUV_W_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_YUV_W_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Start_Addr_Register_pic_start_addr	 0x6034, 0, 32, 0x00000000
#define ROFF_DPE_DMA_N_Y_W_Start_Addr_Register	0x603c /* DMA_N_Y_W_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_N_Y_W_Start_Addr_Register	 0x603c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_Y_W_Start_Addr_Register */
	#define BLSB_DPE_DMA_N_Y_W_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_N_Y_W_Start_Addr_Register */
	#define BWID_DPE_DMA_N_Y_W_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_N_Y_W_Start_Addr_Register */
	#define BMSK_DPE_DMA_N_Y_W_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_N_Y_W_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_Y_W_Start_Addr_Register_pic_start_addr	 0x603c, 0, 32, 0x00000000
#define ROFF_DPE_DMA_N_UV_W_Start_Addr_Register	0x6044 /* DMA_N_UV_W_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_N_UV_W_Start_Addr_Register	 0x6044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_UV_W_Start_Addr_Register */
	#define BLSB_DPE_DMA_N_UV_W_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_N_UV_W_Start_Addr_Register */
	#define BWID_DPE_DMA_N_UV_W_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_N_UV_W_Start_Addr_Register */
	#define BMSK_DPE_DMA_N_UV_W_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_N_UV_W_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_UV_W_Start_Addr_Register_pic_start_addr	 0x6044, 0, 32, 0x00000000
#define ROFF_DPE_DMA_N_MH_W_Start_Addr_Register	0x604c /* DMA_N_MH_W_Start_Addr_Register */ 
	#define BITFIELD_DPE_DMA_N_MH_W_Start_Addr_Register	 0x604c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_MH_W_Start_Addr_Register */
	#define BLSB_DPE_DMA_N_MH_W_Start_Addr_Register_pic_start_addr	0
	/* Register Bit Widths for DPE_DMA_N_MH_W_Start_Addr_Register */
	#define BWID_DPE_DMA_N_MH_W_Start_Addr_Register_pic_start_addr	32
	/* Register Bit MASKS for DPE_DMA_N_MH_W_Start_Addr_Register */
	#define BMSK_DPE_DMA_N_MH_W_Start_Addr_Register_pic_start_addr	0x00000000 /*  */
	/* Register BITFIELD for DPE_DMA_N_MH_W_Start_Addr_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_MH_W_Start_Addr_Register_pic_start_addr	 0x604c, 0, 32, 0x00000000
#define ROFF_DPE_DMA_NP1_Y_R_Stride_Param_Register	0x6050 /* DMA_NP1_Y_R_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_NP1_Y_R_Stride_Param_Register	 0x6050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_Y_R_Stride_Param_Register */
	#define BLSB_DPE_DMA_NP1_Y_R_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_NP1_Y_R_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_NP1_Y_R_Stride_Param_Register */
	#define BWID_DPE_DMA_NP1_Y_R_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_NP1_Y_R_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_NP1_Y_R_Stride_Param_Register */
	#define BMSK_DPE_DMA_NP1_Y_R_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_NP1_Y_R_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_Y_R_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_Y_R_Stride_Param_Register_pix_coord_x	 0x6050, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_NP1_Y_R_Stride_Param_Register_stride_w	 0x6050, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_NP1_UV_R_Stride_Param_Register	0x6054 /* DMA_NP1_UV_R_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_NP1_UV_R_Stride_Param_Register	 0x6054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_UV_R_Stride_Param_Register */
	#define BLSB_DPE_DMA_NP1_UV_R_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_NP1_UV_R_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_NP1_UV_R_Stride_Param_Register */
	#define BWID_DPE_DMA_NP1_UV_R_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_NP1_UV_R_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_NP1_UV_R_Stride_Param_Register */
	#define BMSK_DPE_DMA_NP1_UV_R_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_NP1_UV_R_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_UV_R_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_UV_R_Stride_Param_Register_pix_coord_x	 0x6054, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_NP1_UV_R_Stride_Param_Register_stride_w	 0x6054, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_NM1_YUV_R_Stride_Param_Register	0x6058 /* DMA_NM1_YUV_R_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Stride_Param_Register	 0x6058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NM1_YUV_R_Stride_Param_Register */
	#define BLSB_DPE_DMA_NM1_YUV_R_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_NM1_YUV_R_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_NM1_YUV_R_Stride_Param_Register */
	#define BWID_DPE_DMA_NM1_YUV_R_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_NM1_YUV_R_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_NM1_YUV_R_Stride_Param_Register */
	#define BMSK_DPE_DMA_NM1_YUV_R_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_NM1_YUV_R_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_NM1_YUV_R_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Stride_Param_Register_pix_coord_x	 0x6058, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_NM1_YUV_R_Stride_Param_Register_stride_w	 0x6058, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_NM1_MH_R_Stride_Param_Register	0x605c /* DMA_NM1_MH_R_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_NM1_MH_R_Stride_Param_Register	 0x605c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NM1_MH_R_Stride_Param_Register */
	#define BLSB_DPE_DMA_NM1_MH_R_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_NM1_MH_R_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_NM1_MH_R_Stride_Param_Register */
	#define BWID_DPE_DMA_NM1_MH_R_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_NM1_MH_R_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_NM1_MH_R_Stride_Param_Register */
	#define BMSK_DPE_DMA_NM1_MH_R_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_NM1_MH_R_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_NM1_MH_R_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NM1_MH_R_Stride_Param_Register_pix_coord_x	 0x605c, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_NM1_MH_R_Stride_Param_Register_stride_w	 0x605c, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_N_YUV_R_Stride_Param_Register	0x6060 /* DMA_N_YUV_R_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_YUV_R_Stride_Param_Register	 0x6060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_YUV_R_Stride_Param_Register */
	#define BLSB_DPE_DMA_N_YUV_R_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_N_YUV_R_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_N_YUV_R_Stride_Param_Register */
	#define BWID_DPE_DMA_N_YUV_R_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_N_YUV_R_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_N_YUV_R_Stride_Param_Register */
	#define BMSK_DPE_DMA_N_YUV_R_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_N_YUV_R_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_N_YUV_R_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_YUV_R_Stride_Param_Register_pix_coord_x	 0x6060, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_N_YUV_R_Stride_Param_Register_stride_w	 0x6060, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_NP1_YUV_W_Stride_Param_Register	0x6064 /* DMA_NP1_YUV_W_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Stride_Param_Register	 0x6064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_NP1_YUV_W_Stride_Param_Register */
	#define BLSB_DPE_DMA_NP1_YUV_W_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_NP1_YUV_W_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_NP1_YUV_W_Stride_Param_Register */
	#define BWID_DPE_DMA_NP1_YUV_W_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_NP1_YUV_W_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_NP1_YUV_W_Stride_Param_Register */
	#define BMSK_DPE_DMA_NP1_YUV_W_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_NP1_YUV_W_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_NP1_YUV_W_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Stride_Param_Register_pix_coord_x	 0x6064, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_NP1_YUV_W_Stride_Param_Register_stride_w	 0x6064, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_N_Y_W_Stride_Param_Register	0x6068 /* DMA_N_Y_W_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_Y_W_Stride_Param_Register	 0x6068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_Y_W_Stride_Param_Register */
	#define BLSB_DPE_DMA_N_Y_W_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_N_Y_W_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_N_Y_W_Stride_Param_Register */
	#define BWID_DPE_DMA_N_Y_W_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_N_Y_W_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_N_Y_W_Stride_Param_Register */
	#define BMSK_DPE_DMA_N_Y_W_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_N_Y_W_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_N_Y_W_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_Y_W_Stride_Param_Register_pix_coord_x	 0x6068, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_N_Y_W_Stride_Param_Register_stride_w	 0x6068, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_N_UV_W_Stride_Param_Register	0x606c /* DMA_N_UV_W_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_UV_W_Stride_Param_Register	 0x606c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_UV_W_Stride_Param_Register */
	#define BLSB_DPE_DMA_N_UV_W_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_N_UV_W_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_N_UV_W_Stride_Param_Register */
	#define BWID_DPE_DMA_N_UV_W_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_N_UV_W_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_N_UV_W_Stride_Param_Register */
	#define BMSK_DPE_DMA_N_UV_W_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_N_UV_W_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_N_UV_W_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_UV_W_Stride_Param_Register_pix_coord_x	 0x606c, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_N_UV_W_Stride_Param_Register_stride_w	 0x606c, 7, 9, 0x0000ff80
#define ROFF_DPE_DMA_N_MH_W_Stride_Param_Register	0x6070 /* DMA_N_MH_W_Stride_Param_Register */ 
	#define BITFIELD_DPE_DMA_N_MH_W_Stride_Param_Register	 0x6070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DMA_N_MH_W_Stride_Param_Register */
	#define BLSB_DPE_DMA_N_MH_W_Stride_Param_Register_pix_coord_x	16
	#define BLSB_DPE_DMA_N_MH_W_Stride_Param_Register_stride_w	7
	/* Register Bit Widths for DPE_DMA_N_MH_W_Stride_Param_Register */
	#define BWID_DPE_DMA_N_MH_W_Stride_Param_Register_pix_coord_x	11
	#define BWID_DPE_DMA_N_MH_W_Stride_Param_Register_stride_w	9
	/* Register Bit MASKS for DPE_DMA_N_MH_W_Stride_Param_Register */
	#define BMSK_DPE_DMA_N_MH_W_Stride_Param_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_DMA_N_MH_W_Stride_Param_Register_stride_w	0x0000ff80 /*  */
	/* Register BITFIELD for DPE_DMA_N_MH_W_Stride_Param_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DMA_N_MH_W_Stride_Param_Register_pix_coord_x	 0x6070, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_DMA_N_MH_W_Stride_Param_Register_stride_w	 0x6070, 7, 9, 0x0000ff80
#define ROFF_DPE_INCSC_Stride_Height_Register	0x4180 /* INCSC_Stride_Height_Register */ 
	#define BITFIELD_DPE_INCSC_Stride_Height_Register	 0x4180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Stride_Height_Register */
	#define BLSB_DPE_INCSC_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_INCSC_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_INCSC_Stride_Height_Register */
	#define BWID_DPE_INCSC_Stride_Height_Register_num_strides	4
	#define BWID_DPE_INCSC_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_INCSC_Stride_Height_Register */
	#define BMSK_DPE_INCSC_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_INCSC_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_INCSC_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Stride_Height_Register_num_strides	 0x4180, 12, 4, 0x0000f000
	#define BITFIELD_DPE_INCSC_Stride_Height_Register_stride_h	 0x4180, 0, 11, 0x000007ff
#define ROFF_DPE_INCSC_Stride_Width_Register	0x4184 /* INCSC_Stride_Width_Register */ 
	#define BITFIELD_DPE_INCSC_Stride_Width_Register	 0x4184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Stride_Width_Register */
	#define BLSB_DPE_INCSC_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_INCSC_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_INCSC_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_INCSC_Stride_Width_Register_RM	6
	#define BLSB_DPE_INCSC_Stride_Width_Register_LM	5
	#define BLSB_DPE_INCSC_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_INCSC_Stride_Width_Register */
	#define BWID_DPE_INCSC_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_INCSC_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_INCSC_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_INCSC_Stride_Width_Register_RM	1
	#define BWID_DPE_INCSC_Stride_Width_Register_LM	1
	#define BWID_DPE_INCSC_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_INCSC_Stride_Width_Register */
	#define BMSK_DPE_INCSC_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_INCSC_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_INCSC_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_INCSC_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_INCSC_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_INCSC_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Stride_Width_Register_next_rd_offset_x	 0x4184, 27, 5, 0xf8000000
	#define BITFIELD_DPE_INCSC_Stride_Width_Register_pix_coord_x	 0x4184, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_INCSC_Stride_Width_Register_out_stride_w	 0x4184, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_INCSC_Stride_Width_Register_RM	 0x4184, 6, 1, 0x00000040
	#define BITFIELD_DPE_INCSC_Stride_Width_Register_LM	 0x4184, 5, 1, 0x00000020
	#define BITFIELD_DPE_INCSC_Stride_Width_Register_in_stride_off	 0x4184, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_Control_Register	0x418c /* INCSC_Control_Register */ 
	#define BITFIELD_DPE_INCSC_Control_Register	 0x418c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Control_Register */
	#define BLSB_DPE_INCSC_Control_Register_xvYCC_en	16
	#define BLSB_DPE_INCSC_Control_Register_dc_gain_bypass	15
	#define BLSB_DPE_INCSC_Control_Register_rgb2lms_select	3
	#define BLSB_DPE_INCSC_Control_Register_skin_bypass	2
	#define BLSB_DPE_INCSC_Control_Register_yuv2rgb_bypass	1
	#define BLSB_DPE_INCSC_Control_Register_rgb2ipt_bypass	0
	/* Register Bit Widths for DPE_INCSC_Control_Register */
	#define BWID_DPE_INCSC_Control_Register_xvYCC_en	1
	#define BWID_DPE_INCSC_Control_Register_dc_gain_bypass	1
	#define BWID_DPE_INCSC_Control_Register_rgb2lms_select	1
	#define BWID_DPE_INCSC_Control_Register_skin_bypass	1
	#define BWID_DPE_INCSC_Control_Register_yuv2rgb_bypass	1
	#define BWID_DPE_INCSC_Control_Register_rgb2ipt_bypass	1
	/* Register Bit MASKS for DPE_INCSC_Control_Register */
	#define BMSK_DPE_INCSC_Control_Register_xvYCC_en	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_INCSC_Control_Register_dc_gain_bypass	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_Control_Register_rgb2lms_select	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_INCSC_Control_Register_skin_bypass	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_INCSC_Control_Register_yuv2rgb_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_INCSC_Control_Register_rgb2ipt_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_INCSC_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Control_Register_xvYCC_en	 0x418c, 16, 1, 0x00010000
	#define BITFIELD_DPE_INCSC_Control_Register_dc_gain_bypass	 0x418c, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_Control_Register_rgb2lms_select	 0x418c, 3, 1, 0x00000008
	#define BITFIELD_DPE_INCSC_Control_Register_skin_bypass	 0x418c, 2, 1, 0x00000004
	#define BITFIELD_DPE_INCSC_Control_Register_yuv2rgb_bypass	 0x418c, 1, 1, 0x00000002
	#define BITFIELD_DPE_INCSC_Control_Register_rgb2ipt_bypass	 0x418c, 0, 1, 0x00000001
#define ROFF_DPE_INCSC_422_to_444_Coeff0_Register	0x4190 /* INCSC_422_to_444_Coeff0_Register */ 
	#define BITFIELD_DPE_INCSC_422_to_444_Coeff0_Register	 0x4190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_422_to_444_Coeff0_Register */
	#define BLSB_DPE_INCSC_422_to_444_Coeff0_Register_C422_444_coeff0	0
	/* Register Bit Widths for DPE_INCSC_422_to_444_Coeff0_Register */
	#define BWID_DPE_INCSC_422_to_444_Coeff0_Register_C422_444_coeff0	9
	/* Register Bit MASKS for DPE_INCSC_422_to_444_Coeff0_Register */
	#define BMSK_DPE_INCSC_422_to_444_Coeff0_Register_C422_444_coeff0	0x000001ff /*  */
	/* Register BITFIELD for DPE_INCSC_422_to_444_Coeff0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_422_to_444_Coeff0_Register_C422_444_coeff0	 0x4190, 0, 9, 0x000001ff
#define ROFF_DPE_INCSC_422_to_444_Coeff1_Register	0x4194 /* INCSC_422_to_444_Coeff1_Register */ 
	#define BITFIELD_DPE_INCSC_422_to_444_Coeff1_Register	 0x4194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_422_to_444_Coeff1_Register */
	#define BLSB_DPE_INCSC_422_to_444_Coeff1_Register_C422_444_coeff1	0
	/* Register Bit Widths for DPE_INCSC_422_to_444_Coeff1_Register */
	#define BWID_DPE_INCSC_422_to_444_Coeff1_Register_C422_444_coeff1	9
	/* Register Bit MASKS for DPE_INCSC_422_to_444_Coeff1_Register */
	#define BMSK_DPE_INCSC_422_to_444_Coeff1_Register_C422_444_coeff1	0x000001ff /*  */
	/* Register BITFIELD for DPE_INCSC_422_to_444_Coeff1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_422_to_444_Coeff1_Register_C422_444_coeff1	 0x4194, 0, 9, 0x000001ff
#define ROFF_DPE_INCSC_xvYcc_I_Range_Comp_Register	0x4198 /* INCSC_xvYcc_I_Range_Comp_Register */ 
	#define BITFIELD_DPE_INCSC_xvYcc_I_Range_Comp_Register	 0x4198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xvYcc_I_Range_Comp_Register */
	#define BLSB_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_offset	16
	#define BLSB_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_Gain	0
	/* Register Bit Widths for DPE_INCSC_xvYcc_I_Range_Comp_Register */
	#define BWID_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_offset	13
	#define BWID_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_Gain	13
	/* Register Bit MASKS for DPE_INCSC_xvYcc_I_Range_Comp_Register */
	#define BMSK_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_offset	0x1fff0000 /*  */
	#define BMSK_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_Gain	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xvYcc_I_Range_Comp_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_offset	 0x4198, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_INCSC_xvYcc_I_Range_Comp_Register_I_Gain	 0x4198, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_YUV_to_RGB_Coeff_Register	0x41a0 /* INCSC_YUV_to_RGB_Coeff_Register */ 
	#define BITFIELD_DPE_INCSC_YUV_to_RGB_Coeff_Register	 0x41a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_YUV_to_RGB_Coeff_Register */
	#define BLSB_DPE_INCSC_YUV_to_RGB_Coeff_Register_Yuv2rgb_coeff	0
	/* Register Bit Widths for DPE_INCSC_YUV_to_RGB_Coeff_Register */
	#define BWID_DPE_INCSC_YUV_to_RGB_Coeff_Register_Yuv2rgb_coeff	13
	/* Register Bit MASKS for DPE_INCSC_YUV_to_RGB_Coeff_Register */
	#define BMSK_DPE_INCSC_YUV_to_RGB_Coeff_Register_Yuv2rgb_coeff	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_YUV_to_RGB_Coeff_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_YUV_to_RGB_Coeff_Register_Yuv2rgb_coeff	 0x41a0, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_RGB2LMS_Coefficient01_Register	0x41a0 /* INCSC_RGB2LMS_Coefficient01_Register */ 
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient01_Register	 0x41a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_RGB2LMS_Coefficient01_Register */
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient01_Register_C1	16
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient01_Register_C0	0
	/* Register Bit Widths for DPE_INCSC_RGB2LMS_Coefficient01_Register */
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient01_Register_C1	15
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient01_Register_C0	15
	/* Register Bit MASKS for DPE_INCSC_RGB2LMS_Coefficient01_Register */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient01_Register_C1	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient01_Register_C0	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_RGB2LMS_Coefficient01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient01_Register_C1	 0x41a0, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient01_Register_C0	 0x41a0, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_RGB2LMS_Coefficient23_Register	0x41a4 /* INCSC_RGB2LMS_Coefficient23_Register */ 
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient23_Register	 0x41a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_RGB2LMS_Coefficient23_Register */
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient23_Register_C3	16
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient23_Register_C2	0
	/* Register Bit Widths for DPE_INCSC_RGB2LMS_Coefficient23_Register */
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient23_Register_C3	15
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient23_Register_C2	15
	/* Register Bit MASKS for DPE_INCSC_RGB2LMS_Coefficient23_Register */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient23_Register_C3	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient23_Register_C2	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_RGB2LMS_Coefficient23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient23_Register_C3	 0x41a4, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient23_Register_C2	 0x41a4, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_RGB2LMS_Coefficient45_Register	0x41a8 /* INCSC_RGB2LMS_Coefficient45_Register */ 
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient45_Register	 0x41a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_RGB2LMS_Coefficient45_Register */
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient45_Register_C5	16
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient45_Register_C4	0
	/* Register Bit Widths for DPE_INCSC_RGB2LMS_Coefficient45_Register */
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient45_Register_C5	15
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient45_Register_C4	15
	/* Register Bit MASKS for DPE_INCSC_RGB2LMS_Coefficient45_Register */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient45_Register_C5	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient45_Register_C4	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_RGB2LMS_Coefficient45_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient45_Register_C5	 0x41a8, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient45_Register_C4	 0x41a8, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_RGB2LMS_Coefficient67_Register	0x41ac /* INCSC_RGB2LMS_Coefficient67_Register */ 
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient67_Register	 0x41ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_RGB2LMS_Coefficient67_Register */
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient67_Register_C7	16
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient67_Register_C6	0
	/* Register Bit Widths for DPE_INCSC_RGB2LMS_Coefficient67_Register */
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient67_Register_C7	15
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient67_Register_C6	15
	/* Register Bit MASKS for DPE_INCSC_RGB2LMS_Coefficient67_Register */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient67_Register_C7	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient67_Register_C6	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_RGB2LMS_Coefficient67_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient67_Register_C7	 0x41ac, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient67_Register_C6	 0x41ac, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_RGB2LMS_Coefficient8_Register	0x41b0 /* INCSC_RGB2LMS_Coefficient8_Register */ 
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient8_Register	 0x41b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_RGB2LMS_Coefficient8_Register */
	#define BLSB_DPE_INCSC_RGB2LMS_Coefficient8_Register_C8	0
	/* Register Bit Widths for DPE_INCSC_RGB2LMS_Coefficient8_Register */
	#define BWID_DPE_INCSC_RGB2LMS_Coefficient8_Register_C8	15
	/* Register Bit MASKS for DPE_INCSC_RGB2LMS_Coefficient8_Register */
	#define BMSK_DPE_INCSC_RGB2LMS_Coefficient8_Register_C8	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_RGB2LMS_Coefficient8_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_RGB2LMS_Coefficient8_Register_C8	 0x41b0, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Y_G_Offset_Register	0x41d4 /* INCSC_Y_G_Offset_Register */ 
	#define BITFIELD_DPE_INCSC_Y_G_Offset_Register	 0x41d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Y_G_Offset_Register */
	#define BLSB_DPE_INCSC_Y_G_Offset_Register_YG_OOFF	16
	#define BLSB_DPE_INCSC_Y_G_Offset_Register_YG_IOFF	0
	/* Register Bit Widths for DPE_INCSC_Y_G_Offset_Register */
	#define BWID_DPE_INCSC_Y_G_Offset_Register_YG_OOFF	15
	#define BWID_DPE_INCSC_Y_G_Offset_Register_YG_IOFF	13
	/* Register Bit MASKS for DPE_INCSC_Y_G_Offset_Register */
	#define BMSK_DPE_INCSC_Y_G_Offset_Register_YG_OOFF	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Y_G_Offset_Register_YG_IOFF	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_Y_G_Offset_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Y_G_Offset_Register_YG_OOFF	 0x41d4, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Y_G_Offset_Register_YG_IOFF	 0x41d4, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_Cb_B_Offset_Register	0x41d8 /* INCSC_Cb_B_Offset_Register */ 
	#define BITFIELD_DPE_INCSC_Cb_B_Offset_Register	 0x41d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Cb_B_Offset_Register */
	#define BLSB_DPE_INCSC_Cb_B_Offset_Register_CB_OOFF	16
	#define BLSB_DPE_INCSC_Cb_B_Offset_Register_CB_IOFF	0
	/* Register Bit Widths for DPE_INCSC_Cb_B_Offset_Register */
	#define BWID_DPE_INCSC_Cb_B_Offset_Register_CB_OOFF	15
	#define BWID_DPE_INCSC_Cb_B_Offset_Register_CB_IOFF	13
	/* Register Bit MASKS for DPE_INCSC_Cb_B_Offset_Register */
	#define BMSK_DPE_INCSC_Cb_B_Offset_Register_CB_OOFF	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Cb_B_Offset_Register_CB_IOFF	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_Cb_B_Offset_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Cb_B_Offset_Register_CB_OOFF	 0x41d8, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Cb_B_Offset_Register_CB_IOFF	 0x41d8, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_Cr_R_Offset_Register	0x41dc /* INCSC_Cr_R_Offset_Register */ 
	#define BITFIELD_DPE_INCSC_Cr_R_Offset_Register	 0x41dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Cr_R_Offset_Register */
	#define BLSB_DPE_INCSC_Cr_R_Offset_Register_CR_OOFF	16
	#define BLSB_DPE_INCSC_Cr_R_Offset_Register_CR_IOFF	0
	/* Register Bit Widths for DPE_INCSC_Cr_R_Offset_Register */
	#define BWID_DPE_INCSC_Cr_R_Offset_Register_CR_OOFF	15
	#define BWID_DPE_INCSC_Cr_R_Offset_Register_CR_IOFF	13
	/* Register Bit MASKS for DPE_INCSC_Cr_R_Offset_Register */
	#define BMSK_DPE_INCSC_Cr_R_Offset_Register_CR_OOFF	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Cr_R_Offset_Register_CR_IOFF	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_Cr_R_Offset_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Cr_R_Offset_Register_CR_OOFF	 0x41dc, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Cr_R_Offset_Register_CR_IOFF	 0x41dc, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_Coefficient01_Register	0x41e0 /* INCSC_Coefficient01_Register */ 
	#define BITFIELD_DPE_INCSC_Coefficient01_Register	 0x41e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Coefficient01_Register */
	#define BLSB_DPE_INCSC_Coefficient01_Register_C1	16
	#define BLSB_DPE_INCSC_Coefficient01_Register_C0	0
	/* Register Bit Widths for DPE_INCSC_Coefficient01_Register */
	#define BWID_DPE_INCSC_Coefficient01_Register_C1	15
	#define BWID_DPE_INCSC_Coefficient01_Register_C0	15
	/* Register Bit MASKS for DPE_INCSC_Coefficient01_Register */
	#define BMSK_DPE_INCSC_Coefficient01_Register_C1	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Coefficient01_Register_C0	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Coefficient01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Coefficient01_Register_C1	 0x41e0, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Coefficient01_Register_C0	 0x41e0, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Coefficient23_Register	0x41e4 /* INCSC_Coefficient23_Register */ 
	#define BITFIELD_DPE_INCSC_Coefficient23_Register	 0x41e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Coefficient23_Register */
	#define BLSB_DPE_INCSC_Coefficient23_Register_C3	16
	#define BLSB_DPE_INCSC_Coefficient23_Register_C2	0
	/* Register Bit Widths for DPE_INCSC_Coefficient23_Register */
	#define BWID_DPE_INCSC_Coefficient23_Register_C3	15
	#define BWID_DPE_INCSC_Coefficient23_Register_C2	15
	/* Register Bit MASKS for DPE_INCSC_Coefficient23_Register */
	#define BMSK_DPE_INCSC_Coefficient23_Register_C3	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Coefficient23_Register_C2	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Coefficient23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Coefficient23_Register_C3	 0x41e4, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Coefficient23_Register_C2	 0x41e4, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Coefficient45_Register	0x41e8 /* INCSC_Coefficient45_Register */ 
	#define BITFIELD_DPE_INCSC_Coefficient45_Register	 0x41e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Coefficient45_Register */
	#define BLSB_DPE_INCSC_Coefficient45_Register_C5	16
	#define BLSB_DPE_INCSC_Coefficient45_Register_C4	0
	/* Register Bit Widths for DPE_INCSC_Coefficient45_Register */
	#define BWID_DPE_INCSC_Coefficient45_Register_C5	15
	#define BWID_DPE_INCSC_Coefficient45_Register_C4	15
	/* Register Bit MASKS for DPE_INCSC_Coefficient45_Register */
	#define BMSK_DPE_INCSC_Coefficient45_Register_C5	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Coefficient45_Register_C4	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Coefficient45_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Coefficient45_Register_C5	 0x41e8, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Coefficient45_Register_C4	 0x41e8, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Coefficient67_Register	0x41ec /* INCSC_Coefficient67_Register */ 
	#define BITFIELD_DPE_INCSC_Coefficient67_Register	 0x41ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Coefficient67_Register */
	#define BLSB_DPE_INCSC_Coefficient67_Register_C7	16
	#define BLSB_DPE_INCSC_Coefficient67_Register_C6	0
	/* Register Bit Widths for DPE_INCSC_Coefficient67_Register */
	#define BWID_DPE_INCSC_Coefficient67_Register_C7	15
	#define BWID_DPE_INCSC_Coefficient67_Register_C6	15
	/* Register Bit MASKS for DPE_INCSC_Coefficient67_Register */
	#define BMSK_DPE_INCSC_Coefficient67_Register_C7	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Coefficient67_Register_C6	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Coefficient67_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Coefficient67_Register_C7	 0x41ec, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Coefficient67_Register_C6	 0x41ec, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Coefficient8_Register	0x41f0 /* INCSC_Coefficient8_Register */ 
	#define BITFIELD_DPE_INCSC_Coefficient8_Register	 0x41f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Coefficient8_Register */
	#define BLSB_DPE_INCSC_Coefficient8_Register_C8	0
	/* Register Bit Widths for DPE_INCSC_Coefficient8_Register */
	#define BWID_DPE_INCSC_Coefficient8_Register_C8	15
	/* Register Bit MASKS for DPE_INCSC_Coefficient8_Register */
	#define BMSK_DPE_INCSC_Coefficient8_Register_C8	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Coefficient8_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Coefficient8_Register_C8	 0x41f0, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Y_G_Input_Clamping_Register	0x41f4 /* INCSC_Y_G_Input_Clamping_Register */ 
	#define BITFIELD_DPE_INCSC_Y_G_Input_Clamping_Register	 0x41f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Y_G_Input_Clamping_Register */
	#define BLSB_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMAX	16
	#define BLSB_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMIN	0
	/* Register Bit Widths for DPE_INCSC_Y_G_Input_Clamping_Register */
	#define BWID_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMAX	12
	#define BWID_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMIN	12
	/* Register Bit MASKS for DPE_INCSC_Y_G_Input_Clamping_Register */
	#define BMSK_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMAX	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMIN	0x00000fff /*  */
	/* Register BITFIELD for DPE_INCSC_Y_G_Input_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMAX	 0x41f4, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_Y_G_Input_Clamping_Register_YG_IMIN	 0x41f4, 0, 12, 0x00000fff
#define ROFF_DPE_INCSC_Cb_B_Input_Clamping_Register	0x41f8 /* INCSC_Cb_B_Input_Clamping_Register */ 
	#define BITFIELD_DPE_INCSC_Cb_B_Input_Clamping_Register	 0x41f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Cb_B_Input_Clamping_Register */
	#define BLSB_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMAX	16
	#define BLSB_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMIN	0
	/* Register Bit Widths for DPE_INCSC_Cb_B_Input_Clamping_Register */
	#define BWID_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMAX	12
	#define BWID_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMIN	12
	/* Register Bit MASKS for DPE_INCSC_Cb_B_Input_Clamping_Register */
	#define BMSK_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMAX	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMIN	0x00000fff /*  */
	/* Register BITFIELD for DPE_INCSC_Cb_B_Input_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMAX	 0x41f8, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_Cb_B_Input_Clamping_Register_CB_IMIN	 0x41f8, 0, 12, 0x00000fff
#define ROFF_DPE_INCSC_Cr_R_Input_Clamping_Register	0x41fc /* INCSC_Cr_R_Input_Clamping_Register */ 
	#define BITFIELD_DPE_INCSC_Cr_R_Input_Clamping_Register	 0x41fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Cr_R_Input_Clamping_Register */
	#define BLSB_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMAX	16
	#define BLSB_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMIN	0
	/* Register Bit Widths for DPE_INCSC_Cr_R_Input_Clamping_Register */
	#define BWID_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMAX	12
	#define BWID_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMIN	12
	/* Register Bit MASKS for DPE_INCSC_Cr_R_Input_Clamping_Register */
	#define BMSK_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMAX	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMIN	0x00000fff /*  */
	/* Register BITFIELD for DPE_INCSC_Cr_R_Input_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMAX	 0x41fc, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_Cr_R_Input_Clamping_Register_CR_IMIN	 0x41fc, 0, 12, 0x00000fff
#define ROFF_DPE_INCSC_Y_G_Output_Clamping_Register	0x4200 /* INCSC_YG_Output_Clamping_Register */ 
	#define BITFIELD_DPE_INCSC_Y_G_Output_Clamping_Register	 0x4200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Y_G_Output_Clamping_Register */
	#define BLSB_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMAX	16
	#define BLSB_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMIN	0
	/* Register Bit Widths for DPE_INCSC_Y_G_Output_Clamping_Register */
	#define BWID_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMAX	15
	#define BWID_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMIN	15
	/* Register Bit MASKS for DPE_INCSC_Y_G_Output_Clamping_Register */
	#define BMSK_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMAX	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMIN	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Y_G_Output_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMAX	 0x4200, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Y_G_Output_Clamping_Register_YG_OMIN	 0x4200, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Cb_B_Output_Clamping_Register	0x4204 /* INCSC_Cb_B_Output_Clamping_Register */ 
	#define BITFIELD_DPE_INCSC_Cb_B_Output_Clamping_Register	 0x4204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Cb_B_Output_Clamping_Register */
	#define BLSB_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMAX	16
	#define BLSB_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMIN	0
	/* Register Bit Widths for DPE_INCSC_Cb_B_Output_Clamping_Register */
	#define BWID_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMAX	15
	#define BWID_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMIN	15
	/* Register Bit MASKS for DPE_INCSC_Cb_B_Output_Clamping_Register */
	#define BMSK_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMAX	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMIN	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Cb_B_Output_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMAX	 0x4204, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Cb_B_Output_Clamping_Register_CB_OMIN	 0x4204, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_Cr_R_Output_Clamping_Register	0x4208 /* INCSC_Cr_R_Output_Clamping_Register */ 
	#define BITFIELD_DPE_INCSC_Cr_R_Output_Clamping_Register	 0x4208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Cr_R_Output_Clamping_Register */
	#define BLSB_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMAX	16
	#define BLSB_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMIN	0
	/* Register Bit Widths for DPE_INCSC_Cr_R_Output_Clamping_Register */
	#define BWID_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMAX	15
	#define BWID_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMIN	15
	/* Register Bit MASKS for DPE_INCSC_Cr_R_Output_Clamping_Register */
	#define BMSK_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMAX	0x7fff0000 /*  */
	#define BMSK_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMIN	0x00007fff /*  */
	/* Register BITFIELD for DPE_INCSC_Cr_R_Output_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMAX	 0x4208, 16, 15, 0x7fff0000
	#define BITFIELD_DPE_INCSC_Cr_R_Output_Clamping_Register_CR_OMIN	 0x4208, 0, 15, 0x00007fff
#define ROFF_DPE_INCSC_RGB_LUT_Register	0x4210 /* INCSC_RGB_LUT_Register */ 
	#define BITFIELD_DPE_INCSC_RGB_LUT_Register	 0x4210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_RGB_LUT_Register */
	#define BLSB_DPE_INCSC_RGB_LUT_Register_RGB_lut_value	0
	/* Register Bit Widths for DPE_INCSC_RGB_LUT_Register */
	#define BWID_DPE_INCSC_RGB_LUT_Register_RGB_lut_value	24
	/* Register Bit MASKS for DPE_INCSC_RGB_LUT_Register */
	#define BMSK_DPE_INCSC_RGB_LUT_Register_RGB_lut_value	0x00ffffff /*  */
	/* Register BITFIELD for DPE_INCSC_RGB_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_RGB_LUT_Register_RGB_lut_value	 0x4210, 0, 24, 0x00ffffff
#define ROFF_DPE_INCSC_LMS_LUT_Register	0x4610 /* INCSC_LMS_LUT_Register */ 
	#define BITFIELD_DPE_INCSC_LMS_LUT_Register	 0x4610, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMS_LUT_Register */
	#define BLSB_DPE_INCSC_LMS_LUT_Register_LMS_lut_value	0
	/* Register Bit Widths for DPE_INCSC_LMS_LUT_Register */
	#define BWID_DPE_INCSC_LMS_LUT_Register_LMS_lut_value	24
	/* Register Bit MASKS for DPE_INCSC_LMS_LUT_Register */
	#define BMSK_DPE_INCSC_LMS_LUT_Register_LMS_lut_value	0x00ffffff /*  */
	/* Register BITFIELD for DPE_INCSC_LMS_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMS_LUT_Register_LMS_lut_value	 0x4610, 0, 24, 0x00ffffff
#define ROFF_DPE_INCSC_LMTA_TL_0_Register	0x4a80 /* INCSC_LMTA_TL_0_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_TL_0_Register	 0x4a80, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_TL_0_Register */
	#define BLSB_DPE_INCSC_LMTA_TL_0_Register_LA_0	16
	#define BLSB_DPE_INCSC_LMTA_TL_0_Register_TA_0	0
	/* Register Bit Widths for DPE_INCSC_LMTA_TL_0_Register */
	#define BWID_DPE_INCSC_LMTA_TL_0_Register_LA_0	12
	#define BWID_DPE_INCSC_LMTA_TL_0_Register_TA_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTA_TL_0_Register */
	#define BMSK_DPE_INCSC_LMTA_TL_0_Register_LA_0	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_LMTA_TL_0_Register_TA_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_TL_0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_TL_0_Register_LA_0	 0x4a80, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_LMTA_TL_0_Register_TA_0	 0x4a80, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTA_TL_1_Register	0x4a84 /* INCSC_LMTA_TL_1_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_TL_1_Register	 0x4a84, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_TL_1_Register */
	#define BLSB_DPE_INCSC_LMTA_TL_1_Register_LA_0	16
	#define BLSB_DPE_INCSC_LMTA_TL_1_Register_TA_0	0
	/* Register Bit Widths for DPE_INCSC_LMTA_TL_1_Register */
	#define BWID_DPE_INCSC_LMTA_TL_1_Register_LA_0	12
	#define BWID_DPE_INCSC_LMTA_TL_1_Register_TA_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTA_TL_1_Register */
	#define BMSK_DPE_INCSC_LMTA_TL_1_Register_LA_0	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_LMTA_TL_1_Register_TA_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_TL_1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_TL_1_Register_LA_0	 0x4a84, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_LMTA_TL_1_Register_TA_0	 0x4a84, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTA_TL_2_Register	0x4a88 /* INCSC_LMTA_TL_2_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_TL_2_Register	 0x4a88, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_TL_2_Register */
	#define BLSB_DPE_INCSC_LMTA_TL_2_Register_LA_0	16
	#define BLSB_DPE_INCSC_LMTA_TL_2_Register_TA_0	0
	/* Register Bit Widths for DPE_INCSC_LMTA_TL_2_Register */
	#define BWID_DPE_INCSC_LMTA_TL_2_Register_LA_0	12
	#define BWID_DPE_INCSC_LMTA_TL_2_Register_TA_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTA_TL_2_Register */
	#define BMSK_DPE_INCSC_LMTA_TL_2_Register_LA_0	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_LMTA_TL_2_Register_TA_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_TL_2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_TL_2_Register_LA_0	 0x4a88, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_LMTA_TL_2_Register_TA_0	 0x4a88, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTA_TL_3_Register	0x4a8c /* INCSC_LMTA_TL_3_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_TL_3_Register	 0x4a8c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_TL_3_Register */
	#define BLSB_DPE_INCSC_LMTA_TL_3_Register_LA_0	16
	#define BLSB_DPE_INCSC_LMTA_TL_3_Register_TA_0	0
	/* Register Bit Widths for DPE_INCSC_LMTA_TL_3_Register */
	#define BWID_DPE_INCSC_LMTA_TL_3_Register_LA_0	12
	#define BWID_DPE_INCSC_LMTA_TL_3_Register_TA_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTA_TL_3_Register */
	#define BMSK_DPE_INCSC_LMTA_TL_3_Register_LA_0	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_LMTA_TL_3_Register_TA_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_TL_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_TL_3_Register_LA_0	 0x4a8c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_LMTA_TL_3_Register_TA_0	 0x4a8c, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTA_TL_4_Register	0x4a90 /* INCSC_LMTA_TL_4_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_TL_4_Register	 0x4a90, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_TL_4_Register */
	#define BLSB_DPE_INCSC_LMTA_TL_4_Register_LA_0	16
	#define BLSB_DPE_INCSC_LMTA_TL_4_Register_TA_0	0
	/* Register Bit Widths for DPE_INCSC_LMTA_TL_4_Register */
	#define BWID_DPE_INCSC_LMTA_TL_4_Register_LA_0	12
	#define BWID_DPE_INCSC_LMTA_TL_4_Register_TA_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTA_TL_4_Register */
	#define BMSK_DPE_INCSC_LMTA_TL_4_Register_LA_0	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_LMTA_TL_4_Register_TA_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_TL_4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_TL_4_Register_LA_0	 0x4a90, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_LMTA_TL_4_Register_TA_0	 0x4a90, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTA_TL_5_Register	0x4a94 /* INCSC_LMTA_TL_5_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_TL_5_Register	 0x4a94, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_TL_5_Register */
	#define BLSB_DPE_INCSC_LMTA_TL_5_Register_LA_0	16
	#define BLSB_DPE_INCSC_LMTA_TL_5_Register_TA_0	0
	/* Register Bit Widths for DPE_INCSC_LMTA_TL_5_Register */
	#define BWID_DPE_INCSC_LMTA_TL_5_Register_LA_0	12
	#define BWID_DPE_INCSC_LMTA_TL_5_Register_TA_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTA_TL_5_Register */
	#define BMSK_DPE_INCSC_LMTA_TL_5_Register_LA_0	0x0fff0000 /*  */
	#define BMSK_DPE_INCSC_LMTA_TL_5_Register_TA_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_TL_5_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_TL_5_Register_LA_0	 0x4a94, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_INCSC_LMTA_TL_5_Register_TA_0	 0x4a94, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTA_Slope_0_Register	0x4a98 /* INCSC_LMTA_Slope_0_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_Slope_0_Register	 0x4a98, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_Slope_0_Register */
	#define BLSB_DPE_INCSC_LMTA_Slope_0_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTA_Slope_0_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTA_Slope_0_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTA_Slope_0_Register */
	#define BWID_DPE_INCSC_LMTA_Slope_0_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTA_Slope_0_Register_Shift	4
	#define BWID_DPE_INCSC_LMTA_Slope_0_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTA_Slope_0_Register */
	#define BMSK_DPE_INCSC_LMTA_Slope_0_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTA_Slope_0_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTA_Slope_0_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_Slope_0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_Slope_0_Register_Sign_of_slope	 0x4a98, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTA_Slope_0_Register_Shift	 0x4a98, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTA_Slope_0_Register_Slope	 0x4a98, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTA_Slope_1_Register	0x4a9c /* INCSC_LMTA_Slope_1_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_Slope_1_Register	 0x4a9c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_Slope_1_Register */
	#define BLSB_DPE_INCSC_LMTA_Slope_1_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTA_Slope_1_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTA_Slope_1_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTA_Slope_1_Register */
	#define BWID_DPE_INCSC_LMTA_Slope_1_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTA_Slope_1_Register_Shift	4
	#define BWID_DPE_INCSC_LMTA_Slope_1_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTA_Slope_1_Register */
	#define BMSK_DPE_INCSC_LMTA_Slope_1_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTA_Slope_1_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTA_Slope_1_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_Slope_1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_Slope_1_Register_Sign_of_slope	 0x4a9c, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTA_Slope_1_Register_Shift	 0x4a9c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTA_Slope_1_Register_Slope	 0x4a9c, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTA_Slope_2_Register	0x4aa0 /* INCSC_LMTA_Slope_2_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_Slope_2_Register	 0x4aa0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_Slope_2_Register */
	#define BLSB_DPE_INCSC_LMTA_Slope_2_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTA_Slope_2_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTA_Slope_2_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTA_Slope_2_Register */
	#define BWID_DPE_INCSC_LMTA_Slope_2_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTA_Slope_2_Register_Shift	4
	#define BWID_DPE_INCSC_LMTA_Slope_2_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTA_Slope_2_Register */
	#define BMSK_DPE_INCSC_LMTA_Slope_2_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTA_Slope_2_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTA_Slope_2_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_Slope_2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_Slope_2_Register_Sign_of_slope	 0x4aa0, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTA_Slope_2_Register_Shift	 0x4aa0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTA_Slope_2_Register_Slope	 0x4aa0, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTA_Slope_3_Register	0x4aa4 /* INCSC_LMTA_Slope_3_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_Slope_3_Register	 0x4aa4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_Slope_3_Register */
	#define BLSB_DPE_INCSC_LMTA_Slope_3_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTA_Slope_3_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTA_Slope_3_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTA_Slope_3_Register */
	#define BWID_DPE_INCSC_LMTA_Slope_3_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTA_Slope_3_Register_Shift	4
	#define BWID_DPE_INCSC_LMTA_Slope_3_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTA_Slope_3_Register */
	#define BMSK_DPE_INCSC_LMTA_Slope_3_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTA_Slope_3_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTA_Slope_3_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_Slope_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_Slope_3_Register_Sign_of_slope	 0x4aa4, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTA_Slope_3_Register_Shift	 0x4aa4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTA_Slope_3_Register_Slope	 0x4aa4, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTA_Slope_4_Register	0x4aa8 /* INCSC_LMTA_Slope_4_Register */ 
	#define BITFIELD_DPE_INCSC_LMTA_Slope_4_Register	 0x4aa8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTA_Slope_4_Register */
	#define BLSB_DPE_INCSC_LMTA_Slope_4_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTA_Slope_4_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTA_Slope_4_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTA_Slope_4_Register */
	#define BWID_DPE_INCSC_LMTA_Slope_4_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTA_Slope_4_Register_Shift	4
	#define BWID_DPE_INCSC_LMTA_Slope_4_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTA_Slope_4_Register */
	#define BMSK_DPE_INCSC_LMTA_Slope_4_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTA_Slope_4_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTA_Slope_4_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTA_Slope_4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTA_Slope_4_Register_Sign_of_slope	 0x4aa8, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTA_Slope_4_Register_Shift	 0x4aa8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTA_Slope_4_Register_Slope	 0x4aa8, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTB_TL_0_Register	0x4ab0 /* INCSC_LMTB_TL_0_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_TL_0_Register	 0x4ab0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_TL_0_Register */
	#define BLSB_DPE_INCSC_LMTB_TL_0_Register_LB_0	16
	#define BLSB_DPE_INCSC_LMTB_TL_0_Register_TB_0	0
	/* Register Bit Widths for DPE_INCSC_LMTB_TL_0_Register */
	#define BWID_DPE_INCSC_LMTB_TL_0_Register_LB_0	10
	#define BWID_DPE_INCSC_LMTB_TL_0_Register_TB_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTB_TL_0_Register */
	#define BMSK_DPE_INCSC_LMTB_TL_0_Register_LB_0	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_LMTB_TL_0_Register_TB_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_TL_0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_TL_0_Register_LB_0	 0x4ab0, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_LMTB_TL_0_Register_TB_0	 0x4ab0, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTB_TL_1_Register	0x4ab4 /* INCSC_LMTB_TL_1_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_TL_1_Register	 0x4ab4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_TL_1_Register */
	#define BLSB_DPE_INCSC_LMTB_TL_1_Register_LB_0	16
	#define BLSB_DPE_INCSC_LMTB_TL_1_Register_TB_0	0
	/* Register Bit Widths for DPE_INCSC_LMTB_TL_1_Register */
	#define BWID_DPE_INCSC_LMTB_TL_1_Register_LB_0	10
	#define BWID_DPE_INCSC_LMTB_TL_1_Register_TB_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTB_TL_1_Register */
	#define BMSK_DPE_INCSC_LMTB_TL_1_Register_LB_0	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_LMTB_TL_1_Register_TB_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_TL_1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_TL_1_Register_LB_0	 0x4ab4, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_LMTB_TL_1_Register_TB_0	 0x4ab4, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTB_TL_2_Register	0x4ab8 /* INCSC_LMTB_TL_2_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_TL_2_Register	 0x4ab8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_TL_2_Register */
	#define BLSB_DPE_INCSC_LMTB_TL_2_Register_LB_0	16
	#define BLSB_DPE_INCSC_LMTB_TL_2_Register_TB_0	0
	/* Register Bit Widths for DPE_INCSC_LMTB_TL_2_Register */
	#define BWID_DPE_INCSC_LMTB_TL_2_Register_LB_0	10
	#define BWID_DPE_INCSC_LMTB_TL_2_Register_TB_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTB_TL_2_Register */
	#define BMSK_DPE_INCSC_LMTB_TL_2_Register_LB_0	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_LMTB_TL_2_Register_TB_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_TL_2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_TL_2_Register_LB_0	 0x4ab8, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_LMTB_TL_2_Register_TB_0	 0x4ab8, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTB_TL_3_Register	0x4abc /* INCSC_LMTB_TL_3_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_TL_3_Register	 0x4abc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_TL_3_Register */
	#define BLSB_DPE_INCSC_LMTB_TL_3_Register_LB_0	16
	#define BLSB_DPE_INCSC_LMTB_TL_3_Register_TB_0	0
	/* Register Bit Widths for DPE_INCSC_LMTB_TL_3_Register */
	#define BWID_DPE_INCSC_LMTB_TL_3_Register_LB_0	10
	#define BWID_DPE_INCSC_LMTB_TL_3_Register_TB_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTB_TL_3_Register */
	#define BMSK_DPE_INCSC_LMTB_TL_3_Register_LB_0	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_LMTB_TL_3_Register_TB_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_TL_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_TL_3_Register_LB_0	 0x4abc, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_LMTB_TL_3_Register_TB_0	 0x4abc, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTB_TL_4_Register	0x4ac0 /* INCSC_LMTB_TL_4_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_TL_4_Register	 0x4ac0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_TL_4_Register */
	#define BLSB_DPE_INCSC_LMTB_TL_4_Register_LB_0	16
	#define BLSB_DPE_INCSC_LMTB_TL_4_Register_TB_0	0
	/* Register Bit Widths for DPE_INCSC_LMTB_TL_4_Register */
	#define BWID_DPE_INCSC_LMTB_TL_4_Register_LB_0	10
	#define BWID_DPE_INCSC_LMTB_TL_4_Register_TB_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTB_TL_4_Register */
	#define BMSK_DPE_INCSC_LMTB_TL_4_Register_LB_0	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_LMTB_TL_4_Register_TB_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_TL_4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_TL_4_Register_LB_0	 0x4ac0, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_LMTB_TL_4_Register_TB_0	 0x4ac0, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTB_TL_5_Register	0x4ac4 /* INCSC_LMTB_TL_5_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_TL_5_Register	 0x4ac4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_TL_5_Register */
	#define BLSB_DPE_INCSC_LMTB_TL_5_Register_LB_0	16
	#define BLSB_DPE_INCSC_LMTB_TL_5_Register_TB_0	0
	/* Register Bit Widths for DPE_INCSC_LMTB_TL_5_Register */
	#define BWID_DPE_INCSC_LMTB_TL_5_Register_LB_0	10
	#define BWID_DPE_INCSC_LMTB_TL_5_Register_TB_0	10
	/* Register Bit MASKS for DPE_INCSC_LMTB_TL_5_Register */
	#define BMSK_DPE_INCSC_LMTB_TL_5_Register_LB_0	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_LMTB_TL_5_Register_TB_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_TL_5_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_TL_5_Register_LB_0	 0x4ac4, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_LMTB_TL_5_Register_TB_0	 0x4ac4, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_LMTB_Slope_0_Register	0x4ac8 /* INCSC_LMTB_Slope_0_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_Slope_0_Register	 0x4ac8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_Slope_0_Register */
	#define BLSB_DPE_INCSC_LMTB_Slope_0_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTB_Slope_0_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTB_Slope_0_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTB_Slope_0_Register */
	#define BWID_DPE_INCSC_LMTB_Slope_0_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTB_Slope_0_Register_Shift	4
	#define BWID_DPE_INCSC_LMTB_Slope_0_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTB_Slope_0_Register */
	#define BMSK_DPE_INCSC_LMTB_Slope_0_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTB_Slope_0_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTB_Slope_0_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_Slope_0_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_Slope_0_Register_Sign_of_slope	 0x4ac8, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTB_Slope_0_Register_Shift	 0x4ac8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTB_Slope_0_Register_Slope	 0x4ac8, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTB_Slope_1_Register	0x4acc /* INCSC_LMTB_Slope_1_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_Slope_1_Register	 0x4acc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_Slope_1_Register */
	#define BLSB_DPE_INCSC_LMTB_Slope_1_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTB_Slope_1_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTB_Slope_1_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTB_Slope_1_Register */
	#define BWID_DPE_INCSC_LMTB_Slope_1_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTB_Slope_1_Register_Shift	4
	#define BWID_DPE_INCSC_LMTB_Slope_1_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTB_Slope_1_Register */
	#define BMSK_DPE_INCSC_LMTB_Slope_1_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTB_Slope_1_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTB_Slope_1_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_Slope_1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_Slope_1_Register_Sign_of_slope	 0x4acc, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTB_Slope_1_Register_Shift	 0x4acc, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTB_Slope_1_Register_Slope	 0x4acc, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTB_Slope_2_Register	0x4ad0 /* INCSC_LMTB_Slope_2_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_Slope_2_Register	 0x4ad0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_Slope_2_Register */
	#define BLSB_DPE_INCSC_LMTB_Slope_2_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTB_Slope_2_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTB_Slope_2_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTB_Slope_2_Register */
	#define BWID_DPE_INCSC_LMTB_Slope_2_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTB_Slope_2_Register_Shift	4
	#define BWID_DPE_INCSC_LMTB_Slope_2_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTB_Slope_2_Register */
	#define BMSK_DPE_INCSC_LMTB_Slope_2_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTB_Slope_2_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTB_Slope_2_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_Slope_2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_Slope_2_Register_Sign_of_slope	 0x4ad0, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTB_Slope_2_Register_Shift	 0x4ad0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTB_Slope_2_Register_Slope	 0x4ad0, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTB_Slope_3_Register	0x4ad4 /* INCSC_LMTB_Slope_3_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_Slope_3_Register	 0x4ad4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_Slope_3_Register */
	#define BLSB_DPE_INCSC_LMTB_Slope_3_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTB_Slope_3_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTB_Slope_3_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTB_Slope_3_Register */
	#define BWID_DPE_INCSC_LMTB_Slope_3_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTB_Slope_3_Register_Shift	4
	#define BWID_DPE_INCSC_LMTB_Slope_3_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTB_Slope_3_Register */
	#define BMSK_DPE_INCSC_LMTB_Slope_3_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTB_Slope_3_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTB_Slope_3_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_Slope_3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_Slope_3_Register_Sign_of_slope	 0x4ad4, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTB_Slope_3_Register_Shift	 0x4ad4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTB_Slope_3_Register_Slope	 0x4ad4, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_LMTB_Slope_4_Register	0x4ad8 /* INCSC_LMTB_Slope_4_Register */ 
	#define BITFIELD_DPE_INCSC_LMTB_Slope_4_Register	 0x4ad8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_LMTB_Slope_4_Register */
	#define BLSB_DPE_INCSC_LMTB_Slope_4_Register_Sign_of_slope	15
	#define BLSB_DPE_INCSC_LMTB_Slope_4_Register_Shift	8
	#define BLSB_DPE_INCSC_LMTB_Slope_4_Register_Slope	0
	/* Register Bit Widths for DPE_INCSC_LMTB_Slope_4_Register */
	#define BWID_DPE_INCSC_LMTB_Slope_4_Register_Sign_of_slope	1
	#define BWID_DPE_INCSC_LMTB_Slope_4_Register_Shift	4
	#define BWID_DPE_INCSC_LMTB_Slope_4_Register_Slope	5
	/* Register Bit MASKS for DPE_INCSC_LMTB_Slope_4_Register */
	#define BMSK_DPE_INCSC_LMTB_Slope_4_Register_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_INCSC_LMTB_Slope_4_Register_Shift	0x00000f00 /*  */
	#define BMSK_DPE_INCSC_LMTB_Slope_4_Register_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_INCSC_LMTB_Slope_4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_LMTB_Slope_4_Register_Sign_of_slope	 0x4ad8, 15, 1, 0x00008000
	#define BITFIELD_DPE_INCSC_LMTB_Slope_4_Register_Shift	 0x4ad8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_INCSC_LMTB_Slope_4_Register_Slope	 0x4ad8, 0, 5, 0x0000001f
#define ROFF_DPE_INCSC_xyz_coeff_a1_Register	0x4ae0 /* INCSC_xyz_coeff_a1_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_a1_Register	 0x4ae0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_a1_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_a1_Register_coeff_a1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_a1_Register */
	#define BWID_DPE_INCSC_xyz_coeff_a1_Register_coeff_a1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_a1_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_a1_Register_coeff_a1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_a1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_a1_Register_coeff_a1	 0x4ae0, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_a2_Register	0x4ae4 /* INCSC_xyz_coeff_a2_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_a2_Register	 0x4ae4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_a2_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_a2_Register_coeff_a1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_a2_Register */
	#define BWID_DPE_INCSC_xyz_coeff_a2_Register_coeff_a1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_a2_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_a2_Register_coeff_a1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_a2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_a2_Register_coeff_a1	 0x4ae4, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_a3_Register	0x4ae8 /* INCSC_xyz_coeff_a3_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_a3_Register	 0x4ae8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_a3_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_a3_Register_coeff_a1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_a3_Register */
	#define BWID_DPE_INCSC_xyz_coeff_a3_Register_coeff_a1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_a3_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_a3_Register_coeff_a1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_a3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_a3_Register_coeff_a1	 0x4ae8, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_b1_Register	0x4aec /* INCSC_xyz_coeff_b1_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_b1_Register	 0x4aec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_b1_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_b1_Register_coeff_b1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_b1_Register */
	#define BWID_DPE_INCSC_xyz_coeff_b1_Register_coeff_b1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_b1_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_b1_Register_coeff_b1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_b1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_b1_Register_coeff_b1	 0x4aec, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_b2_Register	0x4af0 /* INCSC_xyz_coeff_b2_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_b2_Register	 0x4af0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_b2_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_b2_Register_coeff_b1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_b2_Register */
	#define BWID_DPE_INCSC_xyz_coeff_b2_Register_coeff_b1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_b2_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_b2_Register_coeff_b1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_b2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_b2_Register_coeff_b1	 0x4af0, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_b3_Register	0x4af4 /* INCSC_xyz_coeff_b3_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_b3_Register	 0x4af4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_b3_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_b3_Register_coeff_b1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_b3_Register */
	#define BWID_DPE_INCSC_xyz_coeff_b3_Register_coeff_b1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_b3_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_b3_Register_coeff_b1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_b3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_b3_Register_coeff_b1	 0x4af4, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_c1_Register	0x4af8 /* INCSC_xyz_coeff_c1_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_c1_Register	 0x4af8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_c1_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_c1_Register_coeff_c1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_c1_Register */
	#define BWID_DPE_INCSC_xyz_coeff_c1_Register_coeff_c1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_c1_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_c1_Register_coeff_c1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_c1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_c1_Register_coeff_c1	 0x4af8, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_c2_Register	0x4afc /* INCSC_xyz_coeff_c2_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_c2_Register	 0x4afc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_c2_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_c2_Register_coeff_c1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_c2_Register */
	#define BWID_DPE_INCSC_xyz_coeff_c2_Register_coeff_c1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_c2_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_c2_Register_coeff_c1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_c2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_c2_Register_coeff_c1	 0x4afc, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_c3_Register	0x4b00 /* INCSC_xyz_coeff_c3_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_c3_Register	 0x4b00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_c3_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_c3_Register_coeff_c1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_c3_Register */
	#define BWID_DPE_INCSC_xyz_coeff_c3_Register_coeff_c1	13
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_c3_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_c3_Register_coeff_c1	0x00001fff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_c3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_c3_Register_coeff_c1	 0x4b00, 0, 13, 0x00001fff
#define ROFF_DPE_INCSC_xyz_coeff_d1_Register	0x4b04 /* INCSC_xyz_coeff_d1_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_d1_Register	 0x4b04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_d1_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_d1_Register_offset_d1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_d1_Register */
	#define BWID_DPE_INCSC_xyz_coeff_d1_Register_offset_d1	11
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_d1_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_d1_Register_offset_d1	0x000007ff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_d1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_d1_Register_offset_d1	 0x4b04, 0, 11, 0x000007ff
#define ROFF_DPE_INCSC_xyz_coeff_d2_Register	0x4b08 /* INCSC_xyz_coeff_d2_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_d2_Register	 0x4b08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_d2_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_d2_Register_offset_d1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_d2_Register */
	#define BWID_DPE_INCSC_xyz_coeff_d2_Register_offset_d1	11
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_d2_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_d2_Register_offset_d1	0x000007ff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_d2_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_d2_Register_offset_d1	 0x4b08, 0, 11, 0x000007ff
#define ROFF_DPE_INCSC_xyz_coeff_d3_Register	0x4b0c /* INCSC_xyz_coeff_d3_Register */ 
	#define BITFIELD_DPE_INCSC_xyz_coeff_d3_Register	 0x4b0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_xyz_coeff_d3_Register */
	#define BLSB_DPE_INCSC_xyz_coeff_d3_Register_offset_d1	0
	/* Register Bit Widths for DPE_INCSC_xyz_coeff_d3_Register */
	#define BWID_DPE_INCSC_xyz_coeff_d3_Register_offset_d1	11
	/* Register Bit MASKS for DPE_INCSC_xyz_coeff_d3_Register */
	#define BMSK_DPE_INCSC_xyz_coeff_d3_Register_offset_d1	0x000007ff /*  */
	/* Register BITFIELD for DPE_INCSC_xyz_coeff_d3_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_xyz_coeff_d3_Register_offset_d1	 0x4b0c, 0, 11, 0x000007ff
#define ROFF_DPE_INCSC_Select_Register	0x4b10 /* INCSC_Select_Register */ 
	#define BITFIELD_DPE_INCSC_Select_Register	 0x4b10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Select_Register */
	#define BLSB_DPE_INCSC_Select_Register_Ycr_select_min	10
	#define BLSB_DPE_INCSC_Select_Register_Lmtb_select_2	8
	#define BLSB_DPE_INCSC_Select_Register_Lmtb_select_1	6
	#define BLSB_DPE_INCSC_Select_Register_Lmta_select_3	4
	#define BLSB_DPE_INCSC_Select_Register_Lmta_select_2	2
	#define BLSB_DPE_INCSC_Select_Register_Lmta_select_1	0
	/* Register Bit Widths for DPE_INCSC_Select_Register */
	#define BWID_DPE_INCSC_Select_Register_Ycr_select_min	2
	#define BWID_DPE_INCSC_Select_Register_Lmtb_select_2	2
	#define BWID_DPE_INCSC_Select_Register_Lmtb_select_1	2
	#define BWID_DPE_INCSC_Select_Register_Lmta_select_3	2
	#define BWID_DPE_INCSC_Select_Register_Lmta_select_2	2
	#define BWID_DPE_INCSC_Select_Register_Lmta_select_1	2
	/* Register Bit MASKS for DPE_INCSC_Select_Register */
	#define BMSK_DPE_INCSC_Select_Register_Ycr_select_min	0x00000c00 /*  */
	#define BMSK_DPE_INCSC_Select_Register_Lmtb_select_2	0x00000300 /*  */
	#define BMSK_DPE_INCSC_Select_Register_Lmtb_select_1	0x000000c0 /*  */
	#define BMSK_DPE_INCSC_Select_Register_Lmta_select_3	0x00000030 /*  */
	#define BMSK_DPE_INCSC_Select_Register_Lmta_select_2	0x0000000c /*  */
	#define BMSK_DPE_INCSC_Select_Register_Lmta_select_1	0x00000003 /*  */
	/* Register BITFIELD for DPE_INCSC_Select_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Select_Register_Ycr_select_min	 0x4b10, 10, 2, 0x00000c00
	#define BITFIELD_DPE_INCSC_Select_Register_Lmtb_select_2	 0x4b10, 8, 2, 0x00000300
	#define BITFIELD_DPE_INCSC_Select_Register_Lmtb_select_1	 0x4b10, 6, 2, 0x000000c0
	#define BITFIELD_DPE_INCSC_Select_Register_Lmta_select_3	 0x4b10, 4, 2, 0x00000030
	#define BITFIELD_DPE_INCSC_Select_Register_Lmta_select_2	 0x4b10, 2, 2, 0x0000000c
	#define BITFIELD_DPE_INCSC_Select_Register_Lmta_select_1	 0x4b10, 0, 2, 0x00000003
#define ROFF_DPE_INCSC_blend_k_Register	0x4b14 /* INCSC_blend_k_Register */ 
	#define BITFIELD_DPE_INCSC_blend_k_Register	 0x4b14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_blend_k_Register */
	#define BLSB_DPE_INCSC_blend_k_Register_blend_k	0
	/* Register Bit Widths for DPE_INCSC_blend_k_Register */
	#define BWID_DPE_INCSC_blend_k_Register_blend_k	8
	/* Register Bit MASKS for DPE_INCSC_blend_k_Register */
	#define BMSK_DPE_INCSC_blend_k_Register_blend_k	0x000000ff /*  */
	/* Register BITFIELD for DPE_INCSC_blend_k_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_blend_k_Register_blend_k	 0x4b14, 0, 8, 0x000000ff
#define ROFF_DPE_INCSC_Y_Gain_Register	0x4b18 /* INCSC_Y_Gain_Register */ 
	#define BITFIELD_DPE_INCSC_Y_Gain_Register	 0x4b18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Y_Gain_Register */
	#define BLSB_DPE_INCSC_Y_Gain_Register_Y_gain	0
	/* Register Bit Widths for DPE_INCSC_Y_Gain_Register */
	#define BWID_DPE_INCSC_Y_Gain_Register_Y_gain	10
	/* Register Bit MASKS for DPE_INCSC_Y_Gain_Register */
	#define BMSK_DPE_INCSC_Y_Gain_Register_Y_gain	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_Y_Gain_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Y_Gain_Register_Y_gain	 0x4b18, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_Y_Offset_Register	0x4b1c /* INCSC_Y_Offset_Register */ 
	#define BITFIELD_DPE_INCSC_Y_Offset_Register	 0x4b1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Y_Offset_Register */
	#define BLSB_DPE_INCSC_Y_Offset_Register_YOutoffset	16
	#define BLSB_DPE_INCSC_Y_Offset_Register_YInoffset	0
	/* Register Bit Widths for DPE_INCSC_Y_Offset_Register */
	#define BWID_DPE_INCSC_Y_Offset_Register_YOutoffset	11
	#define BWID_DPE_INCSC_Y_Offset_Register_YInoffset	11
	/* Register Bit MASKS for DPE_INCSC_Y_Offset_Register */
	#define BMSK_DPE_INCSC_Y_Offset_Register_YOutoffset	0x07ff0000 /*  */
	#define BMSK_DPE_INCSC_Y_Offset_Register_YInoffset	0x000007ff /*  */
	/* Register BITFIELD for DPE_INCSC_Y_Offset_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Y_Offset_Register_YOutoffset	 0x4b1c, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_INCSC_Y_Offset_Register_YInoffset	 0x4b1c, 0, 11, 0x000007ff
#define ROFF_DPE_INCSC_Y_Limit_Register	0x4b20 /* INCSC_Y_Limit_Register */ 
	#define BITFIELD_DPE_INCSC_Y_Limit_Register	 0x4b20, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_Y_Limit_Register */
	#define BLSB_DPE_INCSC_Y_Limit_Register_YMaxlim	16
	#define BLSB_DPE_INCSC_Y_Limit_Register_YMinlin	0
	/* Register Bit Widths for DPE_INCSC_Y_Limit_Register */
	#define BWID_DPE_INCSC_Y_Limit_Register_YMaxlim	10
	#define BWID_DPE_INCSC_Y_Limit_Register_YMinlin	10
	/* Register Bit MASKS for DPE_INCSC_Y_Limit_Register */
	#define BMSK_DPE_INCSC_Y_Limit_Register_YMaxlim	0x03ff0000 /*  */
	#define BMSK_DPE_INCSC_Y_Limit_Register_YMinlin	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_Y_Limit_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_Y_Limit_Register_YMaxlim	 0x4b20, 16, 10, 0x03ff0000
	#define BITFIELD_DPE_INCSC_Y_Limit_Register_YMinlin	 0x4b20, 0, 10, 0x000003ff
#define ROFF_DPE_INCSC_DC_LUT_Eng1_Register	0x4b78 /* INCSC_DC_LUT_Eng1_Register */ 
	#define BITFIELD_DPE_INCSC_DC_LUT_Eng1_Register	 0x4b78, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_DC_LUT_Eng1_Register */
	/* Register Bit Widths for DPE_INCSC_DC_LUT_Eng1_Register */
	/* Register Bit MASKS for DPE_INCSC_DC_LUT_Eng1_Register */
	/* Register BITFIELD for DPE_INCSC_DC_LUT_Eng1_Register - roff, lsb, width, mask */
#define ROFF_DPE_INCSC_DC_LUT_Eng2_Register	0x4b7c /* INCSC_DC_LUT_Eng2_Register */ 
	#define BITFIELD_DPE_INCSC_DC_LUT_Eng2_Register	 0x4b7c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_DC_LUT_Eng2_Register */
	/* Register Bit Widths for DPE_INCSC_DC_LUT_Eng2_Register */
	/* Register Bit MASKS for DPE_INCSC_DC_LUT_Eng2_Register */
	/* Register BITFIELD for DPE_INCSC_DC_LUT_Eng2_Register - roff, lsb, width, mask */
#define ROFF_DPE_INCSC_DC_LUT_Register	0x4b80 /* INCSC_DC_LUT_Register */ 
	#define BITFIELD_DPE_INCSC_DC_LUT_Register	 0x4b80, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_INCSC_DC_LUT_Register */
	#define BLSB_DPE_INCSC_DC_LUT_Register_Y_out	0
	/* Register Bit Widths for DPE_INCSC_DC_LUT_Register */
	#define BWID_DPE_INCSC_DC_LUT_Register_Y_out	10
	/* Register Bit MASKS for DPE_INCSC_DC_LUT_Register */
	#define BMSK_DPE_INCSC_DC_LUT_Register_Y_out	0x000003ff /*  */
	/* Register BITFIELD for DPE_INCSC_DC_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_INCSC_DC_LUT_Register_Y_out	 0x4b80, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_Stride_Height_Register	0x4c80 /* JLCC_Stride_Height_Register */ 
	#define BITFIELD_DPE_JLCC_Stride_Height_Register	 0x4c80, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Stride_Height_Register */
	#define BLSB_DPE_JLCC_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_JLCC_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_JLCC_Stride_Height_Register */
	#define BWID_DPE_JLCC_Stride_Height_Register_num_strides	4
	#define BWID_DPE_JLCC_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_JLCC_Stride_Height_Register */
	#define BMSK_DPE_JLCC_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_JLCC_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_JLCC_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Stride_Height_Register_num_strides	 0x4c80, 12, 4, 0x0000f000
	#define BITFIELD_DPE_JLCC_Stride_Height_Register_stride_h	 0x4c80, 0, 11, 0x000007ff
#define ROFF_DPE_JLCC_Stride_Width_Register	0x4c84 /* JLCC_Stride_Width_Register */ 
	#define BITFIELD_DPE_JLCC_Stride_Width_Register	 0x4c84, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Stride_Width_Register */
	#define BLSB_DPE_JLCC_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_JLCC_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_JLCC_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_JLCC_Stride_Width_Register_RM	6
	#define BLSB_DPE_JLCC_Stride_Width_Register_LM	5
	#define BLSB_DPE_JLCC_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_JLCC_Stride_Width_Register */
	#define BWID_DPE_JLCC_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_JLCC_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_JLCC_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_JLCC_Stride_Width_Register_RM	1
	#define BWID_DPE_JLCC_Stride_Width_Register_LM	1
	#define BWID_DPE_JLCC_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_JLCC_Stride_Width_Register */
	#define BMSK_DPE_JLCC_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_JLCC_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_JLCC_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_JLCC_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_JLCC_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_JLCC_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Stride_Width_Register_next_rd_offset_x	 0x4c84, 27, 5, 0xf8000000
	#define BITFIELD_DPE_JLCC_Stride_Width_Register_pix_coord_x	 0x4c84, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_JLCC_Stride_Width_Register_out_stride_w	 0x4c84, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_JLCC_Stride_Width_Register_RM	 0x4c84, 6, 1, 0x00000040
	#define BITFIELD_DPE_JLCC_Stride_Width_Register_LM	 0x4c84, 5, 1, 0x00000020
	#define BITFIELD_DPE_JLCC_Stride_Width_Register_in_stride_off	 0x4c84, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_CDF_Stride_Width_Register	0x4c88 /* JLCC_CDF_Stride_Width_Register */ 
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register	 0x4c88, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CDF_Stride_Width_Register */
	#define BLSB_DPE_JLCC_CDF_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_JLCC_CDF_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_JLCC_CDF_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_JLCC_CDF_Stride_Width_Register_RM	6
	#define BLSB_DPE_JLCC_CDF_Stride_Width_Register_LM	5
	#define BLSB_DPE_JLCC_CDF_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_JLCC_CDF_Stride_Width_Register */
	#define BWID_DPE_JLCC_CDF_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_JLCC_CDF_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_JLCC_CDF_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_JLCC_CDF_Stride_Width_Register_RM	1
	#define BWID_DPE_JLCC_CDF_Stride_Width_Register_LM	1
	#define BWID_DPE_JLCC_CDF_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_JLCC_CDF_Stride_Width_Register */
	#define BMSK_DPE_JLCC_CDF_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_JLCC_CDF_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_JLCC_CDF_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_JLCC_CDF_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_JLCC_CDF_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_JLCC_CDF_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_CDF_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register_next_rd_offset_x	 0x4c88, 27, 5, 0xf8000000
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register_pix_coord_x	 0x4c88, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register_out_stride_w	 0x4c88, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register_RM	 0x4c88, 6, 1, 0x00000040
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register_LM	 0x4c88, 5, 1, 0x00000020
	#define BITFIELD_DPE_JLCC_CDF_Stride_Width_Register_in_stride_off	 0x4c88, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_Control_Register	0x4c90 /* JLCC_Control_Register */ 
	#define BITFIELD_DPE_JLCC_Control_Register	 0x4c90, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Control_Register */
	#define BLSB_DPE_JLCC_Control_Register_SEL_DCE_LCE	18
	#define BLSB_DPE_JLCC_Control_Register_DCE_TYPE_SEL	17
	#define BLSB_DPE_JLCC_Control_Register_xvYCC_en	16
	#define BLSB_DPE_JLCC_Control_Register_DCE_bypass	13
	#define BLSB_DPE_JLCC_Control_Register_dither_bypass	12
	#define BLSB_DPE_JLCC_Control_Register_bluestretch_bypass	11
	#define BLSB_DPE_JLCC_Control_Register_blue_bypass	10
	#define BLSB_DPE_JLCC_Control_Register_green_bypass	9
	#define BLSB_DPE_JLCC_Control_Register_skin_bypass	8
	#define BLSB_DPE_JLCC_Control_Register_SGB_bypass	7
	#define BLSB_DPE_JLCC_Control_Register_skin_count_bypass	6
	#define BLSB_DPE_JLCC_Control_Register_RGB_to_YUV_bypass	5
	#define BLSB_DPE_JLCC_Control_Register_IPT_to_RGB_bypass	4
	#define BLSB_DPE_JLCC_Control_Register_saturation_bypass	3
	#define BLSB_DPE_JLCC_Control_Register_global_lightness_bypass	2
	#define BLSB_DPE_JLCC_Control_Register_local_contrast_bypass	1
	#define BLSB_DPE_JLCC_Control_Register_jlcc_bypass	0
	/* Register Bit Widths for DPE_JLCC_Control_Register */
	#define BWID_DPE_JLCC_Control_Register_SEL_DCE_LCE	1
	#define BWID_DPE_JLCC_Control_Register_DCE_TYPE_SEL	1
	#define BWID_DPE_JLCC_Control_Register_xvYCC_en	1
	#define BWID_DPE_JLCC_Control_Register_DCE_bypass	1
	#define BWID_DPE_JLCC_Control_Register_dither_bypass	1
	#define BWID_DPE_JLCC_Control_Register_bluestretch_bypass	1
	#define BWID_DPE_JLCC_Control_Register_blue_bypass	1
	#define BWID_DPE_JLCC_Control_Register_green_bypass	1
	#define BWID_DPE_JLCC_Control_Register_skin_bypass	1
	#define BWID_DPE_JLCC_Control_Register_SGB_bypass	1
	#define BWID_DPE_JLCC_Control_Register_skin_count_bypass	1
	#define BWID_DPE_JLCC_Control_Register_RGB_to_YUV_bypass	1
	#define BWID_DPE_JLCC_Control_Register_IPT_to_RGB_bypass	1
	#define BWID_DPE_JLCC_Control_Register_saturation_bypass	1
	#define BWID_DPE_JLCC_Control_Register_global_lightness_bypass	1
	#define BWID_DPE_JLCC_Control_Register_local_contrast_bypass	1
	#define BWID_DPE_JLCC_Control_Register_jlcc_bypass	1
	/* Register Bit MASKS for DPE_JLCC_Control_Register */
	#define BMSK_DPE_JLCC_Control_Register_SEL_DCE_LCE	(1<<18) /* == 0x00040000:  */
	#define BMSK_DPE_JLCC_Control_Register_DCE_TYPE_SEL	(1<<17) /* == 0x00020000:  */
	#define BMSK_DPE_JLCC_Control_Register_xvYCC_en	(1<<16) /* == 0x00010000:  */
	#define BMSK_DPE_JLCC_Control_Register_DCE_bypass	(1<<13) /* == 0x00002000:  */
	#define BMSK_DPE_JLCC_Control_Register_dither_bypass	(1<<12) /* == 0x00001000:  */
	#define BMSK_DPE_JLCC_Control_Register_bluestretch_bypass	(1<<11) /* == 0x00000800:  */
	#define BMSK_DPE_JLCC_Control_Register_blue_bypass	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_JLCC_Control_Register_green_bypass	(1<<9) /* == 0x00000200:  */
	#define BMSK_DPE_JLCC_Control_Register_skin_bypass	(1<<8) /* == 0x00000100:  */
	#define BMSK_DPE_JLCC_Control_Register_SGB_bypass	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_JLCC_Control_Register_skin_count_bypass	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_JLCC_Control_Register_RGB_to_YUV_bypass	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_JLCC_Control_Register_IPT_to_RGB_bypass	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_JLCC_Control_Register_saturation_bypass	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_JLCC_Control_Register_global_lightness_bypass	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_JLCC_Control_Register_local_contrast_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_JLCC_Control_Register_jlcc_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_JLCC_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Control_Register_SEL_DCE_LCE	 0x4c90, 18, 1, 0x00040000
	#define BITFIELD_DPE_JLCC_Control_Register_DCE_TYPE_SEL	 0x4c90, 17, 1, 0x00020000
	#define BITFIELD_DPE_JLCC_Control_Register_xvYCC_en	 0x4c90, 16, 1, 0x00010000
	#define BITFIELD_DPE_JLCC_Control_Register_DCE_bypass	 0x4c90, 13, 1, 0x00002000
	#define BITFIELD_DPE_JLCC_Control_Register_dither_bypass	 0x4c90, 12, 1, 0x00001000
	#define BITFIELD_DPE_JLCC_Control_Register_bluestretch_bypass	 0x4c90, 11, 1, 0x00000800
	#define BITFIELD_DPE_JLCC_Control_Register_blue_bypass	 0x4c90, 10, 1, 0x00000400
	#define BITFIELD_DPE_JLCC_Control_Register_green_bypass	 0x4c90, 9, 1, 0x00000200
	#define BITFIELD_DPE_JLCC_Control_Register_skin_bypass	 0x4c90, 8, 1, 0x00000100
	#define BITFIELD_DPE_JLCC_Control_Register_SGB_bypass	 0x4c90, 7, 1, 0x00000080
	#define BITFIELD_DPE_JLCC_Control_Register_skin_count_bypass	 0x4c90, 6, 1, 0x00000040
	#define BITFIELD_DPE_JLCC_Control_Register_RGB_to_YUV_bypass	 0x4c90, 5, 1, 0x00000020
	#define BITFIELD_DPE_JLCC_Control_Register_IPT_to_RGB_bypass	 0x4c90, 4, 1, 0x00000010
	#define BITFIELD_DPE_JLCC_Control_Register_saturation_bypass	 0x4c90, 3, 1, 0x00000008
	#define BITFIELD_DPE_JLCC_Control_Register_global_lightness_bypass	 0x4c90, 2, 1, 0x00000004
	#define BITFIELD_DPE_JLCC_Control_Register_local_contrast_bypass	 0x4c90, 1, 1, 0x00000002
	#define BITFIELD_DPE_JLCC_Control_Register_jlcc_bypass	 0x4c90, 0, 1, 0x00000001
#define ROFF_DPE_JLCC_I_RANGE_EXP_Register	0x4c98 /* JLCC_I_RANGE_EXP_Register */ 
	#define BITFIELD_DPE_JLCC_I_RANGE_EXP_Register	 0x4c98, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_I_RANGE_EXP_Register */
	#define BLSB_DPE_JLCC_I_RANGE_EXP_Register_I_offset	16
	#define BLSB_DPE_JLCC_I_RANGE_EXP_Register_I_gain	0
	/* Register Bit Widths for DPE_JLCC_I_RANGE_EXP_Register */
	#define BWID_DPE_JLCC_I_RANGE_EXP_Register_I_offset	13
	#define BWID_DPE_JLCC_I_RANGE_EXP_Register_I_gain	14
	/* Register Bit MASKS for DPE_JLCC_I_RANGE_EXP_Register */
	#define BMSK_DPE_JLCC_I_RANGE_EXP_Register_I_offset	0x1fff0000 /*  */
	#define BMSK_DPE_JLCC_I_RANGE_EXP_Register_I_gain	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_I_RANGE_EXP_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_I_RANGE_EXP_Register_I_offset	 0x4c98, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_JLCC_I_RANGE_EXP_Register_I_gain	 0x4c98, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_I_RANGE_MAXMIN_Register	0x4c9c /* JLCC_I_RANGE_MAXMIN_Register */ 
	#define BITFIELD_DPE_JLCC_I_RANGE_MAXMIN_Register	 0x4c9c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_I_RANGE_MAXMIN_Register */
	#define BLSB_DPE_JLCC_I_RANGE_MAXMIN_Register_I_max	16
	#define BLSB_DPE_JLCC_I_RANGE_MAXMIN_Register_I_min	0
	/* Register Bit Widths for DPE_JLCC_I_RANGE_MAXMIN_Register */
	#define BWID_DPE_JLCC_I_RANGE_MAXMIN_Register_I_max	14
	#define BWID_DPE_JLCC_I_RANGE_MAXMIN_Register_I_min	14
	/* Register Bit MASKS for DPE_JLCC_I_RANGE_MAXMIN_Register */
	#define BMSK_DPE_JLCC_I_RANGE_MAXMIN_Register_I_max	0x3fff0000 /*  */
	#define BMSK_DPE_JLCC_I_RANGE_MAXMIN_Register_I_min	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_I_RANGE_MAXMIN_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_I_RANGE_MAXMIN_Register_I_max	 0x4c9c, 16, 14, 0x3fff0000
	#define BITFIELD_DPE_JLCC_I_RANGE_MAXMIN_Register_I_min	 0x4c9c, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CSC_YG_OFFSET_Register	0x4ca0 /* JLCC_CSC_YG_OFFSET_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_YG_OFFSET_Register	 0x4ca0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_YG_OFFSET_Register */
	#define BLSB_DPE_JLCC_CSC_YG_OFFSET_Register_YG_OOFF	16
	#define BLSB_DPE_JLCC_CSC_YG_OFFSET_Register_YG_IOFF	0
	/* Register Bit Widths for DPE_JLCC_CSC_YG_OFFSET_Register */
	#define BWID_DPE_JLCC_CSC_YG_OFFSET_Register_YG_OOFF	16
	#define BWID_DPE_JLCC_CSC_YG_OFFSET_Register_YG_IOFF	16
	/* Register Bit MASKS for DPE_JLCC_CSC_YG_OFFSET_Register */
	#define BMSK_DPE_JLCC_CSC_YG_OFFSET_Register_YG_OOFF	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_YG_OFFSET_Register_YG_IOFF	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_YG_OFFSET_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_YG_OFFSET_Register_YG_OOFF	 0x4ca0, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_YG_OFFSET_Register_YG_IOFF	 0x4ca0, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_CbB_OFFSET_Register	0x4ca4 /* JLCC_CSC_CbB_OFFSET_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_CbB_OFFSET_Register	 0x4ca4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_CbB_OFFSET_Register */
	#define BLSB_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_OOFF	16
	#define BLSB_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_IOFF	0
	/* Register Bit Widths for DPE_JLCC_CSC_CbB_OFFSET_Register */
	#define BWID_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_OOFF	16
	#define BWID_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_IOFF	16
	/* Register Bit MASKS for DPE_JLCC_CSC_CbB_OFFSET_Register */
	#define BMSK_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_OOFF	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_IOFF	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_CbB_OFFSET_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_OOFF	 0x4ca4, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_CbB_OFFSET_Register_CB_IOFF	 0x4ca4, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_CrR_OFFSET_Register	0x4ca8 /* JLCC_CSC_CrR_OFFSET_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_CrR_OFFSET_Register	 0x4ca8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_CrR_OFFSET_Register */
	#define BLSB_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_OOFF	16
	#define BLSB_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_IOFF	0
	/* Register Bit Widths for DPE_JLCC_CSC_CrR_OFFSET_Register */
	#define BWID_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_OOFF	16
	#define BWID_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_IOFF	16
	/* Register Bit MASKS for DPE_JLCC_CSC_CrR_OFFSET_Register */
	#define BMSK_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_OOFF	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_IOFF	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_CrR_OFFSET_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_OOFF	 0x4ca8, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_CrR_OFFSET_Register_CR_IOFF	 0x4ca8, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_Coefficient_01_Register	0x4cac /* JLCC_CSC_Coefficient_01_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_01_Register	 0x4cac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_Coefficient_01_Register */
	#define BLSB_DPE_JLCC_CSC_Coefficient_01_Register_C5	16
	#define BLSB_DPE_JLCC_CSC_Coefficient_01_Register_C4	0
	/* Register Bit Widths for DPE_JLCC_CSC_Coefficient_01_Register */
	#define BWID_DPE_JLCC_CSC_Coefficient_01_Register_C5	16
	#define BWID_DPE_JLCC_CSC_Coefficient_01_Register_C4	16
	/* Register Bit MASKS for DPE_JLCC_CSC_Coefficient_01_Register */
	#define BMSK_DPE_JLCC_CSC_Coefficient_01_Register_C5	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_Coefficient_01_Register_C4	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_Coefficient_01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_01_Register_C5	 0x4cac, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_01_Register_C4	 0x4cac, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_Coefficient_23_Register	0x4cb0 /* JLCC_CSC_Coefficient_23_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_23_Register	 0x4cb0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_Coefficient_23_Register */
	#define BLSB_DPE_JLCC_CSC_Coefficient_23_Register_C3	16
	#define BLSB_DPE_JLCC_CSC_Coefficient_23_Register_C2	0
	/* Register Bit Widths for DPE_JLCC_CSC_Coefficient_23_Register */
	#define BWID_DPE_JLCC_CSC_Coefficient_23_Register_C3	16
	#define BWID_DPE_JLCC_CSC_Coefficient_23_Register_C2	16
	/* Register Bit MASKS for DPE_JLCC_CSC_Coefficient_23_Register */
	#define BMSK_DPE_JLCC_CSC_Coefficient_23_Register_C3	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_Coefficient_23_Register_C2	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_Coefficient_23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_23_Register_C3	 0x4cb0, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_23_Register_C2	 0x4cb0, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_Coefficient_45_Register	0x4cb4 /* JLCC_CSC_Coefficient_45_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_45_Register	 0x4cb4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_Coefficient_45_Register */
	#define BLSB_DPE_JLCC_CSC_Coefficient_45_Register_C5	16
	#define BLSB_DPE_JLCC_CSC_Coefficient_45_Register_C4	0
	/* Register Bit Widths for DPE_JLCC_CSC_Coefficient_45_Register */
	#define BWID_DPE_JLCC_CSC_Coefficient_45_Register_C5	16
	#define BWID_DPE_JLCC_CSC_Coefficient_45_Register_C4	16
	/* Register Bit MASKS for DPE_JLCC_CSC_Coefficient_45_Register */
	#define BMSK_DPE_JLCC_CSC_Coefficient_45_Register_C5	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_Coefficient_45_Register_C4	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_Coefficient_45_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_45_Register_C5	 0x4cb4, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_45_Register_C4	 0x4cb4, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_Coefficient_67_Register	0x4cb8 /* JLCC_CSC_Coefficient_67_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_67_Register	 0x4cb8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_Coefficient_67_Register */
	#define BLSB_DPE_JLCC_CSC_Coefficient_67_Register_C7	16
	#define BLSB_DPE_JLCC_CSC_Coefficient_67_Register_C6	0
	/* Register Bit Widths for DPE_JLCC_CSC_Coefficient_67_Register */
	#define BWID_DPE_JLCC_CSC_Coefficient_67_Register_C7	16
	#define BWID_DPE_JLCC_CSC_Coefficient_67_Register_C6	16
	/* Register Bit MASKS for DPE_JLCC_CSC_Coefficient_67_Register */
	#define BMSK_DPE_JLCC_CSC_Coefficient_67_Register_C7	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_Coefficient_67_Register_C6	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_Coefficient_67_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_67_Register_C7	 0x4cb8, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_67_Register_C6	 0x4cb8, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_Coefficient_8_Register	0x4cbc /* JLCC_CSC_Coefficient_8_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_8_Register	 0x4cbc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_Coefficient_8_Register */
	#define BLSB_DPE_JLCC_CSC_Coefficient_8_Register_C8	0
	/* Register Bit Widths for DPE_JLCC_CSC_Coefficient_8_Register */
	#define BWID_DPE_JLCC_CSC_Coefficient_8_Register_C8	16
	/* Register Bit MASKS for DPE_JLCC_CSC_Coefficient_8_Register */
	#define BMSK_DPE_JLCC_CSC_Coefficient_8_Register_C8	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_Coefficient_8_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_Coefficient_8_Register_C8	 0x4cbc, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_YG_Input_Clamping_Register	0x4cc0 /* JLCC_CSC_YG_Input_Clamping_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_YG_Input_Clamping_Register	 0x4cc0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_YG_Input_Clamping_Register */
	#define BLSB_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMAX	16
	#define BLSB_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMIN	0
	/* Register Bit Widths for DPE_JLCC_CSC_YG_Input_Clamping_Register */
	#define BWID_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMAX	16
	#define BWID_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMIN	16
	/* Register Bit MASKS for DPE_JLCC_CSC_YG_Input_Clamping_Register */
	#define BMSK_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMAX	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMIN	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_YG_Input_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMAX	 0x4cc0, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_YG_Input_Clamping_Register_YG_IMIN	 0x4cc0, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_CbB_Input_Clamping_Register	0x4cc4 /* JLCC_CSC_CbB_Input_Clamping_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_CbB_Input_Clamping_Register	 0x4cc4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_CbB_Input_Clamping_Register */
	#define BLSB_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMAX	16
	#define BLSB_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMIN	0
	/* Register Bit Widths for DPE_JLCC_CSC_CbB_Input_Clamping_Register */
	#define BWID_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMAX	16
	#define BWID_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMIN	16
	/* Register Bit MASKS for DPE_JLCC_CSC_CbB_Input_Clamping_Register */
	#define BMSK_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMAX	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMIN	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_CbB_Input_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMAX	 0x4cc4, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_CbB_Input_Clamping_Register_CB_IMIN	 0x4cc4, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_CrR_Input_Clamping_Register	0x4cc8 /* JLCC_CSC_CrR_Input_Clamping_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_CrR_Input_Clamping_Register	 0x4cc8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_CrR_Input_Clamping_Register */
	#define BLSB_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMAX	16
	#define BLSB_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMIN	0
	/* Register Bit Widths for DPE_JLCC_CSC_CrR_Input_Clamping_Register */
	#define BWID_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMAX	16
	#define BWID_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMIN	16
	/* Register Bit MASKS for DPE_JLCC_CSC_CrR_Input_Clamping_Register */
	#define BMSK_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMAX	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMIN	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_CrR_Input_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMAX	 0x4cc8, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_CrR_Input_Clamping_Register_CR_IMIN	 0x4cc8, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_YG_Output_Clamping_Register	0x4ccc /* JLCC_CSC_YG_Output_Clamping_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_YG_Output_Clamping_Register	 0x4ccc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_YG_Output_Clamping_Register */
	#define BLSB_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMAX	16
	#define BLSB_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMIN	0
	/* Register Bit Widths for DPE_JLCC_CSC_YG_Output_Clamping_Register */
	#define BWID_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMAX	16
	#define BWID_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMIN	16
	/* Register Bit MASKS for DPE_JLCC_CSC_YG_Output_Clamping_Register */
	#define BMSK_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMAX	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMIN	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_YG_Output_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMAX	 0x4ccc, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_YG_Output_Clamping_Register_YG_OMIN	 0x4ccc, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_CbB_Output_Clamping_Register	0x4cd0 /* JLCC_CSC_CbB_Ouput_Clamping_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_CbB_Output_Clamping_Register	 0x4cd0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_CbB_Output_Clamping_Register */
	#define BLSB_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMAX	16
	#define BLSB_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMIN	0
	/* Register Bit Widths for DPE_JLCC_CSC_CbB_Output_Clamping_Register */
	#define BWID_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMAX	16
	#define BWID_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMIN	16
	/* Register Bit MASKS for DPE_JLCC_CSC_CbB_Output_Clamping_Register */
	#define BMSK_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMAX	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMIN	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_CbB_Output_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMAX	 0x4cd0, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_CbB_Output_Clamping_Register_CB_OMIN	 0x4cd0, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_CSC_CrR_Output_Clamping_Register	0x4cd4 /* JLCC_CSC_CrR_Output_Clamping_Register */ 
	#define BITFIELD_DPE_JLCC_CSC_CrR_Output_Clamping_Register	 0x4cd4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSC_CrR_Output_Clamping_Register */
	#define BLSB_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMAX	16
	#define BLSB_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMIN	0
	/* Register Bit Widths for DPE_JLCC_CSC_CrR_Output_Clamping_Register */
	#define BWID_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMAX	16
	#define BWID_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMIN	16
	/* Register Bit MASKS for DPE_JLCC_CSC_CrR_Output_Clamping_Register */
	#define BMSK_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMAX	0xffff0000 /*  */
	#define BMSK_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMIN	0x0000ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CSC_CrR_Output_Clamping_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMAX	 0x4cd4, 16, 16, 0xffff0000
	#define BITFIELD_DPE_JLCC_CSC_CrR_Output_Clamping_Register_CR_OMIN	 0x4cd4, 0, 16, 0x0000ffff
#define ROFF_DPE_JLCC_OUT_CSC_RGB_LUT_Register	0x4d10 /* JLCC_OUT_CSC_RGB_LUT_Register */ 
	#define BITFIELD_DPE_JLCC_OUT_CSC_RGB_LUT_Register	 0x4d10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_OUT_CSC_RGB_LUT_Register */
	#define BLSB_DPE_JLCC_OUT_CSC_RGB_LUT_Register_RGB_lut_value	0
	/* Register Bit Widths for DPE_JLCC_OUT_CSC_RGB_LUT_Register */
	#define BWID_DPE_JLCC_OUT_CSC_RGB_LUT_Register_RGB_lut_value	24
	/* Register Bit MASKS for DPE_JLCC_OUT_CSC_RGB_LUT_Register */
	#define BMSK_DPE_JLCC_OUT_CSC_RGB_LUT_Register_RGB_lut_value	0x00ffffff /*  */
	/* Register BITFIELD for DPE_JLCC_OUT_CSC_RGB_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_OUT_CSC_RGB_LUT_Register_RGB_lut_value	 0x4d10, 0, 24, 0x00ffffff
#define ROFF_DPE_JLCC_OUT_CSC_LMS_LUT_Register	0x5110 /* JLCC_OUT_CSC_LMS_LUT_Register */ 
	#define BITFIELD_DPE_JLCC_OUT_CSC_LMS_LUT_Register	 0x5110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_OUT_CSC_LMS_LUT_Register */
	#define BLSB_DPE_JLCC_OUT_CSC_LMS_LUT_Register_LMS_lut_value	0
	/* Register Bit Widths for DPE_JLCC_OUT_CSC_LMS_LUT_Register */
	#define BWID_DPE_JLCC_OUT_CSC_LMS_LUT_Register_LMS_lut_value	24
	/* Register Bit MASKS for DPE_JLCC_OUT_CSC_LMS_LUT_Register */
	#define BMSK_DPE_JLCC_OUT_CSC_LMS_LUT_Register_LMS_lut_value	0x00ffffff /*  */
	/* Register BITFIELD for DPE_JLCC_OUT_CSC_LMS_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_OUT_CSC_LMS_LUT_Register_LMS_lut_value	 0x5110, 0, 24, 0x00ffffff
#define ROFF_DPE_JLCC_Local_contrast_LUT_Register	0x5510 /* JLCC_Local_contrast_LUT_Register */ 
	#define BITFIELD_DPE_JLCC_Local_contrast_LUT_Register	 0x5510, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Local_contrast_LUT_Register */
	#define BLSB_DPE_JLCC_Local_contrast_LUT_Register_LC_lut_value	0
	/* Register Bit Widths for DPE_JLCC_Local_contrast_LUT_Register */
	#define BWID_DPE_JLCC_Local_contrast_LUT_Register_LC_lut_value	14
	/* Register Bit MASKS for DPE_JLCC_Local_contrast_LUT_Register */
	#define BMSK_DPE_JLCC_Local_contrast_LUT_Register_LC_lut_value	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_Local_contrast_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Local_contrast_LUT_Register_LC_lut_value	 0x5510, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SIN_LUT_Register	0x5594 /* JLCC_SIN_LUT */ 
	#define BITFIELD_DPE_JLCC_SIN_LUT_Register	 0x5594, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SIN_LUT_Register */
	#define BLSB_DPE_JLCC_SIN_LUT_Register_SIN_lut_value	0
	/* Register Bit Widths for DPE_JLCC_SIN_LUT_Register */
	#define BWID_DPE_JLCC_SIN_LUT_Register_SIN_lut_value	14
	/* Register Bit MASKS for DPE_JLCC_SIN_LUT_Register */
	#define BMSK_DPE_JLCC_SIN_LUT_Register_SIN_lut_value	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SIN_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SIN_LUT_Register_SIN_lut_value	 0x5594, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CHROMA_LUT_Register	0x5618 /* JLCC_CHROMA_LUT */ 
	#define BITFIELD_DPE_JLCC_CHROMA_LUT_Register	 0x5618, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CHROMA_LUT_Register */
	#define BLSB_DPE_JLCC_CHROMA_LUT_Register_Chroma_lut_value	0
	/* Register Bit Widths for DPE_JLCC_CHROMA_LUT_Register */
	#define BWID_DPE_JLCC_CHROMA_LUT_Register_Chroma_lut_value	18
	/* Register Bit MASKS for DPE_JLCC_CHROMA_LUT_Register */
	#define BMSK_DPE_JLCC_CHROMA_LUT_Register_Chroma_lut_value	0x0003ffff /*  */
	/* Register BITFIELD for DPE_JLCC_CHROMA_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CHROMA_LUT_Register_Chroma_lut_value	 0x5618, 0, 18, 0x0003ffff
#define ROFF_DPE_JLCC_SQRT_LUT_Register	0x5698 /* JLCC_SQRT_LUT */ 
	#define BITFIELD_DPE_JLCC_SQRT_LUT_Register	 0x5698, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SQRT_LUT_Register */
	#define BLSB_DPE_JLCC_SQRT_LUT_Register_Sqrt_lut_value	0
	/* Register Bit Widths for DPE_JLCC_SQRT_LUT_Register */
	#define BWID_DPE_JLCC_SQRT_LUT_Register_Sqrt_lut_value	18
	/* Register Bit MASKS for DPE_JLCC_SQRT_LUT_Register */
	#define BMSK_DPE_JLCC_SQRT_LUT_Register_Sqrt_lut_value	0x0003ffff /*  */
	/* Register BITFIELD for DPE_JLCC_SQRT_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SQRT_LUT_Register_Sqrt_lut_value	 0x5698, 0, 18, 0x0003ffff
#define ROFF_DPE_JLCC_GL_GAIN	0x5718 /* JLCC_GL_GAIN */ 
	#define BITFIELD_DPE_JLCC_GL_GAIN	 0x5718, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_GL_GAIN */
	#define BLSB_DPE_JLCC_GL_GAIN_GL_gain	0
	/* Register Bit Widths for DPE_JLCC_GL_GAIN */
	#define BWID_DPE_JLCC_GL_GAIN_GL_gain	18
	/* Register Bit MASKS for DPE_JLCC_GL_GAIN */
	#define BMSK_DPE_JLCC_GL_GAIN_GL_gain	0x0003ffff /*  */
	/* Register BITFIELD for DPE_JLCC_GL_GAIN - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_GL_GAIN_GL_gain	 0x5718, 0, 18, 0x0003ffff
#define ROFF_DPE_JLCC_SAT_GAIN	0x571c /* JLCC_SAT_GAIN */ 
	#define BITFIELD_DPE_JLCC_SAT_GAIN	 0x571c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SAT_GAIN */
	#define BLSB_DPE_JLCC_SAT_GAIN_SAT_gain	0
	/* Register Bit Widths for DPE_JLCC_SAT_GAIN */
	#define BWID_DPE_JLCC_SAT_GAIN_SAT_gain	18
	/* Register Bit MASKS for DPE_JLCC_SAT_GAIN */
	#define BMSK_DPE_JLCC_SAT_GAIN_SAT_gain	0x0003ffff /*  */
	/* Register BITFIELD for DPE_JLCC_SAT_GAIN - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SAT_GAIN_SAT_gain	 0x571c, 0, 18, 0x0003ffff
#define ROFF_DPE_JLCC_CDF_Counters	0x5720 /* JLCC_CDF_Counters */ 
	#define BITFIELD_DPE_JLCC_CDF_Counters	 0x5720, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CDF_Counters */
	#define BLSB_DPE_JLCC_CDF_Counters_CDF0_to_CDF31	0
	/* Register Bit Widths for DPE_JLCC_CDF_Counters */
	#define BWID_DPE_JLCC_CDF_Counters_CDF0_to_CDF31	32
	/* Register Bit MASKS for DPE_JLCC_CDF_Counters */
	#define BMSK_DPE_JLCC_CDF_Counters_CDF0_to_CDF31	0x00000000 /*  */
	/* Register BITFIELD for DPE_JLCC_CDF_Counters - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CDF_Counters_CDF0_to_CDF31	 0x5720, 0, 32, 0x00000000
#define ROFF_DPE_JLCC_GL_Low_threshold	0x57a0 /* JLCC_GL_Low_threshold */ 
	#define BITFIELD_DPE_JLCC_GL_Low_threshold	 0x57a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_GL_Low_threshold */
	#define BLSB_DPE_JLCC_GL_Low_threshold_GL_TH0	0
	/* Register Bit Widths for DPE_JLCC_GL_Low_threshold */
	#define BWID_DPE_JLCC_GL_Low_threshold_GL_TH0	14
	/* Register Bit MASKS for DPE_JLCC_GL_Low_threshold */
	#define BMSK_DPE_JLCC_GL_Low_threshold_GL_TH0	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_GL_Low_threshold - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_GL_Low_threshold_GL_TH0	 0x57a0, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_GL_High_threshold	0x57a4 /* JLCC_GL_High_threshold */ 
	#define BITFIELD_DPE_JLCC_GL_High_threshold	 0x57a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_GL_High_threshold */
	#define BLSB_DPE_JLCC_GL_High_threshold_GL_TH1	0
	/* Register Bit Widths for DPE_JLCC_GL_High_threshold */
	#define BWID_DPE_JLCC_GL_High_threshold_GL_TH1	14
	/* Register Bit MASKS for DPE_JLCC_GL_High_threshold */
	#define BMSK_DPE_JLCC_GL_High_threshold_GL_TH1	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_GL_High_threshold - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_GL_High_threshold_GL_TH1	 0x57a4, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_Global_saturation_low_threshold	0x57a8 /* JLCC_Global_saturation_low_threshold */ 
	#define BITFIELD_DPE_JLCC_Global_saturation_low_threshold	 0x57a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Global_saturation_low_threshold */
	#define BLSB_DPE_JLCC_Global_saturation_low_threshold_GS_TH0	0
	/* Register Bit Widths for DPE_JLCC_Global_saturation_low_threshold */
	#define BWID_DPE_JLCC_Global_saturation_low_threshold_GS_TH0	14
	/* Register Bit MASKS for DPE_JLCC_Global_saturation_low_threshold */
	#define BMSK_DPE_JLCC_Global_saturation_low_threshold_GS_TH0	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_Global_saturation_low_threshold - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Global_saturation_low_threshold_GS_TH0	 0x57a8, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_Global_saturation_high_threshold	0x57ac /* JLCC_Global_saturation_high_threshold */ 
	#define BITFIELD_DPE_JLCC_Global_saturation_high_threshold	 0x57ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Global_saturation_high_threshold */
	#define BLSB_DPE_JLCC_Global_saturation_high_threshold_GS_TH1	0
	/* Register Bit Widths for DPE_JLCC_Global_saturation_high_threshold */
	#define BWID_DPE_JLCC_Global_saturation_high_threshold_GS_TH1	14
	/* Register Bit MASKS for DPE_JLCC_Global_saturation_high_threshold */
	#define BMSK_DPE_JLCC_Global_saturation_high_threshold_GS_TH1	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_Global_saturation_high_threshold - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Global_saturation_high_threshold_GS_TH1	 0x57ac, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_sin_lut_lower_bound	0x57b0 /* JLCC_sin_lut_lower_bound */ 
	#define BITFIELD_DPE_JLCC_sin_lut_lower_bound	 0x57b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_sin_lut_lower_bound */
	#define BLSB_DPE_JLCC_sin_lut_lower_bound_Sin_lut_lower_bound	0
	/* Register Bit Widths for DPE_JLCC_sin_lut_lower_bound */
	#define BWID_DPE_JLCC_sin_lut_lower_bound_Sin_lut_lower_bound	14
	/* Register Bit MASKS for DPE_JLCC_sin_lut_lower_bound */
	#define BMSK_DPE_JLCC_sin_lut_lower_bound_Sin_lut_lower_bound	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_sin_lut_lower_bound - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_sin_lut_lower_bound_Sin_lut_lower_bound	 0x57b0, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_Skin_slope_CSR1	0x57b4 /* JLCC_SGB_Skin_slope_CSR1 */ 
	#define BITFIELD_DPE_JLCC_SGB_Skin_slope_CSR1	 0x57b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_Skin_slope_CSR1 */
	#define BLSB_DPE_JLCC_SGB_Skin_slope_CSR1_CSR_skin_slope	14
	#define BLSB_DPE_JLCC_SGB_Skin_slope_CSR1_CSR1_skin	0
	/* Register Bit Widths for DPE_JLCC_SGB_Skin_slope_CSR1 */
	#define BWID_DPE_JLCC_SGB_Skin_slope_CSR1_CSR_skin_slope	18
	#define BWID_DPE_JLCC_SGB_Skin_slope_CSR1_CSR1_skin	14
	/* Register Bit MASKS for DPE_JLCC_SGB_Skin_slope_CSR1 */
	#define BMSK_DPE_JLCC_SGB_Skin_slope_CSR1_CSR_skin_slope	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_Skin_slope_CSR1_CSR1_skin	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_Skin_slope_CSR1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_Skin_slope_CSR1_CSR_skin_slope	 0x57b4, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_Skin_slope_CSR1_CSR1_skin	 0x57b4, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_Skin_slope_inv_CSR2	0x57b8 /* JLCC_SGB_Skin_slope_inv_CSR2 */ 
	#define BITFIELD_DPE_JLCC_SGB_Skin_slope_inv_CSR2	 0x57b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_Skin_slope_inv_CSR2 */
	#define BLSB_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR_skin_slope_inv	14
	#define BLSB_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR2_skin	0
	/* Register Bit Widths for DPE_JLCC_SGB_Skin_slope_inv_CSR2 */
	#define BWID_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR_skin_slope_inv	18
	#define BWID_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR2_skin	14
	/* Register Bit MASKS for DPE_JLCC_SGB_Skin_slope_inv_CSR2 */
	#define BMSK_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR_skin_slope_inv	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR2_skin	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_Skin_slope_inv_CSR2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR_skin_slope_inv	 0x57b8, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_Skin_slope_inv_CSR2_CSR2_skin	 0x57b8, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_Skin_sat_CSR3	0x57bc /* JLCC_SGB_Skin_sat_CSR3 */ 
	#define BITFIELD_DPE_JLCC_SGB_Skin_sat_CSR3	 0x57bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_Skin_sat_CSR3 */
	#define BLSB_DPE_JLCC_SGB_Skin_sat_CSR3_CSR_skin_sat_factor	14
	#define BLSB_DPE_JLCC_SGB_Skin_sat_CSR3_CSR3_skin	0
	/* Register Bit Widths for DPE_JLCC_SGB_Skin_sat_CSR3 */
	#define BWID_DPE_JLCC_SGB_Skin_sat_CSR3_CSR_skin_sat_factor	18
	#define BWID_DPE_JLCC_SGB_Skin_sat_CSR3_CSR3_skin	14
	/* Register Bit MASKS for DPE_JLCC_SGB_Skin_sat_CSR3 */
	#define BMSK_DPE_JLCC_SGB_Skin_sat_CSR3_CSR_skin_sat_factor	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_Skin_sat_CSR3_CSR3_skin	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_Skin_sat_CSR3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_Skin_sat_CSR3_CSR_skin_sat_factor	 0x57bc, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_Skin_sat_CSR3_CSR3_skin	 0x57bc, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_Green_slope_CSR1	0x57c0 /* JLCC_SGB_Green_slope_CSR1 */ 
	#define BITFIELD_DPE_JLCC_SGB_Green_slope_CSR1	 0x57c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_Green_slope_CSR1 */
	#define BLSB_DPE_JLCC_SGB_Green_slope_CSR1_CSR_green_slope	14
	#define BLSB_DPE_JLCC_SGB_Green_slope_CSR1_CSR1_green	0
	/* Register Bit Widths for DPE_JLCC_SGB_Green_slope_CSR1 */
	#define BWID_DPE_JLCC_SGB_Green_slope_CSR1_CSR_green_slope	18
	#define BWID_DPE_JLCC_SGB_Green_slope_CSR1_CSR1_green	14
	/* Register Bit MASKS for DPE_JLCC_SGB_Green_slope_CSR1 */
	#define BMSK_DPE_JLCC_SGB_Green_slope_CSR1_CSR_green_slope	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_Green_slope_CSR1_CSR1_green	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_Green_slope_CSR1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_Green_slope_CSR1_CSR_green_slope	 0x57c0, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_Green_slope_CSR1_CSR1_green	 0x57c0, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_Green_slope_inv_CSR2	0x57c4 /* JLCC_SGB_Green_slope_inv_CSR2 */ 
	#define BITFIELD_DPE_JLCC_SGB_Green_slope_inv_CSR2	 0x57c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_Green_slope_inv_CSR2 */
	#define BLSB_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR_green_slope_inv	14
	#define BLSB_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR2_green	0
	/* Register Bit Widths for DPE_JLCC_SGB_Green_slope_inv_CSR2 */
	#define BWID_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR_green_slope_inv	18
	#define BWID_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR2_green	14
	/* Register Bit MASKS for DPE_JLCC_SGB_Green_slope_inv_CSR2 */
	#define BMSK_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR_green_slope_inv	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR2_green	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_Green_slope_inv_CSR2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR_green_slope_inv	 0x57c4, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_Green_slope_inv_CSR2_CSR2_green	 0x57c4, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_Green_Sat_CSR3	0x57c8 /* JLCC_SGB_Green_sat_CSR3 */ 
	#define BITFIELD_DPE_JLCC_SGB_Green_Sat_CSR3	 0x57c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_Green_Sat_CSR3 */
	#define BLSB_DPE_JLCC_SGB_Green_Sat_CSR3_CSR_green_sat_factor	14
	#define BLSB_DPE_JLCC_SGB_Green_Sat_CSR3_CSR3_green	0
	/* Register Bit Widths for DPE_JLCC_SGB_Green_Sat_CSR3 */
	#define BWID_DPE_JLCC_SGB_Green_Sat_CSR3_CSR_green_sat_factor	18
	#define BWID_DPE_JLCC_SGB_Green_Sat_CSR3_CSR3_green	14
	/* Register Bit MASKS for DPE_JLCC_SGB_Green_Sat_CSR3 */
	#define BMSK_DPE_JLCC_SGB_Green_Sat_CSR3_CSR_green_sat_factor	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_Green_Sat_CSR3_CSR3_green	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_Green_Sat_CSR3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_Green_Sat_CSR3_CSR_green_sat_factor	 0x57c8, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_Green_Sat_CSR3_CSR3_green	 0x57c8, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_blue_slope_CSR1	0x57cc /* JLCC_SGB_blue_slope_CSR1 */ 
	#define BITFIELD_DPE_JLCC_SGB_blue_slope_CSR1	 0x57cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_blue_slope_CSR1 */
	#define BLSB_DPE_JLCC_SGB_blue_slope_CSR1_CSR_blue_slope	14
	#define BLSB_DPE_JLCC_SGB_blue_slope_CSR1_CSR1_blue	0
	/* Register Bit Widths for DPE_JLCC_SGB_blue_slope_CSR1 */
	#define BWID_DPE_JLCC_SGB_blue_slope_CSR1_CSR_blue_slope	18
	#define BWID_DPE_JLCC_SGB_blue_slope_CSR1_CSR1_blue	14
	/* Register Bit MASKS for DPE_JLCC_SGB_blue_slope_CSR1 */
	#define BMSK_DPE_JLCC_SGB_blue_slope_CSR1_CSR_blue_slope	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_blue_slope_CSR1_CSR1_blue	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_blue_slope_CSR1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_blue_slope_CSR1_CSR_blue_slope	 0x57cc, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_blue_slope_CSR1_CSR1_blue	 0x57cc, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_blue_slope_inv_CSR2	0x57d0 /* JLCC_SGB_blue_slope_inv_CSR2 */ 
	#define BITFIELD_DPE_JLCC_SGB_blue_slope_inv_CSR2	 0x57d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_blue_slope_inv_CSR2 */
	#define BLSB_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR_blue_slope_inv	14
	#define BLSB_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR2_blue	0
	/* Register Bit Widths for DPE_JLCC_SGB_blue_slope_inv_CSR2 */
	#define BWID_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR_blue_slope_inv	18
	#define BWID_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR2_blue	14
	/* Register Bit MASKS for DPE_JLCC_SGB_blue_slope_inv_CSR2 */
	#define BMSK_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR_blue_slope_inv	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR2_blue	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_blue_slope_inv_CSR2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR_blue_slope_inv	 0x57d0, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_blue_slope_inv_CSR2_CSR2_blue	 0x57d0, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_SGB_sat_CSR3	0x57d4 /* JLCC_SGB_sat_CSR3 */ 
	#define BITFIELD_DPE_JLCC_SGB_sat_CSR3	 0x57d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_SGB_sat_CSR3 */
	#define BLSB_DPE_JLCC_SGB_sat_CSR3_CSR_blue_sat_factor	14
	#define BLSB_DPE_JLCC_SGB_sat_CSR3_CSR3_blue	0
	/* Register Bit Widths for DPE_JLCC_SGB_sat_CSR3 */
	#define BWID_DPE_JLCC_SGB_sat_CSR3_CSR_blue_sat_factor	18
	#define BWID_DPE_JLCC_SGB_sat_CSR3_CSR3_blue	14
	/* Register Bit MASKS for DPE_JLCC_SGB_sat_CSR3 */
	#define BMSK_DPE_JLCC_SGB_sat_CSR3_CSR_blue_sat_factor	0xffffc000 /*  */
	#define BMSK_DPE_JLCC_SGB_sat_CSR3_CSR3_blue	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_SGB_sat_CSR3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_SGB_sat_CSR3_CSR_blue_sat_factor	 0x57d4, 14, 18, 0xffffc000
	#define BITFIELD_DPE_JLCC_SGB_sat_CSR3_CSR3_blue	 0x57d4, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CSR_Product1	0x57d8 /* JLCC_CSR_Product1 */ 
	#define BITFIELD_DPE_JLCC_CSR_Product1	 0x57d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSR_Product1 */
	#define BLSB_DPE_JLCC_CSR_Product1_CSR_product2	16
	#define BLSB_DPE_JLCC_CSR_Product1_CSR_product1	0
	/* Register Bit Widths for DPE_JLCC_CSR_Product1 */
	#define BWID_DPE_JLCC_CSR_Product1_CSR_product2	12
	#define BWID_DPE_JLCC_CSR_Product1_CSR_product1	12
	/* Register Bit MASKS for DPE_JLCC_CSR_Product1 */
	#define BMSK_DPE_JLCC_CSR_Product1_CSR_product2	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_CSR_Product1_CSR_product1	0x00000fff /*  */
	/* Register BITFIELD for DPE_JLCC_CSR_Product1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSR_Product1_CSR_product2	 0x57d8, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_CSR_Product1_CSR_product1	 0x57d8, 0, 12, 0x00000fff
#define ROFF_DPE_JLCC_CSR_Smooth1	0x57dc /* JLCC_CSR_Smooth1 */ 
	#define BITFIELD_DPE_JLCC_CSR_Smooth1	 0x57dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSR_Smooth1 */
	#define BLSB_DPE_JLCC_CSR_Smooth1_CSR_Smooth1	0
	/* Register Bit Widths for DPE_JLCC_CSR_Smooth1 */
	#define BWID_DPE_JLCC_CSR_Smooth1_CSR_Smooth1	14
	/* Register Bit MASKS for DPE_JLCC_CSR_Smooth1 */
	#define BMSK_DPE_JLCC_CSR_Smooth1_CSR_Smooth1	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_CSR_Smooth1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSR_Smooth1_CSR_Smooth1	 0x57dc, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CSR_Smooth2	0x1028c /* JLCC_CSR_Smooth2 */ 
	#define BITFIELD_DPE_JLCC_CSR_Smooth2	 0x1028c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSR_Smooth2 */
	#define BLSB_DPE_JLCC_CSR_Smooth2_CSR_Smooth2	0
	/* Register Bit Widths for DPE_JLCC_CSR_Smooth2 */
	#define BWID_DPE_JLCC_CSR_Smooth2_CSR_Smooth2	14
	/* Register Bit MASKS for DPE_JLCC_CSR_Smooth2 */
	#define BMSK_DPE_JLCC_CSR_Smooth2_CSR_Smooth2	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_CSR_Smooth2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSR_Smooth2_CSR_Smooth2	 0x1028c, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CSR_Smooth3	0x57e4 /* JLCC_CSR_Smooth3 */ 
	#define BITFIELD_DPE_JLCC_CSR_Smooth3	 0x57e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSR_Smooth3 */
	#define BLSB_DPE_JLCC_CSR_Smooth3_CSR_Smooth3	0
	/* Register Bit Widths for DPE_JLCC_CSR_Smooth3 */
	#define BWID_DPE_JLCC_CSR_Smooth3_CSR_Smooth3	14
	/* Register Bit MASKS for DPE_JLCC_CSR_Smooth3 */
	#define BMSK_DPE_JLCC_CSR_Smooth3_CSR_Smooth3	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_CSR_Smooth3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSR_Smooth3_CSR_Smooth3	 0x57e4, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CSR_Smooth4	0x57e8 /* JLCC_CSR_Smooth4 */ 
	#define BITFIELD_DPE_JLCC_CSR_Smooth4	 0x57e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSR_Smooth4 */
	#define BLSB_DPE_JLCC_CSR_Smooth4_CSR_Smooth4	0
	/* Register Bit Widths for DPE_JLCC_CSR_Smooth4 */
	#define BWID_DPE_JLCC_CSR_Smooth4_CSR_Smooth4	14
	/* Register Bit MASKS for DPE_JLCC_CSR_Smooth4 */
	#define BMSK_DPE_JLCC_CSR_Smooth4_CSR_Smooth4	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_CSR_Smooth4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSR_Smooth4_CSR_Smooth4	 0x57e8, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_CSR_Smooth5	0x57ec /* JLCC_CSR_Smooth5 */ 
	#define BITFIELD_DPE_JLCC_CSR_Smooth5	 0x57ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_CSR_Smooth5 */
	#define BLSB_DPE_JLCC_CSR_Smooth5_CSR_Smooth5	0
	/* Register Bit Widths for DPE_JLCC_CSR_Smooth5 */
	#define BWID_DPE_JLCC_CSR_Smooth5_CSR_Smooth5	14
	/* Register Bit MASKS for DPE_JLCC_CSR_Smooth5 */
	#define BMSK_DPE_JLCC_CSR_Smooth5_CSR_Smooth5	0x00003fff /*  */
	/* Register BITFIELD for DPE_JLCC_CSR_Smooth5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_CSR_Smooth5_CSR_Smooth5	 0x57ec, 0, 14, 0x00003fff
#define ROFF_DPE_JLCC_Dither_Seed	0x57f0 /* JLCC_Dither_Seed */ 
	#define BITFIELD_DPE_JLCC_Dither_Seed	 0x57f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Dither_Seed */
	#define BLSB_DPE_JLCC_Dither_Seed_Dither_rs2	13
	#define BLSB_DPE_JLCC_Dither_Seed_Dither_rs1	0
	/* Register Bit Widths for DPE_JLCC_Dither_Seed */
	#define BWID_DPE_JLCC_Dither_Seed_Dither_rs2	14
	#define BWID_DPE_JLCC_Dither_Seed_Dither_rs1	13
	/* Register Bit MASKS for DPE_JLCC_Dither_Seed */
	#define BMSK_DPE_JLCC_Dither_Seed_Dither_rs2	0x07ffe000 /*  */
	#define BMSK_DPE_JLCC_Dither_Seed_Dither_rs1	0x00001fff /*  */
	/* Register BITFIELD for DPE_JLCC_Dither_Seed - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Dither_Seed_Dither_rs2	 0x57f0, 13, 14, 0x07ffe000
	#define BITFIELD_DPE_JLCC_Dither_Seed_Dither_rs1	 0x57f0, 0, 13, 0x00001fff
#define ROFF_DPE_JLCC_Dither_Params	0x57f4 /* JLCC_Dither_Params */ 
	#define BITFIELD_DPE_JLCC_Dither_Params	 0x57f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_Dither_Params */
	#define BLSB_DPE_JLCC_Dither_Params_CSR_Dither_bits	18
	#define BLSB_DPE_JLCC_Dither_Params_CSR_delta_th_bits	10
	#define BLSB_DPE_JLCC_Dither_Params_CSR_dither_high_threshold	0
	/* Register Bit Widths for DPE_JLCC_Dither_Params */
	#define BWID_DPE_JLCC_Dither_Params_CSR_Dither_bits	2
	#define BWID_DPE_JLCC_Dither_Params_CSR_delta_th_bits	4
	#define BWID_DPE_JLCC_Dither_Params_CSR_dither_high_threshold	10
	/* Register Bit MASKS for DPE_JLCC_Dither_Params */
	#define BMSK_DPE_JLCC_Dither_Params_CSR_Dither_bits	0x000c0000 /*  */
	#define BMSK_DPE_JLCC_Dither_Params_CSR_delta_th_bits	0x00003c00 /*  */
	#define BMSK_DPE_JLCC_Dither_Params_CSR_dither_high_threshold	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_Dither_Params - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_Dither_Params_CSR_Dither_bits	 0x57f4, 18, 2, 0x000c0000
	#define BITFIELD_DPE_JLCC_Dither_Params_CSR_delta_th_bits	 0x57f4, 10, 4, 0x00003c00
	#define BITFIELD_DPE_JLCC_Dither_Params_CSR_dither_high_threshold	 0x57f4, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_TL_0	0x5800 /* JLCC_LMTC_TL_0 */ 
	#define BITFIELD_DPE_JLCC_LMTC_TL_0	 0x5800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_TL_0 */
	#define BLSB_DPE_JLCC_LMTC_TL_0_LC_0	16
	#define BLSB_DPE_JLCC_LMTC_TL_0_TC_0	0
	/* Register Bit Widths for DPE_JLCC_LMTC_TL_0 */
	#define BWID_DPE_JLCC_LMTC_TL_0_LC_0	12
	#define BWID_DPE_JLCC_LMTC_TL_0_TC_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTC_TL_0 */
	#define BMSK_DPE_JLCC_LMTC_TL_0_LC_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTC_TL_0_TC_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_TL_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_TL_0_LC_0	 0x5800, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTC_TL_0_TC_0	 0x5800, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_TL_1	0x5804 /* JLCC_LMTC_TL_1 */ 
	#define BITFIELD_DPE_JLCC_LMTC_TL_1	 0x5804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_TL_1 */
	#define BLSB_DPE_JLCC_LMTC_TL_1_LC_0	16
	#define BLSB_DPE_JLCC_LMTC_TL_1_TC_0	0
	/* Register Bit Widths for DPE_JLCC_LMTC_TL_1 */
	#define BWID_DPE_JLCC_LMTC_TL_1_LC_0	12
	#define BWID_DPE_JLCC_LMTC_TL_1_TC_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTC_TL_1 */
	#define BMSK_DPE_JLCC_LMTC_TL_1_LC_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTC_TL_1_TC_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_TL_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_TL_1_LC_0	 0x5804, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTC_TL_1_TC_0	 0x5804, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_TL_2	0x5808 /* JLCC_LMTC_TL_2 */ 
	#define BITFIELD_DPE_JLCC_LMTC_TL_2	 0x5808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_TL_2 */
	#define BLSB_DPE_JLCC_LMTC_TL_2_LC_0	16
	#define BLSB_DPE_JLCC_LMTC_TL_2_TC_0	0
	/* Register Bit Widths for DPE_JLCC_LMTC_TL_2 */
	#define BWID_DPE_JLCC_LMTC_TL_2_LC_0	12
	#define BWID_DPE_JLCC_LMTC_TL_2_TC_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTC_TL_2 */
	#define BMSK_DPE_JLCC_LMTC_TL_2_LC_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTC_TL_2_TC_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_TL_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_TL_2_LC_0	 0x5808, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTC_TL_2_TC_0	 0x5808, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_TL_3	0x580c /* JLCC_LMTC_TL_3 */ 
	#define BITFIELD_DPE_JLCC_LMTC_TL_3	 0x580c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_TL_3 */
	#define BLSB_DPE_JLCC_LMTC_TL_3_LC_0	16
	#define BLSB_DPE_JLCC_LMTC_TL_3_TC_0	0
	/* Register Bit Widths for DPE_JLCC_LMTC_TL_3 */
	#define BWID_DPE_JLCC_LMTC_TL_3_LC_0	12
	#define BWID_DPE_JLCC_LMTC_TL_3_TC_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTC_TL_3 */
	#define BMSK_DPE_JLCC_LMTC_TL_3_LC_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTC_TL_3_TC_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_TL_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_TL_3_LC_0	 0x580c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTC_TL_3_TC_0	 0x580c, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_TL_4	0x5810 /* JLCC_LMTC_TL_4 */ 
	#define BITFIELD_DPE_JLCC_LMTC_TL_4	 0x5810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_TL_4 */
	#define BLSB_DPE_JLCC_LMTC_TL_4_LC_0	16
	#define BLSB_DPE_JLCC_LMTC_TL_4_TC_0	0
	/* Register Bit Widths for DPE_JLCC_LMTC_TL_4 */
	#define BWID_DPE_JLCC_LMTC_TL_4_LC_0	12
	#define BWID_DPE_JLCC_LMTC_TL_4_TC_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTC_TL_4 */
	#define BMSK_DPE_JLCC_LMTC_TL_4_LC_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTC_TL_4_TC_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_TL_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_TL_4_LC_0	 0x5810, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTC_TL_4_TC_0	 0x5810, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_TL_5	0x5814 /* JLCC_LMTC_TL_5 */ 
	#define BITFIELD_DPE_JLCC_LMTC_TL_5	 0x5814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_TL_5 */
	#define BLSB_DPE_JLCC_LMTC_TL_5_LC_0	16
	#define BLSB_DPE_JLCC_LMTC_TL_5_TC_0	0
	/* Register Bit Widths for DPE_JLCC_LMTC_TL_5 */
	#define BWID_DPE_JLCC_LMTC_TL_5_LC_0	12
	#define BWID_DPE_JLCC_LMTC_TL_5_TC_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTC_TL_5 */
	#define BMSK_DPE_JLCC_LMTC_TL_5_LC_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTC_TL_5_TC_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_TL_5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_TL_5_LC_0	 0x5814, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTC_TL_5_TC_0	 0x5814, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTC_SLOPE_0	0x5818 /* JLCC_LMTC_SLOPE_0 */ 
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_0	 0x5818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_SLOPE_0 */
	#define BLSB_DPE_JLCC_LMTC_SLOPE_0_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTC_SLOPE_0_Shift	8
	#define BLSB_DPE_JLCC_LMTC_SLOPE_0_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTC_SLOPE_0 */
	#define BWID_DPE_JLCC_LMTC_SLOPE_0_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTC_SLOPE_0_Shift	4
	#define BWID_DPE_JLCC_LMTC_SLOPE_0_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTC_SLOPE_0 */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_0_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_0_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_0_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_SLOPE_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_0_Sign_of_slope	 0x5818, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_0_Shift	 0x5818, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_0_Slope	 0x5818, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTC_SLOPE_1	0x581c /* JLCC_LMTC_SLOPE_1 */ 
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_1	 0x581c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_SLOPE_1 */
	#define BLSB_DPE_JLCC_LMTC_SLOPE_1_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTC_SLOPE_1_Shift	8
	#define BLSB_DPE_JLCC_LMTC_SLOPE_1_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTC_SLOPE_1 */
	#define BWID_DPE_JLCC_LMTC_SLOPE_1_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTC_SLOPE_1_Shift	4
	#define BWID_DPE_JLCC_LMTC_SLOPE_1_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTC_SLOPE_1 */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_1_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_1_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_1_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_SLOPE_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_1_Sign_of_slope	 0x581c, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_1_Shift	 0x581c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_1_Slope	 0x581c, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTC_SLOPE_2	0x5820 /* JLCC_LMTC_SLOPE_2 */ 
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_2	 0x5820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_SLOPE_2 */
	#define BLSB_DPE_JLCC_LMTC_SLOPE_2_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTC_SLOPE_2_Shift	8
	#define BLSB_DPE_JLCC_LMTC_SLOPE_2_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTC_SLOPE_2 */
	#define BWID_DPE_JLCC_LMTC_SLOPE_2_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTC_SLOPE_2_Shift	4
	#define BWID_DPE_JLCC_LMTC_SLOPE_2_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTC_SLOPE_2 */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_2_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_2_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_2_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_SLOPE_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_2_Sign_of_slope	 0x5820, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_2_Shift	 0x5820, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_2_Slope	 0x5820, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTC_SLOPE_3	0x5824 /* JLCC_LMTC_SLOPE_3 */ 
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_3	 0x5824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_SLOPE_3 */
	#define BLSB_DPE_JLCC_LMTC_SLOPE_3_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTC_SLOPE_3_Shift	8
	#define BLSB_DPE_JLCC_LMTC_SLOPE_3_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTC_SLOPE_3 */
	#define BWID_DPE_JLCC_LMTC_SLOPE_3_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTC_SLOPE_3_Shift	4
	#define BWID_DPE_JLCC_LMTC_SLOPE_3_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTC_SLOPE_3 */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_3_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_3_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_3_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_SLOPE_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_3_Sign_of_slope	 0x5824, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_3_Shift	 0x5824, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_3_Slope	 0x5824, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTC_SLOPE_4	0x5828 /* JLCC_LMTC_SLOPE_4 */ 
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_4	 0x5828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTC_SLOPE_4 */
	#define BLSB_DPE_JLCC_LMTC_SLOPE_4_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTC_SLOPE_4_Shift	8
	#define BLSB_DPE_JLCC_LMTC_SLOPE_4_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTC_SLOPE_4 */
	#define BWID_DPE_JLCC_LMTC_SLOPE_4_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTC_SLOPE_4_Shift	4
	#define BWID_DPE_JLCC_LMTC_SLOPE_4_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTC_SLOPE_4 */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_4_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_4_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTC_SLOPE_4_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTC_SLOPE_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_4_Sign_of_slope	 0x5828, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_4_Shift	 0x5828, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTC_SLOPE_4_Slope	 0x5828, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTD_TL_0	0x5830 /* JLCC_LMTD_TL_0 */ 
	#define BITFIELD_DPE_JLCC_LMTD_TL_0	 0x5830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_TL_0 */
	#define BLSB_DPE_JLCC_LMTD_TL_0_LD_0	16
	#define BLSB_DPE_JLCC_LMTD_TL_0_TD_0	0
	/* Register Bit Widths for DPE_JLCC_LMTD_TL_0 */
	#define BWID_DPE_JLCC_LMTD_TL_0_LD_0	12
	#define BWID_DPE_JLCC_LMTD_TL_0_TD_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTD_TL_0 */
	#define BMSK_DPE_JLCC_LMTD_TL_0_LD_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTD_TL_0_TD_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_TL_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_TL_0_LD_0	 0x5830, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTD_TL_0_TD_0	 0x5830, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTD_TL_1	0x5834 /* JLCC_LMTD_TL_1 */ 
	#define BITFIELD_DPE_JLCC_LMTD_TL_1	 0x5834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_TL_1 */
	#define BLSB_DPE_JLCC_LMTD_TL_1_LD_0	16
	#define BLSB_DPE_JLCC_LMTD_TL_1_TD_0	0
	/* Register Bit Widths for DPE_JLCC_LMTD_TL_1 */
	#define BWID_DPE_JLCC_LMTD_TL_1_LD_0	12
	#define BWID_DPE_JLCC_LMTD_TL_1_TD_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTD_TL_1 */
	#define BMSK_DPE_JLCC_LMTD_TL_1_LD_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTD_TL_1_TD_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_TL_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_TL_1_LD_0	 0x5834, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTD_TL_1_TD_0	 0x5834, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTD_TL_2	0x5838 /* JLCC_LMTD_TL_2 */ 
	#define BITFIELD_DPE_JLCC_LMTD_TL_2	 0x5838, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_TL_2 */
	#define BLSB_DPE_JLCC_LMTD_TL_2_LD_0	16
	#define BLSB_DPE_JLCC_LMTD_TL_2_TD_0	0
	/* Register Bit Widths for DPE_JLCC_LMTD_TL_2 */
	#define BWID_DPE_JLCC_LMTD_TL_2_LD_0	12
	#define BWID_DPE_JLCC_LMTD_TL_2_TD_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTD_TL_2 */
	#define BMSK_DPE_JLCC_LMTD_TL_2_LD_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTD_TL_2_TD_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_TL_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_TL_2_LD_0	 0x5838, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTD_TL_2_TD_0	 0x5838, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTD_TL_3	0x583c /* JLCC_LMTD_TL_3 */ 
	#define BITFIELD_DPE_JLCC_LMTD_TL_3	 0x583c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_TL_3 */
	#define BLSB_DPE_JLCC_LMTD_TL_3_LD_0	16
	#define BLSB_DPE_JLCC_LMTD_TL_3_TD_0	0
	/* Register Bit Widths for DPE_JLCC_LMTD_TL_3 */
	#define BWID_DPE_JLCC_LMTD_TL_3_LD_0	12
	#define BWID_DPE_JLCC_LMTD_TL_3_TD_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTD_TL_3 */
	#define BMSK_DPE_JLCC_LMTD_TL_3_LD_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTD_TL_3_TD_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_TL_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_TL_3_LD_0	 0x583c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTD_TL_3_TD_0	 0x583c, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTD_TL_4	0x5840 /* JLCC_LMTD_TL_4 */ 
	#define BITFIELD_DPE_JLCC_LMTD_TL_4	 0x5840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_TL_4 */
	#define BLSB_DPE_JLCC_LMTD_TL_4_LD_0	16
	#define BLSB_DPE_JLCC_LMTD_TL_4_TD_0	0
	/* Register Bit Widths for DPE_JLCC_LMTD_TL_4 */
	#define BWID_DPE_JLCC_LMTD_TL_4_LD_0	12
	#define BWID_DPE_JLCC_LMTD_TL_4_TD_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTD_TL_4 */
	#define BMSK_DPE_JLCC_LMTD_TL_4_LD_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTD_TL_4_TD_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_TL_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_TL_4_LD_0	 0x5840, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTD_TL_4_TD_0	 0x5840, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTD_TL_5	0x5844 /* JLCC_LMTD_TL_5 */ 
	#define BITFIELD_DPE_JLCC_LMTD_TL_5	 0x5844, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_TL_5 */
	#define BLSB_DPE_JLCC_LMTD_TL_5_LD_0	16
	#define BLSB_DPE_JLCC_LMTD_TL_5_TD_0	0
	/* Register Bit Widths for DPE_JLCC_LMTD_TL_5 */
	#define BWID_DPE_JLCC_LMTD_TL_5_LD_0	12
	#define BWID_DPE_JLCC_LMTD_TL_5_TD_0	10
	/* Register Bit MASKS for DPE_JLCC_LMTD_TL_5 */
	#define BMSK_DPE_JLCC_LMTD_TL_5_LD_0	0x0fff0000 /*  */
	#define BMSK_DPE_JLCC_LMTD_TL_5_TD_0	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_TL_5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_TL_5_LD_0	 0x5844, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_JLCC_LMTD_TL_5_TD_0	 0x5844, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_LMTD_SLOPE_0	0x5848 /* JLCC_LMTD_SLOPE_0 */ 
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_0	 0x5848, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_SLOPE_0 */
	#define BLSB_DPE_JLCC_LMTD_SLOPE_0_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTD_SLOPE_0_Shift	8
	#define BLSB_DPE_JLCC_LMTD_SLOPE_0_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTD_SLOPE_0 */
	#define BWID_DPE_JLCC_LMTD_SLOPE_0_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTD_SLOPE_0_Shift	4
	#define BWID_DPE_JLCC_LMTD_SLOPE_0_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTD_SLOPE_0 */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_0_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_0_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_0_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_SLOPE_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_0_Sign_of_slope	 0x5848, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_0_Shift	 0x5848, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_0_Slope	 0x5848, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTD_SLOPE_1	0x584c /* JLCC_LMTD_SLOPE_1 */ 
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_1	 0x584c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_SLOPE_1 */
	#define BLSB_DPE_JLCC_LMTD_SLOPE_1_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTD_SLOPE_1_Shift	8
	#define BLSB_DPE_JLCC_LMTD_SLOPE_1_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTD_SLOPE_1 */
	#define BWID_DPE_JLCC_LMTD_SLOPE_1_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTD_SLOPE_1_Shift	4
	#define BWID_DPE_JLCC_LMTD_SLOPE_1_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTD_SLOPE_1 */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_1_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_1_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_1_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_SLOPE_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_1_Sign_of_slope	 0x584c, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_1_Shift	 0x584c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_1_Slope	 0x584c, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTD_SLOPE_2	0x5850 /* JLCC_LMTD_SLOPE_2 */ 
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_2	 0x5850, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_SLOPE_2 */
	#define BLSB_DPE_JLCC_LMTD_SLOPE_2_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTD_SLOPE_2_Shift	8
	#define BLSB_DPE_JLCC_LMTD_SLOPE_2_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTD_SLOPE_2 */
	#define BWID_DPE_JLCC_LMTD_SLOPE_2_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTD_SLOPE_2_Shift	4
	#define BWID_DPE_JLCC_LMTD_SLOPE_2_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTD_SLOPE_2 */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_2_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_2_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_2_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_SLOPE_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_2_Sign_of_slope	 0x5850, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_2_Shift	 0x5850, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_2_Slope	 0x5850, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTD_SLOPE_3	0x5854 /* JLCC_LMTD_SLOPE_3 */ 
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_3	 0x5854, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_SLOPE_3 */
	#define BLSB_DPE_JLCC_LMTD_SLOPE_3_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTD_SLOPE_3_Shift	8
	#define BLSB_DPE_JLCC_LMTD_SLOPE_3_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTD_SLOPE_3 */
	#define BWID_DPE_JLCC_LMTD_SLOPE_3_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTD_SLOPE_3_Shift	4
	#define BWID_DPE_JLCC_LMTD_SLOPE_3_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTD_SLOPE_3 */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_3_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_3_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_3_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_SLOPE_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_3_Sign_of_slope	 0x5854, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_3_Shift	 0x5854, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_3_Slope	 0x5854, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_LMTD_SLOPE_4	0x5858 /* JLCC_LMTD_SLOPE_4 */ 
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_4	 0x5858, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_LMTD_SLOPE_4 */
	#define BLSB_DPE_JLCC_LMTD_SLOPE_4_Sign_of_slope	15
	#define BLSB_DPE_JLCC_LMTD_SLOPE_4_Shift	8
	#define BLSB_DPE_JLCC_LMTD_SLOPE_4_Slope	0
	/* Register Bit Widths for DPE_JLCC_LMTD_SLOPE_4 */
	#define BWID_DPE_JLCC_LMTD_SLOPE_4_Sign_of_slope	1
	#define BWID_DPE_JLCC_LMTD_SLOPE_4_Shift	4
	#define BWID_DPE_JLCC_LMTD_SLOPE_4_Slope	5
	/* Register Bit MASKS for DPE_JLCC_LMTD_SLOPE_4 */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_4_Sign_of_slope	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_4_Shift	0x00000f00 /*  */
	#define BMSK_DPE_JLCC_LMTD_SLOPE_4_Slope	0x0000001f /*  */
	/* Register BITFIELD for DPE_JLCC_LMTD_SLOPE_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_4_Sign_of_slope	 0x5858, 15, 1, 0x00008000
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_4_Shift	 0x5858, 8, 4, 0x00000f00
	#define BITFIELD_DPE_JLCC_LMTD_SLOPE_4_Slope	 0x5858, 0, 5, 0x0000001f
#define ROFF_DPE_JLCC_YCR_select_gain_register	0x5860 /* JLCC_YCR_select_gain_register */ 
	#define BITFIELD_DPE_JLCC_YCR_select_gain_register	 0x5860, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_YCR_select_gain_register */
	#define BLSB_DPE_JLCC_YCR_select_gain_register_Ycr_select_gain	0
	/* Register Bit Widths for DPE_JLCC_YCR_select_gain_register */
	#define BWID_DPE_JLCC_YCR_select_gain_register_Ycr_select_gain	1
	/* Register Bit MASKS for DPE_JLCC_YCR_select_gain_register */
	#define BMSK_DPE_JLCC_YCR_select_gain_register_Ycr_select_gain	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_JLCC_YCR_select_gain_register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_YCR_select_gain_register_Ycr_select_gain	 0x5860, 0, 1, 0x00000001
#define ROFF_DPE_JLCC_DCE_UNA_UNB	0x5864 /* JLCC_DCE_UNA_UNB */ 
	#define BITFIELD_DPE_JLCC_DCE_UNA_UNB	 0x5864, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_DCE_UNA_UNB */
	#define BLSB_DPE_JLCC_DCE_UNA_UNB_UN_B	4
	#define BLSB_DPE_JLCC_DCE_UNA_UNB_UN_A	0
	/* Register Bit Widths for DPE_JLCC_DCE_UNA_UNB */
	#define BWID_DPE_JLCC_DCE_UNA_UNB_UN_B	3
	#define BWID_DPE_JLCC_DCE_UNA_UNB_UN_A	3
	/* Register Bit MASKS for DPE_JLCC_DCE_UNA_UNB */
	#define BMSK_DPE_JLCC_DCE_UNA_UNB_UN_B	0x00000070 /*  */
	#define BMSK_DPE_JLCC_DCE_UNA_UNB_UN_A	0x00000007 /*  */
	/* Register BITFIELD for DPE_JLCC_DCE_UNA_UNB - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_DCE_UNA_UNB_UN_B	 0x5864, 4, 3, 0x00000070
	#define BITFIELD_DPE_JLCC_DCE_UNA_UNB_UN_A	 0x5864, 0, 3, 0x00000007
#define ROFF_DPE_JLCC_DCE_COL_GA	0x5868 /* JLCC_DCE_COL_GA */ 
	#define BITFIELD_DPE_JLCC_DCE_COL_GA	 0x5868, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_DCE_COL_GA */
	#define BLSB_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_DOWN	8
	#define BLSB_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_UP	0
	/* Register Bit Widths for DPE_JLCC_DCE_COL_GA */
	#define BWID_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_DOWN	8
	#define BWID_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_UP	8
	/* Register Bit MASKS for DPE_JLCC_DCE_COL_GA */
	#define BMSK_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_DOWN	0x0000ff00 /*  */
	#define BMSK_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_UP	0x000000ff /*  */
	/* Register BITFIELD for DPE_JLCC_DCE_COL_GA - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_DOWN	 0x5868, 8, 8, 0x0000ff00
	#define BITFIELD_DPE_JLCC_DCE_COL_GA_DCE_COL_GA_UP	 0x5868, 0, 8, 0x000000ff
#define ROFF_DPE_JLCC_DC_LUT_Register	0x5880 /* JLCC_DC_LUT */ 
	#define BITFIELD_DPE_JLCC_DC_LUT_Register	 0x5880, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_DC_LUT_Register */
	#define BLSB_DPE_JLCC_DC_LUT_Register_Y_out	0
	/* Register Bit Widths for DPE_JLCC_DC_LUT_Register */
	#define BWID_DPE_JLCC_DC_LUT_Register_Y_out	10
	/* Register Bit MASKS for DPE_JLCC_DC_LUT_Register */
	#define BMSK_DPE_JLCC_DC_LUT_Register_Y_out	0x000003ff /*  */
	/* Register BITFIELD for DPE_JLCC_DC_LUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_DC_LUT_Register_Y_out	 0x5880, 0, 10, 0x000003ff
#define ROFF_DPE_JLCC_DC_GAIN_MAP_Register	0x5900 /* JLCC_DC_GAIN_MAP */ 
	#define BITFIELD_DPE_JLCC_DC_GAIN_MAP_Register	 0x5900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_JLCC_DC_GAIN_MAP_Register */
	#define BLSB_DPE_JLCC_DC_GAIN_MAP_Register_Gain_map	0
	/* Register Bit Widths for DPE_JLCC_DC_GAIN_MAP_Register */
	#define BWID_DPE_JLCC_DC_GAIN_MAP_Register_Gain_map	12
	/* Register Bit MASKS for DPE_JLCC_DC_GAIN_MAP_Register */
	#define BMSK_DPE_JLCC_DC_GAIN_MAP_Register_Gain_map	0x00000fff /*  */
	/* Register BITFIELD for DPE_JLCC_DC_GAIN_MAP_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_JLCC_DC_GAIN_MAP_Register_Gain_map	 0x5900, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Control_Register	0x5980 /* SCC_Control_Register */ 
	#define BITFIELD_DPE_SCC_Control_Register	 0x5980, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Control_Register */
	#define BLSB_DPE_SCC_Control_Register_IHS_to_IPT_bypass	2
	#define BLSB_DPE_SCC_Control_Register_IPT_to_IHS_bypass	1
	#define BLSB_DPE_SCC_Control_Register_SCC_all_stage_bypass	0
	/* Register Bit Widths for DPE_SCC_Control_Register */
	#define BWID_DPE_SCC_Control_Register_IHS_to_IPT_bypass	1
	#define BWID_DPE_SCC_Control_Register_IPT_to_IHS_bypass	1
	#define BWID_DPE_SCC_Control_Register_SCC_all_stage_bypass	1
	/* Register Bit MASKS for DPE_SCC_Control_Register */
	#define BMSK_DPE_SCC_Control_Register_IHS_to_IPT_bypass	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_SCC_Control_Register_IPT_to_IHS_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_SCC_Control_Register_SCC_all_stage_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_SCC_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Control_Register_IHS_to_IPT_bypass	 0x5980, 2, 1, 0x00000004
	#define BITFIELD_DPE_SCC_Control_Register_IPT_to_IHS_bypass	 0x5980, 1, 1, 0x00000002
	#define BITFIELD_DPE_SCC_Control_Register_SCC_all_stage_bypass	 0x5980, 0, 1, 0x00000001
#define ROFF_DPE_SCC_xvYcc_Offset_Register	0x5984 /* SCC_xvYcc_Offset_Register */ 
	#define BITFIELD_DPE_SCC_xvYcc_Offset_Register	 0x5984, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_xvYcc_Offset_Register */
	#define BLSB_DPE_SCC_xvYcc_Offset_Register_xvYcc_offset	0
	/* Register Bit Widths for DPE_SCC_xvYcc_Offset_Register */
	#define BWID_DPE_SCC_xvYcc_Offset_Register_xvYcc_offset	13
	/* Register Bit MASKS for DPE_SCC_xvYcc_Offset_Register */
	#define BMSK_DPE_SCC_xvYcc_Offset_Register_xvYcc_offset	0x00001fff /*  */
	/* Register BITFIELD for DPE_SCC_xvYcc_Offset_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_xvYcc_Offset_Register_xvYcc_offset	 0x5984, 0, 13, 0x00001fff
#define ROFF_DPE_SCC_xvYcc_I_RANGE_COMP_Register	0x5988 /* SCC_xvYcc_I_RANGE_COMP_Register */ 
	#define BITFIELD_DPE_SCC_xvYcc_I_RANGE_COMP_Register	 0x5988, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_xvYcc_I_RANGE_COMP_Register */
	#define BLSB_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_offset	16
	#define BLSB_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_Gain	0
	/* Register Bit Widths for DPE_SCC_xvYcc_I_RANGE_COMP_Register */
	#define BWID_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_offset	13
	#define BWID_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_Gain	13
	/* Register Bit MASKS for DPE_SCC_xvYcc_I_RANGE_COMP_Register */
	#define BMSK_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_offset	0x1fff0000 /*  */
	#define BMSK_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_Gain	0x00001fff /*  */
	/* Register BITFIELD for DPE_SCC_xvYcc_I_RANGE_COMP_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_offset	 0x5988, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SCC_xvYcc_I_RANGE_COMP_Register_I_Gain	 0x5988, 0, 13, 0x00001fff
#define ROFF_DPE_SCC_ATanLUT_Register	0x5990 /* SCC_ATanLUT_Register */ 
	#define BITFIELD_DPE_SCC_ATanLUT_Register	 0x5990, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_ATanLUT_Register */
	#define BLSB_DPE_SCC_ATanLUT_Register_ArcTan	0
	/* Register Bit Widths for DPE_SCC_ATanLUT_Register */
	#define BWID_DPE_SCC_ATanLUT_Register_ArcTan	9
	/* Register Bit MASKS for DPE_SCC_ATanLUT_Register */
	#define BMSK_DPE_SCC_ATanLUT_Register_ArcTan	0x000001ff /*  */
	/* Register BITFIELD for DPE_SCC_ATanLUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_ATanLUT_Register_ArcTan	 0x5990, 0, 9, 0x000001ff
#define ROFF_DPE_SCC_SinLUT_Register	0x5a10 /* SCC_SinLUT_Register */ 
	#define BITFIELD_DPE_SCC_SinLUT_Register	 0x5a10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SinLUT_Register */
	#define BLSB_DPE_SCC_SinLUT_Register_Sin	0
	/* Register Bit Widths for DPE_SCC_SinLUT_Register */
	#define BWID_DPE_SCC_SinLUT_Register_Sin	11
	/* Register Bit MASKS for DPE_SCC_SinLUT_Register */
	#define BMSK_DPE_SCC_SinLUT_Register_Sin	0x000007ff /*  */
	/* Register BITFIELD for DPE_SCC_SinLUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SinLUT_Register_Sin	 0x5a10, 0, 11, 0x000007ff
#define ROFF_DPE_SCC_SqrtLUT_Register	0x5a90 /* SCC_SqrtLUT_Register */ 
	#define BITFIELD_DPE_SCC_SqrtLUT_Register	 0x5a90, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SqrtLUT_Register */
	#define BLSB_DPE_SCC_SqrtLUT_Register_Sqrt	0
	/* Register Bit Widths for DPE_SCC_SqrtLUT_Register */
	#define BWID_DPE_SCC_SqrtLUT_Register_Sqrt	12
	/* Register Bit MASKS for DPE_SCC_SqrtLUT_Register */
	#define BMSK_DPE_SCC_SqrtLUT_Register_Sqrt	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_SqrtLUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SqrtLUT_Register_Sqrt	 0x5a90, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_CosLUT_Register	0x5e90 /* SCC_CosLUT_Register */ 
	#define BITFIELD_DPE_SCC_CosLUT_Register	 0x5e90, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_CosLUT_Register */
	#define BLSB_DPE_SCC_CosLUT_Register_Cos	0
	/* Register Bit Widths for DPE_SCC_CosLUT_Register */
	#define BWID_DPE_SCC_CosLUT_Register_Cos	11
	/* Register Bit MASKS for DPE_SCC_CosLUT_Register */
	#define BMSK_DPE_SCC_CosLUT_Register_Cos	0x000007ff /*  */
	/* Register BITFIELD for DPE_SCC_CosLUT_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_CosLUT_Register_Cos	 0x5e90, 0, 11, 0x000007ff
#define ROFF_DPE_SCC_Stage_Control_Register	0x1800 /* SCC_Stage_Control_Register */ 
	#define BITFIELD_DPE_SCC_Stage_Control_Register	 0x1800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Stage_Control_Register */
	#define BLSB_DPE_SCC_Stage_Control_Register_Hue_stage_bypass	3
	#define BLSB_DPE_SCC_Stage_Control_Register_Sat_stage_bypass	2
	#define BLSB_DPE_SCC_Stage_Control_Register_Intensity_stage_bypass	1
	#define BLSB_DPE_SCC_Stage_Control_Register_SCC_stage_bypass	0
	/* Register Bit Widths for DPE_SCC_Stage_Control_Register */
	#define BWID_DPE_SCC_Stage_Control_Register_Hue_stage_bypass	1
	#define BWID_DPE_SCC_Stage_Control_Register_Sat_stage_bypass	1
	#define BWID_DPE_SCC_Stage_Control_Register_Intensity_stage_bypass	1
	#define BWID_DPE_SCC_Stage_Control_Register_SCC_stage_bypass	1
	/* Register Bit MASKS for DPE_SCC_Stage_Control_Register */
	#define BMSK_DPE_SCC_Stage_Control_Register_Hue_stage_bypass	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_SCC_Stage_Control_Register_Sat_stage_bypass	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_SCC_Stage_Control_Register_Intensity_stage_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_SCC_Stage_Control_Register_SCC_stage_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_SCC_Stage_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Stage_Control_Register_Hue_stage_bypass	 0x1800, 3, 1, 0x00000008
	#define BITFIELD_DPE_SCC_Stage_Control_Register_Sat_stage_bypass	 0x1800, 2, 1, 0x00000004
	#define BITFIELD_DPE_SCC_Stage_Control_Register_Intensity_stage_bypass	 0x1800, 1, 1, 0x00000002
	#define BITFIELD_DPE_SCC_Stage_Control_Register_SCC_stage_bypass	 0x1800, 0, 1, 0x00000001
#define ROFF_DPE_SCC_Hue_Threshold_AB_Register	0x1804 /* SCC_Hue_Threshold_AB_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Threshold_AB_Register	 0x1804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Threshold_AB_Register */
	#define BLSB_DPE_SCC_Hue_Threshold_AB_Register_HTH_B_ST_N	16
	#define BLSB_DPE_SCC_Hue_Threshold_AB_Register_HTH_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Hue_Threshold_AB_Register */
	#define BWID_DPE_SCC_Hue_Threshold_AB_Register_HTH_B_ST_N	12
	#define BWID_DPE_SCC_Hue_Threshold_AB_Register_HTH_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Hue_Threshold_AB_Register */
	#define BMSK_DPE_SCC_Hue_Threshold_AB_Register_HTH_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Threshold_AB_Register_HTH_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Threshold_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Threshold_AB_Register_HTH_B_ST_N	 0x1804, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Threshold_AB_Register_HTH_A_ST_N	 0x1804, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Threshold_CD_Register	0x1808 /* SCC_Hue_Threshold_CD_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Threshold_CD_Register	 0x1808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Threshold_CD_Register */
	#define BLSB_DPE_SCC_Hue_Threshold_CD_Register_HTH_D_ST_N	16
	#define BLSB_DPE_SCC_Hue_Threshold_CD_Register_HTH_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Hue_Threshold_CD_Register */
	#define BWID_DPE_SCC_Hue_Threshold_CD_Register_HTH_D_ST_N	12
	#define BWID_DPE_SCC_Hue_Threshold_CD_Register_HTH_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Hue_Threshold_CD_Register */
	#define BMSK_DPE_SCC_Hue_Threshold_CD_Register_HTH_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Threshold_CD_Register_HTH_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Threshold_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Threshold_CD_Register_HTH_D_ST_N	 0x1808, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Threshold_CD_Register_HTH_C_ST_N	 0x1808, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Threshold_E_Register	0x180c /* SCC_Hue_Threshold_E_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Threshold_E_Register	 0x180c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Threshold_E_Register */
	#define BLSB_DPE_SCC_Hue_Threshold_E_Register_HTH_E_ST_N	0
	/* Register Bit Widths for DPE_SCC_Hue_Threshold_E_Register */
	#define BWID_DPE_SCC_Hue_Threshold_E_Register_HTH_E_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Hue_Threshold_E_Register */
	#define BMSK_DPE_SCC_Hue_Threshold_E_Register_HTH_E_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Threshold_E_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Threshold_E_Register_HTH_E_ST_N	 0x180c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_AB_Register	0x1810 /* SCC_Hue_Gain_AB_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_AB_Register	 0x1810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_AB_Register */
	#define BLSB_DPE_SCC_Hue_Gain_AB_Register_HGN_B_ST_N	16
	#define BLSB_DPE_SCC_Hue_Gain_AB_Register_HGN_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_AB_Register */
	#define BWID_DPE_SCC_Hue_Gain_AB_Register_HGN_B_ST_N	12
	#define BWID_DPE_SCC_Hue_Gain_AB_Register_HGN_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_AB_Register */
	#define BMSK_DPE_SCC_Hue_Gain_AB_Register_HGN_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Gain_AB_Register_HGN_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_AB_Register_HGN_B_ST_N	 0x1810, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Gain_AB_Register_HGN_A_ST_N	 0x1810, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_CD_Register	0x1818 /* SCC_Hue_Gain_CD_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_CD_Register	 0x1818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_CD_Register */
	#define BLSB_DPE_SCC_Hue_Gain_CD_Register_HGN_D_ST_N	16
	#define BLSB_DPE_SCC_Hue_Gain_CD_Register_HGN_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_CD_Register */
	#define BWID_DPE_SCC_Hue_Gain_CD_Register_HGN_D_ST_N	12
	#define BWID_DPE_SCC_Hue_Gain_CD_Register_HGN_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_CD_Register */
	#define BMSK_DPE_SCC_Hue_Gain_CD_Register_HGN_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Gain_CD_Register_HGN_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_CD_Register_HGN_D_ST_N	 0x1818, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Gain_CD_Register_HGN_C_ST_N	 0x1818, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_E_Register	0x181c /* SCC_Hue_Gain_E_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_E_Register	 0x181c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_E_Register */
	#define BLSB_DPE_SCC_Hue_Gain_E_Register_HGN_E_ST_N	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_E_Register */
	#define BWID_DPE_SCC_Hue_Gain_E_Register_HGN_E_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_E_Register */
	#define BMSK_DPE_SCC_Hue_Gain_E_Register_HGN_E_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_E_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_E_Register_HGN_E_ST_N	 0x181c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_HSlope_AB_BC_N_Register	0x1820 /* SCC_HSlope_AB_BC_N_Register */ 
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register	 0x1820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_HSlope_AB_BC_N_Register */
	#define BLSB_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_BC_ST_N	31
	#define BLSB_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_BC_ST_N	24
	#define BLSB_DPE_SCC_HSlope_AB_BC_N_Register_HSL_BC_ST_N	16
	#define BLSB_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_AB_ST_N	15
	#define BLSB_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_AB_ST_N	8
	#define BLSB_DPE_SCC_HSlope_AB_BC_N_Register_HSL_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_HSlope_AB_BC_N_Register */
	#define BWID_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_BC_ST_N	1
	#define BWID_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_BC_ST_N	4
	#define BWID_DPE_SCC_HSlope_AB_BC_N_Register_HSL_BC_ST_N	8
	#define BWID_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_AB_ST_N	1
	#define BWID_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_AB_ST_N	4
	#define BWID_DPE_SCC_HSlope_AB_BC_N_Register_HSL_AB_ST_N	8
	/* Register Bit MASKS for DPE_SCC_HSlope_AB_BC_N_Register */
	#define BMSK_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_HSlope_AB_BC_N_Register_HSL_BC_ST_N	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_HSlope_AB_BC_N_Register_HSL_AB_ST_N	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_HSlope_AB_BC_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_BC_ST_N	 0x1820, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_BC_ST_N	 0x1820, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register_HSL_BC_ST_N	 0x1820, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SGN_AB_ST_N	 0x1820, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register_HSL_SFT_AB_ST_N	 0x1820, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_HSlope_AB_BC_N_Register_HSL_AB_ST_N	 0x1820, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_HSlope_CD_DE_N_Register	0x1824 /* SCC_HSlope_CD_DE_N_Register */ 
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register	 0x1824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_HSlope_CD_DE_N_Register */
	#define BLSB_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_DE_ST_N	31
	#define BLSB_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_DE_ST_N	24
	#define BLSB_DPE_SCC_HSlope_CD_DE_N_Register_HSL_DE_ST_N	16
	#define BLSB_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_CD_ST_N	15
	#define BLSB_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_CD_ST_N	8
	#define BLSB_DPE_SCC_HSlope_CD_DE_N_Register_HSL_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_HSlope_CD_DE_N_Register */
	#define BWID_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_DE_ST_N	1
	#define BWID_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_DE_ST_N	4
	#define BWID_DPE_SCC_HSlope_CD_DE_N_Register_HSL_DE_ST_N	8
	#define BWID_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_CD_ST_N	1
	#define BWID_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_CD_ST_N	4
	#define BWID_DPE_SCC_HSlope_CD_DE_N_Register_HSL_CD_ST_N	8
	/* Register Bit MASKS for DPE_SCC_HSlope_CD_DE_N_Register */
	#define BMSK_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_DE_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_DE_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_HSlope_CD_DE_N_Register_HSL_DE_ST_N	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_HSlope_CD_DE_N_Register_HSL_CD_ST_N	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_HSlope_CD_DE_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_DE_ST_N	 0x1824, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_DE_ST_N	 0x1824, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register_HSL_DE_ST_N	 0x1824, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SGN_CD_ST_N	 0x1824, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register_HSL_SFT_CD_ST_N	 0x1824, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_HSlope_CD_DE_N_Register_HSL_CD_ST_N	 0x1824, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_Gain_AB_N_Register	0x1828 /* SCC_Saturation_Gain_AB_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_Gain_AB_N_Register	 0x1828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_Gain_AB_N_Register */
	#define BLSB_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_B_ST_N	16
	#define BLSB_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_Gain_AB_N_Register */
	#define BWID_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_B_ST_N	12
	#define BWID_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_Gain_AB_N_Register */
	#define BMSK_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_Gain_AB_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_B_ST_N	 0x1828, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_Gain_AB_N_Register_SGN_A_ST_N	 0x1828, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_Gain_CD_N_Register	0x182c /* SCC_Saturation_Gain_CD_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_Gain_CD_N_Register	 0x182c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_Gain_CD_N_Register */
	#define BLSB_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_D_ST_N	16
	#define BLSB_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_Gain_CD_N_Register */
	#define BWID_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_D_ST_N	12
	#define BWID_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_Gain_CD_N_Register */
	#define BMSK_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_Gain_CD_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_D_ST_N	 0x182c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_Gain_CD_N_Register_SGN_C_ST_N	 0x182c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_Gain_E_N_Register	0x1830 /* SCC_Saturation_Gain_E_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_Gain_E_N_Register	 0x1830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_Gain_E_N_Register */
	#define BLSB_DPE_SCC_Saturation_Gain_E_N_Register_SGN_E_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_Gain_E_N_Register */
	#define BWID_DPE_SCC_Saturation_Gain_E_N_Register_SGN_E_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_Gain_E_N_Register */
	#define BMSK_DPE_SCC_Saturation_Gain_E_N_Register_SGN_E_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_Gain_E_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_Gain_E_N_Register_SGN_E_ST_N	 0x1830, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_Slope_AB_BC_N_Register	0x1834 /* SCC_Saturation_Slope_AB_BC_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register	 0x1834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_Slope_AB_BC_N_Register */
	#define BLSB_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_BC_ST_N	31
	#define BLSB_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_BC_ST_N	24
	#define BLSB_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_BC_ST_N	16
	#define BLSB_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_AB_ST_N	15
	#define BLSB_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_AB_ST_N	8
	#define BLSB_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_Slope_AB_BC_N_Register */
	#define BWID_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_BC_ST_N	1
	#define BWID_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_BC_ST_N	4
	#define BWID_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_BC_ST_N	8
	#define BWID_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_AB_ST_N	1
	#define BWID_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_AB_ST_N	4
	#define BWID_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_AB_ST_N	8
	/* Register Bit MASKS for DPE_SCC_Saturation_Slope_AB_BC_N_Register */
	#define BMSK_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_BC_ST_N	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_AB_ST_N	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_Slope_AB_BC_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_BC_ST_N	 0x1834, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_BC_ST_N	 0x1834, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_BC_ST_N	 0x1834, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SGN_AB_ST_N	 0x1834, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_SFT_AB_ST_N	 0x1834, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_Slope_AB_BC_N_Register_SSL_AB_ST_N	 0x1834, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_Slope_CD_DE_N_Register	0x1838 /* SCC_Saturation_Slope_CD_DE_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register	 0x1838, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_Slope_CD_DE_N_Register */
	#define BLSB_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_DE_ST_N	31
	#define BLSB_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_DE_ST_N	24
	#define BLSB_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_DE_ST_N	16
	#define BLSB_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_CD_ST_N	15
	#define BLSB_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_CD_ST_N	8
	#define BLSB_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_Slope_CD_DE_N_Register */
	#define BWID_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_DE_ST_N	1
	#define BWID_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_DE_ST_N	4
	#define BWID_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_DE_ST_N	8
	#define BWID_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_CD_ST_N	1
	#define BWID_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_CD_ST_N	4
	#define BWID_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_CD_ST_N	8
	/* Register Bit MASKS for DPE_SCC_Saturation_Slope_CD_DE_N_Register */
	#define BMSK_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_DE_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_DE_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_DE_ST_N	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_CD_ST_N	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_Slope_CD_DE_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_DE_ST_N	 0x1838, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_DE_ST_N	 0x1838, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_DE_ST_N	 0x1838, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SGN_CD_ST_N	 0x1838, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_SFT_CD_ST_N	 0x1838, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_Slope_CD_DE_N_Register_SSL_CD_ST_N	 0x1838, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Intensity_Gain_AB_Register	0x183c /* SCC_Intensity_Gain_AB_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_AB_Register	 0x183c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_AB_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_AB_Register_IGN_B_ST_N	16
	#define BLSB_DPE_SCC_Intensity_Gain_AB_Register_IGN_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_AB_Register */
	#define BWID_DPE_SCC_Intensity_Gain_AB_Register_IGN_B_ST_N	12
	#define BWID_DPE_SCC_Intensity_Gain_AB_Register_IGN_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_AB_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_AB_Register_IGN_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_Gain_AB_Register_IGN_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_AB_Register_IGN_B_ST_N	 0x183c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_Gain_AB_Register_IGN_A_ST_N	 0x183c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_Gain_CD_Register	0x1840 /* SCC_Intensity_Gain_CD_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_CD_Register	 0x1840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_CD_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_CD_Register_IGN_D_ST_N	16
	#define BLSB_DPE_SCC_Intensity_Gain_CD_Register_IGN_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_CD_Register */
	#define BWID_DPE_SCC_Intensity_Gain_CD_Register_IGN_D_ST_N	12
	#define BWID_DPE_SCC_Intensity_Gain_CD_Register_IGN_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_CD_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_CD_Register_IGN_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_Gain_CD_Register_IGN_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_CD_Register_IGN_D_ST_N	 0x1840, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_Gain_CD_Register_IGN_C_ST_N	 0x1840, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_Gain_E_Register	0x1844 /* SCC_Intensity_Gain_E_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_E_Register	 0x1844, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_E_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_E_Register_IGN_E_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_E_Register */
	#define BWID_DPE_SCC_Intensity_Gain_E_Register_IGN_E_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_E_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_E_Register_IGN_E_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_E_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_E_Register_IGN_E_ST_N	 0x1844, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Islope_AB_BC_Register	0x1848 /* SCC_Islope_AB_BC_Register */ 
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register	 0x1848, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_AB_BC_Register */
	#define BLSB_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_BC_ST_N	31
	#define BLSB_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_BC_ST_N	24
	#define BLSB_DPE_SCC_Islope_AB_BC_Register_ISL_BC_ST_N	16
	#define BLSB_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_AB_ST_N	15
	#define BLSB_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_AB_ST_N	8
	#define BLSB_DPE_SCC_Islope_AB_BC_Register_ISL_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_AB_BC_Register */
	#define BWID_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_BC_ST_N	1
	#define BWID_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_BC_ST_N	4
	#define BWID_DPE_SCC_Islope_AB_BC_Register_ISL_BC_ST_N	8
	#define BWID_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_AB_ST_N	1
	#define BWID_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_AB_ST_N	4
	#define BWID_DPE_SCC_Islope_AB_BC_Register_ISL_AB_ST_N	8
	/* Register Bit MASKS for DPE_SCC_Islope_AB_BC_Register */
	#define BMSK_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Islope_AB_BC_Register_ISL_BC_ST_N	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_AB_BC_Register_ISL_AB_ST_N	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Islope_AB_BC_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_BC_ST_N	 0x1848, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_BC_ST_N	 0x1848, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register_ISL_BC_ST_N	 0x1848, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register_ISL_SGN_AB_ST_N	 0x1848, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register_ISL_SFT_AB_ST_N	 0x1848, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_AB_BC_Register_ISL_AB_ST_N	 0x1848, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Islope_CD_DE_Register	0x184c /* SCC_Islope_CD_DE_Register */ 
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register	 0x184c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_CD_DE_Register */
	#define BLSB_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_DE_ST_N	31
	#define BLSB_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_DE_ST_N	24
	#define BLSB_DPE_SCC_Islope_CD_DE_Register_ISL_DE_ST_N	16
	#define BLSB_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_CD_ST_N	15
	#define BLSB_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_CD_ST_N	8
	#define BLSB_DPE_SCC_Islope_CD_DE_Register_ISL_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_CD_DE_Register */
	#define BWID_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_DE_ST_N	1
	#define BWID_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_DE_ST_N	4
	#define BWID_DPE_SCC_Islope_CD_DE_Register_ISL_DE_ST_N	8
	#define BWID_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_CD_ST_N	1
	#define BWID_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_CD_ST_N	4
	#define BWID_DPE_SCC_Islope_CD_DE_Register_ISL_CD_ST_N	8
	/* Register Bit MASKS for DPE_SCC_Islope_CD_DE_Register */
	#define BMSK_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_DE_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_DE_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Islope_CD_DE_Register_ISL_DE_ST_N	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_CD_DE_Register_ISL_CD_ST_N	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Islope_CD_DE_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_DE_ST_N	 0x184c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_DE_ST_N	 0x184c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register_ISL_DE_ST_N	 0x184c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register_ISL_SGN_CD_ST_N	 0x184c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register_ISL_SFT_CD_ST_N	 0x184c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_CD_DE_Register_ISL_CD_ST_N	 0x184c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register	0x1850 /* SCC_Saturation_thresh_AB_for_hue_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register	 0x1850, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_B_ST_N	16
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_B_ST_N	12
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_B_ST_N	 0x1850, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_N_Register_STH_HLIM_A_ST_N	 0x1850, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register	0x1854 /* SCC_Saturation_thresh_CD_for_hue_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register	 0x1854, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_D_ST_N	16
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_D_ST_N	12
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_D_ST_N	 0x1854, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_hue_limiter_N_Register_STH_HLIM_C_ST_N	 0x1854, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register	0x1858 /* SCC_Saturation_slope_hue_AB_BC_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register	 0x1858, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_hue_AB_BC_N_Register */
	#define BLSB_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_BC_ST_N	31
	#define BLSB_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_BC_ST_N	24
	#define BLSB_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_BC_ST_N	16
	#define BLSB_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_AB_ST_N	15
	#define BLSB_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_AB_ST_N	8
	#define BLSB_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_hue_AB_BC_N_Register */
	#define BWID_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_BC_ST_N	1
	#define BWID_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_BC_ST_N	4
	#define BWID_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_BC_ST_N	6
	#define BWID_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_AB_ST_N	1
	#define BWID_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_AB_ST_N	4
	#define BWID_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_AB_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_hue_AB_BC_N_Register */
	#define BMSK_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_BC_ST_N	0x003f0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_AB_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_hue_AB_BC_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_BC_ST_N	 0x1858, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_BC_ST_N	 0x1858, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_BC_ST_N	 0x1858, 16, 6, 0x003f0000
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SGN_HLIM_AB_ST_N	 0x1858, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SFT_HLIM_AB_ST_N	 0x1858, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_AB_BC_N_Register_S_SLP_HLIM_AB_ST_N	 0x1858, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Saturation_slope_hue_CD_N_Register	0x185c /* SCC_Saturation_slope_hue_CD_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_CD_N_Register	 0x185c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_hue_CD_N_Register */
	#define BLSB_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SGN_HLIM_CD_ST_N	15
	#define BLSB_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SFT_HLIM_CD_ST_N	8
	#define BLSB_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SLP_HLIM_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_hue_CD_N_Register */
	#define BWID_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SGN_HLIM_CD_ST_N	1
	#define BWID_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SFT_HLIM_CD_ST_N	4
	#define BWID_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SLP_HLIM_CD_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_hue_CD_N_Register */
	#define BMSK_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SGN_HLIM_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SFT_HLIM_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SLP_HLIM_CD_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_hue_CD_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SGN_HLIM_CD_ST_N	 0x185c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SFT_HLIM_CD_ST_N	 0x185c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_hue_CD_N_Register_S_SLP_HLIM_CD_ST_N	 0x185c, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register	0x1860 /* SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register	 0x1860, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_D_ST_N	24
	#define BLSB_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_C_ST_N	16
	#define BLSB_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_B_ST_N	8
	#define BLSB_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_D_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_C_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_B_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_A_ST_N	4
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_D_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_C_ST_N	0x000f0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_B_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_A_ST_N	0x0000000f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_D_ST_N	 0x1860, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_C_ST_N	 0x1860, 16, 4, 0x000f0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_B_ST_N	 0x1860, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_limit_for_Hue_ABCD_limiter_N_Register_S_HLIM_A_ST_N	 0x1860, 0, 4, 0x0000000f
#define ROFF_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register	0x1864 /* SCC_Intensity_thresh_AB_for_hue_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register	 0x1864, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_B_ST_N	16
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register */
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_B_ST_N	12
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_B_ST_N	 0x1864, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_N_Register_ITH_HLIM_A_ST_N	 0x1864, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register	0x1868 /* SCC_Intensity_thresh_CD_for_hue_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register	 0x1868, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_D_ST_N	16
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register */
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_D_ST_N	12
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_D_ST_N	 0x1868, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_N_Register_ITH_HLIM_C_ST_N	 0x1868, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Islope_hue_AB_BC_Register	0x186c /* SCC_Islope_hue_AB_BC_Register */ 
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register	 0x186c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_hue_AB_BC_Register */
	#define BLSB_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_BC_ST_N	31
	#define BLSB_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_BC_ST_N	24
	#define BLSB_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_BC_ST_N	16
	#define BLSB_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_AB_ST_N	15
	#define BLSB_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_AB_ST_N	8
	#define BLSB_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_hue_AB_BC_Register */
	#define BWID_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_BC_ST_N	1
	#define BWID_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_BC_ST_N	4
	#define BWID_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_BC_ST_N	6
	#define BWID_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_AB_ST_N	1
	#define BWID_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_AB_ST_N	4
	#define BWID_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_AB_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Islope_hue_AB_BC_Register */
	#define BMSK_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_BC_ST_N	0x003f0000 /*  */
	#define BMSK_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_AB_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Islope_hue_AB_BC_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_BC_ST_N	 0x186c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_BC_ST_N	 0x186c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_BC_ST_N	 0x186c, 16, 6, 0x003f0000
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register_I_SGN_HLIM_AB_ST_N	 0x186c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register_I_SFT_HLIM_AB_ST_N	 0x186c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_hue_AB_BC_Register_I_SLP_HLIM_AB_ST_N	 0x186c, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Islope_hue_CD_Register	0x1870 /* SCC_Islope_hue_CD_Register */ 
	#define BITFIELD_DPE_SCC_Islope_hue_CD_Register	 0x1870, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_hue_CD_Register */
	#define BLSB_DPE_SCC_Islope_hue_CD_Register_I_SGN_HLIM_CD_ST_N	15
	#define BLSB_DPE_SCC_Islope_hue_CD_Register_I_SFT_HLIM_CD_ST_N	8
	#define BLSB_DPE_SCC_Islope_hue_CD_Register_I_SLP_HLIM_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_hue_CD_Register */
	#define BWID_DPE_SCC_Islope_hue_CD_Register_I_SGN_HLIM_CD_ST_N	1
	#define BWID_DPE_SCC_Islope_hue_CD_Register_I_SFT_HLIM_CD_ST_N	4
	#define BWID_DPE_SCC_Islope_hue_CD_Register_I_SLP_HLIM_CD_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Islope_hue_CD_Register */
	#define BMSK_DPE_SCC_Islope_hue_CD_Register_I_SGN_HLIM_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_hue_CD_Register_I_SFT_HLIM_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_hue_CD_Register_I_SLP_HLIM_CD_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Islope_hue_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_hue_CD_Register_I_SGN_HLIM_CD_ST_N	 0x1870, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_hue_CD_Register_I_SFT_HLIM_CD_ST_N	 0x1870, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_hue_CD_Register_I_SLP_HLIM_CD_ST_N	 0x1870, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Intensity_limit_for_Hue_limiter_Register	0x1874 /* SCC_Intensity_limit_for_Hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_limit_for_Hue_limiter_Register	 0x1874, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_limit_for_Hue_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_D_ST_N	24
	#define BLSB_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_C_ST_N	16
	#define BLSB_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_B_ST_N	8
	#define BLSB_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_limit_for_Hue_limiter_Register */
	#define BWID_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_D_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_C_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_B_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_A_ST_N	4
	/* Register Bit MASKS for DPE_SCC_Intensity_limit_for_Hue_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_D_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_C_ST_N	0x000f0000 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_B_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_A_ST_N	0x0000000f /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_limit_for_Hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_D_ST_N	 0x1874, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_C_ST_N	 0x1874, 16, 4, 0x000f0000
	#define BITFIELD_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_B_ST_N	 0x1874, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Intensity_limit_for_Hue_limiter_Register_I_HLIM_A_ST_N	 0x1874, 0, 4, 0x0000000f
#define ROFF_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register	0x1878 /* SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register	 0x1878, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_B_ST_N	16
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_B_ST_N	12
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_B_ST_N	 0x1878, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_SAT_limiter_N_Register_STH_SLIM_A_ST_N	 0x1878, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register	0x187c /* SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register	 0x187c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_D_ST_N	16
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_D_ST_N	12
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_D_ST_N	 0x187c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_SAT_limiter_N_Register_STH_SLIM_C_ST_N	 0x187c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_sat_slope_AB_BC_Register	0x1880 /* SCC_Saturation_sat_slope_AB_BC_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register	 0x1880, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_sat_slope_AB_BC_Register */
	#define BLSB_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_BC_ST_N	31
	#define BLSB_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_BC_ST_N	24
	#define BLSB_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_BC_ST_N	16
	#define BLSB_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_AB_ST_N	15
	#define BLSB_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_AB_ST_N	8
	#define BLSB_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_sat_slope_AB_BC_Register */
	#define BWID_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_BC_ST_N	1
	#define BWID_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_BC_ST_N	4
	#define BWID_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_BC_ST_N	6
	#define BWID_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_AB_ST_N	1
	#define BWID_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_AB_ST_N	4
	#define BWID_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_AB_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Saturation_sat_slope_AB_BC_Register */
	#define BMSK_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_BC_ST_N	0x003f0000 /*  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_AB_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_sat_slope_AB_BC_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_BC_ST_N	 0x1880, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_BC_ST_N	 0x1880, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_BC_ST_N	 0x1880, 16, 6, 0x003f0000
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SGN_SLIM_AB_ST_N	 0x1880, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SFT_SLIM_AB_ST_N	 0x1880, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_AB_BC_Register_S_SLP_SLIM_AB_ST_N	 0x1880, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Saturation_sat_slope_CD_Register	0x1884 /* SCC_Saturation_sat_slope_CD_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_CD_Register	 0x1884, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_sat_slope_CD_Register */
	#define BLSB_DPE_SCC_Saturation_sat_slope_CD_Register_S_SGN_SLIM_CD_ST_N	15
	#define BLSB_DPE_SCC_Saturation_sat_slope_CD_Register_S_SFT_SLIM_CD_ST_N	8
	#define BLSB_DPE_SCC_Saturation_sat_slope_CD_Register_S_SLP_SLIM_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_sat_slope_CD_Register */
	#define BWID_DPE_SCC_Saturation_sat_slope_CD_Register_S_SGN_SLIM_CD_ST_N	1
	#define BWID_DPE_SCC_Saturation_sat_slope_CD_Register_S_SFT_SLIM_CD_ST_N	4
	#define BWID_DPE_SCC_Saturation_sat_slope_CD_Register_S_SLP_SLIM_CD_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Saturation_sat_slope_CD_Register */
	#define BMSK_DPE_SCC_Saturation_sat_slope_CD_Register_S_SGN_SLIM_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_CD_Register_S_SFT_SLIM_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_sat_slope_CD_Register_S_SLP_SLIM_CD_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_sat_slope_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_CD_Register_S_SGN_SLIM_CD_ST_N	 0x1884, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_CD_Register_S_SFT_SLIM_CD_ST_N	 0x1884, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_sat_slope_CD_Register_S_SLP_SLIM_CD_ST_N	 0x1884, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register	0x1888 /* SCC_Saturation_limit_for_SAT_limiterABCD_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register	 0x1888, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_D_ST_N	24
	#define BLSB_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_C_ST_N	16
	#define BLSB_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_B_ST_N	8
	#define BLSB_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_D_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_C_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_B_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_A_ST_N	4
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_D_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_C_ST_N	0x000f0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_B_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_A_ST_N	0x0000000f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_D_ST_N	 0x1888, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_C_ST_N	 0x1888, 16, 4, 0x000f0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_B_ST_N	 0x1888, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_limit_for_SAT_limiter_ABCD_N_Register_S_SLIM_A_ST_N	 0x1888, 0, 4, 0x0000000f
#define ROFF_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register	0x1890 /* SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register	 0x1890, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_B_ST_N	16
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register */
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_B_ST_N	12
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_B_ST_N	 0x1890, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_SAT_limiter_N_Register_ITH_SLIM_A_ST_N	 0x1890, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register	0x1894 /* SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register	 0x1894, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_D_ST_N	16
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register */
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_D_ST_N	12
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_D_ST_N	 0x1894, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_SAT_limiter_N_Register_ITH_SLIM_C_ST_N	 0x1894, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Islope_sat_AB_BC_N_Register	0x1898 /* SCC_Islope_sat_AB_BC_N_Register */ 
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register	 0x1898, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_sat_AB_BC_N_Register */
	#define BLSB_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_BC_ST_N	31
	#define BLSB_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_BC_ST_N	24
	#define BLSB_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_BC_ST_N	16
	#define BLSB_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_AB_ST_N	15
	#define BLSB_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_AB_ST_N	8
	#define BLSB_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_sat_AB_BC_N_Register */
	#define BWID_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_BC_ST_N	1
	#define BWID_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_BC_ST_N	4
	#define BWID_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_BC_ST_N	6
	#define BWID_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_AB_ST_N	1
	#define BWID_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_AB_ST_N	4
	#define BWID_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_AB_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Islope_sat_AB_BC_N_Register */
	#define BMSK_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_BC_ST_N	0x003f0000 /*  */
	#define BMSK_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_AB_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Islope_sat_AB_BC_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_BC_ST_N	 0x1898, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_BC_ST_N	 0x1898, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_BC_ST_N	 0x1898, 16, 6, 0x003f0000
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SGN_SLIM_AB_ST_N	 0x1898, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SFT_SLIM_AB_ST_N	 0x1898, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_sat_AB_BC_N_Register_I_SLP_SLIM_AB_ST_N	 0x1898, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Islope_sat_CD_N_Register	0x189c /* SCC_Islope_sat_CD_N_Register */ 
	#define BITFIELD_DPE_SCC_Islope_sat_CD_N_Register	 0x189c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_sat_CD_N_Register */
	#define BLSB_DPE_SCC_Islope_sat_CD_N_Register_I_SGN_SLIM_CD_ST_N	15
	#define BLSB_DPE_SCC_Islope_sat_CD_N_Register_I_SFT_SLIM_CD_ST_N	8
	#define BLSB_DPE_SCC_Islope_sat_CD_N_Register_I_SLP_SLIM_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_sat_CD_N_Register */
	#define BWID_DPE_SCC_Islope_sat_CD_N_Register_I_SGN_SLIM_CD_ST_N	1
	#define BWID_DPE_SCC_Islope_sat_CD_N_Register_I_SFT_SLIM_CD_ST_N	4
	#define BWID_DPE_SCC_Islope_sat_CD_N_Register_I_SLP_SLIM_CD_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Islope_sat_CD_N_Register */
	#define BMSK_DPE_SCC_Islope_sat_CD_N_Register_I_SGN_SLIM_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_sat_CD_N_Register_I_SFT_SLIM_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_sat_CD_N_Register_I_SLP_SLIM_CD_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Islope_sat_CD_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_sat_CD_N_Register_I_SGN_SLIM_CD_ST_N	 0x189c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_sat_CD_N_Register_I_SFT_SLIM_CD_ST_N	 0x189c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_sat_CD_N_Register_I_SLP_SLIM_CD_ST_N	 0x189c, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Intensity_limit_for_SAT_limiter_Register	0x18a0 /* SCC_Intensity_limit_for_SAT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_limit_for_SAT_limiter_Register	 0x18a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_limit_for_SAT_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_D_ST_N	24
	#define BLSB_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_C_ST_N	16
	#define BLSB_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_B_ST_N	8
	#define BLSB_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_limit_for_SAT_limiter_Register */
	#define BWID_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_D_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_C_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_B_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_A_ST_N	4
	/* Register Bit MASKS for DPE_SCC_Intensity_limit_for_SAT_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_D_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_C_ST_N	0x000f0000 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_B_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_A_ST_N	0x0000000f /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_limit_for_SAT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_D_ST_N	 0x18a0, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_C_ST_N	 0x18a0, 16, 4, 0x000f0000
	#define BITFIELD_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_B_ST_N	 0x18a0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Intensity_limit_for_SAT_limiter_Register_I_SLIM_A_ST_N	 0x18a0, 0, 4, 0x0000000f
#define ROFF_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register	0x18a4 /* SCC_Saturation_thresh_AB_for_INT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register	 0x18a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_B_ST_N	16
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_B_ST_N	12
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_B_ST_N	 0x18a4, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_N_Register_STH_ILIM_A_ST_N	 0x18a4, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register	0x18a8 /* SCC_Saturation_thresh_CD_for_INT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register	 0x18a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_D_ST_N	16
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_D_ST_N	12
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_D_ST_N	 0x18a8, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_N_Register_STH_ILIM_C_ST_N	 0x18a8, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Sslope_INT_AB_BC_N_Register	0x18ac /* SCC_Sslope_INT_AB_BC_N_Register */ 
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register	 0x18ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Sslope_INT_AB_BC_N_Register */
	#define BLSB_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_BC_ST_N	31
	#define BLSB_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_BC_ST_N	24
	#define BLSB_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_BC_ST_N	16
	#define BLSB_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_AB_ST_N	15
	#define BLSB_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_AB_ST_N	8
	#define BLSB_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Sslope_INT_AB_BC_N_Register */
	#define BWID_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_BC_ST_N	1
	#define BWID_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_BC_ST_N	4
	#define BWID_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_BC_ST_N	6
	#define BWID_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_AB_ST_N	1
	#define BWID_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_AB_ST_N	4
	#define BWID_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_AB_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Sslope_INT_AB_BC_N_Register */
	#define BMSK_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_BC_ST_N	0x003f0000 /*  */
	#define BMSK_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_AB_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Sslope_INT_AB_BC_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_BC_ST_N	 0x18ac, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_BC_ST_N	 0x18ac, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_BC_ST_N	 0x18ac, 16, 6, 0x003f0000
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SGN_ILIM_AB_ST_N	 0x18ac, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SFT_ILIM_AB_ST_N	 0x18ac, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Sslope_INT_AB_BC_N_Register_S_SLP_ILIM_AB_ST_N	 0x18ac, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Sslope_INT_CD_N_Register	0x18b0 /* SCC_Sslope_INT_CD_N_Register */ 
	#define BITFIELD_DPE_SCC_Sslope_INT_CD_N_Register	 0x18b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Sslope_INT_CD_N_Register */
	#define BLSB_DPE_SCC_Sslope_INT_CD_N_Register_S_SGN_ILIM_CD_ST_N	15
	#define BLSB_DPE_SCC_Sslope_INT_CD_N_Register_S_SFT_ILIM_CD_ST_N	8
	#define BLSB_DPE_SCC_Sslope_INT_CD_N_Register_S_SLP_ILIM_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Sslope_INT_CD_N_Register */
	#define BWID_DPE_SCC_Sslope_INT_CD_N_Register_S_SGN_ILIM_CD_ST_N	1
	#define BWID_DPE_SCC_Sslope_INT_CD_N_Register_S_SFT_ILIM_CD_ST_N	4
	#define BWID_DPE_SCC_Sslope_INT_CD_N_Register_S_SLP_ILIM_CD_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Sslope_INT_CD_N_Register */
	#define BMSK_DPE_SCC_Sslope_INT_CD_N_Register_S_SGN_ILIM_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Sslope_INT_CD_N_Register_S_SFT_ILIM_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Sslope_INT_CD_N_Register_S_SLP_ILIM_CD_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Sslope_INT_CD_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Sslope_INT_CD_N_Register_S_SGN_ILIM_CD_ST_N	 0x18b0, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Sslope_INT_CD_N_Register_S_SFT_ILIM_CD_ST_N	 0x18b0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Sslope_INT_CD_N_Register_S_SLP_ILIM_CD_ST_N	 0x18b0, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register	0x18b4 /* SCC_Saturation_limit_for_INT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register	 0x18b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_INT_limiter_N_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_D_ST_N	24
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_C_ST_N	16
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_B_ST_N	8
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_INT_limiter_N_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_D_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_C_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_B_ST_N	4
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_A_ST_N	4
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_INT_limiter_N_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_D_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_C_ST_N	0x000f0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_B_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_A_ST_N	0x0000000f /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_INT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_D_ST_N	 0x18b4, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_C_ST_N	 0x18b4, 16, 4, 0x000f0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_B_ST_N	 0x18b4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_N_Register_S_ILIM_A_ST_N	 0x18b4, 0, 4, 0x0000000f
#define ROFF_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register	0x18b8 /* SCC_Intensity_thresh_AB_for_INT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register	 0x18b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_B_ST_N	16
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register */
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_B_ST_N	12
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_A_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_B_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_A_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_B_ST_N	 0x18b8, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_N_Register_ITH_ILIM_A_ST_N	 0x18b8, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register	0x18bc /* SCC_Intensity_thresh_CD_for_INT_limiter_N_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register	 0x18bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_D_ST_N	16
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_C_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register */
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_D_ST_N	12
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_C_ST_N	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_D_ST_N	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_C_ST_N	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_D_ST_N	 0x18bc, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_N_Register_ITH_ILIM_C_ST_N	 0x18bc, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Islope_INT_AB_BC_N_Register	0x18c0 /* SCC_Islope_INT_AB_BC_N_Register */ 
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register	 0x18c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_INT_AB_BC_N_Register */
	#define BLSB_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_BC_ST_N	31
	#define BLSB_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_BC_ST_N	24
	#define BLSB_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_BC_ST_N	16
	#define BLSB_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_AB_ST_N	15
	#define BLSB_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_AB_ST_N	8
	#define BLSB_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_AB_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_INT_AB_BC_N_Register */
	#define BWID_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_BC_ST_N	1
	#define BWID_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_BC_ST_N	4
	#define BWID_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_BC_ST_N	6
	#define BWID_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_AB_ST_N	1
	#define BWID_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_AB_ST_N	4
	#define BWID_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_AB_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Islope_INT_AB_BC_N_Register */
	#define BMSK_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_BC_ST_N	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_BC_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_BC_ST_N	0x003f0000 /*  */
	#define BMSK_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_AB_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_AB_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_AB_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Islope_INT_AB_BC_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_BC_ST_N	 0x18c0, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_BC_ST_N	 0x18c0, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_BC_ST_N	 0x18c0, 16, 6, 0x003f0000
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SGN_ILIM_AB_ST_N	 0x18c0, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SFT_ILIM_AB_ST_N	 0x18c0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_INT_AB_BC_N_Register_I_SLP_ILIM_AB_ST_N	 0x18c0, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Islope_INT_CD_N_Register	0x18c4 /* SCC_Islope_INT_CD_N_Register */ 
	#define BITFIELD_DPE_SCC_Islope_INT_CD_N_Register	 0x18c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Islope_INT_CD_N_Register */
	#define BLSB_DPE_SCC_Islope_INT_CD_N_Register_I_SGN_ILIM_CD_ST_N	15
	#define BLSB_DPE_SCC_Islope_INT_CD_N_Register_I_SFT_ILIM_CD_ST_N	8
	#define BLSB_DPE_SCC_Islope_INT_CD_N_Register_I_SLP_ILIM_CD_ST_N	0
	/* Register Bit Widths for DPE_SCC_Islope_INT_CD_N_Register */
	#define BWID_DPE_SCC_Islope_INT_CD_N_Register_I_SGN_ILIM_CD_ST_N	1
	#define BWID_DPE_SCC_Islope_INT_CD_N_Register_I_SFT_ILIM_CD_ST_N	4
	#define BWID_DPE_SCC_Islope_INT_CD_N_Register_I_SLP_ILIM_CD_ST_N	6
	/* Register Bit MASKS for DPE_SCC_Islope_INT_CD_N_Register */
	#define BMSK_DPE_SCC_Islope_INT_CD_N_Register_I_SGN_ILIM_CD_ST_N	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Islope_INT_CD_N_Register_I_SFT_ILIM_CD_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Islope_INT_CD_N_Register_I_SLP_ILIM_CD_ST_N	0x0000003f /*  */
	/* Register BITFIELD for DPE_SCC_Islope_INT_CD_N_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Islope_INT_CD_N_Register_I_SGN_ILIM_CD_ST_N	 0x18c4, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Islope_INT_CD_N_Register_I_SFT_ILIM_CD_ST_N	 0x18c4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Islope_INT_CD_N_Register_I_SLP_ILIM_CD_ST_N	 0x18c4, 0, 6, 0x0000003f
#define ROFF_DPE_SCC_Intensity_limit_for_INT_limiter_Register	0x18c8 /* SCC_Intensity_limit_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_limit_for_INT_limiter_Register	 0x18c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_limit_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_D_ST_N	24
	#define BLSB_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_C_ST_N	16
	#define BLSB_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_B_ST_N	8
	#define BLSB_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_A_ST_N	0
	/* Register Bit Widths for DPE_SCC_Intensity_limit_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_D_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_C_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_B_ST_N	4
	#define BWID_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_A_ST_N	4
	/* Register Bit MASKS for DPE_SCC_Intensity_limit_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_D_ST_N	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_C_ST_N	0x000f0000 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_B_ST_N	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_A_ST_N	0x0000000f /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_limit_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_D_ST_N	 0x18c8, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_C_ST_N	 0x18c8, 16, 4, 0x000f0000
	#define BITFIELD_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_B_ST_N	 0x18c8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Intensity_limit_for_INT_limiter_Register_I_ILIM_A_ST_N	 0x18c8, 0, 4, 0x0000000f
#define ROFF_DPE_SCC_Blue_Stretch_Control_Register	0x1800 /* SCC_Blue_Stretch_Control_Register */ 
	#define BITFIELD_DPE_SCC_Blue_Stretch_Control_Register	 0x1800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Blue_Stretch_Control_Register */
	#define BLSB_DPE_SCC_Blue_Stretch_Control_Register_HUE_ZERO_SAT	20
	#define BLSB_DPE_SCC_Blue_Stretch_Control_Register_BS_Hue_bypass	3
	#define BLSB_DPE_SCC_Blue_Stretch_Control_Register_BS_Sat_bypass	2
	#define BLSB_DPE_SCC_Blue_Stretch_Control_Register_BS_Intensity_bypass	1
	#define BLSB_DPE_SCC_Blue_Stretch_Control_Register_Blue_Stretch_stage_bypass	0
	/* Register Bit Widths for DPE_SCC_Blue_Stretch_Control_Register */
	#define BWID_DPE_SCC_Blue_Stretch_Control_Register_HUE_ZERO_SAT	11
	#define BWID_DPE_SCC_Blue_Stretch_Control_Register_BS_Hue_bypass	1
	#define BWID_DPE_SCC_Blue_Stretch_Control_Register_BS_Sat_bypass	1
	#define BWID_DPE_SCC_Blue_Stretch_Control_Register_BS_Intensity_bypass	1
	#define BWID_DPE_SCC_Blue_Stretch_Control_Register_Blue_Stretch_stage_bypass	1
	/* Register Bit MASKS for DPE_SCC_Blue_Stretch_Control_Register */
	#define BMSK_DPE_SCC_Blue_Stretch_Control_Register_HUE_ZERO_SAT	0x7ff00000 /*  */
	#define BMSK_DPE_SCC_Blue_Stretch_Control_Register_BS_Hue_bypass	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_SCC_Blue_Stretch_Control_Register_BS_Sat_bypass	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_SCC_Blue_Stretch_Control_Register_BS_Intensity_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_SCC_Blue_Stretch_Control_Register_Blue_Stretch_stage_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_SCC_Blue_Stretch_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Blue_Stretch_Control_Register_HUE_ZERO_SAT	 0x1800, 20, 11, 0x7ff00000
	#define BITFIELD_DPE_SCC_Blue_Stretch_Control_Register_BS_Hue_bypass	 0x1800, 3, 1, 0x00000008
	#define BITFIELD_DPE_SCC_Blue_Stretch_Control_Register_BS_Sat_bypass	 0x1800, 2, 1, 0x00000004
	#define BITFIELD_DPE_SCC_Blue_Stretch_Control_Register_BS_Intensity_bypass	 0x1800, 1, 1, 0x00000002
	#define BITFIELD_DPE_SCC_Blue_Stretch_Control_Register_Blue_Stretch_stage_bypass	 0x1800, 0, 1, 0x00000001
#define ROFF_DPE_SCC_Hue_thresh_AB_Register	0x1804 /* SCC_Hue_thresh_AB_Register */ 
	#define BITFIELD_DPE_SCC_Hue_thresh_AB_Register	 0x1804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_thresh_AB_Register */
	#define BLSB_DPE_SCC_Hue_thresh_AB_Register_HTH_B_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_thresh_AB_Register_HTH_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_thresh_AB_Register */
	#define BWID_DPE_SCC_Hue_thresh_AB_Register_HTH_B_ST8_BS	11
	#define BWID_DPE_SCC_Hue_thresh_AB_Register_HTH_A_ST8_BS	11
	/* Register Bit MASKS for DPE_SCC_Hue_thresh_AB_Register */
	#define BMSK_DPE_SCC_Hue_thresh_AB_Register_HTH_B_ST8_BS	0x07ff0000 /*  */
	#define BMSK_DPE_SCC_Hue_thresh_AB_Register_HTH_A_ST8_BS	0x000007ff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_thresh_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_thresh_AB_Register_HTH_B_ST8_BS	 0x1804, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_SCC_Hue_thresh_AB_Register_HTH_A_ST8_BS	 0x1804, 0, 11, 0x000007ff
#define ROFF_DPE_SCC_Hue_thresh_CD_Register	0x1808 /* SCC_Hue_thresh_CD_Register */ 
	#define BITFIELD_DPE_SCC_Hue_thresh_CD_Register	 0x1808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_thresh_CD_Register */
	#define BLSB_DPE_SCC_Hue_thresh_CD_Register_HTH_D_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_thresh_CD_Register_HTH_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_thresh_CD_Register */
	#define BWID_DPE_SCC_Hue_thresh_CD_Register_HTH_D_ST8_BS	12
	#define BWID_DPE_SCC_Hue_thresh_CD_Register_HTH_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_thresh_CD_Register */
	#define BMSK_DPE_SCC_Hue_thresh_CD_Register_HTH_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_thresh_CD_Register_HTH_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_thresh_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_thresh_CD_Register_HTH_D_ST8_BS	 0x1808, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_thresh_CD_Register_HTH_C_ST8_BS	 0x1808, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_thresh_EF_Register	0x180c /* SCC_Hue_thresh_EF_Register */ 
	#define BITFIELD_DPE_SCC_Hue_thresh_EF_Register	 0x180c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_thresh_EF_Register */
	#define BLSB_DPE_SCC_Hue_thresh_EF_Register_HTH_F_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_thresh_EF_Register_HTH_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_thresh_EF_Register */
	#define BWID_DPE_SCC_Hue_thresh_EF_Register_HTH_F_ST8_BS	12
	#define BWID_DPE_SCC_Hue_thresh_EF_Register_HTH_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_thresh_EF_Register */
	#define BMSK_DPE_SCC_Hue_thresh_EF_Register_HTH_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_thresh_EF_Register_HTH_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_thresh_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_thresh_EF_Register_HTH_F_ST8_BS	 0x180c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_thresh_EF_Register_HTH_E_ST8_BS	 0x180c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_thresh_GH_Register	0x1810 /* SCC_Hue_thresh_GH_Register */ 
	#define BITFIELD_DPE_SCC_Hue_thresh_GH_Register	 0x1810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_thresh_GH_Register */
	#define BLSB_DPE_SCC_Hue_thresh_GH_Register_HTH_H_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_thresh_GH_Register_HTH_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_thresh_GH_Register */
	#define BWID_DPE_SCC_Hue_thresh_GH_Register_HTH_H_ST8_BS	12
	#define BWID_DPE_SCC_Hue_thresh_GH_Register_HTH_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_thresh_GH_Register */
	#define BMSK_DPE_SCC_Hue_thresh_GH_Register_HTH_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_thresh_GH_Register_HTH_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_thresh_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_thresh_GH_Register_HTH_H_ST8_BS	 0x1810, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_thresh_GH_Register_HTH_G_ST8_BS	 0x1810, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_0A_Register	0x1814 /* SCC_Hue_Gain_0A_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_0A_Register	 0x1814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_0A_Register */
	#define BLSB_DPE_SCC_Hue_Gain_0A_Register_HGN_A_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_Gain_0A_Register_HGN_0_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_0A_Register */
	#define BWID_DPE_SCC_Hue_Gain_0A_Register_HGN_A_ST8_BS	12
	#define BWID_DPE_SCC_Hue_Gain_0A_Register_HGN_0_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_0A_Register */
	#define BMSK_DPE_SCC_Hue_Gain_0A_Register_HGN_A_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Gain_0A_Register_HGN_0_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_0A_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_0A_Register_HGN_A_ST8_BS	 0x1814, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Gain_0A_Register_HGN_0_ST8_BS	 0x1814, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_BC_Register	0x1818 /* SCC_Hue_Gain_BC_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_BC_Register	 0x1818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_BC_Register */
	#define BLSB_DPE_SCC_Hue_Gain_BC_Register_HGN_C_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_Gain_BC_Register_HGN_B_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_BC_Register */
	#define BWID_DPE_SCC_Hue_Gain_BC_Register_HGN_C_ST8_BS	12
	#define BWID_DPE_SCC_Hue_Gain_BC_Register_HGN_B_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_BC_Register */
	#define BMSK_DPE_SCC_Hue_Gain_BC_Register_HGN_C_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Gain_BC_Register_HGN_B_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_BC_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_BC_Register_HGN_C_ST8_BS	 0x1818, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Gain_BC_Register_HGN_B_ST8_BS	 0x1818, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_DE_Register	0x181c /* SCC_Hue_Gain_DE_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_DE_Register	 0x181c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_DE_Register */
	#define BLSB_DPE_SCC_Hue_Gain_DE_Register_HGN_E_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_Gain_DE_Register_HGN_D_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_DE_Register */
	#define BWID_DPE_SCC_Hue_Gain_DE_Register_HGN_E_ST8_BS	12
	#define BWID_DPE_SCC_Hue_Gain_DE_Register_HGN_D_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_DE_Register */
	#define BMSK_DPE_SCC_Hue_Gain_DE_Register_HGN_E_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Gain_DE_Register_HGN_D_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_DE_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_DE_Register_HGN_E_ST8_BS	 0x181c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Gain_DE_Register_HGN_D_ST8_BS	 0x181c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_FG_Register	0x1820 /* SCC_Hue_Gain_FG_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_FG_Register	 0x1820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_FG_Register */
	#define BLSB_DPE_SCC_Hue_Gain_FG_Register_HGN_G_ST8_BS	16
	#define BLSB_DPE_SCC_Hue_Gain_FG_Register_HGN_F_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_FG_Register */
	#define BWID_DPE_SCC_Hue_Gain_FG_Register_HGN_G_ST8_BS	12
	#define BWID_DPE_SCC_Hue_Gain_FG_Register_HGN_F_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_FG_Register */
	#define BMSK_DPE_SCC_Hue_Gain_FG_Register_HGN_G_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Hue_Gain_FG_Register_HGN_F_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_FG_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_FG_Register_HGN_G_ST8_BS	 0x1820, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Hue_Gain_FG_Register_HGN_F_ST8_BS	 0x1820, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hue_Gain_H_Register	0x1824 /* SCC_Hue_Gain_H_Register */ 
	#define BITFIELD_DPE_SCC_Hue_Gain_H_Register	 0x1824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hue_Gain_H_Register */
	#define BLSB_DPE_SCC_Hue_Gain_H_Register_HGN_H_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Hue_Gain_H_Register */
	#define BWID_DPE_SCC_Hue_Gain_H_Register_HGN_H_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Hue_Gain_H_Register */
	#define BMSK_DPE_SCC_Hue_Gain_H_Register_HGN_H_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Hue_Gain_H_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hue_Gain_H_Register_HGN_H_ST8_BS	 0x1824, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Hslope_0A_AB_Register	0x1828 /* SCC_Hslope_0A_AB_Register */ 
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register	 0x1828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hslope_0A_AB_Register */
	#define BLSB_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_AB_ST1	31
	#define BLSB_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_AB_ST1	24
	#define BLSB_DPE_SCC_Hslope_0A_AB_Register_HSL_AB_ST1	16
	#define BLSB_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_0A_ST1	15
	#define BLSB_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_0A_ST1	8
	#define BLSB_DPE_SCC_Hslope_0A_AB_Register_HSL_0A_ST1	0
	/* Register Bit Widths for DPE_SCC_Hslope_0A_AB_Register */
	#define BWID_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_AB_ST1	1
	#define BWID_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_AB_ST1	4
	#define BWID_DPE_SCC_Hslope_0A_AB_Register_HSL_AB_ST1	8
	#define BWID_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_0A_ST1	1
	#define BWID_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_0A_ST1	4
	#define BWID_DPE_SCC_Hslope_0A_AB_Register_HSL_0A_ST1	8
	/* Register Bit MASKS for DPE_SCC_Hslope_0A_AB_Register */
	#define BMSK_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_AB_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_AB_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Hslope_0A_AB_Register_HSL_AB_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_0A_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_0A_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Hslope_0A_AB_Register_HSL_0A_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Hslope_0A_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_AB_ST1	 0x1828, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_AB_ST1	 0x1828, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register_HSL_AB_ST1	 0x1828, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register_HSL_SGN_0A_ST1	 0x1828, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register_HSL_SFT_0A_ST1	 0x1828, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Hslope_0A_AB_Register_HSL_0A_ST1	 0x1828, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Hslope_BC_CD_Register	0x182c /* SCC_Hslope_BC_CD_Register */ 
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register	 0x182c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hslope_BC_CD_Register */
	#define BLSB_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_CD_ST1	31
	#define BLSB_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_CD_ST1	24
	#define BLSB_DPE_SCC_Hslope_BC_CD_Register_HSL_CD_ST1	16
	#define BLSB_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_BC_ST1	15
	#define BLSB_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_BC_ST1	8
	#define BLSB_DPE_SCC_Hslope_BC_CD_Register_HSL_BC_ST1	0
	/* Register Bit Widths for DPE_SCC_Hslope_BC_CD_Register */
	#define BWID_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_CD_ST1	1
	#define BWID_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_CD_ST1	4
	#define BWID_DPE_SCC_Hslope_BC_CD_Register_HSL_CD_ST1	8
	#define BWID_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_BC_ST1	1
	#define BWID_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_BC_ST1	4
	#define BWID_DPE_SCC_Hslope_BC_CD_Register_HSL_BC_ST1	8
	/* Register Bit MASKS for DPE_SCC_Hslope_BC_CD_Register */
	#define BMSK_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_CD_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_CD_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Hslope_BC_CD_Register_HSL_CD_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_BC_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_BC_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Hslope_BC_CD_Register_HSL_BC_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Hslope_BC_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_CD_ST1	 0x182c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_CD_ST1	 0x182c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register_HSL_CD_ST1	 0x182c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register_HSL_SGN_BC_ST1	 0x182c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register_HSL_SFT_BC_ST1	 0x182c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Hslope_BC_CD_Register_HSL_BC_ST1	 0x182c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Hslope_DE_EF_Register	0x1830 /* SCC_Hslope_DE_EF_Register */ 
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register	 0x1830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hslope_DE_EF_Register */
	#define BLSB_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_EF_ST1	31
	#define BLSB_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_EF_ST1	24
	#define BLSB_DPE_SCC_Hslope_DE_EF_Register_HSL_EF_ST1	16
	#define BLSB_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_DE_ST1	15
	#define BLSB_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_DE_ST1	8
	#define BLSB_DPE_SCC_Hslope_DE_EF_Register_HSL_DE_ST1	0
	/* Register Bit Widths for DPE_SCC_Hslope_DE_EF_Register */
	#define BWID_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_EF_ST1	1
	#define BWID_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_EF_ST1	4
	#define BWID_DPE_SCC_Hslope_DE_EF_Register_HSL_EF_ST1	8
	#define BWID_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_DE_ST1	1
	#define BWID_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_DE_ST1	4
	#define BWID_DPE_SCC_Hslope_DE_EF_Register_HSL_DE_ST1	8
	/* Register Bit MASKS for DPE_SCC_Hslope_DE_EF_Register */
	#define BMSK_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_EF_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_EF_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Hslope_DE_EF_Register_HSL_EF_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_DE_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_DE_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Hslope_DE_EF_Register_HSL_DE_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Hslope_DE_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_EF_ST1	 0x1830, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_EF_ST1	 0x1830, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register_HSL_EF_ST1	 0x1830, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register_HSL_SGN_DE_ST1	 0x1830, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register_HSL_SFT_DE_ST1	 0x1830, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Hslope_DE_EF_Register_HSL_DE_ST1	 0x1830, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Hslope_FG_GH_Register	0x1834 /* SCC_Hslope_FG_GH_Register */ 
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register	 0x1834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hslope_FG_GH_Register */
	#define BLSB_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_GH_ST1	31
	#define BLSB_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_GH_ST1	24
	#define BLSB_DPE_SCC_Hslope_FG_GH_Register_HSL_GH_ST1	16
	#define BLSB_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_FG_ST1	15
	#define BLSB_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_FG_ST1	8
	#define BLSB_DPE_SCC_Hslope_FG_GH_Register_HSL_FG_ST1	0
	/* Register Bit Widths for DPE_SCC_Hslope_FG_GH_Register */
	#define BWID_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_GH_ST1	1
	#define BWID_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_GH_ST1	4
	#define BWID_DPE_SCC_Hslope_FG_GH_Register_HSL_GH_ST1	8
	#define BWID_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_FG_ST1	1
	#define BWID_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_FG_ST1	4
	#define BWID_DPE_SCC_Hslope_FG_GH_Register_HSL_FG_ST1	8
	/* Register Bit MASKS for DPE_SCC_Hslope_FG_GH_Register */
	#define BMSK_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_GH_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_GH_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Hslope_FG_GH_Register_HSL_GH_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_FG_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_FG_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Hslope_FG_GH_Register_HSL_FG_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Hslope_FG_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_GH_ST1	 0x1834, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_GH_ST1	 0x1834, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register_HSL_GH_ST1	 0x1834, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register_HSL_SGN_FG_ST1	 0x1834, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register_HSL_SFT_FG_ST1	 0x1834, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Hslope_FG_GH_Register_HSL_FG_ST1	 0x1834, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Hslope_H1_Register	0x1838 /* SCC_Hslope_H1_Register */ 
	#define BITFIELD_DPE_SCC_Hslope_H1_Register	 0x1838, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Hslope_H1_Register */
	#define BLSB_DPE_SCC_Hslope_H1_Register_HSL_SGN_H1_ST1	15
	#define BLSB_DPE_SCC_Hslope_H1_Register_HSL_SFT_H1_ST1	8
	#define BLSB_DPE_SCC_Hslope_H1_Register_HSL_H1_ST1	0
	/* Register Bit Widths for DPE_SCC_Hslope_H1_Register */
	#define BWID_DPE_SCC_Hslope_H1_Register_HSL_SGN_H1_ST1	1
	#define BWID_DPE_SCC_Hslope_H1_Register_HSL_SFT_H1_ST1	4
	#define BWID_DPE_SCC_Hslope_H1_Register_HSL_H1_ST1	8
	/* Register Bit MASKS for DPE_SCC_Hslope_H1_Register */
	#define BMSK_DPE_SCC_Hslope_H1_Register_HSL_SGN_H1_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Hslope_H1_Register_HSL_SFT_H1_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Hslope_H1_Register_HSL_H1_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Hslope_H1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Hslope_H1_Register_HSL_SGN_H1_ST1	 0x1838, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Hslope_H1_Register_HSL_SFT_H1_ST1	 0x1838, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Hslope_H1_Register_HSL_H1_ST1	 0x1838, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_delta_0A_Register	0x183c /* SCC_Saturation_delta_0A_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_delta_0A_Register	 0x183c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_delta_0A_Register */
	#define BLSB_DPE_SCC_Saturation_delta_0A_Register_SDELTA_A_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_delta_0A_Register_SDELTA_0_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_delta_0A_Register */
	#define BWID_DPE_SCC_Saturation_delta_0A_Register_SDELTA_A_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_delta_0A_Register_SDELTA_0_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_delta_0A_Register */
	#define BMSK_DPE_SCC_Saturation_delta_0A_Register_SDELTA_A_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_delta_0A_Register_SDELTA_0_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_delta_0A_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_delta_0A_Register_SDELTA_A_ST8_BS	 0x183c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_delta_0A_Register_SDELTA_0_ST8_BS	 0x183c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_delta_BC_Register	0x1840 /* SCC_Saturation_delta_BC_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_delta_BC_Register	 0x1840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_delta_BC_Register */
	#define BLSB_DPE_SCC_Saturation_delta_BC_Register_SDELTA_C_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_delta_BC_Register_SDELTA_B_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_delta_BC_Register */
	#define BWID_DPE_SCC_Saturation_delta_BC_Register_SDELTA_C_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_delta_BC_Register_SDELTA_B_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_delta_BC_Register */
	#define BMSK_DPE_SCC_Saturation_delta_BC_Register_SDELTA_C_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_delta_BC_Register_SDELTA_B_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_delta_BC_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_delta_BC_Register_SDELTA_C_ST8_BS	 0x1840, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_delta_BC_Register_SDELTA_B_ST8_BS	 0x1840, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_delta_DE_Register	0x1844 /* SCC_Saturation_delta_DE_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_delta_DE_Register	 0x1844, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_delta_DE_Register */
	#define BLSB_DPE_SCC_Saturation_delta_DE_Register_SDELTA_E_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_delta_DE_Register_SDELTA_D_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_delta_DE_Register */
	#define BWID_DPE_SCC_Saturation_delta_DE_Register_SDELTA_E_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_delta_DE_Register_SDELTA_D_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_delta_DE_Register */
	#define BMSK_DPE_SCC_Saturation_delta_DE_Register_SDELTA_E_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_delta_DE_Register_SDELTA_D_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_delta_DE_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_delta_DE_Register_SDELTA_E_ST8_BS	 0x1844, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_delta_DE_Register_SDELTA_D_ST8_BS	 0x1844, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_delta_FG_Register	0x1848 /* SCC_Saturation_delta_FG_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_delta_FG_Register	 0x1848, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_delta_FG_Register */
	#define BLSB_DPE_SCC_Saturation_delta_FG_Register_SDELTA_G_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_delta_FG_Register_SDELTA_F_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_delta_FG_Register */
	#define BWID_DPE_SCC_Saturation_delta_FG_Register_SDELTA_G_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_delta_FG_Register_SDELTA_F_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_delta_FG_Register */
	#define BMSK_DPE_SCC_Saturation_delta_FG_Register_SDELTA_G_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_delta_FG_Register_SDELTA_F_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_delta_FG_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_delta_FG_Register_SDELTA_G_ST8_BS	 0x1848, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_delta_FG_Register_SDELTA_F_ST8_BS	 0x1848, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_delta_H_Register	0x184c /* SCC_Saturation_delta_H_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_delta_H_Register	 0x184c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_delta_H_Register */
	#define BLSB_DPE_SCC_Saturation_delta_H_Register_SDELTA_H_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_delta_H_Register */
	#define BWID_DPE_SCC_Saturation_delta_H_Register_SDELTA_H_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_delta_H_Register */
	#define BMSK_DPE_SCC_Saturation_delta_H_Register_SDELTA_H_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_delta_H_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_delta_H_Register_SDELTA_H_ST8_BS	 0x184c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register	0x1850 /* SCC_SDelta_Saturation_slope_0A_AB_Register */ 
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register	 0x1850, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SDelta_Saturation_slope_0A_AB_Register */
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_AB_ST1	31
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_AB_ST1	24
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_AB_ST1	16
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_0A_ST1	15
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_0A_ST1	8
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_0A_ST1	0
	/* Register Bit Widths for DPE_SCC_SDelta_Saturation_slope_0A_AB_Register */
	#define BWID_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_AB_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_AB_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_AB_ST1	8
	#define BWID_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_0A_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_0A_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_0A_ST1	8
	/* Register Bit MASKS for DPE_SCC_SDelta_Saturation_slope_0A_AB_Register */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_AB_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_AB_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_AB_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_0A_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_0A_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_0A_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_SDelta_Saturation_slope_0A_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_AB_ST1	 0x1850, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_AB_ST1	 0x1850, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_AB_ST1	 0x1850, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SGN_0A_ST1	 0x1850, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_SFT_0A_ST1	 0x1850, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_0A_AB_Register_SSL_0A_ST1	 0x1850, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register	0x1854 /* SCC_SDelta_Saturation_slope_BC_CD_Register */ 
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register	 0x1854, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SDelta_Saturation_slope_BC_CD_Register */
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_CD_ST1	31
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_CD_ST1	24
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_CD_ST1	16
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_BC_ST1	15
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_BC_ST1	8
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_BC_ST1	0
	/* Register Bit Widths for DPE_SCC_SDelta_Saturation_slope_BC_CD_Register */
	#define BWID_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_CD_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_CD_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_CD_ST1	8
	#define BWID_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_BC_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_BC_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_BC_ST1	8
	/* Register Bit MASKS for DPE_SCC_SDelta_Saturation_slope_BC_CD_Register */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_CD_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_CD_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_CD_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_BC_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_BC_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_BC_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_SDelta_Saturation_slope_BC_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_CD_ST1	 0x1854, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_CD_ST1	 0x1854, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_CD_ST1	 0x1854, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SGN_BC_ST1	 0x1854, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_SFT_BC_ST1	 0x1854, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_BC_CD_Register_SSL_BC_ST1	 0x1854, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register	0x1858 /* SCC_SDelta_Saturation_slope_DE_EF_Register */ 
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register	 0x1858, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SDelta_Saturation_slope_DE_EF_Register */
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_EF_ST1	31
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_EF_ST1	24
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_EF_ST1	16
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_DE_ST1	15
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_DE_ST1	8
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_DE_ST1	0
	/* Register Bit Widths for DPE_SCC_SDelta_Saturation_slope_DE_EF_Register */
	#define BWID_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_EF_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_EF_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_EF_ST1	8
	#define BWID_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_DE_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_DE_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_DE_ST1	8
	/* Register Bit MASKS for DPE_SCC_SDelta_Saturation_slope_DE_EF_Register */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_EF_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_EF_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_EF_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_DE_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_DE_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_DE_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_SDelta_Saturation_slope_DE_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_EF_ST1	 0x1858, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_EF_ST1	 0x1858, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_EF_ST1	 0x1858, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SGN_DE_ST1	 0x1858, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_SFT_DE_ST1	 0x1858, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_DE_EF_Register_SSL_DE_ST1	 0x1858, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register	0x185c /* SCC_SDelta_Saturation_slope_FG_GH_Register */ 
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register	 0x185c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SDelta_Saturation_slope_FG_GH_Register */
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_GH_ST1	31
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_GH_ST1	24
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_GH_ST1	16
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_FG_ST1	15
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_FG_ST1	8
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_FG_ST1	0
	/* Register Bit Widths for DPE_SCC_SDelta_Saturation_slope_FG_GH_Register */
	#define BWID_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_GH_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_GH_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_GH_ST1	8
	#define BWID_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_FG_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_FG_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_FG_ST1	8
	/* Register Bit MASKS for DPE_SCC_SDelta_Saturation_slope_FG_GH_Register */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_GH_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_GH_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_GH_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_FG_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_FG_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_FG_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_SDelta_Saturation_slope_FG_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_GH_ST1	 0x185c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_GH_ST1	 0x185c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_GH_ST1	 0x185c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SGN_FG_ST1	 0x185c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_SFT_FG_ST1	 0x185c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_FG_GH_Register_SSL_FG_ST1	 0x185c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_SDelta_Saturation_slope_H1_Register	0x1860 /* SCC_SDelta_Saturation_slope_H1_Register */ 
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_H1_Register	 0x1860, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_SDelta_Saturation_slope_H1_Register */
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SGN_H1_ST1	15
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SFT_H1_ST1	8
	#define BLSB_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_H1_ST1	0
	/* Register Bit Widths for DPE_SCC_SDelta_Saturation_slope_H1_Register */
	#define BWID_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SGN_H1_ST1	1
	#define BWID_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SFT_H1_ST1	4
	#define BWID_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_H1_ST1	8
	/* Register Bit MASKS for DPE_SCC_SDelta_Saturation_slope_H1_Register */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SGN_H1_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SFT_H1_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_H1_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_SDelta_Saturation_slope_H1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SGN_H1_ST1	 0x1860, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_SFT_H1_ST1	 0x1860, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_SDelta_Saturation_slope_H1_Register_SSL_H1_ST1	 0x1860, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Intensity_Gain_0A_Register	0x1864 /* SCC_Intensity_Gain_0A_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_0A_Register	 0x1864, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_0A_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_0A_Register_IGN_A_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_Gain_0A_Register_IGN_0_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_0A_Register */
	#define BWID_DPE_SCC_Intensity_Gain_0A_Register_IGN_A_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_Gain_0A_Register_IGN_0_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_0A_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_0A_Register_IGN_A_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_Gain_0A_Register_IGN_0_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_0A_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_0A_Register_IGN_A_ST8_BS	 0x1864, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_Gain_0A_Register_IGN_0_ST8_BS	 0x1864, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_Gain_BC_Register	0x1868 /* SCC_Intensity_Gain_BC_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_BC_Register	 0x1868, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_BC_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_BC_Register_IGN_C_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_Gain_BC_Register_IGN_B_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_BC_Register */
	#define BWID_DPE_SCC_Intensity_Gain_BC_Register_IGN_C_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_Gain_BC_Register_IGN_B_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_BC_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_BC_Register_IGN_C_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_Gain_BC_Register_IGN_B_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_BC_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_BC_Register_IGN_C_ST8_BS	 0x1868, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_Gain_BC_Register_IGN_B_ST8_BS	 0x1868, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_Gain_DE_Register	0x186c /* SCC_Intensity_Gain_DE_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_DE_Register	 0x186c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_DE_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_DE_Register_IGN_E_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_Gain_DE_Register_IGN_D_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_DE_Register */
	#define BWID_DPE_SCC_Intensity_Gain_DE_Register_IGN_E_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_Gain_DE_Register_IGN_D_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_DE_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_DE_Register_IGN_E_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_Gain_DE_Register_IGN_D_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_DE_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_DE_Register_IGN_E_ST8_BS	 0x186c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_Gain_DE_Register_IGN_D_ST8_BS	 0x186c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_Gain_FG_Register	0x1870 /* SCC_Intensity_Gain_FG_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_FG_Register	 0x1870, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_FG_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_FG_Register_IGN_G_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_Gain_FG_Register_IGN_F_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_FG_Register */
	#define BWID_DPE_SCC_Intensity_Gain_FG_Register_IGN_G_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_Gain_FG_Register_IGN_F_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_FG_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_FG_Register_IGN_G_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_Gain_FG_Register_IGN_F_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_FG_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_FG_Register_IGN_G_ST8_BS	 0x1870, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_Gain_FG_Register_IGN_F_ST8_BS	 0x1870, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_Gain_H_Register	0x1874 /* SCC_Intensity_Gain_H_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_Gain_H_Register	 0x1874, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_Gain_H_Register */
	#define BLSB_DPE_SCC_Intensity_Gain_H_Register_IGN_H_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_Gain_H_Register */
	#define BWID_DPE_SCC_Intensity_Gain_H_Register_IGN_H_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_Gain_H_Register */
	#define BMSK_DPE_SCC_Intensity_Gain_H_Register_IGN_H_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_Gain_H_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_Gain_H_Register_IGN_H_ST8_BS	 0x1874, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_slope_0A_AB_Register	0x1878 /* SCC_Saturation_slope_0A_AB_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register	 0x1878, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_0A_AB_Register */
	#define BLSB_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_AB_ST1	31
	#define BLSB_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_AB_ST1	24
	#define BLSB_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_AB_ST1	16
	#define BLSB_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_0A_ST1	15
	#define BLSB_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_0A_ST1	8
	#define BLSB_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_0A_ST1	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_0A_AB_Register */
	#define BWID_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_AB_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_AB_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_AB_ST1	8
	#define BWID_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_0A_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_0A_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_0A_ST1	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_0A_AB_Register */
	#define BMSK_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_AB_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_AB_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_AB_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_0A_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_0A_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_0A_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_0A_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_AB_ST1	 0x1878, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_AB_ST1	 0x1878, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_AB_ST1	 0x1878, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SGN_0A_ST1	 0x1878, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_SFT_0A_ST1	 0x1878, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_0A_AB_Register_ISL_0A_ST1	 0x1878, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_BC_CD_Register	0x187c /* SCC_Saturation_slope_BC_CD_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register	 0x187c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_BC_CD_Register */
	#define BLSB_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_CD_ST1	31
	#define BLSB_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_CD_ST1	24
	#define BLSB_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_CD_ST1	16
	#define BLSB_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_BC_ST1	15
	#define BLSB_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_BC_ST1	8
	#define BLSB_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_BC_ST1	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_BC_CD_Register */
	#define BWID_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_CD_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_CD_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_CD_ST1	8
	#define BWID_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_BC_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_BC_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_BC_ST1	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_BC_CD_Register */
	#define BMSK_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_CD_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_CD_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_CD_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_BC_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_BC_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_BC_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_BC_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_CD_ST1	 0x187c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_CD_ST1	 0x187c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_CD_ST1	 0x187c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SGN_BC_ST1	 0x187c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_SFT_BC_ST1	 0x187c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_BC_CD_Register_ISL_BC_ST1	 0x187c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_DE_EF_Register	0x1880 /* SCC_Saturation_slope_DE_EF_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register	 0x1880, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_DE_EF_Register */
	#define BLSB_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_EF_ST1	31
	#define BLSB_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_EF_ST1	24
	#define BLSB_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_EF_ST1	16
	#define BLSB_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_DE_ST1	15
	#define BLSB_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_DE_ST1	8
	#define BLSB_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_DE_ST1	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_DE_EF_Register */
	#define BWID_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_EF_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_EF_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_EF_ST1	8
	#define BWID_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_DE_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_DE_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_DE_ST1	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_DE_EF_Register */
	#define BMSK_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_EF_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_EF_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_EF_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_DE_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_DE_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_DE_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_DE_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_EF_ST1	 0x1880, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_EF_ST1	 0x1880, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_EF_ST1	 0x1880, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SGN_DE_ST1	 0x1880, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_SFT_DE_ST1	 0x1880, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_DE_EF_Register_ISL_DE_ST1	 0x1880, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_FG_GH_Register	0x1884 /* SCC_Saturation_slope_FG_GH_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register	 0x1884, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_FG_GH_Register */
	#define BLSB_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_GH_ST1	31
	#define BLSB_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_GH_ST1	24
	#define BLSB_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_GH_ST1	16
	#define BLSB_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_FG_ST1	15
	#define BLSB_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_FG_ST1	8
	#define BLSB_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_FG_ST1	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_FG_GH_Register */
	#define BWID_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_GH_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_GH_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_GH_ST1	8
	#define BWID_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_FG_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_FG_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_FG_ST1	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_FG_GH_Register */
	#define BMSK_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_GH_ST1	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_GH_ST1	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_GH_ST1	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_FG_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_FG_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_FG_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_FG_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_GH_ST1	 0x1884, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_GH_ST1	 0x1884, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_GH_ST1	 0x1884, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SGN_FG_ST1	 0x1884, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_SFT_FG_ST1	 0x1884, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_FG_GH_Register_ISL_FG_ST1	 0x1884, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_H1_Register	0x1888 /* SCC_Saturation_slope_H1_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_H1_Register	 0x1888, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_H1_Register */
	#define BLSB_DPE_SCC_Saturation_slope_H1_Register_ISL_SGN_H1_ST1	15
	#define BLSB_DPE_SCC_Saturation_slope_H1_Register_ISL_SFT_H1_ST1	8
	#define BLSB_DPE_SCC_Saturation_slope_H1_Register_ISL_H1_ST1	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_H1_Register */
	#define BWID_DPE_SCC_Saturation_slope_H1_Register_ISL_SGN_H1_ST1	1
	#define BWID_DPE_SCC_Saturation_slope_H1_Register_ISL_SFT_H1_ST1	4
	#define BWID_DPE_SCC_Saturation_slope_H1_Register_ISL_H1_ST1	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_H1_Register */
	#define BMSK_DPE_SCC_Saturation_slope_H1_Register_ISL_SGN_H1_ST1	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_H1_Register_ISL_SFT_H1_ST1	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_H1_Register_ISL_H1_ST1	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_H1_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_H1_Register_ISL_SGN_H1_ST1	 0x1888, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_H1_Register_ISL_SFT_H1_ST1	 0x1888, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_H1_Register_ISL_H1_ST1	 0x1888, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register	0x188c /* SCC_Saturation_thresh_AB_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register	 0x188c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_B_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_A_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_B_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_A_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_B_ST8_BS	 0x188c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_hue_limiter_Register_STH_HLIM_A_ST8_BS	 0x188c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register	0x1890 /* SCC_Saturation_thresh_CD_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register	 0x1890, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register */
	#define BWID_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_D_ST8_BS	12
	#define BWID_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_D_ST8_BS	 0x1890, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_aturation_thresh_CD_for_hue_limiter_Register_STH_HLIM_C_ST8_BS	 0x1890, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register	0x1894 /* SCC_Saturation_thresh_EF_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register	 0x1894, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_F_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_F_ST8_BS	 0x1894, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_hue_limiter_Register_STH_HLIM_E_ST8_BS	 0x1894, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register	0x1898 /* SCC_Saturation_thresh_GH_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register	 0x1898, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_H_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_H_ST8_BS	 0x1898, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_hue_limiter_Register_STH_HLIM_G_ST8_BS	 0x1898, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register	0x189c /* SCC_S_slope_AB_BC_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register	 0x189c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_BC_ST8_BS	31
	#define BLSB_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_BC_ST8_BS	24
	#define BLSB_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_BC_ST8_BS	16
	#define BLSB_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_AB_ST8_BS	15
	#define BLSB_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_AB_ST8_BS	8
	#define BLSB_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_AB_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register */
	#define BWID_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_BC_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_BC_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_BC_ST8_BS	8
	#define BWID_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_AB_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_AB_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_AB_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_BC_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_BC_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_BC_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_AB_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_AB_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_AB_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_BC_ST8_BS	 0x189c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_BC_ST8_BS	 0x189c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_BC_ST8_BS	 0x189c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SGN_HLIM_AB_ST8_BS	 0x189c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_SFT_HLIM_AB_ST8_BS	 0x189c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_S_slope_AB_BC_for_hue_limiter_Register_S_SLP_HLIM_AB_ST8_BS	 0x189c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register	0x18a0 /* SCC_S_slope_CD_DE_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register	 0x18a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_DE_ST8_BS	31
	#define BLSB_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_DE_ST8_BS	24
	#define BLSB_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_DE_ST8_BS	16
	#define BLSB_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_CD_ST8_BS	15
	#define BLSB_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_CD_ST8_BS	8
	#define BLSB_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_CD_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register */
	#define BWID_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_DE_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_DE_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_DE_ST8_BS	8
	#define BWID_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_CD_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_CD_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_CD_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_DE_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_DE_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_DE_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_CD_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_CD_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_CD_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_DE_ST8_BS	 0x18a0, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_DE_ST8_BS	 0x18a0, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_DE_ST8_BS	 0x18a0, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SGN_HLIM_CD_ST8_BS	 0x18a0, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_SFT_HLIM_CD_ST8_BS	 0x18a0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_S_slope_CD_DE_for_hue_limiter_Register_S_SLP_HLIM_CD_ST8_BS	 0x18a0, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register	0x18a4 /* SCC_S_slope_EF_FG_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register	 0x18a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_FG_ST8_BS	31
	#define BLSB_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_FG_ST8_BS	24
	#define BLSB_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_FG_ST8_BS	16
	#define BLSB_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_EF_ST8_BS	15
	#define BLSB_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_EF_ST8_BS	8
	#define BLSB_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_EF_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register */
	#define BWID_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_FG_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_FG_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_FG_ST8_BS	8
	#define BWID_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_EF_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_EF_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_EF_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_FG_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_FG_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_FG_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_EF_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_EF_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_EF_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_FG_ST8_BS	 0x18a4, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_FG_ST8_BS	 0x18a4, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_FG_ST8_BS	 0x18a4, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SGN_HLIM_EF_ST8_BS	 0x18a4, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_SFT_HLIM_EF_ST8_BS	 0x18a4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_S_slope_EF_FG_for_hue_limiter_Register_S_SLP_HLIM_EF_ST8_BS	 0x18a4, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_S_slope_GH_for_hue_limiter_Register	0x18a8 /* SCC_S_slope_GH_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_S_slope_GH_for_hue_limiter_Register	 0x18a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_S_slope_GH_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SGN_HLIM_GH_ST8_BS	15
	#define BLSB_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SFT_HLIM_GH_ST8_BS	8
	#define BLSB_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_HLIM_GH_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_S_slope_GH_for_hue_limiter_Register */
	#define BWID_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SGN_HLIM_GH_ST8_BS	1
	#define BWID_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SFT_HLIM_GH_ST8_BS	4
	#define BWID_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_HLIM_GH_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_S_slope_GH_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SGN_HLIM_GH_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SFT_HLIM_GH_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_HLIM_GH_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_S_slope_GH_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SGN_HLIM_GH_ST8_BS	 0x18a8, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_SFT_HLIM_GH_ST8_BS	 0x18a8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_S_slope_GH_for_hue_limiter_Register_S_SLP_HLIM_GH_ST8_BS	 0x18a8, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register	0x18ac /* SCC_Saturation_limit_for_hue_limiter_AB_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register	 0x18ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_B_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_A_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_B_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_A_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_B_ST8_BS	 0x18ac, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_AB_Register_S_HLIM_A_ST8_BS	 0x18ac, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register	0x18b0 /* SCC_Saturation_limit_for_hue_limiter_CD_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register	 0x18b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_D_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_C_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_D_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_C_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_D_ST8_BS	 0x18b0, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_CD_Register_S_HLIM_C_ST8_BS	 0x18b0, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register	0x18b4 /* SCC_Saturation_limit_for_hue_limiter_EF_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register	 0x18b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_F_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_E_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_F_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_E_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_F_ST8_BS	 0x18b4, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_hue_limiter_EF_Register_S_HLIM_E_ST8_BS	 0x18b4, 0, 8, 0x000000ff
#define ROFF_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register	0x18b8 /* SCC_Saturation_limit_for_hue_limiter_GH_Register */ 
	#define BITFIELD_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register	 0x18b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register */
	#define BLSB_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_H_ST8_BS	16
	#define BLSB_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register */
	#define BWID_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_H_ST8_BS	8
	#define BWID_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_G_ST8_BS	8
	/* Register Bit MASKS for DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register */
	#define BMSK_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_H_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_G_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_H_ST8_BS	 0x18b8, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SSC_Saturation_limit_for_hue_limiter_GH_Register_S_HLIM_G_ST8_BS	 0x18b8, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register	0x18bc /* SCC_Intensity_thresh_AB_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register	 0x18bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_B_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_A_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_B_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_A_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_B_ST8_BS	 0x18bc, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_hue_limiter_Register_ITH_HLIM_A_ST8_BS	 0x18bc, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register	0x18c0 /* SCC_Intensity_thresh_CD_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register	 0x18c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_D_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_D_ST8_BS	 0x18c0, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_hue_limiter_Register_ITH_HLIM_C_ST8_BS	 0x18c0, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register	0x18c4 /* SCC_Intensity_thresh_EF_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register	 0x18c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_F_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_F_ST8_BS	 0x18c4, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_hue_limiter_Register_ITH_HLIM_E_ST8_BS	 0x18c4, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register	0x18c8 /* SCC_Intensity_thresh_GH_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register	 0x18c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_H_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_H_ST8_BS	 0x18c8, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_hue_limiter_Register_ITH_HLIM_G_ST8_BS	 0x18c8, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register	0x18cc /* SCC_Saturation_slope_AB_BC_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register	 0x18cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_BC_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_BC_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_BC_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_AB_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_AB_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_AB_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_BC_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_BC_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_BC_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_AB_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_AB_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_AB_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_BC_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_BC_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_BC_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_AB_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_AB_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_AB_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_BC_ST8_BS	 0x18cc, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_BC_ST8_BS	 0x18cc, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_BC_ST8_BS	 0x18cc, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SGN_HLIM_AB_ST8_BS	 0x18cc, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_SFT_HLIM_AB_ST8_BS	 0x18cc, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_hue_limiter_Register_I_SLP_HLIM_AB_ST8_BS	 0x18cc, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register	0x18d0 /* SCC_Saturation_slope_CD_DE_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register	 0x18d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_DE_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_DE_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_DE_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_CD_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_CD_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_CD_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_DE_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_DE_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_DE_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_CD_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_CD_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_CD_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_DE_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_DE_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_DE_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_CD_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_CD_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_CD_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_DE_ST8_BS	 0x18d0, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_DE_ST8_BS	 0x18d0, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_DE_ST8_BS	 0x18d0, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SGN_HLIM_CD_ST8_BS	 0x18d0, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_SFT_HLIM_CD_ST8_BS	 0x18d0, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_hue_limiter_Register_I_SLP_HLIM_CD_ST8_BS	 0x18d0, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register	0x18d4 /* SCC_Saturation_slope_EF_FG_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register	 0x18d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_FG_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_FG_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_FG_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_EF_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_EF_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_EF_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_FG_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_FG_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_FG_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_EF_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_EF_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_EF_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_FG_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_FG_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_FG_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_EF_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_EF_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_EF_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_FG_ST8_BS	 0x18d4, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_FG_ST8_BS	 0x18d4, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_FG_ST8_BS	 0x18d4, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SGN_HLIM_EF_ST8_BS	 0x18d4, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_SFT_HLIM_EF_ST8_BS	 0x18d4, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_ED_FG_for_hue_limiter_Register_I_SLP_HLIM_EF_ST8_BS	 0x18d4, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register	0x18d8 /* SCC_Saturation_slope_GH_for_hue_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register	 0x18d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SGN_HLIM_GH_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SFT_HLIM_GH_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_HLIM_GH_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SGN_HLIM_GH_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SFT_HLIM_GH_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_HLIM_GH_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SGN_HLIM_GH_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SFT_HLIM_GH_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_HLIM_GH_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SGN_HLIM_GH_ST8_BS	 0x18d8, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_SFT_HLIM_GH_ST8_BS	 0x18d8, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_hue_limiter_Register_I_SLP_HLIM_GH_ST8_BS	 0x18d8, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_limit_for_hue_limiter_AB_Register	0x18dc /* SCC_I_limit_for_hue_limiter_AB_Register */ 
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_AB_Register	 0x18dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_limit_for_hue_limiter_AB_Register */
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_limit_for_hue_limiter_AB_Register */
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_B_ST8_BS	8
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_A_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_limit_for_hue_limiter_AB_Register */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_B_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_A_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_limit_for_hue_limiter_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_B_ST8_BS	 0x18dc, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_AB_Register_I_HLIM_A_ST8_BS	 0x18dc, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_limit_for_hue_limiter_CD_Register	0x18e0 /* SCC_I_limit_for_hue_limiter_CD_Register */ 
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_CD_Register	 0x18e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_limit_for_hue_limiter_CD_Register */
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_limit_for_hue_limiter_CD_Register */
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_D_ST8_BS	8
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_C_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_limit_for_hue_limiter_CD_Register */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_D_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_C_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_limit_for_hue_limiter_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_D_ST8_BS	 0x18e0, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_CD_Register_I_HLIM_C_ST8_BS	 0x18e0, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_limit_for_hue_limiter_EF_Register	0x18e4 /* SCC_I_limit_for_hue_limiter_EF_Register */ 
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_EF_Register	 0x18e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_limit_for_hue_limiter_EF_Register */
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_limit_for_hue_limiter_EF_Register */
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_F_ST8_BS	8
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_E_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_limit_for_hue_limiter_EF_Register */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_F_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_E_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_limit_for_hue_limiter_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_F_ST8_BS	 0x18e4, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_EF_Register_I_HLIM_E_ST8_BS	 0x18e4, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_limit_for_hue_limiter_GH_Register	0x18e8 /* SCC_I_limit_for_hue_limiter_GH_Register */ 
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_GH_Register	 0x18e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_limit_for_hue_limiter_GH_Register */
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_limit_for_hue_limiter_GH_Register */
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_H_ST8_BS	8
	#define BWID_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_G_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_limit_for_hue_limiter_GH_Register */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_H_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_G_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_limit_for_hue_limiter_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_H_ST8_BS	 0x18e8, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_limit_for_hue_limiter_GH_Register_I_HLIM_G_ST8_BS	 0x18e8, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register	0x18ec /* SCC_Saturation_thresh_AB_for_Sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register	 0x18ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_B_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_A_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_B_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_A_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_B_ST8_BS	 0x18ec, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_Sat_limiter_Register_STH_SLIM_A_ST8_BS	 0x18ec, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register	0x18f0 /* SCC_Saturation_thresh_CD_for_Sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register	 0x18f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_D_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_D_ST8_BS	 0x18f0, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_Sat_limiter_Register_STH_SLIM_C_ST8_BS	 0x18f0, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register	0x18f4 /* SCC_Saturation_thresh_EF_for_Sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register	 0x18f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_F_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_F_ST8_BS	 0x18f4, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_Sat_limiter_Register_STH_SLIM_E_ST8_BS	 0x18f4, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register	0x18f8 /* SCC_Saturation_thresh_GH_for_Sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register	 0x18f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_H_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_H_ST8_BS	 0x18f8, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_Sat_limiter_Register_STH_SLIM_G_ST8_BS	 0x18f8, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register	0x18fc /* SCC_Saturation_slope_AB_BC_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register	 0x18fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_BC_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_BC_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_BC_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_AB_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_AB_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_AB_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_BC_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_BC_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_BC_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_AB_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_AB_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_AB_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_BC_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_BC_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_BC_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_AB_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_AB_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_AB_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_BC_ST8_BS	 0x18fc, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_BC_ST8_BS	 0x18fc, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_BC_ST8_BS	 0x18fc, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SGN_SLIM_AB_ST8_BS	 0x18fc, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SFT_SLIM_AB_ST8_BS	 0x18fc, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_sat_limiter_Register_S_SLP_SLIM_AB_ST8_BS	 0x18fc, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register	0x1900 /* SCC_Saturation_slope_CD_DE_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register	 0x1900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_DE_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_DE_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_DE_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_CD_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_CD_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_CD_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_DE_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_DE_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_DE_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_CD_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_CD_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_CD_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_DE_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_DE_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_DE_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_CD_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_CD_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_CD_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_DE_ST8_BS	 0x1900, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_DE_ST8_BS	 0x1900, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_DE_ST8_BS	 0x1900, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SGN_SLIM_CD_ST8_BS	 0x1900, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SFT_SLIM_CD_ST8_BS	 0x1900, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_sat_limiter_Register_S_SLP_SLIM_CD_ST8_BS	 0x1900, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register	0x1904 /* SCC_Saturation_slope_EF_FG_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register	 0x1904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_FG_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_FG_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_FG_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_EF_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_EF_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_EF_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_FG_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_FG_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_FG_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_EF_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_EF_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_EF_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_FG_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_FG_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_FG_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_EF_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_EF_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_EF_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_FG_ST8_BS	 0x1904, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_FG_ST8_BS	 0x1904, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_FG_ST8_BS	 0x1904, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SGN_SLIM_EF_ST8_BS	 0x1904, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SFT_SLIM_EF_ST8_BS	 0x1904, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_sat_limiter_Register_S_SLP_SLIM_EF_ST8_BS	 0x1904, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register	0x1908 /* SCC_Saturation_slope_GH_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register	 0x1908, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SGN_SLIM_GH_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SFT_SLIM_GH_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SLIM_GH_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SGN_SLIM_GH_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SFT_SLIM_GH_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SLIM_GH_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SGN_SLIM_GH_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SFT_SLIM_GH_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SLIM_GH_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SGN_SLIM_GH_ST8_BS	 0x1908, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SFT_SLIM_GH_ST8_BS	 0x1908, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_sat_limiter_Register_S_SLP_SLIM_GH_ST8_BS	 0x1908, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register	0x190c /* SCC_Saturation_limit_for_sat_limiter_AB_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register	 0x190c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_B_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_A_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_B_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_A_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_B_ST8_BS	 0x190c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_AB_Register_S_SLIM_A_ST8_BS	 0x190c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register	0x1910 /* SCC_Saturation_limit_for_sat_limiter_CD_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register	 0x1910, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_D_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_C_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_D_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_C_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_D_ST8_BS	 0x1910, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_CD_Register_S_SLIM_C_ST8_BS	 0x1910, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register	0x1914 /* SCC_Saturation_limit_for_sat_limiter_EF_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register	 0x1914, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_F_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_E_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_F_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_E_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_F_ST8_BS	 0x1914, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_EF_Register_S_SLIM_E_ST8_BS	 0x1914, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register	0x1918 /* SCC_Saturation_limit_for_sat_limiter_GH_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register	 0x1918, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_H_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_G_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_H_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_G_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_H_ST8_BS	 0x1918, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_sat_limiter_GH_Register_S_SLIM_G_ST8_BS	 0x1918, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register	0x191c /* SCC_Intensity_thresh_AB_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register	 0x191c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_B_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_A_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_B_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_A_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_B_ST8_BS	 0x191c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_sat_limiter_Register_ITH_SLIM_A_ST8_BS	 0x191c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register	0x1920 /* SCC_Intensity_thresh_CD_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register	 0x1920, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_D_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_D_ST8_BS	 0x1920, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_sat_limiter_Register_ITH_SLIM_C_ST8_BS	 0x1920, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register	0x1924 /* SCC_Intensity_thresh_EF_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register	 0x1924, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_F_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_F_ST8_BS	 0x1924, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_sat_limiter_Register_ITH_SLIM_E_ST8_BS	 0x1924, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register	0x1928 /* SCC_Intensity_thresh_GH_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register	 0x1928, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_H_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_H_ST8_BS	 0x1928, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_sat_limiter_Register_ITH_SLIM_G_ST8_BS	 0x1928, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register	0x192c /* SCC_I_Slope_AB_BC_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register	 0x192c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_BC_ST8_BS	31
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_BC_ST8_BS	24
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_BC_ST8_BS	16
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_AB_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_AB_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_AB_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_BC_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_BC_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_BC_ST8_BS	8
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_AB_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_AB_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_AB_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_BC_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_BC_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_BC_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_AB_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_AB_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_AB_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_BC_ST8_BS	 0x192c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_BC_ST8_BS	 0x192c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_BC_ST8_BS	 0x192c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SGN_SLIM_AB_ST8_BS	 0x192c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SFT_SLIM_AB_ST8_BS	 0x192c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_sat_limiter_Register_I_SLP_SLIM_AB_ST8_BS	 0x192c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register	0x1930 /* SCC_I_Slope_CD_DE_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register	 0x1930, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_DE_ST8_BS	31
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_DE_ST8_BS	24
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_DE_ST8_BS	16
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_CD_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_CD_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_CD_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_DE_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_DE_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_DE_ST8_BS	8
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_CD_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_CD_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_CD_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_DE_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_DE_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_DE_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_CD_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_CD_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_CD_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_DE_ST8_BS	 0x1930, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_DE_ST8_BS	 0x1930, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_DE_ST8_BS	 0x1930, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SGN_SLIM_CD_ST8_BS	 0x1930, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SFT_SLIM_CD_ST8_BS	 0x1930, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_sat_limiter_Register_I_SLP_SLIM_CD_ST8_BS	 0x1930, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register	0x1934 /* SCC_I_Slope_EF_FG_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register	 0x1934, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_FG_ST8_BS	31
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_FG_ST8_BS	24
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_FG_ST8_BS	16
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_EF_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_EF_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_EF_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_FG_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_FG_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_FG_ST8_BS	8
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_EF_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_EF_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_EF_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_FG_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_FG_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_FG_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_EF_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_EF_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_EF_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_FG_ST8_BS	 0x1934, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_FG_ST8_BS	 0x1934, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_FG_ST8_BS	 0x1934, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SGN_SLIM_EF_ST8_BS	 0x1934, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SFT_SLIM_EF_ST8_BS	 0x1934, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_sat_limiter_Register_I_SLP_SLIM_EF_ST8_BS	 0x1934, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Slope_GH_for_sat_limiter_Register	0x1938 /* SCC_I_Slope_GH_for_sat_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_sat_limiter_Register	 0x1938, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_GH_for_sat_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SGN_SLIM_GH_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SFT_SLIM_GH_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SLIM_GH_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_GH_for_sat_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SGN_SLIM_GH_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SFT_SLIM_GH_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SLIM_GH_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_GH_for_sat_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SGN_SLIM_GH_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SFT_SLIM_GH_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SLIM_GH_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_GH_for_sat_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SGN_SLIM_GH_ST8_BS	 0x1938, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SFT_SLIM_GH_ST8_BS	 0x1938, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_sat_limiter_Register_I_SLP_SLIM_GH_ST8_BS	 0x1938, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register	0x193c /* SCC_I_Sat_limit_for_sat_limiter_AB_Register */ 
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register	 0x193c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register */
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register */
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_B_ST8_BS	8
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_A_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_B_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_A_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_B_ST8_BS	 0x193c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_AB_Register_I_SLIM_A_ST8_BS	 0x193c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register	0x1940 /* SCC_I_Sat_limit_for_sat_limiter_CD_Register */ 
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register	 0x1940, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register */
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register */
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_D_ST8_BS	0
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_C_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_D_ST8_BS	0x00000000 /*  */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_C_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_D_ST8_BS	 0x1940, 16, 0, 0x00000000
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_CD_Register_I_SLIM_C_ST8_BS	 0x1940, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register	0x1944 /* SCC_I_Sat_limit_for_sat_limiter_EF_Register */ 
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register	 0x1944, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register */
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register */
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_F_ST8_BS	8
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_E_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_F_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_E_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_F_ST8_BS	 0x1944, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_EF_Register_I_SLIM_E_ST8_BS	 0x1944, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register	0x1948 /* SCC_I_Sat_limit_for_sat_limiter_GH_Register */ 
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register	 0x1948, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register */
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register */
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_H_ST8_BS	8
	#define BWID_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_G_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_H_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_G_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_H_ST8_BS	 0x1948, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Sat_limit_for_sat_limiter_GH_Register_I_SLIM_G_ST8_BS	 0x1948, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register	0x194c /* SCC_Saturation_thresh_AB_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register	 0x194c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_B_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_A_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_B_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_A_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_B_ST8_BS	 0x194c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_AB_for_INT_limiter_Register_STH_ILIM_A_ST8_BS	 0x194c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register	0x1950 /* SCC_Saturation_thresh_CD_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register	 0x1950, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_D_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_D_ST8_BS	 0x1950, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_CD_for_INT_limiter_Register_STH_ILIM_C_ST8_BS	 0x1950, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register	0x1954 /* SCC_Saturation_thresh_EF_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register	 0x1954, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_F_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_F_ST8_BS	 0x1954, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_EF_for_INT_limiter_Register_STH_ILIM_E_ST8_BS	 0x1954, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register	0x1958 /* SCC_Saturation_thresh_GH_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register	 0x1958, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_H_ST8_BS	12
	#define BWID_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_H_ST8_BS	 0x1958, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Saturation_thresh_GH_for_INT_limiter_Register_STH_ILIM_G_ST8_BS	 0x1958, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register	0x195c /* SCC_Saturation_slope_AB_BC_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register	 0x195c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_BC_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_BC_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_BC_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_AB_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_AB_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_AB_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_BC_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_BC_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_BC_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_AB_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_AB_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_AB_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_BC_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_BC_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_BC_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_AB_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_AB_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_AB_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_BC_ST8_BS	 0x195c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_BC_ST8_BS	 0x195c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_BC_ST8_BS	 0x195c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SGN_ILIM_AB_ST8_BS	 0x195c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_SFT_ILIM_AB_ST8_BS	 0x195c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_AB_BC_for_INT_limiter_Register_S_SLP_ILIM_AB_ST8_BS	 0x195c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register	0x1960 /* SCC_Saturation_slope_CD_DE_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register	 0x1960, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_DE_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_DE_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_DE_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_CD_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_CD_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_CD_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_DE_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_DE_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_DE_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_CD_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_CD_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_CD_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_DE_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_DE_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_DE_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_CD_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_CD_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_CD_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_DE_ST8_BS	 0x1960, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_DE_ST8_BS	 0x1960, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_DE_ST8_BS	 0x1960, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SGN_ILIM_CD_ST8_BS	 0x1960, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_SFT_ILIM_CD_ST8_BS	 0x1960, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_CD_DE_for_INT_limiter_Register_S_SLP_ILIM_CD_ST8_BS	 0x1960, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register	0x1964 /* SCC_Saturation_slope_EF_FG_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register	 0x1964, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_FG_ST8_BS	31
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_FG_ST8_BS	24
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_FG_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_EF_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_EF_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_EF_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_FG_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_FG_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_FG_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_EF_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_EF_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_EF_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_FG_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_FG_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_FG_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_EF_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_EF_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_EF_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_FG_ST8_BS	 0x1964, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_FG_ST8_BS	 0x1964, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_FG_ST8_BS	 0x1964, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SGN_ILIM_EF_ST8_BS	 0x1964, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_SFT_ILIM_EF_ST8_BS	 0x1964, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_EF_FG_for_INT_limiter_Register_S_SLP_ILIM_EF_ST8_BS	 0x1964, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register	0x1968 /* SCC_Saturation_slope_GH_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register	 0x1968, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SGN_ILIM_GH_ST8_BS	15
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SFT_ILIM_GH_ST8_BS	8
	#define BLSB_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_ILIM_GH_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SGN_ILIM_GH_ST8_BS	1
	#define BWID_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SFT_ILIM_GH_ST8_BS	4
	#define BWID_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_ILIM_GH_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SGN_ILIM_GH_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SFT_ILIM_GH_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_ILIM_GH_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SGN_ILIM_GH_ST8_BS	 0x1968, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_SFT_ILIM_GH_ST8_BS	 0x1968, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_Saturation_slope_GH_for_INT_limiter_Register_S_SLP_ILIM_GH_ST8_BS	 0x1968, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register	0x196c /* SCC_Saturation_lim_for_INT_limiter_AB_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register	 0x196c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register */
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register */
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_B_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_A_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_B_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_A_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_B_ST8_BS	 0x196c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_AB_Register_S_ILIM_A_ST8_BS	 0x196c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register	0x1970 /* SCC_Saturation_lim_for_INT_limiter_CD_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register	 0x1970, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register */
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register */
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_D_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_C_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_D_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_C_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_D_ST8_BS	 0x1970, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_CD_Register_S_ILIM_C_ST8_BS	 0x1970, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register	0x1974 /* SCC_Saturation_lim_for_INT_limiter_EF_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register	 0x1974, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register */
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register */
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_F_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_E_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_F_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_E_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_F_ST8_BS	 0x1974, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_EF_Register_S_ILIM_E_ST8_BS	 0x1974, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register	0x1978 /* SCC_Saturation_lim_for_INT_limiter_GH_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register	 0x1978, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register */
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register */
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_H_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_G_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_H_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_G_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_H_ST8_BS	 0x1978, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_lim_for_INT_limiter_GH_Register_S_ILIM_G_ST8_BS	 0x1978, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register	0x197c /* SCC_Intensity_thresh_AB_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register	 0x197c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_B_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_A_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_B_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_A_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_B_ST8_BS	 0x197c, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_AB_for_INT_limiter_Register_ITH_ILIM_A_ST8_BS	 0x197c, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register	0x1980 /* SCC_Intensity_thresh_CD_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register	 0x1980, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_D_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_C_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_D_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_C_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_D_ST8_BS	 0x1980, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_CD_for_INT_limiter_Register_ITH_ILIM_C_ST8_BS	 0x1980, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register	0x1984 /* SCC_Intensity_thresh_EF_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register	 0x1984, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_F_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_E_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_F_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_E_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_F_ST8_BS	 0x1984, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_EF_for_INT_limiter_Register_ITH_ILIM_E_ST8_BS	 0x1984, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register	0x1988 /* SCC_Intensity_thresh_GH_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register	 0x1988, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register */
	#define BWID_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_H_ST8_BS	12
	#define BWID_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_G_ST8_BS	12
	/* Register Bit MASKS for DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_H_ST8_BS	0x0fff0000 /*  */
	#define BMSK_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_G_ST8_BS	0x00000fff /*  */
	/* Register BITFIELD for DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_H_ST8_BS	 0x1988, 16, 12, 0x0fff0000
	#define BITFIELD_DPE_SCC_Intensity_thresh_GH_for_INT_limiter_Register_ITH_ILIM_G_ST8_BS	 0x1988, 0, 12, 0x00000fff
#define ROFF_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register	0x198c /* SCC_I_Slope_AB_BC_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register	 0x198c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_BC_ST8_BS	31
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_BC_ST8_BS	24
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_BC_ST8_BS	16
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_AB_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_AB_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_AB_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_BC_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_BC_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_BC_ST8_BS	8
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_AB_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_AB_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_AB_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_BC_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_BC_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_BC_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_AB_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_AB_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_AB_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_BC_ST8_BS	 0x198c, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_BC_ST8_BS	 0x198c, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_BC_ST8_BS	 0x198c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SGN_ILIM_AB_ST8_BS	 0x198c, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_SFT_ILIM_AB_ST8_BS	 0x198c, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_AB_BC_for_INT_limiter_Register_I_SLP_ILIM_AB_ST8_BS	 0x198c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register	0x1990 /* SCC_I_Slope_CD_DE_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register	 0x1990, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_DE_ST8_BS	31
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_DE_ST8_BS	24
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_DE_ST8_BS	16
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_CD_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_CD_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_CD_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_DE_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_DE_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_DE_ST8_BS	8
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_CD_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_CD_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_CD_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_DE_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_DE_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_DE_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_CD_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_CD_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_CD_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_DE_ST8_BS	 0x1990, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_DE_ST8_BS	 0x1990, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_DE_ST8_BS	 0x1990, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SGN_ILIM_CD_ST8_BS	 0x1990, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_SFT_ILIM_CD_ST8_BS	 0x1990, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_CD_DE_for_INT_limiter_Register_I_SLP_ILIM_CD_ST8_BS	 0x1990, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register	0x1994 /* SCC_I_Slope_EF_FG_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register	 0x1994, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_FG_ST8_BS	31
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_FG_ST8_BS	24
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_FG_ST8_BS	16
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_EF_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_EF_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_EF_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_FG_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_FG_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_FG_ST8_BS	8
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_EF_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_EF_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_EF_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_FG_ST8_BS	(1<<31) /* == 0x80000000:  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_FG_ST8_BS	0x0f000000 /*  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_FG_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_EF_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_EF_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_EF_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_FG_ST8_BS	 0x1994, 31, 1, 0x80000000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_FG_ST8_BS	 0x1994, 24, 4, 0x0f000000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_FG_ST8_BS	 0x1994, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SGN_ILIM_EF_ST8_BS	 0x1994, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_SFT_ILIM_EF_ST8_BS	 0x1994, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_EF_FG_for_INT_limiter_Register_I_SLP_ILIM_EF_ST8_BS	 0x1994, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_I_Slope_GH_for_INT_limiter_Register	0x1998 /* SCC_I_Slope_GH_for_INT_limiter_Register */ 
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_INT_limiter_Register	 0x1998, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_I_Slope_GH_for_INT_limiter_Register */
	#define BLSB_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SGN_ILIM_GH_ST8_BS	15
	#define BLSB_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SFT_ILIM_GH_ST8_BS	8
	#define BLSB_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_ILIM_GH_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_I_Slope_GH_for_INT_limiter_Register */
	#define BWID_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SGN_ILIM_GH_ST8_BS	1
	#define BWID_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SFT_ILIM_GH_ST8_BS	4
	#define BWID_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_ILIM_GH_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_I_Slope_GH_for_INT_limiter_Register */
	#define BMSK_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SGN_ILIM_GH_ST8_BS	(1<<15) /* == 0x00008000:  */
	#define BMSK_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SFT_ILIM_GH_ST8_BS	0x00000f00 /*  */
	#define BMSK_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_ILIM_GH_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_I_Slope_GH_for_INT_limiter_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SGN_ILIM_GH_ST8_BS	 0x1998, 15, 1, 0x00008000
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_SFT_ILIM_GH_ST8_BS	 0x1998, 8, 4, 0x00000f00
	#define BITFIELD_DPE_SCC_I_Slope_GH_for_INT_limiter_Register_I_SLP_ILIM_GH_ST8_BS	 0x1998, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register	0x199c /* SCC_Saturation_limit_for_INT_limiter_AB_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register	 0x199c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_B_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_A_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_B_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_A_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_B_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_A_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_B_ST8_BS	 0x199c, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_AB_Register_I_ILIM_A_ST8_BS	 0x199c, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register	0x19a0 /* SCC_Saturation_limit_for_INT_limiter_CD_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register	 0x19a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_D_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_C_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_D_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_C_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_D_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_C_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_D_ST8_BS	 0x19a0, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_CD_Register_I_ILIM_C_ST8_BS	 0x19a0, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register	0x19a4 /* SCC_Saturation_limit_for_INT_limiter_EF_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register	 0x19a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_F_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_E_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_F_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_E_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_F_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_E_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_F_ST8_BS	 0x19a4, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_EF_Register_I_ILIM_E_ST8_BS	 0x19a4, 0, 8, 0x000000ff
#define ROFF_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register	0x19a8 /* SCC_Saturation_limit_for_INT_limiter_GH_Register */ 
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register	 0x19a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register */
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_H_ST8_BS	16
	#define BLSB_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_G_ST8_BS	0
	/* Register Bit Widths for DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register */
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_H_ST8_BS	8
	#define BWID_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_G_ST8_BS	8
	/* Register Bit MASKS for DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_H_ST8_BS	0x00ff0000 /*  */
	#define BMSK_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_G_ST8_BS	0x000000ff /*  */
	/* Register BITFIELD for DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_H_ST8_BS	 0x19a8, 16, 8, 0x00ff0000
	#define BITFIELD_DPE_SCC_Saturation_limit_for_INT_limiter_GH_Register_I_ILIM_G_ST8_BS	 0x19a8, 0, 8, 0x000000ff
#define ROFF_DPE_SHRP_Stride_Height_Register	0x4000 /* SHRP_Stride_Height_Register */ 
	#define BITFIELD_DPE_SHRP_Stride_Height_Register	 0x4000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_Stride_Height_Register */
	#define BLSB_DPE_SHRP_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_SHRP_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_SHRP_Stride_Height_Register */
	#define BWID_DPE_SHRP_Stride_Height_Register_num_strides	4
	#define BWID_DPE_SHRP_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_SHRP_Stride_Height_Register */
	#define BMSK_DPE_SHRP_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_SHRP_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_SHRP_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_Stride_Height_Register_num_strides	 0x4000, 12, 4, 0x0000f000
	#define BITFIELD_DPE_SHRP_Stride_Height_Register_stride_h	 0x4000, 0, 11, 0x000007ff
#define ROFF_DPE_SHRP_Stride_Width_Register	0x4004 /* SHRP_Stride_Width_Register */ 
	#define BITFIELD_DPE_SHRP_Stride_Width_Register	 0x4004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_Stride_Width_Register */
	#define BLSB_DPE_SHRP_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_SHRP_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_SHRP_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_SHRP_Stride_Width_Register_RM	6
	#define BLSB_DPE_SHRP_Stride_Width_Register_LM	5
	#define BLSB_DPE_SHRP_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_SHRP_Stride_Width_Register */
	#define BWID_DPE_SHRP_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_SHRP_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_SHRP_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_SHRP_Stride_Width_Register_RM	1
	#define BWID_DPE_SHRP_Stride_Width_Register_LM	1
	#define BWID_DPE_SHRP_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_SHRP_Stride_Width_Register */
	#define BMSK_DPE_SHRP_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_SHRP_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_SHRP_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_SHRP_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_SHRP_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_SHRP_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_SHRP_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_Stride_Width_Register_next_rd_offset_x	 0x4004, 27, 5, 0xf8000000
	#define BITFIELD_DPE_SHRP_Stride_Width_Register_pix_coord_x	 0x4004, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_SHRP_Stride_Width_Register_out_stride_w	 0x4004, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_SHRP_Stride_Width_Register_RM	 0x4004, 6, 1, 0x00000040
	#define BITFIELD_DPE_SHRP_Stride_Width_Register_LM	 0x4004, 5, 1, 0x00000020
	#define BITFIELD_DPE_SHRP_Stride_Width_Register_in_stride_off	 0x4004, 0, 5, 0x0000001f
#define ROFF_DPE_SHRP_Control_Register	0x4008 /* SHRP_Control_Register */ 
	#define BITFIELD_DPE_SHRP_Control_Register	 0x4008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_Control_Register */
	#define BLSB_DPE_SHRP_Control_Register_sharpness_bypass	0
	/* Register Bit Widths for DPE_SHRP_Control_Register */
	#define BWID_DPE_SHRP_Control_Register_sharpness_bypass	1
	/* Register Bit MASKS for DPE_SHRP_Control_Register */
	#define BMSK_DPE_SHRP_Control_Register_sharpness_bypass	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_SHRP_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_Control_Register_sharpness_bypass	 0x4008, 0, 1, 0x00000001
#define ROFF_DPE_SHRP_H0_Coeff_01_Register	0x4020 /* SHRP_H0_Coeff_01_Register */ 
	#define BITFIELD_DPE_SHRP_H0_Coeff_01_Register	 0x4020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H0_Coeff_01_Register */
	#define BLSB_DPE_SHRP_H0_Coeff_01_Register_H0Coeff1	16
	#define BLSB_DPE_SHRP_H0_Coeff_01_Register_H0Coeff0	0
	/* Register Bit Widths for DPE_SHRP_H0_Coeff_01_Register */
	#define BWID_DPE_SHRP_H0_Coeff_01_Register_H0Coeff1	13
	#define BWID_DPE_SHRP_H0_Coeff_01_Register_H0Coeff0	13
	/* Register Bit MASKS for DPE_SHRP_H0_Coeff_01_Register */
	#define BMSK_DPE_SHRP_H0_Coeff_01_Register_H0Coeff1	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H0_Coeff_01_Register_H0Coeff0	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H0_Coeff_01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H0_Coeff_01_Register_H0Coeff1	 0x4020, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H0_Coeff_01_Register_H0Coeff0	 0x4020, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H0_Coeff_23_Register	0x4024 /* SHRP_H0_Coeff_23_Register */ 
	#define BITFIELD_DPE_SHRP_H0_Coeff_23_Register	 0x4024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H0_Coeff_23_Register */
	#define BLSB_DPE_SHRP_H0_Coeff_23_Register_H0Coeff3	16
	#define BLSB_DPE_SHRP_H0_Coeff_23_Register_H0Coeff2	0
	/* Register Bit Widths for DPE_SHRP_H0_Coeff_23_Register */
	#define BWID_DPE_SHRP_H0_Coeff_23_Register_H0Coeff3	13
	#define BWID_DPE_SHRP_H0_Coeff_23_Register_H0Coeff2	13
	/* Register Bit MASKS for DPE_SHRP_H0_Coeff_23_Register */
	#define BMSK_DPE_SHRP_H0_Coeff_23_Register_H0Coeff3	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H0_Coeff_23_Register_H0Coeff2	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H0_Coeff_23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H0_Coeff_23_Register_H0Coeff3	 0x4024, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H0_Coeff_23_Register_H0Coeff2	 0x4024, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H0_Coeff_45_Register	0x4028 /* SHRP_H0_Coeff_45_Register */ 
	#define BITFIELD_DPE_SHRP_H0_Coeff_45_Register	 0x4028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H0_Coeff_45_Register */
	#define BLSB_DPE_SHRP_H0_Coeff_45_Register_H0Coeff5	16
	#define BLSB_DPE_SHRP_H0_Coeff_45_Register_H0Coeff4	0
	/* Register Bit Widths for DPE_SHRP_H0_Coeff_45_Register */
	#define BWID_DPE_SHRP_H0_Coeff_45_Register_H0Coeff5	13
	#define BWID_DPE_SHRP_H0_Coeff_45_Register_H0Coeff4	13
	/* Register Bit MASKS for DPE_SHRP_H0_Coeff_45_Register */
	#define BMSK_DPE_SHRP_H0_Coeff_45_Register_H0Coeff5	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H0_Coeff_45_Register_H0Coeff4	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H0_Coeff_45_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H0_Coeff_45_Register_H0Coeff5	 0x4028, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H0_Coeff_45_Register_H0Coeff4	 0x4028, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H1_Coeff_01_Register	0x402c /* SHRP_H1_Coeff_01_Register */ 
	#define BITFIELD_DPE_SHRP_H1_Coeff_01_Register	 0x402c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H1_Coeff_01_Register */
	#define BLSB_DPE_SHRP_H1_Coeff_01_Register_H1Coeff1	16
	#define BLSB_DPE_SHRP_H1_Coeff_01_Register_H1Coeff0	0
	/* Register Bit Widths for DPE_SHRP_H1_Coeff_01_Register */
	#define BWID_DPE_SHRP_H1_Coeff_01_Register_H1Coeff1	13
	#define BWID_DPE_SHRP_H1_Coeff_01_Register_H1Coeff0	13
	/* Register Bit MASKS for DPE_SHRP_H1_Coeff_01_Register */
	#define BMSK_DPE_SHRP_H1_Coeff_01_Register_H1Coeff1	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H1_Coeff_01_Register_H1Coeff0	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H1_Coeff_01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H1_Coeff_01_Register_H1Coeff1	 0x402c, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H1_Coeff_01_Register_H1Coeff0	 0x402c, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H1_Coeff_23_Register	0x4030 /* SHRP_H1_Coeff_23_Register */ 
	#define BITFIELD_DPE_SHRP_H1_Coeff_23_Register	 0x4030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H1_Coeff_23_Register */
	#define BLSB_DPE_SHRP_H1_Coeff_23_Register_H1Coeff3	16
	#define BLSB_DPE_SHRP_H1_Coeff_23_Register_H1Coeff2	0
	/* Register Bit Widths for DPE_SHRP_H1_Coeff_23_Register */
	#define BWID_DPE_SHRP_H1_Coeff_23_Register_H1Coeff3	13
	#define BWID_DPE_SHRP_H1_Coeff_23_Register_H1Coeff2	13
	/* Register Bit MASKS for DPE_SHRP_H1_Coeff_23_Register */
	#define BMSK_DPE_SHRP_H1_Coeff_23_Register_H1Coeff3	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H1_Coeff_23_Register_H1Coeff2	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H1_Coeff_23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H1_Coeff_23_Register_H1Coeff3	 0x4030, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H1_Coeff_23_Register_H1Coeff2	 0x4030, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H1_Coeff_45_Register	0x4034 /* SHRP_H1_Coeff_45_Register */ 
	#define BITFIELD_DPE_SHRP_H1_Coeff_45_Register	 0x4034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H1_Coeff_45_Register */
	#define BLSB_DPE_SHRP_H1_Coeff_45_Register_H1Coeff5	16
	#define BLSB_DPE_SHRP_H1_Coeff_45_Register_H1Coeff4	0
	/* Register Bit Widths for DPE_SHRP_H1_Coeff_45_Register */
	#define BWID_DPE_SHRP_H1_Coeff_45_Register_H1Coeff5	13
	#define BWID_DPE_SHRP_H1_Coeff_45_Register_H1Coeff4	13
	/* Register Bit MASKS for DPE_SHRP_H1_Coeff_45_Register */
	#define BMSK_DPE_SHRP_H1_Coeff_45_Register_H1Coeff5	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H1_Coeff_45_Register_H1Coeff4	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H1_Coeff_45_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H1_Coeff_45_Register_H1Coeff5	 0x4034, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H1_Coeff_45_Register_H1Coeff4	 0x4034, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V0_Coeff_01_Register	0x4038 /* SHRP_V0_Coeff_01_Register */ 
	#define BITFIELD_DPE_SHRP_V0_Coeff_01_Register	 0x4038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V0_Coeff_01_Register */
	#define BLSB_DPE_SHRP_V0_Coeff_01_Register_V0Coeff1	16
	#define BLSB_DPE_SHRP_V0_Coeff_01_Register_V0Coeff0	0
	/* Register Bit Widths for DPE_SHRP_V0_Coeff_01_Register */
	#define BWID_DPE_SHRP_V0_Coeff_01_Register_V0Coeff1	13
	#define BWID_DPE_SHRP_V0_Coeff_01_Register_V0Coeff0	13
	/* Register Bit MASKS for DPE_SHRP_V0_Coeff_01_Register */
	#define BMSK_DPE_SHRP_V0_Coeff_01_Register_V0Coeff1	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V0_Coeff_01_Register_V0Coeff0	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V0_Coeff_01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V0_Coeff_01_Register_V0Coeff1	 0x4038, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V0_Coeff_01_Register_V0Coeff0	 0x4038, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V0_Coeff_23_Register	0x403c /* SHRP_V0_Coeff_23_Register */ 
	#define BITFIELD_DPE_SHRP_V0_Coeff_23_Register	 0x403c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V0_Coeff_23_Register */
	#define BLSB_DPE_SHRP_V0_Coeff_23_Register_V0Coeff3	16
	#define BLSB_DPE_SHRP_V0_Coeff_23_Register_V0Coeff2	0
	/* Register Bit Widths for DPE_SHRP_V0_Coeff_23_Register */
	#define BWID_DPE_SHRP_V0_Coeff_23_Register_V0Coeff3	13
	#define BWID_DPE_SHRP_V0_Coeff_23_Register_V0Coeff2	13
	/* Register Bit MASKS for DPE_SHRP_V0_Coeff_23_Register */
	#define BMSK_DPE_SHRP_V0_Coeff_23_Register_V0Coeff3	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V0_Coeff_23_Register_V0Coeff2	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V0_Coeff_23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V0_Coeff_23_Register_V0Coeff3	 0x403c, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V0_Coeff_23_Register_V0Coeff2	 0x403c, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V0_Coeff_4_Register	0x4040 /* SHRP_V0_Coeff_4_Register */ 
	#define BITFIELD_DPE_SHRP_V0_Coeff_4_Register	 0x4040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V0_Coeff_4_Register */
	#define BLSB_DPE_SHRP_V0_Coeff_4_Register_V0Coeff4	0
	/* Register Bit Widths for DPE_SHRP_V0_Coeff_4_Register */
	#define BWID_DPE_SHRP_V0_Coeff_4_Register_V0Coeff4	13
	/* Register Bit MASKS for DPE_SHRP_V0_Coeff_4_Register */
	#define BMSK_DPE_SHRP_V0_Coeff_4_Register_V0Coeff4	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V0_Coeff_4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V0_Coeff_4_Register_V0Coeff4	 0x4040, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V1_Coeff_01_Register	0x4044 /* SHRP_V1_Coeff_01_Register */ 
	#define BITFIELD_DPE_SHRP_V1_Coeff_01_Register	 0x4044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V1_Coeff_01_Register */
	#define BLSB_DPE_SHRP_V1_Coeff_01_Register_V1Coeff1	16
	#define BLSB_DPE_SHRP_V1_Coeff_01_Register_V1Coeff0	0
	/* Register Bit Widths for DPE_SHRP_V1_Coeff_01_Register */
	#define BWID_DPE_SHRP_V1_Coeff_01_Register_V1Coeff1	13
	#define BWID_DPE_SHRP_V1_Coeff_01_Register_V1Coeff0	13
	/* Register Bit MASKS for DPE_SHRP_V1_Coeff_01_Register */
	#define BMSK_DPE_SHRP_V1_Coeff_01_Register_V1Coeff1	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V1_Coeff_01_Register_V1Coeff0	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V1_Coeff_01_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V1_Coeff_01_Register_V1Coeff1	 0x4044, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V1_Coeff_01_Register_V1Coeff0	 0x4044, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V1_Coeff_23_Register	0x4048 /* SHRP_V1_Coeff_23_Register */ 
	#define BITFIELD_DPE_SHRP_V1_Coeff_23_Register	 0x4048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V1_Coeff_23_Register */
	#define BLSB_DPE_SHRP_V1_Coeff_23_Register_V1Coeff3	16
	#define BLSB_DPE_SHRP_V1_Coeff_23_Register_V1Coeff2	0
	/* Register Bit Widths for DPE_SHRP_V1_Coeff_23_Register */
	#define BWID_DPE_SHRP_V1_Coeff_23_Register_V1Coeff3	13
	#define BWID_DPE_SHRP_V1_Coeff_23_Register_V1Coeff2	13
	/* Register Bit MASKS for DPE_SHRP_V1_Coeff_23_Register */
	#define BMSK_DPE_SHRP_V1_Coeff_23_Register_V1Coeff3	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V1_Coeff_23_Register_V1Coeff2	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V1_Coeff_23_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V1_Coeff_23_Register_V1Coeff3	 0x4048, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V1_Coeff_23_Register_V1Coeff2	 0x4048, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V1_Coeff_4_Register	0x404c /* SHRP_V1_Coeff_4_Register */ 
	#define BITFIELD_DPE_SHRP_V1_Coeff_4_Register	 0x404c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V1_Coeff_4_Register */
	#define BLSB_DPE_SHRP_V1_Coeff_4_Register_V1Coeff4	0
	/* Register Bit Widths for DPE_SHRP_V1_Coeff_4_Register */
	#define BWID_DPE_SHRP_V1_Coeff_4_Register_V1Coeff4	13
	/* Register Bit MASKS for DPE_SHRP_V1_Coeff_4_Register */
	#define BMSK_DPE_SHRP_V1_Coeff_4_Register_V1Coeff4	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V1_Coeff_4_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V1_Coeff_4_Register_V1Coeff4	 0x404c, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H0_H1_Gain_Register	0x4050 /* SHRP_H0_H1_GAIN_Register */ 
	#define BITFIELD_DPE_SHRP_H0_H1_Gain_Register	 0x4050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H0_H1_Gain_Register */
	#define BLSB_DPE_SHRP_H0_H1_Gain_Register_H1Gain	16
	#define BLSB_DPE_SHRP_H0_H1_Gain_Register_H0Gain	0
	/* Register Bit Widths for DPE_SHRP_H0_H1_Gain_Register */
	#define BWID_DPE_SHRP_H0_H1_Gain_Register_H1Gain	13
	#define BWID_DPE_SHRP_H0_H1_Gain_Register_H0Gain	13
	/* Register Bit MASKS for DPE_SHRP_H0_H1_Gain_Register */
	#define BMSK_DPE_SHRP_H0_H1_Gain_Register_H1Gain	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H0_H1_Gain_Register_H0Gain	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H0_H1_Gain_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H0_H1_Gain_Register_H1Gain	 0x4050, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H0_H1_Gain_Register_H0Gain	 0x4050, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H0_H1_Core_Register	0x4054 /* SHRP_H0_H1_Core_Register */ 
	#define BITFIELD_DPE_SHRP_H0_H1_Core_Register	 0x4054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H0_H1_Core_Register */
	#define BLSB_DPE_SHRP_H0_H1_Core_Register_H1Core	16
	#define BLSB_DPE_SHRP_H0_H1_Core_Register_H0Core	0
	/* Register Bit Widths for DPE_SHRP_H0_H1_Core_Register */
	#define BWID_DPE_SHRP_H0_H1_Core_Register_H1Core	13
	#define BWID_DPE_SHRP_H0_H1_Core_Register_H0Core	13
	/* Register Bit MASKS for DPE_SHRP_H0_H1_Core_Register */
	#define BMSK_DPE_SHRP_H0_H1_Core_Register_H1Core	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H0_H1_Core_Register_H0Core	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H0_H1_Core_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H0_H1_Core_Register_H1Core	 0x4054, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H0_H1_Core_Register_H0Core	 0x4054, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_H0_H1_Clip_Register	0x4058 /* SHRP_H0_H1_Clip_Register */ 
	#define BITFIELD_DPE_SHRP_H0_H1_Clip_Register	 0x4058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_H0_H1_Clip_Register */
	#define BLSB_DPE_SHRP_H0_H1_Clip_Register_H1Clip	16
	#define BLSB_DPE_SHRP_H0_H1_Clip_Register_H0Clip	0
	/* Register Bit Widths for DPE_SHRP_H0_H1_Clip_Register */
	#define BWID_DPE_SHRP_H0_H1_Clip_Register_H1Clip	13
	#define BWID_DPE_SHRP_H0_H1_Clip_Register_H0Clip	13
	/* Register Bit MASKS for DPE_SHRP_H0_H1_Clip_Register */
	#define BMSK_DPE_SHRP_H0_H1_Clip_Register_H1Clip	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_H0_H1_Clip_Register_H0Clip	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_H0_H1_Clip_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_H0_H1_Clip_Register_H1Clip	 0x4058, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_H0_H1_Clip_Register_H0Clip	 0x4058, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V0_V1_Gain_Register	0x405c /* SHRP_V0_V1_GAIN_Register */ 
	#define BITFIELD_DPE_SHRP_V0_V1_Gain_Register	 0x405c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V0_V1_Gain_Register */
	#define BLSB_DPE_SHRP_V0_V1_Gain_Register_V1Gain	16
	#define BLSB_DPE_SHRP_V0_V1_Gain_Register_V0Gain	0
	/* Register Bit Widths for DPE_SHRP_V0_V1_Gain_Register */
	#define BWID_DPE_SHRP_V0_V1_Gain_Register_V1Gain	13
	#define BWID_DPE_SHRP_V0_V1_Gain_Register_V0Gain	13
	/* Register Bit MASKS for DPE_SHRP_V0_V1_Gain_Register */
	#define BMSK_DPE_SHRP_V0_V1_Gain_Register_V1Gain	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V0_V1_Gain_Register_V0Gain	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V0_V1_Gain_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V0_V1_Gain_Register_V1Gain	 0x405c, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V0_V1_Gain_Register_V0Gain	 0x405c, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V0_V1_Core_Register	0x4060 /* SHRP_V0_V1_Core_Register */ 
	#define BITFIELD_DPE_SHRP_V0_V1_Core_Register	 0x4060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V0_V1_Core_Register */
	#define BLSB_DPE_SHRP_V0_V1_Core_Register_V1Core	16
	#define BLSB_DPE_SHRP_V0_V1_Core_Register_V0Core	0
	/* Register Bit Widths for DPE_SHRP_V0_V1_Core_Register */
	#define BWID_DPE_SHRP_V0_V1_Core_Register_V1Core	13
	#define BWID_DPE_SHRP_V0_V1_Core_Register_V0Core	13
	/* Register Bit MASKS for DPE_SHRP_V0_V1_Core_Register */
	#define BMSK_DPE_SHRP_V0_V1_Core_Register_V1Core	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V0_V1_Core_Register_V0Core	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V0_V1_Core_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V0_V1_Core_Register_V1Core	 0x4060, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V0_V1_Core_Register_V0Core	 0x4060, 0, 13, 0x00001fff
#define ROFF_DPE_SHRP_V0_V1_Clip_Register	0x4064 /* SHRP_V0_V1_Clip_Register */ 
	#define BITFIELD_DPE_SHRP_V0_V1_Clip_Register	 0x4064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_SHRP_V0_V1_Clip_Register */
	#define BLSB_DPE_SHRP_V0_V1_Clip_Register_V1Clip	16
	#define BLSB_DPE_SHRP_V0_V1_Clip_Register_V0Clip	0
	/* Register Bit Widths for DPE_SHRP_V0_V1_Clip_Register */
	#define BWID_DPE_SHRP_V0_V1_Clip_Register_V1Clip	13
	#define BWID_DPE_SHRP_V0_V1_Clip_Register_V0Clip	13
	/* Register Bit MASKS for DPE_SHRP_V0_V1_Clip_Register */
	#define BMSK_DPE_SHRP_V0_V1_Clip_Register_V1Clip	0x1fff0000 /*  */
	#define BMSK_DPE_SHRP_V0_V1_Clip_Register_V0Clip	0x00001fff /*  */
	/* Register BITFIELD for DPE_SHRP_V0_V1_Clip_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_SHRP_V0_V1_Clip_Register_V1Clip	 0x4064, 16, 13, 0x1fff0000
	#define BITFIELD_DPE_SHRP_V0_V1_Clip_Register_V0Clip	 0x4064, 0, 13, 0x00001fff
#define ROFF_DPE_DI_0_Counter_Valid	0x6c04 /* DI_0_Counter_Valid */ 
	#define BITFIELD_DPE_DI_0_Counter_Valid	 0x6c04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_0_Counter_Valid */
	#define BLSB_DPE_DI_0_Counter_Valid_CNTR_VALID	0
	/* Register Bit Widths for DPE_DI_0_Counter_Valid */
	#define BWID_DPE_DI_0_Counter_Valid_CNTR_VALID	1
	/* Register Bit MASKS for DPE_DI_0_Counter_Valid */
	#define BMSK_DPE_DI_0_Counter_Valid_CNTR_VALID	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DI_0_Counter_Valid - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_0_Counter_Valid_CNTR_VALID	 0x6c04, 0, 1, 0x00000001
#define ROFF_DPE_DI_1_Counter_Valid	0x6c08 /* DI_1_Counter_Valid */ 
	#define BITFIELD_DPE_DI_1_Counter_Valid	 0x6c08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Counter_Valid */
	#define BLSB_DPE_DI_1_Counter_Valid_CNTR_VALID	0
	/* Register Bit Widths for DPE_DI_1_Counter_Valid */
	#define BWID_DPE_DI_1_Counter_Valid_CNTR_VALID	1
	/* Register Bit MASKS for DPE_DI_1_Counter_Valid */
	#define BMSK_DPE_DI_1_Counter_Valid_CNTR_VALID	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DI_1_Counter_Valid - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Counter_Valid_CNTR_VALID	 0x6c08, 0, 1, 0x00000001
#define ROFF_DPE_DI_1_FMD_TC_prev_count	0x6c0c /* DI_1_FMD_TC_prev_count */ 
	#define BITFIELD_DPE_DI_1_FMD_TC_prev_count	 0x6c0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_FMD_TC_prev_count */
	#define BLSB_DPE_DI_1_FMD_TC_prev_count_TCP_COUNTER	0
	/* Register Bit Widths for DPE_DI_1_FMD_TC_prev_count */
	#define BWID_DPE_DI_1_FMD_TC_prev_count_TCP_COUNTER	20
	/* Register Bit MASKS for DPE_DI_1_FMD_TC_prev_count */
	#define BMSK_DPE_DI_1_FMD_TC_prev_count_TCP_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_1_FMD_TC_prev_count - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_FMD_TC_prev_count_TCP_COUNTER	 0x6c0c, 0, 20, 0x000fffff
#define ROFF_DPE_DI_1_FMD_TC_next_count	0x6c10 /* DI_1_FMD_TC_next_count */ 
	#define BITFIELD_DPE_DI_1_FMD_TC_next_count	 0x6c10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_FMD_TC_next_count */
	#define BLSB_DPE_DI_1_FMD_TC_next_count_TCN_COUNTER	0
	/* Register Bit Widths for DPE_DI_1_FMD_TC_next_count */
	#define BWID_DPE_DI_1_FMD_TC_next_count_TCN_COUNTER	20
	/* Register Bit MASKS for DPE_DI_1_FMD_TC_next_count */
	#define BMSK_DPE_DI_1_FMD_TC_next_count_TCN_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_1_FMD_TC_next_count - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_FMD_TC_next_count_TCN_COUNTER	 0x6c10, 0, 20, 0x000fffff
#define ROFF_DPE_DI_1_FMD_FDC	0x6c14 /* DI_1_FMD_FDC */ 
	#define BITFIELD_DPE_DI_1_FMD_FDC	 0x6c14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_FMD_FDC */
	#define BLSB_DPE_DI_1_FMD_FDC_FD_COUNTER	0
	/* Register Bit Widths for DPE_DI_1_FMD_FDC */
	#define BWID_DPE_DI_1_FMD_FDC_FD_COUNTER	20
	/* Register Bit MASKS for DPE_DI_1_FMD_FDC */
	#define BMSK_DPE_DI_1_FMD_FDC_FD_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_1_FMD_FDC - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_FMD_FDC_FD_COUNTER	 0x6c14, 0, 20, 0x000fffff
#define ROFF_DPE_DI_1_TC_prev_Hist_0	0x6c1c /* DI_1_TC_prev_Hist_0 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_0	 0x6c1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_0 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_0_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_0 */
	#define BWID_DPE_DI_1_TC_prev_Hist_0_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_0 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_0_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_0_TCP_HIST_CNTR	 0x6c1c, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_1	0x6c20 /* DI_1_TC_prev_Hist_1 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_1	 0x6c20, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_1 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_1_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_1 */
	#define BWID_DPE_DI_1_TC_prev_Hist_1_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_1 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_1_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_1_TCP_HIST_CNTR	 0x6c20, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_2	0x6c24 /* DI_1_TC_prev_Hist_2 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_2	 0x6c24, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_2 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_2_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_2 */
	#define BWID_DPE_DI_1_TC_prev_Hist_2_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_2 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_2_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_2_TCP_HIST_CNTR	 0x6c24, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_3	0x6c28 /* DI_1_TC_prev_Hist_3 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_3	 0x6c28, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_3 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_3_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_3 */
	#define BWID_DPE_DI_1_TC_prev_Hist_3_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_3 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_3_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_3_TCP_HIST_CNTR	 0x6c28, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_4	0x6c2c /* DI_1_TC_prev_Hist_4 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_4	 0x6c2c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_4 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_4_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_4 */
	#define BWID_DPE_DI_1_TC_prev_Hist_4_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_4 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_4_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_4_TCP_HIST_CNTR	 0x6c2c, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_5	0x6c30 /* DI_1_TC_prev_Hist_5 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_5	 0x6c30, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_5 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_5_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_5 */
	#define BWID_DPE_DI_1_TC_prev_Hist_5_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_5 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_5_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_5_TCP_HIST_CNTR	 0x6c30, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_6	0x6c34 /* DI_1_TC_prev_Hist_6 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_6	 0x6c34, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_6 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_6_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_6 */
	#define BWID_DPE_DI_1_TC_prev_Hist_6_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_6 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_6_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_6 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_6_TCP_HIST_CNTR	 0x6c34, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_prev_Hist_7	0x6c38 /* DI_1_TC_prev_Hist_7 */ 
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_7	 0x6c38, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_prev_Hist_7 */
	#define BLSB_DPE_DI_1_TC_prev_Hist_7_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_prev_Hist_7 */
	#define BWID_DPE_DI_1_TC_prev_Hist_7_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_prev_Hist_7 */
	#define BMSK_DPE_DI_1_TC_prev_Hist_7_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_prev_Hist_7 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_prev_Hist_7_TCP_HIST_CNTR	 0x6c38, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_0	0x6c3c /* DI_1_TC_next_Hist_0 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_0	 0x6c3c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_0 */
	#define BLSB_DPE_DI_1_TC_next_Hist_0_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_0 */
	#define BWID_DPE_DI_1_TC_next_Hist_0_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_0 */
	#define BMSK_DPE_DI_1_TC_next_Hist_0_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_0_TCN_HIST_CNTR	 0x6c3c, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_1	0x6c40 /* DI_1_TC_next_Hist_1 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_1	 0x6c40, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_1 */
	#define BLSB_DPE_DI_1_TC_next_Hist_1_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_1 */
	#define BWID_DPE_DI_1_TC_next_Hist_1_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_1 */
	#define BMSK_DPE_DI_1_TC_next_Hist_1_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_1_TCN_HIST_CNTR	 0x6c40, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_2	0x6c44 /* DI_1_TC_next_Hist_2 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_2	 0x6c44, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_2 */
	#define BLSB_DPE_DI_1_TC_next_Hist_2_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_2 */
	#define BWID_DPE_DI_1_TC_next_Hist_2_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_2 */
	#define BMSK_DPE_DI_1_TC_next_Hist_2_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_2_TCN_HIST_CNTR	 0x6c44, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_3	0x6c48 /* DI_1_TC_next_Hist_3 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_3	 0x6c48, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_3 */
	#define BLSB_DPE_DI_1_TC_next_Hist_3_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_3 */
	#define BWID_DPE_DI_1_TC_next_Hist_3_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_3 */
	#define BMSK_DPE_DI_1_TC_next_Hist_3_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_3_TCN_HIST_CNTR	 0x6c48, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_4	0x6c4c /* DI_1_TC_next_Hist_4 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_4	 0x6c4c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_4 */
	#define BLSB_DPE_DI_1_TC_next_Hist_4_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_4 */
	#define BWID_DPE_DI_1_TC_next_Hist_4_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_4 */
	#define BMSK_DPE_DI_1_TC_next_Hist_4_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_4_TCN_HIST_CNTR	 0x6c4c, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_5	0x6c50 /* DI_1_TC_next_Hist_5 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_5	 0x6c50, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_5 */
	#define BLSB_DPE_DI_1_TC_next_Hist_5_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_5 */
	#define BWID_DPE_DI_1_TC_next_Hist_5_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_5 */
	#define BMSK_DPE_DI_1_TC_next_Hist_5_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_5_TCN_HIST_CNTR	 0x6c50, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_6	0x6c54 /* DI_1_TC_next_Hist_6 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_6	 0x6c54, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_6 */
	#define BLSB_DPE_DI_1_TC_next_Hist_6_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_6 */
	#define BWID_DPE_DI_1_TC_next_Hist_6_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_6 */
	#define BMSK_DPE_DI_1_TC_next_Hist_6_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_6 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_6_TCN_HIST_CNTR	 0x6c54, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_TC_next_Hist_7	0x6c58 /* DI_1_TC_next_Hist_7 */ 
	#define BITFIELD_DPE_DI_1_TC_next_Hist_7	 0x6c58, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_TC_next_Hist_7 */
	#define BLSB_DPE_DI_1_TC_next_Hist_7_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_TC_next_Hist_7 */
	#define BWID_DPE_DI_1_TC_next_Hist_7_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_TC_next_Hist_7 */
	#define BMSK_DPE_DI_1_TC_next_Hist_7_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_TC_next_Hist_7 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_TC_next_Hist_7_TCN_HIST_CNTR	 0x6c58, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_A_Hist_Counter_0	0x6c64 /* DI_1_Motion_A_Hist_Counter_0 */ 
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_0	 0x6c64, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_A_Hist_Counter_0 */
	#define BLSB_DPE_DI_1_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_A_Hist_Counter_0 */
	#define BWID_DPE_DI_1_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_A_Hist_Counter_0 */
	#define BMSK_DPE_DI_1_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_A_Hist_Counter_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	 0x6c64, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_A_Hist_Counter_1	0x6c68 /* DI_1_Motion_A_Hist_Counter_1 */ 
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_1	 0x6c68, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_A_Hist_Counter_1 */
	#define BLSB_DPE_DI_1_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_A_Hist_Counter_1 */
	#define BWID_DPE_DI_1_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_A_Hist_Counter_1 */
	#define BMSK_DPE_DI_1_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_A_Hist_Counter_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	 0x6c68, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_A_Hist_Counter_2	0x6c6c /* DI_1_Motion_A_Hist_Counter_2 */ 
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_2	 0x6c6c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_A_Hist_Counter_2 */
	#define BLSB_DPE_DI_1_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_A_Hist_Counter_2 */
	#define BWID_DPE_DI_1_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_A_Hist_Counter_2 */
	#define BMSK_DPE_DI_1_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_A_Hist_Counter_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	 0x6c6c, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_A_Hist_Counter_3	0x6c70 /* DI_1_Motion_A_Hist_Counter_3 */ 
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_3	 0x6c70, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_A_Hist_Counter_3 */
	#define BLSB_DPE_DI_1_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_A_Hist_Counter_3 */
	#define BWID_DPE_DI_1_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_A_Hist_Counter_3 */
	#define BMSK_DPE_DI_1_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_A_Hist_Counter_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	 0x6c70, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_B_Hist_Counter_0	0x6c74 /* DI_1_Motion_B_Hist_Counter_0 */ 
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_0	 0x6c74, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_B_Hist_Counter_0 */
	#define BLSB_DPE_DI_1_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_B_Hist_Counter_0 */
	#define BWID_DPE_DI_1_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_B_Hist_Counter_0 */
	#define BMSK_DPE_DI_1_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_B_Hist_Counter_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	 0x6c74, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_B_Hist_Counter_1	0x6c78 /* DI_1_Motion_B_Hist_Counter_1 */ 
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_1	 0x6c78, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_B_Hist_Counter_1 */
	#define BLSB_DPE_DI_1_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_B_Hist_Counter_1 */
	#define BWID_DPE_DI_1_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_B_Hist_Counter_1 */
	#define BMSK_DPE_DI_1_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_B_Hist_Counter_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	 0x6c78, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_B_Hist_Counter_2	0x6c7c /* DI_1_Motion_B_Hist_Counter_2 */ 
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_2	 0x6c7c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_B_Hist_Counter_2 */
	#define BLSB_DPE_DI_1_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_B_Hist_Counter_2 */
	#define BWID_DPE_DI_1_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_B_Hist_Counter_2 */
	#define BMSK_DPE_DI_1_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_B_Hist_Counter_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	 0x6c7c, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Motion_B_Hist_Counter_3	0x6c80 /* DI_1_Motion_B_Hist_Counter_3 */ 
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_3	 0x6c80, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Motion_B_Hist_Counter_3 */
	#define BLSB_DPE_DI_1_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_1_Motion_B_Hist_Counter_3 */
	#define BWID_DPE_DI_1_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_1_Motion_B_Hist_Counter_3 */
	#define BMSK_DPE_DI_1_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Motion_B_Hist_Counter_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	 0x6c80, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Noise_Estimation_Var_Noise_Count	0x6c84 /* DI_1_Noise_Estimation_Var_Noise_Count */ 
	#define BITFIELD_DPE_DI_1_Noise_Estimation_Var_Noise_Count	 0x6c84, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Noise_Estimation_Var_Noise_Count */
	#define BLSB_DPE_DI_1_Noise_Estimation_Var_Noise_Count_VarNoise_Count	0
	/* Register Bit Widths for DPE_DI_1_Noise_Estimation_Var_Noise_Count */
	#define BWID_DPE_DI_1_Noise_Estimation_Var_Noise_Count_VarNoise_Count	32
	/* Register Bit MASKS for DPE_DI_1_Noise_Estimation_Var_Noise_Count */
	#define BMSK_DPE_DI_1_Noise_Estimation_Var_Noise_Count_VarNoise_Count	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Noise_Estimation_Var_Noise_Count - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Noise_Estimation_Var_Noise_Count_VarNoise_Count	 0x6c84, 0, 32, 0x00000000
#define ROFF_DPE_DI_1_Noise_Estimation_Var_Noise_Level	0x6c88 /* DI_1_Noise_Estimation_Var_Noise_Level */ 
	#define BITFIELD_DPE_DI_1_Noise_Estimation_Var_Noise_Level	 0x6c88, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_1_Noise_Estimation_Var_Noise_Level */
	#define BLSB_DPE_DI_1_Noise_Estimation_Var_Noise_Level_VarNoise_Level	0
	/* Register Bit Widths for DPE_DI_1_Noise_Estimation_Var_Noise_Level */
	#define BWID_DPE_DI_1_Noise_Estimation_Var_Noise_Level_VarNoise_Level	32
	/* Register Bit MASKS for DPE_DI_1_Noise_Estimation_Var_Noise_Level */
	#define BMSK_DPE_DI_1_Noise_Estimation_Var_Noise_Level_VarNoise_Level	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_1_Noise_Estimation_Var_Noise_Level - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_1_Noise_Estimation_Var_Noise_Level_VarNoise_Level	 0x6c88, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Counter_Valid	0x6c98 /* DI_2_Counter_Valid */ 
	#define BITFIELD_DPE_DI_2_Counter_Valid	 0x6c98, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Counter_Valid */
	#define BLSB_DPE_DI_2_Counter_Valid_CNTR_VALID	0
	/* Register Bit Widths for DPE_DI_2_Counter_Valid */
	#define BWID_DPE_DI_2_Counter_Valid_CNTR_VALID	1
	/* Register Bit MASKS for DPE_DI_2_Counter_Valid */
	#define BMSK_DPE_DI_2_Counter_Valid_CNTR_VALID	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DI_2_Counter_Valid - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Counter_Valid_CNTR_VALID	 0x6c98, 0, 1, 0x00000001
#define ROFF_DPE_DI_2_FMD_TC_prev_count	0x6c9c /* DI_2_FMD_TC_prev_count */ 
	#define BITFIELD_DPE_DI_2_FMD_TC_prev_count	 0x6c9c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_FMD_TC_prev_count */
	#define BLSB_DPE_DI_2_FMD_TC_prev_count_TCP_COUNTER	0
	/* Register Bit Widths for DPE_DI_2_FMD_TC_prev_count */
	#define BWID_DPE_DI_2_FMD_TC_prev_count_TCP_COUNTER	20
	/* Register Bit MASKS for DPE_DI_2_FMD_TC_prev_count */
	#define BMSK_DPE_DI_2_FMD_TC_prev_count_TCP_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_2_FMD_TC_prev_count - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_FMD_TC_prev_count_TCP_COUNTER	 0x6c9c, 0, 20, 0x000fffff
#define ROFF_DPE_DI_2_FMD_TC_next_count	0x6ca0 /* DI_2_FMD_TC_next_count */ 
	#define BITFIELD_DPE_DI_2_FMD_TC_next_count	 0x6ca0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_FMD_TC_next_count */
	#define BLSB_DPE_DI_2_FMD_TC_next_count_TCN_COUNTER	0
	/* Register Bit Widths for DPE_DI_2_FMD_TC_next_count */
	#define BWID_DPE_DI_2_FMD_TC_next_count_TCN_COUNTER	20
	/* Register Bit MASKS for DPE_DI_2_FMD_TC_next_count */
	#define BMSK_DPE_DI_2_FMD_TC_next_count_TCN_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_2_FMD_TC_next_count - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_FMD_TC_next_count_TCN_COUNTER	 0x6ca0, 0, 20, 0x000fffff
#define ROFF_DPE_DI_2_FMD_FDC	0x6ca4 /* DI_2_FMD_FDC */ 
	#define BITFIELD_DPE_DI_2_FMD_FDC	 0x6ca4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_FMD_FDC */
	#define BLSB_DPE_DI_2_FMD_FDC_FD_COUNTER	0
	/* Register Bit Widths for DPE_DI_2_FMD_FDC */
	#define BWID_DPE_DI_2_FMD_FDC_FD_COUNTER	20
	/* Register Bit MASKS for DPE_DI_2_FMD_FDC */
	#define BMSK_DPE_DI_2_FMD_FDC_FD_COUNTER	0x000fffff /*  */
	/* Register BITFIELD for DPE_DI_2_FMD_FDC - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_FMD_FDC_FD_COUNTER	 0x6ca4, 0, 20, 0x000fffff
#define ROFF_DPE_DI_2_TC_prev_Hist_0	0x6cac /* DI_2_TC_prev_Hist_0 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_0	 0x6cac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_0 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_0_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_0 */
	#define BWID_DPE_DI_2_TC_prev_Hist_0_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_0 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_0_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_0_TCP_HIST_CNTR	 0x6cac, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_1	0x6cb0 /* DI_2_TC_prev_Hist_1 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_1	 0x6cb0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_1 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_1_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_1 */
	#define BWID_DPE_DI_2_TC_prev_Hist_1_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_1 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_1_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_1_TCP_HIST_CNTR	 0x6cb0, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_2	0x6cb4 /* DI_2_TC_prev_Hist_2 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_2	 0x6cb4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_2 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_2_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_2 */
	#define BWID_DPE_DI_2_TC_prev_Hist_2_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_2 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_2_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_2_TCP_HIST_CNTR	 0x6cb4, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_3	0x6cb8 /* DI_2_TC_prev_Hist_3 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_3	 0x6cb8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_3 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_3_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_3 */
	#define BWID_DPE_DI_2_TC_prev_Hist_3_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_3 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_3_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_3_TCP_HIST_CNTR	 0x6cb8, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_4	0x6cbc /* DI_2_TC_prev_Hist_4 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_4	 0x6cbc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_4 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_4_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_4 */
	#define BWID_DPE_DI_2_TC_prev_Hist_4_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_4 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_4_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_4_TCP_HIST_CNTR	 0x6cbc, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_5	0x6cc0 /* DI_2_TC_prev_Hist_5 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_5	 0x6cc0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_5 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_5_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_5 */
	#define BWID_DPE_DI_2_TC_prev_Hist_5_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_5 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_5_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_5_TCP_HIST_CNTR	 0x6cc0, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_6	0x6cc4 /* DI_2_TC_prev_Hist_6 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_6	 0x6cc4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_6 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_6_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_6 */
	#define BWID_DPE_DI_2_TC_prev_Hist_6_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_6 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_6_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_6 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_6_TCP_HIST_CNTR	 0x6cc4, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_prev_Hist_7	0x6cc8 /* DI_2_TC_prev_Hist_7 */ 
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_7	 0x6cc8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_prev_Hist_7 */
	#define BLSB_DPE_DI_2_TC_prev_Hist_7_TCP_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_prev_Hist_7 */
	#define BWID_DPE_DI_2_TC_prev_Hist_7_TCP_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_prev_Hist_7 */
	#define BMSK_DPE_DI_2_TC_prev_Hist_7_TCP_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_prev_Hist_7 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_prev_Hist_7_TCP_HIST_CNTR	 0x6cc8, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_0	0x6ccc /* DI_2_TC_next_Hist_0 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_0	 0x6ccc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_0 */
	#define BLSB_DPE_DI_2_TC_next_Hist_0_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_0 */
	#define BWID_DPE_DI_2_TC_next_Hist_0_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_0 */
	#define BMSK_DPE_DI_2_TC_next_Hist_0_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_0_TCN_HIST_CNTR	 0x6ccc, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_1	0x6cd0 /* DI_2_TC_next_Hist_1 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_1	 0x6cd0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_1 */
	#define BLSB_DPE_DI_2_TC_next_Hist_1_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_1 */
	#define BWID_DPE_DI_2_TC_next_Hist_1_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_1 */
	#define BMSK_DPE_DI_2_TC_next_Hist_1_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_1_TCN_HIST_CNTR	 0x6cd0, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_2	0x6cd4 /* DI_2_TC_next_Hist_2 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_2	 0x6cd4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_2 */
	#define BLSB_DPE_DI_2_TC_next_Hist_2_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_2 */
	#define BWID_DPE_DI_2_TC_next_Hist_2_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_2 */
	#define BMSK_DPE_DI_2_TC_next_Hist_2_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_2_TCN_HIST_CNTR	 0x6cd4, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_3	0x6cd8 /* DI_2_TC_next_Hist_3 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_3	 0x6cd8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_3 */
	#define BLSB_DPE_DI_2_TC_next_Hist_3_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_3 */
	#define BWID_DPE_DI_2_TC_next_Hist_3_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_3 */
	#define BMSK_DPE_DI_2_TC_next_Hist_3_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_3_TCN_HIST_CNTR	 0x6cd8, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_4	0x6cdc /* DI_2_TC_next_Hist_4 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_4	 0x6cdc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_4 */
	#define BLSB_DPE_DI_2_TC_next_Hist_4_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_4 */
	#define BWID_DPE_DI_2_TC_next_Hist_4_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_4 */
	#define BMSK_DPE_DI_2_TC_next_Hist_4_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_4 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_4_TCN_HIST_CNTR	 0x6cdc, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_5	0x6ce0 /* DI_2_TC_next_Hist_5 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_5	 0x6ce0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_5 */
	#define BLSB_DPE_DI_2_TC_next_Hist_5_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_5 */
	#define BWID_DPE_DI_2_TC_next_Hist_5_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_5 */
	#define BMSK_DPE_DI_2_TC_next_Hist_5_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_5 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_5_TCN_HIST_CNTR	 0x6ce0, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_6	0x6ce4 /* DI_2_TC_next_Hist_6 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_6	 0x6ce4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_6 */
	#define BLSB_DPE_DI_2_TC_next_Hist_6_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_6 */
	#define BWID_DPE_DI_2_TC_next_Hist_6_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_6 */
	#define BMSK_DPE_DI_2_TC_next_Hist_6_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_6 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_6_TCN_HIST_CNTR	 0x6ce4, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_TC_next_Hist_7	0x6ce8 /* DI_2_TC_next_Hist_7 */ 
	#define BITFIELD_DPE_DI_2_TC_next_Hist_7	 0x6ce8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_TC_next_Hist_7 */
	#define BLSB_DPE_DI_2_TC_next_Hist_7_TCN_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_TC_next_Hist_7 */
	#define BWID_DPE_DI_2_TC_next_Hist_7_TCN_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_TC_next_Hist_7 */
	#define BMSK_DPE_DI_2_TC_next_Hist_7_TCN_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_TC_next_Hist_7 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_TC_next_Hist_7_TCN_HIST_CNTR	 0x6ce8, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_A_Hist_Counter_0	0x6cf4 /* DI_2_Motion_A_Hist_Counter_0 */ 
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_0	 0x6cf4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_A_Hist_Counter_0 */
	#define BLSB_DPE_DI_2_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_A_Hist_Counter_0 */
	#define BWID_DPE_DI_2_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_A_Hist_Counter_0 */
	#define BMSK_DPE_DI_2_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_A_Hist_Counter_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_0_MOTION_A_HIST_CNTR	 0x6cf4, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_A_Hist_Counter_1	0x6cf8 /* DI_2_Motion_A_Hist_Counter_1 */ 
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_1	 0x6cf8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_A_Hist_Counter_1 */
	#define BLSB_DPE_DI_2_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_A_Hist_Counter_1 */
	#define BWID_DPE_DI_2_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_A_Hist_Counter_1 */
	#define BMSK_DPE_DI_2_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_A_Hist_Counter_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_1_MOTION_A_HIST_CNTR	 0x6cf8, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_A_Hist_Counter_2	0x6cfc /* DI_2_Motion_A_Hist_Counter_2 */ 
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_2	 0x6cfc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_A_Hist_Counter_2 */
	#define BLSB_DPE_DI_2_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_A_Hist_Counter_2 */
	#define BWID_DPE_DI_2_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_A_Hist_Counter_2 */
	#define BMSK_DPE_DI_2_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_A_Hist_Counter_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_2_MOTION_A_HIST_CNTR	 0x6cfc, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_A_Hist_Counter_3	0x6d00 /* DI_2_Motion_A_Hist_Counter_3 */ 
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_3	 0x6d00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_A_Hist_Counter_3 */
	#define BLSB_DPE_DI_2_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_A_Hist_Counter_3 */
	#define BWID_DPE_DI_2_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_A_Hist_Counter_3 */
	#define BMSK_DPE_DI_2_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_A_Hist_Counter_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_A_Hist_Counter_3_MOTION_A_HIST_CNTR	 0x6d00, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_B_Hist_Counter_0	0x6d04 /* DI_2_Motion_B_Hist_Counter_0 */ 
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_0	 0x6d04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_B_Hist_Counter_0 */
	#define BLSB_DPE_DI_2_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_B_Hist_Counter_0 */
	#define BWID_DPE_DI_2_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_B_Hist_Counter_0 */
	#define BMSK_DPE_DI_2_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_B_Hist_Counter_0 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_0_MOTION_B_HIST_CNTR	 0x6d04, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_B_Hist_Counter_1	0x6d08 /* DI_2_Motion_B_Hist_Counter_1 */ 
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_1	 0x6d08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_B_Hist_Counter_1 */
	#define BLSB_DPE_DI_2_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_B_Hist_Counter_1 */
	#define BWID_DPE_DI_2_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_B_Hist_Counter_1 */
	#define BMSK_DPE_DI_2_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_B_Hist_Counter_1 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_1_MOTION_B_HIST_CNTR	 0x6d08, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_B_Hist_Counter_2	0x6d0c /* DI_2_Motion_B_Hist_Counter_2 */ 
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_2	 0x6d0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_B_Hist_Counter_2 */
	#define BLSB_DPE_DI_2_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_B_Hist_Counter_2 */
	#define BWID_DPE_DI_2_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_B_Hist_Counter_2 */
	#define BMSK_DPE_DI_2_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_B_Hist_Counter_2 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_2_MOTION_B_HIST_CNTR	 0x6d0c, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Motion_B_Hist_Counter_3	0x6d10 /* DI_2_Motion_B_Hist_Counter_3 */ 
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_3	 0x6d10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Motion_B_Hist_Counter_3 */
	#define BLSB_DPE_DI_2_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	0
	/* Register Bit Widths for DPE_DI_2_Motion_B_Hist_Counter_3 */
	#define BWID_DPE_DI_2_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	32
	/* Register Bit MASKS for DPE_DI_2_Motion_B_Hist_Counter_3 */
	#define BMSK_DPE_DI_2_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Motion_B_Hist_Counter_3 - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Motion_B_Hist_Counter_3_MOTION_B_HIST_CNTR	 0x6d10, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Noise_Estimation_Var_Noise_Count	0x6d14 /* DI_2_Noise_Estimation_Var_Noise_Count */ 
	#define BITFIELD_DPE_DI_2_Noise_Estimation_Var_Noise_Count	 0x6d14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Noise_Estimation_Var_Noise_Count */
	#define BLSB_DPE_DI_2_Noise_Estimation_Var_Noise_Count_VarNoise_Count	0
	/* Register Bit Widths for DPE_DI_2_Noise_Estimation_Var_Noise_Count */
	#define BWID_DPE_DI_2_Noise_Estimation_Var_Noise_Count_VarNoise_Count	32
	/* Register Bit MASKS for DPE_DI_2_Noise_Estimation_Var_Noise_Count */
	#define BMSK_DPE_DI_2_Noise_Estimation_Var_Noise_Count_VarNoise_Count	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Noise_Estimation_Var_Noise_Count - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Noise_Estimation_Var_Noise_Count_VarNoise_Count	 0x6d14, 0, 32, 0x00000000
#define ROFF_DPE_DI_2_Noise_Estimation_Var_Noise_Level	0x6d18 /* DI_2_Noise_Estimation_Var_Noise_Level */ 
	#define BITFIELD_DPE_DI_2_Noise_Estimation_Var_Noise_Level	 0x6d18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_2_Noise_Estimation_Var_Noise_Level */
	#define BLSB_DPE_DI_2_Noise_Estimation_Var_Noise_Level_VarNoise_Level	0
	/* Register Bit Widths for DPE_DI_2_Noise_Estimation_Var_Noise_Level */
	#define BWID_DPE_DI_2_Noise_Estimation_Var_Noise_Level_VarNoise_Level	32
	/* Register Bit MASKS for DPE_DI_2_Noise_Estimation_Var_Noise_Level */
	#define BMSK_DPE_DI_2_Noise_Estimation_Var_Noise_Level_VarNoise_Level	0x00000000 /*  */
	/* Register BITFIELD for DPE_DI_2_Noise_Estimation_Var_Noise_Level - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_2_Noise_Estimation_Var_Noise_Level_VarNoise_Level	 0x6d18, 0, 32, 0x00000000


/* Module DPE SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_DPE_MESSAGE_DPE_INIT	0x1
#define SVEN_MODULE_EVENT_DPE_READ_INPUT_BUFFER	0x2
#define SVEN_MODULE_EVENT_DPE_WRITE_OUTPUT_BUFFER	0x3
#define SVEN_MODULE_EVENT_DPE_VPP_FW_START	0x4
#define SVEN_MODULE_EVENT_DPE_VPP_FW_RX	0x5
#define SVEN_MODULE_EVENT_DPE_SPA	0x6
#define SVEN_MODULE_EVENT_DPE_FLUSH_STOP	0x8
#define SVEN_MODULE_EVENT_DPE_FMD_DETECT	0x9
#define SVEN_MODULE_EVENT_DPE_FMD_32	0xa
#define SVEN_MODULE_EVENT_DPE_FMD_22	0xb
#define SVEN_MODULE_EVENT_DPE_FMD_DUP	0xc
#define SVEN_MODULE_EVENT_DPE_FMD_START	0xd
#define SVEN_MODULE_EVENT_DPE_FMD_NEW	0xe
#define SVEN_MODULE_EVENT_DPE_INTBUF_ALLOC	0xf
#define SVEN_MODULE_EVENT_DPE_OUTBUF_ALLOC	0x10
#define SVEN_MODULE_EVENT_DPE_OUT_OF_MEMORY	0x11
#define SVEN_MODULE_EVENT_DPE_LOOKAHEAD_READ_INPUT_BUF	0x12
#define SVEN_MODULE_EVENT_DPE_BH_ISR_ENTER	0x13
#define SVEN_MODULE_EVENT_DPE_CURRENT_INPUT_DEPTH	0x14
#define SVEN_MODULE_EVENT_DPE_METADATA_PAN_SCAN	0x15
#define SVEN_MODULE_EVENT_DPE_CLIENT_ID_IN	0x16
#define SVEN_MODULE_EVENT_DPE_CLIENT_ID_OUT	0x17
#define SVEN_MODULE_EVENT_DPE_EOS_IN	0x18
#define SVEN_MODULE_EVENT_DPE_EOS_OUT	0x19
#define SVEN_MODULE_EVENT_DPE_BUFFER_DEREF_FAIL	0x1a
#define SVEN_MODULE_EVENT_DPE_BUFFER_DEREF	0x1b
#define SVEN_MODULE_EVENT_DPE_BUFFER_ADDREF_FAIL	0x1c
#define SVEN_MODULE_EVENT_DPE_BUFFER_ADDREF	0x1d
#define SVEN_MODULE_EVENT_DPE_INPUT_PORT_EVENT	0x1e
#define SVEN_MODULE_EVENT_DPE_OUTPUT_PORT_EVENT	0x1f
#define SVEN_MODULE_EVENT_DPE_INTIAL_INPUT_BUFFER_READ_TIME	0x20
#define SVEN_MODULE_EVENT_DPE_INTIAL_INPUT_BUFFER_READ_SIZE	0x21
#define SVEN_MODULE_EVENT_DPE_OUTPUT_BUFFER_WRITE	0x22
#define SVEN_MODULE_EVENT_DPE_OUTPUT_NON_FRAME_BUFFER	0x23
#define SVEN_MODULE_EVENT_DPE_QUEUE_WORK_ITEM	0x24
#define SVEN_MODULE_EVENT_DPE_SEND_FRAME_TO_FW_WORK	0x25
#define SVEN_MODULE_EVENT_DPE_INTIAL_INPUT_BUFFER_READ_TIME	0x20
#define SVEN_MODULE_EVENT_DPE_INTIAL_INPUT_BUFFER_READ_SIZE	0x21
#define SVEN_MODULE_EVENT_DPE_OUTPUT_BUFFER_WRITE	0x22
#define SVEN_MODULE_EVENT_DPE_OUTPUT_NON_FRAME_BUFFER	0x23
#define SVEN_MODULE_EVENT_DPE_QUEUE_WORK_ITEM	0x24
#define SVEN_MODULE_EVENT_DPE_SEND_FRAME_TO_FW_WORK	0x25
#define SVEN_MODULE_EVENT_DPE_FW_SOURCE_RECTANGE	0x26
#define SVEN_MODULE_EVENT_DPE_FW_DEST_RECTANGE	0x27
#define SVEN_MODULE_EVENT_DPE_GET_FRAME_FROM_FW_WORK	0x28
#define SVEN_MODULE_EVENT_DPE_READ_IN_BUFFER	0x29
#define SVEN_MODULE_EVENT_DPE_INTIAL_INPUT_BUFFER_READ_COLOR	0x2a
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_IN_RECT_POINTS	0x32
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_IN_RECT_SIZE	0x33
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_OUT_RECT_POINTS	0x34
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_OUT_RECT_SIZE	0x35
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_FLAGS	0x36
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_SETTINGS	0x37
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_DI_WEIGHTS	0x38
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_SHIFTS	0x39
#define SVEN_MODULE_EVENT_DPE_FW_PARAMS_BUFFERS	0x3a
#define SVEN_MODULE_EVENT_DPE_IN_DEQUEUE	0x64
#define SVEN_MODULE_EVENT_DPE_OUT_ENQUEUE	0x65
#define SVEN_MODULE_EVENT_DPE_CONTENT_TIME_GAP	0x66
#define SVEN_MODULE_EVENT_DPE_CLOSE	0x68
#define SVEN_MODULE_EVENT_DPE_STATE_CHANGE	0x6b
#define SVEN_MODULE_EVENT_DPE_FLUSH_START	0x6c
#define SVEN_MODULE_EVENT_DPE_FLUSH_COMPLETE	0x6d
#define SVEN_MODULE_EVENT_DPE_NEW_SEG_IN	0x6e
#define SVEN_MODULE_EVENT_DPE_NEW_SEG_OUT	0x6f
#define SVEN_MODULE_EVENT_DPE_OPEN	0x67


#endif /* DPE_REGOFFS_H */
