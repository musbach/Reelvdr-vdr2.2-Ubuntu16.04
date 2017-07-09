//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#include <stdbool.h>
#include "sec_types.h"
#include "ttb/sec_ttb_cmds.h"


//--  sec_init_ttb_type1_nonce  ------------------------------------------------
/**
 * This function must be called first during Type1 initialization. The time
 * server uses this nonce while computing RSA signature. Nonce will be little
 * endian format.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 * @param[out] ttb_nonce_ptr
 *              pointer to buffer that will contain the nonce after function call.
 *
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_NULL_POINTER     The ttb_nonce_ptr is NULL.
 * @retval SEC_INVALID_CONTEXT  The SEC device context is invalid.
 *
 */
//------------------------------------------------------------------------------
sec_result_t
sec_init_ttb_type1_nonce(sec_dev_context_t       sec_dev_context,
                         void                    *ttb_nonce_ptr) ;


//-- sec_init_ttb_type1_verify_sign  -------------------------------------------
/**
 * This function is second step in Type1 initialization. The time server
 * returns updated TTB and a HMAC signature of updated TTB.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 * @param[in] new_ttb_ptr
 *              pointer to 256 bit TTB buffer that time server has created.
 * @param[in] new_ttb_rsa_sign_ptr
 *              pointer to 256 byte RSA signature buffer that time server has
 *              computed. Time Server computes RSA_Sign(Nonce||NewTTB, TrustedB-
 *              -oot_priv_key)
 * @param[out] new_ttb_ret_ptr
 *              pointer to 256 bit(32 byte) TTB buffer that Intel CE platform
 *              will return with updated MTB and Normalization Coefficient fields
 *              in TTB.
 * @param[out] new_ttb_ret_hmac_sign_ptr
 *              pointer to 256 bit(32 byte) HMAC signature buffer that Intel CE
 *              platform will compute and return. The HMAC sign is computed using
 *              Ke obtained during encrypted S1 trusted boot.


 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_NULL_POINTER     One of the pointer arguments 2-5 is NULL.
 * @retval SEC_INVALID_CONTEXT  The SEC device context is invalid.
 * @retval SEC_OUT_OF_MEMORY    Unable to allocate memory.
 */
//------------------------------------------------------------------------------
sec_result_t
sec_init_ttb_type1_verify_sign(sec_dev_context_t   sec_dev_context,
                               void                *new_ttb_ptr,
                               void                *new_ttb_rsa_sign_ptr,
                               void                *new_ttb_ret_ptr,
                               void                *new_ttb_ret_hmac_sign_ptr);


//-- sec_init_ttb_type2  -------------------------------------------------------
/**
 * This function is used to initialize the TTB after power is lost to the system,
 * but NOT the CMOS battery backed well. This command is not available to the
 * Host after power is lost to the CMOS battery backed well. (Type 1 initializa-
 * -tion is required in this case).
 *
 * Note: Starting from CE 4100 B0, the TRC (tamper resistant clock) is
 * powered with wall power instead of battery power. So sec_init_ttb_type2 will
 * not be required.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 * @param[in] flash_ttb_ptr
 *              pointer to 256 bit TTB buffer.
 * @param[in] flash_ttb_sign_ptr
 *              pointer to 256 bit buffer containing HMAC signature of TTB
 *              buffer.
  * @param[out] is_hmac_sign_verified
 *              pointer to 1 byte buffer that Intel CE platform
 *              will return indicating if signature was verified and loaded
 *              successfully(1). 0 indicates signature verification has failed.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_NULL_POINTER     One of the pointer arguments 2-5 is NULL.
 * @retval SEC_INVALID_CONTEXT  The SEC device context is invalid.
 * @retval SEC_OUT_OF_MEMORY    Unable to allocate memory.
 */
//------------------------------------------------------------------------------
sec_result_t
sec_init_ttb_type2(sec_dev_context_t      sec_dev_context,
                               void       *flash_ttb_ptr,
                               void       *flash_ttb_sign_ptr,
                            uint8_t       *is_hmac_sign_verified);

//-- sec_read_ttb  -------------------------------------------------------------
/**
 * This function is used to read current TTB. This function operated in 2 modes.
 * (1) Normalization mode - Returns normalized TTB and required Type1 or Type2
 * initialization before calling this function. (2) Raw mode - Returns raw TRC
 * & MTB read from counters in TTB format. No Type1 or Type2 initialization is
 * required.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 * @param[in] mode
 *              Normalization mode(1). Raw Mode (0).
 * @param[out] ttb_ptr
 *              pointer to 32 byte TTB buffer that platform
 *              will fill-in and return.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_NULL_POINTER     One of the pointer arguments 2-5 is NULL.
 * @retval SEC_INVALID_CONTEXT  The SEC device context is invalid.
 * @retval SEC_INVALID_INPUT    Invalid mode.
 */
//------------------------------------------------------------------------------

sec_result_t
sec_read_ttb(sec_dev_context_t       sec_dev_context,
             TTB_READ_MODE           mode,
             void                    *ttb_ptr);


//-- sec_update_ttb  -----------------------------------------------------------
/**
 * This function is used to read current TTB and corresnponding HMAC signature.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 * @param[out] curr_ttb_ptr
 *              pointer to 32 byte TTB buffer that platform
 *              will fill-in with current TTB and return.
 * @param[out] curr_ttb_hmac_sign_ptr
 *              pointer to 32 byte buffer of HMAC signature of current TTB that
 *              platform will fill-in and return.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_NULL_POINTER     One of the pointer arguments 2-5 is NULL.
 * @retval SEC_INVALID_CONTEXT  The SEC device context is invalid.
 * @retval SEC_INVALID_INPUT    Invalid mode.
 */
//------------------------------------------------------------------------------
sec_result_t
sec_update_ttb(sec_dev_context_t       sec_dev_context,
               void                    *curr_ttb_ptr,
               void                    *curr_ttb_hmac_sign_ptr);
