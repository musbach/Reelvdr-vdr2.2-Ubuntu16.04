//*****************************************************************************
// This file is provided under a dual BSD/LGPLv2.1 license.  When using 
// or redistributing this file, you may do so under either license.
//
// LGPL LICENSE SUMMARY
//
// Copyright(c) <2008-2011>. Intel Corporation. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify 
// it under the terms of version 2.1 of the GNU Lesser General Public 
// License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful, but 
// WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public 
// License along with this library; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
// USA. The full GNU Lesser General Public License is included in this 
// distribution in the file called LICENSE.LGPL.
//
// Contact Information:
//     Intel Corporation
//     2200 Mission College Blvd.
//     Santa Clara, CA  97052
//
// BSD LICENSE
//
// Copyright (c) <2008-2011>. Intel Corporation. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
//
//   - Redistributions of source code must retain the above copyright 
//     notice, this list of conditions and the following disclaimer.
//   - Redistributions in binary form must reproduce the above copyright 
//     notice, this list of conditions and the following disclaimer in 
//     the documentation and/or other materials provided with the 
//     distribution.
//   - Neither the name of Intel Corporation nor the names of its 
//     contributors may be used to endorse or promote products derived 
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*****************************************************************************


#ifndef _COMMON_H
#define _COMMON_H

#define MAX_MEMORY_MAP			1024

#define INTEL_CE_FLASH_ERASE			0x1
#define INTEL_CE_FLASH_RESET			0x2
#define INTEL_CE_FLASH_READINFO			0x3
#define INTEL_CE_FLASH_WRITE_BLOCK		0x4
#define INTEL_CE_FLASH_READ_BLOCK		0x5
#define INTEL_CE_FLASH_GET_MAP			0x6		// Return the memory map
#define INTEL_CE_FLASH_READ_BYTES		0x7
#define INTEL_CE_FLASH_READ_SECRET_BYTES	0x8
#define INTEL_CE_FLASH_WRITE_SECRET_BYTES	0x9

//! \file


/** @addtogroup flashtool_ */
/*@{*/ 
typedef struct _intel_ce_flash_info_t
{
	int size_in_bytes;			// in bytes
	int parameter;				// not used for J3
	int blocksize;
	int blocksize2;				// not used for J3
} intel_ce_flash_info_t;

typedef struct _intel_ce_flash_cmd_t
{
	void * buf;
	int blockno;
	int offset, length;		// for bytes read
} intel_ce_flash_cmd_t;

typedef struct _memory_map_item_t
{
	unsigned int start, end;
} memory_map_item_t;

typedef struct _memory_map_t
{
	int memory_map_size;
	memory_map_item_t map[MAX_MEMORY_MAP];
} memory_map_t;
/*@}*/ 
#endif
