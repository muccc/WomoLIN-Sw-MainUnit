/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "lsm303.h"


namespace mainunit::driver
{

   CUnitInputGetLsm303Magnetic::CUnitInputGetLsm303Magnetic(const CLSM303AgrMagDrv &mag) : m_mag(const_cast<CLSM303AgrMagDrv&>(mag)) {}

   void CUnitInputGetLsm303Magnetic::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

   CUnitInputGetLsm303Acceleration::CUnitInputGetLsm303Acceleration(const CLSM303AgrAccDrv &acc) : m_acc(const_cast<CLSM303AgrAccDrv&>(acc)) {}

   void CUnitInputGetLsm303Acceleration::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

}

