/*  */

#ifndef PKGLIB_ACQUIRE_H
#define PKGLIB_ACQUIRE_H

#include "macros-apt-pkg.h"
#include <apt-pkg/weakptr.h>

#include <vector>
#include <string>

#include <stddef.h>
#include <sys/time.h>
#include <sys/select.h>

#ifndef APT_10_CLEANER_HEADERS
#include <unistd.h>
#endif

#ifndef APT_8_CLEANER_HEADERS
using std::vector;
using std::string;
#endif

class pkgAcquireStatus;

class pkgAcquire
{   
   private:
   int LockFD;
   void *d;

   public:
   
   class Item;
   class Queue;
   class Worker;
   struct MethodConfig;
   struct ItemDesc;
   friend class Item;
   friend class Queue;

   typedef std::vector<Item *>::iterator ItemIterator;
   typedef std::vector<Item *>::const_iterator ItemCIterator;

   protected:
   
   std::vector<Item *> Items;
   
   Queue *Queues;

   Worker *Workers;

   MethodConfig *Configs;

   pkgAcquireStatus *Log;

   unsigned long ToFetch;

   enum QueueStrategy {
     QueueHost,
     QueueAccess} QueueMode;

   bool const Debug;
   bool Running;

   void Add(Item *Item);

   void Remove(Item *Item);

   void Add(Worker *Work);

   void Remove(Worker *Work);
   
   void Enqueue(ItemDesc &Item);

   void Dequeue(Item *Item);

   std::string QueueName(std::string URI,MethodConfig const *&Config);

   virtual void SetFds(int &Fd,fd_set *RSet,fd_set *WSet);

   virtual void RunFds(fd_set *RSet,fd_set *WSet);   

   void Bump();
   
   public:

   MethodConfig *GetConfig(std::string Access);

   enum RunResult {
     Continue,

     Failed,

     Cancelled};

   RunResult Run(int PulseInterval=500000);

   void Shutdown();
   
   inline Worker *WorkersBegin() {return Workers;};

   Worker *WorkerStep(Worker *I) APT_PURE;

   inline ItemIterator ItemsBegin() {return Items.begin();};

   inline ItemIterator ItemsEnd() {return Items.end();};
   
   class UriIterator;
   UriIterator UriBegin();
   UriIterator UriEnd();
   
   bool Clean(std::string Dir);

   unsigned long long TotalNeeded();

   unsigned long long FetchNeeded();

   unsigned long long PartialPresent();

   bool Setup(pkgAcquireStatus *Progress = NULL, std::string const &Lock = "");

   void SetLog(pkgAcquireStatus *Progress) { Log = Progress; }

   pkgAcquire(pkgAcquireStatus *Log) APT_DEPRECATED;
   pkgAcquire();

   virtual ~pkgAcquire();

};

struct pkgAcquire::ItemDesc : public WeakPointable
{
   std::string URI;
   std::string Description;
   std::string ShortDesc;
   Item *Owner;
};
class pkgAcquire::Queue
{
   friend class pkgAcquire;
   friend class pkgAcquire::UriIterator;
   friend class pkgAcquire::Worker;

   void *d;

   Queue *Next;
   
   protected:

   struct QItem : pkgAcquire::ItemDesc
   {
      QItem *Next;
      pkgAcquire::Worker *Worker;

      void operator =(pkgAcquire::ItemDesc const &I)
      {
	 URI = I.URI;
	 Description = I.Description;
	 ShortDesc = I.ShortDesc;
	 Owner = I.Owner;
      };
   };
   
   std::string Name;
   QItem *Items;

   pkgAcquire::Worker *Workers;

   pkgAcquire *Owner;

   signed long PipeDepth;

   unsigned long MaxPipeDepth;
   
   public:
   
   bool Enqueue(ItemDesc &Item);

   bool Dequeue(Item *Owner);

   QItem *FindItem(std::string URI,pkgAcquire::Worker *Owner) APT_PURE;

   bool ItemStart(QItem *Itm,unsigned long long Size);

   bool ItemDone(QItem *Itm);
   
   bool Startup();

   bool Shutdown(bool Final);

   bool Cycle();

   void Bump();
   
   Queue(std::string Name,pkgAcquire *Owner);

   virtual ~Queue();
};
class pkgAcquire::UriIterator
{
   void *d;

   pkgAcquire::Queue *CurQ;
   pkgAcquire::Queue::QItem *CurItem;
   
   public:
   
   inline void operator ++() {operator ++(0);};

   void operator ++(int)
   {
      CurItem = CurItem->Next;
      while (CurItem == 0 && CurQ != 0)
      {
	 CurItem = CurQ->Items;
	 CurQ = CurQ->Next;
      }
   };
   
   inline pkgAcquire::ItemDesc const *operator ->() const {return CurItem;};
   inline bool operator !=(UriIterator const &rhs) const {return rhs.CurQ != CurQ || rhs.CurItem != CurItem;};
   inline bool operator ==(UriIterator const &rhs) const {return rhs.CurQ == CurQ && rhs.CurItem == CurItem;};
   
   UriIterator(pkgAcquire::Queue *Q) : CurQ(Q), CurItem(0)
   {
      while (CurItem == 0 && CurQ != 0)
      {
	 CurItem = CurQ->Items;
	 CurQ = CurQ->Next;
      }
   }   
   virtual ~UriIterator() {};
};
struct pkgAcquire::MethodConfig
{
   void *d;
   MethodConfig *Next;
   
   std::string Access;

   std::string Version;

   bool SingleInstance;

   bool Pipeline;

   bool SendConfig;

   bool LocalOnly;

   bool NeedsCleanup;

   bool Removable;
   
   MethodConfig();

   virtual ~MethodConfig() {};
};
class pkgAcquireStatus
{
   void *d;

   protected:
   
   struct timeval Time;

   struct timeval StartTime;

   unsigned long long LastBytes;

   unsigned long long CurrentCPS;

   unsigned long long CurrentBytes;

   unsigned long long TotalBytes;

   unsigned long long FetchedBytes;

   unsigned long long ElapsedTime;

   unsigned long TotalItems;

   unsigned long CurrentItems;
   
   public:

   bool Update;

   bool MorePulses;
      
   virtual void Fetched(unsigned long long Size,unsigned long long ResumePoint);
   
   virtual bool MediaChange(std::string Media,std::string Drive) = 0;
   
   virtual void IMSHit(pkgAcquire::ItemDesc &/*Itm*/) {};

   virtual void Fetch(pkgAcquire::ItemDesc &/*Itm*/) {};

   virtual void Done(pkgAcquire::ItemDesc &/*Itm*/) {};

   virtual void Fail(pkgAcquire::ItemDesc &/*Itm*/) {};

   virtual bool Pulse(pkgAcquire *Owner);

   virtual void Start();

   virtual void Stop();
   
   pkgAcquireStatus();
   virtual ~pkgAcquireStatus() {};
};

#endif