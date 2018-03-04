#include "MergeSort.hpp"
#include <iostream>

void merge(unsigned arr[], unsigned lo, unsigned mid, unsigned hi)
{
    // SOLUTION 1 --> 1 temporary array
    // unsigned tempArr[hi-lo+1] = {0};
    // unsigned k = 0;

    // unsigned i = lo;
    // unsigned j = mid+1;

    // for(auto pek = lo; pek <= hi; pek++)
    // {
    //     if(i > mid)
    //         tempArr[k++] = arr[j++];
    //     else if(j > hi)
    //         tempArr[k++] = arr[i++];
    //     else if(arr[i] < arr[j])
    //         tempArr[k++] = arr[i++];
    //     else
    //         tempArr[k++] = arr[j++];
    // }

    // for(auto d = 0u, start = lo; d < k; d++, start++)
    // {
    //     arr[start] = tempArr[d];
    // }

    // SOLUTION 2 --> 2 temporary array
    unsigned i = 0, j = 0, k = lo;
    unsigned elemCntListA = mid - lo + 1;
    unsigned elemCntListB = hi - mid;

    unsigned listA[elemCntListA] = {0}, listB[elemCntListB] = {0};
    for(auto p = 0u; p < elemCntListA; p++)
        listA[p] = arr[lo+p];
    for(auto p = 0u; p < elemCntListB; p++)
        listB[p] = arr[mid+1+p];

    while(i < elemCntListA && j < elemCntListB)
        arr[k++] = (listA[i] < listB[j]) ? listA[i++] : listB[j++];

    while(i < elemCntListA)
        arr[k++] = listA[i++];

    while(j < elemCntListB)
        arr[k++] = listB[j++];
}

void merge_sort(unsigned arr[], unsigned start, unsigned end)
{
    if(start < end)
    {
        unsigned mid = (end + start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void MergeSort::sort(unsigned arr[], const unsigned arrLen)
{
    if(1 < arrLen)
    {
        merge_sort(arr, 0, arrLen-1);
    }
}