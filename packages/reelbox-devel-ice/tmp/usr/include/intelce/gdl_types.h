//-----------------------------------------------------------------------------
// BSD LICENSE
//
// Copyright(c) 2005-2011 Intel Corporation. All rights reserved.
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

#ifndef _GDL_TYPES_H_
#define _GDL_TYPES_H_

#define GDL_SERVER_IOC_MAGIC 'S'


/*----------------------------------------------------------------------
 *                     G E N E R A L
 *---------------------------------------------------------------------*/

/** @ingroup general */
/**@{*/
typedef unsigned char      gdl_uint8; ///< Unsigned 8 bit integer.
typedef unsigned short     gdl_uint16;///< Unsigned 16 bit integer.
typedef unsigned int       gdl_uint32;///< Unsigned 32 bit integer.
typedef unsigned long long gdl_uint64;///< Unsigned 64 bit integer.
typedef char               gdl_int8;  ///< Signed 8 bit integer.
typedef short              gdl_int16; ///< Signed 16 bit integer.
typedef int                gdl_int32; ///< Signed 32 bit integer.
typedef long long          gdl_int64; ///< Signed 64 bit integer.
typedef void               gdl_void;  ///< Void data type.
typedef gdl_uint32         gdl_fixed_t; ///< Fixed point value (variable precision)
#ifndef __KERNEL__
typedef float              gdl_f32;   ///< Single precision floating point
#else
#define gdl_f32 gdl_fixed_t
#endif
typedef double             gdl_f64;   ///< Double precision floating point

typedef unsigned long      physaddr_t; ///< A physical memory address

/**@}*/

/** @ingroup general
    Boolean data type
*/
typedef enum
{
    GDL_FALSE   = 0,        ///< Boolean false.
    GDL_TRUE    = 1         ///< Boolean true.
} gdl_boolean_t;


/** @ingroup general
*/
typedef struct
{
    gdl_int32 x;            ///< Point X-coordinate
    gdl_int32 y;            ///< Point Y-coordinate
} gdl_point_t;


/** @ingroup general
*/
typedef struct
{
    gdl_point_t  origin;    ///< Rectangle origin
    gdl_uint32   width;     ///< Rectangle width
    gdl_uint32   height;    ///< Rectangle height
} gdl_rectangle_t;


// Return 0 if two gdl_rectangle_t variables are not equal, non-zero otherwise
static __inline int
rect_eq( gdl_rectangle_t *rect1, gdl_rectangle_t *rect2)
{
    return  (rect1->origin.x == rect2->origin.x)
        &&  (rect1->origin.y == rect2->origin.y)
        &&  (rect1->width    == rect2->width   )
        &&  (rect1->height   == rect2->height  );
}

/** @ingroup general
    Bit flags returned in the 'flags' field of #gdl_driver_info_t.
*/
typedef enum
{
    GDL_DRIVER_INFO_HDCP_ENABLED        = 1,
        ///< Driver is running on a chip with HDCP enabled.
    GDL_DRIVER_INFO_MACROVISION_ENABLED = 4,
        ///< Driver is running on a chip with Macrovision support enabled.
    GDL_DRIVER_INFO_1080P_ENABLED       = 8
        ///< Driver is running on a chip with 1080p display mode enabled.
} gdl_driver_info_flag_t;


/** @ingroup general
    Display Driver information structure returned by gdl_get_driver_info().
*/
typedef struct
{
    gdl_int16       header_version_major;
                    /**< Major version number of header files. */
    gdl_int16       header_version_minor;
                    /**< Minor version number of header files. */
    gdl_uint32      gdl_version;
                    /**< Driver version number */
    gdl_int32       build_tag;
                    /**< Driver build tag. */
    gdl_driver_info_flag_t flags;
                    /**< Capabilities of chip on which the driver is running. */
    char            name[64];
                    /**< Display driver name as a 0-terminated ASCII string. */
    gdl_uint32      mem_size;
                    /**< Total number of bytes allocated for driver memory.
                     * Extra heaps will be visible only if the caller attached
                     * them previously. See #gdl_attach_heap for details.
                     */
    gdl_uint32      mem_avail;
                    /**< Number of bytes of driver memory currently unused.
                     * Extra heaps will be visible only if the caller attached
                     * them previously. See #gdl_attach_heap for details.
                     */
} gdl_driver_info_t;


/** @ingroup general
    Pixel component extension options.  The blender operates on pixels
    with 10-bit components (i.e., 10-bit R, G, and B values for RGB pixel
    formats; 10-bit chroma/luma values for YUV pixel formats).  However, most
    of the pixel formats supported by the planes have component values of less
    than 10 bits; as the planes output such pixels, they extend them to 10 bits
    using one of the methods described by this enumeration.
*/
typedef enum
{
    GDL_PIXEL_EXTENSION_ZERO_PAD,
            /**<
            Pixel component values are extended from N to 10 bits by
            shifting them left (10-N) bits and appending 0's. E.g., the
            8-bit value 0x7f [0111 1111] becomes 0x1fc [01 1111 1100].
            With this method, the difference between any two consecutive
            output values is a constant, but the highest possible value is
            0x3fc (11 1111 1100).
            */
    GDL_PIXEL_EXTENSION_MSB_SHADOW,
            /**<
            Pixel component values are first extended from N to 10 bits by
            shifting them left (10-N) bits and appending 0's. Then the
            (10-N) most significant bits are OR'd into the low-order (10-N)
            places. E.g., the 8-bit value 0x7f (0111 1111) becomes 0x1fd
            (01 1111 1101).   With this method, the difference between any
            two consecutive output values is NOT constant, but the values at
            either end of the output range are fully saturated (0x000 and 0x3ff).
            */
    GDL_PIXEL_EXTENSION_COUNT
            /**<
            Number of valid entries in this enumeration.
            */
} gdl_pixel_extension_t;


/** @ingroup general
    Pixel format identifiers.  Note that the appearance of a pixel format in
    this list does not guarantee that is is supported by the hardware.
 */
typedef enum
{
    /* RGB types */
    GDL_PF_ARGB_32,         ///< ARGB 32bpp 8:8:8:8  LE
    GDL_PF_RGB_32,          ///< xRGB 32bpp x:8:8:8  LE
    GDL_PF_RGB_36,          ///<  RGB 36bpp 12:12:12 LE [fully packed]
    GDL_PF_RGB_30,          ///<  RGB 30bpp 10:10:10 LE [fully packed]
    GDL_PF_RGB_24,          ///<  RGB 24bpp 8:8:8    LE [fully packed]
    GDL_PF_ARGB_16_1555,    ///< ARGB 16bpp 1:5:5:5  LE
    GDL_PF_ARGB_16_4444,    ///< ARGB 16bpp 4:4:4:4  LE
    GDL_PF_RGB_16,          ///<  RGB 16bpp 5:6:5    LE
    GDL_PF_RGB_15,          ///< xRGB 16bpp x:5:5:5  LE

    /* CLUT types */
    GDL_PF_RGB_8,           ///<  RGB 8bpp - 24bpp palette RGB 8:8:8
    GDL_PF_ARGB_8,          ///< ARGB 8bpp - 32bpp palette ARGB 8:8:8:8
    GDL_PF_AYUV_8,          ///< AYUV 8bpp - 32bpp palette AYUV 8:8:8:8

    /* Packed YUV types */
    GDL_PF_YUY2,            ///< Packed YUV 4:2:2 32-bit: V0:Y1:U0:Y0 LE
    GDL_PF_UYVY,            ///< Packed YUV 4:2:2 32-bit: Y1:V0:Y0:U0 LE
    GDL_PF_YVYU,            ///< Packed YUV 4:2:2 32-bit: U0:Y1:V0:Y0 LE
    GDL_PF_VYUY,

    /* Planar YUV types */
    GDL_PF_YV12,            ///< YVU 4:2:0 Planar (V plane precedes U)
    GDL_PF_YVU9,            ///< YUV 4:2:0 Planar
    GDL_PF_I420,            ///< YUV 4:2:0 Planar (U plane precedes V)
    GDL_PF_IYUV=GDL_PF_I420,///< Synonym for I420

            //************************************************************
            // NOTE!: GDL_PF_IYUV must immediately follow GDL_PF_I420!
            //************************************************************

    GDL_PF_I422,            ///< YUV 4:2:2 Planar (U plane precedes V)
    GDL_PF_YV16,            ///< YVU 4:2:2 Planar (V plane precedes U)

    /* Pseudo-planar YUV types */
    GDL_PF_NV12,            ///< YUV 4:2:0 Pseudo-planar
    GDL_PF_NV16,            ///< YUV 4:2:2 Pseudo-planar
    GDL_PF_NV20,            ///< YUV 4:2:2 Pseudo-planar, 10-bit components

    GDL_PF_A1,              ///< 1-bit Alpha-only surface
    GDL_PF_A4,              ///< 4-bit Alpha-only surface
    GDL_PF_A8,              ///< 8-bit Alpha-only surface

    GDL_PF_AY16,            ///< Alpha-luminance 8:8. Used for video textures
    GDL_PF_COUNT            ///< Number of defined pixel formats
} gdl_pixel_format_t;


/** @ingroup general
    Error codes that can be returned by GDL functions.  Note that more detailed
    information about an error may also be printed on the system console.
*/
typedef enum
{
    GDL_SUCCESS             = 0,
        /**<
        Function executed without errors
        */
    GDL_ERR_INVAL           = 0x01,
        /**<
        An invalid argument was passed.
        */
    GDL_ERR_BUSY            = 0x02,
        /**<
        An operation could not be completed because a needed resource is in use.
        */
    GDL_ERR_DISPLAY         = 0x03,
        /**<
        An invalid display ID was passed.
        */
    GDL_ERR_SURFACE         = 0x04,
        /**<
        An invalid surface ID, or the ID of a surface that is not
        appropriate for the requested operation, was passed.
        */
    GDL_ERR_COMMAND         = 0x05,
        /**<
        An internal command processing error occurred
        */
    GDL_ERR_NULL_ARG        = 0x06,
        /**<
        A required argument was missing.  Either a NULL pointer or a count
        of 0 was passed for a required argument.
        */
    GDL_ERR_NO_MEMORY       = 0x07,
        /**<
        Could not allocate memory.
        */
    GDL_ERR_FAILED          = 0x08,
        /**<
        This is a generic error code that generally means that a system
        call or call to some other software external to the driver
        returned a failure code.
        */
    GDL_ERR_INTERNAL        = 0x09,
        /**<
        A condition that "should not be possible" was detected within the
        driver.  This generally means there is nothing the application can
        do to correct the problem.
        */
    GDL_ERR_NOT_IMPL        = 0x0a,
        /**<
        The function is not currently implemented for the target chip.
        */
    GDL_ERR_MAPPED          = 0x0b,
        /**<
        Operation not permitted on the mapped surface.
        */
    GDL_ERR_NO_INIT         = 0x0c,
        /**<
        A GDL function was called without a preceding call to gdl_init().
        */
    GDL_ERR_NO_HW_SUPPORT   = 0x0d,
        /**<
        The target chip does not support the requested function.  Examples:
        - A graphics rendering option is not supported by the graphics core
          in the target chip.
        - A plane or port driver does not support a requested attribute.
        - An attempt was made to request the attribute list from a port
          driver that does not support any attributes.
        */
    GDL_ERR_INVAL_PF        = 0x0e,
        /**<
        An unknown pixel format, or a pixel format not supported by the
        attempted operation, was passed.
        */
    GDL_ERR_INVAL_RECT      = 0x0f,
        /**<
        An invalid argument of type #gdl_rectangle_t was passed to the function.
        */
    GDL_ERR_ATTR_ID         = 0x10,
        /**<
        An undefined ID was specified for a plane attribute,  port driver
        attribute or a post blender attribute.
        */
    GDL_ERR_ATTR_NO_SUPPORT = 0x11,
        /**<
        An unsupported ID was specified for a plane attribute or a port
        driver attribute.
        */
    GDL_ERR_ATTR_READONLY   = 0x12,
        /**<
        An attempt was made to set the value of a read-only plane attribute
        or port driver attribute.
        */
    GDL_ERR_ATTR_VALUE      = 0x13,
        /**<
        An invalid value was specified for a plane attribute, port driver
        attribute or a post blender attribute.
        */
    GDL_ERR_PLANE_CONFLICT  = 0x14,
        /**<
        An attempt was made to change the display mode to a resolution too
        small to accommodate all of the currently enabled planes at their
        current positions on the display. Move/shrink the affected planes first.
        */
    GDL_ERR_DISPLAY_CONFLICT= 0x15,
        /**<
        An attempt was made to change either display resolution or plane
        size/origin, such that part/all of the plane will no longer be on the
        display.
        - If the display resolution is being reduced, change plane size/origin
          first.
        - If plane size is being increased, increase the display resolution
          first, or reposition the plane.
        - If plane origin is being changed, make sure you have picked an
          appropriate origin given the current plane size and display
          resolution.
        */
    GDL_ERR_TIMEOUT        = 0x16,
        /**<
        The requested timeout period occurred before the requested
        operation trigger occurred.
        */
    GDL_ERR_MISSING_BEGIN  = 0x17,
         /**<
         An attempt was made to set a plane attribute without first calling
         gdl_config_begin().
         */
    GDL_ERR_PLANE_ID       = 0x18,
        /**<
        An invalid plane ID was passed.  The ID is undefined, the plane is not
        supported by the target chip, or the plane is not supported by the
        called function.
        */
    GDL_ERR_INVAL_PTR      = 0x19,
        /**<
        On Linux, a copy between user and kernel space failed.  This
        probably indicates an invalid user space (argument) pointer.
        */

    GDL_ERR_INVAL_HEAP = 0x1a,
        /**<
        An invalid heap was passed for addition or removal. Attempt
        to add overlaping heaps will cause this error too.
        */

    GDL_ERR_HEAP_IN_USE = 0x1b,
        /**<
        Heap removal was attempted while at least one surface was allocated
        from that heap.
        */

    GDL_ERR_INVAL_CALLBACK = 0x1c,
        /**<
        Invalid callback (null) was passed to gdl_event_register() function
        */

    GDL_ERR_SCALING_POLICY  = 0x1d,
        /**<
        A single scaling policy is required and was not specified for the
        #gdl_display_info_t structure used, or scaling policies are
        unsupported for the specified display ID.
        */

    GDL_ERR_INVAL_EVENT = 0x1e,
        /**<
        Invalid event was passed to functions expecting #gdl_app_event_t.
        */

    GDL_ERR_INVAL_IOCTL     = 0x1f,
        /**<
        Invalid IOCTL request was sent to kernel module
        */
    GDL_ERR_SCHED_IN_ATOMIC = 0x20,
        /**<
        Scheduling was attempted while being in atomic context.
        */
    GDL_ERR_MMAP            = 0x21,
        /**<
        Memory mapping failed
        */
    GDL_ERR_HDCP            = 0x22,
        /**<
        HDCP failure
        */
    GDL_ERR_CONFIG          = 0x23,
        /**<
        Platform config file error: either a required entry in the
        platform configuration file is missing, or its entry is invalid.
        */
    GDL_ERR_HDMI_AUDIO_PLAYBACK = 0x24,
        /**<
        HDMI Audio start / stop / set buffer / set format command was
        initiated at the wrong time.
        */
    GDL_ERR_HDMI_AUDIO_BUFFER_FULL = 0x25,
        /**<
        Given data does not fit in the internal buffer
        */
    GDL_ERR_PLANE_ORIGIN_ODD   = 0x26,
        /**<
        In interlaced display modes, active planes must be configured with
        their origins on even display lines. This error is returned when:
        - in a progressive display mode: an attempt is made to change to an
          interlaced display mode while there is an active plane does not
          meet this requirement.
        - in an interlaced display mode:
           - an attempt is made to reconfigure an active plane's origin
             to an odd line number, OR
           - an attempt is made to activate (by flipping a surface to) a
             plane that doesn't meet this requirement.
        */
    GDL_ERR_PLANE_HEIGHT_ODD   = 0x27,
        /**<
        In interlaced display modes, active planes must be configured with
        their even heights. This error is returned when:
        - in a progressive display mode: an attempt is made to change to an
          interlaced display mode while there is an active plane does not
          meet this requirement.
        - in an interlaced display mode:
           - an attempt is made to reconfigure an active plane's height
             to an odd value, OR
           - an attempt is made to activate (by flipping a surface to) a
             plane that doesn't meet this requirement.
        */
    GDL_ERR_HANDLE              = 0x28,
        /**<
        Handle is not valid.
        */
    GDL_ERR_TVMODE_UNDEFINED    = 0x29,
        /**<
        Display has undefined tv mode set on it.
        */
    GDL_ERR_PREMULT_CONFLICT    = 0x2a,
        /**<
        An attempt was made to enable the #GDL_PLANE_ALPHA_PREMULT attribute and
        one of the following incompatible features at the same time:
        - Chroma keying on the same plane (#GDL_PLANE_CHROMA_KEY_SRC_ENABLE set
          to #GDL_TRUE).
        - Gamma removal on the same plane (#GDL_PLANE_REVERSE_GAMMA_TYPE set to
          a value other than #GDL_GAMMA_LINEAR.
        - color space conversion (the value of the plane's
          #GDL_PLANE_SRC_COLOR_SPACE attribute is different from the color
          space of the display to which it is connected).
        - a non-RGB pixel format.
        */

    GDL_ERR_SUSPENDED = 0x2b,
        /**<
        An attempt was made to execute a command while the driver was in a
        suspended mode. During the suspended mode driver is in a low-power
        state and no access to hardware is allowed.
        */

    GDL_ERR_STEREO_PLANE = 0x2c,
        /**<
        An attempt was made to stereo-flip to a plane unlinked to a right view
        while a two-plane stereo display mode is in effect.
        */

    GDL_ERR_CE4100_3D_ORIGIN = 0x2d,
        /**<
        On the CE4100, the origin of a plane's destination rectangle cannot
        exceed 922 when GDL_STEREO_FRAME_PACKING_2 stereo frame format is in
        use.
        */

    GDL_ERR_HDCP_KSV_INVALID = 0x2e,
        /**<
        HDCP invalid KSV
        */
    GDL_ERR_HDCP_KSV_REVOKED = 0x2f,
        /**<
        HDCP revoked KSV
        */
    GDL_ERR_HDCP_NO_ACK = 0x30,
        /**<
        HDCP I2C timeout when receiving R'
        */
    GDL_ERR_HDCP_LINK_INTEGRITY = 0x31,
        /**<
        HDCP R != R'
        */

    GDL_ERR_PERM = 0x32,
        /**<
        Callers permissions are insufficient to perform a requested action.
        */

    //**********************************************************************
    // ATTENTION!!: WHEN ADDING AN ERROR CODE MAKE SURE TO:
    // - Search for a value marked "Currently unused" in the list above
    //   before adding a new value at the end.
    // - Include inline (doxygen) documentation for the new error.
    // - Add the new error to _error_string() in debug.c
    //**********************************************************************
} gdl_ret_t;

/** @ingroup general */
#define GDLFAIL(err) ((err) != GDL_SUCCESS)
/** @ingroup general */
#define GDLPASS(err) (!GDLFAIL(err))

/** @ingroup general

    Types of gamma curves. There are three standard values of gamma:
    - 1.0: (linear) leaves the input luminance unchanged.
    - 2.2: NTSC and HDTV content is typically generated with this value.
    - 2.8: PAL and SECAM standards indicate this value, although 2.2
      is commonly used.

    Up to four custom curves may be also specified using the custom values
    below. A custom curve must be loaded with the #gdl_set_custom_gamma_curve
    function before use.
*/
typedef enum
{
    GDL_GAMMA_LINEAR,   ///< 1.0
    GDL_GAMMA_2_2,      ///< 2.2
    GDL_GAMMA_2_8,      ///< 2.8
    GDL_GAMMA_CUSTOM_MIN,   ///Minimum custom gamma ID
    GDL_GAMMA_CUSTOM_0 = GDL_GAMMA_CUSTOM_MIN, ///< Custom curve
    GDL_GAMMA_CUSTOM_1, ///< Custom curve
    GDL_GAMMA_CUSTOM_2, ///< Custom curve
    GDL_GAMMA_CUSTOM_3, ///< Custom curve
    GDL_GAMMA_COUNT,    ///< Number of entries in this enumeration
} gdl_gamma_t;

/** @ingroup general
 *  Maximum number of points that may be specified for a gamma curve.
 */
#define GDL_GAMMA_MAX_POINTS 193

/** @ingroup general
 *  Structure to specify a custom gamma curve
 *
 *  A gamma curve is a transformation function y=g(x), and is represented as a
 *  lookup table of at least one and at most #GDL_GAMMA_MAX_POINTS points.
 *
 *  The gamma curve has an associated color range, or the range of @c x values
 *  the function is expected to transform. The minimum value is fixed at 0.0,
 *  but the maximum allowed input may be specified as @c color_limit. If an
 *  input value is greater than @c color_limit, the maximum value of the curve
 *  is used.
 *
 *  The points for a curve are assumed to be evenly sampled over the input range
 *  [0, @c color_limit ]. For example, let @c length=11 and @c color_limit=2.0.
 *  Then @c points should correspond to values of g(x) at
 *  @c x= {0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0}.
 *
 *  The slope of the curve must be flat or increasing, that is
 *  <tt>points[i] <= points[i+1]</tt> for @c i from 0 to length - 2.
 */
typedef struct
{
    gdl_uint32 length;          ///< Number of points in this curve
    gdl_f32    color_limit;     ///< Maximum color value that can be transformed
    gdl_f32    r_y[GDL_GAMMA_MAX_POINTS]; ///< Red/Y channel of the gamma curve
    gdl_f32    g_u[GDL_GAMMA_MAX_POINTS]; ///< Green/Cb channel of the gamma curve
    gdl_f32    b_v[GDL_GAMMA_MAX_POINTS]; ///< Blue/Cr channel of the gamma curve
} gdl_gamma_curve_t;

/** @ingroup general
    The occurrence of VBlank indicates completion of the updating of video
    output with a new image (and the beginning of the next image update cycle).
    This enumeration defines the different types of images that can be output
    during one update cycle.

    In interlaced display modes, the image type may be either a top field or a
    bottom field; in progressive display modes it is always a full frame.

    In monoscopic display modes, there is a single view (one full frame or one
    pair of top/bottom fields) per frame.

    In stereoscopic modes, there are two views (left and right) per frame.
*/
typedef enum
{
    GDL_POLARITY_FRAME=1,           ///< Mono or Stereo Left frame
    GDL_POLARITY_FIELD_TOP,         ///< Mono or Stereo Left top field
    GDL_POLARITY_FIELD_BOTTOM,      ///< Mono or Stereo Left bottom field
    GDL_POLARITY_FRAME_RIGHT,       ///< Stereo Right frame
    GDL_POLARITY_FIELD_RIGHT_TOP,   ///< Stereo Right top field
    GDL_POLARITY_FIELD_RIGHT_BOTTOM ///< Stereo Right bottom field
} gdl_polarity_t;

/** @ingroup general
     This enumeration specifies the available blending models, which describe
     how the blender is configured. Depending on the specific mode chosen,
     UPP_E and IAP_A may have some limitations.\n In the lists below, planes
     are listed in increasing z-order from bottom to top.\n

     @b Note: Planes which appear in @e italics are only available on CE4200-B
              and above
*/
typedef enum
{
    GDL_BLENDING_MODEL_0, /**< Displays 0 and 1 are both active.\n UPP_A, UPP_B,
                               @e IAP_x, UPP_C, UPP_D, IAP_A, and IAP_B are
                               routed to display 0.\n UPP_E is reserved by the
                               driver to enable display 1.\n\n
                          */
    GDL_BLENDING_MODEL_1, /**< Only display 0 is active. Changing the mode of
                               display 1 is not allowed.\n UPP_A, UPP_B,
                               @e IAP_x, UPP_C, UPP_D, UPP_E, and IAP_B are
                               routed to display 0.\n IAP_A may only be
                               programmed with an 'alpha' mode.\n\n
                          */
    GDL_BLENDING_MODEL_2, /**< Displays 0 and 1 are both active.\n UPP_A, UPP_B,
                               IAP_x, IAP_A, UPP_C, UPP_D, and IAP_B are routed
                               to display 0.\n UPP_E is reserved by the driver
                               to enable display 1.\n Both IAP_A and IAP_B may
                               be programmed in indexed or alpha modes.

                               @b Note: This mode is only available on CE4200-B
                                        and above \n\n
                          */
    GDL_BLENDING_MODEL_3, /**< Only display 0 is active. Changing the mode of
                               display 1 is not allowed.\n UPP_A, UPP_B, IAP_x,
                               IAP_A, UPP_C, UPP_D, UPP_E, and IAP_B are routed
                               to display 0.\n Both IAP_A and IAP_B may be
                               programmed in indexed or alpha modes.

                               @b Note: This mode is only available on CE4200-B
                                        and above\n\n
                          */

    GDL_BLENDING_MODEL_4,/**< Similar to #GDL_BLENDING_MODEL_0. UPP_E is
                              routed to display 1 and is exposed to the end-user.
                              Simultaneous display is not available.

                              @b Note: This mode is only available on CE4200-B
                                       and above\n\n
                         */

    GDL_BLENDING_MODEL_5,/**< Similar to #GDL_BLENDING_MODEL_2. UPP_E is
                              routed to display 1 and is exposed to the end-user.
                              Simultaneous display is not available.

                              @b Note: This mode is only available on CE4200-B
                                       and above\n\n
                         */

    GDL_BLENDING_MODEL_6, /**< Displays 0 and 1 are both active.\n UPP_A, UPP_B,
                               @e IAPx, UPP_C, IAP_A, IAP_B are routed to display 0.\n
                               UPP_D, UPP_E are routed to display 1.\n\n 
                          
                               @b Note: This mode is only available on CE4200-B
                                        and above\n\n     
                          */

    GDL_BLENDING_MODEL_UNDEFINED /**< Internal use only to indicate that blender
                                      is not configured yet
                                 */
} gdl_blending_model_t;

//----------------------------------------------------------------------
//                 D I S P L A Y   M O D E
//----------------------------------------------------------------------

/** @ingroup disp_mode
    Refresh rates for TV mode definitions.

    Refresh rate is the number of times the display is updated per second.
    This is the number of frames per second for progressive display modes;
    the number of fields (half the number of frames) per second for interlaced
    display modes.

    IF WRITING AN EXTERNAL (non-Intel) PORT DRIVER: if new rates need to be
    defined, create a new enumeration whose first entry has a value equal to
    #GDL_REFRESH_USER_DEFINED.  Since no internal port driver will support those
    modes, applications must make sure that only the external port driver is
    active on a display before setting the display to one of those modes.
*/
typedef enum
{
    GDL_REFRESH_23_98,      /**< 23.98... (24/1.001)    */
    GDL_REFRESH_24,         /**< 24                     */
    GDL_REFRESH_25,         /**< 25                     */
    GDL_REFRESH_29_97,      /**< 29.97... (30/1.001)    */
    GDL_REFRESH_30,         /**< 30 - DEPRECATED: This value is normally only
                                 used on computer systems and should be used
                                 with care, if at all. The corresponding TV
                                 rate is 30/(1.001) (see #GDL_REFRESH_29_97).
                            */
    GDL_REFRESH_50,         /**< 50                     */
    GDL_REFRESH_59_94,      /**< 59.94... (60/1.001)    */
    GDL_REFRESH_60,         /**< 60 - DEPRECATED: This value is normally only
                                 used on computer systems and should be used
                                 with care, if at all. The corresponding TV
                                 rate is 60/(1.001) (see #GDL_REFRESH_59_94).
                            */
    GDL_REFRESH_48,         /**< 48 - DEPRECATED: This value is normally only
                                 used on HDMI output with special sink device
                                 and should be used with care, if at all. */
    GDL_REFRESH_47_96,      /**< 47.96... (48/1.001)   */
    GDL_REFRESH_85,         /**< 85                     */
    GDL_REFRESH_100,        /**< 100...                */
    GDL_REFRESH_119_88,     /**< 119.88... (120/1.001) */
    GDL_REFRESH_120,        /**< 120...                */
    GDL_REFRESH_NONE,       /**< Indicates that mode is not set */
    GDL_REFRESH_USER_DEFINED/* External (non-Intel) port drivers may define
                               additional refresh rates that the support. Their
                               IDs must be numbered starting at this value.
                             */
} gdl_refresh_t;

/** @ingroup disp_mode
    pixel clocks for TV mode definitions.
*/
typedef enum
{
    GDL_PIXEL_CLOCK_25_175,    ///< 25.175Mhz
    GDL_PIXEL_CLOCK_25_200,    ///< 25.2Mhz
    GDL_PIXEL_CLOCK_27,        ///< 27Mhz
    GDL_PIXEL_CLOCK_27_027,    ///< 27.027Mhz
    GDL_PIXEL_CLOCK_59_340,    ///< 59.34Mhz   (Available only on CE5300)
    GDL_PIXEL_CLOCK_59_400,    ///< 59.4Mhz    (Available only on CE5300)
    GDL_PIXEL_CLOCK_118_681,   ///< 118.681Mhz (Available only on CE5300)
    GDL_PIXEL_CLOCK_118_800,   ///< 118.8Mhz   (Available only on CE5300)
    GDL_PIXEL_CLOCK_74_175,    ///< 74.175Mhz
    GDL_PIXEL_CLOCK_74_250,    ///< 74.25Mhz
    GDL_PIXEL_CLOCK_79_700,    ///< 79.7Mhz    (Available only on CE5300)
    GDL_PIXEL_CLOCK_148_350,   ///< 148.35Mhz
    GDL_PIXEL_CLOCK_148_500,   ///< 148.5Mhz
    GDL_PIXEL_CLOCK_296_700,   ///< 296.7Mhz   (Available only on CE5300)
    GDL_PIXEL_CLOCK_297,       ///< 297Mhz     (Available only on CE5300)
    GDL_PIXEL_CLOCK_MAX,       ///< end of pixel clock
} gdl_pixel_clock_t;

/** @ingroup disp_mode
    Display (pipe) ids.  The Intel CE Media Processors have two displays.
*/
typedef enum
{
    GDL_DISPLAY_ID_0 = 0,       ///< [Pipe A] Main display/HDMI
    GDL_DISPLAY_ID_1,           ///< [Pipe B] Secondary display/Composite
    GDL_DISPLAY_ID_UNDEFINED    ///< Undefined Pipe
} gdl_display_id_t;


/** @ingroup disp_mode
    This enumeration is used to specify a stereo (3D) video format.  The SOCs
    on which each format is supported are specified within square brackets.

    Format names ending in "_2" indicate that the format requires the use of
    two UPPs, one for the left view and one for the right. The
    #GDL_PLANE_STEREO_LEFT_VIEW attribute of the right view plane must be set
    to reference the left view plane in order to link them together.

    @b GDL_STEREO_NONE \n\n
       Indicates a mono display mode (no stereo format is in use).

    @b GDL_STEREO_FRAME_PACKING_2 \n\n
       Frame packing format implemented with 2 planes per stream.

    @b GDL_STEREO_FRAME_PACKING [CE4200-B and above] \n\n
       Single-plane frame packing format.

    @b GDL_STEREO_SIDE_BY_SIDE_HALF_2 \n\n
       Side-by-side format with the horizontal axis subsampled by half,
       implemented with 2 planes per stream.
       <b>NOTE:</b> Planes should be configured and buffers for graphics
       allocated at half horizontal resolution. The TV set is responsible for
       scaling the blended image horizontally by 2.

    @b GDL_STEREO_TOP_BOTTOM_HALF_2 \n\n
       Top-and-bottom format with the vertical axis subsampled by half,
       implemented with 2 planes per stream.
       <b>NOTE:</b> Planes should be configured and buffers for graphics
       allocated at half vertical resolution. The TV set is responsible for
       scaling the blended image vertically by 2.

    @b GDL_STEREO_FRAME_SEQUENTIAL \n\n
       Frame sequential format, a format used internally in some Digital TV
       sets for direct output to the panel. @b NOTE:  in order to use Frame
       Sequential format, the HDMI port driver must be loaded with the dtv=1
       command line argument.
*/
typedef enum
{
    GDL_STEREO_NONE = 0xabcdef01,
    GDL_STEREO_FRAME_PACKING_2,
    GDL_STEREO_FRAME_PACKING,
    GDL_STEREO_SIDE_BY_SIDE_HALF_2,
    GDL_STEREO_TOP_BOTTOM_HALF_2,
    GDL_STEREO_FRAME_SEQUENTIAL,
} gdl_stereo_t;


/** @ingroup disp_mode

    This structure describes a TV display mode.
*/
typedef struct
{
    gdl_uint32    width;
                    /**<
                    Active display width in pixels
                    */
    gdl_uint32    height;
                    /**<
                    Active display height in pixels
                    */
    gdl_refresh_t refresh;
                    /**<
                    Refresh frame rate: frames/sec in progressive display
                    modes, fields/sec in interlaced display modes.
                    */
    gdl_boolean_t interlaced;
                    /**<
                    GDL_TRUE=>interlaced, GDL_FALSE=>progressive
                    */
    gdl_stereo_t  stereo_type;
                    /**<
                    GDL_STEREO_NONE if this is a normal (mono) display mode.
                    Otherwise, the 3D frame format.

                    Note that in stereo display modes,
                    - The writeback plane is not usable and display 1 (Pipe B)
                      will not produce any output.
                    - Stereo video is supported on HDMI only. The component /
                      composite TV encoders must either be unloaded or
                      disconnected from both displays by setting their
                      GDL_PD_ATTR_ID_DISPLAY_PIPE attributes to
                      GDL_DISPLAY_ID_UNDEFINED.
                    - Mono video/graphics cannot be mixed with stereo. To
                      display a mono image, the same image must be flipped for
                      both the left and right views.
                    - On the CE4100, under GDL_STEREO_FRAME_PACKING_2 format the
                      y-coordinate of the origin (upper-left corner) of the
                      destination rectangle must be < 923 for all planes.
                    */
} gdl_tvmode_t;

/** @ingroup disp_mode
    Defines supported color spaces

    The BT601 and BT709 color spaces assume range limited content which lies in
    16 - 235 for Y and 16 - 240 for Cr and Cb. All conversions from another
    color space will implicitly scale values to fit in this range.

    If full range YCbCr processing is desired, conversions performed using the
    xvYCC color spaces will use the entire 0 - 255 range.

    xvYCC color spaces are only supported on CE5300. They are not supported on
    IAPs on any SoC.
*/
typedef enum
{
    GDL_COLOR_SPACE_BT601, ///< Normally used for Standard Definition YCbCr content
    GDL_COLOR_SPACE_BT709, ///< Normally used for High Definition YCbCr content
    GDL_COLOR_SPACE_RGB,   ///< Used for all RGB pixel formats
    GDL_COLOR_SPACE_XVYCC601, ///< Extended gamut BT601 (Available only on CE5300)
    GDL_COLOR_SPACE_XVYCC709, ///< Extended gamut BT709 (Available only on CE5300)
    GDL_COLOR_SPACE_COUNT  ///< Number of entries in this enumeration
} gdl_color_space_t;


/**@ingroup disp_mode

    Values that can be OR'd together to create an entry for the flags field of
    the #gdl_display_info_t structure.
    */
typedef enum
{
    GDL_DISPLAY_ZOOM_TO_FIT      = 0x00000001,
        /**<
        Display 1 can only be configured for SD display modes, which have a
        4:3 aspect ratio. When display 0 is in a 16:9 display mode, the
        setting of this flag is consulted to determine how the display 0 image
        should be scaled for output on display 1.

        The default (if this flag is not specified) is to scale the 16:9 image
        to 4:3 -- no data is lost, no black bars are displayed, but the image
        is distorted.  In this case, the application may wish to enable Wide
        Screen Signaling in the port driver.

        Specifying this flag selects a "zoom to fit" (letterboxing) scaling
        policy. This maintains the 16:9 aspect ratio on display 1 by scaling
        the image to the point where its width fills the display area. Black
        bars appear above and below the image.

        @note
        This flag can @b only be specified for display 1.
        */

    GDL_DISPLAY_SHARPEN          = 0x00000002,
        /**<
        This flag can be selected to "sharpen" the output on display 1 when
        displaying a static, full-screen graphic frame.

        Setting this flag will @b only produce optimal results if:
        - the graphics plane is configured to @b full-screen resolution (the
          resolution to which display 0 is currently configured), and
        - the original graphics content has the same resolution as the current
          configuration of display 1 (720x480 or 720x576).

        Setting this flag will probably @b degrade the quality of any animated
        or video plane being displayed.

        @note
        This flag can @b only be specified for display 1.
        */

    GDL_DISPLAY_SOFTWARE_VBI = 0x00000004,
        /**<
        * Deprecated
        */

} gdl_display_flag_t;


/** @ingroup disp_mode

    This structure describes the state of one of the displays.
*/
typedef struct
{
    gdl_display_id_t    id;
        /**< The ID of the display. */

    gdl_tvmode_t        tvmode;
        /**< The display mode */

    gdl_uint32          flags;
        /**<
        This is a set of bit flags formed by OR-ing together members of the
        #gdl_display_flag_t enumeration.
        */

    gdl_uint32          bg_color;
        /**<
        An RGB 10/10/10 value designating the "canvas" color that will appear
        on any part of the display that is not completely obscured by one or
        more opaque planes.
        @note
        Display 1's bg_color will never been seen unless the
        #GDL_DISPLAY_ZOOM_TO_FIT flag is set, in which case it will be used as
        the color of the horizontal bars used to "letter-box" 16:9 images on
        display 1. In all other cases, the blended display 0 image is always
        scaled to fit the display 1 exactly, leaving no portion of the canvas
        uncovered; even if there are no planes enabled on display 0, it
        is the display 0 bg_color that will be seen on display 1.
        */

    gdl_gamma_t         gamma;
        /**<
        Additive gamma to be applied to blended output sent to the display.
        */

    gdl_color_space_t   color_space;
        /**<
        The colorspace in which pixels are output on this display.  Planes on
        this pipe whose source pixels are in a different color space will be
        configured to perform color space conversion before outputting pixels
        to the blender.
        */
} gdl_display_info_t;


/*----------------------------------------------------------------------
 *                 P L A N E   M A N A G E M E N T
 *---------------------------------------------------------------------*/


/** @ingroup plane_management
    Value set to a planes GDL_PLANE_Z_ORDER attribute when plane does
    not have a Z-Order (IAP planes in alpha modes).
*/
#define GDL_ZORDER_NONE -1

/** @ingroup plane_management
    Plane IDs

    @b NOTES:

    Unlike other IAPs GDL_PLANE_ID_IAP_x can only be used in indexed mode. It
    is available on CE4200-B0 and above.\n

    GDL_PLANE_ID_UPP_E is only available:
       - For CE3100, CE4100 and CE4200-A in Blending Model 1\n
       - For CE4200-B in Blending Models 1 and 3\n
*/
typedef enum
{
    GDL_PLANE_ID_UNDEFINED = 0,     /**< A plane ID guaranteed to be invalid.
                                         Useful for initializing variables.
                                    */
    GDL_PLANE_ID_WBP,                  ///< Writeback plane
    GDL_PLANE_ID_IAP_x,                ///< Indexed plane x
    GDL_PLANE_ID_IAP_A,                ///< Indexed alpha plane A
    GDL_PLANE_ID_IAP_B,                ///< Indexed alpha plane B
    GDL_PLANE_ID_UPP_A,                ///< Universal pixel plane A
    GDL_PLANE_ID_UPP_B,                ///< Universal pixel plane B
    GDL_PLANE_ID_UPP_C,                ///< Universal pixel plane C
    GDL_PLANE_ID_UPP_D,                ///< Universal pixel plane D
    GDL_PLANE_ID_UPP_E,                ///< Universal pixel plane E
    GDL_MAX_PLANES=GDL_PLANE_ID_UPP_E, ///< The total number of planes

#ifndef DOXYGEN_SKIP /* Omit the following when docs are generated */
    /* THESE ARE FOR INTERNAL DRIVER USE ONLY */
    GDL_PLANE_ID_UPP_WB,
    GDL_MAX_PLANES_INTERNAL=GDL_PLANE_ID_UPP_WB
#endif
} gdl_plane_id_t;

/** @ingroup plane_management
Maximum number of UPPs
*/
#define GDL_MAX_UPPS 5

/** @ingroup plane_management
Maximum number of IAPs
*/
#define GDL_MAX_IAPS 3

/** @ingroup plane_management

    This structure specifies a color in a manner independent of exact pixel
    format.  It is generally used to supply the color component values of a
    pixel in a context in which the pixel format and/or color space are
    indicated separately by enumerators of the appropriate type.

    For formats that include alpha components (or that are alpha-only), the
    alpha_index field holds the alpha value.

    For palettized (CLUT) color formats, only the alpha_index field is used, and
    it holds the 0-based palette index.

    For other RGB formats:
    - r_y holds the Red   color component
    - g_u holds the Green color component
    - b_v holds the Blue  color component

    For YUV (YCbCr) formats:
    - r_y holds the Y component
    - g_u holds the U (Cb) component
    - b_v holds the V (Cr) component
*/
typedef struct
{
    gdl_uint16 alpha_index; ///< Alpha or Index component
    gdl_uint16 r_y;         ///< Red,   Y, or Y' component
    gdl_uint16 g_u;         ///< Green, U, or Cb component
    gdl_uint16 b_v;         ///< Blue,  V, or Cr component
} gdl_color_t;


/** @ingroup plane_management
    This enumeration is used to specify the model to be used by the display
    driver when the SMD video renderer passes a frame whose dimensions do not
    match those of the target plane's current #GDL_PLANE_DST_RECT attribute.
*/
typedef enum
{
    GDL_VID_POLICY_BLACK_FRAME,
        /**<
        Black frame will be displayed if frame's dimensions do not match
        plane's #GDL_PLANE_DST_RECT attribute
        */
    GDL_VID_POLICY_RESIZE,
        /**<
        #GDL_PLANE_DST_RECT will be automatically resized to the size
        of the passed video frame.
        */
    GDL_VID_POLICY_CONSTRAIN,
        /**<
        #GDL_PLANE_VID_SRC_RECT and #GDL_PLANE_VID_DST_RECT are used to
        determine what portion of the video frame is displayed and where.
        */
    GDL_VID_POLICY_COUNT,
} gdl_vid_policy_t;


/** @ingroup plane_management
    Flags indicating how a surface flip should be scheduled by gdl_flip().
*/
typedef enum
{
    GDL_FLIP_ASYNC = 3,
        /**<
        gdl_flip() returns immediately to the caller. The flip begins on the
        next VBlank, as long as it is not over-ridden by a new flip to the same
        plane before then.
        */

    GDL_FLIP_SYNC = 4,
        /**<
        gdl_flip() does not return to the caller until scan-out of the surface
        onto the display has begun. New flip can be submitted at this point
        to the same plane without over-writing the previous flip.

        In stereoscopic modes, gdl_flip_stereo() also ensures that both left
        and right views will be displayed if a new flip is submitted.
        */
} gdl_flip_t;


/** @ingroup plane_management
    This enumeration defines the various attributes that may be implemented by
    a hardware plane.  These values are used in three different ways:

    - to determine plane capabilities\n\n
      The function gdl_plane_capabilities() returns a plane capability array.
      To determine if an attribute is supported by the plane, use the
      corresponding enumeration value as an index into the array.  If the
      indexed entry is non-zero, the attribute is supported; otherwise it isn't.

    - to configure a plane\n\n
      The various set functions (e.g., gdl_plane_set_int()) allow the setting
      of individual attributes of the plane by specifying attribute name-value
      pairs.  The "names" in these pairs are members of this enumeration.

    - to examine the configuration of a plane\n\n
      The various get functions (e.g., gdl_plane_get_int()) allow the current
      value of an attribute to be queried by name.  The "names" used in these
      queries are members of this enumeration.

    The descriptions of the individual enumerated values contain the following
    fields:
    - @b Capability: what a non-zero entry in the corresponding entry of
         the capabilities array indicates.\n
    - @b Attribute: what the attribute controls.\n
    - @b Value: the data type of the attribute, which determines which get/set
         function should be used to manipulate it.  Where relevant, the
         range of legal values for the attribute is listed.  Note that
         enumerations are treated as uint values with a range restricted by the
         enum definition.
    - @b Default: the default setting of the attribute when the system is
         powered up.

    On the Intel CE Media Processors, the capabilities supported by the planes
    are as follows:
    - UPPs/IAPs/WBP:
        - #GDL_PLANE_HIDE
    - UPPs/IAPs:
        - #GDL_PLANE_ALPHA_GLOBAL
        - #GDL_PLANE_ALPHA_PREMULT
        - #GDL_PLANE_CSC_ADJUST
        - #GDL_PLANE_CSC_BASE
        - #GDL_PLANE_CSC_INPUT_CLAMPS
        - #GDL_PLANE_CSC_OUTPUT_CLAMPS
        - #GDL_PLANE_CSC_CLAMPS_OVERRIDE
        - #GDL_PLANE_DISPLAYED_SURFACE
        - #GDL_PLANE_DST_RECT
        - #GDL_PLANE_FLIP
        - #GDL_PLANE_LINE_REPLICATION
        - #GDL_PLANE_PIXEL_EXTENSION
        - #GDL_PLANE_PIXEL_FORMAT
        - #GDL_PLANE_PIXEL_REPLICATION
        - #GDL_PLANE_SRC_COLOR_SPACE
        - #GDL_PLANE_SRC_RECT
        - #GDL_PLANE_STEREO_LEFT_VIEW
        - #GDL_PLANE_Z_ORDER
    - UPPs:
        - #GDL_PLANE_CHROMA_KEY_SRC_ENABLE,
        - #GDL_PLANE_CHROMA_KEY_SRC_HIGH,
        - #GDL_PLANE_CHROMA_KEY_SRC_LOW,
        - #GDL_PLANE_NUM_GFX_SURFACES,
        - #GDL_PLANE_REVERSE_GAMMA_TYPE,
        - #GDL_PLANE_SCALE
        - #GDL_PLANE_VID_DST_RECT
        - #GDL_PLANE_VID_MISMATCH_POLICY
        - #GDL_PLANE_VID_MUTE
        - #GDL_PLANE_VID_SRC_RECT
        - #GDL_PLANE_422_TO_444_COEFF \e *
    - IAPs:
        - #GDL_PLANE_ALPHA_OUT
    - WBP:
        - #GDL_PLANE_SCALE_SHARPNESS

    <em>* = Only supported on CE4100 and above</em>
*/
typedef enum
{
    GDL_PLANE_ALPHA_GLOBAL,
        /**<
        @b Capability: \n
        The plane supports a settable global alpha value.

        @b Attribute: \n
        the current global alpha value.

        @b Value: uint in [0, 255]

        @b Default: 255 (opaque)
        \n\n
        */

    GDL_PLANE_ALPHA_OUT,
        /**<
        @b Capability: \n
        The plane can provide alpha values for another plane.

        @b Attribute: \n
        The ID of the plane to which the alpha values should be sent.

        @b Value: #gdl_plane_id_t

        @b Default: #GDL_PLANE_ID_UNDEFINED

        <b>Programming Notes</b>
        - This attribute is available on IAPs (Indexed/Alpha planes) only.
        - The IAP_x plane (CE4200 B and above) @b cannot supply alpha values
          for other planes.
        - When the value of this attribute is set to #GDL_PLANE_ID_UNDEFINED,
          the IAP is configured to output 8-bit palette-based pixels, and its
          #GDL_PLANE_PIXEL_FORMAT attribute must be set to specify an 8-bit
          CLUT pixel format.
        - When the value of this attribute is set to a valid plane ID, the IAP
          is configured to provide alpha values for the specified plane, and its
          #GDL_PLANE_PIXEL_FORMAT attribute must specify an alpha format.
          Each pixel in the IAP provides the alpha value for the pixel it
          overlaps on-screen in the specified destination plane.
        - On the Intel CE Media Processors,
            - IAP A can only provide alpha values to UPPs with z-order 0, 1, or
              2.
            - IAP B can only provide alpha values to UPPs with z-order 3 or 4.
            .
        - If the destination rectangle of an IAP is different from that of
          its associated UPP, the UPP pixels where there is no overlap will
          receive alpha values of @b zero and will become transparent.
        - Similarly, if an IAP is @b disabled without removing the assignment,
          the associated UPP will become completely transparent.
        .
        \n
        */

    GDL_PLANE_ALPHA_PREMULT,
        /**<
        @b Capability: \n
        The plane's pixel values can be interpreted as containing premultiplied
        alpha values.

        @b Attribute: \n
        Enables/disables use of premultiplied alpha.

        @b Value: uint (#gdl_boolean_t)

        @b Default: #GDL_FALSE (disabled)

        <b>Programming Notes</b>
        - This value is ignored if the plane's current pixel format does not
          include a per-pixel alpha value.
        - @b CAUTION: This attribute cannot operate correctly in conjunction
          with the following features.  An attempt to enable premultiplied alpha
          and any of the following at the same time will return an error of type
          #GDL_ERR_PREMULT_CONFLICT.
          - chroma keying on the same plane (#GDL_PLANE_CHROMA_KEY_SRC_ENABLE
            set to #GDL_TRUE)
          - gamma removal from the same plane (#GDL_PLANE_REVERSE_GAMMA_TYPE set
            to a value other than #GDL_GAMMA_LINEAR).
          - color space conversion (the value of the plane's
            #GDL_PLANE_SRC_COLOR_SPACE attribute is different from the color
            space of the display to which it is connected). This restriction is
            only applicable for Intel CE3100 and CE4100 A-step platforms.
          - a non-RGB pixel format.
          .
        .
        \n
        */

    GDL_PLANE_ANAMORPHIC_REGIONS,
        /**<
        @b Capability: \n
        The plane supports configurable anamorphic scaling

        @b Attribute: \n
        Anamorphic scaling allows for a non-uniform horizontal scaling ratio
        across the plane. The destination rectangle of the plane is divided
        into 2 - 7 regions. The width of each region is given as a percentage
        of the overall #GDL_PLANE_SRC_RECT attribute width.

        Two scaling ratios must be defined for each region, corresponding to the
        left and right edges.  They are relative values, which are scaled so
        that the entire source rectangle will be displayed.

        <b>Programming Notes</b>\n
        There are several restrictions when using anamorphic scaling:\n
            - The region width percentages must add up to 100.0%
            - Any stereo shift passed into #gdl_flip_stereo must be even

        @b Value: #gdl_anamorphic_regions_t

        @b Default: \n
        Two regions, each with 50% width. All scaling ratios are set to 1.0
        \n\n
        */

    GDL_PLANE_CHROMA_KEY_SRC_ENABLE,
        /**<
        @b Capability: \n
        The plane supports source luma/chroma keying.

        @b Attribute: \n
        Enables/disables luma/chroma keying on the plane.  Actual chroma key
        values are set through the #GDL_PLANE_CHROMA_KEY_SRC_HIGH and
        #GDL_PLANE_CHROMA_KEY_SRC_LOW attributes.

        @b Value: #gdl_boolean_t

        @b Default: #GDL_FALSE (Chroma keying is disabled)
        \n\n
        */

    GDL_PLANE_CHROMA_KEY_SRC_HIGH,
        /**<
        @b Capability: \n
        Plane supports source chroma key range.

        @b Attribute: \n
        The upper limit of the luma/chroma keying range. This value is ignored
        unless the #GDL_PLANE_CHROMA_KEY_SRC_ENABLE is set to #GDL_TRUE

        @b Value: #gdl_color_t

        @b Default: 0,0,0

        <b>Programming Notes</b>
        - The value is interpreted as RGB or YCbCr according to the plane's
          current #GDL_PLANE_SRC_COLOR_SPACE attribute setting. Any alpha value
          set for this attribute is ignored.
        - The number of bits used in each field of the structure should
          correspond to the current #GDL_PLANE_PIXEL_FORMAT attribute.  E.g.,
          if the pixel format is #GDL_PF_RGB_16, g_u should be a 6-bit value and
          r_y/b_v should be 5-bit values. Any bits which are set invalid in the
          current pixel format are ignored.
        - The programmer is responsible for correctly coordinating the values of
          #GDL_PLANE_CHROMA_KEY_SRC_HIGH and #GDL_PLANE_CHROMA_KEY_SRC_LOW with
          the settings of #GDL_PLANE_SRC_COLOR_SPACE, #GDL_PLANE_PIXEL_FORMAT,
          and #GDL_PLANE_ALPHA_PREMULT.
        .
        \n
        */

    GDL_PLANE_CHROMA_KEY_SRC_LOW,
        /**<
        Same as #GDL_PLANE_CHROMA_KEY_SRC_HIGH, except that it identifies the
        lower end of the luma/chroma keying range.\n
        \n
        */

    GDL_PLANE_CSC_ADJUST,
        /**<
        @b Capability: \n
        The plane can support Color Space Conversion (CSC).

        @b Attribute: \n
        Planes perform CSC from the color space specified in the
        #GDL_PLANE_SRC_COLOR_SPACE attribute, to the blender color space (as
        specified via the #gdl_display_info_t structure). The three components
        of a color from an input color space (CrR, YG, and CbB) are converted
        to the three components of an output color space (CrR', YG', and CbB')
        according to the following equations:
        @verbatim
CrR'= (CrR+off1)*c0 + (YG+off2)*c1 + (CbB+off3)*c2 + off4
YG' = (CrR+off1)*c3 + (YG+off2)*c4 + (CbB+off3)*c5 + off5
CbB'= (CrR+off1)*c6 + (YG+off2)*c7 + (CbB+off3)*c8 + off6
        @endverbatim
        For each supported combination of color spaces, the display driver
        selects the appropriate values of the offsets offN and coefficients cN.

       The GDL_PLANE_CSC_ADJUST attribute allows the programmer to modify the
       current CSC of a plane by supplying a set of adjustments for the current
       offsets and coefficients.  The adjustments are specified using a
       variable of type gdl_csc_t.  The offsets of this attribute value are @b
       added to the corresponding offsets in each equation, and the equation
       coefficients are @b multiplied by the corresponding coefficients of the
       attribute value.  By varying the adjustment, a (highly knowledgable)
       user can adjust color attributes such as hue, brightness, and
       saturation.

       The final adjusted offsets have a valid range of [-1024, 1023].

       Note that planes are @b always programmed to perform CSC even if the
       input and output color spaces of the plane are identical; when they are
       equal, the driver selects coefficients and offsets that do not actually
       cause any modification of the source pixels. This allows this attribute
       to be used to adjust color attributes even if no actual change in color
       space is taking place.

        @b Value: #gdl_csc_t

        @b Default: \n
        In the default adjustment structure, all offset adjustments are 0, and
        all coefficient adjustments are 1.0.  These adjustment values leave the
        equation for the current CSC operation unchanged.
        \n\n
        */

    GDL_PLANE_CSC_BASE,
        /**<
        @b Capability: \n
        The plane can support color space conversion.

        @b Attribute: \n
        The default coefficients used for this color space conversion (which is
        determined by the plane's source color space and the blending color
        space).  The final values which are used in the conversion may be
        adjusted through the #GDL_PLANE_CSC_ADJUST attribute. Any adjustments
        are not shown in this attribute.

        @b Value: #gdl_csc_t

        @b Default: N/A. <b>THIS VALUE IS READ-ONLY</b>
        */

    GDL_PLANE_CSC_INPUT_CLAMPS,
        /**<
        @b Capability: \n
        The plane can support adjustable Color Space Conversion (CSC) input
        clamps.

        @b Attribute: \n
        When performing a color space conversion, it is sometimes necessary
        to clamp the input or output pixels to a valid range. This attribute
        will adjust the range.

        For the CE3100, CE4100 and CE4200 SoCs, only a few defined settings are
        valid:

        - RGB:      <tt>YG=<16, 235>, CB=<16, 235>, CR=<16, 235></tt>
        - YCbCr:    <tt>YG=<16, 235>, CB=<16, 240>, CR=<16, 240></tt>
        - Disabled: <tt>YG=<0,  255>, CB=<0,  255>, CR=<0,  255></tt>

        where the format is <tt><min, max></tt>. All other settings are not
        supported by the hardware.

        For CE5300, input clamps have a range of [0, 255]. The
        #GDL_PLANE_PIXEL_EXTENSION attribute controls how these values are
        scaled to the necessary internal representation.

        @note
        This attribute only takes effect when the #GDL_PLANE_CSC_CLAMPS_OVERRIDE
        attribute is set to GDL_TRUE

        @b Value: #gdl_csc_clamps_t

        @b Default: \n
        Disabled: <tt><0, 255></tt> for all color components
        \n\n
        */

    GDL_PLANE_CSC_OUTPUT_CLAMPS,
        /**<
        @b Attribute: \n
        Same as the #GDL_PLANE_CSC_INPUT_CLAMPS attribute, except that it
        specifies output clamps (after the CSC operation has been performed).

        For CE5300, UPP output clamps have a range of [-256, 255].
                    IAP output clamps have a range of [0, 255].

        @b Default: \n
        Disabled: <tt><0, 255></tt> for all color components
        \n\n
        */

    GDL_PLANE_CSC_CLAMPS_OVERRIDE,
        /**<
        @b Capability: \n
        The plane supports user-programmable clamp settings

        @b Attribute: \n
        When this attribute is set to GDL_TRUE, then the clamping values
        set in the #GDL_PLANE_CSC_INPUT_CLAMPS and #GDL_PLANE_CSC_OUTPUT_CLAMPS
        attributes are used. The #GDL_PLANE_PIXEL_EXTENSION attribute controls
        how these values are scaled internally.

        When this attribute is set to GDL_FALSE, the standard clamps for the
        color space conversion being performed are used. These defaults are not
        visible in any attributes.

        @b Value: #gdl_boolean_t

        @b Default: \n
        GDL_FALSE
        \n\n
        */

    GDL_PLANE_DISPLAYED_SURFACE,
        /**<
        @b Capability: \n
        Surfaces can be flipped onto the plane with the gdl_flip() function.
        See also #GDL_PLANE_FLIP.

        @b Attribute: \n
        The ID of the surface currently being scanned out by the plane.  The
        surface is at least partially visible.  If the value of this attribute
        is #GDL_PLANE_ID_UNDEFINED, the plane is disabled.
        @note
        This attribute only returns IDs of GDL surfaces flipped with the
        gdl_flip() function. If the plane has been assigned to an SMD video
        pipeline, values returned for this attribute are @b invalid.

        @b Value: uint (#gdl_surface_id_t)

        @b Default: N/A. <b>THIS VALUE IS READ-ONLY</b>.
        \n\n
        */

    GDL_PLANE_DISPLAY_ID,
        /**<
        @b Capability: \n
        Plane is exposed to the caller.

        @b Attribute: \n
        The Display ID to which the plane is assigned.

        @b Value: #gdl_plane_id_t

        @b Default: N/A. <b>THIS VALUE IS READ-ONLY</b>
        */


    GDL_PLANE_DST_RECT,
        /**<
        @b Capability: \n
        The plane's dimensions and its location on the display can be changed.

        @b Attribute: \n
        A rectangle defining the dimensions of the plane and its location on
        the display.

        @b Value: rect (#gdl_rectangle_t)

        @b Default: 320x240

        <b>Programming Notes</b>
        - The rectangle's origin:
            - is relative to the upper left corner of the display.
            - must have non-negative coordinates.
            - must lie within the active display region.
        - The rectangle's height and width must be such that the lower right
          corner of the rectangle also lies within the active display region.
          Line and pixel replication (if enabled) must be taken into account
          when determining the rectangle's size.
        - On the Intel CE Media Processors, the plane can not be less than 16
          pixels wide by 2 pixels high.
        - If the scaling is enabled (#GDL_PLANE_SCALE), the destination
          dimensions must not be below 32x32.
        - If the display is in an interlaced mode:
            - the y-coordinate of the origin must specify an even-numbered
              display line (the top line of the display is line 0).
            - the height must be even.
            .
        .
        \n
        */

    GDL_PLANE_FLIP,
        /**<
        @b Capability: \n
        Surfaces can be flipped onto the plane with the gdl_flip() function.
        See also #GDL_PLANE_DISPLAYED_SURFACE.

        @b Attribute: \n
        The ID of the surface currently flipped onto the plane.

        "Flipping" a surface is the act of programming the VDC registers with
        the address of the surface buffer.  However, the plane does not begin
        to scan out the contents of the surface until the next Framestart
        signal after the programming is done. (Framestart occurs sometime
        between VBlank and VSync). Therefore, the surface whose ID is returned
        as this attribute may not actually be visible yet.  See
        #GDL_PLANE_DISPLAYED_SURFACE for the ID of the currently displayed
        surface.  If the value of GDL_PLANE_FLIP is #GDL_PLANE_ID_UNDEFINED,
        the plane will be @b disabled at the next Framestart (if it isn't
        already).
        @note
        This attribute only returns IDs of GDL surfaces flipped with the
        gdl_flip() function. If the plane has been assigned to an SMD video
        pipeline, values returned for this attribute are @b invalid.

        @b Value: uint (#gdl_surface_id_t)

        @b Default: N/A. <b>THIS VALUE IS READ-ONLY</b>.
        \n\n
        */

    GDL_PLANE_HIDE,
        /**<
        @b Capability: \n
        The plane can be made invisible, hiding planes contents from being
        displayed.

        @b Attribute: \n
        Hides/unhides the plane. While the plane is hidden, it must conform to
        all existing plane configuration restrictions and rules.

        The plane will be visible only if the attribute is set to GDL_FALSE and
        the plane is not disabled.

        @b Value: #gdl_boolean_t

        @b Default: GDL_FALSE

        <b>Programming Notes</b>
        When enabled on the writeback plane (WBP), this attribute will cause 
        "simultaneous" output to be disabled on GDL_DISPLAY_ID_1. Instead, a canvas
        color on GDL_DISPLAY_ID_1 will be visible.
        */


    GDL_PLANE_STEREO_LEFT_VIEW,
        /**<
        @b Capability: \n
        The plane can be used as the "right view" in 2-plane stereo display
        modes.

        @b Attribute: \n
        This attribute is ignored except in 2-plane stereo display modes, i.e.,
        those modes in which 'stereo_type' is one of the following:
        - #GDL_STEREO_FRAME_PACKING_2
        - #GDL_STEREO_TOP_BOTTOM_HALF_2
        - #GDL_STEREO_SIDE_BY_SIDE_HALF_2

        Its value is the ID of the plane which acts as the "left view" for the
        current plane, which is assumed to be a "right view" plane. It must be
        set to #GDL_PLANE_ID_UNDEFINED for all "left view" planes.

        In 2-plane stereo modes,
        - All enabled planes must be paired in this way: IAPs as well as UPPs,
          graphics as well as video content, mono streams as well as stereo
          streams.
        - IAPs can only be paired with IAPs, and UPPs with UPPs.
        - No plane can be specified as its own Left View, nor can any plane can
          be specified as the left view of more than one other plane.
        - Results are undefined if paired planes are not identically
          configured.  Note this implies that the CE4100's single VDC scaler
          cannot be assigned to any plane in stereo display modes.

        @b Value: gdl_plane_id_t

        @b Default: GDL_PLANE_ID_UNDEFINED
        \n\n
        */

    GDL_PLANE_LINE_REPLICATION,
        /**<
        @b Capability: \n
        The plane can output each scan line multiple times.

        @b Attribute: \n
        The number of times each line should be output.  A value of 1 indicates
        normal output; a value of 2 indicates line-doubling.

        @b Value: uint in [1,2]

        @b Default: 1

        <b>Programming Notes</b>
        - The #GDL_PLANE_DST_RECT attribute should be set to the non-replicated
          dimensions. E.g, a plane whose dimensions are 720x240 will be
          displayed as 720x240 when line replication is 1, and 720x480 when
          line replication is 2. #GDL_ERR_DISPLAY_CONFLICT will be returned if
          turning on line replication would cause the plane not to fit entirely
          within the display.
        - Pixel and line replication are not supported while #GDL_PLANE_SCALE
          attribute is enabled on that plane.
        .
        \n
        */

    GDL_PLANE_NUM_GFX_SURFACES,
        /**<
        @b Capability: \n
        The plane can support flip chains for the graphics driver APIs.

        @b Attribute: \n
        Indicates whether the plane will be double-, or triple-buffered for
        flip operations performed via the graphics APIs.  The value of this
        attribute is only used when the plane's ID is passed to
        eglWindowSurfaceCreate() (see the Intel CE Media Processors Graphics
        Driver Programming Guide):
        - The EGL function examines the attribute to determine the number of
          flippable surfaces to request from the display driver (subject to
          memory availability).
        - The pixel format and dimensions of the surfaces will be based on the
          plane's pixel format and dimensions at the time of the call.
        .
        @b Value: uint in [2,3] \n

        @b Default: 3
        \n\n
        */

    GDL_PLANE_PIXEL_EXTENSION,
        /**<
        @b Capability: \n
        The plane supports pixel component extension.  Internally, all planes
        extend their pixels to 10-bits per component prior to blending.  See
        the description of #gdl_pixel_extension_t for further details.

        @b Attribute: \n
        Method used to extend pixel component values.

        @b Value: uint (#gdl_pixel_extension_t)

        @b Default: #GDL_PIXEL_EXTENSION_ZERO_PAD
        \n\n
        */

    GDL_PLANE_PIXEL_FORMAT,
        /**<
        @b Capability: \n
        The plane's pixel format can be changed.

        @b Attribute: \n
        The plane's current pixel format.

        @b Value: uint (#gdl_pixel_format_t)

        @b Default:
        - for UPPs: #GDL_PF_NV16
        - for IAPs: #GDL_PF_ARGB_8
        .
        \n
        */

    GDL_PLANE_PIXEL_REPLICATION,
        /**<
        @b Capability: \n
        The plane can output each pixel on a line multiple times.

        @b Attribute: \n
        The number of times each pixel on a line is output. A value of 1
        indicates normal output; a value of 2 indicates pixel-doubling.

        @b Value: uint in [1,2]

        @b Default: 1

        <b>Programming Notes</b>
        - The #GDL_PLANE_DST_RECT attribute should be set to the
          non-replicated dimensions. E.g, a plane whose dimensions are 360x480
          will be displayed as 360x480 when pixel replication is 1, and
          720x480 when pixel replication is 2. #GDL_ERR_DISPLAY_CONFLICT will
          be returned if turning on pixel replication would cause the plane
          not to fit entirely within the display.\n
        - Pixel and line replication are not supported while #GDL_PLANE_SCALE
          attribute is enabled on that plane.
        .
        \n
        */

    GDL_PLANE_REVERSE_GAMMA_TYPE,
        /**<
        @b Capability: \n
        The plane can remove gamma correction from source material prior to
        outputting pixels for blending with other planes.

        @b Attribute: \n
        The type of reverse gamma correction currently in use.

        @b Value: uint (#gdl_gamma_t)

        @b Default: #GDL_GAMMA_LINEAR

        <b>Programming Notes</b>
        - Gamma removal will work correctly only if the gamma was originally
          applied in the same color space as the one in which blending is
          currently being done (the current color space of Display 0).
        - Note that it is impossible to detect from a video clip the color
          space in which gamma was applied. The color space of the clip can be
          determined, e.g. BT601, but the gamma may have been applied in RGB
          color space by the camera before it output BT601.
        - It is the application's responsibility to determine that the feature
          will work correctly in a given display mode for a given clip. If the
          results do not look correct, it is likely that this requirement was
          not met.
        .
        \n
        */

    GDL_PLANE_SCALE,
        /**<
        @b Capability: \n
        The plane can perform scaling of the surfaces flipped to the plane
        based on the relative sizes of the plane's source (#GDL_PLANE_SRC_RECT)
        and destination (#GDL_PLANE_DST_RECT) rectangles

        @b Attribute: \n
        Enables/disables scaling on the plane.

        @b Value: #gdl_boolean_t

        @b Default: #GDL_FALSE (scaling disabled)

        <b>Programming Notes</b>
        - The number and type of scalers available depends on the target
          processor:
          - CE3100/CE4100: a single bilinear scaler is available.  <b>It has
            the following restrictions:</b>
            - it is not capable of downscaling.
            - it cannot act on planes whose #GDL_PLANE_SRC_RECT width exceeds
              1280.
            .
          - CE4200: Two polyphase scalers are available. <b>They have the
            following restrictions:</b>
            - Scaling is not supported in interlaced display modes.
        .
        - A scaler is allocated to a plane when this attribute is enabled and
          deallocated when it is disabled. Once all scalers have been allocated
          to planes, attempts to enable scaling on additional planes will fail.
        - It is an error to enable plane scaling and pixel/line doubling on the
          same plane at the same time. The programmer must explicitly disable
          one when (or before) enabling the other.
        - It may be necessary to change the source and/or destination
          rectangles of the plane in the same configuration transaction as the
          enabling/disabling of the scaling in order to achieve the desired
          results. For example, since the CE3100/CE4100 are only capable of
          upscaling, it is an error to enable scaling with the dimensions of the
          source rectangle greater than those of the destination rectangle.
        \n\n
        */

    GDL_PLANE_SCALE_ANAMORPHIC,
        /**<
        @b Capability: \n
        The plane can support anamorphic scaling of the plane's content

        @b Attribute: \n
        Enables/disables anamorphic scaling on the plane. The #GDL_PLANE_SCALE
        attribute must also be enabled. Additionally, the
        #GDL_PLANE_ANAMORPHIC_REGIONS attribute must be configured appropriately
        for the #GDL_PLANE_SRC_RECT and #GDL_PLANE_DST_RECT attributes.

        @note
        Animated zoom (changing the destination rectangle size over time to
        produce an animated scaling effect) is not supported for anamorphic
        scaling. Changing the destination rectangle size without the animation
        effect (for example, converting a PIP window into a full screen one) is
        supported.

        @b Value: #gdl_boolean_t

        @b Default: #GDL_FALSE (anamorphic scaling disabled)
        \n\n
        */

    GDL_PLANE_SCALE_SHARPNESS,
        /**<
        @b Capability: \n
        The plane can support setting of the scalers sharpness.

        @b Attribute: \n
        Sharpness to use with the scaling coefficients. Higher values produce
        a sharper image.

        @b Value: uint [0,50]

        @b Default: 0

        @b NOTE: Only supported on the writeback plane. For the writeback plane
        the default value of this attribute is set to the value of a load-time
        wbp_scaler_sharpness=x attribute
        */

    GDL_PLANE_SRC_COLOR_SPACE,
        /**<
        @b Capability: \n
        The plane can perform color space conversion when its pixel data is
        output to the blender.

        @b Attribute: \n
        An enumerated value indicating the color space of the plane's source
        pixels (the color space of pixels in surfaces that will be flipped onto
        the plane).  The pixels will be converted from that color space to the
        current blender color space when they are output by the plane.  NOTE:
        on IAPs, this attribute is ignored when the plane is used in alpha
        output mode (i.e., when the #GDL_PLANE_ALPHA_OUT attribute is set to a
        value other than #GDL_PLANE_ID_UNDEFINED).

        @b Value: uint (#gdl_color_space_t)

        @b Default:
        - For UPPs: #GDL_COLOR_SPACE_BT601
        - For IAPs: #GDL_COLOR_SPACE_RGB
        .
        \n
        */

    GDL_PLANE_SRC_RECT,
        /**<
        @b Capability: \n
        The plane supports the ability to pan and/or scale source surfaces.

        @b Attribute: \n
        A rectangle applied to all surfaces flipped onto the plane, where:
        - The @b origin allows panning over a surface that is larger than the
          plane. The origin is specified as non-negative coordinates relative
          to the upper left corner of the surface. It indicates the surface
          pixel that will appear at the origin (upper left corner) of the
          plane.
        - The @b height and @b width are interpreted as follows:
          - If the plane is a UPP on which scaling has been enabled (i.e., the
            #GDL_PLANE_SCALE attribute has been set to #GDL_TRUE), the region
            of the surface specified by these dimensions is scaled to fit the
            destination rectangle.
          - Otherwise, the height and width of the source rectangle @b are @b
            ignored.  The region of the surface that is displayed is determined
            by the height and width of the destination rectangle.
          .
        .
        @b Value: rect (#gdl_rectangle_t)

        @b Default: Initial value of #GDL_PLANE_DST_RECT.

        <b>Programming Notes</b>
        - If an interlaced display mode is in effect, the low order bit of the
          y-coordinate is ignored (the origin will always be on an
          even-numbered display line).
        - If an interlaced display mode is in effect and scaling is enabled,
          source height must be an even number.
        - If scaling is enabled then the source rectangle dimensions must be
          between the values of 32x32 and 1920x1080.
        - A flip will fail if the plane's source rectangle results in an origin
          or a lower right corner that does not lie within the surface being
          flipped.
        - When #GDL_PLANE_SCALE is enabled, the width of the source rectangle
          cannot exceed 1280.
        .
        \n
        */

    GDL_PLANE_VID_DST_RECT,
        /**<
        @b Capability: \n
        The plane can be made a video sink for the SMD video pipleine (by
        passing its ID to ismd_vidrend_set_video_plane()).

        @b Attribute: \n
        This attribute is ignored unless #GDL_PLANE_VID_MISMATCH_POLICY is set
        to #GDL_VID_POLICY_CONSTRAIN.  Under that policy, when video frames are
        flipped onto the plane by SMD, the display driver automatically
        reprograms GDL_PLANE_DST_RECT to accommodate the size of the frame,
        subject to the height/width limits specified by this rectangle. The
        origin of this rectangle will become the display coordinates of the
        origin of the plane on the display.  Content larger than the dimensions
        of this rectangle will be cropped at the right/bottom.

        <b>Programming Notes</b> \n
        The Programming Notes specified for #GDL_PLANE_DST_RECT apply to this
        attribute also.

        @b Value: rect (#gdl_rectangle_t)

        @b Default: 320x240@(0,0)
        \n\n
        */

    GDL_PLANE_VID_MISMATCH_POLICY,
        /**<
        @b Capability: \n
        The plane can be made a video sink for the SMD video pipleine (by
        passing its ID to ismd_vidrend_set_video_plane()).

        @b Attribute: \n
        This attribute specifies the policy to be used by the display driver
        when SMD flips a video frame whose dimensions do not match those of the
        target plane's current #GDL_PLANE_DST_RECT attribute.

        @b Value: policy enumerator (#gdl_vid_policy_t)

        @b Default: #GDL_VID_POLICY_BLACK_FRAME
        \n\n
        */

    GDL_PLANE_VID_MUTE,
        /**<
        @b Capability: \n
        The plane can be made a video sink for the SMD video pipeline (by
        passing its ID to ismd_vidrend_set_video_plane()).

        @b Attribute: \n
        Once a plane has been designated a video sink, video frames are
        displayed on it automatically by the SMD video pipeline. Whenever this
        attribute is set to #GDL_TRUE, the display driver will ignore all
        frames flipped to the plane by SMD, and the plane can be used for any
        purpose by the application. Video output can be resumed by setting the
        value back to #GDL_FALSE

        @b Value: gdl_boolean_t

        @b Default: GDL_FALSE
        \n\n
        */

    GDL_PLANE_VID_SRC_RECT,
        /**<
        @b Capability: \n
        The plane can be made a video sink for the SMD video pipleine (by
        passing its ID to ismd_vidrend_set_video_plane()).

        @b Attribute: \n
        This attribute is ignored unless #GDL_PLANE_VID_MISMATCH_POLICY is set
        to #GDL_VID_POLICY_CONSTRAIN. It specifies a rectangle used to select
        the active portion of content (source) video frames flipped by SMD onto
        the plane. The intersection of this rectangle with the flipped frame
        constitutes the image to be displayed. The origin of this rectangle is
        specified relative to the origin of the passed frame.

        @b Value: rect (#gdl_rectangle_t)

        @b Default: 320x240@(0,0)

        <b>Programming Notes</b> \n
        The Programming Notes specified for #GDL_PLANE_DST_RECT apply to this
        attribute also.
        \n\n
        */

    GDL_PLANE_Z_ORDER,
        /**<
        @b Capability: \n
        Planes have different "depth" levels, and enabled planes are blended in
        order from lowest to top-most.

        @b Attribute: \n
        The plane's Z-order.  <b>THIS VALUE IS READ-ONLY</b>.

        @b Value: \n
        int [0,NumberOfPlanes-1] or GDL_ZORDER_NONE where:
        -  N is the number of planes in the system
        -  0 is the bottom-most plane, and
        - GDL_ZORDER_NONE specifies the plane with no Z-Order (IAP in alpha
          modes)

        @b Default: \n
        For CE3100, CE4100 and CE4200-A the values returned for each plane are:

        Blending Model 0:
        - IAP_B: 5
        - IAP_A: 4
        - UPP_D: 3
        - UPP_C: 2
        - UPP_B: 1
        - UPP_A: 0
        .
        \n
        Blending Model 1:
        - IAP_B: 5
        - UPP_E: 4
        - UPP_D: 3
        - UPP_C: 2
        - UPP_B: 1
        - UPP_A: 0
        - IAP_A: GDL_ZORDER_NONE (alpha-only mode)
        .
        \n
        For CE4200-B the values returned for each plane are:

        Blending Model 0:
        - IAP_B: 6
        - IAP_A: 5
        - UPP_D: 4
        - UPP_C: 3
        - IAP_x: 2
        - UPP_B: 1
        - UPP_A: 0
        .
        \n
        Blending Model 1:
        - IAP_B: 6
        - UPP_E: 5
        - UPP_D: 4
        - UPP_C: 3
        - IAP_x: 2
        - UPP_B: 1
        - UPP_A: 0
        - IAP_A: GDL_ZORDER_NONE (alpha-only mode)
        .
        \n
        Blending Model 2:
        - IAP_B:  6
        - UPP_D:  5
        - UPP_C:  4
        - IAP_A:  3
        - IAP_x:  2
        - UPP_B:  1
        - UPP_A:  0
        .
        \n
        Blending Model 3:
        - IAP_B:  7
        - UPP_E:  6
        - UPP_D:  5
        - UPP_C:  4
        - IAP_A:  3
        - IAP_x:  2
        - UPP_B:  1
        - UPP_A:  0
        .
        \n
        */
    GDL_PLANE_422_TO_444_COEFF,
        /**<
        @b Capability: \n
        The coefficients used for chroma upsampling from YUV 422 to YUV 444
        may be specified.

        @b Attribute: \n
        If the pixel format of data coming into the plane is YUV 420 or YUV 422,
        the data must be converted to YUV 444. This filter performs the
        upsampling necessary on the chroma components to make this conversion.
        If the incoming data has an RGB pixel format, this attribute has no
        effect.

        This is a four tap horizontal filter. A single coefficient C0 may be
        specified.  The other three coefficients will be calculated from this
        single value based on the following filter equation:

@verbatim
Interpolated value = C0*P_left2 + C1*P_left1 + C1*P_right1 + C0*P_right2

where C1 = 0.5 - C0
      P_* are the pixel chroma values
@endverbatim

        @b Value: floating point number representing C0 in the range (-0.5, 1.0)
        exclusive of the endpoints

        @b Default: -0.25

        <b>Programming Notes</b>
          - This attribute is not available on the CE3100
          \n\n
        */

    GDL_PLANE_ATTRIBUTE_COUNT
        /**<
        The total number of defined plane attributes (not an actual attribute
        ID).
        */
} gdl_plane_attr_t;


/** @ingroup plane_management
    The total number of characters that may be present in a plane's
    name string, including the zero terminator.
*/
#define GDL_PLANE_NAME_LENGTH   32

/** @ingroup plane_management

    Structure that describes the hardware of a display plane.
    This information is retrieved by a call to gdl_plane_capabilities().
*/
typedef struct
{
    gdl_plane_id_t  id;
        /**< The ID of the plane described by this structure. */

    char            name[ GDL_PLANE_NAME_LENGTH ];
        /**<
        The name of the plane as a 0-terminated string, for use in messages
        and debugging.
        */

    gdl_uint8       attr[ GDL_PLANE_ATTRIBUTE_COUNT ];
        /**<
        The programmable attributes of the plane.

        The values of the #gdl_plane_attr_t enumeration are used to index this
        array: if the corresponding entry in the array is non-zero, the
        attribute is supported by the plane.

        See the descriptions of the members of #gdl_plane_attr_t for further
        information about individual attributes.
        */

    gdl_uint8       pixel_formats[ GDL_PF_COUNT ];
        /**<
        The pixel formats supported by the plane.

        The values of the #gdl_pixel_format_t enumeration are used to index this
        array: if the corresponding entry in the array is non-zero, that pixel
        format is supported by the plane.
        */

    gdl_rectangle_t max_dst_rect;
        /**<
        The width/height fields of this rectangle specify the maximum dimensions
        allowed by the hardware for the plane's destination rectangle
        (on-display window).
        */

    gdl_rectangle_t min_dst_rect;
        /**<
        The width/height fields of this rectangle specify the minimum dimensions
        allowed by the hardware for the plane's destination rectangle
        (on-display window).
        */

} gdl_plane_info_t;


/*----------------------------------------------------------------------
 *              S U R F A C E   M A N A G E M E N T
 *---------------------------------------------------------------------*/

/** @ingroup surf

    A structure describing an individual palette element.

*/
typedef struct
{
    gdl_uint8 a;               ///< Alpha component
    gdl_uint8 r_y;             ///< Red (or Y) component
    gdl_uint8 g_u;             ///< Green (or U/Cb) component
    gdl_uint8 b_v;             ///< Blue (or V/Cr) component
} gdl_palette_entry_t;


/** @ingroup surf
    A structure describing an 8-bit indexed palette (CLUT).
*/
typedef struct
{
    gdl_palette_entry_t data[256]; ///< Palette elements
    gdl_uint32          length;    ///< Number of valid entries in palette
} gdl_palette_t;


/** @ingroup surf

    Surfaces are referenced by IDs.  The IDs are unsigned integers.
*/
typedef unsigned int gdl_surface_id_t;

/** @ingroup surf
This value is never allocated for a valid surface.  It can be used
in data structures to indicate an invalid or uninitialized surface ID.
*/
#define GDL_SURFACE_INVALID 0
// Note: If gdl_surface_id_t is defined as an open-ended enum with
// GDL_SURFACE_INVALID entry, then C++ compiler with certain optimizations
// will cause all non-0 surface ids to be set to 1.

/**@ingroup surf

    These flags are used with gdl_alloc_surface() to indicate how the surface
    is intended to be used.
*/
typedef enum
{
    GDL_SURFACE_CACHED      = 0x00000002,
        /**<
        This flag should be set on a surface that the caller would like to
        be in 'cached' memory. If the surface is passed to any other execution
        unit besides cpu, cached surface must be flushed first using
        #gdl_flush_surface API call. Automatic flush of the cache will occur
        internally during #gdl_flip call.
        */
    GDL_SURFACE_DISABLE_AUTOCLEANUP = 0x00000004,
        /**
        This flag when set disables surface from participating in automatic
        cleanup. Upon exit of applcation remaining surfaces marked with this
        flag will not be automatically deleted.
        @bNote: This flag should only be set by applications that perform their
        own memory management.
        */
} gdl_surface_flag_t;


/** @ingroup surf
    This structure describes a surface.
*/
typedef struct
{
    gdl_surface_id_t    id;
        /**< Surface ID, used in GDL calls that operate on this surface */

    gdl_uint32          flags;
        /**< Any combination of OR'd values of type #gdl_surface_flag_t. */

    gdl_pixel_format_t  pixel_format;
        /**< Pixel format of the surface of type #gdl_pixel_format_t. */

    gdl_uint32          width;
        /**<
        Surface width in pixels.  In the case of a YUV format surface, this is
        also the number of active pixels in a line of the Y-plane.
        */

    gdl_uint32          height;
        /**<
        Surface height in pixels.  In the case of a YUV format surface, this is
        also the number of lines in the Y-plane.
        */

    gdl_uint32          size;
        /**<
        Total number of bytes allocated for the surface, including any padding
        added for stride alignment.
        */

    gdl_uint32          pitch;
        /**<
        Byte stride; i.e., the byte offset that must be added to the address
        of pixel in order to access the pixel with the same x-offset in the
        line below it. In the case of a YUV format surface, this is the pitch
        of the Y plane.
        */

    gdl_uint32         phys_addr;
        /**<
        Physical address of the surface.
        */

    gdl_uint32         heap_phys_addr;
        /**<
        Physical address of the heaps base.
        */

    gdl_uint32          y_size;
        /**<
         NOT USED FOR PACKED PIXEL FORMATS.
         For YUV planar and pseudo-planar formats, this is the total number of
         bytes allocated for the Y plane, including any padding for stride
         alignment.  Note that the Y plane always begins at offset 0 into the
         surface.
         */

    gdl_uint32          u_offset;
        /**<
        NOT USED FOR PACKED PIXEL FORMATS.
        For YUV planar formats, this is the (non-zero) offset from the
        start of the surface to the start of the U plane. For YUV
        pseudo-planar surfaces, this is the (non-zero) offset of the
        interleaved UV samples.
        */

    gdl_uint32          v_offset;
        /**<
        NOT USED FOR PACKED PIXEL FORMATS.
        For YUV planar formats, this is the (non-zero) offset from the start of
        the surface to the start of the V plane.  For YUV pseudo-planar
        surfaces, this value is meaningless and will be set to 0.
        */

    gdl_uint32          uv_size;
        /**<
        NOT USED FOR PACKED PIXEL FORMATS.
        The total number of bytes allocated for each of the subsampled
        chrominance planes, including any padding for stride alignment.  For
        YUV planar formats, both the U & V planes are this size. For YUV
        pseudo-planar formats, this is the total allocated for the interleaved
        UV samples.
        */

    gdl_uint32          uv_pitch;
        /**<
        NOT USED FOR PACKED PIXEL FORMATS.
        The byte stride of the subsampled chrominance planes. For YUV planar
        formats, both the U and V planes have this pitch. For pseudo-planar
        formats, this is the pitch of the interleaved UV samples
        */

} gdl_surface_info_t;


/** @ingroup general
    This enumeration represents events that can be used for callback
    registration with the gdl_event_register() API.

    The events GDL_APP_EVENT_RECT_CHANGE_UPP_* will be fired if the display
    driver automatically changes the GDL_PLANE_DST_RECT attribute of a UPP
    to match the dimensions of a video frame flipped by SMD. See also
    #GDL_PLANE_VID_MISMATCH_POLICY.
*/
typedef enum
{
    GDL_APP_EVENT_HDCP_FAILURE=0,       ///< HDCP has failed
    GDL_APP_EVENT_HDCP_SUCCESS,         ///< HDCP authentication has succeeded
    GDL_APP_EVENT_HOTPLUG_DETECT,       ///< HDMI cable was connected
    GDL_APP_EVENT_HOTPLUG_LOSS,         ///< HDMI cable was disconnected
    GDL_APP_EVENT_RECT_CHANGE_UPP_A,    ///< UPP_A DST_RECT changed by SMD.
    GDL_APP_EVENT_RECT_CHANGE_UPP_B,    ///< UPP_B DST_RECT changed by SMD.
    GDL_APP_EVENT_RECT_CHANGE_UPP_C,    ///< UPP_C DST_RECT changed by SMD.
    GDL_APP_EVENT_RECT_CHANGE_UPP_D,    ///< UPP_D DST_RECT changed by SMD.
    GDL_APP_EVENT_RECT_CHANGE_UPP_E,    ///< UPP_E DST_RECT changed by SMD.
    GDL_APP_EVENT_HDCP_RI,              ///< HDCP Ri values have been received
    GDL_APP_EVENT_HDCP_PJ,              ///< HDCP Pj values have been received
    GDL_APP_EVENT_MODE_DISP_0,          ///< Display mode was changed on display 0
    GDL_APP_EVENT_MODE_DISP_1,          ///< Display mode was changed on display 1
    GDL_APP_EVENT_HDCP_DISABLE_DONE,    ///< HDCP has been disabled
    GDL_APP_EVENT_HDCP_KSV_INVALID,     ///< HDCP invalid KSV
    GDL_APP_EVENT_HDCP_KSV_REVOKED,     ///< HDCP revoked KSV
    GDL_APP_EVENT_HDCP_LINK_NO_ACK,     ///< HDCP no-ack when reading R'
    GDL_APP_EVENT_HDCP_LINK_INTEGRITY,  ///< HDCP R!=R'
    GDL_APP_EVENT_HDCP_PHASE_1_DONE,    ///< HDCP phase 1 authentication successful
    GDL_APP_EVENT_CVBS_TELETEXT_ODD,    ///< Teletext CVBS Odd field's data consumed
    GDL_APP_EVENT_CVBS_TELETEXT_EVEN,   ///< Teletext CVBS Even field's data consumed
    GDL_APP_EVENT_COMP_TELETEXT_ODD,    ///< Teletext Component Odd field's data consumed
    GDL_APP_EVENT_COMP_TELETEXT_EVEN,   ///< Teletext Component Even field's data consumed
    GDL_APP_EVENT_PHY_STATUS_CHANGE,    ///< HDMI PHY was enabled / disabled
    GDL_APP_EVENT_RXSENSE_DETECT,       ///< RX sense was detected
    GDL_APP_EVENT_RXSENSE_LOSS,         ///< Rx sense was lost
    GDL_APP_EVENT_COUNT,
} gdl_app_event_t;


/** @ingroup general
    Type for a callback function used with #gdl_event_register API
    call. See #gdl_event_register for more information
*/
typedef void (*gdl_event_callback_t)(gdl_app_event_t event, void * user_data);


/** @ingroup debug
    These flags are used with gdl_debug_log_start() to indicate the type of
    information to be logged.
*/

typedef enum
{
    GDL_LOG_SURFACES = 1,  ///< Log surface-related information
    GDL_LOG_PLANES,        ///< Log plane-related information
    GDL_LOG_EVENTS,        ///< Log event-related information
    GDL_LOG_VIDEO,         ///< Log video-related information
    GDL_LOG_POST_BLENDER,  ///< Log post-blender related information
    GDL_LOG_PORT_DRIVERS,  ///< Log port driver messages
    GDL_LOG_TIMESTAMP,     ///< DEPRECATED
    GDL_LOG_THREAD_ID,     ///< DEPRECATED
    GDL_LOG_COUNT,
} gdl_log_flag_t;


/** @ingroup plane_management
    Structure used to specify the relative z-order of a group of UPPs.
    See gdl_set_upp_zorder() / gdl_get_upp_zorder() .
*/
typedef struct
{
    gdl_plane_id_t    order[GDL_MAX_UPPS];
        /**<
        A list of UPP identifiers, sorted from bottom-most (order[0]) to
        top-most (order[num_planes-1] plane in the group.
        */
    gdl_uint32        num_planes;
        /**<
        The number of UPPs specified in the order[] array.  Only the first
        'num_planes' entries are valid.
        */
} gdl_upp_zorder_t;

/** @ingroup plane_management
    Values used for a color space conversion.

    A color has three components.
    - in RGB space they are R, G, and B.
    - in a YUV space they are Y, Cb, and Cr.

    The three components of a color from an input color space (CrR, YG, and
    CbB) can be converted to the three components of an output color space
    (CrR', YG', and CbB') according to the following equations:

    @verbatim
    CrR' = (CrR+cr_ioff)*c0 + (YG+yg_ioff)*c1 + (CbB+cb_ioff)*c2 + cr_ooff
    YG'  = (CrR+cr_ioff)*c3 + (YG+yg_ioff)*c4 + (CbB+cb_ioff)*c5 + yg_ooff
    CbB' = (CrR+cr_ioff)*c6 + (YG+yg_ioff)*c7 + (CbB+cb_ioff)*c8 + cb_ooff
    @endverbatim

    This data structure contains the offsets and coefficients used to perform
    a color space conversion.
*/
typedef struct
{
    gdl_int32  yg_ioff; ///< The offset applied to the input Y or G component.
    gdl_int32  cb_ioff; ///< The offset applied to the input Cb or B component.
    gdl_int32  cr_ioff; ///< The offset applied to the input Cr or R component.
    gdl_int32  yg_ooff; ///< The offset applied to the output Y or G component.
    gdl_int32  cb_ooff; ///< The offset applied to the output Cb or B component.
    gdl_int32  cr_ooff; ///< The offset applied to the output Cr or R component.
    gdl_f32    c[9];    ///< The nine coefficients in the CSC equations.
} gdl_csc_t;

/** @ingroup general
    Representation of an integer range with a minimum and maximum
*/
typedef struct
{
    gdl_int32 min;  ///< Minimum value of the range
    gdl_int32 max;  ///< Maximum value of the range
} gdl_int_range_t;

/** @ingroup plane_management
    Values used for clamping in a color space

    This data structure contains clamping limits for the input or output
    stages of a color space conversion.  Any value which is below \e min
    is forced to \e min, and any value which is greater than \e max is forced
    to \e max.
*/
typedef struct
{
    gdl_int_range_t yg;  ///< The valid range for the Y or G component.
    gdl_int_range_t cb;  ///< The valid range for the Cb or B component.
    gdl_int_range_t cr;  ///< The valid range for the Cr or R component.
} gdl_csc_clamps_t;



/** @ingroup post_blend
    This enumeration defines the various attributes that may be supported by
    the hardware post blender unit.
    Post blender unit is only available on CE5300-A0 and later SOCs.

    Enumerations are used in two different ways:
    - to configure the post blender unit\n\n
    #gdl_post_blend_set_attr() function allows the setting of individual
    attributes of the post-blender by specifying attribute name-value
    pairs. The "names" in these pairs are members of this enumeration.

    - to examine the configuration of the post-blender\n\n
    #gdl_post_blend_get_attr() function allows the current value of an
    attribute to be queried by name. The "names" used in these queries
    are members of this enumeration.

    The descriptions of the individual enumeration values contain the
    following fields:
    - @b Attribute: what the attribute controls.\n
    - @b Value: the data type of the attribute. Where relevant, the range
         of legal values for the attribute is listed.
    - @b Default: the default setting of the attribute when the system is
         powered up.
*/
typedef enum
{
    GDL_POST_BLEND_CSC_ADJUST = 0x0,
    /**<
    @b Attribute: \n
    Post blender performs a color space conversion on each pixels coming
    out of the blender. CSC is performed on each of three components; three
    components of the color from an input color space (CrR, YG and CbB) are
    converted to the three components of an output color space (CrR', YG' and
    CbB') according to the following equations:
    @verbatim
CrR'= (CrR+off1)*c0 + (YG+off2)*c1 + (CbB+off3)*c2 + off4
YG' = (CrR+off1)*c3 + (YG+off2)*c4 + (CbB+off3)*c5 + off5
CbB'= (CrR+off1)*c6 + (YG+off2)*c7 + (CbB+off3)*c8 + off6
    @endverbatim

    This attribute allows to modify the current color space conversion on a
    post-blender by supplying a set of adjustments for the current offsets and
    coefficients.

    The adjustments are specified using a variable of type #gdl_csc_t. The
    offsets of this attribute value are @b added to the corresponding
    offsets in each CSC equation, and the equation coefficients are
    @b multiplied by the corresponding coefficients of the attribute
    value. By varying the adjustment, a (highly knowledgeable) user can
    adjust color attributes such as hue, brightness and saturation.

    Note that post-blender is always performing a CSC.
    When operating in normal (non-LVDS) mode, CSC unit is programmed with
    values that do not cause any modification of the pixels coming out of
    the blender.

    When operating in LVDS mode, CSC unit converts from the blending colorspace
    (specified inside of #gdl_display_info_t) to #GDL_COLOR_SPACE_RGB.


    @b Value: #gdl_csc_t

    @b Default: \n
    In the default adjustment structure, all offset adjustments are 0, and
    all coefficient adjustments are 1.0. These adjustment values leave the
    equation for the current CSC operation unchanged.
    \n\n
    */

    GDL_POST_BLEND_CSC_BASE,
    /**<
    @b Attribute: \n
    The default coefficients used for this color space conversion (which is
    determined by the blending color space and the required output color
    space). The values used in the final conversion may be adjusted through the
    #GDL_POST_BLEND_CSC_ADJUST attribute. Any adjustment is not shown by this
    attribute.

    @b Value: #gdl_csc_t

    @b Default: N/A. <b>THIS VALUE IS READ-ONLY</b>
    */

    GDL_POST_BLEND_CSC_INPUT_CLAMPS,
    /**<
    @b Attribute: \n
    When performing a color space conversion, it is sometimes necessary
    to clamp the input or output pixels to a valid range. This attribute
    will adjust the range.

    Post blender CSC input clamps have a range of [-256, 255].

    @note
    This attribute only takes effect when the
    #GDL_POST_BLEND_CSC_CLAMPS_OVERRIDE attribute is set to GDL_TRUE.

    @b Value: #gdl_csc_clamps_t

    @b Default: \n
    <tt><-256, 255></tt> for all color components
    \n\n
    */

    GDL_POST_BLEND_CSC_OUTPUT_CLAMPS,
    /**<
    @b Attribute: \n
    Same as the #GDL_POST_BLEND_CSC_INPUT_CLAMPS attribute, except that it
    specifies output clamps (after the CSC operation has been performed).

    Post blender CSC output clamps have a range of [0, 255].

    @b Default: \n
    <tt><0, 255></tt> for all color components
    \n\n
    */

    GDL_POST_BLEND_CSC_CLAMPS_OVERRIDE,
    /**<
    @b Attribute: \n
    When this attribute is set to GDL_TRUE, then the clamping values
    set in the #GDL_POST_BLEND_CSC_INPUT_CLAMPS and
    #GDL_POST_BLEND_CSC_OUTPUT_CLAMPS attributes are used.

    When this attribute is set to GDL_FALSE, the standard clamps for the
    color space conversion being performed are used. These defaults are not
    visible in any attributes.

    @b Value: #gdl_boolean_t

    @b Default: \n
    GDL_FALSE
    \n\n
    */

    GDL_POST_BLEND_GAMMA,
    /**<
    @b Attribute: \n
    The type of gamma to apply to the post-blender output.

    @b Value: #gdl_gamma_t

    @b Default: #GDL_GAMMA_LINEAR
    */

    GDL_POST_BLEND_DITHER,
    /**<
    @b Attribute: \n
    Controls how 12 to 10 "bit per color component" conversion is performed
    by the post blender unit. When enabled a dithering method is used.
    When disabled rounding is used.

    @b Value: #gdl_boolean_t

    @b Default: \n
    GDL_FALSE - (rounding is used)

    */

    GDL_POST_BLEND_TEST_PATTERN,
    /**<
    @b Attribute: \n
    Show a test pattern. No portion of the original blended output is visible.
    The display color space must be set to RGB while this attribute is set to
    a value other than #GDL_TEST_PATTERN_NONE.

    @b Value: #gdl_test_pattern_t

    @b Default: \n
    #GDL_TEST_PATTERN_NONE

    */

    GDL_POST_BLEND_ATTRIBUTE_COUNT,
    /**<
    The total number of defined post blender attributes.
    */
} gdl_post_blend_attr_t;

/** @ingroup post_blend

    This enumeration defines the available test patterns for the post-blender
    pattern generator. Patterns are influenced by
        - Display color space
        - Display gamma
        - Post-blender settings (gamma, CSC, etc)
*/
typedef enum
{
    GDL_TEST_PATTERN_NONE,       //< Do not show a test pattern
    GDL_TEST_PATTERN_COLOR_BARS, //< Show standard color bar pattern
    GDL_TEST_PATTERN_GRAY_BARS,  //< Show 16 gray bars going from black to white
    GDL_TEST_PATTERN_HORZ_RAMP,  //< Show a smooth ramp left to right, black to white
    GDL_TEST_PATTERN_VERT_RAMP,  //< Show a smooth ramp top to bottom, black to white
    GDL_TEST_PATTERN_COUNT       //< Number of patterns which are available
} gdl_test_pattern_t;

/** @ingroup plane_management
    Represent a region used in anamorphic scaling

    The scaling factors specified here are relative.  They will be adjusted
    so that the entire source rectangle is displayed, without clipping parts
    off.
 */
typedef struct
{
    gdl_f32 left_sf;
        ///< Scaling factor at the left edge of the region
    gdl_f32 right_sf;
        ///< Scaling factor at the right edge of the region
    gdl_f32 percent_width;
        ///< Width of this region, before scaling. This value is a percentage
        //   of the source rectangle width
} gdl_scale_region_t;

/** @ingroup plane_management
    Minimum number of anamorphic regions that may be specified
 */
#define GDL_MIN_ANAMORPHIC_REGIONS 2

/** @ingroup plane_management
    Maximum number of anamorphic regions that may be specified
 */
#define GDL_MAX_ANAMORPHIC_REGIONS 7

/** @ingroup plane_management
    Represent all regions used in anamorphic scaling
 */
typedef struct
{
    gdl_scale_region_t regions[GDL_MAX_ANAMORPHIC_REGIONS];
        ///< Settings for each anamorphic region
    gdl_uint32 num_regions;
        ///< Number of valid regions in this structure.
} gdl_anamorphic_regions_t;

#endif
