/*========================================================================
  This file is provided under a dual BSD/LGPLv2.1 license.  When using 
  or redistributing this file, you may do so under either license.
 
  LGPL LICENSE SUMMARY
 
  Copyright(c) <2005-2011>. Intel Corporation. All rights reserved.
 
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
 
  Copyright (c) <2005-2011>. Intel Corporation. All rights reserved.
 
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
/*
 *  This file contains Linux User-space implementations for the OSAL io.h
 *  abstractions.
 */

#ifndef _OSAL_LINUX_USER_SCHED_H
#define _OSAL_LINUX_USER_SCHED_H

#include <unistd.h>
#include <sys/time.h>
#include <time.h>
static __inline os_alarm_t _linux_user_set_alarm(unsigned long t)
{
    os_alarm_t time_value;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    time_value = (os_alarm_t)(tv.tv_sec - 0x3e000000) * 1000000 + (os_alarm_t)tv.tv_usec + (os_alarm_t)(t * 1000);
    return (os_alarm_t)time_value;
}

static __inline int _linux_user_test_alarm(os_alarm_t t)
{
    os_alarm_t time_value;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    time_value = (os_alarm_t)(tv.tv_sec - 0x3e000000) * 1000000 + (os_alarm_t)tv.tv_usec;
    return (time_value >= t)?1:0;
}

#define _OS_SCHEDULE() usleep(1);
#define _OS_SET_ALARM(t) _linux_user_set_alarm(t)
#define _OS_TEST_ALARM(t) _linux_user_test_alarm(t)

/* need to move _OS_SLEEP to a C source file */
#define _OS_SLEEP(t) { \
        unsigned int secs = t/1000000;\
        unsigned int ns = (t%1000000)*(1000);\
        struct timespec ts, ts_rem;\
        ts.tv_sec = secs;\
        ts.tv_nsec = ns;\
        nanosleep(&ts, &ts_rem);\
        }

#if 0
/* Commmented this implementation since it is a polling implementation does not
really sleep */

#define _OS_SLEEP(usec) { \
  struct timeval time; \
  unsigned long start_sec,start_usec; \
  long current_sec,current_usec; \
   \
  gettimeofday(&time,NULL); \
  start_sec = time.tv_sec; \
  start_usec = time.tv_usec; \
  do { \
    gettimeofday(&time,NULL); \
    current_sec = time.tv_sec - start_sec; \
    current_usec = time.tv_usec - start_usec; \
  }while((current_sec * 1000000 + current_usec) < usec); \
}
#endif
#endif
