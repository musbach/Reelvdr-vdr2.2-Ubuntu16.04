//-----------------------------------------------------------------------------
// Copyright (c) 2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_HDCP2R_H
#define SEC_HDCP2R_H

#include <stdbool.h>
#include "sec_types.h"

#define SEC_HDCP2R_SESSION_TYPE_NONE     0    /*!<  no HDCP2R type  */
#define SEC_HDCP2R_SESSION_TYPE_WIDI     1    /*!<  WiDi (via demux)  */
#define SEC_HDCP2R_SESSION_TYPE_MAXIMUM  128

#define SEC_HDCP2R_REPEATER_NO           0    /*!<  no repeater  */
#define SEC_HDCP2R_REPEATER_YES          1    /*!<  repeater  */

typedef unsigned long  sec_hdcp2r_session_t;


#ifdef __cplusplus
extern "C" {
#endif

/**@mainpage
 *
 * The SEC driver includes an interface for HDCP2 Receivers.
 */


/**@defgroup hdcp2_receiver    HDCP2 Receiver
*
*These functions perform HDCP2 specific operations such as Key Provisioning 
* and HDCP2 Authentication.
*/


//--  sec_hdcp2r_materials_rewrap  --------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief rewrap materials
 *
 * This function re-wraps a blob of materials with the chip-unique key.
 *
 * This must be done before the materials blob can be loaded with
 * sec_hdcp2r_materials_load().  Typically, the materials blob is saved
 * to non-volatile storage during the provisioning process.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in, out] materials
 *              Pointer to materials to re-wrap.  It is re-encrypted in-place.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_materials_rewrap( sec_dev_context_t  sec_dev_context,
                             void *             materials );


//--  sec_hdcp2r_materials_load  ----------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief load materials
 *
 * This function loads a blob of materials that was previously wrapped with
 * the chip-unique key via sec_hdcp2r_materials_rewrap().  This may have
 * been done during the provisioning process in the factory.
 *
 * This must be done before a session can be created, or any operations that
 * require a session.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] materials_in
 *              Pointer to store the chip-specific 32-bit value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_materials_load( sec_dev_context_t  sec_dev_context,
                           const void *       materials_in );


//--  sec_hdcp2r_materials_cert_info  -----------------------------------------
/**@ingroup hdcp2_receiver
 * @brief load materials
 *
 * This function returns the byte offset and byte length of the certificate
 * within a blob of materials.
 *
 * Note that this function does not receive a sec_dev_context.  It does not
 * require that the sec_dev_context be opened.  It can be called at any time.
 *
 * @param[out] cert_offset_bytes
 *              Pointer to write the certificate offset, or NULL.
 *
 * @param[out] cert_size_bytes
 *              Pointer to write the certificate byte-length, or NULL.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_materials_cert_info( unsigned int *  cert_offset_bytes,
                                unsigned int *  cert_size_bytes );


//--  sec_hdcp2r_session_reset  -----------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief reset all sessions
 *
 * This function destroys any existing sessions.   It is equivalent to
 * walking through all existing open sessions and calling
 * sec_hdcp2r_session_destroy() on them.  It is not meant to be
 * used in normal situations, but as a cleanup tool to remove old dead
 * sessions.
 *
 * sec_hdcp2r_materials_load() must be called prior to this function.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_session_reset( sec_dev_context_t  sec_dev_context );


//--  sec_hdcp2r_session_create  ----------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief create a session
 *
 * This function creates a session.  A session must be created for most
 * functions in this library, passing the returned Session ID of the
 * currently open session.  Use sec_hdcp2r_session_destroy() to destroy
 * the session when it is no longer needed.
 *
 * The session is only created if SEC_SUCCESS is returned.  In this case,
 * it must be destroyed with sec_hdcp2r_session_destroy().  Alternatively,
 * sec_hdcp2r_session_reset() may be used to destroy all existing
 * sessions.
 *
 * sec_hdcp2r_materials_load() must be called prior to this function.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] session_type
 *              The SEC_HDCP2R_SESSION_TYPE code
 *
 * @param[in] key_slot
 *              The key cache slot to be used for key loading,
 *              if applicable (e.g. SEC_CCW1)
 *
 * @param[out] sid
 *              Pointer to write the newly-opened Session ID.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_session_create( sec_dev_context_t       sec_dev_context,
                           unsigned int            session_type,
                           sec_hdcp2r_session_t *  sid,
                           sec_key_cache_slot_t    key_slot );


//--  sec_hdcp2r_session_destroy  ---------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief destroy a session
 *
 * This function destroys a session that was previously created using
 * sec_hdcp2r_session_create().  Once this function is called, the
 * Session ID is no longer valid.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_session_destroy( sec_dev_context_t     sec_dev_context,
                            sec_hdcp2r_session_t  sid );


//--  sec_hdcp2r_ake_init  ----------------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief AKE_init  
 *
 * This function is to called after AKE_init message is received from transmitter.
 * This function passes rtx value to the firmware and repeater flag is returned.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[in] rtx
 *              Pointer to the 64-bit Rtx value.
 *
 * @param[out] repeater_flag
 *              Pointer to store the repeater flag:
 *                  SEC_HDCP2R_REPEATER_NO for no repeater,
 *                  SEC_HDCP2R_REPEATER_YES for repeater
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_ake_init( sec_dev_context_t     sec_dev_context,
                     sec_hdcp2r_session_t  sid,
                     const void *          rtx,
                     unsigned int *        repeater_flag );


//--  sec_hdcp2r_ake_no_stored_km_rrx  ----------------------------------------
/**@ingroup hdcp2_receiver
 * @brief AKE_No_Stored_Km
 *
 * This function is called after receiving AKE_No_Stored_km message from transmitter.
 * encrypted Km is passed as parameter to the function. The function generates rrx 
 * and returns in buffer pointed to by rrx argument.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[in] e_km
 *              Pointer to the 128-byte (1024-bit) encrypted Km value.
 *
 * @param[out] rrx
 *              Pointer to store the 64-bit Rrx value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_ake_no_stored_km_rrx( sec_dev_context_t     sec_dev_context,
                                 sec_hdcp2r_session_t  sid,
                                 const void *          e_km,
                                 void *                rrx );


//--  sec_hdcp2r_ake_stored_km_rrx  -------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief AKE_Stored_Km
 *
 * This function is called after receiving AKE_Stored_km message from transmitter.
 * encrypted Km is passed as parameter to the function along with m value corresponding 
 * to the receiver. The function generates rrx and returns in buffer pointed to 
 * by rrx argument.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[in] e_km
 *              Pointer to the 128-bit encrypted Km value.
 *
 * @param[out] m
 *              Pointer to the 128-bit m value.
 *
 * @param[out] rrx
 *              Pointer to store the 64-bit Rrx value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_ake_stored_km_rrx( sec_dev_context_t     sec_dev_context,
                              sec_hdcp2r_session_t  sid,
                              const void *          e_km,
                              const void *          m,
                              void *                rrx );


//--  sec_hdcp2r_ake_h_prime  -------------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief AKE_Send_H_Prime
 *
 * This function is called after AKE_Send_rrx message is sent to transmitter.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[out] h_prime
 *              Pointer to store the 128-bit Hprime value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_ake_h_prime( sec_dev_context_t     sec_dev_context,
                        sec_hdcp2r_session_t  sid,
                        void *                h_prime );


//--  sec_hdcp2r_ake_pairing_info  --------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief AKE_Pairing_Info
 *
 * This function is called after AKE_Send_H_Prime message is sent to transmitter.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[out] e_km
 *              Pointer to store the 128-bit encrypted Km value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_ake_pairing_info( sec_dev_context_t     sec_dev_context,
                             sec_hdcp2r_session_t  sid,
                             void *                e_km );


//--  sec_hdcp2r_locality_check  ----------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief locality_check
 *
 * This function is called for Locality Check.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[in] rn
 *              Pointer to the 64-bit Rn value.
 *
 * @param[out] l_prime
 *              Pointer to store the 128-bit Lprime value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_locality_check( sec_dev_context_t     sec_dev_context,
                           sec_hdcp2r_session_t  sid,
                           const void *          rn,
                           void *                l_prime );


//--  sec_hdcp2r_session_key  -------------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief receive encrypted session key
 *
 * This function is called after Locality Check, to set the Session Key.  Once
 * this function returns, content decryption is ready.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[in] e_ks
 *              Pointer to the 128-bit encrypted session key.
 *
 * @param[in] riv
 *              Pointer to the 64-bit Riv value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_session_key( sec_dev_context_t     sec_dev_context,
                        sec_hdcp2r_session_t  sid,
                        const void *          e_ks,
                        const void *          riv );


//--  sec_hdcp2r_repeater_list  -----------------------------------------------
/**@ingroup hdcp2_receiver
 * @brief generate v_prime
 *
 * This function calculates Vprime for a given repeater list.  The repeater list
 * must include 4 bytes of header and a sequence of zero or more 5-byte KSVs.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] sid
 *              The currently-opened Session ID for which this applies to.
 *
 * @param[in] repeater_list_size_bytes
 *              The size of the list pointed to by repeater_list.
 *
 * @param[in] repeater_list
 *              Pointer to the repeater list.
 *
 * @param[out] v_prime
 *              Pointer to store the 128-bit Vprime value.
 *
 * @return SEC_SUCCESS for successful operation, or some sec_result_t error.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_hdcp2r_repeater_list( sec_dev_context_t     sec_dev_context,
                          sec_hdcp2r_session_t  sid,
                          unsigned long         repeater_list_size_bytes,
                          const void *          repeater_list,
                          void *                v_prime );


#ifdef __cplusplus
}
#endif

#endif
