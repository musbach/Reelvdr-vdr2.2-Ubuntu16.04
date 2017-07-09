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

    BSD LICENSE 

    Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
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
#ifndef VIDDEC_FW_WORKLOAD_H
#define VIDDEC_FW_WORKLOAD_H

#include <stdint.h>
#include "viddec_fw_item_types.h"
#include "viddec_fw_frame_attr.h"
#include "viddec_fw_common_defs.h"

#define VIDDEC_WORKLOAD_FLAGS_ES_START_FRAME (1 << 0)
#define VIDDEC_WORKLOAD_FLAGS_ES_START_SLICE (1 << 1)
#define VIDDEC_WORKLOAD_FLAGS_ES_END_SLICE   (1 << 2)
#define VIDDEC_WORKLOAD_FLAGS_ES_END_FRAME   (1 << 3)

#define VIDDEC_FRAME_REFERENCE_IS_VALID   (0x1<<1)
// PIP Output Frame request bits
#define BLSB_VIDDEC_FRAME_REFERENCE_PIP_MODE  24
#define BMSK_VIDDEC_FRAME_REFERENCE_PIP_MODE  (0x3<<BLSB_VIDDEC_FRAME_REFERENCE_PIP_MODE)
#define VIDDEC_FRAME_REFERENCE_PIP_MODE_NORMAL     0x0
#define VIDDEC_FRAME_REFERENCE_PIP_MODE_W_HALF     0x1
#define VIDDEC_FRAME_REFERENCE_PIP_MODE_W_QUARTER  0x2
#define WORKLOAD_REFERENCE_FRAME (1 << 16)
#define WORKLOAD_SKIPPED_FRAME   (1 << 17)
/**
   Bitmask to indicate that this workload has range adjustment and needs a range_adjusted_out buffer for successful decode.
   Will be used for VC1 only.
*/
#define WORKLOAD_FLAGS_RA_FRAME   (1 << 21)
#define WORKLOAD_REFERENCE_FRAME_BMASK 0x000000ff

/*
  This structure is used to store the physical address and len of allocated user data buffer.
*/
typedef struct
{
    unsigned int id;                    /* Unique id for the buffer */
    unsigned int phys;                  /* Physical adress of buffer */    
    unsigned int len;                   /* Length of allocated buffer */
    unsigned int virt;                  /* Virt pointer of buffer not used by FW */
}viddec_fw_userdata_buffer_desc_t;

/*
  This structure is used for storing necessary user data statistics. This is populated by the
  FW for each frame. The host should initialize this structure to Zero before sending to FW.
*/
typedef struct
{
    unsigned int num_ud_items;          /* Number of packed user data items */
    unsigned int num_skipped_ud_items;  /* Number of skipped User data items */
    unsigned int skipped_ud_items_bytes;/* Number of bytes in skipped User Data items */
    unsigned int scratch;               /* scratch variable used only by FW */
}viddec_fw_userdata_buffer_stats_t;

/* User data descriptor provided in workload by Host*/
typedef struct
{
    viddec_fw_userdata_buffer_desc_t desc; /* Information releated to physical buffer */
    viddec_fw_userdata_buffer_stats_t stats; /* User data stats provided by FW */
}viddec_fw_userdata_buffer_t;

/* This structure represents the header of user data thats provided to Host.
   The FW will prepend this header for each user data type that was seen when
   decoding the current frame */
typedef struct
{
    unsigned int type;            /* User data type */
    unsigned int next_offset;     /* Next item_offset */
    unsigned int len;             /* length of payload */
    unsigned char payload[4];     /* First four bytes of payload to keep 4byte alignment*/
    /* This structure is ALLOC_EXTENDED with bytes of user data */
}viddec_fw_userdata_item_t;

typedef struct
{
    unsigned int id;                    /* Unique id for the buffer */
    unsigned int phys;                  /* Physical adress of buffer */    
    unsigned int len;                   /* Length of allocated buffer */
    unsigned int *virt;                  /* Virt pointer of buffer not used by FW */
}viddec_fw_reserved_nal_buffer_desc_t;

typedef struct
{
    unsigned int num_items;          /* Number of packed  items */
    unsigned int num_skipped_items;  /* Number of skipped  items */
    unsigned int skipped_items_bytes;/* Number of bytes in skipped  items */
    unsigned int scratch;               /* scratch variable used only by FW */
}viddec_fw_reserved_nal_buffer_stats_t;

typedef struct
{
    unsigned int type;            /* type */
    unsigned int next_offset;     /* Next item_offset */
    unsigned int len;             /* length of payload */
    unsigned char payload[4];     /* First four bytes of payload to keep 4byte alignment*/
    /* This structure is ALLOC_EXTENDED with bytes */
}viddec_fw_reserved_nal_item_t;


typedef struct
{
    viddec_fw_reserved_nal_buffer_desc_t desc; /* Information releated to physical buffer */
    viddec_fw_reserved_nal_buffer_stats_t stats; /* User data stats provided by FW */
}viddec_fw_reserved_nal_t;

/** Frame reference information to pass to video decoder  when performing a workload (frame decode)  */
typedef struct viddec_frame_reference
{
    signed int   driver_frame_id;
    unsigned int luma_phys_addr;
    unsigned int chroma_phys_addr;
    int internal_id; /* Used by workload manager only */
}viddec_frame_reference_t;

typedef struct
{
   unsigned int parse;
   unsigned int decode;
   unsigned int sw_dec_ovhd;
}viddec_fw_perf_t;

/** This structure contains all the information required  to fully decode one frame of data  */
/**
    num_error_mb: This field is populated at the output of the decoder.
                  Currently, its valid only for MPEG2.
                  For other codecs, it defaults to 0.

    range_adjusted_out:	Frame buffer needed to store range adjusted frames for VC1 only.
                        Range adjustment in VC1 requires that the luma/chroma values in the decoded frame be modified
                        before the frame can be displayed. In this case, we need a new frame buffer to store he adjusted values.
                        The parser will indicate this requirement by setting the WORKLOAD_FLAGS_RA_FRAME bit in the 
                        is_reference_frame of the workload. The decoder expects this field to be valid when range adjustment
                        is indicated and populates this frame buffer along with frame_out.

    Expectation from user:
                        Before feeding workload to the decoder, do the following:
                           If pip is indicated/needed, 
                              provide the pip_out buffer
                           If range adjustment is indicated (WORKLOAD_FLAGS_RA_FRAME bit in is_reference_frame is set), 
                              provide range_adjusted_out buffer
                           Provide frame_out buffer.

                        After workload is returned from the decoder, do the following:
                           If pip is indicated, 
                              display the pip_out buffer
                           Else If range adjustment is indicated, 
                              display range_adjusted_out buffer
                           Else 
                              display frame_out buffer.
*/
typedef struct viddec_workload
{
   enum viddec_stream_format codec;
   signed int                is_reference_frame;
   unsigned int              result;
   unsigned int              num_items;/* number of viddec_workload_item_t in current workload */
   unsigned int              num_error_mb; /* Number of error macroblocks in the current picture. */
   viddec_fw_perf_t          time;
   viddec_frame_attributes_t attrs;

   viddec_frame_reference_t  frame_out;   /* output frame */
   viddec_frame_reference_t  range_adjusted_out;   /* for VC1 only */
   viddec_frame_reference_t  pip_out;     /* PIP Buffer */

   viddec_fw_userdata_buffer_t user_data;  /* User data Buffer */
   viddec_fw_reserved_nal_t resvd_nal_data;  /* Nal data Buffer */ 
   /* Alignment is needed because the packing different between host and vSparc */
   __attribute__ ((aligned (16))) viddec_workload_item_t   item[1];

   /* ------------------------------------------------------ */
   /* ------------------------------------------------------ */
   /* ------------------------------------------------------ */
   /* This structure is ALLOC_EXTENDED with workload_items   */
   /* ------------------------------------------------------ */
   /* ------------------------------------------------------ */
   /* ------------------------------------------------------ */
} viddec_workload_t;

#endif /* VIDDEC_WORKLOAD_H */
