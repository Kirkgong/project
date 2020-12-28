#ifndef UART_TEST_H
#define UART_TEST_H

#include "driver.h"

typedef enum
{
	E_UART_TESTCASE_TYPE_ALL,	
	E_UART_TESTCASE_TYPE_POLLING_TX,
	E_UART_TESTCASE_TYPE_POLLING_RX,
	E_UART_TESTCASE_TYPE_POLLING_TXRX,
	E_UART_TESTCASE_TYPE_INT_TX,
	E_UART_TESTCASE_TYPE_INT_RX,
	E_UART_TESTCASE_TYPE_INT_TXRX,
	E_UART_TESTCASE_TYPE_DMA_TX,
	E_UART_TESTCASE_TYPE_DMA_RX,
	E_UART_TESTCASE_TYPE_DMA_TXRX,
	E_UART_TESTCASE_TYPE_NUM
}E_UART_TESTCASE_TYPE;


uint8_t UART_Config(uint32_t address, uint32_t data);
uint8_t UART_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t UART_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t UART_Polling_TXRX_R(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t UART_Polling_TXRX_W(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
#endif

















