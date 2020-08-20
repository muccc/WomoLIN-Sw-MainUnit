/*
 * relaydrv.cpp
 *
 *  Created on: 17.08.2020
 *      Author: tseeck
 */

#include "relaydrv.h"

#include <vector>

RelayDrv::RelayDrv(const SPI &hspi) : m_pspi(const_cast<SPI&>(hspi))
{
}

RelayDrv::~RelayDrv()
{
}

void RelayDrv::set(OutputNr chn)
{
	std::vector<uint8_t> data;

	m_transfer = static_cast<uint8_t>(chn);

	data.push_back(m_transfer);

	m_pspi.write(data);
}
