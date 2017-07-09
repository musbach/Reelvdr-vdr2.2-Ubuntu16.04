/* 

  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify 
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but 
  WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  General Public License for more details.

  You should have received a copy of the GNU General Public License 
  along with this program; if not, write to the Free Software 
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution 
  in the file called LICENSE.GPL.

  Contact Information:
    Intel Corporation
    2200 Mission College Blvd.
    Santa Clara, CA  97052

  BSD LICENSE 

  Copyright(c) 2005-2008 Intel Corporation. All rights reserved.

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions 
  are met:

    * Redistributions of source code must retain the above copyright 
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in 
      the documentation and/or other materials provided with the 
      distribution.
    * Neither the name of Intel Corporation nor the names of its 
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

#ifndef OMARLIB_H
#define OMARLIB_H 1

struct WaveformSource;      /* black box struct declaration */

enum WaveSourceSampleShape
{
    WSSV_0,             /* ___ */

    WSSV_1,             /* --- */

    WSSV_0_to_1,        /* _-- */

    WSSV_1_to_0,        /* -__ */

    WSSV_hi_pulse,      /* _-_ */

    WSSV_lo_pulse,      /* -_- */

    WSSV_fast_pulse,    /* ### */

    WSSV_tick,          /* |__ */

    WSSV_ind,           /* ??? */

    WSSV_hi_and_lo,     /* === */

    WSSV_cross,         /* =x= */

    WSSV_tock,          /* || */

    WSSV_fast_lo,       /* #_ */

    WSSV_fast_hi,       /* #- */

    /* insert non-level shapes here */


    WSSV_payloadmatch_0  = 0x80,/* 6 bits of "payload match" */
    WSSV_payloadmatch_63 = 0xBf,/* 6 bits of "payload match" */

    WSSV_SampleShape_MAX,

    WSSV_level64_0   = 0xC0,/* draw a fill-level graph */
    WSSV_level64_MAX = 0xff,/*  */

    WSSV_MAX
};

typedef enum WavesourceExpandState
{
    Trace_NotExpandable,
        Trace_Expandable,
        Trace_Collapsible

}WavesourceExpandState, *pWavesourceExpandState;

enum WaveTraceLevelStyle
{
    WAVE_STYLE_LINE,        /* horizonal line at "level" */
//    WAVE_STYLE_DELTA,       /* center line (neutral color) and value is STYLE_LINE */
    WAVE_STYLE_BAR,         /* fill from bottom to "level" */
    WAVE_STYLE_THERMO,      /* fill full trace with varying colors (greeen->yellow->red) */
    WAVE_STYLE_MAX
};

struct WaveTraceInfo
{
    /* publicly visible information about a trace
     * just enough to render
     */
    const char              *label;
    int                      depth;       /* depth in the tree heirarchy */
    int                      level_style; /* affects how _level_ graphs are drawn (line, bar) */
};


WavesourceExpandState wavesource_Expandability(
    struct WaveformSource   *ws,
    unsigned int             sig );

int wavesource_GetNumTraces(
    struct WaveformSource   *ws );

/** Create a WaveSource */
struct WaveformSource *wavesource_Create(
    int                      unit,
    unsigned long            bar_pa,
    unsigned long            bar_size );

/** Delete a WaveSource */
void wavesource_Delete(
    struct WaveformSource   *ws );

int wavesource_PrepareFakeData(
    struct WaveformSource   *ws );


/** Set a wavesource property */
int wavesource_SetProperty(
    struct WaveformSource   *ws,
    const char              *property_name,
    int                      property_value );

/** Get a wavesource property */
int wavesource_GetProperty(
    struct WaveformSource   *ws,
    const char              *property_name,
    int                     *property_value );

/** How many different "traces" were captured (vertical) (usually 1024) */
int wavesource_GetNumSignals(
    struct WaveformSource   *ws );

/** What is the name of signal N */
const char *wavesource_GetSignalName(
    struct WaveformSource   *ws,
    int                     sig );
const char *wavesource_Get_HW_SignalName(
    struct WaveformSource   *ws,
    int                     sig );
int wavesource_GetNum_HW_Signals(
    struct WaveformSource   *ws );

unsigned long wavesource_Get_SvenlogFileSize(
    const char              *filename );

void wavesource_Resize_Local_Svenlog(
      struct WaveformSource   *ws,
      unsigned long            size );

int wavesource_Set_HW_SignalName(
    struct WaveformSource   *ws,
    int                      sig,
    const char              *signame );

/** Rename a signal, signame passed into this is not required to be permanent */
int wavesource_SetSignalName(
    struct WaveformSource   *ws,
    int                      sig,
    const char              *signame );

/** What is the name of the group this signal is in */
int wavesource_GetSignalGroup(
    struct WaveformSource   *ws,
    int                     sig );

/** What is the name of signal N */
const char *wavesource_GetGroupName(
    struct WaveformSource   *ws,
    int                     group );

/** How many times was each signal captured */
long long wavesource_GetDuration(
    struct WaveformSource   *ws );

int wavesource_ExpandSignal(
    struct WaveformSource   *ws,
    unsigned int             sig );

int wavesource_CollapseSignal(
    struct WaveformSource   *ws,
    unsigned int             sig );
/** Get the value of the waveform at time T */

enum WaveSourceSampleShape wavesource_GetSampleShape(
    struct WaveformSource   *ws,
    unsigned int             sig,
    int                      t0,
    int                      t1 );

enum WaveSourceSampleShape wavesource_GetOmarShape(
    struct WaveformSource   *ws,
    unsigned int             sig,
    int                      t0,
    int                      t1 );

const char *wavesource_GetTraceName(
    struct WaveformSource   *ws,
    int                     sig );

int wavesource_GetTraceInfo(
    struct WaveformSource   *ws,
    unsigned int             sig,
    struct WaveTraceInfo    *wti );

int wavesource_LoadTraces(
    struct WaveformSource   *ws,
    const char              *trace_config_path );

int wavesource_LoadConfigFile(
    struct WaveformSource   *ws,
    const char              *config_filename,
    const char              *trace_config_path );

int wavesource_LoadSvenlog(
    struct WaveformSource   *ws,
    const char              *svenlog_filename );

/** Get a text description  of the waveform at time T, primarily used by sven */
int wavesource_GetDescription(
   struct WaveformSource   *ws,
   char**                   ppDescription,
   unsigned int             trace_num,
   long long                t0,
   long long                t1 );

int wavesource_SelectReferenceEventAtTime(
  struct WaveformSource   *ws,
  unsigned int             trace_num,
  long long                t0,
  long long                t1 );

void wavesource_DetectBuses(struct WaveformSource   *ws);

void wavesource_FindMaxStringLength(struct WaveformSource   *ws,unsigned int* pMaxLength );

/* "Live-Wavesource" control APIs */
int wavesource_StartCapture(
    struct WaveformSource   *ws );

/* stop capture immediately */
int wavesource_StopCapture(
    struct WaveformSource   *ws );

int wavesource_SelfCalibrate(
    struct WaveformSource   *ws );

int wavesource_ParseConfig(
    struct WaveformSource   *ws,
    const char              *cfg,
    int                      cfg_size );

void wavesource_GetHiResClockFreq(
    struct WaveformSource   *ws,
    long long               *phclk );

void wavesource_GetHWClockDivider(
    struct WaveformSource   *ws,
    unsigned int             sig,
    unsigned int            *hclk_div );

/** How often to capture new signals (TODO: Rename this with _HW_ in name) */
int wavesource_SetCaptureInterval(
    struct WaveformSource   *ws,
    unsigned int             hclks );

unsigned int wavesource_GetCaptureInterval(
    struct WaveformSource   *ws );

/** Get the value of the waveform at time T */
int wavesource_GetShapes(
    struct WaveformSource   *ws,
    unsigned int             sig,
    long long                t0,            /* signed time in hclks */
    long long                t1,            /* signed time in hclks */
    unsigned char           *shapes,
    int                      shapes_len );  /* REQUIREMENT (t1-t0) * [1,2,3...] */


int wavesource_HW_CheckNewsamplesAvailable(
    struct WaveformSource   *ws,
    int                      pos );

int wavesource_HW_GetCurrentCapturePos(
    struct WaveformSource   *ws,
    int                     *ppos );

int wavesource_LoadBlackBoxRecording(
    struct WaveformSource   *ws,
    const char              *filename );

int wavesource_SaveBlackBoxRecording(
    struct WaveformSource   *ws,
    const char              *filename );

void wavesource_DumpOmarConfig(
     struct WaveformSource   *ws );

void wavesource_ParseOmarConfig(
     struct WaveformSource   *ws );

#endif /* OMARLIB_H */
