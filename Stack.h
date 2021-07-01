#pragma once
#include "stdafx.h"

template <typename T>
class Stack
{
public:
	Stack(int size);
	~Stack();

	int GetSize() { return mTopIndex+1; }

	void Push(const T& element);
	T Pop();

	void Print();



private:
	T* mStack;
	int mSize;
	int mTopIndex;

};

template<typename T>
inline Stack<T>::Stack(int size)
	: mSize(size)
	, mTopIndex(-1)
{
	mStack = new T[size];
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] mStack;
}

template<typename T>
inline void Stack<T>::Push(const T& element)
{
	if (mTopIndex + 1  > mSize -1)
	{
		printf("Stack OverFlow");
		return;
	}


	mStack[++mTopIndex] = element;
	
}

template<typename T>
inline T Stack<T>::Pop()
{
	if (mTopIndex == -1)
	{
		std::cout << "Stack is empty" << std::endl;
		return NULL;
	}
		
	return mStack[mTopIndex--];
}

template<typename T>
inline void Stack<T>::Print()
{
	std::cout << "size : " << GetSize() << std::endl;

	for (int i = 0; i < GetSize(); ++i)
	{
		std::cout << "Element[" << i  << "] : "<< mStack[i] << std::endl;
	}
}


