#include "check.h"


void check_buttons(int floor){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            int btnPressed = elevio_callButton(f, b);
            if (btnPressed && floor != f){
                add_to_queue(floor, f, b, queue);
                elevio_buttonLamp(f, b, 1);
            }
        }
    }
}



int check_stopButton(int floor){
    if(elevio_stopButton()){
        elevio_motorDirection(DIRN_STOP);
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 4; j++){
                queue[i][j] = 0;
                elevio_buttonLamp(j, i, 0);
                elevio_buttonLamp(j, 2, 0); // fiks slik ikke dobbelt?
            }
        }
        printf("forrige etasje %d\n", floor);

        if (elevio_floorSensor() != -1){
            open_door(floor);
        }


        while(elevio_stopButton()){
            elevio_stopLamp(1);
        }
        
        elevio_stopLamp(0);

        return 1;
    }
    return 0; 
}


int check_floor(int floor){
    int current_floor = elevio_floorSensor();
    if (current_floor != -1 && current_floor != floor){
        floor = current_floor;
        printf("ny etasje %d\n", floor);
        elevio_floorIndicator(floor);
    }
    return floor;
}


                           