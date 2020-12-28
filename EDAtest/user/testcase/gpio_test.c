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
#include "gpio_test.h"
#include "string.h"
#include "overtime.h"
/*******************************************************************************
* Constants and macros
*******************************************************************************/


/******************************************************************************
* Global variables
******************************************************************************/
typedef struct
{
	uint8_t dir;
}GPIO_TEST_INFO_T;

static GPIO_TEST_INFO_T sTestInfo={0};

/******************************************************************************
* Private function prototypes
******************************************************************************/
static void GPIO_Open(uint32_t dir)
{
	/*
	GPIO_InitTypeDef GPIO_InitStruct;
	
	if(dir == 1)
	{
		GPIO_InitStruct.Pin = CLK_PIN;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(CLK_PORT, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = DATA_PIN;
		HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct);
	
		HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_RESET);	
		HAL_GPIO_WritePin(DATA_PORT, DATA_PIN, GPIO_PIN_RESET);
	}
	else
	{
		GPIO_InitStruct.Pin = CLK_PIN;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(CLK_PORT, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = DATA_PIN;
		HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct);
	}
	*/
}

uint8_t GPIO_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{	
	/*
	uint32_t count;
	
	uint8_t  ret = ERROR;
	for(count=0; count<*tx_len; count++)
	{
		for(int8_t i = 7; i >= 0; i--)
		{
			HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_RESET);	
			if((tx_memory[count] >> i)&1)
			{
				HAL_GPIO_WritePin(DATA_PORT, DATA_PIN, GPIO_PIN_SET);	
			}
			else
			{
				HAL_GPIO_WritePin(DATA_PORT, DATA_PIN, GPIO_PIN_RESET);	
			}
			for(uint32_t j=0; j < 0x1Fff;j++);
			HAL_GPIO_WritePin(CLK_PORT, CLK_PIN, GPIO_PIN_SET);	
			for(uint32_t j=0; j < 0x1Fff;j++);
		}
	}
	
	return ret;
	*/
}

uint8_t GPIO_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	uint32_t count = 0;
	uint8_t  ret = ERROR;
	uint8_t read_flag=0,data=0,bit_count=0;

	set_overtime(3000);
	while((!get_overtime()) && (count  < *rx_len))
	{
		if(read_flag)
		{
			if(HAL_GPIO_ReadPin(CLK_PORT, CLK_PIN) == GPIO_PIN_SET)
			{
				if(HAL_GPIO_ReadPin(DATA_PORT, DATA_PIN) == GPIO_PIN_SET)
				{
					data += (0x01 << (7-bit_count));
				}
				bit_count++;
				if(bit_count >= 8)
				{
					rx_momory[count++] = data;
					data = 0;
					bit_count = 0;
				}
				read_flag = 0;
			}
		}
		else
		{
			if(HAL_GPIO_ReadPin(CLK_PORT, CLK_PIN) == GPIO_PIN_RESET)
			{
				read_flag = 1;
			}
		}
	}

	return ret;
	*/
}

uint8_t GPIO_Config(uint32_t address, uint32_t data)
{
	/*
	uint8_t  ret;

	switch(address&0x0F)
	{
		case 0x00:
			if(data&0x01)
			{
				GPIO_Open(sTestInfo.dir);
			}
			break;
		
		case 0x04:
			sTestInfo.dir = data;
		break;
	}
	
	return ret;
	*/
}
/******************************************************************************
* end of file
******************************************************************************/
