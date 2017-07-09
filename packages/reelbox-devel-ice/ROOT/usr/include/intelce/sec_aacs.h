//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_AACS_H
#define SEC_AACS_H

#include <stdbool.h>
#include "sec_types.h"
#include "sec_aacs_types.h"

// the feature flag bit in sec_module_features for AACS support
#define  SEC_MOD_FEATURE_AACS  0x00000002ul

#ifdef __cplusplus
extern "C" {
#endif

/**@mainpage
 *
 * The SEC driver includes an interface allowing the AACS compliance player to
 * access the lower level AACS functions supported by AACS Firmware, such as
 * key calculation, EC-DSA signature generation/verification, content
 * decryption and drive authentication.
 *
 * The SEC AACS Driver API may be used in conjunction with the higher level
 * interface provided by the AACS Software Framework library to complete an AACS
 * implementation.  Please refer to the AACS Software Framework Programming
 * Guide for details.
 */


//--  sec_aacs_supported_module_id  -------------------------------------------
/**
 * This function determines whether a given loadable firmware module ID
 * supports AACS.
 *
 * This function does not require that the AACS firmware is loaded or
 * initialized (i.e. via sec_aacs_initialize()).
 *
 * @param[in] module_id
 *              SEC loadable firmware Module ID code to check
 *
 * @retval true                 This Module ID supports AACS
 * @retval false                This Module ID is not known to support AACS
 */
//-----------------------------------------------------------------------------
bool
sec_aacs_supported_module_id( unsigned int  module_id );


//--  sec_aacs_initialize  ----------------------------------------------------
/**
 * This function must be called once after the AACS firmware is loaded before
 * any other AACS APIs can be used (except where specified otherwise).  It is
 * normally called as part of system boot up and initialization.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] flash_module
 *              Pointer to the start of the Encrypted AACS Confidential Data
 *              Flash Module that is stored in the AACS Middleware/Driver
 *              component.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_NULL_POINTER     The encrypted AACS Confidential Data Flash
 *                                  Module is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_initialize(    sec_dev_context_t   sec_dev_context,
                        void *              flash_module);


//--  sec_aacs_create_context  ------------------------------------------------
/**
 * This function will create an AACS context and return the context id to the
 * caller. Most other AACS functions cannot be called without a conext ID
 * returned by this function.
 *
 * If successful, the value returned by *context_id must be passed to all
 * other AACS functions.
 *
 * When an AACS context is no longer needed, the application calls
 * sec_aacs_destroy_context() to free the resource allocated for the context.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[out] context_id
 *              AACS context ID that must be used when requesting all other
 *              AACS specific API. In case of failure, the returned Context ID
 *              is 0xFFFFFFFF.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The encrypted AACS Confidential Data Flash
 *                                  Module is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_create_context(sec_dev_context_t   sec_dev_context,
                        unsigned long *     context_id);


//--  sec_aacs_destroy_context  -----------------------------------------------
/**
 * This function deallocates and destroys all internal information relating to
 * the specified AACS Context
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID that is returned by sec_aacs_create_context().
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_destroy_context (  sec_dev_context_t   sec_dev_context,
                            unsigned long       context_id);


//--  sec_aacs_calculate_processing_key  --------------------------------------
/**
 * This function performs all calculations necessary to obtain the Processing
 * Key from the Umask, UV number, encrypted Device Key
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] UV_number
 *              UV number taken from the Explicit Subset Difference record.
 *
 * @param[in] UV_number_prime
 *              UV number that corresponds with the selected Device Key.
 *
 * @param[in] dev_key_index
 *              Device key index.  Only the values 0 through 252 are valid.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input data pointer is NULL
 */
//-----------------------------------------------------------------------------

sec_result_t
sec_aacs_calculate_processing_key(  sec_dev_context_t   sec_dev_context,
                                    unsigned long       context_id,
                                    unsigned long       UV_number,
                                    unsigned long       UV_number_prime,
                                    unsigned int        dev_key_index);

//--  sec_aacs_verify_media_key  ----------------------------------------------
/**
 * This function decrypts the Verification Data using the AACS context Media
 * Key and comparing it against the specified plaintext input data
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] verification_data
 *              Pointer to a 16-byte encrypted verification data.
 *
 * @param[in] clear_verification_data
 *              Pointer to a 16-byte plaintext verification data.
 *
 * @param[in] compare_data_mask
 *              Pointer to a 16-byte Compare Data Mask.
 *
 * @param[out] success
 *              True returned here if verification succeed, false if
 *              verification failed.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_verify_media_key ( sec_dev_context_t   sec_dev_context,
                            unsigned long       context_id,
                            void *              verification_data,
                            void *              clear_verification_data,
                            void *              compare_data_mask,
                            bool *              success);

//--  sec_aacs_process_key_derivative  ----------------------------------------
/**
 * This function enables the following AACS specific mechanisms:
 *
 * - Application of Media Key Data to the Processing Key to obtain the Media
 *   Key (Km = AES-128D(K, Media Key Data))
 *
 * - Application of KCD data to the Media Key Precursor to obtain the Media
 *   Key (Km = AES-G(Kmp, KCD))
 *
 * - Application of the Volume ID to obtain the Volume Unique Key
 *   (Kvu = AES-G(Km, Volume ID))
 *
 * - Application of the Volume ID to obtain the Volume Variant Unique Key
 *   (Kvvu = AES-G(Kmv, Volume ID))
 *
 * - Application of the Binding Nonce to obtain the Protected Area Key
 *   (Kpa = AES-G(Km, Binding Nonce (X)))
 *
 * - Decryption and Application of the AES Hash of the Content Usage Rules to
 *   obtain the Title Key on Recorded Media (Kt = AES-128D(Kpa, Kte) ^
 *   AES-H(Usage Rules)). This is supported through AES-128CBCD with an IV
 *   equal to AES-H(Usage Rules).
 *
 * - Application of Variant Data to obtain the Media Key Variant
 *   (Kmv = AES-G(Km, Dv || 0x041826FA7749)) This is a special case where the
 *   input data does not come from the Host and instead comes from the AACS
 *   context.  If the Variant Data is 0x0 when this command is executed, the
 *   operation will fail with return status code: SEC_AACS_INVALID_VARIANT.
 *
 * - Decryption of the Title Key/CPS Unit Key (Kcu = AES-128D(Kvu, Kcue)) in
 *   BluRay Prerecorded Media
 *
 * - Application of KmDelta to the Media Key Precursor (Km = Kmp ^ KmDelta ) in
 *   Prepared Video.
 *
 * - Decryption of the Data Key for Bus Encryption/Decryption
 *   (Data Key = AES-128D(Bus Key, E(Data_Key)))
 *
 * - Encryption of the Randomly Generated Title key for Recordable Media
 *   (Kte = AES-128E(Kpa, Kt ^ AES-H(Usage Rules). This is supported
 *   through AES-128CBCE with an IV equal to AES-H(Usage Rules).
 *
 * - Decryption of the BD-ROM Online generated Title Key 
 *   (Kt = AES-128D(Kvu, Kte) ^ nonce ^ AES_H(Volume ID || title_ID).  
 *   The nonce must be pre-generated via the AACSGetNonce command. 
 *   
 * @note
 *   Kte and AES_H(Volume_ID || title_ID) input are from host.  
 *   nonce and Kvu are from AACS context. 
 *   The apply_alg parameter must be set to SEC_AACS_ALG_AES_128_CBC_NONCE_E
 *
 * - Encryption of the BD-ROM Online generated Title Key
 *   (Kte = AES-128E(Kvu, Kt) ^ nonce ^ AES_H(Volume_ID || title_ID)).  
 *
 * @note
 *   Kte and AES_H(Volume_ID || title_ID) input are from host.  
 *   nonce, kt and Kvu are from AACS context. AES-128CBCE-NONCE
 *   The apply_alg parameter must be set to SEC_AACS_ALG_AES_128_CBC_NONCE_D
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] src_key_sel
 *              The source key. valid values are:
 *              - SEC_AACS_Kmv_0 - SEC_AACS_Kmv_5
 *              - SEC_AACS_Kvvu_0 - SEC_AACS_Kvvu_5
 *              - SEC_AACS_K
 *              - SEC_AACS_Km_Kmp
 *              - SEC_AACS_Kms_i
 *              - SEC_AACS_Kvu
 *              - SEC_AACS_Kt_Kcu
 *              - SEC_AACS_Bk
 *              - SEC_AACS_Kpa
 *
 * @param[in] src_data_sel
 *              The source data. Valid values are:
 *              - SEC_AACS_Dv_0 - SEC_AACS_Dv_5
 *              - SEC_AACS_USER_INPUT
 *
 * @param[in] dst_key_sel
 *              The destination key. Valid values are:
 *              - SEC_AACS_Kmv_0 - SEC_AACS_Kmv_5
 *              - SEC_AACS_Kvvu_0 - SEC_AACS_Kvvu_5
 *              - SEC_AACS_K
 *              - SEC_AACS_Km_Kmp
 *              - SEC_AACS_Kms_i
 *              - SEC_AACS_Kvu
 *              - SEC_AACS_Kt_Kcu
 *              - SEC_AACS_Bk
 *              - SEC_AACS_Kpa
 *
 * @param[in] apply_alg
 *              The crypto algorithm used to perform the operation.
 *
 * @param[in] input_data
 *              Pointer to a 16-byte buffer containing one of the following:
 *              KCD, Volume ID, KMA, E(Data Key), Kcue, kte, and X.
 *
 * @param[in] iv
 *              Pointer to a 16-byte buffer containing the Initialization
 *              Vector that will be applied in the case of an AES-128CBCD
 *              operation.  This should be used to calculate the Title Key in
 *              the case of Recorded Media.
 *
 * @param[out] output_data
 *              Pointer to a 16-byte buffer that will receive an Encrypted
 *              Title Key.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_INVALID_AACS_KEY Invalid AACS context key.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_process_key_derivative (   sec_dev_context_t       sec_dev_context,
                                    unsigned long           context_id,
                                    sec_aacs_context_key_t  src_key_sel,
                                    sec_aacs_context_key_t  src_data_sel,
                                    sec_aacs_context_key_t  dst_key_sel,
                                    sec_aacs_algorithm_t    apply_alg,
                                    void *                  input_data,
                                    void *                  iv,
                                    void *                  output_data);



//--  sec_aacs_process_packets  -----------------------------------------------
/**
 * This function performs content and bus decryption/encryption of the
 * following packet types:
 *
 * - BluRay Pre-Recorded 6144 byte Pack Decryption where the Block Key is
 *   calculated from the CPS Unit Key (Kb = AES-G(Kcu, Seed)) followed by
 *   pack decryption: C = AES-128CBCD(Kb, Ce)) where Ce is 6128 bytes in
 *   length following the Seed value (16 bytes).
 * 
 * - BluRay Pre-Recorded 6144 byte Pack Encryption where the Block Key is
 *   calculated from the CPS Unit Key (Kb = AES-G(Kcu, Seed)) followed by
 *   pack encryption: Ce = AES-128CBCD(Kb, C)) where Ce is 6128 bytes in
 *   length following the Seed value (16 bytes).
 *
 * - BluRay Recorded 2048 byte Pack Decryption where the Block Key is
 *   calculated from the CPS Unit Key (Kb = AES-G(Kcu, Seed)) followed by
 *   pack decryption: C = AES-128CBCD(Kb, Ce)) where Ce is 2032 bytes in
 *   length following the Seed value (16 bytes).
 *
 * - BluRay Recorded 2048 byte Pack Encryption where the Block Key is
 *   calculated from the CPS Unit Key (Kb = AES-G(Kcu, Seed)) followed
 *   by pack encryption: Ce = AES-128CBCD(Kb, C)) where Ce is 2032 bytes
 *   in length following the Seed value (16 bytes).
 *
 * Note: BluRay Pre-recorded media with bus encryption enabled must send
 * 3 logical sectors to this command for Bus and/or Content encryption/
 * decryption.
 *
 * In-place encryption and decryption are supported by setting
 * src_packet_data equal to dst_packet_data and src_buffer_type equal
 * to dst_buffer_type.
 *
 * Buffers may be either virtual memory addresses or physical addresses.
 * sec_aacs_packet_list_t.src_buffer_type and
 * sec_aacs_packet_list_t.dst_buffer_type determine which kind of memory
 * pointer is used.  If SEC_AACS_BUFFER_TYPE_VIRTUAL is used, then the
 * corresponding src_packet_data or dst_packet_data in sec_aacs_packet_t
 * is a virtual memory pointer.  If SEC_AACS_BUFFER_TYPE_PHYS_CONTIGUOUS
 * is used, then the corresponding src_packet_data or dst_packet_data in
 * sec_aacs_packet_t is a physical memory address and the buffer must be
 * physically contiguous memory.  It is highly recommended to set both
 * buffer types to SEC_AACS_BUFFER_TYPE_PHYS_CONTIGUOUS because this
 * saves sec_aacs_process_packets() from having to copy the buffers to
 * and/or from an internally-allocated buffer of physically contiguous
 * memory.
 *
 * If SEC_AACS_BUFFER_TYPE_PHYS_CONTIGUOUS is used, then the address must
 * be aligned on a 32-bit boundary.
 *
 * This function may encrypt or decrypt packets using either the
 * CPS Unit Key (Kcu) or a Segment Key.  If the CPS Unit key is used,
 * then sec_aacs_packet_t.title_key is set to SEC_AACS_Kt_Kcu while the
 * play_item_id and play_list_id fields are not used.  To use a segment
 * key, sec_aacs_packet_t.title_key is set to SEC_AACS_BLURAY_SEG_KEY
 * while the play_item_id and play_list_id fields are set as needed to
 * select the proper Segment Key.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in,out] packet_list
 *              A list of packets to be encrypted/decrypted.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_process_packets (  sec_dev_context_t       sec_dev_context,
                            sec_aacs_packet_list_t  packet_list);


//--  sec_aacs_copy_context  --------------------------------------------------
/**
 * THIS FUNCTION IS NO LONGER SUPPORTED AND ALWAYS DOES NOTHING BUT RETURN WITH
 * SEC_NOT_SUPPORTED.
 *
 * THIS FUNCTION IS DEPRECATED AND WILL BE REMOVED IN FUTURE SDKS.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] src_context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] dst_context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @retval SEC_NOT_SUPPORTED       This function is no longer supported.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_copy_context ( sec_dev_context_t   sec_dev_context,
                        unsigned long       src_context_id,
                        unsigned long       dst_context_id);


//--  sec_aacs_sign  ----------------------------------------------------------
/**
 * This function performs ECDSA signature generation of a SHA-1 message digest
 * using the AACS ECDSA private signing key.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] msg_digest
 *              Pointer to a buffer that contains 20-byte SHA-1 Message Digest
 *              in big endian format.
 *
 * @param[out] signature
 *              Pointer to a buffer that receives the signature data. The
 *              caller should allocate the signature buffer. The length of this
 *              buffer must be 40 bytes.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_sign(  sec_dev_context_t   sec_dev_context,
                unsigned long       context_id,
                void *              msg_digest,
                void *              signature);


//--  sec_aacs_verify_signature  ----------------------------------------------
/**
 * This function performs ECDSA signature verification using an externally
 * supplied public signature key.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] pub_key_x
 *              Pointer to a buffer that contains the x-coordinate of ECDSA
 *              public signature key.
 *
 * @param[in] pub_key_y
 *              Pointer to a buffer that contains the y-coordinate of ECDSA
 *              public signature key.
 *
 * @param[in] msg_digest
 *              Pointer to a buffer that contains 20-byte SHA-1 Message Digest
 *              in big endian format.
 *
 * @param[in] signature
 *              Pointer to a 40-byte buffer that contains the signature data.
 *
 * @param[out] success
 *              True is returned here if the signature is successfully verified,
 *              false if signature verification failed or an error occurred.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_verify_signature(  sec_dev_context_t   sec_dev_context,
                            unsigned long       context_id,
                            void *              pub_key_x,
                            void *              pub_key_y,
                            void *              msg_digest,
                            void *              signature,
                            bool *              success);


//--  sec_aacs_generate_Hk_and_return_Hv  -------------------------------------
/**
 * This function generates the 160 bit Nonce Hk and performs an Elliptic
 * Curve scalar multiplication to obtain and return Hv (Hv = Hk G). Hk is
 * maintained in the AACS context for later use in Bus Key Calculations.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[out] EC_output_point_x
 *              Pointer to a 20-byte buffer that receives x-coordinate of the
 *              scalar multiplied point.
 *
 * @param[out] EC_output_point_y
 *              Pointer to a 20-byte buffer that receives y-coordinate of the
 *              scalar multiplied point.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Output data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_generate_Hk_and_return_Hv( sec_dev_context_t   sec_dev_context,
                                    unsigned long       context_id,
                                    void *              EC_output_point_x,
                                    void *              EC_output_point_y);


//--  sec_aacs_calculate_bus_key  ---------------------------------------------
/**
 * This function calculates the 128 bit Bus Key.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] Dv_x
 *              Pointer to a 20-byte buffer that contains x-coordinate of Dv.
 *
 * @param[in] Dv_y
 *              Pointer to a 20-byte buffer that contains y-coordinate of Dv.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_calculate_bus_key( sec_dev_context_t   sec_dev_context,
                            unsigned long       context_id,
                            void *              Dv_x,
                            void *              Dv_y);


//--  sec_aacs_CMAC  ----------------------------------------------------------
/**
 * This function either generates or verifies a MAC in the AACS system using
 * the BusKey, Volume Unique Key, Volume Variant Unique Key, the TitleKey,
 * or Kcu (BluRay).
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] MAC_gen_key
 *              MAC generation key.  Valid keys are:
 *              - Segment Keys
 *              - Media Key Variants,
 *              - Volume Variant Unique Keys
 *              - Processing Key
 *              - Media Key
 *              - Media Sequence Key
 *              - Volume Unique Key
 *              - Title Key/CPS Unit Key
 *              - BusKey
 *              - DataKey
 *              - Protected Area Key
 *
 * @param[in] gen_or_verify
 *              SEC_AACS_CMAC_GEN to generate CMAC, or SEC_AACS_CMAC_VERIFY to
 *              generate CMAC and verify with input MAC.
 *
 * @param[in] data
 *              Pointer to a buffer that contains the data requiring signature
 *              verification.
 *
 * @param[in] data_size
 *              The number of bytes in the data buffer.
 *
 * @param[in,out] MAC_data
 *              Pointer to a buffer that contains the 16-byte MAC input if
 *              SEC_AACS_CMAC_VERIFY is specified in gen_or_verify field or
 *              receives the output if SEC_AACS_CMAC_GEN is specified.
 *
 * @param[out] success
 *              CMAC verification result. Only valid if SEC_AACS_CMAC_VERIFY is
 *              specified in the gen_or_verify field. Otherwise, this field is
 *              ignored. Return true if the signature is successfully verified.
 *              return false if the signature verification failed or an error
 *              has occurred.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_AACS_KEY Invalid AACS context key.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     Input/output data pointer is NULL
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_CMAC(  sec_dev_context_t       sec_dev_context,
                unsigned long           context_id,
                sec_aacs_context_key_t  MAC_gen_key,
                sec_aacs_cmac_t         gen_or_verify,
                void *                  data,
                unsigned long           data_size,
                void *                  MAC_data,
                bool *                  success);


//--  sec_wrap_AACS_keys  -----------------------------------------------------
/**
 * This function must be invoked by the HD-DVD/BluRay manufacturer application
 * in the factory to bind the formatted plaintext confidential data flash
 * module (refer to Intel AACS key ordering reference tool for the format) to
 * the platform.
 *
 * This function should only be used on initial power-up in the OEM/ODM
 * factory and, potentially, during in-the-field updates.
 *
 * @note
 * To avoid dictionary attacks, this API is only enabled for one execution after
 * each load of the AACS firmware.  As of this writing, AACS firmware is only
 * loadable once per system reboot, effectively making this call executable
 * only once per reboot.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in,out] new_flash_module
 *              Pointer to a buffer that contains the AACS Confidential Data
 *              Flash Module to be wrapped. The Host must provide a 9569-byte
 *              plaintext buffer that is formatted as shown in Intel AACS key
 *              ordering reference tool.  The wrapped AACS Confidential Data
 *              Flash Module will be written back to this buffer.
 *
 * @param[in] cur_flash_module
 *              Pointer to a buffer containing the currently installed wrapped
 *              AACS Confidential Data. This value must be NULL when doing
 *              an initial provisioning and must be non-NULL when doing any
 *              of the updating provisionings.  In the latter case, the buffer
 *              will be decrypted and authenticated and the portions specified
 *              by the provisioning_type will be updated from new_flash_module,
 *              and the results will be rewrapped.
 *
 * @param[in] provisioning_type
 *              Indicates if this is an initial provisioning (entire module
 *              is wrapped) or an update provisioning.  In the latter case,
 *              the values specified by the provisioning type are updated in
 *              cur_flash_module with new values taken from new_flash_module.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_CUR_PTR  A non-NULL value for cur_flash_module was passed
 *                                  even though the provisioning_type
 *                                  specified sec_prov_initial.
 * @retval SEC_NULL_POINTER     A NULL pointer was passed for a required
 *                                  parameter.
 * @retval SEC_OUT_OF_MEMORY    Memory allocation failed.
 * @retval SEC_INVALID_PROVISION_TYPE
 *                              An invalid value was passed for the
 *                                  'provisioning_type' parameter.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_wrap_AACS_keys( sec_dev_context_t       sec_dev_context,
                    void *                  new_flash_module,
                    void *                  cur_flash_module,
                    sec_aacs_provision_t    provisioning_type
                    );

//--  sec_aacs_process_variant_data  ------------------------------------------
/**
 * This function processes the provided 10-byte Encrypted Variant Data or
 * Doubly Encrypted Variant Data from the Calculate Variant Data Record or
 * Conditionally Calculate Variant Data Record of a Sequence Key Block (SKB).
 * The caller must select the correct row from the record as determined by
 * the applicable Sequence Key.
 *
 * In the case of Doubly Encrypted Variant Data from a Condtionally Calculate
 * Variant Data Record, sec_aacs_process_ccvd_record_header() must be called
 * first to test if the record applies and return the column number.
 *
 * The variant data may be broken down by 10-byte row data and passed
 * sequentially, in one or more calls to this function.
 *
 * In the event that the derived Variant Data is zero, the function fails
 * with a return status of SEC_INVALID_VARIANT.
 *
 * @param[in] sec_dev_context
 *              SEC context that performs the operation.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] skb_select
 *              SKB Number in range [0,5].
 *
 * @param[in] record_type
 *              SEC_AACS_VDRT_CVDR for Calculate Variant Data Record, or
 *              SEC_AACS_VDRT_CCVDR for Conditionally Calculate Variant Data
 *              Record.
 *
 * @param[in] starting_row
 *              The starting row number to begin parsing. The data must be
 *              parsed sequentially, so the first time it is called for a
 *              SKB record, it is set to zero.
 *
 * @param[in] total_rows
 *              The total number of rows passed in at encrypted_key_data.
 *
 * @param[in] encrypted_key_data
 *              Pointer to buffer containing array of entries consisting
 *              of 10-byte Encrypted Variant Data or Doubly Encrypted Variant
 *              Data entries.  The total length of the array in bytes is
 *              10 times total_rows.
 *
 * @param[in] x
 *              The nonce, X, retrieved from the Nonce Record.
 *
 * @param[in] seq_key_index
 *              Sequence key and row/column information index selection.  Only
 *              the values 0 through 255 are valid.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_INVALID_INPUT    record_type or skb_select is an invalid value.
 * @retval SEC_NULL_POINTER     Input/output data pointer is NULL.
 * @retval SEC_OUT_OF_MEMORY    Failed to allocate memory.
 * @retval SEC_INVALID_VARIANT  The Variant Data is zero.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_process_variant_data(sec_dev_context_t       sec_dev_context,
                              unsigned long           context_id,
                              unsigned int            skb_select,
                              sec_aacs_skb_vdr_type_t record_type,
                              unsigned long           starting_row,
                              unsigned long           total_rows,
                              void *                  encrypted_key_data,
                              void *                  x,
                              unsigned int            seq_key_index);



//--  sec_aacs_process_ccvd_record_header  ------------------------------------
/**
 * This function decrypts the 16-byte Encrypted Conditional Data of the
 * Conditionally Calculate Variant Data Record of a Sequence Key Block to
 * determine if the record applies.  If the record applies (i.e. decryption
 * yields 0xDEADBEEF), then the column and generation numbers are returned.
 *
 * This function should be called when processing a Conditionally Calculate
 * Variant Data Record before calling sec_aacs_process_variant_data().
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] skb_select
 *              SKB Number in range [0,5].
 *
 * @param[in] encrypted_conditional_data
 *              Pointer to buffer containing 16-byte Encrypted Conditional Data.
 *
 * @param[out] column
 *              If the record applies (i.e. *success is true), then this 16-bit
 *              integer is filled with the column number.
 *
 * @param[out] generation
 *              If the record applies (i.e. *success is true), then this 16-bit
 *              integer is filled with the generation number.
 *
 * @param[out] success
 *              If the record applies then this returned value is true;
 *              otherwise false.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_INVALID_INPUT    record_type or skb_select is an invalid value.
 * @retval SEC_NULL_POINTER     Input/output data pointer is NULL.
 * @retval SEC_OUT_OF_MEMORY    Failed to allocate memory.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_process_ccvd_record_header(
                            sec_dev_context_t       sec_dev_context,
                            unsigned long           context_id,
                            unsigned int            skb_select,
                            void *                  encrypted_conditional_data,
                            void *                  column,
                            void *                  generation,
                            bool *                  success);


//--  sec_aacs_generate_title_key  --------------------------------------------
/**
 * THIS FUNCTION IS NOT IMPLEMENTED.
 *
 * This function generates a new random Title Key.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_generate_title_key(sec_dev_context_t       sec_dev_context,
                            unsigned long           context_id);


//--  sec_aacs_get_fw_version  ------------------------------------------------
/**
 * This function returns the version number of the AACS firmware.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[out] aacs_fw_version
 *              AACS firmware version number.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_get_fw_version(sec_dev_context_t       sec_dev_context,
                        unsigned long *         aacs_fw_version);


//--  sec_aacs_process_skf  ---------------------------------------------------
/**
 * This function processes the 278528-byte data in a Segment Key File that is
 * applicable to a specific Sequence Key Block.  The applicable Sequence Key
 * Block must have been processed earlier because the variant data from that
 * SKB is used in the processing.
 *
 * The SKF is parsed one SKB at a time.  For a given SKB, one or more calls
 * to this function may be made to parse the data for the SKB sequentially
 * through the SKF. The data consists of 1024 variant groups of which can be
 * broken down to pass a specified number of variant groups at a time. All
 * 1024 variant groups must be parsed before switching to a different SKB, as
 * switching to a different SKB resets to start parsing at the first variant
 * group for the new SKB.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] skb_select
 *              SKB Number in range [0,5].
 *
 * @param[in] start_of_skb
 *              true to force resetting to start of the SKB in the SKF. Note
 *              that we also automatically reset to the start of the SKB the
 *              first time we are called within a context and also when we
 *              change to a new skb_select.
 *
 * @param[in] skf_data
 *              Pointer to buffer containing 278528 bytes of Segment Key File data
 *              that is associated with the SKB.
 *
 * @param[in] total_variants
 *              Total number of variant groups pointed to by skf_data.
 *
 * @param[out] play_list_id
 *              Filled with the PlayList_ID.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_INVALID_INPUT    record_type or skb_select is an invalid value.
 * @retval SEC_OUT_OF_MEMORY    Failed to allocate memory.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_process_skf(sec_dev_context_t       sec_dev_context,
                     unsigned long           context_id,
                     unsigned int            skb_select,
                     bool                    start_of_skb,
                     void *                  skf_data,
                     unsigned long           total_variants,
                     int *                   play_list_id);

//--  sec_aacs_aes_h_init  ------------------------------------------------------------
/**
 * This function initializes the staged AACS AES-based hashing function.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_aes_h_init( sec_dev_context_t sec_dev_context);

//--  sec_aacs_aes_h_update  ----------------------------------------------------------
/**
 * This function processes the next segment of input data using AES-based hashing
 * function and adds the intermediate result to the SEC context.
 *
 * This AES-based hashing function is compliant with the AACS standard.
 *
 * Note: Use of this function may overwrite previous state set by sec_set_sym_key(),
 * sec_set_asym_key(), and the various SEC hash functions.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] src
 *              A pointer to a buffer containing the input data to be hashed.
 *
 * @param[in] src_size
 *              The length of the src buffer, in bytes.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The src pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE    The src_size is not valid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_aes_h_update (sec_dev_context_t   sec_dev_context,
                       void *              src,
                       unsigned long       src_size);


//--  sec_aacs_aacs_h_final  ----------------------------------------------------------
/**
 * This function completes the staged AES-based hashing function and returns the 
 * message digest from the SEC context.
 *
 * Note: Use of this function may overwrite previous state set by sec_set_sym_key(),
 * sec_set_asym_key(), and the various SEC hash functions.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[out] hash
 *              A pointer to a buffer that receives the hash value. The
 *              caller is responsible for allocating the 16-byte hash buffer
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The hash pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_aes_h_final( sec_dev_context_t sec_dev_context, void *hash);



//--  sec_aacs_get_nonce  ---------------------------------------------------
/**
 * This function generates a 128-bit nonce for usage with AACS Online connections.
 * The nonce will be stored in the specified AACS context and also returned to the
 * caller.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[out] nonce
 *              A pointer to a buffer that receives the nonce. The
 *              caller is responsible for allocating the 16-byte nonce buffer
 *
 * 
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     The nonce pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_get_nonce(sec_dev_context_t       sec_dev_context,
                   unsigned long           context_id,
                   void *                  nonce);       


//--  sec_aacs_permission_verify  ---------------------------------------------------
/**
 * This function encrypts the BD-ROM Online generated Title Key.  It is used by the 
 * application to verify the permissions of the encrypted title key received from 
 * an Online transaction.  The caller must call sec_aacs_generate_nonce prior to 
 * calling this function.
 *
 * Any of the parameters, volume_id, title_id, expected_encrypted_title_key, or
 * success, may be NULL.  Doing so disables the permission verification function
 * (or forces it to fail, depending on which parameters are set NULL), but still
 * causes the previously-generated nonce value to be discarded.
 *
 * @param[in] sec_dev_context
 *              SEC context in which the operation is performed.
 *
 * @param[in] context_id
 *              AACS context ID returned by sec_aacs_create_context().
 *
 * @param[in] volume_id
 *              A pointer to a buffer that contains 16 bytes of volume id.
 *
 * @param[in] title_id
 *              A pointer to a buffer that contains 4 bytes of title id in big endian order.
 *
 * @param[in] expected_encrypted_title_key
 *              A pointer to a buffer that contains the expected encrypted title key.
 *
 * @param[out] success
 *              True is returned here if the encrypted_title_key is successfully
 *              verified, false if otherwise.
 *
 * @retval SEC_SUCCESS          The operation is successfully completed.
 * @retval SEC_FAIL             The operation is failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_INVALID_ID       Invalid AACS context ID.
 * @retval SEC_NULL_POINTER     The volume_id or encrypted_title_key pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aacs_permission_verify(sec_dev_context_t       sec_dev_context,
                           unsigned long           context_id,
                           void *                  volume_id,
                           void *                  title_id,
                           void *                  expected_encrypted_title_key,
                           bool *                  success);    

#ifdef __cplusplus
}
#endif

#endif
