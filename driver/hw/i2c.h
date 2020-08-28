/*
 * i2c.hpp
 *
 *  Created on: 26.08.2020
 *      Author: tseeck
 */

#ifndef INC_I2C_HPP_
#define INC_I2C_HPP_

#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"

#include <vector>

class CI2C
{
public:
	CI2C(I2C_HandleTypeDef *hspi);

	uint32_t read(const uint16_t addr, std::vector<uint8_t> &data, uint32_t toread);
	void write(const uint16_t addr, const std::vector<uint8_t> &data);

	CI2C() = delete;
	CI2C(const CI2C &) = delete;

private:
	I2C_HandleTypeDef *m_phi2c;
};



#endif /* INC_I2C_HPP_ */