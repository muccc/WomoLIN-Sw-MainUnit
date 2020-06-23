/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "birelay.h"

#include <iostream>

namespace mainunit::driver
{

   void COutputBiRelayK1::Set( std::string & attSetOutput )
   {
      std::cout << "Bi Relay K1 set output to " << attSetOutput << std::endl;
   } 
 
   void COutputBiRelayK2::Set( std::string & attSetOutput )
   {
      std::cout << "Bi Relay K2 set output to " << attSetOutput << std::endl;
   } 

   void CInputBiRelayK1::Get( std::string & attGetInput )
   {
      attGetInput = "UNKNOWN";
      std::cout << "Bi Relay K1 Input :" << attGetInput << std::endl;
   } 

   void CInputBiRelayK2::Get( std::string & attGetInput )
   {
      attGetInput = "UNKNOWN";
      std::cout << "Bi Relay K2 Input :" << attGetInput << std::endl;
   } 

}

