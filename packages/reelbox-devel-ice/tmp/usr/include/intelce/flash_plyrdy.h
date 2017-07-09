/****************************************************************************
 * Copyright (c) 2008-2010 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_plyrdy.h
 ***************************************************************************/

#ifndef FLASH_PLYRDY_INCLUDED
#define FLASH_PLYRDY_INCLUDED

#include <stdio.h>
#include "flash_appdata_defs.h"

#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif

#define PLYRDY_MODEL_TYPE 0x00003001

enum enum_module_type
{
	PLAYREADY,
	WMDRM,

	//always last
	MODULE_COUNT
};

const char *g_szModuleTypeStr[MODULE_COUNT] = {
	"PLAYREADY",
	"WMDRM",
};

const char *g_szModel_Key_Flags[32] = {
	"WMDRM Model Keys Present",
	"Playready Model Keys Present",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ", //10
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
	"Reserved    ",
     	"Reserved    ",
        "Reserved    ",
        "Reserved    ",
        "Reserved    ", //20
        "Reserved    ",
        "Reserved    ",
        "Reserved    ",
        "Reserved    ",
        "Reserved    ",
        "Reserved    ",
        "Reserved    ",
	"Reserved    ",
        "Reserved    ",
        "Reserved    ", //30
        "Reserved    ",
        "Reserved    ",
};

typedef struct
{
	flash_appdata_u32_t		moduleType;	// Playready Confidential Model Key Data Flash Module Type = 0x00003001
	flash_appdata_u32_t		revisionNumber;	// Initial Revision = 0x00000001 
	flash_appdata_u32_t		keyFlags;	// Bit 0 = WMDRM Model Keys Present 
							// Bit 1 = Playready Model Keys present
							// Bit 31:2 = Reserved
	flash_appdata_u32_t		keyGenDate;	// BCD representation of date as yyyymmdd where yyyy=4 digit year, mm=1-12, dd=1-31
}model_header_t;

	flash_appdata_u32_t modType;

/*-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-vv-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-*/
/*                        ALL EXTERNAL C SYMBOLS GO BELOW HERE                        */
/*------------------------------------------------------------------------------------*/

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write CPU ID to specified flash
 *
 *   Writes CPU ID to flash.
 *
 *     @param[in] buffer					buffer of 32-bits of cpu id to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be 4 bytes)
 *     @param[in/out] dwflashtype			enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t
flash_plyrdy_write_cpu_id
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t 	*dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read CPU ID
 *
 *   Reads CPU ID from flash.
 *
 *     @param[out] buffer						buffer to write 32-bits of cpu id from flash
 *     @param[in] buffer_length_bytes			number of bytes to read (must be 4 bytes)
 *     @param[out] buffer_length_read_bytes		number of bytes read into buffer
 *     @param[in/out] dwflashtype				enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          	If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t
flash_plyrdy_read_cpu_id
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*buffer_length_read_bytes,
  flash_appdata_u32_t 	*dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write CPU Serial Number
 *
 *   Writes CPU Serial Number to flash.
 *
 *     @param[in] buffer					buffer of 32-bits of serial number to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be 8 bytes)
 *     @param[in/out] dwflashtype			enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t
flash_plyrdy_write_serial_number
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read CPU Serial Number
 *
 *   Reads CPU Serial Number from flash.
 *
 *     @param[out] buffer						buffer to write 64-bits of serial number from flash
 *     @param[in] buffer_length_bytes			number of bytes to read (must be 8 bytes)
 *     @param[out] buffer_length_read_bytes		number of bytes read into buffer
 *     @param[in/out] dwflashtype			enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t
flash_plyrdy_read_serial_number
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*buffer_length_read_bytes,
  flash_appdata_u32_t	*dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Play Ready Modal Data to specified flash type
 *
 *   Writes a Play Ready Modal Data to flash.  The Modal Data is of the following format:
 *
 *     1024 bytes:   pack that contains encrypted Play Ready Modal data
 *
 *     @param[in] buffer					buffer of data to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be <= 1024)
 *     @param[in/out] dwflashtype			enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t
flash_plyrdy_write_modal_data
 (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t	*dwflashtype
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Play Ready Modal Data to specified flash
 *
 *   Read a Play Ready Modal Data to flash.  The Modal Data is of the following format:
 *
 *     1024 bytes:   pack that contains encrypted Play Ready data
 *
 *     @param[out] buffer						buffer to fill with data from flash
 *     @param[in] buffer_length_bytes			number of bytes to read (must be <= 1024)
 *     @param[out] buffer_length_read_bytes		number of bytes read into buffer
 *     @param[in/out] dwflashtype				enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          	If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t
flash_plyrdy_read_modal_data
 (
  void					*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
  flash_appdata_u32_t 	*buffer_length_read_bytes,
  flash_appdata_u32_t	*dwflashtype
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Play Ready raw data from flash
 *   This will select which type of flash
 *
 *   Read a Play Ready raw data from flash.  The data is of the following format:
 *
 *     @param[out] buffer						 buffer to fill with data from flash
 *     @param[in] offset						 offset read into buffer
 *     @param[in] buffer_length_bytes			 number of bytes read into buffer
 *     @param[in]  dwflashtype					 enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          	 If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *
 *	   @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_PARAM_SIZE          Invalid value parameter size.
 */
flash_appdata_result_t 
flash_plyrdy_read_raw_data
 (
 void					*buffer, 
 flash_appdata_u32_t	offset,
 flash_appdata_u32_t	buffer_length_bytes,
 flash_appdata_u32_t	dwflashtype
 );
 /* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */
 
/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Play Ready Data to specified flash type
 *
 *   Writes a Play Ready Data to flash.  The entire Data is of the following format:
 *
 *     1120 bytes:   pack that contains Play Ready data or random data, usage can be to erase all Play Ready data
 *
 *     @param[in] buffer					buffer of data to write to flash
 *     @param[in] buffer_length_bytes		number of bytes to write (must be <= 1120)
 *     @param[in/out] dwflashtype			enum FLASH_TYPE (NOR, NAND, DEF_FLASH) 
 *                                          If DEF_FLASH passed in then check bootstrap settings for which flash type to write data.
 *     @return  nothing
 */
flash_appdata_result_t 
flash_plyrdy_erase
  (
  const void			*buffer,
  flash_appdata_u32_t	buffer_length_bytes,
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
flash_appdata_result_t flash_plyrdy_type(FLASH_TYPE * flash, DEVICE_TYPE * device);

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

#endif  /*  ndef flash_plyrdy_INCLUDED  */

