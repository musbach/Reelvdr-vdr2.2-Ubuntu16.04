/****************************************************************************
 * Copyright (c) 2010-2011 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************/
/*^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^^vvv^^*/

/****************************************************************************
 *  Digital Home Group
 *  Intel Corporation
 *  2200 Mission College Blvd.
 *  Santa Clara, CA  95054-1549
 *  (408) 765-8080
 *  http://www.intel.com
 ***************************************************************************/

#ifndef INTEL_TRUSTED_STORE_H
#define INTEL_TRUSTED_STORE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sec.h"


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup status
 * @brief   return status codes
 *
 * Various return status codes.
 *
 * It is possible that additional "successful" and/or "failure" return
 * status codes may be added later.  As such, it is not advisable to check
 * for specific values to indicate "success" or "failure".  Instead, use the
 * macros: INTEL_TRUSTED_STORE_SUCCESSFUL() and INTEL_TRUSTED_STORE_FAILED().
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef enum
    {
        INTEL_TRUSTED_STORE_RESULT_OK = 0,
            /**<  the operation completed successfully  */
        INTEL_TRUSTED_STORE_RESULT_FAILED = 1000,
            /**<  the operation failed for general reasons  */
        INTEL_TRUSTED_STORE_RESULT_FAILED_PARAMETERS,
            /**<  the operation failed due to invalid calling parameters  */
        INTEL_TRUSTED_STORE_RESULT_FAILED_VERIFICATION,
            /**<  the operation failed due to secure store not verifying  */
        INTEL_TRUSTED_STORE_RESULT_FAILED_FILEIO
            /**<  the operation failed due to a file operation failure  */
    }                                           intel_trusted_store_result_t;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/**@ingroup status
 * @brief   return text name of return status code
 *
 * Receives a return status code, intel_trusted_store_result_t, and returns the ASCIIZ
 * text of the name of that status code.  This macro is useful for writing
 * test programs for reporting the status in human readable form.
 *
 * @param[in] s
 *              return status code (intel_trusted_store_result_t)
 *
 * @return  text of the name of the status code
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define INTEL_TRUSTED_STORE_RESULT_TEXT(s) \
    ( ((s)==INTEL_TRUSTED_STORE_RESULT_OK)                   ? "INTEL_TRUSTED_STORE_RESULT_OK" : \
      ((s)==INTEL_TRUSTED_STORE_RESULT_FAILED)               ? "INTEL_TRUSTED_STORE_RESULT_FAILED" : \
      ((s)==INTEL_TRUSTED_STORE_RESULT_FAILED_PARAMETERS)    ? "INTEL_TRUSTED_STORE_RESULT_FAILED_PARAMETERS" : \
      ((s)==INTEL_TRUSTED_STORE_RESULT_FAILED_VERIFICATION)  ? "INTEL_TRUSTED_STORE_RESULT_FAILED_VERIFICATION" : \
      ((s)==INTEL_TRUSTED_STORE_RESULT_FAILED_FILEIO)        ? "INTEL_TRUSTED_STORE_RESULT_FAILED_FILEIO" : \
                                                "<unrecognized status code>" )
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/**@ingroup status
 * @brief   check return status code for "success"
 *
 * Receives a return status code, intel_trusted_store_result_t, and returns logical true
 * if and only if that status code indicates "successful".
 *
 * @param[in] s
 *              return status code (intel_trusted_store_result_t)
 *
 * @return  logical true if and only if x indicates "successful"
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define INTEL_TRUSTED_STORE_SUCCESSFUL(s)  ((s) == INTEL_TRUSTED_STORE_RESULT_OK)
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/**@ingroup status
 * @brief   check return status code for "failure"
 *
 * Receives a return status code, intel_trusted_store_result_t, and returns logical true
 * if and only if that status code indicates "failure".
 *
 * @param[in] s
 *              return status code (intel_trusted_store_result_t)
 *
 * @return  logical true if and only if x indicates "failure"
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define INTEL_TRUSTED_STORE_FAILED(s)  ((s) >= INTEL_TRUSTED_STORE_RESULT_FAILED)
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


/*#########################################################################*/
/*  EXPORTED FUNCTIONS:                                                    */
/*#########################################################################*/


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup common
 * @brief   create an empty secure store file
 *
 * Creates an empty secure store file.  If the file already exists, it is
 * overwritten.
 *
 * The parameter, c123, may be NULL, in which case random values are
 * generated for these constants.
 *
 * @param[in] file_name
 *              secure store file name
 *
 * @param[in] c123
 *              pointer to 48-byte array of C1,C2,C3 constants (may be NULL)
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_create( const char *  file_name,
                            const void *  c123 );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup common
 * @brief   return the sizes associated with the secure store file
 *
 * Return the sizes associated with the secure store file.  The data size is
 * the size of the data contained in the secure store; whereas the buffer
 * size is the actual buffer size that is required.  The caller must allocate
 * a buffer of the size indicated by the buffer size for secure store
 * operations.
 *
 * The parameters, modify_offset_bytes and modify_size_bytes, indicate a
 * place in the buffer that is to be updated.  The returned sizes reflect
 * what it would be after the update has occurred.  If there is no update
 * (e.g. the sizes are just needed for intel_trusted_store_read()), then both
 * of these parameters may be passed as 0.
 *
 * Either one or both of the parameters, payload_size_bytes and
 * buffer_size_bytes may be NULL.  If the parameter is NULL, then the
 * corresponding value is not returned.
 *
 * This function does not verify the secure store.
 *
 * @param[in] file_name
 *              secure store file name
 *
 * @param[out] payload_size_bytes
 *              pointer to write the payload size to (may be NULL)
 *
 * @param[out] buffer_size_bytes
 *              pointer to write the buffer size to (may be NULL)
 *              (the buffer size is the actual size of a buffer that must be
 *
 * @param[in] modify_offset_bytes
 *              offset into payload where modification should be done
 *
 * @param[in] modify_size_bytes
 *              size of where modification should be done
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_get_sizes( const char *     file_name,
                               unsigned long *  payload_size_bytes,
                               unsigned long *  buffer_size_bytes,
                               unsigned long    modify_offset_bytes,
                               unsigned long    modify_size_bytes );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup common
 * @brief   verify and read the secure store file
 *
 * Verifies and reads the entire contents of the secure store file.
 *
 * The caller must pass in a pre-allocated buffer of the size returned by
 * the buffer_size_bytes field of intel_trusted_store_get_sizes().  That buffer
 * is filled with the contents of the file.
 *
 * The actual length of meaningful data in the buffer is indicated by the
 * payload_size_bytes field of intel_trusted_store_get_sizes().  This length is
 * never larger than the buffer size.
 *
 * If this function fails, the buffer contents is either unchanged or zeroed
 * out.
 *
 * @param[in] file_name
 *              secure store file name
 *
 * @param[out] buffer
 *              pointer to write the data to (of length buffer_size_bytes)
 *
 * @param[in] buffer_size_bytes
 *              the size of the caller-allocated buffer
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_read( const char *   file_name,
                          void *         buffer,
                          unsigned long  buffer_size_bytes );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup common
 * @brief   read&verify, modify, and write the secure store file
 *
 * Reads and verifies the entire contents of the secure store file.  Then
 * updates the contents with the modify_buffer, and writes the updated
 * secure store back out to the file.
 *
 * The modify_buffer may expand the size of the secure store.  If
 * modify_offset_bytes is beyond the current size of the secure store, then
 * the secure store is zero-filled as necessary to expand the size.
 *
 * If modify_offset_bytes is non-zero but modify_size_bytes is zero, then
 * the secure store will be zero-filled as necessary to expand to the size
 * indicated by modify_offset_bytes, but without adding any new data.
 *
 * If the modify_offset_bytes is less than the secure store size and
 * modify_size_bytes is zero, then the secure store file is not updated.
 *
 * The caller must pass in a pre-allocated buffer of the size returned by
 * the buffer_size_bytes field of intel_trusted_store_get_sizes().  That buffer is
 * temporary storage and is filled with zeros when this call is returned.
 *
 * @param[in] file_name
 *              secure store file name
 *
 * @param[out] buffer
 *              pointer to write the data to (of length buffer_size_bytes)
 *
 * @param[in] buffer_size_bytes
 *              the size of the caller-allocated buffer
 *
 * @param[in] modify_buffer
 *              pointer to data to write into the payload
 *
 * @param[in] modify_offset_bytes
 *              offset into payload where modification should be done
 *
 * @param[in] modify_size_bytes
 *              size of where modification should be done
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_modify( const char *   file_name,
                            void *         buffer,
                            unsigned long  buffer_size_bytes,
                            const void *   modify_buffer,
                            unsigned long  modify_offset_bytes,
                            unsigned long  modify_size_bytes );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup common
 * @brief   setup key ladder to key slot CCW1 on SEC_SECONDARY_KEY_LADDER
 *
 * The value of CCW1 is set.  One goal is to use this key for bulk
 * encryption / decryption.  The value written into CCW1 is based on three
 * constants and the internal key SSK.
 *
 * The three constants are supplied as a single 48-byte value, where the
 * first 16 bytes are the first constant, the second 16 bytes are the
 * second constant, and the final 16 bytes are the final constant.  The
 * caller chooses the value of the constants.
 *
 * This function provides a means of using sec functions for bulk encryption
 * and decryption using a secret key bound to the SoC.  An example session
 * could follow this function with sec_set_sym_key() using SEC_INTERNAL_KEY,
 * SEC_SECONDARY_KEY_LADDER, and SEC_CCW1, followed by a call to
 * sec_aes_process_data() to perform the encryption or decryption, and,
 * finally, sec_invalidate_key_in_key_cache() to invalidate key SEC_CCW1.
 *
 * This function uses key ladder slots M1 and M2a during the calculation.
 *
 * @param[in,out] sec_dev_context
 *              a sec_dev_context created with sec_dev_open()
 *
 * @param[in] c123
 *              pointer to the three constants, C1, C2, and C3 used for
 *              setting up the key ladder
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_setup_keyladder( sec_dev_context_t  sec_dev_context,
                                     const void *       c123 );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


#ifdef __cplusplus
}
#endif

#endif  /*  ndef INTEL_TRUSTED_STORE_H  */

