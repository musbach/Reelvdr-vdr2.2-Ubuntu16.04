/*
 * Softcam plugin to VDR (C++)
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 * Or, point your browser to http://www.gnu.org/copyleft/gpl.html
 */

#ifndef MCLISC_H
#define MCLISC_H

#include "../mcli/filter.h"
#include "../mcli/device.h"
#include "../mcli/mcli.h"

#if APIVERSNUM >= 10500
typedef int caid_t;
#else
typedef unsigned short caid_t;
#endif

#define MAX_OE_PIDS 0x2000
// From mcli/mcast/client/recv_tv.c recv_ts: max size per pid = 174*188 bytes
#define MAX_OE_SIZE_PER_PID (174*TS_SIZE)
#define MAX_OE_STORE (MAX_OE_SIZE_PER_PID*4)
#define MAX_OE_CA 4

#define USE_OE
//#define DBSCG_OE
#include <map>

class cCam;
class cDeCSA;
class cScCiAdapter;

class cScDevice {
public:
	virtual ~cScDevice(){};
	virtual bool SoftCSA(bool live) = 0;
	virtual bool SetCaPid(ca_pid_t *ca_pid) = 0;
	virtual bool SetCaDescr(ca_descr_t *ca_descr, bool initial) = 0;
	virtual void DumpAV7110(void) = 0;
#if APIVERSNUM >= 10500
#if APIVERSNUM < 20104
	virtual bool Ready(void) = 0;
#endif
#else
	virtual bool GetPrgCaids(int source, int transponder, int prg, caid_t *c) = 0;
	virtual void CiStartDecrypting(void) = 0;
	virtual bool CiAllowConcurrent(void) const = 0;
#endif
	virtual cCam *Cam(void) = 0;
	virtual void CaidsChanged(void) = 0;
}; // cScDevice

class cScMcliDevice: public cMcliDevice, public cScDevice {
public:
	cScMcliDevice();
	virtual ~cScMcliDevice();
	virtual bool SoftCSA(bool live) { return true; }
#if APIVERSNUM < 10500
#define MAX_LRU_CAID 10
	struct LruCaid {
		int src, tr, prg;
		caid_t caids[MAXCAIDS+1];
	} lrucaid[MAX_LRU_CAID];
	cMutex lruMutex;
	virtual bool GetPrgCaids(int source, int transponder, int prg, caid_t *c);
	int FindLRUPrg(int source, int transponder, int prg);
#endif
	virtual bool SetCaPid(ca_pid_t *ca_pid);
	virtual bool SetCaDescr(ca_descr_t *ca_descr, bool initial);
	virtual void DumpAV7110(void) {}
#if APIVERSNUM >= 10500
#if APIVERSNUM < 20104
	virtual bool Ready(void);
#endif
#else
	virtual void CiStartDecrypting(void);
	virtual bool CiAllowConcurrent(void) const;
#endif
	virtual cCam *Cam(void) { return cam; }
	virtual void CaidsChanged(void);
public:
	virtual bool SetPid(cPidHandle *Handle, int Type, bool On);
	virtual bool StartSC();
	virtual void StopSC();
	virtual bool HasSC() const;
	virtual bool HasFreeSC() const;
	virtual bool UseSC(const cChannel *Channel) const;
	virtual bool SetChannelDevice(const cChannel *Channel, bool LiveView);
	virtual bool ProvidesSCChannel (const cChannel * Channel, int Priority, bool * NeedsDetachReceivers) const;
	virtual bool ProvidesChannel (const cChannel * Channel, int Priority = -1, bool * NeedsDetachReceivers = NULL) const;
#if APIVERSNUM < 10500
	virtual int ProvidesCa(const cChannel *Channel) const;
#else
	virtual bool HasCi(void) { return ciadapter != NULL; };
#endif
	virtual int HandleTsData(unsigned char *buffer, size_t len);
	virtual int PutTsData(unsigned char *buffer, size_t len) { return cMcliDevice::HandleTsData(buffer, len);};
	virtual void EarlyShutdown(void);
	static void Shutdown(void);
	static int GetCaCount() { return ca_count;};
private:
	static void *StartReader(cScMcliDevice *dev);
	void ProcessRead();
private:
	cCam *cam;
#ifdef RBMINI
	int dmx_fd;
	unsigned char read_buff[1000*TS_SIZE];
	int read_pos;
	bool chan_change;
#else
	cDeCSA *decsa;
#endif
#if APIVERSNUM >= 10500
	cScCiAdapter *ciadapter;
#endif
	cRingBufferLinear *buff;
	cMutex dataMutex;
	cTimeMs wait;
	bool gotcw;
	bool thread_run;
	bool thread_running;
	static int ca_count;
	static int max_ca;
	bool softcsa, fullts;
	bool hasVideo;
#ifdef USE_OE
	std::map<int,int> oemap[MAX_OE_CA];
	int oe_first[MAX_OE_CA];
	unsigned char oe_buff[MAX_OE_CA][2][MAX_OE_STORE];
	int oe_pos[MAX_OE_CA][2];
	void PutOEBuff(int ca);
#endif
	unsigned char pidmap[MAX_OE_PIDS];
#ifdef DBSCG_OE
	unsigned char cont[0x1FFF];
#endif
}; // cScMcliDevice

#endif // MCLISC_H
