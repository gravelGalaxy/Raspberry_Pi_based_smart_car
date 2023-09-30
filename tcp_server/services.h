#ifndef SERVICES_H
#define SERVICES_H

#include "message.h"
#include "../include/tem.h"
#include "../include/distance.h"
#include "../include/car.h"
#include "../include/duoji.h"
#include "../include/track.h"
#include "../include/avoidance.h"
#include "../include/system_info.h"
#include "../include/smg_distance.h"
#include "../include/smg_tem.h"
#include "../include/smg.h"
#include "../include/track_avoidance.h"
#include "tcpserver.h"
#include <pthread.h>
#include <errno.h>

#define INVALID_THREAD -1

void services_init();
void run();
void services_cleanup();
void handle_request(int request);

#endif //SERVICES_H