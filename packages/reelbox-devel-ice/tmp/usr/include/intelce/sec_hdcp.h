//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_HDCP_H
#define SEC_HDCP_H
#include <stdbool.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
/** @ingroup hdcp
 *
 * @par ON THE CE3100
 * This function must be invoked by the manufacturer application in the
 * factory to bind the encrypted HDCP keys to the platform. This function
 * should only be used on initial power-up in the OEM/ODM factory and,
 * potentially, during in-the-field updates.
 *
 * @par ON OTHER SOCs
 * This function is not supported.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] iv
 *              Pointer to a 16-byte Initialization Vector.
 *
 * @param[in] encrypted_input_key_blob
 *              Pointer to a buffer containing the encrypted HDCP key module
 *              in little endian format.
 *
 * @param[out] rewrapped_key_blob
 *              Pointer to a buffer that will receive the rewrapped HDCP key
 *              module.
 *
 * @param[in] key_blob_size
 *              The size, in bytes, of the encrypted_input_key_blob and
 *              rewrapped_key_blob buffers.
 *
 * @retval SEC_SUCCESS                  The operation is successfully.
 * @retval SEC_FAIL                     The operation is failed.
 * @retval SEC_INVALID_CONTEXT          SEC context is invalid.
 * @retval SEC_NULL_POINTER             The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE        Invalid key_blob_size size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_rewrap_hdcp_module_keys(sec_dev_context_t   sec_dev_context,
                            void *              iv,
                            void *              encrypted_input_key_blob,
                            void *              rewrapped_key_blob,
                            unsigned int        key_blob_size);

//-----------------------------------------------------------------------------
/** @ingroup hdcp
 *
 * This function is used to securely decrypt and store an HDCP Key Module.
 * The display driver's HDMI port driver is responsible for invoking this
 * function for operation of HDCP content protection on the HDMI outputs.
 *
 * The source of the encrypted key blob and initialization vector varies
 * depending on the host SOC.
 *
 *  @par On the CE3100
 *  These items must be passed as parameters to this call.
 *
 *  @par On other SOCs
 *  These items are burned into one-time programming NVMEM in the chip during
 *  manufacturing, and the SEC firmware accesses them there.  The
 *  corresponding arguments to this function are ignored.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] iv
 *              Pointer to a 16-byte Initialization Vector.
 *              THIS PARAMETER IS REQUIRED ON THE CE3100, IGNORED OTHERWISE.
 *
 * @param[in] encrypted_key_blob
 *              Pointer to a buffer containing the encrypted HDCP key module.
 *              THIS PARAMETER IS REQUIRED ON THE CE3100, IGNORED OTHERWISE.
 *
 * @param[in] key_blob_size
 *              The size, in bytes, of the encrypted_input_key_blob.
 *              THIS PARAMETER IS REQUIRED ON THE CE3100, IGNORED OTHERWISE.
 *
 * @retval SEC_SUCCESS              The operation is successfully.
 * @retval SEC_FAIL                 The operation is failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The input pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp_decrypt_and_load_keys( sec_dev_context_t   sec_dev_context,
                                void *              iv,
                                void *              encrypted_key_blob,
                                unsigned int        key_blob_size);

//-----------------------------------------------------------------------------
/** @ingroup hdcp
 *
 * This function is used to hash and verify the HDCP KSV list. Application
 * software installed by the Set Top Box manufacturer is responsible for
 * invoking this function as part of HDCP authentication when a HDCP Repeater
 * device is attached.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] ksv_list_bstatus
 *              Pointer to a buffer where the start of the concatenated KSV
 *              list and Bstatus buffer are stored.
 *
 * @param[in] ksv_list_bstatus_size
 *              The length, in bytes if the ksv_list_bstatus buffer.
 *
 * @param[in] v_prime
 *              Pointer to a buffer containing the input hash value.
 *
 * @param[out] success
 *              TRUE returned here if the HDCP KSV is authenticated, FALSE if
 *              the HDCP KSV is failed with authentication or any error occurs.
 *
 * @retval SEC_SUCCESS              The operation is successfully.
 * @retval SEC_FAIL                 The operation is failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid ksv_list_bstatus_size size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp_verify_KSV_list(   sec_dev_context_t   sec_dev_context,
                            void *              ksv_list_bstatus,
                            unsigned int        ksv_list_bstatus_size,
                            void *              v_prime,
                            bool *              success);

#ifdef __cplusplus
}
#endif

#endif
