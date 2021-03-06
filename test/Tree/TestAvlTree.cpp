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

TEST(TestAvlTree, delete_nodeDoesNotExist)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    avlTree.insert(60);
    avlTree.insert(40);
    avlTree.deleteNodeWithKey(55);

    const auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(3, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, DISABLED_delete_leftLeftUnbalanced_AfterRemoval)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    avlTree.insert(40);
    avlTree.insert(60);
    avlTree.insert(38);
    avlTree.insert(42);

    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(5, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(38, levelOrderTraversedVector[3]);
    ASSERT_EQ(42, levelOrderTraversedVector[4]);

    avlTree.deleteNodeWithKey(42);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(4, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(38, levelOrderTraversedVector[3]);

    avlTree.deleteNodeWithKey(60);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(3, levelOrderTraversedVector.size());
    ASSERT_EQ(40, levelOrderTraversedVector[0]);
    ASSERT_EQ(38, levelOrderTraversedVector[1]);
    ASSERT_EQ(50, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, DISABLED_delete_leftRightUnbalanced_AfterRemoval)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    avlTree.insert(40);
    avlTree.insert(60);
    avlTree.insert(42);

    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(4, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(42, levelOrderTraversedVector[3]);

    avlTree.deleteNodeWithKey(60);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(3, levelOrderTraversedVector.size());
    ASSERT_EQ(42, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(50, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, DISABLED_delete_rightRightUnbalanced_AfterRemoval)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    avlTree.insert(40);
    avlTree.insert(60);
    avlTree.insert(58);
    avlTree.insert(62);

    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(5, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(58, levelOrderTraversedVector[3]);
    ASSERT_EQ(62, levelOrderTraversedVector[4]);

    avlTree.deleteNodeWithKey(58);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(4, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(62, levelOrderTraversedVector[3]);

    avlTree.deleteNodeWithKey(40);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(3, levelOrderTraversedVector.size());
    ASSERT_EQ(60, levelOrderTraversedVector[0]);
    ASSERT_EQ(50, levelOrderTraversedVector[1]);
    ASSERT_EQ(62, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, delete_rightLeftUnbalanced_AfterRemoval)
{
    AvlTree_t avlTree;

    avlTree.insert(50);
    avlTree.insert(40);
    avlTree.insert(60);
    avlTree.insert(58);
    avlTree.insert(62);

    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(5, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(58, levelOrderTraversedVector[3]);
    ASSERT_EQ(62, levelOrderTraversedVector[4]);

    avlTree.deleteNodeWithKey(62);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(4, levelOrderTraversedVector.size());
    ASSERT_EQ(50, levelOrderTraversedVector[0]);
    ASSERT_EQ(40, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
    ASSERT_EQ(58, levelOrderTraversedVector[3]);

    avlTree.deleteNodeWithKey(40);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(3, levelOrderTraversedVector.size());
    ASSERT_EQ(58, levelOrderTraversedVector[0]);
    ASSERT_EQ(50, levelOrderTraversedVector[1]);
    ASSERT_EQ(60, levelOrderTraversedVector[2]);
}

TEST(TestAvlTree, delete_mix_fromGeeksForGeeks)
{
    AvlTree_t avlTree;
    avlTree.insert(9);
    avlTree.insert(5);
    avlTree.insert(10);
    avlTree.insert(0);
    avlTree.insert(6);
    avlTree.insert(11);
    avlTree.insert(-1);
    avlTree.insert(1);
    avlTree.insert(2);

    auto levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(9, levelOrderTraversedVector.size());
    ASSERT_EQ(9, levelOrderTraversedVector[0]);
    ASSERT_EQ(1, levelOrderTraversedVector[1]);
    ASSERT_EQ(10, levelOrderTraversedVector[2]);
    ASSERT_EQ(0, levelOrderTraversedVector[3]);
    ASSERT_EQ(5, levelOrderTraversedVector[4]);
    ASSERT_EQ(11, levelOrderTraversedVector[5]);
    ASSERT_EQ(-1, levelOrderTraversedVector[6]);
    ASSERT_EQ(2, levelOrderTraversedVector[7]);
    ASSERT_EQ(6, levelOrderTraversedVector[8]);

    avlTree.deleteNodeWithKey(10);
    levelOrderTraversedVector = avlTree.levelOrderTraversal();
    ASSERT_EQ(8, levelOrderTraversedVector.size());
    ASSERT_EQ(1, levelOrderTraversedVector[0]);
    ASSERT_EQ(0, levelOrderTraversedVector[1]);
    ASSERT_EQ(9, levelOrderTraversedVector[2]);
    ASSERT_EQ(-1, levelOrderTraversedVector[3]);
    ASSERT_EQ(5, levelOrderTraversedVector[4]);
    ASSERT_EQ(11, levelOrderTraversedVector[5]);
    ASSERT_EQ(2, levelOrderTraversedVector[6]);
    ASSERT_EQ(6, levelOrderTraversedVector[7]);
}