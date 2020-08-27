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

class I2C
{
public:
	I2C(I2C_HandleTypeDef *hspi, const uint16_t addr);

	uint32_t read(std::vector<uint8_t> &data, uint32_t toread);
	void write(const std::vector<uint8_t> &data);

	I2C() = delete;
	I2C(const I2C &) = delete;

private:
	I2C_HandleTypeDef *m_phi2c;
	const uint16_t m_addr;
};



#endif /* INC_I2C_HPP_ */
