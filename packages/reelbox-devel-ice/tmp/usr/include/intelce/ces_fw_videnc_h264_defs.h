/*  
This file is provided under a dual BSD/GPLv2 license.  When using or 
redistributing this file, you may do so under either license.

GPL LICENSE SUMMARY

Copyright(c) 2007-2010 Intel Corporation. All rights reserved.

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

Copyright(c) 2007-2010 Intel Corporation. All rights reserved.
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

#ifndef CES_FW_VIDENC_H264_DEFS_H
#define CES_FW_VIDENC_H264_DEFS_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
    VIDENC_DISABLE_OPTION = 0,
    VIDENC_ENABLE_OPTION
} enabled_option_t;

typedef enum
{
    VIDENC_RATE_CONTROL_CBR      = 0x00,  /* Use constant bit rate controller */
    VIDENC_RATE_CONTROL_VBR      = 0x01,  /* Use variable bit rate controller */
    VIDENC_RATE_CONTROL_CONST_QP = 0x80   /* Use const slice QP parameters */
} rate_control_mode_t;

typedef struct
{
    uint32_t GOP_length;           /* GOP length in Frame including the I picture */
    uint32_t num_of_B_frames;      /* [0..2] Maximum number of consecutive B Frame in a GOP */
    uint32_t IDR_Frequence;        /* Number of frame between 2 IDR picture. The accuracy is more 
                                      or less 1 gopNumber of GOPs between 2 IDR pictures. 
                                      if scene change detection is supported this parameter can be set
                                      to 0 which means IDR pictures will only be added when scene change happens */
} GOP_info_t;

typedef struct
{
    rate_control_mode_t RC_mode;        /* Rate control mode to use */
    GOP_info_t          GOP_info;       /* Specifies the Gop informations */
    int32_t             Cb_QP_offset;   /* [-12..+12] Specifies QP offset for the first chroma channel (Cb) */
    int32_t             Cr_QP_offset;   /* [-12..+12] Specifies QP offset for the second chroma channel (Cr) */
    uint32_t            sliceQP;        /* [0..51]. The slice QP. used only when the RC mode is 'CONST_QP' */    
} rate_control_settings_t;

typedef enum 
{
    VIDENC_PROFILE_BASELINE = 66, 
    VIDENC_PROFILE_MAIN     = 77, 
    VIDENC_PROFILE_EXTENDED = 88,
    VIDENC_PROFILE_HIGH     = 100,
    VIDENC_PROFILE_HIGH10   = 110,
    VIDENC_PROFILE_HIGH422  = 122,
    VIDENC_PROFILE_HIGH444  = 144
} profile_mode_t;



typedef enum
{
    VIDENC_ENTROPY_MODE_CAVLC = 0, /*cavlc entropy mode */
    VIDENC_ENTROPY_MODE_CABAC      /*cabac entropy mode */
} entropy_mode_t;

typedef enum
{
    VIDENC_SCALING_LIST_FLAT = 0,
    VIDENC_SCALING_LIST_DEFAULT,
    VIDENC_SCALING_LIST_CUSTOM
} scaling_list_mode_t;

#define VIDENC_ENABLE_ALL_PRED   0x00 /* enable all prediction modes */

typedef enum
{
    VIDENC_DISABLE_PRED_VERT   = 0x01, /* Disables Intra_NxN_Vertical prediction Mode */
    VIDENC_DISABLE_PRED_HORZ   = 0x02, /* Disables Intra_NxN_Horizontal prediction Mode */
    VIDENC_DISABLE_PRED_PLANE  = 0x04, /* Disables Intra_16x16_Plane prediction Mode */
    VIDENC_DISABLE_PRED_DDL    = 0x04, /* Disables Intra_NxN_Diagonal_Down_Left prediction Mode */
    VIDENC_DISABLE_PRED_DDR    = 0x08, /* Disables Intra_NxN_Diagonal_Down_Right prediction Mode */
    VIDENC_DISABLE_PRED_VR     = 0x10, /* Disables Intra_NxN_Vertical_Right prediction Mode */
    VIDENC_DISABLE_PRED_HD     = 0x20, /* Disables Intra_NxN_Horizontal_Down prediction Mode */
    VIDENC_DISABLE_PRED_VL     = 0x40, /* Disables Intra_NxN_Vertical_Left prediction Mode */
    VIDENC_DISABLE_PRED_HU     = 0x80  /* Disables Intra_NxN_Horizontal_Up prediction Mode */
} intera_prediction_mode_options_t;

typedef enum
{
    VIDENC_DISABLE_PRED_4X4    = 0x01, /* Disables Inter_4x4 prediction Mode */
    VIDENC_DISABLE_PRED_4X8    = 0x02, /* Disables Inter_4x8 prediction Mode */
    VIDENC_DISABLE_PRED_8X4    = 0x04, /* Disables Inter_8x4 prediction Mode */
    VIDENC_DISABLE_PRED_8X8    = 0x08, /* Disables Inter_8x8 prediction Mode */
    VIDENC_DISABLE_PRED_8X16   = 0x10, /* Disables Inter_8x16 prediction Mode */
    VIDENC_DISABLE_PRED_16X8   = 0x20, /* Disables Inter_16x8 prediction Mode */
    VIDENC_DISABLE_PRED_16X16  = 0x40  /* Disables Inter_16x16 prediction Mode */
} inter_part_prediction_mode_options_t;

typedef enum
{
    VIDENC_DISABLE_PRED_L0     = 0x01, /* Disables B_L0_xx_MxN and B_yy_L0_MxN prediction Mode */
    VIDENC_DISABLE_PRED_L1     = 0x02, /* Disables B_L1_xx_MxN and B_yy_L1_MxN prediction Mode */
    VIDENC_DISABLE_PRED_BI     = 0x04, /* Disables B_Bi_xx_MxN and B_yy_Bi_MxN prediction Mode */
    VIDENC_DISABLE_PRED_D8X8   = 0x08, /* Disables B_Direct_8x8 prediction Mode */
    VIDENC_DISABLE_PRED_D16x16 = 0x10  /* Disables B_Direct_16x16 prediction Mode */
} inter_b_prediction_mode_options_t;


typedef enum
{
    VIDENC_LOOP_FILTER_MODE_ENABLE = 0,
    VIDENC_LOOP_FILTER_MODE_DISABLE,
    VIDENC_LOOP_FILTER_MODE_DIS_SLICE
} loop_filter_mode_t;

typedef struct 
{
    loop_filter_mode_t loop_filter;
    int32_t            loop_filter_alpha_offset; /* [-6..+6] Specifies the offset used in accessing the alpha deblocking filter table */                                      
    int32_t            loop_filter_beta_offset;  /* [-6..+6] Specifies the offset used in accessing the beta deblocking filter table */                                      
} loop_filter_t;

typedef struct 
{
    uint32_t mode_4x4;   /* VIDENC_ENABLE_ALL_PRED or any combination of VIDENC_DISABLE_PRED_VERT, VIDENC_DISABLE_PRED_HORZ, VIDENC_DISABLE_PRED_PLANE */
    uint32_t mode_8x8;   /* VIDENC_ENABLE_ALL_PRED or any combination of VIDENC_DISABLE_PRED_VERT, VIDENC_DISABLE_PRED_HORZ, VIDENC_DISABLE_PRED_DDL, VIDENC_DISABLE_PRED_DDR, VIDENC_DISABLE_PRED_VR, VIDENC_DISABLE_PRED_HD, VIDENC_DISABLE_PRED_VL, VIDENC_DISABLE_PRED_HU */
    uint32_t mode_16x16; /* VIDENC_ENABLE_ALL_PRED or any combination of VIDENC_DISABLE_PRED_VERT, VIDENC_DISABLE_PRED_HORZ, VIDENC_DISABLE_PRED_DDL, VIDENC_DISABLE_PRED_DDR, VIDENC_DISABLE_PRED_VR, VIDENC_DISABLE_PRED_HD, VIDENC_DISABLE_PRED_VL, VIDENC_DISABLE_PRED_HU */                       
} intra_prediction_mode_t;

typedef struct 
{
    uint32_t partition; /* VIDENC_ENABLE_ALL_PRED or any combination of VIDENC_DISABLE_PRED_8x8, VIDENC_DISABLE_PRED_8x16, VIDENC_DISABLE_PRED_16x8, VIDENC_DISABLE_PRED_16x16 */
    uint32_t mode_b;    /* VIDENC_ENABLE_ALL_PRED or any combination of VIDENC_DISABLE_PRED_L0, VIDENC_DISABLE_PRED_L1, VIDENC_DISABLE_PRED_BI, VIDENC_DISABLE_PRED_D8X8, VIDENC_DISABLE_PRED_D16X16 */
} inter_prediction_mode_t;

typedef struct
{
    intra_prediction_mode_t intra;
    inter_prediction_mode_t inter;
} prediction_mode_t;

typedef enum
{
  VIDENC_UNIFORM_QP = 0x00, /* Use the same QP value for the entire slice */
  VIDENC_AUTO_QP    = 0x01, /* Compute Qp by MB on the fly */
} qp_ctrl_mode_t;

typedef enum
{
    VIDENC_STATIC_LDA   = 0x00, /* Use the default static lambda params table */
    VIDENC_IMPROVED_LDA = 0x01  /* Use custom lambda params table */     
} lambda_params_mode_t;

typedef struct
{
    entropy_mode_t            entropy;              /* Select the entropy encoding method */
    enabled_option_t          transform_8x8;        /* Enable/Disable use of 8x8 transformation */
    uint32_t                  cabac_init_idc;       /* [0..2] Specifies the index for determining the table used to initialize the cabac context */    
    scaling_list_mode_t       scaling_list;      
    loop_filter_t             loop_filter;          /* Deblocking Filter parameters */
    enabled_option_t          intra_16x16;          /* Enable/Disable use of Intra_16x16 prediction */  
    enabled_option_t          intra_8x8;            /* Enable/Disable use of Intra_8x8 prediction */  
    enabled_option_t          intra_4x4;            /* Enable/Disable use of Intra_4x4 prediction */

    prediction_mode_t         disable_prediction;   /* If disabled prediction sub mode flags */
    uint32_t /*bool*/         disable_skip;         /* When a macroblock meets the skip conditions, the encoder */
    uint32_t /*bool*/         disable_P8x8_ref_0;   /* When a macroblock meets the conditions, the encoder 
                                                       encodes it using P_8x8ref0 macroblock type. Setting 
                                                       this parameter to TRUE will disabled this capability 
                                                       and the encoder will encode the macroblock using 
                                                       the P_8x8 type instead.  */  
    uint32_t /*bool*/         disable_quart_pixel;  /* Specifies whether the quart pixel algorithms should be used to refine the motion vectors or not. */
    qp_ctrl_mode_t            qp_ctrl_mode;         /* Controls the mode of selecting the MB QPs inside the slice */                                                       
    lambda_params_mode_t      lda_params_mode;      /* Specifies the lambda parameters table that should be used by the encoder */      
} slice_parameters_t;

typedef struct
{
    profile_mode_t          profile;                /* specifies Profile to which the bitstream conforms */
    uint32_t                level;                  /* [9..41] specifies Level to which the bitstream conforms. the values corresponds to level 1.0 to 4.1 */
} stream_settings_t;

typedef struct
{
    stream_settings_t       stream_settings;
    slice_parameters_t      slice_parameters;
    rate_control_settings_t rate_control;
} videnc_h264_encoder_params_t;


typedef struct 
{
    uint32_t reference_buffers_num;
    uint32_t reference_buffers_height;
    uint32_t reference_buffers_width;
    uint32_t colc_buffer_size; 
} videnc_h264_query_resources_t;

#define H264_REFERENCE_BUFFERS_MAX_NUM 3


typedef struct
{
   uint32_t driver_id; 
   uint32_t size;
   uint32_t phys;
} videnc_h264_buffer_desc_t;


typedef struct
{
    uint32_t reference_buffers_num;
    videnc_h264_buffer_desc_t reference_buffers[H264_REFERENCE_BUFFERS_MAX_NUM];/* phys addresses of the stream reference buffers. */
    uint32_t reference_buffers_height;
    uint32_t reference_buffers_width;
    videnc_h264_buffer_desc_t colc_buffer; 
} videnc_h264_encoder_resources_t;


#ifdef __cplusplus
}
#endif

#endif//#ifndef VIDENC_FW_H264_ENCODING_PARAMS_H


