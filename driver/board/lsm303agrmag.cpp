/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */
#include "lsm303agrmag.h"

#include <string.h>
#include <vector>
#include <math.h>

namespace mainunit::driver
{

CLSM303AgrMagDrv::CLSM303AgrMagDrv(const CI2C &i2c) : CLSM303Agr(i2c, LSM303AGRMAG_WR_ADDR, LSM303AGRMAG_RD_ADDR)
{

}

CLSM303AgrMagDrv::~CLSM303AgrMagDrv()
{

}

bool CLSM303AgrMagDrv::init()
{
	if(!isMagSensor())
		return false;

	std::vector<uint8_t> data;

	// Mag = 10 Hz (high-resolution and continuous mode)
	data.push_back(0x00);
	if(!writeRegister(LSM303AGRMAG_CFG_REG_A_M, data))
		return false;

	data.clear();

	// Mag data-ready interrupt enable
	data.push_back(0x01);
	if(!writeRegister(LSM303AGRMAG_CFG_REG_C_M, data))
		return false;

	if(getStatus() == 0)
		return false;

	if(!readOutAxesRegisters())
		return false;

	return true;
}

bool CLSM303AgrMagDrv::read()
{
	memset(&m_axes, 0, sizeof(m_axes));

	if(!readOutAxesRegisters())
		return false;

	m_axes.x = calcSigDec(m_rawaxes.uint16.x) * m_sensitivy;
	m_axes.y = calcSigDec(m_rawaxes.uint16.y) * m_sensitivy;
	m_axes.z = calcSigDec(m_rawaxes.uint16.z) * m_sensitivy;

	return true;
}

bool CLSM303AgrMagDrv::isMagSensor()
{
	std::vector<uint8_t> buffer;

	readRegister(LSM303AGRMAG_WHO_AM_I_REG_M, buffer, 1);

	if(buffer[0] == LSM303AGRMAG_WHO_AM_I_M_ID)
		return true;

	return false;
}

uint8_t CLSM303AgrMagDrv::getStatus()
{
	std::vector<uint8_t> buffer;

	if(!readRegister(LSM303AGRMAG_STATUS_REG_M, buffer, 1))
		return 0;

	return buffer[0];
}

int16_t CLSM303AgrMagDrv::calcSigDec(uint16_t value)
{
	int16_t erg = 0;
	for(int i = 0; i < 16; i++) {
		if(value & 0x0001) {
			if(i == 15) {
				erg = erg - pow(2, i);
				continue;
			}
			erg += pow(2, i);
		}
		value >>= 1;
	}

	return erg;
}
/**
float CLSM303AgrMagDrv::getDegree()
{
	float ret = 0.0;

	ret = (float)(90 - atan((double)m_axes.y / (double)m_axes.x) * 180.0 / M_PI);

	return ret;
}
*/
std::string CLSM303AgrMagDrv::getDegree()
{
	float ret = (float)(90 - atan((double)m_axes.y / (double)m_axes.x) * 180.0 / M_PI);
	int tmp0 = (int)ret;
	int tmp1 = (int)((ret - tmp0) * 10);
	std::string str = std::to_string(tmp0) + "." + std::to_string(tmp1);

	return str;

}

bool CLSM303AgrMagDrv::readOutAxesRegisters()
{
	// Check, is new data available?
	//if(getStatus() & 0x08)
		//return false;

#if 1
	std::vector<uint8_t> buffer;

	if(!readRegister(LSM303AGRMAG_OUTX_L_REG_M, buffer, 6))
		return false;

	for(int i = 0; i < 6; i++){
		m_rawaxes.arr[i] = buffer[i];
	}

	return true;
#else
	for(int i = 0; i < 6; i++)
	{
		std::vector<uint8_t> buffer;

		if(!readRegister(LSM303AGRMAG_OUTX_L_REG_M + i, buffer, 1))
			return false;

		m_axes.magarr[i] = buffer.back();

		buffer.pop_back();
	}

	return true;
#endif
}

}
