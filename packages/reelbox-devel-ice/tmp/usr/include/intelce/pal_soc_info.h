/* =================================================================== 
This file is provided under BSD license.  When using or 
redistributing this file, you may do so under this license.

BSD LICENSE 

Copyright(c) 2009-2011 Intel Corporation. All rights reserved.
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

=====================================================================*/
//! \file
//! This file contains definitions that are common to all the platform abstraction functions.
#ifndef CE_PAL_SOC_INFO_H
#define CE_PAL_SOC_INFO_H 1
/** @ingroup PAL_ */
/*@{*/
typedef enum 
{
    SOC_GENERATION_3 = 1, /**< Generation 3 */
    SOC_GENERATION_4,/**< Generation 4 */
    SOC_GENERATION_5,/**< Generation 5 */
    SOC_GENERATION_5300,/**< Generation 5300 */
    SOC_GENERATION_MAX /**< For enum check */
} pal_soc_generation_t;

typedef enum
{
   SOC_NAME_CE3100 = 1,/**< SOC CE3100 */
   SOC_NAME_CE4100,/**< SOC CE4100 */
   SOC_NAME_CE4200,/**< SOC CE4200 */
   SOC_NAME_CE5300 /**< SOC CE5300 */
} pal_soc_name_t;

typedef enum
{
   SOC_STEPPING_A0 = 1,
   SOC_STEPPING_A1,
   SOC_STEPPING_A2,
   SOC_STEPPING_A3,
   SOC_STEPPING_A4,
   SOC_STEPPING_A5,
   SOC_STEPPING_A6,
   SOC_STEPPING_A7,
   SOC_STEPPING_A8,
   SOC_STEPPING_A9,
   SOC_STEPPING_B0,
   SOC_STEPPING_B1,
   SOC_STEPPING_B2,
   SOC_STEPPING_B3,
   SOC_STEPPING_B4,
   SOC_STEPPING_B5,
   SOC_STEPPING_B6,
   SOC_STEPPING_B7,
   SOC_STEPPING_B8,
   SOC_STEPPING_B9,
   SOC_STEPPING_C0,
   SOC_STEPPING_C1,
   SOC_STEPPING_C2,
   SOC_STEPPING_C3,
   SOC_STEPPING_C4,
   SOC_STEPPING_C5,
   SOC_STEPPING_C6,
   SOC_STEPPING_C7,
   SOC_STEPPING_C8,
   SOC_STEPPING_C9,
   SOC_STEPPING_D0,
   SOC_STEPPING_XX
} pal_soc_stepping_t;

typedef struct _pal_soc_info_t
{
   pal_soc_generation_t generation; /**< The SOC belongs to which generation. */
   pal_soc_name_t name; /**< SOC name */
   pal_soc_stepping_t stepping; /**< The SOC belongs to which stepping. */
} pal_soc_info_t;

typedef struct _soc_user_info
{
   char generation[32];
   int  gen_enum;
   char name[32];
   int  name_enum;
} soc_user_info_t;

int
system_utils_get_soc_info( soc_user_info_t *info );

#define SOC_VERSION(generation, name, stepping) ((generation<<16) | (name<<8) | (stepping)) 
/*@}*/
#endif
