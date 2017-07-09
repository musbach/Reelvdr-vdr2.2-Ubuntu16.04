#ifndef I2C_REGOFFS_H
#define I2C_REGOFFS_H 1
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


/* Module I2C CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_I2C_ICR_0	0x0 /* I2C0 Control Register */ 
	#define BITFIELD_I2C_ICR_0	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ISR_0	0x4 /* I2C0 Status Register */ 
	#define BITFIELD_I2C_ISR_0	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ISAR_0	0x8 /* I2C0 Slave Address Register */ 
	#define BITFIELD_I2C_ISAR_0	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_IDBR_0	0xc /* I2C0 Data Buffer Register */ 
	#define BITFIELD_I2C_IDBR_0	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ICCR_0	0x10 /* I2C0 Clock Control Register */ 
	#define BITFIELD_I2C_ICCR_0	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_IBMR_0	0x14 /* I2C0 Bus Monitor Register */ 
	#define BITFIELD_I2C_IBMR_0	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ICR_1	0x20 /* I2C1 Control Register */ 
	#define BITFIELD_I2C_ICR_1	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ISR_1	0x24 /* I2C1 Status Register */ 
	#define BITFIELD_I2C_ISR_1	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ISAR_1	0x28 /* I2C1 Slave Address Register */ 
	#define BITFIELD_I2C_ISAR_1	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_IDBR_1	0x2c /* I2C1 Data Buffer Register */ 
	#define BITFIELD_I2C_IDBR_1	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ICCR_1	0x30 /* I2C1 Clock Control Register */ 
	#define BITFIELD_I2C_ICCR_1	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_IBMR_1	0x34 /* I2C1 Bus Monitor Register */ 
	#define BITFIELD_I2C_IBMR_1	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ICR_2	0x40 /* I2C2 Control Register */ 
	#define BITFIELD_I2C_ICR_2	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ISR_2	0x44 /* I2C2 Status Register */ 
	#define BITFIELD_I2C_ISR_2	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ISAR_2	0x48 /* I2C2 Slave Address Register */ 
	#define BITFIELD_I2C_ISAR_2	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_IDBR_2	0x4c /* I2C2 Data Buffer Register */ 
	#define BITFIELD_I2C_IDBR_2	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_ICCR_2	0x50 /* I2C2 Clock Control Register */ 
	#define BITFIELD_I2C_ICCR_2	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_I2C_IBMR_2	0x54 /* I2C2 Bus Monitor Register */ 
	#define BITFIELD_I2C_IBMR_2	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module I2C SPECIFIC SVEN Events */




#endif /* I2C_REGOFFS_H */
