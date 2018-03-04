#pragma once

struct SelectionSort
{
    SelectionSort() = delete;
    SelectionSort(const SelectionSort&) = delete;
    ~SelectionSort() = delete;
    static void sort(unsigned arr[], const unsigned arrLen);
};