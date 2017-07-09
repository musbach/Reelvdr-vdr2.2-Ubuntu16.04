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

#ifndef __ISMD_GST_DEMUX_H__
#define __ISMD_GST_DEMUX_H__

#include "ismd_gst_element.h"
#include "ismd_demux.h"

enum
{
  FILTER_AUDIO = 0,
  FILTER_VIDEO,
  FILTER_MAX
};

typedef struct _ISmdGstDemuxClass ISmdGstDemuxClass;
typedef struct _ISmdGstDemux ISmdGstDemux;

struct _ISmdGstDemuxClass
{
  ISmdGstElementClass parent_class;
};

struct _ISmdGstDemux
{
  // base transform already creates a src and sink pad
  ISmdGstElement element;

  ismd_demux_filter_handle_t filter[FILTER_MAX];
  ismd_demux_input_stream_type_t stream_type;
};

GType ismd_gst_demux_get_type (void);

/* standard type-casting and type-checking boilerplate... */
#define ISMD_GST_TYPE_DEMUX      (ismd_gst_demux_get_type())
#define ISMD_GST_DEMUX(obj)      (G_TYPE_CHECK_INSTANCE_CAST\
                                       ((obj), ISMD_GST_TYPE_DEMUX, ISmdGstDemux))
#define ISMD_GST_DEMUX_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST\
                                            ((klass), ISMD_GST_TYPE_DEMUX, ISmdGstDemuxClass))
#define ISMD_GST_IS_DEMUX(obj)    (G_TYPE_CHECK_INSTANCE_TYPE((obj), ISMD_GST_TYPE_DEMUX))
#define ISMD_GST_IS_DEMUX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE\
                                        ((klass), ISMD_GST_TYPE_DEMUX))
#endif /* __ISMD_GST_DEMUX__ */
