/******************************************************************************
 ** Copyright:      2016 by Chipways Communications,Inc. All Rights Reserved.
 **                 This software is supplied under the terms of a license
 **                 agreement or non-disclosure agreement with Chipways.
 **                 Passing on and copying of this document,and communication
 **                 of its contents is not permitted without prior written
 **                 authorization.
 ****************************************************************************//*!
 ** File Name: main.c
 **
 ** Author: Leo Feng
 **
 ** Version: V1.0
 **
 ** Date: 2018.01.28
 **
 ** Description: This file contains the main function.
 ******************************************************************************

 ******************************************************************************
 **                        Revision History
 ** --------------------------------------------------------------------------
 ** Date           revision           Description
 **---------------------------------------------------------------------------
 ** 2018.01.28        V1.0           initial revision
 **
 **
 ******************************************************************************/
#include "osc_test.h"
#include "overtime.h"
#include "gpio_test.h"
/*******************************************************************************
* Constants and macros
*******************************************************************************/
typedef struct
{
	uint8_t  							mode;	
	uint32_t		 					period;	
	uint8_t  							duty;	
}FTM_TEST_INFO_T;



uint8_t OSC_Config(uint32_t address, uint32_t data)
{
	/*
	uint8_t  ret;
	switch(address&0xFF)
	{
		case 0x00:
			
			break;		
		case 0x04:			
		  HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_RESET);
      HAL_Delay(2);	
      HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_SET);
      HAL_Delay(2);		
		  count_init();
			break;
		default:
			break;
	}
	return ret;
	*/
}


