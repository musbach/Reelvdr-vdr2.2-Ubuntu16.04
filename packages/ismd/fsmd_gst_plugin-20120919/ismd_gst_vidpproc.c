/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2012. Intel Corporation. All rights reserved.
    Copyright(c) 2009, 2010. Fluendo S.A. All rights reserved.

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation; either version 2.1 of the
    License.

    This library is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
    USA. The full GNU Lesser General Public License is included in this
    distribution in the file called LICENSE.LGPL.

    Contact Information for Intel:
        Intel Corporation
        2200 Mission College Blvd.
        Santa Clara, CA  97052

    Contat Information for Fluendo:
        FLUENDO S.A.
        World Trade Center Ed Norte 4 pl.
        Moll de Barcelona
        08039 BARCELONA - SPAIN

    BSD LICENSE

    Copyright (c) 2012. Intel Corporation. All rights reserved.
    Copyright(c) 2009, 2010. Fluendo S.A. All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

      - Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      - Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in
        the documentation and/or other materials provided with the
        distribution.
      - Neither the name of Intel Corporation nor the names of its
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

#include <stdlib.h>
#include <string.h>

#include "ismd_gst_element.h"
#include "ismd_gst_vidpproc.h"
#include "platform_config_paths.h"
#include "platform_config.h"
#include "ismd_gst_enum.h"
#include "ismd_gst_rectangle.h"

////////////////////////////////////////////////////////////////////////////////
// Shortcut macros for accessing core platform configuration properties
////////////////////////////////////////////////////////////////////////////////

#ifndef ISMD_CORE_INT_PROPERTY
#define ISMD_CORE_INT_PROPERTY(name) ({                                         \
   config_result_t icipret = CONFIG_SUCCESS;                                    \
   int icipint = 0;                                                             \
   config_ref_t icip_attr_id = ROOT_NODE;                                       \
                                                                                \
   icipret = config_node_find(ROOT_NODE,                                        \
                              CONFIG_PATH_SMD_CORE,                             \
                              &icip_attr_id);                                   \
   if (icipret == CONFIG_SUCCESS) {                                             \
      icipret = config_get_int(icip_attr_id, name, &icipint);                   \
   }                                                                            \
                                                                                \
   if (icipret != CONFIG_SUCCESS) {                                             \
      OS_INFO("Error! %s undefined!", name);                                    \
   }                                                                            \
   icipint;                                                                     \
})
#endif

#define SYSTEM_STRIDE ISMD_CORE_INT_PROPERTY("frame_buffer_properties.stride")
#define CACHE_LINE_SIZE (64)
#define ROUND_UP(num, amt) ((num%amt) ? (num+amt) - (num%amt) : num)

static GstStateChangeReturn ismd_gst_vidpproc_change_state (GstElement *
    element, GstStateChange transition);

/* 
 * ISMD_GST_VIDPPROC_SINK_CAPS is defined in ismd_gst_vidpproc.h to allow
 * the refiller to see it.
 */

#define ISMD_GST_VIDPPROC_SRC_CAPS \
           "video/x-raw-ismd"

static GstStaticPadTemplate ismd_gst_vidpproc_sinkpad_template =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VIDPPROC_SINK_CAPS)
    );

static GstStaticPadTemplate ismd_gst_vidpproc_srcpad_template =
GST_STATIC_PAD_TEMPLATE ("src_1",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VIDPPROC_SRC_CAPS)
    );

static GstStaticCaps srccap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_VIDPPROC_SRC_CAPS };
static GstStaticCaps sinkcap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_VIDPPROC_SINK_CAPS };

static inline gboolean ismd_open (GstElement * element);

GST_DEBUG_CATEGORY_STATIC (ismd_gst_vidpproc_debug);
#define GST_CAT_DEFAULT ismd_gst_vidpproc_debug

enum
{
  PROP_VIDPPROC_UNKNOWN,
  PROP_VIDPPROC_SCALE_MODE,
  PROP_VIDPPROC_PAN_AND_SCAN,
  PROP_VIDPPROC_RECTANGLE
};

#define DEFAULT_ISMD_VIDPPROC_SCALE_MODE      ZOOM_TO_FIT
#define DEFAULT_ISMD_VIDPPROC_RECTANGLE       "0,0,0,0"
#define DEFAULT_ISMD_VIDPPROC_PAN_AND_SCAN    FALSE

enum
{
  FORMAT_UNDEFINED,
  FORMAT_ISMD,
  FORMAT_RAW,
  FORMAT_LAST
};

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_vidpproc_debug, "ISMD_VIDPPROC",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstvidpproc element");
}

GST_BOILERPLATE_FULL (ISmdGstVidpproc, ismd_gst_vidpproc,
    ISmdGstElement, ISMD_GST_TYPE_ELEMENT, _do_init);

static inline gboolean
update_dest_rect (ISmdGstElement * smdelement)
{
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (smdelement);

  guint x = 0, y = 0;
  guint width = 0, height = 0;

  x = gst_value_get_rectangle_x (&vidpproc->rectangle);
  y = gst_value_get_rectangle_y (&vidpproc->rectangle);
  width = gst_value_get_rectangle_width (&vidpproc->rectangle);
  height = gst_value_get_rectangle_height (&vidpproc->rectangle);

  /* 0,0,0,0 means full screen, also protect against wrong values */
  if (!width || width > vidpproc->tv_width || !height
    || height > vidpproc->tv_height) {
    width = vidpproc->tv_width;
    height = vidpproc->tv_height;
  }

  if (x + width > vidpproc->tv_width)
    x = vidpproc->tv_width - width;

  if (y + height > vidpproc->tv_height)
    y = vidpproc->tv_height - height;

  GST_DEBUG_OBJECT (vidpproc, "Configuring vidpproc with width %d height %d",
      width, height);

  /* The pixel aspect ratio is carried in the ismd buffer */
  if (ISMD_SUCCESS != ismd_vidpproc_set_dest_params2 (smdelement->dev_handle,
          width, height, 0, 0, x, y)) {
    GST_ERROR_OBJECT (vidpproc, "ismd_vidpproc_set_dest_params failed");
    return FALSE;
  }

  return TRUE;
}

static GstPadLinkReturn
ismd_gst_vidpproc_setcaps (GstPad * pad, GstCaps * caps)
{
  GstStructure *structure;
  const gchar *name = NULL;
  GstPad *srcpad;
  GstCaps *srccaps;
  gboolean ret = FALSE;
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (gst_pad_get_parent (pad));
  const GValue *par, *fps;
  guint32 fourcc;
  GST_DEBUG_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  structure = gst_caps_get_structure (caps, 0);
  name = gst_structure_get_name (structure);

  if (!strcmp (name, "video/x-raw-yuv") || !strcmp (name, "video/x-decoded-ismd")) {
    if (!gst_structure_get_int (structure, "width", &vidpproc->width) ||
          !gst_structure_get_int (structure, "height", &vidpproc->height)) {
      vidpproc->width = vidpproc->height = 0;      
    }
    if (gst_structure_get_fourcc (structure, "format", &fourcc)) {
      if (fourcc == GST_MAKE_FOURCC ('Y', 'V', '1', '2')) {
        vidpproc->is_yv12 = TRUE;
      }
      if (fourcc == GST_MAKE_FOURCC ('I', '4', '2', '0')) {
        vidpproc->is_i420 = TRUE;
      }
      if (vidpproc->is_yv12 || vidpproc->is_i420) {
        if (!vidpproc->width || !vidpproc->height) {
          GST_WARNING_OBJECT (vidpproc, "missing parameters from the caps " \
              "(required width, height)");
          goto beach;
        }
      }
    }

    par = gst_structure_get_value (structure, "pixel-aspect-ratio");
    if (par) {
      vidpproc->aspect_x = gst_value_get_fraction_numerator (par);
      vidpproc->aspect_y = gst_value_get_fraction_denominator (par);
    }
    else {
      vidpproc->aspect_x = vidpproc->aspect_y = 1;
    }

    fps = gst_structure_get_value (structure, "framerate");
    if (fps) {
      vidpproc->fps_n = gst_value_get_fraction_numerator (fps);
      vidpproc->fps_d = gst_value_get_fraction_denominator (fps);
    }
    else {
      vidpproc->fps_n = 30;
      vidpproc->fps_d = 1;
    }

    GST_OBJECT_LOCK (vidpproc);
    update_dest_rect (ISMD_GST_ELEMENT (vidpproc));
    GST_OBJECT_UNLOCK (vidpproc);

    srcpad = gst_element_get_static_pad (GST_ELEMENT (vidpproc), "src_1");
    srccaps = gst_caps_new_simple ("video/x-raw-ismd",
        "width", G_TYPE_INT, vidpproc->width,
        "height", G_TYPE_INT, vidpproc->height,
        "framerate", GST_TYPE_FRACTION, vidpproc->fps_n, vidpproc->fps_d,
#ifndef NOT_REEL_PATCHED
        "ismd-decoded", G_TYPE_BOOLEAN, !strcmp (name, "video/x-decoded-ismd"),
#endif
        "pixel-aspect-ratio", GST_TYPE_FRACTION, vidpproc->aspect_x,
        vidpproc->aspect_y, NULL);

    if (gst_pad_peer_accept_caps (srcpad, srccaps)) {
      GST_DEBUG_OBJECT (vidpproc, "setting caps downstream to %" GST_PTR_FORMAT,
          srccaps);
      ret = gst_pad_set_caps (srcpad, srccaps);
      if (G_UNLIKELY (!ret)) {
        GST_ERROR_OBJECT (vidpproc, "failed setting downstream caps to %"
            GST_PTR_FORMAT, srccaps);
      }
    }
    gst_caps_unref (srccaps);
    gst_object_unref (srcpad);
    ret = TRUE;
  }

beach:
  gst_object_unref (vidpproc);
  return ret;
}

static GstFlowReturn
vidpproc_alloc_nv12 (ISmdGstVidpproc * vidpproc, ISmdGstBuffer **ismd_gst_buf,
    gint width, gint height, gint par_x, gint par_y)
{
  GstFlowReturn ret = GST_FLOW_OK;
  ismd_buffer_handle_t hbuf;
  ismd_buffer_descriptor_t desc;
  ismd_frame_attributes_t *attr;
  ismd_result_t result;
  void *data_ptr;
  gint height_to_alloc;

  /* Allocate a physically-contiguous frame buffer.
   * After reserving the physical memory through the SMD core, we need to init
   * the descriptor to contain the image attributes. */
  height_to_alloc = (height * 3) / 2;

  result = ismd_frame_buffer_alloc (ROUND_UP (width, CACHE_LINE_SIZE),
      height_to_alloc, &hbuf);
  if (result != ISMD_SUCCESS)
    goto allocation_failed;

  ismd_buffer_read_desc (hbuf, &desc);
  // Now fill in the zillion of frame attribute fields
  attr = (ismd_frame_attributes_t *) desc.attributes;
  attr->discontinuity = FALSE;
  attr->cont_rate = 0;
  if (par_y) {
    attr->cont_ratio.numerator = par_x;
    attr->cont_ratio.denominator = par_y;
  } else {
    attr->cont_ratio.numerator = 0;
    attr->cont_ratio.denominator = 0;
  }
  attr->cont_size.width = width;
  attr->cont_size.height = height;
  attr->dest_size.width = width;
  attr->dest_size.height = height;
  attr->pixel_format = ISMD_PF_NV12;
  attr->color_space = ISMD_SRC_COLOR_SPACE_BT709;       // used
  attr->polarity = ISMD_POLARITY_FRAME; // FIXME: can we tell if it's interlaced?
  attr->gamma_type = ISMD_GAMMA_HDTV;   // default as per as per ISO/IEC 13818-2
  attr->repeated = 0;
  attr->y = 0;
  attr->u = attr->y + (vidpproc->system_stride * height);
  // commit the changes to the descriptor
  result = ismd_buffer_update_desc (hbuf, &desc);
  if (result != ISMD_SUCCESS) {
    ismd_buffer_dereference (hbuf);
    goto description_failed;
  }
  // map buffer physical address to a virtual address
  data_ptr = OS_MAP_IO_TO_MEM_NOCACHE (desc.phys.base,
      height_to_alloc * vidpproc->system_stride);
  if (data_ptr == NULL) {
    GST_ERROR_OBJECT (vidpproc, "virtual mapping failure");
    ismd_buffer_dereference (hbuf);
    goto mapping_failed;
  }
  // init the buffer's data properties
  (*ismd_gst_buf)->ismd_buffer_id = hbuf;
  GST_BUFFER_SIZE (*ismd_gst_buf) = height_to_alloc * vidpproc->system_stride;
  GST_BUFFER_DATA (*ismd_gst_buf) = (guint8 *) data_ptr;

beach:
  return ret;

allocation_failed:
  {
    GST_ERROR_OBJECT (vidpproc, "frame buffer allocation failed");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
description_failed:
  {
    GST_ERROR_OBJECT (vidpproc, "ismd update description failed");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
mapping_failed:
  {
    GST_ERROR_OBJECT (vidpproc, "virtual mapping failure");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
}

static GstFlowReturn
vidpproc_alloc (ISmdGstVidpproc * vidpproc, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf)
{
  GstFlowReturn ret = GST_FLOW_OK;
  GstCaps *intersection = NULL;
  GstStructure *structure = NULL;
  gint width = 0, height = 0, format = FORMAT_UNDEFINED;
  ISmdGstBuffer *ismd_gst_buf = NULL;
  guint32 fourcc;
  const GValue * par;
  gint par_x = 1, par_y = 1;

  if (G_LIKELY (vidpproc->last_caps &&
          gst_caps_is_equal (caps, vidpproc->last_caps))) {
    GST_LOG_OBJECT (vidpproc,
        "buffer alloc for same last_caps, reusing caps");
    intersection = gst_caps_ref (caps);
    format = vidpproc->last_format;
    width = vidpproc->last_width;
    height = vidpproc->last_height;
    par_x = vidpproc->last_par_x;
    par_y = vidpproc->last_par_x;
    goto reuse_last_caps;
  }

  GST_DEBUG_OBJECT (vidpproc, "buffer alloc requested size %d with caps %"
      GST_PTR_FORMAT ", intersecting with our caps %" GST_PTR_FORMAT, size,
      caps, vidpproc->caps);

  /* Check the caps against our xcontext */
  intersection = gst_caps_intersect (vidpproc->caps, caps);

  /* Ensure the returned caps are fixed */
  gst_caps_truncate (intersection);

  GST_DEBUG_OBJECT (vidpproc, "intersection in buffer alloc returned %"
      GST_PTR_FORMAT, intersection);

  if (gst_caps_is_empty (intersection)) {
    goto invalid_caps;
  } else if (gst_caps_is_equal (intersection, caps)) {
    /* Things work better if we return a buffer with the same caps ptr
     * as was asked for when we can */
    gst_caps_replace (&intersection, caps);
  }

  /* Get caps details*/
  structure = gst_caps_get_structure (intersection, 0);

  /* Get format from caps */
  if (gst_structure_has_name (structure, "video/x-decoded-ismd"))
    format = FORMAT_ISMD;
  else if (gst_structure_has_name (structure, "video/x-raw-yuv")) {
    format = FORMAT_RAW;

    par = gst_structure_get_value (structure, "pixel-aspect-ratio");
    if (par) {
      par_x = gst_value_get_fraction_numerator (par);
      par_y = gst_value_get_fraction_denominator (par);
    }
    else {
      par_x = par_y = 1;
    }

    if (!gst_structure_get_int (structure, "width", &width) ||
        !gst_structure_get_int (structure, "height", &height) ||
        !gst_structure_get_fourcc (structure, "format", &fourcc))
      goto invalid_caps;
  }
  /* Store our caps and format as the last_caps to avoid expensive
   * caps intersection next time */
  gst_caps_replace (&vidpproc->last_caps, intersection);
  vidpproc->last_format = format;
  vidpproc->last_width = width;
  vidpproc->last_height = height;
  vidpproc->last_par_x = par_x;
  vidpproc->last_par_y = par_y;

reuse_last_caps:


  if (format == FORMAT_RAW) {
    if (fourcc == GST_MAKE_FOURCC ('N', 'V', '1', '2')) {
      ismd_gst_buf = ismd_gst_buffer_new ();
      if (G_UNLIKELY (!ismd_gst_buf))
        goto allocation_failed;

      ret = vidpproc_alloc_nv12 (vidpproc, &ismd_gst_buf, width, height,
          par_x, par_y);
    }
  }
  else {
    ismd_gst_buf = ismd_gst_buffer_new ();
    if (G_UNLIKELY (!ismd_gst_buf))
      goto allocation_failed;
    /* For empty ISMD buffers just set the buffer size */
    GST_BUFFER_SIZE (ismd_gst_buf) = size;
  }

  if (ismd_gst_buf) {
    gst_buffer_set_caps (GST_BUFFER_CAST (ismd_gst_buf), intersection);
    *buf = GST_BUFFER_CAST (ismd_gst_buf);
  }
  else {
    *buf = gst_buffer_new_and_alloc (size);
    gst_buffer_set_caps (*buf, intersection);
  }

beach:
  if (intersection) {
    gst_caps_unref (intersection);
  }

  return ret;

  /* ERRORS */
allocation_failed:
  {
    GST_ERROR_OBJECT (vidpproc, "buffer allocation failed");
    ret = GST_FLOW_ERROR;
    goto beach;
  }
invalid_caps:
  {
    GST_WARNING_OBJECT (vidpproc, "invalid caps for buffer allocation %"
        GST_PTR_FORMAT, intersection);
    ret = GST_FLOW_NOT_NEGOTIATED;
    goto beach;
  }
}

#define GST_VIDEO_YV12_Y_ROWSTRIDE(width) (GST_ROUND_UP_4(width))
#define GST_VIDEO_YV12_UV_ROWSTRIDE(width) (GST_ROUND_UP_4 (GST_ROUND_UP_2 (width) / 2))

#define GST_VIDEO_YV12_Y_OFFSET(w,h) (0)
#define GST_VIDEO_YV12_U_OFFSET(w,h) (GST_VIDEO_YV12_Y_OFFSET(w,h)+(GST_VIDEO_YV12_Y_ROWSTRIDE(w)*GST_ROUND_UP_2(h)))
#define GST_VIDEO_YV12_V_OFFSET(w,h) (GST_VIDEO_YV12_U_OFFSET(w,h)+(GST_VIDEO_YV12_UV_ROWSTRIDE(w)*GST_ROUND_UP_2(h)/2))

#define GST_VIDEO_YV12_SIZE(w,h)     (GST_VIDEO_YV12_V_OFFSET(w,h)+(GST_VIDEO_YV12_V_ROWSTRIDE(w)*GST_ROUND_UP_2(h)/2))

#define CACHE_LINE_SIZE (64)
#define ROUND_UP(num, amt) ((num%amt) ? (num+amt) - (num%amt) : num)

static __inline void *
memcpy_nt (void *dest, void *src, size_t n)
{
  size_t bytes_to_move_with_prefetch;

  assert((uintptr_t)dest % CACHE_LINE_SIZE == 0);
  assert(n % CACHE_LINE_SIZE == 0);

  /* We can't prefetch the "next" cacheline when processing
   * the last cacheline, because the "next" would exceed
   * the bounds of the buffer. So, we move the first N-1
   * cache lines first, prefetching the next cache line of the
   * source for those */
  bytes_to_move_with_prefetch = n - CACHE_LINE_SIZE;
  /* *INDENT-OFF* */
#ifndef __i386__
#error This code is only for x86-32
#else
  asm(
    "movl %0, %%edi # dest base\n\t"
    "movl %1, %%esi # src base\n\t"
    "movl %2, %%ecx # bytes to move with prefetch\n\t"

    "subl $64, %%esp\n\t"
    "movdqu %%xmm0, 0(%%esp)\n\t"
    "movdqu %%xmm1, 16(%%esp)\n\t"
    "movdqu %%xmm2, 32(%%esp)\n\t"
    "movdqu %%xmm3, 48(%%esp)\n\t"

  "next:\n\t"
    "# start prefetching the next source cache line\n\t"
    "prefetchnta -64(%%esi, %%ecx, 1)\n\t"

    "# read the current cache line of the src\n\t"
    "movdqu 0(%%esi, %%ecx, 1), %%xmm0\n\t"
    "movdqu 16(%%esi, %%ecx, 1), %%xmm1\n\t"
    "movdqu 32(%%esi, %%ecx, 1), %%xmm2\n\t"
    "movdqu 48(%%esi, %%ecx, 1), %%xmm3\n\t"

    "# write it\n\t"
    "movntdq %%xmm0, 0(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm1, 16(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm2, 32(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm3, 48(%%edi, %%ecx, 1)\n\t"

    "subl $64, %%ecx\n\t"
    "jz done\n\t"

    "jmp next\n\t"

  "done:\n\t"
    "# read the last cache line of the src\n\t"
    "movdqu 0(%%esi, %%ecx, 1), %%xmm0\n\t"
    "movdqu 16(%%esi, %%ecx, 1), %%xmm1\n\t"
    "movdqu 32(%%esi, %%ecx, 1), %%xmm2\n\t"
    "movdqu 48(%%esi, %%ecx, 1), %%xmm3\n\t"

    "# write it\n\t"
    "movntdq %%xmm0, 0(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm1, 16(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm2, 32(%%edi, %%ecx, 1)\n\t"
    "movntdq %%xmm3, 48(%%edi, %%ecx, 1)\n\t"

    "sfence\n\t"

    "movdqu 0(%%esp), %%xmm0\n\t"
    "movdqu 16(%%esp), %%xmm1\n\t"
    "movdqu 32(%%esp), %%xmm2\n\t"
    "movdqu 48(%%esp), %%xmm3\n\t"
    "addl $64, %%esp\n\t"

    :
    : "g"(dest),
      "g"(src),
      "g"(bytes_to_move_with_prefetch)
    : "edi", "esi", "ecx"
  );
#endif
  /* *INDENT-ON* */

  return dest;
}

static void
uv_to_nv12 (void *dest_uv,  int dest_uv_stride, void *src_u, void *src_v,
  int src_uv_stride,
  int width, /* number of u bytes per row */
  int height)
{
  int row;
  int round_bytes_to_copy;
  uintptr_t dest_row;
  uintptr_t src_u_row;
  uintptr_t src_v_row;

  assert((uintptr_t)dest_uv % 32 == 0);
  assert(dest_uv_stride % 32 == 0);
  assert(width >= 16);

  round_bytes_to_copy = (width / 16) * 16;

  dest_row = (uintptr_t)dest_uv;
  src_u_row = (uintptr_t)src_u;
  src_v_row = (uintptr_t)src_v;

  for (row = 0; row < height; row++) {
    /* *INDENT-OFF* */
#ifndef __i386__
#error This code is only for x86-32
#else
    /* process the row */
    asm (
       "movl %0, %%edi # dest_row\n\t"
       "movl %1, %%eax # src_u_row\n\t"
       "movl %2, %%esi # src_v_row\n\t"
       "movl %3, %%ecx # round bytes to copy\n\t"
       "movl %4, %%edx # total bytes to copy\n\t"
       "pushl %%ebx\n\t"
       "movl %%esi, %%ebx\n\t"
       "movl %%ecx, %%esi\n\t"

    "next_chunk:\n\t"
       /* read the next 16 U/V bytes */
       "movdqu -16(%%eax, %%ecx, 1), %%xmm1\n\t"
       "movdqu -16(%%ebx, %%ecx, 1), %%xmm2\n\t"

       /* generate the next 16 UV pairs */
       "movdqa %%xmm1, %%xmm3\n\t"
       "movdqa %%xmm2, %%xmm4\n\t"

       "punpckhbw %%xmm2, %%xmm1\n\t"
       "punpcklbw %%xmm4, %%xmm3\n\t"

       /* store the results */
       "movntdq %%xmm1, -16(%%edi, %%ecx, 2)\n\t"
       "movntdq %%xmm3, -32(%%edi, %%ecx, 2)\n\t"

       "subl $16, %%ecx\n\t"
       "jz done_with_chunks\n\t"

       "jmp next_chunk\n\t"
    "done_with_chunks:\n\t"

       "sfence\n\t"

       /* if width == chunked_bytes, we're done */
       "cmpl %%edx, %%esi\n\t"
       "je done_uv\n\t"
       /* else, we need to handle the remaining few bytes */

       /* read the last 16 U/V bytes */
       "movdqu -16(%%eax, %%edx, 1), %%xmm1\n\t"
       "movdqu -16(%%ebx, %%edx, 1), %%xmm2\n\t"

       /* generate the last 16 UV pairs */
       "movdqa %%xmm1, %%xmm3\n\t"
       "movdqa %%xmm2, %%xmm4\n\t"

       "punpckhbw %%xmm2, %%xmm1\n\t"
       "punpcklbw %%xmm4, %%xmm3\n\t"

       /* store the results */
       "movdqu %%xmm1, -16(%%edi, %%edx, 2)\n\t"
       "movdqu %%xmm3, -32(%%edi, %%edx, 2)\n\t"
       "clflush -1(%%edi, %%edx, 2)\n\t"
       "clflush -32(%%edi, %%edx, 2)\n\t"

    "done_uv:\n\t"
       "popl %%ebx\n\t"
       :
       : "g"(dest_row),
         "g"(src_u_row),
         "g"(src_v_row),
         "g"(round_bytes_to_copy),
         "g"(width)
       : "eax", "ecx", "edx", "edi", "esi"
    );
#endif
    /* *INDENT-ON* */

    dest_row += dest_uv_stride;
    src_u_row += src_uv_stride;
    src_v_row += src_uv_stride;
  }
}

static GstBuffer *
vidpproc_yv12_to_nv12 (ISmdGstVidpproc * vidpproc, GstBuffer * in_buffer)
{
  ISmdGstBuffer *ismd_gst_buf;
  GstBuffer * out_buffer = NULL;
  GstFlowReturn ret = GST_FLOW_OK;
  guint8 *data = GST_BUFFER_DATA(in_buffer);
  gint width = vidpproc->width;
  gint height = vidpproc->height;
  gint system_stride = vidpproc->system_stride;
  gint y_stride = GST_VIDEO_YV12_Y_ROWSTRIDE (width);
  gint uv_stride = GST_VIDEO_YV12_UV_ROWSTRIDE (width);
  guint8 *out_data_y, *out_data_uv;
  gint line;

  ismd_gst_buf = ismd_gst_buffer_new ();
  if (G_UNLIKELY (!ismd_gst_buf))
    goto beach;

  ret = vidpproc_alloc_nv12 (vidpproc, &ismd_gst_buf, width, height,
      vidpproc->aspect_x, vidpproc->aspect_y);
  if (ret != GST_FLOW_OK)
    goto beach;

  out_buffer = GST_BUFFER_CAST (ismd_gst_buf);

  GST_BUFFER_TIMESTAMP (out_buffer) = GST_BUFFER_TIMESTAMP (in_buffer);
  GST_BUFFER_DURATION (out_buffer) = GST_BUFFER_DURATION (in_buffer);
  GST_BUFFER_FLAGS (out_buffer) = GST_BUFFER_FLAGS (in_buffer);
  out_data_y = GST_BUFFER_DATA(out_buffer);
  out_data_uv = out_data_y + (height * system_stride);

  /* copy Y data */
  for (line = 0; line < height; line++) {
    /* Potentially copying some extra bytes (up to 63), this is OK because
     * SRC buffer has U and V  after Y, so we won't overrun it
     * DEST buffer locally allocated to have a width of system stride */
    memcpy_nt (out_data_y + (line*system_stride), data + (line*y_stride),
        ROUND_UP (y_stride, CACHE_LINE_SIZE));
  }

  /* This assumes data in buffer is packed YV12 (stride == width) */
  if (vidpproc->is_i420) {
    uv_to_nv12 (out_data_uv, system_stride,
        data + GST_VIDEO_YV12_U_OFFSET(width, height),
        data + GST_VIDEO_YV12_V_OFFSET(width, height),
        uv_stride, uv_stride, height/2);
  } else {
    uv_to_nv12 (out_data_uv, system_stride,
        data + GST_VIDEO_YV12_V_OFFSET(width, height),
        data + GST_VIDEO_YV12_U_OFFSET(width, height),
        uv_stride, uv_stride, height/2);
  }


beach:
  gst_buffer_unref (in_buffer);
  return out_buffer;
}

static GstBuffer *
ismd_gst_vidpproc_convert (ISmdGstElement * smd_element, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (smd_element);
  GstBuffer *outbuf = buf;
  GstClockTime pts, duration;
  gint64 clip_start, clip_stop;
  gboolean in_seg;

  if (G_UNLIKELY(!vidpproc->has_newsegment)) {
    GST_LOG_OBJECT (vidpproc, "dropping buffer due missing new segment");
    gst_buffer_unref (buf);
    outbuf = NULL;
    goto beach;
  }

  pts = GST_BUFFER_TIMESTAMP (buf);
  duration = GST_BUFFER_DURATION (buf);
  if (GST_CLOCK_TIME_IS_VALID (pts)) {
    GST_LOG_OBJECT (vidpproc, "check for clipping on buffer %p with pts %" \
        GST_TIME_FORMAT " and duration %" GST_TIME_FORMAT,
        buf, GST_TIME_ARGS (pts), GST_TIME_ARGS (duration));

    clip_start = clip_stop = pts;
    if (GST_CLOCK_TIME_IS_VALID (duration))
      clip_stop += duration;

    /* Check if this buffer's timestamp/duration is in our segment */
    in_seg = gst_segment_clip (&smd_element->segment, GST_FORMAT_TIME,
        clip_start, clip_stop, &clip_start, &clip_stop);

    if (G_UNLIKELY (!in_seg)) {
      GST_LOG_OBJECT (vidpproc, "dropping buffer due to temporal clipping");
      gst_buffer_unref (buf);
      outbuf = NULL;
    }
  }

  if (outbuf && (vidpproc->is_yv12 || vidpproc->is_i420)) {
    outbuf = vidpproc_yv12_to_nv12 (vidpproc, outbuf);
  }

beach:
  return outbuf;
}

static gboolean
ismd_gst_vidpproc_event (ISmdGstElement * smd_element, GstEvent * event)
{
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (smd_element);

  switch (event->type) {
    case GST_EVENT_NEWSEGMENT:
      {
        gboolean update;
        gst_event_parse_new_segment (event, &update, NULL, NULL, NULL,
            NULL, NULL);
        if (!update) {
          vidpproc->has_newsegment = TRUE;
        }
      }
      break;
    case GST_EVENT_FLUSH_STOP:
      {
        vidpproc->has_newsegment = FALSE;
      }
      break;
    default:
      break;
  }
  return TRUE;
}

static GstFlowReturn
ismd_gst_vidpproc_alloc (GstPad * pad, guint64 offset, guint size,
    GstCaps * caps, GstBuffer ** buf)
{
  GstFlowReturn ret = GST_FLOW_OK;
  ISmdGstVidpproc *vidpproc;

  vidpproc = ISMD_GST_VIDPPROC (gst_pad_get_parent_element (pad));

  ret = vidpproc_alloc (vidpproc, offset, size, caps, buf);

  gst_object_unref (vidpproc);

  return ret;
}

static void
ismd_gst_vidpproc_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (object);

  switch (prop_id) {
    case PROP_VIDPPROC_SCALE_MODE:
      g_value_set_enum (value, vidpproc->scale_mode);
      break;
    case PROP_VIDPPROC_RECTANGLE:
      g_value_transform (&vidpproc->rectangle, value);
      break;
    case PROP_VIDPPROC_PAN_AND_SCAN:
      g_value_set_boolean (value, vidpproc->pan_and_scan_enabled);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_vidpproc_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstElement *smde = ISMD_GST_ELEMENT (object);
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (object);

  switch (prop_id) {
    case PROP_VIDPPROC_SCALE_MODE:
    {
      vidpproc->scale_mode = g_value_get_enum (value);
      if (vidpproc->setup) {
        ismd_result_t res;
        res = ismd_vidpproc_set_scaling_policy (smde->dev_handle,
            vidpproc->scale_mode);
        if (G_UNLIKELY (res != ISMD_SUCCESS)) {
          GST_WARNING_OBJECT (vidpproc, "set_scaling_policy failed");
        }
      }
      break;
    }
    case PROP_VIDPPROC_RECTANGLE:
      GST_OBJECT_LOCK (vidpproc);

      if (!g_value_transform (value, &vidpproc->rectangle)) {
        g_warning ("Could not transform string to rectangle");
        gst_value_set_rectangle (&vidpproc->rectangle, 0, 0, 0, 0);
      }
      GST_DEBUG_OBJECT (vidpproc, "set destination rectangle to %d,%d,%d,%d",
          gst_value_get_rectangle_x (&vidpproc->rectangle),
          gst_value_get_rectangle_y (&vidpproc->rectangle),
          gst_value_get_rectangle_width (&vidpproc->rectangle),
          gst_value_get_rectangle_height (&vidpproc->rectangle));
      if (vidpproc->setup)
        update_dest_rect (ISMD_GST_ELEMENT (vidpproc));
      GST_OBJECT_UNLOCK (vidpproc);
      break;
    case PROP_VIDPPROC_PAN_AND_SCAN:
    {
      vidpproc->pan_and_scan_enabled = g_value_get_boolean (value);
      if (vidpproc->setup) {
        ismd_result_t res;
        res = vidpproc->pan_and_scan_enabled ?
            ismd_vidpproc_pan_scan_enable (smde->dev_handle) :
            ismd_vidpproc_pan_scan_disable (smde->dev_handle);
        if (G_UNLIKELY (res != ISMD_SUCCESS)) {
          GST_WARNING_OBJECT (vidpproc, "pan_scan_enable/disable failed");
        }
      }
      break;
    }

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_vidpproc_finalize (GObject * object)
{
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (object);

  g_value_unset (&vidpproc->rectangle);

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static inline gboolean
ismd_open (GstElement * element)
{
  ISmdGstElement *parent = ISMD_GST_ELEMENT (element);
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (element);

  ismd_result_t result;
  GList *padlist;
  ISmdGstPad *gstpad;
  // initialize the device but don't consume data
  result = ismd_vidpproc_open (&(parent->dev_handle));
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (vidpproc, "open failed <%d>", result);
    goto failure;
  }

  result =
      ismd_vidpproc_get_input_port (parent->dev_handle,
      &(parent->sink_pad->ismd_port));
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (vidpproc, "get input port failed <%d>", result);
    goto failure;
  }

  padlist = parent->src_pads;
  gstpad = ISMD_GST_PAD (padlist->data);
  ismd_vidpproc_get_output_port (parent->dev_handle, &gstpad->ismd_port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (vidpproc, "get output port failed <%d>", result);
    goto failure;
  }
  return TRUE;

failure:
  return FALSE;
}

static inline gboolean
ismd_get_tvmode_size (ISmdGstVidpproc * vidpproc)
{
  gboolean ret = FALSE;
  gdl_display_info_t di;
  memset (&di, 0, sizeof (di));

  if (gdl_init (0) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (vidpproc, "gdl_init failed");
    goto beach;
  }

  /* Read current hardware state */
  if (gdl_get_display_info (GDL_DISPLAY_ID_0, &di) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (vidpproc, "gdl_get_display_info failed");
    goto error;
  }

  GST_DEBUG_OBJECT (vidpproc, "got width %d and height %d from display",
    di.tvmode.width, di.tvmode.height);
  vidpproc->tv_width = di.tvmode.width;
  vidpproc->tv_height = di.tvmode.height;
  vidpproc->interlaced = (di.tvmode.interlaced == GDL_TRUE);

  ret = TRUE;
  gdl_close ();

beach:
  return ret;
error:
  gdl_close ();
  return FALSE;
}

static GstStateChangeReturn
ismd_gst_vidpproc_change_state (GstElement * element, GstStateChange transition)
{
  ISmdGstElement *smdelement = ISMD_GST_ELEMENT (element);
  ISmdGstVidpproc *vidpproc = ISMD_GST_VIDPPROC (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ismd_result_t ismd_ret;
  ismd_vidpproc_deinterlace_policy_t deinterlacing_policy = NONE;

  GST_DEBUG_OBJECT (element, "devh:%d change state from %s to %s (%04x)",
      smdelement->dev_handle, gst_element_state_get_name ((GstState)
          GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)),
      transition);

  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
      if (!ismd_open (element))
        goto failure;

      /* Try to get tvmode size */
      if (!ismd_get_tvmode_size (vidpproc)) {
        GST_ERROR_OBJECT (vidpproc, "couldn't get the screen size");
        goto failure;
      }

      /* Setup the vidpproc settings */
      if (vidpproc->interlaced) {
        deinterlacing_policy = NONE;
      } else {
        deinterlacing_policy = AUTO;
      }

      /* Setup the vidpproc settings */
      if (ISMD_SUCCESS !=
          ismd_vidpproc_set_deinterlace_policy (smdelement->dev_handle, deinterlacing_policy)) {
        GST_ERROR_OBJECT (vidpproc, "ismd_vidpproc_set_deinterlace_policy");
        goto failure;
      }
      GST_OBJECT_LOCK (vidpproc);
      if (!(vidpproc->setup = update_dest_rect (smdelement))) {
        goto failure;
      }
      GST_OBJECT_UNLOCK (vidpproc);
      if (ISMD_SUCCESS != ismd_vidpproc_set_scaling_policy (smdelement->dev_handle,
              vidpproc->scale_mode)) {
        GST_ERROR_OBJECT (vidpproc, "ismd_vidpproc_set_scaling_policy failed");
        goto failure;
      }
      ismd_ret = vidpproc->pan_and_scan_enabled ?
          ismd_vidpproc_pan_scan_enable (smdelement->dev_handle) :
          ismd_vidpproc_pan_scan_disable (smdelement->dev_handle);
      if (ismd_ret != ISMD_SUCCESS)  {
        GST_ERROR_OBJECT (vidpproc, "ismd_vidpproc_pan_scan_enable/disable failed");
        goto failure;
      }
      vidpproc->caps = gst_caps_copy (
          gst_pad_get_pad_template_caps (ISMD_ELEMENT_SINK_PAD(smdelement)));

      vidpproc->system_stride = SYSTEM_STRIDE;
      break;

    case GST_STATE_CHANGE_READY_TO_PAUSED:
      vidpproc->has_newsegment = FALSE;
      break;

    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
      break;

    default:
      break;
  }

  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
      break;

    case GST_STATE_CHANGE_PAUSED_TO_READY:
      vidpproc->width = vidpproc->height = 0;
      vidpproc->is_yv12 = FALSE;
      vidpproc->is_i420 = FALSE;
      break;

    case GST_STATE_CHANGE_READY_TO_NULL:
      if (vidpproc->last_caps)
        gst_caps_replace (&vidpproc->last_caps, NULL);
      if (vidpproc->caps)
        gst_caps_unref (vidpproc->caps);

        ISmdGstElement *parent = ISMD_GST_ELEMENT (element);
        ismd_result_t result;
        result = ismd_dev_close ((parent->dev_handle));
        parent->dev_handle = 0;
      break;

    default:
      break;
  }

  return ret;

failure:
  return GST_STATE_CHANGE_FAILURE;
}

static void
ismd_gst_vidpproc_base_init (gpointer klass)
{
  static GstElementDetails details = {
    "Intel Streaming Media Driver (ISMD) Hardware Video Post-Processor",
    "Filter/Effect/Video",
    "GStreamer Post-Processing Element for Intel Media Processors",
    "http://www.intelconsumerelectronics.com/"
  };

  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GstPadTemplate *curr_tmplt = NULL;
  gst_element_class_set_details (eclass, &details);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_vidpproc_sinkpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);

  curr_tmplt = gst_static_pad_template_get (&ismd_gst_vidpproc_srcpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);
}

static void
ismd_gst_vidpproc_class_init (ISmdGstVidpprocClass * klass)
{
  GObjectClass *oclass;
  oclass = G_OBJECT_CLASS (klass);
  GstElementClass *eclass;
  eclass = GST_ELEMENT_CLASS (klass);
  ISmdGstElementClass *iclass;
  iclass = ISMD_GST_ELEMENT_CLASS (klass);

  oclass->get_property = ismd_gst_vidpproc_get_property;
  oclass->set_property = ismd_gst_vidpproc_set_property;

  g_object_class_install_property (oclass, PROP_VIDPPROC_SCALE_MODE,
      g_param_spec_enum ("scale-mode",
          "Scale mode",
          "Define the mode used by the video scaler",
          GST_TYPE_ISMD_VIDPPROC_SCALE_MODE,
          DEFAULT_ISMD_VIDPPROC_SCALE_MODE, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_VIDPPROC_RECTANGLE,
      g_param_spec_string ("rectangle", "Destination rectangle",
          "The destination rectangle, (0,0,0,0) full screen",
          DEFAULT_ISMD_VIDPPROC_RECTANGLE,
          G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_property (oclass, PROP_VIDPPROC_PAN_AND_SCAN,
      g_param_spec_boolean ("pan-and-scan",
          "Pan and Scan",
          "Enable usage of Pan and Scan information if present in the stream",
          DEFAULT_ISMD_VIDPPROC_PAN_AND_SCAN, G_PARAM_READWRITE));

  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_vidpproc_finalize);
  iclass->convert = GST_DEBUG_FUNCPTR (ismd_gst_vidpproc_convert);
  iclass->event = GST_DEBUG_FUNCPTR (ismd_gst_vidpproc_event);
  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_vidpproc_change_state);
}

static void
ismd_gst_vidpproc_init (ISmdGstVidpproc * vidpproc,
    ISmdGstVidpprocClass * klass)
{
  GstPad *pad;

  ismd_gst_element_create_pads (ISMD_GST_ELEMENT (vidpproc), &sinkcap,
      &srccap, 1);

  pad = gst_element_get_static_pad (GST_ELEMENT (vidpproc), "sink");
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vidpproc_setcaps));
  gst_pad_set_bufferalloc_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vidpproc_alloc));

  gst_object_unref (pad);
  vidpproc->scale_mode = DEFAULT_ISMD_VIDPPROC_SCALE_MODE;
  vidpproc->pan_and_scan_enabled = DEFAULT_ISMD_VIDPPROC_PAN_AND_SCAN;
  vidpproc->aspect_x = vidpproc->aspect_y = 1;
  g_value_init (&vidpproc->rectangle, GST_TYPE_RECTANGLE);
  gst_value_set_rectangle (&vidpproc->rectangle, 0, 0, 0, 0);
  vidpproc->setup = FALSE;
  vidpproc->width = vidpproc->height = 0;
  vidpproc->interlaced = FALSE;
  vidpproc->is_yv12 = FALSE;
  vidpproc->is_i420 = FALSE;
}
