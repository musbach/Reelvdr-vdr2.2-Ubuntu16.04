#ifndef AVI_REGOFFS_H
#define AVI_REGOFFS_H 1
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


/* Module AVI CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_AVI_CONTROL	0x8 /* AVI Configuration Control Register. */ 
	#define BITFIELD_AVI_CONTROL	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVI_CONTROL */
	#define BLSB_AVI_CONTROL_RSVD_31_18	18
	#define BLSB_AVI_CONTROL_AVO_FLASH_EN	17
	#define BLSB_AVI_CONTROL_AVI_FLASH_EN	16
	#define BLSB_AVI_CONTROL_RSVD_15	15
	#define BLSB_AVI_CONTROL_SPDIF_RESET_N	14
	#define BLSB_AVI_CONTROL_HDMI_RESET_N	13
	#define BLSB_AVI_CONTROL_TS_RESET_N	12
	#define BLSB_AVI_CONTROL_RGB_RESET_N	11
	#define BLSB_AVI_CONTROL_BT1120_RESET_N	10
	#define BLSB_AVI_CONTROL_VCAP_RESET_N	9
	#define BLSB_AVI_CONTROL_I2S_RESET_N	8
	#define BLSB_AVI_CONTROL_RSVD_7	7
	#define BLSB_AVI_CONTROL_SPDIF_INTF_EN	6
	#define BLSB_AVI_CONTROL_HDMI_INTF_EN	5
	#define BLSB_AVI_CONTROL_TS_INTF_EN	4
	#define BLSB_AVI_CONTROL_RGB_INTF_EN	3
	#define BLSB_AVI_CONTROL_BT1120_INTF_EN	2
	#define BLSB_AVI_CONTROL_VCAP_INTF_EN	1
	#define BLSB_AVI_CONTROL_I2S_INTF_EN	0
	/* Register Bit Widths for AVI_CONTROL */
	#define BWID_AVI_CONTROL_RSVD_31_18	14
	#define BWID_AVI_CONTROL_AVO_FLASH_EN	1
	#define BWID_AVI_CONTROL_AVI_FLASH_EN	1
	#define BWID_AVI_CONTROL_RSVD_15	1
	#define BWID_AVI_CONTROL_SPDIF_RESET_N	1
	#define BWID_AVI_CONTROL_HDMI_RESET_N	1
	#define BWID_AVI_CONTROL_TS_RESET_N	1
	#define BWID_AVI_CONTROL_RGB_RESET_N	1
	#define BWID_AVI_CONTROL_BT1120_RESET_N	1
	#define BWID_AVI_CONTROL_VCAP_RESET_N	1
	#define BWID_AVI_CONTROL_I2S_RESET_N	1
	#define BWID_AVI_CONTROL_RSVD_7	1
	#define BWID_AVI_CONTROL_SPDIF_INTF_EN	1
	#define BWID_AVI_CONTROL_HDMI_INTF_EN	1
	#define BWID_AVI_CONTROL_TS_INTF_EN	1
	#define BWID_AVI_CONTROL_RGB_INTF_EN	1
	#define BWID_AVI_CONTROL_BT1120_INTF_EN	1
	#define BWID_AVI_CONTROL_VCAP_INTF_EN	1
	#define BWID_AVI_CONTROL_I2S_INTF_EN	1
	/* Register Bit MASKS for AVI_CONTROL */
	#define BMSK_AVI_CONTROL_RSVD_31_18	0xfffc0000 /*  */
	#define BMSK_AVI_CONTROL_AVO_FLASH_EN	(1<<17) /* == 0x00020000:  */
	#define BMSK_AVI_CONTROL_AVI_FLASH_EN	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVI_CONTROL_RSVD_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_AVI_CONTROL_SPDIF_RESET_N	(1<<14) /* == 0x00004000:  */
	#define BMSK_AVI_CONTROL_HDMI_RESET_N	(1<<13) /* == 0x00002000:  */
	#define BMSK_AVI_CONTROL_TS_RESET_N	(1<<12) /* == 0x00001000:  */
	#define BMSK_AVI_CONTROL_RGB_RESET_N	(1<<11) /* == 0x00000800:  */
	#define BMSK_AVI_CONTROL_BT1120_RESET_N	(1<<10) /* == 0x00000400:  */
	#define BMSK_AVI_CONTROL_VCAP_RESET_N	(1<<9) /* == 0x00000200:  */
	#define BMSK_AVI_CONTROL_I2S_RESET_N	(1<<8) /* == 0x00000100:  */
	#define BMSK_AVI_CONTROL_RSVD_7	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVI_CONTROL_SPDIF_INTF_EN	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVI_CONTROL_HDMI_INTF_EN	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVI_CONTROL_TS_INTF_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVI_CONTROL_RGB_INTF_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVI_CONTROL_BT1120_INTF_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVI_CONTROL_VCAP_INTF_EN	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVI_CONTROL_I2S_INTF_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVI_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVI_CONTROL_RSVD_31_18	 0x0008, 18, 14, 0xfffc0000
	#define BITFIELD_AVI_CONTROL_AVO_FLASH_EN	 0x0008, 17, 1, 0x00020000
	#define BITFIELD_AVI_CONTROL_AVI_FLASH_EN	 0x0008, 16, 1, 0x00010000
	#define BITFIELD_AVI_CONTROL_RSVD_15	 0x0008, 15, 1, 0x00008000
	#define BITFIELD_AVI_CONTROL_SPDIF_RESET_N	 0x0008, 14, 1, 0x00004000
	#define BITFIELD_AVI_CONTROL_HDMI_RESET_N	 0x0008, 13, 1, 0x00002000
	#define BITFIELD_AVI_CONTROL_TS_RESET_N	 0x0008, 12, 1, 0x00001000
	#define BITFIELD_AVI_CONTROL_RGB_RESET_N	 0x0008, 11, 1, 0x00000800
	#define BITFIELD_AVI_CONTROL_BT1120_RESET_N	 0x0008, 10, 1, 0x00000400
	#define BITFIELD_AVI_CONTROL_VCAP_RESET_N	 0x0008, 9, 1, 0x00000200
	#define BITFIELD_AVI_CONTROL_I2S_RESET_N	 0x0008, 8, 1, 0x00000100
	#define BITFIELD_AVI_CONTROL_RSVD_7	 0x0008, 7, 1, 0x00000080
	#define BITFIELD_AVI_CONTROL_SPDIF_INTF_EN	 0x0008, 6, 1, 0x00000040
	#define BITFIELD_AVI_CONTROL_HDMI_INTF_EN	 0x0008, 5, 1, 0x00000020
	#define BITFIELD_AVI_CONTROL_TS_INTF_EN	 0x0008, 4, 1, 0x00000010
	#define BITFIELD_AVI_CONTROL_RGB_INTF_EN	 0x0008, 3, 1, 0x00000008
	#define BITFIELD_AVI_CONTROL_BT1120_INTF_EN	 0x0008, 2, 1, 0x00000004
	#define BITFIELD_AVI_CONTROL_VCAP_INTF_EN	 0x0008, 1, 1, 0x00000002
	#define BITFIELD_AVI_CONTROL_I2S_INTF_EN	 0x0008, 0, 1, 0x00000001
#define ROFF_AVI_I2S_CONTROL	0x10000 /* I2S AVI Configuration Control Register. */ 
	#define BITFIELD_AVI_I2S_CONTROL	 0x10000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVI_I2S_CONTROL */
	#define BLSB_AVI_I2S_CONTROL_RSVD_31_21	21
	#define BLSB_AVI_I2S_CONTROL_BURST_SIZE	16
	#define BLSB_AVI_I2S_CONTROL_LOOP	8
	#define BLSB_AVI_I2S_CONTROL_RSVD_7_6	6
	#define BLSB_AVI_I2S_CONTROL_CLR_UFLOW	5
	#define BLSB_AVI_I2S_CONTROL_MEM_AGENT_EN	4
	#define BLSB_AVI_I2S_CONTROL_MODE	2
	#define BLSB_AVI_I2S_CONTROL_MSB_JUSTIFIED	1
	#define BLSB_AVI_I2S_CONTROL_RSVD_0	0
	/* Register Bit Widths for AVI_I2S_CONTROL */
	#define BWID_AVI_I2S_CONTROL_RSVD_31_21	11
	#define BWID_AVI_I2S_CONTROL_BURST_SIZE	5
	#define BWID_AVI_I2S_CONTROL_LOOP	8
	#define BWID_AVI_I2S_CONTROL_RSVD_7_6	2
	#define BWID_AVI_I2S_CONTROL_CLR_UFLOW	1
	#define BWID_AVI_I2S_CONTROL_MEM_AGENT_EN	1
	#define BWID_AVI_I2S_CONTROL_MODE	2
	#define BWID_AVI_I2S_CONTROL_MSB_JUSTIFIED	1
	#define BWID_AVI_I2S_CONTROL_RSVD_0	1
	/* Register Bit MASKS for AVI_I2S_CONTROL */
	#define BMSK_AVI_I2S_CONTROL_RSVD_31_21	0xffe00000 /*  */
	#define BMSK_AVI_I2S_CONTROL_BURST_SIZE	0x001f0000 /*  */
	#define BMSK_AVI_I2S_CONTROL_LOOP	0x0000ff00 /*  */
	#define BMSK_AVI_I2S_CONTROL_RSVD_7_6	0x000000c0 /*  */
	#define BMSK_AVI_I2S_CONTROL_CLR_UFLOW	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVI_I2S_CONTROL_MEM_AGENT_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVI_I2S_CONTROL_MODE	0x0000000c /*  */
	#define BMSK_AVI_I2S_CONTROL_MSB_JUSTIFIED	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVI_I2S_CONTROL_RSVD_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVI_I2S_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVI_I2S_CONTROL_RSVD_31_21	 0x10000, 21, 11, 0xffe00000
	#define BITFIELD_AVI_I2S_CONTROL_BURST_SIZE	 0x10000, 16, 5, 0x001f0000
	#define BITFIELD_AVI_I2S_CONTROL_LOOP	 0x10000, 8, 8, 0x0000ff00
	#define BITFIELD_AVI_I2S_CONTROL_RSVD_7_6	 0x10000, 6, 2, 0x000000c0
	#define BITFIELD_AVI_I2S_CONTROL_CLR_UFLOW	 0x10000, 5, 1, 0x00000020
	#define BITFIELD_AVI_I2S_CONTROL_MEM_AGENT_EN	 0x10000, 4, 1, 0x00000010
	#define BITFIELD_AVI_I2S_CONTROL_MODE	 0x10000, 2, 2, 0x0000000c
	#define BITFIELD_AVI_I2S_CONTROL_MSB_JUSTIFIED	 0x10000, 1, 1, 0x00000002
	#define BITFIELD_AVI_I2S_CONTROL_RSVD_0	 0x10000, 0, 1, 0x00000001
#define ROFF_AVI_I2S_STATUS	0x10004 /* I2S AVI Configuration Status Register. */ 
	#define BITFIELD_AVI_I2S_STATUS	 0x10004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVI_I2S_STATUS */
	#define BLSB_AVI_I2S_STATUS_LOOP_DONE	31
	#define BLSB_AVI_I2S_STATUS_TX_FIFO_UFLOW	30
	#define BLSB_AVI_I2S_STATUS_I2S_BUFFER_UFLOW	29
	#define BLSB_AVI_I2S_STATUS_RSVD_28_17	17
	#define BLSB_AVI_I2S_STATUS_TX_FIFO_EMPTY	16
	#define BLSB_AVI_I2S_STATUS_TX_COUNT	0
	/* Register Bit Widths for AVI_I2S_STATUS */
	#define BWID_AVI_I2S_STATUS_LOOP_DONE	1
	#define BWID_AVI_I2S_STATUS_TX_FIFO_UFLOW	1
	#define BWID_AVI_I2S_STATUS_I2S_BUFFER_UFLOW	1
	#define BWID_AVI_I2S_STATUS_RSVD_28_17	12
	#define BWID_AVI_I2S_STATUS_TX_FIFO_EMPTY	1
	#define BWID_AVI_I2S_STATUS_TX_COUNT	16
	/* Register Bit MASKS for AVI_I2S_STATUS */
	#define BMSK_AVI_I2S_STATUS_LOOP_DONE	(1<<31) /* == 0x80000000:  */
	#define BMSK_AVI_I2S_STATUS_TX_FIFO_UFLOW	(1<<30) /* == 0x40000000:  */
	#define BMSK_AVI_I2S_STATUS_I2S_BUFFER_UFLOW	(1<<29) /* == 0x20000000:  */
	#define BMSK_AVI_I2S_STATUS_RSVD_28_17	0x1ffe0000 /*  */
	#define BMSK_AVI_I2S_STATUS_TX_FIFO_EMPTY	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVI_I2S_STATUS_TX_COUNT	0x0000ffff /*  */
	/* Register BITFIELD for AVI_I2S_STATUS - roff, lsb, width, mask */
	#define BITFIELD_AVI_I2S_STATUS_LOOP_DONE	 0x10004, 31, 1, 0x80000000
	#define BITFIELD_AVI_I2S_STATUS_TX_FIFO_UFLOW	 0x10004, 30, 1, 0x40000000
	#define BITFIELD_AVI_I2S_STATUS_I2S_BUFFER_UFLOW	 0x10004, 29, 1, 0x20000000
	#define BITFIELD_AVI_I2S_STATUS_RSVD_28_17	 0x10004, 17, 12, 0x1ffe0000
	#define BITFIELD_AVI_I2S_STATUS_TX_FIFO_EMPTY	 0x10004, 16, 1, 0x00010000
	#define BITFIELD_AVI_I2S_STATUS_TX_COUNT	 0x10004, 0, 16, 0x0000ffff
#define ROFF_AVI_I2S_BUF_START_ADDR	0x10018 /* I2S AVI Buffer Start Address */ 
	#define BITFIELD_AVI_I2S_BUF_START_ADDR	 0x10018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_I2S_BUF_END_ADDR	0x1001c /* I2S AVI Buffer End Address */ 
	#define BITFIELD_AVI_I2S_BUF_END_ADDR	 0x1001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_I2S_BUF_RD_PTR	0x10020 /* I2S AVI Buffer Read Pointer */ 
	#define BITFIELD_AVI_I2S_BUF_RD_PTR	 0x10020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_I2S_BUF_WR_PTR	0x10024 /* I2S AVI Buffer Write Pointer */ 
	#define BITFIELD_AVI_I2S_BUF_WR_PTR	 0x10024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_BSR_AVI_TS_CONTROL	0x0 /* Pre-Filter Control register */ 
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVI_BSR_AVI_TS_CONTROL */
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_RSVD_31_27	27
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Burst_Size	24
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_TS_CLK_Edge	23
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_ERR_Polarity	22
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_SYNC_Polarity	21
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_DAV_Polarity	20
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_CLR_uFlow	19
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_RSVD_18_17	17
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Inject_Error	16
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Loop	8
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Calendaring	7
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Timestamp	6
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Serial_Parallel	5
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_MEM_Agent_EN	4
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_Mode	2
	#define BLSB_AVI_BSR_AVI_TS_CONTROL_RSVD_1_0	0
	/* Register Bit Widths for AVI_BSR_AVI_TS_CONTROL */
	#define BWID_AVI_BSR_AVI_TS_CONTROL_RSVD_31_27	5
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Burst_Size	3
	#define BWID_AVI_BSR_AVI_TS_CONTROL_TS_CLK_Edge	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_ERR_Polarity	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_SYNC_Polarity	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_DAV_Polarity	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_CLR_uFlow	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_RSVD_18_17	2
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Inject_Error	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Loop	8
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Calendaring	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Timestamp	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Serial_Parallel	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_MEM_Agent_EN	1
	#define BWID_AVI_BSR_AVI_TS_CONTROL_Mode	2
	#define BWID_AVI_BSR_AVI_TS_CONTROL_RSVD_1_0	2
	/* Register Bit MASKS for AVI_BSR_AVI_TS_CONTROL */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_RSVD_31_27	0xf8000000 /*  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Burst_Size	0x07000000 /*  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_TS_CLK_Edge	(1<<23) /* == 0x00800000:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_ERR_Polarity	(1<<22) /* == 0x00400000:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_SYNC_Polarity	(1<<21) /* == 0x00200000:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_DAV_Polarity	(1<<20) /* == 0x00100000:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_CLR_uFlow	(1<<19) /* == 0x00080000:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_RSVD_18_17	0x00060000 /*  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Inject_Error	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Loop	0x0000ff00 /*  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Calendaring	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Timestamp	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Serial_Parallel	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_MEM_Agent_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_Mode	0x0000000c /*  */
	#define BMSK_AVI_BSR_AVI_TS_CONTROL_RSVD_1_0	0x00000003 /*  */
	/* Register BITFIELD for AVI_BSR_AVI_TS_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_RSVD_31_27	 0x0000, 27, 5, 0xf8000000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Burst_Size	 0x0000, 24, 3, 0x07000000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_TS_CLK_Edge	 0x0000, 23, 1, 0x00800000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_ERR_Polarity	 0x0000, 22, 1, 0x00400000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_SYNC_Polarity	 0x0000, 21, 1, 0x00200000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_DAV_Polarity	 0x0000, 20, 1, 0x00100000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_CLR_uFlow	 0x0000, 19, 1, 0x00080000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_RSVD_18_17	 0x0000, 17, 2, 0x00060000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Inject_Error	 0x0000, 16, 1, 0x00010000
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Loop	 0x0000, 8, 8, 0x0000ff00
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Calendaring	 0x0000, 7, 1, 0x00000080
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Timestamp	 0x0000, 6, 1, 0x00000040
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Serial_Parallel	 0x0000, 5, 1, 0x00000020
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_MEM_Agent_EN	 0x0000, 4, 1, 0x00000010
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_Mode	 0x0000, 2, 2, 0x0000000c
	#define BITFIELD_AVI_BSR_AVI_TS_CONTROL_RSVD_1_0	 0x0000, 0, 2, 0x00000003
#define ROFF_AVI_BSR_AVI_TS_STATUS	0x4 /* Pre-Filter Status register */ 
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVI_BSR_AVI_TS_STATUS */
	#define BLSB_AVI_BSR_AVI_TS_STATUS_RSVD_31_7	7
	#define BLSB_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Empty	6
	#define BLSB_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Full	5
	#define BLSB_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Loop_Done	4
	#define BLSB_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Underrun	3
	#define BLSB_AVI_BSR_AVI_TS_STATUS_Address_Error	2
	#define BLSB_AVI_BSR_AVI_TS_STATUS_RSVD_1_0	0
	/* Register Bit Widths for AVI_BSR_AVI_TS_STATUS */
	#define BWID_AVI_BSR_AVI_TS_STATUS_RSVD_31_7	25
	#define BWID_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Empty	1
	#define BWID_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Full	1
	#define BWID_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Loop_Done	1
	#define BWID_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Underrun	1
	#define BWID_AVI_BSR_AVI_TS_STATUS_Address_Error	1
	#define BWID_AVI_BSR_AVI_TS_STATUS_RSVD_1_0	2
	/* Register Bit MASKS for AVI_BSR_AVI_TS_STATUS */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_RSVD_31_7	0xffffff80 /*  */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Empty	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Full	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Loop_Done	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Underrun	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_Address_Error	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVI_BSR_AVI_TS_STATUS_RSVD_1_0	0x00000003 /*  */
	/* Register BITFIELD for AVI_BSR_AVI_TS_STATUS - roff, lsb, width, mask */
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_RSVD_31_7	 0x0004, 7, 25, 0xffffff80
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Empty	 0x0004, 6, 1, 0x00000040
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_PACKET_FIFO_Full	 0x0004, 5, 1, 0x00000020
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Loop_Done	 0x0004, 4, 1, 0x00000010
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_MEM_Agent_Underrun	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_Address_Error	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_AVI_BSR_AVI_TS_STATUS_RSVD_1_0	 0x0004, 0, 2, 0x00000003
#define ROFF_AVI_BSR_AVI_TS_PACKET_COUNT	0x8 /* Pre-Filter Number of Packets Sent (Read only) */ 
	#define BITFIELD_AVI_BSR_AVI_TS_PACKET_COUNT	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_BSR_AVI_TS_CALENDAR	0xc /* Pre-Filter Packet Source if Calendaring is enabled */ 
	#define BITFIELD_AVI_BSR_AVI_TS_CALENDAR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_BSR_AVI_TS_PACKET_FORMAT	0x10 /* Pre-Filter Packet Size and Formatting info */ 
	#define BITFIELD_AVI_BSR_AVI_TS_PACKET_FORMAT	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVI_BSR_AVI_TS_PACKET_FORMAT */
	#define BLSB_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_31_24	24
	#define BLSB_AVI_BSR_AVI_TS_PACKET_FORMAT_Packet_Size	16
	#define BLSB_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_15_8	8
	#define BLSB_AVI_BSR_AVI_TS_PACKET_FORMAT_Num_Valid_Bytes	0
	/* Register Bit Widths for AVI_BSR_AVI_TS_PACKET_FORMAT */
	#define BWID_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_31_24	8
	#define BWID_AVI_BSR_AVI_TS_PACKET_FORMAT_Packet_Size	8
	#define BWID_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_15_8	8
	#define BWID_AVI_BSR_AVI_TS_PACKET_FORMAT_Num_Valid_Bytes	8
	/* Register Bit MASKS for AVI_BSR_AVI_TS_PACKET_FORMAT */
	#define BMSK_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_31_24	0xff000000 /*  */
	#define BMSK_AVI_BSR_AVI_TS_PACKET_FORMAT_Packet_Size	0x00ff0000 /*  */
	#define BMSK_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_15_8	0x0000ff00 /*  */
	#define BMSK_AVI_BSR_AVI_TS_PACKET_FORMAT_Num_Valid_Bytes	0x000000ff /*  */
	/* Register BITFIELD for AVI_BSR_AVI_TS_PACKET_FORMAT - roff, lsb, width, mask */
	#define BITFIELD_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_31_24	 0x0010, 24, 8, 0xff000000
	#define BITFIELD_AVI_BSR_AVI_TS_PACKET_FORMAT_Packet_Size	 0x0010, 16, 8, 0x00ff0000
	#define BITFIELD_AVI_BSR_AVI_TS_PACKET_FORMAT_RSVD_15_8	 0x0010, 8, 8, 0x0000ff00
	#define BITFIELD_AVI_BSR_AVI_TS_PACKET_FORMAT_Num_Valid_Bytes	 0x0010, 0, 8, 0x000000ff
#define ROFF_AVI_BSR_AVI_TS_BUF_START_ADDR	0x14 /* Pre-Filter TS buffer Start Address */ 
	#define BITFIELD_AVI_BSR_AVI_TS_BUF_START_ADDR	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_BSR_AVI_TS_BUF_END_ADDR	0x18 /* Pre-Filter TS buffer End Address */ 
	#define BITFIELD_AVI_BSR_AVI_TS_BUF_END_ADDR	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_BSR_AVI_TS_READ_PTR	0x1c /* Pre-Filter Read Pointer (aligned to frame boundary) */ 
	#define BITFIELD_AVI_BSR_AVI_TS_READ_PTR	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_AVI_BSR_AVI_TS_WRITE_PTR	0x20 /* Pre-Filter Write Pointer (should always be 16-byte aligned 0x010, 0x020...) */ 
	#define BITFIELD_AVI_BSR_AVI_TS_WRITE_PTR	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module AVI SPECIFIC SVEN Events */




#endif /* AVI_REGOFFS_H */
