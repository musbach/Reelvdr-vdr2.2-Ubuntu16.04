#ifndef VIDSINK_REGOFFS_H
#define VIDSINK_REGOFFS_H 1
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


/* Module VIDSINK CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */




/* Module VIDSINK SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_VIDSINK_OPEN	0x1
#define SVEN_MODULE_EVENT_VIDSINK_BASE_TIME	0x4
#define SVEN_MODULE_EVENT_VIDSINK_PLAY_RATE	0x5
#define SVEN_MODULE_EVENT_VIDSINK_SET_GLOBAL_SCALE	0x7
#define SVEN_MODULE_EVENT_VIDSINK_PAUSE_ANIM	0x8
#define SVEN_MODULE_EVENT_VIDSINK_PUSH_FRAME	0x9
#define SVEN_MODULE_EVENT_VIDSINK_ADD_QUEUE	0xa
#define SVEN_MODULE_EVENT_VIDSINK_REMOVE_QUEUE	0xb
#define SVEN_MODULE_EVENT_VIDSINK_DEREF_FRAME	0xc
#define SVEN_MODULE_EVENT_VIDSINK_DPE_EMPTY	0xd
#define SVEN_MODULE_EVENT_VIDSINK_VSYNC	0xe
#define SVEN_MODULE_EVENT_VIDSINK_DPE_FULL	0x10
#define SVEN_MODULE_EVENT_VIDSINK_RESEND_QUEUE_FRAMES	0x13
#define SVEN_MODULE_EVENT_VIDSINK_GET_DISP_FRM	0x14
#define SVEN_MODULE_EVENT_VIDSINK_TAG_RESEND	0x1e
#define SVEN_MODULE_EVENT_VIDSINK_PAUSE	0x1f
#define SVEN_MODULE_EVENT_VIDSINK_PLAY	0x20
#define SVEN_MODULE_EVENT_VIDSINK_QUEUE_STATUS	0x21
#define SVEN_MODULE_EVENT_VIDSINK_WRONG_PTS	0x22
#define SVEN_MODULE_EVENT_VIDSINK_IN_EVENT_RCV	0x23
#define SVEN_MODULE_EVENT_VIDSINK_FLUSH_NON_DISP	0x24
#define SVEN_MODULE_EVENT_VIDSINK_RENDER_FULL	0x25
#define SVEN_MODULE_EVENT_VIDSINK_SEND_RENDER	0x26
#define SVEN_MODULE_EVENT_VIDSINK_RENDER_EMPTY	0x27
#define SVEN_MODULE_EVENT_VIDSINK_PREPROC_START	0x28
#define SVEN_MODULE_EVENT_VIDSINK_PREPROC_END	0x29
#define SVEN_MODULE_EVENT_VIDSINK_POSTPROC_START	0x2a
#define SVEN_MODULE_EVENT_VIDSINK_POSTPROC_END	0x2b
#define SVEN_MODULE_EVENT_VIDSINK_GET_ATTR_START	0x2c
#define SVEN_MODULE_EVENT_VIDSINK_GET_ATTR_END	0x2d
#define SVEN_MODULE_EVENT_VIDSINK_TIMEOUT	0x2e
#define SVEN_MODULE_EVENT_VIDSINK_IN_DEQUEUE	0x64
#define SVEN_MODULE_EVENT_VIDSINK_OUT_ENQUEUE	0x65
#define SVEN_MODULE_EVENT_VIDSINK_CONTENT_TIME_GAP	0x66
#define SVEN_MODULE_EVENT_VIDSINK_CLOSE	0x68
#define SVEN_MODULE_EVENT_VIDSINK_STATE_CHANGE	0x6b
#define SVEN_MODULE_EVENT_VIDSINK_FLUSH_START	0x6c
#define SVEN_MODULE_EVENT_VIDSINK_FLUSH_COMPLETE	0x6d
#define SVEN_MODULE_EVENT_VIDSINK_NEW_SEG_IN	0x6e
#define SVEN_MODULE_EVENT_VIDSINK_NEW_SEG_OUT	0x6f


#endif /* VIDSINK_REGOFFS_H */
