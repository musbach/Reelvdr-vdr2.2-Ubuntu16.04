/** -*- C++ -*-
	@file init.h
	@author Peter Rockai <me@mornfall.net>
*/

#ifndef APTFRONT_INIT_H
#define APTFRONT_INIT_H
#include <deque>

namespace aptFront {

void init();

struct Init {
    typedef void (*Function)( void );
    typedef std::deque<Function> FunctionDeque;
    static FunctionDeque *s_functions;
    static bool s_globalDone;
    static bool s_done;
    Init( Function f ) {
        if (!s_functions)
            s_functions = new FunctionDeque();
        s_functions->push_back( f );
    }
};

}

#endif
