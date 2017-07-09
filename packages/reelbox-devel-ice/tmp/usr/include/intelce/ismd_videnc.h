/*
* File Name: ismd_videnc.h
*/

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
  Santa Clara, CA  97052

  BSD LICENSE

  Copyright(c) 2011 Intel Corporation. All rights reserved.
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
*  Authors:  Video Encoder Software Team
*/

/** @weakgroup ismd_videnc Video Encoder API/structures

<H3>Overview</H3>

The SMD video encoder module provides hardware accelerated compression of
decompressed video streams.
The following compression standards are supported:

- H.264 (supports High Profile up to Level 4.1)<br>

Video encode capabilities are exposed through a stream interface. For a given
stream, decompressed video frames are passed into the video encoder as input.
A compressed video elementary stream is emitted as output. Up to two instances
of the encoder may be opened at once, and streams are completely independent
entities. The actions/operations on one stream in the system will not affect
other streams that are running concurrently.

<H3>Input and Output Interfaces</H3>

The SMD videnc module interfaces are standard \ref smd_core "SMD Ports" where
buffers may be read/written by the client or which may be connected to upstream
or downstream modules.

The SMD videnc module contains three port interfaces:

1) An input port that receives video frame buffers.<br>
2) An output port that emits encoded elementary stream buffers.<br>
3) A user data input port for inserting user data into the bitstream.<br>

The port interfaces are per stream entities. That is, each stream will have its
own input, output, and user data ports.

It should be noted that passing a NULL pointer or an invalid pointer (that
points to invalid address space) is an application error. The behavior of the
encoder in this case is to crash. Here, the kernel dump can be used to figure
out which line of the code received the invalid pointer. The encoder shall not
return a NULL pointer error message.

<H3>Events</H3>

In addition to data channels, the SMD videnc module provides applications with
notification of encoder events asynchronously. The application can be notified
when:

1) The encoder is out of memory.<br>
2) The input stream's resolution or frame rate has changed.<br>
3) The end of the stream was detected and encoded.<br>
4) There was a bitstream error detected.<br>

<H3>Theory of Operation</H3>

I. Setup/Intialization

-# Open a new stream using \ref ismd_videnc_open. Specify the type of video
compression you'd like to generate, initialization parameters for the stream
(such as the maximum resolution expected on the input stream), and
initialization parameters for the particular codec.<br>
-# Query the encoder for the input/output ports using \ref ismd_videnc_get_input_port and \ref ismd_videnc_get_output_port.<br>
-# Set encoder policies and behaviors using the different control interfaces (use get functions to get the defaults for the
selected codec and parameters, and use set functions to change them).
-# For H.264: set the H.264 encoding parameters, by calling \ref ismd_videnc_h264_get_encoding_params to get the
default settings, change the desired parameters and call \ref ismd_videnc_h264_set_encoding_params <br>
-# Query the encoder for the supported events using \ref ismd_videnc_get_event.<br>

II. Compression

-# Write video frame buffers into the encoder using \ref ismd_port_write.<br>
-# Read encoded stream via \ref ismd_port_read.<br>
-# Wait for the EOS event using \ref ismd_event_wait.<br>

III. Shutdown

-# Shutdown stream using \ref ismd_dev_close.<br>

<H3>User Data and SEI Frame Packing Information</H3>

The SMD videnc module provides for the inclusion of User Data and SEI
Frame Packing Information in the encoded video stream.

Because there are many kinds of User Data, and because it is difficult
to anticipate the needs of all the clients of the encoder, the User
Data portion of the videnc module provides an interface for the middleware
to specify how user data in input frames should be copied to the user
data portion of the encoded output video stream.

These specifications come in the form of "rules" that describe what to
do for specific kinds of user data input, with the option for matching
portions of the user data content to determine if the rule applies.

By default, user data in the input video stream is discarded.  Once one
or more rules have been supplied to the videnc module, the module begins
reading user data buffers and attempts to find a rule that matches.

Once a rule matches, the driver executes the action associated with the rule,
and then returns to reading subsequent user data buffers; any further rules
that the driver may have are not checked.

Rules are added to the driver one at a time, using
\ref ismd_videnc_add_ud_conversion_rule.  All of the rules can be cleared
out using \r ismd_videnc_delete_ud_conversion_rules. The driver allows
for a maximum of MAX_UD_RULES.

The rules are processed in the order they were added.

The rules work as follows:

-# ISMD_VIDENC_H264_UD_RULE_TYPE_608_CC.  This is a special purpose
rule for converting EIA 608 closed caption data into H.264 registered
or unregistered user data.  The Middleware can supply a buffer that
is copied into the initial part of the user data buffer. The MW should
supply a country code for registered user data or a GUID for unregistered
user data.
Once the leading bytes have been copied in, the driver formats the
EIA 608 closed caption data using the Captioning Data Syntax as found
in section 6.2.3.1 of the ATSC A/53 Specification (2007), and in
section B.5.1 of
    ETSI TS 101 154 V1.9.1 (2009-09)
    Technical Specification
    Digital Video Broadcasting (DVB);
    Specification for the use of Video and
    Audio Coding in Broadcasting Applications
    based on the MPEG-2 Transport Stream.
This syntax is common to several Digital Video standards.  This is done
in C code, since the Captioning Data Syntax requires bit-level operations
(not just copying bytes), and these are very difficult to express using
a rule structure.
Closed captions that are decoded by the SMD decoder are transferred also over 
the user data port, and there is an option to handle them by using the general 
ISMD_VIDENC_H264_UD_RULE_TYPE_UD rule.  Using both rules together will cause the encoder 
to generate the equivalent SEI information of H.264 registered user data containing the captions.
In order to prevent duplication of the data - which appears on hoth the frame attributes
(formatted as a closed captions sructure) and on the user data port (formatted as user data),
the CC608 dedicated rule cannot appear along with a rule with rule_type of ISMD_VIDENC_H264_UD_RULE_TYPE_UD
and with dest_type of ISMD_VIDENC_H264_SEI_TYPE_UD_REGISTERED.
This is enforced by \ref ismd_videnc_add_ud_conversion_rule.

This rule is processed regardless the user data port and relies on the structure EIA_608_capt
of the frame attributes.

-# ISMD_VIDENC_H264_UD_RULE_TYPE_UD.  This is a general purpose rule.
It allows copying data from any kind of incoming user data to H.264
registered or unregistered user data.  As with the rule for EIA 608 data,
the MW should supply a country code for registered user data or a GUID
for unregistered user data.

-# ISMD_VIDENC_H264_UD_RULE_TYPE_SEI_FRAME_PACKING.  This is a special purpose
rule for encoding H.264 SEI frame packing data.
This rule simply copies H.264 SEI Frame Packing information from the
incoming frame to the outgoing frame.
The rule must have exactly one copy operation which specifies to copy the full input data.
*/
#ifndef __ISMD_VIDENC_H__
#define __ISMD_VIDENC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_global_defs.h"
#include "ismd_videnc_h264_encoding_params.h"

/** @ingroup ismd_videnc */
/** @{ */

/** Number of concurrent streams allowed.
 *
 */
#define ISMD_VIDENC_MAX_STREAMS   2

/**
 * Number of consecutive dropped frames after which the driver
 * sends an event.
 */
#define ISMD_VIDENC_MAX_CONSECUTIVE_DROPS	20

/**
Events that the encoder can generate.
*/
typedef enum {
    ISMD_VIDENC_STREAM_PROPS_CHANGE   = 0x0, /**< Resolution or frame rate change */
    ISMD_VIDENC_EOS                   = 0x1, /**< End of stream reached */
    ISMD_VIDENC_CLIENT_ID_SEEN        = 0x2, /**< Client id seen */
    ISMD_VIDENC_ENCODER_ERROR         = 0x3, /**< An error was detected */
    ISMD_VIDENC_OUT_OF_RESOURCES      = 0x4, /**< Encoder is out of resources */
    ISMD_VIDENC_DROPPED_FRAMES        = 0x5, /**< Dropped
                                                  ISMD_VIDENC_DEFAULT_MAX_CONSECUTIVE_DROPS
                                                  consecutive frames */
    ISMD_VIDENC_INPUT_ERROR           = 0x6, /**< Input frame did not match encoding parameters */
} ismd_videnc_event_t;

/**
Statistics collected from the encoding process.
*/
typedef struct {
   unsigned long es_encoded;       /**< Total number of es buffers generated */
   unsigned long frames_encoded;   /**< Total number of frames encoded */
   unsigned long frames_dropped;   /**< Total number of frames dropped */
   unsigned long scene_change_frames;   /**< Total number of frames that were detected as scene change */
} ismd_videnc_stream_statistics_t;

/**
Parameters used for initializing the selected codec.
*/
typedef union {
   ismd_videnc_h264_init_params_t   h264_init_params;   /**< Initial parameters for H.264 codec */
   // Initial parameters of other codecs to go here
} ismd_videnc_codec_init_params_t;

/**
Type of scan mode for encoder to use
*/
typedef enum
{
   ISMD_VIDENC_SCAN_MODE_ENCODE_PROGRESSIVE = 0,    /**< Encode as progressive */
   ISMD_VIDENC_SCAN_MODE_ENCODE_INTERLACED_FRAME,   /**< Encode as interlaced, encode both fields together */
   ISMD_VIDENC_SCAN_MODE_ENCODE_INTERLACED_FIELD,   /**< Encode as interlaced, encode each field seprately */
   ISMD_VIDENC_SCAN_MODE_ENCODE_INTERLACED_PAFF     /**< Encode as interlaced Picture Adaptive Frame-Field coding:
                                                         choose between frame/field encoding as appropriate */
} ismd_videnc_scan_mode_t;

/**
Bit-field of options to enable/disable when encoding interlaced input (options can be OR'ed)
*/
typedef enum
{
   ISMD_VIDENC_INPUT_INTERLACED_FLAGS_NONE = 0,
   ISMD_VIDENC_INPUT_INTERLACED_FLAGS_DO_PULLDOWN = (1<<0)    /**<  Pass the pull down information
                                                                    to the produced stream when it
                                                                    is relevant.
                                                                    THIS FLAG IS DEPRECATED -
                                                                    when the input stream has pull
                                                                    down information, it will be passed
                                                                    to the produced stream irrespective
                                                                    of the flag setting */
   //... = (1<<1)
   //... = (1<<2)
   //...
} ismd_videnc_input_interlaced_flags_t;

/**
Bit-field of options to enable/disable when encoding progressive input (options can be OR'ed)
*/
typedef enum
{
   ISMD_VIDENC_INPUT_PROGRESSIVE_FLAGS_NONE = 0,
   ISMD_VIDENC_INPUT_PROGRESSIVE_FLAGS_HALVE_FRAME_RATE = (1<<0)    /**< E.g. 50p->25p */
   //... = (1<<1)
   //... = (1<<2)
   //...
} ismd_videnc_input_progressive_flags_t;

/**
Bit-field of options to enable/disable when encoding deinterlaced input (interlaced input
that went through deinterlacing in the DPE).  (options can be OR'ed).
*/
typedef enum
{
   /** If encoding as progressive, can produce a double frame-rate output,
    * using the original field rate (e.g. 50i->50p)
    */
   ISMD_VIDENC_INPUT_DEINTERLACED_FLAGS_NONE = 0,
   ISMD_VIDENC_INPUT_DEINTERLACED_FLAGS_DOUBLE_FRAME_RATE_PROGRESSIVE = (1<<0)
   //... = (1<<1)
   //... = (1<<2)
   //...
} ismd_videnc_input_deinterlaced_flags_t;

/**
Encoding policies.
*/
typedef struct
{
   /** Interlaced input policies. H.264 encoder supports interlaced field/frame/paff */
   ismd_videnc_scan_mode_t                     interlaced_input_encoding_scan_mode;
   ismd_videnc_input_interlaced_flags_t        interlaced_input_flags;

   /** Progressive input policies. H.264 encoder supports progressive encoding scan mode */
   ismd_videnc_scan_mode_t                     progressive_input_encoding_scan_mode;
   ismd_videnc_input_progressive_flags_t       progressive_input_flags;

   /** Deinterlaced input policies. H.264 encoder supports interlaced field/progressive encoding scan modes */
   ismd_videnc_scan_mode_t                     deinterlaced_input_encoding_scan_mode;
   ismd_videnc_input_deinterlaced_flags_t      deinterlaced_input_flags;
} ismd_videnc_per_input_encoding_policies_t;

/**
Parameters for the scene change detection hardware in the encoder.

Scene change detection increases the efficiency of the encoding.  If the
frame being examined is determined to be one where the scene changes,
the encoder will shorten the current GOP, and start a new GOP with the
examined frame as the IDR frame at the beginning of the GOP.

If there is a non-zero lookahead value, the scene change detection
hardware can tell the encoder that a scene change will occur after N
frames. (N is in the range 1..lookahead amount.) The encoder can then
extend the length of the current GOP (by up to half of the original
GOP length).  Then the frame which starts a new scene can become the
IDR frame at the beginning of the next GOP.

The sensitivity threshold of the encoder is controlled by using
\ref ismd_videnc_get_stream_scd_threshold and \ref ismd_videnc_set_stream_scd_threshold.
Use smaller threshold for higher sensitivity; note that lower values
have the chance for false scene change detections and higher values
can lead to miss some true scene changes.
This value is content-dependant and the same threshold may produce different
results for different media clips.

The maximum number of lookahead frames allowed by the driver
is set by the value of videnc.max_scd_lookahead in the platform config file.

See the platform config file for notes about what to do if the value
needs to be increased.

NOTE: These parameters are not supported by the encoder in the CE4200.
*/
typedef struct
{
    bool        scene_change_detect_enabled;    /**< True if we want to do scene change detection */
    uint32_t    lookahead_count;                /**< How many frames to lookahead, ignored if
                                                     scene_change_detect_enabled is false.
                                                     The maximum is defined in the
                                                     platform configuration file. */
} ismd_videnc_scene_change_detect_params_t;

/**
 * Maximal allowed scene change detection sensitivity threshold.
 */
# define ISMD_VIDENC_MAX_SCD_THRESHOLD_VALUE 10000

/**
 * Default scene change detection sensitivity threshold.
 */
# define ISMD_VIDENC_DEFAULT_SCD_THRESHOLD_VALUE 595

/**
Initialization parameters that are codec-independent.
Max_frame_width must be a multiple of 4 between 48 and 1920.
Max_frame_height must be a multiple of 4 between 48 and 1080.
If either is zero, the driver uses a default of the maximum value.
*/
typedef struct
{
    uint32_t                                    max_frame_width;      /**< Maximum frame width */
    uint32_t                                    max_frame_height;     /**< Maximum frame height */
    ismd_videnc_scene_change_detect_params_t    scene_change_control; /**< Scene change control */
} ismd_videnc_stream_init_params_t;

/* Following are defines, enums and structs for user data rules */

#define MAX_UD_COMPARISON_BYTES 16         /**< Number of bytes for comparison when matching */
#define MAX_RULE_BUF_SIZE       64         /**< Size of buffer in user data rule */
#define MAX_COPY_DESCRIPTORS    5          /**< Maximum number of specifications of what to copy */
#define COPY_FULL_UD_BUFFER     0xFFFFFFFF /**< Special value meaning copy all the original user data */
#define MAX_UD_RULES            20         /**< Maximum number of rules that can be supplied */

/**
The kind of input data to which the rule applies.
*/
typedef enum
{
   ISMD_VIDENC_H264_UD_RULE_TYPE_UD,      /**< Rule for converting an input
                                               user data buffer to H264 user data. */
   ISMD_VIDENC_H264_UD_RULE_TYPE_608_CC,  /**< Rule for converting EIA-608 closed
                                               caption data found in input frame
                                               attributes to closed captioning data
                                               embedded in H.264 user data. */
   ISMD_VIDENC_H264_UD_RULE_TYPE_SEI_FRAME_PACKING,  /**< Rule for converting H.264 SEI frame packing
                                                      data buffer to frame packing data*/
} ismd_videnc_h264_ud_rule_t;

/**
The specific kind of incoming user data for which
the rule applies.  We don't use ismd_userdata_type_t
since we want to be able to specify these as bit flags.
*/
typedef enum
{
    ISMD_VIDENC_UD_INPUT_FRAME          = (1 << 0), /**< UD attached to a frame */
    ISMD_VIDENC_UD_INPUT_FIELD          = (1 << 1), /**< UD attached to a field */
    ISMD_VIDENC_UD_INPUT_REGISTERED     = (1 << 2), /**< H.264 registered user data */
    ISMD_VIDENC_UD_INPUT_UNREGISTERED   = (1 << 3), /**< H.264 unregistered user data */
    ISMD_VIDENC_UD_INPUT_FRAME_PACKING  = (1 << 4), /**< H.264 frame packing user data */
} ismd_videnc_h264_ud_input_t;

/**
Specify matching criteria to determine if data in
the video stream matches the rule.
*/
typedef struct
{
   ismd_videnc_h264_ud_rule_t  rule_type;                /**< Type of this rule */
   ismd_videnc_h264_ud_input_t orig_ud_type;             /**< Expected user data type of incoming data.
                                                              Valid only if rule_type=ISMD_VIDENC_H264_UD_RULE_TYPE_UD */
   bool                        compare;                  /**< If true, match rule only if
                                                              comparison_buf_len bytes from
                                                              (incoming user data buffer AND mask) match
                                                              comparison_buf
                                                              (starting at ud_buf_offset).
                                                              Mask values can be anything between 0x00 and 0xFF. */
   uint8_t                     comparison_buf[MAX_UD_COMPARISON_BYTES];      /**< Data to compare against the buffer */
   uint8_t                     comparison_buf_mask[MAX_UD_COMPARISON_BYTES]; /**< Mask, see description above */
   unsigned int                ud_buf_offset;                                /**< Where in the UD buffer to start comparing */
   unsigned int                comparison_buf_len;                           /**< How many bytes to compare,
                                                                                  up to MAX_UD_COMPARISON bytes */
} ismd_videnc_h264_ud_rule_match_criteria;

/**
Specify the source of data to copy to the output buffer
that will be sent to the encoder.
*/
typedef enum
{
   ISMD_VIDENC_H264_UD_REF_ORIG_BUF,      /**< Use original user data buffer as the reference buffer */
   ISMD_VIDENC_H264_UD_REF_GIVEN_BUF      /**< Use a buffer given in this API as the reference buffer */
} ismd_videnc_h264_ud_ref_buf_t;

/**
Description of what to copy to the buffer (user data, SEI frame packing info)
that will be sent to the encoder.
*/
typedef struct
{
   ismd_videnc_h264_ud_ref_buf_t  source;           /**< Indicates source to copy from */
   unsigned int                   orig_ud_offset;   /**< Indicates offset from orig ud
                                                         buffer to copy from. */
   uint8_t                        buf[MAX_RULE_BUF_SIZE]; /**< Buffer to copy (if source
                                                               == ISMD_VIDENC_H264_UD_REF_GIVEN_BUF). */
   unsigned int                   len;              /**< Bytes to copy from orig_ud_offset
                                                         or from buf. COPY_FULL_UD_BUFFER
                                                         to copy all bytes from orig_ud_offset
                                                         until end of ud buffer. */
   unsigned int                   dest_offset;      /**< Offset in destination buffer to copy to */
} ismd_videnc_h264_ud_rule_copy_data;

/**
Describe type of destination buffer for H.264
*/
typedef enum
{
   ISMD_VIDENC_H264_SEI_TYPE_UD_REGISTERED,   /**< Registered User Data */
   ISMD_VIDENC_H264_SEI_TYPE_UD_UNREGISTERED, /**< Unregistered User Data */
   ISMD_VIDENC_H264_SEI_TYPE_FRAME_PACKING    /**< SEI Frame Packing information */
} ismd_videnc_h264_SEI_t;

/**
An actual rule.  When the criteria matches, data is copied as per the
specifications in the copy_data array member.
*/
typedef struct
{
   ismd_videnc_h264_ud_rule_match_criteria  criteria;                         /**< Matching criteria. */
   ismd_videnc_h264_SEI_t                   dest_type;                        /**< Where to put the generated data */
   uint32_t                                 num_copy_descriptors;             /**< How many output specifications there are */
   ismd_videnc_h264_ud_rule_copy_data       copy_data[MAX_COPY_DESCRIPTORS];  /**< Where and how to fill the output */
} ismd_videnc_h264_ud_rule;

/******************************************************************************/
/*!    @name Video encoder device initialization and teardown APIs */

/**
Opens an available video encoder device.
All resources required for normal operation are allocated and the default
encoder capabilites are enabled. This operation must succeed for subsequent
encoder operations to be successful.

The video encoder instance is returned in the videnc handle. Multiple encoder
instances can be created by calling this function multiple times.

The video encoder device is destroyed using the standard Intel SMD close
function.

   @param [in] codec_type: Requested codec format. Supported formats are:
                           H.264.

   @param [in] init_params:  Parameters needed to initialize all codecs.

   @param [in] codec_params: Basic parameters used to initialize the selected codec.
                             Other settings will be automatically initialized to
                             defaults according to the basic parameters provided here.

   @param[out] videnc: Handle to the video encoder. Used in subsequent
                       calls to refer to a specific stream.

   @retval ISMD_SUCCESS: Video encoder handle is created successfully.
   @retval ISMD_ERROR_NO_RESOURCES: No encoder instance is available.
   @retval ISMD_ERROR_OPERATION_FAILED: Video encoder creation failed due to
                                        lack of system resources.
   @retval ISMD_ERROR_INVALID_PARAMETER: One of the initialization parameters
                                         is out of range.
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: Attempt to use scene change features
                                             on SOC that does not support them.
   @retval ISMD_ERROR_OUT_OF_RANGE: Value for one of the parameters is not within
                                    the allowed range.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_open(ismd_codec_type_t codec_type,
                               ismd_videnc_stream_init_params_t *init_params,
                               ismd_videnc_codec_init_params_t *codec_params,
                               ismd_dev_t *videnc);


/******************************************************************************/
/*!    @name Video encoder port interface */
/**
Get the handle to the video encoder input port.
Decompressed video frame buffers are written to the encoder through this port.

   @param[in] videnc: Handle to the video encoder
   @param[out] port : Input port handle

   @retval ISMD_SUCCESS : Stream input port is successfully returned.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
*/
ismd_result_t ismd_videnc_get_input_port(ismd_dev_t videnc,
                                         ismd_port_handle_t *port);

/**
Get the handle to the video encoder output port.
The video encoder writes compressed data to this port.

   @param[in] videnc: Handle to the video encoder.
   @param[out] port : Output port handle.

   @retval ISMD_SUCCESS : Stream output port is successfully returned.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
*/
ismd_result_t ismd_videnc_get_output_port(ismd_dev_t videnc,
                                          ismd_port_handle_t *port);

/**
Get the handle to the user data input port.
The application writes user data to this port. The timestamps of the incoming data are compared
to those of the input frames. Only matching timestamps will be inserted to the resultant stream.

   @param[in] videnc: Handle to the video encoder.
   @param[out] port : User data port handle.

   @retval ISMD_SUCCESS : Stream user data port is successfully returned.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
*/
ismd_result_t  ismd_videnc_get_user_data_port(ismd_dev_t videnc,
                                             ismd_port_handle_t *port);

/******************************************************************************/
/*!    @name Video encoder control interface */

/**
 *  Start, stop, and flush operations use the standard Intel SMD interface.
 */

/**
Set the encoding policies to be used according to the input type.
This function must be called before entering play state.

   @param[in] videnc: Handle to the video encoder
   @param[in] policies: Per input policies to be used by encoder

   @retval ISMD_SUCCESS: Successfully set the policies.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST: The command is invalid in the current encoder
                                       state
   @retval ISMD_ERROR_INVALID_PARAMETER: An invalid parameter was used
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The requested settings aren't supported.
   @retval ISMD_ERROR_OPERATION_FAILED: FW failure.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_set_per_input_encoding_policies(ismd_dev_t videnc,
                                             ismd_videnc_per_input_encoding_policies_t *policies);

/**
Get the encoding policies used by the encoder for handling different input types.

   @param[in] videnc: Handle to the video encoder
   @param[out] policies: Per input policies used by encoder

   @retval ISMD_SUCCESS: Successfully got the policies.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
 */
ismd_result_t ismd_videnc_get_per_input_encoding_policies(ismd_dev_t videnc,
                                                 ismd_videnc_per_input_encoding_policies_t *policies);

/**
Determine whether or not to use the end of sequence indications from the
input stream (received from viddec). This can be useful, for example, for slideshow content.

   @param[in] videnc: Handle to the video encoder
   @param[in] reuse: true=reuse, false=do not reuse

   @retval ISMD_SUCCESS: Successfully set the parameter.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST: The command is invalid in the current encoder
                                       state
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The requested settings aren't supported.
   @retval ISMD_ERROR_OPERATION_FAILED: FW failure.
   @retval ISMD_ERROR_INVALID_PARAMETER: An invalid parameter was used
 */
ismd_result_t ismd_videnc_set_reuse_input_end_sequence(ismd_dev_t videnc, bool reuse);

/**
Get whether or not the encoder reuses the end of sequence indications from the
input stream (received from viddec). This can be useful, for example, for slideshow content.

   @param[in] videnc: Handle to the video encoder
   @param[out] reuse: true if reusing, false if not

   @retval ISMD_SUCCESS: Successfully read the parameter.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_get_reuse_input_end_sequence(ismd_dev_t videnc, bool *reuse);

/*!    @name Video encoder stream properties APIs */

/**
Get stream statistics of the encode process.

   @param[in] videnc: Handle to the video encoder
   @param[out] stat: Receive the stream statistics

   @retval ISMD_SUCCESS: Successfully read stream statistics.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_get_stream_statistics(ismd_dev_t videnc,
                                         ismd_videnc_stream_statistics_t *stat);

/******************************************************************************/
/*!    @name Video encoder user data related APIs */

/**
Supplies a rule to the driver.  Rules are stored per open instance.

This routine can only be called in the stop state.

   @param[in] videnc_handle: Handle to the video encoder.

   @param [in] ud_rule: A pointer to a single rule struct. The rule will
                        be added to the end of the list of rules.
                        A maximum of MAX_UD_RULES may be added per
                        open instance.

   @retval ISMD_SUCCESS: The rule was added to the list successfully.
   @retval ISMD_ERROR_NO_RESOURCES: The rule list is already full.
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The driver is in running state.
   @retval ISMD_ERROR_INVALID_PARAMETER: An invalid parameter was used.
   @retval ISMD_ERROR_NULL_POINTER: One of the parameters was a NULL pointer
 */

ismd_result_t ismd_videnc_add_ud_conversion_rule(ismd_dev_t videnc_handle,
                                                 ismd_videnc_h264_ud_rule *ud_rule);

/**
Removes all previously supplied rules for this open instance.

This routine can only be called in the stop state.

It is not an error to remove the rules if none were added.

   @param[in] videnc_handle: Handle to the video encoder.

   @retval ISMD_SUCCESS: The rules were removed.
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The driver is in running state.
 */
ismd_result_t ismd_videnc_delete_ud_conversion_rules(ismd_dev_t videnc_handle);

/******************************************************************************/
/*!    @name H.264 specific APIs */
/**
Set the parameters of the h264 encode process. To set the encoding parameters, first call
ismd_videnc_h264_get_encoding_params to get the default or current settings, change the desired
parameters and call ismd_videnc_set_encoding_params.
Most parameters can only be changed when the encoder is not in the play state.
Parameters that can be changed also in the play state (on-the-fly changes,
taking effect starting from the next frame): max_bitrate, bitrate.

   @param[in] videnc: Handle to the video encoder
   @param[in] settings: the encoding params

   @retval ISMD_SUCCESS: Successfully set the encoding params.
   @retval ISMD_ERROR_INVALID_HANDLE: The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST: The command is invalid in the current encoder
                                       state or the specified encoder handle is not initialized for h264.
   @retval ISMD_ERROR_NO_SPACE_AVAILABLE: There isn't enough space to process the
                                          request. Try again later.
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: The requested settings aren't supported.
   @retval ISMD_ERROR_OPERATION_FAILED: FW failure.
   @retval ISMD_ERROR_INVALID_PARAMETER: An invalid parameter was used
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_h264_set_encoding_params(ismd_dev_t videnc,
                                         ismd_videnc_h264_encoder_params_t* params);

/**
Get the parameters of the h264 encode process.

   @param[in] videnc: Handle to the video encoder
   @param[out] params: Receive the encoding params

   @retval ISMD_SUCCESS: Successfully read the encoding params.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST : The specified encoder handle is not initialized for h264.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_h264_get_encoding_params(ismd_dev_t videnc,
                                         ismd_videnc_h264_encoder_params_t* params);

/**
Set the scene change detection threshold.
See more details at \ref ismd_videnc_scene_change_detect_params_t.

   @param[in] videnc: Handle to the video encoder
   @param[in] threshold: A number between 0 to ISMD_VIDENC_MAX_SCD_THRESHOLD_VALUE indicates the threshold, 0 is for the most sensitive value.

   @retval ISMD_SUCCESS: Successfully set the scene change detection threshold.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : The threshold value is out of range.
   @retval ISMD_ERROR_INVALID_REQUEST : The specified encoder handle is not initialized for h264.
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: Attempt to set the scene change detection threshold on SOC that does not support it.
 */
ismd_result_t ismd_videnc_set_stream_scd_threshold(ismd_dev_t videnc,
                                                   unsigned int threshold);

/**
Get the scene change detection threshold value.
See more details at \ref ismd_videnc_scene_change_detect_params_t.

   @param[in] videnc: Handle to the video encoder
   @param[out] threshold: Receive the threshold value.

   @retval ISMD_SUCCESS: Successfully read the scene change detection threshold.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_REQUEST : The specified encoder handle is not initialized for h264.
   @retval ISMD_ERROR_NULL_POINTER: One of the parameters was a NULL pointer
   @retval ISMD_ERROR_FEATURE_NOT_SUPPORTED: Attempt to get the scene change detection threshold on SOC that does not support it.
 */
ismd_result_t ismd_videnc_get_stream_scd_threshold(ismd_dev_t videnc,
                                                   unsigned int *threshold);


/******************************************************************************/
/*!    @name Video encoder asynchronous notification APIs */
/**
Gets the event associated with the given event condition.

   @param[in] videnc: Handle to the video encoder.
   @param[in] event_type: Requests the specific event associated with this
                     type.
   @param[out] event: Event that is signalled when the given condition occurs.

   @retval ISMD_SUCCESS: Requested event is returned successfully.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified encoder handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : The event type is invalid.
   @retval ISMD_ERROR_NULL_POINTER : One of the parameters was a NULL pointer
 */
ismd_result_t ismd_videnc_get_event(ismd_dev_t videnc,
                                    ismd_videnc_event_t event_type,
                                    ismd_event_t *event);

/** @} */ // end of ingroup ismd_videnc
/** @} */ // end of weakgroup ismd_videnc


#ifdef __cplusplus
}
#endif

#endif // __ISMD_VIDENC_H__
