#include "protocol.h"
#include "string.h"
#include "port_switch.h"
#include "uart_test.h"
#include "spi_test.h"
#include "can_test.h"
#include "i2c_test.h"
#include "kbi_test.h"
#include "gpio_test.h"
#include "osc_test.h"
#include "lin_test.h"
#include "driver.h"


Protocol protocol;

static unsigned short CRC16_XMODEM(unsigned char *puchMsg, unsigned int usDataLen)  
{
  unsigned short wCRCin = 0x0000;  
  unsigned short wCPoly = 0x1021;  
  unsigned char wChar = 0;  
    
  while (usDataLen--)     
  {  
		wChar = *(puchMsg++);  
		wCRCin ^= (wChar << 8);  
		for(int i = 0;i < 8;i++)  
		{  
			if(wCRCin & 0x8000)  
				wCRCin = (wCRCin << 1) ^ wCPoly;  
			else  
				wCRCin = wCRCin << 1;  
		}  
  }  
  return (wCRCin) ;  
}

static uint32_t decode(uint8_t* des_buf, uint8_t* src_buf, uint32_t head, uint32_t tail)
{
	uint32_t i,ret_len = 0;
	
	for(i=tail; i != head; )
	{
		if(src_buf[i] == 0x7F)
		{
			des_buf[ret_len++] = src_buf[i] + src_buf[i+1] - 0x02;
			i++;
		}
		else
		{
			des_buf[ret_len++] = src_buf[i];
		}
		i++;
		if(i>=MAX_BUF_SIZE)
			i-=MAX_BUF_SIZE;
	}
	return ret_len;
}

static uint32_t encode(uint8_t* buf, uint32_t len)
{
	uint32_t i, count = 0, ret_len;
	
	for(i=1; i<len-1; i++)
	{
		if((buf[i] == 0x7D) || (buf[i] == 0x7E) || (buf[i] == 0x7f))
		{
			count++;
		}
	}
	
	ret_len = len + count;
	
	if(count >0)
	{
		buf[len + count - 1] = buf[len - 1];
		
		for(i=len-2; count>0; i--)
		{
			if((buf[i] == 0x7d) || (buf[i] == 0x7e) || (buf[i] == 0x7F))
			{			
				buf[i + count] = buf[i] + 0x02 - 0x7F;
				buf[i + count - 1] = 0x7F;
				count-- ;
			}
			else
			{
				 buf[i+ count] = buf[i];
			}
		}
	}
	
	return ret_len;
}

static uint32_t exec(Protocol* p, uint8_t* buf, uint32_t* head, uint32_t* tail)
{
	uint32_t index;
	
loop:
	index = *tail;
	
	for(; index != *head;)
	{
		if(buf[index] == 0x7D)
		{
			*tail = index;
			index++;
			break;
		}
		index++;
	}
	
	if(index >= MAX_BUF_SIZE)
		index -= MAX_BUF_SIZE;
	
	for(; index != *head;)
	{
		if(buf[index] == 0x7E)
		{
			p->rx_len = p->decode(p->rx_data, buf, (index + 1)%MAX_BUF_SIZE, *tail);
			*tail = index + 1;
			if(*tail >= MAX_BUF_SIZE)
				*tail -= MAX_BUF_SIZE;
			if(p->rx_data[0] == 0x7D && 
			   p->rx_data[1] == 0x03 &&
			   p->rx_data[2] == 0x30 &&
			   p->rx_data[3] == 0x63 &&
			   p->rx_data[4] == 0x7E)
			{
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_RESET_CMD_ACK);
				for(int i=0;i<20000;i++);
				SystemReset();
			}
			protocol.trigger = 1;
			goto loop;
		}
		else if(buf[index] == 0x7D)
		{
			*tail = index;
			goto loop;
		}
		
		index++;
		if(index >= MAX_BUF_SIZE)
			index -= MAX_BUF_SIZE;
	}
	
	return 0;
}

static void ack(struct _Protocol* p, uint32_t ack_cmd)
{
	uint16_t crc;
	uint16_t i;
	
	for(i=0;i<p->tx_len;i++)
	{
		p->tx_data[p->tx_len - 1 -i + 2] = p->tx_data[p->tx_len - 1 -i];
	}
	
	p->tx_data[0] = 0x7D;
	p->tx_data[1] = ack_cmd;
	p->tx_len += 2;
	
	crc = p->CRC16_XMODEM(&p->tx_data[1], p->tx_len - 1);
	p->tx_data[p->tx_len++] = crc>>8;
	p->tx_data[p->tx_len++] = crc;
	p->tx_data[p->tx_len++] = 0x7E;
	
	p->tx_len = p->encode(p->tx_data, p->tx_len);
	port.port_send_data(p->tx_data, p->tx_len);
}

uint8_t(*test[30][10])(uint8_t* rx_momory, uint32_t* rx_len, uint8_t* tx_memory, uint32_t* tx_len) = {
	{NULL},
	{NULL, UART_Polling_RX, UART_Polling_TX, UART_Polling_TXRX_R, UART_Polling_TXRX_W},
	{NULL, SPI_Polling_RX, SPI_Polling_TX},
	{NULL, I2C_Polling_RX, I2C_Polling_TX},
	{NULL, CAN_Polling_RX, CAN_Polling_TX, CAN_Polling_TXRX_R, CAN_Polling_TXRX_W},
	{NULL, LIN_Polling_RX, LIN_Polling_TX},
	{NULL},
	{NULL, KBI_Polling_RX, KBI_Polling_TX},
	{NULL, GPIO_Polling_RX, GPIO_Polling_TX},
 };

uint8_t (*config[30])(uint32_t address, uint32_t data) = {
	pin_switch,
	UART_Config,
	SPI_Config,
	I2C_Config,
	CAN_Config,
	LIN_Config,
	NULL,
	KBI_Config,
	GPIO_Config,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	OSC_Config,
};

uint8_t (*R_config[30])(uint32_t address, Protocol* p) = {  //读寄存器,只有工具模块才用到,TIM1,ADC
	NULL,//R_pin_switch,
	NULL,//R_UART_Config,
	NULL,//R_SPI_Config,
	NULL,//R_I2C_Config,
	NULL,//R_CAN_Config,
	NULL,
	NULL,
	NULL,//R_KBI_Config,
	NULL,//R_GPIO_Config,
	NULL,	
	NULL,
};

static void cmd(Protocol* p)
{
	uint32_t address;
	uint32_t data;
	uint16_t len;
	void (*runapp)(void);
	if(p->CRC16_XMODEM(&p->rx_data[1], p->rx_len - 4) == ((p->rx_data[p->rx_len - 3]<<8) + p->rx_data[p->rx_len - 2]))
	{
		switch(p->rx_data[1])
		{
			case PROTOCOL_WRITE_REGISTER:
				for(uint32_t i=0; i<((p->rx_len-5)/8); i++)
				{
					address = (p->rx_data[2 + 8*i]<< 24) + (p->rx_data[3 + 8*i] << 16) + (p->rx_data[4 + 8*i] << 8) + (p->rx_data[5 + 8*i] << 0);
					data = (p->rx_data[6 + 8*i]<< 24) + (p->rx_data[7 + 8*i] << 16) + (p->rx_data[8 + 8*i] << 8) + (p->rx_data[9 + 8*i] << 0);
					if((config[(address>>16)&0xFF] != NULL) && (((address>>16)&0xFF) <= sizeof(config)))
					{
						config[(address>>16)&0xFF](address, data);
					}
				}
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_WRITE_REGISTER_ACK);
				break;
			case PROTOCOL_READ_REGISTER:			
				p->tx_data[0] = 1;
				p->tx_len = 1;       
        for(uint32_t i=0; i<((p->rx_len-5)/4); i++)
				{
					address = (p->rx_data[2 + 4*i]<< 24) + (p->rx_data[3 + 4*i] << 16) + (p->rx_data[4 + 4*i] << 8) + (p->rx_data[5 + 4*i] << 0);
					if((config[(address>>16)&0xFF] != NULL) && (((address>>16)&0xFF) <= sizeof(config)))
					{
						R_config[(address>>16)&0xFF](address, p);
						p->tx_len += 8;	
					}
				}	
        p->ack(p, PROTOCOL_READ_REGISTER_ACK);
//				address = (p->rx_data[2]<< 24) + (p->rx_data[3] << 16) + (p->rx_data[4] << 8) + (p->rx_data[5] << 0);	
//				if((config[(address>>16)&0xFF] != NULL) && (((address>>16)&0xFF) <= sizeof(config)))
//				{
//					R_config[(address>>16)&0xFF](address,p);	
//				}	
          				
				break;
			case PROTOCOL_RUN_STATE:
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_RUN_STATE_ACK);
				break;
			case PROTOCOL_WRITE_MEMORY:
				
				p->tx_memory_len = p->rx_len - 5;
			
				memcpy(p->tx_memory, &p->rx_data[2], p->tx_memory_len);
			
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_WRITE_MEMORY_ACK);
				break;
			case PROTOCOL_READ_MEMORY:
				p->tx_data[0] = 1;
				p->tx_len = 1;				
				address = (p->rx_data[2]<< 24) + (p->rx_data[3] << 16) + (p->rx_data[4] << 8) + (p->rx_data[5] << 0);	
        len = 	(p->rx_data[6] << 8) + p->rx_data[7];
				if((config[(address>>16)&0xFF] != NULL) && (((address>>16)&0xFF) <= sizeof(config)))
				{
					R_config[(address>>16)&0xFF](address,p);	
				}	
        p->tx_len += len;				
				p->ack(p, PROTOCOL_READ_MEMORY_ACK);
				break;
			case PROTOCOL_WRITE_MEMORY_CACHE:
				p->tx_memory_len = p->rx_len - 5;
				memcpy(p->tx_memory, &p->rx_data[2], p->tx_memory_len);
			
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_WRITE_MEMORY_CACHE_ACK);
				break;
			case PROTOCOL_READ_MEMORY_CACHE:
				p->tx_data[0] = 1;
				memcpy(&p->tx_data[1], p->rx_memory, p->rx_memory_len);
				p->tx_len = p->rx_memory_len + 1;
				p->rx_memory_len = 0;
				
				p->ack(p, PROTOCOL_READ_MEMORY_CACHE_ACK);
				break;
			
			case PROTOCOL_RESET_CMD:
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_RESET_CMD_ACK);
				break;
			case PROTOCOL_APP_RUN:
				runapp = (void (*) (void))(*(uint32_t*)(0x20008004));
				runapp();
				break;
			case PROTOCOL_TEST_CASE:
				p->tx_data[0] = 1;
				p->tx_len = 1;
				p->ack(p, PROTOCOL_TEST_CASE_ACK);
				p->rx_memory_len = (p->rx_data[2] << 8) + p->rx_data[3];
				p->tx_memory_len = (p->rx_data[2] << 8) + p->rx_data[3];
			
			//	CAN_TxHeader.RTR = p->rx_data[5] ;
			 if(test[p->rx_data[4]][p->rx_data[6]] != NULL)
			 {
				test[p->rx_data[4]][p->rx_data[6]](p->rx_memory, &p->rx_memory_len, p->tx_memory, &p->tx_memory_len);
			 }
			 	
			break;
			default:
				break;
		}
	}
	else
	{
		p->tx_len = 1;
		p->tx_data[1] = 1;
		p->ack(p, PROTOCOL_CRC_ERROR);
	}
}

static void init(void)
{
	
}

void protocol_init(Protocol* p)
{
	p->rx_len = 0;
	p->trigger = 0;
	
	p->init = init;
	p->exec = exec;
	p->decode = decode;
	p->encode = encode;
	p->CRC16_XMODEM = CRC16_XMODEM;
	p->cmd = cmd;
	p->ack = ack;
}

