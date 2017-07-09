/*
 * yacoto.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/plugin.h>
#include <string>

#include "yac-setup.h"
#include "yac-tools.h"
#include "yac-menurecordings.h"

#if VDRVERSNUM < 10507
#include "i18n.h"
#endif

static const char *VERSION        = "0.4";
static const char *DESCRIPTION    = "Convert recordings";
static const char *MAINMENUENTRY  = "Convert recordings";

class cPluginYacoto : public cPlugin {
private:
   // Add any member variables or functions you may need here.
   public:
   cPluginYacoto(void);
   virtual ~cPluginYacoto();
   virtual const char *Version(void) { return VERSION;}
   virtual const char *Description(void) { return tr(DESCRIPTION);}
   virtual const char *CommandLineHelp(void);
   virtual bool ProcessArgs(int argc, char *argv[]);
   virtual bool Initialize(void);
   virtual bool Start(void);
   virtual void Stop(void);
   virtual void Housekeeping(void);
   //virtual void MainThreadHook(void);
   virtual cString Active(void);
   virtual const char *MainMenuEntry(void) { return tr(MAINMENUENTRY);}
   virtual cOsdObject *MainMenuAction(void);
   virtual cMenuSetupPage *SetupMenu(void);
   virtual bool SetupParse(const char *Name, const char *Value);
};

cPluginYacoto::cPluginYacoto(void)
{
   // Initialize any member variables here.
   // DON'T DO ANYTHING ELSE THAT MAY HAVE SIDE EFFECTS, REQUIRE GLOBAL
   // VDR OBJECTS TO EXIST OR PRODUCE ANY OUTPUT!
}

cPluginYacoto::~cPluginYacoto()
{
   // Clean up after yourself!
}

const char *cPluginYacoto::CommandLineHelp(void)
{
   // Return a string that describes all known command line options.
   return NULL;
}

bool cPluginYacoto::ProcessArgs(int argc, char *argv[])
{
   // Implement command line argument processing here if applicable.
   return true;
}

bool cPluginYacoto::Initialize(void)
{
   // Initialize any background activities the plugin shall perform.
#if VDRVERSNUM < 10507
   RegisterI18n( MyPluginPhrases );
#endif
   return true;
}

bool cPluginYacoto::Start(void)
{
   // Start any background activities the plugin shall perform.
   return true;
}

void cPluginYacoto::Stop(void)
{
   // Stop any background activities the plugin shall perform.
}

void cPluginYacoto::Housekeeping(void)
{
   // Perform any cleanup or other regular tasks.
}

cString cPluginYacoto::Active(void)
{
   // Return a message string if shutdown should be postponed
   if ( strstr( GetStatusInfo(), " is running" ) != NULL )
      return cString( tr( "Yacoto conversion is running" ) );
      
   return NULL;
}
    
cOsdObject *cPluginYacoto::MainMenuAction(void)
{
   // Perform the action when selected from the main VDR menu.
   return new cYacMenuRecordings(NULL, 0, true);
}

cMenuSetupPage *cPluginYacoto::SetupMenu(void)
{
   // Return a setup menu in case the plugin supports one.
   return new cYacMenuSetup();
}

bool cPluginYacoto::SetupParse(const char *Name, const char *Value)
{
   // Parse your own setup parameters and store their values.
   return true;
}

VDRPLUGINCREATOR(cPluginYacoto); // Don't touch this!
