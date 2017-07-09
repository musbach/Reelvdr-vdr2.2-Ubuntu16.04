/*
* File Name: ismd_vidpproc_core.h
*/

/*
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2007-2008 Intel Corporation. All rights reserved.
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

*/
#ifndef __ISMD_VIDPPROC_PVT_H__
#define __ISMD_VIDPPROC_PVT_H__

#include "ismd_global_defs.h"
#include "ismd_msg.h"

/*
Build Options
*/
#define VPP_USE_POWER_MANAGEMENT

/*
VPP_USE_GEN5 enables support for new "gen5" firmware interface. 
the is provided for compatibility and debug durring transition 
to gen5 fw and is expected to be removed after gen5 support is 
stable
*/
#define VPP_USE_GEN5

/*
VPP_USE_JLCCE enables support for JLCCE features partial support for 
some of these features exists but this is not yet stable
*/
//#define VPP_USE_JLCCE

/*
VPP_NEW_TABLE_API enables support the new table api
VPP_EXT_TABLE_API enables support the an extended api which is 
still under development
*/
#define VPP_NEW_TABLE_API

#ifdef VPP_NEW_TABLE_API
   //#define VPP_EXT_TABLE_API
#endif

/*
VPP_OLD_TABLE_API enables support the old table api
this api has major issues and will be removed soon
*/
#define VPP_OLD_TABLE_API

/*
VPP_USE_25D enables support for 2.5D mode 3D processing
*/
#define VPP_USE_25D

/*
VPP_USE_FMD_BYPASS enables film mode detection to be 
bypassed based on api settings
*/
#define VPP_USE_FMD_BYPASS

/*
VPP_USE_MAD_DISABLE allows motion adaptive DI disabled 
based on api settings
*/
#define VPP_USE_MAD_DISABLE

/*
VPP_USE_10_BIT_INPUT enables support for 10 bit input
*/
#define VPP_USE_10_BIT_INPUT

/*
VPP_USE_ASYNC_FW_RESULT allows the FW to report errors
on asyncronus results rather than hanging
*/
#define VPP_USE_ASYNC_FW_RESULT

/*
VPP_USE_ADP enables Advanced Display Processing specific features
*/
#define VPP_USE_ADP

/*
VPP_USE_CRITICAL_ERRORS enables reporting of major failures via the
"critical errors" infrastucture
*/
#define VPP_USE_CRITICAL_ERRORS

/* Trace and Debug */
//#define VERBOSE_DEBUG
//#define VPP_SVEN_TRACE
//#define VPP_TRACE
//#define VPP_TRACE_VERBOSE
//#define VPP_TRACE_API

#ifdef __cplusplus
extern "C" {
#endif

#define VPP_GLOBAL_PARAM_POWER_STATE (1)

/**
Unified function to set global parameters.

@param[in] parameter_id: which parameter to set
@param[in] parameter_value: what value to set

@retval ISMD_SUCCESS : The parameter was successfully set
@retval all other values: The parameter was not successfully set

@see ismd_dev_t
@see ismd_vidpproc_param_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_global_parameter( int parameter_id, int parameter_value );


#ifdef __cplusplus
}
#endif

#endif //__ISMD_VIDPPROC_PVT_H__


