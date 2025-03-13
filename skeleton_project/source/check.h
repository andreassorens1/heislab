#pragma once

#include "stdio.h"
#include "driver/elevio.h"
#include "queue_system.h"
#include "door.h"

void check_buttons(int floor);

int check_stopButton(int floor);
int check_floor(int floor);