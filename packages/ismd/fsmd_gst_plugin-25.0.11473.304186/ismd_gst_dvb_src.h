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

#ifndef __ISMD_GST_DVB_SRC_H__
#define __ISMD_GST_DVB_SRC_H__

#include "ismd_gst_element.h"
#include "ismd_core.h"
#include "ismd_demux.h"
#include "ismd_gst_clock.h"
#include "psi_helper.h"
#include "ismd_gst_enum.h"

typedef struct _ISmdGstDVBSrcClass ISmdGstDVBSrcClass;
typedef struct _ISmdGstDVBSrc ISmdGstDVBSrc;

typedef struct _ISmdGstDVBStreamClass ISmdGstDVBStreamClass;
typedef struct _ISmdGstDVBStream ISmdGstDVBStream;

/* standard type-casting and type-checking boilerplate... */
#define ISMD_GST_TYPE_DVB_SRC             (ismd_gst_dvb_src_get_type())
#define ISMD_GST_DVB_SRC(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), ISMD_GST_TYPE_DVB_SRC, ISmdGstDVBSrc))
#define ISMD_GST_DVB_SRC_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), ISMD_GST_TYPE_DVB_SRC, ISmdGstDVBSrcClass))
#define ISMD_GST_IS_DVB_SRC(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj), ISMD_GST_TYPE_DVB_SRC))
#define ISMD_GST_IS_DVB_SRC_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), ISMD_GST_TYPE_DVB_SRC))

struct _ISmdGstDVBSrcClass
{
  GstElementClass parent_class;
};

struct _ISmdGstDVBSrc
{
  GstElement element;

  /* Tuner to use */
  guint tuner;
  /* Program (service id) to select */
  guint program;
  /* Timeout value (in microseconds) when waiting for a PAT or PMT */
  guint64 psi_timeout;
  /* Discovery mode will push GstMessages on all PMTs */
  gboolean discovery;
  /* Additional PIDs to let pass through the filter */
  guint16 *extra_pids;
  guint nb_extra_pids;
  /* Allowed PID categories through the filter */
  PidCategory allowed_pid_categories;

  ISmdGstDVBStream *main_stream;
  GHashTable *streams;

  ismd_dev_t dev_handle;

  psi_filter *psif;

  gboolean check_crc;
  gboolean clock_recovery;

  gboolean running;
  gboolean flushing;
  gboolean clock_is_ismd;
  guint16 current_pcr_pid;
};

GType ismd_gst_dvb_src_get_type (void);

#define ISMD_GST_TYPE_DVB_STREAM            (ismd_gst_dvb_stream_get_type())
#define ISMD_GST_DVB_STREAM(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), ISMD_GST_TYPE_DVB_STREAM, ISmdGstDVBStream))
#define ISMD_GST_DVB_STREAM_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), ISMD_GST_TYPE_DVB_STREAM, ISmdGstDVBStreamClass))
#define ISMD_GST_DVB_STREAM_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ISMD_GST_TYPE_DVB_STREAM, ISmdGstDVBStreamClass))
#define ISMD_GST_IS_DVB_STREAM(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), ISMD_GST_TYPE_DVB_STREAM))
#define ISMD_GST_IS_DVB_STREAM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), ISMD_GST_TYPE_DVB_STREAM))
#define ISMD_GST_DVB_STREAM_CAST(obj)		    ((ISmdGstDVBStream*)(obj))

struct _ISmdGstDVBStreamClass
{
  GstPadClass parent_class;
};

struct _ISmdGstDVBStream
{
  GstPad pad;
  gboolean active;

  ismd_demux_filter_handle_t filter_handle;
  ismd_port_handle_t port;

  gboolean setup;
  gboolean configured;
  gboolean need_new_segment;

  ismd_event_t port_event;

  GStaticRecMutex *adapter_lock;
  GstAdapter *queued_data;
  GstBuffer *prev_ts_fragment;

  gint program;
  guint16 pmt_pid;
  GArray *ES_pids;
};

GType ismd_gst_dvb_stream_get_type (void);

ISmdGstDVBStream * ismd_gst_dvb_stream_create (GstPadTemplate * template,
    const gchar * name);
gboolean ismd_gst_dvb_stream_open (ISmdGstDVBStream * stream,
    ismd_dev_t dev_handle);
gboolean ismd_gst_dvb_stream_flush (ISmdGstDVBStream * stream);
gboolean ismd_gst_dvb_stream_close (ISmdGstDVBStream * stream,
     ismd_dev_t dev_handle);
gboolean ismd_gst_dvb_stream_start (ISmdGstDVBStream * stream);
gboolean ismd_gst_dvb_stream_stop (ISmdGstDVBStream * stream);
gboolean ismd_gst_dvb_stream_map_pid (ISmdGstDVBStream * stream,
    guint16 pid, ismd_demux_pid_type_t pid_type);
gboolean ismd_gst_dvb_stream_unmap_pid (ISmdGstDVBStream * stream, guint16 pid);
gboolean ismd_gst_dvb_stream_configure_es_pids (ISmdGstDVBStream * stream,
    pmt_data * pmt);
void ismd_gst_dvb_stream_queue_data (ISmdGstDVBStream * stream, GstBuffer *buf);

#endif /* __ISMD_GST_DVB_SRC_H__ */
