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
    int stopButton_pressed = 0;

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
                    check_buttons(floor);
                    check_stopButton(floor);
                    floor = check_floor(floor); 
                    if (queue[i][j] == 1 && floor != j){
                        start_motor(floor, j);
                        while (floor != j && stopButton_pressed == 0){
                            check_buttons(floor);                             
                            stopButton_pressed = check_stopButton(floor);
                            floor = check_floor(floor); 
                        }
                        stop_motor(floor, stopButton_pressed, i, j);
                        stopButton_pressed = 0;
                    }
                }
            }
            else if (i == 1){
                for (int j=3; j>=0; j--){
                    check_buttons(floor);
                    check_stopButton(floor);
                    floor = check_floor(floor);
                    if (queue[i][j] == 1 && floor != j){
                        start_motor(floor, j);
                        while (floor != j && stopButton_pressed == 0){
                            check_buttons(floor);
                            stopButton_pressed = check_stopButton(floor);
                            floor = check_floor(floor); 
                        }
                        stop_motor(floor, stopButton_pressed, i, j);
                        stopButton_pressed = 0;
                    }
                }
            }  
        }
    }

    return 0;
}
