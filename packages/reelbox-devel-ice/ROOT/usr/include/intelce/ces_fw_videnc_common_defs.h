/*  
    This file is provided under a dual BSD/GPLv2 license.  When using or 
    redistributing this file, you may do so under either license.
    
    GPL LICENSE SUMMARY
    
    Copyright(c) 2010-2011 Intel Corporation. All rights reserved.
    
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

    Copyright(c) 2010-2011 Intel Corporation. All rights reserved.
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

#ifndef CES_FW_VIDENC_COMMON_DEFS_H
#define CES_FW_VIDENC_COMMON_DEFS_H

#include "ces_fw_videnc_h264_defs.h"
#include "ces_fw_common_defs.h"

typedef union
{
    videnc_h264_encoder_resources_t h264_codec_resources;
} videnc_encoder_codec_resources_t;


typedef union
{
    videnc_h264_encoder_params_t h264_params;
} videnc_codec_specific_params_t;


typedef union
{
    videnc_h264_query_resources_t h264_resources;
} videnc_codec_specific_query_resources_t;

#define VIDENC_FW_ES_INPUT_QUEUE_DEPTH 32
#define VIDENC_FW_WKLD_INPUT_QUEUE_DEPTH 32
#define VIDENC_FW_WKLD_OUTPUT_QUEUE_DEPTH 32

typedef enum
{
    VIDENC_FW_STREAM_PRIORITY_BACKGROUND = 0,
    VIDENC_FW_STREAM_PRIORITY_REALTIME,
    VIDENC_FW_STREAM_PRIORITY_MAX
} videnc_stream_priority_t;

/* Defines for attributes on stream, If not set explicitly will be default values */
typedef enum
{ 
    VIDENC_FW_ES_INPUT_Q_WATERMARK,   /* uint32_t - Define for setting input ES queue watermarks */
    VIDENC_FW_WKLD_INPUT_Q_WATERMARK, /* uint32_t - Define for setting input WKLD queue watermarks */
    VIDENC_FW_STREAM_PRIORITY         /* Define for setting stream priority. should be one of the items in 'videnc_stream_priority_t' */
}videnc_fw_stream_attributes_t;

/** Hardware Accelerated stream formats */
typedef enum 
{
   STREAM_FORMAT_INVALID = 0,
   STREAM_FORMAT_MPEG2,
   STREAM_FORMAT_H264,
   STREAM_FORMAT_VC1,
   STREAM_FORMAT_MPEG4,
   STREAM_FORMAT_MAX          /* must be last  */
} videnc_stream_format_t;

/** information about the size and number of reference buffers */
typedef struct
{
   uint32_t height;       /** The buffer height in bytes */
   uint32_t width;        /** The buffer width in bytes */
   uint32_t buff_num;     /** The number of reference buffers */
} videnc_ref_buff_info_t;

/** Allocated ddr resources for a stream */
typedef struct 
{
    uint32_t strm_phys_addr;                 /* phys address of the ddr buffer allocate for the stream. */
} videnc_stream_allocated_ddr_t;

/* epu settings used in stream initialization */
typedef struct
{
    uint32_t scd_enabled;
    uint32_t fmd_enabled;
    uint32_t scd_look_ahead;
}   videnc_stream_epu_settings_t;

/* stream initialization settings */
typedef struct
{
    videnc_stream_format_t codec_type;         /* the stream codec type */
    videnc_stream_priority_t priority;         /* priority of the stream - background or realtime */
    uint32_t input_es_buffers_size;            /* size of the ES buffers */
    videnc_stream_epu_settings_t epu_settings; /* the epu settings for the stream */ 
} videnc_stream_settings_t;

/* Defines for Interrupt mask */
typedef enum
{
    VIDENC_FW_DISABLE_ALL_INTERRUPTS       = 0x00000000, /* No interrupts. used to mask all the interrupts */
    VIDENC_FW_WKLD_DATA_AVAIL              = 0x00000001, /* A processed workload is available */
    VIDENC_FW_WKLD_INPUT_WATERMARK_REACHED = 0x00000002, /* The wkld input path reached the set watermark for current stream */
    VIDENC_FW_ES_INPUT_WATERMARK_REACHED   = 0x00000004, /* The empty es buffer input path reached the set watermark for current stream */
    VIDENC_FW_ENABLE_ALL_INTERRUPTS        = 0x00000007  /* Enable all interrupts. This is the default option when the stream is created */
}videnc_fw_int_t;

typedef enum /* bit field - used to define the set of flags in the wkld descriptor */
{   
    VIDENC_WKLD_FLAG_NONE                  = 0x00000000,
    VIDENC_WKLD_FLAG_END_OF_SEQUENCE       = 0x00000001,   /* bit 0 - inout */
    VIDENC_WKLD_FLAG_END_OF_STREAM         = 0x00000002,   /* bit 1 - inout */ 
    VIDENC_WKLD_FLAG_RESOLUTION_CHANGE     = 0x00000004,   /* bit 2 - out */ 
    VIDENC_WKLD_FLAG_CHROMA_FORMAT_CHANGE  = 0x00000008,   /* bit 3 - out */  
    VIDENC_WKLD_FLAG_FRAME_FORMAT_CHANGE   = 0x00000010,   /* bit 4 - out */  
    VIDENC_WKLD_FLAG_FRAME_RATE_CHANGE     = 0x00000020,   /* bit 5 - out */  
    VIDENC_WKLD_FLAG_BIT_RATE_CHANGE       = 0x00000040,   /* bit 6 - out */  
    VIDENC_WKLD_FLAG_GOP_MODE_CHANGE       = 0x00000080,   /* bit 7 - out */  
    VIDENC_WKLD_FLAG_ASPECT_RATIO_CHANGE   = 0x00000100,   /* bit 8 - out */  
    VIDENC_WKLD_FLAG_CODEC_SETTINGS_CHANGE = 0x00000200,   /* bit 9 - out */  
    VIDENC_WKLD_FLAG_DISCONTINUITY         = 0x00000400,   /* bit 10 - inout */ 
    VIDENC_WKLD_FLAG_NO_FRAME_IN_WKLD      = 0x00000800,   /* bit 11 - out */
    VIDENC_WKLD_FLAG_SCENE_CHANGE_DETECTED = 0x00001000,   /* bit 12 - out */  
} videnc_wkld_flags_t;

#define VIDENC_WKLD_FLAG_EOS_MASK (VIDENC_WKLD_FLAG_END_OF_SEQUENCE | \
                                   VIDENC_WKLD_FLAG_END_OF_STREAM)

#define VIDENC_WKLD_INPUT_FLAGS (VIDENC_WKLD_FLAG_END_OF_SEQUENCE | \
                                 VIDENC_WKLD_FLAG_END_OF_STREAM | \
                                 VIDENC_WKLD_FLAG_DISCONTINUITY )

#define VIDENC_WKLD_FLAG_NEW_SETTINGS (VIDENC_WKLD_FLAG_RESOLUTION_CHANGE | \
                                       VIDENC_WKLD_FLAG_CHROMA_FORMAT_CHANGE | \
                                       VIDENC_WKLD_FLAG_FRAME_FORMAT_CHANGE | \
                                       VIDENC_WKLD_FLAG_FRAME_RATE_CHANGE | \
                                       VIDENC_WKLD_FLAG_BIT_RATE_CHANGE | \
                                       VIDENC_WKLD_FLAG_GOP_MODE_CHANGE | \
                                       VIDENC_WKLD_FLAG_ASPECT_RATIO_CHANGE | \
                                       VIDENC_WKLD_FLAG_CODEC_SETTINGS_CHANGE)
                                   
typedef ces_fw_que_desc_t videnc_es_desc_t; 
typedef ces_fw_que_desc_t videnc_frm_wkld_desc_t; /* the 'flags' field value is interpreted as a 
                                                     bit field of type videnc_wkld_flags_t */ 

typedef enum
{
    VIDENC_CHROMA_FORMAT_4_0_0 = 0,
    VIDENC_CHROMA_FORMAT_4_2_0,
    VIDENC_CHROMA_FORMAT_4_2_2
} videnc_chroma_format_t;
    
/* Workload items flag.*/
enum videnc_workload_item_flag /* bit field */
{
    VIDENC_WORKLOAD_INVALID                      = 0x0000, /* Unknown type */
    VIDENC_WORKLOAD_FRAME_START                  = 0x0001, /* bit 0 - The first encoded ES buffer of the frame */
    VIDENC_WORKLOAD_DRIVER_TAG                   = 0x0002, /* bit 1 - Driver tag. ignored by the FW. */
    VIDENC_WORKLOAD_ENCODED_ES                   = 0x0004, /* bit 2 - Encoded ES buffer */
    VIDENC_WORKLOAD_FRAME_LEVEL_USER_DATA        = 0x0008, /* bit 3 - Attach user data to frame */
    VIDENC_WORKLOAD_TOP_FIELD_LEVEL_USER_DATA    = 0x0010, /* bit 4 - Attach user data to top field */
    VIDENC_WORKLOAD_BOTTOM_FIELD_LEVEL_USER_DATA = 0x0020, /* bit 5 - Attach user data to bottom field */
    VIDENC_WORKLOAD_REGISTERED_USER_DATA         = 0x0040, /* bit 6 - Registered user data */
    VIDENC_WORKLOAD_UNREGISTERED_USER_DATA       = 0x0080, /* bit 7 - Unregistered user data */
    VIDENC_WORKLOAD_SEI_FRAME_PACKING_MESSAGE    = 0x0100, /* bit 8 - SEI Frame Packing data */
};

/* 16-byte workload */
typedef struct 
{
    enum videnc_workload_item_flag flags;
    union
    {
        struct
        {
            uint32_t    es_id;       /* id of es buffer (not modified by FW).*/
            uint32_t    es_len;      /* number of bytes written.*/
            uint32_t    es_addr;     /* phys addr of the es_buffer*/
        }encoded_es;
        struct
        {
            uint32_t    user_data_id;
            uint32_t    user_data_phys_addr; 
            uint32_t    user_data_len;
        } user_data;
        char driver_tag[12];   
    };
} videnc_workload_item_t;

typedef struct 
{
    uint32_t    driver_frame_id;    
    uint32_t    luma_phys_addr;     
    uint32_t    chroma_phys_addr;   
} videnc_frame_buffer_desc_t;

typedef enum
{
    VIDENC_FRAME_FORMAT_EMPTY,                   /* there is no frame in the WKLD */
    VIDENC_FRAME_FORMAT_PROGRESSIVE,             /* the wkld frame is progressive frame */
    VIDENC_FRAME_FORMAT_INTERLACED_ONE_BUFFER,   /* the wkld frame is interlaced frame. both fields are in the same buffer */
    VIDENC_FRAME_FORMAT_INTERLACED_TWO_BUFFERS   /* the wkld frame is interlaced frame. each field is in different buffer. 
                                                    in this mode the frame in the first buffer is encoded as the first field 
                                                    and the frame in the second buffer is encoded as the second field. Therefore
                                                    the top field should be in the first buffer when the frame is TFF and in the 
                                                    second buffer when the frame is BFF */
} videnc_frame_format_t;

typedef enum /* bit field */
{
    VIDENC_CADENCE_NONE                = 0x00,   
    VIDENC_CADENCE_TOP_FIELD_FIRST     = 0x01,   /* bit 0 - '1' when the top field is first and '0' when the bottom field is first */
    VIDENC_CADENCE_REPEAT_FIRST_FIELD  = 0x02    /* bit 1 - '1' when the first field should be repeated and '0' otherwise */
} videnc_cadence_info_t;

typedef enum
{
    VIDENC_ASPECT_RATIO_NONE = 0, /* no aspect ratio information is provided */
    VIDENC_ASPECT_RATIO_4_3,      /* set the aspect ratio to get a 4:3 picture */
    VIDENC_ASPECT_RATIO_16_9,     /* set the aspect ratio to get a 16:9 picture */
    VIDENC_ASPECT_RATIO_MANUAL    /* manually set the aspect ratio value  */
} videnc_aspect_ratio_mode_t;

typedef struct  
{
    videnc_aspect_ratio_mode_t mode;
    uint32_t numerator;                /* relevant only when the mode is VIDENC_ASPECT_RATIO_MANUAL */
    uint32_t denominator;              /* relevant only when the mode is VIDENC_ASPECT_RATIO_MANUAL */
} videnc_aspect_ratio_t;

typedef struct
{
    uint32_t                    picture_width;    /* the input frame width in pixels*/
    uint32_t                    picture_height;   /* the input frame height in pixels */
    videnc_chroma_format_t      chroma_format;    /* the input frame chroma format */
    videnc_aspect_ratio_t       aspect_ratio;     /* the input frame aspect ratio */    
    videnc_cadence_info_t       cadence;          /* the frame cadence info - interlaced frame only */
    videnc_frame_format_t       frame_format;     /* the input frame format (progressive or interlaced) */
    videnc_frame_buffer_desc_t  frame_buffers[2]; /* buffer descriptors of the input frame buffer(s) */
} videnc_input_frame_t;


typedef struct
{
    videnc_codec_specific_params_t codec_specific_params;
    videnc_encoder_codec_resources_t codec_resources;
} codec_specific_setting_t;


typedef struct
{
    uint32_t driver_buffer_id;
    uint32_t phys_codec_specific_settings;
} codec_specific_setting_desc_t;

typedef enum /* bit field */
{
    VIDENC_FW_WORKLOAD_SUCCESS                    = 0x00000000,
    VIDENC_FW_WORKLOAD_ERR_ITEMS_OVERFLOW         = 0x00000001, /* bit 0 - encoder detected overflow of currently allocated workload memory */
    VIDENC_FW_WORKLOAD_ERR_FLUSHED_FRAME          = 0x00000002, /* bit 1 - this is impartial or empty frame which was flushed by the encoder */
    VIDENC_FW_WORKLOAD_ERR_MISSING_FRM_SETTINGS   = 0x00000004, /* bit 2 - frame was not encoded because of some frame settings are missing */
    VIDENC_FW_WORKLOAD_ERR_INVALID_FRM_SETTINGS   = 0x00000008, /* bit 3 - invalid frame settings */
    VIDENC_FW_WORKLOAD_ERR_FATAL                  = 0x00000010  /* bit 4 - unspecified fatal error - the stream should be closed */
} videnc_fw_workload_status_t;

typedef enum /* bit field */
{
    VIDENC_FW_WORKLOAD_ATTR_NONE                   = 0x00000000,
    VIDENC_FW_WORKLOAD_ATTR_IDR_FRAME              = 0x00000001, /* bit 0 - the frame was encoded as IDR frame */
    VIDENC_FW_WORKLOAD_ATTR_PROGRESSIVE_I_FRAME    = 0x00000002, /* bit 1 - the frame was encoded as progressive I frame */               
    VIDENC_FW_WORKLOAD_ATTR_PROGRESSIVE_P_FRAME    = 0x00000004, /* bit 2 - the frame was encoded as progressive P frame */               
    VIDENC_FW_WORKLOAD_ATTR_PROGRESSIVE_B_FRAME    = 0x00000008, /* bit 3 - the frame was encoded as progressive B frame */               
    VIDENC_FW_WORKLOAD_ATTR_I_TOP_FIELD            = 0x00000010, /* bit 4 - the top field was encoded as I picture */                       
    VIDENC_FW_WORKLOAD_ATTR_P_TOP_FIELD            = 0x00000020, /* bit 5 - the top field was encoded as P picture */                       
    VIDENC_FW_WORKLOAD_ATTR_B_TOP_FIELD            = 0x00000040, /* bit 6 - the top field was encoded as B picture */                       
    VIDENC_FW_WORKLOAD_ATTR_I_BOTTOM_FIELD         = 0x00000080, /* bit 7 - the bottom field was encoded as I picture */                       
    VIDENC_FW_WORKLOAD_ATTR_P_BOTTOM_FIELD         = 0x00000100, /* bit 8 - the bottom field was encoded as P picture */                       
    VIDENC_FW_WORKLOAD_ATTR_B_BOTTOM_FIELD         = 0x00000200, /* bit 9 - the bottom field was encoded as B picture */                       
    VIDENC_FW_WORKLOAD_ATTR_FRAME_SKIPPED          = 0x00000400, /* bit 10 - the frame was encoded as skipped picture(s) */    
 } videnc_fw_workload_attr_t;

typedef struct
{
    uint32_t start_index;
    uint32_t num_of_items;
} items_section_t;

#define MAX_NUMBER_OF_ITEM_SECTIONS 10 // for h264 this should be greater or equal to MAX_SLICE (in pic) + 3

typedef struct
{
    uint32_t num_sections;  /* the driver sets this to 0 or 1. the fw add sections of encoded data. */
    items_section_t section[MAX_NUMBER_OF_ITEM_SECTIONS];
} videnc_wkld_sections_t;

typedef struct 
{
    videnc_wkld_sections_t   sections;
    videnc_workload_item_t   item[1]; /* place holder */
} videnc_items_payload_t;

typedef union
{
    videnc_items_payload_t items;
} videnc_wkld_payload;

typedef enum 
{
    VIDENC_GOP_CONTROL_MODE_FRAME = 0, /* Encode all pictures as frames */
    VIDENC_GOP_CONTROL_MODE_FIELD = 1, /* Encode all pictures as fields */
    VIDENC_GOP_CONTROL_MODE_PAFF  = 3  /* Automatically chooses between MODE_FRAME and MODE_FIELD for each frame. */
} GOP_ctrl_mode_t;

typedef struct
{
    /* FW input */
    videnc_input_frame_t          input_frame;      /* The input frame data */
    codec_specific_setting_desc_t codec_settings;   /* Codec specific settings buffer */
    uint32_t                      mfps;             /* Number of frame per second in units of 10^-3 fps */
    uint32_t                      bit_rate;         /* Target bit stream in Kbits/s */
    uint32_t                      max_bit_rate;     /* Maximal bit rate allowed in Kbits/s */
    GOP_ctrl_mode_t               gop_mode;         /* The output gop mode to use */
    uint32_t                      scd_threshold;      /* The threshold to use in the SCD algorithm when SCD is enabled */
    
    /* FW output */
    uint32_t                      status;           /* 'VIDENC_FW_WORKLOAD_SUCCESS' or combination of 'videnc_fw_workload_status_t' */
    uint32_t                      attributes;       /* 'VIDENC_FW_WORKLOAD_ATTR_NONE' or combination of 'videnc_fw_workload_attr_t' */    
    uint32_t                      removal_delay;    /* The removal delay in 90KHZ clock */
    uint32_t                      temporal_bitrate; /* The temporal output bit rate */ 
} videnc_wkld_header_t;

/* Descriptor for workload populated by host. This descriptor will be returned by the
FW on output queue. The FW will populate this workload with necessary metadata and 
information on what ES buffers were used to encode this frame.*/
typedef struct
{
    /* header (FW input-output) */
    videnc_wkld_header_t header;
    
    /* payload (FW input-output) */
    videnc_wkld_payload payload;         
}videnc_frm_wkld_t;

#define  WKLD_MIN_BUF_SIZE   0x1000 /* 4k */
#define  MAX_NUMBER_OF_ITEMS ((WKLD_MIN_BUF_SIZE - sizeof(videnc_frm_wkld_t)) / sizeof(videnc_workload_item_t))

#endif
