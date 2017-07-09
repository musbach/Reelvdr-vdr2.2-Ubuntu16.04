//-----------------------------------------------------------------------------
// BSD LICENSE
//
// Copyright(c) 2006-2011 Intel Corporation. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   - Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   - Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in
//     the documentation and/or other materials provided with the
//     distribution.
//   - Neither the name of Intel Corporation nor the names of its
//     contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

/**
    @file   util_Surfaces.h

    This module contains surface handling utilities.
*/


#ifndef __UTIL_SURFACES_H__
#define __UTIL_SURFACES_H__


//*****************************************************************************
//  Includes
//*****************************************************************************


#include <stdio.h>
#include <stdlib.h>

#include "gdl_types.h"
#include "util_ImagePNG.h"


//*****************************************************************************
//  Classes, structures and types
//*****************************************************************************


//-----------------------------------------------------------------------------
/**
    Defines constraints for the width or height of an image.
*/
typedef enum
{
    SIZE_CONSTRAINT_NONE, 
    SIZE_CONSTRAINT_MULTIPLE_OF_2, 
    SIZE_CONSTRAINT_MULTIPLE_OF_4
} SizeConstraint;


//*****************************************************************************
//  Global function prototypes
//*****************************************************************************


#if defined( __cplusplus )
extern "C"
{
#endif

//-----------------------------------------------------------------------------
/**
    This function loads an image from a file, then creates a surface with the 
    same dimensions as the image (or slightly modified based on the specified 
    surface size constraints if any), and initializes it with the image.

    @param  pImageFileName          Name of the local file to use that 
                                    contains PNG formatted data.  The string 
                                    may also include an absolute or relative 
                                    path.
    @param surfaceFlags             The surface flags from 
                                    #gdl_surface_flags_t to use when creating 
                                    the surface.
    @param force24To32              Boolean that forces the surface created to 
                                    be 32 bpp if GDL_TRUE.  Otherwise, the 
                                    surface created will be either 24 or 32 
                                    bpp depending upon the type of file loaded.
    @param forceWidthConstraint     An optional surface width constraint that 
                                    is applied to the size of the created 
                                    surface.
    @param forceHeightConstraint    An optional surface height constraint that 
                                    is applied to the size of the created 
                                    surface.
    @param pSurfaceInfo             Pointer to a #gdl_surface_info_t structure 
                                    that upon success will be initialized with 
                                    details about the created surface.

    @return Upon success, GDL_SUCCESS is returned.  Otherwise, one of the GDL 
            failure error codes will be returned.

    @note   If the specified image does not meet the specified surface size 
            constraints, the surface size is increased just enough extra 
            pixels to contain the whole image while still meeting the 
            constaints.  The additional pixels will be filled with black.

    @note   If any surface size constraints are specified and the appropriate 
            surface size is larger than the maximum for the display driver, it 
            will be capped at the largest size (2048 x 2048).

    @note   Only PNG RGB and RGBA images are currently supported (24 and 32 
            bpp).
*/
gdl_ret_t   CreateSurfaceWithImage( 
                char*               pImageFileName, 
                gdl_uint32          surfaceFlags, 
                gdl_boolean_t       force24To32, 
                SizeConstraint      forceWidthConstraint, 
                SizeConstraint      forceHeightConstraint, 
                gdl_surface_info_t* pSurfaceInfo );

//-----------------------------------------------------------------------------
/**
    This function will copy a PNG image to the specified surface.

    @param  pImagePNG   Pointer to an ImagePNG structure that contains a valid 
                        PNG image loaded using the @ref CreateImagePNG and 
                        @ref LoadImagePNG functions.
    @param  surfaceId   Id of an existing surface created using 
                        @ref gdl_alloc_surface.

    @return Upon success, GDL_SUCCESS is returned.  Otherwise, one of the GDL 
            failure error codes will be returned.

    @note   Only 24 and 32 bpp images and surfaces are supported 
            (GDL_PF_ARGB_32, GDL_PF_RGB_32 and GDL_PF_RGB_24).
*/
gdl_ret_t   CopyImageToSurface( 
                ImagePNG*           pImagePNG, 
                gdl_surface_id_t    surfaceId );

//-----------------------------------------------------------------------------
/**
    Copies a surface with an RGB pixel format to one with a YUV format.  The 
    copy can be performed for either progressive or interleaved usage.

    @param  surfaceIdRGB            Id of an existing RGB surface created 
                                    using @ref gdl_alloc_surface that is 24 or 
                                    32 bpp (GDL_PF_RGB_24, GDL_PF_RGB_32 or 
                                    GDL_PF_ARGB_32).  The alpha channel in 
                                    surfaces with one are discarded because 
                                    there is no supported YUV format that 
                                    contains an alpha channel.
    @param  surfaceIsProgressive    Boolean that if GDL_TRUE will perform the 
                                    copy to YUV for progressive usage.  
                                    Otherwise, the YUV copy performed will be 
                                    for interleaved usage.
    @param  surfaceIdYUV            Id of an existing YUV surface created 
                                    using @ref gdl_alloc_surface that is in a 
                                    YUV 4:2:2 or 4:2:0 format (GDL_PF_I422, 
                                    GDL_PF_YV16, GDL_PF_NV16, GDL_PF_I420, 
                                    GDL_PF_YV12 or GDL_PF_NV12).

    @return Upon success, GDL_SUCCESS is returned.  Otherwise, one of the GDL 
            failure error codes will be returned.

    @note   Both surfaces' widths must be evenly divisible by two and their 
            heights must be evenly divisible by four.

    @note   Luma and chroma conversions are done in the MPEG-2/H.264 style.

    @note   This function also handles the packed YUV 4:2:2 pixel formats 
            (GDL_PF_YUY2, GDL_PF_UYVY, GDL_PF_YVYU and GDL_PF_VYUY).
*/
gdl_ret_t   CopySurfaceRGBToYUV( 
                gdl_surface_id_t    surfaceIdRGB, 
                gdl_boolean_t       surfaceIsProgressive, 
                gdl_surface_id_t    surfaceIdYUV );

//-----------------------------------------------------------------------------
/**
    Copies an entire YUV surface or a portion of it to another surface with 
    the same pixel format.

    @param  surfaceSourceId         Id of the source YUV surface created using 
                                    @ref gdl_alloc_surface that is in a YUV 
                                    4:2:2 or 4:2:0 format (GDL_PF_I422, 
                                    GDL_PF_YV16, GDL_PF_NV16, GDL_PF_I420, 
                                    GDL_PF_YV12 or GDL_PF_NV12).
    @param  pRectSource             Pointer to a rectangle relative to the 
                                    upper-left corner of the source surface 
                                    whose pixels will be copied to the 
                                    destination surface.  Rectangle 
                                    requirements are provided below.  NULL may 
                                    be specified to use the entire surface.
    @param  surfaceDestinationId    Id of the destination YUV surface created 
                                    using @ref gdl_alloc_surface that is in a 
                                    YUV 4:2:2 or 4:2:0 format (GDL_PF_I422, 
                                    GDL_PF_YV16, GDL_PF_NV16, GDL_PF_I420, 
                                    GDL_PF_YV12 or GDL_PF_NV12).
    @param  pRectDestination        Pointer to a rectangle relative to the 
                                    upper-left corner of the destination 
                                    surface where the pixels in the specified 
                                    source surface's rectangle will be copied.
                                    Rectangle requirements are provided below.
                                    NULL may be specified to use the entire 
                                    surface.

    @return Upon success, GDL_SUCCESS is returned.  Otherwise, one of the GDL 
            failure error codes will be returned.

    @note   The source and destination rectangles must meet the following 
            requirements:
            -   No scaling is supported.  The destination rectangle size must 
                match the source rectangle size.
            -   No clipping is supported.  The destination rectangle origin 
                must be set such that the entire rectangle resides on the 
                destination surface.
            -   Both rectangle widths must be evenly divisible by two.
            -   Both rectangle heights must be evenly divisible by four.
            -   Both rectangle origin X positions must be either zero or 
                evenly divisible by two.
            -   If a YUV 4:2:2 format is used (GDL_PF_I422, GDL_PF_YV16 or 
                GDL_PF_NV16), both rectangle origin Y positions must be either 
                zero or evenly divisible by two.
            -   If a YUV 4:2:0 format is used (GDL_PF_I420, GDL_PF_YV12 or 
                GDL_PF_NV12), both rectangle origin Y positions must be either 
                zero or evenly divisible by four.

    @note   This function also handles the packed YUV 4:2:2 pixel formats 
            (GDL_PF_YUY2, GDL_PF_UYVY, GDL_PF_YVYU and GDL_PF_VYUY).
*/
gdl_ret_t   CopySurfaceYUVToYUV( 
                gdl_surface_id_t    surfaceSourceId, 
                gdl_rectangle_t*    pRectSource, 
                gdl_surface_id_t    surfaceDestinationId, 
                gdl_rectangle_t*    pRectDestination );
  
gdl_ret_t   SaveSurfaceAsPNG(char*               pImageFileName, 
                             gdl_surface_info_t* pSurfaceInfo   );


#if defined( __cplusplus )
}
#endif


#endif /* __UTIL_SURFACES_H__ */
