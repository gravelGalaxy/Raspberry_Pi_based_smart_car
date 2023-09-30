#pragma once
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "pin.h"

void write_command(int cmd);
void set_num_display(int n1, int n2, int n3, int n4, bool dp);
void smg_init();
void smg_cleanup();
void smg_clean();
void write_byte(int byte);
void write_bit(int bit);
void write_data(int addr, int data);
void smg_start();
void smg_stop();