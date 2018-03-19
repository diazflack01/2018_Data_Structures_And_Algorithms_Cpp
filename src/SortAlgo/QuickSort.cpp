#include "QuickSort.hpp"
#include <iostream>

unsigned partition(unsigned arr[], const unsigned start, const unsigned end)
{
    // SOLUTION 1 --> HackerEarth
    // This only performs one-way scanning left->right
    // until it finds correct position of pivot


    // SOLUTION 2 --> Crawling left and right position until left >= right and also performs swapping
    // 2A --> PIVOT is lowest index


    // 2B --> PIVOT is highest index
    return -1;
}

void quickSort(unsigned arr[], const int start, const int end)
{
    if(start < end)
    {
        int pivotPosition = partition(arr, start, end);
        quickSort(arr, start, pivotPosition-1);
        quickSort(arr, pivotPosition+1, end);
    }
}

void QuickSort::sort(unsigned arr[], const unsigned arrLen)
{
    if(1 < arrLen)
    {
        quickSort(arr, 0, arrLen-1);
    }
}