/* include/configure.h.  Generated from configure.h.in by configure.  */
/* include/configure.h.in.  Generated from configure.ac by autoheader.  */

#ifndef __XINE_LIB_CONFIG_H__
#define __XINE_LIB_CONFIG_H__ 1


#ifndef _XINE_CONFIGURE_H_
#define _XINE_CONFIGURE_H_


/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define this if you're running Alpha architecture */
/* #undef ARCH_ALPHA */

/* Define this if you're running ARM architecture */
/* #undef ARCH_ARM */

/* Define this if you're running PowerPC architecture */
/* #undef ARCH_PPC */

/* Define this if you're running SPARC architecture */
/* #undef ARCH_SPARC */

/* Define this if you're running x86 architecture */
#define ARCH_X86 /**/

/* Define this if you're running x86 architecture 32 bits */
#define ARCH_X86_32 /**/

/* Define this if you're running x86 architecture 64 bits */
/* #undef ARCH_X86_64 */

/* define if '.align n' means alignment to (1 << n) - byte boundaries */
/* #undef ASMALIGN_1SLN */

/* Define the highest alignment supported */
#define ATTRIBUTE_ALIGNED_MAX 64

/* Define this if built on Mac OS X/Darwin */
/* #undef CONFIG_DARWIN */

/* what to put between the brackets for empty arrays */
#define EMPTY_ARRAY_SIZE 

/* Define this if you want to use altivec on PowerPC CPUs */
/* #undef ENABLE_ALTIVEC */

/* Define this to 1 to enable font antialising. */
/* #undef ENABLE_ANTIALIASING */

/* Enable this when IPv6 is requested */
/* #undef ENABLE_IPV6 */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 1

/* Define this if you have Sun UltraSPARC CPU */
/* #undef ENABLE_VIS */

/* Mark a symbol as being exported if visibility is changed */
#define EXPORTED __attribute__((visibility("default")))

/* Get of rid system libcdio build configuration */
#define EXTERNAL_LIBCDIO_CONFIG_H 1

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_64BIT */

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_ARM */

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_DEFAULT */

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_INTEL */

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_MIPS */

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_PPC */

/* Define to select libmad fixed point arithmetic implementation */
/* #undef FPM_SPARC */

/* Define to 1 if you have the <a52dec/a52.h> header file. */
/* #undef HAVE_A52DEC_A52_H */

/* Define to 1 if you have the <alloca.h> header file. */
#define HAVE_ALLOCA_H 1

/* Define this if you have ALSA installed */
#define HAVE_ALSA 1

/* Define to 1 if you have the <asm/types.h> header file. */
#define HAVE_ASM_TYPES_H 1

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the <assert.h> header file. */
#define HAVE_ASSERT_H 1

/* Define to 1 if `output_muted' is a member of `audio_info_t'. */
/* #undef HAVE_AUDIO_INFO_T_OUTPUT_MUTED */

/* Define this if you have libavformat installed */
#define HAVE_AVFORMAT 1

/* define if compiler supports avx inline assembler */
#define HAVE_AVX 1

/* Define to 1 if you have the `basename' function. */
#define HAVE_BASENAME 1

/* Define to 1 if you have the <byteswap.h> header file. */
#define HAVE_BYTESWAP_H 1

/* Define to 1 if you have the `bzero' function. */
#define HAVE_BZERO 1

/* Define to 1 if you have the MacOS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the MacOS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
#define HAVE_DCGETTEXT 1

/* Define to 1 if you have the <dev/dtv/dtvio.h> header file. */
/* #undef HAVE_DEV_DTV_DTVIO_H */

/* Define this if you have DirectX */
/* #undef HAVE_DIRECTX */

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define this if you have a suitable version of libdvdnav */
/* #undef HAVE_DVDNAV */

/* Define to 1 if you have the environ symbol. */
/* #undef HAVE_ENVIRON */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <execinfo.h> header file. */
#define HAVE_EXECINFO_H 1

/* Define to 1 if you have the <fame.h> header file. */
/* #undef HAVE_FAME_H */

/* Define this if you have linux framebuffer support */
#define HAVE_FB 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define this if you have ffmpeg library */
#define HAVE_FFMPEG 1

/* Define to 1 if you have the <ffmpeg/avutil.h> header file. */
/* #undef HAVE_FFMPEG_AVUTIL_H */

/* Define to 1 if you have the <FLAC/stream_decoder.h> header file. */
/* #undef HAVE_FLAC_STREAM_DECODER_H */

/* Define this if you have fontconfig library */
/* #undef HAVE_FONTCONFIG */

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* Define this if you have freetype2 library */
/* #undef HAVE_FT2 */

/* Define this if you have GNU getopt_long() implemented */
#define HAVE_GETOPT_LONG /**/

/* Define to 1 if you have the `getpwuid_r' function. */
#define HAVE_GETPWUID_R 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the <glob.h> header file. */
#define HAVE_GLOB_H 1

/* Define this if you have GLU support available */
#define HAVE_GLU 1

/* Define to 1 if you have the <GL/glu.h> header file. */
#define HAVE_GL_GLU_H 1

/* Define to 1 if you have the <GL/gl.h> header file. */
#define HAVE_GL_GL_H 1

/* Define this if you have GraphicsMagick installed */
/* #undef HAVE_GRAPHICSMAGICK */

/* Define to 1 if you have 'hstrerror' in <netdb.h> */
#define HAVE_HSTRERROR 1

/* Define if you have the iconv() function and it works. */
#define HAVE_ICONV 1

/* Define to 1 if you have the <interface/mmal/mmal.h> header file. */
/* #undef HAVE_INTERFACE_MMAL_MMAL_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define this if you have a usable IRIX al interface available */
/* #undef HAVE_IRIXAL */

/* Supports ISO _Pragma() macro */
#define HAVE_ISOC99_PRAGMA /**/

/* Define to 1 if you have the <jpeglib.h> header file. */
#define HAVE_JPEGLIB_H 1

/* Define this if you have kernel statistics available via kstat interface */
/* #undef HAVE_KSTAT */

/* Define to 1 if you have the <libavutil/avutil.h> header file. */
#define HAVE_LIBAVUTIL_AVUTIL_H 1

/* Define to 1 if you have the <libavutil/sha1.h> header file. */
/* #undef HAVE_LIBAVUTIL_SHA1_H */

/* Define to 1 if you have the <libavutil/sha.h> header file. */
#define HAVE_LIBAVUTIL_SHA_H 1

/* Define this if you have libfame mpeg encoder installed (fame.sf.net) */
/* #undef HAVE_LIBFAME */

/* Define to 1 if you have the <libgen.h> header file. */
#define HAVE_LIBGEN_H 1

/* Define to 1 if you have the <libmng.h> header file. */
/* #undef HAVE_LIBMNG_H */

/* Define to 1 if you have the `posix4' library (-lposix4). */
/* #undef HAVE_LIBPOSIX4 */

/* Define this if you have librte mpeg encoder installed (zapping.sf.net) */
/* #undef HAVE_LIBRTE */

/* Define this if you have libv4l installed */
#define HAVE_LIBV4L2_H 1

/* Define to 1 if you have the `vdpau' library (-lvdpau). */
/* #undef HAVE_LIBVDPAU */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define 1 if you have Linux-type CD-ROM support */
#define HAVE_LINUX_CDROM 1

/* Define to 1 if you have the <linux/cdrom.h> header file. */
#define HAVE_LINUX_CDROM_H 1

/* Define 1 if timeout is in cdrom_generic_command struct */
#define HAVE_LINUX_CDROM_TIMEOUT 1

/* Define to 1 if you have the <linux/fb.h> header file. */
#define HAVE_LINUX_FB_H 1

/* Define to 1 if you have the <linux/videodev2.h> header file. */
#define HAVE_LINUX_VIDEODEV2_H 1

/* Define to 1 if you have the <linux/videodev.h> header file. */
/* #undef HAVE_LINUX_VIDEODEV_H */

/* Define to 1 if you have the `llabs' function. */
#define HAVE_LLABS 1

/* Define this if the 'lrintf' function is declared in math.h */
#define HAVE_LRINTF 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if you have the <machine/soundcard.h> header file. */
/* #undef HAVE_MACHINE_SOUNDCARD_H */

/* Define to 1 if you have the <mad.h> header file. */
#define HAVE_MAD_H 1

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have 'MAX' macro in sys/param.h */
#define HAVE_MAX_MACRO 1

/* Define to 1 if you have the `memalign' function. */
#define HAVE_MEMALIGN 1

/* Define to 1 if you have the `memcpy' function. */
#define HAVE_MEMCPY 1

/* Define to 1 if you have the `memmem' function. */
#define HAVE_MEMMEM 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have 'MIN' macro in sys/param.h */
#define HAVE_MIN_MACRO 1

/* Define this if you have mlib installed */
/* #undef HAVE_MLIB */

/* Define to 1 if you have the <mlib_video.h> header file. */
/* #undef HAVE_MLIB_VIDEO_H */

/* Define this if you have MMAL installed */
/* #undef HAVE_MMAL */

/* Define to 1 if you have the `mmap' function. */
/* #undef HAVE_MMAP */

/* Define this if you can compile MMX asm instructions */
#define HAVE_MMX /**/

/* Define to 1 if you have the <mpcdec/mpcdec.h> header file. */
/* #undef HAVE_MPCDEC_MPCDEC_H */

/* Define to 1 if you have the <mpc/mpcdec.h> header file. */
/* #undef HAVE_MPC_MPCDEC_H */

/* Define to 1 if you have the `nanosleep' function. */
#define HAVE_NANOSLEEP 1

/* Define to 1 if you have the <neaacdec.h> header file. */
#define HAVE_NEAACDEC_H 1

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define this if you have libfame 0.8.10 or above */
/* #undef HAVE_NEW_LIBFAME */

/* Define to 1 if you have the `nl_langinfo' function. */
#define HAVE_NL_LANGINFO 1

/* Define to 1 if you have 'opendir' function */
#define HAVE_OPENDIR 1

/* Define this if you have POSIX timers. */
#define HAVE_POSIX_TIMERS 1

/* Define to 1 if you have 'pthread_mutex_timedlock' in <pthread.h> */
#define HAVE_PTHREAD_MUTEX_TIMEDLOCK 1

/* define this if you have pulseaudio >= 0.9.7 */
/* #undef HAVE_PULSEAUDIO_0_9_7 */

/* Define to 1 if you have the `readlink' function. */
#define HAVE_READLINK 1

/* Define to 1 if you have the <rte.h> header file. */
/* #undef HAVE_RTE_H */

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `sigaction' function. */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the `sigset' function. */
#define HAVE_SIGSET 1

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if you have the <soundcard.h> header file. */
/* #undef HAVE_SOUNDCARD_H */

/* Define this if you have speex */
/* #undef HAVE_SPEEX */

/* Define to 1 if you have the <stdbool.h> header file. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the stderr symbol. */
#define HAVE_STDERR 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strcasestr' function. */
#define HAVE_STRCASESTR 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strndup' function. */
#define HAVE_STRNDUP 1

/* Define to 1 if you have the `strpbrk' function. */
#define HAVE_STRPBRK 1

/* Define to 1 if you have the `strsep' function. */
#define HAVE_STRSEP 1

/* Define to 1 if you have the `strtok_r' function. */
#define HAVE_STRTOK_R 1

/* Define to 1 if you have the <sys/cdio.h> header file. */
/* #undef HAVE_SYS_CDIO_H */

/* Define to 1 if you have the <sys/dvdio.h> header file. */
/* #undef HAVE_SYS_DVDIO_H */

/* Define to 1 if you have the <sys/fbio.h> header file. */
/* #undef HAVE_SYS_FBIO_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/mixer.h> header file. */
/* #undef HAVE_SYS_MIXER_H */

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/scsiio.h> header file. */
/* #undef HAVE_SYS_SCSIIO_H */

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#define HAVE_SYS_SOUNDCARD_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/times.h> header file. */
#define HAVE_SYS_TIMES_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/videodev2.h> header file. */
/* #undef HAVE_SYS_VIDEODEV2_H */

/* Define to 1 if you have the <sys/videoio.h> header file. */
/* #undef HAVE_SYS_VIDEOIO_H */

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* Define this if you have theora */
#define HAVE_THEORA 1

/* Define this if x11 does without XLockDisplay (). */
#define HAVE_THREAD_SAFE_X11 1

/* Define to 1 if you have the `timegm' function. */
#define HAVE_TIMEGM 1

/* Define if struct tm has the tm_gmtoff member. */
#define HAVE_TM_GMTOFF 1

/* Define to 1 if you have the <ucontext.h> header file. */
#define HAVE_UCONTEXT_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `unsetenv' function. */
#define HAVE_UNSETENV 1

/* Define to 1 if you have the `va_copy' function. */
/* #undef HAVE_VA_COPY */

/* Define to 1 if you have the <va/va.h> header file. */
/* #undef HAVE_VA_VA_H */

/* Define to 1 if you have the <va/va_x11.h> header file. */
/* #undef HAVE_VA_VA_X11_H */

/* Define this if you use external libcdio/libvcdinfo */
/* #undef HAVE_VCDNAV */

/* Define to 1 if you have the <vdpau/vdpau_x11.h> header file. */
/* #undef HAVE_VDPAU_VDPAU_X11_H */

/* Define if you have vldXvMC.h */
/* #undef HAVE_VLDXVMC */

/* Define this if you have vorbis */
#define HAVE_VORBIS 1

/* Define this if you have VP9 support in libvpx */
#define HAVE_VPX_VP9_DECODER 1

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define to 1 if you have the `vsscanf' function. */
#define HAVE_VSSCANF 1

/* Define this if you have X11R6 installed */
#define HAVE_X11 1

/* Define to 1 if you have the <X11/extensions/vldXvMC.h> header file. */
/* #undef HAVE_X11_EXTENSIONS_VLDXVMC_H */

/* Define to 1 if you have the <X11/extensions/XShm.h> header file. */
#define HAVE_X11_EXTENSIONS_XSHM_H 1

/* Define to 1 if you have the <X11/extensions/XvMC.h> header file. */
/* #undef HAVE_X11_EXTENSIONS_XVMC_H */

/* Define this if you have libXinerama installed */
#define HAVE_XINERAMA 1

/* Define this if you have libXv installed */
/* #undef HAVE_XV */

/* Define this if you have an XvMC library and XvMC.h installed. */
/* #undef HAVE_XVMC */

/* Define to 1 if you have the _environ symbol. */
/* #undef HAVE__ENVIRON */

/* Define to 1 if you have the `_snprintf' function. */
/* #undef HAVE__SNPRINTF */

/* Define to 1 if you have the `_stricmp' function. */
/* #undef HAVE__STRICMP */

/* Define to 1 if you have the `_strnicmp' function. */
/* #undef HAVE__STRNICMP */

/* Define to 1 if you have the `_vsnprintf' function. */
/* #undef HAVE__VSNPRINTF */

/* Define to 1 if you have the __ctype_b symbol. */
/* #undef HAVE___CTYPE_B */

/* Define to 1 if you have the __environ symbol. */
#define HAVE___ENVIRON 1

/* Define to 1 if you have the __stderrp symbol. */
/* #undef HAVE___STDERRP */

/* Define to 1 if you have the ___brk_addr symbol. */
#define HAVE____BRK_ADDR 1

/* Define this if built on Mac OS X/Darwin */
/* #undef HOST_OS_DARWIN */

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST 

/* Type of the request parameter for ioctl() */
#define IOCTL_REQUEST_TYPE unsigned long

/* Get of rid system libcdio build configuration */
#define LIBCDIO_CONFIG_H 1

/* Define this if you have mlib installed */
/* #undef LIBMPEG2_MLIB */

/* The soname of libX11, needed for dlopen() */
#define LIBX11_SO "libX11.so"

/* The soname of libXv, needed for dlopen() */
#define LIBXV_SO "libXv.so"

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define this if you want to load mlib lazily */
/* #undef MLIB_LAZYLOAD */

/* Name of package */
#define PACKAGE "xine-lib"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "xine-bugs@lists.sourceforge.net"

/* Define to the full name of this package. */
#define PACKAGE_NAME "xine-lib"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "xine-lib 1.2.6hg"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "xine-lib"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.2.6hg"

/* Default path in which to find Real binary codecs */
/* #undef REAL_CODEC_PATH */

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define this if the compiler supports __attribute__(( ifelse([weak, alias],
   , [alias], [weak, alias]) )) */
/* #undef SUPPORT_ATTRIBUTE_ALIAS */

/* Define this if the compiler supports __attribute__(( ifelse([], , [const],
   []) )) */
#define SUPPORT_ATTRIBUTE_CONST 1

/* Define this if the compiler supports __attribute__(( ifelse([], ,
   [deprecated], []) )) */
#define SUPPORT_ATTRIBUTE_DEPRECATED 1

/* Define this if the compiler supports __attribute__(( ifelse([format(printf,
   n, n)], , [format], [format(printf, n, n)]) )) */
#define SUPPORT_ATTRIBUTE_FORMAT 1

/* Define this if the compiler supports __attribute__((
   ifelse([format_arg(printf)], , [format_arg], [format_arg(printf)]) )) */
#define SUPPORT_ATTRIBUTE_FORMAT_ARG 1

/* Define this if the compiler supports __attribute__(( ifelse([], , [malloc],
   []) )) */
#define SUPPORT_ATTRIBUTE_MALLOC 1

/* Define this if the compiler supports __attribute__(( ifelse([], , [packed],
   []) )) */
#define SUPPORT_ATTRIBUTE_PACKED 1

/* Define this if the compiler supports __attribute__(( ifelse([], ,
   [sentinel], []) )) */
#define SUPPORT_ATTRIBUTE_SENTINEL 1

/* Define this if the compiler supports __attribute__(( ifelse([], , [unused],
   []) )) */
#define SUPPORT_ATTRIBUTE_UNUSED 1

/* Define this if the compiler supports __attribute__((
   ifelse([visibility("default")], , [visibility_default],
   [visibility("default")]) )) */
/* #undef SUPPORT_ATTRIBUTE_VISIBILITY_DEFAULT */

/* Define this if the compiler supports __attribute__((
   ifelse([visibility("internal")], , [visibility_internal],
   [visibility("internal")]) )) */
#define SUPPORT_ATTRIBUTE_VISIBILITY_INTERNAL 1

/* Define this if the compiler supports __attribute__((
   ifelse([visibility("protected")], , [visibility_protected],
   [visibility("protected")]) )) */
#define SUPPORT_ATTRIBUTE_VISIBILITY_PROTECTED 1

/* Define this if the compiler supports __attribute__(( ifelse([], , [weak],
   []) )) */
#define SUPPORT_ATTRIBUTE_WEAK 1

/* Define this if the compiler supports the -fvisibility flag */
#define SUPPORT_FLAG_VISIBILITY 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "1.2.6hg"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Path where aclocal m4 files will be. */
#define XINE_ACFLAGS "-I ${prefix}/share/aclocal"

/* Define this to osd fonts dir location */
#define XINE_FONTDIR "/usr/local/share/xine/libxine1/fonts"

/* Path where catalog files will be. */
#define XINE_LOCALEDIR "/usr/local/share/locale"

/* xine interface version age */
#define XINE_LT_AGE 5

/* xine interface version number */
#define XINE_LT_CURRENT 7

/* Define this if a universal binary is being built for Mac OS X */
/* #undef XINE_MACOSX_UNIVERSAL_BINARY */

/* xine major version number */
#define XINE_MAJOR 1

/* xine minor version number */
#define XINE_MINOR 2

/* xine patch version number */
#define XINE_PATCH 

/* Define this to soecific plugins directory location */
#define XINE_PLUGINDIR "/usr/local/lib/xine/plugins/2.5"

/* Define this to general plugins directory location */
#define XINE_PLUGINROOT "/usr/local/lib/xine/plugins/2"

/* Define this to font directory relative to prefix */
#define XINE_REL_FONTDIR "share/xine/libxine1/fonts"

/* Define this to font directory relative to prefix */
#define XINE_REL_LOCALEDIR "share/locale"

/* Define this to specific plugin directory relative to execution prefix */
#define XINE_REL_PLUGINDIR "lib/xine/plugins/2.5"

/* Define this to general plugin directory relative to execution prefix */
#define XINE_REL_PLUGINROOT "lib/xine/plugins/2"

/* xine sub version number */
#define XINE_SUB 6

/* catalog message text domain */
#define XINE_TEXTDOMAIN "libxine2"

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
#define _FILE_OFFSET_BITS 64

/* Define this if you are ISO C9X compliant */
#define _ISOC9X_SOURCE 1

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#define restrict __restrict
/* Work around a bug in Sun C++: it does not support _Restrict or
   __restrict__, even though the corresponding Sun C compiler ends up with
   "#define restrict _Restrict" or "#define restrict __restrict__" in the
   previous line.  Perhaps some future version of Sun C++ will work with
   restrict; if so, hopefully it defines __RESTRICT like Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
# define __restrict__
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define the real type of socklen_t */
/* #undef socklen_t */

/* define ssize_t to __int64 if it's missing in default includes */
/* #undef ssize_t */

#ifdef ASMALIGN_1SLN
# define ASMALIGN(ZEROBITS) ".align " #ZEROBITS "\n\t"
#else
# define ASMALIGN(ZEROBITS) ".align 1<<" #ZEROBITS "\n\t"
#endif

#endif  /* __XINE_LIB_CONFIG_H__ */



#if defined (__FreeBSD__) && !defined (__FreeBSD_kernel__)
#define __FreeBSD_kernel__ __FreeBSD__
#endif

#if defined (__FreeBSD_kernel__)
#include <sys/param.h>
# if defined (__FreeBSD_version) && !defined (__FreeBSD_kernel_version)
# define __FreeBSD_kernel_version __FreeBSD_version
# endif
#endif


#endif

