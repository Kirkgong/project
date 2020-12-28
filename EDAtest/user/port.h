#ifndef PORT_H
#define PORT_H
#include "driver.h"
#define MAX_BUF_SIZE	1024

typedef struct _Port{
	void (*init)(void);
	void (*receive_data)(struct _Port* p, uint8_t data);
	void (*port_send_data)(uint8_t * buf, uint32_t len);
	uint8_t rx_buf[MAX_BUF_SIZE];
	uint32_t head;
	uint32_t tail;
}Port;



void port_init(Port* p);
extern Port port;
#endif
