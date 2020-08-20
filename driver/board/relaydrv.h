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

class RelayDrv
{
public:
	RelayDrv(const SPI &hspi);
	virtual ~RelayDrv();

	void set(OutputNr chn);

private:
	SPI &m_pspi;
	uint8_t m_transfer;

};


#endif /* DRIVER_BOARD_RELAYDRV_H_ */
