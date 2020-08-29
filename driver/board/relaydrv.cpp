/*
 * relaydrv.cpp
 *
 *  Created on: 17.08.2020
 *      Author: tseeck
 */

#include "relaydrv.h"

#include <vector>

#define _SET_BIT(byte, bit)		((byte) |= (1UL << (bit)))
#define _CLR_BIT(byte, bit)		((byte) &= ~(1UL << (bit)))
#define _ISSET_BIT(byte, bit)		((byte) &= (1UL << (bit)))

uint8_t RelayDrv::m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREGMAX)] = {0, 0};


RelayDrv::RelayDrv(const SPI &hspi, const ShiftRegNr reg) : m_pspi(const_cast<SPI&>(hspi)), shiftreg(reg)//shiftreg(ShiftRegNr::SHIFTREG1)
{
	RelayDrv::m_transfer[0] = 0;
	RelayDrv::m_transfer[1] = 0;
	//read();
}

RelayDrv::~RelayDrv()
{
}

void RelayDrv::set(OutputNr chn, bool _write)
{
	if(chn >= OutputNr::OUTPUTMAX)
		return;

	_SET_BIT(m_transfer[static_cast<uint32_t>(shiftreg)], static_cast<uint8_t>(chn));

	if(_write)
		write();
}

void RelayDrv::reset(OutputNr chn, bool _write)
{
	if(chn >= OutputNr::OUTPUTMAX)
		return;

	_CLR_BIT(m_transfer[static_cast<uint32_t>(shiftreg)], static_cast<uint8_t>(chn));

	if(_write)
		write();
}

bool RelayDrv::isSet(OutputNr chn)
{
	if(_ISSET_BIT(m_transfer[static_cast<uint32_t>(shiftreg)], static_cast<uint8_t>(chn)))
		return true;

	return false;
}

void RelayDrv::write()
{
	std::vector<uint8_t> data;


	data.push_back(m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREG2)]);
	data.push_back(m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREG1)]);
	m_pspi.write(data);
}

void RelayDrv::read()
{
	std::vector<uint8_t> data;

	m_pspi.read(data, static_cast<uint8_t>(ShiftRegNr::SHIFTREGMAX));

	m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREG1)] = data[static_cast<uint8_t>(ShiftRegNr::SHIFTREG1)];
	m_transfer[static_cast<uint8_t>(ShiftRegNr::SHIFTREG2)] = data[static_cast<uint8_t>(ShiftRegNr::SHIFTREG2)];
}
