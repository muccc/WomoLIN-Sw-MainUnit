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

namespace mainunit
{
#if 1
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

         siguni::CUnitInput         UnitInputGetK1 { GetHandleUnitInputGetK1() } ; 
         siguni::CUnitInput         UnitInputGetK2 { GetHandleUnitInputGetK2() } ; 


         // signals

         siguni::CSignalGetVersion  GetHwBoardVersion { siguni::CSignalGetVersion() };
         siguni::CSignalGetVersion  GetDriverVersion { siguni::CSignalGetVersion() };

         siguni::CSignalSetReset    SetResetK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetK2 { siguni::CSignalSetReset() };

         siguni::CSignalSetReset    GetK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetK2 { siguni::CSignalSetReset() };

   };
 #else
 class CManager 
      : public driver::CHal
      , public siguni::CManagerBase 
   {
      public:
         CManager();
         ~CManager() = default;

      private:



   };
 #endif
}
