/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */
#include "lsm303agracc.h"

namespace mainunit::driver
{

CLSM303AgrAccDrv::CLSM303AgrAccDrv(const CI2C &i2c) : CLSM303Agr(i2c, LSM303AGRACC_WR_ADDR, LSM303AGRACC_RD_ADDR)
{

}

CLSM303AgrAccDrv::~CLSM303AgrAccDrv()
{

}

bool CLSM303AgrAccDrv::init()
{
	if(!isAccSensor())
		return false;

	std::vector<uint8_t> data;

	// Mag data-ready interrupt enable
	data.push_back(0x57);
	if(!writeRegister(LSM303AGRMAG_CTRL_REG1_A, data))
		return false;

	if(getStatus() == 0)
		return false;

	return true;
}

bool CLSM303AgrAccDrv::read()
{
	return false;
}

bool CLSM303AgrAccDrv::isAccSensor()
{
	std::vector<uint8_t> buffer;

	readRegister(LSM303AGRMAG_WHO_AM_I_REG_A, buffer, 1);

	if(buffer[0] == LSM303AGRMAG_WHO_AM_I_A_ID)
		return true;

	return false;
}

uint8_t CLSM303AgrAccDrv::getStatus()
{
	std::vector<uint8_t> buffer;

	if(!readRegister(LSM303AGRMAG_STATUS_REG_A, buffer, 1))
		return 0;

	return buffer[0];
}

}
