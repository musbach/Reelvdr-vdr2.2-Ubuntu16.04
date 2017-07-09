#ifndef TSI_REGOFFS_H
#define TSI_REGOFFS_H 1
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


/* Module TSI CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_TSI_OC_MODE	0x0 /* OpenCABLE Mode Config Register */ 
	#define BITFIELD_TSI_OC_MODE	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_OC_MODE */
	#define BLSB_TSI_OC_MODE_RESERVED_31_3	3
	#define BLSB_TSI_OC_MODE_OCCRCI	2
	#define BLSB_TSI_OC_MODE_OCCE	1
	#define BLSB_TSI_OC_MODE_OCSSE	0
	/* Register Bit Widths for TSI_OC_MODE */
	#define BWID_TSI_OC_MODE_RESERVED_31_3	29
	#define BWID_TSI_OC_MODE_OCCRCI	1
	#define BWID_TSI_OC_MODE_OCCE	1
	#define BWID_TSI_OC_MODE_OCSSE	1
	/* Register Bit MASKS for TSI_OC_MODE */
	#define BMSK_TSI_OC_MODE_RESERVED_31_3	0xfffffff8 /*  */
	#define BMSK_TSI_OC_MODE_OCCRCI	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_OC_MODE_OCCE	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_OC_MODE_OCSSE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_OC_MODE - roff, lsb, width, mask */
	#define BITFIELD_TSI_OC_MODE_RESERVED_31_3	 0x0000, 3, 29, 0xfffffff8
	#define BITFIELD_TSI_OC_MODE_OCCRCI	 0x0000, 2, 1, 0x00000004
	#define BITFIELD_TSI_OC_MODE_OCCE	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_TSI_OC_MODE_OCSSE	 0x0000, 0, 1, 0x00000001
#define ROFF_TSI_CE_CONFIG_RX	0x40 /* CE Receive Configuration Register */ 
	#define BITFIELD_TSI_CE_CONFIG_RX	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_CONFIG_TX	0x44 /* CE Transmit Configuration Register */ 
	#define BITFIELD_TSI_CE_CONFIG_TX	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_INTERRUPT_ENABLE	0x48 /* CE Interrupt Enable Register */ 
	#define BITFIELD_TSI_CE_INTERRUPT_ENABLE	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_INTERRUPT_STATUS	0x4c /* CE Interrupt Status  Register */ 
	#define BITFIELD_TSI_CE_INTERRUPT_STATUS	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_RX_TS_CAPTURE	0x88 /* Receive Timestamp Capture Value for DV mode */ 
	#define BITFIELD_TSI_CE_RX_TS_CAPTURE	 0x0088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_RX_DIF_DELAY	0x90 /* Delay between FrameSync and DIF in DV mode */ 
	#define BITFIELD_TSI_CE_RX_DIF_DELAY	 0x0090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_TX_TS_CNT	0xc0 /* CE Transmit Timestamp Counter */ 
	#define BITFIELD_TSI_CE_TX_TS_CNT	 0x00c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_OUT_FRAME_INTERVAL	0xd0 /* CE Transmit DV Frame Interval */ 
	#define BITFIELD_TSI_CE_OUT_FRAME_INTERVAL	 0x00d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_OUT_PACKET_INTERVAL	0xd4 /* CE Transmit DV Packet Interval */ 
	#define BITFIELD_TSI_CE_OUT_PACKET_INTERVAL	 0x00d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_DIF_PACKET_SIZE	0xd8 /* DV Size of DIF Packet */ 
	#define BITFIELD_TSI_CE_DIF_PACKET_SIZE	 0x00d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_DIF_FRAME_SIZE	0xdc /* CE Transmit DV Frame Size */ 
	#define BITFIELD_TSI_CE_DIF_FRAME_SIZE	 0x00dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_OUT_FRAME_INTERVAL_CNT	0xe0 /* CE Transmit DV Frame Interval Count */ 
	#define BITFIELD_TSI_CE_OUT_FRAME_INTERVAL_CNT	 0x00e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_OUT_PACKET_INTERVAL_CNT	0xe4 /* CE Transmit DV Packet Interval Count */ 
	#define BITFIELD_TSI_CE_OUT_PACKET_INTERVAL_CNT	 0x00e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_PACKET_SIZE_CNT	0xe8 /* DV DIF Packet Current Byte Count */ 
	#define BITFIELD_TSI_CE_PACKET_SIZE_CNT	 0x00e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_CE_DIF_FRAME_SIZE_CNT	0xec /* CE Transmit DV Frame Size */ 
	#define BITFIELD_TSI_CE_DIF_FRAME_SIZE_CNT	 0x00ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_PMM0	0x4000 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM0	 0x4000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM0 */
	#define BLSB_TSI_PFX_0_PMM0_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM0_MASK	16
	#define BLSB_TSI_PFX_0_PMM0_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM0_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM0 */
	#define BWID_TSI_PFX_0_PMM0_ENABLE	1
	#define BWID_TSI_PFX_0_PMM0_MASK	15
	#define BWID_TSI_PFX_0_PMM0_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM0_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM0 */
	#define BMSK_TSI_PFX_0_PMM0_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM0_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM0_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM0_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM0 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM0_ENABLE	 0x4000, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM0_MASK	 0x4000, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM0_RESERVED_15	 0x4000, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM0_EXACTVALUE	 0x4000, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM1	0x4004 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM1	 0x4004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM1 */
	#define BLSB_TSI_PFX_0_PMM1_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM1_MASK	16
	#define BLSB_TSI_PFX_0_PMM1_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM1_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM1 */
	#define BWID_TSI_PFX_0_PMM1_ENABLE	1
	#define BWID_TSI_PFX_0_PMM1_MASK	15
	#define BWID_TSI_PFX_0_PMM1_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM1_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM1 */
	#define BMSK_TSI_PFX_0_PMM1_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM1_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM1_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM1_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM1_ENABLE	 0x4004, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM1_MASK	 0x4004, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM1_RESERVED_15	 0x4004, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM1_EXACTVALUE	 0x4004, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM2	0x4008 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM2	 0x4008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM2 */
	#define BLSB_TSI_PFX_0_PMM2_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM2_MASK	16
	#define BLSB_TSI_PFX_0_PMM2_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM2_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM2 */
	#define BWID_TSI_PFX_0_PMM2_ENABLE	1
	#define BWID_TSI_PFX_0_PMM2_MASK	15
	#define BWID_TSI_PFX_0_PMM2_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM2_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM2 */
	#define BMSK_TSI_PFX_0_PMM2_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM2_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM2_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM2_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM2 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM2_ENABLE	 0x4008, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM2_MASK	 0x4008, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM2_RESERVED_15	 0x4008, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM2_EXACTVALUE	 0x4008, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM3	0x400c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM3	 0x400c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM3 */
	#define BLSB_TSI_PFX_0_PMM3_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM3_MASK	16
	#define BLSB_TSI_PFX_0_PMM3_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM3_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM3 */
	#define BWID_TSI_PFX_0_PMM3_ENABLE	1
	#define BWID_TSI_PFX_0_PMM3_MASK	15
	#define BWID_TSI_PFX_0_PMM3_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM3_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM3 */
	#define BMSK_TSI_PFX_0_PMM3_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM3_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM3_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM3_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM3 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM3_ENABLE	 0x400c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM3_MASK	 0x400c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM3_RESERVED_15	 0x400c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM3_EXACTVALUE	 0x400c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM4	0x4010 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM4	 0x4010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM4 */
	#define BLSB_TSI_PFX_0_PMM4_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM4_MASK	16
	#define BLSB_TSI_PFX_0_PMM4_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM4_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM4 */
	#define BWID_TSI_PFX_0_PMM4_ENABLE	1
	#define BWID_TSI_PFX_0_PMM4_MASK	15
	#define BWID_TSI_PFX_0_PMM4_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM4_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM4 */
	#define BMSK_TSI_PFX_0_PMM4_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM4_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM4_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM4_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM4 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM4_ENABLE	 0x4010, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM4_MASK	 0x4010, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM4_RESERVED_15	 0x4010, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM4_EXACTVALUE	 0x4010, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM5	0x4014 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM5	 0x4014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM5 */
	#define BLSB_TSI_PFX_0_PMM5_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM5_MASK	16
	#define BLSB_TSI_PFX_0_PMM5_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM5_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM5 */
	#define BWID_TSI_PFX_0_PMM5_ENABLE	1
	#define BWID_TSI_PFX_0_PMM5_MASK	15
	#define BWID_TSI_PFX_0_PMM5_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM5_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM5 */
	#define BMSK_TSI_PFX_0_PMM5_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM5_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM5_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM5_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM5 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM5_ENABLE	 0x4014, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM5_MASK	 0x4014, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM5_RESERVED_15	 0x4014, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM5_EXACTVALUE	 0x4014, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM6	0x4018 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM6	 0x4018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM6 */
	#define BLSB_TSI_PFX_0_PMM6_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM6_MASK	16
	#define BLSB_TSI_PFX_0_PMM6_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM6_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM6 */
	#define BWID_TSI_PFX_0_PMM6_ENABLE	1
	#define BWID_TSI_PFX_0_PMM6_MASK	15
	#define BWID_TSI_PFX_0_PMM6_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM6_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM6 */
	#define BMSK_TSI_PFX_0_PMM6_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM6_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM6_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM6_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM6 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM6_ENABLE	 0x4018, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM6_MASK	 0x4018, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM6_RESERVED_15	 0x4018, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM6_EXACTVALUE	 0x4018, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM7	0x401c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM7	 0x401c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM7 */
	#define BLSB_TSI_PFX_0_PMM7_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM7_MASK	16
	#define BLSB_TSI_PFX_0_PMM7_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM7_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM7 */
	#define BWID_TSI_PFX_0_PMM7_ENABLE	1
	#define BWID_TSI_PFX_0_PMM7_MASK	15
	#define BWID_TSI_PFX_0_PMM7_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM7_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM7 */
	#define BMSK_TSI_PFX_0_PMM7_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM7_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM7_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM7_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM7 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM7_ENABLE	 0x401c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM7_MASK	 0x401c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM7_RESERVED_15	 0x401c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM7_EXACTVALUE	 0x401c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM8	0x4020 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM8	 0x4020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM8 */
	#define BLSB_TSI_PFX_0_PMM8_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM8_MASK	16
	#define BLSB_TSI_PFX_0_PMM8_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM8_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM8 */
	#define BWID_TSI_PFX_0_PMM8_ENABLE	1
	#define BWID_TSI_PFX_0_PMM8_MASK	15
	#define BWID_TSI_PFX_0_PMM8_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM8_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM8 */
	#define BMSK_TSI_PFX_0_PMM8_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM8_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM8_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM8_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM8 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM8_ENABLE	 0x4020, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM8_MASK	 0x4020, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM8_RESERVED_15	 0x4020, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM8_EXACTVALUE	 0x4020, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM9	0x4024 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM9	 0x4024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM9 */
	#define BLSB_TSI_PFX_0_PMM9_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM9_MASK	16
	#define BLSB_TSI_PFX_0_PMM9_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM9_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM9 */
	#define BWID_TSI_PFX_0_PMM9_ENABLE	1
	#define BWID_TSI_PFX_0_PMM9_MASK	15
	#define BWID_TSI_PFX_0_PMM9_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM9_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM9 */
	#define BMSK_TSI_PFX_0_PMM9_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM9_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM9_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM9_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM9 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM9_ENABLE	 0x4024, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM9_MASK	 0x4024, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM9_RESERVED_15	 0x4024, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM9_EXACTVALUE	 0x4024, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM10	0x4028 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM10	 0x4028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM10 */
	#define BLSB_TSI_PFX_0_PMM10_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM10_MASK	16
	#define BLSB_TSI_PFX_0_PMM10_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM10_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM10 */
	#define BWID_TSI_PFX_0_PMM10_ENABLE	1
	#define BWID_TSI_PFX_0_PMM10_MASK	15
	#define BWID_TSI_PFX_0_PMM10_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM10_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM10 */
	#define BMSK_TSI_PFX_0_PMM10_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM10_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM10_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM10_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM10 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM10_ENABLE	 0x4028, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM10_MASK	 0x4028, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM10_RESERVED_15	 0x4028, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM10_EXACTVALUE	 0x4028, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM11	0x402c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM11	 0x402c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM11 */
	#define BLSB_TSI_PFX_0_PMM11_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM11_MASK	16
	#define BLSB_TSI_PFX_0_PMM11_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM11_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM11 */
	#define BWID_TSI_PFX_0_PMM11_ENABLE	1
	#define BWID_TSI_PFX_0_PMM11_MASK	15
	#define BWID_TSI_PFX_0_PMM11_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM11_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM11 */
	#define BMSK_TSI_PFX_0_PMM11_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM11_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM11_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM11_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM11 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM11_ENABLE	 0x402c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM11_MASK	 0x402c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM11_RESERVED_15	 0x402c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM11_EXACTVALUE	 0x402c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM12	0x4030 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM12	 0x4030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM12 */
	#define BLSB_TSI_PFX_0_PMM12_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM12_MASK	16
	#define BLSB_TSI_PFX_0_PMM12_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM12_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM12 */
	#define BWID_TSI_PFX_0_PMM12_ENABLE	1
	#define BWID_TSI_PFX_0_PMM12_MASK	15
	#define BWID_TSI_PFX_0_PMM12_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM12_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM12 */
	#define BMSK_TSI_PFX_0_PMM12_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM12_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM12_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM12_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM12 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM12_ENABLE	 0x4030, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM12_MASK	 0x4030, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM12_RESERVED_15	 0x4030, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM12_EXACTVALUE	 0x4030, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM13	0x4034 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM13	 0x4034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM13 */
	#define BLSB_TSI_PFX_0_PMM13_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM13_MASK	16
	#define BLSB_TSI_PFX_0_PMM13_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM13_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM13 */
	#define BWID_TSI_PFX_0_PMM13_ENABLE	1
	#define BWID_TSI_PFX_0_PMM13_MASK	15
	#define BWID_TSI_PFX_0_PMM13_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM13_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM13 */
	#define BMSK_TSI_PFX_0_PMM13_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM13_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM13_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM13_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM13 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM13_ENABLE	 0x4034, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM13_MASK	 0x4034, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM13_RESERVED_15	 0x4034, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM13_EXACTVALUE	 0x4034, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM14	0x4038 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM14	 0x4038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM14 */
	#define BLSB_TSI_PFX_0_PMM14_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM14_MASK	16
	#define BLSB_TSI_PFX_0_PMM14_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM14_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM14 */
	#define BWID_TSI_PFX_0_PMM14_ENABLE	1
	#define BWID_TSI_PFX_0_PMM14_MASK	15
	#define BWID_TSI_PFX_0_PMM14_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM14_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM14 */
	#define BMSK_TSI_PFX_0_PMM14_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM14_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM14_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM14_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM14 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM14_ENABLE	 0x4038, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM14_MASK	 0x4038, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM14_RESERVED_15	 0x4038, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM14_EXACTVALUE	 0x4038, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM15	0x403c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM15	 0x403c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM15 */
	#define BLSB_TSI_PFX_0_PMM15_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM15_MASK	16
	#define BLSB_TSI_PFX_0_PMM15_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM15_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM15 */
	#define BWID_TSI_PFX_0_PMM15_ENABLE	1
	#define BWID_TSI_PFX_0_PMM15_MASK	15
	#define BWID_TSI_PFX_0_PMM15_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM15_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM15 */
	#define BMSK_TSI_PFX_0_PMM15_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM15_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM15_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM15_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM15 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM15_ENABLE	 0x403c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM15_MASK	 0x403c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM15_RESERVED_15	 0x403c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM15_EXACTVALUE	 0x403c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM16	0x4040 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM16	 0x4040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM16 */
	#define BLSB_TSI_PFX_0_PMM16_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM16_MASK	16
	#define BLSB_TSI_PFX_0_PMM16_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM16_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM16 */
	#define BWID_TSI_PFX_0_PMM16_ENABLE	1
	#define BWID_TSI_PFX_0_PMM16_MASK	15
	#define BWID_TSI_PFX_0_PMM16_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM16_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM16 */
	#define BMSK_TSI_PFX_0_PMM16_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM16_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM16_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM16_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM16 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM16_ENABLE	 0x4040, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM16_MASK	 0x4040, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM16_RESERVED_15	 0x4040, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM16_EXACTVALUE	 0x4040, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM17	0x4044 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM17	 0x4044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM17 */
	#define BLSB_TSI_PFX_0_PMM17_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM17_MASK	16
	#define BLSB_TSI_PFX_0_PMM17_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM17_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM17 */
	#define BWID_TSI_PFX_0_PMM17_ENABLE	1
	#define BWID_TSI_PFX_0_PMM17_MASK	15
	#define BWID_TSI_PFX_0_PMM17_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM17_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM17 */
	#define BMSK_TSI_PFX_0_PMM17_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM17_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM17_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM17_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM17 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM17_ENABLE	 0x4044, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM17_MASK	 0x4044, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM17_RESERVED_15	 0x4044, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM17_EXACTVALUE	 0x4044, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM18	0x4048 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM18	 0x4048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM18 */
	#define BLSB_TSI_PFX_0_PMM18_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM18_MASK	16
	#define BLSB_TSI_PFX_0_PMM18_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM18_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM18 */
	#define BWID_TSI_PFX_0_PMM18_ENABLE	1
	#define BWID_TSI_PFX_0_PMM18_MASK	15
	#define BWID_TSI_PFX_0_PMM18_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM18_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM18 */
	#define BMSK_TSI_PFX_0_PMM18_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM18_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM18_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM18_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM18 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM18_ENABLE	 0x4048, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM18_MASK	 0x4048, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM18_RESERVED_15	 0x4048, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM18_EXACTVALUE	 0x4048, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM19	0x404c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM19	 0x404c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM19 */
	#define BLSB_TSI_PFX_0_PMM19_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM19_MASK	16
	#define BLSB_TSI_PFX_0_PMM19_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM19_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM19 */
	#define BWID_TSI_PFX_0_PMM19_ENABLE	1
	#define BWID_TSI_PFX_0_PMM19_MASK	15
	#define BWID_TSI_PFX_0_PMM19_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM19_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM19 */
	#define BMSK_TSI_PFX_0_PMM19_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM19_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM19_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM19_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM19 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM19_ENABLE	 0x404c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM19_MASK	 0x404c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM19_RESERVED_15	 0x404c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM19_EXACTVALUE	 0x404c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM20	0x4050 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM20	 0x4050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM20 */
	#define BLSB_TSI_PFX_0_PMM20_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM20_MASK	16
	#define BLSB_TSI_PFX_0_PMM20_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM20_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM20 */
	#define BWID_TSI_PFX_0_PMM20_ENABLE	1
	#define BWID_TSI_PFX_0_PMM20_MASK	15
	#define BWID_TSI_PFX_0_PMM20_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM20_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM20 */
	#define BMSK_TSI_PFX_0_PMM20_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM20_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM20_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM20_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM20 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM20_ENABLE	 0x4050, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM20_MASK	 0x4050, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM20_RESERVED_15	 0x4050, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM20_EXACTVALUE	 0x4050, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM21	0x4054 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM21	 0x4054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM21 */
	#define BLSB_TSI_PFX_0_PMM21_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM21_MASK	16
	#define BLSB_TSI_PFX_0_PMM21_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM21_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM21 */
	#define BWID_TSI_PFX_0_PMM21_ENABLE	1
	#define BWID_TSI_PFX_0_PMM21_MASK	15
	#define BWID_TSI_PFX_0_PMM21_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM21_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM21 */
	#define BMSK_TSI_PFX_0_PMM21_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM21_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM21_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM21_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM21 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM21_ENABLE	 0x4054, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM21_MASK	 0x4054, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM21_RESERVED_15	 0x4054, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM21_EXACTVALUE	 0x4054, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM22	0x4058 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM22	 0x4058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM22 */
	#define BLSB_TSI_PFX_0_PMM22_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM22_MASK	16
	#define BLSB_TSI_PFX_0_PMM22_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM22_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM22 */
	#define BWID_TSI_PFX_0_PMM22_ENABLE	1
	#define BWID_TSI_PFX_0_PMM22_MASK	15
	#define BWID_TSI_PFX_0_PMM22_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM22_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM22 */
	#define BMSK_TSI_PFX_0_PMM22_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM22_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM22_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM22_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM22 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM22_ENABLE	 0x4058, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM22_MASK	 0x4058, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM22_RESERVED_15	 0x4058, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM22_EXACTVALUE	 0x4058, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM23	0x405c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM23	 0x405c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM23 */
	#define BLSB_TSI_PFX_0_PMM23_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM23_MASK	16
	#define BLSB_TSI_PFX_0_PMM23_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM23_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM23 */
	#define BWID_TSI_PFX_0_PMM23_ENABLE	1
	#define BWID_TSI_PFX_0_PMM23_MASK	15
	#define BWID_TSI_PFX_0_PMM23_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM23_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM23 */
	#define BMSK_TSI_PFX_0_PMM23_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM23_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM23_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM23_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM23 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM23_ENABLE	 0x405c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM23_MASK	 0x405c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM23_RESERVED_15	 0x405c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM23_EXACTVALUE	 0x405c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM24	0x4060 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM24	 0x4060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM24 */
	#define BLSB_TSI_PFX_0_PMM24_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM24_MASK	16
	#define BLSB_TSI_PFX_0_PMM24_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM24_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM24 */
	#define BWID_TSI_PFX_0_PMM24_ENABLE	1
	#define BWID_TSI_PFX_0_PMM24_MASK	15
	#define BWID_TSI_PFX_0_PMM24_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM24_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM24 */
	#define BMSK_TSI_PFX_0_PMM24_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM24_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM24_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM24_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM24 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM24_ENABLE	 0x4060, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM24_MASK	 0x4060, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM24_RESERVED_15	 0x4060, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM24_EXACTVALUE	 0x4060, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM25	0x4064 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM25	 0x4064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM25 */
	#define BLSB_TSI_PFX_0_PMM25_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM25_MASK	16
	#define BLSB_TSI_PFX_0_PMM25_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM25_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM25 */
	#define BWID_TSI_PFX_0_PMM25_ENABLE	1
	#define BWID_TSI_PFX_0_PMM25_MASK	15
	#define BWID_TSI_PFX_0_PMM25_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM25_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM25 */
	#define BMSK_TSI_PFX_0_PMM25_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM25_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM25_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM25_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM25 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM25_ENABLE	 0x4064, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM25_MASK	 0x4064, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM25_RESERVED_15	 0x4064, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM25_EXACTVALUE	 0x4064, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM26	0x4068 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM26	 0x4068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM26 */
	#define BLSB_TSI_PFX_0_PMM26_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM26_MASK	16
	#define BLSB_TSI_PFX_0_PMM26_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM26_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM26 */
	#define BWID_TSI_PFX_0_PMM26_ENABLE	1
	#define BWID_TSI_PFX_0_PMM26_MASK	15
	#define BWID_TSI_PFX_0_PMM26_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM26_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM26 */
	#define BMSK_TSI_PFX_0_PMM26_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM26_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM26_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM26_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM26 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM26_ENABLE	 0x4068, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM26_MASK	 0x4068, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM26_RESERVED_15	 0x4068, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM26_EXACTVALUE	 0x4068, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM27	0x406c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM27	 0x406c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM27 */
	#define BLSB_TSI_PFX_0_PMM27_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM27_MASK	16
	#define BLSB_TSI_PFX_0_PMM27_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM27_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM27 */
	#define BWID_TSI_PFX_0_PMM27_ENABLE	1
	#define BWID_TSI_PFX_0_PMM27_MASK	15
	#define BWID_TSI_PFX_0_PMM27_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM27_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM27 */
	#define BMSK_TSI_PFX_0_PMM27_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM27_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM27_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM27_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM27 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM27_ENABLE	 0x406c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM27_MASK	 0x406c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM27_RESERVED_15	 0x406c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM27_EXACTVALUE	 0x406c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM28	0x4070 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM28	 0x4070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM28 */
	#define BLSB_TSI_PFX_0_PMM28_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM28_MASK	16
	#define BLSB_TSI_PFX_0_PMM28_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM28_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM28 */
	#define BWID_TSI_PFX_0_PMM28_ENABLE	1
	#define BWID_TSI_PFX_0_PMM28_MASK	15
	#define BWID_TSI_PFX_0_PMM28_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM28_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM28 */
	#define BMSK_TSI_PFX_0_PMM28_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM28_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM28_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM28_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM28 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM28_ENABLE	 0x4070, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM28_MASK	 0x4070, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM28_RESERVED_15	 0x4070, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM28_EXACTVALUE	 0x4070, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM29	0x4074 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM29	 0x4074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM29 */
	#define BLSB_TSI_PFX_0_PMM29_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM29_MASK	16
	#define BLSB_TSI_PFX_0_PMM29_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM29_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM29 */
	#define BWID_TSI_PFX_0_PMM29_ENABLE	1
	#define BWID_TSI_PFX_0_PMM29_MASK	15
	#define BWID_TSI_PFX_0_PMM29_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM29_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM29 */
	#define BMSK_TSI_PFX_0_PMM29_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM29_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM29_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM29_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM29 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM29_ENABLE	 0x4074, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM29_MASK	 0x4074, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM29_RESERVED_15	 0x4074, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM29_EXACTVALUE	 0x4074, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM30	0x4078 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM30	 0x4078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM30 */
	#define BLSB_TSI_PFX_0_PMM30_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM30_MASK	16
	#define BLSB_TSI_PFX_0_PMM30_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM30_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM30 */
	#define BWID_TSI_PFX_0_PMM30_ENABLE	1
	#define BWID_TSI_PFX_0_PMM30_MASK	15
	#define BWID_TSI_PFX_0_PMM30_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM30_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM30 */
	#define BMSK_TSI_PFX_0_PMM30_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM30_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM30_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM30_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM30 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM30_ENABLE	 0x4078, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM30_MASK	 0x4078, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM30_RESERVED_15	 0x4078, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM30_EXACTVALUE	 0x4078, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_PMM31	0x407c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_0_PMM31	 0x407c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PMM31 */
	#define BLSB_TSI_PFX_0_PMM31_ENABLE	31
	#define BLSB_TSI_PFX_0_PMM31_MASK	16
	#define BLSB_TSI_PFX_0_PMM31_RESERVED_15	15
	#define BLSB_TSI_PFX_0_PMM31_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_0_PMM31 */
	#define BWID_TSI_PFX_0_PMM31_ENABLE	1
	#define BWID_TSI_PFX_0_PMM31_MASK	15
	#define BWID_TSI_PFX_0_PMM31_RESERVED_15	1
	#define BWID_TSI_PFX_0_PMM31_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_0_PMM31 */
	#define BMSK_TSI_PFX_0_PMM31_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PMM31_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_0_PMM31_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_0_PMM31_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_0_PMM31 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PMM31_ENABLE	 0x407c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PMM31_MASK	 0x407c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_0_PMM31_RESERVED_15	 0x407c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_0_PMM31_EXACTVALUE	 0x407c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_0_CFG	0x4100 /* Prefilter Config register */ 
	#define BITFIELD_TSI_PFX_0_CFG	 0x4100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_CFG */
	#define BLSB_TSI_PFX_0_CFG_P_SN	31
	#define BLSB_TSI_PFX_0_CFG_RESERVED_30	30
	#define BLSB_TSI_PFX_0_CFG_EIS	28
	#define BLSB_TSI_PFX_0_CFG_CP	27
	#define BLSB_TSI_PFX_0_CFG_DP	26
	#define BLSB_TSI_PFX_0_CFG_EP	25
	#define BLSB_TSI_PFX_0_CFG_SP	24
	#define BLSB_TSI_PFX_0_CFG_RESERVED_23_15	15
	#define BLSB_TSI_PFX_0_CFG_OCHDR_RM	14
	#define BLSB_TSI_PFX_0_CFG_OC_CRC_MSK	13
	#define BLSB_TSI_PFX_0_CFG_OCEN	12
	#define BLSB_TSI_PFX_0_CFG_CC	10
	#define BLSB_TSI_PFX_0_CFG_TSHDR_FMT	9
	#define BLSB_TSI_PFX_0_CFG_TSHDR_EN	8
	#define BLSB_TSI_PFX_0_CFG_PGT	7
	#define BLSB_TSI_PFX_0_CFG_PLT	6
	#define BLSB_TSI_PFX_0_CFG_DAV_MSK	5
	#define BLSB_TSI_PFX_0_CFG_ERR_MSK	4
	#define BLSB_TSI_PFX_0_CFG_ENDIAN	3
	#define BLSB_TSI_PFX_0_CFG_MODE	1
	#define BLSB_TSI_PFX_0_CFG_EN	0
	/* Register Bit Widths for TSI_PFX_0_CFG */
	#define BWID_TSI_PFX_0_CFG_P_SN	1
	#define BWID_TSI_PFX_0_CFG_RESERVED_30	1
	#define BWID_TSI_PFX_0_CFG_EIS	2
	#define BWID_TSI_PFX_0_CFG_CP	1
	#define BWID_TSI_PFX_0_CFG_DP	1
	#define BWID_TSI_PFX_0_CFG_EP	1
	#define BWID_TSI_PFX_0_CFG_SP	1
	#define BWID_TSI_PFX_0_CFG_RESERVED_23_15	9
	#define BWID_TSI_PFX_0_CFG_OCHDR_RM	1
	#define BWID_TSI_PFX_0_CFG_OC_CRC_MSK	1
	#define BWID_TSI_PFX_0_CFG_OCEN	1
	#define BWID_TSI_PFX_0_CFG_CC	2
	#define BWID_TSI_PFX_0_CFG_TSHDR_FMT	1
	#define BWID_TSI_PFX_0_CFG_TSHDR_EN	1
	#define BWID_TSI_PFX_0_CFG_PGT	1
	#define BWID_TSI_PFX_0_CFG_PLT	1
	#define BWID_TSI_PFX_0_CFG_DAV_MSK	1
	#define BWID_TSI_PFX_0_CFG_ERR_MSK	1
	#define BWID_TSI_PFX_0_CFG_ENDIAN	1
	#define BWID_TSI_PFX_0_CFG_MODE	2
	#define BWID_TSI_PFX_0_CFG_EN	1
	/* Register Bit MASKS for TSI_PFX_0_CFG */
	#define BMSK_TSI_PFX_0_CFG_P_SN	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_CFG_RESERVED_30	(1<<30) /* == 0x40000000:  */
	#define BMSK_TSI_PFX_0_CFG_EIS	0x30000000 /*  */
	#define BMSK_TSI_PFX_0_CFG_CP	(1<<27) /* == 0x08000000:  */
	#define BMSK_TSI_PFX_0_CFG_DP	(1<<26) /* == 0x04000000:  */
	#define BMSK_TSI_PFX_0_CFG_EP	(1<<25) /* == 0x02000000:  */
	#define BMSK_TSI_PFX_0_CFG_SP	(1<<24) /* == 0x01000000:  */
	#define BMSK_TSI_PFX_0_CFG_RESERVED_23_15	0x00ff8000 /*  */
	#define BMSK_TSI_PFX_0_CFG_OCHDR_RM	(1<<14) /* == 0x00004000:  */
	#define BMSK_TSI_PFX_0_CFG_OC_CRC_MSK	(1<<13) /* == 0x00002000:  */
	#define BMSK_TSI_PFX_0_CFG_OCEN	(1<<12) /* == 0x00001000:  */
	#define BMSK_TSI_PFX_0_CFG_CC	0x00000c00 /*  */
	#define BMSK_TSI_PFX_0_CFG_TSHDR_FMT	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_0_CFG_TSHDR_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_0_CFG_PGT	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_0_CFG_PLT	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_0_CFG_DAV_MSK	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_0_CFG_ERR_MSK	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_0_CFG_ENDIAN	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_0_CFG_MODE	0x00000006 /*  */
	#define BMSK_TSI_PFX_0_CFG_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_0_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_CFG_P_SN	 0x4100, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_CFG_RESERVED_30	 0x4100, 30, 1, 0x40000000
	#define BITFIELD_TSI_PFX_0_CFG_EIS	 0x4100, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_0_CFG_CP	 0x4100, 27, 1, 0x08000000
	#define BITFIELD_TSI_PFX_0_CFG_DP	 0x4100, 26, 1, 0x04000000
	#define BITFIELD_TSI_PFX_0_CFG_EP	 0x4100, 25, 1, 0x02000000
	#define BITFIELD_TSI_PFX_0_CFG_SP	 0x4100, 24, 1, 0x01000000
	#define BITFIELD_TSI_PFX_0_CFG_RESERVED_23_15	 0x4100, 15, 9, 0x00ff8000
	#define BITFIELD_TSI_PFX_0_CFG_OCHDR_RM	 0x4100, 14, 1, 0x00004000
	#define BITFIELD_TSI_PFX_0_CFG_OC_CRC_MSK	 0x4100, 13, 1, 0x00002000
	#define BITFIELD_TSI_PFX_0_CFG_OCEN	 0x4100, 12, 1, 0x00001000
	#define BITFIELD_TSI_PFX_0_CFG_CC	 0x4100, 10, 2, 0x00000c00
	#define BITFIELD_TSI_PFX_0_CFG_TSHDR_FMT	 0x4100, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_0_CFG_TSHDR_EN	 0x4100, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_0_CFG_PGT	 0x4100, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_0_CFG_PLT	 0x4100, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_0_CFG_DAV_MSK	 0x4100, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_0_CFG_ERR_MSK	 0x4100, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_0_CFG_ENDIAN	 0x4100, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_0_CFG_MODE	 0x4100, 1, 2, 0x00000006
	#define BITFIELD_TSI_PFX_0_CFG_EN	 0x4100, 0, 1, 0x00000001
#define ROFF_TSI_PFX_0_STATUS	0x4104 /* Prefilter status register */ 
	#define BITFIELD_TSI_PFX_0_STATUS	 0x4104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_STATUS */
	#define BLSB_TSI_PFX_0_STATUS_RESERVED_31_12	12
	#define BLSB_TSI_PFX_0_STATUS_NIM_ERR	11
	#define BLSB_TSI_PFX_0_STATUS_DAV_LOW	10
	#define BLSB_TSI_PFX_0_STATUS_OCF	9
	#define BLSB_TSI_PFX_0_STATUS_CRC	8
	#define BLSB_TSI_PFX_0_STATUS_DIS	7
	#define BLSB_TSI_PFX_0_STATUS_DET	6
	#define BLSB_TSI_PFX_0_STATUS_PPF	5
	#define BLSB_TSI_PFX_0_STATUS_WDT	4
	#define BLSB_TSI_PFX_0_STATUS_FE	3
	#define BLSB_TSI_PFX_0_STATUS_FF	2
	#define BLSB_TSI_PFX_0_STATUS_PLT	1
	#define BLSB_TSI_PFX_0_STATUS_PGT	0
	/* Register Bit Widths for TSI_PFX_0_STATUS */
	#define BWID_TSI_PFX_0_STATUS_RESERVED_31_12	20
	#define BWID_TSI_PFX_0_STATUS_NIM_ERR	1
	#define BWID_TSI_PFX_0_STATUS_DAV_LOW	1
	#define BWID_TSI_PFX_0_STATUS_OCF	1
	#define BWID_TSI_PFX_0_STATUS_CRC	1
	#define BWID_TSI_PFX_0_STATUS_DIS	1
	#define BWID_TSI_PFX_0_STATUS_DET	1
	#define BWID_TSI_PFX_0_STATUS_PPF	1
	#define BWID_TSI_PFX_0_STATUS_WDT	1
	#define BWID_TSI_PFX_0_STATUS_FE	1
	#define BWID_TSI_PFX_0_STATUS_FF	1
	#define BWID_TSI_PFX_0_STATUS_PLT	1
	#define BWID_TSI_PFX_0_STATUS_PGT	1
	/* Register Bit MASKS for TSI_PFX_0_STATUS */
	#define BMSK_TSI_PFX_0_STATUS_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_0_STATUS_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_0_STATUS_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_0_STATUS_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_0_STATUS_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_0_STATUS_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_0_STATUS_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_0_STATUS_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_0_STATUS_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_0_STATUS_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_0_STATUS_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_0_STATUS_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_0_STATUS_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_0_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_STATUS_RESERVED_31_12	 0x4104, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_0_STATUS_NIM_ERR	 0x4104, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_0_STATUS_DAV_LOW	 0x4104, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_0_STATUS_OCF	 0x4104, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_0_STATUS_CRC	 0x4104, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_0_STATUS_DIS	 0x4104, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_0_STATUS_DET	 0x4104, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_0_STATUS_PPF	 0x4104, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_0_STATUS_WDT	 0x4104, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_0_STATUS_FE	 0x4104, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_0_STATUS_FF	 0x4104, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_0_STATUS_PLT	 0x4104, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_0_STATUS_PGT	 0x4104, 0, 1, 0x00000001
#define ROFF_TSI_PFX_0_ENABLE	0x4108 /* Prefilter enable register */ 
	#define BITFIELD_TSI_PFX_0_ENABLE	 0x4108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_ENABLE */
	#define BLSB_TSI_PFX_0_ENABLE_RESERVED_31_12	12
	#define BLSB_TSI_PFX_0_ENABLE_NIM_ERR	11
	#define BLSB_TSI_PFX_0_ENABLE_DAV_LOW	10
	#define BLSB_TSI_PFX_0_ENABLE_OCF	9
	#define BLSB_TSI_PFX_0_ENABLE_CRC	8
	#define BLSB_TSI_PFX_0_ENABLE_DIS	7
	#define BLSB_TSI_PFX_0_ENABLE_DET	6
	#define BLSB_TSI_PFX_0_ENABLE_PPF	5
	#define BLSB_TSI_PFX_0_ENABLE_WDT	4
	#define BLSB_TSI_PFX_0_ENABLE_FE	3
	#define BLSB_TSI_PFX_0_ENABLE_FF	2
	#define BLSB_TSI_PFX_0_ENABLE_PLT	1
	#define BLSB_TSI_PFX_0_ENABLE_PGT	0
	/* Register Bit Widths for TSI_PFX_0_ENABLE */
	#define BWID_TSI_PFX_0_ENABLE_RESERVED_31_12	20
	#define BWID_TSI_PFX_0_ENABLE_NIM_ERR	1
	#define BWID_TSI_PFX_0_ENABLE_DAV_LOW	1
	#define BWID_TSI_PFX_0_ENABLE_OCF	1
	#define BWID_TSI_PFX_0_ENABLE_CRC	1
	#define BWID_TSI_PFX_0_ENABLE_DIS	1
	#define BWID_TSI_PFX_0_ENABLE_DET	1
	#define BWID_TSI_PFX_0_ENABLE_PPF	1
	#define BWID_TSI_PFX_0_ENABLE_WDT	1
	#define BWID_TSI_PFX_0_ENABLE_FE	1
	#define BWID_TSI_PFX_0_ENABLE_FF	1
	#define BWID_TSI_PFX_0_ENABLE_PLT	1
	#define BWID_TSI_PFX_0_ENABLE_PGT	1
	/* Register Bit MASKS for TSI_PFX_0_ENABLE */
	#define BMSK_TSI_PFX_0_ENABLE_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_0_ENABLE_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_0_ENABLE_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_0_ENABLE_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_0_ENABLE_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_0_ENABLE_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_0_ENABLE_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_0_ENABLE_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_0_ENABLE_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_0_ENABLE_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_0_ENABLE_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_0_ENABLE_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_0_ENABLE_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_0_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_ENABLE_RESERVED_31_12	 0x4108, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_0_ENABLE_NIM_ERR	 0x4108, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_0_ENABLE_DAV_LOW	 0x4108, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_0_ENABLE_OCF	 0x4108, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_0_ENABLE_CRC	 0x4108, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_0_ENABLE_DIS	 0x4108, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_0_ENABLE_DET	 0x4108, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_0_ENABLE_PPF	 0x4108, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_0_ENABLE_WDT	 0x4108, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_0_ENABLE_FE	 0x4108, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_0_ENABLE_FF	 0x4108, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_0_ENABLE_PLT	 0x4108, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_0_ENABLE_PGT	 0x4108, 0, 1, 0x00000001
#define ROFF_TSI_PFX_0_FERR_STATUS	0x410c /* Prefilter FERR status register */ 
	#define BITFIELD_TSI_PFX_0_FERR_STATUS	 0x410c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_FERR_STATUS */
	#define BLSB_TSI_PFX_0_FERR_STATUS_RESERVED_31_29	29
	#define BLSB_TSI_PFX_0_FERR_STATUS_FERR_VAL	24
	#define BLSB_TSI_PFX_0_FERR_STATUS_RESERVED_23_22	22
	#define BLSB_TSI_PFX_0_FERR_STATUS_PID	8
	#define BLSB_TSI_PFX_0_FERR_STATUS_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_0_FERR_STATUS */
	#define BWID_TSI_PFX_0_FERR_STATUS_RESERVED_31_29	3
	#define BWID_TSI_PFX_0_FERR_STATUS_FERR_VAL	5
	#define BWID_TSI_PFX_0_FERR_STATUS_RESERVED_23_22	2
	#define BWID_TSI_PFX_0_FERR_STATUS_PID	14
	#define BWID_TSI_PFX_0_FERR_STATUS_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_0_FERR_STATUS */
	#define BMSK_TSI_PFX_0_FERR_STATUS_RESERVED_31_29	0xe0000000 /*  */
	#define BMSK_TSI_PFX_0_FERR_STATUS_FERR_VAL	0x1f000000 /*  */
	#define BMSK_TSI_PFX_0_FERR_STATUS_RESERVED_23_22	0x00c00000 /*  */
	#define BMSK_TSI_PFX_0_FERR_STATUS_PID	0x003fff00 /*  */
	#define BMSK_TSI_PFX_0_FERR_STATUS_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_0_FERR_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_FERR_STATUS_RESERVED_31_29	 0x410c, 29, 3, 0xe0000000
	#define BITFIELD_TSI_PFX_0_FERR_STATUS_FERR_VAL	 0x410c, 24, 5, 0x1f000000
	#define BITFIELD_TSI_PFX_0_FERR_STATUS_RESERVED_23_22	 0x410c, 22, 2, 0x00c00000
	#define BITFIELD_TSI_PFX_0_FERR_STATUS_PID	 0x410c, 8, 14, 0x003fff00
	#define BITFIELD_TSI_PFX_0_FERR_STATUS_RESERVED_7_0	 0x410c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_0_DMA_BASE	0x4200 /* Prefilter DMA Base */ 
	#define BITFIELD_TSI_PFX_0_DMA_BASE	 0x4200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_DMA_SIZE	0x4204 /* Prefilter DMA Size */ 
	#define BITFIELD_TSI_PFX_0_DMA_SIZE	 0x4204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_DMA_WR_PTR	0x4208 /* Prefilter DMA Write Pointer */ 
	#define BITFIELD_TSI_PFX_0_DMA_WR_PTR	 0x4208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_DMA_SHDW_WR_PTR_ADDR	0x420c /* Prefilter DMA Shadow Write Pointer Address */ 
	#define BITFIELD_TSI_PFX_0_DMA_SHDW_WR_PTR_ADDR	 0x420c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_DMA_RD_PTR	0x4210 /* Prefilter DMA Read Pointer */ 
	#define BITFIELD_TSI_PFX_0_DMA_RD_PTR	 0x4210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_DMA_SHDW_WR_CTR	0x4214 /* Prefilter DMA Shadow Write Counter */ 
	#define BITFIELD_TSI_PFX_0_DMA_SHDW_WR_CTR	 0x4214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_NIM_WDT	0x4218 /* Prefilter NIM Watch Dog Timer */ 
	#define BITFIELD_TSI_PFX_0_NIM_WDT	 0x4218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_NIM_WDT */
	#define BLSB_TSI_PFX_0_NIM_WDT_ENABLE	31
	#define BLSB_TSI_PFX_0_NIM_WDT_WDT	0
	/* Register Bit Widths for TSI_PFX_0_NIM_WDT */
	#define BWID_TSI_PFX_0_NIM_WDT_ENABLE	1
	#define BWID_TSI_PFX_0_NIM_WDT_WDT	31
	/* Register Bit MASKS for TSI_PFX_0_NIM_WDT */
	#define BMSK_TSI_PFX_0_NIM_WDT_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_NIM_WDT_WDT	0x7fffffff /*  */
	/* Register BITFIELD for TSI_PFX_0_NIM_WDT - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_NIM_WDT_ENABLE	 0x4218, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_NIM_WDT_WDT	 0x4218, 0, 31, 0x7fffffff
#define ROFF_TSI_PFX_0_PCR_CFG	0x4300 /* Prefilter PCR Config */ 
	#define BITFIELD_TSI_PFX_0_PCR_CFG	 0x4300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_PCR_REMOTE_A0	0x431c /* Prefilter PCR Remote A0 */ 
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A0	 0x431c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_PCR_REMOTE_A1	0x4320 /* Prefilter PCR Remote A1 */ 
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A1	 0x4320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_PCR_REMOTE_A1 */
	#define BLSB_TSI_PFX_0_PCR_REMOTE_A1_PCRR_MSBA1	31
	#define BLSB_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_30_17	17
	#define BLSB_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LOCK	16
	#define BLSB_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_15_9	9
	#define BLSB_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LSBSA1	0
	/* Register Bit Widths for TSI_PFX_0_PCR_REMOTE_A1 */
	#define BWID_TSI_PFX_0_PCR_REMOTE_A1_PCRR_MSBA1	1
	#define BWID_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_30_17	14
	#define BWID_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LOCK	1
	#define BWID_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_15_9	7
	#define BWID_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LSBSA1	9
	/* Register Bit MASKS for TSI_PFX_0_PCR_REMOTE_A1 */
	#define BMSK_TSI_PFX_0_PCR_REMOTE_A1_PCRR_MSBA1	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_30_17	0x7ffe0000 /*  */
	#define BMSK_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LOCK	(1<<16) /* == 0x00010000:  */
	#define BMSK_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_15_9	0x0000fe00 /*  */
	#define BMSK_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LSBSA1	0x000001ff /*  */
	/* Register BITFIELD for TSI_PFX_0_PCR_REMOTE_A1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A1_PCRR_MSBA1	 0x4320, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_30_17	 0x4320, 17, 14, 0x7ffe0000
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LOCK	 0x4320, 16, 1, 0x00010000
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A1_RESERVED_15_9	 0x4320, 9, 7, 0x0000fe00
	#define BITFIELD_TSI_PFX_0_PCR_REMOTE_A1_PCRR_LSBSA1	 0x4320, 0, 9, 0x000001ff
#define ROFF_TSI_PFX_0_OC_HEADER_CFG	0x4340 /* Prefilter OC Header Config */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG	 0x4340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_OC_HEADER_CFG */
	#define BLSB_TSI_PFX_0_OC_HEADER_CFG_RESERVED_31_30	30
	#define BLSB_TSI_PFX_0_OC_HEADER_CFG_OCHS	28
	#define BLSB_TSI_PFX_0_OC_HEADER_CFG_RESERVED_27_10	10
	#define BLSB_TSI_PFX_0_OC_HEADER_CFG_OCLTS	9
	#define BLSB_TSI_PFX_0_OC_HEADER_CFG_RESERVED_8	8
	#define BLSB_TSI_PFX_0_OC_HEADER_CFG_OCLTSID	0
	/* Register Bit Widths for TSI_PFX_0_OC_HEADER_CFG */
	#define BWID_TSI_PFX_0_OC_HEADER_CFG_RESERVED_31_30	2
	#define BWID_TSI_PFX_0_OC_HEADER_CFG_OCHS	2
	#define BWID_TSI_PFX_0_OC_HEADER_CFG_RESERVED_27_10	18
	#define BWID_TSI_PFX_0_OC_HEADER_CFG_OCLTS	1
	#define BWID_TSI_PFX_0_OC_HEADER_CFG_RESERVED_8	1
	#define BWID_TSI_PFX_0_OC_HEADER_CFG_OCLTSID	8
	/* Register Bit MASKS for TSI_PFX_0_OC_HEADER_CFG */
	#define BMSK_TSI_PFX_0_OC_HEADER_CFG_RESERVED_31_30	0xc0000000 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_CFG_OCHS	0x30000000 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_CFG_RESERVED_27_10	0x0ffffc00 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_CFG_OCLTS	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_0_OC_HEADER_CFG_RESERVED_8	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_0_OC_HEADER_CFG_OCLTSID	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_0_OC_HEADER_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG_RESERVED_31_30	 0x4340, 30, 2, 0xc0000000
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG_OCHS	 0x4340, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG_RESERVED_27_10	 0x4340, 10, 18, 0x0ffffc00
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG_OCLTS	 0x4340, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG_RESERVED_8	 0x4340, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_0_OC_HEADER_CFG_OCLTSID	 0x4340, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_0_OC_HEADER_0A	0x4344 /* Prefilter OC Header-A0 */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_0A	 0x4344, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_OC_HEADER_0A */
	#define BLSB_TSI_PFX_0_OC_HEADER_0A_OCLTSID	24
	#define BLSB_TSI_PFX_0_OC_HEADER_0A_OCHOSTRES	8
	#define BLSB_TSI_PFX_0_OC_HEADER_0A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_0_OC_HEADER_0A */
	#define BWID_TSI_PFX_0_OC_HEADER_0A_OCLTSID	8
	#define BWID_TSI_PFX_0_OC_HEADER_0A_OCHOSTRES	15
	#define BWID_TSI_PFX_0_OC_HEADER_0A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_0_OC_HEADER_0A */
	#define BMSK_TSI_PFX_0_OC_HEADER_0A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_0A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_0A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_0_OC_HEADER_0A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_OC_HEADER_0A_OCLTSID	 0x4344, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_0_OC_HEADER_0A_OCHOSTRES	 0x4344, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_0_OC_HEADER_0A_RESERVED_7_0	 0x4344, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_0_OC_HEADER_0B	0x4348 /* Prefilter OC Header-B0 */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_0B	 0x4348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_OC_HEADER_1A	0x434c /* Prefilter OC Header-A1 */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_1A	 0x434c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_OC_HEADER_1A */
	#define BLSB_TSI_PFX_0_OC_HEADER_1A_OCLTSID	24
	#define BLSB_TSI_PFX_0_OC_HEADER_1A_OCHOSTRES	8
	#define BLSB_TSI_PFX_0_OC_HEADER_1A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_0_OC_HEADER_1A */
	#define BWID_TSI_PFX_0_OC_HEADER_1A_OCLTSID	8
	#define BWID_TSI_PFX_0_OC_HEADER_1A_OCHOSTRES	15
	#define BWID_TSI_PFX_0_OC_HEADER_1A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_0_OC_HEADER_1A */
	#define BMSK_TSI_PFX_0_OC_HEADER_1A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_1A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_1A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_0_OC_HEADER_1A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_OC_HEADER_1A_OCLTSID	 0x434c, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_0_OC_HEADER_1A_OCHOSTRES	 0x434c, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_0_OC_HEADER_1A_RESERVED_7_0	 0x434c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_0_OC_HEADER_1B	0x4350 /* Prefilter OC Header-B1 */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_1B	 0x4350, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_OC_HEADER_2A	0x4354 /* Prefilter OC Header-A2 */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_2A	 0x4354, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_0_OC_HEADER_2A */
	#define BLSB_TSI_PFX_0_OC_HEADER_2A_OCLTSID	24
	#define BLSB_TSI_PFX_0_OC_HEADER_2A_OCHOSTRES	8
	#define BLSB_TSI_PFX_0_OC_HEADER_2A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_0_OC_HEADER_2A */
	#define BWID_TSI_PFX_0_OC_HEADER_2A_OCLTSID	8
	#define BWID_TSI_PFX_0_OC_HEADER_2A_OCHOSTRES	15
	#define BWID_TSI_PFX_0_OC_HEADER_2A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_0_OC_HEADER_2A */
	#define BMSK_TSI_PFX_0_OC_HEADER_2A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_2A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_0_OC_HEADER_2A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_0_OC_HEADER_2A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_0_OC_HEADER_2A_OCLTSID	 0x4354, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_0_OC_HEADER_2A_OCHOSTRES	 0x4354, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_0_OC_HEADER_2A_RESERVED_7_0	 0x4354, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_0_OC_HEADER_2B	0x4358 /* Prefilter OC Header-B2 */ 
	#define BITFIELD_TSI_PFX_0_OC_HEADER_2B	 0x4358, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_OMAR_SEL	0x4360 /* Prefilter OMAR select */ 
	#define BITFIELD_TSI_PFX_0_OMAR_SEL	 0x4360, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_0_TIMESTAMP_CTR	0x4400 /* Prefilter time stamp counter */ 
	#define BITFIELD_TSI_PFX_0_TIMESTAMP_CTR	 0x4400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_PMM0	0x8000 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM0	 0x8000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM0 */
	#define BLSB_TSI_PFX_1_PMM0_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM0_MASK	16
	#define BLSB_TSI_PFX_1_PMM0_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM0_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM0 */
	#define BWID_TSI_PFX_1_PMM0_ENABLE	1
	#define BWID_TSI_PFX_1_PMM0_MASK	15
	#define BWID_TSI_PFX_1_PMM0_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM0_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM0 */
	#define BMSK_TSI_PFX_1_PMM0_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM0_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM0_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM0_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM0 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM0_ENABLE	 0x8000, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM0_MASK	 0x8000, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM0_RESERVED_15	 0x8000, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM0_EXACTVALUE	 0x8000, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM1	0x8004 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM1	 0x8004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM1 */
	#define BLSB_TSI_PFX_1_PMM1_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM1_MASK	16
	#define BLSB_TSI_PFX_1_PMM1_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM1_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM1 */
	#define BWID_TSI_PFX_1_PMM1_ENABLE	1
	#define BWID_TSI_PFX_1_PMM1_MASK	15
	#define BWID_TSI_PFX_1_PMM1_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM1_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM1 */
	#define BMSK_TSI_PFX_1_PMM1_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM1_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM1_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM1_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM1_ENABLE	 0x8004, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM1_MASK	 0x8004, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM1_RESERVED_15	 0x8004, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM1_EXACTVALUE	 0x8004, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM2	0x8008 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM2	 0x8008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM2 */
	#define BLSB_TSI_PFX_1_PMM2_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM2_MASK	16
	#define BLSB_TSI_PFX_1_PMM2_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM2_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM2 */
	#define BWID_TSI_PFX_1_PMM2_ENABLE	1
	#define BWID_TSI_PFX_1_PMM2_MASK	15
	#define BWID_TSI_PFX_1_PMM2_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM2_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM2 */
	#define BMSK_TSI_PFX_1_PMM2_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM2_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM2_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM2_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM2 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM2_ENABLE	 0x8008, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM2_MASK	 0x8008, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM2_RESERVED_15	 0x8008, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM2_EXACTVALUE	 0x8008, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM3	0x800c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM3	 0x800c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM3 */
	#define BLSB_TSI_PFX_1_PMM3_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM3_MASK	16
	#define BLSB_TSI_PFX_1_PMM3_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM3_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM3 */
	#define BWID_TSI_PFX_1_PMM3_ENABLE	1
	#define BWID_TSI_PFX_1_PMM3_MASK	15
	#define BWID_TSI_PFX_1_PMM3_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM3_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM3 */
	#define BMSK_TSI_PFX_1_PMM3_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM3_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM3_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM3_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM3 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM3_ENABLE	 0x800c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM3_MASK	 0x800c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM3_RESERVED_15	 0x800c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM3_EXACTVALUE	 0x800c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM4	0x8010 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM4	 0x8010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM4 */
	#define BLSB_TSI_PFX_1_PMM4_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM4_MASK	16
	#define BLSB_TSI_PFX_1_PMM4_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM4_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM4 */
	#define BWID_TSI_PFX_1_PMM4_ENABLE	1
	#define BWID_TSI_PFX_1_PMM4_MASK	15
	#define BWID_TSI_PFX_1_PMM4_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM4_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM4 */
	#define BMSK_TSI_PFX_1_PMM4_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM4_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM4_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM4_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM4 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM4_ENABLE	 0x8010, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM4_MASK	 0x8010, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM4_RESERVED_15	 0x8010, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM4_EXACTVALUE	 0x8010, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM5	0x8014 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM5	 0x8014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM5 */
	#define BLSB_TSI_PFX_1_PMM5_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM5_MASK	16
	#define BLSB_TSI_PFX_1_PMM5_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM5_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM5 */
	#define BWID_TSI_PFX_1_PMM5_ENABLE	1
	#define BWID_TSI_PFX_1_PMM5_MASK	15
	#define BWID_TSI_PFX_1_PMM5_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM5_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM5 */
	#define BMSK_TSI_PFX_1_PMM5_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM5_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM5_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM5_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM5 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM5_ENABLE	 0x8014, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM5_MASK	 0x8014, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM5_RESERVED_15	 0x8014, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM5_EXACTVALUE	 0x8014, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM6	0x8018 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM6	 0x8018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM6 */
	#define BLSB_TSI_PFX_1_PMM6_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM6_MASK	16
	#define BLSB_TSI_PFX_1_PMM6_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM6_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM6 */
	#define BWID_TSI_PFX_1_PMM6_ENABLE	1
	#define BWID_TSI_PFX_1_PMM6_MASK	15
	#define BWID_TSI_PFX_1_PMM6_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM6_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM6 */
	#define BMSK_TSI_PFX_1_PMM6_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM6_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM6_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM6_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM6 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM6_ENABLE	 0x8018, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM6_MASK	 0x8018, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM6_RESERVED_15	 0x8018, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM6_EXACTVALUE	 0x8018, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM7	0x801c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM7	 0x801c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM7 */
	#define BLSB_TSI_PFX_1_PMM7_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM7_MASK	16
	#define BLSB_TSI_PFX_1_PMM7_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM7_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM7 */
	#define BWID_TSI_PFX_1_PMM7_ENABLE	1
	#define BWID_TSI_PFX_1_PMM7_MASK	15
	#define BWID_TSI_PFX_1_PMM7_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM7_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM7 */
	#define BMSK_TSI_PFX_1_PMM7_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM7_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM7_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM7_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM7 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM7_ENABLE	 0x801c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM7_MASK	 0x801c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM7_RESERVED_15	 0x801c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM7_EXACTVALUE	 0x801c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM8	0x8020 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM8	 0x8020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM8 */
	#define BLSB_TSI_PFX_1_PMM8_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM8_MASK	16
	#define BLSB_TSI_PFX_1_PMM8_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM8_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM8 */
	#define BWID_TSI_PFX_1_PMM8_ENABLE	1
	#define BWID_TSI_PFX_1_PMM8_MASK	15
	#define BWID_TSI_PFX_1_PMM8_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM8_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM8 */
	#define BMSK_TSI_PFX_1_PMM8_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM8_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM8_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM8_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM8 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM8_ENABLE	 0x8020, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM8_MASK	 0x8020, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM8_RESERVED_15	 0x8020, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM8_EXACTVALUE	 0x8020, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM9	0x8024 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM9	 0x8024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM9 */
	#define BLSB_TSI_PFX_1_PMM9_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM9_MASK	16
	#define BLSB_TSI_PFX_1_PMM9_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM9_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM9 */
	#define BWID_TSI_PFX_1_PMM9_ENABLE	1
	#define BWID_TSI_PFX_1_PMM9_MASK	15
	#define BWID_TSI_PFX_1_PMM9_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM9_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM9 */
	#define BMSK_TSI_PFX_1_PMM9_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM9_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM9_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM9_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM9 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM9_ENABLE	 0x8024, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM9_MASK	 0x8024, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM9_RESERVED_15	 0x8024, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM9_EXACTVALUE	 0x8024, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM10	0x8028 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM10	 0x8028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM10 */
	#define BLSB_TSI_PFX_1_PMM10_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM10_MASK	16
	#define BLSB_TSI_PFX_1_PMM10_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM10_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM10 */
	#define BWID_TSI_PFX_1_PMM10_ENABLE	1
	#define BWID_TSI_PFX_1_PMM10_MASK	15
	#define BWID_TSI_PFX_1_PMM10_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM10_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM10 */
	#define BMSK_TSI_PFX_1_PMM10_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM10_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM10_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM10_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM10 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM10_ENABLE	 0x8028, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM10_MASK	 0x8028, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM10_RESERVED_15	 0x8028, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM10_EXACTVALUE	 0x8028, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM11	0x802c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM11	 0x802c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM11 */
	#define BLSB_TSI_PFX_1_PMM11_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM11_MASK	16
	#define BLSB_TSI_PFX_1_PMM11_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM11_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM11 */
	#define BWID_TSI_PFX_1_PMM11_ENABLE	1
	#define BWID_TSI_PFX_1_PMM11_MASK	15
	#define BWID_TSI_PFX_1_PMM11_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM11_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM11 */
	#define BMSK_TSI_PFX_1_PMM11_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM11_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM11_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM11_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM11 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM11_ENABLE	 0x802c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM11_MASK	 0x802c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM11_RESERVED_15	 0x802c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM11_EXACTVALUE	 0x802c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM12	0x8030 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM12	 0x8030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM12 */
	#define BLSB_TSI_PFX_1_PMM12_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM12_MASK	16
	#define BLSB_TSI_PFX_1_PMM12_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM12_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM12 */
	#define BWID_TSI_PFX_1_PMM12_ENABLE	1
	#define BWID_TSI_PFX_1_PMM12_MASK	15
	#define BWID_TSI_PFX_1_PMM12_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM12_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM12 */
	#define BMSK_TSI_PFX_1_PMM12_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM12_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM12_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM12_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM12 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM12_ENABLE	 0x8030, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM12_MASK	 0x8030, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM12_RESERVED_15	 0x8030, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM12_EXACTVALUE	 0x8030, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM13	0x8034 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM13	 0x8034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM13 */
	#define BLSB_TSI_PFX_1_PMM13_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM13_MASK	16
	#define BLSB_TSI_PFX_1_PMM13_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM13_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM13 */
	#define BWID_TSI_PFX_1_PMM13_ENABLE	1
	#define BWID_TSI_PFX_1_PMM13_MASK	15
	#define BWID_TSI_PFX_1_PMM13_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM13_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM13 */
	#define BMSK_TSI_PFX_1_PMM13_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM13_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM13_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM13_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM13 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM13_ENABLE	 0x8034, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM13_MASK	 0x8034, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM13_RESERVED_15	 0x8034, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM13_EXACTVALUE	 0x8034, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM14	0x8038 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM14	 0x8038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM14 */
	#define BLSB_TSI_PFX_1_PMM14_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM14_MASK	16
	#define BLSB_TSI_PFX_1_PMM14_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM14_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM14 */
	#define BWID_TSI_PFX_1_PMM14_ENABLE	1
	#define BWID_TSI_PFX_1_PMM14_MASK	15
	#define BWID_TSI_PFX_1_PMM14_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM14_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM14 */
	#define BMSK_TSI_PFX_1_PMM14_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM14_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM14_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM14_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM14 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM14_ENABLE	 0x8038, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM14_MASK	 0x8038, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM14_RESERVED_15	 0x8038, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM14_EXACTVALUE	 0x8038, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM15	0x803c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM15	 0x803c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM15 */
	#define BLSB_TSI_PFX_1_PMM15_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM15_MASK	16
	#define BLSB_TSI_PFX_1_PMM15_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM15_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM15 */
	#define BWID_TSI_PFX_1_PMM15_ENABLE	1
	#define BWID_TSI_PFX_1_PMM15_MASK	15
	#define BWID_TSI_PFX_1_PMM15_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM15_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM15 */
	#define BMSK_TSI_PFX_1_PMM15_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM15_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM15_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM15_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM15 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM15_ENABLE	 0x803c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM15_MASK	 0x803c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM15_RESERVED_15	 0x803c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM15_EXACTVALUE	 0x803c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM16	0x8040 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM16	 0x8040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM16 */
	#define BLSB_TSI_PFX_1_PMM16_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM16_MASK	16
	#define BLSB_TSI_PFX_1_PMM16_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM16_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM16 */
	#define BWID_TSI_PFX_1_PMM16_ENABLE	1
	#define BWID_TSI_PFX_1_PMM16_MASK	15
	#define BWID_TSI_PFX_1_PMM16_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM16_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM16 */
	#define BMSK_TSI_PFX_1_PMM16_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM16_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM16_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM16_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM16 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM16_ENABLE	 0x8040, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM16_MASK	 0x8040, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM16_RESERVED_15	 0x8040, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM16_EXACTVALUE	 0x8040, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM17	0x8044 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM17	 0x8044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM17 */
	#define BLSB_TSI_PFX_1_PMM17_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM17_MASK	16
	#define BLSB_TSI_PFX_1_PMM17_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM17_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM17 */
	#define BWID_TSI_PFX_1_PMM17_ENABLE	1
	#define BWID_TSI_PFX_1_PMM17_MASK	15
	#define BWID_TSI_PFX_1_PMM17_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM17_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM17 */
	#define BMSK_TSI_PFX_1_PMM17_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM17_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM17_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM17_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM17 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM17_ENABLE	 0x8044, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM17_MASK	 0x8044, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM17_RESERVED_15	 0x8044, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM17_EXACTVALUE	 0x8044, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM18	0x8048 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM18	 0x8048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM18 */
	#define BLSB_TSI_PFX_1_PMM18_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM18_MASK	16
	#define BLSB_TSI_PFX_1_PMM18_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM18_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM18 */
	#define BWID_TSI_PFX_1_PMM18_ENABLE	1
	#define BWID_TSI_PFX_1_PMM18_MASK	15
	#define BWID_TSI_PFX_1_PMM18_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM18_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM18 */
	#define BMSK_TSI_PFX_1_PMM18_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM18_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM18_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM18_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM18 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM18_ENABLE	 0x8048, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM18_MASK	 0x8048, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM18_RESERVED_15	 0x8048, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM18_EXACTVALUE	 0x8048, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM19	0x804c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM19	 0x804c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM19 */
	#define BLSB_TSI_PFX_1_PMM19_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM19_MASK	16
	#define BLSB_TSI_PFX_1_PMM19_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM19_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM19 */
	#define BWID_TSI_PFX_1_PMM19_ENABLE	1
	#define BWID_TSI_PFX_1_PMM19_MASK	15
	#define BWID_TSI_PFX_1_PMM19_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM19_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM19 */
	#define BMSK_TSI_PFX_1_PMM19_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM19_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM19_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM19_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM19 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM19_ENABLE	 0x804c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM19_MASK	 0x804c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM19_RESERVED_15	 0x804c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM19_EXACTVALUE	 0x804c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM20	0x8050 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM20	 0x8050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM20 */
	#define BLSB_TSI_PFX_1_PMM20_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM20_MASK	16
	#define BLSB_TSI_PFX_1_PMM20_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM20_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM20 */
	#define BWID_TSI_PFX_1_PMM20_ENABLE	1
	#define BWID_TSI_PFX_1_PMM20_MASK	15
	#define BWID_TSI_PFX_1_PMM20_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM20_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM20 */
	#define BMSK_TSI_PFX_1_PMM20_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM20_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM20_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM20_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM20 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM20_ENABLE	 0x8050, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM20_MASK	 0x8050, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM20_RESERVED_15	 0x8050, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM20_EXACTVALUE	 0x8050, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM21	0x8054 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM21	 0x8054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM21 */
	#define BLSB_TSI_PFX_1_PMM21_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM21_MASK	16
	#define BLSB_TSI_PFX_1_PMM21_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM21_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM21 */
	#define BWID_TSI_PFX_1_PMM21_ENABLE	1
	#define BWID_TSI_PFX_1_PMM21_MASK	15
	#define BWID_TSI_PFX_1_PMM21_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM21_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM21 */
	#define BMSK_TSI_PFX_1_PMM21_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM21_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM21_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM21_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM21 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM21_ENABLE	 0x8054, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM21_MASK	 0x8054, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM21_RESERVED_15	 0x8054, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM21_EXACTVALUE	 0x8054, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM22	0x8058 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM22	 0x8058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM22 */
	#define BLSB_TSI_PFX_1_PMM22_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM22_MASK	16
	#define BLSB_TSI_PFX_1_PMM22_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM22_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM22 */
	#define BWID_TSI_PFX_1_PMM22_ENABLE	1
	#define BWID_TSI_PFX_1_PMM22_MASK	15
	#define BWID_TSI_PFX_1_PMM22_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM22_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM22 */
	#define BMSK_TSI_PFX_1_PMM22_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM22_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM22_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM22_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM22 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM22_ENABLE	 0x8058, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM22_MASK	 0x8058, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM22_RESERVED_15	 0x8058, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM22_EXACTVALUE	 0x8058, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM23	0x805c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM23	 0x805c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM23 */
	#define BLSB_TSI_PFX_1_PMM23_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM23_MASK	16
	#define BLSB_TSI_PFX_1_PMM23_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM23_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM23 */
	#define BWID_TSI_PFX_1_PMM23_ENABLE	1
	#define BWID_TSI_PFX_1_PMM23_MASK	15
	#define BWID_TSI_PFX_1_PMM23_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM23_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM23 */
	#define BMSK_TSI_PFX_1_PMM23_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM23_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM23_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM23_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM23 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM23_ENABLE	 0x805c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM23_MASK	 0x805c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM23_RESERVED_15	 0x805c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM23_EXACTVALUE	 0x805c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM24	0x8060 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM24	 0x8060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM24 */
	#define BLSB_TSI_PFX_1_PMM24_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM24_MASK	16
	#define BLSB_TSI_PFX_1_PMM24_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM24_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM24 */
	#define BWID_TSI_PFX_1_PMM24_ENABLE	1
	#define BWID_TSI_PFX_1_PMM24_MASK	15
	#define BWID_TSI_PFX_1_PMM24_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM24_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM24 */
	#define BMSK_TSI_PFX_1_PMM24_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM24_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM24_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM24_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM24 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM24_ENABLE	 0x8060, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM24_MASK	 0x8060, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM24_RESERVED_15	 0x8060, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM24_EXACTVALUE	 0x8060, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM25	0x8064 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM25	 0x8064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM25 */
	#define BLSB_TSI_PFX_1_PMM25_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM25_MASK	16
	#define BLSB_TSI_PFX_1_PMM25_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM25_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM25 */
	#define BWID_TSI_PFX_1_PMM25_ENABLE	1
	#define BWID_TSI_PFX_1_PMM25_MASK	15
	#define BWID_TSI_PFX_1_PMM25_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM25_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM25 */
	#define BMSK_TSI_PFX_1_PMM25_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM25_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM25_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM25_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM25 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM25_ENABLE	 0x8064, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM25_MASK	 0x8064, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM25_RESERVED_15	 0x8064, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM25_EXACTVALUE	 0x8064, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM26	0x8068 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM26	 0x8068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM26 */
	#define BLSB_TSI_PFX_1_PMM26_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM26_MASK	16
	#define BLSB_TSI_PFX_1_PMM26_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM26_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM26 */
	#define BWID_TSI_PFX_1_PMM26_ENABLE	1
	#define BWID_TSI_PFX_1_PMM26_MASK	15
	#define BWID_TSI_PFX_1_PMM26_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM26_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM26 */
	#define BMSK_TSI_PFX_1_PMM26_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM26_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM26_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM26_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM26 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM26_ENABLE	 0x8068, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM26_MASK	 0x8068, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM26_RESERVED_15	 0x8068, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM26_EXACTVALUE	 0x8068, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM27	0x806c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM27	 0x806c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM27 */
	#define BLSB_TSI_PFX_1_PMM27_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM27_MASK	16
	#define BLSB_TSI_PFX_1_PMM27_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM27_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM27 */
	#define BWID_TSI_PFX_1_PMM27_ENABLE	1
	#define BWID_TSI_PFX_1_PMM27_MASK	15
	#define BWID_TSI_PFX_1_PMM27_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM27_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM27 */
	#define BMSK_TSI_PFX_1_PMM27_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM27_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM27_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM27_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM27 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM27_ENABLE	 0x806c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM27_MASK	 0x806c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM27_RESERVED_15	 0x806c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM27_EXACTVALUE	 0x806c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM28	0x8070 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM28	 0x8070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM28 */
	#define BLSB_TSI_PFX_1_PMM28_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM28_MASK	16
	#define BLSB_TSI_PFX_1_PMM28_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM28_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM28 */
	#define BWID_TSI_PFX_1_PMM28_ENABLE	1
	#define BWID_TSI_PFX_1_PMM28_MASK	15
	#define BWID_TSI_PFX_1_PMM28_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM28_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM28 */
	#define BMSK_TSI_PFX_1_PMM28_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM28_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM28_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM28_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM28 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM28_ENABLE	 0x8070, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM28_MASK	 0x8070, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM28_RESERVED_15	 0x8070, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM28_EXACTVALUE	 0x8070, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM29	0x8074 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM29	 0x8074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM29 */
	#define BLSB_TSI_PFX_1_PMM29_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM29_MASK	16
	#define BLSB_TSI_PFX_1_PMM29_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM29_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM29 */
	#define BWID_TSI_PFX_1_PMM29_ENABLE	1
	#define BWID_TSI_PFX_1_PMM29_MASK	15
	#define BWID_TSI_PFX_1_PMM29_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM29_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM29 */
	#define BMSK_TSI_PFX_1_PMM29_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM29_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM29_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM29_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM29 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM29_ENABLE	 0x8074, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM29_MASK	 0x8074, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM29_RESERVED_15	 0x8074, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM29_EXACTVALUE	 0x8074, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM30	0x8078 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM30	 0x8078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM30 */
	#define BLSB_TSI_PFX_1_PMM30_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM30_MASK	16
	#define BLSB_TSI_PFX_1_PMM30_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM30_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM30 */
	#define BWID_TSI_PFX_1_PMM30_ENABLE	1
	#define BWID_TSI_PFX_1_PMM30_MASK	15
	#define BWID_TSI_PFX_1_PMM30_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM30_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM30 */
	#define BMSK_TSI_PFX_1_PMM30_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM30_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM30_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM30_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM30 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM30_ENABLE	 0x8078, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM30_MASK	 0x8078, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM30_RESERVED_15	 0x8078, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM30_EXACTVALUE	 0x8078, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_PMM31	0x807c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_1_PMM31	 0x807c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PMM31 */
	#define BLSB_TSI_PFX_1_PMM31_ENABLE	31
	#define BLSB_TSI_PFX_1_PMM31_MASK	16
	#define BLSB_TSI_PFX_1_PMM31_RESERVED_15	15
	#define BLSB_TSI_PFX_1_PMM31_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_1_PMM31 */
	#define BWID_TSI_PFX_1_PMM31_ENABLE	1
	#define BWID_TSI_PFX_1_PMM31_MASK	15
	#define BWID_TSI_PFX_1_PMM31_RESERVED_15	1
	#define BWID_TSI_PFX_1_PMM31_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_1_PMM31 */
	#define BMSK_TSI_PFX_1_PMM31_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PMM31_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_1_PMM31_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_1_PMM31_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_1_PMM31 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PMM31_ENABLE	 0x807c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PMM31_MASK	 0x807c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_1_PMM31_RESERVED_15	 0x807c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_1_PMM31_EXACTVALUE	 0x807c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_1_CFG	0x8100 /* Prefilter Config register */ 
	#define BITFIELD_TSI_PFX_1_CFG	 0x8100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_CFG */
	#define BLSB_TSI_PFX_1_CFG_P_SN	31
	#define BLSB_TSI_PFX_1_CFG_RESERVED_30	30
	#define BLSB_TSI_PFX_1_CFG_EIS	28
	#define BLSB_TSI_PFX_1_CFG_CP	27
	#define BLSB_TSI_PFX_1_CFG_DP	26
	#define BLSB_TSI_PFX_1_CFG_EP	25
	#define BLSB_TSI_PFX_1_CFG_SP	24
	#define BLSB_TSI_PFX_1_CFG_RESERVED_23_15	15
	#define BLSB_TSI_PFX_1_CFG_OCHDR_RM	14
	#define BLSB_TSI_PFX_1_CFG_OC_CRC_MSK	13
	#define BLSB_TSI_PFX_1_CFG_OCEN	12
	#define BLSB_TSI_PFX_1_CFG_CC	10
	#define BLSB_TSI_PFX_1_CFG_TSHDR_FMT	9
	#define BLSB_TSI_PFX_1_CFG_TSHDR_EN	8
	#define BLSB_TSI_PFX_1_CFG_PGT	7
	#define BLSB_TSI_PFX_1_CFG_PLT	6
	#define BLSB_TSI_PFX_1_CFG_DAV_MSK	5
	#define BLSB_TSI_PFX_1_CFG_ERR_MSK	4
	#define BLSB_TSI_PFX_1_CFG_ENDIAN	3
	#define BLSB_TSI_PFX_1_CFG_MODE	1
	#define BLSB_TSI_PFX_1_CFG_EN	0
	/* Register Bit Widths for TSI_PFX_1_CFG */
	#define BWID_TSI_PFX_1_CFG_P_SN	1
	#define BWID_TSI_PFX_1_CFG_RESERVED_30	1
	#define BWID_TSI_PFX_1_CFG_EIS	2
	#define BWID_TSI_PFX_1_CFG_CP	1
	#define BWID_TSI_PFX_1_CFG_DP	1
	#define BWID_TSI_PFX_1_CFG_EP	1
	#define BWID_TSI_PFX_1_CFG_SP	1
	#define BWID_TSI_PFX_1_CFG_RESERVED_23_15	9
	#define BWID_TSI_PFX_1_CFG_OCHDR_RM	1
	#define BWID_TSI_PFX_1_CFG_OC_CRC_MSK	1
	#define BWID_TSI_PFX_1_CFG_OCEN	1
	#define BWID_TSI_PFX_1_CFG_CC	2
	#define BWID_TSI_PFX_1_CFG_TSHDR_FMT	1
	#define BWID_TSI_PFX_1_CFG_TSHDR_EN	1
	#define BWID_TSI_PFX_1_CFG_PGT	1
	#define BWID_TSI_PFX_1_CFG_PLT	1
	#define BWID_TSI_PFX_1_CFG_DAV_MSK	1
	#define BWID_TSI_PFX_1_CFG_ERR_MSK	1
	#define BWID_TSI_PFX_1_CFG_ENDIAN	1
	#define BWID_TSI_PFX_1_CFG_MODE	2
	#define BWID_TSI_PFX_1_CFG_EN	1
	/* Register Bit MASKS for TSI_PFX_1_CFG */
	#define BMSK_TSI_PFX_1_CFG_P_SN	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_CFG_RESERVED_30	(1<<30) /* == 0x40000000:  */
	#define BMSK_TSI_PFX_1_CFG_EIS	0x30000000 /*  */
	#define BMSK_TSI_PFX_1_CFG_CP	(1<<27) /* == 0x08000000:  */
	#define BMSK_TSI_PFX_1_CFG_DP	(1<<26) /* == 0x04000000:  */
	#define BMSK_TSI_PFX_1_CFG_EP	(1<<25) /* == 0x02000000:  */
	#define BMSK_TSI_PFX_1_CFG_SP	(1<<24) /* == 0x01000000:  */
	#define BMSK_TSI_PFX_1_CFG_RESERVED_23_15	0x00ff8000 /*  */
	#define BMSK_TSI_PFX_1_CFG_OCHDR_RM	(1<<14) /* == 0x00004000:  */
	#define BMSK_TSI_PFX_1_CFG_OC_CRC_MSK	(1<<13) /* == 0x00002000:  */
	#define BMSK_TSI_PFX_1_CFG_OCEN	(1<<12) /* == 0x00001000:  */
	#define BMSK_TSI_PFX_1_CFG_CC	0x00000c00 /*  */
	#define BMSK_TSI_PFX_1_CFG_TSHDR_FMT	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_1_CFG_TSHDR_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_1_CFG_PGT	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_1_CFG_PLT	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_1_CFG_DAV_MSK	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_1_CFG_ERR_MSK	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_1_CFG_ENDIAN	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_1_CFG_MODE	0x00000006 /*  */
	#define BMSK_TSI_PFX_1_CFG_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_1_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_CFG_P_SN	 0x8100, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_CFG_RESERVED_30	 0x8100, 30, 1, 0x40000000
	#define BITFIELD_TSI_PFX_1_CFG_EIS	 0x8100, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_1_CFG_CP	 0x8100, 27, 1, 0x08000000
	#define BITFIELD_TSI_PFX_1_CFG_DP	 0x8100, 26, 1, 0x04000000
	#define BITFIELD_TSI_PFX_1_CFG_EP	 0x8100, 25, 1, 0x02000000
	#define BITFIELD_TSI_PFX_1_CFG_SP	 0x8100, 24, 1, 0x01000000
	#define BITFIELD_TSI_PFX_1_CFG_RESERVED_23_15	 0x8100, 15, 9, 0x00ff8000
	#define BITFIELD_TSI_PFX_1_CFG_OCHDR_RM	 0x8100, 14, 1, 0x00004000
	#define BITFIELD_TSI_PFX_1_CFG_OC_CRC_MSK	 0x8100, 13, 1, 0x00002000
	#define BITFIELD_TSI_PFX_1_CFG_OCEN	 0x8100, 12, 1, 0x00001000
	#define BITFIELD_TSI_PFX_1_CFG_CC	 0x8100, 10, 2, 0x00000c00
	#define BITFIELD_TSI_PFX_1_CFG_TSHDR_FMT	 0x8100, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_1_CFG_TSHDR_EN	 0x8100, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_1_CFG_PGT	 0x8100, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_1_CFG_PLT	 0x8100, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_1_CFG_DAV_MSK	 0x8100, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_1_CFG_ERR_MSK	 0x8100, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_1_CFG_ENDIAN	 0x8100, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_1_CFG_MODE	 0x8100, 1, 2, 0x00000006
	#define BITFIELD_TSI_PFX_1_CFG_EN	 0x8100, 0, 1, 0x00000001
#define ROFF_TSI_PFX_1_STATUS	0x8104 /* Prefilter status register */ 
	#define BITFIELD_TSI_PFX_1_STATUS	 0x8104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_STATUS */
	#define BLSB_TSI_PFX_1_STATUS_RESERVED_31_12	12
	#define BLSB_TSI_PFX_1_STATUS_NIM_ERR	11
	#define BLSB_TSI_PFX_1_STATUS_DAV_LOW	10
	#define BLSB_TSI_PFX_1_STATUS_OCF	9
	#define BLSB_TSI_PFX_1_STATUS_CRC	8
	#define BLSB_TSI_PFX_1_STATUS_DIS	7
	#define BLSB_TSI_PFX_1_STATUS_DET	6
	#define BLSB_TSI_PFX_1_STATUS_PPF	5
	#define BLSB_TSI_PFX_1_STATUS_WDT	4
	#define BLSB_TSI_PFX_1_STATUS_FE	3
	#define BLSB_TSI_PFX_1_STATUS_FF	2
	#define BLSB_TSI_PFX_1_STATUS_PLT	1
	#define BLSB_TSI_PFX_1_STATUS_PGT	0
	/* Register Bit Widths for TSI_PFX_1_STATUS */
	#define BWID_TSI_PFX_1_STATUS_RESERVED_31_12	20
	#define BWID_TSI_PFX_1_STATUS_NIM_ERR	1
	#define BWID_TSI_PFX_1_STATUS_DAV_LOW	1
	#define BWID_TSI_PFX_1_STATUS_OCF	1
	#define BWID_TSI_PFX_1_STATUS_CRC	1
	#define BWID_TSI_PFX_1_STATUS_DIS	1
	#define BWID_TSI_PFX_1_STATUS_DET	1
	#define BWID_TSI_PFX_1_STATUS_PPF	1
	#define BWID_TSI_PFX_1_STATUS_WDT	1
	#define BWID_TSI_PFX_1_STATUS_FE	1
	#define BWID_TSI_PFX_1_STATUS_FF	1
	#define BWID_TSI_PFX_1_STATUS_PLT	1
	#define BWID_TSI_PFX_1_STATUS_PGT	1
	/* Register Bit MASKS for TSI_PFX_1_STATUS */
	#define BMSK_TSI_PFX_1_STATUS_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_1_STATUS_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_1_STATUS_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_1_STATUS_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_1_STATUS_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_1_STATUS_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_1_STATUS_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_1_STATUS_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_1_STATUS_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_1_STATUS_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_1_STATUS_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_1_STATUS_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_1_STATUS_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_1_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_STATUS_RESERVED_31_12	 0x8104, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_1_STATUS_NIM_ERR	 0x8104, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_1_STATUS_DAV_LOW	 0x8104, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_1_STATUS_OCF	 0x8104, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_1_STATUS_CRC	 0x8104, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_1_STATUS_DIS	 0x8104, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_1_STATUS_DET	 0x8104, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_1_STATUS_PPF	 0x8104, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_1_STATUS_WDT	 0x8104, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_1_STATUS_FE	 0x8104, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_1_STATUS_FF	 0x8104, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_1_STATUS_PLT	 0x8104, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_1_STATUS_PGT	 0x8104, 0, 1, 0x00000001
#define ROFF_TSI_PFX_1_ENABLE	0x8108 /* Prefilter enable register */ 
	#define BITFIELD_TSI_PFX_1_ENABLE	 0x8108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_ENABLE */
	#define BLSB_TSI_PFX_1_ENABLE_RESERVED_31_12	12
	#define BLSB_TSI_PFX_1_ENABLE_NIM_ERR	11
	#define BLSB_TSI_PFX_1_ENABLE_DAV_LOW	10
	#define BLSB_TSI_PFX_1_ENABLE_OCF	9
	#define BLSB_TSI_PFX_1_ENABLE_CRC	8
	#define BLSB_TSI_PFX_1_ENABLE_DIS	7
	#define BLSB_TSI_PFX_1_ENABLE_DET	6
	#define BLSB_TSI_PFX_1_ENABLE_PPF	5
	#define BLSB_TSI_PFX_1_ENABLE_WDT	4
	#define BLSB_TSI_PFX_1_ENABLE_FE	3
	#define BLSB_TSI_PFX_1_ENABLE_FF	2
	#define BLSB_TSI_PFX_1_ENABLE_PLT	1
	#define BLSB_TSI_PFX_1_ENABLE_PGT	0
	/* Register Bit Widths for TSI_PFX_1_ENABLE */
	#define BWID_TSI_PFX_1_ENABLE_RESERVED_31_12	20
	#define BWID_TSI_PFX_1_ENABLE_NIM_ERR	1
	#define BWID_TSI_PFX_1_ENABLE_DAV_LOW	1
	#define BWID_TSI_PFX_1_ENABLE_OCF	1
	#define BWID_TSI_PFX_1_ENABLE_CRC	1
	#define BWID_TSI_PFX_1_ENABLE_DIS	1
	#define BWID_TSI_PFX_1_ENABLE_DET	1
	#define BWID_TSI_PFX_1_ENABLE_PPF	1
	#define BWID_TSI_PFX_1_ENABLE_WDT	1
	#define BWID_TSI_PFX_1_ENABLE_FE	1
	#define BWID_TSI_PFX_1_ENABLE_FF	1
	#define BWID_TSI_PFX_1_ENABLE_PLT	1
	#define BWID_TSI_PFX_1_ENABLE_PGT	1
	/* Register Bit MASKS for TSI_PFX_1_ENABLE */
	#define BMSK_TSI_PFX_1_ENABLE_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_1_ENABLE_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_1_ENABLE_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_1_ENABLE_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_1_ENABLE_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_1_ENABLE_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_1_ENABLE_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_1_ENABLE_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_1_ENABLE_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_1_ENABLE_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_1_ENABLE_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_1_ENABLE_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_1_ENABLE_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_1_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_ENABLE_RESERVED_31_12	 0x8108, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_1_ENABLE_NIM_ERR	 0x8108, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_1_ENABLE_DAV_LOW	 0x8108, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_1_ENABLE_OCF	 0x8108, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_1_ENABLE_CRC	 0x8108, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_1_ENABLE_DIS	 0x8108, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_1_ENABLE_DET	 0x8108, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_1_ENABLE_PPF	 0x8108, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_1_ENABLE_WDT	 0x8108, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_1_ENABLE_FE	 0x8108, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_1_ENABLE_FF	 0x8108, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_1_ENABLE_PLT	 0x8108, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_1_ENABLE_PGT	 0x8108, 0, 1, 0x00000001
#define ROFF_TSI_PFX_1_FERR_STATUS	0x810c /* Prefilter FERR status register */ 
	#define BITFIELD_TSI_PFX_1_FERR_STATUS	 0x810c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_FERR_STATUS */
	#define BLSB_TSI_PFX_1_FERR_STATUS_RESERVED_31_29	29
	#define BLSB_TSI_PFX_1_FERR_STATUS_FERR_VAL	24
	#define BLSB_TSI_PFX_1_FERR_STATUS_RESERVED_23_22	22
	#define BLSB_TSI_PFX_1_FERR_STATUS_PID	8
	#define BLSB_TSI_PFX_1_FERR_STATUS_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_1_FERR_STATUS */
	#define BWID_TSI_PFX_1_FERR_STATUS_RESERVED_31_29	3
	#define BWID_TSI_PFX_1_FERR_STATUS_FERR_VAL	5
	#define BWID_TSI_PFX_1_FERR_STATUS_RESERVED_23_22	2
	#define BWID_TSI_PFX_1_FERR_STATUS_PID	14
	#define BWID_TSI_PFX_1_FERR_STATUS_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_1_FERR_STATUS */
	#define BMSK_TSI_PFX_1_FERR_STATUS_RESERVED_31_29	0xe0000000 /*  */
	#define BMSK_TSI_PFX_1_FERR_STATUS_FERR_VAL	0x1f000000 /*  */
	#define BMSK_TSI_PFX_1_FERR_STATUS_RESERVED_23_22	0x00c00000 /*  */
	#define BMSK_TSI_PFX_1_FERR_STATUS_PID	0x003fff00 /*  */
	#define BMSK_TSI_PFX_1_FERR_STATUS_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_1_FERR_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_FERR_STATUS_RESERVED_31_29	 0x810c, 29, 3, 0xe0000000
	#define BITFIELD_TSI_PFX_1_FERR_STATUS_FERR_VAL	 0x810c, 24, 5, 0x1f000000
	#define BITFIELD_TSI_PFX_1_FERR_STATUS_RESERVED_23_22	 0x810c, 22, 2, 0x00c00000
	#define BITFIELD_TSI_PFX_1_FERR_STATUS_PID	 0x810c, 8, 14, 0x003fff00
	#define BITFIELD_TSI_PFX_1_FERR_STATUS_RESERVED_7_0	 0x810c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_1_DMA_BASE	0x8200 /* Prefilter DMA Base */ 
	#define BITFIELD_TSI_PFX_1_DMA_BASE	 0x8200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_DMA_SIZE	0x8204 /* Prefilter DMA Size */ 
	#define BITFIELD_TSI_PFX_1_DMA_SIZE	 0x8204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_DMA_WR_PTR	0x8208 /* Prefilter DMA Write Pointer */ 
	#define BITFIELD_TSI_PFX_1_DMA_WR_PTR	 0x8208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_DMA_SHDW_WR_PTR_ADDR	0x820c /* Prefilter DMA Shadow Write Pointer Address */ 
	#define BITFIELD_TSI_PFX_1_DMA_SHDW_WR_PTR_ADDR	 0x820c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_DMA_RD_PTR	0x8210 /* Prefilter DMA Read Pointer */ 
	#define BITFIELD_TSI_PFX_1_DMA_RD_PTR	 0x8210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_DMA_SHDW_WR_CTR	0x8214 /* Prefilter DMA Shadow Write Counter */ 
	#define BITFIELD_TSI_PFX_1_DMA_SHDW_WR_CTR	 0x8214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_NIM_WDT	0x8218 /* Prefilter NIM Watch Dog Timer */ 
	#define BITFIELD_TSI_PFX_1_NIM_WDT	 0x8218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_NIM_WDT */
	#define BLSB_TSI_PFX_1_NIM_WDT_ENABLE	31
	#define BLSB_TSI_PFX_1_NIM_WDT_WDT	0
	/* Register Bit Widths for TSI_PFX_1_NIM_WDT */
	#define BWID_TSI_PFX_1_NIM_WDT_ENABLE	1
	#define BWID_TSI_PFX_1_NIM_WDT_WDT	31
	/* Register Bit MASKS for TSI_PFX_1_NIM_WDT */
	#define BMSK_TSI_PFX_1_NIM_WDT_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_NIM_WDT_WDT	0x7fffffff /*  */
	/* Register BITFIELD for TSI_PFX_1_NIM_WDT - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_NIM_WDT_ENABLE	 0x8218, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_NIM_WDT_WDT	 0x8218, 0, 31, 0x7fffffff
#define ROFF_TSI_PFX_1_PCR_CFG	0x8300 /* Prefilter PCR Config */ 
	#define BITFIELD_TSI_PFX_1_PCR_CFG	 0x8300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_PCR_REMOTE_A0	0x831c /* Prefilter PCR Remote A0 */ 
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A0	 0x831c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_PCR_REMOTE_A1	0x8320 /* Prefilter PCR Remote A1 */ 
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A1	 0x8320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_PCR_REMOTE_A1 */
	#define BLSB_TSI_PFX_1_PCR_REMOTE_A1_PCRR_MSBA1	31
	#define BLSB_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_30_17	17
	#define BLSB_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LOCK	16
	#define BLSB_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_15_9	9
	#define BLSB_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LSBSA1	0
	/* Register Bit Widths for TSI_PFX_1_PCR_REMOTE_A1 */
	#define BWID_TSI_PFX_1_PCR_REMOTE_A1_PCRR_MSBA1	1
	#define BWID_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_30_17	14
	#define BWID_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LOCK	1
	#define BWID_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_15_9	7
	#define BWID_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LSBSA1	9
	/* Register Bit MASKS for TSI_PFX_1_PCR_REMOTE_A1 */
	#define BMSK_TSI_PFX_1_PCR_REMOTE_A1_PCRR_MSBA1	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_30_17	0x7ffe0000 /*  */
	#define BMSK_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LOCK	(1<<16) /* == 0x00010000:  */
	#define BMSK_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_15_9	0x0000fe00 /*  */
	#define BMSK_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LSBSA1	0x000001ff /*  */
	/* Register BITFIELD for TSI_PFX_1_PCR_REMOTE_A1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A1_PCRR_MSBA1	 0x8320, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_30_17	 0x8320, 17, 14, 0x7ffe0000
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LOCK	 0x8320, 16, 1, 0x00010000
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A1_RESERVED_15_9	 0x8320, 9, 7, 0x0000fe00
	#define BITFIELD_TSI_PFX_1_PCR_REMOTE_A1_PCRR_LSBSA1	 0x8320, 0, 9, 0x000001ff
#define ROFF_TSI_PFX_1_OC_HEADER_CFG	0x8340 /* Prefilter OC Header Config */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG	 0x8340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_OC_HEADER_CFG */
	#define BLSB_TSI_PFX_1_OC_HEADER_CFG_RESERVED_31_30	30
	#define BLSB_TSI_PFX_1_OC_HEADER_CFG_OCHS	28
	#define BLSB_TSI_PFX_1_OC_HEADER_CFG_RESERVED_27_10	10
	#define BLSB_TSI_PFX_1_OC_HEADER_CFG_OCLTS	9
	#define BLSB_TSI_PFX_1_OC_HEADER_CFG_RESERVED_8	8
	#define BLSB_TSI_PFX_1_OC_HEADER_CFG_OCLTSID	0
	/* Register Bit Widths for TSI_PFX_1_OC_HEADER_CFG */
	#define BWID_TSI_PFX_1_OC_HEADER_CFG_RESERVED_31_30	2
	#define BWID_TSI_PFX_1_OC_HEADER_CFG_OCHS	2
	#define BWID_TSI_PFX_1_OC_HEADER_CFG_RESERVED_27_10	18
	#define BWID_TSI_PFX_1_OC_HEADER_CFG_OCLTS	1
	#define BWID_TSI_PFX_1_OC_HEADER_CFG_RESERVED_8	1
	#define BWID_TSI_PFX_1_OC_HEADER_CFG_OCLTSID	8
	/* Register Bit MASKS for TSI_PFX_1_OC_HEADER_CFG */
	#define BMSK_TSI_PFX_1_OC_HEADER_CFG_RESERVED_31_30	0xc0000000 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_CFG_OCHS	0x30000000 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_CFG_RESERVED_27_10	0x0ffffc00 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_CFG_OCLTS	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_1_OC_HEADER_CFG_RESERVED_8	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_1_OC_HEADER_CFG_OCLTSID	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_1_OC_HEADER_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG_RESERVED_31_30	 0x8340, 30, 2, 0xc0000000
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG_OCHS	 0x8340, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG_RESERVED_27_10	 0x8340, 10, 18, 0x0ffffc00
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG_OCLTS	 0x8340, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG_RESERVED_8	 0x8340, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_1_OC_HEADER_CFG_OCLTSID	 0x8340, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_1_OC_HEADER_0A	0x8344 /* Prefilter OC Header-A0 */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_0A	 0x8344, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_OC_HEADER_0A */
	#define BLSB_TSI_PFX_1_OC_HEADER_0A_OCLTSID	24
	#define BLSB_TSI_PFX_1_OC_HEADER_0A_OCHOSTRES	8
	#define BLSB_TSI_PFX_1_OC_HEADER_0A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_1_OC_HEADER_0A */
	#define BWID_TSI_PFX_1_OC_HEADER_0A_OCLTSID	8
	#define BWID_TSI_PFX_1_OC_HEADER_0A_OCHOSTRES	15
	#define BWID_TSI_PFX_1_OC_HEADER_0A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_1_OC_HEADER_0A */
	#define BMSK_TSI_PFX_1_OC_HEADER_0A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_0A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_0A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_1_OC_HEADER_0A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_OC_HEADER_0A_OCLTSID	 0x8344, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_1_OC_HEADER_0A_OCHOSTRES	 0x8344, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_1_OC_HEADER_0A_RESERVED_7_0	 0x8344, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_1_OC_HEADER_0B	0x8348 /* Prefilter OC Header-B0 */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_0B	 0x8348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_OC_HEADER_1A	0x834c /* Prefilter OC Header-A1 */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_1A	 0x834c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_OC_HEADER_1A */
	#define BLSB_TSI_PFX_1_OC_HEADER_1A_OCLTSID	24
	#define BLSB_TSI_PFX_1_OC_HEADER_1A_OCHOSTRES	8
	#define BLSB_TSI_PFX_1_OC_HEADER_1A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_1_OC_HEADER_1A */
	#define BWID_TSI_PFX_1_OC_HEADER_1A_OCLTSID	8
	#define BWID_TSI_PFX_1_OC_HEADER_1A_OCHOSTRES	15
	#define BWID_TSI_PFX_1_OC_HEADER_1A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_1_OC_HEADER_1A */
	#define BMSK_TSI_PFX_1_OC_HEADER_1A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_1A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_1A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_1_OC_HEADER_1A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_OC_HEADER_1A_OCLTSID	 0x834c, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_1_OC_HEADER_1A_OCHOSTRES	 0x834c, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_1_OC_HEADER_1A_RESERVED_7_0	 0x834c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_1_OC_HEADER_1B	0x8350 /* Prefilter OC Header-B1 */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_1B	 0x8350, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_OC_HEADER_2A	0x8354 /* Prefilter OC Header-A2 */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_2A	 0x8354, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_1_OC_HEADER_2A */
	#define BLSB_TSI_PFX_1_OC_HEADER_2A_OCLTSID	24
	#define BLSB_TSI_PFX_1_OC_HEADER_2A_OCHOSTRES	8
	#define BLSB_TSI_PFX_1_OC_HEADER_2A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_1_OC_HEADER_2A */
	#define BWID_TSI_PFX_1_OC_HEADER_2A_OCLTSID	8
	#define BWID_TSI_PFX_1_OC_HEADER_2A_OCHOSTRES	15
	#define BWID_TSI_PFX_1_OC_HEADER_2A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_1_OC_HEADER_2A */
	#define BMSK_TSI_PFX_1_OC_HEADER_2A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_2A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_1_OC_HEADER_2A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_1_OC_HEADER_2A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_1_OC_HEADER_2A_OCLTSID	 0x8354, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_1_OC_HEADER_2A_OCHOSTRES	 0x8354, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_1_OC_HEADER_2A_RESERVED_7_0	 0x8354, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_1_OC_HEADER_2B	0x8358 /* Prefilter OC Header-B2 */ 
	#define BITFIELD_TSI_PFX_1_OC_HEADER_2B	 0x8358, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_OMAR_SEL	0x8360 /* Prefilter OMAR select */ 
	#define BITFIELD_TSI_PFX_1_OMAR_SEL	 0x8360, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_1_TIMESTAMP_CTR	0x8400 /* Prefilter time stamp counter */ 
	#define BITFIELD_TSI_PFX_1_TIMESTAMP_CTR	 0x8400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_PMM0	0xc000 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM0	 0xc000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM0 */
	#define BLSB_TSI_PFX_2_PMM0_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM0_MASK	16
	#define BLSB_TSI_PFX_2_PMM0_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM0_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM0 */
	#define BWID_TSI_PFX_2_PMM0_ENABLE	1
	#define BWID_TSI_PFX_2_PMM0_MASK	15
	#define BWID_TSI_PFX_2_PMM0_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM0_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM0 */
	#define BMSK_TSI_PFX_2_PMM0_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM0_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM0_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM0_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM0 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM0_ENABLE	 0xc000, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM0_MASK	 0xc000, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM0_RESERVED_15	 0xc000, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM0_EXACTVALUE	 0xc000, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM1	0xc004 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM1	 0xc004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM1 */
	#define BLSB_TSI_PFX_2_PMM1_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM1_MASK	16
	#define BLSB_TSI_PFX_2_PMM1_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM1_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM1 */
	#define BWID_TSI_PFX_2_PMM1_ENABLE	1
	#define BWID_TSI_PFX_2_PMM1_MASK	15
	#define BWID_TSI_PFX_2_PMM1_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM1_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM1 */
	#define BMSK_TSI_PFX_2_PMM1_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM1_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM1_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM1_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM1_ENABLE	 0xc004, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM1_MASK	 0xc004, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM1_RESERVED_15	 0xc004, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM1_EXACTVALUE	 0xc004, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM2	0xc008 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM2	 0xc008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM2 */
	#define BLSB_TSI_PFX_2_PMM2_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM2_MASK	16
	#define BLSB_TSI_PFX_2_PMM2_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM2_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM2 */
	#define BWID_TSI_PFX_2_PMM2_ENABLE	1
	#define BWID_TSI_PFX_2_PMM2_MASK	15
	#define BWID_TSI_PFX_2_PMM2_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM2_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM2 */
	#define BMSK_TSI_PFX_2_PMM2_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM2_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM2_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM2_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM2 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM2_ENABLE	 0xc008, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM2_MASK	 0xc008, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM2_RESERVED_15	 0xc008, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM2_EXACTVALUE	 0xc008, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM3	0xc00c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM3	 0xc00c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM3 */
	#define BLSB_TSI_PFX_2_PMM3_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM3_MASK	16
	#define BLSB_TSI_PFX_2_PMM3_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM3_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM3 */
	#define BWID_TSI_PFX_2_PMM3_ENABLE	1
	#define BWID_TSI_PFX_2_PMM3_MASK	15
	#define BWID_TSI_PFX_2_PMM3_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM3_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM3 */
	#define BMSK_TSI_PFX_2_PMM3_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM3_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM3_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM3_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM3 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM3_ENABLE	 0xc00c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM3_MASK	 0xc00c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM3_RESERVED_15	 0xc00c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM3_EXACTVALUE	 0xc00c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM4	0xc010 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM4	 0xc010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM4 */
	#define BLSB_TSI_PFX_2_PMM4_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM4_MASK	16
	#define BLSB_TSI_PFX_2_PMM4_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM4_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM4 */
	#define BWID_TSI_PFX_2_PMM4_ENABLE	1
	#define BWID_TSI_PFX_2_PMM4_MASK	15
	#define BWID_TSI_PFX_2_PMM4_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM4_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM4 */
	#define BMSK_TSI_PFX_2_PMM4_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM4_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM4_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM4_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM4 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM4_ENABLE	 0xc010, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM4_MASK	 0xc010, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM4_RESERVED_15	 0xc010, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM4_EXACTVALUE	 0xc010, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM5	0xc014 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM5	 0xc014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM5 */
	#define BLSB_TSI_PFX_2_PMM5_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM5_MASK	16
	#define BLSB_TSI_PFX_2_PMM5_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM5_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM5 */
	#define BWID_TSI_PFX_2_PMM5_ENABLE	1
	#define BWID_TSI_PFX_2_PMM5_MASK	15
	#define BWID_TSI_PFX_2_PMM5_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM5_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM5 */
	#define BMSK_TSI_PFX_2_PMM5_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM5_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM5_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM5_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM5 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM5_ENABLE	 0xc014, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM5_MASK	 0xc014, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM5_RESERVED_15	 0xc014, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM5_EXACTVALUE	 0xc014, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM6	0xc018 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM6	 0xc018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM6 */
	#define BLSB_TSI_PFX_2_PMM6_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM6_MASK	16
	#define BLSB_TSI_PFX_2_PMM6_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM6_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM6 */
	#define BWID_TSI_PFX_2_PMM6_ENABLE	1
	#define BWID_TSI_PFX_2_PMM6_MASK	15
	#define BWID_TSI_PFX_2_PMM6_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM6_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM6 */
	#define BMSK_TSI_PFX_2_PMM6_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM6_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM6_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM6_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM6 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM6_ENABLE	 0xc018, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM6_MASK	 0xc018, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM6_RESERVED_15	 0xc018, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM6_EXACTVALUE	 0xc018, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM7	0xc01c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM7	 0xc01c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM7 */
	#define BLSB_TSI_PFX_2_PMM7_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM7_MASK	16
	#define BLSB_TSI_PFX_2_PMM7_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM7_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM7 */
	#define BWID_TSI_PFX_2_PMM7_ENABLE	1
	#define BWID_TSI_PFX_2_PMM7_MASK	15
	#define BWID_TSI_PFX_2_PMM7_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM7_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM7 */
	#define BMSK_TSI_PFX_2_PMM7_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM7_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM7_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM7_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM7 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM7_ENABLE	 0xc01c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM7_MASK	 0xc01c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM7_RESERVED_15	 0xc01c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM7_EXACTVALUE	 0xc01c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM8	0xc020 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM8	 0xc020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM8 */
	#define BLSB_TSI_PFX_2_PMM8_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM8_MASK	16
	#define BLSB_TSI_PFX_2_PMM8_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM8_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM8 */
	#define BWID_TSI_PFX_2_PMM8_ENABLE	1
	#define BWID_TSI_PFX_2_PMM8_MASK	15
	#define BWID_TSI_PFX_2_PMM8_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM8_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM8 */
	#define BMSK_TSI_PFX_2_PMM8_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM8_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM8_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM8_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM8 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM8_ENABLE	 0xc020, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM8_MASK	 0xc020, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM8_RESERVED_15	 0xc020, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM8_EXACTVALUE	 0xc020, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM9	0xc024 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM9	 0xc024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM9 */
	#define BLSB_TSI_PFX_2_PMM9_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM9_MASK	16
	#define BLSB_TSI_PFX_2_PMM9_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM9_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM9 */
	#define BWID_TSI_PFX_2_PMM9_ENABLE	1
	#define BWID_TSI_PFX_2_PMM9_MASK	15
	#define BWID_TSI_PFX_2_PMM9_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM9_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM9 */
	#define BMSK_TSI_PFX_2_PMM9_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM9_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM9_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM9_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM9 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM9_ENABLE	 0xc024, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM9_MASK	 0xc024, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM9_RESERVED_15	 0xc024, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM9_EXACTVALUE	 0xc024, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM10	0xc028 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM10	 0xc028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM10 */
	#define BLSB_TSI_PFX_2_PMM10_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM10_MASK	16
	#define BLSB_TSI_PFX_2_PMM10_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM10_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM10 */
	#define BWID_TSI_PFX_2_PMM10_ENABLE	1
	#define BWID_TSI_PFX_2_PMM10_MASK	15
	#define BWID_TSI_PFX_2_PMM10_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM10_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM10 */
	#define BMSK_TSI_PFX_2_PMM10_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM10_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM10_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM10_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM10 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM10_ENABLE	 0xc028, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM10_MASK	 0xc028, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM10_RESERVED_15	 0xc028, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM10_EXACTVALUE	 0xc028, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM11	0xc02c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM11	 0xc02c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM11 */
	#define BLSB_TSI_PFX_2_PMM11_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM11_MASK	16
	#define BLSB_TSI_PFX_2_PMM11_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM11_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM11 */
	#define BWID_TSI_PFX_2_PMM11_ENABLE	1
	#define BWID_TSI_PFX_2_PMM11_MASK	15
	#define BWID_TSI_PFX_2_PMM11_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM11_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM11 */
	#define BMSK_TSI_PFX_2_PMM11_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM11_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM11_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM11_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM11 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM11_ENABLE	 0xc02c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM11_MASK	 0xc02c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM11_RESERVED_15	 0xc02c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM11_EXACTVALUE	 0xc02c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM12	0xc030 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM12	 0xc030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM12 */
	#define BLSB_TSI_PFX_2_PMM12_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM12_MASK	16
	#define BLSB_TSI_PFX_2_PMM12_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM12_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM12 */
	#define BWID_TSI_PFX_2_PMM12_ENABLE	1
	#define BWID_TSI_PFX_2_PMM12_MASK	15
	#define BWID_TSI_PFX_2_PMM12_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM12_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM12 */
	#define BMSK_TSI_PFX_2_PMM12_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM12_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM12_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM12_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM12 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM12_ENABLE	 0xc030, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM12_MASK	 0xc030, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM12_RESERVED_15	 0xc030, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM12_EXACTVALUE	 0xc030, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM13	0xc034 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM13	 0xc034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM13 */
	#define BLSB_TSI_PFX_2_PMM13_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM13_MASK	16
	#define BLSB_TSI_PFX_2_PMM13_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM13_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM13 */
	#define BWID_TSI_PFX_2_PMM13_ENABLE	1
	#define BWID_TSI_PFX_2_PMM13_MASK	15
	#define BWID_TSI_PFX_2_PMM13_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM13_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM13 */
	#define BMSK_TSI_PFX_2_PMM13_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM13_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM13_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM13_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM13 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM13_ENABLE	 0xc034, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM13_MASK	 0xc034, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM13_RESERVED_15	 0xc034, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM13_EXACTVALUE	 0xc034, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM14	0xc038 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM14	 0xc038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM14 */
	#define BLSB_TSI_PFX_2_PMM14_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM14_MASK	16
	#define BLSB_TSI_PFX_2_PMM14_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM14_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM14 */
	#define BWID_TSI_PFX_2_PMM14_ENABLE	1
	#define BWID_TSI_PFX_2_PMM14_MASK	15
	#define BWID_TSI_PFX_2_PMM14_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM14_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM14 */
	#define BMSK_TSI_PFX_2_PMM14_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM14_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM14_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM14_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM14 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM14_ENABLE	 0xc038, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM14_MASK	 0xc038, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM14_RESERVED_15	 0xc038, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM14_EXACTVALUE	 0xc038, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM15	0xc03c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM15	 0xc03c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM15 */
	#define BLSB_TSI_PFX_2_PMM15_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM15_MASK	16
	#define BLSB_TSI_PFX_2_PMM15_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM15_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM15 */
	#define BWID_TSI_PFX_2_PMM15_ENABLE	1
	#define BWID_TSI_PFX_2_PMM15_MASK	15
	#define BWID_TSI_PFX_2_PMM15_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM15_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM15 */
	#define BMSK_TSI_PFX_2_PMM15_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM15_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM15_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM15_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM15 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM15_ENABLE	 0xc03c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM15_MASK	 0xc03c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM15_RESERVED_15	 0xc03c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM15_EXACTVALUE	 0xc03c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM16	0xc040 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM16	 0xc040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM16 */
	#define BLSB_TSI_PFX_2_PMM16_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM16_MASK	16
	#define BLSB_TSI_PFX_2_PMM16_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM16_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM16 */
	#define BWID_TSI_PFX_2_PMM16_ENABLE	1
	#define BWID_TSI_PFX_2_PMM16_MASK	15
	#define BWID_TSI_PFX_2_PMM16_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM16_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM16 */
	#define BMSK_TSI_PFX_2_PMM16_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM16_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM16_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM16_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM16 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM16_ENABLE	 0xc040, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM16_MASK	 0xc040, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM16_RESERVED_15	 0xc040, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM16_EXACTVALUE	 0xc040, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM17	0xc044 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM17	 0xc044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM17 */
	#define BLSB_TSI_PFX_2_PMM17_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM17_MASK	16
	#define BLSB_TSI_PFX_2_PMM17_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM17_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM17 */
	#define BWID_TSI_PFX_2_PMM17_ENABLE	1
	#define BWID_TSI_PFX_2_PMM17_MASK	15
	#define BWID_TSI_PFX_2_PMM17_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM17_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM17 */
	#define BMSK_TSI_PFX_2_PMM17_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM17_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM17_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM17_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM17 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM17_ENABLE	 0xc044, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM17_MASK	 0xc044, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM17_RESERVED_15	 0xc044, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM17_EXACTVALUE	 0xc044, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM18	0xc048 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM18	 0xc048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM18 */
	#define BLSB_TSI_PFX_2_PMM18_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM18_MASK	16
	#define BLSB_TSI_PFX_2_PMM18_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM18_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM18 */
	#define BWID_TSI_PFX_2_PMM18_ENABLE	1
	#define BWID_TSI_PFX_2_PMM18_MASK	15
	#define BWID_TSI_PFX_2_PMM18_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM18_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM18 */
	#define BMSK_TSI_PFX_2_PMM18_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM18_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM18_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM18_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM18 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM18_ENABLE	 0xc048, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM18_MASK	 0xc048, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM18_RESERVED_15	 0xc048, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM18_EXACTVALUE	 0xc048, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM19	0xc04c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM19	 0xc04c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM19 */
	#define BLSB_TSI_PFX_2_PMM19_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM19_MASK	16
	#define BLSB_TSI_PFX_2_PMM19_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM19_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM19 */
	#define BWID_TSI_PFX_2_PMM19_ENABLE	1
	#define BWID_TSI_PFX_2_PMM19_MASK	15
	#define BWID_TSI_PFX_2_PMM19_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM19_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM19 */
	#define BMSK_TSI_PFX_2_PMM19_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM19_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM19_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM19_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM19 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM19_ENABLE	 0xc04c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM19_MASK	 0xc04c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM19_RESERVED_15	 0xc04c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM19_EXACTVALUE	 0xc04c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM20	0xc050 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM20	 0xc050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM20 */
	#define BLSB_TSI_PFX_2_PMM20_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM20_MASK	16
	#define BLSB_TSI_PFX_2_PMM20_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM20_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM20 */
	#define BWID_TSI_PFX_2_PMM20_ENABLE	1
	#define BWID_TSI_PFX_2_PMM20_MASK	15
	#define BWID_TSI_PFX_2_PMM20_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM20_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM20 */
	#define BMSK_TSI_PFX_2_PMM20_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM20_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM20_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM20_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM20 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM20_ENABLE	 0xc050, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM20_MASK	 0xc050, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM20_RESERVED_15	 0xc050, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM20_EXACTVALUE	 0xc050, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM21	0xc054 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM21	 0xc054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM21 */
	#define BLSB_TSI_PFX_2_PMM21_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM21_MASK	16
	#define BLSB_TSI_PFX_2_PMM21_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM21_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM21 */
	#define BWID_TSI_PFX_2_PMM21_ENABLE	1
	#define BWID_TSI_PFX_2_PMM21_MASK	15
	#define BWID_TSI_PFX_2_PMM21_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM21_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM21 */
	#define BMSK_TSI_PFX_2_PMM21_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM21_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM21_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM21_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM21 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM21_ENABLE	 0xc054, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM21_MASK	 0xc054, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM21_RESERVED_15	 0xc054, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM21_EXACTVALUE	 0xc054, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM22	0xc058 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM22	 0xc058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM22 */
	#define BLSB_TSI_PFX_2_PMM22_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM22_MASK	16
	#define BLSB_TSI_PFX_2_PMM22_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM22_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM22 */
	#define BWID_TSI_PFX_2_PMM22_ENABLE	1
	#define BWID_TSI_PFX_2_PMM22_MASK	15
	#define BWID_TSI_PFX_2_PMM22_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM22_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM22 */
	#define BMSK_TSI_PFX_2_PMM22_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM22_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM22_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM22_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM22 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM22_ENABLE	 0xc058, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM22_MASK	 0xc058, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM22_RESERVED_15	 0xc058, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM22_EXACTVALUE	 0xc058, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM23	0xc05c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM23	 0xc05c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM23 */
	#define BLSB_TSI_PFX_2_PMM23_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM23_MASK	16
	#define BLSB_TSI_PFX_2_PMM23_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM23_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM23 */
	#define BWID_TSI_PFX_2_PMM23_ENABLE	1
	#define BWID_TSI_PFX_2_PMM23_MASK	15
	#define BWID_TSI_PFX_2_PMM23_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM23_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM23 */
	#define BMSK_TSI_PFX_2_PMM23_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM23_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM23_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM23_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM23 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM23_ENABLE	 0xc05c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM23_MASK	 0xc05c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM23_RESERVED_15	 0xc05c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM23_EXACTVALUE	 0xc05c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM24	0xc060 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM24	 0xc060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM24 */
	#define BLSB_TSI_PFX_2_PMM24_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM24_MASK	16
	#define BLSB_TSI_PFX_2_PMM24_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM24_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM24 */
	#define BWID_TSI_PFX_2_PMM24_ENABLE	1
	#define BWID_TSI_PFX_2_PMM24_MASK	15
	#define BWID_TSI_PFX_2_PMM24_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM24_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM24 */
	#define BMSK_TSI_PFX_2_PMM24_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM24_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM24_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM24_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM24 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM24_ENABLE	 0xc060, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM24_MASK	 0xc060, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM24_RESERVED_15	 0xc060, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM24_EXACTVALUE	 0xc060, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM25	0xc064 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM25	 0xc064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM25 */
	#define BLSB_TSI_PFX_2_PMM25_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM25_MASK	16
	#define BLSB_TSI_PFX_2_PMM25_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM25_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM25 */
	#define BWID_TSI_PFX_2_PMM25_ENABLE	1
	#define BWID_TSI_PFX_2_PMM25_MASK	15
	#define BWID_TSI_PFX_2_PMM25_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM25_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM25 */
	#define BMSK_TSI_PFX_2_PMM25_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM25_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM25_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM25_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM25 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM25_ENABLE	 0xc064, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM25_MASK	 0xc064, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM25_RESERVED_15	 0xc064, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM25_EXACTVALUE	 0xc064, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM26	0xc068 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM26	 0xc068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM26 */
	#define BLSB_TSI_PFX_2_PMM26_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM26_MASK	16
	#define BLSB_TSI_PFX_2_PMM26_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM26_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM26 */
	#define BWID_TSI_PFX_2_PMM26_ENABLE	1
	#define BWID_TSI_PFX_2_PMM26_MASK	15
	#define BWID_TSI_PFX_2_PMM26_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM26_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM26 */
	#define BMSK_TSI_PFX_2_PMM26_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM26_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM26_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM26_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM26 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM26_ENABLE	 0xc068, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM26_MASK	 0xc068, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM26_RESERVED_15	 0xc068, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM26_EXACTVALUE	 0xc068, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM27	0xc06c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM27	 0xc06c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM27 */
	#define BLSB_TSI_PFX_2_PMM27_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM27_MASK	16
	#define BLSB_TSI_PFX_2_PMM27_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM27_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM27 */
	#define BWID_TSI_PFX_2_PMM27_ENABLE	1
	#define BWID_TSI_PFX_2_PMM27_MASK	15
	#define BWID_TSI_PFX_2_PMM27_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM27_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM27 */
	#define BMSK_TSI_PFX_2_PMM27_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM27_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM27_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM27_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM27 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM27_ENABLE	 0xc06c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM27_MASK	 0xc06c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM27_RESERVED_15	 0xc06c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM27_EXACTVALUE	 0xc06c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM28	0xc070 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM28	 0xc070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM28 */
	#define BLSB_TSI_PFX_2_PMM28_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM28_MASK	16
	#define BLSB_TSI_PFX_2_PMM28_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM28_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM28 */
	#define BWID_TSI_PFX_2_PMM28_ENABLE	1
	#define BWID_TSI_PFX_2_PMM28_MASK	15
	#define BWID_TSI_PFX_2_PMM28_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM28_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM28 */
	#define BMSK_TSI_PFX_2_PMM28_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM28_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM28_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM28_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM28 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM28_ENABLE	 0xc070, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM28_MASK	 0xc070, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM28_RESERVED_15	 0xc070, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM28_EXACTVALUE	 0xc070, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM29	0xc074 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM29	 0xc074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM29 */
	#define BLSB_TSI_PFX_2_PMM29_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM29_MASK	16
	#define BLSB_TSI_PFX_2_PMM29_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM29_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM29 */
	#define BWID_TSI_PFX_2_PMM29_ENABLE	1
	#define BWID_TSI_PFX_2_PMM29_MASK	15
	#define BWID_TSI_PFX_2_PMM29_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM29_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM29 */
	#define BMSK_TSI_PFX_2_PMM29_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM29_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM29_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM29_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM29 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM29_ENABLE	 0xc074, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM29_MASK	 0xc074, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM29_RESERVED_15	 0xc074, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM29_EXACTVALUE	 0xc074, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM30	0xc078 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM30	 0xc078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM30 */
	#define BLSB_TSI_PFX_2_PMM30_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM30_MASK	16
	#define BLSB_TSI_PFX_2_PMM30_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM30_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM30 */
	#define BWID_TSI_PFX_2_PMM30_ENABLE	1
	#define BWID_TSI_PFX_2_PMM30_MASK	15
	#define BWID_TSI_PFX_2_PMM30_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM30_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM30 */
	#define BMSK_TSI_PFX_2_PMM30_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM30_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM30_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM30_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM30 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM30_ENABLE	 0xc078, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM30_MASK	 0xc078, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM30_RESERVED_15	 0xc078, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM30_EXACTVALUE	 0xc078, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_PMM31	0xc07c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_2_PMM31	 0xc07c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PMM31 */
	#define BLSB_TSI_PFX_2_PMM31_ENABLE	31
	#define BLSB_TSI_PFX_2_PMM31_MASK	16
	#define BLSB_TSI_PFX_2_PMM31_RESERVED_15	15
	#define BLSB_TSI_PFX_2_PMM31_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_2_PMM31 */
	#define BWID_TSI_PFX_2_PMM31_ENABLE	1
	#define BWID_TSI_PFX_2_PMM31_MASK	15
	#define BWID_TSI_PFX_2_PMM31_RESERVED_15	1
	#define BWID_TSI_PFX_2_PMM31_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_2_PMM31 */
	#define BMSK_TSI_PFX_2_PMM31_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PMM31_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_2_PMM31_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_2_PMM31_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_2_PMM31 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PMM31_ENABLE	 0xc07c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PMM31_MASK	 0xc07c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_2_PMM31_RESERVED_15	 0xc07c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_2_PMM31_EXACTVALUE	 0xc07c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_2_CFG	0xc100 /* Prefilter Config register */ 
	#define BITFIELD_TSI_PFX_2_CFG	 0xc100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_CFG */
	#define BLSB_TSI_PFX_2_CFG_P_SN	31
	#define BLSB_TSI_PFX_2_CFG_RESERVED_30	30
	#define BLSB_TSI_PFX_2_CFG_EIS	28
	#define BLSB_TSI_PFX_2_CFG_CP	27
	#define BLSB_TSI_PFX_2_CFG_DP	26
	#define BLSB_TSI_PFX_2_CFG_EP	25
	#define BLSB_TSI_PFX_2_CFG_SP	24
	#define BLSB_TSI_PFX_2_CFG_RESERVED_23_15	15
	#define BLSB_TSI_PFX_2_CFG_OCHDR_RM	14
	#define BLSB_TSI_PFX_2_CFG_OC_CRC_MSK	13
	#define BLSB_TSI_PFX_2_CFG_OCEN	12
	#define BLSB_TSI_PFX_2_CFG_CC	10
	#define BLSB_TSI_PFX_2_CFG_TSHDR_FMT	9
	#define BLSB_TSI_PFX_2_CFG_TSHDR_EN	8
	#define BLSB_TSI_PFX_2_CFG_PGT	7
	#define BLSB_TSI_PFX_2_CFG_PLT	6
	#define BLSB_TSI_PFX_2_CFG_DAV_MSK	5
	#define BLSB_TSI_PFX_2_CFG_ERR_MSK	4
	#define BLSB_TSI_PFX_2_CFG_ENDIAN	3
	#define BLSB_TSI_PFX_2_CFG_MODE	1
	#define BLSB_TSI_PFX_2_CFG_EN	0
	/* Register Bit Widths for TSI_PFX_2_CFG */
	#define BWID_TSI_PFX_2_CFG_P_SN	1
	#define BWID_TSI_PFX_2_CFG_RESERVED_30	1
	#define BWID_TSI_PFX_2_CFG_EIS	2
	#define BWID_TSI_PFX_2_CFG_CP	1
	#define BWID_TSI_PFX_2_CFG_DP	1
	#define BWID_TSI_PFX_2_CFG_EP	1
	#define BWID_TSI_PFX_2_CFG_SP	1
	#define BWID_TSI_PFX_2_CFG_RESERVED_23_15	9
	#define BWID_TSI_PFX_2_CFG_OCHDR_RM	1
	#define BWID_TSI_PFX_2_CFG_OC_CRC_MSK	1
	#define BWID_TSI_PFX_2_CFG_OCEN	1
	#define BWID_TSI_PFX_2_CFG_CC	2
	#define BWID_TSI_PFX_2_CFG_TSHDR_FMT	1
	#define BWID_TSI_PFX_2_CFG_TSHDR_EN	1
	#define BWID_TSI_PFX_2_CFG_PGT	1
	#define BWID_TSI_PFX_2_CFG_PLT	1
	#define BWID_TSI_PFX_2_CFG_DAV_MSK	1
	#define BWID_TSI_PFX_2_CFG_ERR_MSK	1
	#define BWID_TSI_PFX_2_CFG_ENDIAN	1
	#define BWID_TSI_PFX_2_CFG_MODE	2
	#define BWID_TSI_PFX_2_CFG_EN	1
	/* Register Bit MASKS for TSI_PFX_2_CFG */
	#define BMSK_TSI_PFX_2_CFG_P_SN	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_CFG_RESERVED_30	(1<<30) /* == 0x40000000:  */
	#define BMSK_TSI_PFX_2_CFG_EIS	0x30000000 /*  */
	#define BMSK_TSI_PFX_2_CFG_CP	(1<<27) /* == 0x08000000:  */
	#define BMSK_TSI_PFX_2_CFG_DP	(1<<26) /* == 0x04000000:  */
	#define BMSK_TSI_PFX_2_CFG_EP	(1<<25) /* == 0x02000000:  */
	#define BMSK_TSI_PFX_2_CFG_SP	(1<<24) /* == 0x01000000:  */
	#define BMSK_TSI_PFX_2_CFG_RESERVED_23_15	0x00ff8000 /*  */
	#define BMSK_TSI_PFX_2_CFG_OCHDR_RM	(1<<14) /* == 0x00004000:  */
	#define BMSK_TSI_PFX_2_CFG_OC_CRC_MSK	(1<<13) /* == 0x00002000:  */
	#define BMSK_TSI_PFX_2_CFG_OCEN	(1<<12) /* == 0x00001000:  */
	#define BMSK_TSI_PFX_2_CFG_CC	0x00000c00 /*  */
	#define BMSK_TSI_PFX_2_CFG_TSHDR_FMT	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_2_CFG_TSHDR_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_2_CFG_PGT	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_2_CFG_PLT	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_2_CFG_DAV_MSK	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_2_CFG_ERR_MSK	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_2_CFG_ENDIAN	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_2_CFG_MODE	0x00000006 /*  */
	#define BMSK_TSI_PFX_2_CFG_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_2_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_CFG_P_SN	 0xc100, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_CFG_RESERVED_30	 0xc100, 30, 1, 0x40000000
	#define BITFIELD_TSI_PFX_2_CFG_EIS	 0xc100, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_2_CFG_CP	 0xc100, 27, 1, 0x08000000
	#define BITFIELD_TSI_PFX_2_CFG_DP	 0xc100, 26, 1, 0x04000000
	#define BITFIELD_TSI_PFX_2_CFG_EP	 0xc100, 25, 1, 0x02000000
	#define BITFIELD_TSI_PFX_2_CFG_SP	 0xc100, 24, 1, 0x01000000
	#define BITFIELD_TSI_PFX_2_CFG_RESERVED_23_15	 0xc100, 15, 9, 0x00ff8000
	#define BITFIELD_TSI_PFX_2_CFG_OCHDR_RM	 0xc100, 14, 1, 0x00004000
	#define BITFIELD_TSI_PFX_2_CFG_OC_CRC_MSK	 0xc100, 13, 1, 0x00002000
	#define BITFIELD_TSI_PFX_2_CFG_OCEN	 0xc100, 12, 1, 0x00001000
	#define BITFIELD_TSI_PFX_2_CFG_CC	 0xc100, 10, 2, 0x00000c00
	#define BITFIELD_TSI_PFX_2_CFG_TSHDR_FMT	 0xc100, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_2_CFG_TSHDR_EN	 0xc100, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_2_CFG_PGT	 0xc100, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_2_CFG_PLT	 0xc100, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_2_CFG_DAV_MSK	 0xc100, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_2_CFG_ERR_MSK	 0xc100, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_2_CFG_ENDIAN	 0xc100, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_2_CFG_MODE	 0xc100, 1, 2, 0x00000006
	#define BITFIELD_TSI_PFX_2_CFG_EN	 0xc100, 0, 1, 0x00000001
#define ROFF_TSI_PFX_2_STATUS	0xc104 /* Prefilter status register */ 
	#define BITFIELD_TSI_PFX_2_STATUS	 0xc104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_STATUS */
	#define BLSB_TSI_PFX_2_STATUS_RESERVED_31_12	12
	#define BLSB_TSI_PFX_2_STATUS_NIM_ERR	11
	#define BLSB_TSI_PFX_2_STATUS_DAV_LOW	10
	#define BLSB_TSI_PFX_2_STATUS_OCF	9
	#define BLSB_TSI_PFX_2_STATUS_CRC	8
	#define BLSB_TSI_PFX_2_STATUS_DIS	7
	#define BLSB_TSI_PFX_2_STATUS_DET	6
	#define BLSB_TSI_PFX_2_STATUS_PPF	5
	#define BLSB_TSI_PFX_2_STATUS_WDT	4
	#define BLSB_TSI_PFX_2_STATUS_FE	3
	#define BLSB_TSI_PFX_2_STATUS_FF	2
	#define BLSB_TSI_PFX_2_STATUS_PLT	1
	#define BLSB_TSI_PFX_2_STATUS_PGT	0
	/* Register Bit Widths for TSI_PFX_2_STATUS */
	#define BWID_TSI_PFX_2_STATUS_RESERVED_31_12	20
	#define BWID_TSI_PFX_2_STATUS_NIM_ERR	1
	#define BWID_TSI_PFX_2_STATUS_DAV_LOW	1
	#define BWID_TSI_PFX_2_STATUS_OCF	1
	#define BWID_TSI_PFX_2_STATUS_CRC	1
	#define BWID_TSI_PFX_2_STATUS_DIS	1
	#define BWID_TSI_PFX_2_STATUS_DET	1
	#define BWID_TSI_PFX_2_STATUS_PPF	1
	#define BWID_TSI_PFX_2_STATUS_WDT	1
	#define BWID_TSI_PFX_2_STATUS_FE	1
	#define BWID_TSI_PFX_2_STATUS_FF	1
	#define BWID_TSI_PFX_2_STATUS_PLT	1
	#define BWID_TSI_PFX_2_STATUS_PGT	1
	/* Register Bit MASKS for TSI_PFX_2_STATUS */
	#define BMSK_TSI_PFX_2_STATUS_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_2_STATUS_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_2_STATUS_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_2_STATUS_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_2_STATUS_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_2_STATUS_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_2_STATUS_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_2_STATUS_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_2_STATUS_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_2_STATUS_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_2_STATUS_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_2_STATUS_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_2_STATUS_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_2_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_STATUS_RESERVED_31_12	 0xc104, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_2_STATUS_NIM_ERR	 0xc104, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_2_STATUS_DAV_LOW	 0xc104, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_2_STATUS_OCF	 0xc104, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_2_STATUS_CRC	 0xc104, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_2_STATUS_DIS	 0xc104, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_2_STATUS_DET	 0xc104, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_2_STATUS_PPF	 0xc104, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_2_STATUS_WDT	 0xc104, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_2_STATUS_FE	 0xc104, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_2_STATUS_FF	 0xc104, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_2_STATUS_PLT	 0xc104, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_2_STATUS_PGT	 0xc104, 0, 1, 0x00000001
#define ROFF_TSI_PFX_2_ENABLE	0xc108 /* Prefilter enable register */ 
	#define BITFIELD_TSI_PFX_2_ENABLE	 0xc108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_ENABLE */
	#define BLSB_TSI_PFX_2_ENABLE_RESERVED_31_12	12
	#define BLSB_TSI_PFX_2_ENABLE_NIM_ERR	11
	#define BLSB_TSI_PFX_2_ENABLE_DAV_LOW	10
	#define BLSB_TSI_PFX_2_ENABLE_OCF	9
	#define BLSB_TSI_PFX_2_ENABLE_CRC	8
	#define BLSB_TSI_PFX_2_ENABLE_DIS	7
	#define BLSB_TSI_PFX_2_ENABLE_DET	6
	#define BLSB_TSI_PFX_2_ENABLE_PPF	5
	#define BLSB_TSI_PFX_2_ENABLE_WDT	4
	#define BLSB_TSI_PFX_2_ENABLE_FE	3
	#define BLSB_TSI_PFX_2_ENABLE_FF	2
	#define BLSB_TSI_PFX_2_ENABLE_PLT	1
	#define BLSB_TSI_PFX_2_ENABLE_PGT	0
	/* Register Bit Widths for TSI_PFX_2_ENABLE */
	#define BWID_TSI_PFX_2_ENABLE_RESERVED_31_12	20
	#define BWID_TSI_PFX_2_ENABLE_NIM_ERR	1
	#define BWID_TSI_PFX_2_ENABLE_DAV_LOW	1
	#define BWID_TSI_PFX_2_ENABLE_OCF	1
	#define BWID_TSI_PFX_2_ENABLE_CRC	1
	#define BWID_TSI_PFX_2_ENABLE_DIS	1
	#define BWID_TSI_PFX_2_ENABLE_DET	1
	#define BWID_TSI_PFX_2_ENABLE_PPF	1
	#define BWID_TSI_PFX_2_ENABLE_WDT	1
	#define BWID_TSI_PFX_2_ENABLE_FE	1
	#define BWID_TSI_PFX_2_ENABLE_FF	1
	#define BWID_TSI_PFX_2_ENABLE_PLT	1
	#define BWID_TSI_PFX_2_ENABLE_PGT	1
	/* Register Bit MASKS for TSI_PFX_2_ENABLE */
	#define BMSK_TSI_PFX_2_ENABLE_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_2_ENABLE_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_2_ENABLE_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_2_ENABLE_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_2_ENABLE_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_2_ENABLE_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_2_ENABLE_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_2_ENABLE_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_2_ENABLE_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_2_ENABLE_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_2_ENABLE_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_2_ENABLE_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_2_ENABLE_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_2_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_ENABLE_RESERVED_31_12	 0xc108, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_2_ENABLE_NIM_ERR	 0xc108, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_2_ENABLE_DAV_LOW	 0xc108, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_2_ENABLE_OCF	 0xc108, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_2_ENABLE_CRC	 0xc108, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_2_ENABLE_DIS	 0xc108, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_2_ENABLE_DET	 0xc108, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_2_ENABLE_PPF	 0xc108, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_2_ENABLE_WDT	 0xc108, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_2_ENABLE_FE	 0xc108, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_2_ENABLE_FF	 0xc108, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_2_ENABLE_PLT	 0xc108, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_2_ENABLE_PGT	 0xc108, 0, 1, 0x00000001
#define ROFF_TSI_PFX_2_FERR_STATUS	0xc10c /* Prefilter FERR status register */ 
	#define BITFIELD_TSI_PFX_2_FERR_STATUS	 0xc10c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_FERR_STATUS */
	#define BLSB_TSI_PFX_2_FERR_STATUS_RESERVED_31_29	29
	#define BLSB_TSI_PFX_2_FERR_STATUS_FERR_VAL	24
	#define BLSB_TSI_PFX_2_FERR_STATUS_RESERVED_23_22	22
	#define BLSB_TSI_PFX_2_FERR_STATUS_PID	8
	#define BLSB_TSI_PFX_2_FERR_STATUS_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_2_FERR_STATUS */
	#define BWID_TSI_PFX_2_FERR_STATUS_RESERVED_31_29	3
	#define BWID_TSI_PFX_2_FERR_STATUS_FERR_VAL	5
	#define BWID_TSI_PFX_2_FERR_STATUS_RESERVED_23_22	2
	#define BWID_TSI_PFX_2_FERR_STATUS_PID	14
	#define BWID_TSI_PFX_2_FERR_STATUS_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_2_FERR_STATUS */
	#define BMSK_TSI_PFX_2_FERR_STATUS_RESERVED_31_29	0xe0000000 /*  */
	#define BMSK_TSI_PFX_2_FERR_STATUS_FERR_VAL	0x1f000000 /*  */
	#define BMSK_TSI_PFX_2_FERR_STATUS_RESERVED_23_22	0x00c00000 /*  */
	#define BMSK_TSI_PFX_2_FERR_STATUS_PID	0x003fff00 /*  */
	#define BMSK_TSI_PFX_2_FERR_STATUS_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_2_FERR_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_FERR_STATUS_RESERVED_31_29	 0xc10c, 29, 3, 0xe0000000
	#define BITFIELD_TSI_PFX_2_FERR_STATUS_FERR_VAL	 0xc10c, 24, 5, 0x1f000000
	#define BITFIELD_TSI_PFX_2_FERR_STATUS_RESERVED_23_22	 0xc10c, 22, 2, 0x00c00000
	#define BITFIELD_TSI_PFX_2_FERR_STATUS_PID	 0xc10c, 8, 14, 0x003fff00
	#define BITFIELD_TSI_PFX_2_FERR_STATUS_RESERVED_7_0	 0xc10c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_2_DMA_BASE	0xc200 /* Prefilter DMA Base */ 
	#define BITFIELD_TSI_PFX_2_DMA_BASE	 0xc200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_DMA_SIZE	0xc204 /* Prefilter DMA Size */ 
	#define BITFIELD_TSI_PFX_2_DMA_SIZE	 0xc204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_DMA_WR_PTR	0xc208 /* Prefilter DMA Write Pointer */ 
	#define BITFIELD_TSI_PFX_2_DMA_WR_PTR	 0xc208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_DMA_SHDW_WR_PTR_ADDR	0xc20c /* Prefilter DMA Shadow Write Pointer Address */ 
	#define BITFIELD_TSI_PFX_2_DMA_SHDW_WR_PTR_ADDR	 0xc20c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_DMA_RD_PTR	0xc210 /* Prefilter DMA Read Pointer */ 
	#define BITFIELD_TSI_PFX_2_DMA_RD_PTR	 0xc210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_DMA_SHDW_WR_CTR	0xc214 /* Prefilter DMA Shadow Write Counter */ 
	#define BITFIELD_TSI_PFX_2_DMA_SHDW_WR_CTR	 0xc214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_NIM_WDT	0xc218 /* Prefilter NIM Watch Dog Timer */ 
	#define BITFIELD_TSI_PFX_2_NIM_WDT	 0xc218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_NIM_WDT */
	#define BLSB_TSI_PFX_2_NIM_WDT_ENABLE	31
	#define BLSB_TSI_PFX_2_NIM_WDT_WDT	0
	/* Register Bit Widths for TSI_PFX_2_NIM_WDT */
	#define BWID_TSI_PFX_2_NIM_WDT_ENABLE	1
	#define BWID_TSI_PFX_2_NIM_WDT_WDT	31
	/* Register Bit MASKS for TSI_PFX_2_NIM_WDT */
	#define BMSK_TSI_PFX_2_NIM_WDT_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_NIM_WDT_WDT	0x7fffffff /*  */
	/* Register BITFIELD for TSI_PFX_2_NIM_WDT - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_NIM_WDT_ENABLE	 0xc218, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_NIM_WDT_WDT	 0xc218, 0, 31, 0x7fffffff
#define ROFF_TSI_PFX_2_PCR_CFG	0xc300 /* Prefilter PCR Config */ 
	#define BITFIELD_TSI_PFX_2_PCR_CFG	 0xc300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_PCR_REMOTE_A0	0xc31c /* Prefilter PCR Remote A0 */ 
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A0	 0xc31c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_PCR_REMOTE_A1	0xc320 /* Prefilter PCR Remote A1 */ 
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A1	 0xc320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_PCR_REMOTE_A1 */
	#define BLSB_TSI_PFX_2_PCR_REMOTE_A1_PCRR_MSBA1	31
	#define BLSB_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_30_17	17
	#define BLSB_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LOCK	16
	#define BLSB_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_15_9	9
	#define BLSB_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LSBSA1	0
	/* Register Bit Widths for TSI_PFX_2_PCR_REMOTE_A1 */
	#define BWID_TSI_PFX_2_PCR_REMOTE_A1_PCRR_MSBA1	1
	#define BWID_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_30_17	14
	#define BWID_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LOCK	1
	#define BWID_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_15_9	7
	#define BWID_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LSBSA1	9
	/* Register Bit MASKS for TSI_PFX_2_PCR_REMOTE_A1 */
	#define BMSK_TSI_PFX_2_PCR_REMOTE_A1_PCRR_MSBA1	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_30_17	0x7ffe0000 /*  */
	#define BMSK_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LOCK	(1<<16) /* == 0x00010000:  */
	#define BMSK_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_15_9	0x0000fe00 /*  */
	#define BMSK_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LSBSA1	0x000001ff /*  */
	/* Register BITFIELD for TSI_PFX_2_PCR_REMOTE_A1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A1_PCRR_MSBA1	 0xc320, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_30_17	 0xc320, 17, 14, 0x7ffe0000
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LOCK	 0xc320, 16, 1, 0x00010000
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A1_RESERVED_15_9	 0xc320, 9, 7, 0x0000fe00
	#define BITFIELD_TSI_PFX_2_PCR_REMOTE_A1_PCRR_LSBSA1	 0xc320, 0, 9, 0x000001ff
#define ROFF_TSI_PFX_2_OC_HEADER_CFG	0xc340 /* Prefilter OC Header Config */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG	 0xc340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_OC_HEADER_CFG */
	#define BLSB_TSI_PFX_2_OC_HEADER_CFG_RESERVED_31_30	30
	#define BLSB_TSI_PFX_2_OC_HEADER_CFG_OCHS	28
	#define BLSB_TSI_PFX_2_OC_HEADER_CFG_RESERVED_27_10	10
	#define BLSB_TSI_PFX_2_OC_HEADER_CFG_OCLTS	9
	#define BLSB_TSI_PFX_2_OC_HEADER_CFG_RESERVED_8	8
	#define BLSB_TSI_PFX_2_OC_HEADER_CFG_OCLTSID	0
	/* Register Bit Widths for TSI_PFX_2_OC_HEADER_CFG */
	#define BWID_TSI_PFX_2_OC_HEADER_CFG_RESERVED_31_30	2
	#define BWID_TSI_PFX_2_OC_HEADER_CFG_OCHS	2
	#define BWID_TSI_PFX_2_OC_HEADER_CFG_RESERVED_27_10	18
	#define BWID_TSI_PFX_2_OC_HEADER_CFG_OCLTS	1
	#define BWID_TSI_PFX_2_OC_HEADER_CFG_RESERVED_8	1
	#define BWID_TSI_PFX_2_OC_HEADER_CFG_OCLTSID	8
	/* Register Bit MASKS for TSI_PFX_2_OC_HEADER_CFG */
	#define BMSK_TSI_PFX_2_OC_HEADER_CFG_RESERVED_31_30	0xc0000000 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_CFG_OCHS	0x30000000 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_CFG_RESERVED_27_10	0x0ffffc00 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_CFG_OCLTS	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_2_OC_HEADER_CFG_RESERVED_8	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_2_OC_HEADER_CFG_OCLTSID	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_2_OC_HEADER_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG_RESERVED_31_30	 0xc340, 30, 2, 0xc0000000
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG_OCHS	 0xc340, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG_RESERVED_27_10	 0xc340, 10, 18, 0x0ffffc00
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG_OCLTS	 0xc340, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG_RESERVED_8	 0xc340, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_2_OC_HEADER_CFG_OCLTSID	 0xc340, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_2_OC_HEADER_0A	0xc344 /* Prefilter OC Header-A0 */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_0A	 0xc344, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_OC_HEADER_0A */
	#define BLSB_TSI_PFX_2_OC_HEADER_0A_OCLTSID	24
	#define BLSB_TSI_PFX_2_OC_HEADER_0A_OCHOSTRES	8
	#define BLSB_TSI_PFX_2_OC_HEADER_0A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_2_OC_HEADER_0A */
	#define BWID_TSI_PFX_2_OC_HEADER_0A_OCLTSID	8
	#define BWID_TSI_PFX_2_OC_HEADER_0A_OCHOSTRES	15
	#define BWID_TSI_PFX_2_OC_HEADER_0A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_2_OC_HEADER_0A */
	#define BMSK_TSI_PFX_2_OC_HEADER_0A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_0A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_0A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_2_OC_HEADER_0A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_OC_HEADER_0A_OCLTSID	 0xc344, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_2_OC_HEADER_0A_OCHOSTRES	 0xc344, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_2_OC_HEADER_0A_RESERVED_7_0	 0xc344, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_2_OC_HEADER_0B	0xc348 /* Prefilter OC Header-B0 */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_0B	 0xc348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_OC_HEADER_1A	0xc34c /* Prefilter OC Header-A1 */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_1A	 0xc34c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_OC_HEADER_1A */
	#define BLSB_TSI_PFX_2_OC_HEADER_1A_OCLTSID	24
	#define BLSB_TSI_PFX_2_OC_HEADER_1A_OCHOSTRES	8
	#define BLSB_TSI_PFX_2_OC_HEADER_1A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_2_OC_HEADER_1A */
	#define BWID_TSI_PFX_2_OC_HEADER_1A_OCLTSID	8
	#define BWID_TSI_PFX_2_OC_HEADER_1A_OCHOSTRES	15
	#define BWID_TSI_PFX_2_OC_HEADER_1A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_2_OC_HEADER_1A */
	#define BMSK_TSI_PFX_2_OC_HEADER_1A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_1A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_1A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_2_OC_HEADER_1A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_OC_HEADER_1A_OCLTSID	 0xc34c, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_2_OC_HEADER_1A_OCHOSTRES	 0xc34c, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_2_OC_HEADER_1A_RESERVED_7_0	 0xc34c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_2_OC_HEADER_1B	0xc350 /* Prefilter OC Header-B1 */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_1B	 0xc350, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_OC_HEADER_2A	0xc354 /* Prefilter OC Header-A2 */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_2A	 0xc354, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_2_OC_HEADER_2A */
	#define BLSB_TSI_PFX_2_OC_HEADER_2A_OCLTSID	24
	#define BLSB_TSI_PFX_2_OC_HEADER_2A_OCHOSTRES	8
	#define BLSB_TSI_PFX_2_OC_HEADER_2A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_2_OC_HEADER_2A */
	#define BWID_TSI_PFX_2_OC_HEADER_2A_OCLTSID	8
	#define BWID_TSI_PFX_2_OC_HEADER_2A_OCHOSTRES	15
	#define BWID_TSI_PFX_2_OC_HEADER_2A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_2_OC_HEADER_2A */
	#define BMSK_TSI_PFX_2_OC_HEADER_2A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_2A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_2_OC_HEADER_2A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_2_OC_HEADER_2A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_2_OC_HEADER_2A_OCLTSID	 0xc354, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_2_OC_HEADER_2A_OCHOSTRES	 0xc354, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_2_OC_HEADER_2A_RESERVED_7_0	 0xc354, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_2_OC_HEADER_2B	0xc358 /* Prefilter OC Header-B2 */ 
	#define BITFIELD_TSI_PFX_2_OC_HEADER_2B	 0xc358, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_OMAR_SEL	0xc360 /* Prefilter OMAR select */ 
	#define BITFIELD_TSI_PFX_2_OMAR_SEL	 0xc360, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_2_TIMESTAMP_CTR	0xc400 /* Prefilter time stamp counter */ 
	#define BITFIELD_TSI_PFX_2_TIMESTAMP_CTR	 0xc400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_PMM0	0x10000 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM0	 0x10000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM0 */
	#define BLSB_TSI_PFX_3_PMM0_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM0_MASK	16
	#define BLSB_TSI_PFX_3_PMM0_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM0_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM0 */
	#define BWID_TSI_PFX_3_PMM0_ENABLE	1
	#define BWID_TSI_PFX_3_PMM0_MASK	15
	#define BWID_TSI_PFX_3_PMM0_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM0_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM0 */
	#define BMSK_TSI_PFX_3_PMM0_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM0_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM0_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM0_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM0 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM0_ENABLE	 0x10000, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM0_MASK	 0x10000, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM0_RESERVED_15	 0x10000, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM0_EXACTVALUE	 0x10000, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM1	0x10004 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM1	 0x10004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM1 */
	#define BLSB_TSI_PFX_3_PMM1_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM1_MASK	16
	#define BLSB_TSI_PFX_3_PMM1_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM1_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM1 */
	#define BWID_TSI_PFX_3_PMM1_ENABLE	1
	#define BWID_TSI_PFX_3_PMM1_MASK	15
	#define BWID_TSI_PFX_3_PMM1_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM1_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM1 */
	#define BMSK_TSI_PFX_3_PMM1_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM1_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM1_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM1_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM1_ENABLE	 0x10004, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM1_MASK	 0x10004, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM1_RESERVED_15	 0x10004, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM1_EXACTVALUE	 0x10004, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM2	0x10008 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM2	 0x10008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM2 */
	#define BLSB_TSI_PFX_3_PMM2_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM2_MASK	16
	#define BLSB_TSI_PFX_3_PMM2_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM2_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM2 */
	#define BWID_TSI_PFX_3_PMM2_ENABLE	1
	#define BWID_TSI_PFX_3_PMM2_MASK	15
	#define BWID_TSI_PFX_3_PMM2_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM2_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM2 */
	#define BMSK_TSI_PFX_3_PMM2_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM2_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM2_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM2_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM2 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM2_ENABLE	 0x10008, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM2_MASK	 0x10008, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM2_RESERVED_15	 0x10008, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM2_EXACTVALUE	 0x10008, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM3	0x1000c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM3	 0x1000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM3 */
	#define BLSB_TSI_PFX_3_PMM3_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM3_MASK	16
	#define BLSB_TSI_PFX_3_PMM3_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM3_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM3 */
	#define BWID_TSI_PFX_3_PMM3_ENABLE	1
	#define BWID_TSI_PFX_3_PMM3_MASK	15
	#define BWID_TSI_PFX_3_PMM3_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM3_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM3 */
	#define BMSK_TSI_PFX_3_PMM3_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM3_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM3_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM3_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM3 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM3_ENABLE	 0x1000c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM3_MASK	 0x1000c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM3_RESERVED_15	 0x1000c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM3_EXACTVALUE	 0x1000c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM4	0x10010 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM4	 0x10010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM4 */
	#define BLSB_TSI_PFX_3_PMM4_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM4_MASK	16
	#define BLSB_TSI_PFX_3_PMM4_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM4_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM4 */
	#define BWID_TSI_PFX_3_PMM4_ENABLE	1
	#define BWID_TSI_PFX_3_PMM4_MASK	15
	#define BWID_TSI_PFX_3_PMM4_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM4_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM4 */
	#define BMSK_TSI_PFX_3_PMM4_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM4_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM4_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM4_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM4 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM4_ENABLE	 0x10010, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM4_MASK	 0x10010, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM4_RESERVED_15	 0x10010, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM4_EXACTVALUE	 0x10010, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM5	0x10014 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM5	 0x10014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM5 */
	#define BLSB_TSI_PFX_3_PMM5_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM5_MASK	16
	#define BLSB_TSI_PFX_3_PMM5_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM5_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM5 */
	#define BWID_TSI_PFX_3_PMM5_ENABLE	1
	#define BWID_TSI_PFX_3_PMM5_MASK	15
	#define BWID_TSI_PFX_3_PMM5_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM5_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM5 */
	#define BMSK_TSI_PFX_3_PMM5_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM5_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM5_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM5_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM5 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM5_ENABLE	 0x10014, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM5_MASK	 0x10014, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM5_RESERVED_15	 0x10014, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM5_EXACTVALUE	 0x10014, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM6	0x10018 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM6	 0x10018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM6 */
	#define BLSB_TSI_PFX_3_PMM6_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM6_MASK	16
	#define BLSB_TSI_PFX_3_PMM6_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM6_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM6 */
	#define BWID_TSI_PFX_3_PMM6_ENABLE	1
	#define BWID_TSI_PFX_3_PMM6_MASK	15
	#define BWID_TSI_PFX_3_PMM6_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM6_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM6 */
	#define BMSK_TSI_PFX_3_PMM6_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM6_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM6_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM6_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM6 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM6_ENABLE	 0x10018, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM6_MASK	 0x10018, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM6_RESERVED_15	 0x10018, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM6_EXACTVALUE	 0x10018, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM7	0x1001c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM7	 0x1001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM7 */
	#define BLSB_TSI_PFX_3_PMM7_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM7_MASK	16
	#define BLSB_TSI_PFX_3_PMM7_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM7_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM7 */
	#define BWID_TSI_PFX_3_PMM7_ENABLE	1
	#define BWID_TSI_PFX_3_PMM7_MASK	15
	#define BWID_TSI_PFX_3_PMM7_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM7_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM7 */
	#define BMSK_TSI_PFX_3_PMM7_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM7_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM7_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM7_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM7 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM7_ENABLE	 0x1001c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM7_MASK	 0x1001c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM7_RESERVED_15	 0x1001c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM7_EXACTVALUE	 0x1001c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM8	0x10020 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM8	 0x10020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM8 */
	#define BLSB_TSI_PFX_3_PMM8_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM8_MASK	16
	#define BLSB_TSI_PFX_3_PMM8_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM8_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM8 */
	#define BWID_TSI_PFX_3_PMM8_ENABLE	1
	#define BWID_TSI_PFX_3_PMM8_MASK	15
	#define BWID_TSI_PFX_3_PMM8_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM8_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM8 */
	#define BMSK_TSI_PFX_3_PMM8_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM8_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM8_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM8_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM8 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM8_ENABLE	 0x10020, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM8_MASK	 0x10020, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM8_RESERVED_15	 0x10020, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM8_EXACTVALUE	 0x10020, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM9	0x10024 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM9	 0x10024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM9 */
	#define BLSB_TSI_PFX_3_PMM9_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM9_MASK	16
	#define BLSB_TSI_PFX_3_PMM9_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM9_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM9 */
	#define BWID_TSI_PFX_3_PMM9_ENABLE	1
	#define BWID_TSI_PFX_3_PMM9_MASK	15
	#define BWID_TSI_PFX_3_PMM9_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM9_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM9 */
	#define BMSK_TSI_PFX_3_PMM9_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM9_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM9_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM9_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM9 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM9_ENABLE	 0x10024, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM9_MASK	 0x10024, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM9_RESERVED_15	 0x10024, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM9_EXACTVALUE	 0x10024, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM10	0x10028 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM10	 0x10028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM10 */
	#define BLSB_TSI_PFX_3_PMM10_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM10_MASK	16
	#define BLSB_TSI_PFX_3_PMM10_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM10_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM10 */
	#define BWID_TSI_PFX_3_PMM10_ENABLE	1
	#define BWID_TSI_PFX_3_PMM10_MASK	15
	#define BWID_TSI_PFX_3_PMM10_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM10_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM10 */
	#define BMSK_TSI_PFX_3_PMM10_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM10_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM10_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM10_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM10 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM10_ENABLE	 0x10028, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM10_MASK	 0x10028, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM10_RESERVED_15	 0x10028, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM10_EXACTVALUE	 0x10028, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM11	0x1002c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM11	 0x1002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM11 */
	#define BLSB_TSI_PFX_3_PMM11_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM11_MASK	16
	#define BLSB_TSI_PFX_3_PMM11_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM11_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM11 */
	#define BWID_TSI_PFX_3_PMM11_ENABLE	1
	#define BWID_TSI_PFX_3_PMM11_MASK	15
	#define BWID_TSI_PFX_3_PMM11_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM11_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM11 */
	#define BMSK_TSI_PFX_3_PMM11_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM11_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM11_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM11_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM11 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM11_ENABLE	 0x1002c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM11_MASK	 0x1002c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM11_RESERVED_15	 0x1002c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM11_EXACTVALUE	 0x1002c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM12	0x10030 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM12	 0x10030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM12 */
	#define BLSB_TSI_PFX_3_PMM12_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM12_MASK	16
	#define BLSB_TSI_PFX_3_PMM12_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM12_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM12 */
	#define BWID_TSI_PFX_3_PMM12_ENABLE	1
	#define BWID_TSI_PFX_3_PMM12_MASK	15
	#define BWID_TSI_PFX_3_PMM12_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM12_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM12 */
	#define BMSK_TSI_PFX_3_PMM12_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM12_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM12_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM12_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM12 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM12_ENABLE	 0x10030, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM12_MASK	 0x10030, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM12_RESERVED_15	 0x10030, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM12_EXACTVALUE	 0x10030, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM13	0x10034 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM13	 0x10034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM13 */
	#define BLSB_TSI_PFX_3_PMM13_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM13_MASK	16
	#define BLSB_TSI_PFX_3_PMM13_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM13_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM13 */
	#define BWID_TSI_PFX_3_PMM13_ENABLE	1
	#define BWID_TSI_PFX_3_PMM13_MASK	15
	#define BWID_TSI_PFX_3_PMM13_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM13_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM13 */
	#define BMSK_TSI_PFX_3_PMM13_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM13_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM13_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM13_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM13 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM13_ENABLE	 0x10034, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM13_MASK	 0x10034, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM13_RESERVED_15	 0x10034, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM13_EXACTVALUE	 0x10034, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM14	0x10038 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM14	 0x10038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM14 */
	#define BLSB_TSI_PFX_3_PMM14_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM14_MASK	16
	#define BLSB_TSI_PFX_3_PMM14_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM14_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM14 */
	#define BWID_TSI_PFX_3_PMM14_ENABLE	1
	#define BWID_TSI_PFX_3_PMM14_MASK	15
	#define BWID_TSI_PFX_3_PMM14_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM14_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM14 */
	#define BMSK_TSI_PFX_3_PMM14_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM14_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM14_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM14_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM14 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM14_ENABLE	 0x10038, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM14_MASK	 0x10038, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM14_RESERVED_15	 0x10038, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM14_EXACTVALUE	 0x10038, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM15	0x1003c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM15	 0x1003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM15 */
	#define BLSB_TSI_PFX_3_PMM15_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM15_MASK	16
	#define BLSB_TSI_PFX_3_PMM15_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM15_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM15 */
	#define BWID_TSI_PFX_3_PMM15_ENABLE	1
	#define BWID_TSI_PFX_3_PMM15_MASK	15
	#define BWID_TSI_PFX_3_PMM15_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM15_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM15 */
	#define BMSK_TSI_PFX_3_PMM15_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM15_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM15_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM15_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM15 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM15_ENABLE	 0x1003c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM15_MASK	 0x1003c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM15_RESERVED_15	 0x1003c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM15_EXACTVALUE	 0x1003c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM16	0x10040 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM16	 0x10040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM16 */
	#define BLSB_TSI_PFX_3_PMM16_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM16_MASK	16
	#define BLSB_TSI_PFX_3_PMM16_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM16_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM16 */
	#define BWID_TSI_PFX_3_PMM16_ENABLE	1
	#define BWID_TSI_PFX_3_PMM16_MASK	15
	#define BWID_TSI_PFX_3_PMM16_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM16_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM16 */
	#define BMSK_TSI_PFX_3_PMM16_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM16_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM16_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM16_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM16 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM16_ENABLE	 0x10040, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM16_MASK	 0x10040, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM16_RESERVED_15	 0x10040, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM16_EXACTVALUE	 0x10040, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM17	0x10044 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM17	 0x10044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM17 */
	#define BLSB_TSI_PFX_3_PMM17_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM17_MASK	16
	#define BLSB_TSI_PFX_3_PMM17_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM17_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM17 */
	#define BWID_TSI_PFX_3_PMM17_ENABLE	1
	#define BWID_TSI_PFX_3_PMM17_MASK	15
	#define BWID_TSI_PFX_3_PMM17_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM17_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM17 */
	#define BMSK_TSI_PFX_3_PMM17_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM17_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM17_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM17_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM17 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM17_ENABLE	 0x10044, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM17_MASK	 0x10044, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM17_RESERVED_15	 0x10044, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM17_EXACTVALUE	 0x10044, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM18	0x10048 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM18	 0x10048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM18 */
	#define BLSB_TSI_PFX_3_PMM18_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM18_MASK	16
	#define BLSB_TSI_PFX_3_PMM18_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM18_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM18 */
	#define BWID_TSI_PFX_3_PMM18_ENABLE	1
	#define BWID_TSI_PFX_3_PMM18_MASK	15
	#define BWID_TSI_PFX_3_PMM18_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM18_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM18 */
	#define BMSK_TSI_PFX_3_PMM18_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM18_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM18_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM18_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM18 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM18_ENABLE	 0x10048, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM18_MASK	 0x10048, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM18_RESERVED_15	 0x10048, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM18_EXACTVALUE	 0x10048, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM19	0x1004c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM19	 0x1004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM19 */
	#define BLSB_TSI_PFX_3_PMM19_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM19_MASK	16
	#define BLSB_TSI_PFX_3_PMM19_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM19_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM19 */
	#define BWID_TSI_PFX_3_PMM19_ENABLE	1
	#define BWID_TSI_PFX_3_PMM19_MASK	15
	#define BWID_TSI_PFX_3_PMM19_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM19_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM19 */
	#define BMSK_TSI_PFX_3_PMM19_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM19_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM19_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM19_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM19 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM19_ENABLE	 0x1004c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM19_MASK	 0x1004c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM19_RESERVED_15	 0x1004c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM19_EXACTVALUE	 0x1004c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM20	0x10050 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM20	 0x10050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM20 */
	#define BLSB_TSI_PFX_3_PMM20_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM20_MASK	16
	#define BLSB_TSI_PFX_3_PMM20_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM20_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM20 */
	#define BWID_TSI_PFX_3_PMM20_ENABLE	1
	#define BWID_TSI_PFX_3_PMM20_MASK	15
	#define BWID_TSI_PFX_3_PMM20_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM20_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM20 */
	#define BMSK_TSI_PFX_3_PMM20_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM20_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM20_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM20_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM20 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM20_ENABLE	 0x10050, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM20_MASK	 0x10050, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM20_RESERVED_15	 0x10050, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM20_EXACTVALUE	 0x10050, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM21	0x10054 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM21	 0x10054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM21 */
	#define BLSB_TSI_PFX_3_PMM21_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM21_MASK	16
	#define BLSB_TSI_PFX_3_PMM21_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM21_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM21 */
	#define BWID_TSI_PFX_3_PMM21_ENABLE	1
	#define BWID_TSI_PFX_3_PMM21_MASK	15
	#define BWID_TSI_PFX_3_PMM21_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM21_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM21 */
	#define BMSK_TSI_PFX_3_PMM21_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM21_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM21_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM21_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM21 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM21_ENABLE	 0x10054, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM21_MASK	 0x10054, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM21_RESERVED_15	 0x10054, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM21_EXACTVALUE	 0x10054, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM22	0x10058 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM22	 0x10058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM22 */
	#define BLSB_TSI_PFX_3_PMM22_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM22_MASK	16
	#define BLSB_TSI_PFX_3_PMM22_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM22_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM22 */
	#define BWID_TSI_PFX_3_PMM22_ENABLE	1
	#define BWID_TSI_PFX_3_PMM22_MASK	15
	#define BWID_TSI_PFX_3_PMM22_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM22_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM22 */
	#define BMSK_TSI_PFX_3_PMM22_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM22_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM22_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM22_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM22 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM22_ENABLE	 0x10058, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM22_MASK	 0x10058, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM22_RESERVED_15	 0x10058, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM22_EXACTVALUE	 0x10058, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM23	0x1005c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM23	 0x1005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM23 */
	#define BLSB_TSI_PFX_3_PMM23_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM23_MASK	16
	#define BLSB_TSI_PFX_3_PMM23_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM23_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM23 */
	#define BWID_TSI_PFX_3_PMM23_ENABLE	1
	#define BWID_TSI_PFX_3_PMM23_MASK	15
	#define BWID_TSI_PFX_3_PMM23_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM23_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM23 */
	#define BMSK_TSI_PFX_3_PMM23_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM23_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM23_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM23_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM23 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM23_ENABLE	 0x1005c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM23_MASK	 0x1005c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM23_RESERVED_15	 0x1005c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM23_EXACTVALUE	 0x1005c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM24	0x10060 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM24	 0x10060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM24 */
	#define BLSB_TSI_PFX_3_PMM24_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM24_MASK	16
	#define BLSB_TSI_PFX_3_PMM24_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM24_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM24 */
	#define BWID_TSI_PFX_3_PMM24_ENABLE	1
	#define BWID_TSI_PFX_3_PMM24_MASK	15
	#define BWID_TSI_PFX_3_PMM24_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM24_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM24 */
	#define BMSK_TSI_PFX_3_PMM24_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM24_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM24_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM24_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM24 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM24_ENABLE	 0x10060, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM24_MASK	 0x10060, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM24_RESERVED_15	 0x10060, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM24_EXACTVALUE	 0x10060, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM25	0x10064 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM25	 0x10064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM25 */
	#define BLSB_TSI_PFX_3_PMM25_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM25_MASK	16
	#define BLSB_TSI_PFX_3_PMM25_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM25_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM25 */
	#define BWID_TSI_PFX_3_PMM25_ENABLE	1
	#define BWID_TSI_PFX_3_PMM25_MASK	15
	#define BWID_TSI_PFX_3_PMM25_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM25_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM25 */
	#define BMSK_TSI_PFX_3_PMM25_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM25_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM25_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM25_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM25 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM25_ENABLE	 0x10064, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM25_MASK	 0x10064, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM25_RESERVED_15	 0x10064, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM25_EXACTVALUE	 0x10064, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM26	0x10068 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM26	 0x10068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM26 */
	#define BLSB_TSI_PFX_3_PMM26_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM26_MASK	16
	#define BLSB_TSI_PFX_3_PMM26_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM26_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM26 */
	#define BWID_TSI_PFX_3_PMM26_ENABLE	1
	#define BWID_TSI_PFX_3_PMM26_MASK	15
	#define BWID_TSI_PFX_3_PMM26_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM26_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM26 */
	#define BMSK_TSI_PFX_3_PMM26_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM26_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM26_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM26_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM26 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM26_ENABLE	 0x10068, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM26_MASK	 0x10068, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM26_RESERVED_15	 0x10068, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM26_EXACTVALUE	 0x10068, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM27	0x1006c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM27	 0x1006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM27 */
	#define BLSB_TSI_PFX_3_PMM27_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM27_MASK	16
	#define BLSB_TSI_PFX_3_PMM27_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM27_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM27 */
	#define BWID_TSI_PFX_3_PMM27_ENABLE	1
	#define BWID_TSI_PFX_3_PMM27_MASK	15
	#define BWID_TSI_PFX_3_PMM27_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM27_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM27 */
	#define BMSK_TSI_PFX_3_PMM27_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM27_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM27_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM27_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM27 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM27_ENABLE	 0x1006c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM27_MASK	 0x1006c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM27_RESERVED_15	 0x1006c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM27_EXACTVALUE	 0x1006c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM28	0x10070 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM28	 0x10070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM28 */
	#define BLSB_TSI_PFX_3_PMM28_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM28_MASK	16
	#define BLSB_TSI_PFX_3_PMM28_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM28_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM28 */
	#define BWID_TSI_PFX_3_PMM28_ENABLE	1
	#define BWID_TSI_PFX_3_PMM28_MASK	15
	#define BWID_TSI_PFX_3_PMM28_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM28_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM28 */
	#define BMSK_TSI_PFX_3_PMM28_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM28_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM28_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM28_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM28 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM28_ENABLE	 0x10070, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM28_MASK	 0x10070, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM28_RESERVED_15	 0x10070, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM28_EXACTVALUE	 0x10070, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM29	0x10074 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM29	 0x10074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM29 */
	#define BLSB_TSI_PFX_3_PMM29_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM29_MASK	16
	#define BLSB_TSI_PFX_3_PMM29_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM29_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM29 */
	#define BWID_TSI_PFX_3_PMM29_ENABLE	1
	#define BWID_TSI_PFX_3_PMM29_MASK	15
	#define BWID_TSI_PFX_3_PMM29_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM29_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM29 */
	#define BMSK_TSI_PFX_3_PMM29_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM29_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM29_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM29_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM29 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM29_ENABLE	 0x10074, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM29_MASK	 0x10074, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM29_RESERVED_15	 0x10074, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM29_EXACTVALUE	 0x10074, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM30	0x10078 /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM30	 0x10078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM30 */
	#define BLSB_TSI_PFX_3_PMM30_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM30_MASK	16
	#define BLSB_TSI_PFX_3_PMM30_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM30_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM30 */
	#define BWID_TSI_PFX_3_PMM30_ENABLE	1
	#define BWID_TSI_PFX_3_PMM30_MASK	15
	#define BWID_TSI_PFX_3_PMM30_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM30_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM30 */
	#define BMSK_TSI_PFX_3_PMM30_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM30_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM30_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM30_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM30 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM30_ENABLE	 0x10078, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM30_MASK	 0x10078, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM30_RESERVED_15	 0x10078, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM30_EXACTVALUE	 0x10078, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_PMM31	0x1007c /* Mask/Match register */ 
	#define BITFIELD_TSI_PFX_3_PMM31	 0x1007c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PMM31 */
	#define BLSB_TSI_PFX_3_PMM31_ENABLE	31
	#define BLSB_TSI_PFX_3_PMM31_MASK	16
	#define BLSB_TSI_PFX_3_PMM31_RESERVED_15	15
	#define BLSB_TSI_PFX_3_PMM31_EXACTVALUE	0
	/* Register Bit Widths for TSI_PFX_3_PMM31 */
	#define BWID_TSI_PFX_3_PMM31_ENABLE	1
	#define BWID_TSI_PFX_3_PMM31_MASK	15
	#define BWID_TSI_PFX_3_PMM31_RESERVED_15	1
	#define BWID_TSI_PFX_3_PMM31_EXACTVALUE	15
	/* Register Bit MASKS for TSI_PFX_3_PMM31 */
	#define BMSK_TSI_PFX_3_PMM31_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PMM31_MASK	0x7fff0000 /*  */
	#define BMSK_TSI_PFX_3_PMM31_RESERVED_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_TSI_PFX_3_PMM31_EXACTVALUE	0x00007fff /*  */
	/* Register BITFIELD for TSI_PFX_3_PMM31 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PMM31_ENABLE	 0x1007c, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PMM31_MASK	 0x1007c, 16, 15, 0x7fff0000
	#define BITFIELD_TSI_PFX_3_PMM31_RESERVED_15	 0x1007c, 15, 1, 0x00008000
	#define BITFIELD_TSI_PFX_3_PMM31_EXACTVALUE	 0x1007c, 0, 15, 0x00007fff
#define ROFF_TSI_PFX_3_CFG	0x10100 /* Prefilter Config register */ 
	#define BITFIELD_TSI_PFX_3_CFG	 0x10100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_CFG */
	#define BLSB_TSI_PFX_3_CFG_P_SN	31
	#define BLSB_TSI_PFX_3_CFG_RESERVED_30	30
	#define BLSB_TSI_PFX_3_CFG_EIS	28
	#define BLSB_TSI_PFX_3_CFG_CP	27
	#define BLSB_TSI_PFX_3_CFG_DP	26
	#define BLSB_TSI_PFX_3_CFG_EP	25
	#define BLSB_TSI_PFX_3_CFG_SP	24
	#define BLSB_TSI_PFX_3_CFG_RESERVED_23_15	15
	#define BLSB_TSI_PFX_3_CFG_OCHDR_RM	14
	#define BLSB_TSI_PFX_3_CFG_OC_CRC_MSK	13
	#define BLSB_TSI_PFX_3_CFG_OCEN	12
	#define BLSB_TSI_PFX_3_CFG_CC	10
	#define BLSB_TSI_PFX_3_CFG_TSHDR_FMT	9
	#define BLSB_TSI_PFX_3_CFG_TSHDR_EN	8
	#define BLSB_TSI_PFX_3_CFG_PGT	7
	#define BLSB_TSI_PFX_3_CFG_PLT	6
	#define BLSB_TSI_PFX_3_CFG_DAV_MSK	5
	#define BLSB_TSI_PFX_3_CFG_ERR_MSK	4
	#define BLSB_TSI_PFX_3_CFG_ENDIAN	3
	#define BLSB_TSI_PFX_3_CFG_MODE	1
	#define BLSB_TSI_PFX_3_CFG_EN	0
	/* Register Bit Widths for TSI_PFX_3_CFG */
	#define BWID_TSI_PFX_3_CFG_P_SN	1
	#define BWID_TSI_PFX_3_CFG_RESERVED_30	1
	#define BWID_TSI_PFX_3_CFG_EIS	2
	#define BWID_TSI_PFX_3_CFG_CP	1
	#define BWID_TSI_PFX_3_CFG_DP	1
	#define BWID_TSI_PFX_3_CFG_EP	1
	#define BWID_TSI_PFX_3_CFG_SP	1
	#define BWID_TSI_PFX_3_CFG_RESERVED_23_15	9
	#define BWID_TSI_PFX_3_CFG_OCHDR_RM	1
	#define BWID_TSI_PFX_3_CFG_OC_CRC_MSK	1
	#define BWID_TSI_PFX_3_CFG_OCEN	1
	#define BWID_TSI_PFX_3_CFG_CC	2
	#define BWID_TSI_PFX_3_CFG_TSHDR_FMT	1
	#define BWID_TSI_PFX_3_CFG_TSHDR_EN	1
	#define BWID_TSI_PFX_3_CFG_PGT	1
	#define BWID_TSI_PFX_3_CFG_PLT	1
	#define BWID_TSI_PFX_3_CFG_DAV_MSK	1
	#define BWID_TSI_PFX_3_CFG_ERR_MSK	1
	#define BWID_TSI_PFX_3_CFG_ENDIAN	1
	#define BWID_TSI_PFX_3_CFG_MODE	2
	#define BWID_TSI_PFX_3_CFG_EN	1
	/* Register Bit MASKS for TSI_PFX_3_CFG */
	#define BMSK_TSI_PFX_3_CFG_P_SN	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_CFG_RESERVED_30	(1<<30) /* == 0x40000000:  */
	#define BMSK_TSI_PFX_3_CFG_EIS	0x30000000 /*  */
	#define BMSK_TSI_PFX_3_CFG_CP	(1<<27) /* == 0x08000000:  */
	#define BMSK_TSI_PFX_3_CFG_DP	(1<<26) /* == 0x04000000:  */
	#define BMSK_TSI_PFX_3_CFG_EP	(1<<25) /* == 0x02000000:  */
	#define BMSK_TSI_PFX_3_CFG_SP	(1<<24) /* == 0x01000000:  */
	#define BMSK_TSI_PFX_3_CFG_RESERVED_23_15	0x00ff8000 /*  */
	#define BMSK_TSI_PFX_3_CFG_OCHDR_RM	(1<<14) /* == 0x00004000:  */
	#define BMSK_TSI_PFX_3_CFG_OC_CRC_MSK	(1<<13) /* == 0x00002000:  */
	#define BMSK_TSI_PFX_3_CFG_OCEN	(1<<12) /* == 0x00001000:  */
	#define BMSK_TSI_PFX_3_CFG_CC	0x00000c00 /*  */
	#define BMSK_TSI_PFX_3_CFG_TSHDR_FMT	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_3_CFG_TSHDR_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_3_CFG_PGT	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_3_CFG_PLT	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_3_CFG_DAV_MSK	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_3_CFG_ERR_MSK	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_3_CFG_ENDIAN	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_3_CFG_MODE	0x00000006 /*  */
	#define BMSK_TSI_PFX_3_CFG_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_3_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_CFG_P_SN	 0x10100, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_CFG_RESERVED_30	 0x10100, 30, 1, 0x40000000
	#define BITFIELD_TSI_PFX_3_CFG_EIS	 0x10100, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_3_CFG_CP	 0x10100, 27, 1, 0x08000000
	#define BITFIELD_TSI_PFX_3_CFG_DP	 0x10100, 26, 1, 0x04000000
	#define BITFIELD_TSI_PFX_3_CFG_EP	 0x10100, 25, 1, 0x02000000
	#define BITFIELD_TSI_PFX_3_CFG_SP	 0x10100, 24, 1, 0x01000000
	#define BITFIELD_TSI_PFX_3_CFG_RESERVED_23_15	 0x10100, 15, 9, 0x00ff8000
	#define BITFIELD_TSI_PFX_3_CFG_OCHDR_RM	 0x10100, 14, 1, 0x00004000
	#define BITFIELD_TSI_PFX_3_CFG_OC_CRC_MSK	 0x10100, 13, 1, 0x00002000
	#define BITFIELD_TSI_PFX_3_CFG_OCEN	 0x10100, 12, 1, 0x00001000
	#define BITFIELD_TSI_PFX_3_CFG_CC	 0x10100, 10, 2, 0x00000c00
	#define BITFIELD_TSI_PFX_3_CFG_TSHDR_FMT	 0x10100, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_3_CFG_TSHDR_EN	 0x10100, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_3_CFG_PGT	 0x10100, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_3_CFG_PLT	 0x10100, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_3_CFG_DAV_MSK	 0x10100, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_3_CFG_ERR_MSK	 0x10100, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_3_CFG_ENDIAN	 0x10100, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_3_CFG_MODE	 0x10100, 1, 2, 0x00000006
	#define BITFIELD_TSI_PFX_3_CFG_EN	 0x10100, 0, 1, 0x00000001
#define ROFF_TSI_PFX_3_STATUS	0x10104 /* Prefilter status register */ 
	#define BITFIELD_TSI_PFX_3_STATUS	 0x10104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_STATUS */
	#define BLSB_TSI_PFX_3_STATUS_RESERVED_31_12	12
	#define BLSB_TSI_PFX_3_STATUS_NIM_ERR	11
	#define BLSB_TSI_PFX_3_STATUS_DAV_LOW	10
	#define BLSB_TSI_PFX_3_STATUS_OCF	9
	#define BLSB_TSI_PFX_3_STATUS_CRC	8
	#define BLSB_TSI_PFX_3_STATUS_DIS	7
	#define BLSB_TSI_PFX_3_STATUS_DET	6
	#define BLSB_TSI_PFX_3_STATUS_PPF	5
	#define BLSB_TSI_PFX_3_STATUS_WDT	4
	#define BLSB_TSI_PFX_3_STATUS_FE	3
	#define BLSB_TSI_PFX_3_STATUS_FF	2
	#define BLSB_TSI_PFX_3_STATUS_PLT	1
	#define BLSB_TSI_PFX_3_STATUS_PGT	0
	/* Register Bit Widths for TSI_PFX_3_STATUS */
	#define BWID_TSI_PFX_3_STATUS_RESERVED_31_12	20
	#define BWID_TSI_PFX_3_STATUS_NIM_ERR	1
	#define BWID_TSI_PFX_3_STATUS_DAV_LOW	1
	#define BWID_TSI_PFX_3_STATUS_OCF	1
	#define BWID_TSI_PFX_3_STATUS_CRC	1
	#define BWID_TSI_PFX_3_STATUS_DIS	1
	#define BWID_TSI_PFX_3_STATUS_DET	1
	#define BWID_TSI_PFX_3_STATUS_PPF	1
	#define BWID_TSI_PFX_3_STATUS_WDT	1
	#define BWID_TSI_PFX_3_STATUS_FE	1
	#define BWID_TSI_PFX_3_STATUS_FF	1
	#define BWID_TSI_PFX_3_STATUS_PLT	1
	#define BWID_TSI_PFX_3_STATUS_PGT	1
	/* Register Bit MASKS for TSI_PFX_3_STATUS */
	#define BMSK_TSI_PFX_3_STATUS_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_3_STATUS_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_3_STATUS_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_3_STATUS_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_3_STATUS_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_3_STATUS_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_3_STATUS_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_3_STATUS_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_3_STATUS_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_3_STATUS_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_3_STATUS_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_3_STATUS_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_3_STATUS_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_3_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_STATUS_RESERVED_31_12	 0x10104, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_3_STATUS_NIM_ERR	 0x10104, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_3_STATUS_DAV_LOW	 0x10104, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_3_STATUS_OCF	 0x10104, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_3_STATUS_CRC	 0x10104, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_3_STATUS_DIS	 0x10104, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_3_STATUS_DET	 0x10104, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_3_STATUS_PPF	 0x10104, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_3_STATUS_WDT	 0x10104, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_3_STATUS_FE	 0x10104, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_3_STATUS_FF	 0x10104, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_3_STATUS_PLT	 0x10104, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_3_STATUS_PGT	 0x10104, 0, 1, 0x00000001
#define ROFF_TSI_PFX_3_ENABLE	0x10108 /* Prefilter enable register */ 
	#define BITFIELD_TSI_PFX_3_ENABLE	 0x10108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_ENABLE */
	#define BLSB_TSI_PFX_3_ENABLE_RESERVED_31_12	12
	#define BLSB_TSI_PFX_3_ENABLE_NIM_ERR	11
	#define BLSB_TSI_PFX_3_ENABLE_DAV_LOW	10
	#define BLSB_TSI_PFX_3_ENABLE_OCF	9
	#define BLSB_TSI_PFX_3_ENABLE_CRC	8
	#define BLSB_TSI_PFX_3_ENABLE_DIS	7
	#define BLSB_TSI_PFX_3_ENABLE_DET	6
	#define BLSB_TSI_PFX_3_ENABLE_PPF	5
	#define BLSB_TSI_PFX_3_ENABLE_WDT	4
	#define BLSB_TSI_PFX_3_ENABLE_FE	3
	#define BLSB_TSI_PFX_3_ENABLE_FF	2
	#define BLSB_TSI_PFX_3_ENABLE_PLT	1
	#define BLSB_TSI_PFX_3_ENABLE_PGT	0
	/* Register Bit Widths for TSI_PFX_3_ENABLE */
	#define BWID_TSI_PFX_3_ENABLE_RESERVED_31_12	20
	#define BWID_TSI_PFX_3_ENABLE_NIM_ERR	1
	#define BWID_TSI_PFX_3_ENABLE_DAV_LOW	1
	#define BWID_TSI_PFX_3_ENABLE_OCF	1
	#define BWID_TSI_PFX_3_ENABLE_CRC	1
	#define BWID_TSI_PFX_3_ENABLE_DIS	1
	#define BWID_TSI_PFX_3_ENABLE_DET	1
	#define BWID_TSI_PFX_3_ENABLE_PPF	1
	#define BWID_TSI_PFX_3_ENABLE_WDT	1
	#define BWID_TSI_PFX_3_ENABLE_FE	1
	#define BWID_TSI_PFX_3_ENABLE_FF	1
	#define BWID_TSI_PFX_3_ENABLE_PLT	1
	#define BWID_TSI_PFX_3_ENABLE_PGT	1
	/* Register Bit MASKS for TSI_PFX_3_ENABLE */
	#define BMSK_TSI_PFX_3_ENABLE_RESERVED_31_12	0xfffff000 /*  */
	#define BMSK_TSI_PFX_3_ENABLE_NIM_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_TSI_PFX_3_ENABLE_DAV_LOW	(1<<10) /* == 0x00000400:  */
	#define BMSK_TSI_PFX_3_ENABLE_OCF	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_3_ENABLE_CRC	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_3_ENABLE_DIS	(1<<7) /* == 0x00000080:  */
	#define BMSK_TSI_PFX_3_ENABLE_DET	(1<<6) /* == 0x00000040:  */
	#define BMSK_TSI_PFX_3_ENABLE_PPF	(1<<5) /* == 0x00000020:  */
	#define BMSK_TSI_PFX_3_ENABLE_WDT	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSI_PFX_3_ENABLE_FE	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSI_PFX_3_ENABLE_FF	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSI_PFX_3_ENABLE_PLT	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSI_PFX_3_ENABLE_PGT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSI_PFX_3_ENABLE - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_ENABLE_RESERVED_31_12	 0x10108, 12, 20, 0xfffff000
	#define BITFIELD_TSI_PFX_3_ENABLE_NIM_ERR	 0x10108, 11, 1, 0x00000800
	#define BITFIELD_TSI_PFX_3_ENABLE_DAV_LOW	 0x10108, 10, 1, 0x00000400
	#define BITFIELD_TSI_PFX_3_ENABLE_OCF	 0x10108, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_3_ENABLE_CRC	 0x10108, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_3_ENABLE_DIS	 0x10108, 7, 1, 0x00000080
	#define BITFIELD_TSI_PFX_3_ENABLE_DET	 0x10108, 6, 1, 0x00000040
	#define BITFIELD_TSI_PFX_3_ENABLE_PPF	 0x10108, 5, 1, 0x00000020
	#define BITFIELD_TSI_PFX_3_ENABLE_WDT	 0x10108, 4, 1, 0x00000010
	#define BITFIELD_TSI_PFX_3_ENABLE_FE	 0x10108, 3, 1, 0x00000008
	#define BITFIELD_TSI_PFX_3_ENABLE_FF	 0x10108, 2, 1, 0x00000004
	#define BITFIELD_TSI_PFX_3_ENABLE_PLT	 0x10108, 1, 1, 0x00000002
	#define BITFIELD_TSI_PFX_3_ENABLE_PGT	 0x10108, 0, 1, 0x00000001
#define ROFF_TSI_PFX_3_FERR_STATUS	0x1010c /* Prefilter FERR status register */ 
	#define BITFIELD_TSI_PFX_3_FERR_STATUS	 0x1010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_FERR_STATUS */
	#define BLSB_TSI_PFX_3_FERR_STATUS_RESERVED_31_29	29
	#define BLSB_TSI_PFX_3_FERR_STATUS_FERR_VAL	24
	#define BLSB_TSI_PFX_3_FERR_STATUS_RESERVED_23_22	22
	#define BLSB_TSI_PFX_3_FERR_STATUS_PID	8
	#define BLSB_TSI_PFX_3_FERR_STATUS_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_3_FERR_STATUS */
	#define BWID_TSI_PFX_3_FERR_STATUS_RESERVED_31_29	3
	#define BWID_TSI_PFX_3_FERR_STATUS_FERR_VAL	5
	#define BWID_TSI_PFX_3_FERR_STATUS_RESERVED_23_22	2
	#define BWID_TSI_PFX_3_FERR_STATUS_PID	14
	#define BWID_TSI_PFX_3_FERR_STATUS_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_3_FERR_STATUS */
	#define BMSK_TSI_PFX_3_FERR_STATUS_RESERVED_31_29	0xe0000000 /*  */
	#define BMSK_TSI_PFX_3_FERR_STATUS_FERR_VAL	0x1f000000 /*  */
	#define BMSK_TSI_PFX_3_FERR_STATUS_RESERVED_23_22	0x00c00000 /*  */
	#define BMSK_TSI_PFX_3_FERR_STATUS_PID	0x003fff00 /*  */
	#define BMSK_TSI_PFX_3_FERR_STATUS_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_3_FERR_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_FERR_STATUS_RESERVED_31_29	 0x1010c, 29, 3, 0xe0000000
	#define BITFIELD_TSI_PFX_3_FERR_STATUS_FERR_VAL	 0x1010c, 24, 5, 0x1f000000
	#define BITFIELD_TSI_PFX_3_FERR_STATUS_RESERVED_23_22	 0x1010c, 22, 2, 0x00c00000
	#define BITFIELD_TSI_PFX_3_FERR_STATUS_PID	 0x1010c, 8, 14, 0x003fff00
	#define BITFIELD_TSI_PFX_3_FERR_STATUS_RESERVED_7_0	 0x1010c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_3_DMA_BASE	0x10200 /* Prefilter DMA Base */ 
	#define BITFIELD_TSI_PFX_3_DMA_BASE	 0x10200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_DMA_SIZE	0x10204 /* Prefilter DMA Size */ 
	#define BITFIELD_TSI_PFX_3_DMA_SIZE	 0x10204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_DMA_WR_PTR	0x10208 /* Prefilter DMA Write Pointer */ 
	#define BITFIELD_TSI_PFX_3_DMA_WR_PTR	 0x10208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_DMA_SHDW_WR_PTR_ADDR	0x1020c /* Prefilter DMA Shadow Write Pointer Address */ 
	#define BITFIELD_TSI_PFX_3_DMA_SHDW_WR_PTR_ADDR	 0x1020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_DMA_RD_PTR	0x10210 /* Prefilter DMA Read Pointer */ 
	#define BITFIELD_TSI_PFX_3_DMA_RD_PTR	 0x10210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_DMA_SHDW_WR_CTR	0x10214 /* Prefilter DMA Shadow Write Counter */ 
	#define BITFIELD_TSI_PFX_3_DMA_SHDW_WR_CTR	 0x10214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_NIM_WDT	0x10218 /* Prefilter NIM Watch Dog Timer */ 
	#define BITFIELD_TSI_PFX_3_NIM_WDT	 0x10218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_NIM_WDT */
	#define BLSB_TSI_PFX_3_NIM_WDT_ENABLE	31
	#define BLSB_TSI_PFX_3_NIM_WDT_WDT	0
	/* Register Bit Widths for TSI_PFX_3_NIM_WDT */
	#define BWID_TSI_PFX_3_NIM_WDT_ENABLE	1
	#define BWID_TSI_PFX_3_NIM_WDT_WDT	31
	/* Register Bit MASKS for TSI_PFX_3_NIM_WDT */
	#define BMSK_TSI_PFX_3_NIM_WDT_ENABLE	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_NIM_WDT_WDT	0x7fffffff /*  */
	/* Register BITFIELD for TSI_PFX_3_NIM_WDT - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_NIM_WDT_ENABLE	 0x10218, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_NIM_WDT_WDT	 0x10218, 0, 31, 0x7fffffff
#define ROFF_TSI_PFX_3_PCR_CFG	0x10300 /* Prefilter PCR Config */ 
	#define BITFIELD_TSI_PFX_3_PCR_CFG	 0x10300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_PCR_REMOTE_A0	0x1031c /* Prefilter PCR Remote A0 */ 
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A0	 0x1031c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_PCR_REMOTE_A1	0x10320 /* Prefilter PCR Remote A1 */ 
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A1	 0x10320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_PCR_REMOTE_A1 */
	#define BLSB_TSI_PFX_3_PCR_REMOTE_A1_PCRR_MSBA1	31
	#define BLSB_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_30_17	17
	#define BLSB_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LOCK	16
	#define BLSB_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_15_9	9
	#define BLSB_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LSBSA1	0
	/* Register Bit Widths for TSI_PFX_3_PCR_REMOTE_A1 */
	#define BWID_TSI_PFX_3_PCR_REMOTE_A1_PCRR_MSBA1	1
	#define BWID_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_30_17	14
	#define BWID_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LOCK	1
	#define BWID_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_15_9	7
	#define BWID_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LSBSA1	9
	/* Register Bit MASKS for TSI_PFX_3_PCR_REMOTE_A1 */
	#define BMSK_TSI_PFX_3_PCR_REMOTE_A1_PCRR_MSBA1	(1<<31) /* == 0x80000000:  */
	#define BMSK_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_30_17	0x7ffe0000 /*  */
	#define BMSK_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LOCK	(1<<16) /* == 0x00010000:  */
	#define BMSK_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_15_9	0x0000fe00 /*  */
	#define BMSK_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LSBSA1	0x000001ff /*  */
	/* Register BITFIELD for TSI_PFX_3_PCR_REMOTE_A1 - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A1_PCRR_MSBA1	 0x10320, 31, 1, 0x80000000
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_30_17	 0x10320, 17, 14, 0x7ffe0000
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LOCK	 0x10320, 16, 1, 0x00010000
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A1_RESERVED_15_9	 0x10320, 9, 7, 0x0000fe00
	#define BITFIELD_TSI_PFX_3_PCR_REMOTE_A1_PCRR_LSBSA1	 0x10320, 0, 9, 0x000001ff
#define ROFF_TSI_PFX_3_OC_HEADER_CFG	0x10340 /* Prefilter OC Header Config */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG	 0x10340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_OC_HEADER_CFG */
	#define BLSB_TSI_PFX_3_OC_HEADER_CFG_RESERVED_31_30	30
	#define BLSB_TSI_PFX_3_OC_HEADER_CFG_OCHS	28
	#define BLSB_TSI_PFX_3_OC_HEADER_CFG_RESERVED_27_10	10
	#define BLSB_TSI_PFX_3_OC_HEADER_CFG_OCLTS	9
	#define BLSB_TSI_PFX_3_OC_HEADER_CFG_RESERVED_8	8
	#define BLSB_TSI_PFX_3_OC_HEADER_CFG_OCLTSID	0
	/* Register Bit Widths for TSI_PFX_3_OC_HEADER_CFG */
	#define BWID_TSI_PFX_3_OC_HEADER_CFG_RESERVED_31_30	2
	#define BWID_TSI_PFX_3_OC_HEADER_CFG_OCHS	2
	#define BWID_TSI_PFX_3_OC_HEADER_CFG_RESERVED_27_10	18
	#define BWID_TSI_PFX_3_OC_HEADER_CFG_OCLTS	1
	#define BWID_TSI_PFX_3_OC_HEADER_CFG_RESERVED_8	1
	#define BWID_TSI_PFX_3_OC_HEADER_CFG_OCLTSID	8
	/* Register Bit MASKS for TSI_PFX_3_OC_HEADER_CFG */
	#define BMSK_TSI_PFX_3_OC_HEADER_CFG_RESERVED_31_30	0xc0000000 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_CFG_OCHS	0x30000000 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_CFG_RESERVED_27_10	0x0ffffc00 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_CFG_OCLTS	(1<<9) /* == 0x00000200:  */
	#define BMSK_TSI_PFX_3_OC_HEADER_CFG_RESERVED_8	(1<<8) /* == 0x00000100:  */
	#define BMSK_TSI_PFX_3_OC_HEADER_CFG_OCLTSID	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_3_OC_HEADER_CFG - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG_RESERVED_31_30	 0x10340, 30, 2, 0xc0000000
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG_OCHS	 0x10340, 28, 2, 0x30000000
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG_RESERVED_27_10	 0x10340, 10, 18, 0x0ffffc00
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG_OCLTS	 0x10340, 9, 1, 0x00000200
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG_RESERVED_8	 0x10340, 8, 1, 0x00000100
	#define BITFIELD_TSI_PFX_3_OC_HEADER_CFG_OCLTSID	 0x10340, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_3_OC_HEADER_0A	0x10344 /* Prefilter OC Header-A0 */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_0A	 0x10344, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_OC_HEADER_0A */
	#define BLSB_TSI_PFX_3_OC_HEADER_0A_OCLTSID	24
	#define BLSB_TSI_PFX_3_OC_HEADER_0A_OCHOSTRES	8
	#define BLSB_TSI_PFX_3_OC_HEADER_0A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_3_OC_HEADER_0A */
	#define BWID_TSI_PFX_3_OC_HEADER_0A_OCLTSID	8
	#define BWID_TSI_PFX_3_OC_HEADER_0A_OCHOSTRES	15
	#define BWID_TSI_PFX_3_OC_HEADER_0A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_3_OC_HEADER_0A */
	#define BMSK_TSI_PFX_3_OC_HEADER_0A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_0A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_0A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_3_OC_HEADER_0A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_OC_HEADER_0A_OCLTSID	 0x10344, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_3_OC_HEADER_0A_OCHOSTRES	 0x10344, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_3_OC_HEADER_0A_RESERVED_7_0	 0x10344, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_3_OC_HEADER_0B	0x10348 /* Prefilter OC Header-B0 */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_0B	 0x10348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_OC_HEADER_1A	0x1034c /* Prefilter OC Header-A1 */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_1A	 0x1034c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_OC_HEADER_1A */
	#define BLSB_TSI_PFX_3_OC_HEADER_1A_OCLTSID	24
	#define BLSB_TSI_PFX_3_OC_HEADER_1A_OCHOSTRES	8
	#define BLSB_TSI_PFX_3_OC_HEADER_1A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_3_OC_HEADER_1A */
	#define BWID_TSI_PFX_3_OC_HEADER_1A_OCLTSID	8
	#define BWID_TSI_PFX_3_OC_HEADER_1A_OCHOSTRES	15
	#define BWID_TSI_PFX_3_OC_HEADER_1A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_3_OC_HEADER_1A */
	#define BMSK_TSI_PFX_3_OC_HEADER_1A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_1A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_1A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_3_OC_HEADER_1A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_OC_HEADER_1A_OCLTSID	 0x1034c, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_3_OC_HEADER_1A_OCHOSTRES	 0x1034c, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_3_OC_HEADER_1A_RESERVED_7_0	 0x1034c, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_3_OC_HEADER_1B	0x10350 /* Prefilter OC Header-B1 */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_1B	 0x10350, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_OC_HEADER_2A	0x10354 /* Prefilter OC Header-A2 */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_2A	 0x10354, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSI_PFX_3_OC_HEADER_2A */
	#define BLSB_TSI_PFX_3_OC_HEADER_2A_OCLTSID	24
	#define BLSB_TSI_PFX_3_OC_HEADER_2A_OCHOSTRES	8
	#define BLSB_TSI_PFX_3_OC_HEADER_2A_RESERVED_7_0	0
	/* Register Bit Widths for TSI_PFX_3_OC_HEADER_2A */
	#define BWID_TSI_PFX_3_OC_HEADER_2A_OCLTSID	8
	#define BWID_TSI_PFX_3_OC_HEADER_2A_OCHOSTRES	15
	#define BWID_TSI_PFX_3_OC_HEADER_2A_RESERVED_7_0	8
	/* Register Bit MASKS for TSI_PFX_3_OC_HEADER_2A */
	#define BMSK_TSI_PFX_3_OC_HEADER_2A_OCLTSID	0xff000000 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_2A_OCHOSTRES	0x007fff00 /*  */
	#define BMSK_TSI_PFX_3_OC_HEADER_2A_RESERVED_7_0	0x000000ff /*  */
	/* Register BITFIELD for TSI_PFX_3_OC_HEADER_2A - roff, lsb, width, mask */
	#define BITFIELD_TSI_PFX_3_OC_HEADER_2A_OCLTSID	 0x10354, 24, 8, 0xff000000
	#define BITFIELD_TSI_PFX_3_OC_HEADER_2A_OCHOSTRES	 0x10354, 8, 15, 0x007fff00
	#define BITFIELD_TSI_PFX_3_OC_HEADER_2A_RESERVED_7_0	 0x10354, 0, 8, 0x000000ff
#define ROFF_TSI_PFX_3_OC_HEADER_2B	0x10358 /* Prefilter OC Header-B2 */ 
	#define BITFIELD_TSI_PFX_3_OC_HEADER_2B	 0x10358, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_OMAR_SEL	0x10360 /* Prefilter OMAR select */ 
	#define BITFIELD_TSI_PFX_3_OMAR_SEL	 0x10360, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSI_PFX_3_TIMESTAMP_CTR	0x10400 /* Prefilter time stamp counter */ 
	#define BITFIELD_TSI_PFX_3_TIMESTAMP_CTR	 0x10400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module TSI SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_TSI_BUFFER_FULL	0x1
#define SVEN_MODULE_EVENT_TSI_PACKET_LOSS	0x2
#define SVEN_MODULE_EVENT_TSI_OC_FIFO_FULL	0x3
#define SVEN_MODULE_EVENT_TSI_OC_CRC	0x4


#endif /* TSI_REGOFFS_H */
