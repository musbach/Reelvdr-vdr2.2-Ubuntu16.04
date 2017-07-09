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

#include <stdlib.h>
#include <string.h>

#include "ismd_gst_element.h"
#include "ismd_gst_vc1_viddec.h"
#include "ismd_viddec.h"

// Forward declarations of private API functions in viddec driver to enable
// special PTS re-ordering mode for Netflix content (ECR #200091).  This
// only affects VC-1 content (see ismd_viddec_pvt.h)
ismd_result_t ismd_viddec_enable_host_pts_reordering (ismd_dev_t viddec);
ismd_result_t ismd_viddec_disable_host_pts_reordering (ismd_dev_t viddec);

static GstBuffer *ismd_gst_vc1_viddec_convert_SPMP (ISmdGstVc1Viddec * viddec,
    GstBuffer * buf, gboolean need_seq_hdr);
static GstBuffer *ismd_gst_vc1_viddec_convert_AP (ISmdGstVc1Viddec * viddec,
    GstBuffer * buf, gboolean need_seq_hdr);
static GstBuffer *ismd_gst_vc1_viddec_convert_AP_ASF (ISmdGstVc1Viddec * viddec,
    GstBuffer * buf, gboolean need_seq_hdr);
static GstBuffer *ismd_gst_vc1_viddec_convert_UN (ISmdGstVc1Viddec * viddec,
    GstBuffer * buf, gboolean need_seq_hdr);
static void ismd_gst_vc1_viddec_finalize (GObject * object);
static GstBuffer *ismd_gst_vc1_viddec_convert (ISmdGstElement * smd_element,
    GstBuffer * buf, gboolean need_seq_hdr);
static inline int
ismd_gst_vc1_viddec_encapsulate_and_write_ebdu (ISmdGstVc1Viddec * viddec,
    guint8 * pDes, guint SizeDes, guint8 * pRbdu, guint SizeRBDU);
static void
ismd_gst_vc1_viddec_SPMP_PESpacket_PayloadFormatHeader (ISmdGstVc1Viddec *
    viddec, GstBuffer * pCodecData, gint width, gint height);

#define ISMD_GST_VC1_VIDDEC_SINK_CAPS \
           "video/x-wmv, " \
           "  wmvversion = (int)3, " \
           "  format = (fourcc) { WMV3, WVC1 }"

#define ISMD_GST_VC1_VIDDEC_SRC_CAPS \
           "video/x-decoded-ismd"

static GstStaticPadTemplate ismd_gst_vc1_viddec_sinkpad_template =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VC1_VIDDEC_SINK_CAPS)
    );

static GstStaticPadTemplate ismd_gst_vc1_viddec_srcpad_template =
GST_STATIC_PAD_TEMPLATE ("src_1",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (ISMD_GST_VC1_VIDDEC_SRC_CAPS)
    );

static GstStaticCaps srccap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_VC1_VIDDEC_SRC_CAPS };
static GstStaticCaps sinkcap =
    { {0, 0, (GstCapsFlags) 0}, ISMD_GST_VC1_VIDDEC_SINK_CAPS };

GST_DEBUG_CATEGORY_STATIC (ismd_gst_vc1_viddec_debug);
#define GST_CAT_DEFAULT ismd_gst_vc1_viddec_debug

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_vc1_viddec_debug, "ISMD_VC1_VIDDEC",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstvc1viddec element");
}

GST_BOILERPLATE_FULL (ISmdGstVc1Viddec, ismd_gst_vc1_viddec,
    ISmdGstElement, ISMD_GST_TYPE_ELEMENT, _do_init);

static void
ismd_gst_vc1_viddec_drop_badframes (ISmdGstElement * smd_element,
    gboolean enable)
{
  ISmdGstVc1Viddec *viddec = ISMD_GST_VC1_VIDDEC (smd_element);  
  ismd_viddec_frame_error_policy_t policy =
      ISMD_VIDDEC_EMIT_ERROR_CONCEAL_FRAMES;
  ismd_result_t result;
      
  GST_DEBUG_OBJECT (viddec, "drop on decoding errors set to: %d", enable);
  if (!enable) {
    policy = ISMD_VIDDEC_EMIT_ALL;
  }
  
  result = ismd_viddec_set_frame_error_policy (smd_element->dev_handle,
      policy);
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (viddec,
        "ismd_viddec_set_frame_error_policy failed(%d)", result);
  }
  viddec->drop_badframes = enable;
}

static GstPadLinkReturn
ismd_gst_vc1_viddec_sinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  GstStructure *structure;
  ISmdGstVc1Viddec *viddec;
  ISmdGstElement *parent;
  ismd_result_t result;
  const GValue *pVar = NULL;
  GstBuffer *pBuf = NULL;
  GstPad *srcpad;
  GstCaps *srccaps;
  gboolean ret = FALSE;
  guint32 fourcc = 0;
  gint width = 0;
  gint height = 0;
  const GValue * par;

  viddec = ISMD_GST_VC1_VIDDEC (gst_pad_get_parent (pad));
  parent = ISMD_GST_ELEMENT (viddec);

  GST_DEBUG_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  if (!(structure = gst_caps_get_structure (caps, 0))) {
    GST_ERROR_OBJECT (pad, "no caps found");
    goto beach;
  }

  if (gst_structure_has_name (structure, "video/x-wmv")) {
    viddec->vCodec = ISMD_CODEC_TYPE_VC1;

    if (!gst_structure_get_fourcc (structure, "format", &fourcc)) {
      GST_ERROR_OBJECT (viddec, "no FOURCC format found");
      goto beach;
    }

    par = gst_structure_get_value (structure, "pixel-aspect-ratio");
    if (par) {
      parent->par_x = gst_value_get_fraction_numerator (par);
      parent->par_y = gst_value_get_fraction_denominator (par);
    } else {
      parent->par_x = 0;
      parent->par_y = 0;
    }
    result = ismd_viddec_enable_host_pts_reordering (parent->dev_handle);
    if (result != ISMD_SUCCESS)
      GST_WARNING_OBJECT (viddec, "Could not enable VC1 PTS re-ordering mode!");

    // here, codec_data must exist to configure smd decoder
    pVar = gst_structure_get_value (structure, "codec_data");

    if (pVar && GST_VALUE_HOLDS_BUFFER (pVar)) {
      pBuf = gst_buffer_copy (gst_value_get_buffer (pVar));
      GST_DEBUG_OBJECT (viddec, "codec_data size: %d", GST_BUFFER_SIZE (pBuf));
      if (pBuf != NULL) {
        if (GST_MAKE_FOURCC ('W', 'V', 'C', '1') == fourcc) {
          // VC1 AP
          viddec->convert_buffer = ismd_gst_vc1_viddec_convert_UN;
          /* Skip ASF binding byte */
          guint8 *data = GST_BUFFER_DATA (pBuf);
          if (data[0] == 0x00 && data[1] == 0x00 && data[1] == 0x01) {
            GST_DEBUG_OBJECT (viddec, "Start Code found %02x %02x %02x %02x",
                data[0], data[1], data[2], data[3]);
          } else {
            GST_DEBUG_OBJECT (viddec, "Skipping ASF binding byte %02x",
                data[0]);
            GST_BUFFER_DATA (pBuf)++;
            GST_BUFFER_SIZE (pBuf)--;
          }

          viddec->AP_Buffer = pBuf;
        } else if (GST_MAKE_FOURCC ('W', 'M', 'V', '3') == fourcc) {
          if (!gst_structure_get_int (structure, "width", &width)) {
            GST_ERROR_OBJECT (viddec, "no width");
            goto beach;
          }

          if (!gst_structure_get_int (structure, "height", &height)) {
            GST_ERROR_OBJECT (viddec, "no height");
            goto beach;
          }
          // VC1 MP/SP
          viddec->convert_buffer = ismd_gst_vc1_viddec_convert_SPMP;
          // wrap codec_data into sequence header suitable for SP/MP
          ismd_gst_vc1_viddec_SPMP_PESpacket_PayloadFormatHeader (viddec, pBuf,
              width, height);
          gst_buffer_unref (pBuf);
        } else {
          GST_ERROR_OBJECT (viddec, "invalid fourcc is %" GST_FOURCC_FORMAT,
              GST_FOURCC_ARGS (fourcc));
          gst_buffer_unref (pBuf);
          goto beach;
        }
      }
    } else {
      viddec->convert_buffer = NULL;
    }
  } else {
    viddec->convert_buffer = NULL;
  }

  ret = TRUE;
  srcpad = gst_element_get_static_pad (GST_ELEMENT (viddec), "src_1");
  srccaps = gst_caps_new_simple ("video/x-decoded-ismd", NULL);

  if (gst_pad_peer_accept_caps (srcpad, srccaps)) {
    GST_DEBUG_OBJECT (viddec, "setting caps downstream to %" GST_PTR_FORMAT,
        srccaps);
    ret = gst_pad_set_caps (srcpad, srccaps);
    if (G_UNLIKELY (!ret)) {
      GST_ERROR_OBJECT (viddec, "failed setting downstream caps to %"
          GST_PTR_FORMAT, srccaps);
    }
    else {
      GstTagList * taglist = gst_tag_list_new ();

      /* Post a tag with the codec name */
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_VIDEO_CODEC,
          "Windows Media Video 9/VC1", NULL);

      gst_element_found_tags_for_pad (GST_ELEMENT (viddec), srcpad, taglist);
    }    
  }
  gst_caps_unref (srccaps);
  gst_object_unref (srcpad);

beach:
  gst_object_unref (viddec);
  return ret;
}

static void
ismd_gst_vc1_viddec_finalize (GObject * object)
{
  ISmdGstVc1Viddec *viddec = ISMD_GST_VC1_VIDDEC (object);

  if (viddec->AP_Buffer) {
    gst_buffer_unref (viddec->AP_Buffer);
    viddec->AP_Buffer = NULL;
  }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GstBuffer *
ismd_gst_vc1_viddec_convert (ISmdGstElement * smd_element, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  ISmdGstVc1Viddec *viddec = ISMD_GST_VC1_VIDDEC (smd_element);
  GstBuffer *outbuf = NULL;

  GST_DEBUG_OBJECT (viddec, "convert on buffer %p pts %" GST_TIME_FORMAT,
      buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)));

  if (viddec->convert_buffer) {
    outbuf = viddec->convert_buffer (viddec, buf, need_seq_hdr);
    // need to preserve the timestamp
    if (!outbuf) {
      GST_WARNING_OBJECT (viddec, "VC1 conversion failed");
    }
    gst_buffer_unref (buf);
  }
  else {
    /* Passthrough on VC1 raw from MPEG TS for example */
    outbuf = buf;
  }
  return outbuf;
}

static void
ismd_gst_vc1_viddec_drain (ISmdGstElement * smd_element)
{
  ISmdGstVc1Viddec *viddec = ISMD_GST_VC1_VIDDEC (smd_element);
  ismd_result_t result;
  ismd_event_t event_handle;
  gint counter = 0;

  result = ismd_viddec_get_event (smd_element->dev_handle,
      ISMD_VIDDEC_CLIENT_ID_SEEN, &event_handle );
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (viddec, "ismd_viddec_get_event failed(%d)", result);
    goto beach;
  }

  while (result == ISMD_SUCCESS) {
    result = ismd_event_wait (event_handle, 50);
    if (result == ISMD_SUCCESS) {
      ismd_event_acknowledge (event_handle);
      counter = 0;
    }
    else if (result == ISMD_ERROR_TIMEOUT) {
      counter += 50;
      GST_LOG_OBJECT (viddec, "timeout %d", counter);
      if (counter < ISMD_POLL_TIMEOUT) {
        result = ISMD_SUCCESS;
      }
    }
    else {
      GST_WARNING_OBJECT (viddec, "ismd_event_wait failed(%d)", result);
    }
  }

beach:
  return;
}

static gboolean
ismd_gst_vc1_viddec_event (ISmdGstElement * smd_element, GstEvent * event)
{
  GST_DEBUG_OBJECT (smd_element, "handling event %s",
      GST_EVENT_TYPE_NAME (event));
  switch (event->type) {
    case GST_EVENT_NEWSEGMENT:
      {
        ismd_viddec_frame_skip_policy_t mask;
        gdouble rate;
        gst_event_parse_new_segment (event, NULL, &rate, NULL, NULL,
            NULL, NULL);
        if (rate > 2.0 || rate < 0.0) {
          mask = ISMD_VIDDEC_SKIP_FRAME_TYPE_P | ISMD_VIDDEC_SKIP_FRAME_TYPE_B;
          GST_DEBUG_OBJECT (smd_element, "switch to only keyframe decoding mode");
        } else {
          mask = ISMD_VIDDEC_SKIP_NONE;
          GST_DEBUG_OBJECT (smd_element, "switch to normal decoding mode");
        }
        ismd_viddec_set_frame_mask (smd_element->dev_handle, mask);
      }
      break;
    case GST_EVENT_CUSTOM_DOWNSTREAM:
      {
        ismd_result_t result;
        const GstStructure *s = gst_event_get_structure (event);

        if (gst_structure_has_name (s, "GstGOPInfo")) {
          gint present_frames = 0;
          gst_structure_get_int (s, "present-frames", &present_frames);
          GST_DEBUG_OBJECT (smd_element, "going to present %d frames out"
              " of next GOP", present_frames);
          result =
              ismd_viddec_set_max_frames_to_decode (smd_element->dev_handle,
              present_frames == 0 ? ISMD_VIDDEC_ALL_FRAMES : present_frames);
          if (result != ISMD_SUCCESS) {
            GST_ERROR_OBJECT (smd_element,
                "could not set viddec max_frames_to_decode: %d", present_frames);
          }
        }              
      }
      break;
    case GST_EVENT_FLUSH_START:
      ismd_gst_vc1_viddec_drop_badframes (smd_element, TRUE);
      break;
    default:
      break;
  }
  return TRUE;
}

static GstStateChangeReturn
ismd_gst_vc1_viddec_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstVc1Viddec *viddec;
  viddec = ISMD_GST_VC1_VIDDEC (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ismd_result_t result;
  ISmdGstPad *gstpad;
  GList *padlist;

  switch (transition) {
    case GST_STATE_CHANGE_NULL_TO_READY:
      // initialize the device but don't consume data
      result = ismd_viddec_open (viddec->vCodec, &(smd_element->dev_handle));
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "ismd_viddec_open failed(%d)", result);
        goto failure;
      }
#if 0
      result =
          ismd_viddec_set_pts_interpolation_policy (smd_element->dev_handle,
          ISMD_VIDDEC_INTERPOLATE_MISSING_PTS, ISMD_NO_PTS);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec,
            "ismd_viddec_set_pts_interpolation_policy failed(%d)", result);
        goto failure;
      }
#endif

      result = ismd_viddec_get_input_port (smd_element->dev_handle,
          &(smd_element->sink_pad->ismd_port));
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "viddec get input port failed(%d)", result);
        goto failure;
      }

      padlist = smd_element->src_pads;
      gstpad = ISMD_GST_PAD (padlist->data);

      ismd_viddec_get_output_port (smd_element->dev_handle, &gstpad->ismd_port);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (viddec, "viddec get output port failed(%d)", result);
        goto failure;
      }
      ismd_gst_vc1_viddec_drop_badframes (smd_element, TRUE);
      break;
    case GST_STATE_CHANGE_READY_TO_PAUSED:
      /* start the decoder with the new data - SMD_GST_PADS must have a valid
         ismd_port_id after this function is called */
      viddec->flag = 1;
      break;
    case GST_STATE_CHANGE_READY_TO_NULL:
      result =
          ismd_viddec_disable_host_pts_reordering (smd_element->dev_handle);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (viddec,
            "Could not disable VC1 PTS re-ordering mode!");
      }
      break;
    default:
      break;
  }

  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
      ismd_gst_vc1_viddec_drop_badframes (smd_element, TRUE);
      break;
    default:
      break;
  }

  return ret;

failure:
  return GST_STATE_CHANGE_FAILURE;
}

static void
ismd_gst_vc1_viddec_SPMP_PESpacket_PayloadFormatHeader (ISmdGstVc1Viddec *
    viddec, GstBuffer * pCodecData, gint width, gint height)
{
  if (viddec->size_SPMP_PESpacket_PayloadFormatHeader > 0) {
    viddec->size_SPMP_PESpacket_PayloadFormatHeader = 0;
    memset (viddec->SPMP_PESpacket_PayloadFormatHeader, 0,
        MAX_SIZE_PES_SEQUENCE_HEADER);
  }

  guint8 pSeqHeaderRbdu[8];

  guint8 *pSequenceHdr = GST_BUFFER_DATA (pCodecData);

  // todo: use a better check here
  if (GST_BUFFER_SIZE (pCodecData) > 5) {
    GST_ELEMENT_ERROR (viddec, STREAM, FORMAT, ("Invalid codec data"),
        ("Codec data size %d", GST_BUFFER_SIZE (pCodecData)));
    return;
  }
  // Now form the SEQ header RBDU

  // MaxCodedWidth and MaxCodedHeight (width and height?)
  //
  // These are little-endian values in the RCV file (valid C DWORD's). 16-bit
  // values which go into the SeqHeaderRbdu are therefore extracted bytewise
  //
  pSeqHeaderRbdu[0] = (guint8) ((width >> 8) & 0xFF);
  pSeqHeaderRbdu[1] = (guint8) ((width >> 0) & 0xFF);
  pSeqHeaderRbdu[2] = (guint8) ((height >> 8) & 0xFF);
  pSeqHeaderRbdu[3] = (guint8) ((height >> 0) & 0xFF);
  //
  // The SEQ header
  //
  memcpy (&pSeqHeaderRbdu[4], pSequenceHdr, 4);
  // start code for header: 0x0000010F
  // Annex E.5, SMPTE-421M-FDS1.doc
  viddec->SPMP_PESpacket_PayloadFormatHeader[0] =
      viddec->SPMP_PESpacket_PayloadFormatHeader[1] = 0;
  viddec->SPMP_PESpacket_PayloadFormatHeader[2] = 0x01;
  viddec->SPMP_PESpacket_PayloadFormatHeader[3] = 0x0F;

  guint8 byte_written =
      ismd_gst_vc1_viddec_encapsulate_and_write_ebdu (viddec,
      &viddec->SPMP_PESpacket_PayloadFormatHeader[4], 12, &pSeqHeaderRbdu[0],
      8);

  viddec->size_SPMP_PESpacket_PayloadFormatHeader = 4 + byte_written;
}

/* Unknown: analize first buffer and decide which convert function to use */
static GstBuffer *
ismd_gst_vc1_viddec_convert_UN (ISmdGstVc1Viddec * viddec, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  guint8 *data = GST_BUFFER_DATA (buf);
  GST_DEBUG_OBJECT (viddec, "%02x %02x %02x %02x %02x %02x",
      data[0], data[1], data[2], data[3], data[4], data[5]);
  if (data[0] == 0x00 && data[1] == 0x00 && data[2] == 0x01) {
    GST_DEBUG_OBJECT (viddec, "decided AP");
    viddec->convert_buffer = ismd_gst_vc1_viddec_convert_AP;
    return ismd_gst_vc1_viddec_convert_AP (viddec, buf, need_seq_hdr);
  } else {
    GST_DEBUG_OBJECT (viddec, "decided AP ASF");
    viddec->convert_buffer = ismd_gst_vc1_viddec_convert_AP_ASF;
    return ismd_gst_vc1_viddec_convert_AP_ASF (viddec, buf, need_seq_hdr);
  }
}

static GstBuffer *
ismd_gst_vc1_viddec_convert_AP (ISmdGstVc1Viddec * viddec, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  GstBuffer *pRet = NULL;
  GstBuffer *outbuf = NULL;

  if (viddec->flag) {
    //add sequence header to 1st buffer
    if (viddec->AP_Buffer) {
      gint bufsize =
          GST_BUFFER_SIZE (viddec->AP_Buffer) + GST_BUFFER_SIZE (buf);

      outbuf = gst_buffer_new_and_alloc (bufsize);

      if (outbuf) {
        guint8 *pdata = GST_BUFFER_DATA (outbuf);
        GST_BUFFER_SIZE (outbuf) = 0;

        gst_buffer_copy_metadata (outbuf, buf, GST_BUFFER_COPY_ALL);

        memcpy (pdata, GST_BUFFER_DATA (viddec->AP_Buffer),
            GST_BUFFER_SIZE (viddec->AP_Buffer));
        pdata += GST_BUFFER_SIZE (viddec->AP_Buffer);
        GST_BUFFER_SIZE (outbuf) += GST_BUFFER_SIZE (viddec->AP_Buffer);

        memcpy (pdata, GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));
        pdata += GST_BUFFER_SIZE (buf);
        GST_BUFFER_SIZE (outbuf) += GST_BUFFER_SIZE (buf);

        pRet = outbuf;
      }
    } else {
      pRet = gst_buffer_ref (buf);
    }
    viddec->flag = 0;
  } else {
    // no change to buffer
    pRet = gst_buffer_ref (buf);
  }
  return pRet;
}

static GstBuffer *
ismd_gst_vc1_viddec_convert_AP_ASF (ISmdGstVc1Viddec * viddec, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  GstBuffer *outbuf = NULL;
  guint8 *pCurrent;             // points to next writing position of the new buffer
  gint max_bufsize = 0;

  // Calculate maximum buffer size, make room for encapsulation
  // SMPTE-421M-FDSI doc, Annex-E
  max_bufsize = 4 + ((GST_BUFFER_SIZE (buf) + 3) / 3) * 4;

  if (viddec->flag  || need_seq_hdr) {
    // Allocate extra buffer to include header
    max_bufsize += GST_BUFFER_SIZE (viddec->AP_Buffer);
  }
  // allocate new buffer
  outbuf = gst_buffer_new_and_alloc (max_bufsize);

  if (outbuf) {
    pCurrent = GST_BUFFER_DATA (outbuf);
    GST_BUFFER_SIZE (outbuf) = 0;

    // copy all meta data
    gst_buffer_copy_metadata (outbuf, buf, GST_BUFFER_COPY_ALL);

    if (viddec->flag || need_seq_hdr) {
      GST_DEBUG_OBJECT (viddec, "Added codec_data");
      // copy sequence header to buffer
      memcpy (pCurrent, GST_BUFFER_DATA (viddec->AP_Buffer),
          GST_BUFFER_SIZE (viddec->AP_Buffer));
      // update buffer data size
      GST_BUFFER_SIZE (outbuf) += GST_BUFFER_SIZE (viddec->AP_Buffer);
      // update pointer
      pCurrent += GST_BUFFER_SIZE (viddec->AP_Buffer);
      viddec->flag = 0;
    }
    // time to convert the data

    // Start Code Prefix for frame
    pCurrent[0] = pCurrent[1] = 0;
    pCurrent[2] = 0x01;
    pCurrent[3] = 0x0D;
    pCurrent += 4;
    GST_BUFFER_SIZE (outbuf) += 4;
#if 0
    int byte_written =
        ismd_gst_vc1_viddec_encapsulate_and_write_ebdu (viddec, pCurrent,
        max_bufsize - GST_BUFFER_SIZE (outbuf),
        GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));
    pCurrent += byte_written;
    GST_BUFFER_SIZE (outbuf) += byte_written;
#else
    memcpy (pCurrent, GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));
    pCurrent += GST_BUFFER_SIZE (buf);
    pCurrent[0] = 0x80;
    GST_BUFFER_SIZE (outbuf) += GST_BUFFER_SIZE (buf) + 1;
#endif
    GST_LOG_OBJECT (viddec, "Allocated new buffer %p of size %d used: %d",
        outbuf, max_bufsize, GST_BUFFER_SIZE (outbuf));
    //gst_util_dump_mem (GST_BUFFER_DATA (outbuf), GST_BUFFER_SIZE (outbuf));
  }
  return outbuf;
}

static GstBuffer *
ismd_gst_vc1_viddec_convert_SPMP (ISmdGstVc1Viddec * viddec, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  GstBuffer *outbuf = NULL;
  guint8 *pCurrent;             // points to next writing position of the new buffer
  gint max_bufsize = 0;

  // Calculate maximum buffer size, make room for encapsulation
  // SMPTE-421M-FDSI doc, Annex-E
  max_bufsize = 4 + ((GST_BUFFER_SIZE (buf) + 3) / 3) * 4;

  if (viddec->flag || need_seq_hdr) {
    // Allocate extra buffer to include header
    max_bufsize += viddec->size_SPMP_PESpacket_PayloadFormatHeader;
  }
  // allocate new buffer
  outbuf = gst_buffer_new_and_alloc (max_bufsize);

  if (outbuf) {
    pCurrent = GST_BUFFER_DATA (outbuf);
    GST_BUFFER_SIZE (outbuf) = 0;

    // copy all meta data
    gst_buffer_copy_metadata (outbuf, buf, 
        GST_BUFFER_COPY_FLAGS | GST_BUFFER_COPY_TIMESTAMPS);

    if (viddec->flag || need_seq_hdr) {
      // copy sequence header to buffer
      memcpy (pCurrent, viddec->SPMP_PESpacket_PayloadFormatHeader,
          viddec->size_SPMP_PESpacket_PayloadFormatHeader);
      // update buffer data size
      GST_BUFFER_SIZE (outbuf) +=
          viddec->size_SPMP_PESpacket_PayloadFormatHeader;
      // update pointer
      pCurrent += viddec->size_SPMP_PESpacket_PayloadFormatHeader;
      viddec->flag = 0;
    }
    // time to convert the data

    // Start Code Prefix for frame
    pCurrent[0] = pCurrent[1] = 0;
    pCurrent[2] = 0x01;
    pCurrent[3] = 0x0D;
    pCurrent += 4;
    GST_BUFFER_SIZE (outbuf) += 4;

    int byte_written =
        ismd_gst_vc1_viddec_encapsulate_and_write_ebdu (viddec, pCurrent,
        max_bufsize - GST_BUFFER_SIZE (outbuf),
        GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));

    pCurrent += byte_written;
    GST_BUFFER_SIZE (outbuf) += byte_written;

    GST_LOG_OBJECT (viddec, "Allocate new buffer of size %d. Actual used: %d",
        max_bufsize, GST_BUFFER_SIZE (outbuf));
  }
  return outbuf;
}

// write EBDU. It returns the number of bytes written to pDes
static inline int
ismd_gst_vc1_viddec_encapsulate_and_write_ebdu (ISmdGstVc1Viddec * viddec,
    guint8 * pDes, guint SizeDes, guint8 * pRbdu, guint SizeRBDU)
{
  int ZeroRun = 0;
  int i;
  guint j = 0;

  const guint8 Escape = 0x03;
  const guint8 StopBit = 0x80;  // Byte with a stop bit in the MSB.

  GST_LOG_OBJECT (viddec,
      "v1rbdu: DEST Addr: %p DEST Size: %d RBDU Addr: %p  RBDU Size: %d",
      pDes, SizeDes, pRbdu, SizeRBDU);
  // loop through source
  for (i = 0; i < SizeRBDU; i++) {
    if ((ZeroRun == 2) && (pRbdu[i] <= 0x03)) {
      pDes[j++] = Escape;

      if (j >= SizeDes) {
        j = 0;
        break;
      }
      ZeroRun = 0;
    }

    pDes[j++] = pRbdu[i];

    if (j >= SizeDes) {
      j = 0;
      break;
    }

    if (pRbdu[i] == 0x0) {
      ZeroRun++;
    } else {
      ZeroRun = 0;
    }

  }
  //
  // Stop bit should not be added for a NULL RBDU
  //
  if (!SizeRBDU)
    return j;
  //
  // Add a stop bit at the end of the BDU. Since RCV data is already byte
  // aligned we don't know the bit in the last byte after which the stop bit
  // should be inserted. Therefore we simply add the byte 0x80 at the end of
  // each EBDU. Once again, we are not very certain about this [TBD].
  //
  pDes[j++] = StopBit;
  return j;
}

static GstFlowReturn
ismd_gst_vc1_viddec_push_buffer (ISmdGstElement * smd_element, GstPad * pad,
    GstBuffer * buf)
{
  GstFlowReturn ret = GST_FLOW_OK; 
  ISmdGstVc1Viddec *viddec = ISMD_GST_VC1_VIDDEC (smd_element);

  if (G_UNLIKELY (viddec->drop_badframes)) {
    ismd_gst_vc1_viddec_drop_badframes (smd_element, FALSE);
  }
  
  GST_DEBUG_OBJECT (viddec, "pushing buffer %p pts %" GST_TIME_FORMAT,
      buf, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (buf)));
  ret = gst_pad_push (pad, buf);

  return ret;
}

static void
ismd_gst_vc1_viddec_base_init (gpointer klass)
{
  static GstElementDetails details = {
    "Intel Streaming Media Driver (ISMD) Hardware VC1 Video Decoder",
    "Codec/Decoder/Video",
    "GStreamer Video Decoder Element for Intel Media Processors",
    "http://www.intelconsumerelectronics.com/"
  };

  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GstPadTemplate *curr_tmplt = NULL;
  gst_element_class_set_details (eclass, &details);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_vc1_viddec_sinkpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);

  curr_tmplt =
      gst_static_pad_template_get (&ismd_gst_vc1_viddec_srcpad_template);
  gst_element_class_add_pad_template (eclass, curr_tmplt);
  gst_object_unref (curr_tmplt);
}

static void
ismd_gst_vc1_viddec_class_init (ISmdGstVc1ViddecClass * klass)
{
  GObjectClass *oclass;
  oclass = G_OBJECT_CLASS (klass);
  GstElementClass *eclass;
  eclass = GST_ELEMENT_CLASS (klass);
  ISmdGstElementClass *iclass;
  iclass = ISMD_GST_ELEMENT_CLASS (klass);

  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_finalize);
  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_change_state);
  iclass->drain = GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_drain);
  iclass->event = GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_event);  
  iclass->convert = GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_convert);
  iclass->push_buffer = GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_push_buffer);  
  iclass->is_decoder = TRUE;  
}

static void
ismd_gst_vc1_viddec_init (ISmdGstVc1Viddec * viddec,
    ISmdGstVc1ViddecClass * klass)
{
  GstPad *pad;

  ismd_gst_element_create_pads (ISMD_GST_ELEMENT (viddec), &sinkcap,
      &srccap, 1);

  pad = gst_element_get_static_pad (GST_ELEMENT (viddec), "sink");
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_vc1_viddec_sinkpad_setcaps));
  gst_object_unref (pad);
  viddec->vCodec = ISMD_CODEC_TYPE_VC1;
  memset (&viddec->SPMP_PESpacket_PayloadFormatHeader[0], 0,
      MAX_SIZE_PES_SEQUENCE_HEADER);
  viddec->size_SPMP_PESpacket_PayloadFormatHeader = 0;
  viddec->flag = 1;
  viddec->convert_buffer = NULL;
  viddec->AP_Buffer = NULL;
}


