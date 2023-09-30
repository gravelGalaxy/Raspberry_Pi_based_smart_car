#include "../include/track.h"

void track_init() {
    pinMode(LineR, INPUT);
    pinMode(LineL, INPUT);
    pinMode(LineM1, INPUT);
    pinMode(LineM2, INPUT);
}

void track_cleanup() {
    go_stop();
}

void turn_right() {
    softPwmWrite(t1, 65);
    softPwmWrite(t3, 65);
    while (!(digitalRead(LineM1) == HIGH || digitalRead(LineM2) == HIGH)) {
        delay(10);
    }
    softPwmWrite(t1, 0);
    softPwmWrite(t3, 0);
}

void turn_left() {
    softPwmWrite(t2, 65);
    softPwmWrite(t4, 65);
    while (!(digitalRead(LineM1) == HIGH || digitalRead(LineM2) == HIGH)) {
        delay(10);
    }
    softPwmWrite(t2, 0);
    softPwmWrite(t4, 0);
}

int get_direction() {
    if (digitalRead(LineL) == HIGH && digitalRead(LineR) == LOW
    && digitalRead(LineM1) == LOW && digitalRead(LineM2) == LOW) {
        printf("左转\n");
        return LEFT;
    } else if (digitalRead(LineR) == HIGH && digitalRead(LineL) == LOW
    && digitalRead(LineM1) == LOW && digitalRead(LineM2) == LOW) {
        printf("右转\n");
        return RIGHT;
    } else if (digitalRead(LineM1) == HIGH && digitalRead(LineM2) == HIGH 
    && digitalRead(LineL) == HIGH && digitalRead(LineR) == HIGH) {
        printf("停止\n");
        return STOP;
    } else if (digitalRead(LineM1) == HIGH || digitalRead(LineM2) == HIGH) {
        return FORWORD;
    } else {
        //printf("未识别到路\n");
        return STOP;
    }
    //delay(10);
}

void *auto_track(void *param) {
    while (TRUE) {
        int left = digitalRead(LineL);
        int right = digitalRead(LineR);
        int mid1 = digitalRead(LineM1);
        int mid2 = digitalRead(LineM2);
        printf("left:%d, mid1:%d, mid2:%d, right:%d\n", left, mid1, mid2, right);
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
    }
}
