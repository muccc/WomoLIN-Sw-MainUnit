/*
 * powerswitch.cpp
 *
 *  Created on: 01.11.2020
 *      Author: tseeck
 */
#include "hssdrv.h"

#include <memory>

namespace mainunit::driver
{

CHSSDrv::CHSSDrv(const GPIO &hssen1, const GPIO &hssen2, const GPIO &hssen3, const GPIO &hssen4) : m_hssen1(const_cast<GPIO &>(hssen1)), m_hssen2(const_cast<GPIO &>(hssen2)), m_hssen3(const_cast<GPIO &>(hssen3)), m_hssen4(const_cast<GPIO &>(hssen4))
{

}

CHSSDrv::~CHSSDrv()
{

}

void CHSSDrv::set(HssNr number, bool state)
{
	GPIO  *_hssen;

	switch(number)
	{
	case HssNr::HSSSWITCH1: _hssen = &m_hssen1; break;
	case HssNr::HSSSWITCH2: _hssen = &m_hssen2; break;
	case HssNr::HSSSWITCH3: _hssen = &m_hssen3; break;
	case HssNr::HSSSWITCH4: _hssen = &m_hssen4; break;
	default: return;
	}

	if(state) {
		_hssen->setHigh();
	} else {
		_hssen->setLow();
	}
}

const bool CHSSDrv::get(HssNr number)
{
	GPIO  *_hssen;

	switch(number)
	{
	case HssNr::HSSSWITCH1: _hssen = &m_hssen1; break;
	case HssNr::HSSSWITCH2: _hssen = &m_hssen2; break;
	case HssNr::HSSSWITCH3: _hssen = &m_hssen3; break;
	case HssNr::HSSSWITCH4: _hssen = &m_hssen4; break;
	default: return false;
	}

	return _hssen->getState();
}

}
