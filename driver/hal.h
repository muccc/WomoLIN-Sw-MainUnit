/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

//#include "stm32l476xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_it.h"

#include "interface.h"

#include "version.h"
#include "controlbus.h"
#include "relaydrv.h"
#include "birelay.h"
#include "extrelay.h"
#include "bme680.h"

namespace mainunit::driver
{

	class CHal : public IHal
	{
    public:
        CHal();
        ~CHal() = default;
        siguni::interface::IControlbus &GetHandleControlbus() override final;

        siguni::interface::IUnitInputGetHwBoardVersion &GetHandleUnitInputGetHwBoardVersion() override final;
        siguni::interface::IUnitInputGetDriverVersion &GetHandleUnitInputGetDriverVersion() override final;

        IUnitOutputSetResetBirelayK1 & GetHandleUnitOutputSetResetBirelayK1() override final;
        IUnitOutputSetResetBirelayK2 & GetHandleUnitOutputSetResetBirelayK2() override final;
        IUnitOutputSetResetBirelayK3 & GetHandleUnitOutputSetResetBirelayK3() override final;
        IUnitOutputSetResetBirelayK4 & GetHandleUnitOutputSetResetBirelayK4() override final;

        IUnitInputGetBirelayK1 &    GetHandleUnitInputGetBirelayK1() override final;
        IUnitInputGetBirelayK2 &    GetHandleUnitInputGetBirelayK2() override final;
        IUnitInputGetBirelayK3 &    GetHandleUnitInputGetBirelayK3() override final;
        IUnitInputGetBirelayK4 &    GetHandleUnitInputGetBirelayK4() override final;

        IUnitOutputSetResetExtRelay1 &    GetHandleUnitOutputSetResetExtRelay1() override final;
        IUnitOutputSetResetExtRelay2 &    GetHandleUnitOutputSetResetExtRelay2() override final;
        IUnitOutputSetResetExtRelay3 &    GetHandleUnitOutputSetResetExtRelay3() override final;
        IUnitOutputSetResetExtRelay4 &    GetHandleUnitOutputSetResetExtRelay4() override final;
        IUnitOutputSetResetExtRelay5 &    GetHandleUnitOutputSetResetExtRelay5() override final;
        IUnitOutputSetResetExtRelay6 &    GetHandleUnitOutputSetResetExtRelay6() override final;
        IUnitOutputSetResetExtRelay7 &    GetHandleUnitOutputSetResetExtRelay7() override final;
        IUnitOutputSetResetExtRelay8 &    GetHandleUnitOutputSetResetExtRelay8() override final;

        IUnitInputGetExtRelay1 &     GetHandleUnitInputGetExtRelay1() override final;
        IUnitInputGetExtRelay2 &     GetHandleUnitInputGetExtRelay2() override final;
        IUnitInputGetExtRelay3 &     GetHandleUnitInputGetExtRelay3() override final;
        IUnitInputGetExtRelay4 &     GetHandleUnitInputGetExtRelay4() override final;
        IUnitInputGetExtRelay5 &     GetHandleUnitInputGetExtRelay5() override final;
        IUnitInputGetExtRelay6 &     GetHandleUnitInputGetExtRelay6() override final;
        IUnitInputGetExtRelay7 &     GetHandleUnitInputGetExtRelay7() override final;
        IUnitInputGetExtRelay8 &     GetHandleUnitInputGetExtRelay8() override final;

        IUnitInputGetBme680Pressure &     GetHandleUnitInputGetBme680Pressure() override final;
        IUnitInputGetBme680Temperature &  GetHandleUnitInputGetBme680Temperature() override final;
        IUnitInputGetBme680Humidity &     GetHandleUnitInputGetBme680Humidity() override final;

    private:

        CControlbus &Controlbus;

        CUnitInputGetHwBoardVersion UnitInputGetHwBoardVersion;
        CUnitInputGetDriverVersion 	UnitInputGetDriverVersion;

        RelayDrv &Relay;

        CUnitOutputSetResetBirelayK1	UnitOutputSetResetBirelayK1;
        CUnitOutputSetResetBirelayK2	UnitOutputSetResetBirelayK2;
        CUnitOutputSetResetBirelayK3	UnitOutputSetResetBirelayK3;
        CUnitOutputSetResetBirelayK4	UnitOutputSetResetBirelayK4;

        CUnitInputGetBirelayK1	UnitInputGetBirelayK1;
        CUnitInputGetBirelayK2	UnitInputGetBirelayK2;
        CUnitInputGetBirelayK3	UnitInputGetBirelayK3;
        CUnitInputGetBirelayK4	UnitInputGetBirelayK4;

        RelayDrv &Relay1;

        CUnitOutputSetResetExtRelay1         UnitOutputSetResetExtRelay1;
        CUnitOutputSetResetExtRelay2         UnitOutputSetResetExtRelay2;
        CUnitOutputSetResetExtRelay3         UnitOutputSetResetExtRelay3;
        CUnitOutputSetResetExtRelay4         UnitOutputSetResetExtRelay4;
        CUnitOutputSetResetExtRelay5         UnitOutputSetResetExtRelay5;
        CUnitOutputSetResetExtRelay6         UnitOutputSetResetExtRelay6;
        CUnitOutputSetResetExtRelay7         UnitOutputSetResetExtRelay7;
        CUnitOutputSetResetExtRelay8         UnitOutputSetResetExtRelay8;

        CUnitInputGetExtRelay1               UnitInputGetExtRelay1;
        CUnitInputGetExtRelay2               UnitInputGetExtRelay2;
        CUnitInputGetExtRelay3               UnitInputGetExtRelay3;
        CUnitInputGetExtRelay4               UnitInputGetExtRelay4;
        CUnitInputGetExtRelay5               UnitInputGetExtRelay5;
        CUnitInputGetExtRelay6               UnitInputGetExtRelay6;
        CUnitInputGetExtRelay7               UnitInputGetExtRelay7;
        CUnitInputGetExtRelay8               UnitInputGetExtRelay8;

        CUnitInputGetBme680Pressure          UnitInputGetBme680Pressure;
        CUnitInputGetBme680Temperature       UnitInputGetBme680Temperature;
        CUnitInputGetBme680Humidity          UnitInputGetBme680Humidity;

    private:
        void SystemClock_Config();
        void MX_GPIO_Init();
        void MX_USART1_UART_Init();
        void MX_SPI3_Init(void);

        static void irqsyshandler(void *param);
	};
}

