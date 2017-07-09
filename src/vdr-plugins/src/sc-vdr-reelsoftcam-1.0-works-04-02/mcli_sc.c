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

#include "mcli_sc.h"
#include "cam.h"
#include "crypto.h"
#include "data.h"
#include "filter.h"
#include "helper.h"
#ifdef RBMINI
#define DMX_DEVICE_NAME "/dev/rbm"
#define MAX_DMX_WRITE (1000*TS_SIZE)
#endif

#ifdef RBMINI
#define TS_BUFF_SIZE MEGABYTE(16)
#else
#define TS_BUFF_SIZE MEGABYTE(4)
#endif

//#define DBSCG(x...) printf(x);isyslog(x)
#define DBSCG(x...)
#define INFO(x...) printf(x);isyslog(x)
#define ERROR(x...) printf(x);esyslog(x)

int cScMcliDevice::ca_count =0;
#ifdef RBMINI
int cScMcliDevice::max_ca =1;
#else
int cScMcliDevice::max_ca =6;
#endif

#if APIVERSNUM >= 10500
// class cScCiMcliAdapter : public cScCiAdapter {
class cScCiMcliAdapter : public cScCiAdapter {
public:
	cScCiMcliAdapter(cDevice *Device, int CardIndex, cCam *Cam) : cScCiAdapter(Device, CardIndex, Cam) {};
	eModuleStatus ModuleStatus(int Slot) {
		cScMcliDevice *test = dynamic_cast<cScMcliDevice *>(device);
		if(test && !test->HasInput()) return msNone;
		return (cam && slots[Slot]) ? slots[Slot]->Status():msNone; 
	}; // Don't use config - always enable
}; // cScCiMcliAdapter
#endif

cScMcliDevice::cScMcliDevice() {
	DBSCG(">>>>>new cScMcliDevice CardIndex %d count %d\n", CardIndex(), ca_count);
#ifdef RBMINI
	dmx_fd = -1;
#else
	decsa = NULL;
#endif
	thread_run=thread_running=false;
	buff=NULL;
	cam=new cCam(this,CardIndex());
#ifdef USE_OE
	memset(&oe_pos, 0, sizeof(oe_pos));
	memset(&oe_first, 0, sizeof(oe_first));
#endif
#if APIVERSNUM < 10500
	memset(lrucaid,0,sizeof(lrucaid));
#else
	ciadapter=new cScCiMcliAdapter(this,CardIndex(),cam);
#endif
} // cScMcliDevice::cScMcliDevice

cScMcliDevice::~cScMcliDevice() {
	DBSCG(">>>>>delete cScMcliDevice CardIndex %d\n", CardIndex());
	EarlyShutdown();
	if(HasSC()) 
		StopSC();
} // cScMcliDevice::~cScMcliDevice

#if APIVERSNUM < 10500
bool cScMcliDevice::GetPrgCaids(int source, int transponder, int prg, caid_t *c) {
	DBSCG(">>>>>cScMcliDevice::GetPrgCaids CardIndex %d\n", CardIndex());
	cMutexLock lock(&lruMutex);
	int i=FindLRUPrg(source,transponder,prg);
	if(i>=0) {
		for(int j=0; j<MAXCAIDS && lrucaid[i].caids[j]; j++)
			*c++=lrucaid[i].caids[j];
		*c=0;
		return true;
	} // if
	return false;
} // cScMcliDevice::GetPrgCaids

int cScMcliDevice::FindLRUPrg(int source, int transponder, int prg) {
	for(int i=0; i<MAX_LRU_CAID; i++)
		if(lrucaid[i].src==source && lrucaid[i].tr==transponder && lrucaid[i].prg==prg) 
			return i;
	return -1;
} // cScMcliDevice::FindLRUPrg
#endif

bool cScMcliDevice::SetCaPid(ca_pid_t *ca_pid) {
	DBSCG(">>>>>cScMcliDevice::SetCaPid %p %04x %d CardIndex %d\n", ca_pid, ca_pid ? ca_pid->pid : 0, ca_pid ? ca_pid->index : 0, CardIndex());
	if(ca_pid->pid < MAX_OE_PIDS) {
#ifdef USE_OE
		if(ca_pid->index) {
			if((ca_pid->index > 0) && (ca_pid->index < MAX_OE_CA))
				oemap[ca_pid->index].insert(std::pair<int,int>(ca_pid->pid, 0));
			DBSCG(">>>>>cScMcliDevice::SetCaPid: count %d (%d)\n", oemap[ca_pid->index].size(), ca_pid->index);
		} else {
			if((pidmap[ca_pid->pid] > 0) && (pidmap[ca_pid->pid] < MAX_OE_CA))
				oemap[pidmap[ca_pid->pid]].erase(ca_pid->pid);
			DBSCG(">>>>>cScMcliDevice::SetCaPid: count %d (%d)\n", oemap[pidmap[ca_pid->pid]].size(), pidmap[ca_pid->pid]);
		} // if
#endif
		pidmap[ca_pid->pid]=ca_pid->index;
	} // if
#ifdef RBMINI
	if(chan_change) {
		ca_pid_t ca_pid = {-1,-1};
		ioctl(dmx_fd, CA_SET_PID, &ca_pid);
		chan_change=false;
	} // if
	return ioctl(dmx_fd, CA_SET_PID, ca_pid)==0;
#else
	if(decsa) return decsa->SetCaPid(ca_pid);
	return false;
#endif
} // cScMcliDevice::SetCaPid

bool cScMcliDevice::SetCaDescr(ca_descr_t *ca_descr, bool initial) {
	DBSCG(">>>>>cScMcliDevice::SetCaDescr %p %d CardIndex %d for %s\n", ca_descr, initial, CardIndex(), CurChan() ? CurChan()->Name() : "<NULL>");
	bool ret=false;
#ifdef RBMINI
	ret = ioctl(dmx_fd, CA_SET_DESCR, ca_descr)==0;
#else
	if(decsa)ret = decsa->SetDescr(ca_descr,initial);
#endif
	gotcw=true;
	return ret;
} // cScMcliDevice::SetCaDescr

#if APIVERSNUM >= 10500
bool cScMcliDevice::Ready(void) {
	if(!cMcliDevice::Ready()) return false;
	if(!HasInput()) return true; // Don't wait for ci if device not used
	return ciadapter ? ciadapter->Ready() : true;
}
#else
void cScMcliDevice::CiStartDecrypting(void) {
	DBSCG(">>>>>cScMcliDevice::CiStartDecrypting CardIndex %d for %s\n", CardIndex(), CurChan() ? CurChan()->Name() : "<NULL>");
	if(cam && GetCaOverride()) {
		cSimpleList<cPrg> prgList;
		for(cCiCaProgramData *p=ciProgramList.First(); p; p=ciProgramList.Next(p)) {
			if(p->modified) {
				cPrg *prg=new cPrg(p->programNumber,cam->HasPrg(p->programNumber));
				if(prg) {
					bool haspid=false;
					caid_t casys[MAXCAIDS+1];
					for(cCiCaPidData *q=p->pidList.First(); q; q=p->pidList.Next(q)) {
						if(q->active) {
							prg->pids.Add(new cPrgPid(q->streamType,q->pid));
							haspid=true;
						} // if
					} // for
					if(haspid) {
						if(GetPrgCaids(ciSource,ciTransponder,p->programNumber,casys)) {
							unsigned char buff[2048];
							bool streamflag;
							int len=GetCaDescriptors(ciSource,ciTransponder,p->programNumber,casys,sizeof(buff),buff,streamflag);
							if(len>0) prg->caDescr.Set(buff,len);
						} // if
					} // if
					prgList.Add(prg);
				} // if
				p->modified=false;
			} // if
		} // for
		for(int loop=1; loop<=2; loop++) // first delete, then add
			for(cPrg *prg=prgList.First(); prg; prg=prgList.Next(prg))
				if((loop==1)!=(prg->pids.Count()>0))
					cam->AddPrg(prg);
	} // if
	cMcliDevice::CiStartDecrypting();
} // cScMcliDevice::CiStartDecrypting

bool cScMcliDevice::CiAllowConcurrent(void) const {
//	DBSCG(">>>>>cScMcliDevice::CiAllowConcurrent CardIndex %d\n", CardIndex());
	return true;
} // cScMcliDevice::CiAllowConcurrent
#endif

void cScMcliDevice::CaidsChanged(void) {
#if APIVERSNUM >= 10500
	if(ciadapter) ciadapter->CaidsChanged();
	PRINTSCF(L_CORE_CAIDS,"caid list rebuild triggered");
#endif
} // cScMcliDevice::CaidsChanged

bool cScMcliDevice::SetPid(cPidHandle *Handle, int Type, bool On) {
	DBSCG(">>>>>cScMcliDevice::SetPid %p (%04x %d) %d %d CardIndex %d for %s\n", Handle, Handle ? Handle->pid : 0, Handle ? Handle->used : 0,  Type, On, CardIndex(), CurChan() ? CurChan()->Name() : "<NULL>");
	if(!HasInput()) return false;
	if(cam) cam->SetPid(Type,Handle->pid,On);
#ifdef USE_OE
	if(!On && !Handle->used) { // If pid is no longer used, release ca
    	   ca_pid_t ca_pid;
    	   memset(&ca_pid, 0, sizeof(ca_pid));
    	   ca_pid.pid = Handle->pid;
    	   SetCaPid(&ca_pid);
	} // if
#endif

	return cMcliDevice::SetPid(Handle, Type, On);
} // cScMcliDevice::SetPid

bool cScMcliDevice::StartSC() {
	if(HasSC()) return true;
	if(!HasFreeSC()) return false;
	
	ca_count++;
	thread_run=thread_running=false;

	INFO("Initializing mcli-sc device %d/%d CardIndex %d\n", ca_count, max_ca, CardIndex());
#ifdef RBMINI
	char dev_name[PATH_MAX];
	sprintf(dev_name, "%s%d", DMX_DEVICE_NAME, ca_count);
	dmx_fd = (ca_count == 1) ? open(dev_name, O_RDWR|O_NDELAY) : -1;
	if(-1==dmx_fd) {
		ERROR("Failed to open %s\n", dev_name);
		goto cleanup;
	} // if
	buff=new cRingBufferLinear(TS_BUFF_SIZE,TS_SIZE,true,"FFdecsa-TS");
	if(!buff) goto cleanup;
	read_pos=0;
#else
	decsa=new cDeCSA(CardIndex());
	if(!decsa) goto cleanup;
	buff=new cRingBufferLinear(TS_BUFF_SIZE,TS_SIZE,true,"FFdecsa-TS");
	if(!buff) goto cleanup;
	decsa->SetActive(true);
#endif
	gotcw=false;
#ifdef RBMINI
	chan_change=false;
#endif
	thread_run=true;
	pthread_t childTid;
	if(0==pthread_create(&childTid, NULL, (void *(*) (void *))&StartReader, (void *)this))
		pthread_detach(childTid);
isyslog("cScMcliDevice::StartSC %d\n", GetCaEnable());
	if(GetCaEnable()) {
		SetEnable(false);   // We have to reenable the device or CAM resources won't be freed (SetCaEnable doesn't do it for us)
		SetCaEnable(true);  // Fake CaEnable, or SetEnable will set it on...
		SetEnable(true);    // Now we are save to set it on again
		SetCaEnable(false); // And now we can set the correct Ca usage
	} // if
isyslog("cScMcliDevice::StartSC -> %d\n", GetCaEnable());
	return true;
cleanup:
	StopSC();
	return false;
} // cScMcliDevice::StartSC

void cScMcliDevice::StopSC() {
	INFO("Release mcli-sc device %d/%d CardIndex %d\n", ca_count, max_ca, CardIndex());
	thread_run=false;
	while(thread_running)
		cCondWait::SleepMs(10);
#ifdef RBMINI
	if(dmx_fd!=-1) close(dmx_fd); dmx_fd=-1;
#else
	if(decsa) delete decsa; decsa = NULL;
#endif
	if(buff) delete buff; buff = NULL;
	ca_count--;
} // cScMcliDevice::StopSC

bool cScMcliDevice::HasSC() const {
#ifdef RBMINI
	if(dmx_fd!=-1) return true;
#else
	if(decsa) return true;
#endif
	return false;
} // cScMcliDevice::HasSC

bool cScMcliDevice::HasFreeSC()const {
	if((-1 != max_ca) && (ca_count >= max_ca)) return false;
#ifdef RBMINI
	if(ca_count) return false;
#endif
	return true;
} // cScMcliDevice::HasFreeSC

bool cScMcliDevice::UseSC(const cChannel *Channel) const {
	if(!Channel) return false;
#if APIVERSNUM < 10500
	DBSCG("cScMcliDevice::UseSC tuned %d ca %d enable %d ProvidesCa %d override %d\n", IsTunedToTransponder(Channel), Channel->Ca(), GetCaEnable(), ProvidesCa(Channel), GetCaOverride());
#else
//	DBSCG("cScMcliDevice::UseSC tuned %d ca %d enable %d ProvidesCa %d override %d\n", IsTunedToTransponder(Channel), Channel->Ca(), GetCaEnable(), ciadapter ? ciadapter->ProvidesCa(Channel->Caids()):-1, GetCaOverride());
#endif
	if(Channel->Ca() && (Channel->Ca()<CA_ENCRYPTED_MIN)) return false;
	if(Channel->Ca() && (Channel->Ca()>=CA_ENCRYPTED_MIN)) return true;
	DBSCG("cScMcliDevice::UseSC -> Default %d\n", GetCaOverride());
	return GetCaOverride();
} // cScMcliDevice::UseSC

bool cScMcliDevice::SetChannelDevice(const cChannel *Channel, bool LiveView) {
	DBSCG(">>>>>cScMcliDevice::SetChannelDevice %s Live %d CardIndex %d\n", Channel ? Channel->Name() : "???", LiveView, CardIndex());
	if(!max_ca) return cMcliDevice::SetChannelDevice(Channel,LiveView);
	if(!HasInput()) return false;
	hasVideo = Channel ? (Channel->Vpid() != 0) : false;
#if APIVERSNUM < 10500
	lruMutex.Lock();
	int i=FindLRUPrg(Channel->Source(),Channel->Transponder(),Channel->Sid());
	if(i<0) i=MAX_LRU_CAID-1;
	if(i>0) memmove(&lrucaid[1],&lrucaid[0],sizeof(struct LruCaid)*i);
	for(i=0; i<=MAXCAIDS; i++) if((lrucaid[0].caids[i]=Channel->Ca(i))==0) break;
	lrucaid[0].src=Channel->Source();
	lrucaid[0].tr=Channel->Transponder();
	lrucaid[0].prg=Channel->Sid();
	lruMutex.Unlock();
#endif
	hasVideo = Channel->Vpid()!=0;
	if(!IsTunedToTransponder(Channel)) {
#ifdef RBMINI
		chan_change=true;
#endif
		gotcw=false;
		if(buff)buff->Clear();
		memset(pidmap, 0, sizeof(pidmap));
#ifdef USE_OE
		memset(&oe_pos, 0, sizeof(oe_pos));
		for(int i=0; i<MAX_OE_CA;i++)
			oemap[i].clear();
#endif
	} // if
	SetCaOverride(UseSC(Channel));
	if(GetCaOverride())
		StartSC();
	else if (HasSC())
		StopSC();
	if(Channel && Channel->Ca()>=CA_ENCRYPTED_MIN) {
	INFO("Using %s for decryption of %s (%04x) %s%s", GetCaOverride() ? "SC" : "NC", 
			Channel ? Channel->Name() : "<NULL>", Channel ? Channel->Ca(0) : -1, hasVideo ? "(has video)":"(no video)", LiveView?" LIVE":"");
	}
	if(cam) cam->Tune(Channel);
	bool ret=cMcliDevice::SetChannelDevice(Channel,LiveView);
        if(LiveView && IsPrimaryDevice() && Channel->Ca()>=CA_ENCRYPTED_MIN &&
        !Transferring() &&
        softcsa && !fullts) {
        //PRINTSCF(L_GEN_INFO,"Forcing transfermode on card %s",devId);
        cScMcliDevice::SetChannelDevice(Channel,false); // force transfermode
        } 
	if(ret && cam) cam->PostTune();
	DBSCG(">>>>>cScMcliDevice::SetChannelDevice %s -> RETURN %d\n", Channel ? Channel->Name() : "???", ret);
	return ret;
} // cScMcliDevice::SetChannelDevice

bool cScMcliDevice::ProvidesSCChannel (const cChannel * Channel, int Priority, bool * NeedsDetachReceivers) const {
	bool result = false;
	bool hasPriority = Priority < 0 || Priority > this->Priority ();
	bool needsDetachReceivers = false;
	if (!HasInput()) return false;
	if(ProvidesTransponder(Channel)) {
		result = hasPriority;
		if (Priority >= 0 && Receiving (true)) {
			if (!IsTunedToTransponder(Channel)) {
				needsDetachReceivers = true;
			} else {
				if(GetCaEnable()) needsDetachReceivers = true; // Dont't allow SC while using CAM
				result = true;
			}
		} // if
	} // if
	if (NeedsDetachReceivers)
		*NeedsDetachReceivers = needsDetachReceivers;
	return result;
} // cScMcliDevice::ProvidesSCChannel

bool cScMcliDevice::ProvidesChannel (const cChannel * Channel, int Priority, bool * NeedsDetachReceivers) const {
	DBSCG(">>>>>cScMcliDevice::ProvidesChannel %s Prio %d CaId %d CardIndex %d max %d (SC %d)\n", Channel->Name(), Priority, Channel->Ca(), CardIndex(), max_ca, HasSC());
	if(!max_ca) return cMcliDevice::ProvidesChannel(Channel, Priority, NeedsDetachReceivers);
	bool ret = false;
	if(UseSC(Channel)) {
		ret = ProvidesSCChannel(Channel, Priority, NeedsDetachReceivers);
		DBSCG(">>>>>cScMcliDevice::ProvidesChannel USE SC %s CaId %d CardIndex %d -> %d detach %d\n", Channel->Name(), Channel->Ca(), CardIndex(), (int)ret, NeedsDetachReceivers ? (int)*NeedsDetachReceivers : -1);
		if(!HasFreeSC() && !HasSC())
			ret = 0; // No free SC resources
	} else {
		ret = cMcliDevice::ProvidesChannel(Channel, Priority, NeedsDetachReceivers);
		if(NeedsDetachReceivers && Channel->Ca() && (Channel->Ca()<CA_ENCRYPTED_MIN) && HasSC())
			*NeedsDetachReceivers = true; // Don't allow CAM while using SC
		DBSCG(">>>>>cScMcliDevice::ProvidesChannel USE NC %s CaId %d CardIndex %d -> %d detach %d\n", Channel->Name(), Channel->Ca(), CardIndex(), (int)ret, NeedsDetachReceivers ? (int)*NeedsDetachReceivers : -1);
	} // if
	DBSCG(">>>>>cScMcliDevice::ProvidesChannel %s CaId %d CardIndex %d -> RETURN %d cam %p ca %d\n", Channel->Name(), Channel->Ca(), CardIndex(), ret, cam, Channel->Ca());
isyslog("cScMcliDevice::ProvidesChannel %s Use %s %s CardIndex %d -> RETURN %d %d\n", Channel->Name(), UseSC(Channel)?"SC":"NC", GetCaEnable()?"CA enable":"CA disable", CardIndex(), ret, NeedsDetachReceivers?*NeedsDetachReceivers:-1);
	return ret;
} // cScMcliDevice::ProvidesChannel

#if APIVERSNUM < 10500
int cScMcliDevice::ProvidesCa(const cChannel *Channel) const {
	DBSCG(">>>>>cScMcliDevice::ProvidesCa %s CaId %d CardIndex %d\n", Channel->Name(), Channel->Ca(), CardIndex());
	if(HasFreeSC() || HasSC()) {
		if(cam && Channel->Ca()>=CA_ENCRYPTED_MIN) {
			int caid;
			for(int j=0; (caid=Channel->Ca(j)); j++)
				if(!overrides.Ignore(Channel->Source(),Channel->Transponder(),caid)) {
					int n=cSystems::CanHandle(caid,!softcsa);
					if(n<0) break;
					if(n>0) return 2;
				} // if 
		} // if
	} // if
	return cMcliDevice::ProvidesCa(Channel);
} // cScMcliDevice::ProvidesCa
#endif

#ifdef USE_OE
void cScMcliDevice::PutOEBuff(int ca) {
	int odd = oe_first[ca];
	if(oe_pos[ca][odd]>0) {
		if(buff->Free() < oe_pos[ca][odd]) {
			ERROR("ERROR: skipped %d bytes - ts-buffer full on device %d\n"  , oe_pos[ca][odd], CardIndex()+1);
			buff->Clear();
		} // if
		if(oe_pos[ca][odd] != buff->Put(&oe_buff[ca][odd][0], oe_pos[ca][odd])) {
			ERROR("ERROR: skipped %d bytes - ts-buffer put failure on device %d\n"  , oe_pos[ca][odd], CardIndex());
			buff->Clear();
		} // if
	} // if
	if(oe_pos[ca][!odd]>0) {
		if(buff->Free() < oe_pos[ca][!odd]) {
			ERROR("ERROR: skipped %d bytes - ts-buffer full on device %d\n"  , oe_pos[ca][!odd], CardIndex()+1);
			buff->Clear();
		} // if
		if(oe_pos[ca][!odd] != buff->Put(&oe_buff[ca][!odd][0], oe_pos[ca][!odd])) {
			ERROR("ERROR: skipped %d bytes - ts-buffer put failure on device %d\n"  , oe_pos[ca][!odd], CardIndex());
			buff->Clear();
		} // if
	} // if
	oe_pos[ca][0]=oe_pos[ca][1]=0;
} // cScMcliDevice::PutOEBuff
#endif

int cScMcliDevice::HandleTsData(unsigned char *buffer, size_t len) {
//	DBSCG(">>>>>cScMcliDevice::HandleTsData %p %d CardIndex %d\n", buffer, len, CardIndex());
	if(!GetCaOverride()) return cMcliDevice::HandleTsData(buffer, len);
	if(len < TS_SIZE) return len;
	int pid = ((buffer[1]&0x1F)<<8)+buffer[2];

	if(!HasInput()) return len;

#ifdef USE_OE
#ifdef RBMINI
	if((pid < MAX_OE_PIDS) && pidmap[pid] && (-1 != dmx_fd) && buff) {
#else	
	if((pid < MAX_OE_PIDS) && pidmap[pid] && decsa && buff) {
#endif
		cMutexLock lock(&dataMutex);
		int ca=pidmap[pid];
		if((ca > 0) && (ca < MAX_OE_CA) && (oemap[ca].size()>1) && (ScSetup.OddEven==1)) {
			std::map<int,int>::iterator it = oemap[ca].find(pid);
			for(size_t x=0;x < len; x+=TS_SIZE) {
				int odd = (buffer[x+3]&0x40) ? 1 : 0;
				if(!(buffer[x+3]&0x10) || !(buffer[x+3]&0x80)) { // No payload -> ignore scrambling
					buffer[x+3] &= ~0xC0;
					if(oemap[ca].end() != it) odd = (*it).second;
				} // if
				if(oemap[ca].end() != it) (*it).second = odd;
				if (oe_pos[ca][odd]>=MAX_OE_STORE) {
					isyslog("OE Buffer flushed [%d] %d", CardIndex()+1, ca);
					PutOEBuff(ca);
				} // if
				memcpy(&oe_buff[ca][odd][oe_pos[ca][odd]], &buffer[x], TS_SIZE);
				oe_pos[ca][odd]+=TS_SIZE;
			} // for
			unsigned int oec=0;
			for (std::map<int,int>::iterator it = oemap[ca].begin(); it != oemap[ca].end(); it++ )
			    oec+=(*it).second;
			if (!oec||(oemap[ca].size()==oec)) {
				oe_first[ca] = oec ? 0 : 1;
				PutOEBuff(ca);
				oe_first[ca] = oec ? 1 : 0;
			}
		} else {
			if((oe_pos[ca][0] || oe_pos[ca][1]) && (ca > 0) && (ca < MAX_OE_CA))
				PutOEBuff(ca);
			if(buff->Free() < (int)len) {
				ERROR("ERROR: skipped %d bytes - ts-buffer full on device %d\n"  , len, CardIndex());
				buff->Clear();
			} // if
			if(((int)len) != buff->Put(buffer, len)) {
				ERROR("ERROR: skipped %d bytes - ts-buffer put failure on device %d\n"  , len, CardIndex());
				buff->Clear();
			} // if
		} // if
	} else
		if(((int)len) != cMcliDevice::HandleTsData(buffer, len)) printf("Not all unencrypted ts data written\n");
	return len;
#else
#ifdef RBMINI	
	if((pid < MAX_OE_PIDS) && pidmap[pid] && (-1 != dmx_fd) && buff) {
#else	
	if((pid < MAX_OE_PIDS) && pidmap[pid] && decsa && buff) {
#endif		
		cMutexLock lock(&dataMutex);
		if(buff->Free() < (int)len) {
			ERROR("ERROR: skipped %d bytes - ts-buffer full on device %d\n"  , len, CardIndex());
			buff->Clear();
		} // if
		if(((int)len) != buff->Put(buffer, len)) {
			ERROR("ERROR: skipped %d bytes - ts-buffer put failure on device %d\n"  , len, CardIndex());
			buff->Clear();
		} // if
	} else
		if(((int)len) != cMcliDevice::HandleTsData(buffer, len)) printf("Not all unencrypted ts data written\n");
	return len;
#endif /*USE_OE*/
} // cScMcliDevice::HandleTsData

void cScMcliDevice::EarlyShutdown(void)
{
#if APIVERSNUM >= 10500
  SetCamSlot(0);
  delete ciadapter; ciadapter=0;
#endif
  if(cam) cam->Stop();
  delete cam; cam=0;
}

void cScMcliDevice::Shutdown(void) {
	DBSCG(">>>>>cScMcliDevice::Shutdown\n");
	for(int i=0;i<MAXDEVICES;i++) {
		cScMcliDevice *test = dynamic_cast<cScMcliDevice *>(cDevice::GetDevice(i));
		if(test) test->EarlyShutdown();
	} // for
} // cScMcliDevice::Shutdown

void *cScMcliDevice::StartReader(cScMcliDevice *dev) {
	DBSCG(">>>>>cScMcliDevice::StartReader\n");
	dev->thread_running=true;
	dev->ProcessRead();
	dev->thread_running=false;
	DBSCG(">>>>>cScMcliDevice::StartReader DONE\n");
	return NULL;
} // cScMcliDevice::StartReader

void cScMcliDevice::ProcessRead() {
#ifdef RBMINI
	int count=0;
	while(thread_run && buff && (-1 != dmx_fd)) {
		if(gotcw) {
			int c=0;
			unsigned char *p=buff->Get(c);
			c-=c%TS_SIZE;
			if(p && (c>=TS_SIZE) && ((c>MAX_DMX_WRITE) || wait.TimedOut())) {
				if(c>MAX_DMX_WRITE) c = MAX_DMX_WRITE;
				int written = write(dmx_fd, p, c);
				if(written != c) printf("Not all crypted data written %d %d (%d/%d)\n", written, c, buff->Available(), buff->Free());
				if(written>0) {
					buff->Del(written);
					wait.Set(500);
				} // if
			} // if
		} // if
		if((count=read(dmx_fd, &read_buff[read_pos], sizeof(read_buff)-read_pos)) > 0) {
			read_pos += count;
			int to_write = read_pos-read_pos%TS_SIZE;
			if(to_write>0) {
				if(to_write != cMcliDevice::HandleTsData(read_buff, to_write)) printf("Not all decrypted ts data written\n");
				if(to_write < read_pos) { // Handle unaligned data
					read_pos -= to_write;
					memcpy(read_buff, &read_buff[to_write], read_pos);
				} else
					read_pos = 0;
				cCondWait::SleepMs(10);
			} else {
				cCondWait::SleepMs(100);
			} // if
		} else {
			cCondWait::SleepMs(100);
		} // if
	} // while
#else
	while(thread_run && buff && decsa) {
		int c=0;
		unsigned char *p=buff->Get(c);
		c-=c%TS_SIZE;
		if(p && (c>=TS_SIZE))  {
			if((p[3]&0xC0)) {
				if(!decsa->Decrypt(p,c,false)) {
					cCondWait::SleepMs(10);
					continue;
				} // if
			} // if
			int w=0;
			while((w<c) && (!(p[w+3]&0xC0) || !(p[w+3]&0x10)))
				w+=TS_SIZE;
			if(w>0) {
				if(w != cMcliDevice::HandleTsData(p, w)) printf("Not all decoded ts data written\n");
				buff->Del(w);
			} else {
				cCondWait::SleepMs(10);
			} // if
		} else {
			cCondWait::SleepMs(10);
		} // if
	} // while
#endif
} // cScMcliDevice::ProcessRead

#ifdef RBMINI
typedef struct _keys_t {
	unsigned char odd[8];
	unsigned char even[8];
} keys_t;

// Avoid unresolved externals due to missing FFDeCsa
int get_internal_parallelism(void) { return 0;}
int get_suggested_cluster_size(void) { return 0;}
void *get_key_struct(void) { return 0;}
void free_key_struct(void *keys) {}
void set_control_words(void *keys, const unsigned char *even, const unsigned char *odd) {}
void set_even_control_word(void *keys, const unsigned char *even) {}
void set_odd_control_word(void *keys, const unsigned char *odd) {}
int decrypt_packets(void *keys, unsigned char **cluster) { return 0;}
#endif
