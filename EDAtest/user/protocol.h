#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "driver.h"
#include "port.h"

#define PROTOCOL_WRITE_REGISTER   		0x01
#define PROTOCOL_WRITE_REGISTER_ACK   	0xFE

#define PROTOCOL_READ_REGISTER   		0x02
#define PROTOCOL_READ_REGISTER_ACK   	0xFD

#define PROTOCOL_RESET_CMD		   		0x03
#define PROTOCOL_RESET_CMD_ACK		   	0xFC

#define PROTOCOL_RUN_STATE			   	0x04
#define PROTOCOL_RUN_STATE_ACK		   	0xFB

#define PROTOCOL_READ_MEMORY   			0x05
#define PROTOCOL_READ_MEMORY_ACK   		0xFA

#define PROTOCOL_WRITE_MEMORY   		0x06
#define PROTOCOL_WRITE_MEMORY_ACK   	0xEF

#define PROTOCOL_ACTIVE_MEMORY   		0x07
#define PROTOCOL_ACTIVE_MEMORY_ACK   	0xEE

#define PROTOCOL_WRITE_MEMORY_CACHE		0x08
#define PROTOCOL_WRITE_MEMORY_CACHE_ACK 0xEC

#define PROTOCOL_TEST_CASE   			0x09
#define PROTOCOL_TEST_CASE_ACK		   	0xEB

#define PROTOCOL_READ_MEMORY_CACHE		0x0A
#define PROTOCOL_READ_MEMORY_CACHE_ACK  0xEA

#define PROTOCOL_CRC_ERROR   			0xED

#define PROTOCOL_APP_RUN				0xFF


typedef struct _Protocol{
	void (*init)(void);
	uint32_t (*exec)(struct _Protocol* p, uint8_t* buf, uint32_t* head, uint32_t* tail);
	uint32_t (*decode)(uint8_t* des_buf, uint8_t* src_buf, uint32_t head, uint32_t tail);
	uint32_t (*encode)(uint8_t* buf, uint32_t len);
	uint16_t (*CRC16_XMODEM)(unsigned char *puchMsg, unsigned int usDataLen);
	void (*cmd)(struct _Protocol* p);
	void (*ack)(struct _Protocol* p, uint32_t ack_cmd);
	uint8_t rx_data[MAX_BUF_SIZE];
	uint32_t rx_len;
	uint8_t tx_data[MAX_BUF_SIZE];
	uint32_t tx_len;
	uint8_t trigger;
	uint8_t rx_memory[1024];
	uint8_t tx_memory[1024];
	uint32_t rx_memory_len;
	uint32_t tx_memory_len;
}Protocol;


void protocol_init(Protocol* p);

extern Protocol protocol;

#endif


