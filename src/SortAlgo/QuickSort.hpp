#pragma once

struct QuickSort
{
    QuickSort() = delete;
    QuickSort(const QuickSort&) = delete;
    ~QuickSort() = delete;
    static void sort(unsigned arr[], const unsigned arrLen);
};