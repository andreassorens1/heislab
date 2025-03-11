#include "motor.h"
#include "driver/elevio.h"
#include <stdio.h>
#include "queue_system.h"
#include "door.h"


void start_motor(int floor, int j){
    if (floor > j){
        elevio_motorDirection(DIRN_DOWN);
        printf("går ned \n");
    }
    else {
        elevio_motorDirection(DIRN_UP);
        printf("går opp \n");
    }
}

void stop_motor(int floor, int i, int j){
    elevio_motorDirection(DIRN_STOP);
    elevio_buttonLamp(j, 2, 0);
    elevio_buttonLamp(j, i, 0);
    open_door(floor);
    queue[i][j] = 0;
    printf("stopper.. \n");
}