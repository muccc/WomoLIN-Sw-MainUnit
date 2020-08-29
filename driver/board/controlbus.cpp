/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "controlbus.h"

#include <iostream>

namespace mainunit::driver
{
/*
   void error(const char *msg)
   {
      perror(msg);
      exit(1);
   }
*/
	CControlbus::CControlbus(const Uart &uart, const GPIO &gpio) : m_puart(const_cast<Uart&>(uart)), m_pstbctrl(const_cast<GPIO&>(gpio))
	{
		//m_pstbctrl.setHigh();
		m_pstbctrl.setLow();
	}

	int CControlbus::WriteData( const std::string & attMessage ) 
	{
		m_puart.write(attMessage);
		return attMessage.length();
	}


	int CControlbus::ReadData( std::string & attMessage )
	{
		return m_puart.read(attMessage);
	}

}

