#ifndef CES_REGOFFS_H
#define CES_REGOFFS_H 1
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


/* Module CES CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */




/* Module CES SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_CES_OPEN	0x1
#define SVEN_MODULE_EVENT_CES_CLOSE	0x2
#define SVEN_MODULE_EVENT_CES_GV_SYNC_ST	0x3
#define SVEN_MODULE_EVENT_CES_GV_SYNC_END	0x4
#define SVEN_MODULE_EVENT_CES_VIDENC_READ_WKLD	0x34
#define SVEN_MODULE_EVENT_CES_VIDENC_WRITE_WKLD	0x35
#define SVEN_MODULE_EVENT_CES_VIDENC_DBG_H264_STATE_CHANGE	0x36
#define SVEN_MODULE_EVENT_CES_VIDENC_DBG_READ_ES	0x37
#define SVEN_MODULE_EVENT_CES_FW_MUX_OPEN	0x67
#define SVEN_MODULE_EVENT_CES_FW_MUX_CLOSE	0x68
#define SVEN_MODULE_EVENT_CES_FW_MUX_FLUSH	0x69
#define SVEN_MODULE_EVENT_CES_FW_MUX_WKLD_R	0x6a
#define SVEN_MODULE_EVENT_CES_FW_MUX_WKLD_W	0x6b
#define SVEN_MODULE_EVENT_CES_FW_MUX_OUTBUFF_R	0x6c
#define SVEN_MODULE_EVENT_CES_FW_MUX_OUTBUFF_W	0x6d
#define SVEN_MODULE_EVENT_CES_FW_MUX_TIMING_PARAMS	0x6e
#define SVEN_MODULE_EVENT_CES_FW_MUX_TIMEBASE_RST	0x6f
#define SVEN_MODULE_EVENT_CES_FW_MUX_CLOCK_ADJ	0x70
#define SVEN_MODULE_EVENT_CES_FW_MUX_BITRATE_ADJ	0x71
#define SVEN_MODULE_EVENT_CES_FW_MUX_PCR	0x72
#define SVEN_MODULE_EVENT_CES_FW_MUX_PSI	0x73
#define SVEN_MODULE_EVENT_CES_FW_MUX_PES_HDR	0x74
#define SVEN_MODULE_EVENT_CES_FW_MUX_DBG_ASSERT	0x90
#define SVEN_MODULE_EVENT_CES_FW_MUX_DBG	0x91
#define SVEN_MODULE_EVENT_CES_TRACE	0x9a
#define SVEN_MODULE_EVENT_CES_FW_PAR_OPEN	0x9b
#define SVEN_MODULE_EVENT_CES_FW_PAR_CLOSE	0x9c
#define SVEN_MODULE_EVENT_CES_FW_PAR_SET_STATE	0x9d
#define SVEN_MODULE_EVENT_CES_FW_PAR_FLUSH	0x9e
#define SVEN_MODULE_EVENT_CES_FW_PAR_WKLD_ST	0x9f
#define SVEN_MODULE_EVENT_CES_FW_PAR_WKLD_DN	0xa0
#define SVEN_MODULE_EVENT_CES_FW_DEC_OPEN	0xcd
#define SVEN_MODULE_EVENT_CES_FW_DEC_CLOSE	0xce
#define SVEN_MODULE_EVENT_CES_FW_DEC_SET_STATE	0xcf
#define SVEN_MODULE_EVENT_CES_FW_DEC_FLUSH	0xd0
#define SVEN_MODULE_EVENT_CES_FW_DEC_WKLD_ST_BEG	0xd1
#define SVEN_MODULE_EVENT_CES_FW_DEC_WKLD_ST_END	0xd2
#define SVEN_MODULE_EVENT_CES_FW_DEC_WKLD_DONE	0xd3
#define SVEN_MODULE_EVENT_CES_FW_DEC_ERROR	0xd4


#endif /* CES_REGOFFS_H */
