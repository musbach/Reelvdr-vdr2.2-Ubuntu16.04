/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2008. Intel Corporation. All rights reserved.
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

    Copyright (c) 2008. Intel Corporation. All rights reserved.
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

#ifndef __ISMD_GST_VIDREND_SINK_H__
#define __ISMD_GST_VIDREND_SINK_H__

#include <gst/gst.h>
#include "ismd_gst_element.h"
#include "libgdl.h"
#include "ismd_gst_clock.h"

#define QOS_MAX_TRACK 16

typedef enum
{
  ISMD_VIDEO_SINK_FORMAT_UNKNOWN,
  ISMD_VIDEO_SINK_FORMAT_UYVY,
  ISMD_VIDEO_SINK_FORMAT_NV12,
  ISMD_VIDEO_SINK_FORMAT_NV21
} ISmdVideoSinkFormat;

typedef struct _qos_entry
{
  ismd_time_t arrival;
  ismd_time_t queued;
} qos_entry;

/**
 * ISmdVidrendSink:
 *
 * The opaque #ISmdVidrendSink data structure.
 */
typedef struct _ISmdGstVidrendSink
{
  ISmdGstElement element;

  gint tvmode;

  guint32 bg_color;
  gdl_gamma_t gamma;

  gdl_plane_id_t video_plane;
  gdl_plane_id_t cc_plane;

  gint tv_width;
  gint tv_height;

  guint32 brightness;
  guint32 contrast;
  guint32 hue;
  guint32 aspect_ratio;

  gboolean setup;
  gint fps_n;
  gint fps_d;

  ISmdGstClock *provided_clock;

  GValue rectangle;                  /* destination rectangle */

  gboolean first_advance_to_pts;
  ismd_time_t ismd_basetime;         /* to restore the base time after flush */ 

  gboolean flush_repeat_frame;
  gboolean qos_enabled;
  qos_entry qos_entries[QOS_MAX_TRACK];
  ismd_time_t qos_last_pts;
  GstClockTime avg_duration;
  GstClockTime avg_pt;
  gdouble avg_rate;

  /* Monitoring task on rendered frames */
  GstTask *monitor_loop;
  GStaticRecMutex *monitor_mutex;
  ismd_event_t out_event;
  ismd_event_t eos_event;
  ismd_port_handle_t out_port;
  gboolean monitor_stop;
  gboolean eos_posted;

} ISmdGstVidrendSink;

typedef struct _ISmdGstVidrendSinkClass
{
  ISmdGstElementClass parent_class;

} ISmdGstVidrendSinkClass;

GType ismd_gst_vidrend_sink_get_type (void);

#define ISMD_GST_TYPE_VIDREND_SINK 	(ismd_gst_vidrend_sink_get_type())
#define ISMD_GST_VIDREND_SINK(obj) 	(G_TYPE_CHECK_INSTANCE_CAST\
					((obj),ISMD_GST_TYPE_VIDREND_SINK,ISmdGstVidrendSink))
#define ISMD_GST_VIDREND_SINK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST\
					((klass),ISMD_GST_TYPE_VIDREND_SINK,ISmdGstVidrendSinkClass))
#define ISMD_GST_IS_VIDREND_SINK(obj) 	(G_TYPE_CHECK_INSTANCE_TYPE\
					((obj),ISMD_GST_TYPE_VIDREND_SINK))
#define ISMD_GST_IS_VIDREND_SINK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
					((klass),ISMD_GST_TYPE_VIDREND_SINK))
#define ISMD_GST_VIDREND_SINK_CAST(obj) ((ISmdGstVidrendSink *)obj)

#endif /* __ISMD_GST_VIDREND_SINK_H__ */