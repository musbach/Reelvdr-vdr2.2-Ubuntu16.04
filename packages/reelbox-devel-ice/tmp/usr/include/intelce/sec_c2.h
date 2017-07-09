//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------
#ifndef SEC_C2_H
#define SEC_C2_H

#include <stdbool.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
/** @ingroup crypt
 *
 * This function allows the application to perform bulk C2 encryption or
 * decryption of data using the specified key.
 *
 * @note
 * This command is only available when the C2_Enable fuse is set in the target
 * chip.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation should be performed.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in] cipher_chain_mode
 *              Either SEC_ECB or SEC_CBC for cipher chain mode.
 *
 * @param[in] key
 *              Pointer to a buffer that contains a 56-bit key.
 *
 * @param[in] src
 *              Pointer to a buffer that contains the input data
 *
 * @param[out] dst
 *              Pointer to a buffer that will received the output data.
 *
 * @param[in] size
 *              The size in bytes of the src and dst buffers.
 *
 * @param[in] offset
 *              The offset from the base addresses of the src and dest buffers
 *              at which processing should begin.
 *
 * @retval SEC_SUCCESS              The operation is successfully.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The input pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE  The chain mode is not valid.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_c2_process_data (   sec_dev_context_t       sec_dev_context,
                        sec_cipher_mode_t       cipher_mode,
                        sec_cipher_chain_mode_t cipher_chain_mode,
                        unsigned char *         key,
                        void *                  src,
                        void *                  dst,
                        unsigned long           size,
                        unsigned long           offset);
#ifdef __cplusplus
}
#endif

#endif
