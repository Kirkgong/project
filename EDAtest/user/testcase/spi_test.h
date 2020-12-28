#ifndef SPI_TEST_H
#define SPI_TEST_H

#include "driver.h"














uint8_t SPI_Config(uint32_t address, uint32_t data);
uint8_t SPI_Polling_TX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
uint8_t SPI_Polling_RX(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len);
#endif

















