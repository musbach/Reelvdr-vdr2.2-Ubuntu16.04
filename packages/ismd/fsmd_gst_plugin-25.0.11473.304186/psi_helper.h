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

#ifndef PSI_HELPER_H_
#define PSI_HELPER_H_

#include <gst/gst.h>
#include "ismd_core.h"
#include "ismd_demux.h"
#include "gstsectionfilter.h"
#include "gstmpegdesc.h"

#define MAX_PID 0x1fff
#define MAX_PROGRAMS 24
#define MAX_STREAMS_PER_PROGRAM 8

#ifndef ISMD_BUFFER_MAP_BY_TYPE
#define ISMD_BUFFER_MAP_BY_TYPE(buf_type, base_address, size) \
            (OS_MAP_IO_TO_MEM_CACHE(base_address, size))
#endif

/* Defines information for an elementary stream inside of a program */
    typedef struct _pmt_stream_data
{
  guint8 type;                 /* Algorithm (mpeg2, ac3, etc...) */
  guint16 pid;                 /* PID the demux needs to get this data */
  guint16 info_length;         /* ES info length */
  GstMPEGDescriptor *info;
} pmt_stream_data;

typedef struct _pmt_data
{
  gboolean valid;
  GCond *pmt_available_cond;
  guint8 table_id;
  guint16 program_number;
  guint8 version_number;
  gboolean current_next_indicator;
  guint8 section_number;
  guint8 last_section_number;
  guint16 pcr_pid;
  guint16 program_info_length;
  GstMPEGDescriptor *program_info;
  GArray *entries;
} pmt_data;

typedef struct _pmt_descriptor
{
  guint16 program_number;
  guint16 pmt_pid;
  gboolean filter_configured;
} pmt_descriptor;

typedef struct _pat_data
{
  gboolean valid;
  guint8 version_number;
  guint8 section_number;
  guint8 last_section_number;
  gboolean current_next_indicator;
  GArray *entries;
  guint16 nit_pid;
  gboolean nit_pid_valid;
  guint16 transport_stream_id;
} pat_data;

typedef void (*pat_changed_cb_t) (gpointer user_data);
typedef void (*pmt_changed_cb_t) (gpointer user_data, guint16 service_id);
typedef void (*data_inject_cb_t) (gpointer user_data, GstBuffer *buf, gint pid);
typedef void (*eit_changed_cb_t) (gpointer user_data, GstStructure *eit);
typedef void (*tdt_changed_cb_t) (gpointer user_data, GstStructure *tdt);

/* This structure is allocated with g_malloc0, so all elements are initialzed
 * to NULL */
typedef struct _psi_filter
{
  /* PAT */
  pat_data pat;
  /* PMT: Key=ProgNum Value=pmt_data* */
  GHashTable *pmt_hash_table;

  /* Section filters: Key=PID, Value=GstSectionFilter* */
  GHashTable *section_filter_hash_table;

  /* ISMD handle for the demuxer device */
  ismd_dev_handle_t demux_handle;
  gint demux_filter_size;

  /* ISMD handle for the filter used to monitor PSIs */
  ismd_demux_filter_handle_t filter_handle;
  /* Output port of the pat_filter */
  ismd_port_handle_t filter_output_port_handle;
  /* Whether or not pat_filter has been opened. Required because there is no
   * such thing as a ISMD_FILTER_INVALID value */
  gboolean filter_valid;

  /* One event used to monitor all ports. */
  ismd_event_t port_event;
  gboolean attached;

  /* Thread used to monitor PATs and PMTs */
  GThread *event_loop_thread;
  /* To signal when the event loop must finish and the thread exit */
  gboolean event_loop_running;
  /* To control simultaneous access to this structure */
  GMutex *mutex;
  /* To signal the main thread of the availability of some data */
  GCond *pat_available_cond;

  /* To call back the main thread when internal structures change */
  pat_changed_cb_t pat_changed_cb;
  pmt_changed_cb_t pmt_changed_cb;
  eit_changed_cb_t eit_changed_cb;
  tdt_changed_cb_t tdt_changed_cb;
  data_inject_cb_t data_inject_cb;
  gpointer user_data;

  /* Piece of a received ISMD buffer which was not parsed in a previous
   * iteration because the packet was not complete. */
  GstBuffer *remnant_buffer;

  /* Whether the parser should check the received CRCs */
  gboolean check_crc;

  // pat_info, hash_table, locks, ismd_event, ismd_port of psi filtering, etc
} psi_filter;

gboolean psi_filter_create (ismd_dev_t demux_handle, psi_filter ** psif);

void psi_filter_destroy (psi_filter * psif);

gboolean psi_filter_wait_for_pat (psi_filter * psif, glong timeout);

gboolean psi_filter_wait_for_pmt (psi_filter * psif, guint16 service_id,
    glong timeout);

gboolean psi_filter_get_pat (psi_filter * psif, pat_data * pat);

gboolean psi_filter_get_pmt (psi_filter * psif, guint16 service_id,
    pmt_data * pmt);

gboolean psi_filter_add_all_pmts (psi_filter * psif);
gboolean psi_filter_add_pmt_for_service (psi_filter * psif,
    guint program);

void psi_filter_set_callbacks (psi_filter * psif,
    pat_changed_cb_t pat_changed_cb, pmt_changed_cb_t pmt_changed_cb,
    eit_changed_cb_t eit_changed_cb, tdt_changed_cb_t tdt_changed_cb,
    data_inject_cb_t data_inject_cb, gpointer user_data);

pmt_descriptor *psi_filter_find_prognum_in_pat (pat_data * pat,
    guint16 program_number);

GstStructure *psi_filter_build_pat_structure (psi_filter * psif);
GstStructure *psi_filter_build_pmt_structure (psi_filter * psif,
    guint16 program);


#endif /*PSI_HELPER_H_ */
