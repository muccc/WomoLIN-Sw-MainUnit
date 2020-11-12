/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "hellaibs2.h"

namespace mainunit::driver
{

CHellaIBS2::CHellaIBS2(const CLinManager &manager) : CHellaIBS(manager)
{
	m_lindevice = LinDevice::DEVICE_OFF;
}

CHellaIBS2::~CHellaIBS2()
{

}

bool CHellaIBS2::search(void)
{
	m_lindevice = LinDevice::DEVICE_1;

	getIdentification(IDENTIFICATION_ID);
	if(!getIdentification(IDENTIFICATION_ID))
		return false;

	return true;
}

bool CHellaIBS2::readSensor()
{
	if(!getIdentification(IDENTIFICATION_ID))
		return false;

	HAL_Delay(100);

	if(!getCurrentValues(CURRENTVALUES_ID))
		return false;

	HAL_Delay(100);

	if(!getStatusError(STATUSERROR_ID))
		return false;

	HAL_Delay(100);
/*
	if(!getIBSFrame4(IBSFRAME4_ID))
		return false;

	HAL_Delay(100);

	if(!getIBSFrame5(IBSFRAME5_ID))
		return false;

	HAL_Delay(100);

	if(!getIBSFrame6(IBSFRAME6_ID))
		return false;
*/
	return true;
}

}
