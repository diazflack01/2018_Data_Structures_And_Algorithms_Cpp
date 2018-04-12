#include <gtest/gtest.h>

#include <Tree/BinaryHeapTree.hpp>

TEST(TestBinaryHeapTree, constructor_default)
{
    MinBinaryHeap<int> minBinaryHeap;

    ASSERT_EQ(0, minBinaryHeap.size());
}

TEST(TestBinaryHeapTree, constructor_arrayAsParameter)
{
    int TEST_INPUT[] = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT, 7);

    ASSERT_EQ(7, minBinaryHeap.size());
    const auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);
}

TEST(TestBinaryHeapTree, constructor_vectorAsParameter)
{
    std::vector<int> TEST_INPUT = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT);

    ASSERT_EQ(7, minBinaryHeap.size());
    const auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);
}

TEST(TestBinaryHeapTree, insert_emptyTree)
{
    MinBinaryHeap<int> minBinaryHeap;

    minBinaryHeap.insert(69);
    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(1, minHeapTree.size());
    ASSERT_EQ(69, minHeapTree[0]);

    minBinaryHeap.insert(5);
    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(2, minHeapTree.size());
    ASSERT_EQ(5, minHeapTree[0]);
    ASSERT_EQ(69, minHeapTree[1]);

    minBinaryHeap.insert(3);
    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(3, minHeapTree.size());
    ASSERT_EQ(3, minHeapTree[0]);
    ASSERT_EQ(69, minHeapTree[1]);
    ASSERT_EQ(5, minHeapTree[2]);
}

TEST(TestBinaryHeapTree, insert_nonEmptyTree)
{
    std::vector<int> TEST_INPUT = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT);

    ASSERT_EQ(7, minBinaryHeap.size());
    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);

    minBinaryHeap.insert(10);

    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(8, minBinaryHeap.size());
    ASSERT_EQ(10, minHeapTree[0]);
    ASSERT_EQ(30, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(50, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);
    ASSERT_EQ(100, minHeapTree[7]);
}

TEST(TestBinaryHeapTree, deleteMin_emptyTreeAndNonExisting)
{
    MinBinaryHeap<int> minBinaryHeap;

    minBinaryHeap.deleteMin();

    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(0, minHeapTree.size());
}

TEST(TestBinaryHeapTree, deleteMin_NonEmptyTree)
{
    std::vector<int> TEST_INPUT = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT);

    ASSERT_EQ(7, minBinaryHeap.size());
    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);

    minBinaryHeap.deleteMin();

    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(6, minBinaryHeap.size());
    ASSERT_EQ(50, minHeapTree[0]);
    ASSERT_EQ(80, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(150, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
}

TEST(TestBinaryHeapTree, extractMin_emptyTree)
{
    MinBinaryHeap<int> minBinaryHeap;

    const auto min = minBinaryHeap.extractMin();

    EXPECT_EQ(-1, min);
}

TEST(TestBinaryHeapTree, extractMin_nonEmptyTree)
{
    std::vector<int> TEST_INPUT = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT);

    ASSERT_EQ(7, minBinaryHeap.size());
    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);

    const auto min = minBinaryHeap.extractMin();
    EXPECT_EQ(30, min);
}

TEST(TestBinaryHeapTree, modifyValueAtIndex_emptyTreeAndInvalidIndex)
{
    MinBinaryHeap<int> minBinaryHeap;

    minBinaryHeap.modifyValueAtIndex(25, 1);
    EXPECT_EQ(0, minBinaryHeap.size());

    minBinaryHeap.insert(55);
    minBinaryHeap.modifyValueAtIndex(25, 1);
    EXPECT_EQ(1, minBinaryHeap.size());
    EXPECT_EQ(55, minBinaryHeap.getHeapTree()[0]);
}

TEST(TestBinaryHeapTree, modifyValueAtIndex_nonEmptyTree)
{
    std::vector<int> TEST_INPUT = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT);

    ASSERT_EQ(7, minBinaryHeap.size());
    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);

    minBinaryHeap.modifyValueAtIndex(2, 2);
    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(7, minHeapTree.size());
    ASSERT_EQ(2, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(30, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);

    minBinaryHeap.modifyValueAtIndex(0, 999);
    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(7, minHeapTree.size());
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(90, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(999, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);
}

TEST(TestBinaryHeapTree, deleteIndex_emptyTreeAndInvalidIndex)
{
    MinBinaryHeap<int> minBinaryHeap;

    minBinaryHeap.deleteIndex(25);
    EXPECT_EQ(0, minBinaryHeap.size());

    minBinaryHeap.insert(55);
    minBinaryHeap.deleteIndex(25);
    EXPECT_EQ(1, minBinaryHeap.size());
    EXPECT_EQ(55, minBinaryHeap.getHeapTree()[0]);
}

TEST(TestBinaryHeapTree, deleteIndex_nonEmptyTree)
{
    std::vector<int> TEST_INPUT = {90, 80, 70, 100, 50, 30, 150};
    MinBinaryHeap<int> minBinaryHeap(TEST_INPUT);

    ASSERT_EQ(7, minBinaryHeap.size());
    auto minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(70, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(90, minHeapTree[5]);
    ASSERT_EQ(150, minHeapTree[6]);

    minBinaryHeap.deleteIndex(2);
    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(6, minHeapTree.size());
    ASSERT_EQ(30, minHeapTree[0]);
    ASSERT_EQ(50, minHeapTree[1]);
    ASSERT_EQ(90, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(80, minHeapTree[4]);
    ASSERT_EQ(150, minHeapTree[5]);

    minBinaryHeap.deleteIndex(0);
    minHeapTree = minBinaryHeap.getHeapTree();
    ASSERT_EQ(5, minHeapTree.size());
    ASSERT_EQ(50, minHeapTree[0]);
    ASSERT_EQ(80, minHeapTree[1]);
    ASSERT_EQ(90, minHeapTree[2]);
    ASSERT_EQ(100, minHeapTree[3]);
    ASSERT_EQ(150, minHeapTree[4]);
}