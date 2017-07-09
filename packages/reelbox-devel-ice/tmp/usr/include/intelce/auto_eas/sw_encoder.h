#ifndef ENCODER_REGOFFS_H
#define ENCODER_REGOFFS_H 1
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


/* Module ENCODER CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */




/* Module ENCODER SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_ENCODER_IN_DEQUEUE	0x64
#define SVEN_MODULE_EVENT_ENCODER_OUT_ENQUEUE	0x65
#define SVEN_MODULE_EVENT_ENCODER_CONTENT_TIME_GAP	0x66
#define SVEN_MODULE_EVENT_ENCODER_CLOSE	0x68
#define SVEN_MODULE_EVENT_ENCODER_STATE_CHANGE	0x6b
#define SVEN_MODULE_EVENT_ENCODER_FLUSH_START	0x6c
#define SVEN_MODULE_EVENT_ENCODER_FLUSH_COMPLETE	0x6d
#define SVEN_MODULE_EVENT_ENCODER_NEW_SEG_IN	0x6e
#define SVEN_MODULE_EVENT_ENCODER_NEW_SEG_OUT	0x6f
#define SVEN_MODULE_EVENT_ENCODER_OUTPUT_ES	0x8
#define SVEN_MODULE_EVENT_ENCODER_FIRST_FRAME	0x9
#define SVEN_MODULE_EVENT_ENCODER_SET_STATE	0x10
#define SVEN_MODULE_EVENT_ENCODER_OPEN	0x11
#define SVEN_MODULE_EVENT_ENCODER_EOS_FOUND	0x12
#define SVEN_MODULE_EVENT_ENCODER_EOS_TRIGGERED	0x13
#define SVEN_MODULE_EVENT_ENCODER_HAL_GET_FW_VER	0x40
#define SVEN_MODULE_EVENT_ENCODER_HAL_TX_FRM_TO_FW	0x4e
#define SVEN_MODULE_EVENT_ENCODER_HAL_TX_ES_TO_FW	0x4e
#define SVEN_MODULE_EVENT_ENCODER_HAL_WKLD_TX	0x50
#define SVEN_MODULE_EVENT_ENCODER_HAL_WKLD_RX	0x51
#define SVEN_MODULE_EVENT_ENCODER_HAL_OPEN	0x62
#define SVEN_MODULE_EVENT_ENCODER_HAL_CLOSE	0x63
#define SVEN_MODULE_EVENT_ENCODER_HAL_GET_DESCR_ERR	0x76


#endif /* ENCODER_REGOFFS_H */
