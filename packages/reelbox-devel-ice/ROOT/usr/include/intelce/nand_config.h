/* "Copyright (c) 2010 Intel Corporation 
DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
This Distributable As Sample Source Software is subject to the
terms and conditions of the Intel Software License Agreement for
the Intel(R) Media Processor Software Development Kit" */

#ifndef _NAND_CONFIG_H_
#define _NAND_CONFIG_H_

#include <sys/types.h>
#include "spectra_raw.h"

typedef enum
{
	NAND_OK = 0,
	NAND_ERR,
	NAND_NOIMPL,
	//The following 3 are for function NAND_Get_Bad_Block
	NAND_GOOD_BLOCK,
	NAND_DEFECTIVE_BLOCK,
	NAND_READ_ERROR,
	NAND_DONE_WITHERR,
	NAND_BTEXIST
	
} NAND_STATUS;

typedef enum
{
	EMMC_OK = 0,
	EMMC_ERR,
	EMMC_NOIMPL,
} EMMC_STATUS;

extern unsigned int failblklimit;
/*
typedef struct nand_device_info_tag
{
    unsigned short        wDeviceMaker;   
    unsigned int          wDeviceType;    
    unsigned short        wSpectraStartBlock;
    unsigned short        wSpectraEndBlock;
    unsigned short        wBlockNum;      
    unsigned short        wTotalBlocks;   
    unsigned short        wPagesPerBlock; 
    unsigned short        wPageSize;      
    unsigned short        wPageDataSize;  
    unsigned short        wPageSpareSize; 
    unsigned short        wNumPageSpareFlag; 
    unsigned short        wECCBytesPerSector; 
    unsigned int          wBlockSize;     
    unsigned int          wBlockDataSize; 
    unsigned short        wDataBlockNum;  
    unsigned char         bPlaneNum;      
    unsigned short        wDeviceMainAreaSize; 
    unsigned short        wDeviceSpareAreaSize;    
    unsigned short        wDevicesConnected;       
    unsigned short        wDeviceWidth;     
    unsigned short        wHWRevision;
    unsigned short        wHWFeatures;      

    unsigned short        wONFIDevFeatures;
    unsigned short        wONFIOptCommands;
    unsigned short        wONFITimingMode;
    unsigned short        wONFIPgmCacheTimingMode;

    unsigned short        MLCDevice;
    unsigned short        wSpareSkipBytes;
    
}NAND_DEVICE_INFO;
*/
typedef struct _NAND_HANDLE
{
	int				fd;
	DEVICE_INFO		*pNAND_DeviceInfo;
}NAND_HANDLE;

typedef struct _EMMC_HANDLE
{
	int				fd;
	unsigned int	st_usrpartblks;
	unsigned int	st_bootpartblks;
	unsigned int    st_gppartblks[4];
	unsigned int	booten;
}EMMC_HANDLE;

/*!  \brief Initialize nand driver
 *
 *     Opens a handle to nand_config.ko driver. Initializes flash controller. 
 *
 *     @param[out] handle                        handle
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_open(NAND_HANDLE *handle);

/*!  \brief Read nand memory with page granularity
 *
 *     This does a naked read. This may fail because of ECC checks. The reason this can happen is a page was doubly written, 
 *      and had not been correctly erase-written. Also could be because of bad blocks.
 *
 *     @param[in] handle                                handle
 *     @param[out] dst                                  pointer to a buffer to place read data
 *     @param[in] length                                size of buffer in bytes.. Must be wPageDataSize granularity (use nand_get_info to find wPageDataSize)
 *     @param[in] block                                  physical block index
 *     @param[in] pagestart                           page to start reading. cannot exceed wPagesPerBlock
 *     @param[in] pagecount                           number of pages to read. pagecount + pagestart cannot exceed wPagesPerBlock
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_read_page(NAND_HANDLE handle, void* dst, unsigned int length, unsigned int block, unsigned int pagestart, unsigned int pagecount);

/*!  \brief Write nand memory with page granularity
 *
 *     This does a naked write. This may fail because of ECC checks. The reason this can happen is a page was doubly written, 
 *      and had not been correctly erase-written. Also could be because of bad blocks.
 *
 *     @param[in] handle                                 handle
 *     @param[in] src                                     pointer to a buffer for data to write
 *     @param[in] length                                 size of buffer in bytes.. Must be wPageDataSize granularity (use nand_get_info to find wPageDataSize)
 *     @param[in] block                                  physical block index
 *     @param[in] pagestart                            page to start writing. cannot exceed wPagesPerBlock
 *     @param[in] pagecount                            number of pages to write. pagecount + pagestart cannot exceed wPagesPerBlock
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_write_page(NAND_HANDLE handle, void* src, unsigned int length, unsigned int block, unsigned int pagestart, unsigned int pagecount);

/*!  \brief Read nand memory with byte granularity
 *
 *     This does a naked read. This may fail because of ECC checks. The reason this can happen is a page was doubly written, 
 *     and had not been correctly erase-written. Also could be because of bad blocks.
 *
 *     This function can take any size buffer and read it. It uses nand_read_page to read. If a page read on one block fails, nand_read
 *     will attempt to read blockcount other consecutive blocks until it finds a valid page.
 *
 *     @param[in] handle                                handle
 *     @param[out] dst                                  pointer to a buffer to place read data
 *     @param[in] length                                size of buffer in bytes. offset + length cannot exceed wPagesPerBlock * wPageDataSize
 *     @param[in] blockstart                          physical block index
 *     @param[in] blockcount                          number of consecutive blocks to try reading if first block fails
 *     @param[in] offset                                block offset(address) in bytes. offset + length cannot exceed wPagesPerBlock * wPageDataSize
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_read(NAND_HANDLE handle, void* dst, unsigned int length, unsigned int blockstart, unsigned int blockcount, unsigned int offset);

/*!  \brief Write nand memory with byte granularity
 *
 *     This function does an erase-write sequence on each block. It saves all valid pages on the block, does an erase, then rewrites
 *     all pages with changes from the src buffer added. It should never fail because of ECC checks.
 *
 *     This function can take any size buffer. It uses nand_read to read. If a page read on one block fails, nand_read
 *     will attempt to read blockcount other consecutive blocks until it finds a valid page.
 *
 *     @param[in] handle                                handle
 *     @param[in] src                                    pointer to a buffer to write data from.
 *     @param[in] length                                size of buffer in bytes. offset + length cannot exceed wPagesPerBlock * wPageDataSize
 *     @param[in] blockstart                          physical block index
 *     @param[in] blockcount                          number of consecutive blocks to write with same data. Also number of consecutive blocks
 *                                                              to read if initial block read fails.
 *     @param[in] offset                                block offset(address) in bytes. offset + length cannot exceed wPagesPerBlock * wPageDataSize
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_write(NAND_HANDLE handle, void* src, unsigned int length, unsigned int blockstart, unsigned int blockcount, unsigned int offset);

/*!  \brief Retrieve information about the nand flash chip.
 *
 *     This fills in the NAND_DEVICE_INFO struct.
 *
 *     @param[in] handle                                handle
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_getinfo(NAND_HANDLE handle);

/*!  \brief Erase a block of NAND flash
 *
 *     This does an erase on a block. Erase can only be done on block granularity. nand_config (FTL-Lite)
 *     does not do any block management, so it must be done using nand_erase. 
 *
 *     @param[in] handle                                handle
 *     @param[in] block                                 block to erase
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_erase(NAND_HANDLE handle, unsigned int block);

/*!  \brief Erase a block of NAND flash base on the block table
 *
 *     This does an erase on a block. Erase can only be done on block granularity. It will check block table
 *     for bad block info before perform the erase operation. 
 *
 *     @param[in] handle                                handle
 *     @param[in] block                                 block to erase
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_erase_bybt(NAND_HANDLE handle, unsigned int block);

/*!  \brief Erase a block of NAND flash base on the bad block mark in the spare area
 *
 *     This does an erase on a block. Erase can only be done on block granularity. It will check bad block mark
  *    in spare area for bad block info before perform the erase operation. 
 *
 *     @param[in] handle                                handle
 *     @param[in] block                                 block to erase
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_erase_bybbmark(NAND_HANDLE handle, unsigned int block);

/*!  \brief Closes nand driver
 *
 *     Releases handle to nand_config.ko. Unitializes driver.
 *
 *     @param[in] handle                                handle
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_close(NAND_HANDLE handle);


/*!  \brief Check whether the block is a bad block or not.
 *
 *     Check bad block by the flag in spare area.
 *
 *     @param[in] handle                                handle
 *     @param[in] blockno                              block to check
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_check_badblock(NAND_HANDLE handle, unsigned int blockno);

/*!  \brief Read nand memory with page granularity, including ecc.
 *
 *     This does a naked read. This may fail because of ECC checks. The reason this can happen is a page was doubly written, 
 *      and had not been correctly erase-written. Also could be because of bad blocks.
 *
 *     @param[in] handle                                handle
 *     @param[out] dst                                  pointer to a buffer to place read data
 *     @param[in] block                                  physical block index
 *     @param[in] pagestart                            page index to start reading.
 *     @param[in] pagecount                           number of pages to read. pagecount + pagestart cannot exceed wPagesPerBlock
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_read_page_mainspare(NAND_HANDLE handle, void* dst, unsigned int block, unsigned int pagestart, unsigned int pagecount);

/*!  \brief Read raw data from nand flash with page granularity, including ecc.
 *
 *     This does a naked read. This may fail because of ECC checks. The reason this can happen is a page was doubly written, 
 *      and had not been correctly erase-written. Also could be because of bad blocks.
 *
 *     @param[in] handle                                handle
 *     @param[out] dst                                  pointer to a buffer to place read data
 *     @param[in] block                                  physical block index
 *     @param[in] pagestart                            page index to start reading.
 *     @param[in] pagecount                           number of pages to read. pagecount + pagestart cannot exceed wPagesPerBlock
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_read_page_mainspare_raw(NAND_HANDLE handle, void* dst, unsigned int block, unsigned int pagestart, unsigned int pagecount);
int GenDenaliECC8bit(const unsigned char *inbuf, unsigned char *outbuf);

/*!  \brief Read out the content of block table.
 *
 *     Read block table from NAND by calling Linux driver.
 *
 *     @param[in] handle                                handle
 *     @param[out] dst                                  pointer to a buffer to place read data
 *     @param[out] length                              size of dst buffer.
 *     @return  NAND_STATUS
 */
NAND_STATUS nand_readbt(NAND_HANDLE handle, void *dst, unsigned int *plength);
NAND_STATUS nand_createdummybt(NAND_HANDLE handle, int arg);
NAND_STATUS nand_createbtbyerase(NAND_HANDLE handle);
NAND_STATUS nand_createbtbybbmark(NAND_HANDLE handle);
EMMC_STATUS emmc_open(EMMC_HANDLE *pHandle);
EMMC_STATUS emmc_close(EMMC_HANDLE handle);
EMMC_STATUS emmc_read(EMMC_HANDLE handle, void *buf, off_t offset, unsigned int length);
EMMC_STATUS emmc_write(EMMC_HANDLE handle, void *buf, off_t offset, unsigned int length);
EMMC_STATUS emmc_readbp(EMMC_HANDLE handle, unsigned int whichbootpart, void *buf, off_t offset, unsigned int length);
EMMC_STATUS emmc_writebp(EMMC_HANDLE handle, unsigned int whichbootpart, void *buf, off_t offset, unsigned int length);
EMMC_STATUS emmc_getstat(EMMC_HANDLE *pemmc_handle);
EMMC_STATUS emmc_io_bp(EMMC_HANDLE handle, unsigned char bwrrd, unsigned int whichbootpart, void *buf, off_t offset, unsigned int length);

#endif
