/*------------------------------------------------------------------------------
 * File Name: dpe_common.h
 *------------------------------------------------------------------------------
 */
/* 
  
  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

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

  BSD LICENSE 

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
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

#ifndef _DPE_COMMON_H_
#define _DPE_COMMON_H_

  
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__i386__) || defined(__x86_64__)
#include "osal.h"
#else
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#ifdef WIN32
#define OS_PRINT	
#else
#define OS_PRINT(...) 
#endif
#endif

#ifdef FW
#define printf(...)
#endif

#include "ipc_shared.h"

/** @defgroup dpe_common_defs DPE Common Definitions */
/** @ingroup dpe_common_defs */
/*@{*/

/** This defines the maximum views supported in 3D stream. */
#define DPE_MAX_VIEWS_PER_STREAM          (2)

/** The invalid stream id */
#define DPE_INVALID_STREAM_ID             (0xFFFFFFFF)

/** This defines the maximum number of scaler filter tables per Y or UV. */
#define DPE_SCALER_TABLES_MAX             (150)

/** Default number of scaler coefficient tables for Y component. */
#define VPP_SCALER_DEFAULT_TABLES_Y       (150)

/** Default number of scaler coefficient tables for UV components. */
#define VPP_SCALER_DEFAULT_TABLES_UV      (150)

/** Default number of scaler coefficient phases for Y component.  This value
must be less than VPP_SCALER_PHASES_MAX defined in vpp_scaler.h */
#define VPP_SCALER_DEFAULT_PHASES_Y       (127)

/** Default number of scaler coefficient phases for UV components.  This
value must be less than VPP_SCALER_PHASES_MAX defined in vpp_scaler.h */
#define VPP_SCALER_DEFAULT_PHASES_UV      (127)

/** Default number of scaler coefficient taps for Y component.  This value
must be less than VPP_SCALER_TAPS_Y_MAX defined in vpp_scaler.h */
#define VPP_SCALER_DEFAULT_TAPS_Y         (9)

/** Default number of scaler coefficient taps for UV components.  This value
must be less than VPP_SCALER_TAPS_UV_MAX defined in vpp_scaler.h */
#define VPP_SCALER_DEFAULT_TAPS_UV        (5)

/** Size of packed, fixed-point coefficient table for Y component. */
#define VPP_SCALER_DEFAULT_TABLE_SIZE_Y   (VPP_SCALER_DEFAULT_PHASES_Y*4)

/** Size of packed, fixed-point coefficient table for UV component. */
#define VPP_SCALER_DEFAULT_TABLE_SIZE_UV  (VPP_SCALER_DEFAULT_PHASES_UV*2)

/** Default programmable weight for gen5 */
#define VPP_FW_MAD_PRE_DEFAULT 5
#define VPP_FW_MAD_POST_DEFAULT 0
#define VPP_FW_SAD_PRE1_DEFAULT 5
#define VPP_FW_SAD_PRE2_DEFAULT 5
#define VPP_FW_SAD_POST_DEFAULT 0


#define DPE_JLCCE_MAX_TABLE_INDEX 2

#ifdef FW
#define ALIGN_32BIT __attribute__((aligned(4)))
#else 
#define ALIGN_32BIT
#endif


/** This define specifies the mask that Control processor should append
    to physical address to access DDR memory.
    NOTE: The assumption is that we always set atr to 2.If not this needs to change.
**/
#ifndef WIN32
#define DPE_DDR_MEM_MASK    0x80000000
#else
#define DPE_DDR_MEM_MASK    0
#endif

/** This enumeration contains the silicon version. */
typedef enum {
   SI_VER_GEN3 = 0,
   SI_VER_GEN4 = 1,
   SI_VER_GEN5 = 2
} dpe_si_version_t;
extern dpe_si_version_t gbSiVersion;

/** This enumeration contains return codes for all DPE functions. */
typedef enum {
   DPE_RESULT_NOT_SUPPORTED,  /** Function is not supported. */
   DPE_RESULT_SUCCESS,        /** Function succeeded in execution. */
   DPE_RESULT_FAILURE,        /** Function failed in execution. */
   DPE_RESULT_INVALID_PARAM,  /** Function has invalid parameter(s). */
   DPE_RESULT_BUSY,           /** Function is still processing. */
   DPE_RESULT_SKIPPED,        /** Function is skipped. */
   DPE_RESULT_EMPTY,          /** Function tried to read buf when queue is empty */
   DPE_RESULT_FULL,           /** Function tried to write buf when queue is full */
   DPE_RESULT_TIMEOUT,        /** Failed to execute in allocated time */
   DPE_RESULT_MAX,            /** Maximum number of results. */
} dpe_result_t;

/** This enumeration lists the DPE units. */
typedef enum {
   DPE_UNIT_UNKNOWN,          /** Unidentified unit. */
   DPE_UNIT_CP,               /** Control processor. */
   DPE_UNIT_FGT,              /** Film grain technology unit. */
   DPE_UNIT_RNR,              /** Ring noise reduction unit. */
   DPE_UNIT_C422,             /** 4:2:0-to-4:2:2 conversion unit. */
   DPE_UNIT_DI,               /** De-interlacer unit. */
   DPE_UNIT_DI_SDI,           /** Spatial de-interlacer in de-interlacer. */
   DPE_UNIT_DI_MD,            /** Motion detection in de-interlacer. */
   DPE_UNIT_DI_FMD,           /** Film mode detection in de-interlacer. */
   DPE_UNIT_DI_NRF,           /** Noise reduction filter in de-interlacer. */
   DPE_UNIT_HSC,              /** Horizontal scaler unit. */
   DPE_UNIT_VSC,              /** Vertical scaler unit. */
   DPE_UNIT_DRTA_DWTA,        /** DRTA/DWTA unit. */
   DPE_UNIT_DMA,              /** Direct memory access unit. */
   DPE_UNIT_MAX               /** Maximum number of units. */
} dpe_unit_t;

/** This enumeration lists the state of a DPE unit. */
typedef enum {
   DPE_UNIT_DISABLE,          /** Unit is disabled. */
   DPE_UNIT_ENABLE,           /** Unit is enabled. */
   DPE_UNIT_BYPASS            /** Unit is bypassed. */
} dpe_unit_state_t;

/** This structure defines the Film Mode Cadence type. Used both in FW/driver */
typedef enum etDpeFmdCadence {
    etDpeCadProg = 0,
    etDpeCadDi,
    etDpeCad32,
    etDpeCad22,
    etDpeCad32322or23322,     /** In our FMD, cadence detection algorithm is same for 32322 and 23322 */
    etDpeCad2224or2332,       /** In our FMD, cadence detection algorithm is same for 2224 and 2332 */
    etDpeCad55,
    etDpeCad64,
    etDpeCad87,
    etDpeCadConflict,
    etDpeCadFL,
    etDpeCad33,
    etDpeCad44,
    etDpeCadEtc,
    etDpeCad32322,           /** In ADP FMD, cadence 32322 and 23322 are detected respectively */
    etDpeCad23322,           /** In ADP FMD, cadence 32322 and 23322 are detected respectively */
    etDpeCad2224,            /** In ADP FMD, cadence 2224 and 2332 are detected respectively */
    etDpeCad2332             /** In ADP FMD, cadence 2224 and 2332 are detected respectively */
} etDpeFmdCadence;

typedef enum {
   DPE_HW_NO_HANG = 0,
   DPE_HW_HANG_LINEAR_SCALE_FACTOR_INVALID,
   DPE_HW_HANG_ETC
} etDpeProcPictResult;

typedef enum 
{
   PACKING_2D,                         /*2D */
   PACKING_2DIN_SBS,                   /*2D- frames have side by side
                                                        * packing */
   PACKING_2DIN_TAB,                   /*2D- frames have top-bottom
                                                         * packing */
   PACKING_3DIN_SBS,                   /*3D- frames have side by side
                                                         * packing */
   PACKING_3DIN_TAB,                   /*3D- frames have top-bottom
                                                         * packing */
} dpe_frame_packing_format_t;

typedef enum etDpeFmdWeave {
    etDpeWeaveDi=0,
    etDpeWeavePrev,
    etDpeWeaveNext
} etDpeFmdWeave;

typedef enum  {
   DPE_JLCCE_INCSC_RGB_LUT = 0,
   DPE_JLCCE_INCSC_LMS_LUT,
   DPE_JLCCE_DC_LUT,
   DPE_JLCCE_OUT_RGB_LUT,
   DPE_JLCCE_OUT_LMS_LUT,
   DPE_JLCCE_LC_LUT,
   DPE_JLCCE_CHROMA_LUT,
   DPE_JLCCE_SIN_LUT,
   DPE_JLCCE_SQRT_LUT,
   DPE_JLCCE_DCE_GAIN_MAP,
   DPE_JLCCE_MAX_TABLE_ID
} dpe_jlcce_table_id_t;


/*@}*/
#ifdef __cplusplus
}
#endif

#endif
