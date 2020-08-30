/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "i2c.h"

#include <string.h>

CI2C::CI2C(I2C_HandleTypeDef *hi2c) : m_phi2c(hi2c)
{

}

uint32_t CI2C::read(const uint16_t addr, std::vector<uint8_t> &data, uint32_t toread)
{
	const uint32_t maxtoread = 16;
	uint8_t tmp[maxtoread];
	uint16_t regaddr = data.front();
	data.clear();
	memset(tmp, 0, maxtoread);

	if(toread > maxtoread)
		toread = maxtoread;

	if(HAL_I2C_Mem_Read(m_phi2c, (uint16_t)(addr << 1), regaddr, I2C_MEMADD_SIZE_8BIT, &tmp[0], (uint16_t)toread, 10000) != HAL_OK)
		return 0;

	for(uint32_t i = 0; i < toread; i++)
		data.push_back(tmp[i]);

	return toread;
}

void CI2C::write(const uint16_t addr, const std::vector<uint8_t> &data)
{
	HAL_I2C_Mem_Write(m_phi2c, (uint16_t)(addr << 1), (uint16_t)data[0], I2C_MEMADD_SIZE_8BIT, (uint8_t *)&data[1], (uint16_t)(data.size() - 1), 10000);
}
