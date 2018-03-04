#include <SearchAlgo/LinearSearch.hpp>
#include <vector>

TEST(LinearSearch, arrayAsInput)
{
	constexpr auto ARRAY_LENGTH = 5;
	constexpr int TEST_DATA[ARRAY_LENGTH] = {2, 55, 3, 69, 69};

	EXPECT_EQ(linearSearch(TEST_DATA, ARRAY_LENGTH, 0), -1);
	EXPECT_EQ(linearSearch(TEST_DATA, ARRAY_LENGTH, 2), 0);
	EXPECT_EQ(linearSearch(TEST_DATA, ARRAY_LENGTH, 3), 2);
	EXPECT_EQ(linearSearch(TEST_DATA, ARRAY_LENGTH, 69), 3);
}

TEST(LinearSearch, vectorAsInput)
{
	const std::vector<int> TEST_DATA = {2, 55, 3, 69, 69};

	EXPECT_EQ(linearSearchVector(TEST_DATA, 0), -1);
	EXPECT_EQ(linearSearchVector(TEST_DATA, 2), 0);
	EXPECT_EQ(linearSearchVector(TEST_DATA, 3), 2);
	EXPECT_EQ(linearSearchVector(TEST_DATA, 69), 3);
}