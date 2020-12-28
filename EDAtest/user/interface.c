#include "interface.h"




#ifdef BUILD_TEST
//xl6600平台端交互函数
void xl6600_data_write(unsigned char *buffer, unsigned int length)
{
	//桩函数
}
#endif

void xl6600_data_read(unsigned char *buffer, unsigned int length)
{
	//xl6600收到平台端数据后直接转出
	XL6600DataWriteToEDA(buffer, length);
}


//辅助测试芯片平台端交互函数
void audi_data_read(unsigned char *buffer, unsigned int length)
{
	aufi_data_read_callback(buffer, length);
}

#ifdef BUILD_TEST
void aufi_data_write(unsigned char *buffer, unsigned int length)
{
	//桩函数
}
#endif


#ifdef BUILD_TEST
//辅助测试芯片读写寄存器函数
int write_reg(unsigned int address, unsigned int data)
{
	//桩函数
	return 1;
}
#endif

#ifdef BUILD_TEST
int read_reg(unsigned int address, unsigned int *data)
{
	//桩函数
	return 1;	
}
#endif














