/** -*- C++ -*-
	@file progresscallback.h
	@author Michael Vogt <mvo@debian.org>
*/

#ifndef APT_FRONT_COMMITPROGRESS_H
#define APT_FRONT_COMMITPROGRESS_H

#include<apt-pkg/acquire.h>
#include<apt-front/utils/shared.h>

namespace aptFront {

class ProgressCallback : public pkgAcquireStatus, public SharedBase
{
protected:
    virtual bool Pulse(pkgAcquire *Owner);
public:
    ProgressCallback() {};
    virtual ~ProgressCallback() {};
    virtual bool MediaChange(string Media,string Drive) { return false; } // bah
    
    // override this to get periodic updates
    virtual void UpdatePulse(double FetchedBytes, double CurrentCPS,
                             unsigned long CurrentItems) {};
};

}



#endif
