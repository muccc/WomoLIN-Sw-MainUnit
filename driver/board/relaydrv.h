/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef DRIVER_BOARD_RELAYDRV_H_
#define DRIVER_BOARD_RELAYDRV_H_

//#include <stdint.h>

#include "spi.h"

namespace mainunit::driver
{

enum class OutputNr
{
	OUTPUT1 = 0,
	OUTPUT2 = 1,
	OUTPUT3 = 2,
	OUTPUT4 = 3,
	OUTPUT5 = 4,
	OUTPUT6 = 5,
	OUTPUT7 = 6,
	OUTPUT8 = 7,
	OUTPUTMAX = 8
};

enum class ShiftRegNr
{
	SHIFTREG1 = 0,
	SHIFTREG2 = 1,
	SHIFTREGMAX = 2
};

class RelayDrv
{
public:
	RelayDrv(const SPI &hspi, const ShiftRegNr reg);
	virtual ~RelayDrv();

	void set(OutputNr chn, bool _write = true);
	void reset(OutputNr chn, bool _write = true);
	bool isSet(OutputNr chn);

	void write();
	void read();

private:

private:
	SPI &m_pspi;
	static uint8_t m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREGMAX)];
	const ShiftRegNr shiftreg;

};

}

#endif /* DRIVER_BOARD_RELAYDRV_H_ */
