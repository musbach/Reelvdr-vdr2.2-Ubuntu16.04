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


#define ROFF_VDC_OVA_OBUF_OY	0x30104 /* Overlay Buffer 1 Y Pointer */ 
	#define BITFIELD_VDC_OVA_OBUF_OY	 0x30104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OBUF_0U	0x30108 /* Overlay Buffer 0 U Pointer */ 
	#define BITFIELD_VDC_OVA_OBUF_0U	 0x30108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OBUF_0V	0x3010c /* Overlay Buffer 0 V Pointer */ 
	#define BITFIELD_VDC_OVA_OBUF_0V	 0x3010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OBUF_1U	0x30110 /* Overlay Buffer 1 U Pointer */ 
	#define BITFIELD_VDC_OVA_OBUF_1U	 0x30110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OBUF_1V	0x30114 /* Overlay Buffer 1 V Pointer */ 
	#define BITFIELD_VDC_OVA_OBUF_1V	 0x30114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OSTRIDE	0x30118 /* Overlay Stride */ 
	#define BITFIELD_VDC_OVA_OSTRIDE	 0x30118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_YRGB_VPH	0x3011c /* Y/RGB Vertical Phase 0/1 */ 
	#define BITFIELD_VDC_OVA_YRGB_VPH	 0x3011c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_UV_VPH	0x30120 /* UV Vertical Phase 0/1 */ 
	#define BITFIELD_VDC_OVA_UV_VPH	 0x30120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_HORZ_PH	0x30124 /* Horizontal Phase */ 
	#define BITFIELD_VDC_OVA_HORZ_PH	 0x30124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_INIT_PHS	0x30128 /* Initial Phase Shift */ 
	#define BITFIELD_VDC_OVA_INIT_PHS	 0x30128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_DWINPOS	0x3012c /* Destination Window Position */ 
	#define BITFIELD_VDC_OVA_DWINPOS	 0x3012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_DWINSZ	0x30130 /* Destination Window Size */ 
	#define BITFIELD_VDC_OVA_DWINSZ	 0x30130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_SWIDTH	0x30134 /* Source Width */ 
	#define BITFIELD_VDC_OVA_SWIDTH	 0x30134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_SWIDTHSW	0x30138 /* Source Width In SWORDS */ 
	#define BITFIELD_VDC_OVA_SWIDTHSW	 0x30138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_SHEIGHT	0x3013c /* Source Height */ 
	#define BITFIELD_VDC_OVA_SHEIGHT	 0x3013c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_YRGBSCALE	0x30140 /* Y/RGB Scale Factor */ 
	#define BITFIELD_VDC_OVA_YRGBSCALE	 0x30140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_UVSCALE	0x30144 /* U V Scale Factor */ 
	#define BITFIELD_VDC_OVA_UVSCALE	 0x30144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OCLRC0	0x30148 /* Overlay Color Correction 0 */ 
	#define BITFIELD_VDC_OVA_OCLRC0	 0x30148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OCLRC1	0x3014c /* Overlay Color Correction 1 */ 
	#define BITFIELD_VDC_OVA_OCLRC1	 0x3014c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OCONFIG	0x30164 /* Overlay Configuration */ 
	#define BITFIELD_VDC_OVA_OCONFIG	 0x30164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OCOMD	0x30168 /* Overlay Command */ 
	#define BITFIELD_VDC_OVA_OCOMD	 0x30168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OFLIPMODE	0x3016c /* Overlay Flip Mode */ 
	#define BITFIELD_VDC_OVA_OFLIPMODE	 0x3016c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OFDROP	0x30170 /* Overlay Frame Drop Counter */ 
	#define BITFIELD_VDC_OVA_OFDROP	 0x30170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_OFREPEAT	0x30174 /* Overlay Frame Repeat Counter */ 
	#define BITFIELD_VDC_OVA_OFREPEAT	 0x30174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_UVSCALEV	0x301a4 /* UV Vertical Downscale Integer */ 
	#define BITFIELD_VDC_OVA_UVSCALEV	 0x301a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_Y_VCOEFS	0x30200 /* Overlay Y Vertical Filter Coefficient */ 
	#define BITFIELD_VDC_OVA_Y_VCOEFS	 0x30200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_Y_HCOEFS	0x30300 /* Overlay Y Horizontal Filter Coefficients */ 
	#define BITFIELD_VDC_OVA_Y_HCOEFS	 0x30300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_UV_VCOEFS	0x30500 /* Overlay UV Vertical Filter Coefficients */ 
	#define BITFIELD_VDC_OVA_UV_VCOEFS	 0x30500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVA_UV_HCOEFS	0x30600 /* Overlay UV Horizontal Filter Coefficients */ 
	#define BITFIELD_VDC_OVA_UV_HCOEFS	 0x30600, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OBUF_OY	0x31104 /* Overlay Buffer 1 Y Pointer */ 
	#define BITFIELD_VDC_OVB_OBUF_OY	 0x31104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OBUF_0U	0x31108 /* Overlay Buffer 0 U Pointer */ 
	#define BITFIELD_VDC_OVB_OBUF_0U	 0x31108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OBUF_0V	0x3110c /* Overlay Buffer 0 V Pointer */ 
	#define BITFIELD_VDC_OVB_OBUF_0V	 0x3110c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OBUF_1U	0x31110 /* Overlay Buffer 1 U Pointer */ 
	#define BITFIELD_VDC_OVB_OBUF_1U	 0x31110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OBUF_1V	0x31114 /* Overlay Buffer 1 V Pointer */ 
	#define BITFIELD_VDC_OVB_OBUF_1V	 0x31114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OSTRIDE	0x31118 /* Overlay Stride */ 
	#define BITFIELD_VDC_OVB_OSTRIDE	 0x31118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_YRGB_VPH	0x3111c /* Y/RGB Vertical Phase 0/1 */ 
	#define BITFIELD_VDC_OVB_YRGB_VPH	 0x3111c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_UV_VPH	0x31120 /* UV Vertical Phase 0/1 */ 
	#define BITFIELD_VDC_OVB_UV_VPH	 0x31120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_HORZ_PH	0x31124 /* Horizontal Phase */ 
	#define BITFIELD_VDC_OVB_HORZ_PH	 0x31124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_INIT_PHS	0x31128 /* Initial Phase Shift */ 
	#define BITFIELD_VDC_OVB_INIT_PHS	 0x31128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_DWINPOS	0x3112c /* Destination Window Position */ 
	#define BITFIELD_VDC_OVB_DWINPOS	 0x3112c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_DWINSZ	0x31130 /* Destination Window Size */ 
	#define BITFIELD_VDC_OVB_DWINSZ	 0x31130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_SWIDTH	0x31134 /* Source Width */ 
	#define BITFIELD_VDC_OVB_SWIDTH	 0x31134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_SWIDTHSW	0x31138 /* Source Width In SWORDS */ 
	#define BITFIELD_VDC_OVB_SWIDTHSW	 0x31138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_SHEIGHT	0x3113c /* Source Height */ 
	#define BITFIELD_VDC_OVB_SHEIGHT	 0x3113c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_YRGBSCALE	0x31140 /* Y/RGB Scale Factor */ 
	#define BITFIELD_VDC_OVB_YRGBSCALE	 0x31140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_UVSCALE	0x31144 /* U V Scale Factor */ 
	#define BITFIELD_VDC_OVB_UVSCALE	 0x31144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OCLRC0	0x31148 /* Overlay Color Correction 0 */ 
	#define BITFIELD_VDC_OVB_OCLRC0	 0x31148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OCLRC1	0x3114c /* Overlay Color Correction 1 */ 
	#define BITFIELD_VDC_OVB_OCLRC1	 0x3114c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OCONFIG	0x31164 /* Overlay Configuration */ 
	#define BITFIELD_VDC_OVB_OCONFIG	 0x31164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OCOMD	0x31168 /* Overlay Command */ 
	#define BITFIELD_VDC_OVB_OCOMD	 0x31168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OFLIPMODE	0x3116c /* Overlay Flip Mode */ 
	#define BITFIELD_VDC_OVB_OFLIPMODE	 0x3116c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OFDROP	0x31170 /* Overlay Frame Drop Counter */ 
	#define BITFIELD_VDC_OVB_OFDROP	 0x31170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_OFREPEAT	0x31174 /* Overlay Frame Repeat Counter */ 
	#define BITFIELD_VDC_OVB_OFREPEAT	 0x31174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_UVSCALEV	0x311a4 /* UV Vertical Downscale Integer */ 
	#define BITFIELD_VDC_OVB_UVSCALEV	 0x311a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_Y_VCOEFS	0x31200 /* Overlay Y Vertical Filter Coefficient */ 
	#define BITFIELD_VDC_OVB_Y_VCOEFS	 0x31200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_Y_HCOEFS	0x31300 /* Overlay Y Horizontal Filter Coefficients */ 
	#define BITFIELD_VDC_OVB_Y_HCOEFS	 0x31300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_UV_VCOEFS	0x31500 /* Overlay UV Vertical Filter Coefficients */ 
	#define BITFIELD_VDC_OVB_UV_VCOEFS	 0x31500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_OVB_UV_HCOEFS	0x31600 /* Overlay UV Horizontal Filter Coefficients */ 
	#define BITFIELD_VDC_OVB_UV_HCOEFS	 0x31600, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DPLL_CTRL	0x6014 /* DPLL_CTRL-DPLL Control Register */ 
	#define BITFIELD_VDC_DPLL_CTRL	 0x6014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CLKGATE	0x6200 /* Clock Gating Disable */ 
	#define BITFIELD_VDC_CLKGATE	 0x6200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DPALETTE_A	0xa000 /* DPALETTE_A Pipe A Display Palette */ 
	#define BITFIELD_VDC_DPALETTE_A	 0xa000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_HTOTAL_A	0x6000 /* HTOTAL_A Pipe A Horizontal Total Register */ 
	#define BITFIELD_VDC_HTOTAL_A	 0x6000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_HBLANK_A	0x6004 /* HBLANK_A Pipe A Horizontal Blank Register */ 
	#define BITFIELD_VDC_HBLANK_A	 0x6004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_HSYNC_A	0x6008 /* HSYNC_A Pipe A Horizontal Sync Register */ 
	#define BITFIELD_VDC_HSYNC_A	 0x6008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VTOTAL_A	0x600c /* VTOTAL_A	Pipe A Vertical Total Register */ 
	#define BITFIELD_VDC_VTOTAL_A	 0x600c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VBLANK_A	0x60010 /* VBLANK_A Pipe A Vertical Blank Register */ 
	#define BITFIELD_VDC_VBLANK_A	 0x60010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VSYNC_A	0x60014 /* VSYNCH_A Pipe A Vertical Sync Register */ 
	#define BITFIELD_VDC_VSYNC_A	 0x60014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEASRC	0x6001c /* Pipe A Source Image Size */ 
	#define BITFIELD_VDC_PIPEASRC	 0x6001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_BCLRPAT_A	0x60020 /* Pipe A Border Color Pattern Register */ 
	#define BITFIELD_VDC_BCLRPAT_A	 0x60020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CANVSCLR_A	0x60024 /* Pipe A Canvas (Background) Color Register */ 
	#define BITFIELD_VDC_CANVSCLR_A	 0x60024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_VSYNCSHIFT_A	0x60028 /* Vertical Sync Shift Register */ 
	#define BITFIELD_VDC_VSYNCSHIFT_A	 0x60028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCCtrlColorA	0x60050 /* Pipe A CRC Color Channel Control Register(RED) */ 
	#define BITFIELD_VDC_CRCCtrlColorA	 0x60050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PVOCONFIG	0x61140 /* Pixel Video Output Configuration Register */ 
	#define BITFIELD_VDC_PVOCONFIG	 0x61140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TMCR0	0x62200 /* Tiled Memory Configuration Register */ 
	#define BITFIELD_VDC_TMCR0	 0x62200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TMTAR0	0x62204 /* Tiled Memory Top Address Register */ 
	#define BITFIELD_VDC_TMTAR0	 0x62204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TMBAR0	0x62208 /* Tiled Memory Base Address Register */ 
	#define BITFIELD_VDC_TMBAR0	 0x62208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TMCR1	0x62210 /* Tiled Memory Configuration Register */ 
	#define BITFIELD_VDC_TMCR1	 0x62210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TMTAR1	0x62214 /* Tiled Memory Top Address Register */ 
	#define BITFIELD_VDC_TMTAR1	 0x62214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TMBAR1	0x62218 /* Tiled Memory Base Address Register */ 
	#define BITFIELD_VDC_TMBAR1	 0x62218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCCtrlColorA0	0x60054 /* Pipe A CRC Color Channel Control Register (Green) */ 
	#define BITFIELD_VDC_CRCCtrlColorA0	 0x60054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCCtrlColorA1	0x60058 /* Pipe A CRC Color Channel Control Register (BLUE) */ 
	#define BITFIELD_VDC_CRCCtrlColorA1	 0x60058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCCtrlColorA2	0x6005c /* Pipe A CRC Color Channel Control Register (ALPHA) */ 
	#define BITFIELD_VDC_CRCCtrlColorA2	 0x6005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCResColorA0	0x60060 /* Pipe A CRC Color Channel Result Register (Red) */ 
	#define BITFIELD_VDC_CRCResColorA0	 0x60060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCResColorA1	0x60064 /* Pipe A CRC Color Channel Result Register (Green) */ 
	#define BITFIELD_VDC_CRCResColorA1	 0x60064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCResColorA2	0x60068 /* Pipe A CRC Color Channel Result Register (Blue) */ 
	#define BITFIELD_VDC_CRCResColorA2	 0x60068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CRCResColorA3	0x6006c /* Pipe A CRC Color Channel Result Register (ALPHA) */ 
	#define BITFIELD_VDC_CRCResColorA3	 0x6006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_IPEACONF	0x70008 /* Pipe A Configuration Register */ 
	#define BITFIELD_VDC_IPEACONF	 0x70008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEGCMAXRED	0x70010 /* Pipe Gamma Correction Max Red */ 
	#define BITFIELD_VDC_PIPEGCMAXRED	 0x70010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEGCMAXGRN	0x70014 /* Pipe Gamma Correction Max Green */ 
	#define BITFIELD_VDC_PIPEGCMAXGRN	 0x70014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEGCMAXBLU	0x70018 /* Pipe Gamma Correction Max Red */ 
	#define BITFIELD_VDC_PIPEGCMAXBLU	 0x70018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PIPEASTAT	0x70024 /* Pipe A Display Status */ 
	#define BITFIELD_VDC_PIPEASTAT	 0x70024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPARB_DDB	0x70030 /*  DSPARBConfiguration */ 
	#define BITFIELD_VDC_DSPARB_DDB	 0x70030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PipeAFrameHigh	0x70040 /* Frame Count */ 
	#define BITFIELD_VDC_PipeAFrameHigh	 0x70040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_PipeAFramePixel	0x70044 /*  Pixel Count */ 
	#define BITFIELD_VDC_PipeAFramePixel	 0x70044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CHKN_BITS	0x70400 /*  Chicken Bits  */ 
	#define BITFIELD_VDC_CHKN_BITS	 0x70400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPBCNTR	0x71180 /* Subtitle Plane Plane Control Register */ 
	#define BITFIELD_VDC_DSPBCNTR	 0x71180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPBADDR	0x71184 /* Subtitle Plane Start Address Register */ 
	#define BITFIELD_VDC_DSPBADDR	 0x71184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPBSTRIDE	0x71188 /* Subtitle Plane Stride Register */ 
	#define BITFIELD_VDC_DSPBSTRIDE	 0x71188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPBPOS	0x7118c /* Subtitle Position Register */ 
	#define BITFIELD_VDC_DSPBPOS	 0x7118c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPBSIZE	0x71190 /* Subtitle Height and Width Register */ 
	#define BITFIELD_VDC_DSPBSIZE	 0x71190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPCCNTR	0x72180 /* Graphics Plane  Control Register */ 
	#define BITFIELD_VDC_DSPCCNTR	 0x72180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPCADDR	0x72184 /* Graphics Plane Start Address Register */ 
	#define BITFIELD_VDC_DSPCADDR	 0x72184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_DSPCSTRIDE	0x72188 /* Graphics Plane Stride Register  */ 
	#define BITFIELD_VDC_DSPCSTRIDE	 0x72188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TV_out_Control	0x68000 /*  */ 
	#define BITFIELD_VDC_TV_out_Control	 0x68000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_TV_DAC_Control_Status	0x68004 /*  */ 
	#define BITFIELD_VDC_TV_DAC_Control_Status	 0x68004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_1	0x68008 /*  */ 
	#define BITFIELD_VDC_reserved_1	 0x68008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_2	0x6800c /*  */ 
	#define BITFIELD_VDC_reserved_2	 0x6800c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Space_Convert_Y	0x68010 /*  */ 
	#define BITFIELD_VDC_Color_Space_Convert_Y	 0x68010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Space_Convert_Y2	0x68014 /*  */ 
	#define BITFIELD_VDC_Color_Space_Convert_Y2	 0x68014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Space_Convert_U	0x68018 /*  */ 
	#define BITFIELD_VDC_Color_Space_Convert_U	 0x68018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Space_Convert_U2	0x6801c /*  */ 
	#define BITFIELD_VDC_Color_Space_Convert_U2	 0x6801c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Space_Convert_V	0x68020 /*  */ 
	#define BITFIELD_VDC_Color_Space_Convert_V	 0x68020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Space_Convert_V2	0x68024 /*  */ 
	#define BITFIELD_VDC_Color_Space_Convert_V2	 0x68024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Knobs	0x68028 /*  */ 
	#define BITFIELD_VDC_Color_Knobs	 0x68028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Color_Level_Control	0x6802c /*  */ 
	#define BITFIELD_VDC_Color_Level_Control	 0x6802c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_H_Control1_Hsync_Htotal	0x68030 /*  */ 
	#define BITFIELD_VDC_H_Control1_Hsync_Htotal	 0x68030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_H_Control2_Hsync_H_Burst_Control	0x68034 /*  */ 
	#define BITFIELD_VDC_H_Control2_Hsync_H_Burst_Control	 0x68034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_H_Control3_Blanking	0x68038 /*  */ 
	#define BITFIELD_VDC_H_Control3_Blanking	 0x68038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control1_NBR_and_VI_end	0x6803c /*  */ 
	#define BITFIELD_VDC_V_Control1_NBR_and_VI_end	 0x6803c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control2_Vsync_Control	0x68040 /*  */ 
	#define BITFIELD_VDC_V_Control2_Vsync_Control	 0x68040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control3_Equalisation_Control	0x68044 /*  */ 
	#define BITFIELD_VDC_V_Control3_Equalisation_Control	 0x68044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control4_v_burst_field_1	0x68048 /*  */ 
	#define BITFIELD_VDC_V_Control4_v_burst_field_1	 0x68048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control5_v_burst_field_2	0x6804c /*  */ 
	#define BITFIELD_VDC_V_Control5_v_burst_field_2	 0x6804c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control6_v_burst_field_3	0x68050 /*  */ 
	#define BITFIELD_VDC_V_Control6_v_burst_field_3	 0x68050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Control7_v_burst_field_4	0x68054 /*  */ 
	#define BITFIELD_VDC_V_Control7_v_burst_field_4	 0x68054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_3	0x68058 /*  */ 
	#define BITFIELD_VDC_reserved_3	 0x68058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_SC_Control_1_enables_Burst_level_SC_DDA1	0x68060 /*  */ 
	#define BITFIELD_VDC_SC_Control_1_enables_Burst_level_SC_DDA1	 0x68060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_SC_Control_2_SC_DDA2	0x68064 /*  */ 
	#define BITFIELD_VDC_SC_Control_2_SC_DDA2	 0x68064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_SC_Control_3_SC_DDA3	0x68068 /*  */ 
	#define BITFIELD_VDC_SC_Control_3_SC_DDA3	 0x68068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_4	0x6806c /*  */ 
	#define BITFIELD_VDC_reserved_4	 0x6806c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Window_Position	0x68070 /*  */ 
	#define BITFIELD_VDC_Window_Position	 0x68070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Window_size	0x68074 /*  */ 
	#define BITFIELD_VDC_Window_size	 0x68074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_5	0x68078 /*  */ 
	#define BITFIELD_VDC_reserved_5	 0x68078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Filter_Control_1_Mode_and_H_frac	0x68080 /*  */ 
	#define BITFIELD_VDC_Filter_Control_1_Mode_and_H_frac	 0x68080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Filter_Control_2_Vert_scale	0x68084 /*  */ 
	#define BITFIELD_VDC_Filter_Control_2_Vert_scale	 0x68084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Filter_Control_3_Vert_Initial_Phase	0x68088 /*  */ 
	#define BITFIELD_VDC_Filter_Control_3_Vert_Initial_Phase	 0x68088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_Sin_Rom	0x6808c /*  */ 
	#define BITFIELD_VDC_Sin_Rom	 0x6808c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CC_Control	0x68090 /*  */ 
	#define BITFIELD_VDC_CC_Control	 0x68090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CC_Data_Field_1	0x68094 /*  */ 
	#define BITFIELD_VDC_CC_Data_Field_1	 0x68094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_CC_Data_Filed_2	0x68098 /*  */ 
	#define BITFIELD_VDC_CC_Data_Filed_2	 0x68098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_6	0x6809c /*  */ 
	#define BITFIELD_VDC_reserved_6	 0x6809c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WSS_Control	0x680b0 /*  */ 
	#define BITFIELD_VDC_WSS_Control	 0x680b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_WSS_DATA	0x680b8 /*  */ 
	#define BITFIELD_VDC_WSS_DATA	 0x680b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_reserved_7	0x680bc /*  */ 
	#define BITFIELD_VDC_reserved_7	 0x680bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_H_Filter_Y_Coefficients	0x68100 /*  */ 
	#define BITFIELD_VDC_H_Filter_Y_Coefficients	 0x68100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_H_Filter_C_Coefficients	0x68200 /*  */ 
	#define BITFIELD_VDC_H_Filter_C_Coefficients	 0x68200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Filter_Y_Coefficients	0x68300 /*  */ 
	#define BITFIELD_VDC_V_Filter_Y_Coefficients	 0x68300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_VDC_V_Filter_C_Coefficients	0x68400 /*  */ 
	#define BITFIELD_VDC_V_Filter_C_Coefficients	 0x68400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module VDC SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_VDC_OUT_FIFO_FULL	0x1
#define SVEN_MODULE_EVENT_VDC_IN_FIFO_STARVED	0x2


#endif /* VDC_REGOFFS_H */
