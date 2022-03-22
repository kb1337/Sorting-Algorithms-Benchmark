#include "insertion_sort.h"

void quick_sort(int *array, int left, int right)
{
    if (right <= left)
        return;

    int pivot, i, j, temp;
    pivot = array[right];
    i = left - 1;
    j = right;
    for (;;)
    {
        while (array[++i] < pivot)
            ;
        while (array[--j] > pivot)
            ;

        if (i >= j)
            break;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    temp = array[i];
    array[i] = array[right];
    array[right] = temp;

    quick_sort(array, left, i - 1);
    quick_sort(array, i + 1, right);
}

void quick_sort_benchmark(int *array, int left, int right, long *numberOfComparison, long *numberOfExchange)
{
    if (right <= left)
        return;

    int pivot, i, j, temp;
    pivot = array[right];
    i = left - 1;
    j = right;
    for (;;)
    {
        while (++(*numberOfComparison) && array[++i] < pivot)
            ;
        while (++(*numberOfComparison) && array[--j] > pivot)
            ;

        if (i >= j)
            break;

        (*numberOfExchange)++;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    (*numberOfExchange)++;
    temp = array[i];
    array[i] = array[right];
    array[right] = temp;

    quick_sort_benchmark(array, left, i - 1, numberOfComparison, numberOfExchange);
    quick_sort_benchmark(array, i + 1, right, numberOfComparison, numberOfExchange);
}

void quick_sort_adapter(int *array, int array_size, long *numberOfComparison, long *numberOfExchange)
{
    quick_sort_benchmark(array, 0, array_size - 1, numberOfComparison, numberOfExchange);
}
