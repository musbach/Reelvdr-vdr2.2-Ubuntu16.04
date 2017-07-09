#ifndef H264_REGOFFS_H
#define H264_REGOFFS_H 1
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


/* Module H264 CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_H264_H264VD_GLOBAL_CTRL	0x0 /* Global Control */ 
	#define BITFIELD_H264_H264VD_GLOBAL_CTRL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DPB_DDR_BA	0x4 /* DPB DDR Base Address */ 
	#define BITFIELD_H264_H264VD_DPB_DDR_BA	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DPB_FS_CTRL	0x8 /* DPB Frame Store Control */ 
	#define BITFIELD_H264_H264VD_DPB_FS_CTRL	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_RSB_DDR_BA	0xc /* RSB DDR Base Address */ 
	#define BITFIELD_H264_H264VD_RSB_DDR_BA	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_FAV_CTRL	0x10 /* Frame Association Value Control */ 
	#define BITFIELD_H264_H264VD_FAV_CTRL	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_FAV	0x14 /* Frame Association Value */ 
	#define BITFIELD_H264_H264VD_FAV	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PAV	0x18 /* PTS Association Value */ 
	#define BITFIELD_H264_H264VD_PAV	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DAV	0x1c /* Discontinuity Association Value */ 
	#define BITFIELD_H264_H264VD_DAV	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SIF_SMP_RS	0x20 /* SIF Semaphore Register (RS access) */ 
	#define BITFIELD_H264_H264VD_SIF_SMP_RS	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SIF_MSK_RS	0x24 /* SIF Interrupt Mask Register (RS access) */ 
	#define BITFIELD_H264_H264VD_SIF_MSK_RS	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SIF_HDAT	0x28 /* SIF Host Semaphore Data Register */ 
	#define BITFIELD_H264_H264VD_SIF_HDAT	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SIF_SDDAT	0x2c /* SIF Slice Decoder Semaphore Data Register  */ 
	#define BITFIELD_H264_H264VD_SIF_SDDAT	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SIF_SMP_RC	0x30 /* SIF Semaphore Register (RC access) */ 
	#define BITFIELD_H264_H264VD_SIF_SMP_RC	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SIF_MSK_RC	0x34 /* SIF Interrupt Mask Register (RC access) */ 
	#define BITFIELD_H264_H264VD_SIF_MSK_RC	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_FW_BA	0x38 /* Slice Controller Firmware Base Address  */ 
	#define BITFIELD_H264_H264VD_FW_BA	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PMOD	0x3c /* Slice Decoder Program Mode */ 
	#define BITFIELD_H264_H264VD_PMOD	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SED	0x40 /* Stream Enable/Disable */ 
	#define BITFIELD_H264_H264VD_SED	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SDEMC	0x44 /* Stream DMA Engine Master Control */ 
	#define BITFIELD_H264_H264VD_SDEMC	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_INT_EN	0x48 /* Interrupt Enable */ 
	#define BITFIELD_H264_H264VD_INT_EN	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_INT_STAT	0x4c /* Interrupt Status */ 
	#define BITFIELD_H264_H264VD_INT_STAT	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_INT_CNTR	0x50 /* Interrupt Counter */ 
	#define BITFIELD_H264_H264VD_INT_CNTR	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PTS_MSB	0x54 /* PTS MSB */ 
	#define BITFIELD_H264_H264VD_PTS_MSB	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PTS_LSB	0x58 /* PTS LSB */ 
	#define BITFIELD_H264_H264VD_PTS_LSB	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_RES1	0x5c /*  */ 
	#define BITFIELD_H264_RES1	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_CB_BASE	0x100 /* Stream DMA Circular/Linear Buffer Base Address */ 
	#define BITFIELD_H264_H264VD_DMA_CB_BASE	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SB_RDPTR	0x104 /* Stream DMA Source Block Register Address of Read Pointer */ 
	#define BITFIELD_H264_H264VD_DMA_SB_RDPTR	 0x0104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_CB_SIZE	0x108 /* Stream DMA Circular/Linear Buffer Size */ 
	#define BITFIELD_H264_H264VD_DMA_CB_SIZE	 0x0108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_WTRMARK	0x10c /* Stream DMA Read/Write Pointer Watermark */ 
	#define BITFIELD_H264_H264VD_DMA_WTRMARK	 0x010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_WDT	0x110 /* Stream DMA Watchdog Timer */ 
	#define BITFIELD_H264_H264VD_DMA_WDT	 0x0110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_CB_RDPTR	0x114 /* Stream DMA Local Read Pointer */ 
	#define BITFIELD_H264_H264VD_DMA_CB_RDPTR	 0x0114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_CB_WRPTR	0x118 /* Stream DMA Local Write Pointer */ 
	#define BITFIELD_H264_H264VD_DMA_CB_WRPTR	 0x0118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SDLINK	0x11c /* Stream DMA Link Address */ 
	#define BITFIELD_H264_H264VD_DMA_SDLINK	 0x011c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SDLLSA	0x120 /* Stream DMA Link List Source Address */ 
	#define BITFIELD_H264_H264VD_DMA_SDLLSA	 0x0120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SDLNDA	0x124 /* Stream DMA Link List Next Descriptor Address */ 
	#define BITFIELD_H264_H264VD_DMA_SDLNDA	 0x0124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SDLDBC	0x128 /* Stream DMA Link List Data Buffer Byte Count */ 
	#define BITFIELD_H264_H264VD_DMA_SDLDBC	 0x0128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SDLCBC	0x12c /* Stream DMA Link List Current Data Buffer Byte Count */ 
	#define BITFIELD_H264_H264VD_DMA_SDLCBC	 0x012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_SDLDC	0x130 /* Stream DMA Link List Descriptor Control */ 
	#define BITFIELD_H264_H264VD_DMA_SDLDC	 0x0130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_RES2	0x134 /*  */ 
	#define BITFIELD_H264_RES2	 0x0134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_FIFO	0x900 /* Stream DMA FIFO Write Data */ 
	#define BITFIELD_H264_H264VD_DMA_FIFO	 0x0900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DMA_FIFO_STAT	0x904 /* Stream DMA FIFO Status */ 
	#define BITFIELD_H264_H264VD_DMA_FIFO_STAT	 0x0904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_TMR_CTRL	0x200 /* PES Packet Parser Timer Control Register */ 
	#define BITFIELD_H264_H264VD_PES_TMR_CTRL	 0x0200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_CTRL	0x204 /* PES Packet Parser Control Register */ 
	#define BITFIELD_H264_H264VD_PES_CTRL	 0x0204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_STAT	0x208 /* PES Packet Parser Status Register */ 
	#define BITFIELD_H264_H264VD_PES_STAT	 0x0208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_STATID	0x20c /* PES Packet Parser Status ID Register */ 
	#define BITFIELD_H264_H264VD_PES_STATID	 0x020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG1	0x210 /* PES Packet Parser Data Register 1 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG1	 0x0210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG2	0x214 /* PES Packet Parser Data Register 2 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG2	 0x0214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG3	0x218 /* PES Packet Parser Data Register 3 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG3	 0x0218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG4	0x21c /* PES Packet Parser Data Register 4 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG4	 0x021c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG5	0x220 /* PES Packet Parser Data Register 5 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG5	 0x0220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG6	0x224 /* PES Packet Parser Data Register 6 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG6	 0x0224, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DATAREG7	0x228 /* PES Packet Parser Data Register 7 */ 
	#define BITFIELD_H264_H264VD_PES_DATAREG7	 0x0228, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_EXT_DATA	0x22c /* PES Packet Parser Extension Data Register */ 
	#define BITFIELD_H264_H264VD_PES_EXT_DATA	 0x022c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_SCR1	0x230 /* PES Packet Parser Programmable Start Codes 1 */ 
	#define BITFIELD_H264_H264VD_PES_SCR1	 0x0230, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_SCR2	0x234 /* PES Packet Parser Programmable Start Codes 2 */ 
	#define BITFIELD_H264_H264VD_PES_SCR2	 0x0234, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DOSTCM	0x238 /* PES Packet Parser Discontinuity Old STC (MSB) */ 
	#define BITFIELD_H264_H264VD_PES_DOSTCM	 0x0238, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DOSTCL	0x23c /* PES Packet Parser Discontinuity Old STC (LSB) */ 
	#define BITFIELD_H264_H264VD_PES_DOSTCL	 0x023c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DNSTCM	0x240 /* PES Packet Parser Discontinuity NEW STC (MSB) */ 
	#define BITFIELD_H264_H264VD_PES_DNSTCM	 0x0240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_PES_DNSTCL	0x244 /* PES Packet Parser Discontinuity NEW STC (LSB) */ 
	#define BITFIELD_H264_H264VD_PES_DNSTCL	 0x0244, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_RES3	0x248 /*  */ 
	#define BITFIELD_H264_RES3	 0x0248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_AM	0x300 /* STC_A (MSB) */ 
	#define BITFIELD_H264_H264VD_STC_AM	 0x0300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_AL	0x304 /* STC_A (LSB) */ 
	#define BITFIELD_H264_H264VD_STC_AL	 0x0304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_BM	0x308 /* STC_B (MSB) */ 
	#define BITFIELD_H264_H264VD_STC_BM	 0x0308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_BL	0x30c /* STC_B (LSB) */ 
	#define BITFIELD_H264_H264VD_STC_BL	 0x030c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_CTRL	0x310 /* STC Control */ 
	#define BITFIELD_H264_H264VD_STC_CTRL	 0x0310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_CNTM	0x314 /* STC Count Value (MSB) */ 
	#define BITFIELD_H264_H264VD_STC_CNTM	 0x0314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_CNTL	0x318 /* STC Count Timeout (LSB) */ 
	#define BITFIELD_H264_H264VD_STC_CNTL	 0x0318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_CNTTM	0x31c /* STC Count Timeout (MSB) */ 
	#define BITFIELD_H264_H264VD_STC_CNTTM	 0x031c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_CNTTL	0x320 /* STC Count Timeout (LSB) */ 
	#define BITFIELD_H264_H264VD_STC_CNTTL	 0x0320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_VCNTM	0x324 /* STC VDC Count (MSB) */ 
	#define BITFIELD_H264_H264VD_STC_VCNTM	 0x0324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_STC_VCNTL	0x328 /* STC VDC Count (LSB) */ 
	#define BITFIELD_H264_H264VD_STC_VCNTL	 0x0328, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_RES4	0x32c /*  */ 
	#define BITFIELD_H264_RES4	 0x032c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_CTRL	0x400 /* DQM PTS Control */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_CTRL	 0x0400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_OM	0x404 /* DQM PTS Post Accumulator Offset (MSB) */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_OM	 0x0404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_OL	0x408 /* DQM PTS Post Accumulator Offset (LSB) */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_OL	 0x0408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_AM	0x40c /* DQM PTS Accumulator (MSB) */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_AM	 0x040c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_AL	0x410 /* DQM PTS Accumulator (LSB) */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_AL	 0x0410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_SM	0x414 /* DQM PTS Accumulator Step Size (MSB) */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_SM	 0x0414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_PTS_SL	0x418 /* DQM PTS Accumulator Step Size (LSB) */ 
	#define BITFIELD_H264_H264VD_DQM_PTS_SL	 0x0418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DEST_Y	0x41c /* DQM Destination Y Buffer Register Address */ 
	#define BITFIELD_H264_H264VD_DQM_DEST_Y	 0x041c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DEST_UV	0x420 /* DQM Destination UV Buffer Register Address */ 
	#define BITFIELD_H264_H264VD_DQM_DEST_UV	 0x0420, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DEST_FLIP	0x424 /* DQM Destination Overlay Flip Mode Register Address  */ 
	#define BITFIELD_H264_H264VD_DQM_DEST_FLIP	 0x0424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DQ_CS	0x428 /* DQM Display Queue Control/Status */ 
	#define BITFIELD_H264_H264VD_DQM_DQ_CS	 0x0428, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DQ_UV_ADR	0x42c /* DQM Display Queue UV Address */ 
	#define BITFIELD_H264_H264VD_DQM_DQ_UV_ADR	 0x042c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DQ_Y_ADR	0x430 /* DQM Display Queue Y Address */ 
	#define BITFIELD_H264_H264VD_DQM_DQ_Y_ADR	 0x0430, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DQ_PTS_M	0x434 /* DQM Display Queue PTS Value (MSB) */ 
	#define BITFIELD_H264_H264VD_DQM_DQ_PTS_M	 0x0434, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DQ_PTS_L	0x438 /* DQM Display Queue PTS Value (LSB) */ 
	#define BITFIELD_H264_H264VD_DQM_DQ_PTS_L	 0x0438, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_ODPQ_CS	0x43c /* DQM Ordered Decoded Picture Queue Control/Status */ 
	#define BITFIELD_H264_H264VD_DQM_ODPQ_CS	 0x043c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_ODPQ_DATA	0x440 /* DQM Ordered Decoded Picture Queue Data */ 
	#define BITFIELD_H264_H264VD_DQM_ODPQ_DATA	 0x0440, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_ODPQ_WMRK	0x444 /* DQM Ordered Decoded Picture Queue Watermark */ 
	#define BITFIELD_H264_H264VD_DQM_ODPQ_WMRK	 0x0444, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_DPB_STAT	0x448 /* DQM DPB Status */ 
	#define BITFIELD_H264_H264VD_DQM_DPB_STAT	 0x0448, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_DQM_RDLY_CS	0x44c /* DQM Release Delay Control/Status */ 
	#define BITFIELD_H264_H264VD_DQM_RDLY_CS	 0x044c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_RES5	0x450 /*  */ 
	#define BITFIELD_H264_RES5	 0x0450, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SMP_RD	0x1000 /* Semaphore Read */ 
	#define BITFIELD_H264_H264VD_SD_SMP_RD	 0x1000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SMP_MSK_RD	0x1004 /* Interrupt Mask Read */ 
	#define BITFIELD_H264_H264VD_SD_SMP_MSK_RD	 0x1004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SMP_SET	0x1008 /* Semaphore Set */ 
	#define BITFIELD_H264_H264VD_SD_SMP_SET	 0x1008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SMP_CLR	0x100c /* Semaphore Clear */ 
	#define BITFIELD_H264_H264VD_SD_SMP_CLR	 0x100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SMP_MSK_SET	0x1010 /* Interrupt Mask Set */ 
	#define BITFIELD_H264_H264VD_SD_SMP_MSK_SET	 0x1010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SMP_MSK_CLR	0x1014 /* Interrupt Mask Clear */ 
	#define BITFIELD_H264_H264VD_SD_SMP_MSK_CLR	 0x1014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_HDAT	0x1018 /* Host Data Register */ 
	#define BITFIELD_H264_H264VD_SD_HDAT	 0x1018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SDDAT	0x101c /* Data Register */ 
	#define BITFIELD_H264_H264VD_SD_SDDAT	 0x101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DQ_PUSH	0x1020 /* Display Queue Push */ 
	#define BITFIELD_H264_H264VD_SD_DQ_PUSH	 0x1020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DQ_STAT	0x1024 /* Display Queue Status */ 
	#define BITFIELD_H264_H264VD_SD_DQ_STAT	 0x1024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DPB_INIT	0x1040 /* DPB Initialize */ 
	#define BITFIELD_H264_H264VD_SD_DPB_INIT	 0x1040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DPB_FRM_SZ_STAT	0x1044 /* DPB Image Frame Size Status */ 
	#define BITFIELD_H264_H264VD_SD_DPB_FRM_SZ_STAT	 0x1044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DPB_FRM_SZ_CTRL	0x1048 /* DPB Image Frame Size Control (Override) */ 
	#define BITFIELD_H264_H264VD_SD_DPB_FRM_SZ_CTRL	 0x1048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DPB_NUMB_OVR	0x104c /* DPB Image Component Size Control (in KB) */ 
	#define BITFIELD_H264_H264VD_SD_DPB_NUMB_OVR	 0x104c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DPB_FS_VALUES	0x1050 /* DPB Frame Store Values (Set by H264VD_DPB_FS_CTRL) */ 
	#define BITFIELD_H264_H264VD_SD_DPB_FS_VALUES	 0x1050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DPB_FS_OFFSET	0x1054 /* DPB Frame Store Offset */ 
	#define BITFIELD_H264_H264VD_SD_DPB_FS_OFFSET	 0x1054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_FSD	0x1058 /* Frame System Data (aka FAV) */ 
	#define BITFIELD_H264_H264VD_SD_FSD	 0x1058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SD_INT_CTRL	0x10c0 /* Slice Decoder Enable and Interrupt Control */ 
	#define BITFIELD_H264_H264VD_SD_SD_INT_CTRL	 0x10c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_INT_STAT	0x10c4 /* Slice Decoder Interrupt Status */ 
	#define BITFIELD_H264_H264VD_SD_INT_STAT	 0x10c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_SOFT_RST	0x10fc /* Slice Decoder Soft Reset */ 
	#define BITFIELD_H264_H264VD_SD_SOFT_RST	 0x10fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_PSR_STAT	0x1100 /* Parser Status */ 
	#define BITFIELD_H264_H264VD_SD_BSD_PSR_STAT	 0x1100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_STAT	0x1104 /* BSD Status */ 
	#define BITFIELD_H264_H264VD_SD_BSD_STAT	 0x1104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_RBSP_CTRL	0x1110 /* RBSP Feed Control */ 
	#define BITFIELD_H264_H264VD_SD_BSD_RBSP_CTRL	 0x1110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_DATA	0x1114 /* BSD Data Register */ 
	#define BITFIELD_H264_H264VD_SD_BSD_DATA	 0x1114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_NAL_TYPE	0x1118 /* NAL Type */ 
	#define BITFIELD_H264_H264VD_SD_BSD_NAL_TYPE	 0x1118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_BBB_STAT	0x111c /* BBB Buffer Bits */ 
	#define BITFIELD_H264_H264VD_SD_BSD_BBB_STAT	 0x111c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_GUE_DEC	0x1120 /* Golomb UE Decode */ 
	#define BITFIELD_H264_H264VD_SD_BSD_GUE_DEC	 0x1120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_GSE_DEC	0x1124 /* Golomb SE Decode */ 
	#define BITFIELD_H264_H264VD_SD_BSD_GSE_DEC	 0x1124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_EXP_GME_INTRA	0x1128 /* Exp Golomb ME Intra */ 
	#define BITFIELD_H264_H264VD_SD_BSD_EXP_GME_INTRA	 0x1128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_EXP_GME_INTER	0x1138 /* Exp Golomb ME Inter */ 
	#define BITFIELD_H264_H264VD_SD_BSD_EXP_GME_INTER	 0x1138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_IMG_INIT	0x1140 /* Image Initialize */ 
	#define BITFIELD_H264_H264VD_SD_BSD_IMG_INIT	 0x1140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_SLICE_P1	0x1150 /* Slice Parameter 1 */ 
	#define BITFIELD_H264_H264VD_SD_BSD_SLICE_P1	 0x1150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_SLICE_P2	0x1154 /* Slice Parameter 2 */ 
	#define BITFIELD_H264_H264VD_SD_BSD_SLICE_P2	 0x1154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_SLICE_START	0x1158 /* Slice Start */ 
	#define BITFIELD_H264_H264VD_SD_BSD_SLICE_START	 0x1158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_MB_CTRL	0x115c /* Macro Block Control for Override engine current MB address/ X and Y positions */ 
	#define BITFIELD_H264_H264VD_SD_BSD_MB_CTRL	 0x115c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_BYTE_ALIGN	0x117c /* Force Byte Align */ 
	#define BITFIELD_H264_H264VD_SD_BSD_BYTE_ALIGN	 0x117c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_BBB_TRAIL	0x1180 /* BBB Buffer Trailing Bits */ 
	#define BITFIELD_H264_H264VD_SD_BSD_BBB_TRAIL	 0x1180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_BSD_GET_BITS	0x1184 /* BSD Get Bits: 1 to 30 bits based on Address */ 
	#define BITFIELD_H264_H264VD_SD_BSD_GET_BITS	 0x1184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_TF_POC	0x1300 /* Top Field Picture POC */ 
	#define BITFIELD_H264_H264VD_SD_MPR_TF_POC	 0x1300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_BF_POC	0x1304 /* Bottom Field Picture POC */ 
	#define BITFIELD_H264_H264VD_SD_MPR_BF_POC	 0x1304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST0	0x1380 /* MPR List 0 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST0	 0x1380, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST1	0x1384 /* MPR List 1 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST1	 0x1384, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST2	0x1388 /* MPR List 2 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST2	 0x1388, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST3	0x138c /* MPR List 3 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST3	 0x138c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST4	0x1390 /* MPR List 4 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST4	 0x1390, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST5	0x1394 /* MPR List 5 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST5	 0x1394, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST6	0x1398 /* MPR List 6 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST6	 0x1398, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST7	0x139c /* MPR List 7 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST7	 0x139c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST8	0x13a0 /* MPR List 8 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST8	 0x13a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST9	0x13a4 /* MPR List 9 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST9	 0x13a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST10	0x13a8 /* MPR List 10 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST10	 0x13a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST11	0x13ac /* MPR List 11 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST11	 0x13ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST12	0x13b0 /* MPR List 12 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST12	 0x13b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST13	0x13b4 /* MPR List 13 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST13	 0x13b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST14	0x13b8 /* MPR List 14 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST14	 0x13b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_MPR_LST15	0x13bc /* MPR List 15 */ 
	#define BITFIELD_H264_H264VD_SD_MPR_LST15	 0x13bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_INTC_INT_MASK	0x1400 /* Interrupt Mask */ 
	#define BITFIELD_H264_H264VD_SD_INTC_INT_MASK	 0x1400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_INTC_WR_INT_PEND	0x1404 /* Write interrupt pending */ 
	#define BITFIELD_H264_H264VD_SD_INTC_WR_INT_PEND	 0x1404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_INTC_INT_FORCE	0x1408 /* Interrupt Force */ 
	#define BITFIELD_H264_H264VD_SD_INTC_INT_FORCE	 0x1408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_INTC_CLR_INT_PEND	0x140c /* Clear interrupt pending */ 
	#define BITFIELD_H264_H264VD_SD_INTC_CLR_INT_PEND	 0x140c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_0_VALUE	0x1800 /* Timer 0 Value */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_0_VALUE	 0x1800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_LOAD_0_VALUE	0x1804 /* Load value 0 */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_LOAD_0_VALUE	 0x1804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_0_CTRL	0x1808 /* Timer 0 Control */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_0_CTRL	 0x1808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_1_VALUE	0x1810 /* Timer 1 Value */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_1_VALUE	 0x1810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_LOAD_1_VALUE	0x1814 /* Load value 1 */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_LOAD_1_VALUE	 0x1814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_1_CTRL	0x1818 /* Timer 1 Control */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_1_CTRL	 0x1818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_SCALER_VALUE	0x1820 /* Scaler Value */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_SCALER_VALUE	 0x1820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_TIMER_SCALER_PRELOAD	0x1824 /* Scaler PreLoad */ 
	#define BITFIELD_H264_H264VD_SD_TIMER_SCALER_PRELOAD	 0x1824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DMA_EM_ADDRESS	0x1c00 /* External Memory Address */ 
	#define BITFIELD_H264_H264VD_SD_DMA_EM_ADDRESS	 0x1c00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DMA_INTERNAL_CONFIG	0x1c04 /* Internal config */ 
	#define BITFIELD_H264_H264VD_SD_DMA_INTERNAL_CONFIG	 0x1c04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DMA_DO_MEM_TRANSFR	0x1c08 /* Do memory transfer */ 
	#define BITFIELD_H264_H264VD_SD_DMA_DO_MEM_TRANSFR	 0x1c08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_SD_DMA_TRANSFR_STATUS	0x1c0c /* Transfer Status */ 
	#define BITFIELD_H264_H264VD_SD_DMA_TRANSFR_STATUS	 0x1c0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_REGFILE	0x2000 /* Windowed Register File */ 
	#define BITFIELD_H264_H264VD_VSPARC_REGFILE	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_GLOBALREGS	0x2204 /* Processor Global Registers (%g0 to %g7) */ 
	#define BITFIELD_H264_H264VD_VSPARC_GLOBALREGS	 0x2204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_FPC	0x2300 /* Fetch Program Counter */ 
	#define BITFIELD_H264_H264VD_VSPARC_FPC	 0x2300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_FSTATUS	0x2308 /* Fetch Status (Supervisor Bit) */ 
	#define BITFIELD_H264_H264VD_VSPARC_FSTATUS	 0x2308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DPC	0x2310 /* Decode Program Counter */ 
	#define BITFIELD_H264_H264VD_VSPARC_DPC	 0x2310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_D_INST	0x2314 /* Decode Instruction */ 
	#define BITFIELD_H264_H264VD_VSPARC_D_INST	 0x2314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DSTATUS	0x2318 /* Decode Status Flags */ 
	#define BITFIELD_H264_H264VD_VSPARC_DSTATUS	 0x2318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_EPC	0x2320 /* Execute Program Counter */ 
	#define BITFIELD_H264_H264VD_VSPARC_EPC	 0x2320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_E_INST	0x2324 /* Execute Instruction */ 
	#define BITFIELD_H264_H264VD_VSPARC_E_INST	 0x2324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_ESTATUS	0x2328 /* Execute Status Flags */ 
	#define BITFIELD_H264_H264VD_VSPARC_ESTATUS	 0x2328, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_MSTATUS	0x2338 /* Memory Status Flags */ 
	#define BITFIELD_H264_H264VD_VSPARC_MSTATUS	 0x2338, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_WSTATUS	0x2348 /* Write Status Flags */ 
	#define BITFIELD_H264_H264VD_VSPARC_WSTATUS	 0x2348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DCTRL	0x2400 /* Debugger Control Register */ 
	#define BITFIELD_H264_H264VD_VSPARC_DCTRL	 0x2400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DSTAT	0x2404 /* Debugger Status Register / Single Step */ 
	#define BITFIELD_H264_H264VD_VSPARC_DSTAT	 0x2404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_PCBREAK0	0x2480 /* PC Breakpoint 0 */ 
	#define BITFIELD_H264_H264VD_VSPARC_PCBREAK0	 0x2480, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_PCBREAKMASK0	0x2484 /* PC Breakpoint Mask 0 */ 
	#define BITFIELD_H264_PCBREAKMASK0	 0x2484, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_PCBREAK1	0x2490 /* PC Breakpoint 1 */ 
	#define BITFIELD_H264_H264VD_VSPARC_PCBREAK1	 0x2490, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_PCBREAKMASK1	0x2494 /* PC Breakpoint Mask 1 */ 
	#define BITFIELD_H264_PCBREAKMASK1	 0x2494, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_PCBREAK2	0x24a0 /* PC Breakpoint 2 */ 
	#define BITFIELD_H264_H264VD_VSPARC_PCBREAK2	 0x24a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_PCBREAKMASK2	0x24a4 /* PC Breakpoint Mask 2 */ 
	#define BITFIELD_H264_PCBREAKMASK2	 0x24a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_PCBREAK3	0x24b0 /* PC Breakpoint 3 */ 
	#define BITFIELD_H264_H264VD_VSPARC_PCBREAK3	 0x24b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_PCBREAKMASK3	0x24b4 /* PC Breakpoint Mask 3 */ 
	#define BITFIELD_H264_PCBREAKMASK3	 0x24b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAK0	0x24c0 /* Data Access Breakpoint 0 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAK0	 0x24c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAKMASK0	0x24c4 /* Data Access Breakpoint Mask 0 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAKMASK0	 0x24c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAK1	0x24d0 /* Data Access Breakpoint 1 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAK1	 0x24d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAKMASK1	0x24d4 /* Data Access Breakpoint Mask 1 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAKMASK1	 0x24d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAK2	0x24e0 /* Data Access Breakpoint 2 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAK2	 0x24e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAKMASK2	0x24e4 /* Data Access Breakpoint Mask 2 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAKMASK2	 0x24e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAK3	0x24f0 /* Data Access Breakpoint 3 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAK3	 0x24f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_DATABREAKMASK3	0x24f4 /* Data Access Breakpoint Mask 3 */ 
	#define BITFIELD_H264_H264VD_VSPARC_DATABREAKMASK3	 0x24f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_LRAM	0x2800 /* Local SRAM Area */ 
	#define BITFIELD_H264_H264VD_VSPARC_LRAM	 0x2800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_H264_H264VD_VSPARC_MEM	0x8000 /* Slice Decoder Controller shared code/data memory window. */ 
	#define BITFIELD_H264_H264VD_VSPARC_MEM	 0x8000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module H264 SPECIFIC SVEN Events */




#endif /* H264_REGOFFS_H */
