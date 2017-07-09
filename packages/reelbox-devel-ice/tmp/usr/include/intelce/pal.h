/*==========================================================================
  This file is provided under BSD license.  When using or
  redistributing this file, you may do so under this license.

  BSD LICENSE

  Copyright(c) 2005, 2008, 2009, 2010,2011 Intel Corporation. All rights reserved.
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

 =========================================================================*/
#ifndef _PAL_H
#define _PAL_H

//! \file
//! This file contains definitions that are common to all the platform abstraction functions.
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __KERNEL__
#include "stdint.h"
#endif
/** 
 * @defgroup PAL_ PAL routines 
 * <I> Provides Platform (and OS)  independent interface for getting interrupt 
 * numbers for SoC components </I> 
 */
/** @addtogroup PAL_ */
/*@{*/
#include "pal_soc_info.h"

typedef struct
{
   unsigned int base_addr0;/**< base_addr0*/
   uint32_t base_addr1;/**< base_addr1*/
   uint32_t base_addr2;/**< base_addr2*/
   uint32_t base_addr3;/**< base_addr3*/
   unsigned int irq_num;/**< irq_num*/
} pal_info_t;

typedef enum
{
  PAL_SUCCESS = 0,           /**< Success code*/
  PAL_FAILURE                      /**< Failure code */
}pal_result_t;

/** Device IDs \enum pal_dev_id_t */
typedef enum
{
    VDC_0, /**< VDC device id */
    MPEG2_VIDDEC_0, /**< MPEG2 decoder device id */
    H264_VIDDEC_0, /**< H264 decoder device id */
    DEMUX_0, /**< (Old)demux device id */
    MPEG2_VE_0, /**< MPEG2 encoder  device id */
    AUDIO_0, /**< Audio device id */
    VIDCAP_0, /**< Video capture device id */
    UEE_0, /**< UEE device id */
    PREFILTER_0, /**< Prefilter device id */
    GFX_0, /**< Graphics controller device id */
    I2C_0, /**< I2C_0 device id */
    I2C_1, /**< I2C_1 device id */
    I2C_2, /**< I2C_2 device id */
    SPI_0, /**< SPI device id */
    SCARD_0, /**< Smart Card 0 device id */
    SCARD_1, /**< Smart Card 1 device id */
    TIMER_0, /**< Timer 0 device id */
    TIMER_1, /**< Timer 1 device id */
    TIME_STAMP_TIMER_0, /**< Time Stamp Timer device id */
    WATCH_DOG_TIMER_0, /**< watch dog timer device id */
    TRANSPORT_PREFILTER_0, /**< Transport Prefilter 0 device id */
    TRANSPORT_PREFILTER_1, /**< Transport prefilter 1 device id */
    TRANSPORT_PREFILTER_2, /**< Transport Prefilter 2 device id */
    UART_0, /**< Uart 0 device id */
    UART_1, /**< Uart 1 device id */
    OLO_DEBUG,   /**<  debug device id */
    OLO_ERROR,   /**<  error device id */
    GPIO_0, /**<  GPIO 0 device */
    GPIO_1, /**<  GPIO 1 device */
    GPIO_2, /**<  GPIO 2 device */
    GPIO_3, /**<  GPIO 3 device */
    GPIO_4, /**<  GPIO 4 device */
    GPIO_5, /**<  GPIO 5 device */
    GPIO_6, /**<  GPIO 6 device */
    GPIO_7, /**<  GPIO 7 device */
    ADI_0, /**< Advanced de-interlacer */
    /* New Gen3 Media units ---------------- */
    TDSP_0,      /**< DSP 0 */
    TDSP_1,      /**< DSP 1 */
    GPU_GMH,     /** Graphics Memory Hub */
    COMPOSITOR,  /**< compositor */
    MFD,         /**< Multi-format Decoder */
    DPE,         /**< Display Processing1 */
    HDMI_TX,     /**< HDMI_TX */
    SEC,         /**< Security */
    SRAM,        /**< SRAM */
    EXP,         /**< Expansion bus */
    EXP_WIN,     /**< Expansion bus window */
    MSPOD,       /**< MSPOD */
    SPI,         /**< SPI */
    IR,          /**< Infra-red */
    DFX,         /**< DFx */
    GBE,         /**< Gigabit-Eth */
    GBE_MDIO,    /**< GBE_MDIO_RCOMP */
    CRU,         /** clock recovery unit */
    USB_0,       /** USB */
    USB_1,       /** USB */
    SATA_0,      /** SATA */
    SATA_1,      /** SATA */
    GPIO_8, /**<  GPIO 8 device */
    GPIO_9, /**<  GPIO 9 device */
    GPIO_10, /**<  GPIO 10 device */
    GPIO_11, /**<  GPIO 11 device */
    /*************************** GEN4 units***********/
    GV,      /*Global vSparc*/
    GVD,      /*Global vSparc for decoder*/
    MEU_CSR,     /**<    MEU Registers */
    MEU_REG0,    /**<    MEU Region 0 */
    MEU_REG1,    /**<    MEU Region 1 */
    HDVCAP,      /**<    HDVCAP */
    NAND_DEV,    /**<     NAND Device */
    NAND_CSR,   /**<     NAND CSR */
    
    /*************************** CE53XX units***********/
    H264VDP,    /**<  Multi Function Decoder H264VDP */
    VC1VDP,      /**<  Multi Function Decoder VC1VDP */
    MPG2VDP,   /**<  Multi Function Decoder MPG2VDP */
    PWM,          /**<  Pulse Width Modulation */
    I2C_3,         /**<  Fourth bus of I2C */
    UART_3,      /**<  Third UART port */
    USB_2,        /**<  Third USB port */
    H264VE ,     /**<   H264 Video Capture */
    TS_DMX2,   /**<   TS_DMX2 */
    SPI_S,         /**<  SPI Slave */
    GFX2D,        /**<  GFX 2D */
    GFX2D_CSR ,    /**< GFX 2D CSR */
    SPI_F_CSR0 ,   /**<  SPI Flash CSR0 */
    SPI_F_WIN ,    /**<  SPI Flash WIN */
    SPI_F_CSR1,   /**<  SPI Flash CSR1 */
    HDMI_RX ,      /**<  HDMI Receiver */
    GVSPARC_T ,  /**< Global VsPAC for Trascoder */    
    GVSPARC_D ,  /**< Global VsPAC for Decoders */
    EPU ,              /**< Encoder Preprocessor Unit */
    EMMC_HOST,  /**< EMMC Nand Flash Host Controller */
    EMMC_AUX,    /**< EMMC Nand Flash AUX*/
    
    PAL_DEV_MAX
}pal_dev_id_t;

#define PAL_DEVICE_NOT_FOUND  255
#define PAL_NUMBER_OF_DEVICES  (PAL_DEV_MAX)


/**
* \addindex
* List of available Chipset IDs for Intel System-on-chip devices.
*/
typedef enum {

   /** Intel Consumer Electronics System-on-Chip 3100 */
   INTEL_CE_SOC_CE3100_A0 = 0x1,
   INTEL_CE_SOC_CE3100_B0 = 0x2,
   INTEL_CE_SOC_CE3100_B1 = 0x3,

   /** Intel Consumer Electronics System-on-Chip 4100 */
   INTEL_CE_SOC_CE4100_A0 = 0x4,
   INTEL_CE_SOC_CE4100_A1 = 0x5,
   INTEL_CE_SOC_CE4100_B0 = 0x6,
   INTEL_CE_SOC_CE4100_B1 = 0x7,
   INTEL_CE_SOC_CE4100_B2 = 0x8,
   INTEL_CE_SOC_CE4100_C0 = 0x9,
   INTEL_CE_SOC_CE4100_C1 = 0xa,

   /** Intel Consumer Electronics System-on-Chip 4200 */
   INTEL_CE_SOC_CE4200_A0 = 0xb,
   INTEL_CE_SOC_CE4200_A1 = 0xc,
   INTEL_CE_SOC_CE4200_B0 = 0xd,
   INTEL_CE_SOC_CE4200_B1 = 0xe,
   INTEL_CE_SOC_CE4200_C0 = 0xf,

   /** Intel Consumer Electronics System-on-Chip 5300 */
   INTEL_CE_SOC_CE5300_A0 = 0x10,
   INTEL_CE_SOC_CE5300_A1 = 0x11,
   INTEL_CE_SOC_CE5300_B0 = 0x12,
   INTEL_CE_SOC_CE5300_B1 = 0x13,
   INTEL_CE_SOC_CE5300_C0 = 0x14,

} pal_chipset_id_t;

/**
 * @brief Retrieve a value that uniquely identifies the current SOC chipset version
 * @param[out] chipset_id Unique value that identifies the chipset.
 * @retval PAL_SUCCESS The chipset's identifier was returned in the chipset_id
 *                     parameter.
 * @retval PAL_FAILURE The chipset is not recognized or an error occurred while
 *                    attempting to identify the chipset.
 */
pal_result_t pal_get_chipset_id( pal_chipset_id_t *chipset_id );

/**
 * @brief The function will flush all lines in the Intel(r) Media Processor CE b-unit cache.It is only work for CE3100
 * @retval No
 */
void pal_flush_chipset_cache(void);

/**
 * @brief Retrieve a unique identity for the current SOC in terms of SOC generation (family), SOC name and stepping
 * @param[out] info address of a struct to hold the above 3 characteristics
 * @retval PAL_SUCCESS The SOC's identity was returned in the info parameter.
 * @retval PAL_FAILURE The SOC is not recognized or an error occurred while
 *                    attempting to identify the SOC.
 */
pal_result_t pal_get_soc_info(pal_soc_info_t *info);

/*@}*/
// End of new get SOC info items

    #ifdef __cplusplus
}
    #endif


#endif /* _PAL_H */

