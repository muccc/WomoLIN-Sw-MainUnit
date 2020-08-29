/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "bme680drv.h"

using namespace siguni::interface;

namespace mainunit::driver
{

   class CUnitInputGetBme680Pressure : public IUnitInputGetBme680Pressure
	{
	public:
      CUnitInputGetBme680Pressure(const CBme680Drv &bme680);
      ~CUnitInputGetBme680Pressure() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CBme680Drv &m_bme680;
	};

   class CUnitInputGetBme680Temperature : public IUnitInputGetBme680Temperature
	{
	public:
      CUnitInputGetBme680Temperature(const CBme680Drv &bme680);
      ~CUnitInputGetBme680Temperature() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
	      CBme680Drv &m_bme680;
	};

   class CUnitInputGetBme680Humidity : public IUnitInputGetBme680Humidity
	{
	public:
      CUnitInputGetBme680Humidity(const CBme680Drv &bme680);
      ~CUnitInputGetBme680Humidity() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
	      CBme680Drv &m_bme680;
	};

}

