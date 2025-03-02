#include "check.h"
#include "driver/elevio.h"
#include "queue_system.h"


void check_all(int current_floor){
    check_buttons(current_floor, queue);
    check_stopButton();
    check_floor(current_floor);
}


void check_buttons(){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            int btnPressed = elevio_callButton(f, b);
            if (btnPressed){
                add_to_queue(f, b, queue);
            }
            elevio_buttonLamp(f, b, btnPressed);
        }
    }
}

void check_stopButton(){
    if(elevio_stopButton()){
        elevio_motorDirection(DIRN_STOP);
    }
}


//pass-by-reference vs. pass-by-value

int check_floor(int current_floor){
    int floor = elevio_floorSensor();
    if (floor != -1){
        current_floor = floor;
    }
    return current_floor;
}