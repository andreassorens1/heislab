#include "door.h"
#include "driver/elevio.h"



//timerfunksjon med nanosleep


void door_lamp_on(){
    elevio_doorOpenLamp(1);
}



void door_lamp_off(){
    elevio_doorOpenLamp(0);
}


int is_obstructed(){
    return elevio_obstruction;
}


/*
void open_door(void (*elevio_doorOpenLamp)()){



    time_t start, now;
    struct timespec wait;

    wait.tv_sec = 0;
    wait.tv_nsec = 1000000;
    
    start = time(NULL);

    while (1){
        while(elevio_obstruction()){
            printf("Obstruksjon \n");
        }


        nanosleep(&wait, NULL);
        }
    }
    
    

    elevio_doorOpenLamp();

    //timer

    //while timeren ikke har gått ut
    //check all
    //if obstruksjon
    //start timer 3 sek på nytt
}

*/
