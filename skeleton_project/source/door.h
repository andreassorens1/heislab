#pragma once
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "check.h"
#include "driver/elevio.h"


void open_door(int floor);
void obstruction_wait(int floor);