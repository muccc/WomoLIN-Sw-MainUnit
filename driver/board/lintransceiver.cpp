/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "lintransceiver.h"

namespace mainunit::driver
{

CLinTransceiver::CLinTransceiver(const GPIO &slplin1, const GPIO &slplin2, const GPIO &slplin3, const GPIO &slplin4) : m_slplin1(const_cast<GPIO&>(slplin1)), m_slplin2(const_cast<GPIO&>(slplin2)), m_slplin3(const_cast<GPIO&>(slplin3)), m_slplin4(const_cast<GPIO&>(slplin4))
{

}

CLinTransceiver::~CLinTransceiver()
{

}

void CLinTransceiver::set(LinTransceiver transceiver)
{
	if(transceiver >= LinTransceiver::TRANSCEIVER_CNT)
		return;

	switch(transceiver)
	{
	case LinTransceiver::TRANSCEIVER_1:
		m_slplin1.setHigh();
		m_slplin2.setLow();
		m_slplin3.setLow();
		m_slplin4.setLow();
		break;
	case LinTransceiver::TRANSCEIVER_2:
		m_slplin1.setLow();
		m_slplin2.setHigh();
		m_slplin3.setLow();
		m_slplin4.setLow();
		break;
	case LinTransceiver::TRANSCEIVER_3:
		m_slplin1.setLow();
		m_slplin2.setLow();
		m_slplin3.setHigh();
		m_slplin4.setLow();
		break;
	case LinTransceiver::TRANSCEIVER_4:
		m_slplin1.setLow();
		m_slplin2.setLow();
		m_slplin3.setLow();
		m_slplin4.setHigh();
		break;
	case LinTransceiver::TRANSCEIVER_OFF:
		m_slplin1.setLow();
		m_slplin2.setLow();
		m_slplin3.setLow();
		m_slplin4.setLow();
		break;
	case LinTransceiver::TRANSCEIVER_CNT: return;
	default: return;
	}
}

}
