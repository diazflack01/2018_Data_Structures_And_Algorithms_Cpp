#include "LinearSearch.hpp"
#include <algorithm>

int linearSearch(const int arr[], const int sizeOfArr, const int searchItem)
{
	int idxPos = -1;
	for(int i = 0;  i < sizeOfArr; ++i)
	{
		if(arr[i] == searchItem)
		{
			idxPos = i;
			break;
		}
	}
	return idxPos;
}

int linearSearchVector(const std::vector<int>& vecArr, const int searchItem)
{
	const auto it = std::find(vecArr.begin(), vecArr.end(), searchItem);
	return (it != vecArr.end()) ? (it - vecArr.begin()) : -1;
}
