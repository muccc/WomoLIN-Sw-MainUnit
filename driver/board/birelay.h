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

	class CUnitOutputSetResetK1 : public IUnitOutputSetResetK1 
	{
	public:
       CUnitOutputSetResetK1(const RelayDrv &relay);
       ~CUnitOutputSetResetK1() = default;

       void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
       RelayDrv &m_relay;
	};

	class CUnitOutputSetResetK2 : public IUnitOutputSetResetK2 
	{
	public:
		CUnitOutputSetResetK2(const RelayDrv &relay);
		~CUnitOutputSetResetK2() = default;

		void Set( std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	       RelayDrv &m_relay;
	};

	class CUnitOutputSetResetK3 : public IUnitOutputSetResetK3
	{
	public:
	   CUnitOutputSetResetK3(const RelayDrv &relay);
	   ~CUnitOutputSetResetK3() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   RelayDrv &m_relay;
	};

	class CUnitOutputSetResetK4 : public IUnitOutputSetResetK4
	{
	public:
	   CUnitOutputSetResetK4(const RelayDrv &relay);
	   ~CUnitOutputSetResetK4() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   RelayDrv &m_relay;
	};

	class CUnitInputGetK1 : public IUnitInputGetK1 
	{
	public:
		CUnitInputGetK1(const GPIO &status);
		~CUnitInputGetK1() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		GPIO &m_status;
	};

	class CUnitInputGetK2 : public IUnitInputGetK2 
	{
	public:
		CUnitInputGetK2(const GPIO &status);
		~CUnitInputGetK2() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
		GPIO &m_status;
	};

	class CUnitInputGetK3 : public IUnitInputGetK3
	{
	public:
		CUnitInputGetK3(const GPIO &status);
		~CUnitInputGetK3() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		GPIO &m_status;
	};

	class CUnitInputGetK4 : public IUnitInputGetK4
	{
	public:
		CUnitInputGetK4(const GPIO &status);
		~CUnitInputGetK4() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		GPIO &m_status;
	};
}

