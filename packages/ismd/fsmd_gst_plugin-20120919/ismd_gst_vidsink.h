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

#ifndef __ISMD_GST_VIDSINK_H__
#define __ISMD_GST_VIDSINK_H__

#include <gst/gst.h>
#include "ismd_gst_element.h"
#include "ismd_global_defs.h"
#include "ismd_vidpproc.h"
#include "ismd_vidsink.h"
#include "libgdl.h"
#include "ismd_gst_clock.h"
#include "ismd_gst_vidrend_sink.h"

/**
 * ISmdVidsink:Design for the scaling function at the playing and pause status by rectangle property.
 * Composite of the compoments:vidpproc and vidrender.
 *
 * The opaque #ISmdVidsink data structure.
 */
typedef struct _ISmdGstVidsink
{
  ISmdGstElement element;
  ismd_dev_t vidpproc_handle;
  ismd_dev_t vidrend_handle;

  ismd_vidpproc_scaling_policy_t scale_mode;
  ismd_vidsink_scale_params_t scale_params;
  gboolean interlaced;

  /* Optimisation storage for buffer_alloc return */
  GstCaps *caps;
  GstCaps *last_caps;

  gint width;
  gint height;
  gint aspect_x;
  gint aspect_y;
  gint fps_n;
  gint fps_d;

  gint last_format;
  gint last_width;
  gint last_height;
  gint last_par_x;
  gint last_par_y;
  gint system_stride;
  gboolean setup;

  gboolean is_yv12;
  gboolean is_i420;
  gboolean pan_and_scan_enabled;

  GValue rectangle;                  /* destination rectangle */
  dest_rect_t dest_rect;             /* corrected destination rectangle */

  gboolean has_newsegment;

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

  ISmdGstClock *provided_clock;

  gboolean need_flush;
  ismd_time_t ismd_basetime;         /* to restore the base time after flush */
  gboolean first_advance_to_pts;

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

} ISmdGstVidsink;

typedef struct _ISmdGstVidsinkClass
{
  ISmdGstElementClass parent_class;

} ISmdGstVidsinkClass;

GType ismd_gst_vidsink_get_type (void);

#define ISMD_GST_TYPE_VIDSINK 	(ismd_gst_vidsink_get_type())
#define ISMD_GST_VIDSINK(obj) 	(G_TYPE_CHECK_INSTANCE_CAST\
					((obj),ISMD_GST_TYPE_VIDSINK,ISmdGstVidsink))
#define ISMD_GST_VIDSINK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST\
					((klass),ISMD_GST_TYPE_VIDSINK,ISmdGstVidsinkClass))
#define ISMD_GST_IS_VIDSINK(obj) 	(G_TYPE_CHECK_INSTANCE_TYPE\
					((obj),ISMD_GST_TYPE_VIDSINK))
#define ISMD_GST_IS_VIDSINK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
					((klass),ISMD_GST_TYPE_VIDSINK))
#define ISMD_GST_VIDSINK_CAST(obj) ((ISmdGstVidsink *)obj)

#endif /* __ISMD_GST_VIDSINK_H__ */
