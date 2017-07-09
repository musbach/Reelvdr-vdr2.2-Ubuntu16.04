/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

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

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

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
#ifndef IPCLIB_H
#define IPCLIB_H

#if defined(__i386__) || defined(__x86_64__)
    #define CONFIG_IPC_HOST_SIDE
#elif defined(__XSCALE__) || defined(__LINUX_ARM_ARCH__)
    #define CONFIG_IPC_HOST_SIDE
#else
    #define CONFIG_IPC_FW_SIDE
#endif

#ifndef IPCLIB_CONFIG_H
#include "ipclib_config.h"
#endif

#ifndef IPC_SHARED_H
#include "ipc_shared.h"
#endif

#ifdef CONFIG_IPC_FW_SIDE
#define OS_SLEEP(x)  usleep(x)
#define OS_PRINT(...)
#else
#include "osal.h"
#endif

#ifdef CONFIG_IPC_FW_SIDE
    #define CONFIG_IPC_MAX_QUEUES   CONFIG_IPC_FW_MAX_RX_QUEUES
    #define CONFIG_IPC_QUEUE_SIZE   CONFIG_IPC_FW_QUEUE_SIZE
#else
    #define CONFIG_IPC_MAX_QUEUES   CONFIG_IPC_HOST_MAX_RX_QUEUES
    #define CONFIG_IPC_QUEUE_SIZE   CONFIG_IPC_HOST_QUEUE_SIZE
#endif

#define IPC_ALIGN_MSG_SIZE( siz )   (((siz) + (CONFIG_IPC_MESSAGE_SIZE_ALIGN-1)) & ~(CONFIG_IPC_MESSAGE_SIZE_ALIGN-1))

/* indication of which type of IA memory path the host is on*/
typedef enum {
    /* "normal" mode  */
    IPC_MEMORY_PATH_COHERENT,
    /* "fast-path" mode */
    IPC_MEMORY_PATH_NON_COHERENT,
} ipc_mem_path_t;
/* --------------------------------------------------- */
/* --------------------------------------------------- */
/** This is a local representation of the IPC message queue,
 * which is essentially a circular buffer
 */
struct IPC_MsgQueue
{
    struct _IPC_QueueHeader *mq_shared; /* shared memory block (in FW SRAM) */
    volatile unsigned char  *mq_buf;    /* must be a power of two size */
    int                      mq_bufmask;/* mask for size of buffer */

    #ifdef CONFIG_IPC_FW_SIDE
        unsigned int             mq_next_unique_id;
        unsigned int             mq_src_qnum;
        unsigned int             mq_dst_qnum;
    #else
        unsigned short           mq_next_unique_id;
        unsigned char            mq_src_qnum;
        unsigned char            mq_dst_qnum;
    #endif

    #ifdef CONFIG_IPC_FW_SIDE
    #ifdef CONFIG_IPC_FW_MUST_USE_DMA_FOR_SHARED_STRUCTS
    struct _IPC_QueueHeader *mq_qh_real;  /* shared memory block (in FW SRAM) */
    unsigned int             mq_pad[1];   /* make struct size multiple of 8 bytes */
    struct _IPC_QueueHeader  mq_qh_proxy; /* Local Proxy (16 bytes) */
    #endif
    #endif
};

/* Shared Queue availability */
/* --------------------------------------------------- */
unsigned int ipc_mq_write_avail(
    struct IPC_MsgQueue     *mq,
    int                     *ppos );

/* Queue fullness */
int ipc_mq_read_avail(
    struct IPC_MsgQueue     *mq,
    int                     *ppos );

#ifdef CONFIG_IPC_FW_MESSAGE_PEEK
void ipc_mq_peek_init(
    struct IPC_MsgQueue     *mq,
    int                     *ppeek );
#endif

/* Internal LUMP API */
/* --------------------------------------------------- */
int ipc_mq_write_lump(
    struct IPC_MsgQueue     *mq,
    const void              *msg,
    unsigned int             size );

#ifdef CONFIG_IPC_FW_MESSAGE_PEEK
int ipc_mq_peek_next_lump(
    struct IPC_MsgQueue     *mq,
    int                     *peek_pos,
    void                    *msg,
    unsigned int             max_size );
#endif

int ipc_mq_read_next_lump(
    struct IPC_MsgQueue     *mq,
    void                    *msg,
    unsigned int             max_size );


/* Internal MESSAGE API */
/* --------------------------------------------------- */

void ipc_set_mem_path(ipc_mem_path_t mem_path);

int ipc_mq_write_message(
    struct IPC_MsgQueue             *mq,
    const void                      *msg,
    unsigned int                     size );

int ipc_mq_write_message_reply(
    struct IPC_MsgQueue             *mq,
    const struct _IPC_MessageHeader *pmh,
    const void                      *msg,
    unsigned int                     size );

#ifdef CONFIG_IPC_FW_MESSAGE_PEEK
int ipc_mq_peek_next_message(
    struct IPC_MsgQueue             *mq,
    int                             *peek_pos,
    struct _IPC_MessageHeader       *mhdr,
    void                            *msg,
    unsigned int                     max_size );
#endif

int ipc_mq_read_next_message(
    struct IPC_MsgQueue             *mq,
    struct _IPC_MessageHeader       *mhdr,
    void                            *msg,
    unsigned int                     max_size );

/* Deep Structure Init */
/* --------------------------------------------------- */
void ipc_shared_queue_header_init(
    struct _IPC_QueueHeader *sqh,           /* recommended in firmware SRAM */
    unsigned int             circbuf_size );

void ipc_mq_connect(
    struct IPC_MsgQueue     *mq,            /* local memory (to host or fw) */
    struct _IPC_QueueHeader *shared,        /* in vsparc SRAM */
    volatile unsigned char  *circbuf );     /* in Host DDR */

#endif /* IPCLIB_H */
