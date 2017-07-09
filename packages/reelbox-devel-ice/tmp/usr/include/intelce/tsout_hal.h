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

#ifndef __TSOUT_HAL_H__
#define __TSOUT_HAL_H__


// Prefilter registers specific to TS-OUT would be accessed from here.

#include "tsout_hal.h"
#include "ismd_core.h"
#include "osal.h"
#include "pal.h"
#include "sven.h"
#include "sven_devh.h"

//
// Macros
//

//
// Register Defines
//

// Clock Control Regiser CP_L2_DIV_CTRL bits for 1394 Tx
//    1394 Output Clock Divider Control
//    0101:  54 MHz
//    1000:  27 MHz
//    All other values are reserved and must not be used.
#define CP_L2_DIV_CTRL_1394_OCK_DIV_27MHZ          (0x8)
#define CP_L2_DIV_CTRL_1394_OCK_DIV_54MHZ          (0x5)

// TSOut related register defines - PRE-Filter and MSPOD regions...
#define PREFILTER_GLOBAL_ADDRESS_SIZE   0x4000
#define CE_CONFIG_RX_OFFSET             0x0040
#define CE_CONFIG_TX_OFFSET             0x0044
#define CE_INTERRUPT_ENABLE_OFFSET      0x0048
#define CE_INTERRUPT_STATUS_OFFSET      0x004C
#define CE_TX_TS_CNT_OFFSET             0x00C0
#define CE_TX_CONTEXT_SIZE              0x0100
#define CE_ISR_LATE_PKT_SHIFT           6
#define CE_ISR_TX_ERR_SHIFT             5

// Bit Definitions for CE_CONFIG_TX
#define OCLK_EDGE_SHIFT             (0) //CE TX Interface Clock sampling edge
#define OCLK_EDGE_FALLING               (1) // 0: rising edge, 1: falling edge
#define CE_CONFIG_OCLK_EDGE_MASK        (0x01)

#define OSYNC_POL_SHIFT             (1) // CE TX Interface Packet SYNC output (1394_OSYNC)
#define OSYNC_POL_ACTIVE_LOW            (1) // 0: active high, 1: active low
#define CE_CONFIG_OSYNC_POL_MASK        (0x02)

#define OENABL_POL_SHIFT            (2) // CE TX Interface Packet Enable/Error output (1394_OENABLE)
#define OENABL_POL_ACTIVE_LOW           (1) // 0: active high, 1: active low
#define CE_CONFIG_OENABL_POL_MASK       (0x04)

#define ODAV_POL_SHIFT              (3) // CE TX Interface Data Valid output (1394_ODAV)
#define ODAV_POL_ACTIVE_LOW             (1) // 0: active high, 1: active low
#define CE_CONFIG_ODAV_POL_MASK         (0x08)

#define SYNC_LEN_SHIFT              (4) // CE TX Interface Packet SYNC (1394_OSYNC) mode
#define SYNC_LEN_BIT_PULSE              (0) // Pulse marking the first bit of the first byte of the DIF packer;
#define SYNC_LEN_BYTE_PULSE             (1) // Pulse marking the first byte of the DIF packer;
#define SYNC_LEN_LEVEL                  (2) // level covering the entire DIF packet from the first bit of the first byte to the last bit of the last byte.
#define CE_CONFIG_SYNC_LENL_MASK        (0x30)

#define TX_MODE_SHIFT               (6) // Transmit CE interface mode
#define TX_MODE_DISABLED                (0) // 000: Interface disabled
#define TX_MODE_MPEG_TS                 (1) // 001: Mpeg TS mode
#define TX_MODE_DIRECTV                 (2) // 010: DirecTV mode
#define TX_MODE_DV_SD                   (4) // 100: DV SD mode
#define TX_MODE_DV_HD                   (5) // 101: DV HD mode
#define CE_CONFIG_TX_TX_MODE_MASK       (0x1C0)

#define TSHDR_FMT_SHIFT             (9) // Transport Stream Time Stamp Header Format : (Valid in MPEG-TS transmit only)
#define TSHDR_FMT_32_BITS               (0) // 0 : All 32 bits are used as time stamp
#define TSHDR_FMT_30_BITS               (1) // 1 : The lower 30 bits are used as time stamp and the upper 2 bits are ignored when comparing with local transmit timebase counter
#define CE_CONFIG_TX_TSHDR_MASK         (0x200)

#define DV_PTS_SHIFT                (10) // DV_PTS = Select what transmit timing control method is used for DV. Only valid in DV mode.
#define DV_PTS_COUNTER                  (0) // 0: Use DV frame and packet interval counter for transmit timing control.
#define DV_PTS_TIMESTAMP                (1) // 1: Use timestamp for transmit timing control,
#define CE_CONFIG_DV_PTS_MASK           (0x400)

#define P_SN_SHIFT                  (11) //Instance operates in Parallel or Serial Mode
#define P_SN                        (1) // 1: Parallel, 0: Serial
#define CE_CONFIG_P_SN_MASK         (0x800)

/**
 * Ref: CE3100 EDS, Section: 5.2.4.10 DMA Descriptor Structures
 */
#define UDMA_CONTEXT_OFFSET         (0x80)      // Offset of the first DMA context register bank
#define UDMA_CONTEXT_SIZE           (0x40)      // Size of each DMA context...
#define MSPOD_REG_SIZE              (0x200)     // Size of the MSPOD register space
#define CDMA_1394_IER_OFFSET        (0x20)      // MSPOD::CDMA 1394 Interface Interrupt Enable Register
#define CDMA_1394_ISR_OFFSET        (0x24)      // MSPOD::CDMA 1394 Interrupt Status Register
#define CDMA_P2P_IER_OFFSET         (0x28)      // MSPOD::CDMA P2P Interface Interrupt Enable Register
#define CDMA_P2P_ISR_OFFSET         (0x2c)      // MSPOD::CDMA P2P Interrupt Status Register



// 1394 related DMA Interrupt bits in MSPOD
#define CDMA_1394_OUT_LL_DN_EN_OFFSET       (3)    // 1394 Out Linked List Done Interrupt Enable Bit
#define CDMA_1394_DN_EN_OFFSET              (2)    // 1394 Out DMA Done Interrupt Enable Bit
#define CDMA_1394_OUT_LL_DN_EN              (1 << CDMA_1394_OUT_LL_DN_EN_OFFSET)
#define CDMA_1394_DN_EN                     (1 << CDMA_1394_DN_EN_OFFSET)
#define CDMA_1394_DMA_DONE_INTERRUPTS       (CDMA_1394_DN_EN | CDMA_1394_OUT_LL_DN_EN)

// P2P related DMA Interrupt bits in MSPOD
#define CDMA_P2P_2_DN_EN_OFFSET             (1)    // P2P DMA 2 Done Interrupt Enable Bit
#define CDMA_P2P_1_DN_EN_OFFSET             (0)    // P2P DMA 1 Done Interrupt Enable Bit
#define CDMA_P2P_2_DN_EN                    (1 << CDMA_P2P_2_DN_EN_OFFSET)
#define CDMA_P2P_1_DN_EN                    (1 << CDMA_P2P_1_DN_EN_OFFSET)
#define CDMA_P2P_DMA_DONE_INTERRUPTS        CDMA_P2P_2_DN_EN // P2P DMA 2 is DMA context 5


// Offsets of the various registers in the UDMA context
#define reserved1_OFFSET            (0x00)
#define reserved2_OFFSET            (0x04)
#define CURR_DESCR_OFFSET           (0x08)
#define NEXT_DESCR_OFFSET           (0x0C)
#define SRCDMA_START_OFFSET         (0x10)
#define DSTDMA_START_OFFSET         (0x14)
#define SRCDMA_SIZE_OFFSET          (0x18)
#define FLAGS_MODE_OFFSET           (0x1C)
#define SRCDMA_START_A_OFFSET       (0x20)
#define SRCDMA_BOT_OFFSET           (0x24)
#define SRCDMA_TOP_OFFSET           (0x28)
#define DSTDMA_BOT_OFFSET           (0x2C)
#define DSTDMA_TOP_OFFSET           (0x30)
#define DSTDMA_SIZE_OFFSET          (0x34)
#define reserved3_OFFSET            (0x38)
#define reserved4_OFFSET            (0x3C)

typedef struct{

   /** Register offset */
   uint32_t reg_offset;

   /** Register length in bytes. */
   uint32_t reg_length; 
}ismd_tsout_register_t;

/**
@brief <H3></H3>
   Size for keeping power managment register context size in uint32_t
*/
#define TSOUT_PM_CONTEXT_SIZE (128)

#define ROFF_CRU_DDS_FREQ 0x8
#define ROFF_CRU_SUBUNIT_BASE_DIFF 0x40
//
// Function Prototypes
//
ismd_result_t tsout_hal_mspod_handle_open(void);
ismd_result_t tsout_hal_mspod_handle_close(void);
ismd_result_t tsout_hal_mspod_read_register(uint32_t reg, uint32_t *pRegValue);
ismd_result_t tsout_hal_mspod_write_register(uint32_t reg, uint32_t regValue);

ismd_result_t tsout_hal_prefilter_handle_open(void);
ismd_result_t tsout_hal_prefilter_handle_close(void);
ismd_result_t tsout_hal_prefilter_read_register(uint32_t reg, uint32_t *pRegValue);
ismd_result_t tsout_hal_prefilter_write_register(uint32_t reg, uint32_t regValue);

ismd_result_t tsout_hal_clock_handle_open(void);
ismd_result_t tsout_hal_clock_handle_close(void);
ismd_result_t tsout_hal_clock_read_register(uint32_t reg, uint32_t *pRegValue);
ismd_result_t tsout_hal_clock_write_register(uint32_t reg, uint32_t regValue);

ismd_result_t tsout_hal_init_hw(uint32_t reg_config_tx, uint32_t reg_ier, uint32_t reg_isr, uint32_t bits_dma_done);
ismd_result_t tsout_hal_deinit_hw(uint32_t reg_config_tx, uint32_t reg_ier, uint32_t reg_isr, uint32_t bits_dma_done);
ismd_result_t tsout_hal_suspend(void);
ismd_result_t tsout_hal_resume(void);


#endif /* __TSOUT_HAL_H__ */
