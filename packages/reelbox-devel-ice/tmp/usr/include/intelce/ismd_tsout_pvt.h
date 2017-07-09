/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.

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

  Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
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

#ifndef __ISMD_TSOUT_PVT_H__
#define __ISMD_TSOUT_PVT_H__

#include "osal.h"
#include "ismd_global_defs.h"
#include "platform_config.h"
#include "platform_config_paths.h"
#include "ismd_tsout.h"
#include "ismd_core.h"
#include "ismd_tsout_dma.h"
#include "auto_eas/gen3_tsout.h"

// Developer revision number for the driver. The number should be incremented everytime code is checked in.
#define DRV_REV_NO      (16)

#define MIN(a, b)  (( (a) < (b) ) ? (a) : (b))
#define MAX(a, b)  (( (a) > (b) ) ? (a) : (b))

// Returns the bit located at "bit_pos" in "val"
#define READ_BIT(val, bit_pos) (( (val) >> (bit_pos) ) & 0x1 )

// Resets the bit located at "bit_pos" in "val" to 0.DOES NOT assign the value to "val"
#define RESET_BIT(val, bit_pos) ( (val) & ~( 0x1 << (bit_pos) ) )

// Sets the bit located at "bit_pos" in "val" to 1. DOES NOT assign the value to "val"
#define SET_BIT(val, bit_pos) ( (val) | ( 0x1 << (bit_pos) ) )

// Returns the next higher index value wrapped around at max_val. Does not check for negative numbers
#define NEXT_RING_INDEX(curr_pos,  max_val ) ((curr_pos + 1) % max_val)
// Returns prebious index number, wrapping around at 0. Does not correct for values higher than max_val
#define PREV_RING_INDEX(curr_pos,  max_val ) ((curr_pos > 0) ? curr_pos - 1 : max_val - 1)

// This Macro returns a string corresponding to the given TSOut state
#define TSOUT_STATE_STR(tsout_context)                                          \
    ((ISMD_DEV_STATE_STOP == tsout_context->state)? "STOP" :                    \
    (ISMD_DEV_STATE_PAUSE == tsout_context->state)? "PAUSE" :                   \
    (ISMD_DEV_STATE_PLAY == tsout_context->state)? "PLAY" : "INVALID")

/* Debug Macros */

#define DEBUG_LEVEL_SILENT          0       // Messages to be Logged always
#define DEBUG_LEVEL_ERRORS          1       // Used for errors
#define DEBUG_LEVEL_WARNINGS        2       // Used to indicate soft errors, warnings
#define DEBUG_LEVEL_MAJOR_EVENTS    3       // Major events, state changes, etc
#define DEBUG_LEVEL_DMA             4       // Used for Logging DMA desc add/remove operations
#define DEBUG_LEVEL_MEMORY          4       // Used for Logging Memory / Buffer Alloc / release operations
#define DEBUG_LEVEL_DISPATCH        4       // Messages related to dispatching buffers
#define DEBUG_LEVEL_BUG_TEST        2       // Used for _CURRENT_ Debug task
#define DEBUG_LEVEL_VERBOSE1        5       // Used for minor events
#define DEBUG_LEVEL_VERBOSE2        6       // Used for data / variable values
#define DEBUG_LEVEL_ALL             7       // Anything that does not fit in the above

#define SVEN_LEVEL_SILENT           0
#define SVEN_LEVEL_ERRORS           1
#define SVEN_LEVEL_WARNINGS         2
#define SVEN_LEVEL_MAJOR_EVENTS     3
#define SVEN_LEVEL_MEMORY           4
#define SVEN_LEVEL_ALL              5
//
// SVEN Logging macros
//

#ifndef SVEN_MODULE_EVENT_TSOUT_MISSING_PCR
// auto_eas should define these... why did we not find them?
    #define SVEN_MODULE_EVENT_TSOUT_OPEN	0x1
    #define SVEN_MODULE_EVENT_TSOUT_OPEN_OP_PORT	0x2
    #define SVEN_MODULE_EVENT_TSOUT_SET_BASETIME	0x3
    #define SVEN_MODULE_EVENT_TSOUT_SET_PCR_PID	0x4
    #define SVEN_MODULE_EVENT_TSOUT_EOS	0x5
    #define SVEN_MODULE_EVENT_TSOUT_LATE_PKT	0x6
    #define SVEN_MODULE_EVENT_TSOUT_PCR_DETECTED	0x7
    #define SVEN_MODULE_EVENT_TSOUT_SYNC_ACQUIRED	0x8
    #define SVEN_MODULE_EVENT_TSOUT_SYNC_LOST	0x9
    #define SVEN_MODULE_EVENT_TSOUT_SYNC_FAILED	0xa
    #define SVEN_MODULE_EVENT_TSOUT_PVT_EVENT	0xb
    #define SVEN_MODULE_EVENT_TSOUT_TIMEOUT	0xc
    #define SVEN_MODULE_EVENT_TSOUT_STARVING	0xd
    #define SVEN_MODULE_EVENT_TSOUT_DATA_DROPPED	0xe
    #define SVEN_MODULE_EVENT_TSOUT_SYNC_PCR_FAILED	0xf
    #define SVEN_MODULE_EVENT_TSOUT_DMA_RESTARTED	0x10
    #define SVEN_MODULE_EVENT_TSOUT_SMD_API_FAILURE	0x11
    #define SVEN_MODULE_EVENT_TSOUT_BAD_TIMESTAMP	0x12
    #define SVEN_MODULE_EVENT_TSOUT_MISSING_PCR	0x13
    #define SVEN_MODULE_EVENT_TSOUT_IN_DEQUEUE	0x64
    #define SVEN_MODULE_EVENT_TSOUT_OUT_ENQUEUE	0x65
    #define SVEN_MODULE_EVENT_TSOUT_CONTENT_TIME_GAP	0x66
    #define SVEN_MODULE_EVENT_TSOUT_CLOSE	0x68
    #define SVEN_MODULE_EVENT_TSOUT_STATE_CHANGE	0x6b
    #define SVEN_MODULE_EVENT_TSOUT_FLUSH_START	0x6c
    #define SVEN_MODULE_EVENT_TSOUT_FLUSH_COMPLETE	0x6d
    #define SVEN_MODULE_EVENT_TSOUT_NEW_SEG_IN	0x6e
    #define SVEN_MODULE_EVENT_TSOUT_NEW_SEG_OUT	0x6f
#endif

// Params: SVEN Level, Event to Log, 6 int params for the event
#define SVEN_LOG_TSOUT(level, event, a, b, c, d, e, f)                \
                if((level) <= tsout_global_data.sven_level)     \
                devh_SVEN_WriteModuleEvent(tsout_global_data.sven_devh, event, a, b, c, d, e, f);

#define SVEN_LOG_TSOUT_OPEN(level, id, ip_port_h, depth, type) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_OPEN, id, ip_port_h, depth, type, 0, 0);

#define SVEN_LOG_TSOUT_OPEN_OP_PORT(level, id, op_port_h, depth ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_OPEN_OP_PORT, id, op_port_h, depth, 0, 0, 0);

#define SVEN_LOG_TSOUT_CLOSE(level, id, in_port_h, op_port_h ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_CLOSE, id, in_port_h, op_port_h, 0, 0, 0);

#define SVEN_LOG_TSOUT_STATE_CHANGE(level, id, old_state, new_state ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_STATE_CHANGE, id, old_state, new_state, 0, 0, 0);

#define SVEN_LOG_TSOUT_FLUSH_START(level, id, in_port_h, ip_port_sz, op_port_h, op_port_sz ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_FLUSH_START, id, in_port_h, ip_port_sz, op_port_h, op_port_sz, 0);

#define SVEN_LOG_TSOUT_FLUSH_COMPLETE(level, id, in_port_h, ip_port_sz, op_port_h, op_port_sz ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_FLUSH_COMPLETE, id, in_port_h, ip_port_sz, op_port_h, op_port_sz, 0);

#define SVEN_LOG_TSOUT_IN_DEQUEUE(level, id, ip_port_h, buffer ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_IN_DEQUEUE, id, ip_port_h, buffer, 0, 0, 0);

#define SVEN_LOG_TSOUT_OUT_ENQUEUE(level, id, op_port_h, buffer ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_OUT_ENQUEUE, id, ip_port_h, buffer, 0, 0, 0);

// #define SVEN_LOG_TSOUT_CONTENT_TIME_GAP(level, id )
//                 SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_CONTENT_TIME_GAP, id, 0, 0, 0, 0, 0);
//
// #define SVEN_LOG_TSOUT_NEW_SEG_IN(level, id )
//                 SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_NEW_SEG_IN, id, 0, 0, 0, 0, 0);
//
// #define SVEN_LOG_TSOUT_NEW_SEG_OUT(level, id )
//                 SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_NEW_SEG_OUT, id, 0, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_SET_BASETIME(level, id, bt ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SET_BASETIME, id, bt, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_SET_PCR_PID(level, id, pcr_pid ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SET_PCR_PID, id, pcr_pid, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_EOS(level, id ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_EOS, id, 0, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_LATE_PKT(level, id, ce_isr, head, tail ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_LATE_PKT, id, ce_isr, head, tail, 0, 0);

#define SVEN_LOG_TSOUT_PCR_DETECTED(level, id, pcr_pid, pcr_ts ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_PCR_DETECTED, id, pcr_pid, pcr_ts, 0, 0, 0);

#define SVEN_LOG_TSOUT_SYNC_ACQUIRED(level, id ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SYNC_ACQUIRED, id, 0, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_SYNC_LOST(level, id ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SYNC_LOST, id, 0, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_SYNC_FAILED(level, id ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SYNC_FAILED, id, 0, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_PVT_EVENT(level, id, evt ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_PVT_EVENT, id, evt, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_TIMEOUT(level, id ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_TIMEOUT, id, 0, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_STARVING(level, id, head, tail, n_pcr ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_STARVING, id, head, tail, n_pcr, 0, 0);

#define SVEN_LOG_TSOUT_DATA_DROPPED(level, id, num_bytes ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_DATA_DROPPED, id, num_bytes, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_SYNC_PCR_FAILED(level, id, pcr_pid ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SYNC_PCR_FAILED, id, pcr_pid, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_DMA_RESTARTED(level, id, head, tail, n_pcr  ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_DMA_RESTARTED, id, head, tail, n_pcr, 0, 0);

#define SVEN_LOG_TSOUT_SMD_API_FAILURE(level, id, error_code ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SMD_API_FAILURE, id, error_code, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_BAD_TIMESTAMP(level, id, ts_delta ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SMD_API_FAILURE, id, ts_delta, 0, 0, 0, 0);

#define SVEN_LOG_TSOUT_MISSING_PCR(level, id, num_pkts ) \
                SVEN_LOG_TSOUT(level, SVEN_MODULE_EVENT_TSOUT_SMD_API_FAILURE, id, num_pkts, 0, 0, 0, 0);

//
// TSOut Memory Regions
//
#define TSOUT_MEMORY_SIZE               (512 * 1024) // 512 KB memory region defined for TSOUT
#define MAX_TS_PACKET_COUNT             (7000)  // MAX TS188 packets that we can buffer up
#define MAX_TS_SPLIT_PACKETS            (256)   // Maximum number of TS188 partial packets we can deal with
#define TSOUT_DMA_DESC_BUFFER_SIZE      (MAX_TS_PACKET_COUNT * 2 * TSOUT_DMA_DESC_SIZE)
#define TSOUT_TIMESTAMPS_BUFFER_SIZE    (MAX_TS_PACKET_COUNT * TTS_TIMESTAMP_SIZE)
#define TSOUT_SPLIT_PKT_BUFFER_SIZE     (MAX_TS_SPLIT_PACKETS * MPEG2_TS188_PACKET_SIZE)
#define TSOUT_PER_CONTEXT_MEMORY_SIZE   (TSOUT_DMA_DESC_BUFFER_SIZE + TSOUT_TIMESTAMPS_BUFFER_SIZE + TSOUT_SPLIT_PKT_BUFFER_SIZE)
#define TSOUT_DMA_DESC_BUFFER_OFFSET    (0) // from base of allocated memory for a TSOut context
#define TSOUT_TIMESTAMPS_BUFFER_OFFSET  (TSOUT_DMA_DESC_BUFFER_SIZE) // from base of allocated memory for a TSOut context
#define TSOUT_SPLIT_PKT_BUFFER_OFFSET   (TSOUT_DMA_DESC_BUFFER_SIZE + TSOUT_TIMESTAMPS_BUFFER_SIZE) // from base of allocated memory for a TSOut context

//#define TSOUT_NUM_DMA_DESC              ( TSOUT_DMA_DESC_BUFFER_SIZE / sizeof (tsout_dma_descriptor_t)) // Enough for TS192
//#define TSOUT_NUM_DMA_DESC              (256) // Enough for 1/10th sec at 40 Mbps with 2K buffers
#define TSOUT_NUM_DMA_DESC_188          (MAX_TS_PACKET_COUNT * 2)
#define TSOUT_NUM_DMA_DESC_192          (256) // Enough for 1/10th sec at 40 Mbps with 2K buffers
#define TSOUT_NUM_TIMESTAMPS            (MAX_TS_PACKET_COUNT)
#define TSOUT_NUM_SPLIT_PKT_BUFFERS     (MAX_TS_SPLIT_PACKETS)

//
// TSOut defines
//
#define MPEG2_TS_START_CODE             (0x47)
#define MPEG2_TS_PACKET_SIZE            (188)
#define MPEG2_TS188_PACKET_SIZE         (188)
#define MPEG2_TS192_PACKET_SIZE         (192)
#define TTS_TIMESTAMP_SIZE              (4)
#define START_CODE_SIZE                 (1)
#define TSOUT_DMA_DESC_SIZE             sizeof (tsout_dma_descriptor_t) //(32)       // 8 DWords
//#define TSOUT_MIN_TIMESTAMP_DELTA       0x5E0    // If the TimeStamp Delta is less that this, we will hit Late Packet Errors at 27Mhz
#define TSOUT_MIN_TIMESTAMP_DELTA       0x2F0      // If the TimeStamp Delta is less that this, we will hit Late Packet Errors at 54Mhz
#define TSOUT_HALF_SEC_TS_DELTA         0x1B00000  // This timestamp delta is equivalent to ~ 1/2 sec wait @54MHz
#define TSOUT_PROPAGATION_DELAY         0x01000000 // (621 ms) This is the internal delay - added to the basetime configuration
#define TSOUT_DMA_RESTART_DELAY         0x00050000 // (5 * 2.427 ms) This is the internal delay used when the TX_TS_CNT is adjusted on DMA re-start

#define TSOUT_PORT_DEPTH                16 // The number of buffers in I/P and O/P Queues
#define TSOUT_IN_PORT_HIGH_WM           6 // High water Mark for input port
#define TSOUT_OUT_PORT_LOW_WM           2 // Low water Mark for output port
#define TSOUT_MIN_FREE_OP_BUFFERS       2 // 1 is the least valid value. Number of buffers / descriptors that must be availabe to consider OP has space.

#define MAX_NUM_TSOUT_CONTEXTS          2
#define TSOUT_PVT_EVENT_MAX             16
#define ISMD_TSOUT_EVENT_WAIT_TIMEOUT   5000 // ISMD_TIMEOUT_NONE //500 // Value specified in ms
#define INVALID_TIMESTAMP               ((uint32_t)-1) // Reserved value used to indicate un-initialized timestamp variables

// TS188 support
#define MAX_NUM_TS188_PKT_BTW_PCRS      (3486)    // (3486) Max Number of TS188 packets between PCRs (1/10th sec) at Max supported bitrate (50Mbps)
#define MIN_PCRS_BUFFERED               (3)       // Minimum numbers of PCRs and the data in between that should be buffered
#define MIN_STREAM_BUFFER_TIME          (2700000 * 10) // 2/10th sec in 27 MHz clock
#define MIN_TS188_PKTS_BUFFERED         (1400)    // About eight 32K buffers worth of data...

#ifdef DEBUG
    // Special development time code to help with debug / tests / integration activities.
    // Enable Extra param and return value checks
    #define TSOUT_EXTRA_CHECKS    1

    extern int debug_msg_ctr;
    #define TSOUT_LOG(level, fmt, x...)                         \
                  if((level) <= tsout_global_data.debug_level)  \
                    OS_PRINT("TSOut %03d %s().%d: " fmt "\n", debug_msg_ctr++, __func__, __LINE__, ##x)

    void dump_buffer_info(ismd_buffer_handle_t buffer_handle);
    #define DUMP_BUFFER_INFO(bh)    dump_buffer_info( bh )

#else // DEBUG
    #define TSOUT_LOG(level, fmt, x...) \
                if((level) <= tsout_global_data.debug_level)  \
                  OS_PRINT(fmt "\n", ##x)

    #define DUMP_BUFFER_INFO(bh)
#endif // DEBUG

#if (! defined(ASSERT))
    #define ASSERT(a) do { if(!(a)) TSOUT_LOG( DEBUG_LEVEL_ERRORS, "ASSERT: "#a ); }while(0)
#endif
#if (! defined(CT_ASSERT))
     // Compile Time assert...
     #define CT_ASSERT(e) extern char (*ct_assert(void)) [sizeof(char[1 - 2*!(e)])]
#endif

#if 0
    #define TSOUT_SVEN_ENTER(devh) if(NULL != devh) DEVH_FUNC_ENTER(devh);
    #define TSOUT_SVEN_EXIT(devh) if(NULL != devh) DEVH_FUNC_EXIT(devh);
#else
//     #define TSOUT_SVEN_ENTER(devh) TSOUT_LOG(DEBUG_LEVEL_ALL, "Enter ==> %s", __func__ );
//     #define TSOUT_SVEN_EXIT(devh)  TSOUT_LOG(DEBUG_LEVEL_ALL, "Exit  <== %s", __func__ );
    #define TSOUT_SVEN_ENTER(devh)
    #define TSOUT_SVEN_EXIT(devh)
#endif // TSOUT_LOG or DEVH_FUNC?


typedef enum
{
    // Ordered according to priority...
    TSOUT_PVT_EVENT_DMA_ISR              = 0,
    TSOUT_PVT_EVENT_INPUT_PORT_NOT_EMPTY = 1,
    TSOUT_PVT_EVENT_OUTPUT_PORT_NOT_FULL = 2,
    TSOUT_PVT_EVENT_PLAY                 = 3,
    TSOUT_PVT_EVENT_PAUSE                = 4,
    TSOUT_PVT_EVENT_STOP                 = 5,
    TSOUT_PVT_EVENT_FLUSH                = 6, // TODO: NPG: 3/17/2009 : Remove this event - not required
    TSOUT_PVT_EVENT_EOS                  = 7, // TODO: NPG: 3/17/2009 : Remove this event - not required
    TSOUT_PVT_EVENT_LAST                 = 8  // This is the number of events defined
} ismd_tsout_internal_event_type_t;

// typedef struct tsout_timebase_info_struct
// {
//     ismd_newsegment_tag_t current_newsegment;
//     ismd_newsegment_tag_t previous_newsegment;
// }tsout_timebase_info_t;

typedef struct tsout_188_info_struct
{
    uint32_t    bottom_pcr_ts;          // earlier of the two PCRs
    uint32_t    avg_ts_delta;           // Average Timestamp Delta for the last PCR pair
    int         num_pcrs_queued;        // Number of PCRs already buffered and ready for DMA...
    uint32_t    first_timestamp;
    uint16_t    pcr_pid;                // PID in the input stream that holds the PCRs
    bool        pcr_pid_valid;          // True if PCR PID has been set...
    char       *split_packet_buffer;    // Pointer to buffer that will hold copies of packets split across buffers
    uint32_t    split_packet_index;     // index into split_packet_buffer for next packet to be copied
    uint32_t    split_packet_buffer_phys_base; // Physical base address

//     uint32_t    lookahead_count;             // Number of buffers "peeked"
    ismd_buffer_handle_t       lookahead_bh; // Current buffer being processed. We Lookahead rather than poping the buffer
    ismd_buffer_descriptor_t   lookahead_bd; // buffer descriptor for current buffer. We Lookahead rather than poping the buffer
}tsout_188_info_t;

typedef struct tsout_192_info_struct
{
    char                       *smd_buffer_start_address;
    uint32_t                   alias_start_offset, alias_stop;
    uint32_t                   first_timestamp;
}tsout_192_info_t;

//typedef union buffer_union
typedef struct buffer_union
{
    tsout_192_info_t  ts_192;
    tsout_188_info_t  ts_188;
}tsout_stream_info_t;

typedef struct tsout_dma_context_struct
{
    uint32_t                head;   // Index into dma_desc where spent dma descriptors are pulled/released from
    uint32_t                tail;   // Index into dma_desc where new dma descriptors are chained for DMA.
    uint32_t                position; // Index into dma_desc where TS188 data is being worked on. Ignored for TS192

    tsout_dma_descriptor_t *dma_desc; // Allocated with an SMD buffer...
    uint32_t                dma_desc_phys_base;
    uint32_t                num_dma_desc; // Number of DMA descriptors to be used
    uint32_t               *timestamp;    // Array to hold TimeStamp values used by TS188 processing
    uint32_t                timestamp_phys_base; // Physical Base address
    int                     hw_dma_context_num; // The Hardware DMA Context number to be used. for CE3100, this would be "2" - 1394 Tx
    bool                    dma_started;    // Set to true when DMA is initially started.
} tsout_dma_context_t;

typedef struct tsout_stream_context_struct
{
    bool in_use; // flag to indicate if instance is in use. Set to true in open() and to false in close()
    int  id;     // instance id - Index into stream_context array

    // Registers for Control and status of the TSOut interface
    uint32_t                reg_base_phys;  // Physical address of the base of the Pre Filter Reg space
    volatile void*          reg_base_virt;  // Virtial pointer to the base of the Pre Filter Reg space

    /* All handles associated with this instance */
    ismd_dev_t              dev;         // device handle from the device manager

    //bool                    use_sw_timesstamp;

    /* Input port */
    ismd_port_handle_t      input_port;

    /* Input data format */
    ismd_tsout_data_type_t     data_format;         // Input TS data format

    /* Output port */
    ismd_port_handle_t      output_port;                      // output port handle from port manager
    bool                    output_port_enabled;    // Can be used with DMA as well

    /* Locks */
    os_sema_t               api_lock;

    /* Clock */
    bool                    clock_valid; // flag to indicate if clock is valid
    ismd_clock_t            clock;       // clock handle
    uint32_t                first_timestamp; // The first timestamp for the stream (TTS value or computed for TS)
    uint32_t                last_ts;         // The Timestamp of the Last packet...
    ismd_time_t             base_time;
    bool                    base_time_valid;

    /* tsout thread */
    bool                    tsout_thread_created;       // flag to indicate if output port thread is valid
    os_thread_t             tsout_thread;               // output port thread

    /* SMD buffers */
    ismd_buffer_handle_t       buffer_handle;           // Current buffer being processed
    ismd_buffer_descriptor_t   buffer_desc;             // buffer descriptor for current buffer
    ismd_buffer_handle_t       partial_ts_buffer;       // This is the buffer handle for the Partial TS packet

    /* Stream specific info */
    tsout_stream_info_t     stream_info;

    /* New segment */
//     tsout_timebase_info_t   new_segment;
    bool                    in_sync;
    bool                    indicate_eos;          // Flag is set when Input EOS is seen. EOS is propagated when DMA is done.
    int                     offset_in_next_buffer; // This is the offset in the buffer we start scanning at...

    /* DMA */
    tsout_dma_context_t     dma_context;

    /* Event */
    ismd_event_t event;     // Others can register an event...
    uint32_t event_mask;    // which events are enabled?

    /* Processing state*/
    ismd_dev_state_t        state;

    /* SMD event notifications */
    ismd_event_t event_list[TSOUT_PVT_EVENT_MAX];

    /* TS Prefilter registers offset */
    uint32_t reg_offset_prefilter_config_tx;
    uint32_t reg_offset_prefilter_tx_ts_cnt;

    /* MSPOD registers offset */
    uint32_t reg_offset_mspod_ier;
    uint32_t reg_offset_mspod_isr;
  
    /* MSPOD DMA done bits in ier/isr registers */
    uint32_t reg_bits_dma_done_interrupts;

    /* Output Mode */	
    ismd_tsout_output_mode_t output_mode;
} tsout_stream_context_t;

typedef struct tsout_global_data_struct
{
    ismd_buffer_handle_t     tsout_memory_bh[MAX_NUM_TSOUT_CONTEXTS]; // Buffer handle to the memory TSOut allocates
    tsout_stream_context_t   stream_context[MAX_NUM_TSOUT_CONTEXTS];  // array of all contexts
    os_devhandle_t           *sven_devh;                        // sven handle to log operation
    int                      debug_level;                       // Verbosity level for debug messages
    int                      sven_level;                        // Verbosity level for SVEN messages
    int                      active_contexts;                   // Number of active TSOut instances
    os_interrupt_t           interrupt;                         // The acquired interrupt
    pal_soc_name_t           soc_name;                          // The soc name
    int                      max_num_tsout_contexts;            // maximum tsout contexts in the platform

    // Hardware signal configuration based on platform config
    int sync_len;   // CE TX Interface Packet SYNC (1394_OSYNC) mode: 0:Bit pulse, 1: Byte Pulse, 2: level covering the entire DIF packet
    int odav_pol;   // CE TX Interface Data Valid output (1394_ODAV) polarity: 0: active high, 1: active low
    int oenable_pol;// CE TX Interface Packet Enable/Error output (1394_OENABLE) polarity: 0: active high, 1: active low
    int osync_pol;  // CE TX Interface Packet SYNC output (1394_OSYNC) polarity.0: active high, 1: active low
    int oclk_edge;  // CE TX Interface Clock sampling edge: 0: rising edge, 1: falling edge
    int oclk_freq;  // Clock Frequency. 0: 27 MHz, 1: 54 MHz, 2: 74.25 MHz
} tsout_global_data_t;


ismd_result_t tsout_instance_get_input_buffer(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_lookahead_input_buffer(tsout_stream_context_t *tsout_context, uint32_t posn);

/* Utilities */
ismd_result_t tsout_port_create(int port_type, int depth, ismd_event_t event, ismd_queue_event_t event_mask, int watermark, ismd_port_handle_t *port);

/* Processing */
bool tsout_instance_output_has_space(tsout_stream_context_t *tsout_context, uint32_t *num_buf_avail);
bool tsout_instance_input_data_available(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_process_ts192_buffer(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_process_ts188_buffer(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_update_timestamp(tsout_stream_context_t *tsout_context, char *b0, char *b1, char *b2, char *b3);
ismd_result_t tsout_instance_indicate_eos(tsout_stream_context_t *tsout_context);

ismd_result_t tsout_instance_init_dma(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_dma_buffer(tsout_stream_context_t *tsout_context, ismd_buffer_handle_t buffer);
ismd_result_t tsout_instance_dma_restart(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_release_completed_buffers(tsout_stream_context_t *tsout_context);
int tsout_instance_num_dma_desc_available(tsout_stream_context_t *tsout_context);
int tsout_instance_num_dma_desc_in_use(tsout_stream_context_t *tsout_context);
ismd_result_t tsout_instance_resync(tsout_stream_context_t *tsout_context,
                                           char     *buff_ptr,
                                           uint32_t buff_size,
                                           uint32_t pkt_size,
                                           uint32_t *sync_offset);
bool tsout_instance_is_dma_active(tsout_stream_context_t *tsout_context);

uint32_t bytes_to_timestamp(char b0, char b1, char b2, char b3);
ismd_result_t timestamp_to_bytes(uint32_t ts, char *b0, char *b1, char *b2, char *b3);
int dma_desc_available(tsout_stream_context_t *tsout_context, int head, int tail, int total);

/* Thread */
void *tsout_instance_thread(void *data);
ismd_result_t tsout_create_thread(tsout_stream_context_t *tsout_context);

ismd_result_t SMDPRIVATE ismd_tsout_suspend_test(void);
ismd_result_t SMDPRIVATE ismd_tsout_resume_test(void);

// Debugging functions
#ifdef DEBUG
void tsout_instance_dump_dma_reg(tsout_stream_context_t *tsout_context);
void tsout_instance_dump_desc(tsout_dma_descriptor_t  *desc);
void dump_ts_active_dma_desc(tsout_stream_context_t *tsout_context);
void dump_ts_config_regs(tsout_stream_context_t *tsout_context);

    #define DEBUG_ENABLE_ALL {tsout_global_data.debug_level = DEBUG_LEVEL_ALL;}
    #define DUMP_TS_REG(tsout_context)              dump_ts_config_regs(tsout_context)
    #define DUMP_DMA_REG(tsout_context)             tsout_instance_dump_dma_reg(tsout_context)
    #define DUMP_DMA_DESC(desc)                     tsout_instance_dump_desc(desc)
    #define DUMP_ACTIVE_DMA_DESC(tsout_context)     dump_ts_active_dma_desc(tsout_context)
#else
    #define DEBUG_ENABLE_ALL
    #define DUMP_TS_REG(tsout_context)
    #define DUMP_DMA_REG(tsout_context)
    #define DUMP_DMA_DESC(desc)
    #define DUMP_ACTIVE_DMA_DESC(tsout_context)
#endif

extern bool tsout_check_suspending(void);

#define TSOUT_LOCK_API(lock)              \
{                                   \
   os_sema_get(lock);               \
   if (tsout_check_suspending()) {    \
      os_sema_put(lock);            \
      return ISMD_ERROR_SUSPENDED;  \
   }                                \
}                                   \

#define TSOUT_UNLOCK_API(lock) os_sema_put(lock);

ismd_result_t ismd_tsout_get_base_and_irq(void **base_addr, unsigned *irq_num);
ismd_result_t ismd_tsout_set_power_state( ismd_power_state_t requested_state );



// power management

typedef ismd_result_t (*pm_callback_t) (void);

ismd_result_t
ismd_tsout_pm_register(pm_callback_t suspend, pm_callback_t resume);

void
ismd_tsout_pm_unregister(void);

#endif /* __ISMD_TSOUT_PVT_H__ */
