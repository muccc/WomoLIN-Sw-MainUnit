/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "linmgr.h"

namespace mainunit::driver
{

CLinManager::CLinManager(const CLinMultiplexer &multiplexer, const CLinTransceiver &transceiver, const CLin &lin) : m_multiplexer(const_cast<CLinMultiplexer&>(multiplexer)), m_transceiver(const_cast<CLinTransceiver&>(transceiver)), m_lin(const_cast<CLin&>(lin))
{
	m_lindev = LinDevice::DEVICE_OFF;
}

CLinManager::~CLinManager()
{

}

void CLinManager::setOn(bool state)
{
	if(state) {
		m_multiplexer.enable();
		m_multiplexer.setChannel(MultiplexerChannel::CHANNEL_0);

		m_transceiver.set(LinTransceiver::TRANSCEIVER_1);

		m_lindev = LinDevice::DEVICE_1;
	} else {
		m_multiplexer.disable();

		m_transceiver.set(LinTransceiver::TRANSCEIVER_OFF);

		m_lindev = LinDevice::DEVICE_OFF;
	}
}

bool CLinManager::read(std::vector<uint8_t> &data)
{
	return m_lin.read(data);
}

bool CLinManager::write(LinDevice lindev, const std::vector<uint8_t> &data)
{
	if(lindev >= LinDevice::DEVICE_CNT)
		return false;

	if(lindev != m_lindev) {
		switch(lindev)
		{
		case LinDevice::DEVICE_1:
			m_multiplexer.setChannel(MultiplexerChannel::CHANNEL_0);
			m_transceiver.set(LinTransceiver::TRANSCEIVER_1);
			break;
		case LinDevice::DEVICE_2:
			m_multiplexer.setChannel(MultiplexerChannel::CHANNEL_1);
			m_transceiver.set(LinTransceiver::TRANSCEIVER_2);
			break;
		case LinDevice::DEVICE_3:
			m_multiplexer.setChannel(MultiplexerChannel::CHANNEL_2);
			m_transceiver.set(LinTransceiver::TRANSCEIVER_3);
			break;
		case LinDevice::DEVICE_4:
			m_multiplexer.setChannel(MultiplexerChannel::CHANNEL_3);
			m_transceiver.set(LinTransceiver::TRANSCEIVER_4);
			break;
		case LinDevice::DEVICE_OFF:
		default: return false;
		}

		m_lindev = lindev;

		HAL_Delay(50);
	}

	return m_lin.write(data);
}

}
