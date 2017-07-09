//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_HDCP_RX_H
#define SEC_HDCP_RX_H
#include <stdbool.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
/** @ingroup hdcp_rx
 *
 * This function is used to securely decrypt and store an HDCP Key Module for
 * the RX.
 *
 * Currently, due to HW/FW limitiations, it also decrypts and loads the for
 * the HDCP TX as well.  This may change in a future revision if a means to
 * separate the RX and TX initialization becomes available.  Therefore,
 * client SW should not make any assumptions about whether or not the TX
 * is impacted by this function.
 *
 * This function returns soon after the SEC IPC command completes.  The
 * corresponding initialization of the HDCP RX (and possibly TX) might not
 * be completed yet.
 *
 * In addition to the listed values, other failing return codes are possible.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @retval SEC_SUCCESS              The operation was successful.
 * @retval SEC_NOT_SUPPORTED        The operation is not supported.
 * @retval SEC_FAIL                 The operation has failed.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp_rx_decrypt_and_load_keys( sec_dev_context_t   sec_dev_context );

//-----------------------------------------------------------------------------
/** @ingroup hdcp_rx
 *
 * This function is used to generate the hash of the HDCP KSV list. The
 * Security Controller retrieves the HDCP 'M0' value from the HDCP RX Unit,
 * calculates the hash and returns the HDCP 'V' value to the HDCP RX Unit.
 *
 * ksv_buffer is 5 bytes per KSV.  Each KSV is in little endian byte order.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] ksv_buffer
 *              Pointer to a buffer containing the KSV List.  Each KSV is
 *              5 bytes and in little endian byte order.
 *
 * @param[in] num_ksvs
 *              The number of KSVs in the KSV List pointed to by ksv_buffer.
 *
 * @param[in] bstatus
 *              Bstatus.
 *
 * @retval SEC_SUCCESS              The operation was successful.
 * @retval SEC_FAIL                 The operation has failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid ksv_list_bstatus_size size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp_rx_generate_v( sec_dev_context_t   sec_dev_context,
                        const void *        ksv_buffer,
                        unsigned int        num_ksvs,
                        unsigned int        bstatus );

#ifdef __cplusplus
}
#endif

#endif

