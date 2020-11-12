/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "hellaibs2.h"

using namespace siguni::interface;

namespace mainunit::driver
{

	class CUnitInputGetIbsTemperature : public IUnitInputGetIbsTemperature
	{
	public:
      CUnitInputGetIbsTemperature(const CHellaIBS2 &ibs);
      ~CUnitInputGetIbsTemperature() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CHellaIBS2 &m_ibs;

	};

   class CUnitInputGetIbsVoltage : public IUnitInputGetIbsVoltage 
	{
	public:
      CUnitInputGetIbsVoltage(const CHellaIBS2 &ibs);
      ~CUnitInputGetIbsVoltage() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CHellaIBS2 &m_ibs;
	};

   class CUnitInputGetIbsCurrent : public IUnitInputGetIbsCurrent 
	{
	public:
      CUnitInputGetIbsCurrent(const CHellaIBS2 &ibs);
      ~CUnitInputGetIbsCurrent() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CHellaIBS2 &m_ibs;
	};

   class CUnitInputGetIbsCapacity : public IUnitInputGetIbsCapacity 
	{
	public:
      CUnitInputGetIbsCapacity(const CHellaIBS2 &ibs);
      ~CUnitInputGetIbsCapacity() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CHellaIBS2 &m_ibs;
	};

   class CUnitInputGetIbsCharge : public IUnitInputGetIbsCharge 
	{
	public:
      CUnitInputGetIbsCharge(const CHellaIBS2 &ibs);
      ~CUnitInputGetIbsCharge() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CHellaIBS2 &m_ibs;
	};

   class CUnitInputGetIbsHealth : public IUnitInputGetIbsHealth 
	{
	public:
      CUnitInputGetIbsHealth(const CHellaIBS2 &ibs);
      ~CUnitInputGetIbsHealth() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CHellaIBS2 &m_ibs;
	};
}

