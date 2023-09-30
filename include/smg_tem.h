#ifndef SMG_TEM_H
#define SMG_TEM_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "pin.h"
#include "smg.h"
#include "tem.h"

void *smg_show_tem(void *param);

#endif //SMG_TEM_H