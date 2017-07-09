/*
  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2010 Intel Corporation. All rights reserved.
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

/*
 * This file contains the enumerations and function declarations that
 * comprise the the VIDSINK APIs.
 */

#ifndef __ISMD_VIDSINK_H__
#define __ISMD_VIDSINK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_global_defs.h"


/** @weakgroup ismd_vidsink Dynamic Scaling Processing  API/Structures

<H3>Overview</H3>

The vidsink component is an user-space library. It will be linked into SMD pipeline,
and work as a combined component of Video Postprocessor and Video Render. User application can
use this wrapper component to change the scaling and position parameters on
per-frame basis.

<H3>Pipeline Creation</H3>

Application will create and configure Video Postprocessor and Vidrend instances, and give the
handles to vidsink component. Video Postprocessor and Video Render will not be linked into pipeline.

<H3>Normal Animation</H3>

This mode works for customers who don't need strict frame-by-frame animation
control, and wants easy App implementation. After pipeline is built, application
can do animation by periodically calling
\ref ismd_vidsink_set_global_scaling_params()

<H3>Frame-by-Frame Animation</H3>

This is the advanced mode compared to the normal mode. In this mode,
application need to start a thread to intercept every buffer out of the video source,
then it can call a vidsink API to change its scaling parameters, and send it to
vidsink component. So every frame can be scaled by different scaling parameters.

When pipeline is built, application needs to attach event for video source output port,
and get the input event from vidsink. It also needs to start a thread to handle per
frame animation.

<H3>Animation When Paused</H3>

With vidsink component, app can do animation when the pipeline is in paused state.
It works for both normal and frame-by-frame mode.

Application can scale paused frame multiple times. In vidsink design, the original picture
of current display frame will be re-scaled, so the picture quality will not be degraded.
Application can do this paused animation by calling
\ref ismd_vidsink_set_global_scaling_params()

 <H3>DPE bypass mode</H3>

 Vidsink supports bypassing vidpproc. This is only for the video capture use case.
 The vidsink component will, if initialized without a "vidpproc" handle, continue to
 function but without sending input frame buffers through the DPE (vidpproc) driver.


 */

/** @ingroup ismd_vidsink */
/** @{ */



/** Handles for vidsink component */
typedef int ismd_vidsink_dev_t;

/** Destination rectangle structure */
typedef struct {
   unsigned int width;
   unsigned int height;
   unsigned int x;
   unsigned int y;
} dest_rect_t;

/**
* Structure for scaling parameters
*/
typedef struct {
   ismd_cropping_window_t  crop_window;    /**< Cropping window offset and size.
                                               If no cropping, offset is 0,0
                                               and size is same as content size. */

   bool                    crop_enable; /**< The cropping is enabled or disabled. */

   dest_rect_t             dest_window;   /**< Pixel origin and dimensions for the
                                                destination of the frame
                                                (usually a video canvas). */

   ismd_aspect_ratio_t     aspect_ratio;  /**< Aspect ratio */

   int                     scaling_policy; /**< The scaling policy for vidpproc. Please
                                             refer to ismd_vidpproc_scaling_policy_t
                                             defined in ismd_vidpproc.h. */


} ismd_vidsink_scale_params_t;

/**
enum ismd_vidsink_flush_policy_t
To determine vidsink behavior on flush.
*/
typedef enum {
   ISMD_VIDSINK_FLUSH_POLICY_INVALID,       // invalid value
   ISMD_VIDSINK_FLUSH_POLICY_REPEAT_FRAME,  ///< repeat last frame/field
   ISMD_VIDSINK_FLUSH_POLICY_DISPLAY_BLACK, ///< send black frame/field
} ismd_vidsink_flush_policy_t;

/**
* Opens a vidsink instance if one is available.
*
* @param[out] handle         : handle to vidsink instance
*
* @return ismd_result_t                 Success / Failure indication.
*
* @retval ISMD_SUCCESS                          : Instance open successfull.
* @retval ISMD_ERROR_NO_RESOURCES               : No free instance available.
* @retval ISMD_ERROR_OPERATION_FAILED           : No free instance available.
* @retval ISMD_ERROR_NULL_POINTER               : The device handle provided at input is NULL.
*/
ismd_result_t ismd_vidsink_open(ismd_vidsink_dev_t *handle);

/**
* Set the state of vidsink component.
*
* @param[in] handle: handle to vidsink instance.
* @param[in] state  : State to transition to.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The state is changed successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid state provided.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_state(ismd_vidsink_dev_t handle,
                                   ismd_dev_state_t state);

/**
* This function will set the output port of video source device to vidsink instance.
* vidsink component will use this port to read out the buffers from upstream devices.
*
* @param[in] handle: handle to vidsink instance.
* @param[in] port   : handle of the output port of video source device.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The port is set successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid port provided.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_source_port(ismd_vidsink_dev_t handle,
                           ismd_port_handle_t port) ;


/**
* This function will get the input port of vidsink device.
* vidsink component will use this port to read the buffers from upstream devices.
*
* Before use this API, ismd_vidsink_open should be called to initialize the needed resource successfully.
* Otherwise, this API may return ISMD_ERROR_OPERATION_FAILED.
*
* @param[in] handle: handle to vidsink instance.
* @param[out] port   : handle of the input port of vidsink device.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Input port handle sucessfully gotten.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_NULL_POINTER      : Null port handle is provided.
* @retval ISMD_ERROR_OPERATION_FAILED  : Fail to get the input port due to the device
*     has not been opened correctly (ismd_vidsink_open should return ISMD_SUCCESS).
*
*/
ismd_result_t ismd_vidsink_get_input_port(ismd_vidsink_dev_t handle,
                           ismd_port_handle_t* port) ;

/**
* This function will set the vidpproc and vidrend handle to vidsink instance.
* ismd_vidsink component will configure vidpproc and vidrend to do the scaling and display.
*
* @param[in] dev           : handle to vidsink instance.
* @param[in] vidpproc_handle   : handle of the vidpproc instance.
* @param[in] vidrend_handle   : handle of the vidrend instance.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The instance was changed successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid parameters provided.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_smd_handles(ismd_vidsink_dev_t dev,
                           ismd_dev_t vidpproc_handle,
                           ismd_dev_t vidrend_handle);

/**
* This function will get the vidpproc and vidrend handles from vidsink instance.
*
* @param[in] dev           : handle to vidsink instance.
* @param[out] vidpproc_handle   : handle of the vidpproc instance.
* @param[out] vidrend_handle   : handle of the vidrend instance.

* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The handle is get successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid parameters provided.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_get_smd_handles(ismd_vidsink_dev_t dev,
                           ismd_dev_t *vidpproc_handle,
                           ismd_dev_t *vidrend_handle);


/**
* This function is a wrapper function which calls vidpproc or vidrend related functions.
*
* @param[in] dev: handle to vidsink instance.
* @param[in] clock  : clock handle to set into vidrend.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The clock is set successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_clock( ismd_vidsink_dev_t  dev, ismd_clock_t clock );


/**
* This function is a wrapper function which calls vidpproc or vidrend related functions.
*
* @param[in] dev: handle to vidsink instance.
* @param[in] basetime  : base time value to set into vidrend.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The base time was set successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid base time provided.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_base_time( ismd_vidsink_dev_t  dev, ismd_time_t basetime );


/**
* This function sends frame/field with the given presentation timestamp to the display.
* All undisplayed frames/fields in the renderer, whose linear_pts that are <=
* (or > in the case the system is in reverse mode) the given pts, are dropped.
* The linear_pts value is specified in units of 90 KHz clock ticks.
*
* @param[in] dev: handle to vidsink instance.
* @param[in] linear_pts : rebased pts of the frame to be displayed.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS : The renderer is successfully advanced to given pts.
* @retval ISMD_ERROR_INVALID_HANDLE : Invalid device handle.
* @retval ISMD_ERROR_INVALID_REQUEST : The renderer is not started and paused.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
* @retval ISMD_ERROR_INVALID_PARAMETER : The linear_pts is not valid. A pts
* is not valid if it is < than the current position for forward frame advance or
* > than the current position for reverse.
*
*/
ismd_result_t ismd_vidsink_advance_to_pts( ismd_vidsink_dev_t  dev, ismd_time_t linear_pts );


/**
* This function is a wrapper function which calls vidpproc or vidrend related functions.
*
* @param[in] dev: handle to vidsink instance.
* @param[in] rate : rate to play the video normalized to 10000.
* @param[in] linear_rate_change_time : linear local time when the rate change is to be applied
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : The play rate was changed successfully.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid parameters provided.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_play_rate( ismd_vidsink_dev_t  dev,
                            ismd_pts_t linear_rate_change_time, int rate );



/**
* Flush the vidsink instance, also flush its vidpproc and vidrend compoent
* maintained in vidsink instance.
*
* @param[in] dev: handle to vidsink instance.
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Flush is successful.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_flush( ismd_vidsink_dev_t  dev);

/**
* Sets the flush behavior of the vidsink.
*
* @param[in] dev: handle to vidsink instance.
* @param[in] flush_policy : controls vidsink's flush behavior
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Flush is successful.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_OPERATION_FAILED   : Internal error occured
*
*/
ismd_result_t ismd_vidsink_set_flush_policy( ismd_vidsink_dev_t  dev,
                                             ismd_vidsink_flush_policy_t flush_policy);

/**
* Gets the flush behavior of the vidsink.
*
* @param[in] dev: handle to vidsink instance.
* @param[in] flush_policy : pointer to vidsink's flush policy
*
* @return ismd_result_t                  Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Flush is successful.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_NULL_POINTER      : The policy pointer is NULL.
* @retval ISMD_ERROR_OPERATION_FAILED  : Internal error occured
*
*/
ismd_result_t ismd_vidsink_get_flush_policy( ismd_vidsink_dev_t  dev,
                                             ismd_vidsink_flush_policy_t * flush_policy);

/**
* Enable or disable frame-by-frame animation mode. Application can
* frame-by-frame set the scaling parameters when this mode is enabled.
*
* @param[in] dev    : handle to vidsink instance.
* @param[in] enable   : enable or disable frame-by-frame control mode.
*
* @return ismd_result_t    Success / Failure indication.
*
* @retval ISMD_SUCCESS       : Successfully enable or disable the mode.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_OPERATION_FAILED: Internal Error.
*
*/
ismd_result_t ismd_vidsink_enable_frame_by_frame_mode (ismd_vidsink_dev_t  dev, bool enable);


/**
* Get the input event. This event will be triggered when all frames
* in this vidsink instance is processed, so that application can feed new buffers.
* Can only be used when frame-by-frame animation mode is enabled.
*
* @param[in] dev   : handle to vidsink instance.
* @param[out] event   : event triggered when all frames in component is processed.
*
* @return ismd_result_t    Success / Failure indication.
*
* @retval ISMD_SUCCESS       : Event successfully returned.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid state provided.
* @retval ISMD_ERROR_OPERATION_FAILED: Internal error.
*
*/
ismd_result_t ismd_vidsink_get_input_event (ismd_vidsink_dev_t  dev, ismd_event_t *event);


/**
* Set the global scaling parameters. This global param will be used in
* following cases:
* 1. Normal animation mode.
* 2. Paused animation.
* 3. Per frame scaling param is invalid when frame-by-frame animation.
*
* @param[in] dev   : handle to vidsink instance.
* @param[in] scaling_param   : global scaling param to be used.
*
* @return ismd_result_t    Success / Failure indication.
*
* @retval ISMD_SUCCESS       : Golbal scaling parameter is successfully set.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid parameters provided.
* @retval ISMD_ERROR_OPERATION_FAILED: Interal error.
*
*/
ismd_result_t ismd_vidsink_set_global_scaling_params (ismd_vidsink_dev_t  dev,
                                    ismd_vidsink_scale_params_t scaling_param);


/**
*
* Get the global scaling parameters.
*
* @param[in] dev   : handle to vidsink instance.
* @param[out] scaling_param   : pointer to global scaling parameters.
*
* @return ismd_result_t    Success / Failure indication.
*
* @retval ISMD_SUCCESS       : Golbal scaling parameter is successfully get.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid parameters provided.
* @retval ISMD_ERROR_OPERATION_FAILED: Interal error.
*
*/
ismd_result_t ismd_vidsink_get_global_scaling_params (ismd_vidsink_dev_t  dev,
                                    ismd_vidsink_scale_params_t *scaling_param);


/**
* This is called by application to set the scaling param for 'frame_buf_id',
* and push it to vidsink. It will return ISMD_ERROR_NO_SPACE_AVAILABLE
* if vidsink is full. When this happens, app should call it multiple times
* until it's successful.
* If 'use_global' is true, it will ignore the 'scaling_param', but use the global scaling
* param for this 'frame_buf_id'.
* This function can only be called in frame by frame animation mode.
*
* @param[in] dev   : handle to vidsink instance.
* @param[in] frame_buf_id   : id of the frame which will use the scaling params.
* @param[in] scaling_param   : scaling param to be used.
* @param[in] use_global   : whether to use global scaling params.
*
* @return ismd_result_t    Success / Failure indication.
*
* @retval ISMD_SUCCESS       : The scaling parameter is successfully set.
* @retval ISMD_ERROR_NO_SPACE_AVAILABLE  : The vidsink is full, push fail.
* @retval ISMD_ERROR_INVALID_HANDLE    : Invalid device handle.
* @retval ISMD_ERROR_INVALID_PARAMETER : Invalid parameters provided.
* @retval ISMD_ERROR_OPERATION_FAILED: Interal error.
*
*/
ismd_result_t ismd_vidsink_scale_by_frame (ismd_vidsink_dev_t  dev, ismd_buffer_handle_t frame_buf_id,
                                     ismd_vidsink_scale_params_t scaling_param, bool use_global);



/**
* Close the vidsink instance. This function validates that
* the component is initialized and then calls internal close function.
*
* @param[in] handle                  : handle to vidsink instance
*
* @return ismd_result_t                Success / Failure indication.
*
* @retval ISMD_SUCCESS               : Instance close successful.
* @retval ISMD_ERROR_OPERATION_FAILED: Module not inited.
* @retval ISMD_ERROR_INVALID_HANDLE  : Invalid vidsink handle
*
*/
ismd_result_t ismd_vidsink_close( ismd_vidsink_dev_t  handle );


/**@}*/ // end of ingroup
/**@}*/ // end of weakgroup

#ifdef __cplusplus
}
#endif

#endif  /* __ISMD_VIDSINK_H__ */


