#ifndef TRACK_H
#define TRACK_H

#include "pin.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <unistd.h>
#include "car.h"

enum {
    RIGHT = 1,
    LEFT = 2,
    FORWORD = 3,
    STOP = 4
};

void track_init();
void track_cleanup();
void turn_right();
void turn_left();
void *auto_track(void *param);
int get_direction();

#endif //TRACK_H
