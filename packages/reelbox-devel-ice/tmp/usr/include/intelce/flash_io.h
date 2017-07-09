/****************************************************************************
 * Copyright (c) 2008-2010 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_io.h
 ***************************************************************************/

#ifndef _FLASH_IO_H_
#define _FLASH_IO_H_

#include "flash_appdata_defs.h"
#include "pal.h"

#define PLATFORM_CONFIG_NAND_BLOCK_START 48
#define PLATFORM_CONFIG_NAND_BLOCK_COUNT 8

// Core flash_appdata APIs
flash_appdata_result_t flash_chkgetdest(FAD_FLASH_TYPE inputflash, pal_soc_name_t *destsoc, FAD_FLASH_TYPE *destflash);
flash_appdata_result_t flash_read(u8 * buffer, u32 buffer_size, u32 offset);
flash_appdata_result_t flash_read2(u8 * buffer, u32 buffer_size, u32 offset, int type);
flash_appdata_result_t flash_write(u8 * buffer, u32 buffer_size, u32 offset);
flash_appdata_result_t flash_write2(u8 * buffer, u32 buffer_size, u32 offset, int type);
flash_appdata_result_t flash_nor_type(FLASH_NOR_TYPE * type);
flash_appdata_result_t flash_nor_secret_io(int read_not_write, u8* buffer, u32 buffer_size, u32 offset);
flash_appdata_result_t flash_nor_io(int read_not_write, u8 * buffer, u32 buffer_size, u32 offset);
flash_appdata_result_t flash_nand_io(int read_not_write, u8 * buffer, u32 buffer_size, u32 offset);
flash_appdata_result_t fad_emmc_io(int read_not_write, u8 * buffer, u32 buffer_size, u32 offset);


#endif
