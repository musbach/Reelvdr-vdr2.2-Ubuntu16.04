/*
 * yac-menurecordings.h: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/osdbase.h>

// --- cYacMenuConvertItem -------------------------------------------------------

class cYacMenuConvertItem : public cOsdItem {
   cYacRecItem *yRec;
   char *title;
public:
   cYacMenuConvertItem(const cYacRecItem *yacRec);
   cYacMenuConvertItem(const char * title, bool selectable = true);
   ~cYacMenuConvertItem(){};
   cYacRecItem *YRec(void) { return yRec;};
};


// --- cYacMenuConvert -------------------------------------------------------

class cYacMenuConvert : public cOsdMenu {
private:
   bool SetFreeDiskDisplay(void);
   void SetHelpKeys(void);
   void Set(int pos = 0);
   eOSState Info(cYacMenuConvertItem *ci);
   bool bSubMenu;
   bool Open(void);
   char projName[1024];
   bool bMergeRecs;
   int bRecIdx;
   int nameRecIdx;
public:
   cYacMenuConvert(void);
   ~cYacMenuConvert();
   virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
   virtual const char* MenuKind() { return "MenuConvert";}
#endif /* GRAPHTFT */
};
