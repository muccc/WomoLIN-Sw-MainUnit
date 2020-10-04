/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LSM303AGRACC_H_
#define INC_LSM303AGRACC_H_

#include "lsm303agr.h"

namespace mainunit::driver
{

class CLSM303AgrAccDrv final : CLSM303Agr
{
public:
	CLSM303AgrAccDrv(const CI2C &i2c);
	virtual ~CLSM303AgrAccDrv();

	bool init();
	bool read();

private:
	bool isAccSensor();
	uint8_t getStatus();

private:
	constexpr static uint8_t LSM303AGRACC_WR_ADDR{0x32};
	constexpr static uint8_t LSM303AGRACC_RD_ADDR{0x33};

	constexpr static uint8_t LSM303AGRMAG_WHO_AM_I_A_ID	{0x33};

	constexpr static uint8_t LSM303AGRMAG_WHO_AM_I_REG_A{0x0F};
	constexpr static uint8_t LSM303AGRMAG_CTRL_REG1_A	{0x20};
	constexpr static uint8_t LSM303AGRMAG_STATUS_REG_A	{0x27};
};

}

#endif /* INC_LSM303AGRACC_HPP_ */
