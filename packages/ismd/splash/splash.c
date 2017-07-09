// Copyright(c) 2012 Reel Multimedia. All rights reserved.

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libgdl.h"
#include "util.h"

static void usage(void) {
    printf("\nUsage: splash filename\n");
    exit(1);
} // usage

static int terminate = 0;
static void signalhandler(int signum) {
    if(SIGHUP == signum) terminate = 1; 
} // signalhandler

int main(int argc, char **argv) {
    char *              pFileName;
    const char *        pVdrSetup = "/etc/vdr/setup.conf";
    gdl_surface_info_t  surface;
    gdl_rectangle_t     r;
    ImagePNG *          pImagePNG      = NULL;
    gdl_display_info_t  di;
    gdl_plane_id_t      plane = GDL_PLANE_ID_UPP_A;
    gdl_display_id_t    disp_id;

    if (argc < 2 ) {
        usage();    // No return
    } // if
#if 0
    if (argc == 3 || argc == 4) {
        int arg_lcv = 2;
        for ( ; arg_lcv < argc; arg_lcv++) {
            if (strcmp(argv[arg_lcv], "-nowait") == 0) {
                wait = 0;
            } else {
                switch (argv[arg_lcv][0]) {
                    case 'A': plane = GDL_PLANE_ID_UPP_A;  break;
                    case 'B': plane = GDL_PLANE_ID_UPP_B;  break;
                    case 'C': plane = GDL_PLANE_ID_UPP_C;  break;
                    case 'D': plane = GDL_PLANE_ID_UPP_D;  break;
                    case 'E': plane = GDL_PLANE_ID_UPP_E;  break;
                    default : usage(); // No return
                } // switch
            } // if
        } // for
    } // if
#endif
    pFileName = argv[1];
    CHKF(gdl_init(NULL));
    signal(SIGHUP, signalhandler);
    gdl_tvmode_t new_mode, old_mode;
    const char *mode_str;
    GetTvMode(pVdrSetup, &new_mode, &mode_str);
    printf("Tvmode %s (%dx%d%s%s) ", mode_str, new_mode.width, new_mode.height, new_mode.interlaced?"i":"p",REFRESH_STR(new_mode.refresh));
    if(GetCurrentTvMode(&old_mode) || memcmp(&old_mode, &new_mode, sizeof(new_mode))) {
        gdl_boolean_t val = GDL_FALSE;
        gdl_port_set_attr(GDL_PD_ID_HDMI, GDL_PD_ATTR_ID_HDCP, &val);
        val = GDL_TRUE;
        gdl_port_set_attr(GDL_PD_ID_HDMI, GDL_PD_ATTR_ID_POWER, &val);
        if(SetCurrentTvMode(&new_mode)) {
            gdl_tvmode_t native_mode;
            MapTVMode(ICE_TVMODE_NATIVE, native_mode);
            if(!memcmp(&native_mode, &new_mode, sizeof(new_mode)) || SetCurrentTvMode(&native_mode)) {
                printf("failed to set\n");
                exit(3);
            } else printf("failed to set -> using native instead (%dx%d%s%s)\n", native_mode.width, native_mode.height, native_mode.interlaced?"i":"p",REFRESH_STR(native_mode.refresh));
        } else printf("changed\n");
    } else printf("unchanged\n");

    ON_ERR(close, gdl_plane_get_attr(plane, GDL_PLANE_DISPLAY_ID, &disp_id));
    ON_ERR(close, CreateImagePNG( pFileName, &pImagePNG));
    printf("Image Width: %d  Height: %d  Format %d\n", pImagePNG->width, pImagePNG->height, pImagePNG->pixelFormat );

    ON_ERR(destroy_image, gdl_get_display_info(disp_id,  &di) );
    if (pImagePNG->width > di.tvmode.width)
        pImagePNG->width = di.tvmode.width;
    if (pImagePNG->height > di.tvmode.height)
        pImagePNG->height = di.tvmode.height;
    ON_ERR(destroy_image, gdl_plane_reset(plane));
    ON_ERR(destroy_image, gdl_plane_get_rect(plane, GDL_PLANE_DST_RECT, &r));
#if 0
    r.width = pImagePNG->width;
    r.height = pImagePNG->height;
    r.origin.x = (di.tvmode.width  - pImagePNG->width ) / 2;
    r.origin.y = (di.tvmode.height - pImagePNG->height) / 2;
    r.origin.y &= 0xfffffffe;
#else
    r.width = di.tvmode.width;
    r.height = di.tvmode.height;
    r.origin.x = 0;
    r.origin.y = 0;
#endif
    ON_ERR(destroy_image, gdl_plane_config_begin(plane));
    ON_ERR(abort, gdl_plane_set_rect(   GDL_PLANE_DST_RECT, &r));
    ON_ERR(abort, gdl_plane_set_uint(   GDL_PLANE_PIXEL_FORMAT, (pImagePNG->pixelFormat == GDL_PF_RGB_24) ? GDL_PF_RGB_32 : GDL_PF_ARGB_32));
    ON_ERR(abort, gdl_plane_set_uint(   GDL_PLANE_SRC_COLOR_SPACE, GDL_COLOR_SPACE_RGB));

    ON_ERR(destroy_image, gdl_plane_config_end( GDL_FALSE));
    CreateSurfaceWithImage( pFileName, 0, GDL_TRUE, SIZE_CONSTRAINT_NONE, SIZE_CONSTRAINT_NONE, &surface );
    CHK(gdl_flip(plane, surface.id, GDL_FLIP_SYNC));
    while(!terminate) usleep(100000);
    CHK(gdl_flip(plane, GDL_SURFACE_INVALID, GDL_FLIP_SYNC));
    CHK(gdl_free_surface(surface.id));
abort:
    gdl_plane_config_end(GDL_TRUE);   // Terminate any incomplete plane config
destroy_image:
    DestroyImagePNG( pImagePNG );
close:
    gdl_close();
    signal(SIGHUP, SIG_DFL);
    return 0;
} // main

