#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>  //sleep-funksjonen
#include "driver/elevio.h"
#include "queue_system.h"
#include "check.h"



int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");
    

    
    int floor = elevio_floorSensor();

    if (floor == -1){
        while (floor == -1){
            floor = elevio_floorSensor();
        }
    }

    printf("startetasje %d\n", floor);


    while(1){

        for (int i=0; i<2; i++){
            if (i == 0){
                for (int j=0; j<4; j++){
                    //check_all(current_floor);
                    check_buttons(floor);
                    check_stopButton();
                    floor = check_floor(floor); 
                    if (queue[i][j] == 1){
                        if (floor != j){
                            elevio_motorDirection(DIRN_UP);
                            printf("går opp \n");
                            while (floor != j){
                                //check_all(current_floor);
                                check_buttons(floor);
                                check_stopButton();
                                floor = check_floor(floor); 
                            }
                        }
                        elevio_motorDirection(DIRN_STOP);
                        queue[i][j] = 0;
                        printf("stopper.. \n");
                        //sleep(1);
                    }
                }
            }
            else if (i == 1){
                for (int j=3; j>=0; j--){
                    //check_all(current_floor);
                    check_buttons(floor);
                    check_stopButton();
                    floor = check_floor(floor);
                    if (queue[i][j] == 1){

                        if (floor != j){
                            elevio_motorDirection(DIRN_DOWN);
                            printf("går ned \n");
                            while (floor != j){
                                //check_all(current_floor);
                                check_buttons(floor);
                                check_stopButton();
                                floor = check_floor(floor); 
                            }
                        }
                        elevio_motorDirection(DIRN_STOP);
                        queue[i][j] = 0;
                        printf("stopper.. \n");
                        // sleep(1);
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
