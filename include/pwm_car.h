#ifndef PWM_CAR_H
#define PWM_CAR_H

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <unistd.h>
#include <softPwm.h>
#include "pin.h"
#include <stdbool.h>


void pwm_car_init();
void pwm_car_cleanup();
void speedUp();
void speedDown();


#endif //PWM_CAR_H