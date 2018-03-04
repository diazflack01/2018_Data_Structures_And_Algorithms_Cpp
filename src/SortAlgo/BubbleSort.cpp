#include "BubbleSort.hpp"

void BubbleSort::sort(unsigned arr[], const unsigned arrLen)
{
    for(auto i = 0u; i < arrLen; i++)
    {
        auto swapped = false;
        for(auto j = 0u; j < arrLen - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                const auto temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped)
        {
            swapped = false;
        }
        else
        {
            return;
        }
    }
}