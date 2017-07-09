#ifndef BUFMON_REGOFFS_H
#define BUFMON_REGOFFS_H 1
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


/* Module BUFMON CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */




/* Module BUFMON SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_BUFMON_UNDERRUN_DETECTED	0x1
#define SVEN_MODULE_EVENT_BUFMON_UNDERRUN_IGNORED_BAD_RENDERER	0x2
#define SVEN_MODULE_EVENT_BUFMON_UNDERRUN_IGNORED_OVERRUN_WAIT	0x3
#define SVEN_MODULE_EVENT_BUFMON_OVERRUN_DETECTED	0x4
#define SVEN_MODULE_EVENT_BUFMON_CRIT_ERROR_DETECTED	0x5
#define SVEN_MODULE_EVENT_BUFMON_ERROR_STROBING_EVENT	0x6
#define SVEN_MODULE_EVENT_BUFMON_ERROR_QUERYING_REND	0x7
#define SVEN_MODULE_EVENT_BUFMON_ERROR_ON_EVENT_WAIT	0x8
#define SVEN_MODULE_EVENT_BUFMON_CLOCK_ADJUSTED	0x9
#define SVEN_MODULE_EVENT_BUFMON_CLOCK_ADJUST_ERROR	0xa
#define SVEN_MODULE_EVENT_BUFMON_REND_ADDED	0xb
#define SVEN_MODULE_EVENT_BUFMON_REND_REMOVED	0xc
#define SVEN_MODULE_EVENT_BUFMON_PORT_ADDED	0xd
#define SVEN_MODULE_EVENT_BUFMON_PORT_REMOVED	0xe
#define SVEN_MODULE_EVENT_BUFMON_PORT_FLUSHED	0xf
#define SVEN_MODULE_EVENT_BUFMON_PORT_FLUSH_ERROR	0x10
#define SVEN_MODULE_EVENT_BUFMON_UNDERRUN_IGNORED_UNDERRUN_WAIT	0x11
#define SVEN_MODULE_EVENT_BUFMON_IN_DEQUEUE	0x64
#define SVEN_MODULE_EVENT_BUFMON_OUT_ENQUEUE	0x65
#define SVEN_MODULE_EVENT_BUFMON_CONTENT_TIME_GAP	0x66
#define SVEN_MODULE_EVENT_BUFMON_CLOSE	0x68
#define SVEN_MODULE_EVENT_BUFMON_STATE_CHANGE	0x6b
#define SVEN_MODULE_EVENT_BUFMON_FLUSH_START	0x6c
#define SVEN_MODULE_EVENT_BUFMON_FLUSH_COMPLETE	0x6d
#define SVEN_MODULE_EVENT_BUFMON_NEW_SEG_IN	0x6e
#define SVEN_MODULE_EVENT_BUFMON_NEW_SEG_OUT	0x6f


#endif /* BUFMON_REGOFFS_H */
