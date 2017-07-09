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

#ifndef MUX_FW_DEFS_H
#define MUX_FW_DEFS_H

#include "stdint.h"

#ifndef NULL
#define NULL (void*)0x0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define MUX_FW_INVALID_VAL 0xFFFFFFFF

/*Shift of 27Mhz clock used by the mux_fw, for achieving better timing accuracy*/
#define MUX_CLOCK_RESOLUTION_SHIFT 10

#define MUX_FW_EMPTY_OUTBUFF_QUEUE_DEPTH  32
#define MUX_FW_WKLD_QUEUE_DEPTH           32
#define MUX_FW_OUTPUT_QUEUE_DEPTH         32

/* Container format defined for the stream */
typedef enum 
{
   MUX_FW_CONTAINER_FORMAT_MPEG_TS        = 0,
   MUX_FW_CONTAINER_FORMAT_BDAV           = 1,
   MUX_FW_CONTAINER_FORMAT_MAX          /* must be last  */
} mux_stream_container_format_t;

/* Stream priority that effects scheduling*/
typedef enum
{
    MUX_FW_STREAM_PRIORITY_BACKGROUND = 0,
    MUX_FW_STREAM_PRIORITY_REALTIME   = 1,
    MUX_FW_STREAM_PRIORITY_MAX
} mux_stream_priority_t;

/* Defines for attributes on stream, If not set explicitly will be default values */
typedef enum
{ 
    MUX_FW_ATTRIBUTE_EMPTY_OUT_Q_WMARK,   /* Define for setting input empty output buffer queue watermarks */
    MUX_FW_ATTRIBUTE_WKLD_Q_WMARK, /* Define for setting input WKLD queue watermarks */
    MUX_FW_ATTRIBUTE_STREAM_PRIORITY,         /* Define for setting stream priority. should be one of the items in 'mux_stream_priority_t' */
    MUX_FW_ATTRIBUTE_MAX
}mux_fw_stream_attributes_t;

/* Defines for interrupt mask and status */

/** Interrupt realted enum*/
typedef enum
{
    MUX_FW_DISABLE_ALL_INTERRUPTS                  = 0x00000000, /* No interrupts. used to mask all the interrupts */
    MUX_FW_WKLD_OUTPUT_AVAIL                       = 0x00000001, /* A processed workload or output buffer is available */
    MUX_FW_WKLD_INPUT_WATERMARK_REACHED            = 0x00000002, /* The workload input queue reached a watermark*/
    MUX_FW_EMPTY_BUFFER_INPUT_WATERMARK_REACHED    = 0x00000004, /* The empty output buffer input queue reached a watermark*/
    MUX_FW_ENABLE_ALL_INTERRUPTS                   = 0x00000007  /* Enable all interrupts. This is the default option when the stream is created */
}mux_fw_int_t;

typedef struct mux_uint64{
   uint32_t hi;
   uint32_t lo;
} mux_uint64_t;


/* MUX queue status data.*/
typedef struct
{
   uint32_t workload_q_space;    /* Num of workload messages that can be written to input queue */
   uint32_t empty_outbuff_q_status; /* Number of free output buffers messages that can be written to input queue */
   uint32_t output_q_data;    /* Num of messages in output queue */
}mux_fw_q_status_t;

typedef struct mux_time_stamp
{
   /*33 bit time stamp in 90KHz resolution (sys clock divided by 300). As used in PTS/DTS*/
   uint32_t    b_0_31; /* bits 0 to 31*/
   uint32_t    b_32; /*bit 32*/
} mux_time_stamp_t;

#define MUX_TIME_STAMPS_EQUAL(ts1,ts2) ((ts1.b_0_31==ts2.b_0_31)&&(ts1.b_32==ts2.b_32))                                           

typedef struct mux_time_stamp_extended
{
   /*33 bit time stamp with 9 bit remainder for stamping in 27MHz resolution*/
   mux_time_stamp_t  base; /*33 bit time stamp in sys clock divided by 300 (90KHz)*/
   uint32_t          remainder; /*9 bit remainder. Units if sys clock resolution(27MHz)*/
} mux_time_stamp_extended_t;

typedef mux_time_stamp_t mux_pts_t;
typedef mux_time_stamp_t mux_dts_t;

#endif //MUX_FW_DEFS_H

