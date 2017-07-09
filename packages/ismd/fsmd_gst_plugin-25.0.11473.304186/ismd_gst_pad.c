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
#include "ismd_gst_pad.h"

GST_BOILERPLATE (ISmdGstPad, ismd_gst_pad, GstPad, GST_TYPE_PAD);

static void ismd_gst_pad_finalize (GObject * object);
static void ismd_gst_pad_dispose (GObject * object);

static void
ismd_gst_pad_base_init (gpointer class)
{
}

static void
ismd_gst_pad_class_init (ISmdGstPadClass * class)
{
  //GstPadClass *pad_class = GST_PAD_CLASS(class);
  GObjectClass *oclass = G_OBJECT_CLASS (class);
  oclass->finalize = GST_DEBUG_FUNCPTR (ismd_gst_pad_finalize);
  oclass->dispose = GST_DEBUG_FUNCPTR (ismd_gst_pad_dispose);
}

static void
ismd_gst_pad_finalize (GObject * object)
{
  GST_CALL_PARENT (G_OBJECT_CLASS, finalize, (object));
}

static void
ismd_gst_pad_dispose (GObject * object)
{
  GST_CALL_PARENT (G_OBJECT_CLASS, dispose, (object));
}


static void
ismd_gst_pad_init (ISmdGstPad * pad, ISmdGstPadClass * class)
{
  pad->ismd_port = ISMD_PORT_HANDLE_INVALID;
  pad->is_event_queue_attached = FALSE;
  pad->last_ret = GST_FLOW_OK;
}

ISmdGstPad *
ismd_gst_pad_new_from_template (GstPadTemplate * pad_template, 
    const gchar * name)
{
  g_return_val_if_fail (GST_IS_PAD_TEMPLATE (pad_template), NULL);
  return g_object_new (ISMD_GST_TYPE_PAD, "name", name, "direction", 
      pad_template->direction, "template", pad_template, NULL);
}
