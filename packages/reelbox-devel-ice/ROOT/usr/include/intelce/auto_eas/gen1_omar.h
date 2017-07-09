#ifndef OMAR_REGOFFS_H
#define OMAR_REGOFFS_H 1
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


/* Module OMAR CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_OMAR_CONTROL	0x0 /* Control Register */ 
	#define BITFIELD_OMAR_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for OMAR_CONTROL */
	#define BLSB_OMAR_CONTROL_RESERVED	1
	#define BLSB_OMAR_CONTROL_ENABLE	0
	/* Register Bit Widths for OMAR_CONTROL */
	#define BWID_OMAR_CONTROL_RESERVED	30
	#define BWID_OMAR_CONTROL_ENABLE	1
	/* Register Bit MASKS for OMAR_CONTROL */
	#define BMSK_OMAR_CONTROL_RESERVED	0x7ffffffe /*  */
	#define BMSK_OMAR_CONTROL_ENABLE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for OMAR_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_OMAR_CONTROL_RESERVED	 0x0000, 1, 30, 0x7ffffffe
	#define BITFIELD_OMAR_CONTROL_ENABLE	 0x0000, 0, 1, 0x00000001
#define ROFF_OMAR_STATUS	0x4 /* Status */ 
	#define BITFIELD_OMAR_STATUS	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_INTERVAL_COUNT	0x8 /* Sample Interval Countdown (XSI clocks) */ 
	#define BITFIELD_OMAR_INTERVAL_COUNT	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_HEADER_WORD	0xc /* (RO) Header Word */ 
	#define BITFIELD_OMAR_HEADER_WORD	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for OMAR_HEADER_WORD */
	#define BLSB_OMAR_HEADER_WORD_HDR_PASS	30
	#define BLSB_OMAR_HEADER_WORD_RESERVED	24
	#define BLSB_OMAR_HEADER_WORD_HDR_SAMP	0
	/* Register Bit Widths for OMAR_HEADER_WORD */
	#define BWID_OMAR_HEADER_WORD_HDR_PASS	2
	#define BWID_OMAR_HEADER_WORD_RESERVED	6
	#define BWID_OMAR_HEADER_WORD_HDR_SAMP	24
	/* Register Bit MASKS for OMAR_HEADER_WORD */
	#define BMSK_OMAR_HEADER_WORD_HDR_PASS	0xc0000000 /* Circular Buffer loop count */
	#define BMSK_OMAR_HEADER_WORD_RESERVED	0x3f000000 /*  */
	#define BMSK_OMAR_HEADER_WORD_HDR_SAMP	0x00ffffff /* Sample Counter */
	/* Register BITFIELD for OMAR_HEADER_WORD - roff, lsb, width, mask */
	#define BITFIELD_OMAR_HEADER_WORD_HDR_PASS	 0x000c, 30, 2, 0xc0000000
	#define BITFIELD_OMAR_HEADER_WORD_RESERVED	 0x000c, 24, 6, 0x3f000000
	#define BITFIELD_OMAR_HEADER_WORD_HDR_SAMP	 0x000c, 0, 24, 0x00ffffff
#define ROFF_OMAR_CAP_BASE_ADDR	0x10 /* Capture Buffer Base Address */ 
	#define BITFIELD_OMAR_CAP_BASE_ADDR	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CAP_SIZE	0x14 /* Capture Buffer Size in bytes */ 
	#define BITFIELD_OMAR_CAP_SIZE	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_CAP_CUR_PTR	0x18 /* (RO) Capture Current Pointer */ 
	#define BITFIELD_OMAR_CAP_CUR_PTR	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_RESERVED0	0x1c /* reserved */ 
	#define BITFIELD_OMAR_RESERVED0	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE0	0x20 /* Capture Enable for signals (00-1f) */ 
	#define BITFIELD_OMAR_SIG_ENABLE0	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE1	0x24 /* Capture Enable for signals (20-3f) */ 
	#define BITFIELD_OMAR_SIG_ENABLE1	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE2	0x28 /* Capture Enable for signals (40-5f) */ 
	#define BITFIELD_OMAR_SIG_ENABLE2	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE3	0x2c /* Capture Enable for signals (60-7f) */ 
	#define BITFIELD_OMAR_SIG_ENABLE3	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE4	0x30 /* Capture Enable for signals (80-9f) */ 
	#define BITFIELD_OMAR_SIG_ENABLE4	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE5	0x34 /* Capture Enable for signals (a0-bf) */ 
	#define BITFIELD_OMAR_SIG_ENABLE5	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE6	0x38 /* Capture Enable for signals (c0-df) */ 
	#define BITFIELD_OMAR_SIG_ENABLE6	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SIG_ENABLE7	0x3c /* Capture Enable for signals (e0-ff) */ 
	#define BITFIELD_OMAR_SIG_ENABLE7	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_SET_OR_INC_0	0x80 /* Set-on-Write, Increment-on-Read, counter 0 */ 
	#define BITFIELD_OMAR_SET_OR_INC_0	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_OMAR_ADD_OR_DEC_0	0x84 /* Add-on-Write, Decrement-on-Read, counter 0 */ 
	#define BITFIELD_OMAR_ADD_OR_DEC_0	 0x0084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module OMAR SPECIFIC SVEN Events */




#endif /* OMAR_REGOFFS_H */
