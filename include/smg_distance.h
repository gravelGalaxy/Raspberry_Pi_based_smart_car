#ifndef SMG_DISTANCE_H
#define SMG_DISTANCE_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "pin.h"
#include "distance.h"
#include "smg.h"

void *smg_show_distance(void *param);

#endif //SMG_DISTANCE_H