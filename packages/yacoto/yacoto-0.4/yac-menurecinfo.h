/*
 * yac-menurecordings.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

class cYacMenuRecInfo : public cOsdMenu {
private:
   cYacRecItem *yacRec;
public:
   cYacMenuRecInfo(const cYacRecItem *yRec);
   ~cYacMenuRecInfo(void) {};
   virtual void Display(void);
   virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
   virtual const char* MenuKind() { return "MenuRecording";}
#endif /* GRAPHTFT */
};

