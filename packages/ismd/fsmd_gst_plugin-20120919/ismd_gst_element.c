/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright (c) 2012. Intel Corporation. All rights reserved.
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

#include "platform_config_paths.h"
#include "platform_config.h"
#include "ismd_gst_element.h"
#include "ismd_core_protected.h"
#include "pal.h"
#include "x86_cache.h"
#include "ismd_audio_defs.h"


/*
* Shortcut macros for accessing core platform configuration properties
*/

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

#ifndef SYSTEM_STRIDE
#define SYSTEM_STRIDE ISMD_CORE_INT_PROPERTY("frame_buffer_properties.stride")
#endif

#define PTS_DISPLAY FALSE

#define SMD_MAX_VIDEO_WIDTH   1920
#define SMD_MAX_VIDEO_HEIGHT  1088

#define CHECK_RESULT() \
	if (result != ISMD_SUCCESS) { \
		printf("error: %d", result); \
		return GST_FLOW_ERROR; \
	} do {} while (0)

#define USE_OPTIMIZED_MEMCPY 1

GST_DEBUG_CATEGORY_STATIC (ismd_gst_element_debug);
#define GST_CAT_DEFAULT ismd_gst_element_debug

enum
{
  UNKNOWN,
  PROP_USE_BUFFERING,
  PROP_STREAM_TIME_OFFSET
};

#define DEFAULT_USE_BUFFERING       TRUE
#define DEFAULT_STREAM_TIME_OFFSET  0 /*100 * GST_MSECOND*/

#define ADAPTER_GET_LOCK(elem)    (elem->adapter_lock)
#define ADAPTER_LOCK(elem)        (g_static_rec_mutex_lock(ADAPTER_GET_LOCK(elem)))
#define ADAPTER_LOCK_FULL(elem,t) (g_static_rec_mutex_lock_full(ADAPTER_GET_LOCK(elem), t))
#define ADAPTER_TRYLOCK(elem)     (g_static_rec_mutex_trylock(ADAPTER_GET_LOCK(elem)))
#define ADAPTER_UNLOCK(elem)      (g_static_rec_mutex_unlock(ADAPTER_GET_LOCK(elem)))

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_element_debug, "ISMD_ELEMENT",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ISMD BASE ELEMENT");
}

GST_BOILERPLATE_FULL (ISmdGstElement, ismd_gst_element, GstElement,
    GST_TYPE_ELEMENT, _do_init);

static void ismd_gst_element_base_init (gpointer klass);
static void ismd_gst_element_class_init (ISmdGstElementClass * klass);
static void ismd_gst_element_init (ISmdGstElement * smd_element,
    ISmdGstElementClass * klass);
static void ismd_gst_element_finalize (GObject * object);
static GstStateChangeReturn ismd_gst_element_change_state (GstElement * element,
    GstStateChange transition);
static void ismd_gst_element_event_loop (ISmdGstElement * smd_element);
static gboolean ismd_gst_element_set_clock (GstElement * element,
    GstClock * clock);
static GstPadLinkReturn ismd_src_link_function (GstPad * pad, GstPad * peer);
static void ismd_unlink_function (GstPad * gstpad);

static GstFlowReturn ismd_gst_element_sink_chain (GstPad * pad,
    GstBuffer * buf);
static gboolean ismd_gst_element_sink_event (GstPad * pad, GstEvent * event);

static gboolean ismd_gst_element_commit_state (ISmdGstElement * smd_element);

static gboolean ismd_gst_element_sink_port_write (ISmdGstElement * smd_element,
    GstPad * pad, ismd_buffer_handle_t buf_handle);

static ISmdGstElementSinkPad * ismd_gst_element_get_sink_pad_nodedata(ISmdGstElement * smd_element, ISmdGstPad * pad);
static inline void ismd_gst_element_reset_flow (ISmdGstElement * smd_element);

static void ismd_gst_mass_unregister_sinkpad_shim(gpointer padp, gpointer ele);
static void ismd_gst_mass_unregister_srcpad_shim(gpointer padp, gpointer ele);

static void inline
ismd_gst_pad_port_stats (ISmdGstPad * pad)
{
  ismd_port_status_t status;
  ismd_result_t result;

  result = ismd_port_get_status (pad->ismd_port, &status);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (pad, "ismd_port_get_status failed(%d)",
        result);
  } else {
    GST_DEBUG_OBJECT (pad, "port=%d MD=%d CD=%d WM=%d",
        pad->ismd_port, status.max_depth, status.cur_depth, status.watermark);
  }
}

#define CACHE_LINE_SIZE (64)
#define ROUND_UP(num, amt) ((num%amt) ? (num+amt) - (num%amt) : num)

/* width = number of u bytes per row */
static __inline void
unpack_uv (void *dest_u, void *dest_v, int dest_u_stride, int dest_v_stride,
    void *src_uv, int src_uv_stride, int width, int height)
{
  int row;
  int round_bytes_to_copy;
  uintptr_t src_row;
  uintptr_t dest_u_row;
  uintptr_t dest_v_row;

  assert ((uintptr_t) src_uv % 32 == 0);
  assert (src_uv_stride % 32 == 0);
  assert (dest_u_stride == dest_v_stride);
  assert (width >= 16);

  round_bytes_to_copy = (width / 16) * 16;

  src_row = (uintptr_t) src_uv;
  dest_u_row = (uintptr_t) dest_u;
  dest_v_row = (uintptr_t) dest_v;

  for (row = 0; row < height; row++) {
    /* process the row */
    /* *INDENT-OFF* */
#ifndef __i386__
#error This code is only for x86-32
#else
    asm (
        "movl %0, %%edi # src_row\n\t"
        "movl %1, %%eax # dest_u_row\n\t"
        "movl %2, %%ebx # dest_v_row\n\t"
        "movl %3, %%ecx # round bytes to copy\n\t"
        "movl %4, %%edx # total bytes to copy\n\t"
        "movl %%ecx, %%esi\n\t" "next_chunk:\n\t"
        /* read the next 16 packed U/V pairs */
        "movdqa -16(%%edi, %%ecx, 2), %%xmm0\n\t"
        "movdqa -32(%%edi, %%ecx, 2), %%xmm2\n\t"
        /* we'll use the EVEN regs for processing U's...
           copy the original values to ODD regs for handling V's. */
        "movdqa %%xmm0, %%xmm1\n\t"
        "movdqa %%xmm2, %%xmm3\n\t"
        /* shift back and forth to clear the U data from the V regs
         */
        "psllw $8, %%xmm1\n\t"
        "psrlw $8, %%xmm1\n\t"
        "psllw $8, %%xmm3\n\t"
        "psrlw $8, %%xmm3\n\t"
        /* shift right to clear the V data from the U regs */
        "psrlw $8, %%xmm0\n\t"
        "psrlw $8, %%xmm2\n\t"
        /* pack the data */
        "packuswb %%xmm0, %%xmm2\n\t"
        "packuswb %%xmm1, %%xmm3\n\t"
        /* store the results */
        "movdqu %%xmm3, -16(%%eax, %%ecx, 1)\n\t"
        "movdqu %%xmm2, -16(%%ebx, %%ecx, 1)\n\t"
        "subl $16, %%ecx\n\t"
        "jz done_with_chunks\n\t"
        "jmp next_chunk\n\t"
        "done_with_chunks:\n\t"
        "sfence\n\t"
        /* if width == chunked_bytes, we're done */
        "cmpl %%edx, %%esi\n\t" "je now_done\n\t"
        /* else, we need to handle the remaining few bytes */
        "movdqu -16(%%edi, %%edx, 2), %%xmm0\n\t"
        "movdqu -32(%%edi, %%edx, 2), %%xmm2\n\t"
        /* we'll use the EVEN regs for processing U's...
           copy the original values to ODD regs for handling V's.  */
        "movdqa %%xmm0, %%xmm1\n\t"
        "movdqa %%xmm2, %%xmm3\n\t"
        /* shift back and forth to clear the U data from the V regs */
        "psllw $8, %%xmm1\n\t"
        "psrlw $8, %%xmm1\n\t"
        "psllw $8, %%xmm3\n\t"
        "psrlw $8, %%xmm3\n\t"
        /* shift right to clear the V data from the U regs */
        "psrlw $8, %%xmm0\n\t"
        "psrlw $8, %%xmm2\n\t"
        /* pack the data */
        "packuswb %%xmm0, %%xmm2\n\t"
        "packuswb %%xmm1, %%xmm3\n\t"
        /* store the results */
        "movdqu %%xmm3, -16(%%eax, %%edx, 1)\n\t"
        "movdqu %%xmm2, -16(%%ebx, %%edx, 1)\n\t"
        "now_done:\n\t":
   :    "g" (src_row),
        "g" (dest_u_row),
        "g" (dest_v_row), "g" (round_bytes_to_copy), "g" (width)
   :    "eax", "ebx", "ecx", "edx", "edi", "esi");
#endif
    /* *INDENT-ON* */

    src_row += src_uv_stride;
    dest_u_row += dest_u_stride;
    dest_v_row += dest_v_stride;
  }
}


static __inline void *
memcpy_nt (void *dest, void *src, size_t n)
{
  size_t bytes_to_move_with_prefetch;

  assert ((uintptr_t) dest % CACHE_LINE_SIZE == 0);
  assert (n % CACHE_LINE_SIZE == 0);

  /* We can't prefetch the "next" cacheline when processing
     the last cacheline, because the "next" would exceed
     the bounds of the buffer. So, we move the first N-1
     cache lines first, prefetching the next cache line of the
     source for those */
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

  "1:\n\t"
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
    "jz 2f\n\t"

    "jmp 1b\n\t"

  "2:\n\t"
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
  /* *INDENT-OFF* */

  return dest;
}
static inline void
adapter_nodedata_reset ( ISmdGstElementSinkPad *pad_node_data)
{ 
    if (pad_node_data->adapter){
        gst_adapter_clear(pad_node_data->adapter);
    }
    pad_node_data->head_ts = GST_CLOCK_TIME_NONE;
    pad_node_data->next_ts = GST_CLOCK_TIME_NONE;
    pad_node_data->bit_rate = ISMD_INVALID_BIT_RATE;
}

static inline void
adapter_reset (ISmdGstElement * smd_element, ISmdGstElementSinkPad *pad_node_data)
{
    ADAPTER_LOCK(pad_node_data);
    adapter_nodedata_reset(pad_node_data);
    ADAPTER_UNLOCK (pad_node_data);
    GST_LOG_OBJECT (smd_element, "adapter reset");
}

static inline void
adapter_all_reset (ISmdGstElement * smd_element)
{ 
    GList *node = NULL;
    ISmdGstElementSinkPad *pad_node_data = NULL; 
    node = smd_element->sink_pads;
    while(node != NULL){
        pad_node_data = node->data;
        node = node->next;
        adapter_reset(smd_element, pad_node_data);
    }
}

static inline void
adapter_set_head (ISmdGstElement * smd_element, ISmdGstElementSinkPad* pad_node_data, GstBuffer * buf)
{
    gboolean is_flushing;

    GST_OBJECT_LOCK (smd_element);
    is_flushing = smd_element->is_flushing;
    GST_OBJECT_UNLOCK (smd_element);

    if (is_flushing) {
        GST_LOG_OBJECT (smd_element, "flushing");
        gst_buffer_unref (buf);
        return;
    }

    ADAPTER_LOCK (pad_node_data);

    GST_LOG_OBJECT (smd_element, "pushing head of %u bytes into the adapter",
            GST_BUFFER_SIZE (buf));

    pad_node_data->discont = GST_BUFFER_FLAG_IS_SET (buf, GST_BUFFER_FLAG_DISCONT);
    pad_node_data->head_ts = GST_BUFFER_TIMESTAMP (buf);
    pad_node_data->next_ts = pad_node_data->head_ts;

    if ((pad_node_data->head_ts != GST_CLOCK_TIME_NONE) && buf->_gst_reserved[0])
      pad_node_data->bit_rate = (guint)(buf->_gst_reserved[0]);
    
    if (G_LIKELY (GST_CLOCK_TIME_IS_VALID (GST_BUFFER_DURATION (buf))))
        pad_node_data->next_ts += GST_BUFFER_DURATION (buf);

    gst_adapter_push (pad_node_data->adapter, buf);
    ADAPTER_UNLOCK (pad_node_data);
}

static inline void
adapter_push (ISmdGstElement * smd_element, ISmdGstElementSinkPad* pad_node_data, GstBuffer * buf)
{
  gboolean is_flushing;

  GST_OBJECT_LOCK (smd_element);
  is_flushing = smd_element->is_flushing;
  GST_OBJECT_UNLOCK (smd_element);
  
  if (is_flushing) {

    GST_LOG_OBJECT (smd_element, "flushing");
    gst_buffer_unref (buf);
    return;
  }

  ADAPTER_LOCK (pad_node_data);

  GST_LOG_OBJECT (smd_element, "pushing %u bytes into the adapter",
      GST_BUFFER_SIZE (buf));
  if (G_LIKELY (GST_CLOCK_TIME_IS_VALID (GST_BUFFER_DURATION (buf))))
    pad_node_data->next_ts += GST_BUFFER_DURATION (buf);
  gst_adapter_push (pad_node_data->adapter, buf);

  ADAPTER_UNLOCK (pad_node_data);
}

static inline ismd_result_t
adapter_drain (ISmdGstElement * smd_element, ISmdGstElementSinkPad* pad_node_data)
{
  ismd_result_t result = ISMD_SUCCESS;
  ismd_buffer_handle_t hbuf;
  ismd_buffer_descriptor_t desc;
  guint8 *dataptr;
  ismd_es_buf_attr_t *attr;
  audio_buffer_attr_t *attr_audio;
  guint avail;
  GstPad *pad = GST_PAD (pad_node_data->sink_pad);
  GstClockTime pts = GST_CLOCK_TIME_NONE;
  gboolean discont = FALSE;
  gboolean written;
  guint bitrate = ISMD_INVALID_BIT_RATE;
  ISmdGstElementClass *klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  pts = pad_node_data->head_ts;
  discont = pad_node_data->discont;
  bitrate = pad_node_data->bit_rate;

  ADAPTER_LOCK (pad_node_data);
  while ((avail = gst_adapter_available (pad_node_data->adapter))) {
    guint size = MIN (avail, ISMD_BUFFER_SIZE);
    GST_LOG_OBJECT (smd_element, "draining %u/%u bytes from the adapter",
        size, avail);

    result = ismd_buffer_alloc (ISMD_BUFFER_SIZE, &hbuf);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "cannot allocate an SMD buffer!");
      goto beach;
    }
    result = ismd_buffer_read_desc (hbuf, &desc);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "read buffer descriptor failed!");
      goto beach;
    }

    /* For mux audio port, cast buffer attribute to audio_buffer_attr_t */    
    if(klass->is_ts_muxer && strstr(gst_pad_get_name(pad), "audio"))    
    {      
      attr_audio = (audio_buffer_attr_t *) desc.attributes;   
      /* Add initialization not 0 but -1*/
      attr_audio->local_pts = ISMD_NO_PTS;
      attr_audio->linear_pts = ISMD_NO_PTS;
      attr_audio->original_pts = ISMD_NO_PTS;
      attr_audio->bitrate = ISMD_INVALID_BIT_RATE;   
      /* ISMD audio sink discards buffers with pts = 0, to avoid this
       * we convert a 0 ticks pts into 1 tick pts. */
      GST_LOG_OBJECT (smd_element, "created a buffer with pts %" GST_TIME_FORMAT,
      GST_TIME_ARGS (pts));
      attr_audio->local_pts = MAX (1, GST_TO_SMD_TIME (pts));  
      attr_audio->bitrate = bitrate;
      attr_audio->discontinuity = discont;
    } else {
      attr = (ismd_es_buf_attr_t *) desc.attributes;
      /* Add initialization not 0 but -1*/
      attr->original_pts = ISMD_NO_PTS;
      attr->original_dts = ISMD_NO_DTS;
      attr->original_ats = ISMD_NO_ATS;
      attr->bit_rate = ISMD_INVALID_BIT_RATE;	
      /* ISMD audio sink discards buffers with pts = 0, to avoid this
       * we convert a 0 ticks pts into 1 tick pts. */
      GST_LOG_OBJECT (smd_element, "created a buffer with pts %" GST_TIME_FORMAT,
          GST_TIME_ARGS (pts));
      attr->local_pts = MAX (1, GST_TO_SMD_TIME (pts));
      attr->original_pts = attr->local_pts;
      attr->bit_rate = bitrate;
      attr->discontinuity = discont;
    }

    /* Only the head chunk have timming info, here reset for next ones */
    pts = GST_CLOCK_TIME_NONE;
    discont = FALSE;

    /* now copy the data to the new smd buffer */
    dataptr = OS_MAP_IO_TO_MEM_CACHE (desc.phys.base, size);
    gst_adapter_copy (pad_node_data->adapter, dataptr, 0, size);
    gst_adapter_flush (pad_node_data->adapter, size);
    cache_flush_buffer (dataptr, size);
    OS_UNMAP_IO_FROM_MEM (dataptr, size);

    desc.phys.level = size;
    result = ismd_buffer_update_desc (hbuf, &desc);
    if (result != ISMD_SUCCESS) {
      /* FIXME: handle this properly */
      GST_ERROR_OBJECT (smd_element, "failed to update ISMD descriptor!");
    }

    /* try to write the buffer to the port.
     * if FALSE is returned, the write was aborted
     */
    ADAPTER_UNLOCK (pad_node_data);
    written = ismd_gst_element_sink_port_write (smd_element, pad, hbuf);
    ADAPTER_LOCK (pad_node_data);
    if (!written) {
      ismd_buffer_dereference (hbuf);
      result = ISMD_ERROR_TIMEOUT;
      goto beach;
    }
  }

beach:
  ADAPTER_UNLOCK (pad_node_data);
  adapter_reset (smd_element, pad_node_data);
  return result;
}

/* This function attempts to connect an SMD port on the source side
 * to a GST soft element on the sink side.  It attaches a port
 * event to the SMD src (output) port so that we can get notified
 * when data is about to be shipped out.
 */
static inline ismd_result_t
ismd_connect_gst_pads (ISmdGstPad * pad, GstPad * peer)
{
  ISmdGstElement *smd_element = NULL;
  ismd_result_t result = ISMD_ERROR_UNSPECIFIED;

  GST_DEBUG_OBJECT (pad, "ismd_connect_gst_pads will try to connect with %"
      GST_PTR_FORMAT, peer);

  smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent (GST_PAD (pad)));

  if (!smd_element)
    goto beach;

  if (pad->is_event_queue_attached)
    goto beach;

  result =
      ismd_port_attach (pad->ismd_port, smd_element->src_pad_event,
      ISMD_QUEUE_EVENT_ALWAYS, ISMD_QUEUE_WATERMARK_NONE);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (pad, "failure registering QUEUE EVENT to output port %d",
        pad->ismd_port);
  } else {
    GST_DEBUG_OBJECT (pad, "QUEUE EVENT attached to output port %d",
        pad->ismd_port);
    pad->is_event_queue_attached = TRUE;
  }

  /* call the sink pad's link function if there is one */
  if (GST_PAD_LINKFUNC (peer)
          && GST_PAD_LINKFUNC (peer) (peer, GST_PAD (pad)) != GST_PAD_LINK_OK) {
      GST_ERROR_OBJECT (pad, "sink pad's link function failed");
      result = ISMD_ERROR_UNSPECIFIED;
      ismd_unlink_function (GST_PAD (pad));
  }

beach:
  if (smd_element)
    gst_object_unref (smd_element);

  return result;
}

static inline void
connect_pads (ISmdGstElement * smd_element)
{
  GList *index = NULL;
  ismd_result_t result;
  GstPad *pad;

  g_mutex_lock (smd_element->pad_list_mutex);
  if (g_list_length (smd_element->src_pads) > 0) {
    index = smd_element->src_pads;
    while (index != NULL) {
      pad = GST_PAD (index->data);
      GST_DEBUG_OBJECT (pad, "connecting pad");
      /* Now try to perform the output pad setup */
      ismd_setup_output_pad (index->data);

      if (gst_pad_is_linked (pad)) {
        GstPad *peer = gst_pad_get_peer (pad);

        /*
         * Add to list of pads to check for output
         */
        GST_DEBUG_OBJECT (pad, "detected a soft GST pad linked to %"
            GST_PTR_FORMAT, peer);

        result = ismd_connect_gst_pads (index->data, peer);

        if (peer)
          gst_object_unref (peer);
      } else {
        /*
         * No link to another pad
         */
        GST_WARNING_OBJECT (pad, "with port %d is not linked",
            ISMD_GST_PAD (index->data)->ismd_port);
      }
      index = g_list_next (index);
    }
  }
  g_mutex_unlock (smd_element->pad_list_mutex);
}

static inline void
disconnect_pads (ISmdGstElement * smd_element)
{
  GList *index = NULL;
  g_mutex_lock (smd_element->pad_list_mutex);

  if (g_list_length (smd_element->src_pads) > 0) {
    index = smd_element->src_pads;
    while (index != NULL) {
      if (gst_pad_is_linked (GST_PAD (index->data))) {
        ismd_unlink_function (GST_PAD (index->data));
      }
      index = g_list_next (index);
    }
  }
  g_mutex_unlock (smd_element->pad_list_mutex);
}

static gboolean is_port_empty (ISmdGstElement * smd_element, ismd_port_handle_t port)
{
  ismd_result_t result;
  ismd_port_status_t port_status;
  result = ismd_port_get_status (port, &port_status);
  return ((port_status.cur_depth == 0) || (smd_element->is_flushing));
}

static void
ismd_gst_element_drain (ISmdGstElement * smd_element, ISmdGstPad * pad)
{
  ISmdGstElementClass *klass;
  ismd_port_handle_t port = pad->ismd_port;

  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  /* Check if element is empty */
  if (smd_element->next_client_id == 0) {
    /* We don't need to drain if nothing had been pushed to the element */
    goto beach;
  }

  ismd_gst_pad_port_stats (pad);

  /* First try to drain the input queue */
  while (!is_port_empty (smd_element, port)) {
    os_sleep (50);
  }

  /* now try to drain the element */
  if (klass->drain) {
    klass->drain (smd_element);
  }

beach:
  GST_DEBUG_OBJECT (smd_element, "element drained");
}

static inline gboolean
tag_new_segment (ISmdGstElement * smd_element,
    ismd_buffer_handle_t smd_buffer)
{
  ismd_newsegment_tag_t newsegment_data;
  ISmdGstElementClass *klass;
  ismd_result_t result;

  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  newsegment_data.requested_rate = GST_TO_SMD_RATE (smd_element->segment.rate);
  newsegment_data.applied_rate =
      GST_TO_SMD_RATE (smd_element->segment.applied_rate);
  newsegment_data.rate_valid = TRUE;

  GST_DEBUG_OBJECT (smd_element, "TAGGING NEWSEGMENT ON BUFFER");

  if (smd_element->segment.format == GST_FORMAT_TIME) {
    newsegment_data.start = GST_TO_SMD_TIME (smd_element->segment.start);
    newsegment_data.stop = GST_TO_SMD_TIME (smd_element->segment.stop);
    if (klass->is_sink) {
      /* We hack here the linear_start for sinks as it's used to synchronize in
       * the smd hardware side and this doesn't match the expected behavior
       * in gstreamer. */
      newsegment_data.linear_start = GST_TO_SMD_TIME (smd_element->segment.accum);
    } else {
      /* Keep the newsegment info until we push it into a sink element */
      newsegment_data.linear_start = GST_TO_SMD_TIME (smd_element->segment.time);
    }
  } else {
    newsegment_data.start = ISMD_NO_PTS;
    newsegment_data.stop = ISMD_NO_PTS;
    newsegment_data.linear_start = 0;
  }

  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: rate: %d: dev: %d:",
      newsegment_data.requested_rate, smd_element->dev_handle);
  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: start   : %llu (0x%llx)",
      newsegment_data.start, newsegment_data.start);
  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: stop    : %llu (0x%llx)",
      newsegment_data.stop, newsegment_data.stop);
  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: position: %llu (0x%llx)",
      newsegment_data.linear_start, newsegment_data.linear_start);
  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: req_rate: %d",
      newsegment_data.requested_rate);
  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: app_rate: %d",
      newsegment_data.applied_rate);
  GST_INFO_OBJECT (smd_element, "SMD NEWSEGMENT: valid   : %d",
      newsegment_data.rate_valid);

  result = ismd_tag_set_newsegment (smd_buffer, newsegment_data);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "cannot set SMD newsegment");
    return FALSE;
  }
  return TRUE;
}

static void
ismd_gst_element_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (object);

  switch (prop_id) {
    case PROP_USE_BUFFERING:
      g_value_set_boolean (value, smd_element->use_buffering);
      break;
    case PROP_STREAM_TIME_OFFSET:
      g_value_set_uint64 (value, smd_element->stream_time_offset);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_element_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (object);

  switch (prop_id) {
    case PROP_USE_BUFFERING:
      smd_element->use_buffering = g_value_get_boolean (value);
      GST_DEBUG_OBJECT (smd_element, "use-buffering set to %d",
          smd_element->use_buffering);
      break;
    case PROP_STREAM_TIME_OFFSET:
      smd_element->stream_time_offset = g_value_get_uint64 (value);
      GST_DEBUG_OBJECT (smd_element, "stream-time-offset set to %" \
          GST_TIME_FORMAT, GST_TIME_ARGS (smd_element->stream_time_offset));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_element_base_init (gpointer klass)
{
  static GstElementDetails details = {
    "Intel Streaming Media Driver (ISMD) Base Element Class",
    "ISmdGstElement",
    "Base element class for Intel's Media Processor Gstreamer Drivers",
    "http://www.intelconsumerelectronics.com/"
  };

  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);

  gst_element_class_set_details (eclass, &details);
}

static void
ismd_gst_element_class_init (ISmdGstElementClass * klass)
{
  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GObjectClass *oclass = G_OBJECT_CLASS (klass);

  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_element_change_state);

  oclass->get_property = ismd_gst_element_get_property;
  oclass->set_property = ismd_gst_element_set_property;

  g_object_class_install_property (oclass,
      PROP_USE_BUFFERING,
      g_param_spec_boolean ("use-buffering",
          "Use Buffering",
          "Permits join multiple buffers to feed 32kb SMD buffers to device",
          DEFAULT_USE_BUFFERING, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_STREAM_TIME_OFFSET,
      g_param_spec_uint64 ("stream-time-offset", "Stream Time Offset",
          "Specifies an offset in ns to apply on clock synchronization.",
          0, G_MAXUINT64, DEFAULT_STREAM_TIME_OFFSET, G_PARAM_READWRITE));

  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_element_finalize);

  klass->dev_ops.close = ismd_dev_close;
  klass->dev_ops.flush = ismd_dev_flush;
  klass->dev_ops.set_state = ismd_dev_set_state;
  klass->dev_ops.set_clock = ismd_dev_set_clock;
  klass->dev_ops.set_base_time = ismd_dev_set_stream_base_time;
  klass->dev_ops.set_play_rate = ismd_dev_set_play_rate;
  klass->dev_ops.set_underrun_event = ismd_dev_set_underrun_event;
  klass->dev_ops.get_underrun_amount = ismd_dev_get_underrun_amount;
  klass->dev_ops.get_state = ismd_dev_get_state;
  klass->dev_ops.get_base_time = ismd_dev_get_stream_base_time;
  klass->dev_ops.get_play_rate = ismd_dev_get_play_rate;
  klass->dev_ops.set_slave_clock = ismd_dev_set_slave_clock;

  klass->push_buffer = NULL;
  klass->convert = NULL;
  klass->prerolled = NULL;
  klass->drain = NULL;
  klass->track_qos = NULL;
  klass->event = NULL;
  klass->is_decoder = FALSE;
  klass->is_sink = FALSE;
  klass->is_audio_decoder = FALSE;
  klass->is_ts_muxer = FALSE;
  klass->is_vidio_enc = FALSE;
}

static void
ismd_gst_element_init (ISmdGstElement * smd_element,
    ISmdGstElementClass * klass)
{
  smd_element->event_loop = NULL;
  smd_element->event_loop_mutex = NULL;
  smd_element->pad_list_mutex = g_mutex_new ();
  smd_element->dev_handle = ISMD_DEV_HANDLE_INVALID;

  smd_element->stop_writing_data = FALSE;
  smd_element->is_flushing = FALSE;
  smd_element->initial_flush = FALSE;
  smd_element->need_new_seq_hdr = FALSE;
  smd_element->send_newsegment = FALSE;
  smd_element->last_ret = GST_FLOW_OK;
  smd_element->use_buffering = DEFAULT_USE_BUFFERING;
  smd_element->stream_time_offset = DEFAULT_STREAM_TIME_OFFSET;

  gst_segment_init (&smd_element->segment, GST_FORMAT_TIME);
  smd_element->src_pad_event = ISMD_EVENT_HANDLE_INVALID;
  smd_element->sink_pad = NULL;

  smd_element->next_client_id = 0;
  smd_element->system_stride = SYSTEM_STRIDE;
  smd_element->video_bitrate = ISMD_INVALID_BIT_RATE;
}

static void
ismd_gst_element_finalize (GObject * object)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (object);
  ISmdGstElementClass *klass;
  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  GST_DEBUG_OBJECT (smd_element, "Destroying");

  if (smd_element->event_loop != NULL) {
    gst_object_unref (smd_element->event_loop);
    smd_element->event_loop = NULL;
    g_static_rec_mutex_free (smd_element->event_loop_mutex);
    g_free (smd_element->event_loop_mutex);
    smd_element->event_loop_mutex = NULL;
    ismd_event_free (smd_element->src_pad_event);
    smd_element->src_pad_event = ISMD_EVENT_HANDLE_INVALID;
  }

  g_list_foreach (smd_element->src_pads, ismd_gst_mass_unregister_srcpad_shim, smd_element);
  g_list_free (smd_element->src_pads);
  smd_element->src_pads = NULL;
  g_list_foreach (smd_element->sink_pads, ismd_gst_mass_unregister_sinkpad_shim, smd_element);
  g_list_free (smd_element->sink_pads);
  smd_element->sink_pads = NULL;
  g_mutex_free (smd_element->pad_list_mutex);
  smd_element->pad_list_mutex = NULL;

  if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
    klass->dev_ops.close (smd_element->dev_handle);
    smd_element->dev_handle = ISMD_DEV_HANDLE_INVALID;
  }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GstStateChangeReturn
ismd_gst_element_change_state (GstElement * element, GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstElementClass *klass;
  GstStateChangeReturn bret, ret = GST_STATE_CHANGE_SUCCESS;
  ismd_result_t result = TRUE;
  GList *padlist_sink = smd_element->sink_pads;
  ISmdGstElementSinkPad *pad_node_data = NULL;
  
  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  GST_DEBUG_OBJECT (smd_element, "going to change state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));

  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
    {
      gst_segment_init (&smd_element->segment, GST_FORMAT_TIME);
      smd_element->next_client_id = 0;
      smd_element->stop_writing_data = FALSE;
      smd_element->prerolled = FALSE;
      smd_element->is_flushing = FALSE;
      smd_element->need_new_seq_hdr = TRUE;
      ismd_setup_input_pad (smd_element->sink_pad);
	  
      /* For only support two-sink pads */
      if ((padlist_sink = g_list_next (padlist_sink)) != NULL) {
	    pad_node_data =  padlist_sink->data;
	    ismd_setup_input_pad (pad_node_data->sink_pad);
      	}
      break;
    }
    case GST_STATE_CHANGE_READY_TO_PAUSED:
      smd_element->par_x = smd_element->par_y = 0;
      smd_element->stop_writing_data = FALSE;
      memset (&smd_element->video_props, 0,
          sizeof (ismd_viddec_stream_properties_t));

      GST_PAD_PREROLL_LOCK (GST_PAD (smd_element->sink_pad));

      if (klass->is_sink) {
        GST_DEBUG_OBJECT (smd_element, "Posting async start");
        smd_element->need_preroll = TRUE;
        smd_element->playing_async = TRUE;
        smd_element->commited = FALSE;
        ret = GST_STATE_CHANGE_ASYNC;
        gst_element_post_message (GST_ELEMENT_CAST (smd_element),
            gst_message_new_async_start (GST_OBJECT_CAST (smd_element),
                FALSE));
      } else {
        GST_DEBUG_OBJECT (element, "setting device %d to ISMD_DEV_STATE_PAUSE",
            smd_element->dev_handle);
        if (!(klass->is_audio_decoder || klass->is_ts_muxer))
        {
          result = klass->dev_ops.set_state (smd_element->dev_handle,
                ISMD_DEV_STATE_PAUSE);
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d",
                result);
          }
        }
      }
      GST_PAD_PREROLL_UNLOCK (GST_PAD (smd_element->sink_pad));
      /* Here we can start the task to push buffers in the src pad */
      if (smd_element->event_loop != NULL) {
        /* Before Task Starts, Determine if can connect pads */
        GST_DEBUG_OBJECT (element, "calling connect_pads()");
        connect_pads (smd_element);
        GST_DEBUG_OBJECT (element, "starting Event Loop task");
        gst_task_start (smd_element->event_loop);
      }

      break;
    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
      /* First distribute the clock to the element */

      GST_PAD_PREROLL_LOCK (GST_PAD (smd_element->sink_pad));
      if (klass->is_sink) {
        if (ISMD_GST_IS_CLOCK (element->clock)) {
          ISmdGstClock *smd_clock = ISMD_GST_CLOCK (element->clock);
          ismd_time_t smd_stream_time;

          GST_INFO_OBJECT (smd_element, "Setting SMD Clock: ID = %d",
              smd_clock->dev_handle);
          result = klass->dev_ops.set_clock (smd_element->dev_handle,
              smd_clock->dev_handle);
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (smd_element, "ismd_dev_set_clock failed(%d)",
                result);
          }

          smd_stream_time = GST_TO_SMD_TIME (element->base_time);
          GST_DEBUG_OBJECT (element, "base_time: %" GST_TIME_FORMAT
              " SMD stream time: %llu",
              GST_TIME_ARGS (element->base_time), smd_stream_time);
          if (smd_element->stream_time_offset) {
            smd_stream_time +=
                GST_TO_SMD_TIME (smd_element->stream_time_offset);
            GST_DEBUG_OBJECT (element, "stream time offset: %" GST_TIME_FORMAT
                " final SMD stream time: %llu",
                GST_TIME_ARGS (smd_element->stream_time_offset),
                smd_stream_time);
          }

          result = klass->dev_ops.set_base_time (smd_element->dev_handle,
              smd_stream_time);
          if (result != ISMD_SUCCESS) {
            GST_WARNING_OBJECT (element,
                "ismd_dev_set_stream_base_time failed(%d)", result);
          }
          ismd_gst_clock_bufmon_add_render (smd_clock, smd_element->dev_handle);
        }

        if (smd_element->prerolled) {
          GST_DEBUG_OBJECT (smd_element,
              "PAUSED to PLAYING, don't need preroll");
          /* no preroll needed anymore now. */
          smd_element->playing_async = FALSE;
          smd_element->need_preroll = FALSE;
          GST_DEBUG_OBJECT (smd_element, "signal preroll");
        } else {
          GST_DEBUG_OBJECT (smd_element,
              "PAUSED to PLAYING, we are not prerolled");
          smd_element->need_preroll = TRUE;
          smd_element->playing_async = TRUE;
          smd_element->commited = FALSE;
          ret = GST_STATE_CHANGE_ASYNC;
          gst_element_post_message (GST_ELEMENT_CAST (smd_element),
              gst_message_new_async_start (GST_OBJECT_CAST (smd_element),
                  FALSE));
        }
      }

      GST_DEBUG_OBJECT (element, "setting device %d to ISMD_DEV_STATE_PLAY",
          smd_element->dev_handle);
      result = klass->dev_ops.set_state (smd_element->dev_handle,
          ISMD_DEV_STATE_PLAY);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (element,
            "ismd_dev_set_state failed(%d)", result);
      }
      GST_PAD_PREROLL_UNLOCK (GST_PAD (smd_element->sink_pad));

      break;
    case GST_STATE_CHANGE_PAUSED_TO_READY:
      GST_OBJECT_LOCK (smd_element);
      smd_element->is_flushing = TRUE;
      smd_element->stop_writing_data = TRUE;
      GST_OBJECT_UNLOCK (smd_element);

      GST_DEBUG_OBJECT (element, "unblock input loop");
      result = ismd_event_strobe (smd_element->sink_pad->sink_pad_event);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (element, "ismd_event_strobe failed(%d)", result);
      }

      if (smd_element->event_loop != NULL) {
        gst_task_stop (smd_element->event_loop);
        GST_DEBUG_OBJECT (element, "strobing queue event to unblock it");
        result = ismd_event_strobe (smd_element->src_pad_event);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (element, "ismd_event_strobe failed(%d)", result);
        }
        gst_task_join (smd_element->event_loop);
      }

      /* Flush the adapter */
      adapter_all_reset (smd_element);
#if 0
      /* need flushing first to unblock looping when handling EOS event */
      GST_DEBUG_OBJECT (smd_element, "flushing device");
      result = smd_element->dev_ops.flush (smd_element->dev_handle);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "ismd_dev_flush failed(%d)", result);
      }
#endif
      GST_DEBUG_OBJECT (element, "stop device");
      result = klass->dev_ops.set_state (smd_element->dev_handle,
          ISMD_DEV_STATE_STOP);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (element, "ismd_dev_set_state failed(%d)", result);
      }

      GST_OBJECT_LOCK (smd_element);
      smd_element->is_flushing = FALSE;
      GST_OBJECT_UNLOCK (smd_element);      
      break;
    case GST_STATE_CHANGE_READY_TO_NULL:
      smd_element->stop_writing_data = TRUE;
      break;
    default:
      break;
  }
  /*
   * Call default parent_class->change_state function
   */
  bret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);

  if (bret == GST_STATE_CHANGE_FAILURE) {
    goto activate_failed;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
      result = klass->dev_ops.set_state (smd_element->dev_handle,
          ISMD_DEV_STATE_PAUSE);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d",
            result);
      }
      if (klass->is_sink) {
        smd_element->need_preroll = TRUE;
        if (smd_element->prerolled) {
          GST_DEBUG_OBJECT (smd_element, "PLAYING to PAUSED, we are prerolled");
          smd_element->playing_async = FALSE;
        } else {
          if (GST_STATE_TARGET (GST_ELEMENT (smd_element)) <= GST_STATE_READY) {
            ret = GST_STATE_CHANGE_SUCCESS;
          } else {
            GST_DEBUG_OBJECT (smd_element,
                "PLAYING to PAUSED, we are not prerolled");
            smd_element->playing_async = TRUE;
            smd_element->commited = FALSE;
            GST_DEBUG_OBJECT (smd_element, "doing async state change");
            ret = GST_STATE_CHANGE_ASYNC;
            gst_element_post_message (GST_ELEMENT_CAST (smd_element),
                gst_message_new_async_start (GST_OBJECT_CAST (smd_element),
                    FALSE));
          }
        }
        ismd_gst_clock_bufmon_remove_render (ISMD_GST_CLOCK (element->clock), smd_element->dev_handle);
      }
      break;
    case GST_STATE_CHANGE_READY_TO_NULL:
      disconnect_pads (smd_element);

      ismd_unlink_function (GST_PAD(smd_element->sink_pad));
	  
      /* For only support two-sink pads */
      if ((padlist_sink = g_list_next (padlist_sink)) != NULL) {
	    pad_node_data =  padlist_sink->data;
	    ismd_unlink_function (GST_PAD (pad_node_data->sink_pad));
      	}

      if ((smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID)) {
        GST_DEBUG_OBJECT (element, "ismd_dev_close(dev_h=%d)",
            smd_element->dev_handle);
        klass->dev_ops.close (smd_element->dev_handle);
        smd_element->dev_handle = ISMD_DEV_HANDLE_INVALID;
      }
      break;
    default:
      break;
  }

  GST_DEBUG_OBJECT (smd_element, "changed state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));

  return ret;

activate_failed:
  {
    GST_DEBUG_OBJECT (smd_element,
        "element failed to change states -- activation problem?");
    return GST_STATE_CHANGE_FAILURE;
  }
}

static ISmdGstElementSinkPad * ismd_gst_element_get_sink_pad_nodedata(ISmdGstElement * smd_element,
                ISmdGstPad * pad)
{
    GList *node = NULL;
    ISmdGstElementSinkPad *pad_node_data = NULL; 
    node = smd_element->sink_pads;
    while(node){
        pad_node_data = node->data;
        node = node->next;
        if (pad_node_data->sink_pad == pad)
            return pad_node_data;
    }
    return NULL;
}

gboolean
ismd_gst_element_register_sinkpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad)
{
   ISmdGstElementSinkPad *pad_node_data = NULL; 
  g_mutex_lock (smd_element->pad_list_mutex);
  GST_LOG_OBJECT (smd_element, "registering sinkpad %" GST_PTR_FORMAT,
      GST_PAD (pad));
  gst_pad_set_event_function (GST_PAD (pad),
      GST_DEBUG_FUNCPTR (ismd_gst_element_sink_event));
  gst_pad_set_chain_function (GST_PAD (pad),
      GST_DEBUG_FUNCPTR (ismd_gst_element_sink_chain));
  gst_pad_set_unlink_function (GST_PAD (pad),
      GST_DEBUG_FUNCPTR (ismd_unlink_function));

  pad_node_data =  g_malloc0 (sizeof (ISmdGstElementSinkPad));
  memset(pad_node_data, 0, sizeof(ISmdGstElementSinkPad));
  pad_node_data->sink_pad = pad;
  pad_node_data->adapter = gst_adapter_new ();
  pad_node_data->head_ts = GST_CLOCK_TIME_NONE;
  pad_node_data->next_ts = GST_CLOCK_TIME_NONE;

  ADAPTER_GET_LOCK(pad_node_data) = g_new0 (GStaticRecMutex, 1);
  g_static_rec_mutex_init (ADAPTER_GET_LOCK(pad_node_data));

  smd_element->sink_pads = g_list_append (smd_element->sink_pads, (gpointer) pad_node_data);
  pad_node_data = smd_element->sink_pads->data;
  smd_element->sink_pad =  pad_node_data->sink_pad;

  g_mutex_unlock (smd_element->pad_list_mutex);
  return TRUE;
}

gboolean
ismd_gst_element_register_srcpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad)
{
  GST_LOG_OBJECT (smd_element, "registering srcpad %" GST_PTR_FORMAT,
      GST_PAD (pad));
  /*
   * Assumptions: This will be called before NULL to Ready
   */
  g_mutex_lock (smd_element->pad_list_mutex);
  smd_element->src_pads = g_list_append (smd_element->src_pads, (gpointer) pad);
  gst_pad_set_link_function (GST_PAD (pad),
      GST_DEBUG_FUNCPTR (ismd_src_link_function));
  gst_pad_set_unlink_function (GST_PAD (pad),
      GST_DEBUG_FUNCPTR (ismd_unlink_function));
  g_mutex_unlock (smd_element->pad_list_mutex);

  if (smd_element->event_loop == NULL) {
    if (ismd_event_alloc (&smd_element->src_pad_event) != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "Cannot allocate src pad event!");
    }

    smd_element->event_loop_mutex = g_new0 (GStaticRecMutex, 1);
    g_static_rec_mutex_init (smd_element->event_loop_mutex);
    GST_DEBUG_OBJECT (smd_element, "creating task ismd_gst_element_event_loop");
    smd_element->event_loop =
        gst_task_create ((GstTaskFunction) ismd_gst_element_event_loop,
        smd_element);
    gst_task_set_lock (smd_element->event_loop, smd_element->event_loop_mutex);
  } else {
    /*
     * look to see if event loop is in running state
     */
  }
  return TRUE;
}

gboolean
ismd_gst_element_unregister_sinkpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad)
{
   ISmdGstElementSinkPad *pad_node_data = NULL; 
  g_mutex_lock (smd_element->pad_list_mutex);
  pad_node_data = ismd_gst_element_get_sink_pad_nodedata(smd_element, pad);
  g_static_rec_mutex_free (pad_node_data->adapter_lock);
  g_free (pad_node_data->adapter_lock);
  pad_node_data->adapter_lock = NULL;
  gst_adapter_clear(pad_node_data->adapter);
  g_object_unref(pad_node_data->adapter);
  pad_node_data->adapter = NULL;

  smd_element->sink_pads =
      g_list_remove (smd_element->sink_pads, (gconstpointer) pad_node_data);
  g_free(pad_node_data);
  g_mutex_unlock (smd_element->pad_list_mutex);
  return TRUE;
}

gboolean
ismd_gst_element_unregister_srcpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad)
{
  g_mutex_lock (smd_element->pad_list_mutex);
  smd_element->src_pads =
      g_list_remove (smd_element->src_pads, (gconstpointer) pad);
  g_mutex_unlock (smd_element->pad_list_mutex);
  return TRUE;
}

static void ismd_gst_mass_unregister_sinkpad_shim(gpointer padp, gpointer ele)
{
   ISmdGstElementSinkPad *pad_node_data = padp; 
   ISmdGstElement *smd_element = ele;

   ismd_gst_element_unregister_sinkpad(smd_element, pad_node_data->sink_pad);
}

static void ismd_gst_mass_unregister_srcpad_shim(gpointer padp, gpointer ele)
{
   ISmdGstPad *pad = padp;
   ISmdGstElement *smd_element = ele;

   ismd_gst_element_unregister_srcpad(smd_element, pad);
}

gboolean
ismd_gst_element_requires_clock (GstElementClass * element_class)
{
  element_class->set_clock = ismd_gst_element_set_clock;
  return TRUE;
}

gboolean
ismd_gst_element_is_src_pad (ISmdGstElement * smd_element)
{
  gboolean is_src_pad = FALSE;
  g_mutex_lock (smd_element->pad_list_mutex);
  if (g_list_length (smd_element->src_pads) > 0) {
    is_src_pad = TRUE;
  }
  g_mutex_unlock (smd_element->pad_list_mutex);
  return is_src_pad;
}

#define FOURCC_MAX_STRING_LEN 5

/* Checks if the supplied caps are supported for frame buffers */
static inline GstFlowReturn
ismd_gst_element_check_image_buf_caps (GstPad * pad, GstStructure * caps_struct)
{
  gint width, height;
  guint32 fourcc;

  if (!gst_structure_get_fourcc (caps_struct, "format", &fourcc)) {
    GST_ERROR_OBJECT (pad, "caps does not contain a fourcc");
    return GST_FLOW_ERROR;
  }

  if (fourcc != GST_MAKE_FOURCC ('N', 'V', '1', '2') &&
      fourcc != GST_MAKE_FOURCC ('I', '4', '2', '0')) {
    GST_ERROR_OBJECT (pad, "fourcc is not supported");
    return GST_FLOW_NOT_SUPPORTED;
  }

  if (!gst_structure_get_int (caps_struct, "width", &width)) {
    GST_ERROR_OBJECT (pad, "width is required");
    return GST_FLOW_ERROR;
  }

  if (width > 2048) {
    GST_ERROR_OBJECT (pad, "width %d exceeds supported %d", width, 2048);
    return GST_FLOW_NOT_SUPPORTED;
  }

  if (!gst_structure_get_int (caps_struct, "height", &height)) {
    GST_ERROR_OBJECT (pad, "height is required");
    return GST_FLOW_ERROR;
  }

  if (height > SMD_MAX_VIDEO_HEIGHT) {
    GST_ERROR_OBJECT (pad, "height %d exceeds supported %d",
        height, SMD_MAX_VIDEO_HEIGHT);
    return GST_FLOW_NOT_SUPPORTED;
  }

  return GST_FLOW_OK;
}

/* Determine the image size from a gst buffer's caps */
static inline gboolean
ismd_gst_element_get_image_details (GstCaps * caps,
    gint * width, gint * height, ismd_pixel_format_t * pixel_format)
{
  GstStructure *caps_struct;
  guint32 format;

  /* parse the attributes - format, width, height. */
  if (caps) {
    caps_struct = gst_caps_get_structure (caps, 0);

    if (!gst_structure_get_int (caps_struct, "width", width)) {
      return FALSE;
    }
    if (!gst_structure_get_int (caps_struct, "height", height)) {
      return FALSE;
    }
    if (!gst_structure_get_fourcc (caps_struct, "format", &format)) {
      return FALSE;
    } else {
      if (format == GST_MAKE_FOURCC ('N', 'V', '1', '2')) {
        *pixel_format = ISMD_PF_NV12;
      } else if (format == GST_MAKE_FOURCC ('N', 'V', '1', '6')) {
        *pixel_format = ISMD_PF_NV16;
      } else {
        return FALSE;
      }
    }
  } else {
    return FALSE;
  }

  return TRUE;
}

/* Helper function - this will set up the image attributes
 * for an ISMD descriptor.
 * This does not fill in the PTS field.
 * ismd_buffer_update_desc is called to update the kernel ISMD descriptor,
 * and subsequent changes to the descriptor must call that function also to
 * keep the user-space descriptor and the kernel-space descriptor synced.
 */
static inline ismd_result_t
ismd_gst_element_set_up_image_attrs_for_ismd_buf (ISmdGstElement * smd_element,
    GstCaps * caps, ismd_buffer_descriptor_t * desc)
{
  gint width, height;
  ismd_pixel_format_t pixel_format = ISMD_PF_COUNT;     /* default to invalid */
  ismd_frame_attributes_t *attr =
      (ismd_frame_attributes_t *) & (desc->attributes);

  /* parse the attributes - format, width, height. */
  ismd_gst_element_get_image_details (caps, &width, &height, &pixel_format);

  /* Now fill in the zillion of frame attribute fields */
  attr->discontinuity = FALSE;

  attr->cont_rate = 0;
  attr->cont_size.width = width;
  attr->cont_size.height = height;
  attr->dest_size.width = width;
  attr->dest_size.height = height;
  attr->pixel_format = pixel_format;

  attr->color_space = ISMD_SRC_COLOR_SPACE_BT709;       /* used */
  attr->polarity = ISMD_POLARITY_FRAME; /* FIXME: can we tell if it's interlaced? */
  attr->gamma_type = ISMD_GAMMA_HDTV;   /* default as per as per ISO/IEC 13818-2 */
  attr->repeated = 0;

  attr->y = 0;
  attr->u = attr->y + (smd_element->system_stride * height);

  /* commit the changes to the descriptor */
  return ismd_buffer_update_desc (desc->unique_id, desc);
}

/* helper function for the sink chain - copies a virtual frame buffer to
 * a physical one.
 * this assumes the incoming frame is YUV 4:2:0 NV12 or NV16
 */
static inline ismd_result_t
ismd_gst_element_copy_virt_frame_data_to_phys_buf (ISmdGstElement * smd_element,
    ismd_physical_address_t
    y_phys_addr,
    ismd_physical_address_t
    uv_phys_addr, guint8 * data,
    guint width, guint height, ismd_pixel_format_t pixel_format)
{
  guint line;
  ismd_result_t result = ISMD_SUCCESS;
  guint8 *virt_phys_y, *virt_phys_uv;
  gint uv_height;
  gint source_stride = width;   /* Assuming stride == width with non-downstream allocating devices */

  virt_phys_y = OS_MAP_IO_TO_MEM_CACHE (y_phys_addr,
      smd_element->system_stride * height);
  if (virt_phys_y == NULL) {
    result = ISMD_ERROR_NO_RESOURCES;
  } else {
    virt_phys_uv = OS_MAP_IO_TO_MEM_CACHE (uv_phys_addr,
        smd_element->system_stride * height);
    if (virt_phys_uv == NULL) {
      result = ISMD_ERROR_NO_RESOURCES;
    } else {

      /* copy Y data */
        for (line = 0; line < height; line++) {
#if USE_OPTIMIZED_MEMCPY
            /* Potentially copying some extra bytes (up to 63), this is OK because
             * SRC buffer has U and V  after Y, so we won't overrun it
             * DEST buffer was down-stream allocated to have a width rounded up to CACHE_LINE_SIZE,
             * or was locally allocated to have a width of desired_stride
             */
            memcpy_nt (virt_phys_y + (line * smd_element->system_stride),
                    data + (line * source_stride), ROUND_UP (width, CACHE_LINE_SIZE));
#else
            memcpy (virt_phys_y + (line * smd_element->system_stride),
                    data + (line * source_stride), width);
#endif
        }
      data += height * width;

      /* copy UV data */
      if (pixel_format == ISMD_PF_NV12) {
        uv_height = height / 2;
      } else if (pixel_format == ISMD_PF_NV16) {
        uv_height = height;
      } else {
        result = ISMD_ERROR_OPERATION_FAILED;
        uv_height = 0;
      }
      for (line = 0; line < uv_height; line++) {
#if USE_OPTIMIZED_MEMCPY
          /* Potentially copying some extra bytes (up to 63), this is OK because
           * SRC buffer has U and V  after Y, so we won't overrun it
           * DEST buffer was down-stream allocated to have a width rounded up to CACHE_LINE_SIZE,
           * or was locally allocated to have a width of desired_stride
           */
          memcpy_nt (virt_phys_uv + (line * smd_element->system_stride),
                  data + (line * source_stride), ROUND_UP (width, CACHE_LINE_SIZE));
#else
          memcpy (virt_phys_uv + (line * smd_element->system_stride),
                  data + (line * source_stride), width);
#endif
      }

      OS_UNMAP_IO_FROM_MEM (virt_phys_y, smd_element->system_stride * height);
      OS_UNMAP_IO_FROM_MEM (virt_phys_uv, smd_element->system_stride * height);
    }
  }

  return result;
}


/* helper to write out an smd buffer to a port
 * returns TRUE on success, FALSE if fatal error or aborted */
static gboolean
ismd_gst_element_sink_port_write (ISmdGstElement * smd_element, GstPad * pad,
    ismd_buffer_handle_t buf_handle)
{
  ismd_result_t result;
  ISmdGstPad *ismd_pad = ISMD_GST_PAD (pad);
  ISmdGstElementClass *klass =
      ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

#if 0
  ismd_gst_pad_port_stats (smd_element->sink_pad);
#endif
  GST_LOG_OBJECT (pad, "write buffer: %d (client-id: %d)", buf_handle,
      smd_element->next_client_id);

  /*  Add a client_id = a serial number to each bufer for sink element */
  if (klass->is_sink) {
    result = ismd_tag_set_client_id (buf_handle, smd_element->next_client_id);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (smd_element, "ismd_tag_set_client_id failed (%d)",
          result);
    }
  }
  
  if (smd_element->send_newsegment == TRUE) {
    tag_new_segment (smd_element, buf_handle);
    smd_element->send_newsegment = FALSE;
  }

  if (klass->track_qos) {
    klass->track_qos (smd_element, smd_element->next_client_id, 0);
  }

  do {
    result = ismd_port_write (ismd_pad->ismd_port, buf_handle);

    if (result == ISMD_SUCCESS) {
      if (klass->track_qos) {
        klass->track_qos (smd_element, smd_element->next_client_id, 1);
      }

      /* Commit the state after write the first buffer */
      if (klass->is_sink) {
        GST_PAD_PREROLL_LOCK (GST_PAD (smd_element->sink_pad));
        if (smd_element->playing_async && smd_element->need_preroll) {
          if (G_UNLIKELY (!ismd_gst_element_commit_state (smd_element)))
            goto stopping;
        }
        GST_PAD_PREROLL_UNLOCK (GST_PAD (smd_element->sink_pad));
      }
      smd_element->next_client_id++;
      return TRUE;
    } else if (result == ISMD_ERROR_NO_SPACE_AVAILABLE) {

#if 0
      GST_DEBUG_OBJECT (pad, "input port is full");
      ismd_gst_pad_port_stats (smd_element->sink_pad);
#endif
      /* wait for the queue event notification before attempting to write
       * again to the port.  In case the event never comes, set timeout to
       * reasonable value.
      */
      result =
          ismd_event_wait (ismd_pad->sink_pad_event, ISMD_EVENT_TIMEOUT);
      if (result == ISMD_SUCCESS) {
        ismd_event_acknowledge (ismd_pad->sink_pad_event);
      }
    } else if (result == ISMD_ERROR_PORT_BUSY) {
      GST_ERROR_OBJECT (pad, "ISMD_PORT_BUSY (connected)");
      return FALSE;
    }
  } while ((result == ISMD_ERROR_TIMEOUT || result == ISMD_SUCCESS) &&
      !smd_element->stop_writing_data);

  if (smd_element->stop_writing_data) {
    GST_DEBUG_OBJECT (pad, "ismd_port_write(): unblocking "
        "from ismd_event_wait() - element flushing");
    smd_element->last_ret = GST_FLOW_WRONG_STATE;
  } else {
    GST_ERROR_OBJECT (pad, "dropped a buffer - expect macroblocking"
        " / out-of-order frame PTS values %d %d", result,
        smd_element->stop_writing_data);
  }

  return FALSE;

stopping:
  {
    GST_DEBUG_OBJECT (smd_element, "stopping while commiting state");
    GST_PAD_PREROLL_UNLOCK (GST_PAD (smd_element->sink_pad));
    return FALSE;
  }
}


static gboolean
ismd_gst_element_send_eos (GstPad * pad)
{
  ismd_result_t result;
  ismd_buffer_handle_t buffer;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent (pad));
  ISmdGstElementClass *klass =
      ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));
  gboolean ret = TRUE;

  GST_DEBUG_OBJECT (smd_element, "injecting EOS SMD buffer");

  if (klass->is_sink) {
    GST_PAD_PREROLL_LOCK (GST_PAD (smd_element->sink_pad));
    if (smd_element->playing_async && smd_element->need_preroll) {
      if (G_UNLIKELY (!ismd_gst_element_commit_state (smd_element))) {
        ret = FALSE;
	goto beach;
      }
    }
    GST_PAD_PREROLL_UNLOCK (GST_PAD (smd_element->sink_pad));
  }

  result = ismd_buffer_alloc (0, &buffer);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_buffer_alloc failed (%d)", result);
    ret = FALSE;
    goto beach;
  }
  result = ismd_tag_set_eos (buffer);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_tag_set_eos failed (%d)", result);
    ret = FALSE;
    goto beach;
  }

  if (!ismd_gst_element_sink_port_write (smd_element, pad, buffer)) {
      ismd_buffer_dereference (buffer);
      ret = FALSE;
      goto beach;
  }
beach:
  gst_object_unref(smd_element);
  return ret;
}

/* with PREROLL_LOCK, STREAM_LOCK */
static gboolean
ismd_gst_element_commit_state (ISmdGstElement * smd_element)
{
  /* commit state and proceed to next pending state */
  GstState current, next, pending, post_pending;
  gboolean post_paused = FALSE;
  gboolean post_async_done = FALSE;
  gboolean post_playing = FALSE;
  ISmdGstElementClass *klass;
  ismd_result_t result;

  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));
  /* we are certainly not playing async anymore now */
  smd_element->playing_async = FALSE;
  smd_element->prerolled = TRUE;

  GST_OBJECT_LOCK (smd_element);
  current = GST_STATE (smd_element);
  next = GST_STATE_NEXT (smd_element);
  pending = GST_STATE_PENDING (smd_element);
  post_pending = pending;

  switch (pending) {
    case GST_STATE_PLAYING:
    {
      GST_DEBUG_OBJECT (smd_element, "commiting state to PLAYING");

      smd_element->need_preroll = FALSE;
      post_async_done = TRUE;
      smd_element->commited = TRUE;
      post_playing = TRUE;
      /* post PAUSED too when we were READY */
      if (current == GST_STATE_READY) {
        post_paused = TRUE;
      }

      break;
    }
    case GST_STATE_PAUSED:
      GST_DEBUG_OBJECT (smd_element, "commiting state to PAUSED");
      GST_DEBUG_OBJECT (smd_element, "setting device %d to ISMD_DEV_STATE_PAUSE",
          smd_element->dev_handle);
      result = klass->dev_ops.set_state (smd_element->dev_handle,
          ISMD_DEV_STATE_PAUSE);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d",
            result);
      }
      post_paused = TRUE;
      post_async_done = TRUE;
      smd_element->commited = TRUE;
      post_pending = GST_STATE_VOID_PENDING;
      if (klass->prerolled) {
        klass->prerolled (smd_element);
      }
      break;
    case GST_STATE_READY:
    case GST_STATE_NULL:
      goto stopping;
    case GST_STATE_VOID_PENDING:
      goto nothing_pending;
    default:
      break;
  }

  GST_STATE (smd_element) = pending;
  GST_STATE_NEXT (smd_element) = GST_STATE_VOID_PENDING;
  GST_STATE_PENDING (smd_element) = GST_STATE_VOID_PENDING;
  GST_STATE_RETURN (smd_element) = GST_STATE_CHANGE_SUCCESS;
  GST_OBJECT_UNLOCK (smd_element);

  if (post_paused) {
    GST_DEBUG_OBJECT (smd_element, "posting PAUSED state change message");
    gst_element_post_message (GST_ELEMENT_CAST (smd_element),
        gst_message_new_state_changed (GST_OBJECT_CAST (smd_element),
            current, next, post_pending));
  }
  if (post_async_done) {
    GST_DEBUG_OBJECT (smd_element, "posting async-done message");
    gst_element_post_message (GST_ELEMENT_CAST (smd_element),
        gst_message_new_async_done (GST_OBJECT_CAST (smd_element)));
  }
  if (post_playing) {
    GST_DEBUG_OBJECT (smd_element, "posting PLAYING state change message");
    gst_element_post_message (GST_ELEMENT_CAST (smd_element),
        gst_message_new_state_changed (GST_OBJECT_CAST (smd_element),
            next, pending, GST_STATE_VOID_PENDING));
  }

  GST_STATE_BROADCAST (smd_element);
  return TRUE;

nothing_pending:
  {
    /* Depending on the state, set our vars. We get in this situation when the
     * state change function got a change to update the state vars before the
     * streaming thread did. This is fine but we need to make sure that we
     * update the need_preroll var since it was TRUE when we got here and might
     * become FALSE if we got to PLAYING. */
    GST_DEBUG_OBJECT (smd_element, "nothing to commit, now in %s",
        gst_element_state_get_name (current));
    switch (current) {
      case GST_STATE_PLAYING:
        smd_element->need_preroll = FALSE;
        break;
      case GST_STATE_PAUSED:
        smd_element->need_preroll = TRUE;
        break;
      default:
        smd_element->need_preroll = FALSE;
        smd_element->is_flushing = TRUE;
        break;
    }
    GST_OBJECT_UNLOCK (smd_element);
    return TRUE;
  }
stopping:
  {
    /* app is going to READY */
    GST_DEBUG_OBJECT (smd_element, "stopping");
    smd_element->need_preroll = FALSE;
    smd_element->is_flushing = TRUE;
    GST_OBJECT_UNLOCK (smd_element);
    return FALSE;
  }
}

/* Someone sent an SMD buffer to the sink chain.  Feed it to the port */
static ismd_result_t
ismd_gst_element_sink_chain_smd_buffer (ISmdGstElement * smd_element,
    GstPad * pad, GstBuffer * buf, gboolean image_buffer)
{
  /* Recieved ISMD BUFFER */
  ismd_result_t result;
  ISmdGstBuffer *my_buf = ISMD_GST_BUFFER (buf);
  ismd_buffer_handle_t buf_handle = my_buf->ismd_buffer_id;
  ismd_buffer_descriptor_t desc;

  GST_LOG_OBJECT (smd_element, "received SMD buffer %p buf_handle: %d (%x)",
      buf, buf_handle, buf_handle);

  result = ismd_buffer_read_desc (buf_handle, &desc);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element,
        "failed to read ISMD descriptor for buf ID %d", buf_handle);
    ismd_buffer_dereference (buf_handle);
    goto beach;
  } else {
    ismd_frame_attributes_t *attr =
        (ismd_frame_attributes_t *) & desc.attributes;

    /* ISMD audio sink discards buffers with pts = 0, to avoid this
     * we convert a 0 ticks pts into 1 tick pts.
     * We ensure here that pts are copied into the SMD counterparts
     * this is important for software decoders that uses pad_alloc buffer
     * to require SMD buffers that won't have the pts inside. */
    if (GST_CLOCK_TIME_IS_VALID (GST_BUFFER_TIMESTAMP (buf))) {
      attr->local_pts = MAX (1, GST_TO_SMD_TIME (GST_BUFFER_TIMESTAMP (buf)));
      attr->original_pts = attr->local_pts;
      attr->discontinuity =
          GST_BUFFER_FLAG_IS_SET (buf, GST_BUFFER_FLAG_DISCONT);

      GST_LOG_OBJECT (smd_element, "buffer with pts %" GST_TIME_FORMAT,
          GST_TIME_ARGS (SMD_TO_GST_TIME (attr->local_pts)));

      /* commit the changes to the descriptor */
      result = ismd_buffer_update_desc (buf_handle, &desc);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element,
          "failed to update ISMD descriptor for PTS value");
      }
    }
    /* We need to increase the reference count, since the element will deref and GST will
     * also once the ismd_gst_buffer gets finalzed. */
    ismd_buffer_add_reference (buf_handle);

    /* try to write the buffer to the port.
     * if FALSE is returned, the write was aborted and the buffer
     * should be freed. */
    if (ismd_gst_element_sink_port_write (smd_element, pad, buf_handle) != TRUE) {
      /* we previously increased the reference count, so now decrese it. */
      ismd_buffer_dereference (buf_handle);
      result = ISMD_ERROR_TIMEOUT;
    }
  }

beach:
  return result;
}

/* Fed an yuv gstreamer buffer.  Grab an smd image buffer, copy the data and
* send it to the input port
*/
static ismd_result_t
ismd_gst_element_sink_chain_image_gst_buffer (ISmdGstElement * smd_element,
    GstPad * pad, GstBuffer * buf)
{
  /* Someone gave us a software frame buffer.  Copy it to an ISMD buffer */
  ismd_result_t result = ISMD_SUCCESS;
  ismd_buffer_descriptor_t desc;
  ismd_buffer_handle_t frame_handle;
  gint width, height;
  ismd_pixel_format_t pixel_format = ISMD_PF_COUNT;     /* default to invalid */
  gint height_to_alloc;


  GstCaps *caps = gst_buffer_get_caps (buf);

  /* Get the basic information of the buffer */
  if (!ismd_gst_element_get_image_details (caps, &width, &height,
          &pixel_format)) {
    result = ISMD_ERROR_UNSPECIFIED;
    goto beach;
  }

  GST_DEBUG_OBJECT (smd_element, "image size: width=%d height=%d "
      "pixel_format=%d", width, height, pixel_format);

  /* allocate hardware frame buffer */
  if (result == ISMD_SUCCESS) {
    if (pixel_format == ISMD_PF_NV16) {
      height_to_alloc = height * 2;
    } else if (pixel_format == ISMD_PF_NV12) {
      height_to_alloc = (height * 3) / 2;
    } else {
      GST_ERROR_OBJECT (smd_element, "Don't recognize pixel format %d",
          pixel_format);
      result = ISMD_ERROR_UNSPECIFIED;
      goto beach;
    }

    result = ismd_frame_buffer_alloc (width, height_to_alloc, &frame_handle);
  }

  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "frame buffer allocation failed(%d)",
        result);
    goto beach;
  } else {
    ismd_buffer_read_desc (frame_handle, &desc);
    ismd_frame_attributes_t *attr =
        (ismd_frame_attributes_t *) & desc.attributes;

    /* set up the descriptor, put it into the ISMD buffer */
    result = ismd_gst_element_set_up_image_attrs_for_ismd_buf (smd_element,
        caps, &desc);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element,
          "ismd_gst_element_set_up_image_attrs_for_ismd_buf failed (%d)",
          result);
      ismd_buffer_dereference (frame_handle);
      goto beach;
    }

    /* ISMD audio sink discards buffers with pts = 0, to avoid this
     * we convert a 0 ticks pts into 1 tick pts. */
    attr->local_pts = MAX (1, GST_TO_SMD_TIME (GST_BUFFER_TIMESTAMP (buf)));
    attr->original_pts = attr->local_pts;
    attr->discontinuity = GST_BUFFER_FLAG_IS_SET (buf, GST_BUFFER_FLAG_DISCONT);

    /* commit the changes to the descriptor */
    result = ismd_buffer_update_desc (frame_handle, &desc);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element,
          "failed to update ISMD descriptor for PTS value");
      ismd_buffer_dereference (frame_handle);
      goto beach;
    }

    /* copy the data into the buffer */
    result = ismd_gst_element_copy_virt_frame_data_to_phys_buf (smd_element,
        desc.phys.base + attr->y,       /* phys Y */
        desc.phys.base + attr->u,       /* phys UV */
        GST_BUFFER_DATA (buf),  /* SW buffer */
        attr->cont_size.width,  /* frame width */
        attr->cont_size.height, /* frame height */
        attr->pixel_format);    /* frame pixel format */

    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "Data copy to ISMD buffer failed!");
      ismd_buffer_dereference (frame_handle);
      goto beach;
    }

    /* try to write the buffer to the port.
    * if FALSE is returned, the write was aborted and the buffer should be freed.
    */
    if (ismd_gst_element_sink_port_write (smd_element, pad,
            frame_handle) != TRUE) {
      ismd_buffer_dereference (frame_handle);
      result = ISMD_ERROR_TIMEOUT;
    }
  }
  if (caps)
    gst_caps_unref (caps);

beach:
  return result;
}

/* Load up the data and timestamp from a gst buffer into an smd buffer and send
* it on down the pad's port
*/
static ismd_result_t
ismd_gst_element_sink_chain_gst_buffer (ISmdGstElement * smd_element,
    GstPad * pad, GstBuffer * buf, gboolean joinable)
{
  ismd_result_t result = ISMD_SUCCESS;
  ISmdGstElementSinkPad *pad_node_data = NULL; 

  GST_LOG_OBJECT (smd_element, "gst/chain called with buffer %p and ts %"
          GST_TIME_FORMAT, buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)));
  pad_node_data = ismd_gst_element_get_sink_pad_nodedata(smd_element, ISMD_GST_PAD(pad));
  guint avail = gst_adapter_available (pad_node_data->adapter);
  /* Now we can join some buffers and detect when there's a discont */
  if (GST_BUFFER_FLAG_IS_SET (buf, GST_BUFFER_FLAG_DISCONT) || !joinable) {
    result = adapter_drain (smd_element, pad_node_data);
    adapter_set_head (smd_element, pad_node_data, buf);
  }
  else if (GST_CLOCK_TIME_IS_VALID (GST_BUFFER_TIMESTAMP (buf))) {
    /* The buffer have a timestamp */
    if (!GST_CLOCK_TIME_IS_VALID (pad_node_data->head_ts)) {
      /* If our head buffer doesn't have a timestamp then drain the adapter
       * and make the new buffer a head buffer */
      if (avail)
        result = adapter_drain (smd_element, pad_node_data);
      adapter_set_head (smd_element, pad_node_data, buf);
    }
    else if (GST_BUFFER_TIMESTAMP(buf) != pad_node_data->next_ts) {
      /* Detect a discontinuty with the timestamp */
      result = adapter_drain (smd_element, pad_node_data);
      adapter_set_head (smd_element, pad_node_data, buf);
    }
    else {
      if (avail + GST_BUFFER_SIZE (buf) > ISMD_BUFFER_SIZE) {
        /* Detect when the adapter going to be bigger than an ISMD slot and
         * drain it */
        result = adapter_drain (smd_element, pad_node_data);
        adapter_set_head (smd_element, pad_node_data, buf);
      }
      else {
        /* otherwhise the buffer can be accumulated */
        adapter_push (smd_element, pad_node_data, buf);
      }
    }
  }
  else {
      /* When there's no timestamp in the buffer */
      if (avail + GST_BUFFER_SIZE (buf) > ISMD_BUFFER_SIZE) {
          /* Detect when the adapter going to be bigger than an ISMD slot and
           * drain it if required 
           */
          result = adapter_drain (smd_element, pad_node_data);
          adapter_set_head (smd_element, pad_node_data, buf);
      }
      else {
          /* otherwhise the buffer can be accumulated */
          adapter_push (smd_element, pad_node_data, buf);
      }
  }

  /* Directly split big buffers */
  avail = gst_adapter_available (pad_node_data->adapter);
  if (avail > ISMD_BUFFER_SIZE)
    result = adapter_drain (smd_element, pad_node_data);

  return result;
}

/* Callback function when someone wants to feed us a buffer from gstreamer.
 * This function takes a gstreamer buffer, insures its data has been placed
 * into an ismd buffer, and then stuffs it in a port.  The function will not
 * return until the buffer is in a port, discarded do to a flush, or aborted do
 * to error or state change.
 */
static GstFlowReturn
ismd_gst_element_sink_chain (GstPad * pad, GstBuffer * buf)
{
  GstCaps *caps;

  gboolean is_video = FALSE;
  gint my_port;
  ISmdGstElementClass *klass;
  ISmdGstElement *smd_element;
  GstFlowReturn ret = GST_FLOW_OK;
  GstClockTime timestamp = GST_BUFFER_TIMESTAMP (buf);
  gboolean joinable = FALSE;
  gboolean is_flushing = FALSE;
  GstState current_state;

  smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent_element (pad));
  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  GST_LOG_OBJECT (smd_element, "chain called with buffer %p of size=%d"
      " and timestamp %" GST_TIME_FORMAT,
      buf, GST_BUFFER_SIZE (buf), GST_TIME_ARGS (timestamp));

  if (GST_BUFFER_FLAG_IS_SET (buf, GST_BUFFER_FLAG_GAP) && klass->is_sink) {
    GST_LOG_OBJECT (smd_element, "Buffer has GAP flag and we are a sink");
    GST_PAD_PREROLL_LOCK (pad);
    if (smd_element->playing_async && smd_element->need_preroll) {
      if (G_UNLIKELY (!ismd_gst_element_commit_state (smd_element)))
        ret = GST_FLOW_UNEXPECTED;
    }
    GST_PAD_PREROLL_UNLOCK (pad);
    goto beach;
  }

  GST_OBJECT_LOCK (smd_element);
  is_flushing = smd_element->is_flushing;
  GST_OBJECT_UNLOCK (smd_element);

  if (is_flushing)
    goto flushing;

  /* Update the timestamps as a fallback to answer the query position in
   * the sink */
  current_state = GST_STATE (smd_element);
  if (current_state == GST_STATE_PLAYING) {
      if (GST_CLOCK_TIME_IS_VALID (timestamp)) {
        gst_segment_set_last_stop (&smd_element->segment, GST_FORMAT_TIME,
          timestamp);
     }
  }

  if (klass->convert) {
    GST_LOG_OBJECT (smd_element, "child convert called");
    buf = klass->convert (smd_element, buf, smd_element->need_new_seq_hdr);
    if (!buf)
      goto beach;
    smd_element->need_new_seq_hdr = FALSE;
  }

  /* detect if this is an image frame, by looking at the caps for the pad. */
  caps = gst_buffer_get_caps (buf);
  if (caps) {
    GstStructure *structure;
    const gchar *name = NULL;
    structure = gst_caps_get_structure (caps, 0);
    name = gst_structure_get_name (structure);

    /* if image frame, remember that it is */
    if (!strcmp (name, "video/x-raw-yuv")) {
      is_video = TRUE;
    } else if (!strncmp (name, "audio",5)) {
      joinable = TRUE;
    } else if (klass->is_decoder && timestamp == -1) {
      joinable = TRUE;
    }
    gst_caps_unref (caps);
  }

  if (!smd_element->use_buffering)
    joinable = FALSE;

  my_port = (ISMD_GST_PAD (pad))->ismd_port;

  if ((my_port == -1) || (smd_element->dev_handle == ISMD_DEV_HANDLE_INVALID)) {
    GST_ERROR_OBJECT (smd_element, "invalid port: %d or dev_handle: %d, "
        "droping buffer", my_port, smd_element->dev_handle);
    gst_buffer_unref (buf);
    buf = NULL;
    ret = GST_FLOW_ERROR;;
  } else if (ISMD_GST_IS_BUFFER (buf)) {
    /*  This is already an SMD buffer.  Life is good. */
    ismd_gst_element_sink_chain_smd_buffer (smd_element, pad, buf, is_video);
  } else if (buf->parent != NULL && ISMD_GST_IS_BUFFER (buf->parent)) {
    GST_DEBUG_OBJECT (smd_element, "Received a subbuffer of an ISMD buffer. Copying parent and continuing.");
    GstBuffer *buf_new = gst_buffer_copy (buf->parent);
    gst_buffer_copy_metadata (buf_new, buf, GST_BUFFER_COPY_ALL);
    ismd_gst_element_sink_chain_smd_buffer (smd_element, pad, buf_new, is_video);
  } else if (is_video) {
    /* Copy to an SMD frame buffer and send it. */
    ismd_gst_element_sink_chain_image_gst_buffer (smd_element, pad, buf);
  } else {
    /* just a generic buffer.  Copy to an SMD buffer and send it. */
    ismd_gst_element_sink_chain_gst_buffer (smd_element, pad, buf, joinable);
    buf = NULL;
  }

beach:
  if (buf)
    gst_buffer_unref (buf);
  /* Propagaut upstream last flow status value */
  GST_OBJECT_LOCK (smd_element);
  ret = smd_element->last_ret;
  GST_LOG_OBJECT (smd_element, "returning %s", gst_flow_get_name (ret));
  GST_OBJECT_UNLOCK (smd_element);

  gst_object_unref (smd_element);
  return ret;

flushing:
  GST_DEBUG_OBJECT (smd_element, "flushing, dropping received buffer");
  gst_buffer_unref (buf);
  gst_object_unref (smd_element);
  return GST_FLOW_WRONG_STATE;
}

static gboolean
ismd_gst_element_sink_event (GstPad * pad, GstEvent * event)
{
  gboolean ret = TRUE;
  ismd_result_t result;
  ISmdGstElement *smd_element;
  ISmdGstElementClass *klass;
  gboolean update;
  gdouble rate;
  GstFormat format;
  gint64 start;
  gint64 stop;
  gint64 position;
  gboolean is_playing = FALSE;
  GstState current_state;
  ISmdGstElementSinkPad *pad_node_data = NULL; 

  smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent (pad));
  pad_node_data = ismd_gst_element_get_sink_pad_nodedata(smd_element, ISMD_GST_PAD(pad));

  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));
  current_state = GST_STATE (smd_element);

  if (current_state == GST_STATE_PLAYING) {
    GST_DEBUG_OBJECT (smd_element, "is in PLAY state");
    is_playing = TRUE;
  }

  GST_DEBUG_OBJECT (smd_element, "handling event %s",
      GST_EVENT_TYPE_NAME (event));

  /* First drain our adapter */
  if (GST_EVENT_IS_SERIALIZED (event)) {
    adapter_drain (smd_element, pad_node_data);
  }
  /* Call the sink_event function of child class if available */
  if (klass->event) {
    ret = klass->event (smd_element, event);
    if (!ret) {
      gst_event_unref (event);
      ret = TRUE;
      goto beach;
    }
  }
  /* Drain again because the subclass might have added some data */
  if (GST_EVENT_IS_SERIALIZED (event)) {
    adapter_drain (smd_element, pad_node_data);
  }

  switch (event->type) {
    case GST_EVENT_NEWSEGMENT:
      gst_event_parse_new_segment (event, &update, &rate, &format, &start,
          &stop, &position);

      if (format == GST_FORMAT_TIME) {
        GST_INFO_OBJECT (smd_element, "received new segment update %d rate %f "
            "start %" GST_TIME_FORMAT " stop %" GST_TIME_FORMAT
            " position %" GST_TIME_FORMAT, update, rate,
            GST_TIME_ARGS (start), GST_TIME_ARGS (stop),
            GST_TIME_ARGS (position));
      }
      else {
        GST_INFO_OBJECT (smd_element, "received new segment format %u update %d"
            " rate %f start %" G_GUINT64_FORMAT " stop %" G_GUINT64_FORMAT
            " position %" G_GUINT64_FORMAT,
            format, update, rate, start, stop, position);
        format = GST_FORMAT_TIME;
        start = 0;
        stop = GST_CLOCK_TIME_NONE;
        position = 0;
      }

      GST_INFO_OBJECT (smd_element, "Our segment was %" GST_SEGMENT_FORMAT,
          &smd_element->segment);
      gst_segment_set_newsegment (&smd_element->segment, update, rate, format,
          start, stop, position);
      GST_INFO_OBJECT (smd_element,
          "Our segment now is %" GST_SEGMENT_FORMAT, &smd_element->segment);

      /* Reset the last flow return */
      ismd_gst_element_reset_flow (smd_element);

      if (update) {
        if (!klass->is_sink) {
          /* Permit the new segment updates being sent out of band because
           * we don't have a good way to serialize them.
           * It shouldn't be very dangerous and fixes playback of a loop */
          /* ismd_gst_element_drain (smd_element); */
          GST_DEBUG_OBJECT (smd_element, "pushing NEW SEGMENT update");
          ret = gst_pad_event_default (pad, event);
        } else {
          gst_event_unref (event);
        }
        smd_element->send_newsegment = FALSE;
      } else {
        /* Non update new segment events are tagged in the buffers */
        smd_element->send_newsegment = TRUE;
        gst_event_unref (event);
      }
      break;
    case GST_EVENT_FLUSH_START:
      /* Flush any data buffered in the device */
      GST_OBJECT_LOCK (smd_element);
      smd_element->is_flushing = TRUE;
      smd_element->stop_writing_data = TRUE;
      GST_OBJECT_UNLOCK (smd_element);

      GST_DEBUG_OBJECT (smd_element, "unblock input loop");
      result = ismd_event_strobe (ISMD_GST_PAD(pad)->sink_pad_event);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "ismd_event_strobe failed(%d)", result);
      }

      if (smd_element->event_loop != NULL) {        
        gst_task_pause (smd_element->event_loop);
        GST_DEBUG_OBJECT (smd_element, "unblock output loop");
        /* wake up the data producer */
        result = ismd_event_strobe (smd_element->src_pad_event);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (smd_element, "ismd_event_strobe failed(%d)", result);
        }
      }

      /* Flush the adapter */
      adapter_reset (smd_element, pad_node_data);

      ismd_gst_pad_port_stats (ISMD_GST_PAD(pad));
      GST_DEBUG_OBJECT (smd_element, "pausing and flushing device %d",
          smd_element->dev_handle);
      result = klass->dev_ops.set_state (smd_element->dev_handle,
          ISMD_DEV_STATE_PAUSE);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "ismd_dev_set_state failed(%d)", result);
      }
      if (klass->is_sink) {
        GST_OBJECT_LOCK (smd_element);
        /* and we need to commit our state again on the next buffer */
        smd_element->playing_async = TRUE;
        smd_element->need_preroll = TRUE;
        smd_element->prerolled = FALSE;
        GST_OBJECT_UNLOCK (smd_element);

        gst_element_lost_state (GST_ELEMENT_CAST (smd_element));
        GST_DEBUG_OBJECT (smd_element, "setting the element in lost state");
        gst_event_unref (event);
        ret = TRUE;
      }
      else {
        GST_DEBUG_OBJECT (smd_element, "pushing FLUSH_START downstream");
        ret = gst_pad_event_default (pad, event);
      }      
      break;
    case GST_EVENT_FLUSH_STOP:
      /* Reset the last flow return */
      ismd_gst_element_reset_flow (smd_element);
      ismd_gst_pad_port_stats (ISMD_GST_PAD(pad));
      /* Flush the device */
      GST_DEBUG_OBJECT (smd_element, "flushing device");
      result = klass->dev_ops.flush (smd_element->dev_handle);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "flush failed(%d)", result);
      }
      ismd_gst_pad_port_stats (ISMD_GST_PAD(pad));

      GST_OBJECT_LOCK (smd_element);
      smd_element->is_flushing = FALSE;
      smd_element->stop_writing_data = FALSE;
      smd_element->need_new_seq_hdr = TRUE;
      smd_element->next_client_id = 0;
      gst_segment_init (&smd_element->segment, GST_FORMAT_TIME);
      GST_OBJECT_UNLOCK (smd_element);


      if (smd_element->event_loop != NULL &&
            GST_STATE (smd_element) > GST_STATE_READY) {
        GST_DEBUG_OBJECT (smd_element, "wake up the event loop");
        gst_task_start (smd_element->event_loop);
        /* wake up the data producer */
        result = ismd_event_strobe (smd_element->src_pad_event);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (smd_element, "ismd_event_strobe failed(%d)", result);
        }
      }

      if (klass->is_sink) {
        /* Call the sink_event function of child class if available again
         * to let vidrend sink restore the base_time */
        if (klass->event) {
          klass->event (smd_element, event);
        }

        gst_event_unref (event);
        ret = TRUE;
      } else {
        GST_DEBUG_OBJECT (smd_element, "pushing FLUSH_STOP downstream");
        ret = gst_pad_event_default (pad, event);
        if (GST_STATE (smd_element) == GST_STATE_PLAYING) {
          GST_DEBUG_OBJECT (smd_element, "back to PLAYING state");
          result = klass->dev_ops.set_state (smd_element->dev_handle,
              ISMD_DEV_STATE_PLAY);
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d",
                result);
          }
        }
      }
      break;
    case GST_EVENT_EOS:
      if (klass->is_sink && !klass->is_decoder) {
        /* In PR13 pushing a ismd_buffer with the eos tag set causes deadlocks
         * in ismd_vidrend_sink teardown */
        ismd_gst_element_drain (smd_element, ISMD_GST_PAD(pad));
        GST_DEBUG_OBJECT (smd_element, "Posting EOS message");
        if (!gst_element_post_message (GST_ELEMENT (smd_element),
                gst_message_new_eos (GST_OBJECT (smd_element)))) {
          GST_ERROR_OBJECT (smd_element, "Couldn't post sink EOS message");
        }
        gst_event_unref (event);
        ret = TRUE;
      }
      else if (!ismd_gst_element_send_eos (pad)) {
        ismd_gst_element_drain (smd_element, ISMD_GST_PAD(pad));
        if (klass->is_sink) {
          GST_DEBUG_OBJECT (smd_element, "Posting EOS message");
          if (!gst_element_post_message (GST_ELEMENT (smd_element),
                  gst_message_new_eos (GST_OBJECT (smd_element)))) {
            GST_ERROR_OBJECT (smd_element, "Couldn't post sink EOS message");
          }
          gst_event_unref (event);
          ret = TRUE;
        }
        else {
          GST_DEBUG_OBJECT (smd_element, "pushing EOS downstream");
          ret = gst_pad_event_default (pad, event);
        }
      }
      else { /* Dispose of the event */
        GST_DEBUG_OBJECT (smd_element, "dropping EOS");
        gst_event_unref (event);
      }
      break;
    case GST_EVENT_CUSTOM_DOWNSTREAM:
      if (klass->is_sink) {
        gst_event_unref (event);
        ret = TRUE;
      } else {
        ismd_gst_element_drain (smd_element, ISMD_GST_PAD(pad));
        GST_DEBUG_OBJECT (smd_element, "pushing CUSTOM downstream");
        ret = gst_pad_event_default (pad, event);
      }
      break;
#if GST_CHECK_VERSION(0,10,26)
    case GST_EVENT_SINK_MESSAGE:
    {
      if (klass->is_sink) {
        GstMessage *msg = NULL;

        gst_event_parse_sink_message (event, &msg);

        if (msg)
          gst_element_post_message (GST_ELEMENT_CAST (smd_element), msg);
      }
    }
#endif
    default:
      if (klass->is_sink) {
        gst_event_unref (event);
        ret = TRUE;
      } else {
        GST_DEBUG_OBJECT (smd_element, "pushing %s downstream",
            GST_EVENT_TYPE_NAME (event));
        ret = gst_pad_event_default (pad, event);
      }
      break;
  }

beach:
  gst_object_unref (smd_element);
  return ret;
}

#if 0
/* TODO: Create an element to pull back ISMD buffers into raw */
static inline void
ismd_gst_element_pull_i420 (ISmdGstElement * smd_element, GstBuffer ** buf,
    ismd_buffer_handle_t smd_buf_handle, ismd_buffer_descriptor_t smd_buf_desc)
{
  GstCaps *caps;
  ismd_result_t result;
  ismd_frame_attributes_t *attr =
      (ismd_frame_attributes_t *) & (smd_buf_desc.attributes);
  guint8 *dest_y_ptr, *dest_u_ptr, *dest_v_ptr;
  int line;
  int dest_y_stride, dest_y_height, dest_y_width;
  int dest_uv_stride, dest_uv_height, dest_uv_width;
  int src_y_stride, src_uv_height, src_uv_width, src_uv_stride;
  int buffer_size;
  guint8 *virt_y, *virt_uv;

  dest_y_stride = GST_ROUND_UP_4 (attr->cont_size.width);
  dest_y_height = attr->cont_size.height;
  dest_y_width = attr->cont_size.width;
  dest_uv_stride = GST_ROUND_UP_4 (GST_ROUND_UP_2 (attr->cont_size.width) / 2);
  dest_uv_height = GST_ROUND_UP_2 (attr->cont_size.height) / 2;
  dest_uv_width = attr->cont_size.width / 2;
  src_y_stride = smd_element->system_stride;
  src_uv_height = GST_ROUND_UP_2 (attr->cont_size.height) / 2;
  src_uv_width = GST_ROUND_UP_2 (attr->cont_size.width) / 2;

  if (attr->pixel_format == ISMD_PF_NV12) {
    src_uv_stride = smd_element->system_stride;
  } else if (attr->pixel_format == ISMD_PF_NV16) {
    src_uv_stride = smd_element->system_stride * 2;
  } else {
    GST_WARNING_OBJECT (smd_element,
        "unsupported format, buffer will be discarded");
    *buf = NULL;
    goto beach;
  }

  buffer_size =
      (dest_y_stride * dest_y_height) + (2 * (dest_uv_stride * dest_uv_height));
  *buf = gst_buffer_new_and_alloc (buffer_size + 16);
  GST_BUFFER_DATA (*buf) += (uintptr_t) GST_BUFFER_DATA (*buf) % 16;
  GST_BUFFER_SIZE (*buf) = buffer_size;

  dest_y_ptr = GST_BUFFER_DATA (*buf);
  dest_u_ptr = GST_BUFFER_DATA (*buf) + (dest_y_height * dest_y_stride);
  dest_v_ptr = dest_u_ptr + (dest_uv_height * dest_uv_stride);

  virt_y =
      OS_MAP_IO_TO_MEM_NOCACHE (smd_buf_desc.phys.base, smd_buf_desc.phys.size);
  virt_uv = virt_y + attr->u;

  for (line = 0; line < dest_y_height; line++) {
#if 0
    memcpy_nt_2 (dest_y_ptr + (line * dest_y_stride),
        (virt_y + (line * src_y_stride)),
        ROUND_UP (dest_y_width, CACHE_LINE_SIZE));
#endif
    memcpy (dest_y_ptr + (line * dest_y_stride),
        (virt_y + (line * src_y_stride)), dest_y_width);
  }

  /* Copy UV Data */
  //g_print("copy uv data");
  unpack_uv (dest_u_ptr, dest_v_ptr, dest_uv_stride,
      dest_uv_stride, virt_uv, src_uv_stride, src_uv_width, src_uv_height);

  OS_UNMAP_IO_FROM_MEM (virt_y, smd_buf_desc.phys.size);

  caps = gst_caps_new_simple ("video/x-raw-yuv",
      "format", GST_TYPE_FOURCC, GST_MAKE_FOURCC ('I', '4', '2', '0'),
      "width", G_TYPE_INT, (int) dest_y_width,
      "height", G_TYPE_INT, (int) dest_y_height, NULL);

  gst_buffer_set_caps (*buf, caps);
  gst_caps_unref (caps);

  /*
   * Get PTS and put as time stamp
   */
  if (attr->original_pts != ISMD_NO_PTS) {
    GST_BUFFER_TIMESTAMP (*buf) = SMD_TO_GST_TIME (attr->original_pts);
    GST_DEBUG_OBJECT (smd_element, "STD buffer %p with pts %" GST_TIME_FORMAT
        " and smd.pts %llu",
        *buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (*buf)),
        (unsigned long long) attr->original_pts);
  }

beach:
  /* Since data copied, free ismd_buffer */
  result = ismd_buffer_dereference (smd_buf_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "freeing ismd_buffer %d failed",
        smd_buf_handle);
  }
}
#endif

static inline void
ismd_gst_element_pull_other (ISmdGstElement * smd_element, GstBuffer ** buf,
    ismd_buffer_handle_t smd_buf_handle, ismd_buffer_descriptor_t smd_buf_desc)
{
  ismd_es_buf_attr_t *attr;
  ismd_result_t result;
  char *dataptr;
  *buf = gst_buffer_new_and_alloc (smd_buf_desc.phys.level);
  GST_DEBUG_OBJECT (smd_element, "allocated buffer of size %d",
      smd_buf_desc.phys.level);

  /* Map and copy the data into a gstreamer buffer */
  dataptr = OS_MAP_IO_TO_MEM_NOCACHE (smd_buf_desc.phys.base,
      smd_buf_desc.phys.level);
  memcpy (GST_BUFFER_DATA (*buf), dataptr, smd_buf_desc.phys.level);
  OS_UNMAP_IO_FROM_MEM (dataptr, smd_buf_desc.phys.level);

  GST_BUFFER_SIZE (*buf) = smd_buf_desc.phys.level;

  attr = (ismd_es_buf_attr_t *) smd_buf_desc.attributes;

  /* Get PTS and put as time stamp */
  if (attr->original_pts != ISMD_NO_PTS) {
    GST_BUFFER_TIMESTAMP (*buf) = SMD_TO_GST_TIME (attr->original_pts);
    GST_DEBUG_OBJECT (smd_element, "STD buffer %p with pts %" GST_TIME_FORMAT
        " and smd.pts %llu",
        *buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (*buf)),
        (unsigned long long) attr->original_pts);
  }

  /* Since data copied, free ismd_buffer */
  result = ismd_buffer_dereference (smd_buf_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "freeing ismd_buffer %d failed",
        smd_buf_handle);
  }
}

static inline gboolean
video_props_is_equal (ismd_viddec_stream_properties_t * vp1,
    ismd_viddec_stream_properties_t * vp2)
{
  gboolean ret = TRUE;

  ret &= (vp1->frame_rate_num == vp2->frame_rate_num);
  ret &= (vp1->frame_rate_den == vp2->frame_rate_den);
  ret &= (vp1->coded_height == vp2->coded_height);
  ret &= (vp1->coded_width == vp2->coded_width);
  ret &= (vp1->display_height == vp2->display_height);
  ret &= (vp1->display_width == vp2->display_width);
  ret &= (vp1->sample_aspect_ratio.numerator ==
            vp2->sample_aspect_ratio.numerator);
  ret &= (vp1->sample_aspect_ratio.denominator ==
            vp2->sample_aspect_ratio.denominator);
  return ret;
}


static GstFlowReturn
ismd_gst_element_try_push (ISmdGstElement * smd_element,
    GstPad * pad, ismd_buffer_handle_t buf_handle)
{
  GstFlowReturn ret = GST_FLOW_UNEXPECTED;
  GstBuffer *buf = NULL;
  GstCaps *out_caps = NULL;
  gboolean is_flushing;
  ismd_result_t result;
  ismd_newsegment_tag_t newsegment;
  ismd_buffer_descriptor_t buf_desc;
  ISmdGstElementClass *klass;
  gint client_id;
  gboolean on_eos = FALSE;
  klass = ISMD_GST_ELEMENT_CLASS (GST_ELEMENT_GET_CLASS (smd_element));

  /* If some data is available read the description of it */
  memset (&buf_desc, 0, sizeof (buf_desc));
  result = ismd_buffer_read_desc (buf_handle, &buf_desc);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "ismd_buffer_read_desc failed(%d)", result);
    goto drop;
  }

  /* Check client id (buffer's serial number) */
  result = ismd_tag_get_client_id (buf_handle, &client_id);
  if (result != ISMD_SUCCESS) {
    GST_DEBUG_OBJECT (smd_element, "Got buffer with no client-id (error %d)",
        result);
  } else {
    GST_DEBUG_OBJECT (smd_element, "Got buffer with client-id %d", client_id);
  }

  /* Check for EOS mark */
  result = ismd_tag_get_eos (buf_handle);
  if (result == ISMD_SUCCESS) {
    GST_DEBUG_OBJECT (smd_element, "Got buffer with EOS");
    on_eos = TRUE;
    goto drop;
  }

  /* Check for newsegment */
  result = ismd_tag_get_newsegment (buf_handle, &newsegment);
  if (result == ISMD_SUCCESS) {
    GstEvent *event;
    GST_DEBUG_OBJECT (smd_element,
        "ismd NEWSEGMENT received start %llu (0x%llx) "
        "stop %lld linear_start %llu requested_rate %d applied_rate %d",
        newsegment.start, newsegment.start,
        newsegment.stop, newsegment.linear_start,
        newsegment.requested_rate, newsegment.applied_rate);
    /* Create a new newsegment event with the parameters from
     * the ISMD newsegment */
    event = gst_event_new_new_segment_full (FALSE, /* not an update */
        SMD_TO_GST_RATE (newsegment.requested_rate),
        SMD_TO_GST_RATE (newsegment.applied_rate),
        GST_FORMAT_TIME,
        SMD_TO_GST_TIME (newsegment.start),
        SMD_TO_GST_TIME (newsegment.stop),
        SMD_TO_GST_TIME (newsegment.linear_start)
        );
    /* Push the event */
    gst_pad_push_event (pad, event);
  }

  /* Check if need to be flushed */
  GST_OBJECT_LOCK (smd_element);
  is_flushing = smd_element->is_flushing;
  GST_OBJECT_UNLOCK (smd_element);

  if (is_flushing) {
    GST_DEBUG_OBJECT (smd_element, "flushing");
    ret = GST_FLOW_WRONG_STATE;
    goto drop;
  }

  out_caps = gst_pad_get_negotiated_caps (pad);
  if (G_UNLIKELY (!GST_IS_CAPS (out_caps))) {
    GST_ERROR_OBJECT (pad, "src pad has not negotiated caps");
    goto drop;
  }

  if ( klass->is_decoder && !klass->is_sink && !klass->is_audio_decoder) {
    ismd_viddec_stream_properties_t video_props;
    result = ismd_viddec_get_stream_properties (smd_element->dev_handle,
        &video_props);
    if (result == ISMD_SUCCESS) {
      GST_LOG_OBJECT (smd_element, "w: %lu h: %lu cw: %lu ch: %lu "
          "fps_n: %lu fps_d: %lu par_n: %u par_d: %u",
          video_props.display_width, video_props.display_height,
          video_props.coded_width, video_props.coded_height,
          video_props.frame_rate_num, video_props.frame_rate_den,
          video_props.sample_aspect_ratio.numerator,
          video_props.sample_aspect_ratio.denominator);

      if (!video_props_is_equal (&smd_element->video_props, &video_props)) {
        GstCaps * new_caps = gst_caps_copy (out_caps);
        memcpy (&smd_element->video_props, &video_props,
            sizeof (ismd_viddec_stream_properties_t));

        if (video_props.coded_width != 0 &&
            video_props.coded_height != 0) {
          gst_caps_set_simple (new_caps,
              "width", G_TYPE_INT, video_props.coded_width,
              "height", G_TYPE_INT, video_props.coded_height, NULL);
        }

        if (video_props.frame_rate_den != 0) {
          gst_caps_set_simple (new_caps, "framerate", GST_TYPE_FRACTION,
              video_props.frame_rate_num, video_props.frame_rate_den, NULL);
        }
        else {
          gst_caps_set_simple (new_caps, "framerate", GST_TYPE_FRACTION,
              30, 1, NULL);
        }

        if (smd_element->par_x != 0 && smd_element->par_y != 0) {
          gst_caps_set_simple (new_caps, "pixel-aspect-ratio",
              GST_TYPE_FRACTION,
              smd_element->par_x,
              smd_element->par_y, NULL);
        } else if (video_props.sample_aspect_ratio.denominator != 0) {
          gst_caps_set_simple (new_caps, "pixel-aspect-ratio",
              GST_TYPE_FRACTION,
              video_props.sample_aspect_ratio.numerator,
              video_props.sample_aspect_ratio.denominator, NULL);
        }
        else {
          gst_caps_set_simple (new_caps, "pixel-aspect-ratio",
              GST_TYPE_FRACTION, 1, 1, NULL);
        }
        GST_DEBUG_OBJECT (pad, "setting caps downstream with %" GST_PTR_FORMAT,
            new_caps);
        if (gst_pad_set_caps (pad, new_caps)) {
          /* We want to use this new caps to alloc a buffer */
          gst_caps_replace (&out_caps, new_caps);
        }
        else {
          GST_WARNING_OBJECT (smd_element, "failed setting caps on src pad");
        }
        /* Don't need this ref anymore */
        gst_caps_unref (new_caps);
      }
    } else {
      GST_ERROR_OBJECT (smd_element,
          "ismd_viddec_get_stream_properties failed(%d)", result);
    }
  }

  /* Check if it's a Video frame and process it */
  if (buf_desc.buffer_type == ISMD_BUFFER_TYPE_VIDEO_FRAME) {
    ISmdGstBuffer *ismd_buf = ismd_gst_buffer_new ();
    ismd_frame_attributes_t *attr =
        (ismd_frame_attributes_t *) & (buf_desc.attributes);
    ismd_time_t pts = ISMD_NO_PTS;

    if (smd_element->par_x != 0 && smd_element->par_y != 0) {
      attr->cont_ratio.numerator = smd_element->par_x;
      attr->cont_ratio.denominator = smd_element->par_y;
      result = ismd_buffer_update_desc (buf_desc.unique_id, &buf_desc);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element,
          "failed to update ISMD descriptor for PAR value");
      }
    }
    ismd_buf->ismd_buffer_id = buf_handle;
    buf = GST_BUFFER_CAST (ismd_buf);
    if (attr->original_pts != ISMD_NO_PTS) {
      pts = attr->original_pts;
    } else {
      pts = attr->local_pts;
    }
    if (pts != ISMD_NO_PTS) {
      GST_BUFFER_TIMESTAMP (buf) = SMD_TO_GST_TIME (pts);
      GST_BUFFER_DURATION (buf) = GST_CLOCK_TIME_NONE;
    }
    GST_LOG_OBJECT (smd_element, "created ISMD video buffer %p with pts %"
        GST_TIME_FORMAT " and smd.original_pts %llu smd.local_pts %llu",
        buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)),
        (unsigned long long) attr->original_pts,
        (unsigned long long) attr->local_pts);
#if 0
    GST_LOG_OBJECT (smd_element, "original_pts %llu (%" GST_TIME_FORMAT ") "
        "local_pts %llu (%" GST_TIME_FORMAT ") "
        "cont_ratio %d/%d cont_rate %d",
        (unsigned long long) attr->original_pts,
        GST_TIME_ARGS (SMD_TO_GST_TIME (attr->original_pts)),
        (unsigned long long) attr->local_pts,
        GST_TIME_ARGS (SMD_TO_GST_TIME (attr->local_pts)),
        attr->cont_ratio.numerator, attr->cont_ratio.denominator,
        attr->cont_rate);
#endif
    gst_buffer_set_caps (buf, out_caps);
  } else if (buf_desc.phys.level) {
    /* When isn't video just generate an standard GstBuffer and copy
     * the data on it */
    ismd_gst_element_pull_other (smd_element, &buf, buf_handle, buf_desc);

   if(klass->is_vidio_enc) {
	 ismd_es_buf_attr_t *attr = 
		 (ismd_es_buf_attr_t *) & (buf_desc.attributes);
	 ismd_time_t pts = ISMD_NO_PTS;
	 uint32_t bit_rate = ISMD_INVALID_BIT_RATE;
	
	 if (attr->original_pts != ISMD_NO_PTS) {
		 pts = attr->original_pts;
	   } else {
		 pts = attr->local_pts;
	 }
	
	 if(pts != ISMD_NO_PTS) 
	 {
	   bit_rate = ((ismd_es_buf_attr_t *) & (buf_desc.attributes))->bit_rate;
	
		 // If bitrate is valid, use new. Otherwise use last valid bitrate.
	   if(bit_rate != ISMD_INVALID_BIT_RATE)
	     smd_element->video_bitrate = bit_rate; 

	   if(!buf->_gst_reserved[0])
	      buf->_gst_reserved[0] = (void *)(smd_element->video_bitrate);
	   }
	 }

    GST_LOG_OBJECT (smd_element, "created buffer %p with pts %"
        GST_TIME_FORMAT,
        buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)));
  }
  else {
    /* This is an empty buffer, discard it, but do not return ERROR */
    ret = GST_FLOW_OK;
    goto drop;
  }

  if (G_LIKELY (buf)) {
    gst_buffer_set_caps (buf, out_caps);
    if (klass->push_buffer) {
      ret = klass->push_buffer (smd_element, pad, buf);
    } else {
      GST_LOG_OBJECT (pad, "pushing buffer %p", buf);
      ret = gst_pad_push (pad, buf);
    }
  }

beach:
  if (out_caps)
    gst_caps_unref (out_caps);

  return ret;

drop:
  GST_LOG_OBJECT (pad, "dropping ismd buffer %d", buf_handle);
  result = ismd_buffer_dereference (buf_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (smd_element, "freeing ismd_buffer failed(%d)", result);
  }

  if (on_eos) {
    gboolean is_playing = (GST_STATE (smd_element) == GST_STATE_PLAYING);
    GST_LOG_OBJECT (pad, "forwarding EOS to next element");
    result = klass->dev_ops.set_state (smd_element->dev_handle, ISMD_DEV_STATE_STOP);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d", result);
    }

    result = klass->dev_ops.set_state (smd_element->dev_handle,
        (is_playing ? ISMD_DEV_STATE_PLAY : ISMD_DEV_STATE_PAUSE));
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d", result);
    }

    gst_pad_push_event (pad, gst_event_new_eos());
  }

  goto beach;
}

/* Next must be called with the list pad lock taken */
static GstFlowReturn
ismd_gst_element_combine_flows (ISmdGstElement * smd_element, ISmdGstPad * pad,
    GstFlowReturn ret)
{
  GList * walk = NULL;

  /* store last result */
  pad->last_ret = ret;

  /* if it's success we can return the value right away */
  if (GST_FLOW_IS_SUCCESS (ret))
    goto done;

  /* any other error that is not-linked can be returned right
   * away */
  if (ret != GST_FLOW_NOT_LINKED)
    goto done;

  /* only return NOT_LINKED if all other pads returned NOT_LINKED */
  for (walk = smd_element->src_pads; walk; walk = g_list_next (walk)) {
    ISmdGstPad * opad = ISMD_GST_PAD (walk->data);

    ret = opad->last_ret;
    GST_DEBUG_OBJECT (pad, "last_ret %s", gst_flow_get_name (ret));
    /* some other return value (must be SUCCESS but we can return
     * other values as well) */
    if (ret != GST_FLOW_NOT_LINKED)
      goto done;
  }
  /* if we get here, all other pads were unlinked and we return
   * NOT_LINKED then */
done:
  return ret;
}

static inline void
ismd_gst_element_reset_flow (ISmdGstElement * smd_element)
{
  GList * walk = NULL;
  smd_element->last_ret = GST_FLOW_OK;
  g_mutex_lock (smd_element->pad_list_mutex);
  for (walk = smd_element->src_pads; walk; walk = g_list_next (walk)) {
    ISmdGstPad * pad = ISMD_GST_PAD (walk->data);
    pad->last_ret = GST_FLOW_OK;
  }
  g_mutex_unlock (smd_element->pad_list_mutex);
}

static gboolean
ismd_gst_element_send_event (ISmdGstElement * smd_element, GstEvent * event)
{
  GList * walk = NULL;
  gboolean ret = FALSE;

  g_return_val_if_fail (GST_IS_EVENT (event), FALSE);

  g_mutex_lock (smd_element->pad_list_mutex);
  for (walk = smd_element->src_pads; walk; walk = g_list_next (walk)) {
    GstPad * pad = GST_PAD (walk->data);
    event = gst_event_ref (event);
    GST_DEBUG_OBJECT (pad, "pushing %s event", GST_EVENT_TYPE_NAME (event));
    if (!gst_pad_push_event (pad, event)) {
      GST_DEBUG_OBJECT (pad, "event %s was not handled correctly",
        GST_EVENT_TYPE_NAME (event));
    }
    else {
      /* If at least one push returns TRUE, then we return TRUE. */
      ret = TRUE;
      GST_DEBUG_OBJECT (pad, "event %s was handled correctly",
        GST_EVENT_TYPE_NAME (event));
    }

  }
  g_mutex_unlock (smd_element->pad_list_mutex);
  gst_event_unref (event);
  return ret;
}

static void
ismd_gst_element_event_loop (ISmdGstElement * smd_element)
{
  gboolean data_written = FALSE;
  GstFlowReturn cret = GST_FLOW_OK, ret = GST_FLOW_OK;

  GList *walk = NULL;
  ismd_result_t result;
  ismd_buffer_handle_t buf_handle;
  GList *padlist_sink = smd_element->sink_pads;
  ISmdGstElementSinkPad *pad_node_data = NULL; 

  g_mutex_lock (smd_element->pad_list_mutex);
  if (g_list_length (smd_element->src_pads) == 0)
    goto beach;

  walk = smd_element->src_pads;
  /* This event loop read data from an SMD src port and pushes it downstream */
  while (walk && ret > GST_FLOW_WRONG_STATE) {
    GstPad *pad = GST_PAD (walk->data);
    ismd_port_handle_t port = (ISMD_GST_PAD (pad))->ismd_port;

    result = ismd_port_read (port, &buf_handle);
    if (result != ISMD_SUCCESS) {
      GST_LOG_OBJECT (smd_element, "ismd_port_read failed(%d) on port %d",
          result, port);
    }
    else {
      ret = ismd_gst_element_try_push (smd_element, pad, buf_handle);
      cret = ismd_gst_element_combine_flows (smd_element, ISMD_GST_PAD (pad), ret);
      data_written = TRUE;
    }
    walk = g_list_next (walk);
  }

beach:
  g_mutex_unlock (smd_element->pad_list_mutex);

  /* If we are a source handle the flow return value here*/

  /* For support two-sink pads */
  if ((padlist_sink = g_list_next (padlist_sink)) != NULL) {
      pad_node_data =  padlist_sink->data;
   }
  
  if (!smd_element->sink_pad && pad_node_data->sink_pad &&
      (GST_FLOW_IS_FATAL (cret) || cret == GST_FLOW_NOT_LINKED)) {
    const gchar *reason = gst_flow_get_name (cret);

    GST_LOG_OBJECT (smd_element, "pausing task, reason %s", reason);
    gst_task_stop (smd_element->event_loop);

    GST_LOG_OBJECT (smd_element, "sending EOS");
    ismd_gst_element_send_event (smd_element, gst_event_new_eos ());

    data_written = TRUE; /* We don't want to stay waiting for more data */
  }

  /* Udate last_ret */
  GST_OBJECT_LOCK (smd_element);
  smd_element->last_ret = cret;
  GST_LOG_OBJECT (smd_element, "returning %s", gst_flow_get_name (cret));
  GST_OBJECT_UNLOCK (smd_element);

  /* If for whatever reason, we couldn't ship data out from this SMD output port
     to the downstream GST element, then we block and wait for an event to
     notify us that something has entered the output port's queue.  This will
     allow us to try again (GstTask will call event_loop again) */
  if (!data_written) {
    GST_LOG_OBJECT (smd_element, "wait for more data");
    ismd_event_wait (smd_element->src_pad_event, ISMD_TIMEOUT_NONE);
    ismd_event_acknowledge (smd_element->src_pad_event);
    GST_LOG_OBJECT (smd_element, "SMD port just got some data");
  }
}

static gboolean
ismd_gst_element_set_clock (GstElement * element, GstClock * clock)
{
  if (ISMD_GST_IS_CLOCK (clock)) {
    ISmdGstClock *smd_clock = ISMD_GST_CLOCK (clock);
    GST_INFO_OBJECT (element, "Received SMD clock %p (ID:%d)",
        smd_clock, smd_clock->dev_handle);
  } else {
    GST_INFO_OBJECT (element, "Received Non SMD clock");
  }
  return TRUE;
}

static GstPadLinkReturn
ismd_src_link_function (GstPad * pad, GstPad * peer)
{
  ismd_result_t result;
  GstStateChangeReturn ret;
  GstState state, pending;
  ISmdGstElement *smd_element;

  smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent (pad));

  ret = gst_element_get_state (GST_ELEMENT (smd_element), &state, &pending,
      GST_CLOCK_TIME_NONE);

  if (ret == GST_STATE_CHANGE_FAILURE) {
    GST_WARNING_OBJECT (pad, "Cannot link pad in current state");
    gst_object_unref (smd_element);
    return GST_PAD_LINK_REFUSED;
  }

  switch (state) {
    case GST_STATE_READY:
    case GST_STATE_PAUSED:
    case GST_STATE_PLAYING:
      GST_DEBUG_OBJECT (pad,
          "In GST_STATE_READY / GST_STATE_PAUSED / GST_STATE_PLAYING state");
      GST_DEBUG_OBJECT (pad, "trying to connect with %" GST_PTR_FORMAT, peer);
      result = ismd_connect_gst_pads (ISMD_GST_PAD (pad), peer);
      break;
    default:
      GST_DEBUG_OBJECT (pad,
          "no link done - not in READY or PAUSE or PLAYING state");
      //result = ISMD_ERROR_OPERATION_FAILED;
      result = ISMD_SUCCESS;
      break;
  }
  gst_object_unref (smd_element);

  if (result == ISMD_SUCCESS) {
    return GST_PAD_LINK_OK;
  } else {
    return GST_PAD_LINK_REFUSED;
  }
}


static void
ismd_unlink_function (GstPad * gstpad)
{
  ISmdGstPad *pad = ISMD_GST_PAD (gstpad);

  if (pad->is_event_queue_attached) {
    GST_DEBUG_OBJECT (gstpad, "detaching on port %d", pad->ismd_port);
    if (ismd_port_detach (pad->ismd_port) != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (pad, "failed to detach from port %d", pad->ismd_port);
    }
    pad->is_event_queue_attached = FALSE;
  }
}

/* Used by sub-classes to make sink pad and source pad(s) with the proper caps */
void
ismd_gst_element_create_pads (ISmdGstElement * smd_element,
    GstStaticCaps * sink_scaps, GstStaticCaps * source_scaps, guint count)
{
  GstPadTemplate *template;
  ISmdGstPad *pad;
  int i;
  gchar *name;

  name = g_strdup_printf ("sink");

  /* Create the sink pad. */
  template =
      gst_pad_template_new ("sink", GST_PAD_SINK, GST_PAD_ALWAYS,
      gst_static_caps_get (sink_scaps));
  pad = ismd_gst_pad_new_from_template (template, name);
  gst_object_unref (template);
  g_free (name);

  /* Now that we have a sink pad, let everyone know */
  ismd_gst_element_register_sinkpad (smd_element, pad);
  smd_element->sink_pad = pad;
  gst_element_add_pad (GST_ELEMENT (smd_element), GST_PAD (pad));

  template =
      gst_pad_template_new ("src", GST_PAD_SRC, GST_PAD_ALWAYS,
      gst_static_caps_get (source_scaps));

  for (i = 1; i <= count; i++) {
    /* Create the source pad.*/
    name = g_strdup_printf ("src_%d", i);
    pad = ismd_gst_pad_new_from_template (template, name);

    /* Now that we have a source pad, let everyone know */
    ismd_gst_element_register_srcpad (smd_element, pad);
    gst_element_add_pad (GST_ELEMENT (smd_element), GST_PAD (pad));
    g_free (name);
  }
  gst_object_unref (template);
}

/**
* ismd_setup_input_pad:
* @ISmdPad:
*/
void
ismd_setup_input_pad (ISmdGstPad * pad)
{
  ISmdGstElement *smd_element = NULL;
  ismd_result_t result;

  if (pad->ismd_port != ISMD_DEV_HANDLE_INVALID
      && !pad->is_event_queue_attached) {
    smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent (GST_PAD (pad)));
    GST_DEBUG_OBJECT (smd_element, "attaching on port %d", pad->ismd_port);
    result =
        ismd_port_attach (pad->ismd_port,
        pad->sink_pad_event, ISMD_QUEUE_EVENT_NOT_FULL,
        ISMD_QUEUE_WATERMARK_NONE);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (pad, "ismd_port_attach failed (%d) to output port %d",
          result, pad->ismd_port);
    } else {
      pad->is_event_queue_attached = TRUE;
    }

    if (smd_element)
      gst_object_unref (smd_element);
  }
}

/**
* ismd_setup_output_pad:
* @ISmdPad:
*/
void
ismd_setup_output_pad (ISmdGstPad * pad)
{
  ISmdGstElement *smd_element = NULL;
  ismd_result_t result;
  if (pad->ismd_port != ISMD_DEV_HANDLE_INVALID
      && !pad->is_event_queue_attached) {
    smd_element = ISMD_GST_ELEMENT (gst_pad_get_parent (GST_PAD (pad)));
    GST_DEBUG_OBJECT (smd_element, "attaching on port %d", pad->ismd_port);
    result =
        ismd_port_attach (pad->ismd_port, smd_element->src_pad_event,
        ISMD_QUEUE_EVENT_ALWAYS, ISMD_QUEUE_WATERMARK_NONE);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (pad, "ismd_port_attach failed (%d) to output port %d",
          result, pad->ismd_port);
    } else {
      pad->is_event_queue_attached = TRUE;
    }

    if (smd_element->event_loop == NULL) {
      if (ismd_event_alloc (&smd_element->src_pad_event) != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (smd_element, "Cannot allocate src pad event!");
      }

      smd_element->event_loop_mutex = g_new0 (GStaticRecMutex, 1);
      g_static_rec_mutex_init (smd_element->event_loop_mutex);
      GST_DEBUG_OBJECT (smd_element, "creating task ismd_gst_element_event_loop");
      smd_element->event_loop =
          gst_task_create ((GstTaskFunction) ismd_gst_element_event_loop,
          smd_element);
      gst_task_set_lock (smd_element->event_loop, smd_element->event_loop_mutex);

      GST_DEBUG_OBJECT (smd_element, "starting Event Loop task");
      gst_task_start (smd_element->event_loop);
    }

    if (smd_element)
      gst_object_unref (smd_element);
  }
}
