/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef DRIVER_BOARD_LED_H_
#define DRIVER_BOARD_LED_H_

#include "gpio.h"

class CLed
{
public:
	CLed(const GPIO &gpio);
	~CLed();

	void set(bool status);

	CLed() = delete;
	CLed(const CLed &) = delete;

private:
	GPIO &m_pled;
};



#endif /* DRIVER_BOARD_LED_H_ */
