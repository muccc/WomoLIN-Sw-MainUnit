/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "manager.h"

extern "C" void __sync_synchronize() {}

//UART_HandleTypeDef huart1;
//CircularBuffer<uint8_t> uart1buffer(128);

int main()
{
	auto manager = mainunit::CManager();

	manager.DoWork();

	return 0;
}


