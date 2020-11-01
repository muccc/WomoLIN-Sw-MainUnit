/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "siguni/interface/ihw.h"

#include "ibirelay.h"
#include "iextrelay.h"
#include "ibme680.h"
#include "ilsm303.h"
#include "iibs.h"
#include "ihss.h"

namespace mainunit::driver
{
	class IHal
	{
	public:
      virtual ~IHal() = default;

	   virtual siguni::interface::IControlbus &         GetHandleControlbus() = 0;

	   virtual siguni::interface::IUnitInputGetHwBoardVersion &     GetHandleUnitInputGetHwBoardVersion() = 0;
	   virtual siguni::interface::IUnitInputGetDriverVersion &      GetHandleUnitInputGetDriverVersion() = 0;

       virtual IUnitOutputSetResetBirelayK1 &    GetHandleUnitOutputSetResetBirelayK1() = 0;
       virtual IUnitOutputSetResetBirelayK2 &    GetHandleUnitOutputSetResetBirelayK2() = 0;
       virtual IUnitOutputSetResetBirelayK3 &    GetHandleUnitOutputSetResetBirelayK3() = 0;
       virtual IUnitOutputSetResetBirelayK4 &    GetHandleUnitOutputSetResetBirelayK4() = 0;

	   virtual IUnitInputGetBirelayK1 &     GetHandleUnitInputGetBirelayK1() = 0;
	   virtual IUnitInputGetBirelayK2 &     GetHandleUnitInputGetBirelayK2() = 0;
	   virtual IUnitInputGetBirelayK3 &     GetHandleUnitInputGetBirelayK3() = 0;
	   virtual IUnitInputGetBirelayK4 &     GetHandleUnitInputGetBirelayK4() = 0;

	   virtual IUnitOutputSetResetExtRelay1 &   GetHandleUnitOutputSetResetExtRelay1() = 0;
	   virtual IUnitOutputSetResetExtRelay2 &   GetHandleUnitOutputSetResetExtRelay2() = 0;
	   virtual IUnitOutputSetResetExtRelay3 &   GetHandleUnitOutputSetResetExtRelay3() = 0;
	   virtual IUnitOutputSetResetExtRelay4 &   GetHandleUnitOutputSetResetExtRelay4() = 0;
	   virtual IUnitOutputSetResetExtRelay5 &   GetHandleUnitOutputSetResetExtRelay5() = 0;
	   virtual IUnitOutputSetResetExtRelay6 &   GetHandleUnitOutputSetResetExtRelay6() = 0;
	   virtual IUnitOutputSetResetExtRelay7 &   GetHandleUnitOutputSetResetExtRelay7() = 0;
	   virtual IUnitOutputSetResetExtRelay8 &   GetHandleUnitOutputSetResetExtRelay8() = 0;

	   virtual IUnitInputGetExtRelay1 &     GetHandleUnitInputGetExtRelay1() = 0;
	   virtual IUnitInputGetExtRelay2 &     GetHandleUnitInputGetExtRelay2() = 0;
	   virtual IUnitInputGetExtRelay3 &     GetHandleUnitInputGetExtRelay3() = 0;
	   virtual IUnitInputGetExtRelay4 &     GetHandleUnitInputGetExtRelay4() = 0;
	   virtual IUnitInputGetExtRelay5 &     GetHandleUnitInputGetExtRelay5() = 0;
	   virtual IUnitInputGetExtRelay6 &     GetHandleUnitInputGetExtRelay6() = 0;
	   virtual IUnitInputGetExtRelay7 &     GetHandleUnitInputGetExtRelay7() = 0;
	   virtual IUnitInputGetExtRelay8 &     GetHandleUnitInputGetExtRelay8() = 0;


	   virtual IUnitInputGetBme680Pressure &        GetHandleUnitInputGetBme680Pressure() = 0;
	   virtual IUnitInputGetBme680Temperature &     GetHandleUnitInputGetBme680Temperature() = 0;
	   virtual IUnitInputGetBme680Humidity &        GetHandleUnitInputGetBme680Humidity() = 0;


      virtual IUnitInputGetLsm303Magnetic &     GetHandleUnitInputGetLsm303Magnetic() = 0; 
      virtual IUnitInputGetLsm303Acceleration & GetHandleUnitInputGetLsm303Acceleration() = 0; 
   
   
      virtual IUnitInputGetIbsTemperature &     GetHandleUnitInputGetIbsTemperature() = 0; 
      virtual IUnitInputGetIbsVoltage &         GetHandleUnitInputGetIbsVoltage() = 0; 
      virtual IUnitInputGetIbsCurrent &         GetHandleUnitInputGetIbsCurrent() = 0; 
      virtual IUnitInputGetIbsCapacity &        GetHandleUnitInputGetIbsCapacity() = 0; 
      virtual IUnitInputGetIbsCharge &          GetHandleUnitInputGetIbsCharge() = 0; 
      virtual IUnitInputGetIbsHealth &          GetHandleUnitInputGetIbsHealth() = 0; 

      virtual IUnitOutputSetResetHss1 &    GetHandleUnitOutputSetResetHss1() = 0;
      virtual IUnitOutputSetResetHss2 &    GetHandleUnitOutputSetResetHss2() = 0;
      virtual IUnitOutputSetResetHss3 &    GetHandleUnitOutputSetResetHss3() = 0;
      virtual IUnitOutputSetResetHss4 &    GetHandleUnitOutputSetResetHss4() = 0;

      virtual IUnitInputGetHss1 &     GetHandleUnitInputGetHss1() = 0;
      virtual IUnitInputGetHss2 &     GetHandleUnitInputGetHss2() = 0;
      virtual IUnitInputGetHss3 &     GetHandleUnitInputGetHss3() = 0;
      virtual IUnitInputGetHss4 &     GetHandleUnitInputGetHss4() = 0;

	};
}

