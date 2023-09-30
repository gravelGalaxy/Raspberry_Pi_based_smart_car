#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getCPUtemperature(char *);

void getRAMinfo(unsigned long*);

void getCPUuse(char*);

void getDiskSpace(char (*diskInfo)[20]);

void getSystemInfo(char *);

#endif //SYSTEM_INFO_H