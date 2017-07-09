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
	#define BLSB_DPE_DPE_420_422_Converter_Control_Pxl_repeat	4
	#define BLSB_DPE_DPE_420_422_Converter_Control_PI	3
	#define BLSB_DPE_DPE_420_422_Converter_Control_TOP	2
	#define BLSB_DPE_DPE_420_422_Converter_Control_BYP	1
	#define BLSB_DPE_DPE_420_422_Converter_Control_UNIT_EN	0
	/* Register Bit Widths for DPE_DPE_420_422_Converter_Control */
	#define BWID_DPE_DPE_420_422_Converter_Control_Pxl_repeat	1
	#define BWID_DPE_DPE_420_422_Converter_Control_PI	1
	#define BWID_DPE_DPE_420_422_Converter_Control_TOP	1
	#define BWID_DPE_DPE_420_422_Converter_Control_BYP	1
	#define BWID_DPE_DPE_420_422_Converter_Control_UNIT_EN	1
	/* Register Bit MASKS for DPE_DPE_420_422_Converter_Control */
	#define BMSK_DPE_DPE_420_422_Converter_Control_Pxl_repeat	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_PI	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_TOP	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_BYP	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_DPE_420_422_Converter_Control_UNIT_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_DPE_420_422_Converter_Control - roff, lsb, width, mask */
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_Pxl_repeat	 0x01e0, 4, 1, 0x00000010
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_PI	 0x01e0, 3, 1, 0x00000008
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_TOP	 0x01e0, 2, 1, 0x00000004
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_BYP	 0x01e0, 1, 1, 0x00000002
	#define BITFIELD_DPE_DPE_420_422_Converter_Control_UNIT_EN	 0x01e0, 0, 1, 0x00000001
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
	#define BLSB_DPE_DI_Field_N_Next_Block_Parameters_Register_onext_rd_offset_y	8
	#define BLSB_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	0
	/* Register Bit Widths for DPE_DI_Field_N_Next_Block_Parameters_Register */
	#define BWID_DPE_DI_Field_N_Next_Block_Parameters_Register_onext_rd_offset_y	5
	#define BWID_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	5
	/* Register Bit MASKS for DPE_DI_Field_N_Next_Block_Parameters_Register */
	#define BMSK_DPE_DI_Field_N_Next_Block_Parameters_Register_onext_rd_offset_y	0x00001f00 /*  */
	#define BMSK_DPE_DI_Field_N_Next_Block_Parameters_Register_next_wr_y	0x0000001f /*  */
	/* Register BITFIELD for DPE_DI_Field_N_Next_Block_Parameters_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_Field_N_Next_Block_Parameters_Register_onext_rd_offset_y	 0x1418, 8, 5, 0x00001f00
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
	#define BLSB_DPE_DI_Control_Register_Swap23_mode	10
	#define BLSB_DPE_DI_Control_Register_FilmMode_1_0	8
	#define BLSB_DPE_DI_Control_Register_CONST_HISTORY	7
	#define BLSB_DPE_DI_Control_Register_Software_Frame_Start	6
	#define BLSB_DPE_DI_Control_Register_BYPASS_SPATIAL_NRF	5
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
	#define BWID_DPE_DI_Control_Register_Swap23_mode	1
	#define BWID_DPE_DI_Control_Register_FilmMode_1_0	2
	#define BWID_DPE_DI_Control_Register_CONST_HISTORY	1
	#define BWID_DPE_DI_Control_Register_Software_Frame_Start	1
	#define BWID_DPE_DI_Control_Register_BYPASS_SPATIAL_NRF	1
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
	#define BMSK_DPE_DI_Control_Register_Swap23_mode	(1<<10) /* == 0x00000400:  */
	#define BMSK_DPE_DI_Control_Register_FilmMode_1_0	0x00000300 /*  */
	#define BMSK_DPE_DI_Control_Register_CONST_HISTORY	(1<<7) /* == 0x00000080:  */
	#define BMSK_DPE_DI_Control_Register_Software_Frame_Start	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_DI_Control_Register_BYPASS_SPATIAL_NRF	(1<<5) /* == 0x00000020:  */
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
	#define BITFIELD_DPE_DI_Control_Register_Swap23_mode	 0x1420, 10, 1, 0x00000400
	#define BITFIELD_DPE_DI_Control_Register_FilmMode_1_0	 0x1420, 8, 2, 0x00000300
	#define BITFIELD_DPE_DI_Control_Register_CONST_HISTORY	 0x1420, 7, 1, 0x00000080
	#define BITFIELD_DPE_DI_Control_Register_Software_Frame_Start	 0x1420, 6, 1, 0x00000040
	#define BITFIELD_DPE_DI_Control_Register_BYPASS_SPATIAL_NRF	 0x1420, 5, 1, 0x00000020
	#define BITFIELD_DPE_DI_Control_Register_BYPASSNRF	 0x1420, 4, 1, 0x00000010
	#define BITFIELD_DPE_DI_Control_Register_TOP_FIELD	 0x1420, 3, 1, 0x00000008
	#define BITFIELD_DPE_DI_Control_Register_SPATIAL	 0x1420, 2, 1, 0x00000004
	#define BITFIELD_DPE_DI_Control_Register_Progressive	 0x1420, 1, 1, 0x00000002
	#define BITFIELD_DPE_DI_Control_Register_Bypass	 0x1420, 0, 1, 0x00000001
#define ROFF_DPE_DI_Status_Register	0x1424 /* status register */ 
	#define BITFIELD_DPE_DI_Status_Register	 0x1424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
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
#define ROFF_DPE_DI_FMD_min_max_diff_Registers	0x1468 /* DI_FMD_min_max_diff_Registers */ 
	#define BITFIELD_DPE_DI_FMD_min_max_diff_Registers	 0x1468, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_DI_FMD_min_max_diff_Registers */
	#define BLSB_DPE_DI_FMD_min_max_diff_Registers_Min_diff	16
	#define BLSB_DPE_DI_FMD_min_max_diff_Registers_Max_diff	0
	/* Register Bit Widths for DPE_DI_FMD_min_max_diff_Registers */
	#define BWID_DPE_DI_FMD_min_max_diff_Registers_Min_diff	16
	#define BWID_DPE_DI_FMD_min_max_diff_Registers_Max_diff	16
	/* Register Bit MASKS for DPE_DI_FMD_min_max_diff_Registers */
	#define BMSK_DPE_DI_FMD_min_max_diff_Registers_Min_diff	0xffff0000 /*  */
	#define BMSK_DPE_DI_FMD_min_max_diff_Registers_Max_diff	0x0000ffff /*  */
	/* Register BITFIELD for DPE_DI_FMD_min_max_diff_Registers - roff, lsb, width, mask */
	#define BITFIELD_DPE_DI_FMD_min_max_diff_Registers_Min_diff	 0x1468, 16, 16, 0xffff0000
	#define BITFIELD_DPE_DI_FMD_min_max_diff_Registers_Max_diff	 0x1468, 0, 16, 0x0000ffff
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
#define ROFF_DPE_Deringing_Stride_Height_Register	0x400 /* set up the stride height and number of strides per frame */ 
	#define BITFIELD_DPE_Deringing_Stride_Height_Register	 0x0400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_Deringing_Stride_Height_Register */
	#define BLSB_DPE_Deringing_Stride_Height_Register_num_strides	12
	#define BLSB_DPE_Deringing_Stride_Height_Register_stride_h	0
	/* Register Bit Widths for DPE_Deringing_Stride_Height_Register */
	#define BWID_DPE_Deringing_Stride_Height_Register_num_strides	4
	#define BWID_DPE_Deringing_Stride_Height_Register_stride_h	11
	/* Register Bit MASKS for DPE_Deringing_Stride_Height_Register */
	#define BMSK_DPE_Deringing_Stride_Height_Register_num_strides	0x0000f000 /*  */
	#define BMSK_DPE_Deringing_Stride_Height_Register_stride_h	0x000007ff /*  */
	/* Register BITFIELD for DPE_Deringing_Stride_Height_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_Deringing_Stride_Height_Register_num_strides	 0x0400, 12, 4, 0x0000f000
	#define BITFIELD_DPE_Deringing_Stride_Height_Register_stride_h	 0x0400, 0, 11, 0x000007ff
#define ROFF_DPE_Deringing_Stride_Width_Register	0x404 /* set up the input stride width, stride offset and output stride width for frame N */ 
	#define BITFIELD_DPE_Deringing_Stride_Width_Register	 0x0404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_Deringing_Stride_Width_Register */
	#define BLSB_DPE_Deringing_Stride_Width_Register_next_rd_offset_x	27
	#define BLSB_DPE_Deringing_Stride_Width_Register_pix_coord_x	16
	#define BLSB_DPE_Deringing_Stride_Width_Register_out_stride_w	7
	#define BLSB_DPE_Deringing_Stride_Width_Register_RM	6
	#define BLSB_DPE_Deringing_Stride_Width_Register_LM	5
	#define BLSB_DPE_Deringing_Stride_Width_Register_in_stride_off	0
	/* Register Bit Widths for DPE_Deringing_Stride_Width_Register */
	#define BWID_DPE_Deringing_Stride_Width_Register_next_rd_offset_x	5
	#define BWID_DPE_Deringing_Stride_Width_Register_pix_coord_x	11
	#define BWID_DPE_Deringing_Stride_Width_Register_out_stride_w	9
	#define BWID_DPE_Deringing_Stride_Width_Register_RM	1
	#define BWID_DPE_Deringing_Stride_Width_Register_LM	1
	#define BWID_DPE_Deringing_Stride_Width_Register_in_stride_off	5
	/* Register Bit MASKS for DPE_Deringing_Stride_Width_Register */
	#define BMSK_DPE_Deringing_Stride_Width_Register_next_rd_offset_x	0xf8000000 /*  */
	#define BMSK_DPE_Deringing_Stride_Width_Register_pix_coord_x	0x07ff0000 /*  */
	#define BMSK_DPE_Deringing_Stride_Width_Register_out_stride_w	0x0000ff80 /*  */
	#define BMSK_DPE_Deringing_Stride_Width_Register_RM	(1<<6) /* == 0x00000040:  */
	#define BMSK_DPE_Deringing_Stride_Width_Register_LM	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_Deringing_Stride_Width_Register_in_stride_off	0x0000001f /*  */
	/* Register BITFIELD for DPE_Deringing_Stride_Width_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_Deringing_Stride_Width_Register_next_rd_offset_x	 0x0404, 27, 5, 0xf8000000
	#define BITFIELD_DPE_Deringing_Stride_Width_Register_pix_coord_x	 0x0404, 16, 11, 0x07ff0000
	#define BITFIELD_DPE_Deringing_Stride_Width_Register_out_stride_w	 0x0404, 7, 9, 0x0000ff80
	#define BITFIELD_DPE_Deringing_Stride_Width_Register_RM	 0x0404, 6, 1, 0x00000040
	#define BITFIELD_DPE_Deringing_Stride_Width_Register_LM	 0x0404, 5, 1, 0x00000020
	#define BITFIELD_DPE_Deringing_Stride_Width_Register_in_stride_off	 0x0404, 0, 5, 0x0000001f
#define ROFF_DPE_Deringing_Control_Register	0x440 /* Deringing_Control_Register */ 
	#define BITFIELD_DPE_Deringing_Control_Register	 0x0440, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_Deringing_Control_Register */
	#define BLSB_DPE_Deringing_Control_Register_rnr_bypass	1
	#define BLSB_DPE_Deringing_Control_Register_rnr_en	0
	/* Register Bit Widths for DPE_Deringing_Control_Register */
	#define BWID_DPE_Deringing_Control_Register_rnr_bypass	1
	#define BWID_DPE_Deringing_Control_Register_rnr_en	1
	/* Register Bit MASKS for DPE_Deringing_Control_Register */
	#define BMSK_DPE_Deringing_Control_Register_rnr_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_Deringing_Control_Register_rnr_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_Deringing_Control_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_Deringing_Control_Register_rnr_bypass	 0x0440, 1, 1, 0x00000002
	#define BITFIELD_DPE_Deringing_Control_Register_rnr_en	 0x0440, 0, 1, 0x00000001
#define ROFF_DPE_Deringing_Threshold_Register	0x444 /* Deringing_Threshold_Register */ 
	#define BITFIELD_DPE_Deringing_Threshold_Register	 0x0444, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DPE_Deringing_Threshold_Register */
	#define BLSB_DPE_Deringing_Threshold_Register_rnr_disthigh_threshold	20
	#define BLSB_DPE_Deringing_Threshold_Register_rnr_average_threshold	10
	#define BLSB_DPE_Deringing_Threshold_Register_rnr_distlow_threshold	0
	/* Register Bit Widths for DPE_Deringing_Threshold_Register */
	#define BWID_DPE_Deringing_Threshold_Register_rnr_disthigh_threshold	10
	#define BWID_DPE_Deringing_Threshold_Register_rnr_average_threshold	10
	#define BWID_DPE_Deringing_Threshold_Register_rnr_distlow_threshold	10
	/* Register Bit MASKS for DPE_Deringing_Threshold_Register */
	#define BMSK_DPE_Deringing_Threshold_Register_rnr_disthigh_threshold	0x3ff00000 /*  */
	#define BMSK_DPE_Deringing_Threshold_Register_rnr_average_threshold	0x000ffc00 /*  */
	#define BMSK_DPE_Deringing_Threshold_Register_rnr_distlow_threshold	0x000003ff /*  */
	/* Register BITFIELD for DPE_Deringing_Threshold_Register - roff, lsb, width, mask */
	#define BITFIELD_DPE_Deringing_Threshold_Register_rnr_disthigh_threshold	 0x0444, 20, 10, 0x3ff00000
	#define BITFIELD_DPE_Deringing_Threshold_Register_rnr_average_threshold	 0x0444, 10, 10, 0x000ffc00
	#define BITFIELD_DPE_Deringing_Threshold_Register_rnr_distlow_threshold	 0x0444, 0, 10, 0x000003ff
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
	#define BLSB_DPE_HSC_CONTROL_dering_en	4
	#define BLSB_DPE_HSC_CONTROL_bank_sel	2
	#define BLSB_DPE_HSC_CONTROL_en	0
	/* Register Bit Widths for DPE_HSC_CONTROL */
	#define BWID_DPE_HSC_CONTROL_dering_en	1
	#define BWID_DPE_HSC_CONTROL_bank_sel	1
	#define BWID_DPE_HSC_CONTROL_en	1
	/* Register Bit MASKS for DPE_HSC_CONTROL */
	#define BMSK_DPE_HSC_CONTROL_dering_en	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_HSC_CONTROL_bank_sel	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_HSC_CONTROL_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_HSC_CONTROL - roff, lsb, width, mask */
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
	#define BLSB_DPE_VSC_CONTROL_UV_420_422_en	5
	#define BLSB_DPE_VSC_CONTROL_dering_en	4
	#define BLSB_DPE_VSC_CONTROL_pic_done	3
	#define BLSB_DPE_VSC_CONTROL_bank_sel	2
	#define BLSB_DPE_VSC_CONTROL_bypass	1
	#define BLSB_DPE_VSC_CONTROL_en	0
	/* Register Bit Widths for DPE_VSC_CONTROL */
	#define BWID_DPE_VSC_CONTROL_UV_420_422_en	1
	#define BWID_DPE_VSC_CONTROL_dering_en	1
	#define BWID_DPE_VSC_CONTROL_pic_done	1
	#define BWID_DPE_VSC_CONTROL_bank_sel	1
	#define BWID_DPE_VSC_CONTROL_bypass	1
	#define BWID_DPE_VSC_CONTROL_en	1
	/* Register Bit MASKS for DPE_VSC_CONTROL */
	#define BMSK_DPE_VSC_CONTROL_UV_420_422_en	(1<<5) /* == 0x00000020:  */
	#define BMSK_DPE_VSC_CONTROL_dering_en	(1<<4) /* == 0x00000010:  */
	#define BMSK_DPE_VSC_CONTROL_pic_done	(1<<3) /* == 0x00000008:  */
	#define BMSK_DPE_VSC_CONTROL_bank_sel	(1<<2) /* == 0x00000004:  */
	#define BMSK_DPE_VSC_CONTROL_bypass	(1<<1) /* == 0x00000002:  */
	#define BMSK_DPE_VSC_CONTROL_en	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DPE_VSC_CONTROL - roff, lsb, width, mask */
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
