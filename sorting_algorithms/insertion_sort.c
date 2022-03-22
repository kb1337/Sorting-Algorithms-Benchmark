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

void insertion_sort_benchmark(int *array, int array_size, long *numberOfComparison, long *numberOfExchange)
{
    for (int i = 1; i < array_size; i++)
    {
        int key = array[i];
        int j = i;
        while (++(*numberOfComparison) && j > 0 && array[j - 1] > key)
        {
            (*numberOfExchange)++;
            array[j] = array[j - 1];
            j--;
        }

        array[j] = key;

        if (i != j)
            (*numberOfExchange)++;
    }
}
