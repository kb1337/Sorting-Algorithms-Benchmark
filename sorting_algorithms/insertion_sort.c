#include "insertion_sort.h"

void insertion_sort(int *array, int array_size)
{
    for (int i = 1; i < array_size; i++)
    {
        int key = array[i];
        int j = i;
        while (j >= 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = key;
    }
}
void insertion_sort_benchmark(int *array, int array_size, long *numberOfComparison, long *numberOfExchange, double *timePassed)
{
    *numberOfComparison = 1;
    *numberOfExchange = 0;
    clock_t start = clock();

    for (int i = 1; i < array_size; i++)
    {
        int key = array[i];
        int j = i;
        while ((*numberOfComparison)++ && j > 0 && array[j - 1] > key)
        {
            (*numberOfExchange)++;
            array[j] = array[j - 1];
            j--;
        }

        array[j] = key;

        if (i != j)
            (*numberOfExchange)++;
    }

    clock_t end = clock();
    *timePassed = (double)(end - start) / CLOCKS_PER_SEC;
}
