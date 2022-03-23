# Quick Sort

```c
void quick_sort(int *array, int left, int right)
{
    if (right <= left)
        return;

    int pivot, i, j, temp;
    pivot = array[right];
    i = left - 1;
    j = right;
    for (;;)
    {
        while (array[++i] < pivot)
            ;
        while (array[--j] > pivot)
            ;

        if (i >= j)
            break;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    temp = array[i];
    array[i] = array[right];
    array[right] = temp;

    quick_sort(array, left, i - 1);
    quick_sort(array, i + 1, right);
}
```

<details>
<summary>Output</summary>

```c
QUICK SORT
-----------------------------------
[*] Array with Random Values
[+] Average number of comparison   : 712
[+] Average number of exchange     : 171
[+] Average time                   : 0.000007


[*] Array with Ordered Values
[+] Number of comparison           : 5148
[+] Number of exchange             : 99
[+] Time                           : 0.000021


[*] Array with Reverse Ordered Values
[+] Number of comparison           : 5148
[+] Number of exchange             : 99
[+] Time                           : 0.000016


[*] Array with Same Values
[+] Number of comparison           : 564
[+] Number of exchange             : 282
[+] Time                           : 0.000007
```

</details>

<br/>

<hr/>

## Time Complexities

. | Array Size | Number of Comparison | Number of Exchange | Time Complexity 
--- | :---: | :---: | :---: | :---: 
Average Case | N | - | N*logN | O(N*logN)
Best Case | N | - | N-1 | O(N*logN)
Worst Case | N | N^2/2 | N-1 | O(N^2)

<br/>

. | Array Size | Number of Comparison | Number of Exchange | Time Complexity
--- | :---: | :---: | :---: | :---:
Array with Random Values | 100 | 712 | 171 | O(N*logN)
Array with Ordered Values | 100 | 5148 | 99 | O(N^2)
Array with Reverse Ordered Values | 100 | 5148 | 99 | O(N^2)
Array with Same Values | 100 | 564 | 282 | O(N*logN)

<br/>

. | Array Size | Number of Comparison | Number of Exchange | Time Passed (sec)
--- | :---: | :---: | :---: | :---:
Array with Random Values | 100000 | 1819579 | 593235 | 0.010080
Array with Ordered Values | 100000 | 5000149998 | 99999 | 12.079033
Array with Reverse Ordered Values | 100000 | 5000149998 | 99999 | 12.269754
Array with Same Values | 100000 | 1561130 | 780565 | 0.009172
