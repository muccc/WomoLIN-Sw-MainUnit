/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/iunit.h"

namespace mainunit::driver
{

   class IUnitInputGetIbsTemperature : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetIbsTemperature() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

   class IUnitInputGetIbsVoltage : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetIbsVoltage() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

   class IUnitInputGetIbsCurrent : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetIbsCurrent() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

   class IUnitInputGetIbsCapacity : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetIbsCapacity() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

   class IUnitInputGetIbsCharge : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetIbsCharge() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };

   class IUnitInputGetIbsHealth : public siguni::interface::IUnitInput
   {
     public:
       virtual ~IUnitInputGetIbsHealth() = default;

       void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override = 0;
   };
}
