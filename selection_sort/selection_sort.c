#include "../array_generator/int_array_generator.h"

#define SIZE 100
#define NUMBER_OF_TRY 1000

void Sort(int *array, int array_size);
void SortComplexity(int *array, int array_size, int *numberOfComparison, int *numberOfSwap);

int main(void)
{
    int *array = NULL;
    int numberOfComparison = 0, numberOfSwap = 0;
    int totalNumberOfComparison = 0, totalNumberOfSwap = 0;

    printf("--- Array with Random Values\n");
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_TRY; i++)
    {
        array = GenerateRandomValues(array, SIZE);
        SortComplexity(array, SIZE, &numberOfComparison, &numberOfSwap);
        totalNumberOfComparison += numberOfComparison;
        totalNumberOfSwap += numberOfSwap;
    }
    printf("%-35s: %d\n", "[+] Average number of comparison", totalNumberOfComparison / NUMBER_OF_TRY);
    printf("%-35s: %d\n", "[+] Average number of swap", totalNumberOfSwap / NUMBER_OF_TRY);

    printf("\n\n--- Array with Ordered Values\n");
    array = GenerateOrderedValues(array, SIZE);
    SortComplexity(array, SIZE, &numberOfComparison, &numberOfSwap);
    printf("%-35s: %d\n", "[+] Number of comparison", numberOfComparison);
    printf("%-35s: %d\n", "[+] Number of swap", numberOfSwap);

    printf("\n\n--- Array with Reverse Ordered Values\n");
    array = GenerateReverseOrderedValues(array, SIZE);
    SortComplexity(array, SIZE, &numberOfComparison, &numberOfSwap);
    printf("%-35s: %d\n", "[+] Number of comparison", numberOfComparison);
    printf("%-35s: %d\n", "[+] Number of swap", numberOfSwap);

    printf("\n\n--- Array with Same Values\n");
    array = GenerateSameValue(array, SIZE);
    SortComplexity(array, SIZE, &numberOfComparison, &numberOfSwap);
    printf("%-35s: %d\n", "[+] Number of comparison", numberOfComparison);
    printf("%-35s: %d\n", "[+] Number of swap", numberOfSwap);

    free(array);
    return 0;
}

void SortComplexity(int *array, int array_size, int *numberOfComparison, int *numberOfSwap)
{
    *numberOfComparison = 0;
    *numberOfSwap = 0;

    for (int i = 0; i < array_size; i++)
    {
        int min = i;
        for (int j = i; j < array_size; j++)
        {
            (*numberOfComparison)++;
            if (array[j] < array[min])
                min = j;
        }

        (*numberOfSwap)++;
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void Sort(int *array, int array_size)
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
