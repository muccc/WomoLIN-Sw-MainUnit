/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "linmultiplexer.h"

namespace mainunit::driver
{

CLinMultiplexer::CLinMultiplexer(const GPIO &enable, const GPIO &a0, const GPIO &a1) : m_enable(const_cast<GPIO&>(enable)), m_a0(const_cast<GPIO&>(a0)), m_a1(const_cast<GPIO&>(a1)), m_channel(MultiplexerChannel::CHANNEL_NONE)
{

}

CLinMultiplexer::~CLinMultiplexer()
{

}

void CLinMultiplexer::setChannel(const MultiplexerChannel &channel)
{
	bool valid = true;

	switch(channel)
	{
	case MultiplexerChannel::CHANNEL_0:
		m_a0.setLow();
		m_a1.setLow();
		break;
	case MultiplexerChannel::CHANNEL_1:
		m_a0.setHigh();
		m_a1.setLow();
		break;
	case MultiplexerChannel::CHANNEL_2:
		m_a0.setLow();
		m_a1.setHigh();
		break;
	case MultiplexerChannel::CHANNEL_3:
		m_a0.setHigh();
		m_a1.setHigh();
		break;
	default:
		valid = false;
		break;
	}

	if(valid) {
		m_channel = channel;
	}
}

}
