/*
 * yac-tools.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */
#include <vdr/plugin.h>

#define BUF_SIZE 1000

const char * GetStatusInfo(void)
{
   static char * commandResult = NULL;
   char cmd[ 255 ];
   if( commandResult != NULL ) {
      free(commandResult);
      commandResult = NULL;
   }
   strcpy(cmd,YAC_DIR);
   strcat(cmd,"/yac_show_status.sh");

   dsyslog("executing command '%s'", cmd);
   FILE *p = popen(cmd, "r");
   if( p ) {
      int l = 0;
      int c;
      while( (c = fgetc(p)) != EOF ) {
         if( l % BUF_SIZE == 0 )
            commandResult = (char *)realloc(commandResult, l + BUF_SIZE + 1);
         commandResult[l++] = c;
      }
      if( commandResult )
         commandResult[l] = 0;
      pclose(p);
   }
   else
      esyslog("ERROR: can't open pipe for command '%s'", cmd);

   return commandResult;
}

