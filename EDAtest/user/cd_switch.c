#include "cd_switch.h"

void cd_switch_init(void)
{
	/*
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_WritePin(CD_SCK_AX0_GPIO_Port, CD_SCK_AX0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AX1_GPIO_Port, CD_SCK_AX1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AX2_GPIO_Port, CD_SCK_AX2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AX3_GPIO_Port, CD_SCK_AX3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX0_GPIO_Port, CD_SDA_AX0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX1_GPIO_Port, CD_SDA_AX1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX2_GPIO_Port, CD_SDA_AX2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX3_GPIO_Port, CD_SDA_AX3_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(CD_SCK_AY0_GPIO_Port, CD_SCK_AY0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AY1_GPIO_Port, CD_SCK_AY1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AY2_GPIO_Port, CD_SCK_AY2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AY0_GPIO_Port, CD_SDA_AY0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AY1_GPIO_Port, CD_SDA_AY1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AY2_GPIO_Port, CD_SDA_AY2_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(CD_CS_GPIO_Port, CD_CS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_RESET_GPIO_Port, CD_RESET_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_DATA_GPIO_Port, CD_DATA_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_STROBE_GPIO_Port, CD_STROBE_Pin, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = CD_SCK_AX0_Pin;
	HAL_GPIO_Init(CD_SCK_AX0_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SCK_AX1_Pin;
	HAL_GPIO_Init(CD_SCK_AX1_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SCK_AX2_Pin;
	HAL_GPIO_Init(CD_SCK_AX2_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SCK_AX3_Pin;
	HAL_GPIO_Init(CD_SCK_AX3_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AX0_Pin;
	HAL_GPIO_Init(CD_SDA_AX0_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AX1_Pin;
	HAL_GPIO_Init(CD_SDA_AX1_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AX2_Pin;
	HAL_GPIO_Init(CD_SDA_AX2_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AX3_Pin;
	HAL_GPIO_Init(CD_SDA_AX3_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = CD_SCK_AY0_Pin;
	HAL_GPIO_Init(CD_SCK_AY0_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SCK_AY1_Pin;
	HAL_GPIO_Init(CD_SCK_AY1_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SCK_AY2_Pin;
	HAL_GPIO_Init(CD_SCK_AY2_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AY0_Pin;
	HAL_GPIO_Init(CD_SDA_AY0_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AY1_Pin;
	HAL_GPIO_Init(CD_SDA_AY1_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_SDA_AY2_Pin;
	HAL_GPIO_Init(CD_SDA_AY2_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = CD_CS_Pin;
	HAL_GPIO_Init(CD_CS_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_RESET_Pin;
	HAL_GPIO_Init(CD_RESET_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_DATA_Pin;
	HAL_GPIO_Init(CD_DATA_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = CD_STROBE_Pin;
	HAL_GPIO_Init(CD_STROBE_GPIO_Port, &GPIO_InitStruct);
	*/
}

void i2c_pin_cd_config(uint8_t xl_sck_pin, uint8_t xl_sda_pin, uint8_t stm32_sck_pin, uint8_t stm32_sda_pin)
{
	/*
//	HAL_GPIO_WritePin(CD_DATA_GPIO_Port, CD_DATA_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(CD_STROBE_GPIO_Port, CD_STROBE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_CS_GPIO_Port, CD_CS_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(CD_SCK_AX0_GPIO_Port, CD_SCK_AX0_Pin, (xl_sck_pin&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AX1_GPIO_Port, CD_SCK_AX1_Pin, (xl_sck_pin&0x02)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AX2_GPIO_Port, CD_SCK_AX2_Pin, (xl_sck_pin&0x04)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AX3_GPIO_Port, CD_SCK_AX3_Pin, (xl_sck_pin&0x08)?GPIO_PIN_SET:GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(CD_SDA_AX0_GPIO_Port, CD_SDA_AX0_Pin, (xl_sda_pin&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX1_GPIO_Port, CD_SDA_AX1_Pin, (xl_sda_pin&0x02)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX2_GPIO_Port, CD_SDA_AX2_Pin, (xl_sda_pin&0x04)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AX3_GPIO_Port, CD_SDA_AX3_Pin, (xl_sda_pin&0x08)?GPIO_PIN_SET:GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(CD_SCK_AY0_GPIO_Port, CD_SCK_AY0_Pin, (stm32_sck_pin&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AY1_GPIO_Port, CD_SCK_AY1_Pin, (stm32_sck_pin&0x02)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SCK_AY2_GPIO_Port, CD_SCK_AY2_Pin, (stm32_sck_pin&0x04)?GPIO_PIN_SET:GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(CD_SDA_AY0_GPIO_Port, CD_SDA_AY0_Pin, (stm32_sda_pin&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AY1_GPIO_Port, CD_SDA_AY1_Pin, (stm32_sda_pin&0x02)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_SDA_AY2_GPIO_Port, CD_SDA_AY2_Pin, (stm32_sda_pin&0x04)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CD_DATA_GPIO_Port, CD_DATA_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CD_STROBE_GPIO_Port, CD_STROBE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CD_STROBE_GPIO_Port, CD_STROBE_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(CD_CS_GPIO_Port, CD_CS_Pin, GPIO_PIN_RESET);
	*/
}
