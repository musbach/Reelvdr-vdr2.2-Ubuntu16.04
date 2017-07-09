/*
 * yac-setup.h stolen from admin plugin
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#define MAX_ENTRIES 1024
#define MAX_LISTITEMS 32
#define MAX_GROUPS  20

typedef struct _admin {
   char *name;
   char *value;
   char type;
   int length;
   char *choices;
   char *scriptName;
   char *desc;
   char *sValue;
   int  iValue;
   int  iValMin;
   int  iValMax;
   int  group;
   char *itemStrings;
   const char * lItems[MAX_LISTITEMS];
   int numLItems;
   char *allowed;
} ADMIN_ENTRY;


class cYacMenuSetup : public cMenuSetupPage {
private:
   ADMIN_ENTRY *admTable[ MAX_ENTRIES ];
   char configFile[254];
   void FreeTable(int);
   void AddMenuEntry( ADMIN_ENTRY *admEntry );
   bool CheckChanged(void);
   bool bChanged;
   bool bStored;
   int idxConfigVar;
   int activeConfigValue;
   void Set(void);
protected:
   virtual void Store(void);
public:
   cYacMenuSetup(void);
   ~cYacMenuSetup(void);
   virtual eOSState ProcessKey(eKeys Key);
};
