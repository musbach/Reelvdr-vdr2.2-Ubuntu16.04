/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2006-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2006-2011 Intel Corporation. All rights reserved.
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
#define ECR200090_DPE_PART_ENABLE

#ifndef __ISMD_GLOBAL_DEFS_H__
#define __ISMD_GLOBAL_DEFS_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup smd_core */
/** @{ */

/**
List of all ISMD return codes
*/
typedef enum {
   ISMD_SUCCESS                              =  0,
   ISMD_ERROR_FEATURE_NOT_IMPLEMENTED        =  1,
   ISMD_ERROR_FEATURE_NOT_SUPPORTED          =  2,
   ISMD_ERROR_INVALID_VERBOSITY_LEVEL        =  3,
   ISMD_ERROR_INVALID_PARAMETER              =  4,
   ISMD_ERROR_INVALID_HANDLE                 =  5,
   ISMD_ERROR_NO_RESOURCES                   =  6,
   ISMD_ERROR_INVALID_RESOURCE               =  7,
   ISMD_ERROR_INVALID_QUEUE_TYPE             =  8,
   ISMD_ERROR_NO_DATA_AVAILABLE              =  9,

   ISMD_ERROR_NO_SPACE_AVAILABLE             = 10,
   ISMD_ERROR_TIMEOUT                        = 11,
   ISMD_ERROR_EVENT_BUSY                     = 12,
   ISMD_ERROR_OBJECT_DELETED                 = 13,

   ISMD_ERROR_ALREADY_INITIALIZED            = 17,
   ISMD_ERROR_IOCTL_FAILED                   = 18,
   ISMD_ERROR_INVALID_BUFFER_TYPE            = 19,
   ISMD_ERROR_INVALID_FRAME_TYPE             = 20,

   ISMD_ERROR_QUEUE_BUSY                     = 21,
   ISMD_ERROR_NOT_FOUND                      = 22,
   ISMD_ERROR_OPERATION_FAILED               = 23,
   ISMD_ERROR_PORT_BUSY                      = 24,

   ISMD_ERROR_NULL_POINTER                   = 25,
   ISMD_ERROR_INVALID_REQUEST                = 26,
   ISMD_ERROR_OUT_OF_RANGE                   = 27,
   ISMD_ERROR_NOT_DONE                       = 28,
   ISMD_ERROR_SUSPENDED                      = 29, /* Low-power state */
   
   ISMD_LAST_NORMAL_ERROR_MARKER,

   ISMD_ERROR_UNSPECIFIED                    = 99
} ismd_result_t;


/**
ismd_verbosity_level_t is defines the level of detail in the messages reported
by the SMD.
TODO: Create specific definitions for these.
*/
typedef enum {
   ISMD_LOG_VERBOSITY_OFF     = 0, /**< Logging is OFF */
   ISMD_LOG_VERBOSITY_LEVEL_1 = 1, /**< Minimal detail */
   ISMD_LOG_VERBOSITY_LEVEL_2 = 2,
   ISMD_LOG_VERBOSITY_LEVEL_3 = 3,
   ISMD_LOG_VERBOSITY_LEVEL_4 = 4  /**< Maximum detail */
} ismd_verbosity_level_t;

/** Playback rate in SMD is normalized to 10000. */
#define ISMD_NORMAL_PLAY_RATE 10000

/** A known invalid device handle is provided for convenience to developers. */
#define ISMD_DEV_HANDLE_INVALID -1

/** Opaque handle used for accessing a device */
typedef int ismd_dev_t;
typedef ismd_dev_t ismd_dev_handle_t; /* deprecated device type */

/** Device types supported by the streaming media drivers */
typedef enum {
   ISMD_DEV_TYPE_INVALID   = 0, /**< A known invalid device type. */
   ISMD_DEV_TYPE_CORE      = 1, /**< Fuctions/Features not specific to any one device. */
   ISMD_DEV_TYPE_TS_OUTPUT = 2, /**< Transport Stream Output */
   ISMD_DEV_TYPE_DEMUX     = 3, /**< Stream Demultiplexor */
   ISMD_DEV_TYPE_AUDIO     = 4, /**< Audio decode/mix/render/etc. */
   ISMD_DEV_TYPE_VIDDEC    = 5, /**< Video decoder */
   ISMD_DEV_TYPE_VIDPPROC  = 6, /**< Video pre-processor */
   ISMD_DEV_TYPE_VIDREND   = 7  /**< Video renderer */
} ismd_device_type_t;


typedef enum {
   ISMD_DEV_STATE_INVALID = 0,
   ISMD_DEV_STATE_STOP    = 1,
   ISMD_DEV_STATE_PAUSE   = 2,
   ISMD_DEV_STATE_PLAY    = 3
} ismd_dev_state_t;


/** Codecs supported by streaming media drivers */
typedef enum {
   ISMD_CODEC_TYPE_INVALID = 0, /**< A known invalid codec type. */
   ISMD_CODEC_TYPE_MPEG2   = 1, /**< MPEG2 video codec type. */
   ISMD_CODEC_TYPE_H264    = 2, /**< H264 video codec type. */
   ISMD_CODEC_TYPE_VC1     = 3, /**< VC1 video codec type. */
   ISMD_CODEC_TYPE_MPEG4   = 4, /**< MPEG4 video codec type. */
   ISMD_CODEC_TYPE_JPEG    = 5  /**< JPEG video codec type. */
} ismd_codec_type_t;

/** Frame types supported by the video decoder */
typedef enum
{
    ISMD_FRAME_TYPE_UNKNOWN = 0, /**< Unknown type - default value */
    ISMD_FRAME_TYPE_IDR     = 1, /**< IDR frame - h264 only */
    ISMD_FRAME_TYPE_I       = 2, /**< I frame */
    ISMD_FRAME_TYPE_P       = 3, /**< P frame */
    ISMD_FRAME_TYPE_B       = 4, /**< B frame */
    ISMD_FRAME_TYPE_BI      = 5, /**< BI frame - Intracoded B frame - vc1 only */
    ISMD_FRAME_TYPE_SKIP    = 6, /**< Skipped frame - vc1 only */
    ISMD_FRAME_TYPE_D       = 7, /**< D frame - mpeg1 only */
    ISMD_FRAME_TYPE_S       = 8, /**< SVOP frame - mpeg4 only - sprite encoded frame - treat as P */
    ISMD_FRAME_TYPE_MAX     = 9
} ismd_frame_type_t;

typedef uint32_t ismd_physical_address_t;

/******************************************************************************/
/* Event-related defines and datatypes */
/******************************************************************************/

/** A known invalid event handle is provided for convenience to developers. */
#define ISMD_EVENT_HANDLE_INVALID -1

/** Timeout value that indicates you should wait forever. */
#define ISMD_TIMEOUT_NONE ((unsigned int)0xFFFFFFFF)

/** Event handle */
typedef int ismd_event_t;

/** Maximum number of events in an event list.  Relavent only to ismd_event_wait_multiple. */
/* TODO:  Profile what an appropriate maximum number of events should be. */
#define ISMD_EVENT_LIST_MAX 16

/** A list of events.  Relevant only to ismd_event_wait_multiple. */
typedef ismd_event_t ismd_event_list_t[ISMD_EVENT_LIST_MAX];

/******************************************************************************/
/* Message-related defines and datatypes */
/******************************************************************************/

typedef uint32_t ismd_message_context_t;

/** Max message context id definition */
#define ISMD_MESSAGE_CONTEXT_MAX       16
#define ISMD_MESSAGE_CONTEXT_INVALID    ISMD_MESSAGE_CONTEXT_MAX

/** Maximum message type per message context*/
#define ISMD_MESSAGE_TYPE_MAX   16

/** Maximum subscribers one message support*/
#define ISMD_MESSAGE_MAX_SUBSCRIBERS_PER_MESSAGE   4

/** This is used to return message*/
typedef struct {
   uint32_t type;
   uint32_t count;
   /* Currently only 8 bytes of message data supported.
    * To extend this, you may use void * pointer plus a size parameter.
    */
   uint64_t data;
} ismd_message_info_t;

typedef struct {
   uint32_t num_of_items;
   ismd_message_info_t info[ISMD_MESSAGE_TYPE_MAX];
} ismd_message_array_t;

/******************************************************************************/
/* Port-related defines and datatypes */
/******************************************************************************/
typedef int ismd_port_handle_t;

/* A known invalid event handle is provided for convenience to developers. */
#define ISMD_PORT_HANDLE_INVALID -1

/*
 * Specifying this as a watermark for a port effectively disables watermark
 * events
 */
#define ISMD_QUEUE_WATERMARK_NONE -1

/**
Structure used to get the status of a port.
*/
typedef struct {
   int                    max_depth;         /**< Maximum depth of the port queue, queue will refuse data if depth would become larger than this amount */
   int                    cur_depth;         /**< Current depth of the port queue in buffers. */
   int                    watermark;         /**< Current watermark setting. */
} ismd_port_status_t;

/**
Definition of queue events.  These events are used with ports to enable
event-driven I/O using the ports.

Note that not all events are available in all situations - the availability of
events depends on which end of the port is being referred to.
Each port, whether it is an input or output port, has an input end and an output
end.  The input end is the end that buffers are written into and the output
end is the end that buffers are read from.

For output ports, the input end is generally used by the port's owning module
and the output end is either directly connected to an input port or is read by
a client application.

For input ports, the output end is generally used by the port's owning module
and the input end is either directly connected to an output port or is written
to by a client application.

The terms "input end" and "output end" are used to specify where the events can
be used.
*/
typedef enum {
    ISMD_QUEUE_EVENT_NONE           = 0,
    ISMD_QUEUE_EVENT_NOT_EMPTY      = 1 << 0,  /**< Queue has gone from empty to not empty. Only available for the output end of the port. */
    ISMD_QUEUE_EVENT_NOT_FULL       = 1 << 1,  /**< Queue has gone from full to not full. Only available for the input end of the port. */
    ISMD_QUEUE_EVENT_HIGH_WATERMARK = 1 << 2,  /**< Queue depth crossed the high watermark. Only available for the output end of the port. */
    ISMD_QUEUE_EVENT_LOW_WATERMARK  = 1 << 3,  /**< Queue depth crossed the low watermark. Only available for the input end of the port. */
    ISMD_QUEUE_EVENT_EMPTY          = 1 << 4,  /**< Queue has become empty. Only available for the input end of the port. */
    ISMD_QUEUE_EVENT_FULL           = 1 << 5,  /**< Queue has become full. Only available for the output end of the port. */

    ISMD_QUEUE_EVENT_ALWAYS         = 1 << 6   /**< Enable all available events */
} ismd_queue_event_t;



/******************************************************************************/
/* Clock-related defines and datatypes */
/******************************************************************************/

// clock types >2 are platform-specific
#define ISMD_CLOCK_TYPE_INVALID        0
#define ISMD_CLOCK_TYPE_FIXED          1
#define ISMD_CLOCK_TYPE_SW_CONTROLLED  2
#define ISMD_CLOCK_TYPE_WRAPPER        3

// For use with ismd_clock_alloc_typed
#define ISMD_CLOCK_CLASS_SLAVE         1
#define ISMD_CLOCK_CLASS_MASTER        2

// Used as both clock handle and clock type in our API
typedef int ismd_clock_t;

#define ISMD_CLOCK_HANDLE_INVALID       -1

#define valid_clock_type(type) ((type > ISMD_CLOCK_TYPE_INVALID) && (type <= ISMD_CLOCK_TYPE_SW_CONTROLLED))

/* Clock signals - the set of inputs available to an SMD clock. */
#define ISMD_CLOCK_SIGNAL_INVALID      -1
/* Common to CE3100, CE4100, CE4200 */
#define ISMD_CLOCK_SIGNAL_VCXO          0
#define ISMD_CLOCK_SIGNAL_MASTER_DDS    1
/* Common to all platforms */
#define ISMD_CLOCK_SIGNAL_LOCAL_DDS     2
/* Following are CE5300 specific */
#define ISMD_CLOCK_SIGNAL_A_MASTER      3
#define ISMD_CLOCK_SIGNAL_V_MASTER      4
#define ISMD_CLOCK_SIGNAL_EXT_MASTER    5
#define ISMD_CLOCK_SIGNAL_HDMI_AUD      6
/* Pseudo-signal valid on all platforms */
#define ISMD_CLOCK_SIGNAL_DEFAULT       7

/* Clock origins - the actual producer of a clock signal */
#define ISMD_CLOCK_ORIGIN_INVALID      -1
/* Common to all platforms */
#define ISMD_CLOCK_ORIGIN_LOCAL         0
/* Common to CE3100, CE4100, CE4200, CE5300 */
#define ISMD_CLOCK_ORIGIN_MASTER_DDS    1
#define ISMD_CLOCK_ORIGIN_VCXO_0        2  /* Primary VCXO */

/* Following are CE5300 specific */
#define ISMD_CLOCK_ORIGIN_VCXO_1        3  /* Secondary VCXO */
#define ISMD_CLOCK_ORIGIN_NOSC_0        4  /* Oscillator 0 */
#define ISMD_CLOCK_ORIGIN_NOSC_1        5  /* Oscillator 1 */
#define ISMD_CLOCK_ORIGIN_DEFAULT       6

/* Clock domain types.*/
#define  ISMD_CLOCK_DOMAIN_TYPE_AUDIO   0
#define  ISMD_CLOCK_DOMAIN_TYPE_VIDEO   1
#define  ISMD_CLOCK_DOMAIN_TYPE_FIXED   2
#define  ISMD_CLOCK_DOMAIN_TYPE_LOCAL   3
#define  ISMD_CLOCK_DOMAIN_TYPE_AV      1000
#define  ISMD_CLOCK_DOMAIN_TYPE_DEFAULT 2000

#define ISMD_CLOCK_ALARM_HANDLE_INVALID -1

typedef uint64_t ismd_time_t;

typedef int ismd_clock_alarm_t;

/** Defines the structure for the clock time information.
 *  See ismd_clock_set_time_discontinuity_event for more description about time discontinuity information.
 *
 *                                                 second_recent_set_timestamp
 *                                                             #    most_recent_set_timestamp
 *                       set_timestamp_causing_discontinuity   #              #
 *   set_timestamp_before_discontinuity     #                  #              #
 *                 #                       TS2                TS3            TS4
 *                TS1                       +                  +              +
 *                 +                        +=======================================================>
 *                 +                        |\__                              #                     #
 * clock time ==============================+   #clock_time_at_discontinuity  #                current_time
 *                 #                        #           clock_time_of_most_recent_set_timestamp
 *                 #      clock_time_before_discontinuity
 *   clock_time_of_set_timestamp_before_discontinuity
 **/
typedef struct ismd_clock_time_info_struct {
   /** The current time value of the clock in ticks. */
   ismd_time_t                current_time;

   /** The timestamp set to the clock in the second recent set_time. */
   ismd_time_t                second_recent_set_timestamp;

   /** The timestamp set to the clock in the most recent set_time. */
   ismd_time_t                most_recent_set_timestamp;

   /** The clock time value when performing the most recent set_time. */
   ismd_time_t                clock_time_of_most_recent_set_timestamp;

   /** The timestamp set to the clock in the most recent set_time before the most
       recent discontinuity. */
   ismd_time_t                set_timestamp_before_discontinuity;

   /** The clock time value when performing the most recent set_time before
       the most recent discontinuity. */
   ismd_time_t                clock_time_of_set_timestamp_before_discontinuity;

   /** The clock time value just before the most recent discontinuity happens.
       This value is usually bigger than clock_time_of_set_timestamp_before_discontinuity. */
   ismd_time_t                clock_time_before_discontinuity;

   /** The timestamp set to the clock that causing the most recent discontinuity. */
   ismd_time_t                set_timestamp_causing_discontinuity;

   /** The clock time value when the most recent discontinuity happens.
       This value is usually equal to set_timestamp_causing_discontinuity. */
   ismd_time_t                clock_time_at_discontinuity;

   /** The count of discontinuity ever happens to the clock. */
   unsigned int               time_discontinuity_count;
} ismd_clock_time_info_t;


/******************************************************************************/
/* Buffer-related defines and datatypes */
/******************************************************************************/
typedef ismd_time_t  ismd_pts_t;
#define ISMD_NO_PTS  ((ismd_pts_t)-1)

typedef ismd_time_t  ismd_dts_t;
#define ISMD_NO_DTS  ((ismd_dts_t)-1)

typedef ismd_time_t  ismd_ats_t;
#define ISMD_NO_ATS  ((ismd_ats_t)-1)

#define ISMD_INVALID_BIT_RATE ((uint32_t)(-1))

typedef int ismd_buffer_id_t;
typedef ismd_buffer_id_t ismd_buffer_handle_t;
#define ISMD_BUFFER_HANDLE_INVALID -1
#define ISMD_PMR_NONE -1     /*  Signifies an "untrusted" state */ 
#define ISMD_FRAME_BUFFER_MANAGER_NO_CONTEXT -1
#define ISMD_CONTEXT_NONE 0

#define ISMD_BUFFER_IS_CACHED(buf_type) ((buf_type) == ISMD_BUFFER_TYPE_PHYS_CACHED)
#define ISMD_BUFFER_MAP_BY_TYPE(buf_type, base_address, size) \
            (ISMD_BUFFER_IS_CACHED(buf_type) ? OS_MAP_IO_TO_MEM_CACHE(base_address, size) : OS_MAP_IO_TO_MEM_NOCACHE(base_address, size))

/** Defines the physical address attributes of the buffer */
typedef struct ismd_phys_buf_node {
   ismd_physical_address_t      base;             /**< Physical base address. */
   int                          size;             /**< Physical size of the buffer allocated in bytes. */
   int                          level;            /**< Actual amount of data in the buffer in bytes (level <= size) */
   struct ismd_phys_buf_node   *next_node;        /**< Should always be NULL. Should be deprecated after modules are updated. */
} ismd_phys_buf_node_t;

/** Defines the virtual address attributes of the buffer */
typedef struct ismd_virt_buf_node {
   void                       *base;              /**< Virtual starting address. */
} ismd_virt_buf_node_t;

/** Defines the type of the ismd_buffer */
typedef enum {
   ISMD_BUFFER_TYPE_INVALID = 0,
   ISMD_BUFFER_TYPE_PHYS = 1,                     /**< Linear physical buffer */
   ISMD_BUFFER_TYPE_VIDEO_FRAME = 2,              /**< for strided video frame buffers.  This is a physical type */
   ISMD_BUFFER_TYPE_VIDEO_FRAME_REGION = 3,       /**< for frame buffer memory region descriptors.  This should only be used internal to the ISMD core */
   ISMD_BUFFER_TYPE_ALIAS = 4,                    /**< Aliased buffers. This should only be used internal to the ISMD core */
   ISMD_BUFFER_TYPE_PHYS_CACHED = 5,              /**< Linear physical buffer with a cached virtual memory address.  Available only to SMD compliant drivers. */
   ISMD_BUFFER_TYPE_PHYS_EXT_MAP = 6              /**< Linear physical buffer allocated and mapped external to the SMD core.  Available only to SMD compliant drivers. */
} ismd_buffer_type_t;

struct ismd_buffer_descriptor_struct;

/** Reserved for use by SMD infrastructure. */
typedef ismd_result_t (* ismd_release_func_t)(void *context, struct ismd_buffer_descriptor_struct *buffer_descriptor);

/** Descriptor for ISMD buffers. */
typedef struct ismd_buffer_descriptor_struct {
   int                                   state;            /**< Reserved for use by SMD infrastructure.                                */
   ismd_buffer_type_t                    buffer_type;      /**< Linear physical buffer or frame buffer                                 */
   ismd_phys_buf_node_t                  phys;             /**< Physical address attributes                                            */
   ismd_virt_buf_node_t                  virt;             /**< Virtual address attributes                                             */
   ismd_buffer_id_t                      unique_id;        /**< System-wide unique identifier assigned to this buffer by the SMD Core.
                                                                May be used in calls to ismd_buffer_read_desc                          */
   struct ismd_buffer_descriptor_struct *next;             /**< Reserved for use by SMD infrastructure.                                */
   int                                   reference_count;  /**< Number of drivers currently processing this buffer.  Should be updated
                                                                by whoever allocates the buffer.                                       */
   ismd_release_func_t                   release_function; /**< Function to call when reference_count == 0.  This function allows one
                                                                device to be notified when all other devices have finished processing
                                                                the buffer.                                                            */
   void                                 *release_context;  /**< Context information passed unmodifed to the release function.          */
   int                                   data_type;        /**< Media data type.                                                       */
   int                                   tags_present;     /**< Indicates whether or not this buffer has associated tags.  0 if no tags
                                                                and nonzero if there are tags.                                         */
   int                                   pmr;              /**< Indicates which protected memory region contains this buffer.          */
   unsigned char                         attributes[256];  /**< Space for buffer-specific attributes.  Drivers can define their own    */
                                                           /**< buffer attribute structures and cast this space to those structures.   */
} ismd_buffer_descriptor_t;


/** Options specifying the frame buffers to be allocated. **/
typedef union {
   /* The context */
   struct {
      /* PMR identifier of the buffer to allocate. ISMD_PMR_NONE (-1) will allocate an unsecured buffer.*/
      int pmr;

      /* Context identifier of the buffer to allocate. ISMD_CONTEXT_NONE (-1) will allocate a buffer with no context.*/
      int id;
   } context;
} ismd_buffer_alloc_options_t;

/**
The following time domains are referred to in the description of ismd_newsegment_tag_t.
Segment time - original time domain of content (segment start, stop is in this domain)
Linear time  - Local monotonically increasing 1x timeline (before rate adjustment)
Scaled time  - Local timeline after accounting for playback rate
Clock time   - actual counter time in smd clock corresponding to scaled time.
*/
/** Defines the data for the newsegment buffer tag */
typedef struct {
   ismd_pts_t start;                      /**<First point in the segment to be presented in forward playback.
                                              Expressed in original media time.
                                              Used to correlate phase between original media time and local
                                              presentation time for forward segments. It corresponds to
                                              local_presentation_time in forward playback.
                                              If this value is specified as ISMD_NO_PTS, it is ignored and the
                                              segment is played from the beginning. */
   ismd_pts_t stop;                       /**<First point in the segment to be presented in reverse playback.
                                              Expressed in original media time.
                                              Used to correlate phase between original media time and local
                                              presentation time for reverse segments. It corresponds to
                                              local_presentation_time in reverse playback.
                                              If this value is specified as ISMD_NO_PTS, it is ignored and the
                                              segment is played till the end. */
   ismd_pts_t linear_start;               /**<Local/play time corresponding to start/stop
                                              (depending on playback direction). */
   int        requested_rate;             /**<Overall play rate required for the segment. Expressed as a fixed point value (when
                                              expressed in decimal) with 4 digits of fractional part.
                                              For example, 10000 indicates 1.0X playback; 5000 -> 0.5X, -25000 -> -2.5X, etc. */
   int        applied_rate;               /**<Play rate achieved for this segment, by earlier elements in the pipeline. Expressed
                                              in the same fixed point format as \a requested_rate. If \a applied_rate equals \a
                                              requested_rate for a segment, downstream elements do not need to do anything further
                                              to achieve the final play rate. */
   bool rate_valid;                       /**<A flag to indicate if the requested_rate in this segment is valid or not.
                                              If false, the requested_rate from this segment is ignored and elements
                                              continue playing at the previous requested_rate (from newsegment or API). */
   ismd_pts_t segment_position;           /**<The segment's position in the stream. This should be a value between zero
                                              and the duration of the clip to guarantee a correct calculation of the stream position.
                                              ISMD_NO_PTS is allowed for this field if application doesn't need to maintain the stream position across segments.
                                              If ISMD_NO_PTS passed, the stream position query APIs in renderers will not report the correct stream_position
                                              (other fields returned by query function is still correct)*/
} ismd_newsegment_tag_t;

/** The maximum number of dynamic input entries that can
  * be set on any single buffer as any single attribute.
  * This can be expanded, but requires that the ISMD_MAX_TAG_SIZE
  * internal define is also expanded.
  *
  * Currentle max tag size is 256 bytes.  16 of these is too big, so using 15.
  */
#define ISMD_MAX_DYN_INPUT_ENTRIES 15

/**
  * Defines data for the dynamic input attributes. These are used for changing
  * the PID and/or the formatting of the incoming data.  This is meant to be
  * only for buffers that are at the input of the demux.  If format change needs
  * to be communicated after this point, there is a data_type field in the buffer
  * descriptor that is used to specify format.
  */
typedef struct ismd_dyn_input_buf_attr {
   unsigned             length;           /**< How many entries are valid in this structure */
   struct {
      union {
         struct {
            uint16_t         pid;                        /**< PID to change to */
         } transport_stream;
         struct {
            uint8_t         stream_id;                   /**< SID to change to */
            uint8_t         substream_id;                /**< substream to change to */
            unsigned        data_offset;                 /**< Data offset of substream */
         } program_stream;
      } stream_info ;
      unsigned               filter_id;                  /**< Demux filter that the PID is mapped to */
      ismd_codec_type_t      codec_format;               /**< Format of the data on the new PID */
   } dyn_filter[ISMD_MAX_DYN_INPUT_ENTRIES];
} ismd_dyn_input_buf_tag_t;



/******************************************************************************/
/* Media specific attributes.  These are placed the buffer attributes field */
/******************************************************************************/

/**
defines attributes to be carried for compressed (ES) data.
*/
typedef struct {
   ismd_pts_t              original_pts;   /**< Original unmodified presentation
                                                timestamp from the
                                                content.  The bit width of this
                                                value depends on the content.
                                                The resolution of this timestamp
                                                also depends on the content.
                                                ISMD_NO_PTS indicates no PTS. */

   ismd_pts_t              local_pts;      /**< Local modified presentation
                                                timestamp for this buffer.
                                                64-bit value representing 90kHz
                                                ticks. Rollovers should
                                                be masked so that this value
                                                never decreases during normal
                                                playback of a single stream.
                                                ISMD_NO_PTS indicates no PTS. */

   bool                    discontinuity;  /**< If true, this buffer is the first
                                                buffer after a discontinuity has
                                                been detected. */
   bool                    pvt_data_valid; /**< If true, Valid data is present
                                                 in pvt_data array */
   uint8_t                 pvt_data[16];   /**< The Audio Description stream can
                                                carry the pan-scan information in
                                                this array.*/
   ismd_dts_t              original_dts;   /**< Original unmodified decode
                                                timestamp (DTS) from the
                                                content.  The bit width of this
                                                value depends on the content.
                                                The resolution of this timestamp
                                                also depends on the content.
                                                ISMD_NO_DTS indicates no DTS. */

   bool                    au_start;       /**< If true, es buffer is the beginning
                                                of a new access unit. */
   
   unsigned int            au_size;        /**< If au_start is true, au_size is
                                                the size of the new access unit.
                                                If not known, this is 0. */
                                                /* 4 Bytes */

   ismd_ats_t              original_ats;   /**< Arrival time of the Access Unit when 
										        taking into account the 
												Coded Picture Buffer (CPB) delay defined 
												by the encoder (this is DTS minus the CPB delay). 
												This information may be provided by video encoders, 
												and is only relevant in a transcoding use case.
												ISMD_NO_ATS indicates no ATS. */
                                               
   uint32_t                bit_rate;       /**< The ES bit rate of the associated buffer (bits/sec).
                                                ISMD_INVALID_BIT_RATE if the bit
                                                rate is not specified */
                                               
                                                
   // We may need to add some audio-specific attributes here as well...
} ismd_es_buf_attr_t;

/**
defines attributes to be carried for TS data.
*/
typedef struct {
  uint32_t    packet1_num; /**< The Packet number of the first TS packet
                                contained in this buffer. Packet numbers
                                start from zero when the stream data
                                starts flowing. 0xFFFFFFFF is invalid. */
  uint32_t    packet_curr_num; /**< The current packet number of the current
                                (last) TS packet. This is the current packet
                                number the fw is dealing with when the buffer
                                was emitted.*/
  // In future, the indexing data (max 15 records) could be contained here as well.
} ismd_ts_buf_attr_t;

/** Enumeration of user data types */
typedef enum
{
    ISMD_UD_TYPE_UNKNOWN,
    ISMD_UD_TYPE_SEQ,            /* Sequence Level User Data */
    ISMD_UD_TYPE_GOP,            /* GOP/EP/GVOP Level User Data */
    ISMD_UD_TYPE_FRAME,          /* Frame/VOP Level User Data */
    ISMD_UD_TYPE_FIELD,          /* Field Level User Data */
    ISMD_UD_TYPE_SLICE,          /* Slice Level User Data */
    ISMD_UD_TYPE_VISUAL_OBJ,     /* Visual Object Level User Data */
    ISMD_UD_TYPE_VIDEO_OBJ,      /* Video Object Level User Data */
    ISMD_UD_TYPE_REGISTERED,     /*  H264 Registered User Data */
    ISMD_UD_TYPE_UNREGISTERED,   /*  H264 UnRegistered User Data */
    ISMD_UD_TYPE_SEI_FRAME_PACKING, /* H264 SEI Frame Packing Message */
} ismd_userdata_type_t;

/**
Polarity for this buffer.  Is it a top field, bottom field, or progressive?
*/
typedef enum {
    ISMD_POLARITY_FRAME          =1,   /**< Progressive - frame based */
    ISMD_POLARITY_FIELD_TOP      =2,   /**< Interlaced - field based,
                                            top/odd field */
    ISMD_POLARITY_FIELD_BOTTOM   =3    /**< Interlaced - field based,
                                            bottom/even field */
} ismd_frame_polarity_t;

/**
defines attributes to be carried for user (UD) data buffers.
*/
typedef struct {
   ismd_pts_t           original_pts;     /**< Original unmodified presentation
                                             timestamp from the
                                             content.  The bit width of this
                                             value depends on the content.
                                             The resolution of this timestamp
                                             also depends on the content.
                                             ISMD_NO_PTS indicates no PTS. */

   ismd_pts_t           local_pts;        /**< Local modified presentation
                                             timestamp for this buffer.
                                             64-bit value representing 90kHz
                                             ticks. Rollovers should
                                             be masked so that this value
                                             never decreases during normal
                                             playback of a single stream.
                                             ISMD_NO_PTS indicates no PTS. */

   ismd_userdata_type_t user_data_type;   /**< Type of user data in this buffer. */
                                    
   ismd_frame_polarity_t polarity;        /**< polarity of the user data for
                                             this buffer. If
                                             ISMD_POLARITY_FIELD_TOP(or
                                             ISMD_POLARITY_FIELD_BOTTOM), this
                                             user data buffer corresponds to
                                             the top field(or bottom field) of
                                             the frame.*/
                                               /* 4 Bytes */

   bool                 discontinuity;    /**< If true, this buffer is the first
                                             buffer after a discontinuity has
                                             been detected. */
   bool                 top_field_first;  /**  If true, the top field first*/
   bool                 repeat_first_field;/** If true, repeat the first field */

   unsigned char        filler[1];        /**< Filler for alignment. */

   unsigned char        uuid_iso_iec_11578[16]; /** <the iso iec 11578 uuid associated 
                                                    with the user data buffer.
                                                    valid only if user_data_type ==
                                                    ISMD_UD_TYPE_UNREGISTERED. */

   unsigned char        debug[212];          /**< Remaining space for debug. */

} ismd_ud_buf_attr_t;

/**
Enumeration of video formats.  Note that not all stages of the pipeline
support all of these formats.

See http://www.fourcc.org/yuv.php for explanations of these formats
*/
typedef enum {
    /* RGB types */
    ISMD_PF_ARGB_32,          /**< ARGB 32bpp 8:8:8:8 LE */
    ISMD_PF_RGB_32,           /**< xRGB 32bpp 8:8:8:8 LE */
    ISMD_PF_RGB_24,           /**< RGB 24bpp 8:8:8 LE */
    ISMD_PF_ARGB_16_1555,     /**< ARGB 16bpp 1:5:5:5 LE */
    ISMD_PF_ARGB_16_4444,     /**< ARGB 16bpp 4:4:4:4 LE */
    ISMD_PF_RGB_16,           /**< RGB  16bpp 5:6:5 LE */
    ISMD_PF_RGB_15,           /**< xRGB 16bpp 1:5:5:5 LE */

    /* Pseudo color types */
    ISMD_PF_RGB_8,            /**< RGB  8bpp - 24bpp palette RGB 8:8:8 */
    ISMD_PF_ARGB_8,           /**< ARGB 8bpp - 32bpp palette ARGB 8:8:8:8 */

    /* Packed YUV types */
    ISMD_PF_YUY2,             /**< YUV 4:2:2 Packed */
    ISMD_PF_UYVY,             /**< YUV 4:2:2 Packed */
    ISMD_PF_YVYU,             /**< YUV 4:2:2 Packed */
    ISMD_PF_VYUY,             /**< YUV 4:2:2 Packed */

    /* Planar YUV types */
    ISMD_PF_YV12,             /**< YVU 4:2:0 Planar (V plane precedes U) */
    ISMD_PF_YVU9,             /**< YUV 4:2:0 Planar */
    ISMD_PF_I420,             /**< YUV 4:2:0 Planar (U plane precedes V) */
    ISMD_PF_IYUV=ISMD_PF_I420,/**< Synonym for I420 */
    ISMD_PF_I422,             /**< YUV 4:2:2 Planar (U plane precedes V) */
    ISMD_PF_YV16,             /**< YVU 4:2:2 Planar (V plane precedes U) */

    /* Pseudo-planar YUV types */
    ISMD_PF_NV12,             /**< YUV 4:2:0 Pseudo-planar */
    ISMD_PF_NV15,
    ISMD_PF_NV16,             /**< YUV 4:2:2 Pseudo-planar */
    ISMD_PF_NV20,

    ISMD_PF_A8,               /**< 8-bit Alpha only surface. For 3D graphics*/
    ISMD_PF_YV8,              /**< YUV 4:0:0 Planar */
    ISMD_PF_YV24,             /**< YUV 4:4:4 Planar */ 

    ISMD_PF_COUNT             /**< Number of defined pixel formats */
} ismd_pixel_format_t;

/**
Enumeration of reverse gamma correction types.
*/
typedef enum {
    ISMD_GAMMA_NTSC,
    ISMD_GAMMA_PAL,
    ISMD_GAMMA_SECAM,
    ISMD_GAMMA_HDTV,
    ISMD_GAMMA_LINEAR
} ismd_gamma_t;

/**
Enumeration of color spaces.
*/
typedef enum {
    ISMD_SRC_COLOR_SPACE_BT601,        /**< BT601 */
    ISMD_SRC_COLOR_SPACE_BT709,        /**< BT709 */
    ISMD_SRC_COLOR_SPACE_RGB,          /**< RGB */
    ISMD_SRC_COLOR_SPACE_XVYCC601,     /**< XVYCC 601 */
    ISMD_SRC_COLOR_SPACE_XVYCC709,     /**< XVYCC 709 */
    ISMD_SRC_COLOR_SPACE_BYPASS,
    ISMD_SRC_COLOR_SPACE_UNKNOWN       /**< Content did not specify */
} ismd_src_color_space_t;

/*
Enumeration to be used to populate the frame attribute flag.
*/
typedef enum {
   ISMD_FRAME_NO_DEINTERLACE = 0<<0,  //Set by DPE to indicate the frame was not deinterlaced
   ISMD_FRAME_DEINTERLACE = 1<<0      //Set by DPE to indicate the frame was deinterlaced. 
} ismd_frame_flag_t;


/**
Pan-scan window offsets.
*/
typedef struct {
   unsigned int horz_offset;           /**< Horizontal offset of window start
                                            (how many pixels on the left side
                                            are skipped) in pixels */
   unsigned int vert_offset;           /**< Vertical offset of window start
                                            (how many pixels on the top
                                            are skipped) in pixels */
   unsigned int horz_size;             /**< Width of the pan-scan window*/
   unsigned int vert_size;             /**< Height of the pan-scan window*/

} ismd_pan_scan_offset_t;

/**
Aspect ratio is expressed as a fraction: numerator and denominator.
*/
typedef struct {
   unsigned int numerator;
   unsigned int denominator;
} ismd_aspect_ratio_t;


/**
Generic rectangle size descriptor - generally used to express video frame size.
*/
typedef struct {
   unsigned int width;                 /**< in pixels */
   unsigned int height;                /**< in pixels */
} ismd_rect_size_t;

/**
Generic rectangle position descriptor - generally used to express video frame position.
*/
typedef struct {
   unsigned int x;                 /**< in pixels */
   unsigned int y;                /**< in pixels */
} ismd_point_t;

/**
Definition for cropping window.  Includes origin and size.
The cropping window is the subset of the source frame that is scaled
for display.
The cropping window's right and bottom edges should not go outside of the
frame.
*/
typedef struct {
   unsigned int h_offset;              /**< Horizontal offset of window start
                                            (how many pixels on the left side
                                            are skipped) in pixels */
   unsigned int v_offset;              /**< Vertical offset of window start
                                            (how many pixels on the top
                                            are skipped) in pixels */
   unsigned int width;                 /**< Window width in pixels. */
   unsigned int height;                /**< Window height in pixels. */
} ismd_cropping_window_t;


/**
@brief Describes how a region from a frame is scaled.

Describes a region (as a rectangle of pixels) from a source frame and
the region that those pixels will be mapped onto on the destination
frame.
*/
typedef struct ismd_video_scaled_region_t {
   /**
   The region (rectangle) from the original frame that was scaled.
   */
   ismd_cropping_window_t source;

   /**
   The region (rectangle) from the destination frame to which "source" is
   scaled.
   */
   ismd_cropping_window_t dest;

   /**
   Indicates that the picture is requested to be scaled non-linearly on the 
   horizontal axis (aka "anamorphic" or side stretch). For most modes scaling 
   this will be false.
   */
   bool non_linear_horizontal_scaling;
} ismd_video_scaled_region_t;


/**
Struct for NTSC (EIA-608) closed captions on line 21 extracted from CEA-708 data.
In EIA-608, each field carrise 16 bits of closed-captioning data on line 21.
Each 16-bit chunk contains two characters, each using bit 7 for parity.
The 16 bits can also be used for control words.
*/
typedef struct {
   unsigned char cc_valid;
   unsigned char cc_type;
   unsigned char cc_data1;
   unsigned char cc_data2;
} ismd_608_cc_t;


/**
The video renderer may need to know which field on the frame it receives is
unaltered.
Deinterlacing may take a field and make up data for the other field to generate
a whole frame.
If rate conversion needs to be done in the renderer, it needs to know if this
was done so it can use the unaltered field for best quality.
If both fields were changed (due to scaling) then neither field is original.
If the input source was progressive then both fields are original.
*/
typedef enum {
   ISMD_TOP_FIELD,
   ISMD_BOTTOM_FIELD,
   ISMD_BOTH_FIELDS,
   ISMD_NEITHER_FIELD,
} ismd_original_field_t;


/**
The angles that pictures in a frame buffer may represent
*/
typedef enum ismd_video_angle_t {

   /** invalid angle*/

   ISMD_VIDEO_ANGLE_NONE = 0,

   /** 2D video, no inherent angle */

   ISMD_VIDEO_ANGLE_2D,

   /** 3D video, left eye view */

   ISMD_VIDEO_ANGLE_LEFT_EYE,

   /** 3D video, right eye view */

   ISMD_VIDEO_ANGLE_RIGHT_EYE,

   /** count of angles*/

   MAX_ISMD_VIDEO_ANGLE
} ismd_video_angle_t;


/** 
 * Codec specific info required to be populated in the frame attrs
 */
typedef struct {
   union {
      struct {
         /** mpeg2 sequence display extension - see section 6.2.2.4 in 
          *  ISO/IEC 13818-2 */
         bool          colour_description; 
         unsigned char colour_primaries;   
         unsigned char transfer_char; 
         unsigned char matrix_coeff; 
      } mpeg2;

      /* any future info for other video codecs can go here */
   };
  /* any future common info for all video codecs will go here */  
} ismd_video_codec_info_t;

#define ISMD_608_CC_ARRAY_MAX 3
#define ISMD_MAX_PAN_SCAN_VECTORS 4
/**
This structure describes each video frame/field.  This is stored in the
"attributes" field of each ismd buffer descriptor.

Note on separated Fields:
Separated fields are an optional feature. They require that scanline stride and
the data offset pointers (y, u, v, bottom_y, bottom_u, and bottom_v) be
interpreted differently than in traditional mode, the diffuseness are based on
the polarity (progressive or interlaced) and Separated fields flag.

The differences in interpretation are described below:

   if (Polarity != Frame and separated_fields is false)
   {
      the top field begins at:
         data offset (y,u,v)

      the bottom field begins at:
         data offset (y,u,v) + scanline_stride/2

      the stride between lines of the same field is:
         scanline_stride

      if (scanline_stride = 0) SYSTEM_STRIDE*2 should be used

      the stride between adjacent lines of alternating fields is:
         scanline_stride/2
  }
  else if (Polarity != Frame and separated_fields is true)
  {
    the top field begins at:
      data offset (y,u,v)

    the bottom field begins at:
      bottom data offset (bottom_y, bottom_u, bottom_v)

    the stride between lines of the same field is:
      scanline_stride.

    if (scanline_stride = 0) SYSTEM_STRIDE should be used
  }
  else // (Polarity == Frame)
  {
    the frame data begins at:
      data offset (y,u,v)

    the stride between lines is:
      scanline_stride.

    if (scanline_stride = 0) SYSTEM_STRIDE should be used
  }

This structure must not exceed the size of the attributes buffer in ismd_buffer_descriptor_struct
*/
typedef struct {

   /////////////////////////////////////////////////////////////////////////////
   // Timing (28 Bytes)

   ismd_pts_t              original_pts;  /**< Original unmodified presentation
                                               timestamp from the
                                               content.  The bit width of this
                                               value depends on the content.
                                               The resolution of this timestamp
                                               also depends on the content.
                                               ISMD_NO_PTS indicates no PTS. */
                                               /* 8 Bytes */

   ismd_pts_t              local_pts;     /**< Local modified presentation
                                               timestamp for this buffer.
                                               64-bit value representing 90kHz
                                               ticks. Rollovers should
                                               be masked so that this value
                                               never decreases during normal
                                               playback of a single stream.
                                               ISMD_NO_PTS indicates no PTS. */
                                               /* 8 Bytes */

   unsigned int            cont_rate;     /**< Original framerate specified in 
                                               the content. Stored in 90kHz 
                                               ticks. If not known, this is 0. 
                                               */
                                               /* 4 Bytes */

   unsigned int            local_cont_rate;
                                          /**< Locally modified frame rate. 
                                               Stored in 90kHz ticks. */
                                               /* 4 Bytes */

   unsigned int            time_code;     /**< The time code provided in the 
                                                bitstream packed as per NDS/CDI
                                                Spec - 
                                                31    - time code available
                                                30-26 - reserved 0s
                                                25    - drop_frame_flag
                                                24-20 - hours
                                                19-14 - minutes
                                                13-8  - seconds
                                                7-0   - pictures 
                                                If not known, this is 0. */
                                               /* 4 Bytes */

   /////////////////////////////////////////////////////////////////////////////
   // Picture Position (4 Bytes)
   ismd_frame_polarity_t   polarity;      /**< value representing
                                               the polarity of the frame.
                                               Progressive = 1
                                               Top Field First = 2
                                               Bottom Field First = 3
                                               */
                                               /* 4 Bytes */
   /////////////////////////////////////////////////////////////////////////////
   // Data Layout (32 Bytes)
    ismd_pixel_format_t     pixel_format;  /**< value representing the layout
                                                of pixel data (NV12, etc...) */
                                               /* 4 Bytes */


   int                     scanline_stride;
                                          /**< number of bytes from a sample in
                                               one to the sample in the same
                                               position on the next line in
                                               any of the y, u, or v buffers.

                                               scanline_stride should never be 0
                                               if separated_fields is true.

                                               If scanline_stride == 0,
                                               SYSTEM_STRIDE should be used.
                                               */
                                               /* 4 Bytes */

   ismd_physical_address_t y;             /**< Physical offset to start of
                                               first line of Y data in this
                                               buffer, relative to the buffer's
                                               physical base address */
                                               /* 4 Bytes */

   ismd_physical_address_t u;             /**< Physical offset to start of
                                               first line of U data in this
                                               buffer, relative to the buffer's
                                               physical base address */
                                               /* 4 Bytes */

   ismd_physical_address_t v;             /**< Physical offset to start of
                                               first line of V data in this
                                               buffer, relative to the buffer's
                                               physical base address
                                               Ignored for pseudoplanar
                                               formats */
                                               /* 4 Bytes */

   ismd_physical_address_t bottom_y;      /**< Valid only if Polarity != Frame
                                               and separated_fields is true.
                                               Physical offset to start of
                                               first line of Y data for the
                                               bottom field in this
                                               buffer, relative to the buffer's
                                               physical base address */
                                               /* 4 Bytes */

   ismd_physical_address_t bottom_u;      /**< Valid only if Polarity != Frame
                                               and separated_fields is true.
                                               Physical offset to start of
                                               first line of U data for the
                                               bottom field in this
                                               buffer, relative to the buffer's
                                               physical base address */
                                               /* 4 Bytes */

   ismd_physical_address_t bottom_v;      /**< Valid only if Polarity != Frame
                                               and separated_fields is true.
                                               Physical offset to start of
                                               first line of V data for the
                                               bottom field in this
                                               buffer, relative to the buffer's
                                               physical base address
                                               Ignored for pseudoplanar
                                               formats */
                                               /* 4 Bytes */

   /////////////////////////////////////////////////////////////////////////////
   // Color (8 Bytes)
     ismd_gamma_t            gamma_type;    /**< value representing the type of
                                               reverse gamma correction.
                                               This is optional in the stream
                                               and if it is not known from the
                                               content, a default value is
                                               assumed depending on the content
                                               specification. */
                                               /* 4 Bytes */

    ismd_src_color_space_t  color_space;   /**< value representing the Color
                                               Space (601/709/etc).
                                               This is optional in the stream
                                               and if it is not known from the
                                               content the value
                                               ISMD_SRC_COLOR_SPACE_UNKNOWN
                                               will be used. */
                                               /* 4 Bytes */

   /////////////////////////////////////////////////////////////////////////////
   // Size (Resolution, Aspect Ratio, Cropping, Pan-Scan, etc.)
   //
   // Scaling is a function of the source cropping window and the destination
   // size.  The final destination aspect ration is calculated as a function
   // of the content aspect ratio (or content size if no ratio specified) and
   // the scaling.
   //
   // (120 Bytes)
   ismd_rect_size_t        cont_size;     /**< Content frame size in pixels.
                                               This is a required value. */
                                               /* 8 Bytes */

   ismd_aspect_ratio_t     cont_ratio;    /**< Aspect ratio of content.
                                               If not known, will be set to
                                               0/0 and square pixels are
                                               used. */
                                               /* 8 Bytes */

   ismd_rect_size_t        cont_disp_res; /**< Display resolution encoded in
                                               the content.  This is optional
                                               in the content and is not used
                                               for display purposes.  This is
                                               supplied in case the client
                                               needs to know this information.
                                               If not known, this will be
                                               0,0. */
                                               /* 8 Bytes */

   ismd_pan_scan_offset_t  cont_pan_scan[ISMD_MAX_PAN_SCAN_VECTORS];
                                          /**< Pan-scan coordinates
                                               extracted from the content.
                                               If pan-scan is enabled,
                                               these should already be
                                               accounted for in the
                                               src_window. */
                                               /* 16*ISMD_MAX_PAN_SCAN_VECTORS
                                                  Bytes */

   ismd_cropping_window_t  src_window;    /**< Cropping window offset and size.
                                               If no cropping, offset is 0,0
                                               and size is same as cont_size. */
                                               /* 16 Bytes */


   ismd_rect_size_t        dest_size;     /**< Origin and pixel dimensions
                                               for the destination of the frame
                                               (usually a vieo canvas). */
                                               /* 8 Bytes */

   ismd_point_t            dest_origin;   /**< Pixel position for the
                                               destination of the frame.*/
                                               /* 8 Bytes */

   /////////////////////////////////////////////////////////////////////////////
   // Closed Captions (12 Bytes)
   ismd_608_cc_t           EIA_608_capt[ISMD_608_CC_ARRAY_MAX];
                                          /**< If 608
                                               (line 21) captions are present,
                                               this structure will indicate so.
                                               708 captions are not stored as
                                               frame attributes but are
                                               forwarded directly to the user
                                               space application.

                                               a picture may contain cc data for
                                               Top Field, Bottom Field and a
                                               Repeated Field.*/
                                               /* 4*ISMD_608_CC_ARRAY_MAX Bytes
                                               */

   /////////////////////////////////////////////////////////////////////////////
   // Frame related information (codec type , frame type , bytes in frame etc)
   //
   // (16 Bytes)
   ismd_codec_type_t       codec_type;    /**< Type of stream (MPEG-2,
                                               MPEG4-2, VC1, or H.264 */
                                               /* 4 Bytes */

   ismd_frame_type_t       frame_type;    /**< Frame types that can be generated
                                               by the decoder . Some frame types
                                               are applicable only for a certain
                                               codec. */
                                               /* 4 Bytes */

   unsigned int            bytes_in_frame; /**< Number of bytes in the frame */
                                               /* 4 Bytes */
   unsigned int            ud_buf_count;  /**< Number of userdata buffers attached 
                                               to this frame */
                                               /* 4 Bytes */
   /////////////////////////////////////////////////////////////////////////////
   // Flags and other 1B fields - to maintain memory alignment
   //
   // (8 Bytes)
   unsigned char           num_pan_scan_windows; /**< number of active pan-scan
                                                      windows */
                                               /* 1 Byte */

   bool                    repeated;      /**< This is a repeated field.
                                               (3:2 pulldown) */
                                               /* 1 Byte */

   bool                    separated_fields;
                                          /**< Flag to indicate if field data is
                                               stored in separate pointers. */
                                               /* 1 Byte */

   bool                    dest_rect_change;
                                          /**< Flag to indicate destination
                                               rectangle change */
                                               /* 1 Byte */

   bool                    discontinuity; /**< If true, this frame is the first
                                               frame after a discontinuity has
                                               been detected.  The decoder must
                                               set this flag if the
                                               corresponding buffer on its
                                               input indicates a
                                               discontinuity. */
                                               /* 1 Byte */

   unsigned char           fmd_cadence_type;
                                          /**< Film Mode Detection result:
                                               Cadence type */
                                               /* 1 Byte */
   unsigned char           fmd_frame_index;
                                          /**< Film Mode Detection result:
                                               frame index */
                                               /* 1 Byte */
   // Transcode (End of Sequence present flag) 
   bool                    end_of_sequence_present;
                                          /**< If true, end of sequence start 
                                               code was detected with the 
                                               frame's corresponding ES 
                                               buffers.*/
                                               /* 1 Byte */
   
   /////////////////////////////////////////////////////////////////////////////
   // video codec info (4 bytes)
   ismd_video_codec_info_t codec_info; /**< video codec specific info - 4 bytes */

   /////////////////////////////////////////////////////////////////////////////
   //@Deprecated: this struct field is Deprecated because it was never being used. //
   char                    orig_field;
                                           /**< value that specifies which field
                                               is original (not altered due to
                                               deinterlacing or scaling) for
                                               use with rate conversion. */
                                               /* 1 Bytes */
   int8_t                  flags;
                                           /**< Can be used by a module to set individual
                                                flags representing the frame Need to
                                                include the flag type ismd_frame_flag_t */
                                                /* 1 Byte */
   /////////////////////////////////////////////////////////////////////////////
   // Debug (20 Bytes)
   unsigned char           debug[20];      /**< General-purpose memory for
                                               debugging.*/
                                               /* 20 Bytes */
} ismd_frame_attributes_t;



/** Defines the type of the extension buffer lookup table */
typedef enum {
   ISMD_EXT_BUFFER_TYPE_INVALID = 0,
   ISMD_EXT_BUFFER_TYPE_FRAME,                    /**< attributes describe a frame extension buffer */
   ISMD_EXT_BUFFER_TYPE_MAX                       /**< count of values in the enum */
} ismd_extension_buffer_type_t;

/** 
* Defines the ID of different extension buffer fields, 
* they are unique across all type of ext buffers.
*/
typedef enum {
   ISMD_EXT_BUFFER_FIELD_ID_INVALID = 0,
   ISMD_EXT_BUFFER_FIELD_ID_PLANE_CSC_ADJ,        /**< Field ID for plane CSC adjustment */
   ISMD_EXT_BUFFER_FIELD_ID_PLANE_IN_CLAMP,       /**< Field ID for plane input clamp */
   ISMD_EXT_BUFFER_FIELD_ID_PLANE_OUT_CLAMP,      /**< Field ID for plane output clamp */
   ISMD_EXT_BUFFER_FIELD_ID_POST_CSC_ADJ,         /**< Field ID for post blend CSC adjustment */
   ISMD_EXT_BUFFER_FIELD_ID_POST_IN_CLAMP,        /**< Field ID for post blend input clamp */
   ISMD_EXT_BUFFER_FIELD_ID_POST_OUT_CLAMP,       /**< Field ID for post blend output clamp */
   ISMD_EXT_BUFFER_FIELD_ID_POST_GAMMA_LUT_1,     /**< Field ID for post blend first gamma LUT */
   ISMD_EXT_BUFFER_FIELD_ID_POST_GAMMA_LUT_2,     /**< Field ID for post blend second gamma LUT */
   ISMD_EXT_BUFFER_FIELD_ID_ACTIVE_REGION,        /**< Field ID for active region information */
   ISMD_EXT_BUFFER_FIELD_ID_MAX
} ismd_ext_buffer_field_id_t;

/** Attributes for extension buffers */
typedef struct {
   ismd_extension_buffer_type_t ext_buf_type;     /**< The type of the extension buffer (indicates what lookup table is populated). 
                                                       This indicates which agent is using this extension buffer,
                                                       such as video, audio, etc. */
   
   union {
      /*
         each member of the union is a struct which is in effect a lookup table for a given type of ext buffer.
         The members of the structs are offsets indicating where their corresponding fields start (or 0 if the 
         Field does not exist.
         Use ext_buf_type to decide which table to read.         
      */
      struct {
         unsigned int plane_csc_adj;              /**< the offset for plane csc adjustment field */
         unsigned int plane_input_clamps;         /**< the offset for plane input clamps field */
         unsigned int plane_output_clamps;        /**< the offset for plane output clamps field */
         unsigned int post_blend_csc_adj;         /**< the offset for post blend csc adjustment field */
         unsigned int post_blend_input_clamps;    /**< the offset for post blend input clamps field */
         unsigned int post_blend_output_clamps;   /**< the offset for post blend output clamps field */
         unsigned int post_blend_gamma_lut_1;     /**< the offset for post blend first gamma LUT field */
         unsigned int post_blend_gamma_lut_2;     /**< the offset for post blend second gamma LUT field */
         unsigned int active_region;              /**< the offset for the active region information field */
      } video;
            
   };
} ismd_ext_buffer_attr_t;



/*
The following macros may be used to ensure "separated_fields" switching is
done correctly on ismd_frame_attributes_t pointers.
*/

#define ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE)    \
   ((FRAME_ATTR)->scanline_stride?                             \
      (FRAME_ATTR)->scanline_stride:                           \
      (((FRAME_ATTR)->polarity != ISMD_POLARITY_FRAME)&&       \
       !(FRAME_ATTR)->separated_fields)?STRIDE*2:STRIDE)

#define ISMD_FRAME_ATTR_IS_PROGRESSIVE(FRAME_ATTR)             \
   ((FRAME_ATTR)->polarity == ISMD_POLARITY_FRAME)
#define ISMD_FRAME_ATTR_IS_INTERLACED(FRAME_ATTR)              \
   (!ISMD_FRAME_ATTR_IS_PROGRESSIVE(FRAME_ATTR))

#define ISMD_FRAME_ATTR_Y(FRAME_ATTR) ((FRAME_ATTR)->y)
#define ISMD_FRAME_ATTR_U(FRAME_ATTR) ((FRAME_ATTR)->u)
#define ISMD_FRAME_ATTR_V(FRAME_ATTR) ((FRAME_ATTR)->v)

#define ISMD_FRAME_ATTR_TOP_Y(FRAME_ATTR) ((FRAME_ATTR)->y)
#define ISMD_FRAME_ATTR_TOP_U(FRAME_ATTR) ((FRAME_ATTR)->u)
#define ISMD_FRAME_ATTR_TOP_V(FRAME_ATTR) ((FRAME_ATTR)->v)

#define ISMD_FRAME_ATTR_BOTTOM_Y(FRAME_ATTR, STRIDE)                          \
(                                                                             \
   (                                                                          \
      (FRAME_ATTR)->polarity == ISMD_POLARITY_FRAME ?                         \
      (FRAME_ATTR)->y+ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE) :   \
      (                                                                       \
         (FRAME_ATTR)->separated_fields?                                      \
         (FRAME_ATTR)->bottom_y :                                             \
         ((FRAME_ATTR)->y+ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE)/2) \
      )                                                                       \
   )                                                                          \
)

#define ISMD_FRAME_ATTR_BOTTOM_U(FRAME_ATTR, STRIDE)                          \
(                                                                             \
   (                                                                          \
      (FRAME_ATTR)->polarity == ISMD_POLARITY_FRAME ?                         \
      (FRAME_ATTR)->u+ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE) :   \
      (                                                                       \
         (FRAME_ATTR)->separated_fields?                                      \
         (FRAME_ATTR)->bottom_u :                                             \
         ((FRAME_ATTR)->u+ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE)/2) \
      )                                                                       \
   )                                                                          \
)

#define ISMD_FRAME_ATTR_BOTTOM_V(FRAME_ATTR, STRIDE)                          \
(                                                                             \
   (                                                                          \
      (FRAME_ATTR)->polarity == ISMD_POLARITY_FRAME ?                         \
      (FRAME_ATTR)->v+ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE) :   \
      (                                                                       \
         (FRAME_ATTR)->separated_fields?                                      \
         (FRAME_ATTR)->bottom_v :                                             \
         ((FRAME_ATTR)->v+ISMD_FRAME_ATTR_SCANLINE_STRIDE(FRAME_ATTR, STRIDE)/2) \
      )                                                                       \
   )                                                                          \
)

/// Demux section filter information which is passed back in the buf_desc->attributes[]
typedef struct {
   unsigned int     stream_id;
   unsigned int     filter_id;             /**< section filter id */
   unsigned long    section_filter_handle;
} ismd_filter_info_t;

// MPEG layer for error reporting
enum eMpegLayer
{
   ML_BLOCK,
   ML_MACROBLOCK,
   ML_SLICE,
   ML_PICTURE,
   ML_GOP,
   ML_SEQUENCE,
   ML_ES,
   ML_PES,
   ML_SECTION,      // PES and sections are actually on a similar layer, but enumerated seperately.
   ML_SYSTEM        // Program or transport
};

/** Use this enum to specify SMD timing mode. */
typedef enum {
   ISMD_TIMING_MODE_INVALID,
   /**Using original timing domain for AV synchronization
    * This means two things:
    * 1. The AV synchronization clock will run in the original timing domain: 
    * The initial clock counter is reset to the first received PCR or PTS, 
    * and the consequent clock counter is adjusted continuously through 
    * incoming original PTS or PCR if necessary. Please note, if there is a 
    * discontinuity in the incoming PCR or PTS, there should also be a 
    * discontinuity in the clock counter correspondingly.
    *
    * 2. The AV synchronization will be done using the original PTS instead of 
    * using the "rebased PTS"(linear PTS or scaled PTS) which is converted using
    * the SMD newsegment framework. This is because the clock also runs in 
    * original time domain in this timing mode.
    */
   ISMD_TIMING_MODE_ORIGINAL,   
   /**This is the default SMD timing mode.
    * This means:
    * 1. AV synchronization Clock's frequency is recovered using PCR information 
    * of the input stream. The input PCR discontinuity will be hided by the clock
    * recovery. That means, the clock counter will increase monotonously and will 
    * NOT reflect PCR discontinuity. The clock counter used for AV synchronization 
    * is also a "rebased" one start from zero at the playback beginning (We call 
    * this clock counter the stream time).
    *
    * 2. PTS used for AV synchronization is also converted ones through the SMD 
    * newsegment framework. That is, before comparison with clock to do AV synchronization,
    * all PTS is converted to linear PTS or scaled PTS in case of trick mode. This is 
    * because the "stream time" (see above) is also a rebased one.
    */
   ISMD_TIMING_MODE_CONVERTED
} ismd_timing_mode_t;


/** Use this enum to specify how data arrives before the first newsegment after startup or flush is handled*/
typedef enum 
{
   /**This is the default SMD newsegment policy.
    * All the buffers before a newsegment tag will be rendered if the renderer is in the PLAY
    * state. 
    *
    * In the PAUSE state, frames before a newsegment tag will be buffered. 
    * Please note, the segment start event may never be generated if the 
    * internal buffer is filled before the newsegment tag comes.
    * (please refer to \ref ismd_vidrend_get_soseg_event() for video renderer and 
    * \ref ismd_audio_notification_t() for audio)
    *
    * This policy is helpful for a faster channel change.
    */
   ISMD_NEWSEGMENT_POLICY_LOOSE,
   /**All the frames before a newsegment tag arrives will be discarded strictly.
    * We are safe on the generation of segment start event in PAUSE state.
    */
   ISMD_NEWSEGMENT_POLICY_STRICT
}ismd_newsegment_policy_t;


/** Power state of the device(s) controlled by a driver.*/
typedef enum
{
   /**Device(s) full on. */
    ISMD_POWER_D0,
   /**Not currently used. */
    ISMD_POWER_D1,
   /**Not currently used. */
    ISMD_POWER_D2,
   /**Device(s) off, driver suspended.*/
    ISMD_POWER_D3
} ismd_power_state_t;

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* __ISMD_GLOBAL_DEFS_H__ */
