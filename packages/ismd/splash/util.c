//-----------------------------------------------------------------------------
// BSD LICENSE
//
// Copyright(c) 2006-2011 Intel Corporation. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   - Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   - Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in
//     the documentation and/or other materials provided with the
//     distribution.
//   - Neither the name of Intel Corporation nor the names of its
//     contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <libgdl.h>
#include "util.h"

gdl_ret_t check(int exitOnFailure, gdl_ret_t gdl_rc, const char *file, int line)
{
    if (gdl_rc != GDL_SUCCESS)
    {
        fprintf(stderr, "GDL ERROR %d (%s) returned at line %s:%d\n",
                gdl_rc,
                gdl_get_error_string(gdl_rc),
                file,
                line);
        if (exitOnFailure)
        {
            exit(gdl_rc);
        }
    }
    return gdl_rc;
}


#include <sys/time.h>
static struct timeval begin;

// Subtract the 'struct timeval' values begin from end, storing result in RESULT
// Return 1 if the difference is negative, otherwise 0.
static
int timeval_subtract(  struct timeval *result,
                       struct timeval *end,
                       struct timeval *begin)
{
    // Perform the carry for the later subtraction by updating Y
    if (end->tv_usec < begin->tv_usec) {
        int nsec = (begin->tv_usec - end->tv_usec) / 1000000 + 1;
        begin->tv_usec -= 1000000 * nsec;
        begin->tv_sec += nsec;
    }
    if (end->tv_usec - begin->tv_usec > 1000000) {
        int nsec = (end->tv_usec - begin->tv_usec) / 1000000;
        begin->tv_usec += 1000000 * nsec;
        begin->tv_sec -= nsec;
    }

    // Compute the time remaining to wait. 'tv_usec' is certainly positive.
    result->tv_sec = end->tv_sec - begin->tv_sec;
    result->tv_usec = end->tv_usec - begin->tv_usec;

    // Return 1 if result is negative
    return end->tv_sec < begin->tv_sec;
}

void start_timing(void)
{
    gettimeofday(&begin, NULL);
}

double end_timing(void)
{
    struct timeval end;
    struct timeval diff;
    int    sign;
    double secs;

    gettimeofday(&end, NULL);
    sign = timeval_subtract(&diff, &begin, &end);
    secs = (double)(diff.tv_sec) + ((double)diff.tv_usec / 1000000.);
    return sign ? -secs : secs;
}
