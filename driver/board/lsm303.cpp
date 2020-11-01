/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "lsm303.h"


namespace mainunit::driver
{

   CUnitInputGetLsm303Magnetic::CUnitInputGetLsm303Magnetic() {}

   void CUnitInputGetLsm303Magnetic::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

   CUnitInputGetLsm303Acceleration::CUnitInputGetLsm303Acceleration() {}

   void CUnitInputGetLsm303Acceleration::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

}

