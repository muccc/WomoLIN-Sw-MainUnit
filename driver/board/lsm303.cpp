/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "lsm303.h"


namespace mainunit::driver
{

   CUnitInputGetLsm303Magnetic::CUnitInputGetLsm303Magnetic(const CLSM303AgrMagDrv &mag) : m_mag(const_cast<CLSM303AgrMagDrv&>(mag)) {}

   void CUnitInputGetLsm303Magnetic::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   m_mag.read();

	   attGetInput = "xraw:" + std::to_string(m_mag.getXRaw()) + ";";
	   attGetInput += "yraw:" + std::to_string(m_mag.getYRaw()) + ";";
	   attGetInput += "zraw:" + std::to_string(m_mag.getZRaw()) + ";";

	   attGetInput += "x:" + std::to_string(m_mag.getX()) + ";";
	   attGetInput += "y:" + std::to_string(m_mag.getY()) + ";";
	   attGetInput += "z:" + std::to_string(m_mag.getZ()) + ";";

	   attGetInput += "deg:" + m_mag.getDegree() + ";";
   }

   CUnitInputGetLsm303Acceleration::CUnitInputGetLsm303Acceleration(const CLSM303AgrAccDrv &acc) : m_acc(const_cast<CLSM303AgrAccDrv&>(acc)) {}

   void CUnitInputGetLsm303Acceleration::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

}

