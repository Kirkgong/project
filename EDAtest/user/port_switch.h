#ifndef __PORT_SWITCH_H
#define __PORT_SWITCH_H
#include "driver.h"

#define PIN_CONFIG_WRITE  		0x00 
#define PIN_CONFIG_READ   		0x01

#define PIN_CONFIG_STM2XL		0x00
#define PIN_CONFIG_XL2STM		0x01

#define FPGA_1				0
#define FPGA_2				1

#define SPI2_NSS_FPGA1_Pin GPIO_PIN_6
#define SPI2_NSS_FPGA1_GPIO_Port GPIOI
#define SPI2_NSS_FPGA2_Pin GPIO_PIN_7
#define SPI2_NSS_FPGA2_GPIO_Port GPIOI

#define TX_I2C_OE1_Pin GPIO_PIN_2
#define TX_I2C_OE1_GPIO_Port GPIOH
#define TX_I2C_OE2_Pin GPIO_PIN_3
#define TX_I2C_OE2_GPIO_Port GPIOH
#define TX_I2C_OE3_Pin GPIO_PIN_4
#define TX_I2C_OE3_GPIO_Port GPIOH

#define TX_OE1_Pin GPIO_PIN_0
#define TX_OE1_GPIO_Port GPIOE
#define TX_OE2_Pin GPIO_PIN_1
#define TX_OE2_GPIO_Port GPIOE
#define TX_OE3_Pin GPIO_PIN_2
#define TX_OE3_GPIO_Port GPIOE
#define TX_OE4_Pin GPIO_PIN_3
#define TX_OE4_GPIO_Port GPIOE
#define TX_OE5_Pin GPIO_PIN_4
#define TX_OE5_GPIO_Port GPIOE
#define TX_OE6_Pin GPIO_PIN_5
#define TX_OE6_GPIO_Port GPIOE
#define TX_OE7_Pin GPIO_PIN_6
#define TX_OE7_GPIO_Port GPIOE
#define TX_OE8_Pin GPIO_PIN_7
#define TX_OE8_GPIO_Port GPIOE
#define TX_OE9_Pin GPIO_PIN_12
#define TX_OE9_GPIO_Port GPIOE
#define TX_OE10_Pin GPIO_PIN_15
#define TX_OE10_GPIO_Port GPIOE
#define TX_OE11_Pin GPIO_PIN_9
#define TX_OE11_GPIO_Port GPIOG

typedef enum
{
	FPGA1_I2C_4LIN_SDA_IN,				//0
	FPGA1_I2C_4LIN_SDA_OUT,				//1
	FPGA1_I2C_4LIN_SCL_IN,				//2
	FPGA1_I2C_4LIN_SCL_OUT,				//3
	CAN_TX_XL6600,								//4
	CAN_RX_XL6600,								//5
	LIN_RX_XL6600,								//6
	LIN_TX_XL6600,								//7
	STM32_GPIOA_PIN_9,						//8				//USART1_TX
	STM32_GPIOA_PIN_10,						//9				//USART1_RX
	STM32_GPIOE_PIN_11,						//10			//STM32_TIM1_CH2
	STM32_GPIOE_PIN_9,						//11			//STM32_TIM1_CH1
	STM32_GPIOE_PIN_13,						//12			//STM32_TIM1_CH3
	STM32_GPIOE_PIN_14,						//13			//STM32_TIM1_CH4
	STM32_GPIOI_PIN_5,						//14			//SPI1_NSS_FPGA
	STM32_GPIOB_PIN_3,						//15			//SPI1_SCK_FPGA
	STM32_GPIOA_PIN_6,						//16			//SPI1_MISO_FPGA
	STM32_GPIOA_PIN_7,						//17			//SPI1_MOSI_FPGA
}PORT_A_PIN;



#define STM32_UART_TX_PIN						STM32_GPIOA_PIN_9
#define STM32_UART_RX_PIN						STM32_GPIOA_PIN_10
#define STM32_SPI_SCK_PIN						STM32_GPIOB_PIN_3
#define STM32_SPI_MOSI_PIN					STM32_GPIOA_PIN_7
#define STM32_SPI_MISO_PIN					STM32_GPIOA_PIN_6
#define STM32_SPI_CS_PIN						STM32_GPIOI_PIN_5
#define STM32_INPUT_CAPTURE_PIN			STM32_GPIOE_PIN_11
#define STM32_KBI_SIGNAL_PIN				STM32_GPIOE_PIN_9
#define STM32_KBI_STIMULATE_PIN			STM32_GPIOE_PIN_11
#define STM32_OUTPUT_COMPARE_PIN 		STM32_GPIOE_PIN_9

typedef enum
{
	XL_PIN_1,
	XL_PIN_2,
	XL_PIN_3,
	XL_PIN_4,
	XL_PIN_5,
	XL_PIN_6,
	XL_PIN_7,
	XL_PIN_8,
	XL_PIN_9,
	XL_PIN_10,
	XL_PIN_11,
	XL_PIN_12,
	XL_PIN_13,
	XL_PIN_14,
	XL_PIN_15,
	XL_PIN_16,
	XL_PIN_17,
	XL_PIN_18,
	XL_PIN_19,
	XL_PIN_20,
	XL_PIN_21,
	XL_PIN_22,
	XL_PIN_23,
	XL_PIN_24,
	XL_PIN_25,
	XL_PIN_26,
	XL_PIN_27,
	XL_PIN_28,
	XL_PIN_29,
	XL_PIN_30,
	XL_PIN_31,
	XL_PIN_32,
	XL_PIN_33,
	XL_PIN_34,
	XL_PIN_35,
	XL_PIN_36,
	XL_PIN_37,
	XL_PIN_38,
	XL_PIN_39,
	XL_PIN_40,
	XL_PIN_41,
	XL_PIN_42,
	XL_PIN_43,
	XL_PIN_45,
	XL_PIN_44,
	XL_PIN_46,
	XL_PIN_47,
	XL_PIN_48,
	XL_PIN_49,
	XL_PIN_50,
	XL_PIN_51,
	XL_PIN_52,
	XL_PIN_53,
	XL_PIN_54,
	XL_PIN_55,
	XL_PIN_56,
	XL_PIN_57,
	XL_PIN_58,
	XL_PIN_59,
	XL_PIN_60,
	XL_PIN_61,
	XL_PIN_62,
	XL_PIN_63,
	XL_PIN_64,
	XL_PIN_65,
	XL_PIN_66,
	XL_PIN_67,
	XL_PIN_68,
	XL_PIN_69,
	XL_PIN_70,
	XL_PIN_71,
	XL_PIN_72,
	XL_PIN_NULL,
}XL_PIN;


typedef enum
{
	E_PAD_PIN_PTD1,
	E_PAD_PIN_PTD0,
	E_PAD_PIN_PTH7,
	E_PAD_PIN_PTH6,
	E_PAD_PIN_PTH5,
	E_PAD_PIN_PTE7,
	E_PAD_PIN_PTH2,
	E_PAD_PIN_VDD_8,
	E_PAD_PIN_VDDA,
	E_PAD_PIN_VREFH,
	
	E_PAD_PIN_VREFL,
	E_PAD_PIN_VSS_VSSA,
	E_PAD_PIN_PTB7,
	E_PAD_PIN_PTB6,
	E_PAD_PIN_PTI4,
	E_PAD_PIN_PTI1,
	E_PAD_PIN_PTI0,
	E_PAD_PIN_PTH1,
	E_PAD_PIN_PTH0,
	E_PAD_PIN_PTE6,
	
	E_PAD_PIN_PTE5,
	E_PAD_PIN_PTB5,
	E_PAD_PIN_PTB4,
	E_PAD_PIN_PTC3,
	E_PAD_PIN_PTC2,
	E_PAD_PIN_PTD7,
	E_PAD_PIN_PTD6,
	E_PAD_PIN_PTD5,
	E_PAD_PIN_PTI6,
	E_PAD_PIN_PTI5,
	
	E_PAD_PIN_PTC1,
	E_PAD_PIN_PTC0,
	E_PAD_PIN_PTH4,
	E_PAD_PIN_PTH3,
	E_PAD_PIN_PTF7,
	E_PAD_PIN_PTF6,
	E_PAD_PIN_PTF5,
	E_PAD_PIN_PTF4,
	E_PAD_PIN_PTB3,
	E_PAD_PIN_PTB2,
	
	E_PAD_PIN_PTB1,
	E_PAD_PIN_PTB0,
	E_PAD_PIN_PTF3,
	E_PAD_PIN_PTF2,
	E_PAD_PIN_PTA7,
	E_PAD_PIN_PTA6,
	E_PAD_PIN_PTE4,
	E_PAD_PIN_VSS_48,
	E_PAD_PIN_VDD_49,
	E_PAD_PIN_PTG7,
	
	E_PAD_PIN_PTG6,
	E_PAD_PIN_PTG5,
	E_PAD_PIN_PTG4,
	E_PAD_PIN_PTF1,
	E_PAD_PIN_PTF0,
	E_PAD_PIN_PTD4,
	E_PAD_PIN_PTD3,
	E_PAD_PIN_PTD2,
	E_PAD_PIN_PTA3,
	E_PAD_PIN_PTA2,
	
	E_PAD_PIN_PTA1,
	E_PAD_PIN_PTA0,
	E_PAD_PIN_PTC7,
	E_PAD_PIN_PTC6,
	E_PAD_PIN_PTI3,
	E_PAD_PIN_PTI2,
	E_PAD_PIN_PTE3,
	E_PAD_PIN_PTE2,
	E_PAD_PIN_VSS_69,
	E_PAD_PIN_VDD_70,
	
	E_PAD_PIN_PTG3,
	E_PAD_PIN_PTG2,
	E_PAD_PIN_PTG1,
	E_PAD_PIN_PTG0,
	E_PAD_PIN_PTE1,
	E_PAD_PIN_PTE0,
	E_PAD_PIN_PTC5,
	E_PAD_PIN_PTC4,
	E_PAD_PIN_PTA5,
	E_PAD_PIN_PTA4,
}E_PAD_PIN;

void port_switch_init(void);
void stop_change(void);
void FPGA1STM_FPGA1XL_config(uint8_t xl_pin, uint8_t stm_pin, uint8_t dir);
void delay_long(void);
void delay_short(void);
uint8_t pin_read(uint8_t xl_pin, uint8_t stm_pin, uint8_t dir,  uint8_t cs);
void start_change(void);
void reset_config(void);
void clear_success_flag(void);
uint8_t get_success_flag(void);
void OE_Enable(void);
void OE_Disable(void);
void I2C_OE_Enable(void);
void I2C_OE_Disable(void);
uint8_t pin_switch(uint32_t address, uint32_t data);
#endif




