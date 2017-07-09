/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_aacs.h
 ***************************************************************************/

#ifndef FLASH_AACS_INCLUDED
#define FLASH_AACS_INCLUDED

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
/*!  \brief Write AACS Keys to boot flash
 *
 *   Writes a blob of keys to flash.  The blob is of the following format:
 *
 *     9744 bytes:   pack that contains encrypted AACS device/sequence keys, hPriv, ECC params, U-UV data, and Device Node
 *
 *     @param[in] buffer                         buffer of data to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 9584)
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_key_blob
 (
  const void                     *buffer,
  flash_appdata_u32_t            buffer_length_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write AACS Keys to specified flash
 *
 *   Writes a blob of keys to flash.  The blob is of the following format:
 *
 *     9744 bytes:   pack that contains encrypted AACS device/sequence keys, hPriv, ECC params, U-UV data, and Device Node
 *
 *     @param[in] buffer					buffer of data to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be 9584)
 *     @param[in/out] dwflashtype			flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_key_blob_byft
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*dwflashtype   
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write AACS Keys to boot flash
 *
 *   Writes a blob of keys to flash.  The blob is of the following format:
 *
 *     9744 bytes:   pack that contains encrypted AACS device/sequence keys, hPriv, ECC params, U-UV data, and Device Node
 *
 *     @param[out] buffer                        buffer to fill with data from flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 9584)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_key_blob
 (
  void                           *buffer,
  flash_appdata_u32_t			  buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write AACS Keys to specified flash
 *
 *   Writes a blob of keys to flash.  The blob is of the following format:
 *
 *     9744 bytes:   pack that contains encrypted AACS device/sequence keys, hPriv, ECC params, U-UV data, and Device Node
 *
 *     @param[out] buffer						buffer to fill with data from flash
 *     @param[in] buffer_length_bytes			number of bytes to write (must be 9584)
 *     @param[out] buffer_length_read_bytes		number of bytes read into buffer
 *     @param[in/out] dwflashtype				flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_key_blob_byft
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t 	*buffer_length_read_bytes,
  flash_appdata_u32_t	*dwflashtype   
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write CPU ID to boot flash
 *
 *   Writes Silicon CPU ID to flash.
 *
 *     @param[in] buffer                         buffer of 64-bits of serial number to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 8 bytes)
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_cpu_id
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write CPU ID to specified flash
 *
 *   Writes Silicon CPU ID to flash.
 *
 *     @param[in] buffer					buffer of 64-bits of serial number to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be 8 bytes)
 *     @param[in/out] dwflashtype			flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_cpu_id_byft
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t 	*dwflashtype   
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read CPU ID
 *
 *   Reads Silicon CPU ID to flash.
 *
 *     @param[out] buffer                        buffer to write 64-bits of cpu id from flash
 *     @param[in] buffer_length_bytes            number of bytes to read (must be >= 8)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_cpu_id
 (
  void                           *buffer,
  flash_appdata_u32_t             buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read CPU ID
 *
 *   Reads Silicon CPU ID to flash.
 *
 *     @param[out] buffer						buffer to write 64-bits of cpu id from flash
 *     @param[in] buffer_length_bytes			number of bytes to read (must be >= 8)
 *     @param[out] buffer_length_read_bytes		number of bytes read into buffer
 *     @param[in/out] dwflashtype				flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_cpu_id_byft
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*buffer_length_read_bytes,
  flash_appdata_u32_t 	*dwflashtype   
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Serial Number
 *
 *   Writes SEC Serial Number to flash.
 *
 *     @param[in] buffer                         buffer of 64-bits of serial number to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 8 bytes)
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_serial_number
 (
  const void                     *buffer,
  flash_appdata_u32_t             buffer_length_bytes
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Serial Number
 *
 *   Writes SEC Serial Number to flash.
 *
 *     @param[in] buffer					buffer of 64-bits of serial number to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be 8 bytes)
 *     @param[in/out] dwflashtype			flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_serial_number_byft
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*dwflashtype   
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Serial Number
 *
 *   Reads SEC Serial Number to flash.
 *
 *     @param[out] buffer                        buffer to write 64-bits of serial number from flash
 *     @param[in] buffer_length_bytes            number of bytes to read (must be >= 8)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_serial_number
 (
  void                           *buffer,
  flash_appdata_u32_t             buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Serial Number
 *
 *   Reads SEC Serial Number to flash.
 *
 *     @param[out] buffer						buffer to write 64-bits of serial number from flash
 *     @param[in] buffer_length_bytes			number of bytes to read (must be >= 8)
 *     @param[out] buffer_length_read_bytes		number of bytes read into buffer
 *     @param[in/out] dwflashtype				flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_serial_number_byft
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*buffer_length_read_bytes,
  flash_appdata_u32_t	*dwflashtype   
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Host Certificate
 *
 *   Writes the Host Certificate to flash.  The Host Certificate is 92 bytes long.
 *
 *     @param[in] buffer                         buffer of 92-byte hcert to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 92 bytes)
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_hcert
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Host Certificate
 *
 *   Writes the Host Certificate to flash.  The Host Certificate is 92 bytes long.
 *
 *     @param[in] buffer                    buffer of 92-byte hcert to write to flash
 *     @param[in] buffer_length_bytes       number of bytes to write (must be 92 bytes)
 *     @param[in/out] dwflashtype			flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_write_hcert_byft
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*dwflashtype   
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Host Certificate
 *
 *   Reads the Host Certificate from flash.  The Host Certificate is 92 bytes long.
 *
 *     @param[out] buffer                        buffer of data to fill with 92-byte hcert from flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be >= 92 bytes)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_hcert
 (
  void                           *buffer,
  flash_appdata_u32_t             buffer_length_bytes,
  flash_appdata_u32_t            *buffer_length_read_bytes
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Host Certificate
 *
 *   Reads the Host Certificate from flash.  The Host Certificate is 92 bytes long.
 *
 *     @param[out] buffer                        buffer of data to fill with 92-byte hcert from flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be >= 92 bytes)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @param[in/out] dwflashtype				flash type (NOR, NAND, DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @return  nothing
 */
flash_appdata_result_t
flash_aacs_read_hcert_byft
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*buffer_length_read_bytes,
  flash_appdata_u32_t	*dwflashtype   
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Retrieve Flash and Device Type
 *
 *   Retrieve Flash and Device Type.
 *
 *     @param[in/out] flash			flash type (NOR, NAND, and DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @param[out] device			device type (GEN3, GEN4, and GEN5) There is no default value
 *     @return  nothing
 */
//flash_appdata_result_t flash_aacs_type(FLASH_TYPE * flash, DEVICE_TYPE * device);

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

#endif  /*  ndef FLASH_AACS_INCLUDED  */

