/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"

namespace mainunit::driver
{

	class CUnitOutputSetResetK1 : public IUnitOutputSetResetK1 
	{
	  public:
       CUnitOutputSetResetK1() = default;
		 ~CUnitOutputSetResetK1() = default;

		 void Set( std::string & attSetOutput ) override final;
	};

	class CUnitOutputSetResetK2 : public IUnitOutputSetResetK2 
	{
	  public:
       CUnitOutputSetResetK2() = default;
		 ~CUnitOutputSetResetK2() = default;

		 void Set( std::string & attSetOutput ) override final;
	};

	class CUnitInputGetK1 : public IUnitInputGetK1 
	{
	  public:
       CUnitInputGetK1() = default;
		 ~CUnitInputGetK1() = default;

		 void Get( std::string & attGetInput ) override final;
	};

	class CUnitInputGetK2 : public IUnitInputGetK2 
	{
	  public:
       CUnitInputGetK2() = default;
		 ~CUnitInputGetK2() = default;

		 void Get( std::string & attGetInput ) override final;
	};
}

