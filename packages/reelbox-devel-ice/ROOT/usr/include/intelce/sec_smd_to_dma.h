//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_SMD_TO_DMA_H
#define SEC_SMD_TO_DMA_H
#include <stdbool.h>
#include <stdint.h>
#include "sec_types.h"

#ifdef __cplusplus
extern "C" {
#endif


//--  sec_set_sec_buffer  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function creates and fills a sec_buffer_t instance.
 *
 * @param[in] type
 *              This is the type of address as defined in sec_addr_t
 *              This should be either SEC_ADDR_VIRTUAL or SEC_ADDR_PHYSCONTIG
 *
 * @param[in] size
 *              The length of the src or dst buffers that starts at *addr,
 *              in bytes. The actual length (size minus offset) of input data
 *              to be processed must be multiple of 16 bytes.
 *
 * @param[in] offset
 *              The initial offset from the start of the src or dst buffer
 *              at *addr where the operation should begin.
 *
 * @param[in] *addr
 *              This is a pointer to a Linux virtual memory address OR a
 *              pointer to an unsigned long that contains the physical address.
 *
 * @param[in,out] **pbuf
 *              This is a pointer to a sec_buffer_t pointer that receives the
 *              address of the allocated memory that has been initialized
 *              using type, size, offset, and *addr. This returned address
 *              will be NULL when the source "*addr" was NULL, or the virtual
 *              address was NULL, or when physical memory was selected and
 *              the physical memory address was zero, or when the mapping fails.
 *
 * @note When allocating the user space virtual memory for SEC_ADDR_VIRTUAL,
 *       the application  should allocate on page aligned boundaries
 *       using posix_memalign. Here is an example:
 *
 *       unsigned long       size  = 48128;
 *       unsigned char* virt_addr  = NULL;
 *       int                   rv  = 0;
 *
 *       rv = posix_memalign((void**)(&virt_addr),
 *                           (size_t)sysconf(_SC_PAGESIZE),
 *                           size );
 *
 * @retval SEC_SUCCESS            The operation completed successfully.
 * @retval SEC_NULL_POINTER       The "addr" or "pbuf" pointer was NULL
 * @retval SEC_DMA_PHYS_FAILED_MAP_TO_VIRT  If the physical memory failed
 *                                          to map to Linux virtual space.
 * @retval SEC_DMA_PHYS_VIRT_NOT_READWRITE If the physical mapped Linux virtual
 *                                         buffer is not read/write-able.
 */
sec_result_t  sec_set_sec_buffer( sec_addr_t  type,
                               unsigned long  size,
                               unsigned long  offset,
                                       void  *addr,
                               sec_buffer_t **pbuf);

//--  sec_free_sec_buffer  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function unmaps physical memory and frees the pointed to
 * sec_buffer_t instance at pbuf. The address pointed to by pbuf
 * is set to NULL on return.
 *
 * @param[in,out] **pbuf
 *              This is a pointer to a sec_buffer_t pointer instance
 *              that was created and initialized by sec_set_sec_buffer.
 *
 * @retval SEC_SUCCESS The operation completed successfully.
 */
sec_result_t sec_free_sec_buffer( sec_buffer_t **pbuf);

                                        
//--  sec_create_dma_desc  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function creates and fills DMA descriptors for the given addresses.
 * It calls the SEC kernel service SEC_CREATE_DMA_DESC that does the work.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in] chain
 *              The DMA chain for the meta data.
 *              There are two DMA chains (sec_dma_node_t) for each client
 *              sec_dma_client_t, a long term (SEC_DMA_DESC_LT) and a short
 *              term (SEC_DMA_DESC_ST).  The DMA descriptors for the long
 *              term can be created in advance of any cipher operations and
 *              reused.  This reduces %CPU and improves throughput.  The
 *              short term DMA descriptors can also be reused but the
 *              chain length is limited.  This chain is typically used
 *              for compatibility with the old sec_aes_process_data.
 *              
 *
 * @param[in] *src
 *              This is a pointer to a structure that holds the source
 *              memory address and type.
 *
 * @param[in] *dst
 *              This is a pointer to a structure that holds the destination
 *              memory address and type.
 *
 * @note When allocating the user space virtual memory for either
 *       the source or the destination DMA buffer, the application 
 *       should allocate on page aligned boundaries
 *       using posix_memalign. Here is an example:
 *
 *       unsigned long  opts_buffer_size    = 48128;
 *       unsigned char* dma_virt_dst_addr   = NULL;
 *       int                             rv = 0;
 *
 *       rv = posix_memalign((void**)(&dma_virt_dst_addr),
 *                           (size_t)sysconf(_SC_PAGESIZE),
 *                           opts_buffer_size );
 *
 * @retval SEC_SUCCESS            The operation completed successfully.
 * @retval SEC_FAIL               The operation failed.
 * @retval SEC_INVALID_CONTEXT    SEC context is invalid.
 * @retval SEC_INVALID_BUFF_SIZE  The "size" was zero
 * @retval SEC_NULL_POINTER       The source "src" or destination "dst" pointer
 *                                was NULL, or virtual address was NULL, or
 *                                when physical memory was selected the
 *                                physical memory address was zero.
 * @retval SEC_INVALID_INPUT      The source or destination memory type was
 *                                neither virtual nor physical
 */
//-----------------------------------------------------------------------------
sec_result_t sec_create_dma_desc(sec_dev_context_t   sec_dev_context,
                                 sec_cipher_mode_t   cipher_mode,
                                   sec_dma_chain_t   chain,
                                      sec_buffer_t  *src,
                                      sec_buffer_t  *dst);


//--  sec_free_dma_desc  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function frees the any virtual memory DMA descriptors
 * that were initialized by sec_create_dma_desc.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] chain
 *              The DMA chain for the meta data.
 *              There are two DMA chains (sec_dma_node_t) for each client
 *              sec_dma_client_t, a long term (SEC_DMA_DESC_LT) and a short
 *              term (SEC_DMA_DESC_ST).  The DMA descriptors for the long
 *              term can be created in advance of any cipher operations and
 *              reused.  This reduces %CPU and improves throughput.  The
 *              short term DMA descriptors can also be reused but the
 *              chain length is limited.  This chain is typically used
 *              for compatibility with the old sec_aes_process_data.
 *              
 *
 * @param[in] *src
 *              This is a pointer to a structure that holds the source
 *              memory address and type.
 *
 * @param[in] *dst
 *              This is a pointer to a structure that holds the destination
 *              memory address and type.
 *
 *
 * @retval SEC_SUCCESS            The operation completed successfully.
 * @retval SEC_FAIL               The operation failed.
 * @retval SEC_INVALID_CONTEXT    SEC context is invalid.
 * @retval SEC_NULL_POINTER       The source "src" or destination "dst" pointer
 *                                was NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t sec_free_dma_desc(sec_dev_context_t  sec_dev_context,
                                 sec_dma_chain_t  chain,
                                    sec_buffer_t *src,
                                    sec_buffer_t *dst);



//--  sec_dma_cleanup  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function frees the any virtual memory DMA descriptors
 * that were not explicitly freed by sec_free_dma_desc.
 * This function is called by sec_dev_close
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @retval SEC_SUCCESS            The operation completed successfully.
 * @retval SEC_FAIL               The operation failed.
 * @retval SEC_INVALID_CONTEXT    SEC context is invalid.
 *                                was NULL.
 */
//-----------------------------------------------------------------------------
sec_result_t sec_dma_cleanup(sec_dev_context_t  sec_dev_context);


//--  sec_aes_process_smd_dma  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function performs bulk AES encryption or decryption of data. The
 * application should use sec_set_sym_key() to set the AES key and 
 * initialization vector (requried by CBC and CTR modes) before calling
 * this function. For Cipher Block Chaining (CBC) mode, the state information
 * is kept in the SEC context after each sec_aes_process_smd_dma() call for 
 * continuous encryption/decryption operation.  
 * 
 * When using this function with an internal key, the internal 
 * key slot id must be:
 * SEC_CW1 - SEC_CW8 or SEC_CCW1 - SEC_CCW4 or SEC_M1 for encryption.
 * SEC_CW1 - SEC_CW8 or SEC_CCW1 - SEC_CCW4 for decryption.
 *
 * For Cipher Block Chaining (CBC) mode, the state information is saved in the
 * SEC context after each sec_aes_process_smd_dma call to support continuous 
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
 * @param[in] *src
 *              This is a pointer to a structure that holds the source
 *              memory address and type.
 *
 * @param[in] *dst
 *              This is a pointer to a structure that holds the destination
 *              memory address and type.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The smd_src or dst_dma pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE  Invalid cipher mode.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 * @retval SEC_INVALID_DATA_LEGNTH  The actual length of input data to be
 *                                  processed in not a multiple of 16 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 16 bytes)
 * @retval SEC_DMA_NO_NODES_FOR_TGID  The passed in addresses had no pre-existing
 *                                  DMA descriptor nodes for this process. This
 *                                  means that sec_set_sec_buffer needs to be
 *                                  called for both the source and destination
 *                                  addresses and then the returned initialized
 *                                  sec_buffer_t pointers need to be passed to
 *                                  sec_create_dma_desc before calling this
 *                                  function. This error is returned from then
 *                                  ioctl call.
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aes_process_smd_dma( sec_dev_context_t   sec_dev_context,
                         sec_cipher_mode_t   cipher_mode,
                         sec_buffer_t       *src,
                         sec_buffer_t       *dst);

//--  sec_aes_process_data2  ---------------------------------------------------
/** @ingroup crypt
 *
 * This function wraps sec_set_sec_buffer, sec_create_dma_desc,
 * sec_aes_process_smd_dma, sec_free_dma_desc, and sec_free_sec_buffer calls.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in] cipher_mode
 *              SEC_ENCRYPTION or SEC_DECRYPTION.
 *
 * @param[in] src_type
 *              Source address data type as defined in sec_addr_t
 *              in sec_types.h either SEC_ADDR_VIRTUAL or SEC_ADDR_PHYSCONTIG
 *
 * @param[in] dst_type
 *              Destination address data type as defined in sec_addr_t
 *              in sec_types.h either SEC_ADDR_VIRTUAL or SEC_ADDR_PHYSCONTIG
 *
 * @param[in] *src
 *              This is a pointer to the source address
 *
 * @param[in] *dst
 *              This is a pointer to the destination address
 *
 * @param[in] size
 *              This is the size of the buffers at the source
 *              and destination addresses
 *
 * @param[in] offset
 *              This is the offset from the start of the buffers
 *              at the source and destination addresses.
 *
 * @retval SEC_SUCCESS              The operation completed successfully.
 * @retval SEC_FAIL                 The operation failed.
 * @retval SEC_INVALID_CONTEXT      SEC context is invalid.
 * @retval SEC_NULL_POINTER         The smd_src or dst_dma pointer is NULL.
 * @retval SEC_INVALID_CIPHER_MODE  Invalid cipher mode.
 * @retval SEC_INVALID_BUFF_SIZE    Invalid input or output buffer size.
 * @retval SEC_INVALID_OFFSET_SIZE  Invalid offset.
 * @retval SEC_INVALID_DATA_LEGNTH  The actual length of input data to be
 *                                  processed in not a multiple of 16 bytes.
 *                                  (e.g. size minus offset is not a multiple
 *                                  of 16 bytes)
 */
//-----------------------------------------------------------------------------
sec_result_t
sec_aes_process_data2(sec_dev_context_t   sec_dev_context,
                      sec_cipher_mode_t   cipher_mode,
                             sec_addr_t   src_type,
                             sec_addr_t   dst_type,
                                   void  *src,
                                   void  *dst,
                          unsigned long   size,
                          unsigned long   offset);

#ifdef __cplusplus
}
#endif

#endif
