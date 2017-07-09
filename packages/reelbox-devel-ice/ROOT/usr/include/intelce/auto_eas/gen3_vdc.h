#ifndef VDC_REGOFFS_H
#define VDC_REGOFFS_H 1
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


/* Module VDC CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_VDC_UPCONFIG_0	0x30164 /* UPP 0 Configuration */ 
	#define BITFIELD_VDC_UPCONFIG_0	 0x30164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCONFIG_0 */
	#define BLSB_VDC_UPCONFIG_0_reserved_31_18	18
	#define BLSB_VDC_UPCONFIG_0_Chroma_Key_Enab	17
	#define BLSB_VDC_UPCONFIG_0_GAMMA_BYPASS	16
	#define BLSB_VDC_UPCONFIG_0_reserved_15_7	7
	#define BLSB_VDC_UPCONFIG_0_CBCR_ISGN	6
	#define BLSB_VDC_UPCONFIG_0_CSC_EN	5
	#define BLSB_VDC_UPCONFIG_0_reserved_4_0	0
	/* Register Bit Widths for VDC_UPCONFIG_0 */
	#define BWID_VDC_UPCONFIG_0_reserved_31_18	14
	#define BWID_VDC_UPCONFIG_0_Chroma_Key_Enab	1
	#define BWID_VDC_UPCONFIG_0_GAMMA_BYPASS	1
	#define BWID_VDC_UPCONFIG_0_reserved_15_7	9
	#define BWID_VDC_UPCONFIG_0_CBCR_ISGN	1
	#define BWID_VDC_UPCONFIG_0_CSC_EN	1
	#define BWID_VDC_UPCONFIG_0_reserved_4_0	1
	/* Register Bit MASKS for VDC_UPCONFIG_0 */
	#define BMSK_VDC_UPCONFIG_0_reserved_31_18	0xfffc0000 /*  */
	#define BMSK_VDC_UPCONFIG_0_Chroma_Key_Enab	(1<<17) /* == 0x00020000:  */
	#define BMSK_VDC_UPCONFIG_0_GAMMA_BYPASS	(1<<16) /* == 0x00010000:  */
	#define BMSK_VDC_UPCONFIG_0_reserved_15_7	0x0000ff80 /*  */
	#define BMSK_VDC_UPCONFIG_0_CBCR_ISGN	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCONFIG_0_CSC_EN	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCONFIG_0_reserved_4_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCONFIG_0 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCONFIG_0_reserved_31_18	 0x30164, 18, 14, 0xfffc0000
	#define BITFIELD_VDC_UPCONFIG_0_Chroma_Key_Enab	 0x30164, 17, 1, 0x00020000
	#define BITFIELD_VDC_UPCONFIG_0_GAMMA_BYPASS	 0x30164, 16, 1, 0x00010000
	#define BITFIELD_VDC_UPCONFIG_0_reserved_15_7	 0x30164, 7, 9, 0x0000ff80
	#define BITFIELD_VDC_UPCONFIG_0_CBCR_ISGN	 0x30164, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCONFIG_0_CSC_EN	 0x30164, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCONFIG_0_reserved_4_0	 0x30164, 0, 1, 0x00000001
#define ROFF_VDC_UPCOMD_0	0x30168 /* UPP 0 Command */ 
	#define BITFIELD_VDC_UPCOMD_0	 0x30168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCOMD_0 */
	#define BLSB_VDC_UPCOMD_0_SCALING_EN	31
	#define BLSB_VDC_UPCOMD_0_reserved_30_28	28
	#define BLSB_VDC_UPCOMD_0_CLKEN	27
	#define BLSB_VDC_UPCOMD_0_MSB_SHDW_EN	26
	#define BLSB_VDC_UPCOMD_0_LINE_DOUBLE	25
	#define BLSB_VDC_UPCOMD_0_PXL_DOUBLE	24
	#define BLSB_VDC_UPCOMD_0_CONST_ALPHA	16
	#define BLSB_VDC_UPCOMD_0_reserved_15	15
	#define BLSB_VDC_UPCOMD_0_VIDEO_FORMAT	10
	#define BLSB_VDC_UPCOMD_0_SYNCFETCH_PARITY	9
	#define BLSB_VDC_UPCOMD_0_FLIP_INV_FIELD	8
	#define BLSB_VDC_UPCOMD_0_SYNCFETCH_ENBL	7
	#define BLSB_VDC_UPCOMD_0_IGNORE_FLIP_MODE	6
	#define BLSB_VDC_UPCOMD_0_reserved_5	5
	#define BLSB_VDC_UPCOMD_0_REQ_LEN_256	4
	#define BLSB_VDC_UPCOMD_0_TG_SEL	3
	#define BLSB_VDC_UPCOMD_0_LGCY_IMODE_EN	2
	#define BLSB_VDC_UPCOMD_0_ACT_F	1
	#define BLSB_VDC_UPCOMD_0_UP_ENBL	0
	/* Register Bit Widths for VDC_UPCOMD_0 */
	#define BWID_VDC_UPCOMD_0_SCALING_EN	1
	#define BWID_VDC_UPCOMD_0_reserved_30_28	3
	#define BWID_VDC_UPCOMD_0_CLKEN	1
	#define BWID_VDC_UPCOMD_0_MSB_SHDW_EN	1
	#define BWID_VDC_UPCOMD_0_LINE_DOUBLE	1
	#define BWID_VDC_UPCOMD_0_PXL_DOUBLE	1
	#define BWID_VDC_UPCOMD_0_CONST_ALPHA	8
	#define BWID_VDC_UPCOMD_0_reserved_15	1
	#define BWID_VDC_UPCOMD_0_VIDEO_FORMAT	5
	#define BWID_VDC_UPCOMD_0_SYNCFETCH_PARITY	1
	#define BWID_VDC_UPCOMD_0_FLIP_INV_FIELD	1
	#define BWID_VDC_UPCOMD_0_SYNCFETCH_ENBL	1
	#define BWID_VDC_UPCOMD_0_IGNORE_FLIP_MODE	1
	#define BWID_VDC_UPCOMD_0_reserved_5	1
	#define BWID_VDC_UPCOMD_0_REQ_LEN_256	1
	#define BWID_VDC_UPCOMD_0_TG_SEL	1
	#define BWID_VDC_UPCOMD_0_LGCY_IMODE_EN	1
	#define BWID_VDC_UPCOMD_0_ACT_F	1
	#define BWID_VDC_UPCOMD_0_UP_ENBL	1
	/* Register Bit MASKS for VDC_UPCOMD_0 */
	#define BMSK_VDC_UPCOMD_0_SCALING_EN	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UPCOMD_0_reserved_30_28	0x70000000 /*  */
	#define BMSK_VDC_UPCOMD_0_CLKEN	(1<<27) /* == 0x08000000:  */
	#define BMSK_VDC_UPCOMD_0_MSB_SHDW_EN	(1<<26) /* == 0x04000000:  */
	#define BMSK_VDC_UPCOMD_0_LINE_DOUBLE	(1<<25) /* == 0x02000000:  */
	#define BMSK_VDC_UPCOMD_0_PXL_DOUBLE	(1<<24) /* == 0x01000000:  */
	#define BMSK_VDC_UPCOMD_0_CONST_ALPHA	0x00ff0000 /*  */
	#define BMSK_VDC_UPCOMD_0_reserved_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UPCOMD_0_VIDEO_FORMAT	0x00007c00 /*  */
	#define BMSK_VDC_UPCOMD_0_SYNCFETCH_PARITY	(1<<9) /* == 0x00000200:  */
	#define BMSK_VDC_UPCOMD_0_FLIP_INV_FIELD	(1<<8) /* == 0x00000100:  */
	#define BMSK_VDC_UPCOMD_0_SYNCFETCH_ENBL	(1<<7) /* == 0x00000080:  */
	#define BMSK_VDC_UPCOMD_0_IGNORE_FLIP_MODE	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCOMD_0_reserved_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCOMD_0_REQ_LEN_256	(1<<4) /* == 0x00000010:  */
	#define BMSK_VDC_UPCOMD_0_TG_SEL	(1<<3) /* == 0x00000008:  */
	#define BMSK_VDC_UPCOMD_0_LGCY_IMODE_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_VDC_UPCOMD_0_ACT_F	(1<<1) /* == 0x00000002:  */
	#define BMSK_VDC_UPCOMD_0_UP_ENBL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCOMD_0 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCOMD_0_SCALING_EN	 0x30168, 31, 1, 0x80000000
	#define BITFIELD_VDC_UPCOMD_0_reserved_30_28	 0x30168, 28, 3, 0x70000000
	#define BITFIELD_VDC_UPCOMD_0_CLKEN	 0x30168, 27, 1, 0x08000000
	#define BITFIELD_VDC_UPCOMD_0_MSB_SHDW_EN	 0x30168, 26, 1, 0x04000000
	#define BITFIELD_VDC_UPCOMD_0_LINE_DOUBLE	 0x30168, 25, 1, 0x02000000
	#define BITFIELD_VDC_UPCOMD_0_PXL_DOUBLE	 0x30168, 24, 1, 0x01000000
	#define BITFIELD_VDC_UPCOMD_0_CONST_ALPHA	 0x30168, 16, 8, 0x00ff0000
	#define BITFIELD_VDC_UPCOMD_0_reserved_15	 0x30168, 15, 1, 0x00008000
	#define BITFIELD_VDC_UPCOMD_0_VIDEO_FORMAT	 0x30168, 10, 5, 0x00007c00
	#define BITFIELD_VDC_UPCOMD_0_SYNCFETCH_PARITY	 0x30168, 9, 1, 0x00000200
	#define BITFIELD_VDC_UPCOMD_0_FLIP_INV_FIELD	 0x30168, 8, 1, 0x00000100
	#define BITFIELD_VDC_UPCOMD_0_SYNCFETCH_ENBL	 0x30168, 7, 1, 0x00000080
	#define BITFIELD_VDC_UPCOMD_0_IGNORE_FLIP_MODE	 0x30168, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCOMD_0_reserved_5	 0x30168, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCOMD_0_REQ_LEN_256	 0x30168, 4, 1, 0x00000010
	#define BITFIELD_VDC_UPCOMD_0_TG_SEL	 0x30168, 3, 1, 0x00000008
	#define BITFIELD_VDC_UPCOMD_0_LGCY_IMODE_EN	 0x30168, 2, 1, 0x00000004
	#define BITFIELD_VDC_UPCOMD_0_ACT_F	 0x30168, 1, 1, 0x00000002
	#define BITFIELD_VDC_UPCOMD_0_UP_ENBL	 0x30168, 0, 1, 0x00000001
#define ROFF_VDC_UPFLIPMODE_0	0x3016c /* UPP 0 Flip Mode */ 
	#define BITFIELD_VDC_UPFLIPMODE_0	 0x3016c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFLIPDIS_0	0x3000c /* UPP 0 Flip Disable */ 
	#define BITFIELD_VDC_UPFLIPDIS_0	 0x3000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBLCONFIG_0	0x30178 /* UPP 0 Blender Config */ 
	#define BITFIELD_VDC_UPBLCONFIG_0	 0x30178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F0_0	0x30100 /* UPP 0 Y/RGB field 0 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F0_0	 0x30100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F1_0	0x30104 /* UPP 0 Y/RGB field 1 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F1_0	 0x30104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F0_0	0x30108 /* UPP 0 CbCr  field 0 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F0_0	 0x30108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F1_0	0x3010c /* UPP 0 CbCr  field 1 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F1_0	 0x3010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_POFF_0	0x30064 /* UPP 0 Pixel Offset */ 
	#define BITFIELD_VDC_UPBUF_POFF_0	 0x30064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPBUF_POFF_0 */
	#define BLSB_VDC_UPBUF_POFF_0_reserved_31_27	27
	#define BLSB_VDC_UPBUF_POFF_0_CbCr_OFF	16
	#define BLSB_VDC_UPBUF_POFF_0_reserved_15_11	11
	#define BLSB_VDC_UPBUF_POFF_0_YRGB_OFF	0
	/* Register Bit Widths for VDC_UPBUF_POFF_0 */
	#define BWID_VDC_UPBUF_POFF_0_reserved_31_27	5
	#define BWID_VDC_UPBUF_POFF_0_CbCr_OFF	10
	#define BWID_VDC_UPBUF_POFF_0_reserved_15_11	5
	#define BWID_VDC_UPBUF_POFF_0_YRGB_OFF	10
	/* Register Bit MASKS for VDC_UPBUF_POFF_0 */
	#define BMSK_VDC_UPBUF_POFF_0_reserved_31_27	0xf8000000 /*  */
	#define BMSK_VDC_UPBUF_POFF_0_CbCr_OFF	0x03ff0000 /*  */
	#define BMSK_VDC_UPBUF_POFF_0_reserved_15_11	0x0000f800 /*  */
	#define BMSK_VDC_UPBUF_POFF_0_YRGB_OFF	0x000003ff /*  */
	/* Register BITFIELD for VDC_UPBUF_POFF_0 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPBUF_POFF_0_reserved_31_27	 0x30064, 27, 5, 0xf8000000
	#define BITFIELD_VDC_UPBUF_POFF_0_CbCr_OFF	 0x30064, 16, 10, 0x03ff0000
	#define BITFIELD_VDC_UPBUF_POFF_0_reserved_15_11	 0x30064, 11, 5, 0x0000f800
	#define BITFIELD_VDC_UPBUF_POFF_0_YRGB_OFF	 0x30064, 0, 10, 0x000003ff
#define ROFF_VDC_UP_STRIDE_0	0x30118 /* UPP 0 Video Stride */ 
	#define BITFIELD_VDC_UP_STRIDE_0	 0x30118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UP_STRIDE_0 */
	#define BLSB_VDC_UP_STRIDE_0_reserved_31	31
	#define BLSB_VDC_UP_STRIDE_0_CbCr_STRIDE	16
	#define BLSB_VDC_UP_STRIDE_0_IPHASE	15
	#define BLSB_VDC_UP_STRIDE_0_YRGB_STRIDE	0
	/* Register Bit Widths for VDC_UP_STRIDE_0 */
	#define BWID_VDC_UP_STRIDE_0_reserved_31	1
	#define BWID_VDC_UP_STRIDE_0_CbCr_STRIDE	15
	#define BWID_VDC_UP_STRIDE_0_IPHASE	1
	#define BWID_VDC_UP_STRIDE_0_YRGB_STRIDE	15
	/* Register Bit MASKS for VDC_UP_STRIDE_0 */
	#define BMSK_VDC_UP_STRIDE_0_reserved_31	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UP_STRIDE_0_CbCr_STRIDE	0x7fff0000 /*  */
	#define BMSK_VDC_UP_STRIDE_0_IPHASE	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UP_STRIDE_0_YRGB_STRIDE	0x00007fff /*  */
	/* Register BITFIELD for VDC_UP_STRIDE_0 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UP_STRIDE_0_reserved_31	 0x30118, 31, 1, 0x80000000
	#define BITFIELD_VDC_UP_STRIDE_0_CbCr_STRIDE	 0x30118, 16, 15, 0x7fff0000
	#define BITFIELD_VDC_UP_STRIDE_0_IPHASE	 0x30118, 15, 1, 0x00008000
	#define BITFIELD_VDC_UP_STRIDE_0_YRGB_STRIDE	 0x30118, 0, 15, 0x00007fff
#define ROFF_VDC_UPDWINPOS_0	0x3012c /* UPP 0 Destination Position */ 
	#define BITFIELD_VDC_UPDWINPOS_0	 0x3012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPDWINSZ_0	0x30130 /* UPP 0 Destination Size */ 
	#define BITFIELD_VDC_UPDWINSZ_0	 0x30130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSWIDTH_0	0x30134 /* UPP 0 Source Width */ 
	#define BITFIELD_VDC_UPSWIDTH_0	 0x30134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSHEIGHT_0	0x3013c /* UPP 0 Source Height */ 
	#define BITFIELD_VDC_UPSHEIGHT_0	 0x3013c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_Y_0	0x30140 /* UPP 0 L/C Keying Y/G */ 
	#define BITFIELD_VDC_UPLCKEY_Y_0	 0x30140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CB_0	0x30144 /* UPP 0 L/C Keying Cb/B */ 
	#define BITFIELD_VDC_UPLCKEY_CB_0	 0x30144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CR_0	0x30148 /* UPP 0 L/C Keying Cr/R */ 
	#define BITFIELD_VDC_UPLCKEY_CR_0	 0x30148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCPC_0	0x30200 /* UPP 0 CSC Clamp */ 
	#define BITFIELD_VDC_UPCSCPC_0	 0x30200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCYGOFF_0	0x30204 /* UPP 0 CSC Y/G Offset */ 
	#define BITFIELD_VDC_UPCSCYGOFF_0	 0x30204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCBOFF_0	0x30208 /* UPP 0 CSC Cb/B Offset */ 
	#define BITFIELD_VDC_UPCSCCBOFF_0	 0x30208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCROFF_0	0x3020c /* UPP 0 CSC Cr/R Offset */ 
	#define BITFIELD_VDC_UPCSCCROFF_0	 0x3020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C01_0	0x30210 /* UPP 0 CSC Coefficient01 */ 
	#define BITFIELD_VDC_UPCSC_C01_0	 0x30210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C23_0	0x30214 /* UPP 0 CSC Coefficient23 */ 
	#define BITFIELD_VDC_UPCSC_C23_0	 0x30214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C45_0	0x30218 /* UPP 0 CSC Coefficient45 */ 
	#define BITFIELD_VDC_UPCSC_C45_0	 0x30218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C67_0	0x3021c /* UPP 0 CSC Coefficient67 */ 
	#define BITFIELD_VDC_UPCSC_C67_0	 0x3021c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C8_0	0x30220 /* UPP 0 CSC Coefficient8 */ 
	#define BITFIELD_VDC_UPCSC_C8_0	 0x30220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPVGAMLUT_0	0x30900 /* UPP 0 Gamma Correction */ 
	#define BITFIELD_VDC_UPVGAMLUT_0	 0x30900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DUPSTA_0	0x30008 /* UPP 0 Status */ 
	#define BITFIELD_VDC_DUPSTA_0	 0x30008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFDROP_0	0x30170 /* UPP 0 Frame Drop Counter */ 
	#define BITFIELD_VDC_UPFDROP_0	 0x30170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFREPEAT_0	0x30174 /* UPP 0 Frame Repeat Counter */ 
	#define BITFIELD_VDC_UPFREPEAT_0	 0x30174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCONFIG_1	0x31164 /* UPP 1 Configuration */ 
	#define BITFIELD_VDC_UPCONFIG_1	 0x31164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCONFIG_1 */
	#define BLSB_VDC_UPCONFIG_1_reserved_31_18	18
	#define BLSB_VDC_UPCONFIG_1_Chroma_Key_Enab	17
	#define BLSB_VDC_UPCONFIG_1_GAMMA_BYPASS	16
	#define BLSB_VDC_UPCONFIG_1_reserved_15_7	7
	#define BLSB_VDC_UPCONFIG_1_CBCR_ISGN	6
	#define BLSB_VDC_UPCONFIG_1_CSC_EN	5
	#define BLSB_VDC_UPCONFIG_1_reserved_4_0	0
	/* Register Bit Widths for VDC_UPCONFIG_1 */
	#define BWID_VDC_UPCONFIG_1_reserved_31_18	14
	#define BWID_VDC_UPCONFIG_1_Chroma_Key_Enab	1
	#define BWID_VDC_UPCONFIG_1_GAMMA_BYPASS	1
	#define BWID_VDC_UPCONFIG_1_reserved_15_7	9
	#define BWID_VDC_UPCONFIG_1_CBCR_ISGN	1
	#define BWID_VDC_UPCONFIG_1_CSC_EN	1
	#define BWID_VDC_UPCONFIG_1_reserved_4_0	1
	/* Register Bit MASKS for VDC_UPCONFIG_1 */
	#define BMSK_VDC_UPCONFIG_1_reserved_31_18	0xfffc0000 /*  */
	#define BMSK_VDC_UPCONFIG_1_Chroma_Key_Enab	(1<<17) /* == 0x00020000:  */
	#define BMSK_VDC_UPCONFIG_1_GAMMA_BYPASS	(1<<16) /* == 0x00010000:  */
	#define BMSK_VDC_UPCONFIG_1_reserved_15_7	0x0000ff80 /*  */
	#define BMSK_VDC_UPCONFIG_1_CBCR_ISGN	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCONFIG_1_CSC_EN	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCONFIG_1_reserved_4_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCONFIG_1 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCONFIG_1_reserved_31_18	 0x31164, 18, 14, 0xfffc0000
	#define BITFIELD_VDC_UPCONFIG_1_Chroma_Key_Enab	 0x31164, 17, 1, 0x00020000
	#define BITFIELD_VDC_UPCONFIG_1_GAMMA_BYPASS	 0x31164, 16, 1, 0x00010000
	#define BITFIELD_VDC_UPCONFIG_1_reserved_15_7	 0x31164, 7, 9, 0x0000ff80
	#define BITFIELD_VDC_UPCONFIG_1_CBCR_ISGN	 0x31164, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCONFIG_1_CSC_EN	 0x31164, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCONFIG_1_reserved_4_0	 0x31164, 0, 1, 0x00000001
#define ROFF_VDC_UPCOMD_1	0x31168 /* UPP 1 Command */ 
	#define BITFIELD_VDC_UPCOMD_1	 0x31168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCOMD_1 */
	#define BLSB_VDC_UPCOMD_1_SCALING_EN	31
	#define BLSB_VDC_UPCOMD_1_reserved_30_28	28
	#define BLSB_VDC_UPCOMD_1_CLKEN	27
	#define BLSB_VDC_UPCOMD_1_MSB_SHDW_EN	26
	#define BLSB_VDC_UPCOMD_1_LINE_DOUBLE	25
	#define BLSB_VDC_UPCOMD_1_PXL_DOUBLE	24
	#define BLSB_VDC_UPCOMD_1_CONST_ALPHA	16
	#define BLSB_VDC_UPCOMD_1_reserved_15	15
	#define BLSB_VDC_UPCOMD_1_VIDEO_FORMAT	10
	#define BLSB_VDC_UPCOMD_1_SYNCFETCH_PARITY	9
	#define BLSB_VDC_UPCOMD_1_FLIP_INV_FIELD	8
	#define BLSB_VDC_UPCOMD_1_SYNCFETCH_ENBL	7
	#define BLSB_VDC_UPCOMD_1_IGNORE_FLIP_MODE	6
	#define BLSB_VDC_UPCOMD_1_reserved_5	5
	#define BLSB_VDC_UPCOMD_1_REQ_LEN_256	4
	#define BLSB_VDC_UPCOMD_1_TG_SEL	3
	#define BLSB_VDC_UPCOMD_1_LGCY_IMODE_EN	2
	#define BLSB_VDC_UPCOMD_1_ACT_F	1
	#define BLSB_VDC_UPCOMD_1_UP_ENBL	0
	/* Register Bit Widths for VDC_UPCOMD_1 */
	#define BWID_VDC_UPCOMD_1_SCALING_EN	1
	#define BWID_VDC_UPCOMD_1_reserved_30_28	3
	#define BWID_VDC_UPCOMD_1_CLKEN	1
	#define BWID_VDC_UPCOMD_1_MSB_SHDW_EN	1
	#define BWID_VDC_UPCOMD_1_LINE_DOUBLE	1
	#define BWID_VDC_UPCOMD_1_PXL_DOUBLE	1
	#define BWID_VDC_UPCOMD_1_CONST_ALPHA	8
	#define BWID_VDC_UPCOMD_1_reserved_15	1
	#define BWID_VDC_UPCOMD_1_VIDEO_FORMAT	5
	#define BWID_VDC_UPCOMD_1_SYNCFETCH_PARITY	1
	#define BWID_VDC_UPCOMD_1_FLIP_INV_FIELD	1
	#define BWID_VDC_UPCOMD_1_SYNCFETCH_ENBL	1
	#define BWID_VDC_UPCOMD_1_IGNORE_FLIP_MODE	1
	#define BWID_VDC_UPCOMD_1_reserved_5	1
	#define BWID_VDC_UPCOMD_1_REQ_LEN_256	1
	#define BWID_VDC_UPCOMD_1_TG_SEL	1
	#define BWID_VDC_UPCOMD_1_LGCY_IMODE_EN	1
	#define BWID_VDC_UPCOMD_1_ACT_F	1
	#define BWID_VDC_UPCOMD_1_UP_ENBL	1
	/* Register Bit MASKS for VDC_UPCOMD_1 */
	#define BMSK_VDC_UPCOMD_1_SCALING_EN	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UPCOMD_1_reserved_30_28	0x70000000 /*  */
	#define BMSK_VDC_UPCOMD_1_CLKEN	(1<<27) /* == 0x08000000:  */
	#define BMSK_VDC_UPCOMD_1_MSB_SHDW_EN	(1<<26) /* == 0x04000000:  */
	#define BMSK_VDC_UPCOMD_1_LINE_DOUBLE	(1<<25) /* == 0x02000000:  */
	#define BMSK_VDC_UPCOMD_1_PXL_DOUBLE	(1<<24) /* == 0x01000000:  */
	#define BMSK_VDC_UPCOMD_1_CONST_ALPHA	0x00ff0000 /*  */
	#define BMSK_VDC_UPCOMD_1_reserved_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UPCOMD_1_VIDEO_FORMAT	0x00007c00 /*  */
	#define BMSK_VDC_UPCOMD_1_SYNCFETCH_PARITY	(1<<9) /* == 0x00000200:  */
	#define BMSK_VDC_UPCOMD_1_FLIP_INV_FIELD	(1<<8) /* == 0x00000100:  */
	#define BMSK_VDC_UPCOMD_1_SYNCFETCH_ENBL	(1<<7) /* == 0x00000080:  */
	#define BMSK_VDC_UPCOMD_1_IGNORE_FLIP_MODE	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCOMD_1_reserved_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCOMD_1_REQ_LEN_256	(1<<4) /* == 0x00000010:  */
	#define BMSK_VDC_UPCOMD_1_TG_SEL	(1<<3) /* == 0x00000008:  */
	#define BMSK_VDC_UPCOMD_1_LGCY_IMODE_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_VDC_UPCOMD_1_ACT_F	(1<<1) /* == 0x00000002:  */
	#define BMSK_VDC_UPCOMD_1_UP_ENBL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCOMD_1 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCOMD_1_SCALING_EN	 0x31168, 31, 1, 0x80000000
	#define BITFIELD_VDC_UPCOMD_1_reserved_30_28	 0x31168, 28, 3, 0x70000000
	#define BITFIELD_VDC_UPCOMD_1_CLKEN	 0x31168, 27, 1, 0x08000000
	#define BITFIELD_VDC_UPCOMD_1_MSB_SHDW_EN	 0x31168, 26, 1, 0x04000000
	#define BITFIELD_VDC_UPCOMD_1_LINE_DOUBLE	 0x31168, 25, 1, 0x02000000
	#define BITFIELD_VDC_UPCOMD_1_PXL_DOUBLE	 0x31168, 24, 1, 0x01000000
	#define BITFIELD_VDC_UPCOMD_1_CONST_ALPHA	 0x31168, 16, 8, 0x00ff0000
	#define BITFIELD_VDC_UPCOMD_1_reserved_15	 0x31168, 15, 1, 0x00008000
	#define BITFIELD_VDC_UPCOMD_1_VIDEO_FORMAT	 0x31168, 10, 5, 0x00007c00
	#define BITFIELD_VDC_UPCOMD_1_SYNCFETCH_PARITY	 0x31168, 9, 1, 0x00000200
	#define BITFIELD_VDC_UPCOMD_1_FLIP_INV_FIELD	 0x31168, 8, 1, 0x00000100
	#define BITFIELD_VDC_UPCOMD_1_SYNCFETCH_ENBL	 0x31168, 7, 1, 0x00000080
	#define BITFIELD_VDC_UPCOMD_1_IGNORE_FLIP_MODE	 0x31168, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCOMD_1_reserved_5	 0x31168, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCOMD_1_REQ_LEN_256	 0x31168, 4, 1, 0x00000010
	#define BITFIELD_VDC_UPCOMD_1_TG_SEL	 0x31168, 3, 1, 0x00000008
	#define BITFIELD_VDC_UPCOMD_1_LGCY_IMODE_EN	 0x31168, 2, 1, 0x00000004
	#define BITFIELD_VDC_UPCOMD_1_ACT_F	 0x31168, 1, 1, 0x00000002
	#define BITFIELD_VDC_UPCOMD_1_UP_ENBL	 0x31168, 0, 1, 0x00000001
#define ROFF_VDC_UPFLIPMODE_1	0x3116c /* UPP 1 Flip Mode */ 
	#define BITFIELD_VDC_UPFLIPMODE_1	 0x3116c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFLIPDIS_1	0x3100c /* UPP 1 Flip Disable */ 
	#define BITFIELD_VDC_UPFLIPDIS_1	 0x3100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBLCONFIG_1	0x31178 /* UPP 1 Blender Config */ 
	#define BITFIELD_VDC_UPBLCONFIG_1	 0x31178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F0_1	0x31100 /* UPP 1 Y/RGB field 0 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F0_1	 0x31100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F1_1	0x31104 /* UPP 1 Y/RGB field 1 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F1_1	 0x31104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F0_1	0x31108 /* UPP 1 CbCr  field 0 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F0_1	 0x31108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F1_1	0x3110c /* UPP 1 CbCr  field 1 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F1_1	 0x3110c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_POFF_1	0x31064 /* UPP 1 Pixel Offset */ 
	#define BITFIELD_VDC_UPBUF_POFF_1	 0x31064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPBUF_POFF_1 */
	#define BLSB_VDC_UPBUF_POFF_1_reserved_31_27	27
	#define BLSB_VDC_UPBUF_POFF_1_CbCr_OFF	16
	#define BLSB_VDC_UPBUF_POFF_1_reserved_15_11	11
	#define BLSB_VDC_UPBUF_POFF_1_YRGB_OFF	0
	/* Register Bit Widths for VDC_UPBUF_POFF_1 */
	#define BWID_VDC_UPBUF_POFF_1_reserved_31_27	5
	#define BWID_VDC_UPBUF_POFF_1_CbCr_OFF	10
	#define BWID_VDC_UPBUF_POFF_1_reserved_15_11	5
	#define BWID_VDC_UPBUF_POFF_1_YRGB_OFF	10
	/* Register Bit MASKS for VDC_UPBUF_POFF_1 */
	#define BMSK_VDC_UPBUF_POFF_1_reserved_31_27	0xf8000000 /*  */
	#define BMSK_VDC_UPBUF_POFF_1_CbCr_OFF	0x03ff0000 /*  */
	#define BMSK_VDC_UPBUF_POFF_1_reserved_15_11	0x0000f800 /*  */
	#define BMSK_VDC_UPBUF_POFF_1_YRGB_OFF	0x000003ff /*  */
	/* Register BITFIELD for VDC_UPBUF_POFF_1 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPBUF_POFF_1_reserved_31_27	 0x31064, 27, 5, 0xf8000000
	#define BITFIELD_VDC_UPBUF_POFF_1_CbCr_OFF	 0x31064, 16, 10, 0x03ff0000
	#define BITFIELD_VDC_UPBUF_POFF_1_reserved_15_11	 0x31064, 11, 5, 0x0000f800
	#define BITFIELD_VDC_UPBUF_POFF_1_YRGB_OFF	 0x31064, 0, 10, 0x000003ff
#define ROFF_VDC_UP_STRIDE_1	0x31118 /* UPP 1 Video Stride */ 
	#define BITFIELD_VDC_UP_STRIDE_1	 0x31118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UP_STRIDE_1 */
	#define BLSB_VDC_UP_STRIDE_1_reserved_31	31
	#define BLSB_VDC_UP_STRIDE_1_CbCr_STRIDE	16
	#define BLSB_VDC_UP_STRIDE_1_IPHASE	15
	#define BLSB_VDC_UP_STRIDE_1_YRGB_STRIDE	0
	/* Register Bit Widths for VDC_UP_STRIDE_1 */
	#define BWID_VDC_UP_STRIDE_1_reserved_31	1
	#define BWID_VDC_UP_STRIDE_1_CbCr_STRIDE	15
	#define BWID_VDC_UP_STRIDE_1_IPHASE	1
	#define BWID_VDC_UP_STRIDE_1_YRGB_STRIDE	15
	/* Register Bit MASKS for VDC_UP_STRIDE_1 */
	#define BMSK_VDC_UP_STRIDE_1_reserved_31	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UP_STRIDE_1_CbCr_STRIDE	0x7fff0000 /*  */
	#define BMSK_VDC_UP_STRIDE_1_IPHASE	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UP_STRIDE_1_YRGB_STRIDE	0x00007fff /*  */
	/* Register BITFIELD for VDC_UP_STRIDE_1 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UP_STRIDE_1_reserved_31	 0x31118, 31, 1, 0x80000000
	#define BITFIELD_VDC_UP_STRIDE_1_CbCr_STRIDE	 0x31118, 16, 15, 0x7fff0000
	#define BITFIELD_VDC_UP_STRIDE_1_IPHASE	 0x31118, 15, 1, 0x00008000
	#define BITFIELD_VDC_UP_STRIDE_1_YRGB_STRIDE	 0x31118, 0, 15, 0x00007fff
#define ROFF_VDC_UPDWINPOS_1	0x3112c /* UPP 1 Destination Position */ 
	#define BITFIELD_VDC_UPDWINPOS_1	 0x3112c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPDWINSZ_1	0x31130 /* UPP 1 Destination Size */ 
	#define BITFIELD_VDC_UPDWINSZ_1	 0x31130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSWIDTH_1	0x31134 /* UPP 1 Source Width */ 
	#define BITFIELD_VDC_UPSWIDTH_1	 0x31134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSHEIGHT_1	0x3113c /* UPP 1 Source Height */ 
	#define BITFIELD_VDC_UPSHEIGHT_1	 0x3113c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_Y_1	0x31140 /* UPP 1 L/C Keying Y/G */ 
	#define BITFIELD_VDC_UPLCKEY_Y_1	 0x31140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CB_1	0x31144 /* UPP 1 L/C Keying Cb/B */ 
	#define BITFIELD_VDC_UPLCKEY_CB_1	 0x31144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CR_1	0x31148 /* UPP 1 L/C Keying Cr/R */ 
	#define BITFIELD_VDC_UPLCKEY_CR_1	 0x31148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCPC_1	0x31200 /* UPP 1 CSC Clamp */ 
	#define BITFIELD_VDC_UPCSCPC_1	 0x31200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCYGOFF_1	0x31204 /* UPP 1 CSC Y/G Offset */ 
	#define BITFIELD_VDC_UPCSCYGOFF_1	 0x31204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCBOFF_1	0x31208 /* UPP 1 CSC Cb/B Offset */ 
	#define BITFIELD_VDC_UPCSCCBOFF_1	 0x31208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCROFF_1	0x3120c /* UPP 1 CSC Cr/R Offset */ 
	#define BITFIELD_VDC_UPCSCCROFF_1	 0x3120c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C01_1	0x31210 /* UPP 1 CSC Coefficient01 */ 
	#define BITFIELD_VDC_UPCSC_C01_1	 0x31210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C23_1	0x31214 /* UPP 1 CSC Coefficient23 */ 
	#define BITFIELD_VDC_UPCSC_C23_1	 0x31214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C45_1	0x31218 /* UPP 1 CSC Coefficient45 */ 
	#define BITFIELD_VDC_UPCSC_C45_1	 0x31218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C67_1	0x3121c /* UPP 1 CSC Coefficient67 */ 
	#define BITFIELD_VDC_UPCSC_C67_1	 0x3121c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C8_1	0x31220 /* UPP 1 CSC Coefficient8 */ 
	#define BITFIELD_VDC_UPCSC_C8_1	 0x31220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPVGAMLUT_1	0x31900 /* UPP 1 Gamma Correction */ 
	#define BITFIELD_VDC_UPVGAMLUT_1	 0x31900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DUPSTA_1	0x31008 /* UPP 1 Status */ 
	#define BITFIELD_VDC_DUPSTA_1	 0x31008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFDROP_1	0x31170 /* UPP 1 Frame Drop Counter */ 
	#define BITFIELD_VDC_UPFDROP_1	 0x31170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFREPEAT_1	0x31174 /* UPP 1 Frame Repeat Counter */ 
	#define BITFIELD_VDC_UPFREPEAT_1	 0x31174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCONFIG_2	0x32164 /* UPP 2 Configuration */ 
	#define BITFIELD_VDC_UPCONFIG_2	 0x32164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCONFIG_2 */
	#define BLSB_VDC_UPCONFIG_2_reserved_31_18	18
	#define BLSB_VDC_UPCONFIG_2_Chroma_Key_Enab	17
	#define BLSB_VDC_UPCONFIG_2_GAMMA_BYPASS	16
	#define BLSB_VDC_UPCONFIG_2_reserved_15_7	7
	#define BLSB_VDC_UPCONFIG_2_CBCR_ISGN	6
	#define BLSB_VDC_UPCONFIG_2_CSC_EN	5
	#define BLSB_VDC_UPCONFIG_2_reserved_4_0	0
	/* Register Bit Widths for VDC_UPCONFIG_2 */
	#define BWID_VDC_UPCONFIG_2_reserved_31_18	14
	#define BWID_VDC_UPCONFIG_2_Chroma_Key_Enab	1
	#define BWID_VDC_UPCONFIG_2_GAMMA_BYPASS	1
	#define BWID_VDC_UPCONFIG_2_reserved_15_7	9
	#define BWID_VDC_UPCONFIG_2_CBCR_ISGN	1
	#define BWID_VDC_UPCONFIG_2_CSC_EN	1
	#define BWID_VDC_UPCONFIG_2_reserved_4_0	1
	/* Register Bit MASKS for VDC_UPCONFIG_2 */
	#define BMSK_VDC_UPCONFIG_2_reserved_31_18	0xfffc0000 /*  */
	#define BMSK_VDC_UPCONFIG_2_Chroma_Key_Enab	(1<<17) /* == 0x00020000:  */
	#define BMSK_VDC_UPCONFIG_2_GAMMA_BYPASS	(1<<16) /* == 0x00010000:  */
	#define BMSK_VDC_UPCONFIG_2_reserved_15_7	0x0000ff80 /*  */
	#define BMSK_VDC_UPCONFIG_2_CBCR_ISGN	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCONFIG_2_CSC_EN	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCONFIG_2_reserved_4_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCONFIG_2 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCONFIG_2_reserved_31_18	 0x32164, 18, 14, 0xfffc0000
	#define BITFIELD_VDC_UPCONFIG_2_Chroma_Key_Enab	 0x32164, 17, 1, 0x00020000
	#define BITFIELD_VDC_UPCONFIG_2_GAMMA_BYPASS	 0x32164, 16, 1, 0x00010000
	#define BITFIELD_VDC_UPCONFIG_2_reserved_15_7	 0x32164, 7, 9, 0x0000ff80
	#define BITFIELD_VDC_UPCONFIG_2_CBCR_ISGN	 0x32164, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCONFIG_2_CSC_EN	 0x32164, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCONFIG_2_reserved_4_0	 0x32164, 0, 1, 0x00000001
#define ROFF_VDC_UPCOMD_2	0x32168 /* UPP 2 Command */ 
	#define BITFIELD_VDC_UPCOMD_2	 0x32168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCOMD_2 */
	#define BLSB_VDC_UPCOMD_2_SCALING_EN	31
	#define BLSB_VDC_UPCOMD_2_reserved_30_28	28
	#define BLSB_VDC_UPCOMD_2_CLKEN	27
	#define BLSB_VDC_UPCOMD_2_MSB_SHDW_EN	26
	#define BLSB_VDC_UPCOMD_2_LINE_DOUBLE	25
	#define BLSB_VDC_UPCOMD_2_PXL_DOUBLE	24
	#define BLSB_VDC_UPCOMD_2_CONST_ALPHA	16
	#define BLSB_VDC_UPCOMD_2_reserved_15	15
	#define BLSB_VDC_UPCOMD_2_VIDEO_FORMAT	10
	#define BLSB_VDC_UPCOMD_2_SYNCFETCH_PARITY	9
	#define BLSB_VDC_UPCOMD_2_FLIP_INV_FIELD	8
	#define BLSB_VDC_UPCOMD_2_SYNCFETCH_ENBL	7
	#define BLSB_VDC_UPCOMD_2_IGNORE_FLIP_MODE	6
	#define BLSB_VDC_UPCOMD_2_reserved_5	5
	#define BLSB_VDC_UPCOMD_2_REQ_LEN_256	4
	#define BLSB_VDC_UPCOMD_2_TG_SEL	3
	#define BLSB_VDC_UPCOMD_2_LGCY_IMODE_EN	2
	#define BLSB_VDC_UPCOMD_2_ACT_F	1
	#define BLSB_VDC_UPCOMD_2_UP_ENBL	0
	/* Register Bit Widths for VDC_UPCOMD_2 */
	#define BWID_VDC_UPCOMD_2_SCALING_EN	1
	#define BWID_VDC_UPCOMD_2_reserved_30_28	3
	#define BWID_VDC_UPCOMD_2_CLKEN	1
	#define BWID_VDC_UPCOMD_2_MSB_SHDW_EN	1
	#define BWID_VDC_UPCOMD_2_LINE_DOUBLE	1
	#define BWID_VDC_UPCOMD_2_PXL_DOUBLE	1
	#define BWID_VDC_UPCOMD_2_CONST_ALPHA	8
	#define BWID_VDC_UPCOMD_2_reserved_15	1
	#define BWID_VDC_UPCOMD_2_VIDEO_FORMAT	5
	#define BWID_VDC_UPCOMD_2_SYNCFETCH_PARITY	1
	#define BWID_VDC_UPCOMD_2_FLIP_INV_FIELD	1
	#define BWID_VDC_UPCOMD_2_SYNCFETCH_ENBL	1
	#define BWID_VDC_UPCOMD_2_IGNORE_FLIP_MODE	1
	#define BWID_VDC_UPCOMD_2_reserved_5	1
	#define BWID_VDC_UPCOMD_2_REQ_LEN_256	1
	#define BWID_VDC_UPCOMD_2_TG_SEL	1
	#define BWID_VDC_UPCOMD_2_LGCY_IMODE_EN	1
	#define BWID_VDC_UPCOMD_2_ACT_F	1
	#define BWID_VDC_UPCOMD_2_UP_ENBL	1
	/* Register Bit MASKS for VDC_UPCOMD_2 */
	#define BMSK_VDC_UPCOMD_2_SCALING_EN	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UPCOMD_2_reserved_30_28	0x70000000 /*  */
	#define BMSK_VDC_UPCOMD_2_CLKEN	(1<<27) /* == 0x08000000:  */
	#define BMSK_VDC_UPCOMD_2_MSB_SHDW_EN	(1<<26) /* == 0x04000000:  */
	#define BMSK_VDC_UPCOMD_2_LINE_DOUBLE	(1<<25) /* == 0x02000000:  */
	#define BMSK_VDC_UPCOMD_2_PXL_DOUBLE	(1<<24) /* == 0x01000000:  */
	#define BMSK_VDC_UPCOMD_2_CONST_ALPHA	0x00ff0000 /*  */
	#define BMSK_VDC_UPCOMD_2_reserved_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UPCOMD_2_VIDEO_FORMAT	0x00007c00 /*  */
	#define BMSK_VDC_UPCOMD_2_SYNCFETCH_PARITY	(1<<9) /* == 0x00000200:  */
	#define BMSK_VDC_UPCOMD_2_FLIP_INV_FIELD	(1<<8) /* == 0x00000100:  */
	#define BMSK_VDC_UPCOMD_2_SYNCFETCH_ENBL	(1<<7) /* == 0x00000080:  */
	#define BMSK_VDC_UPCOMD_2_IGNORE_FLIP_MODE	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCOMD_2_reserved_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCOMD_2_REQ_LEN_256	(1<<4) /* == 0x00000010:  */
	#define BMSK_VDC_UPCOMD_2_TG_SEL	(1<<3) /* == 0x00000008:  */
	#define BMSK_VDC_UPCOMD_2_LGCY_IMODE_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_VDC_UPCOMD_2_ACT_F	(1<<1) /* == 0x00000002:  */
	#define BMSK_VDC_UPCOMD_2_UP_ENBL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCOMD_2 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCOMD_2_SCALING_EN	 0x32168, 31, 1, 0x80000000
	#define BITFIELD_VDC_UPCOMD_2_reserved_30_28	 0x32168, 28, 3, 0x70000000
	#define BITFIELD_VDC_UPCOMD_2_CLKEN	 0x32168, 27, 1, 0x08000000
	#define BITFIELD_VDC_UPCOMD_2_MSB_SHDW_EN	 0x32168, 26, 1, 0x04000000
	#define BITFIELD_VDC_UPCOMD_2_LINE_DOUBLE	 0x32168, 25, 1, 0x02000000
	#define BITFIELD_VDC_UPCOMD_2_PXL_DOUBLE	 0x32168, 24, 1, 0x01000000
	#define BITFIELD_VDC_UPCOMD_2_CONST_ALPHA	 0x32168, 16, 8, 0x00ff0000
	#define BITFIELD_VDC_UPCOMD_2_reserved_15	 0x32168, 15, 1, 0x00008000
	#define BITFIELD_VDC_UPCOMD_2_VIDEO_FORMAT	 0x32168, 10, 5, 0x00007c00
	#define BITFIELD_VDC_UPCOMD_2_SYNCFETCH_PARITY	 0x32168, 9, 1, 0x00000200
	#define BITFIELD_VDC_UPCOMD_2_FLIP_INV_FIELD	 0x32168, 8, 1, 0x00000100
	#define BITFIELD_VDC_UPCOMD_2_SYNCFETCH_ENBL	 0x32168, 7, 1, 0x00000080
	#define BITFIELD_VDC_UPCOMD_2_IGNORE_FLIP_MODE	 0x32168, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCOMD_2_reserved_5	 0x32168, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCOMD_2_REQ_LEN_256	 0x32168, 4, 1, 0x00000010
	#define BITFIELD_VDC_UPCOMD_2_TG_SEL	 0x32168, 3, 1, 0x00000008
	#define BITFIELD_VDC_UPCOMD_2_LGCY_IMODE_EN	 0x32168, 2, 1, 0x00000004
	#define BITFIELD_VDC_UPCOMD_2_ACT_F	 0x32168, 1, 1, 0x00000002
	#define BITFIELD_VDC_UPCOMD_2_UP_ENBL	 0x32168, 0, 1, 0x00000001
#define ROFF_VDC_UPFLIPMODE_2	0x3216c /* UPP 2 Flip Mode */ 
	#define BITFIELD_VDC_UPFLIPMODE_2	 0x3216c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFLIPDIS_2	0x3200c /* UPP 2 Flip Disable */ 
	#define BITFIELD_VDC_UPFLIPDIS_2	 0x3200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBLCONFIG_2	0x32178 /* UPP 2 Blender Config */ 
	#define BITFIELD_VDC_UPBLCONFIG_2	 0x32178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F0_2	0x32100 /* UPP 2 Y/RGB field 0 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F0_2	 0x32100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F1_2	0x32104 /* UPP 2 Y/RGB field 1 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F1_2	 0x32104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F0_2	0x32108 /* UPP 2 CbCr  field 0 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F0_2	 0x32108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F1_2	0x3210c /* UPP 2 CbCr  field 1 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F1_2	 0x3210c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_POFF_2	0x32064 /* UPP 2 Pixel Offset */ 
	#define BITFIELD_VDC_UPBUF_POFF_2	 0x32064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPBUF_POFF_2 */
	#define BLSB_VDC_UPBUF_POFF_2_reserved_31_27	27
	#define BLSB_VDC_UPBUF_POFF_2_CbCr_OFF	16
	#define BLSB_VDC_UPBUF_POFF_2_reserved_15_11	11
	#define BLSB_VDC_UPBUF_POFF_2_YRGB_OFF	0
	/* Register Bit Widths for VDC_UPBUF_POFF_2 */
	#define BWID_VDC_UPBUF_POFF_2_reserved_31_27	5
	#define BWID_VDC_UPBUF_POFF_2_CbCr_OFF	10
	#define BWID_VDC_UPBUF_POFF_2_reserved_15_11	5
	#define BWID_VDC_UPBUF_POFF_2_YRGB_OFF	10
	/* Register Bit MASKS for VDC_UPBUF_POFF_2 */
	#define BMSK_VDC_UPBUF_POFF_2_reserved_31_27	0xf8000000 /*  */
	#define BMSK_VDC_UPBUF_POFF_2_CbCr_OFF	0x03ff0000 /*  */
	#define BMSK_VDC_UPBUF_POFF_2_reserved_15_11	0x0000f800 /*  */
	#define BMSK_VDC_UPBUF_POFF_2_YRGB_OFF	0x000003ff /*  */
	/* Register BITFIELD for VDC_UPBUF_POFF_2 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPBUF_POFF_2_reserved_31_27	 0x32064, 27, 5, 0xf8000000
	#define BITFIELD_VDC_UPBUF_POFF_2_CbCr_OFF	 0x32064, 16, 10, 0x03ff0000
	#define BITFIELD_VDC_UPBUF_POFF_2_reserved_15_11	 0x32064, 11, 5, 0x0000f800
	#define BITFIELD_VDC_UPBUF_POFF_2_YRGB_OFF	 0x32064, 0, 10, 0x000003ff
#define ROFF_VDC_UP_STRIDE_2	0x32118 /* UPP 2 Video Stride */ 
	#define BITFIELD_VDC_UP_STRIDE_2	 0x32118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UP_STRIDE_2 */
	#define BLSB_VDC_UP_STRIDE_2_reserved_31	31
	#define BLSB_VDC_UP_STRIDE_2_CbCr_STRIDE	16
	#define BLSB_VDC_UP_STRIDE_2_IPHASE	15
	#define BLSB_VDC_UP_STRIDE_2_YRGB_STRIDE	0
	/* Register Bit Widths for VDC_UP_STRIDE_2 */
	#define BWID_VDC_UP_STRIDE_2_reserved_31	1
	#define BWID_VDC_UP_STRIDE_2_CbCr_STRIDE	15
	#define BWID_VDC_UP_STRIDE_2_IPHASE	1
	#define BWID_VDC_UP_STRIDE_2_YRGB_STRIDE	15
	/* Register Bit MASKS for VDC_UP_STRIDE_2 */
	#define BMSK_VDC_UP_STRIDE_2_reserved_31	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UP_STRIDE_2_CbCr_STRIDE	0x7fff0000 /*  */
	#define BMSK_VDC_UP_STRIDE_2_IPHASE	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UP_STRIDE_2_YRGB_STRIDE	0x00007fff /*  */
	/* Register BITFIELD for VDC_UP_STRIDE_2 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UP_STRIDE_2_reserved_31	 0x32118, 31, 1, 0x80000000
	#define BITFIELD_VDC_UP_STRIDE_2_CbCr_STRIDE	 0x32118, 16, 15, 0x7fff0000
	#define BITFIELD_VDC_UP_STRIDE_2_IPHASE	 0x32118, 15, 1, 0x00008000
	#define BITFIELD_VDC_UP_STRIDE_2_YRGB_STRIDE	 0x32118, 0, 15, 0x00007fff
#define ROFF_VDC_UPDWINPOS_2	0x3212c /* UPP 2 Destination Position */ 
	#define BITFIELD_VDC_UPDWINPOS_2	 0x3212c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPDWINSZ_2	0x32130 /* UPP 2 Destination Size */ 
	#define BITFIELD_VDC_UPDWINSZ_2	 0x32130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSWIDTH_2	0x32134 /* UPP 2 Source Width */ 
	#define BITFIELD_VDC_UPSWIDTH_2	 0x32134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSHEIGHT_2	0x3213c /* UPP 2 Source Height */ 
	#define BITFIELD_VDC_UPSHEIGHT_2	 0x3213c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_Y_2	0x32140 /* UPP 2 L/C Keying Y/G */ 
	#define BITFIELD_VDC_UPLCKEY_Y_2	 0x32140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CB_2	0x32144 /* UPP 2 L/C Keying Cb/B */ 
	#define BITFIELD_VDC_UPLCKEY_CB_2	 0x32144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CR_2	0x32148 /* UPP 2 L/C Keying Cr/R */ 
	#define BITFIELD_VDC_UPLCKEY_CR_2	 0x32148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCPC_2	0x32200 /* UPP 2 CSC Clamp */ 
	#define BITFIELD_VDC_UPCSCPC_2	 0x32200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCYGOFF_2	0x32204 /* UPP 2 CSC Y/G Offset */ 
	#define BITFIELD_VDC_UPCSCYGOFF_2	 0x32204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCBOFF_2	0x32208 /* UPP 2 CSC Cb/B Offset */ 
	#define BITFIELD_VDC_UPCSCCBOFF_2	 0x32208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCROFF_2	0x3220c /* UPP 2 CSC Cr/R Offset */ 
	#define BITFIELD_VDC_UPCSCCROFF_2	 0x3220c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C10_2	0x32210 /* UPP 2 CSC Coefficient01 */ 
	#define BITFIELD_VDC_UPCSC_C10_2	 0x32210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C23_2	0x32214 /* UPP 2 CSC Coefficient23 */ 
	#define BITFIELD_VDC_UPCSC_C23_2	 0x32214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C45_2	0x32218 /* UPP 2 CSC Coefficient45 */ 
	#define BITFIELD_VDC_UPCSC_C45_2	 0x32218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C67_2	0x3221c /* UPP 2 CSC Coefficient67 */ 
	#define BITFIELD_VDC_UPCSC_C67_2	 0x3221c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C8_2	0x32220 /* UPP 2 CSC Coefficient8 */ 
	#define BITFIELD_VDC_UPCSC_C8_2	 0x32220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPVGAMLUT_2	0x32900 /* UPP 2 Gamma Correction */ 
	#define BITFIELD_VDC_UPVGAMLUT_2	 0x32900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DUPVSTA_2	0x32008 /* UPP 2 Status */ 
	#define BITFIELD_VDC_DUPVSTA_2	 0x32008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFDROP_2	0x32170 /* UPP 2 Frame Drop Counter */ 
	#define BITFIELD_VDC_UPFDROP_2	 0x32170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFREPEAT_2	0x32174 /* UPP 2 Frame Repeat Counter */ 
	#define BITFIELD_VDC_UPFREPEAT_2	 0x32174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCONFIG_3	0x33164 /* UPP 3 Configuration */ 
	#define BITFIELD_VDC_UPCONFIG_3	 0x33164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCONFIG_3 */
	#define BLSB_VDC_UPCONFIG_3_reserved_31_18	18
	#define BLSB_VDC_UPCONFIG_3_Chroma_Key_Enab	17
	#define BLSB_VDC_UPCONFIG_3_GAMMA_BYPASS	16
	#define BLSB_VDC_UPCONFIG_3_reserved_15_7	7
	#define BLSB_VDC_UPCONFIG_3_CBCR_ISGN	6
	#define BLSB_VDC_UPCONFIG_3_CSC_EN	5
	#define BLSB_VDC_UPCONFIG_3_reserved_4_0	0
	/* Register Bit Widths for VDC_UPCONFIG_3 */
	#define BWID_VDC_UPCONFIG_3_reserved_31_18	14
	#define BWID_VDC_UPCONFIG_3_Chroma_Key_Enab	1
	#define BWID_VDC_UPCONFIG_3_GAMMA_BYPASS	1
	#define BWID_VDC_UPCONFIG_3_reserved_15_7	9
	#define BWID_VDC_UPCONFIG_3_CBCR_ISGN	1
	#define BWID_VDC_UPCONFIG_3_CSC_EN	1
	#define BWID_VDC_UPCONFIG_3_reserved_4_0	1
	/* Register Bit MASKS for VDC_UPCONFIG_3 */
	#define BMSK_VDC_UPCONFIG_3_reserved_31_18	0xfffc0000 /*  */
	#define BMSK_VDC_UPCONFIG_3_Chroma_Key_Enab	(1<<17) /* == 0x00020000:  */
	#define BMSK_VDC_UPCONFIG_3_GAMMA_BYPASS	(1<<16) /* == 0x00010000:  */
	#define BMSK_VDC_UPCONFIG_3_reserved_15_7	0x0000ff80 /*  */
	#define BMSK_VDC_UPCONFIG_3_CBCR_ISGN	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCONFIG_3_CSC_EN	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCONFIG_3_reserved_4_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCONFIG_3 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCONFIG_3_reserved_31_18	 0x33164, 18, 14, 0xfffc0000
	#define BITFIELD_VDC_UPCONFIG_3_Chroma_Key_Enab	 0x33164, 17, 1, 0x00020000
	#define BITFIELD_VDC_UPCONFIG_3_GAMMA_BYPASS	 0x33164, 16, 1, 0x00010000
	#define BITFIELD_VDC_UPCONFIG_3_reserved_15_7	 0x33164, 7, 9, 0x0000ff80
	#define BITFIELD_VDC_UPCONFIG_3_CBCR_ISGN	 0x33164, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCONFIG_3_CSC_EN	 0x33164, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCONFIG_3_reserved_4_0	 0x33164, 0, 1, 0x00000001
#define ROFF_VDC_UPCOMD_3	0x33168 /* UPP 3 Command */ 
	#define BITFIELD_VDC_UPCOMD_3	 0x33168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPCOMD_3 */
	#define BLSB_VDC_UPCOMD_3_SCALING_EN	31
	#define BLSB_VDC_UPCOMD_3_reserved_30_28	28
	#define BLSB_VDC_UPCOMD_3_CLKEN	27
	#define BLSB_VDC_UPCOMD_3_MSB_SHDW_EN	26
	#define BLSB_VDC_UPCOMD_3_LINE_DOUBLE	25
	#define BLSB_VDC_UPCOMD_3_PXL_DOUBLE	24
	#define BLSB_VDC_UPCOMD_3_CONST_ALPHA	16
	#define BLSB_VDC_UPCOMD_3_reserved_15	15
	#define BLSB_VDC_UPCOMD_3_VIDEO_FORMAT	10
	#define BLSB_VDC_UPCOMD_3_SYNCFETCH_PARITY	9
	#define BLSB_VDC_UPCOMD_3_FLIP_INV_FIELD	8
	#define BLSB_VDC_UPCOMD_3_SYNCFETCH_ENBL	7
	#define BLSB_VDC_UPCOMD_3_IGNORE_FLIP_MODE	6
	#define BLSB_VDC_UPCOMD_3_reserved_5	5
	#define BLSB_VDC_UPCOMD_3_REQ_LEN_256	4
	#define BLSB_VDC_UPCOMD_3_TG_SEL	3
	#define BLSB_VDC_UPCOMD_3_LGCY_IMODE_EN	2
	#define BLSB_VDC_UPCOMD_3_ACT_F	1
	#define BLSB_VDC_UPCOMD_3_UP_ENBL	0
	/* Register Bit Widths for VDC_UPCOMD_3 */
	#define BWID_VDC_UPCOMD_3_SCALING_EN	1
	#define BWID_VDC_UPCOMD_3_reserved_30_28	3
	#define BWID_VDC_UPCOMD_3_CLKEN	1
	#define BWID_VDC_UPCOMD_3_MSB_SHDW_EN	1
	#define BWID_VDC_UPCOMD_3_LINE_DOUBLE	1
	#define BWID_VDC_UPCOMD_3_PXL_DOUBLE	1
	#define BWID_VDC_UPCOMD_3_CONST_ALPHA	8
	#define BWID_VDC_UPCOMD_3_reserved_15	1
	#define BWID_VDC_UPCOMD_3_VIDEO_FORMAT	5
	#define BWID_VDC_UPCOMD_3_SYNCFETCH_PARITY	1
	#define BWID_VDC_UPCOMD_3_FLIP_INV_FIELD	1
	#define BWID_VDC_UPCOMD_3_SYNCFETCH_ENBL	1
	#define BWID_VDC_UPCOMD_3_IGNORE_FLIP_MODE	1
	#define BWID_VDC_UPCOMD_3_reserved_5	1
	#define BWID_VDC_UPCOMD_3_REQ_LEN_256	1
	#define BWID_VDC_UPCOMD_3_TG_SEL	1
	#define BWID_VDC_UPCOMD_3_LGCY_IMODE_EN	1
	#define BWID_VDC_UPCOMD_3_ACT_F	1
	#define BWID_VDC_UPCOMD_3_UP_ENBL	1
	/* Register Bit MASKS for VDC_UPCOMD_3 */
	#define BMSK_VDC_UPCOMD_3_SCALING_EN	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UPCOMD_3_reserved_30_28	0x70000000 /*  */
	#define BMSK_VDC_UPCOMD_3_CLKEN	(1<<27) /* == 0x08000000:  */
	#define BMSK_VDC_UPCOMD_3_MSB_SHDW_EN	(1<<26) /* == 0x04000000:  */
	#define BMSK_VDC_UPCOMD_3_LINE_DOUBLE	(1<<25) /* == 0x02000000:  */
	#define BMSK_VDC_UPCOMD_3_PXL_DOUBLE	(1<<24) /* == 0x01000000:  */
	#define BMSK_VDC_UPCOMD_3_CONST_ALPHA	0x00ff0000 /*  */
	#define BMSK_VDC_UPCOMD_3_reserved_15	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UPCOMD_3_VIDEO_FORMAT	0x00007c00 /*  */
	#define BMSK_VDC_UPCOMD_3_SYNCFETCH_PARITY	(1<<9) /* == 0x00000200:  */
	#define BMSK_VDC_UPCOMD_3_FLIP_INV_FIELD	(1<<8) /* == 0x00000100:  */
	#define BMSK_VDC_UPCOMD_3_SYNCFETCH_ENBL	(1<<7) /* == 0x00000080:  */
	#define BMSK_VDC_UPCOMD_3_IGNORE_FLIP_MODE	(1<<6) /* == 0x00000040:  */
	#define BMSK_VDC_UPCOMD_3_reserved_5	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_UPCOMD_3_REQ_LEN_256	(1<<4) /* == 0x00000010:  */
	#define BMSK_VDC_UPCOMD_3_TG_SEL	(1<<3) /* == 0x00000008:  */
	#define BMSK_VDC_UPCOMD_3_LGCY_IMODE_EN	(1<<2) /* == 0x00000004:  */
	#define BMSK_VDC_UPCOMD_3_ACT_F	(1<<1) /* == 0x00000002:  */
	#define BMSK_VDC_UPCOMD_3_UP_ENBL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_UPCOMD_3 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPCOMD_3_SCALING_EN	 0x33168, 31, 1, 0x80000000
	#define BITFIELD_VDC_UPCOMD_3_reserved_30_28	 0x33168, 28, 3, 0x70000000
	#define BITFIELD_VDC_UPCOMD_3_CLKEN	 0x33168, 27, 1, 0x08000000
	#define BITFIELD_VDC_UPCOMD_3_MSB_SHDW_EN	 0x33168, 26, 1, 0x04000000
	#define BITFIELD_VDC_UPCOMD_3_LINE_DOUBLE	 0x33168, 25, 1, 0x02000000
	#define BITFIELD_VDC_UPCOMD_3_PXL_DOUBLE	 0x33168, 24, 1, 0x01000000
	#define BITFIELD_VDC_UPCOMD_3_CONST_ALPHA	 0x33168, 16, 8, 0x00ff0000
	#define BITFIELD_VDC_UPCOMD_3_reserved_15	 0x33168, 15, 1, 0x00008000
	#define BITFIELD_VDC_UPCOMD_3_VIDEO_FORMAT	 0x33168, 10, 5, 0x00007c00
	#define BITFIELD_VDC_UPCOMD_3_SYNCFETCH_PARITY	 0x33168, 9, 1, 0x00000200
	#define BITFIELD_VDC_UPCOMD_3_FLIP_INV_FIELD	 0x33168, 8, 1, 0x00000100
	#define BITFIELD_VDC_UPCOMD_3_SYNCFETCH_ENBL	 0x33168, 7, 1, 0x00000080
	#define BITFIELD_VDC_UPCOMD_3_IGNORE_FLIP_MODE	 0x33168, 6, 1, 0x00000040
	#define BITFIELD_VDC_UPCOMD_3_reserved_5	 0x33168, 5, 1, 0x00000020
	#define BITFIELD_VDC_UPCOMD_3_REQ_LEN_256	 0x33168, 4, 1, 0x00000010
	#define BITFIELD_VDC_UPCOMD_3_TG_SEL	 0x33168, 3, 1, 0x00000008
	#define BITFIELD_VDC_UPCOMD_3_LGCY_IMODE_EN	 0x33168, 2, 1, 0x00000004
	#define BITFIELD_VDC_UPCOMD_3_ACT_F	 0x33168, 1, 1, 0x00000002
	#define BITFIELD_VDC_UPCOMD_3_UP_ENBL	 0x33168, 0, 1, 0x00000001
#define ROFF_VDC_UPFLIPMODE_3	0x3316c /* UPP 3 Flip Mode */ 
	#define BITFIELD_VDC_UPFLIPMODE_3	 0x3316c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFLIPDIS_3	0x3300c /* UPP 3 Flip Disable */ 
	#define BITFIELD_VDC_UPFLIPDIS_3	 0x3300c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBLCONFIG_3	0x33178 /* UPP 3 Blender Config */ 
	#define BITFIELD_VDC_UPBLCONFIG_3	 0x33178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F0_3	0x33100 /* UPP 3 Y/RGB field 0 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F0_3	 0x33100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_YRGB_F1_3	0x33104 /* UPP 3 Y/RGB field 1 */ 
	#define BITFIELD_VDC_UPBUF_YRGB_F1_3	 0x33104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F0_3	0x33108 /* UPP 3 CbCr  field 0 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F0_3	 0x33108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_CBCR_F1_3	0x3310c /* UPP 3 CbCr  field 1 */ 
	#define BITFIELD_VDC_UPBUF_CBCR_F1_3	 0x3310c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPBUF_POFF_3	0x33064 /* UPP 3 Pixel Offset */ 
	#define BITFIELD_VDC_UPBUF_POFF_3	 0x33064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UPBUF_POFF_3 */
	#define BLSB_VDC_UPBUF_POFF_3_reserved_31_27	27
	#define BLSB_VDC_UPBUF_POFF_3_CbCr_OFF	16
	#define BLSB_VDC_UPBUF_POFF_3_reserved_15_11	11
	#define BLSB_VDC_UPBUF_POFF_3_YRGB_OFF	0
	/* Register Bit Widths for VDC_UPBUF_POFF_3 */
	#define BWID_VDC_UPBUF_POFF_3_reserved_31_27	5
	#define BWID_VDC_UPBUF_POFF_3_CbCr_OFF	10
	#define BWID_VDC_UPBUF_POFF_3_reserved_15_11	5
	#define BWID_VDC_UPBUF_POFF_3_YRGB_OFF	10
	/* Register Bit MASKS for VDC_UPBUF_POFF_3 */
	#define BMSK_VDC_UPBUF_POFF_3_reserved_31_27	0xf8000000 /*  */
	#define BMSK_VDC_UPBUF_POFF_3_CbCr_OFF	0x03ff0000 /*  */
	#define BMSK_VDC_UPBUF_POFF_3_reserved_15_11	0x0000f800 /*  */
	#define BMSK_VDC_UPBUF_POFF_3_YRGB_OFF	0x000003ff /*  */
	/* Register BITFIELD for VDC_UPBUF_POFF_3 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UPBUF_POFF_3_reserved_31_27	 0x33064, 27, 5, 0xf8000000
	#define BITFIELD_VDC_UPBUF_POFF_3_CbCr_OFF	 0x33064, 16, 10, 0x03ff0000
	#define BITFIELD_VDC_UPBUF_POFF_3_reserved_15_11	 0x33064, 11, 5, 0x0000f800
	#define BITFIELD_VDC_UPBUF_POFF_3_YRGB_OFF	 0x33064, 0, 10, 0x000003ff
#define ROFF_VDC_UP_STRIDE_3	0x33118 /* UPP 3 Video Stride */ 
	#define BITFIELD_VDC_UP_STRIDE_3	 0x33118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_UP_STRIDE_3 */
	#define BLSB_VDC_UP_STRIDE_3_reserved_31	31
	#define BLSB_VDC_UP_STRIDE_3_CbCr_STRIDE	16
	#define BLSB_VDC_UP_STRIDE_3_IPHASE	15
	#define BLSB_VDC_UP_STRIDE_3_YRGB_STRIDE	0
	/* Register Bit Widths for VDC_UP_STRIDE_3 */
	#define BWID_VDC_UP_STRIDE_3_reserved_31	1
	#define BWID_VDC_UP_STRIDE_3_CbCr_STRIDE	15
	#define BWID_VDC_UP_STRIDE_3_IPHASE	1
	#define BWID_VDC_UP_STRIDE_3_YRGB_STRIDE	15
	/* Register Bit MASKS for VDC_UP_STRIDE_3 */
	#define BMSK_VDC_UP_STRIDE_3_reserved_31	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_UP_STRIDE_3_CbCr_STRIDE	0x7fff0000 /*  */
	#define BMSK_VDC_UP_STRIDE_3_IPHASE	(1<<15) /* == 0x00008000:  */
	#define BMSK_VDC_UP_STRIDE_3_YRGB_STRIDE	0x00007fff /*  */
	/* Register BITFIELD for VDC_UP_STRIDE_3 - roff, lsb, width, mask */
	#define BITFIELD_VDC_UP_STRIDE_3_reserved_31	 0x33118, 31, 1, 0x80000000
	#define BITFIELD_VDC_UP_STRIDE_3_CbCr_STRIDE	 0x33118, 16, 15, 0x7fff0000
	#define BITFIELD_VDC_UP_STRIDE_3_IPHASE	 0x33118, 15, 1, 0x00008000
	#define BITFIELD_VDC_UP_STRIDE_3_YRGB_STRIDE	 0x33118, 0, 15, 0x00007fff
#define ROFF_VDC_UPDWINPOS_3	0x3312c /* UPP 3 Destination Position */ 
	#define BITFIELD_VDC_UPDWINPOS_3	 0x3312c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPDWINSZ_3	0x33130 /* UPP 3 Destination Size */ 
	#define BITFIELD_VDC_UPDWINSZ_3	 0x33130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSWIDTH_3	0x33134 /* UPP 3 Source Width */ 
	#define BITFIELD_VDC_UPSWIDTH_3	 0x33134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPSHEIGHT_3	0x3313c /* UPP 3 Source Height */ 
	#define BITFIELD_VDC_UPSHEIGHT_3	 0x3313c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_Y_3	0x33140 /* UPP 3 L/C Keying Y/G */ 
	#define BITFIELD_VDC_UPLCKEY_Y_3	 0x33140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CB_3	0x33144 /* UPP 3 L/C Keying Cb/B */ 
	#define BITFIELD_VDC_UPLCKEY_CB_3	 0x33144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPLCKEY_CR_3	0x33148 /* UPP 3 L/C Keying Cr/R */ 
	#define BITFIELD_VDC_UPLCKEY_CR_3	 0x33148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCPC_3	0x33200 /* UPP 3 CSC Clamp */ 
	#define BITFIELD_VDC_UPCSCPC_3	 0x33200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCYGOFF_3	0x33204 /* UPP 3 CSC Y/G Offset */ 
	#define BITFIELD_VDC_UPCSCYGOFF_3	 0x33204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCBOFF_3	0x33208 /* UPP 3 CSC Cb/B Offset */ 
	#define BITFIELD_VDC_UPCSCCBOFF_3	 0x33208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSCCROFF_3	0x3320c /* UPP 3 CSC Cr/R Offset */ 
	#define BITFIELD_VDC_UPCSCCROFF_3	 0x3320c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C01_3	0x33210 /* UPP 3 CSC Coefficient01 */ 
	#define BITFIELD_VDC_UPCSC_C01_3	 0x33210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C23_3	0x33214 /* UPP 3 CSC Coefficient23 */ 
	#define BITFIELD_VDC_UPCSC_C23_3	 0x33214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C45_3	0x33218 /* UPP 3 CSC Coefficient45 */ 
	#define BITFIELD_VDC_UPCSC_C45_3	 0x33218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C67_3	0x3321c /* UPP 3 CSC Coefficient67 */ 
	#define BITFIELD_VDC_UPCSC_C67_3	 0x3321c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPCSC_C8_3	0x33220 /* UPP 3 CSC Coefficient8 */ 
	#define BITFIELD_VDC_UPCSC_C8_3	 0x33220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPVGAMLUT_3	0x33900 /* UPP 3 Gamma Correction */ 
	#define BITFIELD_VDC_UPVGAMLUT_3	 0x33900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DUPSTA_3	0x33008 /* UPP 3 Status */ 
	#define BITFIELD_VDC_DUPSTA_3	 0x33008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFDROP_3	0x33170 /* UPP 3 Frame Drop Counter */ 
	#define BITFIELD_VDC_UPFDROP_3	 0x33170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_UPFREPEAT_3	0x33174 /* UPP 3 Frame Repeat Counter */ 
	#define BITFIELD_VDC_UPFREPEAT_3	 0x33174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPCOMD_0	0x10168 /* IAP 0 Command */ 
	#define BITFIELD_VDC_IAPCOMD_0	 0x10168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFLIPMODE_0	0x1016c /* IAP 0  */ 
	#define BITFIELD_VDC_IAPFLIPMODE_0	 0x1016c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFLIPDIS_0	0x1000c /* IAP 0  */ 
	#define BITFIELD_VDC_IAPFLIPDIS_0	 0x1000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBLCONFIG_0	0x10178 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPBLCONFIG_0	 0x10178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBUF_F0_0	0x10100 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPBUF_F0_0	 0x10100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBUF_F1_0	0x10104 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPBUF_F1_0	 0x10104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBUF_POFF_0	0x10064 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPBUF_POFF_0	 0x10064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAP_STRIDE_0	0x10118 /* IAP 0  */ 
	#define BITFIELD_VDC_IAP_STRIDE_0	 0x10118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPDWINPOS_0	0x1012c /* IAP 0  */ 
	#define BITFIELD_VDC_IAPDWINPOS_0	 0x1012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPDWINSZ_0	0x10130 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPDWINSZ_0	 0x10130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPSWIDTH_0	0x10134 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPSWIDTH_0	 0x10134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPSHEIGHT_0	0x1013c /* IAP 0  */ 
	#define BITFIELD_VDC_IAPSHEIGHT_0	 0x1013c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPCLUT_0	0x10400 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPCLUT_0	 0x10400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DIAPVSTA_0	0x10008 /* IAP 0  */ 
	#define BITFIELD_VDC_DIAPVSTA_0	 0x10008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFDROP_0	0x10170 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPFDROP_0	 0x10170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFREPEAT_0	0x10174 /* IAP 0  */ 
	#define BITFIELD_VDC_IAPFREPEAT_0	 0x10174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPCOMD_1	0x11168 /* IAP 1 Command */ 
	#define BITFIELD_VDC_IAPCOMD_1	 0x11168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFLIPMODE_1	0x1116c /* IAP 1  */ 
	#define BITFIELD_VDC_IAPFLIPMODE_1	 0x1116c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFLIPDIS_1	0x1100c /* IAP 1  */ 
	#define BITFIELD_VDC_IAPFLIPDIS_1	 0x1100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBLCONFIG_1	0x11178 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPBLCONFIG_1	 0x11178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBUF_F0_1	0x11100 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPBUF_F0_1	 0x11100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBUF_F1_1	0x11104 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPBUF_F1_1	 0x11104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPBUF_POFF_1	0x11064 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPBUF_POFF_1	 0x11064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAP_STRIDE_1	0x11118 /* IAP 1  */ 
	#define BITFIELD_VDC_IAP_STRIDE_1	 0x11118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPDWINPOS_1	0x1112c /* IAP 1  */ 
	#define BITFIELD_VDC_IAPDWINPOS_1	 0x1112c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPDWINSZ_1	0x11130 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPDWINSZ_1	 0x11130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPSWIDTH_1	0x11134 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPSWIDTH_1	 0x11134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPSHEIGHT_1	0x1113c /* IAP 1  */ 
	#define BITFIELD_VDC_IAPSHEIGHT_1	 0x1113c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPCLUT_1	0x11400 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPCLUT_1	 0x11400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DIAPVSTA_1	0x11008 /* IAP 1  */ 
	#define BITFIELD_VDC_DIAPVSTA_1	 0x11008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFDROP_1	0x11170 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPFDROP_1	 0x11170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IAPFREPEAT_1	0x11174 /* IAP 1  */ 
	#define BITFIELD_VDC_IAPFREPEAT_1	 0x11174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPCONFIG	0x40000 /* WrBkPl Config */ 
	#define BITFIELD_VDC_WBPCONFIG	 0x40000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPBUF_Y_F0	0x40100 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPBUF_Y_F0	 0x40100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPBUF_CBCR_F0	0x40108 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPBUF_CBCR_F0	 0x40108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPBUF_CBCR_F1	0x4010c /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPBUF_CBCR_F1	 0x4010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBP_STRIDE	0x40118 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBP_STRIDE	 0x40118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBP_PRNGSR	0x40120 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBP_PRNGSR	 0x40120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_H	0x41000 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_H	 0x41000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_W	0x41004 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_W	 0x41004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_NBP	0x41024 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_NBP	 0x41024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_ISF	0x41044 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_ISF	 0x41044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_PC	0x41048 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_PC	 0x41048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_YPM	0x41200 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_YPM	 0x41200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_CPM	0x41300 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_CPM	 0x41300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPVS_H	0x42000 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPVS_H	 0x42000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPVS_W	0x42004 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPVS_W	 0x42004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPVS_ISF	0x42044 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPVS_ISF	 0x42044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPVS_PC	0x42048 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPVS_PC	 0x42048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPHS_PM	0x42200 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPHS_PM	 0x42200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WBPSTA	0x43000 /* WrBkPl  */ 
	#define BITFIELD_VDC_WBPSTA	 0x43000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_BLCFG_P0SEL	0x50000 /* Blender Pipe0 Select */ 
	#define BITFIELD_VDC_BLCFG_P0SEL	 0x50000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_BLCFG_P1SEL	0x50004 /* Blender Pipe1 Select */ 
	#define BITFIELD_VDC_BLCFG_P1SEL	 0x50004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CANVSCLR_0	0x50008 /* Canvas Color0 */ 
	#define BITFIELD_VDC_CANVSCLR_0	 0x50008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CANVSCLR_1	0x5000c /* Canvas Color1 */ 
	#define BITFIELD_VDC_CANVSCLR_1	 0x5000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PACONFIG	0x61140 /* Pipe A Output Config */ 
	#define BITFIELD_VDC_PACONFIG	 0x61140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_HTOTAL_A	0x60000 /* Pipe A Horiz Total */ 
	#define BITFIELD_VDC_HTOTAL_A	 0x60000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_HBLANK_A	0x60004 /* Pipe A Horiz Blank */ 
	#define BITFIELD_VDC_HBLANK_A	 0x60004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_HSYNC_A	0x60008 /* Pipe A Horiz Sync */ 
	#define BITFIELD_VDC_HSYNC_A	 0x60008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VTOTAL_A	0x6000c /* Pipe A Vert  Total */ 
	#define BITFIELD_VDC_VTOTAL_A	 0x6000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VBLANK_A	0x60010 /* Pipe A Vert  Blank */ 
	#define BITFIELD_VDC_VBLANK_A	 0x60010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VSYNC_A	0x60014 /* Pipe A Vert  Sync */ 
	#define BITFIELD_VDC_VSYNC_A	 0x60014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VSYNCSHIFT_A	0x60028 /* Pipe A Vert  Sync Shift */ 
	#define BITFIELD_VDC_VSYNCSHIFT_A	 0x60028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEASRC	0x6001c /* Pipe A Source Image Size */ 
	#define BITFIELD_VDC_PIPEASRC	 0x6001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_BCLRPAT_A	0x60020 /* Pipe A Border Color Pattern */ 
	#define BITFIELD_VDC_BCLRPAT_A	 0x60020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PAC_PRNGSR	0x60030 /* Pipe A component PRNG Shift */ 
	#define BITFIELD_VDC_PAC_PRNGSR	 0x60030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PAGAMLUT0	0x60900 /* Pipe A Gamma Correction 0 */ 
	#define BITFIELD_VDC_PAGAMLUT0	 0x60900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PAGAMLUT1	0x60904 /* Pipe A Gamma Correction 1... */ 
	#define BITFIELD_VDC_PAGAMLUT1	 0x60904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEACONF	0x70008 /* Pipe A Config */ 
	#define BITFIELD_VDC_PIPEACONF	 0x70008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_PIPEACONF */
	#define BLSB_VDC_PIPEACONF_Pipe_Enable	31
	#define BLSB_VDC_PIPEACONF_reserved_30_29	29
	#define BLSB_VDC_PIPEACONF_Frame_start_delay	27
	#define BLSB_VDC_PIPEACONF_reserved_26	26
	#define BLSB_VDC_PIPEACONF_Force_Border	25
	#define BLSB_VDC_PIPEACONF_reserved_24	24
	#define BLSB_VDC_PIPEACONF_Interlaced_mode	21
	#define BLSB_VDC_PIPEACONF_tg0_comp_en	20
	#define BLSB_VDC_PIPEACONF_Planes_off	19
	#define BLSB_VDC_PIPEACONF_reserved_18_2	2
	#define BLSB_VDC_PIPEACONF_Gamma_en	1
	#define BLSB_VDC_PIPEACONF_PAC_DITHER_ENABLE	0
	/* Register Bit Widths for VDC_PIPEACONF */
	#define BWID_VDC_PIPEACONF_Pipe_Enable	1
	#define BWID_VDC_PIPEACONF_reserved_30_29	2
	#define BWID_VDC_PIPEACONF_Frame_start_delay	2
	#define BWID_VDC_PIPEACONF_reserved_26	1
	#define BWID_VDC_PIPEACONF_Force_Border	1
	#define BWID_VDC_PIPEACONF_reserved_24	1
	#define BWID_VDC_PIPEACONF_Interlaced_mode	3
	#define BWID_VDC_PIPEACONF_tg0_comp_en	1
	#define BWID_VDC_PIPEACONF_Planes_off	1
	#define BWID_VDC_PIPEACONF_reserved_18_2	17
	#define BWID_VDC_PIPEACONF_Gamma_en	1
	#define BWID_VDC_PIPEACONF_PAC_DITHER_ENABLE	1
	/* Register Bit MASKS for VDC_PIPEACONF */
	#define BMSK_VDC_PIPEACONF_Pipe_Enable	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_PIPEACONF_reserved_30_29	0x60000000 /*  */
	#define BMSK_VDC_PIPEACONF_Frame_start_delay	0x18000000 /*  */
	#define BMSK_VDC_PIPEACONF_reserved_26	(1<<26) /* == 0x04000000:  */
	#define BMSK_VDC_PIPEACONF_Force_Border	(1<<25) /* == 0x02000000:  */
	#define BMSK_VDC_PIPEACONF_reserved_24	(1<<24) /* == 0x01000000:  */
	#define BMSK_VDC_PIPEACONF_Interlaced_mode	0x00e00000 /*  */
	#define BMSK_VDC_PIPEACONF_tg0_comp_en	(1<<20) /* == 0x00100000:  */
	#define BMSK_VDC_PIPEACONF_Planes_off	(1<<19) /* == 0x00080000:  */
	#define BMSK_VDC_PIPEACONF_reserved_18_2	0x0007fffc /*  */
	#define BMSK_VDC_PIPEACONF_Gamma_en	(1<<1) /* == 0x00000002:  */
	#define BMSK_VDC_PIPEACONF_PAC_DITHER_ENABLE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_PIPEACONF - roff, lsb, width, mask */
	#define BITFIELD_VDC_PIPEACONF_Pipe_Enable	 0x70008, 31, 1, 0x80000000
	#define BITFIELD_VDC_PIPEACONF_reserved_30_29	 0x70008, 29, 2, 0x60000000
	#define BITFIELD_VDC_PIPEACONF_Frame_start_delay	 0x70008, 27, 2, 0x18000000
	#define BITFIELD_VDC_PIPEACONF_reserved_26	 0x70008, 26, 1, 0x04000000
	#define BITFIELD_VDC_PIPEACONF_Force_Border	 0x70008, 25, 1, 0x02000000
	#define BITFIELD_VDC_PIPEACONF_reserved_24	 0x70008, 24, 1, 0x01000000
	#define BITFIELD_VDC_PIPEACONF_Interlaced_mode	 0x70008, 21, 3, 0x00e00000
	#define BITFIELD_VDC_PIPEACONF_tg0_comp_en	 0x70008, 20, 1, 0x00100000
	#define BITFIELD_VDC_PIPEACONF_Planes_off	 0x70008, 19, 1, 0x00080000
	#define BITFIELD_VDC_PIPEACONF_reserved_18_2	 0x70008, 2, 17, 0x0007fffc
	#define BITFIELD_VDC_PIPEACONF_Gamma_en	 0x70008, 1, 1, 0x00000002
	#define BITFIELD_VDC_PIPEACONF_PAC_DITHER_ENABLE	 0x70008, 0, 1, 0x00000001
#define ROFF_VDC_PIPEASTAT	0x70024 /* Pipe A Display Status */ 
	#define BITFIELD_VDC_PIPEASTAT	 0x70024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for VDC_PIPEASTAT */
	#define BLSB_VDC_PIPEASTAT_FIFO_A_Underrun	31
	#define BLSB_VDC_PIPEASTAT_reserved_30	30
	#define BLSB_VDC_PIPEASTAT_CRC_Error_en	29
	#define BLSB_VDC_PIPEASTAT_CRC_Done_en	28
	#define BLSB_VDC_PIPEASTAT_reserved_27_26	26
	#define BLSB_VDC_PIPEASTAT_Vertical_Sync_en	25
	#define BLSB_VDC_PIPEASTAT_Vertical_Blank_en	24
	#define BLSB_VDC_PIPEASTAT_reserved_23_22	22
	#define BLSB_VDC_PIPEASTAT_Odd_Field_en	21
	#define BLSB_VDC_PIPEASTAT_Even_Field_en	20
	#define BLSB_VDC_PIPEASTAT_reserved_19	19
	#define BLSB_VDC_PIPEASTAT_reserved_18	18
	#define BLSB_VDC_PIPEASTAT_Framestart_en	17
	#define BLSB_VDC_PIPEASTAT_reserved_16_14	14
	#define BLSB_VDC_PIPEASTAT_CRC_Error	13
	#define BLSB_VDC_PIPEASTAT_CRC_Done	12
	#define BLSB_VDC_PIPEASTAT_reserved_11_10	10
	#define BLSB_VDC_PIPEASTAT_Vertical_Sync	9
	#define BLSB_VDC_PIPEASTAT_Vertical_Blank	8
	#define BLSB_VDC_PIPEASTAT_reserved_7_6	6
	#define BLSB_VDC_PIPEASTAT_Odd_Field	5
	#define BLSB_VDC_PIPEASTAT_Even_Field	4
	#define BLSB_VDC_PIPEASTAT_reserved_3	3
	#define BLSB_VDC_PIPEASTAT_reserved_2	2
	#define BLSB_VDC_PIPEASTAT_Framestart	1
	#define BLSB_VDC_PIPEASTAT_reserved_0	0
	/* Register Bit Widths for VDC_PIPEASTAT */
	#define BWID_VDC_PIPEASTAT_FIFO_A_Underrun	1
	#define BWID_VDC_PIPEASTAT_reserved_30	1
	#define BWID_VDC_PIPEASTAT_CRC_Error_en	1
	#define BWID_VDC_PIPEASTAT_CRC_Done_en	1
	#define BWID_VDC_PIPEASTAT_reserved_27_26	2
	#define BWID_VDC_PIPEASTAT_Vertical_Sync_en	1
	#define BWID_VDC_PIPEASTAT_Vertical_Blank_en	1
	#define BWID_VDC_PIPEASTAT_reserved_23_22	2
	#define BWID_VDC_PIPEASTAT_Odd_Field_en	1
	#define BWID_VDC_PIPEASTAT_Even_Field_en	1
	#define BWID_VDC_PIPEASTAT_reserved_19	1
	#define BWID_VDC_PIPEASTAT_reserved_18	1
	#define BWID_VDC_PIPEASTAT_Framestart_en	1
	#define BWID_VDC_PIPEASTAT_reserved_16_14	3
	#define BWID_VDC_PIPEASTAT_CRC_Error	1
	#define BWID_VDC_PIPEASTAT_CRC_Done	1
	#define BWID_VDC_PIPEASTAT_reserved_11_10	2
	#define BWID_VDC_PIPEASTAT_Vertical_Sync	1
	#define BWID_VDC_PIPEASTAT_Vertical_Blank	1
	#define BWID_VDC_PIPEASTAT_reserved_7_6	2
	#define BWID_VDC_PIPEASTAT_Odd_Field	1
	#define BWID_VDC_PIPEASTAT_Even_Field	1
	#define BWID_VDC_PIPEASTAT_reserved_3	1
	#define BWID_VDC_PIPEASTAT_reserved_2	1
	#define BWID_VDC_PIPEASTAT_Framestart	1
	#define BWID_VDC_PIPEASTAT_reserved_0	1
	/* Register Bit MASKS for VDC_PIPEASTAT */
	#define BMSK_VDC_PIPEASTAT_FIFO_A_Underrun	(1<<31) /* == 0x80000000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_30	(1<<30) /* == 0x40000000:  */
	#define BMSK_VDC_PIPEASTAT_CRC_Error_en	(1<<29) /* == 0x20000000:  */
	#define BMSK_VDC_PIPEASTAT_CRC_Done_en	(1<<28) /* == 0x10000000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_27_26	0x0c000000 /*  */
	#define BMSK_VDC_PIPEASTAT_Vertical_Sync_en	(1<<25) /* == 0x02000000:  */
	#define BMSK_VDC_PIPEASTAT_Vertical_Blank_en	(1<<24) /* == 0x01000000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_23_22	0x00c00000 /*  */
	#define BMSK_VDC_PIPEASTAT_Odd_Field_en	(1<<21) /* == 0x00200000:  */
	#define BMSK_VDC_PIPEASTAT_Even_Field_en	(1<<20) /* == 0x00100000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_19	(1<<19) /* == 0x00080000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_18	(1<<18) /* == 0x00040000:  */
	#define BMSK_VDC_PIPEASTAT_Framestart_en	(1<<17) /* == 0x00020000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_16_14	0x0001c000 /*  */
	#define BMSK_VDC_PIPEASTAT_CRC_Error	(1<<13) /* == 0x00002000:  */
	#define BMSK_VDC_PIPEASTAT_CRC_Done	(1<<12) /* == 0x00001000:  */
	#define BMSK_VDC_PIPEASTAT_reserved_11_10	0x00000c00 /*  */
	#define BMSK_VDC_PIPEASTAT_Vertical_Sync	(1<<9) /* == 0x00000200:  */
	#define BMSK_VDC_PIPEASTAT_Vertical_Blank	(1<<8) /* == 0x00000100:  */
	#define BMSK_VDC_PIPEASTAT_reserved_7_6	0x000000c0 /*  */
	#define BMSK_VDC_PIPEASTAT_Odd_Field	(1<<5) /* == 0x00000020:  */
	#define BMSK_VDC_PIPEASTAT_Even_Field	(1<<4) /* == 0x00000010:  */
	#define BMSK_VDC_PIPEASTAT_reserved_3	(1<<3) /* == 0x00000008:  */
	#define BMSK_VDC_PIPEASTAT_reserved_2	(1<<2) /* == 0x00000004:  */
	#define BMSK_VDC_PIPEASTAT_Framestart	(1<<1) /* == 0x00000002:  */
	#define BMSK_VDC_PIPEASTAT_reserved_0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for VDC_PIPEASTAT - roff, lsb, width, mask */
	#define BITFIELD_VDC_PIPEASTAT_FIFO_A_Underrun	 0x70024, 31, 1, 0x80000000
	#define BITFIELD_VDC_PIPEASTAT_reserved_30	 0x70024, 30, 1, 0x40000000
	#define BITFIELD_VDC_PIPEASTAT_CRC_Error_en	 0x70024, 29, 1, 0x20000000
	#define BITFIELD_VDC_PIPEASTAT_CRC_Done_en	 0x70024, 28, 1, 0x10000000
	#define BITFIELD_VDC_PIPEASTAT_reserved_27_26	 0x70024, 26, 2, 0x0c000000
	#define BITFIELD_VDC_PIPEASTAT_Vertical_Sync_en	 0x70024, 25, 1, 0x02000000
	#define BITFIELD_VDC_PIPEASTAT_Vertical_Blank_en	 0x70024, 24, 1, 0x01000000
	#define BITFIELD_VDC_PIPEASTAT_reserved_23_22	 0x70024, 22, 2, 0x00c00000
	#define BITFIELD_VDC_PIPEASTAT_Odd_Field_en	 0x70024, 21, 1, 0x00200000
	#define BITFIELD_VDC_PIPEASTAT_Even_Field_en	 0x70024, 20, 1, 0x00100000
	#define BITFIELD_VDC_PIPEASTAT_reserved_19	 0x70024, 19, 1, 0x00080000
	#define BITFIELD_VDC_PIPEASTAT_reserved_18	 0x70024, 18, 1, 0x00040000
	#define BITFIELD_VDC_PIPEASTAT_Framestart_en	 0x70024, 17, 1, 0x00020000
	#define BITFIELD_VDC_PIPEASTAT_reserved_16_14	 0x70024, 14, 3, 0x0001c000
	#define BITFIELD_VDC_PIPEASTAT_CRC_Error	 0x70024, 13, 1, 0x00002000
	#define BITFIELD_VDC_PIPEASTAT_CRC_Done	 0x70024, 12, 1, 0x00001000
	#define BITFIELD_VDC_PIPEASTAT_reserved_11_10	 0x70024, 10, 2, 0x00000c00
	#define BITFIELD_VDC_PIPEASTAT_Vertical_Sync	 0x70024, 9, 1, 0x00000200
	#define BITFIELD_VDC_PIPEASTAT_Vertical_Blank	 0x70024, 8, 1, 0x00000100
	#define BITFIELD_VDC_PIPEASTAT_reserved_7_6	 0x70024, 6, 2, 0x000000c0
	#define BITFIELD_VDC_PIPEASTAT_Odd_Field	 0x70024, 5, 1, 0x00000020
	#define BITFIELD_VDC_PIPEASTAT_Even_Field	 0x70024, 4, 1, 0x00000010
	#define BITFIELD_VDC_PIPEASTAT_reserved_3	 0x70024, 3, 1, 0x00000008
	#define BITFIELD_VDC_PIPEASTAT_reserved_2	 0x70024, 2, 1, 0x00000004
	#define BITFIELD_VDC_PIPEASTAT_Framestart	 0x70024, 1, 1, 0x00000002
	#define BITFIELD_VDC_PIPEASTAT_reserved_0	 0x70024, 0, 1, 0x00000001
#define ROFF_VDC_PIPEBDE	0x71008 /* Pipe B Dither Enable */ 
	#define BITFIELD_VDC_PIPEBDE	 0x71008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_BB_PRNGSR	0x71000 /* Pipe B PRNG Shift */ 
	#define BITFIELD_VDC_BB_PRNGSR	 0x71000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module VDC SPECIFIC SVEN Events */




#endif /* VDC_REGOFFS_H */
