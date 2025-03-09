#include "motor.h"
#include "driver/elevio.h"

void start_motor(floor, j){
    if (floor > j){
        elevio_motorDirection(DIRN_DOWN);
        printf("går ned \n");
    }
    else {
        elevio_motorDirection(DIRN_UP);
        printf("går opp \n");
    }
}