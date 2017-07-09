#ifndef MPG2VD_REGOFFS_H
#define MPG2VD_REGOFFS_H 1
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


/* Module MPG2VD CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_MPG2VD_MDRC	0x0 /* Reset MPEG2 Decoder Data path */ 
	#define BITFIELD_MPG2VD_MDRC	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SED	0x4 /* Stream Enable/Disable */ 
	#define BITFIELD_MPG2VD_SED	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_SED */
	#define BLSB_MPG2VD_SED_reserved_31_4	4
	#define BLSB_MPG2VD_SED_ByteSwap1	3
	#define BLSB_MPG2VD_SED_ByteSwap0	2
	#define BLSB_MPG2VD_SED_Stream1	1
	#define BLSB_MPG2VD_SED_Stream0	0
	/* Register Bit Widths for MPG2VD_SED */
	#define BWID_MPG2VD_SED_reserved_31_4	28
	#define BWID_MPG2VD_SED_ByteSwap1	1
	#define BWID_MPG2VD_SED_ByteSwap0	1
	#define BWID_MPG2VD_SED_Stream1	1
	#define BWID_MPG2VD_SED_Stream0	1
	/* Register Bit MASKS for MPG2VD_SED */
	#define BMSK_MPG2VD_SED_reserved_31_4	0xfffffff0 /*  */
	#define BMSK_MPG2VD_SED_ByteSwap1	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_SED_ByteSwap0	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_SED_Stream1	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_SED_Stream0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_SED - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_SED_reserved_31_4	 0x0004, 4, 28, 0xfffffff0
	#define BITFIELD_MPG2VD_SED_ByteSwap1	 0x0004, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_SED_ByteSwap0	 0x0004, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_SED_Stream1	 0x0004, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_SED_Stream0	 0x0004, 0, 1, 0x00000001
#define ROFF_MPG2VD_SAS	0x8 /* Stream Active Status */ 
	#define BITFIELD_MPG2VD_SAS	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_SAS */
	#define BLSB_MPG2VD_SAS_reserved_31_2	2
	#define BLSB_MPG2VD_SAS_Stream1	1
	#define BLSB_MPG2VD_SAS_Stream0	0
	/* Register Bit Widths for MPG2VD_SAS */
	#define BWID_MPG2VD_SAS_reserved_31_2	30
	#define BWID_MPG2VD_SAS_Stream1	1
	#define BWID_MPG2VD_SAS_Stream0	1
	/* Register Bit MASKS for MPG2VD_SAS */
	#define BMSK_MPG2VD_SAS_reserved_31_2	0xfffffffc /*  */
	#define BMSK_MPG2VD_SAS_Stream1	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_SAS_Stream0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_SAS - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_SAS_reserved_31_2	 0x0008, 2, 30, 0xfffffffc
	#define BITFIELD_MPG2VD_SAS_Stream1	 0x0008, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_SAS_Stream0	 0x0008, 0, 1, 0x00000001
#define ROFF_MPG2VD_SDEMC	0xc /* Stream DMA Engine Master Control */ 
	#define BITFIELD_MPG2VD_SDEMC	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_SDEMC */
	#define BLSB_MPG2VD_SDEMC_reserved_31_16	16
	#define BLSB_MPG2VD_SDEMC_DMAStream1LLPauseModeStatus	15
	#define BLSB_MPG2VD_SDEMC_DMAStream0LLPauseModeStatus	14
	#define BLSB_MPG2VD_SDEMC_DMAStream1LinearFetchMode	13
	#define BLSB_MPG2VD_SDEMC_DMAStream0LinearFetchMode	12
	#define BLSB_MPG2VD_SDEMC_DMAStream1LLPauseMode	11
	#define BLSB_MPG2VD_SDEMC_DMAStream0LLPauseMode	10
	#define BLSB_MPG2VD_SDEMC_DMAStream1MaxBurst32Bytes	9
	#define BLSB_MPG2VD_SDEMC_DMAStream0MaxBurst32Bytes	8
	#define BLSB_MPG2VD_SDEMC_DMAStream1LinkedListMode	7
	#define BLSB_MPG2VD_SDEMC_DMAStream0LinkedListMode	6
	#define BLSB_MPG2VD_SDEMC_DMAStream1FIFOEmpty	5
	#define BLSB_MPG2VD_SDEMC_DMAStream0FIFOEmpty	4
	#define BLSB_MPG2VD_SDEMC_FlushDMAStream1	3
	#define BLSB_MPG2VD_SDEMC_FlushDMAStream0	2
	#define BLSB_MPG2VD_SDEMC_StartDMAStream1	1
	#define BLSB_MPG2VD_SDEMC_StartDMAStream0	0
	/* Register Bit Widths for MPG2VD_SDEMC */
	#define BWID_MPG2VD_SDEMC_reserved_31_16	16
	#define BWID_MPG2VD_SDEMC_DMAStream1LLPauseModeStatus	1
	#define BWID_MPG2VD_SDEMC_DMAStream0LLPauseModeStatus	1
	#define BWID_MPG2VD_SDEMC_DMAStream1LinearFetchMode	1
	#define BWID_MPG2VD_SDEMC_DMAStream0LinearFetchMode	1
	#define BWID_MPG2VD_SDEMC_DMAStream1LLPauseMode	1
	#define BWID_MPG2VD_SDEMC_DMAStream0LLPauseMode	1
	#define BWID_MPG2VD_SDEMC_DMAStream1MaxBurst32Bytes	1
	#define BWID_MPG2VD_SDEMC_DMAStream0MaxBurst32Bytes	1
	#define BWID_MPG2VD_SDEMC_DMAStream1LinkedListMode	1
	#define BWID_MPG2VD_SDEMC_DMAStream0LinkedListMode	1
	#define BWID_MPG2VD_SDEMC_DMAStream1FIFOEmpty	1
	#define BWID_MPG2VD_SDEMC_DMAStream0FIFOEmpty	1
	#define BWID_MPG2VD_SDEMC_FlushDMAStream1	1
	#define BWID_MPG2VD_SDEMC_FlushDMAStream0	1
	#define BWID_MPG2VD_SDEMC_StartDMAStream1	1
	#define BWID_MPG2VD_SDEMC_StartDMAStream0	1
	/* Register Bit MASKS for MPG2VD_SDEMC */
	#define BMSK_MPG2VD_SDEMC_reserved_31_16	0xffff0000 /*  */
	#define BMSK_MPG2VD_SDEMC_DMAStream1LLPauseModeStatus	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream0LLPauseModeStatus	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream1LinearFetchMode	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream0LinearFetchMode	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream1LLPauseMode	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream0LLPauseMode	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream1MaxBurst32Bytes	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream0MaxBurst32Bytes	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream1LinkedListMode	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream0LinkedListMode	(1<<6) /* == 0x00000040:  */
	#define BMSK_MPG2VD_SDEMC_DMAStream1FIFOEmpty	(1<<5) /* == 0x00000020: Default b1 */
	#define BMSK_MPG2VD_SDEMC_DMAStream0FIFOEmpty	(1<<4) /* == 0x00000010: Default b1 */
	#define BMSK_MPG2VD_SDEMC_FlushDMAStream1	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_SDEMC_FlushDMAStream0	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_SDEMC_StartDMAStream1	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_SDEMC_StartDMAStream0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_SDEMC - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_SDEMC_reserved_31_16	 0x000c, 16, 16, 0xffff0000
	#define BITFIELD_MPG2VD_SDEMC_DMAStream1LLPauseModeStatus	 0x000c, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_SDEMC_DMAStream0LLPauseModeStatus	 0x000c, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_SDEMC_DMAStream1LinearFetchMode	 0x000c, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_SDEMC_DMAStream0LinearFetchMode	 0x000c, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_SDEMC_DMAStream1LLPauseMode	 0x000c, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_SDEMC_DMAStream0LLPauseMode	 0x000c, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_SDEMC_DMAStream1MaxBurst32Bytes	 0x000c, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_SDEMC_DMAStream0MaxBurst32Bytes	 0x000c, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_SDEMC_DMAStream1LinkedListMode	 0x000c, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_SDEMC_DMAStream0LinkedListMode	 0x000c, 6, 1, 0x00000040
	#define BITFIELD_MPG2VD_SDEMC_DMAStream1FIFOEmpty	 0x000c, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_SDEMC_DMAStream0FIFOEmpty	 0x000c, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_SDEMC_FlushDMAStream1	 0x000c, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_SDEMC_FlushDMAStream0	 0x000c, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_SDEMC_StartDMAStream1	 0x000c, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_SDEMC_StartDMAStream0	 0x000c, 0, 1, 0x00000001
#define ROFF_MPG2VD_IM0	0x10 /* Interrupt Mask Stream 0 */ 
	#define BITFIELD_MPG2VD_IM0	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_IM0 */
	#define BLSB_MPG2VD_IM0_StallPictEnd	31
	#define BLSB_MPG2VD_IM0_StallPictBegin	30
	#define BLSB_MPG2VD_IM0_StallGOPAfter	29
	#define BLSB_MPG2VD_IM0_StallSeqBegin	28
	#define BLSB_MPG2VD_IM0_PictureBroken	27
	#define BLSB_MPG2VD_IM0_VidRecover	26
	#define BLSB_MPG2VD_IM0_ASDBufferOverflow	25
	#define BLSB_MPG2VD_IM0_HaveASD	24
	#define BLSB_MPG2VD_IM0_FrameDone	23
	#define BLSB_MPG2VD_IM0_reserved_22_21	21
	#define BLSB_MPG2VD_IM0_FrameDroppedDueToVDCKeepOut	20
	#define BLSB_MPG2VD_IM0_PresentToDisplayDetected	19
	#define BLSB_MPG2VD_IM0_ProgressiveSequence	18
	#define BLSB_MPG2VD_IM0_HorizontalSize	17
	#define BLSB_MPG2VD_IM0_VerticalSize	16
	#define BLSB_MPG2VD_IM0_FrameRateCode	15
	#define BLSB_MPG2VD_IM0_AspectRatioChange	14
	#define BLSB_MPG2VD_IM0_Chroma420Frame	13
	#define BLSB_MPG2VD_IM0_reserved_12	12
	#define BLSB_MPG2VD_IM0_STCCounterTimeout	11
	#define BLSB_MPG2VD_IM0_CanDisplay	10
	#define BLSB_MPG2VD_IM0_CircularOrLinearBufferEmpty	9
	#define BLSB_MPG2VD_IM0_CircularBufferAlmostEmpty	8
	#define BLSB_MPG2VD_IM0_LinkedListIntrBitInDesc	7
	#define BLSB_MPG2VD_IM0_EndOfParsingCurrentPacket	6
	#define BLSB_MPG2VD_IM0_DiscontinuityPacketFound	5
	#define BLSB_MPG2VD_IM0_PTSFound	4
	#define BLSB_MPG2VD_IM0_ext_fifo_data	3
	#define BLSB_MPG2VD_IM0_ext_fifo_service	2
	#define BLSB_MPG2VD_IM0_timeout_s	1
	#define BLSB_MPG2VD_IM0_timeout_d	0
	/* Register Bit Widths for MPG2VD_IM0 */
	#define BWID_MPG2VD_IM0_StallPictEnd	1
	#define BWID_MPG2VD_IM0_StallPictBegin	1
	#define BWID_MPG2VD_IM0_StallGOPAfter	1
	#define BWID_MPG2VD_IM0_StallSeqBegin	1
	#define BWID_MPG2VD_IM0_PictureBroken	1
	#define BWID_MPG2VD_IM0_VidRecover	1
	#define BWID_MPG2VD_IM0_ASDBufferOverflow	1
	#define BWID_MPG2VD_IM0_HaveASD	1
	#define BWID_MPG2VD_IM0_FrameDone	1
	#define BWID_MPG2VD_IM0_reserved_22_21	2
	#define BWID_MPG2VD_IM0_FrameDroppedDueToVDCKeepOut	1
	#define BWID_MPG2VD_IM0_PresentToDisplayDetected	1
	#define BWID_MPG2VD_IM0_ProgressiveSequence	1
	#define BWID_MPG2VD_IM0_HorizontalSize	1
	#define BWID_MPG2VD_IM0_VerticalSize	1
	#define BWID_MPG2VD_IM0_FrameRateCode	1
	#define BWID_MPG2VD_IM0_AspectRatioChange	1
	#define BWID_MPG2VD_IM0_Chroma420Frame	1
	#define BWID_MPG2VD_IM0_reserved_12	1
	#define BWID_MPG2VD_IM0_STCCounterTimeout	1
	#define BWID_MPG2VD_IM0_CanDisplay	1
	#define BWID_MPG2VD_IM0_CircularOrLinearBufferEmpty	1
	#define BWID_MPG2VD_IM0_CircularBufferAlmostEmpty	1
	#define BWID_MPG2VD_IM0_LinkedListIntrBitInDesc	1
	#define BWID_MPG2VD_IM0_EndOfParsingCurrentPacket	1
	#define BWID_MPG2VD_IM0_DiscontinuityPacketFound	1
	#define BWID_MPG2VD_IM0_PTSFound	1
	#define BWID_MPG2VD_IM0_ext_fifo_data	1
	#define BWID_MPG2VD_IM0_ext_fifo_service	1
	#define BWID_MPG2VD_IM0_timeout_s	1
	#define BWID_MPG2VD_IM0_timeout_d	1
	/* Register Bit MASKS for MPG2VD_IM0 */
	#define BMSK_MPG2VD_IM0_StallPictEnd	(1<<31) /* == 0x80000000:  */
	#define BMSK_MPG2VD_IM0_StallPictBegin	(1<<30) /* == 0x40000000:  */
	#define BMSK_MPG2VD_IM0_StallGOPAfter	(1<<29) /* == 0x20000000:  */
	#define BMSK_MPG2VD_IM0_StallSeqBegin	(1<<28) /* == 0x10000000:  */
	#define BMSK_MPG2VD_IM0_PictureBroken	(1<<27) /* == 0x08000000:  */
	#define BMSK_MPG2VD_IM0_VidRecover	(1<<26) /* == 0x04000000:  */
	#define BMSK_MPG2VD_IM0_ASDBufferOverflow	(1<<25) /* == 0x02000000:  */
	#define BMSK_MPG2VD_IM0_HaveASD	(1<<24) /* == 0x01000000:  */
	#define BMSK_MPG2VD_IM0_FrameDone	(1<<23) /* == 0x00800000:  */
	#define BMSK_MPG2VD_IM0_reserved_22_21	0x00600000 /*  */
	#define BMSK_MPG2VD_IM0_FrameDroppedDueToVDCKeepOut	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_IM0_PresentToDisplayDetected	(1<<19) /* == 0x00080000:  */
	#define BMSK_MPG2VD_IM0_ProgressiveSequence	(1<<18) /* == 0x00040000:  */
	#define BMSK_MPG2VD_IM0_HorizontalSize	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_IM0_VerticalSize	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_IM0_FrameRateCode	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_IM0_AspectRatioChange	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_IM0_Chroma420Frame	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_IM0_reserved_12	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_IM0_STCCounterTimeout	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_IM0_CanDisplay	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_IM0_CircularOrLinearBufferEmpty	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_IM0_CircularBufferAlmostEmpty	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_IM0_LinkedListIntrBitInDesc	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_IM0_EndOfParsingCurrentPacket	(1<<6) /* == 0x00000040:  */
	#define BMSK_MPG2VD_IM0_DiscontinuityPacketFound	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_IM0_PTSFound	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_IM0_ext_fifo_data	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_IM0_ext_fifo_service	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_IM0_timeout_s	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_IM0_timeout_d	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_IM0 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_IM0_StallPictEnd	 0x0010, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_IM0_StallPictBegin	 0x0010, 30, 1, 0x40000000
	#define BITFIELD_MPG2VD_IM0_StallGOPAfter	 0x0010, 29, 1, 0x20000000
	#define BITFIELD_MPG2VD_IM0_StallSeqBegin	 0x0010, 28, 1, 0x10000000
	#define BITFIELD_MPG2VD_IM0_PictureBroken	 0x0010, 27, 1, 0x08000000
	#define BITFIELD_MPG2VD_IM0_VidRecover	 0x0010, 26, 1, 0x04000000
	#define BITFIELD_MPG2VD_IM0_ASDBufferOverflow	 0x0010, 25, 1, 0x02000000
	#define BITFIELD_MPG2VD_IM0_HaveASD	 0x0010, 24, 1, 0x01000000
	#define BITFIELD_MPG2VD_IM0_FrameDone	 0x0010, 23, 1, 0x00800000
	#define BITFIELD_MPG2VD_IM0_reserved_22_21	 0x0010, 21, 2, 0x00600000
	#define BITFIELD_MPG2VD_IM0_FrameDroppedDueToVDCKeepOut	 0x0010, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_IM0_PresentToDisplayDetected	 0x0010, 19, 1, 0x00080000
	#define BITFIELD_MPG2VD_IM0_ProgressiveSequence	 0x0010, 18, 1, 0x00040000
	#define BITFIELD_MPG2VD_IM0_HorizontalSize	 0x0010, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_IM0_VerticalSize	 0x0010, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_IM0_FrameRateCode	 0x0010, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_IM0_AspectRatioChange	 0x0010, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_IM0_Chroma420Frame	 0x0010, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_IM0_reserved_12	 0x0010, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_IM0_STCCounterTimeout	 0x0010, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_IM0_CanDisplay	 0x0010, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_IM0_CircularOrLinearBufferEmpty	 0x0010, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_IM0_CircularBufferAlmostEmpty	 0x0010, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_IM0_LinkedListIntrBitInDesc	 0x0010, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_IM0_EndOfParsingCurrentPacket	 0x0010, 6, 1, 0x00000040
	#define BITFIELD_MPG2VD_IM0_DiscontinuityPacketFound	 0x0010, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_IM0_PTSFound	 0x0010, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_IM0_ext_fifo_data	 0x0010, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_IM0_ext_fifo_service	 0x0010, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_IM0_timeout_s	 0x0010, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_IM0_timeout_d	 0x0010, 0, 1, 0x00000001
#define ROFF_MPG2VD_IM1	0x14 /* Interrupt Mask Stream 1 */ 
	#define BITFIELD_MPG2VD_IM1	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_IM1 */
	#define BLSB_MPG2VD_IM1_StallPictEnd	31
	#define BLSB_MPG2VD_IM1_StallPictBegin	30
	#define BLSB_MPG2VD_IM1_StallGOPAfter	29
	#define BLSB_MPG2VD_IM1_StallSeqBegin	28
	#define BLSB_MPG2VD_IM1_PictureBroken	27
	#define BLSB_MPG2VD_IM1_VidRecover	26
	#define BLSB_MPG2VD_IM1_ASDBufferOverflow	25
	#define BLSB_MPG2VD_IM1_HaveASD	24
	#define BLSB_MPG2VD_IM1_FrameDone	23
	#define BLSB_MPG2VD_IM1_reserved_22_21	21
	#define BLSB_MPG2VD_IM1_FrameDroppedDueToVDCKeepOut	20
	#define BLSB_MPG2VD_IM1_PresentToDisplayDetected	19
	#define BLSB_MPG2VD_IM1_ProgressiveSequence	18
	#define BLSB_MPG2VD_IM1_HorizontalSize	17
	#define BLSB_MPG2VD_IM1_VerticalSize	16
	#define BLSB_MPG2VD_IM1_FrameRateCode	15
	#define BLSB_MPG2VD_IM1_AspectRatioChange	14
	#define BLSB_MPG2VD_IM1_Chroma420Frame	13
	#define BLSB_MPG2VD_IM1_reserved_12	12
	#define BLSB_MPG2VD_IM1_STCCounterTimeout	11
	#define BLSB_MPG2VD_IM1_CanDisplay	10
	#define BLSB_MPG2VD_IM1_CircularOrLinearBufferEmpty	9
	#define BLSB_MPG2VD_IM1_CircularBufferAlmostEmpty	8
	#define BLSB_MPG2VD_IM1_LinkedListIntrBitInDesc	7
	#define BLSB_MPG2VD_IM1_EndOfParsingCurrentPacket	6
	#define BLSB_MPG2VD_IM1_DiscontinuityPacketFound	5
	#define BLSB_MPG2VD_IM1_PTSFound	4
	#define BLSB_MPG2VD_IM1_ext_fifo_data	3
	#define BLSB_MPG2VD_IM1_ext_fifo_service	2
	#define BLSB_MPG2VD_IM1_timeout_s	1
	#define BLSB_MPG2VD_IM1_timeout_d	0
	/* Register Bit Widths for MPG2VD_IM1 */
	#define BWID_MPG2VD_IM1_StallPictEnd	1
	#define BWID_MPG2VD_IM1_StallPictBegin	1
	#define BWID_MPG2VD_IM1_StallGOPAfter	1
	#define BWID_MPG2VD_IM1_StallSeqBegin	1
	#define BWID_MPG2VD_IM1_PictureBroken	1
	#define BWID_MPG2VD_IM1_VidRecover	1
	#define BWID_MPG2VD_IM1_ASDBufferOverflow	1
	#define BWID_MPG2VD_IM1_HaveASD	1
	#define BWID_MPG2VD_IM1_FrameDone	1
	#define BWID_MPG2VD_IM1_reserved_22_21	2
	#define BWID_MPG2VD_IM1_FrameDroppedDueToVDCKeepOut	1
	#define BWID_MPG2VD_IM1_PresentToDisplayDetected	1
	#define BWID_MPG2VD_IM1_ProgressiveSequence	1
	#define BWID_MPG2VD_IM1_HorizontalSize	1
	#define BWID_MPG2VD_IM1_VerticalSize	1
	#define BWID_MPG2VD_IM1_FrameRateCode	1
	#define BWID_MPG2VD_IM1_AspectRatioChange	1
	#define BWID_MPG2VD_IM1_Chroma420Frame	1
	#define BWID_MPG2VD_IM1_reserved_12	1
	#define BWID_MPG2VD_IM1_STCCounterTimeout	1
	#define BWID_MPG2VD_IM1_CanDisplay	1
	#define BWID_MPG2VD_IM1_CircularOrLinearBufferEmpty	1
	#define BWID_MPG2VD_IM1_CircularBufferAlmostEmpty	1
	#define BWID_MPG2VD_IM1_LinkedListIntrBitInDesc	1
	#define BWID_MPG2VD_IM1_EndOfParsingCurrentPacket	1
	#define BWID_MPG2VD_IM1_DiscontinuityPacketFound	1
	#define BWID_MPG2VD_IM1_PTSFound	1
	#define BWID_MPG2VD_IM1_ext_fifo_data	1
	#define BWID_MPG2VD_IM1_ext_fifo_service	1
	#define BWID_MPG2VD_IM1_timeout_s	1
	#define BWID_MPG2VD_IM1_timeout_d	1
	/* Register Bit MASKS for MPG2VD_IM1 */
	#define BMSK_MPG2VD_IM1_StallPictEnd	(1<<31) /* == 0x80000000:  */
	#define BMSK_MPG2VD_IM1_StallPictBegin	(1<<30) /* == 0x40000000:  */
	#define BMSK_MPG2VD_IM1_StallGOPAfter	(1<<29) /* == 0x20000000:  */
	#define BMSK_MPG2VD_IM1_StallSeqBegin	(1<<28) /* == 0x10000000:  */
	#define BMSK_MPG2VD_IM1_PictureBroken	(1<<27) /* == 0x08000000:  */
	#define BMSK_MPG2VD_IM1_VidRecover	(1<<26) /* == 0x04000000:  */
	#define BMSK_MPG2VD_IM1_ASDBufferOverflow	(1<<25) /* == 0x02000000:  */
	#define BMSK_MPG2VD_IM1_HaveASD	(1<<24) /* == 0x01000000:  */
	#define BMSK_MPG2VD_IM1_FrameDone	(1<<23) /* == 0x00800000:  */
	#define BMSK_MPG2VD_IM1_reserved_22_21	0x00600000 /*  */
	#define BMSK_MPG2VD_IM1_FrameDroppedDueToVDCKeepOut	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_IM1_PresentToDisplayDetected	(1<<19) /* == 0x00080000:  */
	#define BMSK_MPG2VD_IM1_ProgressiveSequence	(1<<18) /* == 0x00040000:  */
	#define BMSK_MPG2VD_IM1_HorizontalSize	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_IM1_VerticalSize	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_IM1_FrameRateCode	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_IM1_AspectRatioChange	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_IM1_Chroma420Frame	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_IM1_reserved_12	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_IM1_STCCounterTimeout	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_IM1_CanDisplay	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_IM1_CircularOrLinearBufferEmpty	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_IM1_CircularBufferAlmostEmpty	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_IM1_LinkedListIntrBitInDesc	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_IM1_EndOfParsingCurrentPacket	(1<<6) /* == 0x00000040:  */
	#define BMSK_MPG2VD_IM1_DiscontinuityPacketFound	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_IM1_PTSFound	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_IM1_ext_fifo_data	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_IM1_ext_fifo_service	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_IM1_timeout_s	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_IM1_timeout_d	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_IM1 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_IM1_StallPictEnd	 0x0014, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_IM1_StallPictBegin	 0x0014, 30, 1, 0x40000000
	#define BITFIELD_MPG2VD_IM1_StallGOPAfter	 0x0014, 29, 1, 0x20000000
	#define BITFIELD_MPG2VD_IM1_StallSeqBegin	 0x0014, 28, 1, 0x10000000
	#define BITFIELD_MPG2VD_IM1_PictureBroken	 0x0014, 27, 1, 0x08000000
	#define BITFIELD_MPG2VD_IM1_VidRecover	 0x0014, 26, 1, 0x04000000
	#define BITFIELD_MPG2VD_IM1_ASDBufferOverflow	 0x0014, 25, 1, 0x02000000
	#define BITFIELD_MPG2VD_IM1_HaveASD	 0x0014, 24, 1, 0x01000000
	#define BITFIELD_MPG2VD_IM1_FrameDone	 0x0014, 23, 1, 0x00800000
	#define BITFIELD_MPG2VD_IM1_reserved_22_21	 0x0014, 21, 2, 0x00600000
	#define BITFIELD_MPG2VD_IM1_FrameDroppedDueToVDCKeepOut	 0x0014, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_IM1_PresentToDisplayDetected	 0x0014, 19, 1, 0x00080000
	#define BITFIELD_MPG2VD_IM1_ProgressiveSequence	 0x0014, 18, 1, 0x00040000
	#define BITFIELD_MPG2VD_IM1_HorizontalSize	 0x0014, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_IM1_VerticalSize	 0x0014, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_IM1_FrameRateCode	 0x0014, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_IM1_AspectRatioChange	 0x0014, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_IM1_Chroma420Frame	 0x0014, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_IM1_reserved_12	 0x0014, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_IM1_STCCounterTimeout	 0x0014, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_IM1_CanDisplay	 0x0014, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_IM1_CircularOrLinearBufferEmpty	 0x0014, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_IM1_CircularBufferAlmostEmpty	 0x0014, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_IM1_LinkedListIntrBitInDesc	 0x0014, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_IM1_EndOfParsingCurrentPacket	 0x0014, 6, 1, 0x00000040
	#define BITFIELD_MPG2VD_IM1_DiscontinuityPacketFound	 0x0014, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_IM1_PTSFound	 0x0014, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_IM1_ext_fifo_data	 0x0014, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_IM1_ext_fifo_service	 0x0014, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_IM1_timeout_s	 0x0014, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_IM1_timeout_d	 0x0014, 0, 1, 0x00000001
#define ROFF_MPG2VD_IS	0x18 /* Interrupt Status */ 
	#define BITFIELD_MPG2VD_IS	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_IS */
	#define BLSB_MPG2VD_IS_reserved_31_2	2
	#define BLSB_MPG2VD_IS_Stream1	1
	#define BLSB_MPG2VD_IS_Stream0	0
	/* Register Bit Widths for MPG2VD_IS */
	#define BWID_MPG2VD_IS_reserved_31_2	30
	#define BWID_MPG2VD_IS_Stream1	1
	#define BWID_MPG2VD_IS_Stream0	1
	/* Register Bit MASKS for MPG2VD_IS */
	#define BMSK_MPG2VD_IS_reserved_31_2	0xfffffffc /*  */
	#define BMSK_MPG2VD_IS_Stream1	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_IS_Stream0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_IS - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_IS_reserved_31_2	 0x0018, 2, 30, 0xfffffffc
	#define BITFIELD_MPG2VD_IS_Stream1	 0x0018, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_IS_Stream0	 0x0018, 0, 1, 0x00000001
#define ROFF_MPG2VD_IS0	0x1c /* Interrupt Status Stream 0 */ 
	#define BITFIELD_MPG2VD_IS0	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_IS0 */
	#define BLSB_MPG2VD_IS0_StallPictEnd	31
	#define BLSB_MPG2VD_IS0_StallPictBegin	30
	#define BLSB_MPG2VD_IS0_StallGOPAfter	29
	#define BLSB_MPG2VD_IS0_StallSeqBegin	28
	#define BLSB_MPG2VD_IS0_PictureBroken	27
	#define BLSB_MPG2VD_IS0_VidRecover	26
	#define BLSB_MPG2VD_IS0_ASDBufferOverflow	25
	#define BLSB_MPG2VD_IS0_HaveASD	24
	#define BLSB_MPG2VD_IS0_FrameDone	23
	#define BLSB_MPG2VD_IS0_reserved_22_21	21
	#define BLSB_MPG2VD_IS0_FrameDroppedDueToVDCKeepOut	20
	#define BLSB_MPG2VD_IS0_PresentToDisplayDetected	19
	#define BLSB_MPG2VD_IS0_ProgressiveSequence	18
	#define BLSB_MPG2VD_IS0_HorizontalSize	17
	#define BLSB_MPG2VD_IS0_VerticalSize	16
	#define BLSB_MPG2VD_IS0_FrameRateCode	15
	#define BLSB_MPG2VD_IS0_AspectRatioChange	14
	#define BLSB_MPG2VD_IS0_Chroma420Frame	13
	#define BLSB_MPG2VD_IS0_reserved_12	12
	#define BLSB_MPG2VD_IS0_STCCounterTimeout	11
	#define BLSB_MPG2VD_IS0_CanDisplay	10
	#define BLSB_MPG2VD_IS0_CircularOrLinearBufferEmpty	9
	#define BLSB_MPG2VD_IS0_CircularBufferAlmostEmpty	8
	#define BLSB_MPG2VD_IS0_LinkedListIntrBitInDesc	7
	#define BLSB_MPG2VD_IS0_EndOfParsingCurrentPacket	6
	#define BLSB_MPG2VD_IS0_DiscontinuityPacketFound	5
	#define BLSB_MPG2VD_IS0_PTSFound	4
	#define BLSB_MPG2VD_IS0_ext_fifo_data	3
	#define BLSB_MPG2VD_IS0_ext_fifo_service	2
	#define BLSB_MPG2VD_IS0_timeout_s	1
	#define BLSB_MPG2VD_IS0_timeout_d	0
	/* Register Bit Widths for MPG2VD_IS0 */
	#define BWID_MPG2VD_IS0_StallPictEnd	1
	#define BWID_MPG2VD_IS0_StallPictBegin	1
	#define BWID_MPG2VD_IS0_StallGOPAfter	1
	#define BWID_MPG2VD_IS0_StallSeqBegin	1
	#define BWID_MPG2VD_IS0_PictureBroken	1
	#define BWID_MPG2VD_IS0_VidRecover	1
	#define BWID_MPG2VD_IS0_ASDBufferOverflow	1
	#define BWID_MPG2VD_IS0_HaveASD	1
	#define BWID_MPG2VD_IS0_FrameDone	1
	#define BWID_MPG2VD_IS0_reserved_22_21	2
	#define BWID_MPG2VD_IS0_FrameDroppedDueToVDCKeepOut	1
	#define BWID_MPG2VD_IS0_PresentToDisplayDetected	1
	#define BWID_MPG2VD_IS0_ProgressiveSequence	1
	#define BWID_MPG2VD_IS0_HorizontalSize	1
	#define BWID_MPG2VD_IS0_VerticalSize	1
	#define BWID_MPG2VD_IS0_FrameRateCode	1
	#define BWID_MPG2VD_IS0_AspectRatioChange	1
	#define BWID_MPG2VD_IS0_Chroma420Frame	1
	#define BWID_MPG2VD_IS0_reserved_12	1
	#define BWID_MPG2VD_IS0_STCCounterTimeout	1
	#define BWID_MPG2VD_IS0_CanDisplay	1
	#define BWID_MPG2VD_IS0_CircularOrLinearBufferEmpty	1
	#define BWID_MPG2VD_IS0_CircularBufferAlmostEmpty	1
	#define BWID_MPG2VD_IS0_LinkedListIntrBitInDesc	1
	#define BWID_MPG2VD_IS0_EndOfParsingCurrentPacket	1
	#define BWID_MPG2VD_IS0_DiscontinuityPacketFound	1
	#define BWID_MPG2VD_IS0_PTSFound	1
	#define BWID_MPG2VD_IS0_ext_fifo_data	1
	#define BWID_MPG2VD_IS0_ext_fifo_service	1
	#define BWID_MPG2VD_IS0_timeout_s	1
	#define BWID_MPG2VD_IS0_timeout_d	1
	/* Register Bit MASKS for MPG2VD_IS0 */
	#define BMSK_MPG2VD_IS0_StallPictEnd	(1<<31) /* == 0x80000000:  */
	#define BMSK_MPG2VD_IS0_StallPictBegin	(1<<30) /* == 0x40000000:  */
	#define BMSK_MPG2VD_IS0_StallGOPAfter	(1<<29) /* == 0x20000000:  */
	#define BMSK_MPG2VD_IS0_StallSeqBegin	(1<<28) /* == 0x10000000:  */
	#define BMSK_MPG2VD_IS0_PictureBroken	(1<<27) /* == 0x08000000:  */
	#define BMSK_MPG2VD_IS0_VidRecover	(1<<26) /* == 0x04000000:  */
	#define BMSK_MPG2VD_IS0_ASDBufferOverflow	(1<<25) /* == 0x02000000:  */
	#define BMSK_MPG2VD_IS0_HaveASD	(1<<24) /* == 0x01000000:  */
	#define BMSK_MPG2VD_IS0_FrameDone	(1<<23) /* == 0x00800000:  */
	#define BMSK_MPG2VD_IS0_reserved_22_21	0x00600000 /*  */
	#define BMSK_MPG2VD_IS0_FrameDroppedDueToVDCKeepOut	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_IS0_PresentToDisplayDetected	(1<<19) /* == 0x00080000:  */
	#define BMSK_MPG2VD_IS0_ProgressiveSequence	(1<<18) /* == 0x00040000:  */
	#define BMSK_MPG2VD_IS0_HorizontalSize	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_IS0_VerticalSize	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_IS0_FrameRateCode	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_IS0_AspectRatioChange	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_IS0_Chroma420Frame	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_IS0_reserved_12	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_IS0_STCCounterTimeout	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_IS0_CanDisplay	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_IS0_CircularOrLinearBufferEmpty	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_IS0_CircularBufferAlmostEmpty	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_IS0_LinkedListIntrBitInDesc	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_IS0_EndOfParsingCurrentPacket	(1<<6) /* == 0x00000040:  */
	#define BMSK_MPG2VD_IS0_DiscontinuityPacketFound	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_IS0_PTSFound	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_IS0_ext_fifo_data	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_IS0_ext_fifo_service	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_IS0_timeout_s	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_IS0_timeout_d	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_IS0 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_IS0_StallPictEnd	 0x001c, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_IS0_StallPictBegin	 0x001c, 30, 1, 0x40000000
	#define BITFIELD_MPG2VD_IS0_StallGOPAfter	 0x001c, 29, 1, 0x20000000
	#define BITFIELD_MPG2VD_IS0_StallSeqBegin	 0x001c, 28, 1, 0x10000000
	#define BITFIELD_MPG2VD_IS0_PictureBroken	 0x001c, 27, 1, 0x08000000
	#define BITFIELD_MPG2VD_IS0_VidRecover	 0x001c, 26, 1, 0x04000000
	#define BITFIELD_MPG2VD_IS0_ASDBufferOverflow	 0x001c, 25, 1, 0x02000000
	#define BITFIELD_MPG2VD_IS0_HaveASD	 0x001c, 24, 1, 0x01000000
	#define BITFIELD_MPG2VD_IS0_FrameDone	 0x001c, 23, 1, 0x00800000
	#define BITFIELD_MPG2VD_IS0_reserved_22_21	 0x001c, 21, 2, 0x00600000
	#define BITFIELD_MPG2VD_IS0_FrameDroppedDueToVDCKeepOut	 0x001c, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_IS0_PresentToDisplayDetected	 0x001c, 19, 1, 0x00080000
	#define BITFIELD_MPG2VD_IS0_ProgressiveSequence	 0x001c, 18, 1, 0x00040000
	#define BITFIELD_MPG2VD_IS0_HorizontalSize	 0x001c, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_IS0_VerticalSize	 0x001c, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_IS0_FrameRateCode	 0x001c, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_IS0_AspectRatioChange	 0x001c, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_IS0_Chroma420Frame	 0x001c, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_IS0_reserved_12	 0x001c, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_IS0_STCCounterTimeout	 0x001c, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_IS0_CanDisplay	 0x001c, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_IS0_CircularOrLinearBufferEmpty	 0x001c, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_IS0_CircularBufferAlmostEmpty	 0x001c, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_IS0_LinkedListIntrBitInDesc	 0x001c, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_IS0_EndOfParsingCurrentPacket	 0x001c, 6, 1, 0x00000040
	#define BITFIELD_MPG2VD_IS0_DiscontinuityPacketFound	 0x001c, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_IS0_PTSFound	 0x001c, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_IS0_ext_fifo_data	 0x001c, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_IS0_ext_fifo_service	 0x001c, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_IS0_timeout_s	 0x001c, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_IS0_timeout_d	 0x001c, 0, 1, 0x00000001
#define ROFF_MPG2VD_IS1	0x20 /* Interrupt Status Stream 0 */ 
	#define BITFIELD_MPG2VD_IS1	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_IS1 */
	#define BLSB_MPG2VD_IS1_StallPictEnd	31
	#define BLSB_MPG2VD_IS1_StallPictBegin	30
	#define BLSB_MPG2VD_IS1_StallGOPAfter	29
	#define BLSB_MPG2VD_IS1_StallSeqBegin	28
	#define BLSB_MPG2VD_IS1_PictureBroken	27
	#define BLSB_MPG2VD_IS1_VidRecover	26
	#define BLSB_MPG2VD_IS1_ASDBufferOverflow	25
	#define BLSB_MPG2VD_IS1_HaveASD	24
	#define BLSB_MPG2VD_IS1_FrameDone	23
	#define BLSB_MPG2VD_IS1_reserved_22_21	21
	#define BLSB_MPG2VD_IS1_FrameDroppedDueToVDCKeepOut	20
	#define BLSB_MPG2VD_IS1_PresentToDisplayDetected	19
	#define BLSB_MPG2VD_IS1_ProgressiveSequence	18
	#define BLSB_MPG2VD_IS1_HorizontalSize	17
	#define BLSB_MPG2VD_IS1_VerticalSize	16
	#define BLSB_MPG2VD_IS1_FrameRateCode	15
	#define BLSB_MPG2VD_IS1_AspectRatioChange	14
	#define BLSB_MPG2VD_IS1_Chroma420Frame	13
	#define BLSB_MPG2VD_IS1_reserved_12	12
	#define BLSB_MPG2VD_IS1_STCCounterTimeout	11
	#define BLSB_MPG2VD_IS1_CanDisplay	10
	#define BLSB_MPG2VD_IS1_CircularOrLinearBufferEmpty	9
	#define BLSB_MPG2VD_IS1_CircularBufferAlmostEmpty	8
	#define BLSB_MPG2VD_IS1_LinkedListIntrBitInDesc	7
	#define BLSB_MPG2VD_IS1_EndOfParsingCurrentPacket	6
	#define BLSB_MPG2VD_IS1_DiscontinuityPacketFound	5
	#define BLSB_MPG2VD_IS1_PTSFound	4
	#define BLSB_MPG2VD_IS1_ext_fifo_data	3
	#define BLSB_MPG2VD_IS1_ext_fifo_service	2
	#define BLSB_MPG2VD_IS1_timeout_s	1
	#define BLSB_MPG2VD_IS1_timeout_d	0
	/* Register Bit Widths for MPG2VD_IS1 */
	#define BWID_MPG2VD_IS1_StallPictEnd	1
	#define BWID_MPG2VD_IS1_StallPictBegin	1
	#define BWID_MPG2VD_IS1_StallGOPAfter	1
	#define BWID_MPG2VD_IS1_StallSeqBegin	1
	#define BWID_MPG2VD_IS1_PictureBroken	1
	#define BWID_MPG2VD_IS1_VidRecover	1
	#define BWID_MPG2VD_IS1_ASDBufferOverflow	1
	#define BWID_MPG2VD_IS1_HaveASD	1
	#define BWID_MPG2VD_IS1_FrameDone	1
	#define BWID_MPG2VD_IS1_reserved_22_21	2
	#define BWID_MPG2VD_IS1_FrameDroppedDueToVDCKeepOut	1
	#define BWID_MPG2VD_IS1_PresentToDisplayDetected	1
	#define BWID_MPG2VD_IS1_ProgressiveSequence	1
	#define BWID_MPG2VD_IS1_HorizontalSize	1
	#define BWID_MPG2VD_IS1_VerticalSize	1
	#define BWID_MPG2VD_IS1_FrameRateCode	1
	#define BWID_MPG2VD_IS1_AspectRatioChange	1
	#define BWID_MPG2VD_IS1_Chroma420Frame	1
	#define BWID_MPG2VD_IS1_reserved_12	1
	#define BWID_MPG2VD_IS1_STCCounterTimeout	1
	#define BWID_MPG2VD_IS1_CanDisplay	1
	#define BWID_MPG2VD_IS1_CircularOrLinearBufferEmpty	1
	#define BWID_MPG2VD_IS1_CircularBufferAlmostEmpty	1
	#define BWID_MPG2VD_IS1_LinkedListIntrBitInDesc	1
	#define BWID_MPG2VD_IS1_EndOfParsingCurrentPacket	1
	#define BWID_MPG2VD_IS1_DiscontinuityPacketFound	1
	#define BWID_MPG2VD_IS1_PTSFound	1
	#define BWID_MPG2VD_IS1_ext_fifo_data	1
	#define BWID_MPG2VD_IS1_ext_fifo_service	1
	#define BWID_MPG2VD_IS1_timeout_s	1
	#define BWID_MPG2VD_IS1_timeout_d	1
	/* Register Bit MASKS for MPG2VD_IS1 */
	#define BMSK_MPG2VD_IS1_StallPictEnd	(1<<31) /* == 0x80000000:  */
	#define BMSK_MPG2VD_IS1_StallPictBegin	(1<<30) /* == 0x40000000:  */
	#define BMSK_MPG2VD_IS1_StallGOPAfter	(1<<29) /* == 0x20000000:  */
	#define BMSK_MPG2VD_IS1_StallSeqBegin	(1<<28) /* == 0x10000000:  */
	#define BMSK_MPG2VD_IS1_PictureBroken	(1<<27) /* == 0x08000000:  */
	#define BMSK_MPG2VD_IS1_VidRecover	(1<<26) /* == 0x04000000:  */
	#define BMSK_MPG2VD_IS1_ASDBufferOverflow	(1<<25) /* == 0x02000000:  */
	#define BMSK_MPG2VD_IS1_HaveASD	(1<<24) /* == 0x01000000:  */
	#define BMSK_MPG2VD_IS1_FrameDone	(1<<23) /* == 0x00800000:  */
	#define BMSK_MPG2VD_IS1_reserved_22_21	0x00600000 /*  */
	#define BMSK_MPG2VD_IS1_FrameDroppedDueToVDCKeepOut	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_IS1_PresentToDisplayDetected	(1<<19) /* == 0x00080000:  */
	#define BMSK_MPG2VD_IS1_ProgressiveSequence	(1<<18) /* == 0x00040000:  */
	#define BMSK_MPG2VD_IS1_HorizontalSize	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_IS1_VerticalSize	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_IS1_FrameRateCode	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_IS1_AspectRatioChange	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_IS1_Chroma420Frame	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_IS1_reserved_12	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_IS1_STCCounterTimeout	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_IS1_CanDisplay	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_IS1_CircularOrLinearBufferEmpty	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_IS1_CircularBufferAlmostEmpty	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_IS1_LinkedListIntrBitInDesc	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_IS1_EndOfParsingCurrentPacket	(1<<6) /* == 0x00000040:  */
	#define BMSK_MPG2VD_IS1_DiscontinuityPacketFound	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_IS1_PTSFound	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_IS1_ext_fifo_data	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_IS1_ext_fifo_service	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_IS1_timeout_s	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_IS1_timeout_d	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_IS1 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_IS1_StallPictEnd	 0x0020, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_IS1_StallPictBegin	 0x0020, 30, 1, 0x40000000
	#define BITFIELD_MPG2VD_IS1_StallGOPAfter	 0x0020, 29, 1, 0x20000000
	#define BITFIELD_MPG2VD_IS1_StallSeqBegin	 0x0020, 28, 1, 0x10000000
	#define BITFIELD_MPG2VD_IS1_PictureBroken	 0x0020, 27, 1, 0x08000000
	#define BITFIELD_MPG2VD_IS1_VidRecover	 0x0020, 26, 1, 0x04000000
	#define BITFIELD_MPG2VD_IS1_ASDBufferOverflow	 0x0020, 25, 1, 0x02000000
	#define BITFIELD_MPG2VD_IS1_HaveASD	 0x0020, 24, 1, 0x01000000
	#define BITFIELD_MPG2VD_IS1_FrameDone	 0x0020, 23, 1, 0x00800000
	#define BITFIELD_MPG2VD_IS1_reserved_22_21	 0x0020, 21, 2, 0x00600000
	#define BITFIELD_MPG2VD_IS1_FrameDroppedDueToVDCKeepOut	 0x0020, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_IS1_PresentToDisplayDetected	 0x0020, 19, 1, 0x00080000
	#define BITFIELD_MPG2VD_IS1_ProgressiveSequence	 0x0020, 18, 1, 0x00040000
	#define BITFIELD_MPG2VD_IS1_HorizontalSize	 0x0020, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_IS1_VerticalSize	 0x0020, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_IS1_FrameRateCode	 0x0020, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_IS1_AspectRatioChange	 0x0020, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_IS1_Chroma420Frame	 0x0020, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_IS1_reserved_12	 0x0020, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_IS1_STCCounterTimeout	 0x0020, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_IS1_CanDisplay	 0x0020, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_IS1_CircularOrLinearBufferEmpty	 0x0020, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_IS1_CircularBufferAlmostEmpty	 0x0020, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_IS1_LinkedListIntrBitInDesc	 0x0020, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_IS1_EndOfParsingCurrentPacket	 0x0020, 6, 1, 0x00000040
	#define BITFIELD_MPG2VD_IS1_DiscontinuityPacketFound	 0x0020, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_IS1_PTSFound	 0x0020, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_IS1_ext_fifo_data	 0x0020, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_IS1_ext_fifo_service	 0x0020, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_IS1_timeout_s	 0x0020, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_IS1_timeout_d	 0x0020, 0, 1, 0x00000001
#define ROFF_MPG2VD_INTCR0	0x24 /* Interrupt Counter Stream 0 */ 
	#define BITFIELD_MPG2VD_INTCR0	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_INTCR1	0x28 /* Interrupt Counter Stream 1 */ 
	#define BITFIELD_MPG2VD_INTCR1	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PWRSED	0x30 /* Stream Enable(1)/Disable(0) for (VR) Power Savings  */ 
	#define BITFIELD_MPG2VD_PWRSED	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_PWRSED */
	#define BLSB_MPG2VD_PWRSED_reserved_31_2	2
	#define BLSB_MPG2VD_PWRSED_Stream1	1
	#define BLSB_MPG2VD_PWRSED_Stream0	0
	/* Register Bit Widths for MPG2VD_PWRSED */
	#define BWID_MPG2VD_PWRSED_reserved_31_2	30
	#define BWID_MPG2VD_PWRSED_Stream1	1
	#define BWID_MPG2VD_PWRSED_Stream0	1
	/* Register Bit MASKS for MPG2VD_PWRSED */
	#define BMSK_MPG2VD_PWRSED_reserved_31_2	0xfffffffc /*  */
	#define BMSK_MPG2VD_PWRSED_Stream1	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_PWRSED_Stream0	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_PWRSED - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_PWRSED_reserved_31_2	 0x0030, 2, 30, 0xfffffffc
	#define BITFIELD_MPG2VD_PWRSED_Stream1	 0x0030, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_PWRSED_Stream0	 0x0030, 0, 1, 0x00000001
#define ROFF_MPG2VD_S0CC	0x100 /* Decoder 0 Core Control */ 
	#define BITFIELD_MPG2VD_S0CC	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S0CC */
	#define BLSB_MPG2VD_S0CC_reserved_31_13	13
	#define BLSB_MPG2VD_S0CC_DoingDecode	12
	#define BLSB_MPG2VD_S0CC_reserved_11_10	10
	#define BLSB_MPG2VD_S0CC_PIPScalarMode	8
	#define BLSB_MPG2VD_S0CC_reserved_7_5	5
	#define BLSB_MPG2VD_S0CC_ElementaryStreamMask	4
	#define BLSB_MPG2VD_S0CC_reserved_3_2	2
	#define BLSB_MPG2VD_S0CC_ProgressiveRefreshEnable	1
	#define BLSB_MPG2VD_S0CC_ResetCore	0
	/* Register Bit Widths for MPG2VD_S0CC */
	#define BWID_MPG2VD_S0CC_reserved_31_13	19
	#define BWID_MPG2VD_S0CC_DoingDecode	1
	#define BWID_MPG2VD_S0CC_reserved_11_10	2
	#define BWID_MPG2VD_S0CC_PIPScalarMode	2
	#define BWID_MPG2VD_S0CC_reserved_7_5	3
	#define BWID_MPG2VD_S0CC_ElementaryStreamMask	1
	#define BWID_MPG2VD_S0CC_reserved_3_2	2
	#define BWID_MPG2VD_S0CC_ProgressiveRefreshEnable	1
	#define BWID_MPG2VD_S0CC_ResetCore	1
	/* Register Bit MASKS for MPG2VD_S0CC */
	#define BMSK_MPG2VD_S0CC_reserved_31_13	0xffffe000 /*  */
	#define BMSK_MPG2VD_S0CC_DoingDecode	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_S0CC_reserved_11_10	0x00000c00 /*  */
	#define BMSK_MPG2VD_S0CC_PIPScalarMode	0x00000300 /*  */
	#define BMSK_MPG2VD_S0CC_reserved_7_5	0x000000e0 /*  */
	#define BMSK_MPG2VD_S0CC_ElementaryStreamMask	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_S0CC_reserved_3_2	0x0000000c /*  */
	#define BMSK_MPG2VD_S0CC_ProgressiveRefreshEnable	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S0CC_ResetCore	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S0CC - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S0CC_reserved_31_13	 0x0100, 13, 19, 0xffffe000
	#define BITFIELD_MPG2VD_S0CC_DoingDecode	 0x0100, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_S0CC_reserved_11_10	 0x0100, 10, 2, 0x00000c00
	#define BITFIELD_MPG2VD_S0CC_PIPScalarMode	 0x0100, 8, 2, 0x00000300
	#define BITFIELD_MPG2VD_S0CC_reserved_7_5	 0x0100, 5, 3, 0x000000e0
	#define BITFIELD_MPG2VD_S0CC_ElementaryStreamMask	 0x0100, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_S0CC_reserved_3_2	 0x0100, 2, 2, 0x0000000c
	#define BITFIELD_MPG2VD_S0CC_ProgressiveRefreshEnable	 0x0100, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S0CC_ResetCore	 0x0100, 0, 1, 0x00000001
#define ROFF_MPG2VD_S0SM	0x104 /* Decoder 0 Core Stall Mask */ 
	#define BITFIELD_MPG2VD_S0SM	 0x0104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S0SM */
	#define BLSB_MPG2VD_S0SM_reserved_31_5	5
	#define BLSB_MPG2VD_S0SM_Skip_B_Pictures	4
	#define BLSB_MPG2VD_S0SM_STALL_PICT_END	3
	#define BLSB_MPG2VD_S0SM_STALL_PICT_BEGIN	2
	#define BLSB_MPG2VD_S0SM_STALL_GOP_AFTER	1
	#define BLSB_MPG2VD_S0SM_STALL_SEQ_BEGIN	0
	/* Register Bit Widths for MPG2VD_S0SM */
	#define BWID_MPG2VD_S0SM_reserved_31_5	27
	#define BWID_MPG2VD_S0SM_Skip_B_Pictures	1
	#define BWID_MPG2VD_S0SM_STALL_PICT_END	1
	#define BWID_MPG2VD_S0SM_STALL_PICT_BEGIN	1
	#define BWID_MPG2VD_S0SM_STALL_GOP_AFTER	1
	#define BWID_MPG2VD_S0SM_STALL_SEQ_BEGIN	1
	/* Register Bit MASKS for MPG2VD_S0SM */
	#define BMSK_MPG2VD_S0SM_reserved_31_5	0xffffffe0 /*  */
	#define BMSK_MPG2VD_S0SM_Skip_B_Pictures	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_S0SM_STALL_PICT_END	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_S0SM_STALL_PICT_BEGIN	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_S0SM_STALL_GOP_AFTER	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S0SM_STALL_SEQ_BEGIN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S0SM - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S0SM_reserved_31_5	 0x0104, 5, 27, 0xffffffe0
	#define BITFIELD_MPG2VD_S0SM_Skip_B_Pictures	 0x0104, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_S0SM_STALL_PICT_END	 0x0104, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_S0SM_STALL_PICT_BEGIN	 0x0104, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_S0SM_STALL_GOP_AFTER	 0x0104, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S0SM_STALL_SEQ_BEGIN	 0x0104, 0, 1, 0x00000001
#define ROFF_MPG2VD_S0SS	0x108 /* Decoder 0 Core Stall Status */ 
	#define BITFIELD_MPG2VD_S0SS	 0x0108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S0SS */
	#define BLSB_MPG2VD_S0SS_reserved_31_5	5
	#define BLSB_MPG2VD_S0SS_Skip_B_Pictures	4
	#define BLSB_MPG2VD_S0SS_STALL_PICT_END	3
	#define BLSB_MPG2VD_S0SS_STALL_PICT_BEGIN	2
	#define BLSB_MPG2VD_S0SS_STALL_GOP_AFTER	1
	#define BLSB_MPG2VD_S0SS_STALL_SEQ_BEGIN	0
	/* Register Bit Widths for MPG2VD_S0SS */
	#define BWID_MPG2VD_S0SS_reserved_31_5	27
	#define BWID_MPG2VD_S0SS_Skip_B_Pictures	1
	#define BWID_MPG2VD_S0SS_STALL_PICT_END	1
	#define BWID_MPG2VD_S0SS_STALL_PICT_BEGIN	1
	#define BWID_MPG2VD_S0SS_STALL_GOP_AFTER	1
	#define BWID_MPG2VD_S0SS_STALL_SEQ_BEGIN	1
	/* Register Bit MASKS for MPG2VD_S0SS */
	#define BMSK_MPG2VD_S0SS_reserved_31_5	0xffffffe0 /*  */
	#define BMSK_MPG2VD_S0SS_Skip_B_Pictures	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_S0SS_STALL_PICT_END	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_S0SS_STALL_PICT_BEGIN	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_S0SS_STALL_GOP_AFTER	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S0SS_STALL_SEQ_BEGIN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S0SS - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S0SS_reserved_31_5	 0x0108, 5, 27, 0xffffffe0
	#define BITFIELD_MPG2VD_S0SS_Skip_B_Pictures	 0x0108, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_S0SS_STALL_PICT_END	 0x0108, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_S0SS_STALL_PICT_BEGIN	 0x0108, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_S0SS_STALL_GOP_AFTER	 0x0108, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S0SS_STALL_SEQ_BEGIN	 0x0108, 0, 1, 0x00000001
#define ROFF_MPG2VD_S0SC	0x10c /* Decoder 0 Core Stall Control */ 
	#define BITFIELD_MPG2VD_S0SC	 0x010c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S0SC */
	#define BLSB_MPG2VD_S0SC_reserved_31_2	2
	#define BLSB_MPG2VD_S0SC_SkipToNext	1
	#define BLSB_MPG2VD_S0SC_StallContinue	0
	/* Register Bit Widths for MPG2VD_S0SC */
	#define BWID_MPG2VD_S0SC_reserved_31_2	30
	#define BWID_MPG2VD_S0SC_SkipToNext	1
	#define BWID_MPG2VD_S0SC_StallContinue	1
	/* Register Bit MASKS for MPG2VD_S0SC */
	#define BMSK_MPG2VD_S0SC_reserved_31_2	0xfffffffc /*  */
	#define BMSK_MPG2VD_S0SC_SkipToNext	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S0SC_StallContinue	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S0SC - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S0SC_reserved_31_2	 0x010c, 2, 30, 0xfffffffc
	#define BITFIELD_MPG2VD_S0SC_SkipToNext	 0x010c, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S0SC_StallContinue	 0x010c, 0, 1, 0x00000001
#define ROFF_MPG2VD_S0ASDBC	0x110 /* Decoder 0 Core Additional Stream Data Buffer Configuration */ 
	#define BITFIELD_MPG2VD_S0ASDBC	 0x0110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0ASDFP	0x114 /* Decoder 0 Core Additional Stream Data Front Pointer */ 
	#define BITFIELD_MPG2VD_S0ASDFP	 0x0114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0ASDBP	0x118 /* Decoder 0 Core Additional Stream Data Back Pointer */ 
	#define BITFIELD_MPG2VD_S0ASDBP	 0x0118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0ASDR	0x11c /* Decoder 0 Core Additional Stream Data Read */ 
	#define BITFIELD_MPG2VD_S0ASDR	 0x011c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0SI1	0x120 /* Decoder 0 Core Sequence Info 1 */ 
	#define BITFIELD_MPG2VD_S0SI1	 0x0120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0SI2	0x124 /* Decoder 0 Core Sequence Info 2 */ 
	#define BITFIELD_MPG2VD_S0SI2	 0x0124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0SI3	0x128 /* Decoder 0 Core Sequence Info 3 */ 
	#define BITFIELD_MPG2VD_S0SI3	 0x0128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0SI4	0x12c /* Decoder 0 Core Sequence Info 4 */ 
	#define BITFIELD_MPG2VD_S0SI4	 0x012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0PI1	0x130 /* Decoder 0 Core Picture Info 1 */ 
	#define BITFIELD_MPG2VD_S0PI1	 0x0130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0PI2	0x134 /* Decoder 0 Core Picture Info 2 */ 
	#define BITFIELD_MPG2VD_S0PI2	 0x0134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0PI3	0x138 /* Decoder 0 Core Picture Info 3 */ 
	#define BITFIELD_MPG2VD_S0PI3	 0x0138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0PCE	0x13c /* Decoder 0 Core Picture Coding Extension with Composite Display Flag Set */ 
	#define BITFIELD_MPG2VD_S0PCE	 0x013c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0SDE1	0x140 /* Decoder 0 Core Sequence Display Extension 1 */ 
	#define BITFIELD_MPG2VD_S0SDE1	 0x0140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0SDE2	0x144 /* Decoder 0 Core Sequence Display Extension 2 */ 
	#define BITFIELD_MPG2VD_S0SDE2	 0x0144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S0GH	0x148 /* Decoder 0 Core GOP Header */ 
	#define BITFIELD_MPG2VD_S0GH	 0x0148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1CC	0x180 /* Decoder 1 Core Control */ 
	#define BITFIELD_MPG2VD_S1CC	 0x0180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S1CC */
	#define BLSB_MPG2VD_S1CC_reserved_31_13	13
	#define BLSB_MPG2VD_S1CC_DoingDecode	12
	#define BLSB_MPG2VD_S1CC_reserved_11_10	10
	#define BLSB_MPG2VD_S1CC_PIPScalarMode	8
	#define BLSB_MPG2VD_S1CC_reserved_7_5	5
	#define BLSB_MPG2VD_S1CC_ElementaryStreamMask	4
	#define BLSB_MPG2VD_S1CC_reserved_3_2	2
	#define BLSB_MPG2VD_S1CC_ProgressiveRefreshEnable	1
	#define BLSB_MPG2VD_S1CC_ResetCore	0
	/* Register Bit Widths for MPG2VD_S1CC */
	#define BWID_MPG2VD_S1CC_reserved_31_13	19
	#define BWID_MPG2VD_S1CC_DoingDecode	1
	#define BWID_MPG2VD_S1CC_reserved_11_10	2
	#define BWID_MPG2VD_S1CC_PIPScalarMode	2
	#define BWID_MPG2VD_S1CC_reserved_7_5	3
	#define BWID_MPG2VD_S1CC_ElementaryStreamMask	1
	#define BWID_MPG2VD_S1CC_reserved_3_2	2
	#define BWID_MPG2VD_S1CC_ProgressiveRefreshEnable	1
	#define BWID_MPG2VD_S1CC_ResetCore	1
	/* Register Bit MASKS for MPG2VD_S1CC */
	#define BMSK_MPG2VD_S1CC_reserved_31_13	0xffffe000 /*  */
	#define BMSK_MPG2VD_S1CC_DoingDecode	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_S1CC_reserved_11_10	0x00000c00 /*  */
	#define BMSK_MPG2VD_S1CC_PIPScalarMode	0x00000300 /*  */
	#define BMSK_MPG2VD_S1CC_reserved_7_5	0x000000e0 /*  */
	#define BMSK_MPG2VD_S1CC_ElementaryStreamMask	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_S1CC_reserved_3_2	0x0000000c /*  */
	#define BMSK_MPG2VD_S1CC_ProgressiveRefreshEnable	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S1CC_ResetCore	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S1CC - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S1CC_reserved_31_13	 0x0180, 13, 19, 0xffffe000
	#define BITFIELD_MPG2VD_S1CC_DoingDecode	 0x0180, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_S1CC_reserved_11_10	 0x0180, 10, 2, 0x00000c00
	#define BITFIELD_MPG2VD_S1CC_PIPScalarMode	 0x0180, 8, 2, 0x00000300
	#define BITFIELD_MPG2VD_S1CC_reserved_7_5	 0x0180, 5, 3, 0x000000e0
	#define BITFIELD_MPG2VD_S1CC_ElementaryStreamMask	 0x0180, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_S1CC_reserved_3_2	 0x0180, 2, 2, 0x0000000c
	#define BITFIELD_MPG2VD_S1CC_ProgressiveRefreshEnable	 0x0180, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S1CC_ResetCore	 0x0180, 0, 1, 0x00000001
#define ROFF_MPG2VD_S1SM	0x184 /* Decoder 1 Core Stall Mask */ 
	#define BITFIELD_MPG2VD_S1SM	 0x0184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S1SM */
	#define BLSB_MPG2VD_S1SM_reserved_31_5	5
	#define BLSB_MPG2VD_S1SM_Skip_B_Pictures	4
	#define BLSB_MPG2VD_S1SM_STALL_PICT_END	3
	#define BLSB_MPG2VD_S1SM_STALL_PICT_BEGIN	2
	#define BLSB_MPG2VD_S1SM_STALL_GOP_AFTER	1
	#define BLSB_MPG2VD_S1SM_STALL_SEQ_BEGIN	0
	/* Register Bit Widths for MPG2VD_S1SM */
	#define BWID_MPG2VD_S1SM_reserved_31_5	27
	#define BWID_MPG2VD_S1SM_Skip_B_Pictures	1
	#define BWID_MPG2VD_S1SM_STALL_PICT_END	1
	#define BWID_MPG2VD_S1SM_STALL_PICT_BEGIN	1
	#define BWID_MPG2VD_S1SM_STALL_GOP_AFTER	1
	#define BWID_MPG2VD_S1SM_STALL_SEQ_BEGIN	1
	/* Register Bit MASKS for MPG2VD_S1SM */
	#define BMSK_MPG2VD_S1SM_reserved_31_5	0xffffffe0 /*  */
	#define BMSK_MPG2VD_S1SM_Skip_B_Pictures	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_S1SM_STALL_PICT_END	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_S1SM_STALL_PICT_BEGIN	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_S1SM_STALL_GOP_AFTER	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S1SM_STALL_SEQ_BEGIN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S1SM - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S1SM_reserved_31_5	 0x0184, 5, 27, 0xffffffe0
	#define BITFIELD_MPG2VD_S1SM_Skip_B_Pictures	 0x0184, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_S1SM_STALL_PICT_END	 0x0184, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_S1SM_STALL_PICT_BEGIN	 0x0184, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_S1SM_STALL_GOP_AFTER	 0x0184, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S1SM_STALL_SEQ_BEGIN	 0x0184, 0, 1, 0x00000001
#define ROFF_MPG2VD_S1SS	0x188 /* Decoder 1 Core Stall Status */ 
	#define BITFIELD_MPG2VD_S1SS	 0x0188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S1SS */
	#define BLSB_MPG2VD_S1SS_reserved_31_5	5
	#define BLSB_MPG2VD_S1SS_Skip_B_Pictures	4
	#define BLSB_MPG2VD_S1SS_STALL_PICT_END	3
	#define BLSB_MPG2VD_S1SS_STALL_PICT_BEGIN	2
	#define BLSB_MPG2VD_S1SS_STALL_GOP_AFTER	1
	#define BLSB_MPG2VD_S1SS_STALL_SEQ_BEGIN	0
	/* Register Bit Widths for MPG2VD_S1SS */
	#define BWID_MPG2VD_S1SS_reserved_31_5	27
	#define BWID_MPG2VD_S1SS_Skip_B_Pictures	1
	#define BWID_MPG2VD_S1SS_STALL_PICT_END	1
	#define BWID_MPG2VD_S1SS_STALL_PICT_BEGIN	1
	#define BWID_MPG2VD_S1SS_STALL_GOP_AFTER	1
	#define BWID_MPG2VD_S1SS_STALL_SEQ_BEGIN	1
	/* Register Bit MASKS for MPG2VD_S1SS */
	#define BMSK_MPG2VD_S1SS_reserved_31_5	0xffffffe0 /*  */
	#define BMSK_MPG2VD_S1SS_Skip_B_Pictures	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_S1SS_STALL_PICT_END	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_S1SS_STALL_PICT_BEGIN	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_S1SS_STALL_GOP_AFTER	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S1SS_STALL_SEQ_BEGIN	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S1SS - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S1SS_reserved_31_5	 0x0188, 5, 27, 0xffffffe0
	#define BITFIELD_MPG2VD_S1SS_Skip_B_Pictures	 0x0188, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_S1SS_STALL_PICT_END	 0x0188, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_S1SS_STALL_PICT_BEGIN	 0x0188, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_S1SS_STALL_GOP_AFTER	 0x0188, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S1SS_STALL_SEQ_BEGIN	 0x0188, 0, 1, 0x00000001
#define ROFF_MPG2VD_S1SC	0x18c /* Decoder 1 Core Stall Control */ 
	#define BITFIELD_MPG2VD_S1SC	 0x018c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_S1SC */
	#define BLSB_MPG2VD_S1SC_reserved_31_2	2
	#define BLSB_MPG2VD_S1SC_SkipToNext	1
	#define BLSB_MPG2VD_S1SC_StallContinue	0
	/* Register Bit Widths for MPG2VD_S1SC */
	#define BWID_MPG2VD_S1SC_reserved_31_2	30
	#define BWID_MPG2VD_S1SC_SkipToNext	1
	#define BWID_MPG2VD_S1SC_StallContinue	1
	/* Register Bit MASKS for MPG2VD_S1SC */
	#define BMSK_MPG2VD_S1SC_reserved_31_2	0xfffffffc /*  */
	#define BMSK_MPG2VD_S1SC_SkipToNext	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_S1SC_StallContinue	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_S1SC - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_S1SC_reserved_31_2	 0x018c, 2, 30, 0xfffffffc
	#define BITFIELD_MPG2VD_S1SC_SkipToNext	 0x018c, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_S1SC_StallContinue	 0x018c, 0, 1, 0x00000001
#define ROFF_MPG2VD_S1ASDBC	0x190 /* Decoder 1 Core Additional Stream Data Configuration */ 
	#define BITFIELD_MPG2VD_S1ASDBC	 0x0190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1ASDFP	0x194 /* Decoder 1 Core Additional Stream Data Front Pointer */ 
	#define BITFIELD_MPG2VD_S1ASDFP	 0x0194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1ASDBP	0x198 /* Decoder 1 Core Additional Stream Data Back Pointer */ 
	#define BITFIELD_MPG2VD_S1ASDBP	 0x0198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1ASDR	0x19c /* Decoder 1 Core Additional Stream Data Read */ 
	#define BITFIELD_MPG2VD_S1ASDR	 0x019c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1SI1	0x1a0 /* Decoder 1 Core Sequence Info 1 */ 
	#define BITFIELD_MPG2VD_S1SI1	 0x01a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1SI2	0x1a4 /* Decoder 1 Core Sequence Info 2 */ 
	#define BITFIELD_MPG2VD_S1SI2	 0x01a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1SI3	0x1a8 /* Decoder 1 Core Sequence Info 3 */ 
	#define BITFIELD_MPG2VD_S1SI3	 0x01a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1SI4	0x1ac /* Decoder 1 Core Sequence Info 4 */ 
	#define BITFIELD_MPG2VD_S1SI4	 0x01ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1PI1	0x1b0 /* Decoder 1 Core Picture Info 1 */ 
	#define BITFIELD_MPG2VD_S1PI1	 0x01b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1PI2	0x1b4 /* Decoder 1 Core Picture Info 2 */ 
	#define BITFIELD_MPG2VD_S1PI2	 0x01b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1PI3	0x1b8 /* Decoder 1 Core Picture Info 3 */ 
	#define BITFIELD_MPG2VD_S1PI3	 0x01b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1PCE	0x1bc /* Decoder 1 Core Picture Coding Extension with Composite Display Flag Set */ 
	#define BITFIELD_MPG2VD_S1PCE	 0x01bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1SDE1	0x1c0 /* Decoder 1 Core Sequence Display Extension 1 */ 
	#define BITFIELD_MPG2VD_S1SDE1	 0x01c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1SDE2	0x1c4 /* Decoder 1 Core Sequence Display Extension 2 */ 
	#define BITFIELD_MPG2VD_S1SDE2	 0x01c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_S1GH	0x1c8 /* Decoder 1 Core GOP Header */ 
	#define BITFIELD_MPG2VD_S1GH	 0x01c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0BE	0x200 /* FBM Master Buffer Enables */ 
	#define BITFIELD_MPG2VD_FBM0BE	 0x0200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PAP	0x204 /* FBM Buffer Pool Address Pointer */ 
	#define BITFIELD_MPG2VD_FBM0PAP	 0x0204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0YBA	0x208 /* FBM Y Buffer Address */ 
	#define BITFIELD_MPG2VD_FBM0YBA	 0x0208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0UVBA	0x20c /* FBM UV Buffer Address */ 
	#define BITFIELD_MPG2VD_FBM0UVBA	 0x020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PYBA	0x210 /* FBM PIP Y Buffer Address */ 
	#define BITFIELD_MPG2VD_FBM0PYBA	 0x0210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PUVBA	0x214 /* FBM PIP UV Buffer Address */ 
	#define BITFIELD_MPG2VD_FBM0PUVBA	 0x0214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0BI	0x218 /* FBM Buffer Info */ 
	#define BITFIELD_MPG2VD_FBM0BI	 0x0218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_FBM0BI */
	#define BLSB_MPG2VD_FBM0BI_reserved_31_23	23
	#define BLSB_MPG2VD_FBM0BI_Discontinuity	22
	#define BLSB_MPG2VD_FBM0BI_ProgSeq	21
	#define BLSB_MPG2VD_FBM0BI_ProgFrame	20
	#define BLSB_MPG2VD_FBM0BI_PictStruct	18
	#define BLSB_MPG2VD_FBM0BI_TopFieldFirst	17
	#define BLSB_MPG2VD_FBM0BI_ReptFirstField	16
	#define BLSB_MPG2VD_FBM0BI_SequenceNumber	6
	#define BLSB_MPG2VD_FBM0BI_FwdRefFrame	5
	#define BLSB_MPG2VD_FBM0BI_BwdRefFrame	4
	#define BLSB_MPG2VD_FBM0BI_InDisplayQueue	3
	#define BLSB_MPG2VD_FBM0BI_DecoderLocked	2
	#define BLSB_MPG2VD_FBM0BI_PictureCodingType	0
	/* Register Bit Widths for MPG2VD_FBM0BI */
	#define BWID_MPG2VD_FBM0BI_reserved_31_23	9
	#define BWID_MPG2VD_FBM0BI_Discontinuity	1
	#define BWID_MPG2VD_FBM0BI_ProgSeq	1
	#define BWID_MPG2VD_FBM0BI_ProgFrame	1
	#define BWID_MPG2VD_FBM0BI_PictStruct	2
	#define BWID_MPG2VD_FBM0BI_TopFieldFirst	1
	#define BWID_MPG2VD_FBM0BI_ReptFirstField	1
	#define BWID_MPG2VD_FBM0BI_SequenceNumber	10
	#define BWID_MPG2VD_FBM0BI_FwdRefFrame	1
	#define BWID_MPG2VD_FBM0BI_BwdRefFrame	1
	#define BWID_MPG2VD_FBM0BI_InDisplayQueue	1
	#define BWID_MPG2VD_FBM0BI_DecoderLocked	1
	#define BWID_MPG2VD_FBM0BI_PictureCodingType	2
	/* Register Bit MASKS for MPG2VD_FBM0BI */
	#define BMSK_MPG2VD_FBM0BI_reserved_31_23	0xff800000 /*  */
	#define BMSK_MPG2VD_FBM0BI_Discontinuity	(1<<22) /* == 0x00400000:  */
	#define BMSK_MPG2VD_FBM0BI_ProgSeq	(1<<21) /* == 0x00200000:  */
	#define BMSK_MPG2VD_FBM0BI_ProgFrame	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_FBM0BI_PictStruct	0x000c0000 /*  */
	#define BMSK_MPG2VD_FBM0BI_TopFieldFirst	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_FBM0BI_ReptFirstField	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_FBM0BI_SequenceNumber	0x0000ffc0 /*  */
	#define BMSK_MPG2VD_FBM0BI_FwdRefFrame	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_FBM0BI_BwdRefFrame	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_FBM0BI_InDisplayQueue	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_FBM0BI_DecoderLocked	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_FBM0BI_PictureCodingType	0x00000003 /*  */
	/* Register BITFIELD for MPG2VD_FBM0BI - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_FBM0BI_reserved_31_23	 0x0218, 23, 9, 0xff800000
	#define BITFIELD_MPG2VD_FBM0BI_Discontinuity	 0x0218, 22, 1, 0x00400000
	#define BITFIELD_MPG2VD_FBM0BI_ProgSeq	 0x0218, 21, 1, 0x00200000
	#define BITFIELD_MPG2VD_FBM0BI_ProgFrame	 0x0218, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_FBM0BI_PictStruct	 0x0218, 18, 2, 0x000c0000
	#define BITFIELD_MPG2VD_FBM0BI_TopFieldFirst	 0x0218, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_FBM0BI_ReptFirstField	 0x0218, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_FBM0BI_SequenceNumber	 0x0218, 6, 10, 0x0000ffc0
	#define BITFIELD_MPG2VD_FBM0BI_FwdRefFrame	 0x0218, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_FBM0BI_BwdRefFrame	 0x0218, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_FBM0BI_InDisplayQueue	 0x0218, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_FBM0BI_DecoderLocked	 0x0218, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_FBM0BI_PictureCodingType	 0x0218, 0, 2, 0x00000003
#define ROFF_MPG2VD_FBM0BRI	0x21c /* FBM Buffer Resolution Info */ 
	#define BITFIELD_MPG2VD_FBM0BRI	 0x021c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_FBM0BRI */
	#define BLSB_MPG2VD_FBM0BRI_ProgSequence	31
	#define BLSB_MPG2VD_FBM0BRI_HorizontalSize	20
	#define BLSB_MPG2VD_FBM0BRI_VerticalSize	9
	#define BLSB_MPG2VD_FBM0BRI_FrameRateCode	5
	#define BLSB_MPG2VD_FBM0BRI_AspectRatioInfo	1
	#define BLSB_MPG2VD_FBM0BRI_Chroma420	0
	/* Register Bit Widths for MPG2VD_FBM0BRI */
	#define BWID_MPG2VD_FBM0BRI_ProgSequence	1
	#define BWID_MPG2VD_FBM0BRI_HorizontalSize	11
	#define BWID_MPG2VD_FBM0BRI_VerticalSize	11
	#define BWID_MPG2VD_FBM0BRI_FrameRateCode	4
	#define BWID_MPG2VD_FBM0BRI_AspectRatioInfo	4
	#define BWID_MPG2VD_FBM0BRI_Chroma420	1
	/* Register Bit MASKS for MPG2VD_FBM0BRI */
	#define BMSK_MPG2VD_FBM0BRI_ProgSequence	(1<<31) /* == 0x80000000:  */
	#define BMSK_MPG2VD_FBM0BRI_HorizontalSize	0x7ff00000 /*  */
	#define BMSK_MPG2VD_FBM0BRI_VerticalSize	0x000ffe00 /*  */
	#define BMSK_MPG2VD_FBM0BRI_FrameRateCode	0x000001e0 /*  */
	#define BMSK_MPG2VD_FBM0BRI_AspectRatioInfo	0x0000001e /*  */
	#define BMSK_MPG2VD_FBM0BRI_Chroma420	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_FBM0BRI - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_FBM0BRI_ProgSequence	 0x021c, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_FBM0BRI_HorizontalSize	 0x021c, 20, 11, 0x7ff00000
	#define BITFIELD_MPG2VD_FBM0BRI_VerticalSize	 0x021c, 9, 11, 0x000ffe00
	#define BITFIELD_MPG2VD_FBM0BRI_FrameRateCode	 0x021c, 5, 4, 0x000001e0
	#define BITFIELD_MPG2VD_FBM0BRI_AspectRatioInfo	 0x021c, 1, 4, 0x0000001e
	#define BITFIELD_MPG2VD_FBM0BRI_Chroma420	 0x021c, 0, 1, 0x00000001
#define ROFF_MPG2VD_FBM0GC	0x220 /* FBM General Control */ 
	#define BITFIELD_MPG2VD_FBM0GC	 0x0220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0TDR	0x224 /* FBM Tracker Display Queue Release */ 
	#define BITFIELD_MPG2VD_FBM0TDR	 0x0224, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DQS	0x228 /* FBM Display Queue Status */ 
	#define BITFIELD_MPG2VD_FBM0DQS	 0x0228, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_FBM0DQS */
	#define BLSB_MPG2VD_FBM0DQS_reserved_31_14	14
	#define BLSB_MPG2VD_FBM0DQS_SWDisplayQNotEmpty	13
	#define BLSB_MPG2VD_FBM0DQS_HWDisplayQNotEmpty	12
	#define BLSB_MPG2VD_FBM0DQS_DecodeInProgress	11
	#define BLSB_MPG2VD_FBM0DQS_reserved_10	10
	#define BLSB_MPG2VD_FBM0DQS_CanDisplayBuffer	5
	#define BLSB_MPG2VD_FBM0DQS_CurDecodeBuffer	0
	/* Register Bit Widths for MPG2VD_FBM0DQS */
	#define BWID_MPG2VD_FBM0DQS_reserved_31_14	18
	#define BWID_MPG2VD_FBM0DQS_SWDisplayQNotEmpty	1
	#define BWID_MPG2VD_FBM0DQS_HWDisplayQNotEmpty	1
	#define BWID_MPG2VD_FBM0DQS_DecodeInProgress	1
	#define BWID_MPG2VD_FBM0DQS_reserved_10	1
	#define BWID_MPG2VD_FBM0DQS_CanDisplayBuffer	5
	#define BWID_MPG2VD_FBM0DQS_CurDecodeBuffer	5
	/* Register Bit MASKS for MPG2VD_FBM0DQS */
	#define BMSK_MPG2VD_FBM0DQS_reserved_31_14	0xffffc000 /*  */
	#define BMSK_MPG2VD_FBM0DQS_SWDisplayQNotEmpty	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_FBM0DQS_HWDisplayQNotEmpty	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_FBM0DQS_DecodeInProgress	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_FBM0DQS_reserved_10	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_FBM0DQS_CanDisplayBuffer	0x000003e0 /* Valid while decoding and with STALL_PICT_END */
	#define BMSK_MPG2VD_FBM0DQS_CurDecodeBuffer	0x0000001f /* Valid while decoding and with STALL_PICT_END */
	/* Register BITFIELD for MPG2VD_FBM0DQS - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_FBM0DQS_reserved_31_14	 0x0228, 14, 18, 0xffffc000
	#define BITFIELD_MPG2VD_FBM0DQS_SWDisplayQNotEmpty	 0x0228, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_FBM0DQS_HWDisplayQNotEmpty	 0x0228, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_FBM0DQS_DecodeInProgress	 0x0228, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_FBM0DQS_reserved_10	 0x0228, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_FBM0DQS_CanDisplayBuffer	 0x0228, 5, 5, 0x000003e0
	#define BITFIELD_MPG2VD_FBM0DQS_CurDecodeBuffer	 0x0228, 0, 5, 0x0000001f
#define ROFF_MPG2VD_FBM0DQPO	0x22c /* FBM Display Queue Entries */ 
	#define BITFIELD_MPG2VD_FBM0DQPO	 0x022c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSC	0x230 /* FBM PTS Control */ 
	#define BITFIELD_MPG2VD_FBM0PTSC	 0x0230, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTVM	0x234 /* FBM PTS Table (MSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTVM	 0x0234, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTVL	0x238 /* FBM PTS Table (LSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTVL	 0x0238, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSOM	0x23c /* FBM PTS Offset (MSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTSOM	 0x023c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSOL	0x240 /* FBM PTS Offset (LSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTSOL	 0x0240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSAM	0x244 /* FBM PTS Accum Init Value (MSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTSAM	 0x0244, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSAL	0x248 /* FBM PTS Accum Init Value (LSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTSAL	 0x0248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSASM	0x24c /* FBM PTS Accum Step Size (MSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTSASM	 0x024c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PTSASL	0x250 /* FBM PTS Accum Step Size (LSB) */ 
	#define BITFIELD_MPG2VD_FBM0PTSASL	 0x0250, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DYR	0x254 /* FBM Destination Y Buffer Register Address */ 
	#define BITFIELD_MPG2VD_FBM0DYR	 0x0254, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DUVR	0x258 /* FBM Destination UV Buffer Register Address */ 
	#define BITFIELD_MPG2VD_FBM0DUVR	 0x0258, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DFMR	0x25c /* FBM Destination flip mode Register Address */ 
	#define BITFIELD_MPG2VD_FBM0DFMR	 0x025c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0NDB	0x260 /* FBM Next Display Buffer */ 
	#define BITFIELD_MPG2VD_FBM0NDB	 0x0260, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0NDBR	0x264 /* FBM Next Display Buffer Resolution */ 
	#define BITFIELD_MPG2VD_FBM0NDBR	 0x0264, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PSCO1	0x268 /* FBM Pan Scan Frame Center Offset 1 */ 
	#define BITFIELD_MPG2VD_FBM0PSCO1	 0x0268, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PSCO2	0x26c /* FBM Pan Scan Frame Center Offset 2 */ 
	#define BITFIELD_MPG2VD_FBM0PSCO2	 0x026c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0PSCO3	0x270 /* FBM Pan Scan Frame Center Offset 3 */ 
	#define BITFIELD_MPG2VD_FBM0PSCO3	 0x0270, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQY	0x274 /* FBM Software Queue Y Address */ 
	#define BITFIELD_MPG2VD_FBM0SQY	 0x0274, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQUV	0x278 /* FBM Software Queue UV Address */ 
	#define BITFIELD_MPG2VD_FBM0SQUV	 0x0278, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQPM	0x27c /* FBM Software Queue PTS Value (MSB) */ 
	#define BITFIELD_MPG2VD_FBM0SQPM	 0x027c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQPL	0x280 /* FBM Software Queue PTS value (LSB) */ 
	#define BITFIELD_MPG2VD_FBM0SQPL	 0x0280, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0FQCS	0x284 /* FBM Buffer Software Queue Control Status */ 
	#define BITFIELD_MPG2VD_FBM0FQCS	 0x0284, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0BDRI	0x288 /* FBM Buffer Display Resolution Info */ 
	#define BITFIELD_MPG2VD_FBM0BDRI	 0x0288, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0YVPRA	0x28c /* FBM Destination Y Vertical Phase Register Address */ 
	#define BITFIELD_MPG2VD_FBM0YVPRA	 0x028c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQYVP	0x290 /* FBM Software Queue Y Vertical Phase */ 
	#define BITFIELD_MPG2VD_FBM0SQYVP	 0x0290, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DUVUPR	0x294 /* FBM Destination UV Vertical Phase Register */ 
	#define BITFIELD_MPG2VD_FBM0DUVUPR	 0x0294, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQUVVP	0x298 /* FBM Software Queue UV Vertical Phase */ 
	#define BITFIELD_MPG2VD_FBM0SQUVVP	 0x0298, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DHPRA	0x29c /* FBM Destination Horizontal Phase Register Address */ 
	#define BITFIELD_MPG2VD_FBM0DHPRA	 0x029c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQHP	0x2a0 /* FBM Software Queue Horizontal Phase */ 
	#define BITFIELD_MPG2VD_FBM0SQHP	 0x02a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0DIPSR	0x2a4 /* FBM Destination Initial Phase Shift Register */ 
	#define BITFIELD_MPG2VD_FBM0DIPSR	 0x02a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM0SQIPS	0x2a8 /* FBM Software Queue Initial Phase Shift */ 
	#define BITFIELD_MPG2VD_FBM0SQIPS	 0x02a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1BE	0x300 /* FBM Master Buffer Enables */ 
	#define BITFIELD_MPG2VD_FBM1BE	 0x0300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PAP	0x304 /* FBM Buffer Pool Address Pointer */ 
	#define BITFIELD_MPG2VD_FBM1PAP	 0x0304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1YBA	0x308 /* FBM Y Buffer Address */ 
	#define BITFIELD_MPG2VD_FBM1YBA	 0x0308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1UVBA	0x30c /* FBM UV Buffer Address */ 
	#define BITFIELD_MPG2VD_FBM1UVBA	 0x030c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PYBA	0x310 /* FBM PIP Y Buffer Address  */ 
	#define BITFIELD_MPG2VD_FBM1PYBA	 0x0310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PUVBA	0x314 /* FBM PIP UV Buffer Address  */ 
	#define BITFIELD_MPG2VD_FBM1PUVBA	 0x0314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1BI	0x318 /* FBM Buffer Info */ 
	#define BITFIELD_MPG2VD_FBM1BI	 0x0318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_FBM1BI */
	#define BLSB_MPG2VD_FBM1BI_reserved_31_23	23
	#define BLSB_MPG2VD_FBM1BI_Discontinuity	22
	#define BLSB_MPG2VD_FBM1BI_ProgSeq	21
	#define BLSB_MPG2VD_FBM1BI_ProgFrame	20
	#define BLSB_MPG2VD_FBM1BI_PictStruct	18
	#define BLSB_MPG2VD_FBM1BI_TopFieldFirst	17
	#define BLSB_MPG2VD_FBM1BI_ReptFirstField	16
	#define BLSB_MPG2VD_FBM1BI_SequenceNumber	6
	#define BLSB_MPG2VD_FBM1BI_FwdRefFrame	5
	#define BLSB_MPG2VD_FBM1BI_BwdRefFrame	4
	#define BLSB_MPG2VD_FBM1BI_InDisplayQueue	3
	#define BLSB_MPG2VD_FBM1BI_DecoderLocked	2
	#define BLSB_MPG2VD_FBM1BI_PictureCodingType	0
	/* Register Bit Widths for MPG2VD_FBM1BI */
	#define BWID_MPG2VD_FBM1BI_reserved_31_23	9
	#define BWID_MPG2VD_FBM1BI_Discontinuity	1
	#define BWID_MPG2VD_FBM1BI_ProgSeq	1
	#define BWID_MPG2VD_FBM1BI_ProgFrame	1
	#define BWID_MPG2VD_FBM1BI_PictStruct	2
	#define BWID_MPG2VD_FBM1BI_TopFieldFirst	1
	#define BWID_MPG2VD_FBM1BI_ReptFirstField	1
	#define BWID_MPG2VD_FBM1BI_SequenceNumber	10
	#define BWID_MPG2VD_FBM1BI_FwdRefFrame	1
	#define BWID_MPG2VD_FBM1BI_BwdRefFrame	1
	#define BWID_MPG2VD_FBM1BI_InDisplayQueue	1
	#define BWID_MPG2VD_FBM1BI_DecoderLocked	1
	#define BWID_MPG2VD_FBM1BI_PictureCodingType	2
	/* Register Bit MASKS for MPG2VD_FBM1BI */
	#define BMSK_MPG2VD_FBM1BI_reserved_31_23	0xff800000 /*  */
	#define BMSK_MPG2VD_FBM1BI_Discontinuity	(1<<22) /* == 0x00400000:  */
	#define BMSK_MPG2VD_FBM1BI_ProgSeq	(1<<21) /* == 0x00200000:  */
	#define BMSK_MPG2VD_FBM1BI_ProgFrame	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_FBM1BI_PictStruct	0x000c0000 /*  */
	#define BMSK_MPG2VD_FBM1BI_TopFieldFirst	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_FBM1BI_ReptFirstField	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_FBM1BI_SequenceNumber	0x0000ffc0 /*  */
	#define BMSK_MPG2VD_FBM1BI_FwdRefFrame	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_FBM1BI_BwdRefFrame	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_FBM1BI_InDisplayQueue	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_FBM1BI_DecoderLocked	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_FBM1BI_PictureCodingType	0x00000003 /*  */
	/* Register BITFIELD for MPG2VD_FBM1BI - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_FBM1BI_reserved_31_23	 0x0318, 23, 9, 0xff800000
	#define BITFIELD_MPG2VD_FBM1BI_Discontinuity	 0x0318, 22, 1, 0x00400000
	#define BITFIELD_MPG2VD_FBM1BI_ProgSeq	 0x0318, 21, 1, 0x00200000
	#define BITFIELD_MPG2VD_FBM1BI_ProgFrame	 0x0318, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_FBM1BI_PictStruct	 0x0318, 18, 2, 0x000c0000
	#define BITFIELD_MPG2VD_FBM1BI_TopFieldFirst	 0x0318, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_FBM1BI_ReptFirstField	 0x0318, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_FBM1BI_SequenceNumber	 0x0318, 6, 10, 0x0000ffc0
	#define BITFIELD_MPG2VD_FBM1BI_FwdRefFrame	 0x0318, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_FBM1BI_BwdRefFrame	 0x0318, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_FBM1BI_InDisplayQueue	 0x0318, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_FBM1BI_DecoderLocked	 0x0318, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_FBM1BI_PictureCodingType	 0x0318, 0, 2, 0x00000003
#define ROFF_MPG2VD_FBM1BRI	0x31c /* FBM Buffer Resolution Info */ 
	#define BITFIELD_MPG2VD_FBM1BRI	 0x031c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_FBM1BRI */
	#define BLSB_MPG2VD_FBM1BRI_ProgSequence	31
	#define BLSB_MPG2VD_FBM1BRI_HorizontalSize	20
	#define BLSB_MPG2VD_FBM1BRI_VerticalSize	9
	#define BLSB_MPG2VD_FBM1BRI_FrameRateCode	5
	#define BLSB_MPG2VD_FBM1BRI_AspectRatioInfo	1
	#define BLSB_MPG2VD_FBM1BRI_Chroma420	0
	/* Register Bit Widths for MPG2VD_FBM1BRI */
	#define BWID_MPG2VD_FBM1BRI_ProgSequence	1
	#define BWID_MPG2VD_FBM1BRI_HorizontalSize	11
	#define BWID_MPG2VD_FBM1BRI_VerticalSize	11
	#define BWID_MPG2VD_FBM1BRI_FrameRateCode	4
	#define BWID_MPG2VD_FBM1BRI_AspectRatioInfo	4
	#define BWID_MPG2VD_FBM1BRI_Chroma420	1
	/* Register Bit MASKS for MPG2VD_FBM1BRI */
	#define BMSK_MPG2VD_FBM1BRI_ProgSequence	(1<<31) /* == 0x80000000:  */
	#define BMSK_MPG2VD_FBM1BRI_HorizontalSize	0x7ff00000 /*  */
	#define BMSK_MPG2VD_FBM1BRI_VerticalSize	0x000ffe00 /*  */
	#define BMSK_MPG2VD_FBM1BRI_FrameRateCode	0x000001e0 /*  */
	#define BMSK_MPG2VD_FBM1BRI_AspectRatioInfo	0x0000001e /*  */
	#define BMSK_MPG2VD_FBM1BRI_Chroma420	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_FBM1BRI - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_FBM1BRI_ProgSequence	 0x031c, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_FBM1BRI_HorizontalSize	 0x031c, 20, 11, 0x7ff00000
	#define BITFIELD_MPG2VD_FBM1BRI_VerticalSize	 0x031c, 9, 11, 0x000ffe00
	#define BITFIELD_MPG2VD_FBM1BRI_FrameRateCode	 0x031c, 5, 4, 0x000001e0
	#define BITFIELD_MPG2VD_FBM1BRI_AspectRatioInfo	 0x031c, 1, 4, 0x0000001e
	#define BITFIELD_MPG2VD_FBM1BRI_Chroma420	 0x031c, 0, 1, 0x00000001
#define ROFF_MPG2VD_FBM1GC	0x320 /* FBM General Control */ 
	#define BITFIELD_MPG2VD_FBM1GC	 0x0320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1TDR	0x324 /* FBM Tracker Display Queue Release */ 
	#define BITFIELD_MPG2VD_FBM1TDR	 0x0324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DQS	0x328 /* FBM Display Queue Status */ 
	#define BITFIELD_MPG2VD_FBM1DQS	 0x0328, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DQPO	0x32c /* FBM Display Queue Entries */ 
	#define BITFIELD_MPG2VD_FBM1DQPO	 0x032c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSC	0x330 /* FBM PTS Control */ 
	#define BITFIELD_MPG2VD_FBM1PTSC	 0x0330, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTVM	0x334 /* FBM PTS Table (MSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTVM	 0x0334, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTVL	0x338 /* FBM PTS Table (LSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTVL	 0x0338, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSOM	0x33c /* FBM PTS Offset (MSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTSOM	 0x033c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSOL	0x340 /* FBM PTS Offset (LSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTSOL	 0x0340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSAM	0x344 /* FBM PTS Accum Init Value (MSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTSAM	 0x0344, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSAL	0x348 /* FBM PTS Accum Init Value (LSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTSAL	 0x0348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSASM	0x34c /* FBM PTS Accum Step Size (MSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTSASM	 0x034c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PTSASL	0x350 /* FBM PTS Accum Step Size (LSB) */ 
	#define BITFIELD_MPG2VD_FBM1PTSASL	 0x0350, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DYR	0x354 /* FBM Destination Y Buffer Register Address */ 
	#define BITFIELD_MPG2VD_FBM1DYR	 0x0354, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DUVR	0x358 /* FBM Destination UV Buffer Register Address */ 
	#define BITFIELD_MPG2VD_FBM1DUVR	 0x0358, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DFMR	0x35c /* FBM Destination flip mode Register Address */ 
	#define BITFIELD_MPG2VD_FBM1DFMR	 0x035c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1NDB	0x360 /* FBM Next Display Buffer */ 
	#define BITFIELD_MPG2VD_FBM1NDB	 0x0360, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1NDBR	0x364 /* FBM Next Display Buffer Resolution */ 
	#define BITFIELD_MPG2VD_FBM1NDBR	 0x0364, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PSCO1	0x368 /* FBM Pan Scan Frame Center Offset 1 */ 
	#define BITFIELD_MPG2VD_FBM1PSCO1	 0x0368, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PSCO2	0x36c /* FBM Pan Scan Frame Center Offset 2 */ 
	#define BITFIELD_MPG2VD_FBM1PSCO2	 0x036c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1PSCO3	0x370 /* FBM Pan Scan Frame Center Offset 3 */ 
	#define BITFIELD_MPG2VD_FBM1PSCO3	 0x0370, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQY	0x374 /* FBM Software Queue Y Address */ 
	#define BITFIELD_MPG2VD_FBM1SQY	 0x0374, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQUV	0x378 /* FBM Software Queue UV Address */ 
	#define BITFIELD_MPG2VD_FBM1SQUV	 0x0378, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQPM	0x37c /* FBM Software Queue PTS Value (MSB) */ 
	#define BITFIELD_MPG2VD_FBM1SQPM	 0x037c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQPL	0x380 /* FBM Software Queue PTS value (LSB) */ 
	#define BITFIELD_MPG2VD_FBM1SQPL	 0x0380, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1FQCS	0x384 /* FBM Buffer Software Queue Control Status */ 
	#define BITFIELD_MPG2VD_FBM1FQCS	 0x0384, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1BDRI	0x388 /* FBM Buffer Display Resolution Info */ 
	#define BITFIELD_MPG2VD_FBM1BDRI	 0x0388, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DYVPRA	0x38c /* FBM Destination Y Vertical Phase Register Address */ 
	#define BITFIELD_MPG2VD_FBM1DYVPRA	 0x038c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQYVP	0x390 /* FBM Software Queue Y Vertical Phase */ 
	#define BITFIELD_MPG2VD_FBM1SQYVP	 0x0390, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DUVVPR	0x394 /* FBM Destination UV Vertical Phase Register */ 
	#define BITFIELD_MPG2VD_FBM1DUVVPR	 0x0394, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQUVVP	0x398 /* FBM Software Queue UV Vertical Phase */ 
	#define BITFIELD_MPG2VD_FBM1SQUVVP	 0x0398, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DHPRA	0x39c /* FBM Destination Horizontal Phase Register Address */ 
	#define BITFIELD_MPG2VD_FBM1DHPRA	 0x039c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQHP	0x3a0 /* FBM Software Queue Horizontal Phase */ 
	#define BITFIELD_MPG2VD_FBM1SQHP	 0x03a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1DIPSR	0x3a4 /* FBM Destination Initial Phase Shift Register */ 
	#define BITFIELD_MPG2VD_FBM1DIPSR	 0x03a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_FBM1SQIPS	0x3a8 /* FBM Software Queue Initial Phase Shift */ 
	#define BITFIELD_MPG2VD_FBM1SQIPS	 0x03a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPTCR0	0x400 /* PES Packet Parser 0 Timer Control Register */ 
	#define BITFIELD_MPG2VD_PPTCR0	 0x0400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPCR0	0x404 /* PES Packet Parser 0 Control Register */ 
	#define BITFIELD_MPG2VD_PPCR0	 0x0404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_PPCR0 */
	#define BLSB_MPG2VD_PPCR0_PESERRCLR	31
	#define BLSB_MPG2VD_PPCR0_PESEN	30
	#define BLSB_MPG2VD_PPCR0_PESBP	29
	#define BLSB_MPG2VD_PPCR0_Decoder_Flush	28
	#define BLSB_MPG2VD_PPCR0_NFlush	27
	#define BLSB_MPG2VD_PPCR0_STCCLR	26
	#define BLSB_MPG2VD_PPCR0_reserved_25_24	24
	#define BLSB_MPG2VD_PPCR0_STRMID_8_EN	23
	#define BLSB_MPG2VD_PPCR0_STRMID_8_DS	22
	#define BLSB_MPG2VD_PPCR0_STRMID_7_EN	21
	#define BLSB_MPG2VD_PPCR0_STRMID_7_DS	20
	#define BLSB_MPG2VD_PPCR0_STRMID_6_EN	19
	#define BLSB_MPG2VD_PPCR0_STRMID_6_DS	18
	#define BLSB_MPG2VD_PPCR0_STRMID_5_EN	17
	#define BLSB_MPG2VD_PPCR0_STRMID_5_DS	16
	#define BLSB_MPG2VD_PPCR0_STRMID_4_EN	15
	#define BLSB_MPG2VD_PPCR0_STRMID_4_DS	14
	#define BLSB_MPG2VD_PPCR0_STRMID_3_EN	13
	#define BLSB_MPG2VD_PPCR0_STRMID_3_DS	12
	#define BLSB_MPG2VD_PPCR0_STRMID_2_EN	11
	#define BLSB_MPG2VD_PPCR0_STRMID_2_DS	10
	#define BLSB_MPG2VD_PPCR0_STRMID_1_EN	9
	#define BLSB_MPG2VD_PPCR0_STRMID_1_DS	8
	#define BLSB_MPG2VD_PPCR0_reserved_7_6	6
	#define BLSB_MPG2VD_PPCR0_EXT_FIFO_TH	0
	/* Register Bit Widths for MPG2VD_PPCR0 */
	#define BWID_MPG2VD_PPCR0_PESERRCLR	1
	#define BWID_MPG2VD_PPCR0_PESEN	1
	#define BWID_MPG2VD_PPCR0_PESBP	1
	#define BWID_MPG2VD_PPCR0_Decoder_Flush	1
	#define BWID_MPG2VD_PPCR0_NFlush	1
	#define BWID_MPG2VD_PPCR0_STCCLR	1
	#define BWID_MPG2VD_PPCR0_reserved_25_24	2
	#define BWID_MPG2VD_PPCR0_STRMID_8_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_8_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_7_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_7_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_6_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_6_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_5_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_5_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_4_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_4_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_3_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_3_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_2_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_2_DS	1
	#define BWID_MPG2VD_PPCR0_STRMID_1_EN	1
	#define BWID_MPG2VD_PPCR0_STRMID_1_DS	1
	#define BWID_MPG2VD_PPCR0_reserved_7_6	2
	#define BWID_MPG2VD_PPCR0_EXT_FIFO_TH	6
	/* Register Bit MASKS for MPG2VD_PPCR0 */
	#define BMSK_MPG2VD_PPCR0_PESERRCLR	(1<<31) /* == 0x80000000: SW error clear */
	#define BMSK_MPG2VD_PPCR0_PESEN	(1<<30) /* == 0x40000000: Parser Enable */
	#define BMSK_MPG2VD_PPCR0_PESBP	(1<<29) /* == 0x20000000: Parser Bypass */
	#define BMSK_MPG2VD_PPCR0_Decoder_Flush	(1<<28) /* == 0x10000000:  */
	#define BMSK_MPG2VD_PPCR0_NFlush	(1<<27) /* == 0x08000000:  */
	#define BMSK_MPG2VD_PPCR0_STCCLR	(1<<26) /* == 0x04000000:  */
	#define BMSK_MPG2VD_PPCR0_reserved_25_24	0x03000000 /*  */
	#define BMSK_MPG2VD_PPCR0_STRMID_8_EN	(1<<23) /* == 0x00800000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_8_DS	(1<<22) /* == 0x00400000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_7_EN	(1<<21) /* == 0x00200000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_7_DS	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_6_EN	(1<<19) /* == 0x00080000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_6_DS	(1<<18) /* == 0x00040000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_5_EN	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_5_DS	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_4_EN	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_4_DS	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_3_EN	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_3_DS	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_2_EN	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_2_DS	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_PPCR0_STRMID_1_EN	(1<<9) /* == 0x00000200: Prog Startcode ID 1 enable */
	#define BMSK_MPG2VD_PPCR0_STRMID_1_DS	(1<<8) /* == 0x00000100: Discont id for start code ID 1 */
	#define BMSK_MPG2VD_PPCR0_reserved_7_6	0x000000c0 /*  */
	#define BMSK_MPG2VD_PPCR0_EXT_FIFO_TH	0x0000003f /*  */
	/* Register BITFIELD for MPG2VD_PPCR0 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_PPCR0_PESERRCLR	 0x0404, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_PPCR0_PESEN	 0x0404, 30, 1, 0x40000000
	#define BITFIELD_MPG2VD_PPCR0_PESBP	 0x0404, 29, 1, 0x20000000
	#define BITFIELD_MPG2VD_PPCR0_Decoder_Flush	 0x0404, 28, 1, 0x10000000
	#define BITFIELD_MPG2VD_PPCR0_NFlush	 0x0404, 27, 1, 0x08000000
	#define BITFIELD_MPG2VD_PPCR0_STCCLR	 0x0404, 26, 1, 0x04000000
	#define BITFIELD_MPG2VD_PPCR0_reserved_25_24	 0x0404, 24, 2, 0x03000000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_8_EN	 0x0404, 23, 1, 0x00800000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_8_DS	 0x0404, 22, 1, 0x00400000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_7_EN	 0x0404, 21, 1, 0x00200000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_7_DS	 0x0404, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_6_EN	 0x0404, 19, 1, 0x00080000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_6_DS	 0x0404, 18, 1, 0x00040000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_5_EN	 0x0404, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_5_DS	 0x0404, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_4_EN	 0x0404, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_4_DS	 0x0404, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_3_EN	 0x0404, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_3_DS	 0x0404, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_PPCR0_STRMID_2_EN	 0x0404, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_PPCR0_STRMID_2_DS	 0x0404, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_PPCR0_STRMID_1_EN	 0x0404, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_PPCR0_STRMID_1_DS	 0x0404, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_PPCR0_reserved_7_6	 0x0404, 6, 2, 0x000000c0
	#define BITFIELD_MPG2VD_PPCR0_EXT_FIFO_TH	 0x0404, 0, 6, 0x0000003f
#define ROFF_MPG2VD_PPSR0	0x408 /* PES Packet Parser 0 Status Register */ 
	#define BITFIELD_MPG2VD_PPSR0	 0x0408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPIDR0	0x40c /* PES Packet Parser 0 Status ID Register */ 
	#define BITFIELD_MPG2VD_PPIDR0	 0x040c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR10	0x410 /* PES Packet Parser 0 Data Register 1 */ 
	#define BITFIELD_MPG2VD_PPDR10	 0x0410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR20	0x414 /* PES Packet Parser 0 Data Register 2 */ 
	#define BITFIELD_MPG2VD_PPDR20	 0x0414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR30	0x418 /* PES Packet Parser 0 Data Register 3 */ 
	#define BITFIELD_MPG2VD_PPDR30	 0x0418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR40	0x41c /* PES Packet Parser 0 Data Register 4 */ 
	#define BITFIELD_MPG2VD_PPDR40	 0x041c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR50	0x420 /* PES Packet Parser 0 Data Register 5 */ 
	#define BITFIELD_MPG2VD_PPDR50	 0x0420, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR60	0x424 /* PES Packet Parser 0 Data Register 6 */ 
	#define BITFIELD_MPG2VD_PPDR60	 0x0424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR70	0x428 /* PES Packet Parser 0 Data Register 7 */ 
	#define BITFIELD_MPG2VD_PPDR70	 0x0428, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPEDR0	0x42c /* PES Packet Parser 0 Extension Data Register */ 
	#define BITFIELD_MPG2VD_PPEDR0	 0x042c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPSC10	0x430 /* PES Packet Parser 0 Programmable Start Codes 1 */ 
	#define BITFIELD_MPG2VD_PPSC10	 0x0430, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPSC20	0x434 /* PES Packet Parser 0 Programmable Start Codes 2 */ 
	#define BITFIELD_MPG2VD_PPSC20	 0x0434, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDOSM0	0x438 /* PES Packet Parser 0 Discontinuity Old STC (MSB) */ 
	#define BITFIELD_MPG2VD_PDOSM0	 0x0438, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDOSL0	0x43c /* PES Packet Parser 0 Discontinuity Old STC (LSB) */ 
	#define BITFIELD_MPG2VD_PDOSL0	 0x043c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDNSM0	0x440 /* PES Packet Parser 0 Discontinuity NEW STC (MSB) */ 
	#define BITFIELD_MPG2VD_PDNSM0	 0x0440, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDNSL0	0x444 /* PES Packet Parser 0 Discontinuity NEW STC (LSB) */ 
	#define BITFIELD_MPG2VD_PDNSL0	 0x0444, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPTCR1	0x480 /* PES Packet Parser 1 Timer Control Register */ 
	#define BITFIELD_MPG2VD_PPTCR1	 0x0480, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPCR1	0x484 /* PES Packet Parser 1 Control Register */ 
	#define BITFIELD_MPG2VD_PPCR1	 0x0484, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_PPCR1 */
	#define BLSB_MPG2VD_PPCR1_PESERRCLR	31
	#define BLSB_MPG2VD_PPCR1_PESEN	30
	#define BLSB_MPG2VD_PPCR1_PESBP	29
	#define BLSB_MPG2VD_PPCR1_Decoder_Flush	28
	#define BLSB_MPG2VD_PPCR1_NFlush	27
	#define BLSB_MPG2VD_PPCR1_STCCLR	26
	#define BLSB_MPG2VD_PPCR1_reserved_25_24	24
	#define BLSB_MPG2VD_PPCR1_STRMID_8_EN	23
	#define BLSB_MPG2VD_PPCR1_STRMID_8_DS	22
	#define BLSB_MPG2VD_PPCR1_STRMID_7_EN	21
	#define BLSB_MPG2VD_PPCR1_STRMID_7_DS	20
	#define BLSB_MPG2VD_PPCR1_STRMID_6_EN	19
	#define BLSB_MPG2VD_PPCR1_STRMID_6_DS	18
	#define BLSB_MPG2VD_PPCR1_STRMID_5_EN	17
	#define BLSB_MPG2VD_PPCR1_STRMID_5_DS	16
	#define BLSB_MPG2VD_PPCR1_STRMID_4_EN	15
	#define BLSB_MPG2VD_PPCR1_STRMID_4_DS	14
	#define BLSB_MPG2VD_PPCR1_STRMID_3_EN	13
	#define BLSB_MPG2VD_PPCR1_STRMID_3_DS	12
	#define BLSB_MPG2VD_PPCR1_STRMID_2_EN	11
	#define BLSB_MPG2VD_PPCR1_STRMID_2_DS	10
	#define BLSB_MPG2VD_PPCR1_STRMID_1_EN	9
	#define BLSB_MPG2VD_PPCR1_STRMID_1_DS	8
	#define BLSB_MPG2VD_PPCR1_reserved_7_6	6
	#define BLSB_MPG2VD_PPCR1_EXT_FIFO_TH	0
	/* Register Bit Widths for MPG2VD_PPCR1 */
	#define BWID_MPG2VD_PPCR1_PESERRCLR	1
	#define BWID_MPG2VD_PPCR1_PESEN	1
	#define BWID_MPG2VD_PPCR1_PESBP	1
	#define BWID_MPG2VD_PPCR1_Decoder_Flush	1
	#define BWID_MPG2VD_PPCR1_NFlush	1
	#define BWID_MPG2VD_PPCR1_STCCLR	1
	#define BWID_MPG2VD_PPCR1_reserved_25_24	2
	#define BWID_MPG2VD_PPCR1_STRMID_8_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_8_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_7_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_7_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_6_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_6_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_5_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_5_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_4_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_4_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_3_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_3_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_2_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_2_DS	1
	#define BWID_MPG2VD_PPCR1_STRMID_1_EN	1
	#define BWID_MPG2VD_PPCR1_STRMID_1_DS	1
	#define BWID_MPG2VD_PPCR1_reserved_7_6	2
	#define BWID_MPG2VD_PPCR1_EXT_FIFO_TH	6
	/* Register Bit MASKS for MPG2VD_PPCR1 */
	#define BMSK_MPG2VD_PPCR1_PESERRCLR	(1<<31) /* == 0x80000000: SW error clear */
	#define BMSK_MPG2VD_PPCR1_PESEN	(1<<30) /* == 0x40000000: Parser Enable */
	#define BMSK_MPG2VD_PPCR1_PESBP	(1<<29) /* == 0x20000000: Parser Bypass */
	#define BMSK_MPG2VD_PPCR1_Decoder_Flush	(1<<28) /* == 0x10000000:  */
	#define BMSK_MPG2VD_PPCR1_NFlush	(1<<27) /* == 0x08000000:  */
	#define BMSK_MPG2VD_PPCR1_STCCLR	(1<<26) /* == 0x04000000:  */
	#define BMSK_MPG2VD_PPCR1_reserved_25_24	0x03000000 /*  */
	#define BMSK_MPG2VD_PPCR1_STRMID_8_EN	(1<<23) /* == 0x00800000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_8_DS	(1<<22) /* == 0x00400000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_7_EN	(1<<21) /* == 0x00200000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_7_DS	(1<<20) /* == 0x00100000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_6_EN	(1<<19) /* == 0x00080000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_6_DS	(1<<18) /* == 0x00040000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_5_EN	(1<<17) /* == 0x00020000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_5_DS	(1<<16) /* == 0x00010000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_4_EN	(1<<15) /* == 0x00008000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_4_DS	(1<<14) /* == 0x00004000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_3_EN	(1<<13) /* == 0x00002000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_3_DS	(1<<12) /* == 0x00001000:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_2_EN	(1<<11) /* == 0x00000800:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_2_DS	(1<<10) /* == 0x00000400:  */
	#define BMSK_MPG2VD_PPCR1_STRMID_1_EN	(1<<9) /* == 0x00000200: Prog Startcode ID 1 enable */
	#define BMSK_MPG2VD_PPCR1_STRMID_1_DS	(1<<8) /* == 0x00000100: Discont id for start code ID 1 */
	#define BMSK_MPG2VD_PPCR1_reserved_7_6	0x000000c0 /*  */
	#define BMSK_MPG2VD_PPCR1_EXT_FIFO_TH	0x0000003f /*  */
	/* Register BITFIELD for MPG2VD_PPCR1 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_PPCR1_PESERRCLR	 0x0484, 31, 1, 0x80000000
	#define BITFIELD_MPG2VD_PPCR1_PESEN	 0x0484, 30, 1, 0x40000000
	#define BITFIELD_MPG2VD_PPCR1_PESBP	 0x0484, 29, 1, 0x20000000
	#define BITFIELD_MPG2VD_PPCR1_Decoder_Flush	 0x0484, 28, 1, 0x10000000
	#define BITFIELD_MPG2VD_PPCR1_NFlush	 0x0484, 27, 1, 0x08000000
	#define BITFIELD_MPG2VD_PPCR1_STCCLR	 0x0484, 26, 1, 0x04000000
	#define BITFIELD_MPG2VD_PPCR1_reserved_25_24	 0x0484, 24, 2, 0x03000000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_8_EN	 0x0484, 23, 1, 0x00800000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_8_DS	 0x0484, 22, 1, 0x00400000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_7_EN	 0x0484, 21, 1, 0x00200000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_7_DS	 0x0484, 20, 1, 0x00100000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_6_EN	 0x0484, 19, 1, 0x00080000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_6_DS	 0x0484, 18, 1, 0x00040000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_5_EN	 0x0484, 17, 1, 0x00020000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_5_DS	 0x0484, 16, 1, 0x00010000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_4_EN	 0x0484, 15, 1, 0x00008000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_4_DS	 0x0484, 14, 1, 0x00004000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_3_EN	 0x0484, 13, 1, 0x00002000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_3_DS	 0x0484, 12, 1, 0x00001000
	#define BITFIELD_MPG2VD_PPCR1_STRMID_2_EN	 0x0484, 11, 1, 0x00000800
	#define BITFIELD_MPG2VD_PPCR1_STRMID_2_DS	 0x0484, 10, 1, 0x00000400
	#define BITFIELD_MPG2VD_PPCR1_STRMID_1_EN	 0x0484, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_PPCR1_STRMID_1_DS	 0x0484, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_PPCR1_reserved_7_6	 0x0484, 6, 2, 0x000000c0
	#define BITFIELD_MPG2VD_PPCR1_EXT_FIFO_TH	 0x0484, 0, 6, 0x0000003f
#define ROFF_MPG2VD_PPSR1	0x488 /* PES Packet Parser 1 Status Register */ 
	#define BITFIELD_MPG2VD_PPSR1	 0x0488, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPIDR1	0x48c /* PES Packet Parser 1 Status ID Register */ 
	#define BITFIELD_MPG2VD_PPIDR1	 0x048c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR11	0x490 /* PES Packet Parser 1 Data Register 1 */ 
	#define BITFIELD_MPG2VD_PPDR11	 0x0490, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR21	0x494 /* PES Packet Parser 1 Data Register 2 */ 
	#define BITFIELD_MPG2VD_PPDR21	 0x0494, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR31	0x498 /* PES Packet Parser 1 Data Register 3 */ 
	#define BITFIELD_MPG2VD_PPDR31	 0x0498, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR41	0x49c /* PES Packet Parser 1 Data Register 4 */ 
	#define BITFIELD_MPG2VD_PPDR41	 0x049c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR51	0x4a0 /* PES Packet Parser 1 Data Register 5 */ 
	#define BITFIELD_MPG2VD_PPDR51	 0x04a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR61	0x4a4 /* PES Packet Parser 1 Data Register 6 */ 
	#define BITFIELD_MPG2VD_PPDR61	 0x04a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPDR71	0x4a8 /* PES Packet Parser 1 Data Register 7 */ 
	#define BITFIELD_MPG2VD_PPDR71	 0x04a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPEDR1	0x4ac /* PES Packet Parser 1 Extension Data Register */ 
	#define BITFIELD_MPG2VD_PPEDR1	 0x04ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPSC11	0x4b0 /* PES Packet Parser 1 Programmable Start Codes 1 */ 
	#define BITFIELD_MPG2VD_PPSC11	 0x04b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PPSC21	0x4b4 /* PES Packet Parser 1 Programmable Start Codes 2 */ 
	#define BITFIELD_MPG2VD_PPSC21	 0x04b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDOSM1	0x4b8 /* PES Packet Parser 1 Discontinuity Old STC (MSB) */ 
	#define BITFIELD_MPG2VD_PDOSM1	 0x04b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDOSL1	0x4bc /* PES Packet Parser 1 Discontinuity Old STC (LSB) */ 
	#define BITFIELD_MPG2VD_PDOSL1	 0x04bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDNSM1	0x4c0 /* PES Packet Parser 1 Discontinuity NEW STC (MSB) */ 
	#define BITFIELD_MPG2VD_PDNSM1	 0x04c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_PDNSL1	0x4c4 /* PES Packet Parser 1 Discontinuity NEW STC (LSB) */ 
	#define BITFIELD_MPG2VD_PDNSL1	 0x04c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0CBBA	0x500 /* Stream 0 DMA Circular/Linear Buffer Base Address */ 
	#define BITFIELD_MPG2VD_SD0CBBA	 0x0500, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0SBRP	0x504 /* Stream 0 DMA Source Block Register Address of Read Pointer */ 
	#define BITFIELD_MPG2VD_SD0SBRP	 0x0504, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0CBS	0x508 /* Stream 0 DMA Circular/Linear Buffer Size */ 
	#define BITFIELD_MPG2VD_SD0CBS	 0x0508, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0PDV	0x50c /* Stream 0 DMA Read/Write Pointer Watermark */ 
	#define BITFIELD_MPG2VD_SD0PDV	 0x050c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0WT	0x510 /* Stream 0 DMA Watchdog Timer */ 
	#define BITFIELD_MPG2VD_SD0WT	 0x0510, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LRP	0x514 /* Stream 0 DMA Local Read Pointer */ 
	#define BITFIELD_MPG2VD_SD0LRP	 0x0514, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LWP	0x518 /* Stream 0 DMA Local Write Pointer */ 
	#define BITFIELD_MPG2VD_SD0LWP	 0x0518, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LINK	0x51c /* Stream 0 DMA Link Address */ 
	#define BITFIELD_MPG2VD_SD0LINK	 0x051c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LLSA	0x520 /* Stream 0 DMA Link List Source Address */ 
	#define BITFIELD_MPG2VD_SD0LLSA	 0x0520, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LNDA	0x524 /* Stream 0 DMA Link List Next Descriptor Address */ 
	#define BITFIELD_MPG2VD_SD0LNDA	 0x0524, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LDBC	0x528 /* Stream 0 DMA Link List Data Buffer Byte Count */ 
	#define BITFIELD_MPG2VD_SD0LDBC	 0x0528, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LCBC	0x52c /* Stream 0 DMA Link List Current Data Buffer Byte Count */ 
	#define BITFIELD_MPG2VD_SD0LCBC	 0x052c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0LDC	0x530 /* Stream 0 DMA Link List Descriptor Control */ 
	#define BITFIELD_MPG2VD_SD0LDC	 0x0530, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1CBBA	0x580 /* Stream 1 DMA Circular/Linear Buffer Base Address */ 
	#define BITFIELD_MPG2VD_SD1CBBA	 0x0580, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1SBRP	0x584 /* Stream 1 DMA Source Block Register Address of Read Pointer */ 
	#define BITFIELD_MPG2VD_SD1SBRP	 0x0584, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1CBS	0x588 /* Stream 1 DMA Circular/Linear Buffer Size */ 
	#define BITFIELD_MPG2VD_SD1CBS	 0x0588, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1PDV	0x58c /* Stream 1 DMA Read/Write Pointer Watermark */ 
	#define BITFIELD_MPG2VD_SD1PDV	 0x058c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1WT	0x590 /* Stream 1 DMA Watchdog Timer */ 
	#define BITFIELD_MPG2VD_SD1WT	 0x0590, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LRP	0x594 /* Stream 1 DMA Local Read Pointer */ 
	#define BITFIELD_MPG2VD_SD1LRP	 0x0594, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LWP	0x598 /* Stream 1 DMA Local Write Pointer */ 
	#define BITFIELD_MPG2VD_SD1LWP	 0x0598, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LINK	0x59c /* Stream 1 DMA Link Address */ 
	#define BITFIELD_MPG2VD_SD1LINK	 0x059c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LLSA	0x5a0 /* Stream 1 DMA Link List Source Address */ 
	#define BITFIELD_MPG2VD_SD1LLSA	 0x05a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LNDA	0x5a4 /* Stream 1 DMA Link List Next Descriptor Address */ 
	#define BITFIELD_MPG2VD_SD1LNDA	 0x05a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LDBC	0x5a8 /* Stream 1 DMA Link List Data Buffer Byte Count */ 
	#define BITFIELD_MPG2VD_SD1LDBC	 0x05a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LCBC	0x5ac /* Stream 1 DMA Link List Current Data Buffer Byte Count */ 
	#define BITFIELD_MPG2VD_SD1LCBC	 0x05ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1LDC	0x5b0 /* Stream 1 DMA Link List Descriptor Control */ 
	#define BITFIELD_MPG2VD_SD1LDC	 0x05b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD0FWP	0x700 /* Stream 0 FIFO input */ 
	#define BITFIELD_MPG2VD_SD0FWP	 0x0700, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SD1FWP	0x704 /* Stream 1 FIFO input */ 
	#define BITFIELD_MPG2VD_SD1FWP	 0x0704, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_SDFSTAT	0x708 /* FIFO Status */ 
	#define BITFIELD_MPG2VD_SDFSTAT	 0x0708, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_SDFSTAT */
	#define BLSB_MPG2VD_SDFSTAT_reserved_31_8	8
	#define BLSB_MPG2VD_SDFSTAT_Stream1FSMIdle	7
	#define BLSB_MPG2VD_SDFSTAT_Stream1PESStall	6
	#define BLSB_MPG2VD_SDFSTAT_Stream1SyncFIFOEmpty	5
	#define BLSB_MPG2VD_SDFSTAT_Stream1AsyncFIFOEmpty	4
	#define BLSB_MPG2VD_SDFSTAT_Stream0FSMIdle	3
	#define BLSB_MPG2VD_SDFSTAT_Stream0PESStall	2
	#define BLSB_MPG2VD_SDFSTAT_Stream0SyncFIFOEmpty	1
	#define BLSB_MPG2VD_SDFSTAT_Stream0AsyncFIFOEmpty	0
	/* Register Bit Widths for MPG2VD_SDFSTAT */
	#define BWID_MPG2VD_SDFSTAT_reserved_31_8	24
	#define BWID_MPG2VD_SDFSTAT_Stream1FSMIdle	1
	#define BWID_MPG2VD_SDFSTAT_Stream1PESStall	1
	#define BWID_MPG2VD_SDFSTAT_Stream1SyncFIFOEmpty	1
	#define BWID_MPG2VD_SDFSTAT_Stream1AsyncFIFOEmpty	1
	#define BWID_MPG2VD_SDFSTAT_Stream0FSMIdle	1
	#define BWID_MPG2VD_SDFSTAT_Stream0PESStall	1
	#define BWID_MPG2VD_SDFSTAT_Stream0SyncFIFOEmpty	1
	#define BWID_MPG2VD_SDFSTAT_Stream0AsyncFIFOEmpty	1
	/* Register Bit MASKS for MPG2VD_SDFSTAT */
	#define BMSK_MPG2VD_SDFSTAT_reserved_31_8	0xffffff00 /*  */
	#define BMSK_MPG2VD_SDFSTAT_Stream1FSMIdle	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream1PESStall	(1<<6) /* == 0x00000040:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream1SyncFIFOEmpty	(1<<5) /* == 0x00000020:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream1AsyncFIFOEmpty	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream0FSMIdle	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream0PESStall	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream0SyncFIFOEmpty	(1<<1) /* == 0x00000002:  */
	#define BMSK_MPG2VD_SDFSTAT_Stream0AsyncFIFOEmpty	(1<<0) /* == 0x00000001:  */
	/* Register BITFIELD for MPG2VD_SDFSTAT - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_SDFSTAT_reserved_31_8	 0x0708, 8, 24, 0xffffff00
	#define BITFIELD_MPG2VD_SDFSTAT_Stream1FSMIdle	 0x0708, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_SDFSTAT_Stream1PESStall	 0x0708, 6, 1, 0x00000040
	#define BITFIELD_MPG2VD_SDFSTAT_Stream1SyncFIFOEmpty	 0x0708, 5, 1, 0x00000020
	#define BITFIELD_MPG2VD_SDFSTAT_Stream1AsyncFIFOEmpty	 0x0708, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_SDFSTAT_Stream0FSMIdle	 0x0708, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_SDFSTAT_Stream0PESStall	 0x0708, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_SDFSTAT_Stream0SyncFIFOEmpty	 0x0708, 1, 1, 0x00000002
	#define BITFIELD_MPG2VD_SDFSTAT_Stream0AsyncFIFOEmpty	 0x0708, 0, 1, 0x00000001
#define ROFF_MPG2VD_STC_AM0	0x600 /* STC_A (MSB) */ 
	#define BITFIELD_MPG2VD_STC_AM0	 0x0600, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_AL0	0x604 /* STC_A (LSB) */ 
	#define BITFIELD_MPG2VD_STC_AL0	 0x0604, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_BM0	0x608 /* STC_B (MSB) */ 
	#define BITFIELD_MPG2VD_STC_BM0	 0x0608, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_BL0	0x60c /* STC_B (LSB) */ 
	#define BITFIELD_MPG2VD_STC_BL0	 0x060c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CTRL0	0x610 /* STC Control */ 
	#define BITFIELD_MPG2VD_STC_CTRL0	 0x0610, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_STC_CTRL0 */
	#define BLSB_MPG2VD_STC_CTRL0_reserved_31_10	10
	#define BLSB_MPG2VD_STC_CTRL0_DisableSTCCounter	9
	#define BLSB_MPG2VD_STC_CTRL0_VDC_STC_SampleSelect	8
	#define BLSB_MPG2VD_STC_CTRL0_Counter90KhzPrescalerSelect	7
	#define BLSB_MPG2VD_STC_CTRL0_PrefilterClockSelect	5
	#define BLSB_MPG2VD_STC_CTRL0_STC_CNT_ACTIVE	4
	#define BLSB_MPG2VD_STC_CTRL0_CounterTimeoutEnable	3
	#define BLSB_MPG2VD_STC_CTRL0_CounterTimeoutMode	2
	#define BLSB_MPG2VD_STC_CTRL0_SwitchControl	0
	/* Register Bit Widths for MPG2VD_STC_CTRL0 */
	#define BWID_MPG2VD_STC_CTRL0_reserved_31_10	22
	#define BWID_MPG2VD_STC_CTRL0_DisableSTCCounter	1
	#define BWID_MPG2VD_STC_CTRL0_VDC_STC_SampleSelect	1
	#define BWID_MPG2VD_STC_CTRL0_Counter90KhzPrescalerSelect	1
	#define BWID_MPG2VD_STC_CTRL0_PrefilterClockSelect	2
	#define BWID_MPG2VD_STC_CTRL0_STC_CNT_ACTIVE	1
	#define BWID_MPG2VD_STC_CTRL0_CounterTimeoutEnable	1
	#define BWID_MPG2VD_STC_CTRL0_CounterTimeoutMode	1
	#define BWID_MPG2VD_STC_CTRL0_SwitchControl	2
	/* Register Bit MASKS for MPG2VD_STC_CTRL0 */
	#define BMSK_MPG2VD_STC_CTRL0_reserved_31_10	0xfffffc00 /*  */
	#define BMSK_MPG2VD_STC_CTRL0_DisableSTCCounter	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_STC_CTRL0_VDC_STC_SampleSelect	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_STC_CTRL0_Counter90KhzPrescalerSelect	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_STC_CTRL0_PrefilterClockSelect	0x00000060 /*  */
	#define BMSK_MPG2VD_STC_CTRL0_STC_CNT_ACTIVE	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_STC_CTRL0_CounterTimeoutEnable	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_STC_CTRL0_CounterTimeoutMode	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_STC_CTRL0_SwitchControl	0x00000003 /*  */
	/* Register BITFIELD for MPG2VD_STC_CTRL0 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_STC_CTRL0_reserved_31_10	 0x0610, 10, 22, 0xfffffc00
	#define BITFIELD_MPG2VD_STC_CTRL0_DisableSTCCounter	 0x0610, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_STC_CTRL0_VDC_STC_SampleSelect	 0x0610, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_STC_CTRL0_Counter90KhzPrescalerSelect	 0x0610, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_STC_CTRL0_PrefilterClockSelect	 0x0610, 5, 2, 0x00000060
	#define BITFIELD_MPG2VD_STC_CTRL0_STC_CNT_ACTIVE	 0x0610, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_STC_CTRL0_CounterTimeoutEnable	 0x0610, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_STC_CTRL0_CounterTimeoutMode	 0x0610, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_STC_CTRL0_SwitchControl	 0x0610, 0, 2, 0x00000003
#define ROFF_MPG2VD_STC_CNTM0	0x614 /* STC Count Value (MSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTM0	 0x0614, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CNTL0	0x618 /* STC Count Value (LSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTL0	 0x0618, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CNTTM0	0x61c /* STC Count Timer (MSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTTM0	 0x061c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CNTTL0	0x620 /* STC Count Timer (LSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTTL0	 0x0620, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_VCNTM0	0x624 /* STC VDC Count (MSB) */ 
	#define BITFIELD_MPG2VD_STC_VCNTM0	 0x0624, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_VCNTL0	0x628 /* STC VDC Count (LSB) */ 
	#define BITFIELD_MPG2VD_STC_VCNTL0	 0x0628, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_AM1	0x680 /* STC_A (MSB) */ 
	#define BITFIELD_MPG2VD_STC_AM1	 0x0680, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_AL1	0x684 /* STC_A (LSB) */ 
	#define BITFIELD_MPG2VD_STC_AL1	 0x0684, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_BM1	0x688 /* STC_B (MSB) */ 
	#define BITFIELD_MPG2VD_STC_BM1	 0x0688, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_BL1	0x68c /* STC_B (LSB) */ 
	#define BITFIELD_MPG2VD_STC_BL1	 0x068c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CTRL1	0x690 /* STC Control */ 
	#define BITFIELD_MPG2VD_STC_CTRL1	 0x0690, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
	/* Register Bit LSB Positions for MPG2VD_STC_CTRL1 */
	#define BLSB_MPG2VD_STC_CTRL1_reserved_31_10	10
	#define BLSB_MPG2VD_STC_CTRL1_DisableSTCCounter	9
	#define BLSB_MPG2VD_STC_CTRL1_VDC_STC_SampleSelect	8
	#define BLSB_MPG2VD_STC_CTRL1_Counter90KhzPrescalerSelect	7
	#define BLSB_MPG2VD_STC_CTRL1_PrefilterClockSelect	5
	#define BLSB_MPG2VD_STC_CTRL1_STC_CNT_ACTIVE	4
	#define BLSB_MPG2VD_STC_CTRL1_CounterTimeoutEnable	3
	#define BLSB_MPG2VD_STC_CTRL1_CounterTimeoutMode	2
	#define BLSB_MPG2VD_STC_CTRL1_SwitchControl	0
	/* Register Bit Widths for MPG2VD_STC_CTRL1 */
	#define BWID_MPG2VD_STC_CTRL1_reserved_31_10	22
	#define BWID_MPG2VD_STC_CTRL1_DisableSTCCounter	1
	#define BWID_MPG2VD_STC_CTRL1_VDC_STC_SampleSelect	1
	#define BWID_MPG2VD_STC_CTRL1_Counter90KhzPrescalerSelect	1
	#define BWID_MPG2VD_STC_CTRL1_PrefilterClockSelect	2
	#define BWID_MPG2VD_STC_CTRL1_STC_CNT_ACTIVE	1
	#define BWID_MPG2VD_STC_CTRL1_CounterTimeoutEnable	1
	#define BWID_MPG2VD_STC_CTRL1_CounterTimeoutMode	1
	#define BWID_MPG2VD_STC_CTRL1_SwitchControl	2
	/* Register Bit MASKS for MPG2VD_STC_CTRL1 */
	#define BMSK_MPG2VD_STC_CTRL1_reserved_31_10	0xfffffc00 /*  */
	#define BMSK_MPG2VD_STC_CTRL1_DisableSTCCounter	(1<<9) /* == 0x00000200:  */
	#define BMSK_MPG2VD_STC_CTRL1_VDC_STC_SampleSelect	(1<<8) /* == 0x00000100:  */
	#define BMSK_MPG2VD_STC_CTRL1_Counter90KhzPrescalerSelect	(1<<7) /* == 0x00000080:  */
	#define BMSK_MPG2VD_STC_CTRL1_PrefilterClockSelect	0x00000060 /*  */
	#define BMSK_MPG2VD_STC_CTRL1_STC_CNT_ACTIVE	(1<<4) /* == 0x00000010:  */
	#define BMSK_MPG2VD_STC_CTRL1_CounterTimeoutEnable	(1<<3) /* == 0x00000008:  */
	#define BMSK_MPG2VD_STC_CTRL1_CounterTimeoutMode	(1<<2) /* == 0x00000004:  */
	#define BMSK_MPG2VD_STC_CTRL1_SwitchControl	0x00000003 /*  */
	/* Register BITFIELD for MPG2VD_STC_CTRL1 - roff, lsb, width, mask */
	#define BITFIELD_MPG2VD_STC_CTRL1_reserved_31_10	 0x0690, 10, 22, 0xfffffc00
	#define BITFIELD_MPG2VD_STC_CTRL1_DisableSTCCounter	 0x0690, 9, 1, 0x00000200
	#define BITFIELD_MPG2VD_STC_CTRL1_VDC_STC_SampleSelect	 0x0690, 8, 1, 0x00000100
	#define BITFIELD_MPG2VD_STC_CTRL1_Counter90KhzPrescalerSelect	 0x0690, 7, 1, 0x00000080
	#define BITFIELD_MPG2VD_STC_CTRL1_PrefilterClockSelect	 0x0690, 5, 2, 0x00000060
	#define BITFIELD_MPG2VD_STC_CTRL1_STC_CNT_ACTIVE	 0x0690, 4, 1, 0x00000010
	#define BITFIELD_MPG2VD_STC_CTRL1_CounterTimeoutEnable	 0x0690, 3, 1, 0x00000008
	#define BITFIELD_MPG2VD_STC_CTRL1_CounterTimeoutMode	 0x0690, 2, 1, 0x00000004
	#define BITFIELD_MPG2VD_STC_CTRL1_SwitchControl	 0x0690, 0, 2, 0x00000003
#define ROFF_MPG2VD_STC_CNTM1	0x694 /* STC Count Value (MSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTM1	 0x0694, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CNTL1	0x698 /* STC Count Value (LSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTL1	 0x0698, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CNTTM1	0x69c /* STC Count Timer (MSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTTM1	 0x069c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_CNTTL1	0x6a0 /* STC Count Timer (LSB) */ 
	#define BITFIELD_MPG2VD_STC_CNTTL1	 0x06a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_VCNTM1	0x6a4 /* STC VDC Count (MSB) */ 
	#define BITFIELD_MPG2VD_STC_VCNTM1	 0x06a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MPG2VD_STC_VCNTL1	0x6a8 /* STC VDC Count (LSB) */ 
	#define BITFIELD_MPG2VD_STC_VCNTL1	 0x06a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module MPG2VD SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_MPG2VD_INTERRUPT_OCCURED	0x1
#define SVEN_MODULE_EVENT_MPG2VD_PUSH_FRAME	0x2
#define SVEN_MODULE_EVENT_MPG2VD_CAN_DISPLAY	0x3
#define SVEN_MODULE_EVENT_MPG2VD_CIRC_BUF_WRITE	0x4
#define SVEN_MODULE_EVENT_MPG2VD_DISPLAY_QUEUE_RELEASE	0x5
#define SVEN_MODULE_EVENT_MPG2VD_FRAMES_OUT_OF_ORDER	0x6
#define SVEN_MODULE_EVENT_MPG2VD_DISCONT	0x7
#define SVEN_MODULE_EVENT_MPG2VD_PTS_FROM_TSD	0x8
#define SVEN_MODULE_EVENT_MPG2VD_PTS_VBV_INDEX	0x9
#define SVEN_MODULE_EVENT_MPG2VD_PTS_VBV_INDEX2	0xa
#define SVEN_MODULE_EVENT_MPG2VD_PTS_VBV_INDEX3	0xb
#define SVEN_MODULE_EVENT_MPG2VD_FLUSH_START	0xc
#define SVEN_MODULE_EVENT_MPG2VD_FLUSH_STOP	0xd
#define SVEN_MODULE_EVENT_MPG2VD_THROW_AWAY	0xe
#define SVEN_MODULE_EVENT_MPG2VD_NEW_EVENT	0xf


#endif /* MPG2VD_REGOFFS_H */
