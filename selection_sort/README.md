# Selection Sort

```c
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
```

<details>
<summary>Output</summary>

```c
--- Array with Random Values
[+] Average number of comparison   : 4950
[+] Average number of exchange     : 100
[+] Average time                   : 0.000018


--- Array with Ordered Values
[+] Number of comparison           : 4950
[+] Number of exchange             : 100
[+] Time                           : 0.000015


--- Array with Reverse Ordered Values
[+] Number of comparison           : 4950
[+] Number of exchange             : 100
[+] Time                           : 0.000016


--- Array with Same Values
[+] Number of comparison           : 4950
[+] Number of exchange             : 100
[+] Time                           : 0.000014
```

</details>

<br/>

<hr/>

## Time Complexities
. | Array Size | Number of Comparison | Number of Exchange | Time Complexity 
--- | :---: | :---: | :---: | :---: 
Best Case | N | N*(N-1)/2 | N | O(N^2)
Worst Case | N | N*(N-1)/2 | N | O(N^2)
Average Case | N | N*(N-1)/2 | N | O(N^2)

<br/>

. | Array Size | Number of Comparison | Number of Exchange | Time Complexity
--- | :---: | :---: | :---: | :---:
Array with Ordered Values | 100 | 4950 | 100 | O(N^2)
Array with Same Values | 100 | 4950 | 100 | O(N^2)
Array with Reverse Ordered Values | 100 | 4950 | 100 | O(N^2)
Array with Random Values | 100 | 4950 | 100 | O(N^2)

<br/>

. | Array Size | Number of Comparison | Number of Exchange | Time Passed (sec)
--- | :---: | :---: | :---: | :---:
Array with Ordered Values | 100000 | 704982704 | 100000 | 15
Array with Same Values | 100000 | 704982704 | 100000 | 15
Array with Reverse Ordered Values | 100000 | 704982704 | 100000 | 15
Array with Random Values | 100000 | 704982704 | 100000 | 15
