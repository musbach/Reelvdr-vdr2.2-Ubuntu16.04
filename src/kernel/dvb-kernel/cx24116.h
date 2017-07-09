/*
    Conexant cx24116/cx24118 - DVBS/S2 Satellite demod/tuner driver

    Copyright (C) 2006 Steven Toth <stoth@hauppauge.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef CX24116_H
#define CX24116_H

#include <linux/dvb/frontend.h>

struct cx24116_config
{
	/* the demodulator's i2c address */
	u8 demod_address;
	int clock_polarity; // 0/1: TS data change at rising/falling edge

	/* Need to set device param for start_dma */
	int (*set_ts_params)(struct dvb_frontend* fe, int is_punctured);
	
	/* Need to reset device during firmware loading */
	int (*reset_device)(struct dvb_frontend* fe);
};

extern struct dvb_frontend* cx24116_attach(const struct cx24116_config* config,
					   struct i2c_adapter* i2c);

#endif /* CX24116_H */