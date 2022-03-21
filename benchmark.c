#include "array_generator/int_array_generator.h"
#include "sorting_algorithms/selection_sort.h"
#include "sorting_algorithms/insertion_sort.h"

#define SIZE 100
#define NUMBER_OF_EXPERIMENTS 2

#define ALG_COUNT 2
void (*ALGORITHMS_PTR[ALG_COUNT])() = {selection_sort_benchmark, insertion_sort_benchmark};
const char *TITLES[ALG_COUNT] = {"SELECTION SORT", "INSERTION SORT"};

int main(void)
{
    for (int i = 1; i < ALG_COUNT; i++)
    {
        int *array = NULL;
        long numberOfComparison = 0, numberOfExchange = 0;
        long totalNumberOfComparison = 0, totalNumberOfExchange = 0;
        double timePassed = 0, totalTime = 0;

        printf("\n\n%s\n", TITLES[i]);
        printf("-----------------------------------\n");

        printf("[*] Array with Random Values\n");
        srand(time(NULL));
        for (int j = 0; j < NUMBER_OF_EXPERIMENTS; j++)
        {
            array = GenerateRandomValues(array, SIZE);
            // PrintArray(array, SIZE);
            (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
            // PrintArray(array, SIZE);
            totalNumberOfComparison += numberOfComparison;
            totalNumberOfExchange += numberOfExchange;
            totalTime += timePassed;
        }
        printf("%-35s: %ld\n", "[+] Average number of comparison", totalNumberOfComparison / NUMBER_OF_EXPERIMENTS);
        printf("%-35s: %ld\n", "[+] Average number of exchange", totalNumberOfExchange / NUMBER_OF_EXPERIMENTS);
        printf("%-35s: %f\n", "[+] Average time", (totalTime / NUMBER_OF_EXPERIMENTS));

        printf("\n\n[*] Array with Ordered Values\n");
        array = GenerateOrderedValues(array, SIZE);
        // PrintArray(array, SIZE);
        (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
        // PrintArray(array, SIZE);
        printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
        printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
        printf("%-35s: %f\n", "[+] Time", timePassed);

        printf("\n\n[*] Array with Reverse Ordered Values\n");
        array = GenerateReverseOrderedValues(array, SIZE);
        // PrintArray(array, SIZE);
        (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
        // PrintArray(array, SIZE);
        printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
        printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
        printf("%-35s: %f\n", "[+] Time", timePassed);

        printf("\n\n[*] Array with Same Values\n");
        array = GenerateSameValue(array, SIZE);
        // PrintArray(array, SIZE);
        (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange, &timePassed);
        // PrintArray(array, SIZE);
        printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
        printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
        printf("%-35s: %f\n", "[+] Time", timePassed);

        free(array);
    }

    return 0;
}
