/*
 * yac-setup.c stolen from admin plugin
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#include <getopt.h>
#include <stdlib.h>
#include <vdr/interface.h>
#include <vdr/tools.h>
#include <vdr/plugin.h>
#include <vdr/menu.h>
#include <vdr/skins.h>
#include "yac-setup.h"

#define STATE_GROUPS     1000
#define STATE_SAVEEXIT    999
#define STATE_SAVEBACK    998
#define STATE_NOSAVEBACK  997

#define LOW_CHARS   "abcdefghijklmnopqrstuvwxyz"
#define UP_CHARS    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM_CHARS   "0123456789"
#define FNAME_CHARS " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.#~,/_@"

#define CFG_FILE "/yacadmin.conf"
#define START_SCRIPT "/yac_admin.sh -start"
#define INIT_SCRIPT "/yac_admin.sh -init"
#define SAVE_SCRIPT "/yac_admin.sh -save"

extern char activeConfig[32];
// --- cYacMenuSetup --------------------------------------------------------

cYacMenuSetup::cYacMenuSetup(void)
{
   int i = 0;
   int actGroup = 0;
   int numGroup = 0;
   int j;
   char *p1, *p2;
   char buffer[512];

   activeConfigValue = -1;
   idxConfigVar = -1;
   bChanged = false;
   bStored = false;
   strcpy(configFile,AddDirectory( cPlugin::ConfigDirectory(PLUGIN_NAME_I18N), "/" ));
   strcat(configFile,CFG_FILE);
   strcpy(buffer,YAC_DIR);

   strcat(buffer, START_SCRIPT);
   dsyslog( "Executing <%s>", buffer );
   system( buffer );

   admTable[0] = NULL;
   dsyslog( "CfgFile: %s", configFile );

   FILE *fhdl = fopen( configFile, "r" );
   if( fhdl != NULL ) {
      static char buffer[ 2048 ];
      int offset;
      unsigned int maxLen;

      while( fgets( buffer, sizeof( buffer ), fhdl ) != NULL ) {
         buffer[ strlen( buffer ) - 1 ] = '\0';
         admTable[i]=( ADMIN_ENTRY * )calloc( sizeof( ADMIN_ENTRY ), 1 );
         offset = 0;
         if( buffer[ 0 ] == '#' && buffer[1] == '!' )
            offset = 2;

         if( buffer[0] == '/' || offset > 0 ) {
            admTable[i]->desc = NULL;
            sscanf( buffer + offset, "%a[^~]~%a[^~]~%a[^~]~%c~%d~%a[^~]~%a[^~]~",
                    &(admTable[i]->scriptName),
                    &(admTable[i]->name),
                    &(admTable[i]->value),
                    &(admTable[i]->type),
                    &(admTable[i]->length),
                    &(admTable[i]->choices),
                    &(admTable[i]->desc ) );

            /* if empty value doit again */
            if( admTable[i]->desc == NULL ) {
               FreeTable( i );
               sscanf( buffer, "%a[^~]~%a[^~]~~%c~%d~%a[^~]~%a[^~]~",
                       &(admTable[i]->scriptName),
                       &(admTable[i]->name),
                       &(admTable[i]->type),
                       &(admTable[i]->length),
                       &(admTable[i]->choices),
                       &(admTable[i]->desc ) );
            }
            admTable[i]->group = actGroup;
            maxLen = 0;
            switch( admTable[i]->type ) {
               case 'A':
                  admTable[i]->allowed = (char *)calloc(256,1);
                  if( admTable[i]->choices[0] == '-'       && 
                      strlen(admTable[i]->choices) == 2    &&
                      strchr("dDfF",admTable[i]->choices[1]) != NULL ) {
                     strcpy(admTable[i]->allowed, FNAME_CHARS);
                  }
                  else {
                     p1 = strstr(admTable[i]->choices, "a-z");
                     if( p1 )
                        strcat( admTable[i]->allowed, LOW_CHARS );
                     p1 = strstr(admTable[i]->choices, "A-Z");
                     if( p1 )
                        strcat( admTable[i]->allowed, UP_CHARS );
                     p1 = strstr(admTable[i]->choices, "0-9");
                     if( p1 )
                        strcat( admTable[i]->allowed, NUM_CHARS );
                     p1 = admTable[i]->choices;
                     p2 = admTable[i]->allowed + strlen(admTable[i]->allowed);
                     while( *p1 != '\0' ) {
                        if( strncmp(p1, "a-z", 3) && strncmp(p1, "A-Z", 3) && strncmp(p1, "0-9", 3) ) {
                           *p2 = *p1;
                           p2++;
                           p1++;
                        }
                        else
                           p1 += 3;
                     }
                  }
                  maxLen = admTable[i]->length;

                  admTable[i]->sValue = ( char * )calloc( maxLen + 1, 1 );
                  if( admTable[i]->value != NULL )
                     strncpy( admTable[i]->sValue, admTable[i]->value, maxLen );

                  break;
               case 'F':
                  maxLen = strlen( admTable[i]->value );
                  admTable[i]->sValue = ( char * )calloc( maxLen + 5, 1 );
                  strcpy( admTable[i]->sValue, "    " );
                  strcat( admTable[i]->sValue, admTable[i]->value );

                  break;
               case 'I':
                  maxLen = 10;
                  admTable[i]->iValue = atoi( admTable[i]->value );
                  p1 = strchr( admTable[i]->choices, ',' );
                  if( p1 != NULL ) {
                     *p1 = '\0';
                     p1++;
                     admTable[i]->iValMin = atoi(admTable[i]->choices);
                     admTable[i]->iValMax = atoi(p1);
                     maxLen = strlen( p1 ) + 1;
                     p1--;
                     *p1 = ',';
                  }
                  else
                     admTable[i]->choices[0] = '\0';

                  break;
               case 'B':
                  maxLen = 1;
                  admTable[i]->itemStrings = strdup( admTable[i]->choices );
                  p1 = strchr( admTable[i]->itemStrings, ',' );
                  admTable[i]->iValue = atoi( admTable[i]->value );
                  if( p1 != NULL ) {
                     admTable[i]->lItems[0] = admTable[i]->itemStrings;
                     *p1 = '\0';
                     p1++;
                     admTable[i]->lItems[1] = p1;
                  }
                  break;
               case 'L':
                  admTable[i]->itemStrings = strdup( admTable[i]->choices );
                  admTable[i]->iValue = 0;        
                  j = 0;
                  p1 = admTable[i]->itemStrings;
                  p2 = strchr( p1, ',' );
                  while( p1 != NULL && j < MAX_LISTITEMS - 1 ) {
                     if( p2 != NULL )
                        *p2 = '\0';
                     admTable[i]->lItems[j] = p1;
                     if( ! strcmp( p1, admTable[i]->value ) )
                        admTable[i]->iValue = j;

                     if( strlen( p1 ) >= maxLen )
                        maxLen = strlen( p1 ) + 1;

                     if( p2 != NULL ) {
                        p1 = p2 + 1;
                        p2 = strchr( p1, ',' );
                     }
                     else
                        p1 = NULL;
                     j++;
                  }
                  admTable[i]->numLItems = j;
                  admTable[i]->lItems[j] = NULL;

                  if( actGroup == 0 && !strcmp(admTable[i]->name, "CONFIG") )
                     idxConfigVar = i;

                  break;
               default:
                  esyslog( "Illegal type <%c>\n", admTable[i]->type );
                  FreeTable( i );
                  admTable[i]->type = '\0';
                  admTable[i]->desc = (char *) malloc( strlen( buffer ) + 3 );
                  if( offset == 0 ) {
                     strcpy( admTable[i]->desc, "#!" );
                     strcat( admTable[i]->desc, buffer );
                  }
                  else
                     strcpy( admTable[i]->desc, buffer );

                  break;

            }
            if( admTable[i]->type != '\0' || admTable[i]->value == NULL || maxLen > strlen( admTable[i]->value ) ) {
               char * nVal = (char *)calloc(maxLen + 1,1); 
               if( admTable[i]->value ) {
                  strncpy( nVal, admTable[i]->value, maxLen );
                  free( admTable[i]->value );
               }
               admTable[i]->value = nVal;
            }
         }
         else {
            admTable[i]->desc = (char *) malloc( strlen( buffer ) + 1 );
            strcpy( admTable[i]->desc, buffer );
            if( buffer[ 0 ] == ':' ) {
               if( strlen( buffer ) > 1 && buffer[1] != ' ' ) {
                  if( numGroup < MAX_GROUPS )
                     numGroup++;

                  actGroup = numGroup;
               }
               else
                  actGroup = 0;
            }
            else {
               if( buffer[ 0 ] == '-' || ( buffer[ 0 ] == '#' && buffer[1] == '!' ) )
                  admTable[i]->group = actGroup;
            }
         }
         i++;
      }
      admTable[i]=NULL;
      fclose( fhdl );
      Set();
   }
   else {
      esyslog( "Error opening <%s>\n", configFile );
      Add( new cOsdItem( tr( "Config file not found" ), osUnknown, false ) );
   }
}

cYacMenuSetup::~cYacMenuSetup()
{
   if( CheckChanged() && Interface->Confirm(tr("Save changes?")) )
      Store();

   for( int i = 0; i < MAX_ENTRIES && admTable[i] != NULL; i++ ) {
      FreeTable( i );
      free( admTable[ i ] );
   }
   if( bStored ) {
      char buffer[ 512 ];
      strcpy(buffer,YAC_DIR);
      strcat(buffer, SAVE_SCRIPT);
      dsyslog( "Executing <%s>", buffer );
      system( buffer );
   }
   else
      dsyslog( "Leaving yacoto setup without saving" );
}


void cYacMenuSetup::Set( void )
{
   int i;
   bool bActiveConfig = false;

   Clear();
   SetSection( tr("Yacoto Setup") );

   for( i = 0; i < MAX_ENTRIES && admTable[i] != NULL; i++ ) {
      if( admTable[i]->desc && *(admTable[i]->desc) == ':' && 
          admTable[i]->type == '\0' && admTable[i]->group == 0 &&
          idxConfigVar >= 0 ) {
         if( !strcmp( admTable[i]->desc + 1, admTable[idxConfigVar]->lItems[admTable[idxConfigVar]->iValue] ) ) {
            char buffer[256];
            sprintf( buffer, "--- %s %s ---", admTable[i]->desc + 1, tr( "settings" ));
            Add( new cOsdItem( "", osUnknown, false ) );
            Add( new cOsdItem( buffer, osUnknown, false ) );
            bActiveConfig = true;
         }
         else
            bActiveConfig = false;
      }
      else {
         if( admTable[i]->group == 0 || bActiveConfig == true )
            AddMenuEntry( admTable[i] );
      }
   }
   activeConfigValue = admTable[idxConfigVar]->iValue;
   SetHelp( tr("Save+Exit"), tr("Save") );
//    SetCurrent(Get(pos > 1 ? pos : 2));
   Display();
}


void cYacMenuSetup::Store(void)
{
   FILE *fhdl = fopen( configFile, "w" );
   const char *valPtr = NULL;

   Skins.Message(mtInfo, tr("Saving settings"),1);
   Setup.Save();

   strncpy( activeConfig, admTable[idxConfigVar]->lItems[admTable[idxConfigVar]->iValue], sizeof(activeConfig));
   for( int i=0; i < MAX_ENTRIES && admTable[i] != NULL; i++ ) {
      if( admTable[i]->type != '\0' ) {
         switch( admTable[i]->type ) {
            case 'A':
               valPtr = admTable[i]->sValue;
               break;
            case 'F':
               valPtr = admTable[i]->value;
               break;
            case 'I':
               strcpy( admTable[i]->value, itoa( admTable[i]->iValue ) );
               valPtr = admTable[i]->value;
               break;
            case 'B':
               strcpy( admTable[i]->value, itoa( admTable[i]->iValue ) );
               valPtr = admTable[i]->value;
               break;
            case 'L':
               strcpy( admTable[i]->value, admTable[i]->lItems[admTable[i]->iValue] );
               valPtr = admTable[i]->lItems[admTable[i]->iValue];
               break;
            default:
               esyslog( "Illegal type <%c>\n", admTable[i]->type );
               break;
         }
         fprintf( fhdl, "%s~%s~%s~%c~%d~%s~%s~\n",
                  admTable[i]->scriptName,
                  admTable[i]->name,
                  valPtr,
                  admTable[i]->type,
                  admTable[i]->length,
                  admTable[i]->choices,
                  admTable[i]->desc );
      }
      else
         fprintf( fhdl, "%s\n", admTable[i]->desc );
   }
   fclose( fhdl );

   bStored = true;
   bChanged = false;
}


bool cYacMenuSetup::CheckChanged(void)
{
   if( !bChanged ) {
      for( int i=0; i < MAX_ENTRIES && admTable[i] != NULL && !bChanged; i++ ) {
         if( admTable[i]->type != '\0' ) {
            switch( admTable[i]->type ) {
               case 'A':
                  if( strcmp( admTable[i]->value, admTable[i]->sValue ) )
                     bChanged = true;
                  break;
               case 'L':
                  if( strcmp( admTable[i]->value, admTable[i]->lItems[admTable[i]->iValue] ) )
                     bChanged = true;
                  break;
               case 'I':
               case 'B':
                  if( atoi( admTable[i]->value ) != admTable[i]->iValue )
                     bChanged = true;
                  break;
            }
         }
      }
   }

   return bChanged;
}


void cYacMenuSetup::AddMenuEntry( ADMIN_ENTRY *admEntry )
{
   char buffer[256];
   switch( admEntry->type ) {
      case 'A':
         Add(new cMenuEditStrItem( tr(admEntry->desc), admEntry->sValue,
                                   admEntry->length + 1, admEntry->allowed ) );
         break;

      case 'F':
         admEntry->iValue = 0;
         if( strlen( admEntry->value ) > 16 ) {
            Add(new cOsdItem( tr(admEntry->desc), osUnknown, false ));
            Add(new cOsdItem( admEntry->sValue, osUnknown, false ));
         }
         else {
            sprintf( buffer, "%s\t%s", tr(admEntry->desc), admEntry->value);
            Add(new cOsdItem( buffer, osUnknown, false ));
         }
         break;

      case 'I':
         if( admEntry->iValMin != admEntry->iValMax )
            Add(new cMenuEditIntItem( tr(admEntry->desc), &(admEntry->iValue),
                                      admEntry->iValMin, admEntry->iValMax ));
         else
            Add(new cMenuEditIntItem( tr(admEntry->desc), &(admEntry->iValue)));
         break;

      case 'B':
         if( admEntry->lItems[0] != NULL )
            Add(new cMenuEditBoolItem( tr(admEntry->desc), &(admEntry->iValue),
                                       admEntry->lItems[0], admEntry->lItems[1] ));
         else
            Add(new cMenuEditBoolItem( tr(admEntry->desc), &(admEntry->iValue)));
         break;

      case 'L':
         Add(new cMenuEditStraItem( tr(admEntry->desc), &(admEntry->iValue), admEntry->numLItems, admEntry->lItems));
         break;

      default:
         Add( new cOsdItem( tr(admEntry->desc + 1), osUnknown, false ) );
   }
}

void cYacMenuSetup::FreeTable( int idx )
{
   if( admTable[idx]->name != NULL ) {
      free( admTable[idx]->name );
      admTable[idx]->name = NULL;
   }

   if( admTable[idx]->value != NULL ) {
      free( admTable[idx]->value );
      admTable[idx]->value = NULL;
   }

   if( admTable[idx]->choices != NULL ) {
      free( admTable[idx]->choices );
      admTable[idx]->choices = NULL;
   }

   if( admTable[idx]->itemStrings != NULL ) {
      free( admTable[idx]->itemStrings );
      admTable[idx]->itemStrings = NULL;
   }

   if( admTable[idx]->scriptName != NULL ) {
      free( admTable[idx]->scriptName );
      admTable[idx]->scriptName = NULL;
   }

   if( admTable[idx]->desc != NULL ) {
      free( admTable[idx]->desc );
      admTable[idx]->desc = NULL;
   }

   if( admTable[idx]->allowed != NULL ) {
      free( admTable[idx]->allowed );
      admTable[idx]->allowed = NULL;
   }
}

eOSState cYacMenuSetup::ProcessKey(eKeys Key)
{
   eOSState state;
   bool bHadSubMenu = HasSubMenu();
   bool bCfgChanged = false;

   state = cOsdMenu::ProcessKey(Key);

   if( bHadSubMenu )
      return state;

   switch( Key ) {
      case kOk:
         break;
      case kRed:
         Store();
         state = osBack;
         break;
      case kGreen:
         Store();
         break;
      case kYellow:
         break;
      case kLeft: 
      case kRight:
         if( activeConfigValue != admTable[idxConfigVar]->iValue ) {
            activeConfigValue = admTable[idxConfigVar]->iValue;
            bCfgChanged = true;
         }
      default:
         break;
   }

   if( bCfgChanged )
      Set();

   return state;
}

