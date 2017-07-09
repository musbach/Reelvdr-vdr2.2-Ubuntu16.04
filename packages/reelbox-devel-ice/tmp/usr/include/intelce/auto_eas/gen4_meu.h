#ifndef MEU_REGOFFS_H
#define MEU_REGOFFS_H 1
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


/* Module MEU CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_MEU_STATUS	0x0 /* MEU Status Register */ 
	#define BITFIELD_MEU_STATUS	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_STATUS */
	#define BLSB_MEU_STATUS_RESERVED	7
	#define BLSB_MEU_STATUS_MEU_PRCSS_HEAD	6
	#define BLSB_MEU_STATUS_MEU_PRCSS_BODY	5
	#define BLSB_MEU_STATUS_MEU_PRCSS_TAIL	4
	#define BLSB_MEU_STATUS_MEU_RD_CMD	3
	#define BLSB_MEU_STATUS_MEU_REGION_ZERO	2
	#define BLSB_MEU_STATUS_MEU_BUSY	1
	#define BLSB_MEU_STATUS_MEU_AES_BUSY	0
	/* Register Bit Widths for MEU_STATUS */
	#define BWID_MEU_STATUS_RESERVED	32
	#define BWID_MEU_STATUS_MEU_PRCSS_HEAD	7
	#define BWID_MEU_STATUS_MEU_PRCSS_BODY	6
	#define BWID_MEU_STATUS_MEU_PRCSS_TAIL	5
	#define BWID_MEU_STATUS_MEU_RD_CMD	4
	#define BWID_MEU_STATUS_MEU_REGION_ZERO	3
	#define BWID_MEU_STATUS_MEU_BUSY	2
	#define BWID_MEU_STATUS_MEU_AES_BUSY	1
	/* Register Bit MASKS for MEU_STATUS */
	#define BMSK_MEU_STATUS_RESERVED	0x00000000 /* Reserved */
	#define BMSK_MEU_STATUS_MEU_PRCSS_HEAD	0x00001fc0 /* Statemachine signal indicates read-decrypt-modify-encrypt-write on header portion of writes */
	#define BMSK_MEU_STATUS_MEU_PRCSS_BODY	0x000007e0 /* Statemachine signal indicates processing of the body of the transaction */
	#define BMSK_MEU_STATUS_MEU_PRCSS_TAIL	0x000001f0 /*  */
	#define BMSK_MEU_STATUS_MEU_RD_CMD	0x00000078 /*  */
	#define BMSK_MEU_STATUS_MEU_REGION_ZERO	0x0000001c /*  */
	#define BMSK_MEU_STATUS_MEU_BUSY	0x00000006 /*  */
	#define BMSK_MEU_STATUS_MEU_AES_BUSY	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MEU_STATUS - roff, lsb, width, mask */
	#define BITFIELD_MEU_STATUS_RESERVED	 0x0000, 7, 32, 0x00000000
	#define BITFIELD_MEU_STATUS_MEU_PRCSS_HEAD	 0x0000, 6, 7, 0x00001fc0
	#define BITFIELD_MEU_STATUS_MEU_PRCSS_BODY	 0x0000, 5, 6, 0x000007e0
	#define BITFIELD_MEU_STATUS_MEU_PRCSS_TAIL	 0x0000, 4, 5, 0x000001f0
	#define BITFIELD_MEU_STATUS_MEU_RD_CMD	 0x0000, 3, 4, 0x00000078
	#define BITFIELD_MEU_STATUS_MEU_REGION_ZERO	 0x0000, 2, 3, 0x0000001c
	#define BITFIELD_MEU_STATUS_MEU_BUSY	 0x0000, 1, 2, 0x00000006
	#define BITFIELD_MEU_STATUS_MEU_AES_BUSY	 0x0000, 0, 1, 0x00000001
#define ROFF_MEU_CONTROL	0x8 /* MEU Control Register */ 
	#define BITFIELD_MEU_CONTROL	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_CONTROL */
	#define BLSB_MEU_CONTROL_RESERVED	1
	#define BLSB_MEU_CONTROL_MEU_LOCK_KEYS	0
	/* Register Bit Widths for MEU_CONTROL */
	#define BWID_MEU_CONTROL_RESERVED	32
	#define BWID_MEU_CONTROL_MEU_LOCK_KEYS	1
	/* Register Bit MASKS for MEU_CONTROL */
	#define BMSK_MEU_CONTROL_RESERVED	0x00000000 /*  */
	#define BMSK_MEU_CONTROL_MEU_LOCK_KEYS	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MEU_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_MEU_CONTROL_RESERVED	 0x0008, 1, 32, 0x00000000
	#define BITFIELD_MEU_CONTROL_MEU_LOCK_KEYS	 0x0008, 0, 1, 0x00000001
#define ROFF_MEU_MEU_AES0_ENC_KEY0	0x10 /* AES0 Encryption Key[31:0] */ 
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY0	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_ENC_KEY0 */
	#define BLSB_MEU_MEU_AES0_ENC_KEY0_MEU_AES0_ENC_KEY0	0
	/* Register Bit Widths for MEU_MEU_AES0_ENC_KEY0 */
	#define BWID_MEU_MEU_AES0_ENC_KEY0_MEU_AES0_ENC_KEY0	32
	/* Register Bit MASKS for MEU_MEU_AES0_ENC_KEY0 */
	#define BMSK_MEU_MEU_AES0_ENC_KEY0_MEU_AES0_ENC_KEY0	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_ENC_KEY0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY0_MEU_AES0_ENC_KEY0	 0x0010, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_ENC_KEY1	0x14 /* AES0 Encryption Key[63:32] */ 
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY1	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_ENC_KEY1 */
	#define BLSB_MEU_MEU_AES0_ENC_KEY1_MEU_AES0_ENC_KEY1	0
	/* Register Bit Widths for MEU_MEU_AES0_ENC_KEY1 */
	#define BWID_MEU_MEU_AES0_ENC_KEY1_MEU_AES0_ENC_KEY1	32
	/* Register Bit MASKS for MEU_MEU_AES0_ENC_KEY1 */
	#define BMSK_MEU_MEU_AES0_ENC_KEY1_MEU_AES0_ENC_KEY1	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_ENC_KEY1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY1_MEU_AES0_ENC_KEY1	 0x0014, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_ENC_KEY2	0x18 /* AES0 Encryption Key[95:64] */ 
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY2	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_ENC_KEY2 */
	#define BLSB_MEU_MEU_AES0_ENC_KEY2_MEU_AES0_ENC_KEY2	0
	/* Register Bit Widths for MEU_MEU_AES0_ENC_KEY2 */
	#define BWID_MEU_MEU_AES0_ENC_KEY2_MEU_AES0_ENC_KEY2	32
	/* Register Bit MASKS for MEU_MEU_AES0_ENC_KEY2 */
	#define BMSK_MEU_MEU_AES0_ENC_KEY2_MEU_AES0_ENC_KEY2	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_ENC_KEY2 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY2_MEU_AES0_ENC_KEY2	 0x0018, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_ENC_KEY3	0x1c /* AES0 Encryption Key[127:96] */ 
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY3	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_ENC_KEY3 */
	#define BLSB_MEU_MEU_AES0_ENC_KEY3_MEU_AES0_ENC_KEY3	0
	/* Register Bit Widths for MEU_MEU_AES0_ENC_KEY3 */
	#define BWID_MEU_MEU_AES0_ENC_KEY3_MEU_AES0_ENC_KEY3	32
	/* Register Bit MASKS for MEU_MEU_AES0_ENC_KEY3 */
	#define BMSK_MEU_MEU_AES0_ENC_KEY3_MEU_AES0_ENC_KEY3	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_ENC_KEY3 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_ENC_KEY3_MEU_AES0_ENC_KEY3	 0x001c, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_DEC_KEY0	0x20 /* AES0 Decryption Key[31:0] */ 
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY0	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_DEC_KEY0 */
	#define BLSB_MEU_MEU_AES0_DEC_KEY0_MEU_AES0_ENC_KEY0	0
	/* Register Bit Widths for MEU_MEU_AES0_DEC_KEY0 */
	#define BWID_MEU_MEU_AES0_DEC_KEY0_MEU_AES0_ENC_KEY0	32
	/* Register Bit MASKS for MEU_MEU_AES0_DEC_KEY0 */
	#define BMSK_MEU_MEU_AES0_DEC_KEY0_MEU_AES0_ENC_KEY0	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_DEC_KEY0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY0_MEU_AES0_ENC_KEY0	 0x0020, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_DEC_KEY1	0x24 /* AES0 Decryption Key[63:32] */ 
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY1	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_DEC_KEY1 */
	#define BLSB_MEU_MEU_AES0_DEC_KEY1_MEU_AES0_ENC_KEY1	0
	/* Register Bit Widths for MEU_MEU_AES0_DEC_KEY1 */
	#define BWID_MEU_MEU_AES0_DEC_KEY1_MEU_AES0_ENC_KEY1	32
	/* Register Bit MASKS for MEU_MEU_AES0_DEC_KEY1 */
	#define BMSK_MEU_MEU_AES0_DEC_KEY1_MEU_AES0_ENC_KEY1	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_DEC_KEY1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY1_MEU_AES0_ENC_KEY1	 0x0024, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_DEC_KEY2	0x28 /* AES0 Decryption Key[95:64] */ 
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY2	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_DEC_KEY2 */
	#define BLSB_MEU_MEU_AES0_DEC_KEY2_MEU_AES0_ENC_KEY2	0
	/* Register Bit Widths for MEU_MEU_AES0_DEC_KEY2 */
	#define BWID_MEU_MEU_AES0_DEC_KEY2_MEU_AES0_ENC_KEY2	32
	/* Register Bit MASKS for MEU_MEU_AES0_DEC_KEY2 */
	#define BMSK_MEU_MEU_AES0_DEC_KEY2_MEU_AES0_ENC_KEY2	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_DEC_KEY2 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY2_MEU_AES0_ENC_KEY2	 0x0028, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES0_DEC_KEY3	0x2c /* AES0 Decryption Key[127:96] */ 
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY3	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES0_DEC_KEY3 */
	#define BLSB_MEU_MEU_AES0_DEC_KEY3_MEU_AES0_ENC_KEY3	0
	/* Register Bit Widths for MEU_MEU_AES0_DEC_KEY3 */
	#define BWID_MEU_MEU_AES0_DEC_KEY3_MEU_AES0_ENC_KEY3	32
	/* Register Bit MASKS for MEU_MEU_AES0_DEC_KEY3 */
	#define BMSK_MEU_MEU_AES0_DEC_KEY3_MEU_AES0_ENC_KEY3	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES0_DEC_KEY3 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES0_DEC_KEY3_MEU_AES0_ENC_KEY3	 0x002c, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_ENC_KEY0	0x30 /* AES1 Encryption Key[31:0] */ 
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY0	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_ENC_KEY0 */
	#define BLSB_MEU_MEU_AES1_ENC_KEY0_MEU_AES1_ENC_KEY0	0
	/* Register Bit Widths for MEU_MEU_AES1_ENC_KEY0 */
	#define BWID_MEU_MEU_AES1_ENC_KEY0_MEU_AES1_ENC_KEY0	32
	/* Register Bit MASKS for MEU_MEU_AES1_ENC_KEY0 */
	#define BMSK_MEU_MEU_AES1_ENC_KEY0_MEU_AES1_ENC_KEY0	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_ENC_KEY0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY0_MEU_AES1_ENC_KEY0	 0x0030, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_ENC_KEY1	0x34 /* AES1 Encryption Key[63:32] */ 
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY1	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_ENC_KEY1 */
	#define BLSB_MEU_MEU_AES1_ENC_KEY1_MEU_AES1_ENC_KEY1	0
	/* Register Bit Widths for MEU_MEU_AES1_ENC_KEY1 */
	#define BWID_MEU_MEU_AES1_ENC_KEY1_MEU_AES1_ENC_KEY1	32
	/* Register Bit MASKS for MEU_MEU_AES1_ENC_KEY1 */
	#define BMSK_MEU_MEU_AES1_ENC_KEY1_MEU_AES1_ENC_KEY1	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_ENC_KEY1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY1_MEU_AES1_ENC_KEY1	 0x0034, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_ENC_KEY2	0x38 /* AES1 Encryption Key[95:64] */ 
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY2	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_ENC_KEY2 */
	#define BLSB_MEU_MEU_AES1_ENC_KEY2_MEU_AES1_ENC_KEY2	0
	/* Register Bit Widths for MEU_MEU_AES1_ENC_KEY2 */
	#define BWID_MEU_MEU_AES1_ENC_KEY2_MEU_AES1_ENC_KEY2	32
	/* Register Bit MASKS for MEU_MEU_AES1_ENC_KEY2 */
	#define BMSK_MEU_MEU_AES1_ENC_KEY2_MEU_AES1_ENC_KEY2	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_ENC_KEY2 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY2_MEU_AES1_ENC_KEY2	 0x0038, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_ENC_KEY3	0x3c /* AES1 Encryption Key[127:96] */ 
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY3	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_ENC_KEY3 */
	#define BLSB_MEU_MEU_AES1_ENC_KEY3_MEU_AES1_ENC_KEY3	0
	/* Register Bit Widths for MEU_MEU_AES1_ENC_KEY3 */
	#define BWID_MEU_MEU_AES1_ENC_KEY3_MEU_AES1_ENC_KEY3	32
	/* Register Bit MASKS for MEU_MEU_AES1_ENC_KEY3 */
	#define BMSK_MEU_MEU_AES1_ENC_KEY3_MEU_AES1_ENC_KEY3	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_ENC_KEY3 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_ENC_KEY3_MEU_AES1_ENC_KEY3	 0x003c, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_DEC_KEY0	0x40 /* AES1 Decryption Key[31:0] */ 
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY0	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_DEC_KEY0 */
	#define BLSB_MEU_MEU_AES1_DEC_KEY0_MEU_AES1_ENC_KEY0	0
	/* Register Bit Widths for MEU_MEU_AES1_DEC_KEY0 */
	#define BWID_MEU_MEU_AES1_DEC_KEY0_MEU_AES1_ENC_KEY0	32
	/* Register Bit MASKS for MEU_MEU_AES1_DEC_KEY0 */
	#define BMSK_MEU_MEU_AES1_DEC_KEY0_MEU_AES1_ENC_KEY0	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_DEC_KEY0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY0_MEU_AES1_ENC_KEY0	 0x0040, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_DEC_KEY1	0x44 /* AES1 Decryption Key[63:32] */ 
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY1	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_DEC_KEY1 */
	#define BLSB_MEU_MEU_AES1_DEC_KEY1_MEU_AES1_ENC_KEY1	0
	/* Register Bit Widths for MEU_MEU_AES1_DEC_KEY1 */
	#define BWID_MEU_MEU_AES1_DEC_KEY1_MEU_AES1_ENC_KEY1	32
	/* Register Bit MASKS for MEU_MEU_AES1_DEC_KEY1 */
	#define BMSK_MEU_MEU_AES1_DEC_KEY1_MEU_AES1_ENC_KEY1	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_DEC_KEY1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY1_MEU_AES1_ENC_KEY1	 0x0044, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_DEC_KEY2	0x48 /* AES1 Decryption Key[95:64] */ 
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY2	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_DEC_KEY2 */
	#define BLSB_MEU_MEU_AES1_DEC_KEY2_MEU_AES1_ENC_KEY2	0
	/* Register Bit Widths for MEU_MEU_AES1_DEC_KEY2 */
	#define BWID_MEU_MEU_AES1_DEC_KEY2_MEU_AES1_ENC_KEY2	32
	/* Register Bit MASKS for MEU_MEU_AES1_DEC_KEY2 */
	#define BMSK_MEU_MEU_AES1_DEC_KEY2_MEU_AES1_ENC_KEY2	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_DEC_KEY2 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY2_MEU_AES1_ENC_KEY2	 0x0048, 0, 32, 0x00000000
#define ROFF_MEU_MEU_AES1_DEC_KEY3	0x4c /* AES1 Decryption Key[127:96] */ 
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY3	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_AES1_DEC_KEY3 */
	#define BLSB_MEU_MEU_AES1_DEC_KEY3_MEU_AES1_ENC_KEY3	0
	/* Register Bit Widths for MEU_MEU_AES1_DEC_KEY3 */
	#define BWID_MEU_MEU_AES1_DEC_KEY3_MEU_AES1_ENC_KEY3	32
	/* Register Bit MASKS for MEU_MEU_AES1_DEC_KEY3 */
	#define BMSK_MEU_MEU_AES1_DEC_KEY3_MEU_AES1_ENC_KEY3	0x00000000 /*  */
	/* Register BITFIELD for MEU_MEU_AES1_DEC_KEY3 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_AES1_DEC_KEY3_MEU_AES1_ENC_KEY3	 0x004c, 0, 32, 0x00000000
#define ROFF_MEU_MEU_ATU_SRC_BASE0	0x50 /* ATU Source Base register 0 */ 
	#define BITFIELD_MEU_MEU_ATU_SRC_BASE0	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_ATU_SRC_BASE0 */
	#define BLSB_MEU_MEU_ATU_SRC_BASE0_MEU_ATU_SRC_BASE	12
	#define BLSB_MEU_MEU_ATU_SRC_BASE0_RESERVED	0
	/* Register Bit Widths for MEU_MEU_ATU_SRC_BASE0 */
	#define BWID_MEU_MEU_ATU_SRC_BASE0_MEU_ATU_SRC_BASE	32
	#define BWID_MEU_MEU_ATU_SRC_BASE0_RESERVED	12
	/* Register Bit MASKS for MEU_MEU_ATU_SRC_BASE0 */
	#define BMSK_MEU_MEU_ATU_SRC_BASE0_MEU_ATU_SRC_BASE	0x00000000 /*  */
	#define BMSK_MEU_MEU_ATU_SRC_BASE0_RESERVED	0x00000fff /*  */
	/* Register BITFIELD for MEU_MEU_ATU_SRC_BASE0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_ATU_SRC_BASE0_MEU_ATU_SRC_BASE	 0x0050, 12, 32, 0x00000000
	#define BITFIELD_MEU_MEU_ATU_SRC_BASE0_RESERVED	 0x0050, 0, 12, 0x00000fff
#define ROFF_MEU_MEU_ATU_DST_BASE0	0x54 /* ATU Destination Base register 0 */ 
	#define BITFIELD_MEU_MEU_ATU_DST_BASE0	 0x0054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_ATU_DST_BASE0 */
	#define BLSB_MEU_MEU_ATU_DST_BASE0_MEU_ATU_DST_BASE	12
	#define BLSB_MEU_MEU_ATU_DST_BASE0_RESERVED	0
	/* Register Bit Widths for MEU_MEU_ATU_DST_BASE0 */
	#define BWID_MEU_MEU_ATU_DST_BASE0_MEU_ATU_DST_BASE	32
	#define BWID_MEU_MEU_ATU_DST_BASE0_RESERVED	12
	/* Register Bit MASKS for MEU_MEU_ATU_DST_BASE0 */
	#define BMSK_MEU_MEU_ATU_DST_BASE0_MEU_ATU_DST_BASE	0x00000000 /*  */
	#define BMSK_MEU_MEU_ATU_DST_BASE0_RESERVED	0x00000fff /*  */
	/* Register BITFIELD for MEU_MEU_ATU_DST_BASE0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_ATU_DST_BASE0_MEU_ATU_DST_BASE	 0x0054, 12, 32, 0x00000000
	#define BITFIELD_MEU_MEU_ATU_DST_BASE0_RESERVED	 0x0054, 0, 12, 0x00000fff
#define ROFF_MEU_MEU_ATU_ADDR_MASK0	0x58 /* ATU Address Mask register 0 */ 
	#define BITFIELD_MEU_MEU_ATU_ADDR_MASK0	 0x0058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_ATU_ADDR_MASK0 */
	#define BLSB_MEU_MEU_ATU_ADDR_MASK0_MEU_ATU_MASK	12
	#define BLSB_MEU_MEU_ATU_ADDR_MASK0_RESERVED	0
	/* Register Bit Widths for MEU_MEU_ATU_ADDR_MASK0 */
	#define BWID_MEU_MEU_ATU_ADDR_MASK0_MEU_ATU_MASK	32
	#define BWID_MEU_MEU_ATU_ADDR_MASK0_RESERVED	12
	/* Register Bit MASKS for MEU_MEU_ATU_ADDR_MASK0 */
	#define BMSK_MEU_MEU_ATU_ADDR_MASK0_MEU_ATU_MASK	0x00000000 /*  */
	#define BMSK_MEU_MEU_ATU_ADDR_MASK0_RESERVED	0x00000fff /*  */
	/* Register BITFIELD for MEU_MEU_ATU_ADDR_MASK0 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_ATU_ADDR_MASK0_MEU_ATU_MASK	 0x0058, 12, 32, 0x00000000
	#define BITFIELD_MEU_MEU_ATU_ADDR_MASK0_RESERVED	 0x0058, 0, 12, 0x00000fff
#define ROFF_MEU_MEU_ATU_SRC_BASE1	0x60 /* ATU Source Base register 1 */ 
	#define BITFIELD_MEU_MEU_ATU_SRC_BASE1	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_ATU_SRC_BASE1 */
	#define BLSB_MEU_MEU_ATU_SRC_BASE1_MEU_ATU_SRC_BASE	12
	#define BLSB_MEU_MEU_ATU_SRC_BASE1_RESERVED	0
	/* Register Bit Widths for MEU_MEU_ATU_SRC_BASE1 */
	#define BWID_MEU_MEU_ATU_SRC_BASE1_MEU_ATU_SRC_BASE	32
	#define BWID_MEU_MEU_ATU_SRC_BASE1_RESERVED	12
	/* Register Bit MASKS for MEU_MEU_ATU_SRC_BASE1 */
	#define BMSK_MEU_MEU_ATU_SRC_BASE1_MEU_ATU_SRC_BASE	0x00000000 /*  */
	#define BMSK_MEU_MEU_ATU_SRC_BASE1_RESERVED	0x00000fff /*  */
	/* Register BITFIELD for MEU_MEU_ATU_SRC_BASE1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_ATU_SRC_BASE1_MEU_ATU_SRC_BASE	 0x0060, 12, 32, 0x00000000
	#define BITFIELD_MEU_MEU_ATU_SRC_BASE1_RESERVED	 0x0060, 0, 12, 0x00000fff
#define ROFF_MEU_MEU_ATU_DST_BASE1	0x64 /* ATU Destination Base register 1 */ 
	#define BITFIELD_MEU_MEU_ATU_DST_BASE1	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_ATU_DST_BASE1 */
	#define BLSB_MEU_MEU_ATU_DST_BASE1_MEU_ATU_DST_BASE	12
	#define BLSB_MEU_MEU_ATU_DST_BASE1_RESERVED	0
	/* Register Bit Widths for MEU_MEU_ATU_DST_BASE1 */
	#define BWID_MEU_MEU_ATU_DST_BASE1_MEU_ATU_DST_BASE	32
	#define BWID_MEU_MEU_ATU_DST_BASE1_RESERVED	12
	/* Register Bit MASKS for MEU_MEU_ATU_DST_BASE1 */
	#define BMSK_MEU_MEU_ATU_DST_BASE1_MEU_ATU_DST_BASE	0x00000000 /*  */
	#define BMSK_MEU_MEU_ATU_DST_BASE1_RESERVED	0x00000fff /*  */
	/* Register BITFIELD for MEU_MEU_ATU_DST_BASE1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_ATU_DST_BASE1_MEU_ATU_DST_BASE	 0x0064, 12, 32, 0x00000000
	#define BITFIELD_MEU_MEU_ATU_DST_BASE1_RESERVED	 0x0064, 0, 12, 0x00000fff
#define ROFF_MEU_MEU_ATU_ADDR_MASK1	0x68 /* ATU Address Mask register 1 */ 
	#define BITFIELD_MEU_MEU_ATU_ADDR_MASK1	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MEU_MEU_ATU_ADDR_MASK1 */
	#define BLSB_MEU_MEU_ATU_ADDR_MASK1_MEU_ATU_MASK	12
	#define BLSB_MEU_MEU_ATU_ADDR_MASK1_RESERVED	0
	/* Register Bit Widths for MEU_MEU_ATU_ADDR_MASK1 */
	#define BWID_MEU_MEU_ATU_ADDR_MASK1_MEU_ATU_MASK	32
	#define BWID_MEU_MEU_ATU_ADDR_MASK1_RESERVED	12
	/* Register Bit MASKS for MEU_MEU_ATU_ADDR_MASK1 */
	#define BMSK_MEU_MEU_ATU_ADDR_MASK1_MEU_ATU_MASK	0x00000000 /*  */
	#define BMSK_MEU_MEU_ATU_ADDR_MASK1_RESERVED	0x00000fff /*  */
	/* Register BITFIELD for MEU_MEU_ATU_ADDR_MASK1 - roff, lsb, width, mask */
	#define BITFIELD_MEU_MEU_ATU_ADDR_MASK1_MEU_ATU_MASK	 0x0068, 12, 32, 0x00000000
	#define BITFIELD_MEU_MEU_ATU_ADDR_MASK1_RESERVED	 0x0068, 0, 12, 0x00000fff


/* Module MEU SPECIFIC SVEN Events */




#endif /* MEU_REGOFFS_H */
