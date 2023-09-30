#include "smg_tem.h"

unsigned char tem_data[5] = {};

void *smg_show_tem(void *param) {
    bool dot = TRUE;
    while (TRUE) {
        printf("smg_show_tem\n");
        int state = dht11_read_data(tem_data);
        if (state == 1) set_num_display(tem_data[0] / 10, tem_data[0] % 10, tem_data[2] / 10, tem_data[2] % 10, dot);
        else set_num_display(15, 15, 15, 15, dot);  //设置为FF
        sleep(1);
    }
}

