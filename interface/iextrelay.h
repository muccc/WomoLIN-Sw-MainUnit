/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/iunit.h"

namespace mainunit::driver
{

   // outputs

	class IUnitOutputSetResetExtRelay1 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay1() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay2 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay2() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay3 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay3() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay4 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay4() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay5 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay5() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay6 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay6() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay7 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay7() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitOutputSetResetExtRelay8 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IUnitOutputSetResetExtRelay8() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};


   // inputs

	class IUnitInputGetExtRelay1 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay1() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay2 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay2() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay3 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay3() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay4 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay4() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay5 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay5() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay6 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay6() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay7 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay7() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetExtRelay8 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetExtRelay8() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};


}

