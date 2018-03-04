#pragma once

struct InsertionSort
{
    InsertionSort() = delete;
    InsertionSort(const InsertionSort&) = delete;
    ~InsertionSort() = delete;
    static void sort(unsigned arr[], const unsigned arrLen);
};