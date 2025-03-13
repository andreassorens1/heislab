#pragma once
#include "driver/elevio.h"
#include "door.h"
#include "queue_system.h"

void start_motor(int  floor, int j);
void stop_motor(int floor, int stopButton_pressed, int i, int j);