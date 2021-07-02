#pragma once
#include "stdafx.h"

template<typename T>
class Search : public Singleton<Search<T>>
{
public:
	int BinarySearch(const T* arr, int start, int end, const T& key) const;


private:
	

};

template<typename T>
inline int Search<T>::BinarySearch(const T* arr, int start, int end, const T& key) const
{
	//탐색 시간복잡도 O(logN)
	int mid;
	
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr[mid] == key)
			return mid;

		else if (arr[mid] > key)
		{
			end = mid - 1;
		}

		else
		{
			start = mid + 1;
		}
	}

	return -1;
}
