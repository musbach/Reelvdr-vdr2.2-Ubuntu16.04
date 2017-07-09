/*!
 * \file libmfhapi.h
 * \author
 * \version 1.0
 * \brief
 * Declaration of the mfh api.
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
 * Declaration of the mfh api.
 *
 */

/*!
* \mainpage MFH Implementation as Linux lib
   The Master Flash Header serves as a road map for the contents of flash that are processed by security and host firmware. It contains the location and size of each element in the flash, as well as a list of host firmware images that the security processor will attempt to boot. \n
   This list enables capabilities such as golden image failover (the last image in the list can be a known-good image) and safe updates (if an update fails, the security firmware can move on to the next item in the list, the previous version of host firmware). \n

*/

#ifndef __LIB_MFH_API_H__
#define __LIB_MFH_API_H__


#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif


//=======================================================================
// MFH API Functions
//=======================================================================


//
// mfh_info
//
// DESCRIPTION:
// This function displays information about the MFH contained in the specified flash device. 
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
//
mfh_error_desc_t mfh_info(mfh_device_type_t device_type);



//
// mfh_init
//
// DESCRIPTION:
// This function will initialize the specified flash device with a new MFH table containing
// entries for a single CEFDK and a user flash area. The user space area will be created
// starting at the specified offset. The CEFDK image data will be copied from the provided
// file to the first availble location of MFH-managed flash address space (i.e. non-user space).

//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <user_offset> - Specifies the offset in flash at which the user space (non-MFH-managed) area
//                 begins. Thus user space extends from this offset to the end of the partition.
// <image_filename> - File containing the CEFDK binary image to be written to flash
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
// --> All data presently in the MFH-managed area of the flash device at the time this function
// is called will be lost. User space data may also be lost of the user offset provided is located
// higher in flash address space than its previous setting, effectively decreasing size of user space.)
//
mfh_error_desc_t mfh_init(mfh_device_type_t device_type, uint32_t user_offset, char *image_filename);



//
// mfh_defrag
//
// DESCRIPTION:
// This function will defragment the specified flash device by relocating all entries such that
// each entry resides in flash consecutively (i.e. fill-in the gaps).
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
//
//mfh_error_desc_t mfh_defrag(mfh_device_type_t device_type);




//
// mfh_list
//
// DESCRIPTION:
// This function displays each of the entries contained within the MFH of the flash device.
// The list will be filtered according to the specified target type.
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <target_type> - Value of mfh_item_type_t specifying which type(s) of entries to display.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
// --> To display all entries in the MFH, pass a value of 'all' for <target_type>.
//
mfh_error_desc_t mfh_list(mfh_device_type_t device_type, mfh_item_type_t target_type);




//
// mfh_add
//
// DESCRIPTION:
// This function adds and entry to the MFH of the specified flash device, sets the entry's flash
// item type and ID to the provided values, then copies the image data from specified file to the
// next available offset in flash.
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <target_type> - Value of mfh_item_type_t specifying the type of entry to be added.
//
// <target_id> - Specifies the ID of the entry to be added.
//
// <image_filename> - File containing the binary image to be written to flash.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
// --> When adding a CEFDK image to the flash, use value 'cefdk' for the <target_type> parameter.
// Even though types 'host_fw_stage1', 'host_fw_stage1_header', 'host_fw_stage2', and
// 'host_fw_stage2_header' are sub-compents of the CEFDK, this function does not currently
// support user manipulation of these types at this time.
//
mfh_error_desc_t mfh_add(mfh_device_type_t device_type, mfh_item_type_t target_type, uint32_t target_id, char *image_filename);




//
// mfh_label
//
// DESCRIPTION:
// This function adds a label to the entry matching the provided type and id values from the MFH
// of the specified flash device.
//
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <target_type> - Value of mfh_item_type_t specifying the type of the entry to which the lable will
//                 be applied.
//
// <target_id> - Specifies the ID of the entry to which the label will be applied.
//
// <lablel> - Pointer to character string containing no more than MFH_FLASH_ITEM_LABEL_SIZE characters
//            (null terminator not included).
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
//
mfh_error_desc_t mfh_label(mfh_device_type_t device_type, mfh_item_type_t target_type, uint32_t target_id, char *label);




//
// mfh_delete
//
// DESCRIPTION:
// This function deletes the entry matching the provided type and id values from the MFH
// of the specified flash device.
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <target_type> - Value of mfh_item_type_t specifying the type of the entry to delete.
//
// <target_id> - Specifies the ID of the entry to delete.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
//
mfh_error_desc_t mfh_delete(mfh_device_type_t device_type, mfh_item_type_t target_type, uint32_t target_id);


//
// mfh_activate
//
// DESCRIPTION:
// This function activates the entry matching the provided type and id values from the MFH
// of the specified flash device.
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <target_type> - Value of mfh_item_type_t specifying the type of the entry to activate.
//
// <target_id> - Specifies the ID of the entry to activate.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
// --> Once any entry is made active, it becomes a viable entry for use by the system. Entries with type 'cefdk'
// will be added to the MFH 'Boot Priority Index List', thus becoming available to the Secuirty FW for
// booting the system.
//
mfh_error_desc_t mfh_activate(mfh_device_type_t device_type, mfh_item_type_t target_type, uint32_t target_id);


//
// mfh_deactivate
//
// DESCRIPTION:
// This function deactivates the entry matching the provided type and id values from the MFH
// of the specified flash device.
//
// PARAMETERS:
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <target_type> - Value of mfh_item_type_t specifying the type of the entry to deactivate.
//
// <target_id> - Specifies the ID of the entry to deactivate.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
// --> Once deactivated, the entry is no longer a viable entry for use by the system. Entries with type 'cefdk'
// will be removed from the MFH 'Boot Priority Index List', thus becoming unavailable to the Secuirty FW for
// booting the system.
//
mfh_error_desc_t mfh_deactivate(mfh_device_type_t device_type, mfh_item_type_t target_type, uint32_t target_id);


//
// mfh_updateparamzone
//
// DESCRIPTION:
// This function update the parameter zone of the specified flash device.
//
// PARAMETERS:
//
// <direction> - read -1, write - 0.
//
// <device_type> - Value of mfh_device_type_t specifying the target flash device.
//
// <pparambuf> - buffer pointer of parameter data.
//
// <offinpz> - offset in parameter zone.
//
// <paramsize> - Size of the parameter data.
//
// RETURN:
// Value of type mfh_error_desc_t signaling any errors. Returns 0 if no error.
//
// USAGE NOTES:
// 
//
mfh_error_desc_t mfh_paramio (int direction, mfh_device_type_t device_type, char *pparambuf, uint32_t offinpz, uint32_t paramsize);

uint32_t print_mfh_entry_offset(mfh_device_type_t device_type, uint32_t target_id, mfh_item_type_t entry_type);

uint32_t print_mfh_entry_size(mfh_device_type_t device_type, uint32_t target_id, mfh_item_type_t entry_type);

mfh_device_type_t print_mfh_boot_device_type();

#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif


#endif //__LIB_MFH_API_H__

