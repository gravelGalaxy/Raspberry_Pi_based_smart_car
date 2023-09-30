#include "../include/distance.h"

double get_distance() {
    static double distance = 0;
    delay(1000);
    digitalWrite(TRIG, LOW);
    delayMicroseconds(140);
    //开始信号
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    delayMicroseconds(140);

    while (digitalRead(ECHO) == LOW);   //等到ECHO引脚返回高电平信号
    time_t time1 = micros();
    while (digitalRead(ECHO) == HIGH);  //等到ECHO的高电平结束
    time_t time2 = micros();

    distance = (time2 - time1) * 340 * 100 / 2 / 1000000.0;
    printf("time1:%ld, time2:%ld, cha:%ld, distance:%lf\n", time1, time2, time2 - time1, distance);
    return distance;
}

bool get_distance_data(char *dstr) {
    double distance = get_distance();
    sprintf(dstr, "%.2lf", distance);
    return true;
}

void distance_cleanup() {
    digitalWrite(TRIG, LOW);
    digitalWrite(ECHO, LOW);
    pinMode(TRIG, INPUT);
    pinMode(ECHO, INPUT);
}

void distance_init() {
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}
