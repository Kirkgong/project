#include "fifo.h"

void QueueInit(FifoQueue *Queue, uint8_t* pmem, uint32_t size)
{
    Queue->front = Queue->rear;
    Queue->count = 0;   
	Queue->size = size;
	Queue->pdata = pmem;
}

// Queue In
uint8_t QueueIn(FifoQueue *Queue,uint8_t sdat) 
{
    if((Queue->front == Queue->rear) && (Queue->count == Queue->size))
    {                    
        return QueueFull;    
    }else
    {                    
        Queue->pdata[Queue->rear] = sdat;
        Queue->rear = (Queue->rear + 1) % Queue->size;
        Queue->count = Queue->count + 1;
        return QueueOperateOk;
    }
}

// Queue Out
uint8_t QueueOut(FifoQueue *Queue,uint8_t *sdat)
{
    if((Queue->front == Queue->rear) && (Queue->count == 0))
    {                    
        return QueueEmpty;
    }else
    {                    
        *sdat = Queue->pdata[Queue->front];
        Queue->front = (Queue->front + 1) % Queue->size;
        Queue->count = Queue->count - 1;
        return QueueOperateOk;
    }
}
