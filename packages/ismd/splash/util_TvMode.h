// Copyright(c) 2012 Reel Multimedia. All rights reserved.

#ifndef __UTIL_TVMODE_H__
#define __UTIL_TVMODE_H__


#if defined(__cplusplus)
extern "C" {
#endif

#include <gdl_types.h>

int GetCurrentTvMode(gdl_tvmode_t *mode);
int SetCurrentTvMode(gdl_tvmode_t *mode);

#if defined(__cplusplus)
}
#endif

#endif /*__UTIL_TVMODE_H__*/
