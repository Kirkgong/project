#ifndef __UDP_SERVER_H
#define __UDP_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xl6600_data_write(unsigned char *buffer, unsigned int length);
void aufi_data_write(unsigned char *buffer, unsigned int length);
void  *xl6600_data_transmit();
void  *aufi_data_transmit();
#endif
