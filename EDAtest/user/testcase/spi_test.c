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
#include "spi_test.h"
#include "overtime.h"
/*******************************************************************************
* Constants and macros
*******************************************************************************/
typedef struct
{
	uint8_t 				isMaster;
	uint8_t 				MSB;
	uint8_t               	CLKPolarity;
	uint8_t 				CLKPhase;
	uint32_t		 		baudrate;
	uint8_t               	longpack;
}SPI_TEST_INFO_T;

static SPI_TEST_INFO_T sTestInfo={0};

static void SPI_Open(uint32_t baudrate)
{	
	/*
	__HAL_SPI_DISABLE((SPI_HandleTypeDef *)sTestInfo.port);	
	HAL_SPI_MspDeInit((SPI_HandleTypeDef *)sTestInfo.port);
	
	spi1_config.Master      = sTestInfo.isMaster?SPI_MODE_MASTER:SPI_MODE_SLAVE;  //SPI工作模式
	spi1_config.MSB         = sTestInfo.MSB?SPI_FIRSTBIT_LSB:SPI_FIRSTBIT_MSB;
	spi1_config.CLKPolarity = sTestInfo.CLKPolarity?SPI_POLARITY_LOW:SPI_POLARITY_HIGH;//SPI
	spi1_config.CLKPhase    = sTestInfo.CLKPhase?SPI_PHASE_2EDGE:SPI_PHASE_1EDGE;
	
	switch(sTestInfo.baudrate)
	{
		case 24000000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_8;
		  break;
		case 12000000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_16;
		  break;
		case 6000000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_32;
		  break;
		case 3000000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_64;
		  break;
		case 1500000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_128;
		  break;
		case 750000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_256;
		  break;
		case 375000:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_256;
		  break;
		case 187500:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_256;
		  break;
		default:
			spi1_config.Baudrate = SPI_BAUDRATEPRESCALER_128;
		  break;
	}
	
	HAL_SPI_DeInit(&hspi1);
	MX_SPI1_Init();
	__HAL_SPI_ENABLE((SPI_HandleTypeDef *)sTestInfo.port);	
	
	 sTestInfo.port->Instance->DR;
	 */
}

uint8_t SPI_Config(uint32_t address, uint32_t data)
{
	/*
	uint8_t  ret;
	sTestInfo.port = &hspi1;
	
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				SPI_Open(sTestInfo.baudrate);
			}
			else
			{
				HAL_SPI_DeInit((SPI_HandleTypeDef *)sTestInfo.port);
			}
			break;
		
		case 0x04:
			sTestInfo.baudrate = data;
			break;
		case 0x08:
			sTestInfo.isMaster = data;
			break;
		case 0x0C:
			sTestInfo.CLKPolarity = data;
			break;
		case 0x10:
			sTestInfo.CLKPhase = data;
			break;
		case 0x14:
			sTestInfo.MSB = data;
			break;
		case 0x18:
			sTestInfo.longpack = data;
			break;
		default:
			break;
	}
	
	return ret;
	*/
}

uint32_t SPI_MasterPolling_TXRX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	uint32_t rx_count = 0, tx_count = 0;
	
	if(sTestInfo.longpack)
	{
		HAL_GPIO_WritePin(SPI1_NSS_FPGA_GPIO_Port, SPI1_NSS_FPGA_Pin, GPIO_PIN_RESET);
	}
	
	set_overtime(2000);
	while((!get_overtime()) && ((rx_count  < *rx_len) || (tx_count  < *tx_len)))
	{
		if((sTestInfo.port->Instance->SR & SPI_FLAG_RXNE) == SPI_FLAG_RXNE)
		{
			rx_momory[rx_count++] =  (uint8_t)(sTestInfo.port->Instance->DR);
		}
		
		if(tx_count < *tx_len)
		{
			if(__HAL_SPI_GET_FLAG(sTestInfo.port, SPI_FLAG_TXE))
			{
				if(sTestInfo.longpack == 0)
				{
					HAL_GPIO_WritePin(SPI1_NSS_FPGA_GPIO_Port, SPI1_NSS_FPGA_Pin, GPIO_PIN_RESET);
				}					
				
				sTestInfo.port->Instance->DR = (tx_memory[tx_count++] & (uint16_t)0x01FF);
				
				if(sTestInfo.longpack == 0)
				{
					while((sTestInfo.port->Instance->SR & SPI_FLAG_RXNE) != SPI_FLAG_RXNE);
					for(uint32_t j=0; j<0xFF;j++);
					HAL_GPIO_WritePin(SPI1_NSS_FPGA_GPIO_Port, SPI1_NSS_FPGA_Pin, GPIO_PIN_SET);
				}	
			}
		}
	}
	
	if(sTestInfo.longpack)
	{
		HAL_GPIO_WritePin(SPI1_NSS_FPGA_GPIO_Port, SPI1_NSS_FPGA_Pin, GPIO_PIN_SET);
	}
		
	while(__HAL_SPI_GET_FLAG(sTestInfo.port, SPI_FLAG_TXE) == RESET);
	
	HAL_SPI_DeInit((SPI_HandleTypeDef *)sTestInfo.port);

	return rx_count;
	*/
}

uint32_t SPI_SlavePolling_TXRX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	uint32_t rx_count = 0, tx_count = 0;
	
	set_overtime(2000);
	while((!get_overtime()) && ((tx_count  < *tx_len) || (rx_count  < *rx_len) ))
	{
		if((sTestInfo.port->Instance->SR & SPI_FLAG_RXNE) == SPI_FLAG_RXNE)
		{
			rx_momory[rx_count++] = (uint8_t)(sTestInfo.port->Instance->DR);
		}
		
		if(tx_count < *tx_len)
		{
			if(__HAL_SPI_GET_FLAG(sTestInfo.port, SPI_FLAG_TXE))
			{
				sTestInfo.port->Instance->DR = (tx_memory[tx_count++] & (uint16_t)0x01FF);
			}
		}
	}
	
	return rx_count;
	*/
}

uint8_t SPI_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	if(sTestInfo.isMaster)
	{
		*rx_len = SPI_MasterPolling_TXRX(rx_momory, rx_len, tx_memory, tx_len);
	}		
	else
	{
		*rx_len = SPI_SlavePolling_TXRX(rx_momory, rx_len, tx_memory, tx_len);
	}
	
	return 1;
	*/
}

uint8_t SPI_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	if(sTestInfo.isMaster)
	{
		*rx_len = SPI_MasterPolling_TXRX(rx_momory, rx_len, tx_memory, tx_len);
	}		
	else
	{
		*rx_len = SPI_SlavePolling_TXRX(rx_momory, rx_len, tx_memory, tx_len);
	}
	
	return 1;
	*/
}

/******************************************************************************
* end of file
******************************************************************************/
