#pragma once

struct BubbleSort
{
    BubbleSort() = delete;
    BubbleSort(const BubbleSort&) = delete;
    ~BubbleSort() = delete;
    static void sort(unsigned arr[], const unsigned arrLen);
};