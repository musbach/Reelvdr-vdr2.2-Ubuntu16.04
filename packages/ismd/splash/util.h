//-----------------------------------------------------------------------------
// BSD LICENSE
//
// Copyright(c) 2006-2011 Intel Corporation. All rights reserved.
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
//-----------------------------------------------------------------------------

#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stdlib.h>

#include <libgdl.h>
#include "util_ImagePNG.h"
#include "util_Surfaces.h"
#include "util_TvMode.h"
#include "util_VDR.h"

#if defined(__cplusplus)
extern "C" {
#endif

gdl_ret_t check(int exitOnFailure, gdl_ret_t gdl_rc, const char *file, int line);

/* Check GDL return code. If it indicates error, print message with filename
 * and line numbers.  Return the GDL return code to the caller.
 */
#define CHK(gdl_rc) check(0,gdl_rc,__BASE_FILE__,__LINE__)

/* Like CHK, but fatal: after printing error message, call exit() instead
 * of returning to caller.
 */
#define CHKF(gdl_rc) check(1,gdl_rc,__BASE_FILE__,__LINE__)

/* Like CHK, but when error message is printed control is transferred
 * to LABEL and nothing is returned to caller
 */
#define ON_ERR(LABEL,gdl_rc)                                \
    if (GDL_SUCCESS != check(0,gdl_rc,__BASE_FILE__,__LINE__))   \
    {                                                       \
        goto LABEL;                                         \
    }

/* Timing */
void   start_timing(void);  // Begin a timing interval
double end_timing(void);    // Return # seconds since start_timing() last called

#if defined(__cplusplus)
};
#endif

#endif /* __UTIL_H__ */
