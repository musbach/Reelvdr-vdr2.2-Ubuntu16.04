/*
 *  $Id: device.c,v 1.27 2010/08/18 10:26:55 schmirl Exp $
 */
 
#include "client/device.h"
#include "client/setup.h"
#include "client/filter.h"

#include "tools/select.h"

#include <vdr/config.h>
#include <vdr/channels.h>
#include <vdr/ringbuffer.h>
#include <vdr/eit.h>
#include <vdr/timers.h>

#include <time.h>
#include <iostream>

using namespace std;

#ifndef LIVEPRIORITY
#define LIVEPRIORITY 0
#endif

#ifndef TRANSFERPRIORITY
#define TRANSFERPRIORITY -1
#endif

#define VIDEOBUFSIZE MEGABYTE(3)

cStreamdevDevice *cStreamdevDevice::m_Device = NULL;
const cChannel *cStreamdevDevice::m_DenyChannel = NULL;

cStreamdevDevice::cStreamdevDevice(void) {
	m_Channel    = NULL;
	m_TSBuffer   = NULL;

	m_Filters    = new cStreamdevFilters;
	StartSectionHandler();
	isyslog("streamdev-client: got device number %d", CardIndex() + 1);

	m_Device = this;
	m_Pids = 0;
	m_Priority = -100;
}

cStreamdevDevice::~cStreamdevDevice() {
	Dprintf("Device gets destructed\n");

	Lock();
	m_Device = NULL;
	m_Filters->SetConnection(-1);
	ClientSocket.Quit();
	ClientSocket.Reset();
	Unlock();

	Cancel(3);

	StopSectionHandler();
	DELETENULL(m_Filters);
	DELETENULL(m_TSBuffer);
}

#if APIVERSNUM >= 10700
int cStreamdevDevice::NumProvidedSystems(void) const
{	return StreamdevClientSetup.NumProvidedSystems; }
#endif

bool cStreamdevDevice::ProvidesSource(int Source) const {
	Dprintf("ProvidesSource, Source=%d\n", Source);
	return true;
}

bool cStreamdevDevice::ProvidesTransponder(const cChannel *Channel) const
{
	Dprintf("ProvidesTransponder\n");
	return true;
}

#if APIVERSNUM >= 10722
bool cStreamdevDevice::IsTunedToTransponder(const cChannel *Channel) const
#else
bool cStreamdevDevice::IsTunedToTransponder(const cChannel *Channel)
#endif
{
	return ClientSocket.DataSocket(siLive) != NULL &&
			m_Channel != NULL &&
			Channel->Transponder() == m_Channel->Transponder();
}

bool cStreamdevDevice::ProvidesChannel(const cChannel *Channel, int Priority, 
		bool *NeedsDetachReceivers) const {
#if APIVERSNUM >= 10725
	bool prio = Priority == IDLEPRIORITY || Priority >= this->Priority();
#else
	bool prio = Priority < 0 || Priority > this->Priority();
#endif
	bool res = prio;
	bool ndr = false;

	if (!StreamdevClientSetup.StartClient || Channel == m_DenyChannel)
		return false;

	Dprintf("ProvidesChannel, Channel=%s, Prio=%d\n", Channel->Name(), Priority);

	if (StreamdevClientSetup.MinPriority <= StreamdevClientSetup.MaxPriority)
	{
		if (Priority < StreamdevClientSetup.MinPriority ||
				Priority > StreamdevClientSetup.MaxPriority)
			return false;
	}
	else
	{
		if (Priority < StreamdevClientSetup.MinPriority &&
				Priority > StreamdevClientSetup.MaxPriority)
			return false;
	}

	if (IsTunedToTransponder(Channel)) {
		if (Channel->Ca() < CA_ENCRYPTED_MIN ||
				(Channel->Vpid() && HasPid(Channel->Vpid())) ||
				(Channel->Apid(0) && HasPid(Channel->Apid(0))))
			res = true;
		else
			ndr = true;
	}
	else if (prio) {
		if (Priority == LIVEPRIORITY) {
			if (ClientSocket.ServerVersion() >= 100) {
				Priority = StreamdevClientSetup.LivePriority;
				UpdatePriority(true);
			}
			else {
				if (StreamdevClientSetup.LivePriority >= 0)
					Priority = StreamdevClientSetup.LivePriority;
			}
		}

		res = ClientSocket.ProvidesChannel(Channel, Priority);
		ndr = Receiving();

		if (ClientSocket.ServerVersion() >= 100)
			UpdatePriority(false);
	}

	if (NeedsDetachReceivers)
		*NeedsDetachReceivers = ndr;
	Dprintf("prov res = %d, ndr = %d\n", res, ndr);
	return res;
}

bool cStreamdevDevice::SetChannelDevice(const cChannel *Channel, 
		bool LiveView) {
	bool res;
	Dprintf("SetChannelDevice Channel: %s, LiveView: %s\n", Channel->Name(),
			LiveView ? "true" : "false");
	LOCK_THREAD;

	if (LiveView)
		return false;

	if (Receiving() && IsTunedToTransponder(Channel) && (
			Channel->Ca() < CA_ENCRYPTED_MIN ||
			(Channel->Vpid() && HasPid(Channel->Vpid())) ||
			(Channel->Apid(0) && HasPid(Channel->Apid(0))))) {
		res = true;
	}
	else {
		DetachAllReceivers();
		m_Channel = Channel;
		// Old servers delete cStreamdevLiveStreamer in ABRT.
		// Delete it now or it will happen after we tuned to new channel
		if (ClientSocket.ServerVersion() < 100)
			CloseDvr();
		res = ClientSocket.SetChannelDevice(m_Channel);
	}
	Dprintf("setchanneldevice res=%d\n", res);
	return res;
}

bool cStreamdevDevice::SetPid(cPidHandle *Handle, int Type, bool On) {
	Dprintf("SetPid, Pid=%d, Type=%d, On=%d, used=%d\n", Handle->pid, Type, On, Handle->used);
	LOCK_THREAD;

	bool res = true; 
	if (Handle->pid && (On || !Handle->used)) {
		res = ClientSocket.SetPid(Handle->pid, On);

		m_Pids += (!res) ? 0 : On ? 1 : -1;
		if (m_Pids < 0) 
			m_Pids = 0;
	}
	return res;
}

bool cStreamdevDevice::OpenDvr(void) {
	Dprintf("OpenDvr\n");
	LOCK_THREAD;

	CloseDvr();
	if (ClientSocket.CreateDataConnection(siLive)) {
		m_TSBuffer = new cTSBuffer(*ClientSocket.DataSocket(siLive), MEGABYTE(2), CardIndex() + 1);
	}
	else {
		esyslog("cStreamdevDevice::OpenDvr(): DVR connection FAILED");
	}
	return m_TSBuffer != NULL;
}


void cStreamdevDevice::CloseDvr(void) {
	Dprintf("CloseDvr\n");
	LOCK_THREAD;

	ClientSocket.CloseDvr();
	DELETENULL(m_TSBuffer);
}

bool cStreamdevDevice::GetTSPacket(uchar *&Data) {
	if (m_TSBuffer && m_Device) {
		Data = m_TSBuffer->Get();
#if 1 // TODO: this should be fixed in vdr cTSBuffer
		// simple disconnect detection
		static int m_TSFails = 0;
		if (!Data) {
			LOCK_THREAD;
			if(!ClientSocket.DataSocket(siLive)) {
				return false; // triggers CloseDvr() + OpenDvr() in cDevice
                        }
			cPoller Poller(*ClientSocket.DataSocket(siLive));
			errno = 0;
			if (Poller.Poll() && !errno) {
				char tmp[1];
				if (recv(*ClientSocket.DataSocket(siLive), tmp, 1, MSG_PEEK) == 0 && !errno) {
esyslog("cStreamDevice::GetTSPacket: GetChecked: NOTHING (%d)", m_TSFails);
					m_TSFails++; 
					if (m_TSFails > 10) {
						isyslog("cStreamdevDevice::GetTSPacket(): disconnected");
						m_Pids = 0;
						CloseDvr();
						m_TSFails = 0;
						return false;
					}
					return true;
				}
			}
			m_TSFails = 0;
		}
#endif
		return true;
	}
	return false;
}

int cStreamdevDevice::OpenFilter(u_short Pid, u_char Tid, u_char Mask) {
	Dprintf("OpenFilter\n");

	if (!StreamdevClientSetup.StreamFilters)
		return -1;


	if (!ClientSocket.DataSocket(siLiveFilter)) {
		if (ClientSocket.CreateDataConnection(siLiveFilter)) {
			m_Filters->SetConnection(*ClientSocket.DataSocket(siLiveFilter));
		} else {
			isyslog("cStreamdevDevice::OpenFilter: connect failed: %m");
			return -1;
		}
	}

	if (ClientSocket.SetFilter(Pid, Tid, Mask, true))
		return m_Filters->OpenFilter(Pid, Tid, Mask);

	return -1;
}

bool cStreamdevDevice::Init(void) {
	if (m_Device == NULL && StreamdevClientSetup.StartClient)
		new cStreamdevDevice;
	return true;
}

bool cStreamdevDevice::ReInit(void) {
	if(m_Device) {
		m_Device->Lock();
		m_Device->m_Filters->SetConnection(-1);
		m_Device->m_Pids = 0;
	}
	ClientSocket.Quit();
	ClientSocket.Reset();
	if (m_Device != NULL) {
		//DELETENULL(m_Device->m_TSBuffer);
		m_Device->Unlock();
	}
	return StreamdevClientSetup.StartClient ? Init() : true;
}

void cStreamdevDevice::UpdatePriority(bool SwitchingChannels) {
	if (m_Device) {
		m_Device->Lock();
		if (ClientSocket.SupportsPrio() && ClientSocket.DataSocket(siLive)) {
			int Priority = m_Device->Priority();
			// override TRANSFERPRIORITY (-1) with live TV priority from setup
			if (m_Device == cDevice::ActualDevice() && Priority == TRANSFERPRIORITY) {
				Priority = StreamdevClientSetup.LivePriority;
				// temporarily lower priority
				if (SwitchingChannels)
					Priority--;
				if (Priority < 0 && ClientSocket.ServerVersion() < 100)
					Priority = 0;

			}
			if (m_Device->m_Priority != Priority && ClientSocket.SetPriority(Priority))
				m_Device->m_Priority = Priority;
		}
		m_Device->Unlock();
	}
}

int cStreamdevDevice::SignalStrength(void) const {
	int strength = -1;
	if (ClientSocket.DataSocket(siLive) != NULL)
		ClientSocket.GetSignal(&strength, NULL);
	return strength;
}

int cStreamdevDevice::SignalQuality(void) const {
	int quality = -1;
	if (ClientSocket.DataSocket(siLive) != NULL)
		ClientSocket.GetSignal(NULL, &quality);
	return quality;
}
