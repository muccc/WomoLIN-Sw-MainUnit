/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "birelay.h"

#include <iostream>

namespace mainunit::driver
{
    CUnitOutputSetResetBirelayK1::CUnitOutputSetResetBirelayK1(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK1::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT1;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT2;
		}

		m_relay.set(chn);
	}
 
    CUnitOutputSetResetBirelayK2::CUnitOutputSetResetBirelayK2(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK2::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT3;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT4;
		}

		m_relay.set(chn);
	}

    CUnitOutputSetResetBirelayK3::CUnitOutputSetResetBirelayK3(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK3::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT5;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT6;
		}

		m_relay.set(chn);
	}

    CUnitOutputSetResetBirelayK4::CUnitOutputSetResetBirelayK4(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK4::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT7;

		if(attSetOutput == "SET") {
			chn = OutputNr::OUTPUT8;
		}

		m_relay.set(chn);
	}

    CUnitInputGetBirelayK1::CUnitInputGetBirelayK1(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

    void CUnitInputGetBirelayK1::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}

    CUnitInputGetBirelayK2::CUnitInputGetBirelayK2(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

    void CUnitInputGetBirelayK2::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}

    CUnitInputGetBirelayK3::CUnitInputGetBirelayK3(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

    void CUnitInputGetBirelayK3::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}

    CUnitInputGetBirelayK4::CUnitInputGetBirelayK4(const GPIO &status) : m_status(const_cast<GPIO&>(status)) {}

    void CUnitInputGetBirelayK4::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
		bool status = !m_status.getState();

		attGetInput = "SET";
		if(!status)
			attGetInput = "RESET";
	}
}

