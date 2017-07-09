/*
 * yac-menurecordings.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/plugin.h>
#include <vdr/recording.h>
#include <vdr/menu.h>
#include <vdr/tools.h>
#include <vdr/status.h>
#include <vdr/videodir.h>
#include "yac-recordings.h"
#include "yac-menurecordings.h"
#include "yac-menurecinfo.h"
#include "yac-menuconvert.h"
#include "yac-setup.h"

#define STR_STARTCONVERT    tr("Start conversion")
#define STR_SETTINGS        tr("Settings")
#define STR_NAME            tr("Name")
#define STR_CONVERT_RESULT  tr("Merge recordings")
#define STR_AUDIOINFO       tr("Audiotracks")
#define STR_LEN             tr("length")
#define STR_CUTLEN          tr("cutlen")

char activeConfig[32] = "";

class cYacAudioTracks : public cMenuSetupPage {
private:
   const char *aStates[at_master + 2];
   cYacRecItem *yacRec;
   audioTrackState aTracks[ MAX_AUDIOTRACKS ];
   int masterTrack;
   void Set(int pos = 0);
   bool CheckMaster(void);
protected:
   virtual void Store(void);
public:
   cYacAudioTracks(const cYacRecItem *yRec);
   virtual eOSState ProcessKey(eKeys Key);
};


cYacAudioTracks::cYacAudioTracks(const cYacRecItem *yRec)
{
   aStates[at_ignore] = tr("Ignore");
   aStates[at_use] = tr("Use if possible");
   aStates[at_master] = tr("Master");
   aStates[at_master+1] = NULL;
   yacRec = (cYacRecItem *)yRec;
   masterTrack = 0;
   for( int i = 0; i < yacRec->NumATracks(); i++ ) {
      aTracks[i] = yacRec->TrackState(i);
      if( aTracks[i] == at_master )
         masterTrack = i;
   }
   Set();
}

eOSState cYacAudioTracks::ProcessKey(eKeys Key){
   bool bHadSubMenu = HasSubMenu();
   bool bChanged = false;
   eOSState state = cOsdMenu::ProcessKey(Key);

   if( bHadSubMenu )
      return state;

   int newPos = Current();

   switch( Key ) {
      case kRed:
         Store();
         yacRecordings.Start();
         return osBack;
      case kGreen:
         return AddSubMenu(new cYacMenuSetup());
         break;
      case kLeft: 
      case kRight:
         bChanged = CheckMaster(); 
         break;
      case kOk:
         Store();
	 state = osBack;
	 break;	 
      case kBack:
	 state = osBack;
	 break;	 
      default: 
         break;
   }

   if( bChanged ) {
      Set(newPos);
   }

   return state;
}


bool cYacAudioTracks::CheckMaster(void)
{
   int numMaster = 0;
   bool bChanged = false;

   for( int i = 0; i < yacRec->NumATracks(); i++ ) {
      if( aTracks[i] == at_master ) {
         if( i != masterTrack ) {
            bChanged = true;
            aTracks[masterTrack] = at_ignore;
            masterTrack = i;
         }
         numMaster++;
      }
   }

   if( numMaster == 0 ) {
      bChanged = true;
      if( masterTrack == 0 && yacRec->NumATracks() > 1 )
         aTracks[1] = at_master;
      else
         aTracks[0] = at_master;
   }
   return bChanged;
}

void cYacAudioTracks::Set(int pos) 
{
   cString audio;
   void *trA; // to avoid compiler warning

   masterTrack = 0;
   Clear();
   SetTitle( tr("Choose audio tracks") );
   Add( new cOsdItem( yacRec->Name(), osUnknown, false ) );
   Add( new cOsdItem( "", osUnknown, false ) );

   for( int i = 0; i < yacRec->NumATracks(); i++ ) {
      audio = cString::sprintf( "%d: %s", i, yacRec->TrackInfo(i) );
      trA = (void *)&(aTracks[i]);
      Add(new cMenuEditStraItem((const char *)audio, (int *)trA, at_master + 1, aStates));
      if( aTracks[i] == at_master )
         masterTrack = i;

   }
   if( Count() > pos )
      SetCurrent(Get(pos > 1 ? pos : 2));

   SetHelp( tr("Convert"), tr("Settings"));
   Display();
}

void cYacAudioTracks::Store(void)
{
   for( int i = 0; i < yacRec->NumATracks(); i++ ) {
      yacRec->SelectTrack(i, aTracks[i]);
   }
}

// --- cYacMenuConvert -------------------------------------------------------

cYacMenuConvertItem::cYacMenuConvertItem(const cYacRecItem *yacRec)
{
   yRec = (cYacRecItem *)yacRec;
   SetText(yRec->Title());
}

cYacMenuConvertItem::cYacMenuConvertItem(const char *title, bool selectable)
{
   yRec = NULL;
   SetSelectable(selectable);
   SetText(title);
}

// --- cYacMenuConvert -------------------------------------------------------
#define STR_CFG "CONFIG="

cYacMenuConvert::cYacMenuConvert(void)
:cOsdMenu(tr("Convert recordings"), 30)
{
   if( activeConfig[0] == '\0' ) {
      cString configFile = cString::sprintf( "%s/%s.conf", cPlugin::ConfigDirectory(PLUGIN_NAME_I18N), PLUGIN_NAME_I18N);

      FILE *fhdl = fopen( (const char *)configFile, "r" );
      if( fhdl != NULL ) {
         static char buffer[ 2048 ];

         while( fgets( buffer, sizeof( buffer ), fhdl ) != NULL ) {
            if( !strncmp(buffer, STR_CFG, strlen( STR_CFG )) ) {
               int i;
               strncpy(activeConfig, buffer + strlen("CONFIG=") + 1, sizeof(activeConfig) );
               for( i = 0; i < (int)(sizeof(activeConfig)-2) && activeConfig[i] != '\0'; i++ ) {
                  if( activeConfig[i] == '"' )
                     break;
               }
               activeConfig[i] = '\0';
               break;
            }
         }
         fclose( fhdl );
      }
      else
         esyslog( "Error opening <%s>\n", (const char *)configFile );
   }

   Display(); // this keeps the higher level menus from showing up briefly when pressing 'Back' during replay

   bMergeRecs = yacMergeRecs;
   if( yacRecordings.NumItems() > 0 )
      strncpy( projName, yacRecordings.yacRecs[0]->Name(), sizeof(projName) );
   else
      projName[0] = '\0';

   Set();
   SetFreeDiskDisplay();
   Display();
   SetHelpKeys();
   bSubMenu = false;
}

cYacMenuConvert::~cYacMenuConvert()
{
}

bool cYacMenuConvert::SetFreeDiskDisplay()
{
   int FreeMB;
   VideoDiskSpace(&FreeMB);
   cString freeDiskSpaceString = cString::sprintf("%.1f GB %s", ((float)FreeMB) / 1000, tr("free"));

   SetTitle(cString::sprintf("%s - %s", tr("Convert recordings"), (const char *)freeDiskSpaceString ));
   return true;
}

void cYacMenuConvert::SetHelpKeys(void)
{
   bool bShowDown = false, bShowUp = false;
   bool bIsRec = Current() >= bRecIdx ? true : false;

   if( bIsRec && yacRecordings.NumItems() > 1 ) {
      if( Current() < Count() - 1 ) {
         bShowDown = true;
      }
      if( ((cYacMenuConvertItem *)Get(Current()-1))->YRec() ) {
         bShowUp = true;
      }
   }
   if ( Current() != nameRecIdx ) {
      SetHelp( bShowDown ? tr("Move down") : NULL,
               bShowUp   ? tr("Move up") : NULL,
               bIsRec    ? tr("Remove") : NULL,
               bIsRec    ? tr("Audio") : NULL );
   }	       
}

void cYacMenuConvert::Set(int pos){
   int i;
   void *yMR; // to avoid compiler warning
   Clear();
   nameRecIdx = -1;
   if( yacRecordings.NumItems() > 0 ) {
      char buffer[255];
      sprintf( buffer, "%s (%s)", STR_STARTCONVERT, activeConfig );
      Add( new cYacMenuConvertItem( buffer, true ));
      Add( new cYacMenuConvertItem( STR_SETTINGS, true ));
      Add( new cYacMenuConvertItem( "", false ));

      if( yacRecordings.NumItems() > 1 ) {
         yMR = (void *)&yacMergeRecs;
         Add( new cMenuEditBoolItem( STR_CONVERT_RESULT, (int *)yMR));
      }
      if( yacRecordings.NumItems() == 1 || yacMergeRecs == true ) {
         Add( new cYacMenuConvertItem( "", false ));
         nameRecIdx = Count();
         Add( new cMenuEditStrItem( STR_NAME, yacProjName, sizeof( yacProjName ), NULL ));
      }

      Add( new cYacMenuConvertItem( "", false ));
      sprintf( buffer, "%s/%s/%s\t%s", STR_AUDIOINFO, STR_LEN, STR_CUTLEN, STR_NAME );
      Add( new cYacMenuConvertItem( buffer, true ));
      Add( new cYacMenuConvertItem( "", false ));
      bRecIdx = Count();
      for( i = 0; yacRecordings.yacRecs[i] != NULL; i++ ) {
         Add(new cYacMenuConvertItem(yacRecordings.yacRecs[i]));
      }
   }
   else {
      bRecIdx = 2;
      Add( new cYacMenuConvertItem( tr("Empty list") ));
   }

   SetFreeDiskDisplay();
   if( Count() > pos )
      SetCurrent(Get(pos));


   Display();
}

bool cYacMenuConvert::Open(void){
   cYacRecItem *ri = (cYacRecItem *)Get(Current());
   if( ri ) {
      //const char *t = ri->cRec->Name();
      return true;
   }
   return false;
}

eOSState cYacMenuConvert::Info(cYacMenuConvertItem *ci){
   if( ci->YRec() )
      return AddSubMenu(new cYacMenuRecInfo(ci->YRec()));

   return osContinue;
}

eOSState cYacMenuConvert::ProcessKey(eKeys Key){
   bool bHadSubMenu = HasSubMenu();
   bool bMergeRecs = yacMergeRecs;
   eOSState state = cOsdMenu::ProcessKey(Key);
   bool changed = false;
   int newPos = Current();

   if( bHadSubMenu ) {
      bSubMenu = true;
      return state;
   }

   Key = NORMALKEY(Key);
   if( state == osUnknown ) {
      if( yacRecordings.NumItems() > 0 ) {
         if( Current() >= bRecIdx ) {
            cYacMenuConvertItem *ri = (cYacMenuConvertItem *)Get(Current());
            if( ri && ri->YRec() ) {
               switch( Key ) {
                  case kRed:
                     changed = yacRecordings.Move(ri->YRec()->CRec(),move_down);
                     newPos ++;
                     break;
                  case kGreen:
                     changed = yacRecordings.Move(ri->YRec()->CRec(),move_up);
                     newPos --;
                     break;
                  case kYellow: 
                     changed = yacRecordings.Remove(ri->YRec()->CRec());
                     if( yacRecordings.NumItems() <= newPos && newPos > 0 )
                        newPos --;
                     break;
                  case kBlue:   
                     return AddSubMenu( new cYacAudioTracks(ri->YRec()) ); 
                     break;
                  case kInfo:
                  case kOk:
                     return Info(ri);
                  default: 
                     break;
               }
            }
         }
         else {
            if( Key == kOk ) {
               cOsdItem *ri = Get(Current());
               if( !strncmp(ri->Text(), STR_STARTCONVERT, strlen(STR_STARTCONVERT)) ) {
                  yacRecordings.Start();
                  return osBack;
               }
               else if( !strcmp(ri->Text(), STR_SETTINGS) ) {
                  return AddSubMenu(new cYacMenuSetup());
               }
            }
         }
      }
      state = osContinue;
   }
   if( bMergeRecs != yacMergeRecs ) {
      bMergeRecs = yacMergeRecs;
      changed = true;
   }

   if( bSubMenu || changed ) {
      Set(newPos);
      bSubMenu = false;
   }

   if( Key != kNone )
      SetHelpKeys();

   return state;
}

