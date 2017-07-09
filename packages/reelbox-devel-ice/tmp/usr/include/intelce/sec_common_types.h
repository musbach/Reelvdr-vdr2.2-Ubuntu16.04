/*-----------------------------------------------------------------------------
 * This file is provided under a dual BSD/GPLv2 license.  When using or 
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * The full GNU General Public License is included in this distribution 
 * in the file called LICENSE.GPL.
 *
 * Contact Information:
 *      Intel Corporation
 *      2200 Mission College Blvd.
 *      Santa Clara, CA  97052
 *
 * BSD LICENSE 
 *
 * Copyright(c) 2008-2011 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright 
 *     notice, this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright 
 *     notice, this list of conditions and the following disclaimer in 
 *     the documentation and/or other materials provided with the 
 *     distribution.
 *   - Neither the name of Intel Corporation nor the names of its 
 *     contributors may be used to endorse or promote products derived 
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#ifndef _SEC_COMMON_TYPES_H_
#define _SEC_COMMON_TYPES_H_

//----------------------------------------------------------------------------
// This file defines the data structures used by both
// the SEC user-space library and the kernel-space driver.
//----------------------------------------------------------------------------

#include <stdint.h>

// IOCTL constants for kernel mode sec operations
#include <asm/ioctl.h>
#define SEC_IOC_MAGIC 'S'
#define SEC_IOCSIPCCALL         _IOW(SEC_IOC_MAGIC, 3, int)
#define SEC_ALLOC_MEM_CALL      _IOW(SEC_IOC_MAGIC, 4, int)
#define SEC_FREE_MEM_CALL       _IOW(SEC_IOC_MAGIC, 5, int)
#define SEC_GET_JOB_ID          _IOW(SEC_IOC_MAGIC, 6, int)
#define SEC_GET_REVISION_ID     _IOW(SEC_IOC_MAGIC, 7, int)
#define SEC_IPC_FRAGMENTED      _IOW(SEC_IOC_MAGIC, 8, int)
#define SEC_MUNMAP_CALL         _IOW(SEC_IOC_MAGIC, 9, int)
#define SEC_GET_TGID            _IOW(SEC_IOC_MAGIC, 10, int)
#define SEC_FW                  _IOW(SEC_IOC_MAGIC, 11, int)
#define SEC_GET_TDP_INFO        _IOW(SEC_IOC_MAGIC, 12, int)
#define SEC_GET_EAU_LOCK        _IOW(SEC_IOC_MAGIC, 13, int)
#define SEC_RELEASE_EAU_LOCK    _IOW(SEC_IOC_MAGIC, 14, int)
#define SEC_ALLOC_PAGES_CALL    _IOW(SEC_IOC_MAGIC, 15, int)
#define SEC_FREE_PAGES_CALL     _IOW(SEC_IOC_MAGIC, 16, int)
#define SEC_CREATE_DMA_DESC     _IOW(SEC_IOC_MAGIC, 17, int)
#define SEC_FREE_DMA_DESC       _IOW(SEC_IOC_MAGIC, 18, int)
#define SEC_AES_SMD_TO_DMA      _IOW(SEC_IOC_MAGIC, 19, int)
#define SEC_DMA_CLEANUP         _IOW(SEC_IOC_MAGIC, 20, int)


//----------------------------------------------------------------------------
// Known SEC PCI device revisions
// 
// These symbolic names are assigned just to make it easy to find places in the
// code that contain revision-dependent code.
//----------------------------------------------------------------------------
typedef enum
{
    SEC_PCI_REV_0  =  0,  // Intel Media Processor CE 3100
    SEC_PCI_REV_1  =  1,  // Intel Atom Processor CE 4100 A0
    SEC_PCI_REV_2  =  2,  // Intel Atom Processor CE 4100 B0
    SEC_PCI_REV_3  =  3,  // Intel Atom Processor CE 4200 A0
    SEC_PCI_REV_4  =  4,  // Intel Atom Processor CE 4200 B0
    SEC_PCI_REV_5  =  5,  // Intel Atom Processor CE 4200 C0
    SEC_PCI_REV_6  =  6,  // Intel Atom Processor CE 5300 A0
    SEC_PCI_REV_7  =  7   // Intel Atom Processor CE 5300 B0
} sec_pci_rev_t;


//-----------------------------------------------------------------------------
// IPC COMMANDS
//-----------------------------------------------------------------------------
typedef enum
{
    IPC_REQUEST_IPC_SHARED_RAM          = 0,
    IPC_GET_SERIAL_NUMBER               = 1,
    IPC_DES_ENCRYPT_AND_STORE_KEY       = 2,
    IPC_DES_DECRYPT_AND_STORE_KEY       = 3,
    IPC_AES_ENCRYPT_AND_STORE_KEY       = 4,
    IPC_AES_DECRYPT_AND_STORE_KEY       = 5,
    IPC_RSA_ENCRYPT_DATA                = 6,
    IPC_RSA_DECRYPT_DATA                = 7,
    IPC_AES_ENCRYPT_DATA                = 8,
    IPC_AES_DECRYPT_DATA                = 9,
    IPC_DES_ENCRYPT_DATA                = 10,
    IPC_DES_DECRYPT_DATA                = 11,
    IPC_C2_ENCRYPT_DATA                 = 12,
    IPC_C2_DECRYPT_DATA                 = 13,
    IPC_CSS_DECRYPT_DATA                = 14,
    IPC_CTR_DRBG_RESEED                 = 17,
    IPC_CTR_DRBG_GET_RANDOM_DATA        = 18,
    IPC_SET_CLEAR_KEY                   = 19,
    IPC_INVALIDATE_KEY                  = 20,
    IPC_SHA_HASH_DATA                   = 21,
    IPC_MD5_HASH_DATA                   = 22,
    IPC_RSA_SIGN_DATA                   = 23,
    IPC_RSA_VERIFY                      = 24,
//    IPC_VERIFY_OMAC1_SIGNATURE          = 29,
    IPC_GENERATE_MAC                    = 29,
    IPC_GET_HW_FW_VERSION               = 32,
    IPC_REQUEST_FLASH_WRITE_ACCESS      = 34,
    IPC_RELEASE_FLASH_WRITE_ACCESS      = 35,
    IPC_OBFUSCATE_MEMORY                = 43,
    IPC_LOAD_LARGE_EXPONENT             = 45,
    IPC_AUTH_AND_LOAD_FW_MODULE         = 47,
    IPC_PERFORM_EAU_OPERATION           = 49,
    IPC_REWRAP_MODULE_KEYS              = 50,
    IPC_DECRYPT_LOAD_HDCP_KEYS          = 51,
    IPC_HASH_VERIFY_KSV                 = 52,
    IPC_AES_HASH_DATA                   = 53,
    IPC_54                              = 54,
    IPC_55                              = 55,
    IPC_56                              = 56,
    IPC_57                              = 57,
    IPC_58                              = 58,
    IPC_GENERATE_KEY                    = 59,
    IPC_60                              = 60,
    IPC_61                              = 61,
    IPC_EXTERNAL_MODULE_CMD_CE4100      = 62,
    IPC_WRAP_FLASH_KEY                  = 65,
    IPC_ARC4_ENCRYPT_DECRYPT_DATA       = 67,

//  Trusted Time Base
    IPC_INIT_TTB_TYPE1                  = 68,
    IPC_INIT_TTB_TYPE2                  = 69,
    IPC_READ_TTB                        = 70,
    IPC_UPDATE_TTB                      = 71,

//    IPC_LOAD_LARGE_NUMBER               = 72,
    IPC_DH_KEY_EXCHANGE                 = 73,
    IPC_AES128_ENCRYPT_DECRYPT_DATA     = 78,
    IPC_REGISTER_SYSTEM_MEMORY          = 79,
    IPC_EXTERNAL_MODULE_CMD             = 80,
    IPC_GET_CURRENT_PROCESS_LIST        = 128,
    IPC_BIST_TEST                       = 129,
    IPC_OVERRIDE_FUSE_SETTINGS          = 130,
    IPC_DELETE_PROCESS                  = 131 
} sec_fw_cmd_t;

// IPC sub-commands for any IPC command:
/*  Note that we really do not need the other kinds of subcommand enums.
 *  The idea I have here is that we can migrate those over to use this one,
 *  and then remove the others.
 */
typedef enum
{
    IPC_SC_0       = 0x00,
    IPC_SC_1       = 0x01,
    IPC_SC_2       = 0x02,
    IPC_SC_3       = 0x03,
    IPC_SC_4       = 0x04,
    IPC_SC_5       = 0x05,
    IPC_SC_6       = 0x06,
    IPC_SC_7       = 0x07,
    IPC_SC_8       = 0x08,
    IPC_SC_9       = 0x09,
    IPC_SC_10      = 0x0a,
    IPC_SC_11      = 0x0b,
    IPC_SC_12      = 0x0c,
    IPC_SC_13      = 0x0d,
    IPC_SC_14      = 0x0e,
    IPC_SC_15      = 0x0f,
    IPC_SC_16      = 0x10,
    IPC_SC_17      = 0x11,
    IPC_SC_18      = 0x12,
    IPC_SC_19      = 0x13,
    IPC_SC_20      = 0x14,
    IPC_SC_21      = 0x15,
    IPC_SC_22      = 0x16,
    IPC_SC_23      = 0x17,
    IPC_SC_24      = 0x18,
    IPC_SC_25      = 0x19,
    IPC_SC_26      = 0x1a,
    IPC_SC_27      = 0x1b,
    IPC_SC_28      = 0x1c,
    IPC_SC_29      = 0x1d,
    IPC_SC_30      = 0x1e,
    IPC_SC_31      = 0x1f,
    IPC_SC_32      = 0x20,
    IPC_SC_33      = 0x21,
    IPC_SC_34      = 0x22,
    IPC_SC_35      = 0x23,
    IPC_SC_36      = 0x24,
    IPC_SC_37      = 0x25,
    IPC_SC_38      = 0x26,
    IPC_SC_39      = 0x27,
    IPC_SC_40      = 0x28,
    IPC_SC_41      = 0x29,
    IPC_SC_42      = 0x2a,
    IPC_SC_43      = 0x2b,
    IPC_SC_44      = 0x2c,
    IPC_SC_45      = 0x2d,
    IPC_SC_46      = 0x2e,
    IPC_SC_47      = 0x2f,
    IPC_SC_48      = 0x30,
    IPC_SC_49      = 0x31,
} sec_fw_subcmd_generic_t;
#define IPC_SC_NOT_USED  IPC_SC_0

// IPC sub-commands for IPC_54:
typedef enum
{
    IPC_SC_54_0    = 0x00,
    IPC_SC_54_1    = 0x01,
    IPC_SC_54_2    = 0x02,
    IPC_SC_54_3    = 0x03,
    IPC_SC_54_4    = 0x04,
    IPC_SC_54_5    = 0x05,
    IPC_SC_54_6    = 0x06,
    IPC_SC_54_7    = 0x07,
    IPC_SC_54_8    = 0x08,
    IPC_SC_54_9    = 0x09,
    IPC_SC_54_10   = 0x0a,
    IPC_SC_54_11   = 0x0b,
    IPC_SC_54_12   = 0x0c,
    IPC_SC_54_13   = 0x0d,
    IPC_SC_54_14   = 0x0e,
    IPC_SC_54_15   = 0x0f,
    IPC_SC_54_16   = 0x10,
    IPC_SC_54_17   = 0x11,
    IPC_SC_54_18   = 0x12,
    IPC_SC_54_19   = 0x13,
    IPC_SC_54_20   = 0x14,
    IPC_SC_54_36   = 0x24,
    IPC_SC_54_37   = 0x25,
    IPC_SC_54_38   = 0x26,
    IPC_SC_54_39   = 0x27,
    IPC_SC_54_41   = 0x29,
} sec_fw_subcmd_54_t;

// IPC sub-commands for IPC_60:
typedef enum
{
    IPC_SC_60_0    = 0x00,
    IPC_SC_60_1    = 0x01,
    IPC_SC_60_3    = 0x03,
    IPC_SC_60_4    = 0x04,
    IPC_SC_60_5    = 0x05,
    IPC_SC_60_6    = 0x06,
    IPC_SC_60_7    = 0x07,
    IPC_SC_60_8    = 0x08,
    IPC_SC_60_9    = 0x09,
    IPC_SC_60_10   = 0x0a,
    IPC_SC_60_11   = 0x0b,
    IPC_SC_60_12   = 0x0c,
    IPC_SC_60_13   = 0x0d,
    IPC_SC_60_14   = 0x0e,
    IPC_SC_60_15   = 0x0f,
    IPC_SC_60_16   = 0x10,
    IPC_SC_60_17   = 0x11,
    IPC_SC_60_18   = 0x12,
    IPC_SC_60_19   = 0x13,
    IPC_SC_60_20   = 0x14,
    IPC_SC_60_21   = 0x15,
    IPC_SC_60_22   = 0x16,
    IPC_SC_60_23   = 0x17,
    IPC_SC_60_24   = 0x18,
    IPC_SC_60_27   = 0x1b,
    IPC_SC_60_30   = 0x1e,
    IPC_SC_60_32   = 0x20,
    IPC_SC_60_33   = 0x21
} sec_fw_subcmd_60_t;
// IPC sub-commands for IPC_55:
typedef enum
{
    IPC_SC_55_0    = 0x00,
    IPC_SC_55_1    = 0x01,
} sec_fw_subcmd_55_t;

// IPC sub-commands for FW Module Loader:
typedef enum
{
    IPC_SC_PRECE4200 = 0,
    IPC_SC_CE4200    = 1,
    IPC_SC_CE5300    = 2
} sec_fw_subcmd_load_t;

// IPC sub-commands for TDP:
typedef enum
{
    IPC_SC_TDP_INITTDP    = 0x00,
    IPC_SC_TDP_LOADPHFW   = 0x01,
} sec_fw_subcmd_tdp_t;


// IPC sub-commands for DTCPIP:
typedef enum
{
    IPC_SC_DTCPIP_INIT                 = 0x00, //  init dtcpip firmware
    IPC_SC_DTCPIP_CREATE_CTX           = 0x01, //  create context
    IPC_SC_DTCPIP_DESTROY_CTX          = 0x02, //  destroy context
    IPC_SC_DTCPIP_ECDSA_SIGN           = 0x03, //  ECDSA sign
    IPC_SC_DTCPIP_ECDSA_VERIFY         = 0x04, //  ECDSA verify
    IPC_SC_DTCPIP_GEN_HK_HV            = 0x05, //  ECDH - generate Hk and Hv
    IPC_SC_DTCPIP_GEN_KX_KSX           = 0x06, //  ECDH - generate exchange key
    IPC_SC_DTCPIP_PROCESS_PKT          = 0x07, //  process packet
    IPC_SC_DTCPIP_WRAP_KEY             = 0x08, //  wrap keys
    IPC_SC_DTCPIP_GET_CMD_DATA         = 0x09,
    IPC_SC_DTCPIP_GEN_KXM_KXSM         = 0x0a,
    IPC_SC_DTCPIP_EXPIRE_KX            = 0x0b,
    IPC_SC_DTCPIP_NEW_KX_KSX           = 0x0c,
    IPC_SC_DTCPIP_CLONE_CONTEXT        = 0x0d,
    IPC_SC_DTCPIP_TEST_IPC             = 0x0e,
}sec_fw_subcmd_dtcpip_t;

// all IPC sub-commands are encapsulated by this union:
typedef union
{
    sec_fw_subcmd_generic_t  sc;    //  generic sub-commands
    sec_fw_subcmd_54_t       sc_54; //  IPC_54 subcommands
    sec_fw_subcmd_55_t       sc_55; //  IPC_55 subcommands
    sec_fw_subcmd_load_t     sc_fwl;// Info for FW Loader
    sec_fw_subcmd_60_t       sc_60; //  IPC_60 subcommands
    sec_fw_subcmd_tdp_t      sc_tdp; //  IPC_TDP subcommands
    sec_fw_subcmd_dtcpip_t   sc_dtcpip;    //  IPC_DTCPIP subcommands
} sec_fw_subcmd_t;

// sec_ipc_sizes_t contains the required input and
// output sizes for payload and shared memory transfers.
typedef struct
{
    uint16_t        ipl_size; //Explicit byte size of input payload for SEC HW
    uint16_t        ish_size; //Explicit byte size of input shared memory for SEC HW
    uint16_t        opl_size; //Explicit byte size of output payload returned from SEC HW
    uint16_t        osh_size; //Explicit byte size of output shared memory returned from SEC HW
} sec_ipc_sizes_t;

// SEC kernel buffer address types:
typedef enum
{
    SEC_KERNEL_ADDR_NONE        = 0,  /*!<  neither type (generally not used)  */
    SEC_KERNEL_ADDR_VIRTUAL     = 1,  /*!<  buffer is a virtual address  */
    SEC_KERNEL_ADDR_PHYSCONTIG  = 2,  /*!<  buffer is a physical address  */
} sec_kernel_addr_t;

// The sec_kernel_ipc_t structure is used by the user-space library
// to send an IPC command and through the "opl" and "osh_pl" pointers
// receive the response.
typedef struct
{
    sec_fw_cmd_t    cmd; //The command to the SEC HW's firmware
    sec_fw_subcmd_t sub_cmd; //Any subcommand to SEC HW's firmware
    uint32_t        resources; //CE3100 & CE4100 resource semaphores to use
    uint32_t        module_id;  // for ExternalModuleIPC only
    sec_ipc_sizes_t io_sizes;//Input and output payload and shared memory transfers sizes
    ipl_t *         ipl; //Pointer to the user space input payload data
    ipc_shmem_t *   ish_pl; //Pointer to the user space input shared memory data
    opl_t *         opl; //Pointer to the user space output payload data
    ipc_shmem_t *   osh_pl; //Pointer to the user space output shared memory data
    void *          src; //The source address for DMA transfers
    uint32_t        src_size; //The source memory size
    void *          dst; //The destination address for DMA transfers
    uint32_t        dst_size; //The destination memory size
    sec_kernel_addr_t src_dst_buf_type; //The type of src and dst buffers
} sec_kernel_ipc_t;

// SEC kernel lastbytes copy instruction
// (used to determine whether to copy the last block of an operation
// into the OPL and, if so, whether before the operation or after;
// needed if the address is SEC_KERNEL_ADDR_PHYSCONTIG for remembering
// the block cipher CBC chaining state since user space code doesn't
// have a way to read it):
typedef enum
{
    SEC_KERNEL_LB_NO_COPY       = 0,  /*!<  do not copy last block to OPL  */
    SEC_KERNEL_LB_COPY_BEFORE   = 1,  /*!<  copy last block to OPL before IPC cmd  */
    SEC_KERNEL_LB_COPY_AFTER    = 2,  /*!<  copy last block to OPL after IPC cmd  */
} sec_kernel_fb_lb_t;

// The container passed as the IOCTL argument into sec_kernel_ioctl_ipc_call_fb.
// It contains a sec_kernel_ipc_t as well as other parametes associated
// with the fragmented buffer.
typedef struct
{
    sec_kernel_ipc_t    ipc;                    /*!<  the corresponding sec_kernel_ipc_t  */
    sec_kernel_addr_t   bfr_type_src;           /*!<  sec_kernel_addr_t we are using for our buffer(s)  */
    sec_kernel_addr_t   bfr_type_dst;           /*!<  sec_kernel_addr_t we are using for our buffer(s)  */
    uint32_t            fragment_count;         /*!<  total number of fragments in this buffer  */
    uint32_t            fragment_length_bytes;  /*!<  length of each fragment  */
    uint32_t            fragment_period_bytes;  /*!<  length between start of each fragment  */
    sec_kernel_fb_lb_t  lastbytes_copy_mode;    /*!<  sec_kernel_fb_lb_t instruction  */
    uint32_t            lastbytes_opl_ofs;      /*!<  if copying last bytes, the offset to write into OPL  */
    uint32_t            lastbytes_len_bytes;    /*!<  if copying last bytes, the length to write to OPL  */
} sec_kernel_fb_t;

// Maximum payload and shared memory defines
#define SEC_HW_MAX_PAYLOAD    64
#define SEC_HW_MAX_SHAREDMEM  256

// Minimum payload and shared memory defines
#define SEC_HW_NO_PAYLOAD    0
#define SEC_HW_NO_SHAREDMEM   0

#define SEC_HW_PAYLOAD_JUST_JOBID  4
#define SEC_HW_JUST_IPL_HEADER    12
#define SEC_HW_OPL_FW_VERSION      8

//Request IPC Shared RAM output sizes
#define REQ_IPC_SHARED_RAM_OPL_SIZE  4
#define REQ_IPC_SHARED_RAM_OSH_size  0

// AACS sizes in bytes
#define AACS_KEY_SIZE           16
#define AACS_CONTEXT_SIZE       0x1170

// DTCP related defines
//FIXME: fix this size one FW dependency is determined
#define DTCPIP_CONTEXT_SIZE 1000

// AES sizes in bytes
#define AES_BLOCK_SIZE          16

// C2 sizes in bytes
#define C2_BLOCK_SIZE           8
#define C2_KEY_SIZE_BYTE        7

// CSS sizes in bytes
#define CSS_BLOCK_SIZE          4

// DES sizes in bytes
#define DES_BLOCK_SIZE          8

// MD5 sizes in bytes
#define MD5_BLOCK_SIZE          64
#define MD5_DIGEST_SIZE         16


// AES-H sizes in bytes
#define AES_H_BLOCK_SIZE        16
#define AES_H_DIGEST_SIZE       16

// ARC4 sizes in bytes
#define ARC4_BLOCK_SIZE          1

//-----------------------------------------------------------------------------
// SHA
//-----------------------------------------------------------------------------
//SHA mode
#define SHA_1                   0
#define SHA_256                 1
#define SHA_224                 2
#define SHA_384                 3
#define SHA_512                 4

// SHA mode sizes in bytes
#define SHA_1_BLOCK_SIZE        64
#define SHA_1_DIGEST_SIZE       20
#define SHA_1_STATE_SIZE        20

#define SHA_224_BLOCK_SIZE      64
#define SHA_224_DIGEST_SIZE     28
#define SHA_224_STATE_SIZE      32

#define SHA_256_BLOCK_SIZE      64
#define SHA_256_DIGEST_SIZE     32
#define SHA_256_STATE_SIZE      32

#define SHA_384_BLOCK_SIZE      128
#define SHA_384_DIGEST_SIZE     48
#define SHA_384_STATE_SIZE      64

#define SHA_512_BLOCK_SIZE      128
#define SHA_512_DIGEST_SIZE     64
#define SHA_512_STATE_SIZE      64

#define SHA_MAX_DIGEST_SIZE     SHA_512_DIGEST_SIZE

#define SHA_OPL_SIZE            4

#define SHA_MAX_BLOCK_SIZE      SHA_512_BLOCK_SIZE
#define SHA_MAX_STATE_SIZE      SHA_512_STATE_SIZE

#define HASH_MAX_STATE_SIZE     SHA_512_STATE_SIZE
#define HASH_MAX_BLOCK_SIZE     SHA_512_BLOCK_SIZE

// Few helpful macros
#define VERIFY_QUICK(expression, label) if (!(expression)) { goto label; } 

#define VERIFY(expression, label, rc, val) \
        if (!(expression))                 \
        {                                  \
            rc = val;                      \
            goto label;                    \
        }

#define KEY_ID_EQUAL(id_1, id_2, label)    \
        if (id_1 != id_2)                  \
        {                                  \
            rc = SEC_INVALID_KEY_ID;       \
            goto label;                    \
        }

#define SEC_CONTIG_FLAG_PM_FREED    0x00000001  /* The sec PM kernel code will
                                                   free this memory */

// Data type to describe contiguous memory in sec driver
typedef struct
{
    unsigned int paddr;  // physical address
    void * user_vaddr;   // userspace virtual address
    void * kernel_vaddr; // kernelspace virtual address
    unsigned int size;   // size of the block
    unsigned int tgid;   // task Thread Group ID
    int mmap_count;      // physical address to virtual address map count
    int smpool;          // If not zero then small pool area
    unsigned int flags;  // Bit-flags that control certain operations within
                         //    the kernel.
} sec_contig_mem_t;

// SEC resources. 
// Each enumerator is a bit flag.  The bit number that is set in an enumerator
// is also the index of that enumerator's semaphore in the scoreboard.
typedef enum
{
    SEC_C2_RES     = 0x001,
    SEC_HASH_RES   = 0x002,
    SEC_AES_RES    = 0x004,
    SEC_DES_RES    = 0x008,
    SEC_CSS_RES    = 0x010,
    SEC_RNG_RES    = 0x020,
    SEC_EAU_RES    = 0x040,
    SEC_LDEXP_RES  = 0x080,
    SEC_SHMEM_RES  = 0x100,
} sec_fw_resource_t;
#define SEC_RESOURCE_COUNT 9

//-----------------------------------------------------------------------------
// DMA FLAGS
//-----------------------------------------------------------------------------
// BIT 31: Xfer started but not finished
#define SEC_DMA_FLAG_ACTIVE             0x80000000

// BIT 30: Interrupt when source xfer finished
#define SEC_DMA_FLAG_SRC_INT            0x40000000

// BIT 29: Interrupt when destination xfer finished
#define SEC_DMA_FLAG_DST_INT            0x20000000

// BIT 28: Terminator bit: when set indicates last node in a linked-list xfer.
#define SEC_DMA_FLAG_TERM               0x10000000

// ONLY VALID IN STORE AND FORWARD MODE
// BIT 27: Swap endian on source (big-endian source)
// BIT 26: Swap endian on dest (big-endian dest)
#define SEC_DMA_FLAG_SRC_SWAP           0x08000000
#define SEC_DMA_FLAG_DST_SWAP           0x04000000


// ONLY VALID IN READ-ONLY AND WRITE-ONLY MODES
// BIT 25: Source is big endian
// BIT 24: Destination is big endian
#define SEC_DMA_FLAG_SRC_BEND           0x02000000
#define SEC_DMA_FLAG_DST_BEND           0x01000000

// BITS 23-20: RESERVED

// BITS 19-16: XDMA gap 
#define SEC_DMA_FLAG_XDMA_GAP(X)        (((X) << 16) & 0x000F0000)

// BITS 15-12: XSI burst size 
#define SEC_DMA_FLAG_XBST_SZ(X)         (((X) << 12) & 0x0000F000)

// BITS 11-8: RESERVED

// BIT 7: Read mode - if both read AND write selected => store & forward mode
#define SEC_DMA_FLAG_MODE_READ          0x00000080

// BITS 6-5: Source buffer mode; if not set, defaults to LINEAR
#define SEC_DMA_FLAG_SRC_MODE_LINEAR    0x00000000  // LINEAR
#define SEC_DMA_FLAG_SRC_MODE_CIRCULAR  0x00000020  // CIRCULAR
#define SEC_DMA_FLAG_SRC_MODE_FIX       0x00000040  // FIXED
#define SEC_DMA_FLAG_SRC_MODE_FIX_CONT  0x00000060  // FIXED CONTINUOUS

// BIT 4: Source linked-list mode enabled
#define SEC_DMA_FLAG_SRC_LL             0x00000010

// BIT 3: Write mode - if both read AND write selected => store & forward mode
#define SEC_DMA_FLAG_MODE_WRITE         0x00000008

// BITS 2-1: Destination buffer mode; if not set, defaults to LINEAR
#define SEC_DMA_FLAG_DST_MODE_LINEAR    0x00000000  // LINEAR
#define SEC_DMA_FLAG_DST_MODE_CIRCULAR  0x00000002  // CIRCULAR
#define SEC_DMA_FLAG_DST_MODE_FIX       0x00000004  // FIXED
#define SEC_DMA_FLAG_DST_MODE_FIX_CONT  0x00000006  // FIXED CONTINUOUS

// BIT 0: Destination linked-list mode enabled
#define SEC_DMA_FLAG_DST_LL             0x00000001

// ALL read-only transfers must have these flags set.
// Either SEC_DMA_FLAG_DST_MODE_FIX or SEC_DMA_FLAG_DST_MODE_FIX_CONT must also
// be set, as appropriate.
#define SEC_DMA_READ_FLAGS      SEC_DMA_FLAG_MODE_READ      \
                                | SEC_DMA_FLAG_SRC_BEND     \
                                | SEC_DMA_FLAG_XDMA_GAP(1)  \
                                | SEC_DMA_FLAG_XBST_SZ(6)

// ALL write-only transfers must have these flags set.
// XBurst size is 256 bytes SEC HW will transfer 256 bytes to memory at a time
// XDMA GAP is 16 clocks. The destination is Big Endian.
#define SEC_DMA_WRITE_FLAGS     SEC_DMA_FLAG_MODE_WRITE     \
                                | SEC_DMA_FLAG_SRC_MODE_FIX \
                                | SEC_DMA_FLAG_DST_BEND     \
                                | SEC_DMA_FLAG_XDMA_GAP(1)  \
                                | SEC_DMA_FLAG_XBST_SZ(6)

// ALL store-and-forward transfers must have these flags set.
#define SEC_DMA_STF_FLAGS       SEC_DMA_FLAG_MODE_READ      \
                                | SEC_DMA_FLAG_MODE_WRITE   \
                                | SEC_DMA_FLAG_SRC_SWAP     \
                                | SEC_DMA_FLAG_DST_SWAP     \
                                | SEC_DMA_FLAG_XDMA_GAP(1)  \
                                | SEC_DMA_FLAG_XBST_SZ(6)

// store-and-forward transfers for ARC4 cipher must have these flags set.
#define SEC_DMA_STF_FLAGS_ARC4  SEC_DMA_FLAG_MODE_READ      \
                                | SEC_DMA_FLAG_MODE_WRITE   \
                                | SEC_DMA_FLAG_SRC_BEND     \
                                | SEC_DMA_FLAG_DST_BEND     \
                                | SEC_DMA_FLAG_XDMA_GAP(1)  \
                                | SEC_DMA_FLAG_XBST_SZ(6)

// DMA FLAGS Settings for SMD source to user space kernel locked DMA destination
#define SEC_SMD_SRC_TO_DMA_DST  SEC_DMA_FLAG_DST_LL         \
                                | SEC_DMA_FLAG_MODE_WRITE   \
                                | SEC_DMA_FLAG_MODE_READ    \
                                | SEC_DMA_FLAG_XBST_SZ(6)   \
                                | SEC_DMA_FLAG_XDMA_GAP(1)  \
                                | SEC_DMA_FLAG_SRC_SWAP     \
                                | SEC_DMA_FLAG_DST_SWAP

// DMA FLAGS settings for last DMA descriptor's flags when using
// SMD source to user space kernel locked DMA destination
#define SEC_SMD_SRC_TO_DMA_TERM SEC_DMA_FLAG_DST_LL         \
                                | SEC_DMA_FLAG_MODE_WRITE   \
                                | SEC_DMA_FLAG_MODE_READ    \
                                | SEC_DMA_FLAG_XBST_SZ(6)   \
                                | SEC_DMA_FLAG_XDMA_GAP(1)  \
                                | SEC_DMA_FLAG_SRC_SWAP     \
                                | SEC_DMA_FLAG_DST_SWAP     \
                                | SEC_DMA_FLAG_DST_INT      \
                                | SEC_DMA_FLAG_TERM

//-----------------------------------------------------------------------------
// FW Loading Types
//-----------------------------------------------------------------------------

#define SEC_FW_MAX_PATH_LEN         256
#define SEC_FW_UNKNOWN_MODULE_ID    0xFFFFFFFF
#define SEC_FW_UNKNOWN_MODULE_VER   0xFFFFFFFF
#define SEC_MAX_CE3100_FW_MODULES   1
#define SEC_MAX_CE4200_FW_MODULES   4
#define SEC_MAX_LOADED_FW_MODULES   SEC_MAX_CE4200_FW_MODULES

typedef enum {
    SEC_FW_LOADED_INIT,         /* Already loaded when module init'ed */
    SEC_FW_LOADED_FILESYSTEM,   /* Loaded from the filesystem */
    SEC_FW_LOADED_BINARY,       /* Loaded as a passed binary */
} sec_fw_load_time_t;

#define SEC_MAX_FW_CONTIG_COUNT 4

typedef struct {
    sec_kernel_ipc_t    ipc_call;  /* Data passed to IPC call */
    uint32_t            module_id; /* Module ID from ICSS header */
    sec_fw_load_time_t  loaded_by; /* Stores info on who loaded this module */
    char                image_path[SEC_FW_MAX_PATH_LEN]; /* Unused on unload */
#ifdef KERNEL
    sec_contig_mem_t __user * contig_mem[SEC_MAX_FW_CONTIG_COUNT];
#else
    sec_contig_mem_t *  contig_mem[SEC_MAX_FW_CONTIG_COUNT];
#endif
                                   /* Array of contiguous mem entry ptrs;
                                    * NOTE: These are USER SPACE pointers */
} sec_fw_load_t;

typedef enum {
    SEC_FW_LOAD = 0,            /* Load an FW image */
    SEC_FW_UNLOAD,              /* Unload an FW image */
    SEC_FW_GET_LOADED_FW_INFO,  /* Get info on all loaded FW modules */
    SEC_FW_GET_VERSIONS,        /* Get info about loaded FW from the HW */
} sec_fw_ioctl_cmd_t;

typedef enum
{
    SEC_FW_UNLOADED     = 0,
    SEC_FW_LOADING      = 1,
    SEC_FW_INITIALIZING = 2,   /* Unused at this time */
    SEC_FW_INITIALIZED  = 3,   /* Unused at this time */
    SEC_FW_LOADED       = 4
} sec_fw_loading_status_t;

typedef struct
{
    uint32_t                loaded_fw_id;  /* AKA: module_id; this name is used
                                              because user space uses it.
                                              TODO: change to module_id */
    uint32_t                version;       /* Module version */
    sec_fw_loading_status_t status;        /* Loading status */
    uint32_t                index;         /* Index in user context lists */
} sec_fw_info_t;

typedef struct
{
    uint32_t       numloaded;  /* Number of loaded modules */
    sec_fw_info_t  fw_info[SEC_MAX_LOADED_FW_MODULES];
} sec_loaded_fw_info_t; /* Used for storage in user-space */

typedef struct
{
    unsigned long *      rom_ver;
    unsigned long *      mod_count;
    sec_module_list_t *  mod_list;
} sec_fw_ioctl_ver_info_t;

typedef union {
    sec_fw_load_t           fw_load;    /* SEC_FW_LOAD and SEC_FW_UNLOAD */
    sec_loaded_fw_info_t *  loaded_fw_info;
    uint32_t                module_id;
    sec_fw_ioctl_ver_info_t fw_ver_info;/* SEC_FW_GET_VERSIONS */
} sec_fw_ioctl_data_t;

typedef struct {
    sec_fw_ioctl_cmd_t  command;
    sec_fw_ioctl_data_t data;
} sec_fw_ioctl_t;  /* Stores FW IOCTL info */

#endif
