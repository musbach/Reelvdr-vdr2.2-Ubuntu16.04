//-----------------------------------------------------------------------------
// This file is provided under a dual BSD/GPLv2 license.  When using or
// redistributing this file, you may do so under either license.
//
// GPL LICENSE SUMMARY
//
// Copyright(c) 2011 Intel Corporation. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
// The full GNU General Public License is included in this distribution
// in the file called LICENSE.GPL.
//
// Contact Information:
//      Intel Corporation
//      2200 Mission College Blvd.
//      Santa Clara, CA  97052
//
// BSD LICENSE
//
// Copyright(c) 2011 Intel Corporation. All rights reserved.
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
//-----------------------------------------------------------------------------

#ifndef __EXT_BUF_ACCESS_H__
#define __EXT_BUF_ACCESS_H__

#include "ismd_global_defs.h"
#include "osal.h"
#include "ismd_core.h"
#include "gdl_types.h"

// Convert a floating point number to s7.24 fixed point.
#define TO_FIXED(val, to)                                           \
do {                                                                \
    float fval = val;                                               \
    union { gdl_uint32 fixed; float flt; } conv = { 0 };            \
    if (fval < 0)                                                   \
    {                                                               \
        conv.fixed = 0x80000000;                                    \
        fval = -fval;                                               \
    }                                                               \
    conv.fixed |= ((int) fval) << 24;                               \
    conv.fixed |= (unsigned int)((fval - (int) fval) * (1<<24));    \
    to = conv.flt;                                                  \
} while (0)

#define COPY_CSC_ADJ(csc_in, csc_out)                               \
do {                                                                \
    int i;                                                          \
    OS_MEMCPY(csc_out, csc_in, sizeof(gdl_csc_t));                  \
    for (i = 0; i < 9; i++)                                         \
         TO_FIXED((csc_in)->c[i], (csc_out)->c[i]);                 \
} while(0)

#define COPY_CSC_CLAMPS(clamps_in, clamps_out)                      \
    OS_MEMCPY(clamps_out, clamps_in, sizeof(gdl_csc_clamps_t))

#define COPY_GAMMA_CURVE(curve_in, curve_out)                               \
do {                                                                        \
    unsigned int i;                                                         \
    (curve_out)->length = (curve_in)->length;                               \
    TO_FIXED((curve_in)->color_limit, (curve_out)->color_limit);            \
    for (i = 0; i < (curve_in)->length && i < GDL_GAMMA_MAX_POINTS; i++)    \
    {                                                                       \
         TO_FIXED((curve_in)->r_y[i], (curve_out)->r_y[i]);                 \
         TO_FIXED((curve_in)->g_u[i], (curve_out)->g_u[i]);                 \
         TO_FIXED((curve_in)->b_v[i], (curve_out)->b_v[i]);                 \
    }                                                                       \
} while(0)

// Allocate and fill a field in an extension buffer. Float values are converted
// to s7.24 fixed point
#define FILL_FIELD(field_id, type, name, copy_macro)                        \
do {                                                                        \
    if (name)                                                               \
    {                                                                       \
        rc = ismd_buffer_alloc_field(ext_buffer_id,                         \
                                     ISMD_EXT_BUFFER_FIELD_ID_##field_id,   \
                                     sizeof(type),                          \
                                     &(ext_buf_attr->video.name));          \
        if (rc != ISMD_SUCCESS) goto exit;                                  \
        copy_macro(name, (type*)(base_address + ext_buf_attr->video.name)); \
    }                                                                       \
    else                                                                    \
        ext_buf_attr->video.name = 0;                                       \
} while(0)

// Retrieve a field from an extension buffer and copy into preallocated memory.
// If the field does not exist in the extension buffer then the memory is not
// modified. Float values are assumed to be in s7.24 fixed point format
#define GET_FIELD(field_id, type, name)                                     \
do {                                                                        \
    if (name && ext_buf_attr->video.name)                                   \
        OS_MEMCPY(name,                                                     \
                  base_address + ext_buf_attr->video.name,                  \
                  sizeof(type));                                            \
} while(0)

// If a field exists in the extension buffer, then allocate memory large enough
// to hold the contents and fill it with the data from the extension buffer.
// Set the pointer to NULL if the field does not exist
#define GET_FIELD_ALLOC(field_id, type, name)                               \
do {                                                                        \
    if (name)                                                               \
    {                                                                       \
        if (ext_buf_attr->video.name)                                       \
        {                                                                   \
            *name = OS_ALLOC(sizeof(type));                                 \
            OS_MEMCPY(*name,                                                \
                      base_address + ext_buf_attr->video.name,              \
                      sizeof(type));                                        \
        }                                                                   \
        else                                                                \
            *name = NULL;                                                   \
    }                                                                       \
} while (0)


#ifndef __KERNEL__

//------------------------------------------------------------------------------
// ismd_ext_buffer_fill_video
//
// Fill an extention buffer which has already been allocated with video-related
// data. If a parameter is non-NULL, then the corresponding field in the
// extension buffer will be allocated and filled in. The extension buffer must
// be large enough to hold all of the provided fields, or this function will fail.
//
// This function may only be called from user-space
//------------------------------------------------------------------------------
ismd_result_t ismd_ext_buffer_fill_video(ismd_buffer_handle_t ext_buffer_id,
                                         gdl_csc_t          * plane_csc_adj,
                                         gdl_csc_clamps_t   * plane_input_clamps,
                                         gdl_csc_clamps_t   * plane_output_clamps,
                                         gdl_csc_t          * post_blend_csc_adj,
                                         gdl_csc_clamps_t   * post_blend_input_clamps,
                                         gdl_csc_clamps_t   * post_blend_output_clamps,
                                         gdl_gamma_curve_t  * post_blend_gamma_lut_1,
                                         gdl_gamma_curve_t  * post_blend_gamma_lut_2)
{
    ismd_result_t            rc = ISMD_SUCCESS;
    ismd_buffer_descriptor_t desc;
    ismd_ext_buffer_attr_t * ext_buf_attr;
    void                   * base_address;

    rc = ismd_buffer_read_desc(ext_buffer_id, &desc);
    if (rc != ISMD_SUCCESS)
        goto exit;

    ext_buf_attr = (ismd_ext_buffer_attr_t *) desc.attributes;
    base_address = OS_MAP_IO_TO_MEM_NOCACHE(desc.phys.base, desc.phys.size);

    if (base_address == NULL)
    {
        rc = ISMD_ERROR_NULL_POINTER;
        goto exit;
    }

    // Note: Due to macro simplifications, the parameter names for this function
    // must match the name of the struct member
    FILL_FIELD(PLANE_CSC_ADJ,    gdl_csc_t,         plane_csc_adj,            COPY_CSC_ADJ   );
    FILL_FIELD(PLANE_IN_CLAMP,   gdl_csc_clamps_t,  plane_input_clamps,       COPY_CSC_CLAMPS);
    FILL_FIELD(PLANE_OUT_CLAMP,  gdl_csc_clamps_t,  plane_output_clamps,      COPY_CSC_CLAMPS);

    FILL_FIELD(POST_CSC_ADJ,     gdl_csc_t,         post_blend_csc_adj,       COPY_CSC_ADJ   );
    FILL_FIELD(POST_IN_CLAMP,    gdl_csc_clamps_t,  post_blend_input_clamps,  COPY_CSC_CLAMPS);
    FILL_FIELD(POST_OUT_CLAMP,   gdl_csc_clamps_t,  post_blend_output_clamps, COPY_CSC_CLAMPS);
    FILL_FIELD(POST_GAMMA_LUT_1, gdl_gamma_curve_t, post_blend_gamma_lut_1,   COPY_GAMMA_CURVE);
    FILL_FIELD(POST_GAMMA_LUT_2, gdl_gamma_curve_t, post_blend_gamma_lut_2,   COPY_GAMMA_CURVE);


    OS_UNMAP_IO_FROM_MEM(base_address, desc.phys.size);

    rc = ismd_buffer_update_desc(ext_buffer_id, &desc);

exit:
    return rc;
}

#else

//------------------------------------------------------------------------------
// ismd_ext_buffer_get_video
//
// Retrieve video-related data from an extension buffer.
//
// If the csc adjustment or clamps parameters are non-NULL, then new values (if
// present in the extension buffer) will be copied into them.
//
// If the gamma curve parameters are non-NULL, then a buffer will be allocated
// to hold the data from the extension buffer.  This buffer must be freed by
// the caller.
//
// This function may only be called from kernel space
//------------------------------------------------------------------------------
ismd_result_t ismd_ext_buffer_get_video(ismd_buffer_handle_t   ext_buffer_id,
                                        gdl_csc_t            * plane_csc_adj,
                                        gdl_csc_clamps_t     * plane_input_clamps,
                                        gdl_csc_clamps_t     * plane_output_clamps,
                                        gdl_csc_t            * post_blend_csc_adj,
                                        gdl_csc_clamps_t     * post_blend_input_clamps,
                                        gdl_csc_clamps_t     * post_blend_output_clamps,
                                        gdl_gamma_curve_t   ** post_blend_gamma_lut_1,
                                        gdl_gamma_curve_t   ** post_blend_gamma_lut_2)
{
    ismd_result_t            rc = ISMD_SUCCESS;
    ismd_buffer_descriptor_t desc;
    ismd_ext_buffer_attr_t * ext_buf_attr;
    void                   * base_address;

    rc = ismd_buffer_read_desc(ext_buffer_id, &desc);
    if (rc != ISMD_SUCCESS)
        goto exit;

    ext_buf_attr = (ismd_ext_buffer_attr_t *) desc.attributes;
    base_address = OS_MAP_IO_TO_MEM_NOCACHE(desc.phys.base, desc.phys.size);

    if (base_address == NULL)
    {
        rc = ISMD_ERROR_NULL_POINTER;
        goto exit;
    }

    GET_FIELD(PLANE_CSC_ADJ,    gdl_csc_t,         plane_csc_adj);
    GET_FIELD(PLANE_IN_CLAMP,   gdl_csc_clamps_t,  plane_input_clamps);
    GET_FIELD(PLANE_OUT_CLAMP,  gdl_csc_clamps_t,  plane_output_clamps);

    GET_FIELD(POST_CSC_ADJ,     gdl_csc_t,         post_blend_csc_adj);
    GET_FIELD(POST_IN_CLAMP,    gdl_csc_clamps_t,  post_blend_input_clamps);
    GET_FIELD(POST_OUT_CLAMP,   gdl_csc_clamps_t,  post_blend_output_clamps);

    GET_FIELD_ALLOC(POST_GAMMA_LUT_1, gdl_gamma_curve_t, post_blend_gamma_lut_1);
    GET_FIELD_ALLOC(POST_GAMMA_LUT_2, gdl_gamma_curve_t, post_blend_gamma_lut_2);

    OS_UNMAP_IO_FROM_MEM(base_address, desc.phys.size);

exit:
    return rc;
}

#endif // !__KERNEL__

#undef TO_FIXED
#undef COPY_CSC_ADJ
#undef COPY_CSC_CLAMPS
#undef COPY_GAMMA_CURVE
#undef FILL_FIELD
#undef GET_FIELD
#undef GET_FIELD_ALLOC

#endif
