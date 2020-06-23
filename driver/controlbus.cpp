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
   CControlbus::CControlbus()
   {

   }

	int CControlbus::WriteData( const std::string & attMessage ) 
   { 
	return 0;
   }


	int CControlbus::ReadData( std::string & attMessage )
   {
		return 0;
   }

}

