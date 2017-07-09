/*
#
# This file is provided under a dual BSD/LGPLv2.1 license.  When using 
# or redistributing this file, you may do so under either license.
#
# LGPL LICENSE SUMMARY
#
# Copyright(c) 2007-2011. Intel Corporation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify 
# it under the terms of version 2.1 of the GNU Lesser General Public 
# License as published by the Free Software Foundation.
#
# This library is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public 
# License along with this library; if not, write to the Free Software 
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
# USA. The full GNU Lesser General Public License is included in this 
# distribution in the file called LICENSE.LGPL.
#
# Contact Information:
#     Intel Corporation
#     2200 Mission College Blvd.
#     Santa Clara, CA  97052
#
#
#  BSD LICENSE
#
#  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the name of Intel Corporation nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*/

/* 
 *  COSAI Header file internally use for Linux user space
 *  to hide the internel structure.
 */

#ifndef _COSAI_INTERNAL_H_
#define _COSAI_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ANDROID_USER
#include "bionic_ext.h"
#else
#include <pthread.h>
#endif

struct linuxuser_list_head {
  struct linuxuser_list_head *next, *prev;
};

typedef struct _linuxuser_thread_t {
  pthread_t                  tid;
  int               stop; //should stop bit
  struct linuxuser_list_head list;
} linuxuser_thread_t;

#define NUM_CPU 1
struct linuxuser_work
{
  struct linuxuser_list_head entry;
  void (*func)(struct linuxuser_work *work);
};

struct linuxuser_workqueue
{
  pthread_spinlock_t lock;
  const char *name;
  struct linuxuser_list_head list;   //List of work in the queue
  pthread_t threads[NUM_CPU];
  volatile int stop[NUM_CPU];
};

typedef struct _linuxuser_waitqueue_t {
  pthread_cond_t  cond;
  pthread_mutex_t mutex;
} linuxuser_waitqueue_t;


#ifdef __cplusplus
};
#endif

#endif //_COSAI_INTERNAL_H
