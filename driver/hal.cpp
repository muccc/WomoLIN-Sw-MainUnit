/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "hal.h"
#include "gpio.h"
#include "spi.h"
#include "i2c.h"
#include "circularbuffer.h"
#include "led.h"
#include "lin.h"
#include "linmgr.h"

#include <iostream>

#define hK1Status_Pin 			GPIO_PIN_0
#define hK1Status_GPIO_Port 	GPIOG
#define hK2Status_Pin 			GPIO_PIN_1
#define hK2Status_GPIO_Port 	GPIOG
#define hK3Status_Pin 			GPIO_PIN_2
#define hK3Status_GPIO_Port 	GPIOG
#define hK4Status_Pin 			GPIO_PIN_3
#define hK4Status_GPIO_Port 	GPIOG
#define hRel1Reset_Pin 			GPIO_PIN_8
#define hRel1Reset_GPIO_Port 	GPIOG
#define hRel2Reset_Pin 			GPIO_PIN_15
#define hRel2Reset_GPIO_Port 	GPIOG
#define hSTBCtrl_Pin 			GPIO_PIN_9
#define hSTBCtrl_GPIO_Port 		GPIOA
#define hSignalLED_Pin 			GPIO_PIN_0
#define hSignalLED_GPIO_Port 	GPIOB
#define hLinSelA1_Pin 			GPIO_PIN_8
#define hLinSelA1_GPIO_Port 	GPIOD
#define hLinEn_Pin 				GPIO_PIN_9
#define hLinEn_GPIO_Port 		GPIOD
#define hSLPLin1_Pin 			GPIO_PIN_4
#define hSLPLin1_GPIO_Port 		GPIOG
#define hSLPLin2_Pin 			GPIO_PIN_5
#define hSLPLin2_GPIO_Port 		GPIOG
#define hSLPLin3_Pin 			GPIO_PIN_6
#define hSLPLin3_GPIO_Port 		GPIOG
#define hSLPLin4_Pin 			GPIO_PIN_7
#define hSLPLin4_GPIO_Port 		GPIOG
#define hLinSelA0_Pin 			GPIO_PIN_7
#define hLinSelA0_GPIO_Port 	GPIOD
#define hHssEn1_Pin 			GPIO_PIN_14
#define hHssEn1_GPIO_Port 		GPIOF
#define hHssEn2_Pin 			GPIO_PIN_15
#define hHssEn2_GPIO_Port 		GPIOF
#define hHss3En_Pin 			GPIO_PIN_0
#define hHss3En_GPIO_Port 		GPIOE
#define hHssEn4_Pin 			GPIO_PIN_1
#define hHssEn4_GPIO_Port 		GPIOE


namespace mainunit::driver
{
	UART_HandleTypeDef huart1;
	UART_HandleTypeDef huart2;
	SPI_HandleTypeDef hspi3;
	I2C_HandleTypeDef hi2c3;

	GPIO signalled(hSignalLED_Pin, hSignalLED_GPIO_Port);
	//CLed led(signalled);

	CI2C i2c(&hi2c3);
	CBme680Drv bme680(i2c);
	CLSM303AgrAccDrv acc(i2c);
	CLSM303AgrMagDrv mag(i2c);

	// Relay hardware configuration
	GPIO k1status(hK1Status_Pin, hK1Status_GPIO_Port);
	GPIO k2status(hK2Status_Pin, hK2Status_GPIO_Port);
	GPIO k3status(hK3Status_Pin, hK3Status_GPIO_Port);
	GPIO k4status(hK4Status_Pin, hK4Status_GPIO_Port);
	GPIO rel1reset(hRel1Reset_Pin, hRel1Reset_GPIO_Port);
	GPIO rel2reset(hRel2Reset_Pin, hRel2Reset_GPIO_Port);
	SPI spi3(&hspi3);
	RelayDrv birelay(spi3, ShiftRegNr::SHIFTREG1);
	RelayDrv extrelay(spi3, ShiftRegNr::SHIFTREG2);


	// Controlbus hardware configuration
	GPIO stbctrl(hSTBCtrl_Pin, hSTBCtrl_GPIO_Port);
	CircularBuffer<uint8_t> uart1buffer(1024);
	Uart uart1(&huart1, &uart1buffer, signalled);
	CControlbus control(uart1, stbctrl);

	// Lin bus configuration
	GPIO mpenable(hLinEn_Pin, hLinEn_GPIO_Port);
	GPIO mpa0(hLinSelA0_Pin, hLinSelA0_GPIO_Port);
	GPIO mpa1(hLinSelA1_Pin, hLinSelA1_GPIO_Port);
	CLinMultiplexer multiplexer(mpenable, mpa0, mpa1);
	GPIO slplin1(hSLPLin1_Pin, hSLPLin1_GPIO_Port);
	GPIO slplin2(hSLPLin2_Pin, hSLPLin2_GPIO_Port);
	GPIO slplin3(hSLPLin3_Pin, hSLPLin3_GPIO_Port);
	GPIO slplin4(hSLPLin4_Pin, hSLPLin4_GPIO_Port);
	CLinTransceiver transceiver(slplin1, slplin2, slplin3, slplin4);
	CircularBuffer<uint8_t> uart2buffer(128);
	CLin lin(&huart2, &uart2buffer);
	CLinManager linmgr(multiplexer, transceiver, lin);
	CHellaIBS2 ibs(linmgr);

   CHal::CHal()
        : Controlbus(control)
        , UnitInputGetHwBoardVersion()
        , UnitInputGetDriverVersion()
        , BiRelay(birelay)
        , UnitOutputSetResetBirelayK1(BiRelay)
        , UnitOutputSetResetBirelayK2(BiRelay)
        , UnitOutputSetResetBirelayK3(BiRelay)
        , UnitOutputSetResetBirelayK4(BiRelay)
        , UnitInputGetBirelayK1(k1status)
        , UnitInputGetBirelayK2(k2status)
        , UnitInputGetBirelayK3(k3status)
        , UnitInputGetBirelayK4(k4status)
   	    , ExtRelay(extrelay)
        , UnitOutputSetResetExtRelay1(ExtRelay)
        , UnitOutputSetResetExtRelay2(ExtRelay)
        , UnitOutputSetResetExtRelay3(ExtRelay)
        , UnitOutputSetResetExtRelay4(ExtRelay)
        , UnitOutputSetResetExtRelay5(ExtRelay)
        , UnitOutputSetResetExtRelay6(ExtRelay)
        , UnitOutputSetResetExtRelay7(ExtRelay)
        , UnitOutputSetResetExtRelay8(ExtRelay)
        , UnitInputGetExtRelay1(ExtRelay)
        , UnitInputGetExtRelay2(ExtRelay)
        , UnitInputGetExtRelay3(ExtRelay)
        , UnitInputGetExtRelay4(ExtRelay)
        , UnitInputGetExtRelay5(ExtRelay)
        , UnitInputGetExtRelay6(ExtRelay)
        , UnitInputGetExtRelay7(ExtRelay)
        , UnitInputGetExtRelay8(ExtRelay)
   	  	, Bme680(bme680)
        , UnitInputGetBme680Pressure(Bme680)
        , UnitInputGetBme680Temperature(Bme680)
        , UnitInputGetBme680Humidity(Bme680)
   	    , Mag(mag)
   	    , Acc(acc)
        , UnitInputGetLsm303Magnetic(Mag)
        , UnitInputGetLsm303Acceleration(Acc)
        , Ibs(ibs)
        , UnitInputGetIbsTemperature(Ibs)
        , UnitInputGetIbsVoltage(Ibs)
        , UnitInputGetIbsCurrent(Ibs)
        , UnitInputGetIbsCapacity(Ibs)
        , UnitInputGetIbsCharge(Ibs)
        , UnitInputGetIbsHealth(Ibs)
        , UnitOutputSetResetHss1(/* TODO BiRelay*/)
        , UnitOutputSetResetHss2(/* TODO BiRelay*/)
        , UnitOutputSetResetHss3(/* TODO BiRelay*/)
        , UnitOutputSetResetHss4(/* TODO BiRelay*/)
        , UnitInputGetHss1(/* TODO k1status*/)
        , UnitInputGetHss2(/* TODO k2status*/)
        , UnitInputGetHss3(/* TODO k3status*/)
        , UnitInputGetHss4(/* TODO k4status*/)
   {
	   HAL_Init();
	   __HAL_RCC_SYSCFG_CLK_ENABLE();
	   __HAL_RCC_PWR_CLK_ENABLE();
	   SystemClock_Config();
	   MX_GPIO_Init();
	   MX_USART1_UART_Init();
	   MX_USART2_UART_Init();
	   MX_SPI3_Init();
	   MX_I2C3_Init();

	   InterruptHandler::registerCallback(IRQ_SYSTICK, CHal::irqsyshandler, nullptr);

	   if(Bme680.init()) {
		   Bme680.read();
	   }

	   if(Acc.init()) {
		   Acc.read();
	   }

	   if(Mag.init()) {
		   Mag.read();
	   }

	   linmgr.setOn(true);
   }

   void CHal::SystemClock_Config()
   {
	   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	   RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

		/** Initializes the CPU, AHB and APB busses clocks
		*/
	   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	   RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	   RCC_OscInitStruct.PLL.PLLM = 2;
	   RCC_OscInitStruct.PLL.PLLN = 12;
	   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
	   RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
	   RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
	   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	   {
		  //Error_Handler();
	   }
		/** Initializes the CPU, AHB and APB busses clocks
		*/
	   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
									|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	   if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	   {
		  //Error_Handler();
	   }
	   PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2
									|RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_UART4
									|RCC_PERIPHCLK_LPUART1|RCC_PERIPHCLK_I2C1
									|RCC_PERIPHCLK_I2C2|RCC_PERIPHCLK_I2C3
									|RCC_PERIPHCLK_SDMMC1;
	   PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
	   PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
	   PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
	   PeriphClkInit.Uart4ClockSelection = RCC_UART4CLKSOURCE_PCLK1;
	   PeriphClkInit.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PCLK1;
	   PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
	   PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
	   PeriphClkInit.I2c3ClockSelection = RCC_I2C3CLKSOURCE_PCLK1;
	   PeriphClkInit.Sdmmc1ClockSelection = RCC_SDMMC1CLKSOURCE_PLLSAI1;
	   PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSE;
	   PeriphClkInit.PLLSAI1.PLLSAI1M = 2;
	   PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
	   PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
	   PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
	   PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
	   PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_48M2CLK;
	   if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
	   {
		  //Error_Handler();
	   }
		/** Configure the main internal regulator output voltage
		*/
	   if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
	   {
		  //Error_Handler();
	   }
   }

   void CHal::MX_GPIO_Init(void)
   {
	   GPIO_InitTypeDef GPIO_InitStruct = {0};

	   	/* GPIO Ports Clock Enable */
	   	__HAL_RCC_GPIOH_CLK_ENABLE();
	   	__HAL_RCC_GPIOC_CLK_ENABLE();
	   	__HAL_RCC_GPIOA_CLK_ENABLE();
	   	__HAL_RCC_GPIOB_CLK_ENABLE();
	   	__HAL_RCC_GPIOF_CLK_ENABLE();
	   	__HAL_RCC_GPIOG_CLK_ENABLE();
	   	__HAL_RCC_GPIOE_CLK_ENABLE();
	   	__HAL_RCC_GPIOD_CLK_ENABLE();
	   	HAL_PWREx_EnableVddIO2();

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(hSignalLED_GPIO_Port, hSignalLED_Pin, GPIO_PIN_RESET);

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(GPIOF, hHssEn1_Pin|hHssEn2_Pin, GPIO_PIN_RESET);

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(GPIOD, hLinSelA1_Pin|hLinEn_Pin|hLinSelA0_Pin, GPIO_PIN_RESET);

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(GPIOG, hSLPLin1_Pin|hRel1Reset_Pin, GPIO_PIN_SET);

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(GPIOG, hSLPLin2_Pin|hSLPLin3_Pin|hSLPLin4_Pin|hRel2Reset_Pin, GPIO_PIN_RESET);

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(hSTBCtrl_GPIO_Port, hSTBCtrl_Pin, GPIO_PIN_RESET);

	   	/*Configure GPIO pin Output Level */
	   	HAL_GPIO_WritePin(GPIOE, hHss3En_Pin|hHssEn4_Pin, GPIO_PIN_RESET);

	   	/*Configure GPIO pin : hSignalLED_Pin */
	   	GPIO_InitStruct.Pin = hSignalLED_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   	HAL_GPIO_Init(hSignalLED_GPIO_Port, &GPIO_InitStruct);

	   	/*Configure GPIO pins : hHssEn1_Pin hHssEn2_Pin */
	   	GPIO_InitStruct.Pin = hHssEn1_Pin|hHssEn2_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

	   	/*Configure GPIO pins : hK1Status_Pin hK2Status_Pin hK3Status_Pin hK4Status_Pin */
	   	GPIO_InitStruct.Pin = hK1Status_Pin|hK2Status_Pin|hK3Status_Pin|hK4Status_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	   	/*Configure GPIO pins : hLinSelA1_Pin hLinEn_Pin hLinSelA0_Pin */
	   	GPIO_InitStruct.Pin = hLinSelA1_Pin|hLinEn_Pin|hLinSelA0_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	   	/*Configure GPIO pins : hSLPLin1_Pin hSLPLin2_Pin hSLPLin3_Pin hSLPLin4_Pin
	   						   hRel1Reset_Pin hRel2Reset_Pin */
	   	GPIO_InitStruct.Pin = hSLPLin1_Pin|hSLPLin2_Pin|hSLPLin3_Pin|hSLPLin4_Pin
	   						  |hRel1Reset_Pin|hRel2Reset_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	   	/*Configure GPIO pin : hSTBCtrl_Pin */
	   	GPIO_InitStruct.Pin = hSTBCtrl_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   	HAL_GPIO_Init(hSTBCtrl_GPIO_Port, &GPIO_InitStruct);

	   	/*Configure GPIO pins : hHss3En_Pin hHssEn4_Pin */
	   	GPIO_InitStruct.Pin = hHss3En_Pin|hHssEn4_Pin;
	   	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   	GPIO_InitStruct.Pull = GPIO_NOPULL;
	   	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
   }

	void CHal::MX_USART1_UART_Init()
	{
		huart1.Instance = USART1;
		huart1.Init.BaudRate = 115200;
		huart1.Init.WordLength = UART_WORDLENGTH_8B;
		huart1.Init.StopBits = UART_STOPBITS_1;
		huart1.Init.Parity = UART_PARITY_NONE;
		huart1.Init.Mode = UART_MODE_TX_RX;
		huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		huart1.Init.OverSampling = UART_OVERSAMPLING_16;
		huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
		huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
		if (HAL_UART_Init(&huart1) != HAL_OK)
		{
			//Error_Handler();
			//return;
		}
	}

	void CHal::MX_USART2_UART_Init(void)
	{
		huart2.Instance = USART2;
		huart2.Init.BaudRate = 19200;
		huart2.Init.WordLength = UART_WORDLENGTH_8B;
		huart2.Init.StopBits = UART_STOPBITS_1;
		huart2.Init.Parity = UART_PARITY_NONE;
		huart2.Init.Mode = UART_MODE_TX_RX;
		huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		huart2.Init.OverSampling = UART_OVERSAMPLING_16;
		huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
		huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
		//if (HAL_UART_Init(&huart2) != HAL_OK)
		if (HAL_LIN_Init(&huart2, UART_LINBREAKDETECTLENGTH_11B) != HAL_OK)
		{
			//Error_Handler();
		}
	}

	void CHal::MX_SPI3_Init()
	{

		/* USER CODE BEGIN SPI3_Init 0 */

		/* USER CODE END SPI3_Init 0 */

		/* USER CODE BEGIN SPI3_Init 1 */

		/* USER CODE END SPI3_Init 1 */
		/* SPI3 parameter configuration*/
		hspi3.Instance = SPI3;
		hspi3.Init.Mode = SPI_MODE_MASTER;
		hspi3.Init.Direction = SPI_DIRECTION_2LINES;
		hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
		hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
		hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
		hspi3.Init.NSS = SPI_NSS_HARD_OUTPUT;
		hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
		hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
		hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
		hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
		hspi3.Init.CRCPolynomial = 7;
		hspi3.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
		hspi3.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
		if (HAL_SPI_Init(&hspi3) != HAL_OK)
		{
		//Error_Handler();
		}
		/* USER CODE BEGIN SPI3_Init 2 */

		/* USER CODE END SPI3_Init 2 */

	}

	void CHal::MX_I2C3_Init()
	{
		hi2c3.Instance = I2C3;
		hi2c3.Init.Timing = 0x109093DC;
		hi2c3.Init.OwnAddress1 = 0;
		hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
		hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
		hi2c3.Init.OwnAddress2 = 0;
		hi2c3.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
		hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
		hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
		if (HAL_I2C_Init(&hi2c3) != HAL_OK)
		{
			//Error_Handler();
		}
		/** Configure Analogue filter
		*/
		if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
		{
			//Error_Handler();
		}
		/** Configure Digital filter
		*/
		if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
		{
			//Error_Handler();
		}
	}

    void CHal::irqsyshandler(void */*param*/)
	{
		HAL_IncTick();
	}

#if 1
   siguni::interface::IControlbus & CHal::GetHandleControlbus()
   {
      return Controlbus;//control;
   }


	siguni::interface::IUnitInputGetHwBoardVersion & CHal::GetHandleUnitInputGetHwBoardVersion() { return UnitInputGetHwBoardVersion; }
	siguni::interface::IUnitInputGetDriverVersion & CHal::GetHandleUnitInputGetDriverVersion() {return UnitInputGetDriverVersion; }

    IUnitOutputSetResetBirelayK1 & CHal::GetHandleUnitOutputSetResetBirelayK1() { return UnitOutputSetResetBirelayK1; }
    IUnitOutputSetResetBirelayK2 & CHal::GetHandleUnitOutputSetResetBirelayK2() { return UnitOutputSetResetBirelayK2; }
    IUnitOutputSetResetBirelayK3 & CHal::GetHandleUnitOutputSetResetBirelayK3() { return UnitOutputSetResetBirelayK3; }
    IUnitOutputSetResetBirelayK4 & CHal::GetHandleUnitOutputSetResetBirelayK4() { return UnitOutputSetResetBirelayK4; }

    IUnitInputGetBirelayK1 & CHal::GetHandleUnitInputGetBirelayK1() { return UnitInputGetBirelayK1; }
    IUnitInputGetBirelayK2 & CHal::GetHandleUnitInputGetBirelayK2() { return UnitInputGetBirelayK2; }
    IUnitInputGetBirelayK3 & CHal::GetHandleUnitInputGetBirelayK3() { return UnitInputGetBirelayK3; }
    IUnitInputGetBirelayK4 & CHal::GetHandleUnitInputGetBirelayK4() { return UnitInputGetBirelayK4; }


	IUnitOutputSetResetExtRelay1 & CHal::GetHandleUnitOutputSetResetExtRelay1() { return UnitOutputSetResetExtRelay1; }
	IUnitOutputSetResetExtRelay2 & CHal::GetHandleUnitOutputSetResetExtRelay2() { return UnitOutputSetResetExtRelay2; }
	IUnitOutputSetResetExtRelay3 & CHal::GetHandleUnitOutputSetResetExtRelay3() { return UnitOutputSetResetExtRelay3; }
	IUnitOutputSetResetExtRelay4 & CHal::GetHandleUnitOutputSetResetExtRelay4() { return UnitOutputSetResetExtRelay4; }
	IUnitOutputSetResetExtRelay5 & CHal::GetHandleUnitOutputSetResetExtRelay5() { return UnitOutputSetResetExtRelay5; }
	IUnitOutputSetResetExtRelay6 & CHal::GetHandleUnitOutputSetResetExtRelay6() { return UnitOutputSetResetExtRelay6; }
	IUnitOutputSetResetExtRelay7 & CHal::GetHandleUnitOutputSetResetExtRelay7() { return UnitOutputSetResetExtRelay7; }
	IUnitOutputSetResetExtRelay8 & CHal::GetHandleUnitOutputSetResetExtRelay8() { return UnitOutputSetResetExtRelay8; }

	IUnitInputGetExtRelay1 & CHal::GetHandleUnitInputGetExtRelay1() { return UnitInputGetExtRelay1; }
	IUnitInputGetExtRelay2 & CHal::GetHandleUnitInputGetExtRelay2() { return UnitInputGetExtRelay2; }
	IUnitInputGetExtRelay3 & CHal::GetHandleUnitInputGetExtRelay3() { return UnitInputGetExtRelay3; }
	IUnitInputGetExtRelay4 & CHal::GetHandleUnitInputGetExtRelay4() { return UnitInputGetExtRelay4; }
	IUnitInputGetExtRelay5 & CHal::GetHandleUnitInputGetExtRelay5() { return UnitInputGetExtRelay5; }
	IUnitInputGetExtRelay6 & CHal::GetHandleUnitInputGetExtRelay6() { return UnitInputGetExtRelay6; }
	IUnitInputGetExtRelay7 & CHal::GetHandleUnitInputGetExtRelay7() { return UnitInputGetExtRelay7; }
	IUnitInputGetExtRelay8 & CHal::GetHandleUnitInputGetExtRelay8() { return UnitInputGetExtRelay8; }

	IUnitInputGetBme680Pressure &    CHal::GetHandleUnitInputGetBme680Pressure() { return UnitInputGetBme680Pressure; }
	IUnitInputGetBme680Temperature & CHal::GetHandleUnitInputGetBme680Temperature() { return UnitInputGetBme680Temperature; }
	IUnitInputGetBme680Humidity &    CHal::GetHandleUnitInputGetBme680Humidity() { return UnitInputGetBme680Humidity; }

    IUnitInputGetLsm303Magnetic &     CHal::GetHandleUnitInputGetLsm303Magnetic() { return UnitInputGetLsm303Magnetic; }
    IUnitInputGetLsm303Acceleration & CHal::GetHandleUnitInputGetLsm303Acceleration() { return UnitInputGetLsm303Acceleration; }
   
    IUnitInputGetIbsTemperature &     CHal::GetHandleUnitInputGetIbsTemperature() { return UnitInputGetIbsTemperature; }
    IUnitInputGetIbsVoltage &         CHal::GetHandleUnitInputGetIbsVoltage() { return UnitInputGetIbsVoltage; }
    IUnitInputGetIbsCurrent &         CHal::GetHandleUnitInputGetIbsCurrent() { return UnitInputGetIbsCurrent; }
    IUnitInputGetIbsCapacity &        CHal::GetHandleUnitInputGetIbsCapacity() { return UnitInputGetIbsCapacity; }
    IUnitInputGetIbsCharge &          CHal::GetHandleUnitInputGetIbsCharge() { return UnitInputGetIbsCharge; }
    IUnitInputGetIbsHealth &          CHal::GetHandleUnitInputGetIbsHealth() { return UnitInputGetIbsHealth; }

    IUnitOutputSetResetHss1 & CHal::GetHandleUnitOutputSetResetHss1() { return UnitOutputSetResetHss1; }
    IUnitOutputSetResetHss2 & CHal::GetHandleUnitOutputSetResetHss2() { return UnitOutputSetResetHss2; }
    IUnitOutputSetResetHss3 & CHal::GetHandleUnitOutputSetResetHss3() { return UnitOutputSetResetHss3; }
    IUnitOutputSetResetHss4 & CHal::GetHandleUnitOutputSetResetHss4() { return UnitOutputSetResetHss4; }

    IUnitInputGetHss1 & CHal::GetHandleUnitInputGetHss1() { return UnitInputGetHss1; }
    IUnitInputGetHss2 & CHal::GetHandleUnitInputGetHss2() { return UnitInputGetHss2; }
    IUnitInputGetHss3 & CHal::GetHandleUnitInputGetHss3() { return UnitInputGetHss3; }
    IUnitInputGetHss4 & CHal::GetHandleUnitInputGetHss4() { return UnitInputGetHss4; }


#endif

}

