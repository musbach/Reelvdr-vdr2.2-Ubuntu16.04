/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2009-2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2009-2010 Intel Corporation. All rights reserved.
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
 * comprise the the MVC Remux APIs.
 */
#include "ismd_core.h"
#include "ismd_global_defs.h"
#include "osal.h"

#ifndef __ISMD_REMUX_H__
#define __ISMD_REMUX_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @weakgroup ismd_remux MVC Remux */

/**
@brief <H3></H3>
   Defines maximum number of MVC remux instances supported
*/

#define REMUX_MAX_NUM_INSTANCES 1

/**
@brief <H3></H3>
   Defines maximum number of MVC views/input ports supported per remux instance
*/

#define REMUX_MAX_NUM_VIEWS_INSTANCE 2


/** Info associated with the view */
typedef struct {
   ismd_port_handle_t port;
   unsigned int       view_id;
}ismd_remux_view_info_t;

/** Events that can be registered by the application */
typedef enum
{
    REMUX_EVENT_EOS = 0x1, /**< End of File/Stream event Notification */

}ismd_remux_event_type_t;


/** MVC Remux frame drop policies */
typedef enum {

  /** REMUX_DEP_IN_FULL_POLICY_DONT_DROP : No drop policy.  This is recommended in the case
  where the sources to the remux inputs are  independent.  E.g. Two different
  demux's providing independent inputs to the remux inputs */
  REMUX_DEP_IN_FULL_POLICY_DONT_DROP    = 0,

  /** REMUX_DEP_IN_FULL_POLICY_DROP : Drops dependent view frames, when a
  given input dependent view is full and base view is empty (possibly the
  dependent view is blocking the data to base view.  This is recommended in 3D
  m2ts case where there is only one demux with multiple video filters providing
  input to the remux. */
  REMUX_DEP_IN_FULL_POLICY_DROP         = 1,

  /** REMUX_DEP_IN_FULL_POLICY_MAX : Just a flag for internal coding.  */
  REMUX_DEP_IN_FULL_POLICY_MAX          = 2

} ismd_remux_input_drop_policy_t;


/**
Gets a handle to a MVC Remux device if one is available.

@param[in] stream_type : Specifies the data format of the stream to be processed.
@param[out] handle : Pointer to a instance handle ID that will get filled in.
@param[out] output_port : Will be populated with a handle to the output port.
@retval ISMD_SUCCESS : Instance was sucessfully opened and handle was obtained.
@retval ISMD_ERROR_NULL_POINTER : handle was supplied as NULL.
@retval ISMD_ERROR_OPERATION_FAILED : No handles are available or unable to allocate required memory.
*/

ismd_result_t SMDCONNECTION ismd_remux_open(ismd_dev_t *handle,
                                            ismd_port_handle_t *output_port);

/**
Closes the specified MVC Remux instance. All resources allocated
to this particular remux instance are automatically freed.

@param[in] handle : handle to the Remux instance.  The handle should
not be used after this function has been called.

@retval ISMD_SUCCESS : The stream is closed successfully.
@retval ISMD_ERROR_INVALID_HANDLE : handle is not a valid, active Remux handle.
*/

ismd_result_t SMDEXPORT ismd_remux_close(ismd_dev_t handle);


/**
Open and enable an input view for a stream.  Views can be added and removed
ONLY during the (instance) STOP state.

@param[in] handle : Remux stream handle to add the input to.
@param[in] view_id : Specifies the view id of the ES stream associated to this
input port.

Remuxer can only handle ES packets at its input.  So only MVC ES data should be
fed to these inputs.

@param[out] port_handle : handle to a structure holding configuratio
information for the input.

@retval ISMD_SUCCESS : A veiw was successfully added.
@retval ISMD_ERROR_INVALID_HANDLE : Remuxer instance is not a valid Remux handle.
@retval ISMD_ERROR_NO_RESOURCES : No more inputs are available.
@retval ISMD_ERROR_INVALID_REQUEST : if there is already an input present in
the remuxer with is the current view_id.
*/

ismd_result_t SMDEXPORT ismd_remux_add_view(ismd_dev_t handle,
                                            unsigned int view_id,
                                            ismd_remux_view_info_t *view_info);

/**
Close an input view for a remuxer instance.  Views can be added and removed
ONLY during the (instance) STOP state.

@param[in] handle : Remux handle to remove the input from.
@param[in] view_id : Specifies the view id of the ES stream associated to this
input port.

@retval ISMD_SUCCESS : A veiw was successfully removed.
@retval ISMD_ERROR_INVALID_HANDLE : Remuxer instance is not a valid Remux handle.
@retval ISMD_ERROR_INVALID_REQUEST : if there is no such input (view_id)
present/added the remuxer.
*/
ismd_result_t SMDEXPORT ismd_remux_remove_view(ismd_dev_t handle,
                                               unsigned int view_id);

/**

Get the configuration parameters for an remuxer input.

@param[in] handle : Remux stream handle to add the input to.
@param[in] view_id : Specifies the view id of the ES stream associated to this
input port.

Remuxer can only handle PES packets at its input.  So only MVC ES data should be
fed to these inputs.

@param[out] view_info : handle to a structure holding configuration
information for the input.

@retval ISMD_SUCCESS : Requested veiw configuration was successfully retuned.
@retval ISMD_ERROR_INVALID_HANDLE : Remuxer instance is not a valid Remux handle.
@retval ISMD_ERROR_INVALID_REQUEST : if there is no such input (view_id)
present/added the remuxer.
*/
ismd_result_t SMDEXPORT ismd_remux_get_view_info(ismd_dev_t handle,
                                                 unsigned int view_id,
                                                 ismd_remux_view_info_t *view_info);



/**
* @brief <H3>Description:</H3>
* Returns the output port handle.  There is only one output port to remux.
*
* @param[in] handle         : Device handle to MVC Remux instance
* @param[out] output_port   : Handle to output port
*
* @return ismd_result_t       Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Output port handle successfully returned
* @retval ISMD_ERROR_INVALID_HANDLE    : Context handle invalid.
* @retval ISMD_ERROR_INVALID_PARAMETER : Port handle pointer is NULL.
*
* <H3>Algorithm:</H3>
*/
ismd_result_t SMDEXPORT ismd_remux_get_output_port(ismd_dev_t handle,
                                         ismd_port_handle_t *output_port);



/**
* @brief <H3>Description:</H3>
*
* Sets the input frame drop policy on the remux context.  Drop policy cannot be
* changed dynamically.  Remux has to be in STOP state when this API is called.
*
* @param[in] handle         : Device handle to Remux instance
* @param[in] input_drop_policy   : Input Frame drop policy to be set on remux context
*
* @return ismd_result_t       Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Drop policy successfully set
* @retval ISMD_ERROR_INVALID_HANDLE    : Context handle invalid.
* @retval ISMD_ERROR_INVALID_PARAMETER : Drop policy specified is invalid.
* @retval ISMD_ERROR_INVALID_REQUEST   : Remux instance is not in STOP state
*                                        when trying to set the drop policy.
*
* <H3>Algorithm:</H3>
*/
ismd_result_t SMDEXPORT ismd_remux_set_drop_policy(ismd_dev_t handle,
                                                   ismd_remux_input_drop_policy_t input_drop_policy);


/**
* @brief <H3>Description:</H3>
*
* Gets the input frame drop policy on the given context.
*
* @param[in] handle               : Device handle to Remux instance
* @param[out] *input_drop_policy  : Pointer which will hold the currently set drop
* policy on the Remux instance
*
* @return ismd_result_t       Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Drop policy successfully retrieved
* @retval ISMD_ERROR_INVALID_HANDLE    : Context handle invalid.
* @retval ISMD_ERROR_INVALID_PARAMETER : Drop policy handle specified is NULL.
*
* <H3>Algorithm:</H3>
*/
ismd_result_t SMDEXPORT ismd_remux_get_drop_policy(ismd_dev_t handle,
                                                   ismd_remux_input_drop_policy_t *input_drop_policy);



/**
* @brief <H3>Description:</H3>
*
* WARNING: This API is for test purpose only and should not be used by end user
* application.  Remux driver automatically assigns input ports with designed
* port depth when a view is addded.  So this API should not be called from a
* pipeline application.  This is ONLY for INTERNAL test purposes.
* Sets the input port depth of an assigned input view.
*
* @param[in] handle        : Device handle to Remux instance
* @param[in] view_id       : View id of the view for which port_depth needs to
*                            be set
* @param[in] port_depth    : Port depth to be set
*
* @return ismd_result_t       Success / Failure indication.
*
* @retval ISMD_SUCCESS                 : Drop policy successfully set
* @retval ISMD_ERROR_INVALID_HANDLE    : Context handle invalid.
* @retval ISMD_ERROR_INVALID_PARAMETER : view_id specified is invalid .
* @retval ISMD_ERROR_INVALID_REQUEST   : Remux instance is not in STOP state
*                                        when trying to set the port depth.
* @retval ISMD_ERROR_OPERATION_FAILED  : Some other error occured
*
* <H3>Algorithm:</H3>
*/
ismd_result_t SMDEXPORT ismd_remux_set_port_depth(ismd_dev_t handle,
                                                  unsigned int view_id,
                                                  int port_depth);


#ifdef __cplusplus
}
#endif

#endif
