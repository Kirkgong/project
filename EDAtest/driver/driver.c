#include "driver.h"
#include "interface.h"


#include<stdio.h>      /*标准输入输出定义*/  
#include<stdlib.h>     /*标准函数库定义*/  
#include<unistd.h>     /*Unix 标准函数定义*/  
#include<sys/types.h>   
#include<sys/stat.h>     
#include<fcntl.h>      /*文件控制定义*/  
#include<termios.h>    /*PPSIX 终端控制定义*/  
#include<errno.h>      /*错误号定义*/  
#include<string.h>

void SystemReset(void)
{
	
}

void HAL_IncTick(void)
{
	
}


int driver_write_reg(unsigned int address, unsigned int data)
{
	return write_reg((uint32_t)(&address), data);
}

unsigned int driver_read_reg(unsigned int address)
{	
	uint32_t rx_data;
	
	read_reg((uint32_t)(&address), &rx_data);
	
	return rx_data;
}



uint32_t Get_PeripheralClock(void)
{
	return 48000000;
}


int fd;
int XL6600PortToEDAInit(void)
{
	#ifndef BUILD_WIN
	fd = open("ttyS0", O_RDWR | O_NOCTTY);
	#endif
	if(fd < 0) {
		#ifdef DEBUG
		printf("Open serial port ttyS0 fail.\r\n");
		#endif
		return -1;
	}
	#ifdef DEBUG
	printf("Open serial port ttyS0 success.\r\n");
	#endif
	return 0;
}

int XL6600DataWriteToEDA(uint8_t* buf, uint32_t len)
{
	int ret;
	#ifndef BUILD_WIN
	ret = write(fd, buf, len);
	#endif
	if (ret < 0) {
		return -1;
	}
	
	return 0;
}


//需要周期性被调用的函数
void XL6600DataReadFromEDA(void)
{
	static uint8_t data[1024];
	
	int ret;
	#ifndef BUILD_WIN
		ret = read(fd, data, sizeof(data));
	#endif
	if (ret < 0) 
	{
		return;
	}
	
	xl6600_data_write(data, ret);

}



