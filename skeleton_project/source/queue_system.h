#pragma once
#include "driver/elevio.h"
#include "stdio.h"   //print
#include "driver/elevio.h"

int queue[2][4];

void add_to_queue(int current_floor, int target_floor, int button, int queue[2][4]);
