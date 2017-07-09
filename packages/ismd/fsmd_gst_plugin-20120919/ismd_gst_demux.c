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

/* TODO:
 * This element needs to be rewritten using a design similar to ismd_dvb_src.
 * For TS demuxing the PSI helpers can be reused.
 * Instead of GList of streams/pads a subclass similar to ismd_dvb_stream
 * should be used with independent filters, threads and using the pad_lock.
 */

#include <gst/gstmarshal.h>
#include "ismd_gst_element.h"
#include "ismd_gst_demux.h"

#define MPEG2_PS_CAP_STRING "video/mpeg, " \
         "  mpegversion = (int) 2, " \
         "  systemstream = (boolean) true"

#define MPEG2_TS_CAP_STRING "video/mpegts, " \
         "  mpegversion = (int) 2," \
         "  systemstream = (boolean) true," \
         "  packetsize = (int) [188, 192]"

static GstStaticPadTemplate sinktemplate = GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (MPEG2_PS_CAP_STRING ";" MPEG2_TS_CAP_STRING));

static GstStaticPadTemplate video_pad_template = GST_STATIC_PAD_TEMPLATE ("src_1",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);

static GstStaticPadTemplate audio_pad_template = GST_STATIC_PAD_TEMPLATE ("src_2",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);

static GstStaticCaps srccap = { {0, 0, (GstCapsFlags) 0}, "ANY" };
static GstStaticCaps sinkcap =
    { {0, 0, (GstCapsFlags) 0}, MPEG2_PS_CAP_STRING ";" MPEG2_TS_CAP_STRING };

GST_DEBUG_CATEGORY_STATIC (ismd_gst_demux_debug);
#define GST_CAT_DEFAULT ismd_gst_demux_debug

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_demux_debug, "ISMD_DEMUX",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstdemux element");
}

// Call Boilerplate to declare the base_init, class_init and init functions
// and to define the get_type function
GST_BOILERPLATE_FULL (ISmdGstDemux, ismd_gst_demux,
    ISmdGstElement, ISMD_GST_TYPE_ELEMENT, _do_init);


/**
 * ismd_close
 * Close resources
 * @element - element containing ts demux
 */
static void
ismd_close (ISmdGstDemux * demux)
{
  ismd_result_t result = ISMD_SUCCESS;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (demux);

  // Close the ts demux
  result = ismd_dev_close (smd_element->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (demux, "ismd_dev_close failed(%d)", result);
  }
  // TODO: does a ismd_element_unregister_srcpad() need to happen??
  smd_element->dev_handle = ISMD_DEV_HANDLE_INVALID;
  (smd_element->sink_pad)->ismd_port = ISMD_DEV_HANDLE_INVALID;
}


static inline void
negotiate_caps (GstPad * pad, GstCaps * caps)
{
  if (gst_pad_peer_accept_caps (pad, caps)) {
    GST_DEBUG_OBJECT (pad, "setting caps downstream to %" GST_PTR_FORMAT, caps);
    if (G_UNLIKELY (!gst_pad_set_caps (pad, caps))) {
      GST_ERROR_OBJECT (pad, "failed setting downstream caps to %"
          GST_PTR_FORMAT, caps);
    }
  }
  gst_caps_unref (caps);
}

/**
 * ismd_open
 * Open the ts demux and get the port
 * @demux - element containing the demuxer
 * returns TRUE if setup is successful
 */
static gboolean
ismd_open (ISmdGstDemux * demux)
{
  gboolean ret = FALSE;
  ismd_result_t result = ISMD_SUCCESS;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (demux);
  ISmdGstPad *ismdpad;

  GList *padlist;
  ismd_demux_pid_list_t pid_list;

  result = ismd_demux_stream_open (demux->stream_type,
      &(smd_element->dev_handle), &(smd_element->sink_pad->ismd_port));
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (demux, "ismd_demux_stream_open failed(%d)", result);
    goto beach;
  }
  GST_DEBUG_OBJECT (demux, "demux_handle=%d input port=%d",
      smd_element->dev_handle, smd_element->sink_pad->ismd_port);

  ismd_setup_input_pad (smd_element->sink_pad);

  // First source pad is the video filter port
  // Second source pad is the audio filter port
  padlist = smd_element->src_pads;
  ismdpad = ISMD_GST_PAD (padlist->data);

  result = ismd_demux_filter_open (smd_element->dev_handle,
      ISMD_DEMUX_OUTPUT_ES, 32 * 1024, &demux->filter[FILTER_VIDEO],
      &ismdpad->ismd_port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (demux, "ismd_demux_filter_open failed(%d)", result);
    ismd_close (demux);
    goto beach;
  }
  GST_DEBUG_OBJECT (demux, "vidfilt_devhandle=%u, vid_filt_outport=%d",
      demux->filter[FILTER_VIDEO], ismdpad->ismd_port);

  if (demux->stream_type == ISMD_DEMUX_STREAM_TYPE_DVD_PROGRAM_STREAM) {
    result = ismd_demux_filter_map_to_sid (smd_element->dev_handle,
        demux->filter[FILTER_VIDEO], 0xe0, 0x00, 0x00);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (demux, "ismd_demux_filter_map_to_sid failed(%d)",
          result);
    }
  }
  else {
    pid_list.pid_array[0].pid_val = 0x21;
    pid_list.pid_array[0].pid_type = ISMD_DEMUX_PID_TYPE_PES;

    result = ismd_demux_filter_map_to_pids (smd_element->dev_handle,
        demux->filter[FILTER_VIDEO], pid_list, 1);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (demux, "ismd_demux_filter_map_to_pids failed(%d)",
          result);
    }

    ismd_demux_ts_set_pcr_pid (smd_element->dev_handle, 0x21);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (demux, "ismd_demux_ts_set_pcr_pid failed(%d)",
          result);
    }
  }
  negotiate_caps (GST_PAD (ismdpad),
      gst_caps_new_simple ("video/x-h264", NULL));
  ismd_setup_output_pad (ismdpad);
  // get the next source pad
  if ((padlist = g_list_next (padlist)) != NULL) {
    // the second source pad is the audio port
    ismdpad = ISMD_GST_PAD (padlist->data);
    result = ismd_demux_filter_open (smd_element->dev_handle,
        ISMD_DEMUX_OUTPUT_ES, 32 * 1024, &demux->filter[FILTER_AUDIO],
        &ismdpad->ismd_port);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (demux, "ismd_demux_filter_open failed(%d)", result);
      ismd_close (demux);
      goto beach;
    }
    GST_DEBUG_OBJECT (demux, "audfilt_devhandle=%u, aud_filt_outport=%d",
        demux->filter[FILTER_AUDIO], ismdpad->ismd_port);
    ismd_setup_output_pad (ismdpad);
  }

  if (demux->stream_type == ISMD_DEMUX_STREAM_TYPE_DVD_PROGRAM_STREAM) {
    gint data_offset = 0x00;
#if 0
    if (ISMD_AUDIO_MEDIA_FMT_DVD_PCM == eAudioCodec)
      data_offset = 0x01; // 1 extra byte for LPCM

    else if (ISMD_AUDIO_MEDIA_FMT_DD == eAudioCodec)
      data_offset = 0x04; // extra bytes for AC3
    else if ( (ISMD_AUDIO_MEDIA_FMT_DTS_HD == eAudioCodec) ||
               (ISMD_AUDIO_MEDIA_FMT_DTS_HD_HRA == eAudioCodec) ||
               (ISMD_AUDIO_MEDIA_FMT_DTS_HD_MA == eAudioCodec) ||
               (ISMD_AUDIO_MEDIA_FMT_DTS == eAudioCodec) ||
               (ISMD_AUDIO_MEDIA_FMT_DTS_LBR == eAudioCodec) )
      data_offset = 0x4;
#endif
    /* Hardcoded AC3 then data_offset = 0x4*/
    data_offset = 0x4;
    result = ismd_demux_filter_map_to_sid (smd_element->dev_handle,
        demux->filter[FILTER_AUDIO], 0xbd, 0x82, data_offset);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (demux, "ismd_demux_filter_map_to_sid failed(%d)",
          result);
    }
  }
  else {
    pid_list.pid_array[0].pid_val = 0x26;
    pid_list.pid_array[0].pid_type = ISMD_DEMUX_PID_TYPE_PES;

    result = ismd_demux_filter_map_to_pids (smd_element->dev_handle,
        demux->filter[FILTER_AUDIO], pid_list, 1);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (demux, "ismd_demux_filter_map_to_pids failed(%d)",
          result);
    }
  }
  negotiate_caps (GST_PAD (ismdpad),
      gst_caps_new_simple ("audio/x-ac3", NULL));
  ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_PAUSE);
  ret = TRUE;

beach:
  return ret;
}

GstPadLinkReturn
ismd_gst_demux_sinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  GstStructure *structure;
  ISmdGstDemux *demux;
  gint packetsize;
  gboolean ret = FALSE;

  demux = ISMD_GST_DEMUX (gst_pad_get_parent (pad));

  GST_DEBUG_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  if (!(structure = gst_caps_get_structure (caps, 0))) {
    GST_ERROR_OBJECT (pad, "no caps found");
    goto beach;
  }


  if (gst_structure_has_name (structure, "video/mpegts"))
  {
    if (!gst_structure_get_int (structure, "packetsize", &packetsize))
      packetsize = 188;

    if (packetsize == 192)
      demux->stream_type = ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM_192;
    else
      demux->stream_type = ISMD_DEMUX_STREAM_TYPE_MPEG2_TRANSPORT_STREAM;
  } else if (gst_structure_has_name (structure, "video/mpeg")) {
    demux->stream_type = ISMD_DEMUX_STREAM_TYPE_DVD_PROGRAM_STREAM;
  } else {
    goto beach;
  }
  ret = ismd_open (demux);

beach:
  gst_object_unref (demux);
  return ret;
}

static GstStateChangeReturn
ismd_gst_demux_change_state (GstElement * element, GstStateChange transition)
{
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ISmdGstDemux *demux = ISMD_GST_DEMUX (element);

  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);


  switch (transition) {
    case GST_STATE_CHANGE_READY_TO_NULL:
    {
      ismd_close (demux);
      break;
    }
    default:
      break;
  }                             // switch

  return ret;
}

/**
 * ismd_gst_demux_base_init
 *      Define element details and add pad templates if any
 *      @g_class - Pointer to the GStreamer object
 */
static void
ismd_gst_demux_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_demux_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Hardware Transport Stream Demultiplexer",
      "Demuxer",
      "GStreamer VideoSink Element for Intel's Media Processors",
      "http://www.intelconsumerelectronics.com/");

  GstElementClass *gstelement_class = GST_ELEMENT_CLASS (g_class);
  GstPadTemplate *curr_tmplt = NULL;
  gst_element_class_set_details (gstelement_class, &ismd_gst_demux_details);

  /* Add pad templates for the class */
  curr_tmplt = gst_static_pad_template_get (&sinktemplate);
  gst_element_class_add_pad_template (gstelement_class, curr_tmplt);
  gst_object_unref (curr_tmplt);

  curr_tmplt = gst_static_pad_template_get (&video_pad_template);
  gst_element_class_add_pad_template (gstelement_class, curr_tmplt);
  gst_object_unref (curr_tmplt);

  curr_tmplt = gst_static_pad_template_get (&audio_pad_template);
  gst_element_class_add_pad_template (gstelement_class, curr_tmplt);
  gst_object_unref (curr_tmplt);
}

static void
ismd_gst_demux_class_init (ISmdGstDemuxClass * klass)
{
  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_demux_change_state);
}

static void
ismd_gst_demux_init (ISmdGstDemux * demux, ISmdGstDemuxClass * g_class)
{
  GstPad *pad;

  ismd_gst_element_create_pads (ISMD_GST_ELEMENT (demux), &sinkcap,
      &srccap, 2);

  pad = gst_element_get_static_pad (GST_ELEMENT (demux), "sink");
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_demux_sinkpad_setcaps));
  gst_object_unref (pad);
}
