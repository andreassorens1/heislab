#include "stdio.h"  //fjern når vi tar bort printen i check_floor()
#include "check.h"
#include "driver/elevio.h"
#include "queue_system.h"
#include "door.h"

/*
void check_all(int current_floor){
    check_buttons(current_floor, queue);  //ta bort queue fra input
    check_stopButton();
    check_floor(current_floor);
}
*/


void check_buttons(int floor){
    for(int f = 0; f < N_FLOORS; f++){
        for(int b = 0; b < N_BUTTONS; b++){
            int btnPressed = elevio_callButton(f, b);
            if (btnPressed){
                add_to_queue(floor, f, b, queue);
            }
            elevio_buttonLamp(f, b, btnPressed);
        }
    }
}

void check_stopButton(){
    if(elevio_stopButton()){
        elevio_motorDirection(DIRN_STOP);
        elevio_stopLamp(1);

        //if etasje er definert
        //open_door()
    } else{
        elevio_stopLamp(0);
    }
}


//pass-by-reference vs. pass-by-value

int check_floor(int floor){
    int current_floor = elevio_floorSensor();
    if (current_floor != -1){
        if (current_floor != floor){
            floor = current_floor;
            printf("ny etasje %d\n", floor);
            elevio_floorIndicator(floor);
        }
    }
    return floor;
}

/*void check_obstruction(){
    int obstruction = elevio_obstruction();
    if (obstruction == 0){
        open_door(door_lamp_off);
        printf("Ingen obstruksjon \n");
    }
    else {
        printf("Døren holdes åpen pga obstruksjon \n");
        open_door(door_lamp_on);
    }
}
 */                               