#ifndef DUOJI_H
#define DUOJI_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <softPwm.h>
#include <signal.h>
#include "pin.h"

void duoji_init();
void duoji_cleanup();
void check_forward();
void check_left();
void check_right();
void toRight();
void toLeft();

#endif //DUOJI_H