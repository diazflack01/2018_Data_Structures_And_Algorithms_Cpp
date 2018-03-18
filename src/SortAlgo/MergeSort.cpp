#include "MergeSort.hpp"
#include <iostream>

void merge(unsigned arr[], unsigned lo, unsigned mid, unsigned hi)
{
    // SOLUTION 1 --> 1 temporary array
    // creater counter/crawler index for lo->mid and mid+1->hi
    // do the magic


    // SOLUTION 2 --> 2 temporary array
    // save lo->mid in array1 and mid+1->hi in array2
    // do the magic


}

void merge_sort(unsigned arr[], unsigned start, unsigned end /*endIndex inclusive*/)
{
    if(start < end)
    {

    }
}

void MergeSort::sort(unsigned arr[], const unsigned arrLen)
{
    if(1 < arrLen)
    {
        merge_sort(arr, 0, arrLen-1);
    }
}