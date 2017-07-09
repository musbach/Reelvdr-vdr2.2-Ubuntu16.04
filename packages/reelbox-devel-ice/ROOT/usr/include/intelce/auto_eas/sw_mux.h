#ifndef MUX_REGOFFS_H
#define MUX_REGOFFS_H 1
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


/* Module MUX CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */




/* Module MUX SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_MUX_IN_DEQUEUE	0x64
#define SVEN_MODULE_EVENT_MUX_OUT_ENQUEUE	0x65
#define SVEN_MODULE_EVENT_MUX_CONTENT_TIME_GAP	0x66
#define SVEN_MODULE_EVENT_MUX_CLOSE	0x68
#define SVEN_MODULE_EVENT_MUX_STATE_CHANGE	0x6b
#define SVEN_MODULE_EVENT_MUX_FLUSH_START	0x6c
#define SVEN_MODULE_EVENT_MUX_FLUSH_COMPLETE	0x6d
#define SVEN_MODULE_EVENT_MUX_NEW_SEG_IN	0x6e
#define SVEN_MODULE_EVENT_MUX_NEW_SEG_OUT	0x6f
#define SVEN_MODULE_EVENT_MUX_INPUT_STREAM_ADDED	0x3
#define SVEN_MODULE_EVENT_MUX_INPUT_REMOVED	0x4
#define SVEN_MODULE_EVENT_MUX_PORT_FLUSHED	0x5
#define SVEN_MODULE_EVENT_MUX_PORT_FLUSH_ERROR	0x6
#define SVEN_MODULE_EVENT_MUX_STROBE_API_LOCK_EVENT	0x14
#define SVEN_MODULE_EVENT_MUX_STROBE_API_UNLOCK_EVENT	0x15
#define SVEN_MODULE_EVENT_MUX_ACK_API_LOCK_EVENT	0x16
#define SVEN_MODULE_EVENT_MUX_ACK_API_UNLOCK_EVENT	0x17
#define SVEN_MODULE_EVENT_MUX_CONTEXT_LOCK_ACQUIRED	0x1a
#define SVEN_MODULE_EVENT_MUX_QUEUE_STATUS	0x1e
#define SVEN_MODULE_EVENT_MUX_SEND_TO_FW_FAILED	0x1f


#endif /* MUX_REGOFFS_H */
