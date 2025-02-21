#include "elevio.h"

/*
typedef struct {
    int bestilling_etasje;
    ButtonType bestilling_retning;
} bestilling_hall;

typedef struct {
    int floor_target;
    int floor_source;
    int elevator_direction;
} bestilling_CAB;
*/

typedef struct {
    int floor_target;
    int elevator_direction;
} bestilling;


bestilling create_bestilling(int floor, ButtonType button);
void add_bestilling(bestilling nyBestilling);



/*
array retning opp
array retning ned

if floorsensor </> minste/største verdien i arrayen -> bytt array

når floorsensor registrerer samme floor og retning som en bestilling så må alle bestillingene det gjelder fjernes fra arrayen 
- når den er klar til å kjøre videre?

*/