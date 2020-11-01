/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
// TODO #include "relaydrv.h"
// TODO #include "gpio.h"

using namespace siguni::interface;

namespace mainunit::driver
{

    class CUnitOutputSetResetHss1 : public IUnitOutputSetResetHss1
	{
	public:
       CUnitOutputSetResetHss1(/* TODO const RelayDrv &relay*/);
       ~CUnitOutputSetResetHss1() = default;

       void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
       // TODO RelayDrv &m_relay;
	};

    class CUnitOutputSetResetHss2 : public IUnitOutputSetResetHss2
	{
	public:
        CUnitOutputSetResetHss2(/* TODO const RelayDrv &relay*/);
        ~CUnitOutputSetResetHss2() = default;

		void Set( std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	       // TODO RelayDrv &m_relay;
	};

    class CUnitOutputSetResetHss3 : public IUnitOutputSetResetHss3
	{
	public:
       CUnitOutputSetResetHss3(/* TODO const RelayDrv &relay*/);
       ~CUnitOutputSetResetHss3() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   // TODO RelayDrv &m_relay;
	};

    class CUnitOutputSetResetHss4 : public IUnitOutputSetResetHss4
	{
	public:
       CUnitOutputSetResetHss4(/* TODO const RelayDrv &relay*/);
       ~CUnitOutputSetResetHss4() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   // TODO RelayDrv &m_relay;
	};

    class CUnitInputGetHss1 : public IUnitInputGetHss1
	{
	public:
        CUnitInputGetHss1(/* TODO const GPIO &status*/);
        ~CUnitInputGetHss1() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
        /* TODO GPIO &m_status; */
	};

    class CUnitInputGetHss2 : public IUnitInputGetHss2
	{
	public:
        CUnitInputGetHss2(/* TODO const GPIO &status*/);
        ~CUnitInputGetHss2() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
        /* TODO GPIO &m_status;*/
	};

    class CUnitInputGetHss3 : public IUnitInputGetHss3
	{
	public:
        CUnitInputGetHss3(/* TODO const GPIO &status*/);
        ~CUnitInputGetHss3() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
        /* TODO GPIO &m_status;*/
	};

    class CUnitInputGetHss4 : public IUnitInputGetHss4
	{
	public:
        CUnitInputGetHss4(/* TODO const GPIO &status*/);
        ~CUnitInputGetHss4() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
        /* TODO GPIO &m_status;*/
	};
}

