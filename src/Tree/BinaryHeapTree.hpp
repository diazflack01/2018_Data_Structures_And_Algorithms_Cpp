#pragma once

#include <vector>
#include <functional>

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
    for(int i = mHeapTree.size()-1; i >= 0; --i)
        heapifyDown(i);
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::heapifyUp(int index)
{
    const int parentIdx = parent(index);

    if(0 < index && mHeapTree[index] < mHeapTree[parentIdx])
    {
        auto temp = mHeapTree[index];
        mHeapTree[index] = mHeapTree[parentIdx];
        mHeapTree[parentIdx] = temp;
        heapifyUp(parentIdx);
    }
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::heapifyDown(int index)
{
    const int leftChildIdx = leftChild(index);
    const int rightChildIdx = rightChild(index);

    if(leftChildIdx >= int(size()))
        return;
    
    int minIndex = index;
    if(mHeapTree[leftChildIdx] < mHeapTree[minIndex])
        minIndex = leftChildIdx;
    if(rightChildIdx < int(size()) && mHeapTree[rightChildIdx] < mHeapTree[minIndex])
        minIndex = rightChildIdx;
    
    if(index != minIndex)
    {
        auto temp = mHeapTree[index];
        mHeapTree[index] = mHeapTree[minIndex];
        mHeapTree[minIndex] = temp;
        heapifyDown(minIndex);
    }
}

template<typename T, typename Less>
int MinBinaryHeap<T, Less>::leftChild(int parent) const
{
    return (2*parent)+1;
}

template<typename T, typename Less>
int MinBinaryHeap<T, Less>::rightChild(int parent) const
{
    return (2*parent)+2;
}

template<typename T, typename Less>
int MinBinaryHeap<T, Less>::parent(int child) const
{
    return (child-1)/2;
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
    if(mHeapTree.empty())
        return;
    
    mHeapTree.front() = mHeapTree.back();
    mHeapTree.pop_back();
    heapifyDown(0);
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
    if(0 <= index && index < static_cast<int>(mHeapTree.size()))
    {
        mHeapTree[index] = newVal;
        heapifyDown(index);
        heapifyUp(index);
    }
}

template<typename T, typename Less>
void MinBinaryHeap<T, Less>::deleteIndex(int index)
{
    if(0 <= index && index < static_cast<int>(mHeapTree.size()))
    {
        mHeapTree[index] = mHeapTree.back();
        mHeapTree.pop_back();
        heapifyDown(index);
        heapifyUp(index);
    }
}