/*
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2009 Intel Corporation. All rights reserved.
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

#ifndef __ISMD_BUFMON_H__
#define __ISMD_BUFMON_H__

#include <stdint.h>
#include "ismd_global_defs.h"
#include "ismd_msg.h"
#include "ismd_clock_recovery.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @weakgroup smd_bufmon  Buffering Monitor API/Structures */

/** @ingroup smd_bufmon */
/** @{ */

/**
Opens an instance of the buffering monitor device.  All of the ISMD events that
this instance of the buffering monitor uses are allocated at this time.
The handle returned is a standard ISMD device handle.  The buffering monitor
instance is in the ISMD_DEV_STATE_STOP state after allocation.

@param[out] bufmon_handle : Return pointer for the buffering monitor handle.

@retval ISMD_SUCCESS : Ihe instance of the buffering monitor was successfully
allocated.
@retval ISMD_ERROR_NULL_POINTER : bufmon_handle is NULL.
invalid.
@retval ISMD_ERROR_NO_RESOURCES : There are no more available instances
of the buffering monitor device, or there are no more events left in the system.
*/
ismd_result_t SMDCONNECTION ismd_bufmon_open( ismd_dev_t  *bufmon_handle );



/**
Access the event that the bufmon listens to for overrun events.  There is only
one such event per instance.  This event is meant to be registered with the
push source so that it may indicate when an overrun occurs.  The bufmon should
be the only subscriber to this event, clients should not wait on this event.
For client notification of overrun events, use the
ismd_bufmon_get_overrun_event() API.

The event returned should not be freed.

This is required for overrun detection and correction, but is not required
for underrun functionality.  This does not change any state in the bufmon.

This can be called in any state.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[out] push_src_overrun_event : Return pointer for the event that is meant
to be registered with the push source for signaling overrun events.

@retval ISMD_SUCCESS : Ihe push source overrun event was successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle.
@retval ISMD_ERROR_NULL_POINTER :  push_src_overrun_event is NULL.
*/
ismd_result_t SMDEXPORT ismd_bufmon_get_push_source_overrun_event(
                                          ismd_dev_t bufmon_handle,
                                          ismd_event_t *push_src_overrun_event );


/**
Add an ISMD renderer for the buffering monitor to listen for underruns from.
This function returns an ISMD event that is meant to be registered with the
specified renderer so that it may indicate when an underrun occurs.
The bufmon should be the only subscriber to this event, clients should not
wait on this event. For client notification of underrun events, use the
ismd_bufmon_get_underrun_event() API.

The event returned should not be freed.

The same renderer may only be added once.

Unique events will be returned for each renderer added.

If the renderer is to be closed, the ismd_bufmon_remove_renderer() API should
be used to prevent the bufmon from using the stale ISMD device handle.

This can be called in any state.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] renderer_handle : Handle to an ISMD renderer.  Specifically, this
should be an ISMD vidrend or ISMD audio input device.  The handle is used to
query the renderer for how late its input is in the event of an underrun.
@param[out] renderer_underrun_event : Return pointer for the event that is
meant to be registered with the renderer for signaling overrun events.

@retval ISMD_SUCCESS : Ihe renderer was successfully registered.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle or renderer_handle is not a
valid handle.
@retval ISMD_ERROR_NULL_POINTER :  renderer_underrun_event is NULL.
invalid.
@retval ISMD_ERROR_INVALID_REQUEST : renderer_handle has already been
registered.
@retval ISMD_ERROR_NO_RESOURCES : The maximum number of renderers have already
been registered.
*/
ismd_result_t SMDEXPORT ismd_bufmon_add_renderer(
                                          ismd_dev_t bufmon_handle,
                                          ismd_dev_t renderer_handle,
                                          ismd_event_t *renderer_underrun_event );

/**
Notifies the buffering monitor that the specified renderer, previously set with
ismd_bufmon_add_renderer(), should no longer be monitored.

The event that was previously used for this renderer should not be used after
this is called, unless it is obtained from another call to
ismd_bufmon_add_renderer();

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] renderer_handle : Handle to the ISMD reiderer to remove.
This renderer should have previously been set with ismd_bufmon_add_renderer();

@retval ISMD_SUCCESS : Ihe renderer was successfully registered.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle or renderer_handle is not a
valid handle.
@retval ISMD_ERROR_INVALID_REQUEST : renderer_handle is not currently
registered.
*/
ismd_result_t SMDEXPORT ismd_bufmon_remove_renderer(
                                          ismd_dev_t bufmon_handle,
                                          ismd_dev_t renderer_handle );


/**
Allow the client to specify an event for the bufmon to strobe when an underrun
has been detected.  This is meant to be listened to clients for informational
purposes.  This event is to be allocated by the client.
For getting the underrun event meant to be set on the renderers to signal
underrun to the buffering monitor, use the
ismd_bufmon_add_renderer() API.

The default value is ISMD_EVENT_HANDLE_INVALID.
Setting the value to ISMD_EVENT_HANDLE_INVALID disables this notification.

This can be called in any state.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] client_underrun_event : Event to strobe on underrun.

@retval ISMD_SUCCESS : Ihe client underrun event was successfully set.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle.
*/
ismd_result_t SMDEXPORT ismd_bufmon_set_underrun_event(
                                          ismd_dev_t bufmon_handle,
                                          ismd_event_t client_underrun_event );

/**
Allow the client to specify an event for the bufmon to strobe when an overrun
has been detected.  This is meant to be listened to clients for informational
purposes.  This event is to be allocated by the client.
For getting the overrun event meant to be set on the push source to signal
overrun to the buffering monitor, use the
ismd_bufmon_get_push_source_overrun_event() API.

The default value is ISMD_EVENT_HANDLE_INVALID.
Setting the value to ISMD_EVENT_HANDLE_INVALID disables this notification.

This can be called in any state.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] client_overrun_event : Event to strobe on overrun.

@retval ISMD_SUCCESS : Ihe client overrun event was successfully set.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle.
*/
ismd_result_t SMDEXPORT ismd_bufmon_set_overrun_event(
                                          ismd_dev_t bufmon_handle,
                                          ismd_event_t client_overrun_event );

/**
Allow the client to specify an event for the bufmon to strobe when an overrun
and underrun are happening at the same time.  This is meant to be listened to
by clients.  This event is to be allocated by the client.
If this event is being set, the pipeline is in a bad state and some action from
the client may be required to achieve playback.

The default value is ISMD_EVENT_HANDLE_INVALID.
Setting the value to ISMD_EVENT_HANDLE_INVALID disables this notification.

This can be called in any state.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] client_error_event : Event to strobe on error conditions.

@retval ISMD_SUCCESS : Ihe client error event was successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle.
*/
ismd_result_t SMDEXPORT ismd_bufmon_set_critical_error_event(
                                          ismd_dev_t bufmon_handle,
                                          ismd_event_t client_error_event );

/**
Sets the amount that the clock is adjusted backward by when an underrun is
detected.  This amount is in ADDITION to the worst lateness amount reported by
the renderers.  This basically specifies additional buffering needed above
what the renderers need at the instant the underrun occurred. This should be
set to something above 0 so that a second underrun doesn't occur shortly
after the first one.

This can be called in any state.

The default value is  1/5 of a second. (18000).

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] correction_amount : unsigned amount to use for correction,
in 90kHz clock ticks.

@retval ISMD_SUCCESS : Ihe correction amount was successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle.
*/

ismd_result_t SMDEXPORT ismd_bufmon_set_underrun_correction_amount(
                                          ismd_dev_t bufmon_handle,
                                          ismd_time_t correction_amount );

/**
Sets the amount that the clock is adjusted forward by when an overrun is
detected.  This basically specifies how much data should be dropped when
the buffers become totally full, to return the pipeline to the correct
buffering level.  If this quantity is not known by the client, it should
be set to a sufficiently large number to cause an underrun so the underrun
logic can return the pipeline to the correct level.  If this is set so 0 no
action is taken when a buffer overrun is detected.  Note that a small amount
here might produce smoother playback, but a subsequent overrun may occurr
quickly since the original condition that caused the overrun may still be
present.

This can be called in any state.

The default value is  1/5 of a second. (18000).

Note that port flushing may be needed for the pipeline to catch up, see the
ismd_bufmon_add_port_for_overrun_flush() API for more details.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] correction_amount : unsigned amount to use for correction,
in 90kHz clock ticks.

@retval ISMD_SUCCESS : Ihe correction amount was successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle.
*/
ismd_result_t SMDEXPORT ismd_bufmon_set_overrun_correction_amount(
                                          ismd_dev_t bufmon_handle,
                                          ismd_time_t correction_amount );


/**
Adds a port to the list of ports the buffering monitor will flush when an
overrun is detected.  The flush is used to help the pipeline "catch up" to the
correct play time after the buffering monitor has reduced the buffering by
moving forward in time.  The port is not owned by the buffering monitor and thus
the buffering monitor will never free it.  Subsequent calls append the port to
an internal list of ports to flush.  Typically this will be the ISMD viddec
input port.  For software pipelines, the software decoder should be flushed
instead  when the buffering monitor strobes the client overrun event.

The buffering monitor allows for the same port to be added multiple times,
although there is no practical reason to do this.  If this is done it must be
removed multiple times as well.

If the port is to be freed (by freeing its owning device), the
ismd_bufmon_remove_port_for_overrun_flush() API should be used to prevent the
bufmon from using the stale ISMD port handle.

This can be called in any state.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] port : Port to be added to the list.  Cannot be
ISMD_PORT_HANDLE_INVALID but any other value is legal.

@retval ISMD_SUCCESS : Ihe port was successfully added to the list.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle,
or port is ISMD_PORT_HANDLE_INVALID.
@retval ISMD_ERROR_NO_RESOURCES : The port list has already reached its maximum
allowed size.
*/
ismd_result_t SMDEXPORT ismd_bufmon_add_port_for_overrun_flush(
                                          ismd_dev_t bufmon_handle,
                                          ismd_port_handle_t port );


/**
Removes a port previously added with ismd_bufmon_add_port_for_overrun_flush().

This can be called in any state.


@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] port : Port to be removed to the list.  Cannot be
ISMD_PORT_HANDLE_INVALID but any other value is legal.
Should have been added previously with ismd_bufmon_add_port_for_overrun_flush()

@retval ISMD_SUCCESS : Ihe port was successfully removed from the list.
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle,
or port is ISMD_PORT_HANDLE_INVALID.
@retval ISMD_ERROR_INVALID_REQUEST : port is not currently in the list.
*/
ismd_result_t SMDEXPORT ismd_bufmon_remove_port_for_overrun_flush(
                                          ismd_dev_t bufmon_handle,
                                          ismd_port_handle_t port );

/**
Set clock sync to bufmon.
Bufmon will use this handle to reset clock recovery while bufmon detects
under run /over run and adjust STC.

@param[in] bufmon_handle : Handle to the bufmon instance, obtained with
ismd_bufmon_open().
@param[in] clock_sync_handle : Handle to clock recovery.

@retval ISMD_SUCCESS : clock sync handle is successfully set
@retval ISMD_ERROR_INVALID_HANDLE : bufmon_handle is not a valid bufmon handle,
or instance is not in use
*/
ismd_result_t SMDEXPORT ismd_bufmon_set_clock_sync(ismd_dev_t bufmon_handle,
                                           clock_sync_t  clock_sync_handle);

/**@}*/ // end of ingroup smd_bufmon

#ifdef __cplusplus
}
#endif

#endif  /* __ISMD_BUFMON_H__ */

