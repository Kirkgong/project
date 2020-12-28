#include "interface.h"
#include "udp_server.h"




void xl6600_data_eda_write(unsigned char *buffer, unsigned int length)
{
	//xl6600收到平台端数据后直接转出
	XL6600DataWriteToEDA(buffer, length);
}


//辅助测试芯片平台端交互函数
void aufi_data_eda_write(unsigned char *buffer, unsigned int length)
{
	aufi_data_read_callback(buffer, length);
}


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














