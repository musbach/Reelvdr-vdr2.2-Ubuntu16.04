#undef %aptfrontlist
#define %aptfrontlist(cl) %mixin cl "Enumerable"; \
%extend cl { \
    void each() { \
        cl::iterator i = self->begin(); \
	    while (!i.end()) { \
            rb_yield(SWIG_NewPointerObj((void *) i.duplicate(), \
	    	         $descriptor(cl::iterator *), 1)); \
			++i; \
		} \
    } \
}


