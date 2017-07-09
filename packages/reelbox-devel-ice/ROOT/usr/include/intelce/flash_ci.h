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

#ifndef FLASH_CI_INCLUDED
#define FLASH_CI_INCLUDED

#include <stdio.h>
#include "flash_appdata_defs.h"

#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif

#define CI_TYPE 0x00003001

//Constants
#define MAX_ERROR_SZ                    0x400
#define MAX_KEY_FAMILY_NAME_SZ          16
#define MAX_SERIAL_NUMBER_SZ            20
#define MAX_USER_ID_SZ                  10
#define MAX_ERR                         4

#define CPUID_SERIALNUM_BYTES        12
#define CI_KEY_CONTAINER_BYTES       256
#define CI_HEADER_BYTES              16
#define CI_IV_BYTES                  16
#define CI_SLK_BYTES                 16
#define CI_SIV_BYTES                  16
#define CI_CLK_BYTES                 16
#define CI_RESERVE_BYTES             160
#define CI_CMAC_BYTES                16

#define CI_HEADER_OFFSET       0
#define CI_IV_OFFSET           16
#define CI_SLK_OFFSET          32
#define CI_SIV_OFFSET          48
#define CI_CLK_OFFSET          64
#define CI_RESERVE_OFFSER      80
#define CI_CMAC_OFFSET         240

enum enum_ci_type
{
        CI,

        //always last
        CI_COUNT
};

const char *g_szCITypeStr[CI_COUNT] = {
        "CI+",
};

const char *g_szCI_Key_Flags[32] = {
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
        flash_appdata_u32_t             moduleType;     // CI Confidential Key Data Flash Module Type = 0x00003001
        flash_appdata_u32_t             revisionNumber; // Initial Revision = 0x00000001 
        flash_appdata_u32_t             keyFlags;       // Bit 0 = WMDRM Model Keys Present 
                                                        // Bit 1 = Playready Model Keys present
                                                        // Bit 31:2 = Reserved
        flash_appdata_u32_t             keyGenDate;     // BCD representation of date as yyyymmdd where yyyy=4 digit year, mm=1-12, dd=1-31
}ci_header_t;


typedef struct ci_key
{
        uint32_t    module_id;
        uint32_t    revision;
        uint32_t    flags;
        uint32_t    timestamp;
        uint8_t     iv[16];
        uint8_t     skl[16];
        uint8_t     siv[16];
        uint8_t     clk[16];
        uint8_t     reserved[160];
        uint8_t     cmac[16];
} ci_key_t;

/*-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-vv-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-*/
/*                        ALL EXTERNAL C SYMBOLS GO BELOW HERE                        */
/*------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------*/
/*                        ALL EXTERNAL C SYMBOLS GO ABOVE HERE                        */
/*-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-*/
#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif

#endif  /*  ndef *_INCLUDED  */

