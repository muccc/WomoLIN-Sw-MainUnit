/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include "stm32l4xx_it.h"

irq_t InterruptHandler::irqhandler[IRQ_MAX];

InterruptHandler::InterruptHandler()
{

}

InterruptHandler::~InterruptHandler()
{

}

void InterruptHandler::registerCallback(unsigned int irqn, irqcallback cb, void *param)
{
	InterruptHandler::irqhandler[irqn].cb = cb;
	InterruptHandler::irqhandler[irqn].param = param;
}
#if 0
void InterruptHandler::NMI_Handler(void)
{

}

void InterruptHandler::HardFault_Handler(void)
{
	while(1)
	{

	}
}

void InterruptHandler::MemManage_Handler(void)
{
	while(1)
	{

	}
}

void InterruptHandler::BusFault_Handler(void)
{
	while(1)
	{

	}
}

void InterruptHandler::UsageFault_Handler(void)
{
	while(1)
	{

	}
}

void InterruptHandler::SVC_Handler(void)
{

}

void InterruptHandler::DebugMon_Handler(void)
{

}

void InterruptHandler::PendSV_Handler(void)
{

}

void InterruptHandler::SysTick_Handler(void)
{
	if(InterruptHandler::irqhandler[IRQ_SYSTICK].cb != nullptr)
		InterruptHandler::irqhandler[IRQ_SYSTICK].cb(InterruptHandler::irqhandler[IRQ_SYSTICK].param);
}

void InterruptHandler::USART1_IRQHandler(void)
{
	if(InterruptHandler::irqhandler[IRQ_UART1].cb != nullptr)
		InterruptHandler::irqhandler[IRQ_UART1].cb(InterruptHandler::irqhandler[IRQ_UART1].param);
}

void InterruptHandler::USART2_IRQHandler(void)
{

}

#else

#include "stm32l4xx_it.h"


/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{

}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{

}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{

}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{

	if(InterruptHandler::irqhandler[IRQ_SYSTICK].cb != nullptr)
		InterruptHandler::irqhandler[IRQ_SYSTICK].cb(InterruptHandler::irqhandler[IRQ_SYSTICK].param);
}

/******************************************************************************/
/* STM32L4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l4xx.s).                    */
/******************************************************************************/
/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{

	if(InterruptHandler::irqhandler[IRQ_UART1].cb != nullptr)
		InterruptHandler::irqhandler[IRQ_UART1].cb(InterruptHandler::irqhandler[IRQ_UART1].param);

}
/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
	if(InterruptHandler::irqhandler[IRQ_UART1].cb != nullptr)
		InterruptHandler::irqhandler[IRQ_UART1].cb(InterruptHandler::irqhandler[IRQ_UART1].param);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#endif
