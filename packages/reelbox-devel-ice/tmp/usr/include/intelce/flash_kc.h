/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_kc.h
 ***************************************************************************/

#ifndef FLASH_KC_H
#define FLASH_KC_H

#include <stdio.h>
#include <stdbool.h>
#include "flash_appdata_defs.h"
#include "flash_appdata_memmap.h"

#if defined(PLAT_CE21XX)
    static const unsigned int CONFIG_BASE = 0xFFFE0B00;
    static const unsigned int CONFIG_STS1 = 0x8C;
#else
    // These are DFX Register Values
    //common values CE31XX CE41XX
    #define CE31_41XX_DFX_MBAR        0xDF8F0000
    #define CE31_41XX_SERIAL_NUMBER 0x00000044
#endif

#define GKEK_MAX          16    // AES-128 Bits (16 Bytes) CBC Initialization Vector for Encryption/Decryption.
#define IV_MAX            16    // AES-128 Bits (16 Bytes) CBC Initialization Vector for Encryption/Decryption.
#define SIGNATURE_MAX     16    // AES-128 Bits (16 Bytes) CMAC signature of header & body using a secret key.

/*!
 *  Structure to store the Random Initialization Vector when in CBC mode.
 *  @struct iv_t
 */
typedef struct 
{
   flash_appdata_u8_t iv[IV_MAX]; // AES-128 Bits (16 Bytes) CBC Initialization Vector for Encryption/Decryption.
}iv_t;

enum enum_key_algo_mode
{
        RSAES_OAEP = 0x0,
        RSAES_PKCS1 = 0x1,
        RSASSA_PSS = 0x2,
        
        MODE_COUNT
};

const char *g_szAlgoMode[MODE_COUNT] = {
    "RSAES_OAEP",
    "RSAES_PKCS1_V1.5",
    "RSASSA_PSS",
};

enum enum_key_encryption_type
{
    KEY_ENCR_PLAINTEXT,
    KEY_ENCR_INTEL_GKEK,
    KEY_ENCR_CUSTOMER_GKEK,
    KEY_ENCR_INTERNAL_KEY_STORE,
    KEY_ENCR_PROVISION,
    KEY_ENCR_OEM,

    // this entry should always be last
    KEY_ENCR_COUNT
};

const char *g_szKeyEncryptionType[KEY_ENCR_COUNT] = {
    "Plaintext",
    "Intel",
    "Customer",
    "Internal",
    "Provision",
    "OEM",
};

enum enum_key_type
{
    KEY_DES     = 0,
    KEY_AES     = 0x1,
    KEY_C2      = 0x2,
    KEY_CSS     = 0x3,
    KEY_RC4     = 0x4,
    KEY_RSA     = 0x5,
    KEY_EC      = 0x6,
    KEY_PR_SEED = 0x7,
    KEY_HMAC    = 0x8,
    KEY_DH_GROUP = 0x9,
    KEY_DH_SESSION = 0xA,  // Not a provisioned keytype, but for tracking purpse
    KEY_DRM_SEED = 0xB,

    // this entry should always be last
    KEY_COUNT
};

const char *g_szKeyType[KEY_COUNT] = {
    "DES",
    "AES",
    "C2",
    "CSS",
    "RC4",
    "RSA",
    "EC",
    "PR_SEED",
    "HMAC",
    "DH_GROUP",
    "DH_SESSION",
    "DRM_SEED",
};

// DES (8, 16, 24) Key Size Bytes
typedef enum
{
    DES_KS_8 = 8,
    DES_KS_16 = 16,
    DES_KS_24 = 24,
}DES_KEY_SIZE;

// AES (16, 24, 32) Key Size Bytes
typedef enum
{
    AES_KS_16 = 16,
    AES_KS_24 = 24,
    AES_KS_32 = 32,
}AES_KEY_SIZE;

// C2 (7) Key Size Bytes
typedef enum
{
    C2_KS_7 = 7,
}C2_KEY_SIZE;

// CSS (12) Key Size Bytes
typedef enum
{
    CSS_KS_12 = 12,
}CSS_KEY_SIZE;

// RC4 (256) Key Size Bytes
typedef enum
{
    RC4_KS_256 = 256,
}RC4_KEY_SIZE;

// RSA (only a total public/private key size of 260 and 516 bytes are allowed which equates to a modulus size of 128 and 256 respectively)
typedef enum
{
    RSA_KS_260 = 260,
    RSA_KS_516 = 516,
}RSA_KEY_SIZE;

#define RSA_KS_260_MODULUS        128
#define RSA_KS_260_PRIVATE        128
#define RSA_KS_260_PUBLIC         4

#define RSA_KS_516_MODULUS        256
#define RSA_KS_516_PRIVATE        256
#define RSA_KS_516_PUBLIC         4

// EC (only a total public/private/parameter size of 180, 216, 252, 288 bytes are allowed which equates to a modulus size of 20, 24, 28, 32 respectively)
typedef enum
{
    EC_KS_180 = 180,
    EC_KS_216 = 216,
    EC_KS_252 = 252,
    EC_KS_288 = 288,
}EC_KEY_SIZE;


typedef enum
{
    PR_SEED_KS_16 = 16,
}PR_SEED_KEY_SIZE;

typedef enum
{
        HMAC_KS_MIN = 16,
        HMAC_KS_MAX = 128,
}HMAC_KEY_SIZE;

// DH keys size will be equal to modulus*3.  So for 64 bit key, the total keysize will be 64*3
typedef enum
{
        DH_GROUP_KS_64 = 64 * 3,
        DH_GROUP_KS_128 = 128 * 3,
        DH_GROUP_KS_256 = 256 * 3,
}DH_GROUP_KEY_SIZE;

typedef enum
{
        DRM_SEED_KS_16 = 16,
}DRM_SEED_SIZE;


#define EC_KS_180_MODULUS        EC_KS_180/9                // EC Modulus
#define EC_KS_180_A              EC_KS_180/9                // EC parameter A
#define EC_KS_180_B              EC_KS_180/9                // EC parameter B
#define EC_KS_180_Gx             EC_KS_180/9                // EC parameter Gx
#define EC_KS_180_Gy             EC_KS_180/9                // EC parameter Gy
#define EC_KS_180_R              EC_KS_180/9                // EC parameter R
#define EC_KS_180_PRIVATE        EC_KS_180/9                // EC Private Key scalar
#define EC_KS_180_PUBLIC         EC_KS_180_PRIVATE * 2    // EC Public Key Point

#define EC_KS_216_MODULUS        EC_KS_216/9                // EC Modulus
#define EC_KS_216_A              EC_KS_216/9                // EC parameter A
#define EC_KS_216_B              EC_KS_216/9                // EC parameter B
#define EC_KS_216_Gx             EC_KS_216/9                // EC parameter Gx
#define EC_KS_216_Gy             EC_KS_216/9                // EC parameter Gy
#define EC_KS_216_R              EC_KS_216/9                // EC parameter R
#define EC_KS_216_PRIVATE        EC_KS_216/9                // EC Private Key scalar
#define EC_KS_216_PUBLIC         EC_KS_216_PRIVATE * 2    // EC Public Key Point

#define EC_KS_252_MODULUS        EC_KS_252/9                // EC Modulus
#define EC_KS_252_A              EC_KS_252/9                // EC parameter A
#define EC_KS_252_B              EC_KS_252/9                // EC parameter B
#define EC_KS_252_Gx             EC_KS_252/9                // EC parameter Gx
#define EC_KS_252_Gy             EC_KS_252/9                // EC parameter Gy
#define EC_KS_252_R              EC_KS_252/9                // EC parameter R
#define EC_KS_252_PRIVATE        EC_KS_252/9                // EC Private Key scalar
#define EC_KS_252_PUBLIC         EC_KS_252_PRIVATE * 2    // EC Public Key Point

#define EC_KS_288_MODULUS        EC_KS_288/9                // EC Modulus
#define EC_KS_288_A              EC_KS_288/9                // EC parameter A
#define EC_KS_288_B              EC_KS_288/9                // EC parameter B
#define EC_KS_288_Gx             EC_KS_288/9                // EC parameter Gx
#define EC_KS_288_Gy             EC_KS_288/9                // EC parameter Gy
#define EC_KS_288_R              EC_KS_288/9                // EC parameter R
#define EC_KS_288_PRIVATE        EC_KS_288/9                // EC Private Key scalar
#define EC_KS_288_PUBLIC         EC_KS_288_PRIVATE * 2    // EC Public Key Point

const char *g_szSignVerify_EncryptDecrypt_Rights[16] = {
    "Decrypt Data",
    "Encrypt Data",
    "Decrypt Keys",
    "Encrypt Keys",
    "Reserved    ",
    "Reserved    ",
    "Reserved    ",
    "Reserved    ",
    "Sign Data   ",
    "Verify Data ",
    "Sign Keys   ",
    "Verify Keys ",
    "Reserved    ",
    "Reserved    ",
    "Reserved    ",
    "Reserved    ",
};

const char *g_szKey_Flags[8] = {
    "To Be Provisioned",
    "Provisioning Key ",
    "Reserved         ",
    "Reserved         ",
    "Reserved         ",
    "Reserved         ",
    "Reserved         ",
    "Reserved         ",
};

const char *g_szKey_Algo_Mode[32] = {
        "RSAES-OAEP      ",
        "RSAES-PKCS1-v1.5",
        "RSASSA-PSS      ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
        "Reserved        ",
};
        
/*!
 * Struct to store pointers to the next blob to defrag after removing keys
 */
struct defrag_entry
{
    uint32_t                blobSize;
    uint32_t                ptr;
    flash_appdata_u32_t     keyID;
    struct defrag_entry     *next;
};                    
    
    
/*!
 *  Structure to store the Key Container Header.
 *  @struct kc_header
 */
typedef struct
{
    flash_appdata_u32_t       number;                // Number of Key Containers in file
    flash_appdata_u8_t        reserved1[12];
}kc_file_header_t;


/*!
 *  Structure to store the Key Container General Information.
 *  @struct kc_info
 */
typedef struct  
{
    flash_appdata_u8_t         numKeyContainers;
    flash_appdata_u32_t        siliconCPUid;
    flash_appdata_u64_t        siliconSerialNumber;
}kc_info;


/*!
 *  Structure to store the Key Container Header.
 *  @struct kc_header
 */
typedef struct
{
    flash_appdata_u8_t        keyType;              // Key Types supported are defined in enum KEY_TYPES
    flash_appdata_u8_t        encrypt_decryptRights;// Bitmask which specifies the usage allowed for bulk crypto (Decrypt/Encrypt Data) 
                                                    // or key load/provisioning (Decrypt/Encrypt Keys) operations.
                                                    // Bit 0 - Decrypt Data
                                                    // Bit 1 - Encrypt Data
                                                    // Bit 2 - Decrypt Keys
                                                    // Bit 3 - Encrypt Keys
                                                    // Bit 4 - 7 Reserved
    flash_appdata_u8_t        sign_verifyRights;    // Bitmask which specifies the usage allowed for sign/verify operations for data (RSA Sign/Verify, HMAC, etc) 
                                                    // or key load/provisioning (Sign/Verify Keys).
                                                    // Bit 0 - Sign Data
                                                    // Bit 1 - Verify Data
                                                    // Bit 2 - Sign Keys
                                                    // Bit 3 - Verify Keys
                                                    // Bit 4 - 7 Reserved
    flash_appdata_u8_t        keyFlags;             // Bitmask which specifies the usage allowed for Provision data
                                                    // Bit 0 - To Be Provisioned - Key that is going to be loaded and tied to the chip-unique key 
                                                    //                             by ProvisionKey command. Keys with this flag set will be by 
                                                    //                             rejected the LoadKey command.
                                                    // Bit 1 - Provisioning Key -- Key can only be used to decrypt keys during the ProvisionKey command. 
                                                    // Bit 2 - 7 Reserved
    flash_appdata_u32_t        keySize;             // The key size of the Body
    flash_appdata_u32_t        keyID;               // ID to be used by the user for key identification. This field is ignored by the firmware.
    flash_appdata_u32_t        mode;                // Algorithm-specific flags
                                                    // RSA:
                                                    //   Bit 0 – 0 -> RSAES-OAEP
                                                    //           1 -> RSAES-PKCS1-v1.5
                                                    //           2 -> RSASSA-PSS
                                                    //   All other bits for RSA are reserved.
                                                    //   All bits for other algorithms are reserved.
}kc_header_t;

    flash_appdata_u8_t         keyType;                // Key Types supported are defined in enum KEY_TYPES

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
/*!  \brief Write Key Container data to flash
 *   This will select which type of flash
 *
 *   Writes a Key Container data to flash.  The data is of the following format:
 *
 *     @param[in] keyID                          Key Identification used to find the correct Key Container to used. 
 *     @param[in] buffer                         buffer of data to write to flash
 *     @param[in] buffer_length_bytes            number of bytes to write (must be 9584)
 *     @param[in] dwflashtype                    flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 */
flash_appdata_result_t 
flash_kc_write_key_info
 ( 
 const void             *buffer, 
 flash_appdata_u32_t    buffer_length_bytes,
 FAD_FLASH_TYPE         dwflashtype
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Key Container data from flash
 *   This will select which type of flash
 *
 *   Read a Key Container data from flash.  The data is of the following format:
 *
 *     @param[in]  keyID                         Key Identification used to find the correct Key Container to used. 
 *     @param[out] buffer                        buffer to fill with data from flash
 *     @param[in]  buffer_length_bytes           number of bytes to write (must be 9584)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @param[in]  dwflashtype                   flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_NO_DATA             No data stored in flash.
 *     @retval FLASH_APPDATA_UNMATCH_DATA        No data matches with what is stored in flash.
 */
flash_appdata_result_t 
flash_kc_read_key_info
 (
 bool                   load_key,
 flash_appdata_u32_t    keyID,
 flash_appdata_u32_t    *number_of_keys, 
 void                   *buffer, 
 flash_appdata_u32_t    *buffer_length_read_bytes,
 FAD_FLASH_TYPE         dwflashtype
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Key Container Header Information from flash
 *   This will select which type of flash
 *   Defragment of the block will occur each time an erase of a Key Container.
 *
 *   Read a Key Container data from flash.  The data is of the following format:
 *
 *     @param[in]  keyID                         Key Identification used to find the correct Key Container to used. 
 *     @param[in]  dwflashtype                   flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 */
flash_appdata_result_t 
flash_kc_erase_key_info
 (
 flash_appdata_u32_t    keyID, 
 FAD_FLASH_TYPE         dwflashtype
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Key Container data from flash
 *   This will select which type of flash
 *   This will return number of keys, silicon cpu id, and serial number stored in flash.
 *
 *   Read a Key Container data from flash.  The data is of the following format:
 *
 *     @param[out]  kc_info_header               Key Container Information Header structure 
 *     @param[in]  dwflashtype                   flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_NO_DATA             No data stored in flash.
 *     @retval FLASH_APPDATA_UNMATCH_DATA        No data matches with what is stored in flash.
 */
flash_appdata_result_t
flash_kc_read_info_header
 (
 kc_info        *kc_info_header, 
 FAD_FLASH_TYPE dwflashtype 
 );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Key Container raw data from flash
 *   This will select which type of flash
 *
 *   Read a Key Container raw data from flash.  The data is of the following format:
 *
 *     @param[out] buffer                         buffer to fill with data from flash
 *     @param[in]  offset                         offset read into buffer
 *     @param[in]  buffer_length_bytes            number of bytes read into buffer
 *     @param[in]  dwflashtype                    flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_PARAM_SIZE          Invalid value parameter size.
 */
flash_appdata_result_t 
flash_kc_read_raw_data
 (
 void                   *buffer, 
 flash_appdata_u32_t    offset,
 flash_appdata_u32_t    buffer_length_bytes,
 FAD_FLASH_TYPE         dwflashtype
);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

 /* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write CPU ID
 *
 *   Writes Silicon CPU ID to flash.
 *
 *     @param[in]  buffer                        buffer of 64-bits of serial number to write to flash
 *     @param[in]  buffer_length_bytes           number of bytes to write (must be 8 bytes)
 *     @param[in]  dwflashtype                   flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_PARAM_SIZE          Invalid value parameter size.
 */
flash_appdata_result_t
 flash_kc_write_cpu_id
 (
 const void             *buffer, 
 flash_appdata_u32_t    buffer_length_bytes,
 FAD_FLASH_TYPE         dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read CPU ID
 *
 *   Reads Silicon CPU ID from flash.
 *
 *     @param[out] buffer                        buffer to write 64-bits of cpu id from flash
 *     @param[in]  buffer_length_bytes           number of bytes to read (must be >= 8)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @param[in]  dwflashtype                   flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_PARAM_SIZE          Invalid value parameter size.
 */
flash_appdata_result_t
 flash_kc_read_cpu_id
 (
 void                   *buffer, 
 flash_appdata_u32_t    buffer_length_bytes, 
 flash_appdata_u32_t    *buffer_length_read_bytes,
 FAD_FLASH_TYPE         dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Write Serial Number to flash
 *
 *   Writes SEC Serial Number to flash.
 *
 *     @param[in]  buffer                        buffer of 64-bits of serial number to write to flash
 *     @param[in]  buffer_length_bytes           number of bytes to write (must be 8 bytes)
 *     @param[in]  dwflashtype                   flash type to write Key Container to (0 is NOR, 1 is NAND, and 0xFF is use boot strap)
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_PARAM_SIZE          Invalid value parameter size.
 */
flash_appdata_result_t
 flash_kc_write_serial_number
 (
 const void             *buffer, 
 flash_appdata_u32_t    buffer_length_bytes,
 FAD_FLASH_TYPE         dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Read Serial Number from flash
 *
 *   Reads SEC Serial Number from flash.
 *
 *     @param[out] buffer                        buffer to write 64-bits of serial number from flash
 *     @param[in] buffer_length_bytes            number of bytes to read (must be >= 8)
 *     @param[out] buffer_length_read_bytes      number of bytes read into buffer
 *     @retval FLASH_APPDATA_SUCCESS             The operation is successfully.
 *     @retval FLASH_APPDATA_FAIL                The operation is failed.
 *     @retval FLASH_APPDATA_INVALID_PARAM       Invalid value for parameter.
 *     @retval FLASH_APPDATA_PARAM_SIZE          Invalid value parameter size.
 */
flash_appdata_result_t
 flash_kc_read_serial_number
 (
 void                   *buffer, 
 flash_appdata_u32_t    buffer_length_bytes, 
 flash_appdata_u32_t    *buffer_length_read_bytes,
 FAD_FLASH_TYPE         dwflashtype
 );

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Retrieve Flash and Device Type
 *
 *   Retrieve Flash and Device Type.
 *
 *     @param[in/out] flash          flash type (NOR, NAND, and DEF_FLASH) If DEF_FLASH passed in then actual value that is used is returned
 *     @param[out] device            device type (GEN3, GEN4, and GEN5) There is no default value
 *     @return  nothing
 */
//flash_appdata_result_t flash_kc_type(FLASH_TYPE * flash, DEVICE_TYPE * device);

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

#endif  /*  FLASH_KC_H  */

