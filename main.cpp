/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "manager.h"
//#include "driver/hal.h"

//extern "C" void __sync_synchronize() {}

UART_HandleTypeDef huart1;
CircularBuffer<uint8_t> uart1buffer(128);

int main()
{
#if 1
   auto manager = mainunit::CManager();

  manager.DoWork();

#else

  	 mainunit::driver::CHal _hal;

	int j = 0;
   while( 1 )
   {
		  for(int i = 0; i < 1000000; i++) {
			  j++;
		  }
		  j = 0;
   }
#endif
	return 0;
}


