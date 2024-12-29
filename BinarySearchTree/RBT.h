#pragma once
#include "BST.h"

enum class Color { red, black };

template <typename T>
class RBTNode : public BinaryNodeT<T, RBTNode<T>> {
private:
	Color m_color;
public:
	RBTNode(int key, const T& data)
		:BinaryNodeT<T, RBTNode<T>>(key, data), m_color(Color::red) {}

	Color getColor() { return m_color; }
	void setColor(Color color) { m_color = color; }
};

template <typename T>
class RBT :	public BST<T, RBTNode<T>>
{
public:
	RBTNode<T>* insert(int key, const T& data) override;
	RBTNode<T>* remove(int key) override;

private:
	//node�� ��������� nullptr ó���� ���� tree�� ����.
	Color getColor(RBTNode<T>* node) { return (node == nullptr) ? Color::black : node->getColor(); }
	void setColor(RBTNode<T>* node, Color color) { if (node)node->setColor(color); }
	
	//�������� ���� ����.
	bool isBlack(RBTNode<T>* node) { return getColor(node) == Color::black; }
	bool isRed(RBTNode<T>* node) { return !isBlack(node); }

	void rotateRightAndRecolor(RBTNode<T>* node);
	void rotateLeftAndRecolor(RBTNode<T>* node);
	void solveRightDoubleBlack(RBTNode<T>* node);
	void solveLeftDoubleBlack(RBTNode<T>* node);
};

template<typename T>
inline RBTNode<T>* RBT<T>::insert(int key, const T& data)
{
	RBTNode<T>* node = BST<T, RBTNode<T>>::insert(key, data);

	while (node != nullptr)
	{
		//initialize
		RBTNode<T>* parent = node->getParent();
		RBTNode<T>* gp = (parent != nullptr) ? parent->getParent() : nullptr;
		RBTNode<T>* uncle = (gp != nullptr) ? (parent->isLeft() ? gp->getRight() : gp->getLeft()) : nullptr;

		//��Ʈ���� ���
		if (parent == nullptr)
		{
			setColor(node, Color::black);
			return nullptr;
		}
		//�θ� red�̸�, ������ black�� ���
		else if (isRed(parent) && isBlack(uncle))
		{
			//������ ���
			if (gp->getLeft() == parent && parent->getLeft() == node)
			{
				rotateRightAndRecolor(gp);
			}
			else if (gp->getRight() == parent && parent->getRight() == node)
			{
				rotateLeftAndRecolor(gp);
			}
			//������ ���.
			else if (gp->getLeft() == parent && parent->getRight() == node)
			{
				this->rotateLeft(parent);
				rotateRightAndRecolor(gp);
			}
			else if (gp->getRight() == parent && parent->getLeft() == node)
			{
				this->rotateRight(parent);
				rotateLeftAndRecolor(gp);
			}

			return nullptr;
		}
		//�θ� ������ �� �� red
		else if (isRed(parent) && isRed(uncle))
		{
			setColor(gp, Color::red);
			setColor(parent, Color::black);
			setColor(uncle, Color::black);

			node = gp;
		}
		else return nullptr;
	}
}

template<typename T>
inline RBTNode<T>* RBT<T>::remove(int key)
{
	RBTNode<T>* node = BST<T,RBTNode<T>>::remove(key);
	if (node) return node;
	RBTNode<T>* parent = node->getParent();
	RBTNode<T>* child = node->getLeft() != nullptr ? node->getLeft() : node->getRight();

	//������ ��尡 black�϶��� extra black �߻�.
	if (isBlack(node))
	{
		if (parent == nullptr)
		{
			if (isRed(child)) setColor(child, Color::black);
		}
		else
		{
			//child�� NIL����ε� double black�̶�� ���� ��尡 ������ �����Ѵ�. 
			if (child == nullptr)
				parent->getLeft() == nullptr ? solveLeftDoubleBlack(parent) : solveRightDoubleBlack(parent);
			else if (isBlack(child))
				child->isLeft() ? solveLeftDoubleBlack(parent) : solveRightDoubleBlack(parent);
			else if (isRed(child))
				setColor(child, Color::black);
		}
	}

	return nullptr;
}

template<typename T>
inline void RBT<T>::rotateRightAndRecolor(RBTNode<T>* node)
{
	RBTNode<T>* left = node->getLeft();

	Color empty = getColor(node);
	setColor(node, getColor(left));
	setColor(left, empty);

	this->rotateRight(node);
}

template<typename T>
inline void RBT<T>::rotateLeftAndRecolor(RBTNode<T>* node)
{
	RBTNode<T>* right = node->getRight();

	Color empty = getColor(node);
	setColor(node, getColor(right));
	setColor(right, empty);

	this->rotateLeft(node);
}

template<typename T>
inline void RBT<T>::solveRightDoubleBlack(RBTNode<T>* node)
{
	RBTNode<T>* left = node->getRight();
	RBTNode<T>* parent = node->getParent();
	RBTNode<T>* rChild = left->getRight();
	RBTNode<T>* lChild = left->getLeft();

	//4���� case
	if (isBlack(left))
	{
		//���⼭ 3����
		if (isBlack(rChild) && isBlack(lChild))
		{
			setColor(left, Color::red);

			if (isRed(node)) setColor(node, Color::black);
			else
			{
				//��Ʈ���ٸ� �� ������ �ȴ�. �ƴ϶�� node�� DB�� �ż�, �� DB�� �ذ��ؾ� �Ѵ�.
				if (parent != nullptr)
					node->isLeft() ? solveLeftDoubleBlack(parent) : solveRightDoubleBlack(parent);
			}
		}
		else if (isRed(lChild))
		{
			setColor(lChild, Color::black);
			rotateRightAndRecolor(node);
		}
		else if (isRed(rChild))
		{
			rotateLeftAndRecolor(left);
			solveRightDoubleBlack(node);
		}
	}
	else if (isRed(left))
	{
		rotateLeftAndRecolor(node);
		solveRightDoubleBlack(node);
	}
}

template<typename T>
inline void RBT<T>::solveLeftDoubleBlack(RBTNode<T>* node)
{
	RBTNode<T>* parent = node->getParent();
	RBTNode<T>* right = node->getRight();
	RBTNode<T>* rChild = right->getRight();
	RBTNode<T>* lChild = right->getLeft();

	//4���� case
	if (isBlack(right))
	{
		//3 case
		if (isBlack(rChild) && isBlack(lChild))
		{
			setColor(right, Color::red);

			if (isRed(node)) setColor(node, Color::black);
			else
			{
				//��Ʈ���ٸ� �� ������ �ȴ�. �ƴ϶�� node�� DB�� �ż�, �� DB�� �ذ��ؾ� �Ѵ�.
				if (parent != nullptr)
					node->isLeft() ? solveLeftDoubleBlack(parent) : solveRightDoubleBlack(parent);
			}
		}
		else if (isRed(rChild))
		{
			setColor(rChild, Color::black);
			rotateLeftAndRecolor(node);
		}
		else if (isRed(lChild))
		{
			rotateRightAndRecolor(right);
			solveLeftDoubleBlack(node);
		}
	}
	else if (isRed(right))
	{
		rotateLeftAndRecolor(node);
		solveLeftDoubleBlack(node);
	}
}