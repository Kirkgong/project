#ifndef OVERTIME_H
#define OVERTIME_H
#include "driver.h"

void overtime_init(void);
void set_overtime(uint32_t ms);
uint8_t get_overtime(void);
void overtime_callback(void);

#endif


