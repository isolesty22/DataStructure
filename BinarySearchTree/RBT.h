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
	//node의 기능이지만 nullptr 처리를 위해 tree에 정의.
	Color getColor(RBTNode<T>* node) { return (node == nullptr) ? Color::black : node->getColor(); }
	void setColor(RBTNode<T>* node, Color color) { if (node)node->setColor(color); }
	
	//가독성을 위해 정의.
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

		//루트였을 경우
		if (parent == nullptr)
		{
			setColor(node, Color::black);
			return nullptr;
		}
		//부모가 red이며, 삼촌이 black인 경우
		else if (isRed(parent) && isBlack(uncle))
		{
			//선형인 경우
			if (gp->getLeft() == parent && parent->getLeft() == node)
			{
				rotateRightAndRecolor(gp);
			}
			else if (gp->getRight() == parent && parent->getRight() == node)
			{
				rotateLeftAndRecolor(gp);
			}
			//비선형인 경우.
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
		//부모 삼촌이 둘 다 red
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

	//삭제된 노드가 black일때만 extra black 발생.
	if (isBlack(node))
	{
		if (parent == nullptr)
		{
			if (isRed(child)) setColor(child, Color::black);
		}
		else
		{
			//child가 NIL노드인데 double black이라면 형제 노드가 무조건 존재한다. 
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

	//4가지 case
	if (isBlack(left))
	{
		//여기서 3가지
		if (isBlack(rChild) && isBlack(lChild))
		{
			setColor(left, Color::red);

			if (isRed(node)) setColor(node, Color::black);
			else
			{
				//루트였다면 블랙 버려도 된다. 아니라면 node가 DB가 돼서, 또 DB를 해결해야 한다.
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

	//4가지 case
	if (isBlack(right))
	{
		//3 case
		if (isBlack(rChild) && isBlack(lChild))
		{
			setColor(right, Color::red);

			if (isRed(node)) setColor(node, Color::black);
			else
			{
				//루트였다면 블랙 버려도 된다. 아니라면 node가 DB가 돼서, 또 DB를 해결해야 한다.
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