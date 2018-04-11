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
    while(nullptr != node->left)
        node = node->left;

    return node;
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

template<typename T>
void AvlTree<T>::deleteNodeWithKey(const T v)
{
    rootNode = deleteNodeRecursive(rootNode, v);
}

template<typename T>
AvlNode<T>* AvlTree<T>::deleteNodeRecursive(AvlNode<T>* node, const T v)
{
    if(nullptr == node)
        return node;

    if(v < node->key)
    {
        node->left = deleteNodeRecursive(node->left, v);
    }
    else if(v > node->key)
    {
        node->right = deleteNodeRecursive(node->right, v);
    }
    else
    {
        // perform normal BST node deletion here
        if(nullptr == node->left || nullptr == node->right)
        {
            auto temp = (nullptr == node->left) ? node->right : node->left;

            if(nullptr == temp)
            {
                temp = node;
                node = nullptr;
            }
            else if(nullptr == node->left)
            {
                node->key = temp->key;
                node->right = nullptr;
            }
            else
            {
                node->key = temp->key;
                node->left = nullptr;
            }

            delete temp;
        }
        else
        {
            auto temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNodeRecursive(node->right, temp->key);
        }
    }

    if(nullptr == node)
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    const auto balanceFactor = getBalanceFactor(node);
    // std::cout << v << " balanceFactor " << balanceFactor << std::endl;

    if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0) // L, L
    {
        std::cout << "right rotating...\n";
        return rightRotate(node);
    }
    else if(balanceFactor > 1 && getBalanceFactor(node->left) < 0) // L, R
    {
        std::cout << "left right rotating...\n";
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0) // R, R
    {
        std::cout << "left rotating...\n";
        return leftRotate(node);
    }
    else if(balanceFactor < -1 && getBalanceFactor(node->right) > 0) // R, L
    {
        std::cout << "right left rotating...\n";
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

}; // namespace Tree
