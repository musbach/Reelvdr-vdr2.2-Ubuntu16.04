/*==========================================================================
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2005-2010 Intel Corporation. All rights reserved.
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
 =========================================================================*/

/*
 * This file contains Linux kernel implementations for the OSAL io.h
 * abstractions.
 */

#ifndef _OAL_LINUX_IO_H
#define _OAL_LINUX_IO_H

#include <linux/kernel.h>

#include "osal_io.h"

#ifdef CONFIG_PRINT
    #define _OS_PRINT(arg...) printk(arg)
#else
    #define _OS_PRINT(arg...)
#endif


#ifdef CONFIG_ERROR
    #define _OS_ERROR(arg...) do {                    \
		printk(KERN_ERR "%s:%s:", (strrchr(__FILE__,'/') ? (char *)(strrchr(__FILE__,'/')+1) : __FILE__ ), __func__);  \
        printk(arg); } while(0)
#else
    #define _OS_ERROR(arg...)
#endif


#ifdef CONFIG_DEBUG
    #define _OS_DEBUG(arg...)   \
            do {                                            \
				printk(KERN_ERR "%s:%s:", (strrchr(__FILE__,'/') ? (char *)(strrchr(__FILE__,'/')+1) : __FILE__ ), __func__);  \
                printk(arg);                                \
            } while(0)

    #define _OS_DEBUG_S(arg...)                             \
            do {                                            \
                if(osal_debug & MOD_OSAL_DEBUG) {           \
                    printk(arg);                            \
                }                                           \
            } while(0)
#else
    #define _OS_DEBUG(arg...)
    #define _OS_DEBUG_S(arg...)
#endif

//audio uses this macro extensively, make sure it prints at all times
#define _OS_INFO(arg...)                                    \
            do {                                            \
                printk(KERN_ERR "%s:%s:", (strrchr(__FILE__,'/') ? (char *)(strrchr(__FILE__,'/')+1) : __FILE__ ), __func__);  \
                printk(arg);                                \
            } while(0)

#define _OS_READ32(addr) readl(addr)
#define _OS_WRITE32(value, addr) writel(value, addr)

#define _OS_READ16(addr) readw(addr)
#define _OS_WRITE16(value, addr) writew(value, addr)

#define _OS_READ8(addr) readb(addr)
#define _OS_WRITE8(value, addr) writeb(value, addr)

#endif
