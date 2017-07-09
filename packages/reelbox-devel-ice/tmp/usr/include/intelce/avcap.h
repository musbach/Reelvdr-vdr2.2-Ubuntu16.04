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

#ifndef __AVCAP_H__
#define __AVCAP_H__

/**
 * @mainpage AVCAP
 *
 * @section section_pg Quick programmer's guide
 *
 * @par
 * This document applies to the Intel Media Processor CE3100, the Intel Atom
 * processor CE4100 and the Intel Atom Processor CE4200
 *
 * @par Introduction
 * AVCAP is a SW framework that supports different audio / video capture
 * solutions running on Intel CE Media Processors. Such solutions typically
 * consist of an input device, a capture device and a SW controlling both. AVCAP
 * provides means to connect control data flow between input and capture control
 * SW via common interface compliant with existing rendering SW.
 *
 * @par High level SW components interaction overview
 * An input control SW, a capture control SW and an output rendering SW interact
 * via common interface exposed by AVCAP. Both user and kernel space APIs are
 * available. Kernel space API is intended for use by the capture control while
 * user space API is intended for use by the input control SW and by the
 * rendering SW. At a high level the following interaction happens between
 * involved SW components:
 * - Input control SW informs capture control SW of input configuration changes.
 * - Capture control SW responds to input configurations changes and notifies
 *   rendering SW appropriately. In addition it also responds to various 
 *   requests coming from rendering SW.
 * - Rendering SW communicates with capture control SW to configure, initiate
 *   and process data capture.
 *
 * @par Interaction of the capture control SW with AVCAP core
 * - Registration using #avcap_client_register
 * - Responding to queries from AVCAP core using a set of callback routines
 *   advertised via #avcap_client_t structure
 * - Requesting input buffers using #avcap_buffer_get
 * - Notifying the rendering SW of capture related events using #avcap_event_send
 * - Unregistration using #avcap_client_unregister
 * 
 * @par Interaction of the input control SW with AVCAP core
 * - Getting an ID of capture device using #avcap_device_get_id
 * - Notifying a capture control SW of a video mode change via #avcap_video_mode_set
 * - Notifying a capture control SW of an audio mode change via #avcap_audio_mode_set
 *
 * @par Interaction of the rendering SW with AVCAP core
 * - Getting an ID of a capture device using #avcap_device_get_id
 * - Obtaining information about current input configuration using
 *   #avcap_video_mode_get, #avcap_audio_mode_get and #avcap_recv
 * - Providing input buffers for captured data using #avcap_buffer_add
 * - Initiating a capture using #avcap_start
 * - Getting capture device events using #avcap_event_recv
 * - Responding to those events
 * - Stopping a capture when necessary using #avcap_stop
 * - Removing input buffers from a capture device using #avcap_buffer_cancel_all
 *
 * @par Buffer management
 * AVCAP core implements a simple buffer management mechanism which is exposed
 * to the capture control SW via #avcap_buffer_get call of kernel AVCAP library.
 * Specifically, if capture control SW indicates lack of its own buffer
 * management [by declaring @e buffer_add of #avcap_client_t structure as NULL],
 * AVCAP core will keep track of all buffers supplied by rendering SW using
 * #avcap_buffer_add and will make them available to capture control SW. Note
 * that:
 * - AVCAP core does not alter buffers in any way once they are submitted by
 *   the rendering SW. FIFO ordering is guaranteed.
 * - Once capture control SW obtains the buffer using #avcap_buffer_get call
 *   AVCAP core no longer keeps track of this buffer.
 * - Capture control SW relying on AVCAP core buffer management may still
 *   advertise @e buffer_cancel_all entry so it can be notified by AVCAP core
 *   of buffer cancellation requests and possibly discard buffers that it has
 *   already requested from the core but has not returned back rendering SW yet.
 *
 * @par Events
 * TBA..
 *
 * @par Sample code
 * AVCAP source package comes with a sample capture solution:
 * - Input control SW
 *   @verbatim src/apps/input_ctrl.c @endverbatim
 * - Capture control SW
 *   @verbatim src/kernel/native_synthetic/ @endverbatim
 *
 * @par
 * AVCAP samples source package provides:
 * - Example of video rendering SW
 *   @verbatim src/gdl_player.c @endverbatim
 * - Example of audio / video rendering SW
 *   @verbatim src/smd_player/ @endverbatim
 *
 * @section section_ug Quick user's guide
 *
 * @par Installation
 * While target SDK installs AVCAP drivers automatically along with the rest of
 * SW stack, sometimes it may be necessary to install AVCAP drivers without full 
 * SW stack. This can be done via the following commands:
 * - export AVCAP_COMPONENTS=/
 * - /bin/avcap_install.sh
 *
 * @par Building AVCAP dependent applications
 * - Each source file using AVCAP API should include AVCAP header file:
 *   @verbatim #include "libavcap.h" @endverbatim
 * - Source files should be compiled with whe following switch:
 *   @verbatim -I$(AVCAP_INCLUDES) @endverbatim
 *   where $AVCAP_INCLUDES is the path of the directory containing containing
 *   libavcap.h and avcap.h header files.
 * - Application should be linked with avcap library using the following switches:
 *   @verbatim -L($AVCAP_LIBS) -Wl,rpath,$AVCAP_LIBS -lavcap @endverbatim
 *   where $AVCAP_LIBS is the of the directory containing libavcap.so
 *
 * @par Running AVCAP dependent application
 * - AVCAP driver must be installed as described earlier
 * - libavcap.so must be accessible at runtime
 *
 */

//------------------------------------------------------------------------------
// AVCap header files version related definitions
//------------------------------------------------------------------------------
#define AVCAP_VERSION_MAJOR 0
#define AVCAP_VERSION_MINOR 70
#define AVCAP_VERSION ((AVCAP_VERSION_MAJOR << 8) | AVCAP_VERSION_MINOR)

/**
 * List of available return codes.
 */
typedef enum
{
    /** Function has executed without errors.
     */
    AVCAP_SUCCESS = 0, 
    
    /** Generic error code reflecting the call to the function has failed.
     */
    AVCAP_ERR_FAILED = 1,
    
    /** An invalid argument was passed to the function.
     */
    AVCAP_ERR_INVAL = 2,
    
    /** One of the required arguments passed to the function was NULL or zero.
     */
    AVCAP_ERR_NULL = 3,
    
    /** Function is not implemented.
     */
    AVCAP_ERR_NOT_IMPL = 4,
    
    /** A condition that should not be possible was detected within the driver.
        This generally means there is nothing the application can do to correct
        the problem.
     */
    AVCAP_ERR_INTERNAL = 5,
    
    /** Function could not allocate memory.
     */
    AVCAP_ERR_NO_MEMORY = 6,
    
    /** Function is not supported by given device.
     */
    AVCAP_ERR_NO_SUPPORT = 7,
    
    /** An attempt to do an operation that can not be done with pending events
        was detected. The application should process pending events and retry 
        the call.
     */
    AVCAP_ERR_EVENTS_PENDING = 8,
    
    /** Version mismatch between AVCAP SW components has been detected. This
        generally means one of the following:
        - An application was linked to the library that differs from the library
          present on the target system.
        - Version of AVCAP driver is not compatible with version of AVCAP
          library present on the target system.
     */
    AVCAP_ERR_VERSION = 9,

    /** An event timeout was detected. The application should retry
     *  the call.
     */
    AVCAP_ERR_EVENT_TIMEOUT = 10,
    
    /** Requested operation can not be completed due to no mode being set
     */
    AVCAP_ERR_MODE_NOT_SET = 11,
    
    /** Requested operation has been attempted at the wrong time
     */
    AVCAP_ERR_STATE = 12,
    
    /** Requested operation is not allowed due to incufficient privileges of the
     *  caller
     */
    AVCAP_ERR_PERM = 13,
    
} avcap_ret_t;

/**
 * Bolean data type.
 */
typedef enum
{
    AVCAP_FALSE = 0, ///< FALSE
    AVCAP_TRUE  = 1, ///< TRUE
} avcap_bool_t;

/**
 * Buffer type identifiers.
 */
typedef enum
{
    AVCAP_BUFFER_TYPE_VIDEO, ///< Video buffer
    AVCAP_BUFFER_TYPE_AUDIO, ///< Audio buffer
    AVCAP_BUFFER_TYPE_VBI,   ///< VBI buffer
} avcap_buffer_type_t;

/**
 * Defines supported view IDs
 */
typedef enum
{
    AVCAP_VIEW_UNDEFINED, ///< Identifies cases where view ID is not applicable
    AVCAP_VIEW_LEFT,      ///< Identifies left view in #AVCAP_STEREO_FRAME_SEQUENTIAL mode
    AVCAP_VIEW_RIGHT,     ///< Identifies right view in #AVCAP_STEREO_FRAME_SEQUENTIAL mode
} avcap_view_t;

/**
 * Buffer information structure.
 */
typedef struct
{
    unsigned int misc;     ///< User data
    unsigned int addr;     ///< Buffer physical address
    unsigned int size;     ///< Buffer size
    avcap_bool_t valid;    ///< When not set data in the buffer should be considered corrupted
    unsigned long long ts; ///< Timestamp
    unsigned long long wall_clock_ts; ///< Wall Clock Timestamp

    union
    {
        struct
        {
            unsigned int pitch;  ///< Pitch
            unsigned int rate;   ///< 90 KHz domain per frame ticks increment
            avcap_view_t view;   ///< View ID id
            unsigned int vtotal; ///< Vtotal of the input frame
            unsigned int active_offset;///< Byte offset of active pixel data.  
                                       ///< Data before this is vblank data
            avcap_bool_t draw_vblank;  ///< Should we draw vblank data (for debug)
            avcap_bool_t hds;    ///< Indicates the horizontal downscaler status
            avcap_bool_t field_0_first;///< Is the first captured line from field 0?
            
        } _video; ///< Video specific data
        
        struct
        {
            unsigned int level; ///< Amount of data captured into the buffer
            
        } _audio; ///< Audio specific data
        
        struct
        {
            unsigned int level; ///< Amount of data captured into the buffer

        } _vbi; ///< VBI buffer data

    } data; ///< Type specific data
    
} avcap_buffer_info_t;

/**
 * List of pixel format identifiers
 */
typedef enum
{
    AVCAP_PF_RGB_444_24,          ///< input: 24-bit RGB 444; output: 32-bit ARGB 4:4:4:4 packed
    AVCAP_PF_RGB_444_30,          ///< input: 30-bit RGB 444; output: 30-bit RGB 4:4:4 packed
    AVCAP_PF_RGB_444_36,          ///< input: 24-bit RGB 444; output: 36-bit RGB 4:4:4 packed
    AVCAP_PF_YUV_444_24,          ///< input: 24-bit YUV 444; output: 32-bit AYUV 4:4:4:4 packed
    AVCAP_PF_YUV_444_30,          ///< input: 30-bit YUV 444; output: 30-bit YUV 4:4:4 packed
    AVCAP_PF_YUV_444_36,          ///< input: 24-bit YUV 444; output: 36-bit YUV 4:4:4 packed
    AVCAP_PF_YUV_422_16,          ///< input: 16-bit YUV 422; output: 16-bit YUV 4:2:2 pseudo-planar
    AVCAP_PF_YUV_422_20,          ///< input: 20-bit YUV 422; output: 20-bit YUV 4:2:2 pseudo-planar
    AVCAP_PF_YUV_422_24,          ///< input: 24-bit YUV 422; output: 24-bit YUV 4:2:2 pseudo-planar
    AVCAP_PF_RGB_444_24_NO_ALPHA, ///< input: n/a;            output: 24-bit RGB 4:4:4 packed
} avcap_pixel_format_t;

/**
 * This enumeration represents availalbe picture aspect ratio settings as recieved
 * from HDMI source.
 */
typedef enum
{
    AVCAP_PAR_NO_DATA = 0x00, ///< No aspect ratio specified
    AVCAP_PAR_4_3     = 0x01, ///< 4:3 aspect ratio
    AVCAP_PAR_16_9    = 0x02, ///< 16:9 aspect ratio
} avcap_par_t;

/**
 * This enumeration represents available format aspect ratio settings as recieved
 * from HDMI source.
 */
typedef enum
{
    AVCAP_FAR_16_9_TOP      = 0x02, ///< box 16:9 (top)
    AVCAP_FAR_14_9_TOP      = 0x03, ///< box 14:9 (top)
    AVCAP_FAR_G_14_9_CENTER = 0x04, ///< box > 16:9 (center)
    AVCAP_FAR_SAME_AS_PAR   = 0x08, ///< As encoded frame
    AVCAP_FAR_4_3_CENTER    = 0x09, ///< 4:3 center
    AVCAP_FAR_16_9_CENTER   = 0x0A, ///< 16:9 center
    AVCAP_FAR_14_9_CENTER   = 0x0B, ///< 14:9 center
    AVCAP_FAR_4_3_SP_14_9   = 0x0D, ///< 4:3 with s&p 14:9 center
    AVCAP_FAR_16_9_SP_14_9  = 0x0E, ///< 16:9 with s&p 14:9 center
    AVCAP_FAR_16_9_SP_4_3   = 0x0F, ///< 4:3 with s&p 4:3 center
} avcap_far_t;

/**
 * Defines supported color spaces
 */
typedef enum
{
    AVCAP_COLOR_SPACE_BT601,        ///< Used for standard definition YCbCr content
    AVCAP_COLOR_SPACE_BT709,        ///< Used for high definition YCbCr content
    AVCAP_COLOR_SPACE_RGB,          ///< Used for all RGB pixel formats
    AVCAP_COLOR_SPACE_XVYCC601,     ///< Used for standard definition YCbCr content
    AVCAP_COLOR_SPACE_XVYCC709,     ///< Used for high definition YCbCr content
    AVCAP_COLOR_SPACE_SYCC601,      ///< UNUSED
    AVCAP_COLOR_SPACE_ADOBE_YCC601, ///< UNUSED
    AVCAP_COLOR_SPACE_ADOBE_RGB,    ///< UNUSED
} avcap_color_space_t;

/** 
 * List of supported interface bus standards
 */
typedef enum
{
    AVCAP_BUS_CEA861 = 0, ///< HDMI - External sync mode 
    AVCAP_BUS_BT656,      ///< Composite - Embedded sync SD mode 
    AVCAP_BUS_BT1120,     ///< Component - Embedded sync HD mode 
    AVCAP_BUS_COUNT,      ///< INTERNAL USE ONLY!!!
} avcap_bus_standard_t;

/** 
 * List of services we can decode from the VBI
 */
typedef enum
{
    AVCAP_VBI_DECODE_TELETEXT_B = 0,       ///< TeleText B (PAL)
    AVCAP_VBI_DECODE_CLOSED_CAPTIONS_NTSC, ///< Closed Captioning (NTSC)
} avcap_vbi_decode_t; 

/** 
 * VBI decode control command
 */
typedef struct
{
    avcap_bool_t       enable; ///< Enable or Disable decoding of "type"
    avcap_vbi_decode_t type;   ///< Service to decode from the vblank region
} avcap_vbi_decode_ctrl_t;

/**
 * List of supported capture sources
 */
typedef enum
{
    AVCAP_DATA_SOURCE_EXT = 'D'*(1<<24)+'S'*(1<<16)+'M'*(1<<8)+'N', ///< External data source
    AVCAP_DATA_SOURCE_INT,                                          ///< Internal HDMI Rx data source
} avcap_data_source_t;

/**
 * Stereo ext data types.
 */
typedef enum
{
    AVCAP_STEREO_EXT_DATA_HORIZONTAL_ODD_ODD,
    AVCAP_STEREO_EXT_DATA_HORIZONTAL_ODD_EVEN,
    AVCAP_STEREO_EXT_DATA_HORIZONTAL_EVEN_ODD,
    AVCAP_STEREO_EXT_DATA_HORIZONTAL_EVEN_EVEN,
    AVCAP_STEREO_EXT_DATA_QUINCUNX_ODD_ODD,
    AVCAP_STEREO_EXT_DATA_QUINCUNX_ODD_EVEN,
    AVCAP_STEREO_EXT_DATA_QUINCUNX_EVEN_ODD,
    AVCAP_STEREO_EXT_DATA_QUINCUNX_EVEN_EVEN,
} avcap_stereo_ext_data_t;

/**
 * Quantization range
 */
typedef enum
{
    AVCAP_QUANTIZATION_UNKNOWN, ///< Range information not decoded
    AVCAP_QUANTIZATION_FULL,    ///< Full range
    AVCAP_QUANTIZATION_LIMITED, ///< Limited range
} avcap_quantization_t;

/**
 * Arbitrary frame information
 */
typedef struct
{
    avcap_par_t             par;                ///< Picture aspect ration
    avcap_far_t             far;                ///< Format aspect ratio
    avcap_color_space_t     cs_in;              ///< Input colorspace
    avcap_pixel_format_t    pix_fmt_in;         ///< Input pixel format
    unsigned int            pix_ar_numerator;   ///< Pixel aspect ratio numerator
    unsigned int            pix_ar_denominator; ///< Pixel aspect ratio denominator
    unsigned int            vact_space_1;       ///< Active space 1 [if applicable]
    unsigned int            vact_space_2;       ///< Active space 2 [if applicable]
    avcap_stereo_ext_data_t stereo_ext_data;    ///< 3D ext data for SBSH format
    unsigned int            capture_height;     ///< Num of captured lines potentially including vblank area
    avcap_quantization_t    quantization;       ///< Quantization range
    unsigned int            extra_lines;        ///< Maximum extra lines to accomodate non-compliant video
    unsigned int            extra_pixels;       ///< Maximum extra pixels to accomodate non-compliant video
} avcap_frame_info_t;

/**
 * Generic video recognition configuration structure. Can be used with multiple
 * commands.
 * 
 * When used with #AVCAP_SEND_VIDEO_TOLERANCE / #AVCAP_RECV_VIDEO_TOLERANCE
 * command each of the fields represent maximum deviation from ideal reference
 * value. Maximum / default values for h_total, h_active, v_total and v_active
 * respectfully are: 30 / 30, 5 / 5, 153 / 15, and 35 / 3.
 *
 * When used with #AVCAP_SEND_VIDEO_REFERENCE / #AVCAP_RECV_VIDEO_REFERENCE
 * command each of the fields represent actual reference values to which
 * tolerance rules can apply.
 *
 * USE WITH CARE AS THIS SETTINGS HAVE DIRECT IMPACT ON MODE RECONITION ABILITY
 * 
 */
typedef struct
{
    unsigned int h_total;  ///< Total number of pixels
    unsigned int h_active; ///< Active number of pixels
    unsigned int v_total;  ///< Total number of lines
    unsigned int v_active; ///< Active number of lines
} avcap_video_options_t;

/**
 * Additional video mode information
 *
 * The mode information follows the CEA-861 standard where vertical total and 
 * active values are per frame while the vertical blanking values are per field. 
 */
typedef struct
{
    unsigned int h_total;       ///< Total number of pixels
    unsigned int h_active;      ///< Active number of pixels
    unsigned int h_front_porch; ///< Front porch in pixels
    unsigned int h_sync_width;  ///< Sync width in pixels
    unsigned int h_back_porch;  ///< Back porch in pixels
    avcap_bool_t h_sync;        ///< Horizontal sync polarity;
                                ///< #AVCAP_TRUE for positive, #AVCAP_FALSE for negative
    unsigned int v_total;       ///< Total number of lines
    unsigned int v_active;      ///< Active number of lines
    unsigned int v_front_porch; ///< Front porch in pixels
    unsigned int v_sync_width;  ///< Sync width in pixels
    unsigned int v_back_porch;  ///< Back porch in pixels
    avcap_bool_t v_sync;        ///< Vertical sync polarity;
                                ///< #AVCAP_TRUE for positive, #AVCAP_FALSE for negative
    unsigned int clock;         ///< Pixel Clock
    unsigned int repetition;    ///< Horizontal pixel repetition factor
} avcap_video_info_t;

/**
 * Stereo type information
 */
typedef enum
{
    AVCAP_STEREO_NONE = 0xabcdef01, ///< Mono
    AVCAP_STEREO_FRAME_PACKING,     ///< Frame packing
    AVCAP_STEREO_SIDE_BY_SIDE_HALF, ///< Side by side half horizontal resolution
    AVCAP_STEREO_TOP_BOTTOM_HALF,   ///< Top bottom half vertical resolution
    AVCAP_STEREO_FRAME_SEQUENTIAL,  ///< Frame sequential
} avcap_stereo_t;

/**
 * Video mode information structure.
 */
typedef struct
{
    unsigned int         width;         ///< Horizontal resolution
    unsigned int         height;        ///< Vertical resolution
    unsigned int         refresh;       ///< Refresh rate
    avcap_bool_t         progressive;   ///< Scan type
    avcap_bool_t         valid;         ///< Video signal presence indicator
    avcap_frame_info_t   frame_info;    ///< Arbitrary info about frames to come
    avcap_bool_t         adjusted;      ///< Indication of a change not requiring capture stop
    avcap_stereo_t       stereo;        ///< Stereo type
    avcap_data_source_t  data_source;   ///< Capture data source
    avcap_video_info_t   video_info;    ///< Arbitrary info about video mode
} avcap_video_mode_t;

/**
 * List of audio format identifiers.
 */
typedef enum
{
    AVCAP_AUDIO_FORMAT_PCM,        ///< Linear PCM
    AVCAP_AUDIO_FORMAT_COMPRESSED, ///< Compressed
} avcap_audio_format_t;

/**
 * Audio mode information structure
 */
typedef struct
{
    avcap_audio_format_t format;      ///< Format
    unsigned int         num_ch;      ///< Number of channels
    unsigned int         fs;          ///< Sampling frequency, in herz
    unsigned int         ss;          ///< Sample size, in bits
    avcap_bool_t         valid;       ///< Audio signal presence indicator
    avcap_data_source_t  data_source; ///< Capture data source
} avcap_audio_mode_t;

/**
 * List of possible input mute reasons
 */
typedef enum
{
    AVCAP_MUTE_TX_NO_HDCP = 0x01, ///< HDCP is not established on TX side
    AVCAP_MUTE_TX_NO_DEVS = 0x02, ///< No HDMI devices connected to on TX side
    AVCAP_MUTE_ANALOG_HD  = 0x04, ///< Analog interface is set for HD output
    AVCAP_MUTE_RX_AVMUTE  = 0x08, ///< Set AVMUTE in GCP was received from upstream
} avcap_mute_t;

/**
 * This structure is used with #AVCAP_SEND_MUTE request
 */
typedef struct
{
    avcap_bool_t mute;  ///< Status of AV mute
    avcap_mute_t flags; ///< Explanation of muting
} avcap_mute_info_t;

/**
 * This structure is used with #AVCAP_SEND_HDS_OPTIONS request
 * For each of the three coefficients, the following must be true: 
 *   2*c[0] + 2*c[1] + c[2] = 512 
 * NOTE: The coefficients are 10-bit two's complement.
 */
typedef struct
{
    avcap_bool_t clamp;       ///< Horizontal scaler clamp enable
    avcap_bool_t use_default; ///< Use default coefficients
    unsigned int y_g[3];      ///< Y/G  10-bit 2's complement scaler coefficients
    unsigned int cb_b[3];     ///< Cb/B 10-bit 2's complement scaler coefficients
    unsigned int cr_r[3];     ///< Cr/R 10-bit 2's complement Scaler coefficients
} avcap_hds_options_t;

/**
 * Supported notification policies
 */
typedef enum
{
    AVCAP_NOTIFICATION_OFF = 0, ///< Notification disabled
    AVCAP_NOTIFICATION_NEW,     ///< Notification enabled only for updates
    AVCAP_NOTIFICATION_ALL,     ///< Notification enabled for any events
    AVCAP_NOTIFICATION_MAX,     ///< INTERNAL USE ONLY!!!
} avcap_notification_t;

/**
 * Infopacket payload size
 */
#define AVCAP_PACKET_PAYLOAD_SIZE 28

/**
 * Packet notification control structure
 */
typedef struct
{
    /** Packet type
     */
    unsigned int         type;

    /** Packet subtype, applicable only with Vendor specific infoframes, ignored
        with the rest
     */
    unsigned int         subtype;

    /** Approximate notification rate, in frames
     */
    unsigned int         rate;

    /** Notification policy
     */
    avcap_notification_t policy;

    /** Approximate time before declaring packet loss, in frames. Maximum allowed
        timeout for vendor specific infoframes and audio infoframes is 20 frames.
        Other infopackets can be set up to 1000 frames. Note that this setting
        directly affects response of input driver to the loss of a packet.
     */
    unsigned int         timeout;

    /** Filter out changes outside of given mask, applicable only when policy
        is set to AVCAP_NOTIFICATION_NEW, ignored with the rest
     */
    avcap_bool_t         filter;

    /**  Payload change notification filtering mask, applicable only when filter
         is enabled
     */
    unsigned char        mask[AVCAP_PACKET_PAYLOAD_SIZE];

} avcap_packet_options_t;

/**
 * List of event identifiers
 */
typedef enum
{
    AVCAP_EVENT_BUFFER_DONE,       ///< Data has been captured into the buffer
    AVCAP_EVENT_VIDEO_MODE_CHANGE, ///< Video mode has changed 
    AVCAP_EVENT_AUDIO_MODE_CHANGE, ///< Audio mode has changed
    AVCAP_EVENT_MUTE,              ///< AV mute status has changed
    AVCAP_EVENT_HDCP,              ///< Input encryption status has changed
    AVCAP_EVENT_PACKET,            ///< New HDMI packet has been received
    AVCAP_EVENT_MESSAGE,           ///< Generic information message received
    AVCAP_EVENT_MISC,              ///< INTERNAL USE ONLY!!!
    AVCAP_EVENT_EDID_CACHE,        ///< Upstream EDID changed
    AVCAP_EVENT_TELETEXT_B,        ///< Teletext packets decoded from VBI
    AVCAP_EVENT_CLOSED_CAPTION,    ///< Closed captioning decoded from VBI
} avcap_event_id_t;

/**
 * List of supported data channels
 */
typedef enum
{
    AVCAP_SIGNAL_R,
    AVCAP_SIGNAL_G,
    AVCAP_SIGNAL_B,
    AVCAP_SIGNAL_Y,
    AVCAP_SIGNAL_C,
    AVCAP_SIGNAL_Cb,
    AVCAP_SIGNAL_Cr,
    AVCAP_SIGNAL_BT656,
    AVCAP_SIGNAL_NONE,
} avcap_signal_t;

/**
 * Structure representing assignment of signals to physical pads and used with
 * #AVCAP_SEND_PAD_CONTROL and #AVCAP_RECV_PAD_CONTROL requests.
 */
typedef struct
{
    avcap_signal_t pad_a;
    avcap_signal_t pad_b;
    avcap_signal_t pad_c;
} avcap_pad_control_t;

/**
 * Structure representing the AVCAP CSC filter coefficients.
 * YUV422->YUV444 up conversion used with #AVCAP_SEND_444_FILTER
 * and 2*(c0+c1+c2)= 1.0 must be true for accurate result. 
 * YUV444->YUV422 down conversion used with #AVCAP_SEND_422_FILTER.
 * and 2*(c0+c1+c2) + c3 = 1.0 must be true for accurate result. 
 */
typedef struct
{
    avcap_bool_t use_defaults;   ///< AVCAP_TRUE => use defaults,
                                 ///< AVCAP_FALSE => use coefficients
    unsigned int c0, c1, c2, c3; ///< Coefficients are in 1.9 fixed point
                                 ///< format. 
} avcap_filter_t;

/**
 * Structure representing HDMI packet submitted by input control SW via
 * #AVCAP_SEND_PACKET command and received by rendering application as
 * #AVCAP_EVENT_PACKET event.
 */
typedef struct
{
    unsigned char header[3];                          ///< Header
    unsigned char payload[AVCAP_PACKET_PAYLOAD_SIZE]; ///< Payload
    unsigned int  type;    ///< Packet type
    unsigned int  subtype; ///< Packet subtype, if applicable
    avcap_bool_t  valid;   ///< Packet presence / loss indicator
} avcap_packet_t;

/**
 * List of EDID audio formats mask values.
 */
typedef enum
{
    AVCAP_EDID_AUDIO_NONE          = 0x00000,
    AVCAP_EDID_AUDIO_PCM           = 0x00001,
    AVCAP_EDID_AUDIO_AC3           = 0x00002,
    AVCAP_EDID_AUDIO_MPEG_1        = 0x00004,
    AVCAP_EDID_AUDIO_MP3           = 0x00008,
    AVCAP_EDID_AUDIO_MPEG_2        = 0x00010,
    AVCAP_EDID_AUDIO_AAC           = 0x00020,
    AVCAP_EDID_AUDIO_DTS           = 0x00040,
    AVCAP_EDID_AUDIO_ATRAC         = 0x00080,
    AVCAP_EDID_AUDIO_DSD           = 0x00100,
    AVCAP_EDID_AUDIO_E_AC3         = 0x00200,
    AVCAP_EDID_AUDIO_DTS_HD        = 0x00400,
    AVCAP_EDID_AUDIO_MLP           = 0x00800,
    AVCAP_EDID_AUDIO_DST           = 0x01000,
    AVCAP_EDID_AUDIO_WMA_PRO       = 0x02000,
    AVCAP_EDID_AUDIO_HE_AAC        = 0x04000,
    AVCAP_EDID_AUDIO_HE_AAC2       = 0x08000,
    AVCAP_EDID_AUDIO_MPEG_SURROUND = 0x10000,
    AVCAP_EDID_AUDIO_ALL           = 0xFFFFFFFF,
} avcap_edid_audio_mask_t;

/**
 * List of options about how to handle 3D support
 */
typedef enum
{
   AVCAP_EDID_3D_DISABLE = 0,  ///< Disable EDID 3D support
   AVCAP_EDID_3D_ENABLE,       ///< Add 3D support if the downstream supports 3D
   AVCAP_EDID_3D_FORCE_ENABLE, ///< Always add EDID 3D support regardless 
                               ///< of downstream support
} avcap_edid_3D_t;

/**
 * Structure repesenting latency values and used by
 * #AVCAP_SEND_EDID_CMD and #AVCAP_RECV_EDID_CMD with id
 * #AVCAP_EDID_CMD_LATENCY 
 * The unit for latency values is millisecond. Expected value
 * range is from 0 to 500 millisecond. Any value bigger than
 * 500 indicates no video or audio is supported
 * Progressive values and interlaced values must be set separately
 **/
typedef struct
{
    unsigned int p_video_latency;// progressive video latency
    unsigned int p_audio_latency;// progressive audio latency
    unsigned int i_video_latency;// interlaced video latency
    unsigned int i_audio_latency;// interlaced audio latency
} avcap_edid_latency_t;

/**
 * List of EDID command IDs part of #avcap_edid_cmd_t
 */
typedef enum
{
    AVCAP_EDID_CMD_AUDIO_FILTER_UPSTREAM,   ///< Upstream audio formats filter
    AVCAP_EDID_CMD_AUDIO_FILTER_DOWNSTREAM, ///< DS audio format merge/filter
    AVCAP_EDID_CMD_CACHE,                   ///< Copy of the upstream EDID
    AVCAP_EDID_CMD_3D,                      ///< 3D support handling
    AVCAP_EDID_CMD_LATENCY,                 ///< Latency values
} avcap_edid_cmd_id_t;

/**
 * Structure for setting the EDID commands as used by #AVCAP_SEND_EDID_CMD and 
 * #AVCAP_RECV_EDID_CMD. 
 */
typedef struct
{
    avcap_edid_cmd_id_t id; ///< EDID Command ID

    union
    {
        struct
        {
            avcap_edid_audio_mask_t filter; ///< This value contains all of the
                                            ///< desired audio formats OR'd 
                                            ///< together. Any format flag not
                                            ///< listed is not added in the
                                            ///< upstream EDID.
        } _audio_filter_upstream; ///< Used by #AVCAP_EDID_CMD_AUDIO_FILTER_UPSTREAM

        struct
        {
            avcap_bool_t            filter; ///< True or false value that 
                                            ///< indicates to filter out all 
                                            ///< audio formats not supported 
                                            ///< by the downstream device.
        } _audio_filter_downstream; ///< Used by #AVCAP_EDID_CMD_AUDIO_FILTER_DOWNSTREAM

        struct
        {
            char edid[256];   ///< Array to receive a copy of the upstream EDID
        }_cache; ///< Used by #AVCAP_EDID_CMD_CACHE

        struct
        {
            avcap_edid_3D_t option; ///< Specify EDID 3D support 
        }_3D; ///< Used by #AVCAP_EDID_CMD_3D

        struct
        {
            avcap_edid_latency_t latency;///< structure for video and audio latency values
        } _latency;///< Used by #AVCAP_EDID_CMD_LATENCY
    };
} avcap_edid_cmd_t; 

/**
 * List of messages delivered via #AVCAP_EVENT_MESSAGE
 */
typedef enum
{
    AVCAP_MESSAGE_FRAME_DROP,
    AVCAP_MESSAGE_BUFFER_OVERFLOW,
} avcap_message_t;

/**
 * Defines associated with analog capture payload
 */
#define AVCAP_CC_SIZE_BYTES 2
#define AVCAP_TT_B_SIZE_BYTES 42
#define AVCAP_TT_MAX_LINES 4

/**
 * Event information structure.
 */
typedef struct
{
    avcap_event_id_t id; ///< Event type
    
    union
    {
        struct
        {
            avcap_buffer_type_t type;  ///< Buffer type
            avcap_buffer_info_t info;  ///< Buffer descriptor
            
        } _buffer_done; ///< Data specific to #AVCAP_EVENT_BUFFER_DONE
        
        struct
        {
            avcap_video_mode_t   mode;        ///< Mode info
            avcap_bool_t         restart;     ///< Restart hint
            avcap_pixel_format_t pix_fmt_out; ///< Output pixel format
            avcap_color_space_t  cs_out;      ///< Output color space
            
        } _video_mode_change; ///< Data specific to #AVCAP_EVENT_VIDEO_MODE_CHANGE
        
        struct
        {
            avcap_audio_mode_t mode;    ///< Mode info
            avcap_bool_t       restart; ///< Restart hint
            
        } _audio_mode_change; ///< Data specific to #AVCAP_EVENT_AUDIO_MODE_CHANGE
        
        struct
        {
            avcap_mute_info_t info; ///< Mute description
            
        } _mute; ///< Data specific to #AVCAP_EVENT_MUTE
        
        struct
        {
            avcap_bool_t status; ///< HDCP status
            
        } _hdcp; ///< Data specific to #AVCAP_EVENT_HDCP
        
        struct
        {
            avcap_packet_t packet; ///< Packet contents
            
        } _packet; ///< Data specific to #AVCAP_EVENT_PACKET
        
        struct
        {
            avcap_message_t code; ///< Message code
            
        } _message; ///< Data specific to #AVCAP_EVENT_MESSAGE
        
        struct
        {
            unsigned char stuff[512]; ///< INTERNAL USE ONLY!!!
            
        } _misc; ///< Data specific to #AVCAP_EVENT_MISC
               
        struct
        {
            /** 0 or 1 */
            unsigned char field;

            /** MSB formatted raw decoded closed caption data */
            unsigned char cc_data[AVCAP_CC_SIZE_BYTES]; 

        } _closed_caption; ///< Data specific to #AVCAP_EVENT_CLOSED_CAPTION

        struct
        {
            /** Number of lines of teletext sent
             */
            unsigned char num_lines;
            
            /** Indication of last event for a given frame
             */
            avcap_bool_t  end_of_frame;
            
            /** Line number for each entry of data[]
             */
            unsigned int  line_num[AVCAP_TT_MAX_LINES];
            
            /** Raw decoded teletext B data. Bit ordering is configurable 
             *  in the decoder module. Default ordering is LSB
             */
            unsigned char tt_data[AVCAP_TT_MAX_LINES][AVCAP_TT_B_SIZE_BYTES];
            
        } _teletext_b; ///< Data specific to #AVCAP_EVENT_TELETEXT_B
        
    } data; ///< Event data payload
    
} avcap_event_t;

//------------------------------------------------------------------------------
// Value that seperates the recieve identifiers from the send identifiers
//------------------------------------------------------------------------------
#define AVCAP_RECV_FIRST_ID 0x100

/**
 * List of identifiers specifying data sent by user to the AVCAP device
 */
typedef enum
{
    AVCAP_SEND_I2C,             ///< I2C write request
    AVCAP_SEND_PIX_FMT_OUT,     ///< Output pixel format change
    AVCAP_SEND_INPUT_PORT,      ///< Input port selection
    AVCAP_SEND_SMD_CLOCK,       ///< SMD clock handle
    AVCAP_SEND_PAD_CONTROL,     ///< Pads signal assignment configuration
    AVCAP_SEND_MUTE,            ///< Input mute notification
    AVCAP_SEND_HDCP,            ///< HDCP status change notification
    AVCAP_SEND_PACKET,          ///< New HDMI packet notification
    AVCAP_SEND_MISC,            ///< INTERNAL USE!!!
    AVCAP_SEND_422_FILTER,      ///< 444->422 filter coefficient change
    AVCAP_SEND_REPEATER_BYPASS, ///< Indicator of repeater bypass
    AVCAP_SEND_DITHER,          ///< Dithering or rounding
    AVCAP_SEND_BUS_STANDARD,    ///< Bus standard for analog capture
    AVCAP_SEND_DRAW_VBLANK,     ///< Draw vblank data (debug purposes)
    AVCAP_SEND_EDID_AUDIO_MASK, ///< Enable/disable EDID audio capabilities < DEPRECATED >
    AVCAP_SEND_EDID_CMD,        ///< EDID generic commands
    AVCAP_SEND_EDID_CACHE,      ///< Cache of the upstream EDID - < DEPRECATED >
    AVCAP_SEND_VBI_DECODE_CTRL, ///< Add/Remove services to try and decode from the VBI
    AVCAP_SEND_DATA_SOURCE,     ///< Data source selection
    AVCAP_SEND_CALLBACK,        ///< Kernel space callback registration
    AVCAP_SEND_HDS,             ///< Horizontal 2-to-1 downsampler enable
    AVCAP_SEND_HDS_OPTIONS,     ///< Horizontal 2-to-1 downsampler options
    AVCAP_SEND_CUSTOM_VIDEO,    ///< Limited unrecognized video mode support
    AVCAP_SEND_PACKET_OPTIONS,  ///< Packet notification configuration
    AVCAP_SEND_444_FILTER,      ///< 422->444 filter coefficient change
    AVCAP_SEND_CSC_OPTIONS,     ///< CSC options setting
    AVCAP_SEND_TS_SOURCE,       ///< Switching between timestamp counter sources
    AVCAP_SEND_ALPHA,           ///< Set 0..255 range alpha value for the #AVCAP_PF_RGB_444_24 output format
    AVCAP_SEND_VIDEO_REFERENCE, ///< Video mode recognition reference geometry 
    AVCAP_SEND_VIDEO_TOLERANCE, ///< Deviation of geometry from reference point
    
} avcap_send_t;

/**
 * List of identifiers specifying data requested by user from the AVCAP device
 */
typedef enum
{
    AVCAP_RECV_I2C = AVCAP_RECV_FIRST_ID, ///< I2C read request
    AVCAP_RECV_PIX_FMT_OUT,     ///< Output pixel format query
    AVCAP_RECV_INPUT_PORT,      ///< Input port query
    AVCAP_RECV_PAD_CONTROL,     ///< Pads signal assigment query
    AVCAP_RECV_CS_OUT,          ///< Output color space query
    AVCAP_RECV_MISC,            ///< INTERNAL USE!!!
    AVCAP_RECV_REPEATER_BYPASS, ///< Indicator of repeater bypass
    AVCAP_RECV_DITHER,          ///< Dithering or rounding
    AVCAP_RECV_EDID_AUDIO_MASK, ///< EDID audio capabilities query < DEPRECATED >
    AVCAP_RECV_EDID_CMD,        ///< EDID generic commands query
    AVCAP_RECV_EDID_CACHE,      ///< Cache of the upstream EDID < DEPRECATED >
    AVCAP_RECV_DATA_SOURCE,     ///< Active data source query
    AVCAP_RECV_RT_TS,           ///< Real time 64 bit timestamp query in unit's domain
    AVCAP_RECV_HDS,             ///< Horizontal 2-to-1 downsampler enable
    AVCAP_RECV_HDS_OPTIONS,     ///< Horizontal 2-to-1 downsampler options
    AVCAP_RECV_CUSTOM_VIDEO,    ///< Limited unrecognized video mode support
    AVCAP_RECV_PACKET_OPTIONS,  ///< Packet notification configuration query
    AVCAP_RECV_PACKET,          ///< Query last received packet of given type
    AVCAP_RECV_CSC_OPTIONS,     ///< CSC options query 
    AVCAP_RECV_ALPHA,           ///< Query the alpha value for the output format #AVCAP_PF_RGB_444_24
    AVCAP_RECV_VIDEO_REFERENCE, ///< Video mode recognition reference geometry query
    AVCAP_RECV_VIDEO_TOLERANCE, ///< Deviation of geometry from reference point query
} avcap_recv_t;

/**
 * Maximum #avcap_send / #avcap_recv data size
 */
#define AVCAP_MAX_USER_DATA_SIZE 512

/**
 * List of I2C bus identifiers. See #AVCAP_SEND_I2C and #AVCAP_RECV_I2C.
 */
typedef enum
{
    AVCAP_I2C_0 = 0,     ///< I2C Bus 0
    AVCAP_I2C_1 = 1,     ///< I2C Bus 1
    AVCAP_I2C_2 = 2,     ///< I2C Bus 2
    AVCAP_I2C_3 = 3,     ///< I2C Bus 3
} avcap_i2c_bus_id_t;

/**
 * This structure represents I2C request. Specifically:
 * - I2C write request, when used with #avcap_send
 * - I2C read request, when used with #avcap_recv
 */
typedef struct
{
    avcap_i2c_bus_id_t bus;       ///< Bus ID
    unsigned char      device;    ///< Device number
    unsigned char      offset;    ///< Data location
    unsigned int       length;    ///< Data size
    unsigned char      data[256]; ///< Data buffer [input for write, output for read].
    avcap_bool_t       fast;      ///< Access mode
} avcap_i2c_access_t;

/**
 * List of the applicable clamp options
 */
typedef enum
{
    AVCAP_CSC_CLAMP_NONE = 0,  // No clamp applied   
    AVCAP_CSC_CLAMP_16_235,    // [16, 235] for all three components 
    AVCAP_CSC_CLAMP_16_240,    // [16, 235] for Y/G, [16, 240] for Cb/B, Cr/R
} avcap_csc_clamp_t;

/**
 * List of the input port intended for use with #AVCAP_SEND_INPUT_PORT command.
 * The sequence for entries matters. Only add new entries to the end of the enum
 */
typedef enum
{
    AVCAP_INPUT_HDMI_0 = 0, //HDMI port 0
    AVCAP_INPUT_HDMI_1,     //HDMI port 1
    AVCAP_INPUT_HDMI_2,     //HDMI port 2
    AVCAP_INPUT_HDMI_3,     //HDMI port 3
    AVCAP_INPUT_VGA_0,      //Graphics port 0
    AVCAP_INPUT_COMP_0,     //Component port 0 
    AVCAP_INPUT_COMP_1,     //Component port 1
    AVCAP_INPUT_CVBS_TUNER, //Tuner port
    AVCAP_INPUT_CVBS_0,     //CVBS port 0
    AVCAP_INPUT_CVBS_1,     //CVBS port 1
    AVCAP_INPUT_SCART_0,    //SCART port 0
    AVCAP_INPUT_SCART_1,    //SCART port 1
    AVCAP_INPUT_MAX,
} avcap_input_t;

/**
 * This structure contains the parameters used for CSC equations. It can
 * be used with #AVCAP_SEND_CSC_OPTIONS and #AVCAP_RECV_CSC_OPTIONS.
 *
 * The three components of a color from an input color space (CrR, YG, and CbB)
 * can be converted to the three components of an output color space (CrR', 
 * YG', and CbB') according to the following equations:
 *
 * CrR' = (CrR+cr_ioff)*cr[0] + (YG+yg_ioff)*cr[1] + (CbB+cb_ioff)*cr[2] + cr_ooff
 * YG'  = (CrR+cr_ioff)*yg[0] + (YG+yg_ioff)*yg[1] + (CbB+cb_ioff)*yg[2] + yg_ooff
 * CbB' = (CrR+cr_ioff)*cb[0] + (YG+yg_ioff)*cb[1] + (CbB+cb_ioff)*cb[2] + cb_ooff
 *
 */
typedef struct
{
    avcap_bool_t use_default; ///< AVCAP_TRUE : use default coefficients
                              ///< AVCAP_FALSE: use custom coefficients
    int   cr_ioff; ///< The offset applied to the input Cr/R component.Range: [-4096,4095]
    int   yg_ioff; ///< The offset applied to the input Y/G component. Range: [-4096,4095]
    int   cb_ioff; ///< The offset applied to the input Cb/B component.Range: [-4096,4095]
    int   cr_ooff; ///< The offset applied to the output Cr/R component.Range: [-4096,4095]
    int   yg_ooff; ///< The offset applied to the output Y/G component.Range: [-4096,4095]
    int   cb_ooff; ///< The offset applied to the output Cb/B component.Range: [-4096,4095]
    unsigned int cr[3]; ///< The 3 coefficients for Cr/R component in 3.10 fixed point
    unsigned int yg[3]; ///< The 3 coefficients for Y/G component in 3.10 fixed point
    unsigned int cb[3]; ///< The 3 coefficients for Cb/B component in 3.10 fixed point

    avcap_csc_clamp_t  clamp_in;   ///< Input clamp option
    avcap_csc_clamp_t  clamp_out;  ///< Output clamp option
} avcap_csc_options_t;

/**
 * @ingroup api_kernel
 *
 * Signature of the callback function used for events delivery
 */
typedef avcap_ret_t (* avcap_callback_t) (avcap_event_t * event, void * cookie);

/**
 * @ingroup api_kernel
 *
 * Callback registration structure to be used with #AVCAP_SEND_CALLBACK command.
 * Be extremely careful when using this mechanism instead of #avcap_event_recv
 * as callback execution time may impact functionality of entity performing
 * the callback. Unregistration is done by setting foo field to NULL.
 */
typedef struct
{
    avcap_callback_t foo;    ///< Event delivery function to be called
    void *           cookie; ///< Caller's cookie to be passed back to callback
    avcap_bool_t     sync;   ///< Type of callback
} avcap_callback_info_t;

/**
 * @ingroup api_kernel
 *
 * This structure contains a set of helper function that AVCAP client may find
 * helpful when processing commands registred with AVCAP core.
 */
typedef struct
{
    /** Verification of call origination. Logical true indicates call was
     *  originated in user space, logical false indicates call origination from
     *  kernel space.
     */
    avcap_ret_t (* user_process)(unsigned int id, avcap_bool_t * origin);
    
} avcap_service_t;

/**
 * @ingroup api_kernel
 *
 * Information structure provided by the capture control SW during registration
 * with AVCAP core via #avcap_client_register. Fields of this structure represent
 * funtional entry points into capture control SW that allow AVCAP core to manage
 * control data flow from / to the device. Entry points that are not supported by the
 * device @b must be set to NULL.
 */
typedef struct
{
    /** Name of the capture device. Specifically, a name that SW interested in
     *  communicating with this device can use when calling #avcap_device_get_id
     */
    char name[20];
    
    /** Accepts capture start request from the rendering SW
     */
    avcap_ret_t (*start)(void);
    
    /** Accepts capture stop request from the rendering SW
     */
    avcap_ret_t (*stop )(void);
    
    /** Accepts a notification of an input video mode change coming from the input
     *  control SW. Typically should adjust capture device appropriately and
     *  notify the rendering SW by sending a #AVCAP_EVENT_VIDEO_MODE_CHANGE
     *  event via #avcap_event_send.
     */
    avcap_ret_t (*video_mode_set)(avcap_video_mode_t * mode);
    
    /** Returns information about current video mode to the rendering SW
     */
    avcap_ret_t (*video_mode_get)(avcap_video_mode_t * mode);
    
    /** Accepts a notification of an input audio mode change coming from the input
     *  control SW. Typically should adjust capture device appropriately and
     *  notify the rendering SW by sending a a #AVCAP_EVENT_AUDIO_MODE_CHANGE
     *  event via #avcap_event_send.
     */
    avcap_ret_t (*audio_mode_set)(avcap_audio_mode_t * mode);
    
    /** Returns information about current video mode to the rendering SW
     */
    avcap_ret_t (*audio_mode_get)(avcap_audio_mode_t * mode);
    
    /** Accepts buffers provided by the rendering SW. Implementation of this entry
     *  point is not mandatory as AVCAP core provides its own buffer management
     *  mechanism.
     */
    avcap_ret_t (*buffer_add       )(avcap_buffer_type_t   type,
                                     avcap_buffer_info_t * info);
    
    /** Accepts request of the rendering SW to discard all the buffers it has
     *  previously supplied. Implementation of this entry point is not mandatory
     *  as AVCAP core provides its own buffer management mechanism.
     */
    avcap_ret_t (*buffer_cancel_all)(avcap_buffer_type_t   type);
    
    /** Accepts generic data submitted by the rendering SW.
     */
    avcap_ret_t (*send)(avcap_send_t type, void * data, unsigned int size);
    
    /** Returns generic data requested by the rendering SW.
     */
    avcap_ret_t (*recv)(avcap_recv_t type, void * data, unsigned int size);
    
} avcap_client_t;

#endif // __AVCAP_H__
