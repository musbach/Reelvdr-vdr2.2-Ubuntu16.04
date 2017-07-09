/*
 * yac-menurecordings.h: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/osdbase.h>
#include <vdr/recording.h>

class cYacMenuRecordings : public cOsdMenu {
private:
   char *base;
   int level;
   int yacChanges;
   bool SetFreeDiskDisplay(void);
   void SetHelpKeys(void);
   void Set(bool Refresh = false);
   bool Open(bool OpenSubMenus = false);
   eOSState Info(void);
public:
   cYacMenuRecordings(const char *Base = NULL, int Level = 0, bool OpenSubMenus = false);
   ~cYacMenuRecordings();
   virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
   virtual const char* MenuKind() { return "MenuRecordings";}
#endif /* GRAPHTFT */
};
