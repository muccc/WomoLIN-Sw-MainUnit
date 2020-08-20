/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "birelay.h"

#include <iostream>

namespace mainunit::driver
{
	CUnitOutputSetResetK1::CUnitOutputSetResetK1(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetK1::Set( std::string & attSetOutput, CAdditionals & attAdditionals )
	{
		OutputNr chn = OutputNr::OUTPUT1;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT2;
		}

		m_relay.set(chn);
	}
 
	CUnitOutputSetResetK2::CUnitOutputSetResetK2(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetK2::Set( std::string & attSetOutput, CAdditionals & attAdditionals )
	{
		OutputNr chn = OutputNr::OUTPUT3;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT4;
		}

		m_relay.set(chn);
	}

	CUnitOutputSetResetK3::CUnitOutputSetResetK3(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetK3::Set( std::string & attSetOutput, CAdditionals & attAdditionals )
	{
		OutputNr chn = OutputNr::OUTPUT5;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT6;
		}

		m_relay.set(chn);
	}

	CUnitOutputSetResetK4::CUnitOutputSetResetK4(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetK4::Set( std::string & attSetOutput, CAdditionals & attAdditionals )
	{
		OutputNr chn = OutputNr::OUTPUT7;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT8;
		}

		m_relay.set(chn);
	}

	CUnitInputGetK1::CUnitInputGetK1(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

	void CUnitInputGetK1::Get( std::string & attGetInput , CAdditionals & attAdditionals )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}

	CUnitInputGetK2::CUnitInputGetK2(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

	void CUnitInputGetK2::Get( std::string & attGetInput , CAdditionals & attAdditionals )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}

	CUnitInputGetK3::CUnitInputGetK3(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

	void CUnitInputGetK3::Get( std::string & attGetInput , CAdditionals & attAdditionals )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}

	CUnitInputGetK4::CUnitInputGetK4(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

	void CUnitInputGetK4::Get( std::string & attGetInput , CAdditionals & attAdditionals )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}
}

