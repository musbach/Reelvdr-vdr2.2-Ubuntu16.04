/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2009-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2009-2010 Intel Corporation. All rights reserved.
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

/** @file ismd_vidcap.h
 * SMD vidcap API
 */

#ifndef __ISMD_AVCAP_SHIM_H__
#define __ISMD_AVCAP_SHIM_H__

#include "ismd_msg.h"
#include "ismd_global_defs.h"
#include "ismd_clock_recovery.h"
#include "avcap.h"

#ifdef __cplusplus
extern "C" {
#endif

//TODO: Doxygen documentation

/** @ingroup smd_avcap_shim */
/**@{*/

/*
Enumeration listing event handles that can be retreived by the client
*/
typedef enum
{  
    ISMD_AVCAP_SHIM_EVENT_VIDEO_MODE_CHANGE,
    ISMD_AVCAP_SHIM_EVENT_AUDIO_MODE_CHANGE,
    ISMD_AVCAP_SHIM_EVENT_MUTE,
    ISMD_AVCAP_SHIM_EVENT_HDCP,
    ISMD_AVCAP_SHIM_EVENT_PACKET,
    ISMD_AVCAP_SHIM_EVENT_MSG_FRAME_DROP,
    ISMD_AVCAP_SHIM_EVENT_MSG_BUFER_OVERFLOW,
    ISMD_AVCAP_SHIM_EVENT_BUFFER_ALLOC_ERROR,
    ISMD_AVCAP_SHIM_EVENT_PORT_WRITE_ERROR,
} ismd_avcap_event_id_t;

// Refer to avcap.h for field information
typedef avcap_video_mode_t ismd_avcap_video_mode_t;
typedef avcap_audio_mode_t ismd_avcap_audio_mode_t;
typedef avcap_mute_info_t  ismd_avcap_mute_info_t;

/*
Enumeration listing instance types that can be opened.
*/
typedef enum
{
    ISMD_AVCAP_ID_NXP_AUDIO,
    ISMD_AVCAP_ID_NXP_VIDEO,
    ISMD_AVCAP_ID_SYNTHETIC_AUDIO,
    ISMD_AVCAP_ID_SYNTHETIC_VIDEO,
    ISMD_AVCAP_ID_CE4X00_VIDEO,
    ISMD_AVCAP_ID_CE4X00_AUDIO,
} ismd_avcap_id_t;

/*
View status 
*/
typedef struct
{
    ismd_port_handle_t output_port;
    bool               is_active;
} ismd_avcap_view_info_t;

// Creates a device instance and connects it with specified capturing driver
ismd_result_t SMDCONNECTION ismd_avcap_shim_open(ismd_avcap_id_t avcap_id, ismd_dev_t *dev);

// Returns event handle based on event id passed
ismd_result_t SMDEXPORT ismd_avcap_shim_get_event_handle(ismd_dev_t dev, ismd_avcap_event_id_t id, ismd_event_t *event);

// Returns video mode for the specified capturing instance
ismd_result_t SMDEXPORT ismd_avcap_shim_get_video_mode(ismd_dev_t dev, ismd_avcap_video_mode_t *video_mode);

// Returns audio mode for the specified capturing instance
ismd_result_t SMDEXPORT ismd_avcap_shim_get_audio_mode(ismd_dev_t dev, ismd_avcap_audio_mode_t *audio_mode);

// Returns mute information for the specified caputirng instance
ismd_result_t SMDEXPORT ismd_avcap_shim_get_mute_info(ismd_dev_t dev, ismd_avcap_mute_info_t *mute_info);

// Returns hdcp status information for the specified capturing instance
ismd_result_t SMDEXPORT ismd_avcap_shim_get_hdcp_status(ismd_dev_t dev, avcap_bool_t * status);

// Returns output port of the capturing instance
ismd_result_t SMDEXPORT ismd_avcap_shim_get_output_port(ismd_dev_t dev, ismd_port_handle_t *output_port);

// Sets sync clock on capturing instance
ismd_result_t SMDEXPORT ismd_avcap_shim_set_sync_clock(ismd_dev_t dev, clock_sync_t clock);

// Returns output pixel format of the capturing instance. Only makes sense
// for the video capturing drivers
ismd_result_t SMDEXPORT ismd_avcap_shim_get_output_pf(ismd_dev_t dev, avcap_pixel_format_t *format);

// Returns output colorspace of the capturing instance. Only makes sense
// for the video capturing drivers
ismd_result_t SMDEXPORT ismd_avcap_shim_get_output_cs(ismd_dev_t dev, avcap_color_space_t *colorspace);

// Returns first available packet from the internal queue. Call untill error to
// get all packets out.
ismd_result_t SMDEXPORT ismd_avcap_shim_get_packet(ismd_dev_t dev, avcap_packet_t *packet);

// Creates and returns a port for given view ID; New view is disabled by default
ismd_result_t SMDEXPORT ismd_avcap_shim_add_view(ismd_dev_t dev, unsigned int id, ismd_port_handle_t * port);

// Enables given view
ismd_result_t SMDEXPORT ismd_avcap_shim_enable_view(ismd_dev_t dev, unsigned int id);

// Disable given view
ismd_result_t SMDEXPORT ismd_avcap_shim_disable_view(ismd_dev_t dev, unsigned int id);

// Destroys given view
ismd_result_t SMDEXPORT ismd_avcap_shim_remove_view(ismd_dev_t dev, unsigned int id);

// Queries current status of given view
ismd_result_t SMDEXPORT ismd_avcap_shim_get_view_info(ismd_dev_t dev, unsigned int id, ismd_avcap_view_info_t * info);

// Set the output pixel format
ismd_result_t SMDEXPORT ismd_avcap_shim_set_output_pf(ismd_dev_t dev, avcap_pixel_format_t pf);

// Set the horizontal downsampler
ismd_result_t SMDEXPORT ismd_avcap_shim_set_hds(ismd_dev_t dev, avcap_bool_t hds_enable);

// Get the horizontal downsampler
ismd_result_t SMDEXPORT ismd_avcap_shim_get_hds(ismd_dev_t dev, avcap_bool_t * hds_enable);

// Returns VBI port for specified device
ismd_result_t SMDEXPORT ismd_avcap_shim_get_vbi_port(ismd_dev_t dev, ismd_port_handle_t * port);

// Set the custom output geometry
ismd_result_t SMDEXPORT ismd_avcap_shim_set_custom_geometry(ismd_dev_t dev, unsigned int width, unsigned int height);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* __ISMD_AVCAP_SHIM_H_ */
