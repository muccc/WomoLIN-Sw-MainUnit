/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_UART_HPP_
#define INC_UART_HPP_

#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_it.h"

#include "circularbuffer.h"

class Uart
{
public:
	Uart(UART_HandleTypeDef *huart, CircularBuffer<uint8_t> *buffer);

	uint32_t read(std::string &data);
	void write(const std::string &data);

	Uart() = delete;
	Uart(const Uart &) = delete;

private:
	static void irquarthandler(void *param);
	void irqhandler();

private:
	UART_HandleTypeDef *m_phuart;
	CircularBuffer<uint8_t> *m_pbuffer;
	uint32_t m_lastsendsize;
};



#endif /* INC_UART_HPP_ */
