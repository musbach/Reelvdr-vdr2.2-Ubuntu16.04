/*
#
#  This file is provided under a BSD license.  When using or
#  redistributing this file, you may do so under this license.
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

/*------------------------------------------------------------------------------
 * File Name: idl.h
 *------------------------------------------------------------------------------
 *
*/

#ifndef _IDL_H_
#define _IDL_H_

#ifdef __cplusplus
extern "C" {
#endif



//! \file
/** @defgroup idl_ IDL Main Header File */
/** @ingroup idl_ */
/*@{*/

#ifndef IDL_DRIVER
#include <stdint.h>
#include <stdbool.h>
#else
//#include "osal.h"
//#include "pal.h"
#endif

/**
This enumeration contains return codes for all IDL functions.
*/
typedef enum {
	IDL_SUCCESS              = 0x1000, /**< 0x1000 - The field indicates that the function operated successfully. */ 
	IDL_FIRST_ERROR          = IDL_SUCCESS, /**< The field is not used in the current IDL Driver. */
	IDL_INVALID_PARAM        = 0x1001, /**< 0x1001 -  The field indicates the function was given an invalid parameter. */
	IDL_NOT_INITIALIZED      = 0x1002, /**< 0x1002 -  The field indicates that the driver is not initialized. */
	IDL_ALREADY_INITIALIZED  = 0x1003, /**< 0x1003 -  The field indicates that the driver is already initialized. */
	IDL_FAILURE              = 0x1004, /**< 0x1004 -  The field indicates that the function operation failed */
	IDL_NO_MEDIA             = 0x1005, /**< 0x1005 - The field indicates that there is no media. */
	IDL_NOT_IMPLEMENTED      = 0x1006, /**< 0x1006 - The field indicates the required function is not implemented. */
	IDL_DEVICE_BUSY          = 0x1007, /**< 0x1007 - The field indicates that the hardware is busy. */
	IDL_NO_RESOURCES         = 0x1008, /**< 0x1008 - The field indicates that there is no resource. */
	IDL_TIMED_OUT            = 0x1009, /**< 0x1009 - The field indicates time out. */
	IDL_LAST_ERROR           = IDL_TIMED_OUT /**< 0x1009 - The field is currently equal to time out. */
} idl_result_t;

/**
*
* @param[in] idl_errnum is the IDL Result "error" value that
             you want an English text string description for.
* @retval *char_string a pointer to a char string that describes the IDL Result.
*
<BR>
* For IDL_SUCCESS             "IDL Success"
<BR>
* For IDL_INVALID_PARAM       "IDL Invalid Parameter"
<BR>
* For IDL_NOT_INITIALIZED     "IDL Not Initialized"
<BR>
* For IDL_ALREADY_INITIALIZED "IDL Already Initialized"
<BR>
* For IDL_FAILURE             "IDL Failure"
<BR>
* For IDL_NO_MEDIA            "IDL No Media"
<BR>
* For IDL_NOT_IMPLEMENTED     "IDL Not Implemented"
<BR>
* For IDL_DEVICE_BUSY         "IDL Device Busy"
<BR>
* For IDL_NO_RESOURCES        "IDL No Resources"
<BR>
* For IDL_TIMED_OUT           "IDL Timed Out"
<BR>
* For all others              "Unknown IDL ERROR!"
<BR>

*/
const char *idlerror(int idl_errnum);

/*
This macro is used to read from a 32-bit register.
@param[in] addr Address of the 32-bit register.
@retval 32-bit data read from the specified register address (addr).
*/

#define IDL_REG32_READ(addr)           (_OS_READ32(addr))

//here is io space operations, should put appropriate 
//#define IDL_REG_READ_IO(addr)		(inl_p(addr))
//#define IDL_REG_WRITE_IO(addr, val)		(out_p(val,addr))
//#define IDL_REG_READ_IO(addr)		(_OS_READ32(addr)) 
//#define IDL_REG_WRITE_IO(addr, val)		(_OS_WRITE32(val,addr))
/*
This macro is used to write to a 32-bit register.
@param[in] addr Address of the 32-bit register.
@param[in] val 32-bit data to write to the specified register address (addr).
*/

#define IDL_REG32_WRITE(addr, val)     (_OS_WRITE32(val,addr))

/*
This macro is used to read from a 8-bit register.
@param[in] addr Address of the 8-bit register.
@retval 8-bit data from specified register address (addr).
*/

#define IDL_REG8_READ(addr)            (_OS_READ8(addr))

/*
This macro is used to write to a 8-bit register.
@param[in] addr Address of the 8-bit register.
@param[in] val 8-bit data to write to the specified register address (addr).
*/

#define IDL_REG8_WRITE(addr, val)      (_OS_WRITE8(val,addr))

/*@}*/

#ifdef __cplusplus
}
#endif

#endif

