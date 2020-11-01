/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "hellaibs.h"

#define _ISSET_BIT(byte, bit)		(byte & (1UL << (bit)))

namespace mainunit::driver
{

CHellaIBS::CHellaIBS(const CLinManager &manager) : m_manager(const_cast<CLinManager&>(manager))
{
	m_lindevice = LinDevice::DEVICE_OFF;
	m_soc = 0;
	m_soh = 0;
	m_Ubatt = 0.0;
	m_Ibatt = 0.0;
	m_Btemp = 0.0;
	m_AvCap = 0.0;
}

CHellaIBS::~CHellaIBS()
{

}

bool CHellaIBS::transfer(const std::vector<uint8_t> &writebuf, std::vector<uint8_t> &readbuf)
{
	m_manager.write(m_lindevice, writebuf);
	HAL_Delay(100);
	m_manager.read(readbuf);

	if(readbuf.size() > 0)
		return true;

	return false;
}

bool CHellaIBS::getIdentification(uint8_t linID)
{
	std::vector<uint8_t> id;
	std::vector<uint8_t> buffer;

	id.push_back((linID & 0x3F) | addParity(linID));
	if(transfer(id, buffer) == false)
		return false;

	return true;
}

bool CHellaIBS::getCurrentValues(uint8_t linID)
{
	std::vector<uint8_t> id;
	std::vector<uint8_t> buffer;

	id.push_back((linID & 0x3F) | addParity(linID));
	if(transfer(id, buffer) == false)
		return false;

	m_Ubatt = (float((buffer[4] << 8) + buffer[3])) / 1000;
	m_Ibatt = (float((long(buffer[2]) << 16) + (long(buffer[1]) << 8) + long(buffer[0]) - 2000000L)) / 1000;
	m_Btemp = long(buffer[5]) / 2 - 40;


	return true;
}

bool CHellaIBS::getStatusError(uint8_t linID)
{
	std::vector<uint8_t> id;
	std::vector<uint8_t> buffer;

	id.push_back((linID & 0x3F) | addParity(linID));
	if(transfer(id, buffer) == false)
		return false;

	return true;
}

bool CHellaIBS::getIBSFrame4(uint8_t linID)
{
	std::vector<uint8_t> id;
	std::vector<uint8_t> buffer;

	id.push_back((linID & 0x3F) | addParity(linID));
	if(transfer(id, buffer) == false)
		return false;

	return true;
}

bool CHellaIBS::getIBSFrame5(uint8_t linID)
{
	std::vector<uint8_t> id;
	std::vector<uint8_t> buffer;

	id.push_back((linID & 0x3F) | addParity(linID));
	if(transfer(id, buffer) == false)
		return false;

	m_soc = int(buffer[0]) / 2;
	m_soh = int(buffer[1]) / 2;

	return true;
}

bool CHellaIBS::getIBSFrame6(uint8_t linID)
{
	std::vector<uint8_t> id;
	std::vector<uint8_t> buffer;

	id.push_back((linID & 0x3F) | addParity(linID));
	if(transfer(id, buffer) == false)
		return false;

	return true;
}

uint8_t CHellaIBS::addParity(uint8_t linID)
{
  uint8_t p0 = _ISSET_BIT(linID, 0)^_ISSET_BIT(linID, 1)^_ISSET_BIT(linID, 2)^_ISSET_BIT(linID, 4);
  uint8_t p1 = ~(_ISSET_BIT(linID, 1)^_ISSET_BIT(linID, 3)^_ISSET_BIT(linID, 4)^_ISSET_BIT(linID, 5));   // evtl. Klammer rum ???
  return ((p0 | (p1 << 1)) << 6);
}

}
