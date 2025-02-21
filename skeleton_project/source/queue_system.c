#include "queue_system.h"
#include "elevio.h"

bestilling create_bestilling(int floor, int current_floor, ButtonType button){  ///ikke blad floor og current floor

    bestilling nyBestilling;

    if (button <= 1){                  //hvis knapp trykkes på gangen
        nyBestilling.elevator_direction = button;
        nyBestilling.floor_target = floor;
    }
    else {                             //hvis knapp trykkes inni heisen
        /*regne ut retning: targetfloor - currentfloor
        hvis forskjell negativ:
            direction = ned
        else 
            direction = opp
        */
       nyBestilling.floor_target = floor;    //? er dette riktig floor vi tenker på
    }
    return nyBestilling;
};

void add_bestilling(bestilling nyBestilling){

};

/*
int setbestilling_etasje(bestilling_hall *nyBestilling) {
    //nyBestilling.bestilling_etasje = 
};
*/