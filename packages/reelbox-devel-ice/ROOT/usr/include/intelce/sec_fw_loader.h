//-----------------------------------------------------------------------------
// Copyright (c) 2008-2011 Intel Corporation
//
// DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
//
// This Distributable As Sample Source Software is subject to the terms and
// conditions of the Intel Software License Agreement provided with the Intel(R)
// Media Processor Software Development Kit.
//-----------------------------------------------------------------------------
#ifndef _SEC_FW_LOADER_H_
#define _SEC_FW_LOADER_H_

#define MODULE_START    10
#define SIGNATURE_START 11
#define ENCRYPTED       12
#define SEC_FW_VERSION_NO 0x01010000

#define SECFW_ROM_PATCH_MIN      0x1000
#define SECFW_ROM_PATCH_MAX      0x1FFF
#define SECFW_AACS               0x2000
#define SECFW_WMDRM              0x3000
#define SECFW_MARLIN             0x4000
#define SECFW_NAGRA              0x5000
#define SECFW_CISCO              0x6000

//-----------------------------------------------------------------------------
// sec_fw_module_loader
//
/**  @ingroup misc
 *
 * This sec_fw_module_loader function allows the application to load,
 * authenticate, and optionally decrypt an SEC firmware update module.
 * The SEC FW module is encrypted and signed by Intel. This function
 * handles the CE3100 and CE4100 as well as CE4200. The user just
 * passes in the filename to load. It will look in /lib/firmware/sec/
 * for the firmware file.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in]  filename
 *              This is a pointer to the firmware file name. This function
 *              will concatenate this name to /lib/firmware/sec/ to get
 *              a complete path name.
 *
 * @param[in,out]  fw_type
 *              This is a pointer integer that receives the FW type number.
 *
 * @retval SEC_SUCCESS
 *              Successfully loaded the firmware into the SEC.
 * @retval SEC_NULL_POINTER
 *              The file name pointer is NULL.
 * @retval SEC_FW_LOADING_IS_DISABLED
 *              The chip is not fused for firmware loading.
 * @retval SEC_NOT_AN_INTEL_SOC
 *              The chip's host processor is not an Intel product.
 * @retval SEC_NOT_A_SUPPORTED_INTEL_SOC
 *              This chip is an Intel product but it is not a supported
 *              Intel SoC.
 * @retval SEC_HW_PCI_ID_UNKNOWN
 *              This chip is a supported Intel SoC but the reported
 *              SEC is not supported.
 * @retval SEC_FW_FILE_NOT_FOR_THIS_SOC
 *              This firmware file is not for this Intel SoC.
 * @retval SEC_FW_FILE_NOT_FOR_THIS_SOC
 *              This firmware file is not for this Intel SoC.
 * @retval SEC_FW_FILE_OPEN_FAILED
 *              The sec_fw_file_open function failed opening firmware file.
 * @retval SEC_FW_FILE_MEM_CALC_ERROR
 *              The calculation for the amount of memory to allocated
 *              to read in the whole firmware file was wrong.
 * @retval SEC_OUT_OF_MEMORY
 *              Could not allocate memory for the whole firmware file.
 * @retval SEC_FW_FILE_READ_FAIL
 *              The fread function returned some error.
 * @retval
 *         Also returned are errors from sec_fw_file_open,
 *         sec_fw_load_3100_4100, and sec_fw_load_4200.
*/
//-----------------------------------------------------------------------------
sec_result_t sec_fw_module_loader(sec_dev_context_t sec_dev_context,
                                  char *filename, int *fw_type );


//-----------------------------------------------------------------------------
// sec_fw_module_unloader
//
/**  @ingroup misc
 *
 * This sec_fw_module_unloader function unloads any firmware modules
 * that the passed in context previously loaded.
 *
 * @param[in]  sec_dev_context
 *              This is the sec_dev_context_t structure associated
 *              with this instance of sec_dev_open.
 * @param[in]  module_id
 *              This is the module ID of the firmware module you would like to
 *              unload. It is the value returned in fw_type when calling
 *              sec_fw_module_loader. If this value is zero, all modules will
 *              be unloaded.
 *
 * @retval SEC_SUCCESS
 *              Successfully loaded the firmware into the SEC.
 * @retval SEC_INVALID_CONTEXT
 *              The context_t pointer ctx is NULL.
 * @retval SEC_INVALID_INPUT
 *              Module ID provided was invalid.
 * @retval
 *         Also returned are errors from the device driver ioctl call.
*/
//-----------------------------------------------------------------------------
sec_result_t sec_fw_module_unloader(sec_dev_context_t sec_dev_context,
                                    uint32_t          module_id);

//-----------------------------------------------------------------------------
// sec_fw_module_load_from_RAM
//
/**  @ingroup misc
 *
 * This sec_fw_module_load_from_RAM function allows the application to load,
 * authenticate, and optionally decrypt an SEC firmware update module.
 * The SEC FW module is encrypted and signed by Intel. This function
 * handles the CE3100 and CE4100 as well as CE4200. The user just
 * passes in the filename to load. It will look in /lib/firmware/sec/
 * for the firmware file.
 *
 * @param[in] sec_dev_context
 *              The SEC context, returned by sec_dev_open(), in which the
 *              operation should take place.
 *
 * @param[in]  buffer
 *              This is a pointer to the firmware image. This function
 *              will call the IPC command that loads the firmware module
 *               pointed to by the buffer.
 *
 * @param[in]  size
 *              This argument represents the size of the firmware image
 *              pointed to by buffer.
 *
 * @param[in]  path
 *              This argument represents the path of the firmware package
                that is being loaded.
 *
 * @param[in,out]  fw_type
 *              This is a pointer integer that receives the FW type number.
 *
 * @retval SEC_SUCCESS
 *              Successfully loaded the firmware into the SEC.
 * @retval SEC_NULL_POINTER
 *              The file name pointer is NULL.
 * @retval SEC_FW_LOADING_IS_DISABLED
 *              The chip is not fused for firmware loading.
 * @retval SEC_NOT_AN_INTEL_SOC
 *              The chip's host processor is not an Intel product.
 * @retval SEC_NOT_A_SUPPORTED_INTEL_SOC
 *              This chip is an Intel product but it is not a supported
 *              Intel SoC.
 * @retval SEC_HW_PCI_ID_UNKNOWN
 *              This chip is a supported Intel SoC but the reported
 *              SEC is not supported.
 * @retval SEC_FW_FILE_NOT_FOR_THIS_SOC
 *              This firmware file is not for this Intel SoC.
 * @retval SEC_FW_FILE_NOT_FOR_THIS_SOC
 *              This firmware file is not for this Intel SoC.
 * @retval SEC_FW_FILE_OPEN_FAILED
 *              The sec_fw_file_open function failed opening firmware file.
 * @retval SEC_FW_FILE_MEM_CALC_ERROR
 *              The calculation for the amount of memory to allocated
 *              to read in the whole firmware file was wrong.
 * @retval SEC_OUT_OF_MEMORY
 *              Could not allocate memory for the whole firmware file.
 * @retval SEC_FW_FILE_READ_FAIL
 *              The fread function returned some error.
 * @retval
 *         Also returned are errors from sec_fw_file_open,
 *         sec_fw_load_3100_4100, and sec_fw_load_4200.
*/
//-----------------------------------------------------------------------------

sec_result_t sec_fw_module_load_from_RAM(sec_dev_context_t sec_dev_context,
                                   void    *         buffer,
                                   unsigned int      size,
                                   const char *      path, 
                                   int     *         fw_type);
#endif

