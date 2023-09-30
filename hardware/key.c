#include "../include/key.h"

void key_cleanup() {
    digitalWrite(BEEP, 0);
    digitalWrite(R, 0);
    pinMode(BEEP, INPUT);
    pinMode(R, INPUT);
}

void key_init() {
    pinMode(BEEP, OUTPUT);
    pinMode(R, OUTPUT);
    digitalWrite(BEEP, 0);
    pinMode(KEY, INPUT);
}
