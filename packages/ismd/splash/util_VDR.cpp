// Copyright(c) 2012 Reel Multimedia. All rights reserved.

#include <stdio.h>
#include "util.h"
#include "util_VDR.h"

#include <ctype.h>

inline char *skipspace(const char *s) {
	if (*s > ' ') // most strings don't have any leading space, so handle this case as fast as possible
		return (char *)s;
	while (*s && *s <= ' ') // avoiding isspace() here, because it is much slower
		s++;
	return (char *)s;
} // skipspace

static char *stripspace(char *s) {
	if (s && *s) {
		for (char *p = s + strlen(s) - 1; p >= s; p--) {
			if (!isspace(*p))
				break;
			*p = 0;
		}
	}
	return s;
} // stripspace

static char *compactspace(char *s) {
	if (s && *s) {
		char *t = stripspace(skipspace(s));
		char *p = t;
		while (p && *p) {
			char *q = skipspace(p);
			if (q - p > 1)
				memmove(p + 1, q, strlen(q) + 1);
			p++;
		}
		if (t != s)
			memmove(s, t, strlen(t) + 1);
	}
	return s;
} // compactspace

int GetConfigStr(const char *filename, const char *key, char **value) {
	FILE *file = NULL;
	char *data = NULL;
	size_t size = 0;
	ssize_t read;
	file = fopen(filename, "r");
	if(!file) return -1;
	int ret = -2;
	while(read = getline(&data, &size, file) != -1) {
		char *p = strchr(data, '=');
		if(p) {
			*p=0;
			char *n = compactspace(data);
			char *v = compactspace(p+1);
			if(!strncmp(n, key, strlen(key))) {
				printf("Found \"%s\"=\"%s\"\n", n, v);
				*value = strdup(v);
				ret = 0;
				break;
			} // if
		} // if
	} // while
	fclose(file);
	free(data);
	return ret;
} // GetConfigStr

int GetConfigInt(const char *filename, const char *key, int *value) {
	char *v=NULL;
	int ret = GetConfigStr(filename, key, &v);
	if(!ret) *value = atoi(v);
	free(v);
	return ret;
} // GetConfigInt

gdl_tvmode_t DefaultTVMode = {width:720, height:576, refresh:GDL_REFRESH_50, interlaced:GDL_FALSE, stereo_type:GDL_STEREO_NONE};

void MapTVMode(tICE_TVMode in, gdl_tvmode_t &out) {
	memset(&out, 0, sizeof(out));
	out.stereo_type = GDL_STEREO_NONE;
	switch(in) {
		case ICE_TVMODE_NTSC       : // no break;
		case ICE_TVMODE_480I       : out.width =  720; out.height =  480; out.refresh = GDL_REFRESH_59_94; out.interlaced  = GDL_TRUE;  break;
		case ICE_TVMODE_480P       : out.width =  720; out.height =  480; out.refresh = GDL_REFRESH_59_94; out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_PAL        : // no break;
		case ICE_TVMODE_576I       : out.width =  720; out.height =  576; out.refresh = GDL_REFRESH_50;    out.interlaced  = GDL_TRUE;  break;
		case ICE_TVMODE_576P       : out.width =  720; out.height =  576; out.refresh = GDL_REFRESH_50;    out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_720P59_94  : out.width = 1280; out.height =  720; out.refresh = GDL_REFRESH_59_94; out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_720P50     : out.width = 1280; out.height =  720; out.refresh = GDL_REFRESH_50;    out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_1080I59_94 : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_59_94; out.interlaced  = GDL_TRUE;  break;
		case ICE_TVMODE_1080I50    : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_50;    out.interlaced  = GDL_TRUE;  break;
		case ICE_TVMODE_1080P23_98 : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_23_98; out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_1080P25    : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_25;    out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_1080P29_97 : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_29_97; out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_1080P50    : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_50;    out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_1080P59_94 : out.width = 1920; out.height = 1080; out.refresh = GDL_REFRESH_59_94; out.interlaced  = GDL_FALSE; break;
		case ICE_TVMODE_NATIVE     : 
			if(GDL_SUCCESS == gdl_port_recv(GDL_PD_ID_HDMI, GDL_PD_RECV_HDMI_NATIVE_MODE, &out, sizeof(out))); {
				if((GDL_REFRESH_50 != out.refresh) || (GDL_REFRESH_25 != out.refresh)) { // Try to force 50Hz/25Hz
					gdl_refresh_t old = out.refresh;
					out.refresh = GDL_REFRESH_50;
					if(GDL_SUCCESS != gdl_check_tvmode(GDL_DISPLAY_ID_0, &out)) {
						out.refresh = GDL_REFRESH_25;
						if(GDL_SUCCESS != gdl_check_tvmode(GDL_DISPLAY_ID_0, &out)) out.refresh = old;
					} // if
				} // if
				break;
			} // ICE_TVMODE_NATIVE
			// NO break
		default                    : out = DefaultTVMode;
	} // switch
	if(GDL_SUCCESS != gdl_check_tvmode(GDL_DISPLAY_ID_0, &out)) out = DefaultTVMode;
} //  MapTVMode

void GetTvMode(const char *filename, gdl_tvmode_t *mode, const char **mode_str) {
	int m = (int)ICE_TVMODE_NONE;
	if(GetConfigInt(filename, "reelice.tv_mode", &m)) {
		m = (int)ICE_TVMODE_NATIVE;
		if(mode_str) *mode_str = "Default";
	} else if(mode_str) *mode_str = TVMODE_STR((tICE_TVMode)m);
	MapTVMode((tICE_TVMode)m, *mode);
} // GetTvMode

