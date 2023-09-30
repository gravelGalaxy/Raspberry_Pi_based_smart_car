#ifndef AVOIDANCE_H
#define AVOIDANCE_H

#include "duoji.h"
#include "distance.h"
#include "car.h"
#include "pin.h"
#include <signal.h>

void avoidance_init();
void *avoidance_run(void *param);
void avoidance_cleanup();

#endif //AVOIDANCE_H
