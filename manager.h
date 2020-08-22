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

         // units versions 
         siguni::CUnitInput         UnitInputGetHwBoardVersion { GetHandleUnitInputGetHwBoardVersion() } ; 
         siguni::CUnitInput         UnitInputGetDriverVersion { GetHandleUnitInputGetDriverVersion() } ; 
 
         // units birelays Kx 
         siguni::CUnitOutput        UnitOutputSetResetBirelayK1 { GetHandleUnitOutputSetResetBirelayK1() } ;
         siguni::CUnitOutput        UnitOutputSetResetBirelayK2 { GetHandleUnitOutputSetResetBirelayK2() } ;
         siguni::CUnitOutput        UnitOutputSetResetBirelayK3 { GetHandleUnitOutputSetResetBirelayK3() } ;
         siguni::CUnitOutput        UnitOutputSetResetBirelayK4 { GetHandleUnitOutputSetResetBirelayK4() } ;

         siguni::CUnitInput         UnitInputGetBirelayK1 { GetHandleUnitInputGetBirelayK1() } ;
         siguni::CUnitInput         UnitInputGetBirelayK2 { GetHandleUnitInputGetBirelayK2() } ;
         siguni::CUnitInput         UnitInputGetBirelayK3 { GetHandleUnitInputGetBirelayK3() } ;
         siguni::CUnitInput         UnitInputGetBirelayK4 { GetHandleUnitInputGetBirelayK4() } ;

         // units external relays  
         siguni::CUnitOutput        UnitOutputSetResetExtRelay1 { GetHandleUnitOutputSetResetExtRelay1() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay2 { GetHandleUnitOutputSetResetExtRelay2() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay3 { GetHandleUnitOutputSetResetExtRelay3() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay4 { GetHandleUnitOutputSetResetExtRelay4() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay5 { GetHandleUnitOutputSetResetExtRelay5() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay6 { GetHandleUnitOutputSetResetExtRelay6() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay7 { GetHandleUnitOutputSetResetExtRelay7() } ; 
         siguni::CUnitOutput        UnitOutputSetResetExtRelay8 { GetHandleUnitOutputSetResetExtRelay8() } ; 

         siguni::CUnitInput         UnitInputGetExtRelay1 { GetHandleUnitInputGetExtRelay1() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay2 { GetHandleUnitInputGetExtRelay2() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay3 { GetHandleUnitInputGetExtRelay3() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay4 { GetHandleUnitInputGetExtRelay4() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay5 { GetHandleUnitInputGetExtRelay5() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay6 { GetHandleUnitInputGetExtRelay6() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay7 { GetHandleUnitInputGetExtRelay7() } ; 
         siguni::CUnitInput         UnitInputGetExtRelay8 { GetHandleUnitInputGetExtRelay8() } ; 


         // signals versions
         siguni::CSignalGetVersion  GetHwBoardVersion { siguni::CSignalGetVersion() };
         siguni::CSignalGetVersion  GetDriverVersion { siguni::CSignalGetVersion() };

         // signals birelays Kx 
         siguni::CSignalSetReset    SetResetBirelayK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetBirelayK2 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetBirelayK3 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetBirelayK4 { siguni::CSignalSetReset() };

         siguni::CSignalSetReset    GetBirelayK1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetBirelayK2 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetBirelayK3 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetBirelayK4 { siguni::CSignalSetReset() };

         // signals external relays  
         siguni::CSignalSetReset    SetResetExtRelay1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay2 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay3 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay4 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay5 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay6 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay7 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    SetResetExtRelay8 { siguni::CSignalSetReset() };

         siguni::CSignalSetReset    GetExtRelay1 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay2 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay3 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay4 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay5 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay6 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay7 { siguni::CSignalSetReset() };
         siguni::CSignalSetReset    GetExtRelay8 { siguni::CSignalSetReset() };

   };

}
