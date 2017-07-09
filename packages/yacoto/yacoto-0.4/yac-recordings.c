/*
 * yac-menurecordings.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/recording.h>
#include <vdr/plugin.h>
#include "yac-recordings.h"

#define INDEXFILESUFFIX   "/index"
#define SCRIPT_FILE       "/yac_start.sh"

struct tIndexTs {
  uint64_t offset:40; // up to 1TB per file (not using off_t here - must definitely be exactly 64 bit!)
  int reserved:7;     // reserved for future use
  int independent:1;  // marks frames that can be displayed by themselves (for trick modes)
  uint16_t number:16; // up to 64K files per recording
  tIndexTs(off_t Offset, bool Independent, uint16_t Number)
  {
    offset = Offset;
    reserved = 0;
    independent = Independent;
    number = Number;
  }
  };

char yacProjName[MAX_NAME_LEN];
bool yacMergeRecs;
// --- cYacRecItem ----------------------------------------------------

cYacRecItem::cYacRecItem(const cRecording *Recording)
{
   cString text;
   const cComponents *Components;
   cRec = (cRecording *)Recording;
   if( (name = (char *)strrchr(cRec->Name(), '~')) != NULL )
      name++;
   else
      name = (char *)cRec->Name();

   recFullLength = 0;
   recLength = GetLength();
   cutLength = GetCutLength();
   numATracks = 0;
   recSize = DirSizeMB( cRec->FileName() );
   videoInfo[0] = '\0';
   bConverted = CheckConverted( cRec->FileName() );
   Components = cRec->Info()->Components();
   if( Components ) {
      for( int i = 0; i < Components->NumComponents(); i++ ) {
         const tComponent *p = Components->Component(i);
         if( p->stream == 1 && p->description != NULL && !videoInfo[0] )
            strncpy( videoInfo, p->description, sizeof(videoInfo) / 2 );

         if( p->stream == 2 && p->type != 5 ) {
            audioTracks[numATracks].state = numATracks ? at_ignore : at_master;
            asprintf( &(audioTracks[numATracks].desc), "%s-%s", (p->description) ? p->description : "?",
                      (p->language) ? p->language : "?" );
            numATracks++;
         }
      }
      for( int i = 0; i < Components->NumComponents(); i++ ) {
         const tComponent *p = Components->Component(i);
         if( p->stream == 2 && p->type == 5 ) {
            audioTracks[numATracks].state = numATracks ? at_ignore : at_master;
            asprintf( &(audioTracks[numATracks].desc), "%s-%s", (p->description) ? p->description : "?",
                      (p->language) ? p->language : "?" );
            numATracks++;
         }
      }
   }
   titleBuffer[0] = '\0';
}


cYacRecItem::~cYacRecItem()
{
   while( numATracks > 0 ) {
      numATracks--;
      free( audioTracks[numATracks].desc );
   }
}


int cYacRecItem::GetLength(void) {
   struct stat buf;
   recFullLength = 0;

//   cString fullname = cString::sprintf("%s%s", cRec->FileName(), cRec->IsPesRecording() ? INDEXFILESUFFIX ".vdr" : INDEXFILESUFFIX);
   cString fullname = cString::sprintf("%s%s", cRec->FileName(), INDEXFILESUFFIX);
   if (*fullname && access(fullname, R_OK) == 0 && stat(fullname, &buf) == 0 && buf.st_size) {
      recFullLength = (buf.st_size - 1) / sizeof(tIndexTs) + 1;
   }
   else {
      fullname = cString::sprintf("%s%s.vdr", cRec->FileName(), INDEXFILESUFFIX);
      if (*fullname && access(fullname, R_OK) == 0 && stat(fullname, &buf) == 0 && buf.st_size) {
         recFullLength = (buf.st_size - 1) / sizeof(tIndexTs) + 1;
      }
   }
   return recFullLength / SecondsToFrames(60);
}


const char *cYacRecItem::VideoInfo(void) { 
   if( !videoInfo[0] || !strstr( videoInfo, "CODEC:" )) {
      char commandResult[32];
      cString cmd = cString::sprintf("%s%s \"%s\"", (const char *)AddDirectory( YAC_DIR, "/" ),
                                                    "yac_get_vcodec.sh", cRec->FileName());

      dsyslog("executing command '%s'", (const char *)cmd);
      FILE *p = popen((const char *)cmd, "r");
      if( p ) {
         unsigned int l = 0;
         int c;
         while( (c = fgetc(p)) != EOF && l < sizeof(commandResult) )
            if(c >= 32)
               commandResult[l++] = c;

         commandResult[l] = 0;
         pclose(p);
      }
      else
         esyslog("ERROR: can't open pipe for command '%s'", (const char *)cmd);

      snprintf( videoInfo + strlen(videoInfo), sizeof(videoInfo) - strlen(videoInfo), "  CODEC: %s", commandResult );
   }
   return videoInfo[0] ? videoInfo : "?";
}

const char *cYacRecItem::Title(void) {
   int i;
   char audioInfo[32];
   char *tmp;

   tmp = audioInfo;
   for( i = 0; i < numATracks; i++ ) {
      if( i > 0 ) {
         *tmp = ',';
         tmp++;
      }
      strcpy( tmp, itoa(i+1) );
      tmp++;
      if( i > 9 )
         tmp++;
      if( audioTracks[i].state == at_use )
         *tmp = '+';
      else if( audioTracks[i].state == at_ignore )
         *tmp = '-';
      else if( audioTracks[i].state == at_master )
         *tmp = '*';

      tmp++;
   }
   *tmp = '\0';

   snprintf( titleBuffer, sizeof(titleBuffer), "%-16s / %d%s'\t%s", 
                                               audioInfo, 
                                               recLength, 
                                               cutLength >= 0 ? strdup(cString::sprintf("/%d", recLength - cutLength)) : "",
                                               name );
   return titleBuffer;
}

audioTrackState cYacRecItem::TrackState(int idx)
{
   if( idx >= 0 && idx < numATracks ) {
      return audioTracks[idx].state;
   }
   return at_ignore;
}

const char * cYacRecItem::TrackInfo(int idx)
{
   if( idx >= 0 && idx < numATracks ) {
      return audioTracks[idx].desc;
   }
   return "";
}

void cYacRecItem::SelectTrack(int idx, audioTrackState select)
{
   if( idx >= 0 && idx < numATracks )
      audioTracks[idx].state = select;
}

int cYacRecItem::GetCutLength(void)
{
   cMarks marks;
   int oldMark = -1;
   int cutLen = 0;
   if( !marks.Load(cRec->FileName()) || !marks.Count() || strstr( cRec->FileName(), "/%" )  )
      return -1;

   for( cMark *mark = marks.First(); mark != 0; mark = marks.Next(mark) ) {
      int pos = mark->Position();
      if( oldMark >= 0 ) {
         cutLen += pos - oldMark;
         oldMark = -1;
      }
      else
         oldMark = pos;
   }
   if( oldMark > 0 && recFullLength > oldMark )
      cutLen += recFullLength - oldMark;

   return ( recFullLength - cutLen ) / SecondsToFrames(60);
}


bool cYacRecItem::CheckConverted(const char *filename)
{
   struct stat statBuf;

   if (lstat(cString::sprintf( "%s/%s.log", filename, PLUGIN_NAME_I18N ), &statBuf) == -1) 
      return false;

   return true;
}

// --- class cYacRecs ----------------------------------------------------

cYacRecs::cYacRecs(void) 
{
   yacSelState = 0;
   Clear();
}

void cYacRecs::Clear(void) 
{
   for( int i = 0; i < MAX_SEL && yacRecs[i] != NULL ; i++ ) {
      if( yacRecs[i] != NULL ) {
         delete yacRecs[i];
         yacRecs[i] = NULL;
      }
   }
   yacSelState++;
   numItems = 0;
   yacMergeRecs = false;
   yacProjName[0] = '\0';
}


bool cYacRecs::Selected(cRecording *rec)
{
   if( rec ) {
      for( int i = 0; i < MAX_SEL && yacRecs[i] != NULL; i++ ) {
         if( !strcmp(yacRecs[i]->CRec()->FileName(), rec->FileName()) )
            return true;
      }
   }
   return false;
}


bool cYacRecs::Start(void)
{
   char execCmd[8192];
   int baseLen = 0;

   strcpy(execCmd,YAC_DIR);
   strcat(execCmd,SCRIPT_FILE);
   baseLen = strlen(execCmd);
   if( yacMergeRecs == true || numItems == 1 ) {
      strcpy(execCmd + baseLen, " \"");
      strcat(execCmd, yacProjName);
      strcat(execCmd, "\"");
      baseLen = 0;
   }

   Skins.Message(mtInfo, tr("Starting convert"),1);
   for( int i = 0; i < MAX_SEL && yacRecs[i] != NULL; i++ ) {
      if( baseLen > 0 ) {
         strcpy(execCmd + baseLen, " \"");
         strcat(execCmd, yacRecs[i]->Name() );
         strcat(execCmd, "\"");
      }

      strcat( execCmd, " \"" );
      strcat( execCmd, yacRecs[i]->CRec()->FileName() );
      for( int j = 0; j < yacRecs[i]->NumATracks(); j++ ) {
         sprintf( execCmd + strlen(execCmd), "~%d", (int)yacRecs[i]->TrackState(j));
      }
      strcat( execCmd, "\"" );
      if( yacMergeRecs == false || yacRecs[i+1] == NULL ) {
         dsyslog( "Executing <%s>", execCmd );
         system( execCmd );
      }
      yacRecs[i]->SetConverted();
   }

   Clear();
   return true;
}


bool cYacRecs::Remove(cRecording *rec)
{
   int i,j;
   bool rc = false;
   for( i = 0; i < MAX_SEL && yacRecs[i] != NULL; i++ ) {
      dsyslog("Remove %d %s", i, rec->FileName());
      if( !strcmp(yacRecs[i]->CRec()->FileName(), rec->FileName()) ) {
         delete yacRecs[i];
         for( j = i + 1; j < MAX_SEL && yacRecs[j] != NULL; i++, j++ ) {
            yacRecs[i] = yacRecs[j];
         }
         yacRecs[i] = NULL;
         yacSelState++;
         numItems--;
         rc = true;
         break;
      }
   }
   return rc;
}

bool cYacRecs::Add(cRecording *rec)
{
   int i;
   bool rc = false;

   dsyslog( "Adding %s", rec->FileName() );
   for( i = 0; i < MAX_SEL && yacRecs[i] != NULL; i++ ) {
      if( !strcmp(yacRecs[i]->CRec()->FileName(), rec->FileName()) ) {
         return false;
      }
   }
   if( i < MAX_SEL ) {
      yacRecs[i] = new cYacRecItem(rec);
      if( numItems == 0 ) {
         strncpy(yacProjName, yacRecs[i]->Name(), sizeof(yacProjName));
      }
      yacSelState++;
      numItems++;
      rc = true;
   }
   return rc;
}


bool cYacRecs::Changed(int *state)
{
   bool result = ( *state != yacSelState );
   *state = yacSelState;

   return result;
}


bool cYacRecs::Move(cRecording *rec, moveMode mode)
{
   bool rc = false;
   int i,j;
   if( rec && rec->FileName() ) {
      for( i = 0; i < MAX_SEL && yacRecs[i] != NULL; i++ ) {
         if( !strcmp(yacRecs[i]->CRec()->FileName(), rec->FileName()) ) {
            int newPos = i;
            switch( mode ) {
               case move_up:
                  newPos = i - 1;
                  break;
               case move_down:
                  newPos = i + 1;
                  break;
               case move_top:
                  newPos = 0;
                  break;
               case move_bottom:
                  newPos = numItems - 1;
                  break;
               default:
                  break;
            }
            if( newPos >= 0 && newPos < numItems && newPos != i ) {
               cYacRecItem *actRec = yacRecs[i];
               if( newPos > i ) {
                  for( j=i; j < newPos; j++ ) {
                     yacRecs[j] = yacRecs[j+1];
                  }
               }
               else {
                  for( j=i; j > newPos; j-- ) {
                     yacRecs[j] = yacRecs[j-1];
                  }
               }
               yacRecs[newPos] = actRec;
               rc = true;
            }
            break;
         }
      }
   }
   return rc;
}


cYacRecs yacRecordings;
