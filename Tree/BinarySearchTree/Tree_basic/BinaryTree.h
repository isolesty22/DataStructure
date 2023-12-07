#pragma once

template<typename T>
class BinaryTree
{
protected:
	class BinaryNode
	{
	private:
		int m_key;
		T m_data;
		BinaryNode* m_left;
		BinaryNode* m_right;

	public:
		BinaryNode(int key, T data, BinaryNode* left = nullptr, BinaryNode* right = nullptr) :m_key(key), m_data(data), m_left(left), m_right(right) {}
		~BinaryNode() {}

		bool isLeaf() { return m_left == nullptr && m_right == nullptr; }

		int getKey() { return m_key; }
		T getData() { return m_data; }
		BinaryNode* getLeft() { return m_left; }
		BinaryNode* getRight() { return m_right; }
		void setLeft(BinaryNode* node) { m_left = node; }
		void setRight(BinaryNode* node) { m_right = node; }
	};

	BinaryNode* m_root;

public:
	BinaryTree(BinaryNode* root = nullptr) :m_root(root) {}
	~BinaryTree() {}

	bool isEmpty() { return m_root == nullptr; }
	int getCount() { return isEmpty() ? 0 : getCount(m_root); }
	int getHeight() { return isEmpty() ? 0 : getHeight(m_root); }
	void preorder() { if (!isEmpty()) preorder(m_root); };
	void inorder() { if (!isEmpty()) inorder(m_root);; }
	void postorder() { if (!isEmpty()) postorder(m_root); }

private:
	int getCount(BinaryNode* node);
	int getHeight(BinaryNode* node);
	void preorder(BinaryNode* node);
	void inorder(BinaryNode* node);
	void postorder(BinaryNode* node);
};

template<typename T>
inline int BinaryTree<T>::getCount(BinaryNode* node)
{
	if (node == nullptr) return 0;
	return 1 + getCount(node->getLeft()) + getCount(node->getRight());
}

template<typename T>
inline int BinaryTree<T>::getHeight(BinaryNode* node)
{
	if (node == nullptr) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

template<typename T>
inline void BinaryTree<T>::preorder(BinaryNode* node)
{
	if (node == nullptr) return;
	std::cout << node->getKey() << ' ';
	preorder(node->getLeft());
	preorder(node->getRight());
}

template<typename T>
inline void BinaryTree<T>::inorder(BinaryNode* node)
{
	if (node == nullptr) return;
	inorder(node->getLeft());
	std::cout << node->getKey() << ' ';
	inorder(node->getRight());
}

template<typename T>
inline void BinaryTree<T>::postorder(BinaryNode* node)
{
	if (node == nullptr) return;
	inorder(node->getLeft());
	inorder(node->getRight());
	std::cout << node->getKey() << ' ';
}