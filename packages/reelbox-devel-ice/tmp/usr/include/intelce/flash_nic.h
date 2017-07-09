/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_nic.h
 ***************************************************************************/

#ifndef FLASH_NIC_INCLUDED
#define FLASH_NIC_INCLUDED

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
/*!  \brief Read nic address space
 *
 *   Reads nic mac address information in NIC_FLASH_SIZE byte buffer.  only works on gen3
 *
 *     
 *
 *     @param[out] buffer                             buffer of data to read from flash
 *     @param[in] buffer_length_bytes             number of bytes to read (must be NIC_FLASH_SIZE)
 *     @param[out] buffer_length_read_bytes   number of bytes actually read
 *     @param[in] dwflashtype                       flash type to read MAC from (0 is NOR, 1 is NAND)
 *     @return  flash_app_data_result_t
 */
flash_appdata_result_t
flash_nic_read
 (
  void                           *buffer,
  flash_appdata_u32_t			  buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes,
  flash_appdata_u32_t             dwflashtype	 
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write NIC address space
 *
 *   Writes NIC address to flash from NIC_FLASH_SIZE byte buffer. only works on gen3
 *
 *     @param[in] buffer                         data to write
 *     @param[in] buffer_length_bytes      number of bytes to write
 *     @param[in] dwflashtype                 flash type to write MAC to (0 is NOR, 1 is NAND)
 *     @return  flash_appdata_result_t
 */
flash_appdata_result_t
flash_nic_write
 (
  const void                     *buffer,
  flash_appdata_u32_t             buffer_length_bytes,
  flash_appdata_u32_t             dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read nic mac address
 *
 *   Reads nic mac address information in 6 byte buffer
 *
 *     
 *
 *     @param[out] buffer                        buffer of data to read from flash
 *     @param[in] buffer_length_bytes            number of bytes to read (must be 6)
  *     @param[out] buffer_length_read_bytes     number of bytes actually read
 *     @return  flash_app_data_result_t
 */
flash_appdata_result_t
flash_nic_mac_read
 (
  void                           *buffer,
  flash_appdata_u32_t			  buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write NIC MAC address
 *
 *   Writes NIC MAC address to flash
 *
 *     @param[in] buffer                         MAC address to write
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 6 bytes)
 *     @return  flash_appdata_result_t
 */
flash_appdata_result_t
flash_nic_mac_write
 (
  const void *buffer,
  unsigned int buffer_length_bytes  
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

#endif  /*  ifndef FLASH_NIC_INCLUDED  */

