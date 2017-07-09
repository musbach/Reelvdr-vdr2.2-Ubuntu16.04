/*-----------------------------------------------------------------------------
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * The full GNU General Public License is included in this distribution
 * in the file called LICENSE.GPL.
 *
 * Contact Information:
 *      Intel Corporation
 *      2200 Mission College Blvd.
 *      Santa Clara, CA  97052
 *
 * BSD LICENSE
 *
 * Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   - Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#ifndef _SEC_KERNEL_SHARE_TYPES_H_
#define _SEC_KERNEL_SHARE_TYPES_H_

#include "sec_types.h"

typedef uint32_t    sec_address_t;
#define USER_BUF_RO 0
#define USER_BUF_RW 1

// sec_kernel_user_buf_lock is given the user-space virtual memory address,
// the size, a write flag, and a pointer to this user_buf_t that it fills in.
// Descriptor of a user-space (virtual memory) buffer, used when generating
// a DMA descriptor list for the buffer.
typedef struct
{
    sec_address_t   vaddr;      // VM address of buffer.
    struct page   **pages;      // Array of pointers to kernel space allocated
                                // physical pages mapping to the buffer.
    int             num_pages;  // Number of entries in 'pages' array.
    int             size;       // Total size of buffer in bytes.

    // INFO ABOUT PAGE CURRENTLY BEING PROCESSED:

    int             page_index; // Index of current page in 'pages' array
    unsigned long   page_addr;  // Physical address of start of page
    unsigned long   offset;     // Current offset into page
    unsigned long   page_bytes; // # bytes remaining on page: PAGE_SIZE - offset
} user_buf_t;


typedef struct {
    uint32_t next;      // Phys address of next descriptor in linked list
    uint32_t size;      // # bytes in DMA transfer
    uint32_t src;       // Phys address of source buffer
    uint32_t dst;       // Phys address of destination buffer
    uint32_t dma_flags;
} sec_dma_descriptor_t;

typedef struct
{
    unsigned int          tgid;    // Client's thread group identifier
    user_buf_t            src;     // User space source DMA pages
    user_buf_t            dst;     // User space destination DMA pages
    sec_dma_descriptor_t *dma_desc;// Pointer to the head of the linked list of
                            // DMA descriptors associated with these user pages
    uint32_t              dma_flags; //Contains DMA control info (FLAGS_MODE)
    uint32_t              next_descriptor;
    uint32_t              src_start;
    uint32_t              dst_start;
    uint32_t              src_size;
    uint32_t              dst_size;
} dma_desc_info_t;

typedef enum
{
    SEC_SMD_TO_DMA = 0,
    SEC_DMA_TO_SMD = 1,
    SEC_DMA_TO_DMA = 2,
    SEC_SMD_TO_SMD = 3
} sec_dma_type_t;

typedef struct
{
    sec_fw_cmd_t    cmd; //The command to the SEC HW's firmware
    sec_dma_type_t  dma_type; // 0=SMD to DMA, 1=DMA to SMD, 2=DMA to DMA, 3=SMD to SMD
    sec_dma_chain_t dma_chain; //0=LT (Long Term) 1=ST (Short Term)
    uint32_t        dma_size; // The memory size for both source and destination
    void           *dma_src_addr; //The source address for DMA transfers
    void           *dma_dst_addr; //The destination address for DMA transfers
    dma_desc_info_t dma_info;
} sec_dma_mem_t;


#endif

