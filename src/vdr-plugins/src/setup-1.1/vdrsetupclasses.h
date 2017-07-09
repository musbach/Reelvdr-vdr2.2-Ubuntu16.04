/***********************************************************
 * Header file holding Class Definitions from <VDR>/menu.c *
 *                                                         *
 * This file is generated automaticly!                     *
 *                                                         *
 ***********************************************************/

#ifndef VDRSETUPCLASSES_H 
#define VDRSETUPCLASSES_H 

#include "vdr/diseqc.h"
#if VDRVERSNUM >= 10716
#include "vdr/sourceparams.h"
#endif

#if VDRVERSNUM >= 10716
class cMenuEditChannel : public cOsdMenu {
private:
  cChannel *channel;
  cChannel data;
  cSourceParam *sourceParam;
  char name[256];
  void Setup(void);
public:
  cMenuEditChannel(cChannel *Channel, bool New = false);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuEditChannel"; }
#endif /* GRAPHTFT */
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuChannels : public cOsdMenu {
private:
  int number;
  cTimeMs numberTimer;
  void Setup(void);
  cChannel *GetChannel(int Index);
  void Propagate(void);
protected:
  eOSState Number(eKeys Key);
  eOSState Switch(void);
  eOSState Edit(void);
  eOSState New(void);
  eOSState Delete(void);
  virtual void Move(int From, int To);
public:
  cMenuChannels(void);
  ~cMenuChannels();
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuChannels"; }
#endif /* GRAPHTFT */
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuEditFolder : public cOsdMenu {
private:
  cList<cNestedItem> *list;
  cNestedItem *folder;
  char name[PATH_MAX];
  int subFolder;
  eOSState Confirm(void);
public:
  cMenuEditFolder(const char *Dir, cList<cNestedItem> *List, cNestedItem *Folder = NULL);
  cString GetFolder(void);
  virtual eOSState ProcessKey(eKeys Key);
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuTimers : public cOsdMenu {
private:
  int helpKeys;
  eOSState Edit(void);
  eOSState New(void);
  eOSState Delete(void);
  eOSState OnOff(void);
  eOSState Info(void);
  cTimer *CurrentTimer(void);
  void SetHelpKeys(void);
#ifdef USE_TIMERINFO
  void ActualiseDiskStatus(void);
  bool actualiseDiskStatus;
#endif /* TIMERINFO */
public:
  cMenuTimers(void);
  virtual ~cMenuTimers();
#ifdef USE_TIMERINFO
  virtual void Display(void);
#endif /* TIMERINFO */
  virtual eOSState ProcessKey(eKeys Key);
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuWhatsOn : public cOsdMenu {
private:
  bool now;
  bool canSwitch;
  int helpKeys;
  int timerState;
  eOSState Record(void);
  eOSState Switch(void);
  static int currentChannel;
  static const cEvent *scheduleEvent;
  bool Update(void);
  void SetHelpKeys(void);
public:
  cMenuWhatsOn(const cSchedules *Schedules, bool Now, int CurrentChannelNr);
  static int CurrentChannel(void) { return currentChannel; }
  static void SetCurrentChannel(int ChannelNr) { currentChannel = ChannelNr; }
  static const cEvent *ScheduleEvent(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return now ? "MenuWhatsOnNow" : "MenuWhatsOnNext"; }
  virtual void Display(void);
#endif /* GRAPHTFT */
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuSchedule : public cOsdMenu {
private:
  cSchedulesLock schedulesLock;
  const cSchedules *schedules;
  bool now, next;
  bool canSwitch;
  int helpKeys;
  int timerState;
  eOSState Number(void);
  eOSState Record(void);
  eOSState Switch(void);
  void PrepareScheduleAllThis(const cEvent *Event, const cChannel *Channel);
  void PrepareScheduleThisThis(const cEvent *Event, const cChannel *Channel);
  void PrepareScheduleThisAll(const cEvent *Event, const cChannel *Channel);
  void PrepareScheduleAllAll(const cEvent *Event, const cChannel *Channel);
  bool Update(void);
  void SetHelpKeys(void);
public:
  cMenuSchedule(void);
  virtual ~cMenuSchedule();
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSchedule"; }
  virtual void Display(void);
#endif /* GRAPHTFT */
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuCam : public cOsdMenu {
private:
  cCamSlot *camSlot;
  cCiMenu *ciMenu;
  cCiEnquiry *ciEnquiry;
  char *input;
  int offset;
  time_t lastCamExchange;
  void GenerateTitle(const char *s = NULL);
  void QueryCam(void);
  void AddMultiLineItem(const char *s);
  void Set(void);
  eOSState Select(void);
public:
  cMenuCam(cCamSlot *CamSlot);
  virtual ~cMenuCam();
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuCam"; }
#endif /* GRAPHTFT */
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuPathEdit : public cOsdMenu {
private:
  cString path;
  char folder[PATH_MAX];
  char name[NAME_MAX];
  cMenuEditStrItem *folderItem;
  int pathIsInUse;
  eOSState SetFolder(void);
  eOSState Folder(void);
  eOSState ApplyChanges(void);
public:
  cMenuPathEdit(const char *Path);
  virtual eOSState ProcessKey(eKeys Key);
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuRecordingEdit : public cOsdMenu {
private:
  cRecording *recording;
  cString originalFileName;
  int recordingsState;
  char folder[PATH_MAX];
  char name[NAME_MAX];
  int priority;
  int lifetime;
  cMenuEditStrItem *folderItem;
  cMenuEditStrItem *nameItem;
  const char *buttonFolder;
  const char *buttonAction;
  const char *buttonDeleteMarks;
  const char *actionCancel;
  const char *doCut;
  int recordingIsInUse;
  void Set(void);
  void SetHelpKeys(void);
  bool RefreshRecording(void);
  eOSState SetFolder(void);
  eOSState Folder(void);
  eOSState Action(void);
  eOSState RemoveName(void);
  eOSState DeleteMarks(void);
  eOSState ApplyChanges(void);
public:
  cMenuRecordingEdit(cRecording *Recording);
  virtual eOSState ProcessKey(eKeys Key);
  };
#endif

#if VDRVERSNUM >= 10716
class cMenuRecording : public cOsdMenu {
private:
  cRecording *recording;
  cString originalFileName;
  int recordingsState;
  bool withButtons;
  bool RefreshRecording(void);
public:
  cMenuRecording(cRecording *Recording, bool WithButtons = false);
  virtual void Display(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuRecording"; }
#endif /* GRAPHTFT */
};
#endif

#if VDRVERSNUM >= 10716
class cMenuRenameRecording : public cOsdMenu {
private:
  char name[MaxFileName];
  cMenuEditStrItem *file;
  cOsdItem *marksItem, *resumeItem;
  bool isResume, isMarks;
  cRecording *recording;
  void SetHelpKeys(void);
  eOSState SetFolder(void);
public:
  cMenuRenameRecording(cRecording *Recording);
  virtual eOSState ProcessKey(eKeys Key);
};
#endif

class cMenuSetupBase : public cMenuSetupPage {
protected:
  cSetup data;
  virtual void Store(void);
public:
  cMenuSetupBase(void);
  };


class cMenuSetupOSD : public cMenuSetupBase {
private:
  const char *useSmallFontTexts[3];
  const char *keyColorTexts[4];
  int osdLanguageIndex;
  int numSkins;
  int originalSkinIndex;
  int skinIndex;
  const char **skinDescriptions;
  cThemes themes;
  int originalThemeIndex;
  int themeIndex;
  cStringList fontOsdNames, fontSmlNames, fontFixNames;
  int fontOsdIndex, fontSmlIndex, fontFixIndex;
  virtual void Set(void);
public:
  cMenuSetupOSD(void);
  virtual ~cMenuSetupOSD();
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetupOsd"; }
#endif /* GRAPHTFT */
  };


class cMenuSetupEPG : public cMenuSetupBase {
private:
#ifdef USE_NOEPG
  const char *noEPGModes[2];
#endif /* USE_NOEPG */
  int originalNumLanguages;
  int numLanguages;
  void Setup(void);
public:
  cMenuSetupEPG(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetupEpg"; }
#endif /* GRAPHTFT */  
  };


class cMenuSetupDVB : public cMenuSetupBase {
private:
  int originalNumAudioLanguages;
  int numAudioLanguages;
  int originalNumSubtitleLanguages;
  int numSubtitleLanguages;
  void Setup(void);
  const char *videoDisplayFormatTexts[3];
  const char *updateChannelsTexts[6];
  const char *standardComplianceTexts[3];
public:
  cMenuSetupDVB(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetupDvb"; }
#endif /* GRAPHTFT */
  };


class cMenuSetupLNB : public cMenuSetupBase {
private:
  cSatCableNumbers satCableNumbers;
  void Setup(void);
public:
  cMenuSetupLNB(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetupLnb"; }
#endif /* GRAPHTFT */
  };


class cMenuSetupCAM : public cMenuSetupBase {
private:
  const char *activationHelp;
  eOSState Menu(void);
  eOSState Reset(void);
  eOSState Activate(void);
  void SetHelpKeys(void);
public:
  cMenuSetupCAM(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetupCam"; }
#endif /* GRAPHTFT */
  };


class cMenuSetupRecord : public cMenuSetupBase {
private:
  const char *pauseKeyHandlingTexts[3];
  const char *delTimeshiftRecTexts[3];
#ifdef USE_DVLVIDPREFER
  void Set(void);
  int tmpNVidPrefer,
      tmpUseVidPrefer;
#endif /* DVLVIDPREFER */
public:
  cMenuSetupRecord(void);
#ifdef USE_DVLVIDPREFER
  eOSState ProcessKey(eKeys key);
#endif /* DVLVIDPREFER */
  };


class cMenuSetupReplay : public cMenuSetupBase {
protected:
  virtual void Store(void);
public:
  cMenuSetupReplay(void);
  };


class cMenuSetupMisc : public cMenuSetupBase {
#ifdef USE_VOLCTRL
private:
  const char *lrChannelGroupsTexts[3];
  const char *lrForwardRewindTexts[3];
  void Setup(void);
#endif /* VOLCTRL */
public:
  cMenuSetupMisc(void);
#ifdef USE_VOLCTRL
  virtual eOSState ProcessKey(eKeys Key);
#endif /* VOLCTRL */
  };


class cMenuSetupPlugins : public cMenuSetupBase {
public:
  cMenuSetupPlugins(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetupPlugins"; }
#endif /* GRAPHTFT */
  };


#if VDRVERSNUM >= 10716
class cMenuSetup : public cOsdMenu {
private:
  virtual void Set(void);
  eOSState Restart(void);
public:
  cMenuSetup(void);
  virtual eOSState ProcessKey(eKeys Key);
#ifdef USE_GRAPHTFT
  virtual const char* MenuKind() { return "MenuSetup"; }
#endif /* GRAPHTFT */
  };
#endif

#endif // VDRSETUPCLASSES_H 
