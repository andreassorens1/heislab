#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>  //sleep-funksjonen
#include "driver/elevio.h"
#include "queue_system.h"
#include "check.h"
#include "door.h"
#include "motor.h"



int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    
    int floor = elevio_floorSensor();
    //int *stop_ptr = &stop_button_pressed;

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
                    check_stopButton(floor, j);
                    floor = check_floor(floor); 
                    if (queue[i][j] == 1 && floor != j){
                        start_motor(floor, j);
                        while (floor != j){
                            //check_all(current_floor);
                            check_buttons(floor);               //kommer seg aldri ut av while-løkka når stoppknappen trykkes
                            check_stopButton(floor, j);
                            floor = check_floor(floor); 
                        }
                        stop_motor(floor, i ,j);
                    }
                }
            }
            else if (i == 1){
                for (int j=3; j>=0; j--){
                    //check_all(current_floor);
                    check_buttons(floor);
                    check_stopButton(floor, j);
                    floor = check_floor(floor);
                    if (queue[i][j] == 1 && floor != j){
                        start_motor(floor, j);
                        while (floor != j){
                            //check_all(current_floor);
                            check_buttons(floor);
                            check_stopButton(floor, j);
                            floor = check_floor(floor); 
                        }
                        stop_motor(floor, i, j);
                    }
                }
            }  
        }
        
    }

    return 0;
}
