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

#ifndef __ISMD_GST_VC1_VIDDEC_H__
#define __ISMD_GST_VC1_VIDDEC_H__

#include <gst/gst.h>
#include "ismd_gst_element.h"
#include "ismd_global_defs.h"

typedef struct _ISmdGstVc1ViddecClass ISmdGstVc1ViddecClass;
typedef struct _ISmdGstVc1Viddec ISmdGstVc1Viddec;
typedef GstBuffer *(*convert_func) (ISmdGstVc1Viddec * smd_element,
    GstBuffer * buf, gboolean need_seq_hdr);

struct _ISmdGstVc1ViddecClass
{
  ISmdGstElementClass parent_class;
};

#define MAX_SIZE_PES_SEQUENCE_HEADER 16

struct _ISmdGstVc1Viddec
{
  ISmdGstElement element;
  ismd_codec_type_t vCodec;

  // size of the buffer is:
  // start code = 4
  // sequence header = 2 + 2 + 4 = 8 ==> ((8+3)/3)*4 == maximum 12 after encapsulation.
  guint8 SPMP_PESpacket_PayloadFormatHeader[MAX_SIZE_PES_SEQUENCE_HEADER];      // max size of a sequence header
  guint size_SPMP_PESpacket_PayloadFormatHeader;        // actual size
  gint flag;                    // boolean indicates if sequence header should be sent in next buffer
  convert_func convert_buffer;
  GstBuffer *AP_Buffer;
  gboolean drop_badframes;
};

GType ismd_gst_vc1_viddec_get_type (void);

/* standard type-casting and type-checking boilerplate... */
#define ISMD_GST_TYPE_VC1_VIDDEC          (ismd_gst_vc1_viddec_get_type())
#define ISMD_GST_VC1_VIDDEC(obj)          (G_TYPE_CHECK_INSTANCE_CAST((obj), \
						ISMD_GST_TYPE_VC1_VIDDEC, ISmdGstVc1Viddec))
#define ISMD_GST_VC1_VIDDEC_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass), \
						ISMD_GST_TYPE_VC1_VIDDEC, ISmdGstVc1ViddecClass))
#define ISMD_GST_IS_VC1_VIDDEC(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj), \
						ISMD_GST_TYPE_VC1_VIDDEC))
#define ISMD_GST_IS_VC1_VIDDEC_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass), \
						ISMD_GST_TYPE_VC1_VIDDEC))
#endif /* __ISMD_GST_VC1_VIDDEC_H__ */
