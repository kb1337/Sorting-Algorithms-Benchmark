#ifndef int_array_generator_h
#define int_array_generator_h

#include <stdlib.h>
#include <stdio.h>

int *generate_random_values(int *array, int N);
int *generate_ordered_values(int *array, int N);
int *generate_reverse_ordered_values(int *array, int N);
int *generate_same_values(int *array, int N);
void print_array(int *array, int N);

#endif
