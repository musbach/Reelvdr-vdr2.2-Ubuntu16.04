/****************************************************************************
 * Copyright (c) 2008-2010 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_appdata_defs.h
 ***************************************************************************/

#ifndef _FLASH_APPDATA_DEFS_H_
#define _FLASH_APPDATA_DEFS_H_

#undef VERBOSE

#ifdef VERBOSE
#define debug(...)   fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

typedef unsigned char 		flash_appdata_u8_t;
typedef unsigned short 		flash_appdata_u16_t;
typedef unsigned int 		flash_appdata_u32_t;
typedef unsigned long long 	flash_appdata_u64_t;

typedef enum
{
	P30,
	SPANSION,
}FLASH_NOR_TYPE;

typedef enum
{
	NOR = 0,
	NAND = 1,
/*	FAD_EMMC = 2, */
	DEF_FLASH = 0xFF,	//default flash type is the boot flash type
}FLASH_TYPE;

typedef enum
{
	FAD_EXPNOR = 0,
	FAD_NAND = 1,
	FAD_EMMC = 2,
	FAD_SPINOR = 3,
	FAD_BOOT_FLASH = 0xFF,	//default flash type is the boot flash type
}FAD_FLASH_TYPE;

typedef enum
{
	GEN3 = 0,
	GEN4 = 1,
	GEN5 = 2
}DEVICE_TYPE;

typedef enum 
{
	FLASH_APPDATA_SUCCESS = 0,
	FLASH_APPDATA_FAIL,
	FLASH_APPDATA_INVALID_PARAM,
	FLASH_APPDATA_PARAM_SIZE,
	FLASH_APPDATA_UNMATCH_SILICON,
	FLASH_APPDATA_NO_DATA,
	FLASH_APPDATA_UNMATCH_DATA,
	FLASH_APPDATA_NOT_ENOUGH_MEMORY,
	FLASH_APPDATA_INVALID_FLASHTYPE,
	FLASH_APPDATA_PAL_FAIL,
        FLASH_APPDATA_BUFFER_NULL,
} flash_appdata_result_t;

#define FLASH_APPDATA_RESULT_TEXT(s) \
	( ((s)==FLASH_APPDATA_SUCCESS)            ? "FLASH_APPDATA_SUCCESS" : \
	  ((s)==FLASH_APPDATA_FAIL)               ? "FLASH_APPDATA_FAIL" : \
	  ((s)==FLASH_APPDATA_INVALID_PARAM)      ? "FLASH_APPDATA_INVALID_PARAM" : \
	  ((s)==FLASH_APPDATA_PARAM_SIZE)         ? "FLASH_APPDATA_PARAM_SIZE" : \
	  ((s)==FLASH_APPDATA_UNMATCH_SILICON)    ? "FLASH_APPDATA_UNMATCH_SILICON" : \
	  ((s)==FLASH_APPDATA_NO_DATA)            ? "FLASH_APPDATA_NO_DATA" : \
	  ((s)==FLASH_APPDATA_UNMATCH_DATA)       ? "FLASH_APPDATA_UNMATCH_DATA" : \
	  ((s)==FLASH_APPDATA_NOT_ENOUGH_MEMORY)  ? "FLASH_APPDATA_NOT_ENOUGH_MEMORY" : \
	  ((s)==FLASH_APPDATA_INVALID_FLASHTYPE)  ? "FLASH_APPDATA_INVALID_FLASHTYPE" : \
	  ((s)==FLASH_APPDATA_PAL_FAIL)           ? "FLASH_APPDATA_PAL_FAIL" : \
          ((s)==FLASH_APPDATA_BUFFER_NULL)        ? "FLASH_APPDATA_BUFFER_NULL" : \
                                               "<unrecognized status code>" )

typedef enum
{
        WRITE = 0,
        READ = 1,
}flash_action;

// Exported flash_appdata APIs
flash_appdata_result_t flash_type(FLASH_TYPE * flash, DEVICE_TYPE * device);

#endif  /*  ifndef _FLASH_APPDATA_DEFS_H  */
