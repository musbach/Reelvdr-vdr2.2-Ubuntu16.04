//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------

#ifndef SEC_TYPES_H
#define SEC_TYPES_H

//----------------------------------------------------------------------------
// Known SEC HW PCI vendor and device identifications
//----------------------------------------------------------------------------
#define PCI_VENDOR_INTEL    0x8086

#define PCI_DEVICE_CE3100   0x2E50
#define PCI_REV_CE3100_B1   0X05

#define PCI_DEVICE_CE4100   0x0708
#define PCI_REV_CE4100_A1   0x00
#define PCI_REV_CE4100_B0   0x04
#define PCI_REV_CE4100_B1   0x05

#define PCI_DEVICE_CE4200   0x0709
#define PCI_REV_CE4200_A0   0x00
#define PCI_REV_CE4200_B0   0x04
#define PCI_REV_CE4200_C0   0x08

#define PCI_DEVICE_CE5300   0x0C40
#define PCI_REV_CE5300_A0   0x00

#define PCI_BUS_HOST         0x00
#define PCI_DEV_HOST         0x00
#define PCI_FUNC_HOST        0x00

#define PCI_DEVICE_SEC      0x2E64
#define PCI_REV_SEC_CE3100B1 0x00
#define PCI_REV_SEC_CE4100A1 0x01
#define PCI_REV_SEC_CE4100B0 0x02
#define PCI_REV_SEC_CE4100B1 0x02
#define PCI_REV_SEC_CE4200A0 0x03
#define PCI_REV_SEC_CE4200B0 0x04
#define PCI_REV_SEC_CE4200B1 0x05
#define PCI_REV_SEC_CE5300A0 0x06
#define PCI_REV_SEC_CE5300B0 0x07

#define PCI_BUS_SEC         0x01
#define PCI_DEV_SEC         0x09
#define PCI_FUNC_SEC        0x00

/** SEC DEVICE CONTEXT */
typedef int sec_dev_context_t;

/** Chip PCI Info */
typedef struct
{
    unsigned short    host_vendor;
    unsigned short    host_device;
    unsigned short    host_revision;
    unsigned short    sec_vendor;
    unsigned short    sec_device;
    unsigned short    sec_revision;
} sec_chip_info_t;

/** loadable fw module versions */
typedef struct
{
    unsigned long      module_id;
                           /*!<  module id of the corresponding FW module  */
    unsigned long      module_version;
                           /*!<  version number of the corresponding FW module  */
} sec_module_list_t;

/** MEMORY ADDRESS TYPES */
typedef enum
{
    SEC_ADDR_VIRTUAL     = 0x1,
    SEC_ADDR_PHYSCONTIG,
} sec_addr_t;

/** MEMORY BUFFER */
typedef struct
{
    sec_addr_t     addr_type; /*!<  the address type  */
    unsigned long  size;      /*!< the size of the associated memory in bytes */
    unsigned long  offset ;   /*!< the initial offset from the start address in bytes */
    void          *phys_virt; /*!< Linux virtual address associated with the physical */
    union
    {
        void *         virt;  /*!<  virtual pointer (if addr_type==SEC_ADDR_VIRTUAL)  */
        unsigned long  phys;  /*!<  physical address (if addr_type is SEC_ADDR_PHYSCONTIG */
    } addr;                   /*!<  virtual or physical address, depending on addr_type  */
} sec_buffer_t;

/** DMA Chain Type 
Defines DMA Descriptor chain types
 LT is Long Term it means it was created when
    an application explicitly called sec_create_dma_desc
 ST is Short Term it means the descriptor was automatically created
    on behalf of the calling application when it called sec_aes_process_dma
    without first explicitly calling sec_create_dma_desc
*/
typedef enum
{
    SEC_DMA_DESC_LT = 0,
    SEC_DMA_DESC_ST = 1
} sec_dma_chain_t;


/** CIPHER MODE */
typedef enum
{
    SEC_ENCRYPTION  = 0x1,
    SEC_DECRYPTION  = 0x2,
} sec_cipher_mode_t;

/** SHA MODE */
typedef enum
{
    SEC_SHA1    = 0x0,
    SEC_SHA256  = 0x1,
    SEC_SHA224  = 0x2,
    SEC_SHA384  = 0x3,
    SEC_SHA512  = 0x4,
} sec_sha_mode_t;

/** MAC MODE */
typedef enum
{
	SEC_HMAC_SHA1	= 0x0,
	SEC_HMAC_SHA256 = 0x1,
	SEC_HMAC_SHA512 = 0x4,
	SEC_CMAC_AES128 = 0x5,
	SEC_CMAC_AES192 = 0x6,
	SEC_CMAC_AES256 = 0x7,
} sec_mac_mode_t;

/** RSA digest type */
typedef enum
{
    SEC_RSA_DIGEST_SHA1,
    SEC_RSA_DIGEST_SHA256,
    SEC_RSA_DIGEST_SHA384,
    SEC_RSA_DIGEST_SHA512,
    SEC_RSA_DIGEST_MD5,
    SEC_RSA_DIGEST_SHA1MD5 = 7,
} sec_rsa_digest_type_t;

/** RSA Signature Type */
typedef enum
{
    SEC_RSA_PKCS1_1_5_SIGNATURE = 0x00,
    SEC_RSA_PSS_SIGNATURE = 0x01
}sec_signature_t;

/** CRYPTOGRAPHIC ALGORITHM */
typedef enum
{
    SEC_DES_CIPHER  = 0x0,  ///< DES encrytion and decryption
    SEC_2TDES_CIPHER= 0x1,  ///< 2-key Triple DES encrytion and decryption
    SEC_3TDES_CIPHER= 0x2,  ///< 3-key Triple DES encrytion and decryption
    SEC_AES_CIPHER  = 0x3,  ///< AES encrytion and decryption
    SEC_RSA_CIPHER  = 0x4,  ///< RSA encryption/decryption (OAEP) and
                            ///< sign/verification (PKCS 1.5)
    SEC_ARC4_CIPHER = 0x5,  ///< ARC4 encrytion and decryption
    SEC_RSA_PKCS15_CIPHER = 0x6,///< RSA decryption for PKCS 1.5 
                                ///< Padding. Requires FW.
    SEC_RSA_OAEP_CIPHER   = 0x7,///< Tag NOT implemented - placeholder
    SEC_C2_CIPHER   = 0x8,  ///< C2 Encryption and Decryption
    SEC_CSS_CIPHER  = 0x9,  ///< CSS Decryption
} sec_cipher_t;

/** CIPHER CHAIN MODE */
typedef enum
{
    SEC_ECB = 0x0,
    SEC_CBC = 0x1,
    SEC_CTR = 0x2
} sec_cipher_chain_mode_t;

/** IV INCREMENT OPTION FOR CTR MODE */
typedef enum
{
    SEC_NO_IV_INCREMENT     = 0x0,  /**< No bits to be incremented. Indicates SW
                                      *  is implementing the incrementing function
                                      */
    SEC_32BIT_IV_INCREMENT  = 0x1,  ///< Increment LSB 32 bits
    SEC_64BIT_IV_INCREMENT  = 0x2,  ///< Increment LSB 64 bits
    SEC_128BIT_IV_INCREMENT = 0x3   ///< Increment all 128 bits
} sec_iv_inc_mode_t;

/** LOCATION OF CRYPTOGRAPHIC KEY */
typedef enum
{
    SEC_INTERNAL_KEY      = 0x0, 
        ///< Use key in internal key ladder slot (sec_key_cache_slot_t)
    SEC_EXTERNAL_KEY      = 0x1, 
        ///< Pass key in as a parameter
    SEC_INTERNAL_KEY_EXT  = 0x2  
        ///< Use key in internal memory slot (Requires downloadable firmware)
} sec_key_location_t ;

/** KEY LADDER OPTION */
typedef enum
{
    SEC_PRIMARY_KEY_LADDER   = 0x0,  ///< reserved for specific CA vendors
    SEC_SECONDARY_KEY_LADDER = 0x1,  /**< used to unwrap off-chip secrets that are wrapped 
                                       *  and stored in external flash.  It can be used for
                                       *  flash encryption or HDCP key load on Intel CE3100 
                                       *  Media Processor.
                                       *  
                                      */
    SEC_SOFTWARE_KEY_LADDER  = 0x3,  ///< reserved for future use
} sec_key_ladder_t;


/** INTERNAL ASYMMETRIC KEY STORES */
typedef enum
{
    SEC_RSA_INTERNAL_KEYSTORE_0 = 0x1
} sec_key_store_t;

/* TDP status definitions*/
#define PMR_DISABLED -1
#define PMR_ENABLED_FW_LOADED 0
#define PMR_ENABLED_FW_TB_LOADED 1


/** INTERNAL SYMMETRIC KEY IDS */
typedef enum
{
    SEC_SSK     = 0x0,
    SEC_M1      = 0x1,
    SEC_M2a     = 0x2,
    SEC_CCW1    = 0x3,
    SEC_CCW2    = 0x4,
    SEC_CCW3    = 0x5,
    SEC_CCW4    = 0x6,
    SEC_N1      = 0x7,
    SEC_N2      = 0x8,
    SEC_CW1     = 0x9,
    SEC_CW2     = 0xa,
    SEC_CW3     = 0xb,
    SEC_CW4     = 0xc,
    SEC_CW5     = 0xd,
    SEC_CW6     = 0xe,
    SEC_CW7     = 0xf,
    SEC_CW8     = 0x10,
    SEC_PSK     = 0x11,
    SEC_M2b     = 0x12,
    SEC_M2c     = 0x13,
    SEC_MEMORY  = 0xff
}sec_key_cache_slot_t;

/** TSD key store location indicator for "none"  */
#define SEC_TSD_KEYLOC_NONE  0xFFu
#define SEC_TSD_KEY_MAX      0xFFu

/** TSD key store attributes  */
typedef enum
{
    SEC_TSD_KEYATTR_AES       = 0x00,
    SEC_TSD_KEYATTR_DES_TDES  = 0x01,
    SEC_TSD_KEYATTR_3DES      = 0x02,
    SEC_TSD_KEYATTR_MULTI2    = 0x03,
    SEC_TSD_KEYATTR_DVB_CSA2  = 0x04,
    SEC_TSD_KEYATTR_DVB_CSA3  = 0x05,
} sec_tsd_key_attrs_t;
/** we define an alias for "not used" case:  */
#define SEC_TSD_KEYATTR_NONE  SEC_TSD_KEYATTR_AES


  typedef enum {
    SEC_PLAINTEXT = 0x0,
    SEC_INTEL_GKEK = 0x1,
    SEC_CUSTOMER_GKEK = 0x2,
    SEC_INTERNAL_KEY_STORE = 0x3,
    SEC_PROVISIONED_KEY = 0x4,
    SEC_OEM_SEED = 0x5
  } sec_encryption_type_t;

typedef enum
{
    SEC_GENERATE_STORE = 0x0,
    SEC_GENERATE_RETURN =0x1,
    SEC_GENERATE_PROVISION =0x2
}sec_generate_key_mode_t;

/** SEC API RETURN VALUES */
typedef enum
{
    SEC_SUCCESS                     = 0x00,
    SEC_FAIL                        = 0x01,
    SEC_DRIVER_OPEN_FAILURE         = 0x02,
    SEC_INVALID_CONTEXT             = 0x03,
    SEC_OUT_OF_MEMORY               = 0x04,
    SEC_DRIVER_CLOSE_FAILURE        = 0x05,
    SEC_NULL_POINTER                = 0x06,
    SEC_INVALID_INPUT               = 0x07,
    SEC_INVALID_CIPHER              = 0x08,
    SEC_INVALID_INTERNAL_KEY        = 0x09,
    SEC_UNSUPPORTED_CIPHER          = 0x0a,
    SEC_INVALID_KEY_LOCATION        = 0x0b,
    SEC_INVALID_KEY_LENGTH          = 0x0c,
    SEC_INVALID_CHAIN_MODE          = 0x0d,
    SEC_INVALID_KEY_LADDER          = 0x0e,
    SEC_INVALID_KEY_ID              = 0x0f,
    SEC_INVALID_KEY_STORE           = 0x10,
    SEC_INVALID_IV_LENGTH           = 0x11,
    SEC_INVALID_CIPHER_MODE         = 0x12,
    SEC_INVALID_BUFF_SIZE           = 0x13,
    SEC_INVALID_OFFSET_SIZE         = 0x14,
    SEC_UNSUPPORTED_SHA_MODE        = 0x15,
    SEC_INVALID_RANDOM_NUMBER_SIZE  = 0x16,
    SEC_INVALID_FW_MODULE_SIZE      = 0x17,
    SEC_UNSUPPORT_FUNCTION          = 0x18,
    SEC_INVALID_DATA_LENGTH         = 0x19,
    SEC_INVALID_KEY                 = 0x1a,
    SEC_INVALID_SRC_LOCATION        = 0x1b,
    SEC_INVALID_ENTROPY_SIZE        = 0x1c,
    SEC_INVALID_AACS_KEY            = 0x1d,
    SEC_INVALID_ID                  = 0x1e,
    SEC_DEVICE_BUSY                 = 0x1f,
                /**< Requested cipher working on another request, or internal
                  * scratchpad memory full: try again later.
                  */
    SEC_INVALID_HOST_REQUEST        = 0x20,
                /**< Illegal request issued to firmware: make sure proper
                  * SEC firmware is loaded.
                  */
    SEC_NO_AACS_CONTEXT_AVAILABLE   = 0x21,
                /**< No free AACS context available
                  */
    SEC_INVALID_HASH                = 0x22,
                /**< Invalid hash or hash mode selected
                  */  
    SEC_INTERNAL_ERROR              = 0x23,
                /**< Internal error occured
                  */
    SEC_INVALID_PROVISION_TYPE      = 0x24,
                /**< Invalid provisioning selection passed to
                  *  sec_wrap_AACS_keys()
                  */
    SEC_INVALID_CUR_PTR             = 0x25,
                /**< Non-NULL "current flash module" pointer passed to
                  *  sec_wrap_AACS_keys(), when provisioning type is 
                  *  sec_prov_initial.
                  */  
    SEC_NOT_SUPPORTED               = 0x26,
                /**< Functionality not supported by target SOC.
                  */  
    SEC_EXT_FW_NOT_LOADED           = 0x27,
    SEC_INVALID_VARIANT             = 0x28,
                /**< Variant data was zero (indicating self revoked)
                  */  
    SEC_EXT_FW_INVALID_PKG_SIZE     = 0x29,
    SEC_EXT_FW_DUPLICATE_KEY_ID     = 0x2a,
    SEC_EXT_FW_INVALID_KEY_ID       = 0x2b, 
    SEC_PCI_DEVICE_NOT_FOUND        = 0x30,
    SEC_PCI_DEVICE_ACCESS_ERROR     = 0x31,
    SEC_FW_LOADING_IS_DISABLED      = 0x32,
    SEC_NOT_AN_INTEL_SOC            = 0x33,
    SEC_NOT_A_SUPPORTED_INTEL_SOC   = 0x34,
    SEC_HW_PCI_ID_UNKNOWN           = 0x35,
    SEC_FW_FILE_NOT_FOR_THIS_SOC    = 0x36,
    SEC_FW_FILE_OPEN_FAILED         = 0x37,
    SEC_FW_FILE_HAS_ZERO_LENGTH     = 0x38,
    SEC_FW_FILE_READ_FAIL           = 0x39,
    SEC_FW_FILE_MEM_CALC_ERROR      = 0x3a,
    SEC_FW_INVALID_LOAD_TYPE        = 0x3b,
    SEC_FW_MODULE_NOT_FOUND         = 0x3c,
    SEC_FW_MODULE_ALREADY_LOADED    = 0x3d,
    SEC_FW_HKEY_OPERATION_ERROR     = 0x3e,
    SEC_FW_SYMBOL_TABLE_MISMATCH    = 0x3f,
    SEC_FW_NO_MANIFEST_ENTRY        = 0x40,
    SEC_FW_FS_ELF_LOAD_FAILED       = 0x41,
    SEC_FW_FS_SEEK_OUT_OF_BOUNDS    = 0x42,
    SEC_FW_FS_INVALID_SEEK_TYPE     = 0x43,
    SEC_FW_FS_REOPEN_FILE_ERROR     = 0x44,
    SEC_FW_FS_PAGE_NOT_FOUND        = 0x45,
    SEC_FW_FS_HEADER_LENGTH_MISMATCH= 0x46,
    SEC_FW_INVALID_PAGE_ADDRESS     = 0x47,
    SEC_FW_FS_FILE_NOT_OPENED       = 0x48,
    SEC_FW_SYSTEM_MEMORY_FULL       = 0x49,
    SEC_FW_INVALID_SYSTEM_ADDRESS   = 0x4a,
    SEC_FW_INVALID_MODE             = 0x4b,
    SEC_FW_INVALID_NONCE            = 0x4c,
    SEC_FW_INVALID_STEP             = 0x4d,
    SEC_FW_INVALID_KEY_ATTRIBUTES   = 0x4e,
    SEC_FW_TTB_KEY_INVALID          = 0x4f,
    SEC_FW_INVALID_KEY_TYPE         = 0x50,
    SEC_FW_INVALID_KEY_SELECT       = 0x51,
    SEC_FW_NO_KEY_SLOTS_AVAILABLE   = 0x52,
    SEC_FW_DRBG_NOT_INITIALIZED     = 0x53,
    SEC_FW_INVALID_HW_COMMAND       = 0x54,
    SEC_FW_EAU_PARITY_ERROR         = 0x55,
    SEC_FW_MOD_EXP_WITHOUT_EXPONENT = 0x56,
    SEC_FW_INVALID_AES_CTR_MODE     = 0x57,
    SEC_FW_INVALID_CHAIN_MODE       = 0x58,
    SEC_FW_LOAD_DIDNOT_AUTHENTICATE = 0x59,
    SEC_FW_CANNOT_LOAD_FULL         = 0x5a,
    SEC_FW_FILE_PATH_TOO_LONG       = 0x5b,
    SEC_FW_FILE_INVALID_HDR_DATA    = 0x5c,
    SEC_FW_INVALID_LOADED_FW_COUNT  = 0x5d,
    SEC_RDFLASH_AACS_FAIL           = 0x5e,
    SEC_RDFLASH_AACS_INVALID_PARAM  = 0x5f,
    SEC_RDFLASH_AACS_INVALID_SIZE   = 0x60,
    SEC_RDFLASH_AACS_INVALID_KEYSZ  = 0x61,
    SEC_RDFLASH_UNKNOWN_ERROR       = 0x62,
    SEC_INVALID_MEMALIGNMENT        = 0x63,
    SEC_INVALID_STEP                = 0x64,
    SEC_MMAP_PHYSMEM_STILL_MAPPED   = 0x65,
    SEC_MMAP_INVALID_TGID           = 0x66,
    SEC_MMAP_FAILED_GET_VIRTADDR    = 0x67,
    SEC_MUNMAP_INVALID_TGID         = 0x68,
    SEC_MUNMAP_FAILED               = 0x69,
    /* TODO: Any reason we skipped 6a-6f? */
    SEC_PHYS_MEMORY_UNALIGNED       = 0x70,
    SEC_FW_FILE_EXT_NOT_RECOGNIZED  = 0x71,
    SEC_PM_INVALID_STATE            = 0x72, /**< Request was not valid in this
                                                 power mode */
    SEC_UNSUPPORTED_MAC_MODE		= 0x73,
    SEC_EAU_LOCK_FAILED             = 0x74,
    SEC_EAU_LOCK_INTERRUPTED        = 0x75,
    SEC_TDP_INIT_FAILED             = 0x76,
    SEC_NO_DTCPIP_CONTEXT_AVAILABLE = 0x77,
    SEC_DMA_DST_NOT_DWORD_ALIGNED   = 0x78,
    SEC_DMA_SRC_NOT_DWORD_ALIGNED   = 0x79,
    SEC_DMA_DST_PAGE_POINTER_IS_NULL= 0x7a,
    SEC_DMA_SRC_PAGE_POINTER_IS_NULL= 0x7b,
    SEC_DMA_PHYS_VIRT_NOT_READWRITE = 0x7c,
    SEC_DMA_PHYS_FAILED_MAP_TO_VIRT = 0x7d,
    SEC_DMA_COULD_NOT_FIND_CLIENT   = 0x7e,
    SEC_DMA_MAP_VM_TO_DESC_FAILED   = 0x7f,
    SEC_DMA_SRC_NULL_POINTER        = 0x80,
    SEC_DMA_DST_NULL_POINTER        = 0x81,
    SEC_DMA_IPL_NULL_POINTER        = 0x82,
    SEC_DMA_NO_NODES_FOR_TGID       = 0x83,
    SEC_FW_CRYPT_OP_FAILED          = 0x84,
    SEC_FW_DRM_CONTEXT_INVALID      = 0x85,
    SEC_FW_DRM_CONTEXT_NOT_AVAILABLE= 0x86,
    SEC_NOT_IMPLEMENTED_YET         = 0xffff,
} sec_result_t;

/** convenience macro for test programs (return name of status) */
#define SEC_RESULT_TEXT(s) \
    ( ((s)==SEC_SUCCESS)                     ? "SEC_SUCCESS" : \
      ((s)==SEC_FAIL)                        ? "SEC_FAIL" : \
      ((s)==SEC_DRIVER_OPEN_FAILURE)         ? "SEC_DRIVER_OPEN_FAILURE" : \
      ((s)==SEC_INVALID_CONTEXT)             ? "SEC_INVALID_CONTEXT" : \
      ((s)==SEC_OUT_OF_MEMORY)               ? "SEC_OUT_OF_MEMORY" : \
      ((s)==SEC_DRIVER_CLOSE_FAILURE)        ? "SEC_DRIVER_CLOSE_FAILURE" : \
      ((s)==SEC_NULL_POINTER)                ? "SEC_NULL_POINTER" : \
      ((s)==SEC_INVALID_INPUT)               ? "SEC_INVALID_INPUT" : \
      ((s)==SEC_INVALID_CIPHER)              ? "SEC_INVALID_CIPHER" : \
      ((s)==SEC_INVALID_INTERNAL_KEY)        ? "SEC_INVALID_INTERNAL_KEY" : \
      ((s)==SEC_UNSUPPORTED_CIPHER)          ? "SEC_UNSUPPORTED_CIPHER" : \
      ((s)==SEC_INVALID_KEY_LOCATION)        ? "SEC_INVALID_KEY_LOCATION" : \
      ((s)==SEC_INVALID_KEY_LENGTH)          ? "SEC_INVALID_KEY_LENGTH" : \
      ((s)==SEC_INVALID_CHAIN_MODE)          ? "SEC_INVALID_CHAIN_MODE" : \
      ((s)==SEC_INVALID_KEY_LADDER)          ? "SEC_INVALID_KEY_LADDER" : \
      ((s)==SEC_INVALID_KEY_ID)              ? "SEC_INVALID_KEY_ID" : \
      ((s)==SEC_INVALID_KEY_STORE)           ? "SEC_INVALID_KEY_STORE" : \
      ((s)==SEC_INVALID_IV_LENGTH)           ? "SEC_INVALID_IV_LENGTH" : \
      ((s)==SEC_INVALID_CIPHER_MODE)         ? "SEC_INVALID_CIPHER_MODE" : \
      ((s)==SEC_INVALID_BUFF_SIZE)           ? "SEC_INVALID_BUFF_SIZE" : \
      ((s)==SEC_INVALID_OFFSET_SIZE)         ? "SEC_INVALID_OFFSET_SIZE" : \
      ((s)==SEC_UNSUPPORTED_SHA_MODE)        ? "SEC_UNSUPPORTED_SHA_MODE" : \
      ((s)==SEC_INVALID_RANDOM_NUMBER_SIZE)  ? "SEC_INVALID_RANDOM_NUMBER_SIZE" : \
      ((s)==SEC_INVALID_FW_MODULE_SIZE)      ? "SEC_INVALID_FW_MODULE_SIZE" : \
      ((s)==SEC_UNSUPPORT_FUNCTION)          ? "SEC_UNSUPPORT_FUNCTION" : \
      ((s)==SEC_INVALID_DATA_LENGTH)         ? "SEC_INVALID_DATA_LENGTH" : \
      ((s)==SEC_INVALID_KEY)                 ? "SEC_INVALID_KEY" : \
      ((s)==SEC_INVALID_SRC_LOCATION)        ? "SEC_INVALID_SRC_LOCATION" : \
      ((s)==SEC_INVALID_ENTROPY_SIZE)        ? "SEC_INVALID_ENTROPY_SIZE" : \
      ((s)==SEC_INVALID_AACS_KEY)            ? "SEC_INVALID_AACS_KEY" : \
      ((s)==SEC_INVALID_ID)                  ? "SEC_INVALID_ID" : \
      ((s)==SEC_DEVICE_BUSY)                 ? "SEC_DEVICE_BUSY" : \
      ((s)==SEC_INVALID_HOST_REQUEST)        ? "SEC_INVALID_HOST_REQUEST" : \
      ((s)==SEC_NO_AACS_CONTEXT_AVAILABLE)   ? "SEC_NO_AACS_CONTEXT_AVAILABLE" : \
      ((s)==SEC_INVALID_HASH)                ? "SEC_INVALID_HASH" : \
      ((s)==SEC_INTERNAL_ERROR)              ? "SEC_INTERNAL_ERROR" : \
      ((s)==SEC_INVALID_PROVISION_TYPE)      ? "SEC_INVALID_PROVISION_TYPE" : \
      ((s)==SEC_INVALID_CUR_PTR)             ? "SEC_INVALID_CUR_PTR" : \
      ((s)==SEC_NOT_SUPPORTED)               ? "SEC_NOT_SUPPORTED" : \
      ((s)==SEC_EXT_FW_NOT_LOADED)           ? "SEC_EXT_FW_NOT_LOADED" : \
      ((s)==SEC_INVALID_VARIANT)             ? "SEC_INVALID_VARIANT" : \
      ((s)==SEC_EXT_FW_INVALID_PKG_SIZE)     ? "SEC_EXT_FW_INVALID_PKG_SIZE" : \
      ((s)==SEC_EXT_FW_DUPLICATE_KEY_ID)     ? "SEC_EXT_FW_DUPLICATE_KEY_ID" : \
      ((s)==SEC_EXT_FW_INVALID_KEY_ID)       ? "SEC_EXT_FW_INVALID_KEY_ID" : \
      ((s)==SEC_PCI_DEVICE_NOT_FOUND)        ? "SEC_PCI_DEVICE_NOT_FOUND" : \
      ((s)==SEC_PCI_DEVICE_ACCESS_ERROR)     ? "SEC_PCI_DEVICE_ACCESS_ERROR" : \
      ((s)==SEC_FW_LOADING_IS_DISABLED)      ? "SEC_FW_LOADING_IS_DISABLED" : \
      ((s)==SEC_NOT_AN_INTEL_SOC)            ? "SEC_NOT_AN_INTEL_SOC" : \
      ((s)==SEC_NOT_A_SUPPORTED_INTEL_SOC)   ? "SEC_NOT_A_SUPPORTED_INTEL_SOC" : \
      ((s)==SEC_HW_PCI_ID_UNKNOWN)           ? "SEC_HW_PCI_ID_UNKNOWN" : \
      ((s)==SEC_FW_FILE_NOT_FOR_THIS_SOC)    ? "SEC_FW_FILE_NOT_FOR_THIS_SOC" : \
      ((s)==SEC_FW_FILE_OPEN_FAILED)         ? "SEC_FW_FILE_OPEN_FAILED" : \
      ((s)==SEC_FW_FILE_HAS_ZERO_LENGTH)     ? "SEC_FW_FILE_HAS_ZERO_LENGTH" : \
      ((s)==SEC_FW_FILE_READ_FAIL)           ? "SEC_FW_FILE_READ_FAIL" : \
      ((s)==SEC_FW_FILE_MEM_CALC_ERROR)      ? "SEC_FW_FILE_MEM_CALC_ERROR" : \
      ((s)==SEC_FW_INVALID_LOAD_TYPE)        ? "SEC_FW_INVALID_LOAD_TYPE" : \
      ((s)==SEC_FW_MODULE_NOT_FOUND)         ? "SEC_FW_MODULE_NOT_FOUND" : \
      ((s)==SEC_FW_MODULE_ALREADY_LOADED)    ? "SEC_FW_MODULE_ALREADY_LOADED" : \
      ((s)==SEC_FW_HKEY_OPERATION_ERROR)     ? "SEC_FW_HKEY_OPERATION_ERROR" : \
      ((s)==SEC_FW_SYMBOL_TABLE_MISMATCH)    ? "SEC_FW_SYMBOL_TABLE_MISMATCH" : \
      ((s)==SEC_FW_NO_MANIFEST_ENTRY)        ? "SEC_FW_NO_MANIFEST_ENTRY" : \
      ((s)==SEC_FW_FS_ELF_LOAD_FAILED)       ? "SEC_FW_FS_ELF_LOAD_FAILED" : \
      ((s)==SEC_FW_FS_SEEK_OUT_OF_BOUNDS)    ? "SEC_FW_FS_SEEK_OUT_OF_BOUNDS" : \
      ((s)==SEC_FW_FS_INVALID_SEEK_TYPE)     ? "SEC_FW_FS_INVALID_SEEK_TYPE" : \
      ((s)==SEC_FW_FS_REOPEN_FILE_ERROR)     ? "SEC_FW_FS_REOPEN_FILE_ERROR" : \
      ((s)==SEC_FW_FS_PAGE_NOT_FOUND)        ? "SEC_FW_FS_PAGE_NOT_FOUND" : \
      ((s)==SEC_FW_FS_HEADER_LENGTH_MISMATCH) ? "SEC_FW_FS_HEADER_LENGTH_MISMATCH" : \
      ((s)==SEC_FW_INVALID_PAGE_ADDRESS)     ? "SEC_FW_INVALID_PAGE_ADDRESS" : \
      ((s)==SEC_FW_FS_FILE_NOT_OPENED)       ? "SEC_FW_FS_FILE_NOT_OPENED" : \
      ((s)==SEC_FW_SYSTEM_MEMORY_FULL)       ? "SEC_FW_SYSTEM_MEMORY_FULL" : \
      ((s)==SEC_FW_INVALID_SYSTEM_ADDRESS)   ? "SEC_FW_INVALID_SYSTEM_ADDRESS" : \
      ((s)==SEC_FW_INVALID_MODE)             ? "SEC_FW_INVALID_MODE" : \
      ((s)==SEC_FW_INVALID_NONCE)            ? "SEC_FW_INVALID_NONCE" : \
      ((s)==SEC_FW_INVALID_STEP)             ? "SEC_FW_INVALID_STEP" : \
      ((s)==SEC_FW_INVALID_KEY_ATTRIBUTES)   ? "SEC_FW_INVALID_KEY_ATTRIBUTES" : \
      ((s)==SEC_FW_TTB_KEY_INVALID)          ? "SEC_FW_TTB_KEY_INVALID" : \
      ((s)==SEC_FW_INVALID_KEY_TYPE)         ? "SEC_FW_INVALID_KEY_TYPE" : \
      ((s)==SEC_FW_INVALID_KEY_SELECT)       ? "SEC_FW_INVALID_KEY_SELECT" : \
      ((s)==SEC_FW_NO_KEY_SLOTS_AVAILABLE)   ? "SEC_FW_NO_KEY_SLOTS_AVAILABLE" : \
      ((s)==SEC_FW_DRBG_NOT_INITIALIZED)     ? "SEC_FW_DRBG_NOT_INITIALIZED" : \
      ((s)==SEC_FW_INVALID_HW_COMMAND)       ? "SEC_FW_INVALID_HW_COMMAND" : \
      ((s)==SEC_FW_EAU_PARITY_ERROR)         ? "SEC_FW_EAU_PARITY_ERROR" : \
      ((s)==SEC_FW_MOD_EXP_WITHOUT_EXPONENT) ? "SEC_FW_MOD_EXP_WITHOUT_EXPONENT" : \
      ((s)==SEC_FW_INVALID_AES_CTR_MODE)     ? "SEC_FW_INVALID_AES_CTR_MODE" : \
      ((s)==SEC_FW_INVALID_CHAIN_MODE)       ? "SEC_FW_INVALID_CHAIN_MODE" : \
      ((s)==SEC_FW_LOAD_DIDNOT_AUTHENTICATE) ? "SEC_FW_LOAD_DIDNOT_AUTHENTICATE" : \
      ((s)==SEC_FW_CANNOT_LOAD_FULL)         ? "SEC_FW_CANNOT_LOAD_FULL" : \
      ((s)==SEC_FW_FILE_PATH_TOO_LONG)       ? "SEC_FW_FILE_PATH_TOO_LONG" : \
      ((s)==SEC_FW_FILE_INVALID_HDR_DATA)    ? "SEC_FW_FILE_INVALID_HDR_DATA" : \
      ((s)==SEC_FW_INVALID_LOADED_FW_COUNT)  ? "SEC_FW_INVALID_LOADED_FW_COUNT" : \
      ((s)==SEC_RDFLASH_AACS_FAIL)           ? "SEC_RDFLASH_AACS_FAIL" : \
      ((s)==SEC_RDFLASH_AACS_INVALID_PARAM)  ? "SEC_RDFLASH_AACS_INVALID_PARAM" : \
      ((s)==SEC_RDFLASH_AACS_INVALID_SIZE)   ? "SEC_RDFLASH_AACS_INVALID_SIZE" : \
      ((s)==SEC_RDFLASH_AACS_INVALID_KEYSZ)  ? "SEC_RDFLASH_AACS_INVALID_KEYSZ" : \
      ((s)==SEC_RDFLASH_UNKNOWN_ERROR)       ? "SEC_RDFLASH_UNKNOWN_ERROR" : \
      ((s)==SEC_INVALID_MEMALIGNMENT)        ? "SEC_INVALID_MEMALIGNMENT" : \
      ((s)==SEC_NOT_IMPLEMENTED_YET)         ? "SEC_NOT_IMPLEMENTED_YET" : \
      ((s)==SEC_INVALID_STEP)                ? "SEC_INVALID_STEP" : \
      ((s)==SEC_MMAP_PHYSMEM_STILL_MAPPED)   ? "SEC_MMAP_PHYSMEM_STILL_MAPPED" : \
      ((s)==SEC_MMAP_INVALID_TGID)           ? "SEC_MMAP_INVALID_TGID" : \
      ((s)==SEC_MMAP_FAILED_GET_VIRTADDR)    ? "SEC_MMAP_FAILED_GET_VIRTADDR" : \
      ((s)==SEC_MUNMAP_INVALID_TGID)         ? "SEC_MUNMAP_INVALID_TGID" : \
      ((s)==SEC_MUNMAP_FAILED)               ? "SEC_MUNMAP_FAILED" : \
      ((s)==SEC_PHYS_MEMORY_UNALIGNED)       ? "SEC_PHYS_MEMORY_UNALIGNED" : \
      ((s)==SEC_PM_INVALID_STATE)            ? "SEC_PM_INVALID_STATE" : \
      ((s)==SEC_UNSUPPORTED_MAC_MODE)        ? "SEC_UNSUPPORTED_MAC_MODE" : \
      ((s)==SEC_EAU_LOCK_FAILED)             ? "SEC_EAU_LOCK_FAILED" : \
      ((s)==SEC_EAU_LOCK_INTERRUPTED)        ? "SEC_EAU_LOCK_INTERRUPTED" : \
      ((s)==SEC_TDP_INIT_FAILED)             ? "SEC_TDP_INIT_FAILED" : \
      ((s)==SEC_NO_DTCPIP_CONTEXT_AVAILABLE) ? "SEC_NO_DTCPIP_CONTEXT_AVAILABLE" : \
      ((s)==SEC_DMA_DST_NOT_DWORD_ALIGNED)   ? "SEC_DST_NOT_DWORD_ALIGNED" : \
      ((s)==SEC_DMA_SRC_NOT_DWORD_ALIGNED)   ? "SEC_SRC_NOT_DWORD_ALIGNED" : \
      ((s)==SEC_DMA_DST_PAGE_POINTER_IS_NULL)? "SEC_DMA_DST_PAGE_POINTER_IS_NULL" : \
      ((s)==SEC_DMA_SRC_PAGE_POINTER_IS_NULL)? "SEC_DMA_SRC_PAGE_POINTER_IS_NULL" : \
      ((s)==SEC_DMA_PHYS_VIRT_NOT_READWRITE) ? "SEC_DMA_PHYS_VIRT_NOT_READWRITE" : \
      ((s)==SEC_DMA_PHYS_FAILED_MAP_TO_VIRT) ? "SEC_DMA_PHYS_FAILED_MAP_TO_VIRT" : \
      ((s)==SEC_DMA_COULD_NOT_FIND_CLIENT)   ? "SEC_DMA_COULD_NOT_FIND_CLIENT" : \
      ((s)==SEC_DMA_MAP_VM_TO_DESC_FAILED)   ? "SEC_DMA_MAP_VM_TO_DESC_FAILED" : \
      ((s)==SEC_DMA_SRC_NULL_POINTER)        ? "SEC_DMA_SRC_NULL_POINTER" : \
      ((s)==SEC_DMA_DST_NULL_POINTER)        ? "SEC_DMA_DST_NULL_POINTER" : \
      ((s)==SEC_DMA_IPL_NULL_POINTER)        ? "SEC_DMA_IPL_NULL_POINTER" : \
      ((s)==SEC_DMA_NO_NODES_FOR_TGID)       ? "SEC_DMA_NO_NODES_FOR_TGID" : \
      ((s)==SEC_FW_CRYPT_OP_FAILED)          ? "SEC_FW_CRYPT_OP_FAILED" : \
      ((s)==SEC_FW_DRM_CONTEXT_INVALID)      ? "SEC_FW_DRM_CONTEXT_INVALID" : \
      ((s)==SEC_FW_DRM_CONTEXT_NOT_AVAILABLE)? "SEC_FW_DRM_CONTEXT_NOT_AVAILABLE" : \
                                               "<unrecognized status code>" )

#endif
