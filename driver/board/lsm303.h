/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "lsm303agrmag.h"
#include "lsm303agracc.h"

using namespace siguni::interface;

namespace mainunit::driver
{

   class CUnitInputGetLsm303Magnetic : public IUnitInputGetLsm303Magnetic 
	{
	public:
      CUnitInputGetLsm303Magnetic(const CLSM303AgrMagDrv &mag);
      ~CUnitInputGetLsm303Magnetic() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CLSM303AgrMagDrv &m_mag;

	};

   class CUnitInputGetLsm303Acceleration : public IUnitInputGetLsm303Acceleration 
	{
	public:
      CUnitInputGetLsm303Acceleration(const CLSM303AgrAccDrv &acc);
      ~CUnitInputGetLsm303Acceleration() = default;

      void Get( std::string & attGetInput , CAdditionals & attAdditionals ) override final;

	private:
      CLSM303AgrAccDrv &m_acc;

	};

}

