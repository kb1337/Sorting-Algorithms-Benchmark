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

void selection_sort_benchmark(int *array, int array_size, long *numberOfComparison, long *numberOfExchange)
{
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
}
