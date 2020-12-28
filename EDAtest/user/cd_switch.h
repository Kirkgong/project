#ifndef __CD_SWITCH_H
#define __CD_SWITCH_H
#include "driver.h"

#define CD_SCK_AX0_Pin GPIO_PIN_0
#define CD_SCK_AX0_GPIO_Port GPIOG
#define CD_SCK_AX1_Pin GPIO_PIN_1
#define CD_SCK_AX1_GPIO_Port GPIOG
#define CD_SCK_AX2_Pin GPIO_PIN_2
#define CD_SCK_AX2_GPIO_Port GPIOG
#define CD_SCK_AX3_Pin GPIO_PIN_3
#define CD_SCK_AX3_GPIO_Port GPIOG
#define CD_SDA_AX0_Pin GPIO_PIN_4
#define CD_SDA_AX0_GPIO_Port GPIOG
#define CD_SDA_AX1_Pin GPIO_PIN_5
#define CD_SDA_AX1_GPIO_Port GPIOG
#define CD_SDA_AX2_Pin GPIO_PIN_6
#define CD_SDA_AX2_GPIO_Port GPIOG
#define CD_SDA_AX3_Pin GPIO_PIN_7
#define CD_SDA_AX3_GPIO_Port GPIOG

#define CD_SDA_AY0_Pin GPIO_PIN_8
#define CD_SDA_AY0_GPIO_Port GPIOH
#define CD_SDA_AY1_Pin GPIO_PIN_9
#define CD_SDA_AY1_GPIO_Port GPIOH
#define CD_SDA_AY2_Pin GPIO_PIN_10
#define CD_SDA_AY2_GPIO_Port GPIOH
#define CD_SCK_AY0_Pin GPIO_PIN_14
#define CD_SCK_AY0_GPIO_Port GPIOH
#define CD_SCK_AY1_Pin GPIO_PIN_11
#define CD_SCK_AY1_GPIO_Port GPIOH
#define CD_SCK_AY2_Pin GPIO_PIN_12
#define CD_SCK_AY2_GPIO_Port GPIOH

#define CD_CS_Pin GPIO_PIN_8
#define CD_CS_GPIO_Port GPIOG
#define CD_RESET_Pin GPIO_PIN_10
#define CD_RESET_GPIO_Port GPIOG
#define CD_DATA_Pin GPIO_PIN_11
#define CD_DATA_GPIO_Port GPIOG
#define CD_STROBE_Pin GPIO_PIN_12
#define CD_STROBE_GPIO_Port GPIOG

void i2c_pin_cd_config(uint8_t xl_sck_pin, uint8_t xl_sda_pin, uint8_t stm32_sck_pin, uint8_t stm32_sda_pin);
void cd_switch_init(void);

#endif




