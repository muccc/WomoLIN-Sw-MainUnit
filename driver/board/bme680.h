/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"

using namespace siguni::interface;

namespace mainunit::driver
{

   class CUnitInputGetBme680Pressure : public IUnitInputGetBme680Pressure
	{
	public:
      CUnitInputGetBme680Pressure();
      ~CUnitInputGetBme680Pressure() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	};

   class CUnitInputGetBme680Temperature : public IUnitInputGetBme680Temperature
	{
	public:
      CUnitInputGetBme680Temperature();
      ~CUnitInputGetBme680Temperature() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	};

   class CUnitInputGetBme680Humidity : public IUnitInputGetBme680Humidity
	{
	public:
      CUnitInputGetBme680Humidity();
      ~CUnitInputGetBme680Humidity() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;
	};

}

