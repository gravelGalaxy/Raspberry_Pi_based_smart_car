#ifndef TRACK_AVOIDANCE_H
#define TRACK_AVOIDANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <unistd.h>
#include <pthread.h>
#include "car.h"
#include "distance.h"
#include "pin.h"
#include "track.h"

void *check_distance(void *param);
void cancel_track_avoidance();
void *track_avoidance(void *param);

#endif //TRACK_AVOIDANCE_H