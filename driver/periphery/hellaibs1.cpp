/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "hellaibs1.h"

namespace mainunit::driver
{

CHellaIBS1::CHellaIBS1(const CLinManager &manager) : CHellaIBS(manager)
{
	m_lindevice = LinDevice::DEVICE_OFF;
}

CHellaIBS1::~CHellaIBS1()
{

}

bool CHellaIBS1::search(void)
{
	m_lindevice = LinDevice::DEVICE_1;

	getIdentification(0);
	if(!getIdentification(0))
		return false;

	return true;
}

bool CHellaIBS1::readSensor()
{
	if(!getIdentification(0))
		return false;

	HAL_Delay(100);

	if(!getCurrentValues(0))
		return false;

	HAL_Delay(100);

	if(!getStatusError(0))
		return false;

	HAL_Delay(100);
/*
	if(!getIBSFrame4(0))
		return false;

	HAL_Delay(100);

	if(!getIBSFrame5(0))
		return false;

	HAL_Delay(100);

	if(!getIBSFrame6(0))
		return false;
*/
	return true;
}

}
