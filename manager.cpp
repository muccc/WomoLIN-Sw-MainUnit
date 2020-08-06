/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "manager.h"

#include <iostream>

//UART_HandleTypeDef huart1;
SPI_HandleTypeDef hspi3;

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
      signalVector["GetK1"] = &GetK1;
      signalVector["GetK2"] = &GetK2;

      GetHwBoardVersion.AddUnit( &UnitInputGetHwBoardVersion );
      GetDriverVersion.AddUnit( &UnitInputGetDriverVersion );

      SetResetK1.AddUnit( &UnitOutputSetResetK1 );
      SetResetK2.AddUnit( &UnitOutputSetResetK2 );

      GetK1.AddUnit( &UnitInputGetK1 );
      GetK2.AddUnit( &UnitInputGetK2 );


   }
}
