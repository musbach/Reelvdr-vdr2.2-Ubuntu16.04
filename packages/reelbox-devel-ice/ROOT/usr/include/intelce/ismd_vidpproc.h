/*

This file is provided under a dual BSD/GPLv2 license. When using or
redistributing this file, you may do so under either license.

GPL LICENSE SUMMARY

Copyright(c) 2006-2011 Intel Corporation. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
The full GNU General Public License is included in this distribution
in the file called LICENSE.GPL.

Contact Information:

Intel Corporation
2200 Mission College Blvd.
Santa Clara, CA 97052

BSD LICENSE

Copyright(c) 2006-2011 Intel Corporation. All rights reserved.
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

#ifndef __ISMD_VIDPPROC_H__
#define __ISMD_VIDPPROC_H__

#include "ismd_global_defs.h"
#include "ismd_msg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @weakgroup ismd_vidpproc Video Post-Processing APIs/Structures
<H1>Video Post Processing (vidpproc) Module</H1>

The video post processing module (also known as the Video Post Processor,
Display Processing Engine, Vidpproc, or DPE) takes uncompressed frame buffers
containing either a single progressive frame or a pair of interlaced fields
as input and outputs uncompressed frame buffers containing either a single
progressive frame or a pair of interlaced fields. It provides cropping,
scaling, filtering, deinterlacing, deringing, and noise reduction
capabilities.

<H2>I. Normal Playback</H2>

 -# Open the vidpproc device.
 -# Set up options
  - If scaling is desired, set the scaling mode.
  - If deinterlacing is desired, set the deinterlacing mode.
  - If cropping is desired, set cropping rectangles
  - If deringing noise reduction is not desired, disable the de-ringing filter
  - If Gaussian noise reduction is not desired, disable the Gaussian filter
  - Set the output parameters (width, height, pixel aspect ratio)
 -# Get the input and output ports.
 -# Set state to play
 -# Write to the input port

Steps 2 through 5 can be done in any order (with the exception that the state
must be set to "play" before writing frames), however a race condition can
occur if multiple configuration changes are requested resulting in some frames
being processed with only some of the settings. To prevent this ensure that no
frames are being processed when making changes, one way to do this is to set
the state to "stop".

On close, all resources are deallocated and everything is reset to the initial state.

<H2>II. Trick Modes</H2>

There are no external API calls necessary for trick mode.

<H2>III. Power Management</H2>

The Video Post Processor supports power management. The Power management unit
can request the Video Post Processor to suspend to a low power mode when all
device contexts are either closed or in a stopped state. When closing a
stopped Video Post Processor instance the device is automatically flushed to
prevent processing of corrupt data.

<H2>IV. Deinterlacing</H2>

When deinterlacing interlaced input the Video Post Processor outputs two
progressive frame buffers for every buffer containing two interlaced fields
that it reads in. If the "repeat_field" flag is set on an input buffer three
progressive frames are output.

In the case of deinterlacing the Video Post Processor must interpolate time
stamps for the frames created. Given one input frame I the first frame
generated from that input O1 will have a timestamp of T-R/2 where T is the
timestamp of I and R is the content rate or P the second output O2 will have
a timestamp of T and the third (if generated) will have a timestamp of T+R/2.

<table>
<tr><th>Frame</th><th>Port</th><th>Timestamp</th></tr>
<tr><td>I</td><td>In</td><td>T</td></tr>
<tr><td>O1</td><td>Out</td><td>T-R/2</td></tr>
<tr><td> O2</td><td> Out </td><td>T</td></tr>
<tr><td> O3</td><td> Out </td><td>T+R/2</td></tr>
</table>

<H2>V. Destination Parameters</H2>

The destination parameters define the geometry of the frame output by the
Video Post Processor these are:

- Width: the width of the frame
- Height: the height of the frame
- Pixel Aspect Ratio Numerator : the relative width of each pixel to its height
- Pixel Aspect Ratio Denominator: the relative height of each pixel to its width
- Origin: the location on the display plane where the frame should be rendered by the display driver (from the top left of the screen)


When output is connected to the display driver the combined effect of the
Width, Height, and origin must never result in pixels being rendered off of
the display plane (origin must be positive and x+width and y+height must be
smaller than display width and height respectively.

In most cases the Pixel aspect ratio should be the same as the display pixel
aspect ratio. It is important to note that this is not the display aspect
ratio, common values for the pixel aspect ratio are 1:1 or 11:10 while common
values for display aspect ratios are 16:9 or 4:3. Unlike the display aspect
the pixel aspect ratio normally does not change with cropping or zooming
operations.

In some cases such as some 3D output formats changing the pixel aspect ratio
is required to distort the output to achieve desirable effects.

Each input frame buffer has its own width, height and pixel aspect ratio
embedded on it by the device that created it (normally the Video Decoder
or AVCapture)

<H2>VI. Cropping and Scaling</H2>

Vidpproc accomplishes scaling by scaling the cropped input frame to the size
of the destination rectangle. The destination rectangle is set using the
\ref ismd_vidpproc_set_dest_params api. The input can be cropped using several
tools, two cropping rectangles are embedded on each input frame, the source
window cropping rectangle is always applied to the input. In addition vidpproc
can optionally apply the embedded pan-scan cropping rectangle.

In addition to input cropping an output cropping rectangle is available to
permit cropping of destination rectangle before the data is placed on the
output frame. It should be noted that output cropping is accomplished by
mapping the output crop rectangle back to a corresponding input rectangle,
this results in a clean low bandwidth scaling operation, however it does place
some constraints on use cases, for instance the input crop rectangle must remain
larger than the minimum input size, and anamorphic (non-linear) scaling is not
available for most cropping rectangles.

<H2>VII. Default States for Vidpproc</H2>

- Deringing Noise Filter: Enabled (using HW defaults)
- Gaussian Noise Filter: Enabled (using HW defaults)
- Scaling Policy: Scale-to-fit
- Deinterlacing Policy: Auto
- Cropping: Disabled
- Input Format: 4:2:0, 8-bit pseudo-planar(NV12)
- Output Format: 4:2:2, 8-bit pseudo-planar (NV16)
.

<H2>VIII. Important Numbers</H2>
- Widths may range from 48 pixels to 1920 pixels
- Heights may range from 48 pixels to 1088 pixels
- Horizontal Scaling Ratios may range from 19x to 1/19x (this values varies with
HW and FW revisions please check HW and FW documentation for specific values)
- Vertical Scaling Ratios may range from 32x to 1/32x
*/

/** @ingroup ismd_vidpproc */
/** @{ */

/**
@brief The maximum number of vidpproc device contexts supported.

The number of vidpproc device contexts supported by the system will not exceed this value.
This does not reflect the maximum number of device contexts that can be allocated on a
given system, it only reflects an upper bound for the maximum number.

The actual maximum number of device contexts may be platform or configuration dependent.
*/
#define ISMD_VIDPPROC_MAX_HANDLES (16)

/**
@brief The number of bytes required to store a raw (Packed) Luma Filter

Y Plane Filter tables consists of 127 phases each with a 9 tap filter.
Each 9 tap filter is made up of 9 fixed point coefficients packed into 4 dwords.
*/
#define ISMD_VIDPPROC_Y_RAW_FILTER_BYTES (2032)

/**
@brief The number of bytes required to store a raw (Packed) Chroma Filter

UV Plane Filter tables consists of 127 phases each with a 5 tap filter.
Each 5 tap filter is made up of 5 fixed point coefficients packed into 2 dwords.
*/
#define ISMD_VIDPPROC_UV_RAW_FILTER_BYTES (1016)

/**
@brief The number of coefficients in a filter table for the Y plane.

Y Plane Filter tables consists of 127 phases each with a 9 tap filter.
Each 9 tap filter is made up of 9 fixed point coefficients.
*/
#define ISMD_VIDPPROC_Y_FILTER_COEFFICIENTS (127*9)

/**
@brief The number of coefficients in a filter table for the UV plane.

UV Plane Filter tables consists of 127 phases each with a 5 tap filter.
Each 5 tap filter is made up of 5 fixed point coefficients.
*/
#define ISMD_VIDPPROC_UV_FILTER_COEFFICIENTS (127*5)

/**
@brief The number of bytes needed to store an unpacked Y Plane Filter Table.

Y Plane Filter tables consists of 127 phases each with a 9 tap filter.
Each 9 tap filter is made up of 9 fixed point coefficients stored in 9 dwords.
*/
#define ISMD_VIDPPROC_Y_FILTER_SIZE (ISMD_VIDPPROC_Y_FILTER_COEFFICIENTS * 4)

/**
@brief The number of bytes needed to store an unpacked UV Plane Filter Table.

UV Plane Filter tables consists of 127 phases each with a 5 tap filter.
Each 5 tap filter is made up 5 fixed point coefficients stored in 5 dwords.
*/
#define ISMD_VIDPPROC_UV_FILTER_SIZE (ISMD_VIDPPROC_UV_FILTER_COEFFICIENTS * 4)

/* Legacy Defines */

/**
@brief Legacy constant

@deprecated please use ISMD_VIDPPROC_Y_*_FILTER_* macros
*/
#define MAX_Y_FILTER_SIZE ISMD_VIDPPROC_Y_RAW_FILTER_BYTES

/**
@brief Legacy constant

@deprecated please use ISMD_VIDPPROC_UV_*_FILTER_* macros
*/
#define MAX_UV_FILTER_SIZE ISMD_VIDPPROC_UV_RAW_FILTER_BYTES

/**
@brief defines vidpproc's available scaling policies.

Scaling Policies affect how vidpproc fits the source video into the destination
when the frame rectangles do not match.
*/
typedef enum ismd_vidpproc_scaling_policy_t{
   /**
   Scale to Fit uses basic independent x and y adjustment ignoring pixel aspect ratio
   This policy distorts the picture to fill the destination.
   */
   ISMD_VIDPPROC_SCALING_POLICY_SCALE_TO_FIT,

   /**
   No Scaling forces each pixel on the output to corresponds to one and only one pixel
   on the input (ignoring pixel aspect ratio)
   */
   ISMD_VIDPPROC_SCALING_POLICY_NO_SCALING,

   /**
   Zoom To Fill fills the entire output by zooming the input in or out until at least one edge
   is the same size on the input and the output, and at most one side is longer on the input than the
   output, resulting in cropping either the top and bottom or sides of the input.
   This policy respects the source and destination pixel aspect ratios.
   */
   ISMD_VIDPPROC_SCALING_POLICY_ZOOM_TO_FILL,

   /**
   Zoom To Fit fits the entire input on the output by zooming the input in or out until at least one edge
   is the same size on the input and the output, and at most one side is shorter on the input than the
   output, resulting in black bars either on the the top and bottom (letterboxing) or sides (pillar boxing)
   of the input.
   This policy respects the source and destination pixel aspect ratios.
   */
   ISMD_VIDPPROC_SCALING_POLICY_ZOOM_TO_FIT,

   /**
   This policy is similar to Scale to fit, but instead of simple linear scaling non linear regions
   are added to the left and right of a linearly scaled picture in the center resulting in a filled
   output and relatively undistorted central portion of the image.
   */
   ISMD_VIDPPROC_SCALING_POLICY_NON_LINEAR_SCALE_TO_FIT,

   /**
   Maximum number of scaling policies
   */
   ISMD_VIDPPROC_SCALING_POLICY_COUNT,

   /* Legacy Policy Names */

   /**
   @deprecated please use ISMD_VIDPPROC_SCALING_POLICY_SCALE_TO_FIT
   */
   SCALE_TO_FIT = ISMD_VIDPPROC_SCALING_POLICY_SCALE_TO_FIT,

   /**
   @deprecated please use ISMD_VIDPPROC_SCALING_POLICY_NO_SCALING
   */
   VPP_NO_SCALING = ISMD_VIDPPROC_SCALING_POLICY_NO_SCALING,

   /**
   @deprecated please use ISMD_VIDPPROC_SCALING_POLICY_ZOOM_TO_FILL
   */
   ZOOM_TO_FILL = ISMD_VIDPPROC_SCALING_POLICY_ZOOM_TO_FILL,

   /**
   @deprecated please use ISMD_VIDPPROC_SCALING_POLICY_ZOOM_TO_FIT
   */
   ZOOM_TO_FIT = ISMD_VIDPPROC_SCALING_POLICY_ZOOM_TO_FIT,

   /**
   @deprecated please use ISMD_VIDPPROC_SCALING_POLICY_NON_LINEAR_SCALE_TO_FIT
   */
   VPP_SCP_ANAMORPHIC = ISMD_VIDPPROC_SCALING_POLICY_NON_LINEAR_SCALE_TO_FIT,

   /**
   @deprecated please use ISMD_VIDPPROC_SCALING_POLICY_COUNT
   */
   VPP_MAX_SCALING_POLICIES = ISMD_VIDPPROC_SCALING_POLICY_COUNT,

} ismd_vidpproc_scaling_policy_t;

/**
@brief defines vidpproc's available deinterlacing policies.

Deinterlacing policies affect how vidpproc handles interlaced input.
*/
typedef enum ismd_vidpproc_deinterlace_policy_t{
   /**
   The None Deinterlacing Policy allows interlaced pass-through of content without
   vertical scaling.

   If there is no vertical scaling do not deinterlace.
   If there is vertical scaling deinterlace.
   */
   ISMD_VIDPPROC_DI_POLICY_NONE = 0,

   /**
   The Spatial Only Deinterlacing Policy does spatial deinterlacing on all input.
   Spatial Deinterlacing uses only two adjacent fields to create a frame.
   each field is used to generate two frames, combined with the immediate preceding
   and following fields.
   */
   ISMD_VIDPPROC_DI_POLICY_SPATIAL_ONLY,

   /**
   The Film Deinterlacing Policy uses Film Mode Detection with a relatively low threshold
   (effectively making the assumption that the incoming content is Film Mode).
   If the content does not cross the Film Mode Detection threshold Motion Adaptive
   Deinterlacing is used.

   Recommended for applications where content is expected to be of film (24Hz) origin.
   */
   ISMD_VIDPPROC_DI_POLICY_FILM,

   /**
   The Video Deinterlacing Policy uses only Motion Adaptive Deinterlacing. Film Mode
   Detection is disabled in this mode.

   Recommended for applications where content is expected to be of TV (25/30/50/60Hz) origin.
   */
   ISMD_VIDPPROC_DI_POLICY_VIDEO,

   /**
   The Auto Deinterlacing Policy uses Film Mode Detection with a relatively high threshold
   (effectively not making the assumption that the incoming content is Film Mode).
   If the content does not cross the Film Mode Detection threshold Motion Adaptive
   Deinterlacing is used.

   This is a compromise between Film and Video modes.
   */
   ISMD_VIDPPROC_DI_POLICY_AUTO,

   /**
   The Top Field Only Deinterlacing Policy duplicates each top field to generate a full height
   frame with reduced vertical resolution. This is most useful for contrasting with other
   policies when debugging.
   */
   ISMD_VIDPPROC_DI_POLICY_TOP_FIELD_ONLY,

   /**
   The Never Deinterlacing Policy allows the maximum current implemented level of
   interlaced pass-through.

   Note: Some settings may still result in deinterlacing.
   */
   ISMD_VIDPPROC_DI_POLICY_NEVER,

   /**
   The deinterlacing policy count.
   */
   ISMD_VIDPPROC_DI_POLICY_COUNT,

   /* Legacy Policy Names */

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_NONE
   */
   NONE = ISMD_VIDPPROC_DI_POLICY_NONE,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_SPATIAL_ONLY
   */
   SPATIAL_ONLY = ISMD_VIDPPROC_DI_POLICY_SPATIAL_ONLY,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_FILM
   */
   FILM = ISMD_VIDPPROC_DI_POLICY_FILM,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_VIDEO
   */
   VIDEO = ISMD_VIDPPROC_DI_POLICY_VIDEO,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_AUTO
   */
   AUTO = ISMD_VIDPPROC_DI_POLICY_AUTO,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_TOP_FIELD_ONLY
   */
   TOP_FIELD_ONLY = ISMD_VIDPPROC_DI_POLICY_TOP_FIELD_ONLY,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_NEVER
   */
   NEVER = ISMD_VIDPPROC_DI_POLICY_NEVER,

   /**
   @deprecated please use ISMD_VIDPPROC_DI_POLICY_COUNT
   */
   VPP_MAX_DEINTERLACE_POLICIES = ISMD_VIDPPROC_DI_POLICY_COUNT,

} ismd_vidpproc_deinterlace_policy_t;

/**
@brief defines the vertical scaling policies supported by vidpproc.
*/
typedef enum ismd_vidpproc_vertical_scaling_policy_t{
   /**
   Normal Scaling
   */
   ISMD_VIDPPROC_VSCALE_POLICY_NORMAL,

   /**
   Halve the vertical resolution before processing the frame. Used to reduce
   the input bandwidth to the vidpproc hardware.
   */
   ISMD_VIDPPROC_VSCALE_POLICY_HALF_PRESCALING,

   /**
   Maximum number of policies
   */
   ISMD_VIDPPROC_VSCALE_POLICY_COUNT,

   /* Legacy Names */

   /**
   @deprecated please use ISMD_VIDPPROC_VSCALE_POLICY_NORMAL
   */
   NORMAL_VERTICAL_SCALING = ISMD_VIDPPROC_VSCALE_POLICY_NORMAL,

   /**
   @deprecated please use ISMD_VIDPPROC_VSCALE_POLICY_HALF_PRESCALING
   */
   HALF_VERTICAL_PRESCALING = ISMD_VIDPPROC_VSCALE_POLICY_HALF_PRESCALING,

   /**
   @deprecated please use ISMD_VIDPPROC_VSCALE_POLICY_COUNT
   */
   VPP_MAX_VERTICAL_SCALING_POLICIES = ISMD_VIDPPROC_VSCALE_POLICY_COUNT,
} ismd_vidpproc_vertical_scaling_policy_t;

/**
@brief defines vidpproc's available parameters.

These parameters affect basic operation settings used by vidpproc's
underlying firmware.
*/
typedef enum ismd_vidpproc_param_t{
   /**
   Used internally to determine the number of parameter enums
   */
   ISMD_VIDPPROC_PARAM_FIRST = 0x100,

   /**
   deinterlace policy
   */
   ISMD_VIDPPROC_PARAM_DI_POLICY = ISMD_VIDPPROC_PARAM_FIRST,

   /**
   motion threshold
   */
   ISMD_VIDPPROC_PARAM_MADTH_DELTA,

   /**
   noise filter level
   */
   ISMD_VIDPPROC_PARAM_NRF_LEVEL,

   /**
   Horizontal inside-scaler deringing
   */
   ISMD_VIDPPROC_PARAM_ENABLE_HSC_DERING,

   /**
   Vertical inside-scaler deringing
   */
   ISMD_VIDPPROC_PARAM_ENABLE_VSC_DERING,

   /**
   Horizontal coefficients table index shift Y
   */
   ISMD_VIDPPROC_PARAM_HSC_COEFF_IDXSHIFT_Y,

   /**
   Horizontal coefficients table index shift UV
   */
   ISMD_VIDPPROC_PARAM_HSC_COEFF_IDXSHIFT_UV,

   /**
   Vertical coefficients table index shift Y
   */
   ISMD_VIDPPROC_PARAM_VSC_COEFF_IDXSHIFT_Y,

   /**
   Vertical coefficients table index shift UV
   */
   ISMD_VIDPPROC_PARAM_VSC_COEFF_IDXSHIFT_UV,

   /**
   Scaler coefficient table number for Y
   */
   ISMD_VIDPPROC_PARAM_SCALER_TABLES_NUM_Y,

   /**
   Scaler coefficient table number for Y
   */
   ISMD_VIDPPROC_PARAM_SCALER_TABLES_NUM_UV,

   /**
   Stream Priority
   */
   ISMD_VIDPPROC_PARAM_STREAM_PRIORITY,

   /**
   Bypass Deinterlacer
   */
   ISMD_VIDPPROC_PARAM_BYPASS_DEINTERLACE,

   /**
   Maximum of Absolute Differences Post Motion Detection Weight
   */
   ISMD_VIDPPROC_PARAM_MAD_WEIGHT_POST,

   /**
   Maximum of Absolute Differences Pre Detection Weight
   */
   ISMD_VIDPPROC_PARAM_MAD_WEIGHT_PRE,

   /**
   Sum of Absolute Differences Post Motion Detection Weight
   */
   ISMD_VIDPPROC_PARAM_SAD_WEIGHT_POST,

   /**
   Sum of Absolute Differences Pre Motion Detection Weight (used for low scores)
   */
   ISMD_VIDPPROC_PARAM_SAD_WEIGHT_PRE1,

   /**
   Sum of Absolute Differences Pre Motion Detection Weight
   */
   ISMD_VIDPPROC_PARAM_SAD_WEIGHT_PRE2,

   /**
   Enable Gen4 Enhanced DI algorithm
   */
   ISMD_VIDPPROC_PARAM_ENABLE_GEN4_ENHANCED_DI_ALGORITHM,

   /**
   Chroma scanlines vertically co-sited with original 4:2:0 lines
   */
   ISMD_VIDPPROC_PARAM_ENABLE_CHROMA_COSITE,

   /**
   Bypass 32322 23322 Film Mode Cadence Detection in AUTO FMD
   */
   ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_32322_23322,

   /**
   Bypass 32 Film Mode Cadence Detection in AUTO FMD
   */
   ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_32,

   /**
   Bypass 2224 2332 Film Mode Cadence Detection in AUTO FMD
   */
   ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_2224_2332,

   /**
   Bypass 22 Film Mode Cadence Detection in AUTO FMD
   */
   ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_22,

   /**
   Bypass 33 Film Mode Cadence Detection in AUTO FMD
   */
   ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_33,

   /**
   Bypass ETC Film Mode Cadence Detection in AUTO FMD
   */
   ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_ETC,

   /**
   Disable MAD motion detection in Gen4 Deinterlacer
   */
   ISMD_VIDPPROC_PARAM_DISABLE_MAD_MOTION_DETECTION,

   /**
   Cadence type
   */
   ISMD_VIDPPROC_PARAM_FMD_CADENCE_TYPE,

   /**
   frame packing format
   */
   ISMD_VIDPPROC_PARAM_FRAME_PACKING_FORMAT,

   /**
   horizontal shift for side-by-side right view
   */
   ISMD_VIDPPROC_PARAM_RIGHT_SHIFT_FOR_RIGHT_VIEW,

   /**
   vertical shift for tab bottom view
   */
   ISMD_VIDPPROC_PARAM_DOWN_SHIFT_FOR_BOTTOM_VIEW,

   /**
   vertical shift for tab bottom view
   */
   ISMD_VIDPPROC_PARAM_LAST_FIRMWARE_ERROR,

   /**
   Used internally to determine the number of parameter enums
   */
   ISMD_VIDPPROC_PARAM_COUNT,

   /* Legacy Names */

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_FIRST
   */
   PAR_FIRST = ISMD_VIDPPROC_PARAM_FIRST,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_DI_POLICY
   */
   PAR_DI_POLICY = ISMD_VIDPPROC_PARAM_DI_POLICY,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_MADTH_DELTA
   */
   PAR_MADTH_DELTA = ISMD_VIDPPROC_PARAM_MADTH_DELTA,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_NRF_LEVEL
   */
   PAR_NRF_LEVEL = ISMD_VIDPPROC_PARAM_NRF_LEVEL,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_ENABLE_HSC_DERING
   */
   PAR_ENABLE_HSC_DERING = ISMD_VIDPPROC_PARAM_ENABLE_HSC_DERING,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_ENABLE_VSC_DERING
   */
   PAR_ENABLE_VSC_DERING = ISMD_VIDPPROC_PARAM_ENABLE_VSC_DERING,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_HSC_COEFF_IDXSHIFT_Y
   */
   PAR_HSC_COEFF_IDXSHIFT_Y = ISMD_VIDPPROC_PARAM_HSC_COEFF_IDXSHIFT_Y,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_HSC_COEFF_IDXSHIFT_UV
   */
   PAR_HSC_COEFF_IDXSHIFT_UV = ISMD_VIDPPROC_PARAM_HSC_COEFF_IDXSHIFT_UV,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_VSC_COEFF_IDXSHIFT_Y
   */
   PAR_VSC_COEFF_IDXSHIFT_Y = ISMD_VIDPPROC_PARAM_VSC_COEFF_IDXSHIFT_Y,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_VSC_COEFF_IDXSHIFT_UV
   */
   PAR_VSC_COEFF_IDXSHIFT_UV = ISMD_VIDPPROC_PARAM_VSC_COEFF_IDXSHIFT_UV,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_SCALER_TABLES_NUM_Y
   */
   PAR_SCALER_TABLES_NUM_Y = ISMD_VIDPPROC_PARAM_SCALER_TABLES_NUM_Y,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_SCALER_TABLES_NUM_UV
   */
   PAR_SCALER_TABLES_NUM_UV = ISMD_VIDPPROC_PARAM_SCALER_TABLES_NUM_UV,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_STREAM_PRIORITY
   */
   PAR_STREAM_PRIORITY = ISMD_VIDPPROC_PARAM_STREAM_PRIORITY,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_DEINTERLACE
   */
   PAR_BYPASS_DEINTERLACE = ISMD_VIDPPROC_PARAM_BYPASS_DEINTERLACE,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_MAD_WEIGHT_POST
   */
   PAR_MAD_WEIGHT_POST = ISMD_VIDPPROC_PARAM_MAD_WEIGHT_POST,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_MAD_WEIGHT_PRE
   */
   PAR_MAD_WEIGHT_PRE = ISMD_VIDPPROC_PARAM_MAD_WEIGHT_PRE,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_SAD_WEIGHT_POST
   */
   PAR_SAD_WEIGHT_POST = ISMD_VIDPPROC_PARAM_SAD_WEIGHT_POST,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_SAD_WEIGHT_PRE1
   */
   PAR_SAD_WEIGHT_PRE1 = ISMD_VIDPPROC_PARAM_SAD_WEIGHT_PRE1,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_SAD_WEIGHT_PRE2
   */
   PAR_SAD_WEIGHT_PRE2 = ISMD_VIDPPROC_PARAM_SAD_WEIGHT_PRE2,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_ENABLE_GEN4_ENHANCED_DI_ALGORITHM
   */
   PAR_ENABLE_GEN4_ENHANCED_DI_ALGORITHM = ISMD_VIDPPROC_PARAM_ENABLE_GEN4_ENHANCED_DI_ALGORITHM,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_32322_23322
   */
   PAR_BYPASS_AUTO_FMD_32322_23322 = ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_32322_23322,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_32
   */
   PAR_BYPASS_AUTO_FMD_32 = ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_32,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_2224_2332
   */
   PAR_BYPASS_AUTO_FMD_2224_2332 = ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_2224_2332,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_22
   */
   PAR_BYPASS_AUTO_FMD_22 = ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_22,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_33
   */
   PAR_BYPASS_AUTO_FMD_33 = ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_33,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_ETC
   */
   PAR_BYPASS_AUTO_FMD_ETC = ISMD_VIDPPROC_PARAM_BYPASS_AUTO_FMD_ETC,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_DISABLE_MAD_MOTION_DETECTION
   */
   PAR_DISABLE_MAD_MOTION_DETECTION = ISMD_VIDPPROC_PARAM_DISABLE_MAD_MOTION_DETECTION,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_FMD_CADENCE_TYPE
   */
   PAR_FMD_CADENCE_TYPE = ISMD_VIDPPROC_PARAM_FMD_CADENCE_TYPE,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_FMD_CADENCE_TYPE
   */
   FMD_CADENCE_TYPE = ISMD_VIDPPROC_PARAM_FMD_CADENCE_TYPE,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_FRAME_PACKING_FORMAT
   */
   PAR_FRAME_PACKING_FORMAT = ISMD_VIDPPROC_PARAM_FRAME_PACKING_FORMAT,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_RIGHT_SHIFT_FOR_RIGHT_VIEW
   */
   PAR_RIGHT_SHIFT_FOR_RIGHT_VIEW = ISMD_VIDPPROC_PARAM_RIGHT_SHIFT_FOR_RIGHT_VIEW,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_DOWN_SHIFT_FOR_BOTTOM_VIEW
   */
   PAR_DOWN_SHIFT_FOR_BOTTOM_VIEW = ISMD_VIDPPROC_PARAM_DOWN_SHIFT_FOR_BOTTOM_VIEW,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_LAST_FIRMWARE_ERROR
   */
   PAR_LAST_FIRMWARE_ERROR = ISMD_VIDPPROC_PARAM_LAST_FIRMWARE_ERROR,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_LAST_FIRMWARE_ERROR
   */
   HW_HANG_TYPE = ISMD_VIDPPROC_PARAM_LAST_FIRMWARE_ERROR,

   /**
   @deprecated please use ISMD_VIDPPROC_PARAM_COUNT
   */
   PAR_COUNT = ISMD_VIDPPROC_PARAM_COUNT
} ismd_vidpproc_param_t;


/**
@brief defines the potential errors that can be reported by the firmware.
*/
typedef enum ismd_vidpproc_firmware_error_t {
   /**
   No Error detected
   */
   ISMD_VIDPPROC_FIRMWARE_ERROR_NO_ERROR = 0,

   /**
   An error due to an unsupported scaling ratio was detected
   */
   ISMD_VIDPPROC_FIRMWARE_ERROR_LINEAR_SCALE_FACTOR_INVALID,

   /**
   An unknown error was detected
   */
   ISMD_VIDPPROC_FIRMWARE_ERROR_UNKNOWN,

   /**
   The highest known error
   */
   ISMD_VIDPPROC_FIRMWARE_ERROR_COUNT,
} ismd_vidpproc_firmware_error_t;

/**
@brief defines the potential Film Mode Detection cadences that
vidpproc can detect.
*/
typedef enum ismd_vidpproc_cadence_t {
   /**
   Progressive throughput
   */
   ISMD_VIDPPROC_CADENCE_PROGRESSIVE,

   /**
   Simple Deinterlacing
   */
   ISMD_VIDPPROC_CADENCE_DEINTERLACE,

   /**
   3:2 Cadence
   */
   ISMD_VIDPPROC_CADENCE_32,

   /**
   2:2 Cadence
   */
   ISMD_VIDPPROC_CADENCE_22,

   /**
   3:2:3:2:2 or 2:3:3:2:2 Cadence
   */
   ISMD_VIDPPROC_CADENCE_32322_OR_23322,

   /**
   2:2:2:4 or 2:3:3:2 Cadence
   */
   ISMD_VIDPPROC_CADENCE_2224_OR_2332,

   /**
   5:5 Cadence
   */
   ISMD_VIDPPROC_CADENCE_55,

   /**
   6:4 Cadence
   */
   ISMD_VIDPPROC_CADENCE_64,

   /**
   8:7 Cadence
   */
   ISMD_VIDPPROC_CADENCE_87,

   /**
   Conflicting Cadences
   */
   ISMD_VIDPPROC_CADENCE_CONFLICT,

   /**
   Film Look Cadences
   */
   ISMD_VIDPPROC_CADENCE_FILM_LOOK,

   /**
   3:3 Cadences
   */
   ISMD_VIDPPROC_CADENCE_33,

   /**
   4:4 Cadences
   */
   ISMD_VIDPPROC_CADENCE_44,

   /**
   ETC Cadences
   */
   ISMD_VIDPPROC_CADENCE_ETC,

   /**
   Count of known cadences
   */
   ISMD_VIDPPROC_CADENCE_COUNT,
} ismd_vidpproc_cadence_t;

/**
@brief defines the global (non-context specific) events
supported by vidpproc.
*/
typedef enum ismd_vidpproc_global_event_t {
   /**
   Event signaled when a DPE device has been opened.
   */
   ISMD_VIDPPROC_GLOBAL_EVENT_DEVICE_OPENED,

   /**
   Event signaled when a DPE device has been closed
   */
   ISMD_VIDPPROC_GLOBAL_EVENT_DEVICE_CLOSED,

   /**
   Used internally to determine the number of events
   */
   ISMD_VIDPPROC_GLOBAL_EVENT_COUNT,

   /* Legacy Names */

   /**
   @deprecated please use ISMD_VIDPPROC_GLOBAL_EVENT_DEVICE_OPENED
   */
   ISMD_VIDPPROC_DEVICE_OPENED_EVENT = ISMD_VIDPPROC_GLOBAL_EVENT_DEVICE_OPENED,

   /**
   @deprecated please use ISMD_VIDPPROC_GLOBAL_EVENT_DEVICE_CLOSED
   */
   ISMD_VIDPPROC_DEVICE_CLOSED_EVENT = ISMD_VIDPPROC_GLOBAL_EVENT_DEVICE_CLOSED,
} ismd_vidpproc_global_event_t;

/**
@brief Defines the device context specific events available in vidpproc.
*/
typedef enum ismd_vidpproc_event_t {
   /**
   Event signaled when the resolution of the input on a DPE device context has changed.
   */
   ISMD_VIDPPROC_EVENT_INPUT_RESOLUTION_CHANGED,

   /**
   Event signaled when the displayed resolution of the input on a DPE device context has changed.
   */
   ISMD_VIDPPROC_EVENT_INPUT_DISPLAY_RESOLUTION_CHANGED,

   /**
   Event signaled when the detected Film Mode Cadence of the input on a DPE device context has changed.
   */
   ISMD_VIDPPROC_EVENT_FILM_MODE_CADENCE_CHANGED,

   /**
   Event signaled when the vidpproc firmware reports an error.
   */
   ISMD_VIDPPROC_EVENT_FIRMWARE_REPORTED_ERROR,

   /**
   Event signaled when the active region (on input or output) has changed.
   */
   ISMD_VIDPPROC_EVENT_ACTIVE_REGION_CHANGED,

   /**
   Event signaled when the deintelacer reset (in vidpproc) has changed.
   */
   ISMD_VIDPPROC_EVENT_DEINTERLACER_RESET,

   /**
   Used internally to determine the number of event values
   */
   ISMD_VIDPPROC_EVENT_COUNT,
} ismd_vidpproc_event_t;

/**
@brief Defines the primary modes in which vidpproc can execute.
*/
typedef enum ismd_vidpproc_mode_t{
   /**
   Special Invalid mode value. Not a valid mode.
   */
   ISMD_VIDPPROC_INAVLID_MODE = 0,

   /**
   Normal mode, where advanced interfaces that do not ensure correctness
   of input can be used.
   */
   ISMD_VIDPPROC_MODE_NORMAL,

   /**
   Advanced Display Processing Mode. Exposes low level interfaces that can be used unsafely.
   */
   ISMD_VIDPPROC_MODE_ADP,

   /**
   The maximum value of a mode enumeration member.
   */
   ISMD_VIDPPROC_MODE_COUNT,
} ismd_vidpproc_mode_t;

/**
@brief Describes the result of a handle query.

Specifically this a list of handles and flags indicating if those handles
pointed to valid (open) devices at the time of the query.
*/
typedef struct ismd_vidpproc_handle_query_result_t {
   /**
   The list of available handles.
   */
   ismd_dev_handle_t dev_handle[ISMD_VIDPPROC_MAX_HANDLES];

   /**
   Flags to indicate which handles from the dev_handle list are
   valid to be used. Note that the valid handles are not required
   to be packed at the start of the list.
   */
   bool dev_handle_valid[ISMD_VIDPPROC_MAX_HANDLES];

   /**
   The number of valid handles.
   */
   int valid_hanlde_cnt;
}

ismd_vidpproc_handle_query_result_t ;

/**
@brief Initializes the vidpproc driver.

Initializes the vidpproc driver. This should only be
called once. For Linux kernel builds, this will automatically be
called in module init

@retval ISMD_SUCCESS The device was successfully opened

@see ismd_module_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_init(void);

/**
@brief Deinitializes the vidpproc driver

Deinitializes the vidpproc driver. This should only
be called once. For Linux kernel builds, this will automatically be
called in module deinit

@retval ISMD_SUCCESS The device was successfully deinitialized
@retval other All other values are failures as reported by the return code

@see ismd_module_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_deinit(void);

/**
@brief Open a vidpproc device context.

Opens a new vidpproc device. This should be called before
any other vidpproc functions are called. If a device is successfully
opened it should be closed when the application is done using it.

If a vidpproc instance is not successfully opened the handle is in an undefined
state and should not be passed to other API functions, including close.

@param[out] dev handle to the allocated instance. This handle will
be used to access the Video Post-Processor for subsequent
operations.

@retval ISMD_SUCCESS The vidpproc device was successfully opened.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDCONNECTION ismd_vidpproc_open( ismd_dev_t *dev);

/**
@brief Close a vidpproc device that has been previously opened context.

Closes a vidpproc device that has been previously opened. This should
only be called once per device, after this function has been called
no more functions may be called on that device

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The vidpproc device was successfully closed.
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other valuesa failure as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_close(ismd_dev_t dev);

/**
@brief Sets the vidpproc output pixel format for a context.

Sets the pixel format used for output frames, the pixel format will affect
what devices can use the frames as well as the size of frame buffers in memory.

The supported output formats are:
- ISMD_PF_NV16: NV16, 8-bit pseudo-planar 4:2:2
- ISMD_PF_YUY2: YUY2 (aka YUYV), 8-bit packed 4:2:2
- ISMD_PF_NV20: NV20, 10-bit pseudo-planar 4:2:2

@param[in] dev vidpproc device handle
@param[in] output_fmt pixel format

@retval ISMD_SUCCESS The output format was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval ISMD_ERROR_INVALID_PARAMETER The output format was not supported.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_pixel_format_t
*/

ismd_result_t SMDEXPORT ismd_vidpproc_set_output_format(
   ismd_dev_t dev,
   ismd_pixel_format_t output_fmt
);

/**
@brief Sets the output geometry of the vidpproc output for scaling
for a context.

Sets the pixel resolution (width and height) and pixel aspect ratio
used to when scaling input to output. In normal cases the pixel
resolution set here will be the pixel resolution of the output
frame, and the entire input frame (after cropping) will be scaled
to this size using the current scaling policy.

When the scaling policy respects aspect ratio (zoom policies) the
pixel aspect ratio setting provided here is used as part of the scaling
calculation.

When output is connected to the display driver the combined effect of
the Width, Height, and origin (set either in vidpproc or the display driver
must never result in pixels being rendered off of the display plane
(origin must be positive and x+width and y+height must be smaller than
display width and height respectively.)

In most cases the Pixel aspect ratio should be the same as the display
pixel aspect ratio. It is important to note that this is not the display
aspect ratio, common values for the pixel aspect ratio are 1:1 or 11:10
while common values for display aspect ratios are 16:9 or 4:3. Unlike
the display aspect the pixel aspect ratio does not change with cropping
operations, so this value can be used without change in reference to any
rectangle on a frame regardless of pixel dimensions.

In some cases such as some 3D output formats changing the pixel aspect
ratio is required to distort the output to achieve desirable effects.

Each input frame buffer has its own width, height and pixel aspect ratio
embedded on it by the device that created it (normally the Video Decoder
or AVCapture)

@param[in] dev vidpproc device handle
@param[in] width desired target width in pixels
@param[in] height desired target height in pixels
@param[in] aspect_ratio_num the width relative to the height represented by aspect_ratio_denom of each pixel on the output frame
@param[in] aspect_ratio_denom the height relative to the width represented by aspect_ratio_num of each pixel on the output frame

@retval ISMD_SUCCESS The destination width and height were successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed so it is stale.
@retval ISMD_INVALID_PARAMETER The destination rectangle was larger than
supported values. This may also occur if the width or height is not a
multiple of four
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_set_dest_params2
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_dest_params(
   ismd_dev_t dev,
   unsigned int width,
   unsigned int height,
   int aspect_ratio_num,
   int aspect_ratio_denom
);

/**
@brief Sets the output geometry of the vidpproc output for scaling
for a context.

Sets the pixel resolution (width and height) and pixel aspect ratio
used to when scaling input to output. In normal cases the pixel
resolution set here will be the pixel resolution of the output
frame, and the entire input frame (after cropping) will be scaled
to this size using the current scaling policy.

When the scaling policy respects aspect ratio (zoom policies) the
pixel aspect ratio setting provided here is used as part of the scaling
calculation.

When output is connected to the display driver the combined effect of
the Width, Height, and origin (set either in vidpproc or the display driver
must never result in pixels being rendered off of the display plane
(origin must be positive and x+width and y+height must be smaller than
display width and height respectively.)

@note the origin set here is not used by vidpproc but is forwarded
along with the frame data to synchronously update the display driver.

In most cases the Pixel aspect ratio should be the same as the display
pixel aspect ratio. It is important to note that this is not the display
aspect ratio, common values for the pixel aspect ratio are 1:1 or 11:10
while common values for display aspect ratios are 16:9 or 4:3. Unlike
the display aspect the pixel aspect ratio does not change with cropping
operations, so this value can be used without change in reference to any
rectangle on a frame regardless of pixel dimensions.

In some cases such as some 3D output formats changing the pixel aspect
ratio is required to distort the output to achieve desirable effects.

Each input frame buffer has its own width, height and pixel aspect ratio
embedded on it by the device that created it (normally the Video Decoder
or AVCapture)

@param[in] dev vidpproc device handle
@param[in] width desired target width in pixels
@param[in] height desired target height in pixels
@param[in] aspect_ratio_num the width relative to the height represented by aspect_ratio_denom of each pixel on the output frame
@param[in] aspect_ratio_denom the height relative to the width represented by aspect_ratio_num of each pixel on the output frame
@param[in] dest_x destination rectangle origin x
@param[in] dest_y destination rectangle origin y

@retval ISMD_SUCCESS The destination width and height were successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed so it is stale.
@retval ISMD_INVALID_PARAMETER The destination rectangle was larger than
supported values. This may also occur if the width or height is not a
multiple of four
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_set_dest_params
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_dest_params2(
   ismd_dev_t dev,
   unsigned int width,
   unsigned int height,
   int aspect_ratio_num,
   int aspect_ratio_denom,
   unsigned int dest_x,
   unsigned int dest_y
);

/**
@brief Enable the deringing filter for a context.

Enable the deringing filter for a context.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The deringing filter was successfully enabled
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/

ismd_result_t SMDEXPORT ismd_vidpproc_deringing_enable( ismd_dev_t dev);

/**
@brief Disables the deringing filter for a context.

Disables the deringing filter for a context.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The deringing filter was successfully disabled
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/

ismd_result_t SMDEXPORT ismd_vidpproc_deringing_disable( ismd_dev_t dev);

/**
@brief Sets the level of deringing processing for a context.

Sets the deringng level (also known as the Ringing Noise
Reduction, or RNR value) for a context.

Values range from 1-100 with 100 being the highest.
The Default value is 4.

@param[in] dev vidpproc device handle
@param[in] level RNR level (1-100)

@retval ISMD_SUCCESS The RNR level was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_deringing_level( ismd_dev_t dev, int level);

/**
@brief Enable Gaussian noise reduction filter in the deinterlacer for a context.

Enable Gaussian (temporal) noise reduction filter in the deinterlacer for a context.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The Gaussian filter was enabled
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_gaussian_enable( ismd_dev_t dev);

/**
@brief Disable the Gaussian noise reduction filter in the deinterlacer for a context.

Disable the Gaussian (temporal) noise reduction filter in the deinterlacer for a context.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The Gaussian filter was disabled
@retval ISMD_ERROR_INVALID_HANDLE The port handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_gaussian_disable( ismd_dev_t dev);

/**
@brief Set the Gaussian noise reduction level for a context.

Set the Gaussian (temporal) noise reduction level for a context

Values range from 0-2 with 2 being the highest.
The Default value is 1.


@param[in] dev vidpproc device handle
@param[in] level NRF level (0-2)

@retval ISMD_SUCCESS The RNR level was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_gaussian_level( ismd_dev_t dev, int level);

/**
@brief Sets a desired a blur factor for a context

Sets a desired a blur factor for a context.

This API works by shifting the index of the scaling table to be used
each scaling table corresponds to a range of scaling ratios so the result
is similar to (but not exactly the same as) scaling the frame to another
ratio and then re-scaling back to the desired size.

@note Because the list of scaling tables is limited full burring may not
be available at all scaling ratios.

@note if scaling tables been overridden by the application the overridden
tables may be used, this is a particular risk at very high blur factors.

@param[in] dev vidpproc device handle
@param[in] blur_factor range from 0-99 (0 is no blurring, 99 is max)

@retval ISMD_SUCCESS The horizontal degradation mode was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_degrade_factor( ismd_dev_t dev, unsigned int blur_factor);

/**
@brief Disables blurring for a context

Disables blurring for a context

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The horizontal degradation mode was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_disable_degrade_factor( ismd_dev_t dev);

/**
@brief Set playback rate for a context

Set the vidpproc playback rate for the scaler and deinterlacer. This will
only be used in the deinterlacing case. Spatial deinterlacing only in trick mode.

@note this value is not used in any functional paths

@param[in] dev vidpproc device handle
@param[in] playback_rate_fixed rate to set the VIDPPROC playback rate.

@retval ISMD_SUCCESS The playback rate was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_playback_rate( ismd_dev_t dev, int playback_rate_fixed);

/**
@brief Set cropping based on the input frame for a context.

Set cropping of the input frame for a context, this sets a
cropping rectangle based on the size and pixel aspect
ratio of an input frame, similar to the way pan-scan data
is embedded in most formats, it should be adjusted whenever
the input resolution or pixel aspect ratio changes.

This cropping rectangle is applied after all embedded cropping
rectangles on the input frame including pan-scan (if enabled).

Because the vidpproc scaling algorithm fits input to output size
cropping the input without changing the destination size will
normally result in some form of zoom or up scaling depending on the
scaling policy.

@note the ratio between the width/height set here and the output
width/height set in ismd_vidpproc_set_dest_params must not result
in an unsupported scaling ratio (the maximum ratio varies with HW
and FW revisions)

@note the cropping rectangle described must be completely contained
on the input.

@param[in] dev vidpproc device handle
@param[in] x leftmost column of cropping rectangle
@param[in] y topmost row of cropping rectangle
@param[in] width width of cropping rectangle
@param[in] height height of cropping rectangle

@retval ISMD_SUCCESS The source cropping rectangle pixel parameters were
successfully set
@retval ISMD_ERROR_INVALID_HANDLE The port handle was not valid. Note
that this may indicate that handle was recently closed.
@retval ISMD_INVALID_PARAMETER The cropping rectangle or the cropping
rectangle plus x and y was larger than supported values.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_crop_input( ismd_dev_t dev,
      unsigned int x, unsigned int y,
      unsigned int width, unsigned int height);

/**
@brief Set the scaling params to be used by the Display driver.

This feature allows the user to set the width and height of the frame
scaled by the display driver and written on the display plane. Vidpproc
acts as an enabler and passes on these values to downstream drivers.

The API can be used to set the scaling width and height used by the display driver
to scale the frame to the given size right before it is displayed on the screen.4

Please refer to section 7.2.6 of the GDL Programming Guide for more details on how
the scaling is carried out.

@note This API should not be called along with the deprecated API
\ref ismd_vidrend_set_dest_params, as the deprecated API opens a separate instance
of vidpproc on which the above API has not been called. Hence these display feature
would not be enabled on the new scaled frame. This will have an undesired effect
on the screen.

@note: Vidpproc does not perform any sort of validation on the parameters taken
as input from the user. The responsibility of any input parameter validity check
is with Display as it is implementation dependent.

@param[in] dev: vidpproc device handle
@param[in] scaled_width: The scaling output width of the frame which is to be displayed
on the display plane.
@param[in] scaled_height: The scaling output height of the frame which is to be displayed
on the display plane.

@retval ISMD_SUCCESS The display scaling params were set correctly.
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_set_dest_params
@see ismd_vidpproc_set_display_cropping
**/
ismd_result_t SMDEXPORT ismd_vidpproc_set_display_scaling(
   ismd_dev_t dev,
   unsigned int scaling_width,
   unsigned int scaling_height
);

/**
@brief Set the cropping paramaters to be used by the Display driver.

This feature allows the user to set the cropping rectangle of the frame
processed by the display driver before it is flipped onto the display plane.
Vidpproc acts as an enabler and passes on these values to downstream drivers.

The API can be used to set the cropping rectangle used by the display driver
to crop out the remaining portion of the frame before it begins processing the
frame.

Please refer to section 7.2.6 of the GDL Programming Guide for more details on how
the cropping is carried out.

@note This API should not be called along with the deprecated API
\ref ismd_vidrend_set_dest_params, as the deprecated API opens a separate instance
of vidpproc on which the above API has not been called. Hence this display feature
would not be enabled on the new scaled frame. This will have an undesired effect
on the screen.

@note: Vidpproc does not perform any sort of validation on the parameters taken
as input from the user. The responsibility of any input parameter validity check
is with Display as it is implementation dependent.

@param[in] dev vidpproc device handle
@param[in] h_offset: The horizontal offset of the cropping rectangle which is used
by display to define the horizontal region of interest.
@param[in] v_offset: The vertical offset of the cropping rectangle which is used
by display to define the vertical region of interest.
@param[in] cropping_width: The width of the cropping rectangle which is used
by display to define the horizontal region of interest.
@param[in] cropping_height: The height of the cropping rectangle which is used
by display to define the horizontal region of interest.

@retval ISMD_SUCCESS The display cropping rect was correctly set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_set_dest_params
@see ismd_vidpproc_set_display_scaling
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_display_cropping(
   ismd_dev_t dev,
   unsigned int h_offset,
   unsigned int v_offset,
   unsigned int width,
   unsigned int height
);

/**
@brief Disable cropping based on the input frame for a context.

Disable cropping based on input frame for a context.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The source cropping was disabled
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_disable_crop_input( ismd_dev_t dev);

/**
@brief Set cropping based on the destination size for a context.

Set cropping based on the destination size for a context, this sets a
cropping rectangle based on the size and pixel aspect
ratio set in \ref ismd_vidpproc_set_dest_params, the rectangle is
translated by vidpproc into an input cropping rectangle
based on the current scaling policy and input size.

When this API is in use the output frame has the pixel dimensions
of the width and height specified in this API. The content of the
frame is effectively the same as chaining two vidpproc contexts
together and using the settings applied here to configure the
destination width/height and the input crop on t he second
device. The advantage to this API is that the frame is only
processed once by vidpproc, saving bandwidth, and the
rectangle set in \ref ismd_vidpproc_set_dest_params can be larger
than the maximum supported output size allowing higher scaling
ratios without resorting to directly computing the input cropping
rectangle


This cropping rectangle is applied after all input cropping,
including embedded and user specified input cropping on the
input frame including pan-scan (if enabled).

@note This API overrides the output frame size set in
\ref ismd_vidpproc_set_dest_params, however it does not override the
pixel aspect ratio or origin settings, and the size setting in
\ref ismd_vidpproc_set_dest_params is still used to compute the scaling
ratio and cropping or black bars in the zoom scaling policies.

@note Anamorphic (non-linear) scaling is not supported when this
API is in use, vidpproc will automatically revert to the
scale-to-fit policy if anamorphic scaling is in use.


@param[in] dev vidpproc device handle
@param[in] x leftmost column of cropping rectangle
@param[in] y topmost row of cropping rectangle
@param[in] width width of cropping rectangle
@param[in] height height of cropping rectangle

@retval ISMD_SUCCESS The source cropping rectangle pixel parameters were
successfully set
@retval ISMD_ERROR_INVALID_HANDLE The port handle was not valid. Note
that this may indicate that handle was recently closed.
@retval ISMD_INVALID_PARAMETER The cropping rectangle or the cropping
rectangle plus x and y was larger than supported values.
@retval ISMD_ERROR_FEATURE_NOT_IMPLEMENTED The scaling policy of the context
is set to VPP_SCP_ANAMORPHIC

@see ismd_dev_t
@see ismd_vidpproc_set_dest_params
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_output_crop( ismd_dev_t dev,
      unsigned int x, unsigned int y,
      unsigned int width, unsigned int height);

/**
@brief Disable cropping based on the destination size for a context.

Disable cropping based on the destination size for a context as set
in the \ref ismd_vidpproc_set_output_crop API.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The output cropping was disabled
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_disable_output_crop( ismd_dev_t dev);

/**
@brief Enables pan-scan cropping.

Enables pan-scan cropping if pan scan data is embedded on input frames.

Pan-scan data consists of per-frame cropping rectangles used to covert
between display aspect ratios based on upstream settings or human control.
It is often embedded in widescreen content to support full screen 4:3
viewing support.

Pan-scan data is also commonly found on content that is "close" to standard
display aspect ratios such as 1920x1088 (some movie content) and 1920x1200
(computer display) to convert them to standard HD (e.g. 1920x1080) without
scaling.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS Pan and scan was successfully enabled
@retval ISMD_ERROR_INVALID_HANDLE The port handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_pan_scan_enable( ismd_dev_t dev);

/**
@brief Disables pan-scan cropping.

Disables pan-scan cropping if pan scan data embedded on input frames is ignored

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS Pan and scan was disabled
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_pan_scan_disable( ismd_dev_t dev);

/** @ingroup ismd_vidpproc_tables */
/** @{ */
/**
@brief Load new luma and chroma horizontal filter coefficients.
Load new horizontal filter coefficients for the luma and chroma components.
Luma and chroma must be configured separately.

@note Not Implemented

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@deprecated This API is deprecated because it has never been implemented.
it has been replaced with \ref ismd_vidpproc_override_luma_filter_coeffcients_raw.

@param[in] dev vidpproc device handle
@param[in] y_filter_data the new luma coefficients to be loaded
@param[in] uv_filter_data the new chroma coefficients to be loaded
@param[in] y_size the size of the luma coefficients, in bytes
@param[in] uv_size the size of the chroma coefficients, in bytes

@retval ISMD_SUCCESS The horizontal filter coefficients were successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.

@see ismd_vidpproc_override_chroma_filter_coeffcients_raw
@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_horizontal_filter_coeffcients(ismd_dev_t dev, unsigned char y_filter_data[ISMD_VIDPPROC_Y_RAW_FILTER_BYTES], unsigned char uv_filter_data[ISMD_VIDPPROC_UV_RAW_FILTER_BYTES], unsigned int y_size, unsigned int uv_size);

/**
@brief Reset luma and chroma horizontal filter coefficients.
Set default horizontal filter coefficients for the luma component if a custom
set has been overridden, otherwise this function call is ignored.

@note Not Implemented

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@deprecated This API is deprecated because it has never been implemented.
it has been replaced with \ref ismd_vidpproc_reset_luma_filter_coeffcients and
\ref ismd_vidpproc_reset_chroma_filter_coeffcients.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The horizontal filter coefficients were successfully set
@retval ISMD_ERROR_INVALID_HANDLE The port handle was not valid. Note
that this may indicate that handle was recently closed.

@see ismd_vidpproc_reset_luma_filter_coeffcients
@see ismd_vidpproc_reset_chroma_filter_coeffcients
@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_default_horizontal_filter_coeffcients(ismd_dev_t dev);

/**
@brief Load new luma and chroma horizontal vertical coefficients.
Load new vertical filter coefficients for the luma and chroma components.
Luma and chroma must be configured separately.

@note Not Implemented

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@deprecated This API is deprecated because it has never been implemented.
it has been replaced with \ref ismd_vidpproc_reset_luma_filter_coeffcients and
\ref ismd_vidpproc_reset_chroma_filter_coeffcients.

@param[in] dev vidpproc device handle
@param[in] y_filter_data the new luma coefficients to be loaded
@param[in] uv_filter_data the new chroma coefficients to be loaded
@param[in] y_size the size of the luma coefficients, in bytes
@param[in] uv_size the size of the chroma coefficients, in bytes

@retval ISMD_SUCCESS The vertical filter coefficients were successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.

@see ismd_vidpproc_override_chroma_filter_coeffcients_raw
@see ismd_vidpproc_override_chroma_filter_coeffcients_raw
@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_vertical_filter_coeffcients(ismd_dev_t dev, unsigned char y_filter_data[ISMD_VIDPPROC_Y_RAW_FILTER_BYTES], unsigned char uv_filter_data[ISMD_VIDPPROC_UV_RAW_FILTER_BYTES], unsigned int y_size, unsigned int uv_size);

/**
@brief Reset luma and chroma horizontal vertical coefficients.
Set default vertical filter coefficients for the luma component if a custom
set has been overridden, otherwise this function call is ignored.

@note Not Implemented

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@deprecated This API is deprecated because it has never been implemented.
it has been replaced with \ref ismd_vidpproc_override_luma_filter_coeffcients_raw.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The horizontal filter coefficients were successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.

@see ismd_vidpproc_override_luma_filter_coeffcients_raw
@see ismd_dev_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_default_vertical_filter_coeffcients(ismd_dev_t dev);
/**\}*/ // end of ingroup ismd_vidpproc

/**
@brief Sets the scaling policy for a context.

Sets the scaling policy for a context, the scaling policy
determines how mismatches between the size and pixel aspect
ratio of the input and output are handled.

Ultimately the scaling policy handles how a mismatch in the
display aspect ratio between the input and output.

The display aspect ratio (DAR) is the pixel aspect ratio (PAR)
times the pixel width (width) over the pixel height (height).

\f[
 DAR = PAR * \frac{width}{height}
\f]

If the DAR of the input does not match the DAR of the output
vidpproc must introduce a distortion to map between the two.
In policies named "zoom" the PAR of both the input and output
are respected resulting in an apparent zoom in or out, this
requires either cropping or the addition of padding in the form
of black bars.

Other policies may distort the image resulting in apparent stretching
or crushing of the image.

@param[in] dev vidpproc device handle
@param[in] policy which scaling policy to use

@retval ISMD_SUCCESS The scaling policy was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_scaling_policy_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_scaling_policy(
   ismd_dev_t dev,
   ismd_vidpproc_scaling_policy_t policy
);

/**
@brief Sets the deinterlacing policy for a context.

Sets the deinterlacing policy for a context.

@param[in] dev vidpproc device handle
@param[in] policy which deinterlace policy to use

@retval ISMD_SUCCESS The deinterlacing policy was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_deinterlace_policy_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_deinterlace_policy(
   ismd_dev_t dev,
   ismd_vidpproc_deinterlace_policy_t policy
);

/**
@brief Gets the event that is set when the input source resolution changes.

Gets the event that is set when the input source resolution changes.
This event will occur when the first frame is received after a
device close or flush.

@deprecated this function is deprecated in favor of \ref ismd_vidpproc_get_event.

@param[in] dev vidpproc device handle
@param[out] input_src_res_event event that will be triggered when input source
resolution changes

@retval ISMD_SUCCESS The input port was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_event_t
@see ismd_vidpproc_get_event
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_input_src_resolution_event(
   ismd_dev_t dev,
   ismd_event_t *input_src_res_event
);

/**
@brief Gets the event that is set when the input display resolution changes.

Gets the event that is set when the input display resolution changes.
This event will occur when the first frame is received after a
device close or flush.

@deprecated this function is deprecated in favor of \ref ismd_vidpproc_get_event.

@param[in] dev vidpproc device handle
@param[out] *input_disp_res_event event that will be triggered when input display
resolution changes

@retval ISMD_SUCCESS The input port was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_event_t
@see ismd_vidpproc_get_event
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_input_disp_resolution_event(
   ismd_dev_t dev,
   ismd_event_t *input_disp_res_event
);

/**
@brief Gets the event that is set when the firmware detects a hang condition

Gets the event that is set when the firmware detects and recovers from a
hardware hang or a condition that could result in a hardware hang.

@deprecated this function is deprecated in favor of \ref ismd_vidpproc_get_event.

@param[in] dev vidpproc device handle
@param[out] *hw_hang_prevented_event event that will be triggered when
hardware hang is detected and prevented

@retval ISMD_SUCCESS The event was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_event_t
@see ismd_vidpproc_get_event
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_hw_hang_prevented_event(
   ismd_dev_t dev,
   ismd_event_t *hw_hang_prevented_event
);

/**
@brief Gets the current input buffer for a context.

Gets the current input buffer for a context. A new reference is added to the
reference count for the buffer before it is returned. The caller must dereference
the input buffer to prevent a memory leak.

@param[in] dev vidpproc device handle
@param[out] input_buf buffer that is currently has been read from the DPE
input port

@retval ISMD_SUCCESS The input port was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_buffer_handle_t
*/
ismd_result_t SMDTRUSTED ismd_vidpproc_get_input_buffer( ismd_dev_t dev, ismd_buffer_handle_t *input_buf);

/**
@brief Gets the input port handle for a context.

Gets the input port handle for a context. The input port is used to send
frames into vidpproc. The vidpproc driver uses events from this port internally
devices sending frames into vidpproc should create an output port to connect to
this input port.

@param[in] dev vidpproc device handle
@param[out] smd_port_handle input port

@retval ISMD_SUCCESS The input port was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_port_handle_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_input_port( ismd_dev_t dev, ismd_port_handle_t *smd_port_handle);

/**
@brief Gets the output port handle for a context.

Gets the output port handle for a context. The output port is used to send
frames out of vidpproc. The vidpproc driver uses events from this port internally
devices reading frames from vidpproc should create an input port to connect to
this output port.

@param[in] dev vidpproc device handle
@param[out] smd_port_handle output port

@retval ISMD_SUCCESS The output port was successfully retrieved
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid.
Note that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_port_handle_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_output_port( ismd_dev_t dev, ismd_port_handle_t *smd_port_handle);

/**
@brief Unified parameter setting interface.

This unified interface is used to set advanced options, in most cases
it is currently not needed for common use cases. For details in
individual parameters see \ref ismd_vidpproc_param_t.

@param[in] dev vidpproc device handle
@param[in] par_name which parameter to set
@param[in] par_value what value to set

@retval ISMD_SUCCESS The parameter was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_param_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_parameter(
   ismd_dev_t dev,
   ismd_vidpproc_param_t par_name,
   int par_value
);

/**
@brief Unified parameter reading interface.

This unified interface is used to read advanced options, in most cases
it is currently not needed for common use cases. For details in
individual parameters see \ref ismd_vidpproc_param_t.

@param[in] dev vidpproc device handle
@param[in] par_name which parameter to get
@param[out] par_value the variable address for returned parameter value

@retval ISMD_SUCCESS The parameter was successfully got
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_param_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_parameter(
   ismd_dev_t dev,
   ismd_vidpproc_param_t par_name,
   int* par_value
);

/** @ingroup ismd_vidpproc_tables */
/** @{ */

/**
@brief Sets a horizontal luma scaling table.

Overrides the existing horizontal luma coefficients for a given table.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@deprecated This API is deprecated due to security and memory access issues.
it has been replaced with \ref ismd_vidpproc_override_luma_filter_coeffcients_raw.

@param[in] dev vidpproc device handle
@param[in] y_filter_table_index index of the table to be updated
@param[in] y_filter_data a pointer to a buffer holding the new data.
@param[in] y_size the size of the filter data buffer. checked but not used.

@see ismd_vidpproc_override_luma_filter_coeffcients_raw
*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_horizontal_filter_luma_coefficients(
   ismd_dev_t dev,
   unsigned int y_filter_table_index,
   unsigned int y_filter_data,
   unsigned int y_size
);

/**
@brief Sets a horizontal chroma scaling table.

Overrides the existing horizontal chroma coefficients for a given table.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@deprecated This API is deprecated due to security,  and memory access issues.
it has been replaced with \ref ismd_vidpproc_override_luma_filter_coeffcients_raw.

@param[in] dev vidpproc device handle
@param[in] uv_filter_table_index index of the table to be updated
@param[in] uv_filter_data a pointer to a buffer holding the new data.
@param[in] uv_size the size of the filter data buffer. checked but not used.

@see ismd_vidpproc_override_luma_filter_coeffcients_raw
*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_horizontal_filter_chroma_coefficients(
   ismd_dev_t dev,
   unsigned int uv_filter_table_index,
   unsigned int uv_filter_data,
   unsigned int uv_size
);

/**
@brief Sets a vertical chroma scaling table.

Overrides the existing vertical chroma coefficients for a given table.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@deprecated This API is deprecated due to security and memory access issues.
it has been replaced with \ref ismd_vidpproc_override_luma_filter_coeffcients_raw.

@param[in] dev vidpproc device handle
@param[in] uv_filter_table_index index of the table to be updated
@param[in] uv_filter_data a pointer to a buffer holding the new data.
@param[in] uv_size the size of the filter data buffer. checked but not used.

@see ismd_vidpproc_override_chroma_filter_coeffcients_raw
*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_vertical_filter_chroma_coefficients(
   ismd_dev_t dev,
   unsigned int uv_filter_table_index,
   unsigned int uv_filter_data,
   unsigned int uv_size
);
/**\}*/ // end of ingroup ismd_vidpproc_tables

/**
@brief Starts a series of scaling operations spaced over a fixed number of
frames.

Starts a series of scaling operations to scale a fixed part (or all) of
the input frame to a series of rectangles which may change in position (move)
or size (zoom) by fixed increments over a fixed number of frames.

The output rectangle does not need to fill the entire output frame, the
portion of the output not filled by the output window will be filled with
black.

The position of the portion of the input frame to process is provided as a
cropping rectangle in terms of the input frame.

The position of the data on the output frame is specified as two rectangles
representing the positions on the first and last frame, intermediate frames
are calculated as linear interpolations of these.

@note Scale-to-fit is the only scaling policy currently supported during
animated zoom operations.

@note after the last frame of the animated zoom operation vidpproc will
revert to normal scaling mode.

@note This operation takes place over a count of output frames it is up to
the application to select the desired count of frames to match the current
input format.

@param[in] dev vidpproc device handle
@param[in] linear_animated_zoom_start_flag Start flag is used to control
the start and end of one animated zoom. This flag must be set to TRUE if
you want to begin linear animated zoom.
@param[in] transition_frame_cnt Indicates the number of frame for the linear
animated be processed over e.g. 30 indicates that it will take 30 frames
from begin to end. this value is in output frames (when deinterlacing).

@param[in] src_x leftmost column of the source cropping rectangle in the input frame.
@param[in] src_y topmost row of the source cropping rectangle in the input frame.
@param[in] src_width width of the source cropping rectangle in the input frame.
@param[in] src_height height of the source cropping rectangle in the input frame.

@param[in] dest_start_x leftmost column of the starting destination rectangle in the output frame.
@param[in] dest_start_y topmost row of the starting destination rectangle in the output frame.
@param[in] dest_start_width width of the starting destination rectangle in the output frame.
@param[in] dest_start_height height of the starting destination rectangle in the output frame.

@param[in] dest_end_x leftmost column of the ending destination rectangle in the output frame.
@param[in] dest_end_y topmost row of the ending destination rectangle in the output frame.
@param[in] dest_end_width width of the ending destination rectangle in the output frame.
@param[in] dest_end_height height of the ending destination rectangle in the output frame.

@retval ISMD_SUCCESS The parameter was successfully got
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_disable_animated_zoom
@see ismd_vidpproc_set_animated_zoom
*/
ismd_result_t SMDEXPORT ismd_vidpproc_start_linear_animated_zoom(
   ismd_dev_t dev,
   bool linear_animated_zoom_start_flag,
   unsigned int transition_frame_cnt,
   unsigned int src_x,
   unsigned int src_y,
   unsigned int src_width,
   unsigned int src_height,
   unsigned int dest_start_x,
   unsigned int dest_start_y,
   unsigned int dest_start_width,
   unsigned int dest_start_height,
   unsigned int dest_end_x,
   unsigned int dest_end_y,
   unsigned int dest_end_width,
   unsigned int dest_end_height
);

/**
@brief Stops animated zoom operations.

Stops any general or linear animated zoom operations currently in progress, returning vidpproc
to normal scaling mode.

@param[in] dev vidpproc device handle

@retval ISMD_SUCCESS The parameter was successfully got
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_start_linear_animated_zoom
@see ismd_vidpproc_set_animated_zoom
*/
ismd_result_t SMDEXPORT ismd_vidpproc_disable_animated_zoom(ismd_dev_t dev);

/**
@brief Starts a general purpose animated zoom operation

Starts a general purpose animated zoom operation to scale a fixed part
(or all) of the input frame to a rectangle on the output frame. Repeated
calls to this API over time may be used to create a motion effect.

The output rectangle does not need to fill the entire output frame, the
portion of the output not filled by the output window will be filled with
black.

The position of the portion of the input frame to process is provided as a
cropping rectangle in terms of the input frame.

The position on the output frame to place the video data is provided as a
rectangle in terms of the output frame.

@note Scale-to-fit is the only scaling policy currently supported during
animated zoom operations.

@param[in] dev vidpproc device handle

@param[in] src_x leftmost column of the source cropping rectangle in the input frame.
@param[in] src_y topmost row of the source cropping rectangle in the input frame.
@param[in] src_width width of the source cropping rectangle in the input frame.
@param[in] src_height height of the source cropping rectangle in the input frame.

@param[in] dest_x leftmost column of the destination rectangle in the output frame.
@param[in] dest_y topmost row of the destination rectangle in the output frame.
@param[in] dest_width width of the destination rectangle in the output frame.
@param[in] dest_height height of the destination rectangle in the output frame.

@retval ISMD_SUCCESS The parameter was successfully got
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_start_linear_animated_zoom
@see ismd_vidpproc_disable_animated_zoom
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_animated_zoom(
   ismd_dev_t dev,
   unsigned int src_x,
   unsigned int src_y,
   unsigned int src_width,
   unsigned int src_height,

   unsigned int dest_x,
   unsigned int dest_y,
   unsigned int dest_width,
   unsigned int dest_height
);

/**
@brief Queries the driver for a list of open device handles.

Queries the driver for a list of open device handles.

@note the driver may not support as many contexts as can be reported by this
API.

@param[out] handle_info must point t a valid query result structure.
the structure will be populated with the results of the query.
@param[in] size_of_handle_info the size of the query info structure in bytes,
this is used to validate that the correct version of the API is being used.

@retval ISMD_SUCCESS The query has successfully run.
@retval other All other values are failures as reported by the return code

@see ismd_vidpproc_handle_query_result_t
*/
ismd_result_t SMDTRUSTED ismd_vidpproc_query_handle(ismd_vidpproc_handle_query_result_t* handle_info, unsigned int size_of_handle_info);

/**
@brief Gets a global event for the vidpproc driver.

Gets a global event for the vidpproc driver. This may be used to set the
Device Closed or Device Opened event.

@param[in] event_type operation event type.
@param[out] vidpproc_event vidpproc event set by the DPE

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_NULL_POINTER The vidpproc_event pointer is NULL.
@retval ISMD_ERROR_INVALID_PARAMETER The event_type parameter is invalid.
@retval other All other values are failures as reported by the return code

@see ismd_vidpproc_global_event_t
@see ismd_event_t
*/
ismd_result_t SMDTRUSTED ismd_vidpproc_get_global_event(
   ismd_vidpproc_global_event_t event_type,
   ismd_event_t *vidpproc_event
);

/**
@brief Sets the vertical scaling policy for a context.

Sets the vertical scaling policy for a context. The only supported
vertical scaling policies are normal and half pre-scaling.

Half pre-scaling is used to reduce the input bandwidth to vidpproc by dropping
every other line of the input, no filter is used which results in artifacts.

Half pre-scaling can only be used with progressive input, and is automatically
disabled when the input is interlaced.

The primary use case for half pre-scaling is to reduce bandwidth when receiving
data from a source that does not have a vertical pre-scaler.

@param[in] dev vidpproc device handle
@param[in] policy which vertical scaling policy to use

@retval ISMD_SUCCESS The deinterlacing policy was successfully set
@retval ISMD_ERROR_INVALID_HANDLE The device handle was not valid. Note
that this may indicate that handle was recently closed.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_vertical_scaling_policy_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_vertical_scaling_policy(
   ismd_dev_t dev,
   ismd_vidpproc_vertical_scaling_policy_t policy
);

/**
@brief Gets an event for a context.

Gets an event for a context.

@param[in] dev vidpproc device handle
@param[in] event_type operation event type.
@param[out] vidpproc_event vidpproc event set by the DPE

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_NULL_POINTER The vidpproc_event pointer is NULL.
@retval ISMD_ERROR_INVALID_PARAMETER The event_type parameter is invalid.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_event_t
@see ismd_event_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_event(
   ismd_dev_t dev,
   ismd_vidpproc_event_t event_type,
   ismd_event_t *vidpproc_event
);

/**
@brief Configures a high level driver mode.

Configures the driver mode to enable special high level operating modes
such as ADP.

@note This function can only be called by the application after opening the device handle
and before calling \ref ismd_dev_set_state for the first time.

@note ADP mode is a special low level access mode this should only be used by the Vidsink
component.

@param[in] dev vidpproc device handle
@param[in] mode the requested mode.
@retval ISMD_SUCCESS if function succeeds.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_vidpproc_mode_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_mode(ismd_dev_t dev, ismd_vidpproc_mode_t mode);

/**
@brief Sets the shared memory region to be used in ADP mode.

Sets the shared memory region to be used to communicate frame by frame data
in ADP mode.

This function can only be called after vidpproc device is set to be in the ADP mode.

@param[in] dev vidpproc device handle
@param[in] memory_region the buffer to be used for shared memory access.

@retval ISMD_SUCCESS if function succeeds.
@retval other All other values are failures as reported by the return code

@see ismd_dev_t
@see ismd_buffer_handle_t
*/
ismd_result_t SMDEXPORT ismd_vidpproc_set_shared_memory(ismd_dev_t dev, ismd_buffer_handle_t memory_region);


/** @ingroup ismd_vidpproc_tables */
/** @{ */

/**
@brief Sets a luma scaling table.

Sets a luma scaling table based on the index using the packed format for
storing table data.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@param[in] table_index the index of the table to be modified
@param[in] y_filter_data the new coefficients to be loaded

@retval ISMD_SUCCESS The coefficients were successfully set
@retval other All other values are failures as reported by the return code

*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_luma_filter_coeffcients_raw(
   int table_index,
   unsigned char y_filter_data[ISMD_VIDPPROC_Y_RAW_FILTER_BYTES]
);

/**
@brief Sets a chroma scaling table.

Sets a chroma scaling table based on the index using the packed format for
storing table data.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@param[in] table_index the index of the table to be modified
@param[in] uv_filter_data the new coefficients to be loaded

@retval ISMD_SUCCESS The coefficients were successfully set
@retval other All other values are failures as reported by the return code

*/
ismd_result_t SMDEXPORT ismd_vidpproc_override_chroma_filter_coeffcients_raw(
   int table_index,
   unsigned char uv_filter_data[ISMD_VIDPPROC_UV_RAW_FILTER_BYTES]
);

/**
@brief Resets a luma scaling table to default values.

Resets a luma scaling table based on the index to default values.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@param[in] table_index the index of the table to be modified

@retval ISMD_SUCCESS The coefficients were successfully reset
@retval other All other values are failures as reported by the return code

*/
ismd_result_t SMDEXPORT ismd_vidpproc_reset_luma_filter_coeffcients(int table_index);

/**
@brief Resets a chroma scaling table to default values.

Resets a chroma scaling table based on the index to default values.

@note this setting applies to all device contexts.

@note This API should only be called when all contexts are closed or stopped.

@note This API actually sets both horizontal and vertical tables simultaneously.

@param[in] table_index the index of the table to be modified

@retval ISMD_SUCCESS The coefficients were successfully reset
@retval other All other values are failures as reported by the return code

*/
ismd_result_t SMDEXPORT ismd_vidpproc_reset_chroma_filter_coeffcients(int table_index);

/**
@brief gets the current active region.

Gets the active region of the last field/frame queued for processing. The active region
is made up of:

The "Source" rectangle describes the rectangle from the input frame that will be
displayed. In most cases this is the input crop or pan scan rectangle, however in some
cases other cropping rectangles my override or further crop the input.

The "Destination" rectangle describes the rectangle where the input from the
"Source" is displayed on the output frame. The data may be shifted, or scaled.

Pixel Data is scaled from "Source" to "Destination" by scaling the pixel data in "Source"
independently and linearly, both horizontally and vertically, to fit in "Destination"

@note when anamorphic scaling is enabled, the horizontal scaling may not be linear.

@param[in] dev vidpproc device handle
@param[out] region a pointer to a buffer which will receive the current active
region description.

@retval ISMD_SUCCESS The coefficients were successfully reset
@retval other All other values are failures as reported by the return code

*/
ismd_result_t SMDEXPORT ismd_vidpproc_get_active_region(ismd_dev_t dev, ismd_video_scaled_region_t *region);


/**\}*/ // end of ingroup ismd_vidpproc_tables


/**\}*/ // end of ingroup ismd_vidpproc

#ifdef __cplusplus
}

#endif

#endif
