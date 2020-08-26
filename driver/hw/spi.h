/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_SPI_HPP_
#define INC_SPI_HPP_

#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"

#include <vector>

class SPI
{
public:
	SPI(SPI_HandleTypeDef *hspi);

	uint32_t read(std::vector<uint8_t> &data, const uint32_t toread);
	void write(const std::vector<uint8_t> &data);

	SPI() = delete;
	SPI(const SPI &) = delete;

private:
	SPI_HandleTypeDef *m_phspi;
};


#endif /* INC_SPI_HPP_ */
