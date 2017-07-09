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


/*
The PSI handler wraps the PSI parser.  It abstracts the process of
creating demux filters, adding section filters to them, and listening
for PAT/PMT sections.
The basic idea is that clients initialize this with a demux handle and
two PSI events (a PAT event and a PMT event), and then wait for events
to indicate when the requested tables are ready.
At initialization, the demux handle is used to create PSI filters and
a PSI listening thread.  Once the PAT is received from PID 0 filters
will be created to read the PMT data.
When the application wants to read a PAT or PMT table, it generally
first requests either the PAT or a specified PMT (there can be multiple 
PMTs if using an MPTS).  If the table has 
already been parsed, the corresponding event will be set and the
application can call a separate function to read the data.  The PAT and
PMT events are also set if a change is detected in the PAT or the
most recently requested PMT.

A typical programming sequence is:
   * Instantiate a demux and PSI events
   * initialize the PSI parser with the demux handle and the events
   * request a notification for the PAT
   * Start the demux and start writing a transport stream into its input port
   * wait for the PAT event, once received request a notification for the
     desired program's PMT
   * wait for the PMT event, once received set up the rest of the pipe
   * If the PAT or PMT event is triggered after this, it means one of these
     tables has changed.
*/

#ifndef __PSI_HANDLER_H
#define __PSI_HANDLER_H

#include <stdbool.h>
#include <stdlib.h>
#include "osal.h"
#include "ismd_core.h"
#include "ismd_demux.h"
#include "ismd_global_defs.h"
#include "psi_parser.h"


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// This section contains the API for a single-instance PSI handler.
// If multiple instances are needed (multiple demuxs in the same app) then
// Please see the next section
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
Description:
   Initializes the PSI handler.
   If the PSI handler is already initialized, it will 
   automatically deinitialize before the reinitialization.
   
   This will:
      Initialize all data structures
      allocate a PSI filter from the demux, for the PAT
      add a section filter to it
      map pid 0 to it
      create the PSI listening thread
   Once the PAT is received the listener thread will:
      add another filter for each PMT pid, create more section filters, map pids
      The pat event is set when psi_handler_notify_pat() is called and the PAT 
      becomes available, or when the PAT changes later.
      The pmt event is set when psi_handler_notify_pmt() is called and the 
      specified PMT becomes available, or when the specified PMT changes later.
      
Parameters:
   in: demux_handle - demux handle used to create all of the filters, etc...
   in: pat_event - event that is set when the PAT is received
   in: pmt_event - event that is set when the requested PMT is received
   
Return:
   either ISMD_SUCCESS, or an error code forwarded from an error in one of 
   the internal operations described above.
      
 */
ismd_result_t psi_handler_init(ismd_dev_handle_t demux_handle, 
                               ismd_event_t pat_event, 
                               ismd_event_t pmt_event);

/* 
Description:
   Frees all resources allocated in psi_handler_init, 
   including shutting down the listener thread

Return:
   either ISMD_SUCCESS, or an error code forwarded from an error in one of
   the internal operations described above.
   If this fails, there may be unreclaimed resources, 
   but the system will probably continue to work.
*/
ismd_result_t psi_handler_deinit(void);


/*
Description:
   Triggers the PSI handler to set the PAT event when the first 
   PAT is parsed (will set the event immediately if the PAT has 
   already been parsed by the time this function got called)

Return:
   This should always return ISMD_SUCCESS
 */
ismd_result_t psi_handler_notify_pat(void);

/*
Description:
   Reads the PAT, if one has been parsed.  

Parameters:
   out: pat_data - return pointer to copy the PAT structure

Return:
   ISMD_ERROR_INVALID_REQUEST if the PAT has not yet been received, 
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_get_pat(pat_data_t *pat_data);

/*
Description:
   Triggers the PSI handler to set the PMT event when the first 
   PMT for the specified program is parsed (will set the 
   event immediately if the PMT has already been parsed by the 
   time this function got called).

   This will change the internal "primary program" number.
   This number is used to set the pmt event when the first PMT
   for this program is received, and to set when the PMT for this
   program changes.  In this way, it is only possible to listen
   for changes to one program at a time.

Parameters:
   in: program_num - program to wait for.
       The program number is the index of the program in the PAT.

Return:
   ISMD_ERROR_INVALID_REQUEST if the PAT has not yet been received
   ISMD_ERROR_INVALID_PARAMETER if program_num is greater than the
   number of programs in the stream as indicated by the PAT
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_notify_pmt(unsigned program_num);

/*
Description:
   Reads the PMT for the specified program, if one has been parsed.
   
   This will change the internal "primary program" number.
   This number is used to set the pmt event when the first PMT
   for this program is received, and to set when the PMT for this
   program changes.  In this way, it is only possible to listen

Parameters:
   in: program_num - program to read the PMT for
       The program number is the index of the program in the PAT.
   out: pmt_data - return pointer to copy the PMT structure

Return:
   ISMD_ERROR_INVALID_REQUEST if the PAT or specified PMT have not yet
   been received
   ISMD_ERROR_INVALID_PARAMETER if program_num is greater than the
   number of programs in the stream as indicated by the PAT
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_get_pmt(unsigned program_num, pmt_data_t *pmt_data);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// This section contains the API for the multi-instance PSI handler.
// This allows for PSI parsing when there are moltiple demux handles
// in a single application
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

typedef int psi_handler_t;
#define PSI_HANDLER_INVALID_INSTANCE -1

/*
Description: Global initialization needed to be called before doing any
   multi-instance PSI calls.  This initializations the locking infrastructure
   and instance allocator.
   
Return:
   ISMD_SUCCESS if no problems were encountered
*/
ismd_result_t psi_handler_mi_init(void);

/*
Description: Global de initialization of the multi-instance PSI handler.
   Any multi-instance resources (including open instances) in use will be 
   freed if this is called.
   
Return:
   ISMD_SUCCESS if no problems were encountered
*/
ismd_result_t psi_handler_mi_deinit(void);

/*
Description: Multi-instance version of psi_handler_init()
   See the description for that function.  The handle initialized by this
   function can be used for subsequent PSI parsing operations

Parameters:
   in: demux_handle - demux handle used to create all of the filters, etc...
   in: pat_event - event that is set when the PAT is received
   in: pmt_event - event that is set when the requested PMT is received
   out: instance - handle to be used in subsequent multi-instance PSI handler calls
   
Return:
   ISMD_SUCCESS if no problems were encountered.
   ISMD_ERROR_NO_RESOURCES if all PSI instances are in use
   Any error code returned by an internal operation
*/
ismd_result_t psi_handler_mi_open(ismd_dev_handle_t demux_handle, 
                                  ismd_event_t pat_event, 
                                  ismd_event_t pmt_event,
                                  psi_handler_t *instance);

/* 
Description:
   Frees all resources allocated in psi_handler_mi_open, 
   including shutting down the listener thread

Parameters:
   in: instance - PSI instance to close

Return:
   ISMD_ERROR_INVALID_HANDLE if the instance supplied is not valid or open
   either ISMD_SUCCESS, or an error code forwarded from an error in one of
   the internal operations described above.
   If this fails, there may be unreclaimed resources, 
   but the system will probably continue to work.
*/
ismd_result_t psi_handler_mi_close(psi_handler_t instance);

/*
Description:
   Triggers the PSI handler to set the PAT event when the first 
   PAT is parsed (will set the event immediately if the PAT has 
   already been parsed by the time this function got called)

Parameters:
   in: instance - PSI instance to use

Return:
   ISMD_ERROR_INVALID_HANDLE if the instance supplied is not valid or open
   ISMD_SUCCESS otherwise.
 */
ismd_result_t psi_handler_mi_notify_pat(psi_handler_t instance);

/*
Description:
   Reads the PAT, if one has been parsed

Parameters:
   in: instance - PSI instance to use
   out: pat_data - return pointer to copy the PAT structure

Return:
   ISMD_ERROR_INVALID_HANDLE if the instance supplied is not valid or open
   ISMD_ERROR_INVALID_REQUEST if the PAT has not yet been received, 
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_mi_get_pat(psi_handler_t instance,
                                     pat_data_t *pat_data);

/*
Description:
   Triggers the PSI handler to set the PMT event when the first 
   PMT for the specified program is parsed (will set the 
   event immediately if the PMT has already been parsed by the 
   time this function got called).

   This will change the internal "primary program" number.
   This number is used to set the pmt event when the first PMT
   for this program is received, and to set when the PMT for this
   program changes.  In this way, it is only possible to listen
   for changes to one program at a time.

Parameters:
   in: instance - PSI instance to use
   in: program_num - program to wait for
       The program number is the index of the program in the PAT.

Return:
   ISMD_ERROR_INVALID_HANDLE if the instance supplied is not valid or open
   ISMD_ERROR_INVALID_REQUEST if the PAT has not yet been received
   ISMD_ERROR_INVALID_PARAMETER if program_num is greater than the
   number of programs in the stream as indicated by the PAT
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_mi_notify_pmt(psi_handler_t instance,
                                        unsigned program_num);

/*
Description:
   Reads the PMT for the specified program , if one has been parsed.
   
   This will change the internal "primary program" number.
   This number is used to set the pmt event when the first PMT
   for this program is received, and to set when the PMT for this
   program changes.  In this way, it is only possible to listen

Parameters:
   in: instance - PSI instance to use
   in: program_num - program to read the PMT for
       The program number is the index of the program in the PAT.
   out: pmt_data - return pointer to copy the PMT structure

Return:
   ISMD_ERROR_INVALID_HANDLE if the instance supplied is not valid or open
   ISMD_ERROR_INVALID_REQUEST if the PAT or specified PMT have not yet
   been received
   ISMD_ERROR_INVALID_PARAMETER if program_num is greater than the
   number of programs in the stream as indicated by the PAT
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_mi_get_pmt(psi_handler_t instance,
                                     unsigned program_num, 
                                     pmt_data_t *pmt_data);

/*
Description:
   Obtains a list of all PIDs currently being used for PSI parsing.
   
   This includes the PAT PID (0), and the PMT PID.

Parameters:
   in: instance - PSI instance to use
   out: pid_list - array of PIDs to populate with the current PIDs in use
   out: list_size - number of elements that were populated with PIDs

Return:
   ISMD_ERROR_INVALID_HANDLE if the instance supplied is not valid or open
   ISMD_ERROR_INVALID_PARAMETER if pid_list or list_size is NULL
   ISMD_SUCCESS otherwise
 */
ismd_result_t psi_handler_mi_get_current_psi_pids(
                                     psi_handler_t instance,
                                     ismd_demux_pid_list_t *pid_list,
                                     unsigned *list_size);

#endif
