/****************************************************************************
 * Copyright (c) 2008-2011 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************/

#ifndef HDMI_HDCP_INCLUDED
#define HDMI_HDCP_INCLUDED


#ifdef __cplusplus
extern "C" {
#endif

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Return Codes
 *
 *   The HDCP Library returns one of these values to indicate the result of the
 *   operation.
 */
typedef enum
  {
    HDMI_HDCP_SUCCESS = 0,          /**< The operation completed successfully */
    HDMI_HDCP_FAILED,               /**< The operation failed  */
    HDMI_HDCP_ERR_KSV_INVALID,      /**< Invalid KSV  */
    HDMI_HDCP_ERR_KSV_REVOKED       /**< Revoked KSV  */
  } hdmi_hdcp_return_t;
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Return Code Tests
 *
 *   A convenience macro to check if the parameter indicates passing.
 */
#define HDMI_HDCP_IS_SUCCESSFUL(r)          ((r)==HDMI_HDCP_SUCCESS)
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Return Code Tests
 *
 *   A convenience macro to check if the parameter indicates a failure.
 */
#define HDMI_HDCP_IS_FAILURE(r)             ((r)!=HDMI_HDCP_SUCCESS)
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */


/*############################################################################*/
/*  FUNCTION PROTOTYPES:                                                      */
/*############################################################################*/

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Initialize HDCP Library
 *
 * Call this function to allocate a context.  A (void *) context is created and
 * written to *context.
 *
 * This function also reads the HDCP Keys, KSV, and SRM from flash (if
 * present).It will fail if the HDCP Keys are not stored in flash, or if they
 * were bound to a different media processor chip (i.e. chip replaced on board
 * without HDCP Key re-install).  It will not fail due to no SRM stored in
 * flash as that is a valid operating case.  The HDCP Keys are programmed into
 * the HDMI Unit via the Security Controller, and the revocation list(s) within
 * the SRM (if present) are loaded for authentication use.  The KSV is returned
 * to the caller-allocated buffer, as it is the caller's responsibility to
 * program that value into the HDMI Unit.
 *
 * It is acceptable to pass NULL as the parameter: ksv.  In this case, device
 * keys are not read from the flash and, thus, not installed into the HDMI
 * Unit.  It will be up to the caller to retrieve these values and get them
 * installed into the HDMI Unit via other means.
 *
 * If successful, the value returned by *context must be passed to all other
 * functions, and it must be released when down via hdmi_hdcp_sec_close().
 *
 * If failed, then no context was allocated.  Other functions that require a
 * context passed to them cannot be called.
 *
 * @param[out] context      Filled with context if successful
 * @param[out] ksv          Filled with KSV (5 bytes, little-endian)
 *
 * @return  HDMI_HDCP_SUCCESS if successful (new context allocated);
 *          HDMI_HDCP_FAILED if failed for some reason.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_open( void **context,
                    void *ksv
                    );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief De-Initialize HDCP Library
 *
 * Call this function to de-allocate a context.
 *
 * @param[in] context     Context from hdmi_hdcp_sec_open()
 * @return  HDMI_HDCP_SUCCESS is always returned as this function never fails.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_close(void *context);
/*-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Set SRM
 *
 * Receives a buffer containing a System Renewability Message (SRM).
 * Determines if the SRM is an updated version or not.  If updated, it verifies
 * the digital signature and updates our internal Vector Revocation List (VRL)
 * accordingly, and returns an indication that a portion of the SRM should be
 * saved in non-volatile memory (if it isn't already).
 *
 * SRMs will be retrieved by higher-level SW layers and passed down.  The
 * caller must simply route all such SRMs that come down the SW stack to it
 * through this function.  This function takes care of determining if the SRM
 * is valid, is a more recent version than the one stored in flash (if one is
 * stored in flash), and updates the flash with the new SRM if needed.
 *
 * There are some ambiguities involving the interpretation of the HDCP
 * Specification that will be handled automatically by this function.  One of
 * them is whether or not the existing authentication state's B-KSV and KSV
 * List should be rechecked against the updated SRM's revocation list(s).
 * Another one is if the verification of the SRM's digital signature fails, if
 * that causes the existing and/or subsequent HDCP Authentications to fail.
 * The caller only needs to interpret the return value to decide if the
 * existing authentication should fail, and (optionally) use
 * hdmi_hdcp_sec_authentication_query() before initiating future
 * authentications to avoid initiating them if they are going to fail anyway.
 *
 * @param[in] context           Context from hdmi_hdcp_sec_open().
 * @param[in] srm_buffer        Pointer to SRM.
 * @param[in] srm_size_bytes    Size of srm_buffer.
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if failed (HDCP Authentication must fail).
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_set_srm(  void           *context,
                        const void     *srm_buffer,
                        unsigned int    srm_size_bytes
                        );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Get random bytes.
 *
 * Fills a 4-byte buffer with random bytes.  The caller must pass in a pointer
 * to a 4-byte buffer that is filled with random data.
 *
 * @param[in] context       Context from hdmi_hdcp_sec_open().
 * @param[out] rnd_buffer   Pointer to 4-byte buffer to fill.
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if failed for some reason.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_get_rnd64(void *context,
                        void *rnd_buffer
                        );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Validate KSV.
 *
 * Validates a KSV.  A KSV must have 20 1's and 20 0's, and not be on the
 * current Vector Revocation List (VRL).  Although normally only one KSV is
 * validated with this call, the caller could pass a buffer of multiple KSVs.
 *
 * ksv_buffer is 5 bytes per KSV.  Each KSV is in little endian byte order.
 *
 * The VRL is initialized via hdmi_hdcp_sec_set_srm() and intially defaults to
 * an empty list.
 *
 * A returned status of HDMI_HDCP_FAILED does not imply anything is "wrong".
 * It just means that for some reason we could not determine that the KSVs in
 * the list are valid and not revoked.  The correct action to take on
 * HDMI_HDCP_FAILED is to fail HDCP authentication.
 *
 * @param[in] context       Context from hdmi_hdcp_sec_open().
 * @param[in] ksv_buffer    Pointer to KSV.
 * @param[in] num_ksvs      Count of KSVs in ksv_buffer.
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if failed for some reason.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_validate_ksv( void           *context,
                            const void     *ksv_buffer,
                            unsigned int    num_ksvs
                            );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Verify Repeater KSV List
 *
 * Verifies V prime is equal to V and, if so, verifies the KSVs in the KSV List
 * are not in the current Vector Revocation List (VRL).
 *
 * ksv_buffer is 5 bytes per KSV.  Each KSV is in little endian byte order.
 *
 * The VRL is initialized via hdmi_hdcp_sec_set_srm() and intially defaults to
 * an empty list.
 *
 * Note that the HDCP Specification does not require the HDCP Transmitter check
 * that the KSVs in the KSV List each contain 20 0's and 20 1's.  As such, we
 * skip this check and only check the KSVs against the VRL.
 *
 * A returned status of HDMI_HDCP_FAILED does not imply anything is "wrong".
 * It just means that for some reason we could not determine that the KSVs in
 * the list are valid and not revoked.  The correct action to take on
 * HDMI_HDCP_FAILED is to fail HDCP authentication.
 *
 * @param[in] context       Context from hdmi_hdcp_sec_open().
 * @param[in] ksv_buffer    Pointer to KSV List.
 * @param[in] num_ksvs      Count of KSVs in ksv_buffer.
 * @param[in] bstatus       HDCP Bstatus in lower 16 bits.
 * @param[in] v_buffer      Pointer to V prime (20-byte value).
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if failed for some reason.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_verify_v( void           *context,
                        const void     *ksv_buffer,
                        unsigned int    num_ksvs,
                        unsigned int    bstatus,
                        const void     *v_buffer
                        );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Verify Ri - Preliminary Check
 *
 * Receives Ri (before and after reading Ri') and Ri' for HDCP Ri Check.
 *
 * Ri and Ri' are 16-bit values.
 *
 * When performing an HDCP Ri Check, the caller should keep reading Ri (from
 * the HDMI Unit, both before and after reading Ri') and Ri' (from the attached
 * receiver device) and calling this function until it returns
 * HDMI_HDCP_SUCCESS.  The caller can assume that this function will return
 * HDMI_HDCP_SUCCESS within a few calls (thus, avoiding the need for the caller
 * to be concerned about an infinite loop).  Once HDMI_HDCP_SUCCESS is
 * returned, the caller completes the check with hdmi_hdcp_sec_check_r().
 *
 * Once the caller calls this function, the caller should complete the entire
 * check process (that is, keep calling this function repeatedly until it
 * returns HDMI_HDCP_SUCCESS, and then immediately call
 * hdmi_hdcp_sec_check_r()).  Otherwise, future Ri checks will be based on the
 * lingering state of the previous incomplete check.
 *
 * @param[in] context   Context from hdmi_hdcp_sec_open().
 * @param[in] r1        HDCP Ri value (read immediately before r_prime).
 * @param[in] r2        HDCP Ri value (read immediately after r_prime).
 * @param[in] r_prime   HDCP Ri' value.
 *
 * @return  HDMI_HDCP_SUCCESS if successful (can proceed with
 *                  hdmi_hdcp_sec_check_r);
 *          HDMI_HDCP_FAILED if preliminary check failed (must re-read and call
 *              again).
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_receive_r(    void           *context,
                            unsigned int    r1,
                            unsigned int    r2,
                            unsigned int    r_prime
                            );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Verify Ri - Final Check
 *
 * Finalize the Ri check.
 *
 * @param[in] context   Context from hdmi_hdcp_sec_open().
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if they are not equal.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_check_r( void *context);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Verify Pj - Preliminary Check
 *
 * Compares HDCP values Pj and Pj' to determine if the are equal.
 *
 * Pj and Pj' are 8-bit values.
 *
 * When performing an HDCP Pj Check, the caller should keep reading Pj (from
 * the HDMI Unit, before reading Pj') and Pj' (from the attached receiver
 * device) and calling this function until it returns HDMI_HDCP_SUCCESS.  The
 * caller can assume that this function will return HDMI_HDCP_SUCCESS within a
 * few calls (thus, avoiding the need for the caller to be concerned about an
 * infinite loop).  Once HDMI_HDCP_SUCCESS is returned, the caller completes
 * the check with hdmi_hdcp_sec_check_p().
 *
 * Once the caller calls this function, the caller should complete the entire
 * check process (that is, keep calling this function repeatedly until it
 * returns HDMI_HDCP_SUCCESS, and then immediately call
 * hdmi_hdcp_sec_check_p()).  Otherwise, future Pj checks will be based on the
 * lingering state of the previous incomplete check.
 *
 * @param[in] context   Context from hdmi_hdcp_sec_open().
 * @param[in] p         HDCP Pj value.
 * @param[in] p_prime   HDCP Pj' value.
 *
 * @return  HDMI_HDCP_SUCCESS if successful (can proceed with
 *              hdmi_dhcp_sec_check_p);
 *          HDMI_HDCP_FAILED if they are not equal (must re-read and call
 *              again).
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_receive_p(void           *context,
                        unsigned int    p,
                        unsigned int    p_prime
                        );
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Verify Pj - Final Check
 *
 * Finalize the Pj check.
 *
 * Pj and Pj' are 8-bit values.
 *
 * @param[in] context   Context from hdmi_hdcp_sec_open().
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if they are not equal.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_check_p(void *context);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Queries if the system is allowed to HDCP authenticate.
 *
 * Returns an indication if HDCP Authentication is permitted.
 *
 * This is a lightweight function intended to be called whenever there is an
 * event that would cause the caller to want to initiate authentication (e.g.
 * Ri mismatch, device attach, whatever).
 *
 * If it returns successful, then the caller can proceed with authentication.
 * Otherwise, HDCP authentication is not permitted right now for some reason
 * (e.g.  last SRM verify failed), so it is pointless to proceed with it.  Any
 * attempt to call other authentication functions, like
 * hdmi_hdcp_sec_validate_ksv() will also return FAIL anyway.  As such, if the
 * caller fails to call this function, authentication will still fail, but it
 * can detect that failure early and avoid the unnecessary fuss of initiating
 * the exchange with the sink device.
 *
 * A returned status of HDMI_HDCP_FAILED indicates HDCP Authentication is not
 * permitted.
 *
 * @param[in] context   Context from hdmi_hdcp_sec_open().
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if failed for some reason.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_authentication_query(void *context);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

/* = = = = = = = = = = = = = = = = == = = = = = = = = = = = = = = = = = = = = */
/*!  \brief Retrieves the HDCP RX KSV
 *
 * Returns the KSV for the HDCP RX, if applicable.
 *
 * hdmi_hdcp_sec_open() does not need to be called to use this function.
 *
 * This function is not a valid test for the presence of the HDCP RX, as it
 * may return an invalid value for the KSV.
 *
 * @param[out] ksv          Filled with KSV (5 bytes, little-endian)
 *
 * @return  HDMI_HDCP_SUCCESS if successful;
 *          HDMI_HDCP_FAILED if failed for some reason.
 */
hdmi_hdcp_return_t
hdmi_hdcp_sec_retrieve_rx_ksv(void *ksv);
/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - */

#ifdef __cplusplus
}
#endif

#endif  /*  ndef HDMI_HDCP_INCLUDED  */
