/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/managerbase.h"
#include "siguni/signal.h"
#include "siguni/unit.h"

#include "driver/hal.h"
#include "driver/birelay.h"
#include "driver/controlbus.h"

namespace pcsim
{

   class CManager 
      : public driver::CHal
      , public siguni::CManagerBase 
   {
      public:
         CManager();
         ~CManager() = default;

      private:


         // units
        
         siguni::CUnitInput         inputHwBoardVersion { GetHandleInputHwBoardVersion() } ; 
         siguni::CUnitInput         inputDriverVersion { GetHandleInputDriverVersion() } ; 
 
         siguni::CUnitOutput        outputK1 { GetHandleOutputBiRelayK1() } ; 
         siguni::CUnitOutput        outputK2 { GetHandleOutputBiRelayK2() } ; 

         siguni::CUnitInput         inputK1 { GetHandleInputBiRelayK1() } ; 
         siguni::CUnitInput         inputK2 { GetHandleInputBiRelayK2() } ; 

         // signals

         siguni::CSignalGetVersion  sigHwBoardVersion { siguni::CSignalGetVersion() };
         siguni::CSignalGetVersion  sigDriverVersion { siguni::CSignalGetVersion() };

         siguni::CSignalSetReset    sigOutputK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    sigOutputK2 { siguni::CSignalSetReset() };

         siguni::CSignalSetReset    sigInputK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    sigInputK2 { siguni::CSignalSetReset() };

   };

}
