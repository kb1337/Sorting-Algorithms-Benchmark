#ifndef quick_sort_h
#define quick_sort_h

void quick_sort(int *array, int array_size);
void quick_sort_benchmark(int *array, int left, int right, long *numberOfComparison, long *numberOfExchange);
void quick_sort_adapter(int *array, int array_size, long *numberOfComparison, long *numberOfExchange);

#endif
