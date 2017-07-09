/*
This file is provided under a dual BSD/GPLv2 license.  When using or
redistributing this file, you may do so under either license.

GPL LICENSE SUMMARY

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.

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

  BSD LICENSE 

  Copyright(c) 2007-2011 Intel Corporation. All rights reserved.
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
 *------------------------------------------------------------------------------
 */

#ifndef VIDDEC_HOST_WORKLOAD_MANAGER_H
#define VIDDEC_HOST_WORKLOAD_MANAGER_H

#ifdef VIDDEC_HAL_CE4200  /* VIDDEC_HAL_CE4200 */
#include "ces_fw_viddec_workload.h"
#else   /* VIDDEC_HAL_CE4100 */
#include "viddec_fw_workload.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------------ */
/* Driver (or host app) MUST PROVIDE storage for a workload manager per stream   */
/*------------------------------------------------------------------------------ */
#define WORKLOAD_MANAGER_MAX_REFERENCE_FRAMES   32

struct viddec_workload_manager
{
    struct viddec_frame_reference  frame[WORKLOAD_MANAGER_MAX_REFERENCE_FRAMES];
    void                          *host_context;
    bool                           wkld_mngr_init_done;
};

typedef struct
{
    unsigned int errors_in_ref_frames;
    unsigned int  missing_ref_frames;
}viddec_wkld_manager_error_info_t;
    
/*------------------------------------------------------------------------------ */
/* Driver (or host app) MUST PROVIDE THESE ROUTINES                              */
/*------------------------------------------------------------------------------ */
    extern int viddec_host_frame_inc_refcount(
        void                             *host_context,
        unsigned int                      frame_buf_id );
    
    extern int viddec_host_frame_dec_refcount(
        void                             *host_context,
        unsigned int                      frame_buf_id );
    
    extern int viddec_host_es_buffer_inc_refcount(
        void                             *host_context,
        unsigned int                      es_buf_id );
    
    extern int viddec_host_es_buffer_dec_refcount(
        void                             *host_context,
        unsigned int                      es_buf_id );
    
    extern void viddec_host_frame_set_error(
        void                             *host_context,
        unsigned int                      frame_buf_id ,
        unsigned int                      error);
    
    extern unsigned int viddec_host_frame_get_error(
        void                             *host_context,
        unsigned int                      frame_buf_id );
    
/*------------------------------------------------------------------------------ */
/* Exposed Functions from workload manager                                       */
/*------------------------------------------------------------------------------ */
    int viddec_workload_manager_init(
        struct viddec_workload_manager   *wm,
        void                             *host_context );
    
    int viddec_workload_manager_deinit(
        struct viddec_workload_manager   *wm );
    
    int viddec_workload_manager_flush_reference_table(
        struct viddec_workload_manager   *wm );
    
    int viddec_workload_manager_new_workload_from_parser(
        struct viddec_workload_manager   *wm,
        struct viddec_workload           *wl );
    
    int viddec_workload_manager_release_workload(
        struct viddec_workload_manager   *wm,
        struct viddec_workload           *wl );
    
#ifdef __cplusplus
}
#endif

#endif /* VIDDEC_HOST_WORKLOAD_MANAGER_H */
