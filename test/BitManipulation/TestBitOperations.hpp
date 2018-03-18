#include <gtest/gtest.h>
#include <BitManipulation/BitOperations.hpp>


TEST(BitManipulation, setBit)
{
	EXPECT_EQ(0b1111, setBit(0b1011, 2));
	EXPECT_EQ(0b1011, setBit(0b1011, 0));
}

TEST(BitManipulation, toggleBit)
{
	EXPECT_EQ(0b1111, toggleBit(0b1011, 2));
	EXPECT_EQ(0b1010, toggleBit(0b1011, 0));
}

TEST(BitManipulation, clearBit)
{
	EXPECT_EQ(0b1011, clearBit(0b1011, 2));
	EXPECT_EQ(0b1010, clearBit(0b1011, 0));
}

TEST(BitManipulation, testBit)
{
	EXPECT_TRUE(testBit(0b1011, 0));
	EXPECT_TRUE(testBit(0b1011, 1));
	EXPECT_FALSE(testBit(0b1011, 2));
	EXPECT_TRUE(testBit(0b1011, 3));
}

TEST(BitManipulation, addition)
{
	EXPECT_EQ(2, add(1,1));
	EXPECT_EQ(5, add(2,3));
	EXPECT_EQ(8, add(-3,11));
	EXPECT_EQ(5, add(-2,7));
	EXPECT_EQ(-2, add(3,-5));
}

TEST(BitManipulation, subtraction)
{
	EXPECT_EQ(0, subtract(1,1));
	EXPECT_EQ(-1, subtract(2,3));
	EXPECT_EQ(-14, subtract(-3,11));
	EXPECT_EQ(-9, subtract(-2,7));
	EXPECT_EQ(8, subtract(3,-5));
}

TEST(BitManipulation, mutiply)
{
	EXPECT_EQ(1, multiply(1,1));
	EXPECT_EQ(6, multiply(2,3));
	EXPECT_EQ(-6, multiply(2,-3));
	EXPECT_EQ(6, multiply(-2,-3));
}

TEST(BitManipulation, division)
{
	EXPECT_EQ(1, division(1,1));
	EXPECT_EQ(0, division(2,3));
	EXPECT_EQ(0, division(2,-3));
	EXPECT_EQ(2, division(-2,-1));
	EXPECT_EQ(-2, division(-21,10));
	EXPECT_EQ(0, division(0,10));
	EXPECT_EQ(0, division(-1,-2));
}