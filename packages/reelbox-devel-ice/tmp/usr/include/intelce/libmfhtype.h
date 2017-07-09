/*!
 * \file libmfhtype.h
 * \author
 * \version 1.0
 * \brief
 * Defines and typedefs for mfh lib.
 *
 * \section LICENSE
 *
"Copyright (c) 2010-2011 Intel Corporation 
DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
This Distributable As Sample Source Software is subject to the
terms and conditions of the Intel Software License Agreement for
the Intel(R) Media Processor Software Development Kit"
 *
 * @section DESCRIPTION
 *
 * Defines and typedefs for mfh lib.
 *
 */
 
#ifndef __LIB_MFH_TYPE_H__
#define __LIB_MFH_TYPE_H__


#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif


//=======================================================================
// MFH API Definitions
//=======================================================================

/*!
* \typedef mfh_device_type_t
 These labels are used to specify which flash device will be the target of the
 various MFH API function calls.
*/
typedef enum
{
    mfh_boot_device = 0,	/*!< Target the flash device used to boot the system. */
    mfh_exp_nor     = 1,	/*!< Target the NOR device (debug mode only) */
    mfh_emmc        = 2,	/*!< Target the eMMC NAND device */
    mfh_spi_nor     = 3,	/*!< Target the SPI NOR flash */
} mfh_device_type_t;
/*
typedef enum {
    flash_exp_nor = 0,
    flash_emmc    = 1,
    flash_spi_nor = 2,
} flash_type_t;
*/
/*!
* \typedef mfh_item_type_t
* Enumeration of the currently supported MFH Item types. Several values are marked RESERVED for
* use only by the MFH API private functions and should not be exposed to the user.
*/
typedef enum
{
    host_fw_stage1          = 0x00000000,	/*!< RESERVED - For use by MFH API private functions only */
    host_fw_stage1_header   = 0x00000001, /*!< RESERVED - For use by MFH API private functions only */
    host_fw_stage2          = 0x00000002, /*!< RESERVED - For use by MFH API private functions only */
    host_fw_stage2_header   = 0x00000003, /*!< RESERVED - For use by MFH API private functions only */
    host_fw_parameters      = 0x00000004, /*!< firmware parameters */
    platform_parameters     = 0x00000005, /*!< platform parameters to be managed by flash_appdata lib */
    bootloader              = 0x00000006,	/*!< redboot */
    kernel                  = 0x00000007,		/*!< bzImage */
    splash_screen           = 0x00000008,	/*!< splash screen */
    manifest_table          = 0x00000009,	/*!< manifest table */
    sec_fw_module           = 0x0000000A,	/*!< security firmware module */
    ramdisk                 = 0x0000000B,	/*!< ramdisk */
    ilp                     = 0x0000000C,		/*!< ILP */
    cefdk_commands          = 0x0000000D,	/*!< cefdk commands */
    bootloader_parameters   = 0x0000000E,	/*!< redboot params */
    all                     = 0x80000000,	/*!< all */
    cefdk                   = 0x8000000F,	/*!< cefdk */
    illegal                 = 0xDEADD00D,	/*!< RESERVED - For use by MFH API private functions only */
    user_flash              = 0xFFFFFFFF	 /*!< RESERVED - For use by MFH API private functions only */
} mfh_item_type_t;

/*!
* \typedef mfh_error_desc_t
* These mask values are used to for the return value for the MFH API functions calls.
*/
typedef enum
{
    mfh_error_none                   = 0x00000000,  /*!< No error */
    mfh_error_boot_item_limit        = 0x00000001,  /*!< Number of active CEFDK images exceeds MFH_MAX_CEFDKS */
    mfh_error_first_block_item_limit = 0x00000002,  /*!< Number of flash items in the first block exceeds MFH_MAX_FLASH_ITEMS_PER_BLOCK */
    mfh_error_block_item_limit       = 0x00000004,  /*!< Number of flash items in the block exceeds MFH_MAX_FLASH_ITEMS_PER_BLOCK */
    mfh_error_flash_read             = 0x00000008,  /*!< Error reading flash device */
    mfh_error_flash_write            = 0x00000010,  /*!< Error write to flash device */
    mfh_error_invalid_item_type      = 0x00000020,  /*!< Invalid value specified for parameter of type mfh_item_type_t */
    mfh_error_invalid_flash_device   = 0x00000040,  /*!< Invalid value specified for parameter of type flash_device_type_t */
    mfh_error_invalid_image_file     = 0x00000080,  /*!< Invalid filename or file specified for parameter image_filename */
    mfh_error_uspecified             = 0x80000000,	/*!< unspecified error */
} mfh_error_desc_t;


#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif


#endif //__LIB_MFH_TYPE_H__

