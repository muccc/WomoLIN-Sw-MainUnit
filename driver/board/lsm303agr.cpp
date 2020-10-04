/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */
#include "lsm303agr.h"

namespace mainunit::driver
{

CLSM303Agr::CLSM303Agr(const CI2C &i2c, const uint8_t &wr_addr, const uint8_t &rd_addr) : m_pi2c(const_cast<CI2C&>(i2c)), LSM303AGR_WR_ADDR(wr_addr), LSM303AGR_RD_ADDR(rd_addr)
{

}

CLSM303Agr::~CLSM303Agr()
{

}

bool CLSM303Agr::readRegister(uint8_t regaddr, std::vector<uint8_t> &data, uint32_t toread)
{
	if(data.size() > 0)
		data.clear();

	data.push_back(regaddr);

	// Read data.
	if(m_pi2c.read(LSM303AGR_RD_ADDR, data, toread) == 0)
		return false;

	if(data.size() < 1)
		return false;

	return true;
}

bool CLSM303Agr::writeRegister(uint8_t regaddr, std::vector<uint8_t> &data)
{
	std::vector<uint8_t>::iterator it;

	it = data.begin();
	it = data.insert (it, regaddr);

	return m_pi2c.write(LSM303AGR_WR_ADDR, data);
}

}
