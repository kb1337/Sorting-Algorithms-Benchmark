#include "array_generator/int_array_generator.h"
#include "sorting_algorithms/selection_sort.h"
#include "sorting_algorithms/insertion_sort.h"
#include "sorting_algorithms/quick_sort.h"
#include <time.h>

#define SIZE 100
#define NUMBER_OF_EXPERIMENTS 10

#define ALG_COUNT 3
const char *TITLES[ALG_COUNT] = {"SELECTION SORT", "INSERTION SORT", "QUICK SORT"};
void (*ALGORITHMS_PTR[ALG_COUNT])() = {selection_sort_benchmark, insertion_sort_benchmark, quick_sort_adapter};

#define TEST_CASE_COUNT 3
const char *TEST_CASE_TITLE[TEST_CASE_COUNT] = {"Array with Ordered Values", "Array with Reverse Ordered Values", "Array with Same Values"};
int *(*ARRAY_GENERATOR_PTR[TEST_CASE_COUNT])() = {generate_ordered_values, generate_reverse_ordered_values, generate_same_values};

int main(void)
{
    for (int i = 0; i < ALG_COUNT; i++)
    {
        int *array = NULL;
        long numberOfComparison, numberOfExchange;
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
            array = generate_random_values(array, SIZE);

            numberOfComparison = 0;
            numberOfExchange = 0;

            // print_array(array, SIZE);

            start = clock();
            (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange);
            end = clock();

            // print_array(array, SIZE);

            timePassed = (double)(end - start) / CLOCKS_PER_SEC;

            totalNumberOfComparison += numberOfComparison;
            totalNumberOfExchange += numberOfExchange;
            totalTime += timePassed;
        }
        printf("%-35s: %ld\n", "[+] Average number of comparison", totalNumberOfComparison / NUMBER_OF_EXPERIMENTS);
        printf("%-35s: %ld\n", "[+] Average number of exchange", totalNumberOfExchange / NUMBER_OF_EXPERIMENTS);
        printf("%-35s: %f\n", "[+] Average time", (totalTime / NUMBER_OF_EXPERIMENTS));

        // Other test cases
        for (int k = 0; k < TEST_CASE_COUNT; k++)
        {
            printf("\n\n[*] %s\n", TEST_CASE_TITLE[k]);

            array = (*ARRAY_GENERATOR_PTR[k])(array, SIZE);

            numberOfComparison = 0;
            numberOfExchange = 0;

            // print_array(array, SIZE);

            start = clock();
            (*ALGORITHMS_PTR[i])(array, SIZE, &numberOfComparison, &numberOfExchange);
            end = clock();

            // print_array(array, SIZE);

            timePassed = (double)(end - start) / CLOCKS_PER_SEC;

            printf("%-35s: %ld\n", "[+] Number of comparison", numberOfComparison);
            printf("%-35s: %ld\n", "[+] Number of exchange", numberOfExchange);
            printf("%-35s: %f\n", "[+] Time", timePassed);
        }

        free(array);
    }

    return 0;
}
