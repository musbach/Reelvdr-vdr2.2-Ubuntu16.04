/****************************************************************************
 * Copyright (c) 2008-2010 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: flash_appdata_memmap.h
 ***************************************************************************/

#ifndef FLASH_APPDATA_MEMMAP_INCLUDED
#define FLASH_APPDATA_MEMMAP_INCLUDED

#ifdef __cplusplus
extern "C" {
# if 0
}  /*  hack to make things less confusing for some editors  */
# endif
#endif

// Values are here until it determined how Flash Driver will assigning BLK 257 for Key Conatiner
#define	P30_BLK258_SEG_OFFSET		0x8000
//#define	P30_NOR_BLK_257_SEGMENT		0x1FF0000

/* 16KB only of Application partition data reserved for key containers */
#define  MAX_APD_SIZE 0x4000

/*!
 *  NOR Flash address memory map and their offset, including all. (For P30, they're blk257 & blk258)
 *  @enum nor_flash_memmap
 */
enum nor_flash_memmap
{
	nor_kc_base						= 0x0000, /*!< Key Container Base Address */
	nor_kc_cpu_serial_base			= 0x0004, /*!< + 4 dec */
	nor_kc_key_data_base			= 0x0010, /*!< + 12 dec */
	nor_hdcp_cpu_id_base			= P30_BLK258_SEG_OFFSET + 0x00000,	/*!< HDCP Base Address - Reserved 8KB Data */
	nor_hdcp_cpu_serial_base		= P30_BLK258_SEG_OFFSET + 0x00004,	/*!< + 4 dec */
	nor_hdcp_riv_base				= P30_BLK258_SEG_OFFSET + 0x0000D,  /*!< + 8 dec */
	nor_hdcp_eks_base				= P30_BLK258_SEG_OFFSET + 0x0001E,  /*!< + 16 dec */
	nor_hdcp_ksv_base				= P30_BLK258_SEG_OFFSET + 0x0013F,	/*!< + 288 dec */
	nor_hdcp_srm_length_base		= P30_BLK258_SEG_OFFSET + 0x00145,	/*!< + 5 dec */
	nor_hdcp_srm_list_base			= P30_BLK258_SEG_OFFSET + 0x0014A,	/*!< + 4 dec */
	nor_hdcp_2_base					= P30_BLK258_SEG_OFFSET + 0x0154B,	/*!< + 5120 dec */
	nor_hdcp_rsvd_base				= P30_BLK258_SEG_OFFSET + 0x018E5,	/*!< + 922 dec */
	nor_board_cfg_base				= P30_BLK258_SEG_OFFSET + 0x02000,	/*!< Board Config Base Address - Reserved 1KB Data */
	nor_board_rsvd_base				= P30_BLK258_SEG_OFFSET + 0x02100,	/*!< 256 Bytes currently being used */
	nor_plyrdy_cpu_id_base			= P30_BLK258_SEG_OFFSET + 0x02400,	/*!< Play Ready Base Address - Reserved 3KB Data */
	nor_plyrdy_cpu_serial_base		= P30_BLK258_SEG_OFFSET + 0x02404,	/*!< + 4 dec */
	nor_plyrdy_modal_key_base		= P30_BLK258_SEG_OFFSET + 0x02410,  /*!< Modal Key Data */
	nor_aacs_cpu_id_base			= P30_BLK258_SEG_OFFSET + 0x03000,	/*!< ACCS Base Address - Reserved 16KB Data */
	nor_aacs_cpu_serial_base		= P30_BLK258_SEG_OFFSET + 0x03004,	/*!< + 4 dec */
	nor_aacs_host_cert_base			= P30_BLK258_SEG_OFFSET + 0x0300C,	/*!< + 8 dec */
	nor_aacs_key_blob_base			= P30_BLK258_SEG_OFFSET + 0x03068,	/*!< + 92 dec */
	nor_ctv_length_base				= P30_BLK258_SEG_OFFSET + 0x07000,	/*!< Cable TV  Base Address - Reserved 4KB Data */
	nor_ctv_key_base				= P30_BLK258_SEG_OFFSET + 0x07004,	/*!< + 4 dec */
};
#if 0
/*!
 *  NOR Flash BLK 258 address memory map and their offset.
 *  @enum nor_flash_blk258_memmap
 */
enum nor_flash_blk258_memmap
{
	nor_hdcp_cpu_id_base			= 0x00000,	/*!< HDCP Base Address */
	nor_hdcp_cpu_serial_base		= 0x00004,	/*!< + 4 dec */
	nor_hdcp_riv_base				= 0x0000D,  /*!< + 8 dec */
	nor_hdcp_eks_base				= 0x0001E,  /*!< + 16 dec */
	nor_hdcp_ksv_base				= 0x0013F,	/*!< + 288 dec */
	nor_hdcp_srm_length_base		= 0x00145,	/*!< + 5 dec */
	nor_hdcp_srm_list_base			= 0x0014A,	/*!< + 4 dec */
	nor_hdcp_2_base					= 0x0154B,	/*!< + 5120 dec */
	nor_hdcp_rsvd_base				= 0x018E5,	/*!< + 922 dec */
	nor_board_cfg_base				= 0x02000,	/*!< Board Config Base Address - Reserved 1KB Data */
	nor_board_rsvd_base				= 0x02100,	/*!< 256 Bytes currently being used */
	nor_plyrdy_cpu_id_base			= 0x02400,	/*!< Play Ready Base Address - Reserved 3KB Data */
	nor_plyrdy_cpu_serial_base		= 0x02404,	/*!< + 4 dec */
	nor_plyrdy_oem_key_base			= 0x02410,	/*!< + 8 dec - CPU Serial Number + 4 dec - Spare */
	nor_plyrdy_modal_key_base		= 0x02460,  /*!< + 80 dec - OEM Key Data */
	nor_aacs_cpu_id_base			= 0x03000,	/*!< ACCS Base Address */
	nor_aacs_cpu_serial_base		= 0x03004,	/*!< + 4 dec */
	nor_aacs_host_cert_base			= 0x0300C,	/*!< + 8 dec */
	nor_aacs_key_blob_base			= 0x03068,	/*!< + 92 dec */
	nor_ctv_length_base				= 0x07000,	/*!< Cable TV  Base Address */
	nor_ctv_key_base				= 0x07004,	/*!< + 4 dec */
};

/*!
 *  NOR Flash BLK 257 address memory map and their offset.
 *  @enum nor_flash_blk257_memmap
 */
enum nor_flash_blk257_memmap
{
	nor_kc_base						= 0x1FF0000, /*!< Key Container Base Address */
	nor_kc_cpu_serial_base			= 0x1FF0004, /*!< + 4 dec */
	nor_kc_key_data_base			= 0x1FF000C, /*!< + 8 dec */
};
#endif
/*!
 *  NOR Flash BLK 248 address memory map and their offset.
 *  @enum nor_flash_blk248_memmap
 */
enum nor_flash_blk248_memmap
{
	nor_nic_mac_base				= 0X1F00000, /*!< NIC Base Address */
	nor_nic_config_base				= 0X1F00006,
	nor_nic_rsvd_base				= 0X1F00206, /*!< + 512 dec */
};
#if 0	//be replaced by std_param_memmap
/*!
 *  NAND Flash address memory map and their offset.
 *  @enum nand_flash_memmap
 */
enum nand_flash_memmap
{
	nand_hdcp_cpu_id_base			= 0x00000,	/*!< HDCP Base Address */
	nand_hdcp_cpu_serial_base		= 0x00004,	/*!< + 4 dec */
	nand_hdcp_riv_base				= 0x0000D,  /*!< + 8 dec */
	nand_hdcp_eks_base				= 0x0001E,  /*!< + 16 dec */
	nand_hdcp_ksv_base				= 0x0013F,	/*!< + 288 dec */
	nand_hdcp_srm_length_base		= 0x00145,	/*!< + 5 dec */
	nand_hdcp_srm_list_base			= 0x0014A,	/*!< + 4 dec */
	nand_hdcp_2_base				= 0x0154B,	/*!< + 5120 dec */
	nand_hdcp_rsvd_base				= 0x018E5,	/*!< + 922 dec */
	nand_board_cfg_base				= 0x02000,	/*!< Board Config Base Address - Reserved 1KB Data */
	nand_board_rsvd_base			= 0x02100,	/*!< 256 Bytes currently being used */
	nand_plyrdy_cpu_id_base			= 0x02400,	/*!< Play Ready Base Address - Reserved 3KB Data */
	nand_plyrdy_cpu_serial_base		= 0x02404,	/*!< + 4 dec */
	nand_plyrdy_modal_key_base		= 0x02410,  /*!< Modal Key Data */
	nand_aacs_cpu_id_base			= 0x03000,	/*!< ACCS Base Address */
	nand_aacs_cpu_serial_base		= 0x03004,	/*!< + 4 dec */
	nand_aacs_host_cert_base		= 0x0300C,	/*!< + 8 dec */
	nand_aacs_key_blob_base			= 0x03068,	/*!< + 92 dec */
	nand_nic_mac_base				= 0x07000,	/*!< NIC Base Address */
	nand_nic_config_base			= 0x07006,
	nand_nic_rsvd_base				= 0x07200,	/*!< + 512 dec */
	nand_ctv_length_base			= 0x07800,	/*!< Cable TV  Base Address */
	nand_ctv_key_base				= 0x07804,	/*!< + 4 dec */
	nand_kc_base					= 0x08800,	/*!< Key Container Base Address */
	nand_kc_cpu_serial_base			= 0x08804,	/*!< + 4 dec */
	nand_kc_key_data_base			= 0x08810,	/*!< + 12 dec */
	nand_sec_fw_base				= 0x0C000,	// Sec Firmware needs to be removed...
};
#endif
/*!
 *  Standard (MFH and legacy NAND) address memory map and their offset.
 *  @enum std_param_memmap
 */
enum std_param_memmap
{
	std_hdcp_cpu_id_base			= 0x00000,	/*!< HDCP Base Address */
	std_hdcp_cpu_serial_base		= 0x00004,	/*!< + 4 dec */
	std_hdcp_riv_base				= 0x0000D,  /*!< + 8 dec */
	std_hdcp_eks_base				= 0x0001E,  /*!< + 16 dec */
	std_hdcp_ksv_base				= 0x0013F,	/*!< + 288 dec */
	std_hdcp_srm_length_base		= 0x00145,	/*!< + 5 dec */
	std_hdcp_srm_list_base			= 0x0014A,	/*!< + 4 dec */
	std_hdcp_2_base			 		= 0x0154B,	/*!< + 5120 dec */
	std_hdcp_rsvd_base				= 0x018E5,	/*!< + 922 dec */
	std_board_cfg_base				= 0x02000,	/*!< Board Config Base Address - Reserved 1KB Data */
	std_board_rsvd_base				= 0x02100,	/*!< 256 Bytes currently being used */
	std_plyrdy_cpu_id_base			= 0x02400,	/*!< Play Ready Base Address - Reserved 3KB Data */
	std_plyrdy_cpu_serial_base		= 0x02404,	/*!< + 4 dec */
	std_plyrdy_modal_key_base		= 0x02410,  /*!< Modal Key Data */
	std_aacs_cpu_id_base			= 0x03000,	/*!< ACCS Base Address */
	std_aacs_cpu_serial_base		= 0x03004,	/*!< + 4 dec */
	std_aacs_host_cert_base			= 0x0300C,	/*!< + 8 dec */
	std_aacs_key_blob_base			= 0x03068,	/*!< + 92 dec */
	std_nic_mac_base				= 0x07000,	/*!< NIC Base Address */
	std_nic_config_base				= 0x07006,
	std_nic_rsvd_base				= 0x07200,	/*!< + 512 dec */
	std_ctv_length_base				= 0x07800,	/*!< Cable TV  Base Address */
	std_ctv_key_base				= 0x07804,	/*!< + 4 dec */
	std_kc_base						= 0x08800,	/*!< Key Container Base Address */
	std_kc_cpu_serial_base			= 0x08804,	/*!< + 4 dec */
	std_kc_key_data_base			= 0x08810,	/*!< + 12 dec */
	std_sec_fw_base					= 0x0C000,	// Sec Firmware needs to be removed...
};

// HDCP Config Space - 8 KBytes 8192 (0x2000)

//defined in hdcp_flash.c
extern const int hdcp_cpu_id_size;			// 4 Bytes
extern const int hdcp_cpu_serial_size;		// 8 Bytes
extern const int hdcp_riv_size;				// 16 Bytes
extern const int hdcp_eks_size;				// 288 Bytes
extern const int hdcp_ksv_size;				// 5 Bytes
extern const int hdcp_srm_length_size;		// 4 Bytes
extern const int hdcp_srm_list_size;		// 5 KBytes
extern const int hdcp_2_key_size;			// 922 Bytes

//defined in flash_board_info.c
extern const int board_cfg_size;			//= nor_board_rsvd_base - nor_board_cfg_base;

//defined in flash_ply_rdy.c
extern const int plyrdy_cpu_id_size;		//= 4 Bytes
extern const int plyrdy_cpu_serial_size;	//= 8 Bytes
extern const int plyrdy_modal_key_size;		//= 1024 Bytes
extern const int plyrdy_total_size;			//= 3072 Bytes = 3 KB!!!

//defined in flash_aacs.c
extern const int aacs_cpu_id_size;			//= 4;
extern const int aacs_cpu_serial_size;		//= 8;
extern const int aacs_host_cert_size;		//= 92;
extern const int aacs_key_blob_size;		//= 9632;

//defined in flash_sec_fw.c
extern const int sec_fw_size;				//= 81920;

//defined in flash_nic.c
extern const int nic_mac_size; 				// nand_nic_config_base - nand_nic_mac_base
extern const int nic_cfg_size; 				// nand_nic_rsvd_base - nand_nic_mac_base

//defined in flash_ctv.c
extern const int ctv_length_size;			// 4 Bytes
extern const int ctv_list_size;				// 4 KBytes - 4 Bytes or 4092

//defined in flash_kc.c
extern const int kc_cpu_id_size;			// 4 Bytes
extern const int kc_cpu_serial_size;		// 8 Bytes
extern const int kc_header_t_size;			// 16 Bytes
extern const int kc_info_header_size;		// 16 Bytes
extern const int kc_data_size;				// Maximum 32KB
extern const int kc_display_size;			// Maximum 1KB

#ifdef __cplusplus
# if 0
{  /*  hack to make things less confusing for some editors  */
# endif
}
#endif

#endif  /*  ndef FLASH_APPDATA_MEMMAP_INCLUDED  */

