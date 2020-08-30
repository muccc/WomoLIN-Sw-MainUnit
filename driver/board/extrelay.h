/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "relaydrv.h"

namespace mainunit::driver
{

	class CUnitOutputSetResetExtRelay1 : public IUnitOutputSetResetExtRelay1 
	{
	  public:
       CUnitOutputSetResetExtRelay1(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay1() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay2 : public IUnitOutputSetResetExtRelay2 
	{
	  public:
       CUnitOutputSetResetExtRelay2(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay2() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay3 : public IUnitOutputSetResetExtRelay3 
	{
	  public:
       CUnitOutputSetResetExtRelay3(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay3() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay4 : public IUnitOutputSetResetExtRelay4 
	{
	  public:
       CUnitOutputSetResetExtRelay4(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay4() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay5 : public IUnitOutputSetResetExtRelay5 
	{
	  public:
       CUnitOutputSetResetExtRelay5(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay5() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay6 : public IUnitOutputSetResetExtRelay6 
	{
	  public:
       CUnitOutputSetResetExtRelay6(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay6() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay7 : public IUnitOutputSetResetExtRelay7 
	{
	  public:
       CUnitOutputSetResetExtRelay7(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay7() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};

	class CUnitOutputSetResetExtRelay8 : public IUnitOutputSetResetExtRelay8 
	{
	  public:
       CUnitOutputSetResetExtRelay8(const RelayDrv &relay);
		 ~CUnitOutputSetResetExtRelay8() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	         RelayDrv &m_relay;
	};




	class CUnitInputGetExtRelay1 : public IUnitInputGetExtRelay1 
	{
	  public:
       CUnitInputGetExtRelay1(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay1() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay2 : public IUnitInputGetExtRelay2 
	{
	  public:
       CUnitInputGetExtRelay2(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay2() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay3 : public IUnitInputGetExtRelay3 
	{
	  public:
       CUnitInputGetExtRelay3(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay3() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay4 : public IUnitInputGetExtRelay4 
	{
	  public:
       CUnitInputGetExtRelay4(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay4() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay5 : public IUnitInputGetExtRelay5 
	{
	  public:
       CUnitInputGetExtRelay5(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay5() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay6 : public IUnitInputGetExtRelay6 
	{
	  public:
       CUnitInputGetExtRelay6(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay6() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay7 : public IUnitInputGetExtRelay7 
	{
	  public:
       CUnitInputGetExtRelay7(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay7() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

	class CUnitInputGetExtRelay8 : public IUnitInputGetExtRelay8 
	{
	  public:
       CUnitInputGetExtRelay8(const RelayDrv &relay);
		 ~CUnitInputGetExtRelay8() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	  private:
	  	         RelayDrv &m_relay;
	};

}

