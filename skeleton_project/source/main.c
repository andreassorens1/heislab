#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>  //sleep-funksjonen
#include "driver/elevio.h"
#include "queue_system.h"
#include "button.h"



int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");


    elevio_motorDirection(DIRN_UP);

    while(1){
        int floor = elevio_floorSensor();

        for (int i=0; i<2; i++){
            if (i == 0){
                for (int j=0; j<4; j++){
                    if (queue[i][j] == 1){
                        elevio_motorDirection(DIRN_UP);
                        while (floor != j){
                            floor = elevio_floorSensor();
                            check_buttons();
                            check_stopButton();
                        }
                        elevio_motorDirection(DIRN_STOP);
                        sleep(1);
                    }
                }
            }
            else if (i == 1){
                for (int j=3; j>=0; j--){
                    if (queue[i][j] == 1){
                        elevio_motorDirection(DIRN_DOWN);
                        while (floor != j){
                            floor = elevio_floorSensor();
                            check_buttons();
                            check_stopButton();
                        }
                        elevio_motorDirection(DIRN_STOP);
                        sleep(1);
                    }
                }
            }  
        }



        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        

        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
