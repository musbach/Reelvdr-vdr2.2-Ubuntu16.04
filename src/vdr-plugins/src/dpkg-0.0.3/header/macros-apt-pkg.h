// Private header
#ifndef MACROS_H
#define MACROS_H

// MIN_VAL(SINT16) will return -0x8000 and MAX_VAL(SINT16) = 0x7FFF
#define	MIN_VAL(t)	(((t)(-1) > 0) ? (t)( 0) : (t)(((1L<<(sizeof(t)*8-1))  )))
#define	MAX_VAL(t)	(((t)(-1) > 0) ? (t)(-1) : (t)(((1L<<(sizeof(t)*8-1))-1)))

// Min/Max functions
#if !defined(MIN)
#if defined(__HIGHC__)
#define MIN(x,y) _min(x,y)
#define MAX(x,y) _max(x,y)
#endif

// GNU C++ has a min/max operator <coolio>
#if defined(__GNUG__)
#define MIN(A,B) ((A) <? (B))
#define MAX(A,B) ((A) >? (B))
#endif

#if !defined(MIN)
#define MIN(A,B) ((A) < (B)?(A):(B))
#define MAX(A,B) ((A) > (B)?(A):(B))
#endif
#endif

#define _bound(a,b,c) MIN(c,MAX(b,a))
#define _boundv(a,b,c) b = _bound(a,b,c)
#define ABS(a) (((a) < (0)) ?-(a) : (a))

#define _count(a) (sizeof(a)/sizeof(a[0]))

// Flag Macros
#define	FLAG(f)			(1L << (f))
#define	SETFLAG(v,f)	((v) |= FLAG(f))
#define CLRFLAG(v,f)	((v) &=~FLAG(f))
#define	CHKFLAG(v,f)	((v) &  FLAG(f) ? true : false)

#ifdef __GNUC__
#define APT_GCC_VERSION (__GNUC__ << 8 | __GNUC_MINOR__)
#else
#define APT_GCC_VERSION 0
#endif

#if APT_GCC_VERSION >= 0x0300
	#define likely(x)	__builtin_expect (!!(x), 1)
	#define unlikely(x)	__builtin_expect (!!(x), 0)
#else
	#define likely(x)	(x)
	#define unlikely(x)	(x)
#endif

#if APT_GCC_VERSION >= 0x0300
	#define APT_DEPRECATED	__attribute__ ((deprecated))
	#define APT_CONST	__attribute__((const))
	#define APT_PURE	__attribute__((pure))
	#define APT_NORETURN	__attribute__((noreturn))
//	#define APT_PRINTF(n)	__attribute__((format(printf,n,n+1)))
#else
	#define APT_DEPRECATED
	#define APT_CONST
	#define APT_PURE
	#define APT_NORETURN
	#define APT_PRINTF(n)
#endif

#if APT_GCC_VERSION > 0x0302
	#define APT_NONNULL(...)	__attribute__((nonnull(__VA_ARGS__)))
	#define APT_MUSTCHECK		__attribute__((warn_unused_result))
#else
	#define APT_NONNULL(...)
	#define APT_REQRET
#endif

#if APT_GCC_VERSION >= 0x0400
	#define APT_SENTINEL	__attribute__((sentinel))
	#define APT_PUBLIC __attribute__ ((visibility ("default")))
	#define APT_HIDDEN __attribute__ ((visibility ("hidden")))
#else
	#define APT_SENTINEL
	#define APT_PUBLIC
	#define APT_HIDDEN
#endif

// cold functions are unlikely() to be called
#if APT_GCC_VERSION >= 0x0403
//	#define APT_COLD	__attribute__ ((__cold__))
	#define APT_HOT		__attribute__ ((__hot__))
#else
	#define APT_COLD
	#define APT_HOT
#endif

#ifndef APT_10_CLEANER_HEADERS
#if APT_GCC_VERSION >= 0x0300
	#define __must_check	__attribute__ ((warn_unused_result))
	#define __deprecated	__attribute__ ((deprecated))
	#define __attrib_const	__attribute__ ((__const__))
	#define __like_printf(n)	__attribute__((format(printf, n, n + 1)))
#else
	#define __must_check	/* no warn_unused_result */
	#define __deprecated	/* no deprecated */
	#define __attrib_const	/* no const attribute */
	#define __like_printf(n)	/* no like-printf */
#endif
#if APT_GCC_VERSION >= 0x0403
	#define __cold	__attribute__ ((__cold__))
	#define __hot	__attribute__ ((__hot__))
#else
	#define __cold	/* no cold marker */
	#define __hot	/* no hot marker */
#endif
#endif

// These lines are extracted by the makefiles and the buildsystem
// Increasing MAJOR or MINOR results in the need of recompiling all
// reverse-dependencies of libapt-pkg against the new SONAME.
// Non-ABI-Breaks should only increase RELEASE number.
// See also buildlib/libversion.mak
#define APT_PKG_MAJOR 4
#define APT_PKG_MINOR 12
#define APT_PKG_RELEASE 0

#endif