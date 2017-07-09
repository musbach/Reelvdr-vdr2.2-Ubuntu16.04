#ifndef PKGLIB_PKGCACHE_H
#define PKGLIB_PKGCACHE_H

#include "mmap-apt-pkg.h"
#include "macros-apt-pkg.h"

#include <string>
#include <time.h>

#ifndef APT_8_CLEANER_HEADERS
using std::string;
#endif

class pkgVersioningSystem;
class pkgCache
{
   public:
   // Cache element predeclarations
   struct Header;
   struct Group;
   struct Package;
   struct PackageFile;
   struct Version;
   struct Description;
   struct Provides;
   struct Dependency;
   struct StringItem;
   struct VerFile;
   struct DescFile;
   
   // Iterators
   template<typename Str, typename Itr> class Iterator;
   class GrpIterator;
   class PkgIterator;
   class VerIterator;
   class DescIterator;
   class DepIterator;
   class PrvIterator;
   class PkgFileIterator;
   class VerFileIterator;
   class DescFileIterator;
   
   class Namespace;
   
   // These are all the constants used in the cache structures

   // WARNING - if you change these lists you must also edit
   // the stringification in pkgcache.cc and also consider whether
   // the cache file will become incompatible.
   struct Dep
   {
      enum DepType {Depends=1,PreDepends=2,Suggests=3,Recommends=4,
	 Conflicts=5,Replaces=6,Obsoletes=7,DpkgBreaks=8,Enhances=9};
      enum DepCompareOp {Or=0x10,NoOp=0,LessEq=0x1,GreaterEq=0x2,Less=0x3,
	 Greater=0x4,Equals=0x5,NotEquals=0x6};
   };
   
   struct State
   {
      enum VerPriority {Important=1,Required=2,Standard=3,Optional=4,Extra=5};
      enum PkgSelectedState {Unknown=0,Install=1,Hold=2,DeInstall=3,Purge=4};
      enum PkgInstState {Ok=0,ReInstReq=1,HoldInst=2,HoldReInstReq=3};
      enum PkgCurrentState {NotInstalled=0,UnPacked=1,HalfConfigured=2,
	   HalfInstalled=4,ConfigFiles=5,Installed=6,
           TriggersAwaited=7,TriggersPending=8};
   };
   
   struct Flag
   {
      enum PkgFlags {Auto=(1<<0),Essential=(1<<3),Important=(1<<4)};
      enum PkgFFlags {NotSource=(1<<0),NotAutomatic=(1<<1),ButAutomaticUpgrades=(1<<2)};
   };
   
   protected:
   
   // Memory mapped cache file
   std::string CacheFile;
   MMap &Map;

   unsigned long sHash(const std::string &S) const APT_PURE;
   unsigned long sHash(const char *S) const APT_PURE;
   
   public:
   
   // Pointers to the arrays of items
   Header *HeaderP;
   Group *GrpP;
   Package *PkgP;
   VerFile *VerFileP;
   DescFile *DescFileP;
   PackageFile *PkgFileP;
   Version *VerP;
   Description *DescP;
   Provides *ProvideP;
   Dependency *DepP;
   StringItem *StringItemP;
   char *StrP;

   virtual bool ReMap(bool const &Errorchecks = true);
   inline bool Sync() {return Map.Sync();}
   inline MMap &GetMap() {return Map;}
   inline void *DataEnd() {return ((unsigned char *)Map.Data()) + Map.Size();}
      
   // String hashing function (512 range)
   inline unsigned long Hash(const std::string &S) const {return sHash(S);}
   inline unsigned long Hash(const char *S) const {return sHash(S);}

   // Useful transformation things
   const char *Priority(unsigned char Priority);
   
   // Accessors
   GrpIterator FindGrp(const std::string &Name);
   PkgIterator FindPkg(const std::string &Name);
   PkgIterator FindPkg(const std::string &Name, const std::string &Arch);

   Header &Head() {return *HeaderP;}
   inline GrpIterator GrpBegin();
   inline GrpIterator GrpEnd();
   inline PkgIterator PkgBegin();
   inline PkgIterator PkgEnd();
   inline PkgFileIterator FileBegin();
   inline PkgFileIterator FileEnd();

   inline bool MultiArchCache() const { return MultiArchEnabled; }
   inline char const * NativeArch();

   // Make me a function
   pkgVersioningSystem *VS;
   
   // Converters
   static const char *CompTypeDeb(unsigned char Comp) APT_CONST;
   static const char *CompType(unsigned char Comp) APT_CONST;
   static const char *DepType(unsigned char Dep);
   
   pkgCache(MMap *Map,bool DoMap = true);
   virtual ~pkgCache() {}

private:
   bool MultiArchEnabled;
   PkgIterator SingleArchFindPkg(const std::string &Name);
};

// Header structure
struct pkgCache::Header
{
   unsigned long Signature;
   short MajorVersion;
   short MinorVersion;
   bool Dirty;
   unsigned short HeaderSz;
   unsigned short GroupSz;
   unsigned short PackageSz;
   unsigned short PackageFileSz;
   unsigned short VersionSz;
   unsigned short DescriptionSz;
   unsigned short DependencySz;
   unsigned short ProvidesSz;
   unsigned short VerFileSz;
   unsigned short DescFileSz;

   unsigned long GroupCount;
   unsigned long PackageCount;
   unsigned long VersionCount;
   unsigned long DescriptionCount;
   unsigned long DependsCount;
   unsigned long PackageFileCount;
   unsigned long VerFileCount;
   unsigned long DescFileCount;
   unsigned long ProvidesCount;

   map_ptrloc FileList;
   map_ptrloc StringList;
   map_ptrloc VerSysName;
   map_ptrloc Architecture;
   unsigned long MaxVerFileSize;
   unsigned long MaxDescFileSize;

   DynamicMMap::Pool Pools[9];
   
   map_ptrloc PkgHashTable[2*1048];
   map_ptrloc GrpHashTable[2*1048];

   unsigned long  CacheFileSize;

   bool CheckSizes(Header &Against) const APT_PURE;
   Header();
};

struct pkgCache::Group
{
   map_ptrloc Name;		// StringItem

   // Linked List
   map_ptrloc FirstPackage;	// Package
   map_ptrloc LastPackage;	// Package
   map_ptrloc Next;		// Group
   unsigned int ID;

};
struct pkgCache::Package
{
   map_ptrloc Name;              // StringItem
   map_ptrloc Arch;              // StringItem
   map_ptrloc VersionList;       // Version
   map_ptrloc CurrentVer;        // Version
   map_ptrloc Section;           // StringItem
   map_ptrloc Group;             // Group the Package belongs to

   // Linked list
   map_ptrloc NextPackage;       // Package
   map_ptrloc RevDepends;        // Dependency
   map_ptrloc ProvidesList;      // Provides

   // Install/Remove/Purge etc
   unsigned char SelectedState;     // What
   unsigned char InstState;         // Flags
   unsigned char CurrentState;      // State
   unsigned int ID;
   unsigned long Flags;
};

struct pkgCache::PackageFile
{
   map_ptrloc FileName;        // StringItem
   map_ptrloc Archive;         // StringItem
   map_ptrloc Codename;        // StringItem
   map_ptrloc Component;       // StringItem
   map_ptrloc Version;         // StringItem
   map_ptrloc Origin;          // StringItem
   map_ptrloc Label;           // StringItem
   map_ptrloc Architecture;    // StringItem
   map_ptrloc Site;            // StringItem

   map_ptrloc IndexType;       // StringItem
   unsigned long Size;
   time_t mtime;
   unsigned long Flags;
   // Linked list
   map_ptrloc NextFile;        // PackageFile
   unsigned int ID;
};

struct pkgCache::VerFile
{
   map_ptrloc File;           // PackageFile
   map_ptrloc NextFile;       // PkgVerFile
   map_ptrloc Offset;         // File offset
   unsigned long Size;
};

struct pkgCache::DescFile
{
   map_ptrloc File;           // PackageFile
   map_ptrloc NextFile;       // PkgVerFile
   map_ptrloc Offset;         // File offset
   unsigned long Size;
};

struct pkgCache::Version
{
   map_ptrloc VerStr;            // StringItem
   map_ptrloc Section;           // StringItem
   enum VerMultiArch { None = 0, /*!< is the default and doesn't trigger special behaviour */
		       All = (1<<0), /*!< will cause that Ver.Arch() will report "all" */
		       Foreign = (1<<1), /*!< can satisfy dependencies in another architecture */
		       Same = (1<<2), /*!< can be co-installed with itself from other architectures */
		       Allowed = (1<<3), /*!< other packages are allowed to depend on thispkg:any */
		       AllForeign = All | Foreign,
		       AllAllowed = All | Allowed };
   unsigned char MultiArch;
   map_ptrloc FileList;          // VerFile
   map_ptrloc NextVer;           // Version
   map_ptrloc DescriptionList;   // Description
   map_ptrloc DependsList;       // Dependency
   map_ptrloc ParentPkg;         // Package
   map_ptrloc ProvidesList;      // Provides
   unsigned long long Size;      // These are the .deb size
   unsigned long long InstalledSize;
   unsigned short Hash;
   unsigned int ID;
   unsigned char Priority;
};

struct pkgCache::Description
{
   map_ptrloc language_code;     // StringItem
   map_ptrloc md5sum;            // StringItem
   map_ptrloc FileList;          // DescFile
   map_ptrloc NextDesc;          // Description
   map_ptrloc ParentPkg;         // Package
   unsigned int ID;
};

struct pkgCache::Dependency
{
   map_ptrloc Version;         // StringItem
   map_ptrloc Package;         // Package
   map_ptrloc NextDepends;     // Dependency
   map_ptrloc NextRevDepends;  // Dependency
   map_ptrloc ParentVer;       // Version

   map_ptrloc ID;
   unsigned char Type;
   unsigned char CompareOp;
};

struct pkgCache::Provides
{
   map_ptrloc ParentPkg;        // Package
   map_ptrloc Version;          // Version
   map_ptrloc ProvideVersion;   // StringItem
   map_ptrloc NextProvides;     // Provides
   map_ptrloc NextPkgProv;      // Provides
};

struct pkgCache::StringItem
{
   map_ptrloc String;        // StringItem
   map_ptrloc NextItem;      // StringItem
};


inline char const * pkgCache::NativeArch()
	{ return StrP + HeaderP->Architecture; }

#include <apt-pkg/cacheiterators.h>

inline pkgCache::GrpIterator pkgCache::GrpBegin()
       {return GrpIterator(*this);}
inline pkgCache::GrpIterator pkgCache::GrpEnd()
       {return GrpIterator(*this,GrpP);}
inline pkgCache::PkgIterator pkgCache::PkgBegin()
       {return PkgIterator(*this);}
inline pkgCache::PkgIterator pkgCache::PkgEnd()
       {return PkgIterator(*this,PkgP);}
inline pkgCache::PkgFileIterator pkgCache::FileBegin()
       {return PkgFileIterator(*this,PkgFileP + HeaderP->FileList);}
inline pkgCache::PkgFileIterator pkgCache::FileEnd()
       {return PkgFileIterator(*this,PkgFileP);}

// Oh I wish for Real Name Space Support
class pkgCache::Namespace
{
   public:
   typedef pkgCache::GrpIterator GrpIterator;
   typedef pkgCache::PkgIterator PkgIterator;
   typedef pkgCache::VerIterator VerIterator;
   typedef pkgCache::DescIterator DescIterator;
   typedef pkgCache::DepIterator DepIterator;
   typedef pkgCache::PrvIterator PrvIterator;
   typedef pkgCache::PkgFileIterator PkgFileIterator;
   typedef pkgCache::VerFileIterator VerFileIterator;
   typedef pkgCache::Version Version;
   typedef pkgCache::Description Description;
   typedef pkgCache::Package Package;
   typedef pkgCache::Header Header;
   typedef pkgCache::Dep Dep;
   typedef pkgCache::Flag Flag;
};

#endif
