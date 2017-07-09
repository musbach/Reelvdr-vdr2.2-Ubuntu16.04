/* "Copyright (c) 2010 Intel Corporation 
DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
This Distributable As Sample Source Software is subject to the
terms and conditions of the Intel Software License Agreement for
the Intel(R) Media Processor Software Development Kit" */

//Basic data type definition
typedef unsigned char                byte;
typedef unsigned short int           uint16;      /* 16-bit (always) */
typedef unsigned long int            uint32;      /* 32-bit (always) */
typedef unsigned long long int       uint64;      /* 64-bit (always) */

typedef uint16 PAGENUMTYPE;
typedef uint16 PAGESIZETYPE;
typedef uint32 BLOCKSIZETYPE;
typedef uint32 BLOCKNODE;

#define ADDRESSTYPE uint64


//IOCTL raw access commond type
typedef struct _spectra_io_cmd_tag
{
    uint32 	NumPagesToTransfer; // Number of Pages to transfer 
    ADDRESSTYPE 	AddrInRam;    // Source Address for Image in SRAM
    BLOCKNODE 		StartBlockNum; // Image Destination Block number
    PAGENUMTYPE 	StartPageNum;  // Image Destination start Page
}SPEC_IO_CMD;

typedef struct _boot_block_table_io_cmd_tag
{
	byte	btEntrySizeInBits;	//default to be 0x8, means each block status is represented by 8 bits
	uint16	btEntryNum;			//Block table entry number, equal to block number in boot partition
    ADDRESSTYPE	AddrInRam;		// Source address in IDTS
}BOOT_BLOCKTABLE_IO_CMD;

//IOCTL command set
#define GLOB_SBD_IOCTL_RD_MAIN      (0x8810)
#define GLOB_SBD_IOCTL_WR_MAIN      (0x8811)
#define GLOB_SBD_IOCTL_ERASE      (0x8812)
#define GLOB_SBD_IOCTL_RD_ID      (0x8813)
#define GLOB_SBD_IOCTL_CHK_BADBLK      (0x8814)
#define GLOB_SBD_IOCTL_RD_MAIN_SPARE_RAW	(0x8815)
#define GLOB_SBD_IOCTL_WR_MAIN_SPARE_RAW	(0x8816)

#define GLOB_SBD_IOCTL_ERASE_RAW			(0x9910)
#define GLOB_SBD_IOCTL_RD_BT				(0x9911)
#define GLOB_SBD_IOCTL_CREATE_BT_DUMMY		(0x9912)
#define GLOB_SBD_IOCTL_CREATE_BT_byERASE	(0x9913)
#define GLOB_SBD_IOCTL_CREATE_BT_bYMARKER	(0x9914)
#define GLOB_SBD_IOCTL_ERASE_byMARKER		(0x9915)


//Return value of Get Bad block
#define GOOD_BLOCK 0
#define DEFECTIVE_BLOCK 1
#define READ_ERROR 2


#define GLOB_SBD_IOCTL_GC          (0x7701)
#define GLOB_SBD_IOCTL_WL          (0x7702)
#define GLOB_SBD_IOCTL_FORMAT      (0x7703)
#define GLOB_SBD_IOCTL_FLUSH_CACHE (0x7704)

#if 0
typedef struct device_info_tag
{
    uint16        wDeviceMaker;   
    uint32        wDeviceType;    
    BLOCKNODE     wSpectraStartBlock;
    BLOCKNODE     wSpectraEndBlock;
    BLOCKNODE     wBlockNum;      
    BLOCKNODE     wTotalBlocks;   
    PAGENUMTYPE   wPagesPerBlock; 
    PAGESIZETYPE  wPageSize;      
    PAGESIZETYPE  wPageDataSize;  
    PAGESIZETYPE  wPageSpareSize; 
    uint16        wNumPageSpareFlag; 
    uint16        wECCBytesPerSector; 
    BLOCKSIZETYPE wBlockSize;     
    BLOCKSIZETYPE wBlockDataSize; 
    BLOCKNODE     wDataBlockNum;  
    byte          bPlaneNum;      
    uint16        wDeviceMainAreaSize; 
    uint16        wDeviceSpareAreaSize;    
    uint16        wDevicesConnected;       
    uint16        wDeviceWidth;     
    uint16        wHWRevision;
    uint16        wHWFeatures;      

    uint16        wONFIDevFeatures;
    uint16        wONFIOptCommands;
    uint16        wONFITimingMode;
    uint16        wONFIPgmCacheTimingMode;

    uint16 	  MLCDevice;
    uint16        wSpareSkipBytes;
    
}DEVICE_INFO;
#else
typedef struct device_info_tag
{
    uint16        wDeviceMaker;   
    uint32        wDeviceType;    
    BLOCKNODE     wSpectraStartBlock;
    BLOCKNODE     wSpectraEndBlock;
    BLOCKNODE     wTotalBlocks;   
    PAGENUMTYPE   wPagesPerBlock; 
    PAGESIZETYPE  wPageSize;      
    PAGESIZETYPE  wPageDataSize;  
    PAGESIZETYPE  wPageSpareSize; 
    uint16        wNumPageSpareFlag; 
    uint16        wECCBytesPerSector; 
    BLOCKSIZETYPE wBlockSize;     
    BLOCKSIZETYPE wBlockDataSize; 
    BLOCKNODE     wDataBlockNum;  
    byte          bPlaneNum;      
    PAGESIZETYPE  wDeviceMainAreaSize; 
    PAGESIZETYPE  wDeviceSpareAreaSize;    
    uint16        wDevicesConnected;       
    uint16        wDeviceWidth;     
    uint16        wHWRevision;
    uint16        wHWFeatures;      

    uint16        wONFIDevFeatures;
    uint16        wONFIOptCommands;
    uint16        wONFITimingMode;
    uint16        wONFIPgmCacheTimingMode;

    uint16        MLCDevice;
    uint16        wSpareSkipBytes;    
    byte          nBitsInPageNumber;      
    byte          nBitsInPageDataSize;    
    byte          nBitsInBlockDataSize;    
}DEVICE_INFO;
#endif

