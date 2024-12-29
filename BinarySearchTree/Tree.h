#pragma once
#include "Node.h"

template <typename T, typename NodeType>
class Tree
{
protected:
	NodeType* m_root;
public:
	Tree() :m_root(nullptr) {}
	virtual ~Tree() {}

	virtual NodeType* insert(int key, const T& data) = 0;
	virtual NodeType* remove(int key) = 0;
	virtual NodeType* search(int key) = 0;

	virtual void preorder() = 0;
	virtual void inorder() = 0;
	virtual void postorder() = 0;

	bool isEmpty() { return m_root == nullptr; }
	virtual int getHeight(NodeType* node) = 0;
};