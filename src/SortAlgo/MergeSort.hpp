#pragma once

struct MergeSort
{
    MergeSort() = delete;
    MergeSort(const MergeSort&) = delete;
    ~MergeSort() = delete;
    static void sort(unsigned arr[], const unsigned arrLen);
};