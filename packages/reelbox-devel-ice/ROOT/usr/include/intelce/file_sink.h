/*
Copyright [2008-2010] Intel Corporation

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


#ifndef __PL_FILE_SINK_H__
#define __PL_FILE_SINK_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "ismd_core.h"

// Using a different type than ISMD handles to catch possible coding errors.
// It's really just an integer though.
typedef void* pl_filesink_t;

#define PL_FILESINK_INVALID ((pl_filesink_t) -1)

typedef enum {
   PL_FILESINK_EM_NONE   = 0,
   PL_FILESINK_EM_EOS    = 1 << 0,
   PL_FILESINK_EM_EOD    = 1 << 1,
   PL_FILESINK_EM_ERROR  = 1 << 2
} pl_filesink_event_mask_t;

typedef enum {
   PL_FILESINK_SEEK_SET = 0,
   PL_FILESINK_SEEK_CUR = 1,
   PL_FILESINK_SEEK_END = 2,
} pl_filesink_seek_position_t;

/*
   Enables/disables debug information for the file sink.
      0: errors only
      1: 0+ everything
*/
void pl_filesink_set_debug_level(int debug_level);

/*
   Inits filesink library
*/
ismd_result_t pl_filesink_init(void);

/*
   De-inits filesink library
*/
ismd_result_t pl_filesink_deinit(void);


/*
   Opens a handle for a filesink.  Sink will be in the "stop" state.
*/
ismd_result_t pl_filesink_open(pl_filesink_t             *handle);

/*
   Flush a handle for a filesink.  This can be done from any state.
*/
ismd_result_t pl_filesink_flush(pl_filesink_t             handle);

/*
   Closes a handle for a filesink.  This can be done from any state.
*/
ismd_result_t pl_filesink_close(pl_filesink_t             handle);

/*
   Set the output port for the file sink to stream data from.
   This will typically be the output port for ISMD devices that comes
   before in the pipeline.
   This is automatically set for file sinks that are part of a pipeline.
   This should not be called while the file sink is running, set its
   state to "stop" first.
   The file sink does not take ownership of the port, and will never
   try to free it.
*/
ismd_result_t pl_filesink_set_port(pl_filesink_t          handle,
                                   ismd_port_handle_t     output_port);


/*
   Sets the output port and event to stream data from.
   This is NOT a port from another device.  This is used go give the file
   sink its own port that can then be attached to or connected to from another
   device.  The event must be the event bound to the driver-side of the port
   with a mask of EVENT_ALWAYS.

   If you do not know what this means, don't use this function, you just want
   set_port()

*/
ismd_result_t pl_filesink_set_port_with_event(pl_filesink_t          handle,
                                          ismd_port_handle_t     output_port,
                                          ismd_event_t     port_event);

/*
   Set the state of the file sink.  States include stop (filesink is idle),
   paused (filesink is stil idle) and playing (filesink is saving data).
   Attempts to set the file sink to paused or playing while its port handle is
   invalid, or its file path is invalid are blocked.
   This is most useful when restarting a file sink if it stopped itself due to
   hitting an error.
*/
ismd_result_t pl_filesink_set_state(pl_filesink_t         handle,
                                    ismd_dev_state_t      desired_state);

/*
   Returns the state that the file sink is currently in.  This is useful for
   finding out which device trigger a wait for multiple events, if the
   filesink was previously not in the stopped state and is now, then this one
   set the event.
*/
ismd_result_t pl_filesink_get_state(pl_filesink_t         handle,
                                    ismd_dev_state_t     *current_state);

/*
   Sets the path of the file that the file sink will write to.
   Canot be set unless the file sink is in the stopped state.
   This will fail if the opening of the file fails.
   If path is set to NO_WRITE then no data will be written.
*/
ismd_result_t pl_filesink_set_path(pl_filesink_t          handle,
                                   char                  *output_file_path,
                                   int                    path_length);

/*
   Registers an event to set when an event specified in the mask occurs.
   Supported events are specified in pl_filesink_event_mask_t;
   This can be done in any state.
   The file sink does not take ownership of the event, and will never
   try to free it.
*/
ismd_result_t pl_filesink_register_event(pl_filesink_t             handle,
                                         ismd_event_t              ismd_event,
                                         pl_filesink_event_mask_t  mask);



/*
   Gets the file position of the most recently completed write operation.
   Is reported as 0 if no data has been written to the current file yet.
   This can be done in any state.
*/
ismd_result_t pl_filesink_get_position(pl_filesink_t    handle,
                                       int64_t           *position);

/*
   Sets the file offset relative to the start/cur/end of file position. refer to C API 
   fseek(...) for details.  call this API after pl_filesink_set_path().
*/
ismd_result_t pl_filesink_set_position(pl_filesink_t    handle,
                                       int64_t          offset,
                                       pl_filesink_seek_position_t seek_pos);


/*
  Determines if the filesink should move to the 'stop' state when the
  EOS tag is detected in the data stream.
  This does not affect the generation of the EOS event.
  This can be done in any state.
*/
ismd_result_t pl_filesink_set_stop_on_eos(pl_filesink_t      handle,
                                              bool stop_on_eos);


/*
  Enables "triggering" on the file writing from a file sink.
  Buffers encountered before an original PTS exactly matches start_pts are
  not written.
  Once a PTS exactly matches the start_pts, the filesink starts writing the
  buffers to the file, including the buffer with the matching PTS.
  This is called the "capturing" state.
  If capturing, once a PTS exactly matches the end_pts, the filesink
  stops writing the buffers to the file.
  The buffer with the end PTS is also written.
  An exact match on the end PTS has no effect when not capturing.
  NOTE: this is a one-shot capture, once the capture end has been triggered
  the trigger is not ever started again, unless the trigger is set again by
  calling this function or the filesink is set into continuous capture mode
  by calling pl_filesink_disable_pts_triggering.
*/
ismd_result_t pl_filesink_enable_pts_triggering(pl_filesink_t      handle,
                                                ismd_pts_t         start_pts,
                                                ismd_pts_t         end_pts);

/*
  Disables "triggering" on the file writing from a file sink.
  This is the default state, where all buffers are written.
  If triggering is disabled during a triggered capture, the
  filesink will simply keep capturing and not stop, even when the end
  trigger is encountered.
*/
ismd_result_t pl_filesink_disable_pts_triggering(pl_filesink_t      handle);

/*
  write 'size' bytes into file under current file offset position. Content
  comes from memory address 'ptr'. This API works with pl_filesink_set_position.
  only be available after calling pl_filesink_set_path().
  return actual bytes written into file. -1 for error.
  
*/
long pl_filesink_direct_write(pl_filesink_t   handle, 
                                 const void* ptr,
                                 long size);


#endif //__PL_FILE_SINK_H__
