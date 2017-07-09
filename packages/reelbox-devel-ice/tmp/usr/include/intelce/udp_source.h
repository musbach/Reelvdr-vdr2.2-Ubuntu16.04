/*
Copyright [2009] Intel Corporation

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


#ifndef __PL_UDP_SOURCE_H__
#define __PL_UDP_SOURCE_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "ismd_core.h"
#include "ismd_clock_recovery.h"

// Using a different type than ISMD handles to catch possible coding errors.
// It's really just an integer though.
typedef void* pl_udpsource_t;

#define PL_UDPSOURCE_INVALID ((pl_udpsource_t) -1)

typedef enum {
   PL_UDPSOURCE_EM_NONE    = 0,
   PL_UDPSOURCE_EM_OVERRUN = 1 << 0,
   PL_UDPSOURCE_EM_ERROR   = 1 << 1
} pl_udpsource_event_mask_t;


/*
   Enables/disables debug information for the UDP source.
      0: errors only
      1: 0+ everything
*/
void pl_udpsource_set_debug_level(int debug_level);

/*
   Inits udpsource library
*/
ismd_result_t pl_udpsource_init(void);

/*
   De-inits udpsource library
*/
ismd_result_t pl_udpsource_deinit(void);


/*
   Opens a handle for a udpsource.  Source will be in the "stop" state.
*/
ismd_result_t pl_udpsource_open(pl_udpsource_t           *handle);

/*
   Closes a handle for a udpsource.  This can be done from any state.
*/
ismd_result_t pl_udpsource_close(pl_udpsource_t           handle);

/*
   Set the input port for the UDP source to stream data into.
   This will typically be the input port for the ISMD device that comes
   next in the pipeline.
   This is automatically set for UDP sources that are part of a pipeline.
   This should not be called while the UDP source is running, set its
   state to "stop" first.
   The UDP source does not take ownership of the port, and will never
   try to free it.
*/
ismd_result_t pl_udpsource_set_port(pl_udpsource_t        handle,
                                    ismd_port_handle_t    input_port);

/*
   Sets the input port and event to stream data to.
   This is NOT a port from another device.  This is used go give the UDP
   source its own port that can then be attached to or connected to from another
   device.  The event must be the event bound to the driver-side of the port
   with a mask of EVENT_ALWAYS.

   If you do not know what this means, don't use this function, you just want
   set_port()

*/
ismd_result_t pl_udpsource_set_port_with_event(pl_udpsource_t    handle,
                                          ismd_port_handle_t     output_port,
                                          ismd_event_t           port_event);

/*
   Sets the size of the data chunks that the udpsource writes to the port.
   Note that there must be ISMD buffers of this size in the system.
   The default is 32k
   This can be called in any state.
*/
ismd_result_t pl_udpsource_set_chunk_size(pl_udpsource_t             handle,
                                          size_t                     size);

/*
   Set the state of the UDP source.  States include stop (UDP
   source is idle),   paused and playing. Paused and playing are functionally
   equivalent, the UDP source will stream data to its port.
   Attempts to set the UDP source to paused or playing while its port
   handle is invalid, or its UDP path is not set are blocked.
   This is most useful when restarting an UDP source if it stopped itself
   due to hitting an error.
*/
ismd_result_t pl_udpsource_set_state(pl_udpsource_t       handle,
                                     ismd_dev_state_t     desired_state);

/*
   Returns the state that the UDP source is currently in.  This is useful
   for finding out which device triggerd a wait for multiple events, if the
   udpsource was previously not in the stopped state and is now, then
   this one set the event.
*/
ismd_result_t pl_udpsource_get_state(pl_udpsource_t       handle,
                                     ismd_dev_state_t    *current_state);

/*
   Sets the UDP address to stream from.  This includes the port.  It is a
   string in the format
   <num>.<num>.<num>.<num>:<port>

   Example: "123.123.123.123:1234"
   Example: "23.23.23.23:1234"

   Note: the string should be NULL-terminated
*/
ismd_result_t pl_udpsource_set_path(pl_udpsource_t        handle,
                                    char                 *udp_addr);

/*
   Registers an event to set when an event specified in the mask occurs.
   Supported events are specified in pl_udpsource_event_mask_t;
   This can be done in any state.
   The UDP source does not take ownership of the event, and will never
   try to free it.
*/
ismd_result_t pl_udpsource_register_event(pl_udpsource_t             handle,
                                          ismd_event_t               ismd_event,
                                          pl_udpsource_event_mask_t  mask);
/*
   Inserts an arbitrary buffer to the UDP source's port.
   This is useful for inserting EOS or new segment messages.
   This can be done in any state, but the UDP source must have a valid
   port. If this is done when the port is full, the operation will fail.
   The UDP source takes ownership of this buffer.
*/
ismd_result_t pl_udpsource_insert_buffer(pl_udpsource_t        handle,
                                         ismd_buffer_handle_t  ismd_buffer);

/*
   If the UDP source is processing transport stream data, it can optionally
   perform clock recovery using the PCR values in the stream.

   data parsing and clock recovery will not be attempted unless the PCR PID
   is set.

   Setting the PCR PID to 8191 or greater disables data parsing and clock
   recovery.

   The PCR PID can be set in any state.
*/
ismd_result_t pl_udpsource_set_pcr_pid(pl_udpsource_t        handle,
                                       uint16_t              pcr_pid);

/*
   Sets the clock to use for clock recovery.  Clock recovery is not attempted
   unless this as well as a valid PCR PID are set.

   Setting this to ISMD_CLOCK_HANDLE_INVALID disables clock recovery.

   The clock can be set in any state.
*/
ismd_result_t pl_udpsource_set_clock(pl_udpsource_t        handle,
                                     ismd_clock_t          clock);

/*
   Get a handle to the clock sync instance that the UDP source is using
   to do clock recovery.  This will only return a valid handle if the
   UDP source has been assigned a valid clock with pl_udpsource_set_clock();
*/
ismd_result_t pl_udpsource_get_clock_sync(pl_udpsource_t        handle,
                                          clock_sync_t          *clock_sync);



#endif //__PL_UDP_SOURCE_H__
