#include "door.h"


void open_door(int floor){
    elevio_doorOpenLamp(1);

    while (elevio_stopButton()){
            elevio_stopLamp(1);
    }
        
    elevio_stopLamp(0);

    for(int i = 0; i < 1000; i++){
        usleep(2500);
        check_buttons(floor);
        if (elevio_obstruction()){
            obstruction_wait(floor);
            break;
        }
    }
    
    elevio_doorOpenLamp(0);
}


void obstruction_wait(int floor){
    while (elevio_obstruction()){
        check_buttons(floor);
    }

    for(int i = 0; i < 1000; i++){
        usleep(2500);
        check_buttons(floor);
    }
}