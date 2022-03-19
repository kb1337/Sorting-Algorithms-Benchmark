#include "int_array_generator.h"

int *GenerateRandomValues(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
    }

    return array;
}

int *GenerateOrderedValues(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = i;

    return array;
}

int *GenerateReverseOrderedValues(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = N - i - 1;

    return array;
}

int *GenerateSameValue(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = 1;

    return array;
}

void PrintArray(int *array, int N)
{
    if (NULL == array)
        return;

    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
    printf("\n");
}
