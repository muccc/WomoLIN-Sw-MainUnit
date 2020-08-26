/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "extrelay.h"

#include <iostream>

namespace mainunit::driver
{

	CUnitOutputSetResetExtRelay1::CUnitOutputSetResetExtRelay1(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay1::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT1;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}
 
	CUnitOutputSetResetExtRelay2::CUnitOutputSetResetExtRelay2(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay2::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT2;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitOutputSetResetExtRelay3::CUnitOutputSetResetExtRelay3(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay3::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT3;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitOutputSetResetExtRelay4::CUnitOutputSetResetExtRelay4(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay4::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT4;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitOutputSetResetExtRelay5::CUnitOutputSetResetExtRelay5(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay5::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT5;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitOutputSetResetExtRelay6::CUnitOutputSetResetExtRelay6(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay6::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT6;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitOutputSetResetExtRelay7::CUnitOutputSetResetExtRelay7(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay7::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT7;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitOutputSetResetExtRelay8::CUnitOutputSetResetExtRelay8(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitOutputSetResetExtRelay8::Set( std::string &attSetOutput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		OutputNr chn = OutputNr::OUTPUT8;

		if(attSetOutput == "SET") {
			m_relay.set(chn);
		} else {
			m_relay.reset(chn);
		}
	}

	CUnitInputGetExtRelay1::CUnitInputGetExtRelay1(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay1::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT1))
			attGetInput = "SET";
	}

   CUnitInputGetExtRelay2::CUnitInputGetExtRelay2(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay2::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT2))
			attGetInput = "SET";
	}

	CUnitInputGetExtRelay3::CUnitInputGetExtRelay3(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay3::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT3))
			attGetInput = "SET";
	}

	CUnitInputGetExtRelay4::CUnitInputGetExtRelay4(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay4::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT4))
			attGetInput = "SET";
	}

	CUnitInputGetExtRelay5::CUnitInputGetExtRelay5(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay5::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT5))
			attGetInput = "SET";
	}

	CUnitInputGetExtRelay6::CUnitInputGetExtRelay6(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay6::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT6))
			attGetInput = "SET";
	}

	CUnitInputGetExtRelay7::CUnitInputGetExtRelay7(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay7::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT7))
			attGetInput = "SET";
	}

	CUnitInputGetExtRelay8::CUnitInputGetExtRelay8(const RelayDrv &relay) : m_relay(const_cast<RelayDrv&>(relay)) {}

	void CUnitInputGetExtRelay8::Get( std::string & attGetInput, siguni::interface::CAdditionals & /*attAdditionals*/ )
	{
		attGetInput = "RESET";
		if(m_relay.isSet(OutputNr::OUTPUT8))
			attGetInput = "SET";
	}

}

