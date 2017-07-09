//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------
#ifndef SEC_CSS_H
#define SEC_CSS_H
#include <stdbool.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//---  sec_css_process_data  --------------------------------------------------
/** @ingroup crypt
 *
 * This function performs bulk CSS decryption of data using the specified key.
 *
 * @note
 * This command is only available when the CSS_Enable fuse is set on the
 * target chip.
 *
 * @param[in] sec_dev_context
 *              The SEC context in which the operation is performed.
 *
 * @param[in] title_decrypt_key
 *              Pointer to a buffer containing the 40-bit Title Decryption Key.
 *
 * @param[in] title_key_conversion
 *              Pointer to a buffer containing the 40-bit Title Key Conversion.
 *
 * @param[in] src
 *              Pointer to a buffer containing the input data.
 *
 * @param[out] dst
 *              Pointer to a buffer that will receive the output data.
 *
 * @param[in] size
 *              The size, in bytes, of the src and dst buffers.
 *
 * @param[in] offset
 *              The offset from the base address of the src and dest buffers at
 *              which to begin processing.
 *
 * @retval SEC_SUCCESS              The operation is successfully.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 */
 //----------------------------------------------------------------------------
sec_result_t
sec_css_process_data (  sec_dev_context_t   sec_dev_context,
                        unsigned char *     title_decrypt_key,
                        unsigned char *     title_key_conversion,
                        void *              src,
                        void *              dst,
                        unsigned long       size,
                        unsigned long       offset);
#ifdef __cplusplus
}
#endif

#endif
