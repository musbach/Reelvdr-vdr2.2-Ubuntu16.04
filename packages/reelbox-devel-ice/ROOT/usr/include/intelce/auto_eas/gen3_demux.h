#ifndef DEMUX_REGOFFS_H
#define DEMUX_REGOFFS_H 1
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


/* Module DEMUX CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_DEMUX_CRYPTO_CONTROL	0x0 /* Crypto Control Register */ 
	#define BITFIELD_DEMUX_CRYPTO_CONTROL	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRYPTO_CONTROL */
	#define BLSB_DEMUX_CRYPTO_CONTROL_RESERVED_31_5	5
	#define BLSB_DEMUX_CRYPTO_CONTROL_Conformance_mode_select	4
	#define BLSB_DEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	0
	/* Register Bit Widths for DEMUX_CRYPTO_CONTROL */
	#define BWID_DEMUX_CRYPTO_CONTROL_RESERVED_31_5	27
	#define BWID_DEMUX_CRYPTO_CONTROL_Conformance_mode_select	1
	#define BWID_DEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	4
	/* Register Bit MASKS for DEMUX_CRYPTO_CONTROL */
	#define BMSK_DEMUX_CRYPTO_CONTROL_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_DEMUX_CRYPTO_CONTROL_Conformance_mode_select	(1<<4) /* == 0x00000010:  */
	#define BMSK_DEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	0x0000000f /*  */
	/* Register BITFIELD for DEMUX_CRYPTO_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRYPTO_CONTROL_RESERVED_31_5	 0x0000, 5, 27, 0xffffffe0
	#define BITFIELD_DEMUX_CRYPTO_CONTROL_Conformance_mode_select	 0x0000, 4, 1, 0x00000010
	#define BITFIELD_DEMUX_CRYPTO_CONTROL_ACTIVE_KEY_TYPE	 0x0000, 0, 4, 0x0000000f
#define ROFF_DEMUX_CRYPTO_STATUS	0x4 /* Crypto Status Register */ 
	#define BITFIELD_DEMUX_CRYPTO_STATUS	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRYPTO_STATUS */
	#define BLSB_DEMUX_CRYPTO_STATUS_RESERVED_31_4	4
	#define BLSB_DEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	3
	#define BLSB_DEMUX_CRYPTO_STATUS_Output_Ready	2
	#define BLSB_DEMUX_CRYPTO_STATUS_Input_Ready	1
	#define BLSB_DEMUX_CRYPTO_STATUS_Busy	0
	/* Register Bit Widths for DEMUX_CRYPTO_STATUS */
	#define BWID_DEMUX_CRYPTO_STATUS_RESERVED_31_4	28
	#define BWID_DEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	1
	#define BWID_DEMUX_CRYPTO_STATUS_Output_Ready	1
	#define BWID_DEMUX_CRYPTO_STATUS_Input_Ready	1
	#define BWID_DEMUX_CRYPTO_STATUS_Busy	1
	/* Register Bit MASKS for DEMUX_CRYPTO_STATUS */
	#define BMSK_DEMUX_CRYPTO_STATUS_RESERVED_31_4	0xfffffff0 /*  */
	#define BMSK_DEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_CRYPTO_STATUS_Output_Ready	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_CRYPTO_STATUS_Input_Ready	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_CRYPTO_STATUS_Busy	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_CRYPTO_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRYPTO_STATUS_RESERVED_31_4	 0x0004, 4, 28, 0xfffffff0
	#define BITFIELD_DEMUX_CRYPTO_STATUS_Back_Door_Key_Busy	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_CRYPTO_STATUS_Output_Ready	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_CRYPTO_STATUS_Input_Ready	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_CRYPTO_STATUS_Busy	 0x0004, 0, 1, 0x00000001
#define ROFF_DEMUX_CRYPTO_IRQ	0x8 /* Crypto IRQ Register */ 
	#define BITFIELD_DEMUX_CRYPTO_IRQ	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRYPTO_IRQ */
	#define BLSB_DEMUX_CRYPTO_IRQ_RESERVED_31_3	3
	#define BLSB_DEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	2
	#define BLSB_DEMUX_CRYPTO_IRQ_Output_Ready_IRQ	1
	#define BLSB_DEMUX_CRYPTO_IRQ_Input_Ready_IRQ	0
	/* Register Bit Widths for DEMUX_CRYPTO_IRQ */
	#define BWID_DEMUX_CRYPTO_IRQ_RESERVED_31_3	29
	#define BWID_DEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	1
	#define BWID_DEMUX_CRYPTO_IRQ_Output_Ready_IRQ	1
	#define BWID_DEMUX_CRYPTO_IRQ_Input_Ready_IRQ	1
	/* Register Bit MASKS for DEMUX_CRYPTO_IRQ */
	#define BMSK_DEMUX_CRYPTO_IRQ_RESERVED_31_3	0xfffffff8 /*  */
	#define BMSK_DEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_CRYPTO_IRQ_Output_Ready_IRQ	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_CRYPTO_IRQ_Input_Ready_IRQ	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_CRYPTO_IRQ - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRYPTO_IRQ_RESERVED_31_3	 0x0008, 3, 29, 0xfffffff8
	#define BITFIELD_DEMUX_CRYPTO_IRQ_Invalid_Key_IRQ	 0x0008, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_CRYPTO_IRQ_Output_Ready_IRQ	 0x0008, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_CRYPTO_IRQ_Input_Ready_IRQ	 0x0008, 0, 1, 0x00000001
#define ROFF_DEMUX_CRYPTO_IRQ_MASK	0xc /* Crypto IRQ_MASK Register */ 
	#define BITFIELD_DEMUX_CRYPTO_IRQ_MASK	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRYPTO_IRQ_MASK */
	#define BLSB_DEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	3
	#define BLSB_DEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	2
	#define BLSB_DEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	1
	#define BLSB_DEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	0
	/* Register Bit Widths for DEMUX_CRYPTO_IRQ_MASK */
	#define BWID_DEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	29
	#define BWID_DEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	1
	#define BWID_DEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	1
	#define BWID_DEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	1
	/* Register Bit MASKS for DEMUX_CRYPTO_IRQ_MASK */
	#define BMSK_DEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	0xfffffff8 /*  */
	#define BMSK_DEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_CRYPTO_IRQ_MASK - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRYPTO_IRQ_MASK_RESERVED_31_3	 0x000c, 3, 29, 0xfffffff8
	#define BITFIELD_DEMUX_CRYPTO_IRQ_MASK_Invalid_Key_IRQ_MASK	 0x000c, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_CRYPTO_IRQ_MASK_Output_Ready_IRQ_MASK	 0x000c, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_CRYPTO_IRQ_MASK_Input_Ready_IRQ_MASK	 0x000c, 0, 1, 0x00000001
#define ROFF_DEMUX_CRYPTO_IV_0	0x10 /* Least significant word */ 
	#define BITFIELD_DEMUX_CRYPTO_IV_0	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_IV_1	0x14 /* Most significant word */ 
	#define BITFIELD_DEMUX_CRYPTO_IV_1	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_KEY_0	0x18 /* Least significant word of crypto key */ 
	#define BITFIELD_DEMUX_CRYPTO_KEY_0	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_KEY_1	0x1c /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_KEY_1	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_KEY_2	0x20 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_KEY_2	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_KEY_3	0x24 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_KEY_3	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_KEY_4	0x28 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_KEY_4	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_KEY_5	0x2c /* Most signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_KEY_5	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_RESERVED0	0x30 /* Reserved */ 
	#define BITFIELD_DEMUX_CRYPTO_RESERVED0	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_ALGORITHM	0x3c /* Algorithm */ 
	#define BITFIELD_DEMUX_CRYPTO_ALGORITHM	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRYPTO_ALGORITHM */
	#define BLSB_DEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	5
	#define BLSB_DEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	0
	/* Register Bit Widths for DEMUX_CRYPTO_ALGORITHM */
	#define BWID_DEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	27
	#define BWID_DEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	5
	/* Register Bit MASKS for DEMUX_CRYPTO_ALGORITHM */
	#define BMSK_DEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_DEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	0x0000001f /*  */
	/* Register BITFIELD for DEMUX_CRYPTO_ALGORITHM - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRYPTO_ALGORITHM_RESERVED_31_5	 0x003c, 5, 27, 0xffffffe0
	#define BITFIELD_DEMUX_CRYPTO_ALGORITHM_Default_Crypto_Algorithm	 0x003c, 0, 5, 0x0000001f
#define ROFF_DEMUX_CRYPTO_DATAOUT_0	0x40 /* LSB of the result of a crypto operation OUTPUT_READY status flag is asserted */ 
	#define BITFIELD_DEMUX_CRYPTO_DATAOUT_0	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_DATAOUT_1	0x44 /* MSB of result of crypto operation_OUTPUT_READY FLAG ASSERTED */ 
	#define BITFIELD_DEMUX_CRYPTO_DATAOUT_1	 0x0044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_KEY_ADDR	0x48 /* Selects the current back-door crypto key */ 
	#define BITFIELD_DEMUX_KEY_ADDR	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_KEY_ADDR */
	#define BLSB_DEMUX_KEY_ADDR_RESERVED_31_8	8
	#define BLSB_DEMUX_KEY_ADDR_BackDoor_Key_Address	0
	/* Register Bit Widths for DEMUX_KEY_ADDR */
	#define BWID_DEMUX_KEY_ADDR_RESERVED_31_8	24
	#define BWID_DEMUX_KEY_ADDR_BackDoor_Key_Address	8
	/* Register Bit MASKS for DEMUX_KEY_ADDR */
	#define BMSK_DEMUX_KEY_ADDR_RESERVED_31_8	0xffffff00 /*  */
	#define BMSK_DEMUX_KEY_ADDR_BackDoor_Key_Address	0x000000ff /*  */
	/* Register BITFIELD for DEMUX_KEY_ADDR - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_KEY_ADDR_RESERVED_31_8	 0x0048, 8, 24, 0xffffff00
	#define BITFIELD_DEMUX_KEY_ADDR_BackDoor_Key_Address	 0x0048, 0, 8, 0x000000ff
#define ROFF_DEMUX_CRYPTO_RESERVED1	0x4c /* Reserved */ 
	#define BITFIELD_DEMUX_CRYPTO_RESERVED1	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_0	0x60 /* Least significant word of Multi-2 System key */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_0	 0x0060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_1	0x64 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_1	 0x0064, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_2	0x68 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_2	 0x0068, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_3	0x6c /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_3	 0x006c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_4	0x70 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_4	 0x0070, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_5	0x74 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_5	 0x0074, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_6	0x78 /* Middle signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_6	 0x0078, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_SKEY_7	0x7c /* Most signifiacnt word */ 
	#define BITFIELD_DEMUX_CRYPTO_SKEY_7	 0x007c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRYPTO_RESERVED2	0x80 /* Reserved */ 
	#define BITFIELD_DEMUX_CRYPTO_RESERVED2	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_CONTROL	0x800 /* Data Shift Control Register */ 
	#define BITFIELD_DEMUX_DSR_CONTROL	 0x0800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_STATUS	0x804 /* Data Shift Register */ 
	#define BITFIELD_DEMUX_DSR_STATUS	 0x0804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_IRQ	0x808 /* Data Shift IRQ Register */ 
	#define BITFIELD_DEMUX_DSR_IRQ	 0x0808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_IRQ_MASK	0x80c /* Data shiftIRQ_MASK Register */ 
	#define BITFIELD_DEMUX_DSR_IRQ_MASK	 0x080c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_DATA_03	0x810 /* Data Shift Data_03 Register */ 
	#define BITFIELD_DEMUX_DSR_DATA_03	 0x0810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_DATA_47	0x814 /* Data Shift Data_47 Register */ 
	#define BITFIELD_DEMUX_DSR_DATA_47	 0x0814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_DATA_8B	0x818 /* Data Shift Data_8B Register */ 
	#define BITFIELD_DEMUX_DSR_DATA_8B	 0x0818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_DATA_CF	0x81c /* Data Shift Data_CF Register */ 
	#define BITFIELD_DEMUX_DSR_DATA_CF	 0x081c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_DATA_103	0x820 /* Data Shift Data_103 Register */ 
	#define BITFIELD_DEMUX_DSR_DATA_103	 0x0820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_DATA_147	0x824 /* Data Shift Data_147 Register */ 
	#define BITFIELD_DEMUX_DSR_DATA_147	 0x0824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DSR_RESERVED	0x828 /* Reserved */ 
	#define BITFIELD_DEMUX_DSR_RESERVED	 0x0828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRC_CONTROL	0x1000 /* CRC check control register */ 
	#define BITFIELD_DEMUX_CRC_CONTROL	 0x1000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRC_CONTROL */
	#define BLSB_DEMUX_CRC_CONTROL_RESERVED_31_2	2
	#define BLSB_DEMUX_CRC_CONTROL_BIT_DIRECTION	1
	#define BLSB_DEMUX_CRC_CONTROL_CRC_ENABLE	0
	/* Register Bit Widths for DEMUX_CRC_CONTROL */
	#define BWID_DEMUX_CRC_CONTROL_RESERVED_31_2	30
	#define BWID_DEMUX_CRC_CONTROL_BIT_DIRECTION	1
	#define BWID_DEMUX_CRC_CONTROL_CRC_ENABLE	1
	/* Register Bit MASKS for DEMUX_CRC_CONTROL */
	#define BMSK_DEMUX_CRC_CONTROL_RESERVED_31_2	0xfffffffc /*  */
	#define BMSK_DEMUX_CRC_CONTROL_BIT_DIRECTION	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_CRC_CONTROL_CRC_ENABLE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_CRC_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRC_CONTROL_RESERVED_31_2	 0x1000, 2, 30, 0xfffffffc
	#define BITFIELD_DEMUX_CRC_CONTROL_BIT_DIRECTION	 0x1000, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_CRC_CONTROL_CRC_ENABLE	 0x1000, 0, 1, 0x00000001
#define ROFF_DEMUX_CRC_STATUS	0x1004 /* CRC check status register */ 
	#define BITFIELD_DEMUX_CRC_STATUS	 0x1004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_CRC_STATUS */
	#define BLSB_DEMUX_CRC_STATUS_RESERVED_31_1	1
	#define BLSB_DEMUX_CRC_STATUS_CRC_Error	0
	/* Register Bit Widths for DEMUX_CRC_STATUS */
	#define BWID_DEMUX_CRC_STATUS_RESERVED_31_1	31
	#define BWID_DEMUX_CRC_STATUS_CRC_Error	1
	/* Register Bit MASKS for DEMUX_CRC_STATUS */
	#define BMSK_DEMUX_CRC_STATUS_RESERVED_31_1	0xfffffffe /*  */
	#define BMSK_DEMUX_CRC_STATUS_CRC_Error	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_CRC_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_CRC_STATUS_RESERVED_31_1	 0x1004, 1, 31, 0xfffffffe
	#define BITFIELD_DEMUX_CRC_STATUS_CRC_Error	 0x1004, 0, 1, 0x00000001
#define ROFF_DEMUX_CRC_IRQ	0x1008 /* CRC IRQ Register */ 
	#define BITFIELD_DEMUX_CRC_IRQ	 0x1008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRC_IRQ_MASK	0x100c /* CRCIRQ_MASK Register */ 
	#define BITFIELD_DEMUX_CRC_IRQ_MASK	 0x100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRC_ACCUMULATOR	0x1010 /* CRC accumulator register */ 
	#define BITFIELD_DEMUX_CRC_ACCUMULATOR	 0x1010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_CRC_RESERVED	0x101c /* Reserved */ 
	#define BITFIELD_DEMUX_CRC_RESERVED	 0x101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_CONTROL	0x1800 /* Pattern Matcher Unit Control */ 
	#define BITFIELD_DEMUX_PM_CONTROL	 0x1800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_PM_CONTROL */
	#define BLSB_DEMUX_PM_CONTROL_RESERVED_31_5	5
	#define BLSB_DEMUX_PM_CONTROL_MULTI_MATCH_ENABLE	4
	#define BLSB_DEMUX_PM_CONTROL_COMBO_MATCH_ENABLE	3
	#define BLSB_DEMUX_PM_CONTROL_MASK_MATCH_ENABLE	2
	#define BLSB_DEMUX_PM_CONTROL_DIFF_MATCH_ENABLE	1
	#define BLSB_DEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	0
	/* Register Bit Widths for DEMUX_PM_CONTROL */
	#define BWID_DEMUX_PM_CONTROL_RESERVED_31_5	27
	#define BWID_DEMUX_PM_CONTROL_MULTI_MATCH_ENABLE	1
	#define BWID_DEMUX_PM_CONTROL_COMBO_MATCH_ENABLE	1
	#define BWID_DEMUX_PM_CONTROL_MASK_MATCH_ENABLE	1
	#define BWID_DEMUX_PM_CONTROL_DIFF_MATCH_ENABLE	1
	#define BWID_DEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	1
	/* Register Bit MASKS for DEMUX_PM_CONTROL */
	#define BMSK_DEMUX_PM_CONTROL_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_DEMUX_PM_CONTROL_MULTI_MATCH_ENABLE	(1<<4) /* == 0x00000010:  */
	#define BMSK_DEMUX_PM_CONTROL_COMBO_MATCH_ENABLE	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_PM_CONTROL_MASK_MATCH_ENABLE	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_PM_CONTROL_DIFF_MATCH_ENABLE	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_PM_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_PM_CONTROL_RESERVED_31_5	 0x1800, 5, 27, 0xffffffe0
	#define BITFIELD_DEMUX_PM_CONTROL_MULTI_MATCH_ENABLE	 0x1800, 4, 1, 0x00000010
	#define BITFIELD_DEMUX_PM_CONTROL_COMBO_MATCH_ENABLE	 0x1800, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_PM_CONTROL_MASK_MATCH_ENABLE	 0x1800, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_PM_CONTROL_DIFF_MATCH_ENABLE	 0x1800, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_PM_CONTROL_EXACT_MATCH_ENABLE	 0x1800, 0, 1, 0x00000001
#define ROFF_DEMUX_PM_STATUS	0x1804 /* Pattern Matcher Unit Status */ 
	#define BITFIELD_DEMUX_PM_STATUS	 0x1804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_PM_STATUS */
	#define BLSB_DEMUX_PM_STATUS_RESERVED_31_16	16
	#define BLSB_DEMUX_PM_STATUS_MULTI_MATCH_OVERFLOW	15
	#define BLSB_DEMUX_PM_STATUS_RESERVED_14	14
	#define BLSB_DEMUX_PM_STATUS_MULTI_MATCH_COUNTER	8
	#define BLSB_DEMUX_PM_STATUS_RESERVED_7_4	4
	#define BLSB_DEMUX_PM_STATUS_COMBO_MATCH	3
	#define BLSB_DEMUX_PM_STATUS_MASK_MATCH	2
	#define BLSB_DEMUX_PM_STATUS_DIFF_MATCH	1
	#define BLSB_DEMUX_PM_STATUS_EXACT_MATCH	0
	/* Register Bit Widths for DEMUX_PM_STATUS */
	#define BWID_DEMUX_PM_STATUS_RESERVED_31_16	16
	#define BWID_DEMUX_PM_STATUS_MULTI_MATCH_OVERFLOW	1
	#define BWID_DEMUX_PM_STATUS_RESERVED_14	1
	#define BWID_DEMUX_PM_STATUS_MULTI_MATCH_COUNTER	6
	#define BWID_DEMUX_PM_STATUS_RESERVED_7_4	4
	#define BWID_DEMUX_PM_STATUS_COMBO_MATCH	1
	#define BWID_DEMUX_PM_STATUS_MASK_MATCH	1
	#define BWID_DEMUX_PM_STATUS_DIFF_MATCH	1
	#define BWID_DEMUX_PM_STATUS_EXACT_MATCH	1
	/* Register Bit MASKS for DEMUX_PM_STATUS */
	#define BMSK_DEMUX_PM_STATUS_RESERVED_31_16	0xffff0000 /*  */
	#define BMSK_DEMUX_PM_STATUS_MULTI_MATCH_OVERFLOW	(1<<15) /* == 0x00008000:  */
	#define BMSK_DEMUX_PM_STATUS_RESERVED_14	(1<<14) /* == 0x00004000:  */
	#define BMSK_DEMUX_PM_STATUS_MULTI_MATCH_COUNTER	0x00003f00 /*  */
	#define BMSK_DEMUX_PM_STATUS_RESERVED_7_4	0x000000f0 /*  */
	#define BMSK_DEMUX_PM_STATUS_COMBO_MATCH	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_PM_STATUS_MASK_MATCH	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_PM_STATUS_DIFF_MATCH	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_PM_STATUS_EXACT_MATCH	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_PM_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_PM_STATUS_RESERVED_31_16	 0x1804, 16, 16, 0xffff0000
	#define BITFIELD_DEMUX_PM_STATUS_MULTI_MATCH_OVERFLOW	 0x1804, 15, 1, 0x00008000
	#define BITFIELD_DEMUX_PM_STATUS_RESERVED_14	 0x1804, 14, 1, 0x00004000
	#define BITFIELD_DEMUX_PM_STATUS_MULTI_MATCH_COUNTER	 0x1804, 8, 6, 0x00003f00
	#define BITFIELD_DEMUX_PM_STATUS_RESERVED_7_4	 0x1804, 4, 4, 0x000000f0
	#define BITFIELD_DEMUX_PM_STATUS_COMBO_MATCH	 0x1804, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_PM_STATUS_MASK_MATCH	 0x1804, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_PM_STATUS_DIFF_MATCH	 0x1804, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_PM_STATUS_EXACT_MATCH	 0x1804, 0, 1, 0x00000001
#define ROFF_DEMUX_PM_IRQ	0x1808 /* Pattern Matcher IRQ Register */ 
	#define BITFIELD_DEMUX_PM_IRQ	 0x1808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_PM_IRQ */
	#define BLSB_DEMUX_PM_IRQ_RESERVED_31_5	5
	#define BLSB_DEMUX_PM_IRQ_MULTI_MATCH_IRQ	4
	#define BLSB_DEMUX_PM_IRQ_COMBO_MATCH_IRQ	3
	#define BLSB_DEMUX_PM_IRQ_MASK_MATCH_IRQ	2
	#define BLSB_DEMUX_PM_IRQ_DIFF_MATCH_IRQ	1
	#define BLSB_DEMUX_PM_IRQ_EXACT_MATCH_IRQ	0
	/* Register Bit Widths for DEMUX_PM_IRQ */
	#define BWID_DEMUX_PM_IRQ_RESERVED_31_5	27
	#define BWID_DEMUX_PM_IRQ_MULTI_MATCH_IRQ	1
	#define BWID_DEMUX_PM_IRQ_COMBO_MATCH_IRQ	1
	#define BWID_DEMUX_PM_IRQ_MASK_MATCH_IRQ	1
	#define BWID_DEMUX_PM_IRQ_DIFF_MATCH_IRQ	1
	#define BWID_DEMUX_PM_IRQ_EXACT_MATCH_IRQ	1
	/* Register Bit MASKS for DEMUX_PM_IRQ */
	#define BMSK_DEMUX_PM_IRQ_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_DEMUX_PM_IRQ_MULTI_MATCH_IRQ	(1<<4) /* == 0x00000010:  */
	#define BMSK_DEMUX_PM_IRQ_COMBO_MATCH_IRQ	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_PM_IRQ_MASK_MATCH_IRQ	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_PM_IRQ_DIFF_MATCH_IRQ	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_PM_IRQ_EXACT_MATCH_IRQ	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_PM_IRQ - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_PM_IRQ_RESERVED_31_5	 0x1808, 5, 27, 0xffffffe0
	#define BITFIELD_DEMUX_PM_IRQ_MULTI_MATCH_IRQ	 0x1808, 4, 1, 0x00000010
	#define BITFIELD_DEMUX_PM_IRQ_COMBO_MATCH_IRQ	 0x1808, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_PM_IRQ_MASK_MATCH_IRQ	 0x1808, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_PM_IRQ_DIFF_MATCH_IRQ	 0x1808, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_PM_IRQ_EXACT_MATCH_IRQ	 0x1808, 0, 1, 0x00000001
#define ROFF_DEMUX_PM_IRQ_MASK	0x180c /* Pattern Matcher IRQ_MASK Register */ 
	#define BITFIELD_DEMUX_PM_IRQ_MASK	 0x180c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_PM_IRQ_MASK */
	#define BLSB_DEMUX_PM_IRQ_MASK_RESERVED_31_4	4
	#define BLSB_DEMUX_PM_IRQ_MASK_COMBO_MATCH_IRQ_MASK	3
	#define BLSB_DEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_MASK	2
	#define BLSB_DEMUX_PM_IRQ_MASK_DIFF_MATCH_IRQ_MASK	1
	#define BLSB_DEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_MASK	0
	/* Register Bit Widths for DEMUX_PM_IRQ_MASK */
	#define BWID_DEMUX_PM_IRQ_MASK_RESERVED_31_4	28
	#define BWID_DEMUX_PM_IRQ_MASK_COMBO_MATCH_IRQ_MASK	1
	#define BWID_DEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_MASK	1
	#define BWID_DEMUX_PM_IRQ_MASK_DIFF_MATCH_IRQ_MASK	1
	#define BWID_DEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_MASK	1
	/* Register Bit MASKS for DEMUX_PM_IRQ_MASK */
	#define BMSK_DEMUX_PM_IRQ_MASK_RESERVED_31_4	0xfffffff0 /*  */
	#define BMSK_DEMUX_PM_IRQ_MASK_COMBO_MATCH_IRQ_MASK	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_MASK	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_PM_IRQ_MASK_DIFF_MATCH_IRQ_MASK	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_MASK	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_PM_IRQ_MASK - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_PM_IRQ_MASK_RESERVED_31_4	 0x180c, 4, 28, 0xfffffff0
	#define BITFIELD_DEMUX_PM_IRQ_MASK_COMBO_MATCH_IRQ_MASK	 0x180c, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_PM_IRQ_MASK_MASK_MATCH_IRQ_MASK	 0x180c, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_PM_IRQ_MASK_DIFF_MATCH_IRQ_MASK	 0x180c, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_PM_IRQ_MASK_EXACT_MATCH_IRQ_MASK	 0x180c, 0, 1, 0x00000001
#define ROFF_DEMUX_PM_MASK_03	0x1810 /* Pattern Matcher Unit Mask03 */ 
	#define BITFIELD_DEMUX_PM_MASK_03	 0x1810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MASK_47	0x1814 /* Pattern Matcher Unit Mask47 */ 
	#define BITFIELD_DEMUX_PM_MASK_47	 0x1814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_RESERVED0	0x1818 /* Reserved */ 
	#define BITFIELD_DEMUX_PM_RESERVED0	 0x1818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MATCH_03	0x1820 /* Pattern Matcher Unit Match03 */ 
	#define BITFIELD_DEMUX_PM_MATCH_03	 0x1820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MATCH_47	0x1824 /* Pattern Matcher Unit Match03 */ 
	#define BITFIELD_DEMUX_PM_MATCH_47	 0x1824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_POLARITY_03	0x1828 /* Pattern Matcher Unit POLARITY03 */ 
	#define BITFIELD_DEMUX_PM_POLARITY_03	 0x1828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_POLARITY_47	0x182c /* Pattern Matcher Unit POLARITY03 */ 
	#define BITFIELD_DEMUX_PM_POLARITY_47	 0x182c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MASK_CLEAR	0x1830 /* Selectively clears bytes in the MATCH_* registers. */ 
	#define BITFIELD_DEMUX_PM_MASK_CLEAR	 0x1830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_PM_MASK_CLEAR */
	#define BLSB_DEMUX_PM_MASK_CLEAR_RESERVED_31_8	8
	#define BLSB_DEMUX_PM_MASK_CLEAR_Clears_MASK_47	4
	#define BLSB_DEMUX_PM_MASK_CLEAR_Clears_MASK_03	0
	/* Register Bit Widths for DEMUX_PM_MASK_CLEAR */
	#define BWID_DEMUX_PM_MASK_CLEAR_RESERVED_31_8	24
	#define BWID_DEMUX_PM_MASK_CLEAR_Clears_MASK_47	4
	#define BWID_DEMUX_PM_MASK_CLEAR_Clears_MASK_03	4
	/* Register Bit MASKS for DEMUX_PM_MASK_CLEAR */
	#define BMSK_DEMUX_PM_MASK_CLEAR_RESERVED_31_8	0xffffff00 /*  */
	#define BMSK_DEMUX_PM_MASK_CLEAR_Clears_MASK_47	0x000000f0 /*  */
	#define BMSK_DEMUX_PM_MASK_CLEAR_Clears_MASK_03	0x0000000f /*  */
	/* Register BITFIELD for DEMUX_PM_MASK_CLEAR - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_PM_MASK_CLEAR_RESERVED_31_8	 0x1830, 8, 24, 0xffffff00
	#define BITFIELD_DEMUX_PM_MASK_CLEAR_Clears_MASK_47	 0x1830, 4, 4, 0x000000f0
	#define BITFIELD_DEMUX_PM_MASK_CLEAR_Clears_MASK_03	 0x1830, 0, 4, 0x0000000f
#define ROFF_DEMUX_PM_RESERVED	0x834 /* Reserved */ 
	#define BITFIELD_DEMUX_PM_RESERVED	 0x0834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_0	0x1840 /* Bype locations of match 0 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_0	 0x1840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_1	0x1844 /* Bype locations of match 1 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_1	 0x1844, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_2	0x1848 /* Bype locations of match 2 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_2	 0x1848, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_3	0x184c /* Bype locations of match 3 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_3	 0x184c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_4	0x1850 /* Bype locations of match 4 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_4	 0x1850, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_5	0x1854 /* Bype locations of match 5 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_5	 0x1854, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_6	0x1858 /* Bype locations of match 6 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_6	 0x1858, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_MULTIMATCH_7	0x185c /* Bype locations of match 7 in multi matcher mode */ 
	#define BITFIELD_DEMUX_PM_MULTIMATCH_7	 0x185c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_PM_RESERVED1	0x1860 /* RESERVED */ 
	#define BITFIELD_DEMUX_PM_RESERVED1	 0x1860, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_CONTROL	0x2000 /* I/O controller control Register */ 
	#define BITFIELD_DEMUX_IO_CONTROL	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_IO_CONTROL */
	#define BLSB_DEMUX_IO_CONTROL_RESERVED_31_5	5
	#define BLSB_DEMUX_IO_CONTROL_DMEM_Mode	4
	#define BLSB_DEMUX_IO_CONTROL_Send_Remaining	3
	#define BLSB_DEMUX_IO_CONTROL_Send_Enable	2
	#define BLSB_DEMUX_IO_CONTROL_Fetch_Enable	1
	#define BLSB_DEMUX_IO_CONTROL_Input_Flush	0
	/* Register Bit Widths for DEMUX_IO_CONTROL */
	#define BWID_DEMUX_IO_CONTROL_RESERVED_31_5	27
	#define BWID_DEMUX_IO_CONTROL_DMEM_Mode	1
	#define BWID_DEMUX_IO_CONTROL_Send_Remaining	1
	#define BWID_DEMUX_IO_CONTROL_Send_Enable	1
	#define BWID_DEMUX_IO_CONTROL_Fetch_Enable	1
	#define BWID_DEMUX_IO_CONTROL_Input_Flush	1
	/* Register Bit MASKS for DEMUX_IO_CONTROL */
	#define BMSK_DEMUX_IO_CONTROL_RESERVED_31_5	0xffffffe0 /*  */
	#define BMSK_DEMUX_IO_CONTROL_DMEM_Mode	(1<<4) /* == 0x00000010:  */
	#define BMSK_DEMUX_IO_CONTROL_Send_Remaining	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_IO_CONTROL_Send_Enable	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_IO_CONTROL_Fetch_Enable	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_IO_CONTROL_Input_Flush	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_IO_CONTROL - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_IO_CONTROL_RESERVED_31_5	 0x2000, 5, 27, 0xffffffe0
	#define BITFIELD_DEMUX_IO_CONTROL_DMEM_Mode	 0x2000, 4, 1, 0x00000010
	#define BITFIELD_DEMUX_IO_CONTROL_Send_Remaining	 0x2000, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_IO_CONTROL_Send_Enable	 0x2000, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_IO_CONTROL_Fetch_Enable	 0x2000, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_IO_CONTROL_Input_Flush	 0x2000, 0, 1, 0x00000001
#define ROFF_DEMUX_IO_STATUS	0x2004 /* I/O controller status Register */ 
	#define BITFIELD_DEMUX_IO_STATUS	 0x2004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_IO_STATUS */
	#define BLSB_DEMUX_IO_STATUS_RESERVED_31_4	4
	#define BLSB_DEMUX_IO_STATUS_Send_Remaining_Busy	3
	#define BLSB_DEMUX_IO_STATUS_Out_FIFO_Emtpy	2
	#define BLSB_DEMUX_IO_STATUS_Shift_Busy	1
	#define BLSB_DEMUX_IO_STATUS_Input_Flush_Busy	0
	/* Register Bit Widths for DEMUX_IO_STATUS */
	#define BWID_DEMUX_IO_STATUS_RESERVED_31_4	28
	#define BWID_DEMUX_IO_STATUS_Send_Remaining_Busy	1
	#define BWID_DEMUX_IO_STATUS_Out_FIFO_Emtpy	1
	#define BWID_DEMUX_IO_STATUS_Shift_Busy	1
	#define BWID_DEMUX_IO_STATUS_Input_Flush_Busy	1
	/* Register Bit MASKS for DEMUX_IO_STATUS */
	#define BMSK_DEMUX_IO_STATUS_RESERVED_31_4	0xfffffff0 /*  */
	#define BMSK_DEMUX_IO_STATUS_Send_Remaining_Busy	(1<<3) /* == 0x00000008:  */
	#define BMSK_DEMUX_IO_STATUS_Out_FIFO_Emtpy	(1<<2) /* == 0x00000004:  */
	#define BMSK_DEMUX_IO_STATUS_Shift_Busy	(1<<1) /* == 0x00000002:  */
	#define BMSK_DEMUX_IO_STATUS_Input_Flush_Busy	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for DEMUX_IO_STATUS - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_IO_STATUS_RESERVED_31_4	 0x2004, 4, 28, 0xfffffff0
	#define BITFIELD_DEMUX_IO_STATUS_Send_Remaining_Busy	 0x2004, 3, 1, 0x00000008
	#define BITFIELD_DEMUX_IO_STATUS_Out_FIFO_Emtpy	 0x2004, 2, 1, 0x00000004
	#define BITFIELD_DEMUX_IO_STATUS_Shift_Busy	 0x2004, 1, 1, 0x00000002
	#define BITFIELD_DEMUX_IO_STATUS_Input_Flush_Busy	 0x2004, 0, 1, 0x00000001
#define ROFF_DEMUX_IO_IRQ	0x2008 /* I/O Controller IRQ Register */ 
	#define BITFIELD_DEMUX_IO_IRQ	 0x2008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_IRQ_MASK	0x200c /* I/O Controller IRQ_MASK Register */ 
	#define BITFIELD_DEMUX_IO_IRQ_MASK	 0x200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_INPUT_START_ADDR	0x2010 /* I/O controller input start address Register */ 
	#define BITFIELD_DEMUX_IO_INPUT_START_ADDR	 0x2010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_INPUT_CURR_ADDR	0x2014 /* I/O controller input current address Register */ 
	#define BITFIELD_DEMUX_IO_INPUT_CURR_ADDR	 0x2014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_INPUT_SIZE	0x2018 /* I/O controller input size Register */ 
	#define BITFIELD_DEMUX_IO_INPUT_SIZE	 0x2018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_RESERVED0	0x201c /* IO_RESERVED */ 
	#define BITFIELD_DEMUX_IO_RESERVED0	 0x201c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_BYTES_SHIFTED_IN	0x2020 /* The value in this register is incremented by one each time a new byte is shifted into the DSR. */ 
	#define BITFIELD_DEMUX_IO_BYTES_SHIFTED_IN	 0x2020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_INPUT_FIFO_LEVEL	0x2024 /* The number of bytes currently available in the input FIFO for shifting into the DSR.  */ 
	#define BITFIELD_DEMUX_IO_INPUT_FIFO_LEVEL	 0x2024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_OUTPUT_START_ADDR	0x2028 /* I/O controller output start address Register */ 
	#define BITFIELD_DEMUX_IO_OUTPUT_START_ADDR	 0x2028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_OUTPUT_CURR_ADDR	0x202c /* I/O controller output current address Register */ 
	#define BITFIELD_DEMUX_IO_OUTPUT_CURR_ADDR	 0x202c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_OUTPUT_SIZE	0x2030 /* I/O controller output size Register */ 
	#define BITFIELD_DEMUX_IO_OUTPUT_SIZE	 0x2030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_OUTPUT_SEND_THRESHOLD	0x2038 /* Indicates a watermark for creating an xsi request to send out more stream data.  */ 
	#define BITFIELD_DEMUX_IO_OUTPUT_SEND_THRESHOLD	 0x2038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_IO_OUTPUT_SEND_THRESHOLD */
	#define BLSB_DEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	8
	#define BLSB_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	2
	#define BLSB_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	0
	/* Register Bit Widths for DEMUX_IO_OUTPUT_SEND_THRESHOLD */
	#define BWID_DEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	24
	#define BWID_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	6
	#define BWID_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	2
	/* Register Bit MASKS for DEMUX_IO_OUTPUT_SEND_THRESHOLD */
	#define BMSK_DEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	0xffffff00 /*  */
	#define BMSK_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	0x000000fc /*  */
	#define BMSK_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	0x00000003 /*  */
	/* Register BITFIELD for DEMUX_IO_OUTPUT_SEND_THRESHOLD - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_IO_OUTPUT_SEND_THRESHOLD_RESERVED_31_4	 0x2038, 8, 24, 0xffffff00
	#define BITFIELD_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Threshold_Mask	 0x2038, 2, 6, 0x000000fc
	#define BITFIELD_DEMUX_IO_OUTPUT_SEND_THRESHOLD_Hardwired	 0x2038, 0, 2, 0x00000003
#define ROFF_DEMUX_IO_INPUT_FETCH_THRESHOLD	0x203c /* Indicates a watermark for creating an xsi request to read in more stream data.  */ 
	#define BITFIELD_DEMUX_IO_INPUT_FETCH_THRESHOLD	 0x203c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for DEMUX_IO_INPUT_FETCH_THRESHOLD */
	#define BLSB_DEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	8
	#define BLSB_DEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	2
	#define BLSB_DEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	0
	/* Register Bit Widths for DEMUX_IO_INPUT_FETCH_THRESHOLD */
	#define BWID_DEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	24
	#define BWID_DEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	6
	#define BWID_DEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	2
	/* Register Bit MASKS for DEMUX_IO_INPUT_FETCH_THRESHOLD */
	#define BMSK_DEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	0xffffff00 /*  */
	#define BMSK_DEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	0x000000fc /*  */
	#define BMSK_DEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	0x00000003 /*  */
	/* Register BITFIELD for DEMUX_IO_INPUT_FETCH_THRESHOLD - roff, lsb, width, mask */
	#define BITFIELD_DEMUX_IO_INPUT_FETCH_THRESHOLD_RESERVED_31_4	 0x203c, 8, 24, 0xffffff00
	#define BITFIELD_DEMUX_IO_INPUT_FETCH_THRESHOLD_Threshold_Mask	 0x203c, 2, 6, 0x000000fc
	#define BITFIELD_DEMUX_IO_INPUT_FETCH_THRESHOLD_Hardwired	 0x203c, 0, 2, 0x00000003
#define ROFF_DEMUX_IO_OUTPUT_FIFO_LEVEL	0x2040 /* The number of bytes currently available in the output FIFO for shifting into the DSR.  */ 
	#define BITFIELD_DEMUX_IO_OUTPUT_FIFO_LEVEL	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DMEM_INPUT_ADDR	0x2044 /* Address where data will be taken from DMEM to be placed into the register for shifting */ 
	#define BITFIELD_DEMUX_DMEM_INPUT_ADDR	 0x2044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_DMEM_OUTPUT_ADDR	0x2048 /* Address where data will be written into DMEM from the register that buffers the data being shifted out */ 
	#define BITFIELD_DEMUX_DMEM_OUTPUT_ADDR	 0x2048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_IO_RESERVED1	0x204c /* Reserved */ 
	#define BITFIELD_DEMUX_IO_RESERVED1	 0x204c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_CONTROL	0x2800 /* Host Interface control Register */ 
	#define BITFIELD_DEMUX_HOST_CONTROL	 0x2800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_STATUS	0x2804 /* Host Interface status Register */ 
	#define BITFIELD_DEMUX_HOST_STATUS	 0x2804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_IRQ	0x2808 /* Contains the IPC Doorbell IRQs.  They are cleared by writing a 1. */ 
	#define BITFIELD_DEMUX_HOST_IRQ	 0x2808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_IRQ_MASK	0x280c /* indicates the correlated IRQ signal from the IRQ register is masked. */ 
	#define BITFIELD_DEMUX_HOST_IRQ_MASK	 0x280c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_IPC_STATUS	0x2810 /* Contains the Ready and Done IPC flags for each of the processors. */ 
	#define BITFIELD_DEMUX_HOST_IPC_STATUS	 0x2810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_IPC_DOORBELL	0x2814 /* Command mailbox for communicating with the host processor from the RISC controller. */ 
	#define BITFIELD_DEMUX_HOST_IPC_DOORBELL	 0x2814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_RISC_IPC_DOORBELL	0x2818 /* Command mailbox for communicating with the RISC controller from the host processor. */ 
	#define BITFIELD_DEMUX_RISC_IPC_DOORBELL	 0x2818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_ICACHE_BASE_ADDRESS	0x281c /* Indicates the base address of the firmware image in the XSI memory space.  */ 
	#define BITFIELD_DEMUX_ICACHE_BASE_ADDRESS	 0x281c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_ICACHE_INVALIDATE_0	0x2820 /* Each bit in this register corresponds to a cache line in the RISC instruction cache.  */ 
	#define BITFIELD_DEMUX_ICACHE_INVALIDATE_0	 0x2820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_ICACHE_INVALIDATE_1	0x2824 /* Each bit in this register corresponds to a cache line in the RISC instruction cache. */ 
	#define BITFIELD_DEMUX_ICACHE_INVALIDATE_1	 0x2824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_ICACHE_INVALIDATE_2	0x2828 /* Each bit in this register corresponds to a cache line in the RISC instruction cache. */ 
	#define BITFIELD_DEMUX_ICACHE_INVALIDATE_2	 0x2828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_ICACHE_INVALIDATE_3	0x282c /* Each bit in this register corresponds to a cache line in the RISC instruction cache.  */ 
	#define BITFIELD_DEMUX_ICACHE_INVALIDATE_3	 0x282c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_OMAR_MUX_SEL	0x2830 /* Selects which set of debug signals get passed out the demux to the OMAR unit */ 
	#define BITFIELD_DEMUX_OMAR_MUX_SEL	 0x2830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_LDST_X	0x2834 /* Endian control and byte count for LdSt operations */ 
	#define BITFIELD_DEMUX_LDST_X	 0x2834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_HOST_RESERVED	0x2838 /* Reserved 2 */ 
	#define BITFIELD_DEMUX_HOST_RESERVED	 0x2838, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_Coproc_Interface_Opcode	0x3000 /* The opcode written to this register is passed on to the coprocessor via the coprocessor interface  */ 
	#define BITFIELD_DEMUX_Coproc_Interface_Opcode	 0x3000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_Coproc_Interface_Data	0x3004 /* Data written to this register is passed on to the coprocessor via the coprocessor  */ 
	#define BITFIELD_DEMUX_Coproc_Interface_Data	 0x3004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_DEMUX_Coproc_Interface_Aux	0x3008 /* Auxillary Interface */ 
	#define BITFIELD_DEMUX_Coproc_Interface_Aux	 0x3008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module DEMUX SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_DEMUX_DTS_BUFFER	0x1
#define SVEN_MODULE_EVENT_DEMUX_IN_PORT_EMPTY	0x2
#define SVEN_MODULE_EVENT_DEMUX_IN_BUFFERS_FULL	0x4
#define SVEN_MODULE_EVENT_DEMUX_OUT_PORT_FULL	0x6
#define SVEN_MODULE_EVENT_DEMUX_OUT_ENQUEUE	0x7
#define SVEN_MODULE_EVENT_DEMUX_GET_PENDING_INTERRUPT	0xa
#define SVEN_MODULE_EVENT_DEMUX_GET_BOOT_STATUS	0xb
#define SVEN_MODULE_EVENT_DEMUX_GET_IPC_STATUS	0xc
#define SVEN_MODULE_EVENT_DEMUX_FW_STREAM_EMPTY	0xe
#define SVEN_MODULE_EVENT_DEMUX_FW_FILTER_NODE_DONE	0xf
#define SVEN_MODULE_EVENT_DEMUX_FW_FILTER_FULL	0x10
#define SVEN_MODULE_EVENT_DEMUX_IPC_CMD_ID	0x11
#define SVEN_MODULE_EVENT_DEMUX_IPC_SYNC_MODE	0x12
#define SVEN_MODULE_EVENT_DEMUX_IPC_CMD_ARGS	0x13
#define SVEN_MODULE_EVENT_DEMUX_OUT_BUFFER_SHRINK	0x14
#define SVEN_MODULE_EVENT_DEMUX_OUT_BUFFER_ALLOCATED	0x15
#define SVEN_MODULE_EVENT_DEMUX_OUT_BUFFER_DROPPED	0x16
#define SVEN_MODULE_EVENT_DEMUX_DISCONTINUITY_FROM_FW	0x18
#define SVEN_MODULE_EVENT_DEMUX_PTS_BUFFER	0x1e
#define SVEN_MODULE_EVENT_DEMUX_SECTION_INVALID	0x1f
#define SVEN_MODULE_EVENT_DEMUX_SECTION_BAD_CRC	0x20
#define SVEN_MODULE_EVENT_DEMUX_SECTION_NO_MATCH	0x21
#define SVEN_MODULE_EVENT_DEMUX_SECTION_MATCH	0x22
#define SVEN_MODULE_EVENT_DEMUX_FLUSH_START	0x23
#define SVEN_MODULE_EVENT_DEMUX_FLUSH_COMPLETE	0x24
#define SVEN_MODULE_EVENT_DEMUX_NEW_SEG_OUT	0x26
#define SVEN_MODULE_EVENT_DEMUX_NEW_SEG_IN	0x27
#define SVEN_MODULE_EVENT_DEMUX_DISCONTINUITY_AT_INPUT	0x28
#define SVEN_MODULE_EVENT_DEMUX_DISCONTINUITY_AT_OUTPUT	0x29
#define SVEN_MODULE_EVENT_DEMUX_ALLOC_FAIL_FOR_OUTPUT	0x2a
#define SVEN_MODULE_EVENT_DEMUX_ALLOC_FAILURES	0x2b
#define SVEN_MODULE_EVENT_DEMUX_RELEASE_FAILED	0x2c
#define SVEN_MODULE_EVENT_DEMUX_IN_DEQUEUE	0x2d
#define SVEN_MODULE_EVENT_DEMUX_CONTENT_TIME_GAP	0x2e
#define SVEN_MODULE_EVENT_DEMUX_OPEN	0x2f
#define SVEN_MODULE_EVENT_DEMUX_CLOSE	0x30
#define SVEN_MODULE_EVENT_DEMUX_OVER_FLOW	0x31
#define SVEN_MODULE_EVENT_DEMUX_STATE_CHANGE	0x32
#define SVEN_MODULE_EVENT_DEMUX_IPC_ACK_INTR	0x33
#define SVEN_MODULE_EVENT_DEMUX_IPC_ERROR_CODE	0x34
#define SVEN_MODULE_EVENT_DEMUX_INIT_START	0x35
#define SVEN_MODULE_EVENT_DEMUX_INIT_SUCCESSFUL	0x36
#define SVEN_MODULE_EVENT_DEMUX_INIT_FAIL	0x37
#define SVEN_MODULE_EVENT_DEMUX_DEINIT_START	0x38
#define SVEN_MODULE_EVENT_DEMUX_DEINIT_COMPLETE	0x39
#define SVEN_MODULE_EVENT_DEMUX_DEINIT_CLOSING_STREAM	0x3a
#define SVEN_MODULE_EVENT_DEMUX_CQ_INIT_SUCCESS	0x3b
#define SVEN_MODULE_EVENT_DEMUX_MB_INIT_SUCCESS	0x3c
#define SVEN_MODULE_EVENT_DEMUX_CLIENT_ID_TAG_AT_INPUT	0x3d
#define SVEN_MODULE_EVENT_DEMUX_CLIENT_ID_OUT	0x3e
#define SVEN_MODULE_EVENT_DEMUX_TTM_PTS_RECEIVED	0x3f
#define SVEN_MODULE_EVENT_DEMUX_TTM_PTS_PCR_DELTA	0x40
#define SVEN_MODULE_EVENT_DEMUX_TTM_PCR_RECEIVED	0x41
#define SVEN_MODULE_EVENT_DEMUX_TTM_DISCON_RECEIVED	0x42
#define SVEN_MODULE_EVENT_DEMUX_TTM_NS_RECEIVED1	0x43
#define SVEN_MODULE_EVENT_DEMUX_TTM_NS_RECEIVED2	0x44
#define SVEN_MODULE_EVENT_DEMUX_TTM_NS_PROCESSED1	0x45
#define SVEN_MODULE_EVENT_DEMUX_TTM_NS_PROCESSED2	0x46
#define SVEN_MODULE_EVENT_DEMUX_TTM_COMMIT	0x47
#define SVEN_MODULE_EVENT_DEMUX_TTM_DECOMMIT	0x48
#define SVEN_MODULE_EVENT_DEMUX_FW_STATS1	0x49
#define SVEN_MODULE_EVENT_DEMUX_FW_EBQ_EMPTY	0x4a
#define SVEN_MODULE_EVENT_DEMUX_BUFFERING_EVENT	0x4b
#define SVEN_MODULE_EVENT_DEMUX_INDEXING_FROM_FW	0x4c
#define SVEN_MODULE_EVENT_DEMUX_INDEXING_CONVERTED	0x4d
#define SVEN_MODULE_EVENT_DEMUX_POWER_MODE_SET	0x4e
#define SVEN_MODULE_EVENT_DEMUX_POWER_MODE_FAIL	0x4f
#define SVEN_MODULE_EVENT_DEMUX_GET_TIME_FAIL	0x64
#define SVEN_MODULE_EVENT_DEMUX_SCHED_ALARM_FAIL	0x65
#define SVEN_MODULE_EVENT_DEMUX_CANCEL_ALARM_FAIL	0x66
#define SVEN_MODULE_EVENT_DEMUX_EVENT_ALLOC_FAIL	0x67
#define SVEN_MODULE_EVENT_DEMUX_EVENT_FREE_FAIL	0x68
#define SVEN_MODULE_EVENT_DEMUX_EVENT_WAIT_FAIL	0x69
#define SVEN_MODULE_EVENT_DEMUX_EVENT_SET_FAIL	0x6a
#define SVEN_MODULE_EVENT_DEMUX_EVENT_STROBE_FAIL	0x6b
#define SVEN_MODULE_EVENT_DEMUX_EVENT_ACK_FAIL	0x6c
#define SVEN_MODULE_EVENT_DEMUX_THREAD_CREATE_FAIL	0x6d
#define SVEN_MODULE_EVENT_DEMUX_THREAD_WAIT_FAIL	0x6e
#define SVEN_MODULE_EVENT_DEMUX_THREAD_DESTROY_FAIL	0x6f
#define SVEN_MODULE_EVENT_DEMUX_SEMA_INIT_FAIL	0x70
#define SVEN_MODULE_EVENT_DEMUX_INTERRUPT_ACQUIRE_FAIL	0x71
#define SVEN_MODULE_EVENT_DEMUX_MALLOC_FAIL	0x72
#define SVEN_MODULE_EVENT_DEMUX_MB_INIT_FAIL	0x73
#define SVEN_MODULE_EVENT_DEMUX_MB_FREE_FAIL	0x74
#define SVEN_MODULE_EVENT_DEMUX_MB_WRITE_FAIL	0x75
#define SVEN_MODULE_EVENT_DEMUX_MB_WAKE_FAIL	0x76
#define SVEN_MODULE_EVENT_DEMUX_CQ_INIT_FAIL	0x77
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_ALLOC_FAIL	0x78
#define SVEN_MODULE_EVENT_DEMUX_BUFFER_ALLOC_FAIL	0x79
#define SVEN_MODULE_EVENT_DEMUX_BUFFER_READ_DESC_FAIL	0x7a
#define SVEN_MODULE_EVENT_DEMUX_BUFFER_FREE_FAIL	0x7b
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_FREE_FAIL	0x7c
#define SVEN_MODULE_EVENT_DEMUX_SECURE_LOAD_FAIL	0x7d
#define SVEN_MODULE_EVENT_DEMUX_MEMORY_MAPPING_FAIL	0x7e
#define SVEN_MODULE_EVENT_DEMUX_FW_BOOT_FAIL	0x7f
#define SVEN_MODULE_EVENT_DEMUX_FW_BIST_FAIL	0x80
#define SVEN_MODULE_EVENT_DEMUX_CQ_CREATE_FAIL	0x81
#define SVEN_MODULE_EVENT_DEMUX_PORT_ALLOC_FAIL	0x82
#define SVEN_MODULE_EVENT_DEMUX_CQ_DELETE_FAIL	0x82
#define SVEN_MODULE_EVENT_DEMUX_CQ_READ_FAIL	0x84
#define SVEN_MODULE_EVENT_DEMUX_PORT_FREE_FAIL	0x85
#define SVEN_MODULE_EVENT_DEMUX_ALLOCATOR_FREE_FAILED	0x86
#define SVEN_MODULE_EVENT_DEMUX_CQ_CREATE_FAILURE	0x87
#define SVEN_MODULE_EVENT_DEMUX_CQ_DELETE_QUEUE	0x88
#define SVEN_MODULE_EVENT_DEMUX_CQ_NONE_AVAILABLE	0x89
#define SVEN_MODULE_EVENT_DEMUX_PORT_GET_STATUS_FAIL	0x8a
#define SVEN_MODULE_EVENT_DEMUX_PORT_FLUSH_FAIL	0x8b
#define SVEN_MODULE_EVENT_DEMUX_PORT_SET_NAME_FAIL	0x8c
#define SVEN_MODULE_EVENT_DEMUX_PORT_LOOKAHEAD_FAIL	0x8d
#define SVEN_MODULE_EVENT_DEMUX_PORT_READ_FAIL	0x8e
#define SVEN_MODULE_EVENT_DEMUX_CQ_WRITE_FAIL	0x8f
#define SVEN_MODULE_EVENT_DEMUX_TAG_COPY_FAIL	0x90
#define SVEN_MODULE_EVENT_DEMUX_MB_CREATE_FAIL	0x91
#define SVEN_MODULE_EVENT_DEMUX_PORT_WRITE_FAIL	0x92
#define SVEN_MODULE_EVENT_DEMUX_BUFFER_ADD_REF_FAIL	0x93
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_ROUTE_FAIL	0x94
#define SVEN_MODULE_EVENT_DEMUX_OUT_LIST_ERROR	0x95
#define SVEN_MODULE_EVENT_DEMUX_HIGH_LATENCY	0x96
#define SVEN_MODULE_EVENT_DEMUX_EVENT_RESET_FAIL	0x97
#define SVEN_MODULE_EVENT_DEMUX_BUFFER_ALIAS_FAIL	0x98
#define SVEN_MODULE_EVENT_DEMUX_MB_WRITE_ACK_FAIL	0x99
#define SVEN_MODULE_EVENT_DEMUX_MB_READ_FAIL	0x9a
#define SVEN_MODULE_EVENT_DEMUX_ERR_FROM_FW	0xc8
#define SVEN_MODULE_EVENT_DEMUX_FEATURE_NOT_IMPLEMENTED	0xc9
#define SVEN_MODULE_EVENT_DEMUX_NO_DEMUX	0xca
#define SVEN_MODULE_EVENT_DEMUX_NULL_POINTER_SUPPLIED	0xcb
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_ALLOC_STREAM	0xcc
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_ALLOC_HANDLE	0xcd
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_ALLOC_FILTER	0xce
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_ALLOC_PID	0xcf
#define SVEN_MODULE_EVENT_DEMUX_INVALID_STREAM_HANDLE	0xd0
#define SVEN_MODULE_EVENT_DEMUX_INVALID_FILTER_HANDLE	0xd1
#define SVEN_MODULE_EVENT_DEMUX_INVALID_PID	0xd2
#define SVEN_MODULE_EVENT_DEMUX_STREAM_NOT_IN_USE	0xd3
#define SVEN_MODULE_EVENT_DEMUX_INVALID_STREAM_TYPE	0xd4
#define SVEN_MODULE_EVENT_DEMUX_INVALID_OP_FORMAT	0xd6
#define SVEN_MODULE_EVENT_DEMUX_INVALID_PID_TYPE	0xd7
#define SVEN_MODULE_EVENT_DEMUX_BAD_DEV_STATE	0xd8
#define SVEN_MODULE_EVENT_DEMUX_INVALID_Q_LEVEL	0xd9
#define SVEN_MODULE_EVENT_DEMUX_NO_MORE_EBQS	0xda
#define SVEN_MODULE_EVENT_DEMUX_BUFFER_LEAK	0xdb
#define SVEN_MODULE_EVENT_DEMUX_EBQ_STILL_REFFED	0xdc
#define SVEN_MODULE_EVENT_DEMUX_NO_PID_MAPPING_SLOTS	0xdd
#define SVEN_MODULE_EVENT_DEMUX_OUT_QUEUE_FULL	0xde
#define SVEN_MODULE_EVENT_DEMUX_DEL_PID_WITH_MAPPINGS	0xdf
#define SVEN_MODULE_EVENT_DEMUX_OUT_BUF_WITH_DATA_AND_TAGS	0xe0
#define SVEN_MODULE_EVENT_DEMUX_OUT_BUF_NO_DATA_AND_NO_TAGS	0xe1
#define SVEN_MODULE_EVENT_DEMUX_OUT_MISMATCH	0xe2
#define SVEN_MODULE_EVENT_DEMUX_MANY_FILTERS_EBQ	0xe3
#define SVEN_MODULE_EVENT_DEMUX_NOT_SUPPORTED_ON_PS	0xe4
#define SVEN_MODULE_EVENT_DEMUX_INVALID_SECTION_FILTER_HANDLE	0xe5
#define SVEN_MODULE_EVENT_DEMUX_SF_OPEN_FILTER_NOT_PSI	0xe6
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_ALLOC_SECTION_FILTER	0xe7
#define SVEN_MODULE_EVENT_DEMUX_SET_STR_CLOCK_AFTER_PCR	0xe8
#define SVEN_MODULE_EVENT_DEMUX_UNSET_CLOCK_WITH_ARRIVAL_TIME	0xe9
#define SVEN_MODULE_EVENT_DEMUX_USE_ARRIVAL_TIME_NO_CLOCK	0xea
#define SVEN_MODULE_EVENT_DEMUX_TTM_TIMING_ERROR	0xeb
#define SVEN_MODULE_EVENT_DEMUX_TTM_CANNOT_READ_CLOCK	0xec
#define SVEN_MODULE_EVENT_DEMUX_INVALID_SF_PARAMS	0xed
#define SVEN_MODULE_EVENT_DEMUX_PID_MAPPING_DNE	0xee
#define SVEN_MODULE_EVENT_DEMUX_TSI_FAIL	0xef
#define SVEN_MODULE_EVENT_DEMUX_TSI_ALREADY_IN_USE	0xf0
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_SYNC_OPEN_FAIL	0xf1
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_SYNC_CLOSE_FAIL	0xf2
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_SYNC_SET_CLOCK_FAIL	0xf3
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_SYNC_SET_ALGORITHM_FAIL	0xf4
#define SVEN_MODULE_EVENT_DEMUX_INVALID_TS_INTERFACE	0xf5
#define SVEN_MODULE_EVENT_DEMUX_TSI_NOT_PRESENT	0xf6
#define SVEN_MODULE_EVENT_DEMUX_TSI_INVALID_CIRCBUF_SIZE	0xf7
#define SVEN_MODULE_EVENT_DEMUX_CLOCK_NOT_SET	0xf8
#define SVEN_MODULE_EVENT_DEMUX_INVALID_STAT_TYPE	0xf9
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_CRYPTO_ALG	0xfa
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_RESIDUAL_ALG	0xfb
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_IV_LEN	0xfc
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_ODD_EVEN	0xfd
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_KEY_LEN	0xfe
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_SYS_KEY_LEN	0xff
#define SVEN_MODULE_EVENT_DEMUX_NO_CRYPTO_ON_PSI_INDEXING	0x100
#define SVEN_MODULE_EVENT_DEMUX_MUST_SET_CRYPTO_ALG_FIRST	0x101
#define SVEN_MODULE_EVENT_DEMUX_MULTI2_NOT_SET	0x102
#define SVEN_MODULE_EVENT_DEMUX_NO_PID_OPERATIONS_INDEX	0x103
#define SVEN_MODULE_EVENT_DEMUX_NOT_INDEX_FILTER	0x104
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_COUNT_PKTS_FMT	0x105
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_COUNT_PKTS_TYPE	0x106
#define SVEN_MODULE_EVENT_DEMUX_SET_SLAVE_CLOCK_AFTER_PCR	0x107
#define SVEN_MODULE_EVENT_DEMUX_ERROR_LOW_ATS_BITS_SET	0x108
#define SVEN_MODULE_EVENT_DEMUX_ERROR_UNSUPPORTED_INDEXING_TYPE	0x109
#define SVEN_MODULE_EVENT_DEMUX_INDEXING_PARADIGM_MIXING	0x10a
#define SVEN_MODULE_EVENT_DEMUX_INDEXING_ERROR	0x10b
#define SVEN_MODULE_EVENT_DEMUX_UNKNOWN_SOC	0x10c
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_BYTE_ORDER	0x10d
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_KEY_DECODE_TYPE	0x10e
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_KEY_SRC	0x10f
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_KEY_TYPE	0x110
#define SVEN_MODULE_EVENT_DEMUX_NSK_TABLE_ROW_OUT_OF_RANGE	0x111
#define SVEN_MODULE_EVENT_DEMUX_NSK_KEY_SEL_INVALID	0x112
#define SVEN_MODULE_EVENT_DEMUX_NSK_SLOT_NUM_INVALID	0x113
#define SVEN_MODULE_EVENT_DEMUX_SEC_KEY_SELECT_OUT_OF_RANGE	0x114
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_KEY_LOAD_TYPE	0x115
#define SVEN_MODULE_EVENT_DEMUX_OUT_LIST_INVALID_COUNT	0x116
#define SVEN_MODULE_EVENT_DEMUX_OUT_LIST_INVALID_REF	0x117
#define SVEN_MODULE_EVENT_DEMUX_OUT_LIST_DUP_BUF	0x118
#define SVEN_MODULE_EVENT_DEMUX_LIST_NOT_SUPPORTED_ON_IDX	0x119
#define SVEN_MODULE_EVENT_DEMUX_CANNOT_CTRL_SPLITTING_THIS_TYPE	0x11a
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_CC_ERR_POLICY	0x11b
#define SVEN_MODULE_EVENT_DEMUX_ACC_FULL	0x11c
#define SVEN_MODULE_EVENT_DEMUX_UNSUPPORTED_CRC_CHECK_POLICY	0x11d
#define SVEN_MODULE_EVENT_DEMUX_TSI_BUFFER_OVERRUN	0x15e
#define SVEN_MODULE_EVENT_DEMUX_TSI_PACKET_LOSS	0x15f
#define SVEN_MODULE_EVENT_DEMUX_TSI_OC_FIFO_FULL	0x160
#define SVEN_MODULE_EVENT_DEMUX_TSI_OC_CRC	0x161
#define SVEN_MODULE_EVENT_DEMUX_API_STREAM_OPEN	0x190
#define SVEN_MODULE_EVENT_DEMUX_AUTOAPI_STREAM_CLOSE	0x191
#define SVEN_MODULE_EVENT_DEMUX_API_STREAM_CLOSE	0x192
#define SVEN_MODULE_EVENT_DEMUX_API_STREAM_SET_STATE	0x193
#define SVEN_MODULE_EVENT_DEMUX_API_STREAM_FLUSH	0x194
#define SVEN_MODULE_EVENT_DEMUX_API_STREAM_SET_CLOCK	0x195
#define SVEN_MODULE_EVENT_DEMUX_API_USE_ARRIVAL_TIME	0x196
#define SVEN_MODULE_EVENT_DEMUX_API_SET_BUFFERING_EVENT	0x197
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_OPEN	0x198
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_CLOSE	0x199
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_START	0x19a
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_STOP	0x19b
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_FLUSH	0x19c
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_MAP_TO_PID	0x19d
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_UNMAP_FROM_PID	0x19e
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_MAP_TO_PIDS	0x19f
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_UNMAP_FROM_PIDS	0x1a0
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_GET_MAPPED_PIDS	0x1a1
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_MAP_TO_SID	0x1a2
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_UNMAP_FROM_SID	0x1a3
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_GET_MAPPED_SID	0x1a4
#define SVEN_MODULE_EVENT_DEMUX_API_PID_START	0x1a5
#define SVEN_MODULE_EVENT_DEMUX_API_PID_STOP	0x1a6
#define SVEN_MODULE_EVENT_DEMUX_API_GET_INPUT_PORT	0x1a7
#define SVEN_MODULE_EVENT_DEMUX_API_GET_OUTPUT_PORT	0x1a8
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_OPEN	0x1a9
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_CLOSE	0x1aa
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_SET_PARAMS	0x1ab
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_START	0x1ac
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_STOP	0x1ad
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_START_BY_PID	0x1ae
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_STOP_BY_PID	0x1af
#define SVEN_MODULE_EVENT_DEMUX_API_EN_DISCON_DETECT	0x1b0
#define SVEN_MODULE_EVENT_DEMUX_API_DIS_DISCON_DETECT	0x1b1
#define SVEN_MODULE_EVENT_DEMUX_API_SET_PCR_PID	0x1b2
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_OPEN	0x1b3
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_SET_OVERRUN_EVENT	0x1b4
#define SVEN_MODULE_EVENT_DEMUX_API_STREAM_SET_BASE_TIME	0x1b5
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_SET_NIM_CONFIG	0x1b6
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_GET_BUFFER_LEVEL	0x1b7
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_SET_BUFFER_SIZE	0x1b8
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_ENABLE_CLOCK_RECOVERY	0x1b9
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_DISABLE_CLOCK_RECOVERY	0x1ba
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_GET_CLOCK	0x1bb
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_GET_RECOVERY_CLOCK	0x1bc
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_SET_OPEN_CABLE_LTSID	0x1bd
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_GET_OPEN_CABLE_LTSID	0x1be
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_SET_OPEN_CABLE_MODE	0x1bf
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_GET_OPEN_CABLE_MODE	0x1c0
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_ENABLE_INTERNAL_BYPASS	0x1c1
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_DISABLE_INTERNAL_BYPASS	0x1c2
#define SVEN_MODULE_EVENT_DEMUX_API_ADD_STREAM_ID_EXTENSION_TO_PID	0x1c3
#define SVEN_MODULE_EVENT_DEMUX_API_REMOVE_STREAM_ID_EXTENSION_FROM_PID	0x1c4
#define SVEN_MODULE_EVENT_DEMUX_API_ENABLE_PES_PVT_DATA	0x1c5
#define SVEN_MODULE_EVENT_DEMUX_API_DISABLE_PES_PVT_DATA	0x1c6
#define SVEN_MODULE_EVENT_DEMUX_API_ENABLE_LEAKY_FILTERS	0x1c7
#define SVEN_MODULE_EVENT_DEMUX_API_DISABLE_LEAKY_FILTERS	0x1c8
#define SVEN_MODULE_EVENT_DEMUX_API_GET_STATS	0x1c9
#define SVEN_MODULE_EVENT_DEMUX_API_RESET_STAT	0x1ca
#define SVEN_MODULE_EVENT_DEMUX_API_TS_LOAD_KEY1	0x1cb
#define SVEN_MODULE_EVENT_DEMUX_API_TS_LOAD_KEY2	0x1cc
#define SVEN_MODULE_EVENT_DEMUX_API_TS_SET_CRYPTO_PARAMS	0x1cd
#define SVEN_MODULE_EVENT_DEMUX_API_TS_SET_SYSTEM_KEY	0x1ce
#define SVEN_MODULE_EVENT_DEMUX_API_TS_SET_KEY	0x1cf
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_SET_TS_CRYPTO	0x1d0
#define SVEN_MODULE_EVENT_DEMUX_API_RESET_INDEX_COUNT	0x1d1
#define SVEN_MODULE_EVENT_DEMUX_API_SET_INDEXING_ON_PID	0x1d2
#define SVEN_MODULE_EVENT_DEMUX_API_SET_PKT_CNTG_FILTER	0x1d3
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_OPEN_INDEXER	0x1d4
#define SVEN_MODULE_EVENT_DEMUX_API_SET_DISCON_EVENT	0x1d5
#define SVEN_MODULE_EVENT_DEMUX_API_SET_SLAVE_CLOCK	0x1d6
#define SVEN_MODULE_EVENT_DEMUX_API_GET_STREAM_POSITION	0x1d7
#define SVEN_MODULE_EVENT_DEMUX_API_TSIN_SET_TS192_UPPER_BITS	0x1d8
#define SVEN_MODULE_EVENT_DEMUX_API_INDEXING_CONFIGURE_PID	0x1d9
#define SVEN_MODULE_EVENT_DEMUX_API_INDEXING_REMOVE_PID	0x1da
#define SVEN_MODULE_EVENT_DEMUX_API_INDEXING_REMOVE_ALL_PIDS	0x1dc
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_SET_OVERRUN_EVENT	0x1dd
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_SET_OVERRUN_RECOVERED_EVENT	0x1de
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_SET_CRC_EVENT	0x1df
#define SVEN_MODULE_EVENT_DEMUX_API_DESCRAMBLE_SET_PARAMS	0x1e0
#define SVEN_MODULE_EVENT_DEMUX_API_DESCRAMBLE_SET_KEY_DIRECT	0x1e1
#define SVEN_MODULE_EVENT_DEMUX_API_DESCRAMBLE_SET_KEY_INDIRECT	0x1e2
#define SVEN_MODULE_EVENT_DEMUX_API_DESCRAMBLE_SET_SYSTEM_KEY	0x1e3
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_ENABLE_LEAKY	0x1e4
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_DISABLE_LEAKY	0x1e5
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_OPEN_PRESET_BUFFERS	0x1e6
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_DISABLE_BUFFER_SPLITTING	0x1e7
#define SVEN_MODULE_EVENT_DEMUX_API_FILTER_ENABLE_BUFFER_SPLITTING	0x1e8
#define SVEN_MODULE_EVENT_DEMUX_API_TS_SET_CC_ERROR_POLICY	0x1e9
#define SVEN_MODULE_EVENT_DEMUX_API_SECTION_FILTER_SET_CRC_CHECK_POLICY	0x1ea
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_INPUT_STREAM	0x200
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_CONTROL_INPUT_STREAM	0x201
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_FILTER	0x202
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_CTRL_CRYPTO_ON_FILTER	0x203
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_ADD_PID	0x204
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_ADD_FILTER_TO_PID	0x205
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_CONTROL_PID	0x206
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_CONTROL_FILTER	0x207
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_DELETE_PID	0x1fe
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_DELETE_FILTER_FROM_PID	0x209
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_FILTER_WPA	0x20a
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_ADD_MM_FILTER	0x20b
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_CRYPTO_PARAMS	0x20c
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_CRYPTO_KEY	0x20d
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_STR_CRYPTO_INFO	0x20e
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_RESET_INDEX_COUNT	0x20f
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_DISCONT_PKT_STREAM_ID	0x210
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_PCR_PID	0x211
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_RESET_FILTER	0x212
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_RESET_STREAM	0x213
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_STREAM_LOW_WM	0x214
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_FILTER_HIGH_WM	0x215
#define SVEN_MODULE_EVENT_DEMUX_FW_RCV_IPC_CMD_SET_FILTER_CF	0x216
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_TOO_MANY_THREADS	0x258
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_TOO_MANY_MODULES	0x259
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_NULL_STATE_MEM	0x25a
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_NULL_ISR_ADDR	0x25b
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_NULL_MINTR_ADDR	0x25c
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_NULL_MINTRM_ADDR	0x25d
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_ZERO_MMSK	0x25e
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_INIT_DONE	0x25f
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_MODULE_NULL_PROC_FUNC	0x260
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_MODULE_DUP_ID	0x261
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_MODULE_NO_ISR_BITS	0x262
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_MODULE_ID_TOO_BIG	0x263
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_MODULE_DONE	0x264
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK_ID_TOO_BIG	0x265
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK_NULL_DATA	0x266
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK_UNINITIALIZED_MODULE	0x267
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK_ALREADY_EXISTS	0x268
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK_DOUBLE_DIPPING	0x269
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK	0x26a
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ADD_TASK_KICK	0x26b
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_START_MODULE	0x26c
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_END_MODULE	0x26d
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_CALL_ISR_FUNC	0x26e
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_DONE_ISR_FUNC	0x26f
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_CALL_ISR_FAILURE	0x270
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_MODULE_DONE	0x271
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_UNBLOCK_THREAD	0x272
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_CALL_PROC_FUNC	0x273
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_DONE_PROC_FUNC	0x274
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_CALL_PROC_FAILURE	0x275
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_ENTER	0x276
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_ISR_EXIT	0x277
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_THR_ID_TOO_BIG	0x278
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_THR_INVALID_PRIORITY	0x279
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_THR_NULL_FUNC_TABL	0x27a
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_THR_DUP_ID	0x27b
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_REG_THR_DONE	0x27c
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_UNREG_THR_ID_TOO_BIG	0x27d
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_UNREG_THR_NOT_INITIALIZED	0x27e
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_UNREG_THR_DONE	0x27f
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_ENTERED	0x280
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_CHK_THREAD	0x281
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_SEL_THREAD	0x282
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_CALL_THREAD	0x283
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_DONE_THREAD	0x284
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_CHANGE_TO_LP	0x285
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SCHED_CHANGE_TO_HP	0x286
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SET_THR_STATE_UNINITIALIZED	0x287
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SET_THR_STATE	0x288
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SET_THR_IDLE_UNINITIALIZED	0x289
#define SVEN_MODULE_EVENT_DEMUX_FW_KERN_DBG_SET_THR_IDLE	0x28a
#define SVEN_MODULE_EVENT_DEMUX_FW_HAL_INIT	0x2bc
#define SVEN_MODULE_EVENT_DEMUX_FW_HAL_INIT_SUCCESS	0x2bd
#define SVEN_MODULE_EVENT_DEMUX_FW_HAL_ISR_ENTER	0x2be
#define SVEN_MODULE_EVENT_DEMUX_FW_HAL_ISR_EXIT	0x2bf
#define SVEN_MODULE_EVENT_DEMUX_FW_HAL_CRITICAL_ERROR	0x2c0
#define SVEN_MODULE_EVENT_DEMUX_FW_HAL_DMA_BUSY	0x2c1
#define SVEN_MODULE_EVENT_DEMUX_FW_IPC_ERROR	0x384
#define SVEN_MODULE_EVENT_DEMUX_FW_TS_PROCESSING_ERROR	0x385
#define SVEN_MODULE_EVENT_DEMUX_FW_NEED_DATA	0x386
#define SVEN_MODULE_EVENT_DEMUX_FW_PES_PARSE_GOT_PUSI	0x387
#define SVEN_MODULE_EVENT_DEMUX_FW_PES_PARSE_IDLE	0x388
#define SVEN_MODULE_EVENT_DEMUX_FW_PSI_PROCESSING_ERROR	0x389
#define SVEN_MODULE_EVENT_DEMUX_FW_PSI_PWNED	0x38a
#define SVEN_MODULE_EVENT_DEMUX_FW_PSI_BUFFER_LEAK	0x38b
#define SVEN_MODULE_EVENT_DEMUX_FW_PSI_CANT_GET_ACCUMULATOR	0x38c
#define SVEN_MODULE_EVENT_DEMUX_FW_PSI_SIZE_MISMATCH	0x38d
#define SVEN_MODULE_EVENT_DEMUX_FW_POWER_MODE_SET	0x38e
#define SVEN_MODULE_EVENT_DEMUX_FW_PS_PROCESSING_ERROR	0x38f


#endif /* DEMUX_REGOFFS_H */
