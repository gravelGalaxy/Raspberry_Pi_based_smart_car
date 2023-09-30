#ifndef CAR_H
#define CAR_H

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <unistd.h>
#include <softPwm.h>
#include "pin.h"
#include <stdbool.h>


void car_init();
void car_cleanup();

void go_up();
void go_back();
void go_left();
void go_right();
void go_stop();
void rotate_left();
void rotate_right();

#endif //CAR_H