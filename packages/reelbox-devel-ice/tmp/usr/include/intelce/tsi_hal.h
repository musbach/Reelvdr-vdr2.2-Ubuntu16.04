/*
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
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

#include <stdbool.h>
#include <stdint.h>

#ifndef TSI_HAL_H
#define TSI_HAL_H

enum {
    TSI_HAL_SUCCESS = 0,
    TSI_HAL_INVALID_CONTEXT,
    TSI_HAL_FAILED,
    TSI_HAL_BAD_ARG,
    TSI_HAL_CALLBACK_IN_USE,
    TSI_HAL_INTERNAL_ERROR,
};

enum {
    TSI_CTX_0,
    TSI_CTX_1,
    TSI_CTX_2,
    TSI_CTX_3,
    TSI_CTX_MAX,
};


typedef enum {
	OC_MODE_SINGLE_STREAM = 0,
	OC_MODE_MULTIPLE_STREAM = 1
} oc_mode_t;

/**
@brief <H3></H3>
   Tsi registers to saved for power management
*/
typedef struct{

   /** Register offset */
   uint32_t reg_offset;

   /** Register length in bytes. */
   uint32_t reg_length; 
} tsi_register_t;

#define TSI_HAL_MAX_PIDS 32

// generate offset for different contexts; note this is intended to be used
// with an autoeas value, in particular the offset for context 0, so the
// value should be 0 for context 0
#define TSI_CONTEXT_OFFSET(x) (x * 0x4000)

/**
Initialize the TSI Hal.  Must be done before any other functions are called.
*/
int tsi_hal_init(void);


/**
Deinitialize the TSI Hal.  Cleans up any allocated resources.  No other
TSI HAL calls can be called other than tsi_hal_init() once this function
completes.
*/
int tsi_hal_deinit(void);


/**
Turn on or off a TSI input.

@param[in] tsi_context: Identifier for the TSI input
@param[in] enable:      True to turn on the input, false to turn it off

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
*/
int tsi_hal_enable(unsigned tsi_context, bool enable);


/**
Set the PID which carries PCR information for clock recovery

@param[in] tsi_context: Identifier for the TSI input
@param[in] pid:         ID of the packet stream containing the PCR

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          Limit reached on the number of added pids
*/
int tsi_hal_set_pcr_pid(unsigned tsi_context, uint16_t pid);


/**
Remove the PCR PID

@param[in] tsi_context: Identifier for the TSI input

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          No PCR PID set
*/
int tsi_hal_clear_pcr_pid(unsigned tsi_context);


/**
Add a pid to the list of pids allowed through the prefilter

@param[in] tsi_context: Identifier for the TSI input
@param[in] pid:         ID of the allowed packet stream

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          Limit reached on the number of added pids
*/
int tsi_hal_add_pid(unsigned tsi_context, uint16_t pid);


/**
Delete a pid from the list of pids allowed through the prefilter

@param[in] tsi_context: Identifier for the TSI input
@param[in] pid:         ID of the packet stream to delete

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          PID does not exist
*/
int tsi_hal_remove_pid(unsigned tsi_context, uint16_t pid);


/**
Determines the amount of data in a TSI input's output buffer

@param[in] tsi_context: Identifier for the TSI input
@param[out] buflevel:   Number of bytes in the prefilter's buffer

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
*/
int tsi_hal_get_buffer_level(unsigned tsi_context, unsigned *buflevel);


/**
Configures the TSI input's output circular buffer

@param[in] tsi_context: Identifier for the TSI input
@param[in] baseaddr:    Physical start address of the circular buffer
@param[in] size:        power of 2 size of the circular buffer
@param[in] remote_write_ptr: physical address the TSI input will send write
                        pointer updates to

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          baseaddr or size no power of 2 aligned
*/
int tsi_hal_set_buffer(unsigned tsi_context, unsigned long baseaddr, unsigned size,  unsigned long remote_write_ptr);


/**
Determine the TSI input's read pointer address.

@param[in] tsi_context: Identifier for the TSI input
@param[out] read_ptr:   physical address of the TSI input's read pointer
                        register

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
*/
int tsi_hal_get_read_ptr_addr(unsigned tsi_context, unsigned long *read_ptr);


/**
Invert the clock input signal the this TSI input

@param[in] tsi_context: Identifier for the TSI input
@param[in] invert:      true to flip the input signal, false to leave alone

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
*/
int tsi_hal_nim_invert_clock(unsigned tsi_context, bool invert);


/**
Invert the data valid input signal the this TSI input

@param[in] tsi_context: Identifier for the TSI input
@param[in] invert:      true to flip the input signal, false to leave alone

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
*/
int tsi_hal_nim_invert_data_valid(unsigned tsi_context, bool invert);


/**
Invert the clock input signal the this TSI input

@param[in] tsi_context: Identifier for the TSI input
@param[in] invert:      true to flip the input signal, false to leave alone

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
*/
int tsi_hal_nim_invert_sync(unsigned tsi_context, bool invert);

/**
Enable Bypass pid filter to allow all raw data through the prefilter

@param[in] tsi_context: Identifier for the TSI input

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          Limit reached on the number of added pids
*/
int tsi_hal_enable_bypass_pid_filter(unsigned tsi_context);

/**
Bypass pid filter to allow all raw data through the prefilter

@param[in] tsi_context: Identifier for the TSI input

@retval 0 :                       Success
@retval TSI_HAL_INVALID_CONTEXT : tsi_context is not a valid value
@retval TSI_HAL_FAILED :          Limit reached on the number of added pids
*/
int tsi_hal_disable_bypass_pid_filter(unsigned tsi_context);

/**
Specify a function to be called when PCR is encountered for a given TSI input

@param[in] context:  Identifier for the TSI input
@param[in] callback: the function to be called when a PCR is encountered

@retval 0:		Success
@retval TSI_HAL_CALLBACK_IN_USE: Callback already specified/active for the
	given context
@retval TSI_HAL_INVALID_CONTEXT: context out of range
@retval TSI_HAL_BAD_ARG: NULL callback
*/
int tsi_register_pcr_callback(unsigned int context,
   void (*callback)(unsigned int context, uint64_t pcr));


/**
Request the callback not be called anymore for the given context.

@param[in] context:  Identifies the TSI input which should have its callback
		     unregistered.

@retval 0:	Success
@retval TSI_HAL_INVALID_CONTEXT: context out of range
@retval TSI_HAL_BAD_ARG: no callback active for the specified context
*/
int tsi_unregister_pcr_callback(unsigned int context);

/*Enable Mpeg2 TS on 4th instance of prefilter . i.e. pf3*/
void pf3_enable_mpeg2ts(void);


/*To enable the OCEN bit in respective prefilter context */
int oc_enable(unsigned tsi_context);
int oc_disable(unsigned tsi_context);
int oc_mode(oc_mode_t mode);
int oc_enable_internal_bypass(void);
int oc_disable_internal_bypass(void);
int oc_discard_packets_with_bad_crc(unsigned tsi_context);
int oc_ignore_packets_with_bad_crc(unsigned tsi_context);
int oc_enable_header_removal(unsigned tsi_context);
int oc_disable_header_removal(unsigned tsi_context);
int oc_lts_enable(unsigned tsi_context);
int oc_lts_disable(unsigned tsi_context);
int oc_select_header(unsigned tsi_context);
int oc_get_ltsid(unsigned tsi_context, uint8_t *ltsid_ptr);
int oc_set_ltsid(unsigned tsi_context, uint32_t ltsid);
int oc_disable(unsigned tsi_context);;

/* Register access functions */
typedef void (*tsi_sven_event)( os_devhandle_t *devh,
   int              module_event_subtype,
   unsigned int     payload0,
   unsigned int     payload1,
   unsigned int     payload2,
   unsigned int     payload3,
   unsigned int     payload4,
   unsigned int     payload5 );

void tsi_register_sven_event( tsi_sven_event callback );
void tsi_SVEN_WriteModuleEvent( os_devhandle_t  *devh,
   int              module_event_subtype,
   unsigned int     payload0,
   unsigned int     payload1,
   unsigned int     payload2,
   unsigned int     payload3,
   unsigned int     payload4,
   unsigned int     payload5 );
uint32_t tsi_ReadReg32( os_devhandle_t *devh, uint32_t reg_offset );
void tsi_WriteReg32( os_devhandle_t *devh, uint32_t reg_offset, uint32_t value );
void tsi_OrBitsReg32( os_devhandle_t *devh, uint32_t reg_offset, uint32_t or_value );
void tsi_AndBitsReg32( os_devhandle_t *devh, uint32_t reg_offset, uint32_t and_value );
uint32_t tsi_ReadReg32_polling_mode( os_devhandle_t *devh, uint32_t reg_offset, uint32_t prev_value );

int tsi_hal_save_register_context(void);
int tsi_hal_restore_register_context(void);

#endif
