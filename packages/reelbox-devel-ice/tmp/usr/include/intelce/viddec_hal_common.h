
/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2011-2012 Intel Corporation. All rights reserved.

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
  Santa Clara, CA 97052

  BSD LICENSE

  Copyright(c) 20011-2012 Intel Corporation. All rights reserved.

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

#ifndef __VIDDEC_HAL_COMMON_H__
#define __VIDDEC_HAL_COMMON_H__

#include "ismd_global_defs.h"

/** viddec_hal_debug_level_t defines the debug levels to enable/disable
    the logging of debug messages.
    DEBUG_LEVEL_OFF    : no logging
    DEBUG_LEVEL_ON     : the debug information will be printed by VIDDEC_LOG.
    DEBUG_LEVEL_ERRORS : error message will be printed by VIDDEC_LOG
                         defined below.

    DEBUG_LEVEL_ON should be used to enable printing of any debug information.
    DEBUG_LEVEL_ERRORS should be used to print any error messages.
 */
typedef enum
{
   DEBUG_LEVEL_OFF     = 0,
   DEBUG_LEVEL_ON      = 1,
   DEBUG_LEVEL_ERRORS  = 2
} viddec_hal_debug_level_t;

/** This macro is used for printing debug messages
 */
#define VIDDEC_LOG(level, format...) if(level > DEBUG_LEVEL_OFF) OS_PRINT(format)


typedef enum {
   VIDDEC_MEM_PATH_COHERENT = 0,     /** Setting for viddec memory path is coherent with the IA*/
   VIDDEC_MEM_PATH_NON_COHERENT = 1  /** Setting for viddec memory path is not coherent with the IA (Fast Path, non-snooped)*/
}viddec_memory_path_t;


/* use to get the viddec memory path */
ismd_result_t 
viddec_hal_set_memory_path(viddec_memory_path_t mem_path);

#endif /* __VIDDEC_HAL_COMMON_H__*/

