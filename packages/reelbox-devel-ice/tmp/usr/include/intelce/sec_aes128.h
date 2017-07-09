//-----------------------------------------------------------------------------
// Copyright (c) 2010-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_AES128_H
#define SEC_AES128_H
#include <stdbool.h>
#include <stdint.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//--  sec_aes128_process_data  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function performs bulk AES encryption or decryption of data, but only
 * supports 128-bit keys. The application should use sec_set_sym_key() to set
 * the AES key and initialization vector (requried by CBC mode) before calling
 * this function. For Chiper Block Chaining (CBC) mode, the state information
 * is kept in the SEC context after each sec_aes_process_data() call for 
 * continuous encryption/decrytion operation.  
 *
 * For Cipper Block Chaining (CBC) mode, the state information is saved in the
 * SEC context after each sec_aes_process_data call to support continuous 
 * encryption/decrytion operations.
 *
 * @note
 * Since this is a synchronous function call, the application or thread should
 * be careful not to block other applications or threads trying to use this API.
 *
 * @note
 * Applications may provide src and dst buffer pointers that are byte aligned.
 * However, DWORD (32-bit) aligned buffer pointers are recommended for best
 * performance.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in] src
 *              A pointer to a buffer containing the input data.
 *
 * @param[out] dst
 *              A pointer to a buffer that will receive the output data.
 *
 * @param[in] size
 *              The length of the src and dst buffers, in bytes. The actual 
 *              length (size minus offset) of input data to be processed must
 *              be multiple of 16 bytes.
 *
 * @param[in] offset
 *              The offset from the beginning of the src and dst buffers
 *              at which the operation should begin.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The src or dst pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE  Invalid cipher mode.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 * @retval SEC_INVALIDE_DATA_LEGNTH The actual length of input data to be
 *                                  processed in not a multiple of 16 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 16 bytes)
 * @retval SEC_NOT_SUPPORTED        Called on unsupported hardware.
 * @retval SEC_INVALID_CHAIN_MODE   Invalid chain mode.
 * @retval SEC_INVALID_KEY_LENGTH   Key length was not 128-bit.
 * @retval SEC_NOT_IMPLEMENTED_YET  Future hardware will support this.
 * @retval SEC_INVALID_KEY_LOCATION Hardware does not support supplied key
 *                                  location.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aes128_process_data(    sec_dev_context_t   sec_dev_context,
                            sec_cipher_mode_t   cipher_mode,
                            void *              src,
                            void *              dst,
                            unsigned long       size,
                            unsigned long       offset);

#endif /* SEC_AES128_H */