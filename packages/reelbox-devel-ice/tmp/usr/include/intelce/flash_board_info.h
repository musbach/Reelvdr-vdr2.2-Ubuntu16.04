/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_board_info.h
 ***************************************************************************/

#ifndef FLASH_BOARD_INFO_INCLUDED
#define FLASH_BOARD_INFO_INCLUDED

#include <stdio.h>
#include "flash_appdata_defs.h"
//
//typedef struct 
//{
//	unsigned char day;
//	unsigned char month;
//	unsigned char year; //20XX
//} board_info_date_t;
//
//typedef struct
//{
//	unsigned short type;
//	unsigned char sku;
//	unsigned char fab;
//	board_info_date_t mb_mfg_date;
//	unsigned int ch1_sdcr0_config;
//	unsigned int ch1_sdcr1_config;
//	unsigned int ch2_sdcr0_config;
//	unsigned int ch2_sdcr1_config;
//	unsigned short checksum;	
//} flash_board_info_t;

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
/*!  \brief Write board info data
 *
 *   Writes a data to board info part of memory:
 *
 *     256 bytes:     zeros (non-zero reserved for future use to indicate data format)
 *
 *	Description:\n
 *		00-01H 	0004H Main Board\n
 *			01 - Intel?Media Processor CE 2110 Development Platform\n
 *			02 - Reserved\n
 *			03 - Intel?Media Processor CE 2110 Reference Platform\n\n
 *			
 *			04 - Intel?Media Processor CE 2210 Development Platform\n
 *			06 - Intel?Media Processor CE 2210 Reference Platform\n\n
 *			
 *			07 - Intel?Media Processor CE 3100 Development Platform\n
 *			08 - Intel?Media Processor CE 3100 Silicon Validation Platform\n\n
 *			
 *			09 - Intel?Media Processor CE 4XXX DDR2 Development Platform\n
 *			0A - Intel?Media Processor CE 4XXX DDR3 Development Platform\n
 *			0B - Intel?Media Processor CE 4XXX DDR3 Silicon Validation Platform\n\n
 *
 *		02H 	Main Board SKU\n
 *			00 ?HD\n
 *			01 ?SD\n
 *			02 ?FF ?Reserved for future use\n\n
 *		03H 	00-FFH FAB\n\n
 *		This is a Hex-ASCII value (i.e. 41H = Fab A, 42H = Fab B)\n
 *		04-06H	000000H Manufacture Date\n
 *			04H	XXH	    Date - Day\n
 *			05H	XXH	    Date - Month\n
 *			06H	XXH	    Date ?Year 20XX\n\n
 *		07-0AH	CH1-SDCR0 Memory CH1 ?Config SDCR0\n
 *			07H		    Bits 31-24 (tRAS and tRP)\n
 *			08H		    Bits 23-16 (tRCD and tEDP)\n
 *			09H		    Bits 15-8 (tWDL and tCAS)\n
 *			0AH		    Bits 7-0 (DDR1/2,tRRD,2T,dqs#dis and unbuf)\n\n
 *		0B-0EH	CH1-SDCR1 Memory CH1 ?Config SDCR1\n
 *			0BH		    Bits 31-24 (tRTC and tWTCMD)\n
 *			0CH		    Bits 23-16 (tRTW and bit 5 of tRFC)\n
 *			0DH		    Bits 15-8 (tRFC, Speed and bit 5 of tRC)\n
 *			0EH		    Bits 7-0 (tRC and tWTRD)\n\n
 *		0FH 	CH1-SBR0 Memory CH1 ?Config SBR0\n
 *			0FH		    Bits 31-24 (Column bits and Row bits)\n\n
 *		10-13H	CH2-SDCR0 Memory CH2 ?Config SDCR0\n
 *			10H		    Bits 31-24 (tRAS and tRP)\n
 *			11H		    Bits 23-16 (tRCD and tEDP)\n
 *			12H		    Bits 15-8 (tWDL and tCAS)\n
 *			13H		    Bits 7-0 (DDR1/2,tRRD,2T,dqs#dis and unbuf)\n\n
 *		14-17H	CH2-SDCR1 Memory CH2 ?Config SDCR1\n
 *			14H		    Bits 31-24 (tRTC and tWTCMD)\n
 *			15H		    Bits 23-16 (tRTW and bit 5 of tRFC)\n
 *			16H		    Bits 15-8 (tRFC, Speed and bit 5 of tRC)\n
 *			17H		    Bits 7-0 (tRC and tWTRD)\n\n
 *		18H 	CH2-SBR0 Memory CH2 ?Config SBR0\n
 *			18H		    Bits 31-24 (Column bits and Row bits)\n\n
 *		19-24H	Board Serial Number\n
 *		This is a Hex-ASCII values.\n
 *		19H	XXH    	    Char 12\n
 *		1AH	XXH    	    Char 11\n
 *		1BH	XXH    	    Char 10\n
 *		1CH	XXH    	    Char 9\n
 *		1DH	XXH    	    Char 8\n
 *		1EH	XXH    	    Char 7\n
 *		1FH	XXH    	    Char 6\n
 *		20H	XXH    	    Char 5\n
 *		21H	XXH    	    Char 4\n
 *		22H	XXH    	    Char 3\n
 *		23H	XXH    	    Char 2\n
 *		24H	XXH	    	Char 1\n\n
 *		25-2AH	PBA\n
 *		This is a Hex-ASCII values.\n
 *		25H	XXH    	    Char 10\n
 *		26H	XXH    	    Char 9\n
 *		27H	XXH    	    Char 8\n
 *		28H	XXH    	    Char 7\n
 *		29H	XXH    	    Char 6\n
 *		2AH	XXH	    Char 5\n
 *		2BH	2DH	    Char 4\n
 *		2CH	XXH	    Char 3\n
 *		2DH	XXH	    Char 2\n
 *		2EH	XXH	    Char 1\n
 *		2FH-DDH	RESERVED\n
 *		DEH-DFH	CHECKSUM\n
 *		E0H-FFH RESERVED\n\n\n
 *
 *
 *     @param[in] buffer                         buffer of data to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 9584)
 *     @return  flash_appdata_result_t			 result
 */
flash_appdata_result_t
flash_board_info_write
 (
  void *buffer,
  flash_appdata_u32_t buffer_length_bytes
 );

flash_appdata_result_t
flash_board_info_write2
 (
  void *buffer,
  flash_appdata_u32_t buffer_length_bytes,
  flash_appdata_u32_t dwflashtype   
 );

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read board info
 *
 *   Reads a blob of data from flash.  The blob is of the following format:
 *
 *     256 bytes:     zeros (non-zero reserved for future use to indicate data format)
 *
 *	Description:\n
 *		00-01H 	0004H Main Board\n
 *			01 - Intel?Media Processor CE 2110 Development Platform\n
 *			02 - Reserved\n
 *			03 - Intel?Media Processor CE 2110 Reference Platform\n\n
 *			
 *			04 - Intel?Media Processor CE 2210 Development Platform\n
 *			06 - Intel?Media Processor CE 2210 Reference Platform\n\n
 *			
 *			07 - Intel?Media Processor CE 3100 Development Platform\n
 *			08 - Intel?Media Processor CE 3100 Silicon Validation Platform\n\n
 *			
 *			09 - Intel?Media Processor CE 4XXX DDR2 Development Platform\n
 *			0A - Intel?Media Processor CE 4XXX DDR3 Development Platform\n
 *			0B - Intel?Media Processor CE 4XXX DDR3 Silicon Validation Platform\n\n
 *
 *		02H 	Main Board SKU\n
 *			00 ?HD\n
 *			01 ?SD\n
 *			02 ?FF ?Reserved for future use\n\n
 *		03H 	00-FFH FAB\n\n
 *		This is a Hex-ASCII value (i.e. 41H = Fab A, 42H = Fab B)\n
 *		04-06H	000000H Manufacture Date\n
 *			04H	XXH	    Date - Day\n
 *			05H	XXH	    Date - Month\n
 *			06H	XXH	    Date ?Year 20XX\n\n
 *		07-0AH	CH1-SDCR0 Memory CH1 ?Config SDCR0\n
 *			07H		    Bits 31-24 (tRAS and tRP)\n
 *			08H		    Bits 23-16 (tRCD and tEDP)\n
 *			09H		    Bits 15-8 (tWDL and tCAS)\n
 *			0AH		    Bits 7-0 (DDR1/2,tRRD,2T,dqs#dis and unbuf)\n\n
 *		0B-0EH	CH1-SDCR1 Memory CH1 ?Config SDCR1\n
 *			0BH		    Bits 31-24 (tRTC and tWTCMD)\n
 *			0CH		    Bits 23-16 (tRTW and bit 5 of tRFC)\n
 *			0DH		    Bits 15-8 (tRFC, Speed and bit 5 of tRC)\n
 *			0EH		    Bits 7-0 (tRC and tWTRD)\n\n
 *		0FH 	CH1-SBR0 Memory CH1 ?Config SBR0\n
 *			0FH		    Bits 31-24 (Column bits and Row bits)\n\n
 *		10-13H	CH2-SDCR0 Memory CH2 ?Config SDCR0\n
 *			10H		    Bits 31-24 (tRAS and tRP)\n
 *			11H		    Bits 23-16 (tRCD and tEDP)\n
 *			12H		    Bits 15-8 (tWDL and tCAS)\n
 *			13H		    Bits 7-0 (DDR1/2,tRRD,2T,dqs#dis and unbuf)\n\n
 *		14-17H	CH2-SDCR1 Memory CH2 ?Config SDCR1\n
 *			14H		    Bits 31-24 (tRTC and tWTCMD)\n
 *			15H		    Bits 23-16 (tRTW and bit 5 of tRFC)\n
 *			16H		    Bits 15-8 (tRFC, Speed and bit 5 of tRC)\n
 *			17H		    Bits 7-0 (tRC and tWTRD)\n\n
 *		18H 	CH2-SBR0 Memory CH2 ?Config SBR0\n
 *			18H		    Bits 31-24 (Column bits and Row bits)\n\n
 *		19-24H	Board Serial Number\n
 *		This is a Hex-ASCII values.\n
 *		19H	XXH    	    Char 12\n
 *		1AH	XXH    	    Char 11\n
 *		1BH	XXH    	    Char 10\n
 *		1CH	XXH    	    Char 9\n
 *		1DH	XXH    	    Char 8\n
 *		1EH	XXH    	    Char 7\n
 *		1FH	XXH    	    Char 6\n
 *		20H	XXH    	    Char 5\n
 *		21H	XXH    	    Char 4\n
 *		22H	XXH    	    Char 3\n
 *		23H	XXH    	    Char 2\n
 *		24H	XXH	    	Char 1\n\n
 *		25-2AH	PBA\n
 *		This is a Hex-ASCII values.\n
 *		25H	XXH    	    Char 10\n
 *		26H	XXH    	    Char 9\n
 *		27H	XXH    	    Char 8\n
 *		28H	XXH    	    Char 7\n
 *		29H	XXH    	    Char 6\n
 *		2AH	XXH	    Char 5\n
 *		2BH	2DH	    Char 4\n
 *		2CH	XXH	    Char 3\n
 *		2DH	XXH	    Char 2\n
 *		2EH	XXH	    Char 1\n
 *		2FH-DDH	RESERVED\n
 *		DEH-DFH	CHECKSUM\n
 *		E0H-FFH RESERVED\n\n\n
 *
 *
 *     @param[out] buffer                        buffer to fill with data from flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 9584)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @return  flash_appdata_result_t			 result
 */
flash_appdata_result_t
flash_board_info_read
 (
  void *buffer,
  flash_appdata_u32_t buffer_length_bytes,
  flash_appdata_u32_t *buffer_length_read_bytes
 );

flash_appdata_result_t
flash_board_info_read2
 (
  void *buffer,
  flash_appdata_u32_t buffer_length_bytes,
  flash_appdata_u32_t *buffer_length_read_bytes,
  flash_appdata_u32_t dwflashtype   
 );

/*------------------------------------------------------------------------------------*/
/*                        ALL EXTERNAL C SYMBOLS GO ABOVE HERE                        */
/*-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-*/
#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif

#endif  /*  ndef FLASH_BOARD_INFO_INCLUDED  */

