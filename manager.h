/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/managerbase.h"
#include "siguni/signal.h"
#include "siguni/unit.h"
#include "siguni/hal.h"
#include "siguni/protocol.h"

#include "driver/hal.h"
#include "driver/board/birelay.h"
#include "driver/board/controlbus.h"

namespace mainunit
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

         siguni::CUnitInput         UnitInputGetHwBoardVersion { GetHandleUnitInputGetHwBoardVersion() } ; 
         siguni::CUnitInput         UnitInputGetDriverVersion { GetHandleUnitInputGetDriverVersion() } ; 

         siguni::CUnitOutput        UnitOutputSetResetK1 { GetHandleUnitOutputSetResetK1() } ; 
         siguni::CUnitOutput        UnitOutputSetResetK2 { GetHandleUnitOutputSetResetK2() } ;
         siguni::CUnitOutput        UnitOutputSetResetK3 { GetHandleUnitOutputSetResetK3() } ;
         siguni::CUnitOutput        UnitOutputSetResetK4 { GetHandleUnitOutputSetResetK4() } ;


         siguni::CUnitInput         UnitInputGetBirelayK1 { GetHandleUnitInputGetBirelayK1() } ;
         siguni::CUnitInput         UnitInputGetBirelayK2 { GetHandleUnitInputGetBirelayK2() } ;
         siguni::CUnitInput         UnitInputGetBirelayK3 { GetHandleUnitInputGetBirelayK3() } ;
         siguni::CUnitInput         UnitInputGetBirelayK4 { GetHandleUnitInputGetBirelayK4() } ;


         // signals

         siguni::CSignalGetVersion  GetHwBoardVersion { siguni::CSignalGetVersion() };
         siguni::CSignalGetVersion  GetDriverVersion { siguni::CSignalGetVersion() };

         siguni::CSignalSetReset    SetResetK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetK2 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetK3 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetK4 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetK14 { siguni::CSignalSetReset() };

         siguni::CSignalSetReset    GetBirelayK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetBirelayK2 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetBirelayK3 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetBirelayK4 { siguni::CSignalSetReset() };

   };
}
