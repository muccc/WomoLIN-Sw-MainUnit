/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/iunit.h"

namespace pcsim::driver
{

	class IOutputBiRelayK1 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IOutputBiRelayK1() = default;

		 void Set( std::string & attSetOutput ) override = 0;
	};

	class IOutputBiRelayK2 : public siguni::interface::IUnitOutput 
	{
	  public:
		 virtual ~IOutputBiRelayK2() = default;

		 void Set( std::string & attSetOutput ) override = 0;
	};

	class IInputBiRelayK1 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IInputBiRelayK1() = default;

		 void Get( std::string & attGetInput ) override = 0;
	};

	class IInputBiRelayK2 : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IInputBiRelayK2() = default;

		 void Get( std::string & attGetInput ) override = 0;
	};



}

