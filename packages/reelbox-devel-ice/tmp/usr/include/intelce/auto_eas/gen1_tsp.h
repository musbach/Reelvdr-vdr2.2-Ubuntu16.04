#ifndef TSP_REGOFFS_H
#define TSP_REGOFFS_H 1
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


/* Module TSP CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_TSP_PF_P1CFG	0x0 /*  */ 
	#define BITFIELD_TSP_PF_P1CFG	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF_S1CFG	0x8 /*  */ 
	#define BITFIELD_TSP_PF_S1CFG	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_0	0x4000 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_0	 0x4000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_1	0x4004 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_1	 0x4004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_2	0x4008 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_2	 0x4008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_3	0x400c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_3	 0x400c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_4	0x4010 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_4	 0x4010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_5	0x4014 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_5	 0x4014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_6	0x4018 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_6	 0x4018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_7	0x401c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_7	 0x401c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_8	0x4020 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_8	 0x4020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_9	0x4024 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_9	 0x4024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_10	0x4028 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_10	 0x4028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_11	0x402c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_11	 0x402c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_12	0x4030 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_12	 0x4030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_13	0x4034 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_13	 0x4034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_14	0x4038 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_14	 0x4038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_15	0x403c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_15	 0x403c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_16	0x4040 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_16	 0x4040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_17	0x4044 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_17	 0x4044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_18	0x4048 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_18	 0x4048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_19	0x404c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_19	 0x404c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_20	0x4050 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_20	 0x4050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_21	0x4054 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_21	 0x4054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_22	0x4058 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_22	 0x4058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_23	0x405c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_23	 0x405c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_24	0x4060 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_24	 0x4060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_25	0x4064 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_25	 0x4064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_26	0x4068 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_26	 0x4068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_27	0x406c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_27	 0x406c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_28	0x4070 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_28	 0x4070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_29	0x4074 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_29	 0x4074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_30	0x4078 /*  */ 
	#define BITFIELD_TSP_PF1_PMM_30	 0x4078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PMM_31	0x407c /*  */ 
	#define BITFIELD_TSP_PF1_PMM_31	 0x407c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_CONFIG	0x4100 /*  */ 
	#define BITFIELD_TSP_PF1_CONFIG	 0x4100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_STATUS	0x4104 /* Pre-filter 0 Filter Status */ 
	#define BITFIELD_TSP_PF1_STATUS	 0x4104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSP_PF1_STATUS */
	#define BLSB_TSP_PF1_STATUS_RSVD_31_11	11
	#define BLSB_TSP_PF1_STATUS_OCF	10
	#define BLSB_TSP_PF1_STATUS_CRC	9
	#define BLSB_TSP_PF1_STATUS_DIS	8
	#define BLSB_TSP_PF1_STATUS_DET	7
	#define BLSB_TSP_PF1_STATUS_PPF	6
	#define BLSB_TSP_PF1_STATUS_WDT	5
	#define BLSB_TSP_PF1_STATUS_FE	4
	#define BLSB_TSP_PF1_STATUS_FF	3
	#define BLSB_TSP_PF1_STATUS_PLT	2
	#define BLSB_TSP_PF1_STATUS_PGT	1
	#define BLSB_TSP_PF1_STATUS_EN	0
	/* Register Bit Widths for TSP_PF1_STATUS */
	#define BWID_TSP_PF1_STATUS_RSVD_31_11	21
	#define BWID_TSP_PF1_STATUS_OCF	1
	#define BWID_TSP_PF1_STATUS_CRC	1
	#define BWID_TSP_PF1_STATUS_DIS	1
	#define BWID_TSP_PF1_STATUS_DET	1
	#define BWID_TSP_PF1_STATUS_PPF	1
	#define BWID_TSP_PF1_STATUS_WDT	1
	#define BWID_TSP_PF1_STATUS_FE	1
	#define BWID_TSP_PF1_STATUS_FF	1
	#define BWID_TSP_PF1_STATUS_PLT	1
	#define BWID_TSP_PF1_STATUS_PGT	1
	#define BWID_TSP_PF1_STATUS_EN	1
	/* Register Bit MASKS for TSP_PF1_STATUS */
	#define BMSK_TSP_PF1_STATUS_RSVD_31_11	0xfffff800 /*  */
	#define BMSK_TSP_PF1_STATUS_OCF	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSP_PF1_STATUS_CRC	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSP_PF1_STATUS_DIS	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSP_PF1_STATUS_DET	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSP_PF1_STATUS_PPF	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSP_PF1_STATUS_WDT	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSP_PF1_STATUS_FE	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSP_PF1_STATUS_FF	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSP_PF1_STATUS_PLT	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSP_PF1_STATUS_PGT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSP_PF1_STATUS_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSP_PF1_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSP_PF1_STATUS_RSVD_31_11	 0x4104, 11, 21, 0xfffff800
	#define BITFIELD_TSP_PF1_STATUS_OCF	 0x4104, 10, 1, 0x00000400
	#define BITFIELD_TSP_PF1_STATUS_CRC	 0x4104, 9, 1, 0x00000200
	#define BITFIELD_TSP_PF1_STATUS_DIS	 0x4104, 8, 1, 0x00000100
	#define BITFIELD_TSP_PF1_STATUS_DET	 0x4104, 7, 1, 0x00000080
	#define BITFIELD_TSP_PF1_STATUS_PPF	 0x4104, 6, 1, 0x00000040
	#define BITFIELD_TSP_PF1_STATUS_WDT	 0x4104, 5, 1, 0x00000020
	#define BITFIELD_TSP_PF1_STATUS_FE	 0x4104, 4, 1, 0x00000010
	#define BITFIELD_TSP_PF1_STATUS_FF	 0x4104, 3, 1, 0x00000008
	#define BITFIELD_TSP_PF1_STATUS_PLT	 0x4104, 2, 1, 0x00000004
	#define BITFIELD_TSP_PF1_STATUS_PGT	 0x4104, 1, 1, 0x00000002
	#define BITFIELD_TSP_PF1_STATUS_EN	 0x4104, 0, 1, 0x00000001
#define ROFF_TSP_PF1_DMA_BASE	0x4200 /*  */ 
	#define BITFIELD_TSP_PF1_DMA_BASE	 0x4200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_DMA_SIZE	0x4204 /*  */ 
	#define BITFIELD_TSP_PF1_DMA_SIZE	 0x4204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_DMA_WR_PTR	0x4208 /*  */ 
	#define BITFIELD_TSP_PF1_DMA_WR_PTR	 0x4208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_DMA_SHDW_WR_PTR_ADDR	0x420c /*  */ 
	#define BITFIELD_TSP_PF1_DMA_SHDW_WR_PTR_ADDR	 0x420c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_DMA_RD_PTR	0x4210 /*  */ 
	#define BITFIELD_TSP_PF1_DMA_RD_PTR	 0x4210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_DMA_SHDW_WR_CNTR	0x4214 /*  */ 
	#define BITFIELD_TSP_PF1_DMA_SHDW_WR_CNTR	 0x4214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_NIM_WDT	0x4218 /*  */ 
	#define BITFIELD_TSP_PF1_NIM_WDT	 0x4218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_CONFIG	0x4300 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_CONFIG	 0x4300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSP_PF1_PCR_CONFIG */
	#define BLSB_TSP_PF1_PCR_CONFIG_IRQ_EN	31
	#define BLSB_TSP_PF1_PCR_CONFIG_RSVD_30_6	6
	#define BLSB_TSP_PF1_PCR_CONFIG_FIRST	5
	#define BLSB_TSP_PF1_PCR_CONFIG_RSVD_4_1	1
	#define BLSB_TSP_PF1_PCR_CONFIG_EN	0
	/* Register Bit Widths for TSP_PF1_PCR_CONFIG */
	#define BWID_TSP_PF1_PCR_CONFIG_IRQ_EN	1
	#define BWID_TSP_PF1_PCR_CONFIG_RSVD_30_6	25
	#define BWID_TSP_PF1_PCR_CONFIG_FIRST	1
	#define BWID_TSP_PF1_PCR_CONFIG_RSVD_4_1	4
	#define BWID_TSP_PF1_PCR_CONFIG_EN	1
	/* Register Bit MASKS for TSP_PF1_PCR_CONFIG */
	#define BMSK_TSP_PF1_PCR_CONFIG_IRQ_EN	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSP_PF1_PCR_CONFIG_RSVD_30_6	0x7fffffc0 /*  */
	#define BMSK_TSP_PF1_PCR_CONFIG_FIRST	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSP_PF1_PCR_CONFIG_RSVD_4_1	0x0000001e /*  */
	#define BMSK_TSP_PF1_PCR_CONFIG_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSP_PF1_PCR_CONFIG - roff, lsb, width, mask */
	#define BITFIELD_TSP_PF1_PCR_CONFIG_IRQ_EN	 0x4300, 31, 1, 0x80000000
	#define BITFIELD_TSP_PF1_PCR_CONFIG_RSVD_30_6	 0x4300, 6, 25, 0x7fffffc0
	#define BITFIELD_TSP_PF1_PCR_CONFIG_FIRST	 0x4300, 5, 1, 0x00000020
	#define BITFIELD_TSP_PF1_PCR_CONFIG_RSVD_4_1	 0x4300, 1, 4, 0x0000001e
	#define BITFIELD_TSP_PF1_PCR_CONFIG_EN	 0x4300, 0, 1, 0x00000001
#define ROFF_TSP_PF1_TBASE_LOCAL_0	0x4304 /*  */ 
	#define BITFIELD_TSP_PF1_TBASE_LOCAL_0	 0x4304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_TBASE_LOCAL_1	0x4308 /*  */ 
	#define BITFIELD_TSP_PF1_TBASE_LOCAL_1	 0x4308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_LOCAL_A0	0x430c /*  */ 
	#define BITFIELD_TSP_PF1_PCR_LOCAL_A0	 0x430c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_LOCAL_A1	0x4310 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_LOCAL_A1	 0x4310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_LOCAL_B0	0x4314 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_LOCAL_B0	 0x4314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_LOCAL_B1	0x4318 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_LOCAL_B1	 0x4318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_REMOTE_A0	0x431c /*  */ 
	#define BITFIELD_TSP_PF1_PCR_REMOTE_A0	 0x431c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_REMOTE_A1	0x4320 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_REMOTE_A1	 0x4320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_REMOTE_B0	0x4324 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_REMOTE_B0	 0x4324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_PCR_REMOTE_B1	0x4328 /*  */ 
	#define BITFIELD_TSP_PF1_PCR_REMOTE_B1	 0x4328, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_STC_GEN_CONFIG	0x4400 /*  */ 
	#define BITFIELD_TSP_PF1_STC_GEN_CONFIG	 0x4400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_DDS_CONFIG	0x4404 /*  */ 
	#define BITFIELD_TSP_PF1_DDS_CONFIG	 0x4404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF1_VCXO_CONFIG	0x4408 /*  */ 
	#define BITFIELD_TSP_PF1_VCXO_CONFIG	 0x4408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_TBASE_LOCAL_0	0x8304 /*  */ 
	#define BITFIELD_TSP_PF2_TBASE_LOCAL_0	 0x8304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_TBASE_LOCAL_1	0x8308 /*  */ 
	#define BITFIELD_TSP_PF2_TBASE_LOCAL_1	 0x8308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_PCR_LOCAL_A0	0x830c /*  */ 
	#define BITFIELD_TSP_PF2_PCR_LOCAL_A0	 0x830c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_PCR_LOCAL_A1	0x8310 /*  */ 
	#define BITFIELD_TSP_PF2_PCR_LOCAL_A1	 0x8310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_PCR_LOCAL_B0	0x8314 /*  */ 
	#define BITFIELD_TSP_PF2_PCR_LOCAL_B0	 0x8314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_PCR_LOCAL_B1	0x8318 /*  */ 
	#define BITFIELD_TSP_PF2_PCR_LOCAL_B1	 0x8318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_STC_GEN_CONFIG	0x8400 /*  */ 
	#define BITFIELD_TSP_PF2_STC_GEN_CONFIG	 0x8400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_DDS_CONFIG	0x8404 /*  */ 
	#define BITFIELD_TSP_PF2_DDS_CONFIG	 0x8404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF2_VCXO_CONFIG	0x8408 /*  */ 
	#define BITFIELD_TSP_PF2_VCXO_CONFIG	 0x8408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_TBASE_LOCAL_0	0xc304 /*  */ 
	#define BITFIELD_TSP_PF3_TBASE_LOCAL_0	 0xc304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_TBASE_LOCAL_1	0xc308 /*  */ 
	#define BITFIELD_TSP_PF3_TBASE_LOCAL_1	 0xc308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_PCR_LOCAL_A0	0xc30c /*  */ 
	#define BITFIELD_TSP_PF3_PCR_LOCAL_A0	 0xc30c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_PCR_LOCAL_A1	0xc310 /*  */ 
	#define BITFIELD_TSP_PF3_PCR_LOCAL_A1	 0xc310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_PCR_LOCAL_B0	0xc314 /*  */ 
	#define BITFIELD_TSP_PF3_PCR_LOCAL_B0	 0xc314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_PCR_LOCAL_B1	0xc318 /*  */ 
	#define BITFIELD_TSP_PF3_PCR_LOCAL_B1	 0xc318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_STC_GEN_CONFIG	0xc400 /*  */ 
	#define BITFIELD_TSP_PF3_STC_GEN_CONFIG	 0xc400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_DDS_CONFIG	0xc404 /*  */ 
	#define BITFIELD_TSP_PF3_DDS_CONFIG	 0xc404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSP_PF3_VCXO_CONFIG	0xc408 /*  */ 
	#define BITFIELD_TSP_PF3_VCXO_CONFIG	 0xc408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module TSP SPECIFIC SVEN Events */




#endif /* TSP_REGOFFS_H */
