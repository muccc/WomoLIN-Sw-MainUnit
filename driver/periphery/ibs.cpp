/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "ibs.h"


namespace mainunit::driver
{

   CUnitInputGetIbsTemperature::CUnitInputGetIbsTemperature(const CHellaIBS2 &ibs) : m_ibs(const_cast<CHellaIBS2&>(ibs)) {}

   void CUnitInputGetIbsTemperature::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
	{
	   m_ibs.readSensor();
	   int itemp = static_cast<int>(m_ibs.getTemp() * 100.0);

	   attGetInput = std::to_string(itemp / 100) + "." + std::to_string(itemp % 100);
	}

   CUnitInputGetIbsVoltage::CUnitInputGetIbsVoltage(const CHellaIBS2 &ibs) : m_ibs(const_cast<CHellaIBS2&>(ibs)) {}

   void CUnitInputGetIbsVoltage::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
	{
	   m_ibs.readSensor();
	   int iubat = static_cast<int>(m_ibs.getU() * 100.0);

	   attGetInput = std::to_string(iubat / 100) + "." + std::to_string(iubat % 100);
	}

   CUnitInputGetIbsCurrent::CUnitInputGetIbsCurrent(const CHellaIBS2 &ibs) : m_ibs(const_cast<CHellaIBS2&>(ibs)) {}

   void CUnitInputGetIbsCurrent::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
	{
	   m_ibs.readSensor();
	   int iibat = static_cast<int>(m_ibs.getI() * 100.0);

	   attGetInput = std::to_string(iibat / 100) + "." + std::to_string(iibat % 100);
	}

   CUnitInputGetIbsCapacity::CUnitInputGetIbsCapacity(const CHellaIBS2 &ibs) : m_ibs(const_cast<CHellaIBS2&>(ibs)) {}

   void CUnitInputGetIbsCapacity::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
	{
	   attGetInput = "TODO";
	}

   CUnitInputGetIbsCharge::CUnitInputGetIbsCharge(const CHellaIBS2 &ibs) : m_ibs(const_cast<CHellaIBS2&>(ibs)) {}

   void CUnitInputGetIbsCharge::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
	{
      attGetInput = "TODO";
	}

   CUnitInputGetIbsHealth::CUnitInputGetIbsHealth(const CHellaIBS2 &ibs) : m_ibs(const_cast<CHellaIBS2&>(ibs)) {}

   void CUnitInputGetIbsHealth::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
	{
      attGetInput = "TODO";
	}
}

