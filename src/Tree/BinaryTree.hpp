#pragma once
#include <iostream>
#include <vector>
#include <queue>

namespace Tree {
template<typename T>
struct Node;
};


template<typename T>
class BinaryTree
{
public:
	static bool isTreeBst(BinaryTree<T>& binaryTree);

	// CTORs
	BinaryTree();
	BinaryTree(const T v);

	// Insertion
	Tree::Node<T>* insert(const T v);

	// Traversals
	std::vector<T> preOrderTraversalWithRet();
	std::vector<T> postOrderTraversalWithRet();
	std::vector<T> inOrderTraversalWithRet();
	std::vector<T> levelOrderTraversalWithRet();
	void preOrderTraversal();
	void postOrderTraversal();
	void inOrderTraversal();

	// Search
	Tree::Node<T>* search(const T v);

	// Other
	int height();

	Tree::Node<T>* getRootNode() const;

protected:
	// Insertion
	void insert(Tree::Node<T>*& node, Tree::Node<T>* nodeToInsert);

	// Traversals
	void preOrderTraversal(std::vector<T>& container, Tree::Node<T>* node);
	void postOrderTraversal(std::vector<T>& container, Tree::Node<T>* node);
	void inOrderTraversal(std::vector<T>& container, Tree::Node<T>* node);
	void preOrderTraversal(Tree::Node<T>* node);
	void postOrderTraversal(Tree::Node<T>* node);
	void inOrderTraversal(Tree::Node<T>* node);

	// Search
	Tree::Node<T>* recursiveSearch(Tree::Node<T>* node, const T v);

	//Other
	int height(Tree::Node<T>* node);

	Tree::Node<T>* root;
};

template<typename T>
BinaryTree<T>::BinaryTree(): root(nullptr) {}

template<typename T>
BinaryTree<T>::BinaryTree(const T v): root(new Tree::Node<T>({v, nullptr, nullptr})) {}

template<typename T>
Tree::Node<T>* BinaryTree<T>::insert(const T v)
{
	auto newNode = new Tree::Node<T>({v, nullptr, nullptr});

	if(nullptr == root)
	{
		root = newNode;
	}
	else
	{
		insert(root, newNode);	
	}

	return newNode;
}

template<typename T>
void BinaryTree<T>::preOrderTraversal()
{
	if(nullptr != root)
		preOrderTraversal(root);
}

template<typename T>
void BinaryTree<T>::preOrderTraversal(Tree::Node<T>* node)
{
	if(nullptr != node)
	{
		std::cout << node->data << " ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
	
}

template<typename T>
std::vector<T> BinaryTree<T>::preOrderTraversalWithRet()
{
	std::vector<T> ret;
	if(nullptr != root)
	{
		preOrderTraversal(ret, root);
	}
	return ret;
}

template<typename T>
void BinaryTree<T>::preOrderTraversal(std::vector<T>& container, Tree::Node<T>* node)
{
	if(nullptr != node)
	{
		container.push_back(node->data);
		preOrderTraversal(container, node->left);
		preOrderTraversal(container, node->right);
	}
}

template<typename T>
void BinaryTree<T>::postOrderTraversal()
{
	if(nullptr != root)
	{
		postOrderTraversal(root);
	}
}

template<typename T>
void BinaryTree<T>::postOrderTraversal(Tree::Node<T>* node)
{
	if(nullptr != node)
	{
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		std::cout << node->data << " ";
	}
	
}

template<typename T>
std::vector<T> BinaryTree<T>::postOrderTraversalWithRet()
{
	std::vector<T> ret;
	if(nullptr != root)
	{
		postOrderTraversal(ret, root);	
	}
	return ret;
}

template<typename T>
void BinaryTree<T>::postOrderTraversal(std::vector<T>& container, Tree::Node<T>* node)
{
	if(nullptr != node)
	{
		postOrderTraversal(container, node->left);
		postOrderTraversal(container, node->right);
		container.push_back(node->data);
	}
}

template<typename T>
void BinaryTree<T>::inOrderTraversal()
{
	if(nullptr != root)
		inOrderTraversal(root);
}

template<typename T>
void BinaryTree<T>::inOrderTraversal(Tree::Node<T>* node)
{
	if(nullptr != node)
	{
		inOrderTraversal(node->left);
		std::cout << node->data << " ";
		inOrderTraversal(node->right);
	}
}

template<typename T>
std::vector<T> BinaryTree<T>::inOrderTraversalWithRet()
{
	std::vector<T> ret;
	if(nullptr != root)
	{
		inOrderTraversal(ret, root);
	}
	return ret;
}

template<typename T>
void BinaryTree<T>::inOrderTraversal(std::vector<T>& container, Tree::Node<T>* node)
{
	if(nullptr != node)
	{
		inOrderTraversal(container, node->left);
		container.push_back(node->data);
		inOrderTraversal(container, node->right);
	}
}

template<typename T>
std::vector<T> BinaryTree<T>::levelOrderTraversalWithRet()
{
	std::vector<T> ret;
	std::queue<Tree::Node<T>*> queue;
	queue.push(root);

	while(!queue.empty())
	{
		auto node = queue.front();
		queue.pop();
		if(nullptr == node)
		{
			continue;
		}

		ret.push_back(node->data);
		queue.push(node->left);
		queue.push(node->right);
	}
	return ret;
}

template<typename T>
Tree::Node<T>* BinaryTree<T>::getRootNode() const
{
	return root;
}

template<typename T>
void BinaryTree<T>::insert(Tree::Node<T>*& currentNode, Tree::Node<T>* nodeToInsert)
{
	if(nullptr == currentNode)
	{
		currentNode = nodeToInsert;
	}
	else if(nodeToInsert->data <= currentNode->data)
	{
		insert(currentNode->left, nodeToInsert);
	}
	else
	{
		insert(currentNode->right, nodeToInsert);
	}
}

template<typename T>
Tree::Node<T>* BinaryTree<T>::search(const T v)
{
	Tree::Node<T>* ret = nullptr;
	if(nullptr != root)
	{
		ret = recursiveSearch(root, v);
	}
	return ret;
}

template<typename T>
Tree::Node<T>* BinaryTree<T>::recursiveSearch(Tree::Node<T>* node, const T v)
{
	Tree::Node<T>* match = nullptr;
	if(nullptr != node)
	{
		if(node->data == v)
		{
			match = node;
		}
		else if(node->data < v)
		{
			match = recursiveSearch(node->right, v);
		}
		else if(node->data > v)
		{
			match = recursiveSearch(node->left, v);
		}
	}
	return match;
}

template<typename T>
int BinaryTree<T>::height()
{
	if(nullptr == root)
		return -1;

	int leftHeight = height(root->left) + 1;
	int rightHeight = height(root->right) + 1;

	return leftHeight < rightHeight ? rightHeight : leftHeight;
}

template<typename T>
int BinaryTree<T>::height(Tree::Node<T>* node)
{
	if(nullptr == node)
		return -1;

	int leftHeight = height(node->left) + 1;
	int rightHeight = height(node->right) + 1;

	return leftHeight < rightHeight ? rightHeight : leftHeight;
}

template<typename T>
bool BinaryTree<T>::isTreeBst(BinaryTree<T>& binaryTree)
{
	auto rootNode = binaryTree.getRootNode();
	if(nullptr == rootNode)
		return false;

	std::vector<T> treeElements;
	binaryTree.inOrderTraversal(treeElements, rootNode);
	
	for(auto i = 1u; i < treeElements.size(); ++i)
	{
		if(treeElements[i] < treeElements[i-1])
			return false;
	}

	return true;
}
