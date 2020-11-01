/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "hss.h"

#include <iostream>

namespace mainunit::driver
{


   CUnitOutputSetResetHss1::CUnitOutputSetResetHss1() {}

   void CUnitOutputSetResetHss1::Set( std::string & /*attSetOutput*/, [[maybe_unused]] CAdditionals & attAdditionals )
   {
   }
 
   CUnitOutputSetResetHss2::CUnitOutputSetResetHss2() {}

   void CUnitOutputSetResetHss2::Set( std::string & /*attSetOutput*/, [[maybe_unused]] CAdditionals & attAdditionals )
   {
   }

   CUnitOutputSetResetHss3::CUnitOutputSetResetHss3() {}

   void CUnitOutputSetResetHss3::Set( std::string & /*attSetOutput*/, [[maybe_unused]] CAdditionals & attAdditionals )
   {
   }

   CUnitOutputSetResetHss4::CUnitOutputSetResetHss4(){}

   void CUnitOutputSetResetHss4::Set( std::string & /*attSetOutput*/, [[maybe_unused]] CAdditionals & attAdditionals )
   {
   }

   CUnitInputGetHss1::CUnitInputGetHss1(){}

   void CUnitInputGetHss1::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

   CUnitInputGetHss2::CUnitInputGetHss2(){}

   void CUnitInputGetHss2::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

   CUnitInputGetHss3::CUnitInputGetHss3(){}

   void CUnitInputGetHss3::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }

   CUnitInputGetHss4::CUnitInputGetHss4(){}

   void CUnitInputGetHss4::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
      attGetInput = "TODO";
   }
}

