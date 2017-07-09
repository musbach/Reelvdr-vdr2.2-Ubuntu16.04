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
#ifndef _LIBGMA_H_
#define _LIBGMA_H_

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef DOXYGEN_SKIP
#define GMA_API __attribute__ ((visibility ("default")))
#else
#define GMA_API " "
#endif

//-----------------------------------------------------------------------------
// Types
//-----------------------------------------------------------------------------

/**@defgroup pixmap GMA native pixmap type

   A pixmap is a region of memory that can be used as a source or destination
   for graphics operations.  A particular pixmap is defined by:

       - The virtual and physical addresses of the memory region.
       - The size of the memory region.
       - The format of the pixel data.

   The GMA Pixmap APIs allow pixmaps to be created from arbitrary regions
   of memory that are not owned by the graphics drivers.  For this reason, a
   pixmap is also described by a set of functions that manage the memory.
   Specifically:

       - Releasing the memory back to its owner to be reused.

   Pixmaps are reference counted to ensure that the memory is not allowed to be
   reused before the graphics drivers have finished using it.

  */

/** @ingroup pixmap */
/**@{*/

typedef unsigned int        gma_uint32;  ///< Unsigned 32 bit integer
typedef unsigned long long  gma_uint64;  ///< Unsigned 64 bit integer


/**
   Error codes that can be returned by GMA Native Type functions.
*/
typedef enum
{
    GMA_SUCCESS             = 0,
        /**<
        Function executed without errors
        */
    GMA_ERR_NULL_ARG        = 0x01,
        /**<
        A required argument was missing.  Either a NULL pointer or a count
        of 0 was passed for a required argument.
        */
    GMA_ERR_INVAL_FUNCS     = 0x02,
        /**<
        A required pixmap function was missing.
        */
    GMA_ERR_INVAL_INFO      = 0x03,
        /**<
        A pixmap description contained invalid information.
        */
    GMA_ERR_NO_MEMORY       = 0x04,
        /**<
        Could not allocate memory
        */
    GMA_ERR_FAILED          = 0x05
        /**<
        This is a generic error code that generally means that a system
        call or call to some other software external to the driver
        returned a failure code.
        */
} gma_ret_t;


/**
   Color space identifiers for GMA pixmaps.
 */
typedef enum
{
    GMA_COLOR_SPACE_BT601,
    GMA_COLOR_SPACE_BT709,
    GMA_COLOR_SPACE_COUNT
} gma_color_space_t;


/**
   Pixel format identifiers for GMA pixmaps.
 */
typedef enum
{
    GMA_PF_ARGB_32,         ///< ARGB 32bpp 8:8:8:8  Little Endian
    GMA_PF_RGB_32,          ///< xRGB 32bpp x:8:8:8  Little Endian
    GMA_PF_ARGB_16_1555,    ///< ARGB 16bpp 1:5:5:5  Little Endian
    GMA_PF_ARGB_16_4444,    ///< ARGB 16bpp 4:4:4:4  Little Endian
    GMA_PF_RGB_16,          ///<  RGB 16bpp 5:6:5    Little Endian
    GMA_PF_A8,              ///< 8-bit Alpha-only surface
    GMA_PF_AY16,            ///< Alpha-luminance 8:8 Little Endian
    GMA_PF_NV16,            ///< YUV 4:2:2 Pseudo-planar
    GMA_PF_LUT8,            ///< 8-bit palette index, 32bpp ARGB 8:8:8:8 entries
    GMA_PF_COUNT            ///< Number of defined pixel formats
} gma_pixel_format_t;

/**@}*/


/** @ingroup pixmap */
/**@{*/

typedef void* gma_pixmap_t;       ///< Handle to a GMA pixmap


/**
   Identifies the type of memory being used to create a GMA pixmap.
 */
typedef enum
{
    GMA_PIXMAP_TYPE_PHYSICAL,  ///< Contiguous physical memory
    GMA_PIXMAP_TYPE_VIRTUAL    ///< Virtual memory
} gma_pixmap_type_t;


/**
   Describes the memory used to create a GMA pixmap.
 */
typedef struct
{
    gma_pixmap_type_t        type;        ///< The type of pixmap

    void                    *virt_addr;   /**< Virtual address of pixmap
                                            *  memory. Required.
                                            */
    gma_uint32               phys_addr;   /**< Physical address of pixmap
                                            *  memory. Only required if #type
                                            *  is #GMA_PIXMAP_TYPE_PHYSICAL.
                                            *  If required, must not be 0.
                                            */

    gma_pixel_format_t       format;      ///< Pixel format of the pixmap
    gma_color_space_t        color_space; /**< Color space of the pixmap.
                                            *  Only valid if #format is
                                            *  #GMA_PF_NV16.
                                            */

    gma_uint32               width;       /**< Width in pixels of the pixmap.
                                            *  Must not be 0.
                                            */
    gma_uint32               height;      /**< Height in pixels of the pixmap.
                                            *  Must not be 0.
                                            */
    gma_uint32               pitch;       /**< Stride in bytes of the pixmap.
                                            *  Must not be 0.
                                            */

    void                    *palette;     /**< Palette for the pixmap. Only
                                            *  valid if the pixmap has a
                                            *  palettized #format. The size of
                                            *  the array and the size of each
                                            *  entry is determined by the pixmap
                                            *  format. The memory is owned by
                                            *  the creator of the pixmap and
                                            *  should be freed in the pixmap's
                                            *  destroy callback.
                                            */
    gma_uint32               palette_entry_count;
                                          ///< Number of entries in the palette

    void                    *user_data;   ///< Opaque data for use by callbacks
} gma_pixmap_info_t;


/**
   Callback functions to manage a GMA pixmap's memory.
 */
typedef struct
{
    gma_ret_t (*destroy)(gma_pixmap_info_t *pixmap_info);
        ///< Function to return pixmap memory to its owner. Required.
} gma_pixmap_funcs_t;

/**@}*/


//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

GMA_API gma_ret_t
gma_pixmap_alloc(
    gma_pixmap_info_t   *pixmap_info,
    gma_pixmap_funcs_t  *pixmap_funcs,
    gma_pixmap_t        *pixmap
    );
    /**< @ingroup pixmap

    This routine allocates a pixmap for a region of memory.  The pixmap's
    reference count will be initialized to 1.

    @param [in]   pixmap_info
    A description of the memory region from which to create the pixmap.

    @param [in]   pixmap_funcs
    A set of functions for managing the pixmap's memory.

    @param [out]  pixmap
    A pointer to a #gma_pixmap_t to be filled with the pixmap handle.

    */

GMA_API gma_ret_t
gma_pixmap_add_ref(
    gma_pixmap_t      pixmap
    );
    /**< @ingroup pixmap

    This routine increments the reference count for a pixmap.

    @param [in]  pixmap
    The pixmap whose reference count is to be incremented.

    */

GMA_API gma_ret_t
gma_pixmap_release(
    gma_pixmap_t      *pixmap
    );
    /**< @ingroup pixmap

    This routine decrements the reference count for a pixmap.  The pixmap
    handle is set to NULL.  If the count reaches zero, the pixmap's #destroy
    callback will be called to return the pixmap's memory to its owner.

    If the pixmap is destroyed, the return code will be the value returned by
    the pixmap's #destroy callback.

    @param [in]  pixmap
    A pointer to the pixmap whose reference count is to be decremented.

    */

GMA_API gma_ret_t
gma_pixmap_get_info(
    gma_pixmap_t        pixmap,
    gma_pixmap_info_t  *pixmap_info
    );
    /**< @ingroup pixmap

    This routine obtains the description of the memory region that a
    pixmap represents.

    @param [in]   pixmap
    The pixmap whose memory region is to be described.

    @param [out]  pixmap_info
    The description of the memory region for the specified pixmap.

    */

#if defined(__cplusplus)
};
#endif

#endif
