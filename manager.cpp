/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "manager.h"

#include <iostream>

namespace mainunit
{
   CManager::CManager( ) 
      : CHal() 
      , siguni::CManagerBase( GetHandleControlbus() )
   {

      signalVector["GetHwBoardVersion"] = &GetHwBoardVersion;
      signalVector["GetDriverVersion"] = &GetDriverVersion;

      signalVector["SetResetK1"] = &SetResetK1;
      signalVector["SetResetK2"] = &SetResetK2;
      signalVector["SetResetK3"] = &SetResetK3;
      signalVector["SetResetK4"] = &SetResetK4;
      signalVector["SetResetK14"] = &SetResetK14;

      signalVector["GetK1"] = &GetK1;
      signalVector["GetK2"] = &GetK2;
      signalVector["GetK3"] = &GetK3;
      signalVector["GetK4"] = &GetK4;

      GetHwBoardVersion.AddUnit( &UnitInputGetHwBoardVersion );
      GetDriverVersion.AddUnit( &UnitInputGetDriverVersion );

      SetResetK1.AddUnit( &UnitOutputSetResetK1 );
      SetResetK2.AddUnit( &UnitOutputSetResetK2 );
      SetResetK3.AddUnit( &UnitOutputSetResetK3 );
      SetResetK4.AddUnit( &UnitOutputSetResetK4 );
      SetResetK14.AddUnit( &UnitOutputSetResetK1 );
      SetResetK14.AddUnit( &UnitOutputSetResetK2 );
      SetResetK14.AddUnit( &UnitOutputSetResetK3 );
      SetResetK14.AddUnit( &UnitOutputSetResetK4 );

      GetK1.AddUnit( &UnitInputGetK1 );
      GetK2.AddUnit( &UnitInputGetK2 );
      GetK3.AddUnit( &UnitInputGetK3 );
      GetK4.AddUnit( &UnitInputGetK4 );


   }
}
