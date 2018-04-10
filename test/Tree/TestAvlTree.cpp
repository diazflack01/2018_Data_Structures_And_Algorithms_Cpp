#include <gtest/gtest.h>

#include <Tree/AvlTree.hpp>

using namespace Tree;
using AvlTree_t = AvlTree<int>;

TEST(TestAvlTree, defaultConstructor_shouldReturnNullptrForRootNode)
{
    AvlTree_t avlTree;

    ASSERT_TRUE(avlTree.levelOrderTraversal().empty());
}

TEST(TestAvlTree, insert_leftleftUnbalanced)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);

    avlTree.insert(45);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(45, levelOrderTraversedVector[1]);

    avlTree.insert(40);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(45, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(50, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, insert_leftrightUnbalanced)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);

    avlTree.insert(45);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(45, levelOrderTraversedVector[1]);

    avlTree.insert(47);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(47, levelOrderTraversedVector[0]);
    ASSERT_EQ(45, levelOrderTraversedVector[1]);
    ASSERT_EQ(50, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, insert_rightrightUnbalanced)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);

    avlTree.insert(55);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(55, levelOrderTraversedVector[1]);

    avlTree.insert(60);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(55, levelOrderTraversedVector[0]);
    ASSERT_EQ(50, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, insert_rightleftUnbalanced)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);

    avlTree.insert(55);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(55, levelOrderTraversedVector[1]);

    avlTree.insert(53);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(53, levelOrderTraversedVector[0]);
    ASSERT_EQ(50, levelOrderTraversedVector[1]);
    ASSERT_EQ(55, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, insert_mix_fromGeeksForGeeks)
{
    AvlTree_t avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(20, levelOrderTraversedVector[0]);
    ASSERT_EQ(10, levelOrderTraversedVector[1]);
    ASSERT_EQ(30, levelOrderTraversedVector[2]);

    avlTree.insert(40);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(20, levelOrderTraversedVector[0]);
    ASSERT_EQ(10, levelOrderTraversedVector[1]);
    ASSERT_EQ(30, levelOrderTraversedVector[2]);
    ASSERT_EQ(40, levelOrderTraversedVector[3]);

    avlTree.insert(50);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(20, levelOrderTraversedVector[0]);
    ASSERT_EQ(10, levelOrderTraversedVector[1]);
    ASSERT_EQ(40, levelOrderTraversedVector[2]);
    ASSERT_EQ(30, levelOrderTraversedVector[3]);
    ASSERT_EQ(50, levelOrderTraversedVector[4]);
    
    avlTree.insert(25);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(30, levelOrderTraversedVector[0]);
    ASSERT_EQ(20, levelOrderTraversedVector[1]);
    ASSERT_EQ(40, levelOrderTraversedVector[2]);
    ASSERT_EQ(10, levelOrderTraversedVector[3]);
    ASSERT_EQ(25, levelOrderTraversedVector[4]);
    ASSERT_EQ(50, levelOrderTraversedVector[5]);
}