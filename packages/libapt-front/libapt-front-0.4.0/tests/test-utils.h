/** -*- C++ -*-
 * @file test-utils.h
 * @author Peter Rockai <me@mornfall.net>
 * @brief Utility functions for the unit tests
 */
#include <tut.h>
#include <iostream>

/* struct iterator_shar {
};*/
#define TESTGRP(name) \
typedef test_group<name ## _shar> tg; \
typedef tg::object to; \
tg name ## _tg (#name);

#if 0 // maybe someday...
#define TEST(n, str) \
template<> struct test_traits< typeof to, n > \
{ static const char *name() { return str; } }; \
template<> template<> void to::test<n> ()

#define TESTN(n) TEST(n, "unnamed")
#endif

template< typename T, int N > struct test_traits {};

inline static std::string __ensure_errmsg(std::string f, int l, std::string msg)
{
    char buf[64];
    snprintf(buf, 63, "%d", l);
    buf[63] = 0;
    std::string ln = buf;
    f.append(": ");
    f.append(ln);
    f.append(": '");
    f.append(msg);
    f.append("'");
    return f;
}
#define ensure(x) ensure (__ensure_errmsg(__FILE__, __LINE__, #x).c_str(), (x))

namespace tut {

void debtagsInit();
void aptInit();

}
