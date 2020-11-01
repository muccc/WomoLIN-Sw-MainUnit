/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */


#ifndef INC_HELLAIBS1_HPP_
#define INC_HELLAIBS1_HPP_

#include "hellaibs.h"
#include "linmgr.h"

namespace mainunit::driver
{

class CHellaIBS1 final : public CHellaIBS
{
public:
	CHellaIBS1(const CLinManager &manager);
	virtual ~CHellaIBS1();

	bool search(void);
	bool readSensor(void);

private:
	constexpr static uint8_t IDENTIFICATION_ID	{0x21};
	constexpr static uint8_t CURRENTVALUES_ID	{0x22};
	constexpr static uint8_t STATUSERROR_ID		{0x23};
	constexpr static uint8_t IBSFRAME4_ID		{0x24};
	constexpr static uint8_t IBSFRAME5_ID		{0x25};
	constexpr static uint8_t IBSFRAME6_ID		{0x26};
};

}

#endif /* INC_HELLAIBS1_HPP_ */
