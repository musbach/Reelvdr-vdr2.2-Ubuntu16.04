/***************************************************************************
 *   Copyright (C) 2005 by Reel Multimedia                                 *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

// MenuEditChannel.h

#ifndef P__MENU_EDITCHANNEL_H
#define P__MENU_EDITCHANNEL_H

//#include <vdr/menu.h>
#include "menu-vdr.h"
//#include "menu.h"
#include <vdr/menuitems.h>
#include <vdr/osdbase.h>
#if APIVERSNUM > 10700
  #include <vdr/sourceparams.h>
#endif

// ------------------------------------
#define MAXAPIDS 32

typedef struct
{
        int number;
        char *name;
        char *provider;
        char *shortName;
        int type;
        unsigned int frequency;
        int srate;
        int coderateH;
        int coderateL;
        int guard;
        int polarization;
        int inversion;
        int modulation;
        int source;
        int transmission;
        int bandwidth;
        int hierarchy;
        int vpid;
        int ppid;
        int sid;
        int rid;
        int tid;
        int tpid;
        int nid;
        int caids[MAXCAIDS];
        int NumCaids;
        int apids[MAXAPIDS];
        int NumApids;
        int dpids[MAXDPIDS];
        int NumDpids;
        int eitpids[1];
        int NumEitpids;
        int sdtpids[1];
        int NumSdtpids;
} channel_t;


class cMenuEditMyCaItem : public cMenuEditIntItem
{
  public:
    cMenuEditMyCaItem(const char *Name, int *Value, bool EditingBouquet);
    eOSState ProcessKey(eKeys Key);

  protected:
    bool editingBouquet;
    bool Items[CA_ENCRYPTED_MIN];
    void Set(void);
};


class cMenuMyEditChannel : public cOsdMenu
{
  private:
    cChannel * channel;
    cChannel data;
    bool new_;
    char name[256];
    char titleBuf[128];
    void SetNew();
    void Setup(void);
#if APIVERSNUM > 10700
    cSourceParam *sourceParam;
#endif
  public:
    cMenuMyEditChannel(cChannel * Channel, bool New = false);
    virtual eOSState ProcessKey(eKeys Key);
};

#endif // P__MENU_EDITCHANNEL
