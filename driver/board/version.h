/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface.h"

using namespace siguni::interface;

namespace mainunit::driver
{

	class CUnitInputGetHwBoardVersion : public siguni::interface::IUnitInputGetHwBoardVersion
   {
	  public:
       CUnitInputGetHwBoardVersion() = default;
		 ~CUnitInputGetHwBoardVersion() = default;

		 void Get( std::string & attGetInput, CAdditionals & attAdditionals ) override final;
   };

	class CUnitInputGetDriverVersion : public siguni::interface::IUnitInputGetDriverVersion
   {
	  public:
       CUnitInputGetDriverVersion() = default;
		 ~CUnitInputGetDriverVersion() = default;

		 void Get( std::string & attGetInput, CAdditionals & attAdditionals ) override final;
   };
}

