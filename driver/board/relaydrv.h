/*
 * relaydrv.h
 *
 *  Created on: 17.08.2020
 *      Author: tseeck
 */

#ifndef DRIVER_BOARD_RELAYDRV_H_
#define DRIVER_BOARD_RELAYDRV_H_

//#include <stdint.h>

#include "spi.h"
#if 0
enum class OutputNr
{
	OUTPUT1 = 0x01,
	OUTPUT2 = 0x02,
	OUTPUT3 = 0x04,
	OUTPUT4 = 0x08,
	OUTPUT5 = 0x10,
	OUTPUT6 = 0x20,
	OUTPUT7 = 0x40,
	OUTPUT8 = 0x80
};
#else
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
#endif

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

	void set(OutputNr chn);
	void reset(OutputNr chn);
	bool isSet(OutputNr chn);

private:
	void write();
	void read();

private:
	SPI &m_pspi;
	static uint8_t m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREGMAX)];
	const ShiftRegNr shiftreg;

};


#endif /* DRIVER_BOARD_RELAYDRV_H_ */
