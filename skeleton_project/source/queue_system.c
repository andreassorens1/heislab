#include "queue_system.h"
#include "driver/elevio.h"

int queue[2][4] = {
    {0, 0, 1, 0},              //array heis opp
    {1, 1, 0, 0}               //array heis ned
};


void add_to_queue(int target_floor, ButtonType button){  ///ikke blad floor og current floor

    if (button == 0){                  //hvis heisen skal opp
        queue[0][target_floor] = 1;
    }
    else if (button == 1) {            //hvis heisen skal ned
        queue[1][target_floor] = 1;
    }
    else {                             //hvis knapp trykkes inni heis
        int current_floor = elevio_floorSensor();
        if (current_floor < target_floor){
            queue[0][target_floor] = 1;
        }
        else if (current_floor > target_floor){
            queue[1][target_floor] = 1;
        }
    };
};
