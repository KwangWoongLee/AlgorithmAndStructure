#pragma once
#include "stdafx.h"

template <typename T>
class BinaryTree
{
public:
	struct Node
	{
		Node* left;
		Node* right;
		T data;
	};

	BinaryTree(const T& data);
	~BinaryTree();

	Node* GetRoot() { return mRoot; }

	void PreOrder(Node* node);
	void InOrder(Node* node);
	void PostOrder(Node* node);

	virtual Node* AddLeftNode(Node* targetNode, const T& data);
	virtual Node* AddRightNode(Node* targetNode, const T& data);

	void RemoveNode(Node* node);




private:
	Node* mRoot;

};


template<typename T>
inline BinaryTree<T>::BinaryTree(const T& data)
{
	mRoot = new Node;
	mRoot->data = data;
	mRoot->left = nullptr;
	mRoot->right = nullptr;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	RemoveNode(mRoot);
}

template<typename T>
inline void BinaryTree<T>::PreOrder(Node* node)
{
	if (node == nullptr)
		return;

	std::cout << node->data << " ," << std::endl;
	PreOrder(node->left);
	PreOrder(node->right);
}

template<typename T>
inline void BinaryTree<T>::InOrder(Node* node)
{
	if (node == nullptr)
		return;

	InOrder(node->left);
	std::cout << node->data << " ," << std::endl;
	InOrder(node->right);
}

template<typename T>
inline void BinaryTree<T>::PostOrder(Node* node)
{
	if (node == nullptr)
		return;

	PostOrder(node->left);
	PostOrder(node->right);
	std::cout << node->data << " ," << std::endl;
}

template<typename T>
inline typename BinaryTree<T>::Node* BinaryTree<T>::AddLeftNode(Node* targetNode, const T& data)
{
	if (targetNode == nullptr)
		return nullptr;

	if (targetNode->left != nullptr)
		RemoveNode(targetNode->left);

	auto newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	targetNode->left = newNode;

	return newNode;
	
}

template<typename T>
inline typename BinaryTree<T>::Node* BinaryTree<T>::AddRightNode(Node* targetNode, const T& data)
{
	if (targetNode == nullptr)
		return nullptr;

	if (targetNode->right != nullptr)
		RemoveNode(targetNode->right);

	auto newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	targetNode->right = newNode;

	return newNode;
}

template<typename T>
inline void BinaryTree<T>::RemoveNode(Node* node)
{
	if (node == nullptr)
		return;

	RemoveNode(node->left);
	RemoveNode(node->right);

	delete node;
}
