/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "hal.h"

#include <iostream>

namespace mainunit::driver
{

   CHal::CHal()
      : Controlbus()
      , UnitInputGetHwBoardVersion()
      , UnitInputGetDriverVersion()
      , UnitOutputSetResetK1()
      , UnitOutputSetResetK2()
      , UnitInputGetK1()
      , UnitInputGetK2()
   {
   }

   siguni::interface::IControlbus & CHal::GetHandleControlbus()
   {
      return Controlbus;
   }


	siguni::interface::IUnitInputGetHwBoardVersion & CHal::GetHandleUnitInputGetHwBoardVersion()
   {
      return UnitInputGetHwBoardVersion;
   }

	siguni::interface::IUnitInputGetDriverVersion & CHal::GetHandleUnitInputGetDriverVersion()
   {
      return UnitInputGetDriverVersion;
   }

	IUnitOutputSetResetK1 & CHal::GetHandleUnitOutputSetResetK1() 
   {
      return UnitOutputSetResetK1;
   }

	IUnitOutputSetResetK2 & CHal::GetHandleUnitOutputSetResetK2() 
   {
      return UnitOutputSetResetK2;
   }

	IUnitInputGetK1 & CHal::GetHandleUnitInputGetK1() 
   {
      return UnitInputGetK1;
   }

	IUnitInputGetK2 & CHal::GetHandleUnitInputGetK2() 
   {
      return UnitInputGetK2;
   }


}

