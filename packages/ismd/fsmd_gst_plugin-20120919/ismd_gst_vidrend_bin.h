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

    Contat Information for Fluendo:
        FLUENDO S.A.
        World Trade Center Ed Norte 4 pl.
        Moll de Barcelona
        08039 BARCELONA - SPAIN

    BSD LICENSE

    Copyright(c) 2012. Intel Corporation. All rights reserved.
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
      - Neither the name of FLUENDO S.A. nor the names of its
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

#ifndef __ISMD_GST_VIDREND_BIN_H__
#define __ISMD_GST_VIDREND_BIN_H__

#include <gst/gst.h>

G_BEGIN_DECLS
#define ISMD_GST_TYPE_VIDREND_SINK 	(ismd_gst_vidrend_sink_get_type())

#define ISMD_GST_TYPE_VIDREND_BIN   (ismd_gst_vidrend_bin_get_type())
#define ISMD_GST_VIDREND_BIN(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj),\
                                            ISMD_GST_TYPE_VIDREND_BIN, ISmdGstVidrendBin))
#define ISMD_GST_VIDREND_BIN_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass),\
                                            ISMD_GST_TYPE_VIDREND_BIN, ISmdGstVidrendBinClass))
#define ISMD_GST_VIDREND_BIN_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj),\
                                            ISMD_GST_TYPE_VIDREND_BIN, ISmdGstVidrendBinClass))
#define ISMD_GST_IS_VIDREND_BIN(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj),\
                                          ISMD_GST_TYPE_VIDREND_BIN))
#define ISMD_GST_IS_VIDREND_BIN_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass),\
                                            ISMD_GST_TYPE_VIDREND_BIN))


typedef struct _ISmdGstVidrendBin ISmdGstVidrendBin;
typedef struct _ISmdGstVidrendBinClass ISmdGstVidrendBinClass;

struct _ISmdGstVidrendBin {
  GstBin      parent;

  GstElement  * refiller;
  GstElement  * vidpproc;
  GstElement  * vidrendsink;
  GstClockTime stream_time_offset;
  GValue rectangle;                  /* destination rectangle */
};

struct _ISmdGstVidrendBinClass {
  GstBinClass parent_class;
};

GType ismd_gst_vidrend_bin_get_type (void);

G_END_DECLS

#endif /* __ISMD_GST_VIDREND_BIN_H__ */

