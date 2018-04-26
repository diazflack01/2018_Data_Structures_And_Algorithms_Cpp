#pragma once

#include <vector>
#include <functional>
#include <Utils.hpp>

template<typename T, typename Less = std::less<T>>
class MinBinaryHeap
{
public:
    MinBinaryHeap() = default;
    MinBinaryHeap(T* arr, unsigned size);
    MinBinaryHeap(const std::vector<T> vec);

    void insert(T elem);
    void deleteMin();
    void modifyValueAtIndex(int index, const T newVal);
    void deleteIndex(int index);
    T extractMin();
    std::vector<T> getHeapTree() const;
    unsigned size() const;

private:
    void headpify();
    void heapifyUp(int index);
    void heapifyDown(int index);
    int leftChild(int parent) const;
    int rightChild(int parent) const;
    int parent(int child) const;

    std::vector<T> mHeapTree;
};

template<typename T, typename Less>
MinBinaryHeap<T, Less>::MinBinaryHeap(T* arr, unsigned size)
{
    for(auto i = 0u; i < size; ++i)
        mHeapTree.push_back(arr[i]);

    headpify();
    
}

template<typename T, typename Less>
MinBinaryHeap<T, Less>::MinBinaryHeap(const std::vector<T> vec) : mHeapTree(vec)
{
    headpify();
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::headpify()
{

}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::heapifyUp(int index)
{

}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::heapifyDown(int index)
{

}

template<typename T, typename Less>
int MinBinaryHeap<T, Less>::leftChild(int parent) const
{
    return 0;
}

template<typename T, typename Less>
int MinBinaryHeap<T, Less>::rightChild(int parent) const
{
    return 0;
}

template<typename T, typename Less>
int MinBinaryHeap<T, Less>::parent(int child) const
{
    return 0;
}


template<typename T, typename Less>
std::vector<T> MinBinaryHeap<T, Less>::getHeapTree() const
{
    return mHeapTree;
}

template<typename T, typename Less>
unsigned MinBinaryHeap<T, Less>::size() const
{
    return mHeapTree.size();
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::insert(T elem)
{
    mHeapTree.push_back(elem);
    heapifyUp(mHeapTree.size()-1);
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::deleteMin()
{

}

template<typename T, typename Less>
T MinBinaryHeap<T, Less>::extractMin()
{
    if(mHeapTree.empty())
        return -1;
    return mHeapTree.front();
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::modifyValueAtIndex(int index, const T newVal)
{

}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::deleteIndex(int index)
{

}