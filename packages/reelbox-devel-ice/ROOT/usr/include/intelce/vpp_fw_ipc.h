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

#ifndef _VPP_FW_IPC_H_
#define _VPP_FW_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dpe_common.h"
#include "fw_ipc.h"

/** @defgroup vpp_fw_ipc_defs VPP Firmware IPC Definitions */
/** @ingroup vpp_fw_ipc_defs */
/*@{*/

/** This synchronization message indicates to the host that the firmware is
now executing the main program and is set by firmware through the host
doorbell. */
#define VPP_FW_IPC_HOST_SYNC   0x12345678
#define VPP_FW_IPC_HOST_INT    0x87654321

typedef enum
{/* This enumeration defines existing priorities for a stream */
    VPP_FW_IPC_LOW,           /* Lowest priority */
    VPP_FW_IPC_HIGH,          /* Highest priority */
} vpp_fw_ipc_stream_priority;

typedef enum
{/** This enumeration lists the state of a stream. */
    VPP_FW_IPC_STREAM_UNINIT,   /** Stream is not yet opened. */
    VPP_FW_IPC_STREAM_STOP,     /** Stream is initialised but not active. */
    VPP_FW_IPC_STREAM_START,    /** Stream is currently active. */
} vpp_fw_ipc_stream_state_t;

/** This structure is used to initialize the selected scaler tables to be shared
by all streams. */
typedef struct {
   enum
   {/** Selection of scaler table to be updated. */
      VPP_FW_IPC_INIT_SCALERS_HSC_Y,
      VPP_FW_IPC_INIT_SCALERS_HSC_UV,
      VPP_FW_IPC_INIT_SCALERS_VSC_Y,
      VPP_FW_IPC_INIT_SCALERS_VSC_UV,
      VPP_FW_IPC_INIT_SCALERS_MAX
   } table_id;

    uint32_t table_count; /* Number of tables to support uniformly spaced scaling of selected scaler. */
   /** Table of system addresses pointing to each set of packed, fixed-point
   filter coefficients used for selected scaler. */
   uint32_t table_base_addr;
   uint32_t table_size;
} vpp_fw_ipc_init_scalers_t;

typedef enum
{/** Selection of available Int masks */
    VPP_FW_INT_PENDING          = 1 << 0,
    VPP_FW_OUT_DATA_AVAILABLE   = 1 << 1,
    VPP_FW_INP_LOW_WATERMARK    = 1 << 2,
    VPP_FW_INP_HIGH_WATERMARK   = 1 << 3,
} int_status;


typedef enum {
    VPP_FW_PARAM_DEBUG_BASE = 0,
    VPP_FW_PARAM_NRF_LEVEL,
    VPP_FW_PARAM_RNR_LEVEL,
    VPP_FW_PARAM_MAX
} vpp_fw_param_t;

/** This structure is used to set Interrupt mask for a stream. */
typedef struct {
    uint32_t status; /* status of Int for current stream */
    uint32_t mask;   /* Mask of above status bits */
} vpp_fw_ipc_stream_int_state_t;

/** This structure is used to set watermarks for a stream. */
typedef struct {
    uint32_t low;    /* Low water mark value */
    uint32_t high;   /* High watermark value */
} vpp_fw_ipc_stream_watermark_t;


/** This structure is the header used to transport data between host software
and firmware via the message-queue mechanism. */
typedef struct {
   enum
   {/** Identification of queued message. */
      VPP_MSG_PING_FW,         /** Command to ping firmware. */
      VPP_MSG_PROCESS_PICTURE, /** Command to execute vpp_fw_core_process_picture. */
   } msg_id;

   dpe_result_t result;       /** Result of request to firmware. */
   uint32_t time_elapsed;     /** Time spent processing request. */
   uint32_t data[4];          /** Return data from FW for a message.*/
   void *handle;              /** Handle provided by host. */
} vpp_fw_ipc_msg_header_t;

/** This structure is used to initialize the JLCCE tables shared
by all streams. */
typedef struct {
   /** Selection of jlcce table to be updated. */
   dpe_jlcce_table_id_t table_id;
  
   uint32_t table_count; /* Number of tables to load */
   uint32_t table_base_addr;
   uint32_t table_size;
} vpp_fw_ipc_init_jlcce_table_t;

/** This structure defines parameters to open a stream context */
typedef struct {
   uint32_t stream_id;
   uint32_t ipc_addr;
   uint32_t ipc_size;
   uint32_t cxt_addr;
   uint32_t cxt_size;
} vpp_fw_ipc_open_param_t;

/** This structure defines the general fw information */
typedef struct {
   uint32_t major;
   uint32_t minor;
   uint32_t build;
   uint32_t cxt_size;
   uint32_t num_streams_supported;
} vpp_fw_ipc_query_info_t;


/** This structure is used to transport data between host software and firmware
via the synchronous message mechanism.  The following custom structure must be
similar to the structure struct _IPC_SynchronousMessage defined in ipc_shared.h.
*/
typedef struct {
   enum
   {/** Identification of synchronous message. Must be listed first. */
      VPP_SYNC_MSG_REG_READ = 0x80 | (IPC_SYNCMESSAGE_COMMAND_MARKER),  /** Command to execute vpp_reg_read. */
      VPP_SYNC_MSG_REG_WRITE,                                           /** Command to execute vpp_reg_write. */
      VPP_SYNC_MSG_INITIALIZE,                                          /** Command to execute vpp_fw_core_initialize. */
      VPP_SYNC_MSG_SET_STREAM_STATES,                                   /** Command to execute vpp_fw_core_set_stream_states. */
      VPP_SYNC_MSG_SET_RNR_LEVEL,                                       /** Command to execute vpp_fw_core_set_rnr_level. */
      VPP_SYNC_MSG_SET_NRF_LEVEL,                                       /** Command to execute vpp_fw_core_set_nrf_level. */
      VPP_SYNC_MSG_GET_STREAM_STATE,                                    /** Command to execute vpp_fw_core_get_stream_state. */
      VPP_SYNC_MSG_INIT_SCALERS,                                        /** Command to execute vpp_fw_core_init_scalers. */
      VPP_SYNC_MSG_SET_PRORITY,                                         /** Command to set priority for a queue */
      VPP_SYNC_MSG_GET_PRORITY,                                         /** Command to get priority for a queue */
      VPP_SYNC_MSG_SET_WATERMARKS,                                      /** Command to set watermarks for a stream */
      VPP_SYNC_MSG_FLUSH_STREAM,                                        /** Command to flush a stream */
      VPP_SYNC_MSG_BLACK_FRAME,                                         /** Command to set a black frame */
      VPP_SYNC_MSG_SET_PARAM,                                           /** Command to set a parameter */
      VPP_SYNC_MSG_GET_PARAM,                                           /** Command to get a parameter */
      VPP_SYNC_MSG_INIT_JLCCE_TABLE,                                    /** Command to initialize JLCCE tables */
      VPP_SYNC_MSG_SET_MODE,                                            /** Command to set fw mode (legacy or ADP mode) */
      VPP_SYNC_MSG_PING_FW,                                             /** Command to ping fw */
      VPP_SYNC_MSG_OPEN_STREAM,                                         /** Command to open a stream context */
      VPP_SYNC_MSG_CLOSE_STREAM,                                        /** Command to close a stream context */
      VPP_SYNC_MSG_QUERY_FW                                             /** Command to query fw info */
   } sync_msg_id;

   dpe_result_t result;       /** Result of request to firmware. */
   uint32_t time_elapsed;     /** Time spent processing request. */

   union {
      union {
         struct {
            uint32_t offset;
         } send;
         struct {
            uint32_t value;
         } reply;
      } reg_read;             /** Data for VPP_SYNC_MSG_REG_READ. */
      union {
         struct {
            uint32_t offset;
            uint32_t value;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } reg_write;            /** Data for VPP_SYNC_MSG_REG_WRITE. */
      union {
         struct {
			 uint32_t value;
             dpe_si_version_t si_version;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } initialize;           /** Data for VPP_SYNC_MSG_INITIALIZE. */
      union {
         struct {
            uint32_t stream_ids;
            vpp_fw_ipc_stream_state_t stream_state;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } set_stream_states;    /** Data for VPP_SYNC_MSG_SET_STREAM_STATES. */
      union {
         struct {
            uint32_t stream_id;
         } send;
         struct {
            vpp_fw_ipc_stream_state_t stream_state;
         } reply;
      } get_stream_state;     /** Data for VPP_SYNC_MSG_GET_STREAM_STATE. */
      union {
         struct {
            vpp_fw_ipc_init_scalers_t scalers;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } init_scalers;         /** Data for VPP_SYNC_MSG_INIT_SCALERS. */
      union {
         struct {
             uint32_t stream_id;
             vpp_fw_ipc_stream_priority priority;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } set_stream_priority;     /** Data for VPP_SYNC_MSG_SET_PRORITY. */
      union {
         struct {
             uint32_t stream_id;
         } send;
         struct {
             vpp_fw_ipc_stream_priority priority;
         } reply;
      } get_stream_priority;     /** Data for VPP_SYNC_MSG_GET_PRORITY. */
      union {
         struct {
             uint32_t stream_id;
             vpp_fw_ipc_stream_watermark_t mask;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } set_watermarks;     /** Data for VPP_SYNC_MSG_SET_WATERMARK. */
      union {
         struct {
			 uint32_t value;
         } send;
         struct {
             uint32_t addr;
         } reply;
      } get_shd_mem_ptr;  /** Data for VPP_SYNC_MSG_SET_PRORITY. */
      union {
         struct {
             uint32_t stream_id;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } flush_stream;  /** Data for VPP_SYNC_MSG_FLUSH_STREAM. */
      union {
         struct {
             uint32_t stream_id;
             uint32_t rnr_level;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } rnr_level;  /** Data for VPP_SYNC_MSG_SET_RNR_LEVEL. */
      union {
         struct {
             uint32_t stream_id;
             uint32_t nrf_level;
         } send;
         struct {
			 uint32_t value;
         } reply;
      } nrf_level;  /** Data for VPP_SYNC_MSG_SET_NRF_LEVEL. */
      union {
         struct {
             uint32_t pict[128];
         } send;
         struct {
			 uint32_t value;
         } reply;
      } set_blk_frame;  /** Data for VPP_SYNC_MSG_SET_PRORITY. */
      union {
          struct {
              uint32_t param_name;
              uint32_t param_value1;
              uint32_t param_value2;
          } param_data;
      } param_data;
      union {
         struct {
            vpp_fw_ipc_init_jlcce_table_t tables;
         } send;
      } init_jlcce_table;         /** Data for VPP_SYNC_MSG_INIT_JLCCE_TABLE. */
      union {
         struct {
            uint32_t stream_id;
            uint32_t is_adp_mode;
         } send;
      } set_mode;    /** Data for VPP_SYNC_MSG_SET_MODE. */
      union {
         struct {
            uint32_t stream_id;
            uint32_t phys_addr;
            uint32_t size;
         } send;
      } set_shared_mem;    /** Data for VPP_SYNC_MSG_SET_SHARED_MEM. */
      union {
         struct {
            uint32_t stream_id;
            uint32_t cxt_addr;
            uint32_t cxt_size;
         } send;
      } open_stream;    /** Data for VPP_SYNC_MSG_OPEN_STREAM. */
      union {
         struct {
            uint32_t stream_id;
         } send;
      } close_stream;    /** Data for VPP_SYNC_MSG_CLOSE_STREAM. */
      union {
         struct {
            vpp_fw_ipc_query_info_t fw_info;
         } reply;
      } query_fw;    /** Data for VPP_SYNC_MSG_QUERY_FW. */
      union {
          uint32_t dummy_data[128]; /* Dummy data to force size */
      }dummy;
   } data;
} vpp_fw_ipc_sync_msg_t;

/** This structure defines the shared data memory between host and firmware.
Should be instantiated as volatile. */
typedef struct {
   /** Synchronous message data.  Must be listed first. */
    vpp_fw_ipc_sync_msg_t sync_msg;
    /** Shared status and mask for Host and Fw. Should always be after sync message */
    vpp_fw_ipc_stream_int_state_t  int_status[VPP_FW_SUPPORTED_STREAMS];
    vpp_fw_ipc_stream_watermark_t  watermark[VPP_FW_SUPPORTED_STREAMS];
    /** Handle for IPC mechanism. */
    FW_IPC_Handle fwipc;
    void *blk_frame_cxt;
    volatile unsigned int dbg_buf[19];
} vpp_fw_host_dmem_t;


typedef enum
{
    VPP_FMD_NONE = 0,
    VPP_FMD_NORMAL,
    VPP_FMD_FORCE,
}vpp_fw_fmd_mode;

typedef enum
{
    VPP_SCALER_FLAG_FORCE_HSC_Y_TABLE_UPDATE=1,
    VPP_SCALER_FLAG_FORCE_VSC_Y_TABLE_UPDATE=2,
    VPP_SCALER_FLAG_FORCE_HSC_UV_TABLE_UPDATE=4,
    VPP_SCALER_FLAG_FORCE_VSC_UV_TABLE_UPDATE=8,
    VPP_SCALER_FLAG_ANAMORPHIC=0x10,
    VPP_SCALER_FLAG_DEGRADING_ACTIVE=0x20,
    VPP_OUTPUT_10BIT_ENABLE=0x40,
    VPP_AUTO_FMD_32322_23322_BYPASS=0x80,
    VPP_AUTO_FMD_32_BYPASS=0x100,
    VPP_AUTO_FMD_2224_2332_BYPASS=0x200,
    VPP_AUTO_FMD_22_BYPASS=0x400,
    VPP_AUTO_FMD_33_BYPASS=0x800,
    VPP_AUTO_FMD_ETC_BYPASS=0x1000,
    VPP_DISABLE_MAD_MOTION_DETECTION=0x2000,
    VPP_10BIT_PIPELINE=0x4000,
}  vpp_fw_flag;

typedef struct
{
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    uint32_t start_x;
    uint32_t end_x;
    uint32_t start_y;
    uint32_t end_y;
}vpp_pic_rect;

typedef struct {
    etDpeFmdCadence seq;
    uint32_t start;
    etDpeProcPictResult rx_result;
    uint32_t cad_index;
}vpp_fw_msg_process_pict_frame_info_t;

typedef enum {
   VPP_OUTPUT_FORMAT_YUV422 = 0,
   VPP_OUTPUT_FORMAT_YUV444,
   VPP_OUTPUT_FORMAT_YUY2,
   VPP_OUTPUT_FORMAT_YUV420
} vpp_fw_dma_mode_t;

/** This structure defines parameters to process a picture context per
    stream. */
typedef struct {
    /** Message header for IPC. */
    vpp_fw_ipc_msg_header_t mh;
    vpp_pic_rect src;
    vpp_pic_rect dest;
    uint32_t g_hsc_sip;
    uint32_t g_vsc_sip;
    uint32_t g_hsc_tnp;
    uint32_t g_vsc_tnp;
    uint32_t g_hsc_bank1_sel;
    uint32_t g_vsc_bank1_sel;
    uint32_t g_region1_start_isf;
    //uint32_t g_yuy2_output;
    uint32_t g_420_input;
    uint32_t g_even_field;
    uint32_t g_interlaced_input;
    uint32_t g_spatial_only;
    uint32_t g_di_temporal_8_bit_mode;
    uint32_t g_dma_8_bit_mode;
    uint32_t g_dma_8_bit_mode_input;
    uint32_t g_dma_8_bit_mode_output;
    uint32_t g_pipmode;
    uint32_t g_bypass_fgt;
    uint32_t g_bypass_y_fgt;
    uint32_t g_bypass_u_fgt;
    uint32_t g_bypass_v_fgt;
    uint32_t g_bypass_rnr;
    uint32_t g_enable_422;
    uint32_t g_bypass_422;
    uint32_t g_bypass_di;
    uint32_t g_enable_di;
    vpp_fw_fmd_mode fmd_mode;
    uint32_t g_bypass_nrf;
    uint32_t g_bypass_spatial_nrf;
    uint32_t g_enable_prog_weights;
    uint32_t g_di_weights;
    uint32_t g_const_history;
    uint32_t g_sdi_black_spatial;
    uint32_t g_enable_hsc;
    uint32_t g_enable_vsc;
    uint32_t g_bypass_vsc;
    uint32_t g_pad_zeros_lsb;

    uint32_t g_np1_y_top_field_addr;
    uint32_t g_np1_uv_top_field_addr;
    uint32_t g_np1_y_bot_field_addr;
    uint32_t g_np1_uv_bot_field_addr;    
    uint32_t g_nm1_yuv_pic_start_addr;
    uint32_t g_n_yuv_pic_start_addr;
    uint32_t g_np1_yuv_pic_start_addr;
    uint32_t g_n_mh_pic_start_addr;
    uint32_t g_nm1_mh_pic_start_addr;
    uint32_t g_n_y_w_pic_start_addr;
    uint32_t g_n_uv_w_pic_start_addr;
    
    uint32_t g_nm1_yuv_rview_pic_start_addr;
    uint32_t g_n_yuv_rview_pic_start_addr;
    uint32_t g_np1_yuv_rview_pic_start_addr;
    uint32_t g_n_mh_rview_pic_start_addr;
    uint32_t g_nm1_mh_rview_pic_start_addr;    
    /* temporarily used to force a depth of two in the FW */

    /** frame packing format */
    uint32_t frm_packing_fmt;
    uint32_t right_shift_for_right_view;
    uint32_t down_shift_for_bottom_view;

    /** Stream identification. */
    uint32_t stream_id;
    uint32_t unique_id;
    uint32_t field_index;
/* Host specific defines not used by Fw */
    uint32_t first_field_interlaced_passthrough;
    uint32_t first_deinterlaced_frame;
    uint32_t output_buf_id;
    uint32_t input_buf_id;
    uint32_t alternate_deinterlaced_frame;

   //Export deinterlace control
    int32_t mad_threshold_delta;   //MAD threshold delta value
    int32_t nrf_level_shift;       //twshift=swshift=noiseFilterWshift
    int32_t g_enable_hsc_dering;
    int32_t g_enable_vsc_dering;
   /* scaler table update flag */
    uint32_t g_dpe_flags;

   /** scaler coeff table index shift */
   int32_t hsc_idxshift_y;    //horizontal Y
   int32_t hsc_idxshift_uv;   //horizontal UV
   int32_t vsc_idxshift_y;    //vertical Y
   int32_t vsc_idxshift_uv;   //vertical UV

   /** Horizontal inverse scale factor for anamorphic */
   uint32_t inverse_scale_factor;

   vpp_fw_dma_mode_t output_pixel_format;  /* the output dma mode */
   
   uint32_t g_bypass_jlcce;                      /* bypass JLCCE */
   uint32_t g_bypass_sharpness;                    /* bypass Sharpness */
   uint32_t is_xvYcc;                              /* xvYcc mode */
   uint32_t enable_sgb;                         /* SGB enhancement*/
   uint32_t enable_dither;                     /* Dither Algorithm*/
   uint32_t enable_dce;                         /* DCE Algorithm*/
   uint32_t enable_local_contrast;       /* Local contrast enhancement */
   uint32_t enable_lightness;               /* Global lightness adjustment */
   uint32_t enable_saturation;             /* Saturation enhancement */

   uint32_t register_map_addr;            /* The base addr of register map */
   uint32_t register_map_size;             /* The size addr of register map */
} vpp_fw_core_process_picture_t;


/*@}*/

/** @weakgroup vpp_fw_core VPP Firmware Core Functions */
/** @ingroup vpp_fw_core */
/*@{*/

/**
   This function initializes the firmware's internal state, which includes
   indicating all streams are stopped without actually stopping the streams.  This
   is only expected to be executed once at the start of the firmware.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_fw_core_initialize(dpe_si_version_t si_version);

/**
   This function stores information on scaler coefficient tables, which are arrays
   of system addresses pointing to start of filter coefficients for each scale
   factor.
   @param[in] scalers_params - Parameters containing info on scaler filter tables.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_fw_core_init_scalers(const vpp_fw_ipc_init_scalers_t scalers_params);

/**
   This function processes a picture (e.g., field or frame) within a stream.
   @param[in] picture_params - Parameters needed to process a picture.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_fw_core_process_picture(vpp_fw_core_process_picture_t *picture_params);

/**
   This function sets the global shared shared memory.
   @param[in] addr - ptr which gets shared memeory structure.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_fw_core_get_status_addr(vpp_fw_ipc_stream_int_state_t **addr);

/**
   This function flushes the input queue of stream_id to Fw. Flush here is discard.
   The host should stop the stream first and stop sending data to this stream to safely
   Finish this operation. The host should read out all the data that was already processed
   for this stream from its output queue until its empty for completing the flush operation.

   @param[in] stream_id - valid opened stream id.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_fw_core_flush_stream(uint32_t stream_id);


dpe_result_t vpp_fw_core_set_nrf_level(const uint32_t stream_ids, uint32_t nrf_level);
dpe_result_t vpp_fw_core_set_rnr_level(const uint32_t stream_ids, uint32_t rnr_level);


/**
   This function sets the stream state for stream_id. Valid states are start and stop.
   @param[in] stream_id - valid opened stream id.
   @param[in] stream_state - state to set(start,stop).
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/

dpe_result_t vpp_fw_core_set_stream_states(const uint32_t stream_ids, const vpp_fw_ipc_stream_state_t stream_state);

dpe_result_t vpp_fw_core_set_black_frame(vpp_fw_core_process_picture_t *pict);

dpe_result_t vpp_fw_core_get_stream_priority(const uint32_t stream_id, vpp_fw_ipc_stream_priority *priority);
dpe_result_t vpp_fw_core_set_stream_priority(uint32_t stream_id, vpp_fw_ipc_stream_priority priority);
dpe_result_t vpp_fw_core_ping_fw(uint32_t);
dpe_result_t vpp_fw_core_set_watermarks(uint32_t stream_id, vpp_fw_ipc_stream_watermark_t watermark);


dpe_result_t vpp_fw_core_get_param(uint32_t param_name, uint32_t *p_param_value1, uint32_t *p_param_value2);
dpe_result_t vpp_fw_core_set_param(uint32_t param_name, uint32_t param_value1, uint32_t param_value2);

dpe_result_t vpp_fw_core_set_mode(const uint32_t stream_id, uint32_t is_adp_mode);

/**
   This function stores information on JLCCE coefficient tables, which are arrays
   of DDR addresses pointing to different kind of JLCCE tables.
   
   @param[in] jlcce_tables - Parameters containing info on JLCCE tables.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/
dpe_result_t vpp_fw_core_init_jlcce_table(const vpp_fw_ipc_init_jlcce_table_t jlcce_tables);

/**
   This function opens a vidpproc instance.
   
   @param[in] open_params - Parameters containing DDR addr/size for IPC and context.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/
dpe_result_t vpp_fw_core_open_stream(vpp_fw_ipc_open_param_t *open_params);

/**
   This function closes a vidpproc instance.
   
   @param[in] stream_id - The id of closed stream.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/
dpe_result_t vpp_fw_core_close_stream(const uint32_t stream_id);

/**
   This function returns the vidpproc firmware information.
   
   @param[out] fw_info - The FW information including FW version and memory size needed for context.
   @retval DPE_RESULT_SUCCESS if function succeeds.
   @retval DPE_RESULT_FAILURE if function fails.
*/
dpe_result_t vpp_fw_core_query_fw(vpp_fw_ipc_query_info_t *fw_info);


/*@}*/
#ifdef __cplusplus
}
#endif

#endif
