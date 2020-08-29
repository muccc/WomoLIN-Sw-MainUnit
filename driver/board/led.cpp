/*
 * led.cpp
 *
 *  Created on: 26.08.2020
 *      Author: tseeck
 */
#include "led.h"


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
