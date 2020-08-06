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
#include "birelay.h"

extern UART_HandleTypeDef huart1;
extern SPI_HandleTypeDef hspi3;

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

			IUnitInputGetK1 &GetHandleUnitInputGetK1() override final;
			IUnitInputGetK2 &GetHandleUnitInputGetK2() override final;

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

			CUnitOutputSetResetK1	UnitOutputSetResetK1;
			CUnitOutputSetResetK2	UnitOutputSetResetK2;

			CUnitInputGetK1	UnitInputGetK1;
			CUnitInputGetK2	UnitInputGetK2;
	};
}

