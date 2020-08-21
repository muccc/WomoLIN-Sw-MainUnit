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

      signalVector["GetBirelayK1"] = &GetBirelayK1;
      signalVector["GetBirelayK2"] = &GetBirelayK2;
      signalVector["GetBirelayK3"] = &GetBirelayK3;
      signalVector["GetBirelayK4"] = &GetBirelayK4;

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

      GetBirelayK1.AddUnit( &UnitInputGetBirelayK1 );
      GetBirelayK2.AddUnit( &UnitInputGetBirelayK2 );
      GetBirelayK3.AddUnit( &UnitInputGetBirelayK3 );
      GetBirelayK4.AddUnit( &UnitInputGetBirelayK4 );


   }
}
