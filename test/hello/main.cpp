/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <myronfranze@web.de> */

#include "hal.h"
#include "controlbus.h"

extern "C" void __sync_synchronize() {}

int main()
{
	auto hal = mainunit::driver::CHal();

	auto &controlbus = hal.GetHandleControlbus();

	while(1)
	{
		controlbus.WriteData("Hello WomoLIN\r\n");
		HAL_Delay(1000);
	}

	return 0;
}


