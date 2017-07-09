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



#ifndef __ALGO_ADAPTIVE_PID_H__
#define __ALGO_ADAPTIVE_PID_H__

#include "algo_threshold_monitor.h"

/* ------------------------------------------------------------------ */
/* AdaptivePID Structs and Defines */
/* ------------------------------------------------------------------ */

/** low pass filter averages heavy changes */
#define PID_PPM_LOPASS_MAX_SIZE   8

struct PIDControl
{
    int  term_diff;                    /* differential */
    int  term_int;                     /* integral */
    int  integral_max;                 /* max integral value */
    int  integral_min;                 /* max integral value i */
    int  pgain,igain,dgain,jgain;      /* fixed */
    int  ppm[PID_PPM_LOPASS_MAX_SIZE]; /* lowpass filter of adjustments */
};

typedef struct 
{
    SoftPLL             spll; /* SoftPLL MUST BE FIRST ITEM */
    /* PID Controller */
    struct PIDControl   pid;
}AdaptivePID;

// 2011-07-01: refresh
#define ADAPTIVE_PID_COEF_BITS         10          /* Bits of resolution in coefficients */
#define ADAPTIVE_PID_DEFAULT_P_GAIN    (int)(0.300781 * (float)(1<<10))   /* proportional gain (Proposed) */
#define ADAPTIVE_PID_DEFAULT_I_GAIN    (int)(0.000000 * (float)(1<<10))   /* integral gain (Proposed) */
#define ADAPTIVE_PID_DEFAULT_D_GAIN    (int)(1.743164 * (float)(1<<10))   /* differential gain (Proposed) */
#define ADAPTIVE_PID_DEFAULT_J_GAIN    (int)(0.025391 * (float)(1<<10))   /* integral gain (Proposed) */

void adaptive_pid_append_sample(AdaptivePID  *spll,
                           int       pcr, 
                           int       stc);


/** Initialize/Reset the adaptive P.I.D. controller algorithm
 */
void adaptive_pid_init(
    AdaptivePID      *apid,
    unsigned int      min_ppm,    /* highest tunable frequency where 1e6 == unity */
    unsigned int      max_ppm,    /* lowest tunable frequency where 1e6 == unity */
    int               pgain,      /* 10-bit fixed point */
    int               igain,      /* 10-bit fixed point */
    int               dgain,      /* 10 bit fixed point */
    int               jgain );    /* 10 bit fixed point */


void adaptive_pid_append_sample_v1(AdaptivePID  *spll,
                           int       pcr, 
                           int       stc);


void adaptive_pid_init_v1(AdaptivePID  *spll );

#endif /* __ALGO_ADAPTIVE_PID_H__ */
