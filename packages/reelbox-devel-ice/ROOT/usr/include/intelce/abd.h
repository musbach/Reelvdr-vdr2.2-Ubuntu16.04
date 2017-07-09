//-----------------------------------------------------------------------------
// This file is provided under a dual BSD/GPLv2 license.  When using or
// redistributing this file, you may do so under either license.
//
// GPL LICENSE SUMMARY
//
// Copyright(c) 2007-2011  Intel Corporation. All rights reserved.
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
// Copyright(c) 2007-2011  Intel Corporation. All rights reserved.
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

#ifndef __ABD_H_
#define __ABD_H_

#include "gdl_types.h"
#include "gdl_pd.h"

/**
 * This enumeration describes HDMI devices available on current platform
 */
typedef enum
{
    GDL_HDMI_AUDIO_ID_0 = 555,
} gdl_hdmi_audio_device_id_t;

/**
 * This enumeration describes different buffer related events
 */
typedef enum
{
    GDL_HDMI_AUDIO_EVENT_EMPTY = 0,     ///< DMA stopped due to lack of samples
    GDL_HDMI_AUDIO_EVENT_TRANSFER_DONE, ///< DMA completed buffer transfer
    GDL_HDMI_AUDIO_EVENT_CLEAN_UP,      ///< DMA did not get to transferring buffer
    GDL_HDMI_AUDIO_EVENT_STOP_DONE,     ///< DMA has stopped [as requested]
    GDL_HDMI_AUDIO_EVENT_REJECT,        ///< DMA rejected buffer transfer
} gdl_hdmi_audio_event_t;

/**
 * Signature of function registered via abd_set_event_callback()
 *
 * @param [in] user_data - the cookie passed during call registration
 * @param [in] event     - incoming event
 * @param [in] id        - id of correspondent data transfer
 */
typedef void (*gdl_hdmi_event_cb_t)(void                   * user_data,
                                    gdl_hdmi_audio_event_t   event,
                                    unsigned int             id);

/**
 * Open a new instance of the HDMI device.
 *
 * @param [in] id
 * A platform-specific identifier that specifes the physical HDMI device to use.
 *
 * @param [out] handle
 * Handle to the new HDMI instance.
 *
 * @retval GDL_SUCCESS      - The new HDMI instance was successfully opened.
 * @retval GDL_ERR_FAILED   - Creation of new instance failed.
 * @retval GDL_ERR_NULL_ARG - Handle is NULL.
 */
gdl_ret_t abd_open(gdl_hdmi_audio_device_id_t id, void ** handle);

/**
 * Close an instance of HDMI device.
 *
 * @param [in] handle
 * Handle to the HDMI device to be closed
 *
 * @retval GDL_SUCCESS    - HDMI device was successfully closed
 * @retval GDL_ERR_HANDLE - Invalid handle
 */
gdl_ret_t abd_close(void * handle);

/**
 * Configure the behavior of the HDMI render buffer.
 *
 * @param [in] handle
 * Handle to an HDMI instance
 *
 * @param [in] user_data
 * Opaque data that the HDMI device will pass back to event_callback when one
 * of the events occurs.
 *
 * @param [in] event_callback
 * Function to call when the certain events occur within the HDMI device.
 *
 * @retval GDL_SUCCESS
 * The HDMI instance's stuff was successfully configured.
 *
 * @retval GDL_ERR_NULL_ARG
 * Values of event_callback is zero
 *
 * @retval GDL_ERR_HANDLE
 * Invalid handle
 */
gdl_ret_t abd_set_event_callback(void               * handle,
                                 gdl_hdmi_event_cb_t  event_callback,
                                 void               * user_data);

/**
 * Configure an HDMI Audio device instance. Resets channel status info set with
 * #abd_set_channel_status.
 *
 * @param [in] handle       - handle to an HDMI instance.
 * @param [in] format       - format
 * @param [in] num_channels - number of channels
 * @param [in] sample_rate  - sample rate
 * @param [in] sample_size  - sample size
 * @param [in] speaker_map  - speaker allocation map
 *
 * @retval GDL_SUCCESS
 * The HDMI instance was successfully configured.
 *
 * @retval GDL_ERR_HANDLE
 * The HDMI instance handle was invalid.
 *
 * @retval GDL_ERR_NO_HW_SUPPORT
 * Requested configuration is not supported by HDMI unit
 *
 * @retval GDL_ERR_FAILED
 * Configuration failed for some other reason
 */
gdl_ret_t abd_set_format(void                       * handle,
                         gdl_hdmi_audio_fmt_t         format,
                         unsigned int                 num_channels,
                         gdl_hdmi_audio_fs_t          sample_rate,
                         gdl_hdmi_audio_ss_t          sample_size,
                         gdl_hdmi_audio_speaker_map_t speaker_map);

/**
 * Start the HDMI device rendering.
 *
 * @param [in] handle  - handle to the HDMI instance.
 *
 * @retval GDL_SUCCESS    - The HDMI renderer was successfully started.
 * @retval GDL_ERR_HANDLE - The HDMI instance handle was invalid.
 * @retval GDL_ERR_FAILED - Configuration failed for some other reason
 */
gdl_ret_t abd_start(void * handle);

/**
 * Stopping the HDMI device from rendering.
 *
 * @param [in] handle  - handle to an HDMI instance.
 * @param [in] sync    - type of stop request.
 *                       GDL_TRUE  : call exits after DMA is stopped.
 *                       GDL_FALSE : call exits immediately. Upon DMA stop
 *                       GDL_HDMI_AUDIO_EVENT_STOP_DONE event is generated.
 *
 * @retval GDL_SUCCESS    - The HDMI renderer was successfully stopped.
 * @retval GDL_ERR_HANDLE - The HDMI instance handle was invalid.
 * @retval GDL_ERR_FAILED - Other kind of error occured
 */
gdl_ret_t abd_stop(void * handle, gdl_boolean_t sync);

/**
 * Reset the ABD interface to a fresh open state. After this call, it is
 * necessary to reprogram the callback and set the format.
 *
 * @param [in] handle  - handle to an HDMI instance.
 *
 * @retval GDL_SUCCESS     - The HDMI renderer was successfully reset and the
 *                           internal state is set to ABD_USE_STAGE_FORMAT.
 * @retval GDL_ERR_HANDLE  - The HDMI instance handle was invalid.
 * @retval GDL_ERR_FAILED  - Other kind of error occured
 * @retval GDL_ERR_TIMEOUT - Other kind of error occured
 */
gdl_ret_t abd_reset(void * handle);

/**
 * Write a buffer of data into the in the HDMI render buffer
 *
 * @param [in] handle    - handle to an HDMI instance.
 * @param [in] samples   - physical address of audio sample data
 * @param [in] silence   - physical address of audio silence data
 * @param [in] size      - size of audio sample data [must be aligned with
 *                         respect to sample width and number of channels]
 * @param [in] id        - id to be passed to callback once transfer is done
 *
 * @retval GDL_SUCCESS         - supplied samples were successfully written
 * @retval GDL_ERR_NULL_ARG    - address of supplied samples is NULL
 * @retval GDL_ERR_BUFFER_FULL - not enough room in the internal HDMI buffer
 * @retval GDL_ERR_HANDLE      - HDMI instance handle is invalid
 * @retval GDL_ERR_INVAL       - write size is not aligned with respect to
 *                               sample width and number of channels
 */
gdl_ret_t abd_write(void         * handle,
                    unsigned int   samples,
                    unsigned int   silence,
                    unsigned int   size,
                    unsigned int   id);

/**
 * Set 40 bit channel status info. Must be called at any time after #abd_set_format.
 * Note that:
 * - Sample length [bits 32:35], sampling frequency [bits 24:27], and format
 *   information [bit 1] will be ignored as HDMI driver fills it according to
 *   current format.
 * - Calling #abd_set_format resets channel status info set previosuly.
 *
 * @param [in] handle - handle to an HDMI instance
 * @param [in] lsw    - least significant word of channel status info
 * @param [in] msw    - most signoficant word of channel status info; only 8
 *                      lower bits are used
 *
 * @retval GDL_SUCCESS    - Channel status info has been accepted
 * @retval GDL_ERR_HANDLE - HDMI instance handle is invalid
 * @retval GDL_ERR_FAILED - Failure due to some other reason
 */
gdl_ret_t abd_set_channel_status(void         * handle,
                                 unsigned int   lsw,
                                 unsigned int   msw);

/**
 * Get 40 bit channel status info. Can be called at any time after #abd_set_format.
 * Note that:
 * - Sample length [bits 32:35], sampling frequency [bits 24:27], and format
 *   information [bit 1] will be ignored as HDMI driver fills it according to
 *   current format.
 *
 * @param [in]  handle - handle to an HDMI instance
 * @param [out] lsw    - least significant word of channel status info
 * @param [out] msw    - most signoficant word of channel status info; only 8
 *                       lower bits are used
 *
 * @retval GDL_SUCCESS    - Channel status info has been accepted
 * @retval GDL_ERR_HANDLE - HDMI instance handle is invalid
 * @retval GDL_ERR_FAILED - Failure due to some other reason
 */
gdl_ret_t abd_get_channel_status(void         * handle,
                                 unsigned int * lsw,
                                 unsigned int * msw);

#endif // __ABD_H_
