/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2011 Intel Corporation. All rights reserved.

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

#ifndef __VIDENC_HAL_H__
#define __VIDENC_HAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sven_devh.h"
#include "pal.h"

/** videnc hal overview

    The video encoder hardware abstraction layer (HAL) provides a generic,
    low-level programming interface for video compression hardware (HW).
    The API abstracts the basic FW/HW level encoding features from the device
    driver, including details of the mode of communication with the underlying
    FW/HW platform, interrupt management and workload management.

    The video encoder HAL provides a frame based API, taking as input video
    frame buffers and generating associated compressed elementary stream
    buffers. 

    In addition to providing APIs that control the encode process,
    the HAL also defines an event interface that allows the device driver to
    register callbacks for events that are generated. Example events include
    es buffer available, encoder error, encoder input low, (low watermark),
    etc. Events are specified on a per stream basis. The same callback may
    be called by multiple streams (this is the typical case), or different
    callbacks. There is a data pointer (defined as a void *) that allows the
    client programmer that calls the HAL function to pass in callback
    specific data. This data pointer is not modified or used in any way by
    the HAL.

    The videnc HAL defines a stream-based interface to support platforms or
    interfaces that allow multiple video streams to be encoded simultaneously.
    A stream is identified via a handle and is created through an open/close
    interface.

	Videnc HAL Data Types

    The videnc HAL defines the following data structures:

    The \ref videnc_hal_stream_t is a unique identifier for independent video
    streams
    The \ref videnc_hal_events_t structure defines the list of callbacks
    that are called when specific HW events occur.
    The \ref videnc_hal_stream_statistics_t structure defines stream level
    statistics.

    Videnc HAL Methods

    The videnc HAL API methods are classified in the following categories:

    Initialization routines. Performs basic HW initialization/deinit. These
    routines will typically be called when the driver is loaded and on
    shutdown.

    \ref videnc_hal_init
    \ref videnc_hal_deinit

    Stream intialization. Creates and destroys videnc HAL streams

    \ref videnc_hal_open
    \ref videnc_hal_release_resources
    \ref videnc_hal_register_callbacks

    Stream operations. Changes the state of the stream.

    \ref videnc_hal_flush

    Stream input. Interface for pushing frame buffers.

    \ref videnc_hal_push_frm_buffer
    \ref videnc_hal_input_not_full

    Stream output. Interface for pulling es buffers.

    \ref videnc_hal_pull_es_buffer

    Videnc HAL event callbacks

    These are the signatures for the driver event callbacks.

    \ref videnc_hal_output_available_func_t:
    \ref videnc_hal_enc_error_func_t
    \ref videnc_hal_input_not_full_func_t
    \ref videnc_hal_input_stream_settings_change_t
 */

/** Maximum number of streams supported. Driver & HAL both use this macro
 */
#define VIDENC_HAL_MAX_NUM_STREAMS_SUPPORTED 2

/** Maximum number user data buffers per frame buffer
 */
#define VIDENC_HAL_MAX_USER_DATA_PER_FB 10

/*
 * Max number of lookahead frames for scene change detect
 */
#define VIDENC_HAL_MAX_LOOKAHEAD_FRAMES	12
/*
 * Max number of B frames (CE 5300 and later)
 */
#define VIDENC_HAL_MAX_B_FRAMES	2
 

/** used to indicate an invalid stream handle
 */
#define VIDENC_HAL_HANDLE_INVALID -1

/** videnc hal data structures
 */

/** videnc_hal_stream_t is a unique identifier that is used
    to name or identify a specific video stream.
 */
typedef int videnc_hal_stream_t;

/* type of input frame, shared by driver and HAL */
typedef enum {
    VIDENC_INPUT_NONE = 0,
    VIDENC_INPUT_PROGRESSIVE,
    VIDENC_INPUT_INTERLACED,
    VIDENC_INPUT_DEINTERLACED,
} videnc_input_frame_type_t;

/** videnc_hal_input_data_t describes the input data to the encoder.
 */
typedef struct videnc_hal_frame_buffer
{
   ismd_buffer_handle_t frm_buf_handle[2];  // for reinterlacing (the driver send 2 frames to the FW)
   ismd_buffer_descriptor_t desc[2];   
   bool eos; // indicates whether this is the end of the stream
   bool end_of_sequence; // indicates whether this is the end of the sequence
   bool discontinuity; // indicates whether there is a discontinuity
   bool tags_only; // indicates that only tags should be processed on input buffer
   ismd_videnc_scan_mode_t scan_mode;
   videnc_input_frame_type_t input_type;
   unsigned int cont_rate;
   uint32_t num_actual_ud_buffers; // how many user data buffers associated with the frame
   uint32_t num_ud_buffers;	// number of user data buffers
   ismd_buffer_handle_t user_data_handles[VIDENC_HAL_MAX_USER_DATA_PER_FB];
   uint32_t user_data_flags[VIDENC_HAL_MAX_USER_DATA_PER_FB];
} videnc_hal_input_data_t;

/** videnc_hal_error_t defines the set of errors that may be returned by
    the hardware platform.
 */
typedef enum
{
   VIDENC_HAL_INVALID_INPUT = 0x0, /**< this is generated when there is
                                        something wrong with the way the
                                        bitstream was fed to the encoder.
                                        For example, the encoder may have
                                        certain restrictions or limitations
                                        that cannot be handled by the HW
                                        or HAL layers.
                                     */
   VIDENC_HAL_ENCODER_ERROR = 0x1, /**< this is generated when a workload is
                                        returned with an error status.
                                     */
} videnc_hal_error_t;

/**
Statistics collected from the encode process.
*/
typedef struct {
   unsigned long es_encoded;                /**< Total number of es buffers generated */
   unsigned long frames_encoded;            /**< Total number of frame encoded */
   unsigned long frames_dropped;            /**< Total number of frame dropped by hal */
   unsigned long scene_change_frames;       /**< Total number of frames that were detected as scene change */
} videnc_hal_stream_statistics_t;

/** videnc_hal_debug_level_t defines the debug levels to enable/disable
    the logging of debug messages.
    DEBUG_LEVEL_OFF    : no logging
    DEBUG_LEVEL_ERRORS : error message will be printed by VIDENC_LOG
                         defined below.
    DEBUG_LEVEL_ON     : the debug information will be printed by VIDENC_LOG.

    DEBUG_LEVEL_ON should be used to enable printing of any debug information.
    DEBUG_LEVEL_ERRORS should be used to print any error messages.
 */
typedef enum
{
   DEBUG_LEVEL_OFF     = 0,
   DEBUG_LEVEL_ERRORS  = 1,
   DEBUG_LEVEL_ON      = 2,
} videnc_hal_debug_level_t;

/** This macro is used for printing debug messages
 */
#define VIDENC_LOG(level, format...) if(level > DEBUG_LEVEL_OFF) OS_PRINT(format)
//#define VIDENC_LOG(level, format...) OS_PRINT(format)
#define VIDENC_ERR(format...) VIDENC_LOG(DEBUG_LEVEL_ERRORS, format)
#define VIDENC_DBG(format...) VIDENC_LOG(DEBUG_LEVEL_OFF, format)

/** videnc_hal_sven_level_t defines the sven levels to enable/disable
    the logging of sven messages.
 */
typedef enum
{
   SVEN_LEVEL_OFF       = 0x0,
   SVEN_LEVEL_CRITICAL  = 0x1,   //   1: Error / Critical Conditions / API
   SVEN_LEVEL_DATA_FLOW = 0x2,   //   2: Data flow                 
   SVEN_LEVEL_DEBUG     = 0x4,   //   3: Generic Debug
   SVEN_LEVEL_FUNCTION  = 0x8    //   4: Function enter/exit
} videnc_hal_sven_level_t;

#define DEFAULT_SVEN_DEBUG_LEVEL_OVERRIDE 2
#define DEFAULT_SVEN_DEBUG_LEVEL          12

/** extern variable used for hal events in hal and driver */
extern uint32_t videnc_sven_level;

#define VIDENC_SEND_SVEN_EVENT(level, devh, event, a, b, c, d, e, f) \
            if((level) & (videnc_sven_level)) { \
                devh_SVEN_WriteModuleEvent(devh ,event, a, b, c, d, e, f); \
            }

#define VIDENC_SVEN_ENTER(devh) if((NULL != devh) && ((SVEN_LEVEL_FUNCTION) & (videnc_sven_level))) \
   { DEVH_FUNC_ENTER(devh); }

#define VIDENC_SVEN_EXIT(devh) if((NULL != devh) && ((SVEN_LEVEL_FUNCTION) & (videnc_sven_level))) \
   { DEVH_FUNC_EXIT(devh); }

/** videnc hal event callbacks

General notes regarding videnc HAL callbacks.

Currently the return value is not used. The data parameter is user
specific and is passed in when the callbacks are registered (via
\ref videnc_hal_register_callbacks). The value passed into
\ref videnc_hal_register_callbacks is passed as is into the callback,
and is not modified by the HAL.

*/

/** This callback is called when the hal has finished encoding an ES buffer.

Example callback prototype:

void videnc_hal_output_available_func_t(void *data);

See the general callback notes section for general videnc HAL callback
behavior.

*/
typedef ismd_result_t (*videnc_hal_output_available_func_t)(void *data);

/** This callback is called when the hal has detected a device error.

Example callback prototype:

ismd_result_t videnc_handle_encoder_error(void *data,
                                          videnc_hal_error_t err);

See the general callback notes section for general videnc HAL callback
behavior.

err is the error condition detected by the HAL
*/
typedef ismd_result_t (*videnc_hal_error_func_t)(void *data,
                          videnc_hal_error_t err);

/** This callback is called when the HAL is out of resources.

Example callback prototype:

ismd_result_t videnc_handle_resources_error(void *data);

See the general callback notes section for general videnc HAL callback
behavior.
*/
typedef ismd_result_t (*videnc_hal_out_of_resources_func_t)(void *data);

/** This callback is called when the input to the encoder has room for
additional data.

Example callback prototype:

ismd_result_t videnc_hal_input_not_full_func_t(void *data);

See the general callback notes section for general videnc HAL callback
behavior.

*/
typedef ismd_result_t (*videnc_hal_input_not_full_func_t)(void *data);

/** This callback is called when a resolution or frame rate change was detected
on the input stream.

Example callback prototype:

ismd_result_t videnc_handle_stream_settings_change(void *data);

See the general callback notes section for general videnc HAL callback
behavior.

*/
typedef ismd_result_t (*videnc_hal_input_stream_settings_change_t)(void *data);

/**
    This data structure defines the interface that the client programmer uses
    to setup the HAL callbacks. This structure should be filled out by the
    the driver prior to calling the \ref videnc_hal_register_callbacks API.
    If the driver is not interested in a particular callback, then it should
    specify the value of NULL to the driver.

    IMPORTANT NOTE: This structure should be completely initialized by the
    host programmer, otherwise the behavior is undefined. If a field is
    not used, do not leave it unitialized. Set the value to NULL.
 */
typedef struct videnc_hal_events
{
   videnc_hal_output_available_func_t        es_buf_available;  /**< called when there 
                                                                is output avaiable */
   videnc_hal_error_func_t                   enc_err;           /**< called when an encoder
                                                                error is detected */
   videnc_hal_out_of_resources_func_t        resources_err;     /**< called when the encoder
                                                                is out of resources */
   videnc_hal_input_not_full_func_t        input_not_full;   /**< called when a low
                                                                watermark event is
                                                                detected on the
                                                                input, signals
                                                                that the underlying
                                                                HW is ready for
                                                                more data. */
   videnc_hal_input_stream_settings_change_t settings_change;   /**< called when a change
                                                                was detected on the inputs
                                                                stream. */
} videnc_hal_events_t;

/** end hal data structures
 */


/** videnc hal methods
 */

/** Performs basic HW initialization. After this function is called, the HW
    platform is in a usable state.

    @param isr_mode - specifies if encoder should be configured in polled or
                      interrupt mode

    @retval ISMD_SUCCESS : the HAL has successfully initialized the HW platform
 */
ismd_result_t videnc_hal_init(int isr_mode);

/** Performs actions to shutdown the HW. Only one state is supported
   (full shutdown). */
void videnc_hal_deinit(void);

/** Opens a new HAL stream. A codec type must be specified. The handle to the
    newly opened stream is returned in the videnc_hal_stream_t * parameter.

    @param[in] codec - codec format for the stream
    @param[out] h - stream handle that is used to identify the stream in
                    subsequent actions
    @param [in] frame_width - The maximum width expected on the input
                              frame buffer stream. 0 if this is unknown.
    @param [in] frame_height - The maximum height expected on the input
                               frame buffer stream. 0 if this is unknown.
    @param [in] scene_change_detect - True if should attempt to use scene change
                               detection hardware.
    @param [in] lookahead_count - How many frames of lookahead to use for
                                  scene change detection
    @param[out] h - stream handle that is used to identify the stream in
                    subsequent actions
    @retval ISMD_SUCCESS - stream successfully created
    @retval ISMD_ERROR_INVALID_PARAMETER - codec format was not valid
    @retval ISMD_ERROR_NO_RESOURCES - the maximum number of streams for
                                      the platform has been reached
*/
ismd_result_t videnc_hal_open(ismd_codec_type_t codec_type, uint32_t frame_width,
                              uint32_t frame_height,
                              bool scene_change_detect,
                              uint32_t lookahead_count,
                              videnc_hal_stream_t *h);

/** Releases the state information for the specified HAL stream.
    @param[in] h - handle of stream to close
*/
ismd_result_t videnc_hal_release_resources(videnc_hal_stream_t h);

/**
Registers event handlers for the different events that the video encoder
can generate. Pass in a value of NULL to indicate that the specific callback
is not of interest. see \ref videnc_hal_events_t for a list of valid
callbacks.

The callbacks are specified on a per stream basis, although the same
functions can be specified for multiple streams...

   @param[in] h: Handle to HAL stream type to register these callbacks to
   @param[in] event_handlers: List of callbacks to call when encoder events
                              happen.
   @param[in] data: Arbitrary data that the client programmer can pass into
                    the HAL. This data will be passed 'AS IS' to the
                    callback function for use by the callback. This data is
                    not used by the HAL in any way.

   @retval ISMD_SUCCESS : Callbacks were successfully registered.

Example:

   videnc_hal_events_t callbacks;
   ismd_result_t result = ISMD_SUCCESS;

   callbacks.es_buf_available = videnc_output_available;
   callbacks.enc_err = NULL;
   callbacks.input_not_full = NULL;
   callbacks.settings_change = NULL;

   result = videnc_hal_register_callbacks(h, callbacks,
                                          (void *)videnc_context);

This snippet registers the videnc_output_available() and
videnc_handle_eos() functions as callbacks for the buffer available encoded and
EOS HAL events. It indicates that encoder error events do not have a handler
defined. The data parameter is used to pass in the driver's context. This
information is not processed by the HAL. It is simply passed back to the
callback unmodified.

*/
ismd_result_t videnc_hal_register_callbacks(videnc_hal_stream_t h,
                             videnc_hal_events_t event_handlers,
                             void *data);

/** Starts the stream.

    @param[in] h - handle of stream to start
    @retval ISMD_SUCCESS : Start completed without error
*/
ismd_result_t videnc_hal_start(videnc_hal_stream_t h);

/** Stops the stream.

    @param[in] h - handle of stream to stop
    @retval ISMD_SUCCESS : Stop completed without error
*/
ismd_result_t videnc_hal_stop(videnc_hal_stream_t h);

/** Flushes the data currently in the encoder.

    @param[in] h - handle of stream to flush
    @retval ISMD_SUCCESS : flush completed without error
*/
ismd_result_t videnc_hal_flush(videnc_hal_stream_t h);

/** Returns true if the input port is NOT FULL, false if the
    input port is full

   @param[in] h: Handle to HAL stream. This stream's input level is checked
                 to see if there is space available in the input.

   @retval true : Space is available
   @retval false: No space available
 */
bool videnc_hal_input_not_full(videnc_hal_stream_t h);

/** Interface for writing frame buffers to HW. This function returns when
    the buffer is sent to the HW, but not necessarily when the HW xfer
    completes. For example, if the underlying platform uses DMA to send
    the buffer to the encoder, this function will return when the DMA xfer has
    been setup, not when it has completed.

    @param[in] h: Handle to hal stream to write the buffer to
    @param[in] buf: Buffer to write along with user data

    @retval ISMD_SUCCESS : Buffer successfully sent to HW for processing
    @retval ISMD_ERROR_NO_SPACE_AVAILABLE : Encoder input is full, and cannot
                                            accept any more data for processing
 */
ismd_result_t videnc_hal_push_frm_buffer(videnc_hal_stream_t h,
                                        videnc_hal_input_data_t* buf);

/** Interface for reading es buffers.

    @param[in] h: Handle to hal stream to write the buffer to
    @param[in] buf: Buffer to read

    @retval ISMD_SUCCESS : Buffer successfully sent to HW for processing
    @retval ISMD_ERROR_NO_DATA_AVAILABLE : output queue is empty
 */
ismd_result_t videnc_hal_pull_es_buffer(videnc_hal_stream_t h,
                                        ismd_buffer_handle_t* buf);

/** Queries the HAL to get the FW version number

    @param[out] fw_major_num : major number of the FW
    @param[out] fw_minor_num : minor number of the FW
    @param[out] build_num    : build number of the FW
 */
void videnc_hal_get_fw_version_num(unsigned int *fw_major_num,
                                   unsigned int *fw_minor_num,
                                   unsigned int *build_num);

/** Returns the encode statistics from the HAL's point of view.
    @param[in] h : Handle to HAL stream to query
    @param[out] stats : Variable to store hal stats

    @retval ISMD_SUCCESS : we're able to return the dropped frame count
    @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : underlying platform does not
                                               support this feature.
 */
ismd_result_t videnc_hal_get_stream_statistics(videnc_hal_stream_t h,
                                       videnc_hal_stream_statistics_t  *stats);
/**
   This function initializes the h264 encoder
   @param[in] h : Handle to HAL stream
   @param[in] profile : H.264 profile
   @param[in] level : H.264 level

   @retval ISMD_SUCCESS: Successfully initialized the encoder.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : One of the settings was invalid.
 */
ismd_result_t videnc_hal_h264_init(videnc_hal_stream_t h,
	              ismd_videnc_h264_profile_t profile, 
                      ismd_videnc_h264_level_t level);

/**
   This function gets the previously initialized params.
   @param[in] h : Handle to HAL stream
   @param[out] profile : H.264 profile
   @param[out] level : H.264 level
 */
ismd_result_t videnc_hal_h264_get_init_params(videnc_hal_stream_t h,
	              ismd_videnc_h264_profile_t *profile, 
                      ismd_videnc_h264_level_t *level);

/**
Determines whether or not to use the end of sequence indications from the 
input stream (received from viddec). This can be useful, for example, for slideshow content.  

   @param[in] videnc: Handle to the video encoder
   @param[in] reuse: true=reuse, false=do not reuse

   @retval ISMD_SUCCESS: Successfully set the parameter.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST: The command is invalid in the current encoder
                                       state
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The requested settings aren't supported.
   @retval ISMD_ERROR_OPERATION_FAILED: FW failure. Try modifying the settings.
 */
ismd_result_t videnc_hal_set_reuse_input_end_sequence(videnc_hal_stream_t h,
		bool reuse);

/**
Returns whether or not the encoder reuses the end of sequence indications from the 
input stream (received from viddec). This can be useful, for example, for slideshow content.

   @param[in] videnc: Handle to the video encoder
   @param[out] reuse: true if reusing, false if not

   @retval ISMD_SUCCESS: Successfully read the parameter.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
 */
ismd_result_t videnc_hal_get_reuse_input_end_sequence(videnc_hal_stream_t h,
		bool *reuse);

/**
Sets the scene change detection threshold.  

   @param[in] videnc: Handle to the video encoder
   @param[in] scd_threshold: A number between 0 to ISMD_VIDENC_MAX_SCD_THRESHOLD_VALUE value indicates the threshold, 0 is for the most sensitive value.

   @retval ISMD_SUCCESS: Successfully set the parameter.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST: The command is invalid in the current encoder
                                       state
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The requested settings aren't supported.
   @retval ISMD_ERROR_OPERATION_FAILED: FW failure. Try modifying the settings.
 */
ismd_result_t videnc_hal_set_scd_threshold(videnc_hal_stream_t h,
		unsigned int scd_thershold);

/**
Gets the scene change detection threshold value.

   @param[in] videnc: Handle to the video encoder
   @param[out] reuse: The threshold value

   @retval ISMD_SUCCESS: Successfully read the parameter.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
 */
ismd_result_t videnc_hal_get_scd_threshold(videnc_hal_stream_t h,
		unsigned int *scd_thershold);

/**
   This function sets the encoder params.
   @param[in] h : Handle to HAL stream
   @param[in] params : the encoding params

   @retval ISMD_SUCCESS: Successfully set the encoding params.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
 */
ismd_result_t videnc_hal_h264_set_encoder_params(videnc_hal_stream_t h,
                           ismd_videnc_h264_encoder_params_t *params);

/**
   This function gets the encoder params.
   @param[in] h : Handle to HAL stream
   @param[out] params : the encoding params
 */
ismd_result_t videnc_hal_h264_get_encoder_params(videnc_hal_stream_t h,
                           ismd_videnc_h264_encoder_params_t *params);

ismd_result_t videnc_hal_configure_isr(int isr_mode);

/* release hal resources on suspend */
void videnc_hal_suspend(void);

/* hal open on resume */
ismd_result_t videnc_hal_resume(void);

/**
   This function sets the encoding flags for user data.
   @param[in] rule:  The user data copying rule.
   @param[in] input_desc: Descriptor for the frame buffer.
   @param[out] flags_for_driver: The flags the driver should pass to the FW.

   @retval true:  The flags were set.
   @retval false: The flags were not set.
 */
bool videnc_hal_set_driver_ud_flags(ismd_videnc_h264_ud_rule *rule,
                      ismd_buffer_descriptor_t *input_desc,
                      uint32_t *flags_for_driver);

/*************************************************************************************/

ismd_result_t videnc_hal_h264_get_encoder_params(videnc_hal_stream_t h,
                           ismd_videnc_h264_encoder_params_t *params);

extern int get_buf_size_from_memory_layout(char *buf_name, int len);

extern ismd_result_t videnc_hal_set_per_input_encoding_policies(videnc_hal_stream_t h,
		ismd_videnc_per_input_encoding_policies_t *policies);

extern void videnc_hal_set_soc_info(pal_soc_info_t *soc_info);

typedef struct
{
    uint32_t stream_settings_adjust_level_to_input;
    uint32_t slice_parameters_transform_8x8;
    uint32_t slice_parameters_intra_8x8;
    uint32_t slice_parameters_cabac_init_idc;
    uint32_t slice_parameters_loop_filter_loop_filter;
    uint32_t slice_parameters_loop_filter_loop_filter_alpha_offset;
    uint32_t slice_parameters_loop_filter_loop_filter_beta_offset;
    uint32_t slice_parameters_intra_16x16;
    uint32_t slice_parameters_intra_4x4;
    uint32_t slice_parameters_disable_prediction_intra_mode_4x4;
    uint32_t slice_parameters_disable_prediction_intra_mode_8x8;
    uint32_t slice_parameters_disable_prediction_intra_mode_16x16;
    uint32_t slice_parameters_disable_prediction_inter_partition;
    uint32_t slice_parameters_disable_prediction_inter_mode_b;
    uint32_t slice_parameters_disable_skip;
    uint32_t slice_parameters_disable_P8x8_ref_0;
    uint32_t slice_parameters_disable_quart_pixel;
    uint32_t slice_parameters_force_PCM;
    uint32_t rate_control_sliceQP;
    uint32_t rate_control_Cb_QP_offset;
    uint32_t rate_control_Cr_QP_offset;
    uint32_t LDA_mode;	/* either "default" or intel-custom */
} ismd_videnc_h264_hidden_parameters_t;

extern ismd_result_t videnc_hal_h264_get_hidden_parameters(videnc_hal_stream_t h,
                ismd_videnc_h264_hidden_parameters_t *params);

extern ismd_result_t videnc_hal_h264_set_hidden_parameters(videnc_hal_stream_t h,
                ismd_videnc_h264_hidden_parameters_t *params);

/** end hal methods
 */

#ifdef __cplusplus
}
#endif
#endif /* __VIDENC_HAL_H__*/
