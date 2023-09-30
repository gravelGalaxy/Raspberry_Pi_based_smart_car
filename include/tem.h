#ifndef TEM_H
#define TEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <unistd.h>
#include "pin.h"
#include <stdbool.h>

#define DATASIZE  5

void dht11_reset();
char read_bit();
unsigned char read_byte();
int dht11_scan();
unsigned char dht11_read_data(unsigned char *buff);
void uCharConvertToString(unsigned char* array, int length, char* result);
bool get_dht11_data(char *res);

#endif //TEM_H