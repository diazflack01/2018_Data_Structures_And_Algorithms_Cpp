#include "SelectionSort.hpp"

void SelectionSort::sort(unsigned arr[], const unsigned arrLen)
{
    for(auto i = 0u; i < arrLen; ++i)
    {
        auto smallestElemIdx = i;
        for(auto j = smallestElemIdx + 1; j < arrLen; ++j)
        {
            if(arr[smallestElemIdx] > arr[j])
            {
                smallestElemIdx = j;
            }
        }
        if(smallestElemIdx != i)
        {
            auto temp = arr[i];
            arr[i] = arr[smallestElemIdx];
            arr[smallestElemIdx] = temp;
        }
    }
}