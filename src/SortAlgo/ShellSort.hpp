#pragma once

struct ShellSort
{
    ShellSort() = delete;
    ShellSort(const ShellSort&) = delete;
    ~ShellSort() = delete;
    static void sort(unsigned arr[], const unsigned arrLen);
};