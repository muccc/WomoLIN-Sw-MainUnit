/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"

using namespace siguni::interface;

namespace mainunit::driver
{

   class CUnitInputGetIbsTemperature : public IUnitInputGetIbsTemperature 
	{
	public:
      CUnitInputGetIbsTemperature();
      ~CUnitInputGetIbsTemperature() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

   class CUnitInputGetIbsVoltage : public IUnitInputGetIbsVoltage 
	{
	public:
      CUnitInputGetIbsVoltage();
      ~CUnitInputGetIbsVoltage() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

   class CUnitInputGetIbsCurrent : public IUnitInputGetIbsCurrent 
	{
	public:
      CUnitInputGetIbsCurrent();
      ~CUnitInputGetIbsCurrent() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

   class CUnitInputGetIbsCapacity : public IUnitInputGetIbsCapacity 
	{
	public:
      CUnitInputGetIbsCapacity();
      ~CUnitInputGetIbsCapacity() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

   class CUnitInputGetIbsCharge : public IUnitInputGetIbsCharge 
	{
	public:
      CUnitInputGetIbsCharge();
      ~CUnitInputGetIbsCharge() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

   class CUnitInputGetIbsHealth : public IUnitInputGetIbsHealth 
	{
	public:
      CUnitInputGetIbsHealth();
      ~CUnitInputGetIbsHealth() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};
}

