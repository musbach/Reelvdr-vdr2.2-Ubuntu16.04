/*
#
#  This file is provided under a BSD license.
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

/*
 * This file contains utils for converged OSAI. 
 */

#ifndef _SOC_UTILS_H
#define _SOC_UTILS_H

#include "cosai.h"

/*********************************************************
 * Utils for SoC Debugging                               
 *********************************************************/
#define __soc_get_fname (strrchr(__FILE__,'/') ? (const char *)(strrchr(__FILE__,'/')+1) : __FILE__ )

#define SOC_PRINT(fmt, ...)   cosai_print("[SOC]: " fmt, ##__VA_ARGS__)

/* simply following the DHG implementation and need to redefine to cosai_info */
#define SOC_INFO(fmt, ...)    \
        do { \
                cosai_error("%s:%s:", __soc_get_fname, __func__); \
                cosai_print(fmt, ##__VA_ARGS__); \
        } while (0)

#define SOC_ERROR(fmt, ...)   \
        do { \
                cosai_error("%s:%s:", __soc_get_fname, __func__); \
                cosai_print(fmt, ##__VA_ARGS__); \
        } while (0)

#define SOC_DEBUG(fmt, ...)   SOC_ERROR(fmt, ##__VA_ARGS__)

#ifndef DEBUG
#define DEBUG
#endif

#ifdef DEBUG // Assertion in debugging mode

#ifndef SOC_ASSERT_LEVEL
#define SOC_ASSERT_LEVEL 2
#endif

/*! SOC_ASSERT_LEVEL by default is set to WARN, this can be changed by passing
 *! in -DASSERT_LEVEL=2 */

#if (SOC_ASSERT_LEVEL == 2)
#define SOC_ASSERT(condition) cosai_bug_on(!(condition))
#elif (SOC_ASSERT_LEVEL == 1)
#define SOC_ASSERT(condition) cosai_warn_on(!(condition))
#endif

#else // !DEBUG
#define SOC_ASSERT(condition) do {} while(0) 
#endif // DEBUG

/*********************************************************
 * Utils for auto-reset event handling
 * 
 * This event has two modes: manual-reset and auto-reset.
 * Since Linux does not have this two-mode event, we implement
 * it here as a part of our upsteamable OSAI.
 *********************************************************/
typedef struct {
    cosai_waitqueue_t wait_queue;
    int manual_reset;
    cosai_mrevent_t signaled;
} soc_event_t;

extern void soc_init_event(soc_event_t *event, int manual_reset, int init_signaled);
extern void soc_set_event(soc_event_t *event);
extern void soc_destroy_event(soc_event_t *event);
extern void soc_reset_event(soc_event_t *event);

/* It returns Success when the signal is set, otherwise Time-out.
 * It also resets the event if auto-reset is
 * Retures: 1: Success
            0: Time-out */
extern int  soc_trywait_event(soc_event_t *event);

/* Retures: 1: Success
 *          0: Time-out
 *         -1: Interrupted
 */
extern int soc_wait_event(soc_event_t *event, unsigned long wait_ms, int interruptible);

/*********************************************************
 * Utils for PCI devices
 *********************************************************/
extern int soc_pci_enable_device(unsigned int vendor_id,
                                 unsigned int device_id);
#endif //_SOC_UTILS_H
