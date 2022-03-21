# Insertion Sort

```c
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
```

<details>
<summary>Output</summary>

```c
INSERTION SORT
-----------------------------------
[*] Array with Random Values
[+] Average number of comparison   : 2550
[+] Average number of exchange     : 2545
[+] Average time                   : 0.000017


[*] Array with Ordered Values
[+] Number of comparison           : 99
[+] Number of exchange             : 0
[+] Time                           : 0.000002


[*] Array with Reverse Ordered Values
[+] Number of comparison           : 5049
[+] Number of exchange             : 5049
[+] Time                           : 0.000025


[*] Array with Same Values
[+] Number of comparison           : 99
[+] Number of exchange             : 0
[+] Time                           : 0.000002
```

</details>

<br/>

<hr/>

## Time Complexities
. | Array Size | Number of Comparison | Number of Exchange | Time Complexity 
--- | :---: | :---: | :---: | :---: 
Best Case | N | N-1 | 0 | O(N)
Worst Case | N | N*(N+1)/2 | N | O(N^2)
Average Case | N | N*(N+1)/4 | N | O(N^2)

<br/>

. | Array Size | Number of Comparison | Number of Exchange | Time Complexity
--- | :---: | :---: | :---: | :---:
Array with Random Values | 100 | 2550 | 2545 | O(N^2)
Array with Ordered Values | 100 | 99 | 0 | O(N^2)
Array with Reverse Ordered Values | 100 | 5049 | 5049 | O(N^2)
Array with Same Values | 100 | 99 | 0 | O(N^2)

<br/>

. | Array Size | Number of Comparison | Number of Exchange | Time Passed (sec)
--- | :---: | :---: | :---: | :---:
Array with Random Values | 100000 | 2473175568 | 2473174568 | 14.107664
Array with Ordered Values | 100000 | 99999 | 0 | 0.001049
Array with Reverse Ordered Values | 100000 | 5000049999 | 5000049999 | 27.701323
Array with Same Values | 100000 | 99999 | 0 | 0.000839
