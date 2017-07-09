#ifndef MFD_REGOFFS_H
#define MFD_REGOFFS_H 1
#warning including deprecated file MFD_REGOFFS_H please use sanitized filename
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


/* Module MFD CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_MFD_MFD_SIF_HW_ID	0x0 /* MFD SIF HW ID */ 
	#define BITFIELD_MFD_MFD_SIF_HW_ID	 0x0000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_FW_ID	0x4 /* MFD SIF FW ID */ 
	#define BITFIELD_MFD_MFD_SIF_FW_ID	 0x0004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_SOFT_RST	0x8 /* MFD SIF SOFT RST */ 
	#define BITFIELD_MFD_MFD_SIF_SOFT_RST	 0x0008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_HOST_INT_STAT	0xc /* MFD HOST INT STAT */ 
	#define BITFIELD_MFD_MFD_HOST_INT_STAT	 0x000c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_DECODER_SEL	0x10 /* MFD DECODER SEL */ 
	#define BITFIELD_MFD_MFD_DECODER_SEL	 0x0010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_HOST_INT_EN	0x14 /* MFD HOST INT EN */ 
	#define BITFIELD_MFD_MFD_HOST_INT_EN	 0x0014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_SYS_PMODE	0x18 /* MFD SIF SYS PMODE */ 
	#define BITFIELD_MFD_MFD_SIF_SYS_PMODE	 0x0018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_HOST_SMP_SET	0x1c /* MFD SIF HOST SMP SET */ 
	#define BITFIELD_MFD_MFD_SIF_HOST_SMP_SET	 0x001c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_HOST_SMP_MASK	0x20 /* MFD SIF HOST SMP MASK */ 
	#define BITFIELD_MFD_MFD_SIF_HOST_SMP_MASK	 0x0020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_CORE_SMP_SET	0x24 /* MFD SIF CORE SMP SET */ 
	#define BITFIELD_MFD_MFD_SIF_CORE_SMP_SET	 0x0024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_CORE_SMP_MASK	0x28 /* MFD SIF CORE SMP MASK */ 
	#define BITFIELD_MFD_MFD_SIF_CORE_SMP_MASK	 0x0028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_HOST_SMP_DATA	0x2c /* MFD SIF HOST SMP DATA */ 
	#define BITFIELD_MFD_MFD_SIF_HOST_SMP_DATA	 0x002c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_SIF_CORE_SMP_DATA	0x30 /* MFD SIF CORE SMP DATA */ 
	#define BITFIELD_MFD_MFD_SIF_CORE_SMP_DATA	 0x0030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_SIF_INT_STATUS	0x34 /* MFD VSPARC SIF INT STAT */ 
	#define BITFIELD_MFD_MFD_VSPARC_SIF_INT_STATUS	 0x0034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_CORE_INT_STATUS	0x38 /* MFD VSPARC CORE INT STA */ 
	#define BITFIELD_MFD_MFD_VSPARC_CORE_INT_STATUS	 0x0038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_SCD_INT_STATUS	0x3c /* MFD VSPARC SCD INT STAT */ 
	#define BITFIELD_MFD_MFD_VSPARC_SCD_INT_STATUS	 0x003c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DMA_INT_STATUS	0x40 /* MFD VSPARC DMA INT STAT */ 
	#define BITFIELD_MFD_MFD_VSPARC_DMA_INT_STATUS	 0x0040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VCMH_FBW	0x48 /* MFD VCMH FBW */ 
	#define BITFIELD_MFD_MFD_VCMH_FBW	 0x0048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_OMAR_FW_STATUS	0x4c /* MFD OMAR FW STATUS */ 
	#define BITFIELD_MFD_MFD_OMAR_FW_STATUS	 0x004c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_OMAR_FW_DATA	0x50 /* MFD OMAR FW DATA */ 
	#define BITFIELD_MFD_MFD_OMAR_FW_DATA	 0x0050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_INTC_INT_MASK	0x200 /* MFD INIC INT MASK */ 
	#define BITFIELD_MFD_MFD_INTC_INT_MASK	 0x0200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_INTC_INT_PEND	0x204 /* MFD INTC INT PEND */ 
	#define BITFIELD_MFD_MFD_INTC_INT_PEND	 0x0204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_INTC_INT_FORCE	0x208 /* MFD INTC INT FORCE */ 
	#define BITFIELD_MFD_MFD_INTC_INT_FORCE	 0x0208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_INTC_CLR_INT_PEND	0x20c /* MFD INTC CLR INT PEND */ 
	#define BITFIELD_MFD_MFD_INTC_CLR_INT_PEND	 0x020c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER0_VAL	0x400 /* MFD TIMER0 VAL */ 
	#define BITFIELD_MFD_MFD_TIMER0_VAL	 0x0400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER0_LOAD	0x404 /* MFD TIMER0 LOAD */ 
	#define BITFIELD_MFD_MFD_TIMER0_LOAD	 0x0404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER0_CTRL	0x408 /* MFD TIMER0 CTRL */ 
	#define BITFIELD_MFD_MFD_TIMER0_CTRL	 0x0408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER1_VAL	0x410 /* MFD TIMER1 VAL */ 
	#define BITFIELD_MFD_MFD_TIMER1_VAL	 0x0410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER1_LOAD	0x414 /* MFD TIMER1 LOAD */ 
	#define BITFIELD_MFD_MFD_TIMER1_LOAD	 0x0414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER1_CTRL	0x418 /* MFD TIMER1 CTRL */ 
	#define BITFIELD_MFD_MFD_TIMER1_CTRL	 0x0418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER_SCALER	0x420 /* MFD TIMER SCALER */ 
	#define BITFIELD_MFD_MFD_TIMER_SCALER	 0x0420, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_TIMER_PRESET	0x424 /* MFD TIMER PRESET */ 
	#define BITFIELD_MFD_MFD_TIMER_PRESET	 0x0424, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_LINEAR_DMA_EMA	0xa00 /* MFD LINEAR DMA EMA */ 
	#define BITFIELD_MFD_MFD_LINEAR_DMA_EMA	 0x0a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_LINEAR_DMA_CONF	0xa04 /* MFD LINEAR DMA CONF */ 
	#define BITFIELD_MFD_MFD_LINEAR_DMA_CONF	 0x0a04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_LINEAR_DMA_DO_XFER	0xa08 /* MFD LINEAR DMA DO XFER */ 
	#define BITFIELD_MFD_MFD_LINEAR_DMA_DO_XFER	 0x0a08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_LINEAR_DMA_XFER_STAT	0xa0c /* MFD LINEAR DMA XFER STA */ 
	#define BITFIELD_MFD_MFD_LINEAR_DMA_XFER_STAT	 0x0a0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_DQM_ODPQ_CS	0xb5c /* MFD DQM ODPQ CS */ 
	#define BITFIELD_MFD_MFD_DQM_ODPQ_CS	 0x0b5c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_DQM_ODPQ_DATA_OFFSET	0xb60 /* MFD DQM ODPQ DATA OFFSE */ 
	#define BITFIELD_MFD_MFD_DQM_ODPQ_DATA_OFFSET	 0x0b60, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_DQM_ODPQ_CUSTOM_DATA	0xb64 /* MFD DQM ODPQ CUSTOM DAT */ 
	#define BITFIELD_MFD_MFD_DQM_ODPQ_CUSTOM_DATA	 0x0b64, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_DQM_ODPQ_RETURN	0xb68 /* MFD DQM ODPQ RETURN */ 
	#define BITFIELD_MFD_MFD_DQM_ODPQ_RETURN	 0x0b68, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_DQM_DSPLY_FREED_CNT_WTRMRK	0xb6c /* MFD DQM DSPLY FREED CNT WTRMRK */ 
	#define BITFIELD_MFD_MFD_DQM_DSPLY_FREED_CNT_WTRMRK	 0x0b6c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SMP_RD	0x1000 /* MFD H264 0 SMP RD */ 
	#define BITFIELD_MFD_MFD_H264_0_SMP_RD	 0x1000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_INT_EN_RD	0x1004 /* MFD H264 0 INT EN RD */ 
	#define BITFIELD_MFD_MFD_H264_0_INT_EN_RD	 0x1004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SMP_SET	0x1008 /* MFD H264 0 SMP SET */ 
	#define BITFIELD_MFD_MFD_H264_0_SMP_SET	 0x1008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SMP_CLR	0x100c /* MFD H264 0 SMP CLR */ 
	#define BITFIELD_MFD_MFD_H264_0_SMP_CLR	 0x100c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SMP_MSK_SET	0x1010 /* MFD H264 0 SMP MSK SET */ 
	#define BITFIELD_MFD_MFD_H264_0_SMP_MSK_SET	 0x1010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SMP_MSK_CLR	0x1014 /* MFD H264 0 SMP MSK CLR */ 
	#define BITFIELD_MFD_MFD_H264_0_SMP_MSK_CLR	 0x1014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_HDAT	0x1018 /* MFD H264 0 HDAT */ 
	#define BITFIELD_MFD_MFD_H264_0_HDAT	 0x1018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SDDAT	0x101c /* MFD H264 0 SDDAT */ 
	#define BITFIELD_MFD_MFD_H264_0_SDDAT	 0x101c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DQ_PUSH	0x1020 /* MFD H264 0 DQ PUSH */ 
	#define BITFIELD_MFD_MFD_H264_0_DQ_PUSH	 0x1020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DQ_STAT	0x1024 /* MFD H264 0 DQ STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_DQ_STAT	 0x1024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_INIT	0x1040 /* MFD H264 0 DPB INIT */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_INIT	 0x1040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_FRM_SZ_STAT	0x1044 /* MFD H264 0 DPB FRM SZ STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_FRM_SZ_STAT	 0x1044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_FRM_SZ_CTRL	0x1048 /* MFD H264 0 DPB FRM SZ CTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_FRM_SZ_CTRL	 0x1048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_NUMB_OVR	0x104c /* MFD H264 0 DPB NUMB OVR */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_NUMB_OVR	 0x104c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_FS_VALUES	0x1050 /* MFD H264 0 DPB FS VALUES */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_FS_VALUES	 0x1050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_FS_OFFSET	0x1054 /* MFD H264 0 DPB FS OFFSET */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_FS_OFFSET	 0x1054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_FSD	0x1058 /* MFD H264 0 FSD */ 
	#define BITFIELD_MFD_MFD_H264_0_FSD	 0x1058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DANGLING_FIELD	0x105c /* MFD H264 0 DANGLING FIELD */ 
	#define BITFIELD_MFD_MFD_H264_0_DANGLING_FIELD	 0x105c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DISP_TAG	0x1060 /* MFD H264 0 DISP TAG */ 
	#define BITFIELD_MFD_MFD_H264_0_DISP_TAG	 0x1060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_MBI_ADDR_LUT_WR	0x107c /* MFD H264 0 DPB MBI ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_MBI_ADDR_LUT_WR	 0x107c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_UV_ADDR_LUT_WR	0x1080 /* MFD H264 0 DPB UV ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_UV_ADDR_LUT_WR	 0x1080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DPB_Y_ADDR_LUT_WR	0x1084 /* MFD H264 0 DPB Y ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_H264_0_DPB_Y_ADDR_LUT_WR	 0x1084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_FRAME_CYC_COUNT	0x1090 /* MFD H264 0 FRAME CYC COUNT */ 
	#define BITFIELD_MFD_MFD_H264_0_FRAME_CYC_COUNT	 0x1090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_IB_WAIT_COUNT	0x1094 /* MFD H264 0 IB WAIT COUNT */ 
	#define BITFIELD_MFD_MFD_H264_0_IB_WAIT_COUNT	 0x1094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_RBSP_COUNT	0x1098 /* MFD H264 0 RBSP COUNT */ 
	#define BITFIELD_MFD_MFD_H264_0_RBSP_COUNT	 0x1098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_COUNT	0x109c /* MFD H264 0 MPR COUNT */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_COUNT	 0x109c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_CORE_CONFIG	0x10a0 /* MFD H264 0 CORE CONFIG */ 
	#define BITFIELD_MFD_MFD_H264_0_CORE_CONFIG	 0x10a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_INT_CTRL	0x10c0 /* MFD H264 0 INT CTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_INT_CTRL	 0x10c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_INT_STAT	0x10c4 /* MFD H264 0 INT STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_INT_STAT	 0x10c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SOFT_RST	0x10fc /* MFD H264 0 SOFT RST */ 
	#define BITFIELD_MFD_MFD_H264_0_SOFT_RST	 0x10fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_PSR_STAT	0x1100 /* MFD H264 0 BSD PSR STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_PSR_STAT	 0x1100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_STAT	0x1104 /* MFD H264 0 BSD STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_STAT	 0x1104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_RBSP_CTRL	0x1110 /* MFD H264 0 BSD RBSP CTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_RBSP_CTRL	 0x1110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_DATA	0x1114 /* MFD H264 0 BSD DATA */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_DATA	 0x1114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_NAL_TYPE	0x1118 /* MFD H264 0 BSD NAL TYPE */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_NAL_TYPE	 0x1118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_BBB_STAT	0x111c /* MFD H264 0 BSD BBB STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_BBB_STAT	 0x111c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GUE_DEC	0x1120 /* MFD_H264 0 BSD GUE DEC */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GUE_DEC	 0x1120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GSE_DEC	0x1124 /* MFD H264 0 BSD GSE DEC */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GSE_DEC	 0x1124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_EXP_GME_INTRA	0x1128 /* MFD H264 0 BSD EXP GME INTRA */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_EXP_GME_INTRA	 0x1128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_EXP_GME_INTER	0x1138 /* MFD H264 0 BSD EXP GME INTER */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_EXP_GME_INTER	 0x1138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_IMG_INIT	0x1140 /* MFD H264 0 BSD IMG INIT */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_IMG_INIT	 0x1140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_SLICE_P1	0x1150 /* MFD H264 0 BSD SLICE P1 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_SLICE_P1	 0x1150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_SLICE_P2	0x1154 /* MFD H264 0 BSD SLICE P2 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_SLICE_P2	 0x1154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_SLICE_START	0x1158 /* MFD H264 0 BSD SLICE START */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_SLICE_START	 0x1158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_MB_CTRL	0x115c /* MFD H264 0 BSD MB CTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_MB_CTRL	 0x115c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_QM_DEC_START	0x1160 /* MFD H264 0 BSD QM DEC START */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_QM_DEC_START	 0x1160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_DEC_STAT	0x1164 /* MFD H264 0 BSD DEC STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_DEC_STAT	 0x1164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_QM_LOAD_START	0x1168 /* MFD H264 0 BSD QM LOAD START */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_QM_LOAD_START	 0x1168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_QM_LOAD_VALUE	0x116c /* MFD H264 0 BSD QM LOAD VALUE */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_QM_LOAD_VALUE	 0x116c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_BYTE_ALIGN	0x117c /* MFD H264 0 BSD BYTE ALIGN */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_BYTE_ALIGN	 0x117c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_BBB_TRAIL	0x1180 /* MFD H264 0 BSD BBB TRAIL */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_BBB_TRAIL	 0x1180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS01	0x1184 /* MFD H264 0 BSD GET BITS01 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS01	 0x1184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS02	0x1188 /* MFD H264 0 BSD GET BITS02 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS02	 0x1188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS03	0x118c /* MFD H264 0 BSD GET BITS03 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS03	 0x118c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS04	0x1190 /* MFD H264 0 BSD GET BITS04 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS04	 0x1190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS05	0x1194 /* MFD H264 0 BSD GET BITS05 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS05	 0x1194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS06	0x1198 /* MFD H264 0 BSD GET BITS06 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS06	 0x1198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS07	0x119c /* MFD H264 0 BSD GET BITS07 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS07	 0x119c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS08	0x11a0 /* MFD H264 0 BSD GET BITS08 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS08	 0x11a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS09	0x11a4 /* MFD H264 0 BSD GET BITS09 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS09	 0x11a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS10	0x11a8 /* MFD H264 0 BSD GET BITS10 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS10	 0x11a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS11	0x11ac /* MFD H264 0 BSD GET BITS11 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS11	 0x11ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS12	0x11b0 /* MFD H264 0 BSD GET BITS12 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS12	 0x11b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS13	0x11b4 /* MFD H264 0 BSD GET BITS13 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS13	 0x11b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS14	0x11b8 /* MFD H264 0 BSD GET BITS14 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS14	 0x11b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS15	0x11bc /* MFD H264 0 BSD GET BITS15 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS15	 0x11bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS16	0x11c0 /* MFD H264 0 BSD GET BITS16 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS16	 0x11c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS17	0x11c4 /* MFD H264 0 BSD GET BITS17 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS17	 0x11c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS18	0x11c8 /* MFD H264 0 BSD GET BITS18 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS18	 0x11c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS19	0x11cc /* MFD H264 0 BSD GET BITS19 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS19	 0x11cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS20	0x11d0 /* MFD H264 0 BSD GET BITS20 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS20	 0x11d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS21	0x11d4 /* MFD H264 0 BSD GET BITS21 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS21	 0x11d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS22	0x11d8 /* MFD H264 0 BSD GET BITS22 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS22	 0x11d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS23	0x11dc /* MFD H264 0 BSD GET BITS23 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS23	 0x11dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS24	0x11e0 /* MFD H264 0 BSD GET BITS24 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS24	 0x11e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS25	0x11e4 /* MFD H264 0 BSD GET BITS25 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS25	 0x11e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS26	0x11e8 /* MFD H264 0 BSD GET BITS26 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS26	 0x11e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS27	0x11ec /* MFD H264 0 BSD GET BITS27 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS27	 0x11ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS28	0x11f0 /* MFD H264 0 BSD GET BITS28 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS28	 0x11f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS29	0x11f4 /* MFD H264 0 BSD GET BITS29 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS29	 0x11f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS30	0x11f8 /* MFD H264 0 BSD GET BITS30 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS30	 0x11f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_BSD_GET_BITS31	0x11fc /* MFD H264 0 BSD GET BITS31 */ 
	#define BITFIELD_MFD_MFD_H264_0_BSD_GET_BITS31	 0x11fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_TF_POC	0x1300 /* MFD H264 0 MPR TF POC */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_TF_POC	 0x1300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_BF_POC	0x1304 /* MFD H264 0 MPR BF POC */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_BF_POC	 0x1304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST00	0x1380 /* MFD H264 0 MPR LST00 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST00	 0x1380, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST01	0x1384 /* MFD H264 0 MPR LST01 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST01	 0x1384, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST02	0x1388 /* MFD H264 0 MPR LST02 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST02	 0x1388, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST03	0x138c /* MFD H264 0 MPR LST03 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST03	 0x138c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST04	0x1390 /* MFD H264 0 MPR LST04 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST04	 0x1390, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST05	0x1394 /* MFD H264 0 MPR LST05 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST05	 0x1394, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST06	0x1398 /* MFD H264 0 MPR LST06 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST06	 0x1398, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST07	0x139c /* MFD H264 0 MPR LST07 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST07	 0x139c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST08	0x13a0 /* MFD H264 0 MPR LST08 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST08	 0x13a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST09	0x13a4 /* MFD H264 0 MPR LST09 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST09	 0x13a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST10	0x13a8 /* MFD H264 0 MPR LST10 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST10	 0x13a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST11	0x13ac /* MFD H264 0 MPR LST11 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST11	 0x13ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST12	0x13b0 /* MFD H264 0 MPR LST12 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST12	 0x13b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST13	0x13b4 /* MFD H264 0 MPR LST13 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST13	 0x13b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST14	0x13b8 /* MFD H264 0 MPR LST14 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST14	 0x13b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_MPR_LST15	0x13bc /* MFD H264 0 MPR LST15 */ 
	#define BITFIELD_MFD_MFD_H264_0_MPR_LST15	 0x13bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_RSB_DDR_BA	0x1808 /* MFD H264 0 RSB DDR BA */ 
	#define BITFIELD_MFD_MFD_H264_0_RSB_DDR_BA	 0x1808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DEC_STATUS	0x180c /* MFD H264 0 DEC STATUS */ 
	#define BITFIELD_MFD_MFD_H264_0_DEC_STATUS	 0x180c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SIF_SMP_RS	0x1810 /* MFD H264 0 SIF SMP RS */ 
	#define BITFIELD_MFD_MFD_H264_0_SIF_SMP_RS	 0x1810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SIF_MSK_RS	0x1814 /* MFD H264 0 SIF MSK RS */ 
	#define BITFIELD_MFD_MFD_H264_0_SIF_MSK_RS	 0x1814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SIF_HDAT	0x1818 /* MFD H264 0 SIF HDAT */ 
	#define BITFIELD_MFD_MFD_H264_0_SIF_HDAT	 0x1818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SIF_SDDAT	0x181c /* MFD H264 0 SIF SDDAT */ 
	#define BITFIELD_MFD_MFD_H264_0_SIF_SDDAT	 0x181c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SIF_SMP_RC	0x1820 /* MFD H264 0 SIF SMP RC */ 
	#define BITFIELD_MFD_MFD_H264_0_SIF_SMP_RC	 0x1820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SIF_MSK_RC	0x1824 /* MFD H264 0 SIF MSK RC */ 
	#define BITFIELD_MFD_MFD_H264_0_SIF_MSK_RC	 0x1824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SED	0x1900 /* MFD H264 0 SED */ 
	#define BITFIELD_MFD_MFD_H264_0_SED	 0x1900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SDEMC	0x1904 /* MFD H264 0 SDEMC */ 
	#define BITFIELD_MFD_MFD_H264_0_SDEMC	 0x1904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_CB_BASE	0x1908 /* MFD H264 0 DMA CB BASE */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_CB_BASE	 0x1908, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SB_RDPTR	0x190c /* MFD H264 0 DMA SB RDPTR */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SB_RDPTR	 0x190c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_CB_SIZE	0x1910 /* MFD H264 0 DMA CB SIZE */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_CB_SIZE	 0x1910, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_WTRMARK	0x1914 /* MFD H264 0 DMA WTRMARK */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_WTRMARK	 0x1914, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_WDT	0x1918 /* MFD H264 0 DMA WDT */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_WDT	 0x1918, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_CB_RDPTR	0x191c /* MFD H264 0 DMA CB RDPTR */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_CB_RDPTR	 0x191c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_CB_WRPTR	0x1920 /* MFD H264 0 DMA CB WRPTR */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_CB_WRPTR	 0x1920, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SDLINK	0x1924 /* MFD H264 0 DMA SDLINK */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SDLINK	 0x1924, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SDLLSA	0x1928 /* MFD H264 0 DMA SDLLSA */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SDLLSA	 0x1928, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SDLNDA	0x192c /* MFD H264 0 DMA SDLNDA */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SDLNDA	 0x192c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SDLDBC	0x1930 /* MFD H264 0 DMA SDLDBC */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SDLDBC	 0x1930, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SDLCBC	0x1934 /* MFD H264 0 DMA SDLCBC */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SDLCBC	 0x1934, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_SDLDC	0x1938 /* MFD H264 0 DMA SDLDC */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_SDLDC	 0x1938, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_FIFO	0x193c /* MFD H264 0 DMA FIFO */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_FIFO	 0x193c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_FIFO_STAT	0x1940 /* MFD H264 0 DMA FIFO STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_FIFO_STAT	 0x1940, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_INT_EN	0x1944 /* MFD H264 0 DMA INT EN */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_INT_EN	 0x1944, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_INT_STAT	0x1948 /* MFD H264 0 DMA INT STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_INT_STAT	 0x1948, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_DMA_BS_CNTR	0x194c /* MFD H264 0 DMA BS CNTR */ 
	#define BITFIELD_MFD_MFD_H264_0_DMA_BS_CNTR	 0x194c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_XCR	0x1a00 /* MFD H264 0 SCD XCR */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_XCR	 0x1a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_XSCR1	0x1a04 /* MFD H264 0 SCD XSCR1 */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_XSCR1	 0x1a04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_XSCR2	0x1a08 /* MFD H264 0 SCD XSCR2 */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_XSCR2	 0x1a08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_FWPREAD	0x1a0c /* MFD H264 0 SCD FWPREAD */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_FWPREAD	 0x1a0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_FWCRTL	0x1a10 /* MFD H264 0 SCD FWCRTL */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_FWCRTL	 0x1a10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_FWSTAT	0x1a14 /* MFD H264 0 SCD FWSTAT */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_FWSTAT	 0x1a14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_WRCTRL	0x1a18 /* MFD H264 0 SCD WRCTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_WRCTRL	 0x1a18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_SCD_WRDATA	0x1a1c /* MFD H264 0 SCD WRDATA */ 
	#define BITFIELD_MFD_MFD_H264_0_SCD_WRDATA	 0x1a1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_CTRL	0x1b00 /* MFD H264 0 PIP CTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_CTRL	 0x1b00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_STAT	0x1b04 /* MFD H264 0 PIP STAT */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_STAT	 0x1b04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_CDYB	0x1b08 /* MFD H264 0 PIP CDYB */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_CDYB	 0x1b08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_CDUB	0x1b0c /* MFD H264 0 PIP CDUB */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_CDUB	 0x1b0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_TST_CTRL	0x1b10 /* MFD H264 0 PIP TST CTRL */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_TST_CTRL	 0x1b10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_TST_WR_DATA_LO	0x1b14 /* MFD H264 0 PIP TST WR DATA LO */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_TST_WR_DATA_LO	 0x1b14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_0_PIP_TST_WR_DATA_HI	0x1b18 /* MFD H264 0 PIP TST WR DATA HI */ 
	#define BITFIELD_MFD_MFD_H264_0_PIP_TST_WR_DATA_HI	 0x1b18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SMP_RD	0x2000 /* MFD VC1 0 SMP RD */ 
	#define BITFIELD_MFD_MFD_VC1_0_SMP_RD	 0x2000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_INT_EN_RD	0x2004 /* MFD VC1 0 INT EN RD */ 
	#define BITFIELD_MFD_MFD_VC1_0_INT_EN_RD	 0x2004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SMP_SET	0x2008 /* MFD VC1 0 SMP SET */ 
	#define BITFIELD_MFD_MFD_VC1_0_SMP_SET	 0x2008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SMP_CLR	0x200c /* MFD VC1 0 SMP CLR */ 
	#define BITFIELD_MFD_MFD_VC1_0_SMP_CLR	 0x200c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SMP_MSK_SET	0x2010 /* MFD VC1 0 SMP MSK SET */ 
	#define BITFIELD_MFD_MFD_VC1_0_SMP_MSK_SET	 0x2010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SMP_MSK_CLR	0x2014 /* MFD VC1 0 SMP MSK CLR */ 
	#define BITFIELD_MFD_MFD_VC1_0_SMP_MSK_CLR	 0x2014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_HDAT	0x2018 /* MFD VC1 0 HDAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_HDAT	 0x2018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SDDAT	0x201c /* MFD VC1 0 SDDAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_SDDAT	 0x201c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DQ_PUSH	0x2020 /* MFD VC1 0 DQ PUSH */ 
	#define BITFIELD_MFD_MFD_VC1_0_DQ_PUSH	 0x2020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DQ_STAT	0x2024 /* MFD VC1 0 DQ STAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_DQ_STAT	 0x2024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_INIT	0x2040 /* MFD VC1 0 DPB INIT */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_INIT	 0x2040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_FRM_SZ_STAT	0x2044 /* MFD VC1 0 DPB FRM SZ STAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_FRM_SZ_STAT	 0x2044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_FRM_SZ_CTRL	0x2048 /* MFD VC1 0 DPB FRM SZ CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_FRM_SZ_CTRL	 0x2048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_NUMB_OVR	0x204c /* MFD VC1 0 DPB NUMB_OVR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_NUMB_OVR	 0x204c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_FS_SETTING	0x2050 /* MFD VC1 0 DPB FS SETTING */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_FS_SETTING	 0x2050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_LOAD_OFFSET	0x2054 /* MFD VC1 0 DPB LOAD OFFSET */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_LOAD_OFFSET	 0x2054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_FSD	0x2058 /* MFD VC1 0 FSD */ 
	#define BITFIELD_MFD_MFD_VC1_0_FSD	 0x2058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DANGLING_FIELD	0x205c /* MFD VC1 0 DANGLING FIELD */ 
	#define BITFIELD_MFD_MFD_VC1_0_DANGLING_FIELD	 0x205c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DISP_TAG	0x2060 /* MFD VC1 0 DISP TAG */ 
	#define BITFIELD_MFD_MFD_VC1_0_DISP_TAG	 0x2060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_UV_ADDR_LUT_WR	0x2080 /* MFD VC1 0 DPB UV ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_UV_ADDR_LUT_WR	 0x2080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DPB_Y_ADDR_LUT_WR	0x2084 /* MFD VC1 0 DPB Y ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DPB_Y_ADDR_LUT_WR	 0x2084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MPS_RD_BYTE_COUNT	0x2088 /* MFD VC1 0 MPS RD BYTE COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_0_MPS_RD_BYTE_COUNT	 0x2088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SLC_IN_FRM_COUNT	0x208c /* MFD VC1 0 SLC IN FRM COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_0_SLC_IN_FRM_COUNT	 0x208c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_FRAME_CYC_COUNT	0x2090 /* MFD VC1 0 FRAME CYC COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_0_FRAME_CYC_COUNT	 0x2090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_IB_WAIT_COUNT	0x2094 /* MFD VC1 0 IB WAIT COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_0_IB_WAIT_COUNT	 0x2094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_RBSP_COUNT	0x2098 /* MFD VC1 0 RBSP COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_0_RBSP_COUNT	 0x2098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BS2RBSP_STATUS	0x209c /* MFD VC1 0 BS2RBSP STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_0_BS2RBSP_STATUS	 0x209c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_CORE_CONFIG	0x20a0 /* MFD VC1 0 CORE CONFIG */ 
	#define BITFIELD_MFD_MFD_VC1_0_CORE_CONFIG	 0x20a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_RBSP_CTRL	0x20a4 /* MFD VC1 0 RBSP CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_RBSP_CTRL	 0x20a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_INT_CTRL	0x20c0 /* MFD VC1 0 INT CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_INT_CTRL	 0x20c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_INT_STAT	0x20c4 /* MFD VC1 0 INT STAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_INT_STAT	 0x20c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SOFT_RST	0x20c8 /* MFD VC1 0 SOFT RST */ 
	#define BITFIELD_MFD_MFD_VC1_0_SOFT_RST	 0x20c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_BYTE_ALIGN	0x2100 /* MFD VC1 0 BSP BYTE ALIGN */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_BYTE_ALIGN	 0x2100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS01	0x2104 /* MFD VC1 0 BSP GET BITS01 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS01	 0x2104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS02	0x2108 /* MFD VC1 0 BSP GET BITS02 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS02	 0x2108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS03	0x210c /* MFD VC1 0 BSP GET BITS03 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS03	 0x210c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS04	0x2110 /* MFD VC1 0 BSP GET BITS04 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS04	 0x2110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS05	0x2114 /* MFD VC1 0 BSP GET BITS05 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS05	 0x2114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS06	0x2118 /* MFD VC1 0 BSP GET BITS06 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS06	 0x2118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS07	0x211c /* MFD VC1 0 BSP GET BITS07 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS07	 0x211c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS08	0x2120 /* MFD VC1 0 BSP GET BITS08 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS08	 0x2120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS09	0x2124 /* MFD VC1 0 BSP GET BITS09 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS09	 0x2124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS10	0x2128 /* MFD VC1 0 BSP GET BITS10 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS10	 0x2128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS11	0x212c /* MFD VC1 0 BSP GET BITS11 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS11	 0x212c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS12	0x2130 /* MFD VC1 0 BSP GET BITS12 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS12	 0x2130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS13	0x2134 /* MFD VC1 0 BSP GET BITS13 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS13	 0x2134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS14	0x2138 /* MFD VC1 0 BSP GET BITS14 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS14	 0x2138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS15	0x213c /* MFD VC1 0 BSP GET BITS15 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS15	 0x213c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS16	0x2140 /* MFD VC1 0 BSP GET BITS16 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS16	 0x2140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS17	0x2144 /* MFD VC1 0 BSP GET BITS17 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS17	 0x2144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS18	0x2148 /* MFD VC1 0 BSP GET BITS18 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS18	 0x2148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS19	0x214c /* MFD VC1 0 BSP GET BITS19 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS19	 0x214c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS20	0x2150 /* MFD VC1 0 BSP GET BITS20 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS20	 0x2150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS21	0x2154 /* MFD VC1 0 BSP GET BITS21 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS21	 0x2154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS22	0x2158 /* MFD VC1 0 BSP GET BITS22 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS22	 0x2158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS23	0x215c /* MFD VC1 0 BSP GET BITS23 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS23	 0x215c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS24	0x2160 /* MFD VC1 0 BSP GET BITS24 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS24	 0x2160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS25	0x2164 /* MFD VC1 0 BSP GET BITS25 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS25	 0x2164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS26	0x2168 /* MFD VC1 0 BSP GET BITS26 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS26	 0x2168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS27	0x216c /* MFD VC1 0 BSP GET BITS27 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS27	 0x216c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS28	0x2170 /* MFD VC1 0 BSP GET BITS28 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS28	 0x2170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS29	0x2174 /* MFD VC1 0 BSP GET BITS29 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS29	 0x2174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS30	0x2178 /* MFD VC1 0 BSP GET BITS30 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS30	 0x2178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_GET_BITS31	0x217c /* MFD VC1 0 BSP GET BITS31 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_GET_BITS31	 0x217c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_STATUS	0x2180 /* MFD VC1 0 BSP STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_STATUS	 0x2180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_CTRL	0x2184 /* MFD VC1 0 BSP CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_CTRL	 0x2184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_SHOW_BITS	0x2188 /* MFD VC1 0 BSP SHOW BITS */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_SHOW_BITS	 0x2188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_SHOW_BITS_FLPD	0x218c /* MFD VC1 0 BSP SHOW BITS FLPD */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_SHOW_BITS_FLPD	 0x218c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_IGNORE_BBB_LEVEL	0x2190 /* MFD VC1 0 BSP IGNORE BBB LEVEL */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_IGNORE_BBB_LEVEL	 0x2190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_PTYPE	0x21c0 /* MFD VC1 0 BSP HEADER VLC PTYPE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_PTYPE	 0x21c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_FTYPE	0x21c4 /* MFD VC1 0 BSP HEADER VLC FTYPE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_FTYPE	 0x21c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_MVRANGE	0x21c8 /* MFD VC1 0 BSP HEADER VLC MVRANGE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_MVRANGE	 0x21c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_MVMODE	0x21cc /* MFD VC1 0 BSP HEADER VLC MVMODE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_MVMODE	 0x21cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_MVMODE2	0x21d0 /* MFD VC1 0 BSP HEADER VLC MVMODE2 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_MVMODE2	 0x21d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_DMVRANGE	0x21d4 /* MFD VC1 0 BSP HEADER VLC DMVRANGE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_DMVRANGE	 0x21d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_BPPMODE	0x21d8 /* MFD VC1 0 BSP HEADER VLC BPPMODE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_BPPMODE	 0x21d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_BPPVLC2	0x21dc /* MFD VC1 0 BSP HEADER VLC BPPVLC2 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_BPPVLC2	 0x21dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_BPPVLC6	0x21e0 /* MFD VC1 0 BSP HEADER VLC BPPVLC6 */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_BPPVLC6	 0x21e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_BFRACT	0x21e4 /* MFD VC1 0 BSP HEADER VLC BFRACT */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_BFRACT	 0x21e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BSP_HEADER_VLC_REFDIST	0x21e8 /* MFD VC1 0 BSP HEADER VLC REFDIST */ 
	#define BITFIELD_MFD_MFD_VC1_0_BSP_HEADER_VLC_REFDIST	 0x21e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_GENERAL_CORE_CONFIG	0x2200 /* MFD VC1 0 SEQPIC GENERAL CORE CONFIG */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_GENERAL_CORE_CONFIG	 0x2200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_STREAM_FORMAT_1	0x2204 /* MFD VC1 0 SEQPIC STREAM FORMAT 1 */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_STREAM_FORMAT_1	 0x2204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_CODED_SIZE	0x2208 /* MFD VC1 0 SEQPIC CODED SIZE */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_CODED_SIZE	 0x2208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_STREAM_FORMAT_2	0x220c /* MFD VC1 0 SEQPIC STREAM FORMAT 2 */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_STREAM_FORMAT_2	 0x220c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_ENTRY_POINT_1	0x2210 /* MFD VC1 0 SEQPIC ENTRY POINT 1 */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_ENTRY_POINT_1	 0x2210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_RANGE_MAP	0x2214 /* MFD VC1 0 SEQPIC RANGE MAP */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_RANGE_MAP	 0x2214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_FRAME_TYPE	0x2218 /* MFD VC1 0 SEQPIC FRAME TYPE */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_FRAME_TYPE	 0x2218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_RECON_CONTROL	0x221c /* MFD VC1 0 SEQPIC RECON CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_RECON_CONTROL	 0x221c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_MOTION_VECTOR_CONTROL	0x2220 /* MFD VC1 0 SEQPIC MOTION VECTOR CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_MOTION_VECTOR_CONTROL	 0x2220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_INTENSITY_COMPENSATION	0x2224 /* MFD VC1 0 SEQPIC INTENSITY COMPENSATION */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_INTENSITY_COMPENSATION	 0x2224, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_REFERENCE_B_FRACTION	0x2228 /* MFD VC1 0 SEQPIC REFERENCE B FRACTION */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_REFERENCE_B_FRACTION	 0x2228, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_BLOCK_CONTROL	0x222c /* MFD VC1 0 SEQPIC BLOCK CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_BLOCK_CONTROL	 0x222c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_TRANSFORM_DATA	0x2230 /* MFD VC1 0 SEQPIC TRANSFORM DATA */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_TRANSFORM_DATA	 0x2230, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_VOP_DEQUANT	0x2234 /* MFD VC1 0 SEQPIC VOP DEQUANT */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_VOP_DEQUANT	 0x2234, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_CURR_FRAME_ID	0x2238 /* MFD VC1 0 SEQPIC CURR FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_CURR_FRAME_ID	 0x2238, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_CURR_DISPLAY_ID	0x223c /* MFD VC1 0 SEQPIC CURR DISPLAY ID */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_CURR_DISPLAY_ID	 0x223c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_FWD_REF_FRAME_ID	0x2240 /* MFD VC1 0 SEQPIC FWD REF FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_FWD_REF_FRAME_ID	 0x2240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_BWD_REF_FRAME_ID	0x2244 /* MFD VC1 0 SEQPIC BWD REF FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_BWD_REF_FRAME_ID	 0x2244, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_FIELD_REF_FRAME_ID	0x2248 /* MFD VC1 0 SEQPIC FIELD REF FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_FIELD_REF_FRAME_ID	 0x2248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_AUX_FRAME_CONTROL	0x224c /* MFD VC1 0 SEQPIC AUX FRAME CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_AUX_FRAME_CONTROL	 0x224c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_IMAGE_STRUCTURE	0x2250 /* MFD VC1 0 SEQPIC IMAGE STRUCTURE */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_IMAGE_STRUCTURE	 0x2250, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SEQPIC_ALT_FRAME_TYPE	0x2254 /* MFD VC1 0 SEQPIC ALT FRAME TYPE */ 
	#define BITFIELD_MFD_MFD_VC1_0_SEQPIC_ALT_FRAME_TYPE	 0x2254, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_STATUS	0x2300 /* MFD VC1 0 MBDEC STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_STATUS	 0x2300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_FRAME_START	0x2304 /* MFD VC1 0 MBDEC FRAME START */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_FRAME_START	 0x2304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_FW_DEBUG	0x2308 /* MFD VC1 0 MBDEC FW DEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_FW_DEBUG	 0x2308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_MBQDEBUG	0x230c /* MFD VC1 0 MBDEC MBQDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_MBQDEBUG	 0x230c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_MPRDEBUG	0x2310 /* MFD VC1 0 MBDEC MPRDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_MPRDEBUG	 0x2310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_MASDEBUG	0x2314 /* MFD VC1 0 MBDEC MASDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_MASDEBUG	 0x2314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_BPPDEBUG	0x2318 /* MFD VC1 0 MBDEC BPPDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_BPPDEBUG	 0x2318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_DPBMCDEBUG	0x231c /* MFD VC1 0 MBDEC DPBMCDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_DPBMCDEBUG	 0x231c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_GENDEBUG	0x2320 /* MFD VC1 0 MBDEC GENDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_GENDEBUG	 0x2320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_FW_DEBUG	0x2324 /* MFD VC1 0 FW DEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_0_FW_DEBUG	 0x2324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBDEC_ERROR_CONCEAL_CONTROL	0x2340 /* MFD VC1 0 MBDEC ERROR CONCEAL CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBDEC_ERROR_CONCEAL_CONTROL	 0x2340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BP_CONTROL_STATUS	0x2400 /* MFD VC1 0 BP CONTROL STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_0_BP_CONTROL_STATUS	 0x2400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BP_DATA_IN_STATUS	0x2404 /* MFD VC1 0 BP DATA IN STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_0_BP_DATA_IN_STATUS	 0x2404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BP_DATA_IN_VALUE	0x2408 /* MFD VC1 0 BP DATA IN VALUE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BP_DATA_IN_VALUE	 0x2408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_BP_DATA_IN_POSITION_N_SIZE	0x240c /* MFD VC1 0 BP DATA IN POSITION N SIZE */ 
	#define BITFIELD_MFD_MFD_VC1_0_BP_DATA_IN_POSITION_N_SIZE	 0x240c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_MBA_ENABLE	0x2800 /* MFD VC1 0 MBA ENABLE */ 
	#define BITFIELD_MFD_MFD_VC1_0_MBA_ENABLE	 0x2800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_RSB_DDR_BA	0x2808 /* MFD VC1 0 RSB DDR BA */ 
	#define BITFIELD_MFD_MFD_VC1_0_RSB_DDR_BA	 0x2808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DEC_STATUS	0x280c /* MFD VC1 0 DEC STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_0_DEC_STATUS	 0x280c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SIF_SMP_RS	0x2810 /* MFD VC1 0 SIF SMP RS */ 
	#define BITFIELD_MFD_MFD_VC1_0_SIF_SMP_RS	 0x2810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SIF_MSK_RS	0x2814 /* MFD VC1 0 SIF MSK RS */ 
	#define BITFIELD_MFD_MFD_VC1_0_SIF_MSK_RS	 0x2814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SIF_HDAT	0x2818 /* MFD VC1 0 SIF HDAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_SIF_HDAT	 0x2818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SIF_SDDAT	0x281c /* MFD VC1 0 SIF SDDAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_SIF_SDDAT	 0x281c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SIF_SMP_RC	0x2820 /* MFD VC1 0 SIF SMP RC */ 
	#define BITFIELD_MFD_MFD_VC1_0_SIF_SMP_RC	 0x2820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SIF_MSK_RC	0x2824 /* MFD VC1 0 SIF MSK RC */ 
	#define BITFIELD_MFD_MFD_VC1_0_SIF_MSK_RC	 0x2824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SED	0x2900 /* MFD VC1 0 SED */ 
	#define BITFIELD_MFD_MFD_VC1_0_SED	 0x2900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SDEMC	0x2904 /* MFD VC1 0 SDEMC */ 
	#define BITFIELD_MFD_MFD_VC1_0_SDEMC	 0x2904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_CB_BASE	0x2908 /* MFD VC1 0 DMA CB BASE */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_CB_BASE	 0x2908, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SB_RDPTR	0x290c /* MFD VC1 0 DMA SB RDPTR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SB_RDPTR	 0x290c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_CB_SIZE	0x2910 /* MFD VC1 0 DMA CB SIZE */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_CB_SIZE	 0x2910, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_WTRMARK	0x2914 /* MFD VC1 0 DMA WTRMARK */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_WTRMARK	 0x2914, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_WDT	0x2918 /* MFD VC1 0 DMA WDT */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_WDT	 0x2918, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_CB_RDPTR	0x291c /* MFD VC1 0 DMA CB RDPTR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_CB_RDPTR	 0x291c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_CB_WRPTR	0x2920 /* MFD VC1 0 DMA CB WRPTR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_CB_WRPTR	 0x2920, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SDLINK	0x2924 /* MFD VC1 0 DMA SDLINK */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SDLINK	 0x2924, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SDLLSA	0x2928 /* MFD VC1 0 DMA SDLLSA */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SDLLSA	 0x2928, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SDLNDA	0x292c /* MFD VC1 0 DMA SDLNDA */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SDLNDA	 0x292c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SDLDBC	0x2930 /* MFD VC1 0 DMA SDLDBC */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SDLDBC	 0x2930, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SDLCBC	0x2934 /* MFD VC1 0 DMA SDLCBC */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SDLCBC	 0x2934, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_SDLDC	0x2938 /* MFD VC1 0 DMA SDLDC */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_SDLDC	 0x2938, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_FIFO	0x293c /* MFD VC1 0 DMA FIFO */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_FIFO	 0x293c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_FIFO_STAT	0x2940 /* MFD VC1 0 DMA FIFO STAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_FIFO_STAT	 0x2940, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_INT_EN	0x2944 /* MFD VC1 0 DMA INT EN */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_INT_EN	 0x2944, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_INT_STAT	0x2948 /* MFD VC1 0 DMA INT STAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_INT_STAT	 0x2948, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_DMA_BS_CNTR	0x294c /* MFD VC1 0 DMA BS CNTR */ 
	#define BITFIELD_MFD_MFD_VC1_0_DMA_BS_CNTR	 0x294c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_XCR	0x2a00 /* MFD VC1 0 SCD XCR */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_XCR	 0x2a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_XSCR1	0x2a04 /* MFD VC1 0 SCD XSCR1 */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_XSCR1	 0x2a04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_XSCR2	0x2a08 /* MFD VC1 0 SCD XSCR2 */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_XSCR2	 0x2a08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_FWPREAD	0x2a0c /* MFD VC1 0 SCD FWPREAD */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_FWPREAD	 0x2a0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_FWCRTL	0x2a10 /* MFD VC1 0 SCD FWCRTL */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_FWCRTL	 0x2a10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_FWSTAT	0x2a14 /* MFD VC1 0 SCD FWSTAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_FWSTAT	 0x2a14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_WRCTRL	0x2a18 /* MFD VC1 0 SCD WRCTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_WRCTRL	 0x2a18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_SCD_WRDATA	0x2a1c /* MFD VC1 0 SCD WRDATA */ 
	#define BITFIELD_MFD_MFD_VC1_0_SCD_WRDATA	 0x2a1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_CTRL	0x2b00 /* MFD VC1 0 PIP CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_CTRL	 0x2b00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_STAT	0x2b04 /* MFD VC1 0 PIP STAT */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_STAT	 0x2b04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_CDYB	0x2b08 /* MFD VC1 0 PIP CDYB */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_CDYB	 0x2b08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_CDUB	0x2b0c /* MFD VC1 0 PIP CDUB */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_CDUB	 0x2b0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_TST_CTRL	0x2b10 /* MFD VC1 0 PIP TST CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_TST_CTRL	 0x2b10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_TST_WR_DATA_LO	0x2b14 /* MFD VC1 0 PIP TST WR DATA LO */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_TST_WR_DATA_LO	 0x2b14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_0_PIP_TST_WR_DATA_HI	0x2b18 /* MFD VC1 0 PIP TST WR DATA HI */ 
	#define BITFIELD_MFD_MFD_VC1_0_PIP_TST_WR_DATA_HI	 0x2b18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SAS	0x3000 /* MFD MPG2VD SAS */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SAS	 0x3000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_IM	0x3004 /* MFD MPG2VD IM */ 
	#define BITFIELD_MFD_MFD_MPG2VD_IM	 0x3004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_IS	0x3008 /* MFD MPG2VD IS */ 
	#define BITFIELD_MFD_MFD_MPG2VD_IS	 0x3008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DCC	0x300c /* MFD MPG2VD DCC */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DCC	 0x300c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DCSI1	0x3010 /* MFD MPG2VD DCSI1 */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DCSI1	 0x3010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DCSI2	0x3014 /* MFD MPG2VD DCSI2 */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DCSI2	 0x3014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DCPI1	0x3018 /* MFD MPG2VD DCPI1 */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DCPI1	 0x3018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DCGH	0x301c /* MFD MPG2VD DCGH */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DCGH	 0x301c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PPE	0x3020 /* MFD MPG2VD PPE */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PPE	 0x3020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_QMA	0x3024 /* MFD MPG2VD QMA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_QMA	 0x3024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_QMD	0x3028 /* MFD MPG2VD QMD */ 
	#define BITFIELD_MFD_MFD_MPG2VD_QMD	 0x3028, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_CDYB	0x302c /* MFD MPG2VD CDYB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_CDYB	 0x302c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_CDUB	0x3030 /* MFD MPG2VD CDUB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_CDUB	 0x3030, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_BRYB	0x3034 /* MFD MPG2VD BRYB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_BRYB	 0x3034, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_BRUB	0x3038 /* MFD MPG2VD BRUB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_BRUB	 0x3038, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_FRYB	0x303c /* MFD MPG2VD FRYB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_FRYB	 0x303c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_FRUB	0x3040 /* MFD MPG2VD FRUB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_FRUB	 0x3040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_STAT	0x3044 /* MFD MPG2VD STAT */ 
	#define BITFIELD_MFD_MFD_MPG2VD_STAT	 0x3044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_CTRL	0x3400 /* MFD MPG2VD DBF CTRL */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_CTRL	 0x3400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_YDDA	0x3404 /* MFD MPG2VD DBF YDDA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_YDDA	 0x3404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_CDDA	0x3408 /* MFD MPG2VD DBF CDDA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_CDDA	 0x3408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_QSMF	0x340c /* MFD MPG2VD DBF QSMF */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_QSMF	 0x340c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_IFSV	0x3410 /* MFD MPG2VD DBF IFSV */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_IFSV	 0x3410, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_PFSV	0x3414 /* MFD MPG2VD DBF PFSV */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_PFSV	 0x3414, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DBF_BFSV	0x3418 /* MFD MPG2VD DBF BFSV */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DBF_BFSV	 0x3418, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DEC_STATUS	0x3824 /* MFD MPG2VD DEC STATUS */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DEC_STATUS	 0x3824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SED	0x3900 /* MFD MPG2VD SED */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SED	 0x3900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SDEMC	0x3904 /* MFD MPG2VD SDEMC */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SDEMC	 0x3904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_CB_BASE	0x3908 /* MFD MPG2VD DMA CB BASE */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_CB_BASE	 0x3908, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SB_RDPTR	0x390c /* MFD MPG2VD DMA SB RDPTR */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SB_RDPTR	 0x390c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_CB_SIZE	0x3910 /* MFD MPG2VD DMA CB SIZE */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_CB_SIZE	 0x3910, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_WTRMARK	0x3914 /* MFD MPG2VD DMA WTRMARK */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_WTRMARK	 0x3914, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_WDT	0x3918 /* MFD MPG2VD DMA WDT */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_WDT	 0x3918, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_CB_RDPTR	0x391c /* MFD MPG2VD DMA CB RDPTR */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_CB_RDPTR	 0x391c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_CB_WRPTR	0x3920 /* MFD MPG2VD DMA CB WRPTR */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_CB_WRPTR	 0x3920, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SDLINK	0x3924 /* MFD MPG2VD DMA SDLINK */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SDLINK	 0x3924, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SDLLSA	0x3928 /* MFD MPG2VD DMA SDLLSA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SDLLSA	 0x3928, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SDLNDA	0x392c /* MFD MPG2VD DMA SDLNDA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SDLNDA	 0x392c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SDLDBC	0x3930 /* MFD MPG2VD DMA SDLDBC */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SDLDBC	 0x3930, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SDLCBC	0x3934 /* MFD MPG2VD DMA SDLCBC */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SDLCBC	 0x3934, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_SDLDC	0x3938 /* MFD MPG2VD DMA SDLDC */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_SDLDC	 0x3938, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_FIFO	0x393c /* MFD MPG2VD DMA FIFO */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_FIFO	 0x393c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_FIFO_STAT	0x3940 /* MFD MPG2VD DMA FIFO STAT */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_FIFO_STAT	 0x3940, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_INT_EN	0x3944 /* MFD MPG2VD DMA INT EN */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_INT_EN	 0x3944, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_INT_STAT	0x3948 /* MFD MPG2VD DMA INT STAT */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_INT_STAT	 0x3948, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_DMA_BS_CNTR	0x394c /* MFD MPG2VD DMA BS CNTR */ 
	#define BITFIELD_MFD_MFD_MPG2VD_DMA_BS_CNTR	 0x394c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_XCR	0x3a00 /* MFD MPG2VD SCD XCR */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_XCR	 0x3a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_XSCR1	0x3a04 /* MFD MPG2VD SCD XSCR1 */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_XSCR1	 0x3a04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_XSCR2	0x3a08 /* MFD MPG2VD SCD XSCR2 */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_XSCR2	 0x3a08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_FWPREA	0x3a0c /* MFD MPG2VD SCD FWPREA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_FWPREA	 0x3a0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_FWCRTL	0x3a10 /* MFD MPG2VD SCD FWCRTL */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_FWCRTL	 0x3a10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_FWSTAT	0x3a14 /* MFD MPG2VD SCD FWSTAT */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_FWSTAT	 0x3a14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_WRCTRL	0x3a18 /* MFD MPG2VD SCD WRCTRL */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_WRCTRL	 0x3a18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_SCD_WRDATA	0x3a1c /* MFD MPG2VD SCD WRDATA */ 
	#define BITFIELD_MFD_MFD_MPG2VD_SCD_WRDATA	 0x3a1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_CTRL	0x3b00 /* MFD MPG2VD PIP CTRL */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_CTRL	 0x3b00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_STAT	0x3b04 /* MFD MPG2VD PIP STAT */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_STAT	 0x3b04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_CDYB	0x3b08 /* MFD MPG2VD PIP CDYB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_CDYB	 0x3b08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_CDUB	0x3b0c /* MFD MPG2VD PIP CDUB */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_CDUB	 0x3b0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_TST_CTRL	0x3b10 /* MFD MPG2VD PIP TST CTRL */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_TST_CTRL	 0x3b10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_TST_WR_DATA_LO	0x3b14 /* MFD MPG2VD PIP TST WR DATA LO */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_TST_WR_DATA_LO	 0x3b14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_MPG2VD_PIP_TST_WR_DATA_HI	0x3b18 /* MFD MPG2VD PIP TST WR DATA HI */ 
	#define BITFIELD_MFD_MFD_MPG2VD_PIP_TST_WR_DATA_HI	 0x3b18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SMP_RD	0x4000 /* MFD H264 1 SMP RD */ 
	#define BITFIELD_MFD_MFD_H264_1_SMP_RD	 0x4000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_INT_EN_RD	0x4004 /* MFD H264 1 INT EN RD */ 
	#define BITFIELD_MFD_MFD_H264_1_INT_EN_RD	 0x4004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SMP_SET	0x4008 /* MFD H264 1 SMP SET */ 
	#define BITFIELD_MFD_MFD_H264_1_SMP_SET	 0x4008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SMP_CLR	0x400c /* MFD H264 1 SMP CLR */ 
	#define BITFIELD_MFD_MFD_H264_1_SMP_CLR	 0x400c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SMP_MSK_SET	0x4010 /* MFD H264 1 SMP MSK SET */ 
	#define BITFIELD_MFD_MFD_H264_1_SMP_MSK_SET	 0x4010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SMP_MSK_CLR	0x4014 /* MFD H264 1 SMP MSK CLR */ 
	#define BITFIELD_MFD_MFD_H264_1_SMP_MSK_CLR	 0x4014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_HDAT	0x4018 /* MFD H264 1 HDAT */ 
	#define BITFIELD_MFD_MFD_H264_1_HDAT	 0x4018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SDDAT	0x401c /* MFD H264 1 SDDAT */ 
	#define BITFIELD_MFD_MFD_H264_1_SDDAT	 0x401c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DQ_PUSH	0x4020 /* MFD H264 1 DQ PUSH */ 
	#define BITFIELD_MFD_MFD_H264_1_DQ_PUSH	 0x4020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DQ_STAT	0x4024 /* MFD H264 1 DQ STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_DQ_STAT	 0x4024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_INIT	0x4040 /* MFD H264 1 DPB INIT */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_INIT	 0x4040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_FRM_SZ_STAT	0x4044 /* MFD H264 1 DPB FRM SZ STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_FRM_SZ_STAT	 0x4044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_FRM_SZ_CTRL	0x4048 /* MFD H264 1 DPB FRM SZ CTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_FRM_SZ_CTRL	 0x4048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_NUMB_OVR	0x404c /* MFD H264 1 DPB NUMB OVR */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_NUMB_OVR	 0x404c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_FS_VALUES	0x4050 /* MFD H264 1 DPB FS VALUES */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_FS_VALUES	 0x4050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_FS_OFFSET	0x4054 /* MFD H264 1 DPB FS OFFSET */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_FS_OFFSET	 0x4054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_FSD	0x4058 /* MFD H264 1 FSD */ 
	#define BITFIELD_MFD_MFD_H264_1_FSD	 0x4058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DANGLING_FIELD	0x405c /* MFD H264 1 DANGLING FIELD */ 
	#define BITFIELD_MFD_MFD_H264_1_DANGLING_FIELD	 0x405c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DISP_TAG	0x4060 /* MFD H264 1 DISP TAG */ 
	#define BITFIELD_MFD_MFD_H264_1_DISP_TAG	 0x4060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_MBI_ADDR_LUT_WR	0x407c /* MFD H264 1 DPB MBI ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_MBI_ADDR_LUT_WR	 0x407c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_UV_ADDR_LUT_WR	0x4080 /* MFD H264 1 DPB UV ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_UV_ADDR_LUT_WR	 0x4080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DPB_Y_ADDR_LUT_WR	0x4084 /* MFD H264 1 DPB Y ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_H264_1_DPB_Y_ADDR_LUT_WR	 0x4084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_FRAME_CYC_COUNT	0x4090 /* MFD H264 1 FRAME CYC COUNT */ 
	#define BITFIELD_MFD_MFD_H264_1_FRAME_CYC_COUNT	 0x4090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_IB_WAIT_COUNT	0x4094 /* MFD H264 1 IB WAIT COUNT */ 
	#define BITFIELD_MFD_MFD_H264_1_IB_WAIT_COUNT	 0x4094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_RBSP_COUNT	0x4098 /* MFD H264 1 RBSP COUNT */ 
	#define BITFIELD_MFD_MFD_H264_1_RBSP_COUNT	 0x4098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_COUNT	0x409c /* MFD H264 1 MPR COUNT */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_COUNT	 0x409c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_CORE_CONFIG	0x40a0 /* MFD H264 1 CORE CONFIG */ 
	#define BITFIELD_MFD_MFD_H264_1_CORE_CONFIG	 0x40a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_INT_CTRL	0x40c0 /* MFD H264 1 INT CTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_INT_CTRL	 0x40c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_INT_STAT	0x40c4 /* MFD H264 1 INT STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_INT_STAT	 0x40c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SOFT_RST	0x40fc /* MFD H264 1 SOFT RST */ 
	#define BITFIELD_MFD_MFD_H264_1_SOFT_RST	 0x40fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_PSR_STAT	0x4100 /* MFD H264 1 BSD PSR STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_PSR_STAT	 0x4100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_STAT	0x4104 /* MFD H264 1 BSD STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_STAT	 0x4104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_RBSP_CTRL	0x4110 /* MFD H264 1 BSD RBSP CTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_RBSP_CTRL	 0x4110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_DATA	0x4114 /* MFD H264 1 BSD DATA */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_DATA	 0x4114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_NAL_TYPE	0x4118 /* MFD H264 1 BSD NAL TYPE */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_NAL_TYPE	 0x4118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_BBB_STAT	0x411c /* MFD H264 1 BSD BBB STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_BBB_STAT	 0x411c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GUE_DEC	0x4120 /* MFD H264 1 BSD GUE DEC */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GUE_DEC	 0x4120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GSE_DEC	0x4124 /* MFD H264 1 BSD GSE DEC */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GSE_DEC	 0x4124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_EXP_GME_INTRA	0x4128 /* MFD H264 1 BSD EXP GME_INTRA */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_EXP_GME_INTRA	 0x4128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_EXP_GME_INTER	0x4138 /* MFD H264 1 BSD EXP GME_INTER */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_EXP_GME_INTER	 0x4138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_IMG_INIT	0x4140 /* MFD H264 1 BSD IMG INIT */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_IMG_INIT	 0x4140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_SLICE_P1	0x4150 /* MFD H264 1 BSD SLICE P1 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_SLICE_P1	 0x4150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_SLICE_P2	0x4154 /* MFD H264 1 BSD SLICE P2 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_SLICE_P2	 0x4154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_SLICE_START	0x4158 /* MFD H264 1 BSD SLICE START */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_SLICE_START	 0x4158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_MB_CTRL	0x415c /* MFD H264 1 BSD MB CTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_MB_CTRL	 0x415c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_QM_DEC_START	0x4160 /* MFD H264 1 BSD QM DEC START */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_QM_DEC_START	 0x4160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_DEC_STAT	0x4164 /* MFD H264 1 BSD DEC STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_DEC_STAT	 0x4164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_QM_LOAD_START	0x4168 /* MFD H264 1 BSD QM LOAD START */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_QM_LOAD_START	 0x4168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_QM_LOAD_VALUE	0x416c /* MFD H264 1 BSD QM LOAD VALUE */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_QM_LOAD_VALUE	 0x416c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_BYTE_ALIGN	0x417c /* MFD H264 1 BSD BYTE ALIGN */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_BYTE_ALIGN	 0x417c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_BBB_TRAIL	0x4180 /* MFD H264 1 BSD BBB TRAIL */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_BBB_TRAIL	 0x4180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS01	0x4184 /* MFD H264 1 BSD GET BITS01 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS01	 0x4184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS02	0x4188 /* MFD H264 1 BSD GET BITS02 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS02	 0x4188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS03	0x418c /* MFD H264 1 BSD GET BITS03 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS03	 0x418c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS04	0x4190 /* MFD H264 1 BSD GET BITS04 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS04	 0x4190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS05	0x4194 /* MFD H264 1 BSD GET BITS05 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS05	 0x4194, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS06	0x4198 /* MFD H264 1 BSD GET BITS06 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS06	 0x4198, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS07	0x419c /* MFD H264 1 BSD GET BITS07 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS07	 0x419c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS08	0x41a0 /* MFD H264 1 BSD GET BITS08 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS08	 0x41a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS09	0x41a4 /* MFD H264 1 BSD GET BITS09 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS09	 0x41a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS10	0x41a8 /* MFD H264 1 BSD GET BITS10 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS10	 0x41a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS11	0x41ac /* MFD H264 1 BSD GET BITS11 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS11	 0x41ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS12	0x41b0 /* MFD H264 1 BSD GET BITS12 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS12	 0x41b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS13	0x41b4 /* MFD H264 1 BSD GET BITS13 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS13	 0x41b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS14	0x41b8 /* MFD H264 1 BSD GET BITS14 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS14	 0x41b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS15	0x41bc /* MFD H264 1 BSD GET BITS15 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS15	 0x41bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS16	0x41c0 /* MFD H264 1 BSD GET BITS16 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS16	 0x41c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS17	0x41c4 /* MFD H264 1 BSD GET BITS17 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS17	 0x41c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS18	0x41c8 /* MFD H264 1 BSD GET BITS18 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS18	 0x41c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS19	0x41cc /* MFD H264 1 BSD GET BITS19 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS19	 0x41cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS20	0x41d0 /* MFD H264 1 BSD GET BITS20 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS20	 0x41d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS21	0x41d4 /* MFD H264 1 BSD GET BITS21 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS21	 0x41d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS22	0x41d8 /* MFD H264 1 BSD GET BITS22 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS22	 0x41d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS23	0x41dc /* MFD H264 1 BSD GET BITS23 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS23	 0x41dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS24	0x41e0 /* MFD H264 1 BSD GET BITS24 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS24	 0x41e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS25	0x41e4 /* MFD H264 1 BSD GET BITS25 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS25	 0x41e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS26	0x41e8 /* MFD H264 1 BSD GET BITS26 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS26	 0x41e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS27	0x41ec /* MFD H264 1 BSD GET BITS27 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS27	 0x41ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS28	0x41f0 /* MFD H264 1 BSD GET BITS28 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS28	 0x41f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS29	0x41f4 /* MFD H264 1 BSD GET BITS29 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS29	 0x41f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS30	0x41f8 /* MFD H264 1 BSD GET BITS30 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS30	 0x41f8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_BSD_GET_BITS31	0x41fc /* MFD H264 1 BSD GET BITS31 */ 
	#define BITFIELD_MFD_MFD_H264_1_BSD_GET_BITS31	 0x41fc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_TF_POC	0x4300 /* MFD H264 1 MPR TF POC */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_TF_POC	 0x4300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_BF_POC	0x4304 /* MFD H264 1 MPR BF POC */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_BF_POC	 0x4304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST00	0x4380 /* MFD H264 1 MPR LST00 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST00	 0x4380, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST01	0x4384 /* MFD H264 1 MPR LST01 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST01	 0x4384, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST02	0x4388 /* MFD H264 1 MPR LST02 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST02	 0x4388, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST03	0x438c /* MFD H264 1 MPR LST03 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST03	 0x438c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST04	0x4390 /* MFD H264 1 MPR LST04 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST04	 0x4390, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST05	0x4394 /* MFD H264 1 MPR LST05 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST05	 0x4394, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST06	0x4398 /* MFD H264 1 MPR LST06 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST06	 0x4398, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST07	0x439c /* MFD H264 1 MPR LST07 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST07	 0x439c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST08	0x43a0 /* MFD H264 1 MPR LST08 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST08	 0x43a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST09	0x43a4 /* MFD H264 1 MPR LST09 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST09	 0x43a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST10	0x43a8 /* MFD H264 1 MPR LST10 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST10	 0x43a8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST11	0x43ac /* MFD H264 1 MPR LST11 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST11	 0x43ac, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST12	0x43b0 /* MFD H264 1 MPR LST12 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST12	 0x43b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST13	0x43b4 /* MFD H264 1 MPR LST13 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST13	 0x43b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST14	0x43b8 /* MFD H264 1 MPR LST14 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST14	 0x43b8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_MPR_LST15	0x43bc /* MFD H264 1 MPR LST15 */ 
	#define BITFIELD_MFD_MFD_H264_1_MPR_LST15	 0x43bc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_RSB_DDR_BA	0x4808 /* MFD H264 1 RSB DDR BA */ 
	#define BITFIELD_MFD_MFD_H264_1_RSB_DDR_BA	 0x4808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DEC_STATUS	0x480c /* MFD H264 1 DEC STATUS */ 
	#define BITFIELD_MFD_MFD_H264_1_DEC_STATUS	 0x480c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SIF_SMP_RS	0x4810 /* MFD H264 1 SIF SMP RS */ 
	#define BITFIELD_MFD_MFD_H264_1_SIF_SMP_RS	 0x4810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SIF_MSK_RS	0x4814 /* MFD H264 1 SIF MSK RS */ 
	#define BITFIELD_MFD_MFD_H264_1_SIF_MSK_RS	 0x4814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SIF_HDAT	0x4818 /* MFD H264 1 SIF HDAT */ 
	#define BITFIELD_MFD_MFD_H264_1_SIF_HDAT	 0x4818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SIF_SDDAT	0x481c /* MFD H264 1 SIF SDDAT */ 
	#define BITFIELD_MFD_MFD_H264_1_SIF_SDDAT	 0x481c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SIF_SMP_RC	0x4820 /* MFD H264 1 SIF SMP RC */ 
	#define BITFIELD_MFD_MFD_H264_1_SIF_SMP_RC	 0x4820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SIF_MSK_RC	0x4824 /* MFD H264 1 SIF MSK RC */ 
	#define BITFIELD_MFD_MFD_H264_1_SIF_MSK_RC	 0x4824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SED	0x4900 /* MFD H264 1 SED */ 
	#define BITFIELD_MFD_MFD_H264_1_SED	 0x4900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SDEMC	0x4904 /* MFD H264 1 SDEMC */ 
	#define BITFIELD_MFD_MFD_H264_1_SDEMC	 0x4904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_CB_BASE	0x4908 /* MFD H264 1 DMA CB BASE */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_CB_BASE	 0x4908, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SB_RDPTR	0x490c /* MFD H264 1 DMA SB RDPTR */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SB_RDPTR	 0x490c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_CB_SIZE	0x4910 /* MFD H264 1 DMA CB SIZE */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_CB_SIZE	 0x4910, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_WTRMARK	0x4914 /* MFD H264 1 DMA WTRMARK */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_WTRMARK	 0x4914, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_WDT	0x4918 /* MFD H264 1 DMA WDT */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_WDT	 0x4918, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_CB_RDPTR	0x491c /* MFD H264 1 DMA CB RDPTR */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_CB_RDPTR	 0x491c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_CB_WRPTR	0x4920 /* MFD H264 1 DMA CB WRPTR */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_CB_WRPTR	 0x4920, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SDLINK	0x4924 /* MFD H264 1 DMA SDLINK */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SDLINK	 0x4924, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SDLLSA	0x4928 /* MFD H264 1 DMA SDLLSA */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SDLLSA	 0x4928, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SDLNDA	0x492c /* MFD H264 1 DMA SDLNDA */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SDLNDA	 0x492c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SDLDBC	0x4930 /* MFD H264 1 DMA SDLDBC */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SDLDBC	 0x4930, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SDLCBC	0x4934 /* MFD H264 1 DMA SDLCBC */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SDLCBC	 0x4934, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_SDLDC	0x4938 /* MFD H264 1 DMA SDLDC */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_SDLDC	 0x4938, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_FIFO	0x493c /* MFD H264 1 DMA FIFO */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_FIFO	 0x493c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_FIFO_STAT	0x4940 /* MFD H264 1 DMA FIFO STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_FIFO_STAT	 0x4940, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_INT_EN	0x4944 /* MFD H264 1 DMA INT EN */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_INT_EN	 0x4944, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_INT_STAT	0x4948 /* MFD H264 1 DMA INT STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_INT_STAT	 0x4948, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_DMA_BS_CNTR	0x494c /* MFD H264 1 DMA BS CNTR */ 
	#define BITFIELD_MFD_MFD_H264_1_DMA_BS_CNTR	 0x494c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_XCR	0x4a00 /* MFD H264 1 SCD XCR */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_XCR	 0x4a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_XSCR1	0x4a04 /* MFD H264 1 SCD XSCR1 */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_XSCR1	 0x4a04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_XSCR2	0x4a08 /* MFD H264 1 SCD XSCR2 */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_XSCR2	 0x4a08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_FWPREAD	0x4a0c /* MFD H264 1 SCD FWPREAD */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_FWPREAD	 0x4a0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_FWCRTL	0x4a10 /* MFD H264 1 SCD FWCRTL */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_FWCRTL	 0x4a10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_FWSTAT	0x4a14 /* MFD H264 1 SCD FWSTAT */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_FWSTAT	 0x4a14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_WRCTRL	0x4a18 /* MFD H264 1 SCD WRCTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_WRCTRL	 0x4a18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_SCD_WRDATA	0x4a1c /* MFD H264 1 SCD WRDATA */ 
	#define BITFIELD_MFD_MFD_H264_1_SCD_WRDATA	 0x4a1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_CTRL	0x4b00 /* MFD H264 1 PIP CTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_CTRL	 0x4b00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_STAT	0x4b04 /* MFD H264 1 PIP STAT */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_STAT	 0x4b04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_CDYB	0x4b08 /* MFD H264 1 PIP CDYB */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_CDYB	 0x4b08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_CDUB	0x4b0c /* MFD H264 1 PIP CDUB */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_CDUB	 0x4b0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_TST_CTRL	0x4b10 /* MFD H264 1 PIP TST CTRL */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_TST_CTRL	 0x4b10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_TST_WR_DATA_LO	0x4b14 /* MFD H264 1 PIP TST WR DATA LO */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_TST_WR_DATA_LO	 0x4b14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_H264_1_PIP_TST_WR_DATA_HI	0x4b18 /* MFD H264 1 PIP TST WR DATA HI */ 
	#define BITFIELD_MFD_MFD_H264_1_PIP_TST_WR_DATA_HI	 0x4b18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SMP_RD	0x5000 /* MFD VC1 1 SMP RD */ 
	#define BITFIELD_MFD_MFD_VC1_1_SMP_RD	 0x5000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_INT_EN_RD	0x5004 /* MFD VC1 1 INT EN RD */ 
	#define BITFIELD_MFD_MFD_VC1_1_INT_EN_RD	 0x5004, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SMP_SET	0x5008 /* MFD VC1 1 SMP SET */ 
	#define BITFIELD_MFD_MFD_VC1_1_SMP_SET	 0x5008, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SMP_CLR	0x500c /* MFD VC1 1 SMP CLR */ 
	#define BITFIELD_MFD_MFD_VC1_1_SMP_CLR	 0x500c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SMP_MSK_SET	0x5010 /* MFD VC1 1 SMP MSK SET */ 
	#define BITFIELD_MFD_MFD_VC1_1_SMP_MSK_SET	 0x5010, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SMP_MSK_CLR	0x5014 /* MFD VC1 1 SMP MSK CLR */ 
	#define BITFIELD_MFD_MFD_VC1_1_SMP_MSK_CLR	 0x5014, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_HDAT	0x5018 /* MFD VC1 1 HDAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_HDAT	 0x5018, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SDDAT	0x501c /* MFD VC1 1 SDDAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_SDDAT	 0x501c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DQ_PUSH	0x5020 /* MFD VC1 1 DQ PUSH */ 
	#define BITFIELD_MFD_MFD_VC1_1_DQ_PUSH	 0x5020, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DQ_STAT	0x5024 /* MFD VC1 1 DQ STAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_DQ_STAT	 0x5024, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_INIT	0x5040 /* MFD VC1 1 DPB INIT */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_INIT	 0x5040, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_FRM_SZ_STAT	0x5044 /* MFD VC1 1 DPB FRM SZ STAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_FRM_SZ_STAT	 0x5044, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_FRM_SZ_CTRL	0x5048 /* MFD VC1 1 DPB FRM SZ CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_FRM_SZ_CTRL	 0x5048, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_NUMB_OVR	0x504c /* MFD VC1 1 DPB NUMB OVR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_NUMB_OVR	 0x504c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_FS_SETTING	0x5050 /* MFD VC1 1 DPB FS SETTING */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_FS_SETTING	 0x5050, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_LOAD_OFFSET	0x5054 /* MFD VC1 1 DPB LOAD OFFSET */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_LOAD_OFFSET	 0x5054, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_FSD	0x5058 /* MFD VC1 1 FSD */ 
	#define BITFIELD_MFD_MFD_VC1_1_FSD	 0x5058, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DANGLING_FIELD	0x505c /* MFD VC1 1 DANGLING FIELD */ 
	#define BITFIELD_MFD_MFD_VC1_1_DANGLING_FIELD	 0x505c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DISP_TAG	0x5060 /* MFD VC1 1 DISP TAG */ 
	#define BITFIELD_MFD_MFD_VC1_1_DISP_TAG	 0x5060, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_UV_ADDR_LUT_WR	0x2080 /* MFD VC1 1 DPB UV ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_UV_ADDR_LUT_WR	 0x2080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DPB_Y_ADDR_LUT_WR	0x2084 /* MFD VC1 1 DPB Y ADDR LUT WR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DPB_Y_ADDR_LUT_WR	 0x2084, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MPS_RD_BYTE_COUNT	0x5088 /* MFD VC1 1 MPS RD BYTE COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_1_MPS_RD_BYTE_COUNT	 0x5088, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SLC_IN_FRM_COUNT	0x508c /* MFD VC1 1 SLC IN FRM COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_1_SLC_IN_FRM_COUNT	 0x508c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_FRAME_CYC_COUNT	0x5090 /* MFD VC1 1 FRAME CYC COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_1_FRAME_CYC_COUNT	 0x5090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_IB_WAIT_COUNT	0x5094 /* MFD VC1 1 IB WAIT COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_1_IB_WAIT_COUNT	 0x5094, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_RBSP_COUNT	0x5098 /* MFD VC1 1 RBSP COUNT */ 
	#define BITFIELD_MFD_MFD_VC1_1_RBSP_COUNT	 0x5098, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BS2RBSP_STATUS	0x509c /* MFD VC1 1 BS2RBSP STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_1_BS2RBSP_STATUS	 0x509c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_CORE_CONFIG	0x50a0 /* MFD VC1 1 CORE CONFIG */ 
	#define BITFIELD_MFD_MFD_VC1_1_CORE_CONFIG	 0x50a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_RBSP_CTRL	0x50a4 /* MFD VC1 1 RBSP CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_RBSP_CTRL	 0x50a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_INT_CTRL	0x50c0 /* MFD VC1 1 INT CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_INT_CTRL	 0x50c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_INT_STAT	0x50c4 /* MFD VC1 1 INT STAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_INT_STAT	 0x50c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SOFT_RST	0x50c8 /* MFD VC1 1 SOFT RST */ 
	#define BITFIELD_MFD_MFD_VC1_1_SOFT_RST	 0x50c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_BYTE_ALIGN	0x5100 /* MFD VC1 1 BSP BYTE ALIGN */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_BYTE_ALIGN	 0x5100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS01	0x5104 /* MFD VC1 1 BSP GET BITS01 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS01	 0x5104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS02	0x5108 /* MFD VC1 1 BSP GET BITS02 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS02	 0x5108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS03	0x510c /* MFD VC1 1 BSP GET BITS03 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS03	 0x510c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS04	0x5110 /* MFD VC1 1 BSP GET BITS04 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS04	 0x5110, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS05	0x5114 /* MFD VC1 1 BSP GET BITS05 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS05	 0x5114, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS06	0x5118 /* MFD VC1 1 BSP GET BITS06 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS06	 0x5118, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS07	0x511c /* MFD VC1 1 BSP GET BITS07 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS07	 0x511c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS08	0x5120 /* MFD VC1 1 BSP GET BITS08 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS08	 0x5120, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS09	0x5124 /* MFD VC1 1 BSP GET BITS09 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS09	 0x5124, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS10	0x5128 /* MFD VC1 1 BSP GET BITS10 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS10	 0x5128, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS11	0x512c /* MFD VC1 1 BSP GET BITS11 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS11	 0x512c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS12	0x5130 /* MFD VC1 1 BSP GET BITS12 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS12	 0x5130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS13	0x5134 /* MFD VC1 1 BSP GET BITS13 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS13	 0x5134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS14	0x5138 /* MFD VC1 1 BSP GET BITS14 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS14	 0x5138, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS15	0x513c /* MFD VC1 1 BSP GET BITS15 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS15	 0x513c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS16	0x5140 /* MFD VC1 1 BSP GET BITS16 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS16	 0x5140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS17	0x5144 /* MFD VC1 1 BSP GET BITS17 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS17	 0x5144, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS18	0x5148 /* MFD VC1 1 BSP GET BITS18 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS18	 0x5148, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS19	0x514c /* MFD VC1 1 BSP GET BITS19 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS19	 0x514c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS20	0x5150 /* MFD VC1 1 BSP GET BITS20 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS20	 0x5150, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS21	0x5154 /* MFD VC1 1 BSP GET BITS21 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS21	 0x5154, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS22	0x5158 /* MFD VC1 1 BSP GET BITS22 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS22	 0x5158, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS23	0x515c /* MFD VC1 1 BSP GET BITS23 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS23	 0x515c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS24	0x5160 /* MFD VC1 1 BSP GET BITS24 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS24	 0x5160, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS25	0x5164 /* MFD VC1 1 BSP GET BITS25 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS25	 0x5164, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS26	0x5168 /* MFD VC1 1 BSP GET BITS26 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS26	 0x5168, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS27	0x516c /* MFD VC1 1 BSP GET BITS27 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS27	 0x516c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS28	0x5170 /* MFD VC1 1 BSP GET BITS28 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS28	 0x5170, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS29	0x5174 /* MFD VC1 1 BSP GET BITS29 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS29	 0x5174, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS30	0x5178 /* MFD VC1 1 BSP GET BITS30 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS30	 0x5178, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_GET_BITS31	0x517c /* MFD VC1 1 BSP GET BITS31 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_GET_BITS31	 0x517c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_STATUS	0x5180 /* MFD VC1 1 BSP STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_STATUS	 0x5180, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_CTRL	0x5184 /* MFD VC1 1 BSP CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_CTRL	 0x5184, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_SHOW_BITS	0x5188 /* MFD VC1 1 BSP SHOW BITS */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_SHOW_BITS	 0x5188, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_SHOW_BITS_FLPD	0x518c /* MFD VC1 1 BSP SHOW BITS FLPD */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_SHOW_BITS_FLPD	 0x518c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_IGNORE_BBB_LEVEL	0x5190 /* MFD VC1 1 BSP IGNORE BBB LEVEL */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_IGNORE_BBB_LEVEL	 0x5190, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_PTYPE	0x51c0 /* MFD VC1 1 BSP HEADER VLC PTYPE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_PTYPE	 0x51c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_FTYPE	0x51c4 /* MFD VC1 1 BSP HEADER VLC FTYPE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_FTYPE	 0x51c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_MVRANGE	0x51c8 /* MFD VC1 1 BSP HEADER VLC MVRANGE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_MVRANGE	 0x51c8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_MVMODE	0x51cc /* MFD VC1 1 BSP HEADER VLC MVMODE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_MVMODE	 0x51cc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_MVMODE2	0x51d0 /* MFD VC1 1 BSP HEADER VLC MVMODE2 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_MVMODE2	 0x51d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_DMVRANGE	0x51d4 /* MFD VC1 1 BSP HEADER VLC DMVRANGE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_DMVRANGE	 0x51d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_BPPMODE	0x51d8 /* MFD VC1 1 BSP HEADER VLC BPPMODE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_BPPMODE	 0x51d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_BPPVLC2	0x51dc /* MFD VC1 1 BSP HEADER VLC BPPVLC2 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_BPPVLC2	 0x51dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_BPPVLC6	0x51e0 /* MFD VC1 1 BSP HEADER VLC BPPVLC6 */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_BPPVLC6	 0x51e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_BFRACT	0x51e4 /* MFD VC1 1 BSP HEADER VLC BFRACT */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_BFRACT	 0x51e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BSP_HEADER_VLC_REFDIST	0x51e8 /* MFD VC1 1 BSP HEADER VLC REFDIST */ 
	#define BITFIELD_MFD_MFD_VC1_1_BSP_HEADER_VLC_REFDIST	 0x51e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_GENERAL_CORE_CONFIG	0x5200 /* MFD VC1 1 SEQPIC GENERAL CORE CONFIG */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_GENERAL_CORE_CONFIG	 0x5200, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_STREAM_FORMAT_1	0x5204 /* MFD VC1 1 SEQPIC STREAM FORMAT 1 */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_STREAM_FORMAT_1	 0x5204, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_CODED_SIZE	0x5208 /* MFD VC1 1 SEQPIC CODED SIZE */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_CODED_SIZE	 0x5208, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_STREAM_FORMAT_2	0x520c /* MFD VC1 1 SEQPIC STREAM FORMAT 2 */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_STREAM_FORMAT_2	 0x520c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_ENTRY_POINT_1	0x5210 /* MFD VC1 1 SEQPIC ENTRY POINT 1 */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_ENTRY_POINT_1	 0x5210, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_RANGE_MAP	0x5214 /* MFD VC1 1 SEQPIC RANGE MAP */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_RANGE_MAP	 0x5214, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_FRAME_TYPE	0x5218 /* MFD VC1 1 SEQPIC FRAME TYPE */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_FRAME_TYPE	 0x5218, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_RECON_CONTROL	0x521c /* MFD VC1 1 SEQPIC RECON CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_RECON_CONTROL	 0x521c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_MOTION_VECTOR_CONTROL	0x5220 /* MFD VC1 1 SEQPIC MOTION VECTOR CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_MOTION_VECTOR_CONTROL	 0x5220, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_INTENSITY_COMPENSATION	0x5224 /* MFD VC1 1 SEQPIC INTENSITY COMPENSATION */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_INTENSITY_COMPENSATION	 0x5224, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_REFERENCE_B_FRACTION	0x5228 /* MFD VC1 1 SEQPIC REFERENCE B FRACTION */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_REFERENCE_B_FRACTION	 0x5228, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_BLOCK_CONTROL	0x522c /* MFD VC1 1 SEQPIC BLOCK CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_BLOCK_CONTROL	 0x522c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_TRANSFORM_DATA	0x5230 /* MFD VC1 1 SEQPIC TRANSFORM DATA */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_TRANSFORM_DATA	 0x5230, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_VOP_DEQUANT	0x5234 /* MFD VC1 1 SEQPIC VOP DEQUANT */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_VOP_DEQUANT	 0x5234, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_CURR_FRAME_ID	0x5238 /* MFD VC1 1 SEQPIC CURR FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_CURR_FRAME_ID	 0x5238, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_CURR_DISPLAY_ID	0x523c /* MFD VC1 1 SEQPIC CURR DISPLAY ID */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_CURR_DISPLAY_ID	 0x523c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_FWD_REF_FRAME_ID	0x5240 /* MFD VC1 1 SEQPIC FWD REF FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_FWD_REF_FRAME_ID	 0x5240, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_BWD_REF_FRAME_ID	0x5244 /* MFD VC1 1 SEQPIC BWD REF FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_BWD_REF_FRAME_ID	 0x5244, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_FIELD_REF_FRAME_ID	0x5248 /* MFD VC1 1 SEQPIC FIELD REF FRAME ID */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_FIELD_REF_FRAME_ID	 0x5248, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_AUX_FRAME_CONTROL	0x524c /* MFD VC1 1 SEQPIC AUX FRAME CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_AUX_FRAME_CONTROL	 0x524c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_IMAGE_STRUCTURE	0x5250 /* MFD VC1 1 SEQPIC IMAGE STRUCTURE */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_IMAGE_STRUCTURE	 0x5250, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SEQPIC_ALT_FRAME_TYPE	0x5254 /* MFD VC1 1 SEQPIC ALT FRAME TYPE */ 
	#define BITFIELD_MFD_MFD_VC1_1_SEQPIC_ALT_FRAME_TYPE	 0x5254, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_STATUS	0x5300 /* MFD VC1 1 MBDEC STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_STATUS	 0x5300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_FRAME_START	0x5304 /* MFD VC1 1 MBDEC FRAME START */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_FRAME_START	 0x5304, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_FW_DEBUG	0x5308 /* MFD VC1 1 MBDEC FW DEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_FW_DEBUG	 0x5308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_MBQDEBUG	0x530c /* MFD VC1 1 MBDEC MBQDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_MBQDEBUG	 0x530c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_MPRDEBUG	0x5310 /* MFD VC1 1 MBDEC MPRDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_MPRDEBUG	 0x5310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_MASDEBUG	0x5314 /* MFD VC1 1 MBDEC MASDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_MASDEBUG	 0x5314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_BPPDEBUG	0x5318 /* MFD VC1 1 MBDEC BPPDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_BPPDEBUG	 0x5318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_DPBMCDEBUG	0x531c /* MFD VC1 1 MBDEC DPBMCDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_DPBMCDEBUG	 0x531c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_GENDEBUG	0x5320 /* MFD VC1 1 MBDEC GENDEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_GENDEBUG	 0x5320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_FW_DEBUG	0x5324 /* MFD VC1 1 FW DEBUG */ 
	#define BITFIELD_MFD_MFD_VC1_1_FW_DEBUG	 0x5324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBDEC_ERROR_CONCEAL_CONTROL	0x5340 /* MFD VC1 1 MBDEC ERROR CONCEAL CONTROL */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBDEC_ERROR_CONCEAL_CONTROL	 0x5340, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BP_CONTROL_STATUS	0x5400 /* MFD VC1 1 BP CONTROL STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_1_BP_CONTROL_STATUS	 0x5400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BP_DATA_IN_STATUS	0x5404 /* MFD VC1 1 BP DATA IN STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_1_BP_DATA_IN_STATUS	 0x5404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BP_DATA_IN_VALUE	0x5408 /* MFD VC1 1 BP DATA IN VALUE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BP_DATA_IN_VALUE	 0x5408, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_BP_DATA_IN_POSITION_N_SIZE	0x540c /* MFD VC1 1 BP DATA IN POSITION N SIZE */ 
	#define BITFIELD_MFD_MFD_VC1_1_BP_DATA_IN_POSITION_N_SIZE	 0x540c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_MBA_ENABLE	0x5800 /* MFD VC1 1 MBA ENABLE */ 
	#define BITFIELD_MFD_MFD_VC1_1_MBA_ENABLE	 0x5800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_RSB_DDR_BA	0x5808 /* MFD VC1 1 RSB DDR BA */ 
	#define BITFIELD_MFD_MFD_VC1_1_RSB_DDR_BA	 0x5808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DEC_STATUS	0x580c /* MFD VC1 1 DEC STATUS */ 
	#define BITFIELD_MFD_MFD_VC1_1_DEC_STATUS	 0x580c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SIF_SMP_RS	0x5810 /* MFD VC1 1 SIF SMP RS */ 
	#define BITFIELD_MFD_MFD_VC1_1_SIF_SMP_RS	 0x5810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SIF_MSK_RS	0x5814 /* MFD VC1 1 SIF MSK RS */ 
	#define BITFIELD_MFD_MFD_VC1_1_SIF_MSK_RS	 0x5814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SIF_HDAT	0x5818 /* MFD VC1 1 SIF HDAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_SIF_HDAT	 0x5818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SIF_SDDAT	0x581c /* MFD VC1 1 SIF SDDAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_SIF_SDDAT	 0x581c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SIF_SMP_RC	0x5820 /* MFD VC1 1 SIF SMP RC */ 
	#define BITFIELD_MFD_MFD_VC1_1_SIF_SMP_RC	 0x5820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SIF_MSK_RC	0x5824 /* MFD VC1 1 SIF MSK RC */ 
	#define BITFIELD_MFD_MFD_VC1_1_SIF_MSK_RC	 0x5824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SED	0x5900 /* MFD VC1 1 SED */ 
	#define BITFIELD_MFD_MFD_VC1_1_SED	 0x5900, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SDEMC	0x5904 /* MFD VC1 1 SDEMC */ 
	#define BITFIELD_MFD_MFD_VC1_1_SDEMC	 0x5904, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_CB_BASE	0x5908 /* MFD VC1 1 DMA CB BASE */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_CB_BASE	 0x5908, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SB_RDPTR	0x590c /* MFD VC1 1 DMA SB RDPTR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SB_RDPTR	 0x590c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_CB_SIZE	0x5910 /* MFD VC1 1 DMA CB SIZE */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_CB_SIZE	 0x5910, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_WTRMARK	0x5914 /* MFD VC1 1 DMA WTRMARK */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_WTRMARK	 0x5914, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_WDT	0x5918 /* MFD VC1 1 DMA WDT */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_WDT	 0x5918, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_CB_RDPTR	0x591c /* MFD VC1 1 DMA CB RDPTR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_CB_RDPTR	 0x591c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_CB_WRPTR	0x5920 /* MFD VC1 1 DMA CB WRPTR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_CB_WRPTR	 0x5920, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SDLINK	0x5924 /* MFD VC1 1 DMA SDLINK */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SDLINK	 0x5924, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SDLLSA	0x5928 /* MFD VC1 1 DMA SDLLSA */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SDLLSA	 0x5928, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SDLNDA	0x592c /* MFD VC1 1 DMA SDLNDA */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SDLNDA	 0x592c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SDLDBC	0x5930 /* MFD VC1 1 DMA SDLDBC */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SDLDBC	 0x5930, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SDLCBC	0x5934 /* MFD VC1 1 DMA SDLCBC */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SDLCBC	 0x5934, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_SDLDC	0x5938 /* MFD VC1 1 DMA SDLDC */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_SDLDC	 0x5938, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_FIFO	0x593c /* MFD VC1 1 DMA FIFO */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_FIFO	 0x593c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_FIFO_STAT	0x5940 /* MFD VC1 1 DMA FIFO STAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_FIFO_STAT	 0x5940, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_INT_EN	0x5944 /* MFD VC1 1 DMA INT EN */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_INT_EN	 0x5944, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_INT_STAT	0x5948 /* MFD VC1 1 DMA INT STAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_INT_STAT	 0x5948, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_DMA_BS_CNTR	0x594c /* MFD VC1 1 DMA BS CNTR */ 
	#define BITFIELD_MFD_MFD_VC1_1_DMA_BS_CNTR	 0x594c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_XCR	0x5a00 /* MFD VC1 1 SCD XCR */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_XCR	 0x5a00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_XSCR1	0x5a04 /* MFD VC1 1 SCD XSCR1 */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_XSCR1	 0x5a04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_XSCR2	0x5a08 /* MFD VC1 1 SCD XSCR2 */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_XSCR2	 0x5a08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_FWPREAD	0x5a0c /* MFD VC1 1 SCD FWPREAD */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_FWPREAD	 0x5a0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_FWCRTL	0x5a10 /* MFD VC1 1 SCD FWCRTL */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_FWCRTL	 0x5a10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_FWSTAT	0x5a14 /* MFD VC1 1 SCD FWSTAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_FWSTAT	 0x5a14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_WRCTRL	0x5a18 /* MFD VC1 1 SCD WRCTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_WRCTRL	 0x5a18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_SCD_WRDATA	0x5a1c /* MFD VC1 1 SCD WRDATA */ 
	#define BITFIELD_MFD_MFD_VC1_1_SCD_WRDATA	 0x5a1c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_CTRL	0x5b00 /* MFD VC1 1 PIP CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_CTRL	 0x5b00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_STAT	0x5b04 /* MFD VC1 1 PIP STAT */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_STAT	 0x5b04, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_CDYB	0x5b08 /* MFD VC1 1 PIP CDYB */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_CDYB	 0x5b08, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_CDUB	0x5b0c /* MFD VC1 1 PIP CDUB */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_CDUB	 0x5b0c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_TST_CTRL	0x5b10 /* MFD VC1 1 PIP TST CTRL */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_TST_CTRL	 0x5b10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_TST_WR_DATA_LO	0x5b14 /* MFD VC1 1 PIP TST WR DATA LO */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_TST_WR_DATA_LO	 0x5b14, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VC1_1_PIP_TST_WR_DATA_HI	0x5b18 /* MFD VC1 1 PIP TST WR DATA HI */ 
	#define BITFIELD_MFD_MFD_VC1_1_PIP_TST_WR_DATA_HI	 0x5b18, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_FPC	0x7300 /* MFD VSPARC FPC */ 
	#define BITFIELD_MFD_MFD_VSPARC_FPC	 0x7300, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_FSTATUS	0x7308 /* MFD VSPARC FSTATUS */ 
	#define BITFIELD_MFD_MFD_VSPARC_FSTATUS	 0x7308, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DPC	0x7310 /* MFD VSPARC DPC */ 
	#define BITFIELD_MFD_MFD_VSPARC_DPC	 0x7310, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_D_INST	0x7314 /* MFD VSPARC D INST */ 
	#define BITFIELD_MFD_MFD_VSPARC_D_INST	 0x7314, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DSTATUS	0x7318 /* MFD VSPARC DSTATUS */ 
	#define BITFIELD_MFD_MFD_VSPARC_DSTATUS	 0x7318, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_EPC	0x7320 /* MFD VSPARC EPC */ 
	#define BITFIELD_MFD_MFD_VSPARC_EPC	 0x7320, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_E_INST	0x7324 /* MFD VSPARC E INST */ 
	#define BITFIELD_MFD_MFD_VSPARC_E_INST	 0x7324, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_ESTATUS	0x7328 /* MFD VSPARC ESTATUS */ 
	#define BITFIELD_MFD_MFD_VSPARC_ESTATUS	 0x7328, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_MSTATUS	0x7338 /* MFD VSPARC MSTATUS */ 
	#define BITFIELD_MFD_MFD_VSPARC_MSTATUS	 0x7338, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_WSTATUS	0x7348 /* MFD VSPARC WSTATUS */ 
	#define BITFIELD_MFD_MFD_VSPARC_WSTATUS	 0x7348, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DCTRL	0x7400 /* MFD VSPARC DCTRL */ 
	#define BITFIELD_MFD_MFD_VSPARC_DCTRL	 0x7400, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DSTAT	0x7404 /* MFD VSPARC DSTAT */ 
	#define BITFIELD_MFD_MFD_VSPARC_DSTAT	 0x7404, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAK0	0x7480 /* MFD VSPARC PCBREAK0 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAK0	 0x7480, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAKMASK0	0x7484 /* MFD VSPARC PCBREAKMASK0 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAKMASK0	 0x7484, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAK1	0x7490 /* MFD VSPARC PCBREAK1 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAK1	 0x7490, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAKMASK1	0x7494 /* MFD VSPARC PCBREAKMASK1 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAKMASK1	 0x7494, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAK2	0x74a0 /* MFD VSPARC PCBREAK2 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAK2	 0x74a0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAKMASK2	0x74a4 /* MFD VSPARC PCBREAKMASK2 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAKMASK2	 0x74a4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAK3	0x74b0 /* MFD VSPARC PCBREAK3 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAK3	 0x74b0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_PCBREAKMASK3	0x74b4 /* MFD VSPARC PCBREAKMASK3 */ 
	#define BITFIELD_MFD_MFD_VSPARC_PCBREAKMASK3	 0x74b4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAK0	0x74c0 /* MFD VSPARC DATABREAK0 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAK0	 0x74c0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAKMASK0	0x74c4 /* MFD VSPARC DATABREAKMASK0 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAKMASK0	 0x74c4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAK1	0x74d0 /* MFD VSPARC DATABREAK1 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAK1	 0x74d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAKMASK1	0x74d4 /* MFD VSPARC DATABREAKMASK1 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAKMASK1	 0x74d4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAK2	0x74e0 /* MFD VSPARC DATABREAK2 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAK2	 0x74e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAKMASK2	0x74e4 /* MFD VSPARC DATABREAKMASK2 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAKMASK2	 0x74e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAK3	0x74f0 /* MFD VSPARC DATABREAK3 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAK3	 0x74f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_DATABREAKMASK3	0x74f4 /* MFD VSPARC DATABREAKMASK3 */ 
	#define BITFIELD_MFD_MFD_VSPARC_DATABREAKMASK3	 0x74f4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_MFD_MFD_VSPARC_CODERAM	0x8000 /* MFD VSPARC CODERAM      */ 
	#define BITFIELD_MFD_MFD_VSPARC_CODERAM	 0x8000, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module MFD SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_MFD_MESSAGE_TX_TO_FW	0x1
#define SVEN_MODULE_EVENT_MFD_MESSAGE_RX_FROM_FW	0x2
#define SVEN_MODULE_EVENT_MFD_BOTTOM_HALF_HANDLER	0x3
#define SVEN_MODULE_EVENT_MFD_INPUT_PORT_BUFFER	0x4
#define SVEN_MODULE_EVENT_MFD_ENQUEUE_ES_BUFFER	0x5
#define SVEN_MODULE_EVENT_MFD_DEREF_ES_BUFFER	0x6
#define SVEN_MODULE_EVENT_MFD_DECODE_ORDER_FRAME	0x7
#define SVEN_MODULE_EVENT_MFD_DISPLAY_ORDER_FRAME	0x8
#define SVEN_MODULE_EVENT_MFD_OUTPUT_PORT_BUFFER	0x9
#define SVEN_MODULE_EVENT_MFD_RELEASE_FRAME_BUFFER	0xa
#define SVEN_MODULE_EVENT_MFD_FLUSH_START_DEPRECATED	0xb
#define SVEN_MODULE_EVENT_MFD_FLUSH_DONE	0xc
#define SVEN_MODULE_EVENT_MFD_INPUT_PORT_EMPTY	0xd
#define SVEN_MODULE_EVENT_MFD_FB_ALLOCATED	0xe
#define SVEN_MODULE_EVENT_MFD_FB_DEREF	0xf
#define SVEN_MODULE_EVENT_MFD_SPA	0x10
#define SVEN_MODULE_EVENT_MFD_INPUT_INFO	0x11
#define SVEN_MODULE_EVENT_MFD_ES_ATTR_FOUND	0x12
#define SVEN_MODULE_EVENT_MFD_LOW_DESCRIPTORS	0x13
#define SVEN_MODULE_EVENT_MFD_IP_DEPTH_CHANGED	0x14
#define SVEN_MODULE_EVENT_MFD_DEBUG	0x15
#define SVEN_MODULE_EVENT_MFD_PIP_FB_ALLOCATED	0x16
#define SVEN_MODULE_EVENT_MFD_PIP_FB_DEREF	0x17
#define SVEN_MODULE_EVENT_MFD_DROP_FRAME	0x18
#define SVEN_MODULE_EVENT_MFD_DROP_ES_DATA	0x19
#define SVEN_MODULE_EVENT_MFD_INPUT_NEWSEGMENT	0x1a
#define SVEN_MODULE_EVENT_MFD_OUTPUT_NEWSEGMENT	0x1b
#define SVEN_MODULE_EVENT_MFD_FREE_ES_MARKER	0x1c
#define SVEN_MODULE_EVENT_MFD_IN_PORT_THREAD_TRIG	0x1d
#define SVEN_MODULE_EVENT_MFD_OPEN_DEPRECATED	0x1e
#define SVEN_MODULE_EVENT_MFD_START_CLOSE	0x1f
#define SVEN_MODULE_EVENT_MFD_SET_STATE	0x20
#define SVEN_MODULE_EVENT_MFD_ENQUEUE_ES_MARKER	0x21
#define SVEN_MODULE_EVENT_MFD_ADDREF	0x22
#define SVEN_MODULE_EVENT_MFD_BH_INPUT_QUEUE	0x23
#define SVEN_MODULE_EVENT_MFD_INPUT_QUEUE_EMPTY	0x24
#define SVEN_MODULE_EVENT_MFD_ES_MARKER_SEEN	0x25
#define SVEN_MODULE_EVENT_MFD_SEQ_HDR_FOUND	0x26
#define SVEN_MODULE_EVENT_MFD_RES_CHANGE	0x27
#define SVEN_MODULE_EVENT_MFD_ES_END_OF_FRAME_MARK	0x28
#define SVEN_MODULE_EVENT_MFD_PIP_ADDREF	0x29
#define SVEN_MODULE_EVENT_MFD_STREAM_STATISTICS	0x2a
#define SVEN_MODULE_EVENT_MFD_DISPQ_IN_ENQUEUE	0x2b
#define SVEN_MODULE_EVENT_MFD_DISPQ_OUT_DEQUEUE	0x2c
#define SVEN_MODULE_EVENT_MFD_DISP_STACK_PUSH	0x2d
#define SVEN_MODULE_EVENT_MFD_DISP_STACK_POP	0x2e
#define SVEN_MODULE_EVENT_MFD_CONTENT_UNSUP_PROFILE	0x2f
#define SVEN_MODULE_EVENT_MFD_CONTENT_UNSUP_LEVEL	0x30
#define SVEN_MODULE_EVENT_MFD_CONTENT_UNSUP_FEATURE	0x31
#define SVEN_MODULE_EVENT_MFD_CONTENT_UNSUP_RES	0x32
#define SVEN_MODULE_EVENT_MFD_CONTENT_SYNTAX	0x33
#define SVEN_MODULE_EVENT_MFD_IN_DEQUEUE	0x64
#define SVEN_MODULE_EVENT_MFD_OUT_ENQUEUE	0x65
#define SVEN_MODULE_EVENT_MFD_CONTENT_TIME_GAP	0x66
#define SVEN_MODULE_EVENT_MFD_CLOSE	0x68
#define SVEN_MODULE_EVENT_MFD_STATE_CHANGE	0x6b
#define SVEN_MODULE_EVENT_MFD_FLUSH_START	0x6c
#define SVEN_MODULE_EVENT_MFD_FLUSH_COMPLETE	0x6d
#define SVEN_MODULE_EVENT_MFD_NEW_SEG_IN	0x6e
#define SVEN_MODULE_EVENT_MFD_NEW_SEG_OUT	0x6f
#define SVEN_MODULE_EVENT_MFD_OPEN	0x67


#endif /* MFD_REGOFFS_H */
