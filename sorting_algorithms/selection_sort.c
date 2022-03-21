#include "selection_sort.h"

void selection_sort(int *array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        int min = i;
        for (int j = i + 1; j < array_size; j++)
            if (array[j] < array[min])
                min = j;

        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void selection_sort_benchmark(int *array, int array_size, int *numberOfComparison, int *numberOfExchange, double *timePassed)
{
    *numberOfComparison = 0;
    *numberOfExchange = 0;
    clock_t start = clock();

    for (int i = 0; i < array_size; i++)
    {
        int min = i;
        for (int j = i + 1; j < array_size; j++)
        {
            (*numberOfComparison)++;
            if (array[j] < array[min])
                min = j;
        }

        (*numberOfExchange)++;
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }

    clock_t end = clock();
    *timePassed = (double)(end - start) / CLOCKS_PER_SEC;
}
