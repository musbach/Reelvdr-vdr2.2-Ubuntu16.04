/*                                                                  -*- c++ -*-
 * ttxtaudio.c
 *
 *  Created on: Oct 31, 2012
 *      Author: Dimitar Petrovski
 */

#include "ttxtaudio.h"

int64_t cTtxtAudio::pts = 0;

cTtxtAudio::cTtxtAudio()
:cExternalAudio("TtxtAudio")
{
}

cTtxtAudio::~cTtxtAudio()
{
}

void cTtxtAudio::Play(const uchar* p, int Length, uchar Id)
{
  int64_t tmp_pts = 0;

  if (PesHasPts(p))
    tmp_pts = PesGetPts(p);
  if (tmp_pts != 0) {
    if ((pts > 0x1ffff0000LL) && (tmp_pts < 0x000100000LL)) {
      tmp_pts+=0x200000000LL;
    }
  }
  if (tmp_pts != pts) { pts=tmp_pts; }

}

void cTtxtAudio::PlayTs(const uchar* Data, int Length)
{
//  isyslog("ttxtsubs: cTtxtAudio::PlayTs");
    tsToPesTtxtAudio.PutTs(Data, Length);
    int l;
    if (const uchar *p = tsToPesTtxtAudio.GetPes(l)) {
       Play(p,l,0);
       tsToPesTtxtAudio.Reset();
    }
}
