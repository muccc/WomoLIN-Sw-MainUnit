/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "lin.h"

#define LIN_ISSET_BIT(byte, bit)		(byte & (1UL << (bit)))

namespace mainunit::driver
{

CLin::CLin(UART_HandleTypeDef *huart, CircularBuffer<uint8_t> *buffer) : m_phuart(huart), m_pbuffer(buffer), m_lastsendsize(0)
{

}

bool CLin::read(std::vector<uint8_t> &data)
{
	bool ret = false;

	if(!m_pbuffer->empty()) {
		size_t size = m_pbuffer->size();
		for(size_t i = 0; i < size; i++) {
			uint8_t byte = m_pbuffer->get();
			// Filter last send bytes.
			if(m_lastsendsize > 0) {
				m_lastsendsize--;
				continue;
			}
			data.push_back(byte);
		}
		 ret = true;
	}

	return ret;
}

bool CLin::write(const std::vector<uint8_t> &data)
{
	uint8_t sync = 0x55;

	HAL_LIN_SendBreak(m_phuart);
	HAL_UART_Transmit(m_phuart, &sync, 1, 100);
	HAL_UART_Transmit(m_phuart, (uint8_t *) data.data(), data.size(), 100);
	m_lastsendsize = data.size() + 2;

	return true;
}

void CLin::test()
{
	//static unsigned char i = 0;
	unsigned char data[2];
	uint8_t mID = 0x28; //0xe7
	uint8_t linID = ((mID & 0x3F) | addParity(mID));
	data[0] = 0x55;
	//data[1] = i++;
	data[1] = linID;

	// Lin Break
	HAL_LIN_SendBreak(m_phuart);
	HAL_UART_Transmit(m_phuart, (uint8_t *)data, 2, 100);
}

uint8_t CLin::addParity(uint8_t linID)
{
  uint8_t p0 = LIN_ISSET_BIT(linID, 0)^LIN_ISSET_BIT(linID, 1)^LIN_ISSET_BIT(linID, 2)^LIN_ISSET_BIT(linID, 4);
  uint8_t p1 = ~(LIN_ISSET_BIT(linID, 1)^LIN_ISSET_BIT(linID, 3)^LIN_ISSET_BIT(linID, 4)^LIN_ISSET_BIT(linID, 5));   // evtl. Klammer rum ???
  return ((p0 | (p1 << 1)) << 6);
}

}


