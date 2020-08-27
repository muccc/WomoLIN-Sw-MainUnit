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
		OutputNr setchn = OutputNr::OUTPUT1;
		OutputNr clrchn = OutputNr::OUTPUT2;

		if(attSetOutput == "SET") {
			setchn = OutputNr::OUTPUT2;
			clrchn = OutputNr::OUTPUT1;
		}

		m_relay.reset(clrchn, false);
		m_relay.set(setchn, false);
		m_relay.write();
	}
 
    CUnitOutputSetResetBirelayK2::CUnitOutputSetResetBirelayK2(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK2::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr setchn = OutputNr::OUTPUT3;
		OutputNr clrchn = OutputNr::OUTPUT4;

		if(attSetOutput == "SET") {
			setchn = OutputNr::OUTPUT4;
			clrchn = OutputNr::OUTPUT3;
		}

		m_relay.reset(clrchn, false);
		m_relay.set(setchn, false);
		m_relay.write();
	}

    CUnitOutputSetResetBirelayK3::CUnitOutputSetResetBirelayK3(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK3::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr setchn = OutputNr::OUTPUT5;
		OutputNr clrchn = OutputNr::OUTPUT6;

		if(attSetOutput == "SET") {
			setchn = OutputNr::OUTPUT6;
			clrchn = OutputNr::OUTPUT5;
		}

		m_relay.reset(clrchn, false);
		m_relay.set(setchn, false);
		m_relay.write();
	}

    CUnitOutputSetResetBirelayK4::CUnitOutputSetResetBirelayK4(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

    void CUnitOutputSetResetBirelayK4::Set( std::string & attSetOutput, CAdditionals & /*attAdditionals*/ )
	{
		OutputNr setchn = OutputNr::OUTPUT7;
		OutputNr clrchn = OutputNr::OUTPUT8;

		if(attSetOutput == "SET") {
			setchn = OutputNr::OUTPUT8;
			clrchn = OutputNr::OUTPUT7;
		}

		m_relay.reset(clrchn, false);
		m_relay.set(setchn, false);
		m_relay.write();
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

