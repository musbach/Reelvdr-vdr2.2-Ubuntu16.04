/*
    This file is provided under a dual BSD/LGPLv2.1 license.  When using
    or redistributing this file, you may do so under either license.

    LGPL LICENSE SUMMARY

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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gst/gst.h>
#include <gobject/gvaluecollector.h>

#include "ismd_gst_rectangle.h"

/*************
 * rectangle *
 *************/

typedef struct _priv_rect {
  guint x;
  guint y;
  guint w;
  guint h;
} priv_rect;

/* helper functions */
static void
gst_value_init_rectangle (GValue * value)
{
  value->data[0].v_pointer = g_slice_alloc0 (sizeof(priv_rect));
}

static void
gst_value_free_rectangle (GValue * value)
{
  priv_rect * priv = (priv_rect *) value->data[0].v_pointer;

  if (priv != NULL) {
    g_slice_free1 (sizeof (priv_rect), priv);
    value->data[0].v_pointer = NULL;
  }
}

static inline priv_rect *
clone_priv_rect (priv_rect * src)
{
  priv_rect * priv = g_slice_alloc0 (sizeof(priv_rect));
  memcpy (priv, src, sizeof(priv_rect));
  return priv;
}

static void
gst_value_copy_rectangle (const GValue * src_value, GValue * dest_value)
{
  priv_rect * dest_priv = (priv_rect *) dest_value->data[0].v_pointer;
  priv_rect * src_priv = (priv_rect *) src_value->data[0].v_pointer;

  if (dest_priv == NULL) {
    gst_value_init_rectangle (dest_value);
    dest_priv = (priv_rect *) dest_value->data[0].v_pointer;
  }

  if (src_priv != NULL)
    memcpy (dest_priv, src_priv, sizeof(priv_rect));
}

static gchar *
gst_value_collect_rectangle (GValue * value, guint n_collect_values,
    GTypeCValue * collect_values, guint collect_flags)
{
  priv_rect * priv = (priv_rect *) value->data[0].v_pointer;

  if (n_collect_values != 4)
    return g_strdup_printf ("not enough value locations for `%s' passed",
        G_VALUE_TYPE_NAME (value));

  if (priv == NULL) {
    gst_value_init_rectangle (value);
    priv = (priv_rect *) value->data[0].v_pointer;
  }

  priv->x = collect_values[0].v_int;
  priv->y = collect_values[1].v_int;
  priv->w = collect_values[2].v_int;
  priv->h = collect_values[3].v_int;

  return NULL;
}

static gchar *
gst_value_lcopy_rectangle (const GValue * value, guint n_collect_values,
    GTypeCValue * collect_values, guint collect_flags)
{
  int i;
  int *dest_values[4];
  priv_rect *priv = (priv_rect *) value->data[0].v_pointer;

  if (G_UNLIKELY (n_collect_values != 4))
    return g_strdup_printf ("not enough value locations for `%s' passed",
        G_VALUE_TYPE_NAME (value));

  for (i = 0; i < 4; i++) {
    if (G_UNLIKELY (collect_values[i].v_pointer == NULL)) {
      return g_strdup_printf ("value location for `%s' passed as NULL",
          G_VALUE_TYPE_NAME (value));
    }
    dest_values[i] = collect_values[i].v_pointer;
  }

  if (G_UNLIKELY (priv == NULL)) {
    return g_strdup_printf ("Uninitialised `%s' passed",
        G_VALUE_TYPE_NAME (value));
  }

  dest_values[0][0] = gst_value_get_rectangle_x (value);
  dest_values[1][0] = gst_value_get_rectangle_y (value);
  dest_values[2][0] = gst_value_get_rectangle_width (value);
  dest_values[3][0] = gst_value_get_rectangle_height (value);

  return NULL;
}

/**
 * gst_value_set_rectangle:
 * @value: a GValue initialized to #GST_TYPE_rectangle
 * @x: the x coordinate of the rectangle
 * @y: the y coordinate of the rectangle
 * @width: the width of the rectangle
 * @height: the height of the rectangle
 *
 * Sets @value to the rectangle.
 */
void
gst_value_set_rectangle (GValue * value, guint x, guint y,
    guint width, guint height)
{
  priv_rect *priv;
  g_return_if_fail (GST_VALUE_HOLDS_RECTANGLE (value));

  priv = (priv_rect *) value->data[0].v_pointer;
  if (priv == NULL) {
    gst_value_init_rectangle (value);
    priv = (priv_rect *) value->data[0].v_pointer;
  }

  priv->x = x;
  priv->y = y;
  priv->w = width;
  priv->h = height;
}

/**
 * gst_value_get_rectangle_x:
 * @value: a GValue initialized to #GST_TYPE_RECTANGLE
 *
 * Gets the x coordinate of the rectangle specified by @value.
 *
 * Returns: the x coordinate of the rectangle.
 */
guint
gst_value_get_rectangle_x (const GValue * value)
{
  priv_rect *priv;
  g_return_val_if_fail (GST_VALUE_HOLDS_RECTANGLE (value), 0);

  priv = (priv_rect *) value->data[0].v_pointer;
  return priv->x;
}

/**
 * gst_value_get_rectangle_y:
 * @value: a GValue initialized to #GST_TYPE_RECTANGLE
 *
 * Gets the y coordinate of the rectangle specified by @value.
 *
 * Returns: the y coordinate of the rectangle.
 */
guint
gst_value_get_rectangle_y (const GValue * value)
{
  priv_rect *priv;
  g_return_val_if_fail (GST_VALUE_HOLDS_RECTANGLE (value), 0);

  priv = (priv_rect *) value->data[0].v_pointer;
  return priv->y;
}

/**
 * gst_value_get_rectangle_width:
 * @value: a GValue initialized to #GST_TYPE_RECTANGLE
 *
 * Gets the width of the rectangle specified by @value.
 *
 * Returns: the width of the rectangle.
 */
guint
gst_value_get_rectangle_width (const GValue * value)
{
  priv_rect *priv;
  g_return_val_if_fail (GST_VALUE_HOLDS_RECTANGLE (value), 0);

  priv = (priv_rect *) value->data[0].v_pointer;
  return priv->w;
}

/**
 * gst_value_get_rectangle_height:
 * @value: a GValue initialized to #GST_TYPE_RECTANGLE
 *
 * Gets the height of the rectangle specified by @value.
 *
 * Returns: the width of the rectangle.
 */
guint
gst_value_get_rectangle_height (const GValue * value)
{
  priv_rect *priv;
  g_return_val_if_fail (GST_VALUE_HOLDS_RECTANGLE (value), 0);

  priv = (priv_rect *) value->data[0].v_pointer;
  return priv->h;
}

static gchar *
gst_value_serialize_rectangle (const GValue * value)
{
  priv_rect *priv = (priv_rect *) value->data[0].v_pointer;
  return g_strdup_printf ("%u,%u,%u,%u", priv->x, priv->y, priv->w, priv->h);
}

static gboolean
gst_value_deserialize_rectangle (GValue * dest, const gchar * s)
{
  guint x, y, w, h;

  if (G_UNLIKELY (s == NULL))
    return FALSE;

  if (G_UNLIKELY (dest == NULL || !GST_VALUE_HOLDS_RECTANGLE (dest)))
    return FALSE;

  if (sscanf (s, "%u,%u,%u,%u", &x, &y, &w, &h) == 4) {
    gst_value_set_rectangle (dest, x, y, w, h);
    return TRUE;
  }

  return FALSE;
}

static void
gst_value_transform_rectangle_string (const GValue * src_value,
    GValue * dest_value)
{
  dest_value->data[0].v_pointer = gst_value_serialize_rectangle (src_value);
}

static void
gst_value_transform_string_rectangle (const GValue * src_value,
    GValue * dest_value)
{
  if (!gst_value_deserialize_rectangle (dest_value,
          src_value->data[0].v_pointer))
    /* If the deserialize fails, ensure we leave the rectangle in a
     * valid, if incorrect, state */
    gst_value_set_rectangle (dest_value, 0, 0, 0, 0);
}

static const GTypeValueTable _gst_rectangle_value_table = {
  gst_value_init_rectangle,
  gst_value_free_rectangle,
  gst_value_copy_rectangle,
  NULL,
  "ii",
  gst_value_collect_rectangle,
  "pp",
  gst_value_lcopy_rectangle
};

static GTypeInfo _info = {
  0,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  0,
  0,
  NULL,
  NULL,
};

static GTypeFundamentalInfo _finfo = {
  0
};

#define FUNC_VALUE_GET_TYPE(type, name)                         \
GType gst_ ## type ## _get_type (void)                          \
{                                                               \
  static GType gst_ ## type ## _type = 0;                       \
                                                                \
  if (G_UNLIKELY (gst_ ## type ## _type == 0)) {		\
    _info.value_table = & _gst_ ## type ## _value_table;        \
    gst_ ## type ## _type = g_type_register_fundamental (       \
        g_type_fundamental_next (),                             \
        name, &_info, &_finfo, 0);                              \
  }                                                             \
                                                                \
  return gst_ ## type ## _type;                                 \
}

FUNC_VALUE_GET_TYPE (rectangle, "GstRectangle");

void
gst_value_rectangle_register (void)
{
  {
    static GstValueTable gst_value = {
      0,
      0,
      gst_value_serialize_rectangle,
      gst_value_deserialize_rectangle,
    };

    gst_value.type = gst_rectangle_get_type ();
    gst_value_register (&gst_value);

  }

  g_value_register_transform_func (GST_TYPE_RECTANGLE, G_TYPE_STRING,
      gst_value_transform_rectangle_string);
  g_value_register_transform_func (G_TYPE_STRING, GST_TYPE_RECTANGLE,
      gst_value_transform_string_rectangle);

}


