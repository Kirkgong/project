#include "overtime.h"

uint8_t overtime_flag = 0;
uint8_t start_count;
uint32_t count;


void overtime_callback(void)
{
	if(start_count == 1)
	{
		count--;
		if(count == 0)
		{
			overtime_flag = 1;
			start_count = 0;
		}
	}
	
	HAL_IncTick();
}

void overtime_init(void)
{
	
}


void set_overtime(uint32_t ms)
{
	count = ms;
	overtime_flag = 0;
	start_count = 1;
}

uint8_t get_overtime(void)
{
	return overtime_flag;
}


