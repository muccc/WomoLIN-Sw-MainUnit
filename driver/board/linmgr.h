/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LINMGR_HPP_
#define INC_LINMGR_HPP_

#include "lin.h"
#include "linmultiplexer.h"
#include "lintransceiver.h"

namespace mainunit::driver
{

enum class LinDevice
{
	DEVICE_OFF = -1,
	DEVICE_1 = 0,
	DEVICE_2 = 1,
	DEVICE_3 = 2,
	DEVICE_4 = 3,
	DEVICE_CNT = 4
};

class CLinManager
{
public:
	CLinManager(const CLinMultiplexer &multiplexer, const CLinTransceiver &transceiver, const CLin &lin);
	virtual ~CLinManager();

	void setOn(bool state);

	bool read(std::vector<uint8_t> &data);
	bool write(LinDevice lindev, const std::vector<uint8_t> &data);

private:
	CLinMultiplexer &m_multiplexer;
	CLinTransceiver &m_transceiver;
	CLin &m_lin;
	LinDevice m_lindev;
};

}

#endif /* INC_LINMGR_HPP_ */
