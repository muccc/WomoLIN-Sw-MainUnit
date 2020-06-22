/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface.h"

#include "version.h"
#include "controlbus.h"
#include "birelay.h"


namespace mainunit::driver
{

	class CHal : public IHal
	{
	public:
       CHal();
	    ~CHal() = default;
	    IControlbus &          GetHandleControlbus() override final;

	    siguni::interface::IInputHwBoardVersion &     GetHandleInputHwBoardVersion() override final;
	    siguni::interface::IInputDriverVersion &      GetHandleInputDriverVersion() override final;

	    IOutputBiRelayK1 &     GetHandleOutputBiRelayK1() override final;
	    IOutputBiRelayK2 &     GetHandleOutputBiRelayK2() override final;

	    IInputBiRelayK1 &      GetHandleInputBiRelayK1() override final;
	    IInputBiRelayK2 &      GetHandleInputBiRelayK2() override final;

   private:
       CControlbus            controlbus; 

	    CInputHwBoardVersion   inputHwBoardVersion;
	    CInputDriverVersion    inputDriverVersion;

       COutputBiRelayK1       outputBiRelayK1; 
       COutputBiRelayK2       outputBiRelayK2; 

       CInputBiRelayK1        inputBiRelayK1; 
       CInputBiRelayK2        inputBiRelayK2; 
	};
}

