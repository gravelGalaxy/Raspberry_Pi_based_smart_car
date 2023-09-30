#ifndef KEY_H
#define KEY_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <unistd.h>
#include "pin.h"

void key_init();
void key_cleanup();
#endif //KEY_H