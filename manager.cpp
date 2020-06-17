/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "manager.h"

#include <iostream>

namespace pcsim
{

   CManager::CManager( ) 
      : CHal() 
      , siguni::CManagerBase( GetHandleControlbus() )
   {

      signalVector["sigHwBoardVersion"] = &sigHwBoardVersion;
      signalVector["sigDriverVersion"] = &sigDriverVersion;

      signalVector["sigOutputK1"] = &sigOutputK1;
      signalVector["sigOutputK2"] = &sigOutputK2;
      signalVector["sigInputK1"] = &sigInputK1;
      signalVector["sigInputK2"] = &sigInputK2;

      sigHwBoardVersion.AddUnit( &inputHwBoardVersion );
      sigDriverVersion.AddUnit( &inputDriverVersion );

      sigOutputK1.AddUnit( &outputK1 );
      sigOutputK2.AddUnit( &outputK2 );

      sigInputK1.AddUnit( &inputK1 );
      sigInputK2.AddUnit( &inputK2 );


   }

}
