#include <iostream>
#include <vector>

#include <Tree/Node.hpp>
#include <Tree/BinaryTree.hpp>

namespace TreeTestUtil
{

template<typename T>
Tree::Node<T>* createBinaryTree(const std::vector<T>& payload);

template<typename T>
void insertNode(Tree::Node<T>* node, const T val)
{
	auto nodeToInsert = new Tree::Node<T>({val, nullptr, nullptr});
	if(nullptr == node)
	{
		node = nodeToInsert;
	}
	else
	{
		if(node->data <= val)
		{
			node->left = nodeToInsert;
		}
		else
		{
			node->right = nodeToInsert;
		}
	}
}

template<typename T>
void extractNodeValues(std::vector<T>& container, const Tree::Node<T>* const node)
{
	// Extraction Sequence = Root -> Left -> Right
	if(nullptr == node)
		return;

	container.push_back(node->data);
	extractNodeValues(container, node->left);
	extractNodeValues(container, node->right);
}

}