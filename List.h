#pragma once
#include "stdafx.h"

template <typename T>
class List
{
	struct Node
	{
		Node * next;
		T		data;
	};


public:
	List();
	~List();

	void	PushBack(const T& element);
	T		PopBack();

	void	PushFront(const T& element);
	T		PopFront();

	int		GetSize() { return mSize; }

	bool	IsEmpty();

	void	Print();

	T		At(const int& i);


private:
	int		mSize;
	Node*	mHead;
	Node*	mTail;
	Node*	mPreTail;

};

template<typename T>
inline List<T>::List()
	: mSize(0)
{
	mHead = new Node;
	mHead->next = mTail;
	mHead->data = NULL;

	mTail = new Node;
	mTail->next = nullptr;
	mTail->data = NULL;

	mPreTail = mHead;
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::PushBack(const T& element)
{
	auto newNode = new Node();
	newNode->data = element;
	newNode->next = mTail;

	if(IsEmpty())
		mHead->next = newNode;
	else
	{
		mPreTail->next = newNode;
	}

	mPreTail = newNode;

	++mSize;
}

template<typename T>
inline T List<T>::PopBack()
{
	if (IsEmpty())
	{
		std::cout << "List is Empty" << std::endl;
		return NULL;
	}

	auto returnValue = mPreTail->data;

	auto thisNode = mHead->next;
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
inline void List<T>::PushFront(const T& element)
{
	auto newNode = new Node;
	newNode->data = element;
	newNode->next = mHead->next;

	if (IsEmpty())
	{
		mPreTail = newNode;
	}

	mHead->next = newNode;

	++mSize;
}

template<typename T>
inline T List<T>::PopFront()
{
	if (IsEmpty())
	{
		std::cout << "List is Empty" << std::endl;
		return NULL;
	}

	auto popNode = mHead->next;
	auto returnValue = popNode->data;

	if (mPreTail == popNode)
		mPreTail = mHead;

	mHead->next = mHead->next->next;

	delete popNode;

	--mSize;

	return returnValue;
}

template<typename T>
inline bool List<T>::IsEmpty()
{
	return !static_cast<bool>(mSize);
}

template<typename T>
inline void List<T>::Print()
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

template<typename T>
inline T List<T>::At(const int& i)
{
	if (IsEmpty())
	{
		std::cout << "List is Empty" << std::endl;
		return NULL;
	}
		
	auto thisNode = mHead->next;
	int count = 0;

	while (thisNode != mTail)
	{
		if (count == i)
		{
			return thisNode->data;
		}

		thisNode = thisNode->next;
		++count;
	}

	return NULL;
}
