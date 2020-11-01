/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LINMULTIPLEXER_HPP_
#define INC_LINMULTIPLEXER_HPP_

#include "gpio.h"

namespace mainunit::driver
{

enum class MultiplexerChannel
{
	CHANNEL_0 = 0,
	CHANNEL_1 = 1,
	CHANNEL_2 = 2,
	CHANNEL_3 = 3,
	CHANNEL_CNT = 4,
	CHANNEL_NONE
};

class CLinMultiplexer
{
public:
	CLinMultiplexer(const GPIO &enable, const GPIO &a0, const GPIO &a1);
	virtual ~CLinMultiplexer();

	void enable() { m_enable.setLow(); }
	void disable() { m_enable.setHigh(); }

	void setChannel(const MultiplexerChannel &channel);

private:
	GPIO &m_enable;
	GPIO &m_a0;
	GPIO &m_a1;
	MultiplexerChannel m_channel;
};

}

#endif /* INC_LINMULTIPLEXER_HPP_ */
