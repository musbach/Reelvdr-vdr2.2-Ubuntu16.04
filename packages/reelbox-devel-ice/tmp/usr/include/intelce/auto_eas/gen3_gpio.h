#ifndef GPIO_REGOFFS_H
#define GPIO_REGOFFS_H 1
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


/* Module GPIO CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_GPIO_GPIO_GPOUTR	0x0 /* GPIO 0:11 pin data output register. */ 
	#define BITFIELD_GPIO_GPIO_GPOUTR	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_GPOUTR */
	#define BLSB_GPIO_GPIO_GPOUTR_RESERVED	12
	#define BLSB_GPIO_GPIO_GPOUTR_GPIO_DATA	0
	/* Register Bit Widths for GPIO_GPIO_GPOUTR */
	#define BWID_GPIO_GPIO_GPOUTR_RESERVED	20
	#define BWID_GPIO_GPIO_GPOUTR_GPIO_DATA	12
	/* Register Bit MASKS for GPIO_GPIO_GPOUTR */
	#define BMSK_GPIO_GPIO_GPOUTR_RESERVED	0xfffff000 /*  */
	#define BMSK_GPIO_GPIO_GPOUTR_GPIO_DATA	0x00000fff /*  */
	/* Register BITFIELD for GPIO_GPIO_GPOUTR - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_GPOUTR_RESERVED	 0x0000, 12, 20, 0xfffff000
	#define BITFIELD_GPIO_GPIO_GPOUTR_GPIO_DATA	 0x0000, 0, 12, 0x00000fff
#define ROFF_GPIO_GPIO_GPOER	0x4 /* GPIO 0:11 pin output driving register. */ 
	#define BITFIELD_GPIO_GPIO_GPOER	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_GPOER */
	#define BLSB_GPIO_GPIO_GPOER_RESERVED	12
	#define BLSB_GPIO_GPIO_GPOER_GPIO_DATA	0
	/* Register Bit Widths for GPIO_GPIO_GPOER */
	#define BWID_GPIO_GPIO_GPOER_RESERVED	20
	#define BWID_GPIO_GPIO_GPOER_GPIO_DATA	12
	/* Register Bit MASKS for GPIO_GPIO_GPOER */
	#define BMSK_GPIO_GPIO_GPOER_RESERVED	0xfffff000 /*  */
	#define BMSK_GPIO_GPIO_GPOER_GPIO_DATA	0x00000fff /*  */
	/* Register BITFIELD for GPIO_GPIO_GPOER - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_GPOER_RESERVED	 0x0004, 12, 20, 0xfffff000
	#define BITFIELD_GPIO_GPIO_GPOER_GPIO_DATA	 0x0004, 0, 12, 0x00000fff
#define ROFF_GPIO_GPIO_GPINR	0x8 /* GPIO 0:11 pin status input level register. */ 
	#define BITFIELD_GPIO_GPIO_GPINR	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_GPINR */
	#define BLSB_GPIO_GPIO_GPINR_RESERVED	12
	#define BLSB_GPIO_GPIO_GPINR_GPIO_DATA	0
	/* Register Bit Widths for GPIO_GPIO_GPINR */
	#define BWID_GPIO_GPIO_GPINR_RESERVED	20
	#define BWID_GPIO_GPIO_GPINR_GPIO_DATA	12
	/* Register Bit MASKS for GPIO_GPIO_GPINR */
	#define BMSK_GPIO_GPIO_GPINR_RESERVED	0xfffff000 /*  */
	#define BMSK_GPIO_GPIO_GPINR_GPIO_DATA	0x00000fff /*  */
	/* Register BITFIELD for GPIO_GPIO_GPINR - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_GPINR_RESERVED	 0x0008, 12, 20, 0xfffff000
	#define BITFIELD_GPIO_GPIO_GPINR_GPIO_DATA	 0x0008, 0, 12, 0x00000fff
#define ROFF_GPIO_GPIO_GPSTR	0xc /* GPIO 0:11 interrupt status register. */ 
	#define BITFIELD_GPIO_GPIO_GPSTR	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_GPSTR */
	#define BLSB_GPIO_GPIO_GPSTR_RESERVED	12
	#define BLSB_GPIO_GPIO_GPSTR_GPIO_DATA	0
	/* Register Bit Widths for GPIO_GPIO_GPSTR */
	#define BWID_GPIO_GPIO_GPSTR_RESERVED	20
	#define BWID_GPIO_GPIO_GPSTR_GPIO_DATA	12
	/* Register Bit MASKS for GPIO_GPIO_GPSTR */
	#define BMSK_GPIO_GPIO_GPSTR_RESERVED	0xfffff000 /*  */
	#define BMSK_GPIO_GPIO_GPSTR_GPIO_DATA	0x00000fff /*  */
	/* Register BITFIELD for GPIO_GPIO_GPSTR - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_GPSTR_RESERVED	 0x000c, 12, 20, 0xfffff000
	#define BITFIELD_GPIO_GPIO_GPSTR_GPIO_DATA	 0x000c, 0, 12, 0x00000fff
#define ROFF_GPIO_GPIO_GPIT1R0	0x10 /* GPIO 0:7 interrupt type and control register. */ 
	#define BITFIELD_GPIO_GPIO_GPIT1R0	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_GPIT1R0 */
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP7	28
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP6	24
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP5	20
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP4	16
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP3	12
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP2	8
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP1	4
	#define BLSB_GPIO_GPIO_GPIT1R0_GPIO_TYP0	0
	/* Register Bit Widths for GPIO_GPIO_GPIT1R0 */
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP7	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP6	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP5	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP4	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP3	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP2	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP1	4
	#define BWID_GPIO_GPIO_GPIT1R0_GPIO_TYP0	4
	/* Register Bit MASKS for GPIO_GPIO_GPIT1R0 */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP7	0xf0000000 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP6	0x0f000000 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP5	0x00f00000 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP4	0x000f0000 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP3	0x0000f000 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP2	0x00000f00 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP1	0x000000f0 /*  */
	#define BMSK_GPIO_GPIO_GPIT1R0_GPIO_TYP0	0x0000000f /*  */
	/* Register BITFIELD for GPIO_GPIO_GPIT1R0 - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP7	 0x0010, 28, 4, 0xf0000000
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP6	 0x0010, 24, 4, 0x0f000000
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP5	 0x0010, 20, 4, 0x00f00000
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP4	 0x0010, 16, 4, 0x000f0000
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP3	 0x0010, 12, 4, 0x0000f000
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP2	 0x0010, 8, 4, 0x00000f00
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP1	 0x0010, 4, 4, 0x000000f0
	#define BITFIELD_GPIO_GPIO_GPIT1R0_GPIO_TYP0	 0x0010, 0, 4, 0x0000000f
#define ROFF_GPIO_GPIO_INT	0x14 /* GPIO interrupt register. */ 
	#define BITFIELD_GPIO_GPIO_INT	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_INT */
	#define BLSB_GPIO_GPIO_INT_RESERVED	12
	#define BLSB_GPIO_GPIO_INT_GPIO_DATA	0
	/* Register Bit Widths for GPIO_GPIO_INT */
	#define BWID_GPIO_GPIO_INT_RESERVED	20
	#define BWID_GPIO_GPIO_INT_GPIO_DATA	12
	/* Register Bit MASKS for GPIO_GPIO_INT */
	#define BMSK_GPIO_GPIO_INT_RESERVED	0xfffff000 /*  */
	#define BMSK_GPIO_GPIO_INT_GPIO_DATA	0x00000fff /*  */
	/* Register BITFIELD for GPIO_GPIO_INT - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_INT_RESERVED	 0x0014, 12, 20, 0xfffff000
	#define BITFIELD_GPIO_GPIO_INT_GPIO_DATA	 0x0014, 0, 12, 0x00000fff
#define ROFF_GPIO_GPIO_GPIT1R1	0x18 /* GPIO 8:11 interrupt type and control register. */ 
	#define BITFIELD_GPIO_GPIO_GPIT1R1	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GPIO_GPIO_MUX_CNTL	0x1c /* GPIO mux control register. */ 
	#define BITFIELD_GPIO_GPIO_MUX_CNTL	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for GPIO_GPIO_MUX_CNTL */
	#define BLSB_GPIO_GPIO_MUX_CNTL_RESERVED	7
	#define BLSB_GPIO_GPIO_MUX_CNTL_EXT_TS_MUX_CNTL	6
	#define BLSB_GPIO_GPIO_MUX_CNTL_GBE_LINK_MUX_CNTL	5
	#define BLSB_GPIO_GPIO_MUX_CNTL_SC0_MUX_CTNL	4
	#define BLSB_GPIO_GPIO_MUX_CNTL_PUNIT_MUX_CNTL	3
	#define BLSB_GPIO_GPIO_MUX_CNTL_SC1_MUX_CNTL	2
	#define BLSB_GPIO_GPIO_MUX_CNTL_UART1_MUX_CNTL	1
	#define BLSB_GPIO_GPIO_MUX_CNTL_UART0_MUX_CNTL	0
	/* Register Bit Widths for GPIO_GPIO_MUX_CNTL */
	#define BWID_GPIO_GPIO_MUX_CNTL_RESERVED	25
	#define BWID_GPIO_GPIO_MUX_CNTL_EXT_TS_MUX_CNTL	1
	#define BWID_GPIO_GPIO_MUX_CNTL_GBE_LINK_MUX_CNTL	1
	#define BWID_GPIO_GPIO_MUX_CNTL_SC0_MUX_CTNL	1
	#define BWID_GPIO_GPIO_MUX_CNTL_PUNIT_MUX_CNTL	1
	#define BWID_GPIO_GPIO_MUX_CNTL_SC1_MUX_CNTL	1
	#define BWID_GPIO_GPIO_MUX_CNTL_UART1_MUX_CNTL	1
	#define BWID_GPIO_GPIO_MUX_CNTL_UART0_MUX_CNTL	1
	/* Register Bit MASKS for GPIO_GPIO_MUX_CNTL */
	#define BMSK_GPIO_GPIO_MUX_CNTL_RESERVED	0xffffff80 /*  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_EXT_TS_MUX_CNTL	(1<<6) /* == 0x00000040:  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_GBE_LINK_MUX_CNTL	(1<<5) /* == 0x00000020:  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_SC0_MUX_CTNL	(1<<4) /* == 0x00000010:  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_PUNIT_MUX_CNTL	(1<<3) /* == 0x00000008:  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_SC1_MUX_CNTL	(1<<2) /* == 0x00000004:  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_UART1_MUX_CNTL	(1<<1) /* == 0x00000002:  */
	#define BMSK_GPIO_GPIO_MUX_CNTL_UART0_MUX_CNTL	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for GPIO_GPIO_MUX_CNTL - roff, lsb, width, mask */
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_RESERVED	 0x001c, 7, 25, 0xffffff80
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_EXT_TS_MUX_CNTL	 0x001c, 6, 1, 0x00000040
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_GBE_LINK_MUX_CNTL	 0x001c, 5, 1, 0x00000020
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_SC0_MUX_CTNL	 0x001c, 4, 1, 0x00000010
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_PUNIT_MUX_CNTL	 0x001c, 3, 1, 0x00000008
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_SC1_MUX_CNTL	 0x001c, 2, 1, 0x00000004
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_UART1_MUX_CNTL	 0x001c, 1, 1, 0x00000002
	#define BITFIELD_GPIO_GPIO_MUX_CNTL_UART0_MUX_CNTL	 0x001c, 0, 1, 0x00000001


/* Module GPIO SPECIFIC SVEN Events */




#endif /* GPIO_REGOFFS_H */
