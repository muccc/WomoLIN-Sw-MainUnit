/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "spi.h"

SPI::SPI(SPI_HandleTypeDef *hspi) : m_phspi(hspi)
{
}

uint32_t SPI::read(std::vector<uint8_t> &data, const uint32_t toread)
{
	uint8_t _tmp[toread];

	HAL_SPI_Receive(m_phspi, (uint8_t *)_tmp, toread, 100);

	for(size_t i = 0; i < data.size(); i++)
		data[i] = _tmp[i];

	return 0;
}

void SPI::write(const std::vector<uint8_t> &data)
{
	if(data.size() > 0)
		HAL_SPI_Transmit(m_phspi, (uint8_t *)data.data(), data.size(), 100);
}
