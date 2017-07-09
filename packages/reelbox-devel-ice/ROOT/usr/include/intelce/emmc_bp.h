/* "Copyright (c) 2010 Intel Corporation 
DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
This Distributable As Sample Source Software is subject to the
terms and conditions of the Intel Software License Agreement for
the Intel(R) Media Processor Software Development Kit" */


#ifndef MMC_BP_H
#define MMC_BP_H


#define BP_DIR_READ	0x0	/* Read */
#define BP_DIR_WRITE	0x1	/* Write */


#define MMC_BLK_IOCTL_BP_GETINFO	0x8820	/* Get boot partition info */
#define MMC_BLK_IOCTL_BP_RDWR		0x8821	/* Read/write boot partition */
#define MMC_BLK_IOCTL_GP_GETINFO	0x8822	/* Get general purpose partition info */
#define MMC_BLK_IOCTL_GP_RDWR		0x8823	/* Read/write general purpose partition */


#define MMC_BP_UNIT_SIZE		(128 * 1024) /*Boot partition is an integer multiple of 128 kB in size */
#define MMC_SECTOR_SIZE			512	/*A sector size is 512Byte*/
#define MAX_NUM_OF_SECTORS_TRANSFERD	128	/*Only 128 sectors can be transfered at one time*/
#define MAX_NUM_OF_BOOT_PARTITIONS	1	/*Only 2 boot partitions are supported, partition 0 & partition 1*/

#define MMC_BOOT_EN_USER	0
#define MMC_BOOT_EN_BP0		1	
#define MMC_BOOT_EN_BP1		2	
#define MMC_BOOT_EN_NONE	3	
#define MMC_BOOT_EN_RESV	4	

struct mmc_bp_info {
	unsigned long  sectors;
	unsigned long  booten;
};

struct mmc_gp_info {
	unsigned long  sectors[4];
};


struct mmc_bp_rw {
	unsigned char  which;
	unsigned char  dir;
	void           *buf;
	unsigned long  st_sector;
	unsigned long  nr_sectors; /* max 128 */
};

#endif
