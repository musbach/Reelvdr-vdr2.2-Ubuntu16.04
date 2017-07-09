#ifndef APP_REGOFFS_H
#define APP_REGOFFS_H 1
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


/* Module APP CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */




/* Module APP SPECIFIC SVEN Events */


#define SVEN_MODULE_EVENT_APP_CC_CMD	0x1
#define SVEN_MODULE_EVENT_APP_CC_TEARDOWN_START	0x2
#define SVEN_MODULE_EVENT_APP_CC_TEARDOWN_END	0x3
#define SVEN_MODULE_EVENT_APP_STREAM_START	0x4
#define SVEN_MODULE_EVENT_APP_STREAM_STOP	0x5
#define SVEN_MODULE_EVENT_APP_TRICK_PLAY_START	0x6
#define SVEN_MODULE_EVENT_APP_TRICK_PLAY_COMPLETE	0x7
#define SVEN_MODULE_EVENT_APP_STOP	0x8
#define SVEN_MODULE_EVENT_APP_PLAY	0x9
#define SVEN_MODULE_EVENT_APP_PAUSE	0xa
#define SVEN_MODULE_EVENT_APP_INIT_COMPLETE	0xb
#define SVEN_MODULE_EVENT_APP_EXIT_BEGIN	0xc
#define SVEN_MODULE_EVENT_APP_EXIT_COMPLETE	0xd
#define SVEN_MODULE_EVENT_APP_CC_BUFFERING_START	0xe
#define SVEN_MODULE_EVENT_APP_CC_BUFFERING_END	0xf
#define SVEN_MODULE_EVENT_APP_CC_BUILDUP1_START	0x10
#define SVEN_MODULE_EVENT_APP_CC_BUILDUP1_END	0x11
#define SVEN_MODULE_EVENT_APP_CC_BUILDUP2_START	0x12
#define SVEN_MODULE_EVENT_APP_CC_BUILDUP2_END	0x13
#define SVEN_MODULE_EVENT_APP_CC_CONFIG_START	0x14
#define SVEN_MODULE_EVENT_APP_CC_CONFIG_END	0x15
#define SVEN_MODULE_EVENT_APP_CC_PAT_START	0x16
#define SVEN_MODULE_EVENT_APP_CC_PAT_END	0x17
#define SVEN_MODULE_EVENT_APP_CC_PMT_START	0x18
#define SVEN_MODULE_EVENT_APP_CC_PMT_END	0x19


#endif /* APP_REGOFFS_H */
