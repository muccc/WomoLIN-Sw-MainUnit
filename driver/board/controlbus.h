/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#pragma once

#include "interface.h"
#include "uart.h"
#include "gpio.h"

namespace mainunit::driver
{
	class CControlbus : public siguni::interface::IControlbus
	{
		public:
			CControlbus(const Uart &uart, const GPIO &gpio);
			~CControlbus() = default;

			int WriteData( const std::string & attMessage ) override final;
			int ReadData( std::string & attMessage ) override final;

			CControlbus() = delete;
			CControlbus(const CControlbus &) = delete;

		private:
			Uart &m_puart;
			GPIO &m_pstbctrl;

	};
}

