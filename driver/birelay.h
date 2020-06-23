/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"

namespace mainunit::driver
{

	class COutputBiRelayK1 : public IOutputBiRelayK1 
	{
	  public:
       COutputBiRelayK1() = default;
		 ~COutputBiRelayK1() = default;

		 void Set( std::string & attSetOutput ) override final;
	};

	class COutputBiRelayK2 : public IOutputBiRelayK2 
	{
	  public:
       COutputBiRelayK2() = default;
		 ~COutputBiRelayK2() = default;

		 void Set( std::string & attSetOutput ) override final;
	};

	class CInputBiRelayK1 : public IInputBiRelayK1 
	{
	  public:
       CInputBiRelayK1() = default;
		 ~CInputBiRelayK1() = default;

		 void Get( std::string & attGetInput ) override final;
	};

	class CInputBiRelayK2 : public IInputBiRelayK2 
	{
	  public:
       CInputBiRelayK2() = default;
		 ~CInputBiRelayK2() = default;

		 void Get( std::string & attGetInput ) override final;
	};



}

