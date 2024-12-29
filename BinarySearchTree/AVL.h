#pragma once
#include "BST.h"

//AVLTree
template <typename T>
class AVL : public BST<T, BinaryNode<T>>
{
public:
	BinaryNode<T>* insert(int key, const T& data) override;
	BinaryNode<T>* remove(int key) override;

private:
	int getBalancedFactor(BinaryNode<T>* node);
	void rebalance(BinaryNode<T>* x, BinaryNode<T>* y, BinaryNode<T>* z);
};

template<typename T>
inline BinaryNode<T>* AVL<T>::insert(int key, const T& data)
{
	BinaryNode<T>* node = BST<T, BinaryNode<T>>::insert(key, data);

	if (node == nullptr) return nullptr;

	BinaryNode<T>* x = nullptr;
	BinaryNode<T>* y = nullptr;
	BinaryNode<T>* z = node;

	while (z != nullptr)
	{
		if (getBalancedFactor(z) > 1)
		{
			rebalance(x, y, z);
			break;
		}

		x = y;
		y = z;
		z = z->getParent();
	}

	return nullptr;
}

template<typename T>
inline BinaryNode<T>* AVL<T>::remove(int key)
{
	BinaryNode<T>* node = BST<T,BinaryNode<T>>::remove(key);
	BinaryNode<T>* z = node->getParent();
	BinaryNode<T>* y = nullptr;
	BinaryNode<T>* x = nullptr;

	while (z != nullptr)
	{
		if (getBalancedFactor(z) > 1)
		{
			y = (this->getHeight(z->getLeft()) > this->getHeight(z->getRight())) ? z->getLeft() : z->getRight();
			x = (this->getHeight(y->getLeft()) > this->getHeight(y->getRight())) ? y->getLeft() : y->getRight();
			rebalance(x, y, z);
		}

		z = z->getParent();
	}

	delete node;
	return nullptr;
}

template<typename T>
inline int AVL<T>::getBalancedFactor(BinaryNode<T>* node)
{
	int balancedFactor = this->getHeight(node->getRight()) - this->getHeight(node->getLeft());
	return balancedFactor < 0 ? balancedFactor * -1 : balancedFactor;
}

template<typename T>
inline void AVL<T>::rebalance(BinaryNode<T>* x, BinaryNode<T>* y, BinaryNode<T>* z)
{
	//x,y,z 가 선형
	if (z->getLeft() == y && y->getLeft() == x)
	{
		this->rotateRight(z);
	}
	else if (z->getRight() == y && y->getRight() == x)
	{
		this->rotateLeft(z);
	}
	//비선형
	else if (z->getRight() == y && y->getLeft() == x)
	{
		this->rotateRight(y);
		this->rotateLeft(z);
	}
	else
	{
		this->rotateLeft(y);
		this->rotateRight(z);
	}
}
