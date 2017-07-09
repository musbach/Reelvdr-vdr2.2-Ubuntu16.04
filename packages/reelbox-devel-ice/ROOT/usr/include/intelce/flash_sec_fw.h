/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_sec_fw.h
 ***************************************************************************/

#ifndef FLASH_SEC_FW_INCLUDED
#define FLASH_SEC_FW_INCLUDED

#include <stdio.h>
#include "flash_appdata_defs.h"

#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif
/*-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-vv-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-*/
/*                        ALL EXTERNAL C SYMBOLS GO BELOW HERE                        */
/*------------------------------------------------------------------------------------*/

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write SEC Firmware to Flash
 *
 *   Writes the security firmware to flash. This data is a variable length up to max
 *   81920 bytes.
 *
 *     @param[in] buffer                         buffer of data containing fw to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write 
 *     @return  flash_appdata_result_t
 */
flash_appdata_result_t
flash_write_sec_fw
 (
  const void                     *buffer,
  flash_appdata_u32_t             buffer_length_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read SEC Firmware from Flash
 *
 *   Reads the security firmware from flash. This data is max 81920 bytes.
 *
 *     @param[out] buffer                        buffer of data to fill security firmware from flash
 *                                               if NULL, will return the number of bytes required in buffer_length_read_bytes
 *     @param[in] buffer_length_bytes            number of bytes in buffer
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *                                               if buffer == NULL, will return the number of bytes required in buffer_length_read_bytes
 *     @return  flash_appdata_result_t
 */
flash_appdata_result_t
flash_read_sec_fw
 (
  void                           *buffer,
  flash_appdata_u32_t             buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */



/*------------------------------------------------------------------------------------*/
/*                        ALL EXTERNAL C SYMBOLS GO ABOVE HERE                        */
/*-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-*/
#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif

#endif  /*  ndef FLASH_SEC_FW_INCLUDED  */

