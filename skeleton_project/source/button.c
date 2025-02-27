#include "driver/elevio.h"

void check_buttons(){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            int btnPressed = elevio_callButton(f, b);
            elevio_buttonLamp(f, b, btnPressed);
        }
    }
}

void check_stopButton(){
    if(elevio_stopButton()){
        elevio_motorDirection(DIRN_STOP);
    }
}