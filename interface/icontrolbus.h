/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/icontrolbus.h"

namespace pcsim::driver
{

	class IControlbus : public siguni::interface::IControlbus
	{
	  public:
		 virtual ~IControlbus() = default;

		 int WriteData( const std::string & attMessage ) override = 0;
		 int ReadData( std::string & attMessage ) override = 0;
	};
}

