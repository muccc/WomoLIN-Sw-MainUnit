/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "relaydrv.h"
#include "gpio.h"

using namespace siguni::interface;

namespace mainunit::driver
{

    class CUnitOutputSetResetBirelayK1 : public IUnitOutputSetResetBirelayK1
	{
	public:
       CUnitOutputSetResetBirelayK1(const RelayDrv &relay);
       ~CUnitOutputSetResetBirelayK1() = default;

       void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
       RelayDrv &m_relay;
	};

    class CUnitOutputSetResetBirelayK2 : public IUnitOutputSetResetBirelayK2
	{
	public:
        CUnitOutputSetResetBirelayK2(const RelayDrv &relay);
        ~CUnitOutputSetResetBirelayK2() = default;

		void Set( std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	       RelayDrv &m_relay;
	};

    class CUnitOutputSetResetBirelayK3 : public IUnitOutputSetResetBirelayK3
	{
	public:
       CUnitOutputSetResetBirelayK3(const RelayDrv &relay);
       ~CUnitOutputSetResetBirelayK3() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   RelayDrv &m_relay;
	};

    class CUnitOutputSetResetBirelayK4 : public IUnitOutputSetResetBirelayK4
	{
	public:
       CUnitOutputSetResetBirelayK4(const RelayDrv &relay);
       ~CUnitOutputSetResetBirelayK4() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   RelayDrv &m_relay;
	};

    class CUnitInputGetBirelayK1 : public IUnitInputGetBirelayK1
	{
	public:
        CUnitInputGetBirelayK1(const GPIO &status);
        ~CUnitInputGetBirelayK1() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		GPIO &m_status;
	};

    class CUnitInputGetBirelayK2 : public IUnitInputGetBirelayK2
	{
	public:
        CUnitInputGetBirelayK2(const GPIO &status);
        ~CUnitInputGetBirelayK2() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
		GPIO &m_status;
	};

    class CUnitInputGetBirelayK3 : public IUnitInputGetBirelayK3
	{
	public:
        CUnitInputGetBirelayK3(const GPIO &status);
        ~CUnitInputGetBirelayK3() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		GPIO &m_status;
	};

    class CUnitInputGetBirelayK4 : public IUnitInputGetBirelayK4
	{
	public:
        CUnitInputGetBirelayK4(const GPIO &status);
        ~CUnitInputGetBirelayK4() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		GPIO &m_status;
	};
}

