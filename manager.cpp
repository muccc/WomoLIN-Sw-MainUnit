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
      // signal vector versions
      signalVector["GetHwBoardVersion"] = &GetHwBoardVersion;
      signalVector["GetDriverVersion"] = &GetDriverVersion;

      // signal vector birelays
      signalVector["SetResetBirelayK1"] = &SetResetBirelayK1;
      signalVector["SetResetBirelayK2"] = &SetResetBirelayK2;
      signalVector["SetResetBirelayK3"] = &SetResetBirelayK3;
      signalVector["SetResetBirelayK4"] = &SetResetBirelayK4;

      signalVector["GetBirelayK1"] = &GetBirelayK1;
      signalVector["GetBirelayK2"] = &GetBirelayK2;
      signalVector["GetBirelayK3"] = &GetBirelayK3;
      signalVector["GetBirelayK4"] = &GetBirelayK4;

      // signal vector external relays
      signalVector["SetResetExtRelay1"] = &SetResetExtRelay1;
      signalVector["SetResetExtRelay2"] = &SetResetExtRelay2;
      signalVector["SetResetExtRelay3"] = &SetResetExtRelay3;
      signalVector["SetResetExtRelay4"] = &SetResetExtRelay4;
      signalVector["SetResetExtRelay5"] = &SetResetExtRelay5;
      signalVector["SetResetExtRelay6"] = &SetResetExtRelay6;
      signalVector["SetResetExtRelay7"] = &SetResetExtRelay7;
      signalVector["SetResetExtRelay8"] = &SetResetExtRelay8;

      signalVector["GetExtRelay1"] = &GetExtRelay1;
      signalVector["GetExtRelay2"] = &GetExtRelay2;
      signalVector["GetExtRelay3"] = &GetExtRelay3;
      signalVector["GetExtRelay4"] = &GetExtRelay4;
      signalVector["GetExtRelay5"] = &GetExtRelay5;
      signalVector["GetExtRelay6"] = &GetExtRelay6;
      signalVector["GetExtRelay7"] = &GetExtRelay7;
      signalVector["GetExtRelay8"] = &GetExtRelay8;

      // signal vector bme680 
      signalVector["GetBme680Pressure"] = &GetBme680Pressure;
      signalVector["GetBme680Temperature"] = &GetBme680Temperature;
      signalVector["GetBme680Humidity"] = &GetBme680Humidity;


      // connect versions
      GetHwBoardVersion.AddUnit( &UnitInputGetHwBoardVersion );
      GetDriverVersion.AddUnit( &UnitInputGetDriverVersion );

      // connect birelays
      SetResetBirelayK1.AddUnit( &UnitOutputSetResetBirelayK1 );
      SetResetBirelayK2.AddUnit( &UnitOutputSetResetBirelayK2 );
      SetResetBirelayK3.AddUnit( &UnitOutputSetResetBirelayK3 );
      SetResetBirelayK4.AddUnit( &UnitOutputSetResetBirelayK4 );

      GetBirelayK1.AddUnit( &UnitInputGetBirelayK1 );
      GetBirelayK2.AddUnit( &UnitInputGetBirelayK2 );
      GetBirelayK3.AddUnit( &UnitInputGetBirelayK3 );
      GetBirelayK4.AddUnit( &UnitInputGetBirelayK4 );

      // connect external relays

      SetResetExtRelay1.AddUnit( &UnitOutputSetResetExtRelay1 );
      SetResetExtRelay2.AddUnit( &UnitOutputSetResetExtRelay2 );
      SetResetExtRelay3.AddUnit( &UnitOutputSetResetExtRelay3 );
      SetResetExtRelay4.AddUnit( &UnitOutputSetResetExtRelay4 );
      SetResetExtRelay5.AddUnit( &UnitOutputSetResetExtRelay5 );
      SetResetExtRelay6.AddUnit( &UnitOutputSetResetExtRelay6 );
      SetResetExtRelay7.AddUnit( &UnitOutputSetResetExtRelay7 );
      SetResetExtRelay8.AddUnit( &UnitOutputSetResetExtRelay8 );

      GetExtRelay1.AddUnit( &UnitInputGetExtRelay1 );
      GetExtRelay2.AddUnit( &UnitInputGetExtRelay2 );
      GetExtRelay3.AddUnit( &UnitInputGetExtRelay3 );
      GetExtRelay4.AddUnit( &UnitInputGetExtRelay4 );
      GetExtRelay5.AddUnit( &UnitInputGetExtRelay5 );
      GetExtRelay6.AddUnit( &UnitInputGetExtRelay6 );
      GetExtRelay7.AddUnit( &UnitInputGetExtRelay7 );
      GetExtRelay8.AddUnit( &UnitInputGetExtRelay8 );

      // connect bme680

      GetBme680Pressure.AddUnit( &UnitInputGetBme680Pressure );
      GetBme680Temperature.AddUnit( &UnitInputGetBme680Temperature );
      GetBme680Humidity.AddUnit( &UnitInputGetBme680Humidity );
   }

}
