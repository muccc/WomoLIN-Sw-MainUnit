/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "bme680.h"


namespace mainunit::driver
{
   CUnitInputGetBme680Pressure::CUnitInputGetBme680Pressure() {}

   void CUnitInputGetBme680Pressure::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
      attGetInput = "UNKNOWN";
	}

   CUnitInputGetBme680Temperature::CUnitInputGetBme680Temperature() {}

   void CUnitInputGetBme680Temperature::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
      attGetInput = "UNKNOWN";
	}

   CUnitInputGetBme680Humidity::CUnitInputGetBme680Humidity() {}

   void CUnitInputGetBme680Humidity::Get( std::string & attGetInput , CAdditionals & /*attAdditionals*/ )
	{
      attGetInput = "UNKNOWN";
	}


}

