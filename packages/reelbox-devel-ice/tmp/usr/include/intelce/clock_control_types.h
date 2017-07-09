/*----------------------------------------------------------------------------
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * The full GNU General Public License is included in this distribution
 * in the file called LICENSE.GPL.
 *
 * Contact Information:
 *
 * Intel Corporation
 * 2200 Mission College Blvd.
 * Santa Clara, CA  97052
 *
 * BSD LICENSE
 *
 * Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   - Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------*/

#ifndef CLOCK_CONTROL_TYPES_H
#define CLOCK_CONTROL_TYPES_H

/* This file contains the types that are used by clients of the clock_control
 * component
 */

/// Boolean used for flags
typedef enum clock_control_bool_t
{
    CLOCK_TRUE = 1,
    CLOCK_FALSE = 0
} clock_control_bool_t;

/// Return type for component APIs
typedef enum clock_control_ret_t
{
    /** Library completed requested action without issue */
    CLOCK_RET_OK                            = 0,

    /** The requested resource doesn't exist on the target SOC */
    CLOCK_ERROR_INVALID_RESOURCE            = -1,

    /** The write value specified is too large for the bitfield */
    CLOCK_ERROR_VALUE_OUT_OF_RANGE          = -2,

    /** The ioctl call to the device node failed */
    CLOCK_ERROR_IOCTL_FAILED                = -3,

    /** Could not open the device node. Has it been created */
    CLOCK_ERROR_DEV_NODE_OPEN_FAILED        = -4,

    /** The client was built against a version of the library incompatible with
     *  the currently loaded clock_control kernel module.
     */
    CLOCK_ERROR_API_MODULE_VERSION_MISMATCH = -5,

    /** The requested action would violate the bitfield's read-write policy. */
    CLOCK_ERROR_INVALID_READ_WRITE          = -6,

    /** A NULL pointer was passed by the client. */
    CLOCK_ERROR_POINTER_NULL                = -7,

    /** A request was made with blocking set to false and the resource was busy
     */
    CLOCK_BUSY                              = -8,

    /** The clock_control kernel module was not successfully loaded */
    CLOCK_ERROR_MODULE_NOT_INITIALIZED      = -9,

    /** Request failed due to platform specific logic */
    CLOCK_ERROR_PLATFORM                    = -10,

    /** I2C access to an externel clock failed. */
    CLOCK_ERROR_I2C                         = -11,
}clock_control_ret_t;

/// Bit flag identifying an external (I2C) resource from resource
#define CLOCK_EXTERNAL   0x80000000


/// An enumeration of all of the available bit fields, grouped by register.
typedef enum clock_control_resource_t
{
    //--------------------------------------------------------------------------
    // Bit fields in external (off-chip -- I2C access) clock generator.
    // These enumerators are distinguished from on-chip resources by having
    // the CLOCK_EXTERNAL bit set.
    //--------------------------------------------------------------------------
#define EXT(x) (x | CLOCK_EXTERNAL)
    CLOCK_EXT_AUD_CLKX      = EXT(0),
    CLOCK_EXT_OE_AUD_CLK0   = EXT(1),
    CLOCK_EXT_OE_AUD_CLK1   = EXT(2),
    CLOCK_EXT_OE_AUD_CLK2   = EXT(3),
    CLOCK_EXT_OE_AUD_CLK3   = EXT(4),
    CLOCK_EXT_OE_VDC_CLK1   = EXT(5),
    CLOCK_EXT_OE_VDC_CLK2   = EXT(6),
    CLOCK_EXT_OE_VDC_MASTER = EXT(7),
    CLOCK_EXT_VDC_CLK1      = EXT(8),
    CLOCK_EXT_VDC_CLK2      = EXT(9),
#undef EXT

    //--------------------------------------------------------------------------
    // CLOCK_RESOURCE_ENUM_END is used internally to terminate resource lists.
    // All other resources will be numbered consecutively from 1.
    //--------------------------------------------------------------------------
    CLOCK_RESOURCE_ENUM_END = 0,

    //--------------------------------------------------------------------------
    //-------------------------------------------------------------------
    // CE4100 / CE4200 resources
    //
    // Organizied by register in the cp_top unit.
    //
    // Where a resource has an exact analog in CE5300 (or later), the resource
    // name is defined there and commented out here.
    //-------------------------------------------------------------------
    //--------------------------------------------------------------------------
  
    // *** Register CP_CNTL_STS: Clock Control and Status
                                // 4100 4200
                                //  B/C B0/1
    CLOCK_AVPLL_DDS_SEL,        //   X    X
    CLOCK_HDMI_COLOR_DEPTH,     //   X    X
    CLOCK_HDMI_PLL_DIV_RST,     //   X    X
    CLOCK_HDMI_PLL_RESET,       //   X    X
    CLOCK_HDMI_SRC_SEL,         //   X    X
    CLOCK_HDMI_TMDS_CLK_EN,     //   X    X
    CLOCK_PCIE0_CLK_OUT_DIS,    //        X
    CLOCK_PCIE1_CLK_OUT_DIS,    //        X


    // *** Register CP_VDC_CLK_CTRL: Pixel clock control
                                // 4100 4200
                                //  B/C B0/1
    CLOCK_AU_CLK_SELECT,        //       X
    CLOCK_HDMI_148P35_EN,       //       X
    CLOCK_VDC_DA_CFG,           //   X   X
    //CLOCK_VDC_DA_CLK_EN       //   X   X    Defined below
    //CLOCK_VDC_DB_CLK_EN       //   X   X    Defined below
    CLOCK_VDC_DIV_EN,           //   X
    CLOCK_VDC_MDVO_CFG,         //   X   X
    //CLOCK_VDC_MDVO_CLK_EN     //   X   X    Defined below

    // *** Register CP_UNIT_RST: Unit Reset
                                // 4100 4200
                                //  B/C B0/1
    //CLOCK_AU_DSP0_RST         //   X   X    Defined below
    //CLOCK_AU_DSP1_RST         //   X   X    Defined below
    //CLOCK_AU_IF_RST           //   X   X    Defined below
    //CLOCK_CRU_RST             //   X   X    Defined below
    //CLOCK_DFX_RST             //   X   X    Defined below
    //CLOCK_DPE_RST             //   X   X    Defined below
    //CLOCK_GBE_RST             //   X   X    Defined below
    CLOCK_GBLVSPARC_RST,        //   X   X
    CLOCK_GFX_RST,              //   X   X
    //CLOCK_GFX2D_RST           //       X    Defined below
    //CLOCK_H264VE_RST          //       X    Defined below
    //CLOCK_HDMI_RST            //   X   X    Defined below
    //CLOCK_HDMI_I2C_RST        //   X   X    Defined below
    //CLOCK_HDVCAP_RST          //       X    Defined below
    CLOCK_MFD_RST,              //   X   X
    CLOCK_NAND_RST,             //   X   X
    CLOCK_PCIE_RST,             //       X
    CLOCK_PF_RST,               //   X   X
    //CLOCK_SATA_RST            //   X   X    Defined below
    //CLOCK_SEC_RST             //   X   X    Defined below
    //CLOCK_TSD_RST             //       X    Defined below
    //CLOCK_USB_RST             //   X   X    Defined below
    CLOCK_USB_RST_CFG,          //       X
    CLOCK_USB_RST_SW,           //       X
    //CLOCK_VDC_RST             //   X   X    Defined below


    // *** Register CP_PLL_ADDR
                                // 4100 4200
                                //  B/C B0/1
    CLOCK_PLL_ADDR,             //   X   X

    // *** Register CP_PLL_DATA
                                // 4100 4200
                                //  B/C B0/1
    CLOCK_PLL_DATA,             //   X   X

    // *** Register CP_AV DDS Control
    //                          // 4100 4200
                                //  B/C B0/1
    //CLOCK_AV_DDS_CTRL         //   X   X     Defined below

    // *** Register CP_CLK_GATE0
                                // 4100 4200
                                //  B/C B0/1
    //CLOCK_AU_XSI_CLK_EN       //       X    Defined below
    //CLOCK_DPE_CLK_EN          //   X   X    Defined below
    CLOCK_GBLVSPARC_XSI_CLK_EN, //       X
    //CLOCK_GBE_DDS_HREF_CLK_EN //       X    Defined below
    //CLOCK_GBE_HCLK_EN         //       X    Defined below
    //CLOCK_GBE_XSI_CLK_EN      //       X    Defined below
    CLOCK_GFX_CLK_EN,           //   X   X
    //CLOCK_H264_DEF640_CLK_EN  //   X   X    Defined below
    //CLOCK_H264VE_CLK_EN       //       X    Defined below
    //CLOCK_HDVCAP_CLK_EN       //       X    Defined below
    CLOCK_L_AU_DSP_CLK_EN,      //   X   X
    //CLOCK_MPG4_MFD_CLK_EN     //   X   X    Defined below
    //CLOCK_MSPOD_XSI_CLK_EN    //       X    Defined below
    CLOCK_ODLA_CLK_EN,          //       X
    CLOCK_OMAR_CLK_EN,          //       X
    //CLOCK_PAD_GBE_IN_CLK_EN   //       X    Defined below
    //CLOCK_PAD_GBE_REF_CLK_EN  //       X    Defined below
    CLOCK_PMU_CLK_EN,           //       X
    //CLOCK_PREFILTER_XSI_CLK_EN//       X    Defined below
    //CLOCK_RMII_REFCLK_50_CLK_EN/       X    Defined below
    //CLOCK_RSB_MFD_CLK_EN      //   X   X    Defined below
    CLOCK_S_AU_DSP_CLK_EN,      //   X   X
    //CLOCK_SATA_CLK_EN         //       X    Defined below
    //CLOCK_TSD_CLK_EN          //       X    Defined below
    CLOCK_USB_CLK480_EN,        //       X
    //CLOCK_USB_XSI_CLK_EN      //       X    Defined below
    //CLOCK_VC1_MFD_CLK_EN      //   X   X    Defined below
    //CLOCK_VDC_CLK_EN          //   X   X    Defined below
    //CLOCK_VDC_XSI_CLK_EN      //       X    Defined below

    // *** Register CP_CLK_GATE1
                                // 4100 4200
                                //  B/C B0/1
    //CLOCK_GFX2D_CLK_EN        //       X    Defined below
    //CLOCK_MEU_CLK_EN          //       X    Defined below
    //CLOCK_PCIE_BBCLK_EN       //       X    Defined below
    //CLOCK_PCIE_LGCLK_EN       //       X    Defined below

    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    // CE5300 resources
    //
    // Organizied by register in the cp_top unit.
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------

    // *** Register AUDIO_DSP_CLK_CNTL     Audio DSP Control
    CLOCK_AU_DSP1_CLK_EN,
    CLOCK_AU_DSP0_CLK_EN,
    CLOCK_DSP1_CLK_FRQ,
    CLOCK_DSP0_CLK_FRQ,
    CLOCK_AU_DSP1_RST,
    CLOCK_AU_DSP0_RST,

    // *** Register AUDIO_IF_CLK_CNTL      Audio Interfaces Control
    CLOCK_ADAC_RESET,
    CLOCK_MCLK1_OUT_EN,
    CLOCK_MCLK0_OUT_EN,
    CLOCK_AU_XSI_CLK_EN,
    CLOCK_AU_IF_RST,

    // *** Register CP_AV_DDS_CNTL         AV DDS Control
    CLOCK_AV_DDS_CTRL,

    // *** Register CRU_CLK_CNTL           CRU Clock Control
    CLOCK_CRU_RST,

    // *** Register DFX_CLK_CNTL           DFX Clock Control
    CLOCK_DFX_RESET,

    // *** Register DPE_CLK_CNTL           DPE Clock Control
    CLOCK_DPE_CLK_EN,
    CLOCK_DPE_RST,

    // *** Register GBE_CLK_CNTL           GBE Clock Control
    CLOCK_INT_GBE_REF_CLK_EN,
    CLOCK_PAD_GBE_REF_CLK_EN,
    CLOCK_PAD_GBE_IN_CLK_EN,
    CLOCK_RMII_REFCLK_50_CLK_EN,
    CLOCK_GBE_XSI_CLK_EN,
    CLOCK_GBE_HCLK_EN,
    CLOCK_GBE_DDS_HREF_CLK_EN,
    CLOCK_GBE_RST,

    // *** Register GFX2D_CLK_CNTL         GFX 2D Clock Control
    CLOCK_GFX_2D_CLK_EN,
    CLOCK_GFX_2D_RST,

    // *** Register GLOBAL_CLK_CNTL        Global Clock Control
    CLOCK_CLK_27MHZ_OUT_EN,
    CLOCK_CLK_27MHZ_SRC_SEL,
    CLOCK_PSF_RESET,
    CLOCK_SIDEBAND_ROUTER_RESET,
    CLOCK_HCLK_FRQ,
    CLOCK_IOSF_CLK_FRQ,
    CLOCK_XSI_CLK_FRQ,

    // *** Register GLOBAL_VSPARC0_CNTL    Global VSPARC0 Clock Control
    CLOCK_GVT_CLK_FRQ,
    CLOCK_GVT_CLK_EN,
    CLOCK_GVT_VSPARC_RST,

    // *** Register GLOBAL_VSPARC1_CNTL    Global VSPARC1 Clock Control
    CLOCK_GVD_CLK_FREQ,
    CLOCK_GVD_CLK_EN,
    CLOCK_GVD_VSPARC_RST,

    // *** Register H264ENC_CLK_CNTL       H264 Encoder Clock Control
    CLOCK_H264VE_CLK_EN,
    CLOCK_H264VE_CLK_FRQ,
    CLOCK_H264VE_RST,

    // *** Register HDMI_TX_CLK_CNTL       HDMI TX Clock Control
    CLOCK_HDMI_PLL_DIV_RESET,
    CLOCK_HDMI_TX_PLL_RESET,
    CLOCK_HDMI_TX_RST,
    CLOCK_HDMI_I2C_RESET,

    // *** Register HDMI_RX_CLK_CNTL       HDMI RX Clock Control
    CLOCK_HDMI_RX_I2C_RESET,
    CLOCK_HDMI_RX_PLL_DIV_RESET,
    CLOCK_HDMI_RX_PLL_RESET,
    CLOCK_HDMI_RX_CORE_CLK_EN,
    CLOCK_HDMI_RX_CORE_CLK_FREQ,
    CLOCK_HDMI_RX_RST,

    // *** Register HDVCAP_CLK_CNTL        HDVCAP Clock Control
    CLOCK_HDVCAP_CLK_EN,
    CLOCK_HDVCAP_RST,

    // *** Register MEU_CLK_CNTL           MEU Clock Control
    CLOCK_MEU_CLK_EN,
    CLOCK_MEU_CLK_FRQ,

    // *** Register MFD_CLK_CNTL           MFD Clock Control
    CLOCK_MPG2VDP_CLK_EN,
    CLOCK_MFD_RSB_CLK_EN,
    CLOCK_MFVDP_CLK_EN,
    CLOCK_VC1VDP_CLK_EN,
    CLOCK_H264_DEF640_CLK_EN,
    CLOCK_VC1VDP_CLK_FRQ,
    CLOCK_MPG2VDP_CLK_FRQ,
    CLOCK_MFVDP_CLK_FRQ,
    CLOCK_H264DEC_RST,
    CLOCK_VC1VDP_RST,
    CLOCK_MPG2VDP_RST,
    CLOCK_MFVDP_RST,

    // *** Register MSPOD_CLK_CNTL         MSPOD Clock Control
    CLOCK_MSPOD_XSI_CLK_EN,
    CLOCK_MSPOD_RST,

    // *** Register PCI_EX_CLK_CNTL        PCI Ex Clock Control
    CLOCK_PCIE_PLL_EXT_REF_CLKBUFEN,
    CLOCK_PCIE_PLL_INT_REF_CLKBUFEN,
    CLOCK_BBRST_B,
    CLOCK_SBI_BB_RST_B,
    CLOCK_SBI_100_RST_CORE_B,
    CLOCK_PCIE_PHY_CMN_RESET,
    CLOCK_PCIE_BBCLK_EN,
    CLOCK_PCIE_IGCLK_EN,
    CLOCK_PCIE_PHY_CRI_CLK_SEL,

    // *** Register PF_CLK_CNTL            Pre-filter Stream Clock Control
    CLOCK_PREFILTER_XSI_CLK_EN,

    // *** Register PLL_RESET              PLL Reset
    CLOCK_APLL_DIV_RST,
    CLOCK_APLL_VCO_RST,
    CLOCK_DPLL_DIV_RST,
    CLOCK_DPLL_VCO_RST,

    // *** Register SATA_CLK_CNTL          SATA Clock Control
    CLOCK_SATA_PLL_REF_CLKBUF_EN,
    CLOCK_SATA_PHY_CMN_RESET,
    CLOCK_SATA_PLL_CLK_EN,
    CLOCK_SATA_PHY_CRI_CLK_SEL,
    CLOCK_SATA_CLK_EN,
    CLOCK_SATA_RST,

    // *** Register SCD_CLK_CNTL          Scene Change Detect Clock Control
    CLOCK_EPU_CLK_EN,
    CLOCK_EPU_RST,

    // *** Register SEC_CLK_CNTL           SEC Clock Control
    CLOCK_SEC_CLK_FRQ,
    CLOCK_SEC_RST,

    // *** Register SGX_CLK_CNTL           SGX Clock Control
    CLOCK_SGX_CLK_EN,
    CLOCK_SGX_RST,

    // *** Register TS_CLK_CNTL            Transport Stream Clock Control
    CLOCK_TSD_CLK_EN,
    CLOCK_TSD_CLK_FRQ,
    CLOCK_TSD_RST,

    // *** Register USB_CLK_CNTL           USB Clock Control
    CLOCK_USB_WIN_MODE,
    CLOCK_USB_UTMI_CLK_EN,
    CLOCK_USB_XSI_CLK_EN,
    CLOCK_USB_PHY_RST,
    CLOCK_USB_RST,

    // *** Register VDC_CLK_CNTL           VDC Clock Control
    CLOCK_LVDS_CLK_EN,
    CLOCK_HDVCAP_TS_SEL,
    CLOCK_VMASTER_DDS_SEL,
    CLOCK_VDC_DB_CLK_EN,
    CLOCK_VDC_DA_CLK_EN,
    CLOCK_VDC_MDVO_CLK_EN,
    CLOCK_VDC_XSI_CLK_EN,
    CLOCK_VDC_CLK_EN,
    CLOCK_VDC_RST,

} clock_control_resource_t;


// CE3100 vestiges
// To be eliminated when the indicated components stop referencing them from
// source code.  Attempts to access these resources will fail.
#define CLOCK_APLL_FREQ_SEL     ((clock_control_resource_t) -1)  // audio
#define CLOCK_AU_REF_CLK_EN     ((clock_control_resource_t) -1)  // audio
#define CLOCK_AUDIO_PLL_DIV_RST ((clock_control_resource_t) -1)  // audio
#define CLOCK_AUDIO_PLL_RESET   ((clock_control_resource_t) -1)  // audio
#define CLOCK_1394_OCK_DIV      ((clock_control_resource_t) -1)  // tsout
#define CLOCK_POD_MCLKO_DIV     ((clock_control_resource_t) -1)  // demux

//-----------------------------------------------------------------------------
// Synonyms to accommodate silicon naming inconsistencies
//-----------------------------------------------------------------------------
#define CLOCK_DFX_RST           CLOCK_DFX_RESET
#define CLOCK_GFX2D_CLK_EN      CLOCK_GFX_2D_CLK_EN
#define CLOCK_GFX2D_RST         CLOCK_GFX_2D_RST
#define CLOCK_HDMI_I2C_RST      CLOCK_HDMI_I2C_RESET
#define CLOCK_HDMI_RST          CLOCK_HDMI_TX_RST
#define CLOCK_MPG4_MFD_CLK_EN   CLOCK_MFVDP_CLK_EN
#define CLOCK_PCIE_LGCLK_EN     CLOCK_PCIE_IGCLK_EN
#define CLOCK_RSB_MFD_CLK_EN    CLOCK_MFD_RSB_CLK_EN
#define CLOCK_VC1_MFD_CLK_EN    CLOCK_VC1VDP_CLK_EN

#endif //CLOCK_TYPES_H
