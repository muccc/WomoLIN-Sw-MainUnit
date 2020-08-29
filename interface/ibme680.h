/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/iunit.h"

namespace mainunit::driver
{

	class IUnitInputGetBme680Pressure : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetBme680Pressure() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

    class IUnitInputGetBme680Temperature : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetBme680Temperature() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

	class IUnitInputGetBme680Humidity : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetBme680Humidity() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
	};

}

