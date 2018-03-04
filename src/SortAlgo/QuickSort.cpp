#include "QuickSort.hpp"
#include <iostream>

unsigned partition(unsigned arr[], const unsigned start, const unsigned end)
{
    // SOLUTION 1 --> HackerEarth
    // auto i = start + 1;
    // auto pivot = arr[start];

    // for(auto k = i; k <= end; k++)
    // {
    //     if(arr[k] < pivot)
    //     {
    //         auto temp = arr[i];
    //         arr[i++] = arr[k];
    //         arr[k] = temp;
    //     }
    // }
    // if((i-1) != start)
    // {
    //     auto temp = arr[i-1];
    //     arr[i-1] = arr[start];
    //     arr[start] = temp;
    // }
    // return i-1;

    // SOLUTION 2 --> Crawling left and right position until left >= right and also performs swapping
    // 2A --> PIVOT is lowest index
    // int l = start+1, r = end;
    
    // while(true)
    // {
    //     while(arr[l] <= arr[start] && l <= r)
    //     {
    //         l++;
    //     }

    //     while(arr[r] >= arr[start] && r >= l)
    //     {
    //         r--;
    //     }

    //     if(l > r)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         auto temp = arr[l];
    //         arr[l] = arr[r];
    //         arr[r] = temp;
    //     }
    // }
    // auto temp = arr[r];
    // arr[r] = arr[start];
    // arr[start] = temp;
    // return  r;
    // 2B --> PIVOT is highest index
    int l = start, r = end -1;
    while(true)
    {
        while(l <= r && arr[l] <= arr[end])
            l++;

        while(r >= l && arr[r] >= arr[end])
            r--;
        
        if(l > r)
        {
            break;
        }
        else
        {
            auto temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }
    }
    auto temp = arr[l];
    arr[l] = arr[end];
    arr[end] = temp;
    return  l;
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