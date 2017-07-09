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


#ifndef CONFIG_H
#define CONFIG_H

#define TYPE_INVALID	0
#define TYPE_BLDR		1
#define TYPE_FPD		2
#define TYPE_KERNEL		3
#define TYPE_RAMDISK	4
#define TYPE_CONFIGBLOCK	5
#define TYPE_IMGDATA	6
#define TYPE_APPDATA	7
#define TYPE_NULL		10
#define TYPE_END		20


//! \file
/** @addtogroup flashtool_ */
/*@{*/ 
typedef struct _config_item
{
	int type;
	char filename[128];
	int offset;
	int length;
} config_item;

/**
 * @deprecated
 * @brief The function offers filesize.
 * @param[in] file - the field means filename.
 * @retval filesize
 */
int filesize(char * file);
/**
 * @deprecated
 * @brief The function fill the filesize by block unit.
 * @param[in] file - the field means filename.
 * @param[in] blocksize - the field means flash config blocksize.
 * @retval filesize
 */
int filesize_rounded(char * file, int blocksize);
/**
 * @deprecated
 * @brief The function translate number partitiontype from strings.
 * @retval TYPE_INVALID
 * @retval TYPE_BLDR
 * @retval TYPE_KERNEL
 * @retval TYPE_FPD
 * @retval TYPE_RAMDISK
 * @retval TYPE_CONFIGBLOCK
 * @retval TYPE_IMGDATA
 * @retval TYPE_APPDATA
 * @retval TYPE_NULL
 * @retval TYPE_END
 */
int get_type(char * type);
/**
 * @deprecated
 * @brief The function offers partitiontype which from the opened flash device.
 * @param[in] fp - the field is a handle which is called by other function.
 * @param[out] pItem - the field is given as partitionsize.        
 * @retval 0 Success
 * @retval 1 Error
 */
int get_next_config(FILE * fp, config_item * pItem);
/*@}*/ 
#endif
