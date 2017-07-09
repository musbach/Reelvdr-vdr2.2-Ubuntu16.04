/*==========================================================================
  This file is provided under a BSD license.  When using or 
  redistributing this file, you may do so under this license.

  BSD LICENSE 

  Copyright(c) 2005-2011 Intel Corporation. All rights reserved.
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
 =========================================================================*/

/*
 *  This file contains OS_ASSERT
 */

//! \file

/** \defgroup OSAL_ASSERT OSAL Assert macros
 *
 * <I> OSAL ASSERT macro </I>
 *\{*/

#ifndef _OSAL_ASSERT_H
#define _OSAL_ASSERT_H

#include "osal_config.h"
#include "osal_io.h"

// The following is only to get doxygen documentation, dont know of a better way
#define OS_ASSERT(x)
/**<
 * The OS_ASSERT() macro emulates the behavior of the standard C runtime
 * assert macro [For WinXP/Linux user mode]. If the preprocessor macro
 * NDEBUG is defined, the standard assert() macro compiles to nothing, but in
 * this implementation, if CONFIG_ERROR is defined, the OS_ASSERT() macro
 * prints a  message with the condition that failed the test.
 *
 * For Linux kernel mode, the behavior of the OS_ASSERT() macro depends on the
 * definition of 2 prepocessor macros - ASSERT_ON and ASSERT_LEVEL
 *
 * if ASSERT_ON is not defined, the OS_ASSERT macro has no effect.
 *
 * if ASSERT_ON is defined and the ASSERT_LEVEL is defined  WARN
 * {-DASSERT_LEVEL=WARN} the behavior of OS_ASSERT() is the same as the
 * behavior of the WARN_ON() macro defined in <asm/bug.h> 
 *
 * if ASSERT_ON is defined and the ASSERT_LEVEL is defined as BUG
 * {-DASSERT_LEVEL=BUG} the behavior of OS_ASSERT() is the same as the behavior
 * of the BUG_ON() macro defined in <asm/bug.h> 
 *
 * The default value of ASSERT_ON is WARN
 *
 * Please ignore the actual definition above, its this way to get doxygen to
 * generate the documentation
 */
#undef OS_ASSERT


#if defined (OSAL_LINUXUSER) || defined (OSAL_WINHANDHELD) || defined (OSAL_WIN32)
#include <assert.h>

#define OS_ASSERT(x) assert(x)
/**<
 * The OS_ASSERT() macro emulates the behavior of the standard C runtime
 * assert macro [For WinXP/Linux user mode]. If the preprocessor macro
 * NDEBUG is defined, the standard assert() macro compiles to nothing, but in
 * this implementation, if CONFIG_ERROR is defined, the OS_ASSERT() macro
 * prints a  message with the condition that failed the test.
 *
 * For Linux kernel mode, the behavior of the OS_ASSERT() macro depends on the
 * definition of 2 prepocessor macros - ASSERT_ON and ASSERT_LEVEL
 *
 * if ASSERT_ON is not defined, the OS_ASSERT macro has no effect.
 *
 * if ASSERT_ON is defined and the ASSERT_LEVEL is defined  WARN
 * {-DASSERT_LEVEL=WARN} the behavior of OS_ASSERT() is the same as the
 * behavior of the WARN_ON() macro defined in <asm/bug.h>
 *
 * if ASSERT_ON is defined and the ASSERT_LEVEL is defined as BUG
 * {-DASSERT_LEVEL=BUG} the behavior of OS_ASSERT() is the same as the behavior
 * of the BUG_ON() macro defined in <asm/bug.h>
 */

#ifdef NDEBUG //! Causes the assert macro to do nothing.
#undef  OS_ASSERT
#define OS_ASSERT(x) do { \
                if(!(x)) { \
                    OS_ERROR("%s %d:", __FILE__, __LINE__); \
                    OS_ERROR("Assertion '"); \
                OS_ERROR(#x); OS_ERROR("' failed\n");\
                }\
            } while(0)
#endif
#elif defined OSAL_LINUX
/*#include "os/osal_assert.h"*/
#include "/usr/src/reelbox/testing/packages/reelbox-devel-ice/ROOT/usr/include/intelce/linux/os/osal_assert.h"
///! temporary solution
#define assert OS_ASSERT
#else
#error "OSAL_XXXX not defined"
#endif

#endif
