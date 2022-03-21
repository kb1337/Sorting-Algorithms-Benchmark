#ifndef selection_sort_h
#define selection_sort_h

#include <time.h>

void selection_sort(int *array, int array_size);
void selection_sort_benchmark(int *array, int array_size, int *numberOfComparison, int *numberOfExchange, double *timePassed);

#endif
