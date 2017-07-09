/*==========================================================================
  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2005-2009 Intel Corporation. All rights reserved.
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
 *  This file contains the Linux kernel implementations of the OSAL
 *  memory.h abstractions.
 */

#ifndef _OAL_LINUX_MEMORY_H
#define _OAL_LINUX_MEMORY_H

#include <linux/kernel.h>
#include <linux/vmalloc.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

#define _OS_ALLOC(a)            kmalloc(a, GFP_KERNEL)
#define _OS_ALLOC_NONBLOCK(a)   kmalloc(a, GFP_ATOMIC)
#define _OS_ALLOC_LARGE(a)      vmalloc(a)
#define _OS_ALLOC_PAGE          get_zeroed_page(GFP_KERNEL)
#define _OS_VIRT_TO_PHYS(a)     virt_to_phys((void *)a)

#define _OS_FREE(a)             kfree(a)
#define _OS_FREE_NONBLOCK(a)    kfree(a)
#define _OS_FREE_LARGE(a)       vfree(a)
#define _OS_FREE_PAGE(a)        free_page((u32)a)

#define _OS_MEMSET(a,b,c)       memset(a,b,c)
#define _OS_MEMCPY(a,b,c)       memcpy(a,b,c)
#define _OS_MEMCMP(a,b,c)       _os_memcmp(a,b,c)

#endif
