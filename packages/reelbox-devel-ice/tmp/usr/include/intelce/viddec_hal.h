/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

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
  Santa Clara, CA 97052

  BSD LICENSE

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

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

#ifndef __VIDDEC_HAL_H__
#define __VIDDEC_HAL_H__

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __KERNEL__
#define VIDDEC_HAL_KERNEL_MODE_PM
#endif
#include "viddec_hal_frame_buffer_manager.h"
#include "viddec_hal_common.h"

#ifdef VIDDEC_HAL_CE4200
#include "ces_fw_viddec_frame_attr.h"
#else
#include "viddec_fw_frame_attr.h"
#endif

/** viddec hal overview

    The video decoder (viddec) hardware abstraction layer (HAL) provides a
    generic, low-level programming interface for video decompression
    hardware (HW). The API abstracts the basic HW level decoding features
    from the device driver, including:

    1) Details regarding underlying HW platform such as whether or not
       the platform is register based, FW driven via IPC, etc
    2) Details related to device specific representation of video
       codec information such as the way frame attributes like
       chroma format are stored in the HW.

    The video decoder HAL takes in compressed ES buffers and generates
    video frames. In otherwords, it provides a frame based interface
    for the decode process.

    The HAL also provides controls that allow the higher level device
    driver to tweak certain characteristics of the decode process. As an
    example a frame mask API is provided which tells the underlying platform
    to avoid wasting energy decoding frames of certain types (increasing
    available decoder bandwidth).

    In addition to providing APIs that control the HW specific features
    of the platform, the HAL also defines an event interface that allows
    the device driver to register callbacks for events that are generated
    during the decode process. Example events include end of stream (EOS),
    frame decoded, decoder error, decoder input low (low watermark), etc.

    Events are specified on a per stream basis. The same callback may be
    called by multiple streams (this is the typical case), or different
    callbacks. There is a data pointer (defined as a void *) that allows
    the client programmer that calls the HAL function to pass in callback
    specific data. This data pointer is not modified or used in any way by
    the HAL.

    The viddec HAL defines a stream-based interface to support platforms
    or interfaces that allow multiple video streams to be decoded
    simultaneously. A stream is identified via a handle and is created
    through an open/close interface.

    Viddec HAL Data Types

    The viddec HAL defines the following data structures:

    The \ref viddec_hal_stream_t is a unique identifier for independent video
    streams
    The \ref viddec_hal_es_buffer is a data type that describes the format
    of incoming ES data
    The \ref viddec_hal_frame_buffer_t is a data type that describes the
    frame data generated by the decode process
    The \ref viddec_hal_dec_events_t structure defines the list of callbacks
    that are called when specific HW events occur.

    Viddec HAL Methods

    The viddec HAL API methods are classified in the following categories:

    Initialization routines. Performs basic HW initialization/deinit. These
    routines will typically be called when the driver is loaded and on
    shutdown.

    \ref viddec_hal_init
    \ref viddec_hal_deinit

    Global queries. Returns global information regarding the driver.

    \ref viddec_hal_get_platform_info
    \ref viddec_hal_get_num_decodable_streams

    Stream intialization. Creates and destroys viddec HAL streams

    \ref viddec_hal_open
    \ref viddec_hal_release_hal_specific_resources
    \ref viddec_hal_deallocate_shared_resources
    \ref viddec_hal_register_callbacks

    Stream operations. Changes the state of the stream.

    \ref viddec_hal_flush

    Stream configuration. Configures stream specific information.

    \ref viddec_hal_set_frame_mask
    \ref viddec_hal_set_max_frames_to_decode
    \ref viddec_hal_set_output_scaling

    Stream queries. Queries to access stream specific configuration.

    \ref viddec_hal_get_frame_mask
    \ref viddec_hal_get_max_frames_to_decode
    \ref viddec_hal_get_output_scaling

    Stream input. Interface for pushing ES buffers.

    \ref viddec_hal_push_es_buffer
    \ref viddec_hal_input_not_full

    Viddec HAL event callbacks

    These are the signatures for the driver event callbacks.

    \ref viddec_hal_frame_decoded_func_t:
    \ref viddec_hal_eos_func_t
    \ref viddec_hal_dec_error_func_t
    \ref viddec_hal_low_watermark_ip_func_t
    \ref viddec_hal_need_frame_buffer_t
    \ref viddec_hal_user_data_extracted_t
 */

/** viddec hal data structures
 */

/** viddec_hal_stream_t is a unique identifier that is used
    to name or identify a specific video stream.
 */
typedef int viddec_hal_stream_t;

/** viddec_hal_es_buffer_t describes the input data to the decoder.
    The decoder takes in es buffers and decodes them into yuv frames.
    The initial implementation simply stores the smd buffer handle,
    this structure is defined so that if additional attributes are needed
    in the future for the decoder, we can add them.
 */
typedef struct viddec_hal_es_buffer
{
   ismd_buffer_handle_t smd_buf_handle;
} viddec_hal_es_buffer_t;

/* This keeps track of stream properties applicable to the stream*/
typedef struct
{
   /* This structure is exposed to application for reading stream properties */
   ismd_viddec_stream_properties_t ismd_prop;

   /* The gamma and color space values are not part of the exposed ISMD
    * stream properties, hence we currently define a special structure in HAL
    * to keep track of all these in a single entity. */
   ismd_gamma_t            gamma_type;  /* Type of reverse gamma correction.*/
   ismd_src_color_space_t  color_space; /* Color Space (601/709/etc).*/

   unsigned int            cont_rate;   /* Framerate specified in the content.
                                         * Stored in 90kHz ticks.If not known,
                                         * this is 0. */

   ismd_pts_t              pts_step_size;/* Calculated from the frame rate,
                                          * this is the pts step size used
                                          * in PTS interpolation */
   unsigned int            vc1_pulldown; /* pulldown information in VC1 is
                                          * present in sequence layer, but
                                          * needed for computation of each
                                          * frame's polarity */
   unsigned int            vc1_psf;      /* progressive segmented frame flag
                                          * present in VC1 sequence layer */
   unsigned int            mpeg2_closed_gop;/* Indicates whether GOP is closed
                                             * or open in case of MPEG2 stream
                                             */
   unsigned int            num_total_views; /* In a multi-view stream, this
                                             * indicates how many views are
                                             * present in the bitstream */
   unsigned int            num_active_views;/* In a multi-view stream, this
                                             * indicates how many views are
                                             * currently activated/enabled by
                                             * the user */
   unsigned int            vc1_aspect_ratio_flag;   /* progressive segmented frame flag
                                          * present in VC1 sequence layer */
   unsigned int            vc1_color_format_flag;   /* progressive segmented frame flag
                                          * present in VC1 sequence layer */
   unsigned int            vc1_framerate_flag;      /* progressive segmented frame flag
                                          * present in VC1 sequence layer */
   unsigned int            vc1_framerate_ind;       /* progressive segmented frame flag
                                          * present in VC1 sequence layer */

   unsigned int            mpeg2_aspect_ratio;      /* aspect ratio information in MPEG2 SH */
   unsigned int            packed_time_code; /* time code in bitstream packed as 
                                             needed in ismd_frame_attributes_t */

   /* In case of monochrome content, F/w will not update the Chroma component(UV) 
    * of the frame buffer. This component will be updated by the driver after the 
    * frame buffer is allocated. This flag will indicate whether the H264 content 
    * is monochrome. */
   bool monochrome_present; 

} viddec_hal_stream_properties_t;

/* macros used to round the frame dimensions to integer number of
 * macroblocks */
#define ROUND_WIDTH(w)  (16 * (((w) + 15) /16))
#define ROUND_HEIGHT(h) (32 * (((h) + 31) /32))

#define VIDDEC_INVALID_PROFILE   -1
#define VIDDEC_INVALID_LEVEL     -1

#define VIDDEC_TICKS_PER_SECOND  90000

/** This is an accessor method that provides an atomic way of setting the is_released
 *  attribute. DO NOT USE the is_released, is_written attributes
 *  directly in the viddec_hal_frame_buffer_t structure.  */
void viddec_hal_set_frame_is_released(
                                       viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame,
                                       bool is_released
                                     );

/** This is an accessor method that provides an atomic way of getting is_released
 *  attribute. DO NOT USE the is_released, is_written attributes
 *  directly in the viddec_hal_frame_buffer_t structure.  */
bool viddec_hal_get_frame_is_released(
                                       viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame
                                     );

/** This is an accessor method that provides an atomic way of setting the is_written
 *  attribute. DO NOT USE the is_released, is_written attributes
 *  directly in the viddec_hal_frame_buffer_t structure.  */
void viddec_hal_set_frame_is_written (
                                       viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame,
                                       bool is_written
                                     );

/** This is an accessor method that provides an atomic way of getting the is_written
 *  attribute. DO NOT USE the is_released, is_written attributes
 *  directly in the viddec_hal_frame_buffer_t structure.  */
bool viddec_hal_get_frame_is_written(
                                       viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame
                                    );

/** This is an accessor method that provides an atomic way of setting the is_displayed
 *  attribute. DO NOT ACCESS is_displayed
 *  directly in the viddec_hal_frame_buffer_t structure.  */
void viddec_hal_set_frame_is_displayed(viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame,
                                       bool is_displayed);


/** This is an accessor method that provides an atomic way of getting the is_displayed
 *  attribute. DO NOT ACCESS is_displayed
 *  directly in the viddec_hal_frame_buffer_t structure.  */
bool viddec_hal_get_frame_is_displayed(viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame);


/** This is an accessor method that provides an atomic way of setting the is_alias_written
 *  attribute. DO NOT USE the is_alias_written attributes
 *  directly in the viddec_hal_frame_buffer_t structure.  */
void viddec_hal_set_frame_is_alias_written (
                                       viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame,
                                       bool is_written
                                     );

/** This is an accessor method that provides an atomic way of getting the is_alias_written
 *  attribute. DO NOT USE the is_alias_written attributes
 *  directly in the viddec_hal_frame_buffer_t structure.  */
bool viddec_hal_get_frame_is_alias_written(
                                       viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame
                                    );

/** This is an accessor method that provides an atomic way of setting the is_alias_displayed
 *  attribute. DO NOT ACCESS is_alias_displayed
 *  directly in the viddec_hal_frame_buffer_t structure.  */
void viddec_hal_set_frame_is_alias_displayed(viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame,
                                       bool is_displayed);


/** This is an accessor method that provides an atomic way of getting the is_alias_displayed
 *  attribute. DO NOT ACCESS is_alias_displayed
 *  directly in the viddec_hal_frame_buffer_t structure.  */
bool viddec_hal_get_frame_is_alias_displayed(viddec_hal_stream_t handle,
                                       viddec_hal_frame_buffer_t frame);


/* This is used to store the numbner of frames to be reversed
 * during smooth reverse playback */
ismd_result_t viddec_hal_set_max_frames_to_reverse(viddec_hal_stream_t h,
                                                   unsigned int num_frames);

/* This is the number of frames to be reversed during smooth reverse playback */
ismd_result_t viddec_hal_get_max_frames_to_reverse(viddec_hal_stream_t h,
                                                   unsigned int *num_frames);


/** This is an accessor method that provides an atomic way of getting the
 *  PTS attributes present on a buffer. This function is used by driver
 *  during PTS interpolation. The function is also used by HAL during
 *  tag association */
ismd_result_t viddec_hal_get_pts_attrs(
                                       ismd_buffer_handle_t handle,
                                       ismd_pts_t *local_pts,
                                       ismd_pts_t *orig_pts
                                      );

/** This is an accessor method that provides an atomic way of setting the
 *  PTS attributes present on a buffer. This function is used by driver
 *  during PTS interpolation.The function is also used by HAL during
 *  tag association */
ismd_result_t viddec_hal_set_pts_attrs(
                                       ismd_buffer_handle_t handle,
                                       ismd_pts_t local_pts,
                                       ismd_pts_t orig_pts
                                     );

/** The driver uses this API to add a dependent view.
 * This is used for 3D MVC playback */
void viddec_hal_add_view(viddec_hal_stream_t h,
                         unsigned int index);

/** The driver uses this API to remove a previously added dependent view.
 * This is used for 3D MVC playback */
void viddec_hal_remove_view(viddec_hal_stream_t h,
                            unsigned int index);

/** The driver uses this API to enable a previously added dependent view.
 * This is used for 3D MVC playback */
void viddec_hal_enable_view(viddec_hal_stream_t h,
                            unsigned int index);

/** The driver uses this API to disable a previously added dependent view.
 * This is used for 3D MVC playback */
void viddec_hal_disable_view(viddec_hal_stream_t h,
                            unsigned int index);

/** The driver uses this API to check if a dependent view is active.
 * This is used for 3D MVC playback */
bool viddec_hal_is_view_active(viddec_hal_stream_t h,
                               unsigned int index);

/* The driver uses this API to get the view_angle (Left/Right/Invalid) 
 * of the given view (view index)
 * */
unsigned int viddec_hal_get_view_angle(viddec_hal_stream_t h,
                                            unsigned int index);

/** The driver uses this API to set the EOS handling policy.on 
 *  the video decoder FW */
ismd_result_t viddec_hal_set_eos_policy(viddec_hal_stream_t h,
                                        ismd_viddec_eos_policy_t policy);

/** The driver uses this API to get the EOS handling policy.set on 
 *  the video decoder */
ismd_viddec_eos_policy_t viddec_hal_get_eos_policy(viddec_hal_stream_t h);

/** The driver uses this API to set vpp buffers on the video decoder FW */
ismd_result_t viddec_hal_set_video_preproc_pipeline_buffer(viddec_hal_stream_t h, 
                                        ismd_buffer_handle_t vpp_pipeline_buffer);

/** The driver uses this API to set vpp buffers on the video decoder FW */
ismd_result_t viddec_hal_set_video_preproc_id_buffer(ismd_buffer_handle_t vpp_id_buffer);
 

/** The driver uses this API to set vpp flags on the video decoder FW */
ismd_result_t viddec_hal_set_video_preproc_flags(viddec_hal_stream_t h, unsigned int video_preproc_flags);

/* Returns the video preproc disabled flag. */
unsigned int viddec_hal_get_video_preproc_flags(viddec_hal_stream_t h);

/** The driver uses this API to set region of interest for jpeg */
ismd_result_t viddec_hal_set_roi_info(viddec_hal_stream_t h, ismd_video_rect_t roi);

/** The driver uses this API to get region of interest for jpeg */
ismd_result_t viddec_hal_get_roi_info(viddec_hal_stream_t h, ismd_video_rect_t *roi);

/** The driver uses this API to get output video format*/
ismd_viddec_output_video_format_t viddec_hal_get_output_video_format(viddec_hal_stream_t h);

/** The driver uses this API to set output video format*/
void viddec_hal_set_output_video_format(viddec_hal_stream_t h, ismd_viddec_output_video_format_t output_video_format);

/** The driver uses this API to associate buffer tags to the frame buffer.
    For example client id, new segment, EOS, discontinuity. This function
    will not associate PTS values to the frame as those are already
    copied over to the frame by the HAL.

    @param[in] h : Handle to HAL stream to associate tags for
    @param[in] fb : frame buffer structure for which the tags are to be
                    associated

    @retval ISMD_SUCCESS : tag association successful
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_associate_tags (
                                           viddec_hal_stream_t handle,
                                           viddec_hal_frame_buffer_t fb
                                        );
ismd_result_t viddec_hal_start_associate_tags (
                                           viddec_hal_stream_t handle,
                                           viddec_hal_frame_buffer_t fb
                                        );
ismd_result_t viddec_hal_stop_associate_tags (
                                           viddec_hal_stream_t handle,
                                           viddec_hal_frame_buffer_t fb,
                                           bool drop_flag
                                        );

/** The driver uses this API to update buffer tags when a frame is
    dropped due to error policy.

    @param[in] h : Handle to HAL stream to update tags for.
    @param[in] fb : frame buffer which will be dropped

    @retval ISMD_SUCCESS : tag array updation successful
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_handle_dropped_frame_tags(
                                                      viddec_hal_stream_t handle,
                                                      viddec_hal_frame_buffer_t fb
                                                  );

/** The driver uses this API to check whether the frame buffer
 *  has discontinuity tag */
bool viddec_hal_has_discontinuity_tags (
                                           viddec_hal_stream_t handle,
                                           viddec_hal_frame_buffer_t fb
                                        );

/** Driver uses this API to release shared resources between the HAL
 *  and the driver. This function is called by the driver during
 *  close operation. It is intended to be called after the driver
 *  specific resources are released e.g. the input port, output port,
 *  display queues etc.
 */
void viddec_hal_deallocate_shared_resources (viddec_hal_stream_t handle);

/** viddec_hal_dec_error_t defines the set of errors that may be returned by
    the hardware platform.
 */
typedef enum
{
   VIDDEC_HAL_INVALID_INPUT = 0x0, /**< this is generated when there is
                                        something wrong with the way the
                                        bitstream was fed to the decoder.
                                        For example, the decoder may have
                                        certain restrictions or limitations
                                        that cannot be handled by the HW
                                        or HAL layers.
                                     */

   VIDDEC_HAL_INVALD_RESOLUTION = 0x1, /**< generated when a stream
                                            has a resolution that cannot
                                            be decoded
                                         */
} viddec_hal_dec_error_t;

/** Maximum number of streams supported. Driver & HAL both use this macro
 */
#define VIDDEC_HAL_MAX_NUM_STREAMS_SUPPORTED     16

/** Maximum number of views supported in a multi-view stream. We support
 *  only 3DBD implementation of MVC specification which restricts the
 *  number of views to 2.
 */
#define VIDDEC_HAL_MAX_NUM_VIEWS_SUPPORTED     2

/** used to indicate an invalid stream handle
 */
#define VIDDEC_HAL_HANDLE_INVALID -1

/* used for multiview streams  and 3D AVC streams*/
typedef enum
{
   VIDDEC_HAL_INVALID_VIEW_INDEX   = -1,
   VIDDEC_BASE_VIEW_INDEX          =  0,
   VIDDEC_DEPENDENT_VIEW_INDEX     =  1
} viddec_hal_view_index_t;


/**  defined for readability, this indicates that the
 *   viddec_hal_release_frame_buffer() routine should release the underlying
 *   smd frame buffer associated with it. This is done in the dropped frame
 *   case or any other case where the frame will NOT be written out of the
 *   decoder.
 */
#define VIDDEC_HAL_RELEASE_SMD_FB true

/** defined for readability, this indicates that the
 * viddec_hal_release_frame_buffer() routine should NOT release the underlying
 * smd frame buffer associated with it when re-initializing the viddec
 * HAL frame buffer type. This is done when the frame will be written out of
 * decoder to a downstream device.
 */
#define VIDDEC_HAL_PRESERVE_SMD_FB false

/** viddec hal event callbacks

General notes regarding viddec HAL callbacks.

Currently the return value is not used. The data parameter is user
specific and is passed in when the callbacks are registered (via
\ref viddec_hal_register_callbacks). The value passed into
\ref viddec_hal_register_callbacks is passed as is into the callback,
and is not modified by the HAL.

*/

/** This callback is called when the hal has finished decoding a frame.

Example callback prototype:

ismd_result_t viddec_handle_decoded_frame(void *data,
                                          viddec_hal_frame_buffer_t *fb);

See the general callback notes section for general viddec HAL callback
behavior.

fb is the frame buffer that was decoded.

*/
typedef ismd_result_t \
(*viddec_hal_frame_decoded_func_t)(void *data,
                                   viddec_hal_frame_buffer_t *fb);

/** This callback is called when the hal detects a discontinuity after
    processing a h264 workload in decode order and if its in a smooth reverse 
    trick mode.

Example callback prototype:

ismd_result_t viddec_empty_disp_stack_on_disc(void *data);
                                          

See the general callback notes section for general viddec HAL callback
behavior.

fb is the frame buffer that was decoded.
*/
typedef ismd_result_t \
(*viddec_hal_empty_disp_stack_func_t)(void *data);

/** This callback is called when the hal has detected an EOS event.

Example callback prototype:

ismd_result_t viddec_handle_eos(void *data);

See the general callback notes section for general viddec HAL callback
behavior.
*/
typedef ismd_result_t (*viddec_hal_eos_func_t)(void *data);

/** This callback is called when the hal has detected a device error.

Example callback prototype:

ismd_result_t viddec_handle_decoder_error(void *data,
                                          viddec_hal_dec_error_t err);

See the general callback notes section for general viddec HAL callback
behavior.

err is the error condition detected by the HAL
*/
typedef ismd_result_t \
(*viddec_hal_dec_error_func_t)(void *data,
                          viddec_hal_dec_error_t err);

/** This callback is called when the input to the decoder is empty.

Example callback prototype:

ismd_result_t viddec_handle_decoder_low_watermark(void *data);

See the general callback notes section for general viddec HAL callback
behavior.

*/
typedef ismd_result_t \
(*viddec_hal_low_watermark_ip_func_t)(void *data);


/** This callback will be used by the HAL to request a frame buffer from the
 driver. It is called when the hal receives a workload from the FW and
 needs to update the wokload with a frame buffer address before sending the
 workload to the decoder moule.

Skipped frames are treated differently during buffer allocation, hence the
special flag.

Example callback prototype:

ismd_result_t \
viddec_provide_frame_buffer(void *data, viddec_hal_frame_buffer_t **fb,
                                 unsigned int *height, unsigned int *width);

See the general callback notes section for general viddec HAL callback
behavior.
*/
typedef ismd_result_t \
(*viddec_hal_provide_frame_buffer_t)(void *data, viddec_hal_frame_buffer_t **fb, \
                                  bool is_skipped_frame, bool is_range_adjustment, \
                                  unsigned int *width, unsigned int *height);

/** This callback will be used by the HAL to check if the max number of frame
 * buffers have already been allocated . If this function is called for the first time
 * it will also compute the max frame buffers for the codec

Example callback prototype:

ismd_result_t \
viddec_check_frame_buffer_avail(void *data)

*/

typedef ismd_result_t \
(*viddec_hal_check_frame_buffer_avail_t)(void *data);

/** This callback is called only for H264 contents. The FW provides
    information  about when an H264 frame is not required as reference.
    The HAL sends this 'release' information to the driver layer
    through the callback. The driver checks if the frame has
    been written out of the decoder and accordingly updates the
    frame buffer attributes.

Example callback prototype:

ismd_result_t viddec_hal_handle_h264_released_frame( void *data,
                                          viddec_hal_frame_buffer_t *fb );

fb is the frame buffer that was released by the FW.

*/
typedef ismd_result_t \
(*viddec_hal_handle_h264_released_frame_t)(void *data,
                                   viddec_hal_frame_buffer_t *fb, int writte_or_release);


/** This callback is called when user data is found in the bitstream.
 *
 * Example callback prototype:
 *
 * ismd_result_t viddec_process_user_data(void *data,
 *                                        ismd_buffer_handle_t ud);
 *
 */
typedef ismd_result_t \
(*viddec_hal_user_data_extracted_t)(void *data, ismd_buffer_handle_t ud);

/** This callback is called when the hal has detected sequence end event.

Example callback prototype:

ismd_result_t viddec_handle_sequence_end(void *data);

See the general callback notes section for general viddec HAL callback
behavior.
*/
typedef ismd_result_t (*viddec_hal_sequence_end_func_t)(void *data);

/** This callback is called to extract dvd/gop closed caption data.

Example callback prototype:

void viddec_extract_dvd_gop_cc_data(viddec_stream_context_t * context, unsigned char * user_data);
*/

typedef void (* viddec_hal_extract_gop_cc_data_t)(void * context, unsigned char * user_data);

/** This callback is called when the hal has detected an unsupported 3D AVC format.

Example callback prototype:

ismd_result_t viddec_handle_unsupported_3d_avc_format(void *data);

See the general callback notes section for general viddec HAL callback
behavior.
*/
typedef ismd_result_t (*viddec_hal_unsupported_3d_avc_format_detected_t)(void *data);

/** This callback is called when the hal needs to know the number of frame buffers
 * allocated for this instance.

Example callback prototype:

ismd_result_t viddec_handle_get_num_allocated_fbs(void *data);

See the general callback notes section for general viddec HAL callback
behavior.
*/
typedef int (*viddec_hal_get_num_allocated_fbs_t)(void *data);

/** This callback is called when the hal needs to know the display stack size.

Example callback prototype:

ismd_result_t viddec_handle_get_display_stack_size(void *data);

See the general callback notes section for general viddec HAL callback
behavior.
*/
typedef int (*viddec_hal_get_display_stack_size_t)(void *data);

/**
    This data structure defines the interface that the client programmer uses
    to setup the HAL callbacks. This structure should be filled out by the
    the driver prior to calling the \ref viddec_hal_register_callbacks API.
    If the driver is not interested in a particular callback, then it should
    specify the value of NULL to the driver.

    IMPORTANT NOTE: This structure should be completely initialized by the
    host programmer, otherwise the behavior is undefined. If a field is
    not used, do not leave it unitialized. Set the value to NULL.
 */
typedef struct viddec_hal_dec_events
{
   viddec_hal_frame_decoded_func_t   frame_decoded; /**< called when a frame
                                                         has been decoded */
   viddec_hal_empty_disp_stack_func_t empty_disp_stack; /**< for smooth reverse
                                                        tm on h264/3D content.*/
   viddec_hal_eos_func_t            eos;           /**< called when EOS is
                                                         detected */
   viddec_hal_dec_error_func_t      dec_err;       /**< called when a decoder
                                                         error is detected */

   viddec_hal_low_watermark_ip_func_t low_wmark_on_ip; /**< called when a low
                                                             watermark event is
                                                             detected on the
                                                             input, signals
                                                             that the underlying
                                                             HW is ready for
                                                             more data. */
   viddec_hal_provide_frame_buffer_t  provide_frame_buffer; /**< called by HAL when it
                                                           receives a workload
                                                           from parser and needs
                                                           to populate it with
                                                           frame buffer
                                                           address. */
   viddec_hal_handle_h264_released_frame_t h264_release_frame; /**< called by HAL
                                                           when it receives an H264
                                                           frame marked as 'released'
                                                           by the FW */

   viddec_hal_user_data_extracted_t user_data_found; /**< called by HAL
                                                          when it detects user
                                                          data in the workload.
                                                       */

   viddec_hal_sequence_end_func_t seq_end_evict_frm; /**< called when sequence_end or
                                                  evict frame flag detected  */
   
    viddec_hal_extract_gop_cc_data_t extract_gop_cc_data; /* called to extract
                                                   dvd/gop closed caption data */

   viddec_hal_unsupported_3d_avc_format_detected_t unsupported_format_detected; /**< called when unsupported 3d avc format is
                                                     detected */
   viddec_hal_check_frame_buffer_avail_t check_frame_buffer_avail; /** <called to check if max frame buffers
                                                       have already been allocated */
   viddec_hal_get_num_allocated_fbs_t get_num_allocated;
   viddec_hal_get_display_stack_size_t get_display_stack_size;

} viddec_hal_dec_events_t;

/** end hal data structures
 */


/** viddec hal methods
 */

/** Performs basic HW initialization. After this function is called, the HW
    platform is in a usable state.

    @param isr_mode - specifies if decoder should be configured in polled or
                      interrupt mode

    @retval ISMD_SUCCESS : the HAL has successfully initialized the HW platform
 */
ismd_result_t viddec_hal_init(int isr_mode, ismd_clock_t clock);

/** Performs actions to shutdown the HW. Only one state is supported
   (full shutdown). */
void viddec_hal_deinit(void);

/** Returns a string that provides platform level identification (e.g.,
    fw version currently running, HW revision, etc.

    @retval str : string that identifies the HW platform
*/
const char *viddec_hal_get_platform_info(void);

/** This function returns the total number of streams that the
    underlying platform can support. It does NOT consider
    the number of streams currently open or return the
    number of available streams given the runtime state of the
    decoder.

   @param codec - specifies the codec format to query

   @retval num : A constant value that specifies the max
                 number of streams the HW platform supports.
 */
int viddec_hal_get_num_decodable_streams(ismd_codec_type_t codec);

/** Opens a new HAL stream. A codec type must be specified. The handle to the
    newly opened stream is returned in the viddec_hal_stream_t * parameter.

    @param[in] codec - codec format for the stream
    @param[out] h - stream handle that is used to identify the stream in
                    subsequent actions

    @retval ISMD_SUCCESS - stream successfully created
    @retval ISMD_ERROR_INVALID_PARAMETER - codec format was not valid
    @retval ISMD_ERROR_NO_RESOURCES - the maximum number of streams for
                                      the platform has been reached
*/
ismd_result_t viddec_hal_open(ismd_codec_type_t codec, viddec_hal_stream_t *h);

/** Releases the state information for the specified HAL stream.

    Note: viddec_hal_release_hal_specific_resources() does not completely
    return the HAL�s stream context into a reusable state. The client
    programmer must call \ref viddec_hal_deallocate_shared_resources() once
    it has released all frame buffers as these are shared resources between
    the driver and firmware. This is an unfortunate consequence of the
    coupling of viddec frame buffers between the driver and the HAL.

    @param[in] h - handle of stream to close
*/
void viddec_hal_release_hal_specific_resources(viddec_hal_stream_t h);

/**
Registers event handlers for the different events that the video decoder
can generate. Pass in a value of NULL to indicate that the specific callback
is not of interest. see \ref viddec_hal_dec_events_t for a list of valid
callbacks.

The callbacks are specified on a per stream basis, although the same
functions can be specified for multiple streams...

   @param[in] h: Handle to HAL stream type to register these callbacks to
   @param[in] event_handlers: List of callbacks to call when decoder events
                              happen.
   @param[in] data: Arbitrary data that the client programmer can pass into
                    the HAL. This data will be passed 'AS IS' to the
                    callback function for use by the callback. This data is
                    not used by the HAL in any way.

   @retval ISMD_SUCCESS : Callbacks were successfully registered.

Example:

   viddec_hal_dec_events_t callbacks;
   ismd_result_t result = ISMD_SUCCESS;

   callbacks.frame_decoded = viddec_handle_decoded_frame;
   callbacks.eos = viddec_handle_eos;
   callbacks.dec_err = NULL;
   callbacks.low_wmark_on_ip = NULL;
   callbacks.frame_buffer_needed = viddec_provide_frame_buffer;

   result = viddec_hal_register_callbacks(h, callbacks,
                                          (void *)viddec_context);

This snippet registers the viddec_handle_decoded_frame() and
viddec_handle_eos() functions as callbacks for the frame decoded and EOS
HAL events. It indicates that decoder error events do not have a handler
defined. The data parameter is used to pass in the driver's context. This
information is not processed by the HAL. It is simply passed back to the
callback unmodified.

*/
ismd_result_t viddec_hal_register_callbacks(viddec_hal_stream_t h,
                             viddec_hal_dec_events_t event_handlers,
                             void *data);

/** Flushes the data currently in the decoder.

    @param[in] h - handle of stream to flush

    @retval ISMD_SUCCESS : flush completed without error
*/
ismd_result_t viddec_hal_flush(viddec_hal_stream_t h);


/** Returns true if the input port is NOT FULL, false if the
    input port is full

   @param[in] h: Handle to HAL stream. This stream's input level is checked
                 to see if there is space available in the input.

   @retval true : Space is available
   @retval false: No space available
 */
bool viddec_hal_input_not_full(viddec_hal_stream_t h);

/** Interface for writing ES buffers to HW. This function returns when
    the buffer is sent to the HW, but not necessarily when the HW xfer
    completes. For example, if the underlying platform uses DMA to send
    the buffer to the decoder, this function will return when the DMA xfer has
    been setup, not when it has completed.

    @param[in] h: Handle to hal stream to write the buffer to
    @param[in] buf: Buffer to write

    @retval ISMD_SUCCESS : Buffer successfully sent to HW for processing
    @retval ISMD_ERROR_NO_SPACE_AVAILABLE : Decoder input is full, and cannot
                                            accept any more data for processing
 */
ismd_result_t viddec_hal_push_es_buffer(viddec_hal_stream_t h,
                                        viddec_hal_es_buffer_t buf,
                                        bool set_discontinuity,
                                        bool set_evict_frame_flag);



/** Specifies the order in which video frames appear out of the decoder.
    For example, you can specify that the decoder should output frames
    in presentation order or display order.

    @param[in] h: Handle to hal stream to set output policy for
    @param[in] policy: The output policy.

    @retval: Void function.

 */
void viddec_hal_set_frame_output_policy(viddec_hal_stream_t h,
                                    ismd_viddec_frame_output_policy_t policy);

/** Specifies what types of video frames to decode. For example, you can
    specify that the decoder should only decode I frames. This is useful for
    operations such as trick modes where you want to exceed the normal real
    time bandwidth of the decoder.

    @param[in] h: Handle to hal stream to set frame mask on
    @param[in] mask: Mask specifying which frames to skip

    @retval: Void function.

 */
void viddec_hal_set_frame_mask(viddec_hal_stream_t h,
                                    unsigned int mask);

/** For certain applications we may only want to decode a certain number of
    frames within a GOP. If our platform supports it, this API tells the
    decoder to only decode the first N frames of the video playback unit.

    @param[in] h: Handle to hal stream to set maximum frames to decode
    @param[in] n: The count of frames

    @retval ISMD_SUCCESS : max frames to decode is set for the given stream
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support masking frames

 */
ismd_result_t viddec_hal_set_max_frames_to_decode(viddec_hal_stream_t h,
                                                  unsigned int n);


/** Specifies whether or not the video decoder should scale the output frame
    data.

    @param[in] h : Handle to HAL stream to set output scaling
    @param[in] scale_factor : output scale factor

    @retval ISMD_SUCCESS : output scaling set
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_set_output_scaling(viddec_hal_stream_t h,
                               ismd_viddec_output_scale_factor_t scale_factor);

/** Specifies the error policy

    @param[in] h : Handle to HAL stream to set error policy
    @param[in] error_policy: output error policy

    @retval ISMD_SUCCESS : error policy set
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t
viddec_hal_set_frame_error_policy(viddec_hal_stream_t h,
                                  ismd_viddec_frame_error_policy_t error_policy);

/** Queries the HAL to see what the error policy is set to

    @param[in] h : Handle to HAL stream to get error policy
    @param[out] *error_policy: output error policy

    @retval ISMD_SUCCESS : error policy returned
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t
viddec_hal_get_frame_error_policy(viddec_hal_stream_t h,
                                  ismd_viddec_frame_error_policy_t *error_policy);


/** Queries the HAL to see what the frame mask is set to.

    @param[in] h : Handle to HAL stream to query
    @param[out] mask : Variable to store frame mask value in.

    @retval ISMD_SUCCESS : we're able to return the frame mask
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_get_frame_mask(viddec_hal_stream_t h,
                                   unsigned int *mask);

/** Returns the HAL streams properties for the current stream.

    @param[in] h : Handle to HAL stream to query
    @param[out] prop : Address to store stream properties in.

    @retval ISMD_SUCCESS : we're able to return the stream properties
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_get_stream_properties (viddec_hal_stream_t h,
                                                viddec_hal_stream_properties_t *prop);


/** This detects changes in stream properties like frame rate, resolution etc.
    for the current stream.

    @param[in] h : Handle to HAL stream to query
    @param[out] is_prop_changed : true if stream properties have changed,
                                  false if there is no change.
    @param[out] is_format_changed : true if stream format (2D/3D) have changed,
                                  false if there is no change.
                                  
    @param[out] is_display_info_change : true if display info have changed, 
                                  false if there is no change. 
    @retval ISMD_SUCCESS : we're able to compare the stream properties
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_detect_stream_property_changes(viddec_hal_stream_t h,
                                                        bool *is_prop_changed,
                                                        bool *is_format_changed,
                                                        bool *is_display_info_change);

/** Returns the ISMD streams properties for the current stream.

    @param[in] h : Handle to HAL stream to query
    @param[out] prop : Address to store stream properties in.

    @retval ISMD_SUCCESS : we're able to return the stream properties
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_get_ismd_stream_properties (viddec_hal_stream_t h,
                                                     ismd_viddec_stream_properties_t *prop);

/** Returns the output scaling factor for the current stream.

    @param[in] h : Handle to HAL stream to query
    @param[out] scale_val : Address to store output scaling factor in.

    @retval ISMD_SUCCESS : we're able to return the output scaling factor
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t ismd_viddec_hal_get_output_scaling(viddec_hal_stream_t h,
                                       ismd_viddec_output_scale_factor_t *scale_val);

/** Returns the max frames to decode setting for the stream.

    @param[in] h : Handle to HAL stream to query
    @param[out] n : Variable to store max frames to decode value in.

    @retval ISMD_SUCCESS : we're able to return the number of frames to decode
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
  */
ismd_result_t viddec_hal_get_max_frames_to_decode(viddec_hal_stream_t h,
                                                  unsigned int *n);


/** Queries the HAL to see what the output scaling policy is set to

    @param[in] h : Handle to HAL stream to query
    @param[out] scale_factor : Variable to store scale factor value in.

    @retval ISMD_SUCCESS : we're able to return the scale factor value
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_get_output_scaling(viddec_hal_stream_t h,
                              ismd_viddec_output_scale_factor_t *scale_factor);

/** Frees the specified viddec hal frame buffer.

    @param[in] h : Handle to HAL stream to query
    @param[in] frame : Viddec HAL frame buffer to free
    @param[in] release_smdfb : If true, release the SMD frame buffer associated
                               with this frame. If false, allow system
                               (downstream elements) to release this frame.

    Function does not return a value. All attributes are re-initialized to
    default states after execution.
 */


void viddec_hal_release_frame_buffer(viddec_hal_stream_t handle,
                                     viddec_hal_frame_buffer_t *frame,
                                     bool release_smdfb);

/** Calculates minimum width and height required by the underlying HW decoder.
 * Different decoders may have different requirements on width and height
 * alignment, etc.*/
#ifdef VIDDEC_HAL_CE4200
void hal_compute_frame_buffer_size_for_decoder(ismd_codec_type_t codec,
                                                  unsigned int width,
                                                  unsigned int height,
                                                  unsigned int *alloc_width,
                                                  unsigned int *alloc_height);
#else
void hal_compute_frame_buffer_size_for_decoder(ismd_codec_type_t codec,
                                                  unsigned int width,
                                                  unsigned int height,
                                                  unsigned int *alloc_width,
                                                  unsigned int *alloc_height);
#endif

/** Queries the HAL to get the FW version number

    @param[out] fw_major_num : major number of the FW
    @param[out] fw_minor_num : minor number of the FW
    @param[out] build_num    : build number of the FW
 */
void viddec_hal_get_fw_version_num(unsigned int *fw_major_num,
                                   unsigned int *fw_minor_num,
                                   unsigned int *build_num);

/** Returns the decode statistics from the HAL's point of view.
 * For example, the HAL will only drop frames if the frame mask
 * indicates it should, if there isn't memory available to allocate a frame
 * buffer, or if a frame is not decodable.

    @param[in] h : Handle to HAL stream to query
    @param[out] stats : Variable to store dropped frame count in.

    @retval ISMD_SUCCESS : we're able to return the dropped frame count
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t viddec_hal_get_stream_statistics(viddec_hal_stream_t h,
                                       ismd_viddec_stream_statistics_t  *stats);

ismd_result_t viddec_dereference_fb(ismd_buffer_handle_t fb);

/* This API is called for a dropped frame by driver. Since frame is dropped,
 * it will not be sent to the output port. We perform one dereference
 * on the frame which matches the dereference by downstream
 * element (e.g. for normal frames that are written into output port).
 *
 * @param[in] h : Handle to HAL stream
 * @param[in] frame : HAL frame buffer for which ismd frame buffer
 *                    should be dereferenced
 */
void viddec_hal_dereference_dropped_frame (viddec_hal_stream_t handle,
                                           viddec_hal_frame_buffer_t *frame);

/**
 * This function tells the HAL whether or not it should override the frame
 * rate specified in the bitstream. If we should override the frame rate, it
 * allows the programmer to set the new frame rate values using the numerator
 * and denominator.
 *
 */
void viddec_hal_set_frame_rate_override(viddec_hal_stream_t h,
                                        bool override_frame_rate,
                                        unsigned long num,
                                        unsigned long den);

/**
 * This function returns the frame rate settings to the caller
 */
void viddec_hal_get_frame_rate_override(viddec_hal_stream_t h,
                                        bool *override_frame_rate,
                                        unsigned long *num,
                                        unsigned long *den);

/**
 * In this mode the decoder will ignore the frame polarity encoded in the
 * bitstream and mark the polarity of all output frames as interlaced. This
 * will be done ONLY if following conditions are met:
 *  1. The sequence is interlaced
 *  2. The sequence is SD. For HD contents, this mode is inactive.
 *  3. Frame rate is <= 30 fps.
 *  This special mode has been added in the decoder to handle the error case
 *  where the video is captured as interlaced fields, but the encoder generated
 *  all frames as progressive. Consequently the post-processor doesn't perform
 *  deinterlacing for these frames. This results in severe deinterlacing/combing
 *  artifact. To solve this, the decoder provides this mode to the application.
 *
 *  @param[in] h : Handle to HAL stream to enable policy
 *
 */
void viddec_hal_enable_override_frame_polarity(viddec_hal_stream_t h);

/**
 * Disable frame polarity override mode
 */
void viddec_hal_disable_override_frame_polarity(viddec_hal_stream_t h);

void viddec_hal_get_current_codec(viddec_hal_stream_t h,
                                  ismd_codec_type_t *codec);

/**
 * Incase of MPEG2 stream, this routine returns if the stream is closed or open GOP.
 */
void viddec_hal_get_mpeg2_closed_gop(viddec_hal_stream_t h,
                                     unsigned int *closed_gop);

/**
 *   Allocates a HAL frame buffer resource from the stream's frame buffer pool.
 *
    @param[in] h : Handle to HAL stream to query
    @param[in] width : Width of buffer to allocate.
    @param[in] height : Height of buffer to allocate.
    @param[out] fb : Frame buffer resource allocated. If unable to allocate,
                     NULL is returned.
    @param[in] is_skipped_frame : Frame buffer that needs to be allocated is
                                  a skipped frame. This essentially tells
                                  this allocation routine to find the
                                  SMD frame buffer this frame should be linked
                                  to.

    @retval ISMD_SUCCESS : we're able to return the dropped frame count
    @retval ISMD_ERROR_NO_RESOURCES : if there aren't any available frame
                                      buffers

 *
 */
ismd_result_t viddec_hal_allocate_frame_buffer(viddec_hal_stream_t h,
                                               unsigned int width,
                                               unsigned int height,
                                               viddec_hal_frame_buffer_t **fb,
                                               bool is_skipped_frame,
                                               bool is_range_adjustment);

/** Test method - allows the driver to verify that the viddec_hal_frame_buffer
 * pool is in its initial state.
 *
 */
void verify_hal_frame_buffers_initialized(viddec_hal_stream_t h);

/* Set the panscan_propagation flag to the given value. */
ismd_result_t viddec_hal_set_panscan_propagation(viddec_hal_stream_t h, 
                                                 bool panscan_flag);

/* Returns the panscan_propagation flag. */
bool viddec_hal_get_panscan_propagation(viddec_hal_stream_t h); 

/* Set the display_extension_policy to the given value. */
ismd_result_t viddec_hal_set_display_extension_policy(viddec_hal_stream_t h, 
                                                      ismd_viddec_seq_disp_ext_default_policy_t ext_policy);

/* Returns the display_extension_policy. */
ismd_viddec_seq_disp_ext_default_policy_t viddec_hal_get_display_extension_policy(viddec_hal_stream_t h);

/* Strobes the hal fb avail event to indicate to the workload handler thread that a fb has been
 * released by the driver */
ismd_result_t viddec_hal_strobe_fb_avail_event(viddec_hal_stream_t hal_stream_handle);

/* Strobes the eos handled event to indicate to the workload handler thread 
 * that a pending eos has been processed by the driver */
ismd_result_t viddec_hal_strobe_eos_handled_event(viddec_hal_stream_t hal_stream_handle);

ismd_result_t viddec_hal_set_eos_pending(viddec_hal_stream_t h,
                                         unsigned int index,
                                         bool value);
bool viddec_hal_is_any_eos_pending(viddec_hal_stream_t h);
bool viddec_hal_is_eos_pending_for_view(viddec_hal_stream_t h, 
                                        unsigned int index);
bool viddec_hal_frame_mask_is_iframe_only(ismd_viddec_frame_skip_policy_t frame_mask);

ismd_result_t viddec_hal_configure_isr(void);

ismd_result_t viddec_hal_set_play_rate(viddec_hal_stream_t h, int play_rate); 
int viddec_hal_get_max_num_fb_for_codec(viddec_hal_stream_t h);
ismd_result_t viddec_hal_set_disp_stack_size(viddec_hal_stream_t h, int size);

#ifdef VIDDEC_HAL_KERNEL_MODE_PM
/* Called while suspending to deinit viddec fw */
void viddec_hal_deinit_mfd_fw(void);

/* Called while resuming to initialize viddec_fw */
ismd_result_t viddec_hal_init_fw_on_resume(void);

/* release hal resources on suspend */
void viddec_hal_release_on_suspend(viddec_hal_stream_t h);

/* hal open on resume */
void viddec_hal_open_on_resume(viddec_hal_stream_t h, ismd_codec_type_t codec);
#endif

/*Returns SYSTEM_STRIDE value */
int viddec_hal_get_system_stride_val(void);

/** end hal methods
 */

#ifdef __cplusplus
}
#endif
#endif /* __VIDDEC_HAL_H__*/
