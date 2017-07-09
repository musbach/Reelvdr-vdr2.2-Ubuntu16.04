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
    
    Contat Information for Fluendo:
        FLUENDO S.A.
        World Trade Center Ed Norte 4 pl.
        Moll de Barcelona
        08039 BARCELONA - SPAIN

    BSD LICENSE

    Copyright(c) 2012. Intel Corporation. All rights reserved.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gstsectionfilter.h"

#ifndef __always_inline
#if (__GNUC__ > 3) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)
#define __always_inline inline __attribute__((always_inline))
#else
#define __always_inline inline
#endif
#endif

#ifndef DISABLE_INLINE
#define FORCE_INLINE __always_inline
#else
#define FORCE_INLINE
#endif

GST_DEBUG_CATEGORY_EXTERN (ismd_gst_section_filter_debug);
#define GST_CAT_DEFAULT (ismd_gst_section_filter_debug)

void
gst_section_filter_init (GstSectionFilter * filter)
{
  g_return_if_fail (filter != NULL);
  filter->adapter = gst_adapter_new ();
  filter->raw_ts_adapter = gst_adapter_new ();
  /* continuity counter can at max be 15
   * we make 255 as an indication that
   * there is no last continuity counter */
  filter->last_continuity_counter = 255;
  filter->section_length = G_MAXUINT16;
}

void
gst_section_filter_uninit (GstSectionFilter * filter)
{
  g_return_if_fail (filter != NULL);
  if (filter->adapter)
    g_object_unref (filter->adapter);
  filter->adapter = NULL;
  if (filter->raw_ts_adapter)
    g_object_unref (filter->raw_ts_adapter);
  filter->raw_ts_adapter = NULL;
}

void
gst_section_filter_clear (GstSectionFilter * filter)
{
  g_return_if_fail (filter != NULL);
  if (filter->adapter) {
    gst_adapter_clear (filter->adapter);
    filter->last_continuity_counter = 255;
    filter->section_length = G_MAXUINT16;
  }
  if (filter->raw_ts_adapter) {
    gst_adapter_clear (filter->raw_ts_adapter);
  }
}

static FORCE_INLINE gboolean
gst_section_is_complete (GstSectionFilter * filter)
{
  /* section length measures size of section from 3 bytes into section
   * (ie after section length field finished) until end of section)
   */
  guint avail_bytes = gst_adapter_available (filter->adapter);
  if (filter->section_length == avail_bytes - 3) {
    return TRUE;
  } else if (filter->section_length < (int) (avail_bytes - 3)) {
    GST_DEBUG ("section length (%d) seems to be less than available bytes for "
        "rest of section (%d).",
        filter->section_length, (int) (avail_bytes - 3));
    return TRUE;
  }
  return FALSE;
}

/* returns True when section finished and ready to parse */
/* FIXME: especially for multi-section tables, we need to handle pusi correctly
 * and handle cases where a new section starts in the same transport packet.
 */
gboolean
gst_section_filter_push (GstSectionFilter * filter, gboolean pusi,      /* determines whether start or not */
    guint8 continuity_counter, GstBuffer * buf,  GstBuffer * raw_buf)
{
  g_return_val_if_fail (filter != NULL, FALSE);

  /* check if it's the first packet of a section or
   * if it continues the section */
  if (pusi) {
    const guint8 *data = GST_BUFFER_DATA (buf);
    if (filter->last_continuity_counter != 255) {
      GST_WARNING ("section lost, last continuity counter: %d "
          "we now have a pusi at continuity counter: %d",
          filter->last_continuity_counter, continuity_counter);
      gst_section_filter_clear (filter);
    }
    filter->section_length = GST_READ_UINT16_BE (data + 1);
    filter->section_length &= 0x0fff;
    if (filter->section_length > 4093) {
      GST_DEBUG ("section length too big");
      goto failure;
    }
    gst_adapter_push (filter->adapter, buf);
    gst_adapter_push (filter->raw_ts_adapter, raw_buf);
    filter->last_continuity_counter = continuity_counter;
    return gst_section_is_complete (filter);
  } else if (filter->last_continuity_counter == continuity_counter - 1 ||
      (filter->last_continuity_counter == 15 && continuity_counter == 0)) {
    GST_DEBUG ("section still going, no pusi");
    gst_adapter_push (filter->adapter, buf);
    gst_adapter_push (filter->raw_ts_adapter, raw_buf);
    filter->last_continuity_counter = continuity_counter;
    return gst_section_is_complete (filter);
  }
  /* we have lost the section and we are not a start
   * section, so clear what was in it */
  else {
    GST_LOG ("section lost, last continuity counter: %d "
        "new continuity counter but not pusi: %d",
        filter->last_continuity_counter, continuity_counter);
    gst_section_filter_clear (filter);
    goto failure;
  }
failure:
  gst_buffer_unref (buf);
  gst_buffer_unref (raw_buf);
  return FALSE;
}

GstBuffer *
gst_section_filter_take_raw (GstSectionFilter * filter)
{
  GstBuffer * buf = NULL;
  guint avail = gst_adapter_available (filter->raw_ts_adapter);
  if (avail) {
    buf = gst_adapter_take_buffer (filter->raw_ts_adapter, avail);
  }
  return buf;
}
