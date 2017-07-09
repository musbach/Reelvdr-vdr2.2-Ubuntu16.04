/*
 * epgsearchclient.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/plugin.h>

static const char *VERSION        = "0.0.2";
static const char *DESCRIPTION    = "A client for epgsearch services";
static const char *MAINMENUENTRY  = "Epgsearchclient";

// --- cMenuEpgsearch_Client ---------------------------------------------------------
class cMenuEpgsearch_Client : public cOsdMenu {
public:
  cMenuEpgsearch_Client();
  virtual eOSState ProcessKey(eKeys Key);
  eOSState SearchWithEPGSearch();
  eOSState AddTimerWithEPGSearch();
  eOSState EditFirstTimerWithEPGSearch();
  eOSState TriggerSearchtimerUpdate();
  eOSState EnableSearchtimerUpdate(bool enable);
};

cMenuEpgsearch_Client::cMenuEpgsearch_Client()
:cOsdMenu("EPGSearch client demo")
{
    Add(new cOsdItem(hk("Enable searchtimer updates")));
    Add(new cOsdItem(hk("Disable searchtimer updates")));
    Add(new cOsdItem(hk("Search for repeats of 'Tagesschau'")));
    Add(new cOsdItem(hk("Add a new timer")));
    Add(new cOsdItem(hk("Edit first existing timer")));
    Add(new cOsdItem(hk("Trigger searchtimer update")));
}

struct Epgsearch_search_v1_0
{
// in
    char* query;               // search term
    int mode;                  // search mode (0=phrase, 1=and, 2=or, 3=regular expression)
    int channelNr;             // channel number to search in (0=any)
    bool useTitle;             // search in title
    bool useSubTitle;          // search in subtitle
    bool useDescription;       // search in description
// out
    cOsdMenu* pResultMenu;   // pointer to the menu of results
};

struct Epgsearch_exttimeredit_v1_0
{
// in
    cTimer* timer;             // pointer to the timer to edit
    bool bNew;                 // flag that indicates, if this is a new timer or an existing one
    const cEvent* event;             // pointer to the event corresponding to this timer (may be NULL)
// out
    cOsdMenu* pTimerMenu;   // pointer to the menu of results
};

// Data structure for service "Epgsearch-enablesearchtimers-v1.0"
struct Epgsearch_enablesearchtimers_v1_0
{
// in
      bool enable;           // enable search timer thread?
};

// Data structure for service "Epgsearch-updatesearchtimers-v1.0"
struct Epgsearch_updatesearchtimers_v1_0
{
// in
      bool showMessage;           // inform via osd when finished?
};


eOSState cMenuEpgsearch_Client::SearchWithEPGSearch()
{
    cPlugin *p = cPluginManager::GetPlugin("epgsearch");
    if (p)
    {
 	Epgsearch_search_v1_0* serviceData = new Epgsearch_search_v1_0;
	serviceData->query = strdup("Tagesschau");
	serviceData->mode = 0;
	serviceData->channelNr = 0;
	serviceData->useTitle = true;
	serviceData->useSubTitle = serviceData->useDescription = false;

	cOsdMenu* pMenu = NULL;
	if (p->Service("Epgsearch-search-v1.0", serviceData))
	    pMenu = serviceData->pResultMenu;
	else
	    Skins.Message(mtError, "EPGSearch does not support this service!");
	
	delete serviceData;

	if (pMenu)
	    return AddSubMenu(pMenu);	
	else
	    return osContinue;
    }
    else
    {
	Skins.Message(mtError, "EPGSearch does not exist!");
	return osContinue;
    }
}

eOSState cMenuEpgsearch_Client::AddTimerWithEPGSearch()
{
    cPlugin *p = cPluginManager::GetPlugin("epgsearch");
    if (p)
    {
 	Epgsearch_exttimeredit_v1_0* serviceData = new Epgsearch_exttimeredit_v1_0;
	cTimer* pTimer = new cTimer;
	pTimer->SetFlags(tfActive);
	serviceData->timer = pTimer;
	serviceData->bNew = true;
	serviceData->event = NULL;
	
	cOsdMenu* pMenu = NULL;
	if (p->Service("Epgsearch-exttimeredit-v1.0", serviceData))
	    pMenu = serviceData->pTimerMenu;
	else
	    Skins.Message(mtError, "EPGSearch does not support this service!");
	
	delete serviceData;
	
	if (pMenu)
	    return AddSubMenu(pMenu);	
	else
	    return osContinue;
    }
    else
    {
	Skins.Message(mtError, "EPGSearch does not exist!");
	return osContinue;
    }
}

eOSState cMenuEpgsearch_Client::EditFirstTimerWithEPGSearch()
{
    cPlugin *p = cPluginManager::GetPlugin("epgsearch");
    if (p)
    {
	cTimer* pTimer = Timers.First();
	if (pTimer)
	{
	    Epgsearch_exttimeredit_v1_0* serviceData = new Epgsearch_exttimeredit_v1_0;
	    pTimer->SetFlags(tfActive);
	    serviceData->timer = pTimer;
	    serviceData->bNew = false;
	    serviceData->event = pTimer->Event();	 

	    cOsdMenu* pMenu = NULL;
	    if (p->Service("Epgsearch-exttimeredit-v1.0", serviceData))
		pMenu = serviceData->pTimerMenu;
	    else
		Skins.Message(mtError, "EPGSearch does not support this service!");

	    delete serviceData;
	    
	    if (pMenu)
		return AddSubMenu(pMenu);	
	    else
		return osContinue;
	}
	else
	{
	    Skins.Message(mtError, "No timer to edit!");
	    return osContinue;
	}
    }
    else
    {
	Skins.Message(mtError, "EPGSearch does not exist!");
	return osContinue;
    }
}

eOSState cMenuEpgsearch_Client::EnableSearchtimerUpdate(bool enable)
{
    cPlugin *p = cPluginManager::GetPlugin("epgsearch");
    if (p)
    {
      Epgsearch_enablesearchtimers_v1_0* serviceData = new Epgsearch_enablesearchtimers_v1_0;
      serviceData->enable = enable;
      if (!p->Service("Epgsearch-enablesearchtimers-v1.0", (void*) serviceData))
	Skins.Message(mtError, "EPGSearch does not support this service!");
      return osContinue;
    }
    else
    {
	Skins.Message(mtError, "EPGSearch does not exist!");
	return osContinue;
    }
}

eOSState cMenuEpgsearch_Client::TriggerSearchtimerUpdate()
{
    cPlugin *p = cPluginManager::GetPlugin("epgsearch");
    if (p)
    {
      Epgsearch_updatesearchtimers_v1_0* serviceData = new Epgsearch_updatesearchtimers_v1_0;
      serviceData->showMessage = true;
      if (!p->Service("Epgsearch-updatesearchtimers-v1.0", (void*) serviceData))
	Skins.Message(mtError, "EPGSearch does not support this service!");
      return osContinue;
    }
    else
    {
	Skins.Message(mtError, "EPGSearch does not exist!");
	return osContinue;
    }
}

eOSState cMenuEpgsearch_Client::ProcessKey(eKeys Key)
{
    eOSState state = cOsdMenu::ProcessKey(Key);

    if (state == osUnknown) {
	switch (Key) {
	    case kOk:
		if (Current() == 0)
		    return EnableSearchtimerUpdate(true);
		else if (Current() == 1)
		    return EnableSearchtimerUpdate(false);
		else if (Current() == 2)
		    return SearchWithEPGSearch();
		else if (Current() == 3)
		    return AddTimerWithEPGSearch();
		else if (Current() == 4)
		    return EditFirstTimerWithEPGSearch();
		else if (Current() == 5)
		    return TriggerSearchtimerUpdate();
		else
		    return osContinue;
	    default:   break;
	}
    }
    return state;
}

class cPluginEpgsearchclient : public cPlugin {
private:
  // Add any member variables or functions you may need here.
public:
  cPluginEpgsearchclient(void);
  virtual ~cPluginEpgsearchclient();
  virtual const char *Version(void) { return VERSION; }
  virtual const char *Description(void) { return DESCRIPTION; }
  virtual const char *CommandLineHelp(void);
  virtual bool ProcessArgs(int argc, char *argv[]);
  virtual bool Initialize(void);
  virtual bool Start(void);
  virtual void Stop(void);
  virtual void Housekeeping(void);
  virtual const char *MainMenuEntry(void) { return MAINMENUENTRY; }
  virtual cOsdObject *MainMenuAction(void);
  virtual cMenuSetupPage *SetupMenu(void);
  virtual bool SetupParse(const char *Name, const char *Value);
  virtual bool Service(const char *Id, void *Data = NULL);
  };

cPluginEpgsearchclient::cPluginEpgsearchclient(void)
{
  // Initialize any member variables here.
  // DON'T DO ANYTHING ELSE THAT MAY HAVE SIDE EFFECTS, REQUIRE GLOBAL
  // VDR OBJECTS TO EXIST OR PRODUCE ANY OUTPUT!
}

cPluginEpgsearchclient::~cPluginEpgsearchclient()
{
  // Clean up after yourself!
}

const char *cPluginEpgsearchclient::CommandLineHelp(void)
{
  // Return a string that describes all known command line options.
  return NULL;
}

bool cPluginEpgsearchclient::ProcessArgs(int argc, char *argv[])
{
  // Implement command line argument processing here if applicable.
  return true;
}

bool cPluginEpgsearchclient::Initialize(void)
{
  // Initialize any background activities the plugin shall perform.
  return true;
}

bool cPluginEpgsearchclient::Start(void)
{
  // Start any background activities the plugin shall perform.
  return true;
}

void cPluginEpgsearchclient::Stop(void)
{
  // Stop any background activities the plugin shall perform.
}

void cPluginEpgsearchclient::Housekeeping(void)
{
  // Perform any cleanup or other regular tasks.
}

cOsdObject *cPluginEpgsearchclient::MainMenuAction(void)
{
    return new cMenuEpgsearch_Client;
}

cMenuSetupPage *cPluginEpgsearchclient::SetupMenu(void)
{
  // Return a setup menu in case the plugin supports one.
  return NULL;
}

bool cPluginEpgsearchclient::SetupParse(const char *Name, const char *Value)
{
  // Parse your own setup parameters and store their values.
  return false;
}

bool cPluginEpgsearchclient::Service(const char *Id, void *Data)
{
  // Handle custom service requests from other plugins
  return false;
}

VDRPLUGINCREATOR(cPluginEpgsearchclient); // Don't touch this!
