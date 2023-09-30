#include "../include/led.h"

void led_init() {
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
}

void led_cleanup() {
    pinMode(R, INPUT);
    pinMode(G, INPUT);
    pinMode(B, INPUT);
}

void open_led() {
    digitalWrite(R, HIGH);
    sleep(1);
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    sleep(1);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
    sleep(1);
    digitalWrite(B, LOW);
    sleep(1);
}