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


#ifndef __PL_IMAGE_MEMORY_SINK_H__
#define __PL_IMAGE_MEMORY_SINK_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "ismd_core.h"
#include "vid_tex_interface.h"

// Using a different type than ISMD handles to catch possible coding errors.
// It's really just an integer though.
typedef void* pl_image_memsink_t; 

#define PL_IMAGE_MEMSINK_INVALID (pl_image_memsink_t) -1;

typedef enum {
   PL_IMAGE_MEMSINK_EM_NONE   = 0,
   PL_IMAGE_MEMSINK_EM_ERROR  = 1 << 1
} pl_image_memsink_event_mask_t;


/*
   Enables/disables debug information for the image memory sink.
      0: errors only
      1: 0+ everything
*/
void pl_image_memsink_set_debug_level(int debug_level);

/*
   Inits image_memsink library
*/
ismd_result_t pl_image_memsink_init(void);

/*
   De-inits image_memsink library
*/
ismd_result_t pl_image_memsink_deinit(void);


/*
   Opens a handle for a image_memsink.  Sink will be in the "stop" state.
*/
ismd_result_t pl_image_memsink_open(pl_image_memsink_t             *handle);

/*
   Closes a handle for a image_memsink.  This can be done from any state.
*/
ismd_result_t pl_image_memsink_close(pl_image_memsink_t             handle);

/*
   Set the output port for the image memsink to stream data from.  
   This will typically be the output port for ISMD devices that comes 
   before in the pipeline.
   This is automatically set for image memory sinks that are part of a pipeline.
   This should not be called while the image memory sink is running, set its 
   state to "stop" first.
   The image memory sink does not take ownership of the port, and will never
   try to free it.
*/
ismd_result_t pl_image_memsink_set_port(pl_image_memsink_t          handle, 
                                         ismd_port_handle_t           output_port);


/*
   Sets the output port and event to stream data from.
   This is NOT a port from another device.  This is used go give the image memory
   sink its own port that can then be attached to or connected to from another
   device.  The event must be the event bound to the driver-side of the port
   with a mask of EVENT_ALWAYS.

   If you do not know what this means, don't use this function, you just want
   set_port()

*/
ismd_result_t pl_image_memsink_set_port_with_event(pl_image_memsink_t handle,
                                          ismd_port_handle_t     output_port,
                                          ismd_event_t     port_event);


/* 
   Set the state of the image memory sink.  States include stop (image_memsink is idle), 
   paused (image_memsink is still idle) and playing (image_memsink is saving data).
   Attempts to set the image memory sink to paused or playing while its port handle is
   invalid, or its file path is invalid are blocked.
   This is most useful when restarting an image memory sink if it stopped itself due to
   hitting an error.
*/
ismd_result_t pl_image_memsink_set_state(pl_image_memsink_t         handle, 
                                    ismd_dev_state_t                  desired_state);

/*
   Returns the state that the image memory sink is currently in.  This is useful for
   finding out which device trigger a wait for multiple events, if the
   image_memsink was previously not in the stopped state and is now, then this one
   set the event.
*/
ismd_result_t pl_image_memsink_get_state(pl_image_memsink_t         handle, 
                                          ismd_dev_state_t           *current_state);

/* 
   Flushes the image memory sink.  If a buffer was held because it was not cleared 
   yet by the client, it will be released on a flush.
   Note that for this to be useful the upstream devices must be stopped and flushed
   first.
   Since the port does not belong to the memsink
*/
ismd_result_t pl_image_memsink_flush(pl_image_memsink_t         handle);

/*
   Sets the the shared memory info needed to send buffers.
   Cannot be set unless the image memory sink is in the stopped state.
   Note that the memory sink does not own this info, and it will
   not close anything related to the shared memory info when it is closed.
   The memory sink simply uses it for update operations.
*/
ismd_result_t pl_image_memsink_set_sharedmem_info(pl_image_memsink_t          handle, 
                                                  vid_tex_interface_t *shared_mem_attrs);

/*
   Registers an event to set when an event specified in the mask occurs.
   Supported events are specified in pl_image_memsink_event_mask_t;
   This can be done in any state.
   The image memory sink does not take ownership of the event, and will never
   try to free it.
*/
ismd_result_t pl_image_memsink_register_event(pl_image_memsink_t             handle, 
                                               ismd_event_t                  ismd_event, 
                                               pl_image_memsink_event_mask_t mask);



#endif //__PL_IMAGE_MEMORY_SINK_H__
