#ifndef TSDEMUX_REGOFFS_H
#define TSDEMUX_REGOFFS_H 1
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


/* Module TSDEMUX CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_TSDEMUX_CRYPTO_CONTROL	0x0 /* Crypto Control Register */ 
	#define BITFIELD_TSDEMUX_CRYPTO_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRYPTO_CONTROL */
	#define BLSB_TSDEMUX_CRYPTO_CONTROL_RESERVED_31_5	5
	#define BLSB_TSDEMUX_CRYPTO_CONTROL_Conformance_mode_select	4
	#define BLSB_TSDEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	0
	/* Register Bit Widths for TSDEMUX_CRYPTO_CONTROL */
	#define BWID_TSDEMUX_CRYPTO_CONTROL_RESERVED_31_5	27
	#define BWID_TSDEMUX_CRYPTO_CONTROL_Conformance_mode_select	1
	#define BWID_TSDEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	4
	/* Register Bit MASKS for TSDEMUX_CRYPTO_CONTROL */
	#define BMSK_TSDEMUX_CRYPTO_CONTROL_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_TSDEMUX_CRYPTO_CONTROL_Conformance_mode_select	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSDEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	0x0000000f /*  */
	/* Register BITFIELD for TSDEMUX_CRYPTO_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRYPTO_CONTROL_RESERVED_31_5	 0x0000, 5, 27, 0xffffffe0
	#define BITFIELD_TSDEMUX_CRYPTO_CONTROL_Conformance_mode_select	 0x0000, 4, 1, 0x00000010
	#define BITFIELD_TSDEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	 0x0000, 0, 4, 0x0000000f
#define ROFF_TSDEMUX_CRYPTO_STATUS	0x4 /* Crypto Status Register */ 
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRYPTO_STATUS */
	#define BLSB_TSDEMUX_CRYPTO_STATUS_RESERVED_31_8	5
	#define BLSB_TSDEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	4
	#define BLSB_TSDEMUX_CRYPTO_STATUS_Invalid_Key	3
	#define BLSB_TSDEMUX_CRYPTO_STATUS_Output_Ready	2
	#define BLSB_TSDEMUX_CRYPTO_STATUS_Input_Ready	1
	#define BLSB_TSDEMUX_CRYPTO_STATUS_Busy	0
	/* Register Bit Widths for TSDEMUX_CRYPTO_STATUS */
	#define BWID_TSDEMUX_CRYPTO_STATUS_RESERVED_31_8	27
	#define BWID_TSDEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	1
	#define BWID_TSDEMUX_CRYPTO_STATUS_Invalid_Key	1
	#define BWID_TSDEMUX_CRYPTO_STATUS_Output_Ready	1
	#define BWID_TSDEMUX_CRYPTO_STATUS_Input_Ready	1
	#define BWID_TSDEMUX_CRYPTO_STATUS_Busy	1
	/* Register Bit MASKS for TSDEMUX_CRYPTO_STATUS */
	#define BMSK_TSDEMUX_CRYPTO_STATUS_RESERVED_31_8	0xffffffe0 /*  */
	#define BMSK_TSDEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	(1<<4) /* == 0x00000010:  */
	#define BMSK_TSDEMUX_CRYPTO_STATUS_Invalid_Key	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSDEMUX_CRYPTO_STATUS_Output_Ready	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSDEMUX_CRYPTO_STATUS_Input_Ready	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_CRYPTO_STATUS_Busy	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_CRYPTO_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS_RESERVED_31_8	 0x0004, 5, 27, 0xffffffe0
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	 0x0004, 4, 1, 0x00000010
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS_Invalid_Key	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS_Output_Ready	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS_Input_Ready	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_CRYPTO_STATUS_Busy	 0x0004, 0, 1, 0x00000001
#define ROFF_TSDEMUX_CRYPTO_IRQ	0x8 /* Crypto IRQ Register */ 
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRYPTO_IRQ */
	#define BLSB_TSDEMUX_CRYPTO_IRQ_RESERVED_31_3	5
	#define BLSB_TSDEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	2
	#define BLSB_TSDEMUX_CRYPTO_IRQ_Output_Ready_IRQ	1
	#define BLSB_TSDEMUX_CRYPTO_IRQ_Input_Ready_IRQ	0
	/* Register Bit Widths for TSDEMUX_CRYPTO_IRQ */
	#define BWID_TSDEMUX_CRYPTO_IRQ_RESERVED_31_3	29
	#define BWID_TSDEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	1
	#define BWID_TSDEMUX_CRYPTO_IRQ_Output_Ready_IRQ	1
	#define BWID_TSDEMUX_CRYPTO_IRQ_Input_Ready_IRQ	1
	/* Register Bit MASKS for TSDEMUX_CRYPTO_IRQ */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_RESERVED_31_3	0xffffffe0 /*  */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_Output_Ready_IRQ	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_Input_Ready_IRQ	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_CRYPTO_IRQ - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_RESERVED_31_3	 0x0008, 5, 29, 0xffffffe0
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	 0x0008, 2, 1, 0x00000004
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_Output_Ready_IRQ	 0x0008, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_Input_Ready_IRQ	 0x0008, 0, 1, 0x00000001
#define ROFF_TSDEMUX_CRYPTO_IRQ_MASK	0xc /* Crypto IRQ_MASK Register */ 
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_MASK	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRYPTO_IRQ_MASK */
	#define BLSB_TSDEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	5
	#define BLSB_TSDEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	2
	#define BLSB_TSDEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	1
	#define BLSB_TSDEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	0
	/* Register Bit Widths for TSDEMUX_CRYPTO_IRQ_MASK */
	#define BWID_TSDEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	29
	#define BWID_TSDEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	1
	#define BWID_TSDEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	1
	#define BWID_TSDEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	1
	/* Register Bit MASKS for TSDEMUX_CRYPTO_IRQ_MASK */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	0xffffffe0 /*  */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_CRYPTO_IRQ_MASK - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	 0x000c, 5, 29, 0xffffffe0
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	 0x000c, 2, 1, 0x00000004
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	 0x000c, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	 0x000c, 0, 1, 0x00000001
#define ROFF_TSDEMUX_CRYPTO_IV_0	0x10 /* Least significant word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_IV_0	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_IV_1	0x14 /* Most significant word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_IV_1	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_RESERVED0	0x18 /* RESERVED */ 
	#define BITFIELD_TSDEMUX_CRYPTO_RESERVED0	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_KEY_0	0x24 /* Least significant word of crypto key */ 
	#define BITFIELD_TSDEMUX_CRYPTO_KEY_0	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_KEY_1	0x28 /* Middle signifiacnt word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_KEY_1	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_KEY_2	0x2c /* Middle signifiacnt word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_KEY_2	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_KEY_3	0x30 /* Middle signifiacnt word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_KEY_3	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_KEY_4	0x34 /* Middle signifiacnt word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_KEY_4	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_KEY_5	0x38 /* Most signifiacnt word */ 
	#define BITFIELD_TSDEMUX_CRYPTO_KEY_5	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_ALGORITHM	0x3c /* Algorithm */ 
	#define BITFIELD_TSDEMUX_CRYPTO_ALGORITHM	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRYPTO_ALGORITHM */
	#define BLSB_TSDEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	5
	#define BLSB_TSDEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	0
	/* Register Bit Widths for TSDEMUX_CRYPTO_ALGORITHM */
	#define BWID_TSDEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	27
	#define BWID_TSDEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	5
	/* Register Bit MASKS for TSDEMUX_CRYPTO_ALGORITHM */
	#define BMSK_TSDEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_TSDEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	0x0000001f /*  */
	/* Register BITFIELD for TSDEMUX_CRYPTO_ALGORITHM - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	 0x003c, 5, 27, 0xffffffe0
	#define BITFIELD_TSDEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	 0x003c, 0, 5, 0x0000001f
#define ROFF_TSDEMUX_CRYPTO_DATAOUT_0	0x40 /* LSB of the result of a crypto operation OUTPUT_READY status flag is asserted */ 
	#define BITFIELD_TSDEMUX_CRYPTO_DATAOUT_0	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRYPTO_DATAOUT_1	0x44 /* MSB of result of crypto operation_OUTPUT_READY FLAG ASSERTED */ 
	#define BITFIELD_TSDEMUX_CRYPTO_DATAOUT_1	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_KEY_ADDR	0x48 /* Selects the current back-door crypto key */ 
	#define BITFIELD_TSDEMUX_KEY_ADDR	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_KEY_ADDR */
	#define BLSB_TSDEMUX_KEY_ADDR_RESERVED_31_3	3
	#define BLSB_TSDEMUX_KEY_ADDR_BackDoor_Key_Address	0
	/* Register Bit Widths for TSDEMUX_KEY_ADDR */
	#define BWID_TSDEMUX_KEY_ADDR_RESERVED_31_3	29
	#define BWID_TSDEMUX_KEY_ADDR_BackDoor_Key_Address	3
	/* Register Bit MASKS for TSDEMUX_KEY_ADDR */
	#define BMSK_TSDEMUX_KEY_ADDR_RESERVED_31_3	0xfffffff8 /*  */
	#define BMSK_TSDEMUX_KEY_ADDR_BackDoor_Key_Address	0x00000007 /*  */
	/* Register BITFIELD for TSDEMUX_KEY_ADDR - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_KEY_ADDR_RESERVED_31_3	 0x0048, 3, 29, 0xfffffff8
	#define BITFIELD_TSDEMUX_KEY_ADDR_BackDoor_Key_Address	 0x0048, 0, 3, 0x00000007
#define ROFF_TSDEMUX_CRYPTO_RESERVED1	0x48 /* Reserved */ 
	#define BITFIELD_TSDEMUX_CRYPTO_RESERVED1	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_CONTROL	0x800 /* Data Shift Control Register */ 
	#define BITFIELD_TSDEMUX_DSR_CONTROL	 0x0800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_STATUS	0x804 /* Data Shift Register */ 
	#define BITFIELD_TSDEMUX_DSR_STATUS	 0x0804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_IRQ	0x808 /* Data Shift IRQ Register */ 
	#define BITFIELD_TSDEMUX_DSR_IRQ	 0x0808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_IRQ_MASK	0x80c /* Data shiftIRQ_MASK Register */ 
	#define BITFIELD_TSDEMUX_DSR_IRQ_MASK	 0x080c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_DATA_03	0x810 /* Data Shift Data_03 Register */ 
	#define BITFIELD_TSDEMUX_DSR_DATA_03	 0x0810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_DATA_47	0x814 /* Data Shift Data_47 Register */ 
	#define BITFIELD_TSDEMUX_DSR_DATA_47	 0x0814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_DATA_8B	0x818 /* Data Shift Data_8B Register */ 
	#define BITFIELD_TSDEMUX_DSR_DATA_8B	 0x0818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_DATA_CF	0x81c /* Data Shift Data_CF Register */ 
	#define BITFIELD_TSDEMUX_DSR_DATA_CF	 0x081c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_DSR_RESERVED	0x820 /* Reserved */ 
	#define BITFIELD_TSDEMUX_DSR_RESERVED	 0x0820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRC_CONTROL	0x1000 /* CRC check control register */ 
	#define BITFIELD_TSDEMUX_CRC_CONTROL	 0x1000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRC_CONTROL */
	#define BLSB_TSDEMUX_CRC_CONTROL_RESERVED_31_2	2
	#define BLSB_TSDEMUX_CRC_CONTROL_BIT_DIRECTION	1
	#define BLSB_TSDEMUX_CRC_CONTROL_CRC_ENABLE	0
	/* Register Bit Widths for TSDEMUX_CRC_CONTROL */
	#define BWID_TSDEMUX_CRC_CONTROL_RESERVED_31_2	30
	#define BWID_TSDEMUX_CRC_CONTROL_BIT_DIRECTION	1
	#define BWID_TSDEMUX_CRC_CONTROL_CRC_ENABLE	1
	/* Register Bit MASKS for TSDEMUX_CRC_CONTROL */
	#define BMSK_TSDEMUX_CRC_CONTROL_RESERVED_31_2	0xfffffffc /*  */
	#define BMSK_TSDEMUX_CRC_CONTROL_BIT_DIRECTION	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_CRC_CONTROL_CRC_ENABLE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_CRC_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRC_CONTROL_RESERVED_31_2	 0x1000, 2, 30, 0xfffffffc
	#define BITFIELD_TSDEMUX_CRC_CONTROL_BIT_DIRECTION	 0x1000, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_CRC_CONTROL_CRC_ENABLE	 0x1000, 0, 1, 0x00000001
#define ROFF_TSDEMUX_CRC_STATUS	0x1004 /* CRC check status register */ 
	#define BITFIELD_TSDEMUX_CRC_STATUS	 0x1004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_CRC_STATUS */
	#define BLSB_TSDEMUX_CRC_STATUS_RESERVED_31_1	1
	#define BLSB_TSDEMUX_CRC_STATUS_CRC_Error	0
	/* Register Bit Widths for TSDEMUX_CRC_STATUS */
	#define BWID_TSDEMUX_CRC_STATUS_RESERVED_31_1	31
	#define BWID_TSDEMUX_CRC_STATUS_CRC_Error	1
	/* Register Bit MASKS for TSDEMUX_CRC_STATUS */
	#define BMSK_TSDEMUX_CRC_STATUS_RESERVED_31_1	0xfffffffe /*  */
	#define BMSK_TSDEMUX_CRC_STATUS_CRC_Error	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_CRC_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_CRC_STATUS_RESERVED_31_1	 0x1004, 1, 31, 0xfffffffe
	#define BITFIELD_TSDEMUX_CRC_STATUS_CRC_Error	 0x1004, 0, 1, 0x00000001
#define ROFF_TSDEMUX_CRC_IRQ	0x1008 /* CRC IRQ Register */ 
	#define BITFIELD_TSDEMUX_CRC_IRQ	 0x1008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRC_IRQ_MASK	0x100c /* CRCIRQ_MASK Register */ 
	#define BITFIELD_TSDEMUX_CRC_IRQ_MASK	 0x100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRC_ACCUMULATOR	0x1010 /* CRC accumulator register */ 
	#define BITFIELD_TSDEMUX_CRC_ACCUMULATOR	 0x1010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_CRC_RESERVED	0x101c /* Reserved */ 
	#define BITFIELD_TSDEMUX_CRC_RESERVED	 0x101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_CONTROL	0x1800 /* Pattern Matcher Unit Control */ 
	#define BITFIELD_TSDEMUX_PM_CONTROL	 0x1800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_PM_CONTROL */
	#define BLSB_TSDEMUX_PM_CONTROL_RESERVED_31_2	2
	#define BLSB_TSDEMUX_PM_CONTROL_MASK_MATCH_ENABLE	1
	#define BLSB_TSDEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	0
	/* Register Bit Widths for TSDEMUX_PM_CONTROL */
	#define BWID_TSDEMUX_PM_CONTROL_RESERVED_31_2	30
	#define BWID_TSDEMUX_PM_CONTROL_MASK_MATCH_ENABLE	1
	#define BWID_TSDEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	1
	/* Register Bit MASKS for TSDEMUX_PM_CONTROL */
	#define BMSK_TSDEMUX_PM_CONTROL_RESERVED_31_2	0xfffffffc /*  */
	#define BMSK_TSDEMUX_PM_CONTROL_MASK_MATCH_ENABLE	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_PM_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_PM_CONTROL_RESERVED_31_2	 0x1800, 2, 30, 0xfffffffc
	#define BITFIELD_TSDEMUX_PM_CONTROL_MASK_MATCH_ENABLE	 0x1800, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	 0x1800, 0, 1, 0x00000001
#define ROFF_TSDEMUX_PM_STATUS	0x1804 /* Pattern Matcher Unit Status */ 
	#define BITFIELD_TSDEMUX_PM_STATUS	 0x1804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_PM_STATUS */
	#define BLSB_TSDEMUX_PM_STATUS_RESERVED_31_2	2
	#define BLSB_TSDEMUX_PM_STATUS_MASK_MATCH	1
	#define BLSB_TSDEMUX_PM_STATUS_EXACT_MATCH	0
	/* Register Bit Widths for TSDEMUX_PM_STATUS */
	#define BWID_TSDEMUX_PM_STATUS_RESERVED_31_2	30
	#define BWID_TSDEMUX_PM_STATUS_MASK_MATCH	1
	#define BWID_TSDEMUX_PM_STATUS_EXACT_MATCH	1
	/* Register Bit MASKS for TSDEMUX_PM_STATUS */
	#define BMSK_TSDEMUX_PM_STATUS_RESERVED_31_2	0xfffffffc /*  */
	#define BMSK_TSDEMUX_PM_STATUS_MASK_MATCH	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_PM_STATUS_EXACT_MATCH	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_PM_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_PM_STATUS_RESERVED_31_2	 0x1804, 2, 30, 0xfffffffc
	#define BITFIELD_TSDEMUX_PM_STATUS_MASK_MATCH	 0x1804, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_PM_STATUS_EXACT_MATCH	 0x1804, 0, 1, 0x00000001
#define ROFF_TSDEMUX_PM_IRQ	0x1808 /* Pattern Matcher IRQ Register */ 
	#define BITFIELD_TSDEMUX_PM_IRQ	 0x1808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_PM_IRQ */
	#define BLSB_TSDEMUX_PM_IRQ_RESERVED_31_2	2
	#define BLSB_TSDEMUX_PM_IRQ_MASK_MATCH_IRQ	1
	#define BLSB_TSDEMUX_PM_IRQ_EXACT_MATCH_IRQ	0
	/* Register Bit Widths for TSDEMUX_PM_IRQ */
	#define BWID_TSDEMUX_PM_IRQ_RESERVED_31_2	30
	#define BWID_TSDEMUX_PM_IRQ_MASK_MATCH_IRQ	1
	#define BWID_TSDEMUX_PM_IRQ_EXACT_MATCH_IRQ	1
	/* Register Bit MASKS for TSDEMUX_PM_IRQ */
	#define BMSK_TSDEMUX_PM_IRQ_RESERVED_31_2	0xfffffffc /*  */
	#define BMSK_TSDEMUX_PM_IRQ_MASK_MATCH_IRQ	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_PM_IRQ_EXACT_MATCH_IRQ	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_PM_IRQ - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_PM_IRQ_RESERVED_31_2	 0x1808, 2, 30, 0xfffffffc
	#define BITFIELD_TSDEMUX_PM_IRQ_MASK_MATCH_IRQ	 0x1808, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_PM_IRQ_EXACT_MATCH_IRQ	 0x1808, 0, 1, 0x00000001
#define ROFF_TSDEMUX_PM_IRQ_MASK	0x180c /* Pattern Matcher IRQ_MASK Register */ 
	#define BITFIELD_TSDEMUX_PM_IRQ_MASK	 0x180c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_PM_IRQ_MASK */
	#define BLSB_TSDEMUX_PM_IRQ_MASK_RESERVED_31_2	2
	#define BLSB_TSDEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_Mask	1
	#define BLSB_TSDEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_Mask	0
	/* Register Bit Widths for TSDEMUX_PM_IRQ_MASK */
	#define BWID_TSDEMUX_PM_IRQ_MASK_RESERVED_31_2	30
	#define BWID_TSDEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_Mask	1
	#define BWID_TSDEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_Mask	1
	/* Register Bit MASKS for TSDEMUX_PM_IRQ_MASK */
	#define BMSK_TSDEMUX_PM_IRQ_MASK_RESERVED_31_2	0xfffffffc /*  */
	#define BMSK_TSDEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_Mask	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_Mask	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_PM_IRQ_MASK - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_PM_IRQ_MASK_RESERVED_31_2	 0x180c, 2, 30, 0xfffffffc
	#define BITFIELD_TSDEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_Mask	 0x180c, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_Mask	 0x180c, 0, 1, 0x00000001
#define ROFF_TSDEMUX_PM_MASK_03	0x1810 /* Pattern Matcher Unit Mask03 */ 
	#define BITFIELD_TSDEMUX_PM_MASK_03	 0x1810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_MASK_47	0x1814 /* Pattern Matcher Unit Mask47 */ 
	#define BITFIELD_TSDEMUX_PM_MASK_47	 0x1814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_RESERVED0	0x1818 /* Reserved */ 
	#define BITFIELD_TSDEMUX_PM_RESERVED0	 0x1818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_MATCH_03	0x1820 /* Pattern Matcher Unit Match03 */ 
	#define BITFIELD_TSDEMUX_PM_MATCH_03	 0x1820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_MATCH_47	0x1824 /* Pattern Matcher Unit Match03 */ 
	#define BITFIELD_TSDEMUX_PM_MATCH_47	 0x1824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_RESERVED	0x828 /* Reserved */ 
	#define BITFIELD_TSDEMUX_PM_RESERVED	 0x0828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_PM_MASK_CLEAR	0x1830 /* Selectively clears bytes in the MATCH_* registers. */ 
	#define BITFIELD_TSDEMUX_PM_MASK_CLEAR	 0x1830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_PM_MASK_CLEAR */
	#define BLSB_TSDEMUX_PM_MASK_CLEAR_RESERVED_31_8	8
	#define BLSB_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_47	4
	#define BLSB_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_03	0
	/* Register Bit Widths for TSDEMUX_PM_MASK_CLEAR */
	#define BWID_TSDEMUX_PM_MASK_CLEAR_RESERVED_31_8	24
	#define BWID_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_47	4
	#define BWID_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_03	4
	/* Register Bit MASKS for TSDEMUX_PM_MASK_CLEAR */
	#define BMSK_TSDEMUX_PM_MASK_CLEAR_RESERVED_31_8	0xffffff00 /*  */
	#define BMSK_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_47	0x000000f0 /*  */
	#define BMSK_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_03	0x0000000f /*  */
	/* Register BITFIELD for TSDEMUX_PM_MASK_CLEAR - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_PM_MASK_CLEAR_RESERVED_31_8	 0x1830, 8, 24, 0xffffff00
	#define BITFIELD_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_47	 0x1830, 4, 4, 0x000000f0
	#define BITFIELD_TSDEMUX_PM_MASK_CLEAR_Clears_MASK_03	 0x1830, 0, 4, 0x0000000f
#define ROFF_TSDEMUX_PM_RESERVED1	0x1834 /* RESERVED */ 
	#define BITFIELD_TSDEMUX_PM_RESERVED1	 0x1834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_CONTROL	0x2000 /* I/O controller control Register */ 
	#define BITFIELD_TSDEMUX_IO_CONTROL	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_IO_CONTROL */
	#define BLSB_TSDEMUX_IO_CONTROL_RESERVED_31_4	4
	#define BLSB_TSDEMUX_IO_CONTROL_Send_Remaining	3
	#define BLSB_TSDEMUX_IO_CONTROL_Send_Enable	2
	#define BLSB_TSDEMUX_IO_CONTROL_Fetch_Enable	1
	#define BLSB_TSDEMUX_IO_CONTROL_Input_Flush	0
	/* Register Bit Widths for TSDEMUX_IO_CONTROL */
	#define BWID_TSDEMUX_IO_CONTROL_RESERVED_31_4	28
	#define BWID_TSDEMUX_IO_CONTROL_Send_Remaining	1
	#define BWID_TSDEMUX_IO_CONTROL_Send_Enable	1
	#define BWID_TSDEMUX_IO_CONTROL_Fetch_Enable	1
	#define BWID_TSDEMUX_IO_CONTROL_Input_Flush	1
	/* Register Bit MASKS for TSDEMUX_IO_CONTROL */
	#define BMSK_TSDEMUX_IO_CONTROL_RESERVED_31_4	0xfffffff0 /*  */
	#define BMSK_TSDEMUX_IO_CONTROL_Send_Remaining	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSDEMUX_IO_CONTROL_Send_Enable	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSDEMUX_IO_CONTROL_Fetch_Enable	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_IO_CONTROL_Input_Flush	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_IO_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_IO_CONTROL_RESERVED_31_4	 0x2000, 4, 28, 0xfffffff0
	#define BITFIELD_TSDEMUX_IO_CONTROL_Send_Remaining	 0x2000, 3, 1, 0x00000008
	#define BITFIELD_TSDEMUX_IO_CONTROL_Send_Enable	 0x2000, 2, 1, 0x00000004
	#define BITFIELD_TSDEMUX_IO_CONTROL_Fetch_Enable	 0x2000, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_IO_CONTROL_Input_Flush	 0x2000, 0, 1, 0x00000001
#define ROFF_TSDEMUX_IO_STATUS	0x2004 /* I/O controller status Register */ 
	#define BITFIELD_TSDEMUX_IO_STATUS	 0x2004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_IO_STATUS */
	#define BLSB_TSDEMUX_IO_STATUS_RESERVED_31_4	4
	#define BLSB_TSDEMUX_IO_STATUS_Send_Remaining_Busy	3
	#define BLSB_TSDEMUX_IO_STATUS_Out_FIFO_Emtpy	2
	#define BLSB_TSDEMUX_IO_STATUS_Shift_Busy	1
	#define BLSB_TSDEMUX_IO_STATUS_Input_Flush_Busy	0
	/* Register Bit Widths for TSDEMUX_IO_STATUS */
	#define BWID_TSDEMUX_IO_STATUS_RESERVED_31_4	28
	#define BWID_TSDEMUX_IO_STATUS_Send_Remaining_Busy	1
	#define BWID_TSDEMUX_IO_STATUS_Out_FIFO_Emtpy	1
	#define BWID_TSDEMUX_IO_STATUS_Shift_Busy	1
	#define BWID_TSDEMUX_IO_STATUS_Input_Flush_Busy	1
	/* Register Bit MASKS for TSDEMUX_IO_STATUS */
	#define BMSK_TSDEMUX_IO_STATUS_RESERVED_31_4	0xfffffff0 /*  */
	#define BMSK_TSDEMUX_IO_STATUS_Send_Remaining_Busy	(1<<3) /* == 0x00000008:  */
	#define BMSK_TSDEMUX_IO_STATUS_Out_FIFO_Emtpy	(1<<2) /* == 0x00000004:  */
	#define BMSK_TSDEMUX_IO_STATUS_Shift_Busy	(1<<1) /* == 0x00000002:  */
	#define BMSK_TSDEMUX_IO_STATUS_Input_Flush_Busy	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for TSDEMUX_IO_STATUS - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_IO_STATUS_RESERVED_31_4	 0x2004, 4, 28, 0xfffffff0
	#define BITFIELD_TSDEMUX_IO_STATUS_Send_Remaining_Busy	 0x2004, 3, 1, 0x00000008
	#define BITFIELD_TSDEMUX_IO_STATUS_Out_FIFO_Emtpy	 0x2004, 2, 1, 0x00000004
	#define BITFIELD_TSDEMUX_IO_STATUS_Shift_Busy	 0x2004, 1, 1, 0x00000002
	#define BITFIELD_TSDEMUX_IO_STATUS_Input_Flush_Busy	 0x2004, 0, 1, 0x00000001
#define ROFF_TSDEMUX_IO_IRQ	0x2008 /* I/O Controller IRQ Register */ 
	#define BITFIELD_TSDEMUX_IO_IRQ	 0x2008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_IRQ_MASK	0x200c /* I/O Controller IRQ_MASK Register */ 
	#define BITFIELD_TSDEMUX_IO_IRQ_MASK	 0x200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_INPUT_START_ADDR	0x2010 /* I/O controller input start address Register */ 
	#define BITFIELD_TSDEMUX_IO_INPUT_START_ADDR	 0x2010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_INPUT_CURR_ADDR	0x2014 /* I/O controller input current address Register */ 
	#define BITFIELD_TSDEMUX_IO_INPUT_CURR_ADDR	 0x2014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_INPUT_SIZE	0x2018 /* I/O controller input size Register */ 
	#define BITFIELD_TSDEMUX_IO_INPUT_SIZE	 0x2018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_RESERVED0	0x201c /* IO_RESERVED */ 
	#define BITFIELD_TSDEMUX_IO_RESERVED0	 0x201c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_BYTES_SHIFTED_IN	0x2020 /* The value in this register is incremented by one each time a new byte is shifted into the DSR. */ 
	#define BITFIELD_TSDEMUX_IO_BYTES_SHIFTED_IN	 0x2020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_INPUT_FIFO_LEVEL	0x2024 /* The number of bytes currently available in the input FIFO for shifting into the DSR.  */ 
	#define BITFIELD_TSDEMUX_IO_INPUT_FIFO_LEVEL	 0x2024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_OUTPUT_START_ADDR	0x2028 /* I/O controller output start address Register */ 
	#define BITFIELD_TSDEMUX_IO_OUTPUT_START_ADDR	 0x2028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_OUTPUT_CURR_ADDR	0x202c /* I/O controller output current address Register */ 
	#define BITFIELD_TSDEMUX_IO_OUTPUT_CURR_ADDR	 0x202c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_OUTPUT_SIZE	0x2030 /* I/O controller output size Register */ 
	#define BITFIELD_TSDEMUX_IO_OUTPUT_SIZE	 0x2030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD	0x2038 /* Indicates a watermark for creating an xsi request to send out more stream data.  */ 
	#define BITFIELD_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD	 0x2038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_IO_OUTPUT_SEND_THRESHOLD */
	#define BLSB_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	8
	#define BLSB_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	2
	#define BLSB_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	0
	/* Register Bit Widths for TSDEMUX_IO_OUTPUT_SEND_THRESHOLD */
	#define BWID_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	24
	#define BWID_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	6
	#define BWID_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	2
	/* Register Bit MASKS for TSDEMUX_IO_OUTPUT_SEND_THRESHOLD */
	#define BMSK_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	0xffffff00 /*  */
	#define BMSK_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	0x000000fc /*  */
	#define BMSK_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	0x00000003 /*  */
	/* Register BITFIELD for TSDEMUX_IO_OUTPUT_SEND_THRESHOLD - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	 0x2038, 8, 24, 0xffffff00
	#define BITFIELD_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	 0x2038, 2, 6, 0x000000fc
	#define BITFIELD_TSDEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	 0x2038, 0, 2, 0x00000003
#define ROFF_TSDEMUX_IO_INPUT_FETCH_THRESHOLD	0x203c /* Indicates a watermark for creating an xsi request to read in more stream data.  */ 
	#define BITFIELD_TSDEMUX_IO_INPUT_FETCH_THRESHOLD	 0x203c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for TSDEMUX_IO_INPUT_FETCH_THRESHOLD */
	#define BLSB_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	8
	#define BLSB_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	2
	#define BLSB_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	0
	/* Register Bit Widths for TSDEMUX_IO_INPUT_FETCH_THRESHOLD */
	#define BWID_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	24
	#define BWID_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	6
	#define BWID_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	2
	/* Register Bit MASKS for TSDEMUX_IO_INPUT_FETCH_THRESHOLD */
	#define BMSK_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	0xffffff00 /*  */
	#define BMSK_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	0x000000fc /*  */
	#define BMSK_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	0x00000003 /*  */
	/* Register BITFIELD for TSDEMUX_IO_INPUT_FETCH_THRESHOLD - roff, lsb, width, mask */
	#define BITFIELD_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	 0x203c, 8, 24, 0xffffff00
	#define BITFIELD_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	 0x203c, 2, 6, 0x000000fc
	#define BITFIELD_TSDEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	 0x203c, 0, 2, 0x00000003
#define ROFF_TSDEMUX_IO_RESERVED1	0x2040 /* Reserved */ 
	#define BITFIELD_TSDEMUX_IO_RESERVED1	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_RESERVED0	0x2800 /* Host Interface Reserved */ 
	#define BITFIELD_TSDEMUX_HOST_RESERVED0	 0x2800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_RESERVED1	0x2804 /* Host Interface Reserved */ 
	#define BITFIELD_TSDEMUX_HOST_RESERVED1	 0x2804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_IRQ	0x2808 /* Contains the IPC Doorbell IRQs.  They are cleared by writing a 1. */ 
	#define BITFIELD_TSDEMUX_HOST_IRQ	 0x2808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_IRQ_MASK	0x280c /* indicates the correlated IRQ signal from the IRQ register is masked. */ 
	#define BITFIELD_TSDEMUX_HOST_IRQ_MASK	 0x280c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_IPC_STATUS	0x2810 /* Contains the Ready and Done IPC flags for each of the processors. */ 
	#define BITFIELD_TSDEMUX_HOST_IPC_STATUS	 0x2810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_IPC_DOORBELL	0x2814 /* Command mailbox for communicating with the host processor from the RISC controller. */ 
	#define BITFIELD_TSDEMUX_HOST_IPC_DOORBELL	 0x2814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_RISC_IPC_DOORBELL	0x2818 /* Command mailbox for communicating with the RISC controller from the host processor. */ 
	#define BITFIELD_TSDEMUX_RISC_IPC_DOORBELL	 0x2818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_ICACHE_BASE_ADDRESS	0x281c /* Indicates the base address of the firmware image in the XSI memory space.  */ 
	#define BITFIELD_TSDEMUX_ICACHE_BASE_ADDRESS	 0x281c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_ICACHE_INVALIDATE_0	0x2820 /* Each bit in this register corresponds to a cache line in the RISC instruction cache.  */ 
	#define BITFIELD_TSDEMUX_ICACHE_INVALIDATE_0	 0x2820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_ICACHE_INVALIDATE_1	0x2824 /* Each bit in this register corresponds to a cache line in the RISC instruction cache. */ 
	#define BITFIELD_TSDEMUX_ICACHE_INVALIDATE_1	 0x2824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_ICACHE_INVALIDATE_2	0x2828 /* Each bit in this register corresponds to a cache line in the RISC instruction cache. */ 
	#define BITFIELD_TSDEMUX_ICACHE_INVALIDATE_2	 0x2828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_ICACHE_INVALIDATE_3	0x282c /* Each bit in this register corresponds to a cache line in the RISC instruction cache.  */ 
	#define BITFIELD_TSDEMUX_ICACHE_INVALIDATE_3	 0x282c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_HOST_RESERVED	0x2830 /* Reserved	2 */ 
	#define BITFIELD_TSDEMUX_HOST_RESERVED	 0x2830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_Coproc_Interface_Opcode	0x3000 /* The opcode written to this register is passed on to the coprocessor via the coprocessor interface  */ 
	#define BITFIELD_TSDEMUX_Coproc_Interface_Opcode	 0x3000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_Coproc_Interface_Data	0x3004 /* Data written to this register is passed on to the coprocessor via the coprocessor  */ 
	#define BITFIELD_TSDEMUX_Coproc_Interface_Data	 0x3004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_TSDEMUX_Coproc_Interface_Aux	0x3008 /* Auxillary Interface */ 
	#define BITFIELD_TSDEMUX_Coproc_Interface_Aux	 0x3008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module TSDEMUX SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_TSDEMUX_TSD_EVENTAME_0	0x1
#define SVEN_MODULE_EVENT_TSDEMUX_IN_PORT_EMPTY	0x2
#define SVEN_MODULE_EVENT_TSDEMUX_UNDERRUN_DETECTED	0x3
#define SVEN_MODULE_EVENT_TSDEMUX_IN_BUFFERS_FULL	0x4
#define SVEN_MODULE_EVENT_TSDEMUX_OUT_BUFFERS_EMPTY	0x5
#define SVEN_MODULE_EVENT_TSDEMUX_OUT_PORT_FULL	0x6
#define SVEN_MODULE_EVENT_TSDEMUX_PORT_WRITE	0x7
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_INPUT_STREAM	0x80
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_CONTROL_INPUT_STREAM	0x81
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_FILTER	0x82
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_CTRL_CRYPTO_ON_FILTER	0x83
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_ADD_PID	0x84
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_ADD_FILTER_TO_PID	0x85
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_CONTROL_PID	0x86
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_CONTROL_FILTER	0x87
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_DELETE_PID	0x88
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_DELETE_FILTER_FROM_PID	0x89
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_FILTER_WPA	0x8a
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_ADD_MM_FILTER	0x8b
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_CRYPTO_PARAMS	0x8c
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_CRYPTO_KEY	0x8d
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_STR_CRYPTO_INFO	0x8e
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_RESET_INDEX_COUNT	0x8f
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_DISCONT_PKT_STREAM_ID	0x90
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_PCR_PID	0x91
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_RESET_FILTER	0x92
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_RESET_STREAM	0x93
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_STREAM_LOW_WM	0x94
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_FILTER_HIGH_WM	0x95
#define SVEN_MODULE_EVENT_TSDEMUX_FW_RCV_IPC_CMD_SET_FILTER_CF	0x96
#define SVEN_MODULE_EVENT_TSDEMUX_SET_REBASE_OFFSET	0x8
#define SVEN_MODULE_EVENT_TSDEMUX_GET_REBASE_OFFSET	0x9


#endif /* TSDEMUX_REGOFFS_H */
