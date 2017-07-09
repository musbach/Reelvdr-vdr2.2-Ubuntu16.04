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

// -- cMap0501 -----------------------------------------------------------------

class cMap0501 : public cMapCore {
private:
  int mId;
  unsigned int cycles;
protected:
  void DoMap(int f, unsigned char *data=0, int l=0);
  unsigned int MapCycles() { return cycles; }
  void SetCycles (unsigned int c) { cycles = c; } 
public:
  cMap0501(int Id);
  };

cMap0501::cMap0501(int Id)
{
  mId=Id|0x100;
}

void cMap0501::DoMap(int f, unsigned char *data, int l)
{
  PRINTF(L_SYS_MAP,"%04x: calling function %02X",mId,f);
  cycles=0;
  switch(f) {
    case 0x37:
      l=(l?l:wordsize)<<3;
      B.GetLE(data,l);
      MonMul(B,B,A);
      break;
    case 0x3a:
      MonInit();
      MonMul(B,A,B);
      MonMul(B,A,B);
      break;
    default:
      if(!cMapCore::DoMap(f,data,l))
        PRINTF(L_SYS_MAP,"%04x: unsupported call %02x",mId,f);
      break;
    }
}

// -- cN2Prov0501 --------------------------------------------------------------

class cN2Prov0501 : public cN2Prov, private cMap0501, public cN2Emu {
private:
  cN2Timer timer[MAX_TIMERS];
  //
  void AddRomCallbacks(void);
  bool RomCallbacks(void);
  bool ProcessMap(int f);
protected:
  virtual bool Algo(int algo, unsigned char *hd, const unsigned char *ed, unsigned char *hw);
  virtual bool NeedsCwSwap(void) { return true; }
  virtual void WriteHandler(unsigned char seg, unsigned short ea, unsigned char &op);
  virtual void ReadHandler(unsigned char seg, unsigned short ea, unsigned char &op);
  virtual void TimerHandler(unsigned int num);
public:
  cN2Prov0501(int Id, int Flags);
  virtual int ProcessBx(unsigned char *data, int len, int pos);
  };

static cN2ProvLinkReg<cN2Prov0501,0x0501,(N2FLAG_MECM|N2FLAG_INV|N2FLAG_Bx)> staticPL0501;

cN2Prov0501::cN2Prov0501(int Id, int Flags)
:cN2Prov(Id,Flags)
,cMap0501(Id)
{
  hasWriteHandler=hasReadHandler=true;
}

bool cN2Prov0501::Algo(int algo, unsigned char *hd, const unsigned char *ed, unsigned char *hw)
{
  if(algo==0x60) {
    hw[0]=hd[0];
    hw[1]=hd[1];
    hw[2]=hd[2]&0xF8;
    ExpandInput(hw);
    hw[63]|=0x80;
    hw[95]=hw[127]=hw[95]&0x7F;
    DoMap(SETSIZE,0,4);
    DoMap(IMPORT_J,hw+0x18);
    DoMap(IMPORT_D,hw+0x20);
    DoMap(IMPORT_A,hw+0x60);
    DoMap(0x37,hw+0x40);
    DoMap(EXPORT_C,hw);
    DoMap(0x3a);
    DoMap(EXPORT_C,hw+0x20);
    DoMap(0x43);
    DoMap(0x44,hw);
    hw[0]&=7;
    DoMap(EXPORT_B,hw+3);
    memset(hw+3+0x20,0,128-(3+0x20));
    return true;
    }

  PRINTF(L_SYS_ECM,"%04X: unknown MECM algo %02x",id,algo);
  return false;
}

bool cN2Prov0501::ProcessMap(int f)
{
  //unsigned short addr;
  //int size=wordsize<<3;
  unsigned char tmp[256];
  int cycles;

  switch(f) {
    case SETSIZE: // set map size 
      DoMap(f,0,Get(0x48));
      if((wordsize<<3)>256) {
        PRINTF(L_SYS_EMU,"%04x: MAP word size too large: %d",id,wordsize);
        return false;
        }
      break;
    case IMPORT_A:
      // Special handling with cycle count
      //cycles=930;
      //cycles = 772 + 160 * Get (0x48); // variant baumi63
      cycles = 724 + 192 * Get (0x48); // variant halyx
      PRINTF(L_SYS_EMU,"%04x: map call %02x mem48=%d, cycles=%d",id,f,Get(0x48),cycles);
      DoMap(f,tmp);
      SetCycles (cycles);
      break;
    default:
      DoMap(f,tmp);
      break;
    }
  AddCycles(MapCycles());
  return true;
}

bool cN2Prov0501::RomCallbacks(void)
{
  unsigned int ea=GetPc();
  if(ea&0x8000) ea|=(cr<<16);
  switch(ea) {
    case 0x3840: //MAP Handler
      if(!ProcessMap(a)) return false;
      break;
    default:
      PRINTF(L_SYS_EMU,"%04X: unknown ROM breakpoint %04x",id,ea);
      return false;
    }
  if(ea>=0x8000) PopCr();
  PopPc();
  return true;
}

void cN2Prov0501::AddRomCallbacks(void)
{
  AddBreakpoint(0x3840);
  //AddBreakpoint(0x3844);
}

int cN2Prov0501::ProcessBx(unsigned char *data, int len, int pos)
{
  if(Init(id,120)) {
    SetMem(0x80,data,len);
    SetPc(0x80+pos);
    SetSp(0x0FFF,0x0FE0);
    Set(0x0001,0xFF);
    Set(0x000E,0xFF);
    Set(0x0000,0x04);
    ClearBreakpoints();
    AddBreakpoint(0x821f);
    AddRomCallbacks();
    while(!Run(5000)) {
      switch(GetPc()) {
        case 0x821f:
          GetMem(0x80,data,len);
          return a;
	default:
	  if(!RomCallbacks()) break;
        }
      }
    }
  return -1;
}

void cN2Prov0501::TimerHandler(unsigned int num)
{
  for(int i=0; i<MAX_TIMERS; i++) 
    if(timer[i].Running()) timer[i].AddCycles(num);
}

void cN2Prov0501::WriteHandler(unsigned char seg, unsigned short ea, unsigned char &op)
{
  switch(ea) {
    case HW_SECURITY:
      if(cr==0x00) op=Get(ea);
      break;
    case HW_TIMER0_CONTROL:
    case HW_TIMER1_CONTROL:
    case HW_TIMER2_CONTROL:
      {
      int num=TIMER_NUM(ea);
      // The value of a Control Register for a timer (i.e. here $16 for the 3rd timer)
      // can't be changed if the timer is running (i.e. old and 2 <> 0 ) : you can only
      // stop it (i.e. op and 2 = 0).
      if(timer[num].Running()) {
        op=(Get(ea)&~tmRUNNING) | (op&tmRUNNING);
        if(!(op&tmRUNNING)) timer[num].Stop();
        }
      else if(op&tmRUNNING) {
        unsigned int div;
        if((op&0xc0)==0x40) div=1 << (2 *(1 + ((op & 0x38) >> 3)));
        else div=4; // This is wrong, but we haven't figured the right value out yet
        timer[num].Start(op,div);
        }
      break;
      }
    case HW_TIMER0_LATCH:
    case HW_TIMER1_LATCH:
    case HW_TIMER2_LATCH:
      {
      int num=TIMER_NUM(ea);
      if(!timer[num].Running()) timer[num].SetLatch(op);
      break;
      }
#if 0
    case HW_CRC_CONTROL:
      // $0e is to program the CRC unit.  $0f is the data to CRC
      // assumes:
      //   bit 1 disables/enables CRCing
      if(!(op&CRC_DISABLED)) {
        // disable -> reset CRC
        CRCvalue=0; CRCpos=0;
        CRCstarttime=Cycles()-CRCCALC_DELAY;
        }
      break;
     case HW_CRC_DATA:
      if(!(Get(HW_CRC_CONTROL)&CRC_DISABLED)) {
        if(Cycles()-CRCstarttime>=CRCCALC_DELAY) {
          // accept new data if not busy
          CRCvalue=(CRCvalue>>8)^crc16table[(CRCvalue^op)&0xff];
          CRCpos=0;
          CRCstarttime=Cycles();
          }
        }
      break;
#endif
    }
}

void cN2Prov0501::ReadHandler(unsigned char seg, unsigned short ea, unsigned char &op)
{
  //printf ("cN2Prov0501::ReadHandler: seg=%02x ea=%04x, op=%02x\n", seg, ea, op);
  switch(ea) {
    case HW_SECURITY:
      if(cr==0) op=0x0F; break;
    case HW_TIMER0_CONTROL:
    case HW_TIMER1_CONTROL:
    case HW_TIMER2_CONTROL:
      {
      int num=TIMER_NUM(ea);
      //printf ("cN2Prov0501::ReadHandler: TimerControl, seg=%02x ea=%04x, op=%02x\n", seg, ea, op);
      op=timer[num].Running() ? op|tmRUNNING : op&~tmRUNNING;
      break;
      }
    case HW_TIMER0_DATA:
    case HW_TIMER1_DATA:
    case HW_TIMER2_DATA:
      {
      int num=TIMER_NUM(ea);
      //printf ("cN2Prov0501::ReadHandler: TimerData,    seg=%02x ea=%04x, op=%02x, cycles=%d\n", seg, ea, op, timer[num].GetCycles());
      op=timer[num].GetCycles();
      break;
      }
#if 0
    case HW_CRC_CONTROL:
      if(!(op&CRC_DISABLED)) {
        //CRC takes 10 cycles to generate
        if(Cycles()-CRCstarttime>=CRCCALC_DELAY) op&=~CRC_BUSY; // not busy
        else op|=CRC_BUSY; // busy
        }
      else op&=~CRC_BUSY; // clear busy bit
      break;
    case HW_CRC_DATA:
      op=CRCvalue>>((CRCpos&1)<<3);
      CRCpos=!CRCpos;
      break;
#endif
    }
}

// -- cN2Prov0511 ----------------------------------------------------------------

static cN2ProvLinkReg<cN2Prov0501,0x0511,(N2FLAG_MECM|N2FLAG_INV)> staticPL0511;

// -- cN2Prov1101 ----------------------------------------------------------------

static cN2ProvLinkReg<cN2Prov0501,0x1101,(N2FLAG_MECM|N2FLAG_INV)> staticPL1101;

// -- cN2Prov3101 ----------------------------------------------------------------

static cN2ProvLinkReg<cN2Prov0501,0x3101,(N2FLAG_MECM|N2FLAG_INV)> staticPL3101;

