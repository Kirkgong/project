 /**
  ******************************************************************************
  * @file     xl_uart.c
  * @author   Kirk
  * @version  4.1.2
  * @date     Mon Aug 31 15:38:58 2020
  * @brief    This file provide function about SIM firmware program
  ******************************************************************************
  * @attention
  *
  * 2019 by Chipways Communications,Inc. All Rights Reserved.
  * This software is supplied under the terms of a license
  * agreement or non-disclosure agreement with Chipways.
  * Passing on and copying of this document,and communication
  * of its contents is not permitted without prior written
  * authorization.
  *
  * <h2><center>&copy; COPYRIGHT 2019 Chipways</center></h2>
  ******************************************************************************
  */
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */
	
/* Includes ---------------------------------------------------------------*/
#include "xl_sim.h"

/** @addtogroup XL6600_StdPeriph_Driver
  * @{
  */

/** @defgroup SIM SIM Module
  * @brief SIM Driver Modules Library
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/	
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/** @defgroup SIM_Private_Functions
  * @{
 */


/**
  * @brief  ��������SIM�Ĵ���״̬.
  * @param  None
  * @retval None
  */
void SIM_DeInit(void)
{
	/* Deinitializes to default reset values */
	SIM->SOPT0 = 0x0000000C;
	SIM->SOPT1 = 0x00000000;
	SIM->PINSEL0 = 0x00000000;
	SIM->PINSEL1 = 0x00000000;
	SIM->SCGC = 0x00000800;
	SIM->CLKDIV = 0x00000000;
}

/**
  * @brief  ��ȡ����Family ID
  * @param  None
  * @retval ����FamilyID
  */
uint32_t SIM_ReadFAMID(void)
{
	return (SIM->SRSID & SIM_SRSID_FAMID_MASK) >> SIM_SRSID_FAMID_SHIFT;
}

/**
  * @brief  ��ȡ����SUB Family ID
  * @param  None
  * @retval ����SUB Family ID
  */
uint32_t SIM_ReadSUBFAMID(void)
{
	return (SIM->SRSID & SIM_SRSID_SUBFAMID_MASK) >> SIM_SRSID_SUBFAMID_SHIFT;
}

/**
  * @brief  ��ȡ�����汾��
  * @param  None
  * @retval �����汾��
  */
uint32_t SIM_ReadREVID(void)
{
	return (SIM->SRSID & SIM_SRSID_RevID_MASK) >> SIM_SRSID_RevID_SHIFT;
}

/**
  * @brief  ��ȡ����PINID
  * @param  None
  * @retval PINID ����Pin��ID
  *		�����������ȡ�����ֵ:
  * 		@arg PINID_8_PIN: 8��������
  * 		@arg PINID_16_PIN: 16��������
  * 		@arg PINID_20_PIN: 20��������
  * 		@arg PINID_24_PIN: 24��������
  * 		@arg PINID_32_PIN: 32��������
  * 		@arg PINID_44_PIN: 44��������
  * 		@arg PINID_48_PIN: 48��������
  * 		@arg PINID_64_PIN: 64��������
  * 		@arg PINID_80_PIN: 80��������
  * 		@arg PINID_100_PIN: 100��������
  * 		@arg PINID_RESERVE_PIN: ����
  */
uint32_t SIM_ReadFPINID(void)
{
	return (SIM->SRSID & SIM_SRSID_PINID_MASK) >> SIM_SRSID_PINID_SHIFT;
}

/**
  * @brief  ��ȡ��λԭ��
  * @param  SIM: ��λ��ԭ��
  *		�����������ȡ�����ֵ:
  *			@arg SIM_ECCERR_RESET: ECCУ�����λ
  *			@arg SIM_LVD_RESET: �͵�ѹ������ϵ縴λ
  *			@arg SIM_WDOG_RESET: ���Ź���λ
  *			@arg SIM_PIN_RESET: �ⲿ���Ÿ�λ
  *			@arg SIM_POR_RESET: �ϵ縴λ
  *			@arg SIM_SW_RESET: �����λ
  * @retval ��λ״̬(TRUE or FALSE)
  */
FlagStatus SIM_GetRstCauses(uint32_t ResetCause)
{
	FlagStatus ret;
	
	if( ((SIM->SRSID >> ResetCause)&(uint32_t)0x01) != 0u)
	{
		ret = SET;
	}
	else
	{
		ret = RESET;
	}
	
	return ret;
}

/**
  * @brief  �����λԭ���־
  * @param  SIM: �����λ��ԭ��
  *		�����������ȡ�����ֵ:
  *			@arg SIM_ECCERR_RESET: ECCУ�����λ
  * 		@arg SIM_LVD_RESET: �͵�ѹ������ϵ縴λ
  * 		@arg SIM_WDOG_RESET: ���Ź���λ
  *			@arg SIM_PIN_RESET: �ⲿ���Ÿ�λ
  * 		@arg SIM_POR_RESET: �ϵ縴λ
  *			@arg SIM_SW_RESET: �����λ
  * @retval None
  */
void SIM_ClrRstCauses(uint8_t ResetCause)
{
	SIM->SRSID |= ((uint32_t)0x01 << ResetCause);
}	

/**
  * @brief  NMI����ʹ��
  * @param  State: NMI����ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: NMI����ʹ��
  *			@arg DISABLE: NMI����ʧ��
  * @retval None
  */
void SIM_SOPT0_NMIECmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_NMIE_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_NMIE_MASK;
	}
}

/**
  * @brief  RESET����ʹ��
  * @param  State: RESET����ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: RESET����ʹ��
  *			@arg DISABLE: RESET����ʧ��
  * @retval None
  */
void SIM_SOPT0_RSTPECmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_RSTPE_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_RSTPE_MASK;
	}	
}

/**
  * @brief  SWD����ʹ��
  * @param  State: SWD����ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: SWD����ʹ��
  *			@arg DISABLE: SWD����ʧ��
  * @retval None
  */
void SIM_SOPT0_SWDECmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_SWDE_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_SWDE_MASK;
	}		
}	

/**
  * @brief  ACMP����FTM2����Դѡ��
  * @param  TriggerType: ����Դѡ��
  *		�����������ȡ�����ֵ:
  *			@arg ACMP0_OUTPUT_TRIGGER_FTM2: ACMP0�������FTM2
  *			@arg ACMP1_OUTPUT_TRIGGER_FTM2: ACMP1�������FTM2
  * @retval None
  */
void SIM_SOPT0_ACMPT_FTM2Config(uint8_t TriggerType)
{
	if(TriggerType == ACMP1_OUTPUT_TRIGGER_FTM2)
	{
		SIM->SOPT0 |= SIM_SOPT0_ACTRG_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_ACTRG_MASK;
	}
}	

/**
  * @brief  UART0�����ź��˲���ѡ��
  * @param  FilterType: �˲���ѡ��
  *		�����������ȡ�����ֵ:
  *			@arg UART0_RXD0_FILTER_NONE: ���˲���
  *			@arg UART0_RXD0_FILTER_ACMP0: �˲���ACMP0
  *			@arg UART0_RXD0_FILTER_ACMP1: �˲���ACMP1
  * @retval None
  */
void SIM_SOPT0_UART0FilterConfig(uint32_t FilterType)
{
	SIM->SOPT0 &= ~SIM_SOPT0_RXDFE_MASK;
	SIM->SOPT0 |= (FilterType << SIM_SOPT0_RXDFE_SHIFT);
}

/**
  * @brief  FTM1ͨ��1��׽RTC���ʹ��
  * @param  State: FTM1ͨ��1��׽RTC���ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: ʹ��FTM1ͨ��1��׽RTC���
  *			@arg DISABLE: ʧ��FTM1ͨ��1��׽RTC���
  * @retval None
  */
void SIM_SOPT0_FTM1CH1C_RTCOutputCmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_RTCC_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_RTCC_MASK;
	}		
}	

/**
  * @brief  FTM1ͨ��0��׽ACMP0���ʹ��
  * @param  State: FTM1ͨ��0��׽ACMP0���ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: ʹ��FTM1ͨ��0��׽ACMP0���
  *			@arg DISABLE: ʧ��FTM1ͨ��0��׽ACMP0���
  * @retval None
  */
void SIM_SOPT0_FTM1CH0C_ACMP0OCmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_ACIC_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_ACIC_MASK;
	}		
}	

/**
  * @brief  FTM0ͨ��1��׽UART0����ʹ��
  * @param  State: FTM0ͨ��1��׽UART0����ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: ʹ��FTM0ͨ��1��׽UART0����
  *			@arg DISABLE: ʧ��FTM0ͨ��1��׽UART0����
  * @retval None
  */
void SIM_SOPT0_FTM0CH1C_UART0ICmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_RXDCE_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_RXDCE_MASK;
	}			
}

/**
  * @brief  ����FTM2ģ���PWMͬ������ʹ��
  * @param  State: ����FTM2ģ���PWMͬ������ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: ʹ������FTM2ģ���PWMͬ������
  *			@arg DISABLE: ʧ������FTM2ģ���PWMͬ������
  * @retval None
  */
void SIM_SOPT0_FTM2S_PWMCmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_FTMSYNC_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_FTMSYNC_MASK;
	}		
}

/**
  * @brief  FTM0ͨ��0����UART0���ʹ��
  * @param  State: FTM0ͨ��0����UART0���ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: ʹ��FTM0ͨ��0����UART0���
  *			@arg DISABLE: ʧ��FTM0ͨ��0����UART0���
  * @retval None
  */
void SIM_SOPT0_FTM0M_UART0OutputCmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_TXDME_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_TXDME_MASK;
	}			
}

/**
  * @brief  ����ʱ���������
  * @param  Divide: ����ʱ�������Ƶ
  *		�����������ȡ�����ֵ:
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_1: ����ʱ�����1��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_2: ����ʱ�����2��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_4: ����ʱ�����4��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_8: ����ʱ�����8��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_16: ����ʱ�����16��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_32: ����ʱ�����32��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_64: ����ʱ�����64��Ƶ
  *			@arg BUSCLOCK_OUTPUT_DIVIDE_128: ����ʱ�����128��Ƶ
  *  @retval None
  */
void SIM_SOPT0_BusClockDivide(uint8_t Divide)
{
	SIM->SOPT0 &= ~SIM_SOPT0_BUSREF_MASK;
	SIM->SOPT0 |= ((uint32_t)Divide << SIM_SOPT0_BUSREF_SHIFT);	
}

/**
  * @brief  ����ʱ�����ʹ��
  * @param  State: ����ʱ�����ʹ��״̬
  *		�����������ȡ�����ֵ:
  *			@arg ENABLE: ʹ������ʱ�����
  *			@arg DISABLE: ʧ������ʱ�����
  * @retval None
  */
void SIM_SOPT0_BusClockOutputCmd(FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SOPT0 |= SIM_SOPT0_CLKOE_MASK;
	}
	else
	{
		SIM->SOPT0 &= ~SIM_SOPT0_CLKOE_MASK;
	}		
}

/**
  * @brief  ��ȡFTM2�����ӳ�״̬
  * @param  None
  * @retval FTM2�����ӳ�״̬(TRUE or FALSE)
  */
FlagStatus SIM_SOPT0_FTM2DelayTStatus(void)
{
	FlagStatus ret;
	
	if( ((SIM->SOPT0 & SIM_SOPT0_DLYACT_MASK) >> SIM_SOPT0_DLYACT_SHIFT) != 0u)
	{
		ret = SET;
	}
	else
	{
		ret = RESET;
	}
	
	return ret;
}

/**
  * @brief  ����FTM2����ADC�����ӳ�ʱ��
  * @param  Delay: FTM2����ADC�����ӳ�ʱ��(0~255)
  * @retval None
  */
void SIM_SOPT0_FTM2DelayTConfig(uint8_t Delay)
{
	SIM->SOPT0 &= ~SIM_SOPT0_DELAY_MASK;
	SIM->SOPT0 |= ((uint32_t)Delay << SIM_SOPT0_DELAY_SHIFT);	
}


/**
 * @brief  PWTIN2�����ź�ѡ��
 * @param  InputType: PWTIN2�����ź�
 *		�����������ȡ�����ֵ:
 *			@arg PWTIN2_INPUT_ACMP1OUT: ACMP1�����ΪPWTIN2������
 *			@arg PWTIN2_INPUT_ACMP0OUT: ACMP0�����ΪPWTIN2������
 * @retval None
 */
void SIM_SOPT1_PWTIN2InputConfig(uint8_t InputType)
{
	if(InputType == PWTIN2_INPUT_ACMP0OUT)
	{
		SIM->SOPT1 |= SIM_SOPT1_ACPWTS_MASK;
	}
	else
	{
		SIM->SOPT1 &= ~SIM_SOPT1_ACPWTS_MASK;
	}
}

/**
 * @brief  PWTIN3�����ź�ѡ��
 * @param  None
 * @param  InputType: PWTIN3�����ź�
 *		�����������ȡ�����ֵ:
 *			@arg PWTIN3_INPUT_UART0RX: UART0������ΪPWTIN3������
 *			@arg PWTIN3_INPUT_UART1RX: UART1������ΪPWTIN3������
 *			@arg PWTIN3_INPUT_UART2RX: UART2������ΪPWTIN3������
 * @retval None
 */
void SIM_SOPT1_PWTIN3InputConfig(uint8_t InputType)
{
	SIM->SOPT1 &= ~SIM_SOPT1_UARTPWTS_MASK;
	SIM->SOPT1 |= ((uint32_t)InputType << SIM_SOPT1_UARTPWTS_SHIFT);		
}

/**
 * @brief  ADCӲ������Դѡ��
 * @param  TriggerType: ADCӲ������Դ
 *		�����������ȡ�����ֵ:
 *			@arg ADC_HT_RTCOVERFLOW: RTC�������
 *			@arg ADC_HT_FTM0: FTM0����
 *			@arg ADC_HT_FTM2UPDATE: FTM2��ʼ����
 *			@arg ADC_HT_FTM2CAPTURE: FTM2ƥ�䴥��
 *			@arg ADC_HT_PITCH0OVERFLOW: PITͨ��0�������
 *			@arg ADC_HT_PITCH1OVERFLOW: PITͨ��1�������
 *			@arg ADC_HT_ACMP0OUTPUT: ACMP0�������
 *			@arg ADC_HT_ACMP1OUTPUT: ACMP1�������
 *			@arg ADC_HT_FTM2CH1MAP:	 FTM2ͨ��1ƥ�䴥��		  
 *			@arg ADC_HT_FTM2CH2MAP:	 FTM2ͨ��2ƥ�䴥��		  
 *			@arg ADC_HT_FTM2CH3MAP:	 FTM2ͨ��3ƥ�䴥��		  
 *			@arg ADC_HT_FTM2CH4MAP:	 FTM2ͨ��4ƥ�䴥��		  
 *			@arg ADC_HT_FTM2CH5MAP:	 FTM2ͨ��5ƥ�䴥��		  
 *			@arg ADC_HT_FTM1CH0MAP:	 FTM1ͨ��0ƥ�䴥��		  
 *			@arg ADC_HT_FTM1CH1MAP:	 FTM1ͨ��1ƥ�䴥��		  
 *			@arg ADC_HT_FTM0CH1MAP:	 FTM0ͨ��1ƥ�䴥��		  
 * @retval None
 */
void SIM_SOPT1_ADCHardwareTConfig(uint8_t TriggerType)
{
	SIM->SOPT1 &= ~SIM_SOPT1_ADHWT_MASK;
	SIM->SOPT1 |= ((uint32_t)TriggerType << SIM_SOPT1_ADHWT_SHIFT);		
}

/**
 * @brief  UART0�˿�����ѡ�� 20190729XU
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg UART0_PS_PTB0_PTB1: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTB0��PTB1��
 *			@arg UART0_PS_PTA2_PTA3: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTA2��PTA3��
 *			@arg UART0_PS_PTC2_PTC3: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTC2��PTC3��
 * @retval None
 */
void SIM_PINSEL_UART0(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_UART0PS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_UART0PS_SHIFT);			
}

/**
 * @brief  FTM0ͨ��0�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM0CH0_PS_PTA0: FTM0_CH0ͨ��ӳ�䵽PTA0��
 *			@arg FTM0CH0_PS_PTB2: FTM0_CH0ͨ��ӳ�䵽PTB2��
 *			@arg FTM0CH0_PS_PTE5: FTM0_CH0ͨ��ӳ�䵽PTE5��
 *			@arg FTM0CH0_PS_PTF4: FTM0_CH0ͨ��ӳ�䵽PTF4��
 * @retval None
 */
void SIM_PINSEL_FTM0CH0(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM0PS0_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM0PS0_SHIFT);			
}

/**
 * @brief  FTM0ͨ��1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM0CH1_PS_PTA1: FTM0_CH1ͨ��ӳ�䵽PTA1��
 *			@arg FTM0CH1_PS_PTB3: FTM0_CH1ͨ��ӳ�䵽PTB3��
 *			@arg FTM0CH1_PS_PTE6: FTM0_CH1ͨ��ӳ�䵽PTE6��
 *			@arg FTM0CH1_PS_PTF5: FTM0_CH1ͨ��ӳ�䵽PTF5��
 * @retval None
 */
void SIM_PINSEL_FTM0CH1(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM0PS1_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM0PS1_SHIFT);			
}

/**
 * @brief  FTM1ͨ��0�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM1CH0_PS_PTC4: FTM1_CH0ͨ��ӳ�䵽PTC4��
 *			@arg FTM1CH0_PS_PTH2: FTM1_CH0ͨ��ӳ�䵽PTH2��
 *			@arg FTM1CH0_PS_PTE5: FTM1_CH0ͨ��ӳ�䵽PTE5��
 * @retval None
 */
void SIM_PINSEL_FTM1CH0(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM1PS0_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM1PS0_SHIFT);			
}

/**
 * @brief  FTM1ͨ��1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM1CH1_PS_PTC5: FTM1_CH1ͨ��ӳ�䵽PTC5��
 *			@arg FTM1CH1_PS_PTE7: FTM1_CH1ͨ��ӳ�䵽PTE7��
 *			@arg FTM1CH1_PS_PTE6: FTM1_CH1ͨ��ӳ�䵽PTE6��
 * @retval None
 */
void SIM_PINSEL_FTM1CH1(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM1PS1_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM1PS1_SHIFT);			
}

/**
 * @brief  FTM_FLT2����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM_FLT2_PS_PTA7: FTM_FLT2ͨ��ӳ�䵽PTA7
 *			@arg FTM_FLT2_PS_PTI1: FTM_FLT2ͨ��ӳ�䵽PTI1
 *			@arg FTM_FLT2_PS_PTF7: FTM_FLT2ͨ��ӳ�䵽PTF7
 *			@arg FTM_FLT2_PS_PTF6: FTM_FLT2ͨ��ӳ�䵽PTF6
 * @retval None
 */
void SIM_PINSEL_FTMFLT2(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTMFLT2PS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTMFLT2PS_SHIFT);			
}

/**
 * @brief  FTM_FLT1����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM_FLT1_PS_PTA6: FTM_FLT1ͨ��ӳ�䵽PTA7
 *			@arg FTM_FLT2_PS_PTI1: FTM_FLT1ͨ��ӳ�䵽PTI1
 *			@arg FTM_FLT2_PS_PTF7: FTM_FLT1ͨ��ӳ�䵽PTF7
 *			@arg FTM_FLT2_PS_PTF6: FTM_FLT1ͨ��ӳ�䵽PTF6
 * @retval None
 */
void SIM_PINSEL_FTMFLT1(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTMFLT1PS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTMFLT1PS_SHIFT);			
}

/**
 * @brief  BUSOUT�������ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg BUSOUT_PS_PTH2: BUSOUTͨ��ӳ�䵽PTH2
 *			@arg BUSOUT_PS_PTH6: BUSOUTͨ��ӳ�䵽PTH6
 *			@arg BUSOUT_PS_PTB5: BUSOUTͨ��ӳ�䵽PTB5
 * @retval None
 */
void SIM_PINSEL_BUSOUT(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_BUSOUTPS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_BUSOUTPS_SHIFT);			
}

/**
 * @brief  TCLK2����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg TCLK2_PS_PTE7: TCLK2ѡ������PTE7
 *			@arg TCLK2_PS_PTH7: TCLK2ѡ������PTH7
 *			@arg TCLK2_PS_PTD5: TCLK2ѡ������PTD5
 * @retval None
 */
void SIM_PINSEL_TCLK2(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_TCLK2PS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_TCLK2PS_SHIFT);			
}

/**
 * @brief  TCLK1����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg TCLK1_PS_PTE0: TCLK1ѡ������PTE0
 *			@arg TCLK1_PS_PTH7: TCLK1ѡ������PTH7
 *			@arg TCLK1_PS_PTD5: TCLK1ѡ������PTD5
 * @retval None
 */
void SIM_PINSEL_TCLK1(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_TCLK1PS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_TCLK1PS_SHIFT);			
}

/**
 * @brief  TCLK0����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg TCLK0_PS_PTA5: TCLK0ѡ������PTA5
 *			@arg TCLK0_PS_PTH7: TCLK0ѡ������PTH7
 *			@arg TCLK0_PS_PTD5: TCLK0ѡ������PTD5
 * @retval None
 */
void SIM_PINSEL_TCLK0(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_TCLK0PS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_TCLK0PS_SHIFT);			
}

/**
 * @brief  FTM0TCLK����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM0CLK_PS_TCLK0: ѡ��TCLK0����FTM0ģ��
 *			@arg FTM0CLK_PS_TCLK1: ѡ��TCLK1����FTM0ģ��
 *			@arg FTM0CLK_PS_TCLK2: ѡ��TCLK2����FTM0ģ��
 * @retval None
 */
void SIM_PINSEL_FTM0TCLK(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM0CLKPS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM0CLKPS_SHIFT);			
}

/**
 * @brief  FTM1TCLK����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM1CLK_PS_TCLK0: ѡ��TCLK0����FTM1ģ��
 *			@arg FTM1CLK_PS_TCLK1: ѡ��TCLK1����FTM1ģ��
 *			@arg FTM1CLK_PS_TCLK2: ѡ��TCLK2����FTM1ģ��
 * @retval None
 */
void SIM_PINSEL_FTM1TCLK(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM1CLKPS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM1CLKPS_SHIFT);	
}

/**
 * @brief  FTM2TCLK����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CLK_PS_TCLK0: ѡ��TCLK0����FTM2ģ��
 *			@arg FTM2CLK_PS_TCLK1: ѡ��TCLK1����FTM2ģ��
 *			@arg FTM2CLK_PS_TCLK2: ѡ��TCLK2����FTM2ģ��
 * @retval None
 */
void SIM_PINSEL_FTM2TCLK(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_FTM2CLKPS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_FTM2CLKPS_SHIFT);	
}

/**
 * @brief  PWTCLK����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg PWTCLK_PS_TCLK0: ѡ��TCLK0����PWTģ��
 *			@arg PWTCLK_PS_TCLK1: ѡ��TCLK1����PWTģ��
 *			@arg PWTCLK_PS_TCLK2: ѡ��TCLK2����PWTģ��
 * @retval None
 */
void SIM_PINSEL_PWTTCLK(uint8_t PinSelect)
{
	SIM->PINSEL0 &= ~SIM_PINSEL0_PWTCLKPS_MASK;
	SIM->PINSEL0 |= ((uint32_t)PinSelect << SIM_PINSEL0_PWTCLKPS_SHIFT);	
}

/**
 * @brief  FTM2ͨ��0�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH0_PS_PTC0: FTM2_CH0ͨ��ӳ�䵽PTC0��
 *			@arg FTM2CH0_PS_PTH0: FTM2_CH0ͨ��ӳ�䵽PTH0��
 *			@arg FTM2CH0_PS_PTF0: FTM2_CH0ͨ��ӳ�䵽PTF0��
 * @retval None
 */
void SIM_PINSEL_FTM2CH0(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS0_MASK;
	SIM->PINSEL1 |= (uint32_t)PinSelect;	
}

/**
 * @brief  FTM2ͨ��1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH1_PS_PTC1: FTM2_CH1ͨ��ӳ�䵽PTC1��
 *			@arg FTM2CH1_PS_PTH1: FTM2_CH1ͨ��ӳ�䵽PTH1��
 *			@arg FTM2CH1_PS_PTF1: FTM2_CH1ͨ��ӳ�䵽PTF1��
 * @retval None
 */
void SIM_PINSEL_FTM2CH1(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS1_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS1_SHIFT);	
}

/**
 * @brief  FTM2ͨ��2�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH2_PS_PTC2: FTM2_CH2ͨ��ӳ�䵽PTC2��
 *			@arg FTM2CH2_PS_PTD0: FTM2_CH2ͨ��ӳ�䵽PTD0��
 *			@arg FTM2CH2_PS_PTG4: FTM2_CH2ͨ��ӳ�䵽PTG4��
 * @retval None
 */
void SIM_PINSEL_FTM2CH2(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS2_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS2_SHIFT);	
}

/**
 * @brief  FTM2ͨ��3�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH3_PS_PTC3: FTM2_CH3ͨ��ӳ�䵽PTC3��
 *			@arg FTM2CH3_PS_PTD1: FTM2_CH3ͨ��ӳ�䵽PTD1��
 *			@arg FTM2CH3_PS_PTG5: FTM2_CH3ͨ��ӳ�䵽PTG5��
 * @retval None
 */
void SIM_PINSEL_FTM2CH3(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS3_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS3_SHIFT);	
}

/**
 * @brief  FTM2ͨ��4�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH4_PS_PTB4: FTM2_CH4ͨ��ӳ�䵽PTB4��
 *			@arg FTM2CH4_PS_PTG6: FTM2_CH4ͨ��ӳ�䵽PTG6��
 * @retval None
 */
void SIM_PINSEL_FTM2CH4(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS4_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS4_SHIFT);	
}

/**
 * @brief  FTM2ͨ��5�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH5_PS_PTB5: FTM2_CH5ͨ��ӳ�䵽PTB5��
 *			@arg FTM2CH5_PS_PTG7: FTM2_CH5ͨ��ӳ�䵽PTG7��
 * @retval None
 */
void SIM_PINSEL_FTM2CH5(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS5_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS5_SHIFT);	
}

/**
 * @brief  I2C1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg I2C1_PS_PTE1_PTE0: I2C1_SCL��I2C1_SDA�ֱ�ӳ�䵽PTE1��PTE0��
 *			@arg I2C1_PS_PTH4_PTH3: I2C1_SCL��I2C1_SDA�ֱ�ӳ�䵽PTH4��PTH3��
 * @retval None
 */
void SIM_PINSEL_I2C1(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_I2C1PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_I2C1PS_SHIFT);		
}

/**
 * @brief  SPI1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg SPI1_PS_PTD0_PTD1_PTD2_PTD3: SPI0_SCK,SPI0_MOSI,SPI0_MISO��SPI0_CS�ֱ�ӳ�䵽PTD0,PTD1,PTD2��PTD3��
 *			@arg SPI1_PS_PTG4_PTG5_PTG6_PTG7: SPI0_SCK,SPI0_MOSI,SPI0_MISO��SPI0_CS�ֱ�ӳ�䵽PTG4,PTG5,PTG6��PTG7��
 * @retval None
 */
void SIM_PINSEL_SPI1(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_SPI1PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_SPI1PS_SHIFT);		
}

/**
 * @brief  UART1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg UART1_PS_PTC7_PTC6: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTC7��PTC6��
 *			@arg UART1_PS_PTF3_PTF2: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTF3��PTF2��
 * @retval None
 */
void SIM_PINSEL_UART1(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_UART1PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_UART1PS_SHIFT);		
}

/**
 * @brief  UART2�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg UART2_PS_PTD7_PTD6: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTD7��PTD6��
 *			@arg UART2_PS_PTI1_PTI0: UART0_RX��UART0_TX�ֱ�ӳ�䵽PTI1��PTI0��
 * @retval None
 */
void SIM_PINSEL_UART2(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_UART2PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_UART2PS_SHIFT);		
}

/**
 * @brief  PWTIN0�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg PWTIN0_PS_PTD5: PWTIN0����ӳ�䵽PTD5��
 *			@arg PWTIN0_PS_PTE2: PWTIN0����ӳ�䵽PTE2��
 * @retval None
 */
void SIM_PINSEL_PWTIN0(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_PWTIN0PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_PWTIN0PS_SHIFT);		
}

/**
 * @brief  PWTIN1�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg PWTIN1_PS_PTB0: PWTIN0����ӳ�䵽PTB0��
 *			@arg PWTIN1_PS_PTH7: PWTIN0����ӳ�䵽PTH7��
 * @retval None
 */
void SIM_PINSEL_PWTIN1(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_PWTIN1PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_PWTIN1PS_SHIFT);		
}

/**
 * @brief  SPI0�˿�����ѡ�� 20190729XU
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg SPI0_PS_PTB2_PTB3_PTB4_PTB5: SPI0_SCK,SPI0_MOSI,SPI0_MISO��SPI0_CS�ֱ�ӳ�䵽PTB2,PTB3,PTB4��PTB5��
 *			@arg SPI0_PS_PTE0_PTE1_PTE2_PTE3: SPI0_SCK,SPI0_MOSI,SPI0_MISO��SPI0_CS�ֱ�ӳ�䵽PTE0,PTE1,PTE2��PTE3��
 * @retval None
 */
void SIM_PINSEL_SPI0(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_SPI0PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_SPI0PS_SHIFT);		
}

/**
 * @brief  EWM�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg EWM_PS_PTA3_PTA2: EWM_IN��EWM_RESET�ֱ�ӳ�䵽PTA3��PTA2��
 *			@arg EWM_PS_PTC4_PTA4: EWM_IN��EWM_RESET�ֱ�ӳ�䵽PTC4��PTA4��
 *			@arg EWM_PS_PTE7_PTH2: EWM_IN��EWM_RESET�ֱ�ӳ�䵽PTE7��PTH2��
 * @retval None
 */
void SIM_PINSEL_EWM(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_EWMPS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_EWMPS_SHIFT);		
}

/**
 * @brief  IRQ�˿�����ѡ�� 20190729XU
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg IRQ_PS_GROUP1: IRQӳ�䵽��һ��PIN����
 *			@arg IRQ_PS_GROUP2: IRQӳ�䵽�ڶ���PIN����
 *			@arg IRQ_PS_GROUP3: IRQӳ�䵽������PIN����
 *			@arg IRQ_PS_GROUP4: IRQӳ�䵽������PIN����
 *			@arg IRQ_PS_GROUP5: IRQӳ�䵽������PIN����
 * @retval None
 */
void SIM_PINSEL_IRQ(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_IRQPS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_IRQPS_SHIFT);		
}

/**
 * @brief  ACMP1���PS�˿�����ѡ�� 20190729XU
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg ACMP1_PS_PTB5: ACMP1���ӳ�䵽PTB5��
 *			@arg ACMP1_PS_PTI1: ACMP1���ӳ�䵽PTI1��
 * @retval None
 */
void SIM_PINSEL_ACMP(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_ACMP1PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_ACMP1PS_SHIFT);		
}

/**
 * @brief  RTC���PS�˿�����ѡ�� 20190729XU
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg RTCO_PS_PTC4: RTC���ӳ�䵽PTC4��
 *			@arg RTCO_PS_PTC5: RTC���ӳ�䵽PTC5��
 * @retval None
 */
void SIM_PINSEL_RTC(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_RTCPS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_RTCPS_SHIFT);		
}

/**
 * @brief  I2C0�˿�����ѡ�� 20190729XU
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg I2C0_PS_PTA3_PTA2: I2C0_SCL��I2C0_SDA�ֱ�ӳ�䵽PTA3��PTA2��
 *			@arg I2C0_PS_PTB7_PTB6: I2C0_SCL��I2C0_SDA�ֱ�ӳ�䵽PTB7��PTB6��
 * @retval None
 */
void SIM_PINSEL_I2C0(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_I2C0PS_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_I2C0PS_SHIFT);		
}

/**
 * @brief  FTM0ͨ��2�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM0CH2_PS_PTH7: FTM0_CH2ͨ��ӳ�䵽PTH7��
 *			@arg FTM0CH2_PS_PTD5: FTM0_CH2ͨ��ӳ�䵽PTD5��
 * @retval None
 */
void SIM_PINSEL_FTM0CH2(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM0PS2_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM0PS2_SHIFT);		
}

/**
 * @brief  FTM0ͨ��3�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM0CH3_PS_PTE4: FTM0_CH3ͨ��ӳ�䵽PTE4��
 *			@arg FTM0CH3_PS_PTD4: FTM0_CH3ͨ��ӳ�䵽PTD4��
 * @retval None
 */
void SIM_PINSEL_FTM0CH3(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM0PS3_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM0PS3_SHIFT);		
}

/**
 * @brief  FTM1ͨ��2�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM1CH2_PS_PTH1: FTM1_CH2ͨ��ӳ�䵽PTH1��
 *			@arg FTM1CH2_PS_PTB4: FTM1_CH2ͨ��ӳ�䵽PTB4��
 * @retval None
 */
void SIM_PINSEL_FTM1CH2(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM1PS2_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM1PS2_SHIFT);		
}

/**
 * @brief  FTM1ͨ��3�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM1CH3_PS_PTH0: FTM1_CH3ͨ��ӳ�䵽PTE4��
 *			@arg FTM1CH3_PS_PTE3: FTM1_CH3ͨ��ӳ�䵽PTD4��
 * @retval None
 */
void SIM_PINSEL_FTM1CH3(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM1PS3_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM1PS3_SHIFT);		
}

/**
 * @brief  FTM2ͨ��6�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH6_PS_PTF3: FTM2_CH6ͨ��ӳ�䵽PTF3��
 *			@arg FTM2CH6_PS_PTD3: FTM2_CH6ͨ��ӳ�䵽PTD3��
 * @retval None
 */
void SIM_PINSEL_FTM2CH6(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS6_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS6_SHIFT);		
}

/**
 * @brief  FTM2ͨ��7�˿�����ѡ��
 * @param  PinSelect: ����ѡ��
 *		�����������ȡ�����ֵ:
 *			@arg FTM2CH7_PS_PTF2: FTM2_CH7ͨ��ӳ�䵽PTF2��
 *			@arg FTM2CH7_PS_PTD2: FTM2_CH7ͨ��ӳ�䵽PTD2��
 * @retval None
 */
void SIM_PINSEL_FTM2CH7(uint8_t PinSelect)
{
	SIM->PINSEL1 &= ~SIM_PINSEL1_FTM2PS7_MASK;
	SIM->PINSEL1 |= ((uint32_t)PinSelect << SIM_PINSEL1_FTM2PS7_SHIFT);		
}

/**
 * @brief  ϵͳʱ��ѡͨ
 * @param  SCGC_Type: ָ������ʱ��ʹ��״̬
 *		�����������Ϊ����ֵ:
 *			@arg SIM_SCGC_RTC: RTCʱ��ѡͨ
 *			@arg SIM_SCGC_PIT: PITʱ��ѡͨ
 *			@arg SIM_SCGC_EWM: EWMʱ��ѡͨ
 *			@arg SIM_SCGC_PWT: PWTʱ��ѡͨ
 *			@arg SIM_SCGC_FTM0: FTM0ʱ��ѡͨ
 *			@arg SIM_SCGC_FTM1: FTM1ʱ��ѡͨ
 *			@arg SIM_SCGC_FTM2: FTM2ʱ��ѡͨ
 *			@arg SIM_SCGC_CLMA: FTM2ʱ��ѡͨ
 *			@arg SIM_SCGC_CLMB: FTM2ʱ��ѡͨ
 *			@arg SIM_SCGC_CRC: CRCʱ��ѡͨ
 *			@arg SIM_SCGC_WDG: WDGʱ��ѡͨ
 *			@arg SIM_SCGC_MCAN: MCANʱ��ѡͨ
 *			@arg SIM_SCGC_I2C0: I2C0ʱ��ѡͨ
 *			@arg SIM_SCGC_I2C1: I2C1ʱ��ѡͨ
 *			@arg SIM_SCGC_SPI0: SPI0ʱ��ѡͨ
 *			@arg SIM_SCGC_SPI1: SPI1ʱ��ѡͨ
 *			@arg SIM_SCGC_UART0: UART0ʱ��ѡͨ
 *			@arg SIM_SCGC_UART1: UART1ʱ��ѡͨ
 *			@arg SIM_SCGC_UART2: UART2ʱ��ѡͨ
 *			@arg SIM_SCGC_KBI0: KBI0ʱ��ѡͨ
 *			@arg SIM_SCGC_KBI1: KBI1ʱ��ѡͨ
 *			@arg SIM_SCGC_IRQ: IRQʱ��ѡͨ
 *			@arg SIM_SCGC_DMA: DMAʱ��ѡͨ
 *			@arg SIM_SCGC_ADC: ADCʱ��ѡͨ
 *			@arg SIM_SCGC_ACMP0: ACMP0ʱ��ѡͨ
 *			@arg SIM_SCGC_ACMP1: ACMP1ʱ��ѡͨ
 * @param  State: ѡ��ָ��������
 *		�����������ȡ�����ֵ:
 *			@arg ENABLE: ʹ����Ӧģ��
 *			@arg DISABLE: �ر���Ӧģ��
 * @retval None
 */
void SIM_SCGC_Cmd(uint32_t SCGC_Type, FunctionalState State)
{
	if(State == ENABLE)
	{
		driver_write_reg(SIM->SCGC, driver_read_reg(SIM->SCGC) | SCGC_Type);
	}
	else
	{
		driver_write_reg(SIM->SCGC, driver_read_reg(SIM->SCGC) & ~SCGC_Type);
	}		
}

/**
 * @brief  ϵͳʱ��ѡͨ1
 * @param  SCGC_Type: ָ������ʱ��ʹ��״̬
 *		�����������Ϊ����ֵ:
 *			@arg SIM_SCGC1_FTM0F: 	FTM0ѡ��ICSFFCLKʱ��ʹ��                  
 *			@arg SIM_SCGC1_FTM1F: 	FTM1ѡ��ICSFFCLKʱ��ʹ��                                 
 *			@arg SIM_SCGC1_FTM2F: 	FTM2ѡ��ICSFFCLKʱ��ʹ��                                    
 *			@arg SIM_SCGC1_RTCEC: 	RTCѡ��OSCERCLKʱ��ʹ��                                	
 *			@arg SIM_SCGC1_ADCALTC: ADCѡ��ALTCLKʱ��ʹ��                          
 *			@arg SIM_SCGC1_FTM0T:  	FTM0ѡ��TIMERCLKʱ��ʹ��                    
 *			@arg SIM_SCGC1_FTM1T:  	FTM1ѡ��TIMERCLKʱ��ʹ��                       
 *			@arg SIM_SCGC1_FTM2T:  	FTM2ѡ��TIMERCLKʱ��ʹ��    
 *			@arg SIM_SCGC1_WDOGLPO: WDOGѡ��LPOCLKʱ��ʹ��    
 *			@arg SIM_SCGC1_RTCLPOC: RTCѡ��LPOCLKʱ��ʹ��    
 *			@arg SIM_SCGC1_FTM0FFCLK:FTM0ѡ��ICSFFCLKʱ��ʹ��       
 *			@arg SIM_SCGC1_FTM1FFCLK:FTM1ѡ��ICSFFCLKʱ��ʹ��       
 *			@arg SIM_SCGC1_FTM2FFCLK:FTM2ѡ��ICSFFCLKʱ��ʹ��       
 * @param  State: ѡ��ָ��������
 *		�����������ȡ�����ֵ:
 *			@arg ENABLE: ʹ����Ӧģ��
 *			@arg DISABLE: �ر���Ӧģ��
 * @retval None
 */
void SIM_SCGC1_Cmd(uint32_t SCGC1_Type, FunctionalState State)
{
	if(State == ENABLE)
	{
		SIM->SCGC1 |= SCGC1_Type;
	}
	else
	{
		SIM->SCGC1 &= ~SCGC1_Type;
	}		
}

/**
 * @brief  ��ȡͨ��Ψһ��ʶ����λ
 * @param  None
 * @retval ͨ��Ψһ��ʶ����λ
 */
uint32_t SIM_GetUUIDL(void)
{
	return SIM->UUIDL;
}

/**
 * @brief  ��ȡͨ��Ψһ��ʶ���е�λ
 * @param  None
 * @retval ͨ��Ψһ��ʶ����λ
 */
uint32_t SIM_GetUUIDML(void)
{
	return SIM->UUIDML;
}

/**
 * @brief  ��ȡͨ��Ψһ��ʶ���и�λ
 * @param  None
 * @retval ͨ��Ψһ��ʶ����λ
 */
uint32_t SIM_GetUUIDMH(void)
{
	return SIM->UUIDMH;
}

/**
 * @brief  �����ں�ʱ�ӵķ�Ƶֵ
 * @param  divide: �ں�ʱ�ӷ�Ƶֵ(1-256)(ICSOUTCLK����divide)
 * @retval None
 */
void SIM_CLKDIV_OUTDIV1(uint32_t divide)
{
	SIM->CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
	SIM->CLKDIV |= divide - (uint32_t)1;		
}

/**
 * @brief  ����AHB���ߺ�FLASHʱ�ӵķ�Ƶֵ
 * @param  divide: AHB���ߺ�FLASHʱ�ӵķ�Ƶֵ(OUTDIV1����divide)  (1-256)
 * @retval None
 */
void SIM_CLKDIV_OUTDIV2(uint32_t divide)
{
	SIM->CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;
	SIM->CLKDIV |= (divide - (uint32_t)1) << SIM_CLKDIV_OUTDIV2_SHIFT;		
}

/**
 * @brief  ����APB����ʱ�ӵķ�Ƶֵ
 * @param  divide: APB����ʱ�ӵķ�Ƶֵ(OUTDIV2����divide)
 * @retval None
 */
void SIM_CLKDIV_OUTDIV3(uint32_t divide)
{
	SIM->CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;
	SIM->CLKDIV |= (divide - (uint32_t)1) << SIM_CLKDIV_OUTDIV3_SHIFT;		
}

/**
 * @brief  ���ö�ʱ��(FTM0,FTM1,FTM2,PWT)�ķ�Ƶֵ
 * @param  divide: APB����ʱ�ӵķ�Ƶֵ(ICSOUTCLK����divide)
 * @retval None
 */
void SIM_CLKDIV_OUTDIV4(uint32_t divide)
{
	SIM->CLKDIV &= ~SIM_CLKDIV_OUTDIV4_MASK;
	SIM->CLKDIV |= (divide - (uint32_t)1) << SIM_CLKDIV_OUTDIV4_SHIFT;		
}

/**
 * @brief  �õ�OUTDIV1�ķ�Ƶֵ
 * @param  None
 * @retval ��Ƶֵ
 */
uint8_t SIM_GetOUTDIV1(void)
{
	return (uint8_t)(SIM->CLKDIV); 
}

/**
 * @brief  �õ�OUTDIV2�ķ�Ƶֵ
 * @param  None
 * @retval ��Ƶֵ
 */
uint8_t SIM_GetOUTDIV2(void)
{
	return (uint8_t)(SIM->CLKDIV >> 8); 
}

/**
 * @brief  �õ�OUTDIV3�ķ�Ƶֵ
 * @param  None
 * @retval ��Ƶֵ
 */
uint8_t SIM_GetOUTDIV3(void)
{
	return (uint8_t)(SIM->CLKDIV >> 16); 
}

/**
 * @brief  �õ�OUTDIV4�ķ�Ƶֵ
 * @param  None
 * @retval ��Ƶֵ
 */
uint8_t SIM_GetOUTDIV4(void)
{
	return (uint8_t)(SIM->CLKDIV >> 24); 
}

/**
 * @brief  ϵͳ���Ŀ���
 * @param  LP_Type: ѡ��ضϵ�Դ��ģ��
 *		�����������ȡ�����ֵ:
 *			@arg SIM_LP_USER_FLASH: 	�û�ģʽ�ǹض�FLASH��Դ         
 *			@arg SIM_LP_USER_FLASH:   STOPģʽ�ǹض�FLASH��Դ             
 *			@arg SIM_LP_USER_RAM1: 	  �û�ģʽ�ǹض�RAM1��Դ                          
 *			@arg SIM_LP_USER_RAM2: 	  �û�ģʽ�ǹض�RAM2��Դ                                	
 *			@arg SIM_LP_USER_RAM3:    �û�ģʽ�ǹض�RAM3��Դ                          
 *			@arg SIM_LP_STOP_RAM1:  	STOPģʽ�ǹض�RAM1��Դ           
 *			@arg SIM_LP_STOP_RAM2:  	STOPģʽ�ǹض�RAM2��Դ                         
 *			@arg SIM_LP_STOP_RAM3:  	STOPģʽ�ǹض�RAM3��Դ                  	
 * @retval None
 */
void SIM_LP_SetLowpowerCmd(uint32_t LP_Type)
{
	SIM->LP = (0x55690000u | LP_Type);
}

/**
 * @brief  ��ȡFLASH�ϵ��־
 * @param  None
 * @retval FLASH�ϵ��־
 */
FlagStatus SIM_LP_FLASHPowerONStatus(void)
{
	FlagStatus ret;
	
	if( ((SIM->LP & SIM_LP_FLASHPON_MASK)>>SIM_LP_FLASHPON_SHIFT) != 0u)
	{
		ret= SET;
	}
	else
	{
		ret = RESET;
	}
	
	return ret;
}

/**
 * @brief  ��ȡSRAM�ϵ��־
 * @param  None
 * @retval SRAM�ϵ��־
 */
FlagStatus SIM_LP_SRAMPowerONStatus(void)
{
	FlagStatus ret;
	
	if( ((SIM->LP >> SIM_LP_SRAMPON_SHIFT)&(uint32_t)0x01) != 0u)
	{
		ret= SET;
	}
	else
	{
		ret = RESET;
	}
	
	return ret;
}

/**
 * @brief  ����ϵͳ�ȶ��ȴ�ʱ��
 * @param  Clkwait: ICSOUTCLK���ȶ���������
 * @retval None
 */
void SIM_WAIT_CLKWAITConfig(uint16_t Clkwait)
{
	SIM->WAIT &= ~SIM_WAIT_CLKWAIT_MASK;
	SIM->WAIT |= (uint32_t)Clkwait;		
}

/**
 * @brief  ϵͳʱ�ӵ�1us��Ƶϵ��
 * @param  Div1us: ϵͳʱ�ӵ�1us��Ƶϵ��
 * @retval None
 */
void SIM_WAIT_DIV1USConfig(uint16_t Div1us)
{
	SIM->WAIT &= ~SIM_WAIT_DIV1US_MASK;
	SIM->WAIT |= ((uint32_t)Div1us << SIM_WAIT_DIV1US_SHIFT);		
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif



