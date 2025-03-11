#include "stdio.h"   //print
#include "queue_system.h"
#include "driver/elevio.h"
#include "check.h"


int queue[2][4] = {
    {0, 0, 0, 0},              //array heis opp
    {0, 0, 0, 0}               //array heis ned
};


// int queue[2][4]

void add_to_queue(int current_floor, int target_floor, int button){  ///ikke blad floor og current floor
    if (button == 0){                  //hvis heisen skal opp
        queue[0][target_floor] = 1;
        /*for (int i = current_floor + 1; i < target_floor; i++){
            if (queue[0][i] == 1){
                return;
            }
        } */

    }
    else if (button == 1) {            //hvis heisen skal ned
        queue[1][target_floor] = 1;
        /*for (int i = current_floor - 1; i > target_floor; i--){
            if (queue[0][i] == 1){
                return;
            }
        }*/


    }
    else {                              //hvis knapp trykkes inni heis
        current_floor = check_floor(current_floor);
        if (current_floor < target_floor){
            /*for (int i = current_floor + 1; i < target_floor; i++){
                if (queue[0][i] == 1){
                    return;
                }
            }*/
            queue[0][target_floor] = 1;
        }
        else if (current_floor > target_floor){
            /*for (int i = current_floor - 1; i > target_floor; i--){
                if (queue[0][i] == 1){
                    return;
                }
            }*/
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
