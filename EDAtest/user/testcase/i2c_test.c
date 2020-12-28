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
#include "i2c_test.h"
#include "overtime.h"
/*******************************************************************************
* Constants and macros
*******************************************************************************/


typedef struct
{
	uint8_t 							addr_mode;
	uint8_t               				address;
	uint32_t		 					baudrate;	
	uint8_t								isMaster;
}I2C_TEST_INFO_T;

static I2C_TEST_INFO_T sTestInfo={0};
static void I2C_Open(void)
{	
	/*
	i2c1_config.Master = sTestInfo.isMaster?SPI_MODE_MASTER:SPI_MODE_SLAVE;
	i2c1_config.AddressingMode = sTestInfo.addr_mode?I2C_ADDRESSINGMODE_10BIT:I2C_ADDRESSINGMODE_7BIT;
	i2c1_config.Address = sTestInfo.address;
	i2c1_config.Baudrate = sTestInfo.baudrate;

	MX_I2C1_Init();
	*/
}


uint8_t I2C_Config(uint32_t address, uint32_t data)
{
	/*
	uint8_t  ret;
	sTestInfo.port = &hi2c1;
	
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				I2C_Open();
			}
			break;
		case 0x04:
			sTestInfo.isMaster = data;
			break;
		case 0x08:
			sTestInfo.address = data;
			break;
		case 0x0c:
			sTestInfo.baudrate = data;
			break;
		case 0x10:
			sTestInfo.addr_mode = data;
			break;
	}
	
	return ret;
	*/
}

uint8_t I2C_Master_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	HAL_StatusTypeDef HAL_Status;
	
	HAL_Status = HAL_I2C_Master_Transmit(sTestInfo.port, sTestInfo.address, tx_memory, *tx_len, 3000);
	if(HAL_Status != HAL_OK)
	{
		*rx_len = 0;
	}
	
	return 1;
	*/
}

uint8_t I2C_Master_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	HAL_StatusTypeDef HAL_Status;
	
	HAL_Status = HAL_I2C_Master_Receive(sTestInfo.port, sTestInfo.address, rx_momory, *rx_len, 3000);
	
	if(HAL_Status != HAL_OK)
	{
		*rx_len = 0;
	}
	return 1;
	*/
}


uint8_t I2C_Slave_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	HAL_StatusTypeDef HAL_Status;
	
	HAL_Status = HAL_I2C_Slave_Transmit(sTestInfo.port, tx_memory, *tx_len, 3000);
	if(HAL_Status != HAL_OK)
	{
		*rx_len = 0;
	}
	return 1;
	*/
}


uint8_t I2C_Slave_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	HAL_StatusTypeDef HAL_Status;
	HAL_Status = HAL_I2C_Slave_Receive(sTestInfo.port, rx_momory, *rx_len, 3000);
	
	if(HAL_Status != HAL_OK)
	{
		*rx_len = 0;
	}
	return 1;
	*/
}

uint8_t I2C_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	uint8_t ret;
	
	if(sTestInfo.isMaster)
	{
		ret = I2C_Master_Polling_RX(rx_momory, rx_len, tx_memory, tx_len);
	}
	else
	{
		ret = I2C_Slave_Polling_RX(rx_momory, rx_len, tx_memory, tx_len);
	}
	
	return ret;
	*/
}

uint8_t I2C_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	uint8_t ret;
	
	if(sTestInfo.isMaster)
	{
		ret = I2C_Master_Polling_TX(rx_momory, rx_len, tx_memory, tx_len);
	}
	else
	{
		ret = I2C_Slave_Polling_TX(rx_momory, rx_len, tx_memory, tx_len);
	}
	
	return ret;
	*/
}



/******************************************************************************
* end of file
******************************************************************************/
