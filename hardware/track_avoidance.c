#include "track_avoidance.h"

bool MOVABLE = TRUE;
pthread_t distance_trd;


void cancel_track_avoidance() {
    pthread_cancel(distance_trd);
    if (pthread_join(distance_trd, NULL)) {
        printf("track_avoidance: distance_trd join error\n");
    }
}


void *track_avoidance(void *param) {
    if (pthread_create(&distance_trd, NULL, check_distance, NULL)) {
        printf("线程创建失败！\n");
        car_cleanup();
        distance_cleanup();
        exit(1);
    }

    while (TRUE) {
        if (!MOVABLE) {
            printf("not movable!\n");
            go_stop();
            delay(100);
            continue;
        }
        int direction = get_direction();
        switch(direction) {
        case RIGHT:
            turn_right();
            break;
        case LEFT:
            turn_left();
            break;
        case FORWORD:
            go_up();
            break;
        default:
            go_stop();
            break;
        }
        delay(10);
    }
}

void *check_distance(void *param) {
    while (TRUE) {
        if (get_distance() < 20) 
            MOVABLE = FALSE;            
        else 
            MOVABLE = TRUE;
        delay(100);
    }
}
