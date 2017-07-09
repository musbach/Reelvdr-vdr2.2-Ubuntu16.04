//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_H
#define SEC_H
#include <stdbool.h>
#include <stdint.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif
/**@mainpage
 *
 * The Security Controller (SEC) driver provides an interface allowing the
 * application to access various cryptographic functions and utilities
 * supported by SEC hardware accelerators and SEC firmware.
 */


/**@defgroup context     Context
 *
 * Before an application can call any of the other functions in the SEC API,
 * it must open the SEC device and allocate a SEC context.
 *
 * A SEC context is used for caching of user-specified and cryptographic state 
 * information.  For Multi-step cryptographic operations, such as staged hashing
 * or cipher block chaining encryption/decryption operations, the intermediate 
 * operation state is kept in the SEC context. 
 */

/**@defgroup key          Key Processing
 *
 * The functions in this group allow setting of the active key in a SEC
 * context, processing of wrapped keys and the caching/invalidation of keys 
 * using the key ladders.
 *
 * SEC supports primary, secondary and software key ladders based on AES and
 * DES algorithms.  In key ladder operations, the AES and 3DES ciphers redirect
 * their output to SEC internal key store which is not visible to the Host. 
 * This enables wrapped keys to be decrypted within the SEC and stored in the
 * clear in internal key store for system use in SEC and TSD cipher operations.
 * 
 * The primary key ladder is reserved for specific CA vendors. 
 * The secondary key ladder is used to wrap off-chip secrets that are stored in
 * external flash.  It can be used for flash encryption or HDCP key load (Intel
 * CE3100 Media Processor only).
 * The software key ladder is reserved for future use and is not supported in
 * this release.  
 */

/**@defgroup crypt        Encryption and Decryption
 *
 * These functions perform encryption and decryption of data. The application
 * should use the key processing functions to set the key before calling most
 * of these functions. If more than one encryption or decryption is taking
 * place simultaneously, a separate context must be created (via sec_dev_open())
 * for each operation.
 */

/**@defgroup hash        Hashing
 *
 * These functions perform staged cryptographic hashing.
 *
 * There are three separate functions defined for each supported algorithm:
 * - The @b _init() function must be called first to initialize the SEC context
 *   for the hash operation.
 * - The @b _update() function is then called once per message stage or segment.
 *   It hashes the input message and adds it to the intermediate result that is
 *   stored in the SEC context.
 * - the @b _final() function completes the operation and returns the final 
 *   message digest from the SEC context.
 */

/**@defgroup hdcp        HDCP
 *
 * These functions perform HDCP-specific operations such as binding an HDCP key
 * module to the platform at manufacturing and loading an encrypted HDCP key
 * module at run time.
 */

/**@defgroup sign        Signing and Verification
 *
 * These functions perform RSASSA-PKCS1-v1_5 signature generation and
 * verification using various hash algorithms.
 */

/**@defgroup rand         Random Numbers
 *
 * Random data is generated using CTR_DRBG (Deterministic Random Bit Generator,
 * using a block cipher algorithm in Counter mode).  See NIST 800-90.
 */

/**@defgroup eau        Large Number Arithmetic
 *
 * These functions perform large number arithmetic operations such as modular
 * exponentiation, modular reduction, large number addition, subtraction, and
 * multiplication using Exponentiation Acceleration Unit in the Security
 * Controller.
 */

/**@defgroup misc        Miscellaneous
 *
 * The functions in this group return information about the Security Core in
 * the target chip and the firmware running on it, and support secure loading
 * of firmware updates.
 */

//--  sec_dev_open  -----------------------------------------------------------
/** @ingroup context
 * This function opens the SEC driver and returns a SEC context to the caller.
 * If successful, it returns a context that must be passed to all other SEC
 * functions. Therefore, it must be called before any other SEC functions can
 * be called.
 *
 * More than one context may be open at a time by an application. Each context
 * retains separate state, such as keys and IV that are used in subsequent 
 * cryptographic operations.
 *
 * When a context is no longer needed, the application should call
 * sec_dev_close() to free the resources allocated for the context.
 *
 *
 * @param[out] sec_dev_context
 *              Pointer to a variable where the SEC context will be returned.
 *
 * @retval SEC_SUCCESS              SEC was opened and a new SEC context was
 *                                      created.
 * @retval SEC_NULL_POINTER         The passed context pointer was NULL.
 * @retval SEC_INTERNAL_ERROR       Invalid input payload size or ioctl
 *                                  SEC_GET_REVISION_ID returned an error
 *                                  or an unknown SEC core PCI revision ID
 *                                  was returned by SEC_GET_REVISION_ID or
 *                                  register_context returned an error
 * @retval SEC_DRIVER_OPEN_FAILURE  Failed to open device.
 * @retval SEC_OUT_OF_MEMORY        Out of memory
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_dev_open( sec_dev_context_t *sec_dev_context);


//--  sec_dev_close  ----------------------------------------------------------
/** @ingroup context
 *
 * This function closes the SEC driver and frees the SEC context.
 *
 * @param[in] sec_dev_context
 *              Pointer to the SEC context that was returned by sec_dev_open().
 *
 * @retval  SEC_SUCCESS             The device was closed successfully.
 * @retval  SEC_NULL_POINTER        The passed pointer was NULL.
 * @retval  SEC_INVALID_CONTEXT     The SEC context is invalid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_dev_close( sec_dev_context_t *sec_dev_context );


//--  sec_set_sym_key  --------------------------------------------------------
/** @ingroup key
 *
 * This function allows the application to provide a key for symmetric
 * encryption/decryption or key cache operations performed by the SEC context.
 *
 * Applications call this API to set cryptographic algorithm, key, cipher
 * chain mode, key location, Initialization Vector, etc. into the SEC context.
 * This is required before calling sec_aes_process_data(),
 * sec_des_process_data(), sec_arc4_process_data() or
 * sec_process_and_store_key(). 
 *
 * Since the context carries the parameters for a specific cryptographic
 * operation, an application could create multiple contexts to support multiple
 * streams.
 *
 * @note 
 *   The context will change after a call to a process data function when
 *   - the one_time_use flag is set to true: key, iv, and other fields are set to 
 *     zero and
 *   - when AES is used in CBC mode: the iv is updated with with the last block.
 *
 *   @note When chaining together a sequence of calls for sec_aes_process_data when 
 *   using CBC mode, call sec_set_sym_key with the one_time_use flag set to false at
 *   the beginning of the chain. Do not call
 *   it again between calls to sec_aes_process_data. This will assure that the
 *   updated iv is preserved in the context. If AES CBC operations are not to be
 *   chained together, the sec_set_sym_key must be called before each call to 
 *   sec_aes_process_data. To be safe call sec_set_sym_key before each process data
 *   call unless chaining is required.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher
 *              The crypto algorithm to be used.
 *
 * @param[in] cipher_chain_mode
 *              The cipher chain mode.
 *
 * @param[in] iv_increment_mode
 *              The iv_increment mode, if cipher_chain_mode is CTR. Ignored
 *              otherwise.
 *
 * @param[in] key_location
 *              Specifies whether the key is an internal or external key.
 *              Depending on the Cryptographic algorithm, the key can be:
 *              - SEC_EXTERNAL_KEY : a key from the host.
 *              - SEC_INTERNAL_KEY : a key stored in the key ladder cache
 *                                   inside the SEC engine. 
 *              - SEC_INTERNAL_KEY_EXT : a key in an internal key slot
 *                                          inside the SEC engine.
 *                                  SEC extended firmware must be loaded.
 *
 *
 * @param[in] key_ladder_id
 *              The key ladder id if the key_location is SEC_INTERNAL_KEY.
 *              Ignored otherwise.
 *
 * @param[in] internal_key_slot
 *              An ID that identifies the internal key location. It depends
 *              on the key_location parameter above.
 *              - SEC_EXTERNAL_KEY : value ignored
 *              - SEC_INTERNAL_KEY : see sec_key_cache_slot_t for values
 *              - SEC_INTERNAL_KEY_EXT : integer key ID
 *
 * @param[in] key
 *              For SEC_EXTERNAL_KEY only.
 *              Pointer to a buffer containing the external key data.
 *              Different cryptographic algorithms support different key
 *              lengths, as follows:\n
 *              - AES: 128-bit, 192-bit, 256-bit
 *              - DES : 64-bit
 *              - 2-key Triple DES : 128-bit
 *              - 3-key Triple DES : 192-bit
 *              - ARC4: 1-256 bytes
 *
 * @param[in] iv
 *              Pointer to a buffer containing the initialization vector
 *              (IV).  Both CBC and CTR modes requires an IV which is the
 *              same size as the cipher block size.
 *
 * @param[in] key_size_in_byte
 *              The length of the key buffer, in bytes. 
 *              For SEC_EXTERNAL_KEY only.
 *
 * @param[in] iv_size_in_byte
 *              The length of the iv buffer, in bytes.
 *
 * @param[in] one_time_use
 *              Flag indicating whether the input key is one-time use only.
 *              This parameter is used for the external keys only.  If it is
 *              set to TRUE (one-time only key), the key in the context will be
 *              invalidated as soon as one encryption or decryption operation
 *              is completed.
 *
 * @retval SEC_SUCCESS              The key is set successfully.
 * @retval SEC_EXT_FW_NOT_LOADED    SEC Ext firmware module has not been loaded
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_INVALID_KEY_LOCATION Invalid key location.
 * @retval SEC_NULL_POINTER         The key or iv is NULL.
 * @retval SEC_INVALID_CHAIN_MODE   Invalid cipher chain mode.
 * @retval SEC_INVALID_CIPHER       Invalid cipher algorithm.
 * @retval SEC_INVALID_KEY_LADDER   Invalid key ladder.
 * @retval SEC_INVALID_KEY_ID       Invalid internal key id.
 * @retval SEC_INVALID_KEY_LENGTH   Invalid key length.
 * @retval SEC_INVALID_IV_LENGTH    Invalid IV length.
 * @retval SEC_UNSUPPORT_FUNCTION   Invalid cipher type for this hardware
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_set_sym_key(sec_dev_context_t       sec_dev_context,
                sec_cipher_t            cipher,
                sec_cipher_chain_mode_t cipher_chain_mode,
                sec_iv_inc_mode_t       iv_increment_mode,
                sec_key_location_t      key_location,
                sec_key_ladder_t        key_ladder_id,
                int                     internal_key_slot,
                unsigned char *         key,
                unsigned char *         iv,
                int                     key_size_in_byte,
                int                     iv_size_in_byte,
                bool                    one_time_use);

//--  sec_set_asym_key  -------------------------------------------------------
/** @ingroup key
 *
 * This function allows the application to set a key for asymmetric
 * encryption/decryption and digital signature operations performed within the
 * specified context.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher
 *      The crypto algorithm.  Currently, only SEC_RSA_CIPHER is supported.
 *
 * @param[in] key_location
 *       Specifies whether the key is an internal or external key.
 *       Depending on the Cryptographic algorithm, the key can be:
 *       - SEC_EXTERNAL_KEY : a key from the host. Currently, 
 *                              only external keys are supported for
 *                              encryption/decryption and signing operations.
 *       - SEC_INTERNAL_KEY_EXT : a key in an internal key slot
 *                                          inside the SEC engine.
 *                                  SEC extended firmware must be loaded.
 *
 * @param[in] internal_key_store
 *      The internal key store id 
 *      - SEC_EXTERNAL_KEY: The value is ignored.
 *      - SEC_INTERNAL_KEY_EXT: The value is a key ID stored in the
 *      SEC extended FW. The FW must be loaded.
 *
 * @param[in] modulus
 *      - SEC_EXTERNAL_KEY: Pointer to a buffer containing the modulus of the 
 *       external key.
 *      - SEC_INTERNAL_KEY_EXT: The value is ignored.
 *
 * @param[in] exponent
 *      - SEC_EXTERNAL_KEY: Pointer to a buffer containing the 
 *      exponent of the external key.
 *      - SEC_INTERNAL_KEY_EXT: The value is ignored.
 *
 * @param[in] mod_size_in_byte
 *      - SEC_EXTERNAL_KEY: Length of the modulus buffer in bytes. 
 *      RSA supports 128- and
 *      256-byte (1024- and 2048-bit) modulus sizes.
 *      - SEC_INTERNAL_KEY_EXT: The value is ignored.
 *
 * @param[in] exp_size_in_byte
 *      - SEC_EXTERNAL_KEY: Length of the exponent buffer in bytes. 
 *      - SEC_INTERNAL_KEY_EXT: The value is ignored.
 *
 * @param[in] one_time_use
 *      Valid for external keys only. If TRUE, the key in the context will
 *      be invalidated as soon as one encryption, decryption, or digital
 *      signature operation is completed.
 *
 * @retval SEC_SUCCESS              The key is set successfully.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The modulus or exponent is NULL.
 * @retval SEC_INVALID_CIPHER       Invalid cipher algorithm.
 * @retval SEC_EXT_FW_NOT_LOADED    The extended firmware is not loaded
 * @retval SEC_INVALID_KEY_LOCATION Invalid key location.
 * @retval SEC_INVALID_KEY_LENGTH   Invalid key length.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_set_asym_key (  sec_dev_context_t   sec_dev_context,
                    sec_cipher_t        cipher,
                    sec_key_location_t  key_location,
                    sec_key_store_t     internal_key_store,
                    unsigned char *     modulus,
                    unsigned char *     exponent,
                    int                 mod_size_in_byte,
                    int                 exp_size_in_byte,
                    bool                one_time_use);

//--  sec_get_fw_version_number  ----------------------------------------------
/** @ingroup misc
 *
 * This function returns the fused firmware version number in the Security
 * Controller.
 *
 * @param[in] sec_dev_context
 *                  The SEC context, returned by sec_dev_open(), in which the
 *                  operation should take place.
 *
 * @param[out] fw_version
 *                  The firmware version number is returned here.
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The modulus or exponent is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_get_fw_version_number ( sec_dev_context_t   sec_dev_context,
                            unsigned long *     fw_version);

//--  sec_get_fw_2000_version  ----------------------------------------------
/** @ingroup misc
 *
 * sec_get_fw_2000_version returns firmware type 2000's version number.
 * if the return value is SEC_SUCCESS then the 2000 firmware is loaded.
 * if the return value is SEC_INVALID_HOST_REQUEST then the 2000 firmware
 * is not loaded.
 *
 * @param[in] sec_dev_context
 *                  The SEC context, returned by sec_dev_open(), in which the
 *                  operation should take place.
 *
 * @param[out] fw_2000_version
 *                  The firmware version number is returned here.
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The SEC ioctl driver operation failed.
 * @retval SEC_INVALID_CONTEXT  sec_dev_context is invalid.
 * @retval SEC_NULL_POINTER     The fw_2000_version pointer is NULL
 * @retval SEC_INVALID_HOST_REQUEST The firmware is not loaded.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_get_fw_2000_version( sec_dev_context_t  sec_dev_context,
                         unsigned long     *fw_2000_version);


//--  sec_get_fw_versions  ----------------------------------------------------
/** @ingroup misc
 *
 * This function returns the fused firmware version number in the Security
 * Controller, along with a list of currently loaded firmware modules and
 * their respective version numbers.
 *
 * @param[in] sec_dev_context
 *                  The SEC context, returned by sec_dev_open(), in which the
 *                  operation should take place.
 *
 * @param[out] rom_fw_version
 *                  The SEC ROM firmware version number is returned here.
 *                  This value may be NULL if the caller does not want this
 *                  value returned.
 *
 * @param[in,out] module_count
 *                  The incoming value is the maximum number of entries in the
 *                  module_list. Upon return, this value is filled with the
 *                  maxium number of entries available for the module_list.
 *                  The actual number of entries returned is the minimum of
 *                  the incoming and returned values.  This value may also be
 *                  NULL if the caller does not want to return a module_list.
 *
 * @param[out] module_list
 *                  The list of module id's and corresponding versions is
 *                  returned here.  This value may also be NULL if module_count
 *                  is either NULL or passed in as zero.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         module_list is NULL while *module_count > 0.
 * @retval SEC_INVALID_DATA_LENGTH  The FW returned an invalid module_count.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_get_fw_versions( sec_dev_context_t    sec_dev_context,
                     unsigned long *      rom_fw_version,
                     unsigned long *      module_count,
                     sec_module_list_t *  module_list );

//--  sec_get_serial_number  ---------------------------------------------------
/** @ingroup misc
 *
 * This function returns the serial number in the Security Controller if
 * enabled by the SetTop box manufacturer.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[out] sn
 *              A 64-bit serial number is returned here.
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The modulus or exponent is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_get_serial_number( sec_dev_context_t sec_dev_context, uint64_t *sn);

//--  sec_aes_process_data  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function performs bulk AES encryption or decryption of data. The
 * application should use sec_set_sym_key() to set the AES key and 
 * initialization vector (requried by CBC and CTR modes) before calling
 * this function. For Chiper Block Chaining (CBC) mode, the state information
 * is kept in the SEC context after each sec_aes_process_data() call for 
 * continuous encryption/decryption operation.  
 * 
 * When using this function with an internal key, the internal 
 * key slot id must be:
 * SEC_CW1 - SEC_CW8 or SEC_CCW1 - SEC_CCW4 or SEC_M1 for encryption.
 * SEC_CW1 - SEC_CW8 or SEC_CCW1 - SEC_CCW4 for decryption.
 *
 * For Cipper Block Chaining (CBC) mode, the state information is saved in the
 * SEC context after each sec_aes_process_data call to support continuous 
 * encryption/decryption operations.
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
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aes_process_data(   sec_dev_context_t   sec_dev_context,
                        sec_cipher_mode_t   cipher_mode,
                        void *              src,
                        void *              dst,
                        unsigned long       size,
                        unsigned long       offset);

//--  sec_aes_process_fragmented_data  ----------------------------------------
/** @ingroup crypt
 *
 * This function performs bulk AES encryption or decryption of data just like
 * sec_aes_process_data(). Review the documentation of sec_aes_process_data()
 * for more information on this function. The differences from
 * sec_aes_process_data() are that this function processes a buffer of periodic
 * fragments instead of one continuous buffer and this function operates only
 * in-place with the same buffer for both src and dst.
 *
 * The buffer is considered to be a stream of fragments. initial_offset
 * specifies how far into the buffer that the first fragment starts.
 * fragment_period_bytes specifies the number of bytes from the start of one
 * fragment to the start of the next. The total number of fragments in the
 * buffer is determined by how many can fit within the buffer of the given
 * size. If Cipher Block Chaining (CBC) mode is used, then
 * continuous_chaining specifies whether or not the CBC chain is reset for
 * each fragment or is continuous across all fragments.  If a fragment is not
 * completely within the specified buffer, it is not processed.
 *
 * @note
 * The best performance is obtained if bfr is of type SEC_ADDR_PHYSCONTIG
 * instead of SEC_ADDR_VIRTUAL.  However, if an address is of type
 * SEC_ADDR_VIRTUAL, in some cases, performance is improved if each fragment
 * is 32-bit aligned.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in,out] bfr
 *              A pointer to a buffer containing the data.
 *
 * @param[in] size
 *              The length of the src and dst buffers, in bytes.
 *
 * @param[in] initial_offset_bytes
 *              The offset from the beginning of the src and dst buffers
 *              at which the first packet begins. The best performance is
 *              obtained if the address at this offset is 32-bit aligned.
 *
 * @param[in] fragment_length_bytes
 *              The length of each fragment to encrypt or decrypt. This
 *              value must be a multiple of 16 bytes.
 *
 * @param[in] fragment_period_bytes
 *              The length, in bytes, from the start of one fragment to the
 *              start of the next. This includes fragment_length_bytes plus
 *              any gap between fragments. This value must be greater than
 *              or equal to fragment_length_bytes. The best performance is
 *              obtained if each fragment is 32-bit aligned.
 *
 * @param[in] continuous_chaining
 *              If true, then the Cipher Block Chaining (CBC) state will
 *              continue from fragment to fragment; otherwise, it will be
 *              to the IV at each fragemnt. This parameter does not apply
 *              to other cipher chaining modes.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The src or dst pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE  Invalid cipher mode.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_INPUT        The buffer type is not SEC_ADDR_VIRTUAL
 *                                  or SEC_ADDR_PHYSCONTIG.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 * @retval SEC_INVALID_DATA_LENGTH  The actual length of input data to be
 *                                  processed in not a multiple of 16 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 16 bytes)
 * @retval SEC_OUT_OF_MEMORY        Failed to allocate an internal buffer.
 * @retval SEC_INVALID_DATA_LENGTH  fragment_length_bytes is not a multiple of
 *                                  16 bytes.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aes_process_fragmented_data( sec_dev_context_t   sec_dev_context,
                                 sec_cipher_mode_t   cipher_mode,
                                 sec_buffer_t *      bfr,
                                 unsigned long       size,
                                 unsigned long       initial_offset_bytes,
                                 unsigned long       fragment_length_bytes,
                                 unsigned long       fragment_period_bytes,
                                 bool                continuous_chaining );

//--  sec_aes_process_fragmented_data_src_dst  --------------------------------
/** @ingroup crypt
 *
 * This function is like sec_aes_process_fragmented_data() except that it has
 * separate buffers for source and destination.
 *
 * There are some complications in the handling of that data inbetween the
 * fragments. Currently, any space at the start (i.e. the first
 * initial_offset_bytes of the buffer), and any space at the end, are not
 * copied to the destination buffer.  Only the spaces between the fragments
 * is copied.  Also, the copying of this data is slow, especially in the
 * case where both buffers are of type SEC_ADDR_PHYSCONTIG.  Future
 * modifications to this function may change this behavior.  Also, this
 * function may be removed in the future.
 *
 * @note
 * The best performance is obtained if bfr is of type SEC_ADDR_PHYSCONTIG
 * instead of SEC_ADDR_VIRTUAL.  However, if an address is of type
 * SEC_ADDR_VIRTUAL, in some cases, performance is improved if each fragment
 * is 32-bit aligned.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in,out] bfr_src
 *              A pointer to the source buffer containing the data.
 *
 * @param[in,out] bfr_dst
 *              A pointer to the destination buffer.
 *
 * @param[in] size
 *              The length of the src and dst buffers, in bytes.
 *
 * @param[in] initial_offset_bytes
 *              The offset from the beginning of the src and dst buffers
 *              at which the first packet begins. The best performance is
 *              obtained if the address at this offset is 32-bit aligned.
 *
 * @param[in] fragment_length_bytes
 *              The length of each fragment to encrypt or decrypt. This
 *              value must be a multiple of 16 bytes.
 *
 * @param[in] fragment_period_bytes
 *              The length, in bytes, from the start of one fragment to the
 *              start of the next. This includes fragment_length_bytes plus
 *              any gap between fragments. This value must be greater than
 *              or equal to fragment_length_bytes. The best performance is
 *              obtained if each fragment is 32-bit aligned.
 *
 * @param[in] continuous_chaining
 *              If true, then the Cipher Block Chaining (CBC) state will
 *              continue from fragment to fragment; otherwise, it will be
 *              to the IV at each fragemnt. This parameter does not apply
 *              to other cipher chaining modes.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The src or dst pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE  Invalid cipher mode.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_INPUT        The buffer type is not SEC_ADDR_VIRTUAL
 *                                  or SEC_ADDR_PHYSCONTIG.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 * @retval SEC_INVALID_DATA_LENGTH  The actual length of input data to be
 *                                  processed in not a multiple of 16 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 16 bytes)
 * @retval SEC_OUT_OF_MEMORY        Failed to allocate an internal buffer.
 * @retval SEC_INVALID_DATA_LENGTH  fragment_length_bytes is not a multiple of
 *                                  16 bytes.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aes_process_fragmented_data_src_dst( sec_dev_context_t   sec_dev_context,
                                         sec_cipher_mode_t   cipher_mode,
                                         sec_buffer_t *      bfr_src,
                                         sec_buffer_t *      bfr_dst,
                                         unsigned long       size,
                                         unsigned long       initial_offset_bytes,
                                         unsigned long       fragment_length_bytes,
                                         unsigned long       fragment_period_bytes,
                                         bool                continuous_chaining );

//--  sec_des_process_data  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function allows the application to perform bulk DES encryption or
 * decryption of data. The application should use sec_set_sym_key() to
 * set the DES keys before calling this function.
 * 
 * When Internal Keys are used, only 2-key Triple DES encryption and decryption
 * is allowed.
 *
 * @note
 * This API doesn't support multi-step DES-CBC operation.  To perform
 * multi-step operation with CBC mode, the application should use
 * sec_set_sym_key to set the IV to the previous encrypted block before
 * calling sec_des_process_data to process the next block of data.
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
 *              be multiple of 8 bytes.
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
 *                                  processed in not a multiple of 8 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 8 bytes)
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_des_process_data (  sec_dev_context_t   sec_dev_context,
                        sec_cipher_mode_t   cipher_mode,
                        void *              src,
                        void *              dst,
                        unsigned long       size,
                        unsigned long       offset);


//----- sec_rsa_sign_md  ------------------------------------------------------
/** @ingroup sign
 *
 * This function performs signing of the previously-generated message digest
 * passed to it.
 * 
 * The RSA signing algorithm is PKCS #1 v2.1 compliant (RSASSA-PKCS1-v1.5
 * mode).
 *
 * The private exponent and modulus must be set prior to calling this function
 * via sec_set_asym_key().
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] digest_type   
 *               Type of passed digest. Identifies the hashing function used
 *               to generate a digest. MD5, SHA1, SHA256, SHA384 and SHA512
 *               digests are accepted.
 *  
 * @param[in] digest_src
 *               Pointer to digest source.
 *
 * @param[in] digest_size
 *               Size of digest_src in bytes.
 *
 * @param[out] signature 
 *               Pointer to a returned signature. Caller must insure there
 *               is enough space in passed buffer. Buffer has to be at least
 *               'modulus' size bytes long.
 *
 * @param[in]  sig_size
 *                Size of 'signature' buffer passed in bytes.
 *
 * @retval SEC_SUCCESS           Signing was successful
 * @retval SEC_FAIL              The operation failed.
 * @retval SEC_INVALID_CONTEXT   SEC context is invalid.
 * @retval SEC_NULL_POINTER      The key pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE Buffer size is not valid
 */
//-----------------------------------------------------------------------------
sec_result_t 
sec_rsa_sign_md(sec_dev_context_t       sec_dev_context,
                sec_rsa_digest_type_t   digest_type,
                void                  * digest_src,
                unsigned int            digest_size,
                void                  * signature,
                unsigned int            sig_size);


//--  sec_rsa_verify_md  ------------------------------------------------------
/** @ingroup sign
 *
 * This function verifies the passed message digest. 
 *
 * The RSA signing algorithm is PKCS #1 v2.1 compliant (RSASSA-PKCS1-v1.5 mode).
 *  
 * The public exponent and modulus must be set prior to calling this function
 * via sec_set_asym_key().
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] digest_type
 *              Type of passed message digest. Identifies the hashing function
 *              that was used to generate the digest. MD5, SHA1, SHA256, SHA384
 *              and SHA512 digests are accepted.
 *
 * @param[in] digest_src
 *              Pointer to the buffer containing the message digest.
 *
 * @param[in] digest_size
 *              Size of digest_src buffer in bytes.
 *
 * @param[in] signature
 *              Signature of the digest that needs to be verified.
 *
 * @param[in] sig_size
 *              Size of signature buffer in bytes.
 *
 * @param[out] success
 *              Pointer to a verification result. Returns 1 if verification
 *              passed, 0 otherwise.
 *
 * @retval SEC_SUCCESS          Operation succeeded. This does not mean
 *                              that verification passed. 
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The key pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_rsa_verify_md(  sec_dev_context_t       sec_dev_context,
                    sec_rsa_digest_type_t   digest_type,
                    void                  * digest_src,
                    unsigned int            digest_size,
                    void                  * signature,
                    unsigned int            sig_size,
                    bool                  * success);

//--  sec_rsa_set_signature_scheme  -------------------------------------------
/** @ingroup sign
 *
 * This function sets the RSA Signature Scheme to be used by the RSA
 * signature functions sec_rsa_sign_md() and sec_rsa_verify_md().  Any
 * subsequent RSA signature functions called with this sec_dev_context
 * will use the specified signature scheme.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), for which
 *              the signature scheme will be set.
 * 
 * @param[in] scheme
 *              The signature scheme to be used in any future RSA
 *              signature functions on this sec_dev_context
 *
 * @retval SEC_SUCCESS The operation completed successfully.
 * @retval SEC_FAIL    The operation failed.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_rsa_set_signature_scheme(   sec_dev_context_t       sec_dev_context,
                                sec_signature_t         scheme);

//--  sec_rsa_process_data  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function performs RSAES-OAEP encryption or decryption of data.  The
 * hashing function used in RSAES-OAEP encryption is SHA1. The application
 * should use sec_set_asym_key() function to set the RSA private or public key
 * before calling this function.
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
 *              See the "dst_size" for size information.
 *
 * @param[in] src_size
 *      The length of the src buffer, in bytes. For encryption it must be less
 *      than size of modulus - 41 bytes. For decryption is must be equal to
 *      modulus size. (128 or 256 bytes)
 *
 * @param[in] dst_size
 *              The length of the dst buffer, in bytes.  For encryption
 *              it must be the same size as the key modulus size.
 *              For decryption is must be large enough to hold the 
 *              message. 
 *              - SEC_INTERNAL_EXT_KEY it is not possible
 *              to check this value and it is not used by the SEC.
 *              As a result, this parameter it is ignored.
 *	        Incorrecting allocating the size of the destination
 *              buffer may overwrite it corrupting the application.
 *              256 bytes is a safe size for the destination buffer.
 *              See "dst" parameter.
 *
 * @param [out] result_size
 *              The amount of data written to 'dst' buffer. During encryption
 *              returned amount will be the size of modulus, while during
 *              decryption the returned amount will be the size of the clear
 *              text recovered.
 *              - SEC_INTERNAL_EXT_KEY the FW does not return the size
 *              for encryption. We do not know the size of the modulus
 *              because we only have the key's ID. Therefore, 0 is returned.
 *              The programmer will need to determine the result size in
 *              some other fassion. 
 *
 * @retval SEC_SUCCESS             The operation completed successfully.
 * @retval SEC_FAIL                The operation failed.
 * @retval SEC_INVALID_CONTEXT     SEC context is invalid.
 * @retval SEC_NULL_POINTER        The src or dst pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE Invalid cipher mode.
 * @retval SEC_INVALID_BUFF_SIZE   Invalid input or output buffer size.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_rsa_process_data(   sec_dev_context_t   sec_dev_context,
                        sec_cipher_mode_t   cipher_mode,
                        void *              src,
                        void *              dst,
                        unsigned long       src_size,
                        unsigned long       dst_size,
                        unsigned long     * result_size);

//--  sec_sha_init  ------------------------------------------------------------
/** @ingroup hash
 *
 * This function initializes the staged SHA message digest function.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] mode
 *              The SHA mode.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_UNSUPPORTED_SHA_MODE Unsupported SHA mode.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_sha_init( sec_dev_context_t sec_dev_context, sec_sha_mode_t mode);

//--  sec_sha_update  ----------------------------------------------------------
/** @ingroup hash
 *
 * This function processes the next segment of input data using SHA and adds
 * the intermediate result to the SEC context.
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
 * @retval SEC_UNSUPPORTED_SHA_MODE Unsupported SHA mode.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_sha_update (sec_dev_context_t   sec_dev_context,
                void *              src,
                unsigned long       src_size);


//--  sec_sha_final  ----------------------------------------------------------
/** @ingroup hash
 *
 * This function completes the staged SHA hashing function and returns the 
 * message digest from the SEC context.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[out] hash
 *              A pointer to a buffer that receives the hash value. The
 *              caller is responsible for allocating an appropriate length
 *              hash buffer based on the SHA mode used:
 *              - SHA1  : 20 bytes
 *              - SHA224: 28 bytes
 *              - SHA256: 32 bytes
 *              - SHA384: 48 bytes
 *              - SHA512: 64 bytes
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The hash pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_sha_final( sec_dev_context_t sec_dev_context, void *hash);


//--  sec_md5_init  ------------------------------------------------------------
/** @ingroup hash
 *
 * This function initializes the staged MD5 message digest function.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_md5_init ( sec_dev_context_t sec_dev_context);


//--  sec_md5_update  ---------------------------------------------------------
/** @ingroup hash
 *
 * This function processes the next segment of input data using MD5 and adds
 * the intermediate result to the SEC context.
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
 * @retval SEC_SUCCESS           The operation completed successfully.
 * @retval SEC_FAIL              The operation failed.
 * @retval SEC_INVALID_CONTEXT   SEC context is invalid.
 * @retval SEC_NULL_POINTER      The src pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE The src_size is not valid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_md5_update (    sec_dev_context_t   sec_dev_context,
                    void *              src,
                    unsigned long       src_size);

//--  sec_md5_final  ----------------------------------------------------------
/** @ingroup hash
 *
 * This function completes the staged MD5 hashing function and returns the 
 * message digest from the SEC context.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[out] hash
 *              Pointer to a buffer that receives the hash value. The
 *              caller is responsible for allocating 16 bytes the hash buffer.
 *
 * @retval SEC_SUCCESS          The operation completed successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The hash pointer is NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_md5_final ( sec_dev_context_t sec_dev_context, void *hash);


//--  sec_get_random_data  ----------------------------------------------------
/** @ingroup rand
 *
 * This function returns the specified amount of random data.
 *
 * The application can add additional entropy to the mechanism used to generate
 * the data.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] additional_entropy
 *              A pointer to a buffer containing the additional entropy. The
 *              entropy will be incorporated into the CTR_DRBG Reseed process
 *              as stipulated in NIST 800-90. This parameter is ignored if
 *              @b entropy_size is 0.
 *
 * @param[in] entropy_size
 *              The size, in bytes, of the entropy buffer. The size must be a
 *              multiple of 4 bytes and may not be greater than 100 bytes.
 *
 * @param[in] random_data_size
 *              The size, in bytes, of the requested random data. The caller
 *              may request up to 256 bytes of random data per call.
 *
 * @param[out] random_data
 *              A pointer to a buffer that receives the random number.  The
 *              caller is responsible for allocating an approriate size
 *              buffer. The returned random data is in big endian format.
 *
 * @retval SEC_SUCCESS                      The operation completed successfully
 * @retval SEC_FAIL                         The operation failed.
 * @retval SEC_INVALID_CONTEXT              SEC context is invalid.
 * @retval SEC_NULL_POINTER                 The random_data pointer is NULL.
 * @retval SEC_INVALID_ENTROPY_SIZE         Invalid entropy size.
 * @retval SEC_INVALID_RANDOM_NUMBER_SIZE   The size is not valid.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_get_random_data (   sec_dev_context_t   sec_dev_context,
                        void *              additional_entropy,
                        unsigned long       entropy_size,
                        unsigned long       random_data_size,
                        unsigned char *     random_data);


//--  sec_reseed  --------------------------------------------------------------
/** @ingroup rand
 *
 * This function performs reseeding of the global context used by
 * sec_get_random_data(). Refer to NIST 800-90 for CTR_DRBG reseeding
 * mechanism.
 *
 * The application can add additional entropy to the reseed mechanism up to 100
 * bytes in length.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] additional_entropy
 *              A pointer to a buffer containing the additional entropy. The
 *              entropy will be incorporated into the CTR_DRBG Reseed process
 *              as stipulated in NIST 800-90.  This parameter is ignored if
 *              @b entropy_size is 0.
 *
 * @param[in] entropy_size
 *              The length of the entropy buffer, in bytes. The entropy size
 *              must be a multiple of 4 bytes and may not be greater than 100
 *              bytes.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The entropy_size is greater than 0 but the
 *                                      additional_entropy pointer is NULL.
 * @retval SEC_INVALID_ENTROPY_SIZE Invalid entropy size.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_reseed(     sec_dev_context_t   sec_dev_context,
                void *              additional_entropy,
                unsigned long       entropy_size);


//--  sec_authenticate_and_load_FW_module  ------------------------------------
/** @ingroup misc
 *
 * This function allows the application to authenticate, load, and optionally
 * decrypt an SEC firmware update module. The SEC FW module is encrypted and
 * signed by Intel.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] header
 *              A pointer to a buffer containing the 128-byte ICSS Header.
 *
 * @param[in] body
 *              A pointer to a buffer containing the ICSS Module.
 *
 * @param[in] body_size
 *              The length of the body buffer, in bytes. The maximum size
 *              allowed is 49152 bytes.
 *
 * @param[in] signature
 *              A pointer to a buffer containing the signature data to be
 *              verified.
 *
 * @param[in] encrypted
 *              A flag indicating whether the body is encrypted or not. 0
 *              is not encrypted, 1 is encrypted.
 *
 * @param[out] success
 *              TRUE is returned here if the module is authenticated, and
 *              loaded. FALSE is returned if the module failed with
 *              authentication or any error occurred.
 *
 * @retval SEC_SUCCESS                 The key is set successfully.
 * @retval SEC_FAIL                    The operation failed.
 * @retval SEC_INVALID_CONTEXT         SEC context is invalid.
 * @retval SEC_NULL_POINTER            The pin pointer is NULL.
 * @retval SEC_INVALID_FW_MODULE_SIZE  Invalid body_size.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_authenticate_and_load_FW_module (   sec_dev_context_t   sec_dev_context,
                                        void *              header,
                                        void *              body,
                                        unsigned long       body_size,
                                        void *              signature,
                                        bool                encrypted,
                                        bool *              success);

//--  sec_eau_multiply  -------------------------------------------------------
/** @ingroup eau
 *
 * This function performs the multiplication (r=a*b) operation. It supports
 * operands from 256 bits up to 2048 bits in 256-bit increments. It assumes
 * that all input operands (a and b) are the same size. The result data size,
 * in bytes, is the size of input operand *2.  The caller is responsible for
 * allocating the result buffer.
 *
 * @note
 * This API is not supported in this release.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] a
 *              A pointer to a buffer containing operand 'a' data.
 *
 * @param[in] b
 *              A pointer to a buffer containing operand 'b' data.
 *
 * @param[in] size_bytes
 *              The input operand size in bytes.
 *
 * @param[out] r
 *              A pointer to a buffer that receives the result data. The caller
 *              is responsible for allocating an appropriate size (2 *
 *              size_bytes) buffer.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid operand size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_eau_multiply(   sec_dev_context_t   sec_dev_context,
                    void *              a,
                    void *              b,
                    unsigned int        size_bytes,
                    void *              r);

//--  sec_eau_montgomery_mul  --------------------------------------------------
/** @ingroup eau
 *
 * This function performs the Montgomery multiplication (r = a * b * R-1  mod
 * n) operation.  Where r, a, and b are Montgomery Residues and R is the next
 * highest power of 2 larger than the modulus. It supports operands from 256
 * bits up to 2048 bits in 256-bit increments.  It assumes that all input
 * operands (a, b and n) are the same size as the result(r) and the caller is
 * responsible for allocating the result buffer.
 *
 * @note
 * This API is not supported in this release.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] a
 *              A pointer to a buffer containing operand 'a' data.
 *
 * @param[in] b
 *              A pointer to a buffer containing operand 'b' data.
 *
 * @param[in] n
 *              A pointer to a buffer containing the modulus.
 *
 * @param[in] size_bytes
 *              The input operand size, in bytes.
 *
 * @param[out] r
 *              A pointer to a buffer that receives the result data.  The
 *              caller is responsible for allocating an appropriate size
 *              buffer.
 *
 * @retval SEC_SUCCESS             The operation completed successfully.
 * @retval SEC_FAIL                The operation failed.
 * @retval SEC_INVALID_CONTEXT     SEC context is invalid.
 * @retval SEC_NULL_POINTER        The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE   Invalid operand size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_eau_montgomery_mul( sec_dev_context_t   sec_dev_context,
                        void *              a,
                        void *              b,
                        void *              n,
                        unsigned int        size_bytes,
                        void *              r);

//--  sec_eau_modular_exp  ----------------------------------------------------
/** @ingroup eau
 *
 * This function performs the modular exponentiation (r=m^e mod n) operation.
 * It supports operands from 256 bits up to 2048 bits in 256-bit increments.
 * It assumes that all input operands (m, e and n) are the same size as the
 * result (r) and the caller is responsible for allocating the result buffer.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] m
 *              A pointer to a buffer containing operand 'm' data.
 *
 * @param[in] e
 *              A pointer to a buffer containing operand 'e' (exponent) data.
 * @param[in] n
 *              A pointer to a buffer containing operand 'n' (modulus) data.
 *
 * @param[out] r
 *              A pointer to a buffer that receives the result data. The caller
 *              is responsible for allocating an appropriate size buffer.
 *
 * @param[in] size_bytes
 *              The input operand size, in bytes.
 *
 * @retval SEC_SUCCESS             The operation completed successfully.
 * @retval SEC_FAIL                The operation failed.
 * @retval SEC_INVALID_CONTEXT     SEC context is invalid.
 * @retval SEC_NULL_POINTER        The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE   Invalid operand size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_eau_modular_exp(    sec_dev_context_t   sec_dev_context,
                        void *              m,
                        void *              e,
                        void *              n,
                        void *              r,
                        unsigned int        size_bytes);

//--  sec_eau_modular_reduction  ----------------------------------------------
/** @ingroup eau
 *
 * This function performs the modular reduction (a mod n) operation where a is
 * up to 4096 bits and n is up to 2048 bits. The result (r) size is the same
 * size as the modulus (n) size and the caller is responsible for allocating
 * the result buffer.
 *
 * @note
 * This API is not supported in this release.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] a
 *              A pointer to a buffer containing operand 'a' data.
 *
 * @param[in] n
 *              A pointer to a buffer containing operand 'n' (modulus) data.
 *
 * @param[out] r
 *              A pointer to a buffer that receives the result data. The caller
 *              is responsible for allocating an appropriate size buffer.
 *
 * @param[in] size_bytes
 *              The input operand size, in bytes.
 *
 * @retval SEC_SUCCESS             The operation completed successfully.
 * @retval SEC_FAIL                The operation failed.
 * @retval SEC_INVALID_CONTEXT     SEC context is invalid.
 * @retval SEC_NULL_POINTER        The input pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE   Invalid operand size
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_eau_modular_reduction(  sec_dev_context_t   sec_dev_context,
                            void *              a,
                            void *              n,
                            void *              r,
                            unsigned int        size_bytes);

//--  sec_process_and_set_internal_key  ---------------------------------------
/** @ingroup key
 *
 * This function allows the application to wrap or unwrap a key and save the
 * resultant key to the internal SEC key slot using AES, DES or 2-key Triple
 * DES (2TDES) algorithms.
 *
 * For the AES algorithm, the key input must be 128 bits.
 * For the 2TDES algorithm, 128-bit key input is supported with all destination
 * key slots. 64-bit key input is only supported when the destination key slot
 * is CW1-CW8 and CCW1-CCW4. In addition, recursive key ladder operations are
 * only valid if a 128-bit key is used.
 *
 * @note
 * Some combinations of parameters may not be supported on all media processors.
 *
 * This allows application software running on the host CPU to
 * - wrap a 128-bit AES or DES key in external non-volatile
 *   memory, with a storage key (key encryption key) that is rooted in SEC, or
 * - decrypt the cipher key into hidden internal key cache for AES or DES
 *   cryptographic operations.
 *
 * For media processors that support it, the resultant key may be stored in a
 * TSD key slot, as indicated by the parameters tsd_key_location and
 * tsd_key_attributes. If this is not supported or not used, these parameters
 * should be passed as SEC_TSD_KEYLOC_NONE and SEC_TSD_KEYATTR_NONE,
 * respectively.
 *
 * The following rules are enforced to allow only certain keys to
 * encrypt/decrypt other keys in the key cache.
  
   @verbatim
   Cipher  | Key Encryption/ | src_location  | dst_key_slot  | source        |
   Mode    | Decryption key  | Source        | Destination   | size          |
           |                 |(sec_key_cache |(sec_key_cache |               |
           |                 | _slot_t enum) | _slot_t enum) |               |
   --------+-----------------+---------------+---------------+---------------+
   Encrypt | SEC on-chip     |               |               |               |  
   or      | root key        | System memory | M1            | 16 bytes      |
   Decrypt | (PSK or SSK)    | (SEC_MEMORY)  | (SEC_M1)      |               |
   --------+-----------------+---------------+---------------+---------------+
           | SEC on-chip     |               |               |               |
   Decrypt | root key        | System memory | N1            | 16 bytes      |
           | (PSK or SSK)    | (SEC_MEMORY)  | (SEC_N1)      |               |
   --------+-----------------+---------------+---------------+---------------+
   Encrypt |                 |               | M2a,b,c (     |               |
   or      | M1              | System memory |SEC_M2a,SEC_M2b| 16 bytes      |
   Decrypt |                 | (SEC_MEMORY)  | SEC_M2c)       |               |
   --------+-----------------+---------------+---------------+---------------+
   Decrypt | N1              | System memory | N2            | 16 bytes      |
           |                 | (SEC_MEMORY)  | (SEC_N2)      |               |
   --------+-----------------+---------------+---------------+---------------+
   Decrypt | N2              | System memory | CW1-CW8       | 16 or 8 bytes |
           |                 | (SEC_MEMORY)  | (SEC_CW1      |               |
           |                 |               | -SEC_CW8)     |               |
   --------+-----------------+---------------+---------------+---------------+
   Encrypt |                 | System memory | CW1-CW8       |               |
   or      | M2a,b,c, N2     | (SEC_MEMORY)  | (SEC_CW1      | 16 or 8 bytes |
   Decrypt |                 |               | -SEC_CW8)     |               |
   --------+-----------------+---------------+---------------+---------------+
   Encrypt | System memory   | System memory | CCW1-CCW4     |               |
   or      | M2a,b,c         | (SEC_MEMORY)  | (SEC_CCW1     |               |
   Decrypt | N2              |               | -SEC_CCW4)    | 16 or 8 bytes |
           | CW1-CW8         |               |               |               |
           | CCW1-CCW4       |               |               |               |
   --------+-----------------+---------------+---------------+---------------+

   @endverbatim
  
 * @note
 * The application should use sec_set_sym_key() function to set cryptographic
 * algorithm, cipher chain mode, key location, Initialization Vector and the
 * key encryption/decryption key in the internal key slot before calling this
 * function.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in] src_location
 *              The location containing the key to be encrypted or decrypted.
 *              This value dictates whether the key is from the SEC internal
 *              key store or system memory.  Currently, only SEC_MEMORY (key
 *              from the system memory) is supported.
 *
 * @param[in] src_data
 *              A pointer to a buffer containing the cipher key to
 *              be encrypted or decrypted. This argument is used when SEC_MEMORY
 *              is specified in the src_location argument.
 *
 * @param[in] src_size_in_bytes
 *              The size of the input cipher key. Supported values are:
 *                  16 bytes (128 bits) TDES and AES
 *                   8 bytes ( 64 bits) TDES only if the dst_key_slot is
 *                                    CW1-CW8 or CCW1-CCW4.
 *
 * @param[in] dst_key_slot
 *              The key slot in the key cache in which to store the output data.
 *
 * @param[in] tsd_key_location
 *              The TSD key store location to store the key to, or
 *              SEC_TSD_KEYLOC_NONE to not store to the TSD key store.
 *              For CE3100 and CE4100, only SEC_TSD_KEYLOC_NONE is supported;
 *              otherwise, valid key slots are in the range [0,143].
 *
 * @param[in] tsd_key_attributes
 *              The cipher to assign to the key in the TSD key store location,
 *              or SEC_TSD_KEYATTR_NONE if tsd_key_location is set to
 *              SEC_TSD_KEYLOC_NONE.
 *
 * @retval SEC_SUCCESS              The key is set successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The src_data pointer is NULL when
 *                                      src_location is SEC_MEMORY.
 * @retval SEC_INVALID_CIPHER_MODE  Invalid cipher mode.
 * @retval SEC_INVALID_SRC_LOCATION Invalid source location.
 * @retval SEC_INVALID_KEY_ID       Invalid key slot for storing output data.
 * @retval SEC_INVALID_KEY_LOCATION Invalid value for tsd_key_location.
 * @retval SEC_OUT_OF_MEMORY        Could not allocate memory
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_process_and_set_internal_key(sec_dev_context_t       sec_dev_context,
                                 sec_cipher_mode_t       cipher_mode,
                                 sec_key_cache_slot_t    src_location,
                                 void *                  src_data,
                                 unsigned int            src_size_in_bytes,
                                 sec_key_cache_slot_t    dst_key_slot,
                                 unsigned int            tsd_key_location,
                                 sec_tsd_key_attrs_t     tsd_key_attributes );

//--  sec_process_and_set_in_key_cache  ---------------------------------------
/** @ingroup key
 *
 * @note
 * DEPRECATED: See sec_process_and_set_internal_key().
 *
 * The equivalent of this function can be acheived with
 * sec_process_and_set_internal_key() by passing the following values to the
 * additional parameters:
 *   - tsd_key_location: set to SEC_TSD_KEYLOC_NONE
 *   - tsd_key_attributes: set to SEC_TSD_KEYATTR_NONE
 *
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_process_and_set_in_key_cache(  sec_dev_context_t       sec_dev_context,
                                   sec_cipher_mode_t       cipher_mode,
                                   sec_key_cache_slot_t    src_location,
                                   void *                  src_data,
                                   unsigned int            src_size_in_bytes,
                                   sec_key_cache_slot_t    dst_key_slot );

//--  sec_process_and_store_key  ----------------------------------------------
/** @ingroup key
 *
 * @note
 * DEPRECATED: See sec_process_and_set_internal_key().
 *
 * The equivalent of this function can be acheived with
 * sec_process_adn_set_internal_key() by passing the following values to the
 * additional parameters:
 *   - src_size_in_bytes: set to 16
 *   - tsd_key_location: set to SEC_TSD_KEYLOC_NONE
 *   - tsd_key_attributes: set to SEC_TSD_KEYATTR_NONE
 *
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_process_and_store_key(  sec_dev_context_t       sec_dev_context,
                            sec_cipher_mode_t       cipher_mode,
                            sec_key_cache_slot_t    src_location,
                            void *                  src_data,
                            sec_key_cache_slot_t    dst_key_slot );

//--  sec_set_internal_key  ---------------------------------------------------
/** @ingroup key
 *
 * This function allows the application to send a clear 128-bit AES or 64-bit
 * DES key to the specified slot in the software key ladder.
 *
 * @note
 * This API is not supproted on all SOC. If a SOC is not enabled for this
 * operation, this function will return SEC_INVALID_HOST_REQUEST error code.
 *
 * @note
 * For the Intel(R) Atom(TM) processor CE4100 series, the key can only be
 * used by the TSD (demux).  The SEC internal key slot is invalid.  Also,
 * if SEC_TSD_KEYLOC_NONE is used, then it will still load the key to the
 * TSD, but store it in TSD slot 0x8F.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] key
 *              A pointer to a buffer containing the 128-bit AES key or
 *              64-bit DES key.
 *
 * @param[in] key_size_in_byte
 *              The key size in bytes.
 *
 * @param[in] dst_key_slot
 *              The key slot in the key cache to store the clear key. The valid
 *              values are SEC_CCW1, SEC_CCW2, SEC_CCW3 and SEC_CCW4.
 *
 * @param[in] tsd_key_location
 *              The TSD key store location to store the key to, or
 *              SEC_TSD_KEYLOC_NONE to not store to the TSD key store.
 *              For CE3100 and CE4100, only SEC_TSD_KEYLOC_NONE is supported;
 *              otherwise, valid key slots are in the range [0,143].
 *
 * @param[in] tsd_key_attributes
 *              The cipher to assign to the key in the TSD key store location,
 *              or SEC_TSD_KEYATTR_NONE if tsd_key_location is set to
 *              SEC_TSD_KEYLOC_NONE.
 *
 * @retval SEC_SUCCESS              The key is set successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The key pointer is NULL.
 * @retval SEC_INVALID_KEY_LENGTH   Invalid key length..
 * @retval SEC_INVALID_KEY_ID       Invalid key slot for storing the clear key.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_set_internal_key( sec_dev_context_t     sec_dev_context,
                      void *                key,
                      int                   key_size_in_byte,
                      sec_key_cache_slot_t  dst_key_slot,
                      unsigned int          tsd_key_location,
                      sec_tsd_key_attrs_t   tsd_key_attributes );

//--  sec_set_key_in_key_cache  -----------------------------------------------
/** @ingroup key
 *
 * @note
 * DEPRECATED: See sec_set_internal_key().
 *
 * The equivalent of this function can be acheived with
 * sec_set_internal_key() by passing the following values to the
 * additional parameters:
 *   - tsd_key_location: set to SEC_TSD_KEYLOC_NONE
 *   - tsd_key_attributes: set to SEC_TSD_KEYATTR_NONE
 *
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_set_key_in_key_cache(   sec_dev_context_t       sec_dev_context,
                            void *                  key,
                            int                     key_size_in_byte,
                            sec_key_cache_slot_t    dst_key_slot);

//--  sec_invalidate_key_in_key_cache  ----------------------------------------
/** @ingroup key
 *
 * This function allows the application to invalidate a key in the specified
 * slot of key cache.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] key_ladder_id
 *              The key ladder id.
 *
 * @param[in] key_slot
 *              The key slot in the key cache to be invalidated. 
 *              If SEC_SSK or SEC_PSK is specified, the entire key ladder is 
 *              invalidated.
 *
 * @retval SEC_SUCCESS             The key is set successfully.
 * @retval SEC_FAIL                The operation failed.
 * @retval SEC_INVALID_CONTEXT     SEC context is invalid.
 * @retval SEC_INVALID_KEY_LADDER  Invalid key ladder.
 * @retval SEC_INVALID_KEY_ID      Invalid key slot.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_invalidate_key_in_key_cache(    sec_dev_context_t       sec_dev_context,
                                    sec_key_ladder_t        key_ladder_id,
                                    sec_key_cache_slot_t    key_slot);

//--  sec_wrap_flash_key  -----------------------------------------------------
/** @ingroup key
 *
 * This function perform wrap a flash encryption key with an on chip secret.
 * This function must be used prior to performing a secure boot with an
 * encrypted S1 bootloader.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in,out] flash_key
 *              A pointer to a buffer containing a 16-byte flash encryption
 *              key.  The flash encryption key will be wrapped with an on
 *              chip secret and written back to this buffer.
 *
 * @retval SEC_SUCCESS          The key is set successfully.
 * @retval SEC_FAIL             The operation failed.
 * @retval SEC_INVALID_CONTEXT  SEC context is invalid.
 * @retval SEC_NULL_POINTER     The key pointer is NULL.
 */
//----------------------------------------------------------------------------
sec_result_t
sec_wrap_flash_key ( sec_dev_context_t sec_dev_context, void *flash_key);


//--  sec_copy_context  --------------------------------------------------
/**
 * THIS FUNCTION IS NO LONGER SUPPORTED AND ALWAYS DOES NOTHING BUT RETURN WITH
 * SEC_NOT_SUPPORTED.
 *
 * THIS FUNCTION IS DEPRECATED AND WILL BE REMOVED IN FUTURE SDKS.
 *
 * @param[in] src_dev_context
 *              SEC context returned by sec_dev_open().
 *
 * @param[in] dst_dev_context
 *              SEC context returned by sec_dev_open().
 *
 * @retval SEC_NOT_SUPPORTED       This function is no longer supported.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_copy_context ( sec_dev_context_t   src_dev_context,
                   sec_dev_context_t   dst_dev_context);


//--  sec_arc4_process_data  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function allows the application to perform bulk ARC4 encryption or
 * decryption of data. The actual length of input data to be processed must be
 * a multiple of 4 bytes. The application should use sec_set_sym_key() to
 * intialize a new ARC4 keystream before calling this function.  The key state is 
 * stored in the SEC context. The application can call this function multiple times
 * using the same SEC context if the input data is not available in a given window 
 * of time. 
 *
 * @note
 * When calling sec_set_sym_key() to initialize a new keystream. If the key is 
 * less than 256 bytes, the driver will pad the key to 256 bytes by concatenating
 * the key to itself repeatedly until it is 256 bytes. Also, only external keys 
 * (SEC_EXTERNAL_KEY) are supported by this function.
 *
 * @note
 * This API is only supported on Intel Atom Processor CE 4100
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] src
 *              A pointer to a buffer containing the input data.
 *
 * @param[out] dst
 *              A pointer to a buffer that will receive the output data.
 *
 * @param[in] size
 *              The length of the src and dst buffers, in bytes.
 *
 * @param[in] offset
 *              The offset from the beginning of the src and dst buffers
 *              at which the operation should begin.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The src or dst pointer is NULL.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 * @retval SEC_INVALID_KEY_LENGTH   Invalid key length.
 * @retval SEC_INVALIDE_DATA_LEGNTH The actual length of input data to be
 *                                  processed in not a multiple of 4 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 4 bytes)
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_arc4_process_data ( sec_dev_context_t   sec_dev_context,
                        void *              src,
                        void *              dst,
                        unsigned long       size,
                        unsigned long       offset);

// ---- _sec_ext_get_key_info
// Implementation moved from sec_ext.c to here so it can be used by
// RSA sign and verify to get the signature size

sec_result_t
_sec_ext_get_key_info (   sec_dev_context_t     sec_dev_context,
                         unsigned int          key_id,
                         void*                 key_header,
			  void*                 public_key);

//--------------------------------------------------
//sec_check_tdp
/*
* Checks whether TDP is enabled
* if TDP is enabled, checks that TDP FW is loaded
* @param[in] sec_dev_context
*            The SEC context, returned by sec_dev_open(),
*             in which the, operation should take place.
* @retval     status
*             A pointer to status value
*             Status returns the TDP status based on configuration
*             value can be any of the following:
*             PMR_DISABLED: TDP is disabled
*             PMR_ENABLED_FW_LOADED: 
*                TDP is enabled and TDP FW supported by CEFDK
*             PMR_ENABLED_FW_TB_LOADED 
*                TDP is enabled and TDP FW need to be loaded
*/
//--------------------------------------------------

sec_result_t 
sec_check_tdp(sec_dev_context_t sec_dev_context, int *status);

//--------------------------------------------------
//sec_init_tdp
// Triggers the FW to validate the TDP configuration
// of PMR and MEU registers
/* @param[in] sec_dev_context
*            The SEC context, returned by sec_dev_open(),
*             in which the, operation should take place.
*/
//--------------------------------------------------
sec_result_t
sec_init_tdp(sec_dev_context_t context);

//--  sec_get_internal_key_id  ---------------------------------------------------
/** @ingroup crypt
 *
 * Translates the input key_slot_id to and internal key ID and returns it
 * at the location pointed to by internal_key_id
 *
 * @param[in] key_slot_id
 *              This is the input key slot ID.
 *
 * @param[out] *internal_key_id
 *              A pointer to a byte that receives the internal key ID.
 *
 * @retval SEC_SUCCESS The operation completed successfully.
 */
//-----------------------------------------------------------------------------

sec_result_t 
sec_get_internal_key_id(sec_key_cache_slot_t key_slot_id, uint8_t *internal_key_id);


#ifdef __cplusplus
}
#endif

#endif
