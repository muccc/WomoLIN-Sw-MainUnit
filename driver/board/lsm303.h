/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"

using namespace siguni::interface;

namespace mainunit::driver
{

   class CUnitInputGetLsm303Magnetic : public IUnitInputGetLsm303Magnetic 
	{
	public:
      CUnitInputGetLsm303Magnetic();
      ~CUnitInputGetLsm303Magnetic() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

   class CUnitInputGetLsm303Acceleration : public IUnitInputGetLsm303Acceleration 
	{
	public:
      CUnitInputGetLsm303Acceleration();
      ~CUnitInputGetLsm303Acceleration() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:

	};

}

