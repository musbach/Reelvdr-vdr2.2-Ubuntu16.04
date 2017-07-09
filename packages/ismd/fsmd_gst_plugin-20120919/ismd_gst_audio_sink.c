/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

    Copyright(c) 2008-2012. Intel Corporation. All rights reserved.
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

    Copyright (c) 2008-2012. Intel Corporation. All rights reserved.
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

#define NEW_MASTER_CLOCK_API 1

#include <gst/gstmarshal.h>
#ifndef NOT_REEL_PATCHED
#include <gst/audio/multichannel.h>
#endif
#include <ismd_core.h>
#include <ismd_audio.h>
#include <ismd_audio_defs.h>
#include <ismd_core_protected.h>
#include "ismd_gst_element.h"
#include "ismd_gst_audio_sink.h"
#include "ismd_gst_enum.h"

#include <math.h>               /* for log10() */

/* To configure internal AUDIO PLL */
#include <clock_control.h>
//#include "system_utils_soc_info.h"
#include "pal_soc_info.h"

/* The default audio driver output timing slack is 1.5 milliseconds
 * If the audio PTS is not with in this slack then the driver
 * will make correction by dropping packets or adding silence.
 * During soft demux such as an AVI file with out time stamps
 * the soft demux algorithm for determining PTS is not accurate
 * causing audible glitches unless the timing is loosened.
 */
#define ALLOWED_MS_TIMING_DRIFT_FOR_SOFT_DEMUX_AHEAD    1
#define ALLOWED_MS_TIMING_DRIFT_FOR_SOFT_DEMUX_BEHIND 100

#define AUDIO_SADIV_I2S_12KHZ    48
#define AUDIO_SADIV_I2S_24KHZ    24
#define AUDIO_SADIV_I2S_32KHZ    18
#define AUDIO_SADIV_I2S_44_1_KHZ 12
#define AUDIO_SADIV_I2S_48KHZ    12
#define AUDIO_SADIV_I2S_88_2_KHZ  6
#define AUDIO_SADIV_I2S_96KHZ     6
#define AUDIO_SADIV_I2S_176_4_KHZ 3
#define AUDIO_SADIV_I2S_192KHZ    3

#define AUDIO_SADIV_SPDIF_12KHZ    24
#define AUDIO_SADIV_SPDIF_24KHZ    12
#define AUDIO_SADIV_SPDIF_32KHZ     9
#define AUDIO_SADIV_SPDIF_44_1_KHZ  6
#define AUDIO_SADIV_SPDIF_48KHZ     6
#define AUDIO_SADIV_SPDIF_88_2_KHZ  3
#define AUDIO_SADIV_SPDIF_96KHZ     3
#define AUDIO_SADIV_SPDIF_192KHZ    0


/* Structure for storing AAC Header */

/******************************************************
 * AAC Header related Arrays. This will be static array
 * which will be added when we get a buffer.
 ******************************************************/

/* AAC Audio Sample Frequency Index Table as per 13818-7 */
static aac_audio_index audio_frequency[AAC_FREQUENCY_INDEX] = {
  {96000, 0x00}, {88200, 0x01}, {64000, 0x02}, {48000, 0x03}, {44100, 0x04},
  {32000, 0x05}, {24000, 0x06}, {22050, 0x07}, {16000, 0x08}, {12000, 0x09},
  {11025, 0x0a}, {8000, 0x0b}
};

#define freq_index_max_value (sizeof(audio_frequency)/(sizeof(*audio_frequency)))

/* AAC Audio Channels Index Table as per 13818-7 */
static aac_audio_index audio_channels[AAC_CHANNEL_INDEX] = {
  {1, 0x01}, {2, 0x02}, {3, 0x03}, {4, 0x04}, {5, 0x05}, {6, 0x06}, {8, 0x7}
};

enum
{
  UNKNOWN,
  PROP_AUDIO_GLOBAL_PROC,
  PROP_AUDIO_OUT_HDMI,
  PROP_AUDIO_OUT_SPDIF,
  PROP_AUDIO_OUT_I2S0,
  PROP_AUDIO_OUT_I2S1,
  PROP_AUDIO_OUT_DELAY,
  PROP_AUDIO_SYNC,
  PROP_AUDIO_LATENCY,
  PROP_AUDIO_INPUT_GAIN,
  PROP_AUDIO_VOLUME,
  PROP_AUDIO_MUTE
};

enum
{
  OUT_AUTO = -1,
  OUT_OFF = 0,
  OUT_PCM = ISMD_AUDIO_OUTPUT_PCM,
  OUT_PASSTHROUGH = ISMD_AUDIO_OUTPUT_PASSTHROUGH,
  OUT_AC3 = ISMD_AUDIO_OUTPUT_ENCODED_DOLBY_DIGITAL,
  OUT_DTS = ISMD_AUDIO_OUTPUT_ENCODED_DTS
};



#define DEFAULT_ISMD_AUDIO_SINK_GLOBAL_PROC TRUE
#define DEFAULT_ISMD_AUDIO_SINK_SYNC        TRUE
#define DEFAULT_ISMD_AUDIO_SINK_LATENCY     ISMD_AUDIO_LATENCY_MODE_DEFAULT
#define DEFAULT_ISMD_AUDIO_SINK_HDMI        OUT_PCM
#define DEFAULT_ISMD_AUDIO_SINK_SPDIF       OUT_PCM
#define DEFAULT_ISMD_AUDIO_SINK_I2S0        OUT_PCM
#define DEFAULT_ISMD_AUDIO_SINK_I2S1        OUT_PCM
#define DEFAULT_ISMD_AUDIO_SINK_DELAY       0   /* in nanoseconds */
#define DEFAULT_ISMD_AUDIO_SINK_INPUT_GAIN  0.0
#define DEFAULT_ISMD_AUDIO_SINK_VOLUME      1.0
#define DEFAULT_ISMD_AUDIO_SINK_MUTE        FALSE

#define MIN_INPUT_GAIN                      ((gfloat) ISMD_AUDIO_GAIN_MUTE / 10)
#define MAX_INPUT_GAIN                      ((gfloat) ISMD_AUDIO_GAIN_MAX / 10)
#define VOLUME_MAX_DOUBLE                   8.0

#define PCM_CAPS \
  "audio/x-raw-int, " \
    "endianness = (int) { LITTLE_ENDIAN }, " \
    "signed = (boolean) { true }, " \
    "width = (int) { 16, 24, 32 }, " \
    "depth = (int) { 16, 24, 32 }, " \
    "rate = (int) { 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 96000, 192000 }, " \
    "channels = (int) [ 1, 8 ]"

#define XPRIV_LPCM_CAPS     "audio/x-private1-lpcm"
#define MPEG12_CAPS         "audio/mpeg, mpegversion = (int) { 1 }, parsed = true"
#define XMPEG12_CAPS        "audio/x-mpeg, mpegversion = (int) { 1 }, parsed = true"
#define MPEG4_CAPS          "audio/mpeg, mpegversion = (int) { 2, 4 }, framed = true"
#define XMPEG4_CAPS         "audio/x-mpeg, mpegversion = (int) { 2, 4 }, framed = true"
#define XAAC_CAPS           "audio/x-aac"
#define XAC3_CAPS           "audio/x-ac3"
#define XPRIV_AC3_CAPS      "audio/x-private1-ac3"
#define XDD_CAPS            "audio/x-dd"
#define XEAC3_CAPS          "audio/x-eac3"
#define XDDPLUS_CAPS        "audio/x-ddplus"
#define XDTS_CAPS           "audio/x-dts"
#define XPRIV_DTS_CAPS      "audio/x-private1-dts"
#define XWMA_CAPS           "audio/x-wma, wmaversion = (int) { 2 }, "\
  "channels = (int) { 1, 2 }," \
  "rate = (int) { 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 96000, 192000 }"
#define GST_TYPE_ISMD_AUDIO_SINK_OUT_MODE_COMPLEX \
  (ismd_gst_audio_sink_out_mode_complex_get_type())
static GType
ismd_gst_audio_sink_out_mode_complex_get_type (void)
{
  static GType ismd_gst_audio_sink_out_mode_complex_type = 0;
  static const GEnumValue out_mode_types[] = {
    {OUT_AUTO, "Autoselect PCM or Passthrough", "auto"},
    {OUT_OFF, "Off", "off"},
    {OUT_PCM, "PCM", "pcm"},
    {OUT_PASSTHROUGH, "Passthrough", "pt"},
    {OUT_AC3, "Dolby Digital", "ac3"},
    {OUT_DTS, "DTS", "dts"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_audio_sink_out_mode_complex_type) {
    ismd_gst_audio_sink_out_mode_complex_type =
        g_enum_register_static ("GstIsmdAudioSinkOutputModeComplex",
        out_mode_types);
  }
  return ismd_gst_audio_sink_out_mode_complex_type;
}

#define GST_TYPE_ISMD_AUDIO_SINK_OUT_MODE_SIMPLE \
  (ismd_gst_audio_sink_out_mode_simple_get_type())
static GType
ismd_gst_audio_sink_out_mode_simple_get_type (void)
{
  static GType ismd_gst_audio_sink_out_mode_simple_type = 0;
  static const GEnumValue out_mode_types[] = {
    {OUT_OFF, "Off", "off"},
    {OUT_PCM, "PCM", "pcm"},
    {0, NULL, NULL}
  };

  if (!ismd_gst_audio_sink_out_mode_simple_type) {
    ismd_gst_audio_sink_out_mode_simple_type =
        g_enum_register_static ("GstIsmdAudioSinkOutputModeSimple",
        out_mode_types);
  }
  return ismd_gst_audio_sink_out_mode_simple_type;
}

/* Functions that get params from GStreamer elements
 * to pass to functions in audio renderer */
static inline gboolean ismd_open (GstElement * element);
static inline gboolean ismd_stop (GstElement * element);
static inline gboolean ismd_close (GstElement * element);

GST_DEBUG_CATEGORY_STATIC (ismd_gst_audio_sink_debug);
#define GST_CAT_DEFAULT ismd_gst_audio_sink_debug

static void
_do_init (GType ismd_gst_debug_type)
{
  GST_DEBUG_CATEGORY_INIT (ismd_gst_audio_sink_debug, "ISMD_AUDIO_SINK",
      (GST_DEBUG_BOLD | GST_DEBUG_FG_GREEN), "ismdgstaudiosink element");
}

/* Call Boilerplate to declare the base_init, class_init and init functions
 * and to define the get_type function */
GST_BOILERPLATE_FULL (ISmdGstAudioSink, ismd_gst_audio_sink, ISmdGstElement,
    ISMD_GST_TYPE_ELEMENT, _do_init);

/* This function creates the AAC ADTS Header information to be added for all
 * AAC Audio Buffers */
static inline gboolean
create_aac_header (ISmdGstAudioSink * sink, GstStructure * structure)
{
  gboolean ret = FALSE;
  gint rate = 0, channels = 0, freq_index = 0x0F;
  gint channel_index = 2, loop, profile = 1;
  guint8 *aac_header_data = &sink->aac_header_data[0];
  const GValue *codec_data;

  GST_DEBUG_OBJECT (sink, "create_aac_header");

  if (!gst_structure_get_int (structure, "rate", &rate)) {
    codec_data = gst_structure_get_value (structure, "codec_data");
    if (codec_data) {
      GstBuffer *buffer;
      guint8 *data;
      guint16 AudioSpecificConfig;

      buffer = gst_value_get_buffer (codec_data);
      data = GST_BUFFER_DATA (buffer);
      AudioSpecificConfig = (data[0] << 8) | data[1];
      freq_index = (AudioSpecificConfig & 0x0780) >> 7;
      if ( freq_index >= freq_index_max_value ) {
        GST_WARNING_OBJECT (sink, "freq_index out of range: %d, max %d",
            freq_index, freq_index_max_value );
        goto beach;
      } else {
        rate = audio_frequency[freq_index].data;
        GST_DEBUG_OBJECT (sink,"rate %d", rate);
      }
    } else {
      GST_WARNING_OBJECT (sink, "Failed to get rate of the audio packets");
      goto beach;
    }
  }

  if (!gst_structure_get_int (structure, "channels", &channels)) {
    GST_WARNING_OBJECT (sink, "Failed to get number of the audio channels");
    goto beach;
  }

  /* AAC - ADTS header */
  aac_header_data[0] = 0xFF;    /* Sync Word */
  aac_header_data[1] = 0xF1;    /* Sync Word=FF, MPEG ID=0, Layer=0 & Protection_Absent=1 */
  aac_header_data[2] = 0x00;    /* Profile, Sample Frequency Index, Channel Configuration */
  aac_header_data[3] = 0x00;    /* Channel Configuration & Frame Length */
  aac_header_data[4] = 0x00;    /* Frame Length */
  aac_header_data[5] = 0x1F;    /* Frame Length & ADTS Buffer Fullness */
  aac_header_data[6] = 0xFC;    /* ADTS Buffer Fullness & Number of Raw data blocks */

  /* Sampling Frequency index */
  for (loop = 0; loop < AAC_FREQUENCY_INDEX; loop++) {
    if (rate == audio_frequency[loop].data) {
      freq_index = audio_frequency[loop].index;
      break;
    }
  }

  /* Audio Channels index */
  for (loop = 0; loop < AAC_CHANNEL_INDEX; loop++) {
    if (channels == audio_channels[loop].data) {
      channel_index = audio_channels[loop].index;
      break;
    }
  }

  /* Update the profile, frequency and audio channels index */
  aac_header_data[2] |= ((profile & 0x03) << 6);
  aac_header_data[2] |= (freq_index << 2);
  aac_header_data[2] |= (channel_index >> 2);
  aac_header_data[3] |= ((channel_index & 0x03) << 6);

  ret = TRUE;
beach:
  return ret;
}

/**
 * Method: set_sadiv_value
 *
 * Description:
 *     This function assigns the appropriate audio HW output interface bit
 *     clock divider value to the output context. This value is used by the
 *     SMD audio API function ismd_audio_output_set_external_bit_clock_div.
 */
static inline gint
set_sadiv_value (gint sample_rate, gint out_hw_id)
{
  gint bit_clock_div_val = AUDIO_SADIV_I2S_48KHZ;

  switch (sample_rate) {
    case 12000:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_12KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_12KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 24000:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_24KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_24KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 32000:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_32KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_32KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 44100:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_44_1_KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_44_1_KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 88200:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_88_2_KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_88_2_KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 48000:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_48KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_48KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 96000:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_96KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_96KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 176400:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_176_4_KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          GST_ERROR ("SPDIF cannot support 176400Hz!!");
          bit_clock_div_val = AUDIO_SADIV_SPDIF_88_2_KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    case 192000:
      switch (out_hw_id) {
        case GEN3_HW_OUTPUT_I2S0:
        case GEN3_HW_OUTPUT_I2S1:
          bit_clock_div_val = AUDIO_SADIV_I2S_192KHZ;
          break;
        case GEN3_HW_OUTPUT_SPDIF:
          bit_clock_div_val = AUDIO_SADIV_SPDIF_192KHZ;
          break;
        case GEN3_HW_OUTPUT_HDMI:
        default:
          break;
      }
      break;
    default:
      GST_ERROR ("ERROR: Invalid output sample rate!");
      break;
  }
  return bit_clock_div_val;
}

#if NEW_MASTER_CLOCK_API
static inline gboolean
set_audio_pll_freq (ISmdGstAudioSink * sink, AUDIO_PLL_FREQ_FAMILY freq_fam)
{
  gboolean ret = TRUE;
  ismd_result_t result;
  unsigned int frequency = 36864000;
  ismd_audio_clk_src_t clk_src = ISMD_AUDIO_CLK_SRC_EXTERNAL;
  soc_user_info_t info;

  if ((result = system_utils_get_soc_info (&info)) == 0) {
    if (info.name_enum == SOC_NAME_CE3100 || info.name_enum == SOC_NAME_CE4200) {
      clk_src = ISMD_AUDIO_CLK_SRC_INTERNAL;
      GST_DEBUG_OBJECT (sink, "Detected CE3100 soc. Using internal source.");
    }else if (info.name_enum == SOC_NAME_CE4100){
        clk_src = ISMD_AUDIO_CLK_SRC_EXTERNAL;
    }else if (info.name_enum == SOC_NAME_CE5300){
        clk_src = ISMD_AUDIO_CLK_SRC_INTERNAL;
        GST_DEBUG_OBJECT (sink, "Detected CE5300 soc. Using internal source.");
    }else{
        clk_src = ISMD_AUDIO_CLK_SRC_INTERNAL;
        GST_DEBUG_OBJECT (sink,"system_utils_get_soc_info returned unrecognized chip info! Defaulting to external master audio clock source\n");
    }
  }

  switch (freq_fam) {
    case AUDIO_PLL_FREQ_FAMILY_44100:
      frequency = 33868800;
      break;
    case AUDIO_PLL_FREQ_FAMILY_48000:
      frequency = 36864000;
      break;
    case AUDIO_PLL_FREQ_FAMILY_INVALID:
    default:
      GST_ERROR_OBJECT (sink, "Invalid frequency family");
      ret = FALSE;
      goto beach;
  }

  result = ismd_audio_configure_master_clock (sink->processor, frequency,
      clk_src);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_configure_master_clock failed(%d)",
        result);
    ret = FALSE;
  }

beach:
  return ret;
}
#else
static inline ismd_result_t
set_audio_pll_freq_ce3100 (ISmdGstAudioSink * sink,
    AUDIO_PLL_FREQ_FAMILY freq_fam)
{
  ismd_result_t result = ISMD_ERROR_OPERATION_FAILED;
  clock_control_ret_t clock_result = CLOCK_ERROR_INVALID_RESOURCE;
  unsigned int freq_select_bit = 0;

  switch (freq_fam) {
    case AUDIO_PLL_FREQ_FAMILY_44100:
      freq_select_bit = 1;      /* 33.868 MHz */
      break;
    case AUDIO_PLL_FREQ_FAMILY_48000:
      freq_select_bit = 0;      /* Default is 36.864 MHz */
      break;
    case AUDIO_PLL_FREQ_FAMILY_INVALID:
    default:
      result = ISMD_ERROR_INVALID_PARAMETER;
      GST_ERROR_OBJECT (sink, "Invalid frequency family");
      goto beach;
  }

  /* Gate audio_clk_out by clearing AU_REF_CLK_EN bit */
  if ((clock_result =
          clock_control_write (CLOCK_AU_REF_CLK_EN, 0,
              CLOCK_TRUE)) != CLOCK_RET_OK) {
    GST_ERROR_OBJECT (sink,
        "clock_control_write failed(%d) on clearing CLOCK_AU_REF_CLK_EN",
        clock_result);
  }
  /* Switch APLL_FREQ_SEL bit */
  else if ((clock_result =
          clock_control_write (CLOCK_APLL_FREQ_SEL, freq_select_bit,
              CLOCK_TRUE)) != CLOCK_RET_OK) {
    GST_ERROR_OBJECT (sink,
        "clock_control_write failed(%d) on setting CLOCK_APLL_FREQ_SEL",
        clock_result);
  }
  /* Put Audio PLL divider into reset by writing 1 to AUDIO_PLL_DIV_RESET bit */
  else if ((clock_result =
          clock_control_write (CLOCK_AUDIO_PLL_DIV_RST, 1,
              CLOCK_TRUE)) != CLOCK_RET_OK) {
    GST_ERROR_OBJECT (sink,
        "clock_control_write failed(%d) on setting CLOCK_AUDIO_PLL_DIV_RST",
        clock_result);
  }
  /* Release Audio PLL from reset by writing 0 to AUDIO_PLL_RESET bit */
  else if ((clock_result =
          clock_control_write (CLOCK_AUDIO_PLL_RESET, 0,
              CLOCK_TRUE)) != CLOCK_RET_OK) {
    GST_ERROR_OBJECT (sink,
        "clock_control_write failed(5d) on clearing CLOCK_AUDIO_PLL_RESET",
        clock_result);
  }

  else {
    /* Wait one millisecond for APLL to relock.  APLL output will be running at
     * the new frequency */
    os_sleep (1);
  }

  if (clock_result == CLOCK_RET_OK) {

    /* Release Audio PLL divider from reset by writing 0 to
     * AUDIO_PLL_DIV_RESET bit */
    if ((clock_result =
            clock_control_write (CLOCK_AUDIO_PLL_DIV_RST, 0,
                CLOCK_TRUE)) != CLOCK_RET_OK) {
      GST_ERROR_OBJECT (sink,
          "clock_control_write failed(%d) on clearing  CLOCK_AUDIO_PLL_DIV_RST",
          clock_result);
    }
    /* Ungate audio_clk_out by setting AU_REF_CLK_EN bit */
    else if ((clock_result =
            clock_control_write (CLOCK_AU_REF_CLK_EN, 1,
                CLOCK_TRUE)) != CLOCK_RET_OK) {
      GST_ERROR_OBJECT (sink,
          "clock_control_write failed(%d) on clearing CLOCK_AU_REF_CLK_EN",
          clock_result);
    } else {
      result = ISMD_SUCCESS;
    }
  }

beach:
  return result;
}

static inline ismd_result_t
set_audio_pll_freq_ce4100 (ISmdGstAudioSink * sink,
    AUDIO_PLL_FREQ_FAMILY freq_fam)
{
  ismd_result_t result = ISMD_ERROR_OPERATION_FAILED;
  clock_control_ret_t clock_result = CLOCK_ERROR_INVALID_RESOURCE;
  unsigned int freq_select_bit = 0;

  switch (freq_fam) {
    /* 22.5792 MHz - 0 , 24.576 MHz - 1 */
    case AUDIO_PLL_FREQ_FAMILY_44100:
      freq_select_bit = 2;      /* 33.868 MHz - 2 */
      break;
    case AUDIO_PLL_FREQ_FAMILY_48000:
      freq_select_bit = 3;      /* Default is 36.864 MHz - 3 */
      break;
    case AUDIO_PLL_FREQ_FAMILY_INVALID:
    default:
      result = ISMD_ERROR_INVALID_PARAMETER;
      GST_ERROR_OBJECT (sink, "Invalid frequency family");
      break;
  }

  if ((clock_result =
          clock_control_write (CLOCK_EXT_AUD_CLKX, freq_select_bit,
              CLOCK_TRUE)) != CLOCK_RET_OK) {
    GST_ERROR_OBJECT (sink,
        "clock_control_write failed(%d) on setting CLOCK_APLL_FREQ_SEL",
        clock_result);
  } else {
    result = ISMD_SUCCESS;
  }

#if 0
  /* For ce4100 freq can be changed on the fly, no need to gate, set, reset and
   * enable the pll
   * CLOCK_EXT_OE_AUD_CLK0 ,1,2,3 by default enabled
   * clock 0 goes to audio pipe line
   * clock 1 goes to I2S1
   * clock 2 goes to I2S0
   * clock 3 goes to I2SC
   * Gate audio_clk_out by clearing CLOCK_EXT_OE_AUD_CLK0 bit */
  if((clock_result = clock_control_write(CLOCK_EXT_OE_AUD_CLK0, 0, CLOCK_TRUE)) != CLOCK_RET_OK) {
    GST_ERROR_OBJECT (sink, "clock_control_write failed(%d) on clearing "
        "CLOCK_EXT_OE_AUD_CLK0!", clock_result);
  }
#endif
  return result;
}

static inline gboolean
set_audio_pll_freq (ISmdGstAudioSink * sink, AUDIO_PLL_FREQ_FAMILY freq_fam)
{
  soc_user_info_t info;
  ismd_result_t result = ISMD_ERROR_OPERATION_FAILED;

  GST_DEBUG_OBJECT (sink, "Try to enable pll frequency family %d", freq_fam);
  if ((result = system_utils_get_soc_info (&info)) == 0) {
    if (info.name_enum == SOC_NAME_CE3100) {
      result = set_audio_pll_freq_ce3100 (sink, freq_fam);
    } else if (info.name_enum == SOC_NAME_CE4100) {
      result = set_audio_pll_freq_ce4100 (sink, freq_fam);
    } else {
      GST_ERROR_OBJECT (sink,
          "system_utils_get_soc_info returned unrecognized chip info");
    }
  } else {
    GST_DEBUG_OBJECT (sink,
        "Could not read(%d) chip information for audio PLL adjustment", result);
  }

  return (result == ISMD_SUCCESS ? TRUE : FALSE);
}
#endif

static inline AUDIO_PLL_FREQ_FAMILY
get_audio_pll_family (guint samplerate)
{
  AUDIO_PLL_FREQ_FAMILY result = AUDIO_PLL_FREQ_FAMILY_INVALID;

  switch(samplerate)
  {
    case 8000:
    case 12000:
    case 16000:
    case 24000:
    case 32000:
    case 48000:
    case 96000:
    case 192000:
      result = AUDIO_PLL_FREQ_FAMILY_48000;
      break;
    case 11025:
    case 22050:
    case 44100:
    case 88200:
    case 176400:
      result = AUDIO_PLL_FREQ_FAMILY_44100;
      break;
    default:
      break;
  }
  return result;
}

static inline ismd_result_t
config_input_gain (ISmdGstAudioSink * sink, gfloat gain)
{
  ismd_result_t result;
  ismd_audio_channel_mix_config_t ch_mix_config;
  guint in_ch, out_ch;
  gint smd_gain = gain * 10.0;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);

  for (in_ch = 0; in_ch < AUDIO_MAX_INPUT_CHANNELS; in_ch++) {
    ch_mix_config.input_channels_map[in_ch].input_channel_id = in_ch;
    for (out_ch = 0; out_ch < AUDIO_MAX_OUTPUT_CHANNELS; out_ch++) {
      ch_mix_config.input_channels_map[in_ch].output_channels_gain[out_ch] =
          ISMD_AUDIO_GAIN_MUTE;
    }
  }

  for (in_ch = 0; in_ch < AUDIO_MAX_INPUT_CHANNELS; in_ch++) {
    ch_mix_config.input_channels_map[in_ch].output_channels_gain[in_ch] =
        smd_gain;
  }

  result = ismd_audio_input_set_channel_mix (sink->processor,
      smd_element->dev_handle, ch_mix_config);

  GST_INFO_OBJECT (sink, "setting input gain: %f dBs -> %d", gain, smd_gain);

  return result;
}

static inline ismd_result_t
config_master_volume (ISmdGstAudioSink * sink, gfloat volume)
{
  ismd_result_t result;
  gint smd_volume;

  if (volume <= 0.0)
    smd_volume = ISMD_AUDIO_GAIN_MUTE;
  else
    smd_volume = (log10 (volume) * 200.0);

  if (smd_volume < ISMD_AUDIO_GAIN_MUTE)
    smd_volume = ISMD_AUDIO_GAIN_MUTE;

  if (smd_volume > ISMD_AUDIO_GAIN_MAX)
    smd_volume = ISMD_AUDIO_GAIN_MAX;

  GST_INFO_OBJECT (sink, "setting volume: %f %% -> %d", volume, smd_volume);

  result = ismd_audio_set_master_volume (sink->processor, smd_volume);

  return result;
}

static inline void
update_gain_volume_and_mute (ISmdGstAudioSink * sink)
{
  ismd_result_t result;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);

  if (sink->processor == -1)
    return;

  if (smd_element->dev_handle == -1)
    return;

  GST_OBJECT_LOCK (sink);
  if (sink->current_input_gain != sink->input_gain) {
    result = config_input_gain (sink, sink->input_gain);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (sink, "setting input gain failed(%d)", result);
    } else {
      sink->current_input_gain = sink->input_gain;
    }
  }

  if (sink->current_volume != sink->volume) {
    result = config_master_volume (sink, sink->volume);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (sink, "setting volume failed(%d)", result);
    } else {
      sink->current_volume = sink->volume;
    }
  }

  if (sink->current_mute != sink->mute) {
    GST_INFO_OBJECT (sink, "setting mute: %s", (sink->mute ? "TRUE" : "FALSE"));
    result = ismd_audio_mute (sink->processor, sink->mute);
    if (result != ISMD_SUCCESS) {
      GST_WARNING_OBJECT (sink, "ismd_audio_mute failed(%d)", result);
    } else {
      sink->current_mute = sink->mute;
    }
  }
  GST_OBJECT_UNLOCK (sink);
}

static void
ismd_gst_audio_sink_loop (ISmdGstAudioSink * sink)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  ismd_event_list_t event_list = { sink->bos_event, sink->eos_event, sink->clientid_event };
  ismd_event_t event;
  ismd_result_t result;
  gint client_id;

  if (!sink->monitor_stop) {
    GST_LOG_OBJECT (sink, "wait for event");
    result = ismd_event_wait_multiple (event_list, 2, ISMD_TIMEOUT_NONE,
        &event);
    if (result == ISMD_SUCCESS) {
      if (event == sink->clientid_event) {
        result = ismd_audio_input_get_client_id (sink->processor,
            smd_element->dev_handle, &client_id);
        if (result == ISMD_SUCCESS) {
          GST_LOG_OBJECT (sink, "got client_id %d", client_id);
        }
      }
      else if (event == sink->bos_event) {
        if (!sink->bos_posted) {
          GST_DEBUG_OBJECT (sink, "BOS Received");
          sink->bos_posted = TRUE;
        }
      }
      else if (event == sink->eos_event) {
        if (!sink->eos_posted) {
          GST_DEBUG_OBJECT (sink, "Posting EOS message");
          if (!gst_element_post_message (GST_ELEMENT (sink),
                  gst_message_new_eos (GST_OBJECT (sink)))) {
            GST_ERROR_OBJECT (sink, "Couldn't post sink EOS message");
          }
          sink->eos_posted = TRUE;
        }
      }
      result = ismd_event_reset (event);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_event_reset failed(%d)", result);
      }
      result = ismd_event_acknowledge (event);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_event_acknowledge failed(%d)", result);
      }
    }
    else {
      GST_ERROR_OBJECT (sink, "ismd_event_wait_multiple failed(%d)", result);
    }
  }
}

static inline gboolean
ismd_unconfigure_input (ISmdGstAudioSink * sink)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  ismd_result_t result;

  if (smd_element->dev_handle != ISMD_DEV_HANDLE_INVALID) {
    if (sink->monitor_loop != NULL) {
      sink->monitor_stop = TRUE;
      /* Do not post the EOS message when we just close the element */
      sink->eos_posted = TRUE;
      gst_task_stop (sink->monitor_loop);
      result = ismd_event_strobe (sink->eos_event);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_event_strobe failed(%d)", result);
      }
      gst_task_join (sink->monitor_loop);
      gst_object_unref (sink->monitor_loop);
      sink->monitor_loop = NULL;
      sink->eos_posted = FALSE;
      GST_DEBUG_OBJECT (sink, "monitoring task stopped");
    }

    result = ismd_audio_remove_input (sink->processor, smd_element->dev_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_remove_input failed (%d)", result);
    }
    smd_element->dev_handle = ISMD_DEV_HANDLE_INVALID;
  }

  return TRUE;
}

#ifndef NOT_REEL_PATCHED
static inline gboolean
ismd_configure_input (ISmdGstAudioSink * sink, GstAudioChannelPosition *pos)
#else
static inline gboolean
ismd_configure_input (ISmdGstAudioSink * sink)
#endif
{
  gboolean ret = FALSE;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  ismd_result_t result;
  gint pcm_channels;

  GST_DEBUG_OBJECT (sink,
      "setting input data format processor=%d devhandle=%d codec=%d",
      sink->processor, smd_element->dev_handle, sink->codec);

  result = ismd_audio_input_set_data_format (sink->processor,
      smd_element->dev_handle, sink->codec);
  if (result != ISMD_SUCCESS) {
    GST_ERROR ("ismd_audio_input_set_data_format failed(%d)", result);
    goto beach;
  }

  switch (sink->codec) {
    case ISMD_AUDIO_MEDIA_FMT_WM9:
      GST_DEBUG_OBJECT (sink, "setting WMA input data format");
      result = ismd_audio_input_set_wma_format (sink->processor,
          smd_element->dev_handle, sink->wma_fmt);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_audio_input_set_wma_format failed(%d)",
            result);
        goto beach;
      }
      break;
    case ISMD_AUDIO_MEDIA_FMT_PCM:

      GST_DEBUG_OBJECT (sink, "setting PCM input data format");
      /* Configure channels */
      switch (sink->channels) {
        case 1:
          pcm_channels = AUDIO_CHAN_CONFIG_1_CH;
          break;
        case 2:
          pcm_channels = AUDIO_CHAN_CONFIG_2_CH;
          break;
        case 6:
          pcm_channels = AUDIO_CHAN_CONFIG_6_CH;
          break;
        case 8:
          pcm_channels = AUDIO_CHAN_CONFIG_8_CH;
          break;
        default:
          pcm_channels = AUDIO_CHAN_CONFIG_2_CH;
          break;
      }
#ifndef NOT_REEL_PATCHED
      if(pos && (pos[0] != GST_AUDIO_CHANNEL_POSITION_NONE)) {
        pcm_channels = AUDIO_CHAN_CONFIG_INVALID;
        int i;
        for(i=0; (i < sink->channels) && (i <= 8); i++) {
          int pcm_pos = (i<<2);
          pcm_channels = pcm_channels & ~(0xF << pcm_pos);
          switch(pos[i]) {
            case GST_AUDIO_CHANNEL_POSITION_FRONT_MONO           : pcm_channels |= (ISMD_AUDIO_CHANNEL_CENTER         << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_FRONT_LEFT           : pcm_channels |= (ISMD_AUDIO_CHANNEL_LEFT           << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_FRONT_RIGHT          : pcm_channels |= (ISMD_AUDIO_CHANNEL_RIGHT          << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_REAR_CENTER          : pcm_channels |= (ISMD_AUDIO_CHANNEL_INVALID        << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_REAR_LEFT            : pcm_channels |= (ISMD_AUDIO_CHANNEL_LEFT_SUR       << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_REAR_RIGHT           : pcm_channels |= (ISMD_AUDIO_CHANNEL_RIGHT_SUR      << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_LFE                  : pcm_channels |= (ISMD_AUDIO_CHANNEL_LFE            << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_FRONT_CENTER         : pcm_channels |= (ISMD_AUDIO_CHANNEL_CENTER         << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_FRONT_LEFT_OF_CENTER : pcm_channels |= (ISMD_AUDIO_CHANNEL_LEFT           << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_FRONT_RIGHT_OF_CENTER: pcm_channels |= (ISMD_AUDIO_CHANNEL_RIGHT          << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_SIDE_LEFT            : pcm_channels |= (ISMD_AUDIO_CHANNEL_LEFT_REAR_SUR  << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_SIDE_RIGHT           : pcm_channels |= (ISMD_AUDIO_CHANNEL_RIGHT_REAR_SUR << pcm_pos); break;
            case GST_AUDIO_CHANNEL_POSITION_INVALID              : // no break;
            case GST_AUDIO_CHANNEL_POSITION_NONE                 : // no break;
            default                                              : pcm_channels |= (ISMD_AUDIO_CHANNEL_INVALID        << pcm_pos); break;
          }
        }
        printf("ismd_gst_audio_sink: ismd_configure_input: Using custom channel map %8x %1x%1x%1x%1x%1x%1x%1x%1x\n", pcm_channels, (sink->channels>0)?pos[0]:0, (sink->channels>1)?pos[1]:0, (sink->channels>2)?pos[2]:0, (sink->channels>3)?pos[3]:0, (sink->channels>4)?pos[4]:0, (sink->channels>5)?pos[5]:0, (sink->channels>6)?pos[6]:0, (sink->channels>7)?pos[7]:0);
        g_free(pos);
      }
#endif

      result = ismd_audio_input_set_pcm_format (sink->processor,
          smd_element->dev_handle, sink->width, sink->rate,
          /* AUDIO_CHAN_CONFIG_2_CH - 2 channel stereo
           * AUDIO_CHAN_CONFIG_6_CH - 6 channels (5.1)
           * AUDIO_CHAN_CONFIG_8_CH - 8 channels (7.1) */
          pcm_channels);
      if (result != ISMD_SUCCESS) {
        GST_ERROR_OBJECT (sink, "ismd_audio_input_set_pcm_format failed(%d)",
            result);
        goto beach;
      }
      break;
    default:
      break;
  }

  /* Slacken default audio timing.
   * The default audio driver output timing slack is 1.5 milliseconds
   * If the audio PTS is not with in this slack then the audio driver
   * will make correction by dropping packets or adding silence.
   * During soft demux such as an AVI file with out time stamps
   * the soft demux algorithm for determining PTS is not accurate
   * causing audible glitches unless the timing is loosened.
   */
  result = ismd_audio_input_set_timing_accuracy (sink->processor,
      smd_element->dev_handle,
      ALLOWED_MS_TIMING_DRIFT_FOR_SOFT_DEMUX_AHEAD,
      ALLOWED_MS_TIMING_DRIFT_FOR_SOFT_DEMUX_BEHIND);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_input_set_timing_accuracy failed(%d)",
        result);
    goto beach;
  }
  result = ismd_audio_input_get_notification_event (sink->processor,
      smd_element->dev_handle, ISMD_AUDIO_NOTIFY_CLIENT_ID,
      &sink->clientid_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_input_get_notification_event for "
        "client_id failed(%d)", result);
    goto beach;
  }

  result = ismd_audio_input_get_notification_event (sink->processor,
      smd_element->dev_handle, ISMD_AUDIO_NOTIFY_DATA_RENDERED, &sink->bos_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_input_get_notification_event for bos "
        "failed(%d)", result);
    goto beach;
  }

  result = ismd_audio_input_get_notification_event (sink->processor,
      smd_element->dev_handle, ISMD_AUDIO_NOTIFY_STREAM_END, &sink->eos_event);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_input_get_notification_event for eos "
        "failed(%d)", result);
    goto beach;
  }

  if (sink->monitor_loop == NULL) {
    sink->monitor_stop = FALSE;
    sink->monitor_loop = gst_task_create (
        (GstTaskFunction) ismd_gst_audio_sink_loop, sink);
    gst_task_set_lock (sink->monitor_loop, sink->monitor_mutex);
    gst_task_start (sink->monitor_loop);
    GST_DEBUG_OBJECT (sink, "monitoring task started");
  }

  ret = TRUE;
beach:
  return ret;
}


static inline gboolean
ismd_unconfigure_output (ISmdGstAudioSink * sink, output_device * device)
{
  ismd_result_t result = ISMD_SUCCESS;
  if (device->output_handle != ISMD_DEV_HANDLE_INVALID &&
        !device->shared_physical_out) {
    GST_DEBUG_OBJECT (sink, "removing output handle %d", device->output_handle);
    result = ismd_audio_remove_output (sink->processor, device->output_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_remove_output failed(%d)", result);
    }
  }
  device->output_handle = ISMD_DEV_HANDLE_INVALID;
  return TRUE;
}

static inline gboolean
ismd_configure_output (ISmdGstAudioSink * sink, output_device * device)
{
  ismd_result_t result = ISMD_SUCCESS;
  ismd_audio_output_config_t out_config;

  /* First unconfigure it if is required */
  ismd_unconfigure_output (sink, device);
  if (device->out_mode == OUT_OFF)
    goto beach;

  /* Now we can try to configure it */
  out_config.stream_delay = sink->out_delay;
  out_config.sample_rate = sink->rate;
  out_config.sample_size = sink->width;
  out_config.out_mode = device->out_mode;
  out_config.ch_config = ISMD_AUDIO_STEREO;
  out_config.ch_map = 0;

  if (out_config.sample_rate == 8000 || out_config.sample_rate == 12000 ||
        out_config.sample_rate == 16000 || out_config.sample_rate == 24000 ||
        out_config.sample_rate == 32000) {
    out_config.sample_rate = 48000;
  }
  else if (out_config.sample_rate == 11025 || out_config.sample_rate == 22050) {
    out_config.sample_rate = 44100;
  }

  if (device->ismd_port == GEN3_HW_OUTPUT_HDMI) {
    if (device->out_mode == OUT_AUTO) {
      if (sink->codec == ISMD_AUDIO_MEDIA_FMT_DD) {
        GST_DEBUG_OBJECT (sink, "Enable passthrough on the HDMI output");
        out_config.out_mode = ISMD_AUDIO_OUTPUT_PASSTHROUGH;
      }
      else {
        GST_DEBUG_OBJECT (sink, "Enable PCM on the HDMI output");
        out_config.out_mode = ISMD_AUDIO_OUTPUT_PCM;
      }
    }
    if (sink->hdmi_pcm_max_channels == 2)
      out_config.ch_config = ISMD_AUDIO_STEREO;
    else if (sink->hdmi_pcm_max_channels == 6)
      out_config.ch_config = ISMD_AUDIO_5_1;
    else if (sink->hdmi_pcm_max_channels == 8)
      out_config.ch_config = ISMD_AUDIO_7_1;

    /*For pcm output, if input source channel number is supported by recevier, we set output configure accoding to source itself.*/
    if (out_config.out_mode == ISMD_AUDIO_OUTPUT_PCM && sink->channels < sink->hdmi_pcm_max_channels) {
      if (sink->channels == 2)
         out_config.ch_config = ISMD_AUDIO_STEREO;
      else if (sink->channels == 6)
         out_config.ch_config = ISMD_AUDIO_5_1;
    }
    

    if (sink->hdmi_pcm_max_samplesize != 0)
      out_config.sample_size = sink->hdmi_pcm_max_samplesize;

    switch (sink->clock_family) {
      case AUDIO_PLL_FREQ_FAMILY_44100:
        out_config.sample_rate = 44100;
        break;
      case AUDIO_PLL_FREQ_FAMILY_48000:
        out_config.sample_rate = 48000;
        break;
      default:
        out_config.sample_rate = 48000;
        break;
    }
  } else if (device->ismd_port == GEN3_HW_OUTPUT_SPDIF) {
    if (device->out_mode == OUT_AUTO) {
      if (sink->codec == ISMD_AUDIO_MEDIA_FMT_DD) {
        GST_DEBUG_OBJECT (sink, "Enable passthrough on the SPDIF output");
        out_config.out_mode = ISMD_AUDIO_OUTPUT_PASSTHROUGH;
      }
      else {
        GST_DEBUG_OBJECT (sink, "Enable PCM on the SPDIF output");
        out_config.out_mode = ISMD_AUDIO_OUTPUT_PCM;
      }
    }
    if (out_config.out_mode == ISMD_AUDIO_OUTPUT_PASSTHROUGH) {
      out_config.ch_config = ISMD_AUDIO_5_1;
      out_config.sample_rate = sink->rate;
    } else {
      if (out_config.out_mode == ISMD_AUDIO_OUTPUT_PCM) {
        out_config.ch_config = ISMD_AUDIO_STEREO;
        out_config.sample_size = 20;
      } else {
        out_config.ch_config = ISMD_AUDIO_5_1;
        out_config.sample_size = 16;
      }
      switch (sink->clock_family) {
        case AUDIO_PLL_FREQ_FAMILY_44100:
          out_config.sample_rate = 44100;
          break;
        case AUDIO_PLL_FREQ_FAMILY_48000:
          out_config.sample_rate = 48000;
          break;
        default:
          out_config.sample_rate = 48000;
          break;
      }
    }
  } else if (device->ismd_port == GEN3_HW_OUTPUT_I2S1) {
    if (sink->channels == 6)
      out_config.ch_config = ISMD_AUDIO_5_1;
    else if (sink->channels == 8)
      out_config.ch_config = ISMD_AUDIO_7_1;

  }

  /* ensure that sample rate is a valid value of selected PLL family */
  if (sink->clock_family != get_audio_pll_family (out_config.sample_rate)) {
    switch (sink->clock_family) {
      case AUDIO_PLL_FREQ_FAMILY_44100:
        out_config.sample_rate = 44100;
        break;
      case AUDIO_PLL_FREQ_FAMILY_48000:
        out_config.sample_rate = 48000;
        break;
      default:
        out_config.sample_rate = 48000;
        break;
    }
  }

  GST_INFO_OBJECT (sink,
      "Configuring %d delay=%d size=%d chconf=0x%x mode=%d rate=%d",
      device->ismd_port, out_config.stream_delay, out_config.sample_size,
      out_config.ch_config, out_config.out_mode, out_config.sample_rate);

  device->shared_physical_out = TRUE;
  result = ismd_audio_output_get_handle_by_hw_id (sink->processor,
      device->ismd_port, &device->output_handle);
  if (result == ISMD_SUCCESS) {
    GST_INFO_OBJECT (sink, "going to reconfigure shared out port");
    result = ismd_audio_output_disable (sink->processor, device->output_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_output_disable  failed(%d)", result);
      goto beach;
    }
    result = ismd_audio_output_set_channel_config (sink->processor,
      device->output_handle, out_config.ch_config);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_output_set_channel_config failed(%d)",
          result);
      goto beach;
    }
    result = ismd_audio_output_set_sample_size (sink->processor,
      device->output_handle, out_config.sample_size);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_output_set_sample_size failed(%d)",
          result);
      goto beach;
    }
    result = ismd_audio_output_set_sample_rate (sink->processor,
      device->output_handle, out_config.sample_rate);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_output_set_sample_rate failed(%d)",
          result);
      goto beach;
    }
    result = ismd_audio_output_set_mode (sink->processor,
      device->output_handle, out_config.out_mode);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_output_set_mode failed(%d)",
          result);
      goto beach;
    }

    if (out_config.stream_delay) {
      result = ismd_audio_output_set_delay (sink->processor,
          device->output_handle, out_config.stream_delay);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (sink, "ismd_audio_output_set_delay failed(%d) maybe"
            " smd_buffers_AUD_PER_OUTPUT_DELAY is missing in memory layout",
            result);
        result = ISMD_SUCCESS;
      }
    }
  } else {
    device->shared_physical_out = FALSE;
    result = ismd_audio_add_phys_output (sink->processor, device->ismd_port,
        out_config, &device->output_handle);
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink, "ismd_audio_add_phys_output failed(%d)", result);
      goto beach;
    }
  }

#if !NEW_MASTER_CLOCK_API
  /* Next is deprecated */
  if (device->ismd_port != GEN3_HW_OUTPUT_HDMI) {
    GST_DEBUG_OBJECT (sink, "Trying to set external bit clock div");
    result = ismd_audio_output_set_external_bit_clock_div (sink->processor,
        device->output_handle, set_sadiv_value (out_config.sample_rate,
            device->ismd_port));
    if (result != ISMD_SUCCESS) {
      GST_ERROR_OBJECT (sink,
          "ismd_audio_output_set_external_bit_clock_div failed(%d)", result);
      goto beach;
    }
  }
#endif

beach:
  return (result == ISMD_SUCCESS) ? TRUE : FALSE;
}

static inline gboolean
ismd_enable_output (ISmdGstAudioSink * sink, output_device * device)
{
  ismd_result_t result = ISMD_SUCCESS;

  if (device->out_mode == OUT_OFF)
    goto beach;

  /* if latency is set and it's hdmi our encoded output, don't allow it */
  if (  (sink->latency == ISMD_AUDIO_LATENCY_MODE_LOW_WITH_POST_PROCESSING) 
     && (  (device->ismd_port == GEN3_HW_OUTPUT_HDMI)
        || (device->out_mode  >= OUT_AC3) ) )
    goto beach;

  GST_DEBUG_OBJECT (sink, "Trying to enable processor %d output_handle=%d",
      sink->processor, device->output_handle);
  result = ismd_audio_output_enable (sink->processor, device->output_handle);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_output_enable failed(%d)", result);
  }

beach:
  return (result == ISMD_SUCCESS) ? TRUE : FALSE;
}

static inline GstPadTemplate *
get_sink_pad_template ()
{
  GstCaps *caps = NULL;

  /* Add raw pcm format */
  caps = gst_caps_from_string (PCM_CAPS);
  GST_INFO ("Added %s", PCM_CAPS);

  /* Check for LPCM from mpeg PS */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_DVD_PCM) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (XPRIV_LPCM_CAPS));
    GST_INFO ("Added %s", XPRIV_LPCM_CAPS);
  }

#ifdef NOT_REEL_PATCHED
  // Use software mp3 decoder!
  // Helps for fast shoutcast responses and jumping in mp3 files
  /* Check for mpeg 1 or mpeg 2 bc */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_MPEG) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (MPEG12_CAPS));
    GST_INFO ("Added %s", MPEG12_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XMPEG12_CAPS));
    GST_INFO ("Added %s", XMPEG12_CAPS);
  }
#endif

  /* Check for mpeg 2 or mpeg 4 aac */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_AAC) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (MPEG4_CAPS));
    GST_INFO ("Added %s", MPEG4_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XMPEG4_CAPS));
    GST_INFO ("Added %s", XMPEG4_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XAAC_CAPS));
    GST_INFO ("Added %s", XAAC_CAPS);
  }

  /* Check for ac3 */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_DD) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (XAC3_CAPS));
    GST_INFO ("Added %s", XAC3_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XPRIV_AC3_CAPS));
    GST_INFO ("Added %s", XPRIV_AC3_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XDD_CAPS));
    GST_INFO ("Added %s", XDD_CAPS);
  }

  /* Check for eac3/dolby digital+ */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_DD_PLUS) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (XEAC3_CAPS));
    GST_INFO ("Added %s", XEAC3_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XDDPLUS_CAPS));
    GST_INFO ("Added %s", XDDPLUS_CAPS);
  }

  /* Check for dolby TrueHD */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_TRUE_HD) == ISMD_SUCCESS) {
  }

  /* Check for DTS */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_DTS) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (XDTS_CAPS));
    GST_INFO ("Added %s", XDTS_CAPS);
    gst_caps_append (caps, gst_caps_from_string (XPRIV_DTS_CAPS));
    GST_INFO ("Added %s", XPRIV_DTS_CAPS);
  }

  /* Check for WMA */
  if (ismd_audio_codec_available (ISMD_AUDIO_MEDIA_FMT_WM9) == ISMD_SUCCESS) {
    gst_caps_append (caps, gst_caps_from_string (XWMA_CAPS));
    GST_INFO ("Added %s", XWMA_CAPS);
  }


  return gst_pad_template_new ("sink", GST_PAD_SINK, GST_PAD_ALWAYS, caps);
}

/**
 * ismd_audio_sink_base_init
 *      Define element details and add pad templates if any
 *      @g_class - Pointer to the GStreamer object
 */
static void
ismd_gst_audio_sink_base_init (gpointer g_class)
{
  static const GstElementDetails ismd_gst_audio_sink_details =
      GST_ELEMENT_DETAILS
      ("Intel Streaming Media Driver (ISMD) Hardware Audio Renderer Sink",
      "Sink/Audio",
      "GStreamer Audio Sink Element for Intel's Media Processors",
      "http://www.intelconsumerelectronics.com/");


  GstElementClass *gstelement_class = GST_ELEMENT_CLASS (g_class);

  GstPadTemplate *templ = get_sink_pad_template();
  gst_element_class_add_pad_template (gstelement_class, templ);
  gst_object_unref (templ);

  gst_element_class_set_details (gstelement_class,
      &ismd_gst_audio_sink_details);
}

static inline gboolean
ismd_reconfigure_output (ISmdGstAudioSink * sink, output_device * device)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  GstState current_state = GST_STATE (smd_element);
  gboolean is_playing = FALSE;

  if (!device->configured)
    return TRUE;

  if (current_state == GST_STATE_PLAYING) {
    GST_DEBUG_OBJECT (sink, "audio driver is in PLAY state");
    is_playing = TRUE;
    ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_PAUSE);
  }

  ismd_configure_output (sink, device);

  /* Return audio driver to previous state */
  if (is_playing) {
    GST_DEBUG_OBJECT (sink, "audio driver being restored to PLAY state");
    ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_PLAY);
  }

  return TRUE;
}

GstClock *
ismd_gst_audio_sink_provide_clock (GstElement * element)
{
  ISmdGstAudioSink *sink;
  GstClock *clock;

  sink = ISMD_GST_AUDIO_SINK (element);
  if (G_UNLIKELY (sink->provided_clock == NULL)) {
    sink->provided_clock = ismd_gst_clock_get_default_clock ();
  }
  clock = GST_CLOCK_CAST (gst_object_ref (sink->provided_clock));

  GST_INFO_OBJECT (sink, "provide %p (ID:%d)",
      clock, sink->provided_clock->dev_handle);
  return clock;
}

static void
ismd_gst_audio_sink_dispose (GObject * object)
{
  ISmdGstAudioSink *sink;

  sink = ISMD_GST_AUDIO_SINK (object);
  if (sink->provided_clock)
    gst_object_unref (sink->provided_clock);
  sink->provided_clock = NULL;
  G_OBJECT_CLASS (parent_class)->dispose (object);
}

static void
ismd_gst_audio_sink_finalize (GObject * object)
{
  ISmdGstAudioSink *sink;

  sink = ISMD_GST_AUDIO_SINK (object);

  g_static_rec_mutex_free (sink->monitor_mutex);
  g_free (sink->monitor_mutex);
  sink->monitor_mutex = NULL;
  sink->monitor_loop = NULL;

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GstPadLinkReturn
ismd_gst_audio_sinkpad_setcaps (GstPad * pad, GstCaps * caps)
{
  gboolean ret = FALSE;
  GstStructure *structure;
  ISmdGstAudioSink *sink;
  ISmdGstElement *smd_element;
  const gchar *name = NULL;
  gboolean is_playing = FALSE;
  GstState current_state;
  gint mpegversion = 0;
  gint layer = 0;
  ismd_result_t result = ISMD_SUCCESS;
  ismd_audio_input_pass_through_config_t passThroughConfig;
  int latency_ms;

  sink = ISMD_GST_AUDIO_SINK (gst_pad_get_parent (pad));
  smd_element = ISMD_GST_ELEMENT (sink);
  structure = gst_caps_get_structure (caps, 0);
  name = gst_structure_get_name (structure);
  current_state = GST_STATE (smd_element);

  GST_INFO_OBJECT (pad, "setcaps called with %" GST_PTR_FORMAT, caps);

  /* Audio driver cannot be configured while in PLAYING state - if this is the
   * case, pause it before configuring it, then return it back */

  if (current_state == GST_STATE_PLAYING) {
    GST_DEBUG_OBJECT (sink, "audio driver is in PLAY state");
    is_playing = TRUE;
    ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_PAUSE);
  }

  if (!gst_structure_get_int (structure, "width", &sink->width))
    sink->width = 16;
  if (!gst_structure_get_int (structure, "rate", &sink->rate))
    sink->rate = 48000;
  if (!gst_structure_get_int (structure, "channels", &sink->channels))
    sink->channels = 2;
  if (!gst_structure_get_int (structure, "bitrate", &sink->bitrate))
    sink->bitrate = -1;

#ifndef NOT_REEL_PATCHED
printf("#####################ismd_gst_audio_sinkpad_setcaps %s                      \n", gst_structure_to_string(structure));
#endif

  if (!strcmp (name, "audio/x-raw-int")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_PCM;
  } else if (!strcmp (name, "audio/x-private1-lpcm")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_DVD_PCM;
  } else if (!strcmp (name, "audio/x-eac3")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_DD_PLUS;
  } else if (!strcmp (name, "audio/x-ddplus")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_DD_PLUS;
  } else if (!strcmp (name, "audio/x-private1-dts") ||
      !strcmp (name, "audio/x-dts")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_DTS;
  } else if (!strcmp (name, "audio/mpeg") || !strcmp (name, "audio/x-mpeg")) {
    gst_structure_get_int (structure, "mpegversion", &mpegversion);
    gst_structure_get_int (structure, "layer", &layer);
    /* NOTE: MPEG audio decoder can detect the layer */
    switch (mpegversion) {
      case 1:
        sink->codec = ISMD_AUDIO_MEDIA_FMT_MPEG;
        break;
      case 2:
      case 4:
        {
          const gchar * stream_format = NULL;
          stream_format = gst_structure_get_string (structure, "stream-format");
          gboolean is_loas = FALSE;
          if (stream_format) {
            if (!strcmp (stream_format, "loas") ||
                  !strcmp (stream_format, "latm")) {
              is_loas = TRUE;
            }
          }
          if (is_loas) {
            sink->codec = ISMD_AUDIO_MEDIA_FMT_AAC_LOAS;
            sink->first_aac_packet = FALSE;
          }
          else {
            sink->codec = ISMD_AUDIO_MEDIA_FMT_AAC;
            if (stream_format && !strcmp (stream_format, "adts")) {
              sink->first_aac_packet = FALSE;
            }
            else {
              if (sink->first_aac_packet == FALSE) {
                if (create_aac_header (sink, structure)) {
                  sink->first_aac_packet = TRUE;
                }
              }
            }
          }
        }
        break;
      default:
        GST_ERROR_OBJECT (sink, "Invalid MPEG version\n");
        goto beach;
    }
  } else if (!strcmp (name, "audio/x-aac")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_AAC;
  } else if (!strcmp (name, "audio/x-ac3") || !strcmp (name, "audio/x-dd") ||
      !strcmp (name, "audio/x-private1-ac3")) {
    sink->codec = ISMD_AUDIO_MEDIA_FMT_DD;
  } else if (!strcmp (name, "audio/x-wma")) {
    gint wmaversion;
    const GValue *codec_data;

    gst_structure_get_int (structure, "wmaversion", &wmaversion);
    /* FLUENDO FIXME: This is only for wma version = 2  (wma1 = 0x160, ...) */
    sink->wma_fmt.format_tag = 0x161;
    sink->wma_fmt.sample_rate = sink->rate;
    sink->wma_fmt.num_channels = sink->channels;
    sink->wma_fmt.bitrate = sink->bitrate / 8;
    sink->wma_fmt.sample_size = sink->width;
    gst_structure_get_int (structure, "block_align",
        &sink->wma_fmt.block_align);
    codec_data = gst_structure_get_value (structure, "codec_data");

    if (codec_data) {
      GstBuffer *buffer;
      guint8 *data;

      buffer = gst_value_get_buffer (codec_data);
      data = GST_BUFFER_DATA (buffer);
      sink->wma_fmt.encode_option = data[3] << 8 | data[4];
    } else {
      GST_ERROR_OBJECT (sink, "encoding information missing in codec_data");
      goto beach;
    }
    sink->codec = ISMD_AUDIO_MEDIA_FMT_WM9;
  } else {
    GST_ERROR_OBJECT (sink, "unrecognized/unsupported audio format");
    goto beach;
  }

  /* Configure the master clock */
  sink->clock_family = get_audio_pll_family (sink->rate);
  /* AC3 and DTS transcoding only supports 48K sample rate */
  if (sink->hdmi.out_mode >= OUT_AC3 || sink->spdif.out_mode >= OUT_AC3) {
    sink->clock_family = AUDIO_PLL_FREQ_FAMILY_48000;
  }

  /* Reconfigure device */
#ifndef NOT_REEL_PATCHED
  if (!ismd_configure_input (sink, gst_audio_get_channel_positions(structure)))
    goto beach;
#else
  if (!ismd_configure_input (sink))
    goto beach;
#endif

  result = ismd_audio_set_latency_mode(sink->processor, sink->latency, &latency_ms);
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (sink, "ismd_audio_set_latency_mode failed (%d)", result);
  }
  else if (sink->latency == ISMD_AUDIO_LATENCY_MODE_LOW_WITH_POST_PROCESSING) {
    GST_WARNING("audio latency set.  HDMI and encode audio output will be disabled");
  }

  /* Create physical outputs and configure them */
  if (!ismd_configure_output (sink, &sink->hdmi))
    goto beach;
  if (!ismd_configure_output (sink, &sink->spdif))
    goto beach;
  if (!ismd_configure_output (sink, &sink->i2s0))
    goto beach;
  if (!ismd_configure_output (sink, &sink->i2s1))
    goto beach;

  if (!set_audio_pll_freq (sink, sink->clock_family))
    goto beach;

  /* Enable the physical outputs */
  if (!ismd_enable_output (sink, &sink->hdmi))
    goto beach;
  if (!ismd_enable_output (sink, &sink->spdif))
    goto beach;
  if (!ismd_enable_output (sink, &sink->i2s0))
    goto beach;
  if (!ismd_enable_output (sink, &sink->i2s1))
    goto beach;

  /* Configure input as primary an set passthrough if needed.
   * This have to be done after outputs had been added to the processor. */
  passThroughConfig.is_pass_through = FALSE;
  if ((sink->spdif.out_mode == OUT_AUTO ||
       sink->spdif.out_mode == OUT_PASSTHROUGH) &&
       sink->codec == ISMD_AUDIO_MEDIA_FMT_DD) {
    GST_DEBUG_OBJECT (sink, "SPDIF will be passthrough. "
                            "Enable passthrough on the input port");
    passThroughConfig.is_pass_through = TRUE;
  }
  if ((sink->hdmi.out_mode == OUT_AUTO ||
       sink->hdmi.out_mode == OUT_PASSTHROUGH) &&
       sink->codec == ISMD_AUDIO_MEDIA_FMT_DD) {
    GST_DEBUG_OBJECT (sink, "HDMI will be passthrough. "
                            "Enable passthrough on the input port");
    passThroughConfig.is_pass_through = TRUE;
  }

  GST_DEBUG_OBJECT (sink, "make audio input to be primary");
  result = ismd_audio_input_set_as_primary (sink->processor,
      smd_element->dev_handle, passThroughConfig);
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (sink, "ismd_audio_input_set_as_primary failed (%d)",
        result);
  }

  /* Return audio driver to previous state */
  if (is_playing) {
    GST_DEBUG_OBJECT (sink, "audio driver being restored to PLAY state");
    ismd_dev_set_state (smd_element->dev_handle, ISMD_DEV_STATE_PLAY);
  }

  if (sink->codec > ISMD_AUDIO_MEDIA_FMT_PCM) {
    GstTagList * taglist = gst_tag_list_new ();

    /* Post a tag with the codec name */
    if (sink->codec == ISMD_AUDIO_MEDIA_FMT_DVD_PCM) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "LPCM audio", NULL);
    } else if (sink->codec == ISMD_AUDIO_MEDIA_FMT_MPEG) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "MPEG 1/2 audio", NULL);
    } else if (sink->codec == ISMD_AUDIO_MEDIA_FMT_AAC ||
        sink->codec == ISMD_AUDIO_MEDIA_FMT_AAC_LOAS) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "MPEG 2/4 AAC audio", NULL);
    } else if (sink->codec == ISMD_AUDIO_MEDIA_FMT_DD) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "AC-3 audio", NULL);
    } else if (sink->codec == ISMD_AUDIO_MEDIA_FMT_DD_PLUS) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "EAC-3 audio", NULL);
    } else if (sink->codec == ISMD_AUDIO_MEDIA_FMT_TRUE_HD) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "Dolby TrueHD", NULL);
    } else if (sink->codec >= ISMD_AUDIO_MEDIA_FMT_DTS_HD &&
        sink->codec <= ISMD_AUDIO_MEDIA_FMT_DTS_LBR) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "DTS audio", NULL);
    } else if (sink->codec == ISMD_AUDIO_MEDIA_FMT_WM9) {
      gst_tag_list_add (taglist, GST_TAG_MERGE_REPLACE, GST_TAG_AUDIO_CODEC,
          "Windows Media Audio 9", NULL);
    }
    gst_element_found_tags (GST_ELEMENT (sink), taglist);
  }
  ret = TRUE;

beach:
  gst_object_unref (sink);
  return ret;
}

static GstStateChangeReturn
ismd_gst_audio_sink_change_state (GstElement * element,
    GstStateChange transition)
{
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (element);
  GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;

  GST_DEBUG_OBJECT (sink, "change state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));

  switch (transition) {
    case GST_STATE_CHANGE_READY_TO_PAUSED:
    {
      /* This should try to open the HW device connection, and allocate
       * the hw resources. Driver will not consume input data */
      if (ismd_open (element) != TRUE) {
        GST_ERROR_OBJECT (sink, "audio renderer(%d): ismd_open failed",
            smd_element->dev_handle);
        goto failure;
      }
      sink->format = GST_FORMAT_UNDEFINED;
      sink->first_pts = GST_CLOCK_TIME_NONE;
      sink->last_pts = GST_CLOCK_TIME_NONE;
      sink->bos_posted = FALSE;
      sink->eos_posted = FALSE;
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
    GST_ERROR_OBJECT (sink, "audio renderer(%d): change state failure",
        smd_element->dev_handle);
    goto failure;
  }

  switch (transition) {
    case GST_STATE_CHANGE_PAUSED_TO_READY:
    {
      if (ismd_stop (element) != TRUE) {
        GST_ERROR_OBJECT (sink, "audio renderer(%d): ismd_stop failed",
            smd_element->dev_handle);
        goto failure;
      }
      sink->format = GST_FORMAT_UNDEFINED;
      sink->first_pts = GST_CLOCK_TIME_NONE;
      sink->last_pts = GST_CLOCK_TIME_NONE;

      if (ismd_close (element) != TRUE) {
        GST_ERROR_OBJECT (sink, "audio renderer(%d): ismd_close failed",
            smd_element->dev_handle);
        goto failure;
      }
      break;
    }
    default:
      break;
  }

  GST_DEBUG_OBJECT (sink, "changed state from %s to %s",
      gst_element_state_get_name (GST_STATE_TRANSITION_CURRENT (transition)),
      gst_element_state_get_name (GST_STATE_TRANSITION_NEXT (transition)));

  return ret;

failure:
  GST_ERROR_OBJECT (sink, "change state failed");
  return GST_STATE_CHANGE_FAILURE;
}

static inline gboolean
get_hdmi_info (ISmdGstAudioSink * sink)
{
  gboolean ret = FALSE;
  gdl_pd_recv_t cmd = GDL_PD_RECV_HDMI_AUDIO_CTRL;
  gdl_hdmi_audio_ctrl_t ctrl;
  unsigned int rates, i, sizes;
  gint samplerate;
  gint samplesize;
  gint j = 0;
  gdl_ret_t result;


  sink->hdmi_pcm_max_channels = 0;
  sink->hdmi_pcm_max_samplerate = 0;
  sink->hdmi_pcm_max_samplesize = 0;
  for (i = 0; i < 8; i++)
    sink->hdmi_pcm_samplerates[i] = 0;

  if (gdl_init (0) != GDL_SUCCESS) {
    GST_ERROR_OBJECT (sink, "gdl_init failed");
    goto beach;
  }

  memset (&ctrl, 0, sizeof (ctrl));
  /* Initialize query data */
  ctrl.cmd_id = GDL_HDMI_AUDIO_GET_CAPS;
  ctrl.data._get_caps.index = 0;

  result = gdl_port_recv (GDL_PD_ID_HDMI, cmd, &ctrl, sizeof (ctrl));
  if (result != GDL_SUCCESS) {
    GST_WARNING_OBJECT (sink, "HDMI audio output disabled because couldn't "
        "retrieve the capabilities");
    sink->hdmi.out_mode = OUT_OFF;
    goto done;
  }

  /* Get audio capabilities one after another */
  do {
    gboolean is_pcm =
        ((gdl_hdmi_audio_fmt_t) ctrl.data._get_caps.cap.format ==
        GDL_HDMI_AUDIO_FORMAT_PCM);
    if (is_pcm)
      sink->hdmi_pcm_max_channels = ctrl.data._get_caps.cap.max_channels;

    GST_INFO_OBJECT (sink, "Audio format: %s, max channels: %d",
        gdl_dbg_string_audio_format ((gdl_hdmi_audio_fmt_t) ctrl.data.
            _get_caps.cap.format), ctrl.data._get_caps.cap.max_channels);

    rates = ctrl.data._get_caps.cap.fs;
    GST_INFO_OBJECT (sink, "Supported sampling rates: %02x", rates);
    for (i = 0; i < 7; i++) {
      if (rates & (1 << i)) {
        samplerate = 1000.0 *
            g_ascii_strtod (gdl_dbg_string_sampling_rate ((gdl_hdmi_audio_fs_t) (1 <<
                    i)), NULL);
        GST_INFO_OBJECT (sink, "%d Hz", samplerate);
        if (is_pcm) {
          if (j < 8) {
            sink->hdmi_pcm_samplerates[j++] = samplerate;
          }
          if (samplerate > sink->hdmi_pcm_max_samplerate)
            sink->hdmi_pcm_max_samplerate = samplerate;
        }
      }
    }

    sizes = ctrl.data._get_caps.cap.ss_bitrate;
    GST_INFO_OBJECT (sink, "Supported sample sizes: %02x", sizes);
    for (i = 0; i < 3; i++) {
      if (sizes & (1 << i)) {
        samplesize =
            atoi (gdl_dbg_string_sample_size ((gdl_hdmi_audio_ss_t) (1 << i)));
        GST_INFO_OBJECT (sink, "%d bits", samplesize);
        if (is_pcm && samplesize > sink->hdmi_pcm_max_samplesize)
          sink->hdmi_pcm_max_samplesize = samplesize;
      }
    }
    ctrl.data._get_caps.index++;
    /* Loop to find all possible support total channels */
  } while (GDL_SUCCESS == gdl_port_recv (GDL_PD_ID_HDMI, cmd, &ctrl, sizeof (ctrl)));

done:
  gdl_close ();
  ret = TRUE;
beach:
  return ret;
}

/**
 * ismd_open
 * Open the audio renderer and get the port
 * @element - element containing audiosink
 * returns TRUE if setup is successful
 */
static inline gboolean
ismd_open (GstElement * element)
{
  ismd_result_t result = ISMD_SUCCESS;
  ismd_port_handle_t port = -1;
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (element);
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  gboolean ret = FALSE;

  if (sink->use_global_proc) {
    GST_INFO_OBJECT (sink, "Opening global audio processor");
    result = ismd_audio_open_global_processor (&sink->processor);
  } else {
    GST_INFO_OBJECT (sink, "Opening regular audio processor");
    result = ismd_audio_open_processor (&sink->processor);
  }
  if (result != ISMD_SUCCESS) {
    sink->processor = ISMD_DEV_HANDLE_INVALID;
    GST_ERROR_OBJECT (sink, "ismd_audio_open_*_processor failed (%d)", result);
    goto beach;
  }

  /* search for the top bin */
  GstElement *tmp_element = element;
  GstBin *bin_element;
  while ((tmp_element = GST_ELEMENT_PARENT(tmp_element)) != NULL)
  {
    bin_element = GST_BIN_CAST(tmp_element);
  }

  /* search recursively through all child bins for a video sink element */
  gpointer p;
  gboolean found = false;
  GstIterator *it = gst_bin_iterate_recurse(bin_element);
  while (gst_iterator_next(it, &p) != 0)
  {
      gchar *name;
      g_object_get(p,"name",&name,NULL);
      gst_object_unref(p);
      if ((NULL != strstr(name, "ismdgstvidrendsink"))
        ||(NULL != strstr(name, "ismdgstvidsink")))
      {
        found = true;
        break;
      }
  }
  gst_iterator_free(it);

  if (!found)
  {
    GST_DEBUG_OBJECT(sink, "vidrend is not active.  We're playing audio-only.  Force sync=false");
    sink->sync = false;
  }

  GST_DEBUG_OBJECT (sink, "audio processor %d opened -- sync?: %d", sink->processor, sink->sync);

  result = ismd_audio_add_input_port (sink->processor, sink->sync,
      &smd_element->dev_handle, &port);
  if (result != ISMD_SUCCESS) {
    GST_ERROR_OBJECT (sink, "ismd_audio_add_input_port failed (%d)", result);
    goto error;
  }
  GST_DEBUG_OBJECT (sink, "ismd_audio_add_input_port(proc=%d, timed=%d,"
      " aud_dev_handle=%d, aud_port=%d) succeded",
      sink->processor, sink->sync, smd_element->dev_handle, port);
  (smd_element->sink_pad)->ismd_port = port;

  update_gain_volume_and_mute (sink);
  get_hdmi_info (sink);
  ret = TRUE;

beach:
  return ret;

error:
  if (!ismd_close (element)) {
    GST_ERROR_OBJECT (sink, "ismd_close() failed.");
  }
  return FALSE;
}

/**
 * ismd_stop
 * Stop the audio renderer
 * @element - element containing audiosink
 * returns TRUE if audio renderer stop was successful
 */
static inline gboolean
ismd_stop (GstElement * element)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (element);
  GST_DEBUG_OBJECT (sink, "ismd_stop()");

  sink->first_aac_packet = FALSE;
  return TRUE;
}

/**
 * ismd_close
 * Close resources
 * @element - element containing audiosink
 * returns TRUE if closing resources was successful
 */
static inline gboolean
ismd_close (GstElement * element)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (element);
  ISmdGstElement *ismd_element = ISMD_GST_ELEMENT (element);

  if (sink->processor != ISMD_DEV_HANDLE_INVALID) {
    ismd_unconfigure_output (sink, &sink->hdmi);
    ismd_unconfigure_output (sink, &sink->spdif);
    ismd_unconfigure_output (sink, &sink->i2s0);
    ismd_unconfigure_output (sink, &sink->i2s1);

    ismd_unconfigure_input (sink);

    ismd_audio_close_processor (sink->processor);
    sink->processor = ISMD_DEV_HANDLE_INVALID;
    ismd_element->sink_pad->is_event_queue_attached = FALSE;
  }
  return TRUE;
}

static void
ismd_gst_audio_sink_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (object);

  switch (prop_id) {
    case PROP_AUDIO_GLOBAL_PROC:
      g_value_set_boolean (value, sink->use_global_proc);
      break;
    case PROP_AUDIO_SYNC:
      g_value_set_boolean (value, sink->sync);
      break;
    case PROP_AUDIO_OUT_HDMI:
      g_value_set_enum (value, sink->hdmi.out_mode);
      break;
    case PROP_AUDIO_OUT_SPDIF:
      g_value_set_enum (value, sink->spdif.out_mode);
      break;
    case PROP_AUDIO_OUT_I2S0:
      g_value_set_enum (value, sink->i2s0.out_mode);
      break;
    case PROP_AUDIO_OUT_I2S1:
      g_value_set_enum (value, sink->i2s1.out_mode);
      break;
    case PROP_AUDIO_OUT_DELAY:
      g_value_set_int (value, sink->out_delay);
      break;
    case PROP_AUDIO_INPUT_GAIN:
      GST_OBJECT_LOCK (sink);
      g_value_set_double (value, sink->input_gain);
      GST_OBJECT_UNLOCK (sink);
      break;
    case PROP_AUDIO_VOLUME:
      GST_OBJECT_LOCK (sink);
      g_value_set_double (value, sink->volume);
      GST_OBJECT_UNLOCK (sink);
      break;
    case PROP_AUDIO_MUTE:
      GST_OBJECT_LOCK (sink);
      g_value_set_boolean (value, sink->mute);
      GST_OBJECT_UNLOCK (sink);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
ismd_gst_audio_sink_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (object);
  guint out_mode;

  switch (prop_id) {
    case PROP_AUDIO_GLOBAL_PROC:
      sink->use_global_proc = g_value_get_boolean (value);
      GST_DEBUG_OBJECT (sink, "use global processor set to %d",
          sink->use_global_proc);
      break;
    case PROP_AUDIO_SYNC:
      sink->sync = g_value_get_boolean (value);
      GST_DEBUG_OBJECT (sink, "sync set to %d", sink->sync);
      break;
    case PROP_AUDIO_LATENCY:
      sink->latency = g_value_get_enum (value);
      GST_DEBUG_OBJECT (sink, "latency set to %d", sink->latency);
      break;
    case PROP_AUDIO_OUT_HDMI:
      GST_OBJECT_LOCK (sink);
      out_mode = g_value_get_enum (value);
      GST_INFO_OBJECT (sink, "HDMI set to mode %d", out_mode);
      if (out_mode != sink->hdmi.out_mode) {
        sink->hdmi.out_mode = out_mode;
        ismd_reconfigure_output (sink, &sink->hdmi);
      }
      GST_OBJECT_UNLOCK (sink);
      break;
    case PROP_AUDIO_OUT_SPDIF:
      GST_OBJECT_LOCK (sink);
      out_mode = g_value_get_enum (value);
      GST_INFO_OBJECT (sink, "SPDIF set to mode %d", out_mode);
      if (out_mode != sink->spdif.out_mode) {
        sink->spdif.out_mode = out_mode;
        ismd_reconfigure_output (sink, &sink->spdif);
      }
      GST_OBJECT_UNLOCK (sink);
      break;
    case PROP_AUDIO_OUT_I2S0:
      GST_OBJECT_LOCK (sink);
      out_mode = g_value_get_enum (value);
      GST_INFO_OBJECT (sink, "I2S0 set to mode %d", out_mode);
      if (out_mode != sink->i2s0.out_mode) {
        sink->i2s0.out_mode = out_mode;
        ismd_reconfigure_output (sink, &sink->i2s0);
      }
      GST_OBJECT_UNLOCK (sink);
      break;
    case PROP_AUDIO_OUT_I2S1:
      GST_OBJECT_LOCK (sink);
      out_mode = g_value_get_enum (value);
      GST_INFO_OBJECT (sink, "I2S1 set to mode %d", out_mode);
      if (out_mode != sink->i2s1.out_mode) {
        sink->i2s1.out_mode = out_mode;
        ismd_reconfigure_output (sink, &sink->i2s1);
      }
      GST_OBJECT_UNLOCK (sink);
      break;
    case PROP_AUDIO_OUT_DELAY:
      sink->out_delay = g_value_get_int (value);
      break;
    case PROP_AUDIO_INPUT_GAIN:
      GST_OBJECT_LOCK (sink);
      sink->input_gain = g_value_get_double (value);
      GST_OBJECT_UNLOCK (sink);
      update_gain_volume_and_mute (sink);
      break;
    case PROP_AUDIO_VOLUME:
      GST_OBJECT_LOCK (sink);
      sink->volume = g_value_get_double (value);
      GST_OBJECT_UNLOCK (sink);
      update_gain_volume_and_mute (sink);
      break;
    case PROP_AUDIO_MUTE:
      GST_OBJECT_LOCK (sink);
      sink->mute = g_value_get_boolean (value);
      GST_OBJECT_UNLOCK (sink);
      update_gain_volume_and_mute (sink);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static gboolean
ismd_gst_audio_sink_peer_query (ISmdGstElement * smd_element,
    GstQuery * query)
{
  GstPad *peer;
  gboolean res = FALSE;

  GST_DEBUG_OBJECT (smd_element, "forward upstream query type %s",
      GST_QUERY_TYPE_NAME (query));

  if ((peer = gst_pad_get_peer (GST_PAD (smd_element->sink_pad)))) {
    GST_DEBUG_OBJECT (peer, "forward upstream query type %s",
        GST_QUERY_TYPE_NAME (query));

    res = gst_pad_query (peer, query);

    GST_DEBUG_OBJECT (smd_element, "Upstream query returned %d: %"
        GST_PTR_FORMAT, res, query->structure);

    gst_object_unref (peer);
  }
  return res;
}

static gboolean
ismd_gst_audio_sink_query (GstElement * element, GstQuery * query)
{
  gboolean ret = FALSE;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (element);
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (element);
  GstFormat format;
  ismd_result_t result;

  GST_DEBUG_OBJECT (sink, "handling query %" GST_PTR_FORMAT, query->structure);

  switch GST_QUERY_TYPE (query) {
    case GST_QUERY_POSITION:
    {
      gint64 position;
      ismd_audio_stream_position_info_t smd_position;
      gst_query_parse_position (query, &format, &position);

      if (format != GST_FORMAT_TIME) {
        ret =ismd_gst_audio_sink_peer_query (smd_element, query);
        goto beach;
      }

      /* get position */
      result =  ismd_audio_input_get_stream_position (sink->processor,
          smd_element->dev_handle, &smd_position);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (sink, "ismd_audio_input_get_stream_position "
            "failed(%d)", result);
        goto beach;
      }
      GST_DEBUG_OBJECT (sink, "audio.base_time: %" GST_TIME_FORMAT,
          GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.base_time)));
      GST_DEBUG_OBJECT (sink, "audio.current_time: %" GST_TIME_FORMAT,
          GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.current_time)));
      GST_DEBUG_OBJECT (sink, "audio.segment_time: %" GST_TIME_FORMAT,
          GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.segment_time)));
      GST_DEBUG_OBJECT (sink, "audio.linear_time: %" GST_TIME_FORMAT,
          GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.linear_time)));
      GST_DEBUG_OBJECT (sink, "audio.scaled_time: %" GST_TIME_FORMAT,
          GST_TIME_ARGS (SMD_TO_GST_TIME (smd_position.scaled_time)));
      GST_DEBUG_OBJECT (sink, "audio.sample_count: %llu",
          smd_position.sample_count);
      GST_DEBUG_OBJECT (sink, "element.segment.time: %" GST_TIME_FORMAT,
          GST_TIME_ARGS (smd_element->segment.time));

      if (sink->format == GST_FORMAT_TIME) {
        if (smd_position.linear_time == ISMD_NO_PTS) {
          GST_WARNING_OBJECT (sink, "ismd_audio_input_get_stream_position "
              "reported NO PTS");
          position = SMD_TO_GST_TIME (smd_position.segment_time);
          position += smd_element->segment.time;
        } else if (!sink->bos_posted) {
          GST_INFO_OBJECT (sink, "ismd_audio_input_get_stream_position -- failed.  (stream not yet started)");
          goto beach;
        } else {
          position = SMD_TO_GST_TIME (smd_position.linear_time);
          position += smd_element->segment.time;
        }
      }
      else if (sink->format == GST_FORMAT_BYTES && smd_position.sample_count) {
        ismd_audio_stream_info_t stream_info;
        /* get sample_rate */
        result = ismd_audio_input_get_stream_info (sink->processor,
            smd_element->dev_handle, &stream_info);
        if (result != ISMD_SUCCESS) {
          GST_WARNING_OBJECT (sink, "ismd_audio_input_get_stream_info "
              "failed(%d)", result);
          goto beach;
        }
        position = gst_util_uint64_scale (smd_position.sample_count,
            GST_SECOND, stream_info.sample_rate);
      }

      GST_DEBUG_OBJECT (sink, "position = %" GST_TIME_FORMAT,
          GST_TIME_ARGS (position));

      /* return stream position */
      gst_query_set_position (query, format, position);
      ret = TRUE;
      break;
    }
    case GST_QUERY_DURATION:
    {
      gint64 duration;
      ismd_audio_stream_info_t stream_info;

      gst_query_parse_duration (query, &format, NULL);

      /* Try Upstream first */
      if ((ret = ismd_gst_audio_sink_peer_query (smd_element, query))) {
        goto beach;
      }
      /* We could approximate duration in time using the bitrate */
      if (format != GST_FORMAT_TIME) {
        goto beach;
      }

      /* get bitrate */
      result = ismd_audio_input_get_stream_info (sink->processor,
          smd_element->dev_handle, &stream_info);
      if (result != ISMD_SUCCESS) {
        GST_WARNING_OBJECT (sink, "ismd_audio_input_get_stream_info "
            "failed(%d)", result);
        goto beach;
      }

      GST_DEBUG_OBJECT (sink, "bitrate %d sample_rate %d sample_size %d "
          "channel_config %x channel_count %d algo %d",
          stream_info.bitrate, stream_info.sample_rate, stream_info.sample_size,
          stream_info.channel_config, stream_info.channel_count,
          stream_info.algo);

      if (!stream_info.bitrate) {
        GST_WARNING_OBJECT (sink, "no bitrate");
        goto beach;
      }

      /* get duration in bytes */
      gst_query_set_duration (query, GST_FORMAT_BYTES, -1);
      if (!(ret = ismd_gst_audio_sink_peer_query (smd_element, query)))
        goto beach;
      gst_query_parse_duration (query, &format, &duration);
      GST_DEBUG_OBJECT (sink, "query on peer pad reported bytes %"
          G_GUINT64_FORMAT, duration);

      duration = gst_util_uint64_scale (duration, GST_SECOND,
          stream_info.bitrate >> 3);

      GST_DEBUG_OBJECT (sink, "duration = %" GST_TIME_FORMAT,
          GST_TIME_ARGS (duration));

      gst_query_set_duration (query, GST_FORMAT_TIME, duration);
      ret = TRUE;
      break;
    }
    default:
    {
      ret = ismd_gst_audio_sink_peer_query (smd_element, query);
      break;
    }
  }

beach:
  return ret;

}

static void
ismd_gst_audio_sink_drain (ISmdGstElement * smd_element)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (smd_element);
  ismd_result_t result;
  ismd_event_t event_handle;
  gint client_id;
  gint counter = 0;

  result = ismd_audio_input_get_notification_event (sink->processor,
      smd_element->dev_handle, ISMD_AUDIO_NOTIFY_CLIENT_ID, &event_handle );
  if (result != ISMD_SUCCESS) {
    GST_WARNING_OBJECT (sink, "ismd_audio_input_get_notification_event "
        "failed(%d)", result);
    goto beach;
  }

  while (result == ISMD_SUCCESS) {
    result = ismd_event_wait (event_handle, 50);
    if (result == ISMD_SUCCESS) {
      ismd_event_acknowledge (event_handle);
      result = ismd_audio_input_get_client_id (sink->processor,
          smd_element->dev_handle, &client_id);
      if (result == ISMD_SUCCESS) {
        GST_DEBUG_OBJECT (sink, "got client_id %d", client_id);
      }
      counter = 0;
    }
    else if (result == ISMD_ERROR_TIMEOUT) {
      counter += 50;
      GST_LOG_OBJECT (sink, "timeout %d", counter);
      if (counter < ISMD_POLL_TIMEOUT) {
        result = ISMD_SUCCESS;
      }
    }
  }

beach:
  return;
}

static gboolean
ismd_gst_audio_sink_event (ISmdGstElement * smd_element, GstEvent * event)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (smd_element);

  switch (event->type) {
    case GST_EVENT_NEWSEGMENT:
      {
        gboolean update;
        gst_event_parse_new_segment (event, &update, NULL, &sink->format, NULL,
            NULL, NULL);
        if (!update) {
          sink->first_pts = GST_CLOCK_TIME_NONE;
          sink->last_pts = GST_CLOCK_TIME_NONE;
        }
      }
      break;
    case GST_EVENT_FLUSH_STOP:
      {
        GST_DEBUG_OBJECT (smd_element, "flushing audio sink");
        sink->format = GST_FORMAT_UNDEFINED;
        sink->first_pts = GST_CLOCK_TIME_NONE;
        sink->last_pts = GST_CLOCK_TIME_NONE;
        sink->bos_posted = FALSE;
        sink->eos_posted = FALSE;
      }
      break;
    default:
      break;
  }
  return TRUE;
}

static GstBuffer *
ismd_gst_audio_sink_convert (ISmdGstElement * smd_element, GstBuffer * buf,
    gboolean need_seq_hdr)
{
  ISmdGstAudioSink *sink = ISMD_GST_AUDIO_SINK (smd_element);
  GstCaps *caps;

  if (sink->format == GST_FORMAT_TIME) {
    GstClockTime pts, duration;

    gint64 clip_start, clip_stop;
    gboolean in_seg;
    pts = GST_BUFFER_TIMESTAMP (buf);
    duration = GST_BUFFER_DURATION (buf);


    /* Perfom clipping in the buffer if we are dealing with timed audio */
    if (!GST_CLOCK_TIME_IS_VALID (pts)) {
      if (!GST_CLOCK_TIME_IS_VALID (sink->last_pts)) {
        GST_LOG_OBJECT (sink, "dropping buffer due indefined pts");
        gst_buffer_unref (buf);
        buf = NULL;
        goto end;
      }
      else {
        pts = sink->last_pts;
      }
    }
    if (!GST_CLOCK_TIME_IS_VALID (sink->first_pts)) {
      sink->first_pts = GST_BUFFER_TIMESTAMP (buf);
    }

    GST_LOG_OBJECT (sink, "check for clipping on buffer %p with pts %" \
        GST_TIME_FORMAT " and duration %" GST_TIME_FORMAT,
        buf, GST_TIME_ARGS (pts), GST_TIME_ARGS (duration));

    clip_start = clip_stop = pts;
    if (GST_CLOCK_TIME_IS_VALID (duration))
      clip_stop += duration;

    /* Check if this buffer's timestamp/duration is in our segment */
    in_seg = gst_segment_clip (&smd_element->segment, GST_FORMAT_TIME,
        clip_start, clip_stop, &clip_start, &clip_stop);

    if (G_UNLIKELY (!in_seg)) {
      GST_LOG_OBJECT (sink, "dropping buffer due to temporal clipping");
      gst_buffer_unref (buf);
      buf = NULL;
      goto end;
    }
    sink->last_pts = pts;
  } else if (sink->format == GST_FORMAT_BYTES) {
    if (!GST_CLOCK_TIME_IS_VALID (sink->first_pts)) {
      GST_BUFFER_TIMESTAMP (buf) = sink->first_pts = 0;
      GST_DEBUG_OBJECT (sink, "interpolated timestamp of %" GST_TIME_FORMAT,
          GST_TIME_ARGS (0));
    }
    else {
      GST_BUFFER_TIMESTAMP (buf) = GST_CLOCK_TIME_NONE;
    }
  }

  caps = gst_buffer_get_caps (buf);
  if (caps) {
    GstStructure *structure;
    structure = gst_caps_get_structure (caps, 0);

    if (gst_structure_has_name (structure, "audio/x-private1-ac3")) {
      GST_BUFFER_DATA (buf) = GST_BUFFER_DATA (buf) + 2;
      GST_BUFFER_SIZE (buf) = GST_BUFFER_SIZE (buf) - 2;
    } else if (gst_structure_has_name (structure, "audio/x-private1-dts")) {
      GST_BUFFER_DATA (buf) = GST_BUFFER_DATA (buf) + 2;
      GST_BUFFER_SIZE (buf) = GST_BUFFER_SIZE (buf) - 2;
    }

    gst_caps_unref (caps);
  }

  if (sink->first_aac_packet) {
    GstBuffer *convbuf = NULL;
    int len = AAC_ADTS_HEADER_SIZE + GST_BUFFER_SIZE (buf);

    convbuf = gst_buffer_new_and_alloc (len);
    if (convbuf == NULL) {
      GST_ERROR_OBJECT (sink, "Failed to create GST Buffer");
      goto end;
    }
    memset (convbuf->data, 0x00, len);
    memcpy (convbuf->data, sink->aac_header_data, AAC_ADTS_HEADER_SIZE);
    memcpy (convbuf->data + AAC_ADTS_HEADER_SIZE, GST_BUFFER_DATA (buf),
        GST_BUFFER_SIZE (buf));
    GST_BUFFER_SIZE (convbuf) = len;

    /* Update the frame length */
    convbuf->data[3] |= ((len >> 11) & 0x03);
    convbuf->data[4] |= ((len >> 3) & 0xFF);
    convbuf->data[5] |= ((len & 0x07) << 5);

    GST_BUFFER_TIMESTAMP (convbuf) = GST_BUFFER_TIMESTAMP (buf);
    GST_BUFFER_FLAGS (convbuf) = GST_BUFFER_FLAGS (buf);
    gst_buffer_set_caps (convbuf, buf->caps);

    gst_buffer_unref (buf);
    buf = convbuf;
  }

end:
#if 0
  gst_util_dump_mem (GST_BUFFER_DATA (buf), GST_BUFFER_SIZE (buf));
#endif
  return buf;
}
static void
ismd_gst_audio_sink_class_init (ISmdGstAudioSinkClass * klass)
{
  ISmdGstElementClass *iclass = ISMD_GST_ELEMENT_CLASS (klass);
  GstElementClass *eclass = GST_ELEMENT_CLASS (klass);
  GObjectClass *oclass = G_OBJECT_CLASS (klass);

  oclass->get_property = ismd_gst_audio_sink_get_property;
  oclass->set_property = ismd_gst_audio_sink_set_property;

  g_object_class_install_property (oclass,
      PROP_AUDIO_GLOBAL_PROC,
      g_param_spec_boolean ("global-processor",
          "global processor",
          "Use the global audio procesor",
          DEFAULT_ISMD_AUDIO_SINK_GLOBAL_PROC, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_SYNC,
      g_param_spec_boolean ("sync",
          "Sync",
          "Sync on the clock",
          DEFAULT_ISMD_AUDIO_SINK_SYNC, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_LATENCY,
      g_param_spec_enum ("latency",
          "Latency",
          "Set Audio Latency Property - note: must be set before caps negotiation",
          GST_TYPE_ISMD_AUDIO_SINK_LATENCY,
          DEFAULT_ISMD_AUDIO_SINK_LATENCY, G_PARAM_WRITABLE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_OUT_HDMI,
      g_param_spec_enum ("audio-output-hdmi",
          "audio output hdmi mode",
          "Define the audio output hdmi mode",
          GST_TYPE_ISMD_AUDIO_SINK_OUT_MODE_COMPLEX,
          DEFAULT_ISMD_AUDIO_SINK_HDMI, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_OUT_SPDIF,
      g_param_spec_enum ("audio-output-spdif",
          "audio output spdif mode",
          "Define the audio output spdif mode",
          GST_TYPE_ISMD_AUDIO_SINK_OUT_MODE_COMPLEX,
          DEFAULT_ISMD_AUDIO_SINK_SPDIF, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_OUT_I2S0,
      g_param_spec_enum ("audio-output-i2s0",
          "audio output i2s0 mode",
          "Define the audio output i2s0 mode",
          GST_TYPE_ISMD_AUDIO_SINK_OUT_MODE_SIMPLE,
          DEFAULT_ISMD_AUDIO_SINK_I2S0, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_OUT_I2S1,
      g_param_spec_enum ("audio-output-i2s1",
          "audio output i2s1 mode",
          "Define the audio output i2s1 mode",
          GST_TYPE_ISMD_AUDIO_SINK_OUT_MODE_SIMPLE,
          DEFAULT_ISMD_AUDIO_SINK_I2S1, G_PARAM_READWRITE));

  g_object_class_install_property (oclass,
      PROP_AUDIO_OUT_DELAY,
      g_param_spec_int ("render-delay", "Render Delay",
          "Additional render delay of the sink in miliseconds", 0, 255,
          DEFAULT_ISMD_AUDIO_SINK_DELAY, G_PARAM_READWRITE));

  g_object_class_install_property (oclass, PROP_AUDIO_INPUT_GAIN,
      g_param_spec_double ("input-gain", "Input Gain",
          "Gain in dB applied on input signal before is mixed",
          MIN_INPUT_GAIN, MAX_INPUT_GAIN, DEFAULT_ISMD_AUDIO_SINK_INPUT_GAIN,
          G_PARAM_READWRITE | GST_PARAM_CONTROLLABLE));

  g_object_class_install_property (oclass, PROP_AUDIO_VOLUME,
      g_param_spec_double ("volume", "Volume", "volume factor",
          0.0, VOLUME_MAX_DOUBLE, DEFAULT_ISMD_AUDIO_SINK_VOLUME,
          G_PARAM_READWRITE | GST_PARAM_CONTROLLABLE));

  g_object_class_install_property (oclass, PROP_AUDIO_MUTE,
      g_param_spec_boolean ("mute", "Mute", "mute channel",
          DEFAULT_ISMD_AUDIO_SINK_MUTE,
          G_PARAM_READWRITE | GST_PARAM_CONTROLLABLE));

  oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_audio_sink_dispose);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_audio_sink_finalize);
  eclass->change_state = GST_DEBUG_FUNCPTR (ismd_gst_audio_sink_change_state);
  eclass->query = GST_DEBUG_FUNCPTR (ismd_gst_audio_sink_query);
  eclass->provide_clock =
      GST_DEBUG_FUNCPTR (ismd_gst_audio_sink_provide_clock);

  iclass->convert = ismd_gst_audio_sink_convert;
  iclass->event = ismd_gst_audio_sink_event;
  iclass->drain = ismd_gst_audio_sink_drain;
  iclass->is_decoder = TRUE;
  iclass->is_sink = TRUE;
  ismd_gst_element_requires_clock (eclass);
}

static void
ismd_gst_audio_sink_init (ISmdGstAudioSink * sink,
    ISmdGstAudioSinkClass * g_class)
{
  /* Create Sink Pad */
  GstPad *pad;
  ISmdGstElement *smd_element = ISMD_GST_ELEMENT (sink);
  GstPadTemplate *templ = get_sink_pad_template();
  smd_element->sink_pad = ismd_gst_pad_new_from_template (templ, "sink");
  gst_object_unref (templ);
  pad = GST_PAD (smd_element->sink_pad);
  gst_element_add_pad (GST_ELEMENT (smd_element), pad);
  /* Register sinkpad to allow the element to receive and process buffers */
  ismd_gst_element_register_sinkpad (smd_element, smd_element->sink_pad);
  /* Set up the pad capabilities */
  gst_pad_set_setcaps_function (pad,
      GST_DEBUG_FUNCPTR (ismd_gst_audio_sinkpad_setcaps));

  /* Initialize to invalid port id - to prevent buffer passing */
  (smd_element->sink_pad)->ismd_port = -1;
  sink->processor = ISMD_DEV_HANDLE_INVALID;
  sink->sync = DEFAULT_ISMD_AUDIO_SINK_SYNC;
  sink->latency = DEFAULT_ISMD_AUDIO_SINK_LATENCY;
  sink->use_global_proc = DEFAULT_ISMD_AUDIO_SINK_GLOBAL_PROC;
  sink->out_delay = DEFAULT_ISMD_AUDIO_SINK_DELAY;

  sink->input_gain = DEFAULT_ISMD_AUDIO_SINK_INPUT_GAIN;
  sink->current_input_gain = sink->input_gain;
  sink->volume = DEFAULT_ISMD_AUDIO_SINK_VOLUME;
  sink->current_volume = sink->volume;
  sink->mute = DEFAULT_ISMD_AUDIO_SINK_MUTE;
  sink->current_mute = sink->mute;

  sink->hdmi.ismd_port = GEN3_HW_OUTPUT_HDMI;
  sink->hdmi.out_mode = DEFAULT_ISMD_AUDIO_SINK_HDMI;
  sink->hdmi.output_handle = ISMD_DEV_HANDLE_INVALID;
  sink->hdmi.configured = FALSE;

  sink->spdif.ismd_port = GEN3_HW_OUTPUT_SPDIF;
  sink->spdif.out_mode = DEFAULT_ISMD_AUDIO_SINK_SPDIF;
  sink->spdif.output_handle = ISMD_DEV_HANDLE_INVALID;
  sink->spdif.configured = FALSE;

  sink->i2s0.ismd_port = GEN3_HW_OUTPUT_I2S0;
  sink->i2s0.out_mode = DEFAULT_ISMD_AUDIO_SINK_I2S0;
  sink->i2s0.output_handle = ISMD_DEV_HANDLE_INVALID;
  sink->i2s0.configured = FALSE;

  sink->i2s1.ismd_port = GEN3_HW_OUTPUT_I2S1;
  sink->i2s1.out_mode = DEFAULT_ISMD_AUDIO_SINK_I2S1;
  sink->i2s1.output_handle = ISMD_DEV_HANDLE_INVALID;
  sink->i2s1.configured = FALSE;

  sink->first_aac_packet = FALSE;
  sink->hdmi_pcm_max_channels = 0;
  sink->hdmi_pcm_max_samplerate = 0;
  sink->hdmi_pcm_max_samplesize = 0;
  sink->provided_clock = NULL;

  sink->monitor_loop = NULL;
  sink->monitor_mutex = g_new0 (GStaticRecMutex, 1);
  g_static_rec_mutex_init (sink->monitor_mutex);
  sink->bos_event = ISMD_EVENT_HANDLE_INVALID;
  sink->eos_event = ISMD_EVENT_HANDLE_INVALID;
  sink->clientid_event = ISMD_EVENT_HANDLE_INVALID;

  GST_OBJECT_FLAG_SET (GST_OBJECT (sink), GST_ELEMENT_IS_SINK);
}

