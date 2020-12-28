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
#include "uart_test.h"
#include "string.h"
#include "overtime.h"
#include "xl_uart.h"
#include "xl_sim.h"
/*******************************************************************************
* Constants and macros
*******************************************************************************/
typedef struct
{
	UART_Type*                          port;
	uint8_t  							mapping;	
	uint32_t		 					baudrate;	
	uint32_t							wordlength;
	uint32_t							stopbits;
	uint32_t 							parity;
}UART_TEST_INFO_T;

static UART_TEST_INFO_T sTestInfo={0};
/******************************************************************************
* Global variables
******************************************************************************/
/******************************************************************************
* Private function prototypes
******************************************************************************/
static void UART_Open(void)
{	
	//UART≥ı ºªØ
	UART_InitTypeDef UART_InitStructure;

	if(sTestInfo.port == UART0)
	{
		SIM_SCGC_Cmd(SIM_SCGC_UART0,ENABLE);
	}
	else if(sTestInfo.port == UART1)
	{
		SIM_SCGC_Cmd(SIM_SCGC_UART1,ENABLE);
	}
	else if(sTestInfo.port == UART2)
	{
		SIM_SCGC_Cmd(SIM_SCGC_UART2,ENABLE);
	}
	
	UART_InitStructure.UART_SourceClk= Get_PeripheralClock();
	UART_InitStructure.UART_BaudRate = sTestInfo.baudrate;
	UART_InitStructure.UART_DataLength = sTestInfo.wordlength;
	UART_InitStructure.UART_StopBits = sTestInfo.stopbits;
	UART_InitStructure.UART_Parity = sTestInfo.parity;
	
	UART_Init(sTestInfo.port, &UART_InitStructure);
	UART_EnableCmd(sTestInfo.port, ENABLE);
}

static void UART_Close(void)
{
	UART_DeInit(sTestInfo.port);
}

/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t UART_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{	
	uint32_t count;
	
	uint8_t  ret = ERROR;
	for(count=0; count<*tx_len; count++)
	{
		while(!UART_GetLineStatus(sTestInfo.port, UART_LSRTHREmpty)){};
    	UART_SendData(sTestInfo.port, (uint8_t) tx_memory[count]);
	}
	while(!UART_GetLineStatus(sTestInfo.port, UART_LSRTHREmpty)){};
	ret = SUCCESS;
	
	return ret;
}

/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t UART_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	uint32_t count = 0;
	uint8_t  ret = ERROR;

	set_overtime(3000);
	while((!get_overtime()) && (count  < *rx_len))
	{
		if(UART_GetLineStatus(sTestInfo.port, UART_LSRDataReady))
		{
			rx_momory[count++] = UART_ReceiveData(sTestInfo.port);
		}
	}
	return ret;
}

static uint8_t UART_Polling_TXRX_L(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len, uint32_t flag)
{
	uint32_t rx_count = 0 , tx_count = 0;
	uint8_t  ret = ERROR;
	
	set_overtime(5000);
	while((!get_overtime()) && ((rx_count  < *rx_len) || (tx_count  < *tx_len)))
	{
		if(UART_GetLineStatus(sTestInfo.port, UART_LSRDataReady))
		{
			if(flag == 0)
			{
				flag = 1;
			}
			rx_momory[rx_count++] = UART_ReceiveData(sTestInfo.port);
		}
		
		if((tx_count < *tx_len) && (flag == 1))
		{
			if(UART_GetLineStatus(sTestInfo.port, UART_LSRTHREmpty))
			{
				UART_SendData(sTestInfo.port, tx_memory[tx_count++]);
			}
		}
	}
	return ret;
}

/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t UART_Polling_TXRX_W(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	return UART_Polling_TXRX_L(rx_momory, rx_len, tx_memory, tx_len, 0);
}

/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t UART_Polling_TXRX_R(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	return UART_Polling_TXRX_L(rx_momory, rx_len, tx_memory, tx_len, 1);
}

/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t UART_Config(uint32_t address, uint32_t data)
{
	uint8_t  ret;
	sTestInfo.port = UART0;
	
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				UART_Open();
			}
			else
			{
				UART_Close();
			}
			break;
		
		case 0x04:
			sTestInfo.baudrate = data;
			break;
		case 0x08:
			if(data&0x01)
			{
				//sTestInfo.wordlength = UART_DataLength_9b;
				sTestInfo.wordlength = UART_DataLength_8b;
			}
			else
			{
				sTestInfo.wordlength = UART_DataLength_8b;
			}
			break;
		case 0x0c:
			if(data&0x01)
			{
				sTestInfo.stopbits = UART_StopBits_2;
			}
			else
			{
				sTestInfo.stopbits = UART_StopBits_1;
			}
			break;
		case 0x10:
			if((data&0x03) == 0x02)
			{
				sTestInfo.parity = UART_StickParity_Odd;
			}
			else if((data&0x03) == 0x01)
			{
				sTestInfo.parity = UART_Parity_Even;
			}
			else
			{
				sTestInfo.parity = UART_Parity_No;
			}
			break;
	}
	
	return ret;
}
/******************************************************************************
* end of file
******************************************************************************/
