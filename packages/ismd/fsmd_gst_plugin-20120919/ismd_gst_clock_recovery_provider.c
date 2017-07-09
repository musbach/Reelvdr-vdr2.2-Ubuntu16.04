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

#include "ismd_gst_clock_recovery_provider.h"

GST_DEBUG_CATEGORY_STATIC (ismd_gst_clock_recovery_provider_debug);
#define GST_CAT_DEFAULT ismd_gst_clock_recovery_provider_debug

enum
{
  PROP_0,
  PROP_PCR
};

#define TS_PACKET_SYNC_CODE     0x47
#define TS_MIN_PACKET_SIZE      188
#define INVALID_PID             ((guint16)-1)
#define DEFAULT_PCR             INVALID_PID

static GstStaticPadTemplate sink_template_factory =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("video/mpegts"));

static GstStaticPadTemplate src_template_factory =
GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("video/mpegts"));

GST_BOILERPLATE (ISmdGstClockRecoveryProvider,
    ismd_gst_clock_recovery_provider, GstBaseTransform,
    GST_TYPE_BASE_TRANSFORM);


/*
   transport_packet(){
   sync_byte                       8 bslbf
   transport_error_indicator       1 bslbf
   payload_unit_start_indicator    1 bslbf
   transport_priority              1 bslbf
   PID                             13 uimsbf

   transport_scrambling_control    2 bslbf
   adaptation_field_control        2 bslbf
   continuity_counter              4 uimsbf
   if(adaptation_field_control = = '10' || adaptation_field_control = = '11'){
   adaptation_field()
   }
   if(adaptation_field_control = = '01' || adaptation_field_control = = '11') {
   for (i = 0; i < N; i++){
   data_byte 8 bslbf
   }
   }
   adaptation_field() {
   adaptation_field_length                     8 uimsbf
   if (adaptation_field_length > 0) {
   discontinuity_indicator                 1 bslbf
   random_access_indicator                 1 bslbf
   elementary_stream_priority_indicator    1 bslbf
   PCR_flag                                1 bslbf
   OPCR_flag                               1 bslbf
   splicing_point_flag                     1 bslbf
   transport_private_data_flag             1 bslbf
   adaptation_field_extension_flag         1 bslbf
   if (PCR_flag = = '1') {
   program_clock_reference_base        33 uimsbf
   reserved                            6 bslbf
   program_clock_reference_extension   9 uimsbf
   }
   ---- et cetera ----
   }
 */

static gboolean
is_sync_valid (const guint8 * in_data, guint size, guint offset)
{
  static const guint packet_sizes[] = { 188, 192, 204, 208 };
  gint i;

  for (i = 0; i < 4 && (offset + packet_sizes[i]) < size; i++) {
    if (in_data[offset + packet_sizes[i]] == TS_PACKET_SYNC_CODE) {
      return TRUE;
    }
  }
  return FALSE;
}

static void
do_clock_recovery (ISmdGstClockRecoveryProvider * filter,
    const guint8 * in_data, guint size)
{
  guint i = 0;
  ISmdGstClock *clock = NULL;
  ismd_time_t current_time = 0;

  /* Clock recovery can only be performed when the clock_sync_handle is
   * available */
  if (G_UNLIKELY (filter->clock_sync_handle == ISMD_DEV_HANDLE_INVALID)) {
    goto beach;
  }
  /* Clock recovery can only be performed on SMD clocks */
  if (G_LIKELY (ISMD_GST_IS_CLOCK (GST_ELEMENT (filter)->clock))) {
    clock = ISMD_GST_CLOCK (GST_ELEMENT (filter)->clock);
  } else {
    goto beach;
  }

  /* i + ts_packet_size will be equal to size for the last TS packet */
  while ((i + TS_MIN_PACKET_SIZE) <= size) {
    if (TS_PACKET_SYNC_CODE == in_data[i]) {
      /* Check the next SYNC byte for all packets except the last packet
       * in a buffer... */
      if (G_LIKELY (is_sync_valid (in_data, size, i))) {
        /* Check Adaptation field, if it == b10 or b11 */
        if (0x20 & in_data[i + 3]) {
          guint16 pid;

          /* Check PID Match */
          pid = ((in_data[i + 1] & 0x1F) << 8) | in_data[i + 2];

          if (pid == filter->pcr_pid) {
            /* Check Adaptation field size */
            if (0 != in_data[i + 4]) {
              /* Check if PCR is present */
              if (0x10 & in_data[i + 5]) {
                gint pcr;

                /* We're tossing out the MSB of this PCR
                 * because it is not necessary to satisfy
                 * the SoftPLL, mathematically
                 */
                pcr = (in_data[i + 6] << 25) |
                    (in_data[i + 7] << 17) |
                    (in_data[i + 8] << 9) |
                    (in_data[i + 9] << 1) | ((in_data[i + 10] >> 7) & 0x1);


                ismd_clock_get_time (clock->dev_handle, &current_time);
                clock_sync_add_pair (filter->clock_sync_handle, pcr,
                    current_time);
                GST_LOG_OBJECT (filter, "add recovery pair %x %llx",
                    pcr, current_time);
                goto beach;     /* ONLY SEND THE FIRST PCR */
              }
            }
          }
        }
        /* Skip to start of next TSPacket (pre-subract for the i++ later) */
        i += (TS_MIN_PACKET_SIZE - 1);
      }
    }
    i++;                        /* next byte in buffer until we find sync */
  }

beach:
  return;
}

static GstFlowReturn
ismd_gst_clock_recovery_provider_transform_ip (GstBaseTransform * trans,
    GstBuffer * in)
{
  ISmdGstClockRecoveryProvider *filter;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (trans);

  GST_OBJECT_LOCK (filter);
  if (filter->pcr_pid != INVALID_PID) {
    do_clock_recovery (filter, GST_BUFFER_DATA (in), GST_BUFFER_SIZE (in));
  }
  GST_OBJECT_UNLOCK (filter);

  return GST_FLOW_OK;
}

static gboolean
ismd_gst_clock_recovery_provider_event (GstBaseTransform * trans,
    GstEvent * event)
{
  gboolean ret = TRUE;

  if (GST_EVENT_TYPE (event) == GST_EVENT_NEWSEGMENT) {
    GstEvent *news;

    /* Send out a (0, -1) newsegment in bytes */
    news = gst_event_new_new_segment (TRUE, 1.0, GST_FORMAT_BYTES, 0, -1, 0);

    gst_pad_event_default (trans->sinkpad, news);

  }

  ret = parent_class->event (trans, event);

  if (GST_EVENT_TYPE (event) == GST_EVENT_NEWSEGMENT) {
    /* Eat the newsegment */
    ret = FALSE;
  }
  return ret;
}

GstClock *
ismd_gst_clock_recovery_provider_provide_clock (GstElement * element)
{
  ISmdGstClockRecoveryProvider *filter;
  GstClock *clock;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (element);

  if (G_UNLIKELY (filter->provided_clock == NULL)) {
    filter->provided_clock = ismd_gst_clock_get_default_clock();
  }
  clock = GST_CLOCK_CAST (gst_object_ref (filter->provided_clock));

  GST_INFO_OBJECT (filter, "provide %p (ID:%d)",
      clock, filter->provided_clock->dev_handle);
  return clock;
}

static gboolean
ismd_gst_clock_recovery_provider_set_clock (GstElement * element,
    GstClock * clock)
{
  ISmdGstClockRecoveryProvider *filter;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (element);

  if (ISMD_GST_IS_CLOCK (clock)) {
    ISmdGstClock *smd_clock = ISMD_GST_CLOCK (clock);
    GST_INFO_OBJECT (element, "Received SMD clock %p (ID:%d)",
        smd_clock, smd_clock->dev_handle);
  } else {
    GST_INFO_OBJECT (element, "Received Non SMD clock");
  }
  return TRUE;
}

static GstStateChangeReturn
ismd_gst_clock_recovery_provider_change_state (GstElement * element,
    GstStateChange transition)
{
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
  ismd_result_t result;
  ISmdGstClockRecoveryProvider *filter;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (element);
  switch (transition) {
    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
    {
      if (ISMD_GST_IS_CLOCK (element->clock)
            && filter->clock_sync_handle == ISMD_DEV_HANDLE_INVALID) {
        ISmdGstClock *clock = ISMD_GST_CLOCK (element->clock);

        result = clock_sync_open (&(filter->clock_sync_handle));
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (filter, "clock_sync_open failed(%d)", result);
          filter->clock_sync_handle = ISMD_DEV_HANDLE_INVALID;
          goto failure;
        }

        result = clock_sync_set_clock (filter->clock_sync_handle,
            clock->dev_handle);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (filter, "clock_sync_set_clock failed(%d)", result);
          goto recovery_failure;
        }

        result =
            clock_sync_set_algorithm (filter->clock_sync_handle, PID_FILTERING);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (filter, "clock_sync_set_algorithm failed(%d)",
              result);
          goto recovery_failure;
        }
        ismd_gst_clock_bufmon_add_source (clock, filter->clock_sync_handle);
      }
      break;
    }
    default:
      break;
  }

  /* Chain up to the parent class's state change function */
  ret = GST_ELEMENT_CLASS (parent_class)->change_state (element, transition);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_READY_TO_NULL:
    {
      if (filter->clock_sync_handle != ISMD_DEV_HANDLE_INVALID) {
        result = clock_sync_close (filter->clock_sync_handle);
        if (result != ISMD_SUCCESS) {
          GST_ERROR_OBJECT (filter, "clock_sync_close failed(%d)", result);
        }
        filter->clock_sync_handle = ISMD_DEV_HANDLE_INVALID;
      }
      break;
    }
    default:
      break;
  }

  return ret;

failure:
  GST_DEBUG_OBJECT (filter, "state change failed");
  return GST_STATE_CHANGE_FAILURE;

recovery_failure:
  GST_DEBUG_OBJECT (filter, "couldn't configure clock recovery");
  clock_sync_close (filter->clock_sync_handle);
  filter->clock_sync_handle = ISMD_DEV_HANDLE_INVALID;
  return GST_STATE_CHANGE_FAILURE;
}

static void
ismd_gst_clock_recovery_provider_set_property (GObject * object,
    guint prop_id, const GValue * value, GParamSpec * pspec)
{
  ISmdGstClockRecoveryProvider *filter;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (object);

  switch (prop_id) {
    case PROP_PCR:
      GST_OBJECT_LOCK (filter);
      filter->pcr_pid = g_value_get_uint (value);
      GST_DEBUG_OBJECT (filter, "setting PCR pid to %04x", filter->pcr_pid);
      GST_OBJECT_UNLOCK (filter);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_clock_recovery_provider_get_property (GObject * object,
    guint prop_id, GValue * value, GParamSpec * pspec)
{
  ISmdGstClockRecoveryProvider *filter;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (object);

  switch (prop_id) {
    case PROP_PCR:
      GST_OBJECT_LOCK (filter);
      g_value_set_uint (value, filter->pcr_pid);
      GST_OBJECT_UNLOCK (filter);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_clock_recovery_provider_dispose (GObject * object)
{
  ISmdGstClockRecoveryProvider *filter;

  filter = ISMD_GST_CLOCK_RECOVERY_PROVIDER (object);

  if (filter->provided_clock)
    gst_object_unref (filter->provided_clock);
  filter->provided_clock = NULL;
  G_OBJECT_CLASS (parent_class)->dispose (object);
}

static void
ismd_gst_clock_recovery_provider_finalize (GObject * obj)
{
  G_OBJECT_CLASS (parent_class)->finalize (obj);
}

static void
ismd_gst_clock_recovery_provider_base_init (gpointer g_class)
{
  GstElementClass *element_class = g_class;
  static const GstElementDetails ismd_gst_clock_recovery_provider_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Clock Recovery/Provider",
      "Element/Clock Provider",
      "GStreamer Clock Recovery/Provider Element for Intel's Media Processors",
      "http://www.intelconsumerelectronics.com/");

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&sink_template_factory));
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&src_template_factory));

  gst_element_class_set_details (element_class,
      &ismd_gst_clock_recovery_provider_details);
}

static void
ismd_gst_clock_recovery_provider_class_init (ISmdGstClockRecoveryProviderClass *
    klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
  GstBaseTransformClass *trans_class = GST_BASE_TRANSFORM_CLASS (klass);
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);

  gobject_class->get_property = ismd_gst_clock_recovery_provider_get_property;
  gobject_class->set_property = ismd_gst_clock_recovery_provider_set_property;

  g_object_class_install_property (gobject_class, PROP_PCR,
      g_param_spec_uint ("pcr", "PCR",
          "Specifies the PCR pid to perform the clock recovery.",
          0, 0xffff, DEFAULT_PCR, G_PARAM_READWRITE));

  gobject_class->dispose = ismd_gst_clock_recovery_provider_dispose;
  gobject_class->finalize = ismd_gst_clock_recovery_provider_finalize;

  GST_DEBUG_CATEGORY_INIT (ismd_gst_clock_recovery_provider_debug,
      "ISMD_CLOCK_RECOVERY_PROVIDER", (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN),
      "ismdgst_clock_recovery_provider element");

  trans_class->transform_ip =
      GST_DEBUG_FUNCPTR (ismd_gst_clock_recovery_provider_transform_ip);
  trans_class->event =
      GST_DEBUG_FUNCPTR (ismd_gst_clock_recovery_provider_event);
  trans_class->passthrough_on_same_caps = TRUE;

  element_class->change_state =
      GST_DEBUG_FUNCPTR (ismd_gst_clock_recovery_provider_change_state);
  element_class->provide_clock =
      GST_DEBUG_FUNCPTR (ismd_gst_clock_recovery_provider_provide_clock);
  element_class->set_clock =
      GST_DEBUG_FUNCPTR (ismd_gst_clock_recovery_provider_set_clock);
}

static void
ismd_gst_clock_recovery_provider_init (ISmdGstClockRecoveryProvider * filter,
    ISmdGstClockRecoveryProviderClass * g_class)
{
  filter->provided_clock = NULL;
  filter->clock_sync_handle = ISMD_DEV_HANDLE_INVALID;
  filter->pcr_pid = DEFAULT_PCR;
}
