/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "manager.h"

extern "C" void __sync_synchronize() {}

int main() {

   auto manager = pcsim::CManager();

   manager.DoWork();

	return 0;
}


