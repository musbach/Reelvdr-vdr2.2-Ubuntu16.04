#include "error-apt-pkg.h"
#include <stdexcept>

#ifndef APTFRONT_ERROR_H
#define APTFRONT_ERROR_H

class GlobalError;

namespace aptFront {

GlobalError *getGlobalError();
namespace exception {

template <typename T>
void checkGlobal(T x) {
    if(_error->PendingError() == true)
        throw x;
}

struct Exception : public std::exception {
    Exception( std::string msg = "unspecified problem" ) : m_message( msg ) {}
    virtual ~Exception() throw() {}

    virtual const char *what() const throw() {
        return message().c_str(); }

    virtual const std::string message() const {
        return std::string(prefix()).append(m_message); }

    virtual const std::string prefix() const {
        return "EXCEPTION: "; }

    virtual const std::string additionalData() const {
        return ""; }

protected:
    std::string m_message;
};

struct Error : public Exception {
    Error(std::string err) : Exception( err ) {}
    const std::string prefix() const {
        return "ERROR: "; }
    const std::string additionalData() const {
        std::string ret; std::string tmp;
        while(getGlobalError()->PendingError()) {
            getGlobalError()->PopMessage(tmp);
            ret.append(tmp);
            // ret.append("\n");
        }
        return ret;
    }
};

struct InternalError : public Error {
    InternalError( std::string s ) : Error( s ) {}
    const std::string prefix() const {
        return "INTERNAL ERROR: "; }
};

struct NotImplemented : public InternalError {
    NotImplemented( std::string s ) : InternalError( s ) {}
    const std::string prefix() const {
        return "INTERNAL ERROR: Feature not implemented: "; }
};

}

}

#endif
