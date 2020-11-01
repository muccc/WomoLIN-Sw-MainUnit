/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/iunit.h"

namespace mainunit::driver
{

   // outputs

    class IUnitOutputSetResetHss1 : public siguni::interface::IUnitOutput
	{
	  public:
         virtual ~IUnitOutputSetResetHss1() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

    class IUnitOutputSetResetHss2 : public siguni::interface::IUnitOutput
	{
	  public:
         virtual ~IUnitOutputSetResetHss2() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

    class IUnitOutputSetResetHss3 : public siguni::interface::IUnitOutput
	{
	  public:
         virtual ~IUnitOutputSetResetHss3() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

    class IUnitOutputSetResetHss4 : public siguni::interface::IUnitOutput
	{
	  public:
         virtual ~IUnitOutputSetResetHss4() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override = 0;
	};


   // inputs

	class IUnitInputGetHss1 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetHss1() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetHss2 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetHss2() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetHss3 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetHss3() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetHss4 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetHss4() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};



}

