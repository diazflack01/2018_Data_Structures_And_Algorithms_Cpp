#include <gtest/gtest.h>

#include "TreeUtil.hpp"
#include <Tree/BinaryTree.hpp>

TEST(TestBinaryTree, defaultContructor_shouldReturnNullRoot)
{
	BinaryTree<int> binaryTree;
	EXPECT_EQ(nullptr, binaryTree.getRootNode());
}

TEST(TestBinaryTree, contructorWithVal_shouldReturnNonNullRoot)
{
	BinaryTree<int> binaryTree(69);
	const auto rootNode = binaryTree.getRootNode();
	EXPECT_NE(nullptr, rootNode);
	EXPECT_EQ(nullptr, rootNode->left);
	EXPECT_EQ(nullptr, rootNode->right);
	EXPECT_EQ(69, rootNode->data);
}

TEST(TestBinaryTree, insert_emptyTreeShouldInsertInRoot)
{
	BinaryTree<int> binaryTree;
	binaryTree.insert(69);
	EXPECT_NE(nullptr, binaryTree.getRootNode());
	EXPECT_EQ(69, binaryTree.getRootNode()->data);
	EXPECT_EQ(nullptr, binaryTree.getRootNode()->left);
	EXPECT_EQ(nullptr, binaryTree.getRootNode()->right);
}

TEST(TestBinaryTree, insert_nonEmptyTreeShouldInsertToCorrectLeaf)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	std::vector<int> createdTree;
	TreeTestUtil::extractNodeValues(createdTree, binaryTree.getRootNode());
	auto rootNode = binaryTree.getRootNode();
	EXPECT_EQ(69, rootNode->data);
	EXPECT_EQ(55, rootNode->left->data);
	EXPECT_EQ(69, rootNode->left->right->data);
	EXPECT_EQ(49, rootNode->left->left->data);
	EXPECT_EQ(45, rootNode->left->left->left->data);
	EXPECT_EQ(75, rootNode->right->data);
	EXPECT_EQ(99, rootNode->right->right->data);
	EXPECT_EQ(75, rootNode->right->left->data);
	// binaryTree.preOrderTraversal();
	// std::cout << std::endl;
	// auto t = binaryTree.preOrderTraversalWithRet();
	// for(auto&& i : t)
	// 	std::cout << i << " ";
	// std::cout << "\nDONE with vector\n";
	// binaryTree.postOrderTraversal();
	// std::cout << std::endl;
	// t = binaryTree.postOrderTraversalWithRet();
	// for(auto&& i : t)
	// 	std::cout << i << " ";
	// std::cout << "\nDONE with vector\n";
	// binaryTree.inOrderTraversal();
	// std::cout << std::endl;
	// t = binaryTree.inOrderTraversalWithRet();
	// for(auto&& i : t)
	// 	std::cout << i << " ";
	// std::cout << "\nDONE with vector\n";
}

TEST(TestBinaryTree, preOrderTraversal)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	std::vector<int> TEST_OUTPUT_PREORDER = {69, 55, 49, 45, 69, 75, 75, 99};
	
	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	const auto actualPreoderTraversalOutput = binaryTree.preOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_PREORDER.size(), actualPreoderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_PREORDER.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_PREORDER[i], actualPreoderTraversalOutput[i]);
}

TEST(TestBinaryTree, postOrderTraversal)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	std::vector<int> TEST_OUTPUT_POSTORDER = {45, 49, 69, 55, 75, 99, 75, 69};

	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	const auto actualPostoderTraversalOutput = binaryTree.postOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_POSTORDER.size(), actualPostoderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_POSTORDER.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_POSTORDER[i], actualPostoderTraversalOutput[i]);
}

TEST(TestBinaryTree, inOrderTraversal)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	std::vector<int> TEST_OUTPUT_INORDER = {45, 49, 55, 69, 69, 75, 75, 99};

	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	const auto actualInoderTraversalOutput = binaryTree.inOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_INORDER.size(), actualInoderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_INORDER.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_INORDER[i], actualInoderTraversalOutput[i]);
}

TEST(TestBinaryTree, levelOrderTraversalWithRet)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	std::vector<int> TEST_OUTPUT_LEVELORDER = {69, 55, 75, 49, 69, 75, 99, 45};

	BinaryTree<int> binaryTree;
	auto actualLevelOderTraversalOutput = binaryTree.levelOrderTraversalWithRet();
	ASSERT_EQ(0, actualLevelOderTraversalOutput.size());

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	actualLevelOderTraversalOutput = binaryTree.levelOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_LEVELORDER.size(), actualLevelOderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_LEVELORDER.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_LEVELORDER[i], actualLevelOderTraversalOutput[i]);
}

TEST(TestBinaryTree, search_shouldReturnNullptrIfNoMatch)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};

	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	ASSERT_EQ(nullptr, binaryTree.search(999));
	ASSERT_EQ(75, (binaryTree.search(75))->data);
	
}

TEST(TestBinaryTree, search_shouldReturnNodeIfSearchValExist)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};

	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	ASSERT_NE(nullptr, binaryTree.search(75));
	ASSERT_EQ(75, (binaryTree.search(75))->data);
}

TEST(TestBinaryTree, height_mixTest)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};

	BinaryTree<int> binaryTree;

	ASSERT_EQ(-1, binaryTree.height());
	binaryTree.insert(TEST_INPUT[0]);
	ASSERT_EQ(0, binaryTree.height());
	binaryTree.insert(TEST_INPUT[1]);
	ASSERT_EQ(1, binaryTree.height());
	binaryTree.insert(TEST_INPUT[2]);
	ASSERT_EQ(2, binaryTree.height());
	binaryTree.insert(TEST_INPUT[3]);
	ASSERT_EQ(2, binaryTree.height());
	binaryTree.insert(TEST_INPUT[4]);
	ASSERT_EQ(3, binaryTree.height());
	binaryTree.insert(TEST_INPUT[5]);
	ASSERT_EQ(3, binaryTree.height());
	binaryTree.insert(TEST_INPUT[6]);
	ASSERT_EQ(3, binaryTree.height());
	binaryTree.insert(TEST_INPUT[7]);
	ASSERT_EQ(3, binaryTree.height());
}

TEST(TestBinaryTree, isTreeBst_mixTest) //THIS TEST WILL ALWAYS PASS!!!
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	BinaryTree<int> binaryTree;

	EXPECT_EQ(false, BinaryTree<int>::isTreeBst(binaryTree));

	for(auto&& e : TEST_INPUT)
	{
		binaryTree.insert(e);
		EXPECT_EQ(true, BinaryTree<int>::isTreeBst(binaryTree));
	}
}

TEST(TestBinaryTree, mirrorTree)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	std::vector<int> TEST_OUTPUT_LEVELORDER = {69, 55, 75, 49, 69, 75, 99, 45};
	std::vector<int> TEST_OUTPUT_LEVELORDER_MIRROR = {69, 75, 55, 99, 75, 69, 49, 45};
	BinaryTree<int> binaryTree;

	for(auto&& e : TEST_INPUT)
		binaryTree.insert(e);

	auto actualLevelOderTraversalOutput = binaryTree.levelOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_LEVELORDER.size(), actualLevelOderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_LEVELORDER.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_LEVELORDER[i], actualLevelOderTraversalOutput[i]);

	binaryTree.mirrorTree();
	actualLevelOderTraversalOutput = binaryTree.levelOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_LEVELORDER_MIRROR.size(), actualLevelOderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_LEVELORDER_MIRROR.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_LEVELORDER_MIRROR[i], actualLevelOderTraversalOutput[i]);

	binaryTree.mirrorTree();
	actualLevelOderTraversalOutput = binaryTree.levelOrderTraversalWithRet();
	ASSERT_EQ(TEST_OUTPUT_LEVELORDER.size(), actualLevelOderTraversalOutput.size());
	for(auto i = 0u; i < TEST_OUTPUT_LEVELORDER.size(); ++i)
		EXPECT_EQ(TEST_OUTPUT_LEVELORDER[i], actualLevelOderTraversalOutput[i]);
}

TEST(TestBinaryTree, diameter)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	BinaryTree<int> binaryTree;

	ASSERT_EQ(0, binaryTree.diameter());

	for(auto&& e : TEST_INPUT)
		binaryTree.insert(e);

	ASSERT_EQ(6, binaryTree.diameter());
}

TEST(TestBinaryTree, isFoldable)
{
	BinaryTree<int> binaryTree;

	EXPECT_TRUE(binaryTree.isFoldable());
	binaryTree.insert(69);
	EXPECT_TRUE(binaryTree.isFoldable());
	binaryTree.insert(55);
	EXPECT_FALSE(binaryTree.isFoldable());
	binaryTree.insert(70);
	EXPECT_TRUE(binaryTree.isFoldable());
}

TEST(TestBinaryTree, nodeValuesKDistant)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	BinaryTree<int> binaryTree;

	auto nodesWithKDistance = binaryTree.nodeValuesKDistant(0);
	ASSERT_EQ(0, nodesWithKDistance.size());
	nodesWithKDistance = binaryTree.nodeValuesKDistant(1);
	ASSERT_EQ(0, nodesWithKDistance.size());
	nodesWithKDistance = binaryTree.nodeValuesKDistant(69);
	ASSERT_EQ(0, nodesWithKDistance.size());

	for(auto&& e : TEST_INPUT)
		binaryTree.insert(e);

	nodesWithKDistance = binaryTree.nodeValuesKDistant(0);
	ASSERT_EQ(1, nodesWithKDistance.size());
	EXPECT_EQ(69, nodesWithKDistance[0]);

	nodesWithKDistance = binaryTree.nodeValuesKDistant(1);
	ASSERT_EQ(2, nodesWithKDistance.size());
	EXPECT_EQ(55, nodesWithKDistance[0]);
	EXPECT_EQ(75, nodesWithKDistance[1]);

	nodesWithKDistance = binaryTree.nodeValuesKDistant(2);
	ASSERT_EQ(4, nodesWithKDistance.size());
	EXPECT_EQ(49, nodesWithKDistance[0]);
	EXPECT_EQ(69, nodesWithKDistance[1]);
	EXPECT_EQ(75, nodesWithKDistance[2]);
	EXPECT_EQ(99, nodesWithKDistance[3]);

	nodesWithKDistance = binaryTree.nodeValuesKDistant(3);
	ASSERT_EQ(1, nodesWithKDistance.size());
	EXPECT_EQ(45, nodesWithKDistance[0]);
}

TEST(TestBinaryTree, getMaxWidth)
{
	std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	BinaryTree<int> binaryTree;

	ASSERT_EQ(-1, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[0]);
	ASSERT_EQ(1, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[1]);
	ASSERT_EQ(1, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[2]);
	ASSERT_EQ(1, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[3]);
	ASSERT_EQ(2, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[4]);
	ASSERT_EQ(2, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[5]);
	ASSERT_EQ(2, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[6]);
	ASSERT_EQ(3, binaryTree.getMaxWidth());
	binaryTree.insert(TEST_INPUT[7]);
	ASSERT_EQ(4, binaryTree.getMaxWidth());
}

TEST(TestBinaryTree, delete_nodeToDeleteHasNoChild)
{
	const std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75};
	const std::vector<int> EXPECTED_OUTPUT = {69, 55, 75, 49, 69, 75, 99};
	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	binaryTree.deleteNode(45);
	const auto actualLevelOrderOutput = binaryTree.levelOrderTraversalWithRet();

	ASSERT_EQ(EXPECTED_OUTPUT.size(), actualLevelOrderOutput.size());
	for(auto i = 0u; i < actualLevelOrderOutput.size(); ++i)
	{
		EXPECT_EQ(EXPECTED_OUTPUT[i], actualLevelOrderOutput[i]);
	}
}

TEST(TestBinaryTree, delete_nodeToDeleteHasOneLeftChild)
{
	const std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75, 100};
	const std::vector<int> EXPECTED_OUTPUT_LEFT_CHILD_NOT_EMPTY = {69, 55, 75, 45, 69, 75, 99, 100};
	
	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	binaryTree.deleteNode(49);
	const auto actualLevelOrderOutput = binaryTree.levelOrderTraversalWithRet();

	ASSERT_EQ(EXPECTED_OUTPUT_LEFT_CHILD_NOT_EMPTY.size(), actualLevelOrderOutput.size());
	for(auto i = 0u; i < actualLevelOrderOutput.size(); ++i)
	{
		EXPECT_EQ(EXPECTED_OUTPUT_LEFT_CHILD_NOT_EMPTY[i], actualLevelOrderOutput[i]);
	}
}

TEST(TestBinaryTree, delete_nodeToDeleteHasOneRightChild)
{
	const std::vector<int> TEST_INPUT = {69, 55, 69, 49, 45, 75, 99, 75, 100};
	const std::vector<int> EXPECTED_OUTPUT_RIGHT_CHILD_NOT_EMPTY = {69, 55, 75, 49, 69, 75, 100, 45};

		BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	binaryTree.deleteNode(99);
	const auto actualLevelOrderOutput = binaryTree.levelOrderTraversalWithRet();

	ASSERT_EQ(EXPECTED_OUTPUT_RIGHT_CHILD_NOT_EMPTY.size(), actualLevelOrderOutput.size());
	for(auto i = 0u; i < actualLevelOrderOutput.size(); ++i)
	{
		EXPECT_EQ(EXPECTED_OUTPUT_RIGHT_CHILD_NOT_EMPTY[i], actualLevelOrderOutput[i]);
	}
}

TEST(TestBinaryTree, delete_nodeToDeleteHasTwoChild)
{
	const std::vector<int> TEST_INPUT = {69, 55, 69, 2, 1, 45, 75, 99, 75, 43, 46, 42};
	const std::vector<int> EXPECTED_OUTPUT = {69, 55, 75, 42, 69, 75, 99, 1, 45, 43, 46};
	BinaryTree<int> binaryTree;

	for(auto&& i : TEST_INPUT)
		binaryTree.insert(i);

	binaryTree.deleteNode(2);
	const auto actualLevelOrderOutput = binaryTree.levelOrderTraversalWithRet();

	ASSERT_EQ(EXPECTED_OUTPUT.size(), actualLevelOrderOutput.size());
	for(auto i = 0u; i < actualLevelOrderOutput.size(); ++i)
	{
		EXPECT_EQ(EXPECTED_OUTPUT[i], actualLevelOrderOutput[i]);
	}
}