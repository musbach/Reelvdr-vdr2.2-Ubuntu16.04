/*
#
#  BSD LICENSE
#
#  Copyright(c) 2011 Intel Corporation. All rights reserved.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the name of Intel Corporation nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*/

/*------------------------------------------------------------------------------
 * File Name: exp_bus.h
 *------------------------------------------------------------------------------
 */

#ifndef _EXP_BUS_H_
#define _EXP_BUS_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef LINUX_DRIVER
#include <stdint.h>
#include <stdbool.h>
#else
#include <linux/types.h>
#endif

#include <linux/ioctl.h>
//! \file
/** Ioctl routines */
/** @defgroup expbus_ Narrow Expansion Bus API */
/** @ingroup expbus_ */
/*@{*/
#define EXPBUS_MAGIC				0x61167851

//Set /Get Mode Control Register
#define EXP_BUS_IOC_SET_MC_CONF		0x1000
#define EXP_BUS_IOC_GET_MC_CONF 		0x1001

//Set / Get Chip Select and Timming Register
#define EXP_BUS_IOC_SET_CT_CONF 		0x1002
#define EXP_BUS_IOC_GET_CT_CONF 		0x1003

#define MAX_CS_NUM 	4
#define MAX_CS_AREA	(64*1024*1024) //64MB

typedef enum {
	EXP_SUCCESS	            = 0, /**< The field indicates that the function operated successfully. */ 
	EXP_INVALID_PARAM        , /**< The field indicates the function was given an invalid parameter. */
	EXP_NOT_INITIALIZED      , /**< The field indicates that the driver is not initialized. */
	EXP_ALREADY_INITIALIZED  , /**< The field indicates that the driver is already initialized. */
	EXP_NO_DEV       		 , /**< The field indicates that there is no device. */
	EXP_NOT_IMPLEMENTED 	 , /**<The field indicates the required function is not implemented. */
	EXP_DEVICE_BUSY  		 , /**< The field indicates that the hardware is busy. */
	EXP_MAP_FAIL  		 	, /**< The field indicates that the memory map operation fails. */
	EXP_MUNMAP_FAIL  		 , /**< The field indicates that the memory unmap operation fails. */	
	EXP_NOT_MAPPED	 	, /**< The field indicates that the region memory didn¡¯t map yet. */
	EXP_NO_MEM 			, /**< The field indicates that no memory available. */
	EXP_IOCTL_ERROR   		 , /**< 0xB The field indicates ioctl operation fails.*/	
	EXP_TIMED_OUT   		 , /**< 0xC The field indicates time out.*/
	EXP_FIRST_ERROR          = EXP_INVALID_PARAM, /**< The field is currently equal to an invalid parameter.*/
	EXP_LAST_ERROR           = EXP_TIMED_OUT /**< The field is currently equal to time out.*/
} exp_result_t;


/** Mode control Register defaul value is 0x30007FFF */
struct mode_ctrl_reg {
	uint32_t EXP_REV_0 : 2;				/**< [31:30] reserved                            */
	uint32_t EXP_CLK_DIV : 2 ;		/**< [29:28] clock divider                       */
	uint32_t EXP_REV_1 : 13;			/**< [27:15] reserved                            */
	uint32_t EXP_CLK : 1 ;				/**< [14] exp clk out enable                     */
	uint32_t EXP_ALE3 : 1 ;				/**< [13] Address Latch Enable 3 output enable   */
	uint32_t EXP_ALE2 : 1 ;				/**< [12] Address Latch Enable 2 output enable   */
	uint32_t EXP_ALE1 : 1 ;				/**< [11] Address Latch Enable 1 output enable   */
	uint32_t EXP_ALE0 : 1 ;				/**< [10] Address Latch Enable 0 output enable   */
	uint32_t EXP_DIOEA : 1 ;			/**< [9] Read Latch Enable 1 output enable       */
	uint32_t EXP_DIOEB : 1 ;			/**< [8] Read Latch Enable 2 output enable       */
	uint32_t EXP_RD : 1 ;					/**< Memory Read Strobe output enable            */
	uint32_t EXP_WR : 1 ;					/**< [6] Memory Write Strobe output enable       */
	uint32_t EXP_IORD : 1 ;				/**< I/O Read Strobe output enable               */
	uint32_t EXP_IOWR : 1 ;				/**< I/O Write Strobe output enable              */
	uint32_t EXP_DOLEA : 1 ;			/**< Write Latch Enable output enable            */
	uint32_t EXP_DOOE : 1 ;				/**< Data Output Output enable                   */
	uint32_t EXP_IO_7_0 : 1 ;			/**< Input/Output Bus output enable              */
	uint32_t EXP_OUT_EN : 1 ;			/**< All output enables                          */
};	

/** CS0-3 Timming Register defaul value is 0x3FF79CF5 */
struct mode_cs_timing {
	uint32_t CSx_En : 1 ;				/**< [31] chip select enable/disable */
	uint32_t IOSPACE : 1 ;	 			/**< [30] IOWR/IORD cycles are enable/disable */
	uint32_t Num_ALEs : 2 ;				/**< [29:28] Number of Address Latch Eanbles 	*/
	uint32_t ALEPh1Tim : 2 ;			/**< [27:26] Address Latch Enable Phase 1 timing */
	uint32_t ALEPh2Tim : 2 ;			/**< [25:24] Address Latch Enable Phase 2 timing */
	uint32_t ALEPh3Tim : 2 ;			/**< [23:22] Address Latch Enable Phase 3 timing */
	uint32_t ALEPh4Tim : 2 ;			/**< [21:20] Address Latch Enable Phase 4 timing */
	uint32_t Increase_Tsu : 1 ;			/**< [19] Increase Tsu*/
	uint32_t RdDatPh1 : 2 ;				/**< [18:17] Read Data Phase 1 timing control*/
	uint32_t RdDatPh2 : 2 ;				/**< [16:15] Read Data Phase 2 timing control*/
	uint32_t resev1 : 2 ;				/**< [14:13] reserved */
	uint32_t StbTim_AtoD : 2 ;			/**< [12:11] Write Strobe Timing - Address to Data 1 to 4 clocks */
	uint32_t DoStbTim_OtoDA : 2 ;			/**< [10:9] Data Out Timing Output to Data Available 1 to 4 clocks*/
	uint32_t Nor_boot_strap : 1 ;			/**< [8] Nor Boot (CS0 Only, CS1-3 Reserved)*/
	uint32_t WrDatPh1 : 2 ;				/**< [7:6] Write Data Phase 1 timing control */
	uint32_t WrDatPh2 : 2 ;				/**< [5:4] Write Data Phase 2 timing control */
	uint32_t SPLT_EN : 1 ;				/**< [3] AHB Split transfers enable/disabled. Not support split in HW. Always 0 */
	uint32_t LAT_PLS_EXT : 1 ;			/**< [2] Latch Pulse Extension */
	uint32_t WR_EN : 1 ;				/**< [1] Writes to CS region are enabled/disabled */
	uint32_t BYTE_EN : 1 ;				/**< [0] Access 8/16 bit wide data bus on attached boot device. */
};	

/**    
* This function is to initialize the NEXP bus chip select [cs_num].
* 
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4)
* 
* @retval EXP_SUCCESS if chip select [cs_num] is availabe.
* @retval EXP_INVALID_PARAM if provided parameters are invalid.
* @retval EXP_DEVICE_BUSY if chip select [cs_num] is used by other users.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NO_MEM if NEXP bus allocates memory fails.
*/ 
exp_result_t exp_bus_open(uint32_t cs_num);

/**
* This function releases the NEXP bus interface. Call this function when you are through using chip select [cs_num].
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* 
* @retval EXP_SUCCESS if chip select [cs_num] is availabe.
* @retval EXP_INVALID_PARAM if provided parameters are invalid.
* @retval EXP_MUNMAP_FAIL if chip select [cs_num] memory region is unmapped fail.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] region is not initialized by exp_bus_open.
*/
exp_result_t exp_bus_close(uint32_t cs_num);

/**
* This function is to map the chip select [cs_num] region.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] offset - memory offset for chip select [cs_num]. Offset must be a multiple of the page size as offset in mmap() system call.
* @param[in] length - Specify the length of the mapping. (0< length <= 64MB)
* 
* @retval EXP_SUCCESS if chip select [cs_num] is maped successfully.
* @retval EXP_INVALID_PARAM if provided parameters are invalid.
* @retval EXP_MUNMAP_FAIL if chip select [cs_num] was mapped by previous mapping operations and is still busy.
* @retval EXP_MAP_FAIL if chip select [cs_num] was mapped fail.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_MAPPED if chip select [cs_num] region was not mapped by exp_bus_map.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] region is not initialized by exp_bus_open.
*/

exp_result_t exp_bus_map(uint32_t cs_num, uint32_t offset, uint32_t length);

/**
* This function is to unmap the chip select [cs_num] region.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* 
* @retval EXP_SUCCESS if chip select [cs_num] is maped successfully.
* @retval EXP_INVALID_PARAM if provided parameters are invalid.
* @retval EXP_MUNMAP_FAIL if chip select [cs_num] was mapped by previous mapping operation and is busy.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] memory region is not initialized by exp_bus_open.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_MAPPED if chip select [cs_num] region was not mapped by exp_bus_map.
*/ 
exp_result_t exp_bus_unmap(uint32_t cs_num);

/** 
* This function is to read data from chip select [cs_num] region. NOTE: The sum of offset and length in this function must be not larger than the memory length mapped by exp_bus_map.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] buf - Memory buf provided by user to keep the data read from chip select region.
* @param[in] offset - Memory offset is for the region which was mapped by exp_bus_map. This offset is NOT for chip select start address.
* @param[in] length - Specifies the length of reading. 
* 
* @retval EXP_SUCCESS if read operation on chip select [cs_num] successfully.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] memory region is not initialized by exp_bus_open.
* @retval EXP_INVALID_PARAM if provided parameters are invalid.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_MAPPED if chip select [cs_num] region was not mapped by exp_bus_map.
*/
exp_result_t exp_bus_read(uint32_t cs_num, char * buf, uint32_t offset, uint32_t length);

/**
* This function is to write data to chip select [cs_num] region. NOTE: The sum of offset and length in this function must be not larger than the memory length mapped by exp_bus_map.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] buf - Memory buf provided by user to keep the data write to chip select region.
* @param[in] offset - Memory offset is for the region which was mapped by exp_bus_map. This offset is NOT for chip select start address.
* @param[in] length - Specifies the length of writting. 
* 
* @retval EXP_SUCCESS if write operation on chip select [cs_num] successfully.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] memory region is not initialized by exp_bus_open.
* @retval EXP_INVALID_PARAM if provided parameters are invalid.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_MAPPED if chip select [cs_num] region was not mapped by exp_bus_map.
*/
exp_result_t exp_bus_write(uint32_t cs_num, char * buf, uint32_t offset, uint32_t length);

/**
* This function is to read the mode control register that is present by mode_ctrl_reg stucture.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] config - the memory buf provided by user to keep the data read from mode control register.
* 
* @retval EXP_SUCCESS if write operation on chip select [cs_num] successfully.
* @retval EXP_INVALID_PARAM if provide parameters are invalid.
* @retval EXP_IOCTL_ERROR if the ioctl operation fails.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] region is not initialized by exp_bus_open.
*/
exp_result_t exp_bus_get_mode_cotrl_config(uint32_t cs_num, struct mode_ctrl_reg * config);

/**
* This function is to write the mode control register that is present by mode_ctrl_reg stucture.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] config - the memory buf provided by user to keep the data read from mode control register.
* 
* @retval EXP_SUCCESS if write operation on chip select [cs_num] successfully.
* @retval EXP_INVALID_PARAM if provide parameters are invalid.
* @retval EXP_IOCTL_ERROR if the ioctl operation fails.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] region is not initialized by exp_bus_open.
*/
exp_result_t exp_bus_set_mode_cotrl_config(uint32_t cs_num, struct mode_ctrl_reg * config);
/**
* This function is to read the CS0-3 timming and control registers which are present by mode_cs_timming stucture.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] config - the memory buf provided by user to keep the data read from mode control register.
* 
* @retval EXP_SUCCESS if read operation on chip select [cs_num] successfully.
* @retval EXP_INVALID_PARAM if provide parameters are invalid.
* @retval EXP_IOCTL_ERROR if the ioctl operation fails.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] region is not initialized by exp_bus_open.
*/
exp_result_t exp_bus_get_cs_timming_config(uint32_t cs_num, struct mode_cs_timing * config);

/**
* This function is to write the CS0-3 timming and control registers which are present by mode_cs_timming stucture.
* @param[in] cs_num - the index of chip select. (0<= cs_num < 4).
* @param[in] config - the memory buf provided by user to keep the data read from mode control register.
* 
* @retval EXP_SUCCESS if read operation on chip select [cs_num] successfully.
* @retval EXP_INVALID_PARAM if provide parameters are invalid.
* @retval EXP_IOCTL_ERROR if the ioctl operation fails.
* @retval EXP_NO_DEV if device does not exist that mainly causes by driver does not insmod.
* @retval EXP_NOT_INITIALIZED if chip select [cs_num] region is not initialized by exp_bus_open.
*/
exp_result_t exp_bus_set_cs_timming_config(uint32_t cs_num, struct mode_cs_timing * config);


#ifdef __cplusplus
}
#endif
/*@}*/
#endif  //_EXP_BUS_H_

