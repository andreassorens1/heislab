#include "queue_system.h"
#include "driver/elevio.h"

int queue[2][4] = {
    {0, 0, 0, 0},              //array heis opp
    {0, 0, 0, 0}               //array heis ned
};


void add_to_queue(int target_floor, int button, int queue[2][4]){  ///ikke blad floor og current floor
    if (button == 0){                  //hvis heisen skal opp
        queue[0][target_floor] = 1;
    }
    else if (button == 1) {            //hvis heisen skal ned
        queue[1][target_floor] = 1;
    }
    else {   
        //printf("heispanel\n");                          //hvis knapp trykkes inni heis
        int current_floor = elevio_floorSensor();
        printf("%d\n", current_floor);
        if (current_floor < target_floor){
            queue[0][target_floor] = 1;
        }
        else if (current_floor > target_floor){
            queue[1][target_floor] = 1;
        }
    };
    

    //printe queue
    printf("queuefunksjon\n");
    for (int i = 0; i<2; i++){
        for (int j = 0; j<4; j++){
            printf("%d ", queue[i][j]);
        }
        printf("\n");
    }

};
