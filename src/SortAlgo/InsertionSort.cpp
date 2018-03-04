#include "InsertionSort.hpp"

void InsertionSort::sort(unsigned arr[], const unsigned arrLen)
{
    // SOLUTION 1
    // for(auto i = 0u; i < arrLen; ++i)
    // {
    //     auto t = i+1;
    //     while(t > 0 && t < arrLen && arr[t-1] > arr[t])
    //     {
    //         auto temp = arr[t-1];
    //         arr[t-1] = arr[t];
    //         arr[t] = temp;
    //         t--;
    //     }
    // }

    // SOLUTION 2
    // for(auto i = 1u; i < arrLen; i++)
    // {
    //     auto idxToBeInserted = i;
    //     while(idxToBeInserted > 0 && arr[idxToBeInserted] < arr[idxToBeInserted-1])
    //     {
    //         auto temp = arr[idxToBeInserted];
    //         arr[idxToBeInserted] = arr[idxToBeInserted-1];
    //         arr[idxToBeInserted-1] = temp;
    //         idxToBeInserted--;
    //     }
    // }

    // SOLUTION 3 - By Tutorials Point
    for(auto i = 1u; i < arrLen; i++)
    {
        auto valueToInsert = arr[i];
        auto holePosition = i;
        while(holePosition > 0 && arr[holePosition-1] >= valueToInsert)
        {
            arr[holePosition] = arr[holePosition-1];
            holePosition--;
        }

        if(holePosition != i)
        {
            arr[holePosition] = valueToInsert;
        }
    }
}