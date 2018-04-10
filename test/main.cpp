#include <gtest/gtest.h>
#include <LinkedList/TestSinglyLinkedList.cpp>
#include <SearchAlgo/TestLinearSearch.cpp>
#include <SearchAlgo/TestBinarySearch.cpp>
#include <SearchAlgo/TestHashTable.cpp>
#include <SortAlgo/TestBubbleSort.cpp>
#include <SortAlgo/TestInsertionSort.cpp>
#include <SortAlgo/TestSelectionSort.cpp>
#include <SortAlgo/TestMergeSort.cpp>
#include <SortAlgo/TestQuickSort.cpp>
#include <SortAlgo/TestShellSort.cpp>
#include <CompressionAlgo/TestHuffman.cpp>
#include <BitManipulation/TestBitOperations.hpp>
#include <Tree/TestBinaryTree.cpp>
#include <Tree/TestAvlTree.cpp>

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}