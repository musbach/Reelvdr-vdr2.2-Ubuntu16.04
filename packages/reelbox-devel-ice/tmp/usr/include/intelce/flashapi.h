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

#ifndef _FLASHAPI_H
#define _FLASHAPI_H

#include "common.h"

#ifdef FLASHAPI_DEBUG
#   define DPRINTF(fmt, args...) printf("%s: " fmt, __FUNCTION__ , ## args)
#else
#   define DPRINTF(fmt, args...)
#endif

#define PERROR(fmt, args...) printf("[ERROR] %s: " fmt, __FUNCTION__ , ## args)
//! \file

/** 
 * @defgroup flashtool_ Flashtool API 
 */
 
/** @addtogroup flashtool_ */
/*@{*/ 
#define OFLASH_HANDLE_LEN	64

typedef enum _oflash_status {
	OFLASH_OK = 0,
	OFLASH_ERR,
	OFLASH_NOIMPL,
} OFLASH_STATUS;

typedef enum _oflash_partype {
	OFLASH_PAR_ALL = 0,
	OFLASH_PAR_FPD = 1,
	OFLASH_PAR_IMAGEDATA,
	OFLASH_PAR_APPDATA,
} OFLASH_PARTYPE;

typedef enum _oflash_seek_type {
	OFLASH_SEEK_SET = 0,
	OFLASH_SEEK_CUR,
	OFLASH_SEEK_END,
} OFLASH_SEEK_TYPE;

#ifndef _OFLASH_CORE

typedef union _OFLASH_HANDLE{
    unsigned int pad[OFLASH_HANDLE_LEN];
} OFLASH_HANDLE;

#else

typedef union _OFLASH_HANDLE OFLASH_HANDLE;

#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Open the flash device
 * @param[out] pHandle - the field is a handle which be called by other function.
 * @param[in] parType - the field is a enum which indicates different flash data type.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_open(OFLASH_HANDLE * pHandle, OFLASH_PARTYPE parType);
/**
 * @brief Close the flash device
 * @param[out] pHandle - the field is a handle which points to opened flash device.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_close(OFLASH_HANDLE * pHandle);
/**
 * @brief Get the info from flash device
 * @param[out] pHandle - the field is a handle which points to opened flash device.
 * @param[out] pInfo - the field offers information of the flash .
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_getinfo(OFLASH_HANDLE * pHandle, intel_ce_flash_info_t * pInfo);
/**
 * @brief Read the length of data from flash device
 * @param[out] pHandle - the field is a handle which points to opened flash device.
 * @param[out] pDst - the field points a buffer as destination.
 * @param[in] length - the field means length of read data.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_read(OFLASH_HANDLE * pHandle, u8 * pDst, int length);
/**
 * @brief Write the data to the flash device
 * @param[out] pHandle - the field is a handle which points to opened flash device.
 * @param[in] pSrc - the field points a buffer as source data.
 * @param[in] length - the field means length of read data.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_write(OFLASH_HANDLE * pHandle, u8 * pSrc, int length);
/**
 * @brief The function repositions the offset of the open flash device.
 * @param[in] pHandle - the field is a handle which points to opened flash device.
 * @param[in] offset - the field points a position which will be visited.
 * @param[in] seek_type - the field is a type of seek method.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_seek(OFLASH_HANDLE * pHandle, int offset, OFLASH_SEEK_TYPE seek_type);
/**
 * @deprecated
 * @brief The function offers partitionsize which from the opened flash device.
 * @param[in] pHandle - the field is a handle which points to opened flash device.
 * @param[out] pParSize - the field is given as partitionsize
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_getpartitionsize(OFLASH_HANDLE * pHandle, int * pParSize);
/**
 * @deprecated
 * @brief The function offers partitiontype which from the opened flash device.
 * @param[in] pHandle - the field is a handle which is called by other function.
 * @param[out] pParType - the field is given as partition type.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_getpartitiontype(OFLASH_HANDLE * pHandle, OFLASH_PARTYPE * pParType);
/**
 * @deprecated
 * @brief The function offers currentoffset which from the opened flash device.
 * @param[out] pHandle - the field is a handle which is called by other function.
 * @param[out] pCurOffset - the field is given as current offset.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_getcurrentoffset(OFLASH_HANDLE * pHandle, int * pCurOffset);
/**
 * @brief The function offers read operation by secret mode.
 * @param[in] pHandle - the field is a handle which is called by other function.
 * @param[in] pDst - the field points a buffer which read data would be put.
 * @param[in] length - the field means length of read data.
 * @param[in] offset - the field points a position which will be visited.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_secret_read(OFLASH_HANDLE * pHandle, u8 * pDst, int length, int offset);
/**
 * @brief The function offers write operation by secret mode.
 * @param[in] pHandle - the field is a handle which is called by other function.
 * @param[in] pSrc - the field points a buffer as source data.
 * @param[in] length - the field means length of read data.
 * @param[in] offset - the field points a position which will be visited.
 * @retval OFLASH_STATUS 
 */
OFLASH_STATUS oflash_secret_write(OFLASH_HANDLE * pHandle, u8 * pSrc, int length, int offset);

/*@}*/ 
#ifdef __cplusplus
}
#endif

#endif
