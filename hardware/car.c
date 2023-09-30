#include "../include/car.h"
const int maxSpeed = 50;
const int minSpeed = 15;

void car_init() {
    pinMode(t1, OUTPUT);
    pinMode(t2, OUTPUT);
    pinMode(t3, OUTPUT);
    pinMode(t4, OUTPUT);
    softPwmCreate(t1, 0, 100);
    softPwmCreate(t2, 0, 100);
    softPwmCreate(t3, 0, 100);
    softPwmCreate(t4, 0, 100);
}

void car_cleanup() {
    softPwmWrite(t1, 0);
    softPwmWrite(t2, 0);
    softPwmWrite(t3, 0);
    softPwmWrite(t4, 0);

    pinMode(t1, INPUT);
    pinMode(t2, INPUT);
    pinMode(t3, INPUT);
    pinMode(t4, INPUT);
}


void go_back() {
    softPwmWrite(t2, 50);
    softPwmWrite(t3, 50);
}

void go_up() {
    softPwmWrite(t1, 30);
    softPwmWrite(t4, 30);
}

void go_stop() {
    softPwmWrite(t1, 0);
    softPwmWrite(t4, 0);
    softPwmWrite(t2, 0);
    softPwmWrite(t3, 0); 
    printf("STOPPED!!!\n");  
}

//直角弯
void go_left() {
    softPwmWrite(t2, 50);
    softPwmWrite(t4, 30);
    delay(700);
    softPwmWrite(t2, 0);
    softPwmWrite(t4, 0);
    go_up();
}

void rotate_left() {
    softPwmWrite(t2, 50);
    softPwmWrite(t4, 30);
}

void go_right() {
    softPwmWrite(t1, 50);
    softPwmWrite(t3, 30);
    delay(700);
    softPwmWrite(t1, 0);
    softPwmWrite(t3, 0);
    go_up();
}

void rotate_right() {
    softPwmWrite(t1, 50);
    softPwmWrite(t3, 30);
}

