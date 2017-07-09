/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2006-2011 Intel Corporation. All rights reserved.

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

/*
 * This file contains the enumerations and function declarations that
 * comprise the the Demux APIs.
 */

#ifndef __ISMD_DEMUX_H__
#define __ISMD_DEMUX_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @weakgroup ismd_demux Demux API/Structures */

/** @{ */

#ifndef ISMD_DEMUX_DEFINES_ONLY
#include "stdint.h"
#include "osal.h"
#include "ismd_msg.h"
#include "ismd_core.h"
#include "ismd_clock_recovery.h"
#endif

/**
   Identifies the various crypto algorithms the Demux supports
   @enum ismd_demux_crypto_algorithm_t
*/
typedef enum
{
   ISMD_DEMUX_PASSTHROUGH = 0x01,        /**< Indicates direct passthrough. */
   ISMD_DEMUX_DES_ENCRYPT_ECB =  0x08,   /**< Indicates DES ECB encryption. */
   ISMD_DEMUX_DES_DECRYPT_ECB = 0x09,    /**< Indicates DES ECB decryption. */
   ISMD_DEMUX_DES_ENCRYPT_CBC = 0x0A,    /**< Indicates DES CBC encryption. */
   ISMD_DEMUX_DES_DECRYPT_CBC = 0x0B,    /**< Indicates DES CBC decryption. */
   ISMD_DEMUX_3DES_ENCRYPT_ECB = 0x0C,   /**< Indicates 3DES ECB encryption. */
   ISMD_DEMUX_3DES_DECRYPT_ECB = 0x0D,   /**< Indicates 3DES ECB decryption. */
   ISMD_DEMUX_3DES_ENCRYPT_CBC = 0x0E,   /**< Indicates 3DES CBC encryption. */
   ISMD_DEMUX_3DES_DECRYPT_CBC = 0x0F,   /**< Indicates 3DES CBC decryption. */
   ISMD_DEMUX_DVB_CSA_DESCRAMBLE = 0x12, /**< Indicates DVB descrambling. */
   ISMD_DEMUX_MULTI2_DECRYPT = 0x1A,     /**< Indicates MULTI2 decryption. */
   ISMD_DEMUX_AES128_ENCRYPT_ECB = 0x1018, /**< Indicates AES128 ECB encryption. */
   ISMD_DEMUX_AES128_DECRYPT_ECB = 0x1019, /**< Indicates AES128 ECB decryption. */
   ISMD_DEMUX_AES128_ENCRYPT_CBC = 0x1118, /**< Indicates AES128 CBC encryption. */
   ISMD_DEMUX_AES128_DECRYPT_CBC = 0x1119, /**< Indicates AES128 CBC decryption. */
   ISMD_DEMUX_AES128_ENCRYPT_CTR = 0x1e18, /**< Indicates AES128 CTR encryption. */
   ISMD_DEMUX_AES128_DECRYPT_CTR = 0x1e19, /**< Indicates AES128 CTR decryption. */
   ISMD_DEMUX_HDCP20_ENCRYPT = 0x9e18,   /**< Indicates HDCP2.0 AES-CTR encryption. */
   ISMD_DEMUX_HDCP20_DECRYPT = 0x9e19,   /**< Indicates HDCP2.0 AES-CTR decryption. */
   
   ISMD_DEMUX_UNKNOWN_CRYPTO_ALG = 0x61200216, /**< Indicates Unknow decryption. */
} ismd_demux_crypto_algorithm_t;

#define ISMD_DEMUX_MAX_KEY_LEN (32) /**< Length in bytes. 32-bytes = 256-bits */

#define ISMD_DEMUX_NSK_DECODE_MAX_TABLE_ROW  47    /**< Max NSK table row */
#define ISMD_DEMUX_SEC_KEY_SELECT_MAX        0x3ff /**< Max SEC key select */

/**
   Storage structure for crypto informatino such as keys or IV values
*/
typedef struct {
   unsigned char crypto_info[ISMD_DEMUX_MAX_KEY_LEN];
} ismd_demux_crypto_info_t;
/**
   Identifies the various crypto residual modes the Demux supports
   @enum ismd_demux_crypto_residual_mode_t
*/
typedef enum
{
   ISMD_DEMUX_CLEAR_RESIDUAL         = 0x00,
   ISMD_DEMUX_TEXT_STEALING_RESIDUAL =  0x02,
   ISMD_DEMUX_TERMINATION_BLOCK_PROCESSING_RESIDUAL =  0x04,
} ismd_demux_crypto_residual_mode_t;

/**
   Specifies the byte ordering for IV and Keys.
   @enum ismd_demux_iv_key_byte_order_t
*/
typedef enum {
   ISMD_DEMUX_KEY_BYTE_ORDER_NORMAL,   /**< Use network byte order */
   ISMD_DEMUX_KEY_BYTE_ORDER_REVERSE,  /**< Use reverse network byte order */
   ISMD_DEMUX_KEY_BYTE_ORDER_INVALID   /* Must be last in the list */
} ismd_demux_key_byte_order_t;

/**
   Specifies odd or even key when setting crypto key.  Ignored when using
   raw input streams.
   @enum ismd_demux_key_type_t
*/
typedef enum {
   ISMD_DEMUX_KEY_TYPE_EVEN = 2,
   ISMD_DEMUX_KEY_TYPE_ODD,
   ISMD_DEMUX_KEY_TYPE_NOT_SPECIFIED
} ismd_demux_key_type_t;

/**
   Specifies which SEC key ladder to use.  Currently only supporting the
   firmware key ladder.
   @enum ismd_demux_key_src_t
*/
typedef enum {
   ISMD_DEMUX_SEC_KEY_SRC_HKEY1,    /**< SEC HKey1 Key Ladder */
   ISMD_DEMUX_SEC_KEY_SRC_HKEY0,    /**< SEC HKey0 Key Ladder */
   ISMD_DEMUX_SEC_KEY_SRC_DTV,      /**< SEC DTV Key Ladder */
   ISMD_DEMUX_SEC_KEY_SRC_FW,       /**< SEC Firmware Key Ladder */
   ISMD_DEMUX_SEC_KEY_SRC_INVALID   /* Must be last in the list */
} ismd_demux_key_src_t;

/**
   Specifies which SEC key type to use (CW or CPCW).
   @enum ismd_demux_sec_key_type_t
*/
typedef enum {
   ISMD_DEMUX_SEC_CW_KEYS,       /**< Use CW Keys */
   ISMD_DEMUX_SEC_CPCW_KEYS,     /**< Use CPCW Keys */
   ISMD_DEMUX_SEC_INVALID_KEYS   /* Must be last in the list */
} ismd_demux_sec_key_type_t;

/**
   Specifies if key loading mode will be direct (FW) or indirect (SEC).
   @enum ismd_demux_key_load_mode_t
*/
typedef enum {
   ISMD_DEMUX_KEY_LOAD_DIRECT,      /**< Use direct key loading from FW */
   ISMD_DEMUX_KEY_LOAD_INDIRECT,    /**< Use indirect key loading from SEC */
   ISMD_DEMUX_KEY_LOAD_INVALID      /* Must be last in the list */
} ismd_demux_key_load_mode_t;

/**
   Specifies if key decoding type for indirect key loading.
   @enum ismd_demux_key_decode_t
*/
typedef enum {
   ISMD_DEMUX_KEY_DECODE_SEC = 0,   /**< Use SEC Key Ladder Decoding */
   ISMD_DEMUX_KEY_DECODE_NSK,       /**< Use NSK Key Ladder Decoding */
   ISMD_DEMUX_KEY_DECODE_INVALID    /* Must be last in the list */
} ismd_demux_key_decode_t;

/**
   Specifies the key select bits for indirect key loading using NSK
   key table decoding.
   @enum ismd_demux_nsk_decode_key_sel_t
*/
typedef enum {
   ISMD_DEMUX_NSK_DECODE_NSA_DESCRAMBLE_KEY, /**< Use NSA-Descramble key */
   ISMD_DEMUX_NSK_DECODE_ESA_KEY,            /**< Use ESA Key */
   ISMD_DEMUX_NSK_DECODE_NSA_SCRAMBLE_KEY,   /**< Use NSA-Scramble key */
   ISMD_DEMUX_NSK_DECODE_KEY_INVALID         /* Must be last in the list */
} ismd_demux_nsk_decode_key_sel_t;

/**
   Specifies the slot number for indirect key loading using NSK key table
   decoding.
   @enum ismd_demux_nsk_decode_slot_num_t
*/
typedef enum {
   ISMD_DEMUX_NSK_DECODE_SLOT_CLEAR,   /**< Clear slot */
   ISMD_DEMUX_NSK_DECODE_SLOT_EVEN,    /**< Even slot */
   ISMD_DEMUX_NSK_DECODE_SLOT_ODD,     /**< Odd slot */
   ISMD_DEMUX_NSK_DECODE_SLOT_INVALID  /* Must be last in the list */
} ismd_demux_nsk_decode_slot_num_t;

/**
   Defines parameters used for the key_select bits when using NSK key ladder
   decoding.
*/
typedef struct {
   uint8_t                          table_row;     /**< Table row selector */
   ismd_demux_nsk_decode_key_sel_t  key_select;    /**< Key select */
   ismd_demux_nsk_decode_slot_num_t slot_num;      /**< Slot number */
} ismd_demux_key_sel_nsk_t;

/**
   Defines parameters used for indirect key loading.
*/
typedef struct {
   ismd_demux_key_src_t       key_src;    /**< Key Ladder Source */
   ismd_demux_sec_key_type_t  key_type;   /**< CW or CPCW Keys */
   ismd_demux_key_decode_t    key_decode; /**< Key Ladder Decoding Type */
   union {
      uint16_t                   key_sel_sec;   /**< Key Select, SEC Decoding */
      ismd_demux_key_sel_nsk_t   key_sel_nsk;   /**< Key Select, NSK Decoding */
   };
} ismd_demux_indirect_key_params_t;

/**
   Defines parameters used for direct key loading.
*/
typedef struct {
   ismd_demux_crypto_info_t      key_data;      /**< Key data array */
   unsigned int                  key_length;    /**< Key length in bytes */
   ismd_demux_key_byte_order_t   key_byte_order;/**< Normal or rev byte order */
} ismd_demux_direct_key_params_t;

/**
   Defines structure passed to ismd_demux_descramble_set_key and
   ismd_demux_descramble_set_system_key APIs.
*/
typedef struct {
   ismd_demux_key_load_mode_t key_load_mode; /**< Direct or indirect loading */
   ismd_demux_key_type_t      odd_or_even;   /**< Load the odd or even key */
   union {
      ismd_demux_indirect_key_params_t indirect;
      ismd_demux_direct_key_params_t   direct;
   };
} ismd_demux_key_params_t;

typedef enum {
   ISMD_DEMUX_INPUT_PORT_MODE,
   ISMD_DEMUX_INPUT_PHY_MODE,
} ismd_demux_input_mode_t;

/**
   Defines the payload type of the PID being added to a TSD handle.
   @enum ismd_demux_pid_type_t
*/
typedef enum {
   ISMD_DEMUX_PID_TYPE_PSI = 0,/**< No special processing done for PSI. */
   ISMD_DEMUX_PID_TYPE_PES     /**< Standard PES PID. */
} ismd_demux_pid_type_t;


/**
   This structure is used to specify the pid
   @struct ismd_demux_pid_t
*/
typedef struct {
   uint16_t               pid_val;
   ismd_demux_pid_type_t    pid_type;
}ismd_demux_pid_t;

/**
   This structure is used to specify the stream id
   @struct ismd_demux_sid_t
*/
typedef struct {
        uint8_t                stream_id;
} ismd_demux_sid_t;

#define ISMD_DEMUX_MAX_PID_LIST 40
#define ISMD_DEMUX_MAX_SID_LIST 8

/**
   Used to specify a set of pids
   @struct ismd_demux_pid_list_t
*/
typedef struct {
   ismd_demux_pid_t pid_array[ISMD_DEMUX_MAX_PID_LIST];
} ismd_demux_pid_list_t;

/**
   Used to specify a set of stream id's
   @struct ismd_demux_sid_list_t
*/
typedef struct {
   ismd_demux_sid_t sid_array[ISMD_DEMUX_MAX_SID_LIST];
} ismd_demux_sid_list_t;

typedef unsigned ismd_demux_filter_handle_t;

/**
    Defines the filter output formats supported by the Demux
    @enum ismd_demux_filter_output_format_t
*/
typedef enum {
   ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET = 0,/**< Output the entire transport stream
                                            packets. The input must be a
                                            transport stream to use this option.
                                            */
   ISMD_DEMUX_OUTPUT_TS_PACKET_PAYLOAD,  /**< Output only the payload of the
                                            transport stream data.  This will
                                            generate MPEG2 PES data if the input
                                            is an MPEG2 transport stream.  The
                                            input must be a transport stream
                                            to use this option.*/
   ISMD_DEMUX_OUTPUT_INDEXING_INFO,      /**< Output indexing information for
                                            the transport stream on the input.
                                            The input must be a transport
                                            stream to use this option. */
   ISMD_DEMUX_OUTPUT_TS_PACKET_PAYLOAD_WITHOUT_PTS_SPLIT,  /**< Output the
                                            payload of the transport stream data
                                            without spliting the PES buffer
                                            every time a PTS is present.
                                            This will improve the memory
                                            utilization of the output buffers.
                                            Example use: blu-ray PG/IG PES data.
                                            As a consequence, Applications need
                                            to handle multiple PTS values in one
                                            PES buffer.
                                            The input must be a transport stream
                                            to use this option.
                                            This option SHOULD NOT be used when
                                            MVC Remux component is in the
                                            pipeline.*/
   ISMD_DEMUX_OUTPUT_TS_PACKET_PTS,      /**< Output 188-byte TS packets but also
                                            communicate PTS information like the
                                            ES format does.  The information
                                            will be contained in the
                                            ismd_es_buf_attr_t structure. */
   ISMD_DEMUX_OUTPUT_ES,                 /**< Output ES data along with
                                            timestamps.*/
   ISMD_DEMUX_OUTPUT_PSI,                /**< Output program system information
                                            (PSI). The input must be a transport
                                            stream to use this option.
                                            Section filters should be created
                                            with a filter opened in this way.*/
   ISMD_DEMUX_OUTPUT_NOTHING,            /**< Throw away the output. */
   ISMD_DEMUX_OUTPUT_TS192,              /**< Output entire transport stream
                                            packets with the additional 32-bit
                                            header containing a timestamp and
                                            optional copy-protection bits.
                                            This will only produce TS192
                                            output if a TS192 stream is used
                                            for the input
                                            (TSI or a TS192 file).  Otherwise
                                            normal 188-byte transport stream
                                            packets will be output.
                                            The 32-bit extra header from the
                                            input is not modified.
                                         */
   ISMD_DEMUX_OUTPUT_RAW,                /** < Output all of the data that the
                                            demux receives from it's input. Effectively bypassing
                                            all filtering for this output. DEMUX FW supports only
                                            one such kind of filter.
                                          */
   ISMD_DEMUX_OUTPUT_MAX
} ismd_demux_filter_output_format_t;



/**
    Defines the stream input formats supported by the Demux
    @enum ismd_demux_input_stream_type_t
*/
typedef enum
{
   ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM = 1,
   /**< Indicates MPEG2 transport stream. */
   ISMD_DEMUX_STREAM_TYPE_DVD_PROGRAM_STREAM,
   /**< DVD program stream. */
   ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM_192,
   /**< Indicates MPEG2 transport stream with additional 4 byte timestamp header
   preceeding each TS packet. */
   ISMD_DEMUX_STREAM_TYPE_MAX
} ismd_demux_input_stream_type_t;

/**
    Defines the stat selection indices to determine which value is returned
    @enum ismd_demux_stat_t
*/
typedef enum {
    ISMD_DEMUX_STAT_PES_COUNT=0,
    ISMD_DEMUX_STAT_PES_ERRORS=1,
    ISMD_DEMUX_STAT_TS_ERRORS=2,
    ISMD_DEMUX_STAT_PTS_ERRORS=3,
    ISMD_DEMUX_STAT_INDEX_PACKET_COUNT=4,
    ISMD_DEMUX_STAT_CC_ERRORS=5,
    ISMD_DEMUX_STAT_MAX
} ismd_demux_stat_t;

/**
   Statistics for the Demux and Clock Recovery used by ismd_demux_get_stats()
   @struct ismd_demux_stats_t
*/
typedef struct {
   /** Count of PES Headers as determined by valid PUSI bit */
   unsigned int pes_count;

   /** Always 0 - not used */
   unsigned int pes_errors;

   /** Always 0 - not used */
   unsigned int pts_errors;

   /**
     Increments when first byte of TS Packet is not a sync byte or Transport
     Error Indicator bit is set.
   */
   unsigned int ts_errors;

   /**
     Increments when PCR Diff > PCR Threshold which usually results in a New
     Segment event
   */
   unsigned int pcr_discontinuities_count;

   /**
     Increments when a packet or AU is discarded due to a continuity counter
     error.  The continuity counter is only checked for PIDs that have an error
     policy set using \ref ismd_demux_ts_set_cc_error_policy.
   */
   unsigned int continuity_cntr_errors;
#ifndef ISMD_DEMUX_DEFINES_ONLY

   /**
     If == ISMD_DEV_HANDLE_INVALID, then clock recovery is not being used,
     clock_sync_stats are not valid.
     If valid can be used to call clock_sync API's directly.
   */
   clock_sync_t clock_sync_handle;

   /** Includes clock_locked flag */
   clock_sync_statistics_t  clock_sync_stats;
#endif
} ismd_demux_stats_t;

/**
   Specifies whether the NIM is in serial or parallel mode.
   @enum ismd_demux_tsin_nim_mode_t
*/
typedef enum {
   ISMD_DEMUX_TSIN_NIM_SERIAL = 0x55,      /**< The NIM will operate in serial mode. */
   ISMD_DEMUX_TSIN_NIM_PARALLEL            /**< The NIM will operate in parallel mode. */
} ismd_demux_tsin_nim_mode_t;


/**
   Specifies the NIM clock polarity.
   @enum ismd_demux_tsin_clock_polarity_t
*/
typedef enum {
   ISMD_DEMUX_TSIN_POS_CLOCK = 0x66,       /**< Samples are taken on positive clock edges. */
   ISMD_DEMUX_TSIN_NEG_CLOCK               /**< Samples are taken on negative clock edges. */
} ismd_demux_tsin_clock_polarity_t;


/**
   Specifies the NIM data valid polarity.
   @enum ismd_demux_tsin_dv_polarity_t
*/
typedef enum {
   ISMD_DEMUX_TSIN_POS_DV = 0x77,          /**< Data valid signal is active high. */
   ISMD_DEMUX_TSIN_NEG_DV                  /**< Data valid signal is active low. */
} ismd_demux_tsin_dv_polarity_t;


/**
   Specifies the NIM error polarity.
   @enum ismd_demux_tsin_error_polarity_t
*/
typedef enum {
   ISMD_DEMUX_TSIN_POS_ERR = 0x88,          /**< Error signal is active high. */
   ISMD_DEMUX_TSIN_NEG_ERR                  /**< Error signal is active low. */
} ismd_demux_tsin_error_polarity_t;


/**
   Specifies the NIM sync polarity.
   @enum ismd_demux_tsin_sync_polarity_t
*/
typedef enum {
   ISMD_DEMUX_TSIN_POS_SYNC = 0x99,         /**< Sync is pulsed high. */
   ISMD_DEMUX_TSIN_NEG_SYNC                 /**< Sync is pulsed low. */
} ismd_demux_tsin_sync_polarity_t;

/**
   Lists the various indexing options available when advanced indexing is
   used.  This is used by the \ref ismd_demux_indexing_configure_pid().
   These values are meant to be ORed together to enable multiple options
   when using that API.
*/
typedef enum {

   /** Nothing is indexed */
   ISMD_DEMUX_INDEX_NOTHING,

   /**
     The first time a packet of this PID is recorded since this was set with a
     call to \ref ismd_demux_indexing_configure_pid(),
     an index record will be generated.  This is cleared once the first packet
     is detected (one-time event) and must be re-enabled if it is desired
     again.
   */
   ISMD_DEMUX_INDEX_FIRST_PACKET          = 1 << 0,

   /** Index every time a TS packet has the PUSI bit set */
   ISMD_DEMUX_INDEX_TS_HDR_PUSI           = 1 << 1,

   /** Index every time a TS packet has the Random Access Indicator flag set. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_RAI         = 1 << 2,

   /** Index every time a TS packet has the ES Priority flag set. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_ES_PRIORITY = 1 << 3,

   /** Index every time a TS packet has the splice flag set. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_SPLICE      = 1 << 4,

   /** Index every time a TS packet has the Transport Pvt flag set. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_TS_PVT      = 1 << 5,

   /** Index every time a TS packet has an Adaptation Field Extension. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_EXT         = 1 << 6,

   /** Index every time a TS packet has the discontinuity indicator set. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_DI          = 1 << 7,

   /** Index every time a TS packet has a PCR, include PCR if present. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_PCR         = 1 << 8,

   /** Index every time a TS packet has an OPCR, include OPCR if present. */
   ISMD_DEMUX_INDEX_TS_HDR_AF_OPCR        = 1 << 9,

   /** Index every time a PES header is found, include PTS if present. */
   ISMD_DEMUX_INDEX_PES_HDR               = 1 << 10,

   /**
     Index the MPEG2 elementary stream.
     It is assumed that the caller ensures this PID carries MPEG2 video.
   */
   ISMD_DEMUX_INDEX_MPEG2_VID_ES          = 1 << 11

} ismd_demux_indexing_type_t;

/**
   Structure used to set the NIM configuration.
   This should be set to match the external NIM.
   @struct ismd_demux_tsin_nim_config_t
*/
typedef struct {
   ismd_demux_tsin_nim_mode_t        nim_mode;         /**< specifies ISMD_DEMUX_PI_NIM_SERIAL or ISMD_DEMUX_PI_NIM_PARALLEL */
   ismd_demux_tsin_clock_polarity_t  clk_polarity;     /**< specifies ISMD_DEMUX_PI_POS_CLOCK or ISMD_DEMUX_PI_NEG_CLOCK */
   ismd_demux_tsin_dv_polarity_t     dv_polarity;      /**< specifies ISMD_DEMUX_PI_POS_DV or ISMD_DEMUX_PI_NEG_DV */
   ismd_demux_tsin_error_polarity_t  err_polarity;     /**< specifies ISMD_DEMUX_PI_POS_ERR or ISMD_DEMUX_PI_NEG_ERR */
   ismd_demux_tsin_sync_polarity_t   sync_polarity;    /**< specifies ISMD_DEMUX_PI_POS_SYNC or ISMD_DEMUX_PI_NEG_SYNC*/
} ismd_demux_tsin_nim_config_t;


typedef unsigned long ismd_demux_section_filter_handle_t;

#define ISMD_DEMUX_SF_MASK_SIZE  24
#define ISMD_DEMUX_MAX_SECTION_SIZE    4096

typedef struct ismd_demux_section_filter_params
{
    uint8_t        tid;
    uint8_t        section_offset;
    uint8_t        positive_filter[ISMD_DEMUX_SF_MASK_SIZE];
    uint8_t        positive_mask[ISMD_DEMUX_SF_MASK_SIZE];
    uint8_t        negative_filter[ISMD_DEMUX_SF_MASK_SIZE];
    uint8_t        negative_mask[ISMD_DEMUX_SF_MASK_SIZE];
} ismd_demux_section_filter_params_t;


enum ismd_demux_open_cable_mode {
   ISMD_DEMUX_NO_OPEN_CABLE,     /**< no open cable mux/demux (don't route to POD)*/
   ISMD_DEMUX_SINGLE_STREAM,     /**< open cable single stream (route to POD)*/
   ISMD_DEMUX_MULTI_STREAM,      /**< open cable multi-stream (route to POD)*/
};

typedef enum {
   /**
    Normal discontinuity detection. Generates a discontinuity when one or more outlying
    PCR is detected.
    This is the default discontinuity detection algorithm
    */
   ISMD_DEMUX_DISCONTINUITY_DETECTION_NORMAL,
   /**
    Filter out single outlying PCRs. Generates a discontinuity when two or more outlying
    PCRs are detected. When only one inconsistancy is detected, that PCR will be discarded
    and no discontinuity will be generated.(see followed diagram),
    This algorithm allows seamless recovery from a single corrupted PCR value. However,
    This will introduce a slower discontinuity response time (the discontinuity will be
    detected one PCR later compared with the default algorithm)
    pcr
    ^
    |                *
    |              *
    |       *    *
    |          *
    |
    |      *
    |    *
    |  *
    |
    -------------------------------->t
    */
   ISMD_DEMUX_DISCONTINUITY_DETECTION_SINGLE_PCR_FILTER
} ismd_demux_discontinuity_detection_alg_t;

/**
    Defines the various policies available for handling errors in the
    continuity counter in the TS header.  These policies control what, if any,
    data is to be discarded when the continuity counter does not increment
    as expected.
    Note that these can be ORed together to get a combination of behaviors.
    Note that the following packets are not dropped based on continuity
    counter value:
       * packets with no payload
       * packets with the discontinuity indicator set
       * packets with the payload unit start indicator set.  This flag is
         ignored for discontinuities on data filters but is used when checking
         for duplicates.

    @enum ismd_demux_cc_error_policy_t
*/
typedef enum {
   /**
     Ignore the continuity counter entirely. No packets are discarded because
     of the continuity counter.
   */
   ISMD_DEMUX_TS_CC_IGNORE_ERRORS = 0,

   /**
     Discard every other duplicate packet.  In other words, the first time a
     packet is repeated the repeated packet is discarded.  The second time it
     is repeated the second repeat (third identical CC) is not discarded,
     The third repeat is discarded and so on.
   */
   ISMD_DEMUX_TS_CC_DISCARD_ODD_DUPLICATES = 1 << 0,

   /**
     Discard the whole access unit (PES payload or section) when a
     discontinuity is detected based on the continuity counter.
     Note that this has some limitations.
     1) The TSD must buffer some data internally to assemble a whole access
        before it can be written, to ensure there are no errors in that access
        unit.  This means that there will be additional memory usage and
        stream latency depending on the size of the access unit.
     2) This implies that PES payloads are atomic at the demux output and not
        missing any pieces.  In order to guarantee this, none of the PES
        payload is written to the output port until the port has room for all
        buffers that compose the payload.  If the port is not big enough to
        hold the entire PES payload then the payload is dropped in its
        entirety and an error logged. This is not recommended for video PES
        for this reason.
     3) This policy is not applied to filters with multiple PIDs mapped to them.
        This is because packet payloads may be interleaved on the output.
        If a PID with this policy is not the only PID on the filter then that
        filter's output will still contain access units that have continuity
        counter discontinuities.
        If the same PID is ALSO mapped to another filter that has no other PIDs
        then that filter will drop access units as expected (the filters are
        independent).
   */
   ISMD_DEMUX_TS_CC_DISCARD_WHOLE_AU = 1 << 1
} ismd_demux_ts_cc_error_policy_t;

/**
    Defines the various policies available for checking CRC in PSI section header
    for each section filter.

    @enum ismd_demux_section_filter_crc_check_policy_t
*/
typedef enum {
   /**
     Do CRC check according to the section_syntax_indicator in section header:
      If the bit is 1, do CRC check.
      If the bit is 0, not do CRC check.
     This is the default configuration.

     Handling of the policy:
     - Output section data if CRC is valid and section syntax is set.
     - Send out CRC event if CRC is invalid and section syntax is set.
     - Output section data if section syntax is not set

   */
   ISMD_DEMUX_CRC_CHECK_SECTION_SYNTAX,

   /**
     Ignore section_syntax_indicator in section header, always do CRC check.

     Handling of the policy:
     - Output section data if CRC is valid.
     - Send out CRC event if CRC is invalid.  

   */
   ISMD_DEMUX_CRC_CHECK_ALWAYS,

   /**
     Ignore section_syntax_indicator in section header, never do CRC check.

     Handling of the policy:
     - Always output section data.
   */
   ISMD_DEMUX_CRC_CHECK_NEVER,
} ismd_demux_section_filter_crc_check_policy_t;

#ifndef ISMD_DEMUX_DEFINES_ONLY
/**
Structure to consolidate all information related to stream position.
*/
typedef struct {
   ismd_time_t current_time;              /**< Current time when stream position is queried.
                                          A value of ISMD_NO_PTS implies that the "current_time" is not available. */

   ismd_time_t first_pcr_time;            /**< Tracks the arival time of the first PCR.
                                          A value of ISMD_NO_PTS implies that the "first_pcr_time" is not available. */

   ismd_time_t last_pcr_time;             /**< Tracks the arival time of the last PCR.
                                          A value of ISMD_NO_PTS implies that the "last_pcr_time" is not available. */

   ismd_time_t first_pcr;                 /**< First valid original pcr processed by demux.
                                          A value of ISMD_NO_PTS implies that the "first_pcr" is not available. */

   ismd_time_t last_pcr;                  /**< Last valid original pcr processed by demux.
                                          A value of ISMD_NO_PTS implies that the "last_pcr" is not available. */

   ismd_pts_t last_pts;                   /**< Last valid original pts processed by demux.
                                          A value of ISMD_NO_PTS implies that the "last_pts" is not available. */

   ismd_time_t pcr_before_discont;        /**< Old timebase. */

   ismd_time_t pcr_at_discont;            /**< New timebase - combined with old timebase tells how large the discontinuity is. */

   unsigned int pcr_discontinuity_count;  /**< Counter of PCR discontinuity */

   /**
     The arrival time (relative to indexing being enabled) of the most
     recently received packet.  If indexing was never enabled or no packets
     were received since enabling indexing, this is set to 0.
   */
   uint32_t    last_idx_packet_time;

   /**
     The packet count (relative to indexing being enabled) of the most
     recently saved packet.  If indexing was never enabled or no packets
     were received since enabling indexing, this is set to 0.
   */
   uint32_t    last_idx_packet_number;

} ismd_demux_stream_position_info_t;


/**
   Defines the size of the buffer array that can be used in a demux buffer
   List.  The demux doesn’t actually have a limit here, but the API
   marshalling needs a defined maximum size.  Note that the buffer list
   may be specified to have fewer buffers than this, but not more than this.
*/
#define ISMD_DEMUX_MAX_BUFFER_LIST 64

/**
   Structure that represents a list of SMD buffers.
*/
typedef struct {
   /**
      Number of buffers in the list, should not exceed
      ISMD_DEMUX_MAX_BUFFER_LIST
   */
   unsigned             num_buffers;

   /** Array containing the buffer handles */
   ismd_buffer_handle_t buffers[ISMD_DEMUX_MAX_BUFFER_LIST];
} ismd_demux_buffer_list_t;



/*! @name Initialization/teardown functions. */

/**
Gets a stream handle to a Demux device if one is available.

@param[in] stream_type : Specifies the data format of the stream to be processed.
@param[out] handle : Pointer to a stream handle ID that will get filled in.
@param[out] port_handle : Will be populated with a handle to the input port if in port input mode.  The returned value is undefined in phy mode.
@retval ISMD_SUCCESS : Handle was successfully obtained.
@retval ISMD_ERROR_NULL_POINTER : handle was supplied as NULL.
@retval ISMD_ERROR_INVALID_REQUEST : stream_type is invalid.
@retval ISMD_ERROR_OPERATION_FAILED : No handles are available or unable to allocate required memory.
*/
ismd_result_t SMDCONNECTION ismd_demux_stream_open(
                                        ismd_demux_input_stream_type_t stream_type,
                                        ismd_dev_t        *handle,
                                        ismd_port_handle_t *port_handle);

/**
Gets a stream handle to a Demux device bound to a Transport hardware input if one is available.

@param[in] interface_id : identifier for the TS input to bind to.
@param[out] handle : Pointer to a stream handle ID that will get filled in.
@retval ISMD_SUCCESS : Handle was successfully obtained.
@retval ISMD_ERROR_NULL_POINTER : handle was supplied as NULL.
@retval ISMD_ERROR_INVALID_REQUEST : stream_type is invalid.
@retval ISMD_ERROR_OPERATION_FAILED : No handles are available or unable to allocate required memory.
*/
ismd_result_t SMDCONNECTION ismd_tsin_open(
                                        int interface_id,
                                        ismd_dev_t        *handle);


/** ismd_demux_stream_close() is a deprecated API, please use ismd_dev_close() */
#define ismd_demux_stream_close ismd_dev_close

/**
Open and start an output filter for a stream.

Used ONLY to open a pes filter or a psi filter for the specified
stream.
To open an indexer filter, use ismd_demux_filter_open_indexer();

@param[in] handle : Demux stream handle to get the filter from.
@param[in] op_format : Specifies the output format of the data for this filter.
When a transport stream is being processed, it can be entire transport stream
packets, transport stream packet payloads, or ES data.

@param[in] output_buf_size: Specifies the maximum size of each output buffer.  Note that buffers written by the filter
may not use the entire space available.
@param[out] filter_handle : Demux filter handle of the allocated filter.
@param[out] port_handle : handle to the filter's output port.

@retval ISMD_SUCCESS : The filter was successfully obtained.
@retval ISMD_ERROR_NULL_POINTER : filter_handle was supplied as NULL.
@retval ISMD_ERROR_INVALID_HANDLE : stream_handle is not a valid Demux stream handle.
@retval ISMD_ERROR_NO_RESOURCES : No filters are available.
@retval ISMD_ERROR_INVALID_REQUEST : op_format is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_open(ismd_dev_t        handle,
                                        ismd_demux_filter_output_format_t op_format,
                                        unsigned output_buf_size,
                                        ismd_demux_filter_handle_t *filter_handle,
                                        ismd_port_handle_t *port_handle);



/**
Opens an indexer filter, if available, for the specified TS filter.

Indexer filters are used for the DVR feature called indexing and are only required if
this feature is needed.

See also \ref dvr_doc "SMD DVR and indexing documentation"

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle that is exporting the SPTS data.
@param[out] indexer_filter_handle : new Demux indexer filter handle if successful.
@param[out] port_handle : handle to the filter's output port.

@retval ISMD_SUCCESS : The filter was successfully obtained.
@retval ISMD_ERROR_NULL_POINTER : indexer_filter_handle was supplied as NULL.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is not a valid Demux filter handle.
@retval ISMD_ERROR_NO_RESOURCES : No index filter is available.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_open_indexer(ismd_dev_t        handle,
                                                ismd_demux_filter_handle_t filter_handle,
                                                ismd_demux_filter_handle_t *indexer_filter_handle,
                                                ismd_port_handle_t *port_handle);

/**
An alternative to \ref ismd_demux_filter_open() that can be used to specify
a pre-allocated pool of buffers that the demux will use in the order that
they are specified.  This is useful for client software that must read the
demux output, since a specific set of buffers can be mapped once and only
once.

The demux will circle through the list, using the buffers in the same order
that they were specified in the array.  The demux will either throttle or
drop data when it needs to use a buffer that is still being used by the
client.

The list of buffers does not need to be contiguous, although the main use
of this is to create a contiguous memory region for the demux to write into.
note that as with all output modes the demux might not fill every buffer
completely - this does not allow for true emulation of a circular buffer.
If this is not desired, the \ref ismd_demux_filter_disable_buffer_splitting()
API can be used - see that API for more documentation.

Buffers passed in using this function should have a reference count of 1.
Upon successful completion of this function, the buffers will belong to the
demux and should not be dereferenced.

From the filter’s output, these buffers will appear with a reference count
of 2.  One reference belongs to the client and one still belongs to the
demux.  Once the client is done with the buffer and dereferences it
(reference count back to 1) the demux may reuse it.  The client should not
free the buffer or dereference it until the reference count reaches 0.

When a filter using a buffer list is closed, the demux will dereference each
of the buffers once.

If a filter using a buffer pool is flushed (or the stream is flushed,
causing filters to be flushed) the demux will mark all buffers that were
inside of the demux to be reusable.  If the client is holding on to any
buffers then they will not be reused until the client dereferences them.
If the client is not holding onto any buffers than the demux will behave
like it does initially (all buffers available) but it will not necessarily
start at the first buffer in the list - it will start at the next buffer
after the ones that were flushed. For example, if a list of size 4 was being
used and the demux was internally processing 0, 1, and 2 then buffer 3 would
be the first one written after the flush.

For tags (newsegment, etc...), the demux will allocate a buffer with no data
that will come from outside of the pool.  Clients should be prepared to
handle this special case.

If a filter using a buffer list are set to be "leaky" there are two possible
behaviors.  The first is the traditional leaky case when the demux output port
gets full.  The buffers will be dropped and returned to the list of available
buffers in this case (order is still maintained).
The second behavior is when the port is not full but the client is not
dereferencing the buffers in a timely manner.  In this case data will be
discarded and the demux will continue to wait for the client to release the
buffers.  In either case the filter overrun event set with
smd_demux_filter_set_overrun_event() will be strobed.

Used ONLY to open a PES filter or a PSI filter for the specified
stream.
To open an indexer filter, use ismd_demux_filter_open_indexer();

@param[in] handle      : Demux stream handle to get the filter from.
@param[in] op_format   : Specifies the output format for this filter.
@param[in] buffer_list : List of buffers for the demux to use.  The buffers
                         will be written to by the demux in the same order that
                         they appear in the list.

@param[out] filter_handle : Demux filter handle of the allocated filter.
@param[out] port_handle   : handle to the filter's output port.

@retval ISMD_SUCCESS               : The filter was successfully obtained.
@retval ISMD_ERROR_NULL_POINTER    : filter_handle or port_handle was supplied
                                     as NULL.
@retval ISMD_ERROR_INVALID_HANDLE  : stream_handle is not a valid Demux stream
                                     handle, or one of the buffers in the list
                                     is not a valid buffer handle.
@retval ISMD_ERROR_NO_RESOURCES    : No filters are available.
@retval ISMD_ERROR_INVALID_REQUEST : op_format is invalid, or buffer_list
                                     Is not valid (size 0, size > max,
                                     duplicate buffer)
*/
ismd_result_t SMDEXPORT
ismd_demux_filter_open_preset_buffers(
                                 ismd_dev_t                        handle,
                                 ismd_demux_filter_output_format_t op_format,
                                 ismd_demux_buffer_list_t          buffer_list,
                                 ismd_demux_filter_handle_t       *filter_handle,
                                 ismd_port_handle_t               *port_handle);
/**
Closes a previously allocated Demux filter handle.  Any resources allocated
to this filter are automatically freed.  PIDs mapped to this filter are
autmoatically unmapped, but remain mapped to other filters.  This can be used
for indexer filters and normal filters.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
The filter should not be used after this function has been called.

@retval ISMD_SUCCESS : Always returns success.  Error conditions (invalid
                       handles, etc.) are detected but not reported.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_close(ismd_dev_t        handle,
                                         ismd_demux_filter_handle_t filter_handle);


/**
Gets the smd port handle associated with the filter handle. The port handle was created
during filter opening.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[out] port_handle : handle to the filter's output port.

@retval ISMD_SUCCESS : The filter info has been obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is not a valid active filter handle.
@retval ISMD_ERROR_NULL_POINTER : port_handle was supplied as NULL.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_get_output_port(ismd_dev_t        handle,
                                            ismd_demux_filter_handle_t filter_handle,
                                            ismd_port_handle_t *port_handle);


/**
Gets the smd port handle associated with the stream handle. The port handle was created
during stream opening.

@param[in] handle : Demux stream handle.

@param[out] port_handle : handle to the stream's input port.


@retval ISMD_SUCCESS : The filter info has been obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE : handle is not a valid active stream handle.
@retval ISMD_ERROR_NULL_POINTER : input parameter was supplied as NULL.
*/
ismd_result_t SMDEXPORT ismd_demux_stream_get_input_port(ismd_dev_t        handle,
                                            ismd_port_handle_t *port_handle);


/*! @name Basic Configuration functions. */

/**
Sets the PCR PID for this stream.  The Demux needs to know this
PID when rebasing.  If this is not set, pids with rebasing enabled will never
generate PTS values.  If none of the PIDs are set for rebasing, then this
function need not be used.  Note that this is global to the
entire input stream.  If there are multiple programs in the stream and each has
a different PCR PID with a different timebase, only one of the programs can
have rebasing enabled.

The following default settings will be used if this function is not called: <br>
- No PCR PID set, rebasing is not possible <br>

@param[in] handle : Demux stream handle.
@param[in] pcr_pid : Specifies the PCR PID for the stream.

@retval ISMD_SUCCESS : The PID is successfully set.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The stream is not a transport stream.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_pcr_pid(ismd_dev_t        handle,
                                           uint16_t pcr_pid);



/**
Enable PCR discontinuity detection logic on the demux. Current demux discontinuity detection is based on
PCR .

By default, this is enabled.

@param[in] handle : handle for the demux.

@retval ISMD_SUCCESS : .
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_enable_discontinuity_detection(ismd_dev_t handle);


/**
Disable PCR discontinuity detection logic on the demux.

By default, this is enabled.

@param[in] handle : Demux stream handle.

@retval ISMD_SUCCESS : .
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_disable_discontinuity_detection(ismd_dev_t handle);

/**
Set demux discontinuity dectection algorithm. The algorithm determines the method that the
demux uses to detect discontinuities in the input streams. The default discontinuity detection
algorithm is ISMD_DEMUX_DISCONTINUITY_DETECTION_NORMAL

@param[in] handle : Demux stream handle.
@param[in] algorithm : discontinuity detection algorithm to set.

@retval ISMD_SUCCESS : algorithm successfully set.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER: algorithm is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_set_discontinuity_detection_algorithm(ismd_dev_t handle,
                                                                         ismd_demux_discontinuity_detection_alg_t algorithm);


/**
Enables or disables dynamic pid filtering on this filter.
Dynamic PID filters do not have matching PIDs as configured by
ismd_demux_filter_map_to_pids.  Instead, the PID match information is supplied
as meta-data with the stream's input buffers.  A filter cannot be both a normal
filter and a dynamic filter at the same time.  Attempting to enable dynamic
mode while PIDs are explicitly mapped to the filter will return an error.

This can only be used when the stream and filter are in port mode.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] enable : True to enable on this filter, false to disable.

@retval ISMD_SUCCESS : dynamic filtering was successfully enabled or disabled.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : Cannot enable dynamic filtering while pids are mapped
to the filter.
*/
ismd_result_t SMDEXPORT ismd_demux_set_dynamic_filtering(ismd_dev_t        handle,
                                               ismd_demux_filter_handle_t filter_handle,
                                               bool enable);



/**
Adds PIDs to a filter MAP.
Maps a filter to PIDs and starts the filter.
If a PID is invalid, an error is returned.
If the PID is a duplicate, the function returns no error.  The duplicate
PID is not added to the filter.

This fuction causes the Demux to send TS packets or portions with this PID
from the stream's (the handle used to allocate this filter) input to
the specified filter if the stream, PID, and filter are enabled.  This
must be used with a filter derived from ismd_demux_filter_open.

The following default settings will be used if this function is not called: <br>
The filter-PID mappings will not exist.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid_list : array of pids to be mapped.
@param[in] list_size : Specifies the number of valid elements in pid_list.

@retval ISMD_SUCCESS : The filter is successfully mapped to the PID.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_NO_RESOURCES : The stream is already processing the maximum
number of PIDs or the filter is already mapped to the maximum number of
PIDs or the PID is already mapped to the maximum number of filters.
@retval ISMD_ERROR_INVALID_REQUEST : The filter is an indexer, which can't
have PIDs mapped to it.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_map_to_pids(ismd_dev_t        handle,
                                               ismd_demux_filter_handle_t filter_handle,
                                               ismd_demux_pid_list_t pid_list,
                                               unsigned   list_size);


/**
Removes the filter-PID mapping.  This will cause the Demux to stop
sending data with this PID to the specified filter.  This must not be used with an index filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid_list : Specifies the PID list array.
@param[in] list_size : Specifies the number of valid items in the pid list to be unmapped.

@retval ISMD_SUCCESS : The filter is successfully unmapped from the PIDs.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The filter is an indexer, which can't
have PIDs unmapped from it.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_unmap_from_pids(ismd_dev_t        handle,
                                                   ismd_demux_filter_handle_t filter_handle,
                                                   ismd_demux_pid_list_t pid_list,
                                                   unsigned   list_size);



/**
Adds a single PID to a filter MAP.
Maps a filter to PID and starts the filter.
If a PID is invalid, an error is returned.
If the PID is a duplicate, the function returns no error.  The duplicate
PID is not added to the filter.

This fuction causes the Demux to send TS packets or portions with this PID
from the stream's (the handle used to allocate this filter) input to
the specified filter if the stream, PID, and filter are enabled.  This
must be used with a filter derived from ismd_demux_filter_open.

The following default settings will be used if this function is not called: <br>
The filter-PID mappings will not exist.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid_val : pid to be mapped.
@param[in] pid_type : pid type for the pid to be mapped.

@retval ISMD_SUCCESS : The filter is successfully mapped to the PID.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_NO_RESOURCES : The stream is already processing the maximum
number of PIDs or the filter is already mapped to the maximum number of
PIDs or the PID is already mapped to the maximum number of filters.
@retval ISMD_ERROR_INVALID_REQUEST : The filter is an indexer, which can't
have PIDs mapped to it.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_map_to_pid(ismd_dev_t        handle,
                                                   ismd_demux_filter_handle_t filter_handle,
                                                   uint16_t pid_val,
                                                   ismd_demux_pid_type_t pid_type);



/**
Removes the filter-PID mapping.  This will cause the Demux to stop
sending data with this PID to the specified filter.  This must not be used with an index filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid_val : Specifies the pid to be unmapped.

@retval ISMD_SUCCESS : The filter is successfully unmapped from the PIDs.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The filter is an indexer, which can't
have PIDs unmapped from it.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_unmap_from_pid(ismd_dev_t        handle,
                                                   ismd_demux_filter_handle_t filter_handle,
                                                   uint16_t pid_val);



/**
Retrieves the pids associated to the filter.

This must not be used with an index filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid_list : Specifies the PID list.
@param[in,out] list_size : When the function is called, contains the maximum
expected number of array entries, upon successful
return this is chenged to be the actual number of elements the driver wrote
into the pid_list.

@retval ISMD_SUCCESS : The list was successfully retrieved.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_get_mapped_pids(ismd_dev_t        handle,
                                          ismd_demux_filter_handle_t filter_handle,
                                          ismd_demux_pid_list_t *pid_list,
                                          unsigned   *list_size);


/**
Adds a stream_id_extension filter to a PID already added to a filter MAP.
If a PID is invalid, an error is returned.
If the stream_id_extension filter has already been added to this PID, the
function returns no error.  The new stream_id_extension replaces a previous
stream_id_extension.  Only one stream_id_extension can be associated with a
PID at any one time.

This fuction causes the Demux to send TS packets or portions with this PID
and matching stream_id_extension from the stream's (the handle used to
allocate this filter) input to the specified filter.  The function must be
used with a filter derived from ismd_demux_filter_open.

The following default settings will be used if this function is not called: <br>
The PID will have no stream_id_extension associated with it for filtering.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid : The PID to associate the stream_id_extension with.
@param[in] stream_id_extension : The stream_id_extension to be associated with
the PID.

@retval ISMD_SUCCESS : The stream_id_extension is successfully associated with
the PID.
@retval ISMD_ERROR_INVALID_HANDLE : stream handle or filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The PID specified has not been mapped to
the specified filter.
@retval ISMD_ERROR_OPERATION_FAILED : The stream_id_extension could not be
associated with the PID.
*/
ismd_result_t SMDEXPORT ismd_demux_add_stream_id_extension_to_pid(
                                       ismd_dev_t        handle,
                                       ismd_demux_filter_handle_t filter_handle,
                                       ismd_demux_pid_t pid,
                                       uint8_t   stream_id_extension);


/**
Removes the stream_id_extension associated with a PID.  The Demux will continue
sending data with this PID to the specified filter but it will no longer be
subject to filtering based on the stream_id_extension.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] pid : Specifies the PID to disassociated with the
stream_id_extension.

@retval ISMD_SUCCESS : The stream_id_extension is successfully disassociated
with the PID.
@retval ISMD_ERROR_INVALID_HANDLE : stream handle or filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The specified PID has not been mapped to
the filter.
@retval ISMD_ERROR_OPERATION_FAILED : The stream_id_extension could not be
disassociated from the PID.
*/
ismd_result_t SMDEXPORT ismd_demux_remove_stream_id_extension_from_pid(
                                       ismd_dev_t        handle,
                                       ismd_demux_filter_handle_t filter_handle,
                                       ismd_demux_pid_t pid);


/**
Map a filter to a sid and optional substream; this function must not be used with a
transport stream.
This can only be used with program streams.
Upon successful return the sid will be started.


This must not be used with an index filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] stream_id : Specifies the stream to associate with
@param[in] substream_id : Specifies the substream to associate with
@param[in] data_offset : Not currently implemented; size in bytes of additional header information in the packet payload

@retval ISMD_SUCCESS : The list was successfully retrieved.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
*/

ismd_result_t SMDEXPORT ismd_demux_filter_map_to_sid(ismd_dev_t        handle,
                                               ismd_demux_filter_handle_t filter_handle,
                                               uint8_t stream_id,
                                               uint8_t substream_id,
                                               unsigned int data_offset);
/**
Unmap a filter from a sid and optional substream.
This can only be used with program streams.
Upon successful return the filter will have been unmapped from the sid.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] stream_id : Specifies the stream to associate with
@param[in] substream_id : Specifies the substream to associate with

@retval ISMD_SUCCESS : The list was successfully retrieved.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : pid derived from stream_id is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_unmap_from_sid(ismd_dev_handle_t handle,
                                               ismd_demux_filter_handle_t filter_handle,
                                               uint8_t stream_id,
                                               uint8_t substream_id);

/**
Get a the stream & substream ids mapped to a specified filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] stream_id : pointer to area to store stream id mapped to filter
@param[in] substream_id : pointer to area to store substream id mapped to filter

@retval ISMD_SUCCESS : The list was successfully retrieved.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_NULL_PTR : if either the stream_id or substream_id pointers are null.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_get_mapped_sid(ismd_dev_handle_t handle,
                                          ismd_demux_filter_handle_t filter_handle,
                                          uint8_t *stream_id,
                                          uint8_t *substream_id);




/**
Resets the index count to the specified number.  Indexing output
stores the TS packet number (count) that contains a certain PES or ES header.
This function can be used to initialize that count.  This can only be used
on indexer filters derived from ismd_demux_open_indexer_filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : indexer filter handle.
@param[in] reset_value : Specifies the value to which the index count is reset.

@retval ISMD_SUCCESS : The indexer filter's count is successfully reset.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : filter_handle is not an indexer filter.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_reset_index_count(ismd_dev_t        handle,
                                                 ismd_demux_filter_handle_t filter_handle,
                                                 unsigned int reset_value);


/**
Enables or disables indexing on a specific pid.  Only one PID can be indexed
at a time when using this API.

NOTE: this is the only option for indexing on CE3100 and CE4100.  On later
chips this is supported as a legacy mode but the
\ref ismd_demux_indexing_configure_pid() API can be used for more control,
and for supporting multiple PIDs simultaneously.

If this API is used, the basic indexing  format will be output from
the index filter. Refer to \ref dvr_doc "SMD DVR and indexing documentation"
for the definition of this format.

@param[in] handle : Demux stream handle.
@param[in] pid : Specifies the video pid to index.
@param[in] enable_indexing :  Enable indexing if true, false otherwise

@retval ISMD_SUCCESS : The indexing on a pid is successfully enabled or disabled.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : One of the advanced indexing functions
                                     (\ref ismd_demux_indexing_configure_pid(),
                                      \ref ismd_demux_ts_indexing_remove_pid(),
                                      \ref ismd_demux_indexing_remove_all_pids())
                                     has been used for this stream.  Those
                                     indexing functions are not compatible
                                     with the programming model this API uses.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_indexing_on_pid(ismd_dev_t        handle,
                                            uint16_t pid,
                                            bool enable_indexing);


/**
Controls what is indexed for the specified PID.  When using this API, any and
all PIDs that were added to the stream can be indexed simultaneously.  Control
over what is indexed can be individually controlled for each PID.

NOTE: this is not supported for CE3100 and CE4100.  On those SOCs, please use
\ref ismd_demux_ts_set_indexing_on_pid().

If this API is used, the advanced indexing format will be output from
the index filter.  Refer to \ref dvr_doc "SMD DVR and indexing documentation"
for the definition of this format.

It is allowed to use this dynamically while an indexing operation is in
progress.  Both the set of PIDs being indexed and the indexing type can be
changed on the fly.

@param[in] handle        :  Demux stream handle.
@param[in] pid           :  Specifies the pid to configure.
@param[in] indexing_type :  Controls what is indexed for this PID.  This is
                            a bitmask.

@retval ISMD_SUCCESS : The indexing on a pid is successfully configured.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : This is either the CE3100 or CE4100
                                     SOC, or the indexing_type parameter
                                     specifies an unsupported feature.
@retval ISMD_ERROR_INVALID_REQUEST : \ref ismd_demux_ts_set_indexing_on_pid()
                                     has been used for this stream.  That
                                     indexing function is not compatible
                                     with the programming model this API uses.
*/
ismd_result_t SMDEXPORT ismd_demux_indexing_configure_pid(
                                    ismd_dev_t                 handle,
                                    uint16_t                   pid,
                                    ismd_demux_indexing_type_t indexing_type);


/**
Disables indexing for the specified PID.  This is a shortcut for calling
\ref ismd_demux_indexing_configure_pid() with indexing_type set to
ISMD_DEMUX_INDEX_NOTHING.

NOTE: this is not supported for CE3100 and CE4100.  On those SOCs, please use
\ref ismd_demux_ts_set_indexing_on_pid().

If this API is used, the advanced indexing format will be output from
the index filter.  Refer to \ref dvr_doc "SMD DVR and indexing documentation"
for the definition of this format.

It is allowed to use this dynamically while an indexing operation is in
progress.  PIDs can be removed on the fly.

@param[in] handle        :  Demux stream handle.
@param[in] pid           :  Specifies the pid to disable indexing for.

@retval ISMD_SUCCESS : The indexing on a pid is successfully disabled.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : This is either the CE3100 or CE4100
                                     SOC
@retval ISMD_ERROR_INVALID_REQUEST : \ref ismd_demux_ts_set_indexing_on_pid()
                                     has been used for this stream.  That
                                     indexing function is not compatible
                                     with the programming model this API uses.
*/
ismd_result_t SMDEXPORT ismd_demux_indexing_remove_pid(
                                    ismd_dev_t                 handle,
                                    uint16_t                   pid);


/**
Disables indexing for all PIDs.  This is a shortcut for calling
\ref ismd_demux_indexing_remove_pid() for all PIDs in the stream.

NOTE: this is not supported for CE3100 and CE4100.  On those SOCs, please use
\ref ismd_demux_ts_set_indexing_on_pid().

If this API is used, the advanced indexing format will be output from
the index filter.  Refer to \ref dvr_doc "SMD DVR and indexing documentation"
for the definition of this format.

It is allowed to use this dynamically while an indexing operation is in
progress.  PIDs can be removed on the fly.

@param[in] handle        :  Demux stream handle.

@retval ISMD_SUCCESS : All PIDs have indexing disabled.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : This is either the CE3100 or CE4100
                                     SOC
@retval ISMD_ERROR_INVALID_REQUEST : \ref ismd_demux_ts_set_indexing_on_pid()
                                     has been used for this stream.  That
                                     indexing function is not compatible
                                     with the programming model this API uses.
*/
ismd_result_t SMDEXPORT ismd_demux_indexing_remove_all_pids(
                                    ismd_dev_t                 handle);



/**
Enables or disables index packet counting on a specific filter.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.  This should be a filter exporting TS packets.
@param[in] enable_index_packet_counting : Enable index packet counting if true, false otherwise

@retval ISMD_SUCCESS : Counting successfully enabled on the filter.
@retval ISMD_ERROR_INVALID_HANDLE : handle or filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : filter_handle is not a TS packet filter.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_index_pkt_counting_on_filter(
                                            ismd_dev_t        handle,
                                            ismd_demux_filter_handle_t filter_handle,
                                            bool enable_index_packet_counting);


/**
Enable leaky filters on the demux.  This enables dropping of smd buffers if no
space is available on the filter output port.  It will keep dropping the buffers
till space is available on the output port of the filter.  This is
a property on the stream and hence all the filters for that particular stream
will be made leaky. Any new filter created is also made leaky.

By default this is turned off.

@param[in] demux_handle : handle for the demux

@retval ISMD_SUCCESS : the mode was changed
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.
*/

ismd_result_t SMDEXPORT ismd_demux_enable_leaky_filters(ismd_dev_t demux_handle);

/**
Disable leaky filters on the demux.  This disables dropping of smd buffers if no
space is available on the filter output port.  This is a property on the stream
and hence all the filters for that particular stream will be made non-leaky. Any
new filter created is also made non-leaky, execpt that section filters are always
set to leaky when created, regardless of the stream's leaky property.

By default filters on a stream are non-leaky.

@param[in] demux_handle : handle for the demux

@retval ISMD_SUCCESS : the mode was changed
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.

*/

ismd_result_t SMDEXPORT ismd_demux_disable_leaky_filters(ismd_dev_t demux_handle);



/**
Enable leaky filter on the demux.  This enables dropping of smd buffers if no
space is available on the filter output port.  It will keep dropping the buffers
till space is available is available on the output port of the filter. This is a
per filter property, which overrides the current leaky property on the stream, but
can be reset to non-leaky by ismd_demux_disable_leaky_filters.

Section filters are always set to leaky when created, regardless of the stream's
leaky property. Other filters default to the stream's leaky property when created.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.

@retval ISMD_SUCCESS : the mode was changed
@retval ISMD_ERROR_INVALID_HANDLE : handle or filter_handle is invalid.
*/

ismd_result_t SMDEXPORT ismd_demux_filter_enable_leaky(ismd_dev_t handle,
                                                ismd_demux_filter_handle_t filter_handle);

/**
Disable leaky filter on the demux.  This disables dropping of smd buffers if no
space is available on the filter output port. This is a per filter property, which
overrides the current leaky property on the stream, but can be reset to non-leaky
by ismd_demux_disable_leaky_filters.

Section filters are always set to leaky when created, regardless of the stream's
leaky property. Other filters default to the stream's leaky property when created.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.

@retval ISMD_SUCCESS : the mode was changed
@retval ISMD_ERROR_INVALID_HANDLE : handle or filter_handle is invalid.
*/

ismd_result_t SMDEXPORT ismd_demux_filter_disable_leaky(ismd_dev_t handle,
                                                ismd_demux_filter_handle_t filter_handle);


/**
Enables pvt data extraction on a single PES PID.  All the "ES Type" filters
mapped to the specified PID will get the pvt_data on the buffer descriptors.
If a PID is invalid, an error is returned.  If the private data extraction is
already enabled on the PID, the function returns no error.

This fuction causes the Demux to send private data on this PID from the stream
's (the handle used to allocate this filter) input to
the all the ES filters (which are enabled) mapped to this PID.  The specified
PID must be mapped to atleast one ES filter.  If it is mapped to multiple ES
filters, all the filters will receive private data associated with this PID
as a buffer descriptor attribute.

Private data extraction  is disabled by default on all PID's.

@param[in] handle : Demux stream handle.
@param[in] pid_val : pid on which private data extraction is to be enabled.

@retval ISMD_SUCCESS : Private data filtering is enabled on the specified PID
on all the ES filters mapped to this pid.
@retval ISMD_ERROR_INVALID_HANDLE : Device handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : If the specified PID is not mapped to
any ES filter or if the specified is not PES pid. OR If the input stream type
is not TS188 or TS192 stream type.
*/

ismd_result_t SMDEXPORT ismd_demux_enable_pes_pvt_data(ismd_dev_t handle,
                                                         uint16_t pid_val);

/**
Disables pvt data extraction on a single PES PID for a particular filter.
All the "ES Type" filters mapped to the specified PID will not get the
pvt_data on the buffer descriptors anymore.  If a PID is invalid, an error is
returned.  If the private data extraction is already disabled on the PID, the
function returns no error.

Private data extraction is disabled by default on all PID's.

@param[in] handle : Demux stream handle.
@param[in] pid_val : pid on which private data extraction is to be disabled.

@retval ISMD_SUCCESS : Private data filtering is disabled on the specified
PID on all the ES filters mapped to this pid.
@retval ISMD_ERROR_INVALID_HANDLE : Device handle is invalid.
*/

ismd_result_t SMDEXPORT ismd_demux_disable_pes_pvt_data(ismd_dev_t handle,
                                                          uint16_t pid_val);


/**
Sets the event the TSIN is to strobe when overrun occurs.  Defaults to invalid.  Can be set to invalid (ISMD_EVENT_HANDLE_INVALID) to disable event strobing.  Only one listener supported - so if the buffering monitor is being used, the client should NOT register its own event here.

@param[in] handle : Demux device handle.
@param[in] overrun_event: the handle of the event to be strobed.

@retval ISMD_SUCCESS : The client's overrun event has been successfully registered.
@retval ISMD_ERROR_INVALID_HANDLE: The handle provided is not valid.
*/

ismd_result_t SMDEXPORT ismd_tsin_set_overrun_event(ismd_dev_t handle,
                                    ismd_event_t overrun_event);


/**
Disables buffer splitting for the specified filter.

Normally the demux will terminate an output buffer before it has been
completely filled up if there is some metadata that must be associated to
a position in the stream.  This includes
* tags
* discontinuities
* PTS values

Buffers can also be terminated if there has been a long time since the
previous buffer was terminated.  This is to prevent stale data from being
held inside of the demux.

All of this early buffer termination - called "splitting" -
(which results in buffers not being completely filled)
can be disabled with this API.  Note that by disabling buffer splitting the
association of timestamps and tags will not be as accurate, and this mode
of operation is therefore inappropriate for A/V playback.  It is useful for
recording however where timestamps/tags are usually less useful and often
ignored outright.

The default state for a new filter is to have buffer splitting enabled.

NOTE: even with buffer splitting disabled, there is a chance that output
buffers are not completely filled.  The demux makes TS packet (or payload)
writes atomic so as not to split packets (and consequently possibly have
partial packets in a recording).  This means that in order to ensure a TS
packet recording  buffer is completely filled, its size (as specified when
creating the filter) must be a multiple of the recorded packet size.

This API is only supported for data filters obtained from
\ref ismd_demux_filter_open() or \ref ismd_demux_filter_open_preset_buffers().
Attempts to use this on other filter types such as section filters or
indexing filters will fail.

@param[in] handle        : Demux stream handle to use.
@param[in] filter_handle : Demux stream handle to use.

@retval ISMD_ERROR_INVALID_HANDLE  : handle or filter_handle are not valid or
                                     have been previously closed.
@retval ISMD_ERROR_INVALID_REQUEST : The specified filter is for PSI or
                                     indexing data.
*/
ismd_result_t SMDEXPORT
ismd_demux_filter_disable_buffer_splitting(
                              ismd_dev_t                        handle,
                              ismd_demux_filter_handle_t        filter_handle);

/**
See the documentation for \ref ismd_demux_filter_disable_buffer_splitting().

This API returns the filter to the default state of allowing buffers to be
split when metadata must be associated to a specific point in the data stream.

@param[in] handle        : Demux stream handle to use.
@param[in] filter_handle : Demux stream handle to use.

@retval ISMD_ERROR_INVALID_HANDLE  : handle or filter_handle are not valid or
                                     have been previously closed.
@retval ISMD_ERROR_INVALID_REQUEST : The specified filter is for PSI or
                                     indexing data.
*/
ismd_result_t SMDEXPORT
ismd_demux_filter_enable_buffer_splitting(
                              ismd_dev_t                        handle,
                              ismd_demux_filter_handle_t        filter_handle);

/**
Controls how continuity counter errors are handled on a per-PID basis.
See the enumeration of the possible values that can be set for a description
of the limitations.  This can be called any time before or during processing,
but the PID being configured must already be used for section or data filtering.
(settings are not stored for PIDs that are not being used).
Also note that if the specified PID gets freed as a result of it being
removed from all filtering then the setting  will be lost and must be
re-applied after the PID is re-added for filtering.
The default behavior if this is not called is ISMD_DEMUX_TS_CC_IGNORE_ERRORS.

@param[in] handle : Demux stream handle.
@param[in] pid    : PID to configure.  If the PID is not being used for any
                    section filtering and is not mapped to any filters then
                    this API will fail.
@param[in] policy : Policy to set.

@retval ISMD_SUCCESS                     : The policy was successfully set.
@retval ISMD_ERROR_INVALID_HANDLE        : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER     : The policy value is not valid.
@retval ISMD_ERROR_INVALID_REQUEST       : The PID is not in use.
@retval ISMD_ERROR_FEATURE_NOT_SUPPORTED : Not supported on this SOC.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_cc_error_policy(
                                    ismd_dev_t                       handle,
                                    uint16_t                         pid,
                                    ismd_demux_ts_cc_error_policy_t  policy);



/*! @name Enabling/Disabling functions. */

/**
Enables processing of data by a filter.

NOTE:  All filters are enabled (started) by default when a the filter is
opened using ismd_demux_filter_open().  Therefore, it is not necessary to call
this function for initial configuration.

Pre-conditions required for this function:
* The handle must point to a valid demux stream
* The filter handle must point to a valid filter
* The filter must belong to a stream
* The filter must have previously been stopped using ismd_demux_filter_stop()

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.

@retval ISMD_SUCCESS : The filter was successfully started.
@retval ISMD_ERROR_INVALID_HANDLE : handle or filter_handle is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_start(ismd_dev_t        handle,
                                         ismd_demux_filter_handle_t filter_handle);


/**
Disables processing of data by a filter.  This will cause the filter to stop
generating output.  Stream processing of any remaining filters will continue.
This function also forces the filter to be flushed.

Pre-conditions required for this function:
* The handle must point to a valid demux stream
* The filter_handle must point to a valid filter
* The filter must belong to a stream

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.

@retval ISMD_SUCCESS : The filter was successfully stopped.
@retval ISMD_ERROR_INVALID_HANDLE : handle or filter_handle is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_stop(ismd_dev_t        handle,
                                        ismd_demux_filter_handle_t filter_handle);



/**
Force the filter to be flushed.

Pre-conditions required for this function:
* The handle must point to a valid demux stream
* The filter_handle must point to a valid filter
* The filter must belong to a stream

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.

@retval ISMD_SUCCESS : The filter was successfully stopped.
@retval ISMD_ERROR_INVALID_HANDLE : handle or filter_handle is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_flush(ismd_dev_t        handle,
                                        ismd_demux_filter_handle_t filter_handle);

/**
Register a overrun event to a filter.

Description: This function is used to register a handle in output filter to get
overrun event. When Demux found the output filter was full and overrun event
handle is valid, an OVERRUN event will be triggered.

@param[in] handle : Demux stream handle
@param[in] filter_handle : Demux filter handle
@param[in] overrun_event : Overrun event

@retval ISMD_SUCCESS : The op was success
@retval ISMD_ERROR_INVALID_HANDLE : either handle or filter_handle are wrong
*/
ismd_result_t SMDEXPORT ismd_demux_filter_set_overrun_event(ismd_dev_t handle,
                                ismd_demux_filter_handle_t filter_handle,
                                ismd_event_t overrun_event);

/**
Register a overrun recovered event to a filter.

Description: This function is used to register a handle in output filter to get
OVERRUN RECOVERED event. When a filter from OVERRUN state to normal state
and the event handle is valid, an OVERRUN RECOVERED event will be triggered.

@param[in] handle : Demux stream handle
@param[in] filter_handle : Demux filter handle
@param[in] overrun_recovered_event : Overrun recovered event

@retval ISMD_SUCCESS : The op was success
@retval ISMD_ERROR_INVALID_HANDLE : either handle or filter_handle are wrong
*/
ismd_result_t SMDEXPORT ismd_demux_filter_set_overrun_recovered_event(ismd_dev_t handle,
                                ismd_demux_filter_handle_t filter_handle,
                                ismd_event_t overrun_recovered_event);

/**
Enables processing of a PID for any filter which this is mapped to.

NOTE:  All PIDs are enabled (started) by default when a filter is mapped to
to the PID.  Therefore, it is not necessary to call this function for initial
configuration.

Pre-conditions required for this function:
* The handle must point to a valid demux stream
* The specified PID exists in the streams list of PIDs.
* This PID filter has previously been stopped by calling ismd_demux_pid_stop()

@param[in] handle : Demux stream handle.
@param[in] pid : Specifes the PID to start.

@retval ISMD_SUCCESS : The PID is successfully started.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The PID does not exist in the stream.
*/
ismd_result_t SMDEXPORT ismd_demux_pid_start(ismd_dev_t        handle,
                                         uint16_t pid);

/**
Disables processing of a PID for any filter which this PID is mapped to.
The demux will continue to process the stream for any other PIDs that have
not been stopped.

Pre-conditions required for this function:
* The handle must point to a valid demux stream
* The specified PID exists in the streams list of PIDs.

@param[in] handle : Demux stream handle.
@param[in] pid : Specifes the PID to stop.

@retval ISMD_SUCCESS : The PID is successfully stopped.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The PID does not exist in the stream.
*/
ismd_result_t SMDEXPORT ismd_demux_pid_stop(ismd_dev_t        handle,
                                        uint16_t pid);


/*! @name Crypto functions */


/**
Loads a key for the specified PID. The keys are used to
decrypt the payload data with the specified PID.  The key may be a key value,
or an 8-bit numeric identifier for a key to load from the security processor.

@param[in] handle : Demux stream handle.
@param[in] pid : Specifes the PID.  The PID should be mapped to a filter before
this function is called. To map a PID use the function
ismd_demux_filter_map_to_pids.
@param[in] algorithm : Crypto algorithm and mode.
@param[in] residual_type : For generic algorithms (DES,3DES, AES), configures how residual bytes (a partial block) are to be handled.  Ignored for Multi2 and DVB-CSA.
@param[in] key_length : Length (in bytes) of the key.
@param[in] odd_or_even : Specified whether the key is odd or even, it is only
                       effective when input stream is transport stream.
@param[in] key_data : Key data.  If the key_length is 1, key_data holds the
                      key identifieer for loading from the security processor
@param[in] iv : Initialization vector if needed, NULL otherwise.
@param[in] iv_length : Specified the Initialization Vector length in bytes.

@retval ISMD_SUCCESS : The key was loaded successfully.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : key_length or iv_length is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The key type or the algorithm specified is not valid.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_load_key(ismd_dev_t        handle,
                                            uint16_t pid,
                                            ismd_demux_crypto_algorithm_t algorithm,
                                            ismd_demux_crypto_residual_mode_t residual_type,
                                            ismd_demux_key_type_t odd_or_even,
                                            ismd_demux_crypto_info_t key_data,
                                            unsigned int key_length,
                                            ismd_demux_crypto_info_t iv,
                                            unsigned int iv_length);

/**
Loads decryption parameters, like algorithm, IV, for the specified PID.
Those parameters along with keys are used to
decrypt the payload data with the specified PID.
Note! This function must be called before calling ismd_demux_ts_set_key
and ismd_demux_ts_set_system_key

@param[in] handle : Demux stream handle.
@param[in] pid : Specifes the PID.  The PID should be mapped to a filter before
this function is called. To map a PID use the function
ismd_demux_filter_map_to_pids.
@param[in] algorithm : Crypto algorithm and mode.
@param[in] residual_type : For generic algorithms (DES,3DES, AES), configures
how residual bytes (a partial block) are to be handled.  Ignored for Multi2 and DVB-CSA.
@param[in] iv : Initialization vector if needed, NULL otherwise.
@param[in] iv_length : Specified the Initialization Vector length in bytes.

@retval ISMD_SUCCESS : The params were loaded successfully.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : iv_length is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The residual type or the algorithm or
iv length specified is not valid.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_crypto_params(ismd_dev_t        handle,
                                            uint16_t pid,
                                            ismd_demux_crypto_algorithm_t algorithm,
                                            ismd_demux_crypto_residual_mode_t residual_type,
                                            ismd_demux_crypto_info_t iv,
                                            unsigned int iv_length);

/**
Set decryption system key for the specified stream.
System key is only used by multi-2 and is shared by sub-elements in one stream
Note! This function must be called after ismd_demux_ts_set_crypto_params

@param[in] handle : Demux stream handle.
@param[in] skey: system key used by multi2.
@param[in] skey_len: system key length

@retval ISMD_SUCCESS : The system key was loaded successfully.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The decrypto algorithm of specified stream
is not multi2. User should first use ismd_demux_ts_set_crypto_paras to
set the decrypto algorithm before calling this.
@retval ISMD_ERROR_INVALID_PARAMETER : skey length is invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_system_key(ismd_dev_t        handle,
                                            ismd_demux_crypto_info_t skey,
                                            unsigned int skey_len);




/**
Loads a key for the specified PID. The keys are used to
decrypt the payload data with the specified PID.  The key may be a key value,
or an 8-bit numeric identifier for a key to load from the security processor.
Note! 1.This function must be called after ismd_demux_ts_set_crypto_params
      2.In case of 3DES, if key length equals to 8 or 16, key will be automatically
        expanded to 24 bytes by appending the first 8 bytes

@param[in] handle : Demux stream handle.
@param[in] pid : Specifes the PID.  The PID should be mapped to a filter before
this function is called. To map a PID use the function
ismd_demux_filter_map_to_pids.
@param[in] key_length : Length (in bytes) of the key.
@param[in] odd_or_even : Specified whether the key is odd or even, it is only
                       effective when input stream is transport stream.
@param[in] key_data : Key data.  If the key_length is 1, key_data holds the
                      key identifieer for loading from the security processor

@retval ISMD_SUCCESS : The key was loaded successfully.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : key length or key type (odd or even) is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The handle or pid is not valid.
*/
ismd_result_t SMDEXPORT ismd_demux_ts_set_key(ismd_dev_t        handle,
                                            uint16_t pid,
                                            ismd_demux_key_type_t odd_or_even,
                                            ismd_demux_crypto_info_t key_data,
                                            unsigned int key_length);

/**
Enables crypto on the specified filter.  It has no effect if the
transport packets passing through the filter are not encrypted or the PID didn't
have an algorithm and key set for descrambling.  By default, all filters have crypto disabled.
Note: before enable crypto on a filter, the decrytion parameters and key must be set
correctly using ismd_demux_ts_set_key and ismd_demux_ts_set_crypto_params.

@param[in] handle : Demux stream handle.
@param[in] filter_handle : Demux filter handle.
@param[in] enable_decryption : Specifies whether to enable decryption on the filter or not

@retval ISMD_SUCCESS : Crypto was successfully enabled.
@retval ISMD_ERROR_INVALID_HANDLE : filter_handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : the filter_handle is an indexer filter.
*/
ismd_result_t SMDEXPORT ismd_demux_filter_set_ts_crypto(ismd_dev_t        handle,
                                                     ismd_demux_filter_handle_t filter_handle,
                                                     bool enable_decryption);

/**
Loads descramble parameters for the crypto unit associated with the specified
PID.  These parameters along with keys loaded by the
\ref ismd_demux_descramble_set_key and \ref ismd_demux_descramble_set_system_key
APIs are used to descramble payload data with the specified PID.

NOTE: This function must be called before calling \ref ismd_demux_descramble_set_key
and \ref ismd_demux_descramble_set_system_key.

NOTE: This API is designed to replace the old ismd_demux_ts_set_crypto_params()
API.  It covers all the same functionality but in a more flexible manner.
Eventually the old \ref ismd_demux_ts_set_crypto_params() API should be depricated.
It is currently maintained for the sake of backwards compatiblity.

@param[in] handle        : Demux stream handle.
@param[in] pid           : Specifes the PID.  The PID should be mapped to a
                           filter before this function is called. To map a PID
                           use the function ismd_demux_filter_map_to_pids.
@param[in] algorithm     : Crypto algorithm and mode.
@param[in] residual_type : For generic algorithms (DES,3DES, AES), configures
                           how residual bytes (a partial block) are to be
                           handled.  Ignored for Multi2 and DVB-CSA.
@param[in] iv            : Initialization vector if needed.
@param[in] iv_length     : Initialization vector length in bytes (0 if unused).
@param[in] iv_byte_order : Specifies the byte order of the IV provided by the
                           caller.

@retval ISMD_SUCCESS                 : The params were loaded successfully.
@retval ISMD_ERROR_INVALID_HANDLE    : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : iv_length is invalid.
@retval ISMD_ERROR_INVALID_REQUEST   : Invalid residual type or algorithm.
*/
ismd_result_t SMDEXPORT ismd_demux_descramble_set_params(
                              ismd_dev_t                          handle,
                              uint16_t                            pid,
                              ismd_demux_crypto_algorithm_t       algorithm,
                              ismd_demux_crypto_residual_mode_t   residual_type,
                              ismd_demux_crypto_info_t            iv,
                              unsigned int                        iv_length,
                              ismd_demux_key_byte_order_t         iv_byte_order);

/**
Sets up either direct or indirect key loading parameters for the crypto unit
associated with the given PID.  Parameters are passed via a structure pointer
of type \ref ismd_demux_key_params_t.  For direct key loading, the byte ordering of
the key can be specified by the key_byte_order field of the key_params data
structure.  To be backwards compatible with the old \ref ismd_demux_ts_set_key and
\ref ismd_demux_ts_load_key APIs, set the key_params.key_byte_order parameter to
ISMD_DEMUX_KEY_BYTE_ORDER_REVERSE.

NOTE: Use \ref ismd_demux_descramble_set_params API to setup the descramble params
prior to calling this API.

NOTE: This API is designed to replace the old \ref ismd_demux_ts_set_key() and
\ref ismd_demux_ts_load_key() APIs.  It covers all the same functionality but in a
more flexible manner. Eventually the old \ref ismd_demux_ts_set_key() and
\ref ismd_demux_ts_load_key() APIs should be depricated.  They are currently
maintained for the sake of backwards compatiblity.


@param[in] handle     : Demux stream handle.
@param[in] pid        : Specifes the PID.  The PID should be mapped to a filter
                        before this function is called. To map a PID use the
                        function ismd_demux_filter_map_to_pids.
@param[in] key_params : Pointer to structure containing direct or indirect key
                        loading parameters.

@retval ISMD_SUCCESS                 : The key setup was successful.
@retval ISMD_ERROR_INVALID_HANDLE    : Handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : One or more invalid parameters.
*/
ismd_result_t SMDEXPORT ismd_demux_descramble_set_key(
                                          ismd_dev_t              handle,
                                          uint16_t                pid,
                                          ismd_demux_key_params_t *key_params);

/**
Sets the system key for the Multi-2 crypto unit.  The byte ordering of
the key can be specified by the key_byte_order parameter.  To be backwards
compatible with the old \ref ismd_demux_ts_set_system_key, set the key_byte_order
parameter to ISMD_DEMUX_KEY_BYTE_ORDER_REVERSE.

NOTE: Use \ref ismd_demux_descramble_set_params API to setup the descramble params
prior to calling this API.

NOTE: This API is designed to replace the old ismd_demux_ts_set_system_key()
API.  It covers all the same functionality but in a more flexible manner.
Eventually the old \ref ismd_demux_ts_set_system_key() API should be depricated.
It is currently maintained for the sake of backwards compatiblity.

@param[in] handle          : Demux stream handle.
@param[in] skey            : The system key data bytes.
@param[in] skey_len        : The system key length in bytes.
@param[in] skey_byte_order : Specifies the byte order of the key provided by
                             the caller.

@retval ISMD_SUCCESS                 : The system key was loaded successfully.
@retval ISMD_ERROR_INVALID_HANDLE    : Handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER : One or more of the key params invalid.
*/
ismd_result_t SMDEXPORT ismd_demux_descramble_set_system_key(
                                 ismd_dev_t                    handle,
                                 ismd_demux_crypto_info_t      skey,
                                 unsigned int                  skey_len,
                                 ismd_demux_key_byte_order_t   skey_byte_order);

/**
Returns the value of demux information counters
@param[in] handle : Demux stream handle.
@param[in] pid : The PID, for pid specific statistics
@param[out] stats : the values of the requested information counters

@retval ISMD_SUCCESS : Stat was received.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : pid is not configured.
*/
ismd_result_t SMDEXPORT ismd_demux_get_stats(ismd_dev_t        handle,
                                         unsigned int pid,
                                         ismd_demux_stats_t *stats);

/**
Resets the value of a requested information counter
@param[in] handle : Demux stream handle.
@param[in] type : Specifies what information to reset
@param[in] pid : The PID, if resetting a PID-specific counter (e.g. ISMD_DEMUX_STAT_PES_COUNT)

@retval ISMD_SUCCESS : Stat was reset.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : type is invalid or pid is not configured.
*/
ismd_result_t SMDEXPORT ismd_demux_reset_stat(ismd_dev_t        handle,
                                    ismd_demux_stat_t type,
                                    unsigned int pid);
/*! @name NIM configuration functions. */

/**
This function configures the NIM for the specified handle.
This function is optional and won't need to be called unless the defaults
described below do not match the NIM that the TSI is connected to. <br>

The following default settings will be used if this function is not called: <br>
nim_config->nim_mode = ISMD_DEMUX_PI_NIM_PARALLEL (for all modes except 1394 input)
nim_config->nim_mode = ISMD_DEMUX_PI_NIM_SERIAL (for 1394 input)
nim_config->clk_polarity = ISMD_DEMUX_PI_POS_CLOCK
nim_config->dv_polarity = ISMD_DEMUX_PI_POS_DV
nim_config->err_polarity = ISMD_DEMUX_PI_POS_ERR
nim_config->sync_polarity = ISMD_DEMUX_PI_POS_SYNC

@param[in] handle : Demux stream handle.
@param[in] nim_config : Configuration for the NIM.

@retval ISMD_SUCCESS : The configuration was successfully set.
@retval ISMD_ERROR_INVALID_HANDLE : handle is not a valid active handle.
@retval ISMD_ERROR_NULL_POINTER : nim_config is NULL.
@retval ISMD_ERROR_INVALID_REQUEST : This is not a PI handle or nim_config contains an invalid configuration
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_set_nim_config(ismd_dev_t        handle,
                                      ismd_demux_tsin_nim_config_t *nim_config);



/**
This function gets the overall input buffer size and the actual run-time buffer level for
a specified stream.

@param[in] handle : Demux stream handle.
@param[out] buffer_size: pointer to the overall input buffer size in bytes.
@param[out] buffer_level: pointer to the actual buffer level of the input buffer in bytes.

@retval ISMD_SUCCESS : The buffer level and buffer size have been obtained successfully.
@retval ISMD_ERROR_INVALID_HANDLE :  handle is not a valid active handle.
@retval ISMD_ERROR_NULL_POINTER : buffer_size or buffer_level were supplied as NULL.
@retval ISMD_ERROR_INVALID_REQUEST : The DMA has not yet been connected.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_get_buffer_level(ismd_dev_t        handle,
                                     unsigned int *buffer_size,
                                     unsigned int *buffer_level);



/**
Sets the physical input's buffer size for a specified stream.  The size of the buffer determines how much of a stream can be buffered in memory by the physical input in memory before stream loss occurs.

@param[in] handle : Demux stream handle.
@param[in] buffer_size: the input buffer size in bytes.

@retval ISMD_SUCCESS : The buffer size has been set successfully.
@retval ISMD_ERROR_INVALID_HANDLE :  handle is not a valid active handle.
@retval ISMD_ERROR_INVALID_REQUEST : The DMA has not yet been connected.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_set_buffer_size(ismd_dev_t        handle,
                                    unsigned int buffer_size);


/**
This function enables clock recovery based on the specified PCR PID.  If the PID was
not already added to the PID filter then it will be unless all of the
PID filter slots have already been filled, in which case an error will
be reported.  If another PID is currently selected for clock recovery,
clock recovery on that PID will be discontinued and this one will be used.
The old clock recovery PID will still be in the PID filter.

@param[in] handle : Demux stream handle.
@param[in] pcr_pid : PCR PID to use for clock recovery.

@retval ISMD_SUCCESS : The specified PCR PID will be used for clock recovery.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_NO_RESOURCES : the PID filter is full.
@retval ISMD_ERROR_INVALID_REQUEST : The selected use case does not involve the PID filter.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_enable_clock_recovery(ismd_dev_t        handle,
                                                    uint16_t pcr_pid);


/**
This function disables clock recovery.  The PCR PID will remain in the PID filter.

@param[in] handle : Demux stream handle.

@retval ISMD_SUCCESS : Clock recovery is disabled for this hande.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The selected use case does not involve the PID filter.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_disable_clock_recovery(ismd_dev_t        handle);


/**
Gets the clock.

@param[in] handle : Demux stream handle.
@param[out] clock : Pointer to the stream's clock.

@retval ISMD_SUCCESS : Clock recovery is disabled for this hande.
@retval ISMD_ERROR_INVALID_HANDLE : handle is invalid.
@retval ISMD_ERROR_INVALID_REQUEST : The selected use case does not involve the PID filter.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_get_clock(ismd_dev_t        handle,
                                    ismd_clock_t* clock);


/**
Allows manual override over the upper two bits in the 32-bit extra header that
is prepended to each TS packet received through the TSI.  Some applications
use these bits to hold copy permission information.

By default, the 32-bit extra header contains a 32-bit arrival timetstamp
(sampled from the clock assigned to the demux).  If this API is used, the upper
two bits are forced to the value of the upper two bits in the supplied bits
parameter, and the timestamp only occupies 30 bits.

param[in] demux_handle : handle for the demux stream
param[in] bits : value to force the upper two bits of the 32-bit header to.
                 Only the upper two bits of this value are used.
                 If any bits other than the upper two are set, an error is
                 returned.

@retval ISMD_SUCCESS : the bits were stored.
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.
@retval ISMD_ERROR_INVALID_PARAMETER : the bits parameter has bits set
                                       that are not the upper two bits.
                                       This is probably not the intended
                                       behavior.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_set_ts192_upper_bits(
                                               ismd_dev_handle_t demux_handle,
                                               uint32_t bits);

/*! @name Section Filter Functions. */

/**
Add a new section filter to the system.  When matches are found, section data
will be written out the port associated with the PSI filter associated with the
section filter.  Multiple section filters for the same pid can be associated
with the same PSI filter, and when using demux Ver2, the pid should be the same when using
multiple section filters for the same PSI filter,

@param[in] handle : Pointer to the stream handle that the filter will be
    associated with.
@param[in] filter : handle to a PSI filter created prior to this call
@param[in] pid : PID this section filter will operate upon.
@param[out] section_filter_handle : unique ID associated with this section
    filter.  When retrieving a completed section table,  this ID will be
    associated with the section table data so the client knows which section
    filter was used to find the match.

@retval ISMD_SUCCESS : Section filter was successfully set up
@retval ISMD_NULL_POINTER : section_filter structure passed in was NULL
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_open(ismd_dev_handle_t handle,
                                                ismd_demux_filter_handle_t filter,
                                                uint16_t pid,
                                                ismd_demux_section_filter_handle_t* section_filter_handle);

/**
Set the match information for a section filter.  Until called for the first
time, a newly opened section filter is inactive.

Allows configuring a matching TID and a matching byte region of the PSI section.

The sf_params variable has several methods to determine whether or not
a PSI section is allowed or discarded.  The tid field sets the expected TID
value of the PSI section.  The section_offset field controls the byte offset
into the PSI section where pattern matching will be performed. All valid bits
in the positive match must then match, and if there is a non-zero negative mask,
at least one valid bit in the negative match must not match.

As a special case, the tid field in the section params can be ignored by
configuring the section_offset field to be 0.  If at least one bit in
either positive or negative mask fields is set, the tid field is ignored and
instead the TID byte in the PSI section is treated as part of the standard
pattern match.  This enables enables filtering of multiple TIDs with while using
only one section filter.

@param[in] handle : Pointer to the stream handle that the filter is associated with.
@param[in] section_filter_handle : unique ID of this section filter.
@param[in] sf_params: new configuration information for the section filter.

@retval ISMD_SUCCESS : Section filter was successfully deleted
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream or
                                    section_filter_handle is not valid
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_set_params(ismd_dev_handle_t handle,
                                                ismd_demux_section_filter_handle_t section_filter_handle,
                                                ismd_demux_section_filter_params_t* sf_params);

/**
Remove an existing section filter from the system.

@param[in] handle : Pointer to the stream handle that the filter is associated with.
@param[in] section_filter_handle : unique ID of this section filter.

@retval ISMD_SUCCESS : Section filter was successfully deleted
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream or
                                    section_filter_handle is not valid
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_close(ismd_dev_handle_t handle,
                                                ismd_demux_section_filter_handle_t section_filter_handle);


/**
Start a single section filter

@param[in] handle : Pointer to the stream handle that the filter is associated with.
@param[in] section_filter_handle : unique ID of section filter to start

@retval ISMD_SUCCESS : Section filters was successfully started
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream or
                                    section_filter_handle is not valid
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_start(ismd_dev_handle_t handle,
                                                ismd_demux_section_filter_handle_t section_filter_handle);


/**
Stop a single section filter

@param[in] handle : Pointer to the stream handle that the filter is associated with.
@param[in] section_filter_handle : unique ID of section filter to stop

@retval ISMD_SUCCESS : Section filter was successfully stopped
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream or
                                    section_filter_handle is not valid
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_stop(ismd_dev_handle_t handle,
                                                ismd_demux_section_filter_handle_t section_filter_handle);


/**
Start all section filters associated with a given PID

@param[in] handle : Pointer to the stream handle that the filter is associated with.
@param[in] pid : PID of section filters to start

@retval ISMD_SUCCESS : Section filters were successfully started
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream
@retval ISMD_ERROR_INVALID_PARAMETER : no section filters for this PID
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_start_all_by_pid(ismd_dev_handle_t handle,
                                                uint16_t pid);


/**
Stop all section filters associated with a given PID

@param[in] handle : Pointer to the stream handle that the filter is associated with.
@param[in] pid : PID of section filters to stop

@retval ISMD_SUCCESS : Section filters were successfully stopped
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream
@retval ISMD_ERROR_INVALID_PARAMETER : no section filters for this PID
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_stop_all_by_pid(ismd_dev_handle_t handle,
                                                uint16_t pid);

/**
Register a PSI/Section CRC Error event to a filter.

Description: This function is used to register a handle in output filter to get
a PSI CRC ERROR event. When a PSI/Section CRC error is encountered on the
filter, an PSI CRC ERROR event will be triggered. Set crc_event_handle to
ISMD_EVENT_HANDLE_INVALID in order to disable CRC event reporting.

@param[in] handle : Demux stream handle
@param[in] section_filter_handle : Demux section filter handle
@param[in] crc_event_handle : PSI CRC ERROR event handle

@retval ISMD_SUCCESS : The op was success
@retval ISMD_ERROR_INVALID_HANDLE : either handle or section_filter_handle are invalid
*/
ismd_result_t SMDEXPORT ismd_demux_section_filter_set_crc_event(
                                ismd_dev_t handle,
                                ismd_demux_section_filter_handle_t section_filter_handle,
                                ismd_event_t crc_event_handle);

/**
Configure CRC check policy for the specified section filter.
Various section filter for one PID can have different policies.

@param[in] handle : Stream handle that the filter is associated with.
@param[in] section_filter_handle : unique ID of this section filter.
@param[in] policy: CRC check policy.

@retval ISMD_SUCCESS                   : The policy was successfully set.
@retval ISMD_ERROR_INVALID_HANDLE      : handle is invalid.
@retval ISMD_ERROR_INVALID_PARAMETER   : The policy value is not valid.
*/

ismd_result_t SMDEXPORT ismd_demux_section_filter_set_crc_check_policy(
                           ismd_dev_t handle,
                           ismd_demux_section_filter_handle_t section_filter_handle,
                           ismd_demux_section_filter_crc_check_policy_t  policy);

/**
Configure a buffer event notification for a demux stream.

The buffering event is triggered when two conditions are met.
1) A PTS and data have reached the demux's output.
2) The localized reference time (PCR or SCR) in the stream is equal or greater
   than buffer_time.

The first condition ensures data is flowing through the demux, and
localization of PTS timestamps has begun.

The second condition can be used to know when a a certain amount of buffering
has arrived and passed through the demux.

A previous, untriggered buffering event request can be cancelled by passing in
an event of ISMD_EVENT_HANDLE_INVALID.

This buffering event is only valid for normal, 1x forward playback.

@param[in] devhandle : Pointer to the stream handle that the filter is associated with.
@param[in] event : Event to be triggered when the buffering condition is reached
@param[in] buffer_time : Amount of stream time to buffer (in 90000 Hz units)

@retval ISMD_SUCCESS : Section filters were successfully stopped
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream
*/
ismd_result_t SMDEXPORT ismd_demux_set_buffering_event(ismd_dev_t devhandle, ismd_event_t event, unsigned buffer_time);





/**
Enable and disable the demux discontinuity hadling based on the arrival time
of the discontinuous PCRs. The newsegments generated have linear time based
on time values taken from local clock.

@param[in] devhandle : Demux stream handle
@param[in] status : true or false

@retval ISMD_SUCCESS : Section filters were successfully stopped
@retval ISMD_ERROR_INVALID_HANDLE : handle does not point to a valid stream
@retval ISMD_ERROR_INVALID_REQUEST : clock should be set in the demux to
                                     calculate arrival times
*/
ismd_result_t SMDEXPORT ismd_demux_stream_use_arrival_time(ismd_dev_t devhandle, bool status);



/**@}*/ // end of annoymous group (look for @{ near line 204)


/*! @name MSPOD Functions. */
/**
Set the LTSID (Local Trasnport Stream IDentifier) in the open cable header
The LTSID value accepted is limited to the values 0-15 as the hardware sets
the upper bits to a unique value.  Use ismd_demux_tsin_get_open_cable_ltsid
to determine the LTSID that the POD will see.  If this API is not called the
driver will automatically assign individual LTSID's for OC enabled streams.
These LTSID's can be read using ismd_demux_tsin_get_open_cable_ltsid.

The operation fails if the open cable connection is single stream.

@param[in] demux_handle : handle for the demux
@param[in] ltsid : value desired for the LTSID associated with this TSIN

@retval ISMD_SUCCESS : LTSID set for the stream
@retval ISMD_ERROR_OPERATION_FAILED : The demux stream is not connected to an
open cable source or the mode of the stream is single stream and at least one
other stream is being routed to the POD.
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid
@retval ISMD_ERROR_INVALID_PARAMETER : The ltsid value is out of range
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_set_open_cable_ltsid(ismd_dev_handle_t demux_handle,
                                                   uint8_t ltsid);


/**
Get the LTSID (Local Trasnport Stream IDentifier) in the open cable header
associated with the stream.

@param[in] demux_handle : handle for the demux
@param[out] ltsid : pointer to storage for ltsid

@retval ISMD_SUCCESS : *ltsid updated with current LTSID for the stream.
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.
@retval ISMD_ERROR_OPERATION_FAILED : The demux stream is not connected to an
open cable source or the mode of the stream is single stream.
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_get_open_cable_ltsid(ismd_dev_handle_t demux_handle,
                                                   uint8_t *ltsid);


/**
Specify the mode of the open cable stream (single stream, multi-stream,
or not an open cable stream).  For the case of not an open cable stream the
data is not sent to the POD.  By default the mode is set to
ISMD_DEMUX_NO_OPEN_CABLE.

@param[in] demux_handle : handle for the demux
@param[in] mode : specifies the mode to set for the stream

@retval ISMD_SUCCESS : the mode was changed
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.
@retval ISMD_ERROR_INVALID_PARAMETER : An invalid mode value was supplied
@retval ISMD_ERROR_OPERATION_FAILED : The demux stream is not connected to an
open cable source or changing to the requested mode would result in a conflict
(more than one stream in single stream mode or a combination of multi stream
and single stream)

*/
ismd_result_t SMDEXPORT ismd_demux_tsin_set_open_cable_mode(ismd_dev_handle_t demux_handle,
                                                  enum ismd_demux_open_cable_mode mode);


/**
Get the open cable mode for the supplied stream.

param[in] demux_handle : handle for the demux stream
param[out] mode : pointer to store the mode of the stream

@retval ISMD_SUCCESS : the mode was changed
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.
@retval ISMD_ERROR_NULL_POINTER : the mode pointer is NULL
*/
ismd_result_t SMDEXPORT ismd_demux_tsin_get_open_cable_mode(ismd_dev_handle_t demux_handle,
                                                  enum ismd_demux_open_cable_mode *mode);



/* The following two API's only used for testing ms-pod internally */

/* *************************************************************** */
ismd_result_t SMDEXPORT ismd_demux_tsin_enable_internal_bypass(void);
ismd_result_t SMDEXPORT ismd_demux_tsin_disable_internal_bypass(void);
/* *************************************************************** */


/**
Get the handle of clock sync.

param[in] demux_handle : handle for the demux stream
param[out] recovery_clock : pointer to clock syn

@retval ISMD_SUCCESS : clock sync handle is sussessfully gotten.
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is not valid.
@retval ISMD_ERROR_NULL_POINTER : the recovery_clock pointer is NULL.
@retval ISMD_ERROR_INVALID_REQUEST : clock sync has not been opened.
*/

ismd_result_t SMDEXPORT ismd_demux_tsin_get_recovery_clock(ismd_dev_handle_t handle,
                                    clock_sync_t *recovery_clock);


/**
Get the stream position of the demux.

@param[in] handle : handle to the demux stream.
@param[out] position : stream position details. The PCR/PTS values are ISMD_NO_PTS
if not available; the time values are ISMD_NO_PTS if a clock was never set to demux.

@retval ISMD_SUCCESS : The stream position is successfully obtained.
@retval ISMD_ERROR_INVALID_HANDLE : The demux handle is invalid.
@retval ISMD_ERROR_NULL_POINTER : info pointer is NULL.
*/
ismd_result_t SMDEXPORT ismd_demux_get_stream_position(ismd_dev_t handle,
                              ismd_demux_stream_position_info_t *position);

/**
Configure a discontinuity event notification for a demux stream.

Can be cancelled by passing in an event of ISMD_EVENT_HANDLE_INVALID.

@param[in] handle : handle to the demux stream.
@param[in] event : Event to be triggered when the discontinuity happens.

@retval ISMD_SUCCESS : The client's discontiuity event has been successfully registered.
@retval ISMD_ERROR_INVALID_HANDLE: The handle provided is not valid.
*/

ismd_result_t SMDEXPORT ismd_demux_set_discontinuity_event(ismd_dev_t handle,
                                    ismd_event_t discont_event);

/**@}*/ // end of weakgroup ismd_demux
/**@}*/

#endif /* !ISMD_DEMUX_DEFINES_ONLY */

#ifdef __cplusplus
}
#endif

#endif
