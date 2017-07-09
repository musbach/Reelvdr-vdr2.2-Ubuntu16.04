#ifndef EXPBUS_REGOFFS_H
#define EXPBUS_REGOFFS_H 1
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


/* Module EXPBUS CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_EXPBUS_EXP_TIMING_CS0	0x0 /* Timing & Control Register for Chip Select 0 */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS0	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS1	0x4 /* Timing & Control Register for Chip Select 1 */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS1	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS2	0x8 /* Timing & Control Register for Chip Select 2 */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS2	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS3	0xc /* Timing & Control Register for Chip Select 3  */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS3	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS4	0x10 /* Timing & Control Register for Chip Select 4  */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS4	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS5	0x14 /* Timing & Control Register for Chip Select 5 */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS5	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS6	0x18 /* Timing & Control Register for Chip Select 6 */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS6	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_EXP_TIMING_CS7	0x1c /* Timing & Control Register for Chip Select 7 */ 
	#define BITFIELD_EXPBUS_EXP_TIMING_CS7	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_NAND_CMD	0x30 /* NAND Memory interface Command and Mode Register */ 
	#define BITFIELD_EXPBUS_NAND_CMD	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_EXPBUS_NAND_ADDR	0x34 /* NAND Memory interface Address and Action Register */ 
	#define BITFIELD_EXPBUS_NAND_ADDR	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module EXPBUS SPECIFIC SVEN Events */




#endif /* EXPBUS_REGOFFS_H */
