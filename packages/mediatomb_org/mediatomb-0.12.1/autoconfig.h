/* autoconfig.h.  Generated from autoconfig.h.in by configure.  */
/* autoconfig.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* NEVER use this! This is only for devel/debugging - disables all atomic
   arithmetics code. */
/* #undef ATOMIC_TORTURE */

/* use x86 assembler code for atomic arithmetic operations that will only work
   oni singleprocessor systems - compiled binary will be buggy on SMP */
/* #undef ATOMIC_X86 */

/* use x86 assembler code for atomic arithmetic operations - default for SMP
   and UP systems */
#define ATOMIC_X86_SMP 1

/* Enable support for the apple trailers */
/* #undef ATRAILERS */

/* create database automatically if it does not exist */
#define AUTO_CREATE_DATABASE 1

/* ffmpeg/avformat.h */
#define AVFORMAT_INCLUDE <libavformat/avformat.h>

/* Define to 1 if the `closedir' function returns void instead of `int'. */
/* #undef CLOSEDIR_VOID */

/* compile option summary */
#define COMPILE_INFO "\thost:\t\t\ti686-pc-linux-gnu\n\tsqlite3:\t\tyes\n\tmysql:\t\t\tyes\n\tlibjs:\t\t\tmissing\n\tlibmagic:\t\tmissing\n\tinotify:\t\tyes\n\tlibexif:\t\tyes\n\tid3lib:\t\t\tdisabled\n\ttaglib:\t\t\tyes\n\tffmpeg\t\t\tyes\n\tlibmp4v2:\t\tmissing\n\texternal transcoding:\tyes\n\tcurl:\t\t\tyes\n\tYouTube:\t\tyes\n\tlibextractor\t\tdisabled\n\tdb-autocreate:\t\tyes\n\tdebug log:\t\tyes\n\tprotocol info extension:yes\n\tffmpegthumbnailer:\tmissing\n\tlastfmlib:\t\tmissing\n\tdata directory:\t\t/usr/share/mediatomb"

/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP
   systems. This function is required for `alloca.c' support on those systems.
   */
/* #undef CRAY_STACKSEG_END */

/* Define to 1 if using `alloca.c'. */
/* #undef C_ALLOCA */

/* Define to 1 to compile debug code */
/* #undef DEBUG */

/* compile with debug messages */
#define DEBUG_LOG_ENABLED 1

/* debug: abort on malloc/realloc of zero bytes */
/* #undef DEBUG_MALLOC_0 */

/* Enable the X_MS_MediaReceiverRegistrar UPnP service. This is for future
   XBox 360 support, other renderers will probably not need it */
/* #undef ENABLE_MRREG */

/* enable SIGHUP handling */
#define ENABLE_SIGHUP 1

/* exif_entry_get_value() has 1 parameter */
/* #undef EXIF_EGV_1 */

/* exif_entry_get_value() has 3 parameters */
#define EXIF_EGV_3 1

/* This is required for Playstation 3 support, it adds certain tags to the
   protocolInfo attribute */
#define EXTEND_PROTOCOLINFO 1

/* external transcoding feature */
#define EXTERNAL_TRANSCODING 1

/* use ffmpegthumbnailer API */
/* #undef FFMPEGTHUMBNAILER_OLD_API */

/* Define to 1 if you have `alloca', as a function or macro. */
#define HAVE_ALLOCA 1

/* Define to 1 if you have <alloca.h> and it should be used (not on Ultrix).
   */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <attachedpictureframe.h> header file. */
#define HAVE_ATTACHEDPICTUREFRAME_H 1

/* Define to 1 if you have the <audioproperties.h> header file. */
#define HAVE_AUDIOPROPERTIES_H 1

/* Define to 1 if you have the `backtrace' function. */
#define HAVE_BACKTRACE 1

/* Define to 1 if you have the `backtrace_symbols' function. */
#define HAVE_BACKTRACE_SYMBOLS 1

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H 1

/* curl library presence */
#define HAVE_CURL 1

/* Define to 1 if you have the <curl/curl.h> header file. */
#define HAVE_CURL_CURL_H 1

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define to 1 if you have the <execinfo.h> header file. */
#define HAVE_EXECINFO_H 1

/* expat library presence */
#define HAVE_EXPAT 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* FFMPEG library presence */
#define HAVE_FFMPEG 1

/* ffmpegthumbnailer library presence */
/* #undef HAVE_FFMPEGTHUMBNAILER */

/* Define to 1 if you have the <fileref.h> header file. */
#define HAVE_FILEREF_H 1

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* Define to 1 if you have the `gethostbyname' function. */
#define HAVE_GETHOSTBYNAME 1

/* Define to 1 if you have the `gethostbyname_r' function. */
#define HAVE_GETHOSTBYNAME_R 1

/* Define to 1 if you have the `gethostname' function. */
#define HAVE_GETHOSTNAME 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* id3lib library presence */
/* #undef HAVE_ID3LIB */

/* this version of id3lib has album art support */
#define HAVE_ID3_ALBUMART 1

/* Define to 1 if you have the `if_freenameindex' function. */
#define HAVE_IF_FREENAMEINDEX 1

/* Define to 1 if you have the `if_nameindex' function. */
#define HAVE_IF_NAMEINDEX 1

/* Define to 1 if you have the `inet_ntoa' function. */
#define HAVE_INET_NTOA 1

/* inotify presence */
#define HAVE_INOTIFY 1

/* Define to 1 if you have the `inotify_init' function. */
#define HAVE_INOTIFY_INIT 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `ioctl' function. */
#define HAVE_IOCTL 1

/* libjs presence */
/* #undef HAVE_JS */

/* Define to 1 if you have the <langinfo.h> header file. */
#define HAVE_LANGINFO_H 1

/* lastfmlib library presence */
/* #undef HAVE_LASTFMLIB */

/* Define to 1 if you have the `' library (-l). */
/* #undef HAVE_LIB */

/* Define to 1 if you have the `curl' library (-lcurl). */
#define HAVE_LIBCURL 1

/* libexif library presence */
#define HAVE_LIBEXIF 1

/* libextractor library presence */
/* #undef HAVE_LIBEXTRACTOR */

/* we are using the libiconv library */
/* #undef HAVE_LIBICONV */

/* lwres library presence */
/* #undef HAVE_LIBLWRES */

/* libmagic library presence */
/* #undef HAVE_LIBMAGIC */

/* libmp4v2 library presence */
/* #undef HAVE_LIBMP4V2 */

/* Define to 1 if you have the `nsl' library (-lnsl). */
/* #undef HAVE_LIBNSL */

/* Define to 1 if you have the `socket' library (-lsocket). */
/* #undef HAVE_LIBSOCKET */

/* Define to 1 if you have the `tag' library (-ltag). */
#define HAVE_LIBTAG 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the `localtime_r' function. */
#define HAVE_LOCALTIME_R 1

/* LONG_MAX definition available */
#define HAVE_LONG_MAX 1

/* Define to 1 if you have the <lwres/netdb.h> header file. */
/* #undef HAVE_LWRES_NETDB_H */

/* filemagic library presence */
/* #undef HAVE_MAGIC */

/* Define to 1 if you have the `main' function. */
/* #undef HAVE_MAIN */

/* Define to 1 if your system has a GNU libc compatible `malloc' function, and
   to 0 otherwise. */
#define HAVE_MALLOC 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the `mkdir' function. */
#define HAVE_MKDIR 1

/* Define to 1 if you have the `mkfifo' function. */
#define HAVE_MKFIFO 1

/* this version of libmp4v2 has MP4GetMetadataCoverArtCount() support */
/* #undef HAVE_MP4_GET_METADATA_COVER_ART_COUNT */

/* this version of libmp4 has MP4GetTrackAudioChannels support */
/* #undef HAVE_MP4_GET_TRACK_AUDIO_CHANNELS */

/* MySQL library presence */
#define HAVE_MYSQL 1

/* Define to 1 if you have the <mysql.h> header file. */
#define HAVE_MYSQL_H 1

/* Define to 1 if you have the `mysql_init' function. */
#define HAVE_MYSQL_INIT 1

/* MYSQL_OPT_RECONNECT parameter available */
#define HAVE_MYSQL_OPT_RECONNECT 1

/* Define to 1 if you have the `mysql_stmt_init' function. */
#define HAVE_MYSQL_STMT_INIT 1

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the `nl_langinfo' function. */
#define HAVE_NL_LANGINFO 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Define to 1 if your system has a GNU libc compatible `realloc' function,
   and to 0 otherwise. */
#define HAVE_REALLOC 1

/* Define to 1 if you have the `regcomp' function. */
#define HAVE_REGCOMP 1

/* Define to 1 if you have the `sched_getparam' function. */
#define HAVE_SCHED_GETPARAM 1

/* Define to 1 if you have the `sched_get_priority_max' function. */
#define HAVE_SCHED_GET_PRIORITY_MAX 1

/* Define to 1 if you have the `sched_get_priority_min' function. */
#define HAVE_SCHED_GET_PRIORITY_MIN 1

/* Define to 1 if you have the <sched.h> header file. */
#define HAVE_SCHED_H 1

/* Define to 1 if you have the `sched_setparam' function. */
#define HAVE_SCHED_SETPARAM 1

/* Define to 1 if you have the `select' function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the `sigaction' function. */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the `sigprocmask' function. */
#define HAVE_SIGPROCMASK 1

/* Define to 1 if you have the `socket' function. */
#define HAVE_SOCKET 1

/* sqlite3 library presence */
#define HAVE_SQLITE3 1

/* Define to 1 if `stat' has the bug that it succeeds when given the
   zero-length file name argument. */
/* #undef HAVE_STAT_EMPTY_STRING_BUG */

/* Define to 1 if stdbool.h conforms to C99. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the `strerror_r' function. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strrchr' function. */
#define HAVE_STRRCHR 1

/* Define to 1 if you have the `strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoll' function. */
#define HAVE_STRTOLL 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/file.h> header file. */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/utsname.h> header file. */
#define HAVE_SYS_UTSNAME_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* taglib library presence */
#define HAVE_TAGLIB 1

/* Define to 1 if you have the <taglib.h> header file. */
#define HAVE_TAGLIB_H 1

/* Define to 1 if you have the <tag.h> header file. */
#define HAVE_TAG_H 1

/* Define to 1 if you have the <textidentificationframe.h> header file. */
#define HAVE_TEXTIDENTIFICATIONFRAME_H 1

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if the system has the type `time_t'. */
#define HAVE_TIME_T 1

/* Define to 1 if you have the `tolower' function. */
#define HAVE_TOLOWER 1

/* Define to 1 if you have the `toupper' function. */
#define HAVE_TOUPPER 1

/* Define to 1 if you have the <tstring.h> header file. */
#define HAVE_TSTRING_H 1

/* Define to 1 if you have the `uname' function. */
#define HAVE_UNAME 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `vfork' function. */
#define HAVE_VFORK 1

/* Define to 1 if you have the <vfork.h> header file. */
/* #undef HAVE_VFORK_H */

/* Define to 1 if you have the `vprintf' function. */
#define HAVE_VPRINTF 1

/* Define to 1 if `fork' works. */
#define HAVE_WORKING_FORK 1

/* Define to 1 if `vfork' works. */
#define HAVE_WORKING_VFORK 1

/* zlib library presence */
#define HAVE_ZLIB 1

/* Define to 1 if the system has the type `_Bool'. */
#define HAVE__BOOL 1

/* iconv needs const char cast */
#define ICONV_CONST 1

/* this version of spidermonkey is threadsafe */
/* #undef JS_THREADSAFE */

/* $MP4_HEADER.h */
/* #undef LIBMP4V2_INCLUDE */

/* if defined compile with log output */
#define LOG_ENABLED 1

/* Define to 1 if `lstat' dereferences a symlink specified with a trailing
   slash. */
#define LSTAT_FOLLOWS_SLASHED_SYMLINK 1

/* LLONG_MAX not available */
#define MAXLLONG LLONG_MAX

/* make sure there are no asserts in the retail build */
#define NDEBUG 1

/* at least one online service is supported */
#define ONLINE_SERVICES 1

/* Name of package */
#define PACKAGE "mediatomb"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "jin@mediatomb.cc"

/* MediaTomb data directory */
#define PACKAGE_DATADIR "/usr/share/mediatomb"

/* Define to the full name of this package. */
#define PACKAGE_NAME "MediaTomb"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "MediaTomb 0.12.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "mediatomb"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.12.1"

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to the type of arg 1 for `select'. */
#define SELECT_TYPE_ARG1 int

/* Define to the type of args 2, 3 and 4 for `select'. */
#define SELECT_TYPE_ARG234 (fd_set *)

/* Define to the type of arg 5 for `select'. */
#define SELECT_TYPE_ARG5 (struct timeval *)

/* The size of `off_t', as computed by sizeof. */
#define SIZEOF_OFF_T 8

/* The size of `size_t', as computed by sizeof. */
#define SIZEOF_SIZE_T 4

/* The size of `time_t', as computed by sizeof. */
#define SIZEOF_TIME_T 4

/* The size of `unsigned int', as computed by sizeof. */
#define SIZEOF_UNSIGNED_INT 4

/* The size of `unsigned long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG 4

/* we are on solaris */
/* #undef SOLARIS */

/* Enable support for the SopCast service */
/* #undef SOPCAST */

/* enable sqlite db backup settings in config.xml by default */
/* #undef SQLITE_BACKUP_ENABLED */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if the `S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if strerror_r returns char *. */
/* #undef STRERROR_R_CHAR_P */

/* sys/inotify.h exists */
#define SYS_INOTIFY_H_OK 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* if defined compile with debug log output */
/* #undef TOMBDEBUG */

/* see upnpconfig.h */
/* #undef UPNP_HAVE_DEBUG */

/* Compile device API */
#define UPNP_HAVE_DEVICE 1

/* Compile internal web server */
#define UPNP_HAVE_WEBSERVER 1

/* see upnpconfig.h */
#define UPNP_VERSION_MAJOR 0

/* see upnpconfig.h */
#define UPNP_VERSION_MINOR 4

/* see upnpconfig.h */
#define UPNP_VERSION_PATCH 1

/* see upnpconfig.h */
#define UPNP_VERSION_STRING "0.12.1"

/* Version number of package */
#define VERSION "0.12.1"

/* Enable support for the Weborama service */
/* #undef WEBORAMA */

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

/* Enable support for the YouTube service */
#define YOUTUBE 1

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
#define _FILE_OFFSET_BITS 64

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define for Solaris 2.5.1 so the uint32_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT32_T */

/* needed for stdint.h */
#define __STDC_CONSTANT_MACROS 1

/* needed for stdint.h */
#define __STDC_LIMIT_MACROS 1

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* fseeko not present */
/* #undef fseeko */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to the type of a signed integer type of width exactly 64 bits if
   such a type exists and the standard includes do not define it. */
/* #undef int64_t */

/* Define to rpl_malloc if the replacement function should be used. */
/* #undef malloc */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to rpl_realloc if the replacement function should be used. */
/* #undef realloc */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef ssize_t */

/* Define to the type of an unsigned integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint32_t */

/* Define as `fork' if `vfork' does not work. */
/* #undef vfork */

/* Define to empty if the keyword `volatile' does not work. Warning: valid
   code using `volatile' can become incorrect without. Disable with care. */
/* #undef volatile */
