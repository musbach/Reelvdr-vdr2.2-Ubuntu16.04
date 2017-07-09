#ifndef APT_FRONT_WORKAROUNDS_H
#define APT_FRONT_WORKAROUNDS_H

#ifdef APTFRONT_WORKAROUND_POLICY
#ifdef PKGLIB_POLICY_H
#error Broken policy.h from apt included, please include apt-front/workarounds.h first
#endif

#include <apt-front/workarounds/policy.h>

#endif
#endif
