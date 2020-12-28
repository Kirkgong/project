#include "port_switch.h"
#include "cd_switch.h"

uint8_t success;


void clear_success_flag(void)
{
	success = 0;
}

uint8_t get_success_flag(void)
{
	return success;
}

void delay_short(void)
{
	for(volatile uint32_t i=0; i < 0x3F; i++);
}

void delay_long(void)
{
	for(volatile uint32_t i=0; i < 0xFF; i++);
}
	
static void pin_write(uint8_t a_pin, uint8_t b_pin, uint8_t dir, uint8_t cs)
{
	/*
	uint16_t tx_data, rx_data;
	
	tx_data = (PIN_CONFIG_WRITE << 15) | (dir << 14) | (a_pin <<8) | b_pin;
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&tx_data, (uint8_t*)&rx_data, 1, 1000);
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_SET);
	delay_long();
	*/
}

static void pin_write_with_target(uint8_t a_pin, uint8_t b_pin, uint8_t dir, uint8_t cs, uint16_t c0_c1)
{
	/*
	uint16_t tx_data, rx_data;
	
	tx_data = (PIN_CONFIG_WRITE << 15) | (dir << 14) | (a_pin <<8) | b_pin;
	tx_data += c0_c1;
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&tx_data, (uint8_t*)&rx_data, 1, 1000);
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_SET);
	delay_long();
	*/
}

uint8_t pin_read(uint8_t a_pin, uint8_t b_pin, uint8_t dir, uint8_t cs)
{
	/*
	uint16_t tx_data, rx_data, ret;
	
	tx_data = (PIN_CONFIG_READ << 15) | (dir << 14) | (a_pin <<8) | b_pin;
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&tx_data, (uint8_t*)&rx_data, 1, 1000);
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_SET);
	delay_short();
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&tx_data, (uint8_t*)&rx_data, 1, 1000);
	HAL_GPIO_WritePin(PPGA_NSS_Port[cs], PPGA_NSS_Pin[cs], GPIO_PIN_SET);
	
	if((rx_data&0x5F7F) == (tx_data &0x5F7F))
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	
	delay_long();
	return ret;
	*/
}

void FPGA1STM_FPGA1XL_config(uint8_t xl_pin, uint8_t stm_pin, uint8_t dir)
{
	while(pin_read(stm_pin, xl_pin, dir, FPGA_1) == 0)
	{
		pin_write(stm_pin, xl_pin, dir, FPGA_1);
	}
}

void FPGA1STM_FPGA1EXT_config(uint8_t stm_pin, uint8_t ext_pin, uint8_t dir)
{
	while(pin_read(ext_pin, stm_pin, dir, FPGA_1) == 0)
	{
		pin_write_with_target(ext_pin, stm_pin, dir, FPGA_1, 1<<7);
	}
}

void FPGA1EXT_FPGA1XL6600_config(uint8_t xl_pin, uint8_t ext_pin, uint8_t dir)
{
	while(pin_read(ext_pin, xl_pin, dir, FPGA_1) == 0)
	{
		pin_write_with_target(ext_pin, xl_pin, dir, FPGA_1, 1<<13);
	}
}

void start_change(void)
{
	/*
	uint16_t tx_data, rx_data = 1, status = 0;
	
	while(status == 0)
	{
		tx_data = 0x01FF;
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		delay_short();
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
	
		delay_long();
		
		tx_data = 0x80FF;
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		delay_short();
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
		
		delay_long();
		
		tx_data = 0x80FF;
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		delay_short();
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
		
		if(rx_data == 1)
		{
			status = 1;
		}
		delay_long();
	}
	*/
}

void stop_change(void)
{
	/*
	uint16_t tx_data, rx_data = 1, status = 0;
	
	while(status == 0)
	{
		tx_data = 0x00FF;
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
	
		delay_long();
		
		tx_data = 0x80FF;
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
		delay_short();
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
		
		if(rx_data == 0)
		{
			status = 1;
		}
		delay_long();
	}
	*/
}

void reset_config(void)
{
	
	/*
	uint16_t tx_data, rx_data = 0, status = 0;
	

	FPGA1STM_FPGA1XL_config(8 , 8 , PIN_CONFIG_XL2STM);
	
	while(status == 0)
	{

		tx_data = 0x02FF;
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)&tx_data, (uint8_t *)&rx_data, 1, 1000);
		delay_short();
		HAL_GPIO_WritePin(PPGA_NSS_Port[0], PPGA_NSS_Pin[0], GPIO_PIN_SET);
		HAL_GPIO_WritePin(PPGA_NSS_Port[1], PPGA_NSS_Pin[1], GPIO_PIN_SET);
		delay_long();
		

		if(!pin_read(8, 8, PIN_CONFIG_XL2STM, FPGA_1))
		{
			status = 1;
		}
	}
	*/
}

void OE_Enable(void)
{
	/*
	HAL_GPIO_WritePin(GPIOE, TX_OE3_Pin|TX_OE5_Pin|TX_OE6_Pin|TX_OE7_Pin 
                          |TX_OE8_Pin|TX_OE9_Pin|TX_OE10_Pin|TX_OE1_Pin 
                          |TX_OE2_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(GPIOG, TX_OE11_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(TX_OE4_GPIO_Port, TX_OE4_Pin, GPIO_PIN_SET);
	*/
}

void OE_Disable(void)
{
	/*
	HAL_GPIO_WritePin(GPIOE, TX_OE3_Pin|TX_OE5_Pin|TX_OE6_Pin|TX_OE7_Pin 
                          |TX_OE8_Pin|TX_OE9_Pin|TX_OE10_Pin|TX_OE1_Pin 
                          |TX_OE2_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(GPIOG, TX_OE11_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(TX_OE4_GPIO_Port, TX_OE4_Pin, GPIO_PIN_RESET);
	*/
}

void I2C_OE_Enable(void)
{
	/*
	HAL_GPIO_WritePin(GPIOH, TX_I2C_OE1_Pin|TX_I2C_OE2_Pin|TX_I2C_OE3_Pin , GPIO_PIN_SET);
	*/
}

void I2C_OE_Disable(void)
{
	/*
	HAL_GPIO_WritePin(GPIOH, TX_I2C_OE1_Pin|TX_I2C_OE2_Pin|TX_I2C_OE3_Pin , GPIO_PIN_RESET);
	*/
}

void port_switch_init(void)
{

}

uint16_t switch_data[32] = {0};
uint8_t switch_num = 0;


uint8_t port_switch(uint32_t address, uint32_t data)
{
	uint32_t i;
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				do
				{
					clear_success_flag();
					stop_change();
					reset_config();
					for(i=0; i<switch_num; i++)
					{
						if((switch_data[i] >> 7) & 0x1)
						{
							FPGA1STM_FPGA1EXT_config(switch_data[i] & 0x7F , (switch_data[i]>>8)&0x1F ,\
												(switch_data[i] >> 14) & 0x01);
						}
						else if((switch_data[i] >> 13) & 0x1)
						{
							FPGA1EXT_FPGA1XL6600_config(switch_data[i] & 0x7F , (switch_data[i]>>8)&0x1F ,\
												(switch_data[i] >> 14) & 0x01);
						}
						else
						{
							FPGA1STM_FPGA1XL_config(switch_data[i] & 0x7F , (switch_data[i]>>8)&0x1F ,\
												(switch_data[i] >> 14) & 0x01);
						}
					}
					start_change();
				}while(get_success_flag() != 0);
			}
			else
			{
				switch_num = 0;
			}
			break;
		case 0x04:
			switch_data[switch_num++] = (uint16_t)data;
			break;
		default:
			break;
	}
	
	return 1;
}

void i2c_pin_select(uint8_t port, uint8_t mapping)
{
	uint8_t _xl_sck_pin, _xl_sda_pin, _stm_sck_pin = 0, _stm_sda_pin = 0;
	
	if(port==0)
	{
		_xl_sck_pin = mapping;
		_xl_sda_pin = mapping;
	}
	else
	{
		_xl_sck_pin = 2+mapping;
		_xl_sda_pin = 2+mapping;
	}
	
	OE_Disable();
	I2C_OE_Enable();
	
	i2c_pin_cd_config(_xl_sck_pin, _xl_sda_pin, _stm_sck_pin, _stm_sda_pin);
}


void cd_switch(uint32_t address, uint32_t data)
{
	static uint8_t port, mapping;
	
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				i2c_pin_select(port, mapping);
			}
			else
			{
				
			}
			break;
		case 0x04:
			port = data;
			break;
		case 0x08:
			mapping = data;
			break;
		default:
			break;
	}
}

void en_control(uint32_t address, uint32_t data)
{
	switch(address&0xFF)
	{
		case 0x00:
			if(data&0x01)
			{
				OE_Enable();
			}
			else
			{
				OE_Disable();
			}
			break;
		case 0x04:
			if(data&0x01)
			{
				I2C_OE_Enable();
			}
			else
			{
				I2C_OE_Disable();
			}
			break;
		default:
			break;
	}
}

uint8_t pin_switch(uint32_t address, uint32_t data)
{
	if((address&0x1000) == 0x1000)
	{
		cd_switch(address, data);
	}
	else if((address&0x2000) == 0x2000)
	{
		en_control(address, data);
	}
	else if((address&0x0000) == 0x0000)
	{
		port_switch(address, data);
	}
	
	return 1;
}
