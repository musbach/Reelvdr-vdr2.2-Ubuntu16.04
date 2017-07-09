/*                                                                  -*- c++ -*-
 * ttxtaudio.h
 *
 *  Created on: Oct 31, 2012
 *      Author: Dimitar Petrovski
 */

#ifndef CTTXTAUDIO_H_
#define CTTXTAUDIO_H_

#include <vdr/audio.h>
#include <vdr/remux.h>

class cTtxtAudio : public cExternalAudio
{
public:
  cTtxtAudio();
  virtual ~cTtxtAudio();

  virtual void Play(const uchar *Data, int Length, uchar Id);
  virtual void PlayTs(const uchar *Data, int Length);
  virtual void Mute(bool On){};
  virtual void Clear(void){};

  static int64_t pts;
private:
  cTsToPes tsToPesTtxtAudio;

};

#endif /* CTTXTAUDIO_H_ */
