/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright (c) 2012. Intel Corporation. All rights reserved.
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

#ifndef __ISMD_GST_ELEMENT_H__
#define __ISMD_GST_ELEMENT_H__

#include "ismd_core.h"
#include "ismd_viddec.h"
#include "ismd_gst_buffer.h"
#include "ismd_gst_pad.h"
#include "ismd_gst_clock.h"
#include <gst/gstelement.h>
#include <gst/base/gstadapter.h>

typedef struct _ISmdGstElementClass ISmdGstElementClass;
typedef struct _ISmdGstElement ISmdGstElement;

#define SMD_TO_GST_RATE(rate)  ((gdouble)rate / 10000.0)
#define GST_TO_SMD_RATE(rate)  ((gint)(rate * 10000))

#ifndef GST_CHECK_VERSION
#define GST_CHECK_VERSION(major,minor,micro)  \
    (GST_VERSION_MAJOR > (major) || \
     (GST_VERSION_MAJOR == (major) && GST_VERSION_MINOR > (minor)) || \
     (GST_VERSION_MAJOR == (major) && GST_VERSION_MINOR == (minor) && \
      GST_VERSION_MICRO >= (micro)))
#endif

#define ISMD_EVENT_TIMEOUT 20       /* in miliseconds */
#define ISMD_POLL_TIMEOUT 300       /* in miliseconds */
#define ISMD_BUFFER_SIZE (32*1024)  /* use 32k buffers for now */

/*
 * ISMD Device Basic Operations APIs.  All device module plugin registers should set their operation
 * functions when class init if the plugin module uses different APIs:Because the vidsink module 
 * API is different from other modules:viddec, vidpproc, vidrender..., so abstract these type APIs.
 */

/* See description of ismd_dev_close() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_close_func_t)(ismd_dev_t dev);

/* See description of ismd_dev_flush() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_flush_func_t)(ismd_dev_t dev);

/* See description of ismd_dev_set_state() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_set_state_func_t)(ismd_dev_t dev, ismd_dev_state_t state);

/* See description of ismd_dev_set_clock() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_set_clock_func_t)(ismd_dev_t dev, ismd_clock_t clock);

/* See description of ismd_dev_set_stream_base_time() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_set_base_time_func_t)(ismd_dev_t dev, ismd_time_t base);

/* See description of ismd_dev_set_play_rate() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_set_play_rate_func_t)(ismd_dev_t dev, ismd_pts_t current_linear_time, int rate);

/* See description of ismd_dev_set_underrun_event() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_set_underrun_event_func_t)(ismd_dev_t dev, ismd_event_t underrun_event);

/* See description of ismd_dev_get_underrun_amount() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_get_underrun_amount_func_t)(ismd_dev_t dev, ismd_time_t *underrun_amount);

/* See description of ismd_dev_get_state() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_get_state_func_t)(ismd_dev_t dev, ismd_dev_state_t *state);

/* See description of ismd_dev_get_stream_base_time() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_get_base_time_func_t)(ismd_dev_t dev, ismd_time_t *base);

/* See description of ismd_dev_get_play_rate() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_get_play_rate_func_t)(ismd_dev_t dev, int *rate);

/* See description of ismd_dev_set_slave_clock() in ismd_core.h */
typedef ismd_result_t (* ismd_gst_dev_set_slave_clock_func_t)(ismd_dev_t dev, ismd_clock_t clock);

typedef struct ismd_gst_dev_ops {
   ismd_gst_dev_close_func_t         close;         /**< close the device.  cleanly stop and release resources. */
   ismd_gst_dev_flush_func_t         flush;         /**< syncrhonous discard of all in-flight data including data queued in I/O ports */
   ismd_gst_dev_set_state_func_t     set_state;     /**< change the state of the device (e.g. pause, play, stop, etc.) */
   ismd_gst_dev_set_clock_func_t     set_clock;     /**< (optional) set the clock to be used by the device. */
   ismd_gst_dev_set_base_time_func_t set_base_time; /**< (optional) set the base time of a device. should only be called in pause state. */
   ismd_gst_dev_set_play_rate_func_t set_play_rate; /**< (optional) set the play rate on a device. should only be called in pause state. */
   ismd_gst_dev_set_underrun_event_func_t set_underrun_event;   /**< (optional, for push-mode buffer level monitoring) set an event for the renderers to strobe on underrun. */
   ismd_gst_dev_get_underrun_amount_func_t get_underrun_amount; /**< (optional, for push-mode buffer level monitoring) get the "pts lateness" amount from the renderers. */
   ismd_gst_dev_get_state_func_t    get_state;     /**< (optional) get the state of the device (e.g. pause, play, stop, etc.) */
   ismd_gst_dev_get_base_time_func_t get_base_time; /**< (optional) get the base time of a device. */
   ismd_gst_dev_get_play_rate_func_t get_play_rate; /**< (optional) get the play rate of a device.*/
   ismd_gst_dev_set_slave_clock_func_t set_slave_clock;/**< (optional) set the slave clock to be driven by the device. */
} ismd_gst_dev_ops_t;

struct _ISmdGstElementClass
{
  GstElementClass parent_class;
  GstFlowReturn (*push_buffer) (ISmdGstElement * smd_element,
      GstPad * pad, GstBuffer * buf);
  GstBuffer *(*convert) (ISmdGstElement * smd_element, GstBuffer * buf,
      gboolean need_seq_hdr);
  void (*prerolled) (ISmdGstElement * smd_element);
  void (*drain) (ISmdGstElement * smd_element);
  void (*track_qos) (ISmdGstElement * smd_element, gint client_id, gint t);

  gboolean (*event) (ISmdGstElement * element, GstEvent * event);
  ismd_gst_dev_ops_t dev_ops;
  gboolean is_decoder;
  gboolean is_sink;
  gboolean is_audio_decoder;
  gboolean is_ts_muxer;
  gboolean is_vidio_enc;
};

struct _ISmdGstElement
{
  GstElement element;
  ismd_dev_t dev_handle;

  /* private variables */
  ISmdGstPad *sink_pad;
  GList *sink_pads;//use for sink pads list
  GList *src_pads;
  ismd_event_t src_pad_event;

  GstTask *event_loop;
  GStaticRecMutex *event_loop_mutex;
  GMutex *pad_list_mutex;
  gboolean initial_flush;
  GstFlowReturn last_ret;
  ismd_port_handle_t ismd_port;

  /* only used for internal testing */
  gboolean data_available;
  gboolean stop_writing_data;
  gboolean send_newsegment;
  gboolean need_new_seq_hdr;

  gboolean is_flushing;

  GstSegment segment;
  gboolean need_preroll;
  gboolean playing_async;
  gboolean commited;
  gboolean prerolled;
  GstClockTime stream_time_offset;
  gboolean use_buffering;

  ismd_viddec_stream_properties_t video_props;
  gint par_x, par_y;
  gint next_client_id;
  gint current_buffer;
  guint system_stride;  
  guint video_bitrate;  
};


typedef struct _ISmdGstElementSinkPad
{
  ISmdGstPad *sink_pad;
  GStaticRecMutex *adapter_lock;
  /* Adapter */
  GstAdapter * adapter;
  GstClockTime head_ts;
  GstClockTime next_ts;
  gboolean discont;
  guint bit_rate;
}ISmdGstElementSinkPad;


void ismd_gst_element_create_pads (ISmdGstElement * smd_element,
    GstStaticCaps * sink_scaps, GstStaticCaps * source_scaps, guint count);

/**
* ismd_gst_element_register_sinkpad:
* @ISmdGstElement: 
* @ISmdPad:
*/
gboolean ismd_gst_element_register_sinkpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad);

/**
* ismd_gst_element_register_srcpad:
* @ISmdGstElement: 
* @ISmdPad:
*/
gboolean ismd_gst_element_register_srcpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad);

/**
* ismd_gst_element_unregister_srcpad:
* @ISmdGstElement: 
* @ISmdPad:
*/
gboolean ismd_gst_element_unregister_srcpad (ISmdGstElement * smd_element,
    ISmdGstPad * pad);

/**
* ismd_setup_input_pad:
* @ISmdPad:
*/
void ismd_setup_input_pad (ISmdGstPad * pad);

/**
* ismd_setup_output_pad:
* @ISmdPad:
*/
void ismd_setup_output_pad (ISmdGstPad * pad);

/**
* ismd_gst_element_requires_clock:
* @ISmdGstElementClass: 
*/
gboolean ismd_gst_element_requires_clock (GstElementClass *
    element_class);

GType ismd_gst_element_get_type (void);

gboolean ismd_gst_element_unregister_sinkpad (ISmdGstElement * smd_element, ISmdGstPad * pad);

/* standard type-casting and type-checking boilerplate... */
#define ISMD_GST_TYPE_ELEMENT      (ismd_gst_element_get_type())
#define ISMD_GST_ELEMENT(obj)      (G_TYPE_CHECK_INSTANCE_CAST\
                                       ((obj), ISMD_GST_TYPE_ELEMENT, ISmdGstElement))
#define ISMD_GST_ELEMENT_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST\
                                            ((klass), ISMD_GST_TYPE_ELEMENT, ISmdGstElementClass))
#define ISMD_GST_IS_ELEMENT(obj)    (G_TYPE_CHECK_INSTANCE_TYPE((obj), ISMD_GST_TYPE_ELEMENT))
#define ISMD_GST_IS_ELEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
                                        ((klass), ISMD_GST_TYPE_ELEMENT))
#define ISMD_GST_ELEMENT_CAST(obj) ((ISmdGstElement *) (obj))                                 

/**
 * ISMD_ELEMENT_SINK_PAD:
 * @obj: ismd element instance
 *
 * Gives the pointer to the #GstPad object of the element.
 */
#define ISMD_ELEMENT_SINK_PAD(obj)          (GST_PAD (ISMD_GST_ELEMENT_CAST (obj)->sink_pad))

#endif /* __ISMD_GST_ELEMENT__ */
