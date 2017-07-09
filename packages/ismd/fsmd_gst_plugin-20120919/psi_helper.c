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

#include "psi_helper.h"

////////////////////////////////////////////////////////////////////////////////
// Shortcut macros for accessing core platform configuration properties
////////////////////////////////////////////////////////////////////////////////

#define ISMD_MEMORY_INT_PROPERTY(name, ret) ({                                  \
   config_result_t icipret = CONFIG_SUCCESS;                                    \
   config_ref_t icip_attr_id = ROOT_NODE;                                       \
                                                                                \
   icipret = config_node_find(ROOT_NODE,                                        \
                              CONFIG_PATH_PLATFORM_MEMORY_LAYOUT,               \
                              &icip_attr_id);                                   \
   if (icipret == CONFIG_SUCCESS) {                                             \
      icipret = config_get_int(icip_attr_id, name, &ret);                       \
   }                                                                            \
                                                                                \
   if (icipret != CONFIG_SUCCESS) {                                             \
   }                                                                            \
   icipret;                                                                     \
})

#define PSI_BUFFER_SIZE_GET(ret) \
    ISMD_MEMORY_INT_PROPERTY("smd_buffers_DMX_PSI.buf_size", ret)

GST_DEBUG_CATEGORY_EXTERN (ismd_gst_psi_filter_debug);
#define GST_CAT_DEFAULT ismd_gst_psi_filter_debug

/* Returns pointer to the pmt_descriptor inside the PAT matching the progNum
 * or NULL */
pmt_descriptor *
psi_filter_find_prognum_in_pat (pat_data * pat, guint16 program_number)
{
  gint index;

  for (index = 0; index < pat->entries->len; index++) {
    pmt_descriptor *pmt_desc =
        &g_array_index (pat->entries, pmt_descriptor, index);
    if (pmt_desc->program_number == program_number) {
      return pmt_desc;
    }
  }
  return NULL;
}

/* Unmaps all currently tracked PMT PIDs from the filter. Returns TRUE on
 * success. */
static gboolean
psi_filter_remove_pmts (psi_filter * psif)
{
  ismd_result_t result;
  int index;

  if (psif->pat.valid) {
    for (index = 0; index < psif->pat.entries->len; index++) {
      pmt_descriptor *pmt =
          &g_array_index (psif->pat.entries, pmt_descriptor, index);
      if (pmt->filter_configured) {
        GST_LOG ("Removing PMT PID 0x%04x (prog %d)",
            pmt->pmt_pid, pmt->program_number);
        result = ismd_demux_filter_unmap_from_pid (psif->demux_handle,
            psif->filter_handle, pmt->pmt_pid);
        if (result != ISMD_SUCCESS) {
          GST_WARNING ("ismd_demux_filter_unmap_to_pids for PMT PID %d "
              "failed(%d)", pmt->pmt_pid, result);
          goto abort;
        }
        pmt->filter_configured = FALSE;
      }
    }

    g_hash_table_remove_all (psif->pmt_hash_table);
  }
  return TRUE;

abort:
  return FALSE;
}

/* Maps current PMT PIDs to the filter. Returns TRUE on success. */
gboolean
psi_filter_add_all_pmts (psi_filter * psif)
{
  ismd_result_t result;
  gint i;

  for (i = 0; i < psif->pat.entries->len; i++) {
    pmt_descriptor *pmt = &g_array_index (psif->pat.entries, pmt_descriptor, i);
    GST_DEBUG ("Adding PMT PID 0x%04x (prog %d)",
        pmt->pmt_pid, pmt->program_number);
    result = ismd_demux_filter_map_to_pid (psif->demux_handle,
        psif->filter_handle, pmt->pmt_pid, ISMD_DEMUX_PID_TYPE_PSI);
    if (result != ISMD_SUCCESS) {
      GST_WARNING ("ismd_demux_filter_map_to_pids for PMT PID %d failed(%d)",
          pmt->pmt_pid, result);
      goto abort;
    }
    pmt->filter_configured = TRUE;
  }
  return TRUE;

abort:
  return FALSE;
}

/* Maps specified service PMT PIDs to the filter. Returns TRUE on success. */
gboolean
psi_filter_add_pmt_for_service (psi_filter * psif, guint program)
{
  ismd_result_t result;
  gint i;
  gboolean ret = FALSE;

  g_mutex_lock (psif->mutex);

  for (i = 0; i < psif->pat.entries->len; i++) {
    pmt_descriptor *pmt = &g_array_index (psif->pat.entries, pmt_descriptor, i);
    if (pmt->program_number == program) {
      GST_DEBUG ("Adding PMT PID 0x%04x (prog %d)",
          pmt->pmt_pid, pmt->program_number);
      result = ismd_demux_filter_map_to_pid (psif->demux_handle,
          psif->filter_handle, pmt->pmt_pid, ISMD_DEMUX_PID_TYPE_PSI);
      if (result != ISMD_SUCCESS) {
        GST_WARNING ("ismd_demux_filter_map_to_pids for PMT PID %d failed(%d)",
            pmt->pmt_pid, result);
        goto beach;
      }
      ret = pmt->filter_configured = TRUE;
    }
  }

beach:
  g_mutex_unlock (psif->mutex);
  return ret;
}

static void
psi_filter_free_pmt_entries (GArray * entries)
{
  gint i;

  for (i = 0; i < entries->len; i++) {
    pmt_stream_data *cur_entry = &g_array_index (entries, pmt_stream_data, i);
    if (cur_entry->info_length > 0 && cur_entry->info != NULL) {
      gst_mpeg_descriptor_free (cur_entry->info);
    }
  }
  g_array_free (entries, TRUE);
}

static inline guint32
psi_filter_calc_crc32 (guint8 * data, guint datalen)
{
  gint i;
  guint32 crc = 0xffffffff;

  const guint32 crc_tab[256] = {
    0x00000000, 0x04c11db7, 0x09823b6e, 0x0d4326d9, 0x130476dc, 0x17c56b6b,
    0x1a864db2, 0x1e475005, 0x2608edb8, 0x22c9f00f, 0x2f8ad6d6, 0x2b4bcb61,
    0x350c9b64, 0x31cd86d3, 0x3c8ea00a, 0x384fbdbd, 0x4c11db70, 0x48d0c6c7,
    0x4593e01e, 0x4152fda9, 0x5f15adac, 0x5bd4b01b, 0x569796c2, 0x52568b75,
    0x6a1936c8, 0x6ed82b7f, 0x639b0da6, 0x675a1011, 0x791d4014, 0x7ddc5da3,
    0x709f7b7a, 0x745e66cd, 0x9823b6e0, 0x9ce2ab57, 0x91a18d8e, 0x95609039,
    0x8b27c03c, 0x8fe6dd8b, 0x82a5fb52, 0x8664e6e5, 0xbe2b5b58, 0xbaea46ef,
    0xb7a96036, 0xb3687d81, 0xad2f2d84, 0xa9ee3033, 0xa4ad16ea, 0xa06c0b5d,
    0xd4326d90, 0xd0f37027, 0xddb056fe, 0xd9714b49, 0xc7361b4c, 0xc3f706fb,
    0xceb42022, 0xca753d95, 0xf23a8028, 0xf6fb9d9f, 0xfbb8bb46, 0xff79a6f1,
    0xe13ef6f4, 0xe5ffeb43, 0xe8bccd9a, 0xec7dd02d, 0x34867077, 0x30476dc0,
    0x3d044b19, 0x39c556ae, 0x278206ab, 0x23431b1c, 0x2e003dc5, 0x2ac12072,
    0x128e9dcf, 0x164f8078, 0x1b0ca6a1, 0x1fcdbb16, 0x018aeb13, 0x054bf6a4,
    0x0808d07d, 0x0cc9cdca, 0x7897ab07, 0x7c56b6b0, 0x71159069, 0x75d48dde,
    0x6b93dddb, 0x6f52c06c, 0x6211e6b5, 0x66d0fb02, 0x5e9f46bf, 0x5a5e5b08,
    0x571d7dd1, 0x53dc6066, 0x4d9b3063, 0x495a2dd4, 0x44190b0d, 0x40d816ba,
    0xaca5c697, 0xa864db20, 0xa527fdf9, 0xa1e6e04e, 0xbfa1b04b, 0xbb60adfc,
    0xb6238b25, 0xb2e29692, 0x8aad2b2f, 0x8e6c3698, 0x832f1041, 0x87ee0df6,
    0x99a95df3, 0x9d684044, 0x902b669d, 0x94ea7b2a, 0xe0b41de7, 0xe4750050,
    0xe9362689, 0xedf73b3e, 0xf3b06b3b, 0xf771768c, 0xfa325055, 0xfef34de2,
    0xc6bcf05f, 0xc27dede8, 0xcf3ecb31, 0xcbffd686, 0xd5b88683, 0xd1799b34,
    0xdc3abded, 0xd8fba05a, 0x690ce0ee, 0x6dcdfd59, 0x608edb80, 0x644fc637,
    0x7a089632, 0x7ec98b85, 0x738aad5c, 0x774bb0eb, 0x4f040d56, 0x4bc510e1,
    0x46863638, 0x42472b8f, 0x5c007b8a, 0x58c1663d, 0x558240e4, 0x51435d53,
    0x251d3b9e, 0x21dc2629, 0x2c9f00f0, 0x285e1d47, 0x36194d42, 0x32d850f5,
    0x3f9b762c, 0x3b5a6b9b, 0x0315d626, 0x07d4cb91, 0x0a97ed48, 0x0e56f0ff,
    0x1011a0fa, 0x14d0bd4d, 0x19939b94, 0x1d528623, 0xf12f560e, 0xf5ee4bb9,
    0xf8ad6d60, 0xfc6c70d7, 0xe22b20d2, 0xe6ea3d65, 0xeba91bbc, 0xef68060b,
    0xd727bbb6, 0xd3e6a601, 0xdea580d8, 0xda649d6f, 0xc423cd6a, 0xc0e2d0dd,
    0xcda1f604, 0xc960ebb3, 0xbd3e8d7e, 0xb9ff90c9, 0xb4bcb610, 0xb07daba7,
    0xae3afba2, 0xaafbe615, 0xa7b8c0cc, 0xa379dd7b, 0x9b3660c6, 0x9ff77d71,
    0x92b45ba8, 0x9675461f, 0x8832161a, 0x8cf30bad, 0x81b02d74, 0x857130c3,
    0x5d8a9099, 0x594b8d2e, 0x5408abf7, 0x50c9b640, 0x4e8ee645, 0x4a4ffbf2,
    0x470cdd2b, 0x43cdc09c, 0x7b827d21, 0x7f436096, 0x7200464f, 0x76c15bf8,
    0x68860bfd, 0x6c47164a, 0x61043093, 0x65c52d24, 0x119b4be9, 0x155a565e,
    0x18197087, 0x1cd86d30, 0x029f3d35, 0x065e2082, 0x0b1d065b, 0x0fdc1bec,
    0x3793a651, 0x3352bbe6, 0x3e119d3f, 0x3ad08088, 0x2497d08d, 0x2056cd3a,
    0x2d15ebe3, 0x29d4f654, 0xc5a92679, 0xc1683bce, 0xcc2b1d17, 0xc8ea00a0,
    0xd6ad50a5, 0xd26c4d12, 0xdf2f6bcb, 0xdbee767c, 0xe3a1cbc1, 0xe760d676,
    0xea23f0af, 0xeee2ed18, 0xf0a5bd1d, 0xf464a0aa, 0xf9278673, 0xfde69bc4,
    0x89b8fd09, 0x8d79e0be, 0x803ac667, 0x84fbdbd0, 0x9abc8bd5, 0x9e7d9662,
    0x933eb0bb, 0x97ffad0c, 0xafb010b1, 0xab710d06, 0xa6322bdf, 0xa2f33668,
    0xbcb4666d, 0xb8757bda, 0xb5365d03, 0xb1f740b4
  };

  for (i = 0; i < datalen; i++) {
    crc = (crc << 8) ^ crc_tab[((crc >> 24) ^ *data++) & 0xff];
  }
  return crc;
}

/*
 * TS_program_map_section() {
 *   table_id                          8 uimsbf   == 0x02
 *   section_syntax_indicator          1 bslbf    == 1
 *   '0'                               1 bslbf    == 0
 *   reserved                          2 bslbf
 *   section_length                   12 uimsbf   == 00xxxxx...
 *   program_number                   16 uimsbf
 *   reserved                          2 bslbf
 *   version_number                    5 uimsbf
 *   current_next_indicator            1 bslbf
 *   section_number                    8 uimsbf
 *   last_section_number               8 uimsbf
 *   reserved                          3 bslbf
 *   PCR_PID                          13 uimsbf
 *   reserved                          4 bslbf
 *   program_info_length              12 uimsbf   == 00xxxxx...
 *   for (i=0; i<N; i++) {
 *     descriptor()
 *   }
 *   for (i=0;i<N1;i++) {
 *     stream_type                     8 uimsbf
 *     reserved                        3 bslbf
 *     elementary_PID                 13 uimsnf
 *     reserved                        4 bslbf
 *     ES_info_length                 12 uimsbf   == 00xxxxx...
 *     for (i=0; i<N2; i++) {
 *       descriptor()
 *     }
 *   }
 *   CRC_32                           32 rpchof
 * }
 */
static inline guint8
psi_filter_parse_pmt (psi_filter * psif, guint8 * data, guint datalen,
    gpointer * updated_structure, gboolean * version_changed)
{
  gint entries;
  guint32 CRC;
  pmt_data *pmt;
  pmt_descriptor *pmt_desc;
  guint version_number;
  guint8 current_next_indicator;
  guint16 program_number;
  guint8 ret = 0xFF;

  *version_changed = FALSE;

  if (*data++ != 0x02)
    goto wrong_id;
  if ((data[0] & 0xc0) != 0x80)
    goto wrong_sync;
  if ((data[0] & 0x0c) != 0x00)
    goto wrong_seclen;

  data += 2;

  if (psif->check_crc)
    if (psi_filter_calc_crc32 (data - 3, datalen) != 0)
      goto wrong_crc;

  GST_DEBUG ("PMT section_length: %d", datalen - 3);

  program_number = GST_READ_UINT16_BE (data);
  GST_DEBUG ("PMT program_number: %d", program_number);

  version_number = (data[2] & 0x3e) >> 1;
  GST_DEBUG ("PMT version_number: %d", version_number);

  current_next_indicator = (data[2] & 0x01);
  GST_DEBUG ("PMT current_next_indicator %d", current_next_indicator);
  if (current_next_indicator == 0)
    goto not_yet_applicable;

  pmt_desc = psi_filter_find_prognum_in_pat (&psif->pat, program_number);
  if (pmt_desc == NULL)
    goto wrong_program_number;

  pmt = g_hash_table_lookup (psif->pmt_hash_table,
      (gpointer) (gint) program_number);
  if (pmt == NULL) {
    /* This is the first time we receive a PMT with this progNum.
     * Create new PMT entry and add it to the table */
    pmt = g_malloc0 (sizeof (pmt_data));
    pmt->version_number = -1;
    g_hash_table_insert (psif->pmt_hash_table, (gpointer) (gint) program_number,
        pmt);
  } else {
    /* check if version number changed */
    if (version_number == pmt->version_number)
      goto same_version;
  }

  pmt->version_number = version_number;
  pmt->current_next_indicator = current_next_indicator;

  pmt->program_number = program_number;
  data += 3;

  pmt->section_number = *data++;
  GST_DEBUG ("PMT section_number: %d", pmt->section_number);

  pmt->last_section_number = *data++;
  GST_DEBUG ("PMT last_section_number: %d", pmt->last_section_number);

  pmt->pcr_pid = GST_READ_UINT16_BE (data);
  pmt->pcr_pid &= 0x1fff;
  data += 2;
  GST_DEBUG ("PMT PCR_PID: 0x%04x", pmt->pcr_pid);

  if ((data[0] & 0x0c) != 0x00)
    goto wrong_pilen;

  pmt->program_info_length = GST_READ_UINT16_BE (data);
  pmt->program_info_length &= 0x0fff;
  /* FIXME: validate value of program_info_length */
  data += 2;

  /* FIXME: validate value of program_info_length, before using */

  /* parse descriptor */
  if (G_UNLIKELY (pmt->program_info))
    gst_mpeg_descriptor_free (pmt->program_info);
  pmt->program_info =
      gst_mpeg_descriptor_parse (data, pmt->program_info_length);

  /* skip descriptor */
  data += pmt->program_info_length;
  GST_DEBUG ("PMT program_info_length: %d", pmt->program_info_length);

  entries = datalen - 3 - pmt->program_info_length - 9 - 4;

  if (pmt->entries) {
    psi_filter_free_pmt_entries (pmt->entries);
  }
  pmt->entries = g_array_new (FALSE, TRUE, sizeof (pmt_stream_data));

  while (entries > 0) {
    pmt_stream_data entry;

    entry.type = *data++;

    entry.pid = GST_READ_UINT16_BE (data);
    entry.pid &= 0x1fff;
    data += 2;

    if ((data[0] & 0x0c) != 0x00)
      goto wrong_esilen;

    entry.info_length = GST_READ_UINT16_BE (data);
    entry.info_length &= 0x0fff;
    data += 2;

    /* parse descriptor */
    entry.info = entry.info_length == 0 ? NULL :
        gst_mpeg_descriptor_parse (data, entry.info_length);

    /* skip descriptor */
    data += entry.info_length;
    GST_DEBUG ("  PMT stream_type: %02x, PID: 0x%04x (ES_info_len %d)",
        entry.type, entry.pid, entry.info_length);

    g_array_append_val (pmt->entries, entry);

    entries -= 5 + entry.info_length;
  }
  CRC = GST_READ_UINT32_BE (data);
  GST_DEBUG ("PMT CRC: 0x%08x", CRC);

  pmt->valid = TRUE;
  /* PMT has been updated, signal the change */
  *updated_structure = pmt;
  *version_changed = TRUE;
  return 0x02;                  /* Return TableID of PMT */

  /* ERRORS */
wrong_crc:
  {
    GST_DEBUG ("wrong crc");
    return ret;
  }
same_version:
  {
    GST_DEBUG ("same version as existing PMT");
    /* We have not updated our internal structures, but return that the PMT
     * is new anyway, so that it gets injected in the output stream. */
    *updated_structure = pmt;
    return 0x02;
  }
wrong_program_number:
  {
    GST_DEBUG ("PMT program number not found in PAT");
    return ret;
  }

not_yet_applicable:
  {
    GST_DEBUG ("Ignoring PMT with current_next_indicator = 0");
    return ret;
  }
wrong_id:
  {
    GST_DEBUG ("expected table_id == 2, got 0x%02x", data[0]);
    return ret;
  }
wrong_sync:
  {
    GST_DEBUG ("expected sync 10, got %02x", data[0]);
    return ret;
  }
wrong_seclen:
  {
    GST_DEBUG ("first two bits of section length must be 0, got %02x", data[0]);
    return ret;
  }
wrong_pilen:
  {
    GST_DEBUG ("first two bits of program_info length must be 0, got %02x",
        data[0]);
    return ret;
  }
wrong_esilen:
  {
    GST_DEBUG ("first two bits of ES_info length must be 0, got %02x", data[0]);
    psi_filter_free_pmt_entries (pmt->entries);
    pmt->entries = NULL;
    gst_mpeg_descriptor_free (pmt->program_info);
    pmt->program_info = NULL;
    return ret;
  }
}

/*
 * adaptation_field() {
 *   adaptation_field_length                              8 uimsbf
 *   if(adaptation_field_length >0) {
 *     discontinuity_indicator                            1 bslbf
 *     random_access_indicator                            1 bslbf
 *     elementary_stream_priority_indicator               1 bslbf
 *     PCR_flag                                           1 bslbf
 *     OPCR_flag                                          1 bslbf
 *     splicing_point_flag                                1 bslbf
 *     transport_private_data_flag                        1 bslbf
 *     adaptation_field_extension_flag                    1 bslbf
 *     if(PCR_flag == '1') {
 *       program_clock_reference_base                    33 uimsbf
 *       reserved                                         6 bslbf
 *       program_clock_reference_extension                9 uimsbf
 *     }
 *     if(OPCR_flag == '1') {
 *       original_program_clock_reference_base           33 uimsbf
 *       reserved                                         6 bslbf
 *       original_program_clock_reference_extension       9 uimsbf
 *     }
 *     if (splicing_point_flag == '1') {
 *       splice_countdown                                 8 tcimsbf
 *     }
 *     if(transport_private_data_flag == '1') {
 *       transport_private_data_length                    8 uimsbf
 *       for (i=0; i<transport_private_data_length;i++){
 *         private_data_byte                              8 bslbf
 *       }
 *     }
 *     if (adaptation_field_extension_flag == '1' ) {
 *       adaptation_field_extension_length                8 uimsbf
 *       ltw_flag                                         1 bslbf
 *       piecewise_rate_flag                              1 bslbf
 *       seamless_splice_flag                             1 bslbf
 *       reserved                                         5 bslbf
 *       if (ltw_flag == '1') {
 *         ltw_valid_flag                                 1 bslbf
 *         ltw_offset                                    15 uimsbf
 *       }
 *       if (piecewise_rate_flag == '1') {
 *         reserved                                       2 bslbf
 *         piecewise_rate                                22 uimsbf
 *       }
 *       if (seamless_splice_flag == '1'){
 *         splice_type                                    4 bslbf
 *         DTS_next_AU[32..30]                            3 bslbf
 *         marker_bit                                     1 bslbf
 *         DTS_next_AU[29..15]                           15 bslbf
 *         marker_bit                                     1 bslbf
 *         DTS_next_AU[14..0]                            15 bslbf
 *         marker_bit                                     1 bslbf
 *       }
 *       for ( i=0;i<N;i++) {
 *         reserved                                       8 bslbf
 *       }
 *     }
 *     for (i=0;i<N;i++){
 *       stuffing_byte                                    8 bslbf
 *     }
 *   }
 * }
 */
static inline gboolean
psi_filter_parse_adaptation_field (psi_filter * psif,
    const guint8 * data, guint data_len, guint * consumed)
{
  guint8 length;
  length = *data++;

  /* TODO: We might be interested in the information present here... */
  *consumed = length + 1;
  return TRUE;
}

/*
 * program_association_section() {
 *   table_id                               8 uimsbf   == 0x00
 *   section_syntax_indicator               1 bslbf    == 1
 *   '0'                                    1 bslbf    == 0
 *   reserved                               2 bslbf
 *   section_length                        12 uimsbf   == 00xxxxx...
 *   transport_stream_id                   16 uimsbf
 *   reserved                               2 bslbf
 *   version_number                         5 uimsbf
 *   current_next_indicator                 1 bslbf
 *   section_number                         8 uimsbf
 *   last_section_number                    8 uimsbf
 *   for (i=0; i<N;i++) {
 *     program_number                      16 uimsbf
 *     reserved                             3 bslbf
 *     if(program_number == '0') {
 *       network_PID                       13 uimsbf
 *     }
 *     else {
 *       program_map_PID                   13 uimsbf
 *     }
 *   }
 *   CRC_32                                32 rpchof
 * }
 */
static inline guint8
psi_filter_parse_pat (psi_filter * psif, guint8 * data, guint datalen,
    gboolean *version_changed)
{
  gint entries;
  guint32 CRC;
  guint version_number;
  guint8 current_next_indicator;
  pat_data *pat;
  guint8 ret = 0xFF;

  *version_changed = FALSE;

  if (datalen < 8)
    return ret;

  if (*data++ != 0x00)
    goto wrong_id;
  if ((data[0] & 0xc0) != 0x80)
    goto wrong_sync;
  if ((data[0] & 0x0c) != 0x00)
    goto wrong_seclen;

  data += 2;
  GST_DEBUG ("PAT section_length: %d", datalen - 3);

  if (psif->check_crc)
    if (psi_filter_calc_crc32 (data - 3, datalen) != 0)
      goto wrong_crc;

  pat = &psif->pat;

  version_number = (data[2] & 0x3e) >> 1;
  GST_DEBUG ("PAT version_number: %d", version_number);
  if (pat->valid && version_number == pat->version_number)
    goto same_version;

  current_next_indicator = (data[2] & 0x01);
  GST_DEBUG ("PAT current_next_indicator %d", current_next_indicator);
  if (current_next_indicator == 0)
    goto not_yet_applicable;

  GST_DEBUG ("PAT is going to be updated");
  psi_filter_remove_pmts (psif);

  pat->version_number = version_number;
  pat->current_next_indicator = current_next_indicator;

  pat->transport_stream_id = GST_READ_UINT16_BE (data);
  data += 3;
  GST_DEBUG ("PAT stream_id: %d", pat->transport_stream_id);

  pat->section_number = *data++;
  pat->last_section_number = *data++;

  GST_DEBUG ("PAT current_next_indicator: %d", pat->current_next_indicator);
  GST_DEBUG ("PAT section_number: %d", pat->section_number);
  GST_DEBUG ("PAT last_section_number: %d", pat->last_section_number);

  /* 5 bytes after section length and a 4 bytes CRC,
   * the rest is 4 byte entries */
  entries = (datalen - 3 - 9) / 4;

  if (pat->entries)
    g_array_free (pat->entries, TRUE);

  pat->entries =
      g_array_sized_new (FALSE, TRUE, sizeof (pmt_descriptor), entries);

  while (entries--) {
    pmt_descriptor entry;

    entry.program_number = GST_READ_UINT16_BE (data);
    data += 2;
    entry.pmt_pid = GST_READ_UINT16_BE (data);
    entry.pmt_pid &= 0x1fff;
    data += 2;

    if (entry.program_number != 0) {
      g_array_append_val (pat->entries, entry);
      GST_DEBUG ("  PAT program: %d, PID 0x%04x",
          entry.program_number, entry.pmt_pid);
    } else {
      /* We treat NIT in a special way */
      pat->nit_pid = entry.pmt_pid;
      pat->nit_pid_valid = TRUE;
      GST_DEBUG ("  NIT PID 0x%04x", entry.pmt_pid);
    }

  }
  CRC = GST_READ_UINT32_BE (data);
  GST_DEBUG ("PAT CRC: 0x%08x", CRC);

#if 0
  /* PAT has been updated, signal the change */
  if (psi_filter_add_pmts (psif) == FALSE) {
    GST_WARNING ("psi_filter_add_pmts failed");
    /* What else can we do here? */
  }
#endif
  pat->valid = TRUE;
  *version_changed = TRUE;
  return 0x00;                  /* Return TableID of PAT */

  /* ERRORS */
wrong_crc:
  {
    GST_DEBUG ("wrong crc");
    return ret;
  }
same_version:
  {
    GST_DEBUG ("same version as existing PAT");
    /* We have not updated our internal structures, but return that the PAT
     * is new anyway, so that it gets injected in the output stream. */
    return 0x00;
  }
not_yet_applicable:
  {
    GST_DEBUG ("Ignoring PAT with current_next_indicator = 0");
    return ret;
  }
wrong_id:
  {
    GST_DEBUG ("expected table_id == 0x00, got 0x%02x", data[0]);
    return ret;
  }
wrong_sync:
  {
    GST_DEBUG ("expected sync 10, got %02x", data[0]);
    return ret;
  }
wrong_seclen:
  {
    GST_DEBUG ("first two bits of section length must be 0, got %02x", data[0]);
    return ret;
  }
}

static inline guint8
psi_filter_parse_tdt (psi_filter * psif, guint8 * data, guint datalen,
    gpointer * updated_structure)
{
  guint16 mjd;
  guint8 *utc_ptr;
  guint8 ret = 0xFF;
  guint section_length;
  guint year;
  guint month;
  guint day;
  guint hour;
  guint minute;
  guint second;

  if (datalen < 8)
    return ret;

  if (*data++ != 0x70)
    goto wrong_id;

  section_length = GST_READ_UINT16_BE (data) & 0x0FFF;

  if (section_length > (datalen -3))
    goto wrong_seclen;

  data += 2;
  GST_DEBUG ("TDT section_length: %d", section_length);

  mjd = GST_READ_UINT16_BE (data);
  data += 2;

  utc_ptr = data;
  if (mjd == G_MAXUINT16) {
    year = 1900;
    month = day = hour = minute = second = 0;
  } else {
    /* See EN 300 468 Annex C */
    year = (guint32) (((mjd - 15078.2) / 365.25));
    month = (guint8) ((mjd - 14956.1 - (guint) (year * 365.25)) / 30.6001);
    day = mjd - 14956 - (guint) (year * 365.25) - (guint) (month * 30.6001);
    if (month == 14 || month == 15) {
      year++;
      month = month - 1 - 12;
    } else {
      month--;
    }
    year += 1900;
    hour = ((utc_ptr[0] & 0xF0) >> 4) * 10 + (utc_ptr[0] & 0x0F);
    minute = ((utc_ptr[1] & 0xF0) >> 4) * 10 + (utc_ptr[1] & 0x0F);
    second = ((utc_ptr[2] & 0xF0) >> 4) * 10 + (utc_ptr[2] & 0x0F);
  }
  *updated_structure = gst_structure_new ("tdt",
      "year", G_TYPE_UINT, year,
      "month", G_TYPE_UINT, month,
      "day", G_TYPE_UINT, day,
      "hour", G_TYPE_UINT, hour,
      "minute", G_TYPE_UINT, minute,
      "second", G_TYPE_UINT, second, NULL);
  return 0x70;

wrong_id:
  {
    GST_DEBUG ("expected table_id == 0x70, got 0x%02x", data[0]);
    return ret;
  }
wrong_seclen:
  {
    GST_DEBUG ("section lenght %d is greater that available data %d",
        section_length, datalen - 3);
    return ret;
  }
}

static gboolean
psi_filter_parse_descriptors (psi_filter * psif,
    guint8 ** buffer, guint8 * buffer_end, GValueArray * descriptors)
{
  guint8 tag, length;
  guint8 *data;
  GValue value = { 0 };
  GString *desc;

  data = *buffer;

  while (data < buffer_end) {
    tag = *data++;
    length = *data++;

    if (data + length > buffer_end) {
      GST_WARNING ("invalid descriptor length %d now at %d max %d",
          length, data - *buffer, buffer_end - *buffer);
      goto error;
    }

    /* include tag and length */
    desc = g_string_new_len ((gchar *) data - 2, length + 2);
    data += length;
    /* G_TYPE_GSTING is a GBoxed type and is used so properly marshalled from python */
    g_value_init (&value, G_TYPE_GSTRING);
    g_value_take_boxed (&value, desc);
    g_value_array_append (descriptors, &value);
    g_value_unset (&value);
  }

  if (data != buffer_end) {
    GST_WARNING ("descriptors size %d expected %d",
        data - *buffer, buffer_end - *buffer);
    goto error;
  }

  *buffer = data;

  return TRUE;
error:
  return FALSE;
}

static inline guint8
psi_filter_parse_eit (psi_filter * psif, guint8 * data, guint datalen,
    gpointer * updated_structure)
{
  guint8 ret = 0xff;
  GstStructure *eit = NULL, *event = NULL;
  guint service_id, last_table_id, segment_last_section_number;
  guint transport_stream_id, original_network_id;
  gboolean free_ca_mode;
  guint event_id, running_status;
  guint64 start_and_duration;
  guint16 mjd;
  guint year, month, day, hour, minute, second;
  guint duration;
  guint8 *duration_ptr, *utc_ptr;
  guint16 descriptors_loop_length;
  GValue events = { 0 };
  GValue event_value = { 0 };
  GValueArray *descriptors = NULL;
  gchar *event_name;
  guint tmp;
  guint section_length;
  guint table_id, version_number, current_next_indicator;
  guint8 * end;


  /* fixed header + CRC == 16 */
  if (datalen < 18) {
    GST_WARNING ("invalid EIT size %d", datalen);
    goto error;
  }

  end = data + datalen;
  table_id = *data++;
  section_length = GST_READ_UINT16_BE (data) & 0x0FFF;
  data += 2;

  if (section_length > (datalen -3))
    goto wrong_seclen;

  service_id = GST_READ_UINT16_BE (data);
  data += 2;

  tmp = *data++;
  version_number = (tmp >> 1) & 0x1F;
  current_next_indicator = tmp & 0x01;

  /* skip section_number and last_section_number */
  data += 2;

  transport_stream_id = GST_READ_UINT16_BE (data);
  data += 2;
  original_network_id = GST_READ_UINT16_BE (data);
  data += 2;
  segment_last_section_number = *data;
  data += 1;
  last_table_id = *data;
  data += 1;

  eit = gst_structure_new ("eit",
      "version-number", G_TYPE_UINT, version_number,
      "current-next-indicator", G_TYPE_UINT, current_next_indicator,
      "service-id", G_TYPE_UINT, service_id,
      "actual-transport-stream", G_TYPE_BOOLEAN, (table_id == 0x4E ||
          (table_id >= 0x50 && table_id <= 0x5F)),
      "present-following", G_TYPE_BOOLEAN, (table_id == 0x4E ||
          table_id == 0x4F),
      "transport-stream-id", G_TYPE_UINT, transport_stream_id,
      "original-network-id", G_TYPE_UINT, original_network_id,
      "segment-last-section-number", G_TYPE_UINT, segment_last_section_number,
      "last-table-id", G_TYPE_UINT, last_table_id, NULL);

  g_value_init (&events, GST_TYPE_LIST);
  while (data < end - 4) {
    /* 12 is the minimum entry size + CRC */
    if (end - data < 12 + 4) {
      GST_WARNING ("invalid EIT entry length %d", end - 4 - data);
      goto error;
    }

    event_id = GST_READ_UINT16_BE (data);
    data += 2;
    start_and_duration = GST_READ_UINT64_BE (data);
    duration_ptr = data + 5;
    utc_ptr = data + 2;
    mjd = GST_READ_UINT16_BE (data);
    if (mjd == G_MAXUINT16) {
      year = 1900;
      month = day = hour = minute = second = 0;
    } else {
      /* See EN 300 468 Annex C */
      year = (guint32) (((mjd - 15078.2) / 365.25));
      month = (guint8) ((mjd - 14956.1 - (guint) (year * 365.25)) / 30.6001);
      day = mjd - 14956 - (guint) (year * 365.25) - (guint) (month * 30.6001);
      if (month == 14 || month == 15) {
        year++;
        month = month - 1 - 12;
      } else {
        month--;
      }
      year += 1900;
      hour = ((utc_ptr[0] & 0xF0) >> 4) * 10 + (utc_ptr[0] & 0x0F);
      minute = ((utc_ptr[1] & 0xF0) >> 4) * 10 + (utc_ptr[1] & 0x0F);
      second = ((utc_ptr[2] & 0xF0) >> 4) * 10 + (utc_ptr[2] & 0x0F);
    }

    duration = (((duration_ptr[0] & 0xF0) >> 4) * 10 +
        (duration_ptr[0] & 0x0F)) * 60 * 60 +
        (((duration_ptr[1] & 0xF0) >> 4) * 10 +
        (duration_ptr[1] & 0x0F)) * 60 +
        ((duration_ptr[2] & 0xF0) >> 4) * 10 + (duration_ptr[2] & 0x0F);

    data += 8;
    running_status = *data >> 5;
    free_ca_mode = (*data >> 4) & 0x01;
    descriptors_loop_length = GST_READ_UINT16_BE (data) & 0x0FFF;
    data += 2;

    /* TODO: send tag event down relevant pad saying what is currently playing */
    event_name = g_strdup_printf ("event-%d", event_id);
    event = gst_structure_new (event_name,
        "event-id", G_TYPE_UINT, event_id,
        "year", G_TYPE_UINT, year,
        "month", G_TYPE_UINT, month,
        "day", G_TYPE_UINT, day,
        "hour", G_TYPE_UINT, hour,
        "minute", G_TYPE_UINT, minute,
        "second", G_TYPE_UINT, second,
        "duration", G_TYPE_UINT, duration,
        "running-status", G_TYPE_UINT, running_status,
        "free-ca-mode", G_TYPE_BOOLEAN, free_ca_mode, NULL);
    g_free (event_name);

    if (descriptors_loop_length) {
      guint8 *event_descriptor;
      GArray *component_descriptors;
      GArray *extended_event_descriptors;
      GstMPEGDescriptor *mpegdescriptor;

      if (data + descriptors_loop_length > end - 4) {
        GST_WARNING ("invalid EIT descriptors loop length %d",
            descriptors_loop_length);
        gst_structure_free (event);
        goto error;
      }
      mpegdescriptor =
          gst_mpeg_descriptor_parse (data, descriptors_loop_length);
      event_descriptor =
          gst_mpeg_descriptor_find (mpegdescriptor, DESC_DVB_SHORT_EVENT);
      if (event_descriptor != NULL) {
        GString *eventname_tmp, *eventdescription_tmp;
        guint8 eventname_length =
            DESC_DVB_SHORT_EVENT_name_length (event_descriptor);
        gchar *eventname =
            (gchar *) DESC_DVB_SHORT_EVENT_name_text (event_descriptor);
        guint8 eventdescription_length =
            DESC_DVB_SHORT_EVENT_description_length (event_descriptor);
        gchar *eventdescription =
            (gchar *) DESC_DVB_SHORT_EVENT_description_text (event_descriptor);
        if (eventname_length + eventdescription_length + 2 <=
            DESC_LENGTH (event_descriptor)) {

          eventname_tmp = g_string_new_len (eventname, eventname_length);
          eventdescription_tmp =
              g_string_new_len (eventdescription, eventdescription_length);

          gst_structure_set (event, "name", G_TYPE_GSTRING, eventname_tmp, NULL);
          gst_structure_set (event, "description", G_TYPE_GSTRING,
              eventdescription_tmp, NULL);
          g_string_free (eventname_tmp, TRUE);
          g_string_free (eventdescription_tmp, TRUE);
        }
      }

      extended_event_descriptors = gst_mpeg_descriptor_find_all (mpegdescriptor,
          DESC_DVB_EXTENDED_EVENT);
      if (extended_event_descriptors) {
        gint i;
        guint8 *ext_desc;
        GString *extended_text = NULL;

        for (i = 0; i < extended_event_descriptors->len; i++) {
          ext_desc = g_array_index (extended_event_descriptors, guint8 *, i);
          if (DESC_DVB_EXTENDED_EVENT_descriptor_number (ext_desc) == i) {
            if (!extended_text) {
              extended_text = g_string_new_len (
                  (gchar *) DESC_DVB_EXTENDED_EVENT_text (ext_desc),
                  DESC_DVB_EXTENDED_EVENT_text_length (ext_desc));
            } else {
              extended_text = g_string_append_len (extended_text,
                  (gchar *) DESC_DVB_EXTENDED_EVENT_text (ext_desc),
                  DESC_DVB_EXTENDED_EVENT_text_length (ext_desc));
            }
          }
        }
        if (extended_text) {
          gst_structure_set (event, "extended-text", G_TYPE_GSTRING,
              extended_text, NULL);
          g_string_free (extended_text, TRUE);
        }

        g_array_free (extended_event_descriptors, TRUE);
      }
      component_descriptors = gst_mpeg_descriptor_find_all (mpegdescriptor,
          DESC_DVB_COMPONENT);
      if (component_descriptors) {
        int i;
        guint8 *comp_descriptor;
        GValue components = { 0 };
        g_value_init (&components, GST_TYPE_LIST);
        /* FIXME: do the component descriptor parsing less verbosely
         * and better...a task for 0.10.6 */
        for (i = 0; i < component_descriptors->len; i++) {
          GstStructure *component = NULL;
          GValue component_value = { 0 };
          gint widescreen = 0;  /* 0 for 4:3, 1 for 16:9, 2 for > 16:9 */
          gint freq = 25;       /* 25 or 30 measured in Hertz */
          gboolean highdef = FALSE;
          gboolean panvectors = FALSE;
          gchar *comptype = "";

          comp_descriptor = g_array_index (component_descriptors, guint8 *, i);
          switch (DESC_DVB_COMPONENT_stream_content (comp_descriptor)) {
            case 0x01:
              /* video */
              switch (DESC_DVB_COMPONENT_type (comp_descriptor)) {
                case 0x01:
                  widescreen = 0;
                  freq = 25;
                  break;
                case 0x02:
                  widescreen = 1;
                  panvectors = TRUE;
                  freq = 25;
                  break;
                case 0x03:
                  widescreen = 1;
                  panvectors = FALSE;
                  freq = 25;
                  break;
                case 0x04:
                  widescreen = 2;
                  freq = 25;
                  break;
                case 0x05:
                  widescreen = 0;
                  freq = 30;
                  break;
                case 0x06:
                  widescreen = 1;
                  panvectors = TRUE;
                  freq = 30;
                  break;
                case 0x07:
                  widescreen = 1;
                  panvectors = FALSE;
                  freq = 30;
                  break;
                case 0x08:
                  widescreen = 2;
                  freq = 30;
                  break;
                case 0x09:
                  widescreen = 0;
                  highdef = TRUE;
                  freq = 25;
                  break;
                case 0x0A:
                  widescreen = 1;
                  highdef = TRUE;
                  panvectors = TRUE;
                  freq = 25;
                  break;
                case 0x0B:
                  widescreen = 1;
                  highdef = TRUE;
                  panvectors = FALSE;
                  freq = 25;
                  break;
                case 0x0C:
                  widescreen = 2;
                  highdef = TRUE;
                  freq = 25;
                  break;
                case 0x0D:
                  widescreen = 0;
                  highdef = TRUE;
                  freq = 30;
                  break;
                case 0x0E:
                  widescreen = 1;
                  highdef = TRUE;
                  panvectors = TRUE;
                  freq = 30;
                  break;
                case 0x0F:
                  widescreen = 1;
                  highdef = TRUE;
                  panvectors = FALSE;
                  freq = 30;
                  break;
                case 0x10:
                  widescreen = 2;
                  highdef = TRUE;
                  freq = 30;
                  break;
              }
              component = gst_structure_new ("video", "high-definition",
                  G_TYPE_BOOLEAN, TRUE, "frequency", G_TYPE_INT, freq,
                  "tag", G_TYPE_INT, DESC_DVB_COMPONENT_tag (comp_descriptor),
                  NULL);
              if (widescreen == 0) {
                gst_structure_set (component, "aspect-ratio",
                    G_TYPE_STRING, "4:3", NULL);
              } else if (widescreen == 2) {
                gst_structure_set (component, "aspect-ratio", G_TYPE_STRING,
                    "> 16:9", NULL);
              } else {
                gst_structure_set (component, "aspect-ratio", G_TYPE_STRING,
                    "16:9", "pan-vectors", G_TYPE_BOOLEAN, panvectors, NULL);
              }
              break;
            case 0x02:         /* audio */
              comptype = "undefined";
              switch (DESC_DVB_COMPONENT_type (comp_descriptor)) {
                case 0x01:
                  comptype = "single channel mono";
                  break;
                case 0x02:
                  comptype = "dual channel mono";
                  break;
                case 0x03:
                  comptype = "stereo";
                  break;
                case 0x04:
                  comptype = "multi-channel multi-lingual";
                  break;
                case 0x05:
                  comptype = "surround";
                  break;
                case 0x40:
                  comptype = "audio description for the visually impaired";
                  break;
                case 0x41:
                  comptype = "audio for the hard of hearing";
                  break;
              }
              component = gst_structure_new ("audio", "type", G_TYPE_STRING,
                  comptype, "tag", G_TYPE_INT,
                  DESC_DVB_COMPONENT_tag (comp_descriptor), NULL);
              break;
            case 0x03:         /* subtitles/teletext/vbi */
              comptype = "reserved";
              switch (DESC_DVB_COMPONENT_type (comp_descriptor)) {
                case 0x01:
                  comptype = "EBU Teletext subtitles";
                  break;
                case 0x02:
                  comptype = "associated EBU Teletext";
                  break;
                case 0x03:
                  comptype = "VBI data";
                  break;
                case 0x10:
                  comptype = "Normal DVB subtitles";
                  break;
                case 0x11:
                  comptype = "Normal DVB subtitles for 4:3";
                  break;
                case 0x12:
                  comptype = "Normal DVB subtitles for 16:9";
                  break;
                case 0x13:
                  comptype = "Normal DVB subtitles for 2.21:1";
                  break;
                case 0x20:
                  comptype = "Hard of hearing DVB subtitles";
                  break;
                case 0x21:
                  comptype = "Hard of hearing DVB subtitles for 4:3";
                  break;
                case 0x22:
                  comptype = "Hard of hearing DVB subtitles for 16:9";
                  break;
                case 0x23:
                  comptype = "Hard of hearing DVB subtitles for 2.21:1";
                  break;
              }
              component = gst_structure_new ("teletext", "type", G_TYPE_STRING,
                  comptype, "tag", G_TYPE_INT,
                  DESC_DVB_COMPONENT_tag (comp_descriptor), NULL);
              break;
          }
          if (component) {
            g_value_init (&component_value, GST_TYPE_STRUCTURE);
            g_value_take_boxed (&component_value, component);
            gst_value_list_append_value (&components, &component_value);
            g_value_unset (&component_value);
            component = NULL;
          }
        }
        gst_structure_set_value (event, "components", &components);
        g_value_unset (&components);
        g_array_free (component_descriptors, TRUE);
      }
      gst_mpeg_descriptor_free (mpegdescriptor);

      descriptors = g_value_array_new (0);
      if (!psi_filter_parse_descriptors (psif,
              &data, data + descriptors_loop_length, descriptors)) {
        gst_structure_free (event);
        g_value_array_free (descriptors);
        goto error;
      }
      gst_structure_set (event, "descriptors", G_TYPE_VALUE_ARRAY, descriptors,
          NULL);
      g_value_array_free (descriptors);
    }

    g_value_init (&event_value, GST_TYPE_STRUCTURE);
    g_value_take_boxed (&event_value, event);
    gst_value_list_append_value (&events, &event_value);
    g_value_unset (&event_value);
  }

  if (data != end - 4) {
    goto error;
  }

  gst_structure_set_value (eit, "events", &events);
  g_value_unset (&events);
  GST_DEBUG ("%02x EIT %" GST_PTR_FORMAT, ret, eit);
  *updated_structure = eit;
  ret = table_id;
  return ret;

error:
  {
    if (eit)
      gst_structure_free (eit);

    if (GST_VALUE_HOLDS_LIST (&events))
      g_value_unset (&events);

    return ret;
  }
wrong_seclen:
  {
    GST_DEBUG ("section lenght %d is greater that available data %d",
        section_length, datalen - 3);
    return ret;
  }
}

/*
 * transport_packet(){
 *   sync_byte                                                               8 bslbf == 0x47
 *   transport_error_indicator                                               1 bslbf
 *   payload_unit_start_indicator                                            1 bslbf
 *   transport _priority                                                     1 bslbf
 *   PID                                                                    13 uimsbf
 *   transport_scrambling_control                                            2 bslbf
 *   adaptation_field_control                                                2 bslbf
 *   continuity_counter                                                      4 uimsbf
 *   if(adaptation_field_control=='10' || adaptation_field_control=='11'){
 *     adaptation_field()
 *   }
 *   if(adaptation_field_control=='01' || adaptation_field_control=='11') {
 *     for (i=0;i<N;i++){
 *       data_byte                                                           8 bslbf
 *     }
 *   }
 * }
 */
/* Returns the table ID of the received packet if parsed ok, 0xFF otherwise.
 * updated_structure points to the parsed structure.
 * version_changed indicates whether the structure is different from the
 * previous received version */
static inline guint8
psi_filter_parse_TS_packet (psi_filter * psif, GstBuffer * buffer,
    gpointer * updated_structure, GstBuffer ** raw_section,
    gboolean *version_changed)
{
  gboolean transport_error_indicator;
  gboolean payload_unit_start_indicator;
  gboolean transport_priority;
  guint16 PID;
  guint8 transport_scrambling_control;
  guint8 adaptation_field_control;
  guint8 continuity_counter;
  const guint8 *data = GST_BUFFER_DATA (buffer) + 1;
  guint datalen = GST_BUFFER_SIZE (buffer) - 1;
  GstSectionFilter *section_filter;
  guint8 ret = 0xFF;
  *raw_section = NULL;
  transport_error_indicator = (data[0] & 0x80) == 0x80;
  payload_unit_start_indicator = (data[0] & 0x40) == 0x40;
  transport_priority = (data[0] & 0x20) == 0x20;
  PID = ((data[0] & 0x1f) << 8) | data[1];
  transport_scrambling_control = (data[2] & 0xc0) >> 6;
  adaptation_field_control = (data[2] & 0x30) >> 4;
  continuity_counter = data[2] & 0x0f;
  *version_changed = FALSE;

  data += 3;
  datalen -= 3;

  GST_LOG ("afc 0x%x, pusi %d, PID 0x%04x datalen %u",
      adaptation_field_control, payload_unit_start_indicator, PID, datalen);

  /* packets with adaptation_field_control == 0 must be skipped */
  if (adaptation_field_control == 0) {
    GST_DEBUG ("skipping, adaptation_field_control == 0");
    return ret;
  }

  /* parse adaption field if any */
  if (adaptation_field_control & 0x2) {
    guint consumed;

    if (!psi_filter_parse_adaptation_field (psif, data, datalen, &consumed))
      return ret;

    if (datalen <= consumed) {
      GST_DEBUG ("skipping, adaptation_field consumed all data");
      return ret;
    }

    data += consumed;
    datalen -= consumed;
    GST_LOG ("consumed: %u datalen: %u", consumed, datalen);
  }

  /* If this packet has a payload, handle it.
   * We only expect PSI packets here, since these are the only PIDs that
   * we allowed */
  if (adaptation_field_control & 0x1) {
    GstBuffer *sec_buf;
    guint8 *section_data;
    guint16 section_length;
    guint8 pointer;

    GST_LOG ("Packet payload %d bytes, PID 0x%04x", datalen, PID);

    /* do stuff with our section */
    if (payload_unit_start_indicator) {
      pointer = *data++;
      datalen -= 1;
      if (pointer >= datalen) {
        GST_DEBUG ("pointer: 0x%02x too large", pointer);
        return ret;
      }
      data += pointer;
      datalen -= pointer;
    }

    /* Search the proper section filter in our hash table */
    section_filter = g_hash_table_lookup (psif->section_filter_hash_table,
        (gpointer) (gint) PID);
    if (section_filter == NULL) {
      /* We received a PID which we had never seen before. Create a
       * section_filter for it and add it to the hash table of PIDs */
      section_filter = g_try_malloc0 (sizeof (GstSectionFilter));
      if (section_filter == NULL) {
        GST_WARNING ("g_try_malloc0 failed");
        return ret;
      }
      gst_section_filter_init (section_filter);
      g_hash_table_insert (psif->section_filter_hash_table,
          (gpointer) (gint) PID, section_filter);
    }
    /* Create a subbuffer with the PSI data payload */
    sec_buf = gst_buffer_create_sub (buffer, data - GST_BUFFER_DATA (buffer),
        datalen);
    /* Push the subbuffer into the section filter */
    if (gst_section_filter_push (section_filter, payload_unit_start_indicator,
          continuity_counter, sec_buf, buffer)) {
      GST_DEBUG ("section finished");
      /* section ready */
      section_length = section_filter->section_length;
      section_data =
          (guint8 *) gst_adapter_peek (section_filter->adapter,
          section_length + 3);

      switch (section_data[0]) {
        case 0x00:             /* PAT */
          ret = psi_filter_parse_pat (psif, section_data, section_length + 3,
              version_changed);
          break;
        case 0x01:             /* CAT */
/*          psi_filter_parse_cat (psif, section_data, section_length + 3); */
          break;
        case 0x02:             /* PMT */
          ret = psi_filter_parse_pmt (psif, section_data, section_length + 3,
              updated_structure, version_changed);
          break;
        case 0x06:             /* Metadata */
/*          gst_fluts_stream_parse_private_section (stream, section_data,
              section_length + 3);*/
          break;
        case 0x4E:
        case 0x4F:
          /* EIT, present/following */
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x5F:
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6A:
        case 0x6B:
        case 0x6C:
        case 0x6D:
        case 0x6E:
        case 0x6F:
          /* EIT, schedule */
          ret = psi_filter_parse_eit (psif, section_data, section_length + 3,
              updated_structure);
          break;
        case 0x70:
          ret = psi_filter_parse_tdt (psif, section_data, section_length + 3,
              updated_structure);
          break;
      }
      if (ret == 0x00 || ret == 0x02) {
        GST_DEBUG ("Take the whole section to be injected");
        *raw_section = gst_section_filter_take_raw (section_filter);
      }

      gst_section_filter_clear (section_filter);

    } else {
      /* section still going, don't parse yet */
      GST_DEBUG ("section still going for PID 0x%04x", PID);
    }
  }
  return ret;
}

/* Monitoring thread's main loop. Sits on a wait until an event wakes it up.
 * Then reads all available buffers and parses them, until signalled to quit.
 */
static gpointer
psi_filter_event_loop (gpointer user_data)
{
  psi_filter *psif = (psi_filter *) user_data;
  ismd_result_t result;
  ismd_buffer_handle_t buf = ISMD_BUFFER_HANDLE_INVALID;
  gboolean need_wait = TRUE;
  ismd_port_status_t ps;
  gboolean ack = FALSE;

  g_mutex_lock (psif->mutex);

  while (psif->event_loop_running) {
    if (ack) {
      if ((result = ismd_event_acknowledge (psif->port_event)) != ISMD_SUCCESS) {
        GST_WARNING ("ismd_event_acknowledge failed(%d)", result);
      }
      ack = FALSE;
    }

    if (need_wait) {
      /* Wait forever for buffers to arrive. Either arriving buffers or a signal
       * from the main thread will wake us up. Unlock mutex while we sleep */
      GST_LOG ("Going to sleep");
      g_mutex_unlock (psif->mutex);
      result = ismd_event_wait (psif->port_event, ISMD_TIMEOUT_NONE);
      g_mutex_lock (psif->mutex);
      GST_LOG ("Woke up, status: %d", result);

      /* Get some statistics on the output port queue */
      ismd_port_get_status (psif->filter_output_port_handle, &ps);
      GST_LOG ("Port status: MD=%d CD=%d WM=%d",
          ps.max_depth, ps.cur_depth, ps.watermark);

      if (result == ISMD_SUCCESS) {
        ack = TRUE;
      }
      else if (result == ISMD_ERROR_TIMEOUT) {
        continue;
      }      
      else if (result == ISMD_ERROR_NOT_DONE) {
        continue;
      }
      else if (result != ISMD_SUCCESS) {
        GST_WARNING ("ismd_event_wait failed (%d)", result);
        continue;
      }
    }

    need_wait = TRUE;

    /* Check for shutdown condition before moving on, since we might have
     * received order to close while we were sleeping. */
    if (psif->event_loop_running) {
      result = ismd_port_read (psif->filter_output_port_handle, &buf);
      if (result == ISMD_SUCCESS) {
        GstBuffer *buffer = NULL;
        ismd_buffer_descriptor_t buffer_descriptor;
        need_wait = FALSE;

        result = ismd_buffer_read_desc (buf, &buffer_descriptor);
        if (result == ISMD_SUCCESS && buffer_descriptor.phys.level > 0) {
          size_t buffer_size;
          guint8 *mapped_data_pointer;
          buffer_size = buffer_descriptor.phys.level;
          mapped_data_pointer =
              ISMD_BUFFER_MAP_BY_TYPE(buffer_descriptor.buffer_type,
                  buffer_descriptor.phys.base, buffer_size);

          if (mapped_data_pointer != NULL) {
            if (psif->remnant_buffer != NULL) {
              size_t rem_size = GST_BUFFER_SIZE (psif->remnant_buffer);
              buffer = gst_buffer_new_and_alloc (rem_size + buffer_size);
              memcpy (GST_BUFFER_DATA (buffer),
                  GST_BUFFER_DATA (psif->remnant_buffer), rem_size);
              memcpy (GST_BUFFER_DATA (buffer) + rem_size, mapped_data_pointer,
                  buffer_size);
              gst_buffer_unref (psif->remnant_buffer);
              psif->remnant_buffer = NULL;
              GST_DEBUG ("Received %d bytes (plus %d of remnant)",
                  buffer_size, rem_size);
            } else {
              buffer = gst_buffer_new_and_alloc (buffer_size);
              memcpy (GST_BUFFER_DATA (buffer), mapped_data_pointer,
                  buffer_size);
              GST_DEBUG ("Received %d bytes", buffer_size);
            }

            GST_MEMDUMP ("Received ISMD buffer:",
                GST_BUFFER_DATA (buffer), GST_BUFFER_SIZE (buffer));
            OS_UNMAP_IO_FROM_MEM (mapped_data_pointer, buffer_size);
          } else {
            GST_WARNING ("memory mapping failed");
          }
        }
        result = ismd_buffer_dereference (buf);
        if (result != ISMD_SUCCESS) {
          GST_WARNING ("ismd_buffer_dereference failed(%d)", result);
        }


        if (buffer) {
          gint i, prev_i;
          guint8 *data = GST_BUFFER_DATA (buffer);
          for (i = 0; i <= GST_BUFFER_SIZE (buffer) - 188; i += 188) {
            GstBuffer *ts_packet = NULL;
            GstBuffer *raw_section = NULL;
            guint8 updated_tableID;
            gpointer updated_structure = NULL;
            gboolean version_changed = FALSE;

            /* Search for the synchronization marker. Should always be the first
             * byte, but search for it just in case... */
            prev_i = i;
            while (i < GST_BUFFER_SIZE (buffer) && data[i] != 0x47)
              i++;
            if (prev_i != i) {
              GST_LOG ("Skipping %d bytes until next SYNC marker", i - prev_i);
            }
            if (i > GST_BUFFER_SIZE (buffer) - 188) {
              continue;
            }

            ts_packet = gst_buffer_create_sub (buffer, i, 188);

            /* If we registered a callback function for data injection then
             * provide the received TS packet */

            updated_tableID = psi_filter_parse_TS_packet (psif, ts_packet,
                &updated_structure, &raw_section, &version_changed);

            /* Notify registered callbacks if necessary */
            switch (updated_tableID) {
              case 0x00:       /* PAT */
                if (psif->data_inject_cb) {
                  psif->data_inject_cb (psif->user_data, raw_section, -1);
                }
                if (version_changed && psif->pat_changed_cb != NULL) {
                  GST_DEBUG ("Notifying PAT callback");
                  g_mutex_unlock (psif->mutex);
                  psif->pat_changed_cb (psif->user_data);
                  g_mutex_lock (psif->mutex);
                }
                /* Wake up possible threads waiting for the PAT */
                g_cond_signal (psif->pat_available_cond);
                break;
              case 0x02:       /* PMT */
              {
                pmt_data *pmt = updated_structure;
                if (psif->data_inject_cb) {
                  psif->data_inject_cb (psif->user_data, raw_section,
                        pmt->program_number);
                }
                if (version_changed && psif->pmt_changed_cb != NULL) {
                  GST_DEBUG ("Notifying PMT callback");
                  g_mutex_unlock (psif->mutex);
                  psif->pmt_changed_cb (psif->user_data, pmt->program_number);
                  g_mutex_lock (psif->mutex);
                }
                /* Wake up possible threads waiting for this PMT */
                if (pmt->pmt_available_cond) {
                  g_cond_signal (pmt->pmt_available_cond);
                }
                break;
              }
              case 0x4E:
              case 0x4F:
                /* EIT, present/following */
              case 0x50:
              case 0x51:
              case 0x52:
              case 0x53:
              case 0x54:
              case 0x55:
              case 0x56:
              case 0x57:
              case 0x58:
              case 0x59:
              case 0x5A:
              case 0x5B:
              case 0x5C:
              case 0x5D:
              case 0x5E:
              case 0x5F:
              case 0x60:
              case 0x61:
              case 0x62:
              case 0x63:
              case 0x64:
              case 0x65:
              case 0x66:
              case 0x67:
              case 0x68:
              case 0x69:
              case 0x6A:
              case 0x6B:
              case 0x6C:
              case 0x6D:
              case 0x6E:
              case 0x6F:
                /* EIT, schedule */
              {
                if (updated_structure) {
                  if (psif->eit_changed_cb != NULL) {
                    GST_DEBUG ("Notifying EIT callback");
                    g_mutex_unlock (psif->mutex);
                    psif->eit_changed_cb (psif->user_data, updated_structure);
                    g_mutex_lock (psif->mutex);
                  }
                  else {
                    gst_structure_free (updated_structure);
                  }
                }
                break;
              }
              case 0x70:       /* TDT */
              {
                if (updated_structure) {
                  if (psif->tdt_changed_cb != NULL) {
                    GST_DEBUG ("Notifying TDT callback");
                    g_mutex_unlock (psif->mutex);
                    psif->tdt_changed_cb (psif->user_data, updated_structure);
                    g_mutex_lock (psif->mutex);
                  }
                  else {
                    gst_structure_free (updated_structure);
                  }
                }
                break;
              }
            }
            if (raw_section) {
              gst_buffer_unref (raw_section);
            }
          }
          if (i != GST_BUFFER_SIZE (buffer)) {
            /* There is an incomplete packet here. Keep for later. */
            if (psif->remnant_buffer != NULL) {
              /* Free previous remnant (Should not really reach here) */
              gst_buffer_unref (psif->remnant_buffer);
            }
            psif->remnant_buffer = gst_buffer_create_sub (buffer, i,
                GST_BUFFER_SIZE (buffer) - i);

            GST_DEBUG ("Remaining %d bytes not parsed. Keeping for later.",
                GST_BUFFER_SIZE (buffer) - i);
          }

          gst_buffer_unref (buffer);
        }
      } else {
        if (result != ISMD_ERROR_NO_DATA_AVAILABLE)
          GST_WARNING ("ismd_port_read failed(%d)", result);
      }
    }
  }

  if (ack) {
    if ((result = ismd_event_acknowledge (psif->port_event)) != ISMD_SUCCESS) {
      GST_WARNING ("ismd_event_acknowledge failed(%d)", result);
    }
    ack = FALSE;
  }

  g_mutex_unlock (psif->mutex);

  return NULL;
}

static void
psi_filter_free_sectionfilter (gpointer data)
{
  GstSectionFilter *sf = (GstSectionFilter *) data;
  gst_section_filter_uninit (sf);
  g_free (sf);
}

static void
psi_filter_free_pmt_data (gpointer data)
{
  pmt_data *pmt = (pmt_data *) data;
  /* Deallocate array AND container */
  if (pmt->entries) {
    psi_filter_free_pmt_entries (pmt->entries);
  }
  if (pmt->program_info) {
    gst_mpeg_descriptor_free (pmt->program_info);
  }
  g_free (pmt);
}

/* Create a psi_filter instance.
 * Starts a thread and continuously parses incoming PATs and PMTs, storing them
 * in internal structures.
 * Emits a wake up signal for the waiting conditions of psi_filter_wait_for_pat
 * and psi_filter_wait_for_pmt. Checks incoming versions of PATs and PMTs and
 * compares with the previous ones. If changed, calls to the registered
 * callbacks. */
gboolean
psi_filter_create (ismd_dev_t demux_handle, psi_filter ** psif)
{
  psi_filter *pf = NULL;
  ismd_result_t result;
  ismd_demux_pid_list_t pid_list;

  if (demux_handle == ISMD_DEV_HANDLE_INVALID)
    return FALSE;
  g_return_val_if_fail (psif != NULL, FALSE);
  g_return_val_if_fail (*psif == NULL, FALSE);

  /* Allocate instance */
  pf = g_try_malloc0 (sizeof (psi_filter));
  if (pf == NULL) {
    GST_WARNING ("g_try_malloc0 failed");
    goto abort;
  }
  
  /* Some default values */
  pf->pat.version_number = -1;
  pf->port_event = ISMD_EVENT_HANDLE_INVALID;
  PSI_BUFFER_SIZE_GET (pf->demux_filter_size);
  if (pf->demux_filter_size <= 0)
  {
    /* if the filter size is not specified, force it to a default value of 4k */
    pf->demux_filter_size = 0x1000;
  }
  GST_DEBUG ("PSI buffer size set to %d", pf->demux_filter_size);

  *psif = pf;
  pf->demux_handle = demux_handle;

  /* Create mutex */
  pf->mutex = g_mutex_new ();
  
  /*
   * Configure the filter
   */
  result = ismd_demux_filter_open (demux_handle,
      ISMD_DEMUX_OUTPUT_WHOLE_TS_PACKET, pf->demux_filter_size,
      &pf->filter_handle, &pf->filter_output_port_handle);
  if (result != ISMD_SUCCESS) {
    GST_WARNING ("ismd_demux_filter_open failed(%d)", result);
    goto abort;
  }
  GST_DEBUG ("Successfully opened the filter and got port %d",
      pf->filter_output_port_handle);
  
  /* Accept PAT streams */
  pf->filter_valid = TRUE;
  pid_list.pid_array[0].pid_val = 0;    /* PAT is always on PID 0 */
  pid_list.pid_array[0].pid_type = ISMD_DEMUX_PID_TYPE_PES;
  pid_list.pid_array[1].pid_val = 0x12; /* EIT is always on PID 0x12 */
  pid_list.pid_array[1].pid_type = ISMD_DEMUX_PID_TYPE_PES;
  pid_list.pid_array[2].pid_val = 0x14; /* TDT is always on PID 0x14 */
  pid_list.pid_array[2].pid_type = ISMD_DEMUX_PID_TYPE_PES;
  result = ismd_demux_filter_map_to_pids (demux_handle, pf->filter_handle,
      pid_list, 3);
  if (result != ISMD_SUCCESS) {
    GST_WARNING ("ismd_demux_filter_map_to_pids for PAT,TDT failed (%d)",
        result);
    goto abort;
  }

  /* Create table of PMTs being tracked */
  pf->pmt_hash_table = g_hash_table_new_full (g_direct_hash, g_direct_equal,
      NULL, psi_filter_free_pmt_data);

  /* Create TS section filters (NOT ISMD section filters). These allow merging
   * PSI tables that have been split across multiple TS packets */
  pf->section_filter_hash_table =
      g_hash_table_new_full (g_direct_hash, g_direct_equal, NULL,
      psi_filter_free_sectionfilter);

  /* Create event to monitor ismd port activity */
  pf->port_event = ISMD_EVENT_HANDLE_INVALID;
  result = ismd_event_alloc (&pf->port_event);
  if (result != ISMD_SUCCESS) {
    GST_WARNING ("ismd_event_alloc for PAT failed(%d)", result);
    goto abort;
  }
  result = ismd_port_attach (pf->filter_output_port_handle, pf->port_event,
      ISMD_QUEUE_EVENT_ALWAYS, ISMD_QUEUE_WATERMARK_NONE);
  if (result != ISMD_SUCCESS) {
    GST_WARNING ("ismd_port_attach for filter %x failed(%d)",
        pf->filter_output_port_handle, result);
    goto abort;
  }
  pf->attached = TRUE;

  /* Create conditions */
  pf->pat_available_cond = g_cond_new ();

  /* Create event loop thread */
  pf->event_loop_running = TRUE;
  pf->event_loop_thread = g_thread_create ((GThreadFunc) psi_filter_event_loop,
      (gpointer) pf, TRUE, NULL);
  if (pf->event_loop_thread == NULL) {
    GST_WARNING ("g_thread_create failed");
    goto abort;
  } else {
    GST_LOG ("ISMD port monitoring thread created successfully");
  }

  return TRUE;

abort:
  if (pf != NULL) {
    g_mutex_free (pf->mutex);
    if (pf->attached) {
      ismd_port_detach (pf->filter_output_port_handle);
      pf->attached = FALSE;
    }
    if (pf->filter_valid) {
      ismd_demux_filter_close (pf->demux_handle, pf->filter_handle);
    }
    if (pf->port_event != ISMD_EVENT_HANDLE_INVALID) {
      ismd_event_free (pf->port_event);
    }
    if (pf->pat_available_cond) {
      g_cond_free (pf->pat_available_cond);
    }
    if (pf->pmt_hash_table) {
      g_hash_table_destroy (pf->pmt_hash_table);
    }
    if (pf->section_filter_hash_table) {
      /* This will call our destroy handlers for each dynamically allocated
       * GstSectionFilter */
      g_hash_table_destroy (pf->section_filter_hash_table);
    }  
    g_free (pf);
  }
  *psif = NULL;
  return FALSE;
}

/* Destroys the psi_filter instance. Frees resources and finishes the monitoring
 * thread. */
void
psi_filter_destroy (psi_filter * psif)
{
  g_return_if_fail (psif != NULL);

  g_mutex_lock (psif->mutex);

  GST_LOG ("Signalling psi_filter_event_loop thread to stop");
  psif->event_loop_running = FALSE;
  ismd_event_strobe (psif->port_event);

  g_mutex_unlock (psif->mutex);

  g_thread_join (psif->event_loop_thread);
  GST_LOG ("psi_filter_event_loop thread has stopped");

  psi_filter_set_callbacks (psif, NULL, NULL, NULL, NULL, NULL, NULL);

  g_mutex_free (psif->mutex);

  if (psif->attached) {
    ismd_port_detach (psif->filter_output_port_handle);
    psif->attached = FALSE;
  }

  if (psif->filter_valid) {
    ismd_demux_filter_stop (psif->demux_handle, psif->filter_handle);
    ismd_demux_filter_close (psif->demux_handle, psif->filter_handle);
  }
  
  if (psif->port_event != ISMD_EVENT_HANDLE_INVALID) {
    ismd_event_free (psif->port_event);
  }

  if (psif->pat_available_cond)
    g_cond_free (psif->pat_available_cond);

  if (psif->pmt_hash_table) {
    g_hash_table_destroy (psif->pmt_hash_table);
  }

  if (psif->section_filter_hash_table) {
    /* This will call our destroy handlers for each dynamically allocated
     * GstSectionFilter */
    g_hash_table_destroy (psif->section_filter_hash_table);
  }

  if (psif->remnant_buffer != NULL) {
    gst_buffer_unref (psif->remnant_buffer);
  }

  if (psif->pat.entries) {
    g_array_free (psif->pat.entries, TRUE);
    psif->pat.entries = NULL;
  }

  g_free (psif);
}

/* Wait until the PAT is found or the timeout, returns TRUE if PAT found */
/* Timeout in microseconds */
gboolean
psi_filter_wait_for_pat (psi_filter * psif, glong timeout)
{
  GTimeVal alarm;
  gboolean result = TRUE;

  g_mutex_lock (psif->mutex);
  if (psif->pat.valid) {
    GST_LOG ("PAT already available: No need to wait");
    goto beach;
  }

  GST_LOG ("PAT not received yet. Going to wait %g seconds.", timeout / 1E6);
  g_get_current_time (&alarm);
  g_time_val_add (&alarm, timeout);
  result = g_cond_timed_wait (psif->pat_available_cond, psif->mutex, &alarm);
  if (result == TRUE)
    GST_LOG ("Woke up: PAT received");
  else
    GST_LOG ("Woke up: PAT NOT received");

beach:
  g_mutex_unlock (psif->mutex);
  return result;
}

/* Copies PAT from the internal structure to the supplied pat */
gboolean
psi_filter_get_pat (psi_filter * psif, pat_data * pat)
{
  gboolean result = FALSE;

  g_mutex_lock (psif->mutex);

  if (psif->pat.valid) {
    memcpy (pat, &psif->pat, sizeof (psif->pat));
    result = TRUE;
  }

  g_mutex_unlock (psif->mutex);
  return result;
}

/* Wait until the PMT for specified service_id is found or the timeout,
 * returns TRUE if pmt found */
/* Timeout in microseconds */
gboolean
psi_filter_wait_for_pmt (psi_filter * psif, guint16 service_id, glong timeout)
{
  GTimeVal alarm;
  gboolean result = FALSE;
  pmt_data *pmt = NULL;

  g_mutex_lock (psif->mutex);

  GST_DEBUG ("Wait for PMT on program # %d", service_id);

  if (psif->pat.valid == FALSE) {
    GST_WARNING ("PAT not received yet");
    goto beach;
  }

  if (psi_filter_find_prognum_in_pat (&psif->pat, service_id) == NULL) {
    GST_WARNING ("Program number %d not found in current PAT", service_id);
    goto beach;
  }
  pmt =
      g_hash_table_lookup (psif->pmt_hash_table, (gpointer) (gint) service_id);
  if (pmt == NULL) {
    GST_DEBUG ("Create an empty pmt to allocate the condition");
    /* This is the first time we receive a PMT with this progNum.
     * Create new PMT entry and add it to the table */
    pmt = g_malloc0 (sizeof (pmt_data));
    pmt->version_number = -1;
    g_hash_table_insert (psif->pmt_hash_table, (gpointer) (gint) service_id,
        pmt);
  } else if (pmt->valid) {
    GST_LOG ("PMT for program %d already available: No need to wait",
        service_id);
    result = TRUE;
    goto beach;
  }

  if (!pmt->pmt_available_cond) {
    pmt->pmt_available_cond = g_cond_new ();
  }

  GST_LOG ("PMT for program %d not received yet. Going to wait %g seconds.",
      service_id, timeout / 1E6);
  g_get_current_time (&alarm);
  g_time_val_add (&alarm, timeout);
  result = g_cond_timed_wait (pmt->pmt_available_cond, psif->mutex, &alarm);
  if (result == TRUE)
    GST_LOG ("Woke up: PMT received");
  else
    GST_LOG ("Woke up: PMT NOT received");

beach:
  if (pmt && pmt->pmt_available_cond) {
    g_cond_free (pmt->pmt_available_cond);
    pmt->pmt_available_cond = NULL;
  }
  g_mutex_unlock (psif->mutex);
  return result;
}

/* Copies requested PMT from the internal structure into the supplied pmt */
gboolean
psi_filter_get_pmt (psi_filter * psif, guint16 service_id, pmt_data * dest_pmt)
{
  gboolean result = FALSE;
  pmt_data *org_pmt;

  g_mutex_lock (psif->mutex);

  if (psif->pat.valid == FALSE) {
    GST_WARNING ("PAT not received yet.");
    goto beach;
  }

  if (psi_filter_find_prognum_in_pat (&psif->pat, service_id) == NULL) {
    GST_WARNING ("Program number %d not found in current PAT", service_id);
    goto beach;
  }

  org_pmt = g_hash_table_lookup (psif->pmt_hash_table,
      (gpointer) (gint) service_id);
  if (org_pmt != NULL) {
    if (!org_pmt->valid)
      goto beach;
    memcpy (dest_pmt, org_pmt, sizeof (*org_pmt));
    result = TRUE;
  } else {
    GST_WARNING ("PMT for program number %d not received yet", service_id);
  }

beach:
  g_mutex_unlock (psif->mutex);
  return result;
}

/* Registers the supplied callbacks, so that they get called when new PATs or
 * PMTs are received */
void
psi_filter_set_callbacks (psi_filter * psif,
    pat_changed_cb_t pat_changed_cb, pmt_changed_cb_t pmt_changed_cb,
    eit_changed_cb_t eit_changed_cb, tdt_changed_cb_t tdt_changed_cb,
    data_inject_cb_t data_inject_cb, gpointer user_data)
{

  g_mutex_lock (psif->mutex);

  psif->pat_changed_cb = pat_changed_cb;
  psif->pmt_changed_cb = pmt_changed_cb;
  psif->eit_changed_cb = eit_changed_cb;
  psif->tdt_changed_cb = tdt_changed_cb;
  psif->data_inject_cb = data_inject_cb;
  psif->user_data = user_data;

  g_mutex_unlock (psif->mutex);
  GST_DEBUG ("Callbacks succesfully changed");
}

static inline GValueArray *
build_descriptors_value_array (GstMPEGDescriptor * mpeg_desc)
{
  GString *desc;
  GValue value = { 0 };
  GValueArray *descriptors = g_value_array_new (mpeg_desc->n_desc);
  guint i;
  guint8 *data = mpeg_desc->data;

  for (i = 0; i < mpeg_desc->n_desc; i++) {
    guint8 length = DESC_LENGTH (data);

    /* include tag and length */
    desc = g_string_new_len ((gchar *) data, length + 2);
    data += length + 2;

    g_value_init (&value, G_TYPE_GSTRING);
    g_value_take_boxed (&value, desc);
    g_value_array_append (descriptors, &value);
    g_value_unset (&value);
  }

  return descriptors;
}

GstStructure *
psi_filter_build_pat_structure (psi_filter * psif)
{
  pat_data pat;
  GstStructure *pat_struct = NULL;
  GValue entries = { 0 };
  GValue value = { 0 };
  GstStructure *entry = NULL;
  gchar *struct_name;
  gint i;

  g_return_val_if_fail (psif != NULL, NULL);

  if (psi_filter_get_pat (psif, &pat) == FALSE) {
    return NULL;
  }

  GST_DEBUG ("Building PAT structure");

  pat_struct = gst_structure_new ("pat",
      "transport-stream-id", G_TYPE_UINT, pat.transport_stream_id, NULL);
  g_value_init (&entries, GST_TYPE_LIST);
  for (i = 0; i < pat.entries->len; i++) {
    pmt_descriptor *pmt_desc = &g_array_index (pat.entries, pmt_descriptor, i);
    struct_name = g_strdup_printf ("program-%d", pmt_desc->program_number);
    entry = gst_structure_new (struct_name,
        "program-number", G_TYPE_UINT, pmt_desc->program_number,
        "pid", G_TYPE_UINT, pmt_desc->pmt_pid, NULL);
    g_free (struct_name);

    g_value_init (&value, GST_TYPE_STRUCTURE);
    g_value_take_boxed (&value, entry);
    gst_value_list_append_value (&entries, &value);
    g_value_unset (&value);
  }

  gst_structure_set_value (pat_struct, "programs", &entries);
  g_value_unset (&entries);

  GST_DEBUG ("Created PAT structure: %" GST_PTR_FORMAT, pat_struct);

  return pat_struct;
}

GstStructure *
psi_filter_build_pmt_structure (psi_filter * psif, guint16 program)
{
  pmt_data pmt;
  GstStructure *pmt_struct = NULL;
  gint i;
  GValueArray *descriptors;
  GValue stream_value = { 0 };
  GValue programs = { 0 };
  GstStructure *stream_info = NULL;
  gchar *struct_name;

  g_return_val_if_fail (psif != NULL, NULL);

  if (psi_filter_get_pmt (psif, program, &pmt) == FALSE) {
    return NULL;
  }

  GST_DEBUG ("Building PMT structure");

  struct_name = g_strdup ("pmt");
  pmt_struct = gst_structure_new (struct_name,
      "program-number", G_TYPE_UINT, pmt.program_number,
      "pcr-pid", G_TYPE_UINT, pmt.pcr_pid,
      "version-number", G_TYPE_UINT, pmt.version_number, NULL);
  g_free (struct_name);

  if (pmt.program_info_length) {
    descriptors = build_descriptors_value_array (pmt.program_info);

    gst_structure_set (pmt_struct, "descriptors", G_TYPE_VALUE_ARRAY,
        descriptors, NULL);
    g_value_array_free (descriptors);
  }

  g_value_init (&programs, GST_TYPE_LIST);
  for (i = 0; i < pmt.entries->len; i++) {
    pmt_stream_data *cur_entry =
        &g_array_index (pmt.entries, pmt_stream_data, i);

    struct_name = g_strdup_printf ("pid-%d", cur_entry->pid);
    stream_info = gst_structure_new (struct_name,
        "pid", G_TYPE_UINT, cur_entry->pid,
        "stream-type", G_TYPE_UINT, cur_entry->type, NULL);
    g_free (struct_name);

    if (cur_entry->info_length) {
      descriptors = build_descriptors_value_array (cur_entry->info);

      gst_structure_set (stream_info,
          "descriptors", G_TYPE_VALUE_ARRAY, descriptors, NULL);

      g_value_array_free (descriptors);
    }

    g_value_init (&stream_value, GST_TYPE_STRUCTURE);
    g_value_take_boxed (&stream_value, stream_info);
    gst_value_list_append_value (&programs, &stream_value);

    g_value_unset (&stream_value);
  }

  gst_structure_set_value (pmt_struct, "streams", &programs);
  g_value_unset (&programs);

  GST_DEBUG ("Created PMT structure: %" GST_PTR_FORMAT, pmt_struct);

  return pmt_struct;
}
