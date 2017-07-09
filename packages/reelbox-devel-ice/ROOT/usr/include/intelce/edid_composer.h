//*****************************************************************************
// This file is provided under a dual BSD/LGPLv2.1 license.  When using 
// or redistributing this file, you may do so under either license.
//
// LGPL LICENSE SUMMARY
//
// Copyright(c) 2009-2011. Intel Corporation. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify 
// it under the terms of version 2.1 of the GNU Lesser General Public 
// License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful, but 
// WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public 
// License along with this library; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
// USA. The full GNU Lesser General Public License is included in this 
// distribution in the file called LICENSE.LGPL.
//
// Contact Information:
//     Intel Corporation
//     2200 Mission College Blvd.
//     Santa Clara, CA  97052
//
// BSD LICENSE
//
// Copyright (c) 2009-2011. Intel Corporation. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
//
//   - Redistributions of source code must retain the above copyright 
//     notice, this list of conditions and the following disclaimer.
//   - Redistributions in binary form must reproduce the above copyright 
//     notice, this list of conditions and the following disclaimer in 
//     the documentation and/or other materials provided with the 
//     distribution.
//   - Neither the name of Intel Corporation nor the names of its 
//     contributors may be used to endorse or promote products derived 
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*****************************************************************************

/**
    edid_composer.h

    This the interface to the edid_composer library. The EDID
    composer takes an EDID and combines it with values in the
    platform config file to produce an EDID for upstream
    devices.
*/

#ifndef _EDID_COMPOSER_H
#define _EDID_COMPOSER_H

//*****************************************************************************
//  Include Files
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include <avcap.h>

//*****************************************************************************
//  Structure Declarations
//*****************************************************************************

typedef struct
{
    uint32_t width;
    uint32_t height;
    uint32_t interlaced;
    uint32_t refresh;
} edid_video_mode_t;
/**
 * Structure for edid composer parameter
 * Including special parameters needed to compose edid
 */
typedef struct
{
    edid_video_mode_t        current_mode;
    avcap_edid_audio_mask_t  audio_mask;
    avcap_bool_t             audio_filter;
    avcap_edid_3D_t          enable_3d;
    avcap_edid_latency_t     latency;
    unsigned char           *pa_offset;
} edid_config_t;

//*****************************************************************************
//  Function Declarations
//*****************************************************************************

// Decomposes the EDID and prints it out.
// The abbreviated parameter set to true will print a short version of the EDID.
// The preamble is the what is printed before the EDID is printed.
void print_edid(uint8_t *edid_block, 
                uint32_t edid_bytes,
                bool     abbreviated,
                char    *print_preamble);

bool
compose_edid(uint8_t                *edid_block,
             uint32_t                edid_bytes,
             uint8_t                *new_edid_block,
             uint32_t                new_edid_bytes,
             int32_t                 hdmi_input_port,
             edid_config_t          *cfg);

// Prints the audio mask.
void print_edid_audio_mask(avcap_edid_audio_mask_t audio_mask);

#endif
