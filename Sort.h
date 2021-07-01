#pragma once
#include "stdafx.h"

template <typename T>
class Sorter
{
public:
	Sorter(T* arr, int size)
		: mArray(arr)
		, mSize(size)
	{
	}

	virtual void	Sort() = 0;

	T* GetArray();
	int& GetSize();


private:
	T*	mArray;
	int mSize;

};

template<typename T>
inline T* Sorter<T>::GetArray()
{
	return mArray;
}

template<typename T>
inline int& Sorter<T>::GetSize()
{
	return mSize;
}


template <typename T>
class BubbleSorter : public Sorter<T>
{
public:
	BubbleSorter(T* arr, int size)
		:Sorter<T>(arr, size) {};

	void Sort() override;
	void Swap(T& a, T& b);

};

template<typename T>
inline void BubbleSorter<T>::Sort()
{
	auto arr = Sorter<T>::GetArray();
	auto& size = Sorter<T>::GetSize();

	for(int i = 0 ; i < size -1 ; ++i)
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
}

template<typename T>
inline void BubbleSorter<T>::Swap(T& a, T& b)
{
	auto tmp = a;
	a = b;
	b = tmp;
}

