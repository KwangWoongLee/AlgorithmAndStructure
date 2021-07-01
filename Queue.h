#pragma once
#include "stdafx.h"


template <typename T>
class Queue
{
	struct Node
	{
		Node*	next;
		T		data;
	};

public:
	Queue();
	~Queue();

	int	GetSize();

	void Push(const T& element);
	T Pop();

	bool IsEmpty();

	void Print();

private:
	T*	mQueue;
	int mSize;
	Node* mHead;
	Node* mTail;
	Node* mPreTail;

};

template<typename T>
inline Queue<T>::Queue()
	: mSize(0)
{
	mTail = new Node;
	mTail->next = nullptr;
	mTail->data = NULL;


	mHead = new Node;
	mHead->next = mTail;
	mHead->data = NULL;

	mPreTail = mHead;

}

template<typename T>
inline Queue<T>::~Queue()
{
}

template<typename T>
inline int Queue<T>::GetSize()
{
	return mSize;
}

template<typename T>
inline void Queue<T>::Push(const T& element)
{
	auto newNode = new Node;
	newNode->next = mTail;
	newNode->data = element;

	if (IsEmpty())
		mHead->next = newNode;
	else
	{
		mPreTail->next = newNode;
	}

	mPreTail = newNode;

	++mSize;
}

template<typename T>
inline T Queue<T>::Pop()
{
	if (IsEmpty())
	{
		std::cout << "Queue is Empty" << std::endl;
		return NULL;
	}

	auto returnValue = mPreTail->data;


	Node* thisNode = mHead;
	while (thisNode->next != mPreTail)
	{
		thisNode = thisNode->next;
	}

	thisNode->next = mTail;

	delete mPreTail;

	mPreTail = thisNode;

	--mSize;

	return returnValue;
	
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	return !static_cast<bool>(mSize);
}

template<typename T>
inline void Queue<T>::Print()
{
	if (IsEmpty())
		return;

	std::cout << "size : " << GetSize() << std::endl;

	int i = 0;

	auto thisNode = mHead->next;
	while (thisNode != mTail)
	{
		std::cout << "Element " << i << " : " << thisNode->data << std::endl;
		thisNode = thisNode->next;
		++i;
	}
}
