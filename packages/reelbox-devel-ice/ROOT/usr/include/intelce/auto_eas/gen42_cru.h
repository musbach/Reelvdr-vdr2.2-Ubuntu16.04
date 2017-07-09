#ifndef CRU_REGOFFS_H
#define CRU_REGOFFS_H 1
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


/* Module CRU CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_CRU_0_TM_CMD	0x0 /* Configuration */ 
	#define BITFIELD_CRU_0_TM_CMD	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_TM_CMD */
	#define BLSB_CRU_0_TM_CMD_reserved	11
	#define BLSB_CRU_0_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_0_TM_CMD_M150_300	9
	#define BLSB_CRU_0_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_0_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_0_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_0_TM_CMD_MODE	4
	#define BLSB_CRU_0_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_0_TM_CMD */
	#define BWID_CRU_0_TM_CMD_reserved	21
	#define BWID_CRU_0_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_0_TM_CMD_M150_300	1
	#define BWID_CRU_0_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_0_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_0_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_0_TM_CMD_MODE	2
	#define BWID_CRU_0_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_0_TM_CMD */
	#define BMSK_CRU_0_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_0_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_0_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_0_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_0_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_0_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_0_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_0_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_0_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_TM_CMD_reserved	 0x0000, 11, 21, 0xfffff800
	#define BITFIELD_CRU_0_TM_CMD_VSYNC_SEL	 0x0000, 10, 1, 0x00000400
	#define BITFIELD_CRU_0_TM_CMD_M150_300	 0x0000, 9, 1, 0x00000200
	#define BITFIELD_CRU_0_TM_CMD_M300_BYPASS	 0x0000, 8, 1, 0x00000100
	#define BITFIELD_CRU_0_TM_CMD_COMP_ENABLE	 0x0000, 7, 1, 0x00000080
	#define BITFIELD_CRU_0_TM_CMD_MASTER_CLOCK	 0x0000, 6, 1, 0x00000040
	#define BITFIELD_CRU_0_TM_CMD_MODE	 0x0000, 4, 2, 0x00000030
	#define BITFIELD_CRU_0_TM_CMD_TS_SOURCE	 0x0000, 0, 4, 0x0000000f
#define ROFF_CRU_0_DDS_FREQ	0x8 /* DDS Frequency */ 
	#define BITFIELD_CRU_0_DDS_FREQ	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_DDS_FREQ */
	#define BLSB_CRU_0_DDS_FREQ_reserved	27
	#define BLSB_CRU_0_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_0_DDS_FREQ */
	#define BWID_CRU_0_DDS_FREQ_reserved	5
	#define BWID_CRU_0_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_0_DDS_FREQ */
	#define BMSK_CRU_0_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_0_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_0_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_DDS_FREQ_reserved	 0x0008, 27, 5, 0xf8000000
	#define BITFIELD_CRU_0_DDS_FREQ_DDS_FREQ	 0x0008, 0, 27, 0x07ffffff
#define ROFF_CRU_0_GET_SYSTIME	0xc /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_0_GET_SYSTIME	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_0_SET_STC_LO	0x10 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_0_SET_STC_LO	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_0_SET_STC_HI	0x14 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_0_SET_STC_HI	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_SET_STC_HI */
	#define BLSB_CRU_0_SET_STC_HI_reserved1	25
	#define BLSB_CRU_0_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_0_SET_STC_HI_reserved0	10
	#define BLSB_CRU_0_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_0_SET_STC_HI */
	#define BWID_CRU_0_SET_STC_HI_reserved1	7
	#define BWID_CRU_0_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_0_SET_STC_HI_reserved0	6
	#define BWID_CRU_0_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_0_SET_STC_HI */
	#define BMSK_CRU_0_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_0_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_0_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_0_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_0_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_SET_STC_HI_reserved1	 0x0014, 25, 7, 0xfe000000
	#define BITFIELD_CRU_0_SET_STC_HI_PRESC_SET	 0x0014, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_0_SET_STC_HI_reserved0	 0x0014, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_0_SET_STC_HI_MSB_STC	 0x0014, 0, 10, 0x000003ff
#define ROFF_CRU_0_LAST_TS_LO	0x18 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_0_LAST_TS_LO	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_LAST_TS_LO */
	#define BLSB_CRU_0_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_0_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_0_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_0_LAST_TS_LO */
	#define BWID_CRU_0_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_0_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_0_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_0_LAST_TS_LO */
	#define BMSK_CRU_0_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_0_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_0_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_0_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_LAST_TS_LO_Media_TB_UPD	 0x0018, 31, 1, 0x80000000
	#define BITFIELD_CRU_0_LAST_TS_LO_Unlock_TS	 0x0018, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_0_LAST_TS_LO_Make_SW_TS	 0x0018, 0, 1, 0x00000001
#define ROFF_CRU_0_LAST_TS_HI	0x1c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_0_LAST_TS_HI	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_LAST_TS_HI */
	#define BLSB_CRU_0_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_0_LAST_TS_HI_reserved	25
	#define BLSB_CRU_0_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_0_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_0_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_0_LAST_TS_HI */
	#define BWID_CRU_0_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_0_LAST_TS_HI_reserved	6
	#define BWID_CRU_0_LAST_TS_HI_PRESC	9
	#define BWID_CRU_0_LAST_TS_HI_reserved0	6
	#define BWID_CRU_0_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_0_LAST_TS_HI */
	#define BMSK_CRU_0_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_0_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_0_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_0_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_0_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_0_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_LAST_TS_HI_NEW_TS	 0x001c, 31, 1, 0x80000000
	#define BITFIELD_CRU_0_LAST_TS_HI_reserved	 0x001c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_0_LAST_TS_HI_PRESC	 0x001c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_0_LAST_TS_HI_reserved0	 0x001c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_0_LAST_TS_HI_MSB_STC	 0x001c, 0, 10, 0x000003ff
#define ROFF_CRU_0_COMP_LO	0x20 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_0_COMP_LO	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_0_COMP_HI	0x24 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_0_COMP_HI	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_COMP_HI */
	#define BLSB_CRU_0_COMP_HI_reserved	10
	#define BLSB_CRU_0_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_0_COMP_HI */
	#define BWID_CRU_0_COMP_HI_reserved	22
	#define BWID_CRU_0_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_0_COMP_HI */
	#define BMSK_CRU_0_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_0_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_0_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_COMP_HI_reserved	 0x0024, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_0_COMP_HI_MSB_STC	 0x0024, 0, 10, 0x000003ff
#define ROFF_CRU_0_VSYNC_LO	0x28 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_0_VSYNC_LO	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_0_VSYNC_HI	0x2c /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_0_VSYNC_HI	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_VSYNC_HI */
	#define BLSB_CRU_0_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_0_VSYNC_HI_reserved0	10
	#define BLSB_CRU_0_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_0_VSYNC_HI */
	#define BWID_CRU_0_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_0_VSYNC_HI_reserved0	21
	#define BWID_CRU_0_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_0_VSYNC_HI */
	#define BMSK_CRU_0_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_0_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_0_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_0_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_VSYNC_HI_NEW_VSYNC	 0x002c, 31, 1, 0x80000000
	#define BITFIELD_CRU_0_VSYNC_HI_reserved0	 0x002c, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_0_VSYNC_HI_MSB_STC	 0x002c, 0, 10, 0x000003ff
#define ROFF_CRU_0_STC_LO	0x30 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_0_STC_LO	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_0_STC_HI	0x34 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_0_STC_HI	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_0_STC_HI */
	#define BLSB_CRU_0_STC_HI_reserved	10
	#define BLSB_CRU_0_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_0_STC_HI */
	#define BWID_CRU_0_STC_HI_reserved	22
	#define BWID_CRU_0_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_0_STC_HI */
	#define BMSK_CRU_0_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_0_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_0_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_0_STC_HI_reserved	 0x0034, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_0_STC_HI_MSB_STC	 0x0034, 0, 10, 0x000003ff
#define ROFF_CRU_1_TM_CMD	0x40 /* Configuration */ 
	#define BITFIELD_CRU_1_TM_CMD	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_TM_CMD */
	#define BLSB_CRU_1_TM_CMD_reserved	11
	#define BLSB_CRU_1_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_1_TM_CMD_M150_300	9
	#define BLSB_CRU_1_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_1_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_1_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_1_TM_CMD_MODE	4
	#define BLSB_CRU_1_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_1_TM_CMD */
	#define BWID_CRU_1_TM_CMD_reserved	21
	#define BWID_CRU_1_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_1_TM_CMD_M150_300	1
	#define BWID_CRU_1_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_1_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_1_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_1_TM_CMD_MODE	2
	#define BWID_CRU_1_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_1_TM_CMD */
	#define BMSK_CRU_1_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_1_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_1_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_1_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_1_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_1_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_1_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_1_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_1_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_TM_CMD_reserved	 0x0040, 11, 21, 0xfffff800
	#define BITFIELD_CRU_1_TM_CMD_VSYNC_SEL	 0x0040, 10, 1, 0x00000400
	#define BITFIELD_CRU_1_TM_CMD_M150_300	 0x0040, 9, 1, 0x00000200
	#define BITFIELD_CRU_1_TM_CMD_M300_BYPASS	 0x0040, 8, 1, 0x00000100
	#define BITFIELD_CRU_1_TM_CMD_COMP_ENABLE	 0x0040, 7, 1, 0x00000080
	#define BITFIELD_CRU_1_TM_CMD_MASTER_CLOCK	 0x0040, 6, 1, 0x00000040
	#define BITFIELD_CRU_1_TM_CMD_MODE	 0x0040, 4, 2, 0x00000030
	#define BITFIELD_CRU_1_TM_CMD_TS_SOURCE	 0x0040, 0, 4, 0x0000000f
#define ROFF_CRU_1_DDS_FREQ	0x48 /* DDS Frequency */ 
	#define BITFIELD_CRU_1_DDS_FREQ	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_DDS_FREQ */
	#define BLSB_CRU_1_DDS_FREQ_reserved	27
	#define BLSB_CRU_1_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_1_DDS_FREQ */
	#define BWID_CRU_1_DDS_FREQ_reserved	5
	#define BWID_CRU_1_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_1_DDS_FREQ */
	#define BMSK_CRU_1_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_1_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_1_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_DDS_FREQ_reserved	 0x0048, 27, 5, 0xf8000000
	#define BITFIELD_CRU_1_DDS_FREQ_DDS_FREQ	 0x0048, 0, 27, 0x07ffffff
#define ROFF_CRU_1_GET_SYSTIME	0x4c /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_1_GET_SYSTIME	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_1_SET_STC_LO	0x50 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_1_SET_STC_LO	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_1_SET_STC_HI	0x54 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_1_SET_STC_HI	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_SET_STC_HI */
	#define BLSB_CRU_1_SET_STC_HI_reserved1	25
	#define BLSB_CRU_1_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_1_SET_STC_HI_reserved0	10
	#define BLSB_CRU_1_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_1_SET_STC_HI */
	#define BWID_CRU_1_SET_STC_HI_reserved1	7
	#define BWID_CRU_1_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_1_SET_STC_HI_reserved0	6
	#define BWID_CRU_1_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_1_SET_STC_HI */
	#define BMSK_CRU_1_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_1_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_1_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_1_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_1_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_SET_STC_HI_reserved1	 0x0054, 25, 7, 0xfe000000
	#define BITFIELD_CRU_1_SET_STC_HI_PRESC_SET	 0x0054, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_1_SET_STC_HI_reserved0	 0x0054, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_1_SET_STC_HI_MSB_STC	 0x0054, 0, 10, 0x000003ff
#define ROFF_CRU_1_LAST_TS_LO	0x58 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_1_LAST_TS_LO	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_LAST_TS_LO */
	#define BLSB_CRU_1_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_1_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_1_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_1_LAST_TS_LO */
	#define BWID_CRU_1_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_1_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_1_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_1_LAST_TS_LO */
	#define BMSK_CRU_1_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_1_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_1_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_1_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_LAST_TS_LO_Media_TB_UPD	 0x0058, 31, 1, 0x80000000
	#define BITFIELD_CRU_1_LAST_TS_LO_Unlock_TS	 0x0058, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_1_LAST_TS_LO_Make_SW_TS	 0x0058, 0, 1, 0x00000001
#define ROFF_CRU_1_LAST_TS_HI	0x5c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_1_LAST_TS_HI	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_LAST_TS_HI */
	#define BLSB_CRU_1_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_1_LAST_TS_HI_reserved	25
	#define BLSB_CRU_1_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_1_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_1_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_1_LAST_TS_HI */
	#define BWID_CRU_1_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_1_LAST_TS_HI_reserved	6
	#define BWID_CRU_1_LAST_TS_HI_PRESC	9
	#define BWID_CRU_1_LAST_TS_HI_reserved0	6
	#define BWID_CRU_1_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_1_LAST_TS_HI */
	#define BMSK_CRU_1_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_1_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_1_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_1_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_1_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_1_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_LAST_TS_HI_NEW_TS	 0x005c, 31, 1, 0x80000000
	#define BITFIELD_CRU_1_LAST_TS_HI_reserved	 0x005c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_1_LAST_TS_HI_PRESC	 0x005c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_1_LAST_TS_HI_reserved0	 0x005c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_1_LAST_TS_HI_MSB_STC	 0x005c, 0, 10, 0x000003ff
#define ROFF_CRU_1_COMP_LO	0x60 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_1_COMP_LO	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_1_COMP_HI	0x64 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_1_COMP_HI	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_COMP_HI */
	#define BLSB_CRU_1_COMP_HI_reserved	10
	#define BLSB_CRU_1_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_1_COMP_HI */
	#define BWID_CRU_1_COMP_HI_reserved	22
	#define BWID_CRU_1_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_1_COMP_HI */
	#define BMSK_CRU_1_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_1_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_1_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_COMP_HI_reserved	 0x0064, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_1_COMP_HI_MSB_STC	 0x0064, 0, 10, 0x000003ff
#define ROFF_CRU_1_VSYNC_LO	0x68 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_1_VSYNC_LO	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_1_VSYNC_HI	0x6c /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_1_VSYNC_HI	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_VSYNC_HI */
	#define BLSB_CRU_1_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_1_VSYNC_HI_reserved0	10
	#define BLSB_CRU_1_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_1_VSYNC_HI */
	#define BWID_CRU_1_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_1_VSYNC_HI_reserved0	21
	#define BWID_CRU_1_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_1_VSYNC_HI */
	#define BMSK_CRU_1_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_1_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_1_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_1_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_VSYNC_HI_NEW_VSYNC	 0x006c, 31, 1, 0x80000000
	#define BITFIELD_CRU_1_VSYNC_HI_reserved0	 0x006c, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_1_VSYNC_HI_MSB_STC	 0x006c, 0, 10, 0x000003ff
#define ROFF_CRU_1_STC_LO	0x70 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_1_STC_LO	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_1_STC_HI	0x74 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_1_STC_HI	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_1_STC_HI */
	#define BLSB_CRU_1_STC_HI_reserved	10
	#define BLSB_CRU_1_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_1_STC_HI */
	#define BWID_CRU_1_STC_HI_reserved	22
	#define BWID_CRU_1_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_1_STC_HI */
	#define BMSK_CRU_1_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_1_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_1_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_1_STC_HI_reserved	 0x0074, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_1_STC_HI_MSB_STC	 0x0074, 0, 10, 0x000003ff
#define ROFF_CRU_2_TM_CMD	0x80 /* Configuration */ 
	#define BITFIELD_CRU_2_TM_CMD	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_TM_CMD */
	#define BLSB_CRU_2_TM_CMD_reserved	11
	#define BLSB_CRU_2_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_2_TM_CMD_M150_300	9
	#define BLSB_CRU_2_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_2_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_2_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_2_TM_CMD_MODE	4
	#define BLSB_CRU_2_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_2_TM_CMD */
	#define BWID_CRU_2_TM_CMD_reserved	21
	#define BWID_CRU_2_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_2_TM_CMD_M150_300	1
	#define BWID_CRU_2_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_2_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_2_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_2_TM_CMD_MODE	2
	#define BWID_CRU_2_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_2_TM_CMD */
	#define BMSK_CRU_2_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_2_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_2_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_2_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_2_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_2_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_2_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_2_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_2_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_TM_CMD_reserved	 0x0080, 11, 21, 0xfffff800
	#define BITFIELD_CRU_2_TM_CMD_VSYNC_SEL	 0x0080, 10, 1, 0x00000400
	#define BITFIELD_CRU_2_TM_CMD_M150_300	 0x0080, 9, 1, 0x00000200
	#define BITFIELD_CRU_2_TM_CMD_M300_BYPASS	 0x0080, 8, 1, 0x00000100
	#define BITFIELD_CRU_2_TM_CMD_COMP_ENABLE	 0x0080, 7, 1, 0x00000080
	#define BITFIELD_CRU_2_TM_CMD_MASTER_CLOCK	 0x0080, 6, 1, 0x00000040
	#define BITFIELD_CRU_2_TM_CMD_MODE	 0x0080, 4, 2, 0x00000030
	#define BITFIELD_CRU_2_TM_CMD_TS_SOURCE	 0x0080, 0, 4, 0x0000000f
#define ROFF_CRU_2_DDS_FREQ	0x88 /* DDS Frequency */ 
	#define BITFIELD_CRU_2_DDS_FREQ	 0x0088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_DDS_FREQ */
	#define BLSB_CRU_2_DDS_FREQ_reserved	27
	#define BLSB_CRU_2_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_2_DDS_FREQ */
	#define BWID_CRU_2_DDS_FREQ_reserved	5
	#define BWID_CRU_2_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_2_DDS_FREQ */
	#define BMSK_CRU_2_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_2_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_2_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_DDS_FREQ_reserved	 0x0088, 27, 5, 0xf8000000
	#define BITFIELD_CRU_2_DDS_FREQ_DDS_FREQ	 0x0088, 0, 27, 0x07ffffff
#define ROFF_CRU_2_GET_SYSTIME	0x8c /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_2_GET_SYSTIME	 0x008c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_2_SET_STC_LO	0x90 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_2_SET_STC_LO	 0x0090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_2_SET_STC_HI	0x94 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_2_SET_STC_HI	 0x0094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_SET_STC_HI */
	#define BLSB_CRU_2_SET_STC_HI_reserved1	25
	#define BLSB_CRU_2_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_2_SET_STC_HI_reserved0	10
	#define BLSB_CRU_2_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_2_SET_STC_HI */
	#define BWID_CRU_2_SET_STC_HI_reserved1	7
	#define BWID_CRU_2_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_2_SET_STC_HI_reserved0	6
	#define BWID_CRU_2_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_2_SET_STC_HI */
	#define BMSK_CRU_2_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_2_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_2_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_2_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_2_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_SET_STC_HI_reserved1	 0x0094, 25, 7, 0xfe000000
	#define BITFIELD_CRU_2_SET_STC_HI_PRESC_SET	 0x0094, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_2_SET_STC_HI_reserved0	 0x0094, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_2_SET_STC_HI_MSB_STC	 0x0094, 0, 10, 0x000003ff
#define ROFF_CRU_2_LAST_TS_LO	0x98 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_2_LAST_TS_LO	 0x0098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_LAST_TS_LO */
	#define BLSB_CRU_2_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_2_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_2_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_2_LAST_TS_LO */
	#define BWID_CRU_2_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_2_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_2_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_2_LAST_TS_LO */
	#define BMSK_CRU_2_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_2_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_2_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_2_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_LAST_TS_LO_Media_TB_UPD	 0x0098, 31, 1, 0x80000000
	#define BITFIELD_CRU_2_LAST_TS_LO_Unlock_TS	 0x0098, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_2_LAST_TS_LO_Make_SW_TS	 0x0098, 0, 1, 0x00000001
#define ROFF_CRU_2_LAST_TS_HI	0x9c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_2_LAST_TS_HI	 0x009c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_LAST_TS_HI */
	#define BLSB_CRU_2_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_2_LAST_TS_HI_reserved	25
	#define BLSB_CRU_2_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_2_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_2_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_2_LAST_TS_HI */
	#define BWID_CRU_2_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_2_LAST_TS_HI_reserved	6
	#define BWID_CRU_2_LAST_TS_HI_PRESC	9
	#define BWID_CRU_2_LAST_TS_HI_reserved0	6
	#define BWID_CRU_2_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_2_LAST_TS_HI */
	#define BMSK_CRU_2_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_2_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_2_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_2_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_2_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_2_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_LAST_TS_HI_NEW_TS	 0x009c, 31, 1, 0x80000000
	#define BITFIELD_CRU_2_LAST_TS_HI_reserved	 0x009c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_2_LAST_TS_HI_PRESC	 0x009c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_2_LAST_TS_HI_reserved0	 0x009c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_2_LAST_TS_HI_MSB_STC	 0x009c, 0, 10, 0x000003ff
#define ROFF_CRU_2_COMP_LO	0xa0 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_2_COMP_LO	 0x00a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_2_COMP_HI	0xa4 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_2_COMP_HI	 0x00a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_COMP_HI */
	#define BLSB_CRU_2_COMP_HI_reserved	10
	#define BLSB_CRU_2_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_2_COMP_HI */
	#define BWID_CRU_2_COMP_HI_reserved	22
	#define BWID_CRU_2_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_2_COMP_HI */
	#define BMSK_CRU_2_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_2_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_2_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_COMP_HI_reserved	 0x00a4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_2_COMP_HI_MSB_STC	 0x00a4, 0, 10, 0x000003ff
#define ROFF_CRU_2_VSYNC_LO	0xa8 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_2_VSYNC_LO	 0x00a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_2_VSYNC_HI	0xac /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_2_VSYNC_HI	 0x00ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_VSYNC_HI */
	#define BLSB_CRU_2_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_2_VSYNC_HI_reserved0	10
	#define BLSB_CRU_2_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_2_VSYNC_HI */
	#define BWID_CRU_2_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_2_VSYNC_HI_reserved0	21
	#define BWID_CRU_2_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_2_VSYNC_HI */
	#define BMSK_CRU_2_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_2_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_2_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_2_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_VSYNC_HI_NEW_VSYNC	 0x00ac, 31, 1, 0x80000000
	#define BITFIELD_CRU_2_VSYNC_HI_reserved0	 0x00ac, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_2_VSYNC_HI_MSB_STC	 0x00ac, 0, 10, 0x000003ff
#define ROFF_CRU_2_STC_LO	0xb0 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_2_STC_LO	 0x00b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_2_STC_HI	0xb4 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_2_STC_HI	 0x00b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_2_STC_HI */
	#define BLSB_CRU_2_STC_HI_reserved	10
	#define BLSB_CRU_2_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_2_STC_HI */
	#define BWID_CRU_2_STC_HI_reserved	22
	#define BWID_CRU_2_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_2_STC_HI */
	#define BMSK_CRU_2_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_2_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_2_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_2_STC_HI_reserved	 0x00b4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_2_STC_HI_MSB_STC	 0x00b4, 0, 10, 0x000003ff
#define ROFF_CRU_3_TM_CMD	0xc0 /* Configuration */ 
	#define BITFIELD_CRU_3_TM_CMD	 0x00c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_TM_CMD */
	#define BLSB_CRU_3_TM_CMD_reserved	11
	#define BLSB_CRU_3_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_3_TM_CMD_M150_300	9
	#define BLSB_CRU_3_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_3_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_3_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_3_TM_CMD_MODE	4
	#define BLSB_CRU_3_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_3_TM_CMD */
	#define BWID_CRU_3_TM_CMD_reserved	21
	#define BWID_CRU_3_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_3_TM_CMD_M150_300	1
	#define BWID_CRU_3_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_3_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_3_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_3_TM_CMD_MODE	2
	#define BWID_CRU_3_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_3_TM_CMD */
	#define BMSK_CRU_3_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_3_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_3_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_3_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_3_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_3_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_3_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_3_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_3_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_TM_CMD_reserved	 0x00c0, 11, 21, 0xfffff800
	#define BITFIELD_CRU_3_TM_CMD_VSYNC_SEL	 0x00c0, 10, 1, 0x00000400
	#define BITFIELD_CRU_3_TM_CMD_M150_300	 0x00c0, 9, 1, 0x00000200
	#define BITFIELD_CRU_3_TM_CMD_M300_BYPASS	 0x00c0, 8, 1, 0x00000100
	#define BITFIELD_CRU_3_TM_CMD_COMP_ENABLE	 0x00c0, 7, 1, 0x00000080
	#define BITFIELD_CRU_3_TM_CMD_MASTER_CLOCK	 0x00c0, 6, 1, 0x00000040
	#define BITFIELD_CRU_3_TM_CMD_MODE	 0x00c0, 4, 2, 0x00000030
	#define BITFIELD_CRU_3_TM_CMD_TS_SOURCE	 0x00c0, 0, 4, 0x0000000f
#define ROFF_CRU_3_DDS_FREQ	0xc8 /* DDS Frequency */ 
	#define BITFIELD_CRU_3_DDS_FREQ	 0x00c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_DDS_FREQ */
	#define BLSB_CRU_3_DDS_FREQ_reserved	27
	#define BLSB_CRU_3_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_3_DDS_FREQ */
	#define BWID_CRU_3_DDS_FREQ_reserved	5
	#define BWID_CRU_3_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_3_DDS_FREQ */
	#define BMSK_CRU_3_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_3_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_3_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_DDS_FREQ_reserved	 0x00c8, 27, 5, 0xf8000000
	#define BITFIELD_CRU_3_DDS_FREQ_DDS_FREQ	 0x00c8, 0, 27, 0x07ffffff
#define ROFF_CRU_3_GET_SYSTIME	0xcc /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_3_GET_SYSTIME	 0x00cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_3_SET_STC_LO	0xd0 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_3_SET_STC_LO	 0x00d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_3_SET_STC_HI	0xd4 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_3_SET_STC_HI	 0x00d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_SET_STC_HI */
	#define BLSB_CRU_3_SET_STC_HI_reserved1	25
	#define BLSB_CRU_3_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_3_SET_STC_HI_reserved0	10
	#define BLSB_CRU_3_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_3_SET_STC_HI */
	#define BWID_CRU_3_SET_STC_HI_reserved1	7
	#define BWID_CRU_3_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_3_SET_STC_HI_reserved0	6
	#define BWID_CRU_3_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_3_SET_STC_HI */
	#define BMSK_CRU_3_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_3_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_3_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_3_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_3_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_SET_STC_HI_reserved1	 0x00d4, 25, 7, 0xfe000000
	#define BITFIELD_CRU_3_SET_STC_HI_PRESC_SET	 0x00d4, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_3_SET_STC_HI_reserved0	 0x00d4, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_3_SET_STC_HI_MSB_STC	 0x00d4, 0, 10, 0x000003ff
#define ROFF_CRU_3_LAST_TS_LO	0xd8 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_3_LAST_TS_LO	 0x00d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_LAST_TS_LO */
	#define BLSB_CRU_3_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_3_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_3_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_3_LAST_TS_LO */
	#define BWID_CRU_3_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_3_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_3_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_3_LAST_TS_LO */
	#define BMSK_CRU_3_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_3_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_3_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_3_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_LAST_TS_LO_Media_TB_UPD	 0x00d8, 31, 1, 0x80000000
	#define BITFIELD_CRU_3_LAST_TS_LO_Unlock_TS	 0x00d8, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_3_LAST_TS_LO_Make_SW_TS	 0x00d8, 0, 1, 0x00000001
#define ROFF_CRU_3_LAST_TS_HI	0xdc /* Most significant bit of STC */ 
	#define BITFIELD_CRU_3_LAST_TS_HI	 0x00dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_LAST_TS_HI */
	#define BLSB_CRU_3_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_3_LAST_TS_HI_reserved	25
	#define BLSB_CRU_3_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_3_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_3_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_3_LAST_TS_HI */
	#define BWID_CRU_3_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_3_LAST_TS_HI_reserved	6
	#define BWID_CRU_3_LAST_TS_HI_PRESC	9
	#define BWID_CRU_3_LAST_TS_HI_reserved0	6
	#define BWID_CRU_3_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_3_LAST_TS_HI */
	#define BMSK_CRU_3_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_3_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_3_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_3_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_3_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_3_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_LAST_TS_HI_NEW_TS	 0x00dc, 31, 1, 0x80000000
	#define BITFIELD_CRU_3_LAST_TS_HI_reserved	 0x00dc, 25, 6, 0x7e000000
	#define BITFIELD_CRU_3_LAST_TS_HI_PRESC	 0x00dc, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_3_LAST_TS_HI_reserved0	 0x00dc, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_3_LAST_TS_HI_MSB_STC	 0x00dc, 0, 10, 0x000003ff
#define ROFF_CRU_3_COMP_LO	0xe0 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_3_COMP_LO	 0x00e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_3_COMP_HI	0xe4 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_3_COMP_HI	 0x00e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_COMP_HI */
	#define BLSB_CRU_3_COMP_HI_reserved	10
	#define BLSB_CRU_3_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_3_COMP_HI */
	#define BWID_CRU_3_COMP_HI_reserved	22
	#define BWID_CRU_3_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_3_COMP_HI */
	#define BMSK_CRU_3_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_3_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_3_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_COMP_HI_reserved	 0x00e4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_3_COMP_HI_MSB_STC	 0x00e4, 0, 10, 0x000003ff
#define ROFF_CRU_3_VSYNC_LO	0xe8 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_3_VSYNC_LO	 0x00e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_3_VSYNC_HI	0xec /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_3_VSYNC_HI	 0x00ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_VSYNC_HI */
	#define BLSB_CRU_3_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_3_VSYNC_HI_reserved0	10
	#define BLSB_CRU_3_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_3_VSYNC_HI */
	#define BWID_CRU_3_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_3_VSYNC_HI_reserved0	21
	#define BWID_CRU_3_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_3_VSYNC_HI */
	#define BMSK_CRU_3_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_3_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_3_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_3_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_VSYNC_HI_NEW_VSYNC	 0x00ec, 31, 1, 0x80000000
	#define BITFIELD_CRU_3_VSYNC_HI_reserved0	 0x00ec, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_3_VSYNC_HI_MSB_STC	 0x00ec, 0, 10, 0x000003ff
#define ROFF_CRU_3_STC_LO	0xf0 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_3_STC_LO	 0x00f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_3_STC_HI	0xf4 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_3_STC_HI	 0x00f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_3_STC_HI */
	#define BLSB_CRU_3_STC_HI_reserved	10
	#define BLSB_CRU_3_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_3_STC_HI */
	#define BWID_CRU_3_STC_HI_reserved	22
	#define BWID_CRU_3_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_3_STC_HI */
	#define BMSK_CRU_3_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_3_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_3_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_3_STC_HI_reserved	 0x00f4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_3_STC_HI_MSB_STC	 0x00f4, 0, 10, 0x000003ff
#define ROFF_CRU_4_TM_CMD	0x100 /* Configuration */ 
	#define BITFIELD_CRU_4_TM_CMD	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_TM_CMD */
	#define BLSB_CRU_4_TM_CMD_reserved	11
	#define BLSB_CRU_4_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_4_TM_CMD_M150_300	9
	#define BLSB_CRU_4_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_4_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_4_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_4_TM_CMD_MODE	4
	#define BLSB_CRU_4_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_4_TM_CMD */
	#define BWID_CRU_4_TM_CMD_reserved	21
	#define BWID_CRU_4_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_4_TM_CMD_M150_300	1
	#define BWID_CRU_4_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_4_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_4_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_4_TM_CMD_MODE	2
	#define BWID_CRU_4_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_4_TM_CMD */
	#define BMSK_CRU_4_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_4_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_4_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_4_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_4_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_4_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_4_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_4_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_4_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_TM_CMD_reserved	 0x0100, 11, 21, 0xfffff800
	#define BITFIELD_CRU_4_TM_CMD_VSYNC_SEL	 0x0100, 10, 1, 0x00000400
	#define BITFIELD_CRU_4_TM_CMD_M150_300	 0x0100, 9, 1, 0x00000200
	#define BITFIELD_CRU_4_TM_CMD_M300_BYPASS	 0x0100, 8, 1, 0x00000100
	#define BITFIELD_CRU_4_TM_CMD_COMP_ENABLE	 0x0100, 7, 1, 0x00000080
	#define BITFIELD_CRU_4_TM_CMD_MASTER_CLOCK	 0x0100, 6, 1, 0x00000040
	#define BITFIELD_CRU_4_TM_CMD_MODE	 0x0100, 4, 2, 0x00000030
	#define BITFIELD_CRU_4_TM_CMD_TS_SOURCE	 0x0100, 0, 4, 0x0000000f
#define ROFF_CRU_4_DDS_FREQ	0x108 /* DDS Frequency */ 
	#define BITFIELD_CRU_4_DDS_FREQ	 0x0108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_DDS_FREQ */
	#define BLSB_CRU_4_DDS_FREQ_reserved	27
	#define BLSB_CRU_4_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_4_DDS_FREQ */
	#define BWID_CRU_4_DDS_FREQ_reserved	5
	#define BWID_CRU_4_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_4_DDS_FREQ */
	#define BMSK_CRU_4_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_4_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_4_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_DDS_FREQ_reserved	 0x0108, 27, 5, 0xf8000000
	#define BITFIELD_CRU_4_DDS_FREQ_DDS_FREQ	 0x0108, 0, 27, 0x07ffffff
#define ROFF_CRU_4_GET_SYSTIME	0x10c /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_4_GET_SYSTIME	 0x010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_4_SET_STC_LO	0x110 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_4_SET_STC_LO	 0x0110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_4_SET_STC_HI	0x114 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_4_SET_STC_HI	 0x0114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_SET_STC_HI */
	#define BLSB_CRU_4_SET_STC_HI_reserved1	25
	#define BLSB_CRU_4_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_4_SET_STC_HI_reserved0	10
	#define BLSB_CRU_4_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_4_SET_STC_HI */
	#define BWID_CRU_4_SET_STC_HI_reserved1	7
	#define BWID_CRU_4_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_4_SET_STC_HI_reserved0	6
	#define BWID_CRU_4_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_4_SET_STC_HI */
	#define BMSK_CRU_4_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_4_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_4_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_4_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_4_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_SET_STC_HI_reserved1	 0x0114, 25, 7, 0xfe000000
	#define BITFIELD_CRU_4_SET_STC_HI_PRESC_SET	 0x0114, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_4_SET_STC_HI_reserved0	 0x0114, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_4_SET_STC_HI_MSB_STC	 0x0114, 0, 10, 0x000003ff
#define ROFF_CRU_4_LAST_TS_LO	0x118 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_4_LAST_TS_LO	 0x0118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_LAST_TS_LO */
	#define BLSB_CRU_4_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_4_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_4_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_4_LAST_TS_LO */
	#define BWID_CRU_4_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_4_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_4_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_4_LAST_TS_LO */
	#define BMSK_CRU_4_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_4_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_4_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_4_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_LAST_TS_LO_Media_TB_UPD	 0x0118, 31, 1, 0x80000000
	#define BITFIELD_CRU_4_LAST_TS_LO_Unlock_TS	 0x0118, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_4_LAST_TS_LO_Make_SW_TS	 0x0118, 0, 1, 0x00000001
#define ROFF_CRU_4_LAST_TS_HI	0x11c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_4_LAST_TS_HI	 0x011c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_LAST_TS_HI */
	#define BLSB_CRU_4_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_4_LAST_TS_HI_reserved	25
	#define BLSB_CRU_4_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_4_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_4_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_4_LAST_TS_HI */
	#define BWID_CRU_4_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_4_LAST_TS_HI_reserved	6
	#define BWID_CRU_4_LAST_TS_HI_PRESC	9
	#define BWID_CRU_4_LAST_TS_HI_reserved0	6
	#define BWID_CRU_4_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_4_LAST_TS_HI */
	#define BMSK_CRU_4_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_4_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_4_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_4_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_4_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_4_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_LAST_TS_HI_NEW_TS	 0x011c, 31, 1, 0x80000000
	#define BITFIELD_CRU_4_LAST_TS_HI_reserved	 0x011c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_4_LAST_TS_HI_PRESC	 0x011c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_4_LAST_TS_HI_reserved0	 0x011c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_4_LAST_TS_HI_MSB_STC	 0x011c, 0, 10, 0x000003ff
#define ROFF_CRU_4_COMP_LO	0x120 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_4_COMP_LO	 0x0120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_4_COMP_HI	0x124 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_4_COMP_HI	 0x0124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_COMP_HI */
	#define BLSB_CRU_4_COMP_HI_reserved	10
	#define BLSB_CRU_4_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_4_COMP_HI */
	#define BWID_CRU_4_COMP_HI_reserved	22
	#define BWID_CRU_4_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_4_COMP_HI */
	#define BMSK_CRU_4_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_4_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_4_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_COMP_HI_reserved	 0x0124, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_4_COMP_HI_MSB_STC	 0x0124, 0, 10, 0x000003ff
#define ROFF_CRU_4_VSYNC_LO	0x128 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_4_VSYNC_LO	 0x0128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_4_VSYNC_HI	0x12c /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_4_VSYNC_HI	 0x012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_VSYNC_HI */
	#define BLSB_CRU_4_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_4_VSYNC_HI_reserved0	10
	#define BLSB_CRU_4_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_4_VSYNC_HI */
	#define BWID_CRU_4_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_4_VSYNC_HI_reserved0	21
	#define BWID_CRU_4_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_4_VSYNC_HI */
	#define BMSK_CRU_4_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_4_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_4_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_4_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_VSYNC_HI_NEW_VSYNC	 0x012c, 31, 1, 0x80000000
	#define BITFIELD_CRU_4_VSYNC_HI_reserved0	 0x012c, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_4_VSYNC_HI_MSB_STC	 0x012c, 0, 10, 0x000003ff
#define ROFF_CRU_4_STC_LO	0x130 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_4_STC_LO	 0x0130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_4_STC_HI	0x134 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_4_STC_HI	 0x0134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_4_STC_HI */
	#define BLSB_CRU_4_STC_HI_reserved	10
	#define BLSB_CRU_4_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_4_STC_HI */
	#define BWID_CRU_4_STC_HI_reserved	22
	#define BWID_CRU_4_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_4_STC_HI */
	#define BMSK_CRU_4_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_4_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_4_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_4_STC_HI_reserved	 0x0134, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_4_STC_HI_MSB_STC	 0x0134, 0, 10, 0x000003ff
#define ROFF_CRU_5_TM_CMD	0x140 /* Configuration */ 
	#define BITFIELD_CRU_5_TM_CMD	 0x0140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_TM_CMD */
	#define BLSB_CRU_5_TM_CMD_reserved	11
	#define BLSB_CRU_5_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_5_TM_CMD_M150_300	9
	#define BLSB_CRU_5_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_5_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_5_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_5_TM_CMD_MODE	4
	#define BLSB_CRU_5_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_5_TM_CMD */
	#define BWID_CRU_5_TM_CMD_reserved	21
	#define BWID_CRU_5_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_5_TM_CMD_M150_300	1
	#define BWID_CRU_5_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_5_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_5_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_5_TM_CMD_MODE	2
	#define BWID_CRU_5_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_5_TM_CMD */
	#define BMSK_CRU_5_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_5_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_5_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_5_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_5_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_5_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_5_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_5_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_5_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_TM_CMD_reserved	 0x0140, 11, 21, 0xfffff800
	#define BITFIELD_CRU_5_TM_CMD_VSYNC_SEL	 0x0140, 10, 1, 0x00000400
	#define BITFIELD_CRU_5_TM_CMD_M150_300	 0x0140, 9, 1, 0x00000200
	#define BITFIELD_CRU_5_TM_CMD_M300_BYPASS	 0x0140, 8, 1, 0x00000100
	#define BITFIELD_CRU_5_TM_CMD_COMP_ENABLE	 0x0140, 7, 1, 0x00000080
	#define BITFIELD_CRU_5_TM_CMD_MASTER_CLOCK	 0x0140, 6, 1, 0x00000040
	#define BITFIELD_CRU_5_TM_CMD_MODE	 0x0140, 4, 2, 0x00000030
	#define BITFIELD_CRU_5_TM_CMD_TS_SOURCE	 0x0140, 0, 4, 0x0000000f
#define ROFF_CRU_5_DDS_FREQ	0x148 /* DDS Frequency */ 
	#define BITFIELD_CRU_5_DDS_FREQ	 0x0148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_DDS_FREQ */
	#define BLSB_CRU_5_DDS_FREQ_reserved	27
	#define BLSB_CRU_5_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_5_DDS_FREQ */
	#define BWID_CRU_5_DDS_FREQ_reserved	5
	#define BWID_CRU_5_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_5_DDS_FREQ */
	#define BMSK_CRU_5_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_5_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_5_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_DDS_FREQ_reserved	 0x0148, 27, 5, 0xf8000000
	#define BITFIELD_CRU_5_DDS_FREQ_DDS_FREQ	 0x0148, 0, 27, 0x07ffffff
#define ROFF_CRU_5_GET_SYSTIME	0x14c /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_5_GET_SYSTIME	 0x014c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_5_SET_STC_LO	0x150 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_5_SET_STC_LO	 0x0150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_5_SET_STC_HI	0x154 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_5_SET_STC_HI	 0x0154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_SET_STC_HI */
	#define BLSB_CRU_5_SET_STC_HI_reserved1	25
	#define BLSB_CRU_5_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_5_SET_STC_HI_reserved0	10
	#define BLSB_CRU_5_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_5_SET_STC_HI */
	#define BWID_CRU_5_SET_STC_HI_reserved1	7
	#define BWID_CRU_5_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_5_SET_STC_HI_reserved0	6
	#define BWID_CRU_5_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_5_SET_STC_HI */
	#define BMSK_CRU_5_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_5_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_5_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_5_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_5_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_SET_STC_HI_reserved1	 0x0154, 25, 7, 0xfe000000
	#define BITFIELD_CRU_5_SET_STC_HI_PRESC_SET	 0x0154, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_5_SET_STC_HI_reserved0	 0x0154, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_5_SET_STC_HI_MSB_STC	 0x0154, 0, 10, 0x000003ff
#define ROFF_CRU_5_LAST_TS_LO	0x158 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_5_LAST_TS_LO	 0x0158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_LAST_TS_LO */
	#define BLSB_CRU_5_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_5_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_5_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_5_LAST_TS_LO */
	#define BWID_CRU_5_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_5_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_5_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_5_LAST_TS_LO */
	#define BMSK_CRU_5_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_5_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_5_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_5_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_LAST_TS_LO_Media_TB_UPD	 0x0158, 31, 1, 0x80000000
	#define BITFIELD_CRU_5_LAST_TS_LO_Unlock_TS	 0x0158, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_5_LAST_TS_LO_Make_SW_TS	 0x0158, 0, 1, 0x00000001
#define ROFF_CRU_5_LAST_TS_HI	0x15c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_5_LAST_TS_HI	 0x015c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_LAST_TS_HI */
	#define BLSB_CRU_5_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_5_LAST_TS_HI_reserved	25
	#define BLSB_CRU_5_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_5_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_5_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_5_LAST_TS_HI */
	#define BWID_CRU_5_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_5_LAST_TS_HI_reserved	6
	#define BWID_CRU_5_LAST_TS_HI_PRESC	9
	#define BWID_CRU_5_LAST_TS_HI_reserved0	6
	#define BWID_CRU_5_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_5_LAST_TS_HI */
	#define BMSK_CRU_5_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_5_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_5_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_5_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_5_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_5_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_LAST_TS_HI_NEW_TS	 0x015c, 31, 1, 0x80000000
	#define BITFIELD_CRU_5_LAST_TS_HI_reserved	 0x015c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_5_LAST_TS_HI_PRESC	 0x015c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_5_LAST_TS_HI_reserved0	 0x015c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_5_LAST_TS_HI_MSB_STC	 0x015c, 0, 10, 0x000003ff
#define ROFF_CRU_5_COMP_LO	0x160 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_5_COMP_LO	 0x0160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_5_COMP_HI	0x164 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_5_COMP_HI	 0x0164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_COMP_HI */
	#define BLSB_CRU_5_COMP_HI_reserved	10
	#define BLSB_CRU_5_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_5_COMP_HI */
	#define BWID_CRU_5_COMP_HI_reserved	22
	#define BWID_CRU_5_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_5_COMP_HI */
	#define BMSK_CRU_5_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_5_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_5_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_COMP_HI_reserved	 0x0164, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_5_COMP_HI_MSB_STC	 0x0164, 0, 10, 0x000003ff
#define ROFF_CRU_5_VSYNC_LO	0x168 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_5_VSYNC_LO	 0x0168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_5_VSYNC_HI	0x16c /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_5_VSYNC_HI	 0x016c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_VSYNC_HI */
	#define BLSB_CRU_5_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_5_VSYNC_HI_reserved0	10
	#define BLSB_CRU_5_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_5_VSYNC_HI */
	#define BWID_CRU_5_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_5_VSYNC_HI_reserved0	21
	#define BWID_CRU_5_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_5_VSYNC_HI */
	#define BMSK_CRU_5_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_5_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_5_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_5_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_VSYNC_HI_NEW_VSYNC	 0x016c, 31, 1, 0x80000000
	#define BITFIELD_CRU_5_VSYNC_HI_reserved0	 0x016c, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_5_VSYNC_HI_MSB_STC	 0x016c, 0, 10, 0x000003ff
#define ROFF_CRU_5_STC_LO	0x170 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_5_STC_LO	 0x0170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_5_STC_HI	0x174 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_5_STC_HI	 0x0174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_5_STC_HI */
	#define BLSB_CRU_5_STC_HI_reserved	10
	#define BLSB_CRU_5_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_5_STC_HI */
	#define BWID_CRU_5_STC_HI_reserved	22
	#define BWID_CRU_5_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_5_STC_HI */
	#define BMSK_CRU_5_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_5_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_5_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_5_STC_HI_reserved	 0x0174, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_5_STC_HI_MSB_STC	 0x0174, 0, 10, 0x000003ff
#define ROFF_CRU_6_TM_CMD	0x180 /* Configuration */ 
	#define BITFIELD_CRU_6_TM_CMD	 0x0180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_TM_CMD */
	#define BLSB_CRU_6_TM_CMD_reserved	11
	#define BLSB_CRU_6_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_6_TM_CMD_M150_300	9
	#define BLSB_CRU_6_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_6_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_6_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_6_TM_CMD_MODE	4
	#define BLSB_CRU_6_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_6_TM_CMD */
	#define BWID_CRU_6_TM_CMD_reserved	21
	#define BWID_CRU_6_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_6_TM_CMD_M150_300	1
	#define BWID_CRU_6_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_6_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_6_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_6_TM_CMD_MODE	2
	#define BWID_CRU_6_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_6_TM_CMD */
	#define BMSK_CRU_6_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_6_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_6_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_6_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_6_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_6_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_6_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_6_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_6_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_TM_CMD_reserved	 0x0180, 11, 21, 0xfffff800
	#define BITFIELD_CRU_6_TM_CMD_VSYNC_SEL	 0x0180, 10, 1, 0x00000400
	#define BITFIELD_CRU_6_TM_CMD_M150_300	 0x0180, 9, 1, 0x00000200
	#define BITFIELD_CRU_6_TM_CMD_M300_BYPASS	 0x0180, 8, 1, 0x00000100
	#define BITFIELD_CRU_6_TM_CMD_COMP_ENABLE	 0x0180, 7, 1, 0x00000080
	#define BITFIELD_CRU_6_TM_CMD_MASTER_CLOCK	 0x0180, 6, 1, 0x00000040
	#define BITFIELD_CRU_6_TM_CMD_MODE	 0x0180, 4, 2, 0x00000030
	#define BITFIELD_CRU_6_TM_CMD_TS_SOURCE	 0x0180, 0, 4, 0x0000000f
#define ROFF_CRU_6_DDS_FREQ	0x188 /* DDS Frequency */ 
	#define BITFIELD_CRU_6_DDS_FREQ	 0x0188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_DDS_FREQ */
	#define BLSB_CRU_6_DDS_FREQ_reserved	27
	#define BLSB_CRU_6_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_6_DDS_FREQ */
	#define BWID_CRU_6_DDS_FREQ_reserved	5
	#define BWID_CRU_6_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_6_DDS_FREQ */
	#define BMSK_CRU_6_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_6_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_6_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_DDS_FREQ_reserved	 0x0188, 27, 5, 0xf8000000
	#define BITFIELD_CRU_6_DDS_FREQ_DDS_FREQ	 0x0188, 0, 27, 0x07ffffff
#define ROFF_CRU_6_GET_SYSTIME	0x18c /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_6_GET_SYSTIME	 0x018c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_6_SET_STC_LO	0x190 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_6_SET_STC_LO	 0x0190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_6_SET_STC_HI	0x194 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_6_SET_STC_HI	 0x0194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_SET_STC_HI */
	#define BLSB_CRU_6_SET_STC_HI_reserved1	25
	#define BLSB_CRU_6_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_6_SET_STC_HI_reserved0	10
	#define BLSB_CRU_6_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_6_SET_STC_HI */
	#define BWID_CRU_6_SET_STC_HI_reserved1	7
	#define BWID_CRU_6_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_6_SET_STC_HI_reserved0	6
	#define BWID_CRU_6_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_6_SET_STC_HI */
	#define BMSK_CRU_6_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_6_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_6_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_6_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_6_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_SET_STC_HI_reserved1	 0x0194, 25, 7, 0xfe000000
	#define BITFIELD_CRU_6_SET_STC_HI_PRESC_SET	 0x0194, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_6_SET_STC_HI_reserved0	 0x0194, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_6_SET_STC_HI_MSB_STC	 0x0194, 0, 10, 0x000003ff
#define ROFF_CRU_6_LAST_TS_LO	0x198 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_6_LAST_TS_LO	 0x0198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_LAST_TS_LO */
	#define BLSB_CRU_6_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_6_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_6_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_6_LAST_TS_LO */
	#define BWID_CRU_6_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_6_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_6_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_6_LAST_TS_LO */
	#define BMSK_CRU_6_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_6_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_6_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_6_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_LAST_TS_LO_Media_TB_UPD	 0x0198, 31, 1, 0x80000000
	#define BITFIELD_CRU_6_LAST_TS_LO_Unlock_TS	 0x0198, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_6_LAST_TS_LO_Make_SW_TS	 0x0198, 0, 1, 0x00000001
#define ROFF_CRU_6_LAST_TS_HI	0x19c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_6_LAST_TS_HI	 0x019c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_LAST_TS_HI */
	#define BLSB_CRU_6_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_6_LAST_TS_HI_reserved	25
	#define BLSB_CRU_6_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_6_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_6_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_6_LAST_TS_HI */
	#define BWID_CRU_6_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_6_LAST_TS_HI_reserved	6
	#define BWID_CRU_6_LAST_TS_HI_PRESC	9
	#define BWID_CRU_6_LAST_TS_HI_reserved0	6
	#define BWID_CRU_6_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_6_LAST_TS_HI */
	#define BMSK_CRU_6_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_6_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_6_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_6_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_6_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_6_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_LAST_TS_HI_NEW_TS	 0x019c, 31, 1, 0x80000000
	#define BITFIELD_CRU_6_LAST_TS_HI_reserved	 0x019c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_6_LAST_TS_HI_PRESC	 0x019c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_6_LAST_TS_HI_reserved0	 0x019c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_6_LAST_TS_HI_MSB_STC	 0x019c, 0, 10, 0x000003ff
#define ROFF_CRU_6_COMP_LO	0x1a0 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_6_COMP_LO	 0x01a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_6_COMP_HI	0x1a4 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_6_COMP_HI	 0x01a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_COMP_HI */
	#define BLSB_CRU_6_COMP_HI_reserved	10
	#define BLSB_CRU_6_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_6_COMP_HI */
	#define BWID_CRU_6_COMP_HI_reserved	22
	#define BWID_CRU_6_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_6_COMP_HI */
	#define BMSK_CRU_6_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_6_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_6_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_COMP_HI_reserved	 0x01a4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_6_COMP_HI_MSB_STC	 0x01a4, 0, 10, 0x000003ff
#define ROFF_CRU_6_VSYNC_LO	0x1a8 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_6_VSYNC_LO	 0x01a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_6_VSYNC_HI	0x1ac /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_6_VSYNC_HI	 0x01ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_VSYNC_HI */
	#define BLSB_CRU_6_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_6_VSYNC_HI_reserved0	10
	#define BLSB_CRU_6_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_6_VSYNC_HI */
	#define BWID_CRU_6_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_6_VSYNC_HI_reserved0	21
	#define BWID_CRU_6_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_6_VSYNC_HI */
	#define BMSK_CRU_6_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_6_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_6_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_6_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_VSYNC_HI_NEW_VSYNC	 0x01ac, 31, 1, 0x80000000
	#define BITFIELD_CRU_6_VSYNC_HI_reserved0	 0x01ac, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_6_VSYNC_HI_MSB_STC	 0x01ac, 0, 10, 0x000003ff
#define ROFF_CRU_6_STC_LO	0x1b0 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_6_STC_LO	 0x01b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_6_STC_HI	0x1b4 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_6_STC_HI	 0x01b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_6_STC_HI */
	#define BLSB_CRU_6_STC_HI_reserved	10
	#define BLSB_CRU_6_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_6_STC_HI */
	#define BWID_CRU_6_STC_HI_reserved	22
	#define BWID_CRU_6_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_6_STC_HI */
	#define BMSK_CRU_6_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_6_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_6_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_6_STC_HI_reserved	 0x01b4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_6_STC_HI_MSB_STC	 0x01b4, 0, 10, 0x000003ff
#define ROFF_CRU_7_TM_CMD	0x1c0 /* Configuration */ 
	#define BITFIELD_CRU_7_TM_CMD	 0x01c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_TM_CMD */
	#define BLSB_CRU_7_TM_CMD_reserved	11
	#define BLSB_CRU_7_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_7_TM_CMD_M150_300	9
	#define BLSB_CRU_7_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_7_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_7_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_7_TM_CMD_MODE	4
	#define BLSB_CRU_7_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_7_TM_CMD */
	#define BWID_CRU_7_TM_CMD_reserved	21
	#define BWID_CRU_7_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_7_TM_CMD_M150_300	1
	#define BWID_CRU_7_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_7_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_7_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_7_TM_CMD_MODE	2
	#define BWID_CRU_7_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_7_TM_CMD */
	#define BMSK_CRU_7_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_7_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_7_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_7_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_7_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_7_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_7_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_7_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_7_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_TM_CMD_reserved	 0x01c0, 11, 21, 0xfffff800
	#define BITFIELD_CRU_7_TM_CMD_VSYNC_SEL	 0x01c0, 10, 1, 0x00000400
	#define BITFIELD_CRU_7_TM_CMD_M150_300	 0x01c0, 9, 1, 0x00000200
	#define BITFIELD_CRU_7_TM_CMD_M300_BYPASS	 0x01c0, 8, 1, 0x00000100
	#define BITFIELD_CRU_7_TM_CMD_COMP_ENABLE	 0x01c0, 7, 1, 0x00000080
	#define BITFIELD_CRU_7_TM_CMD_MASTER_CLOCK	 0x01c0, 6, 1, 0x00000040
	#define BITFIELD_CRU_7_TM_CMD_MODE	 0x01c0, 4, 2, 0x00000030
	#define BITFIELD_CRU_7_TM_CMD_TS_SOURCE	 0x01c0, 0, 4, 0x0000000f
#define ROFF_CRU_7_DDS_FREQ	0x1c8 /* DDS Frequency */ 
	#define BITFIELD_CRU_7_DDS_FREQ	 0x01c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_DDS_FREQ */
	#define BLSB_CRU_7_DDS_FREQ_reserved	27
	#define BLSB_CRU_7_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_7_DDS_FREQ */
	#define BWID_CRU_7_DDS_FREQ_reserved	5
	#define BWID_CRU_7_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_7_DDS_FREQ */
	#define BMSK_CRU_7_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_7_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_7_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_DDS_FREQ_reserved	 0x01c8, 27, 5, 0xf8000000
	#define BITFIELD_CRU_7_DDS_FREQ_DDS_FREQ	 0x01c8, 0, 27, 0x07ffffff
#define ROFF_CRU_7_GET_SYSTIME	0x1cc /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_7_GET_SYSTIME	 0x01cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_7_SET_STC_LO	0x1d0 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_7_SET_STC_LO	 0x01d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_7_SET_STC_HI	0x1d4 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_7_SET_STC_HI	 0x01d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_SET_STC_HI */
	#define BLSB_CRU_7_SET_STC_HI_reserved1	25
	#define BLSB_CRU_7_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_7_SET_STC_HI_reserved0	10
	#define BLSB_CRU_7_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_7_SET_STC_HI */
	#define BWID_CRU_7_SET_STC_HI_reserved1	7
	#define BWID_CRU_7_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_7_SET_STC_HI_reserved0	6
	#define BWID_CRU_7_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_7_SET_STC_HI */
	#define BMSK_CRU_7_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_7_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_7_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_7_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_7_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_SET_STC_HI_reserved1	 0x01d4, 25, 7, 0xfe000000
	#define BITFIELD_CRU_7_SET_STC_HI_PRESC_SET	 0x01d4, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_7_SET_STC_HI_reserved0	 0x01d4, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_7_SET_STC_HI_MSB_STC	 0x01d4, 0, 10, 0x000003ff
#define ROFF_CRU_7_LAST_TS_LO	0x1d8 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_7_LAST_TS_LO	 0x01d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_LAST_TS_LO */
	#define BLSB_CRU_7_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_7_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_7_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_7_LAST_TS_LO */
	#define BWID_CRU_7_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_7_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_7_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_7_LAST_TS_LO */
	#define BMSK_CRU_7_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_7_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_7_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_7_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_LAST_TS_LO_Media_TB_UPD	 0x01d8, 31, 1, 0x80000000
	#define BITFIELD_CRU_7_LAST_TS_LO_Unlock_TS	 0x01d8, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_7_LAST_TS_LO_Make_SW_TS	 0x01d8, 0, 1, 0x00000001
#define ROFF_CRU_7_LAST_TS_HI	0x1dc /* Most significant bit of STC */ 
	#define BITFIELD_CRU_7_LAST_TS_HI	 0x01dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_LAST_TS_HI */
	#define BLSB_CRU_7_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_7_LAST_TS_HI_reserved	25
	#define BLSB_CRU_7_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_7_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_7_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_7_LAST_TS_HI */
	#define BWID_CRU_7_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_7_LAST_TS_HI_reserved	6
	#define BWID_CRU_7_LAST_TS_HI_PRESC	9
	#define BWID_CRU_7_LAST_TS_HI_reserved0	6
	#define BWID_CRU_7_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_7_LAST_TS_HI */
	#define BMSK_CRU_7_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_7_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_7_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_7_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_7_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_7_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_LAST_TS_HI_NEW_TS	 0x01dc, 31, 1, 0x80000000
	#define BITFIELD_CRU_7_LAST_TS_HI_reserved	 0x01dc, 25, 6, 0x7e000000
	#define BITFIELD_CRU_7_LAST_TS_HI_PRESC	 0x01dc, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_7_LAST_TS_HI_reserved0	 0x01dc, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_7_LAST_TS_HI_MSB_STC	 0x01dc, 0, 10, 0x000003ff
#define ROFF_CRU_7_COMP_LO	0x1e0 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_7_COMP_LO	 0x01e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_7_COMP_HI	0x1e4 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_7_COMP_HI	 0x01e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_COMP_HI */
	#define BLSB_CRU_7_COMP_HI_reserved	10
	#define BLSB_CRU_7_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_7_COMP_HI */
	#define BWID_CRU_7_COMP_HI_reserved	22
	#define BWID_CRU_7_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_7_COMP_HI */
	#define BMSK_CRU_7_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_7_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_7_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_COMP_HI_reserved	 0x01e4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_7_COMP_HI_MSB_STC	 0x01e4, 0, 10, 0x000003ff
#define ROFF_CRU_7_VSYNC_LO	0x1e8 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_7_VSYNC_LO	 0x01e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_7_VSYNC_HI	0x1ec /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_7_VSYNC_HI	 0x01ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_VSYNC_HI */
	#define BLSB_CRU_7_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_7_VSYNC_HI_reserved0	10
	#define BLSB_CRU_7_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_7_VSYNC_HI */
	#define BWID_CRU_7_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_7_VSYNC_HI_reserved0	21
	#define BWID_CRU_7_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_7_VSYNC_HI */
	#define BMSK_CRU_7_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_7_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_7_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_7_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_VSYNC_HI_NEW_VSYNC	 0x01ec, 31, 1, 0x80000000
	#define BITFIELD_CRU_7_VSYNC_HI_reserved0	 0x01ec, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_7_VSYNC_HI_MSB_STC	 0x01ec, 0, 10, 0x000003ff
#define ROFF_CRU_7_STC_LO	0x1f0 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_7_STC_LO	 0x01f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_7_STC_HI	0x1f4 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_7_STC_HI	 0x01f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_7_STC_HI */
	#define BLSB_CRU_7_STC_HI_reserved	10
	#define BLSB_CRU_7_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_7_STC_HI */
	#define BWID_CRU_7_STC_HI_reserved	22
	#define BWID_CRU_7_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_7_STC_HI */
	#define BMSK_CRU_7_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_7_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_7_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_7_STC_HI_reserved	 0x01f4, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_7_STC_HI_MSB_STC	 0x01f4, 0, 10, 0x000003ff
#define ROFF_CRU_INT_STATUS	0x200 /* Interrupt Status */ 
	#define BITFIELD_CRU_INT_STATUS	 0x0200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_INT_STATUS */
	#define BLSB_CRU_INT_STATUS_reserved3	25
	#define BLSB_CRU_INT_STATUS_COMPARE_SYS	24
	#define BLSB_CRU_INT_STATUS_reserved2	19
	#define BLSB_CRU_INT_STATUS_COMPARE_9	18
	#define BLSB_CRU_INT_STATUS_CAPTURE_SYT2	17
	#define BLSB_CRU_INT_STATUS_CAPTURE_SYT1	16
	#define BLSB_CRU_INT_STATUS_COMPARE_8	15
	#define BLSB_CRU_INT_STATUS_COMPARE_7	14
	#define BLSB_CRU_INT_STATUS_COMPARE_6	13
	#define BLSB_CRU_INT_STATUS_COMPARE_5	12
	#define BLSB_CRU_INT_STATUS_COMPARE_4	11
	#define BLSB_CRU_INT_STATUS_COMPARE_3	10
	#define BLSB_CRU_INT_STATUS_COMPARE_2	9
	#define BLSB_CRU_INT_STATUS_COMPARE_1	8
	#define BLSB_CRU_INT_STATUS_reserved0	0
	/* Register Bit Widths for CRU_INT_STATUS */
	#define BWID_CRU_INT_STATUS_reserved3	7
	#define BWID_CRU_INT_STATUS_COMPARE_SYS	1
	#define BWID_CRU_INT_STATUS_reserved2	5
	#define BWID_CRU_INT_STATUS_COMPARE_9	1
	#define BWID_CRU_INT_STATUS_CAPTURE_SYT2	1
	#define BWID_CRU_INT_STATUS_CAPTURE_SYT1	1
	#define BWID_CRU_INT_STATUS_COMPARE_8	1
	#define BWID_CRU_INT_STATUS_COMPARE_7	1
	#define BWID_CRU_INT_STATUS_COMPARE_6	1
	#define BWID_CRU_INT_STATUS_COMPARE_5	1
	#define BWID_CRU_INT_STATUS_COMPARE_4	1
	#define BWID_CRU_INT_STATUS_COMPARE_3	1
	#define BWID_CRU_INT_STATUS_COMPARE_2	1
	#define BWID_CRU_INT_STATUS_COMPARE_1	1
	#define BWID_CRU_INT_STATUS_reserved0	8
	/* Register Bit MASKS for CRU_INT_STATUS */
	#define BMSK_CRU_INT_STATUS_reserved3	0xfe000000 /* Reserved */
	#define BMSK_CRU_INT_STATUS_COMPARE_SYS	(1<<24) /* == 0x01000000: The running value in System Time counter matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_reserved2	0x00f80000 /* Reserved */
	#define BMSK_CRU_INT_STATUS_COMPARE_9	(1<<18) /* == 0x00040000: The running value in STC counter of Channel 9 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_CAPTURE_SYT2	(1<<17) /* == 0x00020000: The valid timestamp was captured in System Time capture register 2 (for received packets on Ethernet) */
	#define BMSK_CRU_INT_STATUS_CAPTURE_SYT1	(1<<16) /* == 0x00010000: The valid timestamp was captured in System Time capture register 1 (for transmitted packets on Ethernet) */
	#define BMSK_CRU_INT_STATUS_COMPARE_8	(1<<15) /* == 0x00008000: The running value in STC counter of Channel 8 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_7	(1<<14) /* == 0x00004000: The running value in STC counter of Channel 7 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_6	(1<<13) /* == 0x00002000: The running value in STC counter of Channel 6 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_5	(1<<12) /* == 0x00001000: The running value in STC counter of Channel 5 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_4	(1<<11) /* == 0x00000800: The running value in STC counter of Channel 4 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_3	(1<<10) /* == 0x00000400: The running value in STC counter of Channel 3 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_2	(1<<9) /* == 0x00000200: The running value in STC counter of Channel 2 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_COMPARE_1	(1<<8) /* == 0x00000100: The running value in STC counter of Channel 1 matched the desired compare setting */
	#define BMSK_CRU_INT_STATUS_reserved0	0x000000ff /* Reserved */
	/* Register BITFIELD for CRU_INT_STATUS - roff, lsb, width, mask */
	#define BITFIELD_CRU_INT_STATUS_reserved3	 0x0200, 25, 7, 0xfe000000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_SYS	 0x0200, 24, 1, 0x01000000
	#define BITFIELD_CRU_INT_STATUS_reserved2	 0x0200, 19, 5, 0x00f80000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_9	 0x0200, 18, 1, 0x00040000
	#define BITFIELD_CRU_INT_STATUS_CAPTURE_SYT2	 0x0200, 17, 1, 0x00020000
	#define BITFIELD_CRU_INT_STATUS_CAPTURE_SYT1	 0x0200, 16, 1, 0x00010000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_8	 0x0200, 15, 1, 0x00008000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_7	 0x0200, 14, 1, 0x00004000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_6	 0x0200, 13, 1, 0x00002000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_5	 0x0200, 12, 1, 0x00001000
	#define BITFIELD_CRU_INT_STATUS_COMPARE_4	 0x0200, 11, 1, 0x00000800
	#define BITFIELD_CRU_INT_STATUS_COMPARE_3	 0x0200, 10, 1, 0x00000400
	#define BITFIELD_CRU_INT_STATUS_COMPARE_2	 0x0200, 9, 1, 0x00000200
	#define BITFIELD_CRU_INT_STATUS_COMPARE_1	 0x0200, 8, 1, 0x00000100
	#define BITFIELD_CRU_INT_STATUS_reserved0	 0x0200, 0, 8, 0x000000ff
#define ROFF_CRU_INT_ENABLE	0x204 /* Interrupt Mask */ 
	#define BITFIELD_CRU_INT_ENABLE	 0x0204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_INT_ENABLE */
	#define BLSB_CRU_INT_ENABLE_reserved3	25
	#define BLSB_CRU_INT_ENABLE_COMPARE_SYS	24
	#define BLSB_CRU_INT_ENABLE_reserved2	19
	#define BLSB_CRU_INT_ENABLE_COMPARE_9	18
	#define BLSB_CRU_INT_ENABLE_CAPTURE_SYT2	17
	#define BLSB_CRU_INT_ENABLE_CAPTURE_SYT1	16
	#define BLSB_CRU_INT_ENABLE_COMPARE_8	15
	#define BLSB_CRU_INT_ENABLE_COMPARE_7	14
	#define BLSB_CRU_INT_ENABLE_COMPARE_6	13
	#define BLSB_CRU_INT_ENABLE_COMPARE_5	12
	#define BLSB_CRU_INT_ENABLE_COMPARE_4	11
	#define BLSB_CRU_INT_ENABLE_COMPARE_3	10
	#define BLSB_CRU_INT_ENABLE_COMPARE_2	9
	#define BLSB_CRU_INT_ENABLE_COMPARE_1	8
	#define BLSB_CRU_INT_ENABLE_reserved0	0
	/* Register Bit Widths for CRU_INT_ENABLE */
	#define BWID_CRU_INT_ENABLE_reserved3	7
	#define BWID_CRU_INT_ENABLE_COMPARE_SYS	1
	#define BWID_CRU_INT_ENABLE_reserved2	5
	#define BWID_CRU_INT_ENABLE_COMPARE_9	1
	#define BWID_CRU_INT_ENABLE_CAPTURE_SYT2	1
	#define BWID_CRU_INT_ENABLE_CAPTURE_SYT1	1
	#define BWID_CRU_INT_ENABLE_COMPARE_8	1
	#define BWID_CRU_INT_ENABLE_COMPARE_7	1
	#define BWID_CRU_INT_ENABLE_COMPARE_6	1
	#define BWID_CRU_INT_ENABLE_COMPARE_5	1
	#define BWID_CRU_INT_ENABLE_COMPARE_4	1
	#define BWID_CRU_INT_ENABLE_COMPARE_3	1
	#define BWID_CRU_INT_ENABLE_COMPARE_2	1
	#define BWID_CRU_INT_ENABLE_COMPARE_1	1
	#define BWID_CRU_INT_ENABLE_reserved0	8
	/* Register Bit MASKS for CRU_INT_ENABLE */
	#define BMSK_CRU_INT_ENABLE_reserved3	0xfe000000 /* Reserved */
	#define BMSK_CRU_INT_ENABLE_COMPARE_SYS	(1<<24) /* == 0x01000000: The running value in System Time counter matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_reserved2	0x00f80000 /* Reserved */
	#define BMSK_CRU_INT_ENABLE_COMPARE_9	(1<<18) /* == 0x00040000: The running value in STC counter of Channel 9 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_CAPTURE_SYT2	(1<<17) /* == 0x00020000: The valid timestamp was captured in System Time capture register 2 (for received packets on Ethernet) */
	#define BMSK_CRU_INT_ENABLE_CAPTURE_SYT1	(1<<16) /* == 0x00010000: The valid timestamp was captured in System Time capture register 1 (for transmitted packets on Ethernet) */
	#define BMSK_CRU_INT_ENABLE_COMPARE_8	(1<<15) /* == 0x00008000: The running value in STC counter of Channel 8 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_7	(1<<14) /* == 0x00004000: The running value in STC counter of Channel 7 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_6	(1<<13) /* == 0x00002000: The running value in STC counter of Channel 6 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_5	(1<<12) /* == 0x00001000: The running value in STC counter of Channel 5 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_4	(1<<11) /* == 0x00000800: The running value in STC counter of Channel 4 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_3	(1<<10) /* == 0x00000400: The running value in STC counter of Channel 3 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_2	(1<<9) /* == 0x00000200: The running value in STC counter of Channel 2 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_COMPARE_1	(1<<8) /* == 0x00000100: The running value in STC counter of Channel 1 matched the desired compare setting */
	#define BMSK_CRU_INT_ENABLE_reserved0	0x000000ff /* Reserved */
	/* Register BITFIELD for CRU_INT_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_CRU_INT_ENABLE_reserved3	 0x0204, 25, 7, 0xfe000000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_SYS	 0x0204, 24, 1, 0x01000000
	#define BITFIELD_CRU_INT_ENABLE_reserved2	 0x0204, 19, 5, 0x00f80000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_9	 0x0204, 18, 1, 0x00040000
	#define BITFIELD_CRU_INT_ENABLE_CAPTURE_SYT2	 0x0204, 17, 1, 0x00020000
	#define BITFIELD_CRU_INT_ENABLE_CAPTURE_SYT1	 0x0204, 16, 1, 0x00010000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_8	 0x0204, 15, 1, 0x00008000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_7	 0x0204, 14, 1, 0x00004000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_6	 0x0204, 13, 1, 0x00002000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_5	 0x0204, 12, 1, 0x00001000
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_4	 0x0204, 11, 1, 0x00000800
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_3	 0x0204, 10, 1, 0x00000400
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_2	 0x0204, 9, 1, 0x00000200
	#define BITFIELD_CRU_INT_ENABLE_COMPARE_1	 0x0204, 8, 1, 0x00000100
	#define BITFIELD_CRU_INT_ENABLE_reserved0	 0x0204, 0, 8, 0x000000ff
#define ROFF_CRU_CW_OMAR_CTRL	0x208 /* Omar CW muxing */ 
	#define BITFIELD_CRU_CW_OMAR_CTRL	 0x0208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_CW_OMAR_CTRL */
	#define BLSB_CRU_CW_OMAR_CTRL_reserved	3
	#define BLSB_CRU_CW_OMAR_CTRL_OMAR1_MUX	2
	#define BLSB_CRU_CW_OMAR_CTRL_OMAR0_MUX	1
	#define BLSB_CRU_CW_OMAR_CTRL_DOORSTEP_0_MUX	0
	/* Register Bit Widths for CRU_CW_OMAR_CTRL */
	#define BWID_CRU_CW_OMAR_CTRL_reserved	29
	#define BWID_CRU_CW_OMAR_CTRL_OMAR1_MUX	1
	#define BWID_CRU_CW_OMAR_CTRL_OMAR0_MUX	1
	#define BWID_CRU_CW_OMAR_CTRL_DOORSTEP_0_MUX	1
	/* Register Bit MASKS for CRU_CW_OMAR_CTRL */
	#define BMSK_CRU_CW_OMAR_CTRL_reserved	0xfffffff8 /* Reserved */
	#define BMSK_CRU_CW_OMAR_CTRL_OMAR1_MUX	(1<<2) /* == 0x00000004: omar bus1 */
	#define BMSK_CRU_CW_OMAR_CTRL_OMAR0_MUX	(1<<1) /* == 0x00000002: omar bus0 */
	#define BMSK_CRU_CW_OMAR_CTRL_DOORSTEP_0_MUX	(1<<0) /* == 0x00000001: Not used  */
	/* Register BITFIELD for CRU_CW_OMAR_CTRL - roff, lsb, width, mask */
	#define BITFIELD_CRU_CW_OMAR_CTRL_reserved	 0x0208, 3, 29, 0xfffffff8
	#define BITFIELD_CRU_CW_OMAR_CTRL_OMAR1_MUX	 0x0208, 2, 1, 0x00000004
	#define BITFIELD_CRU_CW_OMAR_CTRL_OMAR0_MUX	 0x0208, 1, 1, 0x00000002
	#define BITFIELD_CRU_CW_OMAR_CTRL_DOORSTEP_0_MUX	 0x0208, 0, 1, 0x00000001
#define ROFF_CRU_TS_DDS_MAP2	0x20c /* TS DDS MAP Control */ 
	#define BITFIELD_CRU_TS_DDS_MAP2	 0x020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_TS_DDS_MAP2 */
	#define BLSB_CRU_TS_DDS_MAP2_reserved0	16
	#define BLSB_CRU_TS_DDS_MAP2_TS_IN8_MAP	12
	#define BLSB_CRU_TS_DDS_MAP2_TS_IN7_MAP	8
	#define BLSB_CRU_TS_DDS_MAP2_TS_IN6_MAP	4
	#define BLSB_CRU_TS_DDS_MAP2_TS_IN5_MAP	0
	/* Register Bit Widths for CRU_TS_DDS_MAP2 */
	#define BWID_CRU_TS_DDS_MAP2_reserved0	16
	#define BWID_CRU_TS_DDS_MAP2_TS_IN8_MAP	4
	#define BWID_CRU_TS_DDS_MAP2_TS_IN7_MAP	4
	#define BWID_CRU_TS_DDS_MAP2_TS_IN6_MAP	4
	#define BWID_CRU_TS_DDS_MAP2_TS_IN5_MAP	4
	/* Register Bit MASKS for CRU_TS_DDS_MAP2 */
	#define BMSK_CRU_TS_DDS_MAP2_reserved0	0xffff0000 /* Reserved */
	#define BMSK_CRU_TS_DDS_MAP2_TS_IN8_MAP	0x0000f000 /* Select which DDS o/p drives TS input channel 4 timestamp cntr ctrl for packet timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP2_TS_IN7_MAP	0x00000f00 /* Select which DDS o/p drives TS input channel 3 timestamp cntr ctrl for packet timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP2_TS_IN6_MAP	0x000000f0 /* Select which DDS o/p drives TS input channel 2 timestamp cntr ctrl for packet timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP2_TS_IN5_MAP	0x0000000f /* Select which DDS o/p drives TS input channel 1 timestamp cntr ctrl for packet timing ctrl */
	/* Register BITFIELD for CRU_TS_DDS_MAP2 - roff, lsb, width, mask */
	#define BITFIELD_CRU_TS_DDS_MAP2_reserved0	 0x020c, 16, 16, 0xffff0000
	#define BITFIELD_CRU_TS_DDS_MAP2_TS_IN8_MAP	 0x020c, 12, 4, 0x0000f000
	#define BITFIELD_CRU_TS_DDS_MAP2_TS_IN7_MAP	 0x020c, 8, 4, 0x00000f00
	#define BITFIELD_CRU_TS_DDS_MAP2_TS_IN6_MAP	 0x020c, 4, 4, 0x000000f0
	#define BITFIELD_CRU_TS_DDS_MAP2_TS_IN5_MAP	 0x020c, 0, 4, 0x0000000f
#define ROFF_CRU_VCXO_DAC	0x210 /* VCXO DAC Control */ 
	#define BITFIELD_CRU_VCXO_DAC	 0x0210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_VCXO_DAC */
	#define BLSB_CRU_VCXO_DAC_PAT_CTNL	30
	#define BLSB_CRU_VCXO_DAC_VCX0_ENABLE	29
	#define BLSB_CRU_VCXO_DAC_reserved1	24
	#define BLSB_CRU_VCXO_DAC_FREQ_DIV	16
	#define BLSB_CRU_VCXO_DAC_reserved0	12
	#define BLSB_CRU_VCXO_DAC_VCXO_DAC	0
	/* Register Bit Widths for CRU_VCXO_DAC */
	#define BWID_CRU_VCXO_DAC_PAT_CTNL	2
	#define BWID_CRU_VCXO_DAC_VCX0_ENABLE	1
	#define BWID_CRU_VCXO_DAC_reserved1	5
	#define BWID_CRU_VCXO_DAC_FREQ_DIV	8
	#define BWID_CRU_VCXO_DAC_reserved0	4
	#define BWID_CRU_VCXO_DAC_VCXO_DAC	12
	/* Register Bit MASKS for CRU_VCXO_DAC */
	#define BMSK_CRU_VCXO_DAC_PAT_CTNL	0xc0000000 /* Output pattern selection Delta sigma, All zero, All one, Fixed 1-1-0 output seq. */
	#define BMSK_CRU_VCXO_DAC_VCX0_ENABLE	(1<<29) /* == 0x20000000: vcx0_enable */
	#define BMSK_CRU_VCXO_DAC_reserved1	0x1f000000 /* Reserved */
	#define BMSK_CRU_VCXO_DAC_FREQ_DIV	0x00ff0000 /* Delta-Sigma update frequency is bus clock / (2*freq_div+1) */
	#define BMSK_CRU_VCXO_DAC_reserved0	0x0000f000 /* Reserved */
	#define BMSK_CRU_VCXO_DAC_VCXO_DAC	0x00000fff /* 12-bit  */
	/* Register BITFIELD for CRU_VCXO_DAC - roff, lsb, width, mask */
	#define BITFIELD_CRU_VCXO_DAC_PAT_CTNL	 0x0210, 30, 2, 0xc0000000
	#define BITFIELD_CRU_VCXO_DAC_VCX0_ENABLE	 0x0210, 29, 1, 0x20000000
	#define BITFIELD_CRU_VCXO_DAC_reserved1	 0x0210, 24, 5, 0x1f000000
	#define BITFIELD_CRU_VCXO_DAC_FREQ_DIV	 0x0210, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_VCXO_DAC_reserved0	 0x0210, 12, 4, 0x0000f000
	#define BITFIELD_CRU_VCXO_DAC_VCXO_DAC	 0x0210, 0, 12, 0x00000fff
#define ROFF_CRU_TS_DDS_MAP	0x214 /* TS DDS MAP Control */ 
	#define BITFIELD_CRU_TS_DDS_MAP	 0x0214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_TS_DDS_MAP */
	#define BLSB_CRU_TS_DDS_MAP_reserved1	28
	#define BLSB_CRU_TS_DDS_MAP_TS_OUT1_MAP	24
	#define BLSB_CRU_TS_DDS_MAP_reserved0	16
	#define BLSB_CRU_TS_DDS_MAP_TS_IN4_MAP	12
	#define BLSB_CRU_TS_DDS_MAP_TS_IN3_MAP	8
	#define BLSB_CRU_TS_DDS_MAP_TS_IN2_MAP	4
	#define BLSB_CRU_TS_DDS_MAP_TS_IN1_MAP	0
	/* Register Bit Widths for CRU_TS_DDS_MAP */
	#define BWID_CRU_TS_DDS_MAP_reserved1	4
	#define BWID_CRU_TS_DDS_MAP_TS_OUT1_MAP	4
	#define BWID_CRU_TS_DDS_MAP_reserved0	8
	#define BWID_CRU_TS_DDS_MAP_TS_IN4_MAP	4
	#define BWID_CRU_TS_DDS_MAP_TS_IN3_MAP	4
	#define BWID_CRU_TS_DDS_MAP_TS_IN2_MAP	4
	#define BWID_CRU_TS_DDS_MAP_TS_IN1_MAP	4
	/* Register Bit MASKS for CRU_TS_DDS_MAP */
	#define BMSK_CRU_TS_DDS_MAP_reserved1	0xf0000000 /* Reserved */
	#define BMSK_CRU_TS_DDS_MAP_TS_OUT1_MAP	0x0f000000 /* Select which DDS output drives TS ouput channel 1 timestamp cntr ctrl for packet Tx timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP_reserved0	0x00ff0000 /* Reserved */
	#define BMSK_CRU_TS_DDS_MAP_TS_IN4_MAP	0x0000f000 /* Select which DDS o/p drives TS input channel 4 timestamp cntr ctrl for packet timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP_TS_IN3_MAP	0x00000f00 /* Select which DDS o/p drives TS input channel 3 timestamp cntr ctrl for packet timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP_TS_IN2_MAP	0x000000f0 /* Select which DDS o/p drives TS input channel 2 timestamp cntr ctrl for packet timing ctrl */
	#define BMSK_CRU_TS_DDS_MAP_TS_IN1_MAP	0x0000000f /* Select which DDS o/p drives TS input channel 1 timestamp cntr ctrl for packet timing ctrl */
	/* Register BITFIELD for CRU_TS_DDS_MAP - roff, lsb, width, mask */
	#define BITFIELD_CRU_TS_DDS_MAP_reserved1	 0x0214, 28, 4, 0xf0000000
	#define BITFIELD_CRU_TS_DDS_MAP_TS_OUT1_MAP	 0x0214, 24, 4, 0x0f000000
	#define BITFIELD_CRU_TS_DDS_MAP_reserved0	 0x0214, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_TS_DDS_MAP_TS_IN4_MAP	 0x0214, 12, 4, 0x0000f000
	#define BITFIELD_CRU_TS_DDS_MAP_TS_IN3_MAP	 0x0214, 8, 4, 0x00000f00
	#define BITFIELD_CRU_TS_DDS_MAP_TS_IN2_MAP	 0x0214, 4, 4, 0x000000f0
	#define BITFIELD_CRU_TS_DDS_MAP_TS_IN1_MAP	 0x0214, 0, 4, 0x0000000f
#define ROFF_CRU_VCXO_DIG_DAC	0x218 /* VCXO DAC Control */ 
	#define BITFIELD_CRU_VCXO_DIG_DAC	 0x0218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_VCXO_DIG_DAC */
	#define BLSB_CRU_VCXO_DIG_DAC_reserved1	16
	#define BLSB_CRU_VCXO_DIG_DAC_DIG_VCX0_INTERVAL	2
	#define BLSB_CRU_VCXO_DIG_DAC_DIG_VCX0_ADV_SEL	1
	#define BLSB_CRU_VCXO_DIG_DAC_DIG_VCX0_EN	0
	/* Register Bit Widths for CRU_VCXO_DIG_DAC */
	#define BWID_CRU_VCXO_DIG_DAC_reserved1	16
	#define BWID_CRU_VCXO_DIG_DAC_DIG_VCX0_INTERVAL	14
	#define BWID_CRU_VCXO_DIG_DAC_DIG_VCX0_ADV_SEL	1
	#define BWID_CRU_VCXO_DIG_DAC_DIG_VCX0_EN	1
	/* Register Bit MASKS for CRU_VCXO_DIG_DAC */
	#define BMSK_CRU_VCXO_DIG_DAC_reserved1	0xffff0000 /* Reserved */
	#define BMSK_CRU_VCXO_DIG_DAC_DIG_VCX0_INTERVAL	0x0000fffc /* Number of dig_vcxo_ref_clk between activates */
	#define BMSK_CRU_VCXO_DIG_DAC_DIG_VCX0_ADV_SEL	(1<<1) /* == 0x00000002: Perform advance or retard */
	#define BMSK_CRU_VCXO_DIG_DAC_DIG_VCX0_EN	(1<<0) /* == 0x00000001: Enable Digital VCX0 */
	/* Register BITFIELD for CRU_VCXO_DIG_DAC - roff, lsb, width, mask */
	#define BITFIELD_CRU_VCXO_DIG_DAC_reserved1	 0x0218, 16, 16, 0xffff0000
	#define BITFIELD_CRU_VCXO_DIG_DAC_DIG_VCX0_INTERVAL	 0x0218, 2, 14, 0x0000fffc
	#define BITFIELD_CRU_VCXO_DIG_DAC_DIG_VCX0_ADV_SEL	 0x0218, 1, 1, 0x00000002
	#define BITFIELD_CRU_VCXO_DIG_DAC_DIG_VCX0_EN	 0x0218, 0, 1, 0x00000001
#define ROFF_CRU_8_TM_CMD	0x240 /* Configuration */ 
	#define BITFIELD_CRU_8_TM_CMD	 0x0240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_TM_CMD */
	#define BLSB_CRU_8_TM_CMD_reserved	11
	#define BLSB_CRU_8_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_8_TM_CMD_M150_300	9
	#define BLSB_CRU_8_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_8_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_8_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_8_TM_CMD_MODE	4
	#define BLSB_CRU_8_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_8_TM_CMD */
	#define BWID_CRU_8_TM_CMD_reserved	21
	#define BWID_CRU_8_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_8_TM_CMD_M150_300	1
	#define BWID_CRU_8_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_8_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_8_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_8_TM_CMD_MODE	2
	#define BWID_CRU_8_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_8_TM_CMD */
	#define BMSK_CRU_8_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_8_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_8_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_8_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_8_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_8_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_8_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_8_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_8_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_TM_CMD_reserved	 0x0240, 11, 21, 0xfffff800
	#define BITFIELD_CRU_8_TM_CMD_VSYNC_SEL	 0x0240, 10, 1, 0x00000400
	#define BITFIELD_CRU_8_TM_CMD_M150_300	 0x0240, 9, 1, 0x00000200
	#define BITFIELD_CRU_8_TM_CMD_M300_BYPASS	 0x0240, 8, 1, 0x00000100
	#define BITFIELD_CRU_8_TM_CMD_COMP_ENABLE	 0x0240, 7, 1, 0x00000080
	#define BITFIELD_CRU_8_TM_CMD_MASTER_CLOCK	 0x0240, 6, 1, 0x00000040
	#define BITFIELD_CRU_8_TM_CMD_MODE	 0x0240, 4, 2, 0x00000030
	#define BITFIELD_CRU_8_TM_CMD_TS_SOURCE	 0x0240, 0, 4, 0x0000000f
#define ROFF_CRU_8_DDS_FREQ	0x248 /* DDS Frequency */ 
	#define BITFIELD_CRU_8_DDS_FREQ	 0x0248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_DDS_FREQ */
	#define BLSB_CRU_8_DDS_FREQ_reserved	27
	#define BLSB_CRU_8_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_8_DDS_FREQ */
	#define BWID_CRU_8_DDS_FREQ_reserved	5
	#define BWID_CRU_8_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_8_DDS_FREQ */
	#define BMSK_CRU_8_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_8_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_8_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_DDS_FREQ_reserved	 0x0248, 27, 5, 0xf8000000
	#define BITFIELD_CRU_8_DDS_FREQ_DDS_FREQ	 0x0248, 0, 27, 0x07ffffff
#define ROFF_CRU_8_GET_SYSTIME	0x24c /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_8_GET_SYSTIME	 0x024c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_8_SET_STC_LO	0x250 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_8_SET_STC_LO	 0x0250, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_8_SET_STC_HI	0x254 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_8_SET_STC_HI	 0x0254, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_SET_STC_HI */
	#define BLSB_CRU_8_SET_STC_HI_reserved1	25
	#define BLSB_CRU_8_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_8_SET_STC_HI_reserved0	10
	#define BLSB_CRU_8_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_8_SET_STC_HI */
	#define BWID_CRU_8_SET_STC_HI_reserved1	7
	#define BWID_CRU_8_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_8_SET_STC_HI_reserved0	6
	#define BWID_CRU_8_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_8_SET_STC_HI */
	#define BMSK_CRU_8_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_8_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_8_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_8_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_8_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_SET_STC_HI_reserved1	 0x0254, 25, 7, 0xfe000000
	#define BITFIELD_CRU_8_SET_STC_HI_PRESC_SET	 0x0254, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_8_SET_STC_HI_reserved0	 0x0254, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_8_SET_STC_HI_MSB_STC	 0x0254, 0, 10, 0x000003ff
#define ROFF_CRU_8_LAST_TS_LO	0x258 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_8_LAST_TS_LO	 0x0258, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_LAST_TS_LO */
	#define BLSB_CRU_8_LAST_TS_LO_Media_TB_UPD	31
	#define BLSB_CRU_8_LAST_TS_LO_Unlock_TS	1
	#define BLSB_CRU_8_LAST_TS_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_8_LAST_TS_LO */
	#define BWID_CRU_8_LAST_TS_LO_Media_TB_UPD	1
	#define BWID_CRU_8_LAST_TS_LO_Unlock_TS	30
	#define BWID_CRU_8_LAST_TS_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_8_LAST_TS_LO */
	#define BMSK_CRU_8_LAST_TS_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_8_LAST_TS_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_8_LAST_TS_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_8_LAST_TS_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_LAST_TS_LO_Media_TB_UPD	 0x0258, 31, 1, 0x80000000
	#define BITFIELD_CRU_8_LAST_TS_LO_Unlock_TS	 0x0258, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_8_LAST_TS_LO_Make_SW_TS	 0x0258, 0, 1, 0x00000001
#define ROFF_CRU_8_LAST_TS_HI	0x25c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_8_LAST_TS_HI	 0x025c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_LAST_TS_HI */
	#define BLSB_CRU_8_LAST_TS_HI_NEW_TS	31
	#define BLSB_CRU_8_LAST_TS_HI_reserved	25
	#define BLSB_CRU_8_LAST_TS_HI_PRESC	16
	#define BLSB_CRU_8_LAST_TS_HI_reserved0	10
	#define BLSB_CRU_8_LAST_TS_HI_MSB_STC	0
	/* Register Bit Widths for CRU_8_LAST_TS_HI */
	#define BWID_CRU_8_LAST_TS_HI_NEW_TS	1
	#define BWID_CRU_8_LAST_TS_HI_reserved	6
	#define BWID_CRU_8_LAST_TS_HI_PRESC	9
	#define BWID_CRU_8_LAST_TS_HI_reserved0	6
	#define BWID_CRU_8_LAST_TS_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_8_LAST_TS_HI */
	#define BMSK_CRU_8_LAST_TS_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_8_LAST_TS_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_8_LAST_TS_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_8_LAST_TS_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_8_LAST_TS_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_8_LAST_TS_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_LAST_TS_HI_NEW_TS	 0x025c, 31, 1, 0x80000000
	#define BITFIELD_CRU_8_LAST_TS_HI_reserved	 0x025c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_8_LAST_TS_HI_PRESC	 0x025c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_8_LAST_TS_HI_reserved0	 0x025c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_8_LAST_TS_HI_MSB_STC	 0x025c, 0, 10, 0x000003ff
#define ROFF_CRU_8_COMP_LO	0x260 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_8_COMP_LO	 0x0260, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_8_COMP_HI	0x264 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_8_COMP_HI	 0x0264, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_COMP_HI */
	#define BLSB_CRU_8_COMP_HI_reserved	10
	#define BLSB_CRU_8_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_8_COMP_HI */
	#define BWID_CRU_8_COMP_HI_reserved	22
	#define BWID_CRU_8_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_8_COMP_HI */
	#define BMSK_CRU_8_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_8_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_8_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_COMP_HI_reserved	 0x0264, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_8_COMP_HI_MSB_STC	 0x0264, 0, 10, 0x000003ff
#define ROFF_CRU_8_VSYNC_LO	0x268 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_8_VSYNC_LO	 0x0268, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_8_VSYNC_HI	0x26c /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_8_VSYNC_HI	 0x026c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_VSYNC_HI */
	#define BLSB_CRU_8_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_8_VSYNC_HI_reserved0	10
	#define BLSB_CRU_8_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_8_VSYNC_HI */
	#define BWID_CRU_8_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_8_VSYNC_HI_reserved0	21
	#define BWID_CRU_8_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_8_VSYNC_HI */
	#define BMSK_CRU_8_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_8_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_8_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_8_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_VSYNC_HI_NEW_VSYNC	 0x026c, 31, 1, 0x80000000
	#define BITFIELD_CRU_8_VSYNC_HI_reserved0	 0x026c, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_8_VSYNC_HI_MSB_STC	 0x026c, 0, 10, 0x000003ff
#define ROFF_CRU_8_STC_LO	0x270 /* Current value of STC [31:0] */ 
	#define BITFIELD_CRU_8_STC_LO	 0x0270, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_8_STC_HI	0x274 /* Current value of STC [41:32] */ 
	#define BITFIELD_CRU_8_STC_HI	 0x0274, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_8_STC_HI */
	#define BLSB_CRU_8_STC_HI_reserved	10
	#define BLSB_CRU_8_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_8_STC_HI */
	#define BWID_CRU_8_STC_HI_reserved	22
	#define BWID_CRU_8_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_8_STC_HI */
	#define BMSK_CRU_8_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_8_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_8_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_8_STC_HI_reserved	 0x0274, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_8_STC_HI_MSB_STC	 0x0274, 0, 10, 0x000003ff
#define ROFF_CRU_NET_CMD	0x300 /* Command and configuration of network timestamper */ 
	#define BITFIELD_CRU_NET_CMD	 0x0300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_NET_CMD */
	#define BLSB_CRU_NET_CMD_reserved1	7
	#define BLSB_CRU_NET_CMD_COMP_ENABLE	6
	#define BLSB_CRU_NET_CMD_reserved0	0
	/* Register Bit Widths for CRU_NET_CMD */
	#define BWID_CRU_NET_CMD_reserved1	25
	#define BWID_CRU_NET_CMD_COMP_ENABLE	1
	#define BWID_CRU_NET_CMD_reserved0	6
	/* Register Bit MASKS for CRU_NET_CMD */
	#define BMSK_CRU_NET_CMD_reserved1	0xffffff80 /* reserved1 */
	#define BMSK_CRU_NET_CMD_COMP_ENABLE	(1<<6) /* == 0x00000040: Enable Event comparator */
	#define BMSK_CRU_NET_CMD_reserved0	0x0000003f /* Reserved */
	/* Register BITFIELD for CRU_NET_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_NET_CMD_reserved1	 0x0300, 7, 25, 0xffffff80
	#define BITFIELD_CRU_NET_CMD_COMP_ENABLE	 0x0300, 6, 1, 0x00000040
	#define BITFIELD_CRU_NET_CMD_reserved0	 0x0300, 0, 6, 0x0000003f
#define ROFF_CRU_NET_DDS_FREQ	0x308 /* Frequency settings for network timebase DDS */ 
	#define BITFIELD_CRU_NET_DDS_FREQ	 0x0308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_NET_DDS_FREQ */
	#define BLSB_CRU_NET_DDS_FREQ_reserved	27
	#define BLSB_CRU_NET_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_NET_DDS_FREQ */
	#define BWID_CRU_NET_DDS_FREQ_reserved	5
	#define BWID_CRU_NET_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_NET_DDS_FREQ */
	#define BMSK_CRU_NET_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_NET_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_NET_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_NET_DDS_FREQ_reserved	 0x0308, 27, 5, 0xf8000000
	#define BITFIELD_CRU_NET_DDS_FREQ_DDS_FREQ	 0x0308, 0, 27, 0x07ffffff
#define ROFF_CRU_NET_GET_SYSTIME	0x30c /* Running status of System Time bits [31:0] */ 
	#define BITFIELD_CRU_NET_GET_SYSTIME	 0x030c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_NET_GET_SYSTIME */
	#define BLSB_CRU_NET_GET_SYSTIME_reserved1	0
	/* Register Bit Widths for CRU_NET_GET_SYSTIME */
	#define BWID_CRU_NET_GET_SYSTIME_reserved1	32
	/* Register Bit MASKS for CRU_NET_GET_SYSTIME */
	#define BMSK_CRU_NET_GET_SYSTIME_reserved1	0x00000000 /* Reserved */
	/* Register BITFIELD for CRU_NET_GET_SYSTIME - roff, lsb, width, mask */
	#define BITFIELD_CRU_NET_GET_SYSTIME_reserved1	 0x030c, 0, 32, 0x00000000
#define ROFF_CRU_NET_CAPLOW_TX	0x310 /* System Time Capture register C [31:0] - Network TX packets */ 
	#define BITFIELD_CRU_NET_CAPLOW_TX	 0x0310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_NET_CAPLOW_RX	0x314 /* System Time Capture register C [31:0] - Network RX packets */ 
	#define BITFIELD_CRU_NET_CAPLOW_RX	 0x0314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_NET_COMPLOW_S	0x318 /* System Time Compare Register C [31:0] general purpose */ 
	#define BITFIELD_CRU_NET_COMPLOW_S	 0x0318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_FILTER_CFG_A1	0x380 /* Packet Filter configuration and Enables */ 
	#define BITFIELD_CRU_FILTER_CFG_A1	 0x0380, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_FILTER_CFG_A1 */
	#define BLSB_CRU_FILTER_CFG_A1_TXFILTER_EN	31
	#define BLSB_CRU_FILTER_CFG_A1_RXFILTER_EN	30
	#define BLSB_CRU_FILTER_CFG_A1_reserved	29
	#define BLSB_CRU_FILTER_CFG_A1_IP_L2	28
	#define BLSB_CRU_FILTER_CFG_A1_PTP_VER	24
	#define BLSB_CRU_FILTER_CFG_A1_DA_HASH	16
	#define BLSB_CRU_FILTER_CFG_A1_ETHER_TYPE	0
	/* Register Bit Widths for CRU_FILTER_CFG_A1 */
	#define BWID_CRU_FILTER_CFG_A1_TXFILTER_EN	1
	#define BWID_CRU_FILTER_CFG_A1_RXFILTER_EN	1
	#define BWID_CRU_FILTER_CFG_A1_reserved	1
	#define BWID_CRU_FILTER_CFG_A1_IP_L2	1
	#define BWID_CRU_FILTER_CFG_A1_PTP_VER	4
	#define BWID_CRU_FILTER_CFG_A1_DA_HASH	8
	#define BWID_CRU_FILTER_CFG_A1_ETHER_TYPE	16
	/* Register Bit MASKS for CRU_FILTER_CFG_A1 */
	#define BMSK_CRU_FILTER_CFG_A1_TXFILTER_EN	(1<<31) /* == 0x80000000: Enable packet filtering in TX direction */
	#define BMSK_CRU_FILTER_CFG_A1_RXFILTER_EN	(1<<30) /* == 0x40000000:  Enable packet filtering in RX direction */
	#define BMSK_CRU_FILTER_CFG_A1_reserved	(1<<29) /* == 0x20000000: Reserved */
	#define BMSK_CRU_FILTER_CFG_A1_IP_L2	(1<<28) /* == 0x10000000: filter will operate in IP/UDP mode or in Ethernet mode */
	#define BMSK_CRU_FILTER_CFG_A1_PTP_VER	0x0f000000 /* 4-bit PTP version */
	#define BMSK_CRU_FILTER_CFG_A1_DA_HASH	0x00ff0000 /* Ethernet CRC calculated */
	#define BMSK_CRU_FILTER_CFG_A1_ETHER_TYPE	0x0000ffff /* Ether type field for packet filter */
	/* Register BITFIELD for CRU_FILTER_CFG_A1 - roff, lsb, width, mask */
	#define BITFIELD_CRU_FILTER_CFG_A1_TXFILTER_EN	 0x0380, 31, 1, 0x80000000
	#define BITFIELD_CRU_FILTER_CFG_A1_RXFILTER_EN	 0x0380, 30, 1, 0x40000000
	#define BITFIELD_CRU_FILTER_CFG_A1_reserved	 0x0380, 29, 1, 0x20000000
	#define BITFIELD_CRU_FILTER_CFG_A1_IP_L2	 0x0380, 28, 1, 0x10000000
	#define BITFIELD_CRU_FILTER_CFG_A1_PTP_VER	 0x0380, 24, 4, 0x0f000000
	#define BITFIELD_CRU_FILTER_CFG_A1_DA_HASH	 0x0380, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_FILTER_CFG_A1_ETHER_TYPE	 0x0380, 0, 16, 0x0000ffff
#define ROFF_CRU_FILTER_CFG_B1	0x384 /* Parameters for IP-based IEEE1588 protocol implementation */ 
	#define BITFIELD_CRU_FILTER_CFG_B1	 0x0384, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_FILTER_CFG_B1 */
	#define BLSB_CRU_FILTER_CFG_B1_TAG_MAC	31
	#define BLSB_CRU_FILTER_CFG_B1_CHECK_CRC	30
	#define BLSB_CRU_FILTER_CFG_B1_MSG_TYPE	29
	#define BLSB_CRU_FILTER_CFG_B1_PTP_VER	28
	#define BLSB_CRU_FILTER_CFG_B1_DEST_PORT1	27
	#define BLSB_CRU_FILTER_CFG_B1_IP_PROTO	26
	#define BLSB_CRU_FILTER_CFG_B1_ETHER_TYPE	25
	#define BLSB_CRU_FILTER_CFG_B1_DA_HASH	24
	#define BLSB_CRU_FILTER_CFG_B1_PROTO	16
	#define BLSB_CRU_FILTER_CFG_B1_DEST_PORT	0
	/* Register Bit Widths for CRU_FILTER_CFG_B1 */
	#define BWID_CRU_FILTER_CFG_B1_TAG_MAC	1
	#define BWID_CRU_FILTER_CFG_B1_CHECK_CRC	1
	#define BWID_CRU_FILTER_CFG_B1_MSG_TYPE	1
	#define BWID_CRU_FILTER_CFG_B1_PTP_VER	1
	#define BWID_CRU_FILTER_CFG_B1_DEST_PORT1	1
	#define BWID_CRU_FILTER_CFG_B1_IP_PROTO	1
	#define BWID_CRU_FILTER_CFG_B1_ETHER_TYPE	1
	#define BWID_CRU_FILTER_CFG_B1_DA_HASH	1
	#define BWID_CRU_FILTER_CFG_B1_PROTO	8
	#define BWID_CRU_FILTER_CFG_B1_DEST_PORT	16
	/* Register Bit MASKS for CRU_FILTER_CFG_B1 */
	#define BMSK_CRU_FILTER_CFG_B1_TAG_MAC	(1<<31) /* == 0x80000000: Detect tagged MAC field */
	#define BMSK_CRU_FILTER_CFG_B1_CHECK_CRC	(1<<30) /* == 0x40000000: Check for valid CRC 32 */
	#define BMSK_CRU_FILTER_CFG_B1_MSG_TYPE	(1<<29) /* == 0x20000000: Compare Mesaage Type */
	#define BMSK_CRU_FILTER_CFG_B1_PTP_VER	(1<<28) /* == 0x10000000: Compare PTP version */
	#define BMSK_CRU_FILTER_CFG_B1_DEST_PORT1	(1<<27) /* == 0x08000000: Compare destination port */
	#define BMSK_CRU_FILTER_CFG_B1_IP_PROTO	(1<<26) /* == 0x04000000: Compare IP protocol */
	#define BMSK_CRU_FILTER_CFG_B1_ETHER_TYPE	(1<<25) /* == 0x02000000: Compare ether type */
	#define BMSK_CRU_FILTER_CFG_B1_DA_HASH	(1<<24) /* == 0x01000000: enable exclusion of DA hash in teh tiemstamping filter */
	#define BMSK_CRU_FILTER_CFG_B1_PROTO	0x00ff0000 /* IP protocol  */
	#define BMSK_CRU_FILTER_CFG_B1_DEST_PORT	0x0000ffff /* 16 -bit destination port */
	/* Register BITFIELD for CRU_FILTER_CFG_B1 - roff, lsb, width, mask */
	#define BITFIELD_CRU_FILTER_CFG_B1_TAG_MAC	 0x0384, 31, 1, 0x80000000
	#define BITFIELD_CRU_FILTER_CFG_B1_CHECK_CRC	 0x0384, 30, 1, 0x40000000
	#define BITFIELD_CRU_FILTER_CFG_B1_MSG_TYPE	 0x0384, 29, 1, 0x20000000
	#define BITFIELD_CRU_FILTER_CFG_B1_PTP_VER	 0x0384, 28, 1, 0x10000000
	#define BITFIELD_CRU_FILTER_CFG_B1_DEST_PORT1	 0x0384, 27, 1, 0x08000000
	#define BITFIELD_CRU_FILTER_CFG_B1_IP_PROTO	 0x0384, 26, 1, 0x04000000
	#define BITFIELD_CRU_FILTER_CFG_B1_ETHER_TYPE	 0x0384, 25, 1, 0x02000000
	#define BITFIELD_CRU_FILTER_CFG_B1_DA_HASH	 0x0384, 24, 1, 0x01000000
	#define BITFIELD_CRU_FILTER_CFG_B1_PROTO	 0x0384, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_FILTER_CFG_B1_DEST_PORT	 0x0384, 0, 16, 0x0000ffff
#define ROFF_CRU_FILTER_CFG_C1	0x388 /* IP protocol data */ 
	#define BITFIELD_CRU_FILTER_CFG_C1	 0x0388, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_FILTER_CFG_C1 */
	#define BLSB_CRU_FILTER_CFG_C1_DEST_IP_ADDR_3	24
	#define BLSB_CRU_FILTER_CFG_C1_DEST_IP_ADDR_2	16
	#define BLSB_CRU_FILTER_CFG_C1_DEST_IP_ADDR_1	8
	#define BLSB_CRU_FILTER_CFG_C1_DEST_IP_ADDR_0	0
	/* Register Bit Widths for CRU_FILTER_CFG_C1 */
	#define BWID_CRU_FILTER_CFG_C1_DEST_IP_ADDR_3	8
	#define BWID_CRU_FILTER_CFG_C1_DEST_IP_ADDR_2	8
	#define BWID_CRU_FILTER_CFG_C1_DEST_IP_ADDR_1	8
	#define BWID_CRU_FILTER_CFG_C1_DEST_IP_ADDR_0	8
	/* Register Bit MASKS for CRU_FILTER_CFG_C1 */
	#define BMSK_CRU_FILTER_CFG_C1_DEST_IP_ADDR_3	0xff000000 /* Destination IP address for PTP packets, this address is used in both transmit and receive filters */
	#define BMSK_CRU_FILTER_CFG_C1_DEST_IP_ADDR_2	0x00ff0000 /* Destination IP address for PTP packets, this address is used in both transmit and receive filters */
	#define BMSK_CRU_FILTER_CFG_C1_DEST_IP_ADDR_1	0x0000ff00 /* Destination IP address for PTP packets, this address is used in both transmit and receive filters */
	#define BMSK_CRU_FILTER_CFG_C1_DEST_IP_ADDR_0	0x000000ff /* Destination IP address for PTP packets, this address is used in both transmit and receive filters */
	/* Register BITFIELD for CRU_FILTER_CFG_C1 - roff, lsb, width, mask */
	#define BITFIELD_CRU_FILTER_CFG_C1_DEST_IP_ADDR_3	 0x0388, 24, 8, 0xff000000
	#define BITFIELD_CRU_FILTER_CFG_C1_DEST_IP_ADDR_2	 0x0388, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_FILTER_CFG_C1_DEST_IP_ADDR_1	 0x0388, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_FILTER_CFG_C1_DEST_IP_ADDR_0	 0x0388, 0, 8, 0x000000ff
#define ROFF_CRU_FILTER_CFG_D1	0x38c /* IP Protocol data */ 
	#define BITFIELD_CRU_FILTER_CFG_D1	 0x038c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_FILTER_CFG_D1 */
	#define BLSB_CRU_FILTER_CFG_D1_reserved1	16
	#define BLSB_CRU_FILTER_CFG_D1_DEST_IP_MASK	0
	/* Register Bit Widths for CRU_FILTER_CFG_D1 */
	#define BWID_CRU_FILTER_CFG_D1_reserved1	16
	#define BWID_CRU_FILTER_CFG_D1_DEST_IP_MASK	16
	/* Register Bit MASKS for CRU_FILTER_CFG_D1 */
	#define BMSK_CRU_FILTER_CFG_D1_reserved1	0xffff0000 /* Reserved */
	#define BMSK_CRU_FILTER_CFG_D1_DEST_IP_MASK	0x0000ffff /* Ip address mask */
	/* Register BITFIELD for CRU_FILTER_CFG_D1 - roff, lsb, width, mask */
	#define BITFIELD_CRU_FILTER_CFG_D1_reserved1	 0x038c, 16, 16, 0xffff0000
	#define BITFIELD_CRU_FILTER_CFG_D1_DEST_IP_MASK	 0x038c, 0, 16, 0x0000ffff
#define ROFF_CRU_MSG_DATA_1_TX	0x3a0 /* Transmit Message Captured data */ 
	#define BITFIELD_CRU_MSG_DATA_1_TX	 0x03a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_MSG_DATA_1_TX */
	#define BLSB_CRU_MSG_DATA_1_TX_MSGID_3	24
	#define BLSB_CRU_MSG_DATA_1_TX_MSGID_2	16
	#define BLSB_CRU_MSG_DATA_1_TX_MSGID_1	8
	#define BLSB_CRU_MSG_DATA_1_TX_MSGID_0	0
	/* Register Bit Widths for CRU_MSG_DATA_1_TX */
	#define BWID_CRU_MSG_DATA_1_TX_MSGID_3	8
	#define BWID_CRU_MSG_DATA_1_TX_MSGID_2	8
	#define BWID_CRU_MSG_DATA_1_TX_MSGID_1	8
	#define BWID_CRU_MSG_DATA_1_TX_MSGID_0	8
	/* Register Bit MASKS for CRU_MSG_DATA_1_TX */
	#define BMSK_CRU_MSG_DATA_1_TX_MSGID_3	0xff000000 /* Byte 37 or 65 of PTP message */
	#define BMSK_CRU_MSG_DATA_1_TX_MSGID_2	0x00ff0000 /* Byte 36 or 64 of PTP message */
	#define BMSK_CRU_MSG_DATA_1_TX_MSGID_1	0x0000ff00 /* Byte 35 or 63 of PTP message */
	#define BMSK_CRU_MSG_DATA_1_TX_MSGID_0	0x000000ff /* Byte 34 or 62 of PTP message */
	/* Register BITFIELD for CRU_MSG_DATA_1_TX - roff, lsb, width, mask */
	#define BITFIELD_CRU_MSG_DATA_1_TX_MSGID_3	 0x03a0, 24, 8, 0xff000000
	#define BITFIELD_CRU_MSG_DATA_1_TX_MSGID_2	 0x03a0, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_MSG_DATA_1_TX_MSGID_1	 0x03a0, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_MSG_DATA_1_TX_MSGID_0	 0x03a0, 0, 8, 0x000000ff
#define ROFF_CRU_MSG_DATA_2_TX	0x3a4 /* Transmit Message Captured data */ 
	#define BITFIELD_CRU_MSG_DATA_2_TX	 0x03a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_MSG_DATA_2_TX */
	#define BLSB_CRU_MSG_DATA_2_TX_MSGID_7	24
	#define BLSB_CRU_MSG_DATA_2_TX_MSGID_6	16
	#define BLSB_CRU_MSG_DATA_2_TX_MSGID_5	8
	#define BLSB_CRU_MSG_DATA_2_TX_MSGID_4	0
	/* Register Bit Widths for CRU_MSG_DATA_2_TX */
	#define BWID_CRU_MSG_DATA_2_TX_MSGID_7	8
	#define BWID_CRU_MSG_DATA_2_TX_MSGID_6	8
	#define BWID_CRU_MSG_DATA_2_TX_MSGID_5	8
	#define BWID_CRU_MSG_DATA_2_TX_MSGID_4	8
	/* Register Bit MASKS for CRU_MSG_DATA_2_TX */
	#define BMSK_CRU_MSG_DATA_2_TX_MSGID_7	0xff000000 /* Byte 41 or 69 of PTP message */
	#define BMSK_CRU_MSG_DATA_2_TX_MSGID_6	0x00ff0000 /* Byte 40 or 68 of PTP message */
	#define BMSK_CRU_MSG_DATA_2_TX_MSGID_5	0x0000ff00 /* Byte 39 or 67 of PTP message */
	#define BMSK_CRU_MSG_DATA_2_TX_MSGID_4	0x000000ff /* Byte 38 or 66 of PTP message */
	/* Register BITFIELD for CRU_MSG_DATA_2_TX - roff, lsb, width, mask */
	#define BITFIELD_CRU_MSG_DATA_2_TX_MSGID_7	 0x03a4, 24, 8, 0xff000000
	#define BITFIELD_CRU_MSG_DATA_2_TX_MSGID_6	 0x03a4, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_MSG_DATA_2_TX_MSGID_5	 0x03a4, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_MSG_DATA_2_TX_MSGID_4	 0x03a4, 0, 8, 0x000000ff
#define ROFF_CRU_MSG_DATA_3_TX	0x3a8 /* Transmit Message Captured data */ 
	#define BITFIELD_CRU_MSG_DATA_3_TX	 0x03a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_MSG_DATA_3_TX */
	#define BLSB_CRU_MSG_DATA_3_TX_MSGSEQ_1	24
	#define BLSB_CRU_MSG_DATA_3_TX_MSGSEQ_0	16
	#define BLSB_CRU_MSG_DATA_3_TX_MSGID_9	8
	#define BLSB_CRU_MSG_DATA_3_TX_MSGID_8	0
	/* Register Bit Widths for CRU_MSG_DATA_3_TX */
	#define BWID_CRU_MSG_DATA_3_TX_MSGSEQ_1	8
	#define BWID_CRU_MSG_DATA_3_TX_MSGSEQ_0	8
	#define BWID_CRU_MSG_DATA_3_TX_MSGID_9	8
	#define BWID_CRU_MSG_DATA_3_TX_MSGID_8	8
	/* Register Bit MASKS for CRU_MSG_DATA_3_TX */
	#define BMSK_CRU_MSG_DATA_3_TX_MSGSEQ_1	0xff000000 /* Byte 45 or 73 of PTP message */
	#define BMSK_CRU_MSG_DATA_3_TX_MSGSEQ_0	0x00ff0000 /* Byte 44 or 72 of PTP message */
	#define BMSK_CRU_MSG_DATA_3_TX_MSGID_9	0x0000ff00 /* Byte 43 or 71 of PTP message */
	#define BMSK_CRU_MSG_DATA_3_TX_MSGID_8	0x000000ff /* Byte 42 or 70 of PTP message */
	/* Register BITFIELD for CRU_MSG_DATA_3_TX - roff, lsb, width, mask */
	#define BITFIELD_CRU_MSG_DATA_3_TX_MSGSEQ_1	 0x03a8, 24, 8, 0xff000000
	#define BITFIELD_CRU_MSG_DATA_3_TX_MSGSEQ_0	 0x03a8, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_MSG_DATA_3_TX_MSGID_9	 0x03a8, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_MSG_DATA_3_TX_MSGID_8	 0x03a8, 0, 8, 0x000000ff
#define ROFF_CRU_MSG_DATA_1_RX	0x3e0 /* Receive Message Captured data */ 
	#define BITFIELD_CRU_MSG_DATA_1_RX	 0x03e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_MSG_DATA_1_RX */
	#define BLSB_CRU_MSG_DATA_1_RX_MSGID_3	24
	#define BLSB_CRU_MSG_DATA_1_RX_MSGID_2	16
	#define BLSB_CRU_MSG_DATA_1_RX_MSGID_1	8
	#define BLSB_CRU_MSG_DATA_1_RX_MSGID_0	0
	/* Register Bit Widths for CRU_MSG_DATA_1_RX */
	#define BWID_CRU_MSG_DATA_1_RX_MSGID_3	8
	#define BWID_CRU_MSG_DATA_1_RX_MSGID_2	8
	#define BWID_CRU_MSG_DATA_1_RX_MSGID_1	8
	#define BWID_CRU_MSG_DATA_1_RX_MSGID_0	8
	/* Register Bit MASKS for CRU_MSG_DATA_1_RX */
	#define BMSK_CRU_MSG_DATA_1_RX_MSGID_3	0xff000000 /* Byte 37 or 65 of PTP message */
	#define BMSK_CRU_MSG_DATA_1_RX_MSGID_2	0x00ff0000 /* Byte 36 or 64 of PTP message */
	#define BMSK_CRU_MSG_DATA_1_RX_MSGID_1	0x0000ff00 /* Byte 35 or 63 of PTP message */
	#define BMSK_CRU_MSG_DATA_1_RX_MSGID_0	0x000000ff /* Byte 34 or 62 of PTP message */
	/* Register BITFIELD for CRU_MSG_DATA_1_RX - roff, lsb, width, mask */
	#define BITFIELD_CRU_MSG_DATA_1_RX_MSGID_3	 0x03e0, 24, 8, 0xff000000
	#define BITFIELD_CRU_MSG_DATA_1_RX_MSGID_2	 0x03e0, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_MSG_DATA_1_RX_MSGID_1	 0x03e0, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_MSG_DATA_1_RX_MSGID_0	 0x03e0, 0, 8, 0x000000ff
#define ROFF_CRU_MSG_DATA_2_RX	0x3e4 /* Receive Message Captured data */ 
	#define BITFIELD_CRU_MSG_DATA_2_RX	 0x03e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_MSG_DATA_2_RX */
	#define BLSB_CRU_MSG_DATA_2_RX_MSGID_7	24
	#define BLSB_CRU_MSG_DATA_2_RX_MSGID_6	16
	#define BLSB_CRU_MSG_DATA_2_RX_MSGID_5	8
	#define BLSB_CRU_MSG_DATA_2_RX_MSGID_4	0
	/* Register Bit Widths for CRU_MSG_DATA_2_RX */
	#define BWID_CRU_MSG_DATA_2_RX_MSGID_7	8
	#define BWID_CRU_MSG_DATA_2_RX_MSGID_6	8
	#define BWID_CRU_MSG_DATA_2_RX_MSGID_5	8
	#define BWID_CRU_MSG_DATA_2_RX_MSGID_4	8
	/* Register Bit MASKS for CRU_MSG_DATA_2_RX */
	#define BMSK_CRU_MSG_DATA_2_RX_MSGID_7	0xff000000 /* Byte 41 or 69 of PTP message */
	#define BMSK_CRU_MSG_DATA_2_RX_MSGID_6	0x00ff0000 /* Byte 40 or 68 of PTP message */
	#define BMSK_CRU_MSG_DATA_2_RX_MSGID_5	0x0000ff00 /* Byte 39 or 67 of PTP message */
	#define BMSK_CRU_MSG_DATA_2_RX_MSGID_4	0x000000ff /* Byte 38 or 66 of PTP message */
	/* Register BITFIELD for CRU_MSG_DATA_2_RX - roff, lsb, width, mask */
	#define BITFIELD_CRU_MSG_DATA_2_RX_MSGID_7	 0x03e4, 24, 8, 0xff000000
	#define BITFIELD_CRU_MSG_DATA_2_RX_MSGID_6	 0x03e4, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_MSG_DATA_2_RX_MSGID_5	 0x03e4, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_MSG_DATA_2_RX_MSGID_4	 0x03e4, 0, 8, 0x000000ff
#define ROFF_CRU_MSG_DATA_3_RX	0x3e8 /* Receive Message Captured data */ 
	#define BITFIELD_CRU_MSG_DATA_3_RX	 0x03e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_MSG_DATA_3_RX */
	#define BLSB_CRU_MSG_DATA_3_RX_MSGSEQ_1	24
	#define BLSB_CRU_MSG_DATA_3_RX_MSGSEQ_0	16
	#define BLSB_CRU_MSG_DATA_3_RX_MSGID_9	8
	#define BLSB_CRU_MSG_DATA_3_RX_MSGID_8	0
	/* Register Bit Widths for CRU_MSG_DATA_3_RX */
	#define BWID_CRU_MSG_DATA_3_RX_MSGSEQ_1	8
	#define BWID_CRU_MSG_DATA_3_RX_MSGSEQ_0	8
	#define BWID_CRU_MSG_DATA_3_RX_MSGID_9	8
	#define BWID_CRU_MSG_DATA_3_RX_MSGID_8	8
	/* Register Bit MASKS for CRU_MSG_DATA_3_RX */
	#define BMSK_CRU_MSG_DATA_3_RX_MSGSEQ_1	0xff000000 /* Byte 45 or 73 of PTP message */
	#define BMSK_CRU_MSG_DATA_3_RX_MSGSEQ_0	0x00ff0000 /* Byte 44 or 72 of PTP message */
	#define BMSK_CRU_MSG_DATA_3_RX_MSGID_9	0x0000ff00 /* Byte 43 or 71 of PTP message */
	#define BMSK_CRU_MSG_DATA_3_RX_MSGID_8	0x000000ff /* Byte 42 or 70 of PTP message */
	/* Register BITFIELD for CRU_MSG_DATA_3_RX - roff, lsb, width, mask */
	#define BITFIELD_CRU_MSG_DATA_3_RX_MSGSEQ_1	 0x03e8, 24, 8, 0xff000000
	#define BITFIELD_CRU_MSG_DATA_3_RX_MSGSEQ_0	 0x03e8, 16, 8, 0x00ff0000
	#define BITFIELD_CRU_MSG_DATA_3_RX_MSGID_9	 0x03e8, 8, 8, 0x0000ff00
	#define BITFIELD_CRU_MSG_DATA_3_RX_MSGID_8	 0x03e8, 0, 8, 0x000000ff
#define ROFF_CRU_TM_CMD	0x0 /* Configuration */ 
	#define BITFIELD_CRU_TM_CMD	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_TM_CMD */
	#define BLSB_CRU_TM_CMD_reserved	11
	#define BLSB_CRU_TM_CMD_VSYNC_SEL	10
	#define BLSB_CRU_TM_CMD_M150_300	9
	#define BLSB_CRU_TM_CMD_M300_BYPASS	8
	#define BLSB_CRU_TM_CMD_COMP_ENABLE	7
	#define BLSB_CRU_TM_CMD_MASTER_CLOCK	6
	#define BLSB_CRU_TM_CMD_MODE	4
	#define BLSB_CRU_TM_CMD_TS_SOURCE	0
	/* Register Bit Widths for CRU_TM_CMD */
	#define BWID_CRU_TM_CMD_reserved	21
	#define BWID_CRU_TM_CMD_VSYNC_SEL	1
	#define BWID_CRU_TM_CMD_M150_300	1
	#define BWID_CRU_TM_CMD_M300_BYPASS	1
	#define BWID_CRU_TM_CMD_COMP_ENABLE	1
	#define BWID_CRU_TM_CMD_MASTER_CLOCK	1
	#define BWID_CRU_TM_CMD_MODE	2
	#define BWID_CRU_TM_CMD_TS_SOURCE	4
	/* Register Bit MASKS for CRU_TM_CMD */
	#define BMSK_CRU_TM_CMD_reserved	0xfffff800 /* reserved */
	#define BMSK_CRU_TM_CMD_VSYNC_SEL	(1<<10) /* == 0x00000400: VSYNC timestamp src 0= PipeA 1= PipeB */
	#define BMSK_CRU_TM_CMD_M150_300	(1<<9) /* == 0x00000200: Enable 180kHz counter */
	#define BMSK_CRU_TM_CMD_M300_BYPASS	(1<<8) /* == 0x00000100: Enable 27MHz counter */
	#define BMSK_CRU_TM_CMD_COMP_ENABLE	(1<<7) /* == 0x00000080: Enable Event comparator */
	#define BMSK_CRU_TM_CMD_MASTER_CLOCK	(1<<6) /* == 0x00000040: use master clock (VCXO or DDS_0) to drive this timing channel */
	#define BMSK_CRU_TM_CMD_MODE	0x00000030 /* Enable 33-bit presentation counter comparison */
	#define BMSK_CRU_TM_CMD_TS_SOURCE	0x0000000f /* source for timestamping */
	/* Register BITFIELD for CRU_TM_CMD - roff, lsb, width, mask */
	#define BITFIELD_CRU_TM_CMD_reserved	 0x0000, 11, 21, 0xfffff800
	#define BITFIELD_CRU_TM_CMD_VSYNC_SEL	 0x0000, 10, 1, 0x00000400
	#define BITFIELD_CRU_TM_CMD_M150_300	 0x0000, 9, 1, 0x00000200
	#define BITFIELD_CRU_TM_CMD_M300_BYPASS	 0x0000, 8, 1, 0x00000100
	#define BITFIELD_CRU_TM_CMD_COMP_ENABLE	 0x0000, 7, 1, 0x00000080
	#define BITFIELD_CRU_TM_CMD_MASTER_CLOCK	 0x0000, 6, 1, 0x00000040
	#define BITFIELD_CRU_TM_CMD_MODE	 0x0000, 4, 2, 0x00000030
	#define BITFIELD_CRU_TM_CMD_TS_SOURCE	 0x0000, 0, 4, 0x0000000f
#define ROFF_CRU_DDS_PHASE	0x4 /* unused: dds phase */ 
	#define BITFIELD_CRU_DDS_PHASE	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_DDS_FREQ	0x8 /* DDS Frequency */ 
	#define BITFIELD_CRU_DDS_FREQ	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_DDS_FREQ */
	#define BLSB_CRU_DDS_FREQ_reserved	27
	#define BLSB_CRU_DDS_FREQ_DDS_FREQ	0
	/* Register Bit Widths for CRU_DDS_FREQ */
	#define BWID_CRU_DDS_FREQ_reserved	5
	#define BWID_CRU_DDS_FREQ_DDS_FREQ	27
	/* Register Bit MASKS for CRU_DDS_FREQ */
	#define BMSK_CRU_DDS_FREQ_reserved	0xf8000000 /* Reserved : Reads as 0 and writes are ignored */
	#define BMSK_CRU_DDS_FREQ_DDS_FREQ	0x07ffffff /* Frequency setting for DDS */
	/* Register BITFIELD for CRU_DDS_FREQ - roff, lsb, width, mask */
	#define BITFIELD_CRU_DDS_FREQ_reserved	 0x0008, 27, 5, 0xf8000000
	#define BITFIELD_CRU_DDS_FREQ_DDS_FREQ	 0x0008, 0, 27, 0x07ffffff
#define ROFF_CRU_GET_SYSTIME	0xc /* 32-Bit correlated timestamp from system timebase */ 
	#define BITFIELD_CRU_GET_SYSTIME	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SET_STC_LO	0x10 /* LSB of STC[31:0],  preset value for timebase  */ 
	#define BITFIELD_CRU_SET_STC_LO	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SET_STC_HI	0x14 /* Set value for prescaler for timebase channel,STC [33] */ 
	#define BITFIELD_CRU_SET_STC_HI	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_SET_STC_HI */
	#define BLSB_CRU_SET_STC_HI_reserved1	25
	#define BLSB_CRU_SET_STC_HI_PRESC_SET	16
	#define BLSB_CRU_SET_STC_HI_reserved0	10
	#define BLSB_CRU_SET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_SET_STC_HI */
	#define BWID_CRU_SET_STC_HI_reserved1	7
	#define BWID_CRU_SET_STC_HI_PRESC_SET	9
	#define BWID_CRU_SET_STC_HI_reserved0	6
	#define BWID_CRU_SET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_SET_STC_HI */
	#define BMSK_CRU_SET_STC_HI_reserved1	0xfe000000 /* reserved */
	#define BMSK_CRU_SET_STC_HI_PRESC_SET	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_SET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_SET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_SET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_SET_STC_HI_reserved1	 0x0014, 25, 7, 0xfe000000
	#define BITFIELD_CRU_SET_STC_HI_PRESC_SET	 0x0014, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_SET_STC_HI_reserved0	 0x0014, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_SET_STC_HI_MSB_STC	 0x0014, 0, 10, 0x000003ff
#define ROFF_CRU_GET_STC_LO	0x18 /* Correlated timestamp capture of STC */ 
	#define BITFIELD_CRU_GET_STC_LO	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_GET_STC_LO */
	#define BLSB_CRU_GET_STC_LO_Media_TB_UPD	31
	#define BLSB_CRU_GET_STC_LO_Unlock_TS	1
	#define BLSB_CRU_GET_STC_LO_Make_SW_TS	0
	/* Register Bit Widths for CRU_GET_STC_LO */
	#define BWID_CRU_GET_STC_LO_Media_TB_UPD	1
	#define BWID_CRU_GET_STC_LO_Unlock_TS	30
	#define BWID_CRU_GET_STC_LO_Make_SW_TS	1
	/* Register Bit MASKS for CRU_GET_STC_LO */
	#define BMSK_CRU_GET_STC_LO_Media_TB_UPD	(1<<31) /* == 0x80000000: Flag bit for writing SET_STC value in the wall clock.  MSB when read. */
	#define BMSK_CRU_GET_STC_LO_Unlock_TS	0x7ffffffe /* Enable new timestamp capture into LAST_TS_HI and LAST_TS_LO register */
	#define BMSK_CRU_GET_STC_LO_Make_SW_TS	(1<<0) /* == 0x00000001: SW trigger bit when written 1 to.  LSB of lower byte of wall clock when read */
	/* Register BITFIELD for CRU_GET_STC_LO - roff, lsb, width, mask */
	#define BITFIELD_CRU_GET_STC_LO_Media_TB_UPD	 0x0018, 31, 1, 0x80000000
	#define BITFIELD_CRU_GET_STC_LO_Unlock_TS	 0x0018, 1, 30, 0x7ffffffe
	#define BITFIELD_CRU_GET_STC_LO_Make_SW_TS	 0x0018, 0, 1, 0x00000001
#define ROFF_CRU_GET_STC_HI	0x1c /* Most significant bit of STC */ 
	#define BITFIELD_CRU_GET_STC_HI	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_GET_STC_HI */
	#define BLSB_CRU_GET_STC_HI_NEW_TS	31
	#define BLSB_CRU_GET_STC_HI_reserved	25
	#define BLSB_CRU_GET_STC_HI_PRESC	16
	#define BLSB_CRU_GET_STC_HI_reserved0	10
	#define BLSB_CRU_GET_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_GET_STC_HI */
	#define BWID_CRU_GET_STC_HI_NEW_TS	1
	#define BWID_CRU_GET_STC_HI_reserved	6
	#define BWID_CRU_GET_STC_HI_PRESC	9
	#define BWID_CRU_GET_STC_HI_reserved0	6
	#define BWID_CRU_GET_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_GET_STC_HI */
	#define BMSK_CRU_GET_STC_HI_NEW_TS	(1<<31) /* == 0x80000000: set when timestamp registers are updated by hardware  */
	#define BMSK_CRU_GET_STC_HI_reserved	0x7e000000 /* reserved */
	#define BMSK_CRU_GET_STC_HI_PRESC	0x01ff0000 /* The new data to be written into prescaler register */
	#define BMSK_CRU_GET_STC_HI_reserved0	0x0000fc00 /* reserved */
	#define BMSK_CRU_GET_STC_HI_MSB_STC	0x000003ff /* Desired value of Bit 32 of the STC counter in Chan */
	/* Register BITFIELD for CRU_GET_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_GET_STC_HI_NEW_TS	 0x001c, 31, 1, 0x80000000
	#define BITFIELD_CRU_GET_STC_HI_reserved	 0x001c, 25, 6, 0x7e000000
	#define BITFIELD_CRU_GET_STC_HI_PRESC	 0x001c, 16, 9, 0x01ff0000
	#define BITFIELD_CRU_GET_STC_HI_reserved0	 0x001c, 10, 6, 0x0000fc00
	#define BITFIELD_CRU_GET_STC_HI_MSB_STC	 0x001c, 0, 10, 0x000003ff
#define ROFF_CRU_COMP_LO	0x20 /* Event Comparison time for Channel 1, least significant bits */ 
	#define BITFIELD_CRU_COMP_LO	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_COMP_HI	0x24 /* Event Comparison time , MSB and prescaler */ 
	#define BITFIELD_CRU_COMP_HI	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_COMP_HI */
	#define BLSB_CRU_COMP_HI_reserved	10
	#define BLSB_CRU_COMP_HI_MSB_STC	0
	/* Register Bit Widths for CRU_COMP_HI */
	#define BWID_CRU_COMP_HI_reserved	22
	#define BWID_CRU_COMP_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_COMP_HI */
	#define BMSK_CRU_COMP_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_COMP_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_COMP_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_COMP_HI_reserved	 0x0024, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_COMP_HI_MSB_STC	 0x0024, 0, 10, 0x000003ff
#define ROFF_CRU_VSYNC_LO	0x28 /* Vertical Sync Timestamp */ 
	#define BITFIELD_CRU_VSYNC_LO	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_VSYNC_HI	0x2c /* Vertical Sync timestamp */ 
	#define BITFIELD_CRU_VSYNC_HI	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_VSYNC_HI */
	#define BLSB_CRU_VSYNC_HI_NEW_VSYNC	31
	#define BLSB_CRU_VSYNC_HI_reserved0	10
	#define BLSB_CRU_VSYNC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_VSYNC_HI */
	#define BWID_CRU_VSYNC_HI_NEW_VSYNC	1
	#define BWID_CRU_VSYNC_HI_reserved0	21
	#define BWID_CRU_VSYNC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_VSYNC_HI */
	#define BMSK_CRU_VSYNC_HI_NEW_VSYNC	(1<<31) /* == 0x80000000: indicates a new VSYNC event has occured and timestamp is captured */
	#define BMSK_CRU_VSYNC_HI_reserved0	0x7ffffc00 /* Reserved */
	#define BMSK_CRU_VSYNC_HI_MSB_STC	0x000003ff /* Captured value of bits 41:33 of the STC counter */
	/* Register BITFIELD for CRU_VSYNC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_VSYNC_HI_NEW_VSYNC	 0x002c, 31, 1, 0x80000000
	#define BITFIELD_CRU_VSYNC_HI_reserved0	 0x002c, 10, 21, 0x7ffffc00
	#define BITFIELD_CRU_VSYNC_HI_MSB_STC	 0x002c, 0, 10, 0x000003ff
#define ROFF_CRU_STC_LO	0x30 /* Current time from STC */ 
	#define BITFIELD_CRU_STC_LO	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_STC_HI	0x34 /* Most significant bits of STC */ 
	#define BITFIELD_CRU_STC_HI	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for CRU_STC_HI */
	#define BLSB_CRU_STC_HI_reserved	10
	#define BLSB_CRU_STC_HI_MSB_STC	0
	/* Register Bit Widths for CRU_STC_HI */
	#define BWID_CRU_STC_HI_reserved	22
	#define BWID_CRU_STC_HI_MSB_STC	10
	/* Register Bit MASKS for CRU_STC_HI */
	#define BMSK_CRU_STC_HI_reserved	0xfffffc00 /* Reserved */
	#define BMSK_CRU_STC_HI_MSB_STC	0x000003ff /* Bits 41:32 of COMPARE register  */
	/* Register BITFIELD for CRU_STC_HI - roff, lsb, width, mask */
	#define BITFIELD_CRU_STC_HI_reserved	 0x0034, 10, 22, 0xfffffc00
	#define BITFIELD_CRU_STC_HI_MSB_STC	 0x0034, 0, 10, 0x000003ff
#define ROFF_CRU_UNIT_BASE	0x0 /* Base of CRU */ 
	#define BITFIELD_CRU_UNIT_BASE	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_BASE_DIFF	0x40 /* Interval of Sub-units */ 
	#define BITFIELD_CRU_SUBUNIT_BASE_DIFF	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_0_BASE	0x0 /* Base of Unit 0 */ 
	#define BITFIELD_CRU_SUBUNIT_0_BASE	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_1_BASE	0x40 /* Base of Unit 1 */ 
	#define BITFIELD_CRU_SUBUNIT_1_BASE	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_2_BASE	0x80 /* Base of Unit 2 */ 
	#define BITFIELD_CRU_SUBUNIT_2_BASE	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_3_BASE	0xc0 /* Base of Unit 3 */ 
	#define BITFIELD_CRU_SUBUNIT_3_BASE	 0x00c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_4_BASE	0x100 /* Base of Unit 4 */ 
	#define BITFIELD_CRU_SUBUNIT_4_BASE	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_5_BASE	0x140 /* Base of Unit 5 */ 
	#define BITFIELD_CRU_SUBUNIT_5_BASE	 0x0140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_6_BASE	0x180 /* Base of Unit 6 */ 
	#define BITFIELD_CRU_SUBUNIT_6_BASE	 0x0180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_7_BASE	0x1c0 /* Base of Unit 7 */ 
	#define BITFIELD_CRU_SUBUNIT_7_BASE	 0x01c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_CRU_SUBUNIT_8_BASE	0x240 /* Base of Unit 8 */ 
	#define BITFIELD_CRU_SUBUNIT_8_BASE	 0x0240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module CRU SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_CRU_HAL_ISR_WITH_NO_ALARM	0x1


#endif /* CRU_REGOFFS_H */
