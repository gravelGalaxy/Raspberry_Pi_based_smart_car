#include "../include/smg_distance.h"

void *smg_show_distance(void *param) {
    bool dot = TRUE;
    while (TRUE) {
        double distance = get_distance();
        int big = (int)distance;
        double little = distance - big;
        set_num_display(distance / 10, (int)distance % 10, (int)(little * 10), (int)(little * 100) % 10, dot);
        sleep(1);
    }
}