#include "int_array_generator.h"

int *generate_random_values(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
    }

    return array;
}

int *generate_ordered_values(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = i;

    return array;
}

int *generate_reverse_ordered_values(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = N - i - 1;

    return array;
}

int *generate_same_values(int *array, int N)
{
    array = realloc(array, N * sizeof(int));

    for (int i = 0; i < N; i++)
        array[i] = 1;

    return array;
}

void print_array(int *array, int N)
{
    if (NULL == array)
        return;

    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
    printf("\n");
}
