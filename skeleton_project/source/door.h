#pragma once

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "check.h"


void door_lamp_on();
void door_lamp_off();
void open_door(void (*elevio_doorOpenLamp)());
