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
    This module contains image loading utilities for PNG formatted files.

    @note   It depends upon LIBPNG (www.libpng.org) which in turn depends upon 
            LIBZ (www.zlib.net).
*/


#ifndef __UTIL_IMAGEPNG_H__
#define __UTIL_IMAGEPNG_H__

#include <stdio.h>
#include <stdlib.h>

#include "gdl_types.h"
#include "png.h"
#include "util.h"


//*****************************************************************************
//  Classes, structures and types
//*****************************************************************************


//-----------------------------------------------------------------------------
/**
    Structure that contains information specific to a PNG image in the process 
    of being loaded or already loaded.
*/
typedef struct
{
    gdl_pixel_format_t  pixelFormat;    ///< Pixel format of the image.
    gdl_uint32          width,          ///< Width of the image in pixels.
                        height,         ///< Height of the image in pixels.
                        bpp;            ///< Pixel format bits per pixel.
    gdl_uint8           *pImageBuffer;  ///< Pointer to the image's pixels or NULL if the image is not loaded yet.

    // This following data members are not intended for client usage.

    FILE                *pImageFile;    ///< Pointer to the image FILE structure.  It is not intended for client usage.
    png_structp         pPNG;           ///< Pointer to PNG structure used for reading.
    png_infop           pPNGInfo;       ///< Pointer to PNG info structure.
} ImagePNG;


//*****************************************************************************
//  Global function prototypes
//*****************************************************************************


#if defined( __cplusplus )
extern "C"
{
#endif

//-----------------------------------------------------------------------------
/**
    Validates that the specified file exists and is a PNG file that contains 
    an RGB or RGBA image.  Upon success, an #ImagePNG structure pointer is 
    handed back that contains details about the image and internal state for 
    eventually loading its image data by using the @ref LoadImagePNG function.

    @note   When finished using the provided #ImagePNG structure and the image 
            buffer it identifies, the associated resources must be released 
            by using the @ref DestroyImagePNG function.
*/
gdl_ret_t CreateImagePNG( char* pImageFileNameString, ImagePNG** ppImagePNG );

//-----------------------------------------------------------------------------
/**
    Loads the main image data for the PNG file used to create the specified 
    #ImagePNG structure obtained from a previous call to the 
    @ref CreateImagePNG function.  Upon success, the image buffer pointer in 
    the #ImagePNG structure will be valid and it will contain the raw image 
    data.

    @todo   Eventually update this function to read the image directly into 
            the single final contiguous block of memory so that the row-by-row 
            copy to it at the end is unneeded.
*/
gdl_ret_t LoadImagePNG( ImagePNG* pImagePNG );

//-----------------------------------------------------------------------------
/**
    Releases all resources associated with the specified #ImagePNG structure 
    obtained from a previous call to the @ref CreateImagePNG function.
*/
void DestroyImagePNG( ImagePNG* pImagePNG );


gdl_ret_t SaveImagePNG( char* pImageFileNameString, ImagePNG* pImagePNG);

#if defined( __cplusplus )
}
#endif


#endif  /* __UTIL_IMAGEPNG_H__ */
