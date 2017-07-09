/*
 * yac-menurecordings.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <langinfo.h>
#include <locale.h>
#include <vdr/recording.h>
#include <vdr/menu.h>
#include <vdr/status.h>
#include <vdr/videodir.h>
#include "yac-tools.h"
#include "yac-recordings.h"
#include "yac-menurecordings.h"
#include "yac-menurecinfo.h"
#include "yac-menuconvert.h"
#ifdef USE_WAREAGLEICON
#include <vdr/iconpatch.h>
#endif
                                                  

class Icons
{
  public:
#ifdef USE_WAREAGLEICON
    static bool bIsUTF8;
    static void Init(void) {bIsUTF8 = IsLangUtf8();}
    static const char* Done()      {return bIsUTF8 ? ICON_DVD_UTF8    : ICON_DVD;}
    static const char* Directory() {return bIsUTF8 ? ICON_FOLDER_UTF8 : ICON_FOLDER;}
    static const char* FixedBlank(){return bIsUTF8 ? ICON_BLANK_UTF8  : ICON_BLANK;}
    static const char* Selected()  {return bIsUTF8 ? ICON_NEW_UTF8    : ICON_NEW;}
#else
    static const char* Done()      {return "+";}
    static const char* Directory() {return "<DIR>";}
    static const char* FixedBlank(){return "  ";}
    static const char* Selected()  {return "*";}
#endif
};

#ifdef USE_WAREAGLEICON
bool Icons::bIsUTF8 = false;
#endif


// --- cYacMenuRecordingItem ----------------------------------------------------

class cYacMenuRecordingItem : public cOsdItem {
private:
   char *name;
   char *titleBuffer;
   int totalEntries;
   int HierarchyLevels(cRecording *Recording);
   bool Selected(void) { return yacRecordings.Selected(yacRec->CRec());};
   bool isDir;
   cYacRecItem *yacRec;
public:
   cYacMenuRecordingItem(cRecording *Recording, int Level);
   ~cYacMenuRecordingItem();
   void IncrementCounter(void);
   const char *Title(int Level);
   const char *Name(void) { return name;}
   const char *FileName(void) { return yacRec->CRec() ? yacRec->CRec()->FileName() : "";}
   bool IsDirectory(void) { return isDir;}
   cYacRecItem *YRec(void) { return yacRec;};
};


cYacMenuRecordingItem::cYacMenuRecordingItem(cRecording *Recording, int Level)
{
   isDir = ( Level < HierarchyLevels(Recording) );

   yacRec = new cYacRecItem(Recording);
   name = strdup( Recording->Name() );
   titleBuffer = NULL;
   totalEntries = 0;
   SetText(Title(Level));
   if( *Text() == '\t' ) {
      free(name);
      name = strdup(Text() + 1); // 'Text() + 1' to skip the two '\t'
   }
}


cYacMenuRecordingItem::~cYacMenuRecordingItem()
{
   delete yacRec;
   free(name);
}


int cYacMenuRecordingItem::HierarchyLevels(cRecording *cRec)
{
   const char *s = cRec->Name();
   int level = 0;
   while( *++s ) {
      if( *s == '~' )
         level++;
   }
   return level;
}

const char *cYacMenuRecordingItem::Title(int Level)
{
   if( titleBuffer )
      free(titleBuffer);

   titleBuffer = NULL;
   if( !isDir ) {
      struct tm tm_r;
      time_t t_rec = yacRec->CRec()->Start();
      struct tm *t = localtime_r(&t_rec, &tm_r);
      char *s;

      int recLength = yacRec->RecLength();

      if( Level > 0 && (s = strrchr(name, '~')) != NULL )
         s++;
      else
         s = name;

      titleBuffer = strdup(cString::sprintf("%02d.%02d.%02d\t%d%s'\t%s%s%s",
                                            t->tm_mday,
                                            t->tm_mon + 1,
                                            t->tm_year % 100,
                                            recLength,
                                            yacRec->RecCutLength() >= 0 ? strdup(cString::sprintf("/%d", recLength - yacRec->RecCutLength())) : "",
					                        Selected() ? Icons::Selected() : Icons::FixedBlank(),
					                        yacRec->IsConverted() ? Icons::Done() : Icons::FixedBlank(),
                                            s));

      // let's not display a trailing '~':
      stripspace(titleBuffer);
      s = &titleBuffer[strlen(titleBuffer) - 1];
      if( *s == '~' )
         *s = 0;
   }
   else {
      const char *s = name;
      const char *p = s;
      while( *++s ) {
         if( *s == '~' ) {
            if( Level-- )
               p = s + 1;
            else
               break;
         }
      }
      titleBuffer = MALLOC(char, s - p + 3);
      *titleBuffer = '\t';
      strn0cpy(titleBuffer + 1, p, s - p + 1);
   }

   return titleBuffer;
}

void cYacMenuRecordingItem::IncrementCounter(void)
{
   totalEntries++;

   SetText(cString::sprintf("%s%s\t%s<%d>\t<%s>", Icons::FixedBlank(), Icons::Directory(), 
                                                      Icons::FixedBlank(), totalEntries, 
                                                      name));
}

// --- cYacMenuRecordings -------------------------------------------------------

cYacMenuRecordings::cYacMenuRecordings(const char *Base, int Level, bool OpenSubMenus)
:cOsdMenu(Base ? Base : tr("Recordings"), 9, 8 )
{
   if( Base == NULL && Level == 0 )
      yacRecordings.Clear();

#ifdef USE_WAREAGLEICON
   Icons::Init();
#endif
   base = Base ? strdup(Base) : NULL;
   level = Setup.RecordingDirs ? Level : -1;
   yacChanges = 0;
   yacRecordings.Changed(&yacChanges);
   Display(); // this keeps the higher level menus from showing up briefly when pressing 'Back' during replay
   Set();
   SetFreeDiskDisplay();
   if( Current() < 0 )
      SetCurrent(First());

   Display();
   SetHelpKeys();
}

cYacMenuRecordings::~cYacMenuRecordings()
{
   free(base);
}

bool cYacMenuRecordings::SetFreeDiskDisplay()
{
   int FreeMB;
   VideoDiskSpace(&FreeMB);
   cString freeDiskSpaceString = cString::sprintf("%.1f GB %s", ((float)FreeMB) / 1000, tr("free"));

   SetTitle(cString::sprintf("%s  -  %s", base ? base : tr("Recordings"), (const char *)freeDiskSpaceString ));
   return true;
}

void cYacMenuRecordings::SetHelpKeys(void)
{
   cYacMenuRecordingItem *ri = (cYacMenuRecordingItem *)Get(Current());

   SetHelp( ri->Selectable()  ? tr("Convert") : NULL,
#if defined USE_SORTRECORDS || defined USE_LIEMIKUUTIO
            Count() > 1       ? tr("Sort") : NULL,
#else
            NULL,
#endif
            ( ! ri->Selectable() || ( ri->Selectable() && ri->IsDirectory() )) ? NULL : tr("Select"), 
            ri->Selectable()  ? tr("Status") : NULL );
}

void cYacMenuRecordings::Set(bool Refresh){
   const char *CurrentRecording = cReplayControl::LastReplayed();
   cYacMenuRecordingItem *LastItem = NULL;
   char *LastItemText = NULL;
   cThreadLock RecordingsLock(&Recordings);
   if( Refresh ) {
      cYacMenuRecordingItem *ri = (cYacMenuRecordingItem *)Get(Current());
      if( ri ) {
         cRecording *Recording = Recordings.GetByName(ri->FileName());
         if( Recording )
            CurrentRecording = Recording->FileName();
      }
   }
   Clear();
   Recordings.Sort();
   for( cRecording *recording = Recordings.First(); recording; recording = Recordings.Next(recording) ) {
      if( !base || (strstr(recording->Name(), base) == recording->Name() && recording->Name()[strlen(base)] == '~') ) {
         cYacMenuRecordingItem *Item = new cYacMenuRecordingItem(recording, level);
#ifdef USE_PINPLUGIN
         if( (*Item->Text() && (!LastItem || strcmp(Item->Text(), LastItemText) != 0))
             && (!cStatus::MsgReplayProtected(Item->YRec()->CRec(), Item->Name(), base, Item->IsDirectory(), true)) ) {
#else
         if( *Item->Text() && (!LastItem || strcmp(Item->Text(), LastItemText) != 0) ) {
#endif /* PINPLUGIN */
            Add(Item);
            LastItem = Item;
            if(LastItemText)
               free(LastItemText);

            LastItemText = strdup(LastItem->Text()); // must use a copy because of the counters!
         }
         else
            delete Item;

         if( LastItem ) {
            if( CurrentRecording && strcmp(CurrentRecording, recording->FileName()) == 0 )
               SetCurrent(LastItem);
            if( LastItem->IsDirectory() )
               LastItem->IncrementCounter();
         }
      }
   }
   if(LastItemText)
      free(LastItemText);

   if( !Count() )
      Add( new cOsdItem( tr("No recordings found"), osUnknown, false ) );

   if( Refresh ) {
      SetFreeDiskDisplay();
      Display();
   }
}

bool cYacMenuRecordings::Open(bool OpenSubMenus){
   cYacMenuRecordingItem *ri = (cYacMenuRecordingItem *)Get(Current());
   if( ri && ri->IsDirectory() ) {
      const char *t = ri->Name();
      cString buffer;
      if( base ) {
         buffer = cString::sprintf("%s~%s", base, t);
         t = buffer;
      }
      AddSubMenu(new cYacMenuRecordings(t, level + 1, OpenSubMenus));
      return true;
   }
   return false;
}

eOSState cYacMenuRecordings::Info(void){
   if( HasSubMenu() || Count() == 0 )
      return osContinue;
   cYacMenuRecordingItem *ri = (cYacMenuRecordingItem *)Get(Current());
   if( ri && !ri->IsDirectory() )
      return AddSubMenu(new cYacMenuRecInfo(ri->YRec()));

   return osContinue;
}

eOSState cYacMenuRecordings::ProcessKey(eKeys Key){
   bool bHadSubMenu = HasSubMenu();
   eOSState state = cOsdMenu::ProcessKey(Key);

   if( bHadSubMenu )
      return state;

   if( state == osUnknown ) {
      cYacMenuRecordingItem *ri = (cYacMenuRecordingItem *)Get(Current());
      if(! ri->Selectable()) {
         return state;
      }
#ifdef USE_SORTRECORDS
      const char *RecordingsSortModeTexts[MAXSORTMODES];
      RecordingsSortModeTexts[0] = tr("main dir alphabetically, subdirs flexible");
      RecordingsSortModeTexts[1] = tr("main dir by date, subdirs flexible");
      RecordingsSortModeTexts[2] = tr("all alphabetically");
      RecordingsSortModeTexts[3] = tr("all by date");
#endif
      cRecording *cRec = ri->YRec()->CRec();
      switch( Key ) {
         case kRed:    
            if( yacRecordings.NumItems() == 0 && ri && ! ri->IsDirectory() )
               yacRecordings.Add(cRec);

            return AddSubMenu(new cYacMenuConvert());
         case kGreen:  
         case k0:      
#ifdef USE_SORTRECORDS
            Setup.RecordingsSortMode = ++Setup.RecordingsSortMode % MAXSORTMODES;
            Set(true);
            Skins.Message(mtStatus, cString::sprintf("%s %d: %s", tr("Sorting"), Setup.RecordingsSortMode, RecordingsSortModeTexts[Setup.RecordingsSortMode]));
            return osContinue;
#elif defined (USE_LIEMIKUUTIO)
            DirOrderState = !DirOrderState;
            Set(true);
            return osContinue;
#else
            break;
#endif
         case kYellow:
            if( ri && !ri->IsDirectory() ) {
               if( yacRecordings.Selected(cRec) )
                  yacRecordings.Remove(cRec);
               else
                  yacRecordings.Add(cRec);
            }
            if( yacRecordings.Changed(&yacChanges) )
               Set(true);

            return osContinue;
         case kOk:
            if( ri && ri->IsDirectory() )
               Open();
            else
               return Info();

            return osContinue;
         case kInfo:
            return Info();

         case kBlue:   
            return AddSubMenu(new cMenuText(tr("Status"), GetStatusInfo(), fontFix));

#ifdef USE_SORTRECORDS
         case k9:      
            Recordings.ToggleSortOrder();
            Set(true);
            return osContinue;
#endif
         case kNone:   
         default: break;
      }
   }
   if( yacRecordings.Changed(&yacChanges) )
      Set(true);

   if( !HasSubMenu() ) {
      if( bHadSubMenu )
         SetFreeDiskDisplay();
      if( Key != kNone )
         SetHelpKeys();
   }
   return state;
}
