/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface.h"

namespace mainunit::driver
{

	class CInputHwBoardVersion : public siguni::interface::IInputHwBoardVersion
   {
	  public:
       CInputHwBoardVersion() = default;
		 ~CInputHwBoardVersion() = default;

		 void Get( std::string & attGetInput ) override final;
   };

	class CInputDriverVersion : public siguni::interface::IInputDriverVersion
   {
	  public:
       CInputDriverVersion() = default;
		 ~CInputDriverVersion() = default;

		 void Get( std::string & attGetInput ) override final;
   };
}

