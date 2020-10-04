/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "led.h"

namespace mainunit::driver
{

CLed::CLed(const GPIO &gpio) : m_pled(const_cast<GPIO&>(gpio))
{
}

CLed::~CLed()
{
}

void CLed::set(bool status)
{
	if(status)
		m_pled.setHigh();
	else
		m_pled.setLow();
}

}
