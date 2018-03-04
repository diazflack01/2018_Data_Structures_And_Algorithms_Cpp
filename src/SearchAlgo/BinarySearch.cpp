#include "BinarySearch.hpp"
#include <algorithm>
#include <iterator>

int binarySearch(const int arr[], const int sizeOfArr, const int searchItem)
{
	int idxPos = -1;
	int lo = 0, mid = 0, hi = sizeOfArr -1;

	while(lo <= hi)
	{
		mid = lo + ((hi - lo) / 2);
		if(arr[mid] == searchItem)
		{
			idxPos = mid;
			break;
		}
		else if(arr[mid] < searchItem)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return idxPos;
}

int binarySearchVector(const std::vector<int>& vecArr, const int searchItem)
{
	int idxPos = -1;
	if(std::is_sorted(vecArr.begin(), vecArr.end()))
	{
		int lo = 0, mid = 0, hi = vecArr.size()-1;

		while(lo <= hi)
		{
			mid = lo + ((hi - lo) / 2);
			if(vecArr[mid] == searchItem)
			{
				idxPos = mid;
				break;
			}
			else if(vecArr[mid] > searchItem)
			{
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
	}
	return idxPos;
	// auto count = std::distance(vecArr.begin(), vecArr.end());
	// auto first = vecArr.begin();
	// auto current = first;
	// auto step = count / 2;
	// std::advance(first, step);

	// while(count > 0)
	// {
	// 	if(*first == searchItem)
	// 	{
	// 		return std::distance(vecArr.begin(), first);
	// 	}
	// 	else if(*first < searchItem)
	// 	{
	// 		first++;
	// 		count = step;
	// 	}
	// 	else
	// 	{
	// 		first--;
	// 		count = step;
	// 	}
	// }
	
	// return -1;
}