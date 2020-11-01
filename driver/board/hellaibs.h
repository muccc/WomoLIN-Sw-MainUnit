/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_HELLAIBS_HPP_
#define INC_HELLAIBS_HPP_

#include "linmgr.h"

namespace mainunit::driver
{

class CHellaIBS
{
public:
	CHellaIBS(const CLinManager &manager);
	virtual ~CHellaIBS();

	virtual bool search(void) = 0;
	virtual bool readSensor(void) = 0;

	const int getSoc() { return m_soc; }
	const int getSoh() { return m_soh; }
	const float getU() { return m_Ubatt; }
	const float getI() { return m_Ibatt; }
	const float getTemp() { return m_Btemp; }
	const float getAvCap() { return m_AvCap; }

protected:
	bool transfer(const std::vector<uint8_t> &writebuf, std::vector<uint8_t> &readbuf);
	uint8_t addParity(uint8_t linID);

	bool getIdentification(uint8_t linID);
	bool getCurrentValues(uint8_t linID);
	bool getStatusError(uint8_t linID);
	bool getIBSFrame4(uint8_t linID);
	bool getIBSFrame5(uint8_t linID);
	bool getIBSFrame6(uint8_t linID);

protected:
	CLinManager &m_manager;
	LinDevice m_lindevice;

private:
	int m_soc;
	int m_soh;
	float m_Ubatt;
	float m_Ibatt;
	float m_Btemp;
	float m_AvCap;
};

}

#endif /* INC_HELLAIBS_HPP_ */
