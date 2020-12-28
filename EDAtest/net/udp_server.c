#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "interface.h"


unsigned int MAX_WAIT_TIME = 120; //wait 120 s_addr

unsigned char xl6600_rev_switch = 0;//消息缓冲区
unsigned char aufi_rev_switch = 0;//消息缓冲区

 unsigned char xl6600_buf[256] = {0};//消息缓冲区
 unsigned char aufi_buf[256] = {0};//消息缓冲区
 
 unsigned char xl6600_rev_eda[256] = {0};//消息缓冲区
 unsigned char xl6600_rev_eda_len = 0;
 unsigned char aufi_rev_eda[256] = {0};//消息缓冲区
 unsigned char aufi_rev_eda_len = 0;
 
 
 unsigned char xl6600_send_client[256] = {0};//消息缓冲区
 unsigned char aufi_send_client[256] = {0};//消息缓冲区


void xl6600_data_write(unsigned char *buffer, unsigned int length)
{
	if (xl6600_rev_switch == 1)
	{
		memmove(xl6600_rev_eda,buffer,length);
		xl6600_rev_eda_len = length;
		xl6600_rev_switch = 2;
	}
}

void aufi_data_write(unsigned char *buffer, unsigned int length)
{
	if(aufi_rev_switch == 1)
	{
		memmove(aufi_rev_eda,buffer,length);
		aufi_rev_eda_len = length;
		aufi_rev_switch = 2;
	}
}


  
void  *xl6600_data_transmit()
{
	unsigned char data_buf[256] = {0};//消息缓冲区
	unsigned char i = 0;//消息缓冲区
	time_t seconds,current_t;

	//将接收端口号并转换为int
	int port = 5991;
	if( port<1025 || port>65535 )//0~1024一般给系统使用，一共可以分配到65535
	{
		printf("端口号范围应为1025~65535");
		return ;
	}
	
	// 1.创建udp通信socket  
	int xl6600_udp_socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(xl6600_udp_socket_fd < 0 )
	{
		perror("creat socket fail\n");
		return ;
	}
 
	//2.设置UDP的地址并绑定 
	struct sockaddr_in  local_addr = {0};
	local_addr.sin_family  = AF_INET; //使用IPv4协议
	local_addr.sin_port	= htons(port);   //网络通信都使用大端格式
	local_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//让系统检测本地网卡，自动绑定本地IP
 
	int ret = bind(xl6600_udp_socket_fd,(struct sockaddr*)&local_addr,sizeof(local_addr));
	if(ret < 0)
	{
		perror("bind fail:");
		close(xl6600_udp_socket_fd);
		return ;
	}
	else
	{
		printf("recv ready!!!\n");
	}
	
 
	struct sockaddr_in  src_addr = {0};  //用来存放对方(信息的发送方)的IP地址信息
	int len = sizeof(src_addr);	//地址信息的大小

	
	//3 循环接收客户发送过来的数据  
	while(1)
	{
		ret = recvfrom(xl6600_udp_socket_fd, xl6600_buf, sizeof(xl6600_buf), 0, (struct sockaddr *)&src_addr, &len);
		if(ret == -1)
		{
			break;
		}
		
		memmove(data_buf,xl6600_buf,ret);
		memset(xl6600_buf, 0, sizeof(xl6600_buf));
		xl6600_data_eda_write(data_buf,ret);
		xl6600_rev_switch = 1;
		current_t = time((time_t *)NULL);
		while(1)
		{
				seconds = time((time_t *)NULL);
				if((seconds - current_t) > MAX_WAIT_TIME)
				{
					break;
				}
				else
				{
					if(2 == xl6600_rev_switch)
					{
						memmove(xl6600_send_client,xl6600_rev_eda,xl6600_rev_eda_len);
						sendto(xl6600_udp_socket_fd, xl6600_send_client, strlen(xl6600_send_client), 0, (struct sockaddr *)&src_addr,sizeof(src_addr));
						break;
					}
				}
		}
		memset(xl6600_rev_eda, 0, sizeof(xl6600_rev_eda));
		xl6600_rev_eda_len = 0;
		xl6600_rev_switch = 0;
	}
	
	//4 关闭通信socket
	close(xl6600_udp_socket_fd);
}


void  *aufi_data_transmit()
{
	unsigned char data_buf[256] = {0};//消息缓冲区
	unsigned char i = 0;//消息缓冲区
	time_t seconds,current_t;

	//将接收端口号并转换为int
	int port = 5992;
	if( port<1025 || port>65535 )//0~1024一般给系统使用，一共可以分配到65535
	{
		printf("端口号范围应为1025~65535");
		return ;
	}
	
	// 1.创建udp通信socket  
	int aufi_udp_socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(aufi_udp_socket_fd < 0 )
	{
		perror("creat socket fail\n");
		return ;
	}
 
	//2.设置UDP的地址并绑定 
	struct sockaddr_in  local_addr = {0};
	local_addr.sin_family  = AF_INET; //使用IPv4协议
	local_addr.sin_port	= htons(port);   //网络通信都使用大端格式
	local_addr.sin_addr.s_addr = inet_addr("115.157.195.198");//让系统检测本地网卡，自动绑定本地IP
 
	int ret = bind(aufi_udp_socket_fd,(struct sockaddr*)&local_addr,sizeof(local_addr));
	if(ret < 0)
	{
		perror("bind fail:");
		close(aufi_udp_socket_fd);
		return ;
	}
	else
	{
		printf("recv ready!!!\n");
	}
	
 
	struct sockaddr_in  src_addr = {0};  //用来存放对方(信息的发送方)的IP地址信息
	int len = sizeof(src_addr);	//地址信息的大小

	
	//3 循环接收客户发送过来的数据  
	while(1)
	{
		ret = recvfrom(aufi_udp_socket_fd, aufi_buf, sizeof(aufi_buf), 0, (struct sockaddr *)&src_addr, &len);
		if(ret == -1)
		{
			break;
		}
		
		memmove(data_buf,aufi_buf,ret);
		memset(aufi_buf, 0, sizeof(aufi_buf));
		aufi_data_eda_write(data_buf,ret);
		aufi_rev_switch = 1;
		current_t = time((time_t *)NULL);
		while(1)
		{
				seconds = time((time_t *)NULL);
				if((seconds - current_t) > MAX_WAIT_TIME)
				{
					break;
				}
				else
				{
					if(2 == aufi_rev_switch)
					{
						memmove(aufi_send_client,aufi_rev_eda,aufi_rev_eda_len);
						sendto(aufi_udp_socket_fd, aufi_send_client, strlen(aufi_send_client), 0, (struct sockaddr *)&src_addr,sizeof(src_addr));
						break;
					}
				}
		}
		memset(aufi_rev_eda, 0, sizeof(aufi_rev_eda));
		aufi_rev_eda_len = 0;
		aufi_rev_switch = 0;
	}
	
	//4 关闭通信socket
	close(aufi_udp_socket_fd);
}

