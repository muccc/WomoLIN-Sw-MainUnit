/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "birelay.h"

#include <iostream>

namespace mainunit::driver
{

   void CUnitOutputSetResetK1::Set( std::string & attSetOutput )
   {
      std::cout << "Bi Relay K1 set output to " << attSetOutput << std::endl;
   } 
 
   void CUnitOutputSetResetK2::Set( std::string & attSetOutput )
   {
      std::cout << "Bi Relay K2 set output to " << attSetOutput << std::endl;
   } 

   void CUnitInputGetK1::Get( std::string & attGetInput )
   {
      attGetInput = "UNKNOWN";
      std::cout << "Bi Relay K1 Input :" << attGetInput << std::endl;
   } 

   void CUnitInputGetK2::Get( std::string & attGetInput )
   {
      attGetInput = "UNKNOWN";
      std::cout << "Bi Relay K2 Input :" << attGetInput << std::endl;
   } 
}

