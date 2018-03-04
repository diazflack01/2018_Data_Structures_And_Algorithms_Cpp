#include <gtest/gtest.h>
#include <SortAlgo/BubbleSort.hpp>

TEST(BubbleSort, array_1Elem)
{
    constexpr auto ARRAY_LENGTH = 1u;
    const unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1};
    unsigned testInput[ARRAY_LENGTH] = {1};

    BubbleSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }
}

TEST(BubbleSort, array_2Elem)
{
    constexpr auto ARRAY_LENGTH = 2u;
    unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1, 2};
    unsigned testInput[ARRAY_LENGTH] = {2, 1};

    BubbleSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }

    unsigned EXPECTED_OUTPUT2[ARRAY_LENGTH] = {1, 2};
    unsigned testInput2[ARRAY_LENGTH] = {1, 2};

    BubbleSort::sort(testInput2, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT2[i], testInput2[i]);
    }
}

TEST(BubbleSort, array_3Elem)
{
    constexpr auto ARRAY_LENGTH = 3u;
    unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1, 2, 3};
    unsigned testInput[ARRAY_LENGTH] = {2, 1, 3};

    BubbleSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }

    unsigned EXPECTED_OUTPUT2[ARRAY_LENGTH] = {1, 2, 3};
    unsigned testInput2[ARRAY_LENGTH] = {3, 1, 2};

    BubbleSort::sort(testInput2, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT2[i], testInput2[i]);
    }
}

TEST(BubbleSort, array_4Elem)
{
    constexpr auto ARRAY_LENGTH = 4u;
    unsigned EXPECTED_OUTPUT[ARRAY_LENGTH] = {1, 2, 3, 3};
    unsigned testInput[ARRAY_LENGTH] = {3, 2, 1, 3};

    BubbleSort::sort(testInput, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT[i], testInput[i]);
    }

    unsigned EXPECTED_OUTPUT2[ARRAY_LENGTH] = {1, 2, 3, 3};
    unsigned testInput2[ARRAY_LENGTH] = {3, 1, 3, 2};

    BubbleSort::sort(testInput2, ARRAY_LENGTH);
    for(auto i = 0u; i < ARRAY_LENGTH; ++i)
    {
        EXPECT_EQ(EXPECTED_OUTPUT2[i], testInput2[i]);
    }
}