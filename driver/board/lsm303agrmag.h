/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LSM303AGRMAG_H_
#define INC_LSM303AGRMAG_H_

#include <string>
#include "lsm303agr.h"

namespace mainunit::driver
{

class CLSM303AgrMagDrv final : public CLSM303Agr
{
public:
	CLSM303AgrMagDrv(const CI2C &i2c);
	virtual ~CLSM303AgrMagDrv();

	bool init();
	bool read();

	uint16_t getXRaw() { return m_rawaxes.uint16.x; }
	uint16_t getYRaw() { return m_rawaxes.uint16.y; }
	uint16_t getZRaw() { return m_rawaxes.uint16.z; }
	int16_t getX() { return m_axes.x; }
	int16_t getY() { return m_axes.y; }
	int16_t getZ() { return m_axes.z; }
	//float getDegree();
	std::string getDegree();

private:
	bool isMagSensor();
	uint8_t getStatus();
	bool readOutAxesRegisters();
	int16_t calcSigDec(uint16_t value);

private:
	union rawaxes
	{
		uint8_t arr[6];

		struct
		{
			uint8_t x[2];
			uint8_t y[2];
			uint8_t z[2];
		} uint8;

		struct
		{
			uint16_t x;
			uint16_t y;
			uint16_t z;
		} uint16;
	};

	struct axes
	{
		int16_t x;
		int16_t y;
		int16_t z;
	};

	constexpr static uint8_t LSM303AGRMAG_WR_ADDR{0x3C};
	constexpr static uint8_t LSM303AGRMAG_RD_ADDR{0x3D};

	constexpr static uint8_t LSM303AGRMAG_WHO_AM_I_M_ID	{0x40};

	constexpr static uint8_t LSM303AGRMAG_OFFSET_X_REG_L_M {0x45};
	constexpr static uint8_t LSM303AGRMAG_OFFSET_X_REG_H_M {0x46};
	constexpr static uint8_t LSM303AGRMAG_OFFSET_Y_REG_L_M {0x47};
	constexpr static uint8_t LSM303AGRMAG_OFFSET_Y_REG_H_M {0x48};
	constexpr static uint8_t LSM303AGRMAG_OFFSET_Z_REG_L_M {0x49};
	constexpr static uint8_t LSM303AGRMAG_OFFSET_Z_REG_H_M {0x4A};
	constexpr static uint8_t LSM303AGRMAG_WHO_AM_I_REG_M{0x4F};
	constexpr static uint8_t LSM303AGRMAG_CFG_REG_A_M	{0x60};
	constexpr static uint8_t LSM303AGRMAG_CFG_REG_C_M	{0x62};
	constexpr static uint8_t LSM303AGRMAG_STATUS_REG_M	{0x67};
	constexpr static uint8_t LSM303AGRMAG_OUTX_L_REG_M	{0x68};
	constexpr static uint8_t LSM303AGRMAG_OUTX_H_REG_M	{0x69};
	constexpr static uint8_t LSM303AGRMAG_OUTY_L_REG_M	{0x6A};
	constexpr static uint8_t LSM303AGRMAG_OUTY_H_REG_M	{0x6B};
	constexpr static uint8_t LSM303AGRMAG_OUTZ_L_REG_M	{0x6C};
	constexpr static uint8_t LSM303AGRMAG_OUTZ_H_REG_M	{0x6D};

	const float m_sensitivy = 1.5f;

	rawaxes m_rawaxes;
	axes m_axes;
};

}

#endif /* INC_LSM303AGRMAG_HPP_ */
