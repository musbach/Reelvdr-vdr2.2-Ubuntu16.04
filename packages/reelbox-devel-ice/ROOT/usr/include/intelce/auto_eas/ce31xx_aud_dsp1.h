#ifndef AUD_DSP1_REGOFFS_H
#define AUD_DSP1_REGOFFS_H 1
#warning including deprecated file AUD_DSP1_REGOFFS_H please use sanitized filename
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


/* Module AUD_DSP1 CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_AUD_DSP1_CSR	0x0 /* CSR - DSP1 Configuration and Status Register. This register controls clock and reset of the block, various configurations of the block and reflects general status of the block. default(00008001h)  */ 
	#define BITFIELD_AUD_DSP1_CSR	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_CSR */
	#define BLSB_AUD_DSP1_CSR_RESERVED_31_25	25
	#define BLSB_AUD_DSP1_CSR_CODEC_FUSE	20
	#define BLSB_AUD_DSP1_CSR_RESERVED_19_18	18
	#define BLSB_AUD_DSP1_CSR_REMAP_SIZE	16
	#define BLSB_AUD_DSP1_CSR_REMAP	4
	#define BLSB_AUD_DSP1_CSR_RESERVED_3_2	2
	#define BLSB_AUD_DSP1_CSR_DSP_RST	1
	#define BLSB_AUD_DSP1_CSR_RESERVED_0_0	0
	/* Register Bit Widths for AUD_DSP1_CSR */
	#define BWID_AUD_DSP1_CSR_RESERVED_31_25	7
	#define BWID_AUD_DSP1_CSR_CODEC_FUSE	5
	#define BWID_AUD_DSP1_CSR_RESERVED_19_18	2
	#define BWID_AUD_DSP1_CSR_REMAP_SIZE	2
	#define BWID_AUD_DSP1_CSR_REMAP	12
	#define BWID_AUD_DSP1_CSR_RESERVED_3_2	2
	#define BWID_AUD_DSP1_CSR_DSP_RST	1
	#define BWID_AUD_DSP1_CSR_RESERVED_0_0	1
	/* Register Bit MASKS for AUD_DSP1_CSR */
	#define BMSK_AUD_DSP1_CSR_RESERVED_31_25	0xfe000000 /* Reserved, bit(s):31:25, default(0h), access(RO) */
	#define BMSK_AUD_DSP1_CSR_CODEC_FUSE	0x01f00000 /* These are fuse bits that enable different CODECs. The specific Fuses need to be defined.<TBD>, bit(s):24:20, default(0b), access(RO) */
	#define BMSK_AUD_DSP1_CSR_RESERVED_19_18	0x000c0000 /* Reserved, bit(s):19:18, default(0b), access(RO) */
	#define BMSK_AUD_DSP1_CSR_REMAP_SIZE	0x00030000 /* Sets the size of the remap window. 00-> 1Mbyte window ( REMAP bits 15:4 are valid) -Default 01 -> 4Mbyte window (REMAP bits) 15:6 are valid) 10 -> 8Mbyte window (REMAP bits 15: 7 are valid) 11 -> 16Mbyte window (REMAP bits 15:8 are valid), bit(s):17:16, default(0h), access(RW) */
	#define BMSK_AUD_DSP1_CSR_REMAP	0x0000fff0 /* REMAP -12 bit field remapping value for DSP Core  addressing IA32 addresses. The default value is 800h. The size of this bit field is determined by the REMAP_SIZE bits., bit(s):15:4, default(800h), access(RV) */
	#define BMSK_AUD_DSP1_CSR_RESERVED_3_2	0x0000000c /* Reserved , bit(s):3:2, default(0b), access(RO) */
	#define BMSK_AUD_DSP1_CSR_DSP_RST	(1<<1) /* == 0x00000002: DSP Reset. Asserted low, DSP is held in reset state until this bit is set to 1. Minimum number of cycles is defined DSP manual., bit(s):1, default(0b), access(RW) */
	#define BMSK_AUD_DSP1_CSR_RESERVED_0_0	(1<<0) /* == 0x00000001: Reserved , bit(s):0:0, default(0b), access(RO) */
	/* Register BITFIELD for AUD_DSP1_CSR - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_CSR_RESERVED_31_25	 0x0000, 25, 7, 0xfe000000
	#define BITFIELD_AUD_DSP1_CSR_CODEC_FUSE	 0x0000, 20, 5, 0x01f00000
	#define BITFIELD_AUD_DSP1_CSR_RESERVED_19_18	 0x0000, 18, 2, 0x000c0000
	#define BITFIELD_AUD_DSP1_CSR_REMAP_SIZE	 0x0000, 16, 2, 0x00030000
	#define BITFIELD_AUD_DSP1_CSR_REMAP	 0x0000, 4, 12, 0x0000fff0
	#define BITFIELD_AUD_DSP1_CSR_RESERVED_3_2	 0x0000, 2, 2, 0x0000000c
	#define BITFIELD_AUD_DSP1_CSR_DSP_RST	 0x0000, 1, 1, 0x00000002
	#define BITFIELD_AUD_DSP1_CSR_RESERVED_0_0	 0x0000, 0, 1, 0x00000001
#define ROFF_AUD_DSP1_ISRX	0x4 /* ISRX - DSP1 IA32 Interrupt Status Register. This register reflects status of an interrupted mapped event.  default(00000000h) */ 
	#define BITFIELD_AUD_DSP1_ISRX	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_ISRX */
	#define BLSB_AUD_DSP1_ISRX_RESERVED_31_2	2
	#define BLSB_AUD_DSP1_ISRX_IPCD_INT_REQ	1
	#define BLSB_AUD_DSP1_ISRX_IPCX_INT_REQ	0
	/* Register Bit Widths for AUD_DSP1_ISRX */
	#define BWID_AUD_DSP1_ISRX_RESERVED_31_2	30
	#define BWID_AUD_DSP1_ISRX_IPCD_INT_REQ	1
	#define BWID_AUD_DSP1_ISRX_IPCX_INT_REQ	1
	/* Register Bit MASKS for AUD_DSP1_ISRX */
	#define BMSK_AUD_DSP1_ISRX_RESERVED_31_2	0xfffffffc /* Reserved, bit(s):31:2, default(0), access(RW) */
	#define BMSK_AUD_DSP1_ISRX_IPCD_INT_REQ	(1<<1) /* == 0x00000002: IPCD Interrupt Request 1: interrupt when DSP writes a message into IPCD register with bit 31 set 0: Deasserted, bit(s):1, default(0b), access(RWC) */
	#define BMSK_AUD_DSP1_ISRX_IPCX_INT_REQ	(1<<0) /* == 0x00000001: IPCX Interrupt Request 1: interrupt when DSP writes a message into IPCX register with bit 30 set is asserted 0: Deasserted., bit(s):0, default(0b), access(RWC) */
	/* Register BITFIELD for AUD_DSP1_ISRX - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_ISRX_RESERVED_31_2	 0x0004, 2, 30, 0xfffffffc
	#define BITFIELD_AUD_DSP1_ISRX_IPCD_INT_REQ	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_AUD_DSP1_ISRX_IPCX_INT_REQ	 0x0004, 0, 1, 0x00000001
#define ROFF_AUD_DSP1_ISRD	0x8 /* ISRD - DSP1 DSP Interrupt Status Register. This register reflects status of an interrupted mapped event.  default(00000000h) */ 
	#define BITFIELD_AUD_DSP1_ISRD	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_ISRD */
	#define BLSB_AUD_DSP1_ISRD_RESERVED_31_2	2
	#define BLSB_AUD_DSP1_ISRD_IPCX_INT_REQ	1
	#define BLSB_AUD_DSP1_ISRD_IPCD_INT_REQ	0
	/* Register Bit Widths for AUD_DSP1_ISRD */
	#define BWID_AUD_DSP1_ISRD_RESERVED_31_2	30
	#define BWID_AUD_DSP1_ISRD_IPCX_INT_REQ	1
	#define BWID_AUD_DSP1_ISRD_IPCD_INT_REQ	1
	/* Register Bit MASKS for AUD_DSP1_ISRD */
	#define BMSK_AUD_DSP1_ISRD_RESERVED_31_2	0xfffffffc /* Reserved, bit(s):31:2, default(0b), access(RW) */
	#define BMSK_AUD_DSP1_ISRD_IPCX_INT_REQ	(1<<1) /* == 0x00000002: IPCX Interrupt Request to DSP 1: interrupt when IA CPU writes a message into IPCX register with bit 31 set. 0: Deasserted, bit(s):1, default(0b), access(RWC) */
	#define BMSK_AUD_DSP1_ISRD_IPCD_INT_REQ	(1<<0) /* == 0x00000001: IPCD Interrupt Request to DSP 1: interrupt when IA CPU writes a message into IPCD register with bit 30 set is asserted 0: Deasserted., bit(s):0, default(0b), access(RWC) */
	/* Register BITFIELD for AUD_DSP1_ISRD - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_ISRD_RESERVED_31_2	 0x0008, 2, 30, 0xfffffffc
	#define BITFIELD_AUD_DSP1_ISRD_IPCX_INT_REQ	 0x0008, 1, 1, 0x00000002
	#define BITFIELD_AUD_DSP1_ISRD_IPCD_INT_REQ	 0x0008, 0, 1, 0x00000001
#define ROFF_AUD_DSP1_IMRX	0xc /* IMRX - DSP1 IA32 Interrupt Mask Register. This register enables/disables interrupts. default(00000000h)  */ 
	#define BITFIELD_AUD_DSP1_IMRX	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_IMRX */
	#define BLSB_AUD_DSP1_IMRX_RESERVED_31_1	1
	#define BLSB_AUD_DSP1_IMRX_IPCD_INT_EN_IA	1
	#define BLSB_AUD_DSP1_IMRX_IPCX_INT_EN_IA	0
	/* Register Bit Widths for AUD_DSP1_IMRX */
	#define BWID_AUD_DSP1_IMRX_RESERVED_31_1	31
	#define BWID_AUD_DSP1_IMRX_IPCD_INT_EN_IA	1
	#define BWID_AUD_DSP1_IMRX_IPCX_INT_EN_IA	1
	/* Register Bit MASKS for AUD_DSP1_IMRX */
	#define BMSK_AUD_DSP1_IMRX_RESERVED_31_1	0xfffffffe /* Reserved, bit(s):31:1, default(0h), access(RO) */
	#define BMSK_AUD_DSP1_IMRX_IPCD_INT_EN_IA	(1<<1) /* == 0x00000002: IPCD interrupt Enable to IA CPU, bit(s):1, default(0b), access(RWC) */
	#define BMSK_AUD_DSP1_IMRX_IPCX_INT_EN_IA	(1<<0) /* == 0x00000001: IPCX Interrupt Enable to IA CPU, bit(s):0, default(0b), access(RWC) */
	/* Register BITFIELD for AUD_DSP1_IMRX - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_IMRX_RESERVED_31_1	 0x000c, 1, 31, 0xfffffffe
	#define BITFIELD_AUD_DSP1_IMRX_IPCD_INT_EN_IA	 0x000c, 1, 1, 0x00000002
	#define BITFIELD_AUD_DSP1_IMRX_IPCX_INT_EN_IA	 0x000c, 0, 1, 0x00000001
#define ROFF_AUD_DSP1_IMRD	0x10 /* IMRD - DSP1 DSP Interrupt Mask Register. This register enables/disables interrupts.  default(00000000h) */ 
	#define BITFIELD_AUD_DSP1_IMRD	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_IMRD */
	#define BLSB_AUD_DSP1_IMRD_RESERVED_31_2	2
	#define BLSB_AUD_DSP1_IMRD_IPCX_INT_EN_DSP	1
	#define BLSB_AUD_DSP1_IMRD_IPCD_INT_EN_DSP	0
	/* Register Bit Widths for AUD_DSP1_IMRD */
	#define BWID_AUD_DSP1_IMRD_RESERVED_31_2	30
	#define BWID_AUD_DSP1_IMRD_IPCX_INT_EN_DSP	1
	#define BWID_AUD_DSP1_IMRD_IPCD_INT_EN_DSP	1
	/* Register Bit MASKS for AUD_DSP1_IMRD */
	#define BMSK_AUD_DSP1_IMRD_RESERVED_31_2	0xfffffffc /* Reserved, bit(s):31:2, default(0h), access(RO) */
	#define BMSK_AUD_DSP1_IMRD_IPCX_INT_EN_DSP	(1<<1) /* == 0x00000002: IPCX interrupt Enable to DSP Core, bit(s):1, default(0b), access(RWC) */
	#define BMSK_AUD_DSP1_IMRD_IPCD_INT_EN_DSP	(1<<0) /* == 0x00000001: IPCD interrupt Enable to DSP core, bit(s):0, default(0b), access(RW) */
	/* Register BITFIELD for AUD_DSP1_IMRD - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_IMRD_RESERVED_31_2	 0x0010, 2, 30, 0xfffffffc
	#define BITFIELD_AUD_DSP1_IMRD_IPCX_INT_EN_DSP	 0x0010, 1, 1, 0x00000002
	#define BITFIELD_AUD_DSP1_IMRD_IPCD_INT_EN_DSP	 0x0010, 0, 1, 0x00000001
#define ROFF_AUD_DSP1_IPCX	0x14 /* IPCX - DSP1 Inter-process Communication register for IA32 CPU. This register is used for IA32 messaging to the DSP default(00000000h) */ 
	#define BITFIELD_AUD_DSP1_IPCX	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_IPCX */
	#define BLSB_AUD_DSP1_IPCX_DSP_BUSY	31
	#define BLSB_AUD_DSP1_IPCX_DSP_DONE	30
	#define BLSB_AUD_DSP1_IPCX_CPU_TO_DSP_MESSAGE	0
	/* Register Bit Widths for AUD_DSP1_IPCX */
	#define BWID_AUD_DSP1_IPCX_DSP_BUSY	1
	#define BWID_AUD_DSP1_IPCX_DSP_DONE	1
	#define BWID_AUD_DSP1_IPCX_CPU_TO_DSP_MESSAGE	30
	/* Register Bit MASKS for AUD_DSP1_IPCX */
	#define BMSK_AUD_DSP1_IPCX_DSP_BUSY	(1<<31) /* == 0x80000000: Busy. When this bit is cleared, the DSP Ready to accept a message, bit(s):31, default(0b), access(RW) */
	#define BMSK_AUD_DSP1_IPCX_DSP_DONE	(1<<30) /* == 0x40000000: Done. When the bit is set, the DSP completed the operation and requests attention, bit(s):30, default(0b), access(RW) */
	#define BMSK_AUD_DSP1_IPCX_CPU_TO_DSP_MESSAGE	0x3fffffff /* CPU to DSP Message, bit(s):29:0, default(0000h), access(RW) */
	/* Register BITFIELD for AUD_DSP1_IPCX - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_IPCX_DSP_BUSY	 0x0014, 31, 1, 0x80000000
	#define BITFIELD_AUD_DSP1_IPCX_DSP_DONE	 0x0014, 30, 1, 0x40000000
	#define BITFIELD_AUD_DSP1_IPCX_CPU_TO_DSP_MESSAGE	 0x0014, 0, 30, 0x3fffffff
#define ROFF_AUD_DSP1_IPCD	0x18 /* IPCD - DSP1 Inter-process Communication for DSP. This register is used for DSP messaging to IA32. default(00000000h) */ 
	#define BITFIELD_AUD_DSP1_IPCD	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for AUD_DSP1_IPCD */
	#define BLSB_AUD_DSP1_IPCD_IA_BUSY	31
	#define BLSB_AUD_DSP1_IPCD_IA_DONE	30
	#define BLSB_AUD_DSP1_IPCD_DSP_TO_CPU_MESSAGE	0
	/* Register Bit Widths for AUD_DSP1_IPCD */
	#define BWID_AUD_DSP1_IPCD_IA_BUSY	1
	#define BWID_AUD_DSP1_IPCD_IA_DONE	1
	#define BWID_AUD_DSP1_IPCD_DSP_TO_CPU_MESSAGE	30
	/* Register Bit MASKS for AUD_DSP1_IPCD */
	#define BMSK_AUD_DSP1_IPCD_IA_BUSY	(1<<31) /* == 0x80000000: Busy. When this bit is cleared, the IA CPU is Ready to accept a new message, bit(s):31, default(0b), access(RW) */
	#define BMSK_AUD_DSP1_IPCD_IA_DONE	(1<<30) /* == 0x40000000: Done. When the bit is set, the IA CPU completed operation and requests attention from DSP, bit(s):30, default(0b), access(RW) */
	#define BMSK_AUD_DSP1_IPCD_DSP_TO_CPU_MESSAGE	0x3fffffff /* DSP to IA CPU Message, bit(s):29:0, default(0000h), access(RO) */
	/* Register BITFIELD for AUD_DSP1_IPCD - roff, lsb, width, mask */
	#define BITFIELD_AUD_DSP1_IPCD_IA_BUSY	 0x0018, 31, 1, 0x80000000
	#define BITFIELD_AUD_DSP1_IPCD_IA_DONE	 0x0018, 30, 1, 0x40000000
	#define BITFIELD_AUD_DSP1_IPCD_DSP_TO_CPU_MESSAGE	 0x0018, 0, 30, 0x3fffffff


/* Module AUD_DSP1 SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_AUD_DSP1_CUSTOM_MESSAGE	0x1
#define SVEN_MODULE_EVENT_AUD_DSP1_HOST_MSG_RECEIVED	0x2
#define SVEN_MODULE_EVENT_AUD_DSP1_PIPE_REMOVED	0x3
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_API_INIT_COMPLETE	0x4
#define SVEN_MODULE_EVENT_AUD_DSP1_STREAM_SYNC_FOUND	0x5
#define SVEN_MODULE_EVENT_AUD_DSP1_FRAME_DECODED	0x6
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_API_INIT_FAILED	0x7
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_GENERATED_OUTPUT	0x8
#define SVEN_MODULE_EVENT_AUD_DSP1_FW_LOADED	0x9
#define SVEN_MODULE_EVENT_AUD_DSP1_UNSUPPORTED_CODEC	0xa
#define SVEN_MODULE_EVENT_AUD_DSP1_INVALID_HOST_REQUEST	0xb
#define SVEN_MODULE_EVENT_AUD_DSP1_SET_MEM_PTR_COMPLETE	0xc
#define SVEN_MODULE_EVENT_AUD_DSP1_SET_MEM_PTR_FAILED	0xd
#define SVEN_MODULE_EVENT_AUD_DSP1_SET_CODEC_PARAM_COMPLETE	0xe
#define SVEN_MODULE_EVENT_AUD_DSP1_SET_CODEC_PARAM_FAILED	0xf
#define SVEN_MODULE_EVENT_AUD_DSP1_DECODE_FRAME_FAILED	0x10
#define SVEN_MODULE_EVENT_AUD_DSP1_PIPE_STOPPED	0x11
#define SVEN_MODULE_EVENT_AUD_DSP1_HTODMAILBOX_VALUE	0x12
#define SVEN_MODULE_EVENT_AUD_DSP1_PIPE_STARTED	0x13
#define SVEN_MODULE_EVENT_AUD_DSP1_STAGE_INFO	0x14
#define SVEN_MODULE_EVENT_AUD_DSP1_JOB_EXECUTION_FAILED	0x15
#define SVEN_MODULE_EVENT_AUD_DSP1_JOB_EXECUTION_COMPLETE	0x16
#define SVEN_MODULE_EVENT_AUD_DSP1_STAGE_EXECUTION_FAILED	0x17
#define SVEN_MODULE_EVENT_AUD_DSP1_STAGE_EXECUTION_COMPLETE	0x18
#define SVEN_MODULE_EVENT_AUD_DSP1_PSM_BUFFER	0x19
#define SVEN_MODULE_EVENT_AUD_DSP1_AUX_PSM_BUFFER_ASSIGNED	0x1a
#define SVEN_MODULE_EVENT_AUD_DSP1_AUX_PSM_BUFFER_UNAVAILABLE	0x1b
#define SVEN_MODULE_EVENT_AUD_DSP1_NO_OUTPUT	0x1c
#define SVEN_MODULE_EVENT_AUD_DSP1_INTERRUPT_HANDLER	0x1d
#define SVEN_MODULE_EVENT_AUD_DSP1_EXCEPTION_HANDLER	0x1e
#define SVEN_MODULE_EVENT_AUD_DSP1_NO_INPUT_JOB	0x1f
#define SVEN_MODULE_EVENT_AUD_DSP1_PIPE_ADDED	0x20
#define SVEN_MODULE_EVENT_AUD_DSP1_PIPE_CONFIGURED	0x21
#define SVEN_MODULE_EVENT_AUD_DSP1_CUSTOM_MESSAGE_DECIMAL_VALUE	0x22
#define SVEN_MODULE_EVENT_AUD_DSP1_DECODER_FLUSH	0x23
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_SRC_STAGE	0x24
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_PACKETIZER_STAGE	0x25
#define SVEN_MODULE_EVENT_AUD_DSP1_INPUT_STAGE_BUFFER_DEQUEUE	0x26
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_API_INIT	0x27
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_BUFFER_UPDATE	0x28
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_INIT_NOT_DONE	0x29
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_SET_MEMTABS	0x2a
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_SET_PERSISTANT	0x2b
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_SET_SCRATCH	0x2c
#define SVEN_MODULE_EVENT_AUD_DSP1_PACKETIZER_SYNC_NOT_FOUND	0x2d
#define SVEN_MODULE_EVENT_AUD_DSP1_PACKETIZER_INVALID_FRAME_SIZE	0x2e
#define SVEN_MODULE_EVENT_AUD_DSP1_PACKETIZER_FRAME_INFO	0x2f
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_DMIX_STAGE	0x30
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_INTRLVR_STAGE	0x31
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_DEINTRLVR_STAGE	0x32
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_MIXER_STAGE	0x33
#define SVEN_MODULE_EVENT_AUD_DSP1_PCM_DVD_HEADER_INFO	0x34
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_DATA_DIVIDER_STAGE	0x35
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_OUTPUT_STAGE	0x36
#define SVEN_MODULE_EVENT_AUD_DSP1_INVALID_METADATA	0x37
#define SVEN_MODULE_EVENT_AUD_DSP1_INVALID_CH_CONFIG	0x38
#define SVEN_MODULE_EVENT_AUD_DSP1_CH_CONFIG_INFO	0x39
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_BASS_MAN_STAGE	0x3a
#define SVEN_MODULE_EVENT_AUD_DSP1_PIPE_STAGE_PERFORMANCE	0x3b
#define SVEN_MODULE_EVENT_AUD_DSP1_PCM_DECODE_FLUSH	0x3c
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_PRESRC_STAGE	0x3d
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_DELAY_MAN_STAGE	0x3e
#define SVEN_MODULE_EVENT_AUD_DSP1_STAGE_BYPASS	0x3f
#define SVEN_MODULE_EVENT_AUD_DSP1_STAGE_IN_USE	0x40
#define SVEN_MODULE_EVENT_AUD_DSP1_CODEC_METADATA_ASSOCIATION_QUEUE_OVERRUN	0x41
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_WATERMARK_STAGE	0x42
#define SVEN_MODULE_EVENT_AUD_DSP1_MDA_STREAM_POS_IN	0x43
#define SVEN_MODULE_EVENT_AUD_DSP1_MDA_STREAM_POS_OUT	0x44
#define SVEN_MODULE_EVENT_AUD_DSP1_MDA_STREAM_POS_OUT_DISCARD	0x45
#define SVEN_MODULE_EVENT_AUD_DSP1_WATERMARK_ERROR	0x46
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_AD	0x47
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_AUDIO_QUALITY_STAGE	0x48
#define SVEN_MODULE_EVENT_AUD_DSP1_AUDIO_QUALITY_CUSTOM	0x49
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_PER_OUTPUT_DELAY_STAGE	0x4a
#define SVEN_MODULE_EVENT_AUD_DSP1_EXE_BIT_DEPTH_CONVERT	0x4b
#define SVEN_MODULE_EVENT_AUD_DSP1_DECODER_ERROR_RECONFIG	0x4c
#define SVEN_MODULE_EVENT_AUD_DSP1_DTS_DMIX_RUNNING	0x4d
#define SVEN_MODULE_EVENT_AUD_DSP1_DOLBY_BSI_INFO	0x4e
#define SVEN_MODULE_EVENT_AUD_DSP1_MS10_DDC_FRAME_SYNC	0x4f
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_STREAM_METADATA_CHANGE	0x50
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_METADATA_ASSOCIATION_QUEUE_OVERRUN	0x51
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_EXECUTE_FAILED	0x52
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_INSUFFICIENT_OUT_BUFFER_SPACE	0x53
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_INVALID_METADATA_ASSOCIATION	0x54
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_MISSING_END_OF_SEGMENT	0x55
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_STAGE_DISABLED	0x56
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_UNKNOWN_MODE	0x57
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_STAGE_ENABLED	0x58
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_PREPARED_INPUT	0x59
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_EXECUTE_CALL	0x5a
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_STAGE_OUTPUT	0x5b
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_INIT_STAGE	0x5c
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_CLEANUP_STAGE	0x5d
#define SVEN_MODULE_EVENT_AUD_DSP1_CAPP_FLUSH_STAGE	0x5e
#define SVEN_MODULE_EVENT_AUD_DSP1_SRS_STAGE_EXE	0x5f
#define SVEN_MODULE_EVENT_AUD_DSP1_IEC_PARSER_STAGE_EXE	0x60
#define SVEN_MODULE_EVENT_AUD_DSP1_IEC_61937_EXE	0x61
#define SVEN_MODULE_EVENT_AUD_DSP1_IEC_60958_EXE	0x62
#define SVEN_MODULE_EVENT_AUD_DSP1_STAGE_EXECUTION_SKIPPED	0x63
#define SVEN_MODULE_EVENT_AUD_DSP1_WAITING_ON_IO_EVENT	0x64
#define SVEN_MODULE_EVENT_AUD_DSP1_OUTPUT_QUEUE_FULL	0x65


#endif /* AUD_DSP1_REGOFFS_H */
