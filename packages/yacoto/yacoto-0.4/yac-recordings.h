/*
 * yac-recordings.h: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */
#define MAX_SEL 100
#define MAX_AUDIOTRACKS 10
#define MAX_TITLELEN 128

#include <vdr/osdbase.h>

enum audioTrackState {
   at_ignore = 0,
   at_use,
   at_master
};

enum moveMode {
   move_up,
   move_down,
   move_top,
   move_bottom
};

typedef struct audTr {
   char *desc;
   audioTrackState state;
} strAudioTracks;


class cYacRecItem {
private:
   char titleBuffer[MAX_TITLELEN + 1];
   char videoInfo[64];
   char *name;
   int GetLength(void);
   int GetCutLength(void);
   bool CheckConverted(const char * filename);
   int cutLength;
   int recFullLength;
   int recLength;
   int recSize;
   int numATracks;
   bool bConverted;
   strAudioTracks audioTracks[MAX_AUDIOTRACKS];
   cRecording *cRec;
public:
   cYacRecItem(const cRecording *Recording);
   ~cYacRecItem();
   const char *Title(void);
   const char *VideoInfo(void);
   int RecLength(void) { return recLength;};
   int RecSize(void) { return recSize;};
   int RecCutLength(void) { return cutLength;};
   const char *Name(void) { return name;};
   int NumATracks(void) { return numATracks;};
   bool IsConverted(void) { return bConverted;};
   void SetConverted(void) { bConverted = true;};
   audioTrackState TrackState(int idx);
   void SelectTrack(int idx, audioTrackState select);
   const char *TrackInfo(int idx);
   cRecording *CRec(void) { return cRec;};
};

class cYacRecs {
private:
   int numItems;
   int yacSelState;
   int yacActionState;
public:
   cYacRecs(void);
   ~cYacRecs(void) {};
   void Clear(void);
   bool Selected(cRecording *rec);
   int  IsActive(void) { return yacActionState;};
   bool Start(void);
   bool Remove(cRecording *rec);
   bool Add(cRecording *rec);
   bool Move(cRecording *rec, moveMode mm);
   int NumItems(void) { return numItems;};
   bool Changed(int *state);
   cYacRecItem *yacRecs[ MAX_SEL ];
};

#define MAX_NAME_LEN 1024

extern cYacRecs yacRecordings;
extern char yacProjName[MAX_NAME_LEN];
extern bool yacMergeRecs;
