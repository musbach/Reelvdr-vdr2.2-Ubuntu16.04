//-----------------------------------------------------------------------------
// This file is provided under a dual BSD/GPLv2 license.  When using or
// redistributing this file, you may do so under either license.
//
// GPL LICENSE SUMMARY
//
// Copyright(c) 2006-2011 Intel Corporation. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
// The full GNU General Public License is included in this distribution
// in the file called LICENSE.GPL.
//
// Contact Information:
//      Intel Corporation
//      2200 Mission College Blvd.
//      Santa Clara, CA  97052
//
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

#ifndef __VBD_H_
#define __VBD_H_

#include "gdl_types.h"
#include "ismd_core.h"

/**
  * Signature of callback function registered via vbd_set_callback().
  *
  * @param[in] user_data
  * The cookie passed when the callback was registered.
  *
  * @param[in] polarity
  * Indicates the type of image that was just flipped on-screen (full-frame,
  * top-field, or bottom-field; and left or right view, for stereoscopic display
  * modes).  This image is currently in the process of being scanned out.
  *
  * @b NOTE: This signature is deprecated. use #vbd_disp_callback_t instead
  */
typedef void (*vbd_callback_t)( void *          user_data,
                                gdl_polarity_t  polarity
                                );

/**
  * Signature of callback function registered via vbd_set_disp_callback().
  *
  * @param[in] display_id
  * Display ID for which callback was executed.
  *
  * @param[in] user_data
  * The cookie passed when the callback was registered.
  *
  * @param[in] polarity
  * Indicates the type of image that was just flipped on-screen (full-frame,
  * top-field, or bottom-field; and left or right view, for stereoscopic display
  * modes).  This image is currently in the process of being scanned out.
  */
typedef void (*vbd_disp_callback_t) ( gdl_display_id_t display_id,
                                      void           * user_data,
                                      gdl_polarity_t   polarity);
/**
  * Registers a callback that will invoked as soon as possible after
  * the Vsync interrupt on Pipe A.
  *
  * The callback is responsible for scheduling the next frame/field flip for
  * each video plane via calls to vbd_flip().  The callback will be invoked
  * from an interrupt handler, and so MUST RETURN AS QUICKLY AS POSSIBLE.
  *
  * Only one callback may be registered at a time. The function unregisters any
  * existent callback before registering the one it is passed.  If a NULL
  * callback pointer is passed, the current callback (if any) is unregistered
  * without registering any new callback.
  *
  * @param[in] callback
  * The callback to be invoked. If NULL, unregisters the callback.
  *
  * @param[in] user_data
  * A pointer that will be handed back to the callback function when it is
  * invoked.
  *
  * @b NOTE: This function is deprecated. Use #vbd_set_disp_callback instead
  */
gdl_ret_t vbd_set_callback(vbd_callback_t callback, void *user_data);



/**
  * Registers a callback that will invoked as soon as possible after
  * the Vsync interrupt on the specified 'display_id'
  *
  * The callback is responsible for scheduling the next frame/field flip for
  * each video plane via calls to vbd_flip().  The callback will be invoked
  * from an interrupt handler, and so MUST RETURN AS QUICKLY AS POSSIBLE.
  *
  * Only one callback per display may be registered at a time. The function
  * unregisters any existent callback on the specified display before
  * registering the one it is passed.  If a NULL callback pointer is passed,
  * the current callback for the display (if any) is unregistered without
  * registering any new callback.
  *
  * @param[in] display_id
  * Display ID for which to register the callback
  *
  * @param[in] callback
  * The callback to be invoked. If NULL, unregisters the callback.
  *
  * @param[in] user_data
  * A pointer that will be handed back to the callback function when it is
  * invoked.
  */
gdl_ret_t vbd_set_disp_callback(gdl_display_id_t    display_id,
                                vbd_disp_callback_t callback,
                                void              * user_data);

/**
 * One field worth of close caption information.  BOTH BYTES CLOSE CAPTION
 * INFORMATION MUST BE VALID.
 */
typedef struct
{
    gdl_polarity_t  field;  /**< The field (top or bottom) with which this
                              *  data is associated.
                              */
    gdl_uint8       cc1;    /**< 1st byte of close caption info */
    gdl_uint8       cc2;    /**< 2nd byte of close caption info */
} vbd_close_caption_t;


/**
 * Data structure passed to vbd_flip().
 *
 * As much as possible of this structure should be set up in advance, to
 * minimize the amount of processing done by the callback.
 *
 * Note the following assumptions about field and frame buffers:
 * - buffer pointers: when field pointers are passed, the pixel data for each
 *   field is assumed to be part of an interleaved frame in memory.  It is
 *   possible that the fields are from two different such buffers.
 * - strides: Strides are assumed to be the width of a single line in a buffer,
 *   including padding for alignment.
 *
 * The following diagram representing a frame buffer summarizes these
 * assumptions.  E represents pixel data for an even (top) field, O represents
 * pixel data for an odd (bottom) field, '*' represents padding to produce
 * a 64B-aligned line width.
 *
 * @code
 *        <------- stride --------->
 *      0 EEEEEEEEEEEEEEEEEEEEEE****
 *      1 OOOOOOOOOOOOOOOOOOOOOO****
 *      2 EEEEEEEEEEEEEEEEEEEEEE****
 *      3 OOOOOOOOOOOOOOOOOOOOOO****
 *      4 EEEEEEEEEEEEEEEEEEEEEE****
 *      5 OOOOOOOOOOOOOOOOOOOOOO****
 *      .
 *      .
 *      .
 * @endcode
 */

typedef struct
{
    physaddr_t              top_y_ptr;
            /**<
             * The physical address of a luminance (Y) pixel buffer:
             * - for interlaced output, this is the buffer for the top field
             *   (even lines of a 0-based frame).
             * - for progressive output  this is the buffer for the full frame.
             *
             * Must be 128-byte aligned.
             */
    physaddr_t              top_uv_ptr;
            /**<
             * Same as top_y_ptr, for buffer of 4:2:2 subsampled chrominance
             * (U/V) pixel values.
             */
    physaddr_t              bottom_y_ptr;
            /**<
             * Same as top_y_ptr, except:
             * - for interlaced output, this is the buffer for the bottom
             *   field (odd lines from a 0-based frame).
             * - for progressive output, THIS VALUE IS IGNORED.
             */
    physaddr_t              bottom_uv_ptr;
            /**<
             * Same as bottom_y_ptr, for buffer of 4:2:2 subsampled chrominance
             * (U/V) plane.
             */
    gdl_uint32              y_stride;
            /**<
             * The value to add to the address of a row in one of the Y-buffers
             * to access the start of the next row in the frame/field. Must be a
             * multiple of 128.
             */
    gdl_uint32              uv_stride;
            /**<
             * The value to add to the address of a row in one of the UV-buffers
             * to access the start of the next row in the frame/field. Must be a
             * multiple of 128.
             */
    gdl_rectangle_t         image_rect;
            /**<
             * The buffer pointers described above refer to the (0,0) origin of
             * a frame to be flipped on-screen. The image_rect rectangle
             * defines the subrectangle of that frame that is to be displayed.
             *
             * The origin of this rectangle represents a pan/scan point in
             * the frame, as 0-based logical pixel coordinates. The pixel at
             * these coordinates will be at the origin of the displayed image.
             *
             * The width of the rectangle is specified in pixels, and the height
             * in lines.
             *
             * @b NOTE:
             * - The caller must insure that this rectangle lies completely
             *   within the passed frame/field buffer(s).
             * - In interlaced modes, the origin @b must be on an even line
             *   of the frame (i.e., the y-coordinate must be an even number).
             *   The driver will ignore the low bit of the coordinate in that
             *   case.
             */
    gdl_point_t             video_position;
            /**<
             * @b IGNORED unless the current value of the target plane's
             * GDL_PLANE_VID_MISMATCH_POLICY attribute is GDL_VID_POLICY_RESIZE.
             *
             * This point represents a position on the output display, as
             * 0-based pixel coordinates relative to the upper left of the
             * display. The origin (upper-left corner) of the target plane's
             * GDL_PLANE_DST_RECT attribute is updated, if necessary, with this
             * value.
             *
             * @b NOTE:
             * Plane reconfiguration will fail if the position specified by
             * this point is such that the lower right corner of the plane
             * would be off the display.
             */
    gdl_uint32          display_height, display_width;
            /**<
             * @b IGNORED if the plane's GDL_PLANE_VID_MISMATCH_POLICY
             * attribute is GDL_VID_POLICY_BLACK_FRAME.
             *
             * Otherwise, their values are used to reconfigure the dimensions
             * of the target plane's GDL_PLANE_DST_RECT attribute, if necessary.
             * The selected content is scaled if necessary to fit the specified
             * dimensions, subject to the current MISMATCH POLICY.
             *
             * @b NOTE:
             * Plane reconfiguration will fail if:
             * - the reconfigured plane would not fit completely on-screen.
             * - scaling is required but no scaler is assigned to the plane.
             * - an unsupported scaling ratio is required.
             */
    vbd_close_caption_t     close_caption[4];
            /**<
             * Closed caption information to be processed with the frame/field
             * being flipped (see vbd_flip() description).
             */
    gdl_uint32              close_caption_cnt;
            /**<
             * The number of valid entries in the close_caption[] array.
             * Must be in [0,4].  Must be 0 if no close_caption data is to be
             * proceess.
             */
    gdl_pixel_format_t      pixel_format;
            /**<
             * Pixel format.  Corresponds to the GDL_PLANE_PIXEL_FORMAT plane
             * attribute. Must be one of: GDL_PF_NV16, GDL_PF_NV20
             * (see the description of gdl_plane_attr_t in gdl_types.h).
             */
    gdl_color_space_t       color_space;
            /**<
             * Color space of source pixels.
             * Corresponds to the GDL_PLANE_SRC_COLOR_SPACE plane attribute
             * (see the description of gdl_plane_attr_t in gdl_types.h).
             */
    gdl_gamma_t             gamma_type;
            /**<
             * Reverse gamma: type of gamma correction to be removed from the
             * content prior to blending with other planes. Corresponds to the
             * GDL_PLANE_REVERSE_GAMMA_TYPE plane attribute (see the
             * description of gdl_plane_attr_t in gdl_types.h).
             *
             * THIS ARGUMENT IS CURRENTLY IGNORED.
             */
    gdl_polarity_t          flip_type;
            /**<
             * The type of flip that is being performed:
             * - for progressive content, this will be L/R frame
             * - for interlaced content, this will be  top field, R top field,
             *   bottom field or R bottom field.
             */
} vbd_flip_data_t;

/**
 * This function displays the specified frame of video data on the specified
 * Universal Pixel Plane.  It is assumed this function is called at interrupt
 * time (from the callback registered via vbd_set_callback()).
 *
 * If the default plane attributes (see the GDL API documentation) are not
 * appropriate for the video content, they must be modified by a GDL application
 * before this routine is called.  These attributes include the plane origin
 * and plane dimensions.  The following plane attributes, which can be set via
 * the GDL API, can be overridden by data passed to the vbd_flip() routine:
 *      - pixel_format
 *      - source color space
 *      - reverse gamma correction
 *
 * This function also processes close caption data if
 * - data->close_caption_cnt is non-zero, AND
 * - the plane_id argument corresponds to the plane currently selected as the
 *   closed caption source (via gdl_closed_caption_source()).
 * .
 *
 * The number of entries specified by data->close_caption_cnt will be sent
 * from data->close_caption[] to all internal TV encoders currently enabled in
 * a display mode that supports closed captions.  The caller MUST see that all
 * closed caption bytes received on a video stream are sent once and only once,
 * in the order in which they are received, to this routine: closed caption
 * data is stateful, and any breaks in the stream require a call to
 * vbd_closed_caption_reset().
 *
 * If the frame dimensions specified by data->width and data->height don't
 * correspond to the current configuration of the specified plane, the passed
 * field(s)/frame will be discarded and the plane will be filled with opaque
 * black pixels. (This could happen, for example, if a plane was reconfigured
 * while frames for the previous configuration were still in the SMD pipeline.)
 *
 * NOTE: Prior to using this function vbd_plane_reserve() should be called to
 * mark plane as being reserved for video.
 *
 * @param[in] plane_id
 * The plane onto which the video field(s)/frame should be flipped.
 *
 * @param[in] data
 * Pointer to the data needed to process the flip.  If NULL, the plane will be
 * disabled.  Otherwise, if necessary, the plane will be enabled.  See the
 * description of #vbd_flip_data_t for more details.
 */
gdl_ret_t vbd_flip( gdl_plane_id_t plane_id, vbd_flip_data_t *data );


/**
 * Displays all opaque black pixels on the specified Universal Pixel Plane,
 * without requiring the passing of pixel buffer(s). The plane will be enabled
 * if necessary.  The current settings of the plane (origin, dimensions,
 * pixel_format, etc.) will be used.
 *
 * It may be appropriate to call this function when a channel change occurs,
 * and to inhibit further flips until video data from the new channel is
 * available.
 *
 * @param[in] plane_id
 * The plane onto which the opaque black frame/field should be flipped.
 */
gdl_ret_t vbd_flip_black_frame( gdl_plane_id_t plane_id );


/**
 * Flushes the closed caption buffer and resets the parsing of closed caption
 * information by any internal TV encoders are that are currently enabled.
 *
 * This function should be called whenever the stream of closed caption data
 * is either changed or else interrupted in such a way that bytes are lost.
 *
 * For example, the function should be called if:
 *  - There is a channel change.
 *  - A trick mode (such as rewind or fast forward) that drops closed caption
 *      information is entered.  Additional CC information should not be sent
 *      with vbd_flip() calls until the mode is exited.
 *  - A "hold frame" mode is entered and then exited.
 *
 * It should not be necessary to call if no CC info is lost -- e.g., if a
 * "pause" mode that holds off decoding of the input stream (without dropping
 * data) is entered and then exited.
 *
 * @param[in] plane_id
 * The plane on which close caption information is to be reset.  If the current
 * closed caption source is not the video stream associated with the specified
 * plane, the function call is a no-op.
 */
gdl_ret_t vbd_closed_caption_reset( gdl_plane_id_t plane_id );

/**
 * Notifies display driver that the specified Universal Pixel Plane is
 * reserved for video output.
 *
 * This function should be called prior to #vbd_flip being called for
 * that plane.
 *
 * @param[in] plane_id
 * The plane which is to be marked reserved for video output.
 */
gdl_ret_t vbd_plane_reserve ( gdl_plane_id_t plane_id );

/**
 * Notifies display driver that the specified Universal Pixel Plane
 * is no longer reserved for video output.
 *
 * @param[in] plane_id
 * The plane which is to be no longer reserved for video output.
 */
gdl_ret_t vbd_plane_unreserve ( gdl_plane_id_t plane_id );

/**
 * Supports shifting of the VSync signal on display 0 (pipe A) in DTV display
 * modes by adjusting the number of lines in the vertical blanking interval.
 * If a DTV display mode is not in effect, THIS FUNCTION IS A NO-OP.  The HDMI
 * port driver must have been loaded with the command line argument dtv=1 in
 * order to get DTV display modes.
 *
 * Each display mode has its own nominal number of lines (N) in the VBlank
 * interval.  The effect of calling this function is to change the number of
 * lines in that interval to (N + n_lines).  The change stays in effect for
 * all future frames until the next call to vbd_adjust_vblank_lines() or
 * until the display mode is changed.
 *
 * If a renderer changes the interval by calling this routine, it *must*
 * restore the nominal vblank interval (call vbd_adjust_vblank_lines(0))
 * before shutting down.
 *
 * The display driver may be limited in the number of lines by which it can
 * change the VBlank interval in a single frame (currently it is +/- 1), so
 * it may take several frame intervals for the requested adjustment to be
 * completed.
 *
 * @param[in] n_lines
 * A signed value indicating the number of lines to be added to (+) or removed
 * from (-) the nominal VBlank interval for the current display mode.  A value
 * of 0 returns the interval to the nominal length for the current display mode.
 * It is an error to pass a value less than -5.
 */
gdl_ret_t vbd_adjust_vblank_lines( int n_lines );


/**
 * Returns to the caller Display ID to which the specified plane is attached.
 * @b NOTE: This function cannot be called while in an atomic context.
 *
 * @param[in] plane_id
 * Plane ID being queried.
 *
 * @param [out] display_id
 * Display ID onto which the plane is attached.
 */
gdl_ret_t vbd_get_planes_display_id(gdl_plane_id_t     plane_id,
                                    gdl_display_id_t * display_id);


/**
 * Allows to send extension buffer containing reconfiguration data for
 * planes/post-blenders CSC and Gamma units.
 *
 * Extension buffer consists of a base physical address and offsets for
 * each field type (such as CSC/gamma).
 *
 * Field offsets of 0, indicate that the data for a particular field is not
 * provided.
 *
 * Fields in the extension buffer that require post-blender reconfiguration
 * will affect the display to which the specified plane_id is assigned to.
 *
 * Fields containing 'floating point' data, must be presented in
 * s7.24 (sign-magnitude) fixed point format.
 *
 * @b NOTE: This call is synchronous. Upon return from this call,
 * the caller can destroy/re-use provided extension buffer.
 *
 * @param[in] plane_id
 * Plane to configure
 *
 * @param [in] ext_handle
 * SMD extension buffer handle containing reconfiguration data
 */
gdl_ret_t vbd_send_smd_ext_buffer(gdl_plane_id_t       plane_id,
                                  ismd_buffer_handle_t ext_handle);

#endif  /* #ifndef __VBD_H_ */
