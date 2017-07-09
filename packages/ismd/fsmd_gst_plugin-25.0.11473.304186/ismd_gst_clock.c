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

#include <string.h>
#include "ismd_core.h"
#include "ismd_bufmon.h"
#include "ismd_gst_clock.h"

GST_DEBUG_CATEGORY_STATIC (ismd_gst_clock_debug);
#define GST_CAT_DEFAULT ismd_gst_clock_debug

/* In PR10 is used the SW controled */
#define CLOCK_TYPE      ISMD_CLOCK_TYPE_SW_CONTROLLED
/* In PR9 is used fixed */
//#define CLOCK_TYPE      ISMD_CLOCK_TYPE_FIXED

/* in 90khz ticks  3 = 1ms */
#define ADDITIONAL_VALUE_FOR_UNDERRUN  20000

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_clock_debug, "ISMD_CLOCK",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstclock");
}

GST_BOILERPLATE_FULL (ISmdGstClock, ismd_gst_clock, GstSystemClock,
    GST_TYPE_SYSTEM_CLOCK, _do_init);

static GstClockTime
ismd_get_internal_time (GstClock * gstclock)
{
  GstClockTime gst_clock_time = 0;
  ISmdGstClock *clock = ISMD_GST_CLOCK (gstclock);
  ismd_result_t result;
  ismd_time_t time = 0;
  GST_DEBUG_OBJECT (clock, "ismd_get_internal_time()");
  if (clock->dev_handle == ISMD_DEV_HANDLE_INVALID) {
    GST_ERROR_OBJECT (clock, "ismd clock error, invalid dev_handle");
    return GST_CLOCK_TIME_NONE;
  }
  result = ismd_clock_get_time (clock->dev_handle, &time);

  gst_clock_time = SMD_TO_GST_TIME (time);
  GST_DEBUG_OBJECT (clock, "smd time %llu gst clock time: %" GST_TIME_FORMAT,
      time, GST_TIME_ARGS (gst_clock_time));

  if (clock->is_primary == FALSE) {
    /* The clock that GST selects has to be made primary at the ISMD level.
     * This function is only called for the selected clock, so this is a good
     * place to call ismd_clock_make_primary.
     * Making all clocks primary by default will result in a NO_RESOURCES error
     * from the ISMD, since there can only be one primary clock.
     */
    result = ismd_clock_make_primary (clock->dev_handle);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (clock, "ismd_clock_make_primary failed"
          " (code:%d)", result);
    } else {
      clock->is_primary = TRUE;
    }
  }
  return gst_clock_time;
}

static inline gboolean
is_device_monitored (ISmdGstClock * clock, ismd_dev_t device)
{
  gint i;
  gboolean ret = FALSE;

  GST_OBJECT_LOCK (clock);
  for (i = 0; i < clock->bufmon_n_devices && i < MAX_MONITORED_DEVICES ; i++) {
    if (clock->bufmon_devices[i] == device) {
      ret = TRUE;
      goto beach;
    }
  }
beach:
  GST_OBJECT_UNLOCK (clock);
  return ret;
}

static gboolean
ismd_gst_clock_enable_bufmon (ISmdGstClock * clock)
{
  ismd_result_t result = ISMD_SUCCESS;
  gboolean ret = FALSE;

  /* open buffer moniter */
  result = ismd_bufmon_open (&clock->bufmon_handle);
  if(result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_bufmon_open failed(%d)", result);
    goto beach;
  }

  /* set the clock to buffer monitor */
  result = ismd_dev_set_clock (clock->bufmon_handle, clock->dev_handle);
  if(result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_dev_set_clock failed(%d)", result);
    goto beach;
  }

  /* set additional amount */
  result = ismd_bufmon_set_underrun_correction_amount (clock->bufmon_handle,
      ADDITIONAL_VALUE_FOR_UNDERRUN);
  if(result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_bufmon_set_underrun_correction_amount"
        " failed(%d)", result);
    goto beach;
  }
  GST_DEBUG_OBJECT (clock, "bufmon enabled on SMD clock %d", clock->dev_handle);
  ret = TRUE;
beach:
  return TRUE;
}

void
ismd_gst_clock_bufmon_add_render (ISmdGstClock * clock, ismd_dev_t rend_handle)
{
  ismd_event_t underrun_event;
  ismd_result_t result = ISMD_SUCCESS;

  if (clock->bufmon_handle == ISMD_DEV_HANDLE_INVALID) {
    GST_WARNING_OBJECT (clock, "bufmon is not available");
    return;
  }

  if (is_device_monitored (clock, rend_handle)) {
    return;
  }

  result = ismd_bufmon_add_renderer (clock->bufmon_handle, rend_handle,
      &(underrun_event));
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_bufmon_add_renderer failed (%d)", result);
    goto beach;
  }

  result = ismd_dev_set_underrun_event (rend_handle, underrun_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_dev_set_underrun_event failed (%d)", result);
    goto beach;
  }

  GST_DEBUG_OBJECT (clock, "device %d added to bufmon", rend_handle);
beach:
  GST_OBJECT_LOCK (clock);
  clock->bufmon_devices[clock->bufmon_n_devices++] = rend_handle;
  GST_OBJECT_UNLOCK (clock);
}

void
ismd_gst_clock_bufmon_add_source (ISmdGstClock * clock,
    ismd_dev_t clock_sync_handle)
{
  ismd_result_t result = ISMD_SUCCESS;

  if (clock->bufmon_handle == ISMD_DEV_HANDLE_INVALID) {
    GST_WARNING_OBJECT (clock, "bufmon is not available");
    return;
  }

  if (is_device_monitored (clock, clock_sync_handle)) {
    return;
  }

  result = ismd_bufmon_set_clock_sync (clock->bufmon_handle, clock_sync_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_bufmon_set_clock_sync failed (%d)", result);
    goto beach;
  }

  /* set buffmon to playing */
  result = ismd_dev_set_state (clock->bufmon_handle, ISMD_DEV_STATE_PLAY);
  if (ISMD_SUCCESS != result) {
    GST_ERROR_OBJECT (clock, "BUFMON to playing failed(%d)", result);
    goto beach;
  }
  GST_DEBUG_OBJECT (clock, "device %d added to bufmon", clock_sync_handle);

beach:
  GST_OBJECT_LOCK (clock);
  clock->bufmon_devices[clock->bufmon_n_devices++] = clock_sync_handle;
  GST_OBJECT_UNLOCK (clock);
}

#ifndef NOT_REEL_PATCHED
void
ismd_gst_clock_bufmon_remove_render (ISmdGstClock * clock, ismd_dev_t rend_handle) {
  gint i;
  gboolean ret = FALSE;
  ismd_result_t result = ISMD_SUCCESS;

  GST_OBJECT_LOCK (clock);
  for (i = 0; i < MAX_MONITORED_DEVICES ; i++) {
    if(ret) {
      clock->bufmon_devices[i-1] = clock->bufmon_devices[i];
    } else if (clock->bufmon_devices[i] == rend_handle) {
      ret = TRUE;
      result = ismd_bufmon_remove_renderer (clock->bufmon_handle, rend_handle);
      if (result != ISMD_SUCCESS)
        GST_ERROR_OBJECT (clock, "ismd_bufmon_remove_renderer failed (%d)", result);
    }
  }
  if(ret) {
    clock->bufmon_devices[MAX_MONITORED_DEVICES-1] = ISMD_DEV_HANDLE_INVALID;
    clock->bufmon_n_devices--;
  }
  GST_OBJECT_UNLOCK (clock);
}

ISmdGstClock *ismd_gst_clock_reuse(ISmdGstClock * clock) {
  gint i;
  if(!clock) return NULL;

  if (clock->bufmon_handle != ISMD_DEV_HANDLE_INVALID) ismd_dev_close (clock->bufmon_handle);
  clock->bufmon_handle = ISMD_DEV_HANDLE_INVALID;

  for (i = 0; i < MAX_MONITORED_DEVICES; i++)
    clock->bufmon_devices[i] = ISMD_DEV_HANDLE_INVALID;
  clock->bufmon_n_devices = 0;

  ismd_gst_clock_enable_bufmon (clock);
  return gst_object_ref(clock);
}
#endif

static void
ismd_gst_clock_finalize (GObject * object)
{
  ISmdGstClock *clock = ISMD_GST_CLOCK (object);
  ismd_result_t result;

  GST_DEBUG_OBJECT (clock, "destroying clock");
  if (clock->dev_handle != ISMD_DEV_HANDLE_INVALID) {
    if (clock->is_primary == TRUE) {
      result = ismd_clock_reset_primary (clock->dev_handle);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (clock, "ismd_clock_reset_primary failed(%d)", result);
      }
    }

    result = ismd_clock_free (clock->dev_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (clock, "ismd_clock_free failed(%d)", result);
    }
  }
  if (clock->bufmon_handle != ISMD_DEV_HANDLE_INVALID) {
    ismd_dev_close (clock->bufmon_handle);
  }

  GST_CALL_PARENT (G_OBJECT_CLASS, finalize, (object));
}

static void
ismd_gst_clock_base_init (gpointer class)
{
}

static void
ismd_gst_clock_class_init (ISmdGstClockClass * class)
{
  GstClockClass *gstclockclass = GST_CLOCK_CLASS (class);
  GObjectClass *oclass = G_OBJECT_CLASS (class);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_clock_finalize);
  gstclockclass->get_internal_time = ismd_get_internal_time;
}

static void
ismd_gst_clock_init (ISmdGstClock * clock, ISmdGstClockClass * class)
{
  ismd_result_t result;
  gint i;
  clock->dev_handle = ISMD_DEV_HANDLE_INVALID;
  clock->is_primary = FALSE;

  result = ismd_clock_alloc (CLOCK_TYPE, &clock->dev_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (clock, "ismd_clock_alloc failed (%d)", result);
    clock->dev_handle = ISMD_DEV_HANDLE_INVALID;
  } else {
    if ((result = ismd_clock_set_time (clock->dev_handle, 0)) != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (clock, "ismd_clock_set_time failed (%d)", result);
    }
  }
  clock->bufmon_handle = ISMD_DEV_HANDLE_INVALID;
  for (i = 0; i < MAX_MONITORED_DEVICES; i++)
    clock->bufmon_devices[i] = ISMD_DEV_HANDLE_INVALID;
  clock->bufmon_n_devices = 0;

  ismd_gst_clock_enable_bufmon (clock);
}
