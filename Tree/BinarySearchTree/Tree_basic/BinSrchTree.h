#pragma once
#include "BinaryTree.h"

template<typename T>
class BinSrchTree : public BinaryTree<T>
{
public:
	BinSrchTree(typename BinaryTree<T>::BinaryNode* root = nullptr) :BinaryTree<T>(root) {}
	//가지고 있는 노드들 전부 메모리 해제 해줘야 할 거 같은데?
	~BinSrchTree() {}

	typename BinaryTree<T>::BinaryNode* findLoc(int key);
	typename BinaryTree<T>::BinaryNode* search(int key);
	void insert(int key, T item);
	void remove(int key);


};

//비어있으면 null, 찾는 노드가 있으면 해당 노드 리턴, 없으면 빈공간의 부모를 리턴.
template<typename T>
inline typename BinaryTree<T>::BinaryNode* BinSrchTree<T>::findLoc(int key)
{
	if (this->isEmpty()) return nullptr;

	typename BinaryTree<T>::BinaryNode* parent = nullptr;
	typename BinaryTree<T>::BinaryNode* node = this->m_root;

	while (node != nullptr)
	{
		if (key == node->getKey())
			return node;
		else if (key < node->getKey())
		{
			parent = node;
			node = node->getLeft();
		}
		else if (key > node->getKey())
		{
			parent = node;
			node = node->getRight();
		}
	}
	return parent;
}

template<typename T>
inline typename BinaryTree<T>::BinaryNode* BinSrchTree<T>::search(int key)
{
	typename BinaryTree<T>::BinaryNode* node = findLoc(key);

	if (key == node->getKey()) return node;
	else return nullptr;
}

template<typename T>
inline void BinSrchTree<T>::insert(int key, T item)
{
	typename BinaryTree<T>::BinaryNode* node = findLoc(key);

	if (node == nullptr)
	{
		typename BinaryTree<T>::BinaryNode* newNode = new typename BinaryTree<T>::BinaryNode(key, item);
		this->m_root = newNode;
	}
	else if (key == node->getKey()) return;
	else
	{
		typename BinaryTree<T>::BinaryNode* newNode = new typename BinaryTree<T>::BinaryNode(key, item);
		if (key < node->getKey()) node->setLeft(newNode);
		else if (key > node->getKey()) node->setRight(newNode);
	}
}

template<typename T>
inline void BinSrchTree<T>::remove(int key)
{
	if (this->isEmpty()) return;

	typename BinaryTree<T>::BinaryNode* parent = nullptr;
	typename BinaryTree<T>::BinaryNode* node = this->m_root;

	while (node != nullptr && key != node->getKey())
	{
		parent = node;
		node = (key < node->getKey()) ? node->getLeft() : node->getRight();
	}

	if (node == nullptr) return; //찾는 노드가 없음

	if (node->isLeaf())
	{
		if (parent == nullptr) this->m_root = nullptr;
		else
		{
			(parent->getLeft() == node) ? parent->setLeft(nullptr) : parent->setRight(nullptr);
		}
		delete node;
	}
	else if (node->getLeft() == nullptr || node->getRight() == nullptr)
	{
		if (parent == nullptr)
			(node->getLeft() != nullptr) ? this->m_root = node->getLeft() : this->m_root = node->getRight();
		else
		{
			if (parent->getLeft() == node)
			{
				(node->getLeft() != nullptr) ? parent->setLeft(node->getLeft()) : parent->setLeft(node->getRight());
			}
			else
			{
				(node->getLeft() != nullptr) ? parent->setRight(node->getLeft()) : parent->setRight(node->getRight());
			}
		}
		delete node;
	}
	else if (node->getLeft() != nullptr && node->getRight() != nullptr)
	{
		typename BinaryTree<T>::BinaryNode* temp = node->getLeft();
		typename BinaryTree<T>::BinaryNode* tempParent = node;

		while (temp->getRight() != nullptr)
		{
			tempParent = temp;
			temp = temp->getRight();
		}

		(tempParent->getLeft() == temp) ? tempParent->setLeft(nullptr) : tempParent->setRight(nullptr);
		temp->setLeft(node->getLeft());
		temp->setRight(node->getRight());

		if (parent == nullptr)	this->m_root = temp;
		else
		{
			(parent->getLeft() == node) ? parent->setLeft(temp) : parent->setRight(temp);
		}

		delete node;
	}
}