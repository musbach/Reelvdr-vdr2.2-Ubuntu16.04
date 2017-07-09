#ifndef _INTEL_CE_DEVICE_IDS_DEFS_H
#define _INTEL_CE_DEVICE_IDS_DEFS_H 1
/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2010 Intel Corporation. All rights reserved.

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

  Copyright(c) 2010 Intel Corporation. All rights reserved.
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

#define CE_SOC_VENDOR_ID_INTEL        0x8086

/* Device IDs for CE3100, CE4100 and CE4200 */
#define CE_SOC_DEVICE_ID_GFX          0x2E5B
#define CE_SOC_DEVICE_ID_GPU_GMH      0x2E5B
#define CE_SOC_DEVICE_ID_CE           0xFFFF
#define CE_SOC_DEVICE_ID_MFD          0x2E5C
#define CE_SOC_DEVICE_ID_TS_PREFILT   0x2E5D
#define CE_SOC_DEVICE_ID_TS_DEMUX0    0x2E5E    // demux for CE3100 and CE4100
#define CE_SOC_DEVICE_ID_AUDIO_DSP0   0x2E5F
#define CE_SOC_DEVICE_ID_AUDIO_DSP1   0x2E5F
#define CE_SOC_DEVICE_ID_AUDIO_IF     0x2E60
#define CE_SOC_DEVICE_ID_VDC          0x2E61
#define CE_SOC_DEVICE_ID_DPE          0x2E62
#define CE_SOC_DEVICE_ID_HDMI_TX      0x2E63
#define CE_SOC_DEVICE_ID_SEC          0x2E64
#define CE_SOC_DEVICE_ID_SRAM         0x2E64
#define CE_SOC_DEVICE_ID_EXP_CSR      0x2E65
#define CE_SOC_DEVICE_ID_EXP_WIN      0x2E65
#define CE_SOC_DEVICE_ID_UART0        0x2E66
#define CE_SOC_DEVICE_ID_UART1        0x2E66
#define CE_SOC_DEVICE_ID_GPIO         0x2E67
#define CE_SOC_DEVICE_ID_I2C0         0x2E68
#define CE_SOC_DEVICE_ID_I2C1         0x2E68
#define CE_SOC_DEVICE_ID_I2C2         0x2E68
#define CE_SOC_DEVICE_ID_SC0          0x2E69
#define CE_SOC_DEVICE_ID_SC1          0x2E69
#define CE_SOC_DEVICE_ID_SPI          0x2E6A
#define CE_SOC_DEVICE_ID_MSPOD        0x2E6B
#define CE_SOC_DEVICE_ID_IR           0x2E6C
#define CE_SOC_DEVICE_ID_DFX          0x2E6D
#define CE_SOC_DEVICE_ID_GBE          0x2E6E
#define CE_SOC_DEVICE_ID_GBE_MDIO     0x2E6E
#define CE_SOC_DEVICE_ID_CRU          0x2E6F
#define CE_SOC_DEVICE_ID_USB0         0x0101
#define CE_SOC_DEVICE_ID_USB1         0x0101
#define CE_SOC_DEVICE_ID_USB2         0x0101
#define CE_SOC_DEVICE_ID_USB3         0x0101
#define CE_SOC_DEVICE_ID_SATA         0x2E71

/* Device IDs for CE4100 and CE4200 */
#define CE_SOC_DEVICE_ID_NAND_DEV     0x0701
#define CE_SOC_DEVICE_ID_NAND_CSR     0x0701
#define CE_SOC_DEVICE_ID_MEUCSR       0x0702
#define CE_SOC_DEVICE_ID_MEUREG0      0x0702
#define CE_SOC_DEVICE_ID_MEUREG1      0x0702
#define CE_SOC_DEVICE_ID_GV           0x0703

/* Device IDs for CE4200 */
#define CE_SOC_DEVICE_ID_HDVCAP       0x0704
#define CE_SOC_DEVICE_ID_TS_DEMUX1    0x0705    // demux for CE4200
#define CE_SOC_DEVICE_ID_H264VE       0x0706
#define CE_SOC_DEVICE_ID_DAA_SPI      0x0707

/* Device IDs for CE5300 */
#define CE_SOC_DEVICE_ID_EPU          0x089c
#define CE_SOC_DEVICE_ID_GVSPARC_D    0x089d

#endif /* _INTEL_CE_DEVICE_IDS_DEFS_H */
