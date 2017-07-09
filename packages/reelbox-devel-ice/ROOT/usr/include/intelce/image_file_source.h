/*
Copyright [2008] Intel Corporation

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


#ifndef __PL_IMAGE_FILE_SOURCE_H__
#define __PL_IMAGE_FILE_SOURCE_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "ismd_core.h"

// Using a different type than ISMD handles to catch possible coding errors.
// It's really just an integer though.
typedef void* pl_image_filesource_t; 

#define PL_IMAGE_FILESOURCE_INVALID ((pl_image_filesource_t) -1)

typedef enum {
   PL_IMAGE_FILESOURCE_EM_NONE   = 0,
   PL_IMAGE_FILESOURCE_EM_EOF    = 1 << 0,
   PL_IMAGE_FILESOURCE_EM_ERROR  = 1 << 1
} pl_image_filesource_event_mask_t;


/*
   Enables/disables debug information for the image file source.
      0: errors only
      1: 0+ everything
*/
void pl_image_filesource_set_debug_level(int debug_level);

/*
   Inits image_filesource library
*/
ismd_result_t pl_image_filesource_init(void);

/*
   De-inits image_filesource library
*/
ismd_result_t pl_image_filesource_deinit(void);


/*
   Opens a handle for a image_filesource.  Source will be in the "stop" state.
*/
ismd_result_t pl_image_filesource_open(pl_image_filesource_t           *handle);

/*
   Closes a handle for a image_filesource.  This can be done from any state.
*/
ismd_result_t pl_image_filesource_close(pl_image_filesource_t           handle);

/*
   Set the input port for the image file source to stream data into.  
   This will typically be the input port for the ISMD device that comes 
   next in the pipeline.
   This is automatically set for image file sources that are part of a pipeline.
   This should not be called while the image file source is running, set its 
   state to "stop" first.
   The image file source does not take ownership of the port, and will never
   try to free it.
*/
ismd_result_t pl_image_filesource_set_port(pl_image_filesource_t        handle, 
                                           ismd_port_handle_t           input_port);

/*
   Sets the output port and event to stream data to.
   This is NOT a port from another device.  This is used go give the image file
   source its own port that can then be attached to or connected to from another
   device.  The event must be the event bound to the driver-side of the port
   with a mask of EVENT_ALWAYS.

   If you do not know what this means, don't use this function, you just want
   set_port()

*/
ismd_result_t pl_image_filesource_set_port_with_event(pl_image_filesource_t  handle, 
                                          ismd_port_handle_t     output_port,
                                          ismd_event_t           port_event);

/* 
   Set the state of the image file source.  States include stop (image file 
   source is idle),   paused and playing. Paused and playing are functionally 
   equivalent, the image file source will stream data to its port.
   Attempts to set the image file source to paused or playing while its port 
   handle is invalid, or its file path is invalid are blocked.
   This is most useful when restarting an image file source if it stopped itself
   due to hitting an error.
*/
ismd_result_t pl_image_filesource_set_state(pl_image_filesource_t       handle, 
                                            ismd_dev_state_t            desired_state);

/*
   Returns the state that the image file source is currently in.  This is useful
   for finding out which device triggerd a wait for multiple events, if the
   image_filesource was previously not in the stopped state and is now, then
   this one set the event.
*/
ismd_result_t pl_image_filesource_get_state(pl_image_filesource_t       handle, 
                                            ismd_dev_state_t           *current_state);

/*
   Sets the base path of the files that the image file source will read from.
   The files that the image file source reads from have a file number appended
   to them as follows:
      _yuv.0000, _info.0000, _yuv.0001, _info.0001, etc...
      The _yuv files contain the actual pixel data (in packed YUV frmat) and the
      _info files contain a copy of the ismd buffer descriptor.
   Canot be set unless the image file source is in the stopped state.
   This will fail if the opening of the first file fails.
*/
ismd_result_t pl_image_filesource_set_path(pl_image_filesource_t        handle, 
                                     char                              *input_file_path,
                                     int                                path_length);

/*
   Registers an event to set when an event specified in the mask occurs.
   Supported events are specified in pl_image_filesource_event_mask_t;
   This can be done in any state.
   The image file source does not take ownership of the event, and will never
   try to free it.
*/
ismd_result_t pl_image_filesource_register_event(pl_image_filesource_t             handle, 
                                                 ismd_event_t                      ismd_event, 
                                                 pl_image_filesource_event_mask_t  mask);
/*
   Inserts an arbitrary buffer to the image file source's port.
   This is useful for sending EOS or new segment messages.
   This can be done in any state, but the image file source must have a valid
   port. If this is done when the port is full, the operation will fail.  
   The image file source takes ownership of this buffer.
*/
ismd_result_t pl_image_filesource_insert_buffer(pl_image_filesource_t        handle, 
                                                ismd_buffer_handle_t         ismd_buffer);


/*
   Enables looping mode on a image_filesource.
   In looping mode, EOF never happens, the image_filesource will loop back
   to the starting file pair when one of the files does not exist.
   This can be done in any state.
*/
ismd_result_t pl_image_filesource_set_looping(pl_image_filesource_t     handle,
                                              bool                      looping);

/*
   Gets the file extension(number) of the most recently completed read file.
   This can be done in any state.
*/
ismd_result_t pl_image_filesource_get_position(pl_image_filesource_t    handle,
                                               int64_t                 *position);

/*
   Enables PTS interpolation for the frames.  This overwrites any PTSes in the
   image descriptor "info" files.
*/
ismd_result_t pl_image_filesource_set_pts_interpolation(pl_image_filesource_t     handle,
                                                        bool                      enable_interpolation,
                                                        ismd_pts_t                starting_pts,
                                                        ismd_pts_t                pts_increment);

/*
   Gets PTS interpolation values.
*/
ismd_result_t pl_image_filesource_get_pts_interpolation(pl_image_filesource_t     handle,
                                                        bool                     *interpolation_enabled,
                                                        ismd_pts_t               *curr_pts,
                                                        ismd_pts_t               *pts_increment);


#endif //__PL_IMAGE_FILE_SOURCE_H__
