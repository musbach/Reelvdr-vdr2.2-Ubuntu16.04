/*========================================================================
  This file is provided under a dual BSD/LGPLv2.1 license.  When using 
  or redistributing this file, you may do so under either license.
 
  LGPL LICENSE SUMMARY
 
  Copyright(c) 2011. Intel Corporation. All rights reserved.
 
  This program is free software; you can redistribute it and/or modify 
  it under the terms of version 2.1 of the GNU Lesser General Public 
  License as published by the Free Software Foundation.
 
  This library is distributed in the hope that it will be useful, but 
  WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
  Lesser General Public License for more details.
 
  You should have received a copy of the GNU Lesser General Public 
  License along with this library; if not, write to the Free Software 
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
  USA. The full GNU Lesser General Public License is included in this 
  distribution in the file called LICENSE.LGPL.
 
  Contact Information:
      Intel Corporation
      2200 Mission College Blvd.
      Santa Clara, CA  97052
 
  BSD LICENSE
 
  Copyright (c) 2011. Intel Corporation. All rights reserved.
 
  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions 
  are met:
 
    - Redistributions of source code must retain the above copyright 
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in 
      the documentation and/or other materials provided with the 
      distribution.
    - Neither the name of Intel Corporation nor the names of its 
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

=========================================================================*/ 

#ifndef OS_LOCK_H
#define OS_LOCK_H

#include <pthread.h>
#include "osal_type.h"

/*! This is an opaque data type that serves as a handle for an allocated lock.
*/
typedef void *os_lock_t;


typedef struct {
    pthread_mutex_t lock;
} os_mutex_t;

#endif
