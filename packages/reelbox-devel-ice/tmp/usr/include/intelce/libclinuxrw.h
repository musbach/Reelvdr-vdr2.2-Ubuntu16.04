/****************************************************************************
 * Copyright (c) 2008-2009 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: libclinuxrw.h
 ***************************************************************************/
#ifndef __LIB_CLINUXRW_H__
#define __LIB_CLINUXRW_H__

#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <endian.h>
#include <termios.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#define	stricmp	strcasecmp
#include <sys/types.h>
#include <scsi/sg.h>
#include "tdef.h"
#define	WR_PATTERN_SIZE	4


class CLinuxRW
{
public:
	CLinuxRW(void);
	virtual ~CLinuxRW(void);

	//Return number of KBytes free on mount point
	int PrepareFS(char * szDeviceName);
	int CloseFS(void);

	int GetMountPath(char * mountPath, int nMountPathSize);

	int WriteRandom(UINT FileSizeKb, int Loops);
	int WriteStress(UINT WRPattern, UINT FileSizeKb, int Loops);
	int ReadStress(UINT WRPattern, UINT FileSizeKb, int Loops);
	int WRC(UINT WRPattern, UINT FileSize, int Loops);
	int WRCRandom(UINT FileSizeKb, int Loops);

	//Determine why the last call failed
	char* GetLastErrorStr(void);

protected:
	BOOL WriteBufferToFile(UCHAR* pBuffer, UINT nBuffSize, UINT loops);
	char szLastError[256];
	char szFilename[256];
private:
	int WRCBuffer(UCHAR* buffer, UINT nBuffSize, UINT FileSizeKb, int Loops);

	int CheckMountedRW();
	int CheckFirstDeviceStatus(const char* devName);
	int CheckNextDeviceStatus(const char* devName);
	int CheckDeviceStatus(const char* devName, BOOL bFirstDev);
	int FindFirstPartForDev(char * szDevName, char * szPartName, int nPartNameSize);
	int FindNextPartForDev(char * szDevName, char * szPartName, int nPartNameSize);
	int FindPartForDev(char * szDevName, char * szPartName, int nPartNameSize, BOOL bFirst);

	int MapToDevice(char* szDeviceBuf);

	int fTempFile;
	char szMountPath[64];
	UINT nKBytesFree;
	char szDevicePath[64];
	char szMountType[64];
	BOOL bReady;
	BOOL bMountedReadOnly;
	BOOL bCreatedMountPath;
	BOOL bUnmountDevice;
	BOOL bCleanedUp;
	UCHAR* pReadBuf;
	const UINT nWR_BUFF_SIZE;
};

#endif
