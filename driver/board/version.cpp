/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "version.h"

#include <iostream>

namespace mainunit::driver
{

	void CUnitInputGetHwBoardVersion::Get( std::string & attGetInput, CAdditionals & attAdditionals )
	{
      attGetInput = "9.99";
      std::cout << "Hw Board Version Input :" << attGetInput << std::endl;
	}

	void CUnitInputGetDriverVersion::Get( std::string & attGetInput, CAdditionals & attAdditionals )
	{
      attGetInput = "9.99";
      std::cout << "Driver Version Input :" << attGetInput << std::endl;
	}

}

