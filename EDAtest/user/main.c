
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "port_switch.h"
#include "cd_switch.h"
#include "port.h"
#include "protocol.h"
#include "overtime.h"
#include "fifo.h"
#include "stdio.h"
#include <unistd.h>
#include "math.h"

uint32_t lec_shank = 0;

uint8_t xl6600_rx_fifo_buf[1024];
FifoQueue xl6600_rx_fifo;

/**
  * @brief  This function handles TIM interrupt request.
  * @retval None
  */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

int main(void)
{
  uint32_t count = 0;

  SystemClock_Config();
  port_init(&port);
  protocol_init(&protocol);
  overtime_init();
  port_switch_init();
  cd_switch_init();
  OE_Enable();
  I2C_OE_Disable();	

  int a = sin(5);
	
  QueueInit(&xl6600_rx_fifo, xl6600_rx_fifo_buf, sizeof(xl6600_rx_fifo_buf));
  
  XL6600PortToEDAInit();

  printf("start");
	
  while (1)
  {
		if(protocol.trigger == 1)
		{
			protocol.cmd(&protocol);
			protocol.trigger = 0;
		    //led shank times
			lec_shank = 300;
		}
		
		{
			uint8_t rx_data;
			if(QueueOut(&xl6600_rx_fifo, &rx_data) == 2)
			{
				port.receive_data(&port, rx_data);
				if(rx_data == 0x7E)
				{
					protocol.exec(&protocol, port.rx_buf, &port.head, &port.tail);
				}
			}
		}
		
		XL6600DataReadFromEDA();

    count++;
    if((count % 10000) == 0)
    {
      printf("test\r\n");
    }

    sleep(0.001);
  }
}


//xl6600�յ�EDA�����ݺ�ֱ��ת��
void aufi_data_read_callback(unsigned char *buffer, unsigned int length)
{
	
	for(uint32_t i=0; i < length; i++)
	{
		QueueIn(&xl6600_rx_fifo, buffer[i]);
	}
}


//xl6600�յ�EDA�����ݺ�ֱ��ת��
//void aufi_data_read_callback(unsigned char *buffer, unsigned int length)
//{
//	uint8_t rx_data;
//	
//	for(uint32_t i=0; i < length; i++)
//	{
//		port.receive_data(&port, rx_data);
//		if(rx_data == 0x7E)
//		{
//			protocol.exec(&protocol, port.rx_buf, &port.head, &port.tail);
//		}
//	}
//}

//void USART_CallBack(UART_HandleTypeDef *huart)
//{
//	uint8_t rx_data;
//	
//	if(huart == &huart6)
//	{
//		if(HAL_UART_Receive(&huart6,&rx_data,1,5) == HAL_OK)
//		{
//			port.receive_data(&port, rx_data);
//			if(rx_data == 0x7E)
//			{
//				//protocol.trigger = 1;
//				protocol.exec(&protocol, port.rx_buf, &port.head, &port.tail);
//			}
//		}
//	}
//}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM7 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */



/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
