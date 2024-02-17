#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize(int current_floor, int destination_floor, int max_floor, int min_floor);
void elevator_arrival(int picked_floor, int *current_floor);
void display_floor(int *current_floor, int min_floor, int max_floor, int *destination_floor);

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

void initialize(int current_floor, int destination_floor, int max_floor, int min_floor) {
    int *p_current_floor, *p_destination_floor, *p_min_floor, *p_max_floor;

    min_floor = -min_floor;
    p_current_floor = &current_floor;
    p_destination_floor = &destination_floor;
    p_min_floor = &min_floor;
    p_max_floor = &max_floor;

    return;
}

void elevator_arrival(int picked_floor, int *current_floor) {
    int i;
    if (picked_floor < *current_floor) {
        printf("The elevator is arriving, please wait...\n");
        for (i = picked_floor; i <= *current_floor; i++) {
            printf(" -----\n");
            printf(" | %d |\n", i);
            printf(" -----\n");
        }
        printf("The elevator has arrived at your floor.\nYou may enter and indicate your desired floor.\n");
    } else if (picked_floor > *current_floor) {
        printf("The elevator is arriving, please wait...\n");
        for (i = picked_floor; i >= *current_floor; i--) {
            printf(" -----\n");
            printf(" | %d |\n", i);
            printf(" -----\n");
        }
        printf("The elevator has arrived at your floor.\nYou may enter and indicate your desired floor.\n");
    } else {
        printf("The elevator is already here.\nYou may enter and indicate your desired floor.\n");
        return;
    }

    return;
}

void display_floor(int *current_floor, int min_floor, int max_floor, int *destination_floor) {
    int i;
    if (*destination_floor < *current_floor) {
        for (i = *current_floor; i >= *destination_floor; i--) {
            printf(" -----\n");
            printf(" | %d |\n", i);
            printf(" -----\n");
        }
        printf("You have arrived.\n");
    } else if (*destination_floor == *current_floor) {
        printf("You are already on the floor:\n");
        printf(" -----\n");
        printf(" | %d |\n", *current_floor);
        printf(" -----\n");
    } else {
        for (i = *current_floor; i <= *destination_floor; i++) {
            printf(" -----\n");
            printf(" | %d |\n", i);
            printf(" -----\n");
            system("color 1d");
        }
        system("color 4b");
        printf("You have arrived.\n");
    }
    
    return;
}
