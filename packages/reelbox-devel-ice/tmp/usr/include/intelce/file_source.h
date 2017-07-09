/*
Copyright [2008-2009] Intel Corporation

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#ifndef __PL_FILE_SOURCE_H__
#define __PL_FILE_SOURCE_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "ismd_core.h"
#include "ismd_demux.h" // for container types


// Using a different type than ISMD handles to catch possible coding errors.
// It's really just an integer though.
typedef void* pl_filesource_t;

#define PL_FILESOURCE_INVALID ((pl_filesource_t) -1)

typedef enum {
   PL_FILESOURCE_EM_NONE   = 0,
   PL_FILESOURCE_EM_EOF    = 1 << 0,
   PL_FILESOURCE_EM_ERROR  = 1 << 1
} pl_filesource_event_mask_t;


// The filesource can operate in "smart" mode.
// In this mode, the filesource can feed specific chunks
// of the input in forward or reverse order.
// This is useful for sending every other gop, sending I frames only,
// or emulating other advanced trick-mode scenarios.
// The following structures describe the controls for enabling this.
typedef enum {
   FORWARD,
   REVERSE
} filesource_direction_t;

typedef enum {
   BYTES,
   GOPS,
   I_FRAMES,
   PATS
} filesource_unit_type_t;

typedef enum {
   TS = ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM,
   TS192 = ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM_192,
   PS = ISMD_DEMUX_STREAM_TYPE_DVD_PROGRAM_STREAM,
   UNSPECIFIED = 9999
} filesource_container_type_t;

typedef struct {
   filesource_direction_t        direction;
   filesource_unit_type_t        unit_type;
   unsigned                      unit_size;     // Only used when unit_type == BYTES
   unsigned                      mod_counter;   // Specifies every nth chunk
   filesource_container_type_t   container_type;
   ismd_codec_type_t             vid_alg;
   unsigned                      vid_pid;       // PID or stream ID
   unsigned                      pat_pid;       // Used when seeking based on PAT
} filesource_smart_mode_t;



/*
   Enables/disables debug information for the file source.
      0: errors only
      1: 0+ everything
*/
void pl_filesource_set_debug_level(int debug_level);

int  pl_filesource_get_debug_level(void);

/*
   Inits filesource library
*/
ismd_result_t pl_filesource_init(void);

/*
   De-inits filesource library
*/
ismd_result_t pl_filesource_deinit(void);


/*
   Opens a handle for a filesource.  Source will be in the "stop" state.
*/
ismd_result_t pl_filesource_open(pl_filesource_t           *handle);

/*
   Closes a handle for a filesource.  This can be done from any state.
*/
ismd_result_t pl_filesource_close(pl_filesource_t           handle);

/*
   Set the input port for the file source to stream data into.
   This will typically be the input port for ISMD devices that comes
   next in the pipeline.
   This is automatically set for file sources that are part of a pipeline.
   This should not be called while the file source is running, set its
   state to "stop" first.
   The file source does not take ownership of the port, and will never
   try to free it.
*/
ismd_result_t pl_filesource_set_port(pl_filesource_t        handle,
                                     ismd_port_handle_t     input_port);


/*
   Sets the output port and event to stream data to.
   This is NOT a port from another device.  This is used go give the file
   source its own port that can then be attached to or connected to from another
   device.  The event must be the event bound to the driver-side of the port
   with a mask of EVENT_ALWAYS.

   If you do not know what this means, don't use this function, you just want
   set_port()

*/
ismd_result_t pl_filesource_set_port_with_event(pl_filesource_t  handle,
                                          ismd_port_handle_t     output_port,
                                          ismd_event_t           port_event);


/*
   Set the state of the file source.  States include stop (file source is idle),
   paused and playing. Paused and playing are functionally equivalent, the
   source will stream data to its port.
   Attempts to set the file source to paused or playing while its port handle is
   invalid, or its file path is invalid are blocked.
   This is most useful when restarting a file source if it stopped itself due to
   hitting EOF.
*/
ismd_result_t pl_filesource_set_state(pl_filesource_t       handle,
                                      ismd_dev_state_t      desired_state);

/*
   Returns the state that the file source is currently in.  This is useful fot
   finding out which device trigger a wait for multiple events, if the
   filesource was previously not in the stopped state and is now, then this one
   set the event.
*/
ismd_result_t pl_filesource_get_state(pl_filesource_t       handle,
                                      ismd_dev_state_t     *current_state);

/*
   Sets the path of the file that the file source will read from.
   Canot be set unless the file source is in the stopped state.
   This will fail if the opening of the file fails.
*/
ismd_result_t pl_filesource_set_path(pl_filesource_t        handle,
                                     char                  *input_file_path,
                                     int                    path_length);

/*
   Registers an event to set when an event specified  in the mask occurs.
   Supported events are specified in pl_filesource_event_mask_t;
   This can be done in any state.
   The file source does not take ownership of the event, and will never
   try to free it.
*/
ismd_result_t pl_filesource_register_event(pl_filesource_t             handle,
                                           ismd_event_t                ismd_event,
                                           pl_filesource_event_mask_t  mask);

/*
   Inserts an arbitrary buffer to the file source's port.
   This is useful for sending EOS or new segment messages.
   This can be done in any state, but the file source must have a valid port.
   If this is done when the port is full, the operation will fail.
   The file source takes ownership of this buffer.
*/
ismd_result_t pl_filesource_insert_buffer(pl_filesource_t              handle,
                                          ismd_buffer_handle_t         ismd_buffer);

/*
   Sets the size of the data chunks that the filesource writes to the port.
   Note that there must be ISMD buffers of this size in the system.
   The default is 32k
   This can be called in any state.
*/
ismd_result_t pl_filesource_set_chunk_size(pl_filesource_t             handle,
                                           size_t                      size);


/*
   Sets the filesource fread to do 8bit endiend byte swaping.
   Note: Byte swaping is required for some AC3 and EC3 files
   The default is false - no byte swap
   This can be called in any state.
*/
ismd_result_t pl_filesource_set_byte_swap(pl_filesource_t             handle,
                                          bool                        do_byte_swap);


/*
   Enables looping mode on a filesource.
   In looping mode, EOF never happens, the filesource will loop back
   to the starting point when it gets to the end of the file or the end point.
   This can be done in any state.
*/
ismd_result_t pl_filesource_set_looping(pl_filesource_t     handle,
                                        bool                looping);

/*
   Controls whether or not an EOS tag is generated on the EOF condition.
*/
ismd_result_t pl_filesource_enable_eos (pl_filesource_t     handle,
                                        bool                enable);

/*
   Gets the file position of the most recently completed read operation.
   Is reported as 0 if no data has been read from the current file yet.
   This can be done in any state.
*/
ismd_result_t pl_filesource_get_position(pl_filesource_t    handle,
                                         int64_t           *position);

/*
   Sets the file position of the next read operation.
   This will fail if the point set is past the end point.
   This can be done in any state, but cannot be done before the path
   is set.
*/
ismd_result_t pl_filesource_set_position(pl_filesource_t    handle,
                                         int64_t            position);


/*
   An end point other than the end of the file can be set using this API.
   If this is set to 3, bytes 0-2 will be read.
   This can be done in any state, but cannot be done before the path
   is set.  This cannot be set to be beyond the end point, or before any
   specifically set start point for the file.
   When a new path is set, this gets reset to the size of that file.
*/
ismd_result_t pl_filesource_set_end_point(pl_filesource_t              handle,
                                          int64_t                      end_point);

/*
   A start point other than the beginning of the file can be set using this
   API.  This is useful for looping a sub-clip or playing a short segment.
   If this is set to 3, byte 3 is the first byte that gets read.
   This can be done in any state, but cannot be done before the path
   is set.  This cannot be set to be beyond the end of the file, or beyond
   any other set end point.
   When a new path is set, this gets reset to the start of that file.
*/
ismd_result_t pl_filesource_set_start_point(pl_filesource_t            handle,
                                            int64_t                    start_point);

/*
   Gets the start and end points of the clip.  These are either 0 and
   file_length or other values that were set.
*/
ismd_result_t pl_filesource_get_clip_size(pl_filesource_t              handle,
                                          int64_t                     *start_point,
                                          int64_t                     *end_point);

/*
   Enables the smart mode.  Useful for advanced trick mode sourcing.
*/
ismd_result_t pl_filesource_enable_smart_mode(pl_filesource_t              handle,
                                              filesource_smart_mode_t      mode);

/*
   Disables smart mode.  Useful for returning to contiguous playback.
*/
ismd_result_t pl_filesource_disable_smart_mode(pl_filesource_t handle);

/*
   Detects if the media is TS188, TS192, or DVD PS.
*/
ismd_result_t pl_filesource_detect_media_type(pl_filesource_t handle,
                                              filesource_container_type_t *container_type,
                                              uint8_t *vid_sid,
                                              uint8_t *aud_sid, uint8_t *aud_ssid);
/*
   Seeks to the specified PTS value in the content, if it is possible to do so.
*/
ismd_result_t pl_filesource_seek_to_pts(pl_filesource_t handle,
                                        filesource_container_type_t container_type,
                                        unsigned video_pid_sid,
                                        int64_t pts);

/**
   Enable / Disable a simulation of push mode.   Causes the transfer unit to
   OS_SLEEP between input of chunk sizes.
*/
ismd_result_t pl_filesource_set_sim_push_mode(pl_filesource_t  handle,
                                              unsigned int     bitrate);
#endif //__PL_FILE_SOURCE_H__
