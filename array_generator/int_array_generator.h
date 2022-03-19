#ifndef int_array_generator_h
#define int_array_generator_h

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *GenerateRandomValues(int *array, int N);
int *GenerateOrderedValues(int *array, int N);
int *GenerateReverseOrderedValues(int *array, int N);
int *GenerateSameValue(int *array, int N);
void PrintArray(int *array, int N);

#endif
