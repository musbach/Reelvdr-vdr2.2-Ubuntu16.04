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
 * This file contains the enumerations and function declarations that
 * comprise the mux APIs.
 */

#ifndef __ISMD_MUX_H__
#define __ISMD_MUX_H__

#include "osal.h"
#include "ismd_core.h"
#include "ismd_global_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


/** @weakgroup ismd_mux Mux APIs/Structures

<H3>Overview</H3>

The mux creates MPEG2 transport streams from one or more elementary
input stream.

<H3>Input and Output Interfaces</H3>

The SMD mux module interfaces are standard \ref smd_core "SMD Ports" where
buffers may be read/written by the client or which may be connected to upstream
or downstream modules. Input ports are used to pass in one or more elementary
streams. The resultant MPEG2 transport stream is written to an output port.

The port interfaces are per instance entities. That is, each mux instance will
have its own input and output ports.

It should be noted that passing a NULL pointer or an invalid pointer (that
points to invalid address space) is an application error. The behavior of the
mux in this case is to crash. Here, the kernel dump can be used to figure
out which line of the code received the invalid pointer. The mux shall not
return NULL pointer error message.

<H3>Events</H3>

In addition to data channels, the SMD mux module provides applications with
notification of mux events asynchronously. The application can be notified
when:

1) The end of the stream was detected and encoded.<br>

<H3>Basic Operation</H3>
The mux creates a transport stream from the input elementary streams.
The order in which the incoming elementary stream packets are entered to the
transport stream is determined by the input timestamps and a user defined
offset (or video encoder controlled offset - see \ref ismd_mux_input_stream_config_t). 
Once the EOS identifier is reached on an input stream the mux stops
reading data from the port. Once the EOS has been processed on all input
streams, the transport stream is closed and the mux thread ceases to run.
APIs are defined for setting the PSI data on the resultant stream.

I. Setup/Initialization

-# Open a new stream using \ref ismd_mux_open.<br>
-# Set the parameters of the mux program by first calling
   \ref ismd_mux_get_stream_params to get the default settings and then
   \ref ismd_mux_set_stream_params with the updated settings.<br>
-# Create one or more elementary stream input ports using \ismd_mux_add_input.<br>
-# Query the mux for the output port using \ref ismd_mux_get_output_port.<br>
-# Query the mux for the EOS event using \ref ismd_mux_get_event with the ISMD_MUX_EOS field.<br>

II. Play mode

-# Write elementary stream buffers into the mux using \ref ismd_port_write.<br>
-# Read transport stream via \ref ismd_port_read.<br>
-# Wait for EOS event using \ref ismd_event_wait.<br>

III. Shutdown

-# Shutdown instance using \ref ismd_dev_close.<br>

 */

/** @ingroup ismd_mux */
/** @{ */

/** Number of concurrent mux instances allowed.
 */
#define ISMD_MUX_MAX_INSTANCES   2

/** Defines maximum number of input ports supported per mux program instance */
#define ISMD_MUX_MAX_NUM_INPUT_STREAMS 8

/** PID */
typedef uint16_t ismd_mux_pid_t;

/** Periodic ts handle */
typedef uint32_t ismd_mux_periodic_ts_id_t;

/** This can be used when indicating a PID to instruct the mux to generate one automatically */
#define ISMD_MUX_AUTO_GENERATE_PID ((ismd_mux_pid_t)-1)

/** Transport stream id */
typedef uint16_t ismd_mux_transport_stream_id_t;

/** Program number */
typedef uint16_t ismd_mux_program_num_t;

/** Optional program flags */
typedef enum
{
   ISMD_MUX_PROGRAM_NO_FLAGS = 0,
   ISMD_MUX_MANUAL_PAT_PMT = (1<<0)  /**< PAT and PMT are created and entered manually by the application.
                                          Otherwise PAT and PMT are auto generated. */
   //... = (1<<1)
   //... = (1<<2)
   //...
} ismd_mux_program_flags_t;

/** Optional stream flags */
typedef enum
{
   ISMD_MUX_STREAM_NO_FLAGS = 0,
   ISMD_MUX_STREAM_PROTECTED_BY_COPYRIGHT = (1<<0) /**< Indicates that the material is protected by copyright */
   //... = (1<<0)
   //... = (1<<1)
   //...
}ismd_mux_input_stream_flags_t;

/**
Supported input stream types.
Used in PMT as defined by Table 2.36 of ISO 13818-1 + ATSC and Blu-Ray numbers.
*/
typedef enum
{
   ISMD_MUX_STREAM_TYPE_INVALID = 0x0,             /**< INVALID TYPE */
   ISMD_MUX_STREAM_TYPE_VIDEO_MPEG1 = 0x01,        /**< MPEG1 VIDEO */
   ISMD_MUX_STREAM_TYPE_VIDEO_MPEG2 = 0x02,        /**< MPEG2 VIDEO */
   ISMD_MUX_STREAM_TYPE_AUDIO_MP2 = 0x03,          /**< MP2 AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_MP3 = 0x04,          /**< MP3 AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_MPEG2_AAC = 0xF,     /**< MPEG2 AAC AUDIO */
   ISMD_MUX_STREAM_TYPE_VIDEO_MPEG4 = 0x10,        /**< MPEG4 VIDEO */
   ISMD_MUX_STREAM_TYPE_AUDIO_MPEG4_AAC = 0x11,    /**< MPEG4 AAC AUDIO */
   ISMD_MUX_STREAM_TYPE_VIDEO_H264 = 0x1B,         /**< H264 VIDEO */
   ISMD_MUX_STREAM_TYPE_AUDIO_PCM = 0x80,          /**< BD PCM AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP = 0x81,      /**< BD AC3 AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_DTS = 0x82,          /**< BD DTS AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_TRUE_HD = 0x83,      /**< BD "Dolby Lossless" AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP2 = 0x84,     /**< BD DD+ AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_DTS_HD = 0x85,       /**< BD DTS HD (except XLL) AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_DTS_HD_XLL = 0x86,   /**< BD DTS HD XLL AUDIO */
   ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP3 = 0x87,     /**< Defined in atsc spec: http://www.atsc.org/standards/a_53-Part-3-2007.pdf */
   ISMD_MUX_STREAM_TYPE_VIDEO_VC1 = 0xEA           /**< VC1 Video */
} ismd_mux_input_stream_type_t;

/** Events that can be registered by the application. */
typedef enum
{
   ISMD_MUX_EVENT_EOS = 0,  /**< End of File/Stream (on output stream) event Notification */
   ISMD_MUX_CLIENT_ID_SEEN, /**< Client id seen */
   ISMD_MUX_ERROR,          /**< An error was detected */
   MUX_NUM_OF_EVENTS        /**< Must be last, for internal use only */
}ismd_mux_event_t;

/** Output stream type. */
typedef enum
{
   ISMD_MUX_TYPE_MPEG_TS_188 = 0,  /**< Output is Transport Stream with 188-byte packets  */
   ISMD_MUX_TYPE_MPEG_TS_192,      /**< Output is Transport Stream modified for random-access media, with 192-byte packets (e.g. m2ts) */
   ISMD_MUX_TYPE_MAX               /**< must be last, for internal use only */
} ismd_mux_output_stream_type_t;

/** Describes the input stream mode */
typedef enum
{
   ISMD_MUX_INPUT_MODE_ES = 0, /**< Input is elementary stream packets*/
   ISMD_MUX_INPUT_MODE_TS,     /**< This mode is used to insert full TS packets into the stream. The TS packet headers may be
                                    modified but the payloads will not. This mode should be used for passthrough.
                                    Note that at least one stream must be ES mode.*/
  ISMD_MUX_INPUT_MODE_MAX      /**< must be last, for internal use only */
} ismd_mux_input_stream_mode_t;

/** Determines the mux scheduling between its inputs (according to the type of flow: realtime/background muxing) */
typedef enum
{
   ISMD_MUX_SCHEDULING_MODE_BACKGROUND = 0,  /**< For background (non real-time) flows (data accumulates in all inputs allowing precise scheduling) */
   ISMD_MUX_SCHEDULING_MODE_REALTIME,        /**< For real-time flows (schedules according to real-time state of inputs, e.g. even if no data is available from an input) */
   ISMD_MUX_SCHEDULING_MODE_MAX              /**< must be last, for internal use only */
} ismd_mux_scheduling_mode_t;

/** These determine when to strobe the input stream event */
typedef enum {
   ISMD_MUX_INPUT_STREAM_EVENT_NONE  = 0,
   ISMD_MUX_INPUT_STREAM_ALWAYS      = (1<<0),  /**< Enable all available events */
   ISMD_MUX_INPUT_STREAM_UNDERFLOW   = (1<<1),  /**< If the input stream is empty, whereas another is full */
   ISMD_MUX_INPUT_STREAM_OVERFLOW    = (1<<2),  /**< If the input stream is full, whereas another is empty */
   ISMD_MUX_INPUT_STREAM_LATE_DATA   = (1<<3)   /**< If the time stamp on received data indicates it was supposed to be received earlier */
} ismd_input_stream_event_t;

/**
This structure is used to configure a mux program
@struct ismd_mux_ts_program_params_t
*/
typedef struct {
   ismd_mux_program_num_t      program_num;    /**< Program number (to be used in PAT) - only single program muxing supported */
   ismd_time_t                 pmt_interval;   /**< PMT interval in ticks where each second is 90000 ticks.
                                                    Min value = 900(10ms), max value = 5,400,000(60sec).
                                                    If this is 0, PMT will be inserted once.
                                                    The actual PMT interval will be as close as possible to requested value. */
   ismd_time_t                 pcr_interval;   /**< PCR interval in ticks where each second is 90000 ticks.
                                                    Min value = 900(10ms), max value = 9000(100ms).
                                                    The actual PCR interval will be as close as possible to requested value. */
   ismd_mux_pid_t              pmt_pid;        /**< PID of the PMT */
   uint32_t                    bitrate;        /**< Transport stream bitrate: 0 for VBR based on the input stream bitrates.
                                                    Otherwise - a constant bitrate in bps. Min value = 10,000, max value = 500,000,000. */
   ismd_buffer_handle_t        descriptors;    /**< Optional descriptors added to PMT table. Memory region must be accessible by driver.
                                                    If this is not used, it should be set to ISMD_BUFFER_HANDLE_INVALID. */
   ismd_mux_program_flags_t    flags;          /**< Additional options for program configuration */
} ismd_mux_ts_program_params_t;

/**
This structure is used to configure the transport stream
@struct ismd_mux_transport_stream_params_t
*/
typedef struct {
   ismd_mux_transport_stream_id_t transport_stream_id;  /**< Used in the PAT table. */
   ismd_time_t                    pat_interval;         /**< PAT interval in ticks where each second is 90000 ticks.
                                                             Min value = 900(10ms), max value = 5,400,000(60sec).
                                                             If 0 PAT will be inserted once.
                                                             The actual PAT interval will be as close as possible to requested value.*/
   ismd_mux_ts_program_params_t   program_params;       /**< mux is created with a single program */
} ismd_mux_transport_stream_params_t;

/**
This structure is used to configure the muxed stream
@struct ismd_mux_stream_params_t
*/
typedef struct {
   ismd_mux_scheduling_mode_t 	  scheduling_mode;
   union
   {
       ismd_mux_transport_stream_params_t ts_params;
   };
} ismd_mux_stream_params_t;

/**
This structure is used to configure the input stream
@struct ismd_mux_input_stream_config_t
*/
typedef struct {
   ismd_mux_input_stream_mode_t        stream_mode;                /**< mode of input, e.g ES/TS buffers */
   ismd_mux_input_stream_type_t        stream_type;                /**< stream type e.g. H264 */
   ismd_time_t                         ts_offset;                  /**< Expected (approximate) offset of DTS (PTS when there is no DTS) preceding the PCR -
                                                                        used for ordering input stream data relative to PCR.
                                                                        In ticks where each second is 90000 ticks.
                                                                        Note: for video inputs, this offset is used only in passthrough mode, or in case
																		the video encoder doesn't provide CPB information (in the original_ats field of the es attrbiutes).
																		The SMD encoder (videnc) does provide this information so in non-passthrough mode, it will be 
																		used to dynamically control the video offset.
																		Min value = 0(0ms), max value = 5,400,000(60sec). */
   ismd_buffer_handle_t                descriptors;                /**< Optional descriptors added to PMT table. Memory region must be
                                                                        accessible by the driver. If this is not used, it should be set
                                                                        to ISMD_BUFFER_HANDLE_INVALID.*/
   ismd_event_t                        event;                      /**< Optional event handle. If the event handle is valid, the driver will
                                                                        notify the application when events occur on the input stream.*/
   ismd_input_stream_event_t           event_mask;                 /**< Defines the input stream events to listen for.*/
   ismd_mux_input_stream_flags_t       flags;                      /**< Additional options for stream configuration */
}ismd_mux_input_stream_config_t;

/**
This structure is used to return statistics of the mux instance
@struct ismd_mux_statistics_t
*/
typedef struct {
   unsigned int                        buffers_received;           /**< The total number of input buffers received*/
   unsigned int                        buffers_dropped;            /**< The number of buffers that were dropped*/
   unsigned int                        access_units_processed;     /**< The number of access units that were processed*/
   bool                                end_of_stream_reached;      /**< Whether the eos tag was reached on all input streams*/
   ismd_time_t                         last_timestamp;             /**< The timestamp on the last packet that was received*/
} ismd_mux_statistics_t;

/**
Opens an available mux device.
All resources required for normal operation are allocated and the default
mux capabilities are enabled. This operation must succeed for subsequent
mux operations to be successful.

The mux instance is returned in the mux handle. Multiple mux
instances can be created by calling this function multiple times.

The mux device is destroyed using the standard Intel SMD close
function.

@param[in] stream_type: Indicates the output stream type.
@param[out] handle: Handle to the mux. Used in subsequent calls
to refer to a specific stream.

@retval ISMD_SUCCESS: mux handle is created successfully.
@retval ISMD_ERROR_INVALID_PARAMETER : The stream type is invalid.
@retval ISMD_ERROR_NO_RESOURCES: No mux instance is available.
@retval ISMD_ERROR_OPERATION_FAILED: mux creation failed due to
lack of system resources.
*/
ismd_result_t ismd_mux_open(ismd_dev_t *handle, ismd_mux_output_stream_type_t stream_type);

/**
Sets the mux stream parameters
This function must be called only when the device is in the stopped state.

@param[in] mux: Handle to the mux
@param[in] params: stream params of the mux instance

@retval ISMD_SUCCESS : stream params were successfully set.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : One of the stream params is Invalid.
@retval ISMD_ERROR_INVALID_REQUEST: The command is invalid in the current mux state.
*/
ismd_result_t ismd_mux_set_stream_params(ismd_dev_t mux,
                                         ismd_mux_stream_params_t *params);

/**
Gets the mux stream parameters

@param[in] mux: Handle to the mux
@param[out] params: stream of the mux instance

@retval ISMD_SUCCESS : stream params were successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
*/
ismd_result_t ismd_mux_get_stream_params(ismd_dev_t mux,
                                         ismd_mux_stream_params_t *params);

/**
Gets the mux statistics

@param[in] mux: Handle to the mux
@param[out] stat: stream statistics

@retval ISMD_SUCCESS : stream statistics were successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
*/
ismd_result_t ismd_mux_get_statistics(ismd_dev_t mux, ismd_mux_statistics_t *stat);

/******************************************************************************/
/*!    @name mux port interface */
/**
Adds an input port to mux.
Decompressed video frame buffers are written to the mux through this port.
This function must be called when the device state is stopped. If the input
stream type is ISMD_MUX_STREAM_TYPE_TS_PACKETS the TS payloads are inserted as is,
however the TS headers may be modified to comply with the rest of the stream. No
verification is done on the TS payloads.

@param[in] mux: Handle to the mux
@param[in] config: Configuration params of input stream
@param[inout] pid: PID of the input stream
@param[out] port : Input port handle

@retval ISMD_SUCCESS : Stream input port is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
@retval ISMD_ERROR_NO_RESOURCES : No more inputs are available.
@retval ISMD_ERROR_INVALID_PARAMETER : One of the input stream configuration is Invalid.
*/
ismd_result_t ismd_mux_add_input(ismd_dev_t mux,
                                 ismd_mux_input_stream_config_t *config,
                                 ismd_mux_pid_t *pid, ismd_port_handle_t *port);

/**
Gets the input streams configuration parameters.

@param[in] mux: Handle to the mux
@param[in] pid: PID of the input stream
@param[out] config: Configuration params of input stream

@retval ISMD_SUCCESS : Stream input port is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
*/
ismd_result_t ismd_mux_get_input_config_params(ismd_dev_t mux,
                                               ismd_mux_pid_t pid,
                                               ismd_mux_input_stream_config_t *config);

/**
Removes an input PID and it's associate input port from a mux.
This function can be called only when the device state is stopped.

@param[in] mux: Handle to the mux
@param[in] pid: PID of the input to remove

@retval ISMD_SUCCESS : Input port was successfully removed.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
*/
ismd_result_t ismd_mux_remove_input(ismd_dev_t handle, ismd_mux_pid_t pid);

/**
Gets the handle to the mux output port.

@param[in] mux: Handle to the mux.
@param[out] port : Output port handle.

@retval ISMD_SUCCESS : Stream output port is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
*/
ismd_result_t ismd_mux_get_output_port(ismd_dev_t mux,
                                       ismd_port_handle_t *port);

/*!    @name Mux Control APIs */
/**
Sets the PID of the PCRs. Can be one of the input stream PIDs or a different PID dedicated for PCR.
If this function is not called, the PCR PID will be chosen internally. This can only be called in stop state.

   @param[in] mux: Handle to the mux.
   @param[in] pid: The pid of the PCR stream.

   @retval ISMD_SUCCESS: Set PCR PID successfully.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : The input is invalid.
 */
ismd_result_t ismd_mux_set_pcr_pid(ismd_dev_t mux,
                                   ismd_mux_pid_t pid);

/**
Insert a periodic ts data into the stream. This API should typically be called when the mux is configured
to ISMD_MUX_MANUAL_PAT_PMT mode. In this mode the application is responsible for inserting PSI data,
including PAT and PMT. TS data is inserted as is. No verification is done on the input.
The periodic ts data will be removed from the mux when the mux is flushed/closed,
or by calling ismd_mux_remove_periodic_ts().
The mux can store at most 8 periodic ts buffers at any given time.

   @param[in] mux: Handle to the mux.
   @param[in] start_time: Start time of periodic ts data insertion according to the stream clock.
   In ticks where each second is 90000 ticks.  0 is a special value meaning “start now” (use a different
   small value, e.g. 1, to set insertion when the clock wraps around or starts at 0).
   @param[in] end_time: End time of periodic ts data insertion according to the stream clock.
   In ticks where each second is 90000 ticks. 0 is a special value meaning “no expiration time" (use a different
   small value, e.g. 1, to set expiration time when the clock wraps around or ends at 0).
   @param[in] interval: interval time for inserting packets in ticks where each second is 90000 ticks.
   Min value = 900(10ms), max value = 5,400,000(60sec), 0 for single insertion.
   @param[in] buffer: buffer of ts packets to insert.
   @param[out] periodic_ts_handle : Output periodic transport stream handle (should be used when removing the periodic ts).

   @retval ISMD_SUCCESS: Periodic insertion of ts buffer successfully set.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : One of the input parameters is out of valid range.
   @retval ISMD_ERROR_NO_RESOURCES : Mux already contains 8 periodic ts buffers.
 */
ismd_result_t ismd_mux_insert_periodic_ts(ismd_dev_t mux,
                                          ismd_time_t start_time,
                                          ismd_time_t end_time,
                                          ismd_time_t interval,
                                          ismd_buffer_handle_t buffer,
                                          ismd_mux_periodic_ts_id_t* periodic_ts_handle);

/**
Remove periodic ts data insertion into the stream.

   @param[in] mux: Handle to the mux.
   @param[in] periodic_ts_handle: Handle to periodic ts received from ismd_mux_insert_periodic_ts.

   @retval ISMD_SUCCESS: Removed periodic transmit of ts buffer successfully.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : The periodic ts handle is invalid.
 */
ismd_result_t ismd_mux_remove_periodic_ts(ismd_dev_t mux,
                                          ismd_mux_periodic_ts_id_t periodic_ts_handle);

/*!    @name Mux asynchronous notification APIs */
/**
Gets the event associated with the given event condition.

   @param[in] mux: Handle to the mux.
   @param[in] event_type: Requests the specific event associated with this
                     type.
   @param[out] event: Event that is signaled when the given condition occurs.

   @retval ISMD_SUCCESS: Requested event is returned successfully.
   @retval ISMD_ERROR_INVALID_HANDLE : The specified mux handle was invalid.
   @retval ISMD_ERROR_INVALID_PARAMETER : The event type is invalid.
 */
ismd_result_t ismd_mux_get_event(ismd_dev_t mux,
                                 ismd_mux_event_t event_type,
                                 ismd_event_t *event);

/**@}*/ // end of weakgroup ismd_mux
/**@}*/ // end of ingroup ismd_mux

#ifdef __cplusplus
}
#endif

#endif
