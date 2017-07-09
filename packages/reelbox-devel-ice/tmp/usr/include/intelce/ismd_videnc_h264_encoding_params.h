/*
* File Name: ismd_videnc_h264_encoding_params.h
*/

/*
This file is provided under a dual BSD/GPLv2 license.  When using or
redistributing this file, you may do so under either license.

GPL LICENSE SUMMARY

Copyright(c) 2011 Intel Corporation. All rights reserved.

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

BSD LICENSE

Copyright(c) 2011 Intel Corporation. All rights reserved.
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

#ifndef ISMD_VIDENC_H264_ENCODING_PARAMS_H
#define ISMD_VIDENC_H264_ENCODING_PARAMS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * H.264 Encoding profiles.  Current list is only the supported ones.
*/

typedef enum
{
   ISMD_VIDENC_H264_PROFILE_BASELINE = 66, /**< BASELINE profile */
   ISMD_VIDENC_H264_PROFILE_MAIN     = 77, /**< MAIN profile */
   ISMD_VIDENC_H264_PROFILE_HIGH     = 100 /**< HIGH profile */
} ismd_videnc_h264_profile_t;

/**
 * H.264 Encoding level.  Current list is only the supported ones.
 * Specifies performance constraints on the decoder, higher values
 * support higher performance.
 */
typedef enum
{
   ISMD_VIDENC_H264_LEVEL_1_0B = 9,     /**< Level 1.0B */
   ISMD_VIDENC_H264_LEVEL_1_0  = 10,    /**< Level 1.0 */
   ISMD_VIDENC_H264_LEVEL_1_1  = 11,    /**< Level 1.1 */
   ISMD_VIDENC_H264_LEVEL_1_2  = 12,    /**< Level 1.2 */
   ISMD_VIDENC_H264_LEVEL_1_3  = 13,    /**< Level 1.3 */
   ISMD_VIDENC_H264_LEVEL_2_0  = 20,    /**< Level 2.0 */
   ISMD_VIDENC_H264_LEVEL_2_1  = 21,    /**< Level 2.1 */
   ISMD_VIDENC_H264_LEVEL_2_2  = 22,    /**< Level 2.2 */
   ISMD_VIDENC_H264_LEVEL_3_0  = 30,    /**< Level 3.0 */
   ISMD_VIDENC_H264_LEVEL_3_1  = 31,    /**< Level 3.1 */
   ISMD_VIDENC_H264_LEVEL_3_2  = 32,    /**< Level 3.2 */
   ISMD_VIDENC_H264_LEVEL_4_0  = 40,    /**< Level 4.0 */
   ISMD_VIDENC_H264_LEVEL_4_1  = 41     /**< Level 4.1 */
} ismd_videnc_h264_level_t;

/******************************************************************************/
/*!    @name H.264 specific APIs */

/**
Parameters used for initializing the H.264 codec.
*/
typedef struct {
   ismd_videnc_h264_profile_t    profile;  /**< H.264 Profile */
   ismd_videnc_h264_level_t      level;    /**< H.264 Level */
} ismd_videnc_h264_init_params_t;

/**
Encoding aspect ratio.
*/
typedef enum
{
   ISMD_VIDENC_H264_ASPECT_RATIO_AUTO = 0,      /**< Sample aspect ratio will be selected such that a 4:3 image is achieved for SD video, and a 16:9 image for HD video */
   ISMD_VIDENC_H264_ASPECT_RATIO_4_3,           /**< Sample aspect ratio will be selected such that a 4:3 image is achieved */
   ISMD_VIDENC_H264_ASPECT_RATIO_16_9,          /**< Sample aspect ratio will be selected such that a 16:9 image is achieved */
   ISMD_VIDENC_H264_ASPECT_RATIO_NONE,          /**< Aspect ratio information will not be present in the stream */
   ISMD_VIDENC_H264_ASPECT_RATIO_SAME_AS_INPUT  /**< Will use the same sample aspect ratio as in the input if supported, otherwise will use ISMD_VIDENC_H264_ASPECT_RATIO_NONE */
} ismd_videnc_h264_aspect_ratio_t;


/**
Encoding rate entropy mode.
*/
typedef enum
{
   ISMD_VIDENC_H264_ENTROPY_MODE_CAVLC = 0, /**< cavlc entropy mode */
   ISMD_VIDENC_H264_ENTROPY_MODE_CABAC      /**< cabac entropy mode - this is only for main and high profiles */
} ismd_videnc_h264_entropy_mode_t;

/**
Encoding rate chroma format.
*/
typedef enum
{
   ISMD_VIDENC_H264_CHROMA_FORMAT_4_0_0 = 0, /**< Output stream will be monochrome. This is only allowed for HIGH profile */
   ISMD_VIDENC_H264_CHROMA_FORMAT_4_2_0 = 1  /**< Chroma format of output stream will be 4:2:0 */
} ismd_videnc_h264_chroma_format_t;

/**
Encoding rate control mode.
*/
typedef enum
{
   ISMD_VIDENC_H264_RATE_CONTROL_CBR = 0,  /**< Constant bit rate */
   ISMD_VIDENC_H264_RATE_CONTROL_VBR = 1   /**< Variable bit rate */
} ismd_videnc_h264_bitrate_mode_t;

/**
Bitrate settings.
When in VBR mode, if the bitrate is greater than the max_bitrate,
the driver returns an error.
*/
typedef struct
{
   ismd_videnc_h264_bitrate_mode_t   bitrate_mode;           /**< bit rate mode to use */
   uint32_t                          max_bitrate;            /**< Maximum bit rate allowed in bits/sec. This should be greater than 0
                                                                  but not greater than 50 million. This is used for VBR mode */
   uint32_t                          bitrate;                /**< Target bit rate in bits/sec. This should be greater than 0
                                                                  but not greater than 50 million. It must be less than max_bitrate. */
} ismd_videnc_h264_bitrate_settings_t;

typedef struct
{
   uint32_t                          GOP_length;             /**< [1..1000] GOP length in Frame including the I picture. */
   uint32_t                          num_of_B_frames;        /**< [0..2] Maximum number of consecutive B Frame in a GOP.
                                                                  Must be 0 for CE4200 */
   uint32_t                          IDR_Frequency;          /**< Number of frame between 2 IDR pictures.
                                                                  This should be 0 if IDR should
                                                                  be inserted only when scene change
                                                                  is detected. */
} ismd_videnc_h264_gop_settings_t;

/**
Scaling list.
*/
typedef enum {
   ISMD_VIDENC_H264_SCALING_LIST_FLAT,           /**< Use flat scaling list */
   ISMD_VIDENC_H264_SCALING_LIST_DEFAULT,        /**< Use default scaling list. High profile only. */
   ISMD_VIDENC_H264_SCALING_LIST_INTEL_CUSTOM,   /**< Use custom scaling list. High profile only. */
} ismd_videnc_h264_scaling_list_t;

/**
Lambda parameters.
*/
typedef enum {
    ISMD_VIDENC_H264_QP_UNIFORM,            /**< Use the same QP for the entire picture */
    ISMD_VIDENC_H264_QP_AUTO,               /**< Autoselect QP for each macro block */
} ismd_videnc_h264_qp_mode_t;

/**
Encoding settings.
*/
typedef struct
{
   ismd_videnc_h264_chroma_format_t        chroma_format;          /**< chroma format of output stream */
   ismd_videnc_h264_aspect_ratio_t         aspect_ratio;           /**< Aspect ratio of output stream */
   ismd_videnc_h264_entropy_mode_t         entropy;                /**< entropy encoding method */
   ismd_videnc_h264_bitrate_settings_t     bitrate_settings;       /**< bit rate settings */
   ismd_videnc_h264_gop_settings_t         gop_settings;           /**< GOP settings */
   ismd_videnc_h264_scaling_list_t         scaling_list;           /**< Scaling list settings */
   ismd_videnc_h264_qp_mode_t              qp_mode;                /**< QP mode settings */
} ismd_videnc_h264_encoder_params_t;


#ifdef __cplusplus
}
#endif

#endif // ISMD_VIDENC_H264_ENCODING_PARAMS_H
