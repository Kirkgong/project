#include "port.h"
#include "interface.h"

Port port;

void init(void)
{
	/*
	MX_USART6_UART_Init(115200);
	__HAL_UART_ENABLE_IT(&huart6, UART_IT_RXNE);
	*/
}

void receive_data(Port* p, uint8_t data)
{
	p->rx_buf[p->head++] = data;
	if(p->head == sizeof(p->rx_buf))
	{
		p->head = 0;
	}
}

void port_send_data(uint8_t * buf, uint32_t len)
{
	aufi_data_write(buf, len);
	/*
	uint32_t i;
	for(i=0; i<len;i++)
	{
		while((huart6.Instance->SR & UART_FLAG_TXE) != UART_FLAG_TXE);
		huart6.Instance->DR = buf[i];
	}
	*/
}

void port_init(Port* p)
{
	p->init = init;
	p->receive_data = receive_data;
	p->port_send_data = port_send_data;
	
	p->init();
}

