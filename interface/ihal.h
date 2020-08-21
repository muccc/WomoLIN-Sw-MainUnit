/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/ihw.h"

#include "ibirelay.h"

namespace mainunit::driver
{
	class IHal
	{
	public:
      virtual ~IHal() = default;

	   virtual siguni::interface::IControlbus &         GetHandleControlbus() = 0;

	   virtual siguni::interface::IUnitInputGetHwBoardVersion &     GetHandleUnitInputGetHwBoardVersion() = 0;
	   virtual siguni::interface::IUnitInputGetDriverVersion &      GetHandleUnitInputGetDriverVersion() = 0;

	   virtual IUnitOutputSetResetK1 &    GetHandleUnitOutputSetResetK1() = 0;
	   virtual IUnitOutputSetResetK2 &    GetHandleUnitOutputSetResetK2() = 0;
	   virtual IUnitOutputSetResetK3 &    GetHandleUnitOutputSetResetK3() = 0;
	   virtual IUnitOutputSetResetK4 &    GetHandleUnitOutputSetResetK4() = 0;

	   virtual IUnitInputGetBirelayK1 &     GetHandleUnitInputGetBirelayK1() = 0;
	   virtual IUnitInputGetBirelayK2 &     GetHandleUnitInputGetBirelayK2() = 0;
	   virtual IUnitInputGetBirelayK3 &     GetHandleUnitInputGetBirelayK3() = 0;
	   virtual IUnitInputGetBirelayK4 &     GetHandleUnitInputGetBirelayK4() = 0;
	};
}

