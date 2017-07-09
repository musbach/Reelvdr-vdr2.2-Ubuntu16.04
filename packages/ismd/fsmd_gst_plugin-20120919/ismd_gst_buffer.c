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

#include <string.h>
#include "osal.h"
#include "ismd_gst_buffer.h"

GST_DEBUG_CATEGORY_STATIC (ismd_gst_buffer_debug);
#define GST_CAT_DEFAULT ismd_gst_buffer_debug

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_buffer_debug, "ISMD_BUFFER",
      (GST_DEBUG_FG_GREEN), "ismdgstbuffer");
}

GST_BOILERPLATE_FULL (ISmdGstBuffer, ismd_gst_buffer,
    GstBuffer, GST_TYPE_BUFFER, _do_init);

static void ismd_gst_buffer_finalize (ISmdGstBuffer * buf);
static ISmdGstBuffer *ismd_gst_buffer_copy (ISmdGstBuffer * buf);

static void
ismd_gst_buffer_base_init (gpointer class)
{
}

static void
ismd_gst_buffer_class_init (ISmdGstBufferClass * g_class)
{
  GstMiniObjectClass *mini_object_class = GST_MINI_OBJECT_CLASS (g_class);

  mini_object_class->finalize = (GstMiniObjectFinalizeFunction)
      ismd_gst_buffer_finalize;
      
  mini_object_class->copy = (GstMiniObjectCopyFunction) ismd_gst_buffer_copy;      
}

static void
ismd_gst_buffer_init (ISmdGstBuffer * buf, ISmdGstBufferClass * class)
{
  buf->ismd_buffer_id = ISMD_BUFFER_HANDLE_INVALID;
}

ISmdGstBuffer *
ismd_gst_buffer_new (void)
{
  ISmdGstBuffer *buf;
  buf = (ISmdGstBuffer *) gst_mini_object_new (ISMD_GST_TYPE_BUFFER);
  return buf;
}

static void
log_buffer (ISmdGstBuffer * buf)
{
  ismd_buffer_descriptor_t desc;
  ismd_buffer_read_desc (buf->ismd_buffer_id, &desc);
  GST_LOG_OBJECT (buf, "buf id: %d ref. count: %d",
      buf->ismd_buffer_id, desc.reference_count);
}

static void
ismd_gst_buffer_finalize (ISmdGstBuffer * buf)
{
  ismd_result_t ret;

  if (buf->ismd_buffer_id != ISMD_BUFFER_HANDLE_INVALID) {
    if (GST_BUFFER_DATA (buf))
      OS_UNMAP_IO_FROM_MEM (GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));
    log_buffer (buf);
    ret = ismd_buffer_dereference (buf->ismd_buffer_id);
    if (ret != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (buf, "ismd_buffer_dereference failed %d for buf %d",
          ret, buf->ismd_buffer_id);
    }
  }

  buf->ismd_buffer_id = ISMD_BUFFER_HANDLE_INVALID;

  GST_CALL_PARENT (GST_MINI_OBJECT_CLASS, finalize, GST_MINI_OBJECT_CAST (buf));
}

static ISmdGstBuffer *
ismd_gst_buffer_copy (ISmdGstBuffer * buffer)
{
  ISmdGstBuffer * copy;

  g_return_val_if_fail (buffer != NULL, NULL);

  copy = ismd_gst_buffer_new ();

  copy->ismd_buffer_id = buffer->ismd_buffer_id;
  ismd_buffer_add_reference (buffer->ismd_buffer_id);

  GST_BUFFER_SIZE (copy) = GST_BUFFER_SIZE (buffer);

  gst_buffer_copy_metadata (GST_BUFFER_CAST (copy), GST_BUFFER_CAST (buffer),
      GST_BUFFER_COPY_ALL);

  GST_DEBUG_OBJECT (buffer, "Copied ISMD buffer:");
  GST_DEBUG_OBJECT (buffer, "   Original %p: id=%d size=%d timestamp=%"
      GST_TIME_FORMAT, buffer, buffer->ismd_buffer_id, GST_BUFFER_SIZE (buffer),
      GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buffer)));
  GST_DEBUG_OBJECT (buffer, "   Copy     %p: id=%d size=%d timestamp=%"
      GST_TIME_FORMAT, copy, copy->ismd_buffer_id, GST_BUFFER_SIZE (copy),
      GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (copy)));

  return copy;
}
