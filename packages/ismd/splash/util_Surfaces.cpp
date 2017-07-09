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

// This module contains surface handling utilities


#include <stdio.h>
#include <stdlib.h>

#include <libgdl.h>
#include <srb.h>
#include <x86_cache.h>
#include "util.h"
#include "util_Surfaces.h"


// Number of pixels per row in a macro block for the YUV 4:2:2/4:2:0 formats.
#define _NPIX   2

// Number of pixel rows per macro block for YUV 4:2:0 pixel format.
#define _NROW     2

// Maximum factor used in calculating the block row weightings that are used
// for calculating YUV 4:2:0 pixel U and V components.
#define _MAX_FACTOR     4

// Returns minimum of the specified values.
#define _MIN( value1, value2 )  ( ( value1 < value2 ) ? value1 : value2 )


//-----------------------------------------------------------------------------
gdl_ret_t CreateSurfaceWithImage(
                char*               pImageFileName,
                gdl_uint32          surfaceFlags,
                gdl_boolean_t       force24To32,
                SizeConstraint      forceWidthConstraint,
                SizeConstraint      forceHeightConstraint,
                gdl_surface_info_t* pSurfaceInfo )
{
    gdl_ret_t           result          = GDL_SUCCESS;
    ImagePNG           *pImagePNG       = NULL;
    gdl_surface_info_t  surfaceInfo;
    gdl_boolean_t       surfaceCreated  = GDL_FALSE;
    gdl_pixel_format_t  surfaceFormat;
    gdl_uint32          surfaceWidth;
    gdl_uint32          surfaceHeight;
    gdl_color_t         opaque_black    = { 0xff, 0, 0, 0 };

    if ( !pImageFileName || !( *pImageFileName ) || !pSurfaceInfo )
    {
        result = GDL_ERR_INVAL;
        goto exit;
    }

    // Determine details about the specified PNG file.
    ON_ERR( exit, result=CreateImagePNG(pImageFileName,&pImagePNG) );

    // Make sure it contains an image and is not empty.
    if ( !pImagePNG || !pImagePNG->width || !pImagePNG->height )
    {
        result = GDL_ERR_FAILED;
        goto exit;
    }

    surfaceFormat = pImagePNG->pixelFormat;

    // Setup the appropriate pixel format for the surface.
    if ( force24To32 && surfaceFormat == GDL_PF_RGB_24 )
    {
        surfaceFormat = GDL_PF_RGB_32;
    }

    surfaceWidth    = pImagePNG->width;
    surfaceHeight   = pImagePNG->height;

    gdl_display_info_t di;
    if(GDL_SUCCESS == gdl_get_display_info(GDL_DISPLAY_ID_0, &di)) {
        surfaceWidth    = di.tvmode.width;
        surfaceHeight   = di.tvmode.height;
    }

    // Setup the appropriate surface width and height for the surface.
    if ( forceWidthConstraint != SIZE_CONSTRAINT_NONE )
    {
        // Make sure the width is evenly divisible by two or evenly
        // divisible by four.
        if ( forceWidthConstraint == SIZE_CONSTRAINT_MULTIPLE_OF_2 )
        {
            if ( surfaceWidth & 1 )
            {
                surfaceWidth++;
            }
        }
        else if ( forceWidthConstraint == SIZE_CONSTRAINT_MULTIPLE_OF_4 )
        {
            if ( surfaceWidth & 3 )
            {
                surfaceWidth = ( surfaceWidth & ~3 ) + 4;
            }
        }

        // Make sure the height is evenly divisible by two or evenly
        // divisible by four.
        if ( forceHeightConstraint == SIZE_CONSTRAINT_MULTIPLE_OF_2 )
        {
            if ( surfaceHeight & 1 )
            {
                surfaceHeight++;
            }
        }
        else if ( forceHeightConstraint == SIZE_CONSTRAINT_MULTIPLE_OF_4 )
        {
            if ( surfaceHeight & 3 )
            {
                surfaceHeight = ( surfaceHeight & ~3 ) + 4;
            }
        }
    }

    // Before loading image, make sure the needed surface can be created.
    ON_ERR(exit,  result= gdl_alloc_surface(surfaceFormat,
                                            surfaceWidth,
                                            surfaceHeight,
                                            surfaceFlags,
                                            &surfaceInfo ));
    surfaceCreated = GDL_TRUE;

    // Clear the surface in case it will be larger than the image being loaded.
    ON_ERR( exit, result=gdl_clear_surface(surfaceInfo.id,&opaque_black));

    // Load the main image data.
    ON_ERR( exit, result=LoadImagePNG(pImagePNG) );

    // Copy the image to the surface.
    ON_ERR( exit, result=CopyImageToSurface(pImagePNG,surfaceInfo.id));

    // Hand back a copy of the surface information.
    *pSurfaceInfo = surfaceInfo;

exit:
    // Release resources if an error occurred.
    if ( result != GDL_SUCCESS && surfaceCreated )
    {
        CHK( gdl_free_surface( surfaceInfo.id ) );
    }

    // Release PNG resources since they are now unneeded.
    if ( pImagePNG )
    {
        DestroyImagePNG( pImagePNG );
    }

    return result;
}

#if 0
//-----------------------------------------------------------------------------
gdl_ret_t CopyImageToSurface( ImagePNG *pImagePNG, gdl_surface_id_t surfaceId )
{
    gdl_ret_t           result          = GDL_SUCCESS;
    gdl_boolean_t       surfaceMapped   = GDL_FALSE;
    gdl_uint8  *        pDstBuffer;
    gdl_uint8  *        pSrcBuffer;
    gdl_uint32          sourcePitch;
    gdl_uint32          rowsLeft;
    gdl_surface_info_t  surfaceInfo;
    gdl_uint8  *        pSurfaceBuffer = NULL;

    // Validate basic parameters, image is compatible with our copy logic.
    if ( !pImagePNG
    ||   !surfaceId
    ||   !pImagePNG->width
    ||   !pImagePNG->height
    ||   (  pImagePNG->pixelFormat != GDL_PF_ARGB_32
         && pImagePNG->pixelFormat != GDL_PF_RGB_32
         && pImagePNG->pixelFormat != GDL_PF_RGB_24
         )
    ||   ( pImagePNG->bpp != 24 && pImagePNG->bpp != 32 )
    ||   !pImagePNG->pImageBuffer)
    {
        result = GDL_ERR_INVAL;
        goto exit;
    }

    // Get key information about the surface and validate that it is
    // compatible with our copy logic.

    ON_ERR( exit, result=gdl_get_surface_info(surfaceId,&surfaceInfo) );

    if ( surfaceInfo.pixel_format != GDL_PF_ARGB_32
    &&   surfaceInfo.pixel_format != GDL_PF_RGB_32
    &&   surfaceInfo.pixel_format != GDL_PF_RGB_24 )
    {
        result = GDL_ERR_SURFACE;
        goto exit;
    }

    ON_ERR( exit, result=gdl_map_surface(surfaceId,&pSurfaceBuffer,NULL) );
    surfaceMapped = GDL_TRUE;

    pDstBuffer  = pSurfaceBuffer;
    pSrcBuffer  = pImagePNG->pImageBuffer;
    sourcePitch = pImagePNG->width * (pImagePNG->bpp/8);
    rowsLeft    = _MIN(pImagePNG->height,surfaceInfo.height);

    // Copy the loaded image to the surface.  Copy as many pixels from the
    // image to the surface as possible depending upon their sizes.
    // Pixels not covered on the surface are left as they were found.
    if ( pImagePNG->pixelFormat == GDL_PF_RGB_24
    &&   (  surfaceInfo.pixel_format == GDL_PF_ARGB_32
         || surfaceInfo.pixel_format == GDL_PF_RGB_32
         ))
    {
        // Surface is 32 bpp and image is 24 bpp.

        for ( ; rowsLeft > 0; rowsLeft-- )
        {
            gdl_uint8  *pDstPixelComponent = pDstBuffer;
            gdl_uint8  *pSrcPixelComponent = pSrcBuffer;
            gdl_uint32  pixelsLeft;

            for (pixelsLeft = _MIN(pImagePNG->width, surfaceInfo.width);
                 pixelsLeft > 0;
                 pixelsLeft-- )
            {
                *pDstPixelComponent++ = *pSrcPixelComponent++;
                *pDstPixelComponent++ = *pSrcPixelComponent++;
                *pDstPixelComponent++ = *pSrcPixelComponent++;
                *pDstPixelComponent++ = 0xFF;
            }

            pDstBuffer += surfaceInfo.pitch;
            pSrcBuffer += sourcePitch;
        }
    }
    else if ((pImagePNG->pixelFormat == surfaceInfo.pixel_format)
    ||       ( pImagePNG->pixelFormat != GDL_PF_RGB_24
               && surfaceInfo.pixel_format != GDL_PF_RGB_24))
    {
        // Surface and image are either both 32 bpp or 24 bpp.
        int bytesPerRow= _MIN(pImagePNG->width, surfaceInfo.width) * (pImagePNG->bpp/8);

        for ( ; rowsLeft>0; rowsLeft--)
        {
            memcpy( pDstBuffer, pSrcBuffer, bytesPerRow );
            pDstBuffer += surfaceInfo.pitch;
            pSrcBuffer += sourcePitch;
        }
    }
    else
    {
        result = GDL_ERR_INTERNAL;
        goto exit;
    }

exit:
    // Unmap the surface now that we're finished with it.  Result is not
    // checked so as to not override another failure if there's one.
    if ( surfaceId && surfaceMapped)
    {
        CHK( gdl_unmap_surface( surfaceId ) );
    }

    return result;
}
#else
static gma_ret_t destroy_malloc_pixmap(gma_pixmap_info_t *pixmap_info) {
    if(pixmap_info->user_data) free(pixmap_info->user_data);
    return GMA_SUCCESS;
} // destroy_malloc_pixmap

gdl_ret_t CopyImageToSurface( ImagePNG *pImagePNG, gdl_surface_id_t surfaceId ) {
    srb_context_t srb_cnt = NULL;
    srb_context_t dst_hdl = NULL;
    srb_context_t src_hdl = NULL;
    gma_pixmap_t  src_pix = NULL;
    srb_blit_info_t blit_info = {0};
    gdl_surface_info_t  surface_info;
    gma_pixmap_info_t pixmap_info;
    
    memset(&pixmap_info, 0, sizeof(pixmap_info));
    pixmap_info.type      = GMA_PIXMAP_TYPE_VIRTUAL;
    pixmap_info.virt_addr = pImagePNG->pImageBuffer;
    pixmap_info.width     = pImagePNG->width;
    pixmap_info.height    = pImagePNG->height;
    pixmap_info.pitch     = pImagePNG->width * pImagePNG->bpp/8;

    switch(pImagePNG->pixelFormat) {
        /* RGB types */
        case GDL_PF_ARGB_32:         ///< ARGB 32bpp 8:8:8:8  LE
            pixmap_info.format = GMA_PF_ARGB_32;
            break;
        case GDL_PF_RGB_32:          ///< xRGB 32bpp x:8:8:8  LE
            pixmap_info.format = GMA_PF_RGB_32;
            break;
        case GDL_PF_ARGB_16_1555:    ///< ARGB 16bpp 1:5:5:5  LE
            pixmap_info.format = GMA_PF_ARGB_16_1555;
            break;
        case GDL_PF_ARGB_16_4444:    ///< ARGB 16bpp 4:4:4:4  LE
            pixmap_info.format = GMA_PF_ARGB_16_4444;
            break;
        case GDL_PF_RGB_16:          ///<  RGB 16bpp 5:6:5    LE
            pixmap_info.format = GMA_PF_RGB_16;
            break;
        case GDL_PF_NV16:            ///< YUV 4:2:2 Pseudo-planar
            pixmap_info.format = GMA_PF_NV16;
            break;
        case GDL_PF_A8:              ///< 8-bit Alpha-only surface
            pixmap_info.format = GMA_PF_A8;
            break;
        case GDL_PF_AY16:            ///< Alpha-luminance 8:8. Used for video textures
            pixmap_info.format = GMA_PF_AY16;
            break;
        default:
            printf("Image pixel format %d not handled!\n", pImagePNG->pixelFormat);
            return GDL_ERR_INVAL;
    } // switch
    pixmap_info.user_data = NULL;

    static gma_pixmap_funcs_t malloc_pixmap_funcs;
    malloc_pixmap_funcs.destroy = destroy_malloc_pixmap;

    cache_flush_buffer(pixmap_info.virt_addr, pixmap_info.pitch*pixmap_info.height);
    ON_ERR(exit, gdl_get_surface_info(surfaceId, &surface_info) );
    ON_ERR(exit, srb_alloc_context(0, &srb_cnt));
    ON_ERR(exit, srb_attach_surface(&srb_cnt, surfaceId, &dst_hdl));

    if(GMA_SUCCESS!=gma_pixmap_alloc(&pixmap_info, &malloc_pixmap_funcs, &src_pix)) goto exit;
    ON_ERR(exit, srb_attach_pixmap (&srb_cnt, src_pix, &src_hdl));
                                                                                                                                                                                                                                                                                                                                                         src_pix = NULL;
    blit_info.src_surface_handle  = &src_hdl;
    blit_info.dest_surface_handle = &dst_hdl;
    blit_info.src_rect.origin.x   = 0;
    blit_info.src_rect.origin.y   = 0;
    blit_info.src_rect.width      = pixmap_info.width;
    blit_info.src_rect.height     = pixmap_info.height;

#ifdef KEEP_ASPECT    
    if(surface_info.width*pixmap_info.height/pixmap_info.width > surface_info.height) {
        blit_info.dest_rect.width     = surface_info.width*pixmap_info.height/pixmap_info.width;
        blit_info.dest_rect.height    = surface_info.height;
    } else {
        blit_info.dest_rect.width     = surface_info.width;
        blit_info.dest_rect.height    = surface_info.height*pixmap_info.width/pixmap_info.height;
    } // if
    blit_info.dest_rect.origin.x  = (surface_info.width -blit_info.dest_rect.width )/2;
    blit_info.dest_rect.origin.y  = (surface_info.height-blit_info.dest_rect.height)/2;
#else
    blit_info.dest_rect.width     = surface_info.width;
    blit_info.dest_rect.height    = surface_info.height;
    blit_info.dest_rect.origin.x  = 0;
    blit_info.dest_rect.origin.y  = 0;
#endif
    blit_info.clip_rect           = blit_info.dest_rect;
    blit_info.blend.flags         = SRB_BLEND_ENABLE_BLEND_EQUATION;
    blit_info.blend.src_rgb       = SRB_BLEND_FUNC_ONE;
    blit_info.blend.src_alpha     = SRB_BLEND_FUNC_ONE;
    blit_info.blend.dest_rgb      = SRB_BLEND_FUNC_ZERO;
    blit_info.blend.dest_alpha    = SRB_BLEND_FUNC_ZERO;
    blit_info.filter              = SRB_FILTER_LINEAR;

    printf("blit %dx%d to %dx%d at %dx%d\n", blit_info.src_rect.width, blit_info.src_rect.height, blit_info.dest_rect.width, blit_info.dest_rect.height, blit_info.dest_rect.origin.x, blit_info.dest_rect.origin.y);
    ON_ERR(exit, srb_blit(&srb_cnt, &blit_info));
    ON_ERR(exit, srb_wait(&srb_cnt, blit_info.dest_surface_handle));
//    ON_ERR(exit, gdl_flip (ICE_OSD_PLANE, surface_info.id, GDL_FLIP_ASYNC));

exit:
    if(src_hdl) srb_detach_surface(&srb_cnt, &src_hdl);
    if(src_pix) gma_pixmap_release(&src_pix);
    if(dst_hdl) srb_detach_surface(&srb_cnt, &dst_hdl);
    if(srb_cnt) srb_free_context(&srb_cnt);
    return GDL_SUCCESS;
} // CopyImageToSurface
#endif
//-----------------------------------------------------------------------------
gdl_ret_t CopySurfaceRGBToYUV(
                gdl_surface_id_t    surfaceIdRGB,
                gdl_boolean_t       progressive,
                gdl_surface_id_t    surfaceIdYUV )
{
    #define _RGB_TO_Y( red, green, blue )                                   \
                ( ( ( premultiplyRToY[ red ] +                      \
                      premultiplyGToY[ green ] +                    \
                      premultiplyBToY[ blue ] + 128 ) >> 8 ) +  16 )

    #define _RGB_TO_U( red, green, blue )                                   \
                ( ( ( premultiplyRToU[ red ] +                      \
                      premultiplyGToU[ green ] +                    \
                      premultiplyBToU[ blue ] + 128 ) >> 8 ) + 128 )

    #define _RGB_TO_V( red, green, blue )                                   \
                ( ( ( premultiplyRToV[ red ] +                      \
                      premultiplyGToV[ green ] +                    \
                      premultiplyBToV[ blue ] + 128 ) >> 8 ) + 128 )

    static gdl_boolean_t    premultiplyTablesInitialized  = GDL_FALSE;
    static gdl_int32        premultiplyRToY[ 256 ];
    static gdl_int32        premultiplyGToY[ 256 ];
    static gdl_int32        premultiplyBToY[ 256 ];
    static gdl_int32        premultiplyRToU[ 256 ];
    static gdl_int32        premultiplyGToU[ 256 ];
    static gdl_int32        premultiplyBToU[ 256 ];
    static gdl_int32        premultiplyRToV[ 256 ];
    static gdl_int32        premultiplyGToV[ 256 ];
    static gdl_int32        premultiplyBToV[ 256 ];

    gdl_ret_t               result      = GDL_SUCCESS;
    gdl_boolean_t           mappedRGB   = GDL_FALSE;
    gdl_boolean_t           mappedYUV   = GDL_FALSE;
    gdl_boolean_t           format422   = GDL_FALSE;
    gdl_pixel_format_t      formatYUV   = GDL_PF_COUNT; // No format defined yet

    gdl_uint32              widthRGB    = 0;
    gdl_uint32              heightRGB   = 0;
    gdl_uint32              bitCountRGB = 0;
    gdl_uint32              pitchRGB    = 0;
    gdl_uint32              widthYUV    = 0;
    gdl_uint32              heightYUV   = 0;
    gdl_uint32              pitchYUV    = 0;
    gdl_uint32              pitchY      = 0;
    gdl_uint32              pitchUV     = 0;
    gdl_uint8              *pBuffer    = NULL;
    gdl_uint8              *pBufferRGB = NULL;
    gdl_uint8              *pBufferYUV = NULL;
    gdl_uint8              *pBufferY   = NULL;
    gdl_uint8              *pBufferU   = NULL;
    gdl_uint8              *pBufferV   = NULL;
    gdl_uint8              *pBufferUV  = NULL;

    gdl_surface_info_t      surfaceInfoRGB;
    gdl_surface_info_t      surfaceInfoYUV;

    // Setup RGB to YUV conversion helper tables to speed up the process if
    // they have not already been setup.
    if ( !premultiplyTablesInitialized )
    {
        gdl_uint32  i;

        for (i=0; i < 256; i++)
        {
            premultiplyBToU[i] = i * 112;
            premultiplyBToV[i] = i * -18;
            premultiplyBToY[i] = i *  25;
            premultiplyGToU[i] = i * -74;
            premultiplyGToV[i] = i * -94;
            premultiplyGToY[i] = i * 129;
            premultiplyRToU[i] = i * -38;
            premultiplyRToV[i] = i * 112;
            premultiplyRToY[i] = i *  65;
        }

        premultiplyTablesInitialized = GDL_TRUE;
    }

    // Make sure valid parameters were specified.
    if ( !(surfaceIdRGB && surfaceIdYUV) )
    {
        result = GDL_ERR_INVAL;
        goto exit;
    }

    // Validate that the source surface is a 24 bpp RGB or 32 bpp
    // ARGB/XRGB and get key data, including a pointer to the pixels.  In
    // addition, make sure it is compatible with our copy logic and store
    // needed details.
    ON_ERR( exit, result=gdl_get_surface_info(surfaceIdRGB,&surfaceInfoRGB) );

    if ( (surfaceInfoRGB.width & 1)
    ||   (surfaceInfoRGB.height & 3)
    ||   (surfaceInfoRGB.pixel_format   != GDL_PF_ARGB_32
         && surfaceInfoRGB.pixel_format != GDL_PF_RGB_32
         && surfaceInfoRGB.pixel_format != GDL_PF_RGB_24
         ))
    {
        result = GDL_ERR_SURFACE;
        goto exit;
    }

    ON_ERR( exit, result=gdl_map_surface(surfaceIdRGB, &pBufferRGB, NULL) );
    mappedRGB = GDL_TRUE;

    if ( !pBufferRGB )
    {
        result = GDL_ERR_INTERNAL;
        goto exit;
    }

    widthRGB    = surfaceInfoRGB.width;
    heightRGB   = surfaceInfoRGB.height;
    bitCountRGB = surfaceInfoRGB.pixel_format==GDL_PF_RGB_24 ? 24 : 32;
    pitchRGB    = surfaceInfoRGB.pitch;

    ON_ERR( exit, result=gdl_get_surface_info(surfaceIdYUV,&surfaceInfoYUV) );

    if ((surfaceInfoYUV.width & 1) || (surfaceInfoYUV.height & 3))
    {
        result = GDL_ERR_SURFACE;
        goto exit;
    }

    ON_ERR( exit, result=gdl_map_surface(surfaceIdYUV,&pBuffer,NULL) );
    mappedYUV = GDL_TRUE;

    widthYUV    = surfaceInfoYUV.width;
    heightYUV   = surfaceInfoYUV.height;
    formatYUV   = surfaceInfoYUV.pixel_format;

    switch ( formatYUV )
    {
    case GDL_PF_YUY2:
    case GDL_PF_UYVY:
    case GDL_PF_YVYU:
    case GDL_PF_VYUY:
        // Packed 16 bpp YUV 4:2:2 format.
        format422   = GDL_TRUE;
        pitchYUV    = surfaceInfoYUV.pitch;
        pBufferYUV  = pBuffer;
        break;
    case GDL_PF_I422:
        // Planar 16 bpp YUV format that starts with an NxM 8-bit Y plane,
        // followed by (N/2)x(M) 8-bit U and 8-bit V planes (2x1 subsampled).
        format422   = GDL_TRUE;
        pitchY      = surfaceInfoYUV.pitch;
        pitchUV     = surfaceInfoYUV.uv_pitch;
        pBufferY    = pBuffer;
        pBufferU    = pBufferY + surfaceInfoYUV.u_offset;
        pBufferV    = pBufferY + surfaceInfoYUV.v_offset;
        break;
    case GDL_PF_YV16:
        // Planar 16 bpp YUV format that starts with an NxM 8-bit Y plane,
        // followed by (N/2)x(M) 8-bit V and 8-bit U planes (2x1 subsampled).
        format422   = GDL_TRUE;
        pitchY      = surfaceInfoYUV.pitch;
        pitchUV     = surfaceInfoYUV.uv_pitch;
        pBufferY    = pBuffer;
        pBufferV    = pBufferY + surfaceInfoYUV.v_offset;
        pBufferU    = pBufferY + surfaceInfoYUV.u_offset;
        break;
    case GDL_PF_NV16:
        // Pseudo-planar 16 bpp YUV 4:2:2 format that starts with an NxM 8-bit
        // Y plane, followed by (N/2)x(M) packed 8-bit U and 8-bit V plane
        // (2x1 subsampled).
        format422   = GDL_TRUE;
        pitchY      = surfaceInfoYUV.pitch;
        pitchUV     = surfaceInfoYUV.uv_pitch;
        pBufferY    = pBuffer;
        pBufferUV   = pBufferY + surfaceInfoYUV.u_offset;
        break;
    case GDL_PF_I420:
        // Planar 12 bpp YUV format starting with NxM 8-bit Y plane followed by
        // (N/2)x(M/2) 8-bit U and 8-bit V planes (2x2 subsampled).
        format422   = GDL_FALSE;
        pitchY      = surfaceInfoYUV.pitch;
        pBufferY    = pBuffer;
        #if 1
            pitchUV     = surfaceInfoYUV.uv_pitch;
            pBufferU    = pBufferY + surfaceInfoYUV.u_offset;
            pBufferV    = pBufferY + surfaceInfoYUV.v_offset;
        #else
            // When not specified, their pitch is half the Y pitch.
            pitchUV     = pitchY / 2;
            pBufferU    = pBufferY + ( heightYUV * pitchY );
            pBufferV    = pBufferU + ( ( heightYUV / 2 ) * pitchUV );
        #endif
        break;
    case GDL_PF_YV12:
        // Planar 12 bpp YUV format starting with NxM 8-bit Y plane,followed by
        // (N/2)x(M/2) 8-bit V and 8-bit U planes (2x2 subsampled).
        format422   = GDL_FALSE;
        pitchY      = surfaceInfoYUV.pitch;
        pBufferY    = pBuffer;
        #if 1
            pitchUV     = surfaceInfoYUV.uv_pitch;
            pBufferV    = pBufferY + surfaceInfoYUV.v_offset;
            pBufferU    = pBufferY + surfaceInfoYUV.u_offset;
        #else
            // When not specified, their pitch is half the Y pitch.
            pitchUV     = pitchY / 2;
            pBufferV    = pBufferY + ( heightYUV * pitchY );
            pBufferU    = pBufferV + ( ( heightYUV / 2 ) * pitchUV );
        #endif
        break;
    case GDL_PF_NV12:
        // Planar 12 bpp YUV format starting with NxM 8-bit Y plane, followed by
        // (N/2)x(M/2) packed 8-bit U and 8-bit V plane (2x2 subsampled).
        format422   = GDL_FALSE;
        pitchY      = surfaceInfoYUV.pitch;
        pBufferY    = pBuffer;
        pitchUV     = surfaceInfoYUV.uv_pitch;
        pBufferUV   = pBufferY + surfaceInfoYUV.u_offset;
        break;
    default:
        result = GDL_ERR_SURFACE;
        goto exit;
    }

    // Copy the entire RGB surface to the YUV surface, or just the portion that
    // fits (both anchored in the upper-left corner).  For simplicity, handle
    // YUV 4:2:2 formats first, then separately handle YUV 4:2:0 formats.
    if ( format422 )
    {
        gdl_uint8   *pDstBufferYUV  = pBufferYUV;
        gdl_uint8   *pDstBufferY    = pBufferY;
        gdl_uint8   *pDstBufferUV   = pBufferUV;
        gdl_uint8   *pDstBufferU    = pBufferU;
        gdl_uint8   *pDstBufferV    = pBufferV;
        gdl_uint8   *pSrcBuffer     = pBufferRGB;
        int          rowsLeft;
        
        for ( rowsLeft = _MIN(heightRGB,heightYUV); rowsLeft > 0; rowsLeft-- )
        {
            gdl_uint8  *pDstPixelComponentYUV  = pDstBufferYUV;
            gdl_uint8  *pDstPixelComponentY    = pDstBufferY;
            gdl_uint8  *pDstPixelComponentUV   = pDstBufferUV;
            gdl_uint8  *pDstPixelComponentU    = pDstBufferU;
            gdl_uint8  *pDstPixelComponentV    = pDstBufferV;
            gdl_uint8  *pSrcPixelComponent     = pSrcBuffer;
            gdl_uint32  pixelsLeft             =_MIN(widthRGB,widthYUV);
            gdl_uint32  microPixelCount        = 0;
            gdl_uint32  rMicroPixelList[_NPIX];
            gdl_uint32  gMicroPixelList[_NPIX];
            gdl_uint32  bMicroPixelList[_NPIX];

            while ( pixelsLeft )
            {
                // Obtain the RGB components.
                bMicroPixelList[microPixelCount] = *pSrcPixelComponent++;
                gMicroPixelList[microPixelCount] = *pSrcPixelComponent++;
                rMicroPixelList[microPixelCount] = *pSrcPixelComponent++;

                // Advance past unused alpha component if it exists.
                if ( bitCountRGB == 32 )
                {
                    ++pSrcPixelComponent;
                }

                ++microPixelCount;
                --pixelsLeft;

                // Create and store a YUV macropixel if there are enough
                // micropixels or there are none left.
                if ((microPixelCount == _NPIX) || !pixelsLeft )
                {
                    // Since only a single micropixel is available, set a
                    // second to black for storing in the Y1 component.
                    if ( microPixelCount < _NPIX )
                    {
                        rMicroPixelList[_NPIX-1] = 0;
                        gMicroPixelList[_NPIX-1] = 0;
                        bMicroPixelList[_NPIX-1] = 0;
                    }

                    // Calculate the YCbCb YUV components.
                    gdl_uint8 y0Component= gdl_uint8( _RGB_TO_Y(
                                                        rMicroPixelList[0],
                                                        gMicroPixelList[0],
                                                        bMicroPixelList[0]));
                    gdl_uint8 y1Component= gdl_uint8( _RGB_TO_Y(
                                                        rMicroPixelList[1],
                                                        gMicroPixelList[1],
                                                        bMicroPixelList[1]));
                    gdl_uint8 uComponent = gdl_uint8( _RGB_TO_U(
                                                        rMicroPixelList[0],
                                                        gMicroPixelList[0],
                                                        bMicroPixelList[0]));
                    gdl_uint8 vComponent = gdl_uint8( _RGB_TO_V(
                                                        rMicroPixelList[0],
                                                        gMicroPixelList[0],
                                                        bMicroPixelList[0]));

                    // Store the YUV components based on the desired format.
                    switch ( formatYUV )
                    {
                        // YUV 4:2:2 (U & V sampled once for every two Y on
                        // horizontal on every line) formats.

                    case GDL_PF_YUY2:
                            // GDL_PF_YUY2: 16 bpp, 0xV0Y1U0Y0.
                            *pDstPixelComponentYUV++ = y0Component;
                            *pDstPixelComponentYUV++ = uComponent;
                            *pDstPixelComponentYUV++ = y1Component;
                            *pDstPixelComponentYUV++ = vComponent;
                            break;

                    case GDL_PF_UYVY:
                            // GDL_PF_UYVY: 16 bpp, 0xY1V0Y0U0.
                            *pDstPixelComponentYUV++ = uComponent;
                            *pDstPixelComponentYUV++ = y0Component;
                            *pDstPixelComponentYUV++ = vComponent;
                            *pDstPixelComponentYUV++ = y1Component;
                            break;

                    case GDL_PF_YVYU:
                            // GDL_PF_YVYU: 16 bpp, 0xU0Y1V0Y0.
                            *pDstPixelComponentYUV++ = y0Component;
                            *pDstPixelComponentYUV++ = vComponent;
                            *pDstPixelComponentYUV++ = y1Component;
                            *pDstPixelComponentYUV++ = uComponent;
                            break;

                    case GDL_PF_VYUY:
                            // GDL_PF_VYUY: 16 bpp, 0xV0Y0U0Y1.
                            *pDstPixelComponentYUV++ = vComponent;
                            *pDstPixelComponentYUV++ = y0Component;
                            *pDstPixelComponentYUV++ = uComponent;
                            *pDstPixelComponentYUV++ = y1Component;
                            break;

                    case GDL_PF_I422:
                            // GDL_PF_I422: 16 bpp, 0xY0Y1 0xU0 0xV0.
                            *pDstPixelComponentY++ = y0Component;
                            *pDstPixelComponentY++ = y1Component;
                            *pDstPixelComponentU++ = uComponent;
                            *pDstPixelComponentV++ = vComponent;
                            break;

                    case GDL_PF_YV16:
                            // GDL_PF_YV16: 16 bpp, 0xY0Y1 0xV0 0xU0.
                            *pDstPixelComponentY++ = y0Component;
                            *pDstPixelComponentY++ = y1Component;
                            *pDstPixelComponentV++ = vComponent;
                            *pDstPixelComponentU++ = uComponent;
                            break;

                    case GDL_PF_NV16:
                            // GDL_PF_NV16: 16 bpp, 0xY0Y1 0xU0V0.
                            *pDstPixelComponentY++  = y0Component;
                            *pDstPixelComponentY++  = y1Component;
                            *pDstPixelComponentUV++ = uComponent;
                            *pDstPixelComponentUV++ = vComponent;
                            break;
                    default: ON_ERR(exit, GDL_ERR_INVAL);
                    }

                    // Reset the micropixel count for the next pair.
                    microPixelCount = 0;
                }
            }

            // Advance to the next row.
            switch ( formatYUV )
            {
            case GDL_PF_YUY2:
            case GDL_PF_UYVY:
            case GDL_PF_YVYU:
            case GDL_PF_VYUY:
                pDstBufferYUV   += pitchYUV;
                break;
            case GDL_PF_I422:
            case GDL_PF_YV16:
                pDstBufferY     += pitchY;
                pDstBufferU     += pitchUV;
                pDstBufferV     += pitchUV;
                break;
            case GDL_PF_NV16:
                pDstBufferY     += pitchY;
                pDstBufferUV    += pitchUV;
                break;
            default: ON_ERR(exit, GDL_ERR_INVAL);
            }

            pSrcBuffer += pitchRGB;
        }
    }
    else // !format422
    {
        gdl_uint32  rowCount    = _MIN( heightRGB, heightYUV );
        gdl_uint32  pixelCount  = _MIN( widthRGB, widthYUV );
        gdl_uint32  fieldCount  = _MIN(rowCount, (unsigned)(progressive?1:2));
        gdl_uint32  horzBlockCount = (pixelCount+1) / _NPIX;
        gdl_uint32  field;

        // To aid conversion, when converting to the YUV 4:2:0 format iterate
        // over each available field to prevent any Chroma Upsampling Errors
        // (CUE).
        for (field = 0; field < fieldCount; field++)
        {
            gdl_uint32  microFirstRowFactor;
            gdl_uint32  microSecondRowFactor;

            // To aid in calculating U and V components, setup the weightings
            // that should be used with a block's rows.

            if ( progressive )
            {
                microFirstRowFactor = _MAX_FACTOR / 2;          // 50%
            }
            else if ( field )
            {
                microFirstRowFactor = _MAX_FACTOR / 4;          // 25%
            }
            else
            {
                microFirstRowFactor = ( _MAX_FACTOR / 4 ) * 3;  // 75%
            }

            microSecondRowFactor = _MAX_FACTOR - microFirstRowFactor;

            // Determine how many rows to skip to advance to the first row
            // that's used in the next block.  Also determine the number of
            // vertical block rows to generate on this pass over the source buffer.
            gdl_uint32  rowsToSkipPerBlock  = fieldCount * _NROW;
            gdl_uint32  verticalBlockCount  =
                (rowCount + rowsToSkipPerBlock - 1 - field) / rowsToSkipPerBlock;
            gdl_uint32  verticalBlock;

            for (verticalBlock=0; verticalBlock<verticalBlockCount; verticalBlock++)
            {
                gdl_uint8 *pDstBufferY =
                    pBufferY + (pitchY * ((verticalBlock * rowsToSkipPerBlock) + field));

                gdl_uint8 *pDstBufferNextRowY = pDstBufferY+(pitchY*fieldCount);
                gdl_uint8 *pDstBufferU    = NULL;
                gdl_uint8 *pDstBufferV    = NULL;
                gdl_uint8 *pDstBufferUV   = NULL;

                gdl_uint8 *pSrcBufferRGB  =
                    pBufferRGB + (pitchRGB * ((verticalBlock *rowsToSkipPerBlock) + field));

                gdl_uint8 *pSrcBufferRGBNextRow =
                    pSrcBufferRGB+ (pitchRGB * fieldCount);

                gdl_uint32  horzBlock;

                // Are the U and V component stored in the same plane or
                // different ones?

                gdl_uint32 increment = pitchUV * ((verticalBlock*fieldCount) + field);
                if ( pBufferUV )
                {
                    pDstBufferUV = pBufferUV + increment;
                }
                else
                {
                    pDstBufferU = pBufferU + increment;
                    pDstBufferV = pBufferV + increment;
                }

                for ( horzBlock = 0; horzBlock < horzBlockCount; horzBlock++)
                {
                    gdl_uint32  rComponentBlock[_NROW][_NPIX];
                    gdl_uint32  gComponentBlock[_NROW][_NPIX];
                    gdl_uint32  bComponentBlock[_NROW][_NPIX];
                    gdl_uint32  microRowIndex;

                    // Obtain the RGB components for all pixels in this block.
                    // Also calculate and store the associated Y component for
                    // each pixel.
                    
                    for (microRowIndex=0; microRowIndex < _NROW; microRowIndex++)
                    {
                        gdl_uint8 **ppDstBuffer;
                        gdl_uint8 **ppSrcBufferComponent;
                        gdl_uint32  microPixelIndex;

                        if ( microRowIndex )
                        {
                            ppDstBuffer           = &pDstBufferNextRowY;
                            ppSrcBufferComponent  = &pSrcBufferRGBNextRow;
                        }
                        else
                        {
                            ppDstBuffer           = &pDstBufferY;
                            ppSrcBufferComponent  = &pSrcBufferRGB;
                        }

                        for (microPixelIndex=0; microPixelIndex<_NPIX; microPixelIndex++)
                        {
                            bComponentBlock[microRowIndex][microPixelIndex] =
                                                    **ppSrcBufferComponent;
                            ++( *ppSrcBufferComponent );

                            gComponentBlock[microRowIndex][microPixelIndex] =
                                                    **ppSrcBufferComponent;
                            ++( *ppSrcBufferComponent );

                            rComponentBlock[microRowIndex][microPixelIndex] =
                                                    **ppSrcBufferComponent;
                            ++( *ppSrcBufferComponent );

                            if ( bitCountRGB == 32 )
                            {
                                ++( *ppSrcBufferComponent );
                            }

                            **ppDstBuffer = gdl_uint8( _RGB_TO_Y(
                                rComponentBlock[microRowIndex][microPixelIndex],
                                gComponentBlock[microRowIndex][microPixelIndex],
                                bComponentBlock[microRowIndex][microPixelIndex]
                                ) );
                            ++( *ppDstBuffer );
                        }
                    }

                    // Calculate the RGB value that will be used to generate
                    // the U and V components.  It is based on if the content
                    // is progressive or interlaced and the current field.
                    gdl_uint32  r;
                    gdl_uint32  g;
                    gdl_uint32  b;

                    r  = ((rComponentBlock[0][0] * microFirstRowFactor)
                           + (rComponentBlock[1][0] * microSecondRowFactor))
                          / _MAX_FACTOR;
                    g  = ((gComponentBlock[0][0] * microFirstRowFactor )
                            + ( gComponentBlock[1][0] * microSecondRowFactor))
                         / _MAX_FACTOR;
                    b  = ((bComponentBlock[0][0] * microFirstRowFactor)
                            + ( bComponentBlock[1][0] * microSecondRowFactor))
                         / _MAX_FACTOR;

                    // Calculate the U and V components.
                    gdl_uint8 u = _RGB_TO_U(r,g,b);
                    gdl_uint8 v = _RGB_TO_V(r,g,b);

                    // Store the U and V components.
                    if ( pDstBufferUV )
                    {
                        *pDstBufferUV++ = u;
                        *pDstBufferUV++ = v;
                    }
                    else
                    {
                        *pDstBufferU++ = u;
                        *pDstBufferV++ = v;
                    }
                }
            }
        }
    }
exit:
    // Unmap surfaces now that we're finished with them.  Results are not
    // checked so as to not override another failure if there's one.

    if ( surfaceIdYUV && mappedYUV )
    {
        CHK( gdl_unmap_surface( surfaceIdYUV  ) );
    }

    if ( surfaceIdRGB && mappedRGB )
    {
        CHK( gdl_unmap_surface( surfaceIdRGB ) );
    }

    return result;
}

//-----------------------------------------------------------------------------
static int isYUV(gdl_pixel_format_t pf)
{
    return (pf == GDL_PF_YUY2)
        || (pf == GDL_PF_UYVY)
        || (pf == GDL_PF_YVYU)
        || (pf == GDL_PF_VYUY)
        || (pf == GDL_PF_I422)
        || (pf == GDL_PF_YV16)
        || (pf == GDL_PF_NV16)
        || (pf == GDL_PF_I420)
        || (pf == GDL_PF_YV12)
        || (pf == GDL_PF_NV12);
}

//-----------------------------------------------------------------------------
static int isValidRect( gdl_rectangle_t *   rect,
                        gdl_pixel_format_t  pf,
                        gdl_uint32          maxWidth,
                        gdl_uint32          maxHeight
                        )
{
    if ( (rect->width == 0)
    ||   (rect->width & 1)
    ||   (rect->width > maxWidth)
    ||   (rect->height == 0)
    ||   (rect->height & 3)
    ||   (rect->height > maxHeight)
    ||   (rect->origin.x & 1)
    ||   ((pf == GDL_PF_I422 || pf == GDL_PF_YV16 || pf == GDL_PF_NV16)
          && (rect->origin.y & 1))
    ||   ((pf == GDL_PF_I420 || pf == GDL_PF_YV12 || pf == GDL_PF_NV12)
          && (rect->origin.y & 3))
    ){
        return 0;
    }
    return 1;
}



//-----------------------------------------------------------------------------
gdl_ret_t CopySurfaceYUVToYUV(
                gdl_surface_id_t    surfaceSrcId,
                gdl_rectangle_t*    pRectSrc,
                gdl_surface_id_t    surfaceDstId,
                gdl_rectangle_t*    pRectDst )
{
    gdl_ret_t           result      = GDL_SUCCESS;
    gdl_boolean_t       mappedSrc   = GDL_FALSE;
    gdl_boolean_t       mappedDst   = GDL_FALSE;
    gdl_boolean_t       format422   = GDL_FALSE;
    gdl_surface_info_t  surfaceInfoSrc;
    gdl_surface_info_t  surfaceInfoDst;
    gdl_pixel_format_t  formatYUV;

    gdl_uint32      pitchSrcYUV     = 0;
    gdl_uint32      pitchSrcY       = 0;
    gdl_uint32      pitchSrcUV      = 0;
    gdl_uint32      pitchDstYUV     = 0;
    gdl_uint32      pitchDstY       = 0;
    gdl_uint32      pitchDstUV      = 0;
    gdl_uint8      *pBufferSrcYUV   = NULL;
    gdl_uint8      *pBufferSrcY     = NULL;
    gdl_uint8      *pBufferSrcU     = NULL;
    gdl_uint8      *pBufferSrcV     = NULL;
    gdl_uint8      *pBufferSrcUV    = NULL;
    gdl_uint8      *pBufferDstYUV   = NULL;
    gdl_uint8      *pBufferDstY     = NULL;
    gdl_uint8      *pBufferDstU     = NULL;
    gdl_uint8      *pBufferDstV     = NULL;
    gdl_uint8      *pBufferDstUV    = NULL;
    gdl_uint32      bytesPerRowYUV  = 0;
    gdl_uint32      bytesPerRowY    = 0;
    gdl_uint32      bytesPerRowUOrV = 0;
    gdl_uint32      bytesPerRowUV   = 0;
    gdl_uint32      bppY;
    gdl_uint32      bppYUV;
    gdl_uint32      bytesPerBlockUOrV;
    gdl_uint32      bytesPerBlockUV;
    gdl_rectangle_t rect;


    // Validate basic parameters.
    if ( !surfaceSrcId || !surfaceDstId || surfaceSrcId == surfaceDstId )
    {
        result = GDL_ERR_INVAL;
        goto exit;
    }

    // Get key information about the source surface and validate that it
    // is compatible with our copy logic.

    ON_ERR( exit, result=gdl_get_surface_info(surfaceSrcId, &surfaceInfoSrc) );
    formatYUV = surfaceInfoSrc.pixel_format;

    if ((surfaceInfoSrc.width & 1)
    ||  (surfaceInfoSrc.height & 3)
    ||  !isYUV(surfaceInfoSrc.pixel_format))
    {
        result = GDL_ERR_SURFACE;
        goto exit;
    }

    gdl_rectangle_t rectSrcDefault;

    // If a source rectangle was not specified, set one up that is the
    // entire source surface.
    if ( !pRectSrc )
    {
        rectSrcDefault.origin.x = 0;
        rectSrcDefault.origin.y = 0;
        rectSrcDefault.width    = surfaceInfoSrc.width;
        rectSrcDefault.height   = surfaceInfoSrc.height;
        pRectSrc                = &rectSrcDefault;
    }

    // Validate the source rectangle.
    if (!isValidRect( pRectSrc,
                      surfaceInfoSrc.pixel_format,
                      surfaceInfoSrc.width,
                      surfaceInfoSrc.height))
    {
        result = GDL_ERR_INVAL;
        goto exit;
    }

    // Map the source surface to get a pointer to its pixels.
    gdl_uint8   *pBufferSrc;
    ON_ERR( exit, result=gdl_map_surface(surfaceSrcId, &pBufferSrc, NULL) );
    mappedSrc = GDL_TRUE;

    // Get key information about the destination surface and validate that
    // it is compatible with our copy logic.

    ON_ERR( exit, result=gdl_get_surface_info(surfaceDstId, &surfaceInfoDst) );

    if ((surfaceInfoDst.width  & 1)
    ||  (surfaceInfoDst.height & 3)
    ||  (surfaceInfoDst.pixel_format != surfaceInfoSrc.pixel_format))
    {
        result = GDL_ERR_SURFACE;
        goto exit;
    }

    // If a destination rectangle was not specified, set one up that is
    // the entire destination surface.
    if ( !pRectDst )
    {
        rect.origin.x = 0;
        rect.origin.y = 0;
        rect.width    = surfaceInfoDst.width;
        rect.height   = surfaceInfoDst.height;
        pRectDst      = &rect;
    }

    // Validate the destination rectangle.
    if (!isValidRect( pRectDst,
                      surfaceInfoDst.pixel_format,
                      surfaceInfoDst.width,
                      surfaceInfoDst.height)
    || (pRectDst->width  != pRectSrc->width)
    || (pRectDst->height != pRectSrc->height)
    || ((pRectDst->origin.x + pRectDst->width)  > surfaceInfoDst.width)
    || ((pRectDst->origin.y + pRectDst->height) > surfaceInfoDst.height)
    )
    {
        result = GDL_ERR_INVAL;
        goto exit;
    }

    // Map destination surface to get a pointer to its pixels.
    gdl_uint8   *pBufferDst;
    ON_ERR( exit, result=gdl_map_surface(surfaceDstId, &pBufferDst, NULL) );
    mappedDst = GDL_TRUE;

    // Extract details regarding the YUV source and destination surfaces
    // and prepare everything needed for the general copying loops.  This
    // even includes calculating the pointers to the upper-left corner
    // pixel of the rectangle on the surfaces and how many bytes of data
    // to copy per row.
    
    switch (formatYUV)
    {
    case GDL_PF_YUY2:
    case GDL_PF_UYVY:
    case GDL_PF_YVYU:
    case GDL_PF_VYUY:
        // Packed 16 bpp YUV 4:2:2 format.
        bppYUV          = sizeof(gdl_uint8) * 2;
        format422       = GDL_TRUE;
        pitchSrcYUV     = surfaceInfoSrc.pitch;
        pBufferSrcYUV   = pBufferSrc + (pRectSrc->origin.y * pitchSrcYUV)
                            + (pRectSrc->origin.x * bppYUV);
        pitchDstYUV     = surfaceInfoDst.pitch;
        pBufferDstYUV   = pBufferDst + (pRectDst->origin.y * pitchDstYUV)
                            + (pRectDst->origin.x * bppYUV);
        bytesPerRowYUV  = pRectSrc->width * bppYUV;
        break;
    case GDL_PF_I422:
        // Planar 16 bpp YUV format that starts with an NxM 8-bit Y plane,
        // followed by (N/2)x(M) 8-bit U and 8-bit V planes (2x1
        // subsampled).

        bppY                = sizeof( gdl_uint8 );
        bytesPerBlockUOrV   = sizeof( gdl_uint8 );

        format422   = GDL_TRUE;
        pitchSrcY   = surfaceInfoSrc.pitch;
        pitchSrcUV  = surfaceInfoSrc.uv_pitch;
        pBufferSrcY = pBufferSrc
                        + ( pRectSrc->origin.y * pitchSrcY )
                        + ( pRectSrc->origin.x * bppY );
        pBufferSrcU = pBufferSrc
                        + surfaceInfoSrc.u_offset
                        + (pRectSrc->origin.y * pitchSrcUV )
                        + ((pRectSrc->origin.x / _NPIX) * bytesPerBlockUOrV);
        pBufferSrcV = pBufferSrc
                        + surfaceInfoSrc.v_offset
                        + (pRectSrc->origin.y * pitchSrcUV )
                        + ((pRectSrc->origin.x / _NPIX) * bytesPerBlockUOrV );
        pitchDstY   = surfaceInfoDst.pitch;
        pitchDstUV  = surfaceInfoDst.uv_pitch;
        pBufferDstY = pBufferDst
                        + ( pRectDst->origin.y * pitchDstY )
                        + ( pRectDst->origin.x * bppY );
        pBufferDstU = pBufferDst
                        + surfaceInfoDst.u_offset
                        + ( pRectDst->origin.y * pitchDstUV )
                        + ((pRectDst->origin.x / _NPIX) * bytesPerBlockUOrV);
        pBufferDstV = pBufferDst
                        + surfaceInfoDst.v_offset
                        + ( pRectDst->origin.y * pitchDstUV )
                        + ((pRectDst->origin.x / _NPIX) * bytesPerBlockUOrV);
        bytesPerRowY = pRectSrc->width * bppY;
        bytesPerRowUOrV = (pRectSrc->width/_NPIX) * bytesPerBlockUOrV;
        break;
    case GDL_PF_YV16:
        // Planar 16 bpp YUV format that starts with an NxM 8-bit Y plane,
        // followed by (N/2)x(M) 8-bit V and 8-bit U planes (2x1
        // subsampled).

        bytesPerBlockUOrV   = sizeof( gdl_uint8 );
        bppY                = sizeof( gdl_uint8 );

        format422   = GDL_TRUE;
        pitchSrcY   = surfaceInfoSrc.pitch;
        pitchSrcUV  = surfaceInfoSrc.uv_pitch;
        pBufferSrcY = pBufferSrc
                        + ( pRectSrc->origin.y * pitchSrcY )
                        + ( pRectSrc->origin.x * bppY );
        pBufferSrcV = pBufferSrc
                        + surfaceInfoSrc.v_offset
                        + ( pRectSrc->origin.y * pitchSrcUV )
                        + ((pRectSrc->origin.x / _NPIX) * bytesPerBlockUOrV);
        pBufferSrcU = pBufferSrc
                        + surfaceInfoSrc.u_offset
                        + ( pRectSrc->origin.y * pitchSrcUV )
                        + ((pRectSrc->origin.x / _NPIX) * bytesPerBlockUOrV);
        pitchDstY   = surfaceInfoDst.pitch;
        pitchDstUV  = surfaceInfoDst.uv_pitch;
        pBufferDstY = pBufferDst
                        + ( pRectDst->origin.y * pitchDstY )
                        + ( pRectDst->origin.x * bppY );
        pBufferDstV = pBufferDst
                        + surfaceInfoDst.v_offset
                        + ( pRectDst->origin.y * pitchDstUV )
                        + ((pRectDst->origin.x / _NPIX) * bytesPerBlockUOrV);
        pBufferDstU = pBufferDst
                        + surfaceInfoDst.u_offset
                        + ( pRectDst->origin.y * pitchDstUV )
                        + ((pRectDst->origin.x / _NPIX) * bytesPerBlockUOrV);
        bytesPerRowY = pRectSrc->width * bppY;
        bytesPerRowUOrV = (pRectSrc->width/_NPIX) * bytesPerBlockUOrV;
        break;
    case GDL_PF_NV16:
        // Pseudo-planar 16 bpp YUV 4:2:2 format that starts with an NxM
        // 8-bit Y plane, followed by (N/2)x(M) packed 8-bit U and 8-bit V
        // plane (2x1 subsampled).

        bytesPerBlockUV = sizeof( gdl_uint8 ) * 2;
        bppY            = sizeof( gdl_uint8 );

        format422       = GDL_TRUE;
        pitchSrcY       = surfaceInfoSrc.pitch;
        pitchSrcUV      = surfaceInfoSrc.uv_pitch;
        pBufferSrcY     = pBufferSrc + (pRectSrc->origin.y * pitchSrcY )
                            + (pRectSrc->origin.x * bppY);
        pBufferSrcUV    = pBufferSrc + surfaceInfoSrc.u_offset
                            + (pRectSrc->origin.y * pitchSrcUV)
                            + ((pRectSrc->origin.x/_NPIX) * bytesPerBlockUV);
        pitchDstY       = surfaceInfoDst.pitch;
        pitchDstUV      = surfaceInfoDst.uv_pitch;
        pBufferDstY     = pBufferDst + (pRectDst->origin.y * pitchDstY)
                            + (pRectDst->origin.x * bppY);
        pBufferDstUV    = pBufferDst + surfaceInfoDst.u_offset
                            + (pRectDst->origin.y * pitchDstUV)
                            + ((pRectDst->origin.x/_NPIX) * bytesPerBlockUV);
        bytesPerRowY    = pRectSrc->width * bppY;
        bytesPerRowUV   = (pRectSrc->width / _NPIX) * bytesPerBlockUV;
        break;
    default:
        // Planar 12 bpp YUV format that starts with an NxM 8-bit Y plane.

        bppY  = sizeof( gdl_uint8 );

        format422   = GDL_FALSE;
        pitchSrcY   = surfaceInfoSrc.pitch;
        pBufferSrcY = pBufferSrc + (pRectSrc->origin.y * pitchSrcY)
                        + (pRectSrc->origin.x * bppY);
        pitchDstY   = surfaceInfoDst.pitch;
        pBufferDstY = pBufferDst + (pRectDst->origin.y * pitchDstY)
                        + (pRectDst->origin.x * bppY);
        bytesPerRowY= pRectSrc->width * bppY;

        switch (formatYUV)
        {
        case GDL_PF_I420:
            // Y plane is followed by (N/2)x(M/2) 8-bit U and 8-bit V
            // planes (2x2 subsampled).
            #if 1
                pitchSrcUV  = surfaceInfoSrc.uv_pitch;
                pBufferSrcU = pBufferSrc + surfaceInfoSrc.u_offset;
                pBufferSrcV = pBufferSrc + surfaceInfoSrc.v_offset;
                pitchDstUV  = surfaceInfoDst.uv_pitch;
                pBufferDstU = pBufferDst + surfaceInfoDst.u_offset;
                pBufferDstV = pBufferDst + surfaceInfoDst.v_offset;
            #else
                // When not specified, their pitch is half the Y pitch.
                pitchSrcUV  = pitchSrcY / 2;
                pBufferSrcU = pBufferSrc + (heightSrcYUV * pitchSrcY);
                pBufferSrcV = pBufferSrc + ((heightSrcYUV/2) * pitchSrcUV);
                pitchDstUV  = pitchDstY / 2;
                pBufferDstU = pBufferDst + (heightDstYUV * pitchDstY);
                pBufferDstV = pBufferDst + ((heightDstYUV/2 ) * pitchDstUV);
            #endif

            bytesPerBlockUOrV   = sizeof( gdl_uint8 );

            pBufferSrcU += ((pRectSrc->origin.y/_NROW) * pitchSrcUV)
                         + ((pRectSrc->origin.x/_NPIX) * bytesPerBlockUOrV);
            pBufferSrcV += ((pRectSrc->origin.y/_NROW) * pitchSrcUV)
                         + ((pRectSrc->origin.x/_NPIX) * bytesPerBlockUOrV);
            pBufferDstU += ((pRectDst->origin.y/_NROW) * pitchDstUV)
                         + ((pRectDst->origin.x/_NPIX) * bytesPerBlockUOrV );
            pBufferDstV += ((pRectDst->origin.y/_NROW) * pitchDstUV)
                         + ((pRectDst->origin.x/_NPIX) * bytesPerBlockUOrV );
            bytesPerRowUOrV = (pRectSrc->width/_NPIX) * bytesPerBlockUOrV;
            break;
        case GDL_PF_YV12:
            // Y plane is followed by (N/2)x(M/2) 8-bit V and 8-bit U
            // planes (2x2 subsampled).
            #if 1
                pitchSrcUV  = surfaceInfoSrc.uv_pitch;
                pBufferSrcV = pBufferSrc + surfaceInfoSrc.v_offset;
                pBufferSrcU = pBufferSrc + surfaceInfoSrc.u_offset;
                pitchDstUV  = surfaceInfoDst.uv_pitch;
                pBufferDstV = pBufferDst + surfaceInfoDst.v_offset;
                pBufferDstU = pBufferDst + surfaceInfoDst.u_offset;
            #else
                // When not specified, their pitch is half the Y pitch.
                pitchSrcUV  = pitchSrcY / 2;
                pBufferSrcV = pBufferSrc + (heightSrcYUV * pitchSrcY);
                pBufferSrcU = pBufferSrc + ((heightSrcYUV/2) * pitchSrcUV);
                pitchDstUV  = pitchDstY / 2;
                pBufferDstV = pBufferDst + (heightDstYUV * pitchDstY);
                pBufferDstU = pBufferDst + ((heightDstYUV/2 ) * pitchDstUV);
            #endif

            bytesPerBlockUOrV = sizeof( gdl_uint8 );

            pBufferSrcV += ((pRectSrc->origin.y/_NROW) * pitchSrcUV)
                           + ((pRectSrc->origin.x/_NPIX) * bytesPerBlockUOrV);
            pBufferSrcU += ((pRectSrc->origin.y/_NROW) * pitchSrcUV)
                           + ((pRectSrc->origin.x/_NPIX) * bytesPerBlockUOrV);
            pBufferDstV += ((pRectDst->origin.y/_NROW) * pitchDstUV)
                           + ((pRectDst->origin.x/_NPIX) * bytesPerBlockUOrV);
            pBufferDstU += ((pRectDst->origin.y/_NROW) * pitchDstUV)
                           + ((pRectDst->origin.x/_NPIX) * bytesPerBlockUOrV);
            bytesPerRowUOrV = (pRectSrc->width/_NPIX) * bytesPerBlockUOrV;
            break;
        case GDL_PF_NV12:
            // Y plane is followed by (N/2)x(M/2) packed 8-bit U and 8-bit
            // V plane (2x2 subsampled).

            bytesPerBlockUV = sizeof( gdl_uint8 ) * 2;

            pitchSrcUV  = surfaceInfoSrc.uv_pitch;
            pBufferSrcUV= pBufferSrc + surfaceInfoSrc.u_offset
                            + ((pRectSrc->origin.y/_NROW) * pitchSrcUV )
                            + ((pRectSrc->origin.x/_NPIX) * bytesPerBlockUV);
            pitchDstUV  = surfaceInfoDst.uv_pitch;
            pBufferDstUV= pBufferDst + surfaceInfoDst.u_offset
                            + ((pRectDst->origin.y/_NROW) * pitchDstUV)
                            + ((pRectDst->origin.x/_NPIX) * bytesPerBlockUV);
            bytesPerRowUV = (pRectSrc->width/_NPIX) * bytesPerBlockUV;
        default:
            // This should never occur.  If it does, it indicates that
            // validation logic in the big if statement above doesn't
            // match the inner logic.
            result = GDL_ERR_INTERNAL;
            goto exit;
        }
    }

    gdl_uint32  rowsLeft;

    // Copy the pixels from the source to the destination.
    for ( rowsLeft = pRectSrc->height; rowsLeft > 0; rowsLeft-- )
    {
        if ( bytesPerRowYUV )
        {
            memcpy( pBufferDstYUV, pBufferSrcYUV, bytesPerRowYUV );
            pBufferSrcYUV += pitchSrcYUV;
            pBufferDstYUV += pitchDstYUV;
        }
        else if ( bytesPerRowY )
        {
            memcpy( pBufferDstY, pBufferSrcY, bytesPerRowY );
            pBufferSrcY += pitchSrcY;
            pBufferDstY += pitchDstY;
        }
    }

    // Also handle copying chroma buffers if they exist.
    if ( bytesPerRowUOrV || bytesPerRowUV )
    {
        for ( rowsLeft = format422 ? pRectSrc->height : pRectSrc->height / _NROW;
              rowsLeft > 0;
              rowsLeft--)
        {
            if ( bytesPerRowUOrV )
            {
                memcpy(pBufferDstU, pBufferSrcU, bytesPerRowUOrV);
                memcpy(pBufferDstV, pBufferSrcV, bytesPerRowUOrV);
                pBufferSrcU += pitchSrcUV;
                pBufferSrcV += pitchSrcUV;
                pBufferDstU += pitchDstUV;
                pBufferDstV += pitchDstUV;
            }
            else if ( bytesPerRowUV )
            {
                memcpy(pBufferDstUV, pBufferSrcUV, bytesPerRowUV);
                pBufferSrcUV += pitchSrcUV;
                pBufferDstUV += pitchDstUV;
            }
        }
    }

exit:
    // Unmap surfaces now that we're finished with them.  Results are not
    // checked so as to not override another failure if there's one.

    if ( surfaceDstId && mappedDst )
    {
        CHK( gdl_unmap_surface( surfaceDstId ) );
    }

    if ( surfaceSrcId && mappedSrc )
    {
        CHK( gdl_unmap_surface( surfaceSrcId ) );
    }

    return result;
}

gdl_ret_t SaveSurfaceAsPNG(char*               pImageFileName,
                           gdl_surface_info_t* pSurfaceInfo   )
{
    return GDL_ERR_NOT_IMPL;
#if 0
    gdl_ret_t ret_val         = GDL_SUCCESS;
    gdl_uint8 *pSurfaceBuffer = NULL;

    ImagePNG     ImagePNG;
    printf("Save Surface Entry \n");

    memset( &ImagePNG, 0, sizeof(ImagePNG));

    ImagePNG.height     = pSurfaceInfo->height;
    ImagePNG.width      = pSurfaceInfo->width;
    ImagePNG.pixelFormat= pSurfaceInfo->pixel_format;
    ImagePNG.bpp        = pSurfaceInfo->size;
    printf("Height = %d\nWidth = %d\n", ImagePNG.height, ImagePNG.width);

    // Copy the data

    ret_val = gdl_map_surface(pSurfaceInfo->id, &pSurfaceBuffer, NULL);

    if ( !pSurfaceBuffer )
    {
        ret_val = GDL_ERR_INTERNAL;
        goto exit;
    }

    ImagePNG.pImageBuffer = pSurfaceBuffer;

    printf("Calling SaveImagePNG\n");

    ret_val = SaveImagePNG( pImageFileName, &ImagePNG);
    if (ret_val)
    {
        goto exit;
    }

    if (pSurfaceBuffer)
    {
        ret_val = gdl_unmap_surface( pSurfaceInfo->id );
    }
exit:
    return ret_val;
#endif
}
