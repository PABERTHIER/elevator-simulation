#ifndef ELEVATOR_H
#define ELEVATOR_H

void initialize(int current_floor, int destination_floor, int max_floor, int min_floor);
void elevator_arrival(int picked_floor, int *current_floor);
void display_floor(int *current_floor, int min_floor, int max_floor, int *destination_floor);

#endif /* ELEVATOR_H */
