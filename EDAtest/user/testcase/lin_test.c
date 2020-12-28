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
#include "lin_test.h"
#include "string.h"
#include "overtime.h"





/*******************************************************************************
* Constants and macros
*******************************************************************************/
//typedef struct
//{
//	UART_HandleTypeDef*  	port;
//	uint8_t  							mapping;	
//	uint8_t 							*pattern;
//	uint32_t		 					baudrate;	
//}LIN_TEST_INFO_T;
uint8_t TestPid = 0x10;
uint8_t TestLength = 0x08;

typedef struct
{
	uint8_t  							mapping;	
	uint32_t		 					baudrate;	
	uint32_t							wordlength;
	uint32_t							stopbits;
	uint32_t 							parity;
}LIN_UART_TEST_INFO_T;

static LIN_UART_TEST_INFO_T sTestInfo={0};


static uint32_t rx_count;
static uint32_t tx_count;
static uint32_t rx_error_count;
//static LIN_TEST_INFO_T sTestInfo={0};
/******************************************************************************
* Global variables
******************************************************************************/
/******************************************************************************
* Private function prototypes
******************************************************************************/
uint8_t LIN_CalcParity(uint8_t id)
{
  uint8_t parity, p0,p1;
  parity=id;
  p0=(BIT(parity,0)^BIT(parity,1)^BIT(parity,2)^BIT(parity,4))<<6;     //偶校验位
  p1=(!(BIT(parity,1)^BIT(parity,3)^BIT(parity,4)^BIT(parity,5)))<<7;  //奇校验位
  parity|=(p0|p1);
  return parity;
}

/******************************************************************************
* Private function prototypes
******************************************************************************/
uint8_t LIN_Checksum(uint8_t id,uint8_t *data,uint8_t length)
{
	uint8_t i;
	uint32_t check_sum = 0;
	if(id != 0x3c && id != 0x7d)  		//使用增强型校验
	{
		check_sum  = id ;
	}
	else 															//使用标准校验
	{
		check_sum = 0 ;
	}
	for (i = 0; i < length; i++)
	{         
		check_sum += *(data++);
		if (check_sum > 0xFF)          	//进位
		{
			check_sum -= 0xFF;
		}
	}
	return (~check_sum);  						//取反
}

/******************************************************************************
* Private function prototypes
******************************************************************************/
void LIN_Open()
{	
/*
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = LIN_XL6600_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
	HAL_GPIO_WritePin(GPIOG, LIN_XL6600_EN_Pin, GPIO_PIN_SET);
	
	 MX_USART2_UART_Init(sTestInfo.baudrate, sTestInfo.wordlength, sTestInfo.stopbits, sTestInfo.parity);
	
	__HAL_UART_CLEAR_FLAG(sTestInfo.port, UART_FLAG_RXNE);
	__HAL_UART_CLEAR_PEFLAG(sTestInfo.port);
	__HAL_UART_CLEAR_FLAG(sTestInfo.port, UART_FLAG_LBD);
	
	sTestInfo.port->Instance->CR2 |= USART_CR2_LINEN;
	*/
}

/******************************************************************************
* Private function prototypes
******************************************************************************/
void LIN_Close()
{	
	/*
	sTestInfo.port->Instance->CR2 &= (~USART_CR2_LINEN);
	*/
}

/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t LIN_Config(uint32_t address, uint32_t data)
{
	/*
	uint8_t  ret;
	sTestInfo.port = &huart2;
	
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				LIN_Open();
			}
			else
			{
				LIN_Close();
			}
			break;
		
		case 0x04:
			sTestInfo.baudrate = data;
			break;
		case 0x08:
			if(data&0x01)
			{
				sTestInfo.wordlength = UART_WORDLENGTH_9B;
			}
			else
			{
				sTestInfo.wordlength = UART_WORDLENGTH_8B;
			}
			break;
		case 0x0c:
			if(data&0x01)
			{
				sTestInfo.stopbits = UART_STOPBITS_2;
			}
			else
			{
				sTestInfo.stopbits = UART_STOPBITS_1;
			}
			break;
		case 0x10:
			if((data&0x03) == 0x02)
			{
				sTestInfo.parity = UART_PARITY_ODD;
			}
			else if((data&0x03) == 0x01)
			{
				sTestInfo.parity = UART_PARITY_EVEN;
			}
			else
			{
				sTestInfo.parity = UART_PARITY_NONE;
			}
			break;
	}
	
	return ret;
	*/
}
/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
ErrorStatus LIN_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{	
	/*
	ErrorStatus  ret = ERROR;
	uint32_t i ;
	set_overtime(10000);
	HAL_LIN_SendBreak(sTestInfo.port);
	while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TXE) != SET);
	sTestInfo.port->Instance->DR = (0x55 & (uint16_t)0x00FF);

	
	if(tx_memory[0]== TestPid)
	{
		while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TXE) != SET);
	  sTestInfo.port->Instance->DR = (tx_memory[0] & (uint16_t)0x00FF);
		for(i=0;i< 3;i++)
		{
			while((__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_RXNE) != SET)&&(!get_overtime()))
			{;}
			if((!get_overtime()))
			{
			  rx_momory[i] = (uint8_t)(sTestInfo.port->Instance->DR);
			}else
			{break;}
		}
		for(i=0;i< TestLength;i++)
		{
			 while((__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_RXNE) != SET)&&(!get_overtime()))
			 {;}
			 if((!get_overtime()))
			 { 
			   rx_momory[i] = (uint8_t)(sTestInfo.port->Instance->DR);
			 }else
			{break;}
		}
		ret = SUCCESS;
	  
		return ret;
	}
	else
	{
		  while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TXE) != SET);
			sTestInfo.port->Instance->DR = (LIN_CalcParity(0) & (uint16_t)0x00FF);
	}
	
	for(i=0;i< * tx_len;i++)
	{
		while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TXE) != SET)
		{;}
		sTestInfo.port->Instance->DR = (tx_memory[i] & (uint16_t)0x00FF);
	}
	while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TXE) != SET);
	sTestInfo.port->Instance->DR = (LIN_Checksum(0, tx_memory, * tx_len) & (uint16_t)0x00FF);
	while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TC) == RESET);
	ret = SUCCESS;
  return ret;
  */
}


/*******************************************************************************
* Function Name  : main
* Description    : main function 
*******************************************************************************/
uint8_t LIN_DATA_LEN = 0;
uint8_t LIN_DATA_SIZE = 64;
ErrorStatus LIN_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	uint8_t  sys,head,pid,i;
	ErrorStatus  ret = ERROR;
	uint8_t lin_receive_state = LIN_RECEVE_START;
	LIN_DATA_LEN = 0;
	memset(rx_momory,0x00,(*rx_len+1));
	set_overtime(10000);
	while((!get_overtime()) && (LIN_DATA_LEN  < (*rx_len+1)))
	{
		if((__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_LBD) == SET))
		{
			__HAL_UART_CLEAR_FLAG(sTestInfo.port, UART_FLAG_LBD);
			LIN_DATA_LEN = 0;
			lin_receive_state = LIN_RECEVE_SYNC;
		}
		
		if(lin_receive_state != LIN_RECEVE_START)
	  {
				if((sTestInfo.port->Instance->SR & UART_FLAG_RXNE) == UART_FLAG_RXNE)
				{
					switch(lin_receive_state)
					{
						case LIN_RECEVE_SYNC:
							sys = sTestInfo.port->Instance->DR;
							lin_receive_state = LIN_RECEVE_HEAD;
						break;
						
						case LIN_RECEVE_HEAD:
							head = sTestInfo.port->Instance->DR;
							lin_receive_state = LIN_RECEVE_PID;
						break;
						
						case LIN_RECEVE_PID:
							pid = sTestInfo.port->Instance->DR;
						  if(pid == TestPid)
							{
							  	for(i=0;i<8;i++)
									{
										while(__HAL_UART_GET_FLAG(sTestInfo.port, UART_FLAG_TXE) != SET)
										{;}
										sTestInfo.port->Instance->DR = ((i+1) & 0xFF);
									}
									lin_receive_state = LIN_RECEVE_START;
							}
							else
							{
								lin_receive_state = LIN_RECEVE_DATA0;
							}
						break;
						
						case LIN_RECEVE_DATA0:
							  if(LIN_DATA_LEN < LIN_DATA_SIZE)
									rx_momory[LIN_DATA_LEN++] = (uint8_t)(sTestInfo.port->Instance->DR);
								if(LIN_DATA_LEN == LIN_DATA_SIZE)
									lin_receive_state = LIN_RECEVE_CHECK;
						break;
			
						case LIN_RECEVE_CHECK:
							rx_momory[LIN_DATA_LEN++] = sTestInfo.port->Instance->DR;
							lin_receive_state = LIN_RECEVE_START;
						  ret = SUCCESS;
						break;
					}
				}
			}
	}
	return ret;
	*/
}
/******************************************************************************
* end of file
******************************************************************************/
