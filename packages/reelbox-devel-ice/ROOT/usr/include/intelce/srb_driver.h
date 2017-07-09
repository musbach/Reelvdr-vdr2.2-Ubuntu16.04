//-----------------------------------------------------------------------------
//  Copyright 2011 Intel Corporation
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//-----------------------------------------------------------------------------
#ifndef _SRB_DRIVER_H_
#define _SRB_DRIVER_H_

#include "srb.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**@defgroup srb_driver SRB Driver Interface 

   @b Warning: The types and functions defined in this file are not part of the
   SRB API. They are part of the SRB loadable driver interface and should not
   be used by normal SRB applications.

   The SRB implementation is divided into several parts.

   The @b loader implements the SRB API entry points that applications call.
   It is responsible for dynamically loading available driver modules, presenting
   their device descriptions to applications, and dispatching SRB API calls on a
   particular context to the appropriate driver.

   A @b driver implements the actual operations. It provides a device description
   and callback functions for each API entry point to the loader. The loader will
   call these functions directly with minimal error checking. It is the driver's
   responsibility to fully implement the API.

   A set of @b helper routines are provided to support API dispatch, as well as
   error handling and basic context and surface management. The driver should
   call these as part of its implementation of the SRB operations.

   Notes on error checking:
     - The loader will check that all pointer parameters to API functions are
       non-NULL.
     - The loader will check that the context handle pointed to by a context
       handle pointer API parameter is non-NULL.
     - Drivers are responsible for checking that the surface handles pointed to
       by surface handle pointer API parameters are non-NULL.
     - Drivers are responsible for checking that blit and fill info structures
       do not contain NULL surface handles or surface handle pointers.
     - If a surface handle is NULL, the error returned should be GDL_ERR_HANDLE.
       If a surface handle pointer in a blit or fill operation is NULL, the
       error returned should be GDL_ERR_INVAL.
     - Drivers are responsible for checking that blit and fill operations are
       supported by the hardware.
     - Drivers are responsible for checking that a surface is attached to the
       context being used for a detach, blit, fill, or wait operation.
     - Drivers may do their checks by calling the appropriate helper routines.

*/

/** @ingroup srb_driver */
/**@{*/

/**
   Callbacks into the driver to implement the SRB API functions.

   The specification for each function is the same as the corresponding API
   function, unless otherwise noted.
*/
typedef struct
{
    gdl_ret_t (*alloc_context)(gdl_uint32      device_id,
                               srb_context_t * context_handle);

    gdl_ret_t (*free_context)(srb_context_t * context_handle);

    /* attach_surface - This function is intentionally left out. The loader
       implements srb_attach_surface using attach_pixmap. */

    gdl_ret_t (*attach_pixmap)(srb_context_t * context_handle,
                               gma_pixmap_t    pixmap,
                               srb_surface_t * surface_handle);

    gdl_ret_t (*detach_surface)(srb_context_t * context_handle,
                                srb_surface_t * surface_handle);

    gdl_ret_t (*blit)(srb_context_t   * context_handle,
                      srb_blit_info_t * blit_info);

    gdl_ret_t (*fill)(srb_context_t   * context_handle,
                      srb_fill_info_t * fill_info);

    gdl_ret_t (*wait)(srb_context_t * context_handle,
                      srb_surface_t * surface_handle);

} srb_device_funcs_t;


/**
   The loader will look for this symbol in the driver library to get the
   driver's probe function. The probe function determines if the device
   is available and returns the device's info and function table.
*/
#define SRB_PROBE_FUNCTION_NAME srb_device_probe

typedef gdl_ret_t (*srb_probe_func_t)(srb_device_info_t  ** info,
                                      srb_device_funcs_t ** funcs);


/**
   Base structure for SRB context objects. Drivers should define a device-
   specific context structure whose first field is of this type.
*/
typedef struct
{
    gdl_uint32  device_id;
    gdl_uint32  num_surface_attached;
} srb_device_context_t;


/**
   Base structure for SRB surface objects. Drivers should define a device-
   specific surface structure whose first field is of this type.
*/
typedef struct
{
    srb_device_context_t * context;
    gma_pixmap_t           pixmap;
    gma_pixmap_info_t      pixmap_info;
} srb_device_surface_t;

/**@}*/

//-----------------------------------------------------------------------------
// Driver Helper Functions
//-----------------------------------------------------------------------------

SRB_API gdl_ret_t
srb_device_context_init(
    srb_device_context_t * context,
    gdl_uint32             device_id
    );
    /**< @ingroup srb_driver
    
    This routine initializes an already allocated device context.

    @param [in] context
    A pointer to the device context to initialize.

    @param [in] device_id
    An integer that uniquely identifies the device. The value is passed to the
    driver by the loader.
    
    */

SRB_API gdl_ret_t
srb_device_context_destroy(
    srb_device_context_t * context
    );
    /**< @ingroup srb_driver
    
    This routine cleans up the resources for a device context. The context
    structure itself is not freed.

    If surfaces are still attached to the device context, this routine returns
    GDL_ERR_BUSY without doing any further cleanup of the context. Contexts with
    surfaces attached should not be destroyed. Therefore, drivers should call
    this routine before freeing driver-specific context resources.

    @param [in] context
    A pointer to the device context to destroy.
    
    */

SRB_API gdl_ret_t
srb_device_context_format_supported(
    srb_device_context_t * context,
    gma_pixel_format_t     format
    );
    /**< @ingroup srb_driver
    
    This routine checks whether a context can use a pixel format as a source
    or destination in graphics operations. Returns GDL_ERR_NO_HW_SUPPORT if
    the format cannot be used for either a source or destination surface.

    This function should be called by a driver's attach_pixmap callback to
    verify that the driver can support the pixmap's format.

    @param [in] context
    A pointer to the device context to query.

    @param [in] format
    The requested format.
    
    */

SRB_API gdl_ret_t
srb_device_context_blit_supported(
    srb_device_context_t * context,
    srb_blit_info_t      * blit_info
    );
    /**< @ingroup srb_driver
    
    This routine checks whether a context can support a blit operation.
    Returns GDL_ERR_INVAL if any of the fields of blit_info are invalid.
    Returns GDL_ERR_HANDLE if any of the handles in blit_info are invalid.
    Returns GDL_ERR_NO_HW_SUPPORT if the operation cannot be supported.

    This function should be called by a driver's blit callback to verify that
    the driver supports the capabilities needed for the blit.

    @param [in] context
    A pointer to the device context to query.

    @param [in] blit_info
    The requested blit operation.
    
    */

SRB_API gdl_ret_t
srb_device_context_fill_supported(
    srb_device_context_t * context,
    srb_fill_info_t      * fill_info
    );
    /**< @ingroup srb_driver
    
    This routine checks whether a context can support a fill operation.
    Returns GDL_ERR_INVAL if any of the fields of fill_info are invalid.
    Returns GDL_ERR_HANDLE if any of the handles in fill_info are invalid.
    Returns GDL_ERR_NO_HW_SUPPORT if the operation cannot be supported.

    This function should be called by a driver's fill callback to verify that
    the driver supports the capabilities needed for the blit.

    @param [in] context
    A pointer to the device context to query.

    @param [in] fill_info
    The requested fill operation.
    
    */

SRB_API gdl_ret_t
srb_device_surface_init(
    srb_device_surface_t * surface,
    srb_device_context_t * context,
    gma_pixmap_t           pixmap
    );
    /**< @ingroup srb_driver
    
    This routine initializes an already allocated device surface. The
    device surface takes a reference to the pixmap if initialization
    is successful.

    @param [in] surface
    A pointer to the device surface to initialize.

    @param [in] context
    A pointer to the device context the surface is attached to.

    @param [in] pixmap
    A handle to the GMA pixmap that the device surface wraps.
    
    */

SRB_API gdl_ret_t
srb_device_surface_destroy(
    srb_device_surface_t * surface
    );
    /**< @ingroup srb_driver
    
    This routine cleans up the resources for a device surface and releases
    its reference to the underlying pixmap. The surface structure itself
    is not freed.

    @param [in] surface
    A pointer to the device surface to destroy.
    
    */

SRB_API gdl_ret_t
srb_device_surface_attached(
    srb_device_surface_t * surface,
    srb_device_context_t * context
    );
    /**< @ingroup srb_driver
    
    This routine checks whether a surface is attached to a particular context.

    @param [in] surface
    A pointer to the device surface to check.

    @param [in] context
    A pointer to the device context to check.
    
    */

#if defined(__cplusplus)
};
#endif

#endif
