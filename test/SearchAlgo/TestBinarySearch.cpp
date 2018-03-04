#include <gtest/gtest.h>
#include <SearchAlgo/BinarySearch.hpp>
#include <vector>

TEST(BinarySearch, arrayAsInput)
{
	constexpr auto ARRAY_LENGTH_ODD = 5;
	constexpr auto ARRAY_LENGTH_EVEN = 4;
	constexpr int TEST_DATA_ODD[ARRAY_LENGTH_ODD] = {1, 2, 3, 4, 5};
	constexpr int TEST_DATA_EVEN[ARRAY_LENGTH_EVEN] = {1, 2, 3, 4};

	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, 3), 2);
	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, 5), 4);
	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, 1), 0);
	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, 2), 1);
	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, 4), 3);
	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, 69), -1);
	EXPECT_EQ(binarySearch(TEST_DATA_ODD, ARRAY_LENGTH_ODD, -1), -1);

	EXPECT_EQ(binarySearch(TEST_DATA_EVEN, ARRAY_LENGTH_EVEN, 1), 0);
	EXPECT_EQ(binarySearch(TEST_DATA_EVEN, ARRAY_LENGTH_EVEN, 2), 1);
	EXPECT_EQ(binarySearch(TEST_DATA_EVEN, ARRAY_LENGTH_EVEN, 3), 2);
	EXPECT_EQ(binarySearch(TEST_DATA_EVEN, ARRAY_LENGTH_EVEN, 4), 3);
	EXPECT_EQ(binarySearch(TEST_DATA_EVEN, ARRAY_LENGTH_EVEN, 69), -1);
	EXPECT_EQ(binarySearch(TEST_DATA_EVEN, ARRAY_LENGTH_EVEN, -1), -1);
}

TEST(BinarySearch, vectorAsInput)
{
	const std::vector<int> TEST_DATA_ODD = {1, 2, 3, 4, 5};
	const std::vector<int> TEST_DATA_EVEN = {1, 2, 3, 4};

	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, 3), 2);
	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, 5), 4);
	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, 1), 0);
	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, 2), 1);
	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, 4), 3);
	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, 69), -1);
	EXPECT_EQ(binarySearchVector(TEST_DATA_ODD, -1), -1);

	EXPECT_EQ(binarySearchVector(TEST_DATA_EVEN, 1), 0);
	EXPECT_EQ(binarySearchVector(TEST_DATA_EVEN, 2), 1);
	EXPECT_EQ(binarySearchVector(TEST_DATA_EVEN, 3), 2);
	EXPECT_EQ(binarySearchVector(TEST_DATA_EVEN, 4), 3);
	EXPECT_EQ(binarySearchVector(TEST_DATA_EVEN, 69), -1);
	EXPECT_EQ(binarySearchVector(TEST_DATA_EVEN, -1), -1);
}