#include "ShellSort.hpp"

void ShellSort::sort(unsigned arr[], const unsigned arrLen /*endIndex + 1*/)
{

    // SOLUTION 1 --> Tutorials Point using Knuth's Formula
    // auto interval = 1u;

    // while(interval < arrLen/3)
    // {
    //     // Knuth's Formula
    //     interval = interval * 3 + 1;
    // }

    // while(interval > 0)
    // {
    //     for(unsigned outer = interval; outer < arrLen; ++outer)
    //     {
    //         unsigned inner = outer;
    //         auto valueToBeInserted = arr[inner];
    //         while(inner > interval-1 && arr[inner-interval] >= valueToBeInserted)
    //         {
    //             arr[inner] = arr[inner-interval];
    //             inner = inner - interval;
    //         }

    //         arr[inner] = valueToBeInserted;
    //     }

    //     interval = (interval - 1) / 3;
    // }

    // SOLUTION 2 --> Gap recursively divided into 2 while Gap > 0
    for(auto gap = arrLen/2; gap > 0; gap/=2)
    {
        auto interval = gap;
        for(auto outer = interval; outer < arrLen; outer++)
        {
            auto inner = outer;
            auto valueToBeInserted = arr[inner];
            while(inner > interval-1 && arr[inner-interval] >= valueToBeInserted)
            {
                arr[inner] = arr[inner-interval];
                inner -= interval;
            }
            arr[inner] = valueToBeInserted;
        }
    }
}