#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"

int main(int argc, char *argv[]) {
    int current_floor = 0, destination_floor = 0, min_floor = 0, max_floor = 0, picked_floor = 0;
    
    printf("Welcome to the elevator.\nWhich floor are you currently on?\n");
    scanf("%d", &current_floor);
    printf("How many floors are there?\n");
    scanf("%d", &max_floor);
    printf("How many basement floors are there?\n");
    scanf("%d", &min_floor);
    printf("Which floor would you like to go to?\n");
    scanf("%d", &destination_floor);
    
    min_floor = -min_floor;
    picked_floor = rand() % max_floor + min_floor;
    
    initialize(current_floor, destination_floor, max_floor, min_floor);
    elevator_arrival(picked_floor, &current_floor);
    display_floor(&current_floor, min_floor, max_floor, &destination_floor);

    return 0;
}
