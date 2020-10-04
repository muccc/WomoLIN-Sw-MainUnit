/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LSM303AGR_H_
#define INC_LSM303AGR_H_

#include <stdint.h>
#include <vector>

#include "i2c.h"

namespace mainunit::driver
{

class CLSM303Agr
{
public:
	CLSM303Agr(const CI2C &i2c, const uint8_t &wr_addr, const uint8_t &rd_addr);
	virtual ~CLSM303Agr();

	bool readRegister(uint8_t regaddr, std::vector<uint8_t> &data, uint32_t toread);
	bool writeRegister(uint8_t regaddr, std::vector<uint8_t> &data);

private:
	CI2C &m_pi2c;
	const uint8_t LSM303AGR_WR_ADDR;
	const uint8_t LSM303AGR_RD_ADDR;
};

}

#endif /* INC_LSM303AGR_HPP_ */
