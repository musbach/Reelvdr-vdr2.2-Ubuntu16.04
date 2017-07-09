#ifndef OMAR_CW_REGOFFS_H
#define OMAR_CW_REGOFFS_H 1
#warning including deprecated file OMAR_CW_REGOFFS_H please use sanitized filename
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


/* Module OMAR_CW CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_OMAR_CW_GLOBAL_CW	0x0 /* Global Chip Watch Control */ 
	#define BITFIELD_OMAR_CW_GLOBAL_CW	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_RESERVED0	0x4 /* reserved0 */ 
	#define BITFIELD_OMAR_CW_RESERVED0	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_RESERVED1	0x8 /* reserved1 */ 
	#define BITFIELD_OMAR_CW_RESERVED1	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_RESERVED2	0xc /* reserved2 */ 
	#define BITFIELD_OMAR_CW_RESERVED2	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SKEW9_0_CNTRL	0x10 /* Skew Control Register for Bus bits 9-0 */ 
	#define BITFIELD_OMAR_CW_SKEW9_0_CNTRL	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SKEW19_10_CNTRL	0x14 /* Skew Control Register for Bus bits 19-10 */ 
	#define BITFIELD_OMAR_CW_SKEW19_10_CNTRL	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SKEW29_20_CNTRL	0x18 /* Skew Control Register for Bus bits 29-20 */ 
	#define BITFIELD_OMAR_CW_SKEW29_20_CNTRL	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SKEW33_30_CNTRL	0x1c /* Skew Control Register for Bus bits 33-30 */ 
	#define BITFIELD_OMAR_CW_SKEW33_30_CNTRL	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_DTUNIT_CW_OVERRIDE	0x20 /* DTUnit Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_DTUNIT_CW_OVERRIDE	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_VCMH1_CW_OVERRIDE	0x24 /* VCMH1 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_VCMH1_CW_OVERRIDE	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_VCMH0_CW_OVERRIDE	0x28 /* VCMH0 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_VCMH0_CW_OVERRIDE	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_MCU_CW_OVERRIDE	0x2c /* MCU Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_MCU_CW_OVERRIDE	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_XSI_CW_OVERRIDE	0x30 /* XSI Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_XSI_CW_OVERRIDE	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_VCAP1_CW_OVERRIDE	0x34 /* VCAP1 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_VCAP1_CW_OVERRIDE	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_VCAP2_CW_OVERRIDE	0x38 /* VCAP2 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_VCAP2_CW_OVERRIDE	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_MPDG2VE_CW_OVERRIDE	0x3c /* MPEG2VE Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_MPDG2VE_CW_OVERRIDE	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_H264VD_CW_OVERRIDE	0x40 /* H264 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_H264VD_CW_OVERRIDE	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_MPG2VD_CW_OVERRIDE	0x44 /* MPEG2VD Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_MPG2VD_CW_OVERRIDE	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SEC_CW_OVERRIDE	0x48 /* SEC Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_SEC_CW_OVERRIDE	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_TSD_CW_OVERRIDE	0x4c /* TSD Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_TSD_CW_OVERRIDE	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_PREFILTER1_CW_OVERRIDE	0x50 /* Prefilter1 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_PREFILTER1_CW_OVERRIDE	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_PREFILTER2_CW_OVERRIDE	0x54 /* Prefilter2 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_PREFILTER2_CW_OVERRIDE	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_PREFILTER3_CW_OVERRIDE	0x58 /* Prefilter3 Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_PREFILTER3_CW_OVERRIDE	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_PCI_CW_OVERRIDE	0x5c /* PCI Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_PCI_CW_OVERRIDE	 0x005c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_VDC_CW_OVERRIDE	0x60 /* VDC Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_VDC_CW_OVERRIDE	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_GFX_CW_OVERRIDE	0x64 /* GFX Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_GFX_CW_OVERRIDE	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SCK_CW_OVERRIDE	0x68 /* SCK Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_SCK_CW_OVERRIDE	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_PCK_CW_OVERRIDE	0x6c /* PCK Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_PCK_CW_OVERRIDE	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_RU_CW_OVERRIDE	0x70 /* RU Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_RU_CW_OVERRIDE	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_USIM_CW_OVERRIDE	0x74 /* Smart Card Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_USIM_CW_OVERRIDE	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_UART_CW_OVERRIDE	0x78 /* UART Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_UART_CW_OVERRIDE	 0x0078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_EXP_CW_OVERRIDE	0x7c /* Expansion Bus Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_EXP_CW_OVERRIDE	 0x007c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_SPI_CW_OVERRIDE	0x80 /* SPI Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_SPI_CW_OVERRIDE	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_I2C_CW_OVERRIDE	0x84 /* I2C Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_I2C_CW_OVERRIDE	 0x0084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_ARBS_CW_OVERRIDE	0x88 /* Pub Arbiters Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_ARBS_CW_OVERRIDE	 0x0088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CW_AU_CW_OVERRIDE	0x8c /* Audio Bus Chip Watch Selection */ 
	#define BITFIELD_OMAR_CW_AU_CW_OVERRIDE	 0x008c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module OMAR_CW SPECIFIC SVEN Events */




#endif /* OMAR_CW_REGOFFS_H */
