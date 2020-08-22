/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface.h"

namespace mainunit::driver
{

	class CUnitOutputSetResetExtRelay1 : public IUnitOutputSetResetExtRelay1 
	{
	  public:
       CUnitOutputSetResetExtRelay1() = default;
		 ~CUnitOutputSetResetExtRelay1() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay2 : public IUnitOutputSetResetExtRelay2 
	{
	  public:
       CUnitOutputSetResetExtRelay2() = default;
		 ~CUnitOutputSetResetExtRelay2() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay3 : public IUnitOutputSetResetExtRelay3 
	{
	  public:
       CUnitOutputSetResetExtRelay3() = default;
		 ~CUnitOutputSetResetExtRelay3() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay4 : public IUnitOutputSetResetExtRelay4 
	{
	  public:
       CUnitOutputSetResetExtRelay4() = default;
		 ~CUnitOutputSetResetExtRelay4() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay5 : public IUnitOutputSetResetExtRelay5 
	{
	  public:
       CUnitOutputSetResetExtRelay5() = default;
		 ~CUnitOutputSetResetExtRelay5() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay6 : public IUnitOutputSetResetExtRelay6 
	{
	  public:
       CUnitOutputSetResetExtRelay6() = default;
		 ~CUnitOutputSetResetExtRelay6() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay7 : public IUnitOutputSetResetExtRelay7 
	{
	  public:
       CUnitOutputSetResetExtRelay7() = default;
		 ~CUnitOutputSetResetExtRelay7() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitOutputSetResetExtRelay8 : public IUnitOutputSetResetExtRelay8 
	{
	  public:
       CUnitOutputSetResetExtRelay8() = default;
		 ~CUnitOutputSetResetExtRelay8() = default;

		 void Set( std::string & attSetOutput, siguni::interface::CAdditionals & additionals ) override final;
	};




	class CUnitInputGetExtRelay1 : public IUnitInputGetExtRelay1 
	{
	  public:
       CUnitInputGetExtRelay1() = default;
		 ~CUnitInputGetExtRelay1() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay2 : public IUnitInputGetExtRelay2 
	{
	  public:
       CUnitInputGetExtRelay2() = default;
		 ~CUnitInputGetExtRelay2() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay3 : public IUnitInputGetExtRelay3 
	{
	  public:
       CUnitInputGetExtRelay3() = default;
		 ~CUnitInputGetExtRelay3() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay4 : public IUnitInputGetExtRelay4 
	{
	  public:
       CUnitInputGetExtRelay4() = default;
		 ~CUnitInputGetExtRelay4() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay5 : public IUnitInputGetExtRelay5 
	{
	  public:
       CUnitInputGetExtRelay5() = default;
		 ~CUnitInputGetExtRelay5() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay6 : public IUnitInputGetExtRelay6 
	{
	  public:
       CUnitInputGetExtRelay6() = default;
		 ~CUnitInputGetExtRelay6() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay7 : public IUnitInputGetExtRelay7 
	{
	  public:
       CUnitInputGetExtRelay7() = default;
		 ~CUnitInputGetExtRelay7() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

	class CUnitInputGetExtRelay8 : public IUnitInputGetExtRelay8 
	{
	  public:
       CUnitInputGetExtRelay8() = default;
		 ~CUnitInputGetExtRelay8() = default;

		 void Get( std::string & attGetInput, siguni::interface::CAdditionals & additionals ) override final;
	};

}

