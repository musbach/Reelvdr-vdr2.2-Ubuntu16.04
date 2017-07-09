/*
 * yac-menurecordings.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/recording.h>
#include <vdr/menu.h>
#include <vdr/status.h>
#include "yac-recordings.h"
#include "yac-menurecinfo.h"

// --- cYacMenuRecording --------------------------------------------------------

cYacMenuRecInfo::cYacMenuRecInfo(const cYacRecItem *yRec)
:cOsdMenu(tr("Recording info"))
{
   yacRec = (cYacRecItem *)yRec;
   SetHelp(NULL);
}

void cYacMenuRecInfo::Display(void)
{
   cString text = "";
   cString audio = "?";
   int recLength;
   int recSize;

   cOsdMenu::Display();
   DisplayMenu()->SetTitle(yacRec->Name());

   for( int i = 0; i < yacRec->NumATracks(); i++ ) {
      if( strlen((const char *)audio) < 3 )
         audio = cString( yacRec->TrackInfo(i) );
      else
         audio = cString::sprintf("%s / %s", (const char *)audio, (const char *)yacRec->TrackInfo(i) );
   }
   recLength = yacRec->RecLength();
   recSize = yacRec->RecSize();

   text = cString::sprintf( "%s: %s\n%s: %s\n%s: %3d:%02d\n%s: %d.%01d GB\n\n%s", 
                            tr("Video info"), yacRec->VideoInfo(),
                            tr("Audio info"), (const char *)audio,
                            tr("Duration"), (recLength / 60), (recLength % 60),
                            tr("Size"), ((recSize + 50) / 1000), (((recSize + 50) % 1000) / 100),
                            yacRec->CRec()->Info()->Description() ? yacRec->CRec()->Info()->Description() : "" );

   DisplayMenu()->SetText((const char *)text, fontFix);
   cStatus::MsgOsdTextItem(text);
}

eOSState cYacMenuRecInfo::ProcessKey(eKeys Key)
{
   switch( Key ) {
      case kUp|k_Repeat:
      case kUp:
      case kDown|k_Repeat:
      case kDown:
      case kLeft|k_Repeat:
      case kLeft:
      case kRight|k_Repeat:
      case kRight:
         DisplayMenu()->Scroll(NORMALKEY(Key) == kUp || NORMALKEY(Key) == kLeft, NORMALKEY(Key) == kLeft || NORMALKEY(Key) == kRight);
         cStatus::MsgOsdTextItem(NULL, NORMALKEY(Key) == kUp || NORMALKEY(Key) == kLeft);
         return osContinue;
      case kInfo:   return osBack;
      default: break;
   }

   eOSState state = cOsdMenu::ProcessKey(Key);

   if( state == osUnknown && Key == kOk )
      state = osBack;

   return state;
}

