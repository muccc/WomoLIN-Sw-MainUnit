/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "hal.h"

#include <iostream>

namespace mainunit::driver
{

   CHal::CHal()
      : controlbus()
      , inputHwBoardVersion()
      , inputDriverVersion()
      , outputBiRelayK1()
      , outputBiRelayK2()
      , inputBiRelayK1()
      , inputBiRelayK2()
   {
   }

   IControlbus & CHal::GetHandleControlbus()
   {
      return controlbus;
   }


	siguni::interface::IInputHwBoardVersion & CHal::GetHandleInputHwBoardVersion()
   {
      return inputHwBoardVersion;
   }

	siguni::interface::IInputDriverVersion & CHal::GetHandleInputDriverVersion()
   {
      return inputDriverVersion;
   }

	IOutputBiRelayK1 & CHal::GetHandleOutputBiRelayK1() 
   {
      return outputBiRelayK1;
   }

	IOutputBiRelayK2 & CHal::GetHandleOutputBiRelayK2() 
   {
      return outputBiRelayK2;
   }

	IInputBiRelayK1 & CHal::GetHandleInputBiRelayK1() 
   {
      return inputBiRelayK1;
   }

	IInputBiRelayK2 & CHal::GetHandleInputBiRelayK2() 
   {
      return inputBiRelayK2;
   }





}

