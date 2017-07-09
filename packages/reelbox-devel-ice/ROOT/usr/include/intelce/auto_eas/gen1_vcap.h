#ifndef VCAP_REGOFFS_H
#define VCAP_REGOFFS_H 1
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


/* Module VCAP CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_VCAP_GLOBAL_CTL	0x0 /* VIDEO CAPTURE GLOBAL CONTROL */ 
	#define BITFIELD_VCAP_GLOBAL_CTL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_GLOBAL_CTL */
	#define BLSB_VCAP_GLOBAL_CTL_RESERVED	3
	#define BLSB_VCAP_GLOBAL_CTL_BT656_LLC_INVERT_CTL	1
	#define BLSB_VCAP_GLOBAL_CTL_VCAP_ENABLE	0
	/* Register Bit Widths for VCAP_GLOBAL_CTL */
	#define BWID_VCAP_GLOBAL_CTL_RESERVED	29
	#define BWID_VCAP_GLOBAL_CTL_BT656_LLC_INVERT_CTL	1
	#define BWID_VCAP_GLOBAL_CTL_VCAP_ENABLE	1
	/* Register Bit MASKS for VCAP_GLOBAL_CTL */
	#define BMSK_VCAP_GLOBAL_CTL_RESERVED	0xfffffff8 /* RESERVED */
	#define BMSK_VCAP_GLOBAL_CTL_BT656_LLC_INVERT_CTL	(1<<1) /* == 0x00000002: Video Capture Enable */
	#define BMSK_VCAP_GLOBAL_CTL_VCAP_ENABLE	(1<<0) /* == 0x00000001: BT656_LLC clock invert control */
	/* Register BITFIELD for VCAP_GLOBAL_CTL - roff, lsb, width, mask */
	#define BITFIELD_VCAP_GLOBAL_CTL_RESERVED	 0x0000, 3, 29, 0xfffffff8
	#define BITFIELD_VCAP_GLOBAL_CTL_BT656_LLC_INVERT_CTL	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_VCAP_GLOBAL_CTL_VCAP_ENABLE	 0x0000, 0, 1, 0x00000001
#define ROFF_VCAP_INT_STATUS	0x4 /* VIDEO CAPTURE INTERRUPT STATUS */ 
	#define BITFIELD_VCAP_INT_STATUS	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_INT_STATUS */
	#define BLSB_VCAP_INT_STATUS_RESERVED	8
	#define BLSB_VCAP_INT_STATUS_BT656_SYNC_ERROR	7
	#define BLSB_VCAP_INT_STATUS_PDMA_IS_STALLED	6
	#define BLSB_VCAP_INT_STATUS_C_ADDR_OUT_OF_RANGE	5
	#define BLSB_VCAP_INT_STATUS_Y_ADDR_OUT_OF_RANGE	4
	#define BLSB_VCAP_INT_STATUS_BOTTOM_FIELD_DONE1	3
	#define BLSB_VCAP_INT_STATUS_TOP_FIELD_DONE1	2
	#define BLSB_VCAP_INT_STATUS_BOTTOM_FIELD_DONE0	1
	#define BLSB_VCAP_INT_STATUS_TOP_FIELD_DONE0	0
	/* Register Bit Widths for VCAP_INT_STATUS */
	#define BWID_VCAP_INT_STATUS_RESERVED	24
	#define BWID_VCAP_INT_STATUS_BT656_SYNC_ERROR	1
	#define BWID_VCAP_INT_STATUS_PDMA_IS_STALLED	1
	#define BWID_VCAP_INT_STATUS_C_ADDR_OUT_OF_RANGE	1
	#define BWID_VCAP_INT_STATUS_Y_ADDR_OUT_OF_RANGE	1
	#define BWID_VCAP_INT_STATUS_BOTTOM_FIELD_DONE1	1
	#define BWID_VCAP_INT_STATUS_TOP_FIELD_DONE1	1
	#define BWID_VCAP_INT_STATUS_BOTTOM_FIELD_DONE0	1
	#define BWID_VCAP_INT_STATUS_TOP_FIELD_DONE0	1
	/* Register Bit MASKS for VCAP_INT_STATUS */
	#define BMSK_VCAP_INT_STATUS_RESERVED	0xffffff00 /* RESERVED */
	#define BMSK_VCAP_INT_STATUS_BT656_SYNC_ERROR	(1<<7) /* == 0x00000080: BT656 Sync Error */
	#define BMSK_VCAP_INT_STATUS_PDMA_IS_STALLED	(1<<6) /* == 0x00000040: Pixel DMA is stalled */
	#define BMSK_VCAP_INT_STATUS_C_ADDR_OUT_OF_RANGE	(1<<5) /* == 0x00000020: Chroma address out of range */
	#define BMSK_VCAP_INT_STATUS_Y_ADDR_OUT_OF_RANGE	(1<<4) /* == 0x00000010: Luma address out of range */
	#define BMSK_VCAP_INT_STATUS_BOTTOM_FIELD_DONE1	(1<<3) /* == 0x00000008: Frame buffer 1 bottom field done */
	#define BMSK_VCAP_INT_STATUS_TOP_FIELD_DONE1	(1<<2) /* == 0x00000004: Frame buffer 1 top field done */
	#define BMSK_VCAP_INT_STATUS_BOTTOM_FIELD_DONE0	(1<<1) /* == 0x00000002: Frame buffer 0 bottom field done */
	#define BMSK_VCAP_INT_STATUS_TOP_FIELD_DONE0	(1<<0) /* == 0x00000001: Frame buffer 0 top field done */
	/* Register BITFIELD for VCAP_INT_STATUS - roff, lsb, width, mask */
	#define BITFIELD_VCAP_INT_STATUS_RESERVED	 0x0004, 8, 24, 0xffffff00
	#define BITFIELD_VCAP_INT_STATUS_BT656_SYNC_ERROR	 0x0004, 7, 1, 0x00000080
	#define BITFIELD_VCAP_INT_STATUS_PDMA_IS_STALLED	 0x0004, 6, 1, 0x00000040
	#define BITFIELD_VCAP_INT_STATUS_C_ADDR_OUT_OF_RANGE	 0x0004, 5, 1, 0x00000020
	#define BITFIELD_VCAP_INT_STATUS_Y_ADDR_OUT_OF_RANGE	 0x0004, 4, 1, 0x00000010
	#define BITFIELD_VCAP_INT_STATUS_BOTTOM_FIELD_DONE1	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_VCAP_INT_STATUS_TOP_FIELD_DONE1	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_VCAP_INT_STATUS_BOTTOM_FIELD_DONE0	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_VCAP_INT_STATUS_TOP_FIELD_DONE0	 0x0004, 0, 1, 0x00000001
#define ROFF_VCAP_INT_MASK	0x8 /* VIDEO CAPTURE INTERRUPT MASK */ 
	#define BITFIELD_VCAP_INT_MASK	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_BT656_CTL	0xc /* VIDEO CAPTURE BT.656 DECODER CONTROL */ 
	#define BITFIELD_VCAP_BT656_CTL	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_BT656_CTL */
	#define BLSB_VCAP_BT656_CTL_RESERVED	8
	#define BLSB_VCAP_BT656_CTL_PGEN_MODE	4
	#define BLSB_VCAP_BT656_CTL_PGEN_EN	3
	#define BLSB_VCAP_BT656_CTL_BT656_IN_DISABLE	2
	#define BLSB_VCAP_BT656_CTL_SWAP_MODE	0
	/* Register Bit Widths for VCAP_BT656_CTL */
	#define BWID_VCAP_BT656_CTL_RESERVED	24
	#define BWID_VCAP_BT656_CTL_PGEN_MODE	4
	#define BWID_VCAP_BT656_CTL_PGEN_EN	1
	#define BWID_VCAP_BT656_CTL_BT656_IN_DISABLE	1
	#define BWID_VCAP_BT656_CTL_SWAP_MODE	2
	/* Register Bit MASKS for VCAP_BT656_CTL */
	#define BMSK_VCAP_BT656_CTL_RESERVED	0xffffff00 /* RESERVED */
	#define BMSK_VCAP_BT656_CTL_PGEN_MODE	0x000000f0 /* Video Test Pattern Generator Mode Select */
	#define BMSK_VCAP_BT656_CTL_PGEN_EN	(1<<3) /* == 0x00000008: Video Test Pattern Generator Enable */
	#define BMSK_VCAP_BT656_CTL_BT656_IN_DISABLE	(1<<2) /* == 0x00000004: BT.656 Input Disable */
	#define BMSK_VCAP_BT656_CTL_SWAP_MODE	0x00000003 /* BT.656 Decoder Luma/Chroma Swap Mode */
	/* Register BITFIELD for VCAP_BT656_CTL - roff, lsb, width, mask */
	#define BITFIELD_VCAP_BT656_CTL_RESERVED	 0x000c, 8, 24, 0xffffff00
	#define BITFIELD_VCAP_BT656_CTL_PGEN_MODE	 0x000c, 4, 4, 0x000000f0
	#define BITFIELD_VCAP_BT656_CTL_PGEN_EN	 0x000c, 3, 1, 0x00000008
	#define BITFIELD_VCAP_BT656_CTL_BT656_IN_DISABLE	 0x000c, 2, 1, 0x00000004
	#define BITFIELD_VCAP_BT656_CTL_SWAP_MODE	 0x000c, 0, 2, 0x00000003
#define ROFF_VCAP_FILTER_CTL	0x10 /* VIDEO CAPTURE 4:2:2-TO-4:2:0 FILTER CONTROL */ 
	#define BITFIELD_VCAP_FILTER_CTL	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_FILTER_VRT_START	0x14 /* VIDEO CAPTURE 4:2:2-TO-4:2:0 FILTER VERTICAL LINE START */ 
	#define BITFIELD_VCAP_FILTER_VRT_START	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_FILTER_VRT_START */
	#define BLSB_VCAP_FILTER_VRT_START_RESERVED_0	26
	#define BLSB_VCAP_FILTER_VRT_START_BOTTOM_VRT_START	16
	#define BLSB_VCAP_FILTER_VRT_START_RESERVED_1	10
	#define BLSB_VCAP_FILTER_VRT_START_TOP_VRT_START	0
	/* Register Bit Widths for VCAP_FILTER_VRT_START */
	#define BWID_VCAP_FILTER_VRT_START_RESERVED_0	6
	#define BWID_VCAP_FILTER_VRT_START_BOTTOM_VRT_START	10
	#define BWID_VCAP_FILTER_VRT_START_RESERVED_1	6
	#define BWID_VCAP_FILTER_VRT_START_TOP_VRT_START	10
	/* Register Bit MASKS for VCAP_FILTER_VRT_START */
	#define BMSK_VCAP_FILTER_VRT_START_RESERVED_0	0xfc000000 /* RESERVED */
	#define BMSK_VCAP_FILTER_VRT_START_BOTTOM_VRT_START	0x03ff0000 /* The starting line number for the top field */
	#define BMSK_VCAP_FILTER_VRT_START_RESERVED_1	0x0000fc00 /* RESERVED */
	#define BMSK_VCAP_FILTER_VRT_START_TOP_VRT_START	0x000003ff /* The starting line number for the bottom field */
	/* Register BITFIELD for VCAP_FILTER_VRT_START - roff, lsb, width, mask */
	#define BITFIELD_VCAP_FILTER_VRT_START_RESERVED_0	 0x0014, 26, 6, 0xfc000000
	#define BITFIELD_VCAP_FILTER_VRT_START_BOTTOM_VRT_START	 0x0014, 16, 10, 0x03ff0000
	#define BITFIELD_VCAP_FILTER_VRT_START_RESERVED_1	 0x0014, 10, 6, 0x0000fc00
	#define BITFIELD_VCAP_FILTER_VRT_START_TOP_VRT_START	 0x0014, 0, 10, 0x000003ff
#define ROFF_VCAP_FILTER_VRT_END	0x18 /* VIDEO CAPTURE 4:2:2-TO-4:2:0 FILTER VERTICAL LINE END */ 
	#define BITFIELD_VCAP_FILTER_VRT_END	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_FILTER_VRT_END */
	#define BLSB_VCAP_FILTER_VRT_END_RESERVED_0	26
	#define BLSB_VCAP_FILTER_VRT_END_BOTTOM_VRT_END	16
	#define BLSB_VCAP_FILTER_VRT_END_RESERVED_1	10
	#define BLSB_VCAP_FILTER_VRT_END_TOP_VRT_END	0
	/* Register Bit Widths for VCAP_FILTER_VRT_END */
	#define BWID_VCAP_FILTER_VRT_END_RESERVED_0	6
	#define BWID_VCAP_FILTER_VRT_END_BOTTOM_VRT_END	10
	#define BWID_VCAP_FILTER_VRT_END_RESERVED_1	6
	#define BWID_VCAP_FILTER_VRT_END_TOP_VRT_END	10
	/* Register Bit MASKS for VCAP_FILTER_VRT_END */
	#define BMSK_VCAP_FILTER_VRT_END_RESERVED_0	0xfc000000 /* RESERVED */
	#define BMSK_VCAP_FILTER_VRT_END_BOTTOM_VRT_END	0x03ff0000 /* The ending line number for the top field */
	#define BMSK_VCAP_FILTER_VRT_END_RESERVED_1	0x0000fc00 /* RESERVED */
	#define BMSK_VCAP_FILTER_VRT_END_TOP_VRT_END	0x000003ff /* The ending line number for the bottom field */
	/* Register BITFIELD for VCAP_FILTER_VRT_END - roff, lsb, width, mask */
	#define BITFIELD_VCAP_FILTER_VRT_END_RESERVED_0	 0x0018, 26, 6, 0xfc000000
	#define BITFIELD_VCAP_FILTER_VRT_END_BOTTOM_VRT_END	 0x0018, 16, 10, 0x03ff0000
	#define BITFIELD_VCAP_FILTER_VRT_END_RESERVED_1	 0x0018, 10, 6, 0x0000fc00
	#define BITFIELD_VCAP_FILTER_VRT_END_TOP_VRT_END	 0x0018, 0, 10, 0x000003ff
#define ROFF_VCAP_PDMA_CTL	0x1c /* VIDEO CAPTURE PIXEL DMA CONTROL */ 
	#define BITFIELD_VCAP_PDMA_CTL	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_PDMA_CTL */
	#define BLSB_VCAP_PDMA_CTL_RESERVED	7
	#define BLSB_VCAP_PDMA_CTL_DMA_XFER_SIZE_SEL	5
	#define BLSB_VCAP_PDMA_CTL_PDMA_STALL	4
	#define BLSB_VCAP_PDMA_CTL_CC_EN	3
	#define BLSB_VCAP_PDMA_CTL_BIG_ENDIAN	2
	#define BLSB_VCAP_PDMA_CTL_PDMA_FIFO_AUTO_FLUSH_DIS	1
	#define BLSB_VCAP_PDMA_CTL_PROGRESSIVE	0
	/* Register Bit Widths for VCAP_PDMA_CTL */
	#define BWID_VCAP_PDMA_CTL_RESERVED	25
	#define BWID_VCAP_PDMA_CTL_DMA_XFER_SIZE_SEL	2
	#define BWID_VCAP_PDMA_CTL_PDMA_STALL	1
	#define BWID_VCAP_PDMA_CTL_CC_EN	1
	#define BWID_VCAP_PDMA_CTL_BIG_ENDIAN	1
	#define BWID_VCAP_PDMA_CTL_PDMA_FIFO_AUTO_FLUSH_DIS	1
	#define BWID_VCAP_PDMA_CTL_PROGRESSIVE	1
	/* Register Bit MASKS for VCAP_PDMA_CTL */
	#define BMSK_VCAP_PDMA_CTL_RESERVED	0xffffff80 /* RESERVED */
	#define BMSK_VCAP_PDMA_CTL_DMA_XFER_SIZE_SEL	0x00000060 /* DMA Transfer Size Select */
	#define BMSK_VCAP_PDMA_CTL_PDMA_STALL	(1<<4) /* == 0x00000010: Stall Pixel DMA */
	#define BMSK_VCAP_PDMA_CTL_CC_EN	(1<<3) /* == 0x00000008: Capture closed caption line */
	#define BMSK_VCAP_PDMA_CTL_BIG_ENDIAN	(1<<2) /* == 0x00000004: Big Endian */
	#define BMSK_VCAP_PDMA_CTL_PDMA_FIFO_AUTO_FLUSH_DIS	(1<<1) /* == 0x00000002: Pixel DMA FIFO Auto Flush Disable */
	#define BMSK_VCAP_PDMA_CTL_PROGRESSIVE	(1<<0) /* == 0x00000001: Progressive Scan Mode */
	/* Register BITFIELD for VCAP_PDMA_CTL - roff, lsb, width, mask */
	#define BITFIELD_VCAP_PDMA_CTL_RESERVED	 0x001c, 7, 25, 0xffffff80
	#define BITFIELD_VCAP_PDMA_CTL_DMA_XFER_SIZE_SEL	 0x001c, 5, 2, 0x00000060
	#define BITFIELD_VCAP_PDMA_CTL_PDMA_STALL	 0x001c, 4, 1, 0x00000010
	#define BITFIELD_VCAP_PDMA_CTL_CC_EN	 0x001c, 3, 1, 0x00000008
	#define BITFIELD_VCAP_PDMA_CTL_BIG_ENDIAN	 0x001c, 2, 1, 0x00000004
	#define BITFIELD_VCAP_PDMA_CTL_PDMA_FIFO_AUTO_FLUSH_DIS	 0x001c, 1, 1, 0x00000002
	#define BITFIELD_VCAP_PDMA_CTL_PROGRESSIVE	 0x001c, 0, 1, 0x00000001
#define ROFF_VCAP_Y_ADDR0	0x20 /* CAPTURE LUMA FRAME BUFFER 0 ADDRESS */ 
	#define BITFIELD_VCAP_Y_ADDR0	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_C_ADDR0	0x24 /* CAPTURE CHROMA FRAME BUFFER 0 ADDRESS */ 
	#define BITFIELD_VCAP_C_ADDR0	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_Y_PITCH0	0x28 /* CAPTURE LUMA FRAME BUFFER 0 PITCH */ 
	#define BITFIELD_VCAP_Y_PITCH0	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_C_PITCH0	0x2c /* CAPTURE CHROMA FRAME BUFFER 0 PITCH */ 
	#define BITFIELD_VCAP_C_PITCH0	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_Y_ADDR1	0x30 /* CAPTURE LUMA FRAME BUFFER 1 ADDRESS */ 
	#define BITFIELD_VCAP_Y_ADDR1	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_C_ADDR1	0x34 /* CHROMA FRAME BUFFER 1 ADDRESS */ 
	#define BITFIELD_VCAP_C_ADDR1	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_Y_PITCH1	0x38 /* LUMA FRAME BUFFER 1 PITCH */ 
	#define BITFIELD_VCAP_Y_PITCH1	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_C_PITCH1	0x3c /* CHROMA FRAME BUFFER 1 PITCH */ 
	#define BITFIELD_VCAP_C_PITCH1	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_CC_ADDR0	0x40 /* CLOSED CAPTION BUFFER 0 ADDRESS */ 
	#define BITFIELD_VCAP_CC_ADDR0	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_CC_ADDR1	0x44 /* CLOSED CAPTION BUFFER 1 ADDRESS */ 
	#define BITFIELD_VCAP_CC_ADDR1	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_CC_LINE	0x48 /* CLOSED CAPTION LINE NUMBER */ 
	#define BITFIELD_VCAP_CC_LINE	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_CC_LINE */
	#define BLSB_VCAP_CC_LINE_RESERVED_0	26
	#define BLSB_VCAP_CC_LINE_bottom_cc_line	16
	#define BLSB_VCAP_CC_LINE_RESERVED_1	10
	#define BLSB_VCAP_CC_LINE_top_cc_line	0
	/* Register Bit Widths for VCAP_CC_LINE */
	#define BWID_VCAP_CC_LINE_RESERVED_0	6
	#define BWID_VCAP_CC_LINE_bottom_cc_line	10
	#define BWID_VCAP_CC_LINE_RESERVED_1	6
	#define BWID_VCAP_CC_LINE_top_cc_line	10
	/* Register Bit MASKS for VCAP_CC_LINE */
	#define BMSK_VCAP_CC_LINE_RESERVED_0	0xfc000000 /* RESERVED */
	#define BMSK_VCAP_CC_LINE_bottom_cc_line	0x03ff0000 /* Close caption line number for the top field */
	#define BMSK_VCAP_CC_LINE_RESERVED_1	0x0000fc00 /* RESERVED */
	#define BMSK_VCAP_CC_LINE_top_cc_line	0x000003ff /* Close caption line number for the bottom field */
	/* Register BITFIELD for VCAP_CC_LINE - roff, lsb, width, mask */
	#define BITFIELD_VCAP_CC_LINE_RESERVED_0	 0x0048, 26, 6, 0xfc000000
	#define BITFIELD_VCAP_CC_LINE_bottom_cc_line	 0x0048, 16, 10, 0x03ff0000
	#define BITFIELD_VCAP_CC_LINE_RESERVED_1	 0x0048, 10, 6, 0x0000fc00
	#define BITFIELD_VCAP_CC_LINE_top_cc_line	 0x0048, 0, 10, 0x000003ff
#define ROFF_VCAP_CROP_VRT_START	0x4c /* VERTICAL CROP LINE START */ 
	#define BITFIELD_VCAP_CROP_VRT_START	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_CROP_VRT_START */
	#define BLSB_VCAP_CROP_VRT_START_RESERVED_0	26
	#define BLSB_VCAP_CROP_VRT_START_BOTTOM_VRT_START	16
	#define BLSB_VCAP_CROP_VRT_START_RESERVED_1	10
	#define BLSB_VCAP_CROP_VRT_START_TOP_VRT_START	0
	/* Register Bit Widths for VCAP_CROP_VRT_START */
	#define BWID_VCAP_CROP_VRT_START_RESERVED_0	6
	#define BWID_VCAP_CROP_VRT_START_BOTTOM_VRT_START	10
	#define BWID_VCAP_CROP_VRT_START_RESERVED_1	6
	#define BWID_VCAP_CROP_VRT_START_TOP_VRT_START	10
	/* Register Bit MASKS for VCAP_CROP_VRT_START */
	#define BMSK_VCAP_CROP_VRT_START_RESERVED_0	0xfc000000 /* RESERVED */
	#define BMSK_VCAP_CROP_VRT_START_BOTTOM_VRT_START	0x03ff0000 /* The starting line number for the top field */
	#define BMSK_VCAP_CROP_VRT_START_RESERVED_1	0x0000fc00 /* RESERVED */
	#define BMSK_VCAP_CROP_VRT_START_TOP_VRT_START	0x000003ff /* The starting line number for the bottom field */
	/* Register BITFIELD for VCAP_CROP_VRT_START - roff, lsb, width, mask */
	#define BITFIELD_VCAP_CROP_VRT_START_RESERVED_0	 0x004c, 26, 6, 0xfc000000
	#define BITFIELD_VCAP_CROP_VRT_START_BOTTOM_VRT_START	 0x004c, 16, 10, 0x03ff0000
	#define BITFIELD_VCAP_CROP_VRT_START_RESERVED_1	 0x004c, 10, 6, 0x0000fc00
	#define BITFIELD_VCAP_CROP_VRT_START_TOP_VRT_START	 0x004c, 0, 10, 0x000003ff
#define ROFF_VCAP_CROP_VRT_END	0x50 /* VERTICAL CROP LINE END */ 
	#define BITFIELD_VCAP_CROP_VRT_END	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VCAP_CROP_VRT_END */
	#define BLSB_VCAP_CROP_VRT_END_RESERVED_0	26
	#define BLSB_VCAP_CROP_VRT_END_BOTTOM_VRT_END	16
	#define BLSB_VCAP_CROP_VRT_END_RESERVED_1	10
	#define BLSB_VCAP_CROP_VRT_END_TOP_VRT_END	0
	/* Register Bit Widths for VCAP_CROP_VRT_END */
	#define BWID_VCAP_CROP_VRT_END_RESERVED_0	6
	#define BWID_VCAP_CROP_VRT_END_BOTTOM_VRT_END	10
	#define BWID_VCAP_CROP_VRT_END_RESERVED_1	6
	#define BWID_VCAP_CROP_VRT_END_TOP_VRT_END	10
	/* Register Bit MASKS for VCAP_CROP_VRT_END */
	#define BMSK_VCAP_CROP_VRT_END_RESERVED_0	0xfc000000 /* RESERVED */
	#define BMSK_VCAP_CROP_VRT_END_BOTTOM_VRT_END	0x03ff0000 /* The ending line number for the top field */
	#define BMSK_VCAP_CROP_VRT_END_RESERVED_1	0x0000fc00 /* RESERVED */
	#define BMSK_VCAP_CROP_VRT_END_TOP_VRT_END	0x000003ff /* The ending line number for the bottom field */
	/* Register BITFIELD for VCAP_CROP_VRT_END - roff, lsb, width, mask */
	#define BITFIELD_VCAP_CROP_VRT_END_RESERVED_0	 0x0050, 26, 6, 0xfc000000
	#define BITFIELD_VCAP_CROP_VRT_END_BOTTOM_VRT_END	 0x0050, 16, 10, 0x03ff0000
	#define BITFIELD_VCAP_CROP_VRT_END_RESERVED_1	 0x0050, 10, 6, 0x0000fc00
	#define BITFIELD_VCAP_CROP_VRT_END_TOP_VRT_END	 0x0050, 0, 10, 0x000003ff
#define ROFF_VCAP_CROP_HRZ_START	0x54 /* HORIZONTAL CROP PIXEL START */ 
	#define BITFIELD_VCAP_CROP_HRZ_START	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_CROP_HRZ_END	0x58 /* HORIZONTAL CROP PIXEL END */ 
	#define BITFIELD_VCAP_CROP_HRZ_END	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_CTL	0x5c /* TIME STAMP CONTROL */ 
	#define BITFIELD_VCAP_TS_CTL	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_PRELOAD_LSB	0x60 /* TIME STAMP PRELOAD LSB */ 
	#define BITFIELD_VCAP_TS_PRELOAD_LSB	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_PRELOAD_MSB	0x64 /* TIME STAMP PRELOAD MSB */ 
	#define BITFIELD_VCAP_TS_PRELOAD_MSB	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_LSB0	0x68 /* TIMESTAMP LSB BUFFER 0 */ 
	#define BITFIELD_VCAP_TS_LSB0	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_MSB0	0x6c /* TIMESTAMP MSB BUFFER 0 */ 
	#define BITFIELD_VCAP_TS_MSB0	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_LSB1	0x70 /* TIMESTAMP LSB BUFFER 1 */ 
	#define BITFIELD_VCAP_TS_LSB1	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_MSB1	0x74 /* TIMESTAMP MSB BUFFER 1 */ 
	#define BITFIELD_VCAP_TS_MSB1	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_COUNTER_LSB	0x78 /* TIMESTAMP COUNTER LSB */ 
	#define BITFIELD_VCAP_TS_COUNTER_LSB	 0x0078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TS_COUNTER_MSB	0x7c /* TIMESTAMP COUNTER MSB */ 
	#define BITFIELD_VCAP_TS_COUNTER_MSB	 0x007c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_CTL	0x80 /* SCD CONTROL */ 
	#define BITFIELD_VCAP_SCD_CTL	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_MIN_MAX_TOP0	0x84 /* SCENE CHANGE DETECTION AVG/MIN/MAX TOP FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_AVG_MIN_MAX_TOP0	 0x0084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_HRZ_GRAD_TOP0	0x88 /* SCENE CHANGE DETECTION AVERAGE HORIZONTAL GRADIENT TOP FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_AVG_HRZ_GRAD_TOP0	 0x0088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_SUM_GRAD_TOP0	0x8c /* SCENE CHANGE DETECTION SUM OF HORIZONTAL GRADIENTS TOP FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_SUM_GRAD_TOP0	 0x008c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_NUM_GRAD_TOP0	0x90 /* SCENE CHANGE DETECTION NUMBER OF HORIZONTAL GRADIENTS TOP FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_NUM_GRAD_TOP0	 0x0090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_MIN_MAX_BOTTOM0	0x94 /* SCENE CHANGE DETECTION AVG/MIN/MAX BOTTOM FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_AVG_MIN_MAX_BOTTOM0	 0x0094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_HRZ_GRAD_BOTTOM0	0x98 /* SCENE CHANGE DETECTION AVERAGE HORIZONTAL GRADIENT BOTTOM FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_AVG_HRZ_GRAD_BOTTOM0	 0x0098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_SUM_GRAD_BOTTOM0	0x9c /* SCENE CHANGE DETECTION SUM OF HORIZONTAL GRADIENTS BOTTOM FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_SUM_GRAD_BOTTOM0	 0x009c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_NUM_GRAD_BOTTOM0	0xa0 /* SCENE CHANGE DETECTION NUMBER OF HORIZONTAL GRADIENTS BOTTOM FIELD BUFFER 0 */ 
	#define BITFIELD_VCAP_SCD_NUM_GRAD_BOTTOM0	 0x00a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_MIN_MAX_TOP1	0xa4 /* SCENE CHANGE DETECTION AVG/MIN/MAX TOP FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_AVG_MIN_MAX_TOP1	 0x00a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_HRZ_GRAD_TOP1	0xa8 /* SCENE CHANGE DETECTION AVERAGE HORIZONTAL GRADIENT TOP FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_AVG_HRZ_GRAD_TOP1	 0x00a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_SUM_GRAD_TOP1	0xac /* SCENE CHANGE DETECTION SUM OF HORIZONTAL GRADIENTS TOP FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_SUM_GRAD_TOP1	 0x00ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_NUM_GRAD_TOP1	0xb0 /* SCENE CHANGE DETECTION NUMBER OF HORIZONTAL GRADIENTS TOP FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_NUM_GRAD_TOP1	 0x00b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_MIN_MAX_BOTTOM1	0xb4 /* SCENE CHANGE DETECTION AVG/MIN/MAX BOTTOM FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_AVG_MIN_MAX_BOTTOM1	 0x00b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_AVG_HRZ_GRAD_BOTTOM1	0xb8 /* SCENE CHANGE DETECTION AVERAGE HORIZONTAL GRADIENT BOTTOM FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_AVG_HRZ_GRAD_BOTTOM1	 0x00b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_SUM_GRAD_BOTTOM1	0xbc /* SCENE CHANGE DETECTION SUM OF HORIZONTAL GRADIENTS BOTTOM FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_SUM_GRAD_BOTTOM1	 0x00bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_NUM_GRAD_BOTTOM1	0xc0 /* SCENE CHANGE DETECTION NUMBER OF HORIZONTAL GRADIENTS BOTTOM FIELD BUFFER 1 */ 
	#define BITFIELD_VCAP_SCD_NUM_GRAD_BOTTOM1	 0x00c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_SCD_THRESHOLD	0xc4 /* SCENE CHANGE DETECTION HORIZONTAL GRADIENT THRESHOLD */ 
	#define BITFIELD_VCAP_SCD_THRESHOLD	 0x00c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TEST0	0xc8 /* TEST REGISTER 0 */ 
	#define BITFIELD_VCAP_TEST0	 0x00c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TEST1	0xcc /* TEST REGISTER 1 */ 
	#define BITFIELD_VCAP_TEST1	 0x00cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TEST2	0xd0 /* TEST REGISTER 2 */ 
	#define BITFIELD_VCAP_TEST2	 0x00d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VCAP_TEST3	0xd4 /* TEST REGISTER 3 */ 
	#define BITFIELD_VCAP_TEST3	 0x00d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module VCAP SPECIFIC SVEN Events */




#endif /* VCAP_REGOFFS_H */
