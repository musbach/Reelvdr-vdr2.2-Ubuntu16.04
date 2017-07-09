//-----------------------------------------------------------------------------
// This file is provided under a dual BSD/GPLv2 license.  When using or
// redistributing this file, you may do so under either license.
//
// GPL LICENSE SUMMARY
//
// Copyright(c) 2009-2011 Intel Corporation. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
// The full GNU General Public License is included in this distribution
// in the file called LICENSE.GPL.
//
// Contact Information:
//      Intel Corporation
//      2200 Mission College Blvd.
//      Santa Clara, CA  97052
//
// BSD LICENSE
//
// Copyright(c) 2009-2011 Intel Corporation. All rights reserved.
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
//----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Header file to be included by all clients (drivers and applications) of
// power manager.
//------------------------------------------------------------------------------

#ifndef _INTEL_CE_PM_H_
#define _INTEL_CE_PM_H_

#ifndef DOXYGEN_SKIP /* DOXYGEN_SKIP only defined when docs are generated */
#define ICEPM_HEADER_VERSION_MAJOR    3
#define ICEPM_HEADER_VERSION_MINOR    0
#endif

#include "io8051EventMap.h"


/**@defgroup pwr        Power Management
 *
 * The Intel CE Power Management model supports four system states:
 *
 * - Full off. This is an initial state only.  The system performs a cold boot
 *   into Active as soon as external power is applied to the system.
 *
 * - Active. In this state the CPU has power and code is executing. All SoCs
 *   default to Full-On mode (all devices powered on) in Active state. Depending
 *   on the SoC, additional Standby modes may be supported.  In a Standby mode,
 *   a group of unused devices is powered off. The controlling system software
 *   uses the API #icepm_set_mode to request a transition from one supported
 *   Active power mode to another. The supported Active power modes for an SoC
 *   are defined in the platform/power/operational_modes section of its
 *   platform configuration file (found in /etc/plaform_config/).
 *
 * - Soft-off. In this state the system is powered down and all non-persistent
 *   state is lost. This state is entered by executing the Linux 'poweroff'
 *   command. A wake event in this state will cause the system to warm boot
 *   back to Active state.
 *
 * - Suspend-to-RAM (STR). In this state the system is powered down, but RAM is
 *   in self-refresh mode so all state is retained. This state is entered by
 *   executing the standard Linux STR sequence, i.e., by writing the string
 *   "mem" to /sys/power/state.  A wake event in this state will return the
 *   system to Active state, and execution of applications will resume where
 *   they left off.
 */

/** @ingroup pwr
 *
 * Events that can be returned to user space drivers that register a callback
 */
typedef enum
{
    ICEPM_EVT_SUSPEND,      ///< Driver should suspend for power off
    ICEPM_EVT_RESUME,       ///< Driver should resume from power off
    ICEPM_EVT_INTERRUPTED,  ///< Notification wait interrupted by signal
    ICEPM_EVT_ERROR         ///< Internal error (shuold not occur)
} icepm_event_t;


/** @ingroup pwr
 *
 * Values that can be returned by functions in the power management API.
 */
typedef enum
{
    ICEPM_OK,
        ///< Function executed without error.
    ICEPM_ERR_INTERNAL,
        ///< "Should not occur" error.
    ICEPM_ERR_INVALID_EVENT,
        ///< Undefined value of type IO_8051_wake_event_t passed to function.
        ///< Or deprecated function icepm_wake_reason() called and the wake
        ///< reason is not supported by that function.
    ICEPM_ERR_UNKNOWN_MODE,
        ///< Specified power mode not currently defined.
    ICEPM_ERR_INCOMPATIBLE,
        ///< Incompatible versions of library and kernel module are in use.
    ICEPM_ERR_NOMEM,
        ///< Memory allocation failed.
    ICEPM_ERR_MISSING_DEVICE,
        ///< User space library tried unsuccessfully to open /dev/intel_ce_pm.
    ICEPM_ERR_INCOMPLETE,
        ///< One or more device drivers could not be suspended or resumed.
        ///< The requested mode has been "partially" entered -- in the case of
        ///< power-lowering transition, devices controlled by the culpable
        ///< driver(s) are still active; in the case of a power-raising
        ///< transition, some expected devices are not active.
    ICEPM_ERR_NULL_PTR,
        ///< Null pointer passed for required argument.
    ICEPM_ERR_FAIL,
        ///< Call to external function failed.
    ICEPM_ERR_INVALID_TRANSITION,
        ///< Transition between current power state and requested power state
        ///< is not supported.
    ICEPM_ERR_DEV_BUSY
        ///< Driver could not be suspended.
} icepm_ret_t;


/** @ingroup pwr
 *
 * Wake events that can bring the SOC out of Soft Off or Suspend-to-RAM states.
 * Not all events can be generated on all SOCs.
 */
typedef enum
{
    ICEPM_WAKE_EVT_NONE = 0,
                ///< Used as a return value when no event is availble.
    ICEPM_WAKE_EVT_GPIO = 1,
                ///< Caused by whatever is wired to the WAKESM GPIO
    ICEPM_WAKE_EVT_IR   = 2,
                ///< Caused by IR remote (specific event determined by firmware)
    ICEPM_WAKE_EVT_CEC  = 4,
                ///< Caused by HDMI-CEC  (specific event determined by firmware)
    ICEPM_WAKE_EVT_RTC  = 8,
                ///< Caused by real-time clock alarm
} icepm_wake_event_t;


/** @ingroup pwr
 *
 * Signature of callback function registered by driver.
 *
 * The callback should take the necessary steps to handle the passed event, and
 * should return 0 on success, 1 on failure.
 *
 * The callback function is invoked asynchronously and should take the
 * necessary precautions to prevent contention for global data structures.
 *
 * Since suspend/resume calls to other drivers are delayed until the callback
 * function returns, it should complete its work and return as soon as possible.
 *
 * @param [in] event
 * Event of which the callback is being notified.
 *
 * In the case of ICEPM_EVT_SUSPEND, the driver should
 *  - Immediately return a value of 0 (success) if already in suspend state.
 *  - If the driver has "active" device instances (e.g., if a decoder is in
 *    paused or playing state), fail by returning 1.
 *  - Enter suspend state:
 *      - Reject (with an error return) any subsequent client requests.
 *      - Suspend threads, disable IRQs, disable hardware, etc., as
 *        necessary to completely prevent access to hardware.
 *      - Make sure all state needed to bring the device out of reset
 *        and back to the current state is stored in RAM.
 *  - Wait for outstanding transactions to/from the device to complete.
 *  - Call icepm_set_power_state( <drv name>, ICEPM_D3 ) to reduce
 *    power to the controlled devices.
 *  - Return 0 to caller.
 *
 * In the case of ICEPM_EVT_RESUME, the driver should
 *  - Immediately return a value of 0 (success) if already in active state.
 *  - Call icepm_set_power_state( <drv name>, ICEPM_D0 ) to restore
 *    power to the controlled devices.
 *  - Do whatever is necessary to re-discover changes in environment (e.g.,
 *    presence or absence of I/O devices).
 *  - Use stored state information to bring the device from reset to the state
 *    it was in when the suspend() function was called.
 *  - Resume threads, re-enable interrupt handlers, etc.
 *  - Allow normal processing of subsequent client requests.
 *  - If any error occurs after the call to icepm_set_power_state(),
 *    call icepm_set_power_state( <drv name>, ICEPM_D3 ) to return
 *    the controlled devices to low-power state.
 *  - Return 0 to caller.
 *
 * @param [in] cookie
 * The cookie passed by the driver when it registered this callback function.
 */
typedef int (* icepm_callback_t)(icepm_event_t event, void *cookie);

/** @ingroup pwr
 *
 * THIS FUNCTION IS INTENDED TO BE CALLED BY USER-SPACE DRIVERS ONLY
 *
 * Register a callback function to be invoked on power state changes.
 *
 * All Intel CE drivers affected by power management must:
 *  - call this function to register a callback during driver load-time
 *    initialization.
 *  - call this function with a NULL function pointer prior to shutting down.
 *
 * @param [in] func
 * A pointer to the callback function to be invoked when a power management
 * event occurs. If NULL, the driver is unregistered.
 *
 * @param [in] drv_name
 * A 0-terminated ASCII string identifying the driver.  The intel_ce_pm
 * component must specifically define and reserve a unique string for each
 * driver.
 *
 * @param [in] cookie
 * A pointer to any data structure that the driver would like to be passed
 * to the callback function when it is invoked.  May be NULL.
 */
icepm_ret_t icepm_register_callback( icepm_callback_t    func,
                                     char *              drv_name,
                                     void *              cookie);

/** @ingroup pwr
 *
 * Change the current active power mode.
 *
 * When the system is in Active state, all SoCs default to Full-On mode.  Some
 * SoCs also support one or more Standby states, in which the CPU is active but
 * unused subsystems may be powered off.  This function can be used by
 * controlling system software to move between Full-On and Standby states
 * supported by the target SoC.
 *
 * @param [in] mode_name
 * The name of the target power mode.  A 0-terminated ASCII string matching
 * one of the operational modes defined in the platform configuration file.
 */
icepm_ret_t icepm_set_mode(char *mode_name);


/** @ingroup pwr
 * <b>DEPRECATED</B>: call icepm_mask_wake_event() & icepm_unmask_wake_event()
 * instead.
 *
 * Masks off wake events.
 *
 * A wake event is an event that will bring the SOC out of a Suspend-to-RAM
 * (STR) or Soft Off state back to Active state. By default, all possible wake
 * events are enabled. The caller of this function specifies a set of wake
 * events to to be _ignored_ the next time the system goes into STR or
 * Soft Off.
 *
 * @param [in] events
 * The set of wake events to be ignored. This is a set of OR'd flags from the
 * enumeration icepm_wake_event_t.  If a previous call has already established
 * a set of ignored events, this set _replaces_ the old set (the sets are not
 * combined).  It is permissible for the set to contain events that are not
 * generated on the target SOC (it's easy to mask off an event that will never
 * occur).
 */
icepm_ret_t icepm_mask_wake_events(icepm_wake_event_t events);

/** @ingroup pwr
 * <b>DEPRECATED</B>: call icepm_get_wake_reason() instead.
 *
 * Returns the wake event that caused the last return from Suspend-to-RAM or
 * Soft Off state to Active state. (If multiple events occurred in close
 * prioximity, it will be the highest priority event).
 *
 * @param [out] event
 * The wake event that caused the last return from Suspend-to-RAM or
 * Soft Off state to Active state. If the last transition to Active state was a
 * cold boot, the returned value will be #ICEPM_WAKE_EVT_NONE.
 */
icepm_ret_t icepm_wake_reason(icepm_wake_event_t *event);

/** @ingroup pwr
 *
 * Adds the specified event to the list of currently masked wake events.
 *
 * A wake event is an event that will bring the SOC out of a Suspend-to-RAM
 * (STR) or Soft Off state back to Active state. A masked wake event will not
 * wake the system.
 *
 * @param [out] event
 * The wake event to be masked. If the event is IO_8051_WAKE_EVT_NONE, all
 * events will be <b>unmasked</b>.
 *
 * If the specified event is not implemented on the target board this call is a
 * no-op.
 */
icepm_ret_t icepm_mask_wake_event(IO_8051_wake_event_t event);

/** @ingroup pwr
 *
 * Removes the specified event from the list of currently masked wake events.
 *
 * A wake event is an event that will bring the SOC out of a Suspend-to-RAM
 * (STR) or Soft Off state back to Active state. A masked wake event will not
 * wake the system.
 *
 * @param [out] event
 * The wake event to be unmasked. If the event is IO_8051_WAKE_EVT_NONE, all
 * events will be <b>masked</b>. This is useful for initializing the mask list
 * prior to unmasking individual events, but the the system should not normally
 * enter Soft Off or Suspend-to-RAM state with this mask set.
 *
 * If the specified event is not implemented on the target board this call is a
 * no-op.
 */
icepm_ret_t icepm_unmask_wake_event(IO_8051_wake_event_t event);

/** @ingroup pwr
 *
 * Returns the wake event that caused the last return to Active state from
 * Suspend-to-RAM or Soft Off state. (If multiple events occurred in close
 * prioximity, it will be the highest priority event).
 *
 * @param [out] event
 * The wake event that caused the last return to Active state from
 * Suspend-to-RAM or Soft Off state. If the last transition to Active state was
 * a cold boot (first application of power to the system), the returned value
 * will be #ICEPM_WAKE_EVT_NONE.
 */
icepm_ret_t icepm_get_wake_reason(IO_8051_wake_event_t *event);

#endif // _INTEL_CE_PM_H_
