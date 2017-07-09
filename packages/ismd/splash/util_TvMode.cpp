// Copyright(c) 2012 Reel Multimedia. All rights reserved.

#include <stdio.h>
#include "util.h"
#include "util_TvMode.h"

#include <ismd_audio.h>

int GetCurrentTvMode(gdl_tvmode_t *mode) {
	gdl_display_info_t di;
	if(GDL_SUCCESS != gdl_get_display_info(GDL_DISPLAY_ID_0, &di)) return -1;
	*mode = di.tvmode;
	return 0;
} //  GetCurrentTvMode

int SetCurrentTvMode(gdl_tvmode_t *mode) {
	ismd_audio_processor_t aud_prc;
	ismd_audio_output_t    aud_out;
	if(ISMD_SUCCESS==ismd_audio_open_global_processor(&aud_prc))
		if(ISMD_SUCCESS==ismd_audio_output_get_handle_by_hw_id(aud_prc, GEN3_HW_OUTPUT_HDMI, &aud_out))
			ismd_audio_remove_output(aud_prc, aud_out);
	gdl_display_info_t di;
	memset(&di, 0, sizeof(di));
	di.id          = GDL_DISPLAY_ID_0;
	di.tvmode      = *mode;
	di.bg_color    = 0;
	di.gamma       = GDL_GAMMA_LINEAR;
	di.color_space = (mode->height > 576) ? GDL_COLOR_SPACE_BT709 : GDL_COLOR_SPACE_BT601;
	if(GDL_SUCCESS != gdl_set_display_info(&di)) return -1;
	return 0;
} // SetCurrentTvMode
