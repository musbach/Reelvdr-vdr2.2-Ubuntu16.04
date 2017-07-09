#ifndef TUT_REPORTER
#define TUT_REPORTER

#include <tut.h>

/**
 * Template Unit Tests Framework for C++.
 * http://tut.dozen.ru
 *
 * @author dozen, tut@dozen.ru
 */
namespace
{
std::ostream& operator << (std::ostream& os,const tut::test_result& tr)
{

    return os;
}
}

namespace tut
{

#ifdef TUT_COLORS
const char *c_red = "\e[31;1m";
const char *c_green = "\e[32;1m";
const char *c_norm = "\e[0m";
#else
const char *c_red = "";
const char *c_green = "";
const char *c_norm = "";
#endif
/**
 * Default TUT callback handler.
 */
class reporter : public tut::callback
{
    std::string current_group;
    typedef std::vector<tut::test_result> not_passed_list;
    not_passed_list not_passed;
    std::ostream& os;

public:
    int ok_count;
    int exceptions_count;
    int failures_count;
    int terminations_count;
    int warnings_count;

    reporter() : os(std::cout)
        {
            init();
        }

    reporter(std::ostream& out) : os(out)
        {
            init();
        }

    void run_started()
        {
            init();
        }

    void print_failure( const tut::test_result &tr ) {
        os << "---> " << "test: " << tr.group << ", test<" << tr.test << ">" << std::endl;
          
        os << "     problem: ";
        switch(tr.result)
        {
        case tut::test_result::fail: 
            os << c_red <<"assertion failed" << c_norm << std::endl; 
            break;
        case tut::test_result::ex: 
            os << "unexpected exception" << std::endl;
            if( tr.exception_typeid != "" )
            { 
                os << "     exception typeid: " 
                   << tr.exception_typeid << std::endl;
            }
            break;
        case tut::test_result::term: 
            os << "would be terminated" << std::endl; 
            break;
        case tut::test_result::warn: 
            os << "test passed, but cleanup code (destructor) raised an exception" << std::endl; 
            break;
        default: break;
        }
          
        if( tr.message != "" )
        {
            if( tr.result == tut::test_result::fail )
            {
                os << "     failed assertion: " << c_red << '"'
                   << tr.message << '"' << c_norm;
            }
            else
            {
                os << "     message: " << c_red << '"'
                   << tr.message << '"' << c_norm;
            }
        }
    }

    void test_completed(const tut::test_result& tr)
        {
            static bool need_head = true;
            static int tests = 0;
            if( tr.group != current_group )
            {
                tests = 0;
                need_head = true;
                current_group = tr.group;
            }

            if (need_head) {
                need_head = false;
                os << std::endl << tr.group << ": " << std::flush;
            }

            ++tests;
            if (tests > 8) {
                need_head = true;
                tests = 0;
            }

            os << tr << std::flush;
            if( tr.result == tut::test_result::ok ) ok_count++;
            else if( tr.result == tut::test_result::ex ) exceptions_count++;
            else if( tr.result == tut::test_result::fail ) failures_count++;
            else if( tr.result == tut::test_result::warn ) warnings_count++;
            else terminations_count++;
        
            if (tr.result == test_result::ok) {
                float t = tr.time / 100.0;
                os << "" << c_green << tr.test << c_norm << "; " << std::flush; 
            } else {
                need_head = true;
                os << std::endl;
                not_passed.push_back(tr);
                print_failure( tr );
                os << std::flush;
            }
        }
      
    void run_completed()
        {
            os << std::endl;

            if( not_passed.size() > 0 )
            {
                os << std::endl;
                os << "----------------------------" << std::endl;
                not_passed_list::const_iterator i = not_passed.begin();
                while( i != not_passed.end() )
                {
                    tut::test_result tr = *i;
                    print_failure( tr );
                    os << std::endl;
                    ++i;
                }
            }
      
            os << std::endl;

            os << "tests summary:";
            if( terminations_count > 0 ) os << " terminations:" << terminations_count;
            if( exceptions_count > 0 ) os << " exceptions:" << exceptions_count;
            /* if( failures_count > 0 ) */ os << " failures:" << failures_count;
            /* if( warnings_count > 0 ) */ os << " warnings:" << warnings_count;
            os << " ok:" << ok_count;
            os << std::endl;
        }

    bool all_ok() const
        {
            return not_passed.size() == 0;
        }

private:
    void init()
        {
            ok_count = 0;
            exceptions_count = 0;  
            failures_count = 0;
            terminations_count = 0;
            warnings_count = 0;

            not_passed.clear();
        }    
};
};

#endif
