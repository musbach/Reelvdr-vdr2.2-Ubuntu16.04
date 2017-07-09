//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------

#ifndef __LIBAVCAP_H__
#define __LIBAVCAP_H__

#include "avcap.h"

#ifndef DOXYGEN_SKIP
    #ifndef __KERNEL__
    #define AVCAP_API __attribute__ ((visibility ("default")))
    #else
    #define AVCAP_API
    #endif
#else
    #define AVCAP_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __KERNEL__

#define avcap_open(reserved) avcap_open_version(AVCAP_VERSION)

/** @defgroup api_user API available in user space */

/**
 * @ingroup api_user
 *
 * Initializes the session and initiates communication with the AVCAP core
 * driver. Calls to any other AVCAP functions will fail until this call is made.
 * Must be called once per process. All threads in a process are then able to
 * use the AVCAP API.
 *
 * @param [in] version - AVCAP headers version. Must be set to AVCAP_VERSION.
 *
 * @retval AVCAP_SUCCESS
 * Communication session with AVCAP has been successfully initialized
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been determined between application and libavcap binaries.
 *
 * @retval AVCAP_ERR_NO_MEMORY
 * There is not enough memory to initialize communication session with AVCAP
 *
 * @retval AVCAP_ERR_FAILED
 * Initialization has failed for some other reason
 *
 * @note
 * User is encouraged to use avcap_open macro instead.
 *
 */
AVCAP_API
avcap_ret_t avcap_open_version(unsigned int version);


/**
 * @ingroup api_user
 *
 * Terminates the session with AVCAP core driver. Calls to any other AVCAP
 * functions will fail after this call is done.
 *
 * @retval AVCAP_ERR_FAILED
 * Close request has failed due to absence of successfull preceeding open request
 */
AVCAP_API
avcap_ret_t avcap_close(void);

#else

/** @defgroup api_kernel API available in kernel space */

/**
 * @ingroup api_kernel
 *
 * Registers AVCAP device with AVCAP core. Upon successful registration ID is
 * given back to user which should be used in all further interaction with this
 * AVCAP device. Until a client has a valid ID it should not attempt any
 * interaction with AVCAP core. The client can optionally request a set of
 * additional services by providing a valid pointer to the #avcap_service_t
 * structure
 *
 * @param [in]  client - Pointer to the structure describing AVCAP client
 * @param [out] id     - Caller provided buffer for ID assigned to the client
 * @param [out] srv    - Caller provided buffer for additional services
 *
 * @retval AVCAP_SUCCESS
 * AVCAP client has been registerd successfully.
 *
 * @retval AVCAP_ERR_NULL
 * One of the input arguments is NULL
 *
 * @retval AVCAP_ERR_FAILED
 * Given client has already been registered
 *
 * @retval AVCAP_ERR_INTERNAL
 * AVCAP client registration failed for some other reason
 *
 */
avcap_ret_t avcap_client_register(avcap_client_t  * client,
                                  unsigned int    * id,
                                  avcap_service_t * srv);


/**
 * @ingroup api_kernel
 *
 * Unregisters AVCAP device from AVCAP core.
 *
 * @param [in] id - ID of the client to unregister
 *
 * @retval AVCAP_SUCCESS
 * AVCAP client has been unregistered successfully
 *
 * @retval AVCAP_ERR_INVAL
 * Client ID is wrong.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Unregistration attempt failed due to some other reason
 */
avcap_ret_t avcap_client_unregister(unsigned int id);


/**
 * @ingroup api_kernel
 * 
 * Sends event to AVCAP core.
 *
 * @param [in] id    - ID of the client that sends an event
 * @param [in] event - Pointer to the event information
 * @param [in] flush - Flush indicator
 *
 * @note While flush argument indicates whether events of the same type already 
 * sitting in the event queue should be deleted or not, AVCAP core may override
 * this. Specifically, AVCAP core always flushes the following events:
 * - #AVCAP_EVENT_VIDEO_MODE_CHANGE
 * - #AVCAP_EVENT_AUDIO_MODE_CHANGE
 *
 * @retval AVCAP_SUCCESS
 * Event has been accepted by AVCAP core and eventually will be available to the
 * interested party via #avcap_event_recv call.
 *
 * @retval AVCAP_ERR_NULL
 * Pointer to the event information is NULL.
 *
 * @retval AVCAP_ERR_INVAL
 * Client ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * Event submission has failed due to lack of space in the internal event queue.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Event submission has failed for some other reason.
 *
 */
avcap_ret_t avcap_event_send(unsigned int    id,
                             avcap_event_t * event,
                             avcap_bool_t    flush);


/**
 * @ingroup api_kernel
 *
 * Retrieves buffer from AVCAP core. Should be used ONLY by AVCAP devices
 * that do not implement their own buffer management.
 *
 * @param [in]  id   - ID of AVCAP device requesting the buffer.
 * @param [in]  type - Type of the requested byffer.
 * @param [out] info - User provided pointer for buffer information.
 *
 * @retval AVCAP_SUCCESS
 * Buffer of requested type has been successfully obtained. Buffer information
 * has been placed into #avcap_buffer_info_t structure provided by user.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Buffer request has been rejected since given AVCAP device advertises its own
 * buffer management logic.
 *
 * @retval AVCAP_ERR_NULL
 * Pointer to user provided buffer is NULL.
 *
 * @retval AVCAP_ERR_INVAL
 * Client ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * There either no buffers available or given ID is wrong.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Buffer request has failed for some other reason.
 *
 */
avcap_ret_t avcap_buffer_get(unsigned int          id,
                             avcap_buffer_type_t   type,
                             avcap_buffer_info_t * info);

/**
 * @ingroup api_kernel
 *
 * Locks API access to given client. Intended for use strictly by client itself
 * to syncronize external requests with internal logic.
 *
 * @param [in] id - ID of AVCAP device to lock
 *
 */
avcap_ret_t avcap_client_lock(unsigned int id);

/**
 * @ingroup api_kernel
 *
 * Unlocks API access to given client. Intended for use strictly by client itself
 * to syncronize external requests with internal logic.
 *
 * @param [in] id - ID of AVCAP device to lock
 *
 */
avcap_ret_t avcap_client_unlock(unsigned int id);

#endif // __KERNEL__

/** @defgroup api_shared API availalbe in both user and kernel space */

/**
 * @ingroup api_shared
 *
 * Queries ID of the specified AVCAP device.This ID should be used in all
 * subsequent attempts to communicate to the device of interest.
 *
 * @param [in] name - Name of AVCAP device [same as was used during registration
 *                    via avcap_client_register].
 * @param [in] id   - User provided buffer for ID of the given AVCAP device.
 *
 * @retval AVCAP_SUCCESS
 * Device of interest was found and its ID has been stored in provided buffer
 *
 * @retval AVCAP_ERR_FAILED
 * Specified device has not been registered with AVCAP core
 *
 * @retval AVCAP_ERR_INTERNAL
 * ID query has failed for some other reason
 * 
 */
AVCAP_API
avcap_ret_t avcap_device_get_id(char * name, unsigned int * id);


/**
 * @ingroup api_shared
 *
 * Starts capture on the given AVCAP device.
 *
 * @param [in] id - ID of the device
 *
 * @retval AVCAP_SUCCESS
 * Capture has been successfully started.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * Start request has been rejected by the given device.
 *
 * @retval AVCAP_ERR_EVENTS_PENDING
 * There are unprocessed events in the device's queue which should be processed
 * before start can be initiated.
 *
 * @retval AVCAP_ERR_MODE_NOT_SET
 * There is no valid mode present at the moment
 *
 * @retval AVCAP_ERR_INTERNAL
 * Capture start has failed for some other reason.
 */
AVCAP_API
avcap_ret_t avcap_start(unsigned int id);


/**
 * @ingroup api_shared
 *
 * Stops capture on the given AVCAP device. Note that during a mode change 
 * given AVCAP device typically stops capture implicitly making it unnecessary
 * for an application to call stop explicitly. However if an application wants 
 * to terminate active capture then calling stop is the right thing to do.
 *
 * @param [in] id - ID of the device
 *
 * @retval AVCAP_SUCCESS
 * Capture has been stopped.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * Stop request has been rejected by the given device.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Capture stop has failed for some other reason.
 *
 */
AVCAP_API
avcap_ret_t avcap_stop(unsigned int id);


/**
 * @ingroup api_shared
 *
 * Sets video mode on the given AVCAP device.
 *
 * @param [in] id   - ID of the device
 * @param [in] mode - Pointer to the mode information
 *
 * @retval AVCAP_SUCCESS
 * Given mode has been successfully set.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device either does not support this operation or mode.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_NULL
 * Mode pointer is NULL.
 *
 * @retval AVCAP_ERR_FAILED
 * Mode setting request has been rejected by the given device.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Mode setting operation has failed for some other reasons
 *
 */
AVCAP_API
avcap_ret_t avcap_video_mode_set(unsigned int id, avcap_video_mode_t * mode);


/**
 * @ingroup api_shared
 *
 * Queries current video mode on the given AVCAP device.
 *
 * @param [in ] id   - ID of the device
 * @param [out] mode - User provided buffer for information about current mode
 *
 * @retval AVCAP_SUCCESS
 * Information about current mode has been queried successfully and is available
 * in the provided buffer
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_NULL
 * Mode structure pointer is NULL.
 *
 * @retval AVCAP_ERR_FAILED
 * Mode getting request has been rejected by the given device.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Mode getting operation has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_video_mode_get(unsigned int id, avcap_video_mode_t * mode);


/**
 * @ingroup api_shared
 *
 * Sets audio mode on the given AVCAP device.
 *
 * @param [in] id   - ID of the device
 * @param [in] mode - Pointer to the mode information
 *
 * @retval AVCAP_SUCCESS
 * Given mode has been successfully set.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device either does not support this operation or mode.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_NULL
 * Mode pointer is NULL.
 *
 * @retval AVCAP_ERR_FAILED
 * Mode setting request has been rejected by the given device.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Mode setting operation has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_audio_mode_set(unsigned int id, avcap_audio_mode_t * mode);


/**
 * @ingroup api_shared
 *
 * Queries current audio mode on the given AVCAP device
 * 
 * @param [in ] id   - ID of the device
 * @param [out] mode - User provided buffer for information about current mode
 *
 * @retval AVCAP_SUCCESS
 * Information about current mode has been queried successfully and is available
 * in the provided buffer
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_NULL
 * Mode structure pointer is NULL.
 *
 * @retval AVCAP_ERR_FAILED
 * Mode getting request has been rejected by the given device.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Mode getting operation has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_audio_mode_get(unsigned int id, avcap_audio_mode_t * mode);


/**
 * @ingroup api_shared
 *
 * Adds buffer to the given AVCAP device.
 *
 * @param [in] id   - ID of the device
 * @param [in] type - buffer type
 * @param [in] info - buffer information
 *
 * @retval AVCAP_SUCCESS
 * Buffer has been successfully added to the device's queue of buffers.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * Buffer has been rejected either by AVCAP core of by the device driver.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Buffer addition has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_buffer_add(unsigned int          id,
                             avcap_buffer_type_t   type,
                             avcap_buffer_info_t * info);


/**
 * @ingroup api_shared
 *
 * Removes all buffers of specified type used by the given AVCAP device.
 *
 * @warning
 * This call is intended for use with capture disabled. Use of this call
 * during active capture may yeild to unpredictable behavior.
 *
 * @param [in] id   - ID of the device
 * @param [in] type - Type of the buffers to cancell
 *
 * @retval AVCAP_SUCCESS
 * All buffers have been successfully removed from device's queue of buffers.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * Buffers cancellation request has been rejected either by AVCAP core of by the
 * device driver.
 *
 * @retval AVCAP_ERR_INTERNAL
 * Buffers cancellation has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_buffer_cancel_all(unsigned int id, avcap_buffer_type_t type);


/**
 * @ingroup api_shared
 *
 * Recieves for an event from the given AVCAP device. If there is no pending
 * event from given device, the call blocks and waits for one 
 * unless timeout paramater is non-zero.
 *
 * @param [in ] id    - ID of the device
 * @param [out] event - User provided buffer for event information 
 * @param [in]  timeout - timeout in milleseconds
 *
 * @retval AVCAP_SUCCESS
 * Event has been sucessfully received and placed into provided buffer.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_INVAL
 * Device ID is wrong.
 *
 * @retval AVCAP_ERR_FAILED
 * Event receiving request has been rejected by AVCAP core
 *
 * @retval AVCAP_ERR_INTERNAL
 * Event receiving has failed for some other reasons.
 *  
 * @retval AVCAP_ERR_TIMEOUT 
 * Event has not happened and timeout specified 
 *
 */
AVCAP_API
avcap_ret_t avcap_event_recv(unsigned int    id,
                             avcap_event_t * event, 
                             unsigned int    timeout);


/**
 * @ingroup api_shared
 *
 * Sends arbitrary data [up to #AVCAP_MAX_USER_DATA_SIZE bytes] to the given
 * AVCAP device.
 *
 * @param [in] id   - ID of the device
 * @param [in] type - Data type
 * @param [in] data - Data buffer
 * @param [in] size - Data size
 *
 * @retval AVCAP_SUCCESS
 * Data has been successfully submited to the specified device.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_INVAL
 * Either device ID is wrong or data size does not correspond to data type
 *
 * @retval AVCAP_ERR_FAILED
 * Data submission request was rejected by device driver
 *
 * @retval AVCAP_ERR_INTERNAL
 * Data submission has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_send(unsigned int   id,
                       avcap_send_t   type,
                       void         * data,
                       unsigned int   size);


/**
 * @ingroup api_shared
 *
 * Recieves arbitrary data [up to #AVCAP_MAX_USER_DATA_SIZE bytes] from the
 * given AVCAP device.
 *
 * @param [in]     id   - ID of the device
 * @param [in]     type - Data type
 * @param [in,out] data - Data buffer
 * @param [in]     size - Data size
 *
 * @retval AVCAP_SUCCESS
 * Data has been successfully received from the specified device and placed into
 * provided buffer.
 *
 * @retval AVCAP_ERR_VERSION
 * Version mismatch has been detected between AVCAP library and core driver.
 *
 * @retval AVCAP_ERR_NO_SUPPORT
 * Given AVCAP device does not support this operation.
 *
 * @retval AVCAP_ERR_INVAL
 * Either device ID is wrong or data size does not correspond to data type
 *
 * @retval AVCAP_ERR_FAILED
 * Data receiving request was rejected by device driver
 *
 * @retval AVCAP_ERR_INTERNAL
 * Data receiving has failed for some other reasons.
 *
 */
AVCAP_API
avcap_ret_t avcap_recv(unsigned int   id,
                       avcap_recv_t   type,
                       void         * data,
                       unsigned int   size);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_ret_t to string.
 *
 * @param [in] id - Identifier of avcap_ret_t
 *
 */
AVCAP_API
char * avcap_debug_string_return_code(avcap_ret_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_view_t to string.
 *
 * @param [in] id - Identifier of avcap_view_t
 *
 */
AVCAP_API
char * avcap_debug_string_view(avcap_view_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_buffer_type_t to string.
 *
 * @param [in] id - Identifier of avcap_buffer_type_t
 *
 */
AVCAP_API
char * avcap_debug_string_buffer_type(avcap_buffer_type_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_pixel_format_t to string.
 *
 * @param [in] id - Identifier of avcap_pixel_format_t
 *
 */
AVCAP_API
char * avcap_debug_string_pixel_format(avcap_pixel_format_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_par_t to string.
 *
 * @param [in] id - Identifier of avcap_par_t
 *
 */
AVCAP_API
char * avcap_debug_string_par(avcap_par_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_far_t to string.
 *
 * @param [in] id - Identifier of avcap_far_t
 *
 */
AVCAP_API
char * avcap_debug_string_far(avcap_far_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_color_space_t to string.
 *
 * @param [in] id - Identifier of avcap_color_space_t
 *
 */
AVCAP_API
char * avcap_debug_string_color_space(avcap_color_space_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_stereo_ext_data_t to string.
 *
 * @param [in] id - Identifier of avcap_stereo_ext_data_t
 *
 */
AVCAP_API
char * avcap_debug_string_stereo_ext_data(avcap_stereo_ext_data_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_stereo_t to string.
 *
 * @param [in] id - Identifier of avcap_stereo_t
 *
 */
AVCAP_API
char * avcap_debug_string_stereo(avcap_stereo_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_audio_format_t to string.
 *
 * @param [in] id - Identifier of avcap_audio_format_t
 *
 */
AVCAP_API
char * avcap_debug_string_audio_format(avcap_audio_format_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_mute_t to string.
 *
 * @param [in] id - Identifier of avcap_mute_t
 *
 */
AVCAP_API
char * avcap_debug_string_mute(avcap_mute_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_event_id_t to string.
 *
 * @param [in] id - Identifier of avcap_event_id_t
 *
 */
AVCAP_API
char * avcap_debug_string_event(avcap_event_id_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_signal_t to string.
 *
 * @param [in] id - Identifier of avcap_signal_t
 *
 */
AVCAP_API
char * avcap_debug_string_signal(avcap_signal_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_message_t to string.
 *
 * @param [in] id - Identifier of avcap_message_t
 *
 */
AVCAP_API
char * avcap_debug_string_message(avcap_message_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_send_t to string.
 *
 * @param [in] id - Identifier of avcap_send_t
 *
 */
AVCAP_API
char * avcap_debug_string_send(avcap_send_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_recv_t to string.
 *
 * @param [in] id - Identifier of avcap_recv_t
 *
 */
AVCAP_API
char * avcap_debug_string_recv(avcap_recv_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_data_source_t to string.
 *
 * @param [in] id - Identifier of avcap_data_source_t
 *
 */
AVCAP_API
char * avcap_debug_string_data_source(avcap_data_source_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_bus_standard_t to string.
 *
 * @param [in] id - Identifier of avcap_bus_standard_t
 *
 */
AVCAP_API
char * avcap_debug_string_bus_standart(avcap_bus_standard_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_notification_t to string.
 *
 * @param [in] id - Identifier of avcap_notification_t
 *
 */
AVCAP_API
char * avcap_debug_string_notification(avcap_notification_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_csc_clamp_t to string.
 *
 * @param [in] id - Identifier of avcap_csc_clamp_t
 *
 */
AVCAP_API
char * avcap_debug_string_csc_clamp(avcap_csc_clamp_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_bool_t to string.
 *
 * @param [in] id - Identifier of avcap_bool_t
 *
 */
AVCAP_API
char * avcap_debug_string_bool(avcap_bool_t id);

/**
 * @ingroup api_shared
 *
 * Converts identifier of type #avcap_quantization_t to string.
 *
 * @param [in] id - Identifier of avcap_quantization_t
 *
 */
AVCAP_API
char * avcap_debug_string_quantization(avcap_quantization_t id);

#ifdef __cplusplus
};
#endif

#endif // __LIBAVCAP_H__
