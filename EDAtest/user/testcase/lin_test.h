#ifndef LIN_TEST_H
#define LIN_TEST_H

#include "protocol.h"
#include "driver.h"


#define BIT(A,B)      (((A)>>(B))&0x01)   /**< return bit has position \a B in byte \a A, A is the variable while */	

#define LIN_XL6600_EN_Pin GPIO_PIN_13
#define LIN_XL6600_EN_GPIO_Port GPIOG
#define LIN_EXT_EN_Pin GPIO_PIN_15
#define LIN_EXT_EN_GPIO_Port GPIOG

#define	LIN_RECEVE_START			0
#define	LIN_RECEVE_SYNC				1
#define	LIN_RECEVE_HEAD				2
#define	LIN_RECEVE_PID				3
#define	LIN_RECEVE_DATA0			4
#define	LIN_RECEVE_DATA1			5
#define	LIN_RECEVE_CHECK			6

typedef enum
{
	E_LIN_TESTCASE_TYPE_ALL,	
	E_LIN_TESTCASE_TYPE_POLLING_TX,
	E_LIN_TESTCASE_TYPE_POLLING_RX,
	E_LIN_TESTCASE_TYPE_POLLING_TXRX,
	E_LIN_TESTCASE_TYPE_INT_TX,
	E_LIN_TESTCASE_TYPE_INT_RX,
	E_LIN_TESTCASE_TYPE_INT_TXRX,
	E_LIN_TESTCASE_TYPE_DMA_TX,
	E_LIN_TESTCASE_TYPE_DMA_RX,
	E_LIN_TESTCASE_TYPE_DMA_TXRX,
	E_LIN_TESTCASE_TYPE_NUM
}E_LIN_TESTCASE_TYPE;

uint8_t LIN_CalcParity(uint8_t id);
uint8_t LIN_Checksum(uint8_t id,uint8_t *data,uint8_t length);
void LIN_Open();
uint8_t LIN_Config(uint32_t address, uint32_t data);
ErrorStatus LIN_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
ErrorStatus LIN_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
#endif




