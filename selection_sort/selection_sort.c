#include "../array_generator/int_array_generator.h"

#define SIZE 100
#define NUMBER_OF_TRY 2

void Sort(int *array, int array_size);
void SortComplexity(int *array, int array_size, int *numberOfComparison, int *numberOfExchange, int *timePassed);

int main(void)
{
    int *array = NULL;
    int numberOfComparison = 0, numberOfExchange = 0;
    int totalNumberOfComparison = 0, totalNumberOfExchange = 0, totalTime = 0;
    int timePassed = 0;

    printf("--- Array with Random Values\n");
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_TRY; i++)
    {
        array = GenerateRandomValues(array, SIZE);
        SortComplexity(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
        totalNumberOfComparison += numberOfComparison;
        totalNumberOfExchange += numberOfExchange;
        totalTime += timePassed;
    }
    printf("%-35s: %d\n", "[+] Average number of comparison", totalNumberOfComparison / NUMBER_OF_TRY);
    printf("%-35s: %d\n", "[+] Average number of exchange", totalNumberOfExchange / NUMBER_OF_TRY);
    printf("%-35s: %d\n", "[+] Average time", (totalTime / NUMBER_OF_TRY));

    printf("\n\n--- Array with Ordered Values\n");
    array = GenerateOrderedValues(array, SIZE);
    SortComplexity(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
    printf("%-35s: %d\n", "[+] Number of comparison", numberOfComparison);
    printf("%-35s: %d\n", "[+] Number of exchange", numberOfExchange);
    printf("%-35s: %d\n", "[+] Time", timePassed);

    printf("\n\n--- Array with Reverse Ordered Values\n");
    array = GenerateReverseOrderedValues(array, SIZE);
    SortComplexity(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
    printf("%-35s: %d\n", "[+] Number of comparison", numberOfComparison);
    printf("%-35s: %d\n", "[+] Number of exchange", numberOfExchange);
    printf("%-35s: %d\n", "[+] Time", timePassed);

    printf("\n\n--- Array with Same Values\n");
    array = GenerateSameValue(array, SIZE);
    SortComplexity(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
    printf("%-35s: %d\n", "[+] Number of comparison", numberOfComparison);
    printf("%-35s: %d\n", "[+] Number of exchange", numberOfExchange);
    printf("%-35s: %d\n", "[+] Time", timePassed);

    free(array);
    return 0;
}

void SortComplexity(int *array, int array_size, int *numberOfComparison, int *numberOfExchange, int *timePassed)
{
    *numberOfComparison = 0;
    *numberOfExchange = 0;
    int start = time(0);

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

    int end = time(0);
    *timePassed = end - start;
}

void Sort(int *array, int array_size)
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
