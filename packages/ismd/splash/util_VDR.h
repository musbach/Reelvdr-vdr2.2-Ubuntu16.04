// Copyright(c) 2012 Reel Multimedia. All rights reserved.

#ifndef __UTIL_VDR_H__
#define __UTIL_VDR_H__


#if defined(__cplusplus)
extern "C" {
#endif

#include <gdl_types.h>

#define trNOOP(x) (x)
#include <ice_types.h>

int GetConfigStr(const char *filename, const char *key, char **value);
int GetConfigInt(const char *filename, const char *key, int *value);
void GetTvMode(const char *filename, gdl_tvmode_t *mode, const char **tvmode);
void MapTVMode(tICE_TVMode in, gdl_tvmode_t &out);

#if defined(__cplusplus)
}
#endif

#endif /*__UTIL_VDR_H__*/
