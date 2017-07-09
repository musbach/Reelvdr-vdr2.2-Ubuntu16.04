/* 
  This file is provided under a dual BSD/GPLv2 license.  When using or 
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 2007-2011  Intel Corporation. All rights reserved.

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

  Copyright(c) 2007-2011  Intel Corporation. All rights reserved.
  All rights reserved.

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



#ifndef __ALGO_THRESHOLD_MONITOR_H__
#define __ALGO_THRESHOLD_MONITOR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ismd_msg.h"
#include "sven_event_type.h"
#ifdef SELF_TEST
#include <stdio.h>
#endif
#include "osal.h"





/* ------------------------------------------------------------------ */
/* SOFTPLL Structs and Defines */
/* ------------------------------------------------------------------ */

#define SOFTPLL_PCR_FREQ                    90000
#define SOFTPLL_MAX_JITTER_CLOCKS           (SOFTPLL_PCR_FREQ/10)
#define SOFTPLL_DISCONTINUITY_THRESHHOLD    (1*SOFTPLL_PCR_FREQ)
#define SOFTPLL_UNITY_PPM                   1000000
#define SOFTPLL_MAX_PPM_BUMP                45
#define SOFTPLL_PPM_RANGE                   100

#define SOFTPLL_CORRECTION_THRESHHOLD       (SOFTPLL_PCR_FREQ/30)
#define SOFTPLL_CORRECTION_MIN_TIME         (SOFTPLL_PCR_FREQ*60)
#define SOFTPLL_CORRECTION_MAX_TIME         (SOFTPLL_PCR_FREQ*250)
          


#define CLOCK_SYNC_HANDLE_INVALID -1
#define SOFTPLL_TUPLE_GROUP_SIZE        64
#define SOFTPLL_JITTER_HISTORY_SIZE     4
  


/* the tuple is a combination of:
 *
 *  pcr - arriving with High Jitter
 *  stc - monotonically increasing
 *
*/
struct PCRTuple
{
    int pcr;
    int stc;
};

enum SoftPLL_State
{
    SOFTPLL_FreeRun,
    SOFTPLL_Setup,
    SOFTPLL_Acquiring,
    SOFTPLL_Tracking,
};

typedef struct 
{
    enum SoftPLL_State  state;
    int                 iterations_in_current_state;  /* how many analyses performed in this state? */

    int                 stc_dt;         /* constant DT (PCR-STC) while tracking */

    struct PCRTuple     start;          /* since start */
    int                 start_dpcr;     /* delta */
    int                 start_ppm;      /* clock freq at start */

    int                 last_dpcr;      /* delta */

    struct PCRTuple     correct;        /* since last correction */
    int                 correct_dpcr;   /* delta */
    int                 correct_ppm;    /* clock freq set at last correction */

    /* Set DDS Ra */
    void               (*set_dds_ppm)(void *userdata, int ppm );
    void                *ppm_userdata;
    int                 ppm_saturate;

    /* adaptive pid coefficients stored in case reset */
    int                 apid_pgain;
    int                 apid_igain;
    int                 apid_dgain;
    int                 apid_jgain;

    /* De-jitter */
    struct PCRTuple     prev_end;       /* ending position from last bucket */
    struct PCRTuple     minslope;       /* STC/PCR pair with minimum slope from END */
    unsigned int        minslope_age;   /* how many samples has this slope count been minimum */

    int                 in_tuple_min_dpcr;      /* minimum delta for this bucket */
    int                 in_tuple_average_dpcr;  /* average delta for this bucket */

    int                 in_tuple_pos;
    int                 in_tuple_bucket_size;   /* tuned by algorithm according to jitter */
    int                 in_tuple_max_jitter;    /* max jitter */
    struct PCRTuple     in_tuple[SOFTPLL_TUPLE_GROUP_SIZE];

    int                 jitter[SOFTPLL_JITTER_HISTORY_SIZE];   /* jitter history */

    /* PSI Information */
    int                 pmt_pid;
    int                 nit_pid;

    /* Flags */
    bool                error_untrackable; /* Flag is set when error is out of threshold and still increasing */  
    bool                clock_locked;

    unsigned int        min_clock_freq_range;      /* in PPM, 1,000,000 == unity */
    unsigned int        max_clock_freq_range;      /* in PPM, 1,000,000 == unity */

}SoftPLL;



void softpll_append_sample(SoftPLL  *spll,
                           int       pcr, 
                           int       stc);


void SMDEXPORT softpll_init(SoftPLL  *spll );

#ifdef __cplusplus
}
#endif

#endif
