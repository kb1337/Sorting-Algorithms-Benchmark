#include <stdio.h>

void sort(int *array, int array_size);
void print_array(int *array, int array_size);

int main()
{
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("\n\n--- Array---\n");
    print_array(array, 10);

    sort(array, 10);

    printf("\n\n--- Sorted Array---\n");
    print_array(array, 10);

    return 0;
}

void sort(int *array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        int min = i;
        for (int j = i; j < array_size; j++)
            if (array[j] < array[min])
                min = j;

        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void print_array(int *array, int array_size)
{
    for (int i = 0; i < array_size; i++)
        printf("array[%d]: %d\n", i, array[i]);
}
