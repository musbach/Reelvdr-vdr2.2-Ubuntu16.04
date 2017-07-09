/****************************************************************************
 * INTEL CONFIDENTIAL
 * Copyright 2008-2009 Intel Corporation.  All Rights Reserved.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************/

/****************************************************************************
 *  Digital Home Group
 *  Intel Corporation
 *  2200 Mission College Blvd.
 *  Santa Clara, CA  95054-1549
 *  (408) 765-8080
 *  http://www.intel.com
 ***************************************************************************/

/*!  \file sec_crypto.h
 *
 *   Interface to libsec_crypto library.
 *
 *   The libsec_crypto library provides a function to parse generate an AES key and encrypt the data, and
 *   RSA-encrypt the AES key.  The result is an array of entries described in
 *   sec_crypto_common.h.
 */

#ifndef SEC_CRYPTO_INCLUDED
#define SEC_CRYPTO_INCLUDED

#include "libdts_security_common.h"

/* = = = = = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */

#define AES_128_BLOCK_SIZE_BYTES 16

typedef enum
  {
    AES_DECRYPT,
    AES_ENCRYPT
  }  sec_crypto_aes_crypt_t;

typedef struct sec_crypto_buffer_s
{
	sec_crypto_u8_t* array;
	sec_crypto_u32_t write_byte_pointer;
	sec_crypto_u32_t read_byte_pointer;
	sec_crypto_u32_t buffer_size_bytes;
} sec_crypto_buffer;

typedef struct sec_crypto_cmac_context_s
{
	sec_crypto_u8_t K1[AES_128_BLOCK_SIZE_BYTES];
	sec_crypto_u8_t K2[AES_128_BLOCK_SIZE_BYTES];
	sec_crypto_u8_t C[AES_128_BLOCK_SIZE_BYTES];
	sec_crypto_u8_t key[AES_128_BLOCK_SIZE_BYTES];
	sec_crypto_u8_t residual_buffer_array[AES_128_BLOCK_SIZE_BYTES];
	sec_crypto_buffer residual_buffer;
} sec_crypto_cmac_context;

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */


#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif
/*-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-vv-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-*/
/*                        ALL EXTERNAL C SYMBOLS GO BELOW HERE                        */
/*------------------------------------------------------------------------------------*/
#define K_256BIT_MAX	32

sec_crypto_status_t sec_crypto_SHA256(const void *buffer, sec_crypto_u32_t buffer_length_bytes, const void *sha256Digest);
sec_crypto_status_t sec_crypto_256BitTo128Bit(sec_crypto_u8_t *buf_256BitKey, sec_crypto_u32_t buffer_length_bytes, sec_crypto_u8_t *lsb_128BitKey, sec_crypto_u8_t *msb_128BitKey);
sec_crypto_status_t sec_crypto_CMACSignature(sec_crypto_u8_t* key, const void *buffer, sec_crypto_u32_t buffer_length_bytes, sec_crypto_u8_t*cmacSignature);
sec_crypto_status_t sec_crypto_AES_ecb(const void *buffer, sec_crypto_u32_t buffer_length_bytes, const void *sha256Digest);
sec_crypto_status_t sec_crypto_AES128_cbc(sec_crypto_u8_t *k_key, unsigned char *iv, const void *inBuffer, sec_crypto_u32_t buffer_length_bytes, const void *outBuffer, int encrypted);


/*------------------------------------------------------------------------------------*/
/*                        ALL EXTERNAL C SYMBOLS GO ABOVE HERE                        */
/*-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-*/
#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif

#endif  /*  ndef AACSKL_INPUT_INCLUDED  */

