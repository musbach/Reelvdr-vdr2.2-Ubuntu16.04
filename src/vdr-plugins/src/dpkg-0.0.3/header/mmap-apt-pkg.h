#ifndef PKGLIB_MMAP_H
#define PKGLIB_MMAP_H


#include <string>

#ifndef APT_8_CLEANER_HEADERS
#include "fileutl-apt-pkg.h"
using std::string;
#endif

class FileFd;

typedef unsigned int map_ptrloc;

class MMap
{
   protected:
   
   unsigned long Flags;
   unsigned long long iSize;
   void *Base;

   // In case mmap can not be used, we keep a dup of the file
   // descriptor that should have been mmaped so that we can write to
   // the file in Sync().
   FileFd *SyncToFd;

   bool Map(FileFd &Fd);
   bool Close(bool DoSync = true);
   
   public:

   enum OpenFlags {NoImmMap = (1<<0),Public = (1<<1),ReadOnly = (1<<2),
                   UnMapped = (1<<3), Moveable = (1<<4), Fallback = (1 << 5)};
      
   // Simple accessors
   inline operator void *() {return Base;};
   inline void *Data() {return Base;}; 
   inline unsigned long long Size() {return iSize;};
   inline void AddSize(unsigned long long const size) {iSize += size;};
   inline bool validData() const { return Base != (void *)-1 && Base != 0; };
   
   // File manipulators
   bool Sync();
   bool Sync(unsigned long Start,unsigned long Stop);
   
   MMap(FileFd &F,unsigned long Flags);
   MMap(unsigned long Flags);
   virtual ~MMap();
};

class DynamicMMap : public MMap
{
   public:
   
   // This is the allocation pool structure
   struct Pool
   {
      unsigned long ItemSize;
      unsigned long Start;
      unsigned long Count;
   };
   
   protected:
   
   FileFd *Fd;
   unsigned long WorkSpace;
   unsigned long const GrowFactor;
   unsigned long const Limit;
   Pool *Pools;
   unsigned int PoolCount;

   bool Grow();
   
   public:

   // Allocation
   unsigned long RawAllocate(unsigned long long Size,unsigned long Aln = 0);
   unsigned long Allocate(unsigned long ItemSize);
   unsigned long WriteString(const char *String,unsigned long Len = (unsigned long)-1);
   inline unsigned long WriteString(const std::string &S) {return WriteString(S.c_str(),S.length());};
   void UsePools(Pool &P,unsigned int Count) {Pools = &P; PoolCount = Count;};
   
   DynamicMMap(FileFd &F,unsigned long Flags,unsigned long const &WorkSpace = 2*1024*1024,
	       unsigned long const &Grow = 1024*1024, unsigned long const &Limit = 0);
   DynamicMMap(unsigned long Flags,unsigned long const &WorkSpace = 2*1024*1024,
	       unsigned long const &Grow = 1024*1024, unsigned long const &Limit = 0);
   virtual ~DynamicMMap();
};

#endif
