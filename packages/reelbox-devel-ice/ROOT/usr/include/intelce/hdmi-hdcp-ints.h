/****************************************************************************
 * Copyright (c) 2008-2011 Intel Corporation.
 *
 * DISTRIBUTABLE AS SAMPLE SOURCE SOFTWARE
 *
 * This Distributable As Sample Source Software is subject to the terms and
 * conditions of the Intel software License Agreement for the Intel(R) Media
 * Processor Software Development Kit.
 ***************************************************************************/

/****************************************************************************
 * Various typedefs for specific-sized integers:
 *   hdcp__i8_t                   8-bit signed integer
 *   hdcp__u8_t                   8-bit unsigned integer
 *   hdcp__i16_t                  16-bit signed integer
 *   hdcp__u16_t                  16-bit unsigned integer
 *   hdcp__i32_t                  32-bit signed integer
 *   hdcp__u32_t                  32-bit unsigned integer
 *   hdcp__i64_t                  64-bit signed integer
 *   hdcp__u64_t                  64-bit unsigned integer
 *
 * Various defines for specifing literal integers:
 *   HDCP__I8(n)                  literal hdcp__i8_t value n
 *   HDCP__U8(n)                  literal hdcp__u8_t value n
 *   HDCP__I16(n)                 literal hdcp__i16_t value n
 *   HDCP__U16(n)                 literal hdcp__u16_t value n
 *   HDCP__I32(n)                 literal hdcp__i32_t value n
 *   HDCP__U32(n)                 literal hdcp__u32_t value n
 *   HDCP__I64(n)                 literal hdcp__i64_t value n
 *   HDCP__U64(n)                 literal hdcp__u64_t value n
 *
 * Various defines for handling big-endian values (byte-swap if we're little
 * endian):
 *   HDCP__BE_I16(n)              big endian 16-bit signed integer
 *   HDCP__BE_U16(n)              big endian 16-bit unsigned integer
 *   HDCP__BE_I32(n)              big endian 32-bit signed integer
 *   HDCP__BE_U32(n)              big endian 32-bit unsigned integer
 *   HDCP__BE_I64(n)              big endian 64-bit signed integer
 *   HDCP__BE_U64(n)              big endian 64-bit unsigned integer
 *
 * Various defines for handling big-endian values (byte-swap if we're big
 * endian):
 *   HDCP__LE_I16(n)              big endian 16-bit signed integer
 *   HDCP__LE_U16(n)              big endian 16-bit unsigned integer
 *   HDCP__LE_I32(n)              big endian 32-bit signed integer
 *   HDCP__LE_U32(n)              big endian 32-bit unsigned integer
 *   HDCP__LE_I64(n)              big endian 64-bit signed integer
 *   HDCP__LE_U64(n)              big endian 64-bit unsigned integer
 *   (note:  HDCP__BIG_ENDIAN must be pre-defined if we are big endian;
 *           otherwise, we assume we are little endian.)
 ***************************************************************************/

#ifndef HDMI_HDCP_INTS_INCLUDED
#define HDMI_HDCP_INTS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__)
    /*  Note:  If you use long long, be aware that it could be 128 bits on a
     *  64-bit compiler.
     */
    #include <inttypes.h>
    typedef int8_t                    hdcp__i8_t;
    typedef uint8_t                   hdcp__u8_t;
    typedef int16_t                   hdcp__i16_t;
    typedef uint16_t                  hdcp__u16_t;
    typedef int32_t                   hdcp__i32_t;
    typedef uint32_t                  hdcp__u32_t;
    typedef int64_t                   hdcp__i64_t;
    typedef uint64_t                  hdcp__u64_t;
    #define HDCP__I8(n)   ((hdcp__i8_t)n)
    #define HDCP__U8(n)   ((hdcp__u8_t)n##U)
    #define HDCP__I16(n)  ((hdcp__i16_t)n)
    #define HDCP__U16(n)  ((hdcp__u16_t)n##U)
    #define HDCP__I32(n)  ((hdcp__i32_t)n##L)
    #define HDCP__U32(n)  ((hdcp__u32_t)n##UL)
    #define HDCP__I64(n)  ((hdcp__i64_t)n##LL)
    #define HDCP__U64(n)  ((hdcp__u64_t)n##ULL)
#elif defined(_MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__)
    typedef __int8                    hdcp__i8_t;
    typedef unsigned __int8           hdcp__u8_t;
    typedef __int16                   hdcp__i16_t;
    typedef unsigned __int16          hdcp__u16_t;
    typedef __int32                   hdcp__i32_t;
    typedef unsigned __int32          hdcp__u32_t;
    typedef __int64                   hdcp__i64_t;
    typedef unsigned __int64          hdcp__u64_t;
    #define HDCP__I8(n)   ((hdcp__i8_t)n)
    #define HDCP__U8(n)   ((hdcp__u8_t)n##U)
    #define HDCP__I16(n)  ((hdcp__i16_t)n)
    #define HDCP__U16(n)  ((hdcp__u16_t)n##U)
    #define HDCP__I32(n)  n##i32
    #define HDCP__U32(n)  n##ui32
    #define HDCP__I64(n)  n##i64
    #define HDCP__U64(n)  n##ui64
#else  /*elif defined(_MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__)*/
    #error integer types for this compiler not implemented in hdmi-hdcp-ints.h
    /*  If I wasn't lazy, I could #include <limits.h> here and write a huge
     *  blob of gunk to cover all the cases.  But I am too lazy.
     */
#endif /* else elif defined(_MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__) */

#ifdef HDCP__BIG_ENDIAN
    #define HDCP__BE_I16(n)       ((hdcp__i16_t)(n))
    #define HDCP__BE_U16(n)       ((hdcp__u16_t)(n))
    #define HDCP__BE_I32(n)       ((hdcp__i32_t)(n))
    #define HDCP__BE_U32(n)       ((hdcp__u32_t)(n))
    #define HDCP__BE_I64(n)       ((hdcp__i64_t)(n))
    #define HDCP__BE_U64(n)       ((hdcp__u64_t)(n))
    #define HDCP__LE_I16(n)       ((hdcp__i16_t)(((n)>>8&0xFF)|(((n)&0xFF)<<8)))
    #define HDCP__LE_U16(n)       ((hdcp__u16_t)(((n)>>8&0xFF)|(((n)&0xFF)<<8)))
    #define HDCP__LE_I32(n)       (((hdcp__i32_t)(((n)>>24&0xFFL)|((n)>>8&0xFF00L)|((n)&0xFF00L)<<8)|(((n)&0xFFL)<<24)))
    #define HDCP__LE_U32(n)       (((hdcp__u32_t)(((n)>>24&0xFFUL)|((n)>>8&0xFF00UL)|((n)&0xFF00UL)<<8)|(((n)&0xFFUL)<<24)))
    #define HDCP__LE_I64(n)       (((hdcp__i64_t)(((n)>>24&0xFFL)|((n)>>8&0xFF00L)|((n)&0xFF00L)<<8)|(((n)&0xFFL)<<24)))
    #define HDCP__LE_U64(n)       (((hdcp__u64_t)(((n)>>24&0xFFUL)|((n)>>8&0xFF00UL)|((n)&0xFF00UL)<<8)|(((n)&0xFFUL)<<24)))
#else  /*  ifdef HDCP__BIG_ENDIAN  */
    #define HDCP__BE_I16(n)       ((hdcp__i16_t)(((n)>>8&0xFF)|(((n)&0xFF)<<8)))
    #define HDCP__BE_U16(n)       ((hdcp__u16_t)(((n)>>8&0xFF)|(((n)&0xFF)<<8)))
    #define HDCP__BE_I32(n)       (((hdcp__i32_t)(((n)>>24&0xFFL)|((n)>>8&0xFF00L)|((n)&0xFF00L)<<8)|(((n)&0xFFL)<<24)))
    #define HDCP__BE_U32(n)       (((hdcp__u32_t)(((n)>>24&0xFFUL)|((n)>>8&0xFF00UL)|((n)&0xFF00UL)<<8)|(((n)&0xFFUL)<<24)))
    #define HDCP__BE_I64(n)       (((hdcp__i64_t)(((n)>>24&0xFFL)|((n)>>8&0xFF00L)|((n)&0xFF00L)<<8)|(((n)&0xFFL)<<24)))
    #define HDCP__BE_U64(n)       (((hdcp__u64_t)(((n)>>24&0xFFUL)|((n)>>8&0xFF00UL)|((n)&0xFF00UL)<<8)|(((n)&0xFFUL)<<24)))
    #define HDCP__LE_I16(n)       ((hdcp__i16_t)(n))
    #define HDCP__LE_U16(n)       ((hdcp__u16_t)(n))
    #define HDCP__LE_I32(n)       ((hdcp__i32_t)(n))
    #define HDCP__LE_U32(n)       ((hdcp__u32_t)(n))
    #define HDCP__LE_I64(n)       ((hdcp__i64_t)(n))
    #define HDCP__LE_U64(n)       ((hdcp__u64_t)(n))
#endif  /*  else ifdef HDCP__BIG_ENDIAN  */

#ifdef __cplusplus
}
#endif

#endif  /*  ndef HDMI_HDCP_INTS_INCLUDED  */
