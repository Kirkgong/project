#ifndef __FIFO_H
#define __FIFO_H

#include "driver.h"

#define QueueFull      0  
#define QueueEmpty     1  
#define QueueOperateOk 2  
typedef struct 
{
    uint32_t front;     
    uint32_t rear;        
    uint16_t count;
	uint8_t*  pdata;
	uint32_t  size;
}FifoQueue;
//Queue Initalize
extern void QueueInit(FifoQueue *Queue, uint8_t* pmem, uint32_t size);
extern uint8_t QueueIn(FifoQueue *Queue,uint8_t sdat);
extern uint8_t QueueOut(FifoQueue *Queue,uint8_t *sdat);
#endif
