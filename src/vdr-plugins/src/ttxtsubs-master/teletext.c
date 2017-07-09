/*                                                                  -*- c++ -*-
 * vdr-ttxtsubs - A plugin for the Linux Video Disk Recorder
 * Copyright (c) 2003 - 2008 Ragnar Sundblad <ragge@nada.kth.se>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <ctype.h>
#include <string.h>

//#include <linux/dvb/dmx.h>
//#include <vdr/osd.h>
#include <vdr/config.h>

#include "teletext.h"
#include "teletext-tables.h"
#include "teletext-chars.h"
#include "utils.h"


// FROM vbidecode
// unham 2 bytes into 1, report 2 bit errors but ignore them
unsigned char unham(unsigned char a,unsigned char b)
{
  unsigned char c1,c2;
  
  c1=unhamtab[a];
  c2=unhamtab[b];
//  if ((c1|c2)&0x40) 
//      dprint("bad ham!");
  return (c2<<4)|(0x0f&c1);
}


/*
 * Map Latin G0 teletext characters into a ISO-8859-1 approximation.
 * Trying to use similar looking or similar meaning characters.
 * Gtriplet - 4 bits = triplet-1 bits 14-11 (14-8) of a X/28 or M/29 packet, if unknown - use 0
 * natopts - 3 bits = national_options field of a Y/0 packet (or triplet-1 bits 10-8 as above?)
 * inchar - 7 bits = characted to remap
 * Also strips parity
 */

uint16_t ttxt_laG0_la1_char(int Gtriplet, int natopts, uint8_t inchar)
{
  int no = laG0_nat_opts_lookup[Gtriplet & 0xf][natopts & 0x7];
  uint8_t c = inchar & 0x7f;

  //dprint("\n%x/%c/%x/%x\n", c, c, laG0_nat_replace_map[c], laG0_nat_opts[no][laG0_nat_replace_map[c]]);

  if(!laG0_nat_replace_map[c])
    return c;
  else
    if (cCharSetConv::SystemCharacterTable())
       return laG0_nat_opts[no][laG0_nat_replace_map[c]];
    else
       return laG0_nat_opts16[no][laG0_nat_replace_map[c]];
}
