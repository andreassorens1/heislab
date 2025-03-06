#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>  //sleep-funksjonen
#include "driver/elevio.h"
#include "queue_system.h"
#include "check.h"
#include "door.h"



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
                            //elevio_motorDirection(DIRN_UP);
                            if (floor > j){
                                elevio_motorDirection(DIRN_DOWN);
                                printf("går ned \n");
                            }
                            else {
                                elevio_motorDirection(DIRN_UP);
                                printf("går opp \n");
                            }
                            
                            while (floor != j){
                                //check_all(current_floor);
                                check_buttons(floor);
                                check_stopButton();
                                floor = check_floor(floor); 
                                //floor = elevio_floorSensor(); 
                            }
                        }
                        elevio_motorDirection(DIRN_STOP);
                        //open_door(door_lamp_on);
                        //open_door(door_lamp_off);
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
                            //elevio_motorDirection(DIRN_DOWN);
                            if (floor > j){
                                elevio_motorDirection(DIRN_DOWN);
                                printf("går ned \n");
                            }
                            else {
                                elevio_motorDirection(DIRN_UP);
                                printf("går opp \n");
                            }
                            while (floor != j){
                                //check_all(current_floor);
                                check_buttons(floor);
                                check_stopButton();
                                floor = check_floor(floor); 
                                //floor = elevio_floorSensor(); 
                            }
                        }
                        elevio_motorDirection(DIRN_STOP);
                        queue[i][j] = 0;
                        //open_door(door_lamp_on);
                        //open_door(door_lamp_off);
                        printf("stopper.. \n");
                        // sleep(1);
                    }
                }
            }  
        }
        
    }

    return 0;
}
