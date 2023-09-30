#include "../include/avoidance.h"
const int minDistance = 20;

void avoidance_cleanup() {
    duoji_cleanup();
    distance_cleanup();
}

void avoidance_init() {
    duoji_init();
    distance_init();
}


void *avoidance_run(void *param) {
    while (TRUE) {
        check_forward();
        delay(100);
        while (get_distance() > minDistance) {
            go_up();
            delay(100);
        }
        go_stop();
        delay(100);
        check_left();
        delay(500);
        if (get_distance() > minDistance) {
            go_left();
        } else {
            check_right();
            delay(500);
            if (get_distance() > minDistance) {
                go_right();
            }
        }
    }
}





