/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l4xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L4xx_IT_H
#define __STM32L4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

#define IRQ_SYSTICK	0

 typedef void (*irqcallback)(void*);

typedef struct irq_s
{
	irqcallback cb;
	void *param;
} irq_t;


class InterruptHandler
{
public:
	 InterruptHandler();
 	 virtual ~InterruptHandler();

 	 static void registerCallback(unsigned int irqn, irqcallback cb, void *param);

private:
 	static void NMI_Handler(void);
 	static void HardFault_Handler(void);
 	static void MemManage_Handler(void);
 	static void BusFault_Handler(void);
 	static void UsageFault_Handler(void);
 	static void SVC_Handler(void);
 	static void DebugMon_Handler(void);
 	static void PendSV_Handler(void);
 	static void SysTick_Handler(void);
 	static void USART1_IRQHandler(void);
 	static void USART2_IRQHandler(void);

private:

 	static irq_t irqhandler[2];

};

/* Exported functions prototypes ---------------------------------------------*/
#if 0
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
#endif
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L4xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
