/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

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

    Contat Information for Fluendo:
        FLUENDO S.A.
        World Trade Center Ed Norte 4 pl.
        Moll de Barcelona
        08039 BARCELONA - SPAIN

    BSD LICENSE

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
      - Neither the name of FLUENDO S.A. nor the names of its
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

#include <gst/gst.h>

#include "gstmpegdesc.h"

GST_DEBUG_CATEGORY_EXTERN (ismd_gst_mpeg_ts_desc_debug);
#define GST_CAT_DEFAULT (ismd_gst_mpeg_ts_desc_debug)

#ifndef GST_MEMDUMP
#define GST_MEMDUMP(_title, _data, _length)       \
{                                                 \
  guint8 _buf[33];                                \
  guint _len = _length;                           \
  if (_len > 32) _len = 32;                       \
  memcpy (&_buf, _data, _len);                    \
  _buf[_len+1] = 0;                               \
  GST_DEBUG ("%s%s", _title, _buf);               \
}
#endif

void
gst_mpeg_descriptor_free (GstMPEGDescriptor * desc)
{
  g_return_if_fail (desc != NULL);

  g_free (desc);
}

static guint
gst_mpeg_descriptor_parse_1 (guint8 * data, guint size)
{
  guint8 tag;
  guint8 length;

  /* need at least 2 bytes for tag and length */
  if (size < 2)
    return 0;

  tag = *data++;
  length = *data++;
  size -= 2;

  GST_DEBUG ("tag: 0x%02x, length: %d", tag, length);

  if (length > size)
    return 0;

  GST_MEMDUMP ("tag contents:", data, length);

  return length + 2;
}

GstMPEGDescriptor *
gst_mpeg_descriptor_parse (guint8 * data, guint size)
{
  guint8 *current;
  guint consumed, total, n_desc;
  GstMPEGDescriptor *result;

  g_return_val_if_fail (data != NULL, NULL);

  current = data;
  total = 0;
  n_desc = 0;

  do {
    consumed = gst_mpeg_descriptor_parse_1 (current, size);

    if (consumed > 0) {
      current += consumed;
      total += consumed;
      size -= consumed;
      n_desc++;
    }
  }
  while (consumed > 0);

  GST_DEBUG ("parsed %d descriptors", n_desc);

  if (total == 0)
    return NULL;

  result = g_malloc (sizeof (GstMPEGDescriptor) + total);
  result->n_desc = n_desc;
  result->data_length = total;
  result->data = ((guint8 *) result) + sizeof (GstMPEGDescriptor);

  memcpy (result->data, data, total);

  return result;
}

guint
gst_mpeg_descriptor_n_desc (GstMPEGDescriptor * desc)
{
  g_return_val_if_fail (desc != NULL, 0);

  return desc->n_desc;
}

guint8 *
gst_mpeg_descriptor_find (GstMPEGDescriptor * desc, gint tag)
{
  guint8 length;
  guint8 *current;
  guint size;

  g_return_val_if_fail (desc != NULL, NULL);

  current = desc->data;
  length = desc->data_length;

  while (length > 0) {
    if (DESC_TAG (current) == tag)
      return current;

    size = DESC_LENGTH (current) + 2;

    current += size;
    length -= size;
  }
  return NULL;
}

/* array needs freeing afterwards */
GArray *
gst_mpeg_descriptor_find_all (GstMPEGDescriptor * desc, gint tag)
{
  GArray *all;

  guint8 length;
  guint8 *current;
  guint size;

  g_return_val_if_fail (desc != NULL, NULL);
  all = g_array_new (TRUE, TRUE, sizeof (guint8 *));

  current = desc->data;
  length = desc->data_length;

  while (length > 0) {
    if (DESC_TAG (current) == tag)
      g_array_append_val (all, current);
    size = DESC_LENGTH (current) + 2;

    current += size;
    length -= size;
  }

  GST_DEBUG ("found tag 0x%02x %d times", tag, all->len);

  return all;
}

guint8 *
gst_mpeg_descriptor_nth (GstMPEGDescriptor * desc, guint i)
{
  guint8 length;
  guint8 *current;
  guint size;

  g_return_val_if_fail (desc != NULL, NULL);

  if (i > desc->n_desc)
    return NULL;

  current = desc->data;
  length = desc->data_length;

  while (length > 0) {
    if (i == 0)
      return current;

    size = DESC_LENGTH (current) + 2;

    current += size;
    length -= size;
    i--;
  }
  return NULL;
}

