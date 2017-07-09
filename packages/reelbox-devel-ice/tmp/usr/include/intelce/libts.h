/****************************************************************************
 * Copyright (c) 2008-2011 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************
 * File Name: libts.h
 ***************************************************************************/

#ifndef _TSLIB_H_
#define _TSLIB_H_

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <stdio.h>

	#define strnicmp _strnicmp

	#if defined(TESTDLL)
		#define DLLEXPORT __declspec(dllexport)
	#else  
		#define DLLEXPORT __declspec(dllimport)
	#endif
#elif defined linux
	
	#define DLLEXPORT 
	#define stricmp strcasecmp

#endif
#include "tdef.h"

//#define LIBVER_STRING "version_number=1.06.1.0011 "

#define MAX_TSMSG_SIZE	4064

//Macro to determine command to run
#ifdef linux
#define IS_CMD(szTestName, szCmd)	(0 == stricmp(szTestName, szCmd))
#elif defined _WIN32
#define IS_CMD(szTestName, szCmd)	(0 == _stricmp(szTestName, szCmd))
#endif

#define AUTO_CONFIG_CMD		"0"

typedef struct sTSINFO
{
	UINT32	nLength;
	UINT32	nModuleNumber;
	UINT32	nTestNumber;
	LPCSTR	szVersion;
	LPCSTR	szModuleName;
} TSINFO, *PTSINFO;

//typedef struct sTSINFOEX
//{
//	UINT32	nLength;
//	UINT32	nModuleNumber;
//	CHAR	szTestName[128];
//	LPSTR	szVersion;
//	LPSTR	szModuleName;
//} TSINFOEX, *PTSINFOEX;

typedef struct sTSINFO2
{
	UINT32	nLength;
	UINT32	nModuleNumber;
	CHAR	szTestName[128];
	LPCSTR	szVersion;
	LPCSTR	szModuleName;
	// the preceeding memebers are exactly the same as the old TSINFOEX

	// the following is new stuff,
	UINT32	nTestNumber;
	LPCSTR*  aszTestNames;
	INT32   nCount;
} TSINFO2, *PTSINFO2;

typedef enum ePARAMTYPE
{
	P_INT8,
	P_UINT8,
	P_INT16,
	P_UINT16,
	P_INT32,
	P_UINT32,
	P_INT64,
	P_UINT64,
	P_STR,
	P_VOID
} PARAMTYPE,*PPARAMTYPE;

typedef void* TSEVENT, *PTSEVENT;

DLLEXPORT TSSTATUS tsInitialize    (TSINFO *pInfo,INTN argc,LPSTR argv[]);
DLLEXPORT TSSTATUS tsInitialize2   (TSINFO2 *pInfo,INTN argc,LPSTR argv[]);
DLLEXPORT TSSTATUS tsDelay         (UINT32 nMillisecs);
DLLEXPORT TSSTATUS tsSetCleanup    (VOID (*Cleanup)());

DLLEXPORT TSSTATUS tsState         (INTN state);
DLLEXPORT TSSTATUS tsProgress      (INTN progress);
DLLEXPORT TSSTATUS tsDone          ();
DLLEXPORT TSSTATUS tsClear         ();

DLLEXPORT TSSTATUS tsStatus        (LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsAdvisory      (LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsError         (UINT32 nErrorNumber,LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsInfo          (LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsVerbose       (UINT32 nVerboseMask,LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsStatistic     (LPCSTR key,LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsDisableSubtest(UINTN nTestCaseNumber, LPCSTR szReason);
DLLEXPORT TSSTATUS tsRemoveSubtest (UINTN nTestCaseNumber, LPCSTR szReason);
DLLEXPORT TSSTATUS tsRemoveDevice  (LPCSTR szReason);
DLLEXPORT TSSTATUS tsDisableSubtestEx (LPCSTR szTestCommandName, LPCSTR szReason);
DLLEXPORT TSSTATUS tsRemoveSubtestEx (LPCSTR szTestCommandName, LPCSTR szReason);
DLLEXPORT TSSTATUS tsCloneDevice   (LPCSTR szName, LPCSTR szReason);
DLLEXPORT TSSTATUS tsCopyGroup	   (LPCSTR pPath, LPCSTR pName, LPSTR pNewPath, INTN length, LPCSTR pReason);
DLLEXPORT TSSTATUS tsRemoveGroup   (LPCSTR pPath, LPCSTR pReason);
DLLEXPORT TSSTATUS tsGetDeviceName (LPSTR pDeviceName,UINTN szNameSize);
DLLEXPORT TSSTATUS tsGetCfgParam   (LPCSTR szLabel,LPCSTR szSwitch,LPVOID pParam,UINTN szParam,PARAMTYPE typeData);
DLLEXPORT TSSTATUS tsPutCfgParam   (LPCSTR szLabel,LPCVOID pParam,PARAMTYPE typeData);
DLLEXPORT TSSTATUS tsGetCfgArrayDim	(LPCSTR szLabel,LPCSTR szSwitch,PUINTN pXdim, PUINTN pYdim);
DLLEXPORT TSSTATUS tsGetCfgArray	(LPCSTR szLabel,LPCSTR szSwitch,UINTN x,UINTN y,LPVOID pParam,UINTN szParam,PARAMTYPE typeData);
DLLEXPORT TSSTATUS tsPutCfgArray	(LPCSTR szLabel,UINTN x,UINTN y,LPCVOID pParam,PARAMTYPE typeData);

DLLEXPORT TSSTATUS tsPrompt			(LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsPromptList		(PINTN pChoice,INTN count,LPCSTR* ppList,LPCSTR pPrompt);
DLLEXPORT TSSTATUS tsPromptString	(LPSTR pBuffer,INTN length,LPCSTR pPrompt,LPCSTR pCharSet);
DLLEXPORT TSSTATUS tsPromptConfirm	(PBOOL pYesNo,LPCSTR pPrompt);

DLLEXPORT TSSTATUS tsPromptAsync	(LPCSTR szFormat,...);
DLLEXPORT TSSTATUS tsClosePromptAsync();

DLLEXPORT TSSTATUS tsStringToValue	(LPSTR str,PUINT64 pValue,PARAMTYPE type);

DLLEXPORT TSSTATUS tsCreateEvent	(LPCSTR pName, TSEVENT* eventHandle);
DLLEXPORT TSSTATUS tsOpenEvent		(LPCSTR pName, TSEVENT* eventHandle);
DLLEXPORT TSSTATUS tsSetEvent		(TSEVENT eventHandle);
DLLEXPORT TSSTATUS tsWaitEvent		(TSEVENT eventHandle, ULONG* timeoutMs);
DLLEXPORT TSSTATUS tsCloseEvent		(TSEVENT eventHandle);

DLLEXPORT TSSTATUS tsPutRunTimeData	(LPCSTR pName, LPVOID data, INTN size);
DLLEXPORT TSSTATUS tsGetRunTimeData	(LPCSTR pName, LPVOID data, PINTN size);

DLLEXPORT TSSTATUS tsPutFile		(LPCSTR pFileName, LPCSTR pFilePath, LPCSTR pPathToStore);
DLLEXPORT TSSTATUS tsGetFile		(LPCSTR pFileName, LPCSTR pFilePath, LPCSTR pPathToStore);

#pragma deprecated(tsInitialize)
#pragma deprecated(tsInitializeEx)

//Calling ExitProcess from a DLL is not advisable (MSDN)
//Using this macro, tsDone is called, but ExitProcess is no longer called internally,
//It is called from the main application.

#if defined(_WIN32) &&  !defined(TESTDLL) 
//#define tsDone();	{ tsDone(); ExitProcess(0); } take this out for now since it causes some apps to crash on exit
#endif

#define tsPutCfgSTR(szLabel,szBuffer)  tsPutCfgParam(szLabel,szBuffer,P_STR   )
#define tsPutCfgUINT8(szLabel,pData)   tsPutCfgParam(szLabel,pData   ,P_UINT8 )
#define tsPutCfgINT8(szLabel,pData)    tsPutCfgParam(szLabel,pData   ,P_INT8  )
#define tsPutCfgUINT16(szLabel,pData)  tsPutCfgParam(szLabel,pData   ,P_UINT16)
#define tsPutCfgINT16(szLabel,pData)   tsPutCfgParam(szLabel,pData   ,P_INT16 )
#define tsPutCfgUINT32(szLabel,pData)  tsPutCfgParam(szLabel,pData   ,P_UINT32)
#define tsPutCfgINT32(szLabel,pData)   tsPutCfgParam(szLabel,pData   ,P_INT32 )
#define tsPutCfgUINT64(szLabel,pData)  tsPutCfgParam(szLabel,pData   ,P_UINT64)
#define tsPutCfgINT64(szLabel,pData)   tsPutCfgParam(szLabel,pData   ,P_INT64 )

#define tsGetCfgSTR(szLabel,szBuffer,nBytes)  tsGetCfgParam(szLabel,NULL,szBuffer,nBytes        ,P_STR   )
#define tsGetCfgUINT8(szLabel,pData)          tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT8) ,P_UINT8 )
#define tsGetCfgINT8(szLabel,pData)           tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT8)  ,P_INT8  )
#define tsGetCfgUINT16(szLabel,pData)         tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT16),P_UINT16)
#define tsGetCfgINT16(szLabel,pData)          tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT16) ,P_INT16 )
#define tsGetCfgUINT32(szLabel,pData)         tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT32),P_UINT32)
#define tsGetCfgINT32(szLabel,pData)          tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT32) ,P_INT32 )
#define tsGetCfgUINT64(szLabel,pData)         tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT64),P_UINT64)
#define tsGetCfgINT64(szLabel,pData)          tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT64) ,P_INT64 )

#define tsGetFlag(szSwitch)                     tsGetCfgParam(NULL,szSwitch,NULL    ,0          ,P_VOID  )
#define tsGetFlagEx(szLabel, szSwitch)			tsGetCfgParam(szLabel,szSwitch,NULL    ,0          ,P_VOID  )
#define tsGetFlagSTR(szSwitch,szBuffer,nBytes)  tsGetCfgParam(NULL,szSwitch,szBuffer,nBytes        ,P_STR   )
#define tsGetFlagUINT8(szSwitch,pData)          tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(UINT8) ,P_UINT8 )
#define tsGetFlagINT8(szSwitch,pData)           tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(INT8)  ,P_INT8  )
#define tsGetFlagUINT16(szSwitch,pData)         tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(UINT16),P_UINT16)
#define tsGetFlagINT16(szSwitch,pData)          tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(INT16) ,P_INT16 )
#define tsGetFlagUINT32(szSwitch,pData)         tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(UINT32),P_UINT32)
#define tsGetFlagINT32(szSwitch,pData)          tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(INT32) ,P_INT32 )
#define tsGetFlagUINT64(szSwitch,pData)         tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(UINT64),P_UINT64)
#define tsGetFlagINT64(szSwitch,pData)          tsGetCfgParam(NULL,szSwitch,pData   ,sizeof(INT64) ,P_INT64 )

#define tsGetSTR(szLabel,szSwitch,szBuffer,nBytes) tsGetCfgParam(szLabel,szSwitch,szBuffer,nBytes        ,P_STR   )
#define tsGetUINT8(szLabel,szSwitch,pData)          tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(UINT8) ,P_UINT8 )
#define tsGetINT8(szLabel,szSwitch,pData)           tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(INT8)  ,P_INT8  )
#define tsGetUINT16(szLabel,szSwitch,pData)         tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(UINT16),P_UINT16)
#define tsGetINT16(szLabel,szSwitch,pData)          tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(INT16) ,P_INT16 )
#define tsGetUINT32(szLabel,szSwitch,pData)         tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(UINT32),P_UINT32)
#define tsGetINT32(szLabel,szSwitch,pData)          tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(INT32) ,P_INT32 )
#define tsGetUINT64(szLabel,szSwitch,pData)         tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(UINT64),P_UINT64)
#define tsGetINT64(szLabel,szSwitch,pData)          tsGetCfgParam(szLabel,szSwitch,pData   ,sizeof(INT64) ,P_INT64 )

#define tsPutCfgArySTR(szLabel,x,y,szBuffer)  tsPutCfgArray(szLabel,x,y,szBuffer,P_STR   )
#define tsPutCfgAryUINT8(szLabel,x,y,pData)   tsPutCfgArray(szLabel,x,y,pData   ,P_UINT8 )
#define tsPutCfgAryINT8(szLabel,x,y,pData)    tsPutCfgArray(szLabel,x,y,pData   ,P_INT8  )
#define tsPutCfgAryUINT16(szLabel,x,y,pData)  tsPutCfgArray(szLabel,x,y,pData   ,P_UINT16)
#define tsPutCfgAryINT16(szLabel,x,y,pData)   tsPutCfgArray(szLabel,x,y,pData   ,P_INT16 )
#define tsPutCfgAryUINT32(szLabel,x,y,pData)  tsPutCfgArray(szLabel,x,y,pData   ,P_UINT32)
#define tsPutCfgAryINT32(szLabel,x,y,pData)   tsPutCfgArray(szLabel,x,y,pData   ,P_INT32 )
#define tsPutCfgAryUINT64(szLabel,x,y,pData)  tsPutCfgArray(szLabel,x,y,pData   ,P_UINT64)
#define tsPutCfgAryINT64(szLabel,x,y,pData)   tsPutCfgArray(szLabel,x,y,pData   ,P_INT64 )

#define tsGetCfgAryDim(szLabel,pXdim,pYdim)			 tsGetCfgArrayDim(szLabel,NULL,pXdim,pYdim)
#define tsGetCfgArySTR(szLabel,x,y,szBuffer,nBytes)  tsGetCfgArray(szLabel,NULL,x,y,szBuffer,nBytes        ,P_STR   )
#define tsGetCfgAryUINT8(szLabel,x,y,pData)          tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(UINT8) ,P_UINT8 )
#define tsGetCfgAryINT8(szLabel,x,y,pData)           tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(INT8)  ,P_INT8  )
#define tsGetCfgAryUINT16(szLabel,x,y,pData)         tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(UINT16),P_UINT16)
#define tsGetCfgAryINT16(szLabel,x,y,pData)          tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(INT16) ,P_INT16 )
#define tsGetCfgAryUINT32(szLabel,x,y,pData)         tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(UINT32),P_UINT32)
#define tsGetCfgAryINT32(szLabel,x,y,pData)          tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(INT32) ,P_INT32 )
#define tsGetCfgAryUINT64(szLabel,x,y,pData)         tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(UINT64),P_UINT64)
#define tsGetCfgAryINT64(szLabel,x,y,pData)          tsGetCfgArray(szLabel,NULL,x,y,pData   ,sizeof(INT64) ,P_INT64 )

#define tsGetAryDim(szLabel,szSwitch,pXdim,pYdim)	tsGetCfgArrayDim(szLabel,szSwitch,pXdim,pYdim)
#define tsGetArySTR(szLabel,szSwitch,x,y,szBuffer,nBytes)	tsGetCfgArray(szLabel,szSwitch,x,y,szBuffer,nBytes,P_STR   )
#define tsGetAryUINT8(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(UINT8) ,P_UINT8 )
#define tsGetAryINT8(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(INT8)  ,P_INT8  )
#define tsGetAryUINT16(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(UINT16),P_UINT16)
#define tsGetAryINT16(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(INT16) ,P_INT16 )
#define tsGetAryUINT32(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(UINT32),P_UINT32)
#define tsGetAryINT32(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(INT32) ,P_INT32 )
#define tsGetAryUINT64(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(UINT64),P_UINT64)
#define tsGetAryINT64(szLabel,szSwitch,x,y,pData)	tsGetCfgArray(szLabel,szSwitch,x,y,pData   ,sizeof(INT64) ,P_INT64 )

#ifdef USE_TSLIB_INLINE

#undef tsPutCfgSTR
#undef tsPutCfgUINT8
#undef tsPutCfgINT8
#undef tsPutCfgUINT16
#undef tsPutCfgINT16
#undef tsPutCfgUINT32
#undef tsPutCfgINT32
#undef tsPutCfgUINT64
#undef tsPutCfgINT64

#undef tsPutCfgArySTR
#undef tsPutCfgAryUINT8
#undef tsPutCfgAryINT8
#undef tsPutCfgAryUINT16
#undef tsPutCfgAryINT16
#undef tsPutCfgAryUINT32
#undef tsPutCfgAryINT32
#undef tsPutCfgAryUINT64
#undef tsPutCfgAryINT64

#undef tsGetCfgSTR
#undef tsGetCfgUINT8
#undef tsGetCfgINT8
#undef tsGetCfgUINT16
#undef tsGetCfgINT16
#undef tsGetCfgUINT32
#undef tsGetCfgINT32
#undef tsGetCfgUINT64
#undef tsGetCfgINT64

#undef tsGetCfgArySTR
#undef tsGetCfgAryUINT8
#undef tsGetCfgAryINT8
#undef tsGetCfgAryUINT16
#undef tsGetCfgAryINT16
#undef tsGetCfgAryUINT32
#undef tsGetCfgAryINT32
#undef tsGetCfgAryUINT64
#undef tsGetCfgAryINT64

#define DECLARE_TSPUT_INLINE \
	inline DLLEXPORT TSSTATUS tsPutCfgSTR(LPCSTR szLabel, LPSTR szBuffer) { \
						return tsPutCfgParam(szLabel,szBuffer,P_STR   ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgUINT8(LPCSTR szLabel, PUINT8 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_UINT8 ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgINT8(LPCSTR szLabel, PINT8 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_INT8  ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgUINT16(LPCSTR szLabel, PUINT16 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_UINT16); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgINT16(LPCSTR szLabel, PINT16 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_INT16 ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgUINT32(LPCSTR szLabel, PUINT32 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_UINT32); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgINT32(LPCSTR szLabel, PINT32 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_INT32 ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgUINT64(LPCSTR szLabel, PUINT64 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_UINT64); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgINT64(LPCSTR szLabel, PINT64 pData) { \
						return tsPutCfgParam(szLabel,pData   ,P_INT64 ); }; 

	inline DLLEXPORT TSSTATUS tsPutCfgArySTR(LPCSTR szLabel, UINTN x, UINTN y, LPSTR szBuffer) { \
						return tsPutCfgArray(szLabel, x, y, szBuffer,P_STR   ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryUINT8(LPCSTR szLabel, UINTN x, UINTN y, PUINT8 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_UINT8 ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryINT8(LPCSTR szLabel, UINTN x, UINTN y, PINT8 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_INT8  ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryUINT16(LPCSTR szLabel, UINTN x, UINTN y, PUINT16 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_UINT16); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryINT16(LPCSTR szLabel, UINTN x, UINTN y, PINT16 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_INT16 ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryUINT32(LPCSTR szLabel, UINTN x, UINTN y, PUINT32 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_UINT32); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryINT32(LPCSTR szLabel, UINTN x, UINTN y, PINT32 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_INT32 ); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryUINT64(LPCSTR szLabel, UINTN x, UINTN y, PUINT64 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_UINT64); }; \
	inline DLLEXPORT TSSTATUS tsPutCfgAryINT64(LPCSTR szLabel, UINTN x, UINTN y, PINT64 pData) { \
						return tsPutCfgArray(szLabel, x, y, pData   ,P_INT64 ); }; 

#define DECLARE_TSGET_INLINE \
	inline DLLEXPORT TSSTATUS tsGetCfgSTR(LPCSTR szLabel, LPSTR szBuffer, int nBytes) { \
				return tsGetCfgParam(szLabel,NULL,szBuffer,nBytes        ,P_STR   ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgUINT8(LPCSTR szLabel, PUINT8 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT8) ,P_UINT8 ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgINT8(LPCSTR szLabel, PINT8 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT8)  ,P_INT8  ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgUINT16(LPCSTR szLabel, PUINT16 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT16),P_UINT16); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgINT16(LPCSTR szLabel, PINT16 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT16) ,P_INT16 ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgUINT32(LPCSTR szLabel, PUINT32 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT32),P_UINT32); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgINT32(LPCSTR szLabel, PINT32 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT32) ,P_INT32 ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgUINT64(LPCSTR szLabel, PUINT64 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(UINT64),P_UINT64); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgINT64(LPCSTR szLabel, PINT64 pData) { \
				return tsGetCfgParam(szLabel,NULL,pData   ,sizeof(INT64) ,P_INT64 ); }; 

	inline DLLEXPORT TSSTATUS tsGetCfgArySTR(LPCSTR szLabel, UINTN x, UINTN y, LPSTR szBuffer, int nBytes) { \
				return tsGetCfgArray(szLabel, NULL, x, y, szBuffer,nBytes        ,P_STR   ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryUINT8(LPCSTR szLabel, UINTN x, UINTN y, PUINT8 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(UINT8) ,P_UINT8 ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryINT8(LPCSTR szLabel, UINTN x, UINTN y, PINT8 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(INT8)  ,P_INT8  ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryUINT16(LPCSTR szLabel, UINTN x, UINTN y, PUINT16 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(UINT16),P_UINT16); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryINT16(LPCSTR szLabel, UINTN x, UINTN y, PINT16 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(INT16) ,P_INT16 ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryUINT32(LPCSTR szLabel, UINTN x, UINTN y, PUINT32 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(UINT32),P_UINT32); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryINT32(LPCSTR szLabel, UINTN x, UINTN y, PINT32 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(INT32) ,P_INT32 ); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryUINT64(LPCSTR szLabel, UINTN x, UINTN y, PUINT64 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(UINT64),P_UINT64); }; \
	inline DLLEXPORT TSSTATUS tsGetCfgAryINT64(LPCSTR szLabel, UINTN x, UINTN y, PINT64 pData) { \
				return tsGetCfgArray(szLabel, NULL, x, y, pData, sizeof(INT64) ,P_INT64 ); };
#else
#define DECLARE_TSPUT_INLINE
#define DECLARE_TSGET_INLINE
#endif

/*********************************************************************************************
 ** DECLARE_TSPUT_INLINE and DECLARE_TSGET_INLINE is a macro inserted in the main app class	**
 ** or base class to replace the tsPutCfgXXX macro for better type checking administered by **
 ** inline routine																			**
 ** Example:																				**	
 ** In LxMTAApp.h																			**
 ** #include <libts.h>																		**
 ** clase LxMTAApp																			**
 ** {   public:																				**
 **		DECLARE_TSPUT_INLINE																**
 **     //Rest of the class declaration														**
 **																							**
 ** In BASECLASS.h																			**
 ** #include <libts.h>																		**
 ** clase BASECLASS																			**
 ** {   protected:																			**
 **     DECLARE_TSGET_INLINE																**
 **     //Rest of the class declaration														**
 **																							**
 ** Or as public inline function, in main.h													**
 ** DECLARE_TSGET_INLINE																	**
 ** DELCARE_TSPUT_INLINE																	**
 **																							**
 **																							**
 ** In the make file or compile time, ensure the CPPFLAG has defined USE_TSLIB_INLINE		**
 ** Ex: gcc -DUSE_TSLIB_INLINE -c mainclass.cpp -o mainclass.o								**
 ** or in Makefile:																			**
 ** CPPFLAG := $(CPPFLAG) -DUSE_TSLIB_INLINE												**
 **																							**
 *********************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* _TSLIB.H_ */
