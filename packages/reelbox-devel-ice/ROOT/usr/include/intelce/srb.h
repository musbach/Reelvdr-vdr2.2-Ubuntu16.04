//-----------------------------------------------------------------------------
//  Copyright 2009-2011 Intel Corporation
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
#ifndef _SRB_H_
#define _SRB_H_

#include "libgdl.h"
#include "libgma.h"

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef DOXYGEN_SKIP
#define SRB_API __attribute__ ((visibility ("default")))
#else
#define SRB_API " "
#endif

//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

/**@defgroup srb SRB surface rectangle blend 

    SRB is a software interface for blending rectangular areas of surfaces 
    using graphics hardware. SRB supports rectangular blit and fill operations.

    SRB operations can be executed on multiple graphics hardware devices. Blit
    and fill operations are executed on a particular hardware device via an SRB
    context. The SRB API provides functions to obtain information about the
    available hardware devices and to allocate and free an SRB context.
    All other SRB functions are executed relative to an SRB context.

    An SRB surface wraps a surface memory and is associated with an SRB context.  
    The surface memory could come from a GMA pixmap or GDL surface.  When the 
    SRB surface is attached to the context, the surface memory is mapped for use 
    by the graphics hardware.  When the SRB surface is detached from the 
    context, the surface memory is unmapped and the SRB surface is freed.

    The SRB API can execute alpha-blended blit and fill operations on 
    rectangular areas of SRB surfaces.  A blit operation is a copy from a source 
    surface to a destination surface.  A fill operation sets the pixel values in 
    the destination surface.  The blit and fill functions return before the 
    operation is completed.  Multiple blit and fill operations can be submitted 
    without waiting for previous operations to complete.  The SRB API provides 
    a wait function that will return when all blit and fill operations on an 
    SRB surface have been completed. 

*/

/** @ingroup srb */
/**@{*/

typedef void *srb_context_t;  ///< Handle to an SRB context
typedef void *srb_surface_t;  ///< Handle to an SRB surface

typedef gdl_uint32 srb_color_t; ///< A color in ARGB32 format

/**
    Blending flags to control the blending operation.
    (see #srb_blend_info_t for details).
*/
typedef enum
{
    SRB_BLEND_ENABLE_BLEND_EQUATION = 0x01, 
        ///< Use blend equation
    SRB_BLEND_ENABLE_SRC_MODULATE = 0x02, 
        ///< Modulate source pixel before blend
    SRB_BLEND_SRC_PREMULTIPLY_ALPHA = 0x04, 
        ///< Multiply source pixel color by alpha before blend
    SRB_BLEND_DEST_PREMULTIPLY_ALPHA = 0x08, 
        ///< Multiply destination pixel color by alpha before blend
    SRB_BLEND_DEST_POSTDIVIDE_ALPHA = 0x10, 
        ///< Divide result pixel color by alpha after blend
    SRB_BLEND_SRC_COLOR_KEY = 0x20, 
        /**< Ignore source pixels whose values fall in the source
          *  color key range
          *  NOTE
          *  The flag will be ignored by srb_blit if the source surface
          *  is A8 pixel format
          */
    SRB_BLEND_DEST_COLOR_KEY = 0x40 
        /**< Only write to destination pixels whose values fall in
          *  the destination color key range
          *  NOTE
          *  The flag will be ignored by srb_blit if the destination surface
          *  is A8 pixel format
          */
} srb_blend_flags_t;

/**
    Blending functions to control the coefficients used in the alpha blending
    equations (see #srb_blend_info_t for details).
*/
typedef enum
{
    SRB_BLEND_FUNC_ZERO,
    SRB_BLEND_FUNC_ONE,
    SRB_BLEND_FUNC_SRC,
    SRB_BLEND_FUNC_ONE_MINUS_SRC,
    SRB_BLEND_FUNC_DEST,
    SRB_BLEND_FUNC_ONE_MINUS_DEST,
    SRB_BLEND_FUNC_CONSTANT,
    SRB_BLEND_FUNC_ONE_MINUS_CONSTANT,
    SRB_BLEND_FUNC_LAST = SRB_BLEND_FUNC_ONE_MINUS_CONSTANT
} srb_blend_func_t;

/**
    Filter applied to the source surface in a blit operation.

    When scaling a surface as part of a blit operation, the surface may be
    sampled "between" pixels.  The filter option determines how SRB handles
    this situation.    

    The filter #SRB_FILTER_NEAREST selects the nearest pixel.

    The filter #SRB_FILTER_LINEAR interpolates between the four surrounding
    pixels.
*/
typedef enum
{
    SRB_FILTER_NEAREST,
    SRB_FILTER_LINEAR
} srb_filter_t;

//-----------------------------------------------------------------------------
/**
    Describes the desired alpha blending operation.  The #flags field controls 
    which operations are performed as part of the alpha blending operation.

    If #flags & #SRB_BLEND_SRC_PREMULTIPLY_ALPHA, the source color value is 
    multiplied by the source alpha value before use in the blend operation.

    If #flags & #SRB_BLEND_DEST_PREMULTIPLY_ALPHA, the destination color 
    value is multiplied by the destination alpha value before use in the blend 
    operation.

       Premultiply(A,R,G,B) = (A, R*A, G*A, B*A)

    If #flags & #SRB_BLEND_DEST_POSTDIVIDE_ALPHA, the color value result
    from the blend operation is divided by the alpha value result before the 
    pixel is written to the destination.

       Postdivide(A,R,G,B) = (A, R/A, G/A, B/A)

    If #flags & #SRB_BLEND_ENABLE_SRC_MODULATE, the source pixel value is 
    multiplied by the modulation color before use in the blend operation.

       Modulate( (As,Rs,Gs,Bs), (Am,Rm,Gm,Bm) ) = (As*Am, Rs*Rm, Gs*Gm, Bs*Bm)

    where (As,Rs,Gs,Bs) is the source color and (Am,Rm,Gm,Bm) is the 
    modulation color.

    If both #SRB_BLEND_SRC_PREMULTIPLY_ALPHA and 
    #SRB_BLEND_ENABLE_SRC_MODULATE are used, the Premultiply operation is 
    executed before the Modulate operation.

    If #flags & #SRB_BLEND_SRC_COLOR_KEY, the source pixel's RGB channels are
    compared with the corresponding channels in the low and high values of the
    source color key range before alpha premultiplication. The color value
    result from the blend operation is NOT written to the destination if both
    of the following conditions are true:

       * The source pixel's RGB channels are all greater than or equal to the
         cooresponding channels in the low value of the source color key range.
       * The source pixel's RGB channels are all less than or equal to the
         cooresponding channels in the high value of the source color key range.

    NOTE: The source color key setting will be ignored by srb_blit if the source
          surface is A8 pixel format since the color key algorithm ignores the
          alpha channel while A8 pixel format surface only contains alpha
          channel information.
 
    If #flags & #SRB_BLEND_DEST_COLOR_KEY, the RGB channels of the destination
    pixel are compared to the corresponding channels in the low and high values
    of the destination color key range before alpha premultiplication. The color
    value result from the blend operation is ONLY written to the destination if
    both of the following conditions are true:

       * The destination pixel's RGB channels are all greater than or equal to
         the cooresponding channels in the low value of the destination color
         key range.
       * The destination pixel's RGB channels are all less than or equal to the
         cooresponding channels in the high value of the destination color
         key range.

    NOTE: The destination color key setting will be ignored by srb_blit if the
          destination surface is A8 pixel format since the color key algorithm
          ignores the alpha channel while A8 pixel format surface only contains
          alpha channel information.

    If #flags & SRB_BLEND_ENABLE_BLEND_EQUATION, the blending operation uses 
    the following blending equations:
  
       C = Fsc * Cs + Fdc * Cd

       A = Fsa * As + Fda * Ad
  
    where Cs, As, Cd, and Ad are the source color, source alpha, destination 
    color and destination alpha components and Fsc, Fdc, Fsa, and Fda are 
    determined by the source and destination blending functions for the color 
    and alpha equations.  

    If SRB_BLEND_FUNC_CONSTANT or SRB_BLEND_FUNC_ONE_MINUS_CONSTANT are used 
    for a blending function, the constant value is specified in the const_rgb 
    or const_alpha fields.  For example, if src_rgb is SRB_BLEND_FUNC_CONSTANT,
    then Fsc is the value specified by the const_rgb field.

    If SRB_BLEND_ENABLE_BLEND_EQUATION is not used, the source pixel will 
    overwrite the destination pixel.  The equivalent blending equations are:
  
       C = Cs 

       A = As 
    
    Other flags can still be used even if SRB_BLEND_ENABLE_BLEND_EQUATION 
    is not used.

*/
typedef struct
{
    srb_blend_flags_t flags;       ///< Blending operation control flags.

    // Only needed if SRB_BLEND_ENABLE_SRC_MODULATE is used 
    srb_color_t       modulation_color; ///< Modulation color 

    // Only needed if SRB_BLEND_ENABLE_BLEND_EQUATION is used 
    srb_blend_func_t  src_rgb;     
        ///< source blend factor in color equation.
    srb_blend_func_t  src_alpha;   
        ///< source blend factor in alpha equation.
    srb_blend_func_t  dest_rgb;    
        ///< destination blend factor in color equation.
    srb_blend_func_t  dest_alpha;  
        ///< destination blend factor in alpha equation.

    // Only needed if a CONSTANT blend function is used
    gdl_uint8         const_rgb;   
        ///< Constant blend factor in color equation.
    gdl_uint8         const_alpha; 
        ///< Constant blend factor in alpha equation.

    // Only needed if SRB_BLEND_SRC_COLOR_KEY is used.
    srb_color_t       src_color_key_low;
        /**< Low value of the source color key range.
          *  The alpha channel is ignored.
          */
    srb_color_t       src_color_key_high;
        /**< High value of the source color key range.
          *  The alpha channel is ignored.
          */

    // Only needed if SRB_BLEND_DEST_COLOR_KEY is used.
    srb_color_t       dest_color_key_low;
        /**< Low value of the destination color key range. 
          *  The alpha channel is ignored.
          */
    srb_color_t       dest_color_key_high;
        /**< High value of the destination color key range. 
          *  The alpha channel is ignored.
          */
} srb_blend_info_t;


/**
   Describes a blit operation.  Pixels are copied from the source rectangle
   area of the source surface to the destination rectangle area of the
   destination surface with optional alpha blending.  The destination surface
   is only updated where the destination rectangle overlaps the clipping
   rectangle.
*/
typedef struct
{
    srb_surface_t *  src_surface_handle;   ///< The blit source
    srb_surface_t *  dest_surface_handle;  ///< The blit destination
    gdl_rectangle_t  src_rect;             /**< Defines the region of the source
                                             *  surface that is to be copied
                                             */
    gdl_rectangle_t  dest_rect;            /**< Defines the region of the 
                                             *  destination surface to which 
                                             *  the pixels are to be copied
                                             */
    gdl_rectangle_t  clip_rect;            /**< Defines the region of the 
                                             *  destination surface that is 
                                             *  allowed to be modified
                                             */
    srb_blend_info_t blend;                /**< Specifies the alpha blending 
                                             *  for the operation
                                             */

    srb_filter_t     filter;               /**< Specifies the filter for the
                                             *  operation
                                             */
} srb_blit_info_t;


/**
   Describes a fill operation.  The specified color is written to the specified
   rectangle area of the destination surface with optional alpha blending.  The
   destination surface is only updated where the fill rectangle overlaps the
   clipping rectangle.
*/
typedef struct
{
    srb_surface_t *  fill_surface_handle;  ///< The surface to fill
    gdl_rectangle_t  fill_rect;            /**< The region of the surface that 
                                             *  is to be filled
                                             */
    gdl_rectangle_t  clip_rect;            /**< Defines the region of the 
                                             *  destination surface that is 
                                             *  allowed to be modified
                                             */
    srb_color_t      fill_color;           ///< The color of the filled region
    srb_blend_info_t blend;                /**< Specifies the alpha blending 
                                             *  for the operation
                                             */
} srb_fill_info_t;


/**
   Optional features that an SRB implementation may support.
*/
typedef enum
{
    SRB_CAP_COLOR_KEY_RANGE,
        /**< The device supports setting distinct high and low values for
          *  the color key range. If this capability is not supported, then
          *  #src_color_key_low must equal #src_color_key_high and
          *  #dest_color_key_low must equal #dest_color_key_high
          *  in #srb_blend_info_t.
          */

    SRB_CAP_SEPARATE_BLEND_FUNC,
        /**< The device supports setting separate blending functions for the
          *  color and alpha blending equations. If this capability is not
          *  supported, then #src_rgb must equal #src_alpha and #dest_rgb
          *  must equal #dest_alpha in #srb_blend_info_t.
          */

    SRB_CAP_CONSTANT_BLEND_FUNC,
        /**< The device supports constant blending functions. If this
          *  capability is not supported, then #src_rgb, #src_alpha,
          *  #dest_rgb, and #dest_alpha must not have the value
          *  #SRB_BLEND_FUNC_CONSTANT or #SRB_BLEND_FUNC_ONE_MINUS_CONSTANT
          *  in #srb_blend_info_t.
          */

    SRB_CAP_SURFACE_ALPHA_BLEND_FUNC,
        /**< The device supports setting the source and destination blending
          *  functions to values that include the corresponding surface's own
          *  alpha channel. If this capability is not supported, then #src_rgb
          *  and #src_alpha must not have the value #SRB_BLEND_FUNC_SRC or
          *  #SRB_BLEND_FUNC_ONE_MINUS_SRC and #dest_rgb and #dest_alpha must
          *  not have the value #SRB_BLEND_FUNC_DEST or
          *  #SRB_BLEND_FUNC_ONE_MINUS_DEST in #srb_blend_info_t.
          */

    SRB_CAP_COLORKEY_AND_BLEND,
        /**< The device supports colokeying and alpha blending in the same
          *  operation. If this capability is not supported, then
          *  #SRB_BLEND_ENABLE_BLEND_EQUATION can only be set in
          *  #srb_blend_info_t if #SRB_BLEND_SRC_COLOR_KEY and
          *  #SRB_BLEND_DEST_COLOR_KEY are not set.
          */

    SRB_CAP_LINEAR_FILTER,
        /**< The device supports linear filtering. If this capability is not
          *  supported, then #filter must be set to #SRB_FILTER_NEAREST
          *  in #srb_blit_info_t.
          */

    SRB_CAP_SAME_SURFACE_BLIT,
        /**< The device supports "same surface" blits. If this capability is
          *  not supported, then #src_surface_handle must not equal
          *  #dest_surface_handle in #srb_blit_info_t.
          */

    SRB_CAP_COUNT
} srb_capability_t;


/**
   Describes a hardware device on which SRB operations can be executed.

   The #caps, #src_formats, and #dest_formats fields list the supported
   capabilities and pixels formats for the device. If an application tries
   to perform an unsupported operation or use a surface with an unsupported
   format, the SRB API function will return GDL_ERR_NO_HW_SUPPORT. See
   #srb_capability_t for details on unsupported operations.
*/
typedef struct
{
    char               * name;                   ///< The name of the device

    srb_capability_t   * caps;                   /**< Optional features
                                                   *  supported by this device
                                                   */
    gdl_uint32           cap_count;              /**< Number of supported
                                                   *  optional features
                                                   */

    gma_pixel_format_t * src_formats;            /**< Pixel formats supported
                                                   *  for source surfaces
                                                   */
    gdl_uint32           src_format_count;       /**< Number of supported
                                                   *  source formats
                                                   */

    gma_pixel_format_t * dest_formats;           /**< Pixel formats supported
                                                   *  for destination surfaces
                                                   */
    gdl_uint32           dest_format_count;      /**< Number of supported
                                                   *  destination formats
                                                   */
} srb_device_info_t;

/**@}*/


//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

SRB_API gdl_ret_t
srb_query_devices(
    gdl_uint32 *count,
    gdl_uint32 *device_ids
    );
    /**< @ingroup srb

    Returns identifiers for the available devices on which SRB operations can
    be executed.

    @param [in,out] count
    If device_ids is NULL, returns the number of available devices.
    If device_ids is not NULL, specifies the maximum number of elements allowed
    in the device_ids array and returns the actual number of identifiers placed
    in the array.

    @param [out] device_ids
    An array to be filled with identifiers for the available devices.

    */

SRB_API gdl_ret_t
srb_get_device_info(
    gdl_uint32 device_id,
    srb_device_info_t **device_info
    );
    /**< @ingroup srb

    Returns information about a device on which SRB operations can be executed.

    @param [in]  device_id
    The device to be described.

    @param [out] device_info
    Information about the specified device. Memory for the structure is
    allocated by #srb_get_device_info and must be freed by
    #srb_free_device_info.

    */

SRB_API gdl_ret_t
srb_free_device_info(
    srb_device_info_t *device_info
    );
    /**< @ingroup srb

    Frees the memory for the specified device description.

    @param [in] device_info
    The device description to be freed.

    */

SRB_API gdl_ret_t
srb_alloc_context(
    gdl_uint32       device_id,
    srb_context_t *  context_handle
    );
    /**< @ingroup srb

    This routine allocates a context for use by SRB. Operations for this
    context will be executed on the specified device.

    @param [in] device_id
    The identifier of the device used to execute operations for this context.

    @param [out]  context_handle
    A pointer to a #srb_context_t to be filled with the context handle.

    */

SRB_API gdl_ret_t
srb_free_context(
    srb_context_t *  context_handle
    );
    /**< @ingroup srb

    This routine frees a context.  Associated resources are de-allocated.
    Surfaces that have been attached to the context are not detached.

    @param [in] context_handle
    A pointer to the handle for the context to be freed.

    */

SRB_API gdl_ret_t
srb_attach_surface(
    srb_context_t *  context_handle,
    gdl_surface_id_t surface_id,
    srb_surface_t *  surface_handle
    );
    /**< @ingroup srb
    
    This routine attaches a GDL surface to a context.  The surface must have
    a supported pixel format.  Supported pixels formats are determined by the
    capabilities of the device associated with the specified context. 

    @param [in] context_handle
    A pointer to the handle for the context to attach the surface to.

    @param [in] surface_id
    The ID of the GDL surface to be attached to the context.

    @param [out] surface_handle
    A pointer to a #srb_surface_t to be filled with the surface handle.
    
    */

SRB_API gdl_ret_t
srb_attach_pixmap(
    srb_context_t *  context_handle,
    gma_pixmap_t     pixmap,
    srb_surface_t *  surface_handle
    );
    /**< @ingroup srb
    
    This routine attaches a GMA pixmap to a context.  The surface must have
    a supported pixel format.  Supported pixels formats are determined by the
    capabilities of the device associated with the specified context.

    @param [in] context_handle
    A pointer to the handle for the context to attach the pixmap to.

    @param [in] pixmap
    A handle to the GMA pixmap to be attached to the context.

    @param [out] surface_handle
    A pointer to a #srb_surface_t to be filled with the surface handle.
    
    */

SRB_API gdl_ret_t
srb_detach_surface(
    srb_context_t *  context_handle,
    srb_surface_t *  surface_handle
    );
    /**< @ingroup srb

    This routine detaches a surface from a context.  Associated internal
    resources are de-allocated.  The surface memory itself is not de-allocated.

    @param [in] context_handle
    A pointer to the handle for the context from which to detach the surface.

    @param [in] surface_handle
    A pointer to the surface handle of the surface to be detached.

    */

SRB_API gdl_ret_t
srb_blit(
    srb_context_t    *  context_handle,
    srb_blit_info_t  *  blit_info
    );
    /**< @ingroup srb

    This routine submits a blit operation.  The operation is not guaranteed to
    complete before the function returns.  

    @param [in] context_handle
    A pointer to the handle for the context to be used for this blit operation
 
    @param [in] blit_info
    A pointer to a structure that describes the blit operation

    */

SRB_API gdl_ret_t
srb_fill(
    srb_context_t   *  context_handle,
    srb_fill_info_t *  fill_info
    );
    /**< @ingroup srb

    This routine submits a fill rectangle operation.  The operation is not
    guaranteed to complete before the function returns.

    @param [in] context_handle
    A pointer to the handle for the context to be used for this fill operation
 
    @param [in] fill_info
    A pointer to a structure that describes the fill operation

    */

SRB_API gdl_ret_t
srb_wait(
    srb_context_t *  context_handle,
    srb_surface_t *  surface_handle
    );
    /**< @ingroup srb

    This routine waits for all outstanding operations to the specified 
    destination surface to complete.

    @param [in] context_handle
    A pointer to the handle for the context on which operations have
    been submitted

    @param [in] surface_handle
    A pointer to the handle of the surface on which operations have
    been submitted

    */

#if defined(__cplusplus)
};
#endif

#endif
