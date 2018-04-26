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

    // Deletion - https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
    void deleteNodeWithKey(const T v);

    // Traversal
    std::vector<T> levelOrderTraversal();

private:
    AvlNode<T>* insertRecursive(AvlNode<T>* node, const T v);
    AvlNode<T>* deleteNodeRecursive(AvlNode<T>* node, const T v);
    AvlNode<T>* leftRotate(AvlNode<T>* node);
    AvlNode<T>* rightRotate(AvlNode<T>* node);
    AvlNode<T>* minValueNode(AvlNode<T>* node);
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
        // std::cout << "key " << node->key << "\t height " << node->height << std::endl;
        ret.push_back(node->key);
        queue.push(node->left);
        queue.push(node->right);
    }
    
    return ret;
}

template<typename T>
AvlNode<T>* AvlTree<T>::minValueNode(AvlNode<T>* node)
{
    return nullptr;
}

template<typename T>
int AvlTree<T>::getBalanceFactor(AvlNode<T>* node)
{
    return 0;
}

template<typename T>
int AvlTree<T>::height(AvlNode<T>* node)
{
    return 0;
}

template<typename T>
AvlNode<T>* AvlTree<T>::newNode(const T v)
{
    return new AvlNode<T>{v, nullptr, nullptr, 1};
}

template<typename T>
void AvlTree<T>::insert(const T v)
{
    
}

template<typename T>
AvlNode<T>* AvlTree<T>::insertRecursive(AvlNode<T>* node, const T v)
{
    return node;
}

template<typename T>
AvlNode<T>* AvlTree<T>::leftRotate(AvlNode<T>* node)
{
    return nullptr;
}

template<typename T>
AvlNode<T>* AvlTree<T>::rightRotate(AvlNode<T>* node)
{
    return nullptr;
}

template<typename T>
void AvlTree<T>::deleteNodeWithKey(const T v)
{
    
}

template<typename T>
AvlNode<T>* AvlTree<T>::deleteNodeRecursive(AvlNode<T>* node, const T v)
{
    return nullptr;
}

}; // namespace Tree
