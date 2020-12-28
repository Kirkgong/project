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
#include "can_test.h"
/*******************************************************************************
* Constants and macros
*******************************************************************************/
typedef struct
{
	uint8_t  							mapping;	
//	uint8_t 							*pattern;
	uint32_t		 					baudrate;	
	uint32_t		 					fd_baudrate;	
}CAN_TEST_INFO_T;

static uint32_t rx_count;
static uint32_t tx_count;
//static uint32_t rx_error_count;
uint8_t can_rxdata[8];

uint8_t can_txdata[8];

static CAN_TEST_INFO_T sTestInfo={0};


static void CAN_Open(uint32_t baudrate)
{	
	/*
	can1_config.Baudrate = sTestInfo.baudrate;
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  GPIO_InitStruct.Pin = CAN_32_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	

  HAL_GPIO_WritePin(CAN_32_EN_GPIO_Port, CAN_32_EN_Pin, GPIO_PIN_SET);
	
	HAL_CAN_Stop((CAN_HandleTypeDef *)sTestInfo.port);	
	HAL_CAN_DeInit((CAN_HandleTypeDef *)sTestInfo.port);
	MX_CAN1_Init();
	HAL_CAN_Start((CAN_HandleTypeDef *)sTestInfo.port);	
	*/
}


uint8_t CAN_Config(uint32_t address, uint32_t data)
{
	/*
	uint8_t  ret;
	
	switch(address&0x0F)
	{
		case 0x00:
            sTestInfo.port = &hcan1;
			CAN_Open(sTestInfo.baudrate);
			break;
		
		case 0x04:
			sTestInfo.baudrate = data;
			break;
	}
	
	return ret;
	*/
}

uint8_t CAN_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	ErrorStatus  ret = ERROR;
	
	
	for(tx_count=0; tx_count<*tx_len;)
	{
		for(uint8_t i = 0; i < 8; i++)
		{
			can_txdata[i] = tx_memory[tx_count & 0xFF];
			tx_count++;
		}
		
		CAN_TxHeader.DLC = 8;
		CAN_TxHeader.IDE = CAN_ID_STD;
		CAN_TxHeader.ExtId = 0;
		CAN_TxHeader.StdId = 0;
		CAN_TxHeader.RTR = CAN_RTR_DATA;
		
		while(0 == HAL_CAN_GetTxMailboxesFreeLevel(sTestInfo.port));
		while(HAL_CAN_AddTxMessage(sTestInfo.port, &CAN_TxHeader, can_txdata, (uint32_t *)CAN_TX_MAILBOX0) != HAL_OK);
	}
	
	ret = SUCCESS;
	return ret;   
	*/
}

uint8_t CAN_Polling_TX_Ext(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
	ErrorStatus  ret = ERROR;
	
	for(tx_count=0; tx_count<*tx_len;)
	{
		for(uint8_t i = 0; i < 8; i++)
		{
			can_txdata[i] = tx_memory[tx_count & 0xFF];
			tx_count++;
		}
		
		CAN_TxHeader.DLC = 8;
		CAN_TxHeader.IDE = CAN_ID_EXT;
		CAN_TxHeader.ExtId = 0;
		CAN_TxHeader.StdId = 0;
		CAN_TxHeader.RTR = CAN_RTR_DATA;
		
		while(0 == HAL_CAN_GetTxMailboxesFreeLevel(sTestInfo.port));
		while(HAL_CAN_AddTxMessage(sTestInfo.port, &CAN_TxHeader, can_txdata, (uint32_t *)CAN_TX_MAILBOX0) != HAL_OK);
	}
	
	ret = SUCCESS;
	return ret;
		*/
}

static  uint8_t CAN_FrameLen(uint32_t dlc)
{
	/*
    uint8_t len;
    
    if(dlc <= MCAN_DLC_DATASIZE8)
    {
        len = dlc;
    }
    else if(dlc == MCAN_DLC_DATASIZE12)
    {
        len = 12;
    }
    else if(dlc == MCAN_DLC_DATASIZE16)
    {
        len = 16;
    }
    else if(dlc == MCAN_DLC_DATASIZE20)
    {
        len = 20;
    }
    else if(dlc == MCAN_DLC_DATASIZE24)
    {
        len = 24;
    }
    else if(dlc == MCAN_DLC_DATASIZE32)
    {
        len = 32;
    } 
    else if(dlc == MCAN_DLC_DATASIZE48)
    {
        len = 48;
    }
    else if(dlc == MCAN_DLC_DATASIZE64)
    {
        len = 64;
    }
    
    return len;
	*/
}

uint8_t CAN_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
    uint8_t  frameLen;
	set_overtime(3000);
	for(rx_count =0;  rx_count < *rx_len; )
	{
		while((get_overtime()!= 0x01)&&(HAL_CAN_GetRxFifoFillLevel(sTestInfo.port, CAN_RX_FIFO0)) == 0);
		while((get_overtime()!= 0x01)&&(HAL_CAN_GetRxMessage(sTestInfo.port, CAN_RX_FIFO0, &CAN_RxHeader, can_rxdata) != HAL_OK));

		frameLen = CAN_FrameLen(CAN_RxHeader.DLC);
		for(uint8_t i = 0; i< frameLen; i++)
		{            
				rx_momory[rx_count++] = can_rxdata[i];
		}
	}
	
	return SUCCESS;
	*/
}

uint8_t CAN_Polling_RX_Ext(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	/*
    uint8_t  frameLen;
	set_overtime(3000); 
	for(rx_count =0;  rx_count < *rx_len; )
	{
		while((get_overtime()!= 0x01)&&(HAL_CAN_GetRxFifoFillLevel(sTestInfo.port, CAN_RX_FIFO0) == 0));  
		while((get_overtime()!= 0x01)&&(HAL_CAN_GetRxMessage(sTestInfo.port, CAN_RX_FIFO0, &CAN_RxHeader, can_rxdata) != HAL_OK));

		frameLen = CAN_FrameLen(CAN_RxHeader.DLC);
		for(uint8_t i = 0; i< frameLen; i++)
		{            
				rx_momory[rx_count++] = can_rxdata[i];
		}
	}
	
	return SUCCESS;
	*/
}


uint8_t CAN_Polling_TXRX_R(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	return 1;
}

uint8_t CAN_Polling_TXRX_W(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len)
{
	return 1;
}






/******************************************************************************
* end of file
******************************************************************************/
