#ifndef ADI_REGOFFS_H
#define ADI_REGOFFS_H 1
#warning including deprecated file ADI_REGOFFS_H please use sanitized filename
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


/* Module ADI CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_ADI_NMB_ROWS_CHROMA	0x0 /* Number of MB rows of chroma vertically. Defines the chroma depth of the image in NV12 format in units of MB */ 
	#define BITFIELD_ADI_NMB_ROWS_CHROMA	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_NMB_ROWS_LUMA	0x4 /* Number of MB rows of luma vertically. Defines the luma depth of the image in NV12 format in units of MB */ 
	#define BITFIELD_ADI_NMB_ROWS_LUMA	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_NMB_PER_ROW	0x8 /* Number of MB horizonatally. Defines the luma & chroma width of the image in NV12 format in units of MB */ 
	#define BITFIELD_ADI_NMB_PER_ROW	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_LUMA2CHROMA_OFF	0xc /* DO_NOT_USE */ 
	#define BITFIELD_ADI_LUMA2CHROMA_OFF	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_STATUS	0x10 /* Contains debug break status such as interrupts etc. */ 
	#define BITFIELD_ADI_STATUS	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for ADI_STATUS */
	#define BLSB_ADI_STATUS_VCMH_WFIFO_EMPTY	31
	#define BLSB_ADI_STATUS_RDATA_MGR_COL_LAST	30
	#define BLSB_ADI_STATUS_RDATA_MGR_COL_0	29
	#define BLSB_ADI_STATUS_RDATA_MGR_ROW_LAST	28
	#define BLSB_ADI_STATUS_RDATA_MGR_ROW_0	27
	#define BLSB_ADI_STATUS_RDATA_MGR_ROW_VEC	19
	#define BLSB_ADI_STATUS_RDATA_MGR_COL_VEC	11
	#define BLSB_ADI_STATUS_TOP_FIRST	10
	#define BLSB_ADI_STATUS_ENGINE_BUSY_NMINUS1	9
	#define BLSB_ADI_STATUS_ENGINE_BUSY_NPLUS1	8
	#define BLSB_ADI_STATUS_WBUFF_MGR_CSR_RD_PTR	5
	#define BLSB_ADI_STATUS_WBUFF_MGR_CSR_FRAME_COUNT	1
	#define BLSB_ADI_STATUS_ZERO	0
	/* Register Bit Widths for ADI_STATUS */
	#define BWID_ADI_STATUS_VCMH_WFIFO_EMPTY	1
	#define BWID_ADI_STATUS_RDATA_MGR_COL_LAST	1
	#define BWID_ADI_STATUS_RDATA_MGR_COL_0	1
	#define BWID_ADI_STATUS_RDATA_MGR_ROW_LAST	1
	#define BWID_ADI_STATUS_RDATA_MGR_ROW_0	1
	#define BWID_ADI_STATUS_RDATA_MGR_ROW_VEC	8
	#define BWID_ADI_STATUS_RDATA_MGR_COL_VEC	8
	#define BWID_ADI_STATUS_TOP_FIRST	1
	#define BWID_ADI_STATUS_ENGINE_BUSY_NMINUS1	1
	#define BWID_ADI_STATUS_ENGINE_BUSY_NPLUS1	1
	#define BWID_ADI_STATUS_WBUFF_MGR_CSR_RD_PTR	3
	#define BWID_ADI_STATUS_WBUFF_MGR_CSR_FRAME_COUNT	4
	#define BWID_ADI_STATUS_ZERO	1
	/* Register Bit MASKS for ADI_STATUS */
	#define BMSK_ADI_STATUS_VCMH_WFIFO_EMPTY	(1<<31) /* == 0x80000000:  */
	#define BMSK_ADI_STATUS_RDATA_MGR_COL_LAST	(1<<30) /* == 0x40000000:  */
	#define BMSK_ADI_STATUS_RDATA_MGR_COL_0	(1<<29) /* == 0x20000000:  */
	#define BMSK_ADI_STATUS_RDATA_MGR_ROW_LAST	(1<<28) /* == 0x10000000:  */
	#define BMSK_ADI_STATUS_RDATA_MGR_ROW_0	(1<<27) /* == 0x08000000:  */
	#define BMSK_ADI_STATUS_RDATA_MGR_ROW_VEC	0x07f80000 /*  */
	#define BMSK_ADI_STATUS_RDATA_MGR_COL_VEC	0x0007f800 /*  */
	#define BMSK_ADI_STATUS_TOP_FIRST	(1<<10) /* == 0x00000400:  */
	#define BMSK_ADI_STATUS_ENGINE_BUSY_NMINUS1	(1<<9) /* == 0x00000200:  */
	#define BMSK_ADI_STATUS_ENGINE_BUSY_NPLUS1	(1<<8) /* == 0x00000100:  */
	#define BMSK_ADI_STATUS_WBUFF_MGR_CSR_RD_PTR	0x000000e0 /*  */
	#define BMSK_ADI_STATUS_WBUFF_MGR_CSR_FRAME_COUNT	0x0000001e /*  */
	#define BMSK_ADI_STATUS_ZERO	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for ADI_STATUS - roff, lsb, width, mask */
	#define BITFIELD_ADI_STATUS_VCMH_WFIFO_EMPTY	 0x0010, 31, 1, 0x80000000
	#define BITFIELD_ADI_STATUS_RDATA_MGR_COL_LAST	 0x0010, 30, 1, 0x40000000
	#define BITFIELD_ADI_STATUS_RDATA_MGR_COL_0	 0x0010, 29, 1, 0x20000000
	#define BITFIELD_ADI_STATUS_RDATA_MGR_ROW_LAST	 0x0010, 28, 1, 0x10000000
	#define BITFIELD_ADI_STATUS_RDATA_MGR_ROW_0	 0x0010, 27, 1, 0x08000000
	#define BITFIELD_ADI_STATUS_RDATA_MGR_ROW_VEC	 0x0010, 19, 8, 0x07f80000
	#define BITFIELD_ADI_STATUS_RDATA_MGR_COL_VEC	 0x0010, 11, 8, 0x0007f800
	#define BITFIELD_ADI_STATUS_TOP_FIRST	 0x0010, 10, 1, 0x00000400
	#define BITFIELD_ADI_STATUS_ENGINE_BUSY_NMINUS1	 0x0010, 9, 1, 0x00000200
	#define BITFIELD_ADI_STATUS_ENGINE_BUSY_NPLUS1	 0x0010, 8, 1, 0x00000100
	#define BITFIELD_ADI_STATUS_WBUFF_MGR_CSR_RD_PTR	 0x0010, 5, 3, 0x000000e0
	#define BITFIELD_ADI_STATUS_WBUFF_MGR_CSR_FRAME_COUNT	 0x0010, 1, 4, 0x0000001e
	#define BITFIELD_ADI_STATUS_ZERO	 0x0010, 0, 1, 0x00000001
#define ROFF_ADI_CONTROL	0x14 /* Control or configuration register to set up the ADI */ 
	#define BITFIELD_ADI_CONTROL	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for ADI_CONTROL */
	#define BLSB_ADI_CONTROL_RESERVED_26_31	26
	#define BLSB_ADI_CONTROL_BACK_BUFFER_PREVENT	25
	#define BLSB_ADI_CONTROL_SWAP_ALLBYTES4RD_DATA	24
	#define BLSB_ADI_CONTROL_EN_SOFT_FLIP	23
	#define BLSB_ADI_CONTROL_DBG_RPT_FR	22
	#define BLSB_ADI_CONTROL_USE_VDC_FLIPB	21
	#define BLSB_ADI_CONTROL_USE_VDC_FLIPA	20
	#define BLSB_ADI_CONTROL_SOFT_HALT_ADI_VDC_WR	19
	#define BLSB_ADI_CONTROL_SOFT_FLUSH	18
	#define BLSB_ADI_CONTROL_SOFT_POP	17
	#define BLSB_ADI_CONTROL_SOFT_PUSH	16
	#define BLSB_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_LOWER	15
	#define BLSB_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_UPPER	14
	#define BLSB_ADI_CONTROL_DBG_SWAP_8BYTES_WITHIN16	13
	#define BLSB_ADI_CONTROL_MOTION_THRESHHOLD	3
	#define BLSB_ADI_CONTROL_RESERVED_2	2
	#define BLSB_ADI_CONTROL_ENABLE	1
	#define BLSB_ADI_CONTROL_RESERVED_0	0
	/* Register Bit Widths for ADI_CONTROL */
	#define BWID_ADI_CONTROL_RESERVED_26_31	6
	#define BWID_ADI_CONTROL_BACK_BUFFER_PREVENT	1
	#define BWID_ADI_CONTROL_SWAP_ALLBYTES4RD_DATA	1
	#define BWID_ADI_CONTROL_EN_SOFT_FLIP	1
	#define BWID_ADI_CONTROL_DBG_RPT_FR	1
	#define BWID_ADI_CONTROL_USE_VDC_FLIPB	1
	#define BWID_ADI_CONTROL_USE_VDC_FLIPA	1
	#define BWID_ADI_CONTROL_SOFT_HALT_ADI_VDC_WR	1
	#define BWID_ADI_CONTROL_SOFT_FLUSH	1
	#define BWID_ADI_CONTROL_SOFT_POP	1
	#define BWID_ADI_CONTROL_SOFT_PUSH	1
	#define BWID_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_LOWER	1
	#define BWID_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_UPPER	1
	#define BWID_ADI_CONTROL_DBG_SWAP_8BYTES_WITHIN16	1
	#define BWID_ADI_CONTROL_MOTION_THRESHHOLD	10
	#define BWID_ADI_CONTROL_RESERVED_2	1
	#define BWID_ADI_CONTROL_ENABLE	1
	#define BWID_ADI_CONTROL_RESERVED_0	1
	/* Register Bit MASKS for ADI_CONTROL */
	#define BMSK_ADI_CONTROL_RESERVED_26_31	0xfc000000 /*  */
	#define BMSK_ADI_CONTROL_BACK_BUFFER_PREVENT	(1<<25) /* == 0x02000000: A write of 1 to this bit prevents the back-buffer from moving to the front buffer in the ADI  */
	#define BMSK_ADI_CONTROL_SWAP_ALLBYTES4RD_DATA	(1<<24) /* == 0x01000000: MUST ALWAYS BE 1 */
	#define BMSK_ADI_CONTROL_EN_SOFT_FLIP	(1<<23) /* == 0x00800000:  */
	#define BMSK_ADI_CONTROL_DBG_RPT_FR	(1<<22) /* == 0x00400000:  */
	#define BMSK_ADI_CONTROL_USE_VDC_FLIPB	(1<<21) /* == 0x00200000:  */
	#define BMSK_ADI_CONTROL_USE_VDC_FLIPA	(1<<20) /* == 0x00100000:  */
	#define BMSK_ADI_CONTROL_SOFT_HALT_ADI_VDC_WR	(1<<19) /* == 0x00080000:  */
	#define BMSK_ADI_CONTROL_SOFT_FLUSH	(1<<18) /* == 0x00040000:  */
	#define BMSK_ADI_CONTROL_SOFT_POP	(1<<17) /* == 0x00020000:  */
	#define BMSK_ADI_CONTROL_SOFT_PUSH	(1<<16) /* == 0x00010000:  */
	#define BMSK_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_LOWER	(1<<15) /* == 0x00008000: SHOULD ALWAYS BE ZERO */
	#define BMSK_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_UPPER	(1<<14) /* == 0x00004000: SHOULD ALWAYS BE ZERO */
	#define BMSK_ADI_CONTROL_DBG_SWAP_8BYTES_WITHIN16	(1<<13) /* == 0x00002000: SHOULD ALWAYS BE ZERO */
	#define BMSK_ADI_CONTROL_MOTION_THRESHHOLD	0x00001ff8 /* Should always be programmed to ten (decimal) */
	#define BMSK_ADI_CONTROL_RESERVED_2	(1<<2) /* == 0x00000004:  */
	#define BMSK_ADI_CONTROL_ENABLE	(1<<1) /* == 0x00000002:  */
	#define BMSK_ADI_CONTROL_RESERVED_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for ADI_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_ADI_CONTROL_RESERVED_26_31	 0x0014, 26, 6, 0xfc000000
	#define BITFIELD_ADI_CONTROL_BACK_BUFFER_PREVENT	 0x0014, 25, 1, 0x02000000
	#define BITFIELD_ADI_CONTROL_SWAP_ALLBYTES4RD_DATA	 0x0014, 24, 1, 0x01000000
	#define BITFIELD_ADI_CONTROL_EN_SOFT_FLIP	 0x0014, 23, 1, 0x00800000
	#define BITFIELD_ADI_CONTROL_DBG_RPT_FR	 0x0014, 22, 1, 0x00400000
	#define BITFIELD_ADI_CONTROL_USE_VDC_FLIPB	 0x0014, 21, 1, 0x00200000
	#define BITFIELD_ADI_CONTROL_USE_VDC_FLIPA	 0x0014, 20, 1, 0x00100000
	#define BITFIELD_ADI_CONTROL_SOFT_HALT_ADI_VDC_WR	 0x0014, 19, 1, 0x00080000
	#define BITFIELD_ADI_CONTROL_SOFT_FLUSH	 0x0014, 18, 1, 0x00040000
	#define BITFIELD_ADI_CONTROL_SOFT_POP	 0x0014, 17, 1, 0x00020000
	#define BITFIELD_ADI_CONTROL_SOFT_PUSH	 0x0014, 16, 1, 0x00010000
	#define BITFIELD_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_LOWER	 0x0014, 15, 1, 0x00008000
	#define BITFIELD_ADI_CONTROL_DBG_SWAP_WITHIN8BYTES_UPPER	 0x0014, 14, 1, 0x00004000
	#define BITFIELD_ADI_CONTROL_DBG_SWAP_8BYTES_WITHIN16	 0x0014, 13, 1, 0x00002000
	#define BITFIELD_ADI_CONTROL_MOTION_THRESHHOLD	 0x0014, 3, 10, 0x00001ff8
	#define BITFIELD_ADI_CONTROL_RESERVED_2	 0x0014, 2, 1, 0x00000004
	#define BITFIELD_ADI_CONTROL_ENABLE	 0x0014, 1, 1, 0x00000002
	#define BITFIELD_ADI_CONTROL_RESERVED_0	 0x0014, 0, 1, 0x00000001
#define ROFF_ADI_INTEN	0x18 /* Enable the different interrupts */ 
	#define BITFIELD_ADI_INTEN	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for ADI_INTEN */
	#define BLSB_ADI_INTEN_RESERVED_24_31	24
	#define BLSB_ADI_INTEN_ADI_ADDR_VLD	23
	#define BLSB_ADI_INTEN_ARB_WR_CMD_TAKEN	22
	#define BLSB_ADI_INTEN_RDATA_MGR_COL_LAST	21
	#define BLSB_ADI_INTEN_RDATA_MGR_COL_0	20
	#define BLSB_ADI_INTEN_RDATA_MGR_ROW_LAST	19
	#define BLSB_ADI_INTEN_RDATA_MGR_ROW_0	18
	#define BLSB_ADI_INTEN_VCMH_ADI_WFIFO_RD	17
	#define BLSB_ADI_INTEN_VCMH_ADI_REQFIFO_RD	16
	#define BLSB_ADI_INTEN_VCMH_ADI_REORDER_WEN	15
	#define BLSB_ADI_INTEN_VCMH_ADI_REORDER_DONE	14
	#define BLSB_ADI_INTEN_ARDY	13
	#define BLSB_ADI_INTEN_GO_PROCESS_FRAME_NPLUS1	12
	#define BLSB_ADI_INTEN_ENGINE_BUSY_NMINUS1	11
	#define BLSB_ADI_INTEN_CODEC_IF_UPDATE_FRONT_BUFF	10
	#define BLSB_ADI_INTEN_OVRKEEPOUT1	9
	#define BLSB_ADI_INTEN_OVRKEEPOUT0	8
	#define BLSB_ADI_INTEN_FLIP_VIDB	7
	#define BLSB_ADI_INTEN_FLIP_VIDA	6
	#define BLSB_ADI_INTEN_CODEC_IF_KILL_FLIP2CODEC	5
	#define BLSB_ADI_INTEN_WBUFF_MGR_CSR_WR_VDC	4
	#define BLSB_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_N	3
	#define BLSB_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_NPLUS1	2
	#define BLSB_ADI_INTEN_WBUFF_MGR_CSR_DI_UNDERRUN	1
	#define BLSB_ADI_INTEN_MASTER_ENABLE	0
	/* Register Bit Widths for ADI_INTEN */
	#define BWID_ADI_INTEN_RESERVED_24_31	8
	#define BWID_ADI_INTEN_ADI_ADDR_VLD	1
	#define BWID_ADI_INTEN_ARB_WR_CMD_TAKEN	1
	#define BWID_ADI_INTEN_RDATA_MGR_COL_LAST	1
	#define BWID_ADI_INTEN_RDATA_MGR_COL_0	1
	#define BWID_ADI_INTEN_RDATA_MGR_ROW_LAST	1
	#define BWID_ADI_INTEN_RDATA_MGR_ROW_0	1
	#define BWID_ADI_INTEN_VCMH_ADI_WFIFO_RD	1
	#define BWID_ADI_INTEN_VCMH_ADI_REQFIFO_RD	1
	#define BWID_ADI_INTEN_VCMH_ADI_REORDER_WEN	1
	#define BWID_ADI_INTEN_VCMH_ADI_REORDER_DONE	1
	#define BWID_ADI_INTEN_ARDY	1
	#define BWID_ADI_INTEN_GO_PROCESS_FRAME_NPLUS1	1
	#define BWID_ADI_INTEN_ENGINE_BUSY_NMINUS1	1
	#define BWID_ADI_INTEN_CODEC_IF_UPDATE_FRONT_BUFF	1
	#define BWID_ADI_INTEN_OVRKEEPOUT1	1
	#define BWID_ADI_INTEN_OVRKEEPOUT0	1
	#define BWID_ADI_INTEN_FLIP_VIDB	1
	#define BWID_ADI_INTEN_FLIP_VIDA	1
	#define BWID_ADI_INTEN_CODEC_IF_KILL_FLIP2CODEC	1
	#define BWID_ADI_INTEN_WBUFF_MGR_CSR_WR_VDC	1
	#define BWID_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_N	1
	#define BWID_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_NPLUS1	1
	#define BWID_ADI_INTEN_WBUFF_MGR_CSR_DI_UNDERRUN	1
	#define BWID_ADI_INTEN_MASTER_ENABLE	1
	/* Register Bit MASKS for ADI_INTEN */
	#define BMSK_ADI_INTEN_RESERVED_24_31	0xff000000 /*  */
	#define BMSK_ADI_INTEN_ADI_ADDR_VLD	(1<<23) /* == 0x00800000: RW */
	#define BMSK_ADI_INTEN_ARB_WR_CMD_TAKEN	(1<<22) /* == 0x00400000: RW */
	#define BMSK_ADI_INTEN_RDATA_MGR_COL_LAST	(1<<21) /* == 0x00200000: RW */
	#define BMSK_ADI_INTEN_RDATA_MGR_COL_0	(1<<20) /* == 0x00100000: RW */
	#define BMSK_ADI_INTEN_RDATA_MGR_ROW_LAST	(1<<19) /* == 0x00080000: RW */
	#define BMSK_ADI_INTEN_RDATA_MGR_ROW_0	(1<<18) /* == 0x00040000: RW */
	#define BMSK_ADI_INTEN_VCMH_ADI_WFIFO_RD	(1<<17) /* == 0x00020000: RW */
	#define BMSK_ADI_INTEN_VCMH_ADI_REQFIFO_RD	(1<<16) /* == 0x00010000: RW */
	#define BMSK_ADI_INTEN_VCMH_ADI_REORDER_WEN	(1<<15) /* == 0x00008000: RW */
	#define BMSK_ADI_INTEN_VCMH_ADI_REORDER_DONE	(1<<14) /* == 0x00004000: RW */
	#define BMSK_ADI_INTEN_ARDY	(1<<13) /* == 0x00002000: RW */
	#define BMSK_ADI_INTEN_GO_PROCESS_FRAME_NPLUS1	(1<<12) /* == 0x00001000: RW */
	#define BMSK_ADI_INTEN_ENGINE_BUSY_NMINUS1	(1<<11) /* == 0x00000800: RW */
	#define BMSK_ADI_INTEN_CODEC_IF_UPDATE_FRONT_BUFF	(1<<10) /* == 0x00000400: RW */
	#define BMSK_ADI_INTEN_OVRKEEPOUT1	(1<<9) /* == 0x00000200: RW */
	#define BMSK_ADI_INTEN_OVRKEEPOUT0	(1<<8) /* == 0x00000100: RW */
	#define BMSK_ADI_INTEN_FLIP_VIDB	(1<<7) /* == 0x00000080: RW */
	#define BMSK_ADI_INTEN_FLIP_VIDA	(1<<6) /* == 0x00000040: RW */
	#define BMSK_ADI_INTEN_CODEC_IF_KILL_FLIP2CODEC	(1<<5) /* == 0x00000020: RW */
	#define BMSK_ADI_INTEN_WBUFF_MGR_CSR_WR_VDC	(1<<4) /* == 0x00000010: RW */
	#define BMSK_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_N	(1<<3) /* == 0x00000008: RW */
	#define BMSK_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_NPLUS1	(1<<2) /* == 0x00000004: RW */
	#define BMSK_ADI_INTEN_WBUFF_MGR_CSR_DI_UNDERRUN	(1<<1) /* == 0x00000002: RW */
	#define BMSK_ADI_INTEN_MASTER_ENABLE	(1<<0) /* == 0x00000001: GLOBAL OR MASTER ENABLE FOR ALL THE INTERRUPTS. THIS MUST BE PROGRAMMED TO 1 TO ENABLE ANY OF THE INTERRUPTS */
	/* Register BITFIELD for ADI_INTEN - roff, lsb, width, mask */
	#define BITFIELD_ADI_INTEN_RESERVED_24_31	 0x0018, 24, 8, 0xff000000
	#define BITFIELD_ADI_INTEN_ADI_ADDR_VLD	 0x0018, 23, 1, 0x00800000
	#define BITFIELD_ADI_INTEN_ARB_WR_CMD_TAKEN	 0x0018, 22, 1, 0x00400000
	#define BITFIELD_ADI_INTEN_RDATA_MGR_COL_LAST	 0x0018, 21, 1, 0x00200000
	#define BITFIELD_ADI_INTEN_RDATA_MGR_COL_0	 0x0018, 20, 1, 0x00100000
	#define BITFIELD_ADI_INTEN_RDATA_MGR_ROW_LAST	 0x0018, 19, 1, 0x00080000
	#define BITFIELD_ADI_INTEN_RDATA_MGR_ROW_0	 0x0018, 18, 1, 0x00040000
	#define BITFIELD_ADI_INTEN_VCMH_ADI_WFIFO_RD	 0x0018, 17, 1, 0x00020000
	#define BITFIELD_ADI_INTEN_VCMH_ADI_REQFIFO_RD	 0x0018, 16, 1, 0x00010000
	#define BITFIELD_ADI_INTEN_VCMH_ADI_REORDER_WEN	 0x0018, 15, 1, 0x00008000
	#define BITFIELD_ADI_INTEN_VCMH_ADI_REORDER_DONE	 0x0018, 14, 1, 0x00004000
	#define BITFIELD_ADI_INTEN_ARDY	 0x0018, 13, 1, 0x00002000
	#define BITFIELD_ADI_INTEN_GO_PROCESS_FRAME_NPLUS1	 0x0018, 12, 1, 0x00001000
	#define BITFIELD_ADI_INTEN_ENGINE_BUSY_NMINUS1	 0x0018, 11, 1, 0x00000800
	#define BITFIELD_ADI_INTEN_CODEC_IF_UPDATE_FRONT_BUFF	 0x0018, 10, 1, 0x00000400
	#define BITFIELD_ADI_INTEN_OVRKEEPOUT1	 0x0018, 9, 1, 0x00000200
	#define BITFIELD_ADI_INTEN_OVRKEEPOUT0	 0x0018, 8, 1, 0x00000100
	#define BITFIELD_ADI_INTEN_FLIP_VIDB	 0x0018, 7, 1, 0x00000080
	#define BITFIELD_ADI_INTEN_FLIP_VIDA	 0x0018, 6, 1, 0x00000040
	#define BITFIELD_ADI_INTEN_CODEC_IF_KILL_FLIP2CODEC	 0x0018, 5, 1, 0x00000020
	#define BITFIELD_ADI_INTEN_WBUFF_MGR_CSR_WR_VDC	 0x0018, 4, 1, 0x00000010
	#define BITFIELD_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_N	 0x0018, 3, 1, 0x00000008
	#define BITFIELD_ADI_INTEN_WBUFF_MGR_CSR_DI_DONE_NPLUS1	 0x0018, 2, 1, 0x00000004
	#define BITFIELD_ADI_INTEN_WBUFF_MGR_CSR_DI_UNDERRUN	 0x0018, 1, 1, 0x00000002
	#define BITFIELD_ADI_INTEN_MASTER_ENABLE	 0x0018, 0, 1, 0x00000001
#define ROFF_ADI_INTSTAT	0x1c /* View the interrupt status */ 
	#define BITFIELD_ADI_INTSTAT	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_FBUF_ADDR0_Y	0x20 /* DRAM Address of latest deinterlaced frame to be written to VDC. Luma address. */ 
	#define BITFIELD_ADI_FBUF_ADDR0_Y	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_FBUF_ADDR1_U	0x24 /* DRAM Address of latest deinterlaced frame to be written to VDC. Luma address. */ 
	#define BITFIELD_ADI_FBUF_ADDR1_U	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_VDC_OVL_Y	0x28 /* This is the address of the VDC Overlay Buffer 0 Start Address Y Pointer Register */ 
	#define BITFIELD_ADI_VDC_OVL_Y	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_VDC_OVL_U	0x2c /* This is the address of the VDC Overlay Buffer 0 Start Address Y Pointer Register */ 
	#define BITFIELD_ADI_VDC_OVL_U	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_VDC_OVL_V	0x30 /* for future use to support other formats */ 
	#define BITFIELD_ADI_VDC_OVL_V	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF1_Y	0x34 /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 1st frame */ 
	#define BITFIELD_ADI_ADI_FBUF1_Y	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF1_U	0x38 /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 1st frame */ 
	#define BITFIELD_ADI_ADI_FBUF1_U	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF1_V	0x3c /* for future use to support other formats */ 
	#define BITFIELD_ADI_ADI_FBUF1_V	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF2_Y	0x40 /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 2nd frame */ 
	#define BITFIELD_ADI_ADI_FBUF2_Y	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF2_U	0x44 /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 2nd frame */ 
	#define BITFIELD_ADI_ADI_FBUF2_U	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF2_V	0x48 /* for future use to support other formats */ 
	#define BITFIELD_ADI_ADI_FBUF2_V	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF3_Y	0x4c /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 3rd frame */ 
	#define BITFIELD_ADI_ADI_FBUF3_Y	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF3_U	0x50 /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 3rd frame */ 
	#define BITFIELD_ADI_ADI_FBUF3_U	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF3_V	0x54 /* for future use to support other formats */ 
	#define BITFIELD_ADI_ADI_FBUF3_V	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF4_Y	0x58 /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 4th frame */ 
	#define BITFIELD_ADI_ADI_FBUF4_Y	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF4_U	0x5c /* ADI maintains 4 frame buffers and round robins around them. This is the dram address to which ADI writes luma of the 4th frame */ 
	#define BITFIELD_ADI_ADI_FBUF4_U	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FBUF4_V	0x60 /* for future use to support other formats */ 
	#define BITFIELD_ADI_ADI_FBUF4_V	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FRONT_Y	0x64 /* This is a shift register implementation that moves the back buffer to the front every codec flip. */ 
	#define BITFIELD_ADI_ADI_FRONT_Y	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FRONT_U	0x68 /* This is a shift register implementation that moves the back buffer to the front every codec flip. */ 
	#define BITFIELD_ADI_ADI_FRONT_U	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_ADI_FRONT_V	0x6c /* for future use to support other formats */ 
	#define BITFIELD_ADI_ADI_FRONT_V	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_SCRATCH0	0x70 /* Scratch Register 0 */ 
	#define BITFIELD_ADI_SCRATCH0	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_SCRATCH1	0x74 /* Scratch Register 1 */ 
	#define BITFIELD_ADI_SCRATCH1	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_SCRATCH2	0x78 /* Scratch Register 2 */ 
	#define BITFIELD_ADI_SCRATCH2	 0x0078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_OLY_FLIP_MODE	0x90 /* Overlay Flip Mode */ 
	#define BITFIELD_ADI_OLY_FLIP_MODE	 0x0090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_OLY_BUF0_Y	0x94 /* Luma Back Buffer */ 
	#define BITFIELD_ADI_OLY_BUF0_Y	 0x0094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_OLY_BUF0_U	0x98 /* Chroma Back Buffer */ 
	#define BITFIELD_ADI_OLY_BUF0_U	 0x0098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_OLY_BUF0_V	0x9c /* For future Use */ 
	#define BITFIELD_ADI_OLY_BUF0_V	 0x009c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_SW_DEBUG	0xe0 /* Overlay Flip Mode */ 
	#define BITFIELD_ADI_SW_DEBUG	 0x00e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_ADI_VDC_TIMEOUT	0xe4 /*  */ 
	#define BITFIELD_ADI_VDC_TIMEOUT	 0x00e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module ADI SPECIFIC SVEN Events */




#endif /* ADI_REGOFFS_H */
