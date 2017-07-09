#ifndef XAB_APER_REGOFFS_H
#define XAB_APER_REGOFFS_H 1
#warning including deprecated file XAB_APER_REGOFFS_H please use sanitized filename
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


/* Module XAB_APER CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_XAB_APER_XAB_DEBUG_CNTRL	0x0 /* XAB DEBUG CONTROL */ 
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for XAB_APER_XAB_DEBUG_CNTRL */
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_3	30
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_THRESH	24
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR	18
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_RST	17
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_EN	16
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_1	10
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_SAP_PORT_DIS	2
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_XSI_ISSUE_DIS	1
	#define BLSB_XAB_APER_XAB_DEBUG_CNTRL_XAB_DEBUG_MODE_EN	0
	/* Register Bit Widths for XAB_APER_XAB_DEBUG_CNTRL */
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_3	2
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_THRESH	6
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR	6
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_RST	1
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_EN	1
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_1	6
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_SAP_PORT_DIS	8
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_XSI_ISSUE_DIS	1
	#define BWID_XAB_APER_XAB_DEBUG_CNTRL_XAB_DEBUG_MODE_EN	1
	/* Register Bit MASKS for XAB_APER_XAB_DEBUG_CNTRL */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_3	0xc0000000 /* Reserved */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_THRESH	0x3f000000 /* Port Issye Counter Threshold */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR	0x00fc0000 /* Port Issue Counter */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_RST	(1<<17) /* == 0x00020000: Port Issue Counter Reset */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_EN	(1<<16) /* == 0x00010000: Port Iissue Counter Enable */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_1	0x0000fc00 /* Reserved */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_SAP_PORT_DIS	0x000003fc /* SAP Port DISABLE */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_XSI_ISSUE_DIS	(1<<1) /* == 0x00000002: XSI ISSUE DISABLE */
	#define BMSK_XAB_APER_XAB_DEBUG_CNTRL_XAB_DEBUG_MODE_EN	(1<<0) /* == 0x00000001: XAB Debug Mode Enable */
	/* Register BITFIELD for XAB_APER_XAB_DEBUG_CNTRL - roff, lsb, width, mask */
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_3	 0x0000, 30, 2, 0xc0000000
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_THRESH	 0x0000, 24, 6, 0x3f000000
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR	 0x0000, 18, 6, 0x00fc0000
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_RST	 0x0000, 17, 1, 0x00020000
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_PORT_ISSUE_CNTR_EN	 0x0000, 16, 1, 0x00010000
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_RESERVED_1	 0x0000, 10, 6, 0x0000fc00
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_SAP_PORT_DIS	 0x0000, 2, 8, 0x000003fc
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_XSI_ISSUE_DIS	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_XAB_APER_XAB_DEBUG_CNTRL_XAB_DEBUG_MODE_EN	 0x0000, 0, 1, 0x00000001
#define ROFF_XAB_APER_XAB_MATCH_ADDR	0x4 /* XAB MATCH ADDR */ 
	#define BITFIELD_XAB_APER_XAB_MATCH_ADDR	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_XAB_APER_XAB_MATCH_ADDR_MASK	0x8 /* XAB MATCH ADDR MASK */ 
	#define BITFIELD_XAB_APER_XAB_MATCH_ADDR_MASK	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_XAB_APER_PORT0_WATCH_ADDR	0xc /* XAB WATCH ADDR */ 
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_XAB_APER_PORT0_WATCH_ADDR_ATTR	0x10 /* XAB WATCH ADDR ATTR */ 
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR_ATTR	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for XAB_APER_PORT0_WATCH_ADDR_ATTR */
	#define BLSB_XAB_APER_PORT0_WATCH_ADDR_ATTR_Tag	27
	#define BLSB_XAB_APER_PORT0_WATCH_ADDR_ATTR_RESERVED_5	26
	#define BLSB_XAB_APER_PORT0_WATCH_ADDR_ATTR_TYPE	17
	#define BLSB_XAB_APER_PORT0_WATCH_ADDR_ATTR_BYTE_COUNT	8
	#define BLSB_XAB_APER_PORT0_WATCH_ADDR_ATTR_READ_WRITE_CMD	0
	/* Register Bit Widths for XAB_APER_PORT0_WATCH_ADDR_ATTR */
	#define BWID_XAB_APER_PORT0_WATCH_ADDR_ATTR_Tag	5
	#define BWID_XAB_APER_PORT0_WATCH_ADDR_ATTR_RESERVED_5	1
	#define BWID_XAB_APER_PORT0_WATCH_ADDR_ATTR_TYPE	9
	#define BWID_XAB_APER_PORT0_WATCH_ADDR_ATTR_BYTE_COUNT	9
	#define BWID_XAB_APER_PORT0_WATCH_ADDR_ATTR_READ_WRITE_CMD	8
	/* Register Bit MASKS for XAB_APER_PORT0_WATCH_ADDR_ATTR */
	#define BMSK_XAB_APER_PORT0_WATCH_ADDR_ATTR_Tag	0xf8000000 /* Watch Address Tag */
	#define BMSK_XAB_APER_PORT0_WATCH_ADDR_ATTR_RESERVED_5	(1<<26) /* == 0x04000000: Reserved */
	#define BMSK_XAB_APER_PORT0_WATCH_ADDR_ATTR_TYPE	0x03fe0000 /* Watch Address type */
	#define BMSK_XAB_APER_PORT0_WATCH_ADDR_ATTR_BYTE_COUNT	0x0001ff00 /* Watch address Byte Count */
	#define BMSK_XAB_APER_PORT0_WATCH_ADDR_ATTR_READ_WRITE_CMD	0x000000ff /* Read/Write Command */
	/* Register BITFIELD for XAB_APER_PORT0_WATCH_ADDR_ATTR - roff, lsb, width, mask */
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR_ATTR_Tag	 0x0010, 27, 5, 0xf8000000
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR_ATTR_RESERVED_5	 0x0010, 26, 1, 0x04000000
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR_ATTR_TYPE	 0x0010, 17, 9, 0x03fe0000
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR_ATTR_BYTE_COUNT	 0x0010, 8, 9, 0x0001ff00
	#define BITFIELD_XAB_APER_PORT0_WATCH_ADDR_ATTR_READ_WRITE_CMD	 0x0010, 0, 8, 0x000000ff
#define ROFF_XAB_APER_INT_CNTRL_STAT	0x14 /* XAB INTERRUPT CONTROL STATUS */ 
	#define BITFIELD_XAB_APER_INT_CNTRL_STAT	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for XAB_APER_INT_CNTRL_STAT */
	#define BLSB_XAB_APER_INT_CNTRL_STAT_RESERVED_6	5
	#define BLSB_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_ST	4
	#define BLSB_XAB_APER_INT_CNTRL_STAT_RESERVED_7	1
	#define BLSB_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_EN	0
	/* Register Bit Widths for XAB_APER_INT_CNTRL_STAT */
	#define BWID_XAB_APER_INT_CNTRL_STAT_RESERVED_6	27
	#define BWID_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_ST	1
	#define BWID_XAB_APER_INT_CNTRL_STAT_RESERVED_7	3
	#define BWID_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_EN	1
	/* Register Bit MASKS for XAB_APER_INT_CNTRL_STAT */
	#define BMSK_XAB_APER_INT_CNTRL_STAT_RESERVED_6	0xffffffe0 /* Reserved */
	#define BMSK_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_ST	(1<<4) /* == 0x00000010: XAB Counter Match Intr Stat */
	#define BMSK_XAB_APER_INT_CNTRL_STAT_RESERVED_7	0x0000000e /* Reserved */
	#define BMSK_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_EN	(1<<0) /* == 0x00000001: XAB Debug Counter Match Intr En */
	/* Register BITFIELD for XAB_APER_INT_CNTRL_STAT - roff, lsb, width, mask */
	#define BITFIELD_XAB_APER_INT_CNTRL_STAT_RESERVED_6	 0x0014, 5, 27, 0xffffffe0
	#define BITFIELD_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_ST	 0x0014, 4, 1, 0x00000010
	#define BITFIELD_XAB_APER_INT_CNTRL_STAT_RESERVED_7	 0x0014, 1, 3, 0x0000000e
	#define BITFIELD_XAB_APER_INT_CNTRL_STAT_XAB_DBG_INT_EN	 0x0014, 0, 1, 0x00000001


/* Module XAB_APER SPECIFIC SVEN Events */




#endif /* XAB_APER_REGOFFS_H */
