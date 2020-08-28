/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "bme680.h"


namespace mainunit::driver
{
   CUnitInputGetBme680Pressure::CUnitInputGetBme680Pressure(const CBme680Drv &bme680) : m_bme680(const_cast<CBme680Drv&>(bme680)) {}

   void CUnitInputGetBme680Pressure::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
	   m_bme680.read();
      attGetInput = m_bme680.getPressure();
	}

   CUnitInputGetBme680Temperature::CUnitInputGetBme680Temperature(const CBme680Drv &bme680) : m_bme680(const_cast<CBme680Drv&>(bme680)) {}

   void CUnitInputGetBme680Temperature::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
	   m_bme680.read();
      attGetInput = m_bme680.getTemperature();
	}

   CUnitInputGetBme680Humidity::CUnitInputGetBme680Humidity(const CBme680Drv &bme680) : m_bme680(const_cast<CBme680Drv&>(bme680)) {}

   void CUnitInputGetBme680Humidity::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
	   m_bme680.read();
      attGetInput = m_bme680.getHumidity();
	}


}

