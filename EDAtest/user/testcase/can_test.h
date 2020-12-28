#ifndef CAN_TEST_H
#define CAN_TEST_H

#include "driver.h"

#define CAN_FD_EN_Pin GPIO_PIN_14
#define CAN_FD_EN_GPIO_Port GPIOF
#define CAN_32_EN_Pin GPIO_PIN_15
#define CAN_32_EN_GPIO_Port GPIOF


typedef enum
{
	E_CAN_TESTCASE_TYPE_ALL,	
	E_CAN_TESTCASE_TYPE_POLLING_TX,
	E_CAN_TESTCASE_TYPE_POLLING_RX,
	E_CAN_TESTCASE_TYPE_POLLING_TXRX,
	E_CAN_TESTCASE_TYPE_INT_TX,
	E_CAN_TESTCASE_TYPE_INT_RX,
	E_CAN_TESTCASE_TYPE_INT_TXRX,
	FD_POLLING_TX,
	FD_POLLING_RX,
	FD_POLLING_TXRX,
	FD_INTERRUPT_TX,
	FD_INTERRUPT_RX,
	FD_INTERRUPT_TXRX,
	E_CAN_TESTCASE_TYPE_NUM
}E_CAN_TESTCASE_TYPE;


uint8_t CAN_Config(uint32_t address, uint32_t data);
uint8_t CAN_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t CAN_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t CAN_Polling_TXRX_R(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t CAN_Polling_TXRX_W(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
#endif

















