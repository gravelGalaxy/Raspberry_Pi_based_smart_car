#ifndef LED_H
#define LED_H

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <unistd.h>
#include <softPwm.h>
#include "pin.h"

void led_init();
void led_cleanup();
void open_led();

#endif //LED_H
