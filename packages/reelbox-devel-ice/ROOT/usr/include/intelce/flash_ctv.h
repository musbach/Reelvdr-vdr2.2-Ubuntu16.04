/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_ctv.h
 ***************************************************************************/

#ifndef FLASH_CTV_H
#define FLASH_CTV_H

#include <stdio.h>
#include "flash_appdata_defs.h"

/*###################################################################################*/
/*  FUNCTION PROTOTYPES:                                                             */
/*###################################################################################*/
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
/*!  \brief Write Cable TV data to the selected type of flash
 *   This will select which type of flash
 *
 *   Writes a Cable TV data to flash.  The data is of the following format:
 *
 *     @param[in] ctv_buffer_length_bytes        number of bytes to write
 *     @param[in] ctv_buffer                     buffer of data to write to flash
 *     @param[in] dwflashtype                    flash type to write Cable TV keys to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @return  nothing
 */
int flash_ctv_write_key_info
 (
  flash_appdata_u32_t            ctv_buffer_length_bytes,
  const void                     *ctv_buffer,
  FAD_FLASH_TYPE                     dwflashtype
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Cable TV data from flash
 *   This will manually select which type of flash
 *
 *   Read a Cable TV data from flash.  The data is of the following format:
 *
 *     @param[in]  buffer_length_bytes           number of bytes to write (no greater than 4092)
 *     @param[out] ctv_buffer                    buffer to fill with data from flash
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @param[in]  dwflashtype                   flash type to read Cable TV keys from (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @return  nothing
 */
int flash_ctv_read_key_info
 (
  flash_appdata_u32_t			  ctv_buffer_length_bytes,
  void                           *ctv_buffer,
  flash_appdata_u32_t            *buffer_length_read_bytes,
  FAD_FLASH_TYPE                     dwflashtype
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

#endif  /*  FLASH_CTV_H  */

