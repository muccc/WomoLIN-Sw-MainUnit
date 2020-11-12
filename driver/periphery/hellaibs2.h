/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_HELLAIBS2_HPP_
#define INC_HELLAIBS2_HPP_

#include "hellaibs.h"
#include "../board/linmgr.h"

namespace mainunit::driver
{

class CHellaIBS2 final : public CHellaIBS
{
public:
	CHellaIBS2(const CLinManager &manager);
	virtual ~CHellaIBS2();

	bool search(void);
	bool readSensor(void);

private:
	constexpr static uint8_t IDENTIFICATION_ID	{0x27};
	constexpr static uint8_t CURRENTVALUES_ID	{0x28};
	constexpr static uint8_t STATUSERROR_ID		{0x29};
	constexpr static uint8_t IBSFRAME4_ID		{0x2A};
	constexpr static uint8_t IBSFRAME5_ID		{0x2B};
	constexpr static uint8_t IBSFRAME6_ID		{0x2C};
};

}

#endif /* INC_HELLAIBS2_HPP_ */
