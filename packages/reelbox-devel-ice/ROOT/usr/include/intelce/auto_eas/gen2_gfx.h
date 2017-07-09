#ifndef GFX_REGOFFS_H
#define GFX_REGOFFS_H 1
#warning including deprecated file GFX_REGOFFS_H please use sanitized filename
/*

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2009 Intel Corporation. All rights reserved.

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

  Copyright(c) 2007-2009 Intel Corporation. All rights reserved.
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


/* Module GFX CSR Definitions */
/* WARNING: This file is Machine Generated using sven_csr.c */


#define ROFF_GFX_Software_Reset	0x80 /*  */ 
	#define BITFIELD_GFX_Software_Reset	 0x0080, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Interrupt_Status	0x12c /*  */ 
	#define BITFIELD_GFX_Interrupt_Status	 0x012c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Interrupt_Enable	0x130 /*  */ 
	#define BITFIELD_GFX_Interrupt_Enable	 0x0130, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Interrupt_Clear	0x134 /*  */ 
	#define BITFIELD_GFX_Interrupt_Clear	 0x0134, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Memory_Page_Size	0x140 /*  */ 
	#define BITFIELD_GFX_Memory_Page_Size	 0x0140, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Region_HeaderBase	0x608 /*  */ 
	#define BITFIELD_GFX_3D_Region_HeaderBase	 0x0608, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Object_Base	0x60c /*  */ 
	#define BITFIELD_GFX_3D_Object_Base	 0x060c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Z_Load_Store_Control	0x610 /*  */ 
	#define BITFIELD_GFX_3D_Z_Load_Store_Control	 0x0610, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_FPU_PerpendicularCompare	0x614 /*  */ 
	#define BITFIELD_GFX_3D_FPU_PerpendicularCompare	 0x0614, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_FPU_Cull_Value	0x618 /*  */ 
	#define BITFIELD_GFX_3D_FPU_Cull_Value	 0x0618, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Pixel_Sampling	0x61c /*  */ 
	#define BITFIELD_GFX_3D_Pixel_Sampling	 0x061c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Colour_Key_1	0x624 /*  */ 
	#define BITFIELD_GFX_3D_Colour_Key_1	 0x0624, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Colour_Key_2	0x628 /*  */ 
	#define BITFIELD_GFX_3D_Colour_Key_2	 0x0628, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Colour_Key_UV	0x62c /*  */ 
	#define BITFIELD_GFX_3D_Colour_Key_UV	 0x062c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Colour_Key_Mask	0x630 /*  */ 
	#define BITFIELD_GFX_3D_Colour_Key_Mask	 0x0630, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Vertex_Fog_Colour	0x63c /*  */ 
	#define BITFIELD_GFX_3D_Vertex_Fog_Colour	 0x063c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Vertex_Fog_Status	0x640 /*  */ 
	#define BITFIELD_GFX_3D_Vertex_Fog_Status	 0x0640, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_scalar_Control	0x644 /*  */ 
	#define BITFIELD_GFX_3D_scalar_Control	 0x0644, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Blend_ARGB_Sum	0x648 /*  */ 
	#define BITFIELD_GFX_3D_Blend_ARGB_Sum	 0x0648, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Write_Control	0x650 /*  */ 
	#define BITFIELD_GFX_3D_Write_Control	 0x0650, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Write_X_Clipping	0x654 /*  */ 
	#define BITFIELD_GFX_3D_Write_X_Clipping	 0x0654, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Write_Y_Clipping	0x658 /*  */ 
	#define BITFIELD_GFX_3D_Write_Y_Clipping	 0x0658, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Render_Address	0x65c /*  */ 
	#define BITFIELD_GFX_3D_Render_Address	 0x065c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Write_Stride	0x660 /*  */ 
	#define BITFIELD_GFX_3D_Write_Stride	 0x0660, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Texture_Latency	0x664 /*  */ 
	#define BITFIELD_GFX_3D_Texture_Latency	 0x0664, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Z_Base_Address	0x674 /*  */ 
	#define BITFIELD_GFX_3D_Z_Base_Address	 0x0674, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Start_Render	0x680 /*  */ 
	#define BITFIELD_GFX_3D_Start_Render	 0x0680, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Flat_Shaded_Colour_Source	0x6d0 /*  */ 
	#define BITFIELD_GFX_3D_Flat_Shaded_Colour_Source	 0x06d0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_ZLoad_Background_Tag	0x6d8 /*  */ 
	#define BITFIELD_GFX_3D_ZLoad_Background_Tag	 0x06d8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_ZLoad_Background_Depth	0x6dc /*  */ 
	#define BITFIELD_GFX_3D_ZLoad_Background_Depth	 0x06dc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_1Bpp_Background_Colour	0x6e0 /*  */ 
	#define BITFIELD_GFX_3D_1Bpp_Background_Colour	 0x06e0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_1Bpp_Foreground_Colour	0x6e4 /*  */ 
	#define BITFIELD_GFX_3D_1Bpp_Foreground_Colour	 0x06e4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_1Bpp_Use_Register_Values	0x6e8 /*  */ 
	#define BITFIELD_GFX_3D_1Bpp_Use_Register_Values	 0x06e8, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Render_ID	0x6ec /*  */ 
	#define BITFIELD_GFX_3D_Render_ID	 0x06ec, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_3D_Texture_Decimation	0x6f0 /*  */ 
	#define BITFIELD_GFX_3D_Texture_Decimation	 0x06f0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Start	0x800 /*  */ 
	#define BITFIELD_GFX_TA_Start	 0x0800, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Restart	0x804 /*  */ 
	#define BITFIELD_GFX_TA_Restart	 0x0804, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Abort	0x808 /*  */ 
	#define BITFIELD_GFX_TA_Abort	 0x0808, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Render_ID	0x810 /*  */ 
	#define BITFIELD_GFX_TA_Render_ID	 0x0810, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Context_Load	0x814 /*  */ 
	#define BITFIELD_GFX_TA_Context_Load	 0x0814, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Context_Store	0x818 /*  */ 
	#define BITFIELD_GFX_TA_Context_Store	 0x0818, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Context_Reset	0x81c /*  */ 
	#define BITFIELD_GFX_TA_Context_Reset	 0x081c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Context_Base	0x820 /*  */ 
	#define BITFIELD_GFX_TA_Context_Base	 0x0820, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_Page_Table_Base_Address	0x824 /*  */ 
	#define BITFIELD_GFX_EVM_Page_Table_Base_Address	 0x0824, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_List_Start_Page	0x828 /*  */ 
	#define BITFIELD_GFX_EVM_List_Start_Page	 0x0828, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_List_End_Page	0x82c /*  */ 
	#define BITFIELD_GFX_EVM_List_End_Page	 0x082c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_Render_Timeout	0x830 /*  */ 
	#define BITFIELD_GFX_EVM_Render_Timeout	 0x0830, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_TA_Timeout	0x834 /*  */ 
	#define BITFIELD_GFX_EVM_TA_Timeout	 0x0834, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_Init	0x838 /*  */ 
	#define BITFIELD_GFX_EVM_Init	 0x0838, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_ObjectBase_Address	0x83c /*  */ 
	#define BITFIELD_GFX_TA_ObjectBase_Address	 0x083c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Tail_Pointer_Base_Address	0x840 /*  */ 
	#define BITFIELD_GFX_TA_Tail_Pointer_Base_Address	 0x0840, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Region_Base_Address	0x844 /*  */ 
	#define BITFIELD_GFX_TA_Region_Base_Address	 0x0844, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_X_Screen_Clip	0x84c /*  */ 
	#define BITFIELD_GFX_TA_X_Screen_Clip	 0x084c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Y_Screen_Clip	0x850 /*  */ 
	#define BITFIELD_GFX_TA_Y_Screen_Clip	 0x0850, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_RHW_Clamp	0x854 /*  */ 
	#define BITFIELD_GFX_TA_RHW_Clamp	 0x0854, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_RHW_Compare	0x858 /*  */ 
	#define BITFIELD_GFX_TA_RHW_Compare	 0x0858, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TA_Configuration	0x85c /*  */ 
	#define BITFIELD_GFX_TA_Configuration	 0x085c, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_EVM_Context_Base_Address	0x864 /*  */ 
	#define BITFIELD_GFX_EVM_Context_Base_Address	 0x0864, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_ISP1_Signature	0xcc4 /*  */ 
	#define BITFIELD_GFX_ISP1_Signature	 0x0cc4, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_TSP1_Signature	0xccc /*  */ 
	#define BITFIELD_GFX_TSP1_Signature	 0x0ccc, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Diagnostics_Enable	0xce0 /*  */ 
	#define BITFIELD_GFX_Diagnostics_Enable	 0x0ce0, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_MBX_Lite_Core_ID	0xf00 /*  */ 
	#define BITFIELD_GFX_MBX_Lite_Core_ID	 0x0f00, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_MBX_Lite_Core_Revision	0xf10 /*  */ 
	#define BITFIELD_GFX_MBX_Lite_Core_Revision	 0x0f10, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Clock_Ratio_Status	0x90 /*  */ 
	#define BITFIELD_GFX_Clock_Ratio_Status	 0x0090, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_2D_Idle_Timeout_Clock_Cycle_Count	0x100 /*  */ 
	#define BITFIELD_GFX_2D_Idle_Timeout_Clock_Cycle_Count	 0x0100, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_Startup_Timeout_Clock_Cycle_Count	0x104 /*  */ 
	#define BITFIELD_GFX_Startup_Timeout_Clock_Cycle_Count	 0x0104, 0, 32, 0xffffffff  /* roff, lsb, width, mask */
#define ROFF_GFX_General_Purpose_Output	0x108 /*  */ 
	#define BITFIELD_GFX_General_Purpose_Output	 0x0108, 0, 32, 0xffffffff  /* roff, lsb, width, mask */


/* Module GFX SPECIFIC SVEN Events */




#endif /* GFX_REGOFFS_H */
