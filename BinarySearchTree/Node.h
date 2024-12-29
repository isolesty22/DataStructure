#pragma once

template<typename T>
class Node
{
private:
	int m_key;
	T m_data;

public:
	Node(int key, const T& data) : m_key(key), m_data(data) {}
	~Node() {}

	//getter
	int getKey() const { return m_key; }
	T getData() const { return m_data; }
	//setter
	void setData(const T& data) { m_data = data; }
	void setKey(int key) { m_key = key; }
};

template <typename T, typename NodeType>
class BinaryNodeT : public Node<T> {
private:
	NodeType* m_parent;
	NodeType* m_left;
	NodeType* m_right;

public:
	BinaryNodeT(int key, const T& data)
		: Node<T>(key, data), m_parent(nullptr), m_left(nullptr), m_right(nullptr) {}

	bool isLeaf() { return m_left == nullptr && m_right == nullptr; }
	bool isLeft() { return m_parent && m_parent->m_left == this; }
	void initialize() { m_parent = nullptr; m_left = nullptr; m_right = nullptr; }

	//getter
	NodeType* getLeft() const { return m_left; }
	NodeType* getRight() const { return m_right; }
	NodeType* getParent() const { return m_parent; }

	//setter
	void setLeft(NodeType* left) { m_left = left; }
	void setRight(NodeType* right) { m_right = right; }
	void setParent(NodeType* parent) { m_parent = parent; }
};