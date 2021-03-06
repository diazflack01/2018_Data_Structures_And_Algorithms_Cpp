#include <gtest/gtest.h>
#include <SortAlgo/MergeSort.hpp>

TEST(MergeSort, array_1Elem)
{
    constexpr auto ARRAY_LENGTH = 1u;
    const unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1};
    unsigned testInput[ARRAY_LENGTH] = {1};

    MergeSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }
}

TEST(MergeSort, array_2Elem)
{
    constexpr auto ARRAY_LENGTH = 2u;
    unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1, 2};
    unsigned testInput[ARRAY_LENGTH] = {2, 1};

    MergeSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }

    unsigned EXPECTED_OUTPUT2[ARRAY_LENGTH] = {1, 2};
    unsigned testInput2[ARRAY_LENGTH] = {1, 2};

    MergeSort::sort(testInput2, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT2[i], testInput2[i]);
    }
}

TEST(MergeSort, array_3Elem)
{
    constexpr auto ARRAY_LENGTH = 3u;
    unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1, 2, 3};
    unsigned testInput[ARRAY_LENGTH] = {2, 1, 3};

    MergeSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }

    unsigned EXPECTED_OUTPUT2[ARRAY_LENGTH] = {1, 2, 3};
    unsigned testInput2[ARRAY_LENGTH] = {3, 1, 2};

    MergeSort::sort(testInput2, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT2[i], testInput2[i]);
    }
}

TEST(MergeSort, array_4Elem)
{
    constexpr auto ARRAY_LENGTH = 4u;
    unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1, 2, 3, 3};
    unsigned testInput[ARRAY_LENGTH] = {3, 2, 1, 3};

    MergeSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }

    unsigned EXPECTED_OUTPUT2[ARRAY_LENGTH] = {1, 2, 3, 3};
    unsigned testInput2[ARRAY_LENGTH] = {3, 1, 3, 2};

    MergeSort::sort(testInput2, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT2[i], testInput2[i]);
    }
}