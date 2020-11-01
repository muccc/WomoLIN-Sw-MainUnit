/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_LINTRANSCEIVER_HPP_
#define INC_LINTRANSCEIVER_HPP_

#include "gpio.h"

namespace mainunit::driver
{

enum class LinTransceiver
{
	TRANSCEIVER_OFF = -1,
	TRANSCEIVER_1 = 0,
	TRANSCEIVER_2 = 1,
	TRANSCEIVER_3 = 2,
	TRANSCEIVER_4 = 3,
	TRANSCEIVER_CNT = 4
};

class CLinTransceiver
{
public:
	CLinTransceiver(const GPIO &slplin1, const GPIO &slplin2, const GPIO &slplin3, const GPIO &slplin4);
	virtual ~CLinTransceiver();

	void set(LinTransceiver transceiver);

private:
	GPIO &m_slplin1;
	GPIO &m_slplin2;
	GPIO &m_slplin3;
	GPIO &m_slplin4;
};

}

#endif /* INC_LINTRANSCEIVER_HPP_ */
