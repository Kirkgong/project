#ifndef __INTERFACE_H
#define __INTERFACE_H

#include "driver.h"
#include "main.h"

#define BUILD_TEST
// #define BUILD_WIN
#define DEBUG

void xl6600_data_write(unsigned char *buffer, unsigned int length);


void audi_data_read(unsigned char *buffer, unsigned int length);
void aufi_data_write(unsigned char *buffer, unsigned int length);


int write_reg(unsigned int address, unsigned int data);
int read_reg(unsigned int address, unsigned int *data);
#endif
