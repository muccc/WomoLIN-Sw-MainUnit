/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/iunit.h"

namespace mainunit::driver
{

   class IUnitInputGetLsm303Magnetic : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetLsm303Magnetic() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

   class IUnitInputGetLsm303Acceleration : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetLsm303Acceleration() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

}

