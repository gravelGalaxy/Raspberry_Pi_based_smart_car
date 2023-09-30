#ifndef DISTANCE_H
#define DISTANCE_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "pin.h"

double get_distance();
bool get_distance_data(char *dstr);
void distance_cleanup();
void distance_init();

#endif //DISTANCE_H

