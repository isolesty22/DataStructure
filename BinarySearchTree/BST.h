#pragma once
#include "Tree.h"

template <typename T>
class BinaryNode :public BinaryNodeT<T, BinaryNode<T>>
{
public:
	BinaryNode(int key, const T& data)
		:BinaryNodeT<T, BinaryNode<T>>(key, data) {}
};

//Binary Search Tree
template <typename T, typename NodeType = BinaryNode<T>> 
class BST : public Tree<T, NodeType>
{
public:
	NodeType* insert(int key, const T& data) override;
	NodeType* remove(int key) override;
	NodeType* search(int key) override;
	
	void preorder() override { preorder(this->m_root); }
	void inorder() override { inorder(this->m_root); }
	void postorder() override { postorder(this->m_root); }

	int getHeight(NodeType* node) override;

protected:
	void rotateRight(NodeType* node);
	void rotateLeft(NodeType* node);

private:
	void preorder(NodeType* node);
	void inorder(NodeType* node);
	void postorder(NodeType* node);

	NodeType* findLocation(int key);
};

//삽입노드 return, 실패 시 nullptr
template <typename T, typename NodeType>
inline NodeType* BST<T, NodeType>::insert(int key, const T& data)
{
	NodeType* node = new NodeType(key, data);
	NodeType* parent = findLocation(key);

	if (parent == nullptr)
		this->m_root = node;
	else if (parent->getKey() == key)
		return nullptr;
	else
	{
		parent->getKey() > node->getKey() ? parent->setLeft(node) : parent->setRight(node);
		node->setParent(parent);
	}

	return node;
}

//삭제되는 노드 리턴, successor가 될 수도 있음.
template <typename T, typename NodeType>
inline NodeType* BST<T, NodeType>::remove(int key)
{
	if (this->isEmpty()) return nullptr;

	NodeType* node = search(key);
	if (node == nullptr) return nullptr;
	while (true)
	{
		NodeType* parent = node->getParent();

		if (node->isLeaf())
		{
			if (parent == nullptr)
				this->m_root = nullptr;
			else
			{
				node->isLeft() ? parent->setLeft(nullptr) : parent->setRight(nullptr);
			}

			break;
		}
		else if (node->getLeft() == nullptr || node->getRight() == nullptr)
		{
			NodeType* child = (node->getLeft() == nullptr) ? node->getRight() : node->getLeft();

			if (parent == nullptr)
			{
				this->m_root = child;
				child->setParent(nullptr);
			}
			else
			{
				node->isLeft() ? parent->setLeft(child) : parent->setRight(child);
				child->setParent(parent);
			}

			break;
		}
		else
		{
			//successor
			NodeType* s = node->getLeft();
			while (s->getRight() != nullptr)
				s = s->getRight();

			//red black tree 때문에 그냥 data를 copy한다.
			node->setKey(s->getKey());
			node->setData(s->getData());

			node = s;
		}
	}

	return node;
}

template <typename T, typename NodeType>
inline NodeType* BST<T, NodeType>::search(int key)
{
	if (this->isEmpty()) return nullptr;

	NodeType* node = findLocation(key);
	if (node->getKey() == key) return node;
	return nullptr;
}

template <typename T, typename NodeType>
inline int BST<T, NodeType>::getHeight(NodeType* node)
{
	if (node == nullptr) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return hLeft > hRight ? hLeft + 1 : hRight + 1;
}

template<typename T, typename NodeType>
inline void BST<T, NodeType>::rotateRight(NodeType* node)
{
	NodeType* parent = node->getParent();
	NodeType* left = node->getLeft();

	if (parent == nullptr)
	{
		left->setParent(nullptr);
		this->m_root = left;
	}
	else
	{
		node->isLeft() ? parent->setLeft(left) : parent->setRight(left);
		left->setParent(parent);
	}

	node->setLeft(left->getRight());
	if (node->getLeft() != nullptr) node->getLeft()->setParent(node);

	left->setRight(node);
	node->setParent(left);
}

template<typename T, typename NodeType>
inline void BST<T, NodeType>::rotateLeft(NodeType* node)
{
	NodeType* parent = node->getParent();
	NodeType* right = node->getRight();

	if (parent == nullptr)
	{
		right->setParent(nullptr);
		this->m_root = right;
	}
	else
	{
		node->isLeft() ? parent->setLeft(right) : parent->setRight(right);
		right->setParent(parent);
	}

	node->setRight(right->getLeft());
	if (node->getRight() != nullptr) node->getRight()->setParent(node);

	right->setLeft(node);
	node->setParent(right);
}

template <typename T, typename NodeType>
inline void BST<T, NodeType>::preorder(NodeType* node)
{
	if (node == nullptr) return;
	std::cout << node->getKey() << " ";
	preorder(node->getLeft());
	preorder(node->getRight());
}

template <typename T, typename NodeType>
inline void BST<T, NodeType>::inorder(NodeType* node)
{
	if (node == nullptr) return;
	inorder(node->getLeft());
	std::cout << node->getKey() << " ";;
	inorder(node->getRight());
}

template <typename T, typename NodeType>
inline void BST<T, NodeType>::postorder(NodeType* node)
{
	if (node == nullptr) return;
	postorder(node->getLeft());
	postorder(node->getRight());
	std::cout << node->getKey() << " ";;
}

//트리가 비어있으면 null, 키를 찾으면 해당 node, 없으면 삽입될 위치의 parent node return
template <typename T, typename NodeType>
inline NodeType* BST<T, NodeType>::findLocation(int key)
{
	if (this->isEmpty()) return nullptr;

	NodeType* parent = nullptr;
	NodeType* node = this->m_root;

	while (node != nullptr)
	{
		if (node->getKey() == key)
			return node;
		else if (node->getKey() > key)
		{
			parent = node;
			node = node->getLeft();
		}
		else if (node->getKey() < key)
		{
			parent = node;
			node = node->getRight();
		}
	}

	return parent;
}