/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "hssdrv.h"

using namespace siguni::interface;

namespace mainunit::driver
{

    class CUnitOutputSetResetHss1 : public IUnitOutputSetResetHss1
	{
	public:
       CUnitOutputSetResetHss1(const CHSSDrv &hss);
       ~CUnitOutputSetResetHss1() = default;

       void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
       CHSSDrv &m_hss;
	};

    class CUnitOutputSetResetHss2 : public IUnitOutputSetResetHss2
	{
	public:
        CUnitOutputSetResetHss2(const CHSSDrv &hss);
        ~CUnitOutputSetResetHss2() = default;

		void Set( std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
		CHSSDrv &m_hss;
	};

    class CUnitOutputSetResetHss3 : public IUnitOutputSetResetHss3
	{
	public:
       CUnitOutputSetResetHss3(const CHSSDrv &hss);
       ~CUnitOutputSetResetHss3() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   CHSSDrv &m_hss;
	};

    class CUnitOutputSetResetHss4 : public IUnitOutputSetResetHss4
	{
	public:
       CUnitOutputSetResetHss4(const CHSSDrv &hss);
       ~CUnitOutputSetResetHss4() = default;

	   void Set(std::string & attSetOutput, CAdditionals & attAdditionals ) override final;

	private:
	   CHSSDrv &m_hss;
	};

    class CUnitInputGetHss1 : public IUnitInputGetHss1
	{
	public:
        CUnitInputGetHss1(const CHSSDrv &hss);
        ~CUnitInputGetHss1() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		CHSSDrv &m_hss;
	};

    class CUnitInputGetHss2 : public IUnitInputGetHss2
	{
	public:
        CUnitInputGetHss2(const CHSSDrv &hss);
        ~CUnitInputGetHss2() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
		CHSSDrv &m_hss;
	};

    class CUnitInputGetHss3 : public IUnitInputGetHss3
	{
	public:
        CUnitInputGetHss3(const CHSSDrv &hss);
        ~CUnitInputGetHss3() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		CHSSDrv &m_hss;
	};

    class CUnitInputGetHss4 : public IUnitInputGetHss4
	{
	public:
        CUnitInputGetHss4(const CHSSDrv &hss);
        ~CUnitInputGetHss4() = default;

		void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	private:
		CHSSDrv &m_hss;
	};
}

