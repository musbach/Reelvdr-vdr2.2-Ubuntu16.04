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
//---------------------------------------------------------------------------*/

/*
    This module contains image loading utilities for PNG formatted files.

    NOTE   It depends upon LIBPNG (www.libpng.org) which in turn depends upon 
           LIBZ (www.zlib.net).
*/


#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "util_ImagePNG.h"

//*****************************************************************************
//  Global functions
//*****************************************************************************


//-----------------------------------------------------------------------------
gdl_ret_t CreateImagePNG( char* pImageFileNameString, ImagePNG** ppImagePNG )
{
    gdl_ret_t   result      = GDL_SUCCESS;
    FILE        *pImageFile = NULL;
    png_structp pPNG        = NULL;
    png_infop   pPNGInfo    = NULL;
    ImagePNG    *pImagePNG  = NULL;
    
    do
    {
        if ( !pImageFileNameString || !(*pImageFileNameString) || !ppImagePNG )
        {
            result = GDL_ERR_INVAL;
            break;
        }

        // Attempt to open the PNG file.
        pImageFile = fopen( pImageFileNameString, "rb");

        if ( !pImageFile )
        {
            fprintf( 
                stderr, 
                "FAILED:  CANNOT OPEN IMAGE FILE NAMED \"%s\"\n", 
                pImageFileNameString );

            result = GDL_ERR_INVAL;
            break;
        }

        gdl_uint32  itemsRead;
        gdl_uint8   pHeaderBuffer[ 8 ];

        // Read the first eight bytes that should be the file header.
        itemsRead = fread(  pHeaderBuffer, 
                            sizeof( pHeaderBuffer ), 
                            1, 
                            pImageFile );

        if ( itemsRead != 1 )
        {
            result = GDL_ERR_INVAL;
            break;
        }

        // Verify that the header really identifies a PNG file.
        if( png_sig_cmp( pHeaderBuffer, 0, sizeof( pHeaderBuffer ) ) )
        {
            result = GDL_ERR_INVAL;
            break;
        }

        // Create PNG structures.

        pPNG = png_create_read_struct( 
                    PNG_LIBPNG_VER_STRING, 
                    NULL,
                    NULL, 
                    NULL );

        if ( !pPNG )
        {
            result = GDL_ERR_NO_MEMORY;
            break;
        }

        pPNGInfo = png_create_info_struct( pPNG );

        if ( !pPNGInfo )
        {
            result = GDL_ERR_NO_MEMORY;
            break;
        }

        // Perform PNG setup.

        if ( setjmp( png_jmpbuf( pPNG ) ) )
        {
            result = GDL_ERR_INTERNAL;
            break;
        }

        png_set_keep_unknown_chunks( pPNG, 0, NULL, 0 );

        png_init_io( pPNG, pImageFile );

        png_set_sig_bytes( pPNG, sizeof( pHeaderBuffer ) );

        // Read information about the image.
        png_read_info( pPNG, pPNGInfo );

        // Validate the image is okay for our usages and determine what pixel 
        // format it is.

        if ( !pPNGInfo->width || !pPNGInfo->height )
        {
            result = GDL_ERR_INVAL;
            break;
        }

        gdl_pixel_format_t  pixelFormat = GDL_PF_COUNT;
                    // Used since there is no invalid pixel format enumerator.

        switch (pPNGInfo->color_type)
        {
        case PNG_COLOR_TYPE_RGB:
            switch (pPNGInfo->channels)
            {
            case 3:
                pixelFormat = GDL_PF_RGB_24;
                break;
            case 4:
                pixelFormat = GDL_PF_RGB_32;
                break;
            default:
                result = GDL_ERR_INVAL_PF;
                break;
            }
            break;
        case PNG_COLOR_TYPE_RGBA:
            pixelFormat = GDL_PF_ARGB_32;
            break;
        default:
            result = GDL_ERR_INVAL_PF;
            break;
        }

        // Create an ImagePNG structure to contain the loading state and 
        // details about the image for the client.
        pImagePNG = ( ImagePNG* ) malloc( sizeof( ImagePNG ) );

        if ( !pImagePNG )
        {
            result = GDL_ERR_NO_MEMORY;
            break;
        }

        // Initialize the ImagePNG structure.
        pImagePNG->pixelFormat  = pixelFormat;
        pImagePNG->width        = pPNGInfo->width;
        pImagePNG->height       = pPNGInfo->height;
        pImagePNG->bpp          = pPNGInfo->bit_depth * pPNGInfo->channels;
        pImagePNG->pImageBuffer = NULL;
        pImagePNG->pImageFile   = pImageFile;
        pImagePNG->pPNG         = pPNG;
        pImagePNG->pPNGInfo     = pPNGInfo;

        // Hand back a pointer to the ImagePNG structure.
        *ppImagePNG = pImagePNG;
    }
    while ( GDL_FALSE );

    if ( result != GDL_SUCCESS )
    {
        if ( pImagePNG )
        {
            free( pImagePNG );
        }

        if ( pPNG )
        {
            if ( pPNGInfo )
            {
                png_destroy_info_struct( pPNG, &pPNGInfo );
            }

            png_destroy_read_struct( &pPNG, NULL, NULL );
        }

        if ( pImageFile )
        {
            fclose( pImageFile );
        }
    }

    return result;
}

//-----------------------------------------------------------------------------
gdl_ret_t LoadImagePNG( ImagePNG* pImagePNG )
{
    gdl_ret_t   result      = GDL_SUCCESS;
    png_bytepp  ppRowArray  = NULL;
    gdl_uint32  row;

    if ( !pImagePNG )
    {
        return GDL_ERR_INVAL;
    }

    // Don't load the image if it's already loaded.
    if ( pImagePNG->pImageBuffer == NULL )
    {
        // Manually perform png_read_png functionality since we have already 
        // partially read data from the file using png_read_info.  This 
        // includes transforms PNG_TRANSFORM_EXPAND and PNG_TRANSFORM_BGR.

        if (png_get_valid(pImagePNG->pPNG,pImagePNG->pPNGInfo,PNG_INFO_tRNS))
        {
            png_set_expand( pImagePNG->pPNG );
        }

        png_set_bgr( pImagePNG->pPNG );

        png_read_update_info( pImagePNG->pPNG, pImagePNG->pPNGInfo );

        ppRowArray = (png_bytepp) png_malloc( 
                                    pImagePNG->pPNG, 
                                    pImagePNG->height * png_sizeof(png_bytep) );
        if ( !ppRowArray )
        {
            result = GDL_ERR_NO_MEMORY;
            goto release;
        }

        memset( ppRowArray, 0, sizeof( png_bytep ) );

        for ( row = 0; row < pImagePNG->height; ++row )
        {
            ppRowArray[ row ] = ( png_bytep ) png_malloc( 
                                                    pImagePNG->pPNG, 
                                                    png_get_rowbytes( 
                                                        pImagePNG->pPNG, 
                                                        pImagePNG->pPNGInfo ) );
        }

        png_read_image( pImagePNG->pPNG, ppRowArray );
        png_read_end  ( pImagePNG->pPNG, NULL );

        // Determine and double check the stride of the image buffer.
        gdl_uint32  bufferStride  = pImagePNG->pPNGInfo->rowbytes;
        if ( bufferStride != ( ( pImagePNG->bpp / 8 ) * pImagePNG->width ) )
        {
            result = GDL_ERR_INTERNAL;
            goto release;
        }

        // Create a contiguous image buffer
        pImagePNG->pImageBuffer = (gdl_uint8*) malloc( 
                                            bufferStride * pImagePNG->height);
        if ( !pImagePNG->pImageBuffer )
        {
            result = GDL_ERR_NO_MEMORY;
            goto release;
        }

        // Copy the PNG image row-by-row into the contiguous image buffer.
        gdl_uint8  *pBufferRowStart = pImagePNG->pImageBuffer;
        for ( row = 0; row < pImagePNG->height; ++row )
        {
            memcpy( pBufferRowStart, ppRowArray[ row ], bufferStride );
            pBufferRowStart += bufferStride;
        }
    }

release:
    // Release memory resources.
    if ( pImagePNG->pPNG )
    {
        if ( ppRowArray )
        {
            for ( row = 0; row < pImagePNG->height; ++row )
            {
                png_bytep pRow  = ppRowArray[ row ];

                if ( pRow )
                {
                    png_free( pImagePNG->pPNG, pRow );
                }
            }

            png_free( pImagePNG->pPNG, ppRowArray );
            ppRowArray = NULL;
        }

        if ( pImagePNG->pPNGInfo )
        {
            png_destroy_info_struct(pImagePNG->pPNG, 
                                    &pImagePNG->pPNGInfo );
            pImagePNG->pPNGInfo = NULL;
        }

        png_destroy_read_struct( &pImagePNG->pPNG, NULL, NULL );
        pImagePNG->pPNG = NULL;
    }

    // Close PNG file
    if ( pImagePNG->pImageFile )
    {
        fclose( pImagePNG->pImageFile );
        pImagePNG->pImageFile = NULL;
    }

    return result;
}

void DestroyImagePNG( ImagePNG* pImagePNG )
{
    if ( pImagePNG )
    {
        if ( pImagePNG->pImageBuffer )
        {
            free( pImagePNG->pImageBuffer );
            pImagePNG->pImageBuffer = NULL;
        }

        if ( pImagePNG->pPNG )
        {
            if ( pImagePNG->pPNGInfo )
            {
                png_destroy_info_struct(pImagePNG->pPNG, &pImagePNG->pPNGInfo);
                pImagePNG->pPNGInfo = NULL;
            }

            png_destroy_read_struct( &pImagePNG->pPNG, NULL, NULL );
            pImagePNG->pPNG = NULL;
        }

        if ( pImagePNG->pImageFile )
        {
            fclose( pImagePNG->pImageFile );
            pImagePNG->pImageFile = NULL;
        }

        free( pImagePNG );
    }
}


gdl_ret_t SaveImagePNG( char* pImageFileNameString, ImagePNG* pImagePNG)
{
    gdl_ret_t    ret_val = GDL_SUCCESS;
    png_byte color_type = 0;
    //FILE *out_file_handle = NULL;

    if( 0 ==  strlen(pImageFileNameString))
    {
        ret_val = GDL_ERR_NO_INIT;
        goto end;
    }

    if( !(pImagePNG->pImageFile = fopen(pImageFileNameString, "wb")) )
    {
        printf("File not be opened\n");
        ret_val = GDL_ERR_NO_INIT;
        goto end;
    }

    if( !pImagePNG->pImageBuffer)
    {
        printf("Image buffer empty\n");
        ret_val = GDL_ERR_NO_INIT;
        goto end;
    }

    /* NOTE: LRA, what does this function do??? 
    FIXME:  use the image format to fill in the write info struct stuff.
    if( 4 != g_image_info.BPP &&  //Just handle 16/32bpp images for now...
        2 != g_image_info.BPP)
    {
        ret_val = GDL_IMAGE_E_INVALID_VALUE;
        goto end;
    }
    */

    pImagePNG->pPNG = png_create_write_struct
       (PNG_LIBPNG_VER_STRING, NULL,
        NULL, NULL);

    if (!pImagePNG->pPNG)
    {
        ret_val = GDL_ERR_NO_MEMORY;
        goto end;
    }

    pImagePNG->pPNGInfo = png_create_info_struct(pImagePNG->pPNG);
    if (!pImagePNG->pPNGInfo)
    {
        ret_val = GDL_ERR_NO_MEMORY;
        goto end;
    }

    if (setjmp(pImagePNG->pPNG->jmpbuf))
    //if (setjmp(png_jmpbuf(pImagePNG->pPNG)))
    {
       printf("setjmp Failed\n");
       ret_val = GDL_ERR_INTERNAL;
       goto end;
    }

    png_init_io(pImagePNG->pPNG, pImagePNG->pImageFile);

    //png_set_filter(png_ptr, 0, PNG_FILTER_NONE);

    //May want to set compression levels here...
       /* store image format NOTE: Only supports RGB32, RGB24, ARGB */

    switch(pImagePNG->pixelFormat)
    {
    case GDL_PF_RGB_24:
    case GDL_PF_RGB_32:
        color_type = PNG_COLOR_TYPE_RGB;
        break;
    case GDL_PF_ARGB_32:
        color_type = PNG_COLOR_TYPE_RGBA;
        break;
    default:
        ret_val = GDL_ERR_INVAL_PF;
        goto end;
    }

    //Fill in the information we have about the image:
    png_set_IHDR(pImagePNG->pPNG, 
                 pImagePNG->pPNGInfo, 
                 pImagePNG->width, 
                 pImagePNG->height,
                 8,                     //FIXME: Need to store this info
                 color_type, 
                 PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, 
                 PNG_FILTER_TYPE_DEFAULT);

    //Now try to write the image out...
    png_write_png(pImagePNG->pPNG,
                  pImagePNG->pPNGInfo,
                  PNG_TRANSFORM_IDENTITY,
                  NULL);
end:
    if(pImagePNG->pImageFile)
    {
        fclose(pImagePNG->pImageFile);
    }

    if(pImagePNG->pPNG)
    {
        png_destroy_write_struct(&pImagePNG->pPNG, &pImagePNG->pPNGInfo);
    }
    return ret_val;
}
