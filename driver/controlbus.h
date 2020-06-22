/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface.h"

namespace mainunit::driver
{
	class CControlbus : public IControlbus
	{
	  public:
       CControlbus(); 
		 ~CControlbus() = default;

		 int WriteData( const std::string & attMessage ) override final;
		 int ReadData( std::string & attMessage ) override final;

     private:

	};
}

