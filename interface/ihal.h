/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/ihw.h"

#include "icontrolbus.h"
#include "ibirelay.h"

namespace pcsim::driver
{
	class IHal
	{
	public:
      virtual ~IHal() = default;

	   virtual IControlbus &         GetHandleControlbus() = 0;

	   virtual siguni::interface::IInputHwBoardVersion &     GetHandleInputHwBoardVersion() = 0;
	   virtual siguni::interface::IInputDriverVersion &      GetHandleInputDriverVersion() = 0;

	   virtual IOutputBiRelayK1 &    GetHandleOutputBiRelayK1() = 0;
	   virtual IOutputBiRelayK2 &    GetHandleOutputBiRelayK2() = 0;

	   virtual IInputBiRelayK1 &     GetHandleInputBiRelayK1() = 0;
	   virtual IInputBiRelayK2 &     GetHandleInputBiRelayK2() = 0;
	};
}

