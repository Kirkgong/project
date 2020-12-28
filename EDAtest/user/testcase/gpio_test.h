#ifndef GPIO_TEST_H
#define GPIO_TEST_H

#include "driver.h"

#define CLK_PORT			GPIOE
#define CLK_PIN				GPIO_PIN_9
#define DATA_PORT			GPIOE
#define DATA_PIN			GPIO_PIN_11




uint8_t GPIO_Config(uint32_t address, uint32_t data);
uint8_t GPIO_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t GPIO_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
#endif

















