/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2011. Intel Corporation. All rights reserved.

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

    BSD LICENSE

    Copyright (c) 2011. Intel Corporation. All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

      - Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      - Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in
        the documentation and/or other materials provided with the
        distribution.
      - Neither the mimetype of Intel Corporation nor the mimetypes of its
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

#include <gst/gstmarshal.h>
#include <ismd_core.h>
#include <ismd_core_protected.h>
#include "ismd_gst_element.h"
#include "ismd_gst_ts_muxer.h"

#define ISMD_GST_MPEG2_TSMUX_VIDEO_SINK_CAPS \
    "video/mpeg, "\
    "  format = (fourcc) {MPEG, MP2V}, " \
    "  width = (int) [16,1920], " \
    "  height = (int) [16,1088], " \
    "  mpegversion = (int) [1, 2], " \
    "  systemstream = (boolean) false, " \
    "  ispacketized = (boolean) false; " \
    "video/x-h264; " \
    "video/x-decoded-ismd"

#define ISMD_GST_MPEG2_TSMUX_AUDIO_SINK_CAPS \
    "audio/x-raw-int; " \
    "audio/x-eac3; " \
    "audio/x-ddplus; " \
    "audio/x-private1-dts; " \
    "audio/x-dts; " \
    "audio/x-mpeg, mpegversion = (int) { 1, 2, 4 }; " \
    "audio/mpeg, mpegversion = (int) { 1, 2, 4 }; " \
    "audio/x-aac; " \
    "audio/x-ac3; " \
    "audio/x-dd; " \
    "audio/x-private1-ac3"
    

#define ISMD_GST_MPEG2_TSMUX_SRC_CAPS \
    "video/mpegts, "    \
    "systemstream = (boolean) true, "   \
    "packetsize = (int) { 188, 192} "

#define DEFAULT_ISMD_TS_MUXER_OUTPUT_STREAM_TYPE	    ISMD_MUX_TYPE_MPEG_TS_188 /* in nanoseconds */
#define DEFAULT_ISMD_TS_MUXER_INPUT_STREAM_MODE             ISMD_MUX_INPUT_MODE_ES
#define DEFAULT_ISMD_TS_MUXER_SCHEDULING_MODE 		    ISMD_MUX_SCHEDULING_MODE_BACKGROUND
#define DEFAULT_ISMD_TS_MUXER_TRANSPORT_STREAM_ID           1
#define DEFAULT_ISMD_TS_MUXER_PROGRAM_NUM		    1
#define DEFAULT_ISMD_TS_MUXER_PMT_PID			    ISMD_MUX_AUTO_GENERATE_PID
#define DEFAULT_ISMD_TS_MUXER_BITRATE                       0
#define DEFAULT_ISMD_TS_MUXER_PAT_INTERVAL		    7000
#define DEFAULT_ISMD_TS_MUXER_PMT_INTERVAL		    9000
#define DEFAULT_ISMD_TS_MUXER_PCR_INTERVAL		    5000
#define DEFAULT_ISMD_TS_MUXER_VIDEO_TSOFFSET		    120000
#define DEFAULT_ISMD_TS_MUXER_AUDIO_TSOFFSET		    90000



enum
{
    PROP_TS_MUXER_UNKNOWN,
    PROP_TS_MUXER_OUTPUT_STREAM_TYPE,
    PROP_TS_MUXER_INPUT_STREAM_MODE,
    PROP_TS_MUXER_SCHEDULING_MODE,
    PROP_TS_MUXER_TRANSPORT_STREAM_ID,
    PROP_TS_MUXER_PROGRAM_NUM,
    PROP_TS_MUXER_PMT_PID,
    PROP_TS_MUXER_BITRATE,
    PROP_TS_MUXER_PAT_INTERVAL,
    PROP_TS_MUXER_PMT_INTERVAL,
    PROP_TS_MUXER_PCR_INTERVAL,
    PROP_TS_MUXER_LAST,
};

static GstStaticPadTemplate src_factory = GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_MPEG2_TSMUX_SRC_CAPS)
);

static GstStaticPadTemplate video_sink_factory =
    GST_STATIC_PAD_TEMPLATE ("video_%d",
    GST_PAD_SINK,
    GST_PAD_REQUEST,
     GST_STATIC_CAPS (ISMD_GST_MPEG2_TSMUX_VIDEO_SINK_CAPS)
);

static GstStaticPadTemplate audio_sink_factory =
    GST_STATIC_PAD_TEMPLATE ("audio_%d",
    GST_PAD_SINK,
    GST_PAD_REQUEST,
    GST_STATIC_CAPS (ISMD_GST_MPEG2_TSMUX_AUDIO_SINK_CAPS)
);

static GstStaticCaps srccap =
{ {0, 0, (GstCapsFlags) 0}, ISMD_GST_MPEG2_TSMUX_SRC_CAPS};

static gboolean ismd_start (ISmdGstElement* element);
static gboolean ismd_pause (ISmdGstElement* element);
static inline gboolean ismd_open (GstElement * element);
static inline gboolean ismd_stop (GstElement * element);
static inline gboolean ismd_close (GstElement * element);

static gboolean remove_mux_input_and_free_node(ISmdGstElement* smd_element, ISmdGstTSMuxerPad *tsmuxer_pad);
static void ismd_gst_ts_muxer_reset (ISmdGstTSMuxer *tsmuxer);

#define GST_TYPE_ISMD_TS_MUXER_OUTPUT_STREAM_TYPE \
  (ismd_gst_ts_muxer_output_stream_type_get_type())
#define GST_TYPE_ISMD_TS_MUXER_SCHEDULING_MODE \
  (ismd_gst_ts_muxer_scheduling_mode_get_type())

static GType
ismd_gst_ts_muxer_output_stream_type_get_type(void)
{
    static GType ismd_gst_ts_muxer_output_stream_type = 0;
    static const GEnumValue output_stream_types[] = {
        {ISMD_MUX_TYPE_MPEG_TS_188, "Output is Transport Stream with 188-byte packets", "188"},
        {ISMD_MUX_TYPE_MPEG_TS_192, "Output is Transport Stream with 192-byte packets", "192"},
        {10, NULL, NULL}
    };

    if (!ismd_gst_ts_muxer_output_stream_type) {
        ismd_gst_ts_muxer_output_stream_type = 
            g_enum_register_static ("GstIsmdTsMuxerOutputStreamType",
                    output_stream_types);
    }
    return ismd_gst_ts_muxer_output_stream_type;
}

static GType
ismd_gst_ts_muxer_scheduling_mode_get_type(void)
{
    static GType ismd_gst_ts_muxer_scheduling_mode = 0;
    static const GEnumValue scheduling_modes[] = {
        {ISMD_MUX_SCHEDULING_MODE_BACKGROUND, "For background (non real-time) flows", "background"},
        {ISMD_MUX_SCHEDULING_MODE_REALTIME, "For real-time flows", "realtime"},
        {10, NULL, NULL}
    };

    if (!ismd_gst_ts_muxer_scheduling_mode) {
        ismd_gst_ts_muxer_scheduling_mode = 
            g_enum_register_static ("GstIsmdTsMuxerSchedulingMode",
                    scheduling_modes);
    }
    return ismd_gst_ts_muxer_scheduling_mode;
}

GST_DEBUG_CATEGORY_STATIC (ismd_gst_ts_muxer_debug);
#define GST_CAT_DEFAULT ismd_gst_ts_muxer_debug

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_ts_muxer_debug, "ISMD_TS_MUXER",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgsttsmuxer element");
}

GST_BOILERPLATE_FULL (ISmdGstTSMuxer, ismd_gst_ts_muxer, ISmdGstElement,
    ISMD_GST_TYPE_ELEMENT, _do_init);
static void
ismd_gst_ts_muxer_dispose (GObject * object)
{
  ISmdGstTSMuxer *tsmuxer;

  tsmuxer = ISMD_GST_TS_MUXER (object);
  G_OBJECT_CLASS (parent_class)->dispose (object);
}

static void
ismd_gst_ts_muxer_finalize (GObject * object)
{
  ISmdGstTSMuxer *tsmuxer;
  tsmuxer = ISMD_GST_TS_MUXER (object);

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static gboolean
ismd_start (ISmdGstElement * element)
{
    ISmdGstElement *parent = ISMD_GST_ELEMENT (element);

    if (parent->dev_handle == ISMD_DEV_HANDLE_INVALID) 
        return FALSE;

    return TRUE;
}

static gboolean
ismd_pause (ISmdGstElement * element)
{
    ISmdGstElement *parent = ISMD_GST_ELEMENT (element);

    if (parent->dev_handle == ISMD_DEV_HANDLE_INVALID){
        return FALSE;
    }

    return TRUE;
}

static GstStateChangeReturn
ismd_gst_ts_muxer_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstTSMuxer *tsmuxer = ISMD_GST_TS_MUXER (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;

  GST_DEBUG_OBJECT (tsmuxer, "going to  change state from %s to %s",
      gst_element_state_get_name(GST_STATE_TRANSITION_CURRENT (transition)),
     gst_element_state_get_name(GST_STATE_TRANSITION_NEXT (transition)));


  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
    {
      if (ismd_open (element) != TRUE) {
        GST_ERROR_OBJECT (tsmuxer, "ts muxer (%d): ismd_open failed",
            smd_element->dev_handle);
        goto failure;
      }	  
      break;
    }
    case GST_STATE_CHANGE_READY_TO_PAUSED:
    {
      break;
    }
    case GST_STATE_CHANGE_READY_TO_NULL:
    {
      if (smd_element->dev_handle == ISMD_DEV_HANDLE_INVALID) {
        GST_ERROR_OBJECT (tsmuxer,
            "ts muxer(%d): ts muxeris not open",
            smd_element->dev_handle);
        goto failure;
      }

      if (ismd_close (element) != TRUE) {
        GST_ERROR_OBJECT (tsmuxer, "ts muxer(%d): ismd_close failed",
            smd_element->dev_handle);
        goto failure;
      }
      break;
    }
    default:
      break;
  }

  /* Chain up to the parent class's state change function
   * Must do this before downward transitions are handled to safely handle
   * concurrent access by multiple threads */
  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    GST_ERROR_OBJECT (tsmuxer, "ts muxer(%d): change state failure",
        smd_element->dev_handle);
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
        {
            GST_DEBUG_OBJECT(tsmuxer,"-- ts muxer(%d): PLAYING TO PAUSED entered\n",
                    smd_element->dev_handle);
            if (smd_element->dev_handle == ISMD_DEV_HANDLE_INVALID) {
                GST_ERROR_OBJECT(tsmuxer, "-- ts muxer(%d): PLAYING_TO_PAUSED - ts muxer is not open\n",
                        smd_element->dev_handle);
                goto failure;
            }
            if (ismd_pause (smd_element) != TRUE) {
                GST_ERROR_OBJECT(tsmuxer, "-- ts muxer(%d): ismd_pause failed.\n",
                        smd_element->dev_handle);
                goto failure;
            }
            break;
        }
    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
        if (smd_element->dev_handle == ISMD_DEV_HANDLE_INVALID) {
            GST_ERROR_OBJECT(tsmuxer, "-- ts muxer(%d): PLAYING_TO_PAUSED - ts muxer is not open\n",
                    smd_element->dev_handle);
            goto failure;
        }
        if (ismd_start (smd_element) != TRUE) {
            GST_ERROR_OBJECT(tsmuxer, "-- ts muxer(%d): ismd_start failed.\n",
                    smd_element->dev_handle);
            goto failure;
        }
        break;
    case GST_STATE_CHANGE_PAUSED_TO_READY:
    {
        ismd_gst_ts_muxer_reset(tsmuxer);
      if (ismd_stop (element) != TRUE) {
        GST_ERROR_OBJECT (tsmuxer, "ts muxer(%d): ismd_stop failed",
            smd_element->dev_handle);
        goto failure;
      }
      break;
    }
    default:
      break;
  }

  GST_DEBUG_OBJECT (tsmuxer, "changed state from %s to %s",
      gst_element_state_get_name(GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name(GST_STATE_TRANSITION_NEXT (transition)));

  return ret;

failure:
  GST_ERROR_OBJECT (tsmuxer, "change state failed");
  return GST_STATE_CHANGE_FAILURE;
}

/**
 * ismd_open
 * Open the ts muxer and get the port
 * @element - element containing tsmuxer
 * returns TRUE if setup is successful
 */
static inline gboolean
ismd_open (GstElement * element)
{
    ISmdGstTSMuxer *tsmuxer = ISMD_GST_TS_MUXER (element);
    ismd_result_t result = ISMD_SUCCESS;
    ISmdGstElement *parent = ISMD_GST_ELEMENT (element);
    ISmdGstPad *srcpad = NULL;
    GList *padlist = NULL;
    ismd_dev_t mux_handle;
    GstCaps *srccaps = NULL;
    GstPad *gstsrcpad = NULL;
    bool ret = TRUE;
    ismd_mux_stream_params_t params;

    result = ismd_mux_open(&mux_handle, tsmuxer->output_stream_type);
    if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (tsmuxer, "ismd_mux_open failed (%d)", result);
        goto error;
    }
    parent->dev_handle = mux_handle;

    padlist = parent->src_pads;
    srcpad = ISMD_GST_PAD (padlist->data);
    result = ismd_mux_get_output_port(parent->dev_handle, &srcpad->ismd_port);
    if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (tsmuxer, "ismd_mux_get_output_port failed (%d)", result);
        goto error;
    }
    parent->ismd_port = srcpad->ismd_port; 

    result = ismd_mux_get_stream_params(parent->dev_handle, &params);
    if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (tsmuxer, "ismd_mux_get_stream_params failed (%d)", result);
	  goto error;
    }

    params.scheduling_mode = tsmuxer->scheduling_mode;
    params.ts_params.transport_stream_id = tsmuxer->transport_stream_id;
    params.ts_params.pat_interval = tsmuxer->pat_interval;
    params.ts_params.program_params.program_num = tsmuxer->program_num;
    params.ts_params.program_params.pmt_interval = tsmuxer->pmt_interval;
    params.ts_params.program_params.pcr_interval = tsmuxer->pcr_interval;
    params.ts_params.program_params.pmt_pid = tsmuxer->pmt_pid;
    params.ts_params.program_params.bitrate = tsmuxer->bitrate;
    params.ts_params.program_params.descriptors = ISMD_BUFFER_HANDLE_INVALID;
    
    result = ismd_mux_set_stream_params(parent->dev_handle, &params);
    if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (tsmuxer, "ismd_mux_set_stream_params failed (%d)", result);
	  goto error;
    }

    gstsrcpad = gst_element_get_static_pad (GST_ELEMENT (tsmuxer), "src_1");
    srccaps = gst_caps_new_simple ("video/mpegts",
             "systemstream", G_TYPE_BOOLEAN,true,
             "packetsize", G_TYPE_INT, tsmuxer->output_stream_type, NULL);

    if (gst_pad_peer_accept_caps (gstsrcpad, srccaps)) {
        GST_DEBUG_OBJECT (tsmuxer, "setting caps downstream to %" GST_PTR_FORMAT,
                srccaps);
        ret = gst_pad_set_caps (gstsrcpad, srccaps);
        if (G_UNLIKELY (!ret)) {
            GST_ERROR_OBJECT (tsmuxer, "failed setting downstream caps to %"
                    GST_PTR_FORMAT, srccaps);
        }
    }
    gst_caps_unref (srccaps);
    gst_object_unref (gstsrcpad);
 
    return TRUE;
	
error:
    if (!ismd_close (element)) {
        GST_ERROR_OBJECT (tsmuxer, "ismd_close() failed.");
    }
    return FALSE;
}

/**
 * ismd_stop
 * Stop the ts muxer
 * @element - element containing tsmuxer
 * returns TRUE if ts muxer stop was successful
 */
static inline gboolean
ismd_stop (GstElement * element)
{
    ISmdGstTSMuxer *tsmuxer = ISMD_GST_TS_MUXER (element);
    ISmdGstElement *parent = ISMD_GST_ELEMENT (element);
    GST_DEBUG_OBJECT (tsmuxer, "ismd_stop()");
    ismd_dev_flush(parent->dev_handle);

    return TRUE;
}

/**
 * ismd_close
 * Close resources
 * @element - element containing tsmuxer
 * returns TRUE if closing resources was successful
 */
static inline gboolean
ismd_close (GstElement * element)
{

    return TRUE;
}

static void
ismd_gst_ts_muxer_reset (ISmdGstTSMuxer *tsmuxer)
{ 
    ISmdGstTSMuxerPad *tsmuxer_pad = NULL;
    ISmdGstElement *smd_element = ISMD_GST_ELEMENT (tsmuxer);
    GList *node = NULL;
    node = tsmuxer->sinkpads;
    while (node != NULL) {
        tsmuxer_pad = (ISmdGstTSMuxerPad *) node->data;
        node = node->next;
        remove_mux_input_and_free_node(smd_element,tsmuxer_pad);
    }
    g_list_free (tsmuxer->sinkpads);
    tsmuxer->sinkpads = NULL;
    tsmuxer->video_pads = 0;
    tsmuxer->audio_pads = 0;
    tsmuxer->sink_count = 0;
}

static gboolean
ismd_mux_remove_input_by_pad(ISmdGstElement* smd_element, ISmdGstPad *pad){
    ISmdGstTSMuxer *tsmuxer = NULL;
    ISmdGstTSMuxerPad *tsmuxer_pad = NULL;
    GList *node = NULL;

    tsmuxer = ISMD_GST_TS_MUXER(smd_element);
    node = tsmuxer->sinkpads;
    while (node) {
        tsmuxer_pad = (ISmdGstTSMuxerPad *) node->data;
        node = node->next;
        if (tsmuxer_pad->pad == pad){
            remove_mux_input_and_free_node(smd_element,tsmuxer_pad);
            break;
        }
    }
    return TRUE;
}

static gboolean
remove_mux_input_and_free_node(ISmdGstElement* smd_element, ISmdGstTSMuxerPad *tsmuxer_pad){
    ISmdGstTSMuxer *tsmuxer = NULL;
    if (tsmuxer_pad == NULL){
        GST_ERROR_OBJECT(tsmuxer, "remove_mux_input_and_free_node, null pad info");
        return FALSE;
    }
    tsmuxer = ISMD_GST_TS_MUXER(smd_element);
    ismd_mux_remove_input(smd_element->dev_handle, tsmuxer_pad->pid);
    tsmuxer->sinkpads = g_list_remove (tsmuxer->sinkpads, tsmuxer_pad);
    g_free (tsmuxer_pad);
    return TRUE;
}

static gboolean
add_mux_input(ISmdGstElement* smd_element, GstPad * pad, ismd_mux_input_stream_config_t *config){
    ISmdGstTSMuxer *tsmuxer = NULL;
    ISmdGstTSMuxerPad *tsmuxer_pad = NULL;
    ISmdGstPad *ismdpad = NULL ;
    ismd_port_handle_t port = -1;
    ismd_mux_pid_t vpid = ISMD_MUX_AUTO_GENERATE_PID;
    ismd_result_t result;
    ismd_dev_state_t old_state;

    tsmuxer = ISMD_GST_TS_MUXER(smd_element);
    ismdpad = ISMD_GST_PAD(pad);
    if (smd_element->dev_handle == ISMD_DEV_HANDLE_INVALID){
        goto error;
    }
    ismd_dev_get_state(smd_element->dev_handle, &old_state);
    if (old_state != ISMD_DEV_STATE_STOP){
        ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_STOP);
    }
    result =  ismd_mux_add_input(smd_element->dev_handle, config, &vpid, &port);
    if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (tsmuxer, "ismd_mux_add_input failed (%d)", result);
        goto error;
    }
    ismdpad->ismd_port = port;
    tsmuxer_pad = g_malloc0 (sizeof (ISmdGstTSMuxerPad));
    tsmuxer_pad->pad = ismdpad;
    tsmuxer_pad->pid = vpid;
    tsmuxer_pad->port = port;
    tsmuxer_pad->stream_type = config->stream_type;
    tsmuxer_pad->stream_mode = config->stream_mode;
    tsmuxer_pad->ts_offset = config->ts_offset;
    tsmuxer->sinkpads = g_list_prepend (tsmuxer->sinkpads, tsmuxer_pad);
    ismd_dev_set_state (smd_element->dev_handle, old_state);
    tsmuxer->sink_count++; 
    if(tsmuxer->sink_count == tsmuxer->audio_pads + tsmuxer->video_pads)
    {  
      result = ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_PAUSE);
      if (result != ISMD_SUCCESS) 
        GST_ERROR_OBJECT (smd_element, "ismd_sev_set_state failed %d", result);

    }
    return TRUE;
error:
    return FALSE;
}

static gboolean
gst_ts_muxer_vidsink_set_caps(GstPad * pad, GstCaps * vscaps)
{
    GstStructure *structure;
    ISmdGstTSMuxer *tsmuxer = NULL;
    const gchar *mimetype;
    ismd_mux_input_stream_type_t codec_type = ISMD_MUX_STREAM_TYPE_INVALID;
    ISmdGstElement *smd_element;
    ismd_mux_input_stream_config_t vconfig;
	
    tsmuxer = ISMD_GST_TS_MUXER(gst_pad_get_parent (pad));
    smd_element = ISMD_GST_ELEMENT (tsmuxer);
    structure = gst_caps_get_structure (vscaps, 0);
    mimetype = gst_structure_get_name(structure);
	
    vconfig.stream_mode = tsmuxer->input_stream_mode;
    vconfig.ts_offset = DEFAULT_ISMD_TS_MUXER_VIDEO_TSOFFSET;
    vconfig.descriptors = ISMD_BUFFER_HANDLE_INVALID;
    vconfig.event = ISMD_EVENT_HANDLE_INVALID;
	
    if (!strcmp (mimetype, "video/mpeg")) {
        gint mpegversion;
        if (!gst_structure_get_int (structure, "mpegversion", &mpegversion)) {
            goto beach;
        }
        if (mpegversion == 1) {
            codec_type  = ISMD_MUX_STREAM_TYPE_VIDEO_MPEG1;
        } else {
            codec_type  = ISMD_MUX_STREAM_TYPE_VIDEO_MPEG2;
        }
    } else if (!strcmp (mimetype, "video/x-h264")) {
        codec_type  = ISMD_MUX_STREAM_TYPE_VIDEO_H264;
    } else {
        goto beach;
    }
    vconfig.stream_type = codec_type;
    add_mux_input(smd_element, pad, &vconfig);
    return TRUE;
	
beach:
    return FALSE;
}

static gboolean
gst_ts_muxer_audsink_set_caps(GstPad * pad, GstCaps * vscaps)
{
    GstStructure *structure;
    ISmdGstTSMuxer *tsmuxer = NULL;
    const gchar *mimetype;
    ismd_mux_input_stream_type_t codec_type = ISMD_MUX_STREAM_TYPE_INVALID;
    ISmdGstElement *smd_element;
    ismd_mux_input_stream_config_t aconfig;
	
    tsmuxer = ISMD_GST_TS_MUXER(gst_pad_get_parent (pad));
    smd_element = ISMD_GST_ELEMENT (tsmuxer);

    structure = gst_caps_get_structure (vscaps, 0);
    mimetype = gst_structure_get_name(structure);
    aconfig.stream_mode = tsmuxer->input_stream_mode;
    aconfig.ts_offset = DEFAULT_ISMD_TS_MUXER_AUDIO_TSOFFSET;
    aconfig.event = ISMD_EVENT_HANDLE_INVALID;
    if (!strcmp (mimetype, "audio/x-raw-int")) {
        codec_type  = ISMD_MUX_STREAM_TYPE_AUDIO_PCM;
    } else if (!strcmp (mimetype, "audio/x-eac3")) {
        codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP2;
    } else if (!strcmp (mimetype, "audio/x-ddplus")) {
        codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP2;
    } else if (!strcmp (mimetype, "audio/x-private1-dts") ||
            !strcmp (mimetype, "audio/x-dts")) {
        codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_DTS;
    } else if (!strcmp (mimetype, "audio/mpeg") || !strcmp (mimetype, "audio/x-mpeg")) {
        gint mpegversion;
        gst_structure_get_int (structure, "mpegversion", &mpegversion);
        switch (mpegversion) {
            case 1:
                codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_MP2;
                break;
            case 2:
                codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_MP3;
                break;
            case 4:
                    codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_MPEG2_AAC;
                break;
            default:
                GST_ERROR_OBJECT (tsmuxer, "Invalid MPEG version\n");
                goto beach;
        }
    } else if (!strcmp (mimetype, "audio/x-aac")) {
        codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_MPEG2_AAC;
    } else if (!strcmp (mimetype, "audio/x-ac3") || !strcmp (mimetype, "audio/x-dd") ||
            !strcmp (mimetype, "audio/x-private1-ac3")) {
        codec_type = ISMD_MUX_STREAM_TYPE_AUDIO_AC3_DDP;
    } else {
        GST_ERROR_OBJECT (tsmuxer, "unrecognized/unsupported audio format");
        goto beach;
    }
    aconfig.descriptors = ISMD_BUFFER_HANDLE_INVALID;
    aconfig.stream_type = codec_type;
    add_mux_input(smd_element, pad, &aconfig);
    return TRUE;
beach:
    return FALSE;
}

static GstPad *
gst_ts_muxer_request_new_pad (GstElement * element,
    GstPadTemplate * templ, const gchar * req_mimetype)
{
  ISmdGstTSMuxer *tsmuxer = NULL;
  GstPad *pad = NULL;
  ISmdGstPad *newpad = NULL ;
  GstElementClass *klass = NULL;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  gboolean is_audio =  FALSE;
  gchar *name = NULL;

  g_return_val_if_fail (templ != NULL, NULL);

  if (templ->direction != GST_PAD_SINK)
    goto wrong_direction;

  g_return_val_if_fail (ISMD_GST_IS_TS_MUXER(element), NULL);
  tsmuxer = ISMD_GST_TS_MUXER (element);

  klass = GST_ELEMENT_GET_CLASS (element);

  if (templ == gst_element_class_get_pad_template (klass, "audio_%d")) {
    /* setup pad */
    name = g_strdup_printf ("audio_%02d", tsmuxer->audio_pads);
    tsmuxer->audio_pads++;
    GST_DEBUG_OBJECT (tsmuxer, "adding new pad: %s", name);
    newpad = ismd_gst_pad_new_from_template(templ, name);
    g_free (name);
    is_audio = TRUE;
  } else if (templ == gst_element_class_get_pad_template (klass, "video_%d")) {
    if (tsmuxer->video_pads > 0)
      return NULL;
    /* setup pad */
    tsmuxer->video_pads = 1;
    newpad = ismd_gst_pad_new_from_template (templ, "video_00");
  }else{ 
    goto wrong_template;
  }

  ismd_gst_element_register_sinkpad(smd_element, newpad);
  pad = GST_PAD (newpad);
  gst_element_add_pad (GST_ELEMENT (smd_element), pad);
  if (is_audio == TRUE){
      gst_pad_set_setcaps_function (pad,
              GST_DEBUG_FUNCPTR (gst_ts_muxer_audsink_set_caps));
  }else{
      gst_pad_set_setcaps_function (pad,
              GST_DEBUG_FUNCPTR (gst_ts_muxer_vidsink_set_caps));
  }
  return pad;
  
wrong_direction:
wrong_template:
  {
      g_warning ("ts muxer: this is not our template!\n");
      return NULL;
  }
}

static void
gst_ts_muxer_release_pad (GstElement * element, GstPad * pad)
{
    ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
    ISmdGstPad *ismdpad = ISMD_GST_PAD(pad);
    ismd_mux_remove_input_by_pad(smd_element, ismdpad);
    ismd_gst_element_unregister_sinkpad(smd_element, ismdpad);
    return ;
}

static void
ismd_gst_ts_muxer_get_property (GObject * object, guint prop_id,
        GValue * value, GParamSpec * pspec)
{
    ISmdGstTSMuxer *tsmuxer = ISMD_GST_TS_MUXER (object);

    switch (prop_id) {
        case PROP_TS_MUXER_OUTPUT_STREAM_TYPE:
            g_value_set_enum(value, tsmuxer->output_stream_type);
            break;
        case PROP_TS_MUXER_SCHEDULING_MODE:
            g_value_set_enum(value, tsmuxer->scheduling_mode);
            break;
        case PROP_TS_MUXER_PAT_INTERVAL:
            g_value_set_uint64 (value, tsmuxer->pat_interval);
            break;
        case PROP_TS_MUXER_PMT_INTERVAL:
            g_value_set_uint64 (value, tsmuxer->pmt_interval);
            break;
        case PROP_TS_MUXER_PCR_INTERVAL:
            g_value_set_uint64 (value, tsmuxer->pcr_interval);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
            break;
    }
}


static void
ismd_gst_ts_muxer_set_property (GObject * object, guint prop_id,
        const GValue * value, GParamSpec * pspec)
{
    ISmdGstTSMuxer *tsmuxer = ISMD_GST_TS_MUXER (object);

    switch (prop_id) {
        case PROP_TS_MUXER_OUTPUT_STREAM_TYPE:
            tsmuxer->output_stream_type = g_value_get_enum(value);
            break;
        case PROP_TS_MUXER_SCHEDULING_MODE:
            tsmuxer->scheduling_mode = g_value_get_enum(value);
            break;
        case PROP_TS_MUXER_PAT_INTERVAL:
            tsmuxer->pat_interval= g_value_get_uint64(value);
            break;
        case PROP_TS_MUXER_PMT_INTERVAL:
            tsmuxer->pmt_interval= g_value_get_uint64(value);
            break;
        case PROP_TS_MUXER_PCR_INTERVAL:
            tsmuxer->pcr_interval= g_value_get_uint64(value);
            break;
	 default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
            break;
    }
}


static void
ismd_gst_ts_muxer_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_ts_muxer_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Hardware MPEG Transport Stream Muxer",
      "Codec/Muxer",
      "Multiplexes media streams into an MPEG Transport Stream",
      "http://www.intelconsumerelectronics.com/");

  GstElementClass *element_class = GST_ELEMENT_CLASS (g_class);
  gst_element_class_set_details (element_class, &ismd_gst_ts_muxer_details);

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&video_sink_factory));
  
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&audio_sink_factory));
  
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&src_factory));

}

static void
ismd_gst_ts_muxer_class_init (ISmdGstTSMuxerClass * klass)
{
    GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
    GObjectClass *oclass = G_OBJECT_CLASS (klass);
    ISmdGstElementClass *iclass = ISMD_GST_ELEMENT_CLASS (klass);

    oclass->get_property = ismd_gst_ts_muxer_get_property;
    oclass->set_property = ismd_gst_ts_muxer_set_property;

    oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_ts_muxer_dispose);
    oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_ts_muxer_finalize);
	
    g_object_class_install_property (oclass,
            PROP_TS_MUXER_OUTPUT_STREAM_TYPE,
            g_param_spec_enum("output-stream-type",
                "Output Stream Type",
                "the stream type of ts output:188/192",
                GST_TYPE_ISMD_TS_MUXER_OUTPUT_STREAM_TYPE,
                DEFAULT_ISMD_TS_MUXER_OUTPUT_STREAM_TYPE, G_PARAM_READWRITE));
	
    g_object_class_install_property (oclass,
            PROP_TS_MUXER_SCHEDULING_MODE,
            g_param_spec_enum("scheduling-mode",
                "Scheduling Mode",
                "the mux scheduling between its inputs",
                GST_TYPE_ISMD_TS_MUXER_SCHEDULING_MODE,
                DEFAULT_ISMD_TS_MUXER_SCHEDULING_MODE, G_PARAM_READWRITE));

	g_object_class_install_property (oclass, PROP_TS_MUXER_PAT_INTERVAL,
		g_param_spec_uint64 ("pat-interval", "PAT Interval", 
			"PAT interval on output stream", 900, 5400000, DEFAULT_ISMD_TS_MUXER_PAT_INTERVAL, G_PARAM_READWRITE));

	g_object_class_install_property (oclass, PROP_TS_MUXER_PMT_INTERVAL,
		g_param_spec_uint64 ("pmt-interval", "PMT Interval", 
			"PMT interval on output stream", 900, 5400000, DEFAULT_ISMD_TS_MUXER_PMT_INTERVAL, G_PARAM_READWRITE));

	g_object_class_install_property (oclass, PROP_TS_MUXER_PCR_INTERVAL,
		g_param_spec_uint64 ("pcr-interval", "PCR Interval", 
			"PCR interval on output stream", 900, 9000, DEFAULT_ISMD_TS_MUXER_PCR_INTERVAL, G_PARAM_READWRITE));

    eclass->request_new_pad =
        GST_DEBUG_FUNCPTR (gst_ts_muxer_request_new_pad);
    eclass->release_pad = GST_DEBUG_FUNCPTR (gst_ts_muxer_release_pad);
    eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_ts_muxer_change_state);
    iclass->is_ts_muxer = TRUE;

}

static void
ismd_gst_ts_muxer_init (ISmdGstTSMuxer * tsmuxer,
        ISmdGstTSMuxerClass * g_class)
{
    GstPadTemplate *templ = NULL;
    ISmdGstPad *srcpad = NULL;
    ISmdGstElement *smd_element = ISMD_GST_ELEMENT (tsmuxer);
	
    templ = gst_pad_template_new ("src", GST_PAD_SRC, GST_PAD_ALWAYS,
            gst_static_caps_get (&srccap));
    srcpad = ismd_gst_pad_new_from_template (templ, "src_1");
    ismd_gst_element_register_srcpad (smd_element, srcpad);
    gst_element_add_pad (GST_ELEMENT (smd_element), GST_PAD (srcpad));
    gst_object_unref (templ);

    tsmuxer->audio_pads = 0;
    tsmuxer->video_pads = 0;
    tsmuxer->sink_count = 0;
    tsmuxer->output_stream_type = DEFAULT_ISMD_TS_MUXER_OUTPUT_STREAM_TYPE;
    tsmuxer->input_stream_mode = DEFAULT_ISMD_TS_MUXER_INPUT_STREAM_MODE;
    tsmuxer->scheduling_mode = DEFAULT_ISMD_TS_MUXER_SCHEDULING_MODE;
    tsmuxer->transport_stream_id = DEFAULT_ISMD_TS_MUXER_TRANSPORT_STREAM_ID;
    tsmuxer->program_num = DEFAULT_ISMD_TS_MUXER_PROGRAM_NUM;
    tsmuxer->pmt_pid = DEFAULT_ISMD_TS_MUXER_PMT_PID;
    tsmuxer->bitrate = DEFAULT_ISMD_TS_MUXER_BITRATE;
    tsmuxer->pat_interval = DEFAULT_ISMD_TS_MUXER_PAT_INTERVAL;
    tsmuxer->pmt_interval = DEFAULT_ISMD_TS_MUXER_PMT_INTERVAL;
    tsmuxer->pcr_interval = DEFAULT_ISMD_TS_MUXER_PCR_INTERVAL;
}


