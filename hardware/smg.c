#include "../include/smg.h"

int segdata[16] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 57, 94, 121, 113}; //0-F

void smg_start(){
    digitalWrite(CLK, HIGH);
    usleep(140);
    digitalWrite(DIO, HIGH);
    usleep(140);
    digitalWrite(DIO, LOW);
    usleep(140);
    digitalWrite(CLK, LOW);
    usleep(140);
}


void smg_stop() {
    digitalWrite(CLK, LOW);
    usleep(140);
    digitalWrite(DIO, LOW);
    usleep(140);
    digitalWrite(CLK, HIGH);
    usleep(140);
    digitalWrite(DIO, HIGH);
    usleep(140);
}
    

void write_bit(int bit) {
    digitalWrite(CLK, LOW);
    usleep(140);
    digitalWrite(DIO, bit);
    usleep(140);
    digitalWrite(CLK, HIGH);
    usleep(140);
}
    

void write_byte(int byte) {
    for (int i = 0; i < 8; i++){
        write_bit((byte >> i) & 1);
    }
    digitalWrite(CLK, LOW);
    usleep(140);
    digitalWrite(DIO, HIGH);
    usleep(140);
    digitalWrite(CLK, HIGH);
    usleep(140);
    pinMode(DIO, INPUT);
    while (digitalRead(DIO) == HIGH);
    pinMode(DIO, OUTPUT);
}
    

void write_command(int cmd){
    smg_start();
    write_byte(cmd);
    smg_stop();
}
    

void write_data(int addr, int data) {
    smg_start();
    write_byte(addr);
    write_byte(data);
    smg_stop();
}
    

void set_num_display(int n1, int n2, int n3, int n4, bool dp) {
    write_command(64);
    write_command(68);

    write_data(192, segdata[n1]);
    write_data(193, segdata[n2] + dp * 128);
    write_data(194, segdata[n3]);
    write_data(195, segdata[n4]);
    write_command(136);
}
    

void smg_clean() {
    write_command(64);
    write_command(68);

    write_data(192, 0);
    write_data(193, 0);
    write_data(194, 0);
    write_data(195, 0);
    write_command(136);
}

void smg_cleanup() {
    smg_clean();
    digitalWrite(DIO, LOW);
    digitalWrite(CLK, LOW);
    pinMode(DIO, INPUT);
    pinMode(CLK, INPUT);
}

void smg_init() {
    pinMode(DIO, OUTPUT);
    pinMode(CLK, OUTPUT);
}
