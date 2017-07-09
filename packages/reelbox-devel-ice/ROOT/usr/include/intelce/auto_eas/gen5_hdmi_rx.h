#ifndef HDMI_RX_REGOFFS_H
#define HDMI_RX_REGOFFS_H 1
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


/* Module HDMI_RX CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_HDMI_RX_AU_CURR_DESCR	0x8 /* DMA Audio CURR_DESCR Register                     */ 
	#define BITFIELD_HDMI_RX_AU_CURR_DESCR	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_AU_NEXT_DESCR	0xc /* DMA Audio NEXT_DESCR Register                     */ 
	#define BITFIELD_HDMI_RX_AU_NEXT_DESCR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_AU_SRCDMA_START	0x10 /* DMA Audio SRCDMA_START Register                   */ 
	#define BITFIELD_HDMI_RX_AU_SRCDMA_START	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_AU_DSTDMA_START	0x14 /* DMA Audio DSTDMA_START Register                   */ 
	#define BITFIELD_HDMI_RX_AU_DSTDMA_START	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_AU_SRCDMA_SIZE	0x18 /* DMA Audio SRCDMA_SIZE Register                    */ 
	#define BITFIELD_HDMI_RX_AU_SRCDMA_SIZE	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_AU_FLAGS_MODE	0x1c /* DMA Audio FLAGS_MODE Register                     */ 
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_FLAGS_MODE */
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_ACTIVE	31
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_SRC_INT	30
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_DST_INT	29
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_TERM	28
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_RSVD1	20
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_XDMA_GAP	16
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_XBURST_SZ	12
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_BURST_SZ	8
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_READ_EN	7
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_WRITE_EN	3
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_HDMI_RX_AU_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for HDMI_RX_AU_FLAGS_MODE */
	#define BWID_HDMI_RX_AU_FLAGS_MODE_ACTIVE	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_SRC_INT	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_DST_INT	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_TERM	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_RSVD1	4
	#define BWID_HDMI_RX_AU_FLAGS_MODE_XDMA_GAP	4
	#define BWID_HDMI_RX_AU_FLAGS_MODE_XBURST_SZ	4
	#define BWID_HDMI_RX_AU_FLAGS_MODE_BURST_SZ	4
	#define BWID_HDMI_RX_AU_FLAGS_MODE_READ_EN	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_HDMI_RX_AU_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_WRITE_EN	1
	#define BWID_HDMI_RX_AU_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_HDMI_RX_AU_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for HDMI_RX_AU_FLAGS_MODE */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_ACTIVE	(1<<31) /* == 0x80000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_SRC_INT	(1<<30) /* == 0x40000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_DST_INT	(1<<29) /* == 0x20000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_TERM	(1<<28) /* == 0x10000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_RSVD1	0x00f00000 /*  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_XDMA_GAP	0x000f0000 /*  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_XBURST_SZ	0x0000f000 /*  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_BURST_SZ	0x00000f00 /*  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /*  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /*  */
	#define BMSK_HDMI_RX_AU_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_AU_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_ACTIVE	 0x001c, 31, 1, 0x80000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_SRC_INT	 0x001c, 30, 1, 0x40000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_DST_INT	 0x001c, 29, 1, 0x20000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_TERM	 0x001c, 28, 1, 0x10000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_RD_SWAP_ENDIAN	 0x001c, 27, 1, 0x08000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_WR_SWAP_ENDIAN	 0x001c, 26, 1, 0x04000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_SRC_ENDIANISM	 0x001c, 25, 1, 0x02000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_DST_ENDIANISM	 0x001c, 24, 1, 0x01000000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_RSVD1	 0x001c, 20, 4, 0x00f00000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_XDMA_GAP	 0x001c, 16, 4, 0x000f0000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_XBURST_SZ	 0x001c, 12, 4, 0x0000f000
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_BURST_SZ	 0x001c, 8, 4, 0x00000f00
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_READ_EN	 0x001c, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_SRC_ADDR_MODE	 0x001c, 5, 2, 0x00000060
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_SRC_LINK_LIST	 0x001c, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_WRITE_EN	 0x001c, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_DST_ADDR_MODE	 0x001c, 1, 2, 0x00000006
	#define BITFIELD_HDMI_RX_AU_FLAGS_MODE_DST_LINK_LIST	 0x001c, 0, 1, 0x00000001
#define ROFF_HDMI_RX_AU_OTHER_MODE	0x20 /* DMA Audio OTHER_MODE Register                     */ 
	#define BITFIELD_HDMI_RX_AU_OTHER_MODE	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_OTHER_MODE */
	#define BLSB_HDMI_RX_AU_OTHER_MODE_RSVD1	1
	#define BLSB_HDMI_RX_AU_OTHER_MODE_STOP	0
	/* Register Bit Widths for HDMI_RX_AU_OTHER_MODE */
	#define BWID_HDMI_RX_AU_OTHER_MODE_RSVD1	31
	#define BWID_HDMI_RX_AU_OTHER_MODE_STOP	1
	/* Register Bit MASKS for HDMI_RX_AU_OTHER_MODE */
	#define BMSK_HDMI_RX_AU_OTHER_MODE_RSVD1	0xfffffffe /*  */
	#define BMSK_HDMI_RX_AU_OTHER_MODE_STOP	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_AU_OTHER_MODE - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_OTHER_MODE_RSVD1	 0x0020, 1, 31, 0xfffffffe
	#define BITFIELD_HDMI_RX_AU_OTHER_MODE_STOP	 0x0020, 0, 1, 0x00000001
#define ROFF_HDMI_RX_AU_DSTDMA_BOT	0x2c /* DMA Audio DSTDMA_BOT Register                     */ 
	#define BITFIELD_HDMI_RX_AU_DSTDMA_BOT	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_DSTDMA_BOT */
	#define BLSB_HDMI_RX_AU_DSTDMA_BOT_DSTDMA_BOT	2
	#define BLSB_HDMI_RX_AU_DSTDMA_BOT_RSVD1	0
	/* Register Bit Widths for HDMI_RX_AU_DSTDMA_BOT */
	#define BWID_HDMI_RX_AU_DSTDMA_BOT_DSTDMA_BOT	31
	#define BWID_HDMI_RX_AU_DSTDMA_BOT_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_AU_DSTDMA_BOT */
	#define BMSK_HDMI_RX_AU_DSTDMA_BOT_DSTDMA_BOT	0xfffffffc /*  */
	#define BMSK_HDMI_RX_AU_DSTDMA_BOT_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_AU_DSTDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_DSTDMA_BOT_DSTDMA_BOT	 0x002c, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_AU_DSTDMA_BOT_RSVD1	 0x002c, 0, 2, 0x00000003
#define ROFF_HDMI_RX_AU_DSTDMA_TOP	0x30 /* DMA Audio DSTDMA_TOP Register                     */ 
	#define BITFIELD_HDMI_RX_AU_DSTDMA_TOP	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_DSTDMA_TOP */
	#define BLSB_HDMI_RX_AU_DSTDMA_TOP_DSTDMA_TOP	2
	#define BLSB_HDMI_RX_AU_DSTDMA_TOP_RSVD1	0
	/* Register Bit Widths for HDMI_RX_AU_DSTDMA_TOP */
	#define BWID_HDMI_RX_AU_DSTDMA_TOP_DSTDMA_TOP	31
	#define BWID_HDMI_RX_AU_DSTDMA_TOP_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_AU_DSTDMA_TOP */
	#define BMSK_HDMI_RX_AU_DSTDMA_TOP_DSTDMA_TOP	0xfffffffc /*  */
	#define BMSK_HDMI_RX_AU_DSTDMA_TOP_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_AU_DSTDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_DSTDMA_TOP_DSTDMA_TOP	 0x0030, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_AU_DSTDMA_TOP_RSVD1	 0x0030, 0, 2, 0x00000003
#define ROFF_HDMI_RX_AU_DSTDMA_SIZE	0x34 /* DMA Audio DSTDMA_SIZE Register                    */ 
	#define BITFIELD_HDMI_RX_AU_DSTDMA_SIZE	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_DSTDMA_SIZE */
	#define BLSB_HDMI_RX_AU_DSTDMA_SIZE_DSTDMA_SIZE	2
	#define BLSB_HDMI_RX_AU_DSTDMA_SIZE_RSVD1	0
	/* Register Bit Widths for HDMI_RX_AU_DSTDMA_SIZE */
	#define BWID_HDMI_RX_AU_DSTDMA_SIZE_DSTDMA_SIZE	31
	#define BWID_HDMI_RX_AU_DSTDMA_SIZE_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_AU_DSTDMA_SIZE */
	#define BMSK_HDMI_RX_AU_DSTDMA_SIZE_DSTDMA_SIZE	0xfffffffc /*  */
	#define BMSK_HDMI_RX_AU_DSTDMA_SIZE_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_AU_DSTDMA_SIZE - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_DSTDMA_SIZE_DSTDMA_SIZE	 0x0034, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_AU_DSTDMA_SIZE_RSVD1	 0x0034, 0, 2, 0x00000003
#define ROFF_HDMI_RX_AU_DSTDMA_STOP	0x3c /* DMA Audio DSTDMA_STOP Register                    */ 
	#define BITFIELD_HDMI_RX_AU_DSTDMA_STOP	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_DSTDMA_STOP */
	#define BLSB_HDMI_RX_AU_DSTDMA_STOP_DSTDMA_STOP	2
	#define BLSB_HDMI_RX_AU_DSTDMA_STOP_RSVD1	0
	/* Register Bit Widths for HDMI_RX_AU_DSTDMA_STOP */
	#define BWID_HDMI_RX_AU_DSTDMA_STOP_DSTDMA_STOP	31
	#define BWID_HDMI_RX_AU_DSTDMA_STOP_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_AU_DSTDMA_STOP */
	#define BMSK_HDMI_RX_AU_DSTDMA_STOP_DSTDMA_STOP	0xfffffffc /*  */
	#define BMSK_HDMI_RX_AU_DSTDMA_STOP_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_AU_DSTDMA_STOP - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_DSTDMA_STOP_DSTDMA_STOP	 0x003c, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_AU_DSTDMA_STOP_RSVD1	 0x003c, 0, 2, 0x00000003
#define ROFF_HDMI_RX_IF_CURR_DESCR	0x48 /* DMA InfoFrame CURR_DESCR Register                 */ 
	#define BITFIELD_HDMI_RX_IF_CURR_DESCR	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_IF_NEXT_DESCR	0x4c /* DMA InfoFrame NEXT_DESCR Register                 */ 
	#define BITFIELD_HDMI_RX_IF_NEXT_DESCR	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_IF_SRCDMA_START	0x50 /* DMA InfoFrame SRCDMA_START Register               */ 
	#define BITFIELD_HDMI_RX_IF_SRCDMA_START	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_IF_DSTDMA_START	0x54 /* DMA InfoFrame DSTDMA_START Register               */ 
	#define BITFIELD_HDMI_RX_IF_DSTDMA_START	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_IF_SRCDMA_SIZE	0x58 /* DMA InfoFrame SRCDMA_SIZE Register                */ 
	#define BITFIELD_HDMI_RX_IF_SRCDMA_SIZE	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_IF_FLAGS_MODE	0x5c /* DMA InfoFrame FLAGS_MODE Register                 */ 
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_FLAGS_MODE */
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_ACTIVE	31
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_SRC_INT	30
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_DST_INT	29
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_TERM	28
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_RD_SWAP_ENDIAN	27
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_WR_SWAP_ENDIAN	26
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_SRC_ENDIANISM	25
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_DST_ENDIANISM	24
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_RSVD1	20
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_XDMA_GAP	16
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_XBURST_SZ	12
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_BURST_SZ	8
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_READ_EN	7
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_SRC_ADDR_MODE	5
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_SRC_LINK_LIST	4
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_WRITE_EN	3
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_DST_ADDR_MODE	1
	#define BLSB_HDMI_RX_IF_FLAGS_MODE_DST_LINK_LIST	0
	/* Register Bit Widths for HDMI_RX_IF_FLAGS_MODE */
	#define BWID_HDMI_RX_IF_FLAGS_MODE_ACTIVE	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_SRC_INT	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_DST_INT	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_TERM	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_RD_SWAP_ENDIAN	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_WR_SWAP_ENDIAN	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_SRC_ENDIANISM	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_DST_ENDIANISM	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_RSVD1	4
	#define BWID_HDMI_RX_IF_FLAGS_MODE_XDMA_GAP	4
	#define BWID_HDMI_RX_IF_FLAGS_MODE_XBURST_SZ	4
	#define BWID_HDMI_RX_IF_FLAGS_MODE_BURST_SZ	4
	#define BWID_HDMI_RX_IF_FLAGS_MODE_READ_EN	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_SRC_ADDR_MODE	2
	#define BWID_HDMI_RX_IF_FLAGS_MODE_SRC_LINK_LIST	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_WRITE_EN	1
	#define BWID_HDMI_RX_IF_FLAGS_MODE_DST_ADDR_MODE	2
	#define BWID_HDMI_RX_IF_FLAGS_MODE_DST_LINK_LIST	1
	/* Register Bit MASKS for HDMI_RX_IF_FLAGS_MODE */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_ACTIVE	(1<<31) /* == 0x80000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_SRC_INT	(1<<30) /* == 0x40000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_DST_INT	(1<<29) /* == 0x20000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_TERM	(1<<28) /* == 0x10000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_RD_SWAP_ENDIAN	(1<<27) /* == 0x08000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_WR_SWAP_ENDIAN	(1<<26) /* == 0x04000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_SRC_ENDIANISM	(1<<25) /* == 0x02000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_DST_ENDIANISM	(1<<24) /* == 0x01000000:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_RSVD1	0x00f00000 /*  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_XDMA_GAP	0x000f0000 /*  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_XBURST_SZ	0x0000f000 /*  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_BURST_SZ	0x00000f00 /*  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_READ_EN	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_SRC_ADDR_MODE	0x00000060 /*  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_SRC_LINK_LIST	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_WRITE_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_DST_ADDR_MODE	0x00000006 /*  */
	#define BMSK_HDMI_RX_IF_FLAGS_MODE_DST_LINK_LIST	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_IF_FLAGS_MODE - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_ACTIVE	 0x005c, 31, 1, 0x80000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_SRC_INT	 0x005c, 30, 1, 0x40000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_DST_INT	 0x005c, 29, 1, 0x20000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_TERM	 0x005c, 28, 1, 0x10000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_RD_SWAP_ENDIAN	 0x005c, 27, 1, 0x08000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_WR_SWAP_ENDIAN	 0x005c, 26, 1, 0x04000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_SRC_ENDIANISM	 0x005c, 25, 1, 0x02000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_DST_ENDIANISM	 0x005c, 24, 1, 0x01000000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_RSVD1	 0x005c, 20, 4, 0x00f00000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_XDMA_GAP	 0x005c, 16, 4, 0x000f0000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_XBURST_SZ	 0x005c, 12, 4, 0x0000f000
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_BURST_SZ	 0x005c, 8, 4, 0x00000f00
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_READ_EN	 0x005c, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_SRC_ADDR_MODE	 0x005c, 5, 2, 0x00000060
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_SRC_LINK_LIST	 0x005c, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_WRITE_EN	 0x005c, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_DST_ADDR_MODE	 0x005c, 1, 2, 0x00000006
	#define BITFIELD_HDMI_RX_IF_FLAGS_MODE_DST_LINK_LIST	 0x005c, 0, 1, 0x00000001
#define ROFF_HDMI_RX_IF_OTHER_MODE	0x60 /* DMA InfoFrame OTHER_MODE Register                 */ 
	#define BITFIELD_HDMI_RX_IF_OTHER_MODE	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_OTHER_MODE */
	#define BLSB_HDMI_RX_IF_OTHER_MODE_RSVD1	1
	#define BLSB_HDMI_RX_IF_OTHER_MODE_STOP	0
	/* Register Bit Widths for HDMI_RX_IF_OTHER_MODE */
	#define BWID_HDMI_RX_IF_OTHER_MODE_RSVD1	31
	#define BWID_HDMI_RX_IF_OTHER_MODE_STOP	1
	/* Register Bit MASKS for HDMI_RX_IF_OTHER_MODE */
	#define BMSK_HDMI_RX_IF_OTHER_MODE_RSVD1	0xfffffffe /*  */
	#define BMSK_HDMI_RX_IF_OTHER_MODE_STOP	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_IF_OTHER_MODE - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_OTHER_MODE_RSVD1	 0x0060, 1, 31, 0xfffffffe
	#define BITFIELD_HDMI_RX_IF_OTHER_MODE_STOP	 0x0060, 0, 1, 0x00000001
#define ROFF_HDMI_RX_IF_DSTDMA_BOT	0x6c /* DMA InfoFrame DSTDMA_BOT Register                 */ 
	#define BITFIELD_HDMI_RX_IF_DSTDMA_BOT	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_DSTDMA_BOT */
	#define BLSB_HDMI_RX_IF_DSTDMA_BOT_DSTDMA_BOT	2
	#define BLSB_HDMI_RX_IF_DSTDMA_BOT_RSVD1	0
	/* Register Bit Widths for HDMI_RX_IF_DSTDMA_BOT */
	#define BWID_HDMI_RX_IF_DSTDMA_BOT_DSTDMA_BOT	31
	#define BWID_HDMI_RX_IF_DSTDMA_BOT_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_IF_DSTDMA_BOT */
	#define BMSK_HDMI_RX_IF_DSTDMA_BOT_DSTDMA_BOT	0xfffffffc /*  */
	#define BMSK_HDMI_RX_IF_DSTDMA_BOT_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_IF_DSTDMA_BOT - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_DSTDMA_BOT_DSTDMA_BOT	 0x006c, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_IF_DSTDMA_BOT_RSVD1	 0x006c, 0, 2, 0x00000003
#define ROFF_HDMI_RX_IF_DSTDMA_TOP	0x70 /* DMA InfoFrame DSTDMA_TOP Register                 */ 
	#define BITFIELD_HDMI_RX_IF_DSTDMA_TOP	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_DSTDMA_TOP */
	#define BLSB_HDMI_RX_IF_DSTDMA_TOP_DSTDMA_TOP	2
	#define BLSB_HDMI_RX_IF_DSTDMA_TOP_RSVD1	0
	/* Register Bit Widths for HDMI_RX_IF_DSTDMA_TOP */
	#define BWID_HDMI_RX_IF_DSTDMA_TOP_DSTDMA_TOP	31
	#define BWID_HDMI_RX_IF_DSTDMA_TOP_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_IF_DSTDMA_TOP */
	#define BMSK_HDMI_RX_IF_DSTDMA_TOP_DSTDMA_TOP	0xfffffffc /*  */
	#define BMSK_HDMI_RX_IF_DSTDMA_TOP_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_IF_DSTDMA_TOP - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_DSTDMA_TOP_DSTDMA_TOP	 0x0070, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_IF_DSTDMA_TOP_RSVD1	 0x0070, 0, 2, 0x00000003
#define ROFF_HDMI_RX_IF_DSTDMA_SIZE	0x74 /* DMA InfoFrame DSTDMA_SIZE Register                */ 
	#define BITFIELD_HDMI_RX_IF_DSTDMA_SIZE	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_DSTDMA_SIZE */
	#define BLSB_HDMI_RX_IF_DSTDMA_SIZE_DSTDMA_SIZE	2
	#define BLSB_HDMI_RX_IF_DSTDMA_SIZE_RSVD1	0
	/* Register Bit Widths for HDMI_RX_IF_DSTDMA_SIZE */
	#define BWID_HDMI_RX_IF_DSTDMA_SIZE_DSTDMA_SIZE	31
	#define BWID_HDMI_RX_IF_DSTDMA_SIZE_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_IF_DSTDMA_SIZE */
	#define BMSK_HDMI_RX_IF_DSTDMA_SIZE_DSTDMA_SIZE	0xfffffffc /*  */
	#define BMSK_HDMI_RX_IF_DSTDMA_SIZE_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_IF_DSTDMA_SIZE - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_DSTDMA_SIZE_DSTDMA_SIZE	 0x0074, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_IF_DSTDMA_SIZE_RSVD1	 0x0074, 0, 2, 0x00000003
#define ROFF_HDMI_RX_IF_DSTDMA_STOP	0x7c /* DMA InfoFrame DSTDMA_STOP Register                */ 
	#define BITFIELD_HDMI_RX_IF_DSTDMA_STOP	 0x007c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_DSTDMA_STOP */
	#define BLSB_HDMI_RX_IF_DSTDMA_STOP_DSTDMA_STOP	2
	#define BLSB_HDMI_RX_IF_DSTDMA_STOP_RSVD1	0
	/* Register Bit Widths for HDMI_RX_IF_DSTDMA_STOP */
	#define BWID_HDMI_RX_IF_DSTDMA_STOP_DSTDMA_STOP	31
	#define BWID_HDMI_RX_IF_DSTDMA_STOP_RSVD1	2
	/* Register Bit MASKS for HDMI_RX_IF_DSTDMA_STOP */
	#define BMSK_HDMI_RX_IF_DSTDMA_STOP_DSTDMA_STOP	0xfffffffc /*  */
	#define BMSK_HDMI_RX_IF_DSTDMA_STOP_RSVD1	0x00000003 /*  */
	/* Register BITFIELD for HDMI_RX_IF_DSTDMA_STOP - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_DSTDMA_STOP_DSTDMA_STOP	 0x007c, 2, 31, 0xfffffffc
	#define BITFIELD_HDMI_RX_IF_DSTDMA_STOP_RSVD1	 0x007c, 0, 2, 0x00000003
#define ROFF_HDMI_RX_AU_FIFO0_THRSH	0x100 /* AU_FIFO0_THRSH Register                           */ 
	#define BITFIELD_HDMI_RX_AU_FIFO0_THRSH	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_FIFO0_THRSH */
	#define BLSB_HDMI_RX_AU_FIFO0_THRSH_RSVD1	8
	#define BLSB_HDMI_RX_AU_FIFO0_THRSH_AU_FIFO0_THRSH	0
	/* Register Bit Widths for HDMI_RX_AU_FIFO0_THRSH */
	#define BWID_HDMI_RX_AU_FIFO0_THRSH_RSVD1	24
	#define BWID_HDMI_RX_AU_FIFO0_THRSH_AU_FIFO0_THRSH	8
	/* Register Bit MASKS for HDMI_RX_AU_FIFO0_THRSH */
	#define BMSK_HDMI_RX_AU_FIFO0_THRSH_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_AU_FIFO0_THRSH_AU_FIFO0_THRSH	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_AU_FIFO0_THRSH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_FIFO0_THRSH_RSVD1	 0x0100, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_AU_FIFO0_THRSH_AU_FIFO0_THRSH	 0x0100, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_IF_FIFO0_THRSH	0x104 /* IF_FIFO0_THRSH Register                           */ 
	#define BITFIELD_HDMI_RX_IF_FIFO0_THRSH	 0x0104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_FIFO0_THRSH */
	#define BLSB_HDMI_RX_IF_FIFO0_THRSH_RSVD1	8
	#define BLSB_HDMI_RX_IF_FIFO0_THRSH_IF_FIFO0_THRSH	0
	/* Register Bit Widths for HDMI_RX_IF_FIFO0_THRSH */
	#define BWID_HDMI_RX_IF_FIFO0_THRSH_RSVD1	24
	#define BWID_HDMI_RX_IF_FIFO0_THRSH_IF_FIFO0_THRSH	8
	/* Register Bit MASKS for HDMI_RX_IF_FIFO0_THRSH */
	#define BMSK_HDMI_RX_IF_FIFO0_THRSH_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_IF_FIFO0_THRSH_IF_FIFO0_THRSH	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_IF_FIFO0_THRSH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_FIFO0_THRSH_RSVD1	 0x0104, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_IF_FIFO0_THRSH_IF_FIFO0_THRSH	 0x0104, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_AU_FIFO0_LVL	0x110 /* AU_FIFO0_LVL Register                             */ 
	#define BITFIELD_HDMI_RX_AU_FIFO0_LVL	 0x0110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_FIFO0_LVL */
	#define BLSB_HDMI_RX_AU_FIFO0_LVL_RSVD1	8
	#define BLSB_HDMI_RX_AU_FIFO0_LVL_AU_FIFO0_LVL	0
	/* Register Bit Widths for HDMI_RX_AU_FIFO0_LVL */
	#define BWID_HDMI_RX_AU_FIFO0_LVL_RSVD1	24
	#define BWID_HDMI_RX_AU_FIFO0_LVL_AU_FIFO0_LVL	8
	/* Register Bit MASKS for HDMI_RX_AU_FIFO0_LVL */
	#define BMSK_HDMI_RX_AU_FIFO0_LVL_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_AU_FIFO0_LVL_AU_FIFO0_LVL	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_AU_FIFO0_LVL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_FIFO0_LVL_RSVD1	 0x0110, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_AU_FIFO0_LVL_AU_FIFO0_LVL	 0x0110, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_IF_FIFO0_LVL	0x114 /* IF_FIFO0_LVL Register                             */ 
	#define BITFIELD_HDMI_RX_IF_FIFO0_LVL	 0x0114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_FIFO0_LVL */
	#define BLSB_HDMI_RX_IF_FIFO0_LVL_RSVD1	8
	#define BLSB_HDMI_RX_IF_FIFO0_LVL_IF_FIFO0_LVL	0
	/* Register Bit Widths for HDMI_RX_IF_FIFO0_LVL */
	#define BWID_HDMI_RX_IF_FIFO0_LVL_RSVD1	24
	#define BWID_HDMI_RX_IF_FIFO0_LVL_IF_FIFO0_LVL	8
	/* Register Bit MASKS for HDMI_RX_IF_FIFO0_LVL */
	#define BMSK_HDMI_RX_IF_FIFO0_LVL_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_IF_FIFO0_LVL_IF_FIFO0_LVL	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_IF_FIFO0_LVL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_FIFO0_LVL_RSVD1	 0x0114, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_IF_FIFO0_LVL_IF_FIFO0_LVL	 0x0114, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_AU_SEC_STAT	0x200 /* AU_SEC_STAT Register                              */ 
	#define BITFIELD_HDMI_RX_AU_SEC_STAT	 0x0200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_SEC_STAT */
	#define BLSB_HDMI_RX_AU_SEC_STAT_RSVD1	1
	#define BLSB_HDMI_RX_AU_SEC_STAT_TTR_EN	0
	/* Register Bit Widths for HDMI_RX_AU_SEC_STAT */
	#define BWID_HDMI_RX_AU_SEC_STAT_RSVD1	31
	#define BWID_HDMI_RX_AU_SEC_STAT_TTR_EN	1
	/* Register Bit MASKS for HDMI_RX_AU_SEC_STAT */
	#define BMSK_HDMI_RX_AU_SEC_STAT_RSVD1	0xfffffffe /*  */
	#define BMSK_HDMI_RX_AU_SEC_STAT_TTR_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_AU_SEC_STAT - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_SEC_STAT_RSVD1	 0x0200, 1, 31, 0xfffffffe
	#define BITFIELD_HDMI_RX_AU_SEC_STAT_TTR_EN	 0x0200, 0, 1, 0x00000001
#define ROFF_HDMI_RX_AU_SEC_TTBA	0x204 /* AU_SEC_TTBA Register                              */ 
	#define BITFIELD_HDMI_RX_AU_SEC_TTBA	 0x0204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_SEC_TTBA */
	#define BLSB_HDMI_RX_AU_SEC_TTBA_BASE_ADDR	12
	#define BLSB_HDMI_RX_AU_SEC_TTBA_RSVD1	1
	#define BLSB_HDMI_RX_AU_SEC_TTBA_LOCK	0
	/* Register Bit Widths for HDMI_RX_AU_SEC_TTBA */
	#define BWID_HDMI_RX_AU_SEC_TTBA_BASE_ADDR	20
	#define BWID_HDMI_RX_AU_SEC_TTBA_RSVD1	11
	#define BWID_HDMI_RX_AU_SEC_TTBA_LOCK	1
	/* Register Bit MASKS for HDMI_RX_AU_SEC_TTBA */
	#define BMSK_HDMI_RX_AU_SEC_TTBA_BASE_ADDR	0xfffff000 /*  */
	#define BMSK_HDMI_RX_AU_SEC_TTBA_RSVD1	0x00000ffe /*  */
	#define BMSK_HDMI_RX_AU_SEC_TTBA_LOCK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_AU_SEC_TTBA - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_SEC_TTBA_BASE_ADDR	 0x0204, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_AU_SEC_TTBA_RSVD1	 0x0204, 1, 11, 0x00000ffe
	#define BITFIELD_HDMI_RX_AU_SEC_TTBA_LOCK	 0x0204, 0, 1, 0x00000001
#define ROFF_HDMI_RX_AU_SEC_TTS	0x208 /* AU_SEC_TTS Register                               */ 
	#define BITFIELD_HDMI_RX_AU_SEC_TTS	 0x0208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_SEC_TTS */
	#define BLSB_HDMI_RX_AU_SEC_TTS_SIZE	12
	#define BLSB_HDMI_RX_AU_SEC_TTS_RSVD1	0
	/* Register Bit Widths for HDMI_RX_AU_SEC_TTS */
	#define BWID_HDMI_RX_AU_SEC_TTS_SIZE	20
	#define BWID_HDMI_RX_AU_SEC_TTS_RSVD1	12
	/* Register Bit MASKS for HDMI_RX_AU_SEC_TTS */
	#define BMSK_HDMI_RX_AU_SEC_TTS_SIZE	0xfffff000 /*  */
	#define BMSK_HDMI_RX_AU_SEC_TTS_RSVD1	0x00000fff /*  */
	/* Register BITFIELD for HDMI_RX_AU_SEC_TTS - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_SEC_TTS_SIZE	 0x0208, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_AU_SEC_TTS_RSVD1	 0x0208, 0, 12, 0x00000fff
#define ROFF_HDMI_RX_AU_SEC_CTRL	0x20c /* AU_SEC_CTRL Register                              */ 
	#define BITFIELD_HDMI_RX_AU_SEC_CTRL	 0x020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_AU_SEC_CTRL */
	#define BLSB_HDMI_RX_AU_SEC_CTRL_RSVD1	3
	#define BLSB_HDMI_RX_AU_SEC_CTRL_ATTR	0
	/* Register Bit Widths for HDMI_RX_AU_SEC_CTRL */
	#define BWID_HDMI_RX_AU_SEC_CTRL_RSVD1	29
	#define BWID_HDMI_RX_AU_SEC_CTRL_ATTR	3
	/* Register Bit MASKS for HDMI_RX_AU_SEC_CTRL */
	#define BMSK_HDMI_RX_AU_SEC_CTRL_RSVD1	0xfffffff8 /*  */
	#define BMSK_HDMI_RX_AU_SEC_CTRL_ATTR	0x00000007 /*  */
	/* Register BITFIELD for HDMI_RX_AU_SEC_CTRL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_AU_SEC_CTRL_RSVD1	 0x020c, 3, 29, 0xfffffff8
	#define BITFIELD_HDMI_RX_AU_SEC_CTRL_ATTR	 0x020c, 0, 3, 0x00000007
#define ROFF_HDMI_RX_IF_SEC_STAT	0x210 /* IF_SEC_STAT Register                              */ 
	#define BITFIELD_HDMI_RX_IF_SEC_STAT	 0x0210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_SEC_STAT */
	#define BLSB_HDMI_RX_IF_SEC_STAT_RSVD1	1
	#define BLSB_HDMI_RX_IF_SEC_STAT_TTR_EN	0
	/* Register Bit Widths for HDMI_RX_IF_SEC_STAT */
	#define BWID_HDMI_RX_IF_SEC_STAT_RSVD1	31
	#define BWID_HDMI_RX_IF_SEC_STAT_TTR_EN	1
	/* Register Bit MASKS for HDMI_RX_IF_SEC_STAT */
	#define BMSK_HDMI_RX_IF_SEC_STAT_RSVD1	0xfffffffe /*  */
	#define BMSK_HDMI_RX_IF_SEC_STAT_TTR_EN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_IF_SEC_STAT - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_SEC_STAT_RSVD1	 0x0210, 1, 31, 0xfffffffe
	#define BITFIELD_HDMI_RX_IF_SEC_STAT_TTR_EN	 0x0210, 0, 1, 0x00000001
#define ROFF_HDMI_RX_IF_SEC_TTBA	0x214 /* IF_SEC_TTBA Register                              */ 
	#define BITFIELD_HDMI_RX_IF_SEC_TTBA	 0x0214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_SEC_TTBA */
	#define BLSB_HDMI_RX_IF_SEC_TTBA_BASE_ADDR	12
	#define BLSB_HDMI_RX_IF_SEC_TTBA_RSVD1	1
	#define BLSB_HDMI_RX_IF_SEC_TTBA_LOCK	0
	/* Register Bit Widths for HDMI_RX_IF_SEC_TTBA */
	#define BWID_HDMI_RX_IF_SEC_TTBA_BASE_ADDR	20
	#define BWID_HDMI_RX_IF_SEC_TTBA_RSVD1	11
	#define BWID_HDMI_RX_IF_SEC_TTBA_LOCK	1
	/* Register Bit MASKS for HDMI_RX_IF_SEC_TTBA */
	#define BMSK_HDMI_RX_IF_SEC_TTBA_BASE_ADDR	0xfffff000 /*  */
	#define BMSK_HDMI_RX_IF_SEC_TTBA_RSVD1	0x00000ffe /*  */
	#define BMSK_HDMI_RX_IF_SEC_TTBA_LOCK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_IF_SEC_TTBA - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_SEC_TTBA_BASE_ADDR	 0x0214, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_IF_SEC_TTBA_RSVD1	 0x0214, 1, 11, 0x00000ffe
	#define BITFIELD_HDMI_RX_IF_SEC_TTBA_LOCK	 0x0214, 0, 1, 0x00000001
#define ROFF_HDMI_RX_IF_SEC_TTS	0x218 /* IF_SEC_TTS Register                               */ 
	#define BITFIELD_HDMI_RX_IF_SEC_TTS	 0x0218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_SEC_TTS */
	#define BLSB_HDMI_RX_IF_SEC_TTS_SIZE	12
	#define BLSB_HDMI_RX_IF_SEC_TTS_RSVD1	0
	/* Register Bit Widths for HDMI_RX_IF_SEC_TTS */
	#define BWID_HDMI_RX_IF_SEC_TTS_SIZE	20
	#define BWID_HDMI_RX_IF_SEC_TTS_RSVD1	12
	/* Register Bit MASKS for HDMI_RX_IF_SEC_TTS */
	#define BMSK_HDMI_RX_IF_SEC_TTS_SIZE	0xfffff000 /*  */
	#define BMSK_HDMI_RX_IF_SEC_TTS_RSVD1	0x00000fff /*  */
	/* Register BITFIELD for HDMI_RX_IF_SEC_TTS - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_SEC_TTS_SIZE	 0x0218, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_IF_SEC_TTS_RSVD1	 0x0218, 0, 12, 0x00000fff
#define ROFF_HDMI_RX_IF_SEC_CTRL	0x21c /* IF_SEC_CTRL Register                              */ 
	#define BITFIELD_HDMI_RX_IF_SEC_CTRL	 0x021c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IF_SEC_CTRL */
	#define BLSB_HDMI_RX_IF_SEC_CTRL_RSVD1	3
	#define BLSB_HDMI_RX_IF_SEC_CTRL_ATTR	0
	/* Register Bit Widths for HDMI_RX_IF_SEC_CTRL */
	#define BWID_HDMI_RX_IF_SEC_CTRL_RSVD1	29
	#define BWID_HDMI_RX_IF_SEC_CTRL_ATTR	3
	/* Register Bit MASKS for HDMI_RX_IF_SEC_CTRL */
	#define BMSK_HDMI_RX_IF_SEC_CTRL_RSVD1	0xfffffff8 /*  */
	#define BMSK_HDMI_RX_IF_SEC_CTRL_ATTR	0x00000007 /*  */
	/* Register BITFIELD for HDMI_RX_IF_SEC_CTRL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IF_SEC_CTRL_RSVD1	 0x021c, 3, 29, 0xfffffff8
	#define BITFIELD_HDMI_RX_IF_SEC_CTRL_ATTR	 0x021c, 0, 3, 0x00000007
#define ROFF_HDMI_RX_HDMI_PWR_CTRL_REG	0x800 /* HDMI_PWR_CTRL_REG Register                        */ 
	#define BITFIELD_HDMI_RX_HDMI_PWR_CTRL_REG	 0x0800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HDMI_PWR_CTRL_REG */
	#define BLSB_HDMI_RX_HDMI_PWR_CTRL_REG_RSVD1	3
	#define BLSB_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDCP_CLK	2
	#define BLSB_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_AU_CLK	1
	#define BLSB_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDMI_CORE_CLK	0
	/* Register Bit Widths for HDMI_RX_HDMI_PWR_CTRL_REG */
	#define BWID_HDMI_RX_HDMI_PWR_CTRL_REG_RSVD1	29
	#define BWID_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDCP_CLK	1
	#define BWID_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_AU_CLK	1
	#define BWID_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDMI_CORE_CLK	1
	/* Register Bit MASKS for HDMI_RX_HDMI_PWR_CTRL_REG */
	#define BMSK_HDMI_RX_HDMI_PWR_CTRL_REG_RSVD1	0xfffffff8 /*  */
	#define BMSK_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDCP_CLK	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_AU_CLK	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDMI_CORE_CLK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HDMI_PWR_CTRL_REG - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HDMI_PWR_CTRL_REG_RSVD1	 0x0800, 3, 29, 0xfffffff8
	#define BITFIELD_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDCP_CLK	 0x0800, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_AU_CLK	 0x0800, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HDMI_PWR_CTRL_REG_GATE_HDMI_CORE_CLK	 0x0800, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HDMI_DEBUG_REG	0x804 /* HDMI_DEBUG_REG Register                           */ 
	#define BITFIELD_HDMI_RX_HDMI_DEBUG_REG	 0x0804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HDMI_DEBUG_REG */
	#define BLSB_HDMI_RX_HDMI_DEBUG_REG_RSVD2	5
	#define BLSB_HDMI_RX_HDMI_DEBUG_REG_SPEED_UP_CNTRS	4
	#define BLSB_HDMI_RX_HDMI_DEBUG_REG_DBG_RI_CHECK	3
	#define BLSB_HDMI_RX_HDMI_DEBUG_REG_RSVD1	1
	#define BLSB_HDMI_RX_HDMI_DEBUG_REG_DBG_EN_CPU_AUTH	0
	/* Register Bit Widths for HDMI_RX_HDMI_DEBUG_REG */
	#define BWID_HDMI_RX_HDMI_DEBUG_REG_RSVD2	27
	#define BWID_HDMI_RX_HDMI_DEBUG_REG_SPEED_UP_CNTRS	1
	#define BWID_HDMI_RX_HDMI_DEBUG_REG_DBG_RI_CHECK	1
	#define BWID_HDMI_RX_HDMI_DEBUG_REG_RSVD1	2
	#define BWID_HDMI_RX_HDMI_DEBUG_REG_DBG_EN_CPU_AUTH	1
	/* Register Bit MASKS for HDMI_RX_HDMI_DEBUG_REG */
	#define BMSK_HDMI_RX_HDMI_DEBUG_REG_RSVD2	0xffffffe0 /*  */
	#define BMSK_HDMI_RX_HDMI_DEBUG_REG_SPEED_UP_CNTRS	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_HDMI_DEBUG_REG_DBG_RI_CHECK	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_HDMI_DEBUG_REG_RSVD1	0x00000006 /*  */
	#define BMSK_HDMI_RX_HDMI_DEBUG_REG_DBG_EN_CPU_AUTH	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HDMI_DEBUG_REG - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HDMI_DEBUG_REG_RSVD2	 0x0804, 5, 27, 0xffffffe0
	#define BITFIELD_HDMI_RX_HDMI_DEBUG_REG_SPEED_UP_CNTRS	 0x0804, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_HDMI_DEBUG_REG_DBG_RI_CHECK	 0x0804, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_HDMI_DEBUG_REG_RSVD1	 0x0804, 1, 2, 0x00000006
	#define BITFIELD_HDMI_RX_HDMI_DEBUG_REG_DBG_EN_CPU_AUTH	 0x0804, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HDMI_PHY_CTRL_REG	0x840 /* HDMI_PHY_CTRL_REG Register                        */ 
	#define BITFIELD_HDMI_RX_HDMI_PHY_CTRL_REG	 0x0840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HDMI_PHY_CTRL_REG */
	#define BLSB_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD2	2
	#define BLSB_HDMI_RX_HDMI_PHY_CTRL_REG_ASRT_HPD	1
	#define BLSB_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD1	0
	/* Register Bit Widths for HDMI_RX_HDMI_PHY_CTRL_REG */
	#define BWID_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD2	30
	#define BWID_HDMI_RX_HDMI_PHY_CTRL_REG_ASRT_HPD	1
	#define BWID_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD1	1
	/* Register Bit MASKS for HDMI_RX_HDMI_PHY_CTRL_REG */
	#define BMSK_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD2	0xfffffffc /*  */
	#define BMSK_HDMI_RX_HDMI_PHY_CTRL_REG_ASRT_HPD	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD1	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HDMI_PHY_CTRL_REG - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD2	 0x0840, 2, 30, 0xfffffffc
	#define BITFIELD_HDMI_RX_HDMI_PHY_CTRL_REG_ASRT_HPD	 0x0840, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HDMI_PHY_CTRL_REG_RSVD1	 0x0840, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HGCR	0x1000 /* HDMI General Control Register                     */ 
	#define BITFIELD_HDMI_RX_HGCR	 0x1000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HGCR */
	#define BLSB_HDMI_RX_HGCR_EN_AVMUTE	31
	#define BLSB_HDMI_RX_HGCR_AVMUTE_STATE	30
	#define BLSB_HDMI_RX_HGCR_RSTR_HDCP_CTXT	29
	#define BLSB_HDMI_RX_HGCR_AVMUTE_RPLC_PIX	28
	#define BLSB_HDMI_RX_HGCR_RSVD0	18
	#define BLSB_HDMI_RX_HGCR_PIX_CNT_LEN	16
	#define BLSB_HDMI_RX_HGCR_RSVD1	15
	#define BLSB_HDMI_RX_HGCR_EESS_SIG_STICKY_EN	14
	#define BLSB_HDMI_RX_HGCR_IGNR_BCH_ERR	13
	#define BLSB_HDMI_RX_HGCR_IGNR_DIP_PSR_ERR	12
	#define BLSB_HDMI_RX_HGCR_PIX_RPT_CNT	8
	#define BLSB_HDMI_RX_HGCR_VID_FRMT	6
	#define BLSB_HDMI_RX_HGCR_RSVD2	5
	#define BLSB_HDMI_RX_HGCR_INFO_EN	4
	#define BLSB_HDMI_RX_HGCR_AUDIO_EN	3
	#define BLSB_HDMI_RX_HGCR_VIDEO_EN	2
	#define BLSB_HDMI_RX_HGCR_DIS_HDCP	1
	#define BLSB_HDMI_RX_HGCR_DIS_HDMI	0
	/* Register Bit Widths for HDMI_RX_HGCR */
	#define BWID_HDMI_RX_HGCR_EN_AVMUTE	1
	#define BWID_HDMI_RX_HGCR_AVMUTE_STATE	1
	#define BWID_HDMI_RX_HGCR_RSTR_HDCP_CTXT	1
	#define BWID_HDMI_RX_HGCR_AVMUTE_RPLC_PIX	1
	#define BWID_HDMI_RX_HGCR_RSVD0	10
	#define BWID_HDMI_RX_HGCR_PIX_CNT_LEN	2
	#define BWID_HDMI_RX_HGCR_RSVD1	1
	#define BWID_HDMI_RX_HGCR_EESS_SIG_STICKY_EN	1
	#define BWID_HDMI_RX_HGCR_IGNR_BCH_ERR	1
	#define BWID_HDMI_RX_HGCR_IGNR_DIP_PSR_ERR	1
	#define BWID_HDMI_RX_HGCR_PIX_RPT_CNT	4
	#define BWID_HDMI_RX_HGCR_VID_FRMT	2
	#define BWID_HDMI_RX_HGCR_RSVD2	1
	#define BWID_HDMI_RX_HGCR_INFO_EN	1
	#define BWID_HDMI_RX_HGCR_AUDIO_EN	1
	#define BWID_HDMI_RX_HGCR_VIDEO_EN	1
	#define BWID_HDMI_RX_HGCR_DIS_HDCP	1
	#define BWID_HDMI_RX_HGCR_DIS_HDMI	1
	/* Register Bit MASKS for HDMI_RX_HGCR */
	#define BMSK_HDMI_RX_HGCR_EN_AVMUTE	(1<<31) /* == 0x80000000:  */
	#define BMSK_HDMI_RX_HGCR_AVMUTE_STATE	(1<<30) /* == 0x40000000:  */
	#define BMSK_HDMI_RX_HGCR_RSTR_HDCP_CTXT	(1<<29) /* == 0x20000000:  */
	#define BMSK_HDMI_RX_HGCR_AVMUTE_RPLC_PIX	(1<<28) /* == 0x10000000:  */
	#define BMSK_HDMI_RX_HGCR_RSVD0	0x0ffc0000 /*  */
	#define BMSK_HDMI_RX_HGCR_PIX_CNT_LEN	0x00030000 /*  */
	#define BMSK_HDMI_RX_HGCR_RSVD1	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_HGCR_EESS_SIG_STICKY_EN	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_HGCR_IGNR_BCH_ERR	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_HGCR_IGNR_DIP_PSR_ERR	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_HGCR_PIX_RPT_CNT	0x00000f00 /*  */
	#define BMSK_HDMI_RX_HGCR_VID_FRMT	0x000000c0 /*  */
	#define BMSK_HDMI_RX_HGCR_RSVD2	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_HGCR_INFO_EN	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_HGCR_AUDIO_EN	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_HGCR_VIDEO_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_HGCR_DIS_HDCP	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HGCR_DIS_HDMI	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HGCR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HGCR_EN_AVMUTE	 0x1000, 31, 1, 0x80000000
	#define BITFIELD_HDMI_RX_HGCR_AVMUTE_STATE	 0x1000, 30, 1, 0x40000000
	#define BITFIELD_HDMI_RX_HGCR_RSTR_HDCP_CTXT	 0x1000, 29, 1, 0x20000000
	#define BITFIELD_HDMI_RX_HGCR_AVMUTE_RPLC_PIX	 0x1000, 28, 1, 0x10000000
	#define BITFIELD_HDMI_RX_HGCR_RSVD0	 0x1000, 18, 10, 0x0ffc0000
	#define BITFIELD_HDMI_RX_HGCR_PIX_CNT_LEN	 0x1000, 16, 2, 0x00030000
	#define BITFIELD_HDMI_RX_HGCR_RSVD1	 0x1000, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_HGCR_EESS_SIG_STICKY_EN	 0x1000, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_HGCR_IGNR_BCH_ERR	 0x1000, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_HGCR_IGNR_DIP_PSR_ERR	 0x1000, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_HGCR_PIX_RPT_CNT	 0x1000, 8, 4, 0x00000f00
	#define BITFIELD_HDMI_RX_HGCR_VID_FRMT	 0x1000, 6, 2, 0x000000c0
	#define BITFIELD_HDMI_RX_HGCR_RSVD2	 0x1000, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_HGCR_INFO_EN	 0x1000, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_HGCR_AUDIO_EN	 0x1000, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_HGCR_VIDEO_EN	 0x1000, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_HGCR_DIS_HDCP	 0x1000, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HGCR_DIS_HDMI	 0x1000, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HGSR	0x1004 /* HDMI General Status Register                      */ 
	#define BITFIELD_HDMI_RX_HGSR	 0x1004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HGSR */
	#define BLSB_HDMI_RX_HGSR_RSVD2	25
	#define BLSB_HDMI_RX_HGSR_IF0_RCVD	24
	#define BLSB_HDMI_RX_HGSR_5V_PRSNT	23
	#define BLSB_HDMI_RX_HGSR_RSVD1	22
	#define BLSB_HDMI_RX_HGSR_AU_SMPL_PSNT	18
	#define BLSB_HDMI_RX_HGSR_AU_LAYOUT	17
	#define BLSB_HDMI_RX_HGSR_AU_PKT_TYPE	16
	#define BLSB_HDMI_RX_HGSR_PXL_DT_SNT	15
	#define BLSB_HDMI_RX_HGSR_DEFAULT_PHASE	14
	#define BLSB_HDMI_RX_HGSR_PACK_PHASE	10
	#define BLSB_HDMI_RX_HGSR_COLOR_DEPTH	6
	#define BLSB_HDMI_RX_HGSR_ENC_EN	5
	#define BLSB_HDMI_RX_HGSR_AUTH_STATE	4
	#define BLSB_HDMI_RX_HGSR_HDMI_OR_DVI	3
	#define BLSB_HDMI_RX_HGSR_INTL_VID_DTCT	2
	#define BLSB_HDMI_RX_HGSR_VPOL	1
	#define BLSB_HDMI_RX_HGSR_HPOL	0
	/* Register Bit Widths for HDMI_RX_HGSR */
	#define BWID_HDMI_RX_HGSR_RSVD2	7
	#define BWID_HDMI_RX_HGSR_IF0_RCVD	1
	#define BWID_HDMI_RX_HGSR_5V_PRSNT	1
	#define BWID_HDMI_RX_HGSR_RSVD1	1
	#define BWID_HDMI_RX_HGSR_AU_SMPL_PSNT	4
	#define BWID_HDMI_RX_HGSR_AU_LAYOUT	1
	#define BWID_HDMI_RX_HGSR_AU_PKT_TYPE	1
	#define BWID_HDMI_RX_HGSR_PXL_DT_SNT	1
	#define BWID_HDMI_RX_HGSR_DEFAULT_PHASE	1
	#define BWID_HDMI_RX_HGSR_PACK_PHASE	4
	#define BWID_HDMI_RX_HGSR_COLOR_DEPTH	4
	#define BWID_HDMI_RX_HGSR_ENC_EN	1
	#define BWID_HDMI_RX_HGSR_AUTH_STATE	1
	#define BWID_HDMI_RX_HGSR_HDMI_OR_DVI	1
	#define BWID_HDMI_RX_HGSR_INTL_VID_DTCT	1
	#define BWID_HDMI_RX_HGSR_VPOL	1
	#define BWID_HDMI_RX_HGSR_HPOL	1
	/* Register Bit MASKS for HDMI_RX_HGSR */
	#define BMSK_HDMI_RX_HGSR_RSVD2	0xfe000000 /*  */
	#define BMSK_HDMI_RX_HGSR_IF0_RCVD	(1<<24) /* == 0x01000000:  */
	#define BMSK_HDMI_RX_HGSR_5V_PRSNT	(1<<23) /* == 0x00800000:  */
	#define BMSK_HDMI_RX_HGSR_RSVD1	(1<<22) /* == 0x00400000:  */
	#define BMSK_HDMI_RX_HGSR_AU_SMPL_PSNT	0x003c0000 /*  */
	#define BMSK_HDMI_RX_HGSR_AU_LAYOUT	(1<<17) /* == 0x00020000:  */
	#define BMSK_HDMI_RX_HGSR_AU_PKT_TYPE	(1<<16) /* == 0x00010000:  */
	#define BMSK_HDMI_RX_HGSR_PXL_DT_SNT	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_HGSR_DEFAULT_PHASE	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_HGSR_PACK_PHASE	0x00003c00 /*  */
	#define BMSK_HDMI_RX_HGSR_COLOR_DEPTH	0x000003c0 /*  */
	#define BMSK_HDMI_RX_HGSR_ENC_EN	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_HGSR_AUTH_STATE	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_HGSR_HDMI_OR_DVI	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_HGSR_INTL_VID_DTCT	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_HGSR_VPOL	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HGSR_HPOL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HGSR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HGSR_RSVD2	 0x1004, 25, 7, 0xfe000000
	#define BITFIELD_HDMI_RX_HGSR_IF0_RCVD	 0x1004, 24, 1, 0x01000000
	#define BITFIELD_HDMI_RX_HGSR_5V_PRSNT	 0x1004, 23, 1, 0x00800000
	#define BITFIELD_HDMI_RX_HGSR_RSVD1	 0x1004, 22, 1, 0x00400000
	#define BITFIELD_HDMI_RX_HGSR_AU_SMPL_PSNT	 0x1004, 18, 4, 0x003c0000
	#define BITFIELD_HDMI_RX_HGSR_AU_LAYOUT	 0x1004, 17, 1, 0x00020000
	#define BITFIELD_HDMI_RX_HGSR_AU_PKT_TYPE	 0x1004, 16, 1, 0x00010000
	#define BITFIELD_HDMI_RX_HGSR_PXL_DT_SNT	 0x1004, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_HGSR_DEFAULT_PHASE	 0x1004, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_HGSR_PACK_PHASE	 0x1004, 10, 4, 0x00003c00
	#define BITFIELD_HDMI_RX_HGSR_COLOR_DEPTH	 0x1004, 6, 4, 0x000003c0
	#define BITFIELD_HDMI_RX_HGSR_ENC_EN	 0x1004, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_HGSR_AUTH_STATE	 0x1004, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_HGSR_HDMI_OR_DVI	 0x1004, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_HGSR_INTL_VID_DTCT	 0x1004, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_HGSR_VPOL	 0x1004, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HGSR_HPOL	 0x1004, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HICR0	0x1010 /* HDMI Interrupt Control 0                          */ 
	#define BITFIELD_HDMI_RX_HICR0	 0x1010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HICR0 */
	#define BLSB_HDMI_RX_HICR0_N_VAL_CHNG	31
	#define BLSB_HDMI_RX_HICR0_EN_SLOW_CLK_CNDTN	30
	#define BLSB_HDMI_RX_HICR0_EN_CTSCNTR	29
	#define BLSB_HDMI_RX_HICR0_EN_AU_CS_CHNG	28
	#define BLSB_HDMI_RX_HICR0_EN_AU_TS_REQ	27
	#define BLSB_HDMI_RX_HICR0_EN_AU_FRAME_DONE	26
	#define BLSB_HDMI_RX_HICR0_EN_AU_LAYOUT_CHNG	25
	#define BLSB_HDMI_RX_HICR0_EN_I2C_BUS_ERR	24
	#define BLSB_HDMI_RX_HICR0_EN_HDCP_KEY_RDY	23
	#define BLSB_HDMI_RX_HICR0_EN_I2C_EDID_STP	22
	#define BLSB_HDMI_RX_HICR0_EN_I2C_EDID_STRT	21
	#define BLSB_HDMI_RX_HICR0_RSVD2	17
	#define BLSB_HDMI_RX_HICR0_EN_IF_DMA_BUF0_DST_INT	16
	#define BLSB_HDMI_RX_HICR0_EN_AU_DMA_BUF0_DST_INT	15
	#define BLSB_HDMI_RX_HICR0_EN_IF_FIFO0_FULL	14
	#define BLSB_HDMI_RX_HICR0_EN_AU_FIFO0_FULL	13
	#define BLSB_HDMI_RX_HICR0_EN_CLR_AVMUTE	12
	#define BLSB_HDMI_RX_HICR0_EN_SET_AVMUTE	11
	#define BLSB_HDMI_RX_HICR0_EN_PP_SYNC_LOST	10
	#define BLSB_HDMI_RX_HICR0_EN_CD_CHNG	9
	#define BLSB_HDMI_RX_HICR0_EN_RECV_AUTH_REQ	8
	#define BLSB_HDMI_RX_HICR0_EN_VSYNC_DTCT	7
	#define BLSB_HDMI_RX_HICR0_EN_TMDS_CLK_FRQ_CHNG	6
	#define BLSB_HDMI_RX_HICR0_EN_HV_TOTAL_CHNG	5
	#define BLSB_HDMI_RX_HICR0_EN_HV_POL_CHNG	4
	#define BLSB_HDMI_RX_HICR0_RSVD1	3
	#define BLSB_HDMI_RX_HICR0_EN_PHY_EVENT	2
	#define BLSB_HDMI_RX_HICR0_EN_5V_LOST	1
	#define BLSB_HDMI_RX_HICR0_EN_5V_DTCT	0
	/* Register Bit Widths for HDMI_RX_HICR0 */
	#define BWID_HDMI_RX_HICR0_N_VAL_CHNG	1
	#define BWID_HDMI_RX_HICR0_EN_SLOW_CLK_CNDTN	1
	#define BWID_HDMI_RX_HICR0_EN_CTSCNTR	1
	#define BWID_HDMI_RX_HICR0_EN_AU_CS_CHNG	1
	#define BWID_HDMI_RX_HICR0_EN_AU_TS_REQ	1
	#define BWID_HDMI_RX_HICR0_EN_AU_FRAME_DONE	1
	#define BWID_HDMI_RX_HICR0_EN_AU_LAYOUT_CHNG	1
	#define BWID_HDMI_RX_HICR0_EN_I2C_BUS_ERR	1
	#define BWID_HDMI_RX_HICR0_EN_HDCP_KEY_RDY	1
	#define BWID_HDMI_RX_HICR0_EN_I2C_EDID_STP	1
	#define BWID_HDMI_RX_HICR0_EN_I2C_EDID_STRT	1
	#define BWID_HDMI_RX_HICR0_RSVD2	4
	#define BWID_HDMI_RX_HICR0_EN_IF_DMA_BUF0_DST_INT	1
	#define BWID_HDMI_RX_HICR0_EN_AU_DMA_BUF0_DST_INT	1
	#define BWID_HDMI_RX_HICR0_EN_IF_FIFO0_FULL	1
	#define BWID_HDMI_RX_HICR0_EN_AU_FIFO0_FULL	1
	#define BWID_HDMI_RX_HICR0_EN_CLR_AVMUTE	1
	#define BWID_HDMI_RX_HICR0_EN_SET_AVMUTE	1
	#define BWID_HDMI_RX_HICR0_EN_PP_SYNC_LOST	1
	#define BWID_HDMI_RX_HICR0_EN_CD_CHNG	1
	#define BWID_HDMI_RX_HICR0_EN_RECV_AUTH_REQ	1
	#define BWID_HDMI_RX_HICR0_EN_VSYNC_DTCT	1
	#define BWID_HDMI_RX_HICR0_EN_TMDS_CLK_FRQ_CHNG	1
	#define BWID_HDMI_RX_HICR0_EN_HV_TOTAL_CHNG	1
	#define BWID_HDMI_RX_HICR0_EN_HV_POL_CHNG	1
	#define BWID_HDMI_RX_HICR0_RSVD1	1
	#define BWID_HDMI_RX_HICR0_EN_PHY_EVENT	1
	#define BWID_HDMI_RX_HICR0_EN_5V_LOST	1
	#define BWID_HDMI_RX_HICR0_EN_5V_DTCT	1
	/* Register Bit MASKS for HDMI_RX_HICR0 */
	#define BMSK_HDMI_RX_HICR0_N_VAL_CHNG	(1<<31) /* == 0x80000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_SLOW_CLK_CNDTN	(1<<30) /* == 0x40000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_CTSCNTR	(1<<29) /* == 0x20000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_AU_CS_CHNG	(1<<28) /* == 0x10000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_AU_TS_REQ	(1<<27) /* == 0x08000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_AU_FRAME_DONE	(1<<26) /* == 0x04000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_AU_LAYOUT_CHNG	(1<<25) /* == 0x02000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_I2C_BUS_ERR	(1<<24) /* == 0x01000000:  */
	#define BMSK_HDMI_RX_HICR0_EN_HDCP_KEY_RDY	(1<<23) /* == 0x00800000:  */
	#define BMSK_HDMI_RX_HICR0_EN_I2C_EDID_STP	(1<<22) /* == 0x00400000:  */
	#define BMSK_HDMI_RX_HICR0_EN_I2C_EDID_STRT	(1<<21) /* == 0x00200000:  */
	#define BMSK_HDMI_RX_HICR0_RSVD2	0x001e0000 /*  */
	#define BMSK_HDMI_RX_HICR0_EN_IF_DMA_BUF0_DST_INT	(1<<16) /* == 0x00010000:  */
	#define BMSK_HDMI_RX_HICR0_EN_AU_DMA_BUF0_DST_INT	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_HICR0_EN_IF_FIFO0_FULL	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_HICR0_EN_AU_FIFO0_FULL	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_HICR0_EN_CLR_AVMUTE	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_HICR0_EN_SET_AVMUTE	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_HICR0_EN_PP_SYNC_LOST	(1<<10) /* == 0x00000400:  */
	#define BMSK_HDMI_RX_HICR0_EN_CD_CHNG	(1<<9) /* == 0x00000200:  */
	#define BMSK_HDMI_RX_HICR0_EN_RECV_AUTH_REQ	(1<<8) /* == 0x00000100:  */
	#define BMSK_HDMI_RX_HICR0_EN_VSYNC_DTCT	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_HICR0_EN_TMDS_CLK_FRQ_CHNG	(1<<6) /* == 0x00000040:  */
	#define BMSK_HDMI_RX_HICR0_EN_HV_TOTAL_CHNG	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_HICR0_EN_HV_POL_CHNG	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_HICR0_RSVD1	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_HICR0_EN_PHY_EVENT	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_HICR0_EN_5V_LOST	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HICR0_EN_5V_DTCT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HICR0 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HICR0_N_VAL_CHNG	 0x1010, 31, 1, 0x80000000
	#define BITFIELD_HDMI_RX_HICR0_EN_SLOW_CLK_CNDTN	 0x1010, 30, 1, 0x40000000
	#define BITFIELD_HDMI_RX_HICR0_EN_CTSCNTR	 0x1010, 29, 1, 0x20000000
	#define BITFIELD_HDMI_RX_HICR0_EN_AU_CS_CHNG	 0x1010, 28, 1, 0x10000000
	#define BITFIELD_HDMI_RX_HICR0_EN_AU_TS_REQ	 0x1010, 27, 1, 0x08000000
	#define BITFIELD_HDMI_RX_HICR0_EN_AU_FRAME_DONE	 0x1010, 26, 1, 0x04000000
	#define BITFIELD_HDMI_RX_HICR0_EN_AU_LAYOUT_CHNG	 0x1010, 25, 1, 0x02000000
	#define BITFIELD_HDMI_RX_HICR0_EN_I2C_BUS_ERR	 0x1010, 24, 1, 0x01000000
	#define BITFIELD_HDMI_RX_HICR0_EN_HDCP_KEY_RDY	 0x1010, 23, 1, 0x00800000
	#define BITFIELD_HDMI_RX_HICR0_EN_I2C_EDID_STP	 0x1010, 22, 1, 0x00400000
	#define BITFIELD_HDMI_RX_HICR0_EN_I2C_EDID_STRT	 0x1010, 21, 1, 0x00200000
	#define BITFIELD_HDMI_RX_HICR0_RSVD2	 0x1010, 17, 4, 0x001e0000
	#define BITFIELD_HDMI_RX_HICR0_EN_IF_DMA_BUF0_DST_INT	 0x1010, 16, 1, 0x00010000
	#define BITFIELD_HDMI_RX_HICR0_EN_AU_DMA_BUF0_DST_INT	 0x1010, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_HICR0_EN_IF_FIFO0_FULL	 0x1010, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_HICR0_EN_AU_FIFO0_FULL	 0x1010, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_HICR0_EN_CLR_AVMUTE	 0x1010, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_HICR0_EN_SET_AVMUTE	 0x1010, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_HICR0_EN_PP_SYNC_LOST	 0x1010, 10, 1, 0x00000400
	#define BITFIELD_HDMI_RX_HICR0_EN_CD_CHNG	 0x1010, 9, 1, 0x00000200
	#define BITFIELD_HDMI_RX_HICR0_EN_RECV_AUTH_REQ	 0x1010, 8, 1, 0x00000100
	#define BITFIELD_HDMI_RX_HICR0_EN_VSYNC_DTCT	 0x1010, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_HICR0_EN_TMDS_CLK_FRQ_CHNG	 0x1010, 6, 1, 0x00000040
	#define BITFIELD_HDMI_RX_HICR0_EN_HV_TOTAL_CHNG	 0x1010, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_HICR0_EN_HV_POL_CHNG	 0x1010, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_HICR0_RSVD1	 0x1010, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_HICR0_EN_PHY_EVENT	 0x1010, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_HICR0_EN_5V_LOST	 0x1010, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HICR0_EN_5V_DTCT	 0x1010, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HICR1	0x1014 /* HDMI Interrupt Control 1                          */ 
	#define BITFIELD_HDMI_RX_HICR1	 0x1014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HICR1 */
	#define BLSB_HDMI_RX_HICR1_RSVD2	17
	#define BLSB_HDMI_RX_HICR1_EN_TMDS_CLK_STP	16
	#define BLSB_HDMI_RX_HICR1_EN_INVLD_CHAR	15
	#define BLSB_HDMI_RX_HICR1_EN_PIX_RPT_ERR	14
	#define BLSB_HDMI_RX_HICR1_EN_AU_PE	13
	#define BLSB_HDMI_RX_HICR1_EN_BCH_ERR	12
	#define BLSB_HDMI_RX_HICR1_EN_DECODE_ERR	11
	#define BLSB_HDMI_RX_HICR1_EN_INVLD_CTRL_CHAR	10
	#define BLSB_HDMI_RX_HICR1_HDMI_VDP_LGB_ERR	9
	#define BLSB_HDMI_RX_HICR1_HDMI_DIP_GB_ERR	8
	#define BLSB_HDMI_RX_HICR1_RSVD1	2
	#define BLSB_HDMI_RX_HICR1_EN_IF_DMA_BUF0_STP_INT	1
	#define BLSB_HDMI_RX_HICR1_EN_AU_DMA_BUF0_STP_INT	0
	/* Register Bit Widths for HDMI_RX_HICR1 */
	#define BWID_HDMI_RX_HICR1_RSVD2	15
	#define BWID_HDMI_RX_HICR1_EN_TMDS_CLK_STP	1
	#define BWID_HDMI_RX_HICR1_EN_INVLD_CHAR	1
	#define BWID_HDMI_RX_HICR1_EN_PIX_RPT_ERR	1
	#define BWID_HDMI_RX_HICR1_EN_AU_PE	1
	#define BWID_HDMI_RX_HICR1_EN_BCH_ERR	1
	#define BWID_HDMI_RX_HICR1_EN_DECODE_ERR	1
	#define BWID_HDMI_RX_HICR1_EN_INVLD_CTRL_CHAR	1
	#define BWID_HDMI_RX_HICR1_HDMI_VDP_LGB_ERR	1
	#define BWID_HDMI_RX_HICR1_HDMI_DIP_GB_ERR	1
	#define BWID_HDMI_RX_HICR1_RSVD1	6
	#define BWID_HDMI_RX_HICR1_EN_IF_DMA_BUF0_STP_INT	1
	#define BWID_HDMI_RX_HICR1_EN_AU_DMA_BUF0_STP_INT	1
	/* Register Bit MASKS for HDMI_RX_HICR1 */
	#define BMSK_HDMI_RX_HICR1_RSVD2	0xfffe0000 /*  */
	#define BMSK_HDMI_RX_HICR1_EN_TMDS_CLK_STP	(1<<16) /* == 0x00010000:  */
	#define BMSK_HDMI_RX_HICR1_EN_INVLD_CHAR	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_HICR1_EN_PIX_RPT_ERR	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_HICR1_EN_AU_PE	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_HICR1_EN_BCH_ERR	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_HICR1_EN_DECODE_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_HICR1_EN_INVLD_CTRL_CHAR	(1<<10) /* == 0x00000400:  */
	#define BMSK_HDMI_RX_HICR1_HDMI_VDP_LGB_ERR	(1<<9) /* == 0x00000200:  */
	#define BMSK_HDMI_RX_HICR1_HDMI_DIP_GB_ERR	(1<<8) /* == 0x00000100:  */
	#define BMSK_HDMI_RX_HICR1_RSVD1	0x000000fc /*  */
	#define BMSK_HDMI_RX_HICR1_EN_IF_DMA_BUF0_STP_INT	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HICR1_EN_AU_DMA_BUF0_STP_INT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HICR1 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HICR1_RSVD2	 0x1014, 17, 15, 0xfffe0000
	#define BITFIELD_HDMI_RX_HICR1_EN_TMDS_CLK_STP	 0x1014, 16, 1, 0x00010000
	#define BITFIELD_HDMI_RX_HICR1_EN_INVLD_CHAR	 0x1014, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_HICR1_EN_PIX_RPT_ERR	 0x1014, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_HICR1_EN_AU_PE	 0x1014, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_HICR1_EN_BCH_ERR	 0x1014, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_HICR1_EN_DECODE_ERR	 0x1014, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_HICR1_EN_INVLD_CTRL_CHAR	 0x1014, 10, 1, 0x00000400
	#define BITFIELD_HDMI_RX_HICR1_HDMI_VDP_LGB_ERR	 0x1014, 9, 1, 0x00000200
	#define BITFIELD_HDMI_RX_HICR1_HDMI_DIP_GB_ERR	 0x1014, 8, 1, 0x00000100
	#define BITFIELD_HDMI_RX_HICR1_RSVD1	 0x1014, 2, 6, 0x000000fc
	#define BITFIELD_HDMI_RX_HICR1_EN_IF_DMA_BUF0_STP_INT	 0x1014, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HICR1_EN_AU_DMA_BUF0_STP_INT	 0x1014, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HISR0	0x1018 /* HDMI Interrupt Status 0                           */ 
	#define BITFIELD_HDMI_RX_HISR0	 0x1018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HISR0 */
	#define BLSB_HDMI_RX_HISR0_N_VAL_CHNG	31
	#define BLSB_HDMI_RX_HISR0_SLOW_CLK_CNDTN	30
	#define BLSB_HDMI_RX_HISR0_CTS_CNTR_ZERO	29
	#define BLSB_HDMI_RX_HISR0_AU_CS_CHNG	28
	#define BLSB_HDMI_RX_HISR0_AU_TS_REQ	27
	#define BLSB_HDMI_RX_HISR0_AU_FRAME_DONE	26
	#define BLSB_HDMI_RX_HISR0_AU_LAYOUT_CHNG	25
	#define BLSB_HDMI_RX_HISR0_I2C_BUS_ERR	24
	#define BLSB_HDMI_RX_HISR0_HDCP_KEY_RDY	23
	#define BLSB_HDMI_RX_HISR0_I2C_EDID_STP	22
	#define BLSB_HDMI_RX_HISR0_I2C_EDID_STRT	21
	#define BLSB_HDMI_RX_HISR0_RSVD2	17
	#define BLSB_HDMI_RX_HISR0_IF_DMA_BUF0_DST_INT	16
	#define BLSB_HDMI_RX_HISR0_AU_DMA_BUF0_DST_INT	15
	#define BLSB_HDMI_RX_HISR0_IF_FIFO0_FULL	14
	#define BLSB_HDMI_RX_HISR0_AU_FIFO0_FULL	13
	#define BLSB_HDMI_RX_HISR0_CLR_AVMUTE	12
	#define BLSB_HDMI_RX_HISR0_SET_AVMUTE	11
	#define BLSB_HDMI_RX_HISR0_PP_SYNC_LOST	10
	#define BLSB_HDMI_RX_HISR0_CD_CHNG	9
	#define BLSB_HDMI_RX_HISR0_RECV_AUTH_REQ	8
	#define BLSB_HDMI_RX_HISR0_VSYNC_DTCT	7
	#define BLSB_HDMI_RX_HISR0_TMDS_CLK_FRQ_CHNG	6
	#define BLSB_HDMI_RX_HISR0_HV_TOTAL_CHNG	5
	#define BLSB_HDMI_RX_HISR0_HV_POL_CHNG	4
	#define BLSB_HDMI_RX_HISR0_RSVD1	3
	#define BLSB_HDMI_RX_HISR0_PHY_EVENT	2
	#define BLSB_HDMI_RX_HISR0_5V_LOST	1
	#define BLSB_HDMI_RX_HISR0_5V_DTCT	0
	/* Register Bit Widths for HDMI_RX_HISR0 */
	#define BWID_HDMI_RX_HISR0_N_VAL_CHNG	1
	#define BWID_HDMI_RX_HISR0_SLOW_CLK_CNDTN	1
	#define BWID_HDMI_RX_HISR0_CTS_CNTR_ZERO	1
	#define BWID_HDMI_RX_HISR0_AU_CS_CHNG	1
	#define BWID_HDMI_RX_HISR0_AU_TS_REQ	1
	#define BWID_HDMI_RX_HISR0_AU_FRAME_DONE	1
	#define BWID_HDMI_RX_HISR0_AU_LAYOUT_CHNG	1
	#define BWID_HDMI_RX_HISR0_I2C_BUS_ERR	1
	#define BWID_HDMI_RX_HISR0_HDCP_KEY_RDY	1
	#define BWID_HDMI_RX_HISR0_I2C_EDID_STP	1
	#define BWID_HDMI_RX_HISR0_I2C_EDID_STRT	1
	#define BWID_HDMI_RX_HISR0_RSVD2	4
	#define BWID_HDMI_RX_HISR0_IF_DMA_BUF0_DST_INT	1
	#define BWID_HDMI_RX_HISR0_AU_DMA_BUF0_DST_INT	1
	#define BWID_HDMI_RX_HISR0_IF_FIFO0_FULL	1
	#define BWID_HDMI_RX_HISR0_AU_FIFO0_FULL	1
	#define BWID_HDMI_RX_HISR0_CLR_AVMUTE	1
	#define BWID_HDMI_RX_HISR0_SET_AVMUTE	1
	#define BWID_HDMI_RX_HISR0_PP_SYNC_LOST	1
	#define BWID_HDMI_RX_HISR0_CD_CHNG	1
	#define BWID_HDMI_RX_HISR0_RECV_AUTH_REQ	1
	#define BWID_HDMI_RX_HISR0_VSYNC_DTCT	1
	#define BWID_HDMI_RX_HISR0_TMDS_CLK_FRQ_CHNG	1
	#define BWID_HDMI_RX_HISR0_HV_TOTAL_CHNG	1
	#define BWID_HDMI_RX_HISR0_HV_POL_CHNG	1
	#define BWID_HDMI_RX_HISR0_RSVD1	1
	#define BWID_HDMI_RX_HISR0_PHY_EVENT	1
	#define BWID_HDMI_RX_HISR0_5V_LOST	1
	#define BWID_HDMI_RX_HISR0_5V_DTCT	1
	/* Register Bit MASKS for HDMI_RX_HISR0 */
	#define BMSK_HDMI_RX_HISR0_N_VAL_CHNG	(1<<31) /* == 0x80000000:  */
	#define BMSK_HDMI_RX_HISR0_SLOW_CLK_CNDTN	(1<<30) /* == 0x40000000:  */
	#define BMSK_HDMI_RX_HISR0_CTS_CNTR_ZERO	(1<<29) /* == 0x20000000:  */
	#define BMSK_HDMI_RX_HISR0_AU_CS_CHNG	(1<<28) /* == 0x10000000:  */
	#define BMSK_HDMI_RX_HISR0_AU_TS_REQ	(1<<27) /* == 0x08000000:  */
	#define BMSK_HDMI_RX_HISR0_AU_FRAME_DONE	(1<<26) /* == 0x04000000:  */
	#define BMSK_HDMI_RX_HISR0_AU_LAYOUT_CHNG	(1<<25) /* == 0x02000000:  */
	#define BMSK_HDMI_RX_HISR0_I2C_BUS_ERR	(1<<24) /* == 0x01000000:  */
	#define BMSK_HDMI_RX_HISR0_HDCP_KEY_RDY	(1<<23) /* == 0x00800000:  */
	#define BMSK_HDMI_RX_HISR0_I2C_EDID_STP	(1<<22) /* == 0x00400000:  */
	#define BMSK_HDMI_RX_HISR0_I2C_EDID_STRT	(1<<21) /* == 0x00200000:  */
	#define BMSK_HDMI_RX_HISR0_RSVD2	0x001e0000 /*  */
	#define BMSK_HDMI_RX_HISR0_IF_DMA_BUF0_DST_INT	(1<<16) /* == 0x00010000:  */
	#define BMSK_HDMI_RX_HISR0_AU_DMA_BUF0_DST_INT	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_HISR0_IF_FIFO0_FULL	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_HISR0_AU_FIFO0_FULL	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_HISR0_CLR_AVMUTE	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_HISR0_SET_AVMUTE	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_HISR0_PP_SYNC_LOST	(1<<10) /* == 0x00000400:  */
	#define BMSK_HDMI_RX_HISR0_CD_CHNG	(1<<9) /* == 0x00000200:  */
	#define BMSK_HDMI_RX_HISR0_RECV_AUTH_REQ	(1<<8) /* == 0x00000100:  */
	#define BMSK_HDMI_RX_HISR0_VSYNC_DTCT	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_HISR0_TMDS_CLK_FRQ_CHNG	(1<<6) /* == 0x00000040:  */
	#define BMSK_HDMI_RX_HISR0_HV_TOTAL_CHNG	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_HISR0_HV_POL_CHNG	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_HISR0_RSVD1	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_HISR0_PHY_EVENT	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_HISR0_5V_LOST	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HISR0_5V_DTCT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HISR0 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HISR0_N_VAL_CHNG	 0x1018, 31, 1, 0x80000000
	#define BITFIELD_HDMI_RX_HISR0_SLOW_CLK_CNDTN	 0x1018, 30, 1, 0x40000000
	#define BITFIELD_HDMI_RX_HISR0_CTS_CNTR_ZERO	 0x1018, 29, 1, 0x20000000
	#define BITFIELD_HDMI_RX_HISR0_AU_CS_CHNG	 0x1018, 28, 1, 0x10000000
	#define BITFIELD_HDMI_RX_HISR0_AU_TS_REQ	 0x1018, 27, 1, 0x08000000
	#define BITFIELD_HDMI_RX_HISR0_AU_FRAME_DONE	 0x1018, 26, 1, 0x04000000
	#define BITFIELD_HDMI_RX_HISR0_AU_LAYOUT_CHNG	 0x1018, 25, 1, 0x02000000
	#define BITFIELD_HDMI_RX_HISR0_I2C_BUS_ERR	 0x1018, 24, 1, 0x01000000
	#define BITFIELD_HDMI_RX_HISR0_HDCP_KEY_RDY	 0x1018, 23, 1, 0x00800000
	#define BITFIELD_HDMI_RX_HISR0_I2C_EDID_STP	 0x1018, 22, 1, 0x00400000
	#define BITFIELD_HDMI_RX_HISR0_I2C_EDID_STRT	 0x1018, 21, 1, 0x00200000
	#define BITFIELD_HDMI_RX_HISR0_RSVD2	 0x1018, 17, 4, 0x001e0000
	#define BITFIELD_HDMI_RX_HISR0_IF_DMA_BUF0_DST_INT	 0x1018, 16, 1, 0x00010000
	#define BITFIELD_HDMI_RX_HISR0_AU_DMA_BUF0_DST_INT	 0x1018, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_HISR0_IF_FIFO0_FULL	 0x1018, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_HISR0_AU_FIFO0_FULL	 0x1018, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_HISR0_CLR_AVMUTE	 0x1018, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_HISR0_SET_AVMUTE	 0x1018, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_HISR0_PP_SYNC_LOST	 0x1018, 10, 1, 0x00000400
	#define BITFIELD_HDMI_RX_HISR0_CD_CHNG	 0x1018, 9, 1, 0x00000200
	#define BITFIELD_HDMI_RX_HISR0_RECV_AUTH_REQ	 0x1018, 8, 1, 0x00000100
	#define BITFIELD_HDMI_RX_HISR0_VSYNC_DTCT	 0x1018, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_HISR0_TMDS_CLK_FRQ_CHNG	 0x1018, 6, 1, 0x00000040
	#define BITFIELD_HDMI_RX_HISR0_HV_TOTAL_CHNG	 0x1018, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_HISR0_HV_POL_CHNG	 0x1018, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_HISR0_RSVD1	 0x1018, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_HISR0_PHY_EVENT	 0x1018, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_HISR0_5V_LOST	 0x1018, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HISR0_5V_DTCT	 0x1018, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HISR1	0x101c /* HDMI Interrupt Status 1                           */ 
	#define BITFIELD_HDMI_RX_HISR1	 0x101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HISR1 */
	#define BLSB_HDMI_RX_HISR1_RSVD2	17
	#define BLSB_HDMI_RX_HISR1_TMDS_CLK_STP	16
	#define BLSB_HDMI_RX_HISR1_INVLD_CHAR	15
	#define BLSB_HDMI_RX_HISR1_PIX_RPT_ERR	14
	#define BLSB_HDMI_RX_HISR1_AU_PE	13
	#define BLSB_HDMI_RX_HISR1_BCH_ERR	12
	#define BLSB_HDMI_RX_HISR1_DECODE_ERR	11
	#define BLSB_HDMI_RX_HISR1_INVLD_CTRL_CHAR	10
	#define BLSB_HDMI_RX_HISR1_HDMI_VDP_LGB_ERR	9
	#define BLSB_HDMI_RX_HISR1_HDMI_DIP_GB_ERR	8
	#define BLSB_HDMI_RX_HISR1_RSVD1	2
	#define BLSB_HDMI_RX_HISR1_IF_DMA_BUF0_STP_INT	1
	#define BLSB_HDMI_RX_HISR1_AU_DMA_BUF0_STP_INT	0
	/* Register Bit Widths for HDMI_RX_HISR1 */
	#define BWID_HDMI_RX_HISR1_RSVD2	15
	#define BWID_HDMI_RX_HISR1_TMDS_CLK_STP	1
	#define BWID_HDMI_RX_HISR1_INVLD_CHAR	1
	#define BWID_HDMI_RX_HISR1_PIX_RPT_ERR	1
	#define BWID_HDMI_RX_HISR1_AU_PE	1
	#define BWID_HDMI_RX_HISR1_BCH_ERR	1
	#define BWID_HDMI_RX_HISR1_DECODE_ERR	1
	#define BWID_HDMI_RX_HISR1_INVLD_CTRL_CHAR	1
	#define BWID_HDMI_RX_HISR1_HDMI_VDP_LGB_ERR	1
	#define BWID_HDMI_RX_HISR1_HDMI_DIP_GB_ERR	1
	#define BWID_HDMI_RX_HISR1_RSVD1	6
	#define BWID_HDMI_RX_HISR1_IF_DMA_BUF0_STP_INT	1
	#define BWID_HDMI_RX_HISR1_AU_DMA_BUF0_STP_INT	1
	/* Register Bit MASKS for HDMI_RX_HISR1 */
	#define BMSK_HDMI_RX_HISR1_RSVD2	0xfffe0000 /*  */
	#define BMSK_HDMI_RX_HISR1_TMDS_CLK_STP	(1<<16) /* == 0x00010000:  */
	#define BMSK_HDMI_RX_HISR1_INVLD_CHAR	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_HISR1_PIX_RPT_ERR	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_HISR1_AU_PE	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_HISR1_BCH_ERR	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_HISR1_DECODE_ERR	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_HISR1_INVLD_CTRL_CHAR	(1<<10) /* == 0x00000400:  */
	#define BMSK_HDMI_RX_HISR1_HDMI_VDP_LGB_ERR	(1<<9) /* == 0x00000200:  */
	#define BMSK_HDMI_RX_HISR1_HDMI_DIP_GB_ERR	(1<<8) /* == 0x00000100:  */
	#define BMSK_HDMI_RX_HISR1_RSVD1	0x000000fc /*  */
	#define BMSK_HDMI_RX_HISR1_IF_DMA_BUF0_STP_INT	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HISR1_AU_DMA_BUF0_STP_INT	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HISR1 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HISR1_RSVD2	 0x101c, 17, 15, 0xfffe0000
	#define BITFIELD_HDMI_RX_HISR1_TMDS_CLK_STP	 0x101c, 16, 1, 0x00010000
	#define BITFIELD_HDMI_RX_HISR1_INVLD_CHAR	 0x101c, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_HISR1_PIX_RPT_ERR	 0x101c, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_HISR1_AU_PE	 0x101c, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_HISR1_BCH_ERR	 0x101c, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_HISR1_DECODE_ERR	 0x101c, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_HISR1_INVLD_CTRL_CHAR	 0x101c, 10, 1, 0x00000400
	#define BITFIELD_HDMI_RX_HISR1_HDMI_VDP_LGB_ERR	 0x101c, 9, 1, 0x00000200
	#define BITFIELD_HDMI_RX_HISR1_HDMI_DIP_GB_ERR	 0x101c, 8, 1, 0x00000100
	#define BITFIELD_HDMI_RX_HISR1_RSVD1	 0x101c, 2, 6, 0x000000fc
	#define BITFIELD_HDMI_RX_HISR1_IF_DMA_BUF0_STP_INT	 0x101c, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HISR1_AU_DMA_BUF0_STP_INT	 0x101c, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HSTR	0x1020 /* HDMI Statistics Total Register                    */ 
	#define BITFIELD_HDMI_RX_HSTR	 0x1020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HSTR */
	#define BLSB_HDMI_RX_HSTR_VTOTAL	16
	#define BLSB_HDMI_RX_HSTR_HTOTAL	0
	/* Register Bit Widths for HDMI_RX_HSTR */
	#define BWID_HDMI_RX_HSTR_VTOTAL	16
	#define BWID_HDMI_RX_HSTR_HTOTAL	16
	/* Register Bit MASKS for HDMI_RX_HSTR */
	#define BMSK_HDMI_RX_HSTR_VTOTAL	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HSTR_HTOTAL	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HSTR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HSTR_VTOTAL	 0x1020, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HSTR_HTOTAL	 0x1020, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HSAR	0x1024 /* HDMI Statistics Active Register                   */ 
	#define BITFIELD_HDMI_RX_HSAR	 0x1024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HSAR */
	#define BLSB_HDMI_RX_HSAR_VACTIVE	16
	#define BLSB_HDMI_RX_HSAR_HACTIVE	0
	/* Register Bit Widths for HDMI_RX_HSAR */
	#define BWID_HDMI_RX_HSAR_VACTIVE	16
	#define BWID_HDMI_RX_HSAR_HACTIVE	16
	/* Register Bit MASKS for HDMI_RX_HSAR */
	#define BMSK_HDMI_RX_HSAR_VACTIVE	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HSAR_HACTIVE	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HSAR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HSAR_VACTIVE	 0x1024, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HSAR_HACTIVE	 0x1024, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HSSR	0x1028 /* HDMI Statistics Sync Register                     */ 
	#define BITFIELD_HDMI_RX_HSSR	 0x1028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HSSR */
	#define BLSB_HDMI_RX_HSSR_VSYNC	16
	#define BLSB_HDMI_RX_HSSR_HSYNC	0
	/* Register Bit Widths for HDMI_RX_HSSR */
	#define BWID_HDMI_RX_HSSR_VSYNC	16
	#define BWID_HDMI_RX_HSSR_HSYNC	16
	/* Register Bit MASKS for HDMI_RX_HSSR */
	#define BMSK_HDMI_RX_HSSR_VSYNC	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HSSR_HSYNC	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HSSR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HSSR_VSYNC	 0x1028, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HSSR_HSYNC	 0x1028, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HSBR	0x102c /* HDMI Statistics Back Register                     */ 
	#define BITFIELD_HDMI_RX_HSBR	 0x102c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HSBR */
	#define BLSB_HDMI_RX_HSBR_VBACK	16
	#define BLSB_HDMI_RX_HSBR_HBACK	0
	/* Register Bit Widths for HDMI_RX_HSBR */
	#define BWID_HDMI_RX_HSBR_VBACK	16
	#define BWID_HDMI_RX_HSBR_HBACK	16
	/* Register Bit MASKS for HDMI_RX_HSBR */
	#define BMSK_HDMI_RX_HSBR_VBACK	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HSBR_HBACK	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HSBR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HSBR_VBACK	 0x102c, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HSBR_HBACK	 0x102c, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HTCR	0x1030 /* HDMI TMDS Clock Frequency Count Register          */ 
	#define BITFIELD_HDMI_RX_HTCR	 0x1030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HETR	0x1040 /* HDMI Even Field Threshold Register                */ 
	#define BITFIELD_HDMI_RX_HETR	 0x1040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HETR */
	#define BLSB_HDMI_RX_HETR_RSVD1	26
	#define BLSB_HDMI_RX_HETR_V2HSYNC_THRSH	13
	#define BLSB_HDMI_RX_HETR_H2VSYNC_THRSH	0
	/* Register Bit Widths for HDMI_RX_HETR */
	#define BWID_HDMI_RX_HETR_RSVD1	6
	#define BWID_HDMI_RX_HETR_V2HSYNC_THRSH	13
	#define BWID_HDMI_RX_HETR_H2VSYNC_THRSH	13
	/* Register Bit MASKS for HDMI_RX_HETR */
	#define BMSK_HDMI_RX_HETR_RSVD1	0xfc000000 /*  */
	#define BMSK_HDMI_RX_HETR_V2HSYNC_THRSH	0x03ffe000 /*  */
	#define BMSK_HDMI_RX_HETR_H2VSYNC_THRSH	0x00001fff /*  */
	/* Register BITFIELD for HDMI_RX_HETR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HETR_RSVD1	 0x1040, 26, 6, 0xfc000000
	#define BITFIELD_HDMI_RX_HETR_V2HSYNC_THRSH	 0x1040, 13, 13, 0x03ffe000
	#define BITFIELD_HDMI_RX_HETR_H2VSYNC_THRSH	 0x1040, 0, 13, 0x00001fff
#define ROFF_HDMI_RX_HHTR	0x1044 /* HDMI Htotal & Vtotal Variation Threshold Register */ 
	#define BITFIELD_HDMI_RX_HHTR	 0x1044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHTR */
	#define BLSB_HDMI_RX_HHTR_HSYNC_THRSH	16
	#define BLSB_HDMI_RX_HHTR_PIX_CNT_THRSH	0
	/* Register Bit Widths for HDMI_RX_HHTR */
	#define BWID_HDMI_RX_HHTR_HSYNC_THRSH	16
	#define BWID_HDMI_RX_HHTR_PIX_CNT_THRSH	16
	/* Register Bit MASKS for HDMI_RX_HHTR */
	#define BMSK_HDMI_RX_HHTR_HSYNC_THRSH	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HHTR_PIX_CNT_THRSH	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HHTR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHTR_HSYNC_THRSH	 0x1044, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HHTR_PIX_CNT_THRSH	 0x1044, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HPTR	0x1048 /* HDMI Slow Pixel Clock Threshold Register          */ 
	#define BITFIELD_HDMI_RX_HPTR	 0x1048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HTAR	0x104c /* HDMI TMDS Clock Frequency Count Average Register  */ 
	#define BITFIELD_HDMI_RX_HTAR	 0x104c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HTAR */
	#define BLSB_HDMI_RX_HTAR_RSVD1	10
	#define BLSB_HDMI_RX_HTAR_TDMS_CLK_FRQ_CNT_AVG	0
	/* Register Bit Widths for HDMI_RX_HTAR */
	#define BWID_HDMI_RX_HTAR_RSVD1	22
	#define BWID_HDMI_RX_HTAR_TDMS_CLK_FRQ_CNT_AVG	10
	/* Register Bit MASKS for HDMI_RX_HTAR */
	#define BMSK_HDMI_RX_HTAR_RSVD1	0xfffffc00 /*  */
	#define BMSK_HDMI_RX_HTAR_TDMS_CLK_FRQ_CNT_AVG	0x000003ff /*  */
	/* Register BITFIELD for HDMI_RX_HTAR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HTAR_RSVD1	 0x104c, 10, 22, 0xfffffc00
	#define BITFIELD_HDMI_RX_HTAR_TDMS_CLK_FRQ_CNT_AVG	 0x104c, 0, 10, 0x000003ff
#define ROFF_HDMI_RX_HCTS	0x1050 /* HDMI_CTS                                          */ 
	#define BITFIELD_HDMI_RX_HCTS	 0x1050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HCTS */
	#define BLSB_HDMI_RX_HCTS_RSVD1	20
	#define BLSB_HDMI_RX_HCTS_CTS	0
	/* Register Bit Widths for HDMI_RX_HCTS */
	#define BWID_HDMI_RX_HCTS_RSVD1	12
	#define BWID_HDMI_RX_HCTS_CTS	20
	/* Register Bit MASKS for HDMI_RX_HCTS */
	#define BMSK_HDMI_RX_HCTS_RSVD1	0xfff00000 /*  */
	#define BMSK_HDMI_RX_HCTS_CTS	0x000fffff /*  */
	/* Register BITFIELD for HDMI_RX_HCTS - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HCTS_RSVD1	 0x1050, 20, 12, 0xfff00000
	#define BITFIELD_HDMI_RX_HCTS_CTS	 0x1050, 0, 20, 0x000fffff
#define ROFF_HDMI_RX_HNVL	0x1054 /* HDMI_N_VAL                                        */ 
	#define BITFIELD_HDMI_RX_HNVL	 0x1054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HNVL */
	#define BLSB_HDMI_RX_HNVL_RSVD1	20
	#define BLSB_HDMI_RX_HNVL_N_VAL	0
	/* Register Bit Widths for HDMI_RX_HNVL */
	#define BWID_HDMI_RX_HNVL_RSVD1	12
	#define BWID_HDMI_RX_HNVL_N_VAL	20
	/* Register Bit MASKS for HDMI_RX_HNVL */
	#define BMSK_HDMI_RX_HNVL_RSVD1	0xfff00000 /*  */
	#define BMSK_HDMI_RX_HNVL_N_VAL	0x000fffff /*  */
	/* Register BITFIELD for HDMI_RX_HNVL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HNVL_RSVD1	 0x1054, 20, 12, 0xfff00000
	#define BITFIELD_HDMI_RX_HNVL_N_VAL	 0x1054, 0, 20, 0x000fffff
#define ROFF_HDMI_RX_HAUC	0x1060 /* HDMI_AU_CTRL                                      */ 
	#define BITFIELD_HDMI_RX_HAUC	 0x1060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HAUC */
	#define BLSB_HDMI_RX_HAUC_RSVD1	18
	#define BLSB_HDMI_RX_HAUC_AU_TS_THRH	16
	#define BLSB_HDMI_RX_HAUC_BLK_SIZE	0
	/* Register Bit Widths for HDMI_RX_HAUC */
	#define BWID_HDMI_RX_HAUC_RSVD1	14
	#define BWID_HDMI_RX_HAUC_AU_TS_THRH	2
	#define BWID_HDMI_RX_HAUC_BLK_SIZE	16
	/* Register Bit MASKS for HDMI_RX_HAUC */
	#define BMSK_HDMI_RX_HAUC_RSVD1	0xfffc0000 /*  */
	#define BMSK_HDMI_RX_HAUC_AU_TS_THRH	0x00030000 /*  */
	#define BMSK_HDMI_RX_HAUC_BLK_SIZE	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HAUC - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HAUC_RSVD1	 0x1060, 18, 14, 0xfffc0000
	#define BITFIELD_HDMI_RX_HAUC_AU_TS_THRH	 0x1060, 16, 2, 0x00030000
	#define BITFIELD_HDMI_RX_HAUC_BLK_SIZE	 0x1060, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HACL	0x1068 /* HDMI_AU_CS_LSB                                    */ 
	#define BITFIELD_HDMI_RX_HACL	 0x1068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HACM	0x106c /* HDMI_AU_CS_MSB                                    */ 
	#define BITFIELD_HDMI_RX_HACM	 0x106c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HACM */
	#define BLSB_HDMI_RX_HACM_RSVD1	8
	#define BLSB_HDMI_RX_HACM_HDMI_AU_CS_MSB	0
	/* Register Bit Widths for HDMI_RX_HACM */
	#define BWID_HDMI_RX_HACM_RSVD1	24
	#define BWID_HDMI_RX_HACM_HDMI_AU_CS_MSB	8
	/* Register Bit MASKS for HDMI_RX_HACM */
	#define BMSK_HDMI_RX_HACM_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HACM_HDMI_AU_CS_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HACM - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HACM_RSVD1	 0x106c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HACM_HDMI_AU_CS_MSB	 0x106c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HABT	0x1070 /* HDMI_AU_BLK_TS Register                           */ 
	#define BITFIELD_HDMI_RX_HABT	 0x1070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HABA	0x1074 /* HDMI_AU_BLK_ADDR Register                         */ 
	#define BITFIELD_HDMI_RX_HABA	 0x1074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HPRC	0x1080 /* HDMI_PIX_R_CR                                     */ 
	#define BITFIELD_HDMI_RX_HPRC	 0x1080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HPRC */
	#define BLSB_HDMI_RX_HPRC_RSVD1	12
	#define BLSB_HDMI_RX_HPRC_HDMI_PIX_R_CR	0
	/* Register Bit Widths for HDMI_RX_HPRC */
	#define BWID_HDMI_RX_HPRC_RSVD1	20
	#define BWID_HDMI_RX_HPRC_HDMI_PIX_R_CR	12
	/* Register Bit MASKS for HDMI_RX_HPRC */
	#define BMSK_HDMI_RX_HPRC_RSVD1	0xfffff000 /*  */
	#define BMSK_HDMI_RX_HPRC_HDMI_PIX_R_CR	0x00000fff /*  */
	/* Register BITFIELD for HDMI_RX_HPRC - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HPRC_RSVD1	 0x1080, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_HPRC_HDMI_PIX_R_CR	 0x1080, 0, 12, 0x00000fff
#define ROFF_HDMI_RX_HPGY	0x1084 /* HDMI_PIX_G_Y                                      */ 
	#define BITFIELD_HDMI_RX_HPGY	 0x1084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HPGY */
	#define BLSB_HDMI_RX_HPGY_RSVD1	12
	#define BLSB_HDMI_RX_HPGY_HDMI_PIX_G_Y	0
	/* Register Bit Widths for HDMI_RX_HPGY */
	#define BWID_HDMI_RX_HPGY_RSVD1	20
	#define BWID_HDMI_RX_HPGY_HDMI_PIX_G_Y	12
	/* Register Bit MASKS for HDMI_RX_HPGY */
	#define BMSK_HDMI_RX_HPGY_RSVD1	0xfffff000 /*  */
	#define BMSK_HDMI_RX_HPGY_HDMI_PIX_G_Y	0x00000fff /*  */
	/* Register BITFIELD for HDMI_RX_HPGY - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HPGY_RSVD1	 0x1084, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_HPGY_HDMI_PIX_G_Y	 0x1084, 0, 12, 0x00000fff
#define ROFF_HDMI_RX_HPBC	0x1088 /* HDMI_PIX_B_CB                                     */ 
	#define BITFIELD_HDMI_RX_HPBC	 0x1088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HPBC */
	#define BLSB_HDMI_RX_HPBC_RSVD1	12
	#define BLSB_HDMI_RX_HPBC_HDMI_PIX_B_CB	0
	/* Register Bit Widths for HDMI_RX_HPBC */
	#define BWID_HDMI_RX_HPBC_RSVD1	20
	#define BWID_HDMI_RX_HPBC_HDMI_PIX_B_CB	12
	/* Register Bit MASKS for HDMI_RX_HPBC */
	#define BMSK_HDMI_RX_HPBC_RSVD1	0xfffff000 /*  */
	#define BMSK_HDMI_RX_HPBC_HDMI_PIX_B_CB	0x00000fff /*  */
	/* Register BITFIELD for HDMI_RX_HPBC - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HPBC_RSVD1	 0x1088, 12, 20, 0xfffff000
	#define BITFIELD_HDMI_RX_HPBC_HDMI_PIX_B_CB	 0x1088, 0, 12, 0x00000fff
#define ROFF_HDMI_RX_HAIL	0x10c0 /* HDMI_AINFO_LOCAL                                  */ 
	#define BITFIELD_HDMI_RX_HAIL	 0x10c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HAIL */
	#define BLSB_HDMI_RX_HAIL_RSVD1	8
	#define BLSB_HDMI_RX_HAIL_AINFO_RESERVED2	2
	#define BLSB_HDMI_RX_HAIL_ENABLE_1_1_FEATURES	1
	#define BLSB_HDMI_RX_HAIL_AINFO_RESERVED1	0
	/* Register Bit Widths for HDMI_RX_HAIL */
	#define BWID_HDMI_RX_HAIL_RSVD1	24
	#define BWID_HDMI_RX_HAIL_AINFO_RESERVED2	6
	#define BWID_HDMI_RX_HAIL_ENABLE_1_1_FEATURES	1
	#define BWID_HDMI_RX_HAIL_AINFO_RESERVED1	1
	/* Register Bit MASKS for HDMI_RX_HAIL */
	#define BMSK_HDMI_RX_HAIL_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HAIL_AINFO_RESERVED2	0x000000fc /*  */
	#define BMSK_HDMI_RX_HAIL_ENABLE_1_1_FEATURES	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HAIL_AINFO_RESERVED1	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HAIL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HAIL_RSVD1	 0x10c0, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HAIL_AINFO_RESERVED2	 0x10c0, 2, 6, 0x000000fc
	#define BITFIELD_HDMI_RX_HAIL_ENABLE_1_1_FEATURES	 0x10c0, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HAIL_AINFO_RESERVED1	 0x10c0, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HOCL	0x10d0 /* HDMI_OMAR_CTRL                                    */ 
	#define BITFIELD_HDMI_RX_HOCL	 0x10d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HOCL */
	#define BLSB_HDMI_RX_HOCL_RSVD1	16
	#define BLSB_HDMI_RX_HOCL_DIP_TYPE1	8
	#define BLSB_HDMI_RX_HOCL_DIP_TYPE0	0
	/* Register Bit Widths for HDMI_RX_HOCL */
	#define BWID_HDMI_RX_HOCL_RSVD1	16
	#define BWID_HDMI_RX_HOCL_DIP_TYPE1	8
	#define BWID_HDMI_RX_HOCL_DIP_TYPE0	8
	/* Register Bit MASKS for HDMI_RX_HOCL */
	#define BMSK_HDMI_RX_HOCL_RSVD1	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HOCL_DIP_TYPE1	0x0000ff00 /*  */
	#define BMSK_HDMI_RX_HOCL_DIP_TYPE0	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HOCL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HOCL_RSVD1	 0x10d0, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HOCL_DIP_TYPE1	 0x10d0, 8, 8, 0x0000ff00
	#define BITFIELD_HDMI_RX_HOCL_DIP_TYPE0	 0x10d0, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HTCL	0x10e0 /* HDMI_TS_CTRL                                      */ 
	#define BITFIELD_HDMI_RX_HTCL	 0x10e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HTCL */
	#define BLSB_HDMI_RX_HTCL_RSVD1	3
	#define BLSB_HDMI_RX_HTCL_IF_TS_SEL	2
	#define BLSB_HDMI_RX_HTCL_AU_TS_SEL	1
	#define BLSB_HDMI_RX_HTCL_SW_RESET	0
	/* Register Bit Widths for HDMI_RX_HTCL */
	#define BWID_HDMI_RX_HTCL_RSVD1	29
	#define BWID_HDMI_RX_HTCL_IF_TS_SEL	1
	#define BWID_HDMI_RX_HTCL_AU_TS_SEL	1
	#define BWID_HDMI_RX_HTCL_SW_RESET	1
	/* Register Bit MASKS for HDMI_RX_HTCL */
	#define BMSK_HDMI_RX_HTCL_RSVD1	0xfffffff8 /*  */
	#define BMSK_HDMI_RX_HTCL_IF_TS_SEL	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_HTCL_AU_TS_SEL	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HTCL_SW_RESET	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HTCL - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HTCL_RSVD1	 0x10e0, 3, 29, 0xfffffff8
	#define BITFIELD_HDMI_RX_HTCL_IF_TS_SEL	 0x10e0, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_HTCL_AU_TS_SEL	 0x10e0, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HTCL_SW_RESET	 0x10e0, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HTCT	0x10e4 /* HDMI_TS_COUNT                                     */ 
	#define BITFIELD_HDMI_RX_HTCT	 0x10e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HHBL	0x2000 /* HDMI HDCP BKSV LSB                                */ 
	#define BITFIELD_HDMI_RX_HHBL	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HHBM	0x2004 /* HDMI HDCP BKSV MSB                                */ 
	#define BITFIELD_HDMI_RX_HHBM	 0x2004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHBM */
	#define BLSB_HDMI_RX_HHBM_RSVD1	8
	#define BLSB_HDMI_RX_HHBM_BKSV1	0
	/* Register Bit Widths for HDMI_RX_HHBM */
	#define BWID_HDMI_RX_HHBM_RSVD1	24
	#define BWID_HDMI_RX_HHBM_BKSV1	8
	/* Register Bit MASKS for HDMI_RX_HHBM */
	#define BMSK_HDMI_RX_HHBM_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HHBM_BKSV1	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HHBM - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHBM_RSVD1	 0x2004, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HHBM_BKSV1	 0x2004, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HHRI	0x2008 /* HDMI HDCP RI                                      */ 
	#define BITFIELD_HDMI_RX_HHRI	 0x2008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHRI */
	#define BLSB_HDMI_RX_HHRI_RSVD1	16
	#define BLSB_HDMI_RX_HHRI_RI	0
	/* Register Bit Widths for HDMI_RX_HHRI */
	#define BWID_HDMI_RX_HHRI_RSVD1	16
	#define BWID_HDMI_RX_HHRI_RI	16
	/* Register Bit MASKS for HDMI_RX_HHRI */
	#define BMSK_HDMI_RX_HHRI_RSVD1	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HHRI_RI	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_HHRI - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHRI_RSVD1	 0x2008, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HHRI_RI	 0x2008, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_HHPJ	0x200c /* HDMI HDCP PJ                                      */ 
	#define BITFIELD_HDMI_RX_HHPJ	 0x200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHPJ */
	#define BLSB_HDMI_RX_HHPJ_RSVD1	8
	#define BLSB_HDMI_RX_HHPJ_PJ	0
	/* Register Bit Widths for HDMI_RX_HHPJ */
	#define BWID_HDMI_RX_HHPJ_RSVD1	24
	#define BWID_HDMI_RX_HHPJ_PJ	8
	/* Register Bit MASKS for HDMI_RX_HHPJ */
	#define BMSK_HDMI_RX_HHPJ_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HHPJ_PJ	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HHPJ - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHPJ_RSVD1	 0x200c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HHPJ_PJ	 0x200c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HHAL	0x2010 /* HDMI HDCP AKSV LSB                                */ 
	#define BITFIELD_HDMI_RX_HHAL	 0x2010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HHAM	0x2014 /* HDMI HDCP AKSV MSB                                */ 
	#define BITFIELD_HDMI_RX_HHAM	 0x2014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHAM */
	#define BLSB_HDMI_RX_HHAM_RSVD1	8
	#define BLSB_HDMI_RX_HHAM_AKSV1	0
	/* Register Bit Widths for HDMI_RX_HHAM */
	#define BWID_HDMI_RX_HHAM_RSVD1	24
	#define BWID_HDMI_RX_HHAM_AKSV1	8
	/* Register Bit MASKS for HDMI_RX_HHAM */
	#define BMSK_HDMI_RX_HHAM_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HHAM_AKSV1	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HHAM - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHAM_RSVD1	 0x2014, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HHAM_AKSV1	 0x2014, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HHAI	0x2018 /* HDMI HDCP AINFO                                   */ 
	#define BITFIELD_HDMI_RX_HHAI	 0x2018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHAI */
	#define BLSB_HDMI_RX_HHAI_RSVD1	8
	#define BLSB_HDMI_RX_HHAI_AINFO_RESERVED2	2
	#define BLSB_HDMI_RX_HHAI_ENABLE_1_1_FEATURES	1
	#define BLSB_HDMI_RX_HHAI_AINFO_RESERVED1	0
	/* Register Bit Widths for HDMI_RX_HHAI */
	#define BWID_HDMI_RX_HHAI_RSVD1	24
	#define BWID_HDMI_RX_HHAI_AINFO_RESERVED2	6
	#define BWID_HDMI_RX_HHAI_ENABLE_1_1_FEATURES	1
	#define BWID_HDMI_RX_HHAI_AINFO_RESERVED1	1
	/* Register Bit MASKS for HDMI_RX_HHAI */
	#define BMSK_HDMI_RX_HHAI_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HHAI_AINFO_RESERVED2	0x000000fc /*  */
	#define BMSK_HDMI_RX_HHAI_ENABLE_1_1_FEATURES	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HHAI_AINFO_RESERVED1	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HHAI - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHAI_RSVD1	 0x2018, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HHAI_AINFO_RESERVED2	 0x2018, 2, 6, 0x000000fc
	#define BITFIELD_HDMI_RX_HHAI_ENABLE_1_1_FEATURES	 0x2018, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HHAI_AINFO_RESERVED1	 0x2018, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HANL	0x2020 /* HDMI HDCP AN LSB                                  */ 
	#define BITFIELD_HDMI_RX_HANL	 0x2020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HANM	0x2024 /* HDMI HDCP AN MSB                                  */ 
	#define BITFIELD_HDMI_RX_HANM	 0x2024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HHBC	0x2050 /* HDMI HDCP BCAPS                                   */ 
	#define BITFIELD_HDMI_RX_HHBC	 0x2050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHBC */
	#define BLSB_HDMI_RX_HHBC_RSVD2	8
	#define BLSB_HDMI_RX_HHBC_HDMI_RESERVED	7
	#define BLSB_HDMI_RX_HHBC_REPEATER	6
	#define BLSB_HDMI_RX_HHBC_KSV_FIFO_READY	5
	#define BLSB_HDMI_RX_HHBC_FAST	4
	#define BLSB_HDMI_RX_HHBC_RSVD1	2
	#define BLSB_HDMI_RX_HHBC_1_1_FEATURES	1
	#define BLSB_HDMI_RX_HHBC_FAST_REAUTHENTICATION	0
	/* Register Bit Widths for HDMI_RX_HHBC */
	#define BWID_HDMI_RX_HHBC_RSVD2	24
	#define BWID_HDMI_RX_HHBC_HDMI_RESERVED	1
	#define BWID_HDMI_RX_HHBC_REPEATER	1
	#define BWID_HDMI_RX_HHBC_KSV_FIFO_READY	1
	#define BWID_HDMI_RX_HHBC_FAST	1
	#define BWID_HDMI_RX_HHBC_RSVD1	2
	#define BWID_HDMI_RX_HHBC_1_1_FEATURES	1
	#define BWID_HDMI_RX_HHBC_FAST_REAUTHENTICATION	1
	/* Register Bit MASKS for HDMI_RX_HHBC */
	#define BMSK_HDMI_RX_HHBC_RSVD2	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HHBC_HDMI_RESERVED	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_HHBC_REPEATER	(1<<6) /* == 0x00000040:  */
	#define BMSK_HDMI_RX_HHBC_KSV_FIFO_READY	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_HHBC_FAST	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_HHBC_RSVD1	0x0000000c /*  */
	#define BMSK_HDMI_RX_HHBC_1_1_FEATURES	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_HHBC_FAST_REAUTHENTICATION	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HHBC - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHBC_RSVD2	 0x2050, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HHBC_HDMI_RESERVED	 0x2050, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_HHBC_REPEATER	 0x2050, 6, 1, 0x00000040
	#define BITFIELD_HDMI_RX_HHBC_KSV_FIFO_READY	 0x2050, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_HHBC_FAST	 0x2050, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_HHBC_RSVD1	 0x2050, 2, 2, 0x0000000c
	#define BITFIELD_HDMI_RX_HHBC_1_1_FEATURES	 0x2050, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_HHBC_FAST_REAUTHENTICATION	 0x2050, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HHBS	0x2054 /* HDMI HDCP BSTAT                                   */ 
	#define BITFIELD_HDMI_RX_HHBS	 0x2054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HHBS */
	#define BLSB_HDMI_RX_HHBS_RSVD2	14
	#define BLSB_HDMI_RX_HHBS_HDMI_RESERVED_2	13
	#define BLSB_HDMI_RX_HHBS_HDMI_MODE	12
	#define BLSB_HDMI_RX_HHBS_MAX_CASCADE_EXCEEDED	11
	#define BLSB_HDMI_RX_HHBS_DEPTH	8
	#define BLSB_HDMI_RX_HHBS_MAX_DEVS_EXCEEDED	7
	#define BLSB_HDMI_RX_HHBS_DEVICE_COUNT	0
	/* Register Bit Widths for HDMI_RX_HHBS */
	#define BWID_HDMI_RX_HHBS_RSVD2	18
	#define BWID_HDMI_RX_HHBS_HDMI_RESERVED_2	1
	#define BWID_HDMI_RX_HHBS_HDMI_MODE	1
	#define BWID_HDMI_RX_HHBS_MAX_CASCADE_EXCEEDED	1
	#define BWID_HDMI_RX_HHBS_DEPTH	3
	#define BWID_HDMI_RX_HHBS_MAX_DEVS_EXCEEDED	1
	#define BWID_HDMI_RX_HHBS_DEVICE_COUNT	7
	/* Register Bit MASKS for HDMI_RX_HHBS */
	#define BMSK_HDMI_RX_HHBS_RSVD2	0xffffc000 /*  */
	#define BMSK_HDMI_RX_HHBS_HDMI_RESERVED_2	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_HHBS_HDMI_MODE	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_HHBS_MAX_CASCADE_EXCEEDED	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_HHBS_DEPTH	0x00000700 /*  */
	#define BMSK_HDMI_RX_HHBS_MAX_DEVS_EXCEEDED	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_HHBS_DEVICE_COUNT	0x0000007f /*  */
	/* Register BITFIELD for HDMI_RX_HHBS - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HHBS_RSVD2	 0x2054, 14, 18, 0xffffc000
	#define BITFIELD_HDMI_RX_HHBS_HDMI_RESERVED_2	 0x2054, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_HHBS_HDMI_MODE	 0x2054, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_HHBS_MAX_CASCADE_EXCEEDED	 0x2054, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_HHBS_DEPTH	 0x2054, 8, 3, 0x00000700
	#define BITFIELD_HDMI_RX_HHBS_MAX_DEVS_EXCEEDED	 0x2054, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_HHBS_DEVICE_COUNT	 0x2054, 0, 7, 0x0000007f
#define ROFF_HDMI_RX_ICRH	0x3000 /* I2C Control Register                              */ 
	#define BITFIELD_HDMI_RX_ICRH	 0x3000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_ICRH */
	#define BLSB_HDMI_RX_ICRH_RSVD1	16
	#define BLSB_HDMI_RX_ICRH_FAST_MODE	15
	#define BLSB_HDMI_RX_ICRH_UNIT_RESET	14
	#define BLSB_HDMI_RX_ICRH_SLAVE_ADDR_DET_INT_EN	13
	#define BLSB_HDMI_RX_ICRH_ARB_LOSS_DET_INT_EN	12
	#define BLSB_HDMI_RX_ICRH_SLAVE_STP_DET_INT_EN	11
	#define BLSB_HDMI_RX_ICRH_BUS_ERR_INT_EN	10
	#define BLSB_HDMI_RX_ICRH_IDBR_RX_FULL_INT_EN	9
	#define BLSB_HDMI_RX_ICRH_IDBR_TX_EMPTY_INT_EN	8
	#define BLSB_HDMI_RX_ICRH_GEN_CALL_DISABLE	7
	#define BLSB_HDMI_RX_ICRH_UNIT_ENABLE	6
	#define BLSB_HDMI_RX_ICRH_SCL_Enable	5
	#define BLSB_HDMI_RX_ICRH_MASTER_STOP	4
	#define BLSB_HDMI_RX_ICRH_TRANFER_BYTE	3
	#define BLSB_HDMI_RX_ICRH_ACK_NACK_CTRL	2
	#define BLSB_HDMI_RX_ICRH_STOP	1
	#define BLSB_HDMI_RX_ICRH_START	0
	/* Register Bit Widths for HDMI_RX_ICRH */
	#define BWID_HDMI_RX_ICRH_RSVD1	16
	#define BWID_HDMI_RX_ICRH_FAST_MODE	1
	#define BWID_HDMI_RX_ICRH_UNIT_RESET	1
	#define BWID_HDMI_RX_ICRH_SLAVE_ADDR_DET_INT_EN	1
	#define BWID_HDMI_RX_ICRH_ARB_LOSS_DET_INT_EN	1
	#define BWID_HDMI_RX_ICRH_SLAVE_STP_DET_INT_EN	1
	#define BWID_HDMI_RX_ICRH_BUS_ERR_INT_EN	1
	#define BWID_HDMI_RX_ICRH_IDBR_RX_FULL_INT_EN	1
	#define BWID_HDMI_RX_ICRH_IDBR_TX_EMPTY_INT_EN	1
	#define BWID_HDMI_RX_ICRH_GEN_CALL_DISABLE	1
	#define BWID_HDMI_RX_ICRH_UNIT_ENABLE	1
	#define BWID_HDMI_RX_ICRH_SCL_Enable	1
	#define BWID_HDMI_RX_ICRH_MASTER_STOP	1
	#define BWID_HDMI_RX_ICRH_TRANFER_BYTE	1
	#define BWID_HDMI_RX_ICRH_ACK_NACK_CTRL	1
	#define BWID_HDMI_RX_ICRH_STOP	1
	#define BWID_HDMI_RX_ICRH_START	1
	/* Register Bit MASKS for HDMI_RX_ICRH */
	#define BMSK_HDMI_RX_ICRH_RSVD1	0xffff0000 /*  */
	#define BMSK_HDMI_RX_ICRH_FAST_MODE	(1<<15) /* == 0x00008000:  */
	#define BMSK_HDMI_RX_ICRH_UNIT_RESET	(1<<14) /* == 0x00004000:  */
	#define BMSK_HDMI_RX_ICRH_SLAVE_ADDR_DET_INT_EN	(1<<13) /* == 0x00002000:  */
	#define BMSK_HDMI_RX_ICRH_ARB_LOSS_DET_INT_EN	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_ICRH_SLAVE_STP_DET_INT_EN	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_ICRH_BUS_ERR_INT_EN	(1<<10) /* == 0x00000400:  */
	#define BMSK_HDMI_RX_ICRH_IDBR_RX_FULL_INT_EN	(1<<9) /* == 0x00000200:  */
	#define BMSK_HDMI_RX_ICRH_IDBR_TX_EMPTY_INT_EN	(1<<8) /* == 0x00000100:  */
	#define BMSK_HDMI_RX_ICRH_GEN_CALL_DISABLE	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_ICRH_UNIT_ENABLE	(1<<6) /* == 0x00000040:  */
	#define BMSK_HDMI_RX_ICRH_SCL_Enable	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_ICRH_MASTER_STOP	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_ICRH_TRANFER_BYTE	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_ICRH_ACK_NACK_CTRL	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_ICRH_STOP	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_ICRH_START	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_ICRH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_ICRH_RSVD1	 0x3000, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_ICRH_FAST_MODE	 0x3000, 15, 1, 0x00008000
	#define BITFIELD_HDMI_RX_ICRH_UNIT_RESET	 0x3000, 14, 1, 0x00004000
	#define BITFIELD_HDMI_RX_ICRH_SLAVE_ADDR_DET_INT_EN	 0x3000, 13, 1, 0x00002000
	#define BITFIELD_HDMI_RX_ICRH_ARB_LOSS_DET_INT_EN	 0x3000, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_ICRH_SLAVE_STP_DET_INT_EN	 0x3000, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_ICRH_BUS_ERR_INT_EN	 0x3000, 10, 1, 0x00000400
	#define BITFIELD_HDMI_RX_ICRH_IDBR_RX_FULL_INT_EN	 0x3000, 9, 1, 0x00000200
	#define BITFIELD_HDMI_RX_ICRH_IDBR_TX_EMPTY_INT_EN	 0x3000, 8, 1, 0x00000100
	#define BITFIELD_HDMI_RX_ICRH_GEN_CALL_DISABLE	 0x3000, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_ICRH_UNIT_ENABLE	 0x3000, 6, 1, 0x00000040
	#define BITFIELD_HDMI_RX_ICRH_SCL_Enable	 0x3000, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_ICRH_MASTER_STOP	 0x3000, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_ICRH_TRANFER_BYTE	 0x3000, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_ICRH_ACK_NACK_CTRL	 0x3000, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_ICRH_STOP	 0x3000, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_ICRH_START	 0x3000, 0, 1, 0x00000001
#define ROFF_HDMI_RX_ISRH	0x3004 /* I2C Status Register                               */ 
	#define BITFIELD_HDMI_RX_ISRH	 0x3004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_ISRH */
	#define BLSB_HDMI_RX_ISRH_RSVD1	13
	#define BLSB_HDMI_RX_ISRH_SEG_PTR_ADDR_DET	12
	#define BLSB_HDMI_RX_ISRH_EDID_SLAVE_ADDR_DET	11
	#define BLSB_HDMI_RX_ISRH_BUS_ERR_DET	10
	#define BLSB_HDMI_RX_ISRH_HDCP_SLAVE_ADDR_DET	9
	#define BLSB_HDMI_RX_ISRH_GEN_CALL_ADDR_DET	8
	#define BLSB_HDMI_RX_ISRH_IDBR_RX_FULL	7
	#define BLSB_HDMI_RX_ISRH_IDBR_TX_EMPTY	6
	#define BLSB_HDMI_RX_ISRH_ARB_LOSS_DET	5
	#define BLSB_HDMI_RX_ISRH_SLAVE_STP_DET	4
	#define BLSB_HDMI_RX_ISRH_BUS_BUSY	3
	#define BLSB_HDMI_RX_ISRH_UNIT_BUSY	2
	#define BLSB_HDMI_RX_ISRH_ACK_NACK_STATUS	1
	#define BLSB_HDMI_RX_ISRH_RD_WR_MODE	0
	/* Register Bit Widths for HDMI_RX_ISRH */
	#define BWID_HDMI_RX_ISRH_RSVD1	19
	#define BWID_HDMI_RX_ISRH_SEG_PTR_ADDR_DET	1
	#define BWID_HDMI_RX_ISRH_EDID_SLAVE_ADDR_DET	1
	#define BWID_HDMI_RX_ISRH_BUS_ERR_DET	1
	#define BWID_HDMI_RX_ISRH_HDCP_SLAVE_ADDR_DET	1
	#define BWID_HDMI_RX_ISRH_GEN_CALL_ADDR_DET	1
	#define BWID_HDMI_RX_ISRH_IDBR_RX_FULL	1
	#define BWID_HDMI_RX_ISRH_IDBR_TX_EMPTY	1
	#define BWID_HDMI_RX_ISRH_ARB_LOSS_DET	1
	#define BWID_HDMI_RX_ISRH_SLAVE_STP_DET	1
	#define BWID_HDMI_RX_ISRH_BUS_BUSY	1
	#define BWID_HDMI_RX_ISRH_UNIT_BUSY	1
	#define BWID_HDMI_RX_ISRH_ACK_NACK_STATUS	1
	#define BWID_HDMI_RX_ISRH_RD_WR_MODE	1
	/* Register Bit MASKS for HDMI_RX_ISRH */
	#define BMSK_HDMI_RX_ISRH_RSVD1	0xffffe000 /*  */
	#define BMSK_HDMI_RX_ISRH_SEG_PTR_ADDR_DET	(1<<12) /* == 0x00001000:  */
	#define BMSK_HDMI_RX_ISRH_EDID_SLAVE_ADDR_DET	(1<<11) /* == 0x00000800:  */
	#define BMSK_HDMI_RX_ISRH_BUS_ERR_DET	(1<<10) /* == 0x00000400:  */
	#define BMSK_HDMI_RX_ISRH_HDCP_SLAVE_ADDR_DET	(1<<9) /* == 0x00000200:  */
	#define BMSK_HDMI_RX_ISRH_GEN_CALL_ADDR_DET	(1<<8) /* == 0x00000100:  */
	#define BMSK_HDMI_RX_ISRH_IDBR_RX_FULL	(1<<7) /* == 0x00000080:  */
	#define BMSK_HDMI_RX_ISRH_IDBR_TX_EMPTY	(1<<6) /* == 0x00000040:  */
	#define BMSK_HDMI_RX_ISRH_ARB_LOSS_DET	(1<<5) /* == 0x00000020:  */
	#define BMSK_HDMI_RX_ISRH_SLAVE_STP_DET	(1<<4) /* == 0x00000010:  */
	#define BMSK_HDMI_RX_ISRH_BUS_BUSY	(1<<3) /* == 0x00000008:  */
	#define BMSK_HDMI_RX_ISRH_UNIT_BUSY	(1<<2) /* == 0x00000004:  */
	#define BMSK_HDMI_RX_ISRH_ACK_NACK_STATUS	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_ISRH_RD_WR_MODE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_ISRH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_ISRH_RSVD1	 0x3004, 13, 19, 0xffffe000
	#define BITFIELD_HDMI_RX_ISRH_SEG_PTR_ADDR_DET	 0x3004, 12, 1, 0x00001000
	#define BITFIELD_HDMI_RX_ISRH_EDID_SLAVE_ADDR_DET	 0x3004, 11, 1, 0x00000800
	#define BITFIELD_HDMI_RX_ISRH_BUS_ERR_DET	 0x3004, 10, 1, 0x00000400
	#define BITFIELD_HDMI_RX_ISRH_HDCP_SLAVE_ADDR_DET	 0x3004, 9, 1, 0x00000200
	#define BITFIELD_HDMI_RX_ISRH_GEN_CALL_ADDR_DET	 0x3004, 8, 1, 0x00000100
	#define BITFIELD_HDMI_RX_ISRH_IDBR_RX_FULL	 0x3004, 7, 1, 0x00000080
	#define BITFIELD_HDMI_RX_ISRH_IDBR_TX_EMPTY	 0x3004, 6, 1, 0x00000040
	#define BITFIELD_HDMI_RX_ISRH_ARB_LOSS_DET	 0x3004, 5, 1, 0x00000020
	#define BITFIELD_HDMI_RX_ISRH_SLAVE_STP_DET	 0x3004, 4, 1, 0x00000010
	#define BITFIELD_HDMI_RX_ISRH_BUS_BUSY	 0x3004, 3, 1, 0x00000008
	#define BITFIELD_HDMI_RX_ISRH_UNIT_BUSY	 0x3004, 2, 1, 0x00000004
	#define BITFIELD_HDMI_RX_ISRH_ACK_NACK_STATUS	 0x3004, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_ISRH_RD_WR_MODE	 0x3004, 0, 1, 0x00000001
#define ROFF_HDMI_RX_ISARH	0x3008 /* I2C Slave Address Register                        */ 
	#define BITFIELD_HDMI_RX_ISARH	 0x3008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_ISARH */
	#define BLSB_HDMI_RX_ISARH_RSVD1	14
	#define BLSB_HDMI_RX_ISARH_SEG_PTR	7
	#define BLSB_HDMI_RX_ISARH_SLAVE_ADDR	0
	/* Register Bit Widths for HDMI_RX_ISARH */
	#define BWID_HDMI_RX_ISARH_RSVD1	18
	#define BWID_HDMI_RX_ISARH_SEG_PTR	7
	#define BWID_HDMI_RX_ISARH_SLAVE_ADDR	7
	/* Register Bit MASKS for HDMI_RX_ISARH */
	#define BMSK_HDMI_RX_ISARH_RSVD1	0xffffc000 /*  */
	#define BMSK_HDMI_RX_ISARH_SEG_PTR	0x00003f80 /*  */
	#define BMSK_HDMI_RX_ISARH_SLAVE_ADDR	0x0000007f /*  */
	/* Register BITFIELD for HDMI_RX_ISARH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_ISARH_RSVD1	 0x3008, 14, 18, 0xffffc000
	#define BITFIELD_HDMI_RX_ISARH_SEG_PTR	 0x3008, 7, 7, 0x00003f80
	#define BITFIELD_HDMI_RX_ISARH_SLAVE_ADDR	 0x3008, 0, 7, 0x0000007f
#define ROFF_HDMI_RX_IDBRH	0x300c /* I2C Data Buffer Register                          */ 
	#define BITFIELD_HDMI_RX_IDBRH	 0x300c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IDBRH */
	#define BLSB_HDMI_RX_IDBRH_RSVD1	8
	#define BLSB_HDMI_RX_IDBRH_DATA_BUFFER	0
	/* Register Bit Widths for HDMI_RX_IDBRH */
	#define BWID_HDMI_RX_IDBRH_RSVD1	24
	#define BWID_HDMI_RX_IDBRH_DATA_BUFFER	8
	/* Register Bit MASKS for HDMI_RX_IDBRH */
	#define BMSK_HDMI_RX_IDBRH_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_IDBRH_DATA_BUFFER	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_IDBRH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IDBRH_RSVD1	 0x300c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_IDBRH_DATA_BUFFER	 0x300c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_IBMRH	0x3014 /* I2C Bus Monitor Register                          */ 
	#define BITFIELD_HDMI_RX_IBMRH	 0x3014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IBMRH */
	#define BLSB_HDMI_RX_IBMRH_RSVD1	2
	#define BLSB_HDMI_RX_IBMRH_SCL_STATUS	1
	#define BLSB_HDMI_RX_IBMRH_SDA_STATUS	0
	/* Register Bit Widths for HDMI_RX_IBMRH */
	#define BWID_HDMI_RX_IBMRH_RSVD1	30
	#define BWID_HDMI_RX_IBMRH_SCL_STATUS	1
	#define BWID_HDMI_RX_IBMRH_SDA_STATUS	1
	/* Register Bit MASKS for HDMI_RX_IBMRH */
	#define BMSK_HDMI_RX_IBMRH_RSVD1	0xfffffffc /*  */
	#define BMSK_HDMI_RX_IBMRH_SCL_STATUS	(1<<1) /* == 0x00000002:  */
	#define BMSK_HDMI_RX_IBMRH_SDA_STATUS	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_IBMRH - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IBMRH_RSVD1	 0x3014, 2, 30, 0xfffffffc
	#define BITFIELD_HDMI_RX_IBMRH_SCL_STATUS	 0x3014, 1, 1, 0x00000002
	#define BITFIELD_HDMI_RX_IBMRH_SDA_STATUS	 0x3014, 0, 1, 0x00000001
#define ROFF_HDMI_RX_IWCR	0x3018 /* I2C Wait Count Register                           */ 
	#define BITFIELD_HDMI_RX_IWCR	 0x3018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IWCR */
	#define BLSB_HDMI_RX_IWCR_RSVD1	5
	#define BLSB_HDMI_RX_IWCR_WAIT_CNT	0
	/* Register Bit Widths for HDMI_RX_IWCR */
	#define BWID_HDMI_RX_IWCR_RSVD1	27
	#define BWID_HDMI_RX_IWCR_WAIT_CNT	5
	/* Register Bit MASKS for HDMI_RX_IWCR */
	#define BMSK_HDMI_RX_IWCR_RSVD1	0xffffffe0 /*  */
	#define BMSK_HDMI_RX_IWCR_WAIT_CNT	0x0000001f /*  */
	/* Register BITFIELD for HDMI_RX_IWCR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IWCR_RSVD1	 0x3018, 5, 27, 0xffffffe0
	#define BITFIELD_HDMI_RX_IWCR_WAIT_CNT	 0x3018, 0, 5, 0x0000001f
#define ROFF_HDMI_RX_ISMSCR	0x301c /* I2C Standard Mode Short Count Register            */ 
	#define BITFIELD_HDMI_RX_ISMSCR	 0x301c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_ISMSCR */
	#define BLSB_HDMI_RX_ISMSCR_RSVD1	9
	#define BLSB_HDMI_RX_ISMSCR_SHORT_COUNT	0
	/* Register Bit Widths for HDMI_RX_ISMSCR */
	#define BWID_HDMI_RX_ISMSCR_RSVD1	23
	#define BWID_HDMI_RX_ISMSCR_SHORT_COUNT	9
	/* Register Bit MASKS for HDMI_RX_ISMSCR */
	#define BMSK_HDMI_RX_ISMSCR_RSVD1	0xfffffe00 /*  */
	#define BMSK_HDMI_RX_ISMSCR_SHORT_COUNT	0x000001ff /*  */
	/* Register BITFIELD for HDMI_RX_ISMSCR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_ISMSCR_RSVD1	 0x301c, 9, 23, 0xfffffe00
	#define BITFIELD_HDMI_RX_ISMSCR_SHORT_COUNT	 0x301c, 0, 9, 0x000001ff
#define ROFF_HDMI_RX_ISMLCR	0x3020 /* I2C Standard Mode Long Count Register             */ 
	#define BITFIELD_HDMI_RX_ISMLCR	 0x3020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_ISMLCR */
	#define BLSB_HDMI_RX_ISMLCR_RSVD1	9
	#define BLSB_HDMI_RX_ISMLCR_LONG_COUNT	0
	/* Register Bit Widths for HDMI_RX_ISMLCR */
	#define BWID_HDMI_RX_ISMLCR_RSVD1	23
	#define BWID_HDMI_RX_ISMLCR_LONG_COUNT	9
	/* Register Bit MASKS for HDMI_RX_ISMLCR */
	#define BMSK_HDMI_RX_ISMLCR_RSVD1	0xfffffe00 /*  */
	#define BMSK_HDMI_RX_ISMLCR_LONG_COUNT	0x000001ff /*  */
	/* Register BITFIELD for HDMI_RX_ISMLCR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_ISMLCR_RSVD1	 0x3020, 9, 23, 0xfffffe00
	#define BITFIELD_HDMI_RX_ISMLCR_LONG_COUNT	 0x3020, 0, 9, 0x000001ff
#define ROFF_HDMI_RX_IFMSCR	0x3024 /* I2C Fast Mode Short Count Register                */ 
	#define BITFIELD_HDMI_RX_IFMSCR	 0x3024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IFMSCR */
	#define BLSB_HDMI_RX_IFMSCR_RSVD1	9
	#define BLSB_HDMI_RX_IFMSCR_SHORT_COUNT	0
	/* Register Bit Widths for HDMI_RX_IFMSCR */
	#define BWID_HDMI_RX_IFMSCR_RSVD1	23
	#define BWID_HDMI_RX_IFMSCR_SHORT_COUNT	9
	/* Register Bit MASKS for HDMI_RX_IFMSCR */
	#define BMSK_HDMI_RX_IFMSCR_RSVD1	0xfffffe00 /*  */
	#define BMSK_HDMI_RX_IFMSCR_SHORT_COUNT	0x000001ff /*  */
	/* Register BITFIELD for HDMI_RX_IFMSCR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IFMSCR_RSVD1	 0x3024, 9, 23, 0xfffffe00
	#define BITFIELD_HDMI_RX_IFMSCR_SHORT_COUNT	 0x3024, 0, 9, 0x000001ff
#define ROFF_HDMI_RX_IFMLCR	0x3028 /* I2C Fast Mode Long Count Register                 */ 
	#define BITFIELD_HDMI_RX_IFMLCR	 0x3028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IFMLCR */
	#define BLSB_HDMI_RX_IFMLCR_RSVD1	9
	#define BLSB_HDMI_RX_IFMLCR_LONG_COUNT	0
	/* Register Bit Widths for HDMI_RX_IFMLCR */
	#define BWID_HDMI_RX_IFMLCR_RSVD1	23
	#define BWID_HDMI_RX_IFMLCR_LONG_COUNT	9
	/* Register Bit MASKS for HDMI_RX_IFMLCR */
	#define BMSK_HDMI_RX_IFMLCR_RSVD1	0xfffffe00 /*  */
	#define BMSK_HDMI_RX_IFMLCR_LONG_COUNT	0x000001ff /*  */
	/* Register BITFIELD for HDMI_RX_IFMLCR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IFMLCR_RSVD1	 0x3028, 9, 23, 0xfffffe00
	#define BITFIELD_HDMI_RX_IFMLCR_LONG_COUNT	 0x3028, 0, 9, 0x000001ff
#define ROFF_HDMI_RX_IDLBR	0x302c /* I2C DDS Rate Lower Byte Register                  */ 
	#define BITFIELD_HDMI_RX_IDLBR	 0x302c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IDLBR */
	#define BLSB_HDMI_RX_IDLBR_RSVD1	16
	#define BLSB_HDMI_RX_IDLBR_DDSLB	0
	/* Register Bit Widths for HDMI_RX_IDLBR */
	#define BWID_HDMI_RX_IDLBR_RSVD1	16
	#define BWID_HDMI_RX_IDLBR_DDSLB	16
	/* Register Bit MASKS for HDMI_RX_IDLBR */
	#define BMSK_HDMI_RX_IDLBR_RSVD1	0xffff0000 /*  */
	#define BMSK_HDMI_RX_IDLBR_DDSLB	0x0000ffff /*  */
	/* Register BITFIELD for HDMI_RX_IDLBR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IDLBR_RSVD1	 0x302c, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_IDLBR_DDSLB	 0x302c, 0, 16, 0x0000ffff
#define ROFF_HDMI_RX_IDUBR	0x3030 /* I2C DDS Rate Upper Byte Register                  */ 
	#define BITFIELD_HDMI_RX_IDUBR	 0x3030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_IDUBR */
	#define BLSB_HDMI_RX_IDUBR_RSVD1	8
	#define BLSB_HDMI_RX_IDUBR_DDSUB	0
	/* Register Bit Widths for HDMI_RX_IDUBR */
	#define BWID_HDMI_RX_IDUBR_RSVD1	24
	#define BWID_HDMI_RX_IDUBR_DDSUB	8
	/* Register Bit MASKS for HDMI_RX_IDUBR */
	#define BMSK_HDMI_RX_IDUBR_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_IDUBR_DDSUB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_IDUBR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_IDUBR_RSVD1	 0x3030, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_IDUBR_DDSUB	 0x3030, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HEAR	0x3900 /* HDMI EDID Address Register                        */ 
	#define BITFIELD_HDMI_RX_HEAR	 0x3900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HEAR */
	#define BLSB_HDMI_RX_HEAR_RSVD1	16
	#define BLSB_HDMI_RX_HEAR_SEG_PTR	8
	#define BLSB_HDMI_RX_HEAR_OFFSET	0
	/* Register Bit Widths for HDMI_RX_HEAR */
	#define BWID_HDMI_RX_HEAR_RSVD1	16
	#define BWID_HDMI_RX_HEAR_SEG_PTR	8
	#define BWID_HDMI_RX_HEAR_OFFSET	8
	/* Register Bit MASKS for HDMI_RX_HEAR */
	#define BMSK_HDMI_RX_HEAR_RSVD1	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HEAR_SEG_PTR	0x0000ff00 /*  */
	#define BMSK_HDMI_RX_HEAR_OFFSET	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HEAR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HEAR_RSVD1	 0x3900, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HEAR_SEG_PTR	 0x3900, 8, 8, 0x0000ff00
	#define BITFIELD_HDMI_RX_HEAR_OFFSET	 0x3900, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HECR	0x3904 /* HDMI EDID Buffer Control Register                 */ 
	#define BITFIELD_HDMI_RX_HECR	 0x3904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HECR */
	#define BLSB_HDMI_RX_HECR_RSVD2	16
	#define BLSB_HDMI_RX_HECR_SEG_PTR	8
	#define BLSB_HDMI_RX_HECR_RSVD1	1
	#define BLSB_HDMI_RX_HECR_EDID_BUF_VLD	0
	/* Register Bit Widths for HDMI_RX_HECR */
	#define BWID_HDMI_RX_HECR_RSVD2	16
	#define BWID_HDMI_RX_HECR_SEG_PTR	8
	#define BWID_HDMI_RX_HECR_RSVD1	7
	#define BWID_HDMI_RX_HECR_EDID_BUF_VLD	1
	/* Register Bit MASKS for HDMI_RX_HECR */
	#define BMSK_HDMI_RX_HECR_RSVD2	0xffff0000 /*  */
	#define BMSK_HDMI_RX_HECR_SEG_PTR	0x0000ff00 /*  */
	#define BMSK_HDMI_RX_HECR_RSVD1	0x000000fe /*  */
	#define BMSK_HDMI_RX_HECR_EDID_BUF_VLD	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for HDMI_RX_HECR - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HECR_RSVD2	 0x3904, 16, 16, 0xffff0000
	#define BITFIELD_HDMI_RX_HECR_SEG_PTR	 0x3904, 8, 8, 0x0000ff00
	#define BITFIELD_HDMI_RX_HECR_RSVD1	 0x3904, 1, 7, 0x000000fe
	#define BITFIELD_HDMI_RX_HECR_EDID_BUF_VLD	 0x3904, 0, 1, 0x00000001
#define ROFF_HDMI_RX_HKFL_0	0x2400 /* HDMI HDCP KSV FIFO 0 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_0	 0x2400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_0	0x2404 /* HDMI HDCP KSV FIFO 0 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_0	 0x2404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_0 */
	#define BLSB_HDMI_RX_HKFM_0_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_0_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_0 */
	#define BWID_HDMI_RX_HKFM_0_RSVD1	24
	#define BWID_HDMI_RX_HKFM_0_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_0 */
	#define BMSK_HDMI_RX_HKFM_0_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_0_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_0 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_0_RSVD1	 0x2404, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_0_KSV_MSB	 0x2404, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_1	0x2408 /* HDMI HDCP KSV FIFO 1 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_1	 0x2408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_1	0x240c /* HDMI HDCP KSV FIFO 1 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_1	 0x240c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_1 */
	#define BLSB_HDMI_RX_HKFM_1_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_1_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_1 */
	#define BWID_HDMI_RX_HKFM_1_RSVD1	24
	#define BWID_HDMI_RX_HKFM_1_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_1 */
	#define BMSK_HDMI_RX_HKFM_1_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_1_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_1 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_1_RSVD1	 0x240c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_1_KSV_MSB	 0x240c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_2	0x2410 /* HDMI HDCP KSV FIFO 2 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_2	 0x2410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_2	0x2414 /* HDMI HDCP KSV FIFO 2 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_2	 0x2414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_2 */
	#define BLSB_HDMI_RX_HKFM_2_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_2_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_2 */
	#define BWID_HDMI_RX_HKFM_2_RSVD1	24
	#define BWID_HDMI_RX_HKFM_2_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_2 */
	#define BMSK_HDMI_RX_HKFM_2_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_2_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_2 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_2_RSVD1	 0x2414, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_2_KSV_MSB	 0x2414, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_3	0x2418 /* HDMI HDCP KSV FIFO 3 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_3	 0x2418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_3	0x241c /* HDMI HDCP KSV FIFO 3 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_3	 0x241c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_3 */
	#define BLSB_HDMI_RX_HKFM_3_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_3_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_3 */
	#define BWID_HDMI_RX_HKFM_3_RSVD1	24
	#define BWID_HDMI_RX_HKFM_3_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_3 */
	#define BMSK_HDMI_RX_HKFM_3_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_3_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_3 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_3_RSVD1	 0x241c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_3_KSV_MSB	 0x241c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_4	0x2420 /* HDMI HDCP KSV FIFO 4 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_4	 0x2420, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_4	0x2424 /* HDMI HDCP KSV FIFO 4 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_4	 0x2424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_4 */
	#define BLSB_HDMI_RX_HKFM_4_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_4_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_4 */
	#define BWID_HDMI_RX_HKFM_4_RSVD1	24
	#define BWID_HDMI_RX_HKFM_4_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_4 */
	#define BMSK_HDMI_RX_HKFM_4_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_4_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_4 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_4_RSVD1	 0x2424, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_4_KSV_MSB	 0x2424, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_5	0x2428 /* HDMI HDCP KSV FIFO 5 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_5	 0x2428, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_5	0x242c /* HDMI HDCP KSV FIFO 5 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_5	 0x242c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_5 */
	#define BLSB_HDMI_RX_HKFM_5_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_5_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_5 */
	#define BWID_HDMI_RX_HKFM_5_RSVD1	24
	#define BWID_HDMI_RX_HKFM_5_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_5 */
	#define BMSK_HDMI_RX_HKFM_5_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_5_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_5 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_5_RSVD1	 0x242c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_5_KSV_MSB	 0x242c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_6	0x2430 /* HDMI HDCP KSV FIFO 6 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_6	 0x2430, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_6	0x2434 /* HDMI HDCP KSV FIFO 6 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_6	 0x2434, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_6 */
	#define BLSB_HDMI_RX_HKFM_6_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_6_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_6 */
	#define BWID_HDMI_RX_HKFM_6_RSVD1	24
	#define BWID_HDMI_RX_HKFM_6_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_6 */
	#define BMSK_HDMI_RX_HKFM_6_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_6_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_6 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_6_RSVD1	 0x2434, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_6_KSV_MSB	 0x2434, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_7	0x2438 /* HDMI HDCP KSV FIFO 7 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_7	 0x2438, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_7	0x243c /* HDMI HDCP KSV FIFO 7 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_7	 0x243c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_7 */
	#define BLSB_HDMI_RX_HKFM_7_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_7_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_7 */
	#define BWID_HDMI_RX_HKFM_7_RSVD1	24
	#define BWID_HDMI_RX_HKFM_7_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_7 */
	#define BMSK_HDMI_RX_HKFM_7_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_7_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_7 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_7_RSVD1	 0x243c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_7_KSV_MSB	 0x243c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_8	0x2440 /* HDMI HDCP KSV FIFO 8 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_8	 0x2440, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_8	0x2444 /* HDMI HDCP KSV FIFO 8 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_8	 0x2444, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_8 */
	#define BLSB_HDMI_RX_HKFM_8_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_8_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_8 */
	#define BWID_HDMI_RX_HKFM_8_RSVD1	24
	#define BWID_HDMI_RX_HKFM_8_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_8 */
	#define BMSK_HDMI_RX_HKFM_8_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_8_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_8 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_8_RSVD1	 0x2444, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_8_KSV_MSB	 0x2444, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_9	0x2448 /* HDMI HDCP KSV FIFO 9 LSB                          */ 
	#define BITFIELD_HDMI_RX_HKFL_9	 0x2448, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_9	0x244c /* HDMI HDCP KSV FIFO 9 MSB                          */ 
	#define BITFIELD_HDMI_RX_HKFM_9	 0x244c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_9 */
	#define BLSB_HDMI_RX_HKFM_9_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_9_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_9 */
	#define BWID_HDMI_RX_HKFM_9_RSVD1	24
	#define BWID_HDMI_RX_HKFM_9_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_9 */
	#define BMSK_HDMI_RX_HKFM_9_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_9_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_9 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_9_RSVD1	 0x244c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_9_KSV_MSB	 0x244c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_10	0x2450 /* HDMI HDCP KSV FIFO 10 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_10	 0x2450, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_10	0x2454 /* HDMI HDCP KSV FIFO 10 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_10	 0x2454, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_10 */
	#define BLSB_HDMI_RX_HKFM_10_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_10_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_10 */
	#define BWID_HDMI_RX_HKFM_10_RSVD1	24
	#define BWID_HDMI_RX_HKFM_10_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_10 */
	#define BMSK_HDMI_RX_HKFM_10_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_10_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_10 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_10_RSVD1	 0x2454, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_10_KSV_MSB	 0x2454, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_11	0x2458 /* HDMI HDCP KSV FIFO 11 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_11	 0x2458, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_11	0x245c /* HDMI HDCP KSV FIFO 11 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_11	 0x245c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_11 */
	#define BLSB_HDMI_RX_HKFM_11_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_11_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_11 */
	#define BWID_HDMI_RX_HKFM_11_RSVD1	24
	#define BWID_HDMI_RX_HKFM_11_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_11 */
	#define BMSK_HDMI_RX_HKFM_11_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_11_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_11 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_11_RSVD1	 0x245c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_11_KSV_MSB	 0x245c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_12	0x2460 /* HDMI HDCP KSV FIFO 12 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_12	 0x2460, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_12	0x2464 /* HDMI HDCP KSV FIFO 12 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_12	 0x2464, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_12 */
	#define BLSB_HDMI_RX_HKFM_12_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_12_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_12 */
	#define BWID_HDMI_RX_HKFM_12_RSVD1	24
	#define BWID_HDMI_RX_HKFM_12_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_12 */
	#define BMSK_HDMI_RX_HKFM_12_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_12_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_12 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_12_RSVD1	 0x2464, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_12_KSV_MSB	 0x2464, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_13	0x2468 /* HDMI HDCP KSV FIFO 13 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_13	 0x2468, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_13	0x246c /* HDMI HDCP KSV FIFO 13 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_13	 0x246c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_13 */
	#define BLSB_HDMI_RX_HKFM_13_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_13_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_13 */
	#define BWID_HDMI_RX_HKFM_13_RSVD1	24
	#define BWID_HDMI_RX_HKFM_13_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_13 */
	#define BMSK_HDMI_RX_HKFM_13_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_13_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_13 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_13_RSVD1	 0x246c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_13_KSV_MSB	 0x246c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_14	0x2470 /* HDMI HDCP KSV FIFO 14 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_14	 0x2470, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_14	0x2474 /* HDMI HDCP KSV FIFO 14 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_14	 0x2474, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_14 */
	#define BLSB_HDMI_RX_HKFM_14_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_14_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_14 */
	#define BWID_HDMI_RX_HKFM_14_RSVD1	24
	#define BWID_HDMI_RX_HKFM_14_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_14 */
	#define BMSK_HDMI_RX_HKFM_14_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_14_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_14 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_14_RSVD1	 0x2474, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_14_KSV_MSB	 0x2474, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_15	0x2478 /* HDMI HDCP KSV FIFO 15 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_15	 0x2478, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_15	0x247c /* HDMI HDCP KSV FIFO 15 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_15	 0x247c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_15 */
	#define BLSB_HDMI_RX_HKFM_15_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_15_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_15 */
	#define BWID_HDMI_RX_HKFM_15_RSVD1	24
	#define BWID_HDMI_RX_HKFM_15_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_15 */
	#define BMSK_HDMI_RX_HKFM_15_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_15_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_15 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_15_RSVD1	 0x247c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_15_KSV_MSB	 0x247c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_16	0x2480 /* HDMI HDCP KSV FIFO 16 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_16	 0x2480, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_16	0x2484 /* HDMI HDCP KSV FIFO 16 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_16	 0x2484, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_16 */
	#define BLSB_HDMI_RX_HKFM_16_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_16_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_16 */
	#define BWID_HDMI_RX_HKFM_16_RSVD1	24
	#define BWID_HDMI_RX_HKFM_16_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_16 */
	#define BMSK_HDMI_RX_HKFM_16_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_16_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_16 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_16_RSVD1	 0x2484, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_16_KSV_MSB	 0x2484, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_17	0x2488 /* HDMI HDCP KSV FIFO 17 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_17	 0x2488, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_17	0x248c /* HDMI HDCP KSV FIFO 17 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_17	 0x248c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_17 */
	#define BLSB_HDMI_RX_HKFM_17_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_17_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_17 */
	#define BWID_HDMI_RX_HKFM_17_RSVD1	24
	#define BWID_HDMI_RX_HKFM_17_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_17 */
	#define BMSK_HDMI_RX_HKFM_17_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_17_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_17 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_17_RSVD1	 0x248c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_17_KSV_MSB	 0x248c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_18	0x2490 /* HDMI HDCP KSV FIFO 18 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_18	 0x2490, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_18	0x2494 /* HDMI HDCP KSV FIFO 18 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_18	 0x2494, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_18 */
	#define BLSB_HDMI_RX_HKFM_18_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_18_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_18 */
	#define BWID_HDMI_RX_HKFM_18_RSVD1	24
	#define BWID_HDMI_RX_HKFM_18_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_18 */
	#define BMSK_HDMI_RX_HKFM_18_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_18_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_18 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_18_RSVD1	 0x2494, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_18_KSV_MSB	 0x2494, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_19	0x2498 /* HDMI HDCP KSV FIFO 19 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_19	 0x2498, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_19	0x249c /* HDMI HDCP KSV FIFO 19 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_19	 0x249c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_19 */
	#define BLSB_HDMI_RX_HKFM_19_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_19_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_19 */
	#define BWID_HDMI_RX_HKFM_19_RSVD1	24
	#define BWID_HDMI_RX_HKFM_19_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_19 */
	#define BMSK_HDMI_RX_HKFM_19_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_19_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_19 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_19_RSVD1	 0x249c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_19_KSV_MSB	 0x249c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_20	0x24a0 /* HDMI HDCP KSV FIFO 20 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_20	 0x24a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_20	0x24a4 /* HDMI HDCP KSV FIFO 20 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_20	 0x24a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_20 */
	#define BLSB_HDMI_RX_HKFM_20_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_20_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_20 */
	#define BWID_HDMI_RX_HKFM_20_RSVD1	24
	#define BWID_HDMI_RX_HKFM_20_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_20 */
	#define BMSK_HDMI_RX_HKFM_20_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_20_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_20 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_20_RSVD1	 0x24a4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_20_KSV_MSB	 0x24a4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_21	0x24a8 /* HDMI HDCP KSV FIFO 21 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_21	 0x24a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_21	0x24ac /* HDMI HDCP KSV FIFO 21 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_21	 0x24ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_21 */
	#define BLSB_HDMI_RX_HKFM_21_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_21_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_21 */
	#define BWID_HDMI_RX_HKFM_21_RSVD1	24
	#define BWID_HDMI_RX_HKFM_21_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_21 */
	#define BMSK_HDMI_RX_HKFM_21_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_21_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_21 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_21_RSVD1	 0x24ac, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_21_KSV_MSB	 0x24ac, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_22	0x24b0 /* HDMI HDCP KSV FIFO 22 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_22	 0x24b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_22	0x24b4 /* HDMI HDCP KSV FIFO 22 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_22	 0x24b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_22 */
	#define BLSB_HDMI_RX_HKFM_22_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_22_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_22 */
	#define BWID_HDMI_RX_HKFM_22_RSVD1	24
	#define BWID_HDMI_RX_HKFM_22_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_22 */
	#define BMSK_HDMI_RX_HKFM_22_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_22_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_22 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_22_RSVD1	 0x24b4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_22_KSV_MSB	 0x24b4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_23	0x24b8 /* HDMI HDCP KSV FIFO 23 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_23	 0x24b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_23	0x24bc /* HDMI HDCP KSV FIFO 23 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_23	 0x24bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_23 */
	#define BLSB_HDMI_RX_HKFM_23_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_23_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_23 */
	#define BWID_HDMI_RX_HKFM_23_RSVD1	24
	#define BWID_HDMI_RX_HKFM_23_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_23 */
	#define BMSK_HDMI_RX_HKFM_23_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_23_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_23 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_23_RSVD1	 0x24bc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_23_KSV_MSB	 0x24bc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_24	0x24c0 /* HDMI HDCP KSV FIFO 24 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_24	 0x24c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_24	0x24c4 /* HDMI HDCP KSV FIFO 24 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_24	 0x24c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_24 */
	#define BLSB_HDMI_RX_HKFM_24_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_24_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_24 */
	#define BWID_HDMI_RX_HKFM_24_RSVD1	24
	#define BWID_HDMI_RX_HKFM_24_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_24 */
	#define BMSK_HDMI_RX_HKFM_24_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_24_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_24 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_24_RSVD1	 0x24c4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_24_KSV_MSB	 0x24c4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_25	0x24c8 /* HDMI HDCP KSV FIFO 25 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_25	 0x24c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_25	0x24cc /* HDMI HDCP KSV FIFO 25 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_25	 0x24cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_25 */
	#define BLSB_HDMI_RX_HKFM_25_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_25_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_25 */
	#define BWID_HDMI_RX_HKFM_25_RSVD1	24
	#define BWID_HDMI_RX_HKFM_25_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_25 */
	#define BMSK_HDMI_RX_HKFM_25_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_25_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_25 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_25_RSVD1	 0x24cc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_25_KSV_MSB	 0x24cc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_26	0x24d0 /* HDMI HDCP KSV FIFO 26 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_26	 0x24d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_26	0x24d4 /* HDMI HDCP KSV FIFO 26 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_26	 0x24d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_26 */
	#define BLSB_HDMI_RX_HKFM_26_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_26_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_26 */
	#define BWID_HDMI_RX_HKFM_26_RSVD1	24
	#define BWID_HDMI_RX_HKFM_26_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_26 */
	#define BMSK_HDMI_RX_HKFM_26_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_26_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_26 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_26_RSVD1	 0x24d4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_26_KSV_MSB	 0x24d4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_27	0x24d8 /* HDMI HDCP KSV FIFO 27 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_27	 0x24d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_27	0x24dc /* HDMI HDCP KSV FIFO 27 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_27	 0x24dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_27 */
	#define BLSB_HDMI_RX_HKFM_27_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_27_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_27 */
	#define BWID_HDMI_RX_HKFM_27_RSVD1	24
	#define BWID_HDMI_RX_HKFM_27_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_27 */
	#define BMSK_HDMI_RX_HKFM_27_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_27_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_27 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_27_RSVD1	 0x24dc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_27_KSV_MSB	 0x24dc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_28	0x24e0 /* HDMI HDCP KSV FIFO 28 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_28	 0x24e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_28	0x24e4 /* HDMI HDCP KSV FIFO 28 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_28	 0x24e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_28 */
	#define BLSB_HDMI_RX_HKFM_28_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_28_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_28 */
	#define BWID_HDMI_RX_HKFM_28_RSVD1	24
	#define BWID_HDMI_RX_HKFM_28_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_28 */
	#define BMSK_HDMI_RX_HKFM_28_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_28_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_28 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_28_RSVD1	 0x24e4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_28_KSV_MSB	 0x24e4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_29	0x24e8 /* HDMI HDCP KSV FIFO 29 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_29	 0x24e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_29	0x24ec /* HDMI HDCP KSV FIFO 29 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_29	 0x24ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_29 */
	#define BLSB_HDMI_RX_HKFM_29_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_29_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_29 */
	#define BWID_HDMI_RX_HKFM_29_RSVD1	24
	#define BWID_HDMI_RX_HKFM_29_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_29 */
	#define BMSK_HDMI_RX_HKFM_29_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_29_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_29 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_29_RSVD1	 0x24ec, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_29_KSV_MSB	 0x24ec, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_30	0x24f0 /* HDMI HDCP KSV FIFO 30 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_30	 0x24f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_30	0x24f4 /* HDMI HDCP KSV FIFO 30 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_30	 0x24f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_30 */
	#define BLSB_HDMI_RX_HKFM_30_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_30_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_30 */
	#define BWID_HDMI_RX_HKFM_30_RSVD1	24
	#define BWID_HDMI_RX_HKFM_30_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_30 */
	#define BMSK_HDMI_RX_HKFM_30_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_30_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_30 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_30_RSVD1	 0x24f4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_30_KSV_MSB	 0x24f4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_31	0x24f8 /* HDMI HDCP KSV FIFO 31 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_31	 0x24f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_31	0x24fc /* HDMI HDCP KSV FIFO 31 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_31	 0x24fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_31 */
	#define BLSB_HDMI_RX_HKFM_31_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_31_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_31 */
	#define BWID_HDMI_RX_HKFM_31_RSVD1	24
	#define BWID_HDMI_RX_HKFM_31_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_31 */
	#define BMSK_HDMI_RX_HKFM_31_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_31_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_31 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_31_RSVD1	 0x24fc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_31_KSV_MSB	 0x24fc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_32	0x2500 /* HDMI HDCP KSV FIFO 32 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_32	 0x2500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_32	0x2504 /* HDMI HDCP KSV FIFO 32 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_32	 0x2504, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_32 */
	#define BLSB_HDMI_RX_HKFM_32_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_32_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_32 */
	#define BWID_HDMI_RX_HKFM_32_RSVD1	24
	#define BWID_HDMI_RX_HKFM_32_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_32 */
	#define BMSK_HDMI_RX_HKFM_32_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_32_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_32 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_32_RSVD1	 0x2504, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_32_KSV_MSB	 0x2504, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_33	0x2508 /* HDMI HDCP KSV FIFO 33 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_33	 0x2508, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_33	0x250c /* HDMI HDCP KSV FIFO 33 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_33	 0x250c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_33 */
	#define BLSB_HDMI_RX_HKFM_33_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_33_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_33 */
	#define BWID_HDMI_RX_HKFM_33_RSVD1	24
	#define BWID_HDMI_RX_HKFM_33_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_33 */
	#define BMSK_HDMI_RX_HKFM_33_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_33_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_33 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_33_RSVD1	 0x250c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_33_KSV_MSB	 0x250c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_34	0x2510 /* HDMI HDCP KSV FIFO 34 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_34	 0x2510, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_34	0x2514 /* HDMI HDCP KSV FIFO 34 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_34	 0x2514, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_34 */
	#define BLSB_HDMI_RX_HKFM_34_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_34_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_34 */
	#define BWID_HDMI_RX_HKFM_34_RSVD1	24
	#define BWID_HDMI_RX_HKFM_34_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_34 */
	#define BMSK_HDMI_RX_HKFM_34_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_34_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_34 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_34_RSVD1	 0x2514, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_34_KSV_MSB	 0x2514, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_35	0x2518 /* HDMI HDCP KSV FIFO 35 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_35	 0x2518, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_35	0x251c /* HDMI HDCP KSV FIFO 35 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_35	 0x251c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_35 */
	#define BLSB_HDMI_RX_HKFM_35_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_35_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_35 */
	#define BWID_HDMI_RX_HKFM_35_RSVD1	24
	#define BWID_HDMI_RX_HKFM_35_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_35 */
	#define BMSK_HDMI_RX_HKFM_35_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_35_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_35 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_35_RSVD1	 0x251c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_35_KSV_MSB	 0x251c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_36	0x2520 /* HDMI HDCP KSV FIFO 36 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_36	 0x2520, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_36	0x2524 /* HDMI HDCP KSV FIFO 36 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_36	 0x2524, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_36 */
	#define BLSB_HDMI_RX_HKFM_36_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_36_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_36 */
	#define BWID_HDMI_RX_HKFM_36_RSVD1	24
	#define BWID_HDMI_RX_HKFM_36_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_36 */
	#define BMSK_HDMI_RX_HKFM_36_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_36_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_36 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_36_RSVD1	 0x2524, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_36_KSV_MSB	 0x2524, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_37	0x2528 /* HDMI HDCP KSV FIFO 37 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_37	 0x2528, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_37	0x252c /* HDMI HDCP KSV FIFO 37 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_37	 0x252c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_37 */
	#define BLSB_HDMI_RX_HKFM_37_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_37_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_37 */
	#define BWID_HDMI_RX_HKFM_37_RSVD1	24
	#define BWID_HDMI_RX_HKFM_37_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_37 */
	#define BMSK_HDMI_RX_HKFM_37_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_37_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_37 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_37_RSVD1	 0x252c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_37_KSV_MSB	 0x252c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_38	0x2530 /* HDMI HDCP KSV FIFO 38 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_38	 0x2530, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_38	0x2534 /* HDMI HDCP KSV FIFO 38 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_38	 0x2534, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_38 */
	#define BLSB_HDMI_RX_HKFM_38_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_38_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_38 */
	#define BWID_HDMI_RX_HKFM_38_RSVD1	24
	#define BWID_HDMI_RX_HKFM_38_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_38 */
	#define BMSK_HDMI_RX_HKFM_38_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_38_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_38 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_38_RSVD1	 0x2534, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_38_KSV_MSB	 0x2534, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_39	0x2538 /* HDMI HDCP KSV FIFO 39 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_39	 0x2538, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_39	0x253c /* HDMI HDCP KSV FIFO 39 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_39	 0x253c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_39 */
	#define BLSB_HDMI_RX_HKFM_39_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_39_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_39 */
	#define BWID_HDMI_RX_HKFM_39_RSVD1	24
	#define BWID_HDMI_RX_HKFM_39_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_39 */
	#define BMSK_HDMI_RX_HKFM_39_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_39_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_39 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_39_RSVD1	 0x253c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_39_KSV_MSB	 0x253c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_40	0x2540 /* HDMI HDCP KSV FIFO 40 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_40	 0x2540, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_40	0x2544 /* HDMI HDCP KSV FIFO 40 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_40	 0x2544, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_40 */
	#define BLSB_HDMI_RX_HKFM_40_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_40_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_40 */
	#define BWID_HDMI_RX_HKFM_40_RSVD1	24
	#define BWID_HDMI_RX_HKFM_40_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_40 */
	#define BMSK_HDMI_RX_HKFM_40_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_40_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_40 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_40_RSVD1	 0x2544, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_40_KSV_MSB	 0x2544, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_41	0x2548 /* HDMI HDCP KSV FIFO 41 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_41	 0x2548, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_41	0x254c /* HDMI HDCP KSV FIFO 41 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_41	 0x254c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_41 */
	#define BLSB_HDMI_RX_HKFM_41_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_41_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_41 */
	#define BWID_HDMI_RX_HKFM_41_RSVD1	24
	#define BWID_HDMI_RX_HKFM_41_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_41 */
	#define BMSK_HDMI_RX_HKFM_41_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_41_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_41 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_41_RSVD1	 0x254c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_41_KSV_MSB	 0x254c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_42	0x2550 /* HDMI HDCP KSV FIFO 42 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_42	 0x2550, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_42	0x2554 /* HDMI HDCP KSV FIFO 42 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_42	 0x2554, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_42 */
	#define BLSB_HDMI_RX_HKFM_42_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_42_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_42 */
	#define BWID_HDMI_RX_HKFM_42_RSVD1	24
	#define BWID_HDMI_RX_HKFM_42_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_42 */
	#define BMSK_HDMI_RX_HKFM_42_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_42_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_42 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_42_RSVD1	 0x2554, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_42_KSV_MSB	 0x2554, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_43	0x2558 /* HDMI HDCP KSV FIFO 43 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_43	 0x2558, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_43	0x255c /* HDMI HDCP KSV FIFO 43 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_43	 0x255c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_43 */
	#define BLSB_HDMI_RX_HKFM_43_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_43_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_43 */
	#define BWID_HDMI_RX_HKFM_43_RSVD1	24
	#define BWID_HDMI_RX_HKFM_43_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_43 */
	#define BMSK_HDMI_RX_HKFM_43_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_43_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_43 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_43_RSVD1	 0x255c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_43_KSV_MSB	 0x255c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_44	0x2560 /* HDMI HDCP KSV FIFO 44 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_44	 0x2560, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_44	0x2564 /* HDMI HDCP KSV FIFO 44 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_44	 0x2564, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_44 */
	#define BLSB_HDMI_RX_HKFM_44_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_44_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_44 */
	#define BWID_HDMI_RX_HKFM_44_RSVD1	24
	#define BWID_HDMI_RX_HKFM_44_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_44 */
	#define BMSK_HDMI_RX_HKFM_44_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_44_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_44 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_44_RSVD1	 0x2564, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_44_KSV_MSB	 0x2564, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_45	0x2568 /* HDMI HDCP KSV FIFO 45 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_45	 0x2568, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_45	0x256c /* HDMI HDCP KSV FIFO 45 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_45	 0x256c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_45 */
	#define BLSB_HDMI_RX_HKFM_45_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_45_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_45 */
	#define BWID_HDMI_RX_HKFM_45_RSVD1	24
	#define BWID_HDMI_RX_HKFM_45_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_45 */
	#define BMSK_HDMI_RX_HKFM_45_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_45_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_45 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_45_RSVD1	 0x256c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_45_KSV_MSB	 0x256c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_46	0x2570 /* HDMI HDCP KSV FIFO 46 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_46	 0x2570, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_46	0x2574 /* HDMI HDCP KSV FIFO 46 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_46	 0x2574, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_46 */
	#define BLSB_HDMI_RX_HKFM_46_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_46_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_46 */
	#define BWID_HDMI_RX_HKFM_46_RSVD1	24
	#define BWID_HDMI_RX_HKFM_46_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_46 */
	#define BMSK_HDMI_RX_HKFM_46_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_46_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_46 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_46_RSVD1	 0x2574, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_46_KSV_MSB	 0x2574, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_47	0x2578 /* HDMI HDCP KSV FIFO 47 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_47	 0x2578, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_47	0x257c /* HDMI HDCP KSV FIFO 47 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_47	 0x257c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_47 */
	#define BLSB_HDMI_RX_HKFM_47_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_47_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_47 */
	#define BWID_HDMI_RX_HKFM_47_RSVD1	24
	#define BWID_HDMI_RX_HKFM_47_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_47 */
	#define BMSK_HDMI_RX_HKFM_47_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_47_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_47 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_47_RSVD1	 0x257c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_47_KSV_MSB	 0x257c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_48	0x2580 /* HDMI HDCP KSV FIFO 48 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_48	 0x2580, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_48	0x2584 /* HDMI HDCP KSV FIFO 48 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_48	 0x2584, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_48 */
	#define BLSB_HDMI_RX_HKFM_48_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_48_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_48 */
	#define BWID_HDMI_RX_HKFM_48_RSVD1	24
	#define BWID_HDMI_RX_HKFM_48_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_48 */
	#define BMSK_HDMI_RX_HKFM_48_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_48_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_48 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_48_RSVD1	 0x2584, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_48_KSV_MSB	 0x2584, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_49	0x2588 /* HDMI HDCP KSV FIFO 49 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_49	 0x2588, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_49	0x258c /* HDMI HDCP KSV FIFO 49 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_49	 0x258c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_49 */
	#define BLSB_HDMI_RX_HKFM_49_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_49_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_49 */
	#define BWID_HDMI_RX_HKFM_49_RSVD1	24
	#define BWID_HDMI_RX_HKFM_49_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_49 */
	#define BMSK_HDMI_RX_HKFM_49_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_49_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_49 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_49_RSVD1	 0x258c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_49_KSV_MSB	 0x258c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_50	0x2590 /* HDMI HDCP KSV FIFO 50 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_50	 0x2590, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_50	0x2594 /* HDMI HDCP KSV FIFO 50 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_50	 0x2594, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_50 */
	#define BLSB_HDMI_RX_HKFM_50_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_50_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_50 */
	#define BWID_HDMI_RX_HKFM_50_RSVD1	24
	#define BWID_HDMI_RX_HKFM_50_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_50 */
	#define BMSK_HDMI_RX_HKFM_50_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_50_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_50 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_50_RSVD1	 0x2594, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_50_KSV_MSB	 0x2594, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_51	0x2598 /* HDMI HDCP KSV FIFO 51 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_51	 0x2598, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_51	0x259c /* HDMI HDCP KSV FIFO 51 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_51	 0x259c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_51 */
	#define BLSB_HDMI_RX_HKFM_51_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_51_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_51 */
	#define BWID_HDMI_RX_HKFM_51_RSVD1	24
	#define BWID_HDMI_RX_HKFM_51_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_51 */
	#define BMSK_HDMI_RX_HKFM_51_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_51_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_51 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_51_RSVD1	 0x259c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_51_KSV_MSB	 0x259c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_52	0x25a0 /* HDMI HDCP KSV FIFO 52 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_52	 0x25a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_52	0x25a4 /* HDMI HDCP KSV FIFO 52 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_52	 0x25a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_52 */
	#define BLSB_HDMI_RX_HKFM_52_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_52_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_52 */
	#define BWID_HDMI_RX_HKFM_52_RSVD1	24
	#define BWID_HDMI_RX_HKFM_52_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_52 */
	#define BMSK_HDMI_RX_HKFM_52_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_52_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_52 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_52_RSVD1	 0x25a4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_52_KSV_MSB	 0x25a4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_53	0x25a8 /* HDMI HDCP KSV FIFO 53 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_53	 0x25a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_53	0x25ac /* HDMI HDCP KSV FIFO 53 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_53	 0x25ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_53 */
	#define BLSB_HDMI_RX_HKFM_53_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_53_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_53 */
	#define BWID_HDMI_RX_HKFM_53_RSVD1	24
	#define BWID_HDMI_RX_HKFM_53_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_53 */
	#define BMSK_HDMI_RX_HKFM_53_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_53_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_53 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_53_RSVD1	 0x25ac, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_53_KSV_MSB	 0x25ac, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_54	0x25b0 /* HDMI HDCP KSV FIFO 54 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_54	 0x25b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_54	0x25b4 /* HDMI HDCP KSV FIFO 54 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_54	 0x25b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_54 */
	#define BLSB_HDMI_RX_HKFM_54_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_54_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_54 */
	#define BWID_HDMI_RX_HKFM_54_RSVD1	24
	#define BWID_HDMI_RX_HKFM_54_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_54 */
	#define BMSK_HDMI_RX_HKFM_54_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_54_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_54 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_54_RSVD1	 0x25b4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_54_KSV_MSB	 0x25b4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_55	0x25b8 /* HDMI HDCP KSV FIFO 55 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_55	 0x25b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_55	0x25bc /* HDMI HDCP KSV FIFO 55 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_55	 0x25bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_55 */
	#define BLSB_HDMI_RX_HKFM_55_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_55_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_55 */
	#define BWID_HDMI_RX_HKFM_55_RSVD1	24
	#define BWID_HDMI_RX_HKFM_55_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_55 */
	#define BMSK_HDMI_RX_HKFM_55_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_55_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_55 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_55_RSVD1	 0x25bc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_55_KSV_MSB	 0x25bc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_56	0x25c0 /* HDMI HDCP KSV FIFO 56 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_56	 0x25c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_56	0x25c4 /* HDMI HDCP KSV FIFO 56 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_56	 0x25c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_56 */
	#define BLSB_HDMI_RX_HKFM_56_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_56_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_56 */
	#define BWID_HDMI_RX_HKFM_56_RSVD1	24
	#define BWID_HDMI_RX_HKFM_56_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_56 */
	#define BMSK_HDMI_RX_HKFM_56_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_56_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_56 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_56_RSVD1	 0x25c4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_56_KSV_MSB	 0x25c4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_57	0x25c8 /* HDMI HDCP KSV FIFO 57 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_57	 0x25c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_57	0x25cc /* HDMI HDCP KSV FIFO 57 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_57	 0x25cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_57 */
	#define BLSB_HDMI_RX_HKFM_57_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_57_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_57 */
	#define BWID_HDMI_RX_HKFM_57_RSVD1	24
	#define BWID_HDMI_RX_HKFM_57_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_57 */
	#define BMSK_HDMI_RX_HKFM_57_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_57_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_57 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_57_RSVD1	 0x25cc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_57_KSV_MSB	 0x25cc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_58	0x25d0 /* HDMI HDCP KSV FIFO 58 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_58	 0x25d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_58	0x25d4 /* HDMI HDCP KSV FIFO 58 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_58	 0x25d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_58 */
	#define BLSB_HDMI_RX_HKFM_58_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_58_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_58 */
	#define BWID_HDMI_RX_HKFM_58_RSVD1	24
	#define BWID_HDMI_RX_HKFM_58_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_58 */
	#define BMSK_HDMI_RX_HKFM_58_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_58_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_58 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_58_RSVD1	 0x25d4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_58_KSV_MSB	 0x25d4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_59	0x25d8 /* HDMI HDCP KSV FIFO 59 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_59	 0x25d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_59	0x25dc /* HDMI HDCP KSV FIFO 59 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_59	 0x25dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_59 */
	#define BLSB_HDMI_RX_HKFM_59_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_59_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_59 */
	#define BWID_HDMI_RX_HKFM_59_RSVD1	24
	#define BWID_HDMI_RX_HKFM_59_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_59 */
	#define BMSK_HDMI_RX_HKFM_59_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_59_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_59 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_59_RSVD1	 0x25dc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_59_KSV_MSB	 0x25dc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_60	0x25e0 /* HDMI HDCP KSV FIFO 60 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_60	 0x25e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_60	0x25e4 /* HDMI HDCP KSV FIFO 60 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_60	 0x25e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_60 */
	#define BLSB_HDMI_RX_HKFM_60_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_60_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_60 */
	#define BWID_HDMI_RX_HKFM_60_RSVD1	24
	#define BWID_HDMI_RX_HKFM_60_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_60 */
	#define BMSK_HDMI_RX_HKFM_60_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_60_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_60 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_60_RSVD1	 0x25e4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_60_KSV_MSB	 0x25e4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_61	0x25e8 /* HDMI HDCP KSV FIFO 61 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_61	 0x25e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_61	0x25ec /* HDMI HDCP KSV FIFO 61 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_61	 0x25ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_61 */
	#define BLSB_HDMI_RX_HKFM_61_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_61_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_61 */
	#define BWID_HDMI_RX_HKFM_61_RSVD1	24
	#define BWID_HDMI_RX_HKFM_61_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_61 */
	#define BMSK_HDMI_RX_HKFM_61_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_61_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_61 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_61_RSVD1	 0x25ec, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_61_KSV_MSB	 0x25ec, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_62	0x25f0 /* HDMI HDCP KSV FIFO 62 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_62	 0x25f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_62	0x25f4 /* HDMI HDCP KSV FIFO 62 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_62	 0x25f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_62 */
	#define BLSB_HDMI_RX_HKFM_62_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_62_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_62 */
	#define BWID_HDMI_RX_HKFM_62_RSVD1	24
	#define BWID_HDMI_RX_HKFM_62_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_62 */
	#define BMSK_HDMI_RX_HKFM_62_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_62_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_62 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_62_RSVD1	 0x25f4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_62_KSV_MSB	 0x25f4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_63	0x25f8 /* HDMI HDCP KSV FIFO 63 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_63	 0x25f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_63	0x25fc /* HDMI HDCP KSV FIFO 63 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_63	 0x25fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_63 */
	#define BLSB_HDMI_RX_HKFM_63_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_63_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_63 */
	#define BWID_HDMI_RX_HKFM_63_RSVD1	24
	#define BWID_HDMI_RX_HKFM_63_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_63 */
	#define BMSK_HDMI_RX_HKFM_63_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_63_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_63 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_63_RSVD1	 0x25fc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_63_KSV_MSB	 0x25fc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_64	0x2600 /* HDMI HDCP KSV FIFO 64 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_64	 0x2600, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_64	0x2604 /* HDMI HDCP KSV FIFO 64 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_64	 0x2604, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_64 */
	#define BLSB_HDMI_RX_HKFM_64_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_64_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_64 */
	#define BWID_HDMI_RX_HKFM_64_RSVD1	24
	#define BWID_HDMI_RX_HKFM_64_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_64 */
	#define BMSK_HDMI_RX_HKFM_64_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_64_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_64 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_64_RSVD1	 0x2604, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_64_KSV_MSB	 0x2604, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_65	0x2608 /* HDMI HDCP KSV FIFO 65 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_65	 0x2608, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_65	0x260c /* HDMI HDCP KSV FIFO 65 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_65	 0x260c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_65 */
	#define BLSB_HDMI_RX_HKFM_65_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_65_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_65 */
	#define BWID_HDMI_RX_HKFM_65_RSVD1	24
	#define BWID_HDMI_RX_HKFM_65_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_65 */
	#define BMSK_HDMI_RX_HKFM_65_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_65_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_65 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_65_RSVD1	 0x260c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_65_KSV_MSB	 0x260c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_66	0x2610 /* HDMI HDCP KSV FIFO 66 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_66	 0x2610, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_66	0x2614 /* HDMI HDCP KSV FIFO 66 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_66	 0x2614, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_66 */
	#define BLSB_HDMI_RX_HKFM_66_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_66_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_66 */
	#define BWID_HDMI_RX_HKFM_66_RSVD1	24
	#define BWID_HDMI_RX_HKFM_66_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_66 */
	#define BMSK_HDMI_RX_HKFM_66_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_66_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_66 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_66_RSVD1	 0x2614, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_66_KSV_MSB	 0x2614, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_67	0x2618 /* HDMI HDCP KSV FIFO 67 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_67	 0x2618, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_67	0x261c /* HDMI HDCP KSV FIFO 67 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_67	 0x261c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_67 */
	#define BLSB_HDMI_RX_HKFM_67_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_67_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_67 */
	#define BWID_HDMI_RX_HKFM_67_RSVD1	24
	#define BWID_HDMI_RX_HKFM_67_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_67 */
	#define BMSK_HDMI_RX_HKFM_67_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_67_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_67 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_67_RSVD1	 0x261c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_67_KSV_MSB	 0x261c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_68	0x2620 /* HDMI HDCP KSV FIFO 68 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_68	 0x2620, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_68	0x2624 /* HDMI HDCP KSV FIFO 68 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_68	 0x2624, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_68 */
	#define BLSB_HDMI_RX_HKFM_68_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_68_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_68 */
	#define BWID_HDMI_RX_HKFM_68_RSVD1	24
	#define BWID_HDMI_RX_HKFM_68_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_68 */
	#define BMSK_HDMI_RX_HKFM_68_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_68_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_68 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_68_RSVD1	 0x2624, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_68_KSV_MSB	 0x2624, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_69	0x2628 /* HDMI HDCP KSV FIFO 69 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_69	 0x2628, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_69	0x262c /* HDMI HDCP KSV FIFO 69 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_69	 0x262c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_69 */
	#define BLSB_HDMI_RX_HKFM_69_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_69_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_69 */
	#define BWID_HDMI_RX_HKFM_69_RSVD1	24
	#define BWID_HDMI_RX_HKFM_69_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_69 */
	#define BMSK_HDMI_RX_HKFM_69_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_69_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_69 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_69_RSVD1	 0x262c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_69_KSV_MSB	 0x262c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_70	0x2630 /* HDMI HDCP KSV FIFO 70 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_70	 0x2630, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_70	0x2634 /* HDMI HDCP KSV FIFO 70 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_70	 0x2634, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_70 */
	#define BLSB_HDMI_RX_HKFM_70_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_70_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_70 */
	#define BWID_HDMI_RX_HKFM_70_RSVD1	24
	#define BWID_HDMI_RX_HKFM_70_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_70 */
	#define BMSK_HDMI_RX_HKFM_70_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_70_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_70 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_70_RSVD1	 0x2634, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_70_KSV_MSB	 0x2634, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_71	0x2638 /* HDMI HDCP KSV FIFO 71 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_71	 0x2638, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_71	0x263c /* HDMI HDCP KSV FIFO 71 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_71	 0x263c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_71 */
	#define BLSB_HDMI_RX_HKFM_71_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_71_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_71 */
	#define BWID_HDMI_RX_HKFM_71_RSVD1	24
	#define BWID_HDMI_RX_HKFM_71_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_71 */
	#define BMSK_HDMI_RX_HKFM_71_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_71_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_71 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_71_RSVD1	 0x263c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_71_KSV_MSB	 0x263c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_72	0x2640 /* HDMI HDCP KSV FIFO 72 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_72	 0x2640, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_72	0x2644 /* HDMI HDCP KSV FIFO 72 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_72	 0x2644, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_72 */
	#define BLSB_HDMI_RX_HKFM_72_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_72_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_72 */
	#define BWID_HDMI_RX_HKFM_72_RSVD1	24
	#define BWID_HDMI_RX_HKFM_72_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_72 */
	#define BMSK_HDMI_RX_HKFM_72_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_72_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_72 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_72_RSVD1	 0x2644, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_72_KSV_MSB	 0x2644, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_73	0x2648 /* HDMI HDCP KSV FIFO 73 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_73	 0x2648, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_73	0x264c /* HDMI HDCP KSV FIFO 73 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_73	 0x264c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_73 */
	#define BLSB_HDMI_RX_HKFM_73_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_73_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_73 */
	#define BWID_HDMI_RX_HKFM_73_RSVD1	24
	#define BWID_HDMI_RX_HKFM_73_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_73 */
	#define BMSK_HDMI_RX_HKFM_73_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_73_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_73 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_73_RSVD1	 0x264c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_73_KSV_MSB	 0x264c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_74	0x2650 /* HDMI HDCP KSV FIFO 74 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_74	 0x2650, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_74	0x2654 /* HDMI HDCP KSV FIFO 74 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_74	 0x2654, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_74 */
	#define BLSB_HDMI_RX_HKFM_74_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_74_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_74 */
	#define BWID_HDMI_RX_HKFM_74_RSVD1	24
	#define BWID_HDMI_RX_HKFM_74_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_74 */
	#define BMSK_HDMI_RX_HKFM_74_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_74_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_74 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_74_RSVD1	 0x2654, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_74_KSV_MSB	 0x2654, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_75	0x2658 /* HDMI HDCP KSV FIFO 75 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_75	 0x2658, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_75	0x265c /* HDMI HDCP KSV FIFO 75 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_75	 0x265c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_75 */
	#define BLSB_HDMI_RX_HKFM_75_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_75_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_75 */
	#define BWID_HDMI_RX_HKFM_75_RSVD1	24
	#define BWID_HDMI_RX_HKFM_75_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_75 */
	#define BMSK_HDMI_RX_HKFM_75_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_75_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_75 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_75_RSVD1	 0x265c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_75_KSV_MSB	 0x265c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_76	0x2660 /* HDMI HDCP KSV FIFO 76 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_76	 0x2660, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_76	0x2664 /* HDMI HDCP KSV FIFO 76 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_76	 0x2664, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_76 */
	#define BLSB_HDMI_RX_HKFM_76_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_76_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_76 */
	#define BWID_HDMI_RX_HKFM_76_RSVD1	24
	#define BWID_HDMI_RX_HKFM_76_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_76 */
	#define BMSK_HDMI_RX_HKFM_76_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_76_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_76 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_76_RSVD1	 0x2664, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_76_KSV_MSB	 0x2664, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_77	0x2668 /* HDMI HDCP KSV FIFO 77 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_77	 0x2668, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_77	0x266c /* HDMI HDCP KSV FIFO 77 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_77	 0x266c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_77 */
	#define BLSB_HDMI_RX_HKFM_77_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_77_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_77 */
	#define BWID_HDMI_RX_HKFM_77_RSVD1	24
	#define BWID_HDMI_RX_HKFM_77_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_77 */
	#define BMSK_HDMI_RX_HKFM_77_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_77_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_77 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_77_RSVD1	 0x266c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_77_KSV_MSB	 0x266c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_78	0x2670 /* HDMI HDCP KSV FIFO 78 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_78	 0x2670, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_78	0x2674 /* HDMI HDCP KSV FIFO 78 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_78	 0x2674, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_78 */
	#define BLSB_HDMI_RX_HKFM_78_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_78_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_78 */
	#define BWID_HDMI_RX_HKFM_78_RSVD1	24
	#define BWID_HDMI_RX_HKFM_78_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_78 */
	#define BMSK_HDMI_RX_HKFM_78_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_78_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_78 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_78_RSVD1	 0x2674, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_78_KSV_MSB	 0x2674, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_79	0x2678 /* HDMI HDCP KSV FIFO 79 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_79	 0x2678, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_79	0x267c /* HDMI HDCP KSV FIFO 79 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_79	 0x267c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_79 */
	#define BLSB_HDMI_RX_HKFM_79_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_79_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_79 */
	#define BWID_HDMI_RX_HKFM_79_RSVD1	24
	#define BWID_HDMI_RX_HKFM_79_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_79 */
	#define BMSK_HDMI_RX_HKFM_79_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_79_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_79 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_79_RSVD1	 0x267c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_79_KSV_MSB	 0x267c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_80	0x2680 /* HDMI HDCP KSV FIFO 80 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_80	 0x2680, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_80	0x2684 /* HDMI HDCP KSV FIFO 80 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_80	 0x2684, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_80 */
	#define BLSB_HDMI_RX_HKFM_80_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_80_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_80 */
	#define BWID_HDMI_RX_HKFM_80_RSVD1	24
	#define BWID_HDMI_RX_HKFM_80_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_80 */
	#define BMSK_HDMI_RX_HKFM_80_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_80_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_80 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_80_RSVD1	 0x2684, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_80_KSV_MSB	 0x2684, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_81	0x2688 /* HDMI HDCP KSV FIFO 81 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_81	 0x2688, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_81	0x268c /* HDMI HDCP KSV FIFO 81 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_81	 0x268c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_81 */
	#define BLSB_HDMI_RX_HKFM_81_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_81_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_81 */
	#define BWID_HDMI_RX_HKFM_81_RSVD1	24
	#define BWID_HDMI_RX_HKFM_81_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_81 */
	#define BMSK_HDMI_RX_HKFM_81_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_81_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_81 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_81_RSVD1	 0x268c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_81_KSV_MSB	 0x268c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_82	0x2690 /* HDMI HDCP KSV FIFO 82 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_82	 0x2690, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_82	0x2694 /* HDMI HDCP KSV FIFO 82 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_82	 0x2694, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_82 */
	#define BLSB_HDMI_RX_HKFM_82_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_82_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_82 */
	#define BWID_HDMI_RX_HKFM_82_RSVD1	24
	#define BWID_HDMI_RX_HKFM_82_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_82 */
	#define BMSK_HDMI_RX_HKFM_82_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_82_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_82 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_82_RSVD1	 0x2694, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_82_KSV_MSB	 0x2694, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_83	0x2698 /* HDMI HDCP KSV FIFO 83 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_83	 0x2698, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_83	0x269c /* HDMI HDCP KSV FIFO 83 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_83	 0x269c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_83 */
	#define BLSB_HDMI_RX_HKFM_83_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_83_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_83 */
	#define BWID_HDMI_RX_HKFM_83_RSVD1	24
	#define BWID_HDMI_RX_HKFM_83_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_83 */
	#define BMSK_HDMI_RX_HKFM_83_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_83_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_83 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_83_RSVD1	 0x269c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_83_KSV_MSB	 0x269c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_84	0x26a0 /* HDMI HDCP KSV FIFO 84 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_84	 0x26a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_84	0x26a4 /* HDMI HDCP KSV FIFO 84 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_84	 0x26a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_84 */
	#define BLSB_HDMI_RX_HKFM_84_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_84_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_84 */
	#define BWID_HDMI_RX_HKFM_84_RSVD1	24
	#define BWID_HDMI_RX_HKFM_84_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_84 */
	#define BMSK_HDMI_RX_HKFM_84_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_84_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_84 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_84_RSVD1	 0x26a4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_84_KSV_MSB	 0x26a4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_85	0x26a8 /* HDMI HDCP KSV FIFO 85 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_85	 0x26a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_85	0x26ac /* HDMI HDCP KSV FIFO 85 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_85	 0x26ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_85 */
	#define BLSB_HDMI_RX_HKFM_85_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_85_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_85 */
	#define BWID_HDMI_RX_HKFM_85_RSVD1	24
	#define BWID_HDMI_RX_HKFM_85_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_85 */
	#define BMSK_HDMI_RX_HKFM_85_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_85_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_85 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_85_RSVD1	 0x26ac, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_85_KSV_MSB	 0x26ac, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_86	0x26b0 /* HDMI HDCP KSV FIFO 86 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_86	 0x26b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_86	0x26b4 /* HDMI HDCP KSV FIFO 86 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_86	 0x26b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_86 */
	#define BLSB_HDMI_RX_HKFM_86_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_86_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_86 */
	#define BWID_HDMI_RX_HKFM_86_RSVD1	24
	#define BWID_HDMI_RX_HKFM_86_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_86 */
	#define BMSK_HDMI_RX_HKFM_86_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_86_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_86 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_86_RSVD1	 0x26b4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_86_KSV_MSB	 0x26b4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_87	0x26b8 /* HDMI HDCP KSV FIFO 87 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_87	 0x26b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_87	0x26bc /* HDMI HDCP KSV FIFO 87 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_87	 0x26bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_87 */
	#define BLSB_HDMI_RX_HKFM_87_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_87_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_87 */
	#define BWID_HDMI_RX_HKFM_87_RSVD1	24
	#define BWID_HDMI_RX_HKFM_87_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_87 */
	#define BMSK_HDMI_RX_HKFM_87_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_87_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_87 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_87_RSVD1	 0x26bc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_87_KSV_MSB	 0x26bc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_88	0x26c0 /* HDMI HDCP KSV FIFO 88 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_88	 0x26c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_88	0x26c4 /* HDMI HDCP KSV FIFO 88 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_88	 0x26c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_88 */
	#define BLSB_HDMI_RX_HKFM_88_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_88_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_88 */
	#define BWID_HDMI_RX_HKFM_88_RSVD1	24
	#define BWID_HDMI_RX_HKFM_88_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_88 */
	#define BMSK_HDMI_RX_HKFM_88_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_88_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_88 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_88_RSVD1	 0x26c4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_88_KSV_MSB	 0x26c4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_89	0x26c8 /* HDMI HDCP KSV FIFO 89 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_89	 0x26c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_89	0x26cc /* HDMI HDCP KSV FIFO 89 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_89	 0x26cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_89 */
	#define BLSB_HDMI_RX_HKFM_89_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_89_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_89 */
	#define BWID_HDMI_RX_HKFM_89_RSVD1	24
	#define BWID_HDMI_RX_HKFM_89_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_89 */
	#define BMSK_HDMI_RX_HKFM_89_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_89_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_89 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_89_RSVD1	 0x26cc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_89_KSV_MSB	 0x26cc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_90	0x26d0 /* HDMI HDCP KSV FIFO 90 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_90	 0x26d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_90	0x26d4 /* HDMI HDCP KSV FIFO 90 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_90	 0x26d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_90 */
	#define BLSB_HDMI_RX_HKFM_90_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_90_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_90 */
	#define BWID_HDMI_RX_HKFM_90_RSVD1	24
	#define BWID_HDMI_RX_HKFM_90_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_90 */
	#define BMSK_HDMI_RX_HKFM_90_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_90_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_90 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_90_RSVD1	 0x26d4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_90_KSV_MSB	 0x26d4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_91	0x26d8 /* HDMI HDCP KSV FIFO 91 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_91	 0x26d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_91	0x26dc /* HDMI HDCP KSV FIFO 91 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_91	 0x26dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_91 */
	#define BLSB_HDMI_RX_HKFM_91_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_91_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_91 */
	#define BWID_HDMI_RX_HKFM_91_RSVD1	24
	#define BWID_HDMI_RX_HKFM_91_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_91 */
	#define BMSK_HDMI_RX_HKFM_91_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_91_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_91 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_91_RSVD1	 0x26dc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_91_KSV_MSB	 0x26dc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_92	0x26e0 /* HDMI HDCP KSV FIFO 92 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_92	 0x26e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_92	0x26e4 /* HDMI HDCP KSV FIFO 92 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_92	 0x26e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_92 */
	#define BLSB_HDMI_RX_HKFM_92_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_92_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_92 */
	#define BWID_HDMI_RX_HKFM_92_RSVD1	24
	#define BWID_HDMI_RX_HKFM_92_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_92 */
	#define BMSK_HDMI_RX_HKFM_92_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_92_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_92 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_92_RSVD1	 0x26e4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_92_KSV_MSB	 0x26e4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_93	0x26e8 /* HDMI HDCP KSV FIFO 93 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_93	 0x26e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_93	0x26ec /* HDMI HDCP KSV FIFO 93 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_93	 0x26ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_93 */
	#define BLSB_HDMI_RX_HKFM_93_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_93_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_93 */
	#define BWID_HDMI_RX_HKFM_93_RSVD1	24
	#define BWID_HDMI_RX_HKFM_93_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_93 */
	#define BMSK_HDMI_RX_HKFM_93_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_93_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_93 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_93_RSVD1	 0x26ec, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_93_KSV_MSB	 0x26ec, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_94	0x26f0 /* HDMI HDCP KSV FIFO 94 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_94	 0x26f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_94	0x26f4 /* HDMI HDCP KSV FIFO 94 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_94	 0x26f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_94 */
	#define BLSB_HDMI_RX_HKFM_94_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_94_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_94 */
	#define BWID_HDMI_RX_HKFM_94_RSVD1	24
	#define BWID_HDMI_RX_HKFM_94_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_94 */
	#define BMSK_HDMI_RX_HKFM_94_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_94_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_94 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_94_RSVD1	 0x26f4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_94_KSV_MSB	 0x26f4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_95	0x26f8 /* HDMI HDCP KSV FIFO 95 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_95	 0x26f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_95	0x26fc /* HDMI HDCP KSV FIFO 95 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_95	 0x26fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_95 */
	#define BLSB_HDMI_RX_HKFM_95_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_95_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_95 */
	#define BWID_HDMI_RX_HKFM_95_RSVD1	24
	#define BWID_HDMI_RX_HKFM_95_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_95 */
	#define BMSK_HDMI_RX_HKFM_95_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_95_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_95 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_95_RSVD1	 0x26fc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_95_KSV_MSB	 0x26fc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_96	0x2700 /* HDMI HDCP KSV FIFO 96 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_96	 0x2700, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_96	0x2704 /* HDMI HDCP KSV FIFO 96 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_96	 0x2704, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_96 */
	#define BLSB_HDMI_RX_HKFM_96_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_96_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_96 */
	#define BWID_HDMI_RX_HKFM_96_RSVD1	24
	#define BWID_HDMI_RX_HKFM_96_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_96 */
	#define BMSK_HDMI_RX_HKFM_96_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_96_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_96 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_96_RSVD1	 0x2704, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_96_KSV_MSB	 0x2704, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_97	0x2708 /* HDMI HDCP KSV FIFO 97 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_97	 0x2708, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_97	0x270c /* HDMI HDCP KSV FIFO 97 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_97	 0x270c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_97 */
	#define BLSB_HDMI_RX_HKFM_97_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_97_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_97 */
	#define BWID_HDMI_RX_HKFM_97_RSVD1	24
	#define BWID_HDMI_RX_HKFM_97_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_97 */
	#define BMSK_HDMI_RX_HKFM_97_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_97_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_97 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_97_RSVD1	 0x270c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_97_KSV_MSB	 0x270c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_98	0x2710 /* HDMI HDCP KSV FIFO 98 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_98	 0x2710, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_98	0x2714 /* HDMI HDCP KSV FIFO 98 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_98	 0x2714, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_98 */
	#define BLSB_HDMI_RX_HKFM_98_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_98_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_98 */
	#define BWID_HDMI_RX_HKFM_98_RSVD1	24
	#define BWID_HDMI_RX_HKFM_98_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_98 */
	#define BMSK_HDMI_RX_HKFM_98_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_98_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_98 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_98_RSVD1	 0x2714, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_98_KSV_MSB	 0x2714, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_99	0x2718 /* HDMI HDCP KSV FIFO 99 LSB                         */ 
	#define BITFIELD_HDMI_RX_HKFL_99	 0x2718, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_99	0x271c /* HDMI HDCP KSV FIFO 99 MSB                         */ 
	#define BITFIELD_HDMI_RX_HKFM_99	 0x271c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_99 */
	#define BLSB_HDMI_RX_HKFM_99_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_99_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_99 */
	#define BWID_HDMI_RX_HKFM_99_RSVD1	24
	#define BWID_HDMI_RX_HKFM_99_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_99 */
	#define BMSK_HDMI_RX_HKFM_99_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_99_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_99 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_99_RSVD1	 0x271c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_99_KSV_MSB	 0x271c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_100	0x2720 /* HDMI HDCP KSV FIFO 100 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_100	 0x2720, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_100	0x2724 /* HDMI HDCP KSV FIFO 100 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_100	 0x2724, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_100 */
	#define BLSB_HDMI_RX_HKFM_100_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_100_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_100 */
	#define BWID_HDMI_RX_HKFM_100_RSVD1	24
	#define BWID_HDMI_RX_HKFM_100_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_100 */
	#define BMSK_HDMI_RX_HKFM_100_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_100_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_100 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_100_RSVD1	 0x2724, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_100_KSV_MSB	 0x2724, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_101	0x2728 /* HDMI HDCP KSV FIFO 101 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_101	 0x2728, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_101	0x272c /* HDMI HDCP KSV FIFO 101 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_101	 0x272c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_101 */
	#define BLSB_HDMI_RX_HKFM_101_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_101_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_101 */
	#define BWID_HDMI_RX_HKFM_101_RSVD1	24
	#define BWID_HDMI_RX_HKFM_101_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_101 */
	#define BMSK_HDMI_RX_HKFM_101_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_101_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_101 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_101_RSVD1	 0x272c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_101_KSV_MSB	 0x272c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_102	0x2730 /* HDMI HDCP KSV FIFO 102 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_102	 0x2730, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_102	0x2734 /* HDMI HDCP KSV FIFO 102 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_102	 0x2734, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_102 */
	#define BLSB_HDMI_RX_HKFM_102_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_102_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_102 */
	#define BWID_HDMI_RX_HKFM_102_RSVD1	24
	#define BWID_HDMI_RX_HKFM_102_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_102 */
	#define BMSK_HDMI_RX_HKFM_102_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_102_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_102 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_102_RSVD1	 0x2734, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_102_KSV_MSB	 0x2734, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_103	0x2738 /* HDMI HDCP KSV FIFO 103 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_103	 0x2738, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_103	0x273c /* HDMI HDCP KSV FIFO 103 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_103	 0x273c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_103 */
	#define BLSB_HDMI_RX_HKFM_103_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_103_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_103 */
	#define BWID_HDMI_RX_HKFM_103_RSVD1	24
	#define BWID_HDMI_RX_HKFM_103_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_103 */
	#define BMSK_HDMI_RX_HKFM_103_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_103_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_103 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_103_RSVD1	 0x273c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_103_KSV_MSB	 0x273c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_104	0x2740 /* HDMI HDCP KSV FIFO 104 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_104	 0x2740, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_104	0x2744 /* HDMI HDCP KSV FIFO 104 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_104	 0x2744, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_104 */
	#define BLSB_HDMI_RX_HKFM_104_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_104_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_104 */
	#define BWID_HDMI_RX_HKFM_104_RSVD1	24
	#define BWID_HDMI_RX_HKFM_104_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_104 */
	#define BMSK_HDMI_RX_HKFM_104_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_104_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_104 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_104_RSVD1	 0x2744, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_104_KSV_MSB	 0x2744, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_105	0x2748 /* HDMI HDCP KSV FIFO 105 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_105	 0x2748, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_105	0x274c /* HDMI HDCP KSV FIFO 105 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_105	 0x274c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_105 */
	#define BLSB_HDMI_RX_HKFM_105_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_105_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_105 */
	#define BWID_HDMI_RX_HKFM_105_RSVD1	24
	#define BWID_HDMI_RX_HKFM_105_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_105 */
	#define BMSK_HDMI_RX_HKFM_105_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_105_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_105 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_105_RSVD1	 0x274c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_105_KSV_MSB	 0x274c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_106	0x2750 /* HDMI HDCP KSV FIFO 106 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_106	 0x2750, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_106	0x2754 /* HDMI HDCP KSV FIFO 106 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_106	 0x2754, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_106 */
	#define BLSB_HDMI_RX_HKFM_106_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_106_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_106 */
	#define BWID_HDMI_RX_HKFM_106_RSVD1	24
	#define BWID_HDMI_RX_HKFM_106_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_106 */
	#define BMSK_HDMI_RX_HKFM_106_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_106_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_106 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_106_RSVD1	 0x2754, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_106_KSV_MSB	 0x2754, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_107	0x2758 /* HDMI HDCP KSV FIFO 107 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_107	 0x2758, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_107	0x275c /* HDMI HDCP KSV FIFO 107 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_107	 0x275c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_107 */
	#define BLSB_HDMI_RX_HKFM_107_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_107_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_107 */
	#define BWID_HDMI_RX_HKFM_107_RSVD1	24
	#define BWID_HDMI_RX_HKFM_107_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_107 */
	#define BMSK_HDMI_RX_HKFM_107_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_107_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_107 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_107_RSVD1	 0x275c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_107_KSV_MSB	 0x275c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_108	0x2760 /* HDMI HDCP KSV FIFO 108 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_108	 0x2760, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_108	0x2764 /* HDMI HDCP KSV FIFO 108 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_108	 0x2764, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_108 */
	#define BLSB_HDMI_RX_HKFM_108_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_108_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_108 */
	#define BWID_HDMI_RX_HKFM_108_RSVD1	24
	#define BWID_HDMI_RX_HKFM_108_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_108 */
	#define BMSK_HDMI_RX_HKFM_108_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_108_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_108 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_108_RSVD1	 0x2764, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_108_KSV_MSB	 0x2764, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_109	0x2768 /* HDMI HDCP KSV FIFO 109 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_109	 0x2768, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_109	0x276c /* HDMI HDCP KSV FIFO 109 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_109	 0x276c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_109 */
	#define BLSB_HDMI_RX_HKFM_109_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_109_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_109 */
	#define BWID_HDMI_RX_HKFM_109_RSVD1	24
	#define BWID_HDMI_RX_HKFM_109_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_109 */
	#define BMSK_HDMI_RX_HKFM_109_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_109_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_109 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_109_RSVD1	 0x276c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_109_KSV_MSB	 0x276c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_110	0x2770 /* HDMI HDCP KSV FIFO 110 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_110	 0x2770, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_110	0x2774 /* HDMI HDCP KSV FIFO 110 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_110	 0x2774, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_110 */
	#define BLSB_HDMI_RX_HKFM_110_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_110_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_110 */
	#define BWID_HDMI_RX_HKFM_110_RSVD1	24
	#define BWID_HDMI_RX_HKFM_110_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_110 */
	#define BMSK_HDMI_RX_HKFM_110_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_110_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_110 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_110_RSVD1	 0x2774, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_110_KSV_MSB	 0x2774, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_111	0x2778 /* HDMI HDCP KSV FIFO 111 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_111	 0x2778, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_111	0x277c /* HDMI HDCP KSV FIFO 111 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_111	 0x277c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_111 */
	#define BLSB_HDMI_RX_HKFM_111_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_111_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_111 */
	#define BWID_HDMI_RX_HKFM_111_RSVD1	24
	#define BWID_HDMI_RX_HKFM_111_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_111 */
	#define BMSK_HDMI_RX_HKFM_111_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_111_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_111 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_111_RSVD1	 0x277c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_111_KSV_MSB	 0x277c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_112	0x2780 /* HDMI HDCP KSV FIFO 112 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_112	 0x2780, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_112	0x2784 /* HDMI HDCP KSV FIFO 112 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_112	 0x2784, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_112 */
	#define BLSB_HDMI_RX_HKFM_112_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_112_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_112 */
	#define BWID_HDMI_RX_HKFM_112_RSVD1	24
	#define BWID_HDMI_RX_HKFM_112_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_112 */
	#define BMSK_HDMI_RX_HKFM_112_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_112_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_112 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_112_RSVD1	 0x2784, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_112_KSV_MSB	 0x2784, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_113	0x2788 /* HDMI HDCP KSV FIFO 113 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_113	 0x2788, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_113	0x278c /* HDMI HDCP KSV FIFO 113 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_113	 0x278c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_113 */
	#define BLSB_HDMI_RX_HKFM_113_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_113_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_113 */
	#define BWID_HDMI_RX_HKFM_113_RSVD1	24
	#define BWID_HDMI_RX_HKFM_113_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_113 */
	#define BMSK_HDMI_RX_HKFM_113_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_113_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_113 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_113_RSVD1	 0x278c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_113_KSV_MSB	 0x278c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_114	0x2790 /* HDMI HDCP KSV FIFO 114 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_114	 0x2790, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_114	0x2794 /* HDMI HDCP KSV FIFO 114 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_114	 0x2794, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_114 */
	#define BLSB_HDMI_RX_HKFM_114_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_114_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_114 */
	#define BWID_HDMI_RX_HKFM_114_RSVD1	24
	#define BWID_HDMI_RX_HKFM_114_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_114 */
	#define BMSK_HDMI_RX_HKFM_114_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_114_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_114 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_114_RSVD1	 0x2794, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_114_KSV_MSB	 0x2794, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_115	0x2798 /* HDMI HDCP KSV FIFO 115 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_115	 0x2798, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_115	0x279c /* HDMI HDCP KSV FIFO 115 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_115	 0x279c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_115 */
	#define BLSB_HDMI_RX_HKFM_115_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_115_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_115 */
	#define BWID_HDMI_RX_HKFM_115_RSVD1	24
	#define BWID_HDMI_RX_HKFM_115_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_115 */
	#define BMSK_HDMI_RX_HKFM_115_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_115_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_115 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_115_RSVD1	 0x279c, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_115_KSV_MSB	 0x279c, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_116	0x27a0 /* HDMI HDCP KSV FIFO 116 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_116	 0x27a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_116	0x27a4 /* HDMI HDCP KSV FIFO 116 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_116	 0x27a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_116 */
	#define BLSB_HDMI_RX_HKFM_116_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_116_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_116 */
	#define BWID_HDMI_RX_HKFM_116_RSVD1	24
	#define BWID_HDMI_RX_HKFM_116_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_116 */
	#define BMSK_HDMI_RX_HKFM_116_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_116_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_116 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_116_RSVD1	 0x27a4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_116_KSV_MSB	 0x27a4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_117	0x27a8 /* HDMI HDCP KSV FIFO 117 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_117	 0x27a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_117	0x27ac /* HDMI HDCP KSV FIFO 117 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_117	 0x27ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_117 */
	#define BLSB_HDMI_RX_HKFM_117_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_117_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_117 */
	#define BWID_HDMI_RX_HKFM_117_RSVD1	24
	#define BWID_HDMI_RX_HKFM_117_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_117 */
	#define BMSK_HDMI_RX_HKFM_117_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_117_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_117 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_117_RSVD1	 0x27ac, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_117_KSV_MSB	 0x27ac, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_118	0x27b0 /* HDMI HDCP KSV FIFO 118 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_118	 0x27b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_118	0x27b4 /* HDMI HDCP KSV FIFO 118 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_118	 0x27b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_118 */
	#define BLSB_HDMI_RX_HKFM_118_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_118_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_118 */
	#define BWID_HDMI_RX_HKFM_118_RSVD1	24
	#define BWID_HDMI_RX_HKFM_118_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_118 */
	#define BMSK_HDMI_RX_HKFM_118_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_118_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_118 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_118_RSVD1	 0x27b4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_118_KSV_MSB	 0x27b4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_119	0x27b8 /* HDMI HDCP KSV FIFO 119 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_119	 0x27b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_119	0x27bc /* HDMI HDCP KSV FIFO 119 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_119	 0x27bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_119 */
	#define BLSB_HDMI_RX_HKFM_119_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_119_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_119 */
	#define BWID_HDMI_RX_HKFM_119_RSVD1	24
	#define BWID_HDMI_RX_HKFM_119_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_119 */
	#define BMSK_HDMI_RX_HKFM_119_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_119_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_119 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_119_RSVD1	 0x27bc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_119_KSV_MSB	 0x27bc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_120	0x27c0 /* HDMI HDCP KSV FIFO 120 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_120	 0x27c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_120	0x27c4 /* HDMI HDCP KSV FIFO 120 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_120	 0x27c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_120 */
	#define BLSB_HDMI_RX_HKFM_120_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_120_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_120 */
	#define BWID_HDMI_RX_HKFM_120_RSVD1	24
	#define BWID_HDMI_RX_HKFM_120_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_120 */
	#define BMSK_HDMI_RX_HKFM_120_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_120_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_120 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_120_RSVD1	 0x27c4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_120_KSV_MSB	 0x27c4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_121	0x27c8 /* HDMI HDCP KSV FIFO 121 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_121	 0x27c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_121	0x27cc /* HDMI HDCP KSV FIFO 121 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_121	 0x27cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_121 */
	#define BLSB_HDMI_RX_HKFM_121_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_121_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_121 */
	#define BWID_HDMI_RX_HKFM_121_RSVD1	24
	#define BWID_HDMI_RX_HKFM_121_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_121 */
	#define BMSK_HDMI_RX_HKFM_121_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_121_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_121 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_121_RSVD1	 0x27cc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_121_KSV_MSB	 0x27cc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_122	0x27d0 /* HDMI HDCP KSV FIFO 122 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_122	 0x27d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_122	0x27d4 /* HDMI HDCP KSV FIFO 122 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_122	 0x27d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_122 */
	#define BLSB_HDMI_RX_HKFM_122_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_122_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_122 */
	#define BWID_HDMI_RX_HKFM_122_RSVD1	24
	#define BWID_HDMI_RX_HKFM_122_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_122 */
	#define BMSK_HDMI_RX_HKFM_122_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_122_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_122 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_122_RSVD1	 0x27d4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_122_KSV_MSB	 0x27d4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_123	0x27d8 /* HDMI HDCP KSV FIFO 123 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_123	 0x27d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_123	0x27dc /* HDMI HDCP KSV FIFO 123 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_123	 0x27dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_123 */
	#define BLSB_HDMI_RX_HKFM_123_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_123_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_123 */
	#define BWID_HDMI_RX_HKFM_123_RSVD1	24
	#define BWID_HDMI_RX_HKFM_123_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_123 */
	#define BMSK_HDMI_RX_HKFM_123_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_123_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_123 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_123_RSVD1	 0x27dc, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_123_KSV_MSB	 0x27dc, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_124	0x27e0 /* HDMI HDCP KSV FIFO 124 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_124	 0x27e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_124	0x27e4 /* HDMI HDCP KSV FIFO 124 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_124	 0x27e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_124 */
	#define BLSB_HDMI_RX_HKFM_124_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_124_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_124 */
	#define BWID_HDMI_RX_HKFM_124_RSVD1	24
	#define BWID_HDMI_RX_HKFM_124_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_124 */
	#define BMSK_HDMI_RX_HKFM_124_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_124_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_124 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_124_RSVD1	 0x27e4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_124_KSV_MSB	 0x27e4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_125	0x27e8 /* HDMI HDCP KSV FIFO 125 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_125	 0x27e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_125	0x27ec /* HDMI HDCP KSV FIFO 125 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_125	 0x27ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_125 */
	#define BLSB_HDMI_RX_HKFM_125_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_125_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_125 */
	#define BWID_HDMI_RX_HKFM_125_RSVD1	24
	#define BWID_HDMI_RX_HKFM_125_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_125 */
	#define BMSK_HDMI_RX_HKFM_125_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_125_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_125 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_125_RSVD1	 0x27ec, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_125_KSV_MSB	 0x27ec, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HKFL_126	0x27f0 /* HDMI HDCP KSV FIFO 126 LSB                        */ 
	#define BITFIELD_HDMI_RX_HKFL_126	 0x27f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HKFM_126	0x27f4 /* HDMI HDCP KSV FIFO 126 MSB                        */ 
	#define BITFIELD_HDMI_RX_HKFM_126	 0x27f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for HDMI_RX_HKFM_126 */
	#define BLSB_HDMI_RX_HKFM_126_RSVD1	8
	#define BLSB_HDMI_RX_HKFM_126_KSV_MSB	0
	/* Register Bit Widths for HDMI_RX_HKFM_126 */
	#define BWID_HDMI_RX_HKFM_126_RSVD1	24
	#define BWID_HDMI_RX_HKFM_126_KSV_MSB	8
	/* Register Bit MASKS for HDMI_RX_HKFM_126 */
	#define BMSK_HDMI_RX_HKFM_126_RSVD1	0xffffff00 /*  */
	#define BMSK_HDMI_RX_HKFM_126_KSV_MSB	0x000000ff /*  */
	/* Register BITFIELD for HDMI_RX_HKFM_126 - roff, lsb, width, mask */
	#define BITFIELD_HDMI_RX_HKFM_126_RSVD1	 0x27f4, 8, 24, 0xffffff00
	#define BITFIELD_HDMI_RX_HKFM_126_KSV_MSB	 0x27f4, 0, 8, 0x000000ff
#define ROFF_HDMI_RX_HEDR_0	0x3800 /* HDMI EDID Buffer Register 0                       */ 
	#define BITFIELD_HDMI_RX_HEDR_0	 0x3800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_1	0x3804 /* HDMI EDID Buffer Register 1                       */ 
	#define BITFIELD_HDMI_RX_HEDR_1	 0x3804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_2	0x3808 /* HDMI EDID Buffer Register 2                       */ 
	#define BITFIELD_HDMI_RX_HEDR_2	 0x3808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_3	0x380c /* HDMI EDID Buffer Register 3                       */ 
	#define BITFIELD_HDMI_RX_HEDR_3	 0x380c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_4	0x3810 /* HDMI EDID Buffer Register 4                       */ 
	#define BITFIELD_HDMI_RX_HEDR_4	 0x3810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_5	0x3814 /* HDMI EDID Buffer Register 5                       */ 
	#define BITFIELD_HDMI_RX_HEDR_5	 0x3814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_6	0x3818 /* HDMI EDID Buffer Register 6                       */ 
	#define BITFIELD_HDMI_RX_HEDR_6	 0x3818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_7	0x381c /* HDMI EDID Buffer Register 7                       */ 
	#define BITFIELD_HDMI_RX_HEDR_7	 0x381c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_8	0x3820 /* HDMI EDID Buffer Register 8                       */ 
	#define BITFIELD_HDMI_RX_HEDR_8	 0x3820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_9	0x3824 /* HDMI EDID Buffer Register 9                       */ 
	#define BITFIELD_HDMI_RX_HEDR_9	 0x3824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_10	0x3828 /* HDMI EDID Buffer Register 10                      */ 
	#define BITFIELD_HDMI_RX_HEDR_10	 0x3828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_11	0x382c /* HDMI EDID Buffer Register 11                      */ 
	#define BITFIELD_HDMI_RX_HEDR_11	 0x382c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_12	0x3830 /* HDMI EDID Buffer Register 12                      */ 
	#define BITFIELD_HDMI_RX_HEDR_12	 0x3830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_13	0x3834 /* HDMI EDID Buffer Register 13                      */ 
	#define BITFIELD_HDMI_RX_HEDR_13	 0x3834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_14	0x3838 /* HDMI EDID Buffer Register 14                      */ 
	#define BITFIELD_HDMI_RX_HEDR_14	 0x3838, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_15	0x383c /* HDMI EDID Buffer Register 15                      */ 
	#define BITFIELD_HDMI_RX_HEDR_15	 0x383c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_16	0x3840 /* HDMI EDID Buffer Register 16                      */ 
	#define BITFIELD_HDMI_RX_HEDR_16	 0x3840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_17	0x3844 /* HDMI EDID Buffer Register 17                      */ 
	#define BITFIELD_HDMI_RX_HEDR_17	 0x3844, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_18	0x3848 /* HDMI EDID Buffer Register 18                      */ 
	#define BITFIELD_HDMI_RX_HEDR_18	 0x3848, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_19	0x384c /* HDMI EDID Buffer Register 19                      */ 
	#define BITFIELD_HDMI_RX_HEDR_19	 0x384c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_20	0x3850 /* HDMI EDID Buffer Register 20                      */ 
	#define BITFIELD_HDMI_RX_HEDR_20	 0x3850, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_21	0x3854 /* HDMI EDID Buffer Register 21                      */ 
	#define BITFIELD_HDMI_RX_HEDR_21	 0x3854, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_22	0x3858 /* HDMI EDID Buffer Register 22                      */ 
	#define BITFIELD_HDMI_RX_HEDR_22	 0x3858, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_23	0x385c /* HDMI EDID Buffer Register 23                      */ 
	#define BITFIELD_HDMI_RX_HEDR_23	 0x385c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_24	0x3860 /* HDMI EDID Buffer Register 24                      */ 
	#define BITFIELD_HDMI_RX_HEDR_24	 0x3860, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_25	0x3864 /* HDMI EDID Buffer Register 25                      */ 
	#define BITFIELD_HDMI_RX_HEDR_25	 0x3864, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_26	0x3868 /* HDMI EDID Buffer Register 26                      */ 
	#define BITFIELD_HDMI_RX_HEDR_26	 0x3868, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_27	0x386c /* HDMI EDID Buffer Register 27                      */ 
	#define BITFIELD_HDMI_RX_HEDR_27	 0x386c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_28	0x3870 /* HDMI EDID Buffer Register 28                      */ 
	#define BITFIELD_HDMI_RX_HEDR_28	 0x3870, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_29	0x3874 /* HDMI EDID Buffer Register 29                      */ 
	#define BITFIELD_HDMI_RX_HEDR_29	 0x3874, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_30	0x3878 /* HDMI EDID Buffer Register 30                      */ 
	#define BITFIELD_HDMI_RX_HEDR_30	 0x3878, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_31	0x387c /* HDMI EDID Buffer Register 31                      */ 
	#define BITFIELD_HDMI_RX_HEDR_31	 0x387c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_32	0x3880 /* HDMI EDID Buffer Register 32                      */ 
	#define BITFIELD_HDMI_RX_HEDR_32	 0x3880, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_33	0x3884 /* HDMI EDID Buffer Register 33                      */ 
	#define BITFIELD_HDMI_RX_HEDR_33	 0x3884, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_34	0x3888 /* HDMI EDID Buffer Register 34                      */ 
	#define BITFIELD_HDMI_RX_HEDR_34	 0x3888, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_35	0x388c /* HDMI EDID Buffer Register 35                      */ 
	#define BITFIELD_HDMI_RX_HEDR_35	 0x388c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_36	0x3890 /* HDMI EDID Buffer Register 36                      */ 
	#define BITFIELD_HDMI_RX_HEDR_36	 0x3890, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_37	0x3894 /* HDMI EDID Buffer Register 37                      */ 
	#define BITFIELD_HDMI_RX_HEDR_37	 0x3894, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_38	0x3898 /* HDMI EDID Buffer Register 38                      */ 
	#define BITFIELD_HDMI_RX_HEDR_38	 0x3898, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_39	0x389c /* HDMI EDID Buffer Register 39                      */ 
	#define BITFIELD_HDMI_RX_HEDR_39	 0x389c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_40	0x38a0 /* HDMI EDID Buffer Register 40                      */ 
	#define BITFIELD_HDMI_RX_HEDR_40	 0x38a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_41	0x38a4 /* HDMI EDID Buffer Register 41                      */ 
	#define BITFIELD_HDMI_RX_HEDR_41	 0x38a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_42	0x38a8 /* HDMI EDID Buffer Register 42                      */ 
	#define BITFIELD_HDMI_RX_HEDR_42	 0x38a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_43	0x38ac /* HDMI EDID Buffer Register 43                      */ 
	#define BITFIELD_HDMI_RX_HEDR_43	 0x38ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_44	0x38b0 /* HDMI EDID Buffer Register 44                      */ 
	#define BITFIELD_HDMI_RX_HEDR_44	 0x38b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_45	0x38b4 /* HDMI EDID Buffer Register 45                      */ 
	#define BITFIELD_HDMI_RX_HEDR_45	 0x38b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_46	0x38b8 /* HDMI EDID Buffer Register 46                      */ 
	#define BITFIELD_HDMI_RX_HEDR_46	 0x38b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_47	0x38bc /* HDMI EDID Buffer Register 47                      */ 
	#define BITFIELD_HDMI_RX_HEDR_47	 0x38bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_48	0x38c0 /* HDMI EDID Buffer Register 48                      */ 
	#define BITFIELD_HDMI_RX_HEDR_48	 0x38c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_49	0x38c4 /* HDMI EDID Buffer Register 49                      */ 
	#define BITFIELD_HDMI_RX_HEDR_49	 0x38c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_50	0x38c8 /* HDMI EDID Buffer Register 50                      */ 
	#define BITFIELD_HDMI_RX_HEDR_50	 0x38c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_51	0x38cc /* HDMI EDID Buffer Register 51                      */ 
	#define BITFIELD_HDMI_RX_HEDR_51	 0x38cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_52	0x38d0 /* HDMI EDID Buffer Register 52                      */ 
	#define BITFIELD_HDMI_RX_HEDR_52	 0x38d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_53	0x38d4 /* HDMI EDID Buffer Register 53                      */ 
	#define BITFIELD_HDMI_RX_HEDR_53	 0x38d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_54	0x38d8 /* HDMI EDID Buffer Register 54                      */ 
	#define BITFIELD_HDMI_RX_HEDR_54	 0x38d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_55	0x38dc /* HDMI EDID Buffer Register 55                      */ 
	#define BITFIELD_HDMI_RX_HEDR_55	 0x38dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_56	0x38e0 /* HDMI EDID Buffer Register 56                      */ 
	#define BITFIELD_HDMI_RX_HEDR_56	 0x38e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_57	0x38e4 /* HDMI EDID Buffer Register 57                      */ 
	#define BITFIELD_HDMI_RX_HEDR_57	 0x38e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_58	0x38e8 /* HDMI EDID Buffer Register 58                      */ 
	#define BITFIELD_HDMI_RX_HEDR_58	 0x38e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_59	0x38ec /* HDMI EDID Buffer Register 59                      */ 
	#define BITFIELD_HDMI_RX_HEDR_59	 0x38ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_60	0x38f0 /* HDMI EDID Buffer Register 60                      */ 
	#define BITFIELD_HDMI_RX_HEDR_60	 0x38f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_61	0x38f4 /* HDMI EDID Buffer Register 61                      */ 
	#define BITFIELD_HDMI_RX_HEDR_61	 0x38f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_62	0x38f8 /* HDMI EDID Buffer Register 62                      */ 
	#define BITFIELD_HDMI_RX_HEDR_62	 0x38f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_HDMI_RX_HEDR_63	0x38fc /* HDMI EDID Buffer Register 63                      */ 
	#define BITFIELD_HDMI_RX_HEDR_63	 0x38fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module HDMI_RX SPECIFIC SVEN Events */




#endif /* HDMI_RX_REGOFFS_H */
