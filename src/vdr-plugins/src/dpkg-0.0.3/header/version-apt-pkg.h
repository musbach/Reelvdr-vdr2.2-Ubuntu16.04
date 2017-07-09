#ifndef PKGLIB_VERSION_H
#define PKGLIB_VERSION_H

//#include "strutl-apt-pkg.h.org"
#include "strutl-apt-pkg.h"
//#include <apt-pkg/strutl.h>
#include <string>

#ifndef APT_8_CLEANER_HEADERS
using std::string;
#endif

class pkgVersioningSystem
{
   public:
   static pkgVersioningSystem **GlobalList;
   static unsigned long GlobalListLen;
   static pkgVersioningSystem *GetVS(const char *Label) APT_PURE;
   
   const char *Label;
   
   virtual int DoCmpVersion(const char *A,const char *Aend,
			  const char *B,const char *Bend) = 0;   

   virtual bool CheckDep(const char *PkgVer,int Op,const char *DepVer) = 0;
   virtual int DoCmpReleaseVer(const char *A,const char *Aend,
			       const char *B,const char *Bend) = 0;
   virtual std::string UpstreamVersion(const char *A) = 0;
   
   virtual bool TestCompatibility(pkgVersioningSystem const &Against) 
                {return this == &Against;};

   APT_MKSTRCMP(CmpVersion,DoCmpVersion);
   APT_MKSTRCMP(CmpReleaseVer,DoCmpReleaseVer);
   
   pkgVersioningSystem();
   virtual ~pkgVersioningSystem() {};
};

#endif
