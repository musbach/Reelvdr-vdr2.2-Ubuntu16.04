/***************************************************************************
 *   Copyright (C) 2005 by Reel Multimedia;  Author:  Markus Hahn          *
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
 *
 ***************************************************************************
 *
 *   transponders.h
 *
 ***************************************************************************/

#ifndef _TRANSPONDERS__H
#define _TRANSPONDERS__H

#define DBGT "DEBUG [transponders]: "


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

#include <assert.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <vdr/channels.h>

#define TERR  0
#define CABLE 1
#define SAT   2
#define SATS2 3

#ifndef REELVDR

namespace setup
{
    std::string FileNameFactory(std::string Filename);
}

#endif

struct cScanParameters
{
    int card;
    int type;
    int source;
    int frequency;              // 0: Full band scan
    int symbolrate;
    int bandwidth;
    int polarization;
    int fec;
    int detail;                 // DVB-T: Scan +-166kHz offsets
    int modulation;             // DVB-C: auto, ...
    int symbolrate_mode;        // DVB-C: 0/1/2 intelligent/dumb/fixed symbolrate
};


class cTransponder;

typedef std::vector<std::string>::const_iterator consStrIter;
typedef std::vector<cTransponder*>::const_iterator constTpIter;
typedef std::vector<cTransponder*>::iterator TpIter;

// the source below is taken from http://www.parashift.com/c++-faq-lite/

inline int strToInt(const std::string & s)
{
    std::istringstream i(s);
    int x = -1;
    if (!(i >> x))
        ;                       // no error message
    //std::cerr << " error in strToInt(): " << s << std::endl;
    return x;
}

// --- Class cTransponder ------------------------------------------------------
   ///< base class which actual transponders can be derived

class cTransponder
{
  public:
    virtual ~ cTransponder() {};
    int ChannelNum() const;
    int Frequency() const;
    int Modulation() const;
    int Symbolrate() const;
    void SetFrequency(int f);
    void SetSymbolrate(int sr);
    void SetModulation(int mod);
    virtual bool SetTransponderData(cChannel * c, int Code = 0) = 0;
    ///<  set transponder Data to channel
    bool Scanned() const;
    void SetScanned();
    virtual void PrintData() const {}; ///< for debug purposes
    std::string IntToStr(int num);
    int StrToInt(std::string str);
    int IntToFec(int val);

  protected:
    cTransponder(int Frequency);
    int channelNum_;
    int frequency_;
    int symbolrate_;
    int modulation_;
    int bandwidth_;
    bool scanned_;

  private:
    //cTransponder(const cTransponder&); // private
    cTransponder & operator=(const cTransponder &);
    std::string service_;
};

// --- class cSatTransponder ---------------------------------------------------

class cSatTransponder:public cTransponder
{
  private:
    char pol_;
    int fec_;
    int rolloff_;
    int system_;
    //cSatTransponder(const cSatTransponder& obj); //?? what about cpy ctor

  public:
    cSatTransponder();          //?? what about cpy ctor
    cSatTransponder(int Frequency, char Pol, int SymbolRate, int Modulation, int FEC, int Rolloff = 0, int ModSystem = 0);
    bool SetTransponderData(cChannel * c, int Code = 0);
    ///<  set transponder Data to channel
    int RollOff() const;
    int FEC() const;
    void SetRollOff(int rolloff);
    void SetFEC(int fec);
    int System() const;
    void SetSystem(int system);
    char Polarization() const;
    bool Parse(const std::string & line);
    virtual void PrintData() const;
};

// --- class cTerrTransponder --------------------------------------------------

class cTerrTransponder:public cTransponder
{
  public:
    cTerrTransponder(int ChannelNr, int Frequency, int Bandwidth);
    ///< ChannelNr is only for debunging purposes
    cTerrTransponder();
    ~cTerrTransponder();
    bool SetTransponderData(cChannel * c, int Code = 0);
    ///<  set transponder Data to channel
    virtual void PrintData() const;

  private:
    int fec_l_;
    int fec_h_;
    int hierarchy_;
    int transmission_;
    int guard_;
};

// --- class cCableTransponder -------------------------------------------------

class cCableTransponder:public cTransponder
{
  public:
    cCableTransponder(int ChannelNr, int Frequency, int sRate, int Mod);
     ~cCableTransponder();
    bool SetTransponderData(cChannel * c, int Code = 0);
    virtual void PrintData() const;

  private:
    int fec_h_;
    int hierarchy_;
    int transmission_;
    int guard_;
};

// ---- Class cTransponders --------------------------------------
///< Container class for cTransponder class
///< can be created only once, and can hold
///< only one type of cTransponder

class cTransponders
{
  public:
    static void Create();
    ///< call Constructor and instance_
    static void Destroy();
    ///<  put this to your destructor of class calling Create()
    static cTransponders & GetInstance();
    ///<  gives you reference to existing cTransponders
    void Clear();
    ///< Clears all transponders in vector. deletes all allocated memmory
    ///< don`t  use v_tp_.clear() !
    std::vector < cTransponder * >v_tp_;

    //void Load(int source, scanParameters *scp);
    void Load(cScanParameters * scp);
    ///< loads complete transponder lists or single data for given source

    bool LoadNitTransponder(int Source);
    bool LoadTpl(const std::string & tpList);
    void Add(int Source, const cScanParameters & scp);
    void CalcTerrTpl();
    ///< Calculates terrestrial transponder lists and load them to cTransponder
    void CalcCableTpl(bool Complete, cScanParameters * scp);
    ///< Calculates cable Transponder lists and load them to cTransponder

    static int channel2Frequency(int region, int channel, int &bandwidth);
    ///< Common data of signal source:
    static int StatToS2Mod(int val);
    ///< returns transformed S2 modulation values
    int StatToS2Fec(int mod);

    int SourceCode() const;
    ///< returns vdr internal code of signal source
    std::string TplFileName(int source);
    ///< returns complete path and filename to transponder list
    std::string Position() const;
    ///< returns orbital position. of sources eg. S19.2E
    std::string Description() const;
    ///< returns Descr. of sources eg. ASTRA ...
    int LockMs() const;
    cTransponder *GetNITStartTransponder();
    void ResetNITStartTransponder(cSatTransponder * v);
    bool MissingTransponder(int Transponder);
  private:
    cTransponders();
    ~cTransponders();
    cTransponders(const cTransponders &);
    cTransponders & operator=(const cTransponders &);
    std::auto_ptr < cSatTransponder > nitStartTransponder_;
    //bool SetNITStartTransponder();
    static cTransponders *instance_;
    int sourceCode_;

    std::string SetPosition(const std::string & tplFileName);
    std::string SetDescription();

    std::string position_;
    std::string description_;
    std::string fileName_;
    int lockMs_;
};

#endif //_TRANSPONDERS__H