#ifndef insertion_sort_h
#define insertion_sort_h

#include <time.h>

void insertion_sort(int *array, int array_size);
void insertion_sort_benchmark(int *array, int array_size, long *numberOfComparison, long *numberOfExchange, double *timePassed);

#endif
