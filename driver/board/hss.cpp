/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck tiloseeck@web.de> */

#include "hss.h"

#include <iostream>

namespace mainunit::driver
{


   CUnitOutputSetResetHss1::CUnitOutputSetResetHss1(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitOutputSetResetHss1::Set( std::string &attSetOutput, [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   if(attSetOutput == "SET") {
		   m_hss.set(HssNr::HSSSWITCH1, true);
	   } else {
		   m_hss.set(HssNr::HSSSWITCH1, false);
	   }
   }
 
   CUnitOutputSetResetHss2::CUnitOutputSetResetHss2(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitOutputSetResetHss2::Set( std::string &attSetOutput, [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   if(attSetOutput == "SET") {
		   m_hss.set(HssNr::HSSSWITCH2, true);
	   } else {
		   m_hss.set(HssNr::HSSSWITCH2, false);
	   }
   }

   CUnitOutputSetResetHss3::CUnitOutputSetResetHss3(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitOutputSetResetHss3::Set( std::string &attSetOutput, [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   if(attSetOutput == "SET") {
		   m_hss.set(HssNr::HSSSWITCH3, true);
	   } else {
		   m_hss.set(HssNr::HSSSWITCH3, false);
	   }
   }

   CUnitOutputSetResetHss4::CUnitOutputSetResetHss4(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitOutputSetResetHss4::Set( std::string &attSetOutput, [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   if(attSetOutput == "SET") {
		   m_hss.set(HssNr::HSSSWITCH4, true);
	   } else {
		   m_hss.set(HssNr::HSSSWITCH4, false);
	   }
   }

   CUnitInputGetHss1::CUnitInputGetHss1(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitInputGetHss1::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   attGetInput = "RESET";
	   if(m_hss.get(HssNr::HSSSWITCH1))
		   attGetInput = "SET";
   }

   CUnitInputGetHss2::CUnitInputGetHss2(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitInputGetHss2::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   attGetInput = "RESET";
	   if(m_hss.get(HssNr::HSSSWITCH2))
		   attGetInput = "SET";
   }

   CUnitInputGetHss3::CUnitInputGetHss3(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitInputGetHss3::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   attGetInput = "RESET";
	   if(m_hss.get(HssNr::HSSSWITCH3))
		   attGetInput = "SET";
   }

   CUnitInputGetHss4::CUnitInputGetHss4(const CHSSDrv &hss) : m_hss(const_cast<CHSSDrv&>(hss)) {}

   void CUnitInputGetHss4::Get( std::string & attGetInput , [[maybe_unused]] CAdditionals & attAdditionals )
   {
	   attGetInput = "RESET";
	   if(m_hss.get(HssNr::HSSSWITCH4))
		   attGetInput = "SET";
   }
}

