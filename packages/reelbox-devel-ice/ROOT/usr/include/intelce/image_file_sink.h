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

#ifndef __PL_IMAGE_FILE_SINK_H__
#define __PL_IMAGE_FILE_SINK_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "ismd_core.h"

// Using a different type than ISMD handles to catch possible coding errors.
// It's really just an integer though.
typedef void* pl_image_filesink_t;

#define PL_IMAGE_FILESINK_INVALID ((pl_image_filesink_t) -1)

typedef enum {
   PL_IMAGE_FILESINK_EM_NONE   = 0,
   PL_IMAGE_FILESINK_EM_EOS    = 1 << 0,
   PL_IMAGE_FILESINK_EM_ERROR  = 1 << 1
} pl_image_filesink_event_mask_t;


/*
   Enables/disables debug information for the image file sink.
      0: errors only
      1: 0+ everything
*/
void pl_image_filesink_set_debug_level(int debug_level);

/*
   Inits image_filesink library
*/
ismd_result_t pl_image_filesink_init(void);

/*
   De-inits image_filesink library
*/
ismd_result_t pl_image_filesink_deinit(void);


/*
   Opens a handle for a image_filesink.  Sink will be in the "stop" state.
*/
ismd_result_t pl_image_filesink_open(pl_image_filesink_t             *handle);

/*
   Closes a handle for a image_filesink.  This can be done from any state.
*/
ismd_result_t pl_image_filesink_close(pl_image_filesink_t             handle);

/*
   Set the output port for the image filesink to stream data from.
   This will typically be the output port for ISMD devices that comes
   before in the pipeline.
   This is automatically set for image file sinks that are part of a pipeline.
   This should not be called while the image file sink is running, set its
   state to "stop" first.
   The image file sink does not take ownership of the port, and will never
   try to free it.
*/
ismd_result_t pl_image_filesink_set_port(pl_image_filesink_t          handle,
                                         ismd_port_handle_t           output_port);


/*
   Sets the output port and event to stream data from.
   This is NOT a port from another device.  This is used go give the image file
   sink its own port that can then be attached to or connected to from another
   device.  The event must be the event bound to the driver-side of the port
   with a mask of EVENT_ALWAYS.

   If you do not know what this means, don't use this function, you just want
   set_port()

*/
ismd_result_t pl_image_filesink_set_port_with_event(pl_image_filesink_t handle,
                                          ismd_port_handle_t     output_port,
                                          ismd_event_t     port_event);


/*
   Set the state of the image file sink.  States include stop (image_filesink is idle),
   paused (image_filesink is still idle) and playing (image_filesink is saving data).
   Attempts to set the image file sink to paused or playing while its port handle is
   invalid, or its file path is invalid are blocked.
   This is most useful when restarting an image file sink if it stopped itself due to
   hitting an error.
*/
ismd_result_t pl_image_filesink_set_state(pl_image_filesink_t         handle,
                                    ismd_dev_state_t                  desired_state);

/*
   Returns the state that the image file sink is currently in.  This is useful for
   finding out which device trigger a wait for multiple events, if the
   image_filesink was previously not in the stopped state and is now, then this one
   set the event.
*/
ismd_result_t pl_image_filesink_get_state(pl_image_filesink_t         handle,
                                          ismd_dev_state_t           *current_state);

/*
   Sets the path of the file that the image file sink will write to.
   Canot be set unless the image file sink is in the stopped state.
   The files that the image file sink writes to have a file number appended
   to them as follows:
      _yuv.0000, _info.0000, _yuv.0001, _info.0001, etc...
      The _yuv files contain the actual pixel data (in packed YUV frmat) and the
      _info files contain a copy of the ismd buffer descriptor.
   This will fail if the opening of the first file fails.
   If path is set to NO_WRITE then no data will be written.
*/
ismd_result_t pl_image_filesink_set_path(pl_image_filesink_t          handle,
                                         char                        *output_file_path,
                                         int                          path_length);

/*
   Registers an event to set when an event specified in the mask occurs.
   Supported events are specified in pl_image_filesink_event_mask_t;
   This can be done in any state.
   The image file sink does not take ownership of the event, and will never
   try to free it.
*/
ismd_result_t pl_image_filesink_register_event(pl_image_filesink_t             handle,
                                               ismd_event_t                    ismd_event,
                                               pl_image_filesink_event_mask_t  mask);

/*
   Gets the file position of the most recently completed write operation.
   Is reported as 0 if no data has been written to the current file yet.
   This can be done in any state.
*/
ismd_result_t pl_image_filesink_get_position(pl_image_filesink_t    handle,
                                             int64_t               *position);

/*
   Enables or disables the saving of the info files that go along with the
   yuv files.  Can be done in any state.
   By default the sending of into files is enabled.
*/
ismd_result_t pl_image_filesink_disable_info(pl_image_filesink_t    handle,
                                             bool                   enable);


/*
   Enables or disables the saving of the yuv files.
   This is useful for developing tests that just check the info files and
   do not necessarily care about the yuv content.
   Can be done in any state.
   By default the sending of yuv files is enabled.
*/
ismd_result_t pl_image_filesink_disable_yuv(pl_image_filesink_t    handle,
                                            bool                   enable);

/*
  Enables "triggering" on the file writing from an image file sink.
  Buffers encountered before an original PTS exactly matches start_pts are
  not written.
  Once a PTS exactly matches the start_pts, the image filesink starts writing
  the buffers to the file, including the buffer with the matching PTS.
  This is called the "capturing" state.
  If capturing, once a PTS exactly matches the end_pts, the image filesink
  stops writing the buffers to the file.
  The buffer with the end PTS is also written.
  An exact match on the end PTS has no effect when not capturing.
  NOTE: this is a one-shot capture, once the capture end has been triggered
  the trigger is not ever started again, unless the trigger is set again by
  calling this function or the image filesink is set into continuous capture
  mode by calling pl_image_filesink_disable_pts_triggering.
*/
ismd_result_t pl_image_filesink_enable_pts_triggering(pl_image_filesink_t      handle,
                                                      ismd_pts_t               start_pts,
                                                      ismd_pts_t               end_pts);
/*
  Disables "triggering" on the file writing from an image file sink.
  This is the default state, where all buffers are written.
  If triggering is disabled during a triggered capture, the image
  filesink will simply keep capturing and not stop, even when the end
  trigger is encountered.
*/
ismd_result_t pl_image_filesink_disable_pts_triggering(pl_image_filesink_t      handle);

/*
   Tells the mage filesink whether to create a single YUV file with all the data concatenated
   or to create one file for each frame (_yuv.0000, _info.0000, _yuv.0001, _info.0001, etc.).
   Cannot be set unless the image file sink is in the stopped state.
*/
ismd_result_t pl_image_filesink_set_single_yuv_flag(pl_image_filesink_t          handle,
                                         bool                        generate_single_yuv_file);

#endif //__PL_IMAGE_FILE_SINK_H__
