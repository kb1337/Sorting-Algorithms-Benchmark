#include "array_generator/int_array_generator.h"
#include "sorting_algorithms/selection_sort.h"
#include "sorting_algorithms/insertion_sort.h"
#include "sorting_algorithms/quick_sort.h"
#include <time.h>

#define SIZE 10000
#define NUMBER_OF_EXPERIMENTS 5

#define ALG_COUNT 3
void (*ALGORITHMS_PTR[ALG_COUNT])() = {selection_sort_benchmark, insertion_sort_benchmark, quick_sort_adapter};
const char *TITLES[ALG_COUNT] = {"SELECTION SORT", "INSERTION SORT", "QUICK SORT"};

int main(void)
{
    for (int i = 0; i < ALG_COUNT; i++)
    {
        int *array = NULL;
        long numberOfComparison = 0, numberOfExchange = 0;
        long totalNumberOfComparison = 0, totalNumberOfExchange = 0;
        double timePassed = 0, totalTime = 0;
        clock_t start;
        clock_t end;

        printf("\n\n%s\n", TITLES[i]);
        printf("-----------------------------------\n");

        printf("[*] Array with Random Values\n");
        srand(time(NULL));
        for (int j = 0; j < NUMBER_OF_EXPERIMENTS; j++)
        {
            array = GenerateRandomValues(array, SIZE);
            // PrintArray(array, SIZE);
            start = clock();
            (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange);
            end = clock();
            timePassed = (double)(end - start) / CLOCKS_PER_SEC;
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
        numberOfComparison = 0;
        numberOfExchange = 0;
        start = clock();
        (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange);
        end = clock();
        timePassed = (double)(end - start) / CLOCKS_PER_SEC;
        // PrintArray(array, SIZE);
        printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
        printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
        printf("%-35s: %f\n", "[+] Time", timePassed);

        printf("\n\n[*] Array with Reverse Ordered Values\n");
        array = GenerateReverseOrderedValues(array, SIZE);
        // PrintArray(array, SIZE);
        numberOfComparison = 0;
        numberOfExchange = 0;
        start = clock();
        (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange);
        end = clock();
        timePassed = (double)(end - start) / CLOCKS_PER_SEC;
        // PrintArray(array, SIZE);
        printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
        printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
        printf("%-35s: %f\n", "[+] Time", timePassed);

        printf("\n\n[*] Array with Same Values\n");
        array = GenerateSameValue(array, SIZE);
        // PrintArray(array, SIZE);
        numberOfComparison = 0;
        numberOfExchange = 0;
        start = clock();
        (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange);
        end = clock();
        timePassed = (double)(end - start) / CLOCKS_PER_SEC;
        // PrintArray(array, SIZE);
        printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
        printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
        printf("%-35s: %f\n", "[+] Time", timePassed);

        free(array);
    }

    return 0;
}
