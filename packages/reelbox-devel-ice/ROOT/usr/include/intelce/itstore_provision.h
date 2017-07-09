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

#ifndef INTEL_TRUSTED_STORE_PROVISION_H
#define INTEL_TRUSTED_STORE_PROVISION_H

#include "itstore.h"

#ifdef __cplusplus
extern "C" {
#endif


/*#########################################################################*/
/*  EXPORTED FUNCTIONS:                                                    */
/*#########################################################################*/


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup provision
 * @brief   encrypt KEK
 *
 * Encrypts the 16-byte key, kek, to form the 16-byte encrypted key, ekek.
 *
 * This function needs C1, which is the first 16 bytes of c123.
 * intel_trusted_store_retrieve_c123() may be used to retrieve this value if it is not
 * known.  Alternatively, a different value for C1 may be used than the one
 * used to create the secure store.
 *
 * @param[in] kek
 *              pointer to incoming unencrypted KEK (16 bytes)
 *
 * @param[out] ekek
 *              pointer to outgoing encrypted KEK (16 bytes)
 *
 * @param[in] c123
 *              pointer to 48-byte array of C1,C2,C3 constants (may be NULL)
 *              (only C1, the first 16 bytes, are used)
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_generate_ekek( const void *  kek,
                                   void *        ekek,
                                   const void *  c123 );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */
/**@ingroup provision
 * @brief   retrieve the C123 from a secure store file
 *
 * Retrieves the constants, C1, C2, and C3 (48 bytes total) from a secure
 * store file.  This function is useful if the secure store file was created
 * with random values for C1, C2, and C3, and you need to retrieve C1 for
 * intel_trusted_store_generate_ekek().
 *
 * @param[in] file_name
 *              secure store file name
 *
 * @param[out] c123
 *              pointer to 48-byte array of C1,C2,C3 constants
 *
 * @return  intel_trusted_store_result_t indicating the status of the operation
 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
intel_trusted_store_result_t
intel_trusted_store_retrieve_c123( const char *  file_name,
                                   void *        c123 );
/* -  -  -  -  -  -  -  -  -  -  -  -   -  -  -  -  -  -  -  -  -  -  -  - */


#ifdef __cplusplus
}
#endif

#endif  /*  ndef INTEL_TRUSTED_STORE_PROVISION_H  */

