/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution
  in the file called LICENSE.GPL.

  Contact Information:

  Intel Corporation
  2200 Mission College Blvd.
  Santa Clara, CA  97052

  BSD LICENSE

  Copyright(c) 2007-2009 Intel Corporation. All rights reserved.
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

#ifndef __ISMD_VIDREND_H__
#define __ISMD_VIDREND_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_global_defs.h"

/** @weakgroup ismd_vidrend Video Rendering API/Structures

<H1>Video Rendering (vidrend) Module</H1>

The Video Renderer (also known as Video Timing Controller, VTC, or Vidrend)
takes uncompressed frame buffers containing either a single progressive frame
or a pair of interlaced fields as input and and outputs either directly to the
Display driver or outputs uncompressed frame buffers containing either a single
progressive frame or a pair of interlaced fields to a general purpose output
port.  At every Vertical Sync (\ref VSync) interrupt (representing a frame or
field) the renderer determines if the next field/frame in its internal queue
is ready for display. If so, it flips the frame or field to the display driver
and/or outputs the frame buffer to the output port.

<H2>I. Normal playback</H2>
-# Open the renderer.
-# Set the video plane.
-# Set the \ref Local_Clock for the renderer to use.
-# Set the \ref Base_Time of the stream.
-# Set the display mode.
-# Start the renderer.
Steps 2 thru 5 can be done in any order.


The \ref Base_Time, Segment Start (or Stop for negative rates), Segment Linear Start,
Each Frame's Presentation Time Stamp, the Play Rate (set either in the
segment or in vidrend) and the Timestamp of the \ref VSync are used to calculate
what frame to display.

The \ref Local_Clock provided to vidrend defines a time domain for matching input timestamps
to \ref VSync timestamps.

- The \ref VSync Time is read from the \ref Local_Clock.
- The Scaled Presentation Timestamp plus the \ref Base_Time must be in the domain of
the \ref Local_Clock.
- The Scaled Presentation Timestamp is the Linear Presentation Timestamp minus
the Segment Linear Start plus the Segment Scaled Start divided by the Play Rate
- The Segment Scaled Start is Scaled Presentation Timestamp at the end of the
prior segment.
- The Linear Presentation Timestamp is the Frame's Presentation Time Stamp
minus the Segment Start plus the Segment Linear Start

\ref Base_Time, presentation timestamps and current time are based off the same \ref Local_Clock
and the renderer is notified of this \ref Local_Clock in step 3 above.
The renderer start fails if the \ref Base_Time or a valid video plane is not set.

On stop, the renderer disables the video plane and releases all frame/field
buffers.
On close, all resources are deallocated and everything is reset to the initial
state.

<H2>II. Trick modes</H2>

<H3>Pause/Resume</H3>
-# Pause playback.
-# Set new \ref Base_Time (normally prior \ref Base_Time plus the duration of the pause).
-# Resume playback.

<H3>Frame advance/reverse</H3>

The video renderer provides APIs to support frame advance in both forward
and backward directions. It does this via the \ref ismd_vidrend_advance_to_pts
method. The video renderer expects the following programming sequence to
be followed.

-# If reverse frame advance is desired, put the system into reverse mode and
flush the renderer.
-# Pause playback. If \ref ismd_vidrend_advance_to_pts is called when the
video renderer is not paused, or not started, the operation will fail.
-# Query current linear time using \ref ismd_vidrend_get_stream_position
-# Call \ref ismd_vidrend_advance_to_pts with the \ref Linear_Time value to
jump to. Time is specified in 90 KHz clock ticks. The value is relative to the
current linear time.

Example:

Assume that \ref ismd_vidrend_get_stream_position returned 10000, and we had
a stream that was 30 FPS. To advance forward one frame, we'd call
\ref ismd_vidrend_advance_to_pts with the value 13000. To advance backwards
one frame (this requires the system to be in reverse playback mode), the
value 7000 would be specified.

-# The frame will then be flipped at the appropriate time specified in the
previous step. The video renderer will return to the paused state.
-# To advance to another frame, the application should repeat the process
outlined above starting at step 3.

@note In the case that the \ref Linear_Time value specified in
\ref ismd_vidrend_get_stream_position is < the current linear stream position
in forward playback (or > current linear position for reverse playback), an
error will be generated.

@note If \ref ismd_vidrend_advance_to_pts is called multiple times prior
to triggering the video frame flip, the value is overwritten and the last
value is used.

@note Transitioning between forward and reverse playback requires flushing
the video renderer prior to step 3. Other components must be configured
for the new direction appropriately.

-# To resume normal playback, the application should query the \ref Local_Clock
time using \ref ismd_clock_get_time, update both the video and audio
renderers \ref Base_Time (use \ref ismd_dev_set_stream_base_time), then
call \ref ismd_dev_set_state to the PLAY state. If the renderer is waiting to
advance, it will stop and immediately resume normal playback.

<H3>Other trick modes</H3>
-# Pause playback.
-# Flush the renderer.
-# Set new \ref Base_Time.
-# Resume playback.

<H2>III. Power Management</H2>
The Video Renderer does not support power management. As a software only driver
The Video Renderer runs exclusively on the IA core, it is event driven based on
input (normally from the Video Post-Processor) and \ref VSync timing (driven by the
display driver) without events from these sources The Video Renderer will remain
idle pending on events.

<H2>IV. Concepts</H2>
@section Local_Clock Local Clock
The clock instance provided to a vidrend context by the application.
Various relationships between this clock, the video source, clock
recovery, and the display driver are assumed to exist depending on use
case.

@section VSync VSync
The time in the source time domain when a Vertical Sync pulse occurred,
indicating a division between pictures (frames or fields) in the output
normally refers to the last VSync to have occurred. Each increment of a
VSync corresponds to one tick of a 90KHz clock.

@section PTS Presentation Timestamp
The time in the source time domain when a frame should be displayed. Each
Increment of a Presentation Timestamp corresponds to one tick of a 90KHz clock.

@section Orig_PTS Original Presentation Timestamp
A \ref PTS based on data from the input source rather than interpolated data.
For AVCap data all frames have valid Original Presentation Timestamps since
they are stamped based on the \ref Local_Clock, however for decoded data Original
Presentation Timestamps may arrive sparsely and erratically. Prior to the
first Original Presentation Timestamp in a segment the Presentation Timestamps
may be interpolated based on invalid values and so are normally ignored.

@section Base_Time Base Time
The time on the \ref Local_Clock when a frame with a
\ref Scaled_Time of zero would be displayed.

@section Base_Time_Offset Base Time Offset
The difference between the \ref Base_Time and the current time at the moment
when the \ref Base_Time value is set. This represents the length of the pipeline
in terms of how long it takes for a frame to move from one end to the other.
Increasing the \ref Base_Time Offset adds buffering at the cost of latency and
increased memory usage.

@note \ref Base_Time Offset cannot be directly set, it is a factor that is added to
the \ref Base_Time value set by the application.

@f{eqnarray*}
Base Time Offset &=& Base Time - Now
@f}

@section Play_Rate Play Rate
A fraction describing how much faster or than normal speed media should be
played Higher values indicate faster playback. This value acts as a divisor
when converting the the scaled time domain.

@section Start_Time Start Time
Indicates the first \ref PTS in a segment to be displayed.
This is the time that will align to the \ref Linear_Start_Time, if the
Start_Time does not align to the first "good" \ref PTS in
a segment it will affect the quality of playback. For negative rates this is
optional and is used as the \ref Stop_Time. For positive rates this value is
used must be valid.

@section Stop_Time Stop Time
Indicates the last \ref PTS in a segment to be displayed.
For positive rates this is optional and is used as the \ref Stop_Time. For
negative rates this value is used must be valid.

@section Linear_Start_Time Linear Start Time
The time in the Linear time domain matching the \ref Start_Time in the source
time domain for a segment. It is expected for the last linear time of one
segment be align to the Linear_Start_Time of the next segment.

@section Linear_Time Linear Time
The time in the linear domain matching the \ref PTS.

@f{eqnarray*}
Linear Time &=& (Presentation Timestamp - Start Time) + Linear Start Time
@f}

@section Scaled_Start_Time Scaled Start Time
The time in the Scaled time domain matching the \ref Start_Time in the source
time domain for a segment. This value is based on the Linear and Scaled Start
Times for the prior segment. The reliance on the prior Scaled Start Time creates
a feedback loop that allows adjustments from all prior segments to accumulate.

@f{eqnarray*}
Scaled Start Time &=& \frac{Linear Start Time - Prior Linear Start Time}{Prior Play Rate} + Prior Scaled Start Time
@f}

@section Scaled_Time Scaled Time
The time in the scaled domain matching the \ref PTS.

@f{eqnarray*}
Scaled Time &=& \frac{Linear Time - Linear Start Time}{Play Rate} + Scaled Start Time \\
            &=& \frac{Presentation Timestamp - Start Time}{Play Rate} + Scaled Start Time
@f}

@section Render_Time Render Time
The time in the domain of the \ref Local_Clock matching the \ref PTS.

@f{eqnarray*}
Render Time &=& Scaled Time + Base Time \\
            &=& \frac{Linear Time - Linear Start Time}{Play Rate} + Scaled Start Time + Base Time \\
            &=& \frac{Presentation Timestamp - Start Time}{Play Rate} + Scaled Start Time + Base Time
@f}

<H2>V. End of Video Display Policies (Stop/Flush/Mute/etc.)</H2>
There are several policies that can be set to handle various "end of video"
conditions. These are the general options that these policies make available.
Specific policies may support only a subset of these options, please check the
policy specific documentation for the options available.

@note Calling code should not make assumptions vidrend will do with a display
plane  while it is owned by vidrend. If Calling code needs to directly
interact with a display plane it should dissociate it from vidrend first.

@par Clear Display Plane
This option clears the display plane allowing data in lower z-order planes to
be seen and allows the last frame displayed be released.

@par Show Black
This option fills the display plane with black and allows the last frame
displayed be released.

@par Keep Last Frame
This option allows the last frame displayed to remain on screen (effectively
freezing the video. This may be accomplished in several ways, in some cases
frames may not be re-flipped to the display driver, in other cases the same
frame may be re-flipped to the display driver periodically. The method used
may differ depending on how vidrend reached this state and on the current
implementation of vidrend. Calling code should not make assumptions about
what mode is used or in general what vidrend will do with a display plane
while it is owned by vidrend.

<H2>VI. Pre-Rolling</H2>
Pre-Rolling is the process of filling the pipeline with data before actually
displaying any data to the user. (it is named for pre-rolling film between
reels in movie projection)

To pre-roll video the applications should:
(assuming vidrend is starting in the Stopped state)
- ensure that the vidrend internal queues are empty (by flushing)
- set the new segment policy to strict (so that only in segment frames are
queued)
- register and listen for the Start of Segment event (SOSEG)
- place vidrend in the paused state.
- place the rest of the pipeline in either the pause or play state.

When the Start of Segment  event is triggered video is pre-rolled, normally
an application will wait for both audio and video to pre-roll and then place
the pipe into the Play state.

<H2>VI. 3D</H2>
Vidrend supports several Stereoscopic 3D modes.

For all Stereoscopic 3D modes two vidrend contexts are needed to receive the
two 2D views representing the left and right eye data.

The two contexts are linked together using the \ref ismd_vidrend_link_views
API which establishes a base/dependent relationship between them.

The 3D Output policy set with \ref ismd_vidrend_set_3D_output_policy and the
3D Drop policies set with \ref ismd_vidrend_set_3D_drop_policy provide
general control over how the Stereoscopic 3D data is displayed.

@warning In the normal 3D mode selected frames must have matching \ref PTS values
this means that 3D video is particularly susceptible to issues from frames
arriving late.

There are two general classes of Stereoscopic modes available in the display driver:

<h3>Two Plane modes</h3>
Two UPP modes have names ending in "_2" and require two separate UPPs to be used.

For these modes the base and dependent contexts must both have separate planes
assigned to them, and vidrend will flip data for both the left and right view
on each \ref VSync.

In this mode setting the angle of the view represented by each context using
\ref ismd_vidrend_set_angle is permitted but not required. the actual angle is
determined by the plane.

<h3>One Plane modes</h3>
One UPP modes names do not end in "_2" and require only one UPP to be used.

For these modes the base view MUST be the only view with a valid plane
assigned to it, vidrend will alternate flipping data for the left and right
views on each \ref VSync.

@note it may take up to 3 VSyncs before vidrend identifies this mode, during
this time output will be either 2D or correct 3D depending on startup
conditions.

In this mode setting the angle of the view represented by each context using
\ref ismd_vidrend_set_angle is required.

*/

/** @ingroup ismd_vidrend */
/** @{ */

/**
@brief A total of 16 renderers can be initialized in the system at a time.
*/
#define NUM_OF_RENDERERS 16

/**
@brief Frame type mask

A bitmask where each bit represents a mask fr a value from
\ref ismd_frame_type_t.

- A zero value mask specifies the default value and allows for all frame
types to be candidates to be displayed by vidrend.

- A mask of value (ismd_frame_type_t)(-1) (all ones) prevents frame
types from being candidates to be displayed by vidrend.

@see ismd_vidrend_set_frame_mask
@see ismd_frame_type_t
*/
typedef uint32_t ismd_vidrend_frame_type_mask_t;

/**
@brief Defines available behaviors when vidrend is flushed.
*/
typedef enum ismd_vidrend_flush_policy_t{
   /**
   Invalid flush policy
   */
   ISMD_VIDREND_FLUSH_POLICY_INVALID,

   /**
   Keep last frame on screen.
   */
   ISMD_VIDREND_FLUSH_POLICY_REPEAT_FRAME,

   /**
   Display black frame
   */
   ISMD_VIDREND_FLUSH_POLICY_DISPLAY_BLACK,

   /**
   count of policies
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_FLUSH_POLICY_COUNT
} ismd_vidrend_flush_policy_t;

/**
@brief Defines possible types of \ref VSync to receive from the display
*/
typedef enum ismd_vidrend_vsync_type_t{
   /**
   Progressive Frame \ref VSync
   */
   ISMD_VIDREND_VSYNC_TYPE_FRAME,

   /**
   Top Field \ref VSync
   */
   ISMD_VIDREND_VSYNC_TYPE_FIELD_TOP,

   /**
   Bottom Field \ref VSync
   */
   ISMD_VIDREND_VSYNC_TYPE_FIELD_BOTTOM,

   /**
   count of VSync types
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_VSYNC_TYPE_COUNT
} ismd_vidrend_vsync_type_t;

/**
@brief Defines the device context specific events available in vidrend.
*/
typedef enum ismd_vidrend_event_type_t{
   /**
   An error occurred in vidrend some possible errors include:
   - skipped \ref VSync
   - late flip
   - late frames
   - out of order frames.

   Retrieving \ref ismd_vidrend_stats_t with \ref ismd_vidrend_get_stats may
   help to identify the issue.
   */
   ISMD_VIDREND_EVENT_TYPE_ERROR,

   /**
   Progressive Frame \ref VSync interrupt received.
   */
   ISMD_VIDREND_EVENT_TYPE_VSYNC_FRAME,

   /**
   Top Field \ref VSync interrupt received.
   */
   ISMD_VIDREND_EVENT_TYPE_VSYNC_FIELD_TOP,

   /**
   Bottom Field \ref VSync interrupt received.
   */
   ISMD_VIDREND_EVENT_TYPE_VSYNC_FIELD_BOTTOM,

   /**
   The frame just flipped to the display has a different resolution from the
   frame currently being displayed.

   Examine the curr_frame_* and next_frame_* values \ref ismd_vidrend_status_t
   from \ref ismd_vidrend_get_status to identify the actual values.
   */
   ISMD_VIDREND_EVENT_TYPE_RES_CHG,

   /**
   An end of stream tag was encountered
   */
   ISMD_VIDREND_EVENT_TYPE_EOS,

   /**
   An client ID tag was encountered
   */
   ISMD_VIDREND_EVENT_TYPE_CLIENT_ID_SEEN,

   /**
   A frame with a \ref PTS after the \ref Stop_Time was found
   */
   ISMD_VIDREND_EVENT_TYPE_EOSEG,

   /**
   A significant number (16) of late frames arrived. A late frame is a frame
   that arrives at the input of vidrend after its render time has already
   passed. This indicates insufficient buffering and that the
   \ref Base_Time_Offset should be increased.
   */
   ISMD_VIDREND_EVENT_TYPE_UNDERRUN,

   /**
   The first frame with a \ref PTS after the \ref Start_Time
   was found on the input and queued for display.

   @note as long as there is space in the internal queue input can be read
   even when in the Paused state which can cause this event to fire, providing
   feedback for pre-rolling features.
   */
   ISMD_VIDREND_EVENT_TYPE_SOSEG,

   /**
   A new frame or field was flipped to the display.
   */
   ISMD_VIDREND_EVENT_TYPE_FRAME_FLIPPED,

   /**
   The input was unexpectedly empty and no frames are in the internal queue.
   This will normally mean that frames are not being sent to vidrend or
   that there is insufficient buffering and that the \ref Base_Time_Offset
   should be increased.
   */
   ISMD_VIDREND_EVENT_TYPE_UNDERFLOW,

   /**
   Vidrend has recovered from the underflow condition (i.e frames have arrived)
   */
   ISMD_VIDREND_EVENT_TYPE_UNDERFLOW_RECOVERED,

   /**
   A count of supported events.
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_EVENT_COUNT
} ismd_vidrend_event_type_t;

/**
@brief Refresh rate for interlaced display.

@note this is not used in any functional paths
*/
typedef enum ismd_vidrend_interlaced_rate_t{
   ISMD_VIDREND_INTERLACED_RATE_INVALID,
   ISMD_VIDREND_INTERLACED_RATE_50,
   ISMD_VIDREND_INTERLACED_RATE_59_94,
} ismd_vidrend_interlaced_rate_t;

/**
@brief Defines available behaviors when vidrend is stopped.
*/
typedef enum ismd_vidrend_stop_policy_t{
   /**
   Invalid stop policy
   */
   ISMD_VIDREND_STOP_POLICY_INVALID,

   /**
   Clear the display plane
   */
   ISMD_VIDREND_STOP_POLICY_CLOSE_VIDEO_PLANE,

   /**
   Keep last frame on screen.
   */
   ISMD_VIDREND_STOP_POLICY_KEEP_VIDEO_PLANE,

   /**
   Display black frame
   */
   ISMD_VIDREND_STOP_POLICY_DISPLAY_BLACK,

   /**
   count of policies
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_STOP_POLICY_COUNT
} ismd_vidrend_stop_policy_t;

/**
@brief Defines available behaviors when vidrend is muted.
*/
typedef enum ismd_vidrend_mute_policy_t{
   /**
   Not muted, normal playback
   */
   ISMD_VIDREND_MUTE_NONE = 0,

   /**
   Display black frame
   */
   ISMD_VIDREND_MUTE_DISPLAY_BLACK_FRAME,

   /**
   Keep last frame on screen.
   */
   ISMD_VIDREND_MUTE_HOLD_LAST_FRAME,

   /**
   count of policies
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_MUTE_POLICY_COUNT

} ismd_vidrend_mute_policy_t;

/**
@brief message type for MIB management.
*/
typedef enum ismd_vidrend_message_t{
   /**
   The \ref PTS of a frame is out of segment.
   The frame will be dropped.
   */
   ISMD_VIDREND_MESSAGE_OUT_OF_SEGMENT = 0x0,

   /**
   The Timestamp of a frame is earlier than the prior frame.
   The frame will be dropped.
   */
   ISMD_VIDREND_MESSAGE_OUT_OF_ORDER = 0x1,
} ismd_vidrend_message_t;

/**
@brief Angle of a video view/stream
*/
typedef enum ismd_vidrend_video_angle_t {

   /**
   invalid angle
   */
   VIDEO_ANGLE_NONE = 0,

   /**
   2D video, no inherent angle
   */
   VIDEO_ANGLE_2D,

   /**
   3D video, left eye view
   */
   VIDEO_ANGLE_LEFT_EYE,

   /**
   3D video, right eye view
   */
   VIDEO_ANGLE_RIGHT_EYE,

   /**
   count of angles
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   VIDEO_ANGLE_COUNT,

   /**
   @Deprecated Please use VIDEO_ANGLE_COUNT
   */
   MAX_VIDEO_ANGLE
} ismd_vidrend_video_angle_t;

/**
@brief Output policy for normal 3D playback.
*/
typedef enum ismd_vidrend_3D_output_policy_t {

   /**
   No Policy, invalid
   */
   OUTPUT_3D_POLICY_NONE = 0,

   /**
   Output Base and Dependent frames for 3D effect
   */
   OUTPUT_3D_POLICY_BASE_AND_DEPENDENT,

   /**
   Output Base frames on all interfaces for 2D effect
   */
   OUTPUT_3D_POLICY_BASE_ONLY,

   /**
   Output Base and Dependent frames without checking for matching \ref PTS
   values (approximates unlinked behavior)
   */
   OUTPUT_3D_POLICY_INDEPENDENT,

   /**
   count of policies. 
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   OUTPUT_3D_POLICY_COUNT, 

   /**
   @Deprecated Please use OUTPUT_3D_POLICY_COUNT
   */
   MAX_BASE_OUTPUT_3D_POLICY = OUTPUT_3D_POLICY_COUNT
} ismd_vidrend_3D_output_policy_t;

/**
@brief Error policy for missing base view frame in 3D playback
*/
typedef enum ismd_vidrend_3D_base_drop_policy_t {

   /**
   No Policy, invalid
   */
   BASE_DROP_POLICY_NONE = 0,

   /**
   Do not flip the base or dependent streams when a
   Frame is dropped on the base, the effect is the freeze the video
   */
   BASE_DROP_POLICY_SKIP_ALL_FLIPS,

   /**
   Use a dependent frame if the base is missing selection of what
   dependent to use is up to the driver
   */
   BASE_DROP_POLICY_USE_DEP,

   /**
   count of policies. 
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   BASE_DROP_POLICY_COUNT,

   /**
   @Deprecated Please use BASE_DROP_POLICY_COUNT
   */
   MAX_BASE_DROP_POLICY = BASE_DROP_POLICY_COUNT

} ismd_vidrend_3D_base_drop_policy_t;

/**
@brief Error policy for missing dependent view frame in 3D playback
*/
typedef enum ismd_vidrend_3D_dependent_drop_policy_t {

   /**
   No Policy, invalid
   */
   DEPENDENT_DROP_POLICY_NONE = 0,

   /**
   Do not flip the base or dependent streams when a
   Frame is dropped on the base, the effect is the freeze the video
   */
   DEPENDENT_DROP_POLICY_SKIP_ALL_FLIPS,

   /**
   use a base frame if the dependent is missing
   */
   DEPENDENT_DROP_POLICY_USE_BASE,

   /**
   count of policies. 
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   DEPENDENT_DROP_POLICY_COUNT, 

   /**
   @Deprecated Please use DEPENDENT_DROP_POLICY_COUNT
   */
   MAX_DEPENDENT_DROP_POLICY = DEPENDENT_DROP_POLICY_COUNT

} ismd_vidrend_3D_dependent_drop_policy_t;

/**
@brief Defines a policy to specify the frame at which vidrend should
begin processing within a segment.
*/
typedef enum ismd_vidrend_segment_start_policy_t {

   /**
   This is the default policy for vidrend. It specifies that processing
   should start on the first frame with a valid original Timestamp.
   This is the recommended setting for the majority of use cases
   */
   ISMD_VIDREND_START_SEGMENT_ON_FIRST_STABLE_TIME_STAMP = 0,
   /**
   This policy specifies that processing should start on the first available
   frame. This may result in a large jump in Timestamp values which can
   appear as artifacts such as a video freeze.
   @Note The policy has been added to comply with the DVD conformance tests.
   */
   ISMD_VIDREND_START_SEGMENT_ON_FIRST_TIME_STAMP,

   /**
   count of policies. 
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_START_SEGMENT_POLICY_COUNT
}ismd_vidrend_segment_start_policy_t;

/**
@brief Defines a policy to specify what latency reduction algorithm(s).
to use.
*/
typedef enum ismd_vidrend_latancy_policy_t {

   /**
   This is the default policy for vidrend. It will always be the lowest latency 
   that behaves optimally in all cases
   */
   ISMD_VIDREND_NORMAL_LATENCY = 0,

   /**
   This policy specifies that Vidrend should reduce latency as much as possible.
   In some (transient) corner cases this may result in sub optimal behavior 
   such as repeating a frame more times that optimal. These are generally
   theoretical cases that correspond to system wide state changes (such as output 
   format change) that would have significantly higher impact on the user experience 
   than the sub-optimal behavior of vidrend.

   This is expected to be used as part of a system wide low latency configuration (game mode)
   that also includes changing to base time offset.
   */
   ISMD_VIDREND_LOW_LATENCY,

   /**
   count of policies. 
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_LATENCY_POLICY_COUNT
}ismd_vidrend_latancy_policy_t;


/**
@brief Defines the policies available to be set in vidrend

\see ismd_vidrend_set_policy
*/
typedef enum ismd_vidrend_policy_t {

   /**
   Policy to set the behavior of vidrend when stopped.

   \see ismd_vidrend_stop_policy_t
   */
   ISMD_VIDREND_STOP_POLICY = 0,
   /**
   Policy to set the behavior of vidrend when muted

   \see ismd_vidrend_mute_policy_t
   */
   ISMD_VIDREND_MUTE_POLICY,
   /**
   Policy to set the behavior of vidrend when flushed

   \see ismd_vidrend_flush_policy_t
   */
   ISMD_VIDREND_FLUSH_POLICY,
   /**
   Policy to set the output behavior of vidrend when displaying 3D

   \see ismd_vidrend_3D_output_policy_t
   */
   ISMD_VIDREND_3D_OUTPUT_POLICY,
   /**
   Policy to set the behavior of vidrend when the base view does
   cannot display the corresponding frame

   \see ismd_vidrend_3D_base_drop_policy_t
   */
   ISMD_VIDREND_3D_BASE_DROP_POLICY,
   /**
   Policy to set the behavior of vidrend when the dep view does
   cannot display the corresponding frame

   \see ismd_vidrend_3D_dep_drop_policy_t
   */
   ISMD_VIDREND_3D_DEP_DROP_POLICY,
   /**
   Policy to specify the frame at which vidrend should begin
   processing within a segment.

   \see ismd_vidrend_segment_start_policy_t
   */
   ISMD_VIDREND_SEGMENT_START_POLICY,

   /**
   Policy to specify what latency reduction should be used.

   \see ismd_vidrend_latancy_policy_t
   */
   ISMD_VIDREND_LATENCY_POLICY,

   /**
   Count of vidrend policies
   
   @Note Not a valid value, for internal use and loop/array size tracking
   */
   ISMD_VIDREND_POLICY_COUNT
}ismd_vidrend_policy_t;

/**
@brief stream position information.
*/
typedef struct ismd_vidrend_stream_position_info_t{

   /**
   @brief Current \ref Base_Time set in the renderer. This should reflect the last
   \ref Base_Time set by the application.
   */
   ismd_time_t base_time;

   /**
   @brief Current Time on the \ref Local_Clock.
   */
   ismd_time_t current_time;

   /**
   @brief \ref PTS of the last frame processed.

   @note This is the last frame evaluated to see if it should be flipped,
   this may not be the last frame flipped.
   */
   ismd_pts_t segment_time;

   /**
   @brief \ref Linear_Time of the last frame processed.
   */
   ismd_pts_t linear_time;

   /**
   @brief \ref Scaled_Time of the last frame processed.
   */
   ismd_pts_t scaled_time;

   /**
   @brief First \ref Orig_PTS found in the current segment.

   @note A value of ISMD_NO_PTS implies that this is is not yet available.
   @note This may not be the \ref Start_Time
   */
   ismd_pts_t first_segment_pts;

   /**
   @brief Last \ref Orig_PTS processed.

   @note A value of ISMD_NO_PTS implies that this is is not yet available.
   @note the least significant bit of this value may be truncated in the pipeline.
   */
   ismd_pts_t last_segment_pts;

   /**
   @brief \ref Linear_Time of the last \ref Orig_PTS processed.

   @note If "last_segment_pts" is ISMD_NO_PTS, this value is undefined.
   */
   ismd_pts_t linear_of_last_segment_pts;

   /**
   @brief \ref Linear_Time of the last \ref PTS processed.
   */
   ismd_pts_t last_linear_pts;

   /**
   @brief \ref Linear_Time of the \ref PTS of the next buffer that MAY be flipped to
   the display.
   */
   ismd_pts_t next_linear_pts;

   /**
   @brief Last \ref Orig_PTS processed.

   @deprecated Replaced by \ref ismd_vidrend_stream_position_info_t::last_segment_pts
   */
   ismd_pts_t last_orig_pts;

   /**
   @brief \ref Linear_Time of the last \ref Orig_PTS processed.

   @deprecated Replaced by \ref ismd_vidrend_stream_position_info_t::linear_of_last_segment_pts
   */
   ismd_pts_t local_of_last_orig_pts;

   /**
   @brief \ref Linear_Time of the last \ref PTS processed.

   @deprecated Replaced by \ref ismd_vidrend_stream_position_info_t::last_linear_pts
   */
   ismd_pts_t current_local_pts;

   /**
   @brief \ref Linear_Time of the \ref PTS of the next buffer that MAY be flipped to
   the display.

   @deprecated Replaced by \ref ismd_vidrend_stream_position_info_t::next_linear_pts
   */
   ismd_pts_t next_local_pts;

   /**
   @brief The time according to the \ref Local_Clock when the last frame was flipped.
   */
   ismd_pts_t flip_time;

   /**
   @brief Current stream position between zero and the duration of the clip.

   ISMD_NO_PTS will be returned if the driver does not have enough information
   to calculate this field.

   @note This is the \ref Linear_Time of either the last \ref PTS or the last
   \ref Orig_PTS depending on a number of factors.
   */
   ismd_pts_t stream_position;

} ismd_vidrend_stream_position_info_t;

/**
@brief renderer statistics
*/
typedef struct ismd_vidrend_stats_t{
   /**
   @brief Number of frame vsyncs since start
   */
   unsigned int vsyncs_frame_received;

   /**
   @brief Number of frame vsyncs skipped
   */
   unsigned int vsyncs_frame_skipped;

   /**
   @brief Number of top field vsyncs since start
   */
   unsigned int vsyncs_top_received;

   /**
   @brief Number of top field vsyncs skipped
   */
   unsigned int vsyncs_top_skipped;

   /**
   @brief Number of bottom field vsyncs since start
   */
   unsigned int vsyncs_bottom_received;

   /**
   @brief Number of bottom field vsyncs skipped
   */
   unsigned int vsyncs_bottom_skipped;

   /**
   @brief Number of frames fed into the renderer
   */
   unsigned int frames_input;

   /**
   @brief Number of frames (progressive) /fields (interlaced) sent to display
   */
   unsigned int frames_displayed;

   /**
   @brief Number of frames released (including both dropped and displayed frames)
   */
   unsigned int frames_released;

   /**
   @brief Number of frames drops
   */
   unsigned int frames_dropped;

   /**
   @brief Number of frames (progressive) /fields (interlaced) contiguous drops (Maximum)
   */
   unsigned int max_contiguous_frame_drop;

   /**
   @brief Number of frames (progressive) /fields (interlaced) repeats
   */
   unsigned int frames_repeated;

   /**
   @brief Number of frames (progressive) /fields (interlaced) contiguous repeats (Maximum)
   */
   unsigned int max_contiguous_frame_repeats;

   /**
   @brief Number of frames that are late
   */
   unsigned int frames_late;

   /**
   @brief Number of frames that are out of order
   */
   unsigned int frames_out_of_order;

   /**
   @brief Number of frames that are out of segment range
   */
   unsigned int frames_out_of_segment;

   /**
   @brief Number of flipped frames that are late
   */
   unsigned int late_flips;
} ismd_vidrend_stats_t;

/**
@brief renderer status
*/
typedef struct ismd_vidrend_status_t{
   /**
   @brief Difference in the \ref PTS "Presentation Timestamps" of consecutive
   frames that are not out of order

   @note as with all Presentation Timestamps this value is in 90 KHz clock ticks.
   */
   unsigned int content_pts_interval;

   /**
   @brief Frame time of the display. For interlaced display this time is the
   sum of its field times (i.e. for 480i video with 1501.5 field time the frame time
   is 3003) In 90KHz clock ticks.

   @note as with Presentation Timestamps this value is in 90 KHz clock ticks.
   */
   unsigned int display_frame_time;

   /**
   @brief Difference between the predicted time of the next display interrupt and
   the (\ref Base_Time + presentation timestamp of the frame chosen for display)
   */
   int pts_phase;

   /**
   @brief Last Client ID seen by the renderer
   */
   int client_id_last_seen;

   /**
   @brief Width of frame currently on display
   */
   unsigned int curr_frame_width;

   /**
   @brief Height of frame currently on display
   */
   unsigned int curr_frame_height;

   /**
   @brief Width of last frame flipped (next frame to be displayed).
   */
   unsigned int next_frame_width;

   /**
   @brief Height of last frame flipped (next frame to be displayed).
   */
   unsigned int next_frame_height;
} ismd_vidrend_status_t;

/**
@brief Open a vidrend device context.

Opens a new vidrend device. This should be called before
any other vidrend functions are called. If a device is successfully
opened it should be closed when the application is done using it.

If a vidrend instance is not successfully opened the handle is in an undefined
state and should not be passed to other API functions, including close.

@param[out] vidrend handle to the allocated instance. This handle will
be used to access the video renderer for subsequent
operations.

@retval ISMD_SUCCESS The instance is successfully allocated.
@retval ISMD_ERROR_NULL_POINTER The handle pointer is NULL.
@retval ISMD_ERROR_NO_RESOURCES No free instance of renderer is available.
@retval ISMD_ERROR_OPERATION_FAILED Unrecoverable internal error occurred
during resource allocation.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_open(ismd_dev_t *vidrend);

/**
@brief Gets the input port handle for a context.

Gets the input port handle for a context. The input port is used to send
frames into vidrend. The vidrend driver uses events from this port internally
devices sending frames into vidrend should create an output port to connect to
this input port.

@param[in] vidrend vidrend device handle
@param[out] port handle to the allocated input port.

@retval ISMD_SUCCESS The port handle is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The port handle pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_input_port(ismd_dev_t         vidrend,
                                          ismd_port_handle_t *port);

/**
@brief Sets the display plane used by the renderer to send frames to.

Sets the video plane that receives the frames/fields pushed by the renderer.

Setting this value to the invalid plane (0) will dissociate the vidrend
context from any current planes and cause it to not flip frames directly
to the display (in this case the output port may still be used to read frames)

The user is responsible for setting a valid unused plane id. The renderer
does not validate this.

@warning This API should only be called when the context is in the Stopped
state. In other states calling this API may result in undesirable side effects.

@note The plane provided must be a Universal Pixel Plane (UPP) from the
display driver which is not in use by other devices.

@param[in] vidrend vidrend device handle
@param[in] video_plane_id the desired video plane. (a UPP defined in gdl_types.h)

@retval ISMD_SUCCESS The plane id is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_video_plane(ismd_dev_t   vidrend,
                                           unsigned int video_plane_id);

/**
@brief Gets the video plane used by the renderer.

@param[in] vidrend vidrend device handle
@param[out] video_plane_id plane set in the renderer.

@retval ISMD_SUCCESS The plane is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The plane pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_video_plane(ismd_dev_t   vidrend,
                                           unsigned int *video_plane_id);

/**
@brief Sets the video pipe to used by the renderer.

Pipe A is used by default.

@warning Each video pipe my have a different display rate and polarity so
setting the wrong pipe will result in undesirable artifacts.

@warning The user is responsible for setting the correct display pipe id to match the
\ref Local_Clock and UPP provided. The renderer may not validate this.

@param[in] vidrend vidrend device handle
@param[in] video_pipe_id the desired video display pipe. (a display pipe defined in gdl_types.h)

@retval ISMD_SUCCESS The display pipe id is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_video_pipe(ismd_dev_t   vidrend,
                                           int video_pipe_id);

/**
@brief Gets the video display pipe used by the renderer.

@param[in] vidrend vidrend device handle
@param[out] video_pipe_id pipe set in the renderer.

@retval ISMD_SUCCESS The pipe is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The pipe pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_video_pipe(ismd_dev_t   vidrend,
                                           int *video_pipe_id);


/**
@brief Sets the refresh rate for interlaced display.

@note this value is not used in any functional paths

@param[in] rate refresh rate of the display.

@retval ISMD_SUCCESS The refresh rate is successfully set.
@retval ISMD_ERROR_INVALID_PARAMETER Invalid refresh rate.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_interlaced_display_rate(
                                         ismd_vidrend_interlaced_rate_t rate);

/**
@brief Gets the refresh rate for interlaced display.

@note this value is not used in any functional paths

@param[out] rate refresh rate set in the renderer.

@retval ISMD_SUCCESS The refresh rate is successfully returned.
@retval ISMD_ERROR_NULL_POINTER The rate pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_interlaced_display_rate(
                                       ismd_vidrend_interlaced_rate_t *rate);

/**
@brief Enables output port support for the renderer instance.

When this API is called an output port is created for the context. After each
\ref VSync any frame that was selected to be flipped to the display driver will be
written to the output port. Note that if the application does not read from
the port in a timely manor timing will be off and there is an opportunity to
drop frames on the port write.

@note Output port depth is the number of frames to be queued in the port. It
cannot be less than 0.

@param[in] vidrend vidrend device handle
@param[in] time_offset not supported
@param[in] port_depth depth of the output port.
@param[out] output_port output port handle for this instance.

@retval ISMD_SUCCESS The output port handle successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER The time_offset or port_depth is invalid.
@retval ISMD_ERROR_NULL_POINTER The output_port pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Enable output port operation failed.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_enable_port_output(ismd_dev_t vidrend,
                                              ismd_time_t time_offset,
                                              int port_depth,
                                              ismd_port_handle_t *output_port);

/**
@brief Disables output port support for the renderer context.

@note When this API is called the output port is deallocated.

@param[in] vidrend vidrend device handle

@retval ISMD_SUCCESS The output port is disabled successfully.
@retval ISMD_ERROR_HANDLE_INVALID The renderer handle is invalid.
@retval ISMD_ERROR_OPERATION_FAILED Disable output port operation failed.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_disable_port_output(ismd_dev_t vidrend);

/**
@brief Gets the output port for the given renderer instance.

@note Port output must be enabled.

Video buffer may be read form this port for further processing such as
for use as video as texture by the graphics engine.

@param[in] vidrend vidrend device handle
@param[out] port handle to the allocated output port.

@retval ISMD_SUCCESS The port handle is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The port handle pointer is NULL.
@retval ISMD_ERROR_INVALID_REQUEST The output port is not enabled.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_output_port(ismd_dev_t         vidrend,
                                           ismd_port_handle_t *port);

/**
@brief Gets the \ref Base_Time last used by the renderer.

Returns the last \ref Base_Time value submitted by the application to
the context.

@param[in] vidrend vidrend device handle
@param[out] basetime \ref Base_Time set in the renderer.

@retval ISMD_SUCCESS The \ref Base_Time is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The \ref Base_Time pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_base_time(ismd_dev_t  vidrend,
                                         ismd_time_t *basetime);

/**
@brief Mutes the video for one context.

The renderer continues its operations but no new frames/fields are sent
to the display. If the flag is true, a black frame/field is displayed. If
the flag is false, the renderer sends new frames/fields to the display. This
operation is invalid if the renderer is not started.

@deprecated Replaced by \ref ismd_vidrend_mute

@param[in] vidrend vidrend device handle
@param[in] flag flag to indicate if video is to be muted or not.

@retval ISMD_SUCCESS The operation is successfully completed.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST The renderer handle is not running.
@retval ISMD_ERROR_OPERATION_FAILED Internal operations failed.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_mute_video(ismd_dev_t vidrend,
                                      bool       flag);

/**
@brief Sets the behavior of the context when flushed.

Possible policies are:

- \ref ISMD_VIDREND_FLUSH_POLICY_DISPLAY_BLACK : a black frame/field is displayed until
flush completes and video data starts flowing through the renderer again.
- \ref ISMD_VIDREND_FLUSH_POLICY_REPEAT_FRAME : the last frame/field sent to the display is
maintained till new video data starts flowing through the renderer.

The default flush policy is \ref ISMD_VIDREND_FLUSH_POLICY_REPEAT_FRAME.

@param[in] vidrend vidrend device handle
@param[in] flush_policy the policy to set in the renderer.

@retval ISMD_SUCCESS The flush behavior is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER Invalid flush policy.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_flush_policy(ismd_dev_t          vidrend,
                                    ismd_vidrend_flush_policy_t flush_policy);

/**
@brief Gets the current flush policy for a context.

@param[in] vidrend vidrend device handle
@param[out] flush_policy flush policy in instance.

@retval ISMD_SUCCESS The policy is obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The policy pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_flush_policy(ismd_dev_t         vidrend,
                                   ismd_vidrend_flush_policy_t *flush_policy);

/**
@brief Enables fixed frame rate mode.

In fixed frame rate mode the embedded \ref PTS of each frame is discarded, and
is replaced by adding the PTS Increment value provided to the time of the prior
frame.

Frames may still be dropped or repeated when in fixed frame rate mode
as the effective source rate is changed, but not the output rate.

@note When Vidpproc deinterlaces frames it generates two or more frames per
input frame, this can result in an apparent reduction in the frame rate
when using fixed frame rate. as opposed to normal playback where the
\ref PTS values are interpolated, automatically adjusting for the increased
frame rate.

@note In general the input to vidrend should be deinterlaced when using
Fixed frame rate, or most rate conversions that would include repeating
a field more than once.

@param[in] vidrend vidrend device handle
@param[in] frame_pts_inc frame \ref PTS increment value in 90KHz clock ticks.

@retval ISMD_SUCCESS Fixed frame rate is enabled successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER Invalid frame_pts_inc value.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_enable_fixed_frame_rate(ismd_dev_t vidrend,
                                                   unsigned int frame_pts_inc);

/**
@brief Disable fixed frame rate mode

@param[in] vidrend vidrend device handle

@retval ISMD_SUCCESS Fixed frame rate is disabled.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_disable_fixed_frame_rate(ismd_dev_t vidrend);

/**
@brief Get the fixed frame rate \ref PTS increment value for a context.

@note only valid if fixed frame rate is enabled.

@param[in] vidrend vidrend device handle
@param[out] frame_pts_inc frame PTS increment value in 90KHz clock ticks.

@retval ISMD_SUCCESS Frame PTS increment value is obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER frame_pts_inc pointer is NULL.
@retval ISMD_ERROR_INVALID_REQUEST fixed frame rate is not enabled.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_fixed_frame_rate(ismd_dev_t   vidrend,
                                            unsigned int *frame_pts_inc);

/**
@brief Get the stream position of the renderer.

When fixed frame rate mode is enabled, the scaled_time value in position
is set to ISMD_NO_PTS.

@note The least significant bit of the last_segment_pts in the returned
in the stream position structure may be truncated.

@param[in] vidrend vidrend device handle
@param[out] position stream position details.

@retval ISMD_SUCCESS The stream position is successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER info pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_stream_position(ismd_dev_t         vidrend,
                              ismd_vidrend_stream_position_info_t *position);

/**
@brief Jumps to the next frame at or beyond the provided \ref Linear_Time

@note Vidrend must be in the Paused state before this API is called.

After this API Vidrend reads through any data in its internal queue and then
processes data arriving at the input port until it finds a frame with a
\ref Linear_Time greater than or equal to the requested time. All frames
prior to the requested time are dropped. Once a frame is found it is flipped
on the next \ref VSync interrupt.

@note This API is intended to skip between relatively small periods of time
time. Skipping between long periods of time or skipping in the reverse
direction of current playback requires more system configuration.
Example. Assume current stream position is 10000. Skipping to 5*90K = 450000
clock ticks will result in a noticeable delay due to decode and processing
delay unless data is also dropped at the source.

@param[in] vidrend vidrend device handle
@param[in] linear_pts \ref Linear_Time of the frame/field to be displayed.

@retval ISMD_SUCCESS The request is valid.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST The renderer is not paused or not started.
@retval ISMD_ERROR_INVALID_PARAMETER The \ref Linear_Time is not valid. A
\ref Linear_Time is not valid if it is < than the current position for
forward frame advance or > than the current position for reverse.
@retval other All other values are failures as reported by the return code

*/
ismd_result_t ismd_vidrend_advance_to_pts(ismd_dev_t vidrend,
                                          ismd_pts_t linear_pts);

/**
@brief Get the play rate set in the renderer.

Returns 10000 in case of normal playback.

The rate is \f$speed = rate / 10000\f$.

This means that for 5x playback the rate is 50000 and for
1/5x playback the rate is 2000.

@param[in] vidrend vidrend device handle
@param[out] rate play rate set in the renderer normalized to 10000.

@retval ISMD_SUCCESS The renderer is successfully flushed.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER rate pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_play_rate(ismd_dev_t vidrend,
                                         int *rate);

/**
@brief Enables the max hold time feature.

Max hold time is the maximum time that can elapse before a new frame is
rendered (provided the frame exists in the renderer). It is a robustness
feature that allows video renderer to gracefully recover in the presence
of abnormally far apart presentation timestamps in the stream, without
causing a video freeze.

Max hold time is specified as a ratio (denominator over numerator) of
the nominal frame rate and must be greater than 1. Example, if the
frame rate is 60fps and the ratio is 2, then hold time is 1/30 sec.

By default, max hold time feature is disabled.

@param[in] vidrend vidrend device handle
@param[in] hold_time_num numerator of the hold time ratio.
@param[in] hold_time_den denominator of the hold time ratio.

@retval ISMD_SUCCESS The hold time is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER If hold_time_num/hold_time_den is 0.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_enable_max_hold_time(ismd_dev_t vidrend,
                                                unsigned int hold_time_num,
                                                unsigned int hold_time_den);

/**
@brief Disables the max hold time feature in the renderer.

@param[in] vidrend vidrend device handle

@retval ISMD_SUCCESS The hold time is disabled successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_disable_max_hold_time(ismd_dev_t vidrend);

/**
@brief Gets the max hold time for this instance.

@param[in] vidrend vidrend device handle
@param[out] hold_time_num numerator of the hold time ratio.
@param[out] hold_time_den denominator of the hold time ratio.

@retval ISMD_SUCCESS The hold time is obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER One/more of the hold time pointers is NULL.
@retval ISMD_ERROR_INVALID_REQUEST The hold time is not enabled.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_max_hold_time(ismd_dev_t vidrend,
                                             unsigned int *hold_time_num,
                                             unsigned int *hold_time_den);

/**
@brief Gets attributes of the current frame/field.

@param[in] vidrend vidrend device handle
@param[out] frame_attr pointer to frame/field attributes.

@retval ISMD_SUCCESS The attributes are successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER frame_attr pointer is NULL.
@retval ISMD_ERROR_INVALID_REQUEST The renderer is not started.
@retval ISMD_ERROR_NO_DATA_AVAILABLE Current frame/field not available.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_video_attr(ismd_dev_t             vidrend,
                                         ismd_frame_attributes_t *frame_attr);

/**
@brief Gets the current statistics.

@param[in] vidrend vidrend device handle
@param[out] stats pointer to renderer statistics.

@retval ISMD_SUCCESS The statistics are successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The stats pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_stats(ismd_dev_t           vidrend,
                                     ismd_vidrend_stats_t *stats);

/**
@brief Resets the statistics.

@param[in] vidrend vidrend device handle

@retval ISMD_SUCCESS The statistics are successfully reset.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_reset_stats(ismd_dev_t vidrend);

/**
@brief Gets the current status.

@param[in] vidrend vidrend device handle
@param[out] status pointer to renderer status.

@retval ISMD_SUCCESS The status is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The status pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_status(ismd_dev_t           vidrend,
                                     ismd_vidrend_status_t *status);

/**
@brief Gets the event that is set when \ref VSync interrupts occur.

The \ref VSync type requested can be set to frame, top field or bottom
field (as defined in \ref ismd_vidrend_vsync_type_t).

@param[in] vidrend vidrend device handle
@param[in] vsync_type type of vsync interrupt to strobe on.
@param[out] on_vsync vsync event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_NULL_POINTER The on_vsync pointer is NULL.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER The vsync_type parameter is invalid.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_vsync_event(ismd_dev_t   vidrend,
                                           ismd_vidrend_vsync_type_t vsync_type,
                                           ismd_event_t *on_vsync);

/**
@brief Gets the event that is set when errors occur.

@param[in] vidrend vidrend device handle
@param[out] on_error error event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_error pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_error_event(ismd_dev_t   vidrend,
                                           ismd_event_t *on_error);

/**
@brief Gets the event that is set when end of stream is reached.

@param[in] vidrend vidrend device handle
@param[out] on_eos eos event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_eos pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_eos_event(ismd_dev_t   vidrend,
                                         ismd_event_t *on_eos);

/**
@brief Gets the event that is set when a frame flip is detected.

@param[in] vidrend vidrend device handle
@param[out] on_frame_flipped frame flipped event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_frame_flipped pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_frame_flipped_event(ismd_dev_t vidrend,
                                                   ismd_event_t *on_frame_flipped);

/**
@brief Gets the event that is set when an underflow is detected.

This event is used to detect when input of vidrend is empty.

@param[in] vidrend vidrend device handle
@param[out] on_underflow frame timeout event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_underflow pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_underflow_event(ismd_dev_t vidrend,
                                                   ismd_event_t *on_underflow);

/**
@brief Gets the event that is set when vidrend recovers from an underflow
condition.

@param[in] vidrend vidrend device handle
@param[out] on_underflow_recovered UNDERFLOW RECOVERED event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_underflow_recovered pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_underflow_recovered_event(ismd_dev_t vidrend,
                                                   ismd_event_t *on_underflow_recovered);

/**
@brief Gets the event that is set when resolution change is detected.

@param[in] vidrend vidrend device handle
@param[out] on_res_chg resolution change event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_res_chg pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_resolution_change_event(ismd_dev_t vidrend,
                                                   ismd_event_t *on_res_chg);

/**
@brief Gets the event that is set when client id tag is seen in the buffer.

@param[in] vidrend vidrend device handle
@param[out] on_client_id_seen client id seen event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_client_id_seen pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_client_id_seen_event(ismd_dev_t vidrend,
                                                   ismd_event_t *on_client_id_seen);

/**
@brief Gets the event that is set when end of segment is reached.

@param[in] vidrend vidrend device handle
@param[out] on_eoseg end of segment event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_eoseg pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_eoseg_event(ismd_dev_t   vidrend,
                                         ismd_event_t *on_eoseg);

/**
@brief Gets the event that is set when start of segment is read from the input port.

@param[in] vidrend vidrend device handle
@param[out] on_soseg start of segment event set by the renderer

@retval ISMD_SUCCESS The event is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The on_soseg pointer is NULL.
@retval ISMD_ERROR_OPERATION_FAILED Unable to allocate event.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_soseg_event(ismd_dev_t   vidrend,
                                         ismd_event_t *on_soseg);

/**
@brief Gets the number of frames requested to be dropped before playback
for a context.

@note this returns the requested count set in
\ref ismd_vidrend_set_drop_frame_count, it does not actually read
any frames.

@param[in] vidrend vidrend device handle
@param[out] frame_count drop frame count in instance

@retval ISMD_SUCCESS The drop count was successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The frame count pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_drop_frame_count(ismd_dev_t vidrend,
                                                uint32_t   *frame_count);

/**
@brief Sets the count of frames to be dropped before playback starts for a context

The default drop_count is 0, in this case no frames are dropped.

The operation fails if the renderer is already started.

@param[in] vidrend vidrend device handle
@param[in] frame_count determines dropped frame count

@retval ISMD_SUCCESS The control is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST The renderer is started.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_drop_frame_count(ismd_dev_t vidrend,
                                                uint32_t   frame_count);

/**
@brief Toggles discontinuity handling.

Disables discontinuity handling based on the flag set. The video renderer is
capable of detecting \ref PTS discontinuities in the stream and modifying the
PTS values to handle them. It keeps modifying PTS values for up to 1/4 second
or until till it receives a New Segment tag from the demux,after which it
again starts using the PTS values coming in the frames.

discontinuity handling is enabled by default.

@note Discontinuity handling should be disabled when frames are being filtered
upstream and fixed frame rate mode is not in use as variations in encoding
patterns and deinterlacing can be detected as discontinuities.

@param[in] vidrend vidrend device handle
@param[in] disable_flag flag to disable discontinuity handling.

@retval ISMD_SUCCESS The flag is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_disable_discontinuity_handling(ismd_dev_t vidrend,
                                                  bool       disable_flag);


/**
@brief Returns the last frame flipped for a context.

Gets the last frame flipped to the display for a context. A new reference is
added to the reference count for the buffer before it is returned. The caller
must dereference the input buffer to prevent a memory leak.

@param[in] vidrend vidrend device handle
@param[out] buffer the current displayed frame.

@retval ISMD_SUCCESS The current frame is successfully returned.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NO_DATA_AVAILABLE No frame is currently in display.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_current_frame(ismd_dev_t vidrend,
                                                  ismd_buffer_handle_t *buffer);


/**
@brief Sets the behavior of the video renderer when stopped.

Possible policies include:

- \ref ISMD_VIDREND_STOP_POLICY_CLOSE_VIDEO_PLANE : video render will close the video plane which is used for
this stream.
- \ref ISMD_VIDREND_STOP_POLICY_KEEP_VIDEO_PLANE : video render will keep the video plane current status.
- \ref ISMD_VIDREND_STOP_POLICY_DISPLAY_BLACK : video render will flip a black screen to plane, rather
than close the plane.

The default stop policy is CLOSE_VIDEO_PLANE.

@note The stop policy is used when closing a context,
if \ref ISMD_VIDREND_STOP_POLICY_KEEP_VIDEO_PLANE there is a possibility of
garbage data being displayed. The policy should be set to another value before
closing the context to avoid this condition.

@param[in] vidrend vidrend device handle
@param[in] stop_policy the policy to set in the renderer.

@retval ISMD_SUCCESS The stop behavior is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER Invalid flush policy.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_stop_policy(ismd_dev_t          vidrend,
                                    ismd_vidrend_stop_policy_t stop_policy);


/**
@brief Gets the stop policy for this renderer.

@param[in] vidrend vidrend device handle
@param[out] stop_policy stop policy in instance.

@retval ISMD_SUCCESS The policy is obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_NULL_POINTER The policy pointer is NULL.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_stop_policy(ismd_dev_t         vidrend,
                                   ismd_vidrend_stop_policy_t *stop_policy);


/**
@brief Configure a vidrend instance to scale and crop incoming frames.

Sets up scaling and cropping of incoming frames if they do not match
the desired size. Can also, optionally, cause vidrend to override the
destination video window display position.

@warning this API overrides multiple settings and behaviors set and used
by other drivers. calls to this api can result in temporary reduction in
bandwidth in the vidpproc driver and a reduction in quality of the displayed
frame.

@deprecated The behavior supplied by this API has been migrated to the
Vidsink driver.

@param[in] vidrend vidrend device handle
@param[in] image_size size of the full image after scaling.
@param[in] portion_to_display  sub-region of the scaled image to be displayed.
@param[in] override_window_position optionally override the final video window position.
@param[in] window_pos_x optionally override the final video window position.
@param[in] window_pos_y optionally override the final video window position.

@retval ISMD_SUCCESS The policy is obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST The vidpproc handle in render is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_dest_params(   ismd_dev_t vidrend,
                                   ismd_rect_size_t image_size,
                                   ismd_cropping_window_t portion_to_display,
                                   bool override_window_position,
                                   unsigned int window_pos_x,
                                   unsigned int window_pos_y);

/**
@brief Do not scale incoming frames. Used to disable/stop the effects of any previous
calls to \ref ismd_vidrend_set_dest_params.

@deprecated The behavior supplied by this API has been migrated to the
Vidsink driver.

@param[in] vidrend vidrend device handle

@retval ISMD_SUCCESS The policy is obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_disable_scaling(ismd_dev_t vidrend);


/**
@brief Mutes or unmutes a context

When muted vidrend stops displaying frames, either by displaying a black frame
or keeping the last displayed frame on screen. To re-enable the display of
active video, this API may be called, using the value
\ref ISMD_VIDREND_MUTE_NONE. When muted vidrend will continue to read and
consume frames as if it were playing active video (the stream continues to
flow) however the data is not sent to the display to be included in the
visual output.

Possible options include:

- \ref ISMD_VIDREND_MUTE_DISPLAY_BLACK_FRAME : a black frame/field is displayed.
- \ref ISMD_VIDREND_MUTE_HOLD_LAST_FRAME : last frame is kept on the screen.
- \ref ISMD_VIDREND_MUTE_NONE : the renderer sends new frames/fields to the display.

The default value is \ref ISMD_VIDREND_MUTE_NONE.

This operation is invalid if the renderer is not started or plane id is not set.

@note This function replaces \ref ismd_vidrend_mute_video

@param[in] vidrend vidrend device handle
@param[in] mode the mode to freeze frame.

@retval ISMD_SUCCESS The operation is successfully completed.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST The renderer handle is not running.
@retval ISMD_ERROR_OPERATION_FAILED Internal operations failed.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_mute(   ismd_dev_t vidrend,
                                   ismd_vidrend_mute_policy_t mode);

/**
@brief Get the message context id of a context.

@param[in] vidrend vidrend device handle
@param[out] message_context used to return message context id.

@retval ISMD_SUCCESS The message context was successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_message_context(ismd_dev_t          vidrend,
                                    ismd_message_context_t *message_context);

/**
@brief Set the timing mode for a context.

By default,  video synchronization will be done in converted time domain
(timing mode equals to ISMD_TIMING_MODE_CONVERTED). Use this API to specify
the timing mode if you want to do video synchronization in original
time domain. Please also see definition of \ref ismd_timing_mode_t.

@param[in] vidrend vidrend device handle
@param[in] timing_mode mode to be set

@retval ISMD_SUCCESS the timing mode was successfully set for this device.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_timing_mode( ismd_dev_t vidrend,
                                                   ismd_timing_mode_t timing_mode);


/**
@brief Set the newsegment handling policy for a context.

Possible options include:

- \ref ISMD_NEWSEGMENT_POLICY_LOOSE : in some cases out of segment data may
not be dropped in order to increase the apparent speed of operations such as
channel change.
- \ref ISMD_NEWSEGMENT_POLICY_STRICT : no out of segment data is placed in the
internal queues. This policy should be used when using the Start Of Segment
event to enable pre-rolling.

The default value is \ref ISMD_NEWSEGMENT_POLICY_LOOSE.

@param[in] vidrend vidrend device handle
@param[in] policy Policy to be set.

@retval ISMD_SUCCESS the policy was successfully set for this device.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_newsegment_policy(ismd_dev_t vidrend,
                                                ismd_newsegment_policy_t policy);

/**
@brief Links two views in a Base/Dependent relationship

The Base/Dependent relationship is the fundamental relationship between
views/streams in 3D video. For stereoscopic 3D video only one Base and
one Dependent view are active at a time, when rendered as stereoscopic 3D
frames from both views must have matching \ref PTS values to be displayed
correctly.

@param[in] base_vidrend the vidrend device that will represent the Base view
@param[in] dependent_vidrend the vidrend device that will represent the Dependent view

@retval ISMD_SUCCESS the two views were linked
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_link_views(
   ismd_dev_t base_vidrend,
   ismd_dev_t dependent_vidrend
);

/**
@brief Unlink a dependent view from its Base.
@param[in] dependent_vidrend vidrend device handle representing a dependent view

@retval ISMD_SUCCESS the device is no longer linked to a base view
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_unlink_dependent(
   ismd_dev_t dependent_vidrend
);

/**
@brief Set the policy for handling frame drops on the base and dependent streams.

Possible options for each policy include:

- Drop the frame on the other view : in effect pause video when a valid
frame pair is not found.
- Display the frame from the other view : in effect switch to 2D for a frame.
this can result in a significant flicker depending on the content.

The default behavior is to Drop the frame on the other view.

@param[in] base_vidrend vidrend device handle representing a base view
@param[in] base_policy policy for handling missing frames on the base view
@param[in] dependent_policy policy for handling missing frames on the dependent view

@retval ISMD_SUCCESS the policy was applied
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_3D_drop_policy(
   ismd_dev_t base_vidrend,
   ismd_vidrend_3D_base_drop_policy_t base_policy,
   ismd_vidrend_3D_dependent_drop_policy_t dependent_policy
);

/**
@brief Set the policy for displaying 3D video

Possible options for each policy include:

- Display Both the Base and Dependent Views : normal stereoscopic 3D
- Display Base View on Both Outputs : 2D output on a 3D display.

The default behavior is to Display Both the Base and Dependent Views.

@param[in] base_vidrend vidrend device handle representing a base view
@param[in] policy 3D output policy

@retval ISMD_SUCCESS: the policy was applied
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_3D_output_policy(
   ismd_dev_t base_vidrend,
   ismd_vidrend_3D_output_policy_t policy
);

/**
@brief Set the angle of a context.

Sets the angle the view represented by a context should be viewed at. Used for
displaying 3D video. This value is only used for cases where two linked
vidrend instances are flipping frames to a single UPP.

@note For Dual UPP use cases this value is ignored, as each UPP has an inherent
Left/Right property

@param[in] vidrend vidrend device handle
@param[in] angle Video Angle

@retval ISMD_SUCCESS the angle was applied
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_angle(
   ismd_dev_t vidrend,
   ismd_vidrend_video_angle_t angle
);

/**
@brief Set the offset from the origin of the base view where dependent view
should be placed.

When using linked views this function allows the origin of a dependent view to
be calculated as: dependent_orgin = base_origin + offset

This is not needed in most cases for full screen 3D that uses the capabilities
of the display driver, however for "virtual" 3D modes (not using the display
driver) and some pip-animation cases this allows perfect synchronization of
window movement between linked views.

@param[in] dependent_vidrend vidrend device handle representing a dependent view
@param[in] dX the desired x offset from the base origin
@param[in] dY the desired y offset from the base origin

@retval ISMD_SUCCESS the offset was applied
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_dependent_origin_offset(
   ismd_dev_t dependent_vidrend,
   int dX,
   int dY
);

/**
@brief Disables the use of a base origin offset for a dependent view context.

@param[in] dependent_vidrend vidrend device handle representing a dependent view

@retval ISMD_SUCCESS the origin offset was applied
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_clear_dependent_origin_offset(
   ismd_dev_t dependent_vidrend
);

/**
@brief Sets a mask to prevent selected frame types form being displayed.

Sets a mask that prevents certain types of frames (such as P or B frames)
from being sent to the display. The filtered frames are processed through the
entire vidrend pipeline including internal queues and are dropped during the
process of selecting the next frame to flip.

This API allows vidrend to act as a secondary filter to the video decoder,
allowing the pipeline to refill for or flush from normal (all frames)
playback without extra flushes. This is done at the cost of extra processing
and increased delay between availability of filtered frames since the video
decoder may still be decoding and sending all frames for some time when
transitioning into filtered playback, and since it will take some time for
the pipeline to refill with normal unfiltered frames when transitioning back
to normal playback.

The default mask is 0, which does not filter any frame types. To skip a
particular frame type the bit at the position corresponding to the
desired type in \ref ismd_frame_type must be set to 1.

The following filter will reject all P and B frames
\code
frame_type_skip_mask = (1 << ISMD_FRAME_TYPE_P) | (1 << ISMD_FRAME_TYPE_B);
\endcode

The following filter will reject all frames except I frames
\code
frame_type_skip_mask = ~(1 << ISMD_FRAME_TYPE_I);
\endcode

@param[in] vidrend vidrend device handle
@param[in] frame_type_skip_mask specifies a ISMD_FRAME_TYPE_MAX(enum) bit mask, each frame type is represented by a bit

@retval ISMD_SUCCESS the frame masking was enabled/disabled successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_frame_mask( ismd_dev_t vidrend,
                                           ismd_vidrend_frame_type_mask_t frame_type_skip_mask);

/**
@brief Gets the current frame type filter mask in use by a context

@param[in] vidrend vidrend device handle
@param[out] frame_type_skip_mask specifies a bit mask with each bit masking of one frame type.

@retval ISMD_SUCCESS the frame masking was retrieved successfully.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_frame_mask( ismd_dev_t vidrend,
                                           ismd_vidrend_frame_type_mask_t *frame_type_skip_mask);

/**
@brief Enable 1VnH timing adjustment mode.

This function enables alignment of input and output \ref VSync times by
adjusting the blanking period of the output frames based on the timestamps
on incoming frames on one context, the \ref Base_Time, and the timing of the
\ref VSyncs

Once enabled for a context 1VnH checks for the following before
making timing adjustments:

- The rate of the input must be stable. The difference in \ref PTS between
three sequential frames selected for output must be less than
rate_match_epsilon.

- The rate of the output must be stable. The difference in time between
three sequential VSyncs on which frames were flipped must be less
than rate_match_epsilon.

- The rates of the input and output must be similar. The difference between
the time between sequential VSyncs on which frames are flipped and sequential
frames selected for output must be less than rate_match_epsilon.

1VnH adjusts for both frequency and phase differences.

- 1VnH will adjust for frequency if the difference between the input and
output rates is greater than adjustment_epsilon.

- 1VnH will adjust for phase if the difference between the VSync Time
and the \ref PTS flipped is greater than adjustment_epsilon.

- If both conditions are true 1VnH will alternate between the two adjustment
modes.

1VnH will never add or remove more than a total of adjustment_max blanking
lines from the nominal number of lines that should be output.
adjustment_max should be a value around 1 to 3 see Display Driver
documentation for more information about the range of possible values.

To reduce thrash it is often best for 1VnH to wait thru several cycles before
attempting to make another adjustment, lock_speed indicates how many cycles to
wait (including the current cycle). A lock_speed  of 1 indicates that
adjustments should be made every cycle, A lock_speed  of 2 indicates that
adjustments should be made every other cycle, and so on.

@param[in] vidrend vidrend device handle to use as the control source
@param[in] rate_match_epsilon maximum allowed change for 1VnH rate matching
in 90KHz ticks
@param[in] adjustment_epsilon minimum variation in rate or phase (in 90KHz
clock ticks) to trigger 1VnH adjustment to be made
@param[in] adjustment_max maximum allowed 1VnH adjustment (should be 1-3)
see Display Driver documentation for more information about the range of this
value
@param[in] lock_speed adjustments will be made 1 in every lock_speed output
vsyncs. Statistics will continue to be gathered every vsync.

@retval ISMD_SUCCESS 1VnH timing adjustment enabled
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_enable_1vnh_timing_adjustment(
   ismd_dev_t vidrend,
   int rate_match_epsilon,
   int adjustment_epsilon,
   int adjustment_max,
   int lock_speed
);

/**
@brief Disable 1VnH timing adjustment mode

@param[in] vidrend vidrend device handle

@retval ISMD_SUCCESS 1VnH timing adjustment disabled
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_disable_1vnh_timing_adjustment(
   ismd_dev_t vidrend
);

/**
@brief Common API to set any of the vidrend policies as specified
by the enum \ref ismd_vidrend_policy_t

@param[in] vidrend vidrend device handle
@param[in] policy_type Specifies the type of policy that has to be set.
@param[in] policy_value Specifies the value of the policy to be set.

@retval ISMD_SUCCESS The policy has successfully been set.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_set_policy(
   ismd_dev_t vidrend,
   ismd_vidrend_policy_t policy_type,
   unsigned int policy_value
);

/**
@brief Common API to get any of the vidrend policies as specified
by the enum \ref ismd_vidrend_policy_t

@param[in] vidrend vidrend device handle
@param[in] policy_type Specifies the type of policy that has to be set.
@param[out] policy_value Returns the value of the policy specified by policy_type.

@retval ISMD_SUCCESS The policy value has been successfully retrieved.
@retval ISMD_ERROR_INVALID_HANDLE The renderer handle is invalid.
@retval other All other values are failures as reported by the return code
*/
ismd_result_t ismd_vidrend_get_policy(
   ismd_dev_t vidrend,
   ismd_vidrend_policy_t policy_type,
   unsigned int* policy_value
);

/**@}*/ // end of ingroup ismd_vidrend
/**@}*/ // end of weakgroup ismd_vidrend

#ifdef __cplusplus
}
#endif

#endif /* __ISMD_VIDREND_H__ */
