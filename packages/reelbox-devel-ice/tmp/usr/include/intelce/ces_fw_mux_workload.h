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

#ifndef _MUX_FW_WORKLOAD_H_
#define _MUX_FW_WORKLOAD_H_

#include "ces_fw_mux_common_defs.h"

/************************************************************************************
*  Inband messags:
************************************************************************************/

typedef enum mux_io_buffer_type {
   MUX_WORKLOAD_INVALID   = 0x00, /* Unknown type */
   MUX_WORKLOAD_ES              , /* Elementry stream buffer */
   MUX_WORKLOAD_TS              , /* Buffer holding TS packets */
   MUX_WORKLOAD_PSI             , /* PSI sections to be inserted to the muxed stream */
   MUX_WORKLOAD_TIMING_PARAMS   , /* Parameters for timing data insertion e.g. for claculating PCR */

   MUX_OUTPUT_BUFFER      , /* A buffer holding muxed data*/

   MUX_IO_BUFFER_TYPE_MAX         /* Should always be last*/
} mux_io_buffer_type_t;

/** 
   mux_io_flags flags may appear in the lower 16 bits of the flags parameter of 
   an async message. These flags are used by the FW or driver to signal I/O buffer 
   management information. The following enum describes the bit number of each flag.
*/
typedef enum mux_io_flags{
   /**
      The driver should use this flag when sending the last workload of a 
      stream. This flag means that the last byte of the buffer assicuated with the
      workload is the last byte to be muxed. The FW is expected to copy this flag
      to the output buffer holding the last data byte muxed.
   */
   MUX_FLAG_EOS          = 0,
   
   /**
      The driver should use this flag on a workload that has data associated 
      with some user given tag. This flag means that the first byte of the buffer 
      assicuated with the workload is associated with a tag.
      The FW is expected to mux the first byte of this workload into a new 
      output buffer, copy this flag to the new output buffer and set the 
      input_ref_id to the value of teh driver_id of the workload carrying the flag.
   */
   MUX_FLAG_TAG          = 1,
   
   /**
      The driver may use this flag on a workload to indicate to the FW that 
      the workload should be stored and not outputed until explicitly requested to do
      so (via trhe MUX_FLAG_RELEASE_WKLD) or until flush has been called.
      (example: PSI workloads that have non-zero interval).
   */
   MUX_FLAG_STORE_WKLD   = 2,
   
   /**
      The driver may use this flag on a workload to indicate to the FW that 
      a previously stored workload needs to be released and outputted to the 
      output queue. The workload to be released is identified by the driver_id
      field of the async message.
   */
   MUX_FLAG_RELEASE_WKLD = 3,

   /**
      The FW may use this flag on a workload to indicate that an error has occurred
      during the attempt to process the associated workload. 
   */
   MUX_FLAG_ERROR        = 4,

   /**
      The FW may use this flag on a workload to indicate that a workload has not
      been processed at all by the FW (for example: on a workload in the FW input
      queue that has been outputted during a call to flush).
   */
   MUX_FLAG_UNPROCESSED  = 5,
   /*up to 16 flags are supported*/
} mux_io_flags_t;

/* Macros to get and set buffer-type and io-flags uint16 subfields of the uint32 "flags" field in ipc_msg_data */ 
#define MUX_MSG_BUFTYPE_GET(msg_flags) ((((msg_flags) & 0xFFFF0000) >> 16) & 0x0000FFFF)
#define MUX_MSG_IOFLAG_GET(msg_flags, ioflag) (((msg_flags) >> ioflag) & 1)
#define MUX_MSG_IOFLAG_GET_ALL(msg_flags) ((msg_flags) & 0x0000FFFF)

#define MUX_MSG_BUFTYPE_SET(msg_flags, buftype) ((msg_flags) = ((msg_flags) & 0x0000FFFF) | (((buftype) << 16) & 0xFFFF0000))
#define MUX_MSG_IOFLAG_SET(msg_flags, ioflag) (msg_flags |= (1 << (ioflag)))
#define MUX_MSG_IOFLAG_CLEAR(msg_flags, ioflag) (msg_flags &= ~(((uint32_t)(1<< (ioflag)))))
#define MUX_MSG_IOFLAG_CLEAR_ALL(msg_flags) (msg_flags &= 0xFFFF0000)

/** The maximum number of worloads that can be stored by the mux FW for periodic
processing (e.g. PSI and TS workload that are inserted on driver defined intervals)*/
#define MUX_FW_WORKLOAD_STORE_MAX  8

/************************************************************************************
*  MUX IO buffer structs:
************************************************************************************/
typedef struct mux_workload_es {
   mux_uint64_t          time_per_byte;/* Time Per Byte calculated by the driver according to recieved bit_rate from the AV encoders*/
   mux_uint64_t          underflow_per_byte;/* Underflow Per Byte calculated by the driver in CBR mode according to recieved bit_rate from the AV encoders*/
   uint32_t              pid;/* Identifier associated with given ES*/
   uint32_t              phys; /*physical address of the ES buffer*/
   uint32_t              length /*length of the ES buffer*/;
   uint32_t              driver_id; /*id used by the driver. FW should not use or modify this.*/
   uint32_t              au_start; /*If this flag is not 0, this ES is the first of a new AU*/
   mux_time_stamp_t      pts;/* Presentation time stamp value. Only relevant if (au_start!=0)*/
   mux_time_stamp_t      dts;/* Decoding time stamp value, if no DTS expecting all 0xFF. Only relevant if (au_start!=0)*/
   mux_time_stamp_t      ats;/* Arrival time stamp value, if no ATS expecting all 0xFF. Only relevant if (au_start!=0)*/
   mux_uint64_t          clock_offset; /* Requested offset between the PTS/DTS and the system clock (shifted 27MHz). Only relevant if (au_start!=0)*/
   uint32_t              stream_id; /* Translated by driver from stream type, identifies content of the AU. Only relevant if (au_start!=0)*/
   uint32_t              new_au_size; /*Size of new  AU. Only relevant if (au_start!=0)*/
   uint32_t              copyright;  /* When set to '1' it indicates that the material of the associated PES packet payload is protected by copyright , 0 otherwise */
	/*make sure to keep 8-byte alignment*/ 
} mux_workload_es_t;

typedef struct mux_workload_ts {
   uint32_t              pid;/* Identifier associated with given TS*/
   uint32_t              phys; /*physical address of the TS buffer*/
   uint32_t              length; /*length of the TS buffer*/
   uint32_t              driver_id; /*id used by the driver. FW should not use or modify this.*/
   uint32_t              ts_packet_length; /*Size in bytes of each TS packet in the buffer.*/
   mux_uint64_t          interval;/* Reinsertion interval (shifted 27MHz). Value of 0 indicates single insertion */
   uint32_t              time_stamp_avail; /*A flag stating a time stamp is available with this workload*/ 
   mux_time_stamp_t      pts;/* Presentation time stamp value. Only relevant if (time_stamp_avail!=0)*/
   mux_time_stamp_t      dts;/* Decoding time stamp value, if no DTS expecting all 0xFF. Only relevant if (time_stamp_avail!=0)*/
   mux_time_stamp_t      ats;/* Arrival time stamp value, if no ATS expecting all 0xFF. Only relevant if (au_start!=0)*/
   mux_uint64_t          clock_offset; /* Requested offset between the PTS/DTS and the system clock (shifted 27MHz). Only relevant if (time_stamp_avail!=0)*/
   mux_uint64_t          start_time; /*The time (shifted 27MHz) to start inserting the TS packets*/
   mux_uint64_t          end_time; /*The time (shifted 27MHz) to stop inserting the TS packets*/
} mux_workload_ts_t;


typedef enum mux_psi_type {
   MUX_PSI_INVALID   = 0x00,
   MUX_PSI_PAT       = 0x01,
   MUX_PSI_PMT       = 0x02,
   MUX_PSI_CAT       = 0x03,
   MUX_PSI_NIT       = 0x04,
   MUX_PSI_PRIVATE   = 0x05
} mux_psi_type_t;

typedef struct mux_workload_psi {
  mux_psi_type_t        type; /* Type of program specific information*/
  uint32_t              pid;  /* The pid to be associated with this data*/
  mux_uint64_t          interval;/* Reinsertion interval. Value of 0 indicates single insertion */
  uint32_t              phys; /*physical address of the buffer holding the PSI data*/
  uint32_t              length /*length of the buffer*/;
  uint32_t              driver_id; /*id used by the driver. FW should not use or modify this.*/
  uint32_t              reserved; /*for keeping 8-byte alignment*/    
} mux_workload_psi_t;

typedef enum mux_bitrate_type {
   MUX_BITRATE_CBR = 0x0,
   MUX_BITRATE_VBR = 0x1,
   MUX_BITRATE_TYPE_MAX
} mux_bitrate_type_t;

typedef struct mux_workload_timing_params {
  uint32_t                    clock_reference_pid; /*The pid whose AU boundries will be used as indications to advance the clock. (0 means all pids)*/
  mux_bitrate_type_t          bitrate_type; /*VBR or CBR of resulting stream*/
  uint32_t                    pcr_pid; /* The pid of the TS packet carrying the PCR*/
  uint32_t                    pcr_pid_carries_es; /*0 means that the PCR_PID is not used for carrying any ES data. 1 otherwise*/
  mux_uint64_t                pcr_interval;/*Time interval between PCRs (shifted 27MHz)*/
  mux_uint64_t                time_per_packet; /*Time (shifted 27MHz) per packet according to desired bit rate (relevant only for CBR)*/
  mux_uint64_t                pcr_field_time_adjustment; /*Time (shifted 27MHz) per 11 bytes (relevant only for CBR)*/  
} mux_workload_timing_params_t;
   

typedef struct mux_output_buffer {
  uint32_t  phys; /*physical address of the buffer holding the muxed data*/
  uint32_t  length /*length of the buffer*/;
  uint32_t  level; /*length of data in the buffer (level <= length)*/
  uint32_t  driver_id; /*id used by the driver. FW should not use or modify this.*/
  uint32_t  input_ref_id;/*the id of the input buffer (ES/PSI/TS...) realting to the
                            data of the first none null packet in the buffer*/
  uint32_t  reserved; /*for keeping 8-byte alignment*/                              
} mux_output_buffer_t;

typedef union mux_input_workload {
      mux_workload_es_t             es;
      mux_workload_ts_t             ts;
      mux_workload_psi_t            psi;
      mux_workload_timing_params_t  timing;      
}mux_input_workload_t ;


/*A general struct to hold any kind of mux FW workload */
typedef struct mux_workload
{   
   mux_io_buffer_type_t    type;
   uint32_t                flags;
   mux_input_workload_t    input_wkld;
}  mux_workload_t;

#endif //_MUX_FW_WORKLOAD_H_
