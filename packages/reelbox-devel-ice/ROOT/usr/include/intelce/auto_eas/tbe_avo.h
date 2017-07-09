#ifndef AVO_REGOFFS_H
#define AVO_REGOFFS_H 1
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


/* Module AVO CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_AVO_VERSION	0x0 /* AVO Version Register */ 
	#define BITFIELD_AVO_VERSION	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_VERSION */
	#define BLSB_AVO_VERSION_RSVD_31_16	16
	#define BLSB_AVO_VERSION_Year	12
	#define BLSB_AVO_VERSION_Month	8
	#define BLSB_AVO_VERSION_Date	3
	#define BLSB_AVO_VERSION_Version	0
	/* Register Bit Widths for AVO_VERSION */
	#define BWID_AVO_VERSION_RSVD_31_16	16
	#define BWID_AVO_VERSION_Year	4
	#define BWID_AVO_VERSION_Month	4
	#define BWID_AVO_VERSION_Date	5
	#define BWID_AVO_VERSION_Version	3
	/* Register Bit MASKS for AVO_VERSION */
	#define BMSK_AVO_VERSION_RSVD_31_16	0xffff0000 /*  */
	#define BMSK_AVO_VERSION_Year	0x0000f000 /*  */
	#define BMSK_AVO_VERSION_Month	0x00000f00 /*  */
	#define BMSK_AVO_VERSION_Date	0x000000f8 /*  */
	#define BMSK_AVO_VERSION_Version	0x00000007 /*  */
	/* Register BITFIELD for AVO_VERSION - roff, lsb, width, mask */
	#define BITFIELD_AVO_VERSION_RSVD_31_16	 0x0000, 16, 16, 0xffff0000
	#define BITFIELD_AVO_VERSION_Year	 0x0000, 12, 4, 0x0000f000
	#define BITFIELD_AVO_VERSION_Month	 0x0000, 8, 4, 0x00000f00
	#define BITFIELD_AVO_VERSION_Date	 0x0000, 3, 5, 0x000000f8
	#define BITFIELD_AVO_VERSION_Version	 0x0000, 0, 3, 0x00000007
#define ROFF_AVO_ID	0x4 /* AVO ID Register */ 
	#define BITFIELD_AVO_ID	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_ID */
	#define BLSB_AVO_ID_RSVD_31_16	16
	#define BLSB_AVO_ID_FPGA_ID	12
	#define BLSB_AVO_ID_FEATURE_ID	8
	#define BLSB_AVO_ID_PROJECT_ID	0
	/* Register Bit Widths for AVO_ID */
	#define BWID_AVO_ID_RSVD_31_16	16
	#define BWID_AVO_ID_FPGA_ID	4
	#define BWID_AVO_ID_FEATURE_ID	4
	#define BWID_AVO_ID_PROJECT_ID	8
	/* Register Bit MASKS for AVO_ID */
	#define BMSK_AVO_ID_RSVD_31_16	0xffff0000 /*  */
	#define BMSK_AVO_ID_FPGA_ID	0x0000f000 /*  */
	#define BMSK_AVO_ID_FEATURE_ID	0x00000f00 /*  */
	#define BMSK_AVO_ID_PROJECT_ID	0x000000ff /*  */
	/* Register BITFIELD for AVO_ID - roff, lsb, width, mask */
	#define BITFIELD_AVO_ID_RSVD_31_16	 0x0004, 16, 16, 0xffff0000
	#define BITFIELD_AVO_ID_FPGA_ID	 0x0004, 12, 4, 0x0000f000
	#define BITFIELD_AVO_ID_FEATURE_ID	 0x0004, 8, 4, 0x00000f00
	#define BITFIELD_AVO_ID_PROJECT_ID	 0x0004, 0, 8, 0x000000ff
#define ROFF_AVO_CONTROL	0x8 /* Master Control Register */ 
	#define BITFIELD_AVO_CONTROL	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_CONTROL */
	#define BLSB_AVO_CONTROL_RSVD_31_18	28
	#define BLSB_AVO_CONTROL_Reset_Strap_Enable	27
	#define BLSB_AVO_CONTROL_LB_Select	26
	#define BLSB_AVO_CONTROL_SD_Select	25
	#define BLSB_AVO_CONTROL_HD_Select	24
	#define BLSB_AVO_CONTROL_AUDIO_MODE	22
	#define BLSB_AVO_CONTROL_PCOMP_ON	21
	#define BLSB_AVO_CONTROL_Global_PLLENA	20
	#define BLSB_AVO_CONTROL_IEEE1394_PLL_RST	19
	#define BLSB_AVO_CONTROL_MSPOD_PLL_RST	18
	#define BLSB_AVO_CONTROL_AUXSD_PLL_RST	17
	#define BLSB_AVO_CONTROL_AUXHD_PLL_RST	16
	#define BLSB_AVO_CONTROL_MDVO_PLL_RST	15
	#define BLSB_AVO_CONTROL_VIDEO_PLL_RST	14
	#define BLSB_AVO_CONTROL_DDR_PLL_RST	13
	#define BLSB_AVO_CONTROL_AUX_VIDEO_RST_N	12
	#define BLSB_AVO_CONTROL_PCOMP_RST_N	11
	#define BLSB_AVO_CONTROL_HRESET_N	10
	#define BLSB_AVO_CONTROL_AUDIO_RST_N	9
	#define BLSB_AVO_CONTROL_MDVO_RST_N	8
	#define BLSB_AVO_CONTROL_SPD_SCL_PIN_STAT	7
	#define BLSB_AVO_CONTROL_SPD_SDA_PIN_STAT	6
	#define BLSB_AVO_CONTROL_SPD_SCL_PIN_CTRL	5
	#define BLSB_AVO_CONTROL_SPD_SDA_PIN_CTRL	4
	#define BLSB_AVO_CONTROL_LED3	3
	#define BLSB_AVO_CONTROL_LED2	2
	#define BLSB_AVO_CONTROL_LED1	1
	#define BLSB_AVO_CONTROL_LED0	0
	/* Register Bit Widths for AVO_CONTROL */
	#define BWID_AVO_CONTROL_RSVD_31_18	4
	#define BWID_AVO_CONTROL_Reset_Strap_Enable	1
	#define BWID_AVO_CONTROL_LB_Select	1
	#define BWID_AVO_CONTROL_SD_Select	1
	#define BWID_AVO_CONTROL_HD_Select	1
	#define BWID_AVO_CONTROL_AUDIO_MODE	2
	#define BWID_AVO_CONTROL_PCOMP_ON	1
	#define BWID_AVO_CONTROL_Global_PLLENA	1
	#define BWID_AVO_CONTROL_IEEE1394_PLL_RST	1
	#define BWID_AVO_CONTROL_MSPOD_PLL_RST	1
	#define BWID_AVO_CONTROL_AUXSD_PLL_RST	1
	#define BWID_AVO_CONTROL_AUXHD_PLL_RST	1
	#define BWID_AVO_CONTROL_MDVO_PLL_RST	1
	#define BWID_AVO_CONTROL_VIDEO_PLL_RST	1
	#define BWID_AVO_CONTROL_DDR_PLL_RST	1
	#define BWID_AVO_CONTROL_AUX_VIDEO_RST_N	1
	#define BWID_AVO_CONTROL_PCOMP_RST_N	1
	#define BWID_AVO_CONTROL_HRESET_N	1
	#define BWID_AVO_CONTROL_AUDIO_RST_N	1
	#define BWID_AVO_CONTROL_MDVO_RST_N	1
	#define BWID_AVO_CONTROL_SPD_SCL_PIN_STAT	1
	#define BWID_AVO_CONTROL_SPD_SDA_PIN_STAT	1
	#define BWID_AVO_CONTROL_SPD_SCL_PIN_CTRL	1
	#define BWID_AVO_CONTROL_SPD_SDA_PIN_CTRL	1
	#define BWID_AVO_CONTROL_LED3	1
	#define BWID_AVO_CONTROL_LED2	1
	#define BWID_AVO_CONTROL_LED1	1
	#define BWID_AVO_CONTROL_LED0	1
	/* Register Bit MASKS for AVO_CONTROL */
	#define BMSK_AVO_CONTROL_RSVD_31_18	0xf0000000 /*  */
	#define BMSK_AVO_CONTROL_Reset_Strap_Enable	(1<<27) /* == 0x08000000:  */
	#define BMSK_AVO_CONTROL_LB_Select	(1<<26) /* == 0x04000000:  */
	#define BMSK_AVO_CONTROL_SD_Select	(1<<25) /* == 0x02000000:  */
	#define BMSK_AVO_CONTROL_HD_Select	(1<<24) /* == 0x01000000:  */
	#define BMSK_AVO_CONTROL_AUDIO_MODE	0x00c00000 /*  */
	#define BMSK_AVO_CONTROL_PCOMP_ON	(1<<21) /* == 0x00200000:  */
	#define BMSK_AVO_CONTROL_Global_PLLENA	(1<<20) /* == 0x00100000:  */
	#define BMSK_AVO_CONTROL_IEEE1394_PLL_RST	(1<<19) /* == 0x00080000:  */
	#define BMSK_AVO_CONTROL_MSPOD_PLL_RST	(1<<18) /* == 0x00040000:  */
	#define BMSK_AVO_CONTROL_AUXSD_PLL_RST	(1<<17) /* == 0x00020000:  */
	#define BMSK_AVO_CONTROL_AUXHD_PLL_RST	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVO_CONTROL_MDVO_PLL_RST	(1<<15) /* == 0x00008000:  */
	#define BMSK_AVO_CONTROL_VIDEO_PLL_RST	(1<<14) /* == 0x00004000:  */
	#define BMSK_AVO_CONTROL_DDR_PLL_RST	(1<<13) /* == 0x00002000:  */
	#define BMSK_AVO_CONTROL_AUX_VIDEO_RST_N	(1<<12) /* == 0x00001000:  */
	#define BMSK_AVO_CONTROL_PCOMP_RST_N	(1<<11) /* == 0x00000800:  */
	#define BMSK_AVO_CONTROL_HRESET_N	(1<<10) /* == 0x00000400:  */
	#define BMSK_AVO_CONTROL_AUDIO_RST_N	(1<<9) /* == 0x00000200:  */
	#define BMSK_AVO_CONTROL_MDVO_RST_N	(1<<8) /* == 0x00000100:  */
	#define BMSK_AVO_CONTROL_SPD_SCL_PIN_STAT	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVO_CONTROL_SPD_SDA_PIN_STAT	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVO_CONTROL_SPD_SCL_PIN_CTRL	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVO_CONTROL_SPD_SDA_PIN_CTRL	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVO_CONTROL_LED3	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVO_CONTROL_LED2	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_CONTROL_LED1	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_CONTROL_LED0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVO_CONTROL_RSVD_31_18	 0x0008, 28, 4, 0xf0000000
	#define BITFIELD_AVO_CONTROL_Reset_Strap_Enable	 0x0008, 27, 1, 0x08000000
	#define BITFIELD_AVO_CONTROL_LB_Select	 0x0008, 26, 1, 0x04000000
	#define BITFIELD_AVO_CONTROL_SD_Select	 0x0008, 25, 1, 0x02000000
	#define BITFIELD_AVO_CONTROL_HD_Select	 0x0008, 24, 1, 0x01000000
	#define BITFIELD_AVO_CONTROL_AUDIO_MODE	 0x0008, 22, 2, 0x00c00000
	#define BITFIELD_AVO_CONTROL_PCOMP_ON	 0x0008, 21, 1, 0x00200000
	#define BITFIELD_AVO_CONTROL_Global_PLLENA	 0x0008, 20, 1, 0x00100000
	#define BITFIELD_AVO_CONTROL_IEEE1394_PLL_RST	 0x0008, 19, 1, 0x00080000
	#define BITFIELD_AVO_CONTROL_MSPOD_PLL_RST	 0x0008, 18, 1, 0x00040000
	#define BITFIELD_AVO_CONTROL_AUXSD_PLL_RST	 0x0008, 17, 1, 0x00020000
	#define BITFIELD_AVO_CONTROL_AUXHD_PLL_RST	 0x0008, 16, 1, 0x00010000
	#define BITFIELD_AVO_CONTROL_MDVO_PLL_RST	 0x0008, 15, 1, 0x00008000
	#define BITFIELD_AVO_CONTROL_VIDEO_PLL_RST	 0x0008, 14, 1, 0x00004000
	#define BITFIELD_AVO_CONTROL_DDR_PLL_RST	 0x0008, 13, 1, 0x00002000
	#define BITFIELD_AVO_CONTROL_AUX_VIDEO_RST_N	 0x0008, 12, 1, 0x00001000
	#define BITFIELD_AVO_CONTROL_PCOMP_RST_N	 0x0008, 11, 1, 0x00000800
	#define BITFIELD_AVO_CONTROL_HRESET_N	 0x0008, 10, 1, 0x00000400
	#define BITFIELD_AVO_CONTROL_AUDIO_RST_N	 0x0008, 9, 1, 0x00000200
	#define BITFIELD_AVO_CONTROL_MDVO_RST_N	 0x0008, 8, 1, 0x00000100
	#define BITFIELD_AVO_CONTROL_SPD_SCL_PIN_STAT	 0x0008, 7, 1, 0x00000080
	#define BITFIELD_AVO_CONTROL_SPD_SDA_PIN_STAT	 0x0008, 6, 1, 0x00000040
	#define BITFIELD_AVO_CONTROL_SPD_SCL_PIN_CTRL	 0x0008, 5, 1, 0x00000020
	#define BITFIELD_AVO_CONTROL_SPD_SDA_PIN_CTRL	 0x0008, 4, 1, 0x00000010
	#define BITFIELD_AVO_CONTROL_LED3	 0x0008, 3, 1, 0x00000008
	#define BITFIELD_AVO_CONTROL_LED2	 0x0008, 2, 1, 0x00000004
	#define BITFIELD_AVO_CONTROL_LED1	 0x0008, 1, 1, 0x00000002
	#define BITFIELD_AVO_CONTROL_LED0	 0x0008, 0, 1, 0x00000001
#define ROFF_AVO_STATUS	0xc /* Master Status Register */ 
	#define BITFIELD_AVO_STATUS	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_STATUS */
	#define BLSB_AVO_STATUS_RSVD_31_9	9
	#define BLSB_AVO_STATUS_DDR_INIT	8
	#define BLSB_AVO_STATUS_IEEE1394_PLL_LOCK	7
	#define BLSB_AVO_STATUS_MSPOD_PLL_LOCK	6
	#define BLSB_AVO_STATUS_AUXSD_PLL_LOCK	5
	#define BLSB_AVO_STATUS_AUXHD_PLL_LOCK	4
	#define BLSB_AVO_STATUS_LB_PLL_LOCK	3
	#define BLSB_AVO_STATUS_MDVO_PLL_LOCK	2
	#define BLSB_AVO_STATUS_VIDEO_PLL_LOCK	1
	#define BLSB_AVO_STATUS_DDR_PLL_LOCK	0
	/* Register Bit Widths for AVO_STATUS */
	#define BWID_AVO_STATUS_RSVD_31_9	23
	#define BWID_AVO_STATUS_DDR_INIT	1
	#define BWID_AVO_STATUS_IEEE1394_PLL_LOCK	1
	#define BWID_AVO_STATUS_MSPOD_PLL_LOCK	1
	#define BWID_AVO_STATUS_AUXSD_PLL_LOCK	1
	#define BWID_AVO_STATUS_AUXHD_PLL_LOCK	1
	#define BWID_AVO_STATUS_LB_PLL_LOCK	1
	#define BWID_AVO_STATUS_MDVO_PLL_LOCK	1
	#define BWID_AVO_STATUS_VIDEO_PLL_LOCK	1
	#define BWID_AVO_STATUS_DDR_PLL_LOCK	1
	/* Register Bit MASKS for AVO_STATUS */
	#define BMSK_AVO_STATUS_RSVD_31_9	0xfffffe00 /*  */
	#define BMSK_AVO_STATUS_DDR_INIT	(1<<8) /* == 0x00000100:  */
	#define BMSK_AVO_STATUS_IEEE1394_PLL_LOCK	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVO_STATUS_MSPOD_PLL_LOCK	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVO_STATUS_AUXSD_PLL_LOCK	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVO_STATUS_AUXHD_PLL_LOCK	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVO_STATUS_LB_PLL_LOCK	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVO_STATUS_MDVO_PLL_LOCK	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_STATUS_VIDEO_PLL_LOCK	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_STATUS_DDR_PLL_LOCK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_STATUS - roff, lsb, width, mask */
	#define BITFIELD_AVO_STATUS_RSVD_31_9	 0x000c, 9, 23, 0xfffffe00
	#define BITFIELD_AVO_STATUS_DDR_INIT	 0x000c, 8, 1, 0x00000100
	#define BITFIELD_AVO_STATUS_IEEE1394_PLL_LOCK	 0x000c, 7, 1, 0x00000080
	#define BITFIELD_AVO_STATUS_MSPOD_PLL_LOCK	 0x000c, 6, 1, 0x00000040
	#define BITFIELD_AVO_STATUS_AUXSD_PLL_LOCK	 0x000c, 5, 1, 0x00000020
	#define BITFIELD_AVO_STATUS_AUXHD_PLL_LOCK	 0x000c, 4, 1, 0x00000010
	#define BITFIELD_AVO_STATUS_LB_PLL_LOCK	 0x000c, 3, 1, 0x00000008
	#define BITFIELD_AVO_STATUS_MDVO_PLL_LOCK	 0x000c, 2, 1, 0x00000004
	#define BITFIELD_AVO_STATUS_VIDEO_PLL_LOCK	 0x000c, 1, 1, 0x00000002
	#define BITFIELD_AVO_STATUS_DDR_PLL_LOCK	 0x000c, 0, 1, 0x00000001
#define ROFF_AVO_MDVO_CONTROL	0x0 /* MDVO Capture Interface Unit Control Register */ 
	#define BITFIELD_AVO_MDVO_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_CONTROL */
	#define BLSB_AVO_MDVO_CONTROL_Signal_Capture_Mode	31
	#define BLSB_AVO_MDVO_CONTROL_MDVO_mem_agnt_loopctrl_7_0	23
	#define BLSB_AVO_MDVO_CONTROL_MDVO_mem_agnt_burst_size_4_0	18
	#define BLSB_AVO_MDVO_CONTROL_MDVO_mem_agnt_mode_1_0	16
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_sclk	15
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_sen_n	14
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_fwft_si	13
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_partial_reset_l	12
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_master_reset_l	11
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_ld_n	10
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_fsel1	9
	#define BLSB_AVO_MDVO_CONTROL_Ext_fifo_fsel0	8
	#define BLSB_AVO_MDVO_CONTROL_PreDAC_Mode	7
	#define BLSB_AVO_MDVO_CONTROL_Mem_agnt_go	6
	#define BLSB_AVO_MDVO_CONTROL_Blanking	5
	#define BLSB_AVO_MDVO_CONTROL_Mem_Agent_En	4
	#define BLSB_AVO_MDVO_CONTROL_Enable	3
	#define BLSB_AVO_MDVO_CONTROL_Format	0
	/* Register Bit Widths for AVO_MDVO_CONTROL */
	#define BWID_AVO_MDVO_CONTROL_Signal_Capture_Mode	1
	#define BWID_AVO_MDVO_CONTROL_MDVO_mem_agnt_loopctrl_7_0	8
	#define BWID_AVO_MDVO_CONTROL_MDVO_mem_agnt_burst_size_4_0	5
	#define BWID_AVO_MDVO_CONTROL_MDVO_mem_agnt_mode_1_0	2
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_sclk	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_sen_n	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_fwft_si	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_partial_reset_l	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_master_reset_l	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_ld_n	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_fsel1	1
	#define BWID_AVO_MDVO_CONTROL_Ext_fifo_fsel0	1
	#define BWID_AVO_MDVO_CONTROL_PreDAC_Mode	1
	#define BWID_AVO_MDVO_CONTROL_Mem_agnt_go	1
	#define BWID_AVO_MDVO_CONTROL_Blanking	1
	#define BWID_AVO_MDVO_CONTROL_Mem_Agent_En	1
	#define BWID_AVO_MDVO_CONTROL_Enable	1
	#define BWID_AVO_MDVO_CONTROL_Format	3
	/* Register Bit MASKS for AVO_MDVO_CONTROL */
	#define BMSK_AVO_MDVO_CONTROL_Signal_Capture_Mode	(1<<31) /* == 0x80000000:  */
	#define BMSK_AVO_MDVO_CONTROL_MDVO_mem_agnt_loopctrl_7_0	0x7f800000 /*  */
	#define BMSK_AVO_MDVO_CONTROL_MDVO_mem_agnt_burst_size_4_0	0x007c0000 /*  */
	#define BMSK_AVO_MDVO_CONTROL_MDVO_mem_agnt_mode_1_0	0x00030000 /*  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_sclk	(1<<15) /* == 0x00008000:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_sen_n	(1<<14) /* == 0x00004000:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_fwft_si	(1<<13) /* == 0x00002000:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_partial_reset_l	(1<<12) /* == 0x00001000:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_master_reset_l	(1<<11) /* == 0x00000800:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_ld_n	(1<<10) /* == 0x00000400:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_fsel1	(1<<9) /* == 0x00000200:  */
	#define BMSK_AVO_MDVO_CONTROL_Ext_fifo_fsel0	(1<<8) /* == 0x00000100:  */
	#define BMSK_AVO_MDVO_CONTROL_PreDAC_Mode	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVO_MDVO_CONTROL_Mem_agnt_go	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVO_MDVO_CONTROL_Blanking	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVO_MDVO_CONTROL_Mem_Agent_En	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVO_MDVO_CONTROL_Enable	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVO_MDVO_CONTROL_Format	0x00000007 /*  */
	/* Register BITFIELD for AVO_MDVO_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_CONTROL_Signal_Capture_Mode	 0x0000, 31, 1, 0x80000000
	#define BITFIELD_AVO_MDVO_CONTROL_MDVO_mem_agnt_loopctrl_7_0	 0x0000, 23, 8, 0x7f800000
	#define BITFIELD_AVO_MDVO_CONTROL_MDVO_mem_agnt_burst_size_4_0	 0x0000, 18, 5, 0x007c0000
	#define BITFIELD_AVO_MDVO_CONTROL_MDVO_mem_agnt_mode_1_0	 0x0000, 16, 2, 0x00030000
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_sclk	 0x0000, 15, 1, 0x00008000
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_sen_n	 0x0000, 14, 1, 0x00004000
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_fwft_si	 0x0000, 13, 1, 0x00002000
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_partial_reset_l	 0x0000, 12, 1, 0x00001000
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_master_reset_l	 0x0000, 11, 1, 0x00000800
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_ld_n	 0x0000, 10, 1, 0x00000400
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_fsel1	 0x0000, 9, 1, 0x00000200
	#define BITFIELD_AVO_MDVO_CONTROL_Ext_fifo_fsel0	 0x0000, 8, 1, 0x00000100
	#define BITFIELD_AVO_MDVO_CONTROL_PreDAC_Mode	 0x0000, 7, 1, 0x00000080
	#define BITFIELD_AVO_MDVO_CONTROL_Mem_agnt_go	 0x0000, 6, 1, 0x00000040
	#define BITFIELD_AVO_MDVO_CONTROL_Blanking	 0x0000, 5, 1, 0x00000020
	#define BITFIELD_AVO_MDVO_CONTROL_Mem_Agent_En	 0x0000, 4, 1, 0x00000010
	#define BITFIELD_AVO_MDVO_CONTROL_Enable	 0x0000, 3, 1, 0x00000008
	#define BITFIELD_AVO_MDVO_CONTROL_Format	 0x0000, 0, 3, 0x00000007
#define ROFF_AVO_MDVO_STAT	0x4 /* MDVO Capture Interface Unit Status Register */ 
	#define BITFIELD_AVO_MDVO_STAT	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_STAT */
	#define BLSB_AVO_MDVO_STAT_RSVD_31_18	18
	#define BLSB_AVO_MDVO_STAT_Underrun_flag	17
	#define BLSB_AVO_MDVO_STAT_Loop_done	16
	#define BLSB_AVO_MDVO_STAT_MDVO_fifo_usedw	8
	#define BLSB_AVO_MDVO_STAT_Start_of_frame	7
	#define BLSB_AVO_MDVO_STAT_Ext_fifo_paf	6
	#define BLSB_AVO_MDVO_STAT_Ext_fifo_pae	5
	#define BLSB_AVO_MDVO_STAT_Ext_fifo_hf	4
	#define BLSB_AVO_MDVO_STAT_Ext_fifo_ff	3
	#define BLSB_AVO_MDVO_STAT_Ext_fifo_ef	2
	#define BLSB_AVO_MDVO_STAT_Fifo_overwrite	1
	#define BLSB_AVO_MDVO_STAT_RSVD_0	0
	/* Register Bit Widths for AVO_MDVO_STAT */
	#define BWID_AVO_MDVO_STAT_RSVD_31_18	14
	#define BWID_AVO_MDVO_STAT_Underrun_flag	1
	#define BWID_AVO_MDVO_STAT_Loop_done	1
	#define BWID_AVO_MDVO_STAT_MDVO_fifo_usedw	8
	#define BWID_AVO_MDVO_STAT_Start_of_frame	1
	#define BWID_AVO_MDVO_STAT_Ext_fifo_paf	1
	#define BWID_AVO_MDVO_STAT_Ext_fifo_pae	1
	#define BWID_AVO_MDVO_STAT_Ext_fifo_hf	1
	#define BWID_AVO_MDVO_STAT_Ext_fifo_ff	1
	#define BWID_AVO_MDVO_STAT_Ext_fifo_ef	1
	#define BWID_AVO_MDVO_STAT_Fifo_overwrite	1
	#define BWID_AVO_MDVO_STAT_RSVD_0	1
	/* Register Bit MASKS for AVO_MDVO_STAT */
	#define BMSK_AVO_MDVO_STAT_RSVD_31_18	0xfffc0000 /*  */
	#define BMSK_AVO_MDVO_STAT_Underrun_flag	(1<<17) /* == 0x00020000:  */
	#define BMSK_AVO_MDVO_STAT_Loop_done	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVO_MDVO_STAT_MDVO_fifo_usedw	0x0000ff00 /*  */
	#define BMSK_AVO_MDVO_STAT_Start_of_frame	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVO_MDVO_STAT_Ext_fifo_paf	(1<<6) /* == 0x00000040:  */
	#define BMSK_AVO_MDVO_STAT_Ext_fifo_pae	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVO_MDVO_STAT_Ext_fifo_hf	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVO_MDVO_STAT_Ext_fifo_ff	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVO_MDVO_STAT_Ext_fifo_ef	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_MDVO_STAT_Fifo_overwrite	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_MDVO_STAT_RSVD_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_MDVO_STAT - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_STAT_RSVD_31_18	 0x0004, 18, 14, 0xfffc0000
	#define BITFIELD_AVO_MDVO_STAT_Underrun_flag	 0x0004, 17, 1, 0x00020000
	#define BITFIELD_AVO_MDVO_STAT_Loop_done	 0x0004, 16, 1, 0x00010000
	#define BITFIELD_AVO_MDVO_STAT_MDVO_fifo_usedw	 0x0004, 8, 8, 0x0000ff00
	#define BITFIELD_AVO_MDVO_STAT_Start_of_frame	 0x0004, 7, 1, 0x00000080
	#define BITFIELD_AVO_MDVO_STAT_Ext_fifo_paf	 0x0004, 6, 1, 0x00000040
	#define BITFIELD_AVO_MDVO_STAT_Ext_fifo_pae	 0x0004, 5, 1, 0x00000020
	#define BITFIELD_AVO_MDVO_STAT_Ext_fifo_hf	 0x0004, 4, 1, 0x00000010
	#define BITFIELD_AVO_MDVO_STAT_Ext_fifo_ff	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_AVO_MDVO_STAT_Ext_fifo_ef	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_AVO_MDVO_STAT_Fifo_overwrite	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_AVO_MDVO_STAT_RSVD_0	 0x0004, 0, 1, 0x00000001
#define ROFF_AVO_MDVO_START_ADDR	0x8 /* Starting Memory Address for the MDVO Memory Agent */ 
	#define BITFIELD_AVO_MDVO_START_ADDR	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_START_ADDR */
	#define BLSB_AVO_MDVO_START_ADDR_Start_Pointer	0
	/* Register Bit Widths for AVO_MDVO_START_ADDR */
	#define BWID_AVO_MDVO_START_ADDR_Start_Pointer	32
	/* Register Bit MASKS for AVO_MDVO_START_ADDR */
	#define BMSK_AVO_MDVO_START_ADDR_Start_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_MDVO_START_ADDR - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_START_ADDR_Start_Pointer	 0x0008, 0, 32, 0x00000000
#define ROFF_AVO_MDVO_END_ADDR	0xc /* Ending Memory Address for the MDVO Memory Agent */ 
	#define BITFIELD_AVO_MDVO_END_ADDR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_END_ADDR */
	#define BLSB_AVO_MDVO_END_ADDR_End_Pointer	0
	/* Register Bit Widths for AVO_MDVO_END_ADDR */
	#define BWID_AVO_MDVO_END_ADDR_End_Pointer	32
	/* Register Bit MASKS for AVO_MDVO_END_ADDR */
	#define BMSK_AVO_MDVO_END_ADDR_End_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_MDVO_END_ADDR - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_END_ADDR_End_Pointer	 0x000c, 0, 32, 0x00000000
#define ROFF_AVO_MDVO_WRITE_PTR	0x10 /* Write Pointer Register for the MDVO Memory Agent */ 
	#define BITFIELD_AVO_MDVO_WRITE_PTR	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_WRITE_PTR */
	#define BLSB_AVO_MDVO_WRITE_PTR_Write_Pointer	0
	/* Register Bit Widths for AVO_MDVO_WRITE_PTR */
	#define BWID_AVO_MDVO_WRITE_PTR_Write_Pointer	32
	/* Register Bit MASKS for AVO_MDVO_WRITE_PTR */
	#define BMSK_AVO_MDVO_WRITE_PTR_Write_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_MDVO_WRITE_PTR - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_WRITE_PTR_Write_Pointer	 0x0010, 0, 32, 0x00000000
#define ROFF_AVO_MDVO_READ_PTR	0x14 /* Read Pointer Register for the MDVO Memory Agent */ 
	#define BITFIELD_AVO_MDVO_READ_PTR	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_READ_PTR */
	#define BLSB_AVO_MDVO_READ_PTR_Read_Pointer	0
	/* Register Bit Widths for AVO_MDVO_READ_PTR */
	#define BWID_AVO_MDVO_READ_PTR_Read_Pointer	32
	/* Register Bit MASKS for AVO_MDVO_READ_PTR */
	#define BMSK_AVO_MDVO_READ_PTR_Read_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_MDVO_READ_PTR - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_READ_PTR_Read_Pointer	 0x0014, 0, 32, 0x00000000
#define ROFF_AVO_MDVO_FRAME_COUNTER	0x18 /* Frame counter for the MDVO Packing State Machine Block */ 
	#define BITFIELD_AVO_MDVO_FRAME_COUNTER	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_FRAME_COUNTER */
	#define BLSB_AVO_MDVO_FRAME_COUNTER_Frame_Counter	0
	/* Register Bit Widths for AVO_MDVO_FRAME_COUNTER */
	#define BWID_AVO_MDVO_FRAME_COUNTER_Frame_Counter	32
	/* Register Bit MASKS for AVO_MDVO_FRAME_COUNTER */
	#define BMSK_AVO_MDVO_FRAME_COUNTER_Frame_Counter	0x00000000 /*  */
	/* Register BITFIELD for AVO_MDVO_FRAME_COUNTER - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_FRAME_COUNTER_Frame_Counter	 0x0018, 0, 32, 0x00000000
#define ROFF_AVO_MDVO_MISC_COUNTER	0x1c /* Miscellaneous counters and flags in MDVO Packing State Machine Block */ 
	#define BITFIELD_AVO_MDVO_MISC_COUNTER	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_MDVO_MISC_COUNTER */
	#define BLSB_AVO_MDVO_MISC_COUNTER_MDVO_Flags	24
	#define BLSB_AVO_MDVO_MISC_COUNTER_RSVD	23
	#define BLSB_AVO_MDVO_MISC_COUNTER_Line_Counter	12
	#define BLSB_AVO_MDVO_MISC_COUNTER_Pixel_Counter	0
	/* Register Bit Widths for AVO_MDVO_MISC_COUNTER */
	#define BWID_AVO_MDVO_MISC_COUNTER_MDVO_Flags	8
	#define BWID_AVO_MDVO_MISC_COUNTER_RSVD	1
	#define BWID_AVO_MDVO_MISC_COUNTER_Line_Counter	11
	#define BWID_AVO_MDVO_MISC_COUNTER_Pixel_Counter	12
	/* Register Bit MASKS for AVO_MDVO_MISC_COUNTER */
	#define BMSK_AVO_MDVO_MISC_COUNTER_MDVO_Flags	0xff000000 /*  */
	#define BMSK_AVO_MDVO_MISC_COUNTER_RSVD	(1<<23) /* == 0x00800000:  */
	#define BMSK_AVO_MDVO_MISC_COUNTER_Line_Counter	0x007ff000 /*  */
	#define BMSK_AVO_MDVO_MISC_COUNTER_Pixel_Counter	0x00000fff /*  */
	/* Register BITFIELD for AVO_MDVO_MISC_COUNTER - roff, lsb, width, mask */
	#define BITFIELD_AVO_MDVO_MISC_COUNTER_MDVO_Flags	 0x001c, 24, 8, 0xff000000
	#define BITFIELD_AVO_MDVO_MISC_COUNTER_RSVD	 0x001c, 23, 1, 0x00800000
	#define BITFIELD_AVO_MDVO_MISC_COUNTER_Line_Counter	 0x001c, 12, 11, 0x007ff000
	#define BITFIELD_AVO_MDVO_MISC_COUNTER_Pixel_Counter	 0x001c, 0, 12, 0x00000fff
#define ROFF_AVO_AUXSD_CONTROL	0x0 /* AUXSD Capture Interface Unit Control Register */ 
	#define BITFIELD_AVO_AUXSD_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_CONTROL */
	#define BLSB_AVO_AUXSD_CONTROL_RSVD	31
	#define BLSB_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_loopctrl_7_0	23
	#define BLSB_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_burst_size_4_0	18
	#define BLSB_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_mode_1_0	16
	#define BLSB_AVO_AUXSD_CONTROL_RSVD_15_6	6
	#define BLSB_AVO_AUXSD_CONTROL_Blanking	5
	#define BLSB_AVO_AUXSD_CONTROL_MEM_AGENT_EN	4
	#define BLSB_AVO_AUXSD_CONTROL_Enable	3
	#define BLSB_AVO_AUXSD_CONTROL_Reserved	2
	#define BLSB_AVO_AUXSD_CONTROL_Reset_Counters	1
	#define BLSB_AVO_AUXSD_CONTROL_Storage_CRC_mode	0
	/* Register Bit Widths for AVO_AUXSD_CONTROL */
	#define BWID_AVO_AUXSD_CONTROL_RSVD	1
	#define BWID_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_loopctrl_7_0	8
	#define BWID_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_burst_size_4_0	5
	#define BWID_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_mode_1_0	2
	#define BWID_AVO_AUXSD_CONTROL_RSVD_15_6	10
	#define BWID_AVO_AUXSD_CONTROL_Blanking	1
	#define BWID_AVO_AUXSD_CONTROL_MEM_AGENT_EN	1
	#define BWID_AVO_AUXSD_CONTROL_Enable	1
	#define BWID_AVO_AUXSD_CONTROL_Reserved	1
	#define BWID_AVO_AUXSD_CONTROL_Reset_Counters	1
	#define BWID_AVO_AUXSD_CONTROL_Storage_CRC_mode	1
	/* Register Bit MASKS for AVO_AUXSD_CONTROL */
	#define BMSK_AVO_AUXSD_CONTROL_RSVD	(1<<31) /* == 0x80000000:  */
	#define BMSK_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_loopctrl_7_0	0x7f800000 /*  */
	#define BMSK_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_burst_size_4_0	0x007c0000 /*  */
	#define BMSK_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_mode_1_0	0x00030000 /*  */
	#define BMSK_AVO_AUXSD_CONTROL_RSVD_15_6	0x0000ffc0 /*  */
	#define BMSK_AVO_AUXSD_CONTROL_Blanking	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVO_AUXSD_CONTROL_MEM_AGENT_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVO_AUXSD_CONTROL_Enable	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVO_AUXSD_CONTROL_Reserved	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_AUXSD_CONTROL_Reset_Counters	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_AUXSD_CONTROL_Storage_CRC_mode	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_AUXSD_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_CONTROL_RSVD	 0x0000, 31, 1, 0x80000000
	#define BITFIELD_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_loopctrl_7_0	 0x0000, 23, 8, 0x7f800000
	#define BITFIELD_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_burst_size_4_0	 0x0000, 18, 5, 0x007c0000
	#define BITFIELD_AVO_AUXSD_CONTROL_AUXSD_mem_agnt_mode_1_0	 0x0000, 16, 2, 0x00030000
	#define BITFIELD_AVO_AUXSD_CONTROL_RSVD_15_6	 0x0000, 6, 10, 0x0000ffc0
	#define BITFIELD_AVO_AUXSD_CONTROL_Blanking	 0x0000, 5, 1, 0x00000020
	#define BITFIELD_AVO_AUXSD_CONTROL_MEM_AGENT_EN	 0x0000, 4, 1, 0x00000010
	#define BITFIELD_AVO_AUXSD_CONTROL_Enable	 0x0000, 3, 1, 0x00000008
	#define BITFIELD_AVO_AUXSD_CONTROL_Reserved	 0x0000, 2, 1, 0x00000004
	#define BITFIELD_AVO_AUXSD_CONTROL_Reset_Counters	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_AVO_AUXSD_CONTROL_Storage_CRC_mode	 0x0000, 0, 1, 0x00000001
#define ROFF_AVO_AUXSD_STAT	0x4 /* AUXSD Capture Interface Unit Status Register */ 
	#define BITFIELD_AVO_AUXSD_STAT	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_STAT */
	#define BLSB_AVO_AUXSD_STAT_RSVD_31_28	31
	#define BLSB_AVO_AUXSD_STAT_CRC_COMP_wusedw	27
	#define BLSB_AVO_AUXSD_STAT_RSVD_19_17	17
	#define BLSB_AVO_AUXSD_STAT_Loop_done	16
	#define BLSB_AVO_AUXSD_STAT_AUXSD_fifo_usedw	8
	#define BLSB_AVO_AUXSD_STAT_Start_of_frame	7
	#define BLSB_AVO_AUXSD_STAT_RSVD_6_3	3
	#define BLSB_AVO_AUXSD_STAT_Pixel_Error	2
	#define BLSB_AVO_AUXSD_STAT_Data_out_FIFO_Overwrite	1
	#define BLSB_AVO_AUXSD_STAT_CRC_in_FIFO_Underrun	0
	/* Register Bit Widths for AVO_AUXSD_STAT */
	#define BWID_AVO_AUXSD_STAT_RSVD_31_28	4
	#define BWID_AVO_AUXSD_STAT_CRC_COMP_wusedw	8
	#define BWID_AVO_AUXSD_STAT_RSVD_19_17	3
	#define BWID_AVO_AUXSD_STAT_Loop_done	1
	#define BWID_AVO_AUXSD_STAT_AUXSD_fifo_usedw	8
	#define BWID_AVO_AUXSD_STAT_Start_of_frame	1
	#define BWID_AVO_AUXSD_STAT_RSVD_6_3	4
	#define BWID_AVO_AUXSD_STAT_Pixel_Error	1
	#define BWID_AVO_AUXSD_STAT_Data_out_FIFO_Overwrite	1
	#define BWID_AVO_AUXSD_STAT_CRC_in_FIFO_Underrun	1
	/* Register Bit MASKS for AVO_AUXSD_STAT */
	#define BMSK_AVO_AUXSD_STAT_RSVD_31_28	0x80000000 /*  */
	#define BMSK_AVO_AUXSD_STAT_CRC_COMP_wusedw	0xf8000000 /*  */
	#define BMSK_AVO_AUXSD_STAT_RSVD_19_17	0x000e0000 /*  */
	#define BMSK_AVO_AUXSD_STAT_Loop_done	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVO_AUXSD_STAT_AUXSD_fifo_usedw	0x0000ff00 /*  */
	#define BMSK_AVO_AUXSD_STAT_Start_of_frame	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVO_AUXSD_STAT_RSVD_6_3	0x00000078 /*  */
	#define BMSK_AVO_AUXSD_STAT_Pixel_Error	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_AUXSD_STAT_Data_out_FIFO_Overwrite	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_AUXSD_STAT_CRC_in_FIFO_Underrun	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_AUXSD_STAT - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_STAT_RSVD_31_28	 0x0004, 31, 4, 0x80000000
	#define BITFIELD_AVO_AUXSD_STAT_CRC_COMP_wusedw	 0x0004, 27, 8, 0xf8000000
	#define BITFIELD_AVO_AUXSD_STAT_RSVD_19_17	 0x0004, 17, 3, 0x000e0000
	#define BITFIELD_AVO_AUXSD_STAT_Loop_done	 0x0004, 16, 1, 0x00010000
	#define BITFIELD_AVO_AUXSD_STAT_AUXSD_fifo_usedw	 0x0004, 8, 8, 0x0000ff00
	#define BITFIELD_AVO_AUXSD_STAT_Start_of_frame	 0x0004, 7, 1, 0x00000080
	#define BITFIELD_AVO_AUXSD_STAT_RSVD_6_3	 0x0004, 3, 4, 0x00000078
	#define BITFIELD_AVO_AUXSD_STAT_Pixel_Error	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_AVO_AUXSD_STAT_Data_out_FIFO_Overwrite	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_AVO_AUXSD_STAT_CRC_in_FIFO_Underrun	 0x0004, 0, 1, 0x00000001
#define ROFF_AVO_AUXSD_START_ADDR	0x8 /* Starting Memory Address for the AUXSD Memory Agent */ 
	#define BITFIELD_AVO_AUXSD_START_ADDR	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_START_ADDR */
	#define BLSB_AVO_AUXSD_START_ADDR_Start_Pointer	0
	/* Register Bit Widths for AVO_AUXSD_START_ADDR */
	#define BWID_AVO_AUXSD_START_ADDR_Start_Pointer	32
	/* Register Bit MASKS for AVO_AUXSD_START_ADDR */
	#define BMSK_AVO_AUXSD_START_ADDR_Start_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXSD_START_ADDR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_START_ADDR_Start_Pointer	 0x0008, 0, 32, 0x00000000
#define ROFF_AVO_AUXSD_END_ADDR	0xc /* I2S AVI Buffer End Address */ 
	#define BITFIELD_AVO_AUXSD_END_ADDR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_END_ADDR */
	#define BLSB_AVO_AUXSD_END_ADDR_End_Pointer	0
	/* Register Bit Widths for AVO_AUXSD_END_ADDR */
	#define BWID_AVO_AUXSD_END_ADDR_End_Pointer	32
	/* Register Bit MASKS for AVO_AUXSD_END_ADDR */
	#define BMSK_AVO_AUXSD_END_ADDR_End_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXSD_END_ADDR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_END_ADDR_End_Pointer	 0x000c, 0, 32, 0x00000000
#define ROFF_AVO_AUXSD_WRITE_PTR	0x10 /* I2S AVI Buffer Read Pointer */ 
	#define BITFIELD_AVO_AUXSD_WRITE_PTR	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_WRITE_PTR */
	#define BLSB_AVO_AUXSD_WRITE_PTR_Write_Pointer	0
	/* Register Bit Widths for AVO_AUXSD_WRITE_PTR */
	#define BWID_AVO_AUXSD_WRITE_PTR_Write_Pointer	32
	/* Register Bit MASKS for AVO_AUXSD_WRITE_PTR */
	#define BMSK_AVO_AUXSD_WRITE_PTR_Write_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXSD_WRITE_PTR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_WRITE_PTR_Write_Pointer	 0x0010, 0, 32, 0x00000000
#define ROFF_AVO_AUXSD_READ_PTR	0x14 /* Read Pointer Register for the AUXSD Memory Agent */ 
	#define BITFIELD_AVO_AUXSD_READ_PTR	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_READ_PTR */
	#define BLSB_AVO_AUXSD_READ_PTR_Read_Pointer	0
	/* Register Bit Widths for AVO_AUXSD_READ_PTR */
	#define BWID_AVO_AUXSD_READ_PTR_Read_Pointer	32
	/* Register Bit MASKS for AVO_AUXSD_READ_PTR */
	#define BMSK_AVO_AUXSD_READ_PTR_Read_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXSD_READ_PTR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_READ_PTR_Read_Pointer	 0x0014, 0, 32, 0x00000000
#define ROFF_AVO_AUXSD_FIELD_COUNTER	0x18 /* Field counter for the AUXSD Block */ 
	#define BITFIELD_AVO_AUXSD_FIELD_COUNTER	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_FIELD_COUNTER */
	#define BLSB_AVO_AUXSD_FIELD_COUNTER_Field_Counter	0
	/* Register Bit Widths for AVO_AUXSD_FIELD_COUNTER */
	#define BWID_AVO_AUXSD_FIELD_COUNTER_Field_Counter	32
	/* Register Bit MASKS for AVO_AUXSD_FIELD_COUNTER */
	#define BMSK_AVO_AUXSD_FIELD_COUNTER_Field_Counter	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXSD_FIELD_COUNTER - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_FIELD_COUNTER_Field_Counter	 0x0018, 0, 32, 0x00000000
#define ROFF_AVO_AUXSD_MISC_COUNTER	0x1c /* Line and Byte counters in AUXSD Block */ 
	#define BITFIELD_AVO_AUXSD_MISC_COUNTER	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXSD_MISC_COUNTER */
	#define BLSB_AVO_AUXSD_MISC_COUNTER_Line_Counter	17
	#define BLSB_AVO_AUXSD_MISC_COUNTER_Byte_Counter	0
	/* Register Bit Widths for AVO_AUXSD_MISC_COUNTER */
	#define BWID_AVO_AUXSD_MISC_COUNTER_Line_Counter	16
	#define BWID_AVO_AUXSD_MISC_COUNTER_Byte_Counter	16
	/* Register Bit MASKS for AVO_AUXSD_MISC_COUNTER */
	#define BMSK_AVO_AUXSD_MISC_COUNTER_Line_Counter	0xfffe0000 /*  */
	#define BMSK_AVO_AUXSD_MISC_COUNTER_Byte_Counter	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXSD_MISC_COUNTER - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXSD_MISC_COUNTER_Line_Counter	 0x001c, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXSD_MISC_COUNTER_Byte_Counter	 0x001c, 0, 16, 0x0000ffff
#define ROFF_AVO_AUXHD_CONTROL	0x0 /* AUXHD Capture Interface Unit Control Register */ 
	#define BITFIELD_AVO_AUXHD_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_CONTROL */
	#define BLSB_AVO_AUXHD_CONTROL_RSVD	31
	#define BLSB_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_loopctrl_7_0	23
	#define BLSB_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_burst_size_4_0	18
	#define BLSB_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_mode_1_0	16
	#define BLSB_AVO_AUXHD_CONTROL_RSVD_15_9	9
	#define BLSB_AVO_AUXHD_CONTROL_Ignore_SOF	8
	#define BLSB_AVO_AUXHD_CONTROL_Data_width	6
	#define BLSB_AVO_AUXHD_CONTROL_Blanking	5
	#define BLSB_AVO_AUXHD_CONTROL_MEM_AGENT_EN	4
	#define BLSB_AVO_AUXHD_CONTROL_Enable	3
	#define BLSB_AVO_AUXHD_CONTROL_LAmode	2
	#define BLSB_AVO_AUXHD_CONTROL_Reset_Counters	1
	#define BLSB_AVO_AUXHD_CONTROL_Storage_CRC_mode	0
	/* Register Bit Widths for AVO_AUXHD_CONTROL */
	#define BWID_AVO_AUXHD_CONTROL_RSVD	1
	#define BWID_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_loopctrl_7_0	8
	#define BWID_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_burst_size_4_0	5
	#define BWID_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_mode_1_0	2
	#define BWID_AVO_AUXHD_CONTROL_RSVD_15_9	7
	#define BWID_AVO_AUXHD_CONTROL_Ignore_SOF	1
	#define BWID_AVO_AUXHD_CONTROL_Data_width	2
	#define BWID_AVO_AUXHD_CONTROL_Blanking	1
	#define BWID_AVO_AUXHD_CONTROL_MEM_AGENT_EN	1
	#define BWID_AVO_AUXHD_CONTROL_Enable	1
	#define BWID_AVO_AUXHD_CONTROL_LAmode	1
	#define BWID_AVO_AUXHD_CONTROL_Reset_Counters	1
	#define BWID_AVO_AUXHD_CONTROL_Storage_CRC_mode	1
	/* Register Bit MASKS for AVO_AUXHD_CONTROL */
	#define BMSK_AVO_AUXHD_CONTROL_RSVD	(1<<31) /* == 0x80000000:  */
	#define BMSK_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_loopctrl_7_0	0x7f800000 /*  */
	#define BMSK_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_burst_size_4_0	0x007c0000 /*  */
	#define BMSK_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_mode_1_0	0x00030000 /*  */
	#define BMSK_AVO_AUXHD_CONTROL_RSVD_15_9	0x0000fe00 /*  */
	#define BMSK_AVO_AUXHD_CONTROL_Ignore_SOF	(1<<8) /* == 0x00000100:  */
	#define BMSK_AVO_AUXHD_CONTROL_Data_width	0x000000c0 /*  */
	#define BMSK_AVO_AUXHD_CONTROL_Blanking	(1<<5) /* == 0x00000020:  */
	#define BMSK_AVO_AUXHD_CONTROL_MEM_AGENT_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_AVO_AUXHD_CONTROL_Enable	(1<<3) /* == 0x00000008:  */
	#define BMSK_AVO_AUXHD_CONTROL_LAmode	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_AUXHD_CONTROL_Reset_Counters	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_AUXHD_CONTROL_Storage_CRC_mode	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_AUXHD_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_CONTROL_RSVD	 0x0000, 31, 1, 0x80000000
	#define BITFIELD_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_loopctrl_7_0	 0x0000, 23, 8, 0x7f800000
	#define BITFIELD_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_burst_size_4_0	 0x0000, 18, 5, 0x007c0000
	#define BITFIELD_AVO_AUXHD_CONTROL_AUXHD_mem_agnt_mode_1_0	 0x0000, 16, 2, 0x00030000
	#define BITFIELD_AVO_AUXHD_CONTROL_RSVD_15_9	 0x0000, 9, 7, 0x0000fe00
	#define BITFIELD_AVO_AUXHD_CONTROL_Ignore_SOF	 0x0000, 8, 1, 0x00000100
	#define BITFIELD_AVO_AUXHD_CONTROL_Data_width	 0x0000, 6, 2, 0x000000c0
	#define BITFIELD_AVO_AUXHD_CONTROL_Blanking	 0x0000, 5, 1, 0x00000020
	#define BITFIELD_AVO_AUXHD_CONTROL_MEM_AGENT_EN	 0x0000, 4, 1, 0x00000010
	#define BITFIELD_AVO_AUXHD_CONTROL_Enable	 0x0000, 3, 1, 0x00000008
	#define BITFIELD_AVO_AUXHD_CONTROL_LAmode	 0x0000, 2, 1, 0x00000004
	#define BITFIELD_AVO_AUXHD_CONTROL_Reset_Counters	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_AVO_AUXHD_CONTROL_Storage_CRC_mode	 0x0000, 0, 1, 0x00000001
#define ROFF_AVO_AUXHD_STAT	0x4 /* AUXHD Capture Interface Unit Status Register */ 
	#define BITFIELD_AVO_AUXHD_STAT	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_STAT */
	#define BLSB_AVO_AUXHD_STAT_RSVD_31_28	31
	#define BLSB_AVO_AUXHD_STAT_CRC_COMP_wusedw	27
	#define BLSB_AVO_AUXHD_STAT_RSVD_19_17	17
	#define BLSB_AVO_AUXHD_STAT_Loop_done	16
	#define BLSB_AVO_AUXHD_STAT_AUXHD_fifo_usedw	8
	#define BLSB_AVO_AUXHD_STAT_Start_of_frame	7
	#define BLSB_AVO_AUXHD_STAT_RSVD_6_3	3
	#define BLSB_AVO_AUXHD_STAT_Pixel_Error	2
	#define BLSB_AVO_AUXHD_STAT_Data_out_FIFO_Overwrite	1
	#define BLSB_AVO_AUXHD_STAT_CRC_in_FIFO_Underrun	0
	/* Register Bit Widths for AVO_AUXHD_STAT */
	#define BWID_AVO_AUXHD_STAT_RSVD_31_28	4
	#define BWID_AVO_AUXHD_STAT_CRC_COMP_wusedw	8
	#define BWID_AVO_AUXHD_STAT_RSVD_19_17	3
	#define BWID_AVO_AUXHD_STAT_Loop_done	1
	#define BWID_AVO_AUXHD_STAT_AUXHD_fifo_usedw	8
	#define BWID_AVO_AUXHD_STAT_Start_of_frame	1
	#define BWID_AVO_AUXHD_STAT_RSVD_6_3	4
	#define BWID_AVO_AUXHD_STAT_Pixel_Error	1
	#define BWID_AVO_AUXHD_STAT_Data_out_FIFO_Overwrite	1
	#define BWID_AVO_AUXHD_STAT_CRC_in_FIFO_Underrun	1
	/* Register Bit MASKS for AVO_AUXHD_STAT */
	#define BMSK_AVO_AUXHD_STAT_RSVD_31_28	0x80000000 /*  */
	#define BMSK_AVO_AUXHD_STAT_CRC_COMP_wusedw	0xf8000000 /*  */
	#define BMSK_AVO_AUXHD_STAT_RSVD_19_17	0x000e0000 /*  */
	#define BMSK_AVO_AUXHD_STAT_Loop_done	(1<<16) /* == 0x00010000:  */
	#define BMSK_AVO_AUXHD_STAT_AUXHD_fifo_usedw	0x0000ff00 /*  */
	#define BMSK_AVO_AUXHD_STAT_Start_of_frame	(1<<7) /* == 0x00000080:  */
	#define BMSK_AVO_AUXHD_STAT_RSVD_6_3	0x00000078 /*  */
	#define BMSK_AVO_AUXHD_STAT_Pixel_Error	(1<<2) /* == 0x00000004:  */
	#define BMSK_AVO_AUXHD_STAT_Data_out_FIFO_Overwrite	(1<<1) /* == 0x00000002:  */
	#define BMSK_AVO_AUXHD_STAT_CRC_in_FIFO_Underrun	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for AVO_AUXHD_STAT - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_STAT_RSVD_31_28	 0x0004, 31, 4, 0x80000000
	#define BITFIELD_AVO_AUXHD_STAT_CRC_COMP_wusedw	 0x0004, 27, 8, 0xf8000000
	#define BITFIELD_AVO_AUXHD_STAT_RSVD_19_17	 0x0004, 17, 3, 0x000e0000
	#define BITFIELD_AVO_AUXHD_STAT_Loop_done	 0x0004, 16, 1, 0x00010000
	#define BITFIELD_AVO_AUXHD_STAT_AUXHD_fifo_usedw	 0x0004, 8, 8, 0x0000ff00
	#define BITFIELD_AVO_AUXHD_STAT_Start_of_frame	 0x0004, 7, 1, 0x00000080
	#define BITFIELD_AVO_AUXHD_STAT_RSVD_6_3	 0x0004, 3, 4, 0x00000078
	#define BITFIELD_AVO_AUXHD_STAT_Pixel_Error	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_AVO_AUXHD_STAT_Data_out_FIFO_Overwrite	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_AVO_AUXHD_STAT_CRC_in_FIFO_Underrun	 0x0004, 0, 1, 0x00000001
#define ROFF_AVO_AUXHD_START_ADDR	0x8 /* Starting Memory Address for the AUXHD Memory Agent */ 
	#define BITFIELD_AVO_AUXHD_START_ADDR	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_START_ADDR */
	#define BLSB_AVO_AUXHD_START_ADDR_Start_Pointer	0
	/* Register Bit Widths for AVO_AUXHD_START_ADDR */
	#define BWID_AVO_AUXHD_START_ADDR_Start_Pointer	32
	/* Register Bit MASKS for AVO_AUXHD_START_ADDR */
	#define BMSK_AVO_AUXHD_START_ADDR_Start_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXHD_START_ADDR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_START_ADDR_Start_Pointer	 0x0008, 0, 32, 0x00000000
#define ROFF_AVO_AUXHD_END_ADDR	0xc /* Ending Memory Address for the AUXHD Memory Agent */ 
	#define BITFIELD_AVO_AUXHD_END_ADDR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_END_ADDR */
	#define BLSB_AVO_AUXHD_END_ADDR_End_Pointer	0
	/* Register Bit Widths for AVO_AUXHD_END_ADDR */
	#define BWID_AVO_AUXHD_END_ADDR_End_Pointer	32
	/* Register Bit MASKS for AVO_AUXHD_END_ADDR */
	#define BMSK_AVO_AUXHD_END_ADDR_End_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXHD_END_ADDR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_END_ADDR_End_Pointer	 0x000c, 0, 32, 0x00000000
#define ROFF_AVO_AUXHD_WRITE_PTR	0x10 /* Write Pointer Register for the AUXHD Memory Agent */ 
	#define BITFIELD_AVO_AUXHD_WRITE_PTR	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_WRITE_PTR */
	#define BLSB_AVO_AUXHD_WRITE_PTR_Write_Pointer	0
	/* Register Bit Widths for AVO_AUXHD_WRITE_PTR */
	#define BWID_AVO_AUXHD_WRITE_PTR_Write_Pointer	32
	/* Register Bit MASKS for AVO_AUXHD_WRITE_PTR */
	#define BMSK_AVO_AUXHD_WRITE_PTR_Write_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXHD_WRITE_PTR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_WRITE_PTR_Write_Pointer	 0x0010, 0, 32, 0x00000000
#define ROFF_AVO_AUXHD_READ_PTR	0x14 /* Read Pointer Register for the AUXHD Memory Agent */ 
	#define BITFIELD_AVO_AUXHD_READ_PTR	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_READ_PTR */
	#define BLSB_AVO_AUXHD_READ_PTR_Read_Pointer	0
	/* Register Bit Widths for AVO_AUXHD_READ_PTR */
	#define BWID_AVO_AUXHD_READ_PTR_Read_Pointer	32
	/* Register Bit MASKS for AVO_AUXHD_READ_PTR */
	#define BMSK_AVO_AUXHD_READ_PTR_Read_Pointer	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXHD_READ_PTR - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_READ_PTR_Read_Pointer	 0x0014, 0, 32, 0x00000000
#define ROFF_AVO_AUXHD_FIELD_COUNTER	0x18 /* Field counter for the AUXHD Block */ 
	#define BITFIELD_AVO_AUXHD_FIELD_COUNTER	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_FIELD_COUNTER */
	#define BLSB_AVO_AUXHD_FIELD_COUNTER_Field_Counter	0
	/* Register Bit Widths for AVO_AUXHD_FIELD_COUNTER */
	#define BWID_AVO_AUXHD_FIELD_COUNTER_Field_Counter	32
	/* Register Bit MASKS for AVO_AUXHD_FIELD_COUNTER */
	#define BMSK_AVO_AUXHD_FIELD_COUNTER_Field_Counter	0x00000000 /*  */
	/* Register BITFIELD for AVO_AUXHD_FIELD_COUNTER - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_FIELD_COUNTER_Field_Counter	 0x0018, 0, 32, 0x00000000
#define ROFF_AVO_AUXHD_MISC_COUNTER	0x1c /* Line and Byte counters in AUXHD Block */ 
	#define BITFIELD_AVO_AUXHD_MISC_COUNTER	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_MISC_COUNTER */
	#define BLSB_AVO_AUXHD_MISC_COUNTER_Line_Counter	17
	#define BLSB_AVO_AUXHD_MISC_COUNTER_Byte_Counter	0
	/* Register Bit Widths for AVO_AUXHD_MISC_COUNTER */
	#define BWID_AVO_AUXHD_MISC_COUNTER_Line_Counter	16
	#define BWID_AVO_AUXHD_MISC_COUNTER_Byte_Counter	16
	/* Register Bit MASKS for AVO_AUXHD_MISC_COUNTER */
	#define BMSK_AVO_AUXHD_MISC_COUNTER_Line_Counter	0xfffe0000 /*  */
	#define BMSK_AVO_AUXHD_MISC_COUNTER_Byte_Counter	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXHD_MISC_COUNTER - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_MISC_COUNTER_Line_Counter	 0x001c, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXHD_MISC_COUNTER_Byte_Counter	 0x001c, 0, 16, 0x0000ffff
#define ROFF_AVO_AUXHD_HSYNC	0x38 /* Hsync timing register */ 
	#define BITFIELD_AVO_AUXHD_HSYNC	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_HSYNC */
	#define BLSB_AVO_AUXHD_HSYNC_Hsync_Fall	17
	#define BLSB_AVO_AUXHD_HSYNC_Hsync_Rise	0
	/* Register Bit Widths for AVO_AUXHD_HSYNC */
	#define BWID_AVO_AUXHD_HSYNC_Hsync_Fall	16
	#define BWID_AVO_AUXHD_HSYNC_Hsync_Rise	16
	/* Register Bit MASKS for AVO_AUXHD_HSYNC */
	#define BMSK_AVO_AUXHD_HSYNC_Hsync_Fall	0xfffe0000 /*  */
	#define BMSK_AVO_AUXHD_HSYNC_Hsync_Rise	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXHD_HSYNC - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_HSYNC_Hsync_Fall	 0x0038, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXHD_HSYNC_Hsync_Rise	 0x0038, 0, 16, 0x0000ffff
#define ROFF_AVO_AUXHD_VSYNC_BYTE	0x3c /* Vsync byte timing register */ 
	#define BITFIELD_AVO_AUXHD_VSYNC_BYTE	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_VSYNC_BYTE */
	#define BLSB_AVO_AUXHD_VSYNC_BYTE_Vsync_Fall	17
	#define BLSB_AVO_AUXHD_VSYNC_BYTE_Vsync_Rise	0
	/* Register Bit Widths for AVO_AUXHD_VSYNC_BYTE */
	#define BWID_AVO_AUXHD_VSYNC_BYTE_Vsync_Fall	16
	#define BWID_AVO_AUXHD_VSYNC_BYTE_Vsync_Rise	16
	/* Register Bit MASKS for AVO_AUXHD_VSYNC_BYTE */
	#define BMSK_AVO_AUXHD_VSYNC_BYTE_Vsync_Fall	0xfffe0000 /*  */
	#define BMSK_AVO_AUXHD_VSYNC_BYTE_Vsync_Rise	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXHD_VSYNC_BYTE - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_VSYNC_BYTE_Vsync_Fall	 0x003c, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXHD_VSYNC_BYTE_Vsync_Rise	 0x003c, 0, 16, 0x0000ffff
#define ROFF_AVO_AUXHD_VSYNC_LINE	0x40 /* Vsync line timing register */ 
	#define BITFIELD_AVO_AUXHD_VSYNC_LINE	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_VSYNC_LINE */
	#define BLSB_AVO_AUXHD_VSYNC_LINE_Vsync_Fall	17
	#define BLSB_AVO_AUXHD_VSYNC_LINE_Vsync_Rise	0
	/* Register Bit Widths for AVO_AUXHD_VSYNC_LINE */
	#define BWID_AVO_AUXHD_VSYNC_LINE_Vsync_Fall	16
	#define BWID_AVO_AUXHD_VSYNC_LINE_Vsync_Rise	16
	/* Register Bit MASKS for AVO_AUXHD_VSYNC_LINE */
	#define BMSK_AVO_AUXHD_VSYNC_LINE_Vsync_Fall	0xfffe0000 /*  */
	#define BMSK_AVO_AUXHD_VSYNC_LINE_Vsync_Rise	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXHD_VSYNC_LINE - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_VSYNC_LINE_Vsync_Fall	 0x0040, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXHD_VSYNC_LINE_Vsync_Rise	 0x0040, 0, 16, 0x0000ffff
#define ROFF_AVO_AUXHD_FIELD_BYTE	0x44 /* Field byte timing register */ 
	#define BITFIELD_AVO_AUXHD_FIELD_BYTE	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_FIELD_BYTE */
	#define BLSB_AVO_AUXHD_FIELD_BYTE_Field_Fall	17
	#define BLSB_AVO_AUXHD_FIELD_BYTE_Field_Rise	0
	/* Register Bit Widths for AVO_AUXHD_FIELD_BYTE */
	#define BWID_AVO_AUXHD_FIELD_BYTE_Field_Fall	16
	#define BWID_AVO_AUXHD_FIELD_BYTE_Field_Rise	16
	/* Register Bit MASKS for AVO_AUXHD_FIELD_BYTE */
	#define BMSK_AVO_AUXHD_FIELD_BYTE_Field_Fall	0xfffe0000 /*  */
	#define BMSK_AVO_AUXHD_FIELD_BYTE_Field_Rise	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXHD_FIELD_BYTE - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_FIELD_BYTE_Field_Fall	 0x0044, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXHD_FIELD_BYTE_Field_Rise	 0x0044, 0, 16, 0x0000ffff
#define ROFF_AVO_AUXHD_FIELD_LINE	0x48 /* Field line timing register */ 
	#define BITFIELD_AVO_AUXHD_FIELD_LINE	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AVO_AUXHD_FIELD_LINE */
	#define BLSB_AVO_AUXHD_FIELD_LINE_Field_Fall	17
	#define BLSB_AVO_AUXHD_FIELD_LINE_Field_Rise	0
	/* Register Bit Widths for AVO_AUXHD_FIELD_LINE */
	#define BWID_AVO_AUXHD_FIELD_LINE_Field_Fall	16
	#define BWID_AVO_AUXHD_FIELD_LINE_Field_Rise	16
	/* Register Bit MASKS for AVO_AUXHD_FIELD_LINE */
	#define BMSK_AVO_AUXHD_FIELD_LINE_Field_Fall	0xfffe0000 /*  */
	#define BMSK_AVO_AUXHD_FIELD_LINE_Field_Rise	0x0000ffff /*  */
	/* Register BITFIELD for AVO_AUXHD_FIELD_LINE - roff, lsb, width, mask */
	#define BITFIELD_AVO_AUXHD_FIELD_LINE_Field_Fall	 0x0048, 17, 16, 0xfffe0000
	#define BITFIELD_AVO_AUXHD_FIELD_LINE_Field_Rise	 0x0048, 0, 16, 0x0000ffff


/* Module AVO SPECIFIC SVEN Events */




#endif /* AVO_REGOFFS_H */
