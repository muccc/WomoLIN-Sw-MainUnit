/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LIN_HPP_
#define INC_LIN_HPP_

/**
 * Handle TJA1029 and SN74lv4052.
 */
#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_it.h"

#include "circularbuffer.h"
#include <vector>

namespace mainunit::driver
{

class CLin
{
public:
	CLin(UART_HandleTypeDef *huart, CircularBuffer<uint8_t> *buffer);

	bool read(std::vector<uint8_t> &data);
	bool write(const std::vector<uint8_t> &data);
	void test();
	uint8_t addParity(uint8_t id);

	CLin() = delete;
	CLin(const CLin &) = delete;

private:
	static void irquarthandler(void *param);
	void irqhandler();

private:
	UART_HandleTypeDef *m_phuart;
	CircularBuffer<uint8_t> *m_pbuffer;
	uint32_t m_lastsendsize;
};

}

#endif /* INC_LIN_HPP_ */
