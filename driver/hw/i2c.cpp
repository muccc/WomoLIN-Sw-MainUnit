/*
 * i2c.cpp
 *
 *  Created on: 26.08.2020
 *      Author: tseeck
 */

#include "i2c.h"

I2C::I2C(I2C_HandleTypeDef *hi2c, const uint16_t addr) : m_phi2c(hi2c), m_addr(addr)
{

}

uint32_t I2C::read(std::vector<uint8_t> &data, uint32_t toread)
{
	uint8_t tmp[toread];

	HAL_I2C_Master_Receive(m_phi2c, m_addr, tmp, toread, 100);

	for(uint32_t i = 0; i < toread; i++)
		data.push_back(tmp[i]);

	return toread;
}

void I2C::write(const std::vector<uint8_t> &data)
{
	HAL_I2C_Master_Transmit(m_phi2c, m_addr, (uint8_t *)data.data(), data.size(), 100);
}
