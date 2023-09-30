#include "../include/duoji.h"

void duoji_cleanup() {
    pinMode(duoji, INPUT);
}

void duoji_init() {
    pinMode(duoji, OUTPUT);
    softPwmCreate(duoji, 0, 100);
    softPwmWrite(duoji, 15);    
}

void check_forward() {
    softPwmWrite(duoji, 15);
    delay(100);
}

void check_left() {
    softPwmWrite(duoji, 24);
    delay(100);
}

void check_right() {
    softPwmWrite(duoji, 5);
    delay(100);
}

void toLeft() {
    for (int i = 15; i <= 25; i++) {
        softPwmWrite(duoji, i);
        usleep(100000);
    }
}

void toRight() {
    for (double i = 15; i >= 5; i--) {
        softPwmWrite(duoji, i);
        usleep(100000);
    }
}
