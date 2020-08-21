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

			IUnitOutputSetResetK1 &GetHandleUnitOutputSetResetK1() override final;
			IUnitOutputSetResetK2 &GetHandleUnitOutputSetResetK2() override final;
			IUnitOutputSetResetK3 &GetHandleUnitOutputSetResetK3() override final;
			IUnitOutputSetResetK4 &GetHandleUnitOutputSetResetK4() override final;

			IUnitInputGetBirelayK1 &GetHandleUnitInputGetBirelayK1() override final;
			IUnitInputGetBirelayK2 &GetHandleUnitInputGetBirelayK2() override final;
			IUnitInputGetBirelayK3 &GetHandleUnitInputGetBirelayK3() override final;
			IUnitInputGetBirelayK4 &GetHandleUnitInputGetBirelayK4() override final;

		private:
			void SystemClock_Config();
			void MX_GPIO_Init();
			void MX_USART1_UART_Init();
			void MX_SPI3_Init(void);

			static void irqsyshandler(void *param);

		private:

			CControlbus &Controlbus;

			CUnitInputGetHwBoardVersion UnitInputGetHwBoardVersion;
			CUnitInputGetDriverVersion 	UnitInputGetDriverVersion;

			RelayDrv &Relay;

			CUnitOutputSetResetK1	UnitOutputSetResetK1;
			CUnitOutputSetResetK2	UnitOutputSetResetK2;
			CUnitOutputSetResetK3	UnitOutputSetResetK3;
			CUnitOutputSetResetK4	UnitOutputSetResetK4;

			CUnitInputGetBirelayK1	UnitInputGetBirelayK1;
			CUnitInputGetBirelayK2	UnitInputGetBirelayK2;
			CUnitInputGetBirelayK3	UnitInputGetBirelayK3;
			CUnitInputGetBirelayK4	UnitInputGetBirelayK4;
	};
}

