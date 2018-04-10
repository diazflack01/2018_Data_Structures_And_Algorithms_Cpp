#pragma once
#include <vector>
#include <queue>
#include <algorithm>

namespace Tree
{

template<typename T>
struct AvlNode
{
    T key;
    AvlNode* left;
    AvlNode* right;
    int height;
};

template<typename T>
class AvlTree
{
public:
    // CTOR
    AvlTree();
    AvlTree(const T v);

    // Insertion - https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
    void insert(const T v);

    // Deletion
    void deleteNodeWithKey(const T v);

    // Traversal
    std::vector<T> levelOrderTraversal();

private:
    AvlNode<T>* insertRecursive(AvlNode<T>* node, const T v);
    AvlNode<T>* leftRotate(AvlNode<T>* node);
    AvlNode<T>* rightRotate(AvlNode<T>* node);
    int getBalanceFactor(AvlNode<T>* node);
    int height(AvlNode<T>* node);
    AvlNode<T>* newNode(const T v);
    AvlNode<T>* rootNode;
};

template<typename T>
AvlTree<T>::AvlTree(): rootNode{nullptr} {}

template<typename T>
std::vector<T> AvlTree<T>::levelOrderTraversal()
{
    std::vector<T> ret;
    std::queue<AvlNode<T>*> queue;
    queue.push(rootNode);

    while(!queue.empty())
    {
        AvlNode<T>* node = queue.front();
        queue.pop();

        if(nullptr == node)
            continue;

        ret.push_back(node->key);
        queue.push(node->left);
        queue.push(node->right);
    }
    
    return ret;
}

template<typename T>
int AvlTree<T>::getBalanceFactor(AvlNode<T>* node)
{
    if(nullptr == node)
        return 0;
    return height(node->left) - height(node->right);
}

template<typename T>
int AvlTree<T>::height(AvlNode<T>* node)
{
    if(nullptr == node)
        return 0;
    return node->height;
}

template<typename T>
AvlNode<T>* AvlTree<T>::newNode(const T v)
{
    return new AvlNode<T>{v, nullptr, nullptr, 1};
}

template<typename T>
void AvlTree<T>::insert(const T v)
{
    rootNode = insertRecursive(rootNode, v);
}

template<typename T>
void AvlTree<T>::deleteNodeWithKey(const T v)
{

}

template<typename T>
AvlNode<T>* AvlTree<T>::insertRecursive(AvlNode<T>* node, const T v)
{
    if(nullptr == node)
        return newNode(v);

    if(v < node->key)
    {
        node->left = insertRecursive(node->left, v);
    }
    else if(v > node->key)
    {
        node->right = insertRecursive(node->right, v);
    }
    else
    {
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));
    const auto balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && v < node->left->key) // L, L
    {
        return rightRotate(node);
    }
    else if(balanceFactor < -1 && v > node->right->key) // R, R
    {
        return leftRotate(node);
    }
    else if(balanceFactor > 1 && v > node->left->key) // L, R
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if(balanceFactor < -1 && v < node->right->key) // R, L
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename T>
AvlNode<T>* AvlTree<T>::leftRotate(AvlNode<T>* node)
{
    auto* x = node->right;
    auto* xLeftChild = x->left;

    node->right = xLeftChild;
    x->left = node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

template<typename T>
AvlNode<T>* AvlTree<T>::rightRotate(AvlNode<T>* node)
{
    auto* x = node->left;
    auto* xRightChild = x->right;

    node->left = xRightChild;
    x->right = node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

}; // namespace Tree
