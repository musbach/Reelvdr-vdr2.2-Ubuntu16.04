#include "progresscallback.h"

namespace aptFront {

   bool ProgressCallback::Pulse(pkgAcquire *Owner)
   {
      pkgAcquireStatus::Pulse(Owner);
      UpdatePulse(FetchedBytes, CurrentCPS, CurrentItems);
      return true;
   }

}
